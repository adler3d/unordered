class TMutiplayerGameWithAcc{
public:
  typedef Socket THttpSocket;
  struct TLinkSocket:Socket{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,id,-1)\
    ADD(string,ip,$)\
    ADD(int,port,-1)\
    //===
    #include "defprovar.inl"
    //===
    TLinkSocket(){DoReset();}
    TLinkSocket(TLinkSocket&&ref):Socket(std::move(ref)){
      id=ref.id;ip=ref.ip;port=ref.port;
    }
    TLinkSocket(const TLinkSocket&ref){QapNoWay();}
    void operator=(const TLinkSocket&ref){QapNoWay();}
    void operator=(TLinkSocket&&ref){
      Socket&base_ref=ref;Socket&base=*this;
      base=std::move(base_ref);
      id=ref.id;ip=ref.ip;port=ref.port;
    }
  };

  struct TAccServerMem{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    //===
    #include "defprovar.inl"
    //===
    TAccServerMem(){DoReset();}
  public:
  };

  struct TSoketItem{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,time,$)\
    ADD(string,data,$)\
    //===
    #include "defprovar.inl"
    //===
    TSoketItem(){DoReset();}
  };

  struct TSocket{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,socket,0)\
    ADD(string,addr,$)\
    ADD(vector<string>,addtime,$)\
    ADD(vector<TSoketItem>,news,$)\
    ADD(string,content,$)\
    ADD(vector<string>,deltime,$)\
    ADD(vector<string>,offtime,$)\
    ADD(vector<string>,errtime,$)\
    //===
    #include "defprovar.inl"
    //===
    TSocket(){DoReset();}
  };

  struct TKeyValue{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,key,$)\
    ADD(string,value,$)\
    //===
    #include "defprovar.inl"
    //===
    TKeyValue(){DoReset();}
  public:
    void set(const string&key,const string&value){this->key=key;this->value=value;}
  };

  struct TCore{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,page_name,"/closefirefox")\
    ADD(vector<TKeyValue>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
    TCore(){DoReset();}
  public:
    t_answer eval(const THttpRequest&request,TAccServerMem&mem)
    {
      string q=get_query(request.webpath);
      auto params=split(q,"&");
      auto f=[&](const string&param){return get_decoded_param_value(params,param);};
      auto gen_answer=t_answer::gen;
      if(params_defined(params,"test"))
      {
        return t_answer::gen("200;raw;win","/*\n"+cur_date_str()+"\n*/");
      }
      if(params_defined(params,"pl"))
      {
        string g_out;
        t_proc_list::GetProcessList(g_out);
        return t_answer::gen("200;raw;win","/*\n"+cur_date_str()+"\n*/\n"+g_out);
      }
      if(params_defined(params,"off"))
      {
        string g_out;string ffexe="firefox.exe";
        t_proc_list::GetProcessList(g_out,&ffexe);
        return t_answer::gen("200;raw;win","/*\n"+cur_date_str()+"\n*/\n"+g_out);
      }
      if(params_defined(params,"serv,event"))
      {
        qap_add_back(arr).set(f("serv"),f("event"));
        return t_answer::gen("200;raw;win","/*\n"+cur_date_str()+"\n*/");
      }
      if(params_defined(params,"clear")){auto n=arr.size();arr.clear();return t_answer::gen("200;raw;win","removed = "+IToS(n));};
      return t_answer::gen("200;raw;win","//fail");
    }
  };
  struct t_account_server{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,link_port,7010)\
    ADD(int,http_port,7020)\
    ADD(TCore,core,$)\
    ADD(TAccServerMem,mem,$)\
    ADD(vector<TSocket>,sockets,$)\
    ADD(vector<TSocket>,olds,$)\
    ADD(GatewayServer<THttpSocket>,http,$)\
    //===
    #include "defprovar.inl"
    //===
    t_account_server(){DoReset();}
  public:
    class TAccServerCallback:public GatewayServer<THttpSocket>::TCallback{
    public:
      t_account_server*pOwner;
      TAccServerCallback(t_account_server*pOwner):pOwner(pOwner){}
    public:
      t_answer GetAnswer(const THttpRequest&request)
      {
        string page=get_first_part(request.webpath,'?');
        if(page.empty())page=request.webpath;
        auto&own=*pOwner;
        if(own.core.page_name==page)
        {
          return own.core.eval(request,own.mem);
        }
        return t_answer::gen("404;raw;u8","page not found");
      }
      void OnRecvPack(THttpSocket&client,std::string&data){
        int id=find_socket_id(pOwner->sockets,client.sock);
        QapAssert(id>=0);
        auto&s=pOwner->sockets[id];
        s.news.push_back(TSoketItem());
        s.news.back().time=cur_date_str();
        s.news.back().data=data;
        s.content+=data;
        //return;/*
        auto header_get_value=[](const string&header,const string&param)->string
        {
          auto arr=split(header,"\r\n");
          for(int i=1;i<arr.size();i++)
          {
            auto&ex=arr[i];
            if(param!=get_first_part(ex,':'))continue;
            return join(split(get_second_part(ex,':')," "),"");
          }
          return "";
        };
        //
        const Extractor::Gripper tag_method(""," ");
        const Extractor::Gripper tag_webpath(""," HTTP/1.");
        const Extractor::Gripper tag_header("","\r\n\r\n");
        Extractor all(s.content);
        auto header=all.extract(tag_header);
        if(!all)return;
        Extractor e(header);
        auto method=e.extract(tag_method);
        if(!e)return;
        auto webpath=e.extract(tag_webpath);
        if(!e)return;
        auto low_header=LowerStr(header);
        auto host=header_get_value(low_header,"host");
        if(method=="POST")
        {
          auto length=header_get_value(low_header,"content-length");
          length=StrReplace(length," ","");
          int l=SToI(length);
          int dl=(header.size()+tag_header.after.size());
          dl=int(s.content.size()-dl);
          if(l!=dl){
            return;
          }
        }
        string keepalive="keep-alive";
        string con=header_get_value(header,"Connection");
        if(con.empty())con="close";
        con=LowerStr(con);
        string origin=header_get_value(header,"Origin");
        QapAssert(con==keepalive||con=="close");
        THttpRequest request;
        request.method=method;
        request.host=host;
        request.webpath=webpath;
        request.content=s.content.substr(all.pos);
        request.connection=con;
        request.origin=origin;
        auto answer=GetAnswer(request);
        client.send_raw(answer.get(request.connection,request.origin));
        if(con!=keepalive)
        {
          shutdown(client.sock,SD_BOTH);
        }else{
          s.content="";
        }
      }
      static int find_socket_id(vector<TSocket>&arr,int id){
        for(int i=0;i<arr.size();i++){
          if(arr[i].socket==id){
            return i;
          }
        }
        return -1;
      }
      void OnAddClient(THttpSocket&client)
      {
        client.set_auto_flush(true);
        int id=find_socket_id(pOwner->sockets,client.sock);
        QapAssert(id<0);
        pOwner->sockets.push_back(TSocket());
        auto&s=pOwner->sockets.back();
        s.socket=client.sock;
        s.addr=client.name();
        s.addtime.push_back(cur_date_str());
      }
      void OnDeleteClient(THttpSocket&client)
      {
        int id=find_socket_id(pOwner->sockets,client.sock);
        QapAssert(id>=0);
        pOwner->sockets[id].deltime.push_back(cur_date_str());
        vector<TSocket> tmp;
        for(int i=0;i<pOwner->sockets.size();i++){
          if(i!=id)tmp.push_back(std::move(pOwner->sockets[i]));
          if(i==id)pOwner->olds.push_back(std::move(pOwner->sockets[i]));
        }
        pOwner->sockets=std::move(tmp);
      }
    };
  public:
    void update_http()
    {
      if(!http.runned)
      {
        http=GatewayServer<Socket>();
        http.port=http_port;
        http.raw=true;
        http.start_tcp();
      }
      if(http.runned)
      {
        TAccServerCallback cb(this);
        http.update_tcp(cb);
        //mem.update(http,link);
      }
    }
  public:
    void update()
    {
      update_http();
    }
  };
public:
  t_account_server acc_serv;
  void update_account_server()
  {
    acc_serv.update();
  }
};
class TMutiplayerGameWithAcc:public TMutiplayerGame{
public:
  struct TClientRec{
    #define DEF_PRO_CLASSNAME()TClientRec
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(string,server_id,$)\
    ADD(int,id,-1)\
    ADD(string,token,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct TClientInfo{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(string,nick,$)\
    ADD(string,addr,$)\
    //===
    #include "defprovar.inl"
    //===
    TClientInfo(){DoReset();}
  };

  struct TServerInfo{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(vector<string>,clients,$)\
    //===
    #include "defprovar.inl"
    //===
    TServerInfo(){DoReset();}
  };

  struct TMachineInfo{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(vector<string>,servers,$)\
    //===
    #include "defprovar.inl"
    //===
    TMachineInfo(){DoReset();}
  };

  struct THttpTask{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(THttpRequest,request,$)\
    ADD(SOCKET,sock,SOCKET_ERROR)\
    ADD(string,answer,$)\
    ADD(string,name,$)\
    ADD(string,info,$)\
    //===
    #include "defprovar.inl"
    //===
    THttpTask(){DoReset();}
  };

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
    TGameServerAddr get_info()const{TGameServerAddr tmp;tmp.id=id;tmp.ip=ip;tmp.port=port;return tmp;}
  };

  static bool add_unique_value(vector<string>&arr,const string&value)
  {
    if(!qap_find_str(arr,value).empty())return false;
    qap_add_back(arr)=value;
    return true;
  }
  static string gen_token(){return cur_date_str()+";"+IToS(RAND_MAX*2+t_map::rnd());}
  struct TAccServerMem{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<THttpTask>,tasks,$)\
    ADD(vector<TMachineInfo>,machines,$)\
    ADD(vector<TServerInfo>,servers,$)\
    ADD(vector<TClientRec>,clients,$)\
    ADD(int,last_server_id,2000)\
    ADD(int,last_client_id,14000)\
    ADD(int,last_machine_id,1000)\
    //===
    #include "defprovar.inl"
    //===
    TAccServerMem(){DoReset();}
  public:
    PRO_FUNCGEN_GETP(THttpTask,get_task_by_name,tasks,name);
    PRO_FUNCGEN_GETP_BY_FIELD(TMachineInfo,get_machine_by_name,machines,const string&,name);
    PRO_FUNCGEN_GETP_BY_FIELD(TServerInfo,get_server_by_name,servers,const string&,name);
    PRO_FUNCGEN_GETP_BY_FIELD(TClientRec,get_client_by_id,clients,const int&,id);
    string get_new_server_id(){return IToS(last_server_id++);}
    int get_new_client_id(){return last_client_id++;}
    string get_new_machine_id(){return IToS(last_machine_id++);}
  public:
    bool update_task(GatewayServer<THttpSocket>&serv,GatewayServer<TLinkSocket>&link,THttpTask&task)
    {
      auto&mem=*this;
      auto gen_answer=t_answer::gen;
      auto ret=[&](const string&answer)->bool{task.answer=gen_answer("200;raw;win",answer).get(task.request);return true;};
      auto&request=task.request;
      string q=get_query(request.webpath);
      auto params=split(q,"&");
      auto f=[&](const string&param){return get_decoded_param_value(params,param);};
      if(link.clients.size())if(params_defined(params,"list_of_servers"))
      {
        auto&arr=link.clients;vector<TGameServerAddr> out;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          if(ex.port<0)continue;
          qap_add_back(out)=ex.get_info();
        }
        return ret("?list_of_servers="+HttpTool::urlencode(QapSaveToStr(out)));
      }
      if(!servers.empty())if(params_defined(params,"client,token"))
      {
        auto id=f("client");
        auto client_id=SToI(id);
        if(id!=IToS(client_id)){id="-1";client_id=-1;}
        auto*pc=get_client_by_id(client_id);
        if(pc)
        {
          if(!pc->server_id.empty()){
            QapDebugMsg("");
            return false;
          }
          auto&s=servers.back();
          if(auto*ptask=mem.get_task_by_name("srv"+s.name))
          {
            pc->server_id=s.name;
            ptask->answer=t_answer::gen("200;raw;win","?add_unit&id="+id+"&name="+id).get(ptask->request);
            return ret("?set_server_id="+s.name+"&set_actor_id="+id);
          }
        }
        if(!pc){id="-1";client_id=-1;}
        if(id.empty()||id=="-1")
        {
          auto token=gen_token();
          client_id=get_new_client_id();
          id=IToS(client_id);
          auto&b=qap_add_back(clients);
          b.id=client_id;
          b.token=token;
          return ret("?client_id="+id+"&token="+HttpTool::urlencode(token));
        }
        //pc->
        //add_unique_value(pm->servers,id);
      }
      if(params_defined(params,"machine"))
      {
        auto id=f("machine");
        if(id.empty()||id=="-1"){return ret("?machine_id="+get_new_machine_id());}
        auto*p=get_machine_by_name(id);
        if(!p)
        {
          p=&qap_add_back(machines);p->name=id;
          auto nsid=get_new_server_id();
          //qap_add_back(p->servers)=nsid;
          return ret("?add_server&id="+nsid);
        }
      }
      if(params_defined(params,"server,mid"))
      {
        auto id=f("server");auto mid=f("mid");
        if(id.empty()||id=="-1"){return ret("?server_id="+get_new_server_id());}
        auto*pm=get_machine_by_name(mid);
        QapAssert(pm);
        add_unique_value(pm->servers,id);
        auto*ps=get_server_by_name(id);
        if(!ps)
        {
          qap_add_back(servers).name=id;
        }
      }
      return false;
    }
    void update_tasks(GatewayServer<Socket>&serv,GatewayServer<TLinkSocket>&link)
    {
      for(int i=0;i<tasks.size();i++)
      {
        auto&ex=tasks[i];
        if(!ex.answer.empty())continue;
        if(update_task(serv,link,ex))return;
      }
    }
    void update(GatewayServer<Socket>&serv,GatewayServer<TLinkSocket>&link)
    {
      update_tasks(serv,link);
      for(int i=0;i<tasks.size();i++)
      {
        auto&ex=tasks[i];
        if(ex.answer.empty())continue;
        auto*p=serv.getClientBySock(ex.sock);
        if(p)
        {
          p->send_raw(ex.answer);
          shutdown(p->sock,SD_BOTH);
        }
        ex.sock=-1;
      }
      QapCleanIf(tasks,[&serv](THttpTask&ex)->bool{auto*p=serv.getClientBySock(ex.sock);return !p||ex.sock==-1;});
    }
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
    ADD(string,page_name,"/account_server")\
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
      auto answer_as_task=[&](const string&task_name)->t_answer{
        auto&t=qap_add_back(mem.tasks);t.name=task_name;t.request=request;t.info=cur_date_str();
        return gen_answer("task","");
      };
      if(params_defined(params,"client"))
      {
        string task_name="cnt"+f("client");
        return answer_as_task(task_name);
      }
      if(params_defined(params,"machine"))
      {
        auto id=f("machine");
        string task_name="m"+id;
        QapCleanIf(mem.tasks,[&task_name](THttpTask&ex){return ex.name==task_name;});
        return answer_as_task(task_name);
      }
      if(params_defined(params,"server,mid"))
      {
        auto id=f("server");
        string task_name="srv"+id;
        QapCleanIf(mem.tasks,[&task_name](THttpTask&ex){return ex.name==task_name;});
        return answer_as_task(task_name);
      }
      if(params_defined(params,"list_of_servers"))
      {
        string task_name="rndtask"+IToS(t_map::rnd()+RAND_MAX*2)+IToS(t_map::rnd()+RAND_MAX*2)+cur_date_str();
        QapCleanIf(mem.tasks,[&task_name](THttpTask&ex){return ex.name==task_name;});
        return answer_as_task(task_name);
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
    ADD(GatewayServer<TLinkSocket>,link,$)\
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
        auto&tasks=pOwner->mem.tasks;
        if(answer.type=="task"){
          THttpTask e;
          tasks.back().sock=client.sock;
          return;
        }
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
        mem.update(http,link);
      }
    }
  public:
    class TLinkServerCallback:public GatewayServer<TLinkSocket>::TCallback{
    public:
      struct t_packet{int sock;string data;};
      vector<t_packet> arr;
      vector<int> del;
    public:
      void OnRecvPack(TLinkSocket&client,std::string&data){
        auto&p=qap_add_back(arr);
        p.data=data;
        p.sock=client.sock;
      }
      void OnAddClient(TLinkSocket&client){
        int gg=1;
      }
      void OnDeleteClient(TLinkSocket&client){
        del.push_back(client.sock);
        int gg=1;
      }
    };
  public:
    void update_link()
    {
      if(!link.runned)
      {
        link=GatewayServer<TLinkSocket>();
        link.port=link_port;
        link.raw=false;
        link.start_tcp();
      }
      if(link.runned)
      {
        TLinkServerCallback cb;
        link.update_tcp(cb);
        for(int i=0;i<cb.arr.size();i++)
        {
          auto&ex=cb.arr[i];
          if(auto*p=link.getClientBySock(ex.sock))
          {
            string type;
            QapLoadFromStr(type,ex.data);
            if(type=="gen")if(p->sel_w())
            {
              int gg=1;
            }
            if(type=="hi")if(p->sel_w())if(p->id<0)
            {
              p->ip=p->ip2str();
              p->port=7021;
              p->send_pack_with_type("set_port",t_acc2srv_set_port::make(p->port));
            }
            //QapAssert(ex.sock.
            continue;
          }
        }
        for(int i=0;i<cb.del.size();i++)
        {
          auto&ex=cb.arr[i];
          int gg=1;
          //ex.sock
          //mem.get_server_by_name(
        }
      }
    }
  public:
    void update()
    {
      update_http();
      update_link();
    }
  };
public:
  t_account_server acc_serv;
  void update_account_server()
  {
    acc_serv.update();
  }
};
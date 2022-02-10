#define PARSE_PARAM_FROM_DL_BODY()\
  auto params=split(DownLoader::get_query(body),"&");\
  auto f=[&](char*param)->string{return DownLoader::get_decoded_param_value(params,param);};\
  auto has_params=[&](char*list)->bool{return DownLoader::params_defined(params,list);};
//

struct TGameServerAddr{
public:
  #define DEF_PRO_CLASSNAME()TGameServerAddr
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,id,-1)\
  ADD(string,ip,$)\
  ADD(int,port,-1)\
  //===
  #include "defprovar.inl"
  //===
};

struct t_acc2srv_set_port{
  #define DEF_PRO_CLASSNAME()t_acc2srv_set_port
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,port,-1)\
  //===
  #include "defprovar.inl"
  //===
  static string make(int port){t_acc2srv_set_port t;t.port=port;return QapSaveToStr(t);}
};

struct t_srv2cnt_set_rec{
  #define DEF_PRO_CLASSNAME()t_srv2cnt_set_rec
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,actor_id,-1)\
  ADD(int,client_id,-1)\
  ADD(string,token,$)\
  //===
  #include "defprovar.inl"
  //===
  static string make(int actor_id,int client_id,string token){t_srv2cnt_set_rec t;t.actor_id=actor_id;t.client_id=client_id;t.token=token;return QapSaveToStr(t);}
};

struct t_srv2acc_lock{
  #define DEF_PRO_CLASSNAME()t_srv2acc_lock
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,client_id,-1)\
  ADD(string,token,$)\
  //===
  #include "defprovar.inl"
  //===
  static string make(int client_id,string token){t_srv2cnt_set_rec t;t.client_id=client_id;t.token=token;return QapSaveToStr(t);}
};

class TMutiplayerGame:public TGame{
public:
  virtual bool use_dl(){return true;}
  virtual bool use_gs(){return true;}
public:
  struct t_cnt2srv_login{
    #define DEF_PRO_CLASSNAME()t_cnt2srv_login
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,cid,-1)\
    ADD(string,token,$)\
    //===
    #include "defprovar.inl"
    //===
    static string make(int cid,string token){t_cnt2srv_login t;t.cid=cid;t.token=token;return QapSaveToStr(t);}
  };
  struct t_sock2aid_pair{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(SOCKET,sock,SOCKET_ERROR)\
    ADD(int,aid,-1)\
    ADD(int,oper_id,-1)\
    //===
    #include "defprovar.inl"
    //===
  };
  class t_server{
  public:
    #define DEF_PRO_UNSAVEABLE()
    #define DEF_PRO_CLASSNAME()t_server
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_world,world,$)\
    ADD(vector<t_input>,inputs,$)\
    ADD(Socket,link,$)\
    ADD(int,port,-1)\
    ADD(GatewayServer<Socket>,GS,$)\
    ADD(vector<t_sock2aid_pair>,sock2aid,$)\
    ADD(int,last_oper_id,1000)\
    //===
    #include "defprovar.inl"
    //===
  public:
    PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD(t_sock2aid_pair,add_unique_pair_by_sock,sock2aid,int,sock);
    PRO_FUNCGEN_GETP_BY_FIELD(t_sock2aid_pair,get_pair_by_sock,sock2aid,int,sock);
    PRO_FUNCGEN_GETP_BY_FIELD(t_sock2aid_pair,get_pair_by_oper_id,sock2aid,int,oper_id);
    t_sock2aid_pair&add_pair(int actor_id,int sock){
      QapAssert(!get_pair_by_sock(sock));
      auto&r=*add_unique_pair_by_sock(sock);
      r.aid=actor_id;
      r.sock=sock;
      r.oper_id=last_oper_id++;
      return r;
    }
    int sock2actor_id(int sock){auto*p=get_pair_by_sock(sock);return p?p->aid:-1;}
    string get_srv_id()const{return IToS(world.input.server_id);}
    //void update_dl(TMutiplayerGame&game)
    //{
    //  if(!game.use_dl())return;
    //  QapAssert(game.srvpass&&game.movepass);
    //  if(!DL.active)
    //  {
    //    DL=std::move(DownLoader());
    //    DL.start_ex("localhost:7020/account_server?server="+get_srv_id()+"&mid="+IToS(game.machine_id));
    //  }
    //  if(!DL.update())for(auto body=DL.get_body();!body.empty();body="")
    //  {
    //    handle_response_body(body);
    //  }
    //}
    void handle_response_body(const string&body)
    {
      PARSE_PARAM_FROM_DL_BODY();
      if(has_params("server_id"))
      {
        auto id=f("server_id");
        world.input.server_id=SToI(id);
      }
      if(has_params("add_unit,id,name"))
      {
        auto id=f("id");auto name=f("name");
        auto&b=world.add_unit(name);
        b.input.actor_id=SToI(id);
        b.input.server_id=world.input.server_id;
      }
      if(has_params("user,gold"))
      {
        auto user=f("user");
        auto gold=f("gold");
        auto*p=world.get_unit_by_name(user);
        if(p)
        {
          p->gold+=SToI(gold);
        }
      }
      int gg=1;
    }
    void update_dl(TMutiplayerGame&game)
    {
      if(link.sock==SOCKET_ERROR)
      {
        bool ok=link.connect_noblock("localhost",7010);
        QapAssert(ok);
      }
      if(link)
      {
        if(link.sel_w()&&!link.connected)
        {
          link.connected=true;
          link.send(QapSaveToStr(string("hi")));
        }
        if(link.sel_r())
        {
          if(link.recv_raw()<1)
          {
            link=Socket();
          }
          string msg;
          for(;;)
          {
            bool flag=link.unpack(msg)!=-1;
            if(!flag)break;
            TDataIO IO;IO.IO.mem=msg;
            string type;
            QapLoad(IO,type);
            if(type=="response")
            {
              string body;
              QapLoad(IO,body);
              handle_response_body(body);
              int gg=1;
              continue;
            }
            if(type=="set_port")
            {
              t_acc2srv_set_port a2s;
              QapLoad(IO,a2s);
              port=a2s.port;
              int gg=1;
              continue;
            }
            QapDebugMsg("unknow msg from account_server:\n"+type);
          }
        }
      }
    }
    class TServerCallback:public GatewayServer<Socket>::TCallback{
    public:
      struct t_packet{int sock;string data;};
      vector<t_packet> arr;
      vector<int> del;
    public:
      void OnRecvPack(Socket&client,std::string&data){
        auto&p=qap_add_back(arr);
        p.data=data;
        p.sock=client.sock;
      }
      void OnAddClient(Socket&client){
        int gg=1;
      }
      void OnDeleteClient(Socket&client){
        del.push_back(client.sock);
        int gg=1;
      }
    };
    void update_gs(TMutiplayerGame&game)
    {
      if(port<0)return;
      if(!game.use_gs())return;
      QapAssert(game.srvpass&&game.movepass);
      if(!GS.runned)
      {
        GS.port=port;
        GS.raw=false;
        GS.start_tcp();
      }
      TServerCallback cb;
      GS.update_tcp(cb);
      for(int i=0;i<cb.arr.size();i++)
      {
        auto&ex=cb.arr[i];
        TDataIO IO;IO.IO.mem=ex.data;
        string type;
        QapLoad(IO,type);
        //if(!get_pair_by_sock(ex.sock))
        if(type=="login")
        {
          auto*p=GS.getClientBySock(ex.sock);QapAssert(p);
          t_cnt2srv_login ref;
          QapLoadFromStr(ref,ex.data);
          auto&pair=add_pair(-1,ex.sock);
          if(link&&link.sel_w()){
            if(ref.cid<0){
              link.send_pack_with_type("gen",IToS(pair.oper_id));
            }else{
              link.send_pack_with_type("lock",t_srv2acc_lock::make(ref.cid,ref.token));
            }
          }else QapNoWay();
          //ref.cid
          //if(p->sel_w())
          //{
          //  p->send(QapSaveToStr(string("done"))+"");
          //}
          //QapAssert(ex.sock.
          continue;
        }
        QapAssert(type=="input");
        auto&b=qap_add_back(inputs);
        QapLoad(IO,b);
        auto aid=sock2actor_id(ex.sock);
        if(b.actor_id!=aid)
        {
          if(auto*p=GS.getClientBySock(ex.sock))if(p->sel_w())
          {
            QapNoWay();
            p->send_pack_with_type("error","wrong actor_id in input");
            shutdown(p->sock,SD_BOTH);
          }
          QapDebugMsg("wrong actor_id in input");
          inputs.pop_back();
        }
        //add_rec(b.actor_id,ex.sock);
      }
      for(int i=0;i<cb.del.size();i++)
      {
        auto*p=get_pair_by_sock(cb.del[i]);
        p->deaded=true;
        auto*pu=world.getp(p->aid);
        pu->deaded=true;
      }
      qap_clean_if_deaded(sock2aid);
    }
    void soUpdate(TMutiplayerGame&game)
    {
      update_dl(game);
      update_gs(game);
      for(int i=0;i<inputs.size();i++)
      {
        auto&ex=inputs[i];
        QapAssert(ex.actor_id>=0);
        auto*p=world.getp(ex.actor_id);
        if(p){
          p->input=ex;
          p->tick_from_last_input=ex.game_tick;
        }
      }
      world.soUpdate(game);
      if(game.movepass)inputs.clear();
    }
  };
  class t_client_rec{
  public:
    #define DEF_PRO_CLASSNAME()t_client_rec
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,client_id,-1)\
    ADD(string,token,"")\
    //===
    #include "defprovar.inl"
    //===
  };
  class t_client{
  public:
    #define DEF_PRO_UNSAVEABLE()
    #define DEF_PRO_CLASSNAME()t_client
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_world,world,$)\
    ADD(string,client_fn,$)\
    ADD(t_client_rec,rec,$)\
    ADD(DownLoader,DL,$)\
    ADD(string,server_ip_port_id,$)\
    ADD(Socket,sock,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    void update_dl_old(TMutiplayerGame&game)
    {
      if(!game.use_dl())return;
      auto&client_id=rec.client_id;
      auto&server_id=world.input.server_id;
      auto&actor_id=world.input.actor_id;
      if(client_id>=0&&server_id>=0&&actor_id>=0)return;
      if(game.movepass)
      {
        if(!DL.active)
        {
          DL=std::move(DownLoader());
          DL.start_ex("localhost:7020/account_server?client="+IToS(client_id)+"&token="+HttpTool::urldecode(rec.token));
        }
        if(!DL.update())for(auto body=DL.get_body();!body.empty();body="")
        {
          PARSE_PARAM_FROM_DL_BODY();
          if(has_params("client_id,token"))
          {
            auto id=f("client_id");
            client_id=SToI(id);//t_client_rec::ProxySys$$;
            rec.token=f("token");
            if(!client_fn.empty())file_put_contents(client_fn,QapSaveToStr(rec));
          }
          if(has_params("set_server_id"))
          {
            auto id=f("set_server_id");
            server_id=SToI(id);
          }
          if(has_params("set_actor_id"))
          {
            auto id=f("set_actor_id");
            actor_id=SToI(id);
          }
          int gg=1;
        }
      }
    }
    void update_dl(TMutiplayerGame&game)
    {
      if(!game.use_dl())return;
      if(!server_ip_port_id.empty())return;
      if(game.movepass)
      {
        if(!DL.active)
        {
          DL=std::move(DownLoader());
          DL.start_ex("localhost:7020/account_server?list_of_servers");
        }
        if(!DL.update())for(auto body=DL.get_body();!body.empty();body="")
        {
          PARSE_PARAM_FROM_DL_BODY();
          if(has_params("list_of_servers"))
          {
            auto str=f("list_of_servers");
            vector<TGameServerAddr> arr;
            QapLoadFromStr(arr,str);
            if(arr.size()>0){
              auto&s=arr[0];
              server_ip_port_id=s.ip+":"+IToS(s.port)+":"+IToS(s.id);
            }
            break;
          }
          QapNoWay();
          int gg=1;
        }
      }
    }
    void update_gs(TMutiplayerGame&game)
    {
      if(server_ip_port_id.empty())return;
      if(!game.use_gs())return;
      if(sock.sock==SOCKET_ERROR)
      {
        auto arr=split(server_ip_port_id,":");auto ip=arr[0];auto port=SToI(arr[1]);
        bool ok=sock.connect_noblock(ip,port);
        QapAssert(ok);
      }
      if(sock)
      {
        if(!sock.connected&&sock.sel_w())
        {
          sock.connected=true;
          sock.send_pack_with_type("login",t_cnt2srv_login::make(rec.client_id,rec.token));
        }
        if(sock.sel_r())
        {
          if(sock.recv_raw()<1)
          {
            sock=Socket();
          }
          string msg;
          for(;;)
          {
            bool flag=sock.unpack(msg)!=-1;
            if(!flag)break;
            TDataIO IO;IO.IO.mem=msg;
            string type;
            QapLoad(IO,type);
            if(type=="set_rec")
            {
              t_srv2cnt_set_rec tmp;
              QapLoad(IO,tmp);
              rec.client_id=tmp.client_id;
              rec.token=tmp.token;
              world.input.actor_id=tmp.actor_id;
            }
            if(type=="world")
            {
              copy_without_input(world,IO);continue;
            }
            if(type=="done")
            {
              int gg=1;
              continue;
            }
            QapDebugMsg("unknow msg from server:\n"+type);
          }
        }
      }
    }
    void soUpdate(TMutiplayerGame&game)
    {
      update_dl(game);
      if(game.drawpass)
      {
        game.qDev.color=0xff000000;
        auto sid=world.input.server_id;
        auto aid=world.input.actor_id;
        bool flag=sid<0||aid<0;
        if(flag)qap_text::draw(game.qDev,vec2i(0,00),"server_id = "+IToS(sid),world.textsize);
        if(flag)qap_text::draw(game.qDev,vec2i(0,-64),"actor_id = "+IToS(aid),world.textsize);
        if(flag)return;
      }
      world.soUpdate(game);
      if(game.movepass){
        world.input.kb=game.kb;
        world.input.zDelta=game.win.zDelta;
        world.input.mpos=game.mpos;
        world.input.consize=game.consize;
        world.input.game_tick=world.tick;
      }
      if(game.movepass)
      {
        update_gs(game);
      }
    }
  };
public:
  #define DEF_PRO_UNSAVEABLE()
  #define DEF_PRO_CLASSNAME()TMutiplayerGame
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_server>,servers,$)\
  ADD(vector<t_client>,clients,$)\
  ADD(DownLoader,machine,$)\
  ADD(int,machine_id,-1)\
  //===
  #include "defprovar.inl"
  //===
public:
  PRO_FUNCGEN_GETP_BY_FIELD(t_server,get_server_by_id,servers,int,world.input.server_id);
  virtual void init_server(t_server&server){QapNoWay();}
  void update_dl()
  {
    if(!use_dl())return;
    auto&DL=machine;
    static QapClock clock;
    if(!DL.active)
    {
      DL=std::move(DownLoader());
      DL.start_ex("localhost:7020/account_server?machine="+IToS(machine_id));
      clock.Start();
    }
    if(!DL.update())for(auto body=DL.get_body();!body.empty();body="")
    {
      PARSE_PARAM_FROM_DL_BODY();
      clock.Stop();
      auto ms=clock.MS();
      if(has_params("machine_id"))
      {
        auto id=f("machine_id");
        machine_id=SToI(id);
      }
      if(has_params("add_server,id"))
      {
        auto&s=qap_add_back(servers);
        init_server(s);
        s.world.input.server_id=SToI(f("id"));
      }
    }
  }
  void move_inputs_to_server(int vps_size)
  {
    if(!use_gs())
    {
      for(int i=0;i<vps_size;i++)
      {
        auto&ex=clients[i].world.input;
        auto*p=get_server_by_id(ex.server_id);
        if(!p)continue;
        //qap_add_back(p->inputs)=ex;
      }
      return;
    }
    for(int i=0;i<vps_size;i++)
    {
      auto&ex=clients[i].world.input;
      if(ex.actor_id<0||ex.server_id<0)continue;
      auto&sock=clients[i].sock;
      if(sock&&sock.sel_w())
      {
        auto inp=QapSaveToStr(ex);
        sock.send_pack_with_type("input",inp);
      }
    }
  }
  void send_world_vps_based(int vps_size)
  {
    for(int i=0;i<vps_size;i++)
    {
      auto&client=clients[i];
      auto server_id=client.world.input.server_id;
      auto actor_id=client.world.input.actor_id;
      if(server_id<0)continue;
      QapAssert(server_id>=0);
      auto*pserver=get_server_by_id(server_id);QapAssert(pserver);
      copy_without_input(client.world,pserver->world);
    }
  }
  void send_world_gs_based()
  {
    for(int j=0;j<servers.size();j++)
    {
      auto&serv=servers[j];
      auto&arr=serv.GS.clients;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto aid=serv.sock2actor_id(ex.sock);
        if(aid<0)continue;
        TDataIO IO;
        QapSave(IO,string("world"));
        copy_without_input(IO,aid,serv.world);
        if(ex.sel_w())ex.send(IO.IO.mem);
      }
    }
  }
  virtual void update_account_server(){}
  void soUpdate()
  {
    static bool use_clients=get_last_cmdline_param()!="gameserver";
    static bool use_servers=get_last_cmdline_param()=="gameserver";
    static bool use_account=get_last_cmdline_param()=="accserver";
    if(use_account)update_account_server();
    QapDev::BatchScopeEx scope(qDev,drawpass);
    if(movepass)
    {
      if(kb.Down[VK_ESCAPE])win.Close();
    }
    if(movepass)update_dl();
    //if(movepass)update_gs();
    auto clients_on_screen=clients.size();clients_on_screen=!use_clients?0:1;// <---------------------------------------------------------------- [||| NUM |||]
    vector<t_quad> vps=split_quad_by_dir(viewport,'x',clients_on_screen);
    if(use_clients)if(movepass)
    {
      move_inputs_to_server(vps.size());
    }
    if(use_servers)if(movepass)
    {
      srvpass=true;
      //:servers
      for(int i=0;i<servers.size();i++)
      {
        auto&ex=servers[i];
        ex.soUpdate(*this);
      }
      if(use_gs()){
        send_world_gs_based();
      }
      if(!use_gs()){
        send_world_vps_based(vps.size());
      }
      srvpass=false;
    }
    qDev.use_viewport=clients_on_screen>1;
    qDev.auto_clamp=qDev.use_viewport;
    //:clients
    {
      cntpass=true;
      for(int i=0;i<vps.size();i++)
      {
        QapDev::ViewportScope scope(qDev,vps[i]);
        auto old_mpos=mpos;
        mpos-=vec2i::fromVec2d(viewport.pos);
        clients[i].soUpdate(*this);
        mpos=old_mpos;
      }
      cntpass=false;
    }
    qDev.use_viewport=false;
    if(drawpass){for(int i=0;i<vps.size();i++)DrawQuadBorder(vps[i]);}
  }
};
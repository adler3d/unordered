#define PARSE_PARAM_FROM_DL_BODY()\
  auto params=split(DownLoader::get_query(body),"&");\
  auto f=[&](char*param)->string{return DownLoader::get_decoded_param_value(params,param);};\
  auto has_params=[&](char*list)->bool{return DownLoader::params_defined(params,list);};
//
class TMutiplayerGame:public TGame{
public:
  class t_server{
  public:
    #define DEF_PRO_CLASSNAME()t_server
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_world,world,$)\
    ADD(vector<t_input>,inputs,$)\
    ADD(DownLoader,DL,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    string get_srv_id()const{return IToS(world.input.server_id);}
    void soUpdate(TMutiplayerGame&game)
    {
      QapAssert(game.srvpass&&game.movepass);
      if(!DL.active)
      {
        DL=std::move(DownLoader());
        DL.start_ex("localhost:7020/account_server?server="+get_srv_id()+"&mid="+IToS(game.machine_id));
      }
      if(!DL.update())for(auto body=DL.get_body();!body.empty();body="")
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
  class t_client{
  public:
    #define DEF_PRO_CLASSNAME()t_client
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_world,world,$)\
    ADD(int,client_id,-1)\
    ADD(DownLoader,DL,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    void soUpdate(TMutiplayerGame&game)
    {
      if(game.movepass)
      {
        if(!DL.active)
        {
          DL=std::move(DownLoader());
          DL.start_ex("localhost:7020/account_server?client="+IToS(client_id));
        }
        if(!DL.update())for(auto body=DL.get_body();!body.empty();body="")
        {
          PARSE_PARAM_FROM_DL_BODY();
          if(has_params("client_id"))
          {
            auto id=f("client_id");
            client_id=SToI(id);
          }
          if(has_params("set_server_id"))
          {
            auto id=f("set_server_id");
            world.input.server_id=SToI(id);
          }
          if(has_params("set_actor_id"))
          {
            auto id=f("set_actor_id");
            world.input.actor_id=SToI(id);
          }
          int gg=1;
        }
      }
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
    }
    //void copy_without_input(const t_world&w){auto buff=world.input;world=w;world.input=buff;}
  };
public:
  #define DEF_PRO_CLASSNAME()TMutiplayerGame
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_server>,servers,$)\
  ADD(vector<t_client>,clients,$)\
  ADD(vector<t_looped_buffer<t_input>>,tmp,$)\
  ADD(vector<t_looped_buffer<t_world>>,worlds,$)\
  ADD(DownLoader,machine,$)\
  ADD(int,machine_id,-1)\
  //===
  #include "defprovar.inl"
  //===
public:
  PRO_FUNCGEN_GETP_BY_FIELD(t_server,get_server_by_id,servers,int,world.input.server_id);
  virtual void init_server(t_server&server){QapNoWay();}
  void soUpdate()
  {
    QapDev::BatchScopeEx scope(qDev,drawpass);
    if(movepass)
    {
      if(kb.Down[VK_ESCAPE])win.Close();
    }
    if(movepass)
    {
      auto&DL=machine;
      static QapClock clock;
      for(int iter=0;;iter++)
      {
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
        if(!servers.empty())break;
        Sleep(16);
      }
    }
    auto clients_on_screen=clients.size();clients_on_screen=2;
    vector<t_quad> vps=split_quad_by_dir(viewport,'x',clients_on_screen);
    if(movepass)
    {
      bool fail=false;//!(t_map::rnd()%64<16);
      if(tmp.empty())tmp.resize(vps.size());//tmp[0].n=2;tmp[1].n=2;
      vector<t_input> inputs;
      vector<t_input> olds;
      for(int i=0;i<vps.size();i++)qap_add_back(inputs)=clients[i].world.input;
      for(int i=0;i<vps.size();i++)qap_add_back(olds)=tmp[i].add(std::move(inputs[i]));
      //auto old=tmp.add(std::move(inputs));
      if(!fail)for(int i=0;i<vps.size();i++){
        if(olds[i].actor_id<0)continue;
        auto&ex=olds[i];
        auto*p=get_server_by_id(ex.server_id);
        if(!p)continue;
        qap_add_back(p->inputs)=ex;//clients[i].world.input;
      }
      //server.inputs=olds;
      srvpass=true;
      for(int i=0;i<servers.size();i++)
      {
        auto&ex=servers[i];
        ex.soUpdate(*this);
      }
      QapClock clock; clock.Start();
      if(worlds.empty())worlds.resize(vps.size());//worlds[0].n=2;worlds[1].n=2;
      if(!fail)for(int i=0;i<vps.size();i++)
      {
        auto&w=worlds[i].add();
        auto&ex=clients[i];if(ex.world.input.server_id<0)continue;
        auto server_id=ex.world.input.server_id;QapAssert(server_id>=0);
        auto*pserver=get_server_by_id(server_id);QapAssert(pserver);
        if(w.input.actor_id<0)
        {
          auto*punit=pserver->world.getp(ex.world.input.actor_id);
          if(punit){
            w.input=punit->input;
          }
        }
        if(w.tick>=0)
        {
          copy_without_input(ex.world,w);
        }
        copy_without_input(w,pserver->world);
        //copy_without_input(clients[i].world,server.world);
      }
      clock.Stop();
      static real total_ms=0; static int n=0;
      total_ms+=clock.MS();n++;
      auto avr_ms=total_ms/n;
      srvpass=false;
    }
    qDev.use_viewport=clients_on_screen>1;
    //qDev.use_viewport=true;
    qDev.auto_clamp=qDev.use_viewport;
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
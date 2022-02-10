  struct t_server{
    t_world world;
    vector<t_input> inputs;
    void soUpdate(TGame&game)
    {
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
  struct t_client{
    t_world world;
    void soUpdate(TGame&game)
    {
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
  t_server server;
  vector<t_client> clients;
  void soUpdate()
  {
    QapDev::BatchScopeEx scope(qDev,drawpass);
    if(movepass)
    {
      if(kb.Down[VK_ESCAPE])win.Close();
    }
    auto clients_on_screen=clients.size();clients_on_screen=1;
    vector<t_quad> vps=split_quad_by_dir(viewport,'x',clients_on_screen);
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
    if(movepass)
    {
      bool fail=false;//!(t_map::rnd()%64<16);
      static vector<t_looped_buffer<t_input>> tmp;if(tmp.empty())tmp.resize(vps.size());//tmp[0].n=2;tmp[1].n=2;
      vector<t_input> inputs;
      vector<t_input> olds;
      for(int i=0;i<vps.size();i++)qap_add_back(inputs)=clients[i].world.input;
      for(int i=0;i<vps.size();i++)qap_add_back(olds)=tmp[i].add(std::move(inputs[i]));
      //auto old=tmp.add(std::move(inputs));
      //tmp.add(
      /*if(0)*/if(!fail)for(int i=0;i<vps.size();i++){
        if(olds[i].actor_id<0)continue;
        qap_add_back(server.inputs)=olds[i];//clients[i].world.input;
      }
      //server.inputs=olds;
      srvpass=true;
      server.soUpdate(*this);
      QapClock clock; clock.Start();
      static vector<t_looped_buffer<t_world>> worlds;if(worlds.empty())worlds.resize(vps.size());//worlds[0].n=2;worlds[1].n=2;
      if(!fail)for(int i=0;i<vps.size();i++){
        auto&w=worlds[i].add();
        if(w.input.actor_id<0)w.input=server.world.units[i].input;
        if(w.tick>=0)
        {
          copy_without_input(clients[i].world,w);
        }
        copy_without_input(w,server.world);
        //copy_without_input(clients[i].world,server.world);
      }
      clock.Stop();
      static real total_ms=0; static int n=0;
      total_ms+=clock.MS();n++;
      auto avr_ms=total_ms/n;
      srvpass=false;
    }
  }
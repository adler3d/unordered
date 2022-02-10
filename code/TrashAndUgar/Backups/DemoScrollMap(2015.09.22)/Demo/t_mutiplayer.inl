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
        QapAssert(p);
        p->input=ex;
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
      }
    }
    void copy_without_input(const t_world&w){auto buff=world.input;world=w;world.input=buff;}
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
    if(!qap_check_id(clients,client_id))client_id=-1;
    vector<t_quad> vps=split_quad_by_dir(viewport,'x',client_id<0?clients.size():1);
    qDev.use_viewport=true;
    {
      cntpass=true;
      for(int i=0;i<vps.size();i++)
      {
        QapDev::ViewportScope scope(qDev,vps[i]);
        auto old_mpos=mpos;
        mpos-=vec2i::fromVec2d(viewport.pos);
        clients[client_id<0?i:client_id].soUpdate(*this);
        mpos=old_mpos;
      }
      cntpass=false;
    }
    qDev.use_viewport=false;
    if(drawpass){for(int i=0;i<vps.size();i++)DrawQuadBorder(vps[i]);}
    if(movepass)
    {
      for(int i=0;i<vps.size();i++){
        qap_add_back(server.inputs)=clients[client_id<0?i:client_id].world.input;
      }
      srvpass=true;
      server.soUpdate(*this);
      QapClock clock; clock.Start();
      for(int i=0;i<vps.size();i++){
        clients[client_id<0?i:client_id].copy_without_input(server.world);
      }
      clock.Stop();
      static real total_ms=0; static int n=0;
      total_ms+=clock.MS();n++;
      auto avr_ms=total_ms/n;
      srvpass=false;
      if(kb.Down(VK_CONTROL)&&kb.OnDown(VK_TAB))client_id++;
    }
  }
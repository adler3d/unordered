  struct t_brains:i_sim_elem_v2{
    struct t_player:t_ps_counter_v2{
      t_plan_with_side buff;
    };
    t_player tmp[2];
    t_player*pa;
    t_player*pb;
    t_break br;
    t_result_b res;
    vector<i_sim_elem_v2*> elems;
  }
  void fdgdjgfjfjfgj(...){

    
    t_host_with_score hws;
    hws.host=get_by_id(-1,"empty",1,"");
    
    auto arr=build_gen_vs_hws(hws...);
      arr=gen_arr(...).map
        e is t_brains
        e+=hws;
        e+=rnd_plan_with_info();
        e.sim();
      hws+=qapsum(arr);
      return arr;
    
    
    
    arr.map
      e is t_brains
      //e.update_winrate_vs(some_enemy_set)
      hb=e.mk_new_hws_for_player_b();
      build_gen_vs_hws(hb,...);
      e.pb->winrate=hb.winrate;{
        winrate
        force
        samples
        fails
        equals
      }
  
  }
  void mainloop()
  {
    auto enemy=get_by_id(-1,"empty",1,"");
    vector<t_generation> gens;size_t N=256;auto world_id=3+6*0;
    
    update_win_rate_v2(world_id,&qap_add_back(gens),host,N,false,"EL");
    
    //build_gen_vs_pws(qap_add_back(gens),enemy,N,false,"EL",3+6*0);
    auto&arr=gens[0].arr;
    auto buff=arr;
    size_t base_n=15;
    #define F(L,N)if(buff.size()*4<=L)base_n=N; 
    F(100,16);
    F(50,25);
    F(25,32);
    F(16,64);
    F(8,128);
    F(4,256);
    F(2,512);
    #undef F
    for(;;){
      cout<<"====="<<endl;
      qap_sort(buff);
      QAP_FOREACH(buff,ex.upd_ptrs());
      if(buff.size()/3<=1)break;
      buff.resize(buff.size()/3);
      for(int i=0;i<buff.size();i++){
        auto&ex=buff[i];
        t_result host_ex;
        host_ex.put_and_ret_other(*ex.b.pws);
        host_ex.res.world_id=3+6*0;
        update_win_rate_v2(world_id,nullptr,host_ex,base_n,true,"EL");
        ex.b.res+=host_ex.a.res;
      }
      //QAP_FOREACH(buff,update_win_rate_v2(nullptr,host_ex,base_n,true,"EL"));
      if(buff.size()<=10)base_n=500;
      if(buff.size()<=5)base_n=1000;
      base_n*=2;
    }
    cout<<"====="<<endl;
    auto id=QAP_MINVAL_ID_OF_VEC(buff,ex.b.res.get_score());
    auto&win=buff[id];
    cout<<"\n\n..........\n\n"<<endl;
    cout<<"clock.MS() = "<<clock.MS()<<endl;
    cout<<"arr.size() = "<<arr.size()<<endl;
    cout<<"host.a.pws->to_code() = "<<host.a.pws->to_code()<<endl;
    cout<<" win.a.pws->to_code() = "<<win.a.pws->to_code()<<endl;
    cout<<"host.to_str() = "<<host.to_str()<<endl;
    cout<<"win.to_str() = "<<win.to_str()<<endl;
    auto&wpws=win.get_pws();
    auto&wbres=win.b.res;
    cout<<"sucks vs "<<wpws.plan_id<<" at iter "<<wbres.iter<<", force_vs_rnd is "<<FToS(wbres.get_force())<<"%, host.force is "<<FToS(host.b.res.get_force())<<"%"<<endl;
  }
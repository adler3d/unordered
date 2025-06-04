    auto drop_when_lose_vs_host=[&](const string&host_name,t_player&host,vector<t_player>&earr){
      cout<<host_name<<" = "<<host.pws.to_code()<<"\n"<<endl;
      host_vs_earr(world_id,host,earr,false);
      clean_if(earr,[](t_player&ex)->int{return ex.res.number_of_deads_v2()>0;});
    };

        auto run_vs=[&](const string&host_name,t_player&host,vector<t_player>&earr,bool need_clean){
          //drop_when_lose_vs_host(host_name,host,earr);
          cout<<host_name<<" = "<<host.pws.to_code()<<"\n"<<endl;
          host_vs_earr(world_id,host,earr,false);
          if(need_clean)clean_if(earr,[](t_player&ex)->int{return ex.res.number_of_deads_v2()>0;});
          if(!need_clean)QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
        };

struct t_two_top{
  vector<t_player> earr,marr;
  void spawn(t_plan_generator&PG,size_t N=100){
    gen_players(PG,earr,N,0);
    gen_players(PG,marr,N,1);
  }
  void resize(int N){
    marr.resize(out_n);
    earr.resize(out_n);
  }
  void full_run(int world_id){
    QAP_FOREACH(marr,{
      run_vs(world_id,"marr["+IToS(i)+"]",ex,earr,false);
    });
  }
  void run_vs_top(int world_id,t_two_top&top){
    for(int i=0;i<top.marr.size();i++){
      auto&host=top.marr[i];
      drop_when_lose_vs_host(world_id,"top.marr["+IToS(i)+"]",host,earr);
      if(earr.empty())break;
    }
    for(int i=0;i<top.earr.size();i++){
      auto&host=top.earr[i];
      drop_when_lose_vs_host(world_id,"top.earr["+IToS(i)+"]",host,marr);
      if(marr.empty())break;
    }
  }
  void draw(){
    draw(marr);
    draw(earr);
  }
  void make_first_top(int world_id,,size_t out_n=50,t){
    
    

  }

  static void main(){
    t_two_top top;
    top.spawn(100);
    top.full_run(0);
    top.draw();
    
    t_two_top super;
    for(int i=0;i<10;i++){
      t_two_top noobs;
      noobs.spawn(1000);
      noobs.run_vs_top(0,top);
      noobs.draw();
      super.marr+=noobs.marr;
      super.earr+=noobs.earr;
    }
    super.draw();
    super.full_run(0);
    top.draw();
  }
};
  
        
  t_plan_with_side ML_impl_v4(t_WI wi,size_t N=100,size_t out_n=50,t_plan_with_side*penemy=nullptr){
    string WI=wi.tostr();
    const int world_id=wi.map+6*wi.car;
    string head="world_id:"+IToS(world_id)+",side:"+IToS(wi.side);
    QapClock clock;

    t_plan_generator PG;
    PG.init_with(string(seed));
  
    vector<t_player> earr,marr;
    gen_players(PG,earr,N,0);
    gen_players(PG,marr,N,1);
    
    QAP_FOREACH(marr,{
      run_vs("marr["+IToS(i)+"]",ex,earr,false);
    });
    
    marr.resize(out_n);
    earr.resize(out_n);
    
        auto eh=pws2player(this->get_by_id(-1,"empty",wi.side?0:1,WI));
        gen_players(PG,tmp_earr,base_n*100,empty.pId);
        vector<t_player> like_our;
        gen_players(PG,like_our,base_n*5,eh.pws.pId);
        run_vs("run_vs.host",eh,tmp_earr,true);
        QAP_FOREACH(like_our,{
          run_vs("run_vs.host["+IToS(i)+"]",ex,tmp_earr,false);
        });
        clean_if_v2(tmp_earr,[&](t_player&ex,int id){return id>=base_n;});
        QAP_FOREACH(tmp_earr,cout<<"like_tmp_host = "<<ex.pws.to_code()<<"\n"<<endl;);
    
    for(bool start=true;;start=false)
    {
      cout<<"=====bef("+head+",LEFT:"<<earr.size()<<")"<<endl;
      QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
      if(!start){
        auto EN=earr.size();
        int deadline=std::max<int>(1,earr.size()*42/100);
        deadline=std::min<int>(deadline,4096);
        auto&top1=earr[0].res;auto top1_nd=top1.number_of_deads_v2();auto top1_force=top1.get_force();auto top1_samples=int(top1.samples);
        clean_if_v2(earr,[EN,deadline,top1_nd,const_base_n,top1_force](t_player&ex,int id){
          return id>=deadline&&(
            ex.res.number_of_deads_v2()>=top1_nd+const_base_n||
            (ex.res.get_force()+12.5<top1_force)||
            (EN>20000&&ex.res.number_of_deads_v2()>=top1_nd+1)||
            (EN>10000&&ex.res.number_of_deads_v2()>=top1_nd+2)||
            (EN>5000&&ex.res.number_of_deads_v2()>=top1_nd+3)
          );
        });
        if(earr.size()<=1||top1_samples>16000)break;
        //buff.resize(buff.size()/3);
        cout<<"=====aft("+head+",LEFT:"<<earr.size()<<")"<<endl;
      }
      base_n++;
      vector<t_player> tmp_earr;
      if(start&&earr.size()>1000){
        auto eh=pws2player(this->get_by_id(-1,"empty",wi.side?0:1,WI));
        gen_players(PG,tmp_earr,base_n*100,empty.pId);
        auto run_vs=[&](const string&host_name,t_player&host,vector<t_player>&earr,bool need_clean){
          //drop_when_lose_vs_host(host_name,host,earr);
          cout<<host_name<<" = "<<host.pws.to_code()<<"\n"<<endl;
          host_vs_earr(world_id,host,earr,false);
          if(need_clean)clean_if(earr,[](t_player&ex)->int{return ex.res.number_of_deads_v2()>0;});
          if(!need_clean)QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
        };
        vector<t_player> like_our;
        gen_players(PG,like_our,base_n*5,eh.pws.pId);
        run_vs("run_vs.host",eh,tmp_earr,true);
        QAP_FOREACH(like_our,{
          run_vs("run_vs.host["+IToS(i)+"]",ex,tmp_earr,false);
        });
        clean_if_v2(tmp_earr,[&](t_player&ex,int id){return id>=base_n;});
        QAP_FOREACH(tmp_earr,cout<<"like_tmp_host = "<<ex.pws.to_code()<<"\n"<<endl;);
      }else{
        gen_players(PG,tmp_earr,base_n,empty.pId);
      }
      for(int i=0;i<earr.size();i++){
        auto&ex=earr[i];
        host_vs_earr(world_id,ex,tmp_earr,true);
      }
    }
    cout<<"=====("+head+",LEFT:"<<earr.size()<<")"<<endl;
    auto id=QAP_MINVAL_ID_OF_VEC(earr,ex.res.get_score());
    auto&win=earr[id];
    auto&wpws=win.pws;
    auto&wres=win.res;
    auto&ores=win.old;
    string msg="win vs "+host.pws.to_code(true)+" at iter "+IToS(ores.iter)+", avg_iter "+FToS(wres.avg_iter())+", force_vs_rnd is "+FToS(wres.get_force())+"%";
      msg+=", host.force is "+FToS(host.res.get_force())+"%";
      msg+=", samples:"+IToS(wres.samples);
      msg+=", WI:"+WI;
      msg+=", ms:"+IToS(clock.MS());
    wpws.info=msg;
    cout<<"\n\n..........\n\n"<<endl;
    cout<<"clock.MS() = "<<clock.MS()<<endl;
    cout<<"      host.to_str() = "<<host.to_str()<<endl;
    cout<<"empty_host.to_str() = "<<empty_host.to_str()<<endl;
    cout<<"       win.to_str() = "<<win.to_str()<<endl;
    cout<<"host.pws.to_code() = "<<host.pws.to_code()<<endl;
    cout<<" win.pws.to_code() = "<<win.pws.to_code()<<endl;
    //cout<<msg<<endl;
    return win.pws;
  }
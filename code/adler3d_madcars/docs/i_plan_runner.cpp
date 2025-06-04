t_move
  int dir=MOVDIR_USE_SMART_ALGO;

struct i_plan_runner{
  int pId=-1;
  t_plan_runner PR;
  virtual void bef(t_plan&plan,t_mech&mech){
    PR.ptr=&plan;
    PR.restart();
    return;
  }
  virtual t_move get_direct(t_mech&mech){
    return PR.next();
  }
  virtual void aft(t_mech&mech){}
};

struct t_plan_runners{

  struct t_def:i_plan_runner{};

  struct t_smart:i_plan_runner{
    t_plan_runner PR;
    vector<t_plan> head;
    int tick_when_need_think=0;
    vector<t_plan> plans;
    void bef(t_plan&plan,t_mech&mech){
      PR.ptr=&head;
      PR.restart();
      return;
    }
    t_move get_direct(t_mech&mech){
      if(tick==tick_when_need_think){
        PR.ptr=&plans[mech2plan_id(mech)];
        PR.restart();
      }
      return PR.next();//get(plan,iter,mech);
    }
    void aft(t_mech&mech){}
    int mech2plan_id(t_mech&mech){
      return random_algo(mpos,mang,epos,eang)%plans.size();
    }
  }
  
  struct t_random_ga_nn_algo:i_plan_runner{
    void bef(t_plan&plan,t_mech&mech){}
    t_move get_direct(t_mech&mech){
      return random_algo(mpos,mang,epos,eang);
    }
    void aft(t_mech&mech){}
  }
  struct t_app_with_planer_with_hacks:i_plan_runner{... the same as blow but pass mech to on_tick as fast as possible ...}
  struct t_app_with_planer_without_hacks:i_plan_runner{
    t_app app;
    void bef(t_plan&plan,t_mech&mech){
      app.smart=true;
      std::thread...
        app.main...
          stream as t_wait_style_io
    }
    t_move get_direct(t_mech&mech){
      return random_algo(mpos,mang,epos,eang);
    }
    void aft(t_mech&mech){
      
    }
  }
}
  
struct t_player_memory{
  int pId=-1;
  unique_ptr<i_plan_runner> PR;
  void bef(t_plan&plan,t_mech&mech){
    QapAssert(pId>=0);
    PR=std::move(PR_load(plan));
    PR->pId=pId;
    PR->bef(plan,mech);
  }
  t_move get_direct(t_mech&mech){
    return PR->next(mech);//get(plan,iter,mech);
  }
  void aft(t_mech&mech){
    PR->aft(mech);
  }
};
  
struct t_plan_generator{
  void spawn_n_rnd_new(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000){...}
  void spawn_n_rnd_new_v80(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000){...}
  void smart_split(t_plan&out,int&t){auto&q=qap_add_back(out.arr);q.tick=-1;q.dir=MOVDIR_USE_SMART_ALGO;t=0;}
  void algo_smart_1337(t_plan&out,int&t){
    auto&b=qap_add_back(out.arr);
    b.tick=0;
    b.dir=MOVDIR_USE_SMART_ALGO_1337;
    smart_split(out,t);
    spawn_n_rnd_new_v80(out,t,9,400);
    smart_split(out,t);
    spawn_n_rnd_new_v80(out,t,9,400);
    smart_split(out,t);
    spawn_n_rnd_new_v80(out,t,9,400);
  }
  void algo_sn_rnd_9_400(t_plan&out,int&t){spawn_n_rnd_new(out,t,9,400);}
  vector<decltype(&t_plan_generator::algo_dt8)> get_algos(){
    vector<decltype(&t_plan_generator::algo_dt8)> alogs;
    #define F(FUNC)qap_add_back(alogs)=&t_plan_generator::FUNC;
    F(algo_sn_rnd_9_400);
    //F(algo_sn_rnd_768_99);
    #undef F
    return alogs;
  }
  t_plan rnd_plan(){
    static const auto algos=get_algos();
    t_plan out;
    int t=0;
    auto algo=rand()%algos.size();
    auto&func=algos[algo];
    (this->*func)(out,t);
    return out;
  }
};
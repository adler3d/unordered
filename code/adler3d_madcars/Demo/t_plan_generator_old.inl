struct t_plan_generator_old{
  /*old trash with bug          */std::random_device rd;
  /*old trash with bug          */std::mt19937 rand;
  /*old trash with bug          */string seed;
  /*old trash with bug          */t_plan_generator_old():rand(rd()){init_with();}
  /*old trash with bug          */void init_with(const string&new_seed="SEED 2018.10.06 20:46"){
  /*old trash with bug          */  seed=new_seed;call_id=-1;
  /*old trash with bug          */  std::seed_seq seq(seed.begin(),seed.end());rand.seed(seq);
  /*old trash with bug          */}
  /*old trash with bug          */void write_n_kink_at_every_dt(t_plan&out,int&t,int dt,int n){
  /*old trash with bug there -> */  for(int i=0;i<16/*yep, this is bug*/;i++){
  /*old trash with bug          */    out.add(t,t_move().set(rand()%3-1));t+=dt;
  /*old trash with bug          */  }
  /*old trash with bug          */}
  /*old trash with bug          */void algo0(t_plan&out,int&t)
  /*old trash with bug          */{
  /*old trash with bug          */  write_n_kink_at_every_dt(out,t,4,16);
  /*old trash with bug          */  write_n_kink_at_every_dt(out,t,8,16);
  /*old trash with bug          */  write_n_kink_at_every_dt(out,t,16,16);
  /*old trash with bug          */  write_n_kink_at_every_dt(out,t,32,16);
  /*old trash with bug          */  write_n_kink_at_every_dt(out,t,64,16);
  /*old trash with bug          */  write_n_kink_at_every_dt(out,t,128,16);
  /*old trash with bug          */}
  /*old trash with bug          */void algo1(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,21,2100/21);}
  /*old trash with bug          */void algo2(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,64,2100/64);}
  /*old trash with bug          */void algo3(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,16,2100/16);}
  /*old trash with bug          */void algo4(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,8,2100/8);}
  /*old trash with bug          */void algo5(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,32,2100/32);}
  /*old trash with bug          */vector<decltype(&t_plan_generator_old::algo0)> get_algos(){
  /*old trash with bug          */  vector<decltype(&t_plan_generator_old::algo0)> alogs;
  /*old trash with bug          */  #define F(FUNC)qap_add_back(alogs)=&t_plan_generator_old::FUNC;
  /*old trash with bug          */  F(algo0);
  /*old trash with bug          */  F(algo1);
  /*old trash with bug          */  F(algo2);
  /*old trash with bug          */  F(algo3);
  /*old trash with bug          */  F(algo4);
  /*old trash with bug          */  F(algo5);
  /*old trash with bug          */  #undef F
  /*old trash with bug          */  return alogs;
  /*old trash with bug          */}
  /*old trash with bug          */t_plan rnd_plan(){
  /*old trash with bug          */  static const auto algos=get_algos();
  /*old trash with bug          */  t_plan out;call_id++;
  /*old trash with bug          */  int t=0;
  /*old trash with bug          */  auto algo=rand()%algos.size();
  /*old trash with bug          */  auto&func=algos[algo];
  /*old trash with bug          */  (this->*func)(out,t);
  /*old trash with bug          */  return out;
  /*old trash with bug          */}
  static bool is_old_seed(const string&seed){
    if("SEED 2018.10.06 20:46"==seed)return true;
    if(split(seed,"SEED ML_v2 N=").size()==2)return true;
    return false;
  }
  size_t call_id=-1;
  void skip_plan(){rnd_plan();}
};

struct t_plan_generator_v3{
  typedef t_plan_generator_v3 SelfClass;
  std::random_device rd;
  std::mt19937 rand;
  string seed;
  //
  size_t call_id=-1;
  vector<size_t> used;
  vector<size_t> tick2id;
  vector<t_plan_rec> recs;
  //
  t_plan_generator_v3():rand(rd()){init_with();}
  void init_with(const string&new_seed="SEED 2018.10.12 22:05"){
    seed=new_seed;
    std::seed_seq seq(seed.begin(),seed.end());rand.seed(seq);
    used.clear();tick2id.clear();recs.clear();call_id=-1;
  }
  void write_n_kink_at_every_dt(t_plan&out,int&t,int dt,int n){
    for(int i=0;i<n;i++){
      out.add(t,t_move().set(rand()%3-1));t+=dt;
    }
  }
  void spawn_n_rnd_new(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000){
    static const int to_small_n=116;
    static const int to_xxxxx_n=6;
    static const int SIM_LIMIT=2200; //fast_rand(12,0xfff)%SIM_LIMIT
    QapAssert(out.arr.empty()&&ADD_RND_N);
    int n=BASE_N+rand()%ADD_RND_N;
    unsigned fast_buff=0;int fast_n=0;
    auto fast_rand=[&](int bits,unsigned bitmask){
      if(fast_n<bits){fast_n=32;fast_buff=rand();}
      fast_n-=bits;
      auto v=fast_buff&bitmask;
      fast_buff>>=bits;
      return v;
    };
    if(used.size()!=SIM_LIMIT){used.resize(SIM_LIMIT,call_id);tick2id.resize(SIM_LIMIT);}
    call_id++;
    bool to_small=n<to_small_n;
    bool use_update=to_small&&n>to_xxxxx_n;
    //auto&recs=to_small&&n>to_xxxxx_n?out.arr:this->recs;
    recs.clear();
    for(int i=0;i<n;i++){
      auto tick=t+fast_rand(12,0xfff)%SIM_LIMIT;
      if(used[tick]==call_id)continue;
      used[tick]=call_id;
      if(!use_update)tick2id[tick]=recs.size();
      auto&b=qap_add_back(recs);
      b.tick=tick;
      b.move=t_move().set(fast_rand(2,0x3)%3-1);
    }
    if(!use_update)
    {
      out.arr.reserve(recs.size());
      for(int i=0;i<used.size();i++){
        if(used[i]!=call_id)continue;
        auto&cur=recs[tick2id[i]];
        if(bool need_auto_pack=true&&out.arr.size()){
          if(out.arr.back().move==cur.move)continue;
        }
        qap_add_back(out.arr)=std::move(cur);
      }
    }else{
      out.arr.resize(recs.size());
      QAP_FOREACH(out.arr,ex=std::move(recs[i]));
      out.update();
    }
    t=out.arr.back().tick+1;
  }
  void spawn_n_rnd_old(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000,int SIM_LIMIT=2200){
    QapAssert(out.arr.empty()&&ADD_RND_N);
    int n=BASE_N+rand()%ADD_RND_N;
    for(int i=0;i<n;i++)out.tick2rec(t+rand()%SIM_LIMIT)->move=t_move().set(rand()%3-1);
    out.update();
    t=out.arr.back().tick+1;
  }
  void spawn_n_rnd_new_v80(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000){
    auto tmp=std::move(out.arr);int old_t=t;t=0;
    //
    QapAssert(out.arr.empty()&&ADD_RND_N);
    spawn_n_rnd_new(out,t,BASE_N,ADD_RND_N);
    //
    QAP_FOREACH(out.arr,ex.tick+=old_t);
    tmp+=out.arr;
    out.arr=std::move(tmp);
    t=out.arr.back().tick+1;
  }
  void algo_with_empty_at_start(t_plan&out,int&t){
    auto&b=qap_add_back(out.arr);
    b.tick=5+rand()%50;
    t=out.arr.back().tick+1;
    spawn_n_rnd_new_v80(out,t,9,400);
  }
  void algo_dt8(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,8,2200/8);}
  void algo_dt6(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,6,2200/6);}
  void algo_dt4(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,4,2200/4);}
  void algo_dt3(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,3,2200/3);}
  void algo_dt2(t_plan&out,int&t){write_n_kink_at_every_dt(out,t,2,2200/2);}
  void algo_sn_rnd_9_1000(t_plan&out,int&t){spawn_n_rnd_new(out,t,9,1000);}
  void algo_sn_rnd_256_16(t_plan&out,int&t){spawn_n_rnd_new(out,t,256,16);}
  void algo_sn_rnd_128_16(t_plan&out,int&t){spawn_n_rnd_new(out,t,128,16);}
  void algo_sn_rnd_128_99(t_plan&out,int&t){spawn_n_rnd_new(out,t,128,99);}
  void algo_sn_rnd_768_99(t_plan&out,int&t){spawn_n_rnd_new(out,t,768,99);}
  void algo_sn_rnd_16_8(t_plan&out,int&t){spawn_n_rnd_new(out,t,16,8);}
  void algo_sn_rnd_9_400(t_plan&out,int&t){spawn_n_rnd_new(out,t,9,400);}
  vector<decltype(&SelfClass::algo_dt8)> get_algos(){
    vector<decltype(&SelfClass::algo_dt8)> alogs;
    #define F(FUNC)qap_add_back(alogs)=&SelfClass::FUNC;
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
  void skip_plan(){
    static const auto algos=get_algos();
    auto algo=rand()%algos.size();
    int t=0;
    skip_spawn_n_rnd_new(t,9,400);
  }
  void skip_spawn_n_rnd_new(int&t,int BASE_N=4,int ADD_RND_N=1000){
    static const int SIM_LIMIT=2200; //fast_rand(12,0xfff)%SIM_LIMIT
    int n=BASE_N+rand()%ADD_RND_N;
    unsigned fast_buff=0;int fast_n=0;
    auto fast_rand=[&](int bits,unsigned bitmask){
      if(fast_n<bits){fast_n=32;fast_buff=rand();}
      fast_n-=bits;
      auto v=fast_buff&bitmask;
      fast_buff>>=bits;
      return v;
    };
    if(used.size()!=SIM_LIMIT){used.resize(SIM_LIMIT,call_id);tick2id.resize(SIM_LIMIT);}
    call_id++;
    for(int i=0;i<n;i++){
      auto tick=t+fast_rand(12,0xfff)%SIM_LIMIT;
      if(used[tick]==call_id)continue;
      used[tick]=call_id;
      fast_rand(2,0x3);
    }
  }
  static bool is_your_seed(const string&seed){
    if(split(seed,"SEED ML_v3 N=").size()==2)return true;
    return false;
  }
};
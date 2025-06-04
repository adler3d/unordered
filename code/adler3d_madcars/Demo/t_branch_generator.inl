



  struct t_branch_generator{
    void spawn_n_new_branches(t_node node,ARR movdirs){
      
    }
    void foo(t_node node){
      "запустить n ветки на столько то кадров"(node,movdirs);
    }
    t_world_input{t_moves m;t_moves e;};
    t_node_storage{
      t_node{
        t_score score;
        t_score get_avg_score(){
          score.
        }
      }
      // t_group = t_nodes_with_the_same_inpfrag_for_a_player
      t_group{
        t_node parent;
        vector<int> ids_of_nodes; //parent_node.subnodes[ids_of_nodes[i]]
        vector<t_node> nodes; //nodes=parent.get_subnodes(ids_of_nodes);
        t_score get_avg_score(){t_score out;QAP_FOREACH(nodes,out+=ex.get_avg());return out;}
      }
      t_node node;
      void promote(t_world_input inp){
        subnode=node.get_subnode_by_id(inp2id(inp));
        auto branch_generator=[](...){
          get_front_wave_nodes(node);
          get_inner_nodes(node); // inner = not_front_wave
          is_front_node=node_without_subnodes;
          auto f=[](t_node ex)->t_score{
            GA ga=env.ga;
            input:
              $("*+")<<ex.subnodes.size(); //mean env.rnd_koef_with_any_operator_from("*+");
              $("*+")<<int(ex.subnodes.empty()); // yes, almost the same, but like is_front_wave_node()
              $("*+")<<ex.total_score; // total_score = as_vec(score).reduce((accum,ex,i)=>$$$,0); // $$$ = any_of(exponenta,just_sum,just_mul,"accum<<=$;accum+=ex;")
              $("*+")<<ex.total_energy;
              $("*+")<<ex.total_btnH;
              $("*+")<<ex.total_penalty; // make_grid(proto_map).fill(point2penalty); // looklike not usefull for aicup3.
            output:
              t_score // or any obj with "operator <"
          }
          auto res=resources_per_step/arr.size();
          // impl_a
          auto arr=select_n_with_minval(node.get_all_subnodes(),n,f(ex));
          QAP_FOREACH(arr,ex.grow(res)); // grow = any(grow_in_the_same_dir_as_parent,grow_in_each_direction);
          // or impl_b
          for(int i=0;i<n;i++){
            auto id=select_1_with_minval(node.get_all_subnodes(),f(ex));
            node.get_all_subnodes()[id].grow(res);
          }
        };
        node=branch_generator(subnode,resources_per_step);
        if(bool need_slect_best=true){
          auto frag2group=node.subnodes.group_by_our_inpfrag();.
          auto frag2score=frag2nodes.map(group=>group.get_avg_score());
          auto id=QAP_MINVAL_ID_OF_VEC(frag2score,ex);
          auto win=frag2score[id];
        }
      }

    }
    t_nbf nbf;
    void someloop_iter(){
      
      nbf.build_some_numbers_of_nodes(foo);
      nbf.find_best_unsing_this_estimation_function(func);
      cout<<nbf.best_result;
    }
  };

  struct t_nbf{
    typedef size_t t_node_id;
    struct t_world_input{t_move m;t_move e;};
    struct t_node{
      t_node_id parent;
      vector<t_node_id> arr;
      t_inpid inpid;
      t_score score;
      t_growscore growscore;
      t_score get_avg_score(){}
      t_node get_subnode_by_id(int id){}
      void update_scores();
      t_world_input get_inpfrag(){return inpid2frag[inpid];}
      t_move get_move(){return get_inpfrag().get_me_move();};
    };
    //===
    vector<t_node> nodes;
    vector<t_node_id> unused_nodes;
    vector<t_node_id> cur;
    vector<t_node_id> next;
    t_node_id root_node;
    t_node_id best_node_id=-1;
    //===
    void grow(t_node&node){
      foreach_new_nodes(on_build(ex));
    }
    void on_node_build(t_node&node){node.update_scores();}
    void branch_generator()
    {
      
    }
    void promote(t_world_input inp){
      auto&root=get_node(root_node);
      auto&subnode=root.get_subnode_by_id(inp2id(inp));

      branch_generator(subnode,resources_per_step);
      if(bool need_slect_best=true){
        auto frag2group=node.subnodes.group_by_our_inpfrag();.
        auto frag2score=frag2nodes.map(group=>group.get_avg_score());
        auto id=QAP_MINVAL_ID_OF_VEC(frag2score,ex);
        auto win=frag2score[id];
      }
    }
    t_move get_best_result(){
      QapAssert(qap_check_id(nodes,best_node_id));
      return nodes[best_node_id].get_move();
    }
  };

  t_nbf nbf;

  void main(){
    for(;;){
      nbf_update();
      cout<<nbf.get_best_result();
    }
  }

  void nbf_update(){
    if(frame_id){
      inp=prev_our_move+FUEM();
      nbf.promote(inp);
    }
    nbf.branch_generator(resources_per_step);
    nbf.find_best_unsing_this_estimation_function(func);
  }



  struct t_nbf{
    vector<t_node> nodes;
    vector<int> unused_nodes;
    struct t_world_input{t_moves m;t_moves e;};
    struct t_node{
      vector<t_node> arr;
      t_score score;
      t_score get_avg_score(){
        //score.
      }
      t_node get_subnode_by_id(int id){}
      template<class FUNC>
      void foreach(FUNC&&func){
        func(*this);
        //if(!arr.size())func(*this);
        //func.bef(*this);
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          ex.foreach(func);
        }
        //func.aft(*this);
      }
      vector<t_node> get_all_subnodes(){
        vector<t_node> out;
        QAP_FOREACH(arr,out+=ex.get_all_subnodes());
        return out;
      }
      template<class NODE2VAL,class FUNC>
      void find_n_with_minval_and_do_func_foreach_of_it(size_t n,NODE2VAL&&node2val,FUNC&&func){
        struct t_rec{
          decltype(node2val()) score;
          t_node*pnode; // int node_id;
        };
        if(n==1&&buff.size()){auto id=QAP_MINVAL_ID_OF_VEC(buff,ex.score);func(*buff[id].node);return;}
        vector<t_rec> buff;
        foreach([&](t_node&ref){auto&b=qap_add_back(buff);b.pnode=&ex;b.score=node2val(ref);});
        QAP_SORT(buff,ex.score);
        for(int i=0;i<n;i++){func(*buff[i].pnode);}
        //QAP_FOREACH_N_MINVAL_ID_OF_VEC(buff,n,ex.score,func(*ex.node));
      }
      void grow(...){arr.resize(10500);} // grow = any(grow_in_the_same_dir_as_parent,grow_in_each_direction);
    };
    vector<int> select_n_with_minval();
    void branch_generator(...)
    {
      get_front_wave_nodes(node);
      get_inner_nodes(node); // inner = not_front_wave
      is_front_node=node_without_subnodes;
      auto node2growval=[](t_node ex)->t_score{...};
      auto res=resources_per_step/arr.size();
      // impl_a
      node.find_n_with_minval_and_do_func_foreach_of_it(n,node2growval(ex),[](t_node&ex){ex.grow(res);});// DON't work beacause grow call t_node::arr::resize and pointers inside buff will be point to invalid memory adress
      // impl_b
      for(int i=0;i<n;i++)
      node.find_n_with_minval_and_do_func_foreach_of_it(1,node2growval(ex),[](t_node&ex){ex.grow(res);});
      //
      /*
      
      */
    }
    void promote(t_world_input inp){
      subnode=node.get_subnode_by_id(inp2id(inp));
      node=branch_generator(subnode,resources_per_step);
      if(bool need_slect_best=true){
        auto frag2group=node.subnodes.group_by_our_inpfrag();.
        auto frag2score=frag2nodes.map(group=>group.get_avg_score());
        auto id=QAP_MINVAL_ID_OF_VEC(frag2score,ex);
        auto win=frag2score[id];
      }
    }
    void build_nodes(){
      foreach(cur_wave,ex.
    }
    t_move best_result;
  };

  t_nbf nbf;

  void main(){
    for(;;){
      nbf_update();
      cout<<nbf.best_result;
    }
  }



  void nbf_update(){
    nbf.build_some_numbers_of_nodes(foo);
    nbf.find_best_unsing_this_estimation_function(func);
  }



  //при симул€ции в точках траектории где линейный импульс или угловой импульс существенно мен€ютс€ - создавать ноды, и давать этим нодам дополнительные ресурсы дл€ делени€.
  //точнее сначала нужно провер€ть сильное изменение импульса, а уже потом провер€ть есть ли контакт между колесом и другой поверхностью.
  //всЄ что нужно просто найти ноды в дереве перебора в которых ¬”ѕ существенно мен€ет импульс.
  //нужно выдел€ть процессорные ресы пропроционально тому насколько сильно ‘¬”ѕ мен€ет состо€ние дочерних нодов.



  struct t_movdirs_con{
    //t_movdirs marr;
    //t_movdirs earr;
    int sim_limit=0;
    int gen_alog_id=0;
    int SHA=0;
    //int weakup_algo;
  };



  vector<t_movdirs_con> part1;
  void build_movdirscons(){
    LOOP_BY(sim_limit,18,1,256);
      LOOP_BY(gen_alog_id,t_gen_algos::beg,1,t_gen_algos::end);
        LOOP_BY(scorehack_alog_id,t_scorehack_algos::beg,1,t_scorehack_algos::end);
  }

  template<class T_PLAN,class SIM_AUTO,T_CONTEXT>
  auto find_best_curset(t_plan_with_dbg&out,vector<T_PLAN>&arr,SIM_AUTO&&sim_auto,T_CONTEXT&&context){
    auto&envs=out.envs;
    envs.resize(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&env=envs[i];
      env.set(i,arr[i],context);
      sim_auto(env);
    }
    auto id=QAP_MINVAL_ID_OF_VEC(envs,ex.score);
    if(id<0)
    {
      out.err("curset.empty();");
      return;
    }
    auto&win=envs[id];
    out.plan=win.plan;
    out.score=win.score;
    int gg=1;
  }

  struct t_sim_env{
    t_score score;
    t_plan plan;
  };

  struct t_plan_with_dbg{
    t_plan plan;
    string dbg;
    t_score score;
    vector<t_sim_env> envs;
    vector<t_zmech> log;
    t_plan_with_dbg&err(const string&msg){dbg+="err:"+msg;return *this;}
    t_plan_with_dbg&set(const t_plan&ref){plan=ref;return *this;}
  };

  struct t_movdirs_with_dbg{
    t_score score;
    t_movdirs plan;
    vector<t_sim_env> envs;
    string dbg;
    vector<t_zmech> log;
    t_plan_with_dbg&err(const string&msg){dbg+="err:"+msg;return *this;}
    t_plan_with_dbg&set(const t_plan&ref){plan=ref;return *this;}
  };

  void on_tick_v2(t_plan_with_dbg&out)
  {

    find_best_curset(out,curset,[this](t_env&env){sim_auto_for_movdirs(env);},con);
    auto con=t_env::t_con(our_id,sim_limit);
    find_best_curset(out,curset,[this](t_env&env){sim_auto(env);},con);
  }

  void on_tick(t_plan_with_dbg&out)
  {
    curset=find_best_curset();
    auto&envs=out.envs;
    envs.resize(curset.size());
    for(int i=0;i<curset.size();i++)
    {
      auto&env=envs[i];
      env.score.id=i;
      env.plan=curset[i];
      env.pId=our_id;
      env.sim_limit=sim_limit;

      sim_auto(emovdirs,env,plogger);

      env.score.id=i;
      QapAssert(env.score.id==i);
    }
    auto id=QAP_MINVAL_ID_OF_VEC(envs,ex.score);
    if(id<0)
    {
      out.err("curset.empty();");
      return;
    }
    auto&win=envs[id];
    out.plan=win.plan;
    out.score=win.score;
    int gg=1;
  }
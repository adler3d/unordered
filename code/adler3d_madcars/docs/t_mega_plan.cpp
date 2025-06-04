t_plan

t_rec
  
  time,
  epos,mpos,dist,eang,mang,
  
  
  t_move::get(t_mech mech)
    if(use_dyn_anlog)
      return exec(algo_id,payload,mech);
    
    
  
  t_mega_plan
    vector<t_main_rec> main_plan;
    vector<vector<t_move>> buff;
    //t_plan cur_plan; //in runner
    vector<t_plan> mdirs; // or mdirs_gen_algo_id
    vector<t_plan> edirs; // or edirs_gen_algo_id
    t_rec
      int t;
      int algo;
      string payload;
      string message;
      string command;
      string cmd;
      string code;
      string data;
      string userdata;
      string algodata;
      unique_ptr<i_algo_userdata*> userdata;
      vector<int> int_params;
      vector<real> real_params;
      string some_data;
    
    t_user_data_for{
      t_trajectory_planer{
        int simlimit;
        vector<t_plan> mdirs,edirs;
        t_score_function_settings sfs;
        i_score_function*pscore_func;
      }
      t_trajectory_planer_with_cheap_triger{
        t_cheap_triger_settings cts;
        t_user_data_for_trajectory_planer tp;
      }
      t_neuronetwork_algo{
        int neuronetwork_id;
      }
      t_neuronetwork_algo_v2{
        vector<t_plan> arr;
        int neuronetwork_id;
      }
      t_nbf_algo{
        ...
      }
      t_constant_dir{
        int dir;
      }
      t_constant_plan{
        t_plan plan;
      }
      t_constant_plan_v2{
        if f(epos,mpos) then exec(plan_a); else exec(plan_b); // look like a simple future prediction, but without simulation, so this can react at predicted event that happen after 900 frames.
      }
      t_keep_ang{
        real ang;
      }
      t_keep_pos{
        real x;
        int do_it_every_n_frame=2;
      }
    }
    

    t_algo_rec
      int dir;
      bool ret;

(dir+new_context) = t_context(t_plan).use(iter,t_mech);

t_plan_runner{
  const t_plan*ptr;
  int buff_id;
  int iter;
  t_move get(t_zmech){
    mech
  }
}
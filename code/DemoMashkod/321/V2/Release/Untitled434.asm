{
  int L0_x=10;
  int L0_z=20;
  int L1_top_x=L0_x;
  int L1_$;
  int L2_sub_x=L1_top_x;
  L1_$=L2_sub_x+50;
  L0_z=L1_$;
  return L0_z;
}

class t_stat_visitor:public t_smart_asm::i_stat_visitor{
public:
  class t_dev{
  public:
  };
  t_dev&dev;
  t_visitor(t_dev&dev):dev(dev){}
public:
  #define no_impl()QapDebugMsg("no impl");
public:
  void Do(t_nop_stat*p){}
  void Do(t_ret_stat*p){
  }
  void Do(t_call_stat*p){
  }
  void Do(t_block_stat*p){no_impl();}
  void Do(t_auto_stat*p){no_impl();}
  void Do(t_var_stat*p){
    }
  void Do(t_if_stat*p){no_impl();}
  void Do(t_loop_stat*p){no_impl();}
  void Do(t_for_stat*p){no_impl();}
  void Do(t_break_stat*p){no_impl();}
  void Do(t_continue_stat*p){no_impl();}
  void Do(t_sep_stat*p){}
public:
  #undef no_impl
};


























































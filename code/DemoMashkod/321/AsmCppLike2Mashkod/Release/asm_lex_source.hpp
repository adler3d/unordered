t_asm_machine{
  t_int{string value;{go_const(" ");go_any(value,gen_dips("09"));}}
  t_label{string id;{go_const(" ");go_str<t_name>(id);}}
  t_reg{char id;{go_const(" ");go_any_char(id,gen_dips("azAZ"));}}
  t_nop=>i_cmd{{go_const("  nop");}}
  t_inp_const{string offset;{go_const(" inp[");go_any(offset,gen_dips("09"));go_const("]");}}
  t_out_const{string offset;{go_const(" out[");go_any(offset,gen_dips("09"));go_const("]");}}
  t_inp_reg{char id;{go_const(" inp[");go_any_char(id,gen_dips("azAZ"));go_const("]");}}
  t_out_reg{char id;{go_const(" out[");go_any_char(id,gen_dips("azAZ"));go_const("]");}}
  t_mrk=>i_cmd{string name;{go_str<t_name>(name);go_const(":");}}
  t_ret=>i_cmd{{go_const("  ret");}}
  t_call=>i_cmd{t_out_reg out;t_label to;{go_const("  call");go_auto(to);}}
  t_jmp=>i_cmd{t_label to;{go_const("  jmp");go_auto(to);}}
  t_jnz=>i_cmd{t_reg cond;t_label to;{go_const("  jnz");go_auto(cond);go_auto(to);}}
  t_jz=>i_cmd{t_reg cond;t_label to;{go_const("  jz");go_auto(cond);go_auto(to);}}
  t_inc=>i_cmd{t_reg reg;{go_const("  inc");go_auto(reg);}}
  t_add=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  add");go_auto(out);go_auto(a);go_auto(b);}}
  t_sub=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  sub");go_auto(out);go_auto(a);go_auto(b);}}
  t_mul=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  mul");go_auto(out);go_auto(a);go_auto(b);}}
  t_div=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  div");go_auto(out);go_auto(a);go_auto(b);}}
  t_mod=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  mod");go_auto(out);go_auto(a);go_auto(b);}}
  t_more=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  more");go_auto(out);go_auto(a);go_auto(b);}}
  t_less=>i_cmd{t_reg out;t_reg a;t_reg b;{go_const("  less");go_auto(out);go_auto(a);go_auto(b);}}
  t_mov_reg_reg=>i_cmd{t_reg out;t_reg inp;{go_const("  mov");go_auto(out);go_auto(inp);}}
  t_mov_const=>i_cmd{t_reg out;t_int value;{go_const("  mov");go_auto(out);go_auto(value);}}
  t_mov_inp_const=>i_cmd{t_reg       out;t_inp_const inp;{go_const("  mov");go_auto(out);go_auto(inp);}}
  t_mov_out_const=>i_cmd{t_out_const out;t_reg       inp;{go_const("  mov");go_auto(out);go_auto(inp);}}
  t_mov_inp_reg=>i_cmd{t_reg     out;t_inp_reg inp;{go_const("  mov");go_auto(out);go_auto(inp);}}
  t_mov_out_reg=>i_cmd{t_out_reg out;t_reg     inp;{go_const("  mov");go_auto(out);go_auto(inp);}}
  t_movc_reg_reg=>i_cmd{
    t_reg out;t_reg out_id;
    t_reg inp;t_reg inp_id;
    {
      go_const("  movc");
      go_auto(out);go_auto(out_id);
      go_auto(inp);go_auto(inp_id);
    }
  }
  t_movc_const_const=>i_cmd{
    t_reg out;t_int out_id;
    t_reg inp;t_int inp_id;
    {
      go_const("  movc");
      go_auto(out);go_auto(out_id);
      go_auto(inp);go_auto(inp_id);
    }
  }
  t_movc_reg_const=>i_cmd{
    t_reg out;t_reg out_id;
    t_reg inp;t_int inp_id;
    {
      go_const("  movc");
      go_auto(out);go_auto(out_id);
      go_auto(inp);go_auto(inp_id);
    }
  }
  t_movc_const_reg=>i_cmd{
    t_reg out;t_int out_id;
    t_reg inp;t_reg inp_id;
    {
      go_const("  movc");
      go_auto(out);go_auto(out_id);
      go_auto(inp);go_auto(inp_id);
    }
  }
  vector<TAutoPtr<i_cmd>> arr;
  {
    go_vec(arr,"\n");
  }
}
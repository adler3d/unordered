надо сделать генератор вот таких вот вещей.

t_type{
  string value;
  {
    go_any_str_from_vec(value,split("int,bool,char,string,real",","));
  }
}

t_cmd{
  string value;
  {
    go_const("_");
    go_any_str_from_vec(value,split("set,add,sub,mul,div,mod,and,or,not,inv,xor",","));
  }
}

t_lex{
  {
    go_const("t");
    
    go_const("_set");
  }
}

t_bool_set_int_less_int
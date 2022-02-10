t_alias_func_call{
  string alias;
  string func;
  string str_param;
  {
    go_const("auto ");
    go_str<t_name>(alias);
    go_const("=");
    go_str<t_name>(func);
    go_const("(");
    go_str<t_str_item::t_impl>(str_param);
    go_const(")");
  }
}
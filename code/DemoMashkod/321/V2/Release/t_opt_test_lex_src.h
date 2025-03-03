t_opt_test_lex_scope{
t_mov{
  string bef;
  vector<t_name> arr;
  {
    go_str<t_name>(bef);
    go_const("=");
    go_vec(arr," ");
    go_const("\n");
  }
}

t_ret{
  string var;
  {
    go_const("ret ");
    go_str<t_name>(var);
  }
}

t_program{
  vector<t_mov> arr;
  t_ret ret;
  {
    go_auto(arr);
    go_auto(ret);
  }
}
}
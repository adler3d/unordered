t_int{
  string value;
  {
    go_str<TAutoPtr<t_simple_stat_lex::t_int_expr::i_val>>(value);
  }
}
t_vec2i{
  t_int x;
  t_int y;
  {
    go_auto(x);
    go_const(" ")
    go_auto(y);
  }
}
t_circle=>i_object{
  t_vec2i pos;
  t_int r;
  {
    go_const("C ")
    go_auto(pos);
    go_const(" ")
    go_auto(r);
    go_const(";")
  }
}
t_line=>i_object{
  t_vec2i a;
  t_vec2i b;
  {
    go_const("L ")
    go_auto(a);
    go_const(" ")
    go_auto(b);
    go_const(";")
  }
}
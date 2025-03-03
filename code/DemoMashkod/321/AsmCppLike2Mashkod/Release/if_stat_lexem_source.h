
t_struct_field{
  string type;
  t_name name;
  string value;
  {
    M+=go_const("  ");
    M+=go_end(type," ");
    M+=go_auto(name);
    O+=go_const("=");
    M+=go_end(value,";\n");
  }
}

t_struct_cmd_mode{
  char body='M';
  {
    M+=go_any_char(body,"MO");
    M+=go_const("+=");
  }
}

t_struct_cmd{
  TAutoPtr<t_struct_cmd_mode> mode;
  string code;
  {
    M+=go_const("    ");
    O+=go_auto(mode);
    M+=go_end(code,";\n");
  }
}

t_struct_body{
  vector<t_struct_field> arr;
  vector<t_struct_cmd> cmds;
  {
    M+=go_const("{\n");
    O+=go_auto(arr);
    M+=go_const("  {\n");
    M+=go_auto(cmds);
    M+=go_const("  }\n}");
  }
}

t_class_def=>i_def{
  t_name name;
  t_name parent;
  {
    M+=go_auto(name);
    M+=go_const("=>");
    M+=go_auto(parent);
  }
}

t_struct_def=>i_def{
  t_name name;
  {
    M+=go_auto(name);
  }
}

t_target_item{
  string sep;
  TAutoPtr<i_def> def;
  t_struct_body body;
  {
    O+=go_any(sep," \n");
    M+=go_auto(def);
    M+=go_auto(body);
  }
}

t_target{
  vector<t_target_item> arr;
  {
    M+=go_auto(arr);
  }
}

-----------------------------

t_expr_stat=>i_stat{
  TAutoPtr<i_expr> expr;
  {
    M+=go_auto(expr);
    M+=go_const(";");
  }
}

t_null_stat=>i_stat{
  {
    M+=go_const(";");
  }
}

t_if_body_one=>i_if_body{
  TAutoPtr<i_stat> stat;
  {
    M+=go_auto(stat);
  }
}

t_if_body_two=>i_if_body{
  t_block_stat bef;
  TAutoPtr<i_stat> aft;
  {
    M+=go_auto(bef);
    M+=go_const("else");
    M+=go_auto(aft);
  }
}

t_if_stat=>i_stat{
  TAutoPtr<i_expr> cond;
  TAutoPtr<i_if_body> body;
  {
    M+=go_const("if");
    M+=go_const("(");
    M+=go_auto(cond);
    M+=go_const(")");
    M+=go_auto(body);
  }
}

t_for_stat=>i_stat{
  t_var_stat init;
  TAutoPtr<i_expr> cond;
  TAutoPtr<i_expr> loop;
  TAutoPtr<i_stat> body;
  {
    go_const("for(");
    go_auto(init);
    go_auto(cond);
    go_const(";");
    go_auto(loop);
    go_const(")");
    go_auto(body);
  }
}

t_do_stat=>i_stat{
  TAutoPtr<i_expr> cond;
  TAutoPtr<i_stat> body;
  {
    go_const("do(");
    go_auto(cond);
    go_const(")");
    go_auto(body);
  }
}





























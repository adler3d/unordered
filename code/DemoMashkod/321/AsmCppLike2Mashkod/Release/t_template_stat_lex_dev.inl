t_simple_stat_lex{
  t_template_stat=>i_stat{
    t_param{
      t_type{{go_const("class");}}
      t_sep sep0;
      t_type type;
      t_sep sep1;
      t_name name;
      t_sep sep2;
      {
        O+=go_auto(sep0);
        M+=go_auto(type);
        O+=go_auto(sep1);
        M+=go_auto(name);
        O+=go_auto(sep2);
      }
    }
    t_params{
      vector<t_param> arr;
      {
        go_const("{");
        go_vec(arr,",");
        go_const("}");
      }
    }
    t_func_body=>i_body{t_func_stat::t_impl body;{go_auto(body);}}
    t_oper_body=>i_body{t_oper_stat body;{go_auto(body);}}
    t_struct_body=>i_body{t_struct body;{go_auto(body);}}
    t_sep sep0;
    t_params params;
    t_sep sep1;
    TAutoPtr<i_body> body;
    {
      M+=go_const("template");
      O+=go_auto(sep0);
      M+=go_auto(params);
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
}
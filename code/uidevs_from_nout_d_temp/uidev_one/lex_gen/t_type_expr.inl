t_type_expr{
  t_first_scope{
    string body;
    t_sep sep;
    {
      M+=go_const("::");
      O+=go_auto(sep);
    }
  }
  t_const_with_sep{t_sep sep;{O+=go_auto(sep);M+=go_const("const");}}
  t_type_with_sep{
    t_type_param=>i_param{
      TAutoPtr<t_const_with_sep> cv;
      TAutoPtr<t_type_expr> body;
      {
        O+=go_auto(cv);
        M+=go_auto(body);
      }
    }
    t_num_param=>i_param{string body;{go_any(body,gen_dips("09"));}}
    t_params{
      t_type_expr_with_sep{t_sep sep_bef;TAutoPtr<i_param> param;t_sep sep_aft;{O+=go_auto(sep_bef);M+=go_auto(param);O+=go_auto(sep_aft);}}
      t_sep sep;
      vector<t_type_expr_with_sep> arr;
      {
        O+=go_auto(sep);
        M+=go_const("<");
        O+=go_vec(arr,",");
        M+=go_const(">");
      }
    }
    t_sep sep;
    string name;
    TAutoPtr<t_params> params;
    {
      O+=go_auto(sep);
      M+=go_str<t_name>(name);
      O+=go_auto(params);
    }
  }
  t_scope_with_sep{t_sep sep;{O+=go_auto(sep);M+=go_const("::");}}
  t_scope{{go_const("::");}}
  t_ptr{
    TAutoPtr<t_const_with_sep> cv;
    t_sep sep;
    {
      O+=go_auto(cv);
      O+=go_auto(sep);
      M+=go_const("*");
    }
  }
  t_ref{
    TAutoPtr<t_const_with_sep> cv;
    t_sep sep;
    string ref;
    {
      O+=go_auto(cv);
      O+=go_auto(sep);
      M+=go_any_str_from_vec(ref,split("&&,&",","));
    }
  }
  t_scopes{
    t_item{t_scope_with_sep sws;t_type_with_sep body;{go_auto(sws);go_auto(body);}}
    t_type_with_sep first;
    vector<t_item> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }
  t_main_test{
    t_keyword{
      string keyword;
      t_sep sep;
      {
        M+=go_any_str_from_vec(keyword,split("explicit,constexpr,virtual,const,static",","));
        O+=go_auto(sep);
      }
    }
    t_func_stat{
      vector<t_keyword> keywords;
      t_sep sep0;
      TAutoPtr<t_type_expr> type;
      t_sep sep1;
      TAutoPtr<t_const_with_sep> cv;
      string func_name;
      t_sep sep2;
      {
        O+=go_auto(keywords);
        M+=go_auto(type);
        O+=go_auto(cv);
        O+=go_auto(sep1);
        M+=go_str<t_name>(func_name);
        O+=go_auto(sep2);
        M+=go_const("();");
      }
    }
    t_line{
      t_sep sep;
      t_func_stat func_stat;
      {
        O+=go_auto(sep);
        M+=go_auto(func_stat);
      }
    }
    vector<t_line> lines;
    {go_auto(lines);}
  }
  TAutoPtr<t_first_scope> first;
  t_scopes scopes;
  vector<t_ptr> ptrs;
  t_ref ref;
  {
    O+=go_auto(first);
    M+=go_auto(scopes);
    O+=go_auto(ptrs);
    O+=go_auto(ref);
  }
}
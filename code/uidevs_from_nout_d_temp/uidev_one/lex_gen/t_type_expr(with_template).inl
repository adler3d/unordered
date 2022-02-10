t_type_expr{
  t_const_first=>i_first{
    string body;
    {
      M+=go_const("const");
      M+=sep;
    }
  }
  t_scope_first=>i_first{
    t_const{{go_const("const");}};
    string body;
    {
      O+=go_str<t_const>(body);
      O+=sep;
      M+=go_const("::");
      O+=sep;
    }
  }
  t_first{TAutoPtr<i_first> body;{go_auto(body);}}
  t_type_with_sep{
    t_params{
      t_type_expr_with_sep{t_type_expr body;{O+=sep;M+=go_auto(body);O+=sep;}}
      vector<t_type_expr> arr;
      t_impl impl;
      {
        O+=sep;
        M+=go_const("<");
        O+=go_vec(arr,",");
        M+=go_const(">");
      }
    }
    TAutoPtr<t_params> params;
    string name;
    {
      O+=sep;
      M+=go_str<t_name>(body);
      O+=go_auto(params);
    }
  }
  t_scope_with_sep{{O+=sep;M+=go_const("::");}}
  t_scope{{go_const("::");}}
  t_ptr{{O+=sep;M+=go_const("*");}};
  t_ref{string body;{O+=sep;M+=go_any_str_from_vec(body,split("&&,&",","));}}
  typedef t_vec_with_sep{t_type_with_sep,t_scope_with_sep} t_scopes;
  t_first first;
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
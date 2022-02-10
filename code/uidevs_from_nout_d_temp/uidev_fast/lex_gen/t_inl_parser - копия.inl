t_inl_file{
  t_access_mod{string keyword;{go_any_str_from_vec(keyword,split("public,protected,private",","));}}
  t_access_mod_class_stat=>i_class_stat{
    t_access_mod mod;
    t_sep sep;
    {
      M+=go_auto(mod);
      O+=go_auto(sep);
      M+=go_const(":");
    }
  }
  t_raw_func_body{
    t_sep_item=>i_item{t_sep sep;{go_auto(sep);}}
    t_s_item=>i_item{string value;{go_str<t_str_item::t_impl>(value);}}
    t_c_item=>i_item{string value;{go_str<t_char_item::t_impl>(value);}}
    t_code_item=>i_item{string code;{go_any(code,gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");}}
    t_div_item=>i_item{{go_const("/");}}
    t_block_item=>i_item{TAutoPtr<t_raw_func_body> body;{go_auto(body);}}
    t_sep sep;
    vector<TAutoPtr<i_item>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }
  t_fv_class_stat=>i_class_stat{
    t_type_expr{
      t_first_scope{
        string body;
        t_sep sep;
        {
          M+=go_const("::");
          O+=go_auto(sep);
        }
      }
      t_const_with_sep{t_sep sep;string keyword;{O+=go_auto(sep);M+=go_any_str_from_vec(keyword,split("typename,const,unsigned",","));}}
      t_type_with_sep{
        t_type_param=>i_param{
          vector<t_const_with_sep> cvs;
          TAutoPtr<t_type_expr> body;
          {
            O+=go_auto(cvs);
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
      t_keyword{
        string keyword;
        t_sep sep;
        {
          M+=go_any_str_from_vec(keyword,split("extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
          O+=go_auto(sep);
        }
      }
      t_type_expr_with_sep_and_cv{
        vector<t_const_with_sep> cvs;
        TAutoPtr<t_type_expr> body;
        {
          O+=go_auto(cvs);
          M+=go_auto(body);
        }
      }
      t_pfunc_func_param=>i_func_param{
        t_addr{
          t_type_expr_with_sep_and_cv type;
          {
            M+=go_auto(type);
            M+=go_const("::");
          }
        }
        t_type_expr_with_sep_and_cv type;
        t_addr addr;
        string name;
        {
          M+=go_auto(type);
          M+=go_const("(");
          O+=go_auto(addr);
          M+=go_const("*");
          M+=go_str<t_name>(name);
          M+=go_const(")");
          M+=go_const("()");
        }
      }
      t_var_args_func_param=>i_func_param{{go_const("...");}}
      t_type_func_param=>i_func_param{
        t_name_part{TAutoPtr<i_name_part> body;{go_auto(body);}}
        t_brackets_name_part=>i_name_part{
          string stars;
          t_sep sep;
          TAutoPtr<t_name_part> namepart;
          {
            M+=go_const("(");
            M+=go_any(stars,"*");
            O+=go_auto(sep);
            O+=go_auto(namepart);
            M+=go_const(")");
          }
        }
        t_raw_name_part=>i_name_part{string name;{go_str<t_name>(name);}}
        t_type_expr_with_sep_and_cv type;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
        {
          M+=go_auto(type);
          O+=go_auto(sep);
          O+=go_auto(namepart);
        }
      }
      t_expr_ext=>i_func_param_ext{TAutoPtr<i_expr> body;{go_auto(body);}}
      t_func_ref_ext=>i_func_param_ext{
        t_sep sep;
        t_type_expr_with_sep_and_cv type;
        {
          M+=go_const("&");
          O+=go_auto(sep);
          M+=go_auto(type);
        }
      }
      t_func_param_ext{
        t_sep sep;
        TAutoPtr<i_func_param_ext> body;
        {
          M+=go_const("=");
          O+=go_auto(sep);
          M+=go_auto(body);
        }
      }
      t_func_param{
        t_sep sep0;
        TAutoPtr<i_func_param> body;
        t_sep sep1;
        TAutoPtr<t_func_param_ext> ext;
        t_sep sep2;
        {
          O+=go_auto(sep0);
          M+=go_auto(body);
          O+=go_auto(sep1);
          O+=go_auto(ext);
          O+=go_auto(sep2);
        }
      }
      t_func_params{
        t_sep sep;
        vector<t_func_param> arr;
        {
          O+=go_auto(sep);
          M+=go_const("(");
          O+=go_vec(arr,",");
          M+=go_const(")");
        }
      }
      t_fv_stat{
        t_impl_func_body=>i_fv_body{t_sep sep;t_raw_func_body body;{O+=go_auto(sep);M+=go_auto(body);}}
        t_zero_func_body=>i_fv_body{{go_const("=0;");}}
        t_delete_func_body=>i_fv_body{{go_const("=delete;");}}
        t_empty_func_body=>i_fv_body{{go_const(";");}}
        t_func_fv_part=>i_fv_part{
          TAutoPtr<t_func_params> params;
          TAutoPtr<t_const_with_sep> cv1;
          t_sep sep1;
          TAutoPtr<i_fv_body> body;
          {
            M+=go_auto(params);
            O+=go_auto(cv1);
            O+=go_auto(sep1);
            M+=go_auto(body);
          }
        }
        t_var_fv_part=>i_fv_part{
          t_body{
            string body;
            t_sep sep;
            {
              M+=go_const("[");
              M+=go_any(body,gen_dips("09"));
              M+=go_const("]");
              O+=go_auto(sep);
            }
          }
          t_sep sep0;
          TAutoPtr<t_body> body;
          TAutoPtr<t_func_param_ext> ext;
          t_sep sep1;
          {
            O+=go_auto(sep0);
            O+=go_auto(body);
            O+=go_auto(ext);
            O+=go_auto(sep1);
            M+=go_const(";");
          }
        }
        vector<t_keyword> keywords;
        TAutoPtr<t_type_expr> type;
        t_sep sep;
        TAutoPtr<t_const_with_sep> cv0;
        string func_name;
        TAutoPtr<i_fv_part> part;
        {
          O+=go_auto(keywords);
          M+=go_auto(type);
          O+=go_auto(cv0);
          O+=go_auto(sep);
          M+=go_str<t_name>(func_name);
          M+=go_auto(part);
        }
      }
      t_main_test{
        t_line{
          t_sep sep;
          t_fv_stat fv_stat;
          {
            O+=go_auto(sep);
            M+=go_auto(fv_stat);
          }
        }
        vector<t_line> lines;
        {go_auto(lines);}
      }
      TAutoPtr<t_first_scope> first;
      t_scopes scopes;
      vector<t_ptr> ptrs;
      TAutoPtr<t_ref> ref;
      {
        O+=go_auto(first);
        M+=go_auto(scopes);
        O+=go_auto(ptrs);
        O+=go_auto(ref);
      }
    }
    t_type_expr::t_fv_stat body;
    {go_auto(body);}
  }
  t_typedef_class_stat=>i_class_stat{
    t_sep sep0;
    t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv type;
    t_sep sep1;
    string name;
    {
      M+=go_const("typedef");
      O+=go_auto(sep0);
      M+=go_auto(type);
      O+=go_auto(sep1);
      M+=go_str<t_name>(name);
    }
  }
  t_bool_expr=>i_expr{string value;{go_any_str_from_vec(value,split("false,true",","));}}
  t_string_expr=>i_expr{string value;{go_str<t_str_item::t_impl>(value);}}
  t_char_expr=>i_expr{string value;{go_str<t_char_item::t_impl>(value);}}
  t_num_expr=>i_expr{string value;{go_any(value,gen_dips("09"));}}
  t_nullptr_expr=>i_expr{{go_const("nullptr");}}
  t_var_expr=>i_expr{
    t_item{
      t_fv_class_stat::t_type_expr::t_type_with_sep body;
      t_sep sep;
      {
        M+=go_auto(body);
        O+=go_auto(sep);
        M+=go_const("::");
      }
    }
    t_field{t_sep bef;string name;t_sep aft;{O+=go_auto(bef);M+=go_str<t_name>(name);O+=go_auto(aft);}}
    t_impl{
      vector<t_item> items;
      t_sep sep;
      vector<t_field> arr;
      {
        O+=go_auto(items);
        O+=go_auto(sep);
        M+=go_vec(arr,".");
      }
    }
    string name;{go_str<t_impl>(name);}
  }
  t_expr{TAutoPtr<i_expr> body;{go_auto(body);}}
  t_ctor_init_list{
    t_init_param{
      string name;
      TAutoPtr<t_expr> expr;
      {
        M+=go_str<t_name>(name);
        M+=go_const("(");
        O+=go_auto(expr);
        M+=go_const(")");
      }
    }
    vector<t_init_param> params;
    t_sep sep;
    {
      M+=go_const(":");
      M+=go_vec(params,",");
      O+=go_auto(sep);
    }
  }
  t_null_func_body=>i_func_body{{go_const(";");}}
  t_impl_func_body=>i_func_body{t_sep sep;t_raw_func_body body;{O+=go_auto(sep);M+=go_auto(body);}}
  t_zero_func_body=>i_func_body{{go_const("=0;");}}
  t_delete_func_body=>i_func_body{{go_const("=delete;");}}
  t_delete_ctor_body=>i_ctor_body{{go_const("=delete;");}}
  t_impl_ctor_body=>i_ctor_body{
    t_sep sep;
    TAutoPtr<t_ctor_init_list> init_list;
    t_raw_func_body body;
    {
      O+=go_auto(sep);
      O+=go_auto(init_list);
      M+=go_auto(body);
    }
  }
  t_null_ctor_body{t_sep sep;{O+=go_auto(sep);M+=go_const(";");}}
  t_ctor_body{TAutoPtr<i_ctor_body> body;{go_auto(body);}}
  t_dtor_class_stat=>i_class_stat{
    t_sep sep;
    string name;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<t_ctor_body> body;
    {
      M+=go_const("~");
      O+=go_auto(sep);
      M+=go_str<t_name>(name);
      M+=go_const("()");
      O+=go_auto(body);
    }
  }
  t_ctor_class_stat=>i_class_stat{
    t_impl{
      t_explicit{t_sep sep;{M+=go_const("explicit");M+=go_auto(sep);}}
      TAutoPtr<t_explicit> prefix;
      string name;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<t_ctor_body> body;
      {
        O+=go_auto(prefix);
        M+=go_str<t_name>(name);
        M+=go_auto(params);
        O+=go_auto(body);
      }
    }
    t_impl body;{go_auto(body);}
  }
  t_oper_cast_class_stat=>i_class_stat{
    t_sep sep0;
    t_fv_class_stat::t_type_expr type;
    t_sep sep1;
    t_sep sep2;
    TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv;
    TAutoPtr<i_func_body> body;
    {
      M+=go_const("operator");
      O+=go_auto(sep0);
      M+=go_auto(type);
      O+=go_auto(sep1);
      M+=go_const("(");
      O+=go_auto(sep2);
      M+=go_const(")");
      O+=go_auto(cv);
      M+=go_auto(body);
    }
  }
  t_common_oper_class_stat=>i_class_stat{
    t_impl{
      vector<t_fv_class_stat::t_type_expr::t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv0;
      t_sep sep0;
      t_sep sep1;
      string oper;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
      {
        O+=go_auto(keywords);
        M+=go_auto(type);
        O+=go_auto(cv0);
        O+=go_auto(sep0);
        M+=go_const("operator");
        O+=go_auto(sep1);
        M+=go_any_str_from_vec(oper,split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[]",","));
        M+=go_auto(params);
        O+=go_auto(cv1);
        M+=go_auto(body);
      }
    }
    t_impl body;{go_auto(body);}
  }
  t_parents{
    t_item{
      t_pub{t_access_mod mod;t_sep sep;{M+=go_auto(mod);O+=go_auto(sep);}}
      t_sep sep;
      TAutoPtr<t_pub> pub;
      string name;
      {
        O+=go_auto(sep);
        O+=go_auto(pub);
        M+=go_str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>(name);
      }
    }
    t_sep sep;
    vector<t_item> arr;
    {
      M+=go_const(":");
      O+=go_auto(sep);
      M+=go_vec(arr,",");
    }
  }
  t_class_body{
    vector<TAutoPtr<i_class_stat>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }
  t_class{
    string keyword;
    t_sep sep0;
    string name;
    t_sep sep1;
    TAutoPtr<t_parents> parents;
    t_sep sep2;
    TAutoPtr<t_class_body> body;
    t_sep sep3;
    {
      M+=go_any_str_from_vec(keyword,split("struct,class",","));
      O+=go_auto(sep0);
      O+=go_str<t_name>(name);
      O+=go_auto(sep1);
      O+=go_auto(parents);
      O+=go_auto(sep2);
      O+=go_auto(body);
      O+=go_auto(sep3);
      M+=go_const(";");
    }
  }
  t_namespace_class_stat=>i_class_stat{
    t_sep sep0;
    string name;
    t_sep sep1;
    t_class_body body;
    {
      M+=go_const("namespace");
      O+=go_auto(sep0);
      O+=go_str<t_name>(name);
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
  t_template_class_stat=>i_class_stat{
    t_template_param{
      t_sep bef;
      TAutoPtr<i_template_param> body;
      t_sep aft;
      {
        O+=go_auto(bef);
        M+=go_auto(body);
        O+=go_auto(aft);
      }
    }
    t_concrete_param{
      t_raw_expr=>i_body{TAutoPtr<i_expr> body;{go_auto(body);}}
      t_template_expr=>i_body{
        t_main{vector<t_fv_class_stat::t_type_expr::t_type_with_sep> arr;{go_vec(arr,"::");}}
        t_main body;
        {go_diff<t_raw_expr>(body);}
      }
      t_sep sep0;
      TAutoPtr<i_body> body;
      t_sep sep1;
      {
        O+=go_auto(sep0);
        M+=go_auto(body);
        O+=go_auto(sep1);
      }
    }
    t_concrete_params{
      vector<t_concrete_param> arr;
      t_sep sep;
      {
        M+=go_const("<");
        O+=go_vec(arr,",");
        M+=go_const(">");
        O+=go_auto(sep);
      }
    }
    t_common_oper_template_body=>i_template_body{t_common_oper_class_stat::t_impl body;{go_auto(body);}}
    t_ctor_template_body=>i_template_body{t_ctor_class_stat::t_impl body;{go_auto(body);}}
    t_func_template_body=>i_template_body{
      vector<t_fv_class_stat::t_type_expr::t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv0;
      t_sep sep0;
      string func_name;
      TAutoPtr<t_concrete_params> concrete_params;
      t_sep sep1;
      t_fv_class_stat::t_type_expr::t_func_params params;
      t_sep sep2;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
      {
        O+=go_auto(keywords);
        M+=go_auto(type);
        O+=go_auto(cv0);
        O+=go_auto(sep0);
        M+=go_str<t_name>(func_name);
        O+=go_auto(concrete_params);
        O+=go_auto(sep1);
        M+=go_auto(params);
        O+=go_auto(sep2);
        O+=go_auto(cv1);
        M+=go_auto(body);
      }
    }
    t_class_template_body=>i_template_body{
      string keyword;
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_concrete_params> params;
      TAutoPtr<t_parents> parents;
      t_sep sep2;
      TAutoPtr<t_class_body> body;
      t_sep sep3;
      {
        M+=go_any_str_from_vec(keyword,split("struct,class",","));
        M+=go_auto(sep0);
        O+=go_str<t_name>(name);
        O+=go_auto(sep1);
        O+=go_auto(params);
        O+=go_auto(parents);
        O+=go_auto(sep2);
        O+=go_auto(body);
        O+=go_auto(sep3);
        M+=go_const(";");
      }
    }
    t_head{
      t_sep sep0;
      vector<t_template_param> params;
      t_sep sep1;
      TAutoPtr<i_template_body> body;
      {
        M+=go_const("template");
        O+=go_auto(sep0);
        M+=go_const("<");
        O+=go_vec(params,",");
        M+=go_const(">");
        O+=go_auto(sep1);
      }
    }
    t_name_template_param=>i_template_param{
      string type;
      t_sep sep;
      string name;
      {
        M+=go_str<t_name>(type);
        O+=go_auto(sep);
        O+=go_str<t_name>(name);
      }
    }
    t_type_template_param=>i_template_param{
      TAutoPtr<t_head> head;
      string type;
      t_sep sep;
      string name;
      {
        O+=go_auto(head);
        M+=go_any_str_from_vec(type,split("class,typename",","));
        O+=go_auto(sep);
        O+=go_str<t_name>(name);
      }
    }
    t_head head;
    vector<t_template_param> params;
    TAutoPtr<i_template_body> body;
    {
      M+=go_auto(head);
      M+=go_auto(body);
    }
  }
  t_enum_class_stat=>i_class_stat{
    t_value{
      t_sep sep0;
      TAutoPtr<i_expr> expr;
      t_sep sep1;
      {
        M+=go_const("=");
        O+=go_auto(sep0);
        M+=go_auto(expr);
        O+=go_auto(sep1);
      }
    }
    t_item{
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_value> value;
      {
        O+=go_auto(sep0);
        M+=go_str<t_name>(name);
        O+=go_auto(sep1);
        O+=go_auto(value);
      }
    }
    t_impl_body=>i_body{
      vector<t_item> arr;
      {
        M+=go_const("{");
        O+=go_vec(arr,",");
        M+=go_const("}");
      }
    }
    t_empty_body=>i_body{{go_const(";");}}
    t_body{TAutoPtr<i_body> body;{go_auto(body);}}
    t_sep sep0;
    string name;
    t_sep sep1;
    t_body body;
    {
      M+=go_const("enum");
      O+=go_auto(sep0);
      O+=go_str<t_name>(name);
      O+=go_auto(sep1);
      O+=go_auto(body);
    }
  }
  t_sep_stat=>i_class_stat{t_sep sep;{go_auto(sep);}}
  t_null_class_stat=>i_class_stat{{go_const(";");}}
  t_class_class_stat=>i_class_stat{t_class body;{go_auto(body);}}
  t_inl_file_stat{
    t_sep sep;
    TAutoPtr<t_class> body;
    {
      O+=go_auto(sep);
      M+=go_auto(body);
    }
  }
  vector<TAutoPtr<i_class_stat>> arr;
  {
    go_auto(arr);
  }
}
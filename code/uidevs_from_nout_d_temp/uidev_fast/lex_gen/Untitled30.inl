      t_fv_stat{
        t_impl_func_body=>i_fv_body{t_sep sep;t_raw_func_body body;{O+=go_auto(sep);M+=go_auto(body);}}
        t_zero_func_body=>i_fv_body{{go_const("=0;");}}
        t_delete_func_body=>i_fv_body{{go_const("=delete;");}}
        t_empty_func_body=>i_fv_body{{go_const(";");}}
        t_func_fv_end=>i_fv_end{
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
        t_var_arr_fv_end=>i_fv_end{
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
          t_sep sep1;
          TAutoPtr<t_func_param_value> value;
          t_sep sep2;
          {
            M+=go_auto(body);
            O+=go_auto(sep1);
            O+=go_auto(value);
            O+=go_auto(sep2);
            M+=go_const(";");
          }
        }
        t_var_init_fv_end=>i_fv_end{
          t_sep sep0;
          TAutoPtr<t_func_param_value> value;
          t_sep sep1;
          {
            M+=go_auto(value);
            O+=go_auto(sep1);
            M+=go_const(";");
          }
        }
        t_var_def_fv_end=>i_fv_end{{go_const(";");}}
        vector<t_keyword> keywords;
        TAutoPtr<t_type_expr> type;
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep0;
        string name;
        t_sep sep1;
        TAutoPtr<i_fv_end> way;
        {
          O+=go_auto(keywords);
          M+=go_auto(type);
          O+=go_auto(cv);
          O+=go_auto(sep0);
          M+=go_str<t_name>(name);
          O+=go_auto(sep1);
          M+=go_auto(way);
        }
      }
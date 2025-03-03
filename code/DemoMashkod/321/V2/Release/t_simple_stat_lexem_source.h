t_string{
  vector<TAutoPtr<i_str_item>> arr;
  {
    M+=go_const("\"");
    O+=go_auto(arr);
    M+=go_const("\"");
  }
}

t_simple_stat_lex{
  t_type_expr{
    t_params{
      t_name name;
      t_int_expr count;
      {
        go_const("{");
        go_auto(name);
        go_const(",");
        go_auto(count);
        go_const("}");
      }
    }
    t_elem{
      t_name name;
      TAutoPtr<t_params> params;
      {
        M+=go_auto(name);
        O+=go_auto(params);
      }
    }
    t_item{
      t_sep sep0;
      t_sep sep1;
      t_elem body;
      {
        O+=go_auto(sep0);
        M+=go_const("::");
        O+=go_auto(sep1);
        M+=go_auto(body);
      }
    }
    t_elem first;
    vector<t_item> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }
  t_struct{
    t_field{
      t_sep sep0;
      t_var_stat::t_impl body;
      t_sep sep1;
      {
        O+=go_auto(sep0);
        M+=go_auto(body);
        M+=go_const(";");
        O+=go_auto(sep1);
      }
    }
    t_method{
      t_sep sep0;
      t_func_stat::t_impl body;
      t_sep sep1;
      {
        O+=go_auto(sep0);
        M+=go_auto(body);
        O+=go_auto(sep1);
      }
    }
    t_sep sep0;
    t_name name;
    t_sep sep1;
    vector<t_sep_struct> arr;
    vector<t_field> fields;
    vector<t_method> methods;
    {
      M+=go_const("struct");
      M+=go_auto(sep0);
      M+=go_auto(name);
      O+=go_auto(sep1);
      M+=go_const("{");
      O+=go_auto(arr);
      O+=go_auto(fields);
      O+=go_auto(methods);
      M+=go_const("}");
    }
  }
  t_sep_struct{
    t_sep sep0;
    t_struct body;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      M+=go_auto(body);
      O+=go_auto(sep1);
    }
  }
  t_struct_stat=>i_stat{
    t_struct body;
    {
      go_auto(body);
    }
  }
  
  t_var_stat=>i_stat{
    t_type_impl=>i_impl{
      t_name type;
      t_sep sep0;
      t_name name;
      t_sep sep1;
      t_sep sep2;
      t_lev14 value;
      t_sep sep3;
      {
        M+=go_auto(type);
        M+=go_auto(sep0);
        M+=go_auto(name);
        O+=go_auto(sep1);
        M+=go_const("=");
        O+=go_auto(sep2);
        M+=go_auto(value);
        O+=go_auto(sep3);
      }
    }
    t_auto_impl=>i_impl{
      t_sep sep0;
      t_name name;
      t_sep sep1;
      t_sep sep2;
      t_lev14 value;
      t_sep sep3;
      {
        M+=go_const("auto");
        M+=go_auto(sep0);
        M+=go_auto(name);
        O+=go_auto(sep1);
        M+=go_const("=");
        O+=go_auto(sep2);
        M+=go_auto(value);
        O+=go_auto(sep3);
      }
    }
    TAutoPtr<i_impl> body;
    {
      go_auto(body);
      go_const(";");
    }
  }

  t_sep_stat=>i_stat{
    t_sep sep;
    {
      go_auto(sep);
    }
  }

  t_command_block{
    vector<TAutoPtr<i_stat>> arr;
    {
      go_auto(arr);
    }
  }

  t_block_stat=>i_stat{
    t_command_block body;
    {
      M+=go_const("{");
      O+=go_auto(body);
      M+=go_const("}");
    }
  }

  t_expr_stat=>i_stat{
    TAutoPtr<i_expr> body;
    {
      go_auto(body);
      go_const(";");
    }
  }
  
  t_dot_expr=>i_expr{
    t_item{
      t_name name;
      {
        go_const(".");
        go_auto(name);
      }
    }
    t_name var;
    vector<t_item> arr;
    {
      M+=go_auto(var);
      M+=go_auto(arr);
    }
  }

  t_char_expr=>i_expr{
    t_char_item body;
    {
      go_auto(body);
    }
  }
  
  t_bool_expr=>i_expr{
    t_false=>i_bool{{go_const("false");}}
    t_true=>i_bool{{go_const("true");}}
    t_impl{
      TAutoPtr<i_bool> body; 
      {
        go_auto(body);
      }
    }
    string value;
    {
      go_str<t_impl>(value);
    }
  }
  
  t_int_expr=>i_expr{
    t_zero=>i_val{{go_const("0");}}
    t_num=>i_val{
      char first='1';
      string num;
      {
        M+=go_any_char(first,gen_dips("19"));
        O+=go_any(num,gen_dips("09"));
      }
    }
    string value;
    {go_str<TAutoPtr<i_val>>(value);}
  }
  
  t_real_expr=>i_expr{
    t_frac{
      string arr;
      {
        go_const(".");
        go_any(arr,gen_dips("09"));
      }
    }
    t_sign{
      char sign='+';
      {
        go_any_char(sign,"-+");
      }
    }
    t_exp{
      char e='e';
      TAutoPtr<t_sign> sign;
      string arr;
      {
        M+=go_any_char(e,"eE");
        O+=go_auto(sign);
        M+=go_any(arr,gen_dips("09"));
      }
    }
    t_num=>i_val{
      char first='1';
      string num;
      {
        M+=go_any_char(first,gen_dips("19"));
        O+=go_any(num,gen_dips("09"));
      }
    }
    t_zero=>i_val{{go_const("0");}}
    t_impl{
      TAutoPtr<i_val> val;
      TAutoPtr<t_frac> frac;
      TAutoPtr<t_exp> exp;
      {
        M+=go_auto(val);
        M+=go_auto(frac);
        O+=go_auto(exp);
      }
    }
    string value;
    {go_str<t_impl>(value);}
  }

  t_string_expr=>i_expr{
    t_string body;
    {
      go_auto(body);
    }
  }

  t_var_expr=>i_expr{
    t_elem{
      t_sep sep0;
      TAutoPtr<t_lev14> expr;
      t_sep sep1;
      {
        M+=go_const("[");
        O+=go_auto(sep0);
        M+=go_auto(expr);
        O+=go_auto(sep1);
        M+=go_const("]");
      }
    }
    t_item{
      t_name name;
      vector<t_elem> arr;
      {
        M+=go_auto(name);
        O+=go_auto(arr);
      }
    }
    t_impl{
      vector<t_item> arr;
      {
        go_vec(arr,".");
      }
    }
    t_impl body;
    {
      go_auto(body);
    }
  }

  t_block_expr=>i_expr{
    TAutoPtr<i_expr> body;
    {
      go_const("(");
      go_auto(body);
      go_const(")");
    }
  }

  t_if_stat=>i_stat{
    t_stat=>i_body{TAutoPtr<i_stat> body;{go_auto(body);}}
    t_block=>i_body{t_block_stat body;{go_auto(body);}}
    t_else{
      t_sep sep0;
      t_sep sep1;
      TAutoPtr<i_body> body;
      {
        O+=go_auto(sep0);
        M+=go_const("else");
        O+=go_auto(sep1);
        M+=go_auto(body);
      }
    }
    //t_cond cond;
    //TAutoPtr<i_body> bef;
    //TAutoPtr<t_else> aft;
    //{go_auto(cond);}
  }
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  t_prio6_subexpr{
    TAutoPtr<i_prio5_expr> body;
    {
      go_auto(body);
    }
  }

  t_sep_prio6_subexpr{
    char sep;
    TAutoPtr<t_prio6_subexpr> body;
    {
      go_any_char(sep,"+-");
      go_auto(body);
    }
  }

  t_prio6_expr=>i_expr{
    t_prio6_subexpr first;
    vector<t_sep_prio6_subexpr> arr;
    {
      go_auto(first);
      go_auto(arr);
    }
  }

  t_call_param{
    TAutoPtr<i_expr> body;
    {
      go_auto(body);
    }
  }

  t_call_comma_param{
    t_call_param param;
    {
      go_const(",");
      go_auto(param);
    }
  }

  t_call_params{
    t_call_param first;
    vector<t_call_comma_param> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }

  t_call_expr=>i_expr{
    t_field{
      t_name name;
      {
        go_const(".");
        go_auto(name);
      }
    }
    t_type{
      t_name name;
      {
        go_const("::");
        go_auto(name);
      }
    }
    t_fields=>i_next{vector<t_field> arr;{go_auto(arr);}}
    t_types=>i_next{vector<t_type> arr;{go_auto(arr);}}
    t_next{TAutoPtr<i_next> body;{go_auto(body);}}
    t_name first;
    TAutoPtr<t_next> next;
    t_sep sep;
    t_call_params params;
    {
      M+=go_auto(first);
      O+=go_auto(next);
      O+=go_auto(sep);
      M+=go_auto(params);
    }
  }

  t_param{
    t_name type;
    t_name name;
    {
      go_auto(type);
      go_const(" ");
      go_auto(name);
    }
  }

  t_comma_param{
    t_param body;
    {
      go_const(",");
      go_auto(body);
    }
  }

  t_params{
    t_param first;
    vector<t_comma_param> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }

  t_func_body{
    vector<TAutoPtr<i_stat>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }

  t_func_stat=>i_stat{
    t_name type;
    t_name name;
    TAutoPtr<t_params> params;
    t_sep sep;
    t_func_body body;
    {
      M+=go_auto(type);
      M+=go_const(" ");
      M+=go_auto(name);
      M+=go_const("(");
      O+=go_auto(params);
      M+=go_const(")");
      O+=go_auto(sep);
      M+=go_auto(body);
    }
  }

  t_ret_stat=>i_stat{
    TAutoPtr<i_expr> body;
    {
      go_const("return ");
      go_auto(body);
      go_const(";");
    }
  }

  t_null_stat=>i_stat{
    {
      go_const(";");
    }
  }
/*
++  Suffix increment Left-to-right
--  Suffix decrement
()  Function call
[]  Array subscripting
.   Element selection by reference
*/
  t_suffix_expr=>i_expr{
    TAutoPtr<i_expr> body;
    char oper='+';
    {
      go_auto(body);
      go_any_char(oper,"+-");
      go_const(oper);
    }
  }

  t_prio2_expr=>i_expr{
    TAutoPtr<i_expr> body;
    t_suffix_expr oper;
    {
      go_auto(body);
      go_auto(oper);
    }
  }

  t_inc_unaryoper=>i_unaryoper{{go_const("++");}}
  t_dec_unaryoper=>i_unaryoper{{go_const("--");}}
  t_add_unaryoper=>i_unaryoper{{go_const("+");}}
  t_sub_unaryoper=>i_unaryoper{{go_const("-");}}
  t_not_unaryoper=>i_unaryoper{{go_const("!");}}
  t_inv_unaryoper=>i_unaryoper{{go_const("~");}}

  t_prio3_expr=>i_expr{
    TAutoPtr<i_unaryoper> oper;
    TAutoPtr<i_expr> body;
    {
      go_auto(oper);
      go_auto(body);
    }
  }

  t_prio5_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    char oper='*';
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_any_char(oper,"*/%");
      go_auto(aft);
    }
  }

  t_prio6_expr=>i_expr{
    t_expr{TAutoPtr<i_expr> body;{go_auto(body);}}
    t_item{char oper='+';t_expr body;{go_any_char(oper,"+-");go_auto(body);}}
    t_expr first;
    vector<t_item> arr;
    {
      go_auto(first);
      go_auto(arr);
    }
  }

  t_prio7_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    char oper='<';
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_any_char(oper,"<>");
      go_const(oper);
      go_auto(aft);
    }
  }

  t_lt_compoper=>i_compoper{{go_const("<");}}
  t_lteq_compoper=>i_compoper{{go_const("<=");}}
  t_gt_compoper=>i_compoper{{go_const(">");}}
  t_gteq_compoper=>i_compoper{{go_const(">=");}}

  t_prio8_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_compoper> oper;
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_auto(oper);
      go_auto(aft);
    }
  }

  t_prio9_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    char oper='=';
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_any_char(oper,"=!");
      go_const("=");
      go_auto(aft);
    }
  }

  t_prio10_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_const("&");
      go_auto(aft);
    }
  }

  t_prio11_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_const("^");
      go_auto(aft);
    }
  }

  t_prio12_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_const("|");
      go_auto(aft);
    }
  }

  t_prio13_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_const("&&");
      go_auto(aft);
    }
  }

  t_prio14_expr=>i_expr{
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_expr> aft;
    {
      go_auto(bef);
      go_const("||");
      go_auto(aft);
    }
  }

  t_prio15_expr=>i_expr{
    TAutoPtr<i_expr> cond;
    TAutoPtr<i_expr> bef;
    TAutoPtr<i_expr> aft;
    {
      go_auto(cond);
      go_const("?");
      go_auto(bef);
      go_const(":");
      go_auto(aft);
    }
  }

  t_set_setoper=>i_setoper{{go_const("=");}}
  t_add_setoper=>i_setoper{{go_const("+=");}}
  t_sub_setoper=>i_setoper{{go_const("-=");}}
  t_mul_setoper=>i_setoper{{go_const("*=");}}
  t_div_setoper=>i_setoper{{go_const("/=");}}
  t_mod_setoper=>i_setoper{{go_const("%=");}}
  t_lsh_setoper=>i_setoper{{go_const("<<=");}}
  t_rsh_setoper=>i_setoper{{go_const(">>=");}}
  t_and_setoper=>i_setoper{{go_const("&=");}}
  t_xor_setoper=>i_setoper{{go_const("^=");}}
  t_or_setoper=>i_setoper{{go_const("|=");}}

  t_prio16_expr=>i_expr{
    t_name name;
    TAutoPtr<i_setoper> oper;
    TAutoPtr<i_expr> value;
    {
      go_auto(name);
      go_auto(oper);
      go_auto(value);
    }
  }

}
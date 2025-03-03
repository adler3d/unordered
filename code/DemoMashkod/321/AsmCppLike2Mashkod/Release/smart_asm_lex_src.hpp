t_smart_asm{

t_string{
  string value;
  {
    M+=go_const("\"");
    O+=go_str<vector<TAutoPtr<i_str_item>>>(value);
    M+=go_const("\"");
  }
}

t_number{
  t_zero=>i_val{
    {
      go_const("0");
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
  string value;
  {
    go_str<TAutoPtr<i_val>>(value);
  }
}

t_string_expr=>i_expr{
  t_string body;
  {
    go_auto(body);
  }
}

t_char_expr=>i_expr{
  t_char_item body;
  {
    go_auto(body);
  }
}

t_bool_expr=>i_expr{
  string value;
  {
    go_any_str_from_vec(value,split("false,true",","));
  }
}

t_num_expr=>i_expr{
  string value;
  {
    go_str<t_number>(value);
  }
}

t_reg_expr=>i_expr{
  t_field=>i_ext{
    string field;
    {
      go_const(".");
      go_str<t_name>(field);
    }
  }
  t_id=>i_ext{
    t_num=>i_case{
      string value;{go_str<t_number>(value);}
    }
    t_reg=>i_case{
      string value;{go_str<t_name>(value);}
    }
    TAutoPtr<i_case> idexpr;
    {
      go_const("[");
      go_auto(idexpr);
      go_const("]");
    }
  }
  t_ext{
    TAutoPtr<i_ext> body;
    {go_auto(body);}
  }
  string name;
  TAutoPtr<t_ext> ext;
  {
    M+=go_str<t_name>(name);
    O+=go_auto(ext);
  }
}

t_nop_stat=>i_stat{
  {
    go_const("nop");
  }
}

t_ret_stat=>i_stat{
  TAutoPtr<i_expr> expr;
  {
    go_const("ret");
    go_const(" ");
    go_auto(expr);
  }
}

t_label{
  t_sep sep0;
  string name;
  t_sep sep1;
  {
    M+=go_const(":");
    O+=go_auto(sep0);
    M+=go_str<t_name>(name);
    O+=go_auto(sep1);
  }
}

t_call_stat=>i_stat{
  t_params{
    vector<TAutoPtr<i_expr>> arr;
    {
      go_const(" ");
      go_vec(arr," ");
    }
  }
  t_string func;
  t_reg_expr out;
  TAutoPtr<t_params> params;
  {
    M+=go_const("call");
    M+=go_const(" ");
    M+=go_auto(func);
    M+=go_const(" ");
    M+=go_auto(out);
    O+=go_auto(params);
  }
}

t_block{
  vector<TAutoPtr<i_stat>> arr;
  {
    M+=go_const("{");
    O+=go_auto(arr);
    M+=go_const("}");
  }
}

t_block_stat=>i_stat{
  t_block body;
  {
    go_auto(body);
  }
}

t_type{
  t_params{
    string type;
    t_number count;
    {
      go_const("{");
      go_str<t_type>(type);
      go_const(",");
      go_auto(count);
      go_const("}");
    }
  }
  t_name name;
  TAutoPtr<t_params> params;
  {
    M+=go_auto(name);
    O+=go_auto(params);
  }
}

t_set_stat=>i_stat{
  t_reg_expr reg;
  TAutoPtr<i_expr> expr;
  {
    go_auto(reg);
    go_const("=");
    go_auto(expr);
  }
}

t_auto_stat=>i_stat{
  t_name name;
  TAutoPtr<i_expr> expr;
  {
    go_const("auto");
    go_const(" ");
    go_auto(name);
    go_const("=");
    go_auto(value);
  }
}

t_var_stat=>i_stat{
  t_type type;
  t_name name;
  {
    go_const("var");
    go_const(" ");
    go_auto(type);
    go_const(" ");
    go_auto(name);
  }
}

t_if_stat=>i_stat{
  t_cond{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("cond");O+=go_auto(sep1);M+=go_auto(body);}}
  t_then{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("then");O+=go_auto(sep1);M+=go_auto(body);}}
  t_else{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("else");O+=go_auto(sep1);M+=go_auto(body);}}
  t_sep sep0;
  t_cond cond;
  TAutoPtr<t_then> bef;
  TAutoPtr<t_else> aft;
  t_sep sep1;
  {
    M+=go_const("if");
    O+=go_auto(sep0);
    M+=go_const("{");
    M+=go_auto(cond);
    O+=go_auto(bef);
    O+=go_auto(aft);
    O+=go_auto(sep1);
    M+=go_const("}");
  }
}

t_loop_stat=>i_stat{
  t_sep sep;
  TAutoPtr<t_label> label;
  t_block code;
  {
    M+=go_const("loop");
    O+=go_auto(sep);
    O+=go_auto(label);
    M+=go_auto(code);
  }
}

t_for_stat=>i_stat{
  t_rec{
    t_sep sep;
    t_var_stat var;
    {
      O+=go_auto(sep);
      M+=go_auto(var);
    }
  }
  t_init{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("init");O+=go_auto(sep1);M+=go_auto(body);}}
  t_cond{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("cond");O+=go_auto(sep1);M+=go_auto(body);}}
  t_body{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("body");O+=go_auto(sep1);M+=go_auto(body);}}
  t_next{t_sep sep0;t_sep sep1;t_block body;{O+=go_auto(sep0);M+=go_const("next");O+=go_auto(sep1);M+=go_auto(body);}}
  t_sep sep0;
  TAutoPtr<t_label> label;
  vector<t_rec> arr;
  TAutoPtr<t_init> init;
  TAutoPtr<t_cond> cond;
  TAutoPtr<t_body> body;
  TAutoPtr<t_next> next;
  t_sep sep1;
  {
    M+=go_const("for");
    O+=go_auto(sep0);
    O+=go_auto(label);
    M+=go_const("{");
    O+=go_auto(arr);
    O+=go_auto(init);
    O+=go_auto(cond);
    O+=go_auto(body);
    O+=go_auto(next);
    O+=go_auto(sep1);
    M+=go_const("}");
  }
}

t_break_stat=>i_stat{
  TAutoPtr<t_label> label;
  {
    M+=go_const("break");
    O+=go_auto(label);
  }
}

t_continue_stat=>i_stat{
  TAutoPtr<t_label> label;
  {
    M+=go_const("continue");
    O+=go_auto(label);
  }
}

t_sep_stat=>i_stat{
  t_sep sep;
  {
    go_auto(sep);
  }
}

t_comment_stat=>i_node{
  string body;
  {
    go_const(";");
    go_end(body,"\n");
  }
}

t_func_node=>i_node{
  t_param{
    string type;
    string name;
    {
      M+=go_str<t_type>(type);
      M+=go_const(" ");
      M+=go_str<t_name>(name);
    }
  }
  string type;
  t_string name;
  vector<t_param> params;
  t_sep sep;
  t_block code;
  {
    M+=go_str<t_type>(type);
    M+=go_const(" ");
    M+=go_auto(name);
    M+=go_const("(");
    O+=go_vec(params,",");
    M+=go_const(")asm");
    O+=go_auto(sep);
    M+=go_auto(code);
  }
}

t_struct_node=>i_node{
  t_field{
    t_sep sep;
    string type;
    string name;
    {
      O+=go_auto(sep);
      M+=go_str<t_type>(type);
      M+=go_const(" ");
      M+=go_str<t_name>(name);
      M+=go_const(";");
    }
  }
  string name;
  t_sep sep0;
  vector<t_field> arr;
  t_sep sep1;
  {
    M+=go_const("struct ");
    M+=go_str<t_name>(name);
    O+=go_auto(sep0);
    M+=go_const("{");
    O+=go_auto(arr);
    O+=go_auto(sep1);
    M+=go_const("}");
  }
}

t_sep_node=>i_node{
  string sep;
  {
    go_str<t_sep>(sep);
  }
}

t_comment_node=>i_node{
  string body;
  {
    go_const(";");
    go_end(body,"\n");
  }
}

t_asm_scope{
  vector<TAutoPtr<i_node>> arr;{go_auto(arr);}
}
}
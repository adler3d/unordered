t_name_code=>i_code{
  string value;
  {
    go_str<t_name::t_impl>(value);
  }
}

t_num_code=>i_code{
  t_number body;
  {
    go_auto(body);
  }
}

t_str_seq{
  vector<i_str_item> arr;
  {
    M+=go_const("\"");
    O+=go_auto(arr);
    M+=go_const("\"");
  }
}

t_sep_str_seq{
  t_sep sep;
  t_str_seq body;
  {
    go_auto(sep);
    go_auto(body);
  }
}

t_str_code=>i_code{
  t_str_seq first;
  vector<t_sep_str_seq> arr;
  {
    M+=go_auto(first);
    O+=go_auto(arr);
  }
}

t_char_code=>i_code{
  i_char_item body;
  {
    go_const("'");
    go_auto(body);
    go_const("'");
  }
}

t_sign_code=>i_code{
  t_sign body;
  {
    go_auto(body);
  }
}

t_code{
  vector<i_code> arr;
  {
    go_auto(arr);
  }
}

t_soft_brackets_code=>i_code{
  t_sep sep0;
  t_code body;
  t_sep sep1;
  {
    M+=go_const("(");
    O+=go_auto(sep0);
    O+=go_auto(body);
    O+=go_auto(sep1);
    M+=go_const(")");
  }
}

t_hard_brackets_code=>i_code{
  t_sep sep0;
  t_code body;
  t_sep sep1;
  {
    M+=go_const("[");
    O+=go_auto(sep0);
    O+=go_auto(body);
    O+=go_auto(sep1);
    M+=go_const("]");
  }
}

t_curly_brackets_code=>i_code{
  t_sep sep0;
  t_code body;
  t_sep sep1;
  {
    M+=go_const("{");
    O+=go_auto(sep0);
    O+=go_auto(body);
    O+=go_auto(sep1);
    M+=go_const("}");
  }
}

t_semicolon{
  {
    go_const(";");
  }
}

t_value_item{
  i_code_with_sep body;
  {
    go_minor<t_semicolon>(body);
  }
}

t_value{
  t_sep sep;
  string body;
  {
    O+=go_auto(sep);
    M+=go_const("=");
    M+=go_str<vector<t_value_item>>(body);
  }
}

t_type_scope{
  {
    go_const("::");
  }
}

t_type_templ{
  i_type_templ body;
  {
    go_auto(body);
  }
}

t_type_item_string=>i_type_item{
  t_str_item body;
  {
    go_auto(body);
  }
}

t_type_item_char=>i_type_item{
  t_char_item body;
  {
    go_auto(body);
  }
}

t_type_item_number=>i_type_item{
  t_number body;
  {
    go_auto(body);
  }
}

t_type_item_type=>i_type_item{
  t_type_scope scope;
  t_name type;
  t_type_templ param;
  vector<t_scope_type_item> arr;
  {
    O+=go_auto(scope);
    M+=go_auto(type);
    O+=go_auto(param);
    O+=go_auto(arr);
  }
}

t_scope_type_item{
  t_type_scope scope;
  t_type_item_type body;
  {
    go_auto(scope);
    go_auto(body);
  }
}

t_type_expr{
  t_type_scope scope;
  t_type_item_type body;
  {
    O+=go_auto(scope);
    M+=go_auto(body);
  }
}

t_type_templ_param{
  i_type_item body;
  {
    go_auto(body);
  }
}

t_sep_type_templ_param{
  t_type_templ_param body;
  {
    go_const(",");
    go_auto(body);
  }
}

t_type_templ_params{
  t_type_templ_param first;
  vector<t_sep_type_templ_param> arr;
  {
    M+=go_auto(first);
    O+=go_auto(arr);
  }
}

t_type_templ_angle=>i_type_templ{
  t_type_templ_params params;
  {
    M+=go_const("<");
    O+=go_auto(params);
    M+=go_const(">");
  }
}

t_type_templ_soft=>i_type_templ{
  t_type_templ_params params;
  {
    M+=go_const("(");
    O+=go_auto(params);
    M+=go_const(")");
  }
}

t_struct_field{
  t_type_expr type;
  t_sep sep0;
  t_name name;
  t_sep sep1;
  t_value value;
  {
    M+=go_auto(type);
    M+=go_auto(sep0);
    M+=go_auto(name);
    O+=go_auto(value);
    O+=go_auto(sep1);
    M+=go_const(";");
  }
}

t_sep_struct_field{
  t_sep sep;
  t_struct_field body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
}

t_struct_cmd_mode{
  char body;
  {
    M+=go_any_char(body,"MO");
    M+=go_const("+=");
  }
}

t_templ_params{
  string body;
  {
    go_const("<");
    go_str<t_type_templ_params>(body);
    go_const(">");
  }
}

t_cmd_param{
  string body;
  {
    go_str<t_cmd_param.impl>(body);
  }

  impl{
    vector<i_expr> arr;
    {
      go_vec(arr,"+");
    }
  }

  t_expr_call=>i_expr{
    t_name func;
    t_cmd_params params;
    {
      go_auto(func);
      go_const("(");
      go_auto(params);
      go_const(")");
    }
  }

  t_expr_str=>i_expr{
    string body;
    {
      go_str<t_str_seq>(body);
    }
  }

  t_expr_var=>i_expr{
    string body;
    {
      go_str<t_expr_var.impl>(body);
    }

    t_this{
      {
        go_const("this->");
      }
    }

    impl{
      t_this self;
      t_name name;
      {
        O+=go_auto(self);
        M+=go_auto(name);
      }
    }
  }
}

t_cmd_params{
  vector<t_cmd_param> arr;
  {
    go_vec(arr,",");
  }
}

t_struct_cmd{
  t_struct_cmd_mode mode;
  t_name func;
  string templ_params;
  t_cmd_params params;
  {
    O+=go_auto(mode);
    M+=go_auto(func);
    O+=go_str<t_templ_params>(templ_params);
    M+=go_const("(");
    M+=go_auto(params);
    M+=go_const(");");
  }
}

t_sep_struct_cmd{
  t_sep sep;
  t_struct_cmd body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
}

t_struct_cmds{
  vector<t_sep_struct_cmd> arr;
  t_sep sep;
  {
    M+=go_const("{");
    M+=go_auto(arr);
    O+=go_auto(sep);
    M+=go_const("}");
  }
}

t_sep_struct_cmds{
  t_sep sep;
  t_struct_cmds body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
}

t_cpp_code_sep=>i_cpp_code{
  t_sep sep;
  {
    go_auto(sep);
  }
}

t_cpp_code_main=>i_cpp_code{
  i_code_with_sep body;
  {
    go_auto(body);
  }
}

t_cpp_code{
  vector<i_cpp_code> arr;
  {
    M+=go_const("[::]");
    O+=go_auto(arr);
  }
}

t_struct_body{
  vector<t_target_item> nested;
  t_sep sep0;
  vector<t_sep_struct_field> arr;
  t_sep_struct_cmds cmds;
  t_sep sep1;
  t_cpp_code cppcode;
  {
    M+=go_const("{");
    O+=go_auto(nested);
    O+=go_auto(sep0);
    O+=go_auto(arr);
    O+=go_auto(cmds);
    O+=go_auto(sep1);
    O+=go_auto(cppcode);
    M+=go_const("}");
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
  t_sep sep;
  i_def def;
  t_struct_body body;
  {
    O+=go_auto(sep);
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
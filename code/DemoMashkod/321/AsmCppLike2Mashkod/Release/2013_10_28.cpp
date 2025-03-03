t_sep_seq=>i_sep{
  string body;
  {
    go_any(body," \t\r\n");
  }
}

t_c_comment=>i_sep{
  string body;
  {
    go_const("/*");
    go_end(body,"*/");
  }
}

t_cpp_comment=>i_sep{
  string body;
  {
    go_const("//");
    go_end(body,"\n");
  }
}

t_sep{
  vector<TAutoPtr<i_sep>> arr;
  {
    go_auto(arr);
  }
}

t_raw_item=>i_str_item{
  string body;
  {
    go_any(body,dip_inv("\"\\\n"));
  }
}

t_hex_item=>i_str_item{
  array(char,2) body;
  {
    go_const("\\x");
    go_any_arr_char(body,gen_dips("09afAF"));
  }
}

t_num_item=>i_str_item{
  array(char,2) body;
  {
    go_const("\\u");
    go_any_arr_char(body,gen_dips("09"));
  }
}

t_fix_item=>i_str_item{
  char body='\x00';
  {
    go_const("\\");
    go_any_char(body,"tfbrn\\\"\'"+gen_dips("09"));
  }
}


t_str=>i_param{
  vector<TAutoPtr<i_str_item>> arr;
  {
    M+=go_const("\"");
    O+=go_auto(arr);
    M+=go_const("\"");
  }
}

t_raw_char=>i_char_item{
  string body;
  {
    go_any(body,dip_inv("\'\\\n"));
  }
}

t_hex_chat=>i_char_item{
  array(char,2) body;
  {
    go_const("\\x");
    go_any_arr_char(body,gen_dips("09afAF"));
  }
}

t_num_char=>i_char_item{
  array(char,4) body;
  {
    go_const("\\u");
    go_any_arr_char(body,gen_dips("09"));
  }
}

t_fix_char=>i_char_item{
  char body;
  {
    go_const("\\");
    go_any_char(body,"tfbrn\\\"\'"+gen_dips("09"));
  }
}

t_char=>i_param{
  TAutoPtr<i_char_item> body;
  {
    go_const("\'");
    go_auto(dev,body);
    go_const("\'");
  }
}

t_number=>i_param{
  string body;
  {
    go_any(body,gen_dips("09"));
  }
}

t_name{
  char A='0x00';
  string B;
  {
    M+=go_any_char(A,gen_dips("azAZ")+"_$@");
    O+=go_any(B,gen_dips("azAZ09")+"_$@");
  }
}

t_id=>i_param{
  t_name body;
  {
    go_auto(body);
  }
}

t_sign=>i_param{
  char body;
  {
    go_any_char(body,"~|&=<>!:?;,.+-*/%^");
  }
}

t_soft_brackets=>i_param{
  vector<TAutoPtr<i_param>> arr;
  {
    M+=go_const("(");
    O+=go_auto(arr);
    M+=go_const(")");
  }
}

t_hard_brackets=>i_param{
  vector<TAutoPtr<i_param>> arr;
  {
    M+=go_const("[");
    O+=go_auto(arr);
    M+=go_const("]");
  }
}

t_curly_brackets=>i_param{
  vector<TAutoPtr<i_param>> arr;
  {
    M+=go_const("{");
    O+=go_auto(arr);
    M+=go_const("}");
  }
}
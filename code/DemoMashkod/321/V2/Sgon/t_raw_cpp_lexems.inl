t_string{
  string value;
  {
    M+=go_const("\"");
    O+=go_str<vector<TAutoPtr<i_str_item>>>(value);
    M+=go_const("\"");
  }
}

i_str_item=>t_str_item_raw|t_str_item_hex|t_str_item_num|t_str_item_fix;

t_str_item_raw=>i_str_item{
  string body;
  {go_any(body,dip_inv("\"\\\n"));}
  string get_code(){return body;}
  string get_value(){return body;}
}

t_str_item_hex=>i_str_item{
  array(char,2) body;
  {go_const("\\x");go_any_arr_char(body,gen_dips("09afAF"));}
  string get_code(){return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value(){
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    auto value=CToS(n);
    return value;
  }
}

t_str_item_num=>i_str_item{
  array(char,2) body;
  {go_const("\\u");go_any_arr_char(body,gen_dips("09"));}
  string get_code(){return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value(){
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    auto value=CToS(n);
    return value;
  }
}

t_str_item_fix=>i_str_item{
  char body;
  {go_const("\\");go_any_char(body,"tfbrn\\\"\'"+gen_dips("07"));}
  string get_code(){return "\\"+CToS(body);}
  string get_value(){
    string code=SelfClass::get_code();
    BinString str=code;
    return str.data;
  }
}

t_char_item{
  string value;
  {go_str<t_impl>(value);}
}

t_impl{
  TAutoPtr<i_char_item> body;
  {go_const("\'");go_auto(body);go_const("\'");}
}

i_char_item=>t_char_item_raw|t_char_item_hex|t_char_item_num|t_char_item_fix;

t_char_item_raw=>i_char_item{
  string body;
  {go_any(body,dip_inv("\'\\\n"));}
  string get_code(){return body;}
  string get_value(){return body;}
}

t_char_item_hex=>i_char_item{
  array(char,2) body;
  {go_const("\\x");go_any_arr_char(body,gen_dips("09afAF"));}
  string get_code(){return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value(){
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    auto value=CToS(n);
    return value;
  }
}

t_char_item_num=>i_char_item{
  array(char,4) body;
  {go_const("\\u");go_any_arr_char(body,gen_dips("09"));}
  string get_code(){return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value(){
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    auto value=CToS(n);
    return value;
  }
}

t_char_item_fix=>i_char_item{
  char body;
  {go_const("\\");go_any_char(body,"tfbrn\\\"\'"+gen_dips("07"));}
  string get_code(){return "\\"+CToS(body);}
  string get_value(){
    string code=SelfClass::get_code();
    BinString str=code;
    return str.data;
  }
}
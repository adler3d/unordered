

t_oper_stat{
  t_param{
    t_sep sep0;
    t_name type;
    t_sep sep1;
    t_name name;
  }
  t_name type;
  t_sep sep0;
  t_sep sep1;
  string oper;
  t_sep sep2;
  t_sep sep3;
  vector<t_param> params;
  {
    M+=go_auto(type);
    M+=go_auto(sep0);
    M+=go_const("operator");
    O+=go_auto(sep1);
    M+=go_any_str_from_vec(
      oper,
      split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%",",")
    );
    O+=go_auto(sep2);
    M+=go_const("(");
    O+=go_vec(params,",");
    O+=go_auto(sep3);
    M+=go_const(")");
    M+=go_auto(body);
  }
}


















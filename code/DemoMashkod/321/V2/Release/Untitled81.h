//23:16

//template<class EXPR_TYPE,class OPER_TYPE>
t_bin_oper{
  t_item{
    OPER_TYPE oper;
    EXPR_TYPE expr;
    {go_auto(oper);go_auto(expr);}
  }
  EXPR_TYPE expr;
  vector<t_item> arr;
  {
    go_auto(expr);go_auto(arr);
  }
}

t_oper_level_0{char oper='+';{go_any_char(oper,"+-");}}

t_bin_oper<TAutoPtr<t_level_1::i_expr>,t_oper_level_0> 

//1+1+1+2*2+1

//1+1-2+1

//(16.12+2*2*(1+2+(3)+4+7*16*14*5+1*3)+8)

//

e=true==x*(y+a)+b+c*x<10;
e=true!=x/(y-a)-b-c/x>10;

e|=true!=x/(y-a)-b-c/x>=10;
e&=true==x/(y-a)-b-c/x<=10;
e+=true==x/(y-a)-b-c/x>=10;
e-=true==x/(y-a)-b-c/x<=10;

++i;
a=true!=false;
a=true==1+2*2+3*(4+2)+1>8;

(5-=1==10-100+512*2/2/8>=8%3)

int&foo(int&i){return i;}
foo(i)++;
+1++
//

//--------------------------------------------------
15:"=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>="
14:"||"
13:"&&"
12:"|"
11:"^"
10:"&"
09:"==,!="
08:"<,<=,>,>="
07:"<<,>>"
06:"+,-"
05:"*,/,%"
04:no_impl
03:prefix:"!,~,+,-,++,--"
02:no_bin_oper(),[],.,->++,--
01:"::" type_expr пристройка к имени функций.
//--------------------------------------------------

"t_lev"+cur+"{\n"
"  t_oper{string value;{go_any_str_from_vec(value,split("+next+",\",\"));}}\n"
"  t_item{t_oper oper;t_lev"+next+" expr;{go_auto(oper);go_auto(expr);}}\n"
"  t_lev"+next+" expr;\n"
"  vector<t_item> arr;\n"
"  {go_auto(expr);go_auto(arr);}\n"
"}"

t_matalexpack{
  t_num{
    string body;
    {go_any(body,gen_dips("09"));}
  }
  t_rec{
    t_num bef;
    t_str_item aft;
    {
      go_auto(bef);
      go_const(":");
      go_auto(aft);
    }
  }
  t_line{
    vector<t_rec> arr;{go_auto(arr);}
  }
}










t_yaru{

t_raw_number{
  t_frac{string value;{go_const(".");go_any(value,gen_dips("09"));}}
  string val;
  TAutoPtr<t_frac> frac;
  {
    M+=go_any(val,gen_dips("09"));
    O+=go_auto(frac);
  }
}

t_number_expr=>i_expr{
  string value;
  {
    go_str<t_raw_number>(value);
  }
  [::]public:
  void Use(i_expr_visitor&A){A.Do(this);}
}

t_block_expr=>i_expr{
  TAutoPtr<t_lev0> body;
  {
    go_const("(");
    go_auto(body);
    go_const(")");
  }
  [::]public:
  void Use(i_expr_visitor&A){A.Do(this);}
}

t_lev1{
  t_expr{TAutoPtr<i_expr> body;{go_auto(body);}}
  t_oper{char oper='*';{go_any_char(oper,"*/");}}
  t_item{t_oper oper;t_expr expr;{go_auto(oper);go_auto(expr);}}
  t_expr expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
  [::]public:
  void Use(i_expr_visitor&A){A.Do(this);}
}

t_lev0{
  t_expr{TAutoPtr<t_lev1> body;{go_auto(body);}}
  t_oper{char oper='+';{go_any_char(oper,"+-");}}
  t_item{t_oper oper;t_expr expr;{go_auto(oper);go_auto(expr);}}
  t_expr expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
  [::]public:
  void Use(i_expr_visitor&A){A.Do(this);}
}

}
















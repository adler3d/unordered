#include "big_number.inl"

struct t_big_real{
  bool minus;
  big_number n;
  big_number d;
  static big_number static_oper_sub(const big_number&a,const big_number&b){return a-b;}
  static big_number static_oper_add(const big_number&a,const big_number&b){return a+b;}
  //typedef decltype(&static_oper_sub) t_static_oper_xxx;
  static void common_func(char oper,bool&out_minus,big_number&out,const big_number&a,const big_number&b,bool a_minus,bool b_minus)
  {
    auto za=a_minus?'-':'+';
    auto zb=b_minus?'-':'+';
    char out_oper;
    char zo;
    bool inv_order=false;
    auto zinv=[](const char&z){return z=='-'?'+':'-';};
    auto go=[&](char o,char z,bool io)->void
    {
      out_oper=o;zo=z;inv_order=io;
      out_minus=zo=='-';
      auto&qa=inv_order?b:a;
      auto&qb=inv_order?a:b;
      if(out_oper=='+')
      {
        out=static_oper_add(qa,qb);
        return;
      }
      if(out_oper=='-')
      {
        out=static_oper_sub(qa,qb);
        return;
      }
    };
    if(oper=='-'){zb=zinv(zb);oper='+';}
    QapAssert(oper=='+')
    if(za=='+')if(zb=='+')return go('+','+',false);
    if(za=='+')if(zb=='-')if(a>b)return go('-','+',false);
    if(za=='+')if(zb=='-')if(a<b)return go('-','-',true);
    if(za=='-')if(zb=='-')return go('+','-',false);
    if(za=='-')if(zb=='+')if(a>b)return go('-','-',false);
    if(za=='-')if(zb=='+')if(a<b)return go('-','+',true);
    if(za=='+')if(zb=='-')if(a==b){out="0";out_minus=false;return;}
    if(za=='-')if(zb=='+')if(a==b){out="0";out_minus=false;return;}
  }
  t_big_real operator*(const t_big_real&b)const
  {
    t_big_real out;
    auto&a=*this;
    if(a.n.empty()||b.n.empty())return t_big_real("0");
    out.d=a.d*b.d;
    out.n=a.n*b.n;
    out.minus=a.minus!=b.minus;
    return out;
  }
  t_big_real operator-(const t_big_real&b)const
  {
    t_big_real out;
    auto&a=*this;
    if(a.d==b.d)
    {
      out.d=d;
      common_func('-',out.minus,out.n,a.n,b.n,a.minus,b.minus);
      return out;
    }
    auto nd=a.d*b.d;
    auto na=a.n*b.d;
    auto nb=b.n*a.d;
    out.d=nd;
    common_func('-',out.minus,out.n,na,nb,a.minus,b.minus);
    return out;
  }
  t_big_real operator+(const t_big_real&b)const
  {
    t_big_real out;
    auto&a=*this;
    if(a.d==b.d)
    {
      out.d=d;
      common_func('+',out.minus,out.n,a.n,b.n,a.minus,b.minus);
      return out;
    }
    auto nd=a.d*b.d;
    auto na=a.n*b.d;
    auto nb=b.n*a.d;
    out.d=nd;
    common_func('+',out.minus,out.n,na,nb,a.minus,b.minus);
    return out;
  }
  static t_big_real fromStr(const string&s)
  {
    QapAssert(!s.empty());
    t_big_real out;
    out.minus=false;
    string t=s;
    if(s[0]=='-'){out.minus=true;t=t.substr(1);}
    if(s[0]=='+'){out.minus=false;t=t.substr(1);}
    QapAssert(!t.empty());
    vector<string> arr=split(t,"/");
    if(arr.size()==1)
    {
      out.n=arr[0];
      out.d=1;
      return out;
    }
    if(arr.size()==2)
    {
      out.n=arr[0];
      out.d=arr[1];
      return out;
    }
    QapDebugMsg("WTF?");
    return out;
  }
  void operator=(const string&s){*this=fromStr(s);}
  t_big_real():minus(false){};
  t_big_real(const string&s){*this=fromStr(s);}
  t_big_real(const t_big_real&s){
    this->minus=s.minus;
    this->n=s.n;
    this->d=s.d;
  }
  t_big_real(t_big_real&&s){
    this->minus=std::move(s.minus);
    this->n=std::move(s.n);
    this->d=std::move(s.d);
  }
public:
  int toInt()const{return toInt(*this);}
public:
  static int toInt(const t_big_real&v)
  {
    QapAssert(!v.d.empty());
    if(v.n.empty())return 0;
    auto r=v.n/v.d;
    if(r.empty())return 0;
    QapAssert(r<1024*16);
    return r.data[0]*(v.minus?-1:+1);
  }
  string toStr()const
  {
    string out;
    out=minus?"-":"+";
    out+=n.toString();
    out+="/";
    out+=d.toString();
    return out;
  }
};

static int test_20140607_v2()
{
  t_big_real a="10";
  t_big_real b="1";
  t_big_real v=a-b;
  int s=v.toInt();
  int n=10;
  for(int i=-n;i<=+n;i++){
    for(int j=-n;j<=+n;j++){
      t_big_real a=IToS(i);
      t_big_real b=IToS(j);
      t_big_real v=a-b;
      if(v.n.data.empty())v.n.data.resize(1);
      int s=v.toInt();
      QapAssert(s==(i-j));
    }
  }
  t_big_real tmp="+10/2";
  t_big_real tmp2="-10/3";
  auto res=(tmp+tmp2);
  string tmp_s=IToS(res.toInt());
  string tmp_s2=res.toStr();
  QapDebugMsg("ok");
  return 0;
}

//static const int eeldgkl=test_20140607_v2();

class vec2s{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(vec2s)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,x,SET,"0",$)\
ADDVAR(string,y,SET,"0",$)\
ADDEND()
//=====+>>>>>vec2s
#include "QapGenStruct.inl"
//<<<<<+=====vec2s
public:
  vec2s(const vec2i&ref):x(IToS(ref.x)),y(IToS(ref.y)){}
  vec2s(const string&x,const string&y):x(x),y(y){}
  void operator+=(const vec2s&ref){
    x=(t_big_real(x)+ref.x).toStr();
    y=(t_big_real(y)+ref.y).toStr();
  }
  vec2s operator*(int k){
    return vec2s((big_number(x)*k).toCode(),(big_number(y)*k).toCode());
  }
  vec2s operator*(const t_big_real&ref)const{
    vec2s out;
    out.x=(t_big_real(x)*ref).toStr();
    out.y=(t_big_real(y)*ref).toStr();
    return out;
  }
  vec2s operator-(const vec2s&a)const{
    vec2s out;
    out.x=(t_big_real(x)-t_big_real(a.x)).toStr();
    out.y=(t_big_real(y)-t_big_real(a.y)).toStr();
    return out;
  }
  vec2s operator+(const vec2s&a)const{
    vec2s out;
    out.x=(t_big_real(x)+t_big_real(a.x)).toStr();
    out.y=(t_big_real(y)+t_big_real(a.y)).toStr();
    return out;
  }
  operator vec2i(){
    vec2i out;
    out.x=toInt(x);
    out.y=toInt(y);
    return out;
  }
public:
  static int toInt(const string&s)
  {
    return t_big_real(s).toInt();
  }/*
  static t_big_real fromStr(const string&s)
  {
    return t_big_real::fromStr(s);
  }*/
};
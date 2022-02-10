#include "StdAfx.h"

#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"

class t_yaru{
public:
  static int&get_static_counter(){static int counter=0;return counter;};
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_number_expr)\
  ADD(t_block_expr)\
  ADD(t_lev0)\
  ADD(t_lev1)\
  ADDEND()

  class i_expr;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_expr_visitor{
  public:
    virtual void Do(t_number_expr*p)=0;
    virtual void Do(t_block_expr*p)=0;
    virtual void Do(t_lev0*p)=0;
    virtual void Do(t_lev1*p)=0;
  public:
    #define ADD(U)typedef t_yaru::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
      #define ADD(U)void Do(U*p){ptr=get(p);}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
  public:
    typedef t_yaru::i_expr i_expr;
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_expr_visitor
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_yaru)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====i_expr
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_number_expr);
        F(t_block_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        static int&counter=get_static_counter();counter++;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_expr_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_raw_number{
  public:
    class t_frac{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac)OWNER(t_raw_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_frac
    #include "QapGenStruct.inl"
    //<<<<<+=====t_frac
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const(".");
        if(!ok)return ok;
        static const string g_static_dip_1=gen_dips("09");
        D+=dev.go_any(value,g_static_dip_1);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_frac)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_number)OWNER(t_yaru)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,val,DEF,$,$)\
  ADDVAR(TAutoPtr<t_frac>,frac,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_number
  #include "QapGenStruct.inl"
  //<<<<<+=====t_raw_number
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const string g_static_dip_0=gen_dips("09");
      M+=dev.go_any(val,g_static_dip_0);
      if(!ok)return ok;
      O+=dev.go_auto(frac);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_number_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number_expr)PARENT(i_expr)OWNER(t_yaru)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_number_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_raw_number>(value);
      if(!ok)return ok;
      return ok;
    }
  public:
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_lev1{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev1)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,oper,SET,'*',$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStruct.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const string g_static_dip_0="*/";
        D+=dev.go_any_char(oper,g_static_dip_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev1)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStruct.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)F(t_oper)F(t_item)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev1)OWNER(t_yaru)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev1
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev1
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  public:
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_lev0{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev0)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,oper,SET,'+',$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStruct.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const string g_static_dip_0="+-";
        D+=dev.go_any_char(oper,g_static_dip_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev0)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev1,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStruct.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_oper)F(t_item)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev0)OWNER(t_yaru)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev1,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev0
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev0
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  public:
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_yaru)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev0,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  public:
    void Use(i_expr_visitor&A){A.Do(this);}
  };
#define DEF_PRO_NESTED(F)F(t_raw_number)F(t_number_expr)F(t_lev1)F(t_lev0)F(t_block_expr)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_yaru)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_yaru
#include "QapGenStruct.inl"
//<<<<<+=====t_yaru
public:
  struct t_dev{
    real result;
  };
  struct t_expr_visitor:public i_expr_visitor{
  public:
    t_dev&dev;
    t_expr_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_number_expr*p){
      real value;
      QapAssert(SToF(p->value,value));
      dev.result=value;
    }
    void Do(t_block_expr*p){
      p->body.Use(*this);
    }
    void Do(t_lev0*p){
      auto&arr=p->arr;
      vector<real> buff;
      p->expr.Use(*this);
      real init_value=dev.result;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        ex.expr.Use(*this);
        buff.push_back(dev.result);
      }
      dev.result=init_value;
      for(int i=0;i<buff.size();i++){
        auto&ex=arr[i];
        char oper=ex.oper.oper;
        if('+'==oper){dev.result+=buff[i];continue;}
        if('-'==oper){dev.result-=buff[i];continue;}
        QapDebugMsg("no way");
      }
    }
    void Do(t_lev1*p){
      auto&arr=p->arr;
      vector<real> buff;
      p->expr->Use(*this);
      real init_value=dev.result;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        ex.expr->Use(*this);
        buff.push_back(dev.result);
      }
      dev.result=init_value;
      for(int i=0;i<buff.size();i++){
        auto&ex=arr[i];
        char oper=ex.oper.oper;
        if('*'==oper){dev.result*=buff[i];continue;}
        if('/'==oper){
          if(buff[i]==0.0)QapDebugMsg("div by zero");
          dev.result/=buff[i];
          continue;
        }
        QapDebugMsg("no way");
      }
    }
  };
};

/*
//list of types:
F(t_yaru)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fyaru%7B%0A%0At%5Fraw%5Fnumber%7B%0A%20%20t%5Ffrac%7Bstring%20value%3B%7Bgo%5
Fconst%28%22%2E%22%29%3Bgo%5Fany%28value%2Cgen%5Fdips%28%2209%22%29%29%3B%7D%7D%
0A%20%20string%20val%3B%0A%20%20TAutoPtr%3Ct%5Ffrac%3E%20frac%3B%0A%20%20%7B%0A%
20%20%20%20M%2B%3Dgo%5Fany%28val%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%20%20
O%2B%3Dgo%5Fauto%28frac%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fnumber%5Fexpr%3D%3Ei%5F
expr%7B%0A%20%20string%20value%3B%0A%20%20%7B%0A%20%20%20%20go%5Fstr%3Ct%5Fraw%5
Fnumber%3E%28value%29%3B%0A%20%20%7D%0A%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20void%
20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28this%29%3B%7D%0A%7D%0A%0At%5Flev1%7
B%0A%20%20t%5Foper%7Bchar%20oper%3D%27%2A%27%3B%7Bgo%5Fany%5Fchar%28oper%2C%22%2
A%2F%22%29%3B%7D%7D%0A%20%20t%5Fitem%7Bt%5Foper%20oper%3BTAutoPtr%3Ci%5Fexpr%3E%
20expr%3B%7Bgo%5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20TAutoPtr%
3Ci%5Fexpr%3E%20expr%3B%0A%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%7B%0A%20%
20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B
%0A%20%20%7D%0A%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20void%20Use%28i%5Fexpr%5Fvisit
or%26A%29%7BA%2EDo%28this%29%3B%7D%0A%7D%0A%0At%5Flev0%7B%0A%20%20t%5Foper%7Bcha
r%20oper%3D%27%2B%27%3B%7Bgo%5Fany%5Fchar%28oper%2C%22%2B%2D%22%29%3B%7D%7D%0A%2
0%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev1%20expr%3B%7Bgo%5Fauto%28oper%29%3Bgo%5
Fauto%28expr%29%3B%7D%7D%0A%20%20t%5Flev1%20expr%3B%0A%20%20vector%3Ct%5Fitem%3E
%20arr%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20
O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%7D%0A%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20v
oid%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28this%29%3B%7D%0A%7D%0A%0At%5Fbl
ock%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20t%5Flev0%20body%3B%0A%20%20%7B%0A%20%20%20%2
0go%5Fconst%28%22%28%22%29%3B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%2
0go%5Fconst%28%22%29%22%29%3B%0A%20%20%7D%0A%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20
void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28this%29%3B%7D%0A%7D%0A%0A%7D
*/

class t_easy_calc{
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_number_expr)\
  ADD(t_block_expr)\
  ADD(t_oper_expr)\
  ADDEND()

  class i_expr;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_expr_visitor{
  public:
    virtual void Do(t_number_expr*p)=0;
    virtual void Do(t_block_expr*p)=0;
    virtual void Do(t_oper_expr*p)=0;
  public:
    #define ADD(U)typedef t_easy_calc::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    typedef t_yaru::i_expr i_expr;
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_expr_visitor
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_easy_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====i_expr
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_number_expr);
        F(t_block_expr);
        F(t_oper_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_expr_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_number_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number_expr)PARENT(i_expr)OWNER(t_easy_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_number_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_yaru::t_raw_number>(value);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_easy_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_oper_expr:public i_expr{
  public:
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_oper_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,oper,SET,'+',$)\
    ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStruct.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const string g_static_dip_0="+-*/";
        D+=dev.go_any_char(oper,g_static_dip_0);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)F(t_item)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_expr)PARENT(i_expr)OWNER(t_easy_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,first,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_oper_expr
  public:
    bool go(i_dev&dev){
      QapDebugMsg("this code lead to stackoverflow.");
      QapDebugMsg("first.get<t_oper_expr>()->first.get<...>()->first...");
      QapDebugMsg("no way");
      return false;
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(first);
      if(!ok)return ok;
      M+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_expr_visitor&A){A.Do(this);}
  };
#define DEF_PRO_NESTED(F)F(t_number_expr)F(t_block_expr)F(t_oper_expr)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_easy_calc)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_easy_calc
#include "QapGenStruct.inl"
//<<<<<+=====t_easy_calc
public:
  struct t_dev{
  public:
    typedef t_easy_calc OwnerClass;
  public:
    IEnvRTTI&Env;
    vector<TRawPtr> stack;
    TRawPtr ptr;
    void push(){
      stack.push_back(TRawPtr());
      auto&back=stack.back();
      back.pType=ptr.pType;
      back.pValue=ptr.pValue;
    }
    void pop(...){
      ptr=std::move(stack.back());
      stack.pop_back();
    }
    template<class TYPE>
    TYPE*get(){
      return (TYPE*)ptr.pValue;
    }
  public:
    struct t_oper{};
    struct t_oper_first{};
    struct t_oper_item{int id;};
    struct t_number{};
    struct t_block{};
  public:
    void push(t_oper&v){
      auto&value=*get<TAutoPtr<i_expr>>();
      value.build<OwnerClass::t_oper_expr>(Env);
      ptr.set(value);
      push();
    }
    void push(t_oper_first&v){
      auto&value=*get<OwnerClass::t_oper_expr>();
      ptr.set(Env,value.first);
      push();
    }
    void push(t_oper_item&v){
      auto&value=*get<OwnerClass::t_oper_expr>();
      ptr.set(Env,value.arr[v.id].expr);
      push();
    }
    void push(t_number&v){
      auto&value=*get<TAutoPtr<i_expr>>();
      value.build<OwnerClass::t_number_expr>(Env);
      ptr.set(value);
      push();
    }
    void push(t_block&v){
      auto&value=*get<TAutoPtr<i_expr>>();
      value.build<OwnerClass::t_block_expr>(Env);
      ptr.set(value);
      push();
    }
  };
  struct t_expr_visitor:public t_yaru::i_expr_visitor{
  public:
    typedef t_easy_calc OwnerClass;
  public:
    t_dev&dev;
    t_expr_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_number_expr*p){
      real value;
      QapAssert(SToF(p->value,value));
      //dev.result=value;
    }
    void Do(t_block_expr*p){
      p->body.Use(*this);
    }
    void Do(t_lev0*p){
      t_dev::t_oper oper;
      dev.push(oper);
      auto&value=*dev.get<OwnerClass::t_oper_expr>();
      {
        t_dev::t_oper_first first;
        dev.push(first);
        p->expr.Use(*this);
        dev.pop(first);
      }
      auto&arr=p->arr;
      value.arr.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        value.arr[i].oper=ex.oper.oper;
        t_dev::t_oper_item item={i};
        dev.push(item);
        ex.expr.Use(*this);
        dev.pop(item);
      }
      dev.pop(oper);
    }
    void Do(t_lev1*p){
      t_dev::t_oper oper;
      dev.push(oper);
      auto&value=*dev.get<OwnerClass::t_oper_expr>();
      {
        t_dev::t_oper_first first;
        dev.push(first);
        p->Use(*this);
        dev.pop(first);
      }
      auto&arr=p->arr;
      value.arr.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        value.arr[i].oper=ex.oper.oper;
        t_dev::t_oper_item item={i};
        dev.push(item);
        ex.expr->Use(*this);
        dev.pop(item);
      }
      dev.pop(oper);
    }
  };
  void clone(IEnvRTTI&Env,TAutoPtr<i_expr>&out,TAutoPtr<t_yaru::i_expr>&inp){
    t_dev dev={Env};
    dev.ptr.set(out);
    t_expr_visitor V(dev);
    if(!inp)return;
    inp->Use(V);
    auto*p=inp.get();
    //if p is t_lev0
    {
      t_yaru::t_lev0*p;
      if(p->arr.empty()&&p->expr.arr.empty()){
        //t_number_expr or t_block_expr;
        //if p->expr.expr is t_number
      }else;// t_oper_expr;

    }
  }
};

/*
//list of types:
F(t_easy_calc)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Feasy%5Fcalc%7B%0A%0At%5Fraw%5Fnumber%7B%0A%20%20t%5Ffrac%7Bstring%20value%3B
%7Bgo%5Fconst%28%22%2E%22%29%3Bgo%5Fany%28value%2Cgen%5Fdips%28%2209%22%29%29%3B
%7D%7D%0A%20%20string%20val%3B%0A%20%20TAutoPtr%3Ct%5Ffrac%3E%20frac%3B%0A%20%20
%7B%0A%20%20%20%20M%2B%3Dgo%5Fany%28val%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%2
0%20%20O%2B%3Dgo%5Fauto%28frac%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fnumber%5Fexpr%3D
%3Ei%5Fexpr%7B%0A%20%20string%20value%3B%0A%20%20%7B%0A%20%20%20%20go%5Fstr%3Ct%
5Fraw%5Fnumber%3E%28value%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fblock%5Fexpr%3D%3Ei%5
Fexpr%7B%0A%20%20TAutoPtr%3Ci%5Fexpr%3E%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5
Fconst%28%22%28%22%29%3B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20go%5
Fconst%28%22%29%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Foper%5Fexpr%3D%3Ei%5Fexpr%7B
%0A%20%20t%5Fitem%7B%0A%20%20%20%20char%20oper%3D%27%2B%27%3B%0A%20%20%20%20TAut
oPtr%3Ci%5Fexpr%3E%20expr%3B%0A%20%20%20%20%7Bgo%5Fany%5Fchar%28oper%2C%22%2B%2D
%2A%2F%22%29%3Bgo%5Fauto%28expr%29%3B%7D%0A%20%20%7D%0A%20%20TAutoPtr%3Ci%5Fexpr
%3E%20first%3B%0A%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20M
%2B%3Dgo%5Fauto%28first%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%2
0%7D%0A%7D%0A%0A%7D
*/

extern string test20131204_chat_json(IEnvRTTI&Env,TRawPtr&ptr);

class t_yaru2013:public IShellCommand{
public:
#define DEF_PRO_NESTED(F)F(Impl)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_yaru2013)PARENT(IShellCommand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_yaru2013
#include "QapGenStruct.inl"
//<<<<<+=====t_yaru2013
public:
  class Impl{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Impl)OWNER(t_yaru2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,expr,SET,"/",$)\
  ADDVAR(string,flag,DEF,$,$)\
  ADDEND()
  //=====+>>>>>Impl
  #include "QapGenStruct.inl"
  //<<<<<+=====Impl
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv){
      t_yaru::get_static_counter()=0;
      TAutoPtr<t_yaru::t_lev0> ug;
      load_obj(Env,ug,expr);
      if(flag=="eval")if(ug){
        t_yaru::t_dev dev;
        t_yaru::t_expr_visitor V(dev);
        ug->Use(V);
        return "ok:["+cur_date_str()+"]\nresult = "+FToS(dev.result)+"\ncost = "+IToS(t_yaru::get_static_counter());
      }
      if(flag=="json")if(ug){
        TRawPtr ptr;
        ptr.set(ug);
        return "ok:["+cur_date_str()+"]\n"+test20131204_chat_json(Env,ptr);
      }
      return "ok:["+cur_date_str()+"]\n"+QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug));
    }
  };
public:
  string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
  {
    Impl tmp;
    auto c=Args.size();
    if(c>1)tmp.expr=Args[1];
    if(c>2)tmp.flag=Args[2];
    return tmp.eval(Env,ShellEnv);
  }
};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)\
        F(t_yaru)F(t_yaru2013)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){}
  };
  ThisCompileUnit ThisUnit;
}
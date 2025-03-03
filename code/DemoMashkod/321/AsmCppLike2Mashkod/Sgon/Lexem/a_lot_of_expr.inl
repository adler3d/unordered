//=============================================================================
class t_calctest{
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_number_expr)\
  ADD(t_block_expr)\
  ADD(t_lev05)\
  ADD(t_lev06)\
  ADD(t_lev07)\
  ADD(t_lev08)\
  ADD(t_lev09)\
  ADD(t_lev10)\
  ADD(t_lev11)\
  ADD(t_lev12)\
  ADD(t_lev13)\
  ADD(t_lev14)\
  ADD(t_lev15)\
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
    virtual void Do(t_lev05*p)=0;
    virtual void Do(t_lev06*p)=0;
    virtual void Do(t_lev07*p)=0;
    virtual void Do(t_lev08*p)=0;
    virtual void Do(t_lev09*p)=0;
    virtual void Do(t_lev10*p)=0;
    virtual void Do(t_lev11*p)=0;
    virtual void Do(t_lev12*p)=0;
    virtual void Do(t_lev13*p)=0;
    virtual void Do(t_lev14*p)=0;
    virtual void Do(t_lev15*p)=0;
  public:
    #define ADD(U)typedef t_calctest::U U;
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
    typedef t_calctest::i_expr i_expr;
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_expr_visitor
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_calctest)
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
        F(t_block_expr);
        F(t_number_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_expr_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_lev05{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("*,/,%",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,TAutoPtr<i_expr>,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TAutoPtr<i_expr>,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev05
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev05
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
  class t_lev06{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("+,-",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev05,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev05,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev06
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev06
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
  class t_lev07{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev07)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("<<,>>",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev07)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev06,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev06,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev07
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev07
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
  class t_lev08{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev08)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("<,<=,>,>=",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev08)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev07,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev07,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev08
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev08
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
  class t_lev09{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("==,!=",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev08,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev09)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev08,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev09
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev09
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
  class t_lev10{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("&",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev09,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev10)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev09,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev10
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev10
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
  class t_lev11{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("^",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev10,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev11)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev10,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev11
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev11
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
  class t_lev12{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("|",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev11,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev12)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev11,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev12
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev12
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
  class t_lev13{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("&&",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev12,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev13)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev12,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev13
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev13
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
  class t_lev14{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("||",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev13,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev14)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev13,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev14
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev14
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
  class t_lev15{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev15)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
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
        D+=dev.go_any_str_from_vec(value,split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=",","));
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev15)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev14,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev15)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev14,expr,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev15
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev15
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev15,body,DEF,$,$)\
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
  class t_number_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number_expr)PARENT(i_expr)OWNER(t_calctest)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
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
      D+=dev.go_str<t_number>(value);
      if(!ok)return ok;
      return ok;
    }
  public:
    void Use(i_expr_visitor&A){A.Do(this);}
  };
public:
#define DEF_PRO_NESTED(F)\
  F(t_lev05)F(t_lev06)F(t_lev07)F(t_lev08)F(t_lev09)F(t_lev10)F(t_lev11)F(t_lev12)\
  F(t_lev13)F(t_lev14)F(t_lev15)F(t_block_expr)F(t_number_expr)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_calctest)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_calctest
#include "QapGenStruct.inl"
//<<<<<+=====t_calctest
public:
  struct t_expr_visitor:public t_calctest::i_expr_visitor{
  public:
    typedef t_easy_calc t_out;
    typedef t_out::t_dev t_dev;
  public:
    t_dev&dev;
    t_expr_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_number_expr*p){
      auto&ptr=dev.get_ptr();
      auto*pValue=ptr.build<t_out::t_number_expr>(dev.Env);
      pValue->value=p->value;
    }
    void Do(t_block_expr*p){
      auto&ptr=dev.get_ptr();
      auto*pValue=ptr.build<t_out::t_block_expr>(dev.Env);
      t_dev::t_block block;
      dev.push(block);
      p->body.Use(*this);
      dev.pop(block);
    }
  public:
    template<class TYPE>
    void exprUse(TYPE&expr){
      expr.Use(*this);
    }
    //template<class TYPE>
    void exprUse(TAutoPtr<t_calctest::i_expr>&expr){
      expr->Use(*this);
    }
  public:
    template<class TYPE>
    void DoLevel(TYPE*p)
    {
      if(p->arr.empty())
      {
        exprUse(p->expr);
        return;
      }
      auto&ptr=dev.get_ptr();
      auto*pValue=ptr.build<t_out::t_oper_expr>(dev.Env);
      {
        t_dev::t_oper_first first;
        dev.push(first);
        exprUse(p->expr);
        dev.pop(first);
      }
      auto&arr=p->arr;
      pValue->arr.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        pValue->arr[i].oper=ex.oper.value;
        t_dev::t_oper_item item={i};
        dev.push(item);
        exprUse(ex.expr);
        dev.pop(item);
      }
    }
  public:
    void Do(t_lev05*p){DoLevel(p);}
    void Do(t_lev06*p){DoLevel(p);}
    void Do(t_lev07*p){DoLevel(p);}
    void Do(t_lev08*p){DoLevel(p);}
    void Do(t_lev09*p){DoLevel(p);}
    void Do(t_lev10*p){DoLevel(p);}
    void Do(t_lev11*p){DoLevel(p);}
    void Do(t_lev12*p){DoLevel(p);}
    void Do(t_lev13*p){DoLevel(p);}
    void Do(t_lev14*p){DoLevel(p);}
    void Do(t_lev15*p){DoLevel(p);}
  };
  static void clone(IEnvRTTI&Env,TAutoPtr<t_easy_calc::i_expr>&out,TAutoPtr<t_calctest::i_expr>&inp){
    t_easy_calc::t_dev dev={Env};
    dev.push();
    dev.ptr.set(Env,out);
    t_expr_visitor V(dev);
    if(!inp)return;
    inp->Use(V);
  }
};

/*
//list of types:
F(t_calctest)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fcalctest%7B%0A%20%20t%5Flev05%7B%0A%20%20%20%20t%5Foper%7Bstring%20value%3B%
7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%2A%2C%2F%2C%25%22%2C%22%2C%2
2%29%29%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3BTAutoPtr%3Ci%5Fexpr%
3E%20expr%3B%7Bgo%5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20
TAutoPtr%3Ci%5Fexpr%3E%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%
20%20%20%20%7BM%2B%3Dgo%5Fauto%28expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20
%20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A
%29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev06%7B%0A%20%
20%20%20t%5Foper%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Cspl
it%28%22%2B%2C%2D%22%2C%22%2C%22%29%29%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Fope
r%20oper%3Bt%5Flev05%20expr%3B%7Bgo%5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D
%7D%0A%20%20%20%20t%5Flev05%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3
B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%28expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%
0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisito
r%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev07%7B%0
A%20%20%20%20t%5Foper%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%
2Csplit%28%22%3C%3C%2C%3E%3E%22%2C%22%2C%22%29%29%3B%7D%7D%0A%20%20%20%20t%5Fite
m%7Bt%5Foper%20oper%3Bt%5Flev06%20expr%3B%7Bgo%5Fauto%28oper%29%3Bgo%5Fauto%28ex
pr%29%3B%7D%7D%0A%20%20%20%20t%5Flev06%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem
%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%28expr%29%3BO%2B%3Dgo%5Fauto%28ar
r%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%20%20void%20Use%28i%5Fex
pr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%0A%20%20%7D%0A%20%20t%5
Flev08%7B%0A%20%20%20%20t%5Foper%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fv
ec%28value%2Csplit%28%22%3C%2C%3C%3D%2C%3E%2C%3E%3D%22%2C%22%2C%22%29%29%3B%7D%7
D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev07%20expr%3B%7Bgo%5Fauto%28o
per%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev07%20expr%3B%0A%20%20
%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%28expr%29%
3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%2
0%20void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%
0A%20%20%7D%0A%20%20t%5Flev09%7B%0A%20%20%20%20t%5Foper%7Bstring%20value%3B%7Bgo
%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3D%3D%2C%21%3D%22%2C%22%2C%22%29
%29%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev08%20expr%3B%7Bgo
%5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev08%20expr%
3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto
%28expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A
%0A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2
F%29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev10%7B%0A%20%20%20%20t%5Foper%7Bstring%20va
lue%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%26%22%2C%22%2C%22%29%
29%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev09%20expr%3B%7Bgo%
5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev09%20expr%3
B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%
28expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%
0A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F
%29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev11%7B%0A%20%20%20%20t%5Foper%7Bstring%20val
ue%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%5E%22%2C%22%2C%22%29%2
9%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev10%20expr%3B%7Bgo%5
Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev10%20expr%3B
%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%2
8expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0
A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%
29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev12%7B%0A%20%20%20%20t%5Foper%7Bstring%20valu
e%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%22%2C%22%2C%22%29%29
%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev11%20expr%3B%7Bgo%5F
auto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev11%20expr%3B%
0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%28
expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0A
%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%2
9%3B%7D%0A%20%20%7D%0A%20%20t%5Flev13%7B%0A%20%20%20%20t%5Foper%7Bstring%20value
%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%26%26%22%2C%22%2C%22%29%
29%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev12%20expr%3B%7Bgo%
5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev12%20expr%3
B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%
28expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%
0A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F
%29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev14%7B%0A%20%20%20%20t%5Foper%7Bstring%20val
ue%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%7C%22%2C%22%2C%22%2
9%29%3B%7D%7D%0A%20%20%20%20t%5Fitem%7Bt%5Foper%20oper%3Bt%5Flev13%20expr%3B%7Bg
o%5Fauto%28oper%29%3Bgo%5Fauto%28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev13%20expr
%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Faut
o%28expr%29%3BO%2B%3Dgo%5Fauto%28arr%29%3B%7D%0A%20%20%7D%0A%20%20t%5Flev15%7B%0
A%20%20%20%20t%5Foper%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%
2Csplit%28%22%3D%2C%2B%3D%2C%2D%3D%2C%2A%3D%2C%2F%3D%2C%25%3D%2C%7C%3D%2C%26%3D%
2C%5E%3D%2C%3C%3C%3D%2C%3E%3E%3D%22%2C%22%2C%22%29%29%3B%7D%7D%0A%20%20%20%20t%5
Fitem%7Bt%5Foper%20oper%3Bt%5Flev14%20expr%3B%7Bgo%5Fauto%28oper%29%3Bgo%5Fauto%
28expr%29%3B%7D%7D%0A%20%20%20%20t%5Flev14%20expr%3B%0A%20%20%20%20vector%3Ct%5F
item%3E%20arr%3B%0A%20%20%20%20%7BM%2B%3Dgo%5Fauto%28expr%29%3BO%2B%3Dgo%5Fauto%
28arr%29%3B%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%20%20void%20Use%28i%
5Fexpr%5Fvisitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%0A%20%20%7D%0A%20%2
0t%5Fblock%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20%20%20t%5Flev15%20body%3B%0A%20%20%20
%20%7B%0A%20%20%20%20%20%20go%5Fconst%28%22%28%22%29%3B%0A%20%20%20%20%20%20go%5
Fauto%28body%29%3B%0A%20%20%20%20%20%20go%5Fconst%28%22%29%22%29%3B%0A%20%20%20%
20%7D%0A%20%20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%20%20void%20Use%28i%5Fexpr%5F
visitor%26A%29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%0A%20%20%7D%0A%20%20t%5Fnumb
er%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20%20%20string%20value%3B%0A%20%20%20%20%7B%0A%
20%20%20%20%20%20go%5Fstr%3Ct%5Fnumber%3E%28value%29%3B%0A%20%20%20%20%7D%0A%20%
20%20%20%5B%3A%3A%5Dpublic%3A%0A%20%20%20%20void%20Use%28i%5Fexpr%5Fvisitor%26A%
29%7BA%2EDo%28%2F%2Athis%2A%2F%29%3B%7D%0A%20%20%7D%0A%7D
*/

/*
//real source data:
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
04:"no impl"
//real source data_lexem:
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
  t_list{
    vector<t_rec> arr;{go_auto(arr);}
  }
}
//real source code_gen:
string gen_metalex(const string&cur,const string&next,const string&code){
  string v=(
    "t_lev"+cur+"{\n"
    "  t_oper{string value;{go_any_str_from_vec(value,split("+code+",\",\"));}}\n"
    "  t_item{t_oper oper;t_lev"+next+" expr;{go_auto(oper);go_auto(expr);}}\n"
    "  t_lev"+next+" expr;\n"
    "  vector<t_item> arr;\n"
    "  {M+=go_auto(expr);O+=go_auto(arr);}\n"
    "}"
  );
  return v;
}
void gen_all_metalexpack(IEnvRTTI&Env){
  string data=file_get_contents("metalexpack.h");
  data=drop_cr(data);
  t_matalexpack::t_list root;
  load_obj(Env,root,data);
  string answer=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(root));
  auto&arr=root.arr;
  vector<string> out;
  for(int i=arr.size()-2;i>=0;i--){
    auto&a=arr[i+0];
    auto&b=arr[i+1];
    string num=a.bef.body;
    string code=a.aft.get_code();
    out.push_back(gen_metalex(num,b.bef.body,code));
  }
  string out_buff=join(out,"\n");
  int gg=1;
}
*/
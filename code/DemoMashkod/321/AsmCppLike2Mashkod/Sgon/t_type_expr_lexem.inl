//time = 17.08 ms.

class t_type_expr{
public:
  class t_first_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_first_scope)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_first_scope
  #include "QapGenStruct.inl"
  //<<<<<+=====t_first_scope
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("::");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_const_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const_with_sep)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_const_with_sep
  #include "QapGenStruct.inl"
  //<<<<<+=====t_const_with_sep
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("const");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_type_with_sep{
  public:
    //===>>===i_param_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_type_param)\
    ADD(t_num_param)\
    ADDEND()
  
    class i_param;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_param_visitor{
    public:
      typedef t_type_with_sep::i_param i_param;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_type_with_sep::U U;
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
      static TYPE*UberCast(i_param*p){
        if(!p)return nullptr;Is<TYPE,i_param_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_param_visitor
    //class t_visitor:public t_type_with_sep::i_param_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_type_param*p){}
    //  void Do(t_num_param*p){}
    //};
  public:
    class i_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_param)OWNER(t_type_with_sep)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_param
    #include "QapGenStruct.inl"
    //<<<<<+=====i_param
    public:
      typedef i_param_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_type_param);
          F(t_num_param);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_type_param:public i_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_param)PARENT(i_param)OWNER(t_type_with_sep)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
    ADDVAR(TAutoPtr<t_type_expr>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_param
    #include "QapGenStruct.inl"
    //<<<<<+=====t_type_param
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(cv);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_num_param:public i_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_param)PARENT(i_param)OWNER(t_type_with_sep)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_num_param
    #include "QapGenStruct.inl"
    //<<<<<+=====t_num_param
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
        D+=dev.go_any(body,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_params{
    public:
      class t_type_expr_with_sep{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr_with_sep)OWNER(t_params)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep_bef,DEF,$,$)\
      ADDVAR(TAutoPtr<i_param>,param,DEF,$,$)\
      ADDVAR(t_sep,sep_aft,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_type_expr_with_sep
      #include "QapGenStruct.inl"
      //<<<<<+=====t_type_expr_with_sep
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep_bef);
          if(!ok)return ok;
          M+=dev.go_auto(param);
          if(!ok)return ok;
          O+=dev.go_auto(sep_aft);
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_type_expr_with_sep)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_type_with_sep)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(vector<t_type_expr_with_sep>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_params
    #include "QapGenStruct.inl"
    //<<<<<+=====t_params
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_const("<");
        if(!ok)return ok;
        O+=dev.go_vec(arr,",");
        if(!ok)return ok;
        M+=dev.go_const(">");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_type_param)\
    F(t_num_param )\
    F(t_params    )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_with_sep)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(TAutoPtr<t_params>,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_with_sep
  #include "QapGenStruct.inl"
  //<<<<<+=====t_type_with_sep
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(params);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_type_with_sep::TYPE TYPE;
    //  F(i_param);
    //  F(t_type_param);
    //  F(t_num_param);
    //  F(t_params);
    //  #undef F
    //public:
    //  void Do(t_type_param&ref){}
    //  void Do(t_num_param&ref){}
    //  void Do(t_params&ref){}
    //};
  };
  class t_scope_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope_with_sep)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope_with_sep
  #include "QapGenStruct.inl"
  //<<<<<+=====t_scope_with_sep
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_scope
  #include "QapGenStruct.inl"
  //<<<<<+=====t_scope
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_ptr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(cv);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("*");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ref{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ref)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,ref,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ref
  #include "QapGenStruct.inl"
  //<<<<<+=====t_ref
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(cv);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      static const auto g_static_var_2=QapStrFinder::fromArr(split("&&,&",","));
      M+=dev.go_any_str_from_vec(ref,g_static_var_2);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_scopes{
  public:
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_scopes)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_scope_with_sep,sws,DEF,$,$)\
    ADDVAR(t_type_with_sep,body,DEF,$,$)\
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
        D+=dev.go_auto(sws);
        if(!ok)return ok;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scopes)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_with_sep,first,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scopes
  #include "QapGenStruct.inl"
  //<<<<<+=====t_scopes
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(first);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_main_test{
  public:
    class t_keyword{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_keyword)OWNER(t_main_test)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,keyword,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_keyword
    #include "QapGenStruct.inl"
    //<<<<<+=====t_keyword
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("explicit,constexpr,virtual,const,static",","));
        M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_func_stat{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_stat)OWNER(t_main_test)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(TAutoPtr<t_type_expr>,type,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
    ADDVAR(string,func_name,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_func_stat
    #include "QapGenStruct.inl"
    //<<<<<+=====t_func_stat
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(keywords);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(cv);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(func_name);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        M+=dev.go_const("();");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_line{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)OWNER(t_main_test)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(t_func_stat,func_stat,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_line
    #include "QapGenStruct.inl"
    //<<<<<+=====t_line
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_auto(func_stat);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_keyword  )\
    F(t_func_stat)\
    F(t_line     )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_main_test)OWNER(t_type_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_line>,lines,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_main_test
  #include "QapGenStruct.inl"
  //<<<<<+=====t_main_test
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(lines);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_main_test::TYPE TYPE;
    //  F(t_keyword);
    //  F(t_func_stat);
    //  F(t_line);
    //  #undef F
    //public:
    //  void Do(t_keyword&ref){}
    //  void Do(t_func_stat&ref){}
    //  void Do(t_line&ref){}
    //};
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_first_scope   )\
  F(t_const_with_sep)\
  F(t_type_with_sep )\
  F(t_scope_with_sep)\
  F(t_scope         )\
  F(t_ptr           )\
  F(t_ref           )\
  F(t_scopes        )\
  F(t_main_test     )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_first_scope>,first,DEF,$,$)\
ADDVAR(t_scopes,scopes,DEF,$,$)\
ADDVAR(vector<t_ptr>,ptrs,DEF,$,$)\
ADDVAR(t_ref,ref,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_expr
#include "QapGenStruct.inl"
//<<<<<+=====t_type_expr
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_auto(first);
    if(!ok)return ok;
    M+=dev.go_auto(scopes);
    if(!ok)return ok;
    O+=dev.go_auto(ptrs);
    if(!ok)return ok;
    O+=dev.go_auto(ref);
    if(!ok)return ok;
    return ok;
  }
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_type_expr::TYPE TYPE;
  //  F(t_first_scope);
  //  F(t_const_with_sep);
  //  F(t_type_with_sep);
  //  F(t_scope_with_sep);
  //  F(t_scope);
  //  F(t_ptr);
  //  F(t_ref);
  //  F(t_scopes);
  //  F(t_main_test);
  //  #undef F
  //public:
  //  void Do(t_first_scope&ref){}
  //  void Do(t_const_with_sep&ref){}
  //  void Do(t_type_with_sep&ref){}
  //  void Do(t_scope_with_sep&ref){}
  //  void Do(t_scope&ref){}
  //  void Do(t_ptr&ref){}
  //  void Do(t_ref&ref){}
  //  void Do(t_scopes&ref){}
  //  void Do(t_main_test&ref){}
  //};
};

/*
//list of types:
F(t_type_expr)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Ftype%5Fexpr%7B%0D%0A%20%20t%5Ffirst%5Fscope%7B%0D%0A%20%20%20%20string%20bod
y%3B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20
%20M%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28sep%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fconst%5Fwith%5F
sep%7Bt%5Fsep%20sep%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fconst%28%22cons
t%22%29%3B%7D%7D%0D%0A%20%20t%5Ftype%5Fwith%5Fsep%7B%0D%0A%20%20%20%20t%5Ftype%5
Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fse
p%3E%20cv%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ftype%5Fexpr%3E%20body%3B%0D%0
A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%
0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fnum%5Fparam%3D%3Ei%5Fparam%7Bstr
ing%20body%3B%7Bgo%5Fany%28body%2Cgen%5Fdips%28%2209%22%29%29%3B%7D%7D%0D%0A%20%
20%20%20t%5Fparams%7B%0D%0A%20%20%20%20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%7Bt%5F
sep%20sep%5Fbef%3BTAutoPtr%3Ci%5Fparam%3E%20param%3Bt%5Fsep%20sep%5Faft%3B%7BO%2
B%3Dgo%5Fauto%28sep%5Fbef%29%3BM%2B%3Dgo%5Fauto%28param%29%3BO%2B%3Dgo%5Fauto%28
sep%5Faft%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%
20%20vector%3Ct%5Ftype%5Fexpr%5Fwith%5Fsep%3E%20arr%3B%0D%0A%20%20%20%20%20%20%7
B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20
%20%20%20M%2B%3Dgo%5Fconst%28%22%3C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3
Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst
%28%22%3E%22%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%2
0%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20TAutoPtr
%3Ct%5Fparams%3E%20params%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28nam
e%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20
%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fscope%5Fwith%5Fsep%7Bt%5Fsep%20sep%3B%7BO%2B%3
Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%7D%7D%0D%0A%20%20t%
5Fscope%7B%7Bgo%5Fconst%28%22%3A%3A%22%29%3B%7D%7D%0D%0A%20%20t%5Fptr%7B%0D%0A%2
0%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20%20%20%20t%5Fsep%
20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B
%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B
%3Dgo%5Fconst%28%22%2A%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t
%5Fref%7B%0D%0A%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20
%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20string%20ref%3B%0D%0A%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20O%2B%3
Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec
%28ref%2Csplit%28%22%26%26%2C%26%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%7D%0D
%0A%20%20%7D%0D%0A%20%20t%5Fscopes%7B%0D%0A%20%20%20%20t%5Fitem%7Bt%5Fscope%5Fwi
th%5Fsep%20sws%3Bt%5Ftype%5Fwith%5Fsep%20body%3B%7Bgo%5Fauto%28sws%29%3Bgo%5Faut
o%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Ftype%5Fwith%5Fsep%20first%3B%0D%0A%20%
20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fauto%28first%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%2
9%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fmain%5Ftest%7B%0D%0A%20%
20%20%20t%5Fkeyword%7B%0D%0A%20%20%20%20%20%20string%20keyword%3B%0D%0A%20%20%20
%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%
20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28keyword%2Csplit%28%22explicit%2Cconstexpr
%2Cvirtual%2Cconst%2Cstatic%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%2
0O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D
%0A%20%20%20%20t%5Ffunc%5Fstat%7B%0D%0A%20%20%20%20%20%20vector%3Ct%5Fkeyword%3E
%20keywords%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20T
AutoPtr%3Ct%5Ftype%5Fexpr%3E%20type%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%
0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20%20%
20%20%20%20string%20func%5Fname%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0
A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28keywords%
29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%
28func%5Fname%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0
D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%29%3B%22%29%3B%0D%0A%20%2
0%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fline%7B%0D%0A%20%20%2
0%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20t%5Ffunc%5Fstat%20func%5Fstat%
3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28se
p%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28func%5Fstat%29%3B%0D%0A%
20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20vector%3Ct%5Fline%3E%
20lines%3B%0D%0A%20%20%20%20%7Bgo%5Fauto%28lines%29%3B%7D%0D%0A%20%20%7D%0D%0A%2
0%20TAutoPtr%3Ct%5Ffirst%5Fscope%3E%20first%3B%0D%0A%20%20t%5Fscopes%20scopes%3B
%0D%0A%20%20vector%3Ct%5Fptr%3E%20ptrs%3B%0D%0A%20%20t%5Fref%20ref%3B%0D%0A%20%2
0%7B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28first%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%
5Fauto%28scopes%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28ptrs%29%3B%0D%0A%20%20
%20%20O%2B%3Dgo%5Fauto%28ref%29%3B%0D%0A%20%20%7D%0D%0A%7D
*/
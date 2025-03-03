//time = 5398.18 ms.
class t_simple_stat_lex{
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_int_expr)\
  ADD(t_char_expr)\
  ADD(t_bool_expr)\
  ADD(t_string_expr)\
  ADD(t_real_expr)\
  ADD(t_var_expr)\
  ADD(t_block_expr)\
  ADD(t_call_expr)\
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
    typedef t_simple_stat_lex::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_simple_stat_lex::U U;
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
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_expr_visitor
  //class t_visitor:public t_simple_stat_lex::i_expr_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_int_expr*p){}
  //  void Do(t_char_expr*p){}
  //  void Do(t_bool_expr*p){}
  //  void Do(t_string_expr*p){}
  //  void Do(t_real_expr*p){}
  //  void Do(t_var_expr*p){}
  //  void Do(t_block_expr*p){}
  //  void Do(t_call_expr*p){}
  //};
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====i_expr
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_int_expr);
        F(t_char_expr);
        F(t_bool_expr);
        F(t_string_expr);
        F(t_real_expr);
        F(t_var_expr);
        F(t_block_expr);
        F(t_call_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
public:
  //===>>===i_stat_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_var_stat)\
  ADD(t_sep_stat)\
  ADD(t_block_stat)\
  ADD(t_expr_stat)\
  ADD(t_set_oper_stat)\
  ADD(t_func_stat)\
  ADD(t_oper_stat)\
  ADD(t_ret_stat)\
  ADD(t_null_stat)\
  ADD(t_postfix_oper_stat)\
  ADD(t_break_stat)\
  ADD(t_continue_stat)\
  ADD(t_for_stat)\
  ADD(t_if_stat)\
  ADD(t_struct_stat)\
  ADD(t_template_stat)\
  ADDEND()

  class i_stat;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_stat_visitor{
  public:
    typedef t_simple_stat_lex::i_stat i_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_simple_stat_lex::U U;
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
    static TYPE*UberCast(i_stat*p){
      if(!p)return nullptr;Is<TYPE,i_stat_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_stat_visitor
  //class t_visitor:public t_simple_stat_lex::i_stat_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_var_stat*p){}
  //  void Do(t_sep_stat*p){}
  //  void Do(t_block_stat*p){}
  //  void Do(t_expr_stat*p){}
  //  void Do(t_set_oper_stat*p){}
  //  void Do(t_func_stat*p){}
  //  void Do(t_oper_stat*p){}
  //  void Do(t_ret_stat*p){}
  //  void Do(t_null_stat*p){}
  //  void Do(t_postfix_oper_stat*p){}
  //  void Do(t_break_stat*p){}
  //  void Do(t_continue_stat*p){}
  //  void Do(t_for_stat*p){}
  //  void Do(t_if_stat*p){}
  //  void Do(t_struct_stat*p){}
  //  void Do(t_template_stat*p){}
  //};
public:
  class i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====i_stat
  public:
    typedef i_stat_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_var_stat);
        F(t_sep_stat);
        F(t_block_stat);
        F(t_expr_stat);
        F(t_set_oper_stat);
        F(t_func_stat);
        F(t_oper_stat);
        F(t_ret_stat);
        F(t_null_stat);
        F(t_postfix_oper_stat);
        F(t_break_stat);
        F(t_continue_stat);
        F(t_for_stat);
        F(t_if_stat);
        F(t_struct_stat);
        F(t_template_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,oper,DEF,$,$)\
  ADDVAR(1,TAutoPtr<i_expr>,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev03
  #include "QapGenStruct.inl"
  //<<<<<+=====t_lev03
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=split("+,-,!,~",",");
      O+=dev.go_any_str_from_vec(oper,g_static_var_0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
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
        static const auto g_static_var_0=split("*,/,%",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper,oper,DEF,$,$)\
    ADDVAR(1,t_lev03,expr,DEF,$,$)\
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev03,expr,DEF,$,$)\
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
        static const auto g_static_var_0=split("+,-",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("<<,>>",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("<,<=,>,>=",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("==,!=",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev09)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("&",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev10)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("^",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev11)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("|",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev12)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("&&",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev13)OWNER(t_simple_stat_lex)
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
        static const auto g_static_var_0=split("||",",");
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev14)OWNER(t_simple_stat_lex)
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
  };
  class t_string{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string
  #include "QapGenStruct.inl"
  //<<<<<+=====t_string
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("\"");
      if(!ok)return ok;
      O+=dev.go_str<vector<TAutoPtr<i_str_item>>>(value);
      if(!ok)return ok;
      M+=dev.go_const("\"");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_int_expr:public i_expr{
  public:
    //===>>===i_val_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_zero)\
    ADD(t_num)\
    ADDEND()
  
    class i_val;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_val_visitor{
    public:
      typedef t_int_expr::i_val i_val;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_int_expr::U U;
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
      static TYPE*UberCast(i_val*p){
        if(!p)return nullptr;Is<TYPE,i_val_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_val_visitor
    //class t_visitor:public t_int_expr::i_val_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_zero*p){}
    //  void Do(t_num*p){}
    //};
  public:
    class i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_val
    #include "QapGenStruct.inl"
    //<<<<<+=====i_val
    public:
      typedef i_val_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_zero);
          F(t_num);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_zero:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_zero
    #include "QapGenStruct.inl"
    //<<<<<+=====t_zero
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
        D+=dev.go_const("0");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_num:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,first,SET,'1',$)\
    ADDVAR(1,string,num,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_num
    #include "QapGenStruct.inl"
    //<<<<<+=====t_num
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
        static const auto g_static_var_0=gen_dips("19");
        M+=dev.go_any_char(first,g_static_var_0);
        if(!ok)return ok;
        static const auto g_static_var_1=gen_dips("09");
        O+=dev.go_any(num,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_zero)\
    F(t_num )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_int_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_int_expr
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
      D+=dev.go_str<TAutoPtr<i_val>>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_type_expr{
  public:
    class t_params{
    public:
      class t_count{
      public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_count)OWNER(t_params)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(1,t_int_expr,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_count
      #include "QapGenStruct.inl"
      //<<<<<+=====t_count
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const(",");
          if(!ok)return ok;
          D+=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)F(t_count)
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,TAutoPtr<t_count>,count,DEF,$,$)\
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
        M+=dev.go_const("{");
        if(!ok)return ok;
        M+=dev.go_str<t_type_expr>(type);
        if(!ok)return ok;
        O+=dev.go_auto(count);
        if(!ok)return ok;
        M+=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_name,name,DEF,$,$)\
    ADDVAR(1,TAutoPtr<t_params>,params,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStruct.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_auto(name);
        if(!ok)return ok;
        O+=dev.go_auto(params);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_elem,body,DEF,$,$)\
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
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("::");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_params)\
    F(t_elem  )\
    F(t_item  )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_elem,first,DEF,$,$)\
  ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
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
      M+=dev.go_auto(first);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_type_expr::TYPE TYPE;
    //  F(t_params);
    //  F(t_elem);
    //  F(t_item);
    //  #undef F
    //public:
    //  void Do(t_params&ref){}
    //  void Do(t_elem&ref){}
    //  void Do(t_item&ref){}
    //};
  };
  class t_var_stat:public i_stat{
  public:
    //===>>===i_impl_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_type_impl)\
    ADD(t_auto_impl)\
    ADDEND()
  
    class i_impl;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_impl_visitor{
    public:
      typedef t_var_stat::i_impl i_impl;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_var_stat::U U;
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
      static TYPE*UberCast(i_impl*p){
        if(!p)return nullptr;Is<TYPE,i_impl_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_impl_visitor
    //class t_visitor:public t_var_stat::i_impl_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_type_impl*p){}
    //  void Do(t_auto_impl*p){}
    //};
  public:
    class i_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====i_impl
    public:
      typedef i_impl_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_type_impl);
          F(t_auto_impl);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_lev14,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_value
    #include "QapGenStruct.inl"
    //<<<<<+=====t_value
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("=");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_type_impl:public i_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_impl)PARENT(i_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_type_expr,type,DEF,$,$)\
    ADDVAR(1,t_sep,sep0,DEF,$,$)\
    ADDVAR(2,t_name,name,DEF,$,$)\
    ADDVAR(3,TAutoPtr<t_value>,value,DEF,$,$)\
    ADDVAR(4,t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_type_impl
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
        M+=dev.go_auto(type);
        if(!ok)return ok;
        M+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(name);
        if(!ok)return ok;
        O+=dev.go_auto(value);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_auto_impl:public i_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_auto_impl)PARENT(i_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_name,name,DEF,$,$)\
    ADDVAR(2,TAutoPtr<t_value>,value,DEF,$,$)\
    ADDVAR(3,t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_auto_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_auto_impl
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
        M+=dev.go_const("auto");
        if(!ok)return ok;
        M+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(name);
        if(!ok)return ok;
        O+=dev.go_auto(value);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_impl>,impl,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(impl);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_value    )\
    F(t_type_impl)\
    F(t_auto_impl)\
    F(t_impl     )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_var_stat::TYPE TYPE;
    //  F(i_impl);
    //  F(t_value);
    //  F(t_type_impl);
    //  F(t_auto_impl);
    //  F(t_impl);
    //  #undef F
    //public:
    //  void Do(t_value&ref){}
    //  void Do(t_type_impl&ref){}
    //  void Do(t_auto_impl&ref){}
    //  void Do(t_impl&ref){}
    //};
  };
  class t_sep_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sep_stat
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
      D+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_command_block{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_command_block)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_command_block
  #include "QapGenStruct.inl"
  //<<<<<+=====t_command_block
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_block_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_command_block,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_expr_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_char_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_char_item,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_char_expr
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_bool_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_bool_expr
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
      static const auto g_static_var_0=split("true,false",",");
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_string_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_string_expr
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_real_expr:public i_expr{
  public:
    //===>>===i_val_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_num)\
    ADD(t_zero)\
    ADDEND()
  
    class i_val;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_val_visitor{
    public:
      typedef t_real_expr::i_val i_val;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_real_expr::U U;
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
      static TYPE*UberCast(i_val*p){
        if(!p)return nullptr;Is<TYPE,i_val_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_val_visitor
    //class t_visitor:public t_real_expr::i_val_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_num*p){}
    //  void Do(t_zero*p){}
    //};
  public:
    class i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_val
    #include "QapGenStruct.inl"
    //<<<<<+=====i_val
    public:
      typedef i_val_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_num);
          F(t_zero);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_frac{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,arr,DEF,$,$)\
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
        static const auto g_static_var_1=gen_dips("09");
        D+=dev.go_any(arr,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_sign{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,sign,SET,'+',$)\
    ADDEND()
    //=====+>>>>>t_sign
    #include "QapGenStruct.inl"
    //<<<<<+=====t_sign
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0="-+";
        D+=dev.go_any_char(sign,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_exp{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,e,SET,'e',$)\
    ADDVAR(1,TAutoPtr<t_sign>,sign,DEF,$,$)\
    ADDVAR(2,string,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_exp
    #include "QapGenStruct.inl"
    //<<<<<+=====t_exp
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0="eE";
        M+=dev.go_any_char(e,g_static_var_0);
        if(!ok)return ok;
        O+=dev.go_auto(sign);
        if(!ok)return ok;
        static const auto g_static_var_2=gen_dips("09");
        M+=dev.go_any(arr,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_num:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,first,SET,'1',$)\
    ADDVAR(1,string,num,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_num
    #include "QapGenStruct.inl"
    //<<<<<+=====t_num
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
        static const auto g_static_var_0=gen_dips("19");
        M+=dev.go_any_char(first,g_static_var_0);
        if(!ok)return ok;
        static const auto g_static_var_1=gen_dips("09");
        O+=dev.go_any(num,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_zero:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_zero
    #include "QapGenStruct.inl"
    //<<<<<+=====t_zero
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
        D+=dev.go_const("0");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_val>,val,DEF,$,$)\
    ADDVAR(1,TAutoPtr<t_frac>,frac,DEF,$,$)\
    ADDVAR(2,TAutoPtr<t_exp>,exp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_auto(val);
        if(!ok)return ok;
        M+=dev.go_auto(frac);
        if(!ok)return ok;
        O+=dev.go_auto(exp);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_frac)\
    F(t_sign)\
    F(t_exp )\
    F(t_num )\
    F(t_zero)\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_real_expr
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
      M+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_real_expr::TYPE TYPE;
    //  F(i_val);
    //  F(t_frac);
    //  F(t_sign);
    //  F(t_exp);
    //  F(t_num);
    //  F(t_zero);
    //  F(t_impl);
    //  #undef F
    //public:
    //  void Do(t_frac&ref){}
    //  void Do(t_sign&ref){}
    //  void Do(t_exp&ref){}
    //  void Do(t_num&ref){}
    //  void Do(t_zero&ref){}
    //  void Do(t_impl&ref){}
    //};
  };
  class t_var_expr:public i_expr{
  public:
    class t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_lev14,expr,DEF,$,$)\
    ADDVAR(2,t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStruct.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("[");
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(expr);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_const("]");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_name,name,DEF,$,$)\
    ADDVAR(1,vector<t_elem>,arr,DEF,$,$)\
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
        M+=dev.go_auto(name);
        if(!ok)return ok;
        O+=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<t_item>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_vec(arr,".");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_elem)\
    F(t_item)\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var_expr
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_var_expr::TYPE TYPE;
    //  F(t_elem);
    //  F(t_item);
    //  F(t_impl);
    //  #undef F
    //public:
    //  void Do(t_elem&ref){}
    //  void Do(t_item&ref){}
    //  void Do(t_impl&ref){}
    //};
  };
  class t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block_expr
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
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_param)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_lev14,body,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_param
  #include "QapGenStruct.inl"
  //<<<<<+=====t_call_param
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_params)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep,DEF,$,$)\
  ADDVAR(1,vector<t_call_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_params
  #include "QapGenStruct.inl"
  //<<<<<+=====t_call_params
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_expr:public i_expr{
  public:
    //===>>===i_call_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_dot)\
    ADD(t_colon)\
    ADDEND()
  
    class i_call;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_call_visitor{
    public:
      typedef t_call_expr::i_call i_call;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_call_expr::U U;
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
      static TYPE*UberCast(i_call*p){
        if(!p)return nullptr;Is<TYPE,i_call_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_call_visitor
    //class t_visitor:public t_call_expr::i_call_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_dot*p){}
    //  void Do(t_colon*p){}
    //};
  public:
    class i_call{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_call)OWNER(t_call_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_call
    #include "QapGenStruct.inl"
    //<<<<<+=====i_call
    public:
      typedef i_call_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_dot);
          F(t_colon);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_dot:public i_call{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dot)PARENT(i_call)OWNER(t_call_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_var_expr::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_dot
    #include "QapGenStruct.inl"
    //<<<<<+=====t_dot
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_colon:public i_call{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_colon)PARENT(i_call)OWNER(t_call_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<t_name>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_colon
    #include "QapGenStruct.inl"
    //<<<<<+=====t_colon
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
        D+=dev.go_bin_oper(arr,"::");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_dot  )\
    F(t_colon)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TAutoPtr<i_call>,call,DEF,$,$)\
  ADDVAR(1,t_sep,sep,DEF,$,$)\
  ADDVAR(2,t_call_params,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_call_expr
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
      M+=dev.go_auto(call);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(params);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,string,type,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDVAR(3,t_name,name,DEF,$,$)\
  ADDVAR(4,t_sep,sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_param
  #include "QapGenStruct.inl"
  //<<<<<+=====t_param
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_str<t_type_expr>(type);
      if(!ok)return ok;
      M+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<t_param>,arr,DEF,$,$)\
  ADDVAR(1,t_sep,sep,DEF,$,$)\
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
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_set_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_oper)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_var_expr::t_impl,var,DEF,$,$)\
  ADDVAR(1,string,oper,DEF,$,$)\
  ADDVAR(2,t_lev14,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_set_oper
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(var);
      if(!ok)return ok;
      static const auto g_static_var_1=split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=",",");
      D+=dev.go_any_str_from_vec(oper,g_static_var_1);
      if(!ok)return ok;
      D+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_set_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_set_oper,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_oper_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_set_oper_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_func_stat:public i_stat{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_func_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,t_sep,sep0,DEF,$,$)\
    ADDVAR(2,t_name,name,DEF,$,$)\
    ADDVAR(3,t_sep,sep1,DEF,$,$)\
    ADDVAR(4,t_params,params,DEF,$,$)\
    ADDVAR(5,t_sep,sep2,DEF,$,$)\
    ADDVAR(6,t_command_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_str<t_type_expr>(type);
        if(!ok)return ok;
        M+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_func_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,type,DEF,$,$)\
  ADDVAR(1,t_sep,sep0,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDVAR(3,string,oper,DEF,$,$)\
  ADDVAR(4,t_sep,sep2,DEF,$,$)\
  ADDVAR(5,t_params,params,DEF,$,$)\
  ADDVAR(6,t_sep,sep3,DEF,$,$)\
  ADDVAR(7,t_command_block,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_oper_stat
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
      M+=dev.go_str<t_type_expr>(type);
      if(!ok)return ok;
      M+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_const("operator");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      static const auto g_static_var_4=split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!",",");
      M+=dev.go_any_str_from_vec(oper,g_static_var_4);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      M+=dev.go_auto(params);
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ret_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_lev14,body,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ret_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_ret_stat
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
      M+=dev.go_const("return");
      if(!ok)return ok;
      M+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_null_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_null_stat
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
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_postfix_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix_oper)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_var_expr::t_impl,var,DEF,$,$)\
  ADDVAR(1,string,oper,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_postfix_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_postfix_oper
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(var);
      if(!ok)return ok;
      static const auto g_static_var_1=split("++,--",",");
      D+=dev.go_any_str_from_vec(oper,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_postfix_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_postfix_oper,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_postfix_oper_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_postfix_oper_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_break_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_break_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_break_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_break_stat
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
      D+=dev.go_const("break;");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_continue_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_continue_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_continue_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_continue_stat
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
      D+=dev.go_const("continue;");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_for_stat:public i_stat{
  public:
    //===>>===i_next_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_set)\
    ADD(t_postfix)\
    ADDEND()
  
    class i_next;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_next_visitor{
    public:
      typedef t_for_stat::i_next i_next;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_for_stat::U U;
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
      static TYPE*UberCast(i_next*p){
        if(!p)return nullptr;Is<TYPE,i_next_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_next_visitor
    //class t_visitor:public t_for_stat::i_next_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_set*p){}
    //  void Do(t_postfix*p){}
    //};
  public:
    class i_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_next
    #include "QapGenStruct.inl"
    //<<<<<+=====i_next
    public:
      typedef i_next_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_set);
          F(t_postfix);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_set:public i_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set)PARENT(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_set_oper,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_set
    #include "QapGenStruct.inl"
    //<<<<<+=====t_set
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_postfix:public i_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix)PARENT(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_postfix_oper,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_postfix
    #include "QapGenStruct.inl"
    //<<<<<+=====t_postfix
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_next>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_next
    #include "QapGenStruct.inl"
    //<<<<<+=====t_next
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_set    )\
    F(t_postfix)\
    F(t_next   )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0x1,t_sep,sep0,DEF,$,$)\
  ADDVAR(0x2,t_sep,sep1,DEF,$,$)\
  ADDVAR(0x3,TAutoPtr<t_var_stat::t_impl>,init,DEF,$,$)\
  ADDVAR(0x4,t_sep,sep2,DEF,$,$)\
  ADDVAR(0x5,t_sep,sep3,DEF,$,$)\
  ADDVAR(0x6,TAutoPtr<t_lev14>,cond,DEF,$,$)\
  ADDVAR(0x7,t_sep,sep4,DEF,$,$)\
  ADDVAR(0x8,t_sep,sep5,DEF,$,$)\
  ADDVAR(0x9,TAutoPtr<t_next>,next,DEF,$,$)\
  ADDVAR(0xA,t_sep,sep6,DEF,$,$)\
  ADDVAR(0xB,t_sep,sep7,DEF,$,$)\
  ADDVAR(0xC,TAutoPtr<i_stat>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_for_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_for_stat
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
      M+=dev.go_const("for");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      O+=dev.go_auto(init);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      O+=dev.go_auto(cond);
      if(!ok)return ok;
      O+=dev.go_auto(sep4);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      O+=dev.go_auto(sep5);
      if(!ok)return ok;
      O+=dev.go_auto(next);
      if(!ok)return ok;
      O+=dev.go_auto(sep6);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      O+=dev.go_auto(sep7);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_for_stat::TYPE TYPE;
    //  F(i_next);
    //  F(t_set);
    //  F(t_postfix);
    //  F(t_next);
    //  #undef F
    //public:
    //  void Do(t_set&ref){}
    //  void Do(t_postfix&ref){}
    //  void Do(t_next&ref){}
    //};
  };
  class t_if_stat:public i_stat{
  public:
    class t_else{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else)OWNER(t_if_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,TAutoPtr<i_stat>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_else
    #include "QapGenStruct.inl"
    //<<<<<+=====t_else
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("else");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_else)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_if_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_sep,sep1,DEF,$,$)\
  ADDVAR(2,t_lev14,cond,DEF,$,$)\
  ADDVAR(3,t_sep,sep2,DEF,$,$)\
  ADDVAR(4,t_sep,sep3,DEF,$,$)\
  ADDVAR(5,TAutoPtr<i_stat>,bef,DEF,$,$)\
  ADDVAR(6,TAutoPtr<t_else>,aft,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_if_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_if_stat
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
      M+=dev.go_const("if");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(cond);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      M+=dev.go_auto(bef);
      if(!ok)return ok;
      O+=dev.go_auto(aft);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_struct;
  class t_struct{
  public:
    class t_field{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_struct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_var_stat::t_type_impl,body,DEF,$,$)\
    ADDVAR(2,t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_field
    #include "QapGenStruct.inl"
    //<<<<<+=====t_field
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        M+=dev.go_const(";");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_method{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_method)OWNER(t_struct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_func_stat::t_impl,body,DEF,$,$)\
    ADDVAR(2,t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_method
    #include "QapGenStruct.inl"
    //<<<<<+=====t_method
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_field )\
    F(t_method)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_name,name,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDVAR(3,vector<t_sep_struct>,arr,DEF,$,$)\
  ADDVAR(4,vector<t_field>,fields,DEF,$,$)\
  ADDVAR(5,vector<t_method>,methods,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("struct");
      if(!ok)return ok;
      M+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      O+=dev.go_auto(fields);
      if(!ok)return ok;
      O+=dev.go_auto(methods);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_struct{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_struct,body,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_struct
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sep_struct
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_struct_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_struct,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_stat
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_template_stat:public i_stat{
  public:
    //===>>===i_body_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_func_body)\
    ADD(t_oper_body)\
    ADD(t_struct_body)\
    ADDEND()
  
    class i_body;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_body_visitor{
    public:
      typedef t_template_stat::i_body i_body;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_template_stat::U U;
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
      static TYPE*UberCast(i_body*p){
        if(!p)return nullptr;Is<TYPE,i_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_body_visitor
    //class t_visitor:public t_template_stat::i_body_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_func_body*p){}
    //  void Do(t_oper_body*p){}
    //  void Do(t_struct_body*p){}
    //};
  public:
    class i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_body
    #include "QapGenStruct.inl"
    //<<<<<+=====i_body
    public:
      typedef i_body_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_func_body);
          F(t_oper_body);
          F(t_struct_body);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_param{
    public:
      class t_type{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type)OWNER(t_param)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_type
      #include "QapGenStruct.inl"
      //<<<<<+=====t_type
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const("class");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_type)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_type,type,DEF,$,$)\
    ADDVAR(2,t_sep,sep1,DEF,$,$)\
    ADDVAR(3,t_name,name,DEF,$,$)\
    ADDVAR(4,t_sep,sep2,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_param
    #include "QapGenStruct.inl"
    //<<<<<+=====t_param
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_params{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<t_param>,arr,DEF,$,$)\
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
        D+=dev.go_const("{");
        if(!ok)return ok;
        D+=dev.go_vec(arr,",");
        if(!ok)return ok;
        D+=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_func_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_body)PARENT(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_func_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_func_body
    #include "QapGenStruct.inl"
    //<<<<<+=====t_func_body
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_oper_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_body)PARENT(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_oper_stat,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper_body
    #include "QapGenStruct.inl"
    //<<<<<+=====t_oper_body
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_struct_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_body)PARENT(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_struct,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_struct_body
    #include "QapGenStruct.inl"
    //<<<<<+=====t_struct_body
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_param      )\
    F(t_params     )\
    F(t_func_body  )\
    F(t_oper_body  )\
    F(t_struct_body)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_params,params,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDVAR(3,TAutoPtr<i_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_template_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_template_stat
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
      M+=dev.go_const("template");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(params);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_template_stat::TYPE TYPE;
    //  F(i_body);
    //  F(t_param);
    //  F(t_params);
    //  F(t_func_body);
    //  F(t_oper_body);
    //  F(t_struct_body);
    //  #undef F
    //public:
    //  void Do(t_param&ref){}
    //  void Do(t_params&ref){}
    //  void Do(t_func_body&ref){}
    //  void Do(t_oper_body&ref){}
    //  void Do(t_struct_body&ref){}
    //};
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_lev03            )\
  F(t_lev05            )\
  F(t_lev06            )\
  F(t_lev07            )\
  F(t_lev08            )\
  F(t_lev09            )\
  F(t_lev10            )\
  F(t_lev11            )\
  F(t_lev12            )\
  F(t_lev13            )\
  F(t_lev14            )\
  F(t_string           )\
  F(t_int_expr         )\
  F(t_type_expr        )\
  F(t_var_stat         )\
  F(t_sep_stat         )\
  F(t_command_block    )\
  F(t_block_stat       )\
  F(t_expr_stat        )\
  F(t_char_expr        )\
  F(t_bool_expr        )\
  F(t_string_expr      )\
  F(t_real_expr        )\
  F(t_var_expr         )\
  F(t_block_expr       )\
  F(t_call_param       )\
  F(t_call_params      )\
  F(t_call_expr        )\
  F(t_param            )\
  F(t_params           )\
  F(t_set_oper         )\
  F(t_set_oper_stat    )\
  F(t_func_stat        )\
  F(t_oper_stat        )\
  F(t_ret_stat         )\
  F(t_null_stat        )\
  F(t_postfix_oper     )\
  F(t_postfix_oper_stat)\
  F(t_break_stat       )\
  F(t_continue_stat    )\
  F(t_for_stat         )\
  F(t_if_stat          )\
  F(t_struct           )\
  F(t_sep_struct       )\
  F(t_struct_stat      )\
  F(t_template_stat    )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_simple_stat_lex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_simple_stat_lex
#include "QapGenStruct.inl"
//<<<<<+=====t_simple_stat_lex
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("");
    if(!ok)return ok;
    return ok;
  }
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
  //  F(i_expr);
  //  F(i_stat);
  //  F(t_lev03);
  //  F(t_lev05);
  //  F(t_lev06);
  //  F(t_lev07);
  //  F(t_lev08);
  //  F(t_lev09);
  //  F(t_lev10);
  //  F(t_lev11);
  //  F(t_lev12);
  //  F(t_lev13);
  //  F(t_lev14);
  //  F(t_string);
  //  F(t_int_expr);
  //  F(t_type_expr);
  //  F(t_var_stat);
  //  F(t_sep_stat);
  //  F(t_command_block);
  //  F(t_block_stat);
  //  F(t_expr_stat);
  //  F(t_char_expr);
  //  F(t_bool_expr);
  //  F(t_string_expr);
  //  F(t_real_expr);
  //  F(t_var_expr);
  //  F(t_block_expr);
  //  F(t_call_param);
  //  F(t_call_params);
  //  F(t_call_expr);
  //  F(t_param);
  //  F(t_params);
  //  F(t_set_oper);
  //  F(t_set_oper_stat);
  //  F(t_func_stat);
  //  F(t_oper_stat);
  //  F(t_ret_stat);
  //  F(t_null_stat);
  //  F(t_postfix_oper);
  //  F(t_postfix_oper_stat);
  //  F(t_break_stat);
  //  F(t_continue_stat);
  //  F(t_for_stat);
  //  F(t_if_stat);
  //  F(t_struct);
  //  F(t_sep_struct);
  //  F(t_struct_stat);
  //  F(t_template_stat);
  //  #undef F
  //public:
  //  void Do(t_lev03&ref){}
  //  void Do(t_lev05&ref){}
  //  void Do(t_lev06&ref){}
  //  void Do(t_lev07&ref){}
  //  void Do(t_lev08&ref){}
  //  void Do(t_lev09&ref){}
  //  void Do(t_lev10&ref){}
  //  void Do(t_lev11&ref){}
  //  void Do(t_lev12&ref){}
  //  void Do(t_lev13&ref){}
  //  void Do(t_lev14&ref){}
  //  void Do(t_string&ref){}
  //  void Do(t_int_expr&ref){}
  //  void Do(t_type_expr&ref){}
  //  void Do(t_var_stat&ref){}
  //  void Do(t_sep_stat&ref){}
  //  void Do(t_command_block&ref){}
  //  void Do(t_block_stat&ref){}
  //  void Do(t_expr_stat&ref){}
  //  void Do(t_char_expr&ref){}
  //  void Do(t_bool_expr&ref){}
  //  void Do(t_string_expr&ref){}
  //  void Do(t_real_expr&ref){}
  //  void Do(t_var_expr&ref){}
  //  void Do(t_block_expr&ref){}
  //  void Do(t_call_param&ref){}
  //  void Do(t_call_params&ref){}
  //  void Do(t_call_expr&ref){}
  //  void Do(t_param&ref){}
  //  void Do(t_params&ref){}
  //  void Do(t_set_oper&ref){}
  //  void Do(t_set_oper_stat&ref){}
  //  void Do(t_func_stat&ref){}
  //  void Do(t_oper_stat&ref){}
  //  void Do(t_ret_stat&ref){}
  //  void Do(t_null_stat&ref){}
  //  void Do(t_postfix_oper&ref){}
  //  void Do(t_postfix_oper_stat&ref){}
  //  void Do(t_break_stat&ref){}
  //  void Do(t_continue_stat&ref){}
  //  void Do(t_for_stat&ref){}
  //  void Do(t_if_stat&ref){}
  //  void Do(t_struct&ref){}
  //  void Do(t_sep_struct&ref){}
  //  void Do(t_struct_stat&ref){}
  //  void Do(t_template_stat&ref){}
  //};
};

/*
//list of types:
F(t_simple_stat_lex)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fsimple%5Fstat%5Flex%7B%0A%20%20t%5Flev03%7B%0A%20%20%20%20string%20oper%3B%0
A%20%20%20%20TAutoPtr%3Ci%5Fexpr%3E%20expr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%2
0%20O%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%2B%2C%2D%2C%21%2C%7E
%22%2C%22%2C%22%29%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20
%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flev05%7B%0A%20%20%20%20t%5Foper%7B%0A%20%20
%20%20%20%20string%20value%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20
go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%2A%2C%2F%2C%25%22%2C%22%2C%22%
29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%
20%20%20%20%20%20t%5Foper%20oper%3B%0A%20%20%20%20%20%20t%5Flev03%20expr%3B%0A%2
0%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0A%20%20%20
%20%20%20%20%20go%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%
0A%20%20%20%20t%5Flev03%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A
%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flev
06%7B%0A%20%20%20%20t%5Foper%7B%0A%20%20%20%20%20%20string%20value%3B%0A%20%20%2
0%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csp
lit%28%22%2B%2C%2D%22%2C%22%2C%22%29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%2
0%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0A%20%20%2
0%20%20%20t%5Flev05%20expr%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20
go%5Fauto%28oper%29%3B%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0A%20%20
%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Flev05%20expr%3B%0A%20%20%20%
20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%
5Fauto%28expr%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20
%20%7D%0A%20%20%7D%0A%20%20t%5Flev07%7B%0A%20%20%20%20t%5Foper%7B%0A%20%20%20%20
%20%20string%20value%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fa
ny%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3C%3C%2C%3E%3E%22%2C%22%2C%22%29%29%
3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%
20%20%20%20t%5Foper%20oper%3B%0A%20%20%20%20%20%20t%5Flev06%20expr%3B%0A%20%20%2
0%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0A%20%20%20%20%20
%20%20%20go%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%
20%20%20t%5Flev06%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20
%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flev08%7B%
0A%20%20%20%20t%5Foper%7B%0A%20%20%20%20%20%20string%20value%3B%0A%20%20%20%20%2
0%20%7B%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28
%22%3C%2C%3C%3D%2C%3E%2C%3E%3D%22%2C%22%2C%22%29%29%3B%0A%20%20%20%20%20%20%7D%0
A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20t%5Foper%20oper%3
B%0A%20%20%20%20%20%20t%5Flev07%20expr%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20
%20%20%20%20go%5Fauto%28oper%29%3B%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29
%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Flev07%20expr%3B%
0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B
%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flev09%7B%0A%20%20%20%20t%5Foper%7B%0A
%20%20%20%20%20%20string%20value%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20
%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3D%3D%2C%21%3D%22%2C%22%
2C%22%29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%
7B%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0A%20%20%20%20%20%20t%5Flev08%20expr%3
B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0A%20
%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%
20%7D%0A%20%20%20%20t%5Flev08%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr
%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20
%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t
%5Flev10%7B%0A%20%20%20%20t%5Foper%7B%0A%20%20%20%20%20%20string%20value%3B%0A%2
0%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28valu
e%2Csplit%28%22%26%22%2C%22%2C%22%29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%2
0%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0A%20%20%2
0%20%20%20t%5Flev09%20expr%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20
go%5Fauto%28oper%29%3B%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0A%20%20
%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Flev09%20expr%3B%0A%20%20%20%
20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%
5Fauto%28expr%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20
%20%7D%0A%20%20%7D%0A%20%20t%5Flev11%7B%0A%20%20%20%20t%5Foper%7B%0A%20%20%20%20
%20%20string%20value%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fa
ny%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%5E%22%2C%22%2C%22%29%29%3B%0A%20%20%
20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20t
%5Foper%20oper%3B%0A%20%20%20%20%20%20t%5Flev10%20expr%3B%0A%20%20%20%20%20%20%7
B%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0A%20%20%20%20%20%20%20%20go%
5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5F
lev10%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7B%0A
%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flev12%7B%0A%20%20%20%
20t%5Foper%7B%0A%20%20%20%20%20%20string%20value%3B%0A%20%20%20%20%20%20%7B%0A%2
0%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%22%2C
%22%2C%22%29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fi
tem%7B%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0A%20%20%20%20%20%20t%5Flev11%20ex
pr%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0
A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20
%20%20%7D%0A%20%20%20%20t%5Flev11%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%2
0arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%2
0%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20
%20t%5Flev13%7B%0A%20%20%20%20t%5Foper%7B%0A%20%20%20%20%20%20string%20value%3B%
0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28
value%2Csplit%28%22%26%26%22%2C%22%2C%22%29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%
20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0A%
20%20%20%20%20%20t%5Flev12%20expr%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%2
0%20%20go%5Fauto%28oper%29%3B%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0
A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Flev12%20expr%3B%0A%20
%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2
B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%2
0%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flev14%7B%0A%20%20%20%20t%5Foper%7B%0A%20%2
0%20%20%20%20string%20value%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%2
0go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%7C%22%2C%22%2C%22%29%29%3B
%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20
%20%20%20t%5Foper%20oper%3B%0A%20%20%20%20%20%20t%5Flev13%20expr%3B%0A%20%20%20%
20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0A%20%20%20%20%20%2
0%20%20go%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20
%20%20t%5Flev13%20expr%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%2
0%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fstring%7B%0
A%20%20%20%20string%20value%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5
Fconst%28%22%5C%22%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Cvector%3CTAuto
Ptr%3Ci%5Fstr%5Fitem%3E%3E%3E%28value%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fcons
t%28%22%5C%22%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fint%5Fexpr%3D%3
Ei%5Fexpr%7B%0A%20%20%20%20t%5Fzero%3D%3Ei%5Fval%7B%0A%20%20%20%20%20%20%7B%0A%2
0%20%20%20%20%20%20%20go%5Fconst%28%220%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%2
0%20%20%7D%0A%20%20%20%20t%5Fnum%3D%3Ei%5Fval%7B%0A%20%20%20%20%20%20char%20firs
t%3D%271%27%3B%0A%20%20%20%20%20%20string%20num%3B%0A%20%20%20%20%20%20%7B%0A%20
%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28first%2Cgen%5Fdips%28%2219%22%29%2
9%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fany%28num%2Cgen%5Fdips%28%2209%22%29%
29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20string%20value%3B%
0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fstr%3CTAutoPtr%3Ci%5Fval%3E%3E%28valu
e%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Ftype%5Fexpr%7B%0A%20%20%20%20t
%5Fparams%7B%0A%20%20%20%20%20%20string%20type%3B%0A%20%20%20%20%20%20t%5Fint%5F
expr%20count%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%
22%7B%22%29%3B%0A%20%20%20%20%20%20%20%20go%5Fstr%3Ct%5Ftype%5Fexpr%3E%28type%29
%3B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%2C%22%29%3B%0A%20%20%20%20%20%20%
20%20go%5Fauto%28count%29%3B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%7D%22%29
%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Felem%7B%0A%20%20
%20%20%20%20t%5Fname%20name%3B%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fparams%3E%20pa
rams%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28nam
e%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0A%20%20%20%20
%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20t%5Fse
p%20sep0%3B%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20t%5Felem%2
0body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28se
p0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%0A%20%
20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%20%20M%2B
%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%
20t%5Felem%20first%3B%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20
%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28first%29%3B%0A%20%20%20%20%20%20O%2B%
3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fvar%5Fstat%3D%
3Ei%5Fstat%7B%0A%20%20%20%20t%5Fvalue%7B%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0
A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20t%5Flev14%20value%3B%0A
%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A
%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3D%22%29%3B%0A%20%20%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%2
8value%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Ftype%5F
impl%3D%3Ei%5Fimpl%7B%0A%20%20%20%20%20%20t%5Ftype%5Fexpr%20type%3B%0A%20%20%20%
20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20%20%20t%5Fname%20name%3B%0A%20%20%20%20%
20%20TAutoPtr%3Ct%5Fvalue%3E%20value%3B%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A
%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0A
%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20%20%20
M%2B%3Dgo%5Fauto%28name%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28value
%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20
%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fauto%5Fimpl%3D%3Ei%5Fimpl%7B%0A%20%20
%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20%20%20t%5Fname%20name%3B%0A%20%20%20
%20%20%20TAutoPtr%3Ct%5Fvalue%3E%20value%3B%0A%20%20%20%20%20%20t%5Fsep%20sep1%3
B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22auto%
22%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%
20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fa
uto%28value%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%
20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fimpl%7B%0A%20%20%20%20%20%
20TAutoPtr%3Ci%5Fimpl%3E%20impl%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%
20%20go%5Fauto%28impl%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%2
0%20t%5Fimpl%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fauto%28body%29
%3B%0A%20%20%20%20%20%20go%5Fconst%28%22%3B%22%29%3B%0A%20%20%20%20%7D%0A%20%20%
7D%0A%20%20t%5Fsep%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fsep%20sep%3B%0A%20%
20%20%20%7B%0A%20%20%20%20%20%20go%5Fauto%28sep%29%3B%0A%20%20%20%20%7D%0A%20%20
%7D%0A%20%20t%5Fcommand%5Fblock%7B%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fstat%3E
%3E%20arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22
%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%20%20M%2B
%3Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fblock%
5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fcommand%5Fblock%20body%3B%0A%20%20%20%
20%7B%0A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0
A%20%20t%5Fexpr%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Flev14%20body%3B%0A%20%
20%20%20%7B%0A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%20%20go%5F
const%28%22%3B%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fchar%5Fexpr%3D
%3Ei%5Fexpr%7B%0A%20%20%20%20t%5Fchar%5Fitem%20body%3B%0A%20%20%20%20%7B%0A%20%2
0%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fbo
ol%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20%20%20string%20value%3B%0A%20%20%20%20%7B%0A%
20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22true%2Cfalse%2
2%2C%22%2C%22%29%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fstring%5Fexpr%3
D%3Ei%5Fexpr%7B%0A%20%20%20%20t%5Fstring%20body%3B%0A%20%20%20%20%7B%0A%20%20%20
%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Freal%5
Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20%20%20t%5Ffrac%7B%0A%20%20%20%20%20%20string%20ar
r%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%2E%22%29
%3B%0A%20%20%20%20%20%20%20%20go%5Fany%28arr%2Cgen%5Fdips%28%2209%22%29%29%3B%0A
%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fsign%7B%0A%20%20%20%20
%20%20char%20sign%3D%27%2B%27%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20
%20go%5Fany%5Fchar%28sign%2C%22%2D%2B%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%
20%20%7D%0A%20%20%20%20t%5Fexp%7B%0A%20%20%20%20%20%20char%20e%3D%27e%27%3B%0A%2
0%20%20%20%20%20TAutoPtr%3Ct%5Fsign%3E%20sign%3B%0A%20%20%20%20%20%20string%20ar
r%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28
e%2C%22eE%22%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sign%29%3B%0A%20
%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%28arr%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%2
0%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fnum%3D%3Ei%5Fval%7B%0A%2
0%20%20%20%20%20char%20first%3D%271%27%3B%0A%20%20%20%20%20%20string%20num%3B%0A
%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28first%2
Cgen%5Fdips%28%2219%22%29%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fany%28num%
2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20
%20%20%20t%5Fzero%3D%3Ei%5Fval%7B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%2
0%20go%5Fconst%28%220%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%2
0%20%20t%5Fimpl%7B%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Fval%3E%20val%3B%0A%20%20%2
0%20%20%20TAutoPtr%3Ct%5Ffrac%3E%20frac%3B%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fex
p%3E%20exp%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto
%28val%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28frac%29%3B%0A%20%20%20
%20%20%20%20%20O%2B%3Dgo%5Fauto%28exp%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%
20%7D%0A%20%20%20%20string%20value%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B
%3Dgo%5Fstr%3Ct%5Fimpl%3E%28value%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%
5Fvar%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20%20%20t%5Felem%7B%0A%20%20%20%20%20%20t%5F
sep%20sep0%3B%0A%20%20%20%20%20%20t%5Flev14%20expr%3B%0A%20%20%20%20%20%20t%5Fse
p%20sep1%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%
28%22%5B%22%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%
20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0A%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5D%2
2%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fitem%7B%0A%2
0%20%20%20%20%20t%5Fname%20name%3B%0A%20%20%20%20%20%20vector%3Ct%5Felem%3E%20ar
r%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%2
9%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%20%20
%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fimpl%7B%0A%20%20%20%20%20%20vector%3Ct%5
Fitem%3E%20arr%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fvec%28a
rr%2C%22%2E%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5
Fimpl%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%
20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fblock%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20%20
%20t%5Flev14%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fconst%28%22%28
%22%29%3B%0A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%20%20go%5Fco
nst%28%22%29%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fcall%5Fparam%7B%
0A%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20t%5Flev14%20body%3B%0A%20%20%20%20
t%5Fsep%20sep1%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%
29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fcall%5Fparam
s%7B%0A%20%20%20%20t%5Fsep%20sep%3B%0A%20%20%20%20vector%3Ct%5Fcall%5Fparam%3E%2
0arr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3
B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo
%5Fvec%28arr%2C%22%2C%22%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22
%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fcall%5Fexpr%3D%3Ei%5Fexpr%7B%0A
%20%20%20%20t%5Fdot%3D%3Ei%5Fcall%7B%0A%20%20%20%20%20%20t%5Fvar%5Fexpr%3A%3At%5
Fimpl%20body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28bo
dy%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fcolon%3D%3E
i%5Fcall%7B%0A%20%20%20%20%20%20vector%3Ct%5Fname%3E%20arr%3B%0A%20%20%20%20%20%
20%7B%0A%20%20%20%20%20%20%20%20go%5Fbin%5Foper%28arr%2C%22%3A%3A%22%29%3B%0A%20
%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20TAutoPtr%3Ci%5Fcall%3E%20call
%3B%0A%20%20%20%20t%5Fsep%20sep%3B%0A%20%20%20%20t%5Fcall%5Fparams%20params%3B%0
A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28call%29%3B%0A%20%20%20%2
0%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28param
s%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fparam%7B%0A%20%20%20%20t%5Fsep
%20sep0%3B%0A%20%20%20%20string%20type%3B%0A%20%20%20%20t%5Fsep%20sep1%3B%0A%20%
20%20%20t%5Fname%20name%3B%0A%20%20%20%20t%5Fsep%20sep2%3B%0A%20%20%20%20%7B%0A%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fs
tr%3Ct%5Ftype%5Fexpr%3E%28type%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28sep1
%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0A%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep2%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fparams%7B%0
A%20%20%20%20vector%3Ct%5Fparam%3E%20arr%3B%0A%20%20%20%20t%5Fsep%20sep%3B%0A%20
%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0A%20%20%20
%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28sep%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0A%20%
20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fset%5Foper%7B%0A%20%20%20%20t%5Fvar%5Fexpr%3
A%3At%5Fimpl%20var%3B%0A%20%20%20%20string%20oper%3B%0A%20%20%20%20t%5Flev14%20e
xpr%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fauto%28var%29%3B%0A%20%20%20%2
0%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%3D%2C%2B%3D%2C%2D%3D%2C%
2A%3D%2C%2F%3D%2C%25%3D%2C%7C%3D%2C%26%3D%2C%5E%3D%2C%3C%3C%3D%2C%3E%3E%3D%22%2C
%22%2C%22%29%29%3B%0A%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0A%20%20%20%20%7D%
0A%20%20%7D%0A%20%20t%5Fset%5Foper%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fset
%5Foper%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0
A%20%20%20%20%20%20go%5Fconst%28%22%3B%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A
%20%20t%5Ffunc%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fimpl%7B%0A%20%20%20%20%
20%20string%20type%3B%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20%20%20
t%5Fname%20name%3B%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20t%5
Fparams%20params%3B%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0A%20%20%20%20%20%20t%
5Fcommand%5Fblock%20body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20M%
2B%3Dgo%5Fstr%3Ct%5Ftype%5Fexpr%3E%28type%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3
Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%
0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%20%
20M%2B%3Dgo%5Fauto%28params%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28s
ep2%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20
%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fimpl%20body%3B%0A%20%20%20%20%7B%0
A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20
t%5Foper%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fname%20type%3B%0A%20%20%20%20
t%5Fsep%20sep0%3B%0A%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20string%20oper%3B
%0A%20%20%20%20t%5Fsep%20sep2%3B%0A%20%20%20%20t%5Fparams%20params%3B%0A%20%20%2
0%20t%5Fsep%20sep3%3B%0A%20%20%20%20t%5Fcommand%5Fblock%20body%3B%0A%20%20%20%20
%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0A%20%20%20%20%20%20M%2B%3
Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22operator%22%2
9%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20M%2B%
3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%3D%2C%2B%3D%2C%2D%3D%2C%2A%3D
%2C%2F%3D%2C%25%3D%2C%7C%3D%2C%26%3D%2C%5E%3D%2C%3C%3C%3D%2C%3E%3E%3D%2C%7C%7C%2
C%26%26%2C%7C%2C%5E%2C%26%2C%3D%3D%2C%21%3D%2C%3C%2C%3C%3D%2C%3E%2C%3E%3D%2C%3C%
3C%2C%3E%3E%2C%2B%2C%2D%2C%2A%2C%2F%2C%25%2C%2B%2B%2C%2D%2D%2C%7E%2C%21%22%2C%22
%2C%22%29%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0A%20%20%20%20
%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep
3%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%2
0%20%7D%0A%20%20t%5Fret%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fsep%20sep0%3B%
0A%20%20%20%20t%5Flev14%20body%3B%0A%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20
%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22return%22%29%3B%0A%20%20%20%20%20
%20M%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%
3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20M%2B%3D
go%5Fconst%28%22%3B%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fnull%5Fst
at%3D%3Ei%5Fstat%7B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fconst%28%22%3B%22
%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fpostfix%5Foper%7B%0A%20%20%20%2
0t%5Fvar%5Fexpr%3A%3At%5Fimpl%20var%3B%0A%20%20%20%20string%20oper%3B%0A%20%20%2
0%20%7B%0A%20%20%20%20%20%20go%5Fauto%28var%29%3B%0A%20%20%20%20%20%20go%5Fany%5
Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%2B%2B%2C%2D%2D%22%2C%22%2C%22%29%29%3B%0A
%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fpostfix%5Foper%5Fstat%3D%3Ei%5Fstat%7B%0
A%20%20%20%20t%5Fpostfix%5Foper%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20
go%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fbreak%5Fstat%3D
%3Ei%5Fstat%7B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fconst%28%22break%3B%22
%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fcontinue%5Fstat%3D%3Ei%5Fstat%7
B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fconst%28%22continue%3B%22%29%3B%0A%
20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Ffor%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%2
0t%5Fset%3D%3Ei%5Fnext%7B%0A%20%20%20%20%20%20t%5Fset%5Foper%20body%3B%0A%20%20%
20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%2
0%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fpostfix%3D%3Ei%5Fnext%7B%0A%20%20%20
%20%20%20t%5Fpostfix%5Foper%20body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%
20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%2
0%20%20t%5Fnext%7B%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Fnext%3E%20body%3B%0A%20%20
%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%
20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20t%5Fsep
%20sep1%3B%0A%20%20%20%20TAutoPtr%3Ct%5Fvar%5Fstat%3A%3At%5Fimpl%3E%20init%3B%0A
%20%20%20%20t%5Fsep%20sep2%3B%0A%20%20%20%20t%5Fsep%20sep3%3B%0A%20%20%20%20TAut
oPtr%3Ct%5Flev14%3E%20cond%3B%0A%20%20%20%20t%5Fsep%20sep4%3B%0A%20%20%20%20t%5F
sep%20sep5%3B%0A%20%20%20%20TAutoPtr%3Ct%5Fnext%3E%20next%3B%0A%20%20%20%20t%5Fs
ep%20sep6%3B%0A%20%20%20%20t%5Fsep%20sep7%3B%0A%20%20%20%20TAutoPtr%3Ci%5Fstat%3
E%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22for%22%
29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20M%2B
%3Dgo%5Fconst%28%22%28%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3
B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28init%29%3B%0A%20%20%20%20%20%20O%2B%3Dg
o%5Fauto%28sep2%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0A
%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28cond%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep4%29%3B%0A%20%20%20%
20%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto
%28sep5%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28next%29%3B%0A%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28sep6%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29
%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep7%29%3B%0A%20%20%20%20%20%20
M%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fif%5Fsta
t%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Felse%7B%0A%20%20%20%20%20%20t%5Fsep%20sep0%
3B%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Fstat
%3E%20body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto
%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22else%22%29%3B%0A%
20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%20%20M
%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%
20%20t%5Fsep%20sep0%3B%0A%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20t%5Flev14%2
0cond%3B%0A%20%20%20%20t%5Fsep%20sep2%3B%0A%20%20%20%20t%5Fsep%20sep3%3B%0A%20%2
0%20%20TAutoPtr%3Ci%5Fstat%3E%20bef%3B%0A%20%20%20%20TAutoPtr%3Ct%5Felse%3E%20af
t%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22if%22%29%3B%0A
%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5F
const%28%22%28%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%
20%20%20%20%20M%2B%3Dgo%5Fauto%28cond%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto
%28sep2%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28b
ef%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28aft%29%3B%0A%20%20%20%20%7D%0A%2
0%20%7D%0A%20%20t%5Fstruct%7B%0A%20%20%20%20t%5Ffield%7B%0A%20%20%20%20%20%20t%5
Fsep%20sep0%3B%0A%20%20%20%20%20%20t%5Fvar%5Fstat%3A%3At%5Ftype%5Fimpl%20body%3B
%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20
%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Faut
o%28body%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0A%
20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%7D%0A%
20%20%20%20%7D%0A%20%20%20%20t%5Fmethod%7B%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B
%0A%20%20%20%20%20%20t%5Ffunc%5Fstat%3A%3At%5Fimpl%20body%3B%0A%20%20%20%20%20%2
0t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0A%20
%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20%7D%0A%20
%20%20%20%7D%0A%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20t%5Fname%20name%3B%0A
%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20vector%3Ct%5Fsep%5Fstruct%3E%20arr%3
B%0A%20%20%20%20vector%3Ct%5Ffield%3E%20fields%3B%0A%20%20%20%20vector%3Ct%5Fmet
hod%3E%20methods%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2struct%22%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%2
0%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1
%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0A%20%20%20%20%20
%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28fields%29
%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28methods%29%3B%0A%20%20%20%20%20%20M%2
B%3Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fsep%5
Fstruct%7B%0A%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20t%5Fstruct%20body%3B%0A
%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28sep0%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%
20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5F
struct%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fstruct%20body%3B%0A%20%20%20%20
%7B%0A%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%
20%20t%5Ftemplate%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%20%20t%5Fparam%7B%0A%20%20%20
%20%20%20t%5Ftype%7B%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20
%20go%5Fconst%28%22class%22%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%2
0%20%7D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0A%20%20%20%20%20%20t%5Ftype%20typ
e%3B%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0A%20%20%20%20%20%20t%5Fname%20name%3
B%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fau
to%28type%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20
%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3
Dgo%5Fauto%28sep2%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20
t%5Fparams%7B%0A%20%20%20%20%20%20vector%3Ct%5Fparam%3E%20arr%3B%0A%20%20%20%20%
20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%7B%22%29%3B%0A%20%20%20%20%2
0%20%20%20go%5Fvec%28arr%2C%22%2C%22%29%3B%0A%20%20%20%20%20%20%20%20go%5Fconst%
28%22%7D%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Ffu
nc%5Fbody%3D%3Ei%5Fbody%7B%0A%20%20%20%20%20%20t%5Ffunc%5Fstat%3A%3At%5Fimpl%20b
ody%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28body%29%3B%
0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Foper%5Fbody%3D%3Ei%5
Fbody%7B%0A%20%20%20%20%20%20t%5Foper%5Fstat%20body%3B%0A%20%20%20%20%20%20%7B%0
A%20%20%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20
%20%20%7D%0A%20%20%20%20t%5Fstruct%5Fbody%3D%3Ei%5Fbody%7B%0A%20%20%20%20%20%20t
%5Fstruct%20body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%
28body%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fsep%20s
ep0%3B%0A%20%20%20%20t%5Fparams%20params%3B%0A%20%20%20%20t%5Fsep%20sep1%3B%0A%2
0%20%20%20TAutoPtr%3Ci%5Fbody%3E%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%2
0M%2B%3Dgo%5Fconst%28%22template%22%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8sep0%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0A%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29
%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%22%
29%3B%0A%20%20%7D%0A%7D
*/
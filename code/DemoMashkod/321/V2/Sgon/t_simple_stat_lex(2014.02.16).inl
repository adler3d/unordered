class t_simple_stat_lex{
public:
  //===>>===i_stat_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_var_stat)\
  ADD(t_struct_stat)\
  ADD(t_sep_stat)\
  ADD(t_block_stat)\
  ADD(t_expr_stat)\
  ADD(t_func_stat)\
  ADD(t_oper_stat)\
  ADD(t_ret_stat)\
  ADD(t_set_oper_stat)\
  ADD(t_postfix_oper_stat)\
  ADD(t_set_oper)\
  ADD(t_postfix_oper)\
  ADD(t_null_stat)\
  ADD(t_break_stat)\
  ADD(t_continue_stat)\
  ADD(t_for_stat)\
  ADD(t_if_stat)\
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
    virtual void Do(t_var_stat*p)=0;
    virtual void Do(t_struct_stat*p)=0;
    virtual void Do(t_sep_stat*p)=0;
    virtual void Do(t_block_stat*p)=0;
    virtual void Do(t_expr_stat*p)=0;
    virtual void Do(t_func_stat*p)=0;
    virtual void Do(t_oper_stat*p)=0;
    virtual void Do(t_ret_stat*p)=0;
    virtual void Do(t_set_oper_stat*p)=0;
    virtual void Do(t_postfix_oper_stat*p)=0;
    virtual void Do(t_null_stat*p)=0;
    virtual void Do(t_break_stat*p)=0;
    virtual void Do(t_continue_stat*p)=0;
    virtual void Do(t_for_stat*p)=0;
    virtual void Do(t_if_stat*p)=0;
    virtual void Do(t_template_stat*p)=0;
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
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_var_stat);
        F(t_struct_stat);
        F(t_sep_stat);
        F(t_block_stat);
        F(t_expr_stat);
        F(t_func_stat);
        F(t_oper_stat);
        F(t_ret_stat);
        F(t_null_stat);
        F(t_set_oper_stat);
        F(t_postfix_oper_stat);
        F(t_break_stat);
        F(t_continue_stat);
        F(t_for_stat);
        F(t_if_stat);
        F(t_template_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };

  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_char_expr)\
  ADD(t_bool_expr)\
  ADD(t_int_expr)\
  ADD(t_real_expr)\
  ADD(t_string_expr)\
  ADD(t_var_expr)\
  ADD(t_block_expr)\
  ADD(t_call_expr)\
  ADD(t_lev03)\
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
    virtual void Do(t_char_expr*p)=0;
    virtual void Do(t_bool_expr*p)=0;
    virtual void Do(t_int_expr*p)=0;
    virtual void Do(t_real_expr*p)=0;
    virtual void Do(t_string_expr*p)=0;
    virtual void Do(t_var_expr*p)=0;
    virtual void Do(t_block_expr*p)=0;
    virtual void Do(t_call_expr*p)=0;/*
    virtual void Do(t_lev03*p)=0;
    virtual void Do(t_lev05*p)=0;
    virtual void Do(t_lev06*p)=0;
    virtual void Do(t_lev07*p)=0;
    virtual void Do(t_lev08*p)=0;
    virtual void Do(t_lev09*p)=0;
    virtual void Do(t_lev10*p)=0;
    virtual void Do(t_lev11*p)=0;
    virtual void Do(t_lev12*p)=0;
    virtual void Do(t_lev13*p)=0;
    virtual void Do(t_lev14*p)=0;*/
  public:
    #define ADD(U)typedef t_simple_stat_lex::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    typedef t_simple_stat_lex::i_expr i_expr;
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_expr_visitor

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
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_char_expr);
        F(t_bool_expr);
        F(t_int_expr);
        F(t_real_expr);
        F(t_string_expr);
        F(t_var_expr);
        F(t_block_expr);
        F(t_call_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };

  class t_lev03{
  public:
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
      static const auto g_static_split_arr_0=split("+,-,!,~",",");
      O+=dev.go_any_str_from_vec(oper,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("*,/,%",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
  #define DEF_PRO_NESTED(F)F(t_oper)F(t_item)
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
        static const auto g_static_split_arr_0=split("+,-",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("<<,>>",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("<,<=,>,>=",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("==,!=",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("&",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("^",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("|",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("&&",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
        static const auto g_static_split_arr_0=split("||",",");
        D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
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
  public:
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
    class i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_val
    #include "QapGenStruct.inl"
    //<<<<<+=====i_val
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
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const string g_static_dip_0=gen_dips("19");
        M+=dev.go_any_char(first,g_static_dip_0);
        if(!ok)return ok;
        static const string g_static_dip_1=gen_dips("09");
        O+=dev.go_any(num,g_static_dip_1);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)F(t_zero)F(t_num)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_int_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_int_expr
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_type_expr{
  public:
    class t_params{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,t_int_expr,count,DEF,$,$)\
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
        D+=dev.go_str<t_type_expr>(type);
        if(!ok)return ok;
        D+=dev.go_const(",");
        if(!ok)return ok;
        D+=dev.go_auto(count);
        if(!ok)return ok;
        D+=dev.go_const("}");
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
  #define DEF_PRO_NESTED(F)F(t_params)F(t_elem)F(t_item)
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
      virtual void Do(t_type_impl*p)=0;
      virtual void Do(t_auto_impl*p)=0;
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
      virtual void Use(i_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_impl_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
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
      void Use(i_impl_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
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
  #define DEF_PRO_NESTED(F)F(t_type_impl)F(t_auto_impl)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var_stat
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_sep_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sep_stat
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_command_block{
  public:
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
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_command_block,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block_stat
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_expr_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_stat
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_char_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_char_item,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_char_expr
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_bool_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_bool_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_split_arr_0=split("true,false",",");
      D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_string_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_string_expr
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_real_expr:public i_expr{
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
        static const string g_static_dip_1=gen_dips("09");
        D+=dev.go_any(arr,g_static_dip_1);
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
        static const string g_static_dip_0="-+";
        D+=dev.go_any_char(sign,g_static_dip_0);
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
        static const string g_static_dip_0="eE";
        M+=dev.go_any_char(e,g_static_dip_0);
        if(!ok)return ok;
        O+=dev.go_auto(sign);
        if(!ok)return ok;
        static const string g_static_dip_2=gen_dips("09");
        M+=dev.go_any(arr,g_static_dip_2);
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
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const string g_static_dip_0=gen_dips("19");
        M+=dev.go_any_char(first,g_static_dip_0);
        if(!ok)return ok;
        static const string g_static_dip_1=gen_dips("09");
        O+=dev.go_any(num,g_static_dip_1);
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
  #define DEF_PRO_NESTED(F)F(t_frac)F(t_sign)F(t_exp)F(t_num)F(t_zero)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_real_expr
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
    void Use(i_visitor&A){A.Do(this);}
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
  #define DEF_PRO_NESTED(F)F(t_elem)F(t_item)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var_expr
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_block_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_lev14,body,DEF,$,$)\
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_call_param{
  public:
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
  public:
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
      virtual void Do(t_dot*p)=0;
      virtual void Do(t_colon*p)=0;
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

    //class t_visitor:public t_call_expr::i_call_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_dot*p)=0;
    //  void Do(t_colon*p)=0;
    //};

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
  #define DEF_PRO_NESTED(F)F(t_dot)F(t_colon)
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_param{
  public:
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
  public:
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
  public:
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
      static const auto g_static_split_arr_0=split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=",",");
      D+=dev.go_any_str_from_vec(oper,g_static_split_arr_0);
      if(!ok)return ok;
      D+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_set_oper_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_set_oper,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_oper_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_set_oper_stat
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_func_stat:public i_stat{
  public:
    class t_impl{
    public:
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
  #define DEF_PRO_NESTED(F)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_impl,body,DEF,$,$)\
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_visitor&A){A.Do(this);}
  public:
    string&get_type(){return body.type;}
    string&get_name(){return body.name.value;}
    t_params&get_params(){return body.params;}
    t_command_block&get_body(){return body.body;}
  };
  class t_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_name,type,DEF,$,$)\
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
      M+=dev.go_const("operator");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      static const auto g_static_split_arr_0=split(
        "=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!",
        ","
      );
      M+=dev.go_any_str_from_vec(oper,g_static_split_arr_0);
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
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    string&get_type(){return type.value;}
    string&get_name(){return oper;}
    t_params&get_params(){return params;}
    t_command_block&get_body(){return body;}
  };
  class t_ret_stat:public i_stat{
  public:
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_null_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_null_stat
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
    void Use(i_visitor&A){A.Do(this);}
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
      static const auto g_static_split_arr_0=split("++,--",",");
      D+=dev.go_any_str_from_vec(oper,g_static_split_arr_0);
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
    void Use(i_visitor&A){A.Do(this);}
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
    void Use(i_visitor&A){A.Do(this);}
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
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_for_stat:public i_stat{
  public:
    //===>>===i_next_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_set)\
    ADD(t_postfix)\
    ADDEND()

    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK

    #define DEF_PRO_BLANK()
    class i_next_visitor{
    public:
      virtual void Do(t_set*p)=0;
      virtual void Do(t_postfix*p)=0;
    public:
      #define ADD(U)typedef t_for_stat::U U;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
    };
    #undef DEF_PRO_BLANK

    #undef LIST
    //===<<===i_next_visitor

    class i_next{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_next
    #include "QapGenStruct.inl"
    //<<<<<+=====i_next
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
      virtual void Use(i_next_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
    };
    class t_set:public i_next{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set)PARENT(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_set_oper,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_set
    #include "QapGenStruct.inl"
    //<<<<<+=====t_set
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
      void Use(i_next_visitor&A){A.Do(this);}
    };
    class t_postfix:public i_next{
    public:
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix)PARENT(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_postfix_oper,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_postfix
    #include "QapGenStruct.inl"
    //<<<<<+=====t_postfix
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
      void Use(i_next_visitor&A){A.Do(this);}
    };
    class t_next{
    public:
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_next>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_postfix
    #include "QapGenStruct.inl"
    //<<<<<+=====t_postfix
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
  #define DEF_PRO_NESTED(F)F(t_next)F(t_postfix)F(t_set)
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
    void Use(i_visitor&A){A.Do(this);}
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
  #define DEF_PRO_NESTED(F)F(t_else)
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
    void Use(i_visitor&A){A.Do(this);}
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
  #define DEF_PRO_NESTED(F)F(t_field)F(t_method)
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
    void Use(i_visitor&A){A.Do(this);}
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
    public:
      //class t_static_visitor{
      //public:
      //  #define F(TYPE)typedef t_param::TYPE TYPE;
      //  F(t_type);
      //  #undef F
      //public:
      //  void Do(t_type&ref){}
      //};
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
/*
//list of types:
F(t_string);
F(t_var_stat);
F(t_sep_stat);
F(t_command_block);
F(t_block_stat);
F(t_expr_stat);
F(t_string_expr);
F(t_var_expr);
F(t_block_expr);
F(t_call_param);
F(t_call_params);
F(t_call_expr);
F(t_param);
F(t_params);
F(t_func_stat);
F(t_ret_stat);
F(t_null_stat);
F(t_template_stat);

//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fstring%7B%0A%20%20vector%3CTAutoPtr%3Ci%5Fstr%5Fitem%3E%3E%20arr%3B%0A%20%20
%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0A%20%20%20%20O%2B%3Dgo
%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0A%20%2
0%7D%0A%7D%0A%0At%5Fvar%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20t%5Fname%20type%3B%0A%20
%20t%5Fname%20name%3B%0A%20%20t%5Fstring%20value%3B%0A%20%20%7B%0A%20%20%20%20go
%5Fauto%28type%29%3B%0A%20%20%20%20go%5Fconst%28%22%20%22%29%3B%0A%20%20%20%20go
%5Fauto%28name%29%3B%0A%20%20%20%20go%5Fconst%28%22%3D%22%29%3B%0A%20%20%20%20go
%5Fauto%28value%29%3B%0A%20%20%20%20go%5Fconst%28%22%3B%22%29%3B%0A%20%20%7D%0A%
7D%0A%0At%5Fsep%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20t%5Fsep%20sep%3B%0A%20%20%7B%0A%
20%20%20%20go%5Fauto%28sep%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fcommand%5Fblock%7B%0
A%20%20vector%3CTAutoPtr%3Ci%5Fstat%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20go%
5Fauto%28arr%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fblock%5Fstat%3D%3Ei%5Fstat%7B%0A%2
0%20t%5Fcommand%5Fblock%20body%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28
%22%7B%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20M%2B%3
Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fexpr%5Fstat%3D%3Ei%5Fst
at%7B%0A%20%20TAutoPtr%3Ci%5Fexpr%3E%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fau
to%28body%29%3B%0A%20%20%20%20go%5Fconst%28%22%3B%22%29%3B%0A%20%20%7D%0A%7D%0A%
0At%5Fstring%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20t%5Fstring%20body%3B%0A%20%20%7B%0A
%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fvar%5Fexpr%3D%3Ei%
5Fexpr%7B%0A%20%20t%5Fname%20name%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28name%
29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fblock%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20TAutoPtr%
3Ci%5Fexpr%3E%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%28%22%29%3B%0
A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20go%5Fconst%28%22%29%22%29%3B%0
A%20%20%7D%0A%7D%0A%0At%5Fsum%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20TAutoPtr%3Ci%5Fexp
r%3E%20bef%3B%0A%20%20TAutoPtr%3Ci%5Fexpr%3E%20aft%3B%0A%20%20%7B%0A%20%20%20%20
go%5Fauto%28bef%29%3B%0A%20%20%20%20go%5Fconst%28%22%2B%22%29%3B%0A%20%20%20%20g
o%5Fauto%28aft%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fcall%5Fparam%7B%0A%20%20TAutoPtr
%3Ci%5Fexpr%3E%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%
20%7D%0A%7D%0A%0At%5Fcall%5Fcomma%5Fparam%7B%0A%20%20t%5Fcall%5Fparam%20param%3B
%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%2C%22%29%3B%0A%20%20%20%20go%5Fauto%
28param%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fcall%5Fparams%7B%0A%20%20t%5Fcall%5Fpar
am%20first%3B%0A%20%20vector%3Ct%5Fcall%5Fcomma%5Fparam%3E%20arr%3B%0A%20%20%7B%
0A%20%20%20%20M%2B%3Dgo%5Fauto%28first%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28ar
r%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fcall%5Fexpr%3D%3Ei%5Fexpr%7B%0A%20%20t%5Fname
%20func%3B%0A%20%20t%5Fcall%5Fparams%20params%3B%0A%20%20%7B%0A%20%20%20%20M%2B%
3Dgo%5Fauto%28func%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0A%20
%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%2
9%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fparam%7B%0A%20%20t%5Fname%20type%3B%0A%20%
20t%5Fname%20name%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28type%29%3B%0A%20%20%2
0%20go%5Fconst%28%22%20%22%29%3B%0A%20%20%20%20go%5Fauto%28name%29%3B%0A%20%20%7
D%0A%7D%0A%0At%5Fcomma%5Fparam%7B%0A%20%20t%5Fparam%20body%3B%0A%20%20%7B%0A%20%
20%20%20go%5Fauto%28%22%2C%22%29%3B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%2
0%7D%0A%7D%0A%0At%5Fparams%7B%0A%20%20t%5Fparam%20first%3B%0A%20%20vector%3Ct%5F
comma%5Fparam%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28first%29%
3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Ffunc%5F
body%7B%0A%20%20vector%3CTAutoPtr%3Ci%5Fstat%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20
%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%2
9%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%
5Ffunc%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20t%5Fname%20type%3B%0A%20%20t%5Fname%20nam
e%3B%0A%20%20TAutoPtr%3Ct%5Fparams%3E%20params%3B%0A%20%20t%5Fsep%20sep%3B%0A%20
%20t%5Ffunc%5Fbody%20body%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28type%2
9%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%20%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5
Fauto%28name%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0A%20%20%20
%20M%2B%3Dgo%5Fauto%28params%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%2
9%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%2
8body%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fret%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20TAuto
Ptr%3Ci%5Fexpr%3E%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22return%20%
22%29%3B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%20%20go%5Fconst%28%22%3B%
22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fnull%5Fstat%3D%3Ei%5Fstat%7B%0A%20%20%7B%0A%
20%20%20%20go%5Fconst%28%22%3B%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fsetadd%5Fstat
%3D%3Ei%5Fstat%7B%0A%20%20t%5Fname%20name%3B%0A%20%20TAutoPtr%3Ci%5Fexpr%3E%20va
lue%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28name%29%3B%0A%20%20%20%20go%5Fconst
%28%22%2B%3D%22%29%3B%0A%20%20%20%20go%5Fauto%28value%29%3B%0A%20%20%20%20go%5Fc
onst%28%22%3B%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fset%5Fstat%3D%3Ei%5Fstat%7B%0A
%20%20t%5Fname%20name%3B%0A%20%20TAutoPtr%3Ci%5Fexpr%3E%20value%3B%0A%20%20%7B%0
A%20%20%20%20go%5Fauto%28name%29%3B%0A%20%20%20%20go%5Fconst%28%22%3D%22%29%3B%0
A%20%20%20%20go%5Fauto%28value%29%3B%0A%20%20%20%20go%5Fconst%28%22%3B%22%29%3B%
0A%20%20%7D%0A%7D
*/
public:
#define DEF_PRO_NESTED(F)\
  F(t_string)\
  F(t_var_stat)\
  F(t_struct_stat)\
  F(t_sep_stat)\
  F(t_command_block)\
  F(t_block_stat)\
  F(t_expr_stat)\
  F(t_char_expr)\
  F(t_bool_expr)\
  F(t_int_expr)\
  F(t_string_expr)\
  F(t_var_expr)\
  F(t_block_expr)\
  F(t_call_param)\
  F(t_call_params)\
  F(t_call_expr)\
  F(t_param)\
  F(t_params)\
  F(t_func_stat)\
  F(t_oper_stat)\
  F(t_ret_stat)\
  F(t_null_stat)\
  F(t_set_oper_stat)\
  F(t_postfix_oper)\
  F(t_postfix_oper_stat)\
  F(i_stat)\
  F(i_expr)\
  F(t_continue_stat)\
  F(t_break_stat)\
  F(t_for_stat)\
  F(t_if_stat)\
  F(t_lev03)\
  F(t_lev05)\
  F(t_lev06)\
  F(t_lev07)\
  F(t_lev08)\
  F(t_lev09)\
  F(t_lev10)\
  F(t_lev11)\
  F(t_lev12)\
  F(t_lev13)\
  F(t_lev14)\
  F(t_struct)\
  F(t_sep_struct)\
  F(t_type_expr)\
  F(t_template_stat)
public:
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
    O+=dev.go_const("not used at all!");
    if(!ok)return ok;
    return ok;
  }
};
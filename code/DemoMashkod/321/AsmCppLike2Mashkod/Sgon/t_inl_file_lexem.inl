//time = 153.23 ms.

class t_inl_file{
public:
  //===>>===i_class_stat_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_access_mod_class_stat)\
  ADD(t_fv_class_stat)\
  ADD(t_typedef_class_stat)\
  ADD(t_dtor_class_stat)\
  ADD(t_ctor_class_stat)\
  ADD(t_oper_cast_class_stat)\
  ADD(t_common_oper_class_stat)\
  ADD(t_namespace_class_stat)\
  ADD(t_template_class_stat)\
  ADD(t_enum_class_stat)\
  ADD(t_using_class_stat)\
  ADD(t_pragma_class_stat)\
  ADD(t_include_class_stat)\
  ADD(t_preproc_if_class_stat)\
  ADD(t_preproc_else_class_stat)\
  ADD(t_preproc_endif_class_stat)\
  ADD(t_define_class_stat)\
  ADD(t_undef_class_stat)\
  ADD(t_sep_class_stat)\
  ADD(t_null_class_stat)\
  ADD(t_class_class_stat)\
  ADDEND()

  class i_class_stat;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_class_stat_visitor{
  public:
    typedef t_inl_file::i_class_stat i_class_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_class_stat*p){
      if(!p)return nullptr;Is<TYPE,i_class_stat_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK
  #undef LIST
public:
  class i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_class_stat
  public:
    typedef i_class_stat_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_access_mod_class_stat);
        F(t_fv_class_stat);
        F(t_typedef_class_stat);
        F(t_dtor_class_stat);
        F(t_ctor_class_stat);
        F(t_oper_cast_class_stat);
        F(t_common_oper_class_stat);
        F(t_namespace_class_stat);
        F(t_template_class_stat);
        F(t_enum_class_stat);
        F(t_using_class_stat);
        F(t_pragma_class_stat);
        F(t_include_class_stat);
        F(t_preproc_if_class_stat);
        F(t_preproc_else_class_stat);
        F(t_preproc_endif_class_stat);
        F(t_define_class_stat);
        F(t_undef_class_stat);
        F(t_sep_class_stat);
        F(t_null_class_stat);
        F(t_class_class_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_block_expr)\
  ADD(t_bool_expr)\
  ADD(t_string_expr)\
  ADD(t_char_expr)\
  ADD(t_num_expr)\
  ADD(t_real_expr)\
  ADD(t_nullptr_expr)\
  ADD(t_or_expr)\
  ADD(t_hex_expr)\
  ADD(t_var_expr)\
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
    typedef t_inl_file::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;
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
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_expr
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_block_expr);
        F(t_bool_expr);
        F(t_string_expr);
        F(t_char_expr);
        F(t_num_expr);
        F(t_real_expr);
        F(t_nullptr_expr);
        F(t_or_expr);
        F(t_hex_expr);
        F(t_var_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_func_body_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_zero_func_body)\
  ADD(t_null_func_body)\
  ADD(t_delete_func_body)\
  ADD(t_impl_func_body)\
  ADDEND()

  class i_func_body;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_func_body_visitor{
  public:
    typedef t_inl_file::i_func_body i_func_body;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_func_body*p){
      if(!p)return nullptr;Is<TYPE,i_func_body_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK
  #undef LIST
public:
  class i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_func_body
  public:
    typedef i_func_body_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_zero_func_body);
        F(t_null_func_body);
        F(t_delete_func_body);
        F(t_impl_func_body);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_tmpl_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_call_tmpl_expr)\
  ADD(t_block_tmpl_expr)\
  ADD(t_bool_tmpl_expr)\
  ADD(t_string_tmpl_expr)\
  ADD(t_char_tmpl_expr)\
  ADD(t_num_tmpl_expr)\
  ADD(t_real_tmpl_expr)\
  ADD(t_nullptr_tmpl_expr)\
  ADD(t_or_tmpl_expr)\
  ADD(t_hex_tmpl_expr)\
  ADD(t_var_tmpl_expr)\
  ADDEND()

  class i_tmpl_expr;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_tmpl_expr_visitor{
  public:
    typedef t_inl_file::i_tmpl_expr i_tmpl_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_tmpl_expr*p){
      if(!p)return nullptr;Is<TYPE,i_tmpl_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK
  #undef LIST
public:
  class i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_tmpl_expr
  public:
    typedef i_tmpl_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_call_tmpl_expr);
        F(t_block_tmpl_expr);
        F(t_bool_tmpl_expr);
        F(t_string_tmpl_expr);
        F(t_char_tmpl_expr);
        F(t_num_tmpl_expr);
        F(t_real_tmpl_expr);
        F(t_nullptr_tmpl_expr);
        F(t_or_tmpl_expr);
        F(t_hex_tmpl_expr);
        F(t_var_tmpl_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_concrete_param_way_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_pfunc_concrete_param_way)\
  ADD(t_type_concrete_param_way)\
  ADD(t_expr_concrete_param_way)\
  ADDEND()

  class i_concrete_param_way;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_concrete_param_way_visitor{
  public:
    typedef t_inl_file::i_concrete_param_way i_concrete_param_way;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_concrete_param_way*p){
      if(!p)return nullptr;Is<TYPE,i_concrete_param_way_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK
  #undef LIST
public:
  class i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_concrete_param_way
  public:
    typedef i_concrete_param_way_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_pfunc_concrete_param_way);
        F(t_type_concrete_param_way);
        F(t_expr_concrete_param_way);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  class t_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,oper,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev03
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev03
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("&,*,+,-,!,~",","));
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev03,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev03,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev05
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev05,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev05,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev06
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<<,>>",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev07)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev06,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev06,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev07
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<,<=,>,>=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev08)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev07,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev07,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev08
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("==,!=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev08,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev09)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev08,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev09
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev09,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev10)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev09,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev10
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("^",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev10,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev11)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev10,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev11
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("|",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev11,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev12)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev11,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev12
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev12,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev13)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev12,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev13
  #include "QapGenStructNoTemplate.inl"
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
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("||",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev13,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev14)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev13,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev14
  #include "QapGenStructNoTemplate.inl"
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
  class t_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_expr
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
  class t_tmpl_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev03)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,oper,DEF,$,$)\
  ADDVAR(TAutoPtr<i_tmpl_expr>,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev03
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev03
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("&,*,+,-,!,~",","));
      O+=dev.go_any_str_from_vec(oper,g_static_var_0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_tmpl_lev05{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev03,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev05)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev03,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev05
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev05
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
  class t_tmpl_lev06{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev05,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev06)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev05,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev06
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev06
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
  class t_tmpl_lev09{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("==,!=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev06,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev09)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev06,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev09
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev09
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
  class t_tmpl_lev10{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev09,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev10)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev09,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev10
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev10
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
  class t_tmpl_lev11{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("^",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev10,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev11)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev10,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev11
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev11
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
  class t_tmpl_lev12{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("|",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev11,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev12)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev11,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev12
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev12
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
  class t_tmpl_lev13{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev12,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev13)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev12,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev13
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev13
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
  class t_tmpl_lev14{
  public:
    class t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("||",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev13,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev14)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev13,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev14
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev14
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
  class t_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_expr
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
  class t_concrete_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_concrete_param)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<i_concrete_param_way>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_concrete_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_concrete_param
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
  class t_concrete_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_concrete_params)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_concrete_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_concrete_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_concrete_params
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("<");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(">");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_access_mod{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_access_mod)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_access_mod
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_access_mod
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("public,protected,private",","));
      D+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_access_mod_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_access_mod_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_access_mod,mod,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_access_mod_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_access_mod_class_stat
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
      M+=dev.go_auto(mod);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const(":");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_raw_func_body{
  public:
    //===>>===i_item_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_sep_item)\
    ADD(t_s_item)\
    ADD(t_c_item)\
    ADD(t_code_item)\
    ADD(t_div_item)\
    ADD(t_block_item)\
    ADDEND()
  
    class i_item;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_item_visitor{
    public:
      typedef t_raw_func_body::i_item i_item;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_raw_func_body::U U;
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
      static TYPE*UberCast(i_item*p){
        if(!p)return nullptr;Is<TYPE,i_item_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
    #undef LIST
  public:
    class i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_item
    public:
      typedef i_item_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load()
        {
          F(t_sep_item);
          F(t_s_item);
          F(t_c_item);
          F(t_code_item);
          F(t_div_item);
          F(t_block_item);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    class t_sep_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_sep_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_sep_item
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
    class t_s_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_s_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_s_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_s_item
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
        D+=dev.go_str<t_str_item::t_impl>(value);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_c_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_c_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_c_item
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
        D+=dev.go_str<t_char_item::t_impl>(value);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_code_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,code,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_code_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_code_item
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
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");
        D+=dev.go_any(code,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_div_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_div_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_div_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_div_item
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
        D+=dev.go_const("/");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_block_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_raw_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_block_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_block_item
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
    F(t_sep_item  )\
    F(t_s_item    )\
    F(t_c_item    )\
    F(t_code_item )\
    F(t_div_item  )\
    F(t_block_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw_func_body
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
  public:
  };
  class t_func_path{
  public:
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_func_path)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_str<t_name>(value);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("::");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_path)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_func_path
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_func_path
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_const_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const_with_sep)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_const_with_sep
  #include "QapGenStructNoTemplate.inl"
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
      static const auto g_static_var_1=QapStrFinder::fromArr(split("typename,const,unsigned",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_keyword{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_keyword)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_keyword
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_keyword
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("friend,typename,extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_callconv{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_callconv)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_callconv
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_callconv
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("__cdecl,__stdcall,__fastcall,__thiscall,__vectorcall",","));
      M+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr
  #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ref)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,ref,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ref
  #include "QapGenStructNoTemplate.inl"
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
  class t_type_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_with_sep)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_with_sep
  #include "QapGenStructNoTemplate.inl"
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
      O+=dev.go_auto(concrete_params);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_scope_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope_with_sep)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope_with_sep
  #include "QapGenStructNoTemplate.inl"
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
    #include "QapGenStructNoTemplate.inl"
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scopes)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_with_sep,first,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scopes
  #include "QapGenStructNoTemplate.inl"
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
  class t_global{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_global)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_global
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_global
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_raw_type_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_type_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_global>,global,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_scopes,scopes,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_type_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw_type_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(global);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(scopes);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_arr_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDVAR(t_sep,sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_arr_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_arr_body
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_const("[");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      M+=dev.go_const("]");
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_fv_class_stat:public i_class_stat{
  public:
    class t_type_expr{
    public:
      //===>>===i_name_part_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_raw_name_part)\
      ADD(t_brackets_name_part)\
      ADDEND()
    
      class i_name_part;
    
      #define DEF_PRO_BLANK()
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      #undef DEF_PRO_BLANK
    
      #define DEF_PRO_BLANK()
      class i_name_part_visitor{
      public:
        typedef t_type_expr::i_name_part i_name_part;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_type_expr::U U;
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
        static TYPE*UberCast(i_name_part*p){
          if(!p)return nullptr;Is<TYPE,i_name_part_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
      #undef DEF_PRO_BLANK
      #undef LIST
    public:
      class i_name_part{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_name_part
      public:
        typedef i_name_part_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          bool load()
          {
            F(t_raw_name_part);
            F(t_brackets_name_part);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
    public:
      //===>>===i_func_param_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_pfunc_func_param)\
      ADD(t_var_args_func_param)\
      ADD(t_type_func_param)\
      ADD(t_expr_func_param)\
      ADDEND()
    
      class i_func_param;
    
      #define DEF_PRO_BLANK()
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      #undef DEF_PRO_BLANK
    
      #define DEF_PRO_BLANK()
      class i_func_param_visitor{
      public:
        typedef t_type_expr::i_func_param i_func_param;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_type_expr::U U;
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
        static TYPE*UberCast(i_func_param*p){
          if(!p)return nullptr;Is<TYPE,i_func_param_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
      #undef DEF_PRO_BLANK
      #undef LIST
    public:
      class i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_func_param
      public:
        typedef i_func_param_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          bool load()
          {
            F(t_pfunc_func_param);
            F(t_var_args_func_param);
            F(t_type_func_param);
            F(t_expr_func_param);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
    public:
      //===>>===i_typeexpr_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_impl_typeexpr)\
      ADD(t_decl_typeexpr)\
      ADDEND()
    
      class i_typeexpr;
    
      #define DEF_PRO_BLANK()
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      #undef DEF_PRO_BLANK
    
      #define DEF_PRO_BLANK()
      class i_typeexpr_visitor{
      public:
        typedef t_type_expr::i_typeexpr i_typeexpr;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_type_expr::U U;
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
        static TYPE*UberCast(i_typeexpr*p){
          if(!p)return nullptr;Is<TYPE,i_typeexpr_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
      #undef DEF_PRO_BLANK
      #undef LIST
    public:
      class i_typeexpr{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_typeexpr
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_typeexpr
      public:
        typedef i_typeexpr_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          bool load()
          {
            F(t_impl_typeexpr);
            F(t_decl_typeexpr);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
      class t_type_expr_with_sep_and_cv{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr_with_sep_and_cv)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(vector<t_const_with_sep>,cvs,DEF,$,$)\
      ADDVAR(TAutoPtr<t_type_expr>,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_type_expr_with_sep_and_cv
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_type_expr_with_sep_and_cv
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(cvs);
          if(!ok)return ok;
          M+=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_name_part{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<i_name_part>,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_name_part
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
      class t_raw_name_part:public i_name_part{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_name_part)PARENT(i_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(string,name,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_raw_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_raw_name_part
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
          D+=dev.go_str<t_name>(name);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_brackets_name_part:public i_name_part{
      public:
        //===>>===i_part_visitor
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
        ADD(t_amp_part)\
        ADD(t_star_part)\
        ADDEND()
      
        class i_part;
      
        #define DEF_PRO_BLANK()
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        #undef DEF_PRO_BLANK
      
        #define DEF_PRO_BLANK()
        class i_part_visitor{
        public:
          typedef t_brackets_name_part::i_part i_part;
        public:
          #define ADD(TYPE)virtual void Do(TYPE*p)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_brackets_name_part::U U;
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
          static TYPE*UberCast(i_part*p){
            if(!p)return nullptr;Is<TYPE,i_part_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
        #undef DEF_PRO_BLANK
        #undef LIST
      public:
        class i_part{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_part)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_part
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====i_part
        public:
          typedef i_part_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            bool load()
            {
              F(t_amp_part);
              F(t_star_part);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }
            #include "QapLexPolyEndNoTemplate.inl"
          };
        };
        class t_amp{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_amp)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(string,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_amp
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_amp
        public:
          bool go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            static const auto g_static_var_0=QapStrFinder::fromArr(split("&,&&",","));
            D+=dev.go_any_str_from_vec(body,g_static_var_0);
            if(!ok)return ok;
            return ok;
          }
        };
        class t_amp_part:public i_part{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_amp_part)PARENT(i_part)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_amp,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_amp_part
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_amp_part
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
        class t_star_part:public i_part{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_star_part)PARENT(i_part)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(string,stars,DEF,$,$)\
        ADDVAR(TAutoPtr<t_amp>,amp,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_star_part
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_star_part
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
            static const auto g_static_var_0=CharMask::fromStr("*");
            M+=dev.go_any(stars,g_static_var_0);
            if(!ok)return ok;
            O+=dev.go_auto(amp);
            if(!ok)return ok;
            return ok;
          }
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_amp      )\
        F(t_amp_part )\
        F(t_star_part)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_brackets_name_part)PARENT(i_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<i_part>,stamp_part,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(TAutoPtr<t_name_part>,namepart,DEF,$,$)\
      ADDVAR(TAutoPtr<t_arr_body>,arrbody,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_brackets_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_brackets_name_part
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
          M+=dev.go_const("(");
          if(!ok)return ok;
          M+=dev.go_auto(stamp_part);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          O+=dev.go_auto(namepart);
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          O+=dev.go_auto(arrbody);
          if(!ok)return ok;
          return ok;
        }
      public:
      };
      class t_func_param_value{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_param_value)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(t_expr,value,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_func_param_value
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_func_param_value
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("=");
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_auto(value);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(TAutoPtr<i_func_param>,body,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(TAutoPtr<t_func_param_value>,value,DEF,$,$)\
      ADDVAR(t_sep,sep2,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_func_param
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
          O+=dev.go_auto(value);
          if(!ok)return ok;
          O+=dev.go_auto(sep2);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_func_params{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_params)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(vector<t_func_param>,arr,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_func_params
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_func_params
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_const("(");
          if(!ok)return ok;
          O+=dev.go_vec(arr,",");
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          return ok;
        }
      };
      class t_pfunc{
      public:
        class t_addr{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_addr)OWNER(t_pfunc)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_type_expr_with_sep_and_cv,type,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_addr
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_addr
        public:
          bool go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_auto(type);
            if(!ok)return ok;
            M+=dev.go_const("::");
            if(!ok)return ok;
            return ok;
          }
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_addr)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pfunc)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_type_expr_with_sep_and_cv,type,DEF,$,$)\
      ADDVAR(t_addr,addr,DEF,$,$)\
      ADDVAR(string,name,DEF,$,$)\
      ADDVAR(t_func_params,params,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_pfunc
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_pfunc
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(type);
          if(!ok)return ok;
          M+=dev.go_const("(");
          if(!ok)return ok;
          O+=dev.go_auto(addr);
          if(!ok)return ok;
          M+=dev.go_const("*");
          if(!ok)return ok;
          O+=dev.go_str<t_name>(name);
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          M+=dev.go_auto(params);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_pfunc_func_param:public i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pfunc_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_pfunc,value,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_pfunc_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_pfunc_func_param
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
          D+=dev.go_auto(value);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_var_args_func_param:public i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_args_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_var_args_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_var_args_func_param
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
          D+=dev.go_const("...");
          if(!ok)return ok;
          return ok;
        }
      };
      class t_type_func_param:public i_func_param{
      public:
        class t_const{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const)OWNER(t_type_func_param)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_sep,sep,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_const
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_const
        public:
          bool go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_const("const");
            if(!ok)return ok;
            O+=dev.go_auto(sep);
            if(!ok)return ok;
            return ok;
          }
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_const)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_type_expr_with_sep_and_cv,type,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(TAutoPtr<t_const>,cv,DEF,$,$)\
      ADDVAR(TAutoPtr<t_name_part>,namepart,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_type_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_type_func_param
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
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          O+=dev.go_auto(cv);
          if(!ok)return ok;
          O+=dev.go_auto(namepart);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_expr_func_param:public i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_expr,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_expr_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_expr_func_param
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
          D+=dev.go_minor<t_type_func_param>(body);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_fv_stat{
      public:
        //===>>===i_fv_body_visitor
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
        ADD(t_impl_func_body)\
        ADD(t_zero_func_body)\
        ADD(t_delete_func_body)\
        ADDEND()
      
        class i_fv_body;
      
        #define DEF_PRO_BLANK()
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        #undef DEF_PRO_BLANK
      
        #define DEF_PRO_BLANK()
        class i_fv_body_visitor{
        public:
          typedef t_fv_stat::i_fv_body i_fv_body;
        public:
          #define ADD(TYPE)virtual void Do(TYPE*p)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_fv_stat::U U;
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
          static TYPE*UberCast(i_fv_body*p){
            if(!p)return nullptr;Is<TYPE,i_fv_body_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
        #undef DEF_PRO_BLANK
        #undef LIST
      public:
        class i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_fv_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====i_fv_body
        public:
          typedef i_fv_body_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            bool load()
            {
              F(t_impl_func_body);
              F(t_zero_func_body);
              F(t_delete_func_body);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }
            #include "QapLexPolyEndNoTemplate.inl"
          };
        };
      public:
        //===>>===i_fv_end_visitor
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
        ADD(t_func_fv_end)\
        ADD(t_var_fv_end)\
        ADDEND()
      
        class i_fv_end;
      
        #define DEF_PRO_BLANK()
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        #undef DEF_PRO_BLANK
      
        #define DEF_PRO_BLANK()
        class i_fv_end_visitor{
        public:
          typedef t_fv_stat::i_fv_end i_fv_end;
        public:
          #define ADD(TYPE)virtual void Do(TYPE*p)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_fv_stat::U U;
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
          static TYPE*UberCast(i_fv_end*p){
            if(!p)return nullptr;Is<TYPE,i_fv_end_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
        #undef DEF_PRO_BLANK
        #undef LIST
      public:
        class i_fv_end{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_fv_end)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_fv_end
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====i_fv_end
        public:
          typedef i_fv_end_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            bool load()
            {
              F(t_func_fv_end);
              F(t_var_fv_end);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }
            #include "QapLexPolyEndNoTemplate.inl"
          };
        };
        class t_impl_func_body:public i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_func_body)PARENT(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_sep,sep,DEF,$,$)\
        ADDVAR(t_raw_func_body,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_impl_func_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_impl_func_body
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
            O+=dev.go_auto(sep);
            if(!ok)return ok;
            M+=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
        };
        class t_zero_func_body:public i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero_func_body)PARENT(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_zero_func_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_zero_func_body
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
            D+=dev.go_const("=0;");
            if(!ok)return ok;
            return ok;
          }
        };
        class t_delete_func_body:public i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_delete_func_body)PARENT(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_delete_func_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_delete_func_body
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
            D+=dev.go_const("=delete;");
            if(!ok)return ok;
            return ok;
          }
        };
        class t_func_fv_end:public i_fv_end{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_fv_end)PARENT(i_fv_end)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(TAutoPtr<t_func_params>,params,DEF,$,$)\
        ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
        ADDVAR(t_sep,sep1,DEF,$,$)\
        ADDVAR(TAutoPtr<i_fv_body>,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_func_fv_end
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_func_fv_end
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
            M+=dev.go_auto(params);
            if(!ok)return ok;
            O+=dev.go_auto(cv1);
            if(!ok)return ok;
            O+=dev.go_auto(sep1);
            if(!ok)return ok;
            M+=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
        };
        class t_var_fv_end:public i_fv_end{
        public:
          //===>>===i_fv_item_visitor
          #define LIST(ADDBEG,ADD,ADDEND)\
          ADDBEG()\
          ADD(t_func_fv_item)\
          ADD(t_var_fv_item)\
          ADDEND()
        
          class i_fv_item;
        
          #define DEF_PRO_BLANK()
          #define ADD(TYPE)class TYPE;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
          #undef DEF_PRO_BLANK
        
          #define DEF_PRO_BLANK()
          class i_fv_item_visitor{
          public:
            typedef t_var_fv_end::i_fv_item i_fv_item;
          public:
            #define ADD(TYPE)virtual void Do(TYPE*p)=0;
            LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
            #undef ADD
          public:
            #define ADD(U)typedef t_var_fv_end::U U;
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
            static TYPE*UberCast(i_fv_item*p){
              if(!p)return nullptr;Is<TYPE,i_fv_item_visitor> IS;p->Use(IS);return IS.ptr;
            }
          };
          #undef DEF_PRO_BLANK
          #undef LIST
        public:
          class i_fv_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_fv_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDEND()
          //=====+>>>>>i_fv_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====i_fv_item
          public:
            typedef i_fv_item_visitor i_visitor;
            virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
          public:
            virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
              #include "QapLexPolyBeg.inl"
              bool load()
              {
                F(t_func_fv_item);
                F(t_var_fv_item);
                (void)count;(void)first_id;(void)out_arr;(void)this;
                main();
                return scope.ok;
              }
              #include "QapLexPolyEndNoTemplate.inl"
            };
          };
          class t_func_fv_item:public i_fv_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_fv_item)PARENT(i_fv_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(TAutoPtr<t_func_params>,params,DEF,$,$)\
          ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_func_fv_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_func_fv_item
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
              M+=dev.go_auto(params);
              if(!ok)return ok;
              O+=dev.go_auto(cv1);
              if(!ok)return ok;
              return ok;
            }
          };
          class t_var_fv_item:public i_fv_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_fv_item)PARENT(i_fv_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(TAutoPtr<t_arr_body>,arrbody,DEF,$,$)\
          ADDVAR(TAutoPtr<t_func_param_value>,value,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_var_fv_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_var_fv_item
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
              O+=dev.go_auto(arrbody);
              if(!ok)return ok;
              O+=dev.go_auto(value);
              if(!ok)return ok;
              return ok;
            }
          };
          class t_body{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_body)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(TAutoPtr<i_fv_item>,body,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_body
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_body
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
          class t_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(t_sep,sep0,DEF,$,$)\
          ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
          ADDVAR(t_sep,sep1,DEF,$,$)\
          ADDVAR(string,name,DEF,$,$)\
          ADDVAR(t_sep,sep2,DEF,$,$)\
          ADDVAR(t_body,body,DEF,$,$)\
          ADDVAR(t_sep,sep3,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_item
          public:
            bool go(i_dev&dev){
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              M+=dev.go_const(",");
              if(!ok)return ok;
              O+=dev.go_auto(sep0);
              if(!ok)return ok;
              O+=dev.go_auto(cv);
              if(!ok)return ok;
              O+=dev.go_auto(sep1);
              if(!ok)return ok;
              M+=dev.go_str<t_name>(name);
              if(!ok)return ok;
              O+=dev.go_auto(sep2);
              if(!ok)return ok;
              M+=dev.go_auto(body);
              if(!ok)return ok;
              O+=dev.go_auto(sep3);
              if(!ok)return ok;
              return ok;
            }
          };
        public:
        #define DEF_PRO_NESTED(F)\
          /*<DEF_PRO_NESTED>*/\
          F(t_func_fv_item)\
          F(t_var_fv_item )\
          F(t_body        )\
          F(t_item        )\
          /*</DEF_PRO_NESTED>*/
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_fv_end)PARENT(i_fv_end)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(TAutoPtr<t_body>,body,DEF,$,$)\
        ADDVAR(vector<t_item>,arr,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_var_fv_end
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_var_fv_end
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
            O+=dev.go_auto(body);
            if(!ok)return ok;
            O+=dev.go_auto(arr);
            if(!ok)return ok;
            M+=dev.go_const(";");
            if(!ok)return ok;
            return ok;
          }
        public:
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_impl_func_body  )\
        F(t_zero_func_body  )\
        F(t_delete_func_body)\
        F(t_func_fv_end     )\
        F(t_var_fv_end      )\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fv_stat)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep_wa,DEF,$,$)\
      ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
      ADDVAR(TAutoPtr<t_type_expr>,type,DEF,$,$)\
      ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
      ADDVAR(TAutoPtr<t_callconv>,callconv,DEF,$,$)\
      ADDVAR(t_name_part,name,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(TAutoPtr<i_fv_end>,way,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_fv_stat
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_fv_stat
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep_wa);
          if(!ok)return ok;
          O+=dev.go_auto(keywords);
          if(!ok)return ok;
          M+=dev.go_auto(type);
          if(!ok)return ok;
          O+=dev.go_auto(cv);
          if(!ok)return ok;
          O+=dev.go_auto(sep0);
          if(!ok)return ok;
          O+=dev.go_auto(path);
          if(!ok)return ok;
          O+=dev.go_auto(callconv);
          if(!ok)return ok;
          M+=dev.go_auto(name);
          if(!ok)return ok;
          O+=dev.go_auto(sep1);
          if(!ok)return ok;
          M+=dev.go_auto(way);
          if(!ok)return ok;
          return ok;
        }
      public:
      };
      class t_impl_typeexpr:public i_typeexpr{
      public:
        class t_global{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_global)OWNER(t_impl_typeexpr)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_global
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_global
        public:
          bool go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_const("::");
            if(!ok)return ok;
            return ok;
          }
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_global)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_typeexpr)PARENT(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<t_global>,global,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(t_scopes,scopes,DEF,$,$)\
      ADDVAR(vector<t_ptr>,ptrs,DEF,$,$)\
      ADDVAR(TAutoPtr<t_ref>,ref,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_impl_typeexpr
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_impl_typeexpr
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
          O+=dev.go_auto(global);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_auto(scopes);
          if(!ok)return ok;
          O+=dev.go_auto(ptrs);
          if(!ok)return ok;
          O+=dev.go_auto(ref);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_decl_typeexpr:public i_typeexpr{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_decl_typeexpr)PARENT(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(t_expr,expr,DEF,$,$)\
      ADDVAR(t_sep,sep2,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_decl_typeexpr
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_decl_typeexpr
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
          M+=dev.go_const("decltype");
          if(!ok)return ok;
          O+=dev.go_auto(sep0);
          if(!ok)return ok;
          M+=dev.go_const("(");
          if(!ok)return ok;
          O+=dev.go_auto(sep1);
          if(!ok)return ok;
          M+=dev.go_auto(expr);
          if(!ok)return ok;
          O+=dev.go_auto(sep2);
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_type_expr_with_sep_and_cv)\
      F(t_name_part                )\
      F(t_raw_name_part            )\
      F(t_brackets_name_part       )\
      F(t_func_param_value         )\
      F(t_func_param               )\
      F(t_func_params              )\
      F(t_pfunc                    )\
      F(t_pfunc_func_param         )\
      F(t_var_args_func_param      )\
      F(t_type_func_param          )\
      F(t_expr_func_param          )\
      F(t_fv_stat                  )\
      F(t_impl_typeexpr            )\
      F(t_decl_typeexpr            )\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)OWNER(t_fv_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_typeexpr>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_expr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_type_expr
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
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_type_expr)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fv_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_expr::t_fv_stat,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_fv_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fv_class_stat
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
  class t_typedef_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_typedef_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr::t_fv_stat,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_typedef_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_typedef_class_stat
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
      M+=dev.go_const("typedef");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_real{
  public:
    class t_f{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_f)OWNER(t_real)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_f
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_f
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr("fF");
        D+=dev.go_any_char(body,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_f)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,bef,DEF,$,$)\
  ADDVAR(string,aft,DEF,$,$)\
  ADDVAR(TAutoPtr<t_f>,ext,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_real
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      M+=dev.go_any(bef,g_static_var_0);
      if(!ok)return ok;
      M+=dev.go_const(".");
      if(!ok)return ok;
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
      O+=dev.go_any(aft,g_static_var_2);
      if(!ok)return ok;
      O+=dev.go_auto(ext);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_param)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_param
  #include "QapGenStructNoTemplate.inl"
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
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_params)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_params
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_expr
  #include "QapGenStructNoTemplate.inl"
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
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_bool_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool_expr
  #include "QapGenStructNoTemplate.inl"
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_string_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string_expr
  #include "QapGenStructNoTemplate.inl"
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
      D+=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_char_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_expr
  #include "QapGenStructNoTemplate.inl"
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
      D+=dev.go_str<t_char_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_num_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_expr
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
      D+=dev.go_any(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_real_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real_expr
  #include "QapGenStructNoTemplate.inl"
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
      D+=dev.go_str<t_real>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_nullptr_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nullptr_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_nullptr_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_nullptr_expr
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
      D+=dev.go_const("nullptr");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_or_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_or_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_name>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_or_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_or_expr
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
      D+=dev.go_bin_oper(arr,"|");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_hex_expr:public i_expr{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_hex_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,x,DEF,$,$)\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("0");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        D+=dev.go_any_char(x,g_static_var_1);
        if(!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        D+=dev.go_any(value,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hex_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hex_expr
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
      D+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_var_expr:public i_expr{
  public:
    //===>>===i_ext_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_arr_ext)\
    ADD(t_call_ext)\
    ADD(t_tmpl_ext)\
    ADDEND()
  
    class i_ext;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_ext_visitor{
    public:
      typedef t_var_expr::i_ext i_ext;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_var_expr::U U;
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
      static TYPE*UberCast(i_ext*p){
        if(!p)return nullptr;Is<TYPE,i_ext_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
    #undef LIST
  public:
    class i_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_ext)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_ext
    public:
      typedef i_ext_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load()
        {
          F(t_arr_ext);
          F(t_call_ext);
          F(t_tmpl_ext);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    class t_arr_ext:public i_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr_ext)PARENT(i_ext)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_arr_body,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_arr_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_arr_ext
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
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_call_ext:public i_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_ext)PARENT(i_ext)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(vector<t_call_params>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_call_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_call_ext
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
        O+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_tmpl_ext:public i_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_ext)PARENT(i_ext)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_tmpl_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_tmpl_ext
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
        M+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_part{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_part)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,bef,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,aft,DEF,$,$)\
    ADDVAR(TAutoPtr<i_ext>,ext,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_part
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(bef);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(aft);
        if(!ok)return ok;
        O+=dev.go_auto(ext);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_step{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_step)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_part,part,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_step
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_step
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        static const auto g_static_var_1=QapStrFinder::fromArr(split("->,.,::",","));
        M+=dev.go_any_str_from_vec(oper,g_static_var_1);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(part);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_global>,global,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_part,head,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(vector<t_step>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(global);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(head);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_arr_ext )\
    F(t_call_ext)\
    F(t_tmpl_ext)\
    F(t_part    )\
    F(t_step    )\
    F(t_impl    )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_expr
  #include "QapGenStructNoTemplate.inl"
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
      D+=dev.go_str<t_impl>(name);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  class t_ctor_init_list{
  public:
    class t_init_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_init_param)OWNER(t_ctor_init_list)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_init_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_init_param
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        M+=dev.go_const("(");
        if(!ok)return ok;
        O+=dev.go_vec(arr,",");
        if(!ok)return ok;
        M+=dev.go_const(")");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_init_param)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ctor_init_list)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_init_param>,params,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ctor_init_list
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ctor_init_list
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if(!ok)return ok;
      M+=dev.go_vec(params,",");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_zero_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_zero_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_zero_func_body
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
      D+=dev.go_const("=0;");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_null_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_null_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_null_func_body
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
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_delete_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_delete_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_delete_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_delete_func_body
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
      D+=dev.go_const("=delete;");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_impl_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(TAutoPtr<t_ctor_init_list>,init_list,DEF,$,$)\
  ADDVAR(t_raw_func_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl_func_body
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
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      O+=dev.go_auto(init_list);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_dtor_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dtor_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_callconv>,callconv,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
  ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_dtor_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_dtor_class_stat
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
      O+=dev.go_auto(callconv);
      if(!ok)return ok;
      O+=dev.go_auto(path);
      if(!ok)return ok;
      M+=dev.go_const("~");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(params);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ctor_class_stat:public i_class_stat{
  public:
    class t_impl{
    public:
      class t_explicit{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_explicit)OWNER(t_impl)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_explicit
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_explicit
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("explicit");
          if(!ok)return ok;
          M+=dev.go_auto(sep);
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_explicit)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_ctor_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_callconv>,callconv,DEF,$,$)\
    ADDVAR(TAutoPtr<t_explicit>,prefix,DEF,$,$)\
    ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        O+=dev.go_auto(prefix);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        O+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        M+=dev.go_auto(params);
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ctor_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ctor_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ctor_class_stat
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
  class t_oper_cast_class_stat:public i_class_stat{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_oper_cast_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_callconv>,callconv,DEF,$,$)\
    ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_const("operator");
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(cv);
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_cast_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper_cast_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper_cast_class_stat
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
  class t_common_oper_class_stat:public i_class_stat{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_common_oper_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv0,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(TAutoPtr<t_callconv>,callconv,DEF,$,$)\
    ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
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
        O+=dev.go_auto(cv0);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_const("operator");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        static const auto g_static_var_8=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[],->",","));
        M+=dev.go_any_str_from_vec(oper,g_static_var_8);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(cv1);
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_common_oper_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_common_oper_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_common_oper_class_stat
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
  class t_parents{
  public:
    class t_item{
    public:
      class t_pub{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pub)OWNER(t_item)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_access_mod,mod,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_pub
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_pub
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(mod);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_pub)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_parents)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(TAutoPtr<t_pub>,pub,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        O+=dev.go_auto(pub);
        if(!ok)return ok;
        M+=dev.go_str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>(name);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_parents)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_parents
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_parents
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_vec(arr,",");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_class_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_class_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_body
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
  class t_class{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<t_parents>,parents,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDVAR(TAutoPtr<t_class_body>,body,DEF,$,$)\
  ADDVAR(t_sep,sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      O+=dev.go_auto(parents);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      O+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_namespace_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_namespace_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_class_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_namespace_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_namespace_class_stat
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
      M+=dev.go_const("namespace");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_template_class_stat:public i_class_stat{
  public:
    //===>>===i_template_body_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_oper_cast_template_body)\
    ADD(t_common_oper_template_body)\
    ADD(t_ctor_template_body)\
    ADD(t_func_template_body)\
    ADD(t_class_template_body)\
    ADDEND()
  
    class i_template_body;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_template_body_visitor{
    public:
      typedef t_template_class_stat::i_template_body i_template_body;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_template_class_stat::U U;
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
      static TYPE*UberCast(i_template_body*p){
        if(!p)return nullptr;Is<TYPE,i_template_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
    #undef LIST
  public:
    class i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_template_body
    public:
      typedef i_template_body_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load()
        {
          F(t_oper_cast_template_body);
          F(t_common_oper_template_body);
          F(t_ctor_template_body);
          F(t_func_template_body);
          F(t_class_template_body);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
  public:
    //===>>===i_template_param_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_name_template_param)\
    ADD(t_type_template_param)\
    ADDEND()
  
    class i_template_param;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_template_param_visitor{
    public:
      typedef t_template_class_stat::i_template_param i_template_param;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_template_class_stat::U U;
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
      static TYPE*UberCast(i_template_param*p){
        if(!p)return nullptr;Is<TYPE,i_template_param_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
    #undef LIST
  public:
    class i_template_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_template_param
    public:
      typedef i_template_param_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load()
        {
          F(t_name_template_param);
          F(t_type_template_param);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    class t_template_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,bef,DEF,$,$)\
    ADDVAR(TAutoPtr<i_template_param>,body,DEF,$,$)\
    ADDVAR(t_sep,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_template_param
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(bef);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        O+=dev.go_auto(aft);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_oper_cast_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_cast_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper_cast_class_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper_cast_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper_cast_template_body
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
    class t_common_oper_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_common_oper_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_common_oper_class_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_common_oper_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_common_oper_template_body
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
    class t_ctor_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ctor_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_ctor_class_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ctor_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_ctor_template_body
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
    class t_func_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv0,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(TAutoPtr<t_callconv>,callconv,DEF,$,$)\
    ADDVAR(string,func_name,DEF,$,$)\
    ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_func_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_func_template_body
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
        O+=dev.go_auto(keywords);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(cv0);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(func_name);
        if(!ok)return ok;
        O+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        O+=dev.go_auto(cv1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_class_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,keyword,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_concrete_params>,params,DEF,$,$)\
    ADDVAR(TAutoPtr<t_parents>,parents,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(TAutoPtr<t_class_body>,body,DEF,$,$)\
    ADDVAR(t_sep,sep3,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_class_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_class_template_body
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
        static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
        M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
        if(!ok)return ok;
        M+=dev.go_auto(sep0);
        if(!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(parents);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        O+=dev.go_auto(body);
        if(!ok)return ok;
        O+=dev.go_auto(sep3);
        if(!ok)return ok;
        M+=dev.go_const(";");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_name_template_param:public i_template_param{
    public:
      class t_unsgnd{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_unsgnd)OWNER(t_name_template_param)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_unsgnd
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_unsgnd
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("unsigned");
          if(!ok)return ok;
          return ok;
        }
      };
      class t_value{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_name_template_param)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_expr,body,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_value
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_value
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("=");
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_unsgnd)\
      F(t_value )\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_template_param)PARENT(i_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,unsgnd0,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,type,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(string,unsgnd1,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep3,DEF,$,$)\
    ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_name_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_name_template_param
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
        O+=dev.go_str<t_unsgnd>(unsgnd0);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(type);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_str<t_unsgnd>(unsgnd1);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep3);
        if(!ok)return ok;
        O+=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_head{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_head)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(vector<t_template_param>,params,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_head
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_head
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
        M+=dev.go_const("<");
        if(!ok)return ok;
        O+=dev.go_vec(params,",");
        if(!ok)return ok;
        M+=dev.go_const(">");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_type_template_param:public i_template_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_template_param)PARENT(i_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_head>,head,DEF,$,$)\
    ADDVAR(string,type,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_type_template_param
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
        O+=dev.go_auto(head);
        if(!ok)return ok;
        static const auto g_static_var_1=QapStrFinder::fromArr(split("class,typename",","));
        M+=dev.go_any_str_from_vec(type,g_static_var_1);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_template_param           )\
    F(t_oper_cast_template_body  )\
    F(t_common_oper_template_body)\
    F(t_ctor_template_body       )\
    F(t_func_template_body       )\
    F(t_class_template_body      )\
    F(t_name_template_param      )\
    F(t_head                     )\
    F(t_type_template_param      )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_head,head,DEF,$,$)\
  ADDVAR(TAutoPtr<i_template_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_template_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_template_class_stat
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
      M+=dev.go_auto(head);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  class t_enum_class_stat:public i_class_stat{
  public:
    //===>>===i_body_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_impl_body)\
    ADD(t_empty_body)\
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
      typedef t_enum_class_stat::i_body i_body;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_enum_class_stat::U U;
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
  public:
    class i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_body
    public:
      typedef i_body_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load()
        {
          F(t_impl_body);
          F(t_empty_body);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    class t_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_expr,expr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_value
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_value
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("=");
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(expr);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
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
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_comma_with_sep{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comma_with_sep)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_comma_with_sep
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_comma_with_sep
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const(",");
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_body)PARENT(i_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_item>,arr,DEF,$,$)\
    ADDVAR(TAutoPtr<t_comma_with_sep>,comma,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl_body
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
        M+=dev.go_const("{");
        if(!ok)return ok;
        O+=dev.go_vec(arr,",");
        if(!ok)return ok;
        O+=dev.go_auto(comma);
        if(!ok)return ok;
        M+=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_empty_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_empty_body)PARENT(i_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_empty_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_empty_body
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
    class t_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_body
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
    F(t_value         )\
    F(t_item          )\
    F(t_comma_with_sep)\
    F(t_impl_body     )\
    F(t_empty_body    )\
    F(t_body          )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_enum_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_enum_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_enum_class_stat
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
      M+=dev.go_const("enum");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      O+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  class t_using_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_using_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_using_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_using_class_stat
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
      M+=dev.go_const("using");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(type);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_tmpl_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_call_param)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_tmpl_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_call_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_call_param
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,func,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_tmpl_call_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_tmpl_expr
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
      M+=dev.go_str<t_name>(func);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_block_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_tmpl_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_block_tmpl_expr
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
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_pfunc_concrete_param_way:public i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pfunc_concrete_param_way)PARENT(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_fv_class_stat::t_type_expr::t_pfunc,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pfunc_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_pfunc_concrete_param_way
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
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_type_concrete_param_way:public i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_concrete_param_way)PARENT(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_concrete_param_way
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
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_expr_concrete_param_way:public i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_concrete_param_way)PARENT(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_expr,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_expr_concrete_param_way
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
      D+=dev.go_minor<t_type_concrete_param_way>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_bool_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_bool_tmpl_expr
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_string_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_string_tmpl_expr
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
      D+=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_char_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_tmpl_expr
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
      D+=dev.go_str<t_char_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_num_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_tmpl_expr
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
      D+=dev.go_any(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_real_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_real_tmpl_expr
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
      D+=dev.go_str<t_real>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_nullptr_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nullptr_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_nullptr_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_nullptr_tmpl_expr
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
      D+=dev.go_const("nullptr");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_or_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_or_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_name>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_or_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_or_tmpl_expr
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
      D+=dev.go_bin_oper(arr,"|");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_hex_tmpl_expr:public i_tmpl_expr{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_hex_tmpl_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,x,DEF,$,$)\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("0");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        D+=dev.go_any_char(x,g_static_var_1);
        if(!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        D+=dev.go_any(value,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hex_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hex_tmpl_expr
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
      D+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_var_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var_tmpl_expr
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
      D+=dev.go_str<t_fv_class_stat::t_type_expr>(name);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_pragma_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pragma_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pragma_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_pragma_class_stat
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
      D+=dev.go_const("#pragma");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_include_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_include_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_include_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_include_class_stat
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
      D+=dev.go_const("#include");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_preproc_if_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_preproc_if_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_preproc_if_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_preproc_if_class_stat
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
      D+=dev.go_const("#if");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_preproc_else_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_preproc_else_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_preproc_else_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_preproc_else_class_stat
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
      D+=dev.go_const("#else");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_preproc_endif_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_preproc_endif_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_preproc_endif_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_preproc_endif_class_stat
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
      D+=dev.go_const("#endif");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_define_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_define_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_define_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_define_class_stat
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
      D+=dev.go_const("#define");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_undef_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_undef_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_undef_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_undef_class_stat
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
      D+=dev.go_const("#undef");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_class_stat
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
  class t_null_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_null_class_stat
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
  class t_class_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_class,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_class_stat
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
  class t_inl_file_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inl_file_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(TAutoPtr<t_class>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_inl_file_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_inl_file_stat
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_lev03                   )\
  F(t_lev05                   )\
  F(t_lev06                   )\
  F(t_lev07                   )\
  F(t_lev08                   )\
  F(t_lev09                   )\
  F(t_lev10                   )\
  F(t_lev11                   )\
  F(t_lev12                   )\
  F(t_lev13                   )\
  F(t_lev14                   )\
  F(t_expr                    )\
  F(t_tmpl_lev03              )\
  F(t_tmpl_lev05              )\
  F(t_tmpl_lev06              )\
  F(t_tmpl_lev09              )\
  F(t_tmpl_lev10              )\
  F(t_tmpl_lev11              )\
  F(t_tmpl_lev12              )\
  F(t_tmpl_lev13              )\
  F(t_tmpl_lev14              )\
  F(t_tmpl_expr               )\
  F(t_concrete_param          )\
  F(t_concrete_params         )\
  F(t_access_mod              )\
  F(t_access_mod_class_stat   )\
  F(t_raw_func_body           )\
  F(t_func_path               )\
  F(t_const_with_sep          )\
  F(t_keyword                 )\
  F(t_callconv                )\
  F(t_ptr                     )\
  F(t_ref                     )\
  F(t_type_with_sep           )\
  F(t_scope_with_sep          )\
  F(t_scopes                  )\
  F(t_global                  )\
  F(t_raw_type_expr           )\
  F(t_arr_body                )\
  F(t_fv_class_stat           )\
  F(t_typedef_class_stat      )\
  F(t_real                    )\
  F(t_call_param              )\
  F(t_call_params             )\
  F(t_block_expr              )\
  F(t_bool_expr               )\
  F(t_string_expr             )\
  F(t_char_expr               )\
  F(t_num_expr                )\
  F(t_real_expr               )\
  F(t_nullptr_expr            )\
  F(t_or_expr                 )\
  F(t_hex_expr                )\
  F(t_var_expr                )\
  F(t_ctor_init_list          )\
  F(t_zero_func_body          )\
  F(t_null_func_body          )\
  F(t_delete_func_body        )\
  F(t_impl_func_body          )\
  F(t_dtor_class_stat         )\
  F(t_ctor_class_stat         )\
  F(t_oper_cast_class_stat    )\
  F(t_common_oper_class_stat  )\
  F(t_parents                 )\
  F(t_class_body              )\
  F(t_class                   )\
  F(t_namespace_class_stat    )\
  F(t_template_class_stat     )\
  F(t_enum_class_stat         )\
  F(t_using_class_stat        )\
  F(t_tmpl_call_param         )\
  F(t_call_tmpl_expr          )\
  F(t_block_tmpl_expr         )\
  F(t_pfunc_concrete_param_way)\
  F(t_type_concrete_param_way )\
  F(t_expr_concrete_param_way )\
  F(t_bool_tmpl_expr          )\
  F(t_string_tmpl_expr        )\
  F(t_char_tmpl_expr          )\
  F(t_num_tmpl_expr           )\
  F(t_real_tmpl_expr          )\
  F(t_nullptr_tmpl_expr       )\
  F(t_or_tmpl_expr            )\
  F(t_hex_tmpl_expr           )\
  F(t_var_tmpl_expr           )\
  F(t_pragma_class_stat       )\
  F(t_include_class_stat      )\
  F(t_preproc_if_class_stat   )\
  F(t_preproc_else_class_stat )\
  F(t_preproc_endif_class_stat)\
  F(t_define_class_stat       )\
  F(t_undef_class_stat        )\
  F(t_sep_class_stat          )\
  F(t_null_class_stat         )\
  F(t_class_class_stat        )\
  F(t_inl_file_stat           )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inl_file)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_class_stat>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_inl_file
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_inl_file
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
public:
};

/*
//list of types:
F(t_inl_file)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Finl%5Ffile%7B%0D%0A%20%20t%5Flev03%7B%0D%0A%20%20%20%20string%20oper%3B%0D%0
A%20%20%20%20TAutoPtr%3Ci%5Fexpr%3E%20expr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%26%2C%2A%2C%2B
%2C%2D%2C%21%2C%7E%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fau
to%28expr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev05%7B%0D%0
A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20
%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2C
split%28%22%2A%2C%2F%2C%25%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D
%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%
20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev03%20expr%3B%0D%0A%20%20%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%2
0go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20
%20%20%20t%5Flev03%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0
A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%2
0%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D
%0A%20%20t%5Flev06%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string
%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fs
tr%5Ffrom%5Fvec%28value%2Csplit%28%22%2B%2C%2D%22%2C%22%2C%22%29%29%3B%0D%0A%20%
20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%
20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev05%20expr%3B%0D%0A%2
0%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20
%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%
20%20%20%7D%0D%0A%20%20%20%20t%5Flev05%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fi
tem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28e
xpr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%
7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev07%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%
20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3C%3C%2C%3E%3E%22%2C%2
2%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%
20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t
%5Flev06%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5F
auto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%2
0%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev06%20expr%3B%0D%0A
%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20
%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ar
r%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev08%7B%0D%0A%20%20%
20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%2
0%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28
%22%3C%2C%3C%3D%2C%3E%2C%3E%3D%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7
D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Fo
per%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev07%20expr%3B%0D%0A%20%20%20%20%20%20
%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%
20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0
A%20%20%20%20t%5Flev07%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%
0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7
D%0D%0A%20%20t%5Flev09%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20st
ring%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany
%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3D%3D%2C%21%3D%22%2C%22%2C%22%29%29%3B
%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D
%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev08%20expr%
3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3
B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D
%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev08%20expr%3B%0D%0A%20%20%20%20vect
or%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%
5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20
%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev10%7B%0D%0A%20%20%20%20t%5Foper%7B
%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20
%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%26%22%2C%22%
2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20
t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5
Flev09%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fau
to%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%
20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev09%20expr%3B%0D%0A%2
0%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%2
0%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%
29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev11%7B%0D%0A%20%20%20
%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%
7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%2
2%5E%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%
0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%
20%20%20%20t%5Flev10%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%2
0%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3
B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev10%20e
xpr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A
%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev12%7B%
0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%2
0%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28valu
e%2Csplit%28%22%7C%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%2
0%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3
B%0D%0A%20%20%20%20%20%20t%5Flev11%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20
%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fau
to%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%2
0t%5Flev11%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%
20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%2
0t%5Flev13%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value
%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffro
m%5Fvec%28value%2Csplit%28%22%26%26%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20
%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20
t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev12%20expr%3B%0D%0A%20%20%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%2
0%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D
%0D%0A%20%20%20%20t%5Flev12%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20ar
r%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0
D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20
%20%7D%0D%0A%20%20t%5Flev14%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20
%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%
5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%7C%22%2C%22%2C%22%29%29%3B%0D%
0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%
20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev13%20expr%3B%0
D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D
%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%
0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev13%20expr%3B%0D%0A%20%20%20%20vector%3
Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fau
to%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%
20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fexpr%7Bt%5Flev14%20body%3B%7Bgo%5Fauto%28
body%29%3B%7D%7D%0D%0A%20%20t%5Ftmpl%5Flev03%7B%0D%0A%20%20%20%20string%20oper%3
B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Ftmpl%5Fexpr%3E%20expr%3B%0D%0A%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%2
6%2C%2A%2C%2B%2C%2D%2C%21%2C%7E%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20M
%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5F
tmpl%5Flev05%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20val
ue%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ff
rom%5Fvec%28value%2Csplit%28%22%2A%2C%2F%2C%25%22%2C%22%2C%22%29%29%3B%0D%0A%20%
20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%
20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Ftmpl%5Flev03%20expr%3B%
0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0
D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D
%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5Flev03%20expr%3B%0D%0A%20%20%20%20
vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3
Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0
A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftmpl%5Flev06%7B%0D%0A%20%20%20%20
t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%2
B%2C%2D%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%
0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%
20%20%20%20%20t%5Ftmpl%5Flev05%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%
20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%2
8expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5
Ftmpl%5Flev05%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%
20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%
20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%2
0%20t%5Ftmpl%5Flev09%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20stri
ng%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5
Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3D%3D%2C%21%3D%22%2C%22%2C%22%29%29%3B%0
D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0
A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Ftmpl%5Flev06%20
expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper
%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5Flev06%20expr%3B%0D%0A%20%
20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29
%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftmpl%5Flev10%7B%0D%0A%20%
20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%2
0%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit
%28%22%26%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7
D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%2
0%20%20%20%20%20t%5Ftmpl%5Flev09%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%2
0%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto
%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t
%5Ftmpl%5Flev09%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%2
0%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A
%20%20t%5Ftmpl%5Flev11%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20st
ring%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany
%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%5E%22%2C%22%2C%22%29%29%3B%0D%0A%20%20
%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20
%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Ftmpl%5Flev10%20expr%3B%0D
%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%
0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0
A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5Flev10%20expr%3B%0D%0A%20%20%20%20ve
ctor%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dg
o%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%
20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftmpl%5Flev12%7B%0D%0A%20%20%20%20t%
5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D
%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%
22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20
%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20
%20%20t%5Ftmpl%5Flev11%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20
%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29
%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5F
lev11%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20
%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5F
tmpl%5Flev13%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20val
ue%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ff
rom%5Fvec%28value%2Csplit%28%22%26%26%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%
20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%
20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Ftmpl%5Flev12%20expr%3B%0D%0A%20%
20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%2
0%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20
%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5Flev12%20expr%3B%0D%0A%20%20%20%20vector%3C
t%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Faut
o%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%2
0%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftmpl%5Flev14%7B%0D%0A%20%20%20%20t%5Foper%
7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%
20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%7C%7C%22%2
C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%
20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%
20t%5Ftmpl%5Flev13%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%
20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%
0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5Flev1
3%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftmpl
%5Fexpr%7Bt%5Ftmpl%5Flev14%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20t
%5Fconcrete%5Fparam%7B%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20TAuto
Ptr%3Ci%5Fconcrete%5Fparam%5Fway%3E%20body%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B
%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A
%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fconcrete
%5Fparams%7B%0D%0A%20%20%20%20vector%3Ct%5Fconcrete%5Fparam%3E%20arr%3B%0D%0A%20
%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%
5Fconst%28%22%3C%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%
22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3E%22%29%3B%0D%0A%20%20%
20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0
A%20%20t%5Faccess%5Fmod%7Bstring%20keyword%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28ke
yword%2Csplit%28%22public%2Cprotected%2Cprivate%22%2C%22%2C%22%29%29%3B%7D%7D%0D
%0A%20%20t%5Faccess%5Fmod%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20
%20t%5Faccess%5Fmod%20mod%3B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20
%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28mod%29%3B%0D%0A%20%20%20%20%20%20O
%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%22
%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fraw%5Ffunc%5Fbody%7B%0
D%0A%20%20%20%20t%5Fsep%5Fitem%3D%3Ei%5Fitem%7Bt%5Fsep%20sep%3B%7Bgo%5Fauto%28se
p%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fs%5Fitem%3D%3Ei%5Fitem%7Bstring%20value%3B%7B
go%5Fstr%3Ct%5Fstr%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20%20%20
t%5Fc%5Fitem%3D%3Ei%5Fitem%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fchar%5Fitem%3A%3
At%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fcode%5Fitem%3D%3Ei%5Fitem%
7Bstring%20code%3B%7Bgo%5Fany%28code%2Cgen%5Fdips%28%22AZaz09%22%29%2B%22%2B%2D%
2A%3F%3C%3E%5B%5D%28%29%2C%2E%3A%3B%7E%21%40%23%24%5F%3D%25%5E%26%5C%5C%7C%22%29
%3B%7D%7D%0D%0A%20%20%20%20t%5Fdiv%5Fitem%3D%3Ei%5Fitem%7B%7Bgo%5Fconst%28%22%2F
%22%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fblock%5Fitem%3D%3Ei%5Fitem%7BTAutoPtr%3Ct%5
Fraw%5Ffunc%5Fbody%3E%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20
t%5Fsep%20sep%3B%0D%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fitem%3E%3E%20arr%3B%0D
%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D
%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%20M%2B%3D
go%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5F
func%5Fpath%7B%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20%20%20string%
20value%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20t%5Fs
ep%20sep1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5
Fstr%3Ct%5Fname%3E%28value%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%
0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%
20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D
%0D%0A%20%20%7D%0D%0A%20%20t%5Fconst%5Fwith%5Fsep%7Bt%5Fsep%20sep%3Bstring%20key
word%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28keywo
rd%2Csplit%28%22typename%2Cconst%2Cunsigned%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0A%
20%20t%5Fkeyword%7B%0D%0A%20%20%20%20string%20keyword%3B%0D%0A%20%20%20%20t%5Fse
p%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ff
rom%5Fvec%28keyword%2Csplit%28%22friend%2Ctypename%2Cextern%2Cexplicit%2Cconstex
pr%2Cvirtual%2Cconst%2Cstatic%2Cinline%2Cunsigned%22%2C%22%2C%22%29%29%3B%0D%0A%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7
D%0D%0A%20%20t%5Fcallconv%7B%0D%0A%20%20%20%20string%20value%3B%0D%0A%20%20%20%2
0t%5Fsep%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fany%5F
str%5Ffrom%5Fvec%28value%2Csplit%28%22%5F%5Fcdecl%2C%5F%5Fstdcall%2C%5F%5Ffastca
ll%2C%5F%5Fthiscall%2C%5F%5Fvectorcall%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%
20t%5Fptr%7B%0D%0A%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A
%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%2
0%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%2A%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%2
0%20%7D%0D%0A%20%20t%5Fref%7B%0D%0A%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep
%3E%20cv%3B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20string%20ref%3B%0
D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fan
y%5Fstr%5Ffrom%5Fvec%28ref%2Csplit%28%22%26%26%2C%26%22%2C%22%2C%22%29%29%3B%0D%
0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftype%5Fwith%5Fsep%7B%0D%0A%20%20
%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20TAutoP
tr%3Ct%5Fconcrete%5Fparams%3E%20concrete%5Fparams%3B%0D%0A%20%20%20%20%7B%0D%0A%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5
Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28concre
te%5Fparams%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fscope%5Fwit
h%5Fsep%7Bt%5Fsep%20sep%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fconst%28%22
%3A%3A%22%29%3B%7D%7D%0D%0A%20%20t%5Fscopes%7B%0D%0A%20%20%20%20t%5Fitem%7Bt%5Fs
cope%5Fwith%5Fsep%20sws%3Bt%5Ftype%5Fwith%5Fsep%20body%3B%7Bgo%5Fauto%28sws%29%3
Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Ftype%5Fwith%5Fsep%20first%3B%
0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%
20%20%20%20M%2B%3Dgo%5Fauto%28first%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fglobal%7B%7BM%2
B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%7D%7D%0D%0A%20%20t%5Fraw%5Ftype%5Fexpr%7B%0D
%0A%20%20%20%20TAutoPtr%3Ct%5Fglobal%3E%20global%3B%0D%0A%20%20%20%20t%5Fsep%20s
ep%3B%0D%0A%20%20%20%20t%5Fscopes%20scopes%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28global%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28scopes%29%3B%0D%0A%20%20
%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Farr%5Fbody%7B%0D%0A%20%20%20%20t%5Fsep%2
0sep0%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20t%5Fexpr%20expr%3B%
0D%0A%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%2
0%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%2
0%20%20M%2B%3Dgo%5Fconst%28%22%5B%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fau
to%28sep1%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20
%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fcon
st%28%22%5D%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D%0A%
20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ffv%5Fclass%5Fstat%3D%3Ei%5Fclass%5F
stat%7B%0D%0A%20%20%20%20t%5Ftype%5Fexpr%7B%0D%0A%20%20%20%20%20%20t%5Ftype%5Fex
pr%5Fwith%5Fsep%5Fand%5Fcv%7B%0D%0A%20%20%20%20%20%20%20%20vector%3Ct%5Fconst%5F
with%5Fsep%3E%20cvs%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ftype%5Fexpr%3
E%20body%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28cvs%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto
%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%
20%20%20%20%20%20t%5Fname%5Fpart%7BTAutoPtr%3Ci%5Fname%5Fpart%3E%20body%3B%7Bgo%
5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fraw%5Fname%5Fpart%3D%3Ei%5F
name%5Fpart%7Bstring%20name%3B%7Bgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%7D%7D%0D%0A
%20%20%20%20%20%20t%5Fbrackets%5Fname%5Fpart%3D%3Ei%5Fname%5Fpart%7B%0D%0A%20%20
%20%20%20%20%20%20t%5Famp%7Bstring%20body%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28bod
y%2Csplit%28%22%26%2C%26%26%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0A%20%20%20%20%20%2
0%20%20t%5Famp%5Fpart%3D%3Ei%5Fpart%7Bt%5Famp%20body%3B%7Bgo%5Fauto%28body%29%3B
%7D%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fstar%5Fpart%3D%3Ei%5Fpart%7Bstring%20sta
rs%3BTAutoPtr%3Ct%5Famp%3E%20amp%3B%7BM%2B%3Dgo%5Fany%28stars%2C%22%2A%22%29%3BO
%2B%3Dgo%5Fauto%28amp%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ci%5Fpa
rt%3E%20stamp%5Fpart%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%2
0%20%20%20%20%20%20TAutoPtr%3Ct%5Fname%5Fpart%3E%20namepart%3B%0D%0A%20%20%20%20
%20%20%20%20TAutoPtr%3Ct%5Farr%5Fbody%3E%20arrbody%3B%0D%0A%20%20%20%20%20%20%20
%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D
%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28stamp%5Fpart%29%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28namepart%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M
%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%
5Fauto%28arrbody%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%
7D%0D%0A%20%20%20%20%20%20t%5Ffunc%5Fparam%5Fvalue%7B%0D%0A%20%20%20%20%20%20%20
%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fexpr%20value%3B%0D%0A%20%20
%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22
%3D%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%
0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20%20%20
%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Ffunc%5Fpar
am%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20%20%
20TAutoPtr%3Ci%5Ffunc%5Fparam%3E%20body%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%
20sep1%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fparam%5Fvalue%3E%20
value%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%
20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O
%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A
%20%20%20%20%20%20t%5Ffunc%5Fparams%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20se
p%3B%0D%0A%20%20%20%20%20%20%20%20vector%3Ct%5Ffunc%5Fparam%3E%20arr%3B%0D%0A%20
%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28s
ep%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%
0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A
%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20
%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fpfunc%7
B%0D%0A%20%20%20%20%20%20%20%20t%5Faddr%7B%0D%0A%20%20%20%20%20%20%20%20%20%20t%
5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5Fcv%20type%3B%0D%0A%20%20%20%20%20%20%20%20%20
%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D
%0A%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%0D
%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%2
0%20%20%20%20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5Fcv%20type%3B%0D%0A%20%20
%20%20%20%20%20%20t%5Faddr%20addr%3B%0D%0A%20%20%20%20%20%20%20%20string%20name%
3B%0D%0A%20%20%20%20%20%20%20%20t%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20%
20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%
0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28addr%29%3B%0D%0A%20%20%20%20%20%20%
20%20%20%20M%2B%3Dgo%5Fconst%28%22%2A%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%
20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20
M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo
%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%
7D%0D%0A%20%20%20%20%20%20t%5Fpfunc%5Ffunc%5Fparam%3D%3Ei%5Ffunc%5Fparam%7Bt%5Fp
func%20value%3B%7Bgo%5Fauto%28value%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fvar%5
Fargs%5Ffunc%5Fparam%3D%3Ei%5Ffunc%5Fparam%7B%7Bgo%5Fconst%28%22%2E%2E%2E%22%29%
3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Ftype%5Ffunc%5Fparam%3D%3Ei%5Ffunc%5Fparam%7B
%0D%0A%20%20%20%20%20%20%20%20t%5Fconst%7Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fconst%2
8%22const%22%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%
20t%5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5Fcv%20type%3B%0D%0A%20%20%20%20%20%20%20%2
0t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%3E%20cv%3B%0
D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fname%5Fpart%3E%20namepart%3B%0D%0A%20
%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28t
ype%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%
20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20
%20%20%20%20O%2B%3Dgo%5Fauto%28namepart%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0
D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fexpr%5Ffunc%5Fparam%3D%3Ei%
5Ffunc%5Fparam%7Bt%5Fexpr%20body%3B%7Bgo%5Fminor%3Ct%5Ftype%5Ffunc%5Fparam%3E%28
body%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Ffv%5Fstat%7B%0D%0A%20%20%20%20%20%20
%20%20t%5Fimpl%5Ffunc%5Fbody%3D%3Ei%5Ffv%5Fbody%7Bt%5Fsep%20sep%3Bt%5Fraw%5Ffunc
%5Fbody%20body%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fauto%28body%29%3B%7D
%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fzero%5Ffunc%5Fbody%3D%3Ei%5Ffv%5Fbody%7B%7B
go%5Fconst%28%22%3D0%3B%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fdelete%5
Ffunc%5Fbody%3D%3Ei%5Ffv%5Fbody%7B%7Bgo%5Fconst%28%22%3Ddelete%3B%22%29%3B%7D%7D
%0D%0A%20%20%20%20%20%20%20%20t%5Ffunc%5Ffv%5Fend%3D%3Ei%5Ffv%5Fend%7B%0D%0A%20%
20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fparams%3E%20params%3B%0D%0A%20%2
0%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv1%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%20%20%20%20T
AutoPtr%3Ci%5Ffv%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7B%0D%0
A%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20
%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv1%29%3B%0D%0A%20%20%20%20%20%
20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20%
20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%
0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fvar%5Ffv%5Fend
%3D%3Ei%5Ffv%5Fend%7B%0D%0A%20%20%20%20%20%20%20%20%20%20t%5Ffunc%5Ffv%5Fitem%3D
%3Ei%5Ffv%5Fitem%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc
%5Fparams%3E%20params%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5
Fconst%5Fwith%5Fsep%3E%20cv1%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%7B%0D%
0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0
A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv1%29%3B%0D%0A%20
%20%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0
A%20%20%20%20%20%20%20%20%20%20t%5Fvar%5Ffv%5Fitem%3D%3Ei%5Ffv%5Fitem%7B%0D%0A%2
0%20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Farr%5Fbody%3E%20arrbody%3B%0D%0
A%20%20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fparam%5Fvalue%3E%20va
lue%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%2
0%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arrbody%29%3B%0D%0A%20%20%20%20%20%20%20%2
0%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20%20%20%20%20%20%20%
20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20
%20%20%20t%5Fbody%7BTAutoPtr%3Ci%5Ffv%5Fitem%3E%20body%3B%7Bgo%5Fauto%28body%29%
3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20%
20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20TAut
oPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%
20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20string%20name%3B%0D
%0A%20%20%20%20%20%20%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20
%20%20%20%20%20%20t%5Fbody%20body%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20t%
5Fsep%20sep3%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%2
0%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%2C%22%29%3B%0D%0A%20%20%20%2
0%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%2
0%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20%
20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%
20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20
%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20
%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20
%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D%0A%20%20%20%20%20%20%20
%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%2
0%20%20%20%20TAutoPtr%3Ct%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20%20%20%20%2
0vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%2
0%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%2
0%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%20%20%20
%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20
%20%7D%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20s
ep%5Fwa%3B%0D%0A%20%20%20%20%20%20%20%20vector%3Ct%5Fkeyword%3E%20keywords%3B%0D
%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ftype%5Fexpr%3E%20type%3B%0D%0A%20%20%2
0%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20%20%20%20%2
0%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fp
ath%3E%20path%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fcallconv%3E%20callc
onv%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fname%5Fpart%20name%3B%0D%0A%20%20%20%20%
20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ci%5Ffv%5Fen
d%3E%20way%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%
20O%2B%3Dgo%5Fauto%28sep%5Fwa%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28keywords%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28t
ype%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%2
0%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%2
0%20%20%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28callconv%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fa
uto%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3
B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28way%29%3B%0D%0A%20%20%20
%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fimpl%5F
typeexpr%3D%3Ei%5Ftypeexpr%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fglobal%7B%7BM%2B%
3Dgo%5Fconst%28%22%3A%3A%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3C
t%5Fglobal%3E%20global%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20
%20%20%20%20%20%20%20t%5Fscopes%20scopes%3B%0D%0A%20%20%20%20%20%20%20%20vector%
3Ct%5Fptr%3E%20ptrs%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fref%3E%20ref%
3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28global%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep
%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28scopes%29%3B%0D%0A%
20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ptrs%29%3B%0D%0A%20%20%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28ref%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0
A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fdecl%5Ftypeexpr%3D%3Ei%5Ftypee
xpr%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20%20
%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fexpr%20expr%3B%0D%0A%20%20
%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20
%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22decltype%22%29%3B%0D%0A%20%20%20%
20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20%
20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28
expr%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0
A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%2
0%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20TAutoPtr%3
Ci%5Ftypeexpr%3E%20body%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20
%20go%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%
20%20%20%20t%5Ftype%5Fexpr%3A%3At%5Ffv%5Fstat%20body%3B%0D%0A%20%20%20%20%7Bgo%5
Fauto%28body%29%3B%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftypedef%5Fclass%5Fstat%3D%3E
i%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20t%5Ffv%5F
class%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ffv%5Fstat%20body%3B%0D%0A%20%20%20%20
%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22typedef%22%29%3B%0D%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%2
8body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Freal%7B%0D%0A%20%
20%20%20t%5Ff%7Bchar%20body%3B%7Bgo%5Fany%5Fchar%28body%2C%22fF%22%29%3B%7D%7D%0
D%0A%20%20%20%20string%20bef%3B%0D%0A%20%20%20%20string%20aft%3B%0D%0A%20%20%20%
20TAutoPtr%3Ct%5Ff%3E%20ext%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%
3Dgo%5Fany%28bef%2Cgen%5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%20%20M%2B%3D
go%5Fconst%28%22%2E%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fany%28aft%2Cgen%
5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ext%29%3B%0
D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fcall%5Fparam%7B%0D%0A%20%20%20
%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20t%5Fexpr%20expr%3B%0D%0A%20%20%20%20t%5Fse
p%20sep1%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%
29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%
20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t
%5Fcall%5Fparams%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20vector%3C
t%5Fcall%5Fparam%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B
%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20%20%2
0%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0
D%0A%20%20t%5Fblock%5Fexpr%3D%3Ei%5Fexpr%7B%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0
D%0A%20%20%20%20t%5Fexpr%20expr%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%2
0%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%2
0%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fau
to%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20
%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20
%7D%0D%0A%20%20t%5Fbool%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fany%5Fst
r%5Ffrom%5Fvec%28value%2Csplit%28%22false%2Ctrue%22%2C%22%2C%22%29%29%3B%7D%7D%0
D%0A%20%20t%5Fstring%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fs
tr%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20t%5Fchar%5Fexpr%3D%3Ei
%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fchar%5Fitem%3A%3At%5Fimpl%3E%28valu
e%29%3B%7D%7D%0D%0A%20%20t%5Fnum%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5
Fany%28value%2Cgen%5Fdips%28%2209%22%29%29%3B%7D%7D%0D%0A%20%20t%5Freal%5Fexpr%3
D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Freal%3E%28value%29%3B%7D%7D%0D
%0A%20%20t%5Fnullptr%5Fexpr%3D%3Ei%5Fexpr%7B%7Bgo%5Fconst%28%22nullptr%22%29%3B%
7D%7D%0D%0A%20%20t%5For%5Fexpr%3D%3Ei%5Fexpr%7Bvector%3Ct%5Fname%3E%20arr%3B%7Bg
o%5Fbin%5Foper%28arr%2C%22%7C%22%29%3B%7D%7D%0D%0A%20%20t%5Fhex%5Fexpr%3D%3Ei%5F
expr%7Bt%5Fimpl%7Bchar%20x%3Bstring%20value%3B%7Bgo%5Fconst%28%220%22%29%3Bgo%5F
any%5Fchar%28x%2C%22xX%22%29%3Bgo%5Fany%28value%2Cgen%5Fdips%28%2209afAF%22%29%2
9%3B%7D%7Dstring%20value%3B%7Bgo%5Fstr%3Ct%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%2
0%20t%5Fvar%5Fexpr%3D%3Ei%5Fexpr%7B%0D%0A%20%20%20%20t%5Farr%5Fext%3D%3Ei%5Fext%
7B%0D%0A%20%20%20%20%20%20t%5Farr%5Fbody%20body%3B%0D%0A%20%20%20%20%20%20%7B%0D
%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20
%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fcall%5Fext%3D%3Ei%5Fext%7B%0D%0A%2
0%20%20%20%20%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%20concrete%5Fparams%3B%0D%0A
%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20vector%3Ct%5Fcall%5Fpa
rams%3E%20arr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3D
go%5Fauto%28concrete%5Fparams%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20
%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ftmpl%5Fext%3D%3Ei%5
Fext%7B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%20concrete%5F
params%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fau
to%28concrete%5Fparams%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%
0A%20%20%20%20t%5Fpart%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20bef%3B%0D%0A%20%20%20
%20%20%20string%20name%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20aft%3B%0D%0A%20%20%20
%20%20%20TAutoPtr%3Ci%5Fext%3E%20ext%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%
0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28bef%2
9%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%
0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28aft%29%3B%0D%0A%20%20%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28ext%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8sep%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5F
step%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%2
0oper%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20t%5Fpar
t%20part%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%
20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%2D%3E%2C%2E%2C%3
A%3A%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep
1%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28part%29%3B%0D%0A%20%20%2
0%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%2
0%20%20%20%7D%0D%0A%20%20%20%20t%5Fimpl%7B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5
Fglobal%3E%20global%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%2
0%20%20t%5Fpart%20head%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%2
0%20%20%20vector%3Ct%5Fstep%3E%20arr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%2
0%20%20%20%20%20O%2B%3Dgo%5Fauto%28global%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28head%
29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%2
0%20%20%7D%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20
%20%20%20go%5Fstr%3Ct%5Fimpl%3E%28name%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D
%0D%0A%20%20t%5Fctor%5Finit%5Flist%7B%0D%0A%20%20%20%20t%5Finit%5Fparam%7B%0D%0A
%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%20name%3B%0D%0
A%20%20%20%20%20%20vector%3Ct%5Fcall%5Fparam%3E%20arr%3B%0D%0A%20%20%20%20%20%20
t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3
Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%
3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B
%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%2
0%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7
D%0D%0A%20%20%20%20vector%3Ct%5Finit%5Fparam%3E%20params%3B%0D%0A%20%20%20%20t%5
Fsep%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%3A%22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fvec%28params%2C%22%2C%22%29%3B%
0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%7D%0D%0A%2
0%20%7D%0D%0A%20%20t%5Fzero%5Ffunc%5Fbody%3D%3Ei%5Ffunc%5Fbody%7B%7Bgo%5Fconst%2
8%22%3D0%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fnull%5Ffunc%5Fbody%3D%3Ei%5Ffunc%5Fbod
y%7Bt%5Fsep%20sep%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fconst%28%22%3B%22
%29%3B%7D%7D%0D%0A%20%20t%5Fdelete%5Ffunc%5Fbody%3D%3Ei%5Ffunc%5Fbody%7B%7Bgo%5F
const%28%22%3Ddelete%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fimpl%5Ffunc%5Fbody%3D%3Ei%
5Ffunc%5Fbody%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20TAutoPtr%3Ct
%5Fctor%5Finit%5Flist%3E%20init%5Flist%3B%0D%0A%20%20%20%20t%5Fraw%5Ffunc%5Fbody
%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29
%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28init%5Flist%29%3B%0D%0A%20%20%20%2
0%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%2
0%20t%5Fdtor%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20TAutoPtr%3
Ct%5Fcallconv%3E%20callconv%3B%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20
%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%20%20string%20name%3B%0D%
0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5F
type%5Fexpr%3A%3At%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Ff
unc%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28callconv%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A
%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7E%22%29%3B%0D%0A%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%
28name%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20
%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto
%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fctor%5Fclass%5F
stat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fimpl%7B%0D%0A%20%20%20%20%20%
20t%5Fexplicit%7Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fconst%28%22explicit%22%29%3BM%2B
%3Dgo%5Fauto%28sep%29%3B%7D%7D%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fcallconv%3E
%20callconv%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fexplicit%3E%20prefix%3B%0D%
0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%20%20%20
%20string%20name%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20
%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%20concrete%5Fparams%3B%0D%0A%20%20%20%20%
20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20params%
3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20
%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28callconv%29%3B%0D%0
A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28prefix%29%3B%0D%0A%20%20%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr
%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%
29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28concrete%5Fparams%29%3B%0D
%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%
20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%
20%7D%0D%0A%20%20%20%20t%5Fimpl%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%0D%0A%20%2
0%7D%0D%0A%20%20t%5Foper%5Fcast%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20
%20%20%20t%5Fimpl%7B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fcallconv%3E%20callcon
v%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%
20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At
%5Ftype%5Fexpr%20type%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20
%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20par
ams%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A
%20%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%2
0%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28callconv%29%3B%0D%0A%20%20%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B
%3Dgo%5Fconst%28%22operator%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fau
to%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A
%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto
%28cv%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%
20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fimpl%20body%3B%7Bgo%
5Fauto%28body%29%3B%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fcommon%5Foper%5Fclass%5Fsta
t%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fimpl%7B%0D%0A%20%20%20%20%20%20v
ector%3Ct%5Fkeyword%3E%20keywords%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fsta
t%3A%3At%5Ftype%5Fexpr%20type%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fw
ith%5Fsep%3E%20cv0%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20
%20%20TAutoPtr%3Ct%5Fcallconv%3E%20callconv%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3
Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%
20%20%20%20%20string%20oper%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3
At%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20%20%20TAuto
Ptr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv1%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Ff
unc%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28keywords%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%
28type%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv0%29%3B%0D%0A%20%
20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20O
%2B%3Dgo%5Fauto%28callconv%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8path%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22operator%22%29%3
B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%2
0%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%3D%2C%2B%3D%2C
%2D%3D%2C%2A%3D%2C%2F%3D%2C%25%3D%2C%7C%3D%2C%26%3D%2C%5E%3D%2C%3C%3C%3D%2C%3E%3
E%3D%2C%7C%7C%2C%26%26%2C%7C%2C%5E%2C%26%2C%3D%3D%2C%21%3D%2C%3C%2C%3C%3D%2C%3E%
2C%3E%3D%2C%3C%3C%2C%3E%3E%2C%2B%2C%2D%2C%2A%2C%2F%2C%25%2C%2B%2B%2C%2D%2D%2C%7E
%2C%21%2C%28%29%2C%5B%5D%2C%2D%3E%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%2
0%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28cv1%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0
A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fimpl%20body%3B%
7Bgo%5Fauto%28body%29%3B%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fparents%7B%0D%0A%20%20
%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Fpub%7Bt%5Faccess%5Fmod%20mod%3Bt%5F
sep%20sep%3B%7BM%2B%3Dgo%5Fauto%28mod%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%7D%7D%0D
%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fpub%
3E%20pub%3B%0D%0A%20%20%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%20%20%7B%0
D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28pub%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%
3Ct%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ftype%5Fexpr%5Fwith%5Fsep%5
Fand%5Fcv%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%
20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A
%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%22%29%3B%0D%0A
%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%
5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5
Fclass%5Fbody%7B%0D%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fclass%5Fstat%3E%3E%20a
rr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%
29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%2
0M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%2
0%20t%5Fclass%7B%0D%0A%20%20%20%20string%20keyword%3B%0D%0A%20%20%20%20t%5Fsep%2
0sep0%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D
%0A%20%20%20%20TAutoPtr%3Ct%5Fparents%3E%20parents%3B%0D%0A%20%20%20%20t%5Fsep%2
0sep2%3B%0D%0A%20%20%20%20TAutoPtr%3Ct%5Fclass%5Fbody%3E%20body%3B%0D%0A%20%20%2
0%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fan
y%5Fstr%5Ffrom%5Fvec%28keyword%2Csplit%28%22struct%2Cclass%2Cunion%22%2C%22%2C%2
2%29%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%2
0%20%20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28parents%29%3B%0
D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20O%2B%
3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D
%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0D%0A%20%20%20%20%7D%0D
%0A%20%20%7D%0D%0A%20%20t%5Fnamespace%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D
%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%2
0%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20t%5Fclass%5Fbody%20body%3B%0D%0A%20%20%20
%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22namespace%22%29%3B%0D%0A%20
%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5F
str%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29
%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D
%0A%20%20%7D%0D%0A%20%20t%5Ftemplate%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%
0A%20%20%20%20t%5Ftemplate%5Fparam%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20bef%3B%0D
%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Ftemplate%5Fparam%3E%20body%3B%0D%0A%20%20%20
%20%20%20t%5Fsep%20aft%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%
20O%2B%3Dgo%5Fauto%28bef%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28b
ody%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28aft%29%3B%0D%0A%20%20%
20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Foper%5Fcast%5Ftemplate%
5Fbody%3D%3Ei%5Ftemplate%5Fbody%7Bt%5Foper%5Fcast%5Fclass%5Fstat%3A%3At%5Fimpl%2
0body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fcommon%5Foper%5Ftem
plate%5Fbody%3D%3Ei%5Ftemplate%5Fbody%7Bt%5Fcommon%5Foper%5Fclass%5Fstat%3A%3At%
5Fimpl%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fctor%5Ftemp
late%5Fbody%3D%3Ei%5Ftemplate%5Fbody%7Bt%5Fctor%5Fclass%5Fstat%3A%3At%5Fimpl%20b
ody%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Ffunc%5Ftemplate%5Fbod
y%3D%3Ei%5Ftemplate%5Fbody%7B%0D%0A%20%20%20%20%20%20vector%3Ct%5Fkeyword%3E%20k
eywords%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%20t
ype%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv0%3B%0D%0
A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fcallc
onv%3E%20callconv%3B%0D%0A%20%20%20%20%20%20string%20func%5Fname%3B%0D%0A%20%20%
20%20%20%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%20concrete%5Fparams%3B%0D%0A%20%2
0%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3
At%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20%20%20t%5Fs
ep%20sep2%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv1%3
B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20%
20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28keywords%29%3B%0D%0A
%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%20%20%20
%20O%2B%3Dgo%5Fauto%28cv0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28
sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28callconv%29%3B%0D%0A%
20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28func%5Fname%29%3B%0D%0A%2
0%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28concrete%5Fparams%29%3B%0D%0A%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3D
go%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29
%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv1%29%3B%0D%0A%20%20%20%20%
20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%
20%20%7D%0D%0A%20%20%20%20t%5Fclass%5Ftemplate%5Fbody%3D%3Ei%5Ftemplate%5Fbody%7
B%0D%0A%20%20%20%20%20%20string%20keyword%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20se
p0%3B%0D%0A%20%20%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20s
ep1%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%20params%3B%0D
%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fparents%3E%20parents%3B%0D%0A%20%20%20%20%20
%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fclass%5Fbody%3E%20bod
y%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%2
0%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28keyword%2Csplit%28%22
struct%2Cclass%2Cunion%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B
%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fnam
e%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%
0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%2
0%20%20O%2B%3Dgo%5Fauto%28parents%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28body%29%3B%0D
%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D%0A%20%20%20%20%20%20
%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20
%20%20%7D%0D%0A%20%20%20%20t%5Fname%5Ftemplate%5Fparam%3D%3Ei%5Ftemplate%5Fparam
%7B%0D%0A%20%20%20%20%20%20t%5Funsgnd%7Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fconst%28%
22unsigned%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fvalue%7B%0D%0A%20%20%20%20%
20%20%20%20t%5Fexpr%20body%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0
A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fcons
t%28%22%3D%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29
%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20
%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20string%2
0unsgnd0%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20stri
ng%20type%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20str
ing%20unsgnd1%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%2
0string%20name%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20%20%
20TAutoPtr%3Ct%5Fvalue%3E%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%2
0%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Funsgnd%3E%28unsgnd0%29%3B%0D%0A%20%20%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5
Fstr%3Ct%5Fname%3E%28type%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28
sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Funsgnd%3E%28unsgnd
1%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%2
0%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%
20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fa
uto%28value%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20
%20t%5Fhead%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20v
ector%3Ct%5Ftemplate%5Fparam%3E%20params%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep
1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%2
8%22template%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B
%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3C%22%29%3B%0D%0A%20%20%20
%20%20%20%20%20O%2B%3Dgo%5Fvec%28params%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%2
0%20%20M%2B%3Dgo%5Fconst%28%22%3E%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dg
o%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%2
0%20%20t%5Ftype%5Ftemplate%5Fparam%3D%3Ei%5Ftemplate%5Fparam%7B%0D%0A%20%20%20%2
0%20%20TAutoPtr%3Ct%5Fhead%3E%20head%3B%0D%0A%20%20%20%20%20%20string%20type%3B%
0D%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20string%20name%3B%
0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28head%
29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28type%2Cs
plit%28%22class%2Ctypename%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5F
name%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20
%20%20t%5Fhead%20head%3B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Ftemplate%5Fbody%3E%20bo
dy%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28head%29%3B%
0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%
20%20%7D%0D%0A%20%20t%5Fenum%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20
%20%20t%5Fvalue%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20
%20t%5Fexpr%20expr%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20
%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3D%22%29%3B%0D%0A
%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8sep1%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5
Fitem%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%
20name%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20TAutoP
tr%3Ct%5Fvalue%3E%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%
20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%
3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%
29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20%20
%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fcomma%5Fwith%5Fsep%7Bt%5F
sep%20sep%3B%7BM%2B%3Dgo%5Fconst%28%22%2C%22%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%7
D%7D%0D%0A%20%20%20%20t%5Fimpl%5Fbody%3D%3Ei%5Fbody%7B%0D%0A%20%20%20%20%20%20ve
ctor%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fcomma%5Fwith%5
Fsep%3E%20comma%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%
3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28ar
r%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28comma%29%3B%
0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%20%
20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fempty%5Fbody%3D%3Ei%5Fbody
%7B%7Bgo%5Fconst%28%22%3B%22%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fbody%7BTAutoPtr%3C
i%5Fbody%3E%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fsep%20
sep0%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%
0A%20%20%20%20t%5Fbody%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2
B%3Dgo%5Fconst%28%22enum%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0
%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%2
0%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fusing%5Fcl
ass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%2
0%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%20type%3B%0D%0A%20%20%20%20%7B
%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22using%22%29%3B%0D%0A%20%20%20%20%
20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type
%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftmpl%5Fcall%5Fparam%7B
%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20t%5Ftmpl%5Fexpr%20expr%3B%0
D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B
%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%7D%0D%0A
%20%20%7D%0D%0A%20%20t%5Fcall%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7B%0D%0A%20%20%
20%20string%20func%3B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20vector%
3Ct%5Ftmpl%5Fcall%5Fparam%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28func%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0
A%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%
20%20t%5Fblock%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7B%0D%0A%20%20%20%20t%5Fsep%20
sep0%3B%0D%0A%20%20%20%20t%5Ftmpl%5Fexpr%20expr%3B%0D%0A%20%20%20%20t%5Fsep%20se
p1%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%
29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%2
9%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A%20%20%20%2
0%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fpfunc%5Fconcrete%5Fparam%5Fway%3D%3Ei%5Fconcr
ete%5Fparam%5Fway%7Bt%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Fpfunc%20
value%3B%7Bgo%5Fauto%28value%29%3B%7D%7D%0D%0A%20%20t%5Ftype%5Fconcrete%5Fparam%
5Fway%3D%3Ei%5Fconcrete%5Fparam%5Fway%7Bt%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fex
pr%3A%3At%5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5Fcv%20value%3B%7Bgo%5Fauto%28value%2
9%3B%7D%7D%0D%0A%20%20t%5Fexpr%5Fconcrete%5Fparam%5Fway%3D%3Ei%5Fconcrete%5Fpara
m%5Fway%7Bt%5Ftmpl%5Fexpr%20value%3B%7Bgo%5Fminor%3Ct%5Ftype%5Fconcrete%5Fparam%
5Fway%3E%28value%29%3B%7D%7D%0D%0A%20%20t%5Fbool%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fe
xpr%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22false
%2Ctrue%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0A%20%20t%5Fstring%5Ftmpl%5Fexpr%3D%3Ei
%5Ftmpl%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fstr%5Fitem%3A%3At%5Fimpl%3E%
28value%29%3B%7D%7D%0D%0A%20%20t%5Fchar%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7Bstr
ing%20value%3B%7Bgo%5Fstr%3Ct%5Fchar%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D
%0D%0A%20%20t%5Fnum%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7Bstring%20value%3B%7Bgo%
5Fany%28value%2Cgen%5Fdips%28%2209%22%29%29%3B%7D%7D%0D%0A%20%20t%5Freal%5Ftmpl%
5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Freal%3E%28value
%29%3B%7D%7D%0D%0A%20%20t%5Fnullptr%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7B%7Bgo%5
Fconst%28%22nullptr%22%29%3B%7D%7D%0D%0A%20%20t%5For%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl
%5Fexpr%7Bvector%3Ct%5Fname%3E%20arr%3B%7Bgo%5Fbin%5Foper%28arr%2C%22%7C%22%29%3
B%7D%7D%0D%0A%20%20t%5Fhex%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7B%0D%0A%20%20%20%
20t%5Fimpl%7Bchar%20x%3Bstring%20value%3B%7Bgo%5Fconst%28%220%22%29%3Bgo%5Fany%5
Fchar%28x%2C%22xX%22%29%3Bgo%5Fany%28value%2Cgen%5Fdips%28%2209afAF%22%29%29%3B%
7D%7Dstring%20value%3B%0D%0A%20%20%20%20%7Bgo%5Fstr%3Ct%5Fimpl%3E%28value%29%3B%
7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fvar%5Ftmpl%5Fexpr%3D%3Ei%5Ftmpl%5Fexpr%7Bstring
%20name%3B%7Bgo%5Fstr%3Ct%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3E%28name%29%
3B%7D%7D%0D%0A%20%20t%5Fpragma%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20b
ody%3B%7Bgo%5Fconst%28%22%23pragma%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D
%7D%0D%0A%20%20t%5Finclude%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20body%
3B%7Bgo%5Fconst%28%22%23include%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D%7D
%0D%0A%20%20t%5Fpreproc%5Fif%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20bod
y%3B%7Bgo%5Fconst%28%22%23if%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D%7D%0D
%0A%20%20t%5Fpreproc%5Felse%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20body
%3B%7Bgo%5Fconst%28%22%23else%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D%7D%0
D%0A%20%20t%5Fpreproc%5Fendif%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20bo
dy%3B%7Bgo%5Fconst%28%22%23endif%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D%7
D%0D%0A%20%20t%5Fdefine%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20body%3B%
7Bgo%5Fconst%28%22%23define%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D%7D%0D%
0A%20%20t%5Fundef%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%20body%3B%7Bgo%5
Fconst%28%22%23undef%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%7D%7D%0D%0A%20%2
0t%5Fsep%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bt%5Fsep%20sep%3B%7Bgo%5Fauto%28s
ep%29%3B%7D%7D%0D%0A%20%20t%5Fnull%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%7Bgo%
5Fconst%28%22%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fclass%5Fclass%5Fstat%3D%3Ei%5Fcla
ss%5Fstat%7Bt%5Fclass%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20t%5Fin
l%5Ffile%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20TAutoPtr%3
Ct%5Fclass%3E%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%2
0%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20vector%3CTAutoPtr%3Ci%5Fclass%5Fstat%3E%3E%
20arr%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fauto%28arr%29%3B%0D%0A%20%20%7D%0D
%0A%7D
*/
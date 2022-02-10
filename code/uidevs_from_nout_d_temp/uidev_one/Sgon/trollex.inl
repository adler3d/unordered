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
  ADD(t_call_expr)\
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
        F(t_call_expr);
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
  class t_first_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_first_scope)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_first_scope
  #include "QapGenStructNoTemplate.inl"
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
      //===>>===i_func_param_value_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_expr_func_param_value)\
      ADDEND()
    
      class i_func_param_value;
    
      #define DEF_PRO_BLANK()
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      #undef DEF_PRO_BLANK
    
      #define DEF_PRO_BLANK()
      class i_func_param_value_visitor{
      public:
        typedef t_type_expr::i_func_param_value i_func_param_value;
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
        static TYPE*UberCast(i_func_param_value*p){
          if(!p)return nullptr;Is<TYPE,i_func_param_value_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
      #undef DEF_PRO_BLANK
      #undef LIST
    public:
      class i_func_param_value{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_func_param_value)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_func_param_value
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_func_param_value
      public:
        typedef i_func_param_value_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          bool load()
          {
            F(t_expr_func_param_value);
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
      class t_arr_body{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr_body)OWNER(t_type_expr)
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
      ADDVAR(TAutoPtr<i_func_param_value>,value,DEF,$,$)\
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
      class t_expr_func_param_value:public i_func_param_value{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_func_param_value)PARENT(i_func_param_value)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_expr,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_expr_func_param_value
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_expr_func_param_value
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
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_typeexpr)PARENT(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<t_first_scope>,first,DEF,$,$)\
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
      F(t_arr_body                 )\
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
      F(t_expr_func_param_value    )\
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
  class t_call_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,func,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_expr
  #include "QapGenStructNoTemplate.inl"
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
    class t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_type_with_sep,body,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
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
        M+=dev.go_auto(body);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_const("::");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_field{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,bef,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_field
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_field
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
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_item>,items,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(vector<t_field>,arr,DEF,$,$)\
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
        O+=dev.go_auto(items);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_vec(arr,".");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item )\
    F(t_field)\
    F(t_impl )\
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
    ADDVAR(TAutoPtr<t_explicit>,prefix,DEF,$,$)\
    ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
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
        O+=dev.go_auto(prefix);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_cast_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
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
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_const("operator");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        static const auto g_static_var_7=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[],->",","));
        M+=dev.go_any_str_from_vec(oper,g_static_var_7);
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
    ADD(t_common_oper_template_body)\
    ADD(t_ctor_template_body)\
    ADD(t_func_template_body)\
    ADD(class_template_body)\
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
          F(t_common_oper_template_body);
          F(t_ctor_template_body);
          F(t_func_template_body);
          F(class_template_body);
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
    class class_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(class_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
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
    //=====+>>>>>class_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====class_template_body
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
    F(t_common_oper_template_body)\
    F(t_ctor_template_body       )\
    F(t_func_template_body       )\
    F(class_template_body        )\
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
  F(t_first_scope             )\
  F(t_const_with_sep          )\
  F(t_keyword                 )\
  F(t_ptr                     )\
  F(t_ref                     )\
  F(t_type_with_sep           )\
  F(t_scope_with_sep          )\
  F(t_scopes                  )\
  F(t_fv_class_stat           )\
  F(t_typedef_class_stat      )\
  F(t_real                    )\
  F(t_call_param              )\
  F(t_call_expr               )\
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
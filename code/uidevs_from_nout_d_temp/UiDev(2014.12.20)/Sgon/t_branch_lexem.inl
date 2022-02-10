//time = 21.96 ms.

class t_branch_lexem{
public:
  //===>>===i_case_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_hard)\
  ADD(t_soft)\
  ADDEND()

  class i_case;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_case_visitor{
  public:
    typedef t_branch_lexem::i_case i_case;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_branch_lexem::U U;
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
    static TYPE*UberCast(i_case*p){
      if(!p)return nullptr;Is<TYPE,i_case_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_case_visitor
  //class t_visitor:public t_branch_lexem::i_case_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_hard*p){}
  //  void Do(t_soft*p){}
  //};
public:
  class i_case{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_case)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_case
  #include "QapGenStruct.inl"
  //<<<<<+=====i_case
  public:
    typedef i_case_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_hard);
        F(t_soft);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_var_expr)\
  ADD(t_string_expr)\
  ADD(t_num_expr)\
  ADD(t_hexnum_expr)\
  ADD(t_bool_expr)\
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
    typedef t_branch_lexem::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_branch_lexem::U U;
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
  //class t_visitor:public t_branch_lexem::i_expr_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_var_expr*p){}
  //  void Do(t_string_expr*p){}
  //  void Do(t_num_expr*p){}
  //  void Do(t_hexnum_expr*p){}
  //  void Do(t_bool_expr*p){}
  //};
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_branch_lexem)
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
        F(t_var_expr);
        F(t_string_expr);
        F(t_num_expr);
        F(t_hexnum_expr);
        F(t_bool_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
public:
  //===>>===i_alias_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_alias_from_func_call)\
  ADD(t_alias_from_var_expr)\
  ADDEND()

  class i_alias;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_alias_visitor{
  public:
    typedef t_branch_lexem::i_alias i_alias;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_branch_lexem::U U;
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
    static TYPE*UberCast(i_alias*p){
      if(!p)return nullptr;Is<TYPE,i_alias_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_alias_visitor
  //class t_visitor:public t_branch_lexem::i_alias_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_alias_from_func_call*p){}
  //  void Do(t_alias_from_var_expr*p){}
  //};
public:
  class i_alias{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_alias)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_alias
  #include "QapGenStruct.inl"
  //<<<<<+=====i_alias
  public:
    typedef i_alias_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_alias_from_func_call);
        F(t_alias_from_var_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
public:
  //===>>===i_oper_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_set_oper)\
  ADD(t_inc_oper)\
  ADD(t_dec_oper)\
  ADDEND()

  class i_oper;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_oper_visitor{
  public:
    typedef t_branch_lexem::i_oper i_oper;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_branch_lexem::U U;
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
    static TYPE*UberCast(i_oper*p){
      if(!p)return nullptr;Is<TYPE,i_oper_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_oper_visitor
  //class t_visitor:public t_branch_lexem::i_oper_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_set_oper*p){}
  //  void Do(t_inc_oper*p){}
  //  void Do(t_dec_oper*p){}
  //};
public:
  class i_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_oper)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====i_oper
  public:
    typedef i_oper_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_set_oper);
        F(t_inc_oper);
        F(t_dec_oper);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
public:
  //===>>===i_line_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_alias)\
  ADD(t_line)\
  ADDEND()

  class i_line;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_line_visitor{
  public:
    typedef t_branch_lexem::i_line i_line;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_branch_lexem::U U;
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
    static TYPE*UberCast(i_line*p){
      if(!p)return nullptr;Is<TYPE,i_line_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_line_visitor
  //class t_visitor:public t_branch_lexem::i_line_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_alias*p){}
  //  void Do(t_line*p){}
  //};
public:
  class i_line{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_line)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_line
  #include "QapGenStruct.inl"
  //<<<<<+=====i_line
  public:
    typedef i_line_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_alias);
        F(t_line);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_hex_number{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex_number)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hex_number
  #include "QapGenStruct.inl"
  //<<<<<+=====t_hex_number
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("0x");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09afAF"));
      D+=dev.go_any(value,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_bool{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool
  #include "QapGenStruct.inl"
  //<<<<<+=====t_bool
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("true,false",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_number{
  public:
    class t_sign{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,value,DEF,$,$)\
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
        static const auto g_static_var_0=CharMask::fromStr("+-");
        D+=dev.go_any_char(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_sign)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,sign,DEF,$,$)\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number
  #include "QapGenStruct.inl"
  //<<<<<+=====t_number
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_str<TAutoPtr<t_sign>>(sign);
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      M+=dev.go_any(value,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_hard_barckets{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_barckets)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hard_barckets
  #include "QapGenStruct.inl"
  //<<<<<+=====t_hard_barckets
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("[");
      if(!ok)return ok;
      D+=dev.go_str<t_number>(value);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_hard:public i_case{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard)PARENT(i_case)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_hard_barckets>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hard
  #include "QapGenStruct.inl"
  //<<<<<+=====t_hard
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
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_template{
  public:
    class t_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_template)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_name>,arr,DEF,$,$)\
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
        D+=dev.go_vec(arr,"::");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_param)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_template
  #include "QapGenStruct.inl"
  //<<<<<+=====t_template
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("{");
      if(!ok)return ok;
      D+=dev.go_str<t_param>(name);
      if(!ok)return ok;
      D+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_soft:public i_case{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft)PARENT(i_case)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_template>,templ,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_soft
  #include "QapGenStruct.inl"
  //<<<<<+=====t_soft
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
      O+=dev.go_auto(templ);
      if(!ok)return ok;
      M+=dev.go_const("()");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(TAutoPtr<i_case>,ext,DEF,$,$)\
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
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(ext);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_var_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
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
      D+=dev.go_vec(arr,".");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_string_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      D+=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_num_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_expr)PARENT(i_expr)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_expr
  #include "QapGenStruct.inl"
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
      D+=dev.go_str<t_number>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_hexnum_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hexnum_expr)PARENT(i_expr)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hexnum_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_hexnum_expr
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
      D+=dev.go_str<t_hex_number>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_bool_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      D+=dev.go_str<t_bool>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_alias_from_func_call:public i_alias{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_alias_from_func_call)PARENT(i_alias)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,alias,DEF,$,$)\
  ADDVAR(string,func,DEF,$,$)\
  ADDVAR(string,str_param,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_alias_from_func_call
  #include "QapGenStruct.inl"
  //<<<<<+=====t_alias_from_func_call
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
      D+=dev.go_const("auto ");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(alias);
      if(!ok)return ok;
      D+=dev.go_const("=");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(func);
      if(!ok)return ok;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_str<t_str_item::t_impl>(str_param);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_alias_from_var_expr:public i_alias{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_alias_from_var_expr)PARENT(i_alias)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,alias,DEF,$,$)\
  ADDVAR(t_var_expr,var_expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_alias_from_var_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_alias_from_var_expr
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
      D+=dev.go_const("auto ");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(alias);
      if(!ok)return ok;
      D+=dev.go_const("=");
      if(!ok)return ok;
      D+=dev.go_auto(var_expr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_set_oper:public i_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_oper)PARENT(i_oper)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_set_oper
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
      D+=dev.go_const("=");
      if(!ok)return ok;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_inc_oper:public i_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inc_oper)PARENT(i_oper)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_inc_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_inc_oper
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
      D+=dev.go_const("++");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_dec_oper:public i_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dec_oper)PARENT(i_oper)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_dec_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_dec_oper
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
      D+=dev.go_const("--");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_oper>,value,DEF,$,$)\
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
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_alias:public i_line{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_alias)PARENT(i_line)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_alias>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_alias
  #include "QapGenStruct.inl"
  //<<<<<+=====t_alias
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
  class t_line:public i_line{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)PARENT(i_line)OWNER(t_branch_lexem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_var_expr,bef,DEF,$,$)\
  ADDVAR(TAutoPtr<t_oper>,opt,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_line
  #include "QapGenStruct.inl"
  //<<<<<+=====t_line
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
      M+=dev.go_auto(bef);
      if(!ok)return ok;
      O+=dev.go_auto(opt);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_hex_number          )\
  F(t_bool                )\
  F(t_number              )\
  F(t_hard_barckets       )\
  F(t_hard                )\
  F(t_template            )\
  F(t_soft                )\
  F(t_item                )\
  F(t_var_expr            )\
  F(t_string_expr         )\
  F(t_num_expr            )\
  F(t_hexnum_expr         )\
  F(t_bool_expr           )\
  F(t_alias_from_func_call)\
  F(t_alias_from_var_expr )\
  F(t_set_oper            )\
  F(t_inc_oper            )\
  F(t_dec_oper            )\
  F(t_oper                )\
  F(t_alias               )\
  F(t_line                )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_branch_lexem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_line>>,lines,DEF,$,$)\
ADDEND()
//=====+>>>>>t_branch_lexem
#include "QapGenStruct.inl"
//<<<<<+=====t_branch_lexem
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_vec(lines,"\n");
    if(!ok)return ok;
    return ok;
  }
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_branch_lexem::TYPE TYPE;
  //  F(i_case);
  //  F(i_expr);
  //  F(i_alias);
  //  F(i_oper);
  //  F(i_line);
  //  F(t_hex_number);
  //  F(t_bool);
  //  F(t_number);
  //  F(t_hard_barckets);
  //  F(t_hard);
  //  F(t_template);
  //  F(t_soft);
  //  F(t_item);
  //  F(t_var_expr);
  //  F(t_string_expr);
  //  F(t_num_expr);
  //  F(t_hexnum_expr);
  //  F(t_bool_expr);
  //  F(t_alias_from_func_call);
  //  F(t_alias_from_var_expr);
  //  F(t_set_oper);
  //  F(t_inc_oper);
  //  F(t_dec_oper);
  //  F(t_oper);
  //  F(t_alias);
  //  F(t_line);
  //  #undef F
  //public:
  //  void Do(t_hex_number&ref){}
  //  void Do(t_bool&ref){}
  //  void Do(t_number&ref){}
  //  void Do(t_hard_barckets&ref){}
  //  void Do(t_hard&ref){}
  //  void Do(t_template&ref){}
  //  void Do(t_soft&ref){}
  //  void Do(t_item&ref){}
  //  void Do(t_var_expr&ref){}
  //  void Do(t_string_expr&ref){}
  //  void Do(t_num_expr&ref){}
  //  void Do(t_hexnum_expr&ref){}
  //  void Do(t_bool_expr&ref){}
  //  void Do(t_alias_from_func_call&ref){}
  //  void Do(t_alias_from_var_expr&ref){}
  //  void Do(t_set_oper&ref){}
  //  void Do(t_inc_oper&ref){}
  //  void Do(t_dec_oper&ref){}
  //  void Do(t_oper&ref){}
  //  void Do(t_alias&ref){}
  //  void Do(t_line&ref){}
  //};
};

/*
//list of types:
F(t_branch_lexem)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fbranch%5Flexem%7B%0D%20%20t%5Fhex%5Fnumber%7B%0D%20%20%20%20string%20value%3
B%0D%20%20%20%20%7B%0D%20%20%20%20%20%20go%5Fconst%28%220x%22%29%3B%0D%20%20%20%
20%20%20go%5Fany%28value%2Cgen%5Fdips%28%2209afAF%22%29%29%3B%0D%20%20%20%20%7D%
0D%20%20%7D%0D%20%20t%5Fbool%7B%0D%20%20%20%20string%20value%3B%0D%20%20%20%20%7
B%0D%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22true%2Cfa
lse%22%2C%22%2C%22%29%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20t%5Fnumber%7B%
0D%20%20%20%20t%5Fsign%7Bchar%20value%3B%7Bgo%5Fany%5Fchar%28value%2C%22%2B%2D%2
2%29%3B%7D%7D%0D%20%20%20%20string%20sign%3B%0D%20%20%20%20string%20value%3B%0D%
20%20%20%20%7B%0D%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3CTAutoPtr%3Ct%5Fsign%3E%3E%2
8sign%29%3B%0D%20%20%20%20%20%20M%2B%3Dgo%5Fany%28value%2Cgen%5Fdips%28%2209%22%
29%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20t%5Fhard%5Fbarckets%7Bstring%20va
lue%3B%7Bgo%5Fconst%28%22%5B%22%29%3Bgo%5Fstr%3Ct%5Fnumber%3E%28value%29%3Bgo%5F
const%28%22%5D%22%29%3B%7D%7D%0D%20%20t%5Fhard%3D%3Ei%5Fcase%7Bvector%3Ct%5Fhard
%5Fbarckets%3E%20arr%3B%7Bgo%5Fauto%28arr%29%3B%7D%7D%0D%20%20t%5Ftemplate%7B%0D
%20%20%20%20t%5Fparam%7B%0D%20%20%20%20%20%20vector%3Ct%5Fname%3E%20arr%3B%0D%20
%20%20%20%20%20%7B%0D%20%20%20%20%20%20%20%20go%5Fvec%28arr%2C%22%3A%3A%22%29%3B
%0D%20%20%20%20%20%20%7D%0D%20%20%20%20%7D%0D%20%20%20%20string%20name%3B%0D%20%
20%20%20%7B%0D%20%20%20%20%20%20go%5Fconst%28%22%7B%22%29%3B%0D%20%20%20%20%20%2
0go%5Fstr%3Ct%5Fparam%3E%28name%29%3B%0D%20%20%20%20%20%20go%5Fconst%28%22%7D%22
%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20t%5Fsoft%3D%3Ei%5Fcase%7B%0D%20%20%
20%20TAutoPtr%3Ct%5Ftemplate%3E%20templ%3B%0D%20%20%20%20%7B%0D%20%20%20%20%20%2
0O%2B%3Dgo%5Fauto%28templ%29%3B%0D%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%2
9%22%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20t%5Fitem%7B%0D%20%20%20%20strin
g%20name%3B%0D%20%20%20%20TAutoPtr%3Ci%5Fcase%3E%20ext%3B%0D%20%20%20%20%7B%0D%2
0%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%20%20%20%20%20%20O
%2B%3Dgo%5Fauto%28ext%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20t%5Fvar%5Fexpr
%3D%3Ei%5Fexpr%7B%0D%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%20%20%20%20%7B%
0D%20%20%20%20%20%20go%5Fvec%28arr%2C%22%2E%22%29%3B%0D%20%20%20%20%7D%0D%20%20%
7D%0D%20%20t%5Fstring%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5F
str%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D%0D%20%20t%5Fnum%5Fexpr%3D%3Ei%5F
expr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fnumber%3E%28value%29%3B%7D%7D%0D%20%20
t%5Fhexnum%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fhex%5Fnumbe
r%3E%28value%29%3B%7D%7D%0D%20%20t%5Fbool%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%
3B%7Bgo%5Fstr%3Ct%5Fbool%3E%28value%29%3B%7D%7D%0D%20%20t%5Falias%5Ffrom%5Ffunc%
5Fcall%3D%3Ei%5Falias%7B%0D%20%20%20%20string%20alias%3B%0D%20%20%20%20string%20
func%3B%0D%20%20%20%20string%20str%5Fparam%3B%0D%20%20%20%20%7B%0D%20%20%20%20%2
0%20go%5Fconst%28%22auto%20%22%29%3B%0D%20%20%20%20%20%20go%5Fstr%3Ct%5Fname%3E%
28alias%29%3B%0D%20%20%20%20%20%20go%5Fconst%28%22%3D%22%29%3B%0D%20%20%20%20%20
%20go%5Fstr%3Ct%5Fname%3E%28func%29%3B%0D%20%20%20%20%20%20go%5Fconst%28%22%28%2
2%29%3B%0D%20%20%20%20%20%20go%5Fstr%3Ct%5Fstr%5Fitem%3A%3At%5Fimpl%3E%28str%5Fp
aram%29%3B%0D%20%20%20%20%20%20go%5Fconst%28%22%29%22%29%3B%0D%20%20%20%20%7D%0D
%20%20%7D%0D%20%20t%5Falias%5Ffrom%5Fvar%5Fexpr%3D%3Ei%5Falias%7B%0D%20%20%20%20
string%20alias%3B%0D%20%20%20%20t%5Fvar%5Fexpr%20var%5Fexpr%3B%0D%20%20%20%20%7B
%0D%20%20%20%20%20%20go%5Fconst%28%22auto%20%22%29%3B%0D%20%20%20%20%20%20go%5Fs
tr%3Ct%5Fname%3E%28alias%29%3B%0D%20%20%20%20%20%20go%5Fconst%28%22%3D%22%29%3B%
0D%20%20%20%20%20%20go%5Fauto%28var%5Fexpr%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0
D%20%20t%5Fset%5Foper%3D%3Ei%5Foper%7B%0D%20%20%20%20TAutoPtr%3Ci%5Fexpr%3E%20va
lue%3B%0D%20%20%20%20%7B%0D%20%20%20%20%20%20go%5Fconst%28%22%3D%22%29%3B%0D%20%
20%20%20%20%20go%5Fauto%28value%29%3B%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20t%5F
inc%5Foper%3D%3Ei%5Foper%7B%7Bgo%5Fconst%28%22%2B%2B%22%29%3B%7D%7D%0D%20%20t%5F
dec%5Foper%3D%3Ei%5Foper%7B%7Bgo%5Fconst%28%22%2D%2D%22%29%3B%7D%7D%0D%20%20t%5F
oper%7BTAutoPtr%3Ci%5Foper%3E%20value%3B%7Bgo%5Fauto%28value%29%3B%7D%7D%0D%20%2
0t%5Falias%3D%3Ei%5Fline%7B%0D%20%20%20%20TAutoPtr%3Ci%5Falias%3E%20body%3B%0D%2
0%20%20%20%7B%0D%20%20%20%20%20%20go%5Fauto%28body%29%3B%0D%20%20%20%20%7D%0D%20
%20%7D%0D%20%20t%5Fline%3D%3Ei%5Fline%7B%0D%20%20%20%20t%5Fvar%5Fexpr%20bef%3B%0
D%20%20%20%20TAutoPtr%3Ct%5Foper%3E%20opt%3B%0D%20%20%20%20%7B%0D%20%20%20%20%20
%20M%2B%3Dgo%5Fauto%28bef%29%3B%0D%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28opt%29%3B
%0D%20%20%20%20%7D%0D%20%20%7D%0D%20%20vector%3CTAutoPtr%3Ci%5Fline%3E%3E%20line
s%3B%0D%20%20%7B%0D%20%20%20%20go%5Fvec%28lines%2C%22%5Cn%22%29%3B%0D%20%20%7D%0
D%7D
*/
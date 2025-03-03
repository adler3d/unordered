//time = 36.48 ms.

class t_smart_asm{
public:
  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_num_expr)\
  ADD(t_reg_expr)\
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
    typedef t_smart_asm::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_smart_asm::U U;
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
  //class t_visitor:public t_smart_asm::i_expr_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_num_expr*p){}
  //  void Do(t_reg_expr*p){}
  //};
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_smart_asm)
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
        F(t_num_expr);
        F(t_reg_expr);
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
  ADD(t_nop_stat)\
  ADD(t_ret_stat)\
  ADD(t_call_stat)\
  ADD(t_block_stat)\
  ADD(t_auto_stat)\
  ADD(t_var_stat)\
  ADD(t_if_stat)\
  ADD(t_loop_stat)\
  ADD(t_for_stat)\
  ADD(t_break_stat)\
  ADD(t_continue_stat)\
  ADD(t_sep_stat)\
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
    typedef t_smart_asm::i_stat i_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_smart_asm::U U;
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
  //class t_visitor:public t_smart_asm::i_stat_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_nop_stat*p){}
  //  void Do(t_ret_stat*p){}
  //  void Do(t_call_stat*p){}
  //  void Do(t_block_stat*p){}
  //  void Do(t_auto_stat*p){}
  //  void Do(t_var_stat*p){}
  //  void Do(t_if_stat*p){}
  //  void Do(t_loop_stat*p){}
  //  void Do(t_for_stat*p){}
  //  void Do(t_break_stat*p){}
  //  void Do(t_continue_stat*p){}
  //  void Do(t_sep_stat*p){}
  //};
public:
  class i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)OWNER(t_smart_asm)
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
        F(t_nop_stat);
        F(t_ret_stat);
        F(t_call_stat);
        F(t_block_stat);
        F(t_auto_stat);
        F(t_var_stat);
        F(t_if_stat);
        F(t_loop_stat);
        F(t_for_stat);
        F(t_break_stat);
        F(t_continue_stat);
        F(t_sep_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
public:
  //===>>===i_node_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_func_node)\
  ADD(t_struct_node)\
  ADD(t_sep_node)\
  ADDEND()

  class i_node;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_node_visitor{
  public:
    typedef t_smart_asm::i_node i_node;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_smart_asm::U U;
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
    static TYPE*UberCast(i_node*p){
      if(!p)return nullptr;Is<TYPE,i_node_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_node_visitor
  //class t_visitor:public t_smart_asm::i_node_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_func_node*p){}
  //  void Do(t_struct_node*p){}
  //  void Do(t_sep_node*p){}
  //};
public:
  class i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_node)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_node
  #include "QapGenStruct.inl"
  //<<<<<+=====i_node
  public:
    typedef i_node_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_func_node);
        F(t_struct_node);
        F(t_sep_node);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_string{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)OWNER(t_smart_asm)
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
  class t_number{
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
      typedef t_number::i_val i_val;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_number::U U;
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
    //class t_visitor:public t_number::i_val_visitor{
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_val)OWNER(t_number)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_val)OWNER(t_number)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_val)OWNER(t_number)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
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
      D+=dev.go_str<TAutoPtr<i_val>>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_num_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_expr)PARENT(i_expr)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
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
  class t_reg_expr:public i_expr{
  public:
    //===>>===i_ext_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_field)\
    ADD(t_id)\
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
      typedef t_reg_expr::i_ext i_ext;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_reg_expr::U U;
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
    //===<<===i_ext_visitor
    //class t_visitor:public t_reg_expr::i_ext_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_field*p){}
    //  void Do(t_id*p){}
    //};
  public:
    class i_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_ext)OWNER(t_reg_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_ext
    #include "QapGenStruct.inl"
    //<<<<<+=====i_ext
    public:
      typedef i_ext_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_field);
          F(t_id);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_field:public i_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)PARENT(i_ext)OWNER(t_reg_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,field,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_field
    #include "QapGenStruct.inl"
    //<<<<<+=====t_field
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
        D+=dev.go_const(".");
        if(!ok)return ok;
        D+=dev.go_str<t_name>(field);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_id:public i_ext{
    public:
      //===>>===i_case_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_num)\
      ADD(t_reg)\
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
        typedef t_id::i_case i_case;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_id::U U;
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
      //class t_visitor:public t_id::i_case_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_num*p){}
      //  void Do(t_reg*p){}
      //};
    public:
      class i_case{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_case)OWNER(t_id)
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
            F(t_num);
            F(t_reg);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
          #include "QapLexPolyEnd.inl"
        };
      };
      class t_num:public i_case{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_case)OWNER(t_id)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,value,DEF,$,$)\
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
          D+=dev.go_str<t_number>(value);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_reg:public i_case{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_reg)PARENT(i_case)OWNER(t_id)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,value,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_reg
      #include "QapGenStruct.inl"
      //<<<<<+=====t_reg
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
          D+=dev.go_str<t_name>(value);
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_num)\
      F(t_reg)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_id)PARENT(i_ext)OWNER(t_reg_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_case>,idexpr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_id
    #include "QapGenStruct.inl"
    //<<<<<+=====t_id
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
        D+=dev.go_const("[");
        if(!ok)return ok;
        D+=dev.go_auto(idexpr);
        if(!ok)return ok;
        D+=dev.go_const("]");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ext)OWNER(t_reg_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_ext>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ext
    #include "QapGenStruct.inl"
    //<<<<<+=====t_ext
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
    F(t_field)\
    F(t_id   )\
    F(t_ext  )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_reg_expr)PARENT(i_expr)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,name,DEF,$,$)\
  ADDVAR(1,TAutoPtr<t_ext>,ext,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_reg_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_reg_expr
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
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(ext);
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_reg_expr::TYPE TYPE;
    //  F(i_ext);
    //  F(t_field);
    //  F(t_id);
    //  F(t_ext);
    //  #undef F
    //public:
    //  void Do(t_field&ref){}
    //  void Do(t_id&ref){}
    //  void Do(t_ext&ref){}
    //};
  };
  class t_nop_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nop_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_nop_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_nop_stat
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
      D+=dev.go_const("nop");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ret_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TAutoPtr<i_expr>,expr,DEF,$,$)\
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
      D+=dev.go_const("ret");
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_label{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_label)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,string,name,DEF,$,$)\
  ADDVAR(2,t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_label
  #include "QapGenStruct.inl"
  //<<<<<+=====t_label
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_stat:public i_stat{
  public:
    class t_params{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_call_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
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
        D+=dev.go_const(" ");
        if(!ok)return ok;
        D+=dev.go_vec(arr," ");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_params)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_string,func,DEF,$,$)\
  ADDVAR(1,t_reg_expr,out,DEF,$,$)\
  ADDVAR(2,TAutoPtr<t_params>,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_call_stat
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
      M+=dev.go_const("call");
      if(!ok)return ok;
      M+=dev.go_const(" ");
      if(!ok)return ok;
      M+=dev.go_auto(func);
      if(!ok)return ok;
      M+=dev.go_const(" ");
      if(!ok)return ok;
      M+=dev.go_auto(out);
      if(!ok)return ok;
      O+=dev.go_auto(params);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_block{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_block,body,DEF,$,$)\
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
  class t_type{
  public:
    class t_params{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_type)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,t_number,count,DEF,$,$)\
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
        D+=dev.go_str<t_type>(type);
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_params)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_name,name,DEF,$,$)\
  ADDVAR(1,TAutoPtr<t_params>,params,DEF,$,$)\
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
      M+=dev.go_auto(name);
      if(!ok)return ok;
      O+=dev.go_auto(params);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_auto_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_auto_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_name,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_auto_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_auto_stat
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
      D+=dev.go_const("auto");
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_var_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_type,type,DEF,$,$)\
  ADDVAR(1,t_name,name,DEF,$,$)\
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
      D+=dev.go_const("var");
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(type);
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_if_stat:public i_stat{
  public:
    class t_cond{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cond)OWNER(t_if_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_cond
    #include "QapGenStruct.inl"
    //<<<<<+=====t_cond
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("cond");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_then{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_then)OWNER(t_if_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_then
    #include "QapGenStruct.inl"
    //<<<<<+=====t_then
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("then");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_else{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else)OWNER(t_if_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
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
    F(t_cond)\
    F(t_then)\
    F(t_else)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_if_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,t_cond,cond,DEF,$,$)\
  ADDVAR(2,TAutoPtr<t_then>,bef,DEF,$,$)\
  ADDVAR(3,TAutoPtr<t_else>,aft,DEF,$,$)\
  ADDVAR(4,t_sep,sep1,DEF,$,$)\
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
      M+=dev.go_const("{");
      if(!ok)return ok;
      M+=dev.go_auto(cond);
      if(!ok)return ok;
      O+=dev.go_auto(bef);
      if(!ok)return ok;
      O+=dev.go_auto(aft);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_if_stat::TYPE TYPE;
    //  F(t_cond);
    //  F(t_then);
    //  F(t_else);
    //  #undef F
    //public:
    //  void Do(t_cond&ref){}
    //  void Do(t_then&ref){}
    //  void Do(t_else&ref){}
    //};
  };
  class t_loop_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_loop_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep,DEF,$,$)\
  ADDVAR(1,TAutoPtr<t_label>,label,DEF,$,$)\
  ADDVAR(2,t_block,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_loop_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_loop_stat
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
      M+=dev.go_const("loop");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      O+=dev.go_auto(label);
      if(!ok)return ok;
      M+=dev.go_auto(code);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_for_stat:public i_stat{
  public:
    class t_rec{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rec)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep,DEF,$,$)\
    ADDVAR(1,t_var_stat,var,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_rec
    #include "QapGenStruct.inl"
    //<<<<<+=====t_rec
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_auto(var);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_init{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_init)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_init
    #include "QapGenStruct.inl"
    //<<<<<+=====t_init
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("init");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_cond{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cond)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_cond
    #include "QapGenStruct.inl"
    //<<<<<+=====t_cond
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("cond");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_body)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_body
    #include "QapGenStruct.inl"
    //<<<<<+=====t_body
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("body");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep0,DEF,$,$)\
    ADDVAR(1,t_sep,sep1,DEF,$,$)\
    ADDVAR(2,t_block,body,DEF,$,$)\
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
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("next");
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
    F(t_rec )\
    F(t_init)\
    F(t_cond)\
    F(t_body)\
    F(t_next)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_sep,sep0,DEF,$,$)\
  ADDVAR(1,TAutoPtr<t_label>,label,DEF,$,$)\
  ADDVAR(2,vector<t_rec>,arr,DEF,$,$)\
  ADDVAR(3,TAutoPtr<t_init>,init,DEF,$,$)\
  ADDVAR(4,TAutoPtr<t_cond>,cond,DEF,$,$)\
  ADDVAR(5,TAutoPtr<t_body>,body,DEF,$,$)\
  ADDVAR(6,TAutoPtr<t_next>,next,DEF,$,$)\
  ADDVAR(7,t_sep,sep1,DEF,$,$)\
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
      O+=dev.go_auto(label);
      if(!ok)return ok;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      O+=dev.go_auto(init);
      if(!ok)return ok;
      O+=dev.go_auto(cond);
      if(!ok)return ok;
      O+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(next);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_for_stat::TYPE TYPE;
    //  F(t_rec);
    //  F(t_init);
    //  F(t_cond);
    //  F(t_body);
    //  F(t_next);
    //  #undef F
    //public:
    //  void Do(t_rec&ref){}
    //  void Do(t_init&ref){}
    //  void Do(t_cond&ref){}
    //  void Do(t_body&ref){}
    //  void Do(t_next&ref){}
    //};
  };
  class t_break_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_break_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TAutoPtr<t_label>,label,DEF,$,$)\
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
      M+=dev.go_const("break");
      if(!ok)return ok;
      O+=dev.go_auto(label);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_continue_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_continue_stat)PARENT(i_stat)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TAutoPtr<t_label>,label,DEF,$,$)\
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
      M+=dev.go_const("continue");
      if(!ok)return ok;
      O+=dev.go_auto(label);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_smart_asm)
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
  class t_func_node:public i_node{
  public:
    class t_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_func_node)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
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
        M+=dev.go_str<t_type>(type);
        if(!ok)return ok;
        M+=dev.go_const(" ");
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_param)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_node)PARENT(i_node)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,type,DEF,$,$)\
  ADDVAR(1,t_string,name,DEF,$,$)\
  ADDVAR(2,vector<t_param>,params,DEF,$,$)\
  ADDVAR(3,t_sep,sep,DEF,$,$)\
  ADDVAR(4,t_block,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_func_node
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_node
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
      M+=dev.go_str<t_type>(type);
      if(!ok)return ok;
      M+=dev.go_const(" ");
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(params,",");
      if(!ok)return ok;
      M+=dev.go_const(")asm");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(code);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_struct_node:public i_node{
  public:
    class t_field{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_struct_node)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_sep,sep,DEF,$,$)\
    ADDVAR(1,string,type,DEF,$,$)\
    ADDVAR(2,string,name,DEF,$,$)\
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
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_str<t_type>(type);
        if(!ok)return ok;
        M+=dev.go_const(" ");
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        M+=dev.go_const(";");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_field)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_node)PARENT(i_node)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,name,DEF,$,$)\
  ADDVAR(1,t_sep,sep0,DEF,$,$)\
  ADDVAR(2,vector<t_field>,arr,DEF,$,$)\
  ADDVAR(3,t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_node
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_node
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
      M+=dev.go_const("struct ");
      if(!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_node:public i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_node)PARENT(i_node)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_node
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sep_node
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
      D+=dev.go_str<t_sep>(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_asm_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_asm_scope)OWNER(t_smart_asm)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_node>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_asm_scope
  #include "QapGenStruct.inl"
  //<<<<<+=====t_asm_scope
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
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_string       )\
  F(t_number       )\
  F(t_num_expr     )\
  F(t_reg_expr     )\
  F(t_nop_stat     )\
  F(t_ret_stat     )\
  F(t_label        )\
  F(t_call_stat    )\
  F(t_block        )\
  F(t_block_stat   )\
  F(t_type         )\
  F(t_auto_stat    )\
  F(t_var_stat     )\
  F(t_if_stat      )\
  F(t_loop_stat    )\
  F(t_for_stat     )\
  F(t_break_stat   )\
  F(t_continue_stat)\
  F(t_sep_stat     )\
  F(t_func_node    )\
  F(t_struct_node  )\
  F(t_sep_node     )\
  F(t_asm_scope    )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_smart_asm)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_smart_asm
#include "QapGenStruct.inl"
//<<<<<+=====t_smart_asm
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_smart_asm::TYPE TYPE;
  //  F(i_expr);
  //  F(i_stat);
  //  F(i_node);
  //  F(t_string);
  //  F(t_number);
  //  F(t_num_expr);
  //  F(t_reg_expr);
  //  F(t_nop_stat);
  //  F(t_ret_stat);
  //  F(t_label);
  //  F(t_call_stat);
  //  F(t_block);
  //  F(t_block_stat);
  //  F(t_type);
  //  F(t_auto_stat);
  //  F(t_var_stat);
  //  F(t_if_stat);
  //  F(t_loop_stat);
  //  F(t_for_stat);
  //  F(t_break_stat);
  //  F(t_continue_stat);
  //  F(t_sep_stat);
  //  F(t_func_node);
  //  F(t_struct_node);
  //  F(t_sep_node);
  //  F(t_asm_scope);
  //  #undef F
  //public:
  //  void Do(t_string&ref){}
  //  void Do(t_number&ref){}
  //  void Do(t_num_expr&ref){}
  //  void Do(t_reg_expr&ref){}
  //  void Do(t_nop_stat&ref){}
  //  void Do(t_ret_stat&ref){}
  //  void Do(t_label&ref){}
  //  void Do(t_call_stat&ref){}
  //  void Do(t_block&ref){}
  //  void Do(t_block_stat&ref){}
  //  void Do(t_type&ref){}
  //  void Do(t_auto_stat&ref){}
  //  void Do(t_var_stat&ref){}
  //  void Do(t_if_stat&ref){}
  //  void Do(t_loop_stat&ref){}
  //  void Do(t_for_stat&ref){}
  //  void Do(t_break_stat&ref){}
  //  void Do(t_continue_stat&ref){}
  //  void Do(t_sep_stat&ref){}
  //  void Do(t_func_node&ref){}
  //  void Do(t_struct_node&ref){}
  //  void Do(t_sep_node&ref){}
  //  void Do(t_asm_scope&ref){}
  //};
};

/*
//list of types:
F(t_smart_asm)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fsmart%5Fasm%7B%0D%0A%0D%0At%5Fstring%7B%0D%0A%20%20string%20value%3B%0D%0A%2
0%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0D%0A%20%20%20%2
0O%2B%3Dgo%5Fstr%3Cvector%3CTAutoPtr%3Ci%5Fstr%5Fitem%3E%3E%3E%28value%29%3B%0D%
0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%
0A%0D%0At%5Fnumber%7B%0D%0A%20%20t%5Fzero%3D%3Ei%5Fval%7B%0D%0A%20%20%20%20%7B%0
D%0A%20%20%20%20%20%20go%5Fconst%28%220%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%2
0%7D%0D%0A%20%20t%5Fnum%3D%3Ei%5Fval%7B%0D%0A%20%20%20%20char%20first%3D%271%27%
3B%0D%0A%20%20%20%20string%20num%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20
M%2B%3Dgo%5Fany%5Fchar%28first%2Cgen%5Fdips%28%2219%22%29%29%3B%0D%0A%20%20%20%2
0%20%20O%2B%3Dgo%5Fany%28num%2Cgen%5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%
7D%0D%0A%20%20%7D%0D%0A%20%20string%20value%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20g
o%5Fstr%3CTAutoPtr%3Ci%5Fval%3E%3E%28value%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0
D%0At%5Fnum%5Fexpr%3D%3Ei%5Fexpr%7B%0D%0A%20%20string%20value%3B%0D%0A%20%20%7B%
0D%0A%20%20%20%20go%5Fstr%3Ct%5Fnumber%3E%28value%29%3B%0D%0A%20%20%7D%0D%0A%7D%
0D%0A%0D%0At%5Freg%5Fexpr%3D%3Ei%5Fexpr%7B%0D%0A%20%20t%5Ffield%3D%3Ei%5Fext%7B%
0D%0A%20%20%20%20string%20field%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20g
o%5Fconst%28%22%2E%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fstr%3Ct%5Fname%3E%28fiel
d%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fid%3D%3Ei%5Fext%7B%0D
%0A%20%20%20%20t%5Fnum%3D%3Ei%5Fcase%7B%0D%0A%20%20%20%20%20%20string%20value%3B
%7Bgo%5Fstr%3Ct%5Fnumber%3E%28value%29%3B%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20
%20t%5Freg%3D%3Ei%5Fcase%7B%0D%0A%20%20%20%20%20%20string%20value%3B%7Bgo%5Fstr%
3Ct%5Fname%3E%28value%29%3B%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20TAutoPtr%3C
i%5Fcase%3E%20idexpr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%2
8%22%5B%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fauto%28idexpr%29%3B%0D%0A%20%20%20%
20%20%20go%5Fconst%28%22%5D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%2
0%20t%5Fext%7B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Fext%3E%20body%3B%0D%0A%20%20%20%2
0%7Bgo%5Fauto%28body%29%3B%7D%0D%0A%20%20%7D%0D%0A%20%20string%20name%3B%0D%0A%2
0%20TAutoPtr%3Ct%5Fext%3E%20ext%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5Fs
tr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28ext%29%3B%0D%0
A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fnop%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20%7B%0D
%0A%20%20%20%20go%5Fconst%28%22nop%22%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At
%5Fret%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20TAutoPtr%3Ci%5Fexpr%3E%20expr%3B%0D%0A
%20%20%7B%0D%0A%20%20%20%20go%5Fconst%28%22ret%22%29%3B%0D%0A%20%20%20%20go%5Fco
nst%28%22%20%22%29%3B%0D%0A%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%7D%0D%
0A%7D%0D%0A%0D%0At%5Flabel%7B%0D%0A%20%20t%5Fsep%20sep0%3B%0D%0A%20%20string%20n
ame%3B%0D%0A%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5F
const%28%22%3A%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%
20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5F
auto%28sep1%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fcall%5Fstat%3D%3Ei%5Fst
at%7B%0D%0A%20%20t%5Fparams%7B%0D%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fexpr%3E%
3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%20%22%2
9%3B%0D%0A%20%20%20%20%20%20go%5Fvec%28arr%2C%22%20%22%29%3B%0D%0A%20%20%20%20%7
D%0D%0A%20%20%7D%0D%0A%20%20t%5Fstring%20func%3B%0D%0A%20%20t%5Freg%5Fexpr%20out
%3B%0D%0A%20%20TAutoPtr%3Ct%5Fparams%3E%20params%3B%0D%0A%20%20%7B%0D%0A%20%20%2
0%20M%2B%3Dgo%5Fconst%28%22call%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%20%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fauto%28func%29%3B%0D%0A%20%20%20%20M%
2B%3Dgo%5Fconst%28%22%20%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fauto%28out%29%3B%
0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0
D%0At%5Fblock%7B%0D%0A%20%20vector%3CTAutoPtr%3Ci%5Fstat%3E%3E%20arr%3B%0D%0A%20
%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20O%2
B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0
D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fblock%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20t
%5Fblock%20body%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fauto%28body%29%3B%0D%0A%
20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Ftype%7B%0D%0A%20%20t%5Fparams%7B%0D%0A%20%20%20
%20string%20type%3B%0D%0A%20%20%20%20t%5Fnumber%20count%3B%0D%0A%20%20%20%20%7B%
0D%0A%20%20%20%20%20%20go%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20%20%20go%5F
str%3Ct%5Ftype%3E%28type%29%3B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%2C%22%29%
3B%0D%0A%20%20%20%20%20%20go%5Fauto%28count%29%3B%0D%0A%20%20%20%20%20%20go%5Fco
nst%28%22%7D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fname%20
name%3B%0D%0A%20%20TAutoPtr%3Ct%5Fparams%3E%20params%3B%0D%0A%20%20%7B%0D%0A%20%
20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28params
%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fauto%5Fstat%3D%3Ei%5Fstat%7B%0D%0A
%20%20t%5Fname%20name%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fconst%28%22auto%22
%29%3B%0D%0A%20%20%20%20go%5Fconst%28%22%20%22%29%3B%0D%0A%20%20%20%20go%5Fauto%
28name%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fvar%5Fstat%3D%3Ei%5Fstat%7B%
0D%0A%20%20t%5Ftype%20type%3B%0D%0A%20%20t%5Fname%20name%3B%0D%0A%20%20%7B%0D%0A
%20%20%20%20go%5Fconst%28%22var%22%29%3B%0D%0A%20%20%20%20go%5Fconst%28%22%20%22
%29%3B%0D%0A%20%20%20%20go%5Fauto%28type%29%3B%0D%0A%20%20%20%20go%5Fconst%28%22
%20%22%29%3B%0D%0A%20%20%20%20go%5Fauto%28name%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%
0A%0D%0At%5Fif%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20t%5Fcond%7Bt%5Fsep%20sep0%3Bt%
5Fsep%20sep1%3Bt%5Fblock%20body%3B%7BO%2B%3Dgo%5Fauto%28sep0%29%3BM%2B%3Dgo%5Fco
nst%28%22cond%22%29%3BO%2B%3Dgo%5Fauto%28sep1%29%3BM%2B%3Dgo%5Fauto%28body%29%3B
%7D%7D%0D%0A%20%20t%5Fthen%7Bt%5Fsep%20sep0%3Bt%5Fsep%20sep1%3Bt%5Fblock%20body%
3B%7BO%2B%3Dgo%5Fauto%28sep0%29%3BM%2B%3Dgo%5Fconst%28%22then%22%29%3BO%2B%3Dgo%
5Fauto%28sep1%29%3BM%2B%3Dgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20t%5Felse%7Bt%5
Fsep%20sep0%3Bt%5Fsep%20sep1%3Bt%5Fblock%20body%3B%7BO%2B%3Dgo%5Fauto%28sep0%29%
3BM%2B%3Dgo%5Fconst%28%22else%22%29%3BO%2B%3Dgo%5Fauto%28sep1%29%3BM%2B%3Dgo%5Fa
uto%28body%29%3B%7D%7D%0D%0A%20%20t%5Fsep%20sep0%3B%0D%0A%20%20t%5Fcond%20cond%3
B%0D%0A%20%20TAutoPtr%3Ct%5Fthen%3E%20bef%3B%0D%0A%20%20TAutoPtr%3Ct%5Felse%3E%2
0aft%3B%0D%0A%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5
Fconst%28%22if%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%
20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fauto%28
cond%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28bef%29%3B%0D%0A%20%20%20%20O%2B%3
Dgo%5Fauto%28aft%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%2
0%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%
5Floop%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20t%5Fsep%20sep%3B%0D%0A%20%20TAutoPtr%3
Ct%5Flabel%3E%20label%3B%0D%0A%20%20t%5Fblock%20code%3B%0D%0A%20%20%7B%0D%0A%20%
20%20%20M%2B%3Dgo%5Fconst%28%22loop%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%2
8sep%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28label%29%3B%0D%0A%20%20%20%20M%2B
%3Dgo%5Fauto%28code%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Ffor%5Fstat%3D%3
Ei%5Fstat%7B%0D%0A%20%20t%5Frec%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20
%20%20t%5Fvar%5Fstat%20var%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%3
Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28var%29%3B%0D%0A
%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Finit%7Bt%5Fsep%20sep0%3Bt%5Fsep%20
sep1%3Bt%5Fblock%20body%3B%7BO%2B%3Dgo%5Fauto%28sep0%29%3BM%2B%3Dgo%5Fconst%28%2
2init%22%29%3BO%2B%3Dgo%5Fauto%28sep1%29%3BM%2B%3Dgo%5Fauto%28body%29%3B%7D%7D%0
D%0A%20%20t%5Fcond%7Bt%5Fsep%20sep0%3Bt%5Fsep%20sep1%3Bt%5Fblock%20body%3B%7BO%2
B%3Dgo%5Fauto%28sep0%29%3BM%2B%3Dgo%5Fconst%28%22cond%22%29%3BO%2B%3Dgo%5Fauto%2
8sep1%29%3BM%2B%3Dgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20t%5Fbody%7Bt%5Fsep%20s
ep0%3Bt%5Fsep%20sep1%3Bt%5Fblock%20body%3B%7BO%2B%3Dgo%5Fauto%28sep0%29%3BM%2B%3
Dgo%5Fconst%28%22body%22%29%3BO%2B%3Dgo%5Fauto%28sep1%29%3BM%2B%3Dgo%5Fauto%28bo
dy%29%3B%7D%7D%0D%0A%20%20t%5Fnext%7Bt%5Fsep%20sep0%3Bt%5Fsep%20sep1%3Bt%5Fblock
%20body%3B%7BO%2B%3Dgo%5Fauto%28sep0%29%3BM%2B%3Dgo%5Fconst%28%22next%22%29%3BO%
2B%3Dgo%5Fauto%28sep1%29%3BM%2B%3Dgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20t%5Fse
p%20sep0%3B%0D%0A%20%20TAutoPtr%3Ct%5Flabel%3E%20label%3B%0D%0A%20%20vector%3Ct%
5Frec%3E%20arr%3B%0D%0A%20%20TAutoPtr%3Ct%5Finit%3E%20init%3B%0D%0A%20%20TAutoPt
r%3Ct%5Fcond%3E%20cond%3B%0D%0A%20%20TAutoPtr%3Ct%5Fbody%3E%20body%3B%0D%0A%20%2
0TAutoPtr%3Ct%5Fnext%3E%20next%3B%0D%0A%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%7B%0D
%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22for%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5F
auto%28sep0%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28label%29%3B%0D%0A%20%20%20
%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%2
9%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28init%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5
Fauto%28cond%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20
%20O%2B%3Dgo%5Fauto%28next%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%
0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%
0A%0D%0At%5Fbreak%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20TAutoPtr%3Ct%5Flabel%3E%20l
abel%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22break%22%29%3B%0D
%0A%20%20%20%20O%2B%3Dgo%5Fauto%28label%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0
At%5Fcontinue%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20TAutoPtr%3Ct%5Flabel%3E%20label
%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22continue%22%29%3B%0D%
0A%20%20%20%20O%2B%3Dgo%5Fauto%28label%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0A
t%5Fsep%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20t%5Fsep%20sep%3B%0D%0A%20%20%7B%0D%0A
%20%20%20%20go%5Fauto%28sep%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Ffunc%5F
node%3D%3Ei%5Fnode%7B%0D%0A%20%20t%5Fparam%7B%0D%0A%20%20%20%20string%20type%3B%
0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%
2B%3Dgo%5Fstr%3Ct%5Ftype%3E%28type%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fcons
t%28%22%20%22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%
29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20string%20type%3B%0D%0A%20%2
0t%5Fstring%20name%3B%0D%0A%20%20vector%3Ct%5Fparam%3E%20params%3B%0D%0A%20%20t%
5Fsep%20sep%3B%0D%0A%20%20t%5Fblock%20code%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%
2B%3Dgo%5Fstr%3Ct%5Ftype%3E%28type%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%20%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0D%0A%20%20%20%20M%
2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fvec%28params%2C%2
2%2C%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29asm%22%29%3B%0D%0A%20%2
0%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fauto%28code%29%
3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fstruct%5Fnode%3D%3Ei%5Fnode%7B%0D%0A%2
0%20t%5Ffield%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20string%20typ
e%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20
%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Ftyp
e%3E%28type%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%20%22%29%3B%0D%
0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20
%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D
%0A%20%20string%20name%3B%0D%0A%20%20t%5Fsep%20sep0%3B%0D%0A%20%20vector%3Ct%5Ff
ield%3E%20arr%3B%0D%0A%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20M%
2B%3Dgo%5Fconst%28%22struct%20%22%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fn
ame%3E%28name%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%2
0%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%
29%3B%0D%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20M%2B%3Dgo%
5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fsep%5Fnode%3D%3
Ei%5Fnode%7B%0D%0A%20%20string%20sep%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fstr
%3Ct%5Fsep%3E%28sep%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fasm%5Fscope%7B%
0D%0A%20%20vector%3CTAutoPtr%3Ci%5Fnode%3E%3E%20arr%3B%7Bgo%5Fauto%28arr%29%3B%7
D%0D%0A%7D%0D%0A%7D
*/
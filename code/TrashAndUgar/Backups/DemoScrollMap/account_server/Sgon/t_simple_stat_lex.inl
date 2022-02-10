struct t_simple_stat_lex{
public:
  //===>>===i_stat_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_var_stat)\
  ADD(t_sep_stat)\
  ADD(t_block_stat)\
  ADD(t_expr_stat)\
  ADD(t_func_stat)\
  ADD(t_ret_stat)\
  ADD(t_null_stat)\
  ADD(t_setadd_stat)\
  ADD(t_set_stat)\
  ADD(t_break_stat)\
  ADD(t_continue_stat)\
  ADD(t_for_stat)\
  ADD(t_if_stat)\
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
    virtual void Do(t_sep_stat*p)=0;
    virtual void Do(t_block_stat*p)=0;
    virtual void Do(t_expr_stat*p)=0;
    virtual void Do(t_func_stat*p)=0;
    virtual void Do(t_ret_stat*p)=0;
    virtual void Do(t_null_stat*p)=0;
    virtual void Do(t_setadd_stat*p)=0;
    virtual void Do(t_set_stat*p)=0;
    virtual void Do(t_break_stat*p)=0;
    virtual void Do(t_continue_stat*p)=0;
    virtual void Do(t_for_stat*p)=0;
    virtual void Do(t_if_stat*p)=0;
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
        F(t_func_stat);
        F(t_ret_stat);
        F(t_null_stat);
        F(t_setadd_stat);
        F(t_set_stat);
        F(t_break_stat);
        F(t_continue_stat);
        F(t_for_stat);
        F(t_if_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_stat_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };

  //===>>===i_expr_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_string_expr)\
  ADD(t_var_expr)\
  ADD(t_block_expr)\
  ADD(t_add_expr)\
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
    virtual void Do(t_string_expr*p)=0;
    virtual void Do(t_var_expr*p)=0;
    virtual void Do(t_block_expr*p)=0;
    virtual void Do(t_add_expr*p)=0;
    virtual void Do(t_call_expr*p)=0;
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
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_string_expr);
        F(t_var_expr);
        F(t_add_expr);
        F(t_block_expr);
        F(t_call_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_expr_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_string{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
    }/*
    string get_code(){
      string out;
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->get_code();
      }
      return out;
    }*//*
    string get_value(){
      string out;
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->get_value();
      }
      return out;
    }*/
  };
  class t_var_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,value,DEF,$,$)\
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
      D+=dev.go_auto(type);
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(name);
      if(!ok)return ok;
      D+=dev.go_const("=");
      if(!ok)return ok;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_sep_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
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
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_command_block{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_command_block)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
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
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_block_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_command_block,body,DEF,$,$)\
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
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(body);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_expr_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,body,DEF,$,$)\
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
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_string_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_string,body,DEF,$,$)\
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
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_var_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
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
      D+=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_block_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
  class t_call_param{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_param)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,body,DEF,$,$)\
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
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_params{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_params)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
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
      M+=dev.go_vec(arr,",");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,func,DEF,$,$)\
  ADDVAR(TAutoPtr<t_call_params>,params,DEF,$,$)\
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
      M+=dev.go_auto(func);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(params);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_without_add{
  public:
    typedef t_simple_stat_lex t_main;
  public:
    //===>>===i_expr_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_string_expr)\
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
      virtual void Do(t_string_expr*p)=0;
      virtual void Do(t_var_expr*p)=0;
      virtual void Do(t_block_expr*p)=0;
      virtual void Do(t_call_expr*p)=0;
    public:
      #define ADD(U)typedef t_without_add::U U;
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
      typedef t_without_add::i_expr i_expr;
    };
    template<class T_VISITOR>
    class t_expr_visitor:public i_expr_visitor{
    public:
      T_VISITOR&V;
      t_expr_visitor(T_VISITOR&V):V(V){}
    public:
      #define ADD(U)void Do(U*p){p->body.Use(V);}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
    };
    #undef DEF_PRO_BLANK

    #undef LIST
    //===<<===i_expr_visitor
  public:
    class i_expr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_without_add)
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
          F(t_string_expr);
          F(t_block_expr);
          F(t_call_expr);
          F(t_var_expr);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
      virtual void Use(i_expr_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
    };
    class t_string_expr:public i_expr{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_without_add)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_main::t_string_expr,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_string_expr
    #include "QapGenStruct.inl"
    //<<<<<+=====t_string_expr
    public:
      bool go(i_dev&dev){return body.go(dev);}
      void Use(i_expr_visitor&A){A.Do(this);}
    };
    class t_var_expr:public i_expr{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_without_add)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_main::t_var_expr,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_var_expr
    #include "QapGenStruct.inl"
    //<<<<<+=====t_var_expr
    public:
      bool go(i_dev&dev){return body.go(dev);}
      void Use(i_expr_visitor&A){A.Do(this);}
    };
    class t_block_expr:public i_expr{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_without_add)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_main::t_block_expr,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_block_expr
    #include "QapGenStruct.inl"
    //<<<<<+=====t_block_expr
    public:
      bool go(i_dev&dev){return body.go(dev);}
      void Use(i_expr_visitor&A){A.Do(this);}
    };
    class t_call_expr:public i_expr{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_without_add)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_main::t_call_expr,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_call_expr
    #include "QapGenStruct.inl"
    //<<<<<+=====t_call_expr
    public:
      bool go(i_dev&dev){return body.go(dev);}
      void Use(i_expr_visitor&A){A.Do(this);}
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_string_expr)F(t_var_expr)F(t_block_expr)F(t_call_expr)F(i_expr)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_without_add)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_without_add
  #include "QapGenStruct.inl"
  //<<<<<+=====t_without_add
  public:
  };
  class t_add_subexpr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_add_subexpr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_without_add::i_expr>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_add_subexpr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_add_subexpr
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
  class t_add_expr:public i_expr{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_add_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_add_subexpr>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_add_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_add_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_bin_oper(arr,"+");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_expr_visitor&A){A.Do(this);}
  };
  class t_param{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
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
      D+=dev.go_auto(type);
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_params{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_param>,arr,DEF,$,$)\
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
      M+=dev.go_vec(arr,",");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_func_body{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_body)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_func_body
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_body
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
  class t_func_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(TAutoPtr<t_params>,params,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_func_body,body,DEF,$,$)\
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
      M+=dev.go_auto(type);
      if(!ok)return ok;
      M+=dev.go_const(" ");
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(params);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_ret_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,body,DEF,$,$)\
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
      D+=dev.go_const("return ");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
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
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_setadd_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_setadd_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_setadd_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_setadd_stat
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(name);
      if(!ok)return ok;
      D+=dev.go_const("+=");
      if(!ok)return ok;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_set_stat:public i_stat{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_stat
  #include "QapGenStruct.inl"
  //<<<<<+=====t_set_stat
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(name);
      if(!ok)return ok;
      D+=dev.go_const("=");
      if(!ok)return ok;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_less_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_less_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,bef,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,aft,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_less_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_less_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(bef);
      if(!ok)return ok;
      D+=dev.go_const("<");
      if(!ok)return ok;
      D+=dev.go_auto(aft);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_addadd_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_addadd_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_addadd_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_addadd_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const("++");
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
    void Use(i_stat_visitor&A){A.Do(this);}
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
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_for_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_var_stat,init,DEF,$,$)\
  ADDVAR(t_less_expr,cond,DEF,$,$)\
  ADDVAR(t_addadd_expr,next,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_block_stat,body,DEF,$,$)\
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
      M+=dev.go_auto(init);
      if(!ok)return ok;
      M+=dev.go_auto(cond);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      M+=dev.go_auto(next);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
  };
  class t_neq_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_neq_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,bef,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,aft,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_neq_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_neq_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(bef);
      if(!ok)return ok;
      D+=dev.go_const("!=");
      if(!ok)return ok;
      D+=dev.go_auto(aft);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_eq_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_eq_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_expr>,bef,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,aft,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_eq_expr
  #include "QapGenStruct.inl"
  //<<<<<+=====t_eq_expr
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(bef);
      if(!ok)return ok;
      D+=dev.go_const("==");
      if(!ok)return ok;
      D+=dev.go_auto(aft);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_if_stat:public i_stat{
  public:
    class t_else{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else)OWNER(t_if_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_block_stat,body,DEF,$,$)\
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
  #define DEF_PRO_NESTED(F)F(t_else)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_if_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_eq_expr,cond,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_block_stat,bef,DEF,$,$)\
  ADDVAR(TAutoPtr<t_else>,aft,DEF,$,$)\
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
      M+=dev.go_const("if(");
      if(!ok)return ok;
      M+=dev.go_auto(cond);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(bef);
      if(!ok)return ok;
      O+=dev.go_auto(aft);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_stat_visitor&A){A.Do(this);}
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
F(t_add_expr);
F(t_call_param);
F(t_call_params);
F(t_call_expr);
F(t_param);
F(t_params);
F(t_func_body);
F(t_func_stat);
F(t_ret_stat);
F(t_null_stat);
F(t_setadd_stat);
F(t_set_stat);

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
  F(t_sep_stat)\
  F(t_command_block)\
  F(t_block_stat)\
  F(t_expr_stat)\
  F(t_string_expr)\
  F(t_var_expr)\
  F(t_block_expr)\
  F(t_add_expr)\
  F(t_call_param)\
  F(t_call_params)\
  F(t_call_expr)\
  F(t_param)\
  F(t_params)\
  F(t_func_body)\
  F(t_func_stat)\
  F(t_ret_stat)\
  F(t_null_stat)\
  F(t_setadd_stat)\
  F(t_set_stat)\
  F(i_stat)\
  F(i_expr)\
  F(t_add_subexpr)\
  F(t_without_add)\
  F(t_continue_stat)\
  F(t_break_stat)\
  F(t_for_stat)\
  F(t_less_expr)\
  F(t_addadd_expr)\
  F(t_if_stat)\
  F(t_eq_expr)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_simple_stat_lex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_simple_stat_lex
#include "QapGenStruct.inl"
//<<<<<+=====t_simple_stat_lex
public:
};
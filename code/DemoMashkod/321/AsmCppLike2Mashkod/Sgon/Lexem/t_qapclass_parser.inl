//time = 1304.80 ms.
class t_file_with_lex{
public:
  //===>>===i_elem_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_class)\
  ADD(t_other)\
  ADDEND()

  class i_elem;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_elem_visitor{
  public:
    typedef t_file_with_lex::i_elem i_elem;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_file_with_lex::U U;
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
    static TYPE*UberCast(i_elem*p){
      if(!p)return nullptr;Is<TYPE,i_elem_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_elem_visitor
  //class t_visitor:public t_file_with_lex::i_elem_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_class*p){}
  //  void Do(t_other*p){}
  //};
public:
  class i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_elem)OWNER(t_file_with_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_elem
  #include "QapGenStruct.inl"
  //<<<<<+=====i_elem
  public:
    typedef i_elem_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_class);
        F(t_other);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)OWNER(t_file_with_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sep
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const string g_static_dip_0=" \n";
      D+=dev.go_any(body,g_static_dip_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_class:public i_elem{
  public:
    //===>>===i_def_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_with_parent)\
    ADD(t_without_parent)\
    ADDEND()
  
    class i_def;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_def_visitor{
    public:
      typedef t_class::i_def i_def;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_class::U U;
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
      static TYPE*UberCast(i_def*p){
        if(!p)return nullptr;Is<TYPE,i_def_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_def_visitor
    //class t_visitor:public t_class::i_def_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_with_parent*p){}
    //  void Do(t_without_parent*p){}
    //};
  public:
    class i_def{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_def)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_def
    #include "QapGenStruct.inl"
    //<<<<<+=====i_def
    public:
      typedef i_def_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_with_parent);
          F(t_without_parent);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
  public:
    //===>>===i_lex_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_lex_base)\
    ADD(t_lex_impl)\
    ADDEND()
  
    class i_lex;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_lex_visitor{
    public:
      typedef t_class::i_lex i_lex;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_class::U U;
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
      static TYPE*UberCast(i_lex*p){
        if(!p)return nullptr;Is<TYPE,i_lex_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_lex_visitor
    //class t_visitor:public t_class::i_lex_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_lex_base*p){}
    //  void Do(t_lex_impl*p){}
    //};
  public:
    class i_lex{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_lex)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_lex
    #include "QapGenStruct.inl"
    //<<<<<+=====i_lex
    public:
      typedef i_lex_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_lex_base);
          F(t_lex_impl);
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
    ADD(t_sep_stat)\
    ADD(t_public_stat)\
    ADD(t_class_stat)\
    ADD(t_forward_decl_stat)\
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
      typedef t_class::i_stat i_stat;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_class::U U;
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
    //class t_visitor:public t_class::i_stat_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_sep_stat*p){}
    //  void Do(t_public_stat*p){}
    //  void Do(t_class_stat*p){}
    //  void Do(t_forward_decl_stat*p){}
    //};
  public:
    class i_stat{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)OWNER(t_class)
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
          F(t_sep_stat);
          F(t_public_stat);
          F(t_class_stat);
          F(t_forward_decl_stat);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_with_parent:public i_def{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_with_parent)PARENT(i_def)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,name,DEF,$,$)\
    ADDVAR(1,string,parent,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_with_parent
    #include "QapGenStruct.inl"
    //<<<<<+=====t_with_parent
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
        D+=dev.go_const(":public ");
        if(!ok)return ok;
        D+=dev.go_str<t_name>(parent);
        if(!ok)return ok;
        D+=dev.go_const("{\n");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_without_parent:public i_def{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_without_parent)PARENT(i_def)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,name,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_without_parent
    #include "QapGenStruct.inl"
    //<<<<<+=====t_without_parent
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
        D+=dev.go_const("{\n");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_head{
    public:
      class t_impl{
      public:
        //===>>===i_way_visitor
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
        ADD(t_noway)\
        ADD(t_okway)\
        ADDEND()
      
        class i_way;
      
        #define DEF_PRO_BLANK()
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        #undef DEF_PRO_BLANK
      
        #define DEF_PRO_BLANK()
        class i_way_visitor{
        public:
          typedef t_impl::i_way i_way;
        public:
          #define ADD(TYPE)virtual void Do(TYPE*p)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_impl::U U;
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
          static TYPE*UberCast(i_way*p){
            if(!p)return nullptr;Is<TYPE,i_way_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
        #undef DEF_PRO_BLANK
      
        #undef LIST
        //===<<===i_way_visitor
        //class t_visitor:public t_impl::i_way_visitor{
        //public:
        //  class t_dev{
        //  public:
        //  };
        //  t_dev&dev;
        //  t_visitor(t_dev&dev):dev(dev){}
        //public:
        //  void Do(t_noway*p){}
        //  void Do(t_okway*p){}
        //};
      public:
        class i_way{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_way)OWNER(t_impl)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_way
        #include "QapGenStruct.inl"
        //<<<<<+=====i_way
        public:
          typedef i_way_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            template<int>
            bool load()
            {
              F(t_noway);
              F(t_okway);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }
            #include "QapLexPolyEnd.inl"
          };
        };
        class t_noway:public i_way{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_noway)PARENT(i_way)OWNER(t_impl)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(0,TAutoPtr<i_def>,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_noway
        #include "QapGenStruct.inl"
        //<<<<<+=====t_noway
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
        class t_okway:public i_way{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_okway)PARENT(i_way)OWNER(t_impl)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_okway
        #include "QapGenStruct.inl"
        //<<<<<+=====t_okway
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
            D+=dev.go_const("#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\\\n");
            if(!ok)return ok;
            return ok;
          }
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_noway)\
        F(t_okway)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_head)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,body,DEF,$,$)\
      ADDVAR(1,t_okway,okway,DEF,$,$)\
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
          D+=dev.go_str_without<TAutoPtr<i_way>>(body);
          if(!ok)return ok;
          D+=dev.go_auto(okway);
          if(!ok)return ok;
          return ok;
        }
      public:
        //class t_static_visitor{
        //public:
        //  #define F(TYPE)typedef t_impl::TYPE TYPE;
        //  F(i_way);
        //  F(t_noway);
        //  F(t_okway);
        //  #undef F
        //public:
        //  void Do(t_noway&ref){}
        //  void Do(t_okway&ref){}
        //};
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_impl)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_head)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_head
    #include "QapGenStruct.inl"
    //<<<<<+=====t_head
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_str<t_impl>(body);
        if(!ok)return ok;
        return ok;
      }
    public:
      //class t_static_visitor{
      //public:
      //  #define F(TYPE)typedef t_head::TYPE TYPE;
      //  F(t_impl);
      //  #undef F
      //public:
      //  void Do(t_impl&ref){}
      //};
    };
    class t_vars{
    public:
      class t_item{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_vars)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,sep,DEF,$,$)\
      ADDVAR(1,string,num,DEF,$,$)\
      ADDVAR(2,string,type,DEF,$,$)\
      ADDVAR(3,string,name,DEF,$,$)\
      ADDVAR(4,string,mode,DEF,$,$)\
      ADDVAR(5,string,value,DEF,$,$)\
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
          O+=dev.go_str<t_sep>(sep);
          if(!ok)return ok;
          M+=dev.go_const("ADDVAR(");
          if(!ok)return ok;
          M+=dev.go_end(num,",");
          if(!ok)return ok;
          M+=dev.go_end(type,",");
          if(!ok)return ok;
          M+=dev.go_end(name,",");
          if(!ok)return ok;
          M+=dev.go_end(mode,",");
          if(!ok)return ok;
          M+=dev.go_end(value,",");
          if(!ok)return ok;
          M+=dev.go_const("$)\\\n");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_item)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vars)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,sep0,DEF,$,$)\
    ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
    ADDVAR(2,string,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_vars
    #include "QapGenStruct.inl"
    //<<<<<+=====t_vars
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_str<t_sep>(sep0);
        if(!ok)return ok;
        M+=dev.go_const("ADDBEG()\\\n");
        if(!ok)return ok;
        O+=dev.go_auto(arr);
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep1);
        if(!ok)return ok;
        M+=dev.go_const("ADDEND()\n");
        if(!ok)return ok;
        return ok;
      }
    public:
      //class t_static_visitor{
      //public:
      //  #define F(TYPE)typedef t_vars::TYPE TYPE;
      //  F(t_item);
      //  #undef F
      //public:
      //  void Do(t_item&ref){}
      //};
    };
    class t_include{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_include)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,sep0,DEF,$,$)\
    ADDVAR(1,string,name_bef,DEF,$,$)\
    ADDVAR(2,string,sep1,DEF,$,$)\
    ADDVAR(3,string,sep2,DEF,$,$)\
    ADDVAR(4,string,name_aft,DEF,$,$)\
    ADDVAR(5,string,sep3,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_include
    #include "QapGenStruct.inl"
    //<<<<<+=====t_include
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_str<t_sep>(sep0);
        if(!ok)return ok;
        M+=dev.go_const("//=====+>>>>>");
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name_bef);
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep1);
        if(!ok)return ok;
        M+=dev.go_const("#include \"QapGenStruct.inl\"");
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep2);
        if(!ok)return ok;
        M+=dev.go_const("//<<<<<+=====");
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name_aft);
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep3);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_lex_base:public i_lex{
    public:
      //===>>===i_way_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_okway)\
      ADD(t_noway)\
      ADDEND()
    
      class i_way;
    
      #define DEF_PRO_BLANK()
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      #undef DEF_PRO_BLANK
    
      #define DEF_PRO_BLANK()
      class i_way_visitor{
      public:
        typedef t_lex_base::i_way i_way;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_lex_base::U U;
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
        static TYPE*UberCast(i_way*p){
          if(!p)return nullptr;Is<TYPE,i_way_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
      #undef DEF_PRO_BLANK
    
      #undef LIST
      //===<<===i_way_visitor
      //class t_visitor:public t_lex_base::i_way_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_okway*p){}
      //  void Do(t_noway*p){}
      //};
    public:
      class i_way{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_way)OWNER(t_lex_base)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_way
      #include "QapGenStruct.inl"
      //<<<<<+=====i_way
      public:
        typedef i_way_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          template<int>
          bool load()
          {
            F(t_okway);
            F(t_noway);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
          #include "QapLexPolyEnd.inl"
        };
      };
      class t_okway:public i_way{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_okway)PARENT(i_way)OWNER(t_lex_base)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_okway
      #include "QapGenStruct.inl"
      //<<<<<+=====t_okway
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
          D+=dev.go_const("virtual bool go(i_dev&dev)");
          if(!ok)return ok;
          return ok;
        }
      };
      class t_noway:public i_way{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_noway)PARENT(i_way)OWNER(t_lex_base)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_noway
      #include "QapGenStruct.inl"
      //<<<<<+=====t_noway
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
          D+=dev.go_const("bool go(i_dev&dev){\n");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_okway)\
      F(t_noway)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lex_base)PARENT(i_lex)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,body,DEF,$,$)\
    ADDVAR(1,t_okway,okway,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_lex_base
    #include "QapGenStruct.inl"
    //<<<<<+=====t_lex_base
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
        M+=dev.go_str_without<TAutoPtr<i_way>>(body);
        if(!ok)return ok;
        M+=dev.go_auto(okway);
        if(!ok)return ok;
        return ok;
      }
    public:
      //class t_static_visitor{
      //public:
      //  #define F(TYPE)typedef t_lex_base::TYPE TYPE;
      //  F(i_way);
      //  F(t_okway);
      //  F(t_noway);
      //  #undef F
      //public:
      //  void Do(t_okway&ref){}
      //  void Do(t_noway&ref){}
      //};
    };
    class t_lex_impl:public i_lex{
    public:
      class t_line{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)OWNER(t_lex_impl)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,sep0,DEF,$,$)\
      ADDVAR(1,char,mode,DEF,$,$)\
      ADDVAR(2,string,line,DEF,$,$)\
      ADDVAR(3,string,sep1,DEF,$,$)\
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
          O+=dev.go_str<t_sep>(sep0);
          if(!ok)return ok;
          static const string g_static_dip_1="DOM";
          M+=dev.go_any_char(mode,g_static_dip_1);
          if(!ok)return ok;
          M+=dev.go_const("+=dev.");
          if(!ok)return ok;
          M+=dev.go_end(line,"\n");
          if(!ok)return ok;
          O+=dev.go_str<t_sep>(sep1);
          if(!ok)return ok;
          M+=dev.go_const("if(!ok)return ok;\n");
          if(!ok)return ok;
          return ok;
        }
      };
      class t_unused{
      public:
        //===>>===i_way_visitor
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
        ADD(t_noway)\
        ADD(t_okway)\
        ADDEND()
      
        class i_way;
      
        #define DEF_PRO_BLANK()
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        #undef DEF_PRO_BLANK
      
        #define DEF_PRO_BLANK()
        class i_way_visitor{
        public:
          typedef t_unused::i_way i_way;
        public:
          #define ADD(TYPE)virtual void Do(TYPE*p)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_unused::U U;
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
          static TYPE*UberCast(i_way*p){
            if(!p)return nullptr;Is<TYPE,i_way_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
        #undef DEF_PRO_BLANK
      
        #undef LIST
        //===<<===i_way_visitor
        //class t_visitor:public t_unused::i_way_visitor{
        //public:
        //  class t_dev{
        //  public:
        //  };
        //  t_dev&dev;
        //  t_visitor(t_dev&dev):dev(dev){}
        //public:
        //  void Do(t_noway*p){}
        //  void Do(t_okway*p){}
        //};
      public:
        class i_way{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_way)OWNER(t_unused)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_way
        #include "QapGenStruct.inl"
        //<<<<<+=====i_way
        public:
          typedef i_way_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            template<int>
            bool load()
            {
              F(t_noway);
              F(t_okway);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }
            #include "QapLexPolyEnd.inl"
          };
        };
        class t_noway:public i_way{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_noway)PARENT(i_way)OWNER(t_unused)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_noway
        #include "QapGenStruct.inl"
        //<<<<<+=====t_noway
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
            D+=dev.go_const("virtual bool go(i_dev&dev)");
            if(!ok)return ok;
            return ok;
          }
        };
        class t_okway:public i_way{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_okway)PARENT(i_way)OWNER(t_unused)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_okway
        #include "QapGenStruct.inl"
        //<<<<<+=====t_okway
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
            D+=dev.go_const("bool go(i_dev&dev){\n");
            if(!ok)return ok;
            return ok;
          }
        };
      public:
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_noway)\
        F(t_okway)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_unused)OWNER(t_lex_impl)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,body,DEF,$,$)\
      ADDVAR(1,t_okway,okway,DEF,$,$)\
      ADDVAR(2,string,sep0,DEF,$,$)\
      ADDVAR(3,string,sep1,DEF,$,$)\
      ADDVAR(4,string,sep2,DEF,$,$)\
      ADDVAR(5,string,sep3,DEF,$,$)\
      ADDVAR(6,string,sep4,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_unused
      #include "QapGenStruct.inl"
      //<<<<<+=====t_unused
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_str_without<TAutoPtr<i_way>>(body);
          if(!ok)return ok;
          M+=dev.go_auto(okway);
          if(!ok)return ok;
          O+=dev.go_str<t_sep>(sep0);
          if(!ok)return ok;
          M+=dev.go_const("t_fallback scope(dev,__FUNCTION__);");
          if(!ok)return ok;
          O+=dev.go_str<t_sep>(sep1);
          if(!ok)return ok;
          M+=dev.go_const("auto&ok=scope.ok;");
          if(!ok)return ok;
          O+=dev.go_str<t_sep>(sep2);
          if(!ok)return ok;
          M+=dev.go_const("auto&D=scope.mandatory;");
          if(!ok)return ok;
          O+=dev.go_str<t_sep>(sep3);
          if(!ok)return ok;
          M+=dev.go_const("auto&M=scope.mandatory;");
          if(!ok)return ok;
          O+=dev.go_str<t_sep>(sep4);
          if(!ok)return ok;
          M+=dev.go_const("auto&O=scope.optional;");
          if(!ok)return ok;
          return ok;
        }
      public:
        //class t_static_visitor{
        //public:
        //  #define F(TYPE)typedef t_unused::TYPE TYPE;
        //  F(i_way);
        //  F(t_noway);
        //  F(t_okway);
        //  #undef F
        //public:
        //  void Do(t_noway&ref){}
        //  void Do(t_okway&ref){}
        //};
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_line  )\
      F(t_unused)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lex_impl)PARENT(i_lex)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,unused,DEF,$,$)\
    ADDVAR(1,vector<t_line>,arr,DEF,$,$)\
    ADDVAR(2,string,sep0,DEF,$,$)\
    ADDVAR(3,string,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_lex_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_lex_impl
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
        M+=dev.go_str<t_unused>(unused);
        if(!ok)return ok;
        M+=dev.go_auto(arr);
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep0);
        if(!ok)return ok;
        M+=dev.go_const("return ok;\n");
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep1);
        if(!ok)return ok;
        M+=dev.go_const("}\n");
        if(!ok)return ok;
        return ok;
      }
    public:
      //class t_static_visitor{
      //public:
      //  #define F(TYPE)typedef t_lex_impl::TYPE TYPE;
      //  F(t_line);
      //  F(t_unused);
      //  #undef F
      //public:
      //  void Do(t_line&ref){}
      //  void Do(t_unused&ref){}
      //};
    };
    class t_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_body)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<i_lex>,body,DEF,$,$)\
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
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_end{
    public:
      //===>>===i_code_visitor
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_code)\
      ADD(t_scope)\
      ADDEND()
    
      class i_code;
    
      #define DEF_PRO_BLANK()
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      #undef DEF_PRO_BLANK
    
      #define DEF_PRO_BLANK()
      class i_code_visitor{
      public:
        typedef t_end::i_code i_code;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_end::U U;
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
        static TYPE*UberCast(i_code*p){
          if(!p)return nullptr;Is<TYPE,i_code_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
      #undef DEF_PRO_BLANK
    
      #undef LIST
      //===<<===i_code_visitor
      //class t_visitor:public t_end::i_code_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_code*p){}
      //  void Do(t_scope*p){}
      //};
    public:
      class i_code{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code)OWNER(t_end)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_code
      #include "QapGenStruct.inl"
      //<<<<<+=====i_code
      public:
        typedef i_code_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          template<int>
          bool load()
          {
            F(t_code);
            F(t_scope);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
          #include "QapLexPolyEnd.inl"
        };
      };
      class t_code:public i_code{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code)PARENT(i_code)OWNER(t_end)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_code
      #include "QapGenStruct.inl"
      //<<<<<+=====t_code
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
          static const string g_static_dip_0=dip_inv("{}");
          D+=dev.go_any(body,g_static_dip_0);
          if(!ok)return ok;
          return ok;
        }
      };
      class t_scope:public i_code{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)PARENT(i_code)OWNER(t_end)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,vector<t_end>,arr,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_scope
      #include "QapGenStruct.inl"
      //<<<<<+=====t_scope
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
          O+=dev.go_auto(arr);
          if(!ok)return ok;
          M+=dev.go_const("}");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_code )\
      F(t_scope)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_end)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<TAutoPtr<i_code>>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_end
    #include "QapGenStruct.inl"
    //<<<<<+=====t_end
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
      //  #define F(TYPE)typedef t_end::TYPE TYPE;
      //  F(i_code);
      //  F(t_code);
      //  F(t_scope);
      //  #undef F
      //public:
      //  void Do(t_code&ref){}
      //  void Do(t_scope&ref){}
      //};
    };
    class t_sep_stat:public i_stat{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,sep,DEF,$,$)\
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
        static const string g_static_dip_0=" \n";
        D+=dev.go_any(sep,g_static_dip_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_public_stat:public i_stat{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_public_stat)PARENT(i_stat)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_public_stat
    #include "QapGenStruct.inl"
    //<<<<<+=====t_public_stat
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
        D+=dev.go_const("public:");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_class_stat:public i_stat{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_stat)PARENT(i_stat)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<t_class>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_class_stat
    #include "QapGenStruct.inl"
    //<<<<<+=====t_class_stat
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
    class t_forward_decl_stat:public i_stat{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_forward_decl_stat)PARENT(i_stat)OWNER(t_class)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,name,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_forward_decl_stat
    #include "QapGenStruct.inl"
    //<<<<<+=====t_forward_decl_stat
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
        D+=dev.go_const("class ");
        if(!ok)return ok;
        D+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        D+=dev.go_const(";");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_with_parent      )\
    F(t_without_parent   )\
    F(t_head             )\
    F(t_vars             )\
    F(t_include          )\
    F(t_lex_base         )\
    F(t_lex_impl         )\
    F(t_body             )\
    F(t_end              )\
    F(t_sep_stat         )\
    F(t_public_stat      )\
    F(t_class_stat       )\
    F(t_forward_decl_stat)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class)PARENT(i_elem)OWNER(t_file_with_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,sep,DEF,$,$)\
  ADDVAR(1,TAutoPtr<i_def>,def,DEF,$,$)\
  ADDVAR(2,vector<TAutoPtr<i_stat>>,stats,DEF,$,$)\
  ADDVAR(3,t_head,head,DEF,$,$)\
  ADDVAR(4,t_vars,vars,DEF,$,$)\
  ADDVAR(5,t_include,incl,DEF,$,$)\
  ADDVAR(6,t_body,body,DEF,$,$)\
  ADDVAR(7,string,end,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class
  #include "QapGenStruct.inl"
  //<<<<<+=====t_class
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
      O+=dev.go_str<t_sep>(sep);
      if(!ok)return ok;
      M+=dev.go_const("class ");
      if(!ok)return ok;
      M+=dev.go_auto(def);
      if(!ok)return ok;
      O+=dev.go_auto(stats);
      if(!ok)return ok;
      M+=dev.go_auto(head);
      if(!ok)return ok;
      O+=dev.go_auto(vars);
      if(!ok)return ok;
      M+=dev.go_auto(incl);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_str<t_end>(end);
      if(!ok)return ok;
      M+=dev.go_const("};\n");
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_class::TYPE TYPE;
    //  F(i_def);
    //  F(i_lex);
    //  F(i_stat);
    //  F(t_with_parent);
    //  F(t_without_parent);
    //  F(t_head);
    //  F(t_vars);
    //  F(t_include);
    //  F(t_lex_base);
    //  F(t_lex_impl);
    //  F(t_body);
    //  F(t_end);
    //  F(t_sep_stat);
    //  F(t_public_stat);
    //  F(t_class_stat);
    //  F(t_forward_decl_stat);
    //  #undef F
    //public:
    //  void Do(t_with_parent&ref){}
    //  void Do(t_without_parent&ref){}
    //  void Do(t_head&ref){}
    //  void Do(t_vars&ref){}
    //  void Do(t_include&ref){}
    //  void Do(t_lex_base&ref){}
    //  void Do(t_lex_impl&ref){}
    //  void Do(t_body&ref){}
    //  void Do(t_end&ref){}
    //  void Do(t_sep_stat&ref){}
    //  void Do(t_public_stat&ref){}
    //  void Do(t_class_stat&ref){}
    //  void Do(t_forward_decl_stat&ref){}
    //};
  };
  class t_other:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_other)PARENT(i_elem)OWNER(t_file_with_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_other
  #include "QapGenStruct.inl"
  //<<<<<+=====t_other
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
      D+=dev.go_str_without<t_class>(body);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_sep  )\
  F(t_class)\
  F(t_other)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_file_with_lex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TAutoPtr<i_elem>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_file_with_lex
#include "QapGenStruct.inl"
//<<<<<+=====t_file_with_lex
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
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_file_with_lex::TYPE TYPE;
  //  F(i_elem);
  //  F(t_sep);
  //  F(t_class);
  //  F(t_other);
  //  #undef F
  //public:
  //  void Do(t_sep&ref){}
  //  void Do(t_class&ref){}
  //  void Do(t_other&ref){}
  //};
};

/*
//list of types:
F(t_file_with_lex)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Ffile%5Fwith%5Flex%7B%0A%20%20t%5Fsep%7Bstring%20body%3B%7Bgo%5Fany%28body%2C
%22%20%5Cn%22%29%3B%7D%7D%0A%20%20t%5Fclass%3D%3Ei%5Felem%7B%0A%20%20%20%20t%5Fw
ith%5Fparent%3D%3Ei%5Fdef%7B%0A%20%20%20%20%20%20string%20name%3B%0A%20%20%20%20
%20%20string%20parent%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5F
str%3Ct%5Fname%3E%28name%29%3B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%3Apubl
ic%20%22%29%3B%0A%20%20%20%20%20%20%20%20go%5Fstr%3Ct%5Fname%3E%28parent%29%3B%0
A%20%20%20%20%20%20%20%20go%5Fconst%28%22%7B%5Cn%22%29%3B%0A%20%20%20%20%20%20%7
D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fwithout%5Fparent%3D%3Ei%5Fdef%7B%0A%20%20%
20%20%20%20string%20name%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go
%5Fstr%3Ct%5Fname%3E%28name%29%3B%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%7B%
5Cn%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fhead%7B
%0A%20%20%20%20%20%20t%5Fimpl%7B%0A%20%20%20%20%20%20%20%20t%5Fnoway%3D%3Ei%5Fwa
y%7BTAutoPtr%3Ci%5Fdef%3E%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0A%20%20%20%2
0%20%20%20%20t%5Fokway%3D%3Ei%5Fway%7B%7Bgo%5Fconst%28%22%23define%20DEF%5FPRO%5
FVARIABLE%28ADDBEG%2CADDVAR%2CADDEND%29%5C%5C%5Cn%22%29%3B%7D%7D%0A%20%20%20%20%
20%20%20%20string%20body%3B%0A%20%20%20%20%20%20%20%20t%5Fokway%20okway%3B%0A%20
%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20go%5Fstr%5Fwithout%3CTA
utoPtr%3Ci%5Fway%3E%3E%28body%29%3B%0A%20%20%20%20%20%20%20%20%20%20go%5Fauto%28
okway%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%7D%0A%20%20%20%20
%20%20string%20body%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fst
r%3Ct%5Fimpl%3E%28body%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%
20%20t%5Fvars%7B%0A%20%20%20%20%20%20t%5Fitem%7B%0A%20%20%20%20%20%20%20%20strin
g%20sep%3B%0A%20%20%20%20%20%20%20%20string%20num%3B%0A%20%20%20%20%20%20%20%20s
tring%20type%3B%0A%20%20%20%20%20%20%20%20string%20name%3B%0A%20%20%20%20%20%20%
20%20string%20mode%3B%0A%20%20%20%20%20%20%20%20string%20value%3B%0A%20%20%20%20
%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28s
ep%29%3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22ADDVAR%28%22%29%
3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fend%28num%2C%22%2C%22%29%3B%0A%20
%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fend%28type%2C%22%2C%22%29%3B%0A%20%20%20%
20%20%20%20%20%20%20M%2B%3Dgo%5Fend%28name%2C%22%2C%22%29%3B%0A%20%20%20%20%20%2
0%20%20%20%20M%2B%3Dgo%5Fend%28mode%2C%22%2C%22%29%3B%0A%20%20%20%20%20%20%20%20
%20%20M%2B%3Dgo%5Fend%28value%2C%22%2C%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20
M%2B%3Dgo%5Fconst%28%22%24%29%5C%5C%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20%7D%0
A%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20string%20sep0%3B%0A%20%20%20%20%20%20
vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20%20%20%20%20string%20sep1%3B%0A%20%20%20%2
0%20%20%7B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep0%29%3B%0
A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22ADDBEG%28%29%5C%5C%5Cn%22%29%3B%
0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%20%20%20%2
0O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep1%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5
Fconst%28%22ADDEND%28%29%5Cn%22%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%
0A%20%20%20%20t%5Finclude%7B%0A%20%20%20%20%20%20string%20sep0%3B%0A%20%20%20%20
%20%20string%20name%5Fbef%3B%0A%20%20%20%20%20%20string%20sep1%3B%0A%20%20%20%20
%20%20string%20sep2%3B%0A%20%20%20%20%20%20string%20name%5Faft%3B%0A%20%20%20%20
%20%20string%20sep3%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20O%2B%3D
go%5Fstr%3Ct%5Fsep%3E%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%2
8%22%2F%2F%3D%3D%3D%3D%3D%2B%3E%3E%3E%3E%3E%22%29%3B%0A%20%20%20%20%20%20%20%20M
%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%5Fbef%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3
Dgo%5Fstr%3Ct%5Fsep%3E%28sep1%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%
28%22%23include%20%5C%22QapGenStruct%2Einl%5C%22%22%29%3B%0A%20%20%20%20%20%20%2
0%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep2%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dg
o%5Fconst%28%22%2F%2F%3C%3C%3C%3C%3C%2B%3D%3D%3D%3D%3D%22%29%3B%0A%20%20%20%20%2
0%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%5Faft%29%3B%0A%20%20%20%20%20%20%
20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep3%29%3B%0A%20%20%20%20%20%20%7D%0A%20%20%
20%20%7D%0A%20%20%20%20t%5Flex%5Fbase%3D%3Ei%5Flex%7B%0A%20%20%20%20%20%20t%5Fok
way%3D%3Ei%5Fway%7B%7Bgo%5Fconst%28%22virtual%20bool%20go%28i%5Fdev%26dev%29%22%
29%3B%7D%7D%0A%20%20%20%20%20%20t%5Fnoway%3D%3Ei%5Fway%7B%7Bgo%5Fconst%28%22bool
%20go%28i%5Fdev%26dev%29%7B%5Cn%22%29%3B%7D%7D%0A%20%20%20%20%20%20string%20body
%3B%0A%20%20%20%20%20%20t%5Fokway%20okway%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20
%20%20%20%20%20M%2B%3Dgo%5Fstr%5Fwithout%3CTAutoPtr%3Ci%5Fway%3E%3E%28body%29%3B
%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28okway%29%3B%0A%20%20%20%20%20%20%7
D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Flex%5Fimpl%3D%3Ei%5Flex%7B%0A%20%20%20%20%
20%20t%5Fline%7B%0A%20%20%20%20%20%20%20%20string%20sep0%3B%0A%20%20%20%20%20%20
%20%20char%20mode%3B%0A%20%20%20%20%20%20%20%20string%20line%3B%0A%20%20%20%20%2
0%20%20%20string%20sep1%3B%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20
%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep0%29%3B%0A%20%20%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fany%5Fchar%28mode%2C%22DOM%22%29%3B%0A%20%20%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fconst%28%22%2B%3Ddev%2E%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20
M%2B%3Dgo%5Fend%28line%2C%22%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20O%2B%3
Dgo%5Fstr%3Ct%5Fsep%3E%28sep1%29%3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5F
const%28%22if%28%21ok%29return%20ok%3B%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20%7
D%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20t%5Funused%7B%0A%20%20%20%20%20%20
%20%20t%5Fnoway%3D%3Ei%5Fway%7B%7Bgo%5Fconst%28%22virtual%20bool%20go%28i%5Fdev%
26dev%29%22%29%3B%7D%7D%0A%20%20%20%20%20%20%20%20t%5Fokway%3D%3Ei%5Fway%7B%7Bgo
%5Fconst%28%22bool%20go%28i%5Fdev%26dev%29%7B%5Cn%22%29%3B%7D%7D%0A%20%20%20%20%
20%20%20%20string%20body%3B%0A%20%20%20%20%20%20%20%20t%5Fokway%20okway%3B%0A%20
%20%20%20%20%20%20%20string%20sep0%3B%0A%20%20%20%20%20%20%20%20string%20sep1%3B
%0A%20%20%20%20%20%20%20%20string%20sep2%3B%0A%20%20%20%20%20%20%20%20string%20s
ep3%3B%0A%20%20%20%20%20%20%20%20string%20sep4%3B%0A%20%20%20%20%20%20%20%20%7B%
0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%5Fwithout%3CTAutoPtr%3Ci%5Fway%3
E%3E%28body%29%3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28okway%29%3B
%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep0%29%3B%0A%20
%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22t%5Ffallback%20scope%28dev%2C%
5F%5FFUNCTION%5F%5F%29%3B%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fs
tr%3Ct%5Fsep%3E%28sep1%29%3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%2
8%22auto%26ok%3Dscope%2Eok%3B%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo
%5Fstr%3Ct%5Fsep%3E%28sep2%29%3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fcon
st%28%22auto%26D%3Dscope%2Emandatory%3B%22%29%3B%0A%20%20%20%20%20%20%20%20%20%2
0O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep3%29%3B%0A%20%20%20%20%20%20%20%20%20%20M%2B%
3Dgo%5Fconst%28%22auto%26M%3Dscope%2Emandatory%3B%22%29%3B%0A%20%20%20%20%20%20%
20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep4%29%3B%0A%20%20%20%20%20%20%20%20%
20%20M%2B%3Dgo%5Fconst%28%22auto%26O%3Dscope%2Eoptional%3B%22%29%3B%0A%20%20%20%
20%20%20%20%20%7D%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20string%20unused%3B
%0A%20%20%20%20%20%20vector%3Ct%5Fline%3E%20arr%3B%0A%20%20%20%20%20%20string%20
sep0%3B%0A%20%20%20%20%20%20string%20sep1%3B%0A%20%20%20%20%20%20%7B%0A%20%20%20
%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Funused%3E%28unused%29%3B%0A%20%20%20%20%20%
20%20%20M%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3
Ct%5Fsep%3E%28sep0%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22return
%20ok%3B%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28s
ep1%29%3B%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%5Cn%22%29%3B%0A%2
0%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fbody%7BTAutoPtr%3Ci%5Fle
x%3E%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0A%20%20%20%20t%5Fend%7B%0A%20%20%
20%20%20%20t%5Fcode%3D%3Ei%5Fcode%7Bstring%20body%3B%7Bgo%5Fany%28body%2Cdip%5Fi
nv%28%22%7B%7D%22%29%29%3B%7D%7D%0A%20%20%20%20%20%20t%5Fscope%3D%3Ei%5Fcode%7B%
0A%20%20%20%20%20%20%20%20vector%3Ct%5Fend%3E%20arr%3B%0A%20%20%20%20%20%20%20%2
0%7B%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0A%20%2
0%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20%20%20%20%20
%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20
%20%20%20%20%7D%0A%20%20%20%20%20%20vector%3CTAutoPtr%3Ci%5Fcode%3E%3E%20body%3B
%0A%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20go%5Fauto%28body%29%3B%0A%20%
20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20t%5Fsep%5Fstat%3D%3Ei%5Fstat%7
Bstring%20sep%3B%7Bgo%5Fany%28sep%2C%22%20%5Cn%22%29%3B%7D%7D%0A%20%20%20%20t%5F
public%5Fstat%3D%3Ei%5Fstat%7B%7Bgo%5Fconst%28%22public%3A%22%29%3B%7D%7D%0A%20%
20%20%20t%5Fclass%5Fstat%3D%3Ei%5Fstat%7BTAutoPtr%3Ct%5Fclass%3E%20body%3B%7Bgo%
5Fauto%28body%29%3B%7D%7D%0A%20%20%20%20t%5Fforward%5Fdecl%5Fstat%3D%3Ei%5Fstat%
7Bstring%20name%3B%7Bgo%5Fconst%28%22class%20%22%29%3Bgo%5Fstr%3Ct%5Fname%3E%28n
ame%29%3Bgo%5Fconst%28%22%3B%22%29%3B%7D%7D%0A%20%20%20%20string%20sep%3B%0A%20%
20%20%20TAutoPtr%3Ci%5Fdef%3E%20def%3B%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fsta
t%3E%3E%20stats%3B%0A%20%20%20%20t%5Fhead%20head%3B%0A%20%20%20%20t%5Fvars%20var
s%3B%0A%20%20%20%20t%5Finclude%20incl%3B%0A%20%20%20%20t%5Fbody%20body%3B%0A%20%
20%20%20string%20end%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3C
t%5Fsep%3E%28sep%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22class%20%22%29
%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28def%29%3B%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28stats%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28head%29%3B%0A%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28vars%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto
%28incl%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0A%20%20%20%20%2
0%20O%2B%3Dgo%5Fstr%3Ct%5Fend%3E%28end%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fcon
st%28%22%7D%3B%5Cn%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fother%3D%3
Ei%5Felem%7B%0A%20%20%20%20string%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%
20go%5Fstr%5Fwithout%3Ct%5Fclass%3E%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0
A%20%20vector%3CTAutoPtr%3Ci%5Felem%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20go%
5Fauto%28arr%29%3B%0A%20%20%7D%0A%7D
*/
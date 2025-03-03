//time = 26.61 ms.

class t_asmcpplike2016{
public:
  //===>>===i_param_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_char_param)\
  ADD(t_str_param)\
  ADD(t_num_param)\
  ADD(t_ptr_reg_soft_param)\
  ADD(t_ptr_reg_raw_param)\
  ADD(t_reg_param)\
  ADD(t_ptr_raw_param)\
  ADD(t_mem_param)\
  ADD(t_raw_param)\
  ADD(t_ptr_reg_offset_param)\
  ADD(t_ptr_reg_param)\
  ADD(t_ptr_num_param)\
  ADD(t_name_param)\
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
    typedef t_asmcpplike2016::i_param i_param;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asmcpplike2016::U U;
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
public:
  class i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_param
  public:
    typedef i_param_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_char_param);
        F(t_str_param);
        F(t_num_param);
        F(t_ptr_reg_soft_param);
        F(t_ptr_reg_raw_param);
        F(t_reg_param);
        F(t_ptr_raw_param);
        F(t_mem_param);
        F(t_raw_param);
        F(t_ptr_reg_offset_param);
        F(t_ptr_reg_param);
        F(t_ptr_num_param);
        F(t_name_param);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_stat_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_cmd_stat)\
  ADD(t_block_stat)\
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
    typedef t_asmcpplike2016::i_stat i_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asmcpplike2016::U U;
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
public:
  class i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_stat
  public:
    typedef i_stat_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load()
      {
        F(t_cmd_stat);
        F(t_block_stat);
        F(t_sep_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_item_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_proc_item)\
  ADD(t_sep_item)\
  ADD(t_struct_item)\
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
    typedef t_asmcpplike2016::i_item i_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asmcpplike2016::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_asmcpplike2016)
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
        F(t_proc_item);
        F(t_sep_item);
        F(t_struct_item);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  class t_sign{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sign
  #include "QapGenStructNoTemplate.inl"
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
  class t_offset_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_offset_impl)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,sign,DEF,$,$)\
  ADDVAR(string,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_offset_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_offset_impl
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_sign>(sign);
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      D+=dev.go_any(num,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_num_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_impl)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,sign,DEF,$,$)\
  ADDVAR(string,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_impl
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_str<t_sign>(sign);
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      M+=dev.go_any(num,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_num{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_num_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_char_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_char,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_param
  public:
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
  class t_str_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_str_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_str_param
  public:
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
  class t_num_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_num,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_param
  #include "QapGenStructNoTemplate.inl"
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
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_arg{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arg)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_arg
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_arg
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("dest,src,a,b",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr_reg_soft_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_reg_soft_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,arg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_reg_soft_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_reg_soft_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("ptr(");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(arg);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr_reg_raw_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_reg_raw_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,reg,DEF,$,$)\
  ADDVAR(string,raw,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_reg_raw_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_reg_raw_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("ptr[reg[");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(reg);
      if(!ok)return ok;
      D+=dev.go_const("]+raw[");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(raw);
      if(!ok)return ok;
      D+=dev.go_const("]]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_reg_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_reg_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,arg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_reg_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_reg_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("reg[");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(arg);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr_raw_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_raw_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,arg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_raw_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_raw_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("reg[raw[");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(arg);
      if(!ok)return ok;
      D+=dev.go_const("]]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mem_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mem_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,arg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mem_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_mem_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("mem[");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(arg);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_raw_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,arg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("raw[");
      if(!ok)return ok;
      D+=dev.go_str<t_arg>(arg);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr_reg_offset_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_reg_offset_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,reg,DEF,$,$)\
  ADDVAR(string,offset,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_reg_offset_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_reg_offset_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("ptr[");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(reg);
      if(!ok)return ok;
      D+=dev.go_str<t_offset_impl>(offset);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr_reg_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_reg_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,reg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_reg_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_reg_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("ptr[");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(reg);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ptr_num_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_num_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_num_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_num_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("ptr[");
      if(!ok)return ok;
      D+=dev.go_str<t_num>(num);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_name_param:public i_param{
  public:
    class t_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ext)OWNER(t_name_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,field,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_ext
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("[\"");
        if(!ok)return ok;
        D+=dev.go_str<t_name>(field);
        if(!ok)return ok;
        D+=dev.go_const("\"]");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_ext)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(vector<t_ext>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_name_param
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
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
  class t_cmd_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_stat)PARENT(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,cmd,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_param>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cmd_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cmd_stat
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_str<t_name>(cmd);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(");");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_block_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_stat
  #include "QapGenStructNoTemplate.inl"
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
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_stat
  #include "QapGenStructNoTemplate.inl"
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
      D+=dev.go_str<t_sep>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_proc_item:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_proc_item)PARENT(i_item)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,name,DEF,$,$)\
  ADDVAR(string,sep,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_proc_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_proc_item
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{proc(");
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      M+=dev.go_const("){");
      if(!ok)return ok;
      O+=dev.go_str<t_sep>(sep);
      if(!ok)return ok;
      M+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("}}");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_field{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,type,DEF,$,$)\
  ADDVAR(t_str,name,DEF,$,$)\
  ADDVAR(string,sep,DEF,$,$)\
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
      M+=dev.go_const("FIELD(");
      if(!ok)return ok;
      M+=dev.go_auto(type);
      if(!ok)return ok;
      M+=dev.go_const(",");
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      M+=dev.go_const(");");
      if(!ok)return ok;
      O+=dev.go_str<t_sep>(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep_item:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_item)PARENT(i_item)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      D+=dev.go_str<t_sep>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_struct_item:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_item)PARENT(i_item)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,name,DEF,$,$)\
  ADDVAR(string,sep,DEF,$,$)\
  ADDVAR(vector<t_field>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_item
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{STRUCT(");
      if(!ok)return ok;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      M+=dev.go_const("){");
      if(!ok)return ok;
      O+=dev.go_str<t_sep>(sep);
      if(!ok)return ok;
      M+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("}}");
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_sign                )\
  F(t_offset_impl         )\
  F(t_num_impl            )\
  F(t_num                 )\
  F(t_char_param          )\
  F(t_str_param           )\
  F(t_num_param           )\
  F(t_arg                 )\
  F(t_ptr_reg_soft_param  )\
  F(t_ptr_reg_raw_param   )\
  F(t_reg_param           )\
  F(t_ptr_raw_param       )\
  F(t_mem_param           )\
  F(t_raw_param           )\
  F(t_ptr_reg_offset_param)\
  F(t_ptr_reg_param       )\
  F(t_ptr_num_param       )\
  F(t_name_param          )\
  F(t_cmd_stat            )\
  F(t_block_stat          )\
  F(t_sep_stat            )\
  F(t_proc_item           )\
  F(t_field               )\
  F(t_sep_item            )\
  F(t_struct_item         )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_asmcpplike2016)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_asmcpplike2016
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_asmcpplike2016
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("{");
    if(!ok)return ok;
    D+=dev.go_auto(arr);
    if(!ok)return ok;
    D+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
public:
};

/*
//list of types:
F(t_asmcpplike2016)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fasmcpplike2016%7B%0D%0A%20%20t%5Fsign%7Bchar%20value%3B%7Bgo%5Fany%5Fchar%28
value%2C%22%2B%2D%22%29%3B%7D%7D%0D%0A%20%20t%5Foffset%5Fimpl%7Bstring%20sign%3B
string%20num%3B%7Bgo%5Fstr%3Ct%5Fsign%3E%28sign%29%3Bgo%5Fany%28num%2Cgen%5Fdips
%28%2209%22%29%29%3B%7D%7D%0D%0A%20%20t%5Fnum%5Fimpl%7Bstring%20sign%3Bstring%20
num%3B%7BO%2B%3Dgo%5Fstr%3Ct%5Fsign%3E%28sign%29%3BM%2B%3Dgo%5Fany%28num%2Cgen%5
Fdips%28%2209%22%29%29%3B%7D%7D%0D%0A%20%20t%5Fnum%7Bstring%20value%3B%7Bgo%5Fst
r%3Ct%5Fnum%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20t%5Fchar%5Fparam%3D%3Ei%5Fp
aram%7Bt%5Fchar%20value%3B%7Bgo%5Fauto%28value%29%3B%7D%7D%0D%0A%20%20t%5Fstr%5F
param%3D%3Ei%5Fparam%7Bt%5Fstr%20value%3B%7Bgo%5Fauto%28value%29%3B%7D%7D%0D%0A%
20%20t%5Fnum%5Fparam%3D%3Ei%5Fparam%7Bt%5Fnum%20value%3B%7Bgo%5Fauto%28value%29%
3B%7D%7D%0D%0A%20%20t%5Farg%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28
value%2Csplit%28%22dest%2Csrc%2Ca%2Cb%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0A%20%20t
%5Fptr%5Freg%5Fsoft%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20string%20arg%3B%0
D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22ptr%28%22%29%3B%0D%0A
%20%20%20%20%20%20go%5Fstr%3Ct%5Farg%3E%28arg%29%3B%0D%0A%20%20%20%20%20%20go%5F
const%28%22%29%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fptr%5
Freg%5Fraw%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20string%20reg%3B%0D%0A%20%2
0%20%20string%20raw%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28
%22ptr%5Breg%5B%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fstr%3Ct%5Farg%3E%28reg%29%3
B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%5D%2Braw%5B%22%29%3B%0D%0A%20%20%20%20
%20%20go%5Fstr%3Ct%5Farg%3E%28raw%29%3B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%
5D%5D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Freg%5Fparam%3D
%3Ei%5Fparam%7B%0D%0A%20%20%20%20string%20arg%3B%0D%0A%20%20%20%20%7B%0D%0A%20%2
0%20%20%20%20go%5Fconst%28%22reg%5B%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fstr%3Ct
%5Farg%3E%28arg%29%3B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%5D%22%29%3B%0D%0A%
20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fptr%5Fraw%5Fparam%3D%3Ei%5Fparam%7B
%0D%0A%20%20%20%20string%20arg%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go
%5Fconst%28%22reg%5Braw%5B%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fstr%3Ct%5Farg%3E
%28arg%29%3B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%5D%5D%22%29%3B%0D%0A%20%20%
20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fmem%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20
%20%20string%20arg%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%
22mem%5B%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fstr%3Ct%5Farg%3E%28arg%29%3B%0D%0A
%20%20%20%20%20%20go%5Fconst%28%22%5D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%
7D%0D%0A%20%20t%5Fraw%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20string%20arg%3B
%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22raw%5B%22%29%3B%0D%
0A%20%20%20%20%20%20go%5Fstr%3Ct%5Farg%3E%28arg%29%3B%0D%0A%20%20%20%20%20%20go%
5Fconst%28%22%5D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fptr
%5Freg%5Foffset%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20string%20reg%3Bstring
%20offset%3B%7Bgo%5Fconst%28%22ptr%5B%22%29%3Bgo%5Fstr%3Ct%5Fname%3E%28reg%29%3B
go%5Fstr%3Ct%5Foffset%5Fimpl%3E%28offset%29%3Bgo%5Fconst%28%22%5D%22%29%3B%7D%0D
%0A%20%20%7D%0D%0A%20%20t%5Fptr%5Freg%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%2
0string%20reg%3B%7Bgo%5Fconst%28%22ptr%5B%22%29%3Bgo%5Fstr%3Ct%5Fname%3E%28reg%2
9%3Bgo%5Fconst%28%22%5D%22%29%3B%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fptr%5Fnum%5Fpa
ram%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20string%20num%3B%7Bgo%5Fconst%28%22ptr%5B%
22%29%3Bgo%5Fstr%3Ct%5Fnum%3E%28num%29%3Bgo%5Fconst%28%22%5D%22%29%3B%7D%0D%0A%2
0%20%7D%0D%0A%20%20t%5Fname%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20t%5Fext%7
Bstring%20field%3B%7Bgo%5Fconst%28%22%5B%5C%22%22%29%3Bgo%5Fstr%3Ct%5Fname%3E%28
field%29%3Bgo%5Fconst%28%22%5C%22%5D%22%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fname%20
name%3B%0D%0A%20%20%20%20vector%3Ct%5Fext%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A
%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%0D%0A%20%20t%5Fcmd
%5Fstat%3D%3Ei%5Fstat%7B%0D%0A%20%20%20%20string%20cmd%3B%0D%0A%20%20%20%20vecto
r%3CTAutoPtr%3Ci%5Fparam%3E%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%2
0%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28cmd%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5
Fconst%28%22%28%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%2
2%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%3B%22%29%3B%0D%0A%20%2
0%20%20%7D%0D%0A%20%20%7D%0D%0A%0D%0A%20%20t%5Fblock%5Fstat%3D%3Ei%5Fstat%7B%0D%
0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fstat%3E%3E%20arr%3B%0D%0A%20%20%20%20%7B%0
D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20%20%2
0O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%
22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%0D%0A%20%20t%5Fsep%5Fstat%3D%
3Ei%5Fstat%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fsep%3E%28value%29%3B%7D%7D%0D%0A
%0D%0A%20%20t%5Fproc%5Fitem%3D%3Ei%5Fitem%7B%0D%0A%20%20%20%20t%5Fstr%20name%3B%
0D%0A%20%20%20%20string%20sep%3B%0D%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fstat%3
E%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%7Bproc%28%22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%29%3B%0D%0A%
20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%7B%22%29%3B%0D%0A%20%20%20%20%20%20O
%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%
28arr%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%7D%22%29%3B%0D%0A%
20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%0D%0A%20%20t%5Ffield%7B%0D%0A%20%20%20%20t%5
Fstr%20type%3B%0D%0A%20%20%20%20t%5Fstr%20name%3B%0D%0A%20%20%20%20string%20sep%
3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22FIELD%28%2
2%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%2
0%20M%2B%3Dgo%5Fconst%28%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%
28name%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%3B%22%29%3B%0D%0A
%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep%29%3B%0D%0A%20%20%20%20%7D%
0D%0A%20%20%7D%0D%0A%0D%0A%20%20t%5Fsep%5Fitem%3D%3Ei%5Fitem%7Bstring%20value%3B
%7Bgo%5Fstr%3Ct%5Fsep%3E%28value%29%3B%7D%7D%0D%0A%0D%0A%20%20t%5Fstruct%5Fitem%
3D%3Ei%5Fitem%7B%0D%0A%20%20%20%20t%5Fstr%20name%3B%0D%0A%20%20%20%20string%20se
p%3B%0D%0A%20%20%20%20vector%3Ct%5Ffield%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%
20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7BSTRUCT%28%22%29%3B%0D%0A%20%20%20%20%
20%20M%2B%3Dgo%5Fauto%28name%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%29%7B%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep%29%3B
%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%20M%2B
%3Dgo%5Fconst%28%22%7D%7D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%
20vector%3CTAutoPtr%3Ci%5Fitem%3E%3E%20arr%3B%0D%0A%20%20%7Bgo%5Fconst%28%22%7B%
22%29%3Bgo%5Fauto%28arr%29%3Bgo%5Fconst%28%22%7D%22%29%3B%7D%0D%0A%7D
*/
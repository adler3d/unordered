//time = 610.00 ms.

class t_asm_machine{
public:
  //===>>===i_cmd_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_nop)\
  ADD(t_mrk)\
  ADD(t_ret)\
  ADD(t_call)\
  ADD(t_jmp)\
  ADD(t_jnz)\
  ADD(t_jz)\
  ADD(t_inc)\
  ADD(t_add)\
  ADD(t_sub)\
  ADD(t_mul)\
  ADD(t_div)\
  ADD(t_mod)\
  ADD(t_more)\
  ADD(t_less)\
  ADD(t_mov_reg_reg)\
  ADD(t_mov_const)\
  ADD(t_mov_inp_const)\
  ADD(t_mov_out_const)\
  ADD(t_mov_inp_reg)\
  ADD(t_mov_out_reg)\
  ADD(t_movc_reg_reg)\
  ADD(t_movc_const_const)\
  ADD(t_movc_reg_const)\
  ADD(t_movc_const_reg)\
  ADDEND()

  class i_cmd;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_cmd_visitor{
  public:
    typedef t_asm_machine::i_cmd i_cmd;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asm_machine::U U;
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
    static TYPE*UberCast(i_cmd*p){
      if(!p)return nullptr;Is<TYPE,i_cmd_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_cmd_visitor
  //class t_visitor:public t_asm_machine::i_cmd_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_nop*p){}
  //  void Do(t_mrk*p){}
  //  void Do(t_ret*p){}
  //  void Do(t_call*p){}
  //  void Do(t_jmp*p){}
  //  void Do(t_jnz*p){}
  //  void Do(t_jz*p){}
  //  void Do(t_inc*p){}
  //  void Do(t_add*p){}
  //  void Do(t_sub*p){}
  //  void Do(t_mul*p){}
  //  void Do(t_div*p){}
  //  void Do(t_mod*p){}
  //  void Do(t_more*p){}
  //  void Do(t_less*p){}
  //  void Do(t_mov_reg_reg*p){}
  //  void Do(t_mov_const*p){}
  //  void Do(t_mov_inp_const*p){}
  //  void Do(t_mov_out_const*p){}
  //  void Do(t_mov_inp_reg*p){}
  //  void Do(t_mov_out_reg*p){}
  //  void Do(t_movc_reg_reg*p){}
  //  void Do(t_movc_const_const*p){}
  //  void Do(t_movc_reg_const*p){}
  //  void Do(t_movc_const_reg*p){}
  //};
public:
  class i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====i_cmd
  public:
    typedef i_cmd_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_nop);
        F(t_mrk);
        F(t_ret);
        F(t_call);
        F(t_jmp);
        F(t_jnz);
        F(t_jz);
        F(t_inc);
        F(t_add);
        F(t_sub);
        F(t_mul);
        F(t_div);
        F(t_mod);
        F(t_more);
        F(t_less);
        F(t_mov_reg_reg);
        F(t_mov_const);
        F(t_mov_inp_const);
        F(t_mov_out_const);
        F(t_mov_inp_reg);
        F(t_mov_out_reg);
        F(t_movc_reg_reg);
        F(t_movc_const_const);
        F(t_movc_reg_const);
        F(t_movc_const_reg);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_int{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_int
  #include "QapGenStruct.inl"
  //<<<<<+=====t_int
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("09");
      D+=dev.go_any(value,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_label{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_label)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,id,DEF,$,$)\
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
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(id);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_reg{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_reg)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,char,id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_reg
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("azAZ");
      D+=dev.go_any_char(id,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_nop:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nop)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_nop
  #include "QapGenStruct.inl"
  //<<<<<+=====t_nop
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  nop");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_inp_const{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inp_const)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,offset,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_inp_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_inp_const
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(" inp[");
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("09");
      D+=dev.go_any(offset,g_static_var_1);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_out_const{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_out_const)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,offset,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_out_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_out_const
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(" out[");
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("09");
      D+=dev.go_any(offset,g_static_var_1);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_inp_reg{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inp_reg)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,char,id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_inp_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_inp_reg
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(" inp[");
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("azAZ");
      D+=dev.go_any_char(id,g_static_var_1);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_out_reg{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_out_reg)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,char,id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_out_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_out_reg
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(" out[");
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("azAZ");
      D+=dev.go_any_char(id,g_static_var_1);
      if(!ok)return ok;
      D+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mrk:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mrk)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mrk
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mrk
  public:
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
      D+=dev.go_const(":");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ret:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_ret
  #include "QapGenStruct.inl"
  //<<<<<+=====t_ret
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  ret");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_call:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_out_reg,out,DEF,$,$)\
  ADDVAR(1,t_label,to,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call
  #include "QapGenStruct.inl"
  //<<<<<+=====t_call
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  call");
      if(!ok)return ok;
      D+=dev.go_auto(to);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_jmp:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_jmp)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_label,to,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_jmp
  #include "QapGenStruct.inl"
  //<<<<<+=====t_jmp
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  jmp");
      if(!ok)return ok;
      D+=dev.go_auto(to);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_jnz:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_jnz)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,cond,DEF,$,$)\
  ADDVAR(1,t_label,to,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_jnz
  #include "QapGenStruct.inl"
  //<<<<<+=====t_jnz
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  jnz");
      if(!ok)return ok;
      D+=dev.go_auto(cond);
      if(!ok)return ok;
      D+=dev.go_auto(to);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_jz:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_jz)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,cond,DEF,$,$)\
  ADDVAR(1,t_label,to,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_jz
  #include "QapGenStruct.inl"
  //<<<<<+=====t_jz
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  jz");
      if(!ok)return ok;
      D+=dev.go_auto(cond);
      if(!ok)return ok;
      D+=dev.go_auto(to);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_inc:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inc)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,reg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_inc
  #include "QapGenStruct.inl"
  //<<<<<+=====t_inc
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  inc");
      if(!ok)return ok;
      D+=dev.go_auto(reg);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_add:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_add)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_add
  #include "QapGenStruct.inl"
  //<<<<<+=====t_add
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  add");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sub:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sub)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sub
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sub
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  sub");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mul:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mul)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mul
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mul
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mul");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_div:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_div)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_div
  #include "QapGenStruct.inl"
  //<<<<<+=====t_div
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  div");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mod:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mod)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mod
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mod
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mod");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_more:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_more)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_more
  #include "QapGenStruct.inl"
  //<<<<<+=====t_more
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  more");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_less:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_less)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,a,DEF,$,$)\
  ADDVAR(2,t_reg,b,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_less
  #include "QapGenStruct.inl"
  //<<<<<+=====t_less
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  less");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(a);
      if(!ok)return ok;
      D+=dev.go_auto(b);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mov_reg_reg:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov_reg_reg)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov_reg_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov_reg_reg
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mov");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mov_const:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov_const)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_int,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov_const
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mov");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mov_inp_const:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov_inp_const)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_inp_const,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov_inp_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov_inp_const
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mov");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mov_out_const:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov_out_const)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_out_const,out,DEF,$,$)\
  ADDVAR(1,t_reg,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov_out_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov_out_const
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mov");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mov_inp_reg:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov_inp_reg)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_inp_reg,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov_inp_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov_inp_reg
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mov");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_mov_out_reg:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov_out_reg)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_out_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov_out_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov_out_reg
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  mov");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_movc_reg_reg:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_movc_reg_reg)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,out_id,DEF,$,$)\
  ADDVAR(2,t_reg,inp,DEF,$,$)\
  ADDVAR(3,t_reg,inp_id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_movc_reg_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_movc_reg_reg
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  movc");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(out_id);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      D+=dev.go_auto(inp_id);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_movc_const_const:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_movc_const_const)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_int,out_id,DEF,$,$)\
  ADDVAR(2,t_reg,inp,DEF,$,$)\
  ADDVAR(3,t_int,inp_id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_movc_const_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_movc_const_const
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  movc");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(out_id);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      D+=dev.go_auto(inp_id);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_movc_reg_const:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_movc_reg_const)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_reg,out_id,DEF,$,$)\
  ADDVAR(2,t_reg,inp,DEF,$,$)\
  ADDVAR(3,t_int,inp_id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_movc_reg_const
  #include "QapGenStruct.inl"
  //<<<<<+=====t_movc_reg_const
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  movc");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(out_id);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      D+=dev.go_auto(inp_id);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_movc_const_reg:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_movc_const_reg)PARENT(i_cmd)OWNER(t_asm_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_reg,out,DEF,$,$)\
  ADDVAR(1,t_int,out_id,DEF,$,$)\
  ADDVAR(2,t_reg,inp,DEF,$,$)\
  ADDVAR(3,t_reg,inp_id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_movc_const_reg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_movc_const_reg
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("  movc");
      if(!ok)return ok;
      D+=dev.go_auto(out);
      if(!ok)return ok;
      D+=dev.go_auto(out_id);
      if(!ok)return ok;
      D+=dev.go_auto(inp);
      if(!ok)return ok;
      D+=dev.go_auto(inp_id);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_int             )\
  F(t_label           )\
  F(t_reg             )\
  F(t_nop             )\
  F(t_inp_const       )\
  F(t_out_const       )\
  F(t_inp_reg         )\
  F(t_out_reg         )\
  F(t_mrk             )\
  F(t_ret             )\
  F(t_call            )\
  F(t_jmp             )\
  F(t_jnz             )\
  F(t_jz              )\
  F(t_inc             )\
  F(t_add             )\
  F(t_sub             )\
  F(t_mul             )\
  F(t_div             )\
  F(t_mod             )\
  F(t_more            )\
  F(t_less            )\
  F(t_mov_reg_reg     )\
  F(t_mov_const       )\
  F(t_mov_inp_const   )\
  F(t_mov_out_const   )\
  F(t_mov_inp_reg     )\
  F(t_mov_out_reg     )\
  F(t_movc_reg_reg    )\
  F(t_movc_const_const)\
  F(t_movc_reg_const  )\
  F(t_movc_const_reg  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_asm_machine)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TAutoPtr<i_cmd>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_asm_machine
#include "QapGenStruct.inl"
//<<<<<+=====t_asm_machine
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_vec(arr,"\n");
    if(!ok)return ok;
    return ok;
  }
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_asm_machine::TYPE TYPE;
  //  F(i_cmd);
  //  F(t_int);
  //  F(t_label);
  //  F(t_reg);
  //  F(t_nop);
  //  F(t_inp_const);
  //  F(t_out_const);
  //  F(t_inp_reg);
  //  F(t_out_reg);
  //  F(t_mrk);
  //  F(t_ret);
  //  F(t_call);
  //  F(t_jmp);
  //  F(t_jnz);
  //  F(t_jz);
  //  F(t_inc);
  //  F(t_add);
  //  F(t_sub);
  //  F(t_mul);
  //  F(t_div);
  //  F(t_mod);
  //  F(t_more);
  //  F(t_less);
  //  F(t_mov_reg_reg);
  //  F(t_mov_const);
  //  F(t_mov_inp_const);
  //  F(t_mov_out_const);
  //  F(t_mov_inp_reg);
  //  F(t_mov_out_reg);
  //  F(t_movc_reg_reg);
  //  F(t_movc_const_const);
  //  F(t_movc_reg_const);
  //  F(t_movc_const_reg);
  //  #undef F
  //public:
  //  void Do(t_int&ref){}
  //  void Do(t_label&ref){}
  //  void Do(t_reg&ref){}
  //  void Do(t_nop&ref){}
  //  void Do(t_inp_const&ref){}
  //  void Do(t_out_const&ref){}
  //  void Do(t_inp_reg&ref){}
  //  void Do(t_out_reg&ref){}
  //  void Do(t_mrk&ref){}
  //  void Do(t_ret&ref){}
  //  void Do(t_call&ref){}
  //  void Do(t_jmp&ref){}
  //  void Do(t_jnz&ref){}
  //  void Do(t_jz&ref){}
  //  void Do(t_inc&ref){}
  //  void Do(t_add&ref){}
  //  void Do(t_sub&ref){}
  //  void Do(t_mul&ref){}
  //  void Do(t_div&ref){}
  //  void Do(t_mod&ref){}
  //  void Do(t_more&ref){}
  //  void Do(t_less&ref){}
  //  void Do(t_mov_reg_reg&ref){}
  //  void Do(t_mov_const&ref){}
  //  void Do(t_mov_inp_const&ref){}
  //  void Do(t_mov_out_const&ref){}
  //  void Do(t_mov_inp_reg&ref){}
  //  void Do(t_mov_out_reg&ref){}
  //  void Do(t_movc_reg_reg&ref){}
  //  void Do(t_movc_const_const&ref){}
  //  void Do(t_movc_reg_const&ref){}
  //  void Do(t_movc_const_reg&ref){}
  //};
};

/*
//list of types:
F(t_asm_machine)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fasm%5Fmachine%7B%0D%0A%20%20t%5Fint%7Bstring%20value%3B%7Bgo%5Fconst%28%22%2
0%22%29%3Bgo%5Fany%28value%2Cgen%5Fdips%28%2209%22%29%29%3B%7D%7D%0D%0A%20%20t%5
Flabel%7Bstring%20id%3B%7Bgo%5Fconst%28%22%20%22%29%3Bgo%5Fstr%3Ct%5Fname%3E%28i
d%29%3B%7D%7D%0D%0A%20%20t%5Freg%7Bchar%20id%3B%7Bgo%5Fconst%28%22%20%22%29%3Bgo
%5Fany%5Fchar%28id%2Cgen%5Fdips%28%22azAZ%22%29%29%3B%7D%7D%0D%0A%20%20t%5Fnop%3
D%3Ei%5Fcmd%7B%7Bgo%5Fconst%28%22%20%20nop%22%29%3B%7D%7D%0D%0A%20%20t%5Finp%5Fc
onst%7Bstring%20offset%3B%7Bgo%5Fconst%28%22%20inp%5B%22%29%3Bgo%5Fany%28offset%
2Cgen%5Fdips%28%2209%22%29%29%3Bgo%5Fconst%28%22%5D%22%29%3B%7D%7D%0D%0A%20%20t%
5Fout%5Fconst%7Bstring%20offset%3B%7Bgo%5Fconst%28%22%20out%5B%22%29%3Bgo%5Fany%
28offset%2Cgen%5Fdips%28%2209%22%29%29%3Bgo%5Fconst%28%22%5D%22%29%3B%7D%7D%0D%0
A%20%20t%5Finp%5Freg%7Bchar%20id%3B%7Bgo%5Fconst%28%22%20inp%5B%22%29%3Bgo%5Fany
%5Fchar%28id%2Cgen%5Fdips%28%22azAZ%22%29%29%3Bgo%5Fconst%28%22%5D%22%29%3B%7D%7
D%0D%0A%20%20t%5Fout%5Freg%7Bchar%20id%3B%7Bgo%5Fconst%28%22%20out%5B%22%29%3Bgo
%5Fany%5Fchar%28id%2Cgen%5Fdips%28%22azAZ%22%29%29%3Bgo%5Fconst%28%22%5D%22%29%3
B%7D%7D%0D%0A%20%20t%5Fmrk%3D%3Ei%5Fcmd%7Bstring%20name%3B%7Bgo%5Fstr%3Ct%5Fname
%3E%28name%29%3Bgo%5Fconst%28%22%3A%22%29%3B%7D%7D%0D%0A%20%20t%5Fret%3D%3Ei%5Fc
md%7B%7Bgo%5Fconst%28%22%20%20ret%22%29%3B%7D%7D%0D%0A%20%20t%5Fcall%3D%3Ei%5Fcm
d%7Bt%5Fout%5Freg%20out%3Bt%5Flabel%20to%3B%7Bgo%5Fconst%28%22%20%20call%22%29%3
Bgo%5Fauto%28to%29%3B%7D%7D%0D%0A%20%20t%5Fjmp%3D%3Ei%5Fcmd%7Bt%5Flabel%20to%3B%
7Bgo%5Fconst%28%22%20%20jmp%22%29%3Bgo%5Fauto%28to%29%3B%7D%7D%0D%0A%20%20t%5Fjn
z%3D%3Ei%5Fcmd%7Bt%5Freg%20cond%3Bt%5Flabel%20to%3B%7Bgo%5Fconst%28%22%20%20jnz%
22%29%3Bgo%5Fauto%28cond%29%3Bgo%5Fauto%28to%29%3B%7D%7D%0D%0A%20%20t%5Fjz%3D%3E
i%5Fcmd%7Bt%5Freg%20cond%3Bt%5Flabel%20to%3B%7Bgo%5Fconst%28%22%20%20jz%22%29%3B
go%5Fauto%28cond%29%3Bgo%5Fauto%28to%29%3B%7D%7D%0D%0A%20%20t%5Finc%3D%3Ei%5Fcmd
%7Bt%5Freg%20reg%3B%7Bgo%5Fconst%28%22%20%20inc%22%29%3Bgo%5Fauto%28reg%29%3B%7D
%7D%0D%0A%20%20t%5Fadd%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3Bt%5Freg%20a%3Bt%5Freg%20b%
3B%7Bgo%5Fconst%28%22%20%20add%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28a%29%3Bg
o%5Fauto%28b%29%3B%7D%7D%0D%0A%20%20t%5Fsub%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3Bt%5Fr
eg%20a%3Bt%5Freg%20b%3B%7Bgo%5Fconst%28%22%20%20sub%22%29%3Bgo%5Fauto%28out%29%3
Bgo%5Fauto%28a%29%3Bgo%5Fauto%28b%29%3B%7D%7D%0D%0A%20%20t%5Fmul%3D%3Ei%5Fcmd%7B
t%5Freg%20out%3Bt%5Freg%20a%3Bt%5Freg%20b%3B%7Bgo%5Fconst%28%22%20%20mul%22%29%3
Bgo%5Fauto%28out%29%3Bgo%5Fauto%28a%29%3Bgo%5Fauto%28b%29%3B%7D%7D%0D%0A%20%20t%
5Fdiv%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3Bt%5Freg%20a%3Bt%5Freg%20b%3B%7Bgo%5Fconst%2
8%22%20%20div%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28a%29%3Bgo%5Fauto%28b%29%3
B%7D%7D%0D%0A%20%20t%5Fmod%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3Bt%5Freg%20a%3Bt%5Freg%
20b%3B%7Bgo%5Fconst%28%22%20%20mod%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28a%29
%3Bgo%5Fauto%28b%29%3B%7D%7D%0D%0A%20%20t%5Fmore%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3B
t%5Freg%20a%3Bt%5Freg%20b%3B%7Bgo%5Fconst%28%22%20%20more%22%29%3Bgo%5Fauto%28ou
t%29%3Bgo%5Fauto%28a%29%3Bgo%5Fauto%28b%29%3B%7D%7D%0D%0A%20%20t%5Fless%3D%3Ei%5
Fcmd%7Bt%5Freg%20out%3Bt%5Freg%20a%3Bt%5Freg%20b%3B%7Bgo%5Fconst%28%22%20%20less
%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28a%29%3Bgo%5Fauto%28b%29%3B%7D%7D%0D%0A
%20%20t%5Fmov%5Freg%5Freg%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3Bt%5Freg%20inp%3B%7Bgo%5
Fconst%28%22%20%20mov%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28inp%29%3B%7D%7D%0
D%0A%20%20t%5Fmov%5Fconst%3D%3Ei%5Fcmd%7Bt%5Freg%20out%3Bt%5Fint%20value%3B%7Bgo
%5Fconst%28%22%20%20mov%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28value%29%3B%7D%
7D%0D%0A%20%20t%5Fmov%5Finp%5Fconst%3D%3Ei%5Fcmd%7Bt%5Freg%20%20%20%20%20%20%20o
ut%3Bt%5Finp%5Fconst%20inp%3B%7Bgo%5Fconst%28%22%20%20mov%22%29%3Bgo%5Fauto%28ou
t%29%3Bgo%5Fauto%28inp%29%3B%7D%7D%0D%0A%20%20t%5Fmov%5Fout%5Fconst%3D%3Ei%5Fcmd
%7Bt%5Fout%5Fconst%20out%3Bt%5Freg%20%20%20%20%20%20%20inp%3B%7Bgo%5Fconst%28%22
%20%20mov%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28inp%29%3B%7D%7D%0D%0A%20%20t%
5Fmov%5Finp%5Freg%3D%3Ei%5Fcmd%7Bt%5Freg%20%20%20%20%20out%3Bt%5Finp%5Freg%20inp
%3B%7Bgo%5Fconst%28%22%20%20mov%22%29%3Bgo%5Fauto%28out%29%3Bgo%5Fauto%28inp%29%
3B%7D%7D%0D%0A%20%20t%5Fmov%5Fout%5Freg%3D%3Ei%5Fcmd%7Bt%5Fout%5Freg%20out%3Bt%5
Freg%20%20%20%20%20inp%3B%7Bgo%5Fconst%28%22%20%20mov%22%29%3Bgo%5Fauto%28out%29
%3Bgo%5Fauto%28inp%29%3B%7D%7D%0D%0A%20%20t%5Fmovc%5Freg%5Freg%3D%3Ei%5Fcmd%7B%0
D%0A%20%20%20%20t%5Freg%20out%3Bt%5Freg%20out%5Fid%3B%0D%0A%20%20%20%20t%5Freg%2
0inp%3Bt%5Freg%20inp%5Fid%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fco
nst%28%22%20%20movc%22%29%3B%0D%0A%20%20%20%20%20%20go%5Fauto%28out%29%3Bgo%5Fau
to%28out%5Fid%29%3B%0D%0A%20%20%20%20%20%20go%5Fauto%28inp%29%3Bgo%5Fauto%28inp%
5Fid%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fmovc%5Fconst%5Fcon
st%3D%3Ei%5Fcmd%7B%0D%0A%20%20%20%20t%5Freg%20out%3Bt%5Fint%20out%5Fid%3B%0D%0A%
20%20%20%20t%5Freg%20inp%3Bt%5Fint%20inp%5Fid%3B%0D%0A%20%20%20%20%7B%0D%0A%20%2
0%20%20%20%20go%5Fconst%28%22%20%20movc%22%29%3B%0D%0A%20%20%20%20%20%20go%5Faut
o%28out%29%3Bgo%5Fauto%28out%5Fid%29%3B%0D%0A%20%20%20%20%20%20go%5Fauto%28inp%2
9%3Bgo%5Fauto%28inp%5Fid%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%
5Fmovc%5Freg%5Fconst%3D%3Ei%5Fcmd%7B%0D%0A%20%20%20%20t%5Freg%20out%3Bt%5Freg%20
out%5Fid%3B%0D%0A%20%20%20%20t%5Freg%20inp%3Bt%5Fint%20inp%5Fid%3B%0D%0A%20%20%2
0%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%20%20movc%22%29%3B%0D%0A%20%20%2
0%20%20%20go%5Fauto%28out%29%3Bgo%5Fauto%28out%5Fid%29%3B%0D%0A%20%20%20%20%20%2
0go%5Fauto%28inp%29%3Bgo%5Fauto%28inp%5Fid%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%2
0%7D%0D%0A%20%20t%5Fmovc%5Fconst%5Freg%3D%3Ei%5Fcmd%7B%0D%0A%20%20%20%20t%5Freg%
20out%3Bt%5Fint%20out%5Fid%3B%0D%0A%20%20%20%20t%5Freg%20inp%3Bt%5Freg%20inp%5Fi
d%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%20%20movc%22%2
9%3B%0D%0A%20%20%20%20%20%20go%5Fauto%28out%29%3Bgo%5Fauto%28out%5Fid%29%3B%0D%0
A%20%20%20%20%20%20go%5Fauto%28inp%29%3Bgo%5Fauto%28inp%5Fid%29%3B%0D%0A%20%20%2
0%20%7D%0D%0A%20%20%7D%0D%0A%20%20vector%3CTAutoPtr%3Ci%5Fcmd%3E%3E%20arr%3B%0D%
0A%20%20%7B%0D%0A%20%20%20%20go%5Fvec%28arr%2C%22%5Cn%22%29%3B%0D%0A%20%20%7D%0D
%0A%7D
*/
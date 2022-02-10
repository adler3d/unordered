//time = 8.97 ms.

class t_diff_sys{
public:
  //===>>===i_proxy_cmd_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_struct_cmd)\
  ADD(t_sys_cmd)\
  ADD(t_vec_cmd)\
  ADDEND()

  class i_proxy_cmd;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_proxy_cmd_visitor{
  public:
    typedef t_diff_sys::i_proxy_cmd i_proxy_cmd;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_diff_sys::U U;
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
    static TYPE*UberCast(i_proxy_cmd*p){
      if(!p)return nullptr;Is<TYPE,i_proxy_cmd_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_proxy_cmd_visitor
  //class t_visitor:public t_diff_sys::i_proxy_cmd_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_struct_cmd*p){}
  //  void Do(t_sys_cmd*p){}
  //  void Do(t_vec_cmd*p){}
  //};
public:
  class i_proxy_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_proxy_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_proxy_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====i_proxy_cmd
  public:
    typedef i_proxy_cmd_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
public:
  //===>>===i_struct_cmd_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_struct_def_cmd)\
  ADD(t_struct_new_cmd)\
  ADD(t_struct_patch_cmd)\
  ADD(t_struct_patch_ex_cmd)\
  ADDEND()

  class i_struct_cmd;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_struct_cmd_visitor{
  public:
    typedef t_diff_sys::i_struct_cmd i_struct_cmd;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_diff_sys::U U;
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
    static TYPE*UberCast(i_struct_cmd*p){
      if(!p)return nullptr;Is<TYPE,i_struct_cmd_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_struct_cmd_visitor
  //class t_visitor:public t_diff_sys::i_struct_cmd_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_struct_def_cmd*p){}
  //  void Do(t_struct_new_cmd*p){}
  //  void Do(t_struct_patch_cmd*p){}
  //  void Do(t_struct_patch_ex_cmd*p){}
  //};
public:
  class i_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_struct_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_struct_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====i_struct_cmd
  public:
    typedef i_struct_cmd_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
public:
  //===>>===i_sys_cmd_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_sys_def_cmd)\
  ADD(t_sys_new_cmd)\
  ADDEND()

  class i_sys_cmd;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_sys_cmd_visitor{
  public:
    typedef t_diff_sys::i_sys_cmd i_sys_cmd;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_diff_sys::U U;
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
    static TYPE*UberCast(i_sys_cmd*p){
      if(!p)return nullptr;Is<TYPE,i_sys_cmd_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_sys_cmd_visitor
  //class t_visitor:public t_diff_sys::i_sys_cmd_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_sys_def_cmd*p){}
  //  void Do(t_sys_new_cmd*p){}
  //};
public:
  class i_sys_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sys_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_sys_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====i_sys_cmd
  public:
    typedef i_sys_cmd_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
public:
  //===>>===i_vec_cmd_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_vec_def_cmd)\
  ADD(t_vec_new_cmd)\
  ADD(t_vec_patch_cmd)\
  ADD(t_vec_patch_resize_cmd)\
  ADDEND()

  class i_vec_cmd;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_vec_cmd_visitor{
  public:
    typedef t_diff_sys::i_vec_cmd i_vec_cmd;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_diff_sys::U U;
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
    static TYPE*UberCast(i_vec_cmd*p){
      if(!p)return nullptr;Is<TYPE,i_vec_cmd_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_vec_cmd_visitor
  //class t_visitor:public t_diff_sys::i_vec_cmd_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_vec_def_cmd*p){}
  //  void Do(t_vec_new_cmd*p){}
  //  void Do(t_vec_patch_cmd*p){}
  //  void Do(t_vec_patch_resize_cmd*p){}
  //};
public:
  class i_vec_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_vec_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_vec_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====i_vec_cmd
  public:
    typedef i_vec_cmd_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_struct_cmd:public i_proxy_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd)PARENT(i_proxy_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_struct_cmd>,cmd,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_sys_cmd:public i_proxy_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sys_cmd)PARENT(i_proxy_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_sys_cmd>,cmd,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sys_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sys_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_vec_cmd:public i_proxy_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vec_cmd)PARENT(i_proxy_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_vec_cmd>,cmd,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_vec_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_vec_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct_def_cmd:public i_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_def_cmd)PARENT(i_struct_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_struct_def_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_def_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct_new_cmd:public i_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_new_cmd)PARENT(i_struct_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_new_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_new_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct_patch_cmd:public i_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_patch_cmd)PARENT(i_struct_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_struct_cmd>,subtype,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_proxy_cmd>>,members,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_patch_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_patch_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct_patch_ex_cmd:public i_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_patch_ex_cmd)PARENT(i_struct_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,id,DEF,$,$)\
  ADDVAR(TAutoPtr<i_struct_cmd>,subtype,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_proxy_cmd>>,members,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_patch_ex_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_patch_ex_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_sys_def_cmd:public i_sys_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sys_def_cmd)PARENT(i_sys_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_sys_def_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sys_def_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_sys_new_cmd:public i_sys_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sys_new_cmd)PARENT(i_sys_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sys_new_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sys_new_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_vec_def_cmd:public i_vec_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vec_def_cmd)PARENT(i_vec_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_vec_def_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_vec_def_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_vec_new_cmd:public i_vec_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vec_new_cmd)PARENT(i_vec_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_vec_new_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_vec_new_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_vec_patch_cmd:public i_vec_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vec_patch_cmd)PARENT(i_vec_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_proxy_cmd>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_vec_patch_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_vec_patch_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_vec_patch_resize_cmd:public i_vec_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vec_patch_resize_cmd)PARENT(i_vec_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_proxy_cmd>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_vec_patch_resize_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_vec_patch_resize_cmd
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_struct_cmd          )\
  F(t_sys_cmd             )\
  F(t_vec_cmd             )\
  F(t_struct_def_cmd      )\
  F(t_struct_new_cmd      )\
  F(t_struct_patch_cmd    )\
  F(t_struct_patch_ex_cmd )\
  F(t_sys_def_cmd         )\
  F(t_sys_new_cmd         )\
  F(t_vec_def_cmd         )\
  F(t_vec_new_cmd         )\
  F(t_vec_patch_cmd       )\
  F(t_vec_patch_resize_cmd)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_sys)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_diff_sys
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_sys
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_diff_sys::TYPE TYPE;
  //  F(i_proxy_cmd);
  //  F(i_struct_cmd);
  //  F(i_sys_cmd);
  //  F(i_vec_cmd);
  //  F(t_struct_cmd);
  //  F(t_sys_cmd);
  //  F(t_vec_cmd);
  //  F(t_struct_def_cmd);
  //  F(t_struct_new_cmd);
  //  F(t_struct_patch_cmd);
  //  F(t_struct_patch_ex_cmd);
  //  F(t_sys_def_cmd);
  //  F(t_sys_new_cmd);
  //  F(t_vec_def_cmd);
  //  F(t_vec_new_cmd);
  //  F(t_vec_patch_cmd);
  //  F(t_vec_patch_resize_cmd);
  //  #undef F
  //public:
  //  void Do(t_struct_cmd&ref){}
  //  void Do(t_sys_cmd&ref){}
  //  void Do(t_vec_cmd&ref){}
  //  void Do(t_struct_def_cmd&ref){}
  //  void Do(t_struct_new_cmd&ref){}
  //  void Do(t_struct_patch_cmd&ref){}
  //  void Do(t_struct_patch_ex_cmd&ref){}
  //  void Do(t_sys_def_cmd&ref){}
  //  void Do(t_sys_new_cmd&ref){}
  //  void Do(t_vec_def_cmd&ref){}
  //  void Do(t_vec_new_cmd&ref){}
  //  void Do(t_vec_patch_cmd&ref){}
  //  void Do(t_vec_patch_resize_cmd&ref){}
  //};
};

/*
//list of types:
F(t_diff_sys)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fdiff%5Fsys%7B%0D%20%20t%5Fstruct%5Fcmd%3D%3Ei%5Fproxy%5Fcmd%7BTAutoPtr%3Ci%5
Fstruct%5Fcmd%3E%20cmd%3B%7D%0D%20%20t%5Fsys%5Fcmd%3D%3Ei%5Fproxy%5Fcmd%7BTAutoP
tr%3Ci%5Fsys%5Fcmd%3E%20cmd%3B%7D%0D%20%20t%5Fvec%5Fcmd%3D%3Ei%5Fproxy%5Fcmd%7BT
AutoPtr%3Ci%5Fvec%5Fcmd%3E%20cmd%3B%7D%0D%20%20t%5Fstruct%5Fdef%5Fcmd%3D%3Ei%5Fs
truct%5Fcmd%7B%7D%0D%20%20t%5Fstruct%5Fnew%5Fcmd%3D%3Ei%5Fstruct%5Fcmd%7Bstring%
20value%3B%7D%0D%20%20t%5Fstruct%5Fpatch%5Fcmd%3D%3Ei%5Fstruct%5Fcmd%7B%0D%20%20
%20%20TAutoPtr%3Ci%5Fstruct%5Fcmd%3E%20subtype%3B%0D%20%20%20%20vector%3CTAutoPt
r%3Ci%5Fproxy%5Fcmd%3E%3E%20members%3B%0D%20%20%7D%0D%20%20t%5Fstruct%5Fpatch%5F
ex%5Fcmd%3D%3Ei%5Fstruct%5Fcmd%7B%0D%20%20%20%20int%20id%3B%0D%20%20%20%20TAutoP
tr%3Ci%5Fstruct%5Fcmd%3E%20subtype%3B%0D%20%20%20%20vector%3CTAutoPtr%3Ci%5Fprox
y%5Fcmd%3E%3E%20members%3B%0D%20%20%7D%0D%20%20t%5Fsys%5Fdef%5Fcmd%3D%3Ei%5Fsys%
5Fcmd%7B%7D%0D%20%20t%5Fsys%5Fnew%5Fcmd%3D%3Ei%5Fsys%5Fcmd%7Bstring%20value%3B%7
D%0D%20%20t%5Fvec%5Fdef%5Fcmd%3D%3Ei%5Fvec%5Fcmd%7B%7D%0D%20%20t%5Fvec%5Fnew%5Fc
md%3D%3Ei%5Fvec%5Fcmd%7Bstring%20value%3B%7D%0D%20%20t%5Fvec%5Fpatch%5Fcmd%3D%3E
i%5Fvec%5Fcmd%7B%0D%20%20%20%20vector%3CTAutoPtr%3Ci%5Fproxy%5Fcmd%3E%3E%20arr%3
B%0D%20%20%7D%0D%20%20t%5Fvec%5Fpatch%5Fresize%5Fcmd%3D%3Ei%5Fvec%5Fcmd%7B%0D%20
%20%20%20vector%3CTAutoPtr%3Ci%5Fproxy%5Fcmd%3E%3E%20arr%3B%0D%20%20%7D%0D%7D
*/
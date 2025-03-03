#include "StdAfx.h"
#include <utility>/*
#include "Gateway.h"
#include "Gateway.cpp"*/

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_12_20.h"
#else
//=====>>>>>main_2013_12_20
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
#include "t_simple_stat_lex.inl"
//<<<<<=====main_2013_12_20
#endif //DEF_BUILD_MACRO//

//#include "t_stat_fast_clone.inl"
#include "i_object_dev.inl"

template<class TYPE>
static void qap_lex_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  static auto&counter=get_QapClone_counter();counter++;
  QapClock clock;
  clock.Start();
  string mem;
  save_obj(Env,source,mem);
  bool ok=load_obj(Env,dest,mem);
  QapAssert(ok);
  clock.Stop();
  QapClone_timer()+=clock.MS();
}

template<class TYPE>
static void unsafe_easy_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  t_clone_dev dev={Env};
  dev.dest.ptr.set(Env,dest);
  dev.source.ptr.set(Env,source);
  TCloneVisitor V(dev);
  dev.source.ptr.pType->Use(V);
}

template<class TYPE>
static void easy_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  static auto&counter=get_QapClone_counter();counter++;
  QapClock clock;
  clock.Start();
  string source_mem;
  save_obj(Env,source,source_mem);
  t_clone_dev dev={Env};
  dev.dest.ptr.set(Env,dest);
  dev.source.ptr.set(Env,source);
  TCloneVisitor V(dev);
  dev.source.ptr.pType->Use(V);
  string dest_mem;
  save_obj(Env,source,dest_mem);
  QapAssert(dest_mem==source_mem);
  clock.Stop();
  QapClone_timer()+=clock.MS();
}

static void fast_clone(IEnvRTTI&Env,t_simple_stat_lex::t_command_block&dest,t_simple_stat_lex::t_command_block&source){
  easy_clone(Env,dest,source);
  //qap_lex_clone(Env,dest,source);
  return;/*
  static auto&counter=get_QapClone_counter();counter++;
  QapClock clock;
  clock.Start();
  t_clone_sys::clone(Env,dest,source);
  clock.Stop();
  QapClone_timer()+=clock.MS();*/
}

class t_full_stat_dev;
class t_expr{
public:
  //===>>===i_sysval_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_string)\
  ADD(t_int)\
  ADD(t_char)\
  ADD(t_bool)\
  ADD(t_real)\
  ADDEND()

  class i_sysval;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_sysval_visitor{
  public:
    virtual void Do(t_string*p)=0;
    virtual void Do(t_int*p)=0;
    virtual void Do(t_char*p)=0;
    virtual void Do(t_bool*p)=0;
    virtual void Do(t_real*p)=0;
  public:
    #define ADD(U)typedef t_expr::U U;
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
    static TYPE*UberCast(i_sysval*p){
      if(!p)return nullptr;Is<TYPE,i_sysval_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_sysval_visitor
public:
  //===>>===i_value_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_sys)\
  ADD(t_struct)\
  ADD(t_array)\
  ADD(t_vector)\
  ADDEND()

  class i_value;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_value_visitor{
  public:
    virtual void Do(t_sys*p)=0;
    virtual void Do(t_struct*p)=0;
    virtual void Do(t_array*p)=0;
    virtual void Do(t_vector*p)=0;
  public:
    #define ADD(U)typedef t_expr::U U;
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
    static TYPE*UberCast(i_value*p){
      if(!p)return nullptr;Is<TYPE,i_value_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_value_visitor
public:
  class i_sysval{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sysval)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_sysval
  #include "QapGenStruct.inl"
  //<<<<<+=====i_sysval
  public:
    //F(t_string);
    //F(t_int);
    //F(t_char);
    //F(t_bool);
    //F(t_real);
  public:
    typedef i_sysval_visitor i_visitor;
  public:
    virtual string gettype()const{QapDebugMsg("no way.");return "";};
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_value)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_value
  #include "QapGenStruct.inl"
  //<<<<<+=====i_value
  public:
    //F(t_sys);
    //F(t_struct);
    //F(t_array);
    //F(t_vector);
  public:
    typedef i_value_visitor i_visitor;
    virtual string gettype()const{QapDebugMsg("no way.");return "";};
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_string:public i_sysval{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_sysval)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string
  #include "QapGenStruct.inl"
  //<<<<<+=====t_string
  public:
    string gettype()const{return "string";};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_int:public i_sysval{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int)PARENT(i_sysval)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,int,value,SET,0,$)\
  ADDEND()
  //=====+>>>>>t_int
  #include "QapGenStruct.inl"
  //<<<<<+=====t_int
  public:
    string gettype()const{return "int";};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_char:public i_sysval{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char)PARENT(i_sysval)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,char,value,SET,'\0',$)\
  ADDEND()
  //=====+>>>>>t_char
  #include "QapGenStruct.inl"
  //<<<<<+=====t_char
  public:
    string gettype()const{return "char";};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_bool:public i_sysval{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool)PARENT(i_sysval)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,bool,value,SET,false,$)\
  ADDEND()
  //=====+>>>>>t_bool
  #include "QapGenStruct.inl"
  //<<<<<+=====t_bool
  public:
    string gettype()const{return "bool";};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_real:public i_sysval{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real)PARENT(i_sysval)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,real,value,SET,0.0,$)\
  ADDEND()
  //=====+>>>>>t_real
  #include "QapGenStruct.inl"
  //<<<<<+=====t_real
  public:
    string gettype()const{return "real";};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_sys:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sys)PARENT(i_value)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TAutoPtr<i_sysval>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sys
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sys
  public:
    string gettype()const{return value->gettype();};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct)PARENT(i_value)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_value>>,arr,DEF,$,$)\
  ADDVAR(1,string,type,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct
  public:
    string gettype()const{return type;};
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_array:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_array)PARENT(i_value)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_value>>,arr,DEF,$,$)\
  ADDVAR(1,string,subtype,DEF,$,$)\
  ADDVAR(2,int,count,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_array
  #include "QapGenStruct.inl"
  //<<<<<+=====t_array
  public:
    string gettype()const{return "array{"+subtype+","+IToS(count)+"}";}
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_vector:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_vector)PARENT(i_value)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_value>>,arr,DEF,$,$)\
  ADDVAR(1,string,subtype,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_vector
  #include "QapGenStruct.inl"
  //<<<<<+=====t_vector
  public:
    string gettype()const{return "vector{"+subtype+"}";}
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct_info{
  public:
    class t_field{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_struct_info)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
    ADDVAR(2,TAutoPtr<t_expr::i_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_field
    #include "QapGenStruct.inl"
    //<<<<<+=====t_field
    public:
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_field)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_info)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,name,DEF,$,$)\
  ADDVAR(1,vector<t_field>,fields,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_info
  #include "QapGenStruct.inl"
  //<<<<<+=====t_struct_info
  public:
    int find(const string&field){
      auto&arr=fields;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.name==field)return i;
      }
      return -1;
    }
    t_field&unsafe_find(const string&field){
      int id=find(field);
      if(id>=0)return fields[id];
      string msg=field+" - field not found.\nfor type:\n"+name;
      QapDebugMsg(msg);
      return *(t_field*)nullptr;
    }
  };
#define DEF_PRO_NESTED(F)F(t_string)F(t_int)F(t_char)F(t_bool)F(t_real)F(t_sys)F(t_struct)F(t_struct_info)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_expr
#include "QapGenStruct.inl"
//<<<<<+=====t_expr
public:
  class t_sysval_copy_fast:public i_sysval_visitor{
  public:
    struct t_dev{
      IEnvRTTI&Env;
      TAutoPtr<i_sysval>&out;
    };
    t_dev&dev;
    t_sysval_copy_fast(t_dev&dev):dev(dev){}
  public:
    #define F(TYPE)void Do(TYPE*p){auto*ptr=dev.out.build<TYPE>(dev.Env);ptr->value=p->value;}
    F(t_string);
    F(t_int);
    F(t_char);
    F(t_bool);
    F(t_real);
    #undef F
  };
  static void sys_clone(IEnvRTTI&Env,TAutoPtr<i_sysval>&out,TAutoPtr<i_sysval>&inp){
    t_sysval_copy_fast::t_dev dev={Env,out};
    t_sysval_copy_fast V(dev);
    inp->Use(V);
  }
};

/*
//list of types:
F(t_expr)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fexpr%7B%0A%20%20t%5Fstring%3D%3Ei%5Fsysval%7Bstring%20value%3B%7D%0A%20%20t%
5Fint%3D%3Ei%5Fsysval%7Bint%20value%3D0%3B%7D%0A%20%20t%5Fchar%3D%3Ei%5Fsysval%7
Bchar%20value%3D%27%5C0%27%3B%7D%0A%20%20t%5Fbool%3D%3Ei%5Fsysval%7Bbool%20value
%3Dfalse%3B%7D%0A%20%20t%5Freal%3D%3Ei%5Fsysval%7Breal%20value%3D0%2E0%3B%7D
%0A%20%20%0A%20%20t%5Fsys%3D%3Ei%5Fvalue%7BTAutoPtr%3Ci%5Fsysval%3E%20value%3B%7
D%0A%20%20t%5Fstruct%3D%3Ei%5Fvalue%7B%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fval
ue%3E%3E%20arr%3B%0A%20%20%20%20string%20type%3B%0A%20%20%7D%0A%20%20t%5Fstruct%
5Finfo%7B%0A%20%20%20%20t%5Ffield%7B%0A%20%20%20%20%20%20string%20type%3B%0A%20%
20%20%20%20%20string%20name%3B%0A%20%20%20%20%20%20string%20value%3B%0A%20%20%20
%20%7D%0A%20%20%20%20string%20name%3B%0A%20%20%20%20vector%3Ct%5Ffield%3E%20fiel
ds%3B%0A%20%20%7D%0A%7D
*/

class t_stat_cmds{
public:
  typedef t_full_stat_dev t_dev;
public:
  class i_cmd;
  //===>>===i_cmd_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_block_id        )\
  ADD(t_func_body       )\
  ADD(t_oper_body       )\
  ADD(t_for_body        )\
  ADD(t_if_bef          )\
  ADD(t_if_aft          )\
  ADD(t_struct_body     )\
  ADDEND()

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_cmd_visitor{
  public:
    virtual void Do(t_block_id*p)=0;
    virtual void Do(t_func_body*p)=0;
    virtual void Do(t_oper_body*p)=0;
    virtual void Do(t_for_body*p)=0;
    virtual void Do(t_if_bef*p)=0;
    virtual void Do(t_if_aft*p)=0;
    virtual void Do(t_struct_body*p)=0;
    //virtual void Do(t_struct_arr_id*p)=0;
    //virtual void Do(t_struct_method_id*p)=0;
  public:
    #define ADD(U)typedef t_stat_cmds::U U;
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
public:
  class i_cmd{
  public:
    typedef i_cmd_visitor i_visitor;
  public:
    virtual void Use(i_visitor&){QapDebugMsg("no way.");}
  public:
    template<int>
    static string weak_toStr(i_cmd*p){
      t_cmd_to_str::t_dev dev;
      t_cmd_to_str V(dev);
      p->Use(V);
      return dev.out;
    }
    string toStr(){return weak_toStr<0>(this);}
  };
public:
  #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
  F(t_command_block);
  //F(t_block_stat);
  F(t_func_stat);
  F(t_oper_stat);
  F(t_for_stat);
  F(t_struct_stat);
  F(t_if_stat);
  F(t_struct);
  #undef F
public:
  class t_block_id:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_block_id SelfClass;
    typedef t_command_block t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    int id;
    t_block_id(t_dev&dev,t_ptr*ptr,int id):dev(dev),ptr(ptr),id(id){weak_init(this);}
   ~t_block_id(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_func_body:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_func_body SelfClass;
    typedef t_func_stat t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    t_func_body(t_dev&dev,t_ptr*ptr):dev(dev),ptr(ptr){weak_init(this);}
   ~t_func_body(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_oper_body:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_oper_body SelfClass;
    typedef t_oper_stat t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    t_oper_body(t_dev&dev,t_ptr*ptr):dev(dev),ptr(ptr){weak_init(this);}
   ~t_oper_body(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_for_body:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_for_body SelfClass;
    typedef t_for_stat t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    t_for_body(t_dev&dev,t_ptr*ptr):dev(dev),ptr(ptr){weak_init(this);}
   ~t_for_body(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_if_bef:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_if_bef SelfClass;
    typedef t_if_stat t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    t_if_bef(t_dev&dev,t_ptr*ptr):dev(dev),ptr(ptr){weak_init(this);}
   ~t_if_bef(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_if_aft:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_if_aft SelfClass;
    typedef t_if_stat t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    t_if_aft(t_dev&dev,t_ptr*ptr):dev(dev),ptr(ptr){weak_init(this);}
   ~t_if_aft(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
  class t_struct_body:public i_cmd{
  public:
    typedef i_cmd ParentClass;
    typedef t_struct_body SelfClass;
    typedef t_struct t_ptr;
    t_dev&dev;
    t_ptr*ptr;
    t_struct_body(t_dev&dev,t_ptr*ptr):dev(dev),ptr(ptr){weak_init(this);}
   ~t_struct_body(){weak_free(this);}
  public:
    void Use(i_visitor&A){A.Do(this);}
  public:
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };
public:
  class t_cmd_to_str:public i_cmd::i_visitor{
  public:
    struct t_dev{string out;};
    t_dev&dev;
    t_cmd_to_str(t_dev&dev):dev(dev){}
  public:
    void Do(t_block_id*p){dev.out="block_id["+IToS(p->id)+"]";}
    void Do(t_func_body*p){dev.out="func_body";}
    void Do(t_oper_body*p){dev.out="oper_body";}
    void Do(t_for_body*p){dev.out="for_body";}
    void Do(t_if_bef*p){dev.out="if_bef";}
    void Do(t_if_aft*p){dev.out="if_aft";}
    void Do(t_struct_body*p){dev.out="struct_body";}
  public:
  };
  template<class TYPE>
  static void weak_init(TYPE*ptr){
    ptr->dev.path.push(ptr);
  }
  template<class TYPE>
  static void weak_free(TYPE*ptr){
    ptr->dev.path.pop(ptr);
  }
};

class t_full_stat_dev;

class t_stat_dev{
public:
  class t_var;
  class t_expr_value{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_value)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TAutoPtr<t_expr::i_value>,value,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_expr_value
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_value
  public:
    //BEG
    #define F(TYPE)\
      void set_##TYPE(IEnvRTTI&Env,const TYPE&value){\
        auto*p=this->value.build<t_expr::t_sys>(Env);\
        auto*pValue=p->value.build<t_expr::t_##TYPE>(Env);\
        pValue->value=value;\
      }\
      bool get_##TYPE(TYPE&out)const{\
        if(!this->value)return false;\
        QapAssert(this->value);\
        if(this->value->gettype()!=#TYPE){\
          QapDebugMsg("wrong way for type - ["#TYPE", "+this->value->gettype()+"]");\
          return false;\
        }\
        auto*p=t_expr::t_sys::UberCast(this->value.get());\
        QapAssert(p);\
        auto*pValue=t_expr::t_##TYPE::UberCast(p->value.get());\
        QapAssert(pValue);\
        out=pValue->value;\
        return true;\
      }\
      TYPE&unsafe_get_ref_##TYPE(){\
        QapAssert(this->value);\
        if(this->value->gettype()!=#TYPE){\
          QapDebugMsg("wrong way for type - ["#TYPE", "+this->value->gettype()+"]");\
          return *(TYPE*)nullptr;\
        }\
        auto*p=t_expr::t_sys::UberCast(this->value.get());\
        QapAssert(p);\
        auto*pValue=t_expr::t_##TYPE::UberCast(p->value.get());\
        QapAssert(pValue);\
        return pValue->value;\
      }
    //=>
      F(string);
      F(int);
      F(char);
      F(bool);
      F(real);
    //<=
    #undef F
    //END
    void set(t_full_stat_dev&dev,t_var&var){
      set(dev,var.value.value);
    }
    bool try_set_internal(IEnvRTTI&Env,t_expr_value&inp)
    {
      if(!inp.value){
        QapDebugMsg("way not tested.");
        value=nullptr;
        return true;
      }
      string type=inp.gettype();
      //BEG
      #define F(TYPE)\
        if(type==#TYPE){\
          TYPE value;\
          bool ok=inp.get_##TYPE(value);\
          QapAssert(ok);\
          set_##TYPE(Env,value);\
          return true;\
        }
      //=>
        F(string);
        F(int);
        F(char);
        F(bool);
        F(real);
      //<=
      #undef F
      //END
      //QapDebugMsg("no impl");
      return false;
    }
    bool set(t_full_stat_dev&dev,t_expr_value&inp){
      return weak_set<0>(dev,inp.value);
    }
    bool set(t_full_stat_dev&dev,TAutoPtr<t_expr::i_value>&inp_value){
      return weak_set<0>(dev,inp_value);
    }
    template<int>
    bool weak_set(t_full_stat_dev&dev,TAutoPtr<t_expr::i_value>&inp_value)
    {
      if(&this->value==&inp_value)return true;
      this->value=nullptr;
      //fast
      for(;;){
        auto*psys=t_expr::t_sys::UberCast(inp_value.get());
        if(!psys)break;
        auto*pout=value.build<t_expr::t_sys>(dev.Env);
        t_expr::sys_clone(dev.Env,pout->value,psys->value);
        return true;
      }
      unsafe_easy_clone(dev.Env,this->value,inp_value);
      return true;
    }
    bool isString()const{return "string"==gettype();}
    bool isInt()const{return "int"==gettype();}
    bool isChar()const{return "char"==gettype();}
    bool isBool()const{return "bool"==gettype();}
    bool isReal()const{return "real"==gettype();}
    string gettype()const{if(!value)return "void";return value->gettype();}
  public:
    static void clone(t_full_stat_dev&dev,TAutoPtr<t_expr::i_value>&dest,TAutoPtr<t_expr::i_value>&source){
      t_expr_value tmp;
      tmp.set(dev,source);
      dest=std::move(tmp.value);
    }
  };
public:
  class t_var{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,name,DEF,$,$)\
    ADDVAR(1,t_expr_value,value,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_var
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var
  public:
  };
  class t_func_param{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_param)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_func_param
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_param
  public:
  };
  class t_func_info{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_info)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,isOper,DEF,$,$)\
    ADDVAR(1,int,counter,DEF,$,$)\
    ADDVAR(2,real,exec_time,DEF,$,$)\
    ADDVAR(3,real,full_time,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_func_info
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_info
  public:
  };
  class t_func_head{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_head)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,name,DEF,$,$)\
    ADDVAR(1,string,type,DEF,$,$)\
    ADDVAR(2,vector<t_func_param>,params,DEF,$,$)\
    ADDVAR(3,t_func_info,info,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_func_head
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_head
  public:
    vector<string> get_param_types()const
    {
      auto&arr=params;
      vector<string> out;
      for(int i=0;i<arr.size();i++){
        out.push_back(arr[i].type);
      }
      return out;
    };
    string get_code()const
    {
      return info.isOper?get_oper_code_impl():get_func_code_impl();
    }
    string get_func_code_impl()const
    {
      return type+" "+name+"("+join(get_param_types(),",")+")";
    }
    string get_oper_code_impl()const
    {
      return type+" operator"+name+"("+join(get_param_types(),",")+")";
    }
  };
  class i_func_impl;
  struct t_sys_func_tools{
  public:
    typedef t_func_head t_head;
    //typedef TAutoPtr<i_sys_impl> t_body;
  public:
    //static bool try_copy()
    static void do_exec(t_full_stat_dev&dev,i_sys_impl*pBody){
      pBody->exec();
    }
    template<class t_full_stat_dev>
    static void do_exec(t_full_stat_dev&dev,i_sysfunc_with_rtti*pBody){
      pBody->exec(dev.Env);
    }
    template<class TYPE>
    static void weak_exec(t_full_stat_dev&dev,vector<t_expr_value>&values,t_head&head,TAutoPtr<TYPE>&body)
    {
      typedef t_full_stat_dev::t_rettype_scope t_rettype_scope;
      QapClock clock;
      clock.Start();
      QapAssert(body);
      auto*pBody=body.get();
      auto*p=TTypeStruct::UberCast(body.Product.pType.get());
      QapAssert(p);
      auto&arr=p->Members;
      QapAssert(arr.size()>=1);
      QapAssert(arr.size()==values.size()+1);
      vector<string> types;
      string rettype;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        string fieldtype=ex.Type->GetFullName();
        types.push_back(fieldtype);
        if(!i){rettype=fieldtype;continue;}
        int id=i-1;
        auto&v=values[id];
        string valuetype=v.gettype();
        QapAssert(valuetype==fieldtype);
        for(;;)
        {
          //BEG
          #define F(TYPE)\
          if(fieldtype==#TYPE){\
            auto&value=v.unsafe_get_ref_##TYPE();\
            auto&field=*(TYPE*)ex.getValue(pBody);\
            field=value;\
            break;\
          }
          //=>
          F(string);
          F(int);
          F(char);
          F(bool);
          F(real);
          //<=
          #undef F
          //END
          QapDebugMsg("no way for "+fieldtype);
          break;
        }
      }
      {
        auto*pBody=body.get();
        real cur=clock.MS();
        do_exec(dev,pBody);
        //body->exec();
        head.info.exec_time+=clock.MS()-cur;
        head.info.counter++;
      }
      t_expr_value out;
      {
        t_rettype_scope scope(dev,rettype,out);
        for(;;)
        {
          //BEG
          #define F(TYPE)\
            if(rettype==#TYPE)\
            {\
              auto&field=*(TYPE*)arr[0].getValue(pBody);\
              out.set_##TYPE(dev.Env,field);\
              dev.ret(out);\
              break;\
            }                                           
          //=>
          F(string);
          F(int);
          F(char);
          F(bool);
          F(real);
          //<=
          #undef F
          //END
          dev.drop_error("[2014.03.12 18:52]: no way for "+rettype);
          return;
        }
      }
      if(dev.isErr())return;
      dev.expr_buff=std::move(out);
      head.info.full_time+=clock.MS();
    }
  public:
    template<class IEnvRTTI,class TYPE>
    static void weak_init(IEnvRTTI&Env,const string&name,t_head&head,TAutoPtr<TYPE>&body)
    {
      head.name=name;
      QapAssert(body);
      auto*p=TTypeStruct::UberCast(body.Product.pType.get());
      QapAssert(p);
      auto&arr=p->Members;
      QapAssert(arr.size()>=1);
      auto&params=head.params;
      params.resize(arr.size()-1);
      vector<string> types;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        string fieldtype=ex.Type->GetFullName();
        types.push_back(fieldtype);
        if(!i){head.type=fieldtype;continue;}
        int id=i-1;
        params[id].name=ex.Name;
        params[id].type=fieldtype;
      }
    }
  };
  class t_func{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_func_head,head,DEF,$,$)\
    ADDVAR(1,TAutoPtr<i_sys_impl>,body,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_func
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func
  public:
    void exec(t_full_stat_dev&dev,vector<t_expr_value>&values){
      t_sys_func_tools::weak_exec(dev,values,head,body);
    }
  public:
    const vector<t_func_param>&get_params()const{return head.params;}
    const string&get_type()const{return head.type;}
    const t_func_head&get_head()const{return head;}
  };
  class t_oper{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_func_head,head,DEF,$,$)\
    ADDVAR(1,TAutoPtr<i_sys_impl>,body,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_oper
  public:
    void exec(t_full_stat_dev&dev,vector<t_expr_value>&values){
      t_sys_func_tools::weak_exec(dev,values,head,body);
    }
  public:
    const vector<t_func_param>&get_params()const{return head.params;}
    const string&get_type()const{return head.type;}
    const t_func_head&get_head()const{return head;}
  };
  class t_rtti_func{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rtti_func)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,t_func_head,head,DEF,$,$)\
    ADDVAR(1,TAutoPtr<i_sysfunc_with_rtti>,body,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_rtti_func
  #include "QapGenStruct.inl"
  //<<<<<+=====t_rtti_func
  public:
    void exec(t_full_stat_dev&dev,vector<t_expr_value>&values){
      t_sys_func_tools::weak_exec(dev,values,head,body);
    }
  public:
    const vector<t_func_param>&get_params()const{return head.params;}
    const string&get_type()const{return head.type;}
    const t_func_head&get_head()const{return head;}
  };
  class t_state{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_state)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,value,SET,'N',$)\
    ADDEND()
  //=====+>>>>>t_state
  #include "QapGenStruct.inl"
  //<<<<<+=====t_state
  public:
  };
  class t_info{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_info)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,find_time,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_info
  #include "QapGenStruct.inl"
  //<<<<<+=====t_info
  public:
  };
  class t_context{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_context)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<t_var>,vars,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_context
  #include "QapGenStruct.inl"
  //<<<<<+=====t_context
  public:
    int find(const string&name){
      for(int i=0;i<vars.size();i++){
        auto&ex=vars[i];
        if(ex.name==name)return i;
      }
      return -1;
    }
    t_var&unsafe_find_ref(const string&name){
      for(int i=0;i<vars.size();i++){
        auto&ex=vars[i];
        if(ex.name==name)return ex;
      }
      QapAssert(false);
      return *(t_var*)nullptr;
    }
    t_var*find_ptr(const string&name){
      for(int i=0;i<vars.size();i++){
        auto&ex=vars[i];
        if(ex.name==name)return &ex;
      }
      return nullptr;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  F(t_var)F(t_context)F(t_func_param)F(t_func_info)F(t_func_head)\
  F(t_func)F(t_oper)F(t_rtti_func)\
  F(t_expr_value)F(t_state)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_stat_dev)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<t_context>,stack,DEF,$,$)\
ADDVAR(1,vector<t_func>,funcs,DEF,$,$)\
ADDVAR(2,vector<t_oper>,opers,DEF,$,$)\
ADDVAR(3,vector<t_rtti_func>,rttifuncs,DEF,$,$)\
ADDVAR(4,t_expr_value,expr_buff,DEF,$,$)\
ADDVAR(5,t_state,state,DEF,$,$)\
ADDVAR(6,vector<t_expr::t_struct_info>,typelist,DEF,$,$)\
ADDVAR(7,t_info,info,DEF,$,$)\
ADDEND()
//=====+>>>>>t_stat_dev
#include "QapGenStruct.inl"
//<<<<<+=====t_stat_dev
public:
  int find_struct_id_by_name(const string&type)const
  {
    auto&arr=typelist;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.name==type)return i;
    }
    return -1;
  }
  t_expr::t_struct_info&unsafe_find_struct(const string&type){
    int id=find_struct_id_by_name(type);
    if(id<0){
      QapDebugMsg("WTF?");
      return *(t_expr::t_struct_info*)nullptr;
    }
    return typelist[id];
  }
};

class t_full_stat_dev:public t_stat_dev{
public:
  class t_path{
  public:
    #define F(TYPE)typedef t_stat_cmds::TYPE TYPE;
    F(i_cmd        );
    F(t_block_id   );
    F(t_func_body  );
    F(t_oper_body  );
    F(t_for_body   );
    F(t_if_bef     );
    F(t_if_aft     );
    F(t_struct_body);
    #undef F
  public:
    vector<i_cmd*> arr;
  public:
    t_path(){}
    t_path(t_path&&ref){oper_move(std::move(ref));}
    t_path(const t_path&&){QapDebugMsg("no way");}
    void oper_move(t_path&&ref){
      arr=std::move(ref.arr);
    }
    void operator=(const t_path&){QapDebugMsg("no way");}
    void operator=(t_path&&ref){oper_move(std::move(ref));}
  public:
    void push(i_cmd*p)
    {
      arr.push_back(p);
    }
  public:
    void pop(i_cmd*p)
    {
      QapAssert(!arr.empty());
      QapAssert(arr.back()==p);
      arr.pop_back();
    }
  public:
    string toStr(){
      vector<string> out;out.push_back("root");
      for(int i=0;i<arr.size();i++){
        out.push_back(arr[i]->toStr());
      }
      return join(out,"::");
    }
    string toStr(int level){
      vector<string> out;out.push_back("root");
      int count=level<0?0:level;
      count=count<arr.size()?count:arr.size();
      QapAssert(count==level);
      for(int i=0;i<count;i++){
        out.push_back(arr[i]->toStr());
      }
      return join(out,"::");
    }
  };
public:
  class t_stack_frame{
  public:
    vector<t_stat_dev::t_context> stack;
    t_stat_dev::t_state state;
    t_path path;
    vector<string> rettype;
    t_stack_frame(){}
    t_stack_frame(t_stack_frame&&ref){oper_move(std::move(ref));}
    t_stack_frame(const t_stack_frame&&){QapDebugMsg("no way");}
    void oper_move(t_stack_frame&&ref){
      stack=std::move(ref.stack);
      state=std::move(ref.state);
      path=std::move(ref.path);
      rettype=std::move(ref.rettype);
    }
    void operator=(const t_stack_frame&){QapDebugMsg("no way");}
    void operator=(t_stack_frame&&ref){oper_move(std::move(ref));}
  };
public:
  struct t_err_frame{
    vector<string> rettype;
    string retpath;
    string errcode;
  };
public:
  vector<t_stack_frame> frames;
  vector<t_err_frame> err_frames;
  t_path path;
  vector<string> rettype;
  string retpath;
  string errcode;
  IEnvRTTI&Env;
  t_full_stat_dev(IEnvRTTI&Env):Env(Env){init();}
public:
  struct t_rettype_scope{
    t_full_stat_dev&dev;
    const string rettype;
    t_expr_value&out;
    t_rettype_scope(t_full_stat_dev&dev,const string&rettype,t_expr_value&out):dev(dev),rettype(rettype),out(out){
      QapAssert(!dev.expr_buff.value);
      //QapAssert(!out.value);
      dev.rettype.push_back(rettype);
    }
   ~t_rettype_scope(){
      QapAssert(!dev.rettype.empty());
      QapAssert(dev.rettype.back()==rettype);
      if(dev.expr_buff.gettype()!=rettype){
        string msg=(
          "return type is wrong!\n"
          "expected = "+rettype+"\n"
          "returned = "+dev.expr_buff.gettype()+"\n"
          "---\n"
          "path to return_stat:\n"+dev.path.toStr()
        );
        dev.drop_error(msg);
      }
      dev.rettype.pop_back();
      out=std::move(dev.expr_buff);
      dev.expr_buff.value=nullptr;
    }
  };
public:
  void push_frame(){
    t_stack_frame tmp;
    tmp.stack=std::move(stack);
    tmp.state=std::move(state);
    tmp.path=std::move(path);
    tmp.rettype=std::move(rettype);
    frames.push_back(std::move(tmp));
  }
  void pop_frame(){
    QapAssert(!frames.empty());
    auto&back=frames.back();
    stack=std::move(back.stack);
    state=std::move(back.state);
    path=std::move(back.path);
    rettype=std::move(back.rettype);
    frames.pop_back();
  }
  void init_funcs_and_opers()
  {
    auto*pSysOpersHolder=Sys$$<t_sys_opers_holder>::GetRTTI(Env);
    auto*pBase=Sys$$<i_sys_impl>::GetRTTI(Env);
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      if(!p->SubType)continue;
      if(p->SubType.get()!=pBase)continue;
      QapAssert(p->OwnType);
      bool isOper=p->OwnType->IsBasedOn(pSysOpersHolder);
      if(isOper&&p->extInfo.SpecInfo.empty()){
        QapDebugMsg(p->GetFullName()+" - this is oper_impl has wrong SpecInfo!");continue;
      }
      string name="__"+p->Info.Name;
      funcs.push_back(t_stat_dev::t_func());
      auto&back=funcs.back();
      auto*ptr=&back;
      ptr->body.unsafe_build(p);
      t_sys_func_tools::weak_init(Env,name,ptr->head,ptr->body);
      if(isOper){
        opers.push_back(t_stat_dev::t_oper());
        auto*ptr=&opers.back();
        ptr->head.info.isOper=true;
        ptr->body.unsafe_build(p);
        string oper_name=p->extInfo.SpecInfo;
        t_sys_func_tools::weak_init(Env,oper_name,ptr->head,ptr->body);
      }
    }
    int gg=1;
  }
  void init()
  {
    init_funcs_and_opers();
    init_rtti_funcs();
  }
  void init_rtti_funcs()
  {
    auto*pBase=Sys$$<i_sysfunc_with_rtti>::GetRTTI(Env);
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      if(!p->SubType)continue;
      if(p->SubType.get()!=pBase)continue;
      QapAssert(p->OwnType);
      string name="__"+p->Info.Name;
      rttifuncs.push_back(t_stat_dev::t_rtti_func());
      auto&back=rttifuncs.back();
      auto*ptr=&back;
      ptr->body.unsafe_build(p);
      t_sys_func_tools::weak_init(Env,name,ptr->head,ptr->body);
    }
    int gg=1;
  }
public:
  void push(){
    stack.push_back(t_context());
  }
  void pop(){
    stack.pop_back();
  }
  t_context&back(){
    return stack.back();
  }
  bool isRet()const{
    if(isErr())return true;
    return state.value=='R';
  }
  bool isCon()const{
    return state.value=='C';
  }
  bool isBre()const{
    return state.value=='B';
  }
  bool isErr()const{
    if(!errcode.empty())return true;
    return state.value=='E';
  }
public:
  struct t_find_retval{
    bool ok;
    int stack_id;
    int var_id;
  };
  t_find_retval find(const string&name){
    t_find_retval retval={false,-1,-1};
    for(int i=0;i<stack.size();i++){
      auto id=stack.size()-1-i;
      auto&ex=stack[id];
      auto ret=ex.find(name);
      if(ret<0)continue;
      retval.ok=true;
      retval.stack_id=id;
      retval.var_id=ret;
      return retval;
    }
    return retval;
  }
  t_var&unsafe_find_ref(const string&name){
    auto retval=find(name);
    if(!retval.ok){
      QapDebugMsg(name+" - variable not found.");
    }
    QapAssert(retval.ok);
    return stack[retval.stack_id].vars[retval.var_id];
  }
  t_var*find_ptr(const string&name){
    auto retval=find(name);
    if(!retval.ok)return nullptr;
    return &stack[retval.stack_id].vars[retval.var_id];
  }
  t_var*safe_find_pvar(const string&name){
    auto*ptr=find_ptr(name);
    if(ptr)return ptr;
    string msg=name+" - variable not found";
    //QapDebugMsg(msg);
    drop_error(msg);
    return nullptr;
  }
public:
  template<class t_xxxx>
  struct t_find_func_retval
  {
    vector<t_xxxx>&dev_arr;
    const vector<string>&params;
    string status;
    int id;
    vector<int> buff;
    void init(){
      status.clear();
      id=-1;
      buff.clear();
    }
    template<class TYPE>
    void grep_name_from_list_to_buff(const string&name,const vector<TYPE>&list){
      auto&arr=list;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.get_head().name==name)buff.push_back(i);
      }
    }
    static string get_code(const t_func&ref){return ref.get_head().get_code();}
    static string get_code(const t_oper&ref){return ref.get_head().get_code();}
    static string get_code(const t_rtti_func&ref){return ref.get_head().get_code();}
    bool check(const vector<t_func_param>&arr)
    {
      if(arr.size()!=params.size())return false;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        bool ok=ex.type==params[i];
        if(!ok){return false;}
      }
      return true;
    }
    void find_in_list(const string&name)
    {
      init();
      grep_name_from_list_to_buff(name,dev_arr);
      if(buff.empty()){status+=string("Not found").substr(0,1);return;}
      auto&arr=dev_arr;
      vector<int> win;
      for(int i=0;i<buff.size();i++){
        auto&ex=arr[buff[i]];
        auto&ex_params=ex.get_params();
        auto&ex_type=ex.get_type();
        bool ok=check(ex_params);
        if(!ok)continue;
        win.push_back(buff[i]);
      }
      if(win.empty())return;
      bool ok=win.size()==1;
      //QapAssert(ok);
      if(!ok){
        string msg="function has more than one implementation("+IToS(win.size())+" pcs.):\n";
        msg+=get_code(arr[win.front()]);
        QapDebugMsg(msg);
      }
      if(!ok){status+=string("Error").substr(0,1);return;}
      status+=string("Yes").substr(0,1);
      id=win.front();
      //ptr=&arr[id];
    }
    t_xxxx*find_xxxx(const string&name){
      find_in_list(name);
      return id<0?nullptr:&dev_arr[id];
    }
    static bool is_oper(t_oper*){return true;}
    static bool is_oper(void*){return false;}
    static bool is_oper(){return is_oper((t_xxxx*)nullptr);}
    string make_xxxx(const string&name)
    {
      string op=is_oper()?"operator":"";
      string msg="function "+op+name+"("+join(params,",")+") - not found\n";
      if(buff.size()>0){
        msg+="but found:\n";
        auto&arr=buff;
        for(int i=0;i<arr.size();i++){
          auto&ex=dev_arr[arr[i]];
          msg+=get_code(ex)+"\n";
        }
      }
      return msg;
    }
  };
public:
  t_var&add_var(const string&name){
    t_var tmp;
    //tmp.type=type;
    tmp.name=name;
    //tmp.value=value;
    auto&back=stack.back();
    QapAssert(!back.find_ptr(name));
    back.vars.push_back(std::move(tmp));
    return back.vars.back();
  }
  void drop_error(const string&msg){
    state.value='E';
    bool skip=!errcode.empty();
    err_frames.push_back(t_err_frame());
    auto&back=err_frames.back();
    back.retpath=path.toStr();
    back.errcode="["+cur_date_str()+"]:\n"+msg;
    back.rettype=rettype;
    if(skip)return;
    retpath=back.retpath;
    errcode=back.errcode;
  }
  void ret(t_expr_value&result){
    //QapAssert(&result==&expr_buff);
    expr_buff.set(*this,result);
    QapAssert(state.value=='N');
    state.value='R';
    QapAssert(!rettype.empty());
    if(rettype.back()!=result.gettype()){
      //retpath=path.toStr();
      string msg=(
        "return type is wrong!\n"
        "expected = "+rettype.back()+"\n"
        "returned = "+result.gettype()+"\n"
        "---\n"
        "path to return_stat:\n"+path.toStr()
      );
      drop_error(msg);
    }
  }
  void con(){
    QapAssert(state.value=='N');
    state.value='C';
  }
  void bre(){
    QapAssert(state.value=='N');
    state.value='B';
  }
public:
  class t_var_field_tool{
  public:
    typedef TAutoPtr<t_expr::i_value> t_val;
    typedef t_simple_stat_lex::t_var_expr t_var_expr;
  public:
    struct t_item{
      string name;
      vector<int> arr;
      //vector<t_expr_value> arr;
    };
  public:
    t_full_stat_dev&dev;
    t_val&val;
    vector<t_item> path;
    vector<t_val> stack;
  public:
    template<class TYPE>
    static void get_expr_value(t_full_stat_dev&dev,TYPE&expr){
      static_assert(std::is_same<t_simple_stat_lex::t_lev14,TYPE>::value,"WTF?");
      t_expr_visitor::get_expr_value(dev,expr);
    }
    void internal_load_path(vector<t_var_expr::t_item>&arr,bool hack)
    {
      int count=arr.size();
      if(count&&hack)count--;
      for(int i=0;i<count;i++)
      {
        auto&ex=arr[i];
        path.push_back(t_item());
        auto&back=path.back();
        back.name=ex.name.value;
        back.arr.resize(ex.arr.size());
        for(int i=0;i<ex.arr.size();i++)
        {
          auto&item=ex.arr[i];
          t_expr_value buff;
          {
            t_rettype_scope scope(dev,"int",buff);
            get_expr_value(dev,item.expr);
          }
          if(dev.isErr())return;
          back.arr[i]=buff.unsafe_get_ref_int();
        }
      }
    }
    void load_path(vector<t_var_expr::t_item>&arr)
    {
      internal_load_path(arr,false);
    }
    void load_path_hack(vector<t_var_expr::t_item>&arr)
    {
      internal_load_path(arr,true);
    }
    void unsafe_push_val(TAutoPtr<t_expr::i_value>&ref)
    {
      t_expr_value next;
      next.set(dev,ref);
      stack.push_back(std::move(val));
      val=std::move(next.value);
    }
    void unsafe_pop_val(TAutoPtr<t_expr::i_value>&ref)
    {
      auto&back=stack.back();
      ref=std::move(val);
      val=std::move(back);
      stack.pop_back();
    }
    void bef_arr_id(int id)
    {
      QapAssert(val);
      //t_array
      {
        auto*pv=t_expr::t_array::UberCast(val.get());
        if(pv)
        {
          auto&count=pv->count;
          if(id>=count||id<0){
            dev.drop_error("[2014.02.04 18:40]\nwrong offset:\ncount = "+IToS(count)+"\noffset = "+IToS(id));
            return;
          }
          if(pv->arr.size()!=pv->count){
            QapDebugMsg("WTF?");
            dev.drop_error("[2014.02.04 20:03]\nbef_arr_id::WTF?");
            return;
          }
          unsafe_push_val(pv->arr[id]);
          return;
        }
        int gg=1;
      }
      //t_vector
      {
        auto*pv=t_expr::t_vector::UberCast(val.get());
        if(pv)
        {
          auto count=pv->arr.size();
          if(id>=count||id<0){
            dev.drop_error("[2014.03.07 12:06]\nwrong offset:\ncount = "+IToS(count)+"\noffset = "+IToS(id));
            return;
          }
          unsafe_push_val(pv->arr[id]);
          return;
        }
        int gg=1;
      }
      dev.drop_error("[2014.02.04 23:09]\ntype does not support the element access:\n"+val->gettype());
      return;
    }
    void bef_arr(t_item&item)
    {
      if(item.arr.empty())return;
      auto&arr=item.arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        bef_arr_id(ex);
        if(dev.isErr())return;
      }
    }
    void bef_struct(t_item&field)
    {
      QapAssert(val);
      auto*pv=t_expr::t_struct::UberCast(val.get());
      if(!pv){
        dev.drop_error("[2014.02.04 23:15]\ntype is not struct:\n"+val->gettype());
        return;
      }
      auto struct_id=dev.find_struct_id_by_name(pv->type);
      if(struct_id<0){
        QapDebugMsg("WTF?");
        dev.drop_error("[2014.02.04 18:56]\nunknow struct type:\n"+pv->type);
        return;
      }
      auto&t=dev.typelist[struct_id];
      int id=t.find(field.name);
      if(id<0||id>=pv->arr.size()){
        dev.drop_error(
          "[2014.02.04 19:19]\nfield not found:\n"+field.name+"\n"
          "for type:\n"+pv->type
        );
        return;
      }
      t_val next;
      unsafe_easy_clone(dev.Env,next,pv->arr[id]);
      stack.push_back(std::move(val));
      val=std::move(next);
    }
    void bef()
    {
      QapAssert(!path.empty());
      bef_arr(path[0]);
      if(dev.isErr())return;
      for(int i=1;i<path.size();i++)
      {
        auto&field=path[i];
        bef_struct(field);
        if(dev.isErr())return;
        bef_arr(field);
        if(dev.isErr())return;
      }
    }
    void aft_arr_id(int id)
    {
      QapAssert(!stack.empty());
      auto&back=stack.back();
      //t_array
      {
        auto*pv=t_expr::t_array::UberCast(back.get());
        if(pv)
        {
          auto&count=pv->count;
          if(id>=count||id<0){
            dev.drop_error("[2014.02.04 19:59]\nwrong offset:\ncount = "+IToS(count)+"\noffset = "+IToS(id));
            return;
          }
          if(pv->arr.size()!=pv->count){
            QapDebugMsg("WTF?");
            dev.drop_error("[2014.02.04 20:04]\naft_arr_id::WTF?");
            return;
          }
          unsafe_pop_val(pv->arr[id]);
          return;
        }
        int gg=1;
      }
      //t_vector
      {
        auto*pv=t_expr::t_vector::UberCast(back.get());
        if(pv)
        {
          auto count=pv->arr.size();
          if(id>=count||id<0){
            dev.drop_error("[2014.03.07 12:11]\nwrong offset:\ncount = "+IToS(count)+"\noffset = "+IToS(id));
            return;
          }
          unsafe_pop_val(pv->arr[id]);
          return;
        }
        int gg=1;
      }
      dev.drop_error("[2014.03.07 12:10]\ntype does not support the element access:\n"+back->gettype());
      return;
    }
    void aft_arr(t_item&item)
    {
      if(item.arr.empty())return;
      auto&arr=item.arr;
      for(int i=arr.size()-1;i>=0;i--){
        auto&ex=arr[i];
        aft_arr_id(ex);
        if(dev.isErr())return;
      }
    }
    void aft_struct(t_item&field)
    {
      auto&back=stack.back();
      auto*pv=t_expr::t_struct::UberCast(back.get());
      if(!pv){
        dev.drop_error("[2014.02.04 23:16]\ntype is not struct:\n"+back->gettype());
        return;
      }
      auto struct_id=dev.find_struct_id_by_name(pv->type);
      if(struct_id<0){
        QapDebugMsg("WTF?");
        dev.drop_error("[2014.02.04 20:17]\nunknow struct type:\n"+pv->type);
        return;
      }
      auto&t=dev.typelist[struct_id];
      int id=t.find(field.name);
      if(id<0||id>=pv->arr.size()){
        dev.drop_error(
          "[2014.02.04 20:18]\nfield not found:\n"+field.name+"\n"
          "for type:\n"+pv->type
        );
        return;
      }
      pv->arr[id]=std::move(val);
      val=std::move(back);
      stack.pop_back();
    }
    void aft()
    {
      for(int i=path.size()-1;i>0;i--)
      {
        auto&field=path[i];
        aft_arr(field);
        //if(dev.isErr())return;
        aft_struct(field);
        //if(dev.isErr())return;
      }
      aft_arr(path[0]);
      QapAssert(stack.empty());
    }/*
      for(;!stack.empty();stack.pop_back())
      {
        auto&back=stack.back();
        auto&field=path[stack.size()-1];
        auto*pv=t_expr::t_struct::UberCast(back.get());
        QapAssert(pv);
        auto&t=dev.unsafe_find_struct(pv->type);
        int id=t.find(field);
        QapAssert(id>=0);
        QapAssert(id<pv->arr.size());
        pv->arr[id]=std::move(val);
        val=std::move(back);
      }
    }*/
  };
};

class t_stat_visitor;

class t_expr_visitor:public t_simple_stat_lex::i_expr_visitor{
public:
  typedef t_expr_visitor SelfClass;
  typedef i_expr_visitor ParentClass;
public:
  t_full_stat_dev&dev;
  t_expr_visitor(t_full_stat_dev&dev):dev(dev){}
public:
  #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
  F(t_lev14);
  F(t_lev13);
  F(t_lev12);
  F(t_lev11);
  F(t_lev10);
  F(t_lev09);
  F(t_lev08);
  F(t_lev07);
  F(t_lev06);
  F(t_lev05);
  F(t_lev03);
  #undef F
public:
  typedef t_stat_dev::t_expr_value t_expr_value;
  static t_expr_value&get_expr_value(t_full_stat_dev&dev,TAutoPtr<i_expr>&ref){
    t_expr_visitor V(dev);
    auto*ptr=ref.get();
    ptr->Use(V);
    auto&retval=dev.expr_buff;
    return retval;
  }
  static t_expr_value&get_expr_value(t_full_stat_dev&dev,t_lev14&ref){
    t_expr_visitor V(dev);
    V.Do(&ref);
    auto&retval=dev.expr_buff;
    return retval;
  }
public:
  void Do(t_char_expr*p){
    string&full=p->body.value;
    QapAssert(full.size()>2);
    QapAssert('\''==full.front());
    QapAssert('\''==full.back());
    BinString bin=full.substr(1,full.size()-2);
    string str=bin.data;
    QapAssert(str.size()==1);
    char value=str[0];
    dev.expr_buff.set_char(dev.Env,value);
  }
  void Do(t_bool_expr*p){
    bool value;
    bool ok=SToB(p->value,value);
    QapAssert(ok);
    dev.expr_buff.set_bool(dev.Env,value);
  }
  void Do(t_int_expr*p){
    int value=SToI(p->value);
    dev.expr_buff.set_int(dev.Env,value);
  }
  void Do(t_real_expr*p){
    real value=0;
    bool ok=SToF(p->value,value);
    QapAssert(ok);
    dev.expr_buff.set_real(dev.Env,value);
  }
  void Do(t_string_expr*p){
    BinString bin=p->body.value;
    //string value=BinString::fullCppStr2RawStr(p->value);
    dev.expr_buff.set_string(dev.Env,bin.data);
  }
  void Do(t_var_expr::t_impl*p){
    QapAssert(!p->arr.empty());
    auto&front=p->arr.front();
    string name=front.name.value;
    auto*pvar=dev.safe_find_pvar(name);
    if(!pvar){
      QapAssert(dev.isErr());
      return;
    }
    auto&ref=*pvar;
    t_expr_value val;
    val.set(dev,ref);
    //dev.expr_buff.set(dev,ref);
    if(!p->arr.empty())
    {
      typedef t_full_stat_dev::t_var_field_tool t_tool;
      t_tool tool={dev,val.value};
      tool.load_path(p->arr);
      tool.bef();
      {
        dev.expr_buff.set(dev,val);
        return;
      }
      //tool.aft();
      //var.value=std::move(var_value);
      return;
    }
  }
  void Do(t_var_expr*p){
    Do(&p->body);
  }
  void Do(t_block_expr*p){
    auto&value=get_expr_value(dev,p->body);
    dev.expr_buff.set(dev,value);
  }
public:
  template<class TYPE>
  void exprUse(TYPE&expr){
    Do(&expr);
  }
  //template<class TYPE>
  void exprUse(TAutoPtr<t_simple_stat_lex::i_expr>&expr){
    QapAssert(expr);
    expr->Use(*this);
  }
public:
  typedef t_stat_dev::t_oper t_oper;
public:
  void call_anyoper(vector<t_expr_value>&values,const string&oper){
    auto params=get_types_from_values(values);
    t_cmd_dev<t_oper_stat> cmddev(values,params,oper);
    bool ok=cmddev.main(dev);
    if(ok)return;
    dev.push_frame();
    weak_call_xxxx<t_oper>(dev,values,oper);
    QapAssert(dev.isRet());
    dev.pop_frame();
  }
  void call_binoper(const string&oper,t_expr_value&&bef,t_expr_value&&aft){
    dev.push();
    vector<t_expr_value> values;
    values.push_back(std::move(bef));
    values.push_back(std::move(aft));
    call_anyoper(values,oper);
    dev.pop();
  }
  void call_oneoper(const string&oper,t_expr_value&&value){
    dev.push();
    vector<t_expr_value> values;
    values.push_back(std::move(value));
    call_anyoper(values,oper);
    dev.pop();
  }
public:
  template<class TYPE>
  void DoLevel(TYPE*p)
  {
    exprUse(p->expr);
    if(dev.isErr())return;
    auto&arr=p->arr;
    if(arr.empty())return;
    t_expr_value buff=std::move(dev.expr_buff);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      exprUse(ex.expr);
      if(dev.isErr())return;
      const string&oper=ex.oper.value;
      call_binoper(oper,std::move(buff),std::move(dev.expr_buff));
      if(dev.isErr())return;
      buff=std::move(dev.expr_buff);
      dev.expr_buff.value=nullptr;
    }
    dev.expr_buff=std::move(buff);
    //QapDebugMsg("void operator+(?,?) no has impl for "+type);
  }
public:
  void Do(t_lev03*p){
    exprUse(p->expr);
    if(dev.isErr())return;
    const auto&oper=p->oper;
    if(oper.empty())return;
    call_oneoper(oper,std::move(dev.expr_buff));
  }
  void Do(t_lev05*p){DoLevel(p);}
  void Do(t_lev06*p){DoLevel(p);}
  void Do(t_lev07*p){DoLevel(p);}
  void Do(t_lev08*p){DoLevel(p);}
  void Do(t_lev09*p){DoLevel(p);}
  void Do(t_lev10*p){DoLevel(p);}
  void Do(t_lev11*p){DoLevel(p);}
  void Do(t_lev12*p){DoLevel(p);}
  void Do(t_lev13*p){DoLevel(p);}
  void Do(t_lev14*p){DoLevel(p);}
public:
  typedef t_simple_stat_lex::t_call_params t_call_params;
  typedef t_simple_stat_lex::t_call_param t_call_param;
  typedef t_stat_dev::t_expr_value t_expr_value;
public:
  static vector<t_expr_value> get_params_values(t_full_stat_dev&dev,t_call_params&params){
    vector<t_stat_dev::t_expr_value> out;
    if(params.arr.empty())return out;
    auto&arr=params.arr;
    out.resize(arr.size());
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto&value=t_expr_visitor::get_expr_value(dev,ex.body);
      if(dev.isErr())return out;
      t_expr_value&item=out[i];
      item=std::move(value);
      value.value=nullptr;
    }
    return out;
  }
public:
  static vector<string> get_types_from_values(const vector<t_expr_value>&values)
  {
    vector<string> out;
    for(int i=0;i<values.size();i++)out.push_back(values[i].gettype());
    return out;
  }
  static vector<string> get_types_from_params(const t_simple_stat_lex::t_params&params){
    vector<string> out;
    auto&arr=params.arr;
    for(int i=0;i<arr.size();i++){
      out.push_back(arr[i].type);
    }
    return out;
  }
public:
  #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
  F(i_stat_visitor);
  //F(t_block_stat);
  F(t_func_stat);
  F(t_command_block);
  #undef F
public:
  typedef t_stat_dev::t_oper t_oper;
  typedef t_stat_dev::t_func t_func;
  static vector<t_func>&get_dev_arr(t_stat_dev&dev,t_func*){return dev.funcs;}
  static vector<t_oper>&get_dev_arr(t_stat_dev&dev,t_oper*){return dev.opers;}
  template<class t_xxxx>
  static bool weak_call_xxxx(t_full_stat_dev&dev,vector<t_expr_value>&values,const string&name)
  {
    QapClock clock;clock.Start();
    vector<string> types=get_types_from_values(values);
    auto&dev_arr=get_dev_arr(dev,(t_xxxx*)nullptr);
    t_full_stat_dev::t_find_func_retval<t_xxxx> retval={dev_arr,types};
    auto*ptr=retval.find_xxxx(name);
    if(!ptr){
      string msg=retval.make_xxxx(name);
      dev.drop_error(msg);
      //QapDebugMsg(msg);
      return false;
    }
    dev.info.find_time+=clock.MS();
    ptr->exec(dev,values);
    return true;
  }
public:
  typedef t_full_stat_dev t_dev;
  typedef t_dev::t_rettype_scope t_rettype_scope;
public:
  typedef t_simple_stat_lex::t_oper_stat t_oper_stat;
  typedef t_simple_stat_lex::t_func_stat t_func_stat;
  typedef t_simple_stat_lex::t_struct_stat t_struct_stat;
  typedef t_simple_stat_lex::t_template_stat t_template_stat;
  typedef t_simple_stat_lex::t_params t_params;
public:
  class t_template_stat_get_name:public t_template_stat::i_body_visitor{
  public:
    class t_dev{
    public:
      string*name;
    };
    t_dev&dev;
    t_template_stat_get_name(t_dev&dev):dev(dev){}
  public:
    void Do(t_func_body*p){dev.name=&p->body.name.value;}
    void Do(t_oper_body*p){dev.name=&p->body.oper;}
    void Do(t_struct_body*p){dev.name=&p->body.name.value;}
  public:
    static const string&main(TAutoPtr<t_template_stat::i_body>&ref){
      t_dev dev={nullptr};
      t_template_stat_get_name V(dev);
      auto*p=ref.get();
      p->Use(V);
      return *dev.name;
    }
  };
public:
  static const string&get_name(t_func_stat*ptr){return ptr->body.name.value;}
  static const string&get_name(t_oper_stat*ptr){return ptr->oper;}
  static const string&get_name(t_struct_stat*ptr){return ptr->body.name.value;}
  static const string&get_name(t_template_stat*ptr){return t_template_stat_get_name::main(ptr->body);}
public:
  static const string&get_type(t_func_stat*ptr){return ptr->body.type;}
  static const string&get_type(t_oper_stat*ptr){return ptr->type;}
public:
  static t_params&get_params(t_func_stat*ptr){return ptr->body.params;}
  static t_params&get_params(t_oper_stat*ptr){return ptr->params;}
public:
  static t_command_block&get_body(t_func_stat*ptr){return ptr->body.body;}
  static t_command_block&get_body(t_oper_stat*ptr){return ptr->body;}
public:
  static string get_xxxx_code(t_func_stat&xxxx){
    return get_type(&xxxx)+" "        +get_name(&xxxx)+get_params_string(get_params(&xxxx));
  }
  static string get_xxxx_code(t_oper_stat&xxxx){
    return get_type(&xxxx)+" operator"+get_name(&xxxx)+get_params_string(get_params(&xxxx));
  }
  static string get_xxxx_code(t_stat_dev::t_func&xxxx){
    return xxxx.get_head().get_code();
  }
  static string get_xxxx_code(t_stat_dev::t_oper&xxxx){
    return xxxx.get_head().get_code();
  }
public:
  template<class t_xxxx_stat>
  class t_cmd_dev{
  public:
    struct t_rec{
      int id;
      t_xxxx_stat*pstat;
    };
    struct t_frame{
      int level;
      vector<t_rec> arr;
    };
  public:
    vector<t_expr_value>&values;
    const vector<string>&params;
    string name;
    vector<t_rec> wins;
    vector<t_rec> fails;
    vector<t_frame> stack;
    t_cmd_dev(
      vector<t_expr_value>&values,
      const vector<string>&params,
      const string&name
    ):values(values),params(params),name(name){}
  public:
    void make_frame(int level){
      if(fails.empty())return;
      t_frame tmp={level,fails};
      stack.push_back(tmp);
      fails.clear();
    }
  public:
    void add_win(int id,t_xxxx_stat*p){t_rec tmp={id,p};wins.push_back(tmp);}
    void add_fail(int id,t_xxxx_stat*p){t_rec tmp={id,p};fails.push_back(tmp);}
  public:
    void find_xxxxs(t_stat_cmds::i_cmd*p)
    {
      QapAssert(p);
      auto*ptr=t_stat_cmds::t_block_id::UberCast(p);
      if(!ptr)return;
      find_xxxxs(ptr);
    }
    void find_templ(t_stat_cmds::t_block_id*p)
    {
      auto&arr=p->ptr->arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*ptr=t_template_stat::UberCast(ex.get());
        if(!ptr)continue;
        if(get_name(ptr)!=name)continue;
        auto*fb_ptr=t_template_stat::t_func_body::UberCast(ptr->body.get());
        if(!fb_ptr)continue;
        auto&func_params=fb_ptr->body.params;
        int fp_size=func_params.arr.size();
        if(fp_size!=params.size()){
          add_fail(i,ptr);
          continue;
        }
        add_win(i,ptr);
      }
    }
    void find_xxxxs(t_stat_cmds::t_block_id*p)
    {
      auto&arr=p->ptr->arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*ptr=i_stat_visitor::UberCast<t_xxxx_stat>(ex.get());
        if(!ptr)continue;
        if(get_name(ptr)!=name)continue;
        auto func_params=get_types_from_params(get_params(ptr));
        if(func_params!=params){
          add_fail(i,ptr);
          continue;
        }
        add_win(i,ptr);
      }
    }
  public:
    template<class t_xxxx_stat>struct conv_stat_to_body;
    template<>struct conv_stat_to_body<t_func_stat>{typedef t_stat_cmds::t_func_body type;};
    template<>struct conv_stat_to_body<t_oper_stat>{typedef t_stat_cmds::t_oper_body type;};
  public:
    typedef typename conv_stat_to_body<t_xxxx_stat>::type t_stat_cmds__t_xxxx_body;
  public:
    void exec_xxxx_stat(t_dev&dev,t_xxxx_stat&xxxx,vector<t_expr_value>&values)
    {
      //t_func_stat or t_oper_stat
      dev.push();
      {
        auto&params=get_params(&xxxx).arr;
        QapAssert(params.size()==values.size());
        auto&arr=values;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          auto&param=params[i];
          QapAssert(ex.gettype()==param.type);
          dev.add_var(param.name.value).value.set(dev,ex);
        }
      }
      string functype=get_type(&xxxx);
      {
        auto&body=get_body(&xxxx);
        t_stat_visitor V(dev);
        {
          t_expr_value out;
          {
            t_rettype_scope scope(dev,functype,out);
            V.Do(&body);
          }
          if(dev.isErr())return;
          dev.expr_buff=std::move(out);
        }
      }
      if(functype!="void")
      {
        QapAssert(dev.isRet());
        string exprtype=dev.expr_buff.gettype();
        if(functype!=exprtype){
          QapDebugMsg(
            "for function:\n"+get_xxxx_code(xxxx)+"\n"
            "path to return_stat:\n"+dev.retpath+"\n"
            "return type is wrong!\n"
            "---\n"
            "func.type = "+functype+"\n"
            "expr.type = "+exprtype+"\n"
          );
        }
      }
      if(dev.isErr()){
        string msg="error in function:\n"+get_xxxx_code(xxxx)+"\n";
        msg+="retpath:\n"+dev.retpath+"\n";
        msg+="\n\n[-----errcode-----]:\n"+dev.errcode+"\n";
        //dev.errcode";
        QapDebugMsg(msg);
      }
      dev.pop();
    }
  public:
    bool main(t_full_stat_dev&dev)
    {
      auto&arr=dev.path.arr;
      for(int i=0;i<arr.size();i++)
      {
        int id=arr.size()-1-i;
        auto*ptr=arr[id];
        QapAssert(wins.empty());
        find_xxxxs(ptr);
        if(wins.size()==1)
        {
          auto&cmd=wins.front();
          dev.push_frame();
          {
            const auto&arr=dev.frames.back().path.arr;
            {t_full_stat_dev::t_path path;path.arr=subarr(arr,0,id+1);dev.path=std::move(path);}
            QapAssert(!dev.path.arr.empty());
            auto*pBlock=t_stat_cmds::t_block_id::UberCast(dev.path.arr.back());
            QapAssert(pBlock);
            dev.path.arr.pop_back();
            t_stat_cmds::t_block_id block_scope(dev,pBlock->ptr,cmd.id);
            t_stat_cmds__t_xxxx_body xxxx_scope(dev,cmd.pstat);
            exec_xxxx_stat(dev,*cmd.pstat,values);
          }
          dev.pop_frame();
          return true;
        }
        if(wins.size()>1)
        {
          string msg="path to caller:\n";
          msg+=dev.path.toStr()+"\n";
          msg+="The function call is ambiguous:\n";
          msg+=name+"("+join(params,",")+");\n";
          msg+="found("+IToS(wins.size())+" pcs.):\n";
          msg+=cmd_xxxx_join(wins,"\n")+"\n";
          {
            msg+="path to block with functions:\n";
            msg+=dev.path.toStr(id)+"\n";
          }
          dev.drop_error(msg);
          return true;
        }
        make_frame(id);
        continue;
      }
      return false;
    }
  };
public:
  typedef t_simple_stat_lex::t_func_stat t_func_stat;
  typedef t_simple_stat_lex::t_oper_stat t_oper_stat;
  //typedef t_simple_stat_lex::t_params t_params;
  static string get_params_string(const t_simple_stat_lex::t_params&params){
    vector<string> out=get_types_from_params(params);
    return "("+join(out,",")+")";
  }
public:
  //template<class t_xxxx_stat>
  static string cmd_xxxx_join(vector<t_cmd_dev<t_oper_stat>::t_rec>&arr,const string&needle)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      //string path=dev.path.toStr(ex.level);
      out.push_back("::block_id["+IToS(ex.id)+"]=>  "+get_xxxx_code(*ex.pstat)+";");
    }
    return join(out,needle);
  };
  static string cmd_xxxx_join(vector<t_cmd_dev<t_func_stat>::t_rec>&arr,const string&needle)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      //string path=dev.path.toStr(ex.level);
      out.push_back("::block_id["+IToS(ex.id)+"]=>  "+get_xxxx_code(*ex.pstat)+";");
    }
    return join(out,needle);
  };
public:
  typedef t_stat_dev::t_func t_func;
public:
  class t_blob_space{
  public:
    class t_dev{
    public:
      t_full_stat_dev&dev;
      string&buff;
      int pos;
      bool ok;
      string error;
      //vector<> stack;
    public:
      template<class TYPE>
      bool save_vector_size(vector<TYPE>&ref){
        string out;
        out.resize(4);
        ((int&)out[0])=ref.size();
        buff+=out;
        return true;
      }
      template<class TYPE>
      bool safe_load_vector_size(vector<TYPE>&ref){
        int c=0;
        if(!safe_load(c,"[2014.03.06 21:44]:\nsafe_load_vector_size::end_of_buff"))return false;
        if(c<0||c>1024*1024)
        {
          drop_error("safe_load_vector_size::if(c<0||c>1024*1024) passed.\nwhere c="+IToS(c));
          return false;
        }
        ref.resize(c);
        return true;
      }
      bool load(char*p,int size){
        if(!check(size))return false;
        for(int i=0;i<size;i++){
          p[i]=buff[pos+i];
        }
        pos+=size;
        return true;
      }
      template<class TYPE>
      bool safe_load(TYPE&ref,const char*const err_msg){
        bool ok=load((char*)&ref,sizeof(TYPE));
        if(ok)return true;
        drop_error(err_msg);
        return false;
      }
      bool check(int size)const{return pos>=0&&pos<buff.size()&&size+pos>=0&&size+pos<=buff.size();}
      void drop_error(const string&msg){
        ok=false;error=msg;
      }
      bool isErr()const{return !error.empty();}
      void push(){

      }
      void pop(){

      }
    };
  };
  class t_sysval_to_blob:public t_expr::i_sysval_visitor,public t_blob_space{
  public:
    t_dev&dev;
    t_sysval_to_blob(t_dev&dev):dev(dev){}
  public:
    void Do(t_string*p){
      auto&inp=p->value;
      auto size=inp.size();
      dev.buff+=string((char*)(void*)&size,sizeof(size));
      dev.buff+=inp;
    }
    void Do(t_int*p){
      auto&inp=p->value;
      dev.buff+=string((char*)(void*)&inp,sizeof(inp));
    }
    void Do(t_char*p){
      auto&inp=p->value;
      dev.buff+=string((char*)(void*)&inp,sizeof(inp));
    }
    void Do(t_bool*p){
      auto&inp=p->value;
      dev.buff+=string((char*)(void*)&inp,sizeof(inp));
    }
    void Do(t_real*p){
      auto&inp=p->value;
      dev.buff+=string((char*)(void*)&inp,sizeof(inp));
    }
  };
  class t_blob_to_sysval:public t_expr::i_sysval_visitor,public t_blob_space{
  public:
    t_dev&dev;
    t_blob_to_sysval(t_dev&dev):dev(dev){}
  public:
    void Do(t_string*p){
      auto&out=p->value;
      int size=0;
      if(!dev.safe_load(size,"string::int"))return;
      if(!size)return;
      if(!dev.check(size)){
        dev.drop_error("wrong_size:\n"+IToS(size));
        return;
      }
      out.resize(size);
      dev.load(&out[0],size);
    }
    void Do(t_int*p){
      auto&out=p->value;
      dev.safe_load(out,"int");
    }
    void Do(t_char*p){
      auto&out=p->value;
      dev.safe_load(out,"char");
    }
    void Do(t_bool*p){
      auto&out=p->value;
      dev.safe_load(out,"bool");
    }
    void Do(t_real*p){
      auto&out=p->value;
      dev.safe_load(out,"real");
    }
  };
public:
  class t_value_to_blob:public t_expr::i_value_visitor,public t_blob_space{
  public:
    t_dev&dev;
    t_value_to_blob(t_dev&dev):dev(dev){}
  public:
    void Do(t_sys*p){
      t_sysval_to_blob V(dev);
      auto*ptr=p->value.get();
      ptr->Use(V);
    }
    void Do(t_struct*p){
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto*ptr=ex.get();
        dev.push();
        ptr->Use(*this);
        dev.pop();
        if(dev.isErr())return;
      }
    }
    void Do(t_array*p){
      QapAssert(p->count==p->arr.size());
      //dev.add_int(arr.size());
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto*ptr=ex.get();
        dev.push();
        ptr->Use(*this);
        dev.pop();
        if(dev.isErr())return;
      }
    }
    void Do(t_vector*p){
      dev.save_vector_size(p->arr);
      if(dev.isErr())return;
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto*ptr=ex.get();
        dev.push();
        ptr->Use(*this);
        dev.pop();
        if(dev.isErr())return;
      }
    }
  };
  class t_blob_to_value:public t_expr::i_value_visitor,public t_blob_space{
  public:
    t_dev&dev;
    t_blob_to_value(t_dev&dev):dev(dev){}
  public:
    void Do(t_sys*p){
      t_blob_to_sysval V(dev);
      auto*ptr=p->value.get();
      ptr->Use(V);
    }
    void Do(t_struct*p){
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto*ptr=ex.get();
        dev.push();
        ptr->Use(*this);
        dev.pop();
        if(dev.isErr())return;
      }
    }
    void Do(t_array*p){
      QapAssert(p->count==p->arr.size());
      //dev.add_int(arr.size());
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto*ptr=ex.get();
        dev.push();
        ptr->Use(*this);
        dev.pop();
        if(dev.isErr())return;
      }
    }
    template<int>
    void weak_do_vector(t_vector*p)
    {
      dev.safe_load_vector_size(p->arr);
      if(dev.isErr())return;
      typedef t_stat_visitor::t_var_impl_visitor t_var_impl_visitor;
      t_var_impl_visitor viv(dev.dev);
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!viv.do_var_init_by_string_full(ex,p->subtype)){
          string msg=(
            "error in t_blob_to_value::Do(t_vector*)\n"
            "for type:\n"+p->gettype()+"\n"
            "subtype not found:\n"+
            p->subtype
          );
          dev.drop_error(msg);
          return;
        }
        auto*ptr=ex.get();
        dev.push();
        ptr->Use(*this);
        dev.pop();
        if(dev.isErr())return;
      }
      int gg=1;
    }
    void Do(t_vector*p)
    {
      weak_do_vector<0>(p);
    }
  };
public:
  struct t_call_visitor:public t_call_expr::i_call_visitor{
  public:
    class t_machine{
    public:
      t_full_stat_dev&dev;
      vector<t_expr_value>&params_values;
      bool ok;
      bool hack_call;
      bool value_changed;
      string varname;
      t_machine(t_full_stat_dev&dev,vector<t_expr_value>&params_values)
        :
        dev(dev),
        params_values(params_values)
      {
        ok=false;
        hack_call=false;
        value_changed=false;
      }
    };
    t_machine&machine;
    t_call_visitor(t_machine&machine):machine(machine){}
  public:
    template<int>
    bool weak_init_var(TAutoPtr<t_expr::i_value>&value,const string&type)
    {
      auto&dev=machine.dev;
      typedef t_stat_visitor::t_var_impl_visitor t_var_impl_visitor;
      t_var_impl_visitor viv(dev);
      return viv.do_var_init_by_string_full(value,type);
    }
  public:
    bool call_method(const string&method,TAutoPtr<t_expr::i_value>&val)
    {
      auto&values=machine.params_values;
      auto*pvalue=val.get();
      auto&dev=machine.dev;
      if("toProto"==method){
        #define CHECK(COND)if(!(COND)){\
          dev.drop_error(\
            "file"":"__FILE__"\nline:"+IToS(__LINE__)+"\n"\
            "function:"__FUNCTION__"\ncondition:\n"#COND\
          );return false;}
        CHECK(values.empty());
        #undef CHECK
        string out=QapPublicUberFullSaverProtoToStr(dev.Env,QapRawUberObject(val));
        dev.expr_buff.set_string(dev.Env,out);
        return true;
      }
      if("size"==method)
      {
        if(true)
        {
          #define CHECK(COND)if(!(COND)){\
            dev.drop_error(\
              "file"":"__FILE__"\nline:"+IToS(__LINE__)+"\n"\
              "function:"__FUNCTION__"\ncondition:\n"#COND\
            );return false;}
          CHECK(values.empty());
          #undef CHECK
        }
        auto*p=val.get();
        {
          auto*psys=t_expr::t_sys::UberCast(p);
          if(psys)
          {
            auto*pstr=t_expr::t_string::UberCast(psys->value.get());
            if(!pstr)return false;
            int size=pstr->value.size();
            dev.expr_buff.set_int(dev.Env,size);
            return true;
          }
          int gg=1;
        }
        {
          auto*parr=t_expr::t_array::UberCast(p);
          if(parr)
          {
            QapAssert(parr->arr.size()==parr->count);
            int size=parr->arr.size();
            dev.expr_buff.set_int(dev.Env,size);
            return true;
          }
          int gg=1;
        }
        {
          auto*parr=t_expr::t_vector::UberCast(p);
          if(parr)
          {
            int size=parr->arr.size();
            dev.expr_buff.set_int(dev.Env,size);
            return true;
          }
          int gg=1;
        }
        return false;
      }
      if("toJson"==method)
      {
        return false;
      }
      if("pop_back"==method)
      {
        auto*p=val.get();
        auto*parr=t_expr::t_vector::UberCast(p);
        int new_size=0;
        if(true||new_size)
        {
          string err_info;
          #define CHECK(COND)if(!(COND)){\
            dev.drop_error(\
              "file"":"__FILE__"\nline:"+IToS(__LINE__)+"\n"\
              "function:"__FUNCTION__"\ncondition:\n"#COND+err_info\
            );return false;}
          #define CHECK_WITH_INFO(COND,INFO)if(!(COND))err_info+="\n"+(INFO);CHECK(COND);
          CHECK(parr);
          CHECK_WITH_INFO(values.size()==0,"values.size = "+IToS(values.size()));
          CHECK_WITH_INFO(parr->arr.size()>0,"parr->arr.size = "+IToS(parr->arr.size()));
          new_size=int(parr->arr.size())-1;
          CHECK_WITH_INFO(new_size>=0&&new_size<1024*1024,"new_size = "+IToS(new_size));
          //CHECK(new_size>=0&&new_size<1024*1024);
          #undef CHECK_WITH_INFO
          #undef CHECK
        }
        parr->arr.resize(new_size);
        machine.value_changed=true;
        return true;
      }
      if("push_back"==method)
      {
        auto*p=val.get();
        auto*parr=t_expr::t_vector::UberCast(p);
        int new_size=0;
        if(true||new_size)
        {
          string err_info;
          #define CHECK(COND)if(!(COND)){\
            dev.drop_error(\
              "file"":"__FILE__"\nline:"+IToS(__LINE__)+"\n"\
              "function:"__FUNCTION__"\ncondition:\n"#COND+err_info\
            );return false;}
          #define CHECK_WITH_INFO(COND,INFO)if(!(COND))err_info+="\n"+(INFO);CHECK(COND);
          CHECK(parr);
          CHECK_WITH_INFO(values.size()==1,"values.size = "+IToS(values.size()));
          CHECK_WITH_INFO(
            parr->subtype==values[0].gettype(),
            "parr->subtype = "+parr->subtype+"\n"
            "values[0].gettype = "+values[0].gettype()
          );
          new_size=parr->arr.size()+1;
          CHECK_WITH_INFO(new_size>=0&&new_size<1024*1024,"new_size = "+IToS(new_size));
          #undef CHECK_WITH_INFO
          #undef CHECK
        }
        parr->arr.resize(new_size);
        auto&back=parr->arr.back();
        if(!weak_init_var<0>(back,parr->subtype)){
          string msg=(
            "error in method push_back\n"
            "for type:\n"+p->gettype()+"\n"
            "subtype not found:\n"+
            parr->subtype
          );
          dev.drop_error(msg);
          return true;
        }
        t_expr_value::clone(dev,back,values[0].value);
        machine.value_changed=true;
        return true;
      }
      if("resize"==method)
      {
        int new_size=0;
        if(true||new_size)
        {
          string err_info;
          #define CHECK(COND)if(!(COND)){\
            dev.drop_error(\
              "file"":"__FILE__"\nline:"+IToS(__LINE__)+"\n"\
              "function:"__FUNCTION__"\ncondition:\n"#COND+err_info\
            );return false;}
          #define CHECK_WITH_INFO(COND,INFO)if(!(COND))err_info+="\n"+(INFO);CHECK(COND);
          CHECK_WITH_INFO(values.size()==1,"values.size = "+IToS(values.size()));
          CHECK_WITH_INFO(values[0].isInt(),"values[0].gettype = "+values[0].gettype());
          new_size=values[0].unsafe_get_ref_int();
          CHECK_WITH_INFO(new_size>=0&&new_size<1024*1024,"new_size = "+IToS(new_size));
          #undef CHECK_WITH_INFO
          #undef CHECK
        }
        auto*p=val.get();
        {
          auto*psys=t_expr::t_sys::UberCast(p);
          if(psys)
          {
            auto*pstr=t_expr::t_string::UberCast(psys->value.get());
            if(!pstr)return false;
            pstr->value.resize(new_size);
            machine.value_changed=true;
            return true;
          }
          int gg=1;
        }
        {
          auto*parr=t_expr::t_vector::UberCast(p);
          if(parr)
          {
            parr->arr.resize(new_size);
            auto&arr=parr->arr;
            for(int i=0;i<arr.size();i++)
            {
              auto&back=arr[i];
              if(!weak_init_var<0>(back,parr->subtype))
              {
                string msg=(
                  "error in method resize\n"
                  "for type:\n"+p->gettype()+"\n"
                  "subtype not found:\n"+
                  parr->subtype
                );
                dev.drop_error(msg);
                return true;
              }
            }
            machine.value_changed=true;
            return true;
          }
          int gg=1;
        }
        return false;
      }
      if("toBlob"==method)
      {
        string out;
        {
          t_blob_space::t_dev bdev={dev,out};
          t_value_to_blob V(bdev);
          pvalue->Use(V);
        }
        if(dev.isErr())return true;
        dev.expr_buff.set_string(dev.Env,out);
        return true;
      }
      if("fromBlob"==method)
      {
        #define CHECK(COND)if(!(COND)){\
          dev.drop_error(\
            "file"":"__FILE__"\nline:"+IToS(__LINE__)+"\n"\
            "function:"__FUNCTION__"\ncondition:\n"#COND\
          );return false;}
        CHECK(values.size()==1);
        CHECK(values.front().isString());
        #undef CHECK
        auto&inp=values.front().unsafe_get_ref_string();
        t_blob_to_value::t_dev bdev={dev,inp};
        bdev.pos=0;
        bdev.ok=false;
        t_blob_to_value V(bdev);
        pvalue->Use(V);
        if(bdev.isErr()){
          dev.drop_error("error inside method 'fromBlob':\n"+bdev.error);
          return false;
        }
        machine.value_changed=true;
        return true;
      }
      return false;
    }
  public:
    void Do(t_dot*p)
    {
      auto&dev=machine.dev;
      auto&call=p->body;
      QapAssert(!call.arr.empty());
      auto&front=call.arr.front();
      auto&varname=front.name.value;
      if(call.arr.size()==1){
        machine.ok=false;
        machine.hack_call=true;
        machine.varname=varname;
        return;
      }
      auto*pvar=dev.safe_find_pvar(varname);
      if(!pvar)return;
      auto&var=*pvar;
      t_expr_value var_value;
      var_value.set(dev,var.value);
      if(dev.isErr())return;
      {
        typedef t_full_stat_dev::t_var_field_tool t_tool;
        t_tool tool={dev,var_value.value};
        tool.load_path_hack(call.arr);
        if(dev.isErr())return;
        tool.bef();
        if(dev.isErr())return;
        {
          auto&back=call.arr.back();
          if(!back.arr.empty()){
            dev.drop_error("[2014.02.06 16:43]\n!back.arr.empty()\nno way.");
            return;
          }
          string method=back.name.value;
          bool ok=call_method(method,tool.val);
          if(!ok){
            //QapDebugMsg(method+" - unknow method.\nno way.");
            dev.drop_error("[2014.02.06 16:44]\nunknow method:\n"+method);
            return;
          }
          if(dev.isErr())return;
          if(!machine.value_changed)
          {
            machine.ok=true;
            return;
          }
          //var_value.set(dev,dev.expr_buff);
        }
        tool.aft();
        if(dev.isErr())return;
        var.value=std::move(var_value);
        machine.ok=true;
        return;
      }
      QapDebugMsg("no impl");
      int gg=1;
      return;
    }
    void Do(t_colon*p){
      QapDebugMsg("no way.");
      machine.dev.drop_error("[2014.02.06 15:12]:\nvoid Do(t_colon*p)\nno way.");
      return;
    }
  };
public:
  static string StrToCpp(const string&content){
    CppString cpp;
    cpp=content;
    return "\""+cpp.data+"\"";
  }
  static string conv_func_head_to_stat_in_json(t_stat_dev::t_func_head&head)
  {
    auto*p=&head.info;
    vector<string> out;real k=1000.0;
    #define F(NAME,VALUE,FUNC)out.push_back("\""#NAME"\":"+FUNC(VALUE));
    F(name,head.get_code(),StrToCpp);
    F(count,p->counter,IToS);
    F(exec,p->exec_time*k,FToS);
    F(full,p->full_time*k,FToS);
    F(f/e,p->full_time/p->exec_time,FToS);
    F(avg_e,p->exec_time*k/real(p->counter),FToS);
    F(avg_f,p->full_time*k/real(p->counter),FToS);
    #undef F
    return "{"+join(out,",")+"}";
  }
  template<class TYPE>
  static void grab_sysfunc_stats(vector<string>&out,vector<TYPE>&inp)
  {
    auto&arr=inp;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex.head.info.counter)continue;
      out.push_back(conv_func_head_to_stat_in_json(ex.head));
    }
  }
  struct t_sysfunc_total_time{
    real exec;
    real full;
  };
  template<class TYPE>
  static t_sysfunc_total_time get_sysfunc_total_time(vector<TYPE>&inp){
    auto&arr=inp;
    real exec=0.0;
    real full=0.0;real k=1000.0;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&info=ex.head.info;
      if(!info.counter)continue;
      exec+=info.exec_time*k;
      full+=info.full_time*k;
    }
    t_sysfunc_total_time tmp={exec,full};
    return tmp;
  }
  bool try_call_internal_routines(const string&func,vector<t_expr_value>&values)
  {
    if(func=="__get_internal_funcs_list")
    {
      if(!values.empty())return false;
      vector<string> out;
      auto&arr=dev.funcs;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        out.push_back(ex.get_head().get_code());
      }
      string outstr=join(out,"\n");
      dev.expr_buff.set_string(dev.Env,outstr);
      return true;
    }
    if(func=="__get_internal_stats")
    {
      if(!values.empty())return false;
      vector<string> out;
      grab_sysfunc_stats(out,dev.funcs);
      grab_sysfunc_stats(out,dev.opers);
      grab_sysfunc_stats(out,dev.rttifuncs);
      string outstr="[\n"+join(out,",\n")+"\n]";
      t_sysfunc_total_time stt={0,0};
      {
        t_sysfunc_total_time arr[]={
          get_sysfunc_total_time(dev.funcs),
          get_sysfunc_total_time(dev.opers),
          get_sysfunc_total_time(dev.rttifuncs)
        };
        for(int i=0;i<lenof(arr);i++){
          stt.exec+=arr[i].exec;
          stt.full+=arr[i].full;
        }
      }
      vector<string> arr;
      auto add=[&arr](const string&name,real value){
        arr.push_back(StrToCpp(name)+":"+FToS(value));
      };
      real tote=stt.exec;
      real totf=stt.full;
      add("total_e",tote);
      add("total_f",totf);
      add("f/e",totf/tote);
      add("find_time",dev.info.find_time*1000.0);
      string summary="{"+join(arr,",")+"}";
      outstr="{\n"+StrToCpp("summary")+":"+summary+",\n"+StrToCpp("detail")+":\n"+outstr+"\n}";
      dev.expr_buff.set_string(dev.Env,outstr);
      return true;
    }
    if(func=="__get_internal_funcs_count")
    {
      if(!values.empty())return false;
      auto&arr=dev.funcs;
      dev.expr_buff.set_int(dev.Env,arr.size());
      return true;
    }
    if(func=="__get_internal_func_by_id")
    {
      if(!values[0].isInt())return false;
      int&id=values[0].unsafe_get_ref_int();
      string out="";
      if(id<0||id>=dev.funcs.size()){
        dev.expr_buff.set_string(dev.Env,out);
        return true;
      }
      out=dev.funcs[id].get_head().get_code();
      dev.expr_buff.set_string(dev.Env,out);
      return true;
    }
    if(func=="__get_foo")
    {
      if(values.empty())return false;
      if(!values[0].isString())return false;
      const string&name=values[0].unsafe_get_ref_string();
      auto&arr=dev.funcs;
      string out="[false]";
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(name!=ex.get_head().get_code())continue;
        auto*p=&ex.head.info;
        QapAssert(p);
        out="[true,"+IToS(p->counter)+","+FToS(p->exec_time*1000.0)+","+FToS(p->full_time*1000.0)+"]";
        break;
      }
      dev.expr_buff.set_string(dev.Env,out);
      return true;
    }
    return false;
  }
public:
  typedef t_stat_dev::t_rtti_func t_rtti_func;
public:
  void Do(t_call_expr*p)
  {
    auto values=get_params_values(dev,p->params);
    if(dev.isErr())return;
    vector<string> params=get_types_from_values(values);
    //QapAssert(!p->next);
    t_call_visitor::t_machine machine(dev,values);
    t_call_visitor V(machine);
    auto*pcall=p->call.get();
    pcall->Use(V);
    if(dev.isErr())return;
    if(machine.value_changed){
      dev.expr_buff.value=nullptr;
    }
    if(machine.ok)return;
    if(machine.hack_call&&machine.varname.empty()){
      QapDebugMsg("WTF?");
      return;
    }
    auto&func=machine.varname;
    t_cmd_dev<t_func_stat> cmddev(values,params,func);
    {
      bool ok=cmddev.main(dev);
      if(ok)return;
    }
    t_full_stat_dev::t_find_func_retval<t_func> retval={dev.funcs,params};
    auto*ptr=retval.find_xxxx(func);
    if(ptr)
    {
      dev.push_frame();
      ptr->exec(dev,values);
      dev.pop_frame();
      if(dev.isErr())return;
      return;
    }
    t_full_stat_dev::t_find_func_retval<t_rtti_func> rtti_retval={dev.rttifuncs,params};
    auto*rtti_ptr=rtti_retval.find_xxxx(func);
    if(rtti_ptr)
    {
      dev.push_frame();
      rtti_ptr->exec(dev,values);
      dev.pop_frame();
      if(dev.isErr())return;
      return;
    }
    if(!rtti_ptr&&!ptr&&cmddev.stack.empty()&&retval.buff.empty()&&rtti_retval.buff.empty())
    {
      if(try_call_internal_routines(func,values))return;
    }
    if(!ptr)
    {
      string msg="---[usr_func_finder]---\n";
      msg+="function "+func+"("+join(params,",")+") - not found\n";
      if(!cmddev.stack.empty())
      {
        msg+="but found:\nbegin";
        auto&arr=cmddev.stack;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          string path=dev.path.toStr(ex.level);
          msg+="\n  //"+path+"\n  ";
          msg+=cmd_xxxx_join(ex.arr,"\n  ");
        }
        msg+="\nend";
      }
      msg+="\n---[rtti_func_finder]---\n";
      msg+=rtti_retval.make_xxxx(func);
      msg+="\n---[sys_func_finder]---\n";
      msg+=retval.make_xxxx(func);
      dev.drop_error(msg);
      //QapDebugMsg(msg);
    }
    int gg=1;
  }
public:
};

class t_for_next_visitor:public t_simple_stat_lex::t_for_stat::i_next_visitor{
public:
  t_full_stat_dev&dev;
  t_for_next_visitor(t_full_stat_dev&dev):dev(dev){}
public:
  template<class TYPE>
  void DoAuto(TYPE*ptr){
    t_stat_visitor V(dev);
    V.Do(&ptr->body);
  }
public:
  void Do(t_set*p){DoAuto(p);}
  void Do(t_postfix*p){DoAuto(p);}
};

class t_stat_visitor:public t_simple_stat_lex::i_stat_visitor{
public:
  typedef t_stat_visitor SelfClass;
  typedef i_stat_visitor ParentClass;
public:
  typedef t_simple_stat_lex::i_expr i_expr;
  typedef t_simple_stat_lex::t_lev14 t_lev14;
public:
  t_full_stat_dev&dev;
  t_stat_visitor(t_full_stat_dev&dev):dev(dev){}
public:
  typedef t_stat_dev::t_expr_value t_expr_value;
  t_expr_value&get_expr_value(TAutoPtr<i_expr>&ref){
    return t_expr_visitor::get_expr_value(dev,ref);
  }
  t_expr_value&get_expr_value(t_lev14&ref){
    return t_expr_visitor::get_expr_value(dev,ref);
  }
public:
  template<class t_xxxx_stat>
  class t_cmd_find_dev{
  public:
    typedef t_simple_stat_lex::t_oper_stat t_oper_stat;
    typedef t_simple_stat_lex::t_func_stat t_func_stat;
    typedef t_simple_stat_lex::t_struct_stat t_struct_stat;
  public:
    struct t_rec{
      int id;
      t_xxxx_stat*pstat;
    };
    struct t_frame{
      int level;
      vector<t_rec> arr;
    };
  public:
    string name;
    vector<t_rec> found;
    vector<t_frame> stack;
    //t_cmd_find_dev(const string&name):name(name){}
  public:
    void make_frame(int level){
      if(found.empty())return;
      t_frame tmp={level,found};
      stack.push_back(tmp);
      found.clear();
    }
  public:
    void add(int id,t_xxxx_stat*p){t_rec tmp={id,p};found.push_back(tmp);}
  public:
    static const string&get_name(t_func_stat*ptr){return ptr->body.name.value;}
    static const string&get_name(t_oper_stat*ptr){return ptr->oper;}
    static const string&get_name(t_struct_stat*ptr){return ptr->body.name.value;}
  public:
    void find(t_stat_cmds::i_cmd*p)
    {
      QapAssert(p);
      auto*ptr=t_stat_cmds::t_block_id::UberCast(p);
      if(!ptr)return;
      find(ptr);
    }
    void find(t_stat_cmds::t_block_id*p)
    {
      auto&arr=p->ptr->arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*ptr=i_stat_visitor::UberCast<t_xxxx_stat>(ex.get());
        if(!ptr)continue;
        if(get_name(ptr)!=name)continue;
        add(i,ptr);
      }
    }
  public:
    template<class t_xxxx_stat>struct conv_stat_to_body;
    template<>struct conv_stat_to_body<t_func_stat>{typedef t_stat_cmds::t_func_body type;};
    template<>struct conv_stat_to_body<t_oper_stat>{typedef t_stat_cmds::t_oper_body type;};
    template<>struct conv_stat_to_body<t_struct_stat>{typedef t_stat_cmds::t_struct_body type;};
  public:
    typedef typename conv_stat_to_body<t_xxxx_stat>::type t_stat_cmds__t_xxxx_body;
  public:
  };
public:
  struct t_var_impl_visitor:public t_var_stat::i_impl_visitor{
  public:
    typedef t_stat_visitor OwnerClass;
  public:
    t_full_stat_dev&dev;
    t_var_impl_visitor(t_full_stat_dev&dev):dev(dev){}
  public:
    typedef t_stat_dev::t_expr_value t_expr_value;
    t_expr_value&get_expr_value(TAutoPtr<i_expr>&ref){
      return t_expr_visitor::get_expr_value(dev,ref);
    }
    t_expr_value&get_expr_value(t_lev14&ref){
      return t_expr_visitor::get_expr_value(dev,ref);
    }
  public:
    bool do_var_init_by_string_v02(TAutoPtr<t_expr::i_value>&ref,const string&type)
    {
      //BEG
      #define F(TYPE)if(#TYPE==type){\
        auto*p=ref.build<t_expr::t_sys>(dev.Env);\
        p->value.build<t_expr::t_##TYPE>(dev.Env);\
        return true;\
      }
      //=>
        F(string);
        F(int);
        F(char);
        F(bool);
        F(real);
      //<=
      #undef F
      //END
      return false;
    }
  public:
    t_struct_stat*find_type_by_name_in_ast(const string&name)
    {
      t_cmd_find_dev<t_struct_stat> cfd={name};
      auto&arr=dev.path.arr;
      for(int i=0;i<arr.size();i++){
        int id=arr.size()-i-1;
        auto*ptr=arr[id];
        cfd.find(ptr);
        if(cfd.found.empty())continue;
        if(cfd.found.size()!=1){
          dev.drop_error(name+" - struct type is ambiguous.");
          return nullptr;
        }
        auto&back=cfd.found.back();
        return back.pstat;
        //cfd.make_frame(id);
      }
      dev.drop_error(name+" - struct not found.");
      return nullptr;
    }
    static string get_type_fullname(t_simple_stat_lex::t_type_expr::t_elem&elem){
      string out=elem.name.value;
      if(!elem.params)return out;
      auto&params=*elem.params.get();
      out+="{"+params.type;
      if(params.count){
        out+=","+params.count->body.value;
      }
      out+="}";
      return out;
    }
    void reg_struct(t_struct_stat*pstat){
      t_expr::t_struct_info temp;
      temp.name=pstat->body.name.value;
      auto&arr=pstat->body.fields;
      auto&fields=temp.fields;
      fields.resize(arr.size());
      for(int i=0;i<fields.size();i++){
        auto&ex=fields[i]; //t_expr::t_struct_info::t_field
        auto&src=arr[i].body;
        QapAssert(src.type.arr.empty());
        ex.name=src.name.value;
        ex.type=get_type_fullname(src.type.first);//src.type.first.name.value;
        if(!src.value)continue;
        auto*pvalue=src.value.get();
        t_expr_value buff;
        {
          t_rettype_scope scope(dev,ex.type,buff);
          get_expr_value(pvalue->value);
        }
        if(dev.isErr())return;
        ex.value=nullptr;
        ex.value=std::move(buff.value);
      }
      dev.typelist.push_back(std::move(temp));
    }
  public:
    bool do_var_init_by_string_v03(TAutoPtr<t_expr::i_value>&ref,const string&type)
    {
      auto id=dev.find_struct_id_by_name(type);
      if(id<0)
      {
        auto*pstat=find_type_by_name_in_ast(type);
        if(!pstat){
          return true;
        }
        reg_struct(pstat);
        id=dev.find_struct_id_by_name(type);
      }
      QapAssert(id>=0);
      auto*p=ref.build<t_expr::t_struct>(dev.Env);
      p->type=type;
      {
        auto&item=dev.typelist[id];
        p->arr.resize(item.fields.size());
      }
      auto&arr=p->arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&item=dev.typelist[id];
        auto&field=item.fields[i];
        if(!do_var_init_by_string_full(ex,field.type))
        {
          string msg=(
            field.type+" - field type not found.\n"
            "field:\n"+field.type+" "+field.name+"\n"
            "for struct:\n"+type
          );
          dev.drop_error(msg);
          return true;
        }
        if(dev.isErr())return true;
        if(!field.value)continue;
        ex=nullptr;
        unsafe_easy_clone(dev.Env,ex,field.value);
      }
      return true;
    }
    static bool is_array(const string&type){
      static const string arr="array";
      return type.substr(0,arr.size())==arr;
    }
    static bool is_vector(const string&type){
      static const string arr="vector";
      return type.substr(0,arr.size())==arr;
    }
    bool do_var_init_by_string_v00(TAutoPtr<t_expr::i_value>&ref,const string&type)
    {
      if(!is_array(type))return false;
      t_simple_stat_lex::t_type_expr expr;
      bool ok=load_obj(dev.Env,expr,type);
      QapAssert(ok);
      QapAssert(expr.arr.empty());
      QapAssert(expr.first.params);
      auto*pParams=expr.first.params.get();
      auto&subtype=pParams->type;
      QapAssert(pParams->count);
      auto&count=pParams->count->body.value;
      auto*pv=ref.build<t_expr::t_array>(dev.Env);
      pv->count=SToI(count);
      pv->subtype=subtype;
      if(pv->count<=0||pv->count>=1024*1024*16)
      {
        dev.drop_error("array size is wrong:\n"+count);
        return false;
      }
      {
        auto&arr=pv->arr;
        arr.resize(pv->count);
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          if(do_var_init_by_string_full(ex,subtype))continue;
          if(dev.isErr())return false;
          string msg=type+" - subtype not found.";
          dev.drop_error(msg);
          return false;
        }
      }
      return true;
    }
    bool do_var_init_by_string_v01(TAutoPtr<t_expr::i_value>&ref,const string&type)
    {
      if(!is_vector(type))return false;
      t_simple_stat_lex::t_type_expr expr;
      bool ok=load_obj(dev.Env,expr,type);
      QapAssert(ok);
      QapAssert(expr.arr.empty());
      QapAssert(expr.first.params);
      auto*pParams=expr.first.params.get();
      auto&subtype=pParams->type;
      auto*pv=ref.build<t_expr::t_vector>(dev.Env);
      pv->subtype=subtype;
      return true;
    }
    bool do_var_init_by_string_full(TAutoPtr<t_expr::i_value>&ref,const string&type)
    {
      if(do_var_init_by_string_v00(ref,type))return true;
      if(do_var_init_by_string_v01(ref,type))return true;
      if(do_var_init_by_string_v02(ref,type))return true;
      if(do_var_init_by_string_v03(ref,type))return true;
      return false;
    }
  public:
    typedef t_simple_stat_lex::t_type_expr t_type_expr;
  public:
    bool try_init_array(t_type_impl*p)
    {
      auto&first=p->type.first;
      if(first.name.value!="array")return false;
      if(!p->type.arr.empty())
      {
        auto msg=(
          "nesteds types not supported for template:\n"+first.name.value
        );
        dev.drop_error(msg);
        return true;
      }
      auto*pParams=first.params.get();
      auto&subtype=pParams->type;
      if(!pParams->count)
      {
        auto msg=(
          "need set count for template:\n"+first.name.value
        );
        dev.drop_error(msg);
        return true;
      }
      auto&count=pParams->count->body.value;
      //array{subtype,count}
      auto&ref=dev.add_var(p->name.value);
      QapAssert(!p->value);
      auto&value=ref.value.value;
      auto*pv=value.build<t_expr::t_array>(dev.Env);
      pv->count=SToI(count);
      pv->subtype=subtype;
      {
        auto&arr=pv->arr;
        arr.resize(pv->count);
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          if(do_var_init_by_string_full(ex,subtype))continue;
          string msg=(
            subtype+" - type not found.\n"
            "about var_stat:\narray{"+subtype+","+count+"} "+ref.name+";"
          );
          dev.drop_error(msg);
          return true;
        }
      }
      int gg=1;
      return true;
    }
    bool try_init_vector(t_type_impl*p)
    {
      auto&first=p->type.first;
      if(first.name.value!="vector")return false;
      if(!p->type.arr.empty())
      {
        auto msg=(
          "nesteds types not supported for template:\n"+first.name.value
        );
        dev.drop_error(msg);
        return true;
      }
      auto*pParams=first.params.get();
      auto&subtype=pParams->type;
      if(pParams->count)
      {
        auto msg=(
          "no need set count for template:\n"+first.name.value
        );
        dev.drop_error(msg);
        return true;
      }
      //vector{subtype}
      auto&ref=dev.add_var(p->name.value);
      QapAssert(!p->value);
      auto&value=ref.value.value;
      auto*pv=value.build<t_expr::t_vector>(dev.Env);
      pv->subtype=subtype;
      int gg=1;
      return true;
    }
    bool try_init_templtype_var(t_type_impl*p)
    {
      auto&first=p->type.first;
      if(!first.params)return false;
      if(try_init_array(p))return true;
      if(try_init_vector(p))return true;
      if(true)
      {
        auto msg=first.name.value+" - unknow template";
        dev.drop_error(msg);
        return true;
      }
      int gg=1;
      return true;
    }
    bool try_init_no_templtype_var(t_type_impl*p)
    {
      auto&first=p->type.first;
      if(first.params)return false;
      QapAssert(p->type.arr.empty());
      QapAssert(!p->type.first.params);
      auto type=p->type.first.name.value;
      auto name=p->name.value;
      auto&ref=dev.add_var(name);
      if(!p->value)
      {
        auto&value=ref.value.value;
        if(do_var_init_by_string_full(value,type))return true;
        string msg=(
          type+" - type not found.\n"
          "about var_stat:\n"+type+" "+ref.name+";"
        );
        dev.drop_error(msg);
        return true;
      }
      auto*pValue=p->value.get();
      {
        {
          t_rettype_scope scope(dev,type,ref.value);
          get_expr_value(pValue->value);
        }
        if(dev.isErr())return true;
      }
      int gg=1;
      return true;
    }
  public:
    void Do(t_type_impl*p)
    {
      if(try_init_templtype_var(p))return;
      if(try_init_no_templtype_var(p))return;
      int gg=1;
    }
    void Do(t_auto_impl*p)
    {
      if(!p->value){
        string msg="variable is not initialized:\n auto "+p->name.get();
        dev.drop_error(msg);
        return;
      }
      auto*pValue=p->value.get();
      {
        auto&value=get_expr_value(pValue->value);
        if(dev.isErr())return;
        auto name=p->name.get();
        dev.add_var(name).value=std::move(value);
        dev.expr_buff.value=nullptr;
      }
    }
  };
public:
  void DoAuto(TAutoPtr<t_var_stat::i_impl>&ref){
    QapAssert(ref);
    t_var_impl_visitor V(dev);
    auto*p=ref.get();
    p->Use(V);
  }
public:
  void Do(t_var_stat::t_impl*p){
    DoAuto(p->impl);
  }
  void Do(t_var_stat*p){
    Do(&p->body);
  }
  void Do(t_struct_stat*p){
    return;
  }
  void Do(t_null_stat*p){return;}
  void Do(t_sep_stat*p){return;}
public:
  typedef t_simple_stat_lex::t_command_block t_command_block;
  void Do(t_command_block*p){
    dev.push();
    auto&arr=p->arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*ptr=ex.get();
      {
        t_stat_cmds::t_block_id scope(dev,p,i);
        ptr->Use(*this);
      }
      if(dev.isRet())return;
      if(dev.isCon()||dev.isBre()){
        break;return;
      }
    }
    dev.pop();
  }
public:
  void Do(t_block_stat*p){
    Do(&p->body);
  }
  void Do(t_ret_stat*p){
    auto&value=get_expr_value(p->body);
    if(dev.isErr())return;
    dev.ret(value);
  }
  void Do(t_func_stat::t_impl*p){
    return;
  }
  void Do(t_func_stat*p){
    return;
  }
  void Do(t_oper_stat*p){
    return;
  }
  void Do(t_template_stat*p){
    return;
  }
  void Do(t_expr_stat*p){
    auto&value=get_expr_value(p->body);
    value.value=nullptr;
    int gg=1;
  }
  void Do(t_break_stat*p){
    dev.bre();
    int gg=1;
  }
  void Do(t_continue_stat*p){
    dev.con();
    int gg=1;
  }
public:
  void update(TAutoPtr<t_for_stat::i_next>&next)
  {
    t_for_next_visitor V(dev);
    next->Use(V);
  }
public:
  typedef t_simple_stat_lex::i_stat i_stat;
  void Do(TAutoPtr<i_stat>*p){
    auto*ptr=p->get();
    ptr->Use(*this);
  }
public:
  void Do(t_for_stat*p){
    dev.push();
    if(p->init){
      auto*pInit=p->init.get();
      Do(pInit);
    }
    for(;;){
      t_expr_value cond;
      if(p->cond)
      {
        auto*pCond=p->cond.get();
        {
          {
            t_rettype_scope scope(dev,"bool",cond);
            auto&value=get_expr_value(*pCond);
          }
          if(dev.isErr())return;
        }
        bool flag=cond.unsafe_get_ref_bool();
        if(!flag)break;
      }
      {
        t_stat_cmds::t_for_body scope(dev,p);
        Do(&p->body);
      }
      if(dev.isRet()){
        return;
      }
      if(dev.isCon()){
        auto&v=dev.state.value;
        QapAssert('C'==v);
        v='N';
      }
      if(dev.isBre()){
        auto&v=dev.state.value;
        QapAssert('B'==v);
        v='N';
        break;
      }
      if(!p->next)continue;
      auto*pNext=p->next.get();
      update(pNext->body);
    }
    int gg=1;
    dev.pop();
  }
public:
  void Do(t_if_stat*p){
    t_expr_value cond;
    {
      {
        t_rettype_scope scope(dev,"bool",cond);
        auto&value=get_expr_value(p->cond);
      }
      if(dev.isErr())return;
    }
    bool flag=cond.unsafe_get_ref_bool();
    if(flag)
    {
      t_stat_cmds::t_if_bef scope(dev,p);
      Do(&p->bef);
    }else if(p->aft)
    {
      t_stat_cmds::t_if_aft scope(dev,p);
      Do(&p->aft.get()->body);
    }
    int gg=1;
  }
public:
  void Do(t_postfix_oper_stat*p){
    Do(&p->body);
  }
  void Do(t_set_oper_stat*p){
    Do(&p->body);
  }
public:
  typedef t_simple_stat_lex::t_postfix_oper t_postfix_oper;
  typedef t_simple_stat_lex::t_set_oper t_set_oper;
public:
  typedef t_full_stat_dev::t_rettype_scope t_rettype_scope;
public:
  void Do(t_postfix_oper*p){
    QapAssert(!p->var.arr.empty());
    auto&front=p->var.arr.front();
    auto&varname=front.name.value;
    auto*pvar=dev.safe_find_pvar(varname);
    if(!pvar)return;
    auto&var=*pvar;
    t_expr_value var_value;
    var_value.set(dev,var.value);
    t_expr_value formal;
    formal.set_int(dev.Env,0);
    /*see t_set_oper*p */if(dev.isErr())return;
    /*see t_set_oper*p */{
    /*see t_set_oper*p */  typedef t_full_stat_dev::t_var_field_tool t_tool;
    /*see t_set_oper*p */  t_tool tool={dev,var_value.value};
    /*see t_set_oper*p */  tool.load_path(p->var.arr);
    /*see t_set_oper*p */  if(dev.isErr())return;
    /*see t_set_oper*p */  tool.bef();
    /*see t_set_oper*p */  if(dev.isErr())return;
    /*see t_set_oper*p */  {
    /*see t_set_oper*p */    string rettype=var_value.gettype();
    /*see t_set_oper*p */    t_expr_visitor V(dev);
    /*see t_set_oper*p */    {
    /*see t_set_oper*p */      {
    /*see t_set_oper*p */        t_rettype_scope scope(dev,rettype,var_value);
    /*see t_set_oper*p */        V.call_binoper(p->oper,std::move(var_value),std::move(formal));
    /*see t_set_oper*p */      }
    /*see t_set_oper*p */      if(dev.isErr())return;
    /*see t_set_oper*p */    }
    /*see t_set_oper*p */    int gg=1;
    /*see t_set_oper*p */  }
    /*see t_set_oper*p */  tool.aft();
    /*see t_set_oper*p */  if(dev.isErr())return;
    /*see t_set_oper*p */  var.value=std::move(var_value);
    /*see t_set_oper*p */  return;
    /*see t_set_oper*p */}
    /*see t_set_oper*p */QapDebugMsg("no impl");
  }
  void Do(t_set_oper*p)
  {
    QapAssert(!p->var.arr.empty());
    auto&front=p->var.arr.front();
    auto&varname=front.name.value;
    auto*pvar=dev.safe_find_pvar(varname);
    if(!pvar)return;
    auto&var=*pvar;
    t_expr_value var_value;
    var_value.set(dev,var.value);
    t_expr_value value=std::move(get_expr_value(p->expr));
    if(dev.isErr())return;
    //if(!p->var.arr.empty())
    {
      typedef t_full_stat_dev::t_var_field_tool t_tool;
      t_tool tool={dev,var_value.value};
      tool.load_path(p->var.arr);
      if(dev.isErr())return;
      tool.bef();
      if(dev.isErr())return;
      {
        string rettype=var_value.gettype();
        t_expr_visitor V(dev);
        {
          {
            t_rettype_scope scope(dev,rettype,var_value);
            V.call_binoper(p->oper,std::move(var_value),std::move(value));
          }
          if(dev.isErr())return;
        }
        int gg=1;
      }
      tool.aft();
      if(dev.isErr())return;
      var.value=std::move(var_value);
      return;
    }
    QapDebugMsg("no impl");
  }
public:
};

class t_qap_eval_block:public i_eval_block{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_qap_eval_block)PARENT(i_eval_block)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_simple_stat_lex::t_block_stat,block,DEF,$,$)\
ADDEND()
//=====+>>>>>t_qap_eval_block
#include "QapGenStruct.inl"
//<<<<<+=====t_qap_eval_block
public:
  void block_clear()
  {
    block.body.arr.clear();
  }
  void block_compile(IEnvRTTI&Env)
  {
    QapClock clock;
    clock.Start();
    this->load_status=load_obj_ex(Env,this->block,this->code);
    this->load_time=clock.MS();
  }
public:
  typedef t_stat_dev::t_expr_value t_expr_value;
public:
  void block_run(IEnvRTTI&Env)
  {
    real k=1000.0;
    QapClock clock;
    clock.Start();
    t_full_stat_dev dev(Env);
    real time_init=clock.MS();
    dev.stack.reserve(4096);
    real time_reserve=clock.MS();
    dev.push();
    dev.add_var("POST_CODE").value.set_string(Env,this->code);
    dev.add_var("POST_DATA").value.set_string(Env,this->inp);
    real time_adds=clock.MS();
    dev.add_var("POST_TIME").value.set_string
    (
      Env,
      #define F(var)#var" = "+FToS(time_##var*k)+"\n"
      F(init)
      F(reserve)
      F(adds)
      #undef F
    );
    dev.push();
    t_expr_value result;
    t_stat_visitor V(dev);
    {
      t_stat_visitor::t_rettype_scope scope(dev,"string",result);
      block.Use(V);
      if(dev.isErr()){
        this->errcode=dev.errcode;
        this->retpath=dev.retpath;
        this->exec_time=clock.MS()-this->load_time;
        return;
      }
    }
    dev.pop();
    dev.pop();
    this->exec_time=clock.MS();
    auto ok=result.get_string(this->out);
    if(!ok)QapDebugMsg("return value is non-string.");
    this->full_time=clock.MS()+this->load_time;
  }
};

extern i_eval_block*make_t_qap_eval_block(IEnvRTTI&Env,TAutoPtr<i_eval_block>&out){
  return out.build<t_qap_eval_block>(Env);
}

extern bool qap_eval_string(IEnvRTTI&Env,t_qap_eval_string&ref);
extern bool qap_no_eval_string(IEnvRTTI&Env,t_qap_eval_string&ref);

bool qap_no_eval_string(IEnvRTTI&Env,t_qap_eval_string&ref){
  QapClock clock;
  clock.Start();
  t_simple_stat_lex::t_block_stat block;
  ref.load_status=load_obj_ex(Env,block,ref.code);
  ref.load_time=clock.MS();
  ref.out=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(block));
  ref.exec_time=clock.MS()-ref.load_time;
  if(ref.load_status.find("true")>16)return false;
  return true;
}

bool qap_eval_string(IEnvRTTI&Env,t_qap_eval_string&ref){
  QapClock clock;
  clock.Start();
  t_simple_stat_lex::t_block_stat block;
  ref.load_status=load_obj_ex(Env,block,ref.code);
  ref.load_time=clock.MS();
  if(ref.load_status.find("true")>16)return false;
  t_full_stat_dev dev(Env);
  dev.stack.reserve(2048);
  dev.push();
  typedef t_stat_dev::t_expr_value t_expr_value;
  t_expr_value result;
  t_stat_visitor V(dev);
  {
    t_stat_visitor::t_rettype_scope scope(dev,"string",result);
    block.Use(V);
    if(dev.isErr()){
      ref.errcode=dev.errcode;
      ref.retpath=dev.retpath;
      ref.exec_time=clock.MS()-ref.load_time;
      return false;
    }
  }
  dev.pop();
  ref.exec_time=clock.MS()-ref.load_time;
  auto ok=result.get_string(ref.out);
  ref.full_time=clock.MS();
  return ok;
}

void UberInfoBox(const string&caption,const string&text);

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
      QapLexerRegAll(Env);
      RegAllCppLex(Env);
    }
    void Run(IEnvRTTI&Env)
    {
      //return;
      //QapClock clock;clock.Start();
      //t_simple_stat_lex::t_block_stat block;
      //string code=file_get_contents("qapscript.h");
      //string load_status=load_obj_ex(Env,block,code);
      //if(load_status.find("true")>16){
      //  int fail=1;
      //  QapDebugMsg(load_status);
      //}
      //real load_time=clock.MS();
      //t_full_stat_dev dev(Env);
      //t_stat_visitor V(dev);
      //dev.rettype="string";
      //dev.stack.reserve(2048);
      //dev.stack.push_back(t_full_stat_dev::t_context());
      //block.Use(V);
      //clock.Stop();
      //if(dev.isErr()){
      //  UberInfoBox("errcode",dev.errcode);
      //}
      //string out;
      //auto ok=dev.expr_buff.get_string(out);
      //out=(
      //  "--------------------\n"
      //  "load_time = "+FToS(load_time)+" ms.\n"
      //  "exec_time = "+FToS(clock.MS())+" ms.\n"
      //  "--------------------\n\n"+out
      //);
      //UberInfoBox("Output",out);
      //return;
      ////int counter=get_QapClone_counter();
      ////real clone_time=QapClone_timer();
      ////real cost_per_call=clone_time/counter;
      ////string msg="clone_time = "+FToS(clone_time)+"\ncost_per_call = "+FToS(cost_per_call)+"\ntotal_time = "+FToS(clock.MS());
      //////file_put_contents("some_msg.txt",msg);
      ////UberInfoBox("TimeInfo",msg);
      ////int gg=1;
    }
    ThisCompileUnit(){
      
    }
  };
  ThisCompileUnit ThisUnit;
}
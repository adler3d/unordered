class t_struct_field{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_field)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,type,DEF,$,$)\
ADDVAR(1,name,name,DEF,$,$)\
ADDVAR(2,value,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_field
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_field
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("  ");
    if(!ok)return ok;
    M+=dev.go_end(type," ");
    if(!ok)return ok;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    O+=dev.go_const("=");
    if(!ok)return ok;
    M+=dev.go_end(value,";\n");
    if(!ok)return ok;
    return ok;
  }
};

class t_struct_cmd_mode{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_mode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,char,body,SET,'\x00',$)\
ADDEND()
//=====+>>>>>t_struct_cmd_mode
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_cmd_mode
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_any_char(body,"MO");
    if(!ok)return ok;
    M+=dev.go_const("+=");
    if(!ok)return ok;
    return ok;
  }
};

class t_struct_cmd{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TAutoPtr<t_struct_cmd_mode>,mode,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_cmd
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_cmd
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("    ");
    if(!ok)return ok;
    O+=dev.go_auto(mode);
    if(!ok)return ok;
    M+=dev.go_auto(code);
    if(!ok)return ok;
    M+=dev.go_end(code,";\n");
    if(!ok)return ok;
    return ok;
  }
};

class t_struct_body{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_body)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<t_struct_field>,arr,DEF,$,$)\
ADDVAR(1,vector<t_struct_cmd>,cmds,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_body
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_body
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("{\n");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("  {\n");
    if(!ok)return ok;
    M+=dev.go_auto(cmds);
    if(!ok)return ok;
    M+=dev.go_const("  }\n}");
    if(!ok)return ok;
    return ok;
  }
};

class i_def{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_def)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_def
#include "QapGenStruct.inl"
//<<<<<+=====i_def
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  template<class i_dev>
  static bool weak_go_for_poly_lt(i_dev&dev,TAutoPtr<SelfClass>&ref){
    t_fallback scope(dev,__FUNCTION__);
    bool&ok=scope.ok;
    #define F(TYPE)ok=go_for_class<TYPE>(dev,ref);if(ok)return ok;
    F(t_class_def);
    F(t_struct_def);
    #undef F
    return ok;
  }
  template<class i_dev>
  static bool weak_go_for_poly_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
    t_fallback scope(dev,__FUNCTION__);
    bool&ok=scope.ok;
    QapAssert(ref);
    auto*p=ref.get();
    ok=p->go(dev);
    return ok;
  }
};

class t_class_def:public i_def{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_def)PARENT(i_def)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_name,name,DEF,$,$)\
ADDVAR(1,t_name,parent,DEF,$,$)\
ADDVAR(2,t_struct_body,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_class_def
#include "QapGenStruct.inl"
//<<<<<+=====t_class_def
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    if(!ok)return ok;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    M+=dev.go_const("=>");
    if(!ok)return ok;
    M+=dev.go_auto(parent);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};

class t_struct_def:public i_def{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_def)PARENT(i_def)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_name,name,DEF,$,$)\
ADDVAR(1,t_struct_body,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_def
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_def
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};

class t_target_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,sep,DEF,$,$)\
ADDVAR(1,TAutoPtr<i_def>,def,DEF,$,$)\
ADDVAR(2,t_struct_body,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_target_item
#include "QapGenStruct.inl"
//<<<<<+=====t_target_item
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_any(sep," \n");
    if(!ok)return ok;
    M+=dev.go_auto(def);
    if(!ok)return ok;
    return ok;
  }
};
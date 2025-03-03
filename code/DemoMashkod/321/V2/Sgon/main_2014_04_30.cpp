#include "StdAfx.h"
#include <utility>/*
#include "Gateway.h"
#include "Gateway.cpp"*/

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_01_11.h"
#else
//=====>>>>>main_2013_01_11
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
//#include "t_simple_stat_lex.inl"
//<<<<<=====main_2013_01_11
#endif //DEF_BUILD_MACRO//

void UberInfoBox(const string&caption,const string&text);

#include "Lexem\t_opt_test.inl"

class t_opt_test_machine:public t_opt_test_lex_scope{
public:
  class t_version{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_version)OWNER(t_opt_test_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,var,DEF,$,$)\
  ADDVAR(1,int,id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_version
  #include "QapGenStruct.inl"
  //<<<<<+=====t_version
  };
  class t_ver_info{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ver_info)OWNER(t_opt_test_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,int,mov_id,DEF,$,$)\
  ADDVAR(1,vector<t_version>,depends,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cmd_info
  #include "QapGenStruct.inl"
  //<<<<<+=====t_cmd_info
  };
  class t_var{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)OWNER(t_opt_test_machine)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,name,DEF,$,$)\
  ADDVAR(1,string,type,DEF,$,$)\
  ADDVAR(2,vector<t_ver_info>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var
  };
public:
#define DEF_PRO_NESTED(F)F(t_version)F(t_var)F(t_ver_info)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_opt_test_machine)PARENT(t_opt_test_lex_scope)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_program,scope,DEF,$,$)\
ADDVAR(1,vector<t_var>,vars,DEF,$,$)\
ADDVAR(2,vector<int>,useds,DEF,$,$)\
ADDVAR(3,int,mov_id,DEF,$,$)\
ADDEND()
//=====+>>>>>t_opt_test_machine
#include "QapGenStruct.inl"
//<<<<<+=====t_opt_test_machine
public:
  void add_var_value(const string&var,vector<t_version>&arr)
  {
    t_ver_info info;
    info.mov_id=mov_id;
    info.depends=std::move(arr);
    for(int i=0;i<vars.size();i++)
    {
      if(var!=vars[i].name)continue;
      vars[i].arr.push_back(std::move(info));
      return;
    }
    t_var v;
    v.name=var;
    v.arr.push_back(std::move(info));
    vars.push_back(std::move(v));
    //QapDebugMsg("wtf?");
  }
  t_version get_var_version(const string&var)
  {
    t_version tmp;
    tmp.var=var;
    tmp.id=0;
    for(int i=0;i<vars.size();i++)
    {
      if(var!=vars[i].name)continue;
      tmp.id=vars[i].arr.size()-1;
      return tmp;
    }
    t_var v;
    v.name=var;
    t_ver_info empty;
    empty.mov_id=-1;
    v.arr.push_back(std::move(empty));
    vars.push_back(std::move(v));
    return std::move(tmp);
  }
  t_var&get_var(const string&var)
  {
    for(int i=0;i<vars.size();i++)
    {
      if(var!=vars[i].name)continue;
      return vars[i];
    }
    return *(t_var*)nullptr;
  }
public:
  void Do(t_mov&ref)
  {
    auto&arr=ref.arr;
    vector<t_version> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto v=std::move(get_var_version(ex.value));
      out.push_back(std::move(v));
    }
    add_var_value(ref.bef,out);
  }
  void Do(vector<t_mov>&arr)
  {
    mov_id=0;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      Do(ex);
      mov_id++;
    }
  }
  void Do(t_program&ref)
  {
    useds.resize(ref.arr.size());
    Do(ref.arr);
    auto ver=get_var_version(ref.ret.var);
    t_depends_solver ds={*this};
    ds.stack.push_back(std::move(ver));
    ds.main();
    int gg=1;
  }
public:
  struct t_depends_solver
  {
    t_opt_test_machine&dev;
    vector<t_version> stack;
    void add_depends_from(t_version&ver)
    {
      auto&info=dev.get_var(ver.var).arr[ver.id];
      if(info.mov_id<0)return;
      dev.useds[info.mov_id]++;
      auto&arr=info.depends;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        t_version v;
        v.id=ex.id;
        v.var=ex.var;
        stack.push_back(std::move(v));
      }
    }
    void step()
    {
      vector<t_version> arr=std::move(stack);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        add_depends_from(ex);
      }
    }
    void main()
    {
      for(;;)
      {
        if(stack.empty())break;
        step();
      }
    }
  };
};

class t_opt_test_funcs{
public:
#define DEF_PRO_NESTED(F)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_opt_test_funcs)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_opt_test_funcs
#include "QapGenStruct.inl"
//<<<<<+=====t_opt_test_funcs
public:
};

void test_2014_04_30(IEnvRTTI&Env)
{
  t_opt_test_machine machine;
  t_opt_test_lex_scope::t_program&app=machine.scope;
  string code=file_get_contents("t_opt_test_code.h");
  code=StrReplace(code,"\r","");
  string load_status=load_obj_ex(Env,app,code);
  machine.Do(app);
  UberInfoBox("test_2014_04_30::result",load_status+"\n"+QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(machine)));
  int gg=1;
  //UberInfoBox("act.out",act.out);
}

#include "Lexem/t_xml_lexem.inl"

void test_2014_05_07(IEnvRTTI&Env)
{
  t_xml_scope::t_content content;
  string code=file_get_contents("xml_test.xml");
  code=StrReplace(code,"\r","");
  string load_status=load_obj_ex(Env,content,code);
  UberInfoBox("test_2014_05_07::result",load_status+"\n"+QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(content)));
  int gg=1;
}

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
        F(TType)F(t_opt_test_funcs)F(t_xml_scope)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      //test_2014_04_30(Env);
      //test_2014_05_07(Env);
    }
    ThisCompileUnit(){
      int i=0;
      i>>=1;
      i<<=1;
      int gg=1+i;   
    }
  };
  ThisCompileUnit ThisUnit;
}
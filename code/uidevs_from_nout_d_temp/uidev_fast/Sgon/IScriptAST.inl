#pragma once
class IScriptAST{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IScriptAST)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IScriptAST
#include "QapGenStruct.inl"
//<<<<<+=====IScriptAST
public:
  typedef IBookPage::t_context t_context;
public:
  struct t_exec_result{
    bool ok=false;
    string msg;
  };
  virtual bool check_source(const string&source){return false;}
  virtual t_exec_result exec(t_context&con,vector<t_branch_head_ptr>&ptrs){QapNoWay();return *(t_exec_result*)nullptr;}
};

void build_branch_script_ast(IEnvRTTI&Env,TAutoPtr<IScriptAST>&out,const string&code);
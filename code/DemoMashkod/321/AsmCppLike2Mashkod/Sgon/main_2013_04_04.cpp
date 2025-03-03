//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//

class TReloadCounterProgram:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TReloadCounterProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TReloadDetector,detector,DEF,$,$)\
ADDVAR(1,int,counter,SET,0,$)\
ADDEND()
//=====+>>>>>TReloadCounterProgram
#include "QapGenStruct.inl"
//<<<<<+=====TReloadCounterProgram
public:
  void Update(IEnv&Env)
  {
    detector.Update();
    if(detector.needinit)
    {
      detector.Init();
      counter++;
    }
  }
};

class TMeUnit20130404:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMeUnit20130404)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TAutoPtr<ISubProgram>,Content,DEF,$,$)\
ADDEND()
//=====+>>>>>TMeUnit20130404
#include "QapGenStruct.inl"
//<<<<<+=====TMeUnit20130404
public:
  void OnBuild(TBuildContext&Context)
  {
    auto*pNode=Content.build<TProgramNode>(Context.Env);
    pNode->AddItem<TReloadCounterProgram>(Context.Env);
  }
  void Update(IEnvRTTI&Env)
  {
    ISubProgram::IEnv env={Env};
    if(Content)Content->Update(env);
  }
};

class QapItem_v001{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapItem_v001)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>QapItem_v001
#include "QapGenStruct.inl"
//<<<<<+=====QapItem_v001
public:
};

class QapItem_v001_string:public QapItem_v001{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapItem_v001_string)PARENT(QapItem_v001)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>QapItem_v001_string
#include "QapGenStruct.inl"
//<<<<<+=====QapItem_v001_string
public:
};

class QapItem_v001_int:public QapItem_v001{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapItem_v001_int)PARENT(QapItem_v001)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,value,SET,0,$)\
ADDEND()
//=====+>>>>>QapItem_v001_int
#include "QapGenStruct.inl"
//<<<<<+=====QapItem_v001_int
public:
};

class QapItem_v001_string_int:public QapItem_v001{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapItem_v001_string_int)PARENT(QapItem_v001)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,value_a,DEF,$,$)\
ADDVAR(1,int,value_b,SET,0,$)\
ADDEND()
//=====+>>>>>QapItem_v001_string_int
#include "QapGenStruct.inl"
//<<<<<+=====QapItem_v001_string_int
public:
};

class QapItem_v001_linked:public QapItem_v001{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapItem_v001_linked)PARENT(QapItem_v001)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<SelfClass>,Other,DEF,$,$)\
ADDVAR(2,string,name,DEF,$,$)\
ADDEND()
//=====+>>>>>QapItem_v001_linked
#include "QapGenStruct.inl"
//<<<<<+=====QapItem_v001_linked
public:
};

class QapNode_v001{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapNode_v001)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<QapNode_v001>,Items,DEF,$,$)\
ADDVAR(1,string,Caption,DEF,$,$)\
ADDVAR(2,TAutoPtr<QapItem_v001>,Content,DEF,$,$)\
ADDEND()
//=====+>>>>>QapNode_v001
#include "QapGenStruct.inl"
//<<<<<+=====QapNode_v001
public:
};

class TQapNodeProgram_v001:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TQapNodeProgram_v001)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,QapNode_v001,Root,DEF,$,$)\
ADDEND()
//=====+>>>>>TQapNodeProgram_v001
#include "QapGenStruct.inl"
//<<<<<+=====TQapNodeProgram_v001
public:
  static void SysHasSelf();
public:
  void Update(IEnv&Env)
  {
  }
};

extern void RunExternFunc_2013_04_06(IEnvRTTI&Env,void*pValue,TType*pType);

class TProgramFor20130406:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramFor20130406)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,bool,flag,SET,false,$)\
ADDVAR(1,TAutoPtr<ISubProgram>,SubProgram,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramFor20130406
#include "QapGenStruct.inl"
//<<<<<+=====TProgramFor20130406
public:
  void Update(IEnv&Env)
  {
    if(!SubProgram)return;
    if(!flag)return;flag=false;
    auto*pSubProgram=SubProgram.get();
    auto*pType=SubProgram.Product.GetType();
    RunExternFunc_2013_04_06(Env.Env,pSubProgram,pType);
  }
};

#include "qap_text_selector.inl"
#include "QapTypeSelector.inl"

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
        F(TType)F(TReloadCounterProgram)F(TMeUnit20130404)F(TQapNodeProgram_v001)\
        F(QapItem_v001_string_int)\
        F(QapItem_v001_int)\
        F(QapItem_v001_string)\
        F(QapItem_v001_linked)\
        F(TProgramFor20130406)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){
      
    }
  };
  ThisCompileUnit ThisUnit;
}
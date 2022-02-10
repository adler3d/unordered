#include "StdAfx.h"

namespace dev_space_plain{
  #include "plain_dev_unit.h"
};

namespace dev_space_json{
  #include "json_dev_unit.h"
};

namespace
{
  class TSpaceItem{
  public:
    int id;
    string str_type;
    TServerPtr<IEsoteric>*ptr;
    TType*type;
    void init()
    {
      id=-1;
      str_type="";
      ptr=nullptr;
      type=nullptr;
    }
  };
  class TSpace{
  public:
    std::vector<TSpaceItem> arr;
    std::map<void*,int> ptr2id;
    bool CheckServSaveID(void*ptr){
      return ptr2id.count(ptr);
    }
    void UnsafeAdd(void*ptr,TType*type){
      ptr2id[ptr]=arr.size();
      TSpaceItem tmp;
      tmp.init();
      tmp.id=arr.size();
      tmp.str_type=type->GetFullName();
      tmp.ptr=(TServerPtr<IEsoteric>*)ptr;
      tmp.type=type;
      arr.push_back(tmp);
    }
  };
  class TServerPtrGraber:public TSmartPtrVisitor::ICallBack{
  public:
    TSpace&Space;
    TServerPtrGraber(TSpace&Space):Space(Space){}
  public:
    void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
    {
      if(Space.CheckServSaveID(&Serv))
      {
        QapDebugMsg("the way used?");
        auto&ex=Space.ptr2id[&Serv];
      }
      Space.UnsafeAdd(&Serv,elemType);
    }
    void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
    void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
    void Visit(TClientPtr<IEsoteric>&A){}
    void Visit(THardClientPtr<IEsoteric>&A){}
  };

  void PrivateCode(IEnvRTTI&Env,void*pValue,TType*pType)
  {
    TSpace Space;
    TServerPtrGraber CB(Space);
    TSmartPtrVisitor SPV(CB,pValue);
    pType->Use(SPV);
    int gg=1;
  }
}

namespace{
  class QapItem{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapItem)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,caption,DEF,$,$)\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>QapItem
  #include "QapGenStruct.inl"
  //<<<<<+=====QapItem
  public:
  };
  class Foo{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Foo)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<QapItem>,Item,DEF,$,$)\
  ADDVAR(int,x,SET,0,$)\
  ADDVAR(int,y,SET,0,$)\
  ADDEND()
  //=====+>>>>>Foo
  #include "QapGenStruct.inl"
  //<<<<<+=====Foo
  public:
  };
};

class T20130406_New:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130406_New)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(Foo,foo,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130406_New
#include "QapGenStruct.inl"
//<<<<<+=====T20130406_New
public:
  void Update(IEnv&Env)
  {
    //TFieldPtr fp;
    //fp.
  }
};

class TTargetForPtr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTargetForPtr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,x,DEF,$,$)\
ADDVAR(string,y,DEF,$,$)\
ADDEND()
//=====+>>>>>TTargetForPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTargetForPtr
public:
  static void SysHasSelf();
public:
};

class IUniPtrHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IUniPtrHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IUniPtrHolder
#include "QapGenStruct.inl"
//<<<<<+=====IUniPtrHolder
public:
  virtual void*getValue(){return nullptr;}
};

struct T20130406_Debuger{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130406_Debuger)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IUniPtrHolder>,Holder,DEF,$,$)\
ADDVAR(string,str_type_fn,DEF,$,$)\
ADDVAR(string,str_type_raw,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130406_Debuger
#include "QapGenStruct.inl"
//<<<<<+=====T20130406_Debuger
public:
  static string find_weakptr_field(TType*pType,const string&field)
  {
    auto*pStruct=TTypeStruct::UberCast(pType);
    if(!pStruct)return "nullptr";
    auto&arr=pStruct->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.Name!=field)continue;
      auto*field_type=ex.Type.get();
      auto*p=TTypeWeakPtr::UberCast(field_type);
      if(!p)return "field_type_is_not_weakptr";
      return p->ElementType->GetFullName();
    }
    return "field_not_found";
  }
  void update()
  {
    if(!Holder)return;
    auto*pType=Holder.Product.pType.get();
    str_type_fn=pType->GetFullName();
    str_type_raw=find_weakptr_field(pType,"Value");
  }
};
/*
template<class TYPE>
class TUnitPtr:public IUniPtrHolder{
public:
#define DEF_PRO_TEMPLATE_INFO(NAME,PARAM,PARENT,OWNER)NAME(TUnitPtr)PARAM(TYPE)PARENT(IUniPtrHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TYPE>,Value,DEF,$,$)\
ADDEND()
//=====+>>>>>TUnitPtr
#include "QapGenStruct.inl"
//<<<<<+=====TUnitPtr
public:
  void*getValue(){
    return Value.get();
  }
};*/

class TUnitPtr_To_TTargetForPtr:public IUniPtrHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUnitPtr_To_TTargetForPtr)PARENT(IUniPtrHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TTargetForPtr>,Value,DEF,$,$)\
ADDEND()
//=====+>>>>>TUnitPtr_To_TTargetForPtr
#include "QapGenStruct.inl"
//<<<<<+=====TUnitPtr_To_TTargetForPtr
public:
  void*getValue(){
    return Value.get();
  }
};

class TUnitPtr_To_ISubProgram:public IUniPtrHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUnitPtr_To_ISubProgram)PARENT(IUniPtrHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<ISubProgram>,Value,DEF,$,$)\
ADDEND()
//=====+>>>>>TUnitPtr_To_ISubProgram
#include "QapGenStruct.inl"
//<<<<<+=====TUnitPtr_To_ISubProgram
public:
  void*getValue(){
    return Value.get();
  }
};

class TUnitPtr_To_Troll:public IUniPtrHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUnitPtr_To_Troll)PARENT(IUniPtrHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,Value,SET,0,$)\
ADDEND()
//=====+>>>>>TUnitPtr_To_ISubProgram
#include "QapGenStruct.inl"
//<<<<<+=====TUnitPtr_To_ISubProgram
public:
};

class TUnitPtr_Test:public IUniPtrHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUnitPtr_Test)PARENT(IUniPtrHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TVoidPtr,vptr,DEF,$,$)\
ADDEND()
//=====+>>>>>TUnitPtr_Test
#include "QapGenStruct.inl"
//<<<<<+=====TUnitPtr_Test
public:
};

class T20130406_New2:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130406_New2)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(T20130406_Debuger,debugger,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130406_New2
#include "QapGenStruct.inl"
//<<<<<+=====T20130406_New2
public:
  void Update(IEnv&Env)
  {
    debugger.update();
  }
};

class TProgramPlainHolder:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramPlainHolder)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,filename,SET,"mega_file",$)\
ADDVAR(bool,need_save,SET,false,$)\
ADDVAR(bool,need_load,SET,false,$)\
ADDVAR(bool,enabled,SET,false,$)\
ADDVAR(int,mode,SET,0,$)\
ADDVAR(string,mode_as_string,DEF,$,$)\
ADDVAR(TAutoPtr<ISubProgram>,root,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramPlainHolder
#include "QapGenStruct.inl"
//<<<<<+=====TProgramPlainHolder
public:
  void Update(IEnv&Env)
  {
    string arr[]={"qap::bin","qap::proto","qap::plain","qap::json"};
    mode_as_string=arr[abs(mode)%lenof(arr)];
    if(need_load){
      need_load=false;
      //if(mode_as_string=="qap::plain")dev_space_plain::QapPublicUberFullLoaderPlain(Env.Env,QapRawUberObject(root),filename);
      //if(mode_as_string=="qap::proto")QapPublicUberFullSaverProto(Env.Env,QapRawUberObject(root),filename);
      if(mode_as_string=="qap::bin")QapPublicUberFullLoaderBin(Env.Env,QapRawUberObject(root),filename);
      //if(mode_as_string=="qap::json")dev_space_json::QapPublicUberFullSaverJson(Env.Env,QapRawUberObject(root),filename);
    }
    if(need_save){
      need_save=false;
      if(mode_as_string=="qap::plain")dev_space_plain::QapPublicUberFullSaverPlain(Env.Env,QapRawUberObject(root),filename);
      if(mode_as_string=="qap::proto")QapPublicUberFullSaverProto(Env.Env,QapRawUberObject(root),filename);
      if(mode_as_string=="qap::bin")QapPublicUberFullSaverBin(Env.Env,QapRawUberObject(root),filename);
      if(mode_as_string=="qap::json")dev_space_json::QapPublicUberFullSaverJson(Env.Env,QapRawUberObject(root),filename);
    }
    if(enabled)if(root)root->Update(Env);
  }
};

void RunExternFunc_2013_04_06(IEnvRTTI&Env,void*pValue,TType*pType){
  PrivateCode(Env,pValue,pType);
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
      if(0)
      {
        auto&arr=Env.GetArr();
        arr.push_back(EnvType());
        auto&back=arr.back();
        DeclareEnvRTTI DeclEnv;
        TVoidPtr vp;
        //DeclEnv.Arr[0]->
        //back.Type->
      }
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(T20130406_New)\
        F(T20130406_New2)\
        F(T20130406_Debuger)\
        F(TUnitPtr_To_TTargetForPtr)\
        F(TUnitPtr_To_ISubProgram)\
        F(TUnitPtr_To_Troll)\
        F(TProgramPlainHolder)\
        F(TUnitPtr_Test)
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
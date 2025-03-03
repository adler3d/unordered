//#include "DynamicTestProgram.inl"

TType*QapFindTypeByFactory(TEnvRTTI&Env,IFactory*pFactory)
{
  return Env.FindTypeByFactory(pFactory);
}

TType*FindTypeByFactoryFast(TEnvRTTI&Env,TServerPtrSpace&Space,IFactory*pFactory)
{
  auto&ptr_lnk=Space[pFactory->Self].ptr_lnk;
  if(ptr_lnk.IsNull()){
    ptr_lnk=Space[QapFindTypeByFactory(Env,pFactory)->Self].ptr;
  }
  if(ptr_lnk.IsValid())return (TType*)ptr_lnk.get();
  return nullptr;
}

void MarkEmptyAsSystem(TServerPtrSpace&Space)
{
  auto&arr=Space.Arr;
  for(int i=1;i<arr.size();i++)
  {
    auto&item=arr[i];
    if(item.ptr.IsNull())item.system=true;
  }
}

void SafeClearSpace(TServerPtrSpace&Space)
{
  auto&arr=Space.Arr;
  for(int i=0;i<arr.size();i++)
  {
    auto&item=arr[i];
    if(item.ptr.IsValid())Space.Del(item);
  }
  arr.clear();
}

IFactory*TypeGetFactory(TType*pType){return pType->Factory.get();}

TType*FindTypeInPtrArrayByFactory(vector<TType*>&arr,IFactory*pFactory)
{
  for(int i=0;i<arr.size();i++)
  {
    auto*pType=arr[i];
    if(pType->Factory.get()==pFactory)return pType;
  }
  return nullptr;
}

struct TYetAnotherClientCounter20120821:public TClientPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
public:
  TYetAnotherClientCounter20120821(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if(item.passed)return;
    if(item.count)return;
    if(!item.ptr.type)return;
    if(!item.ptr.type->IsBasedOn(pTType)){item.passed=true;item.count=0;return;}
    item.count++;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if(!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};

void AddDependsToList(IEnvRTTI&Env,vector<TType*>&arr)
{
  TServerPtrSpace Space;
  TYetAnotherClientCounter20120821 Yacc(Env,Space);
  TClientPtrVisitor ClientVisitor(Yacc);
  EnvAdapter::GoV3(Space,Env);
  EnvAdapter::FixEnvType(Space,Env,EnvAdapter::TMetaTypePack(Env));
  for(int i=0;i<arr.size();i++)
  {
    auto*pType=arr[i];
    auto&item=Space[pType->Self];
    item.count=1;
  }
  DependsSolver DS(Env,ClientVisitor);
  DS.SolveDepends(Space);
  //Space.Repack();
  for(int i=1;i<Space.size();i++){Space[i].system=false;}
  for(int i=0;i<arr.size();i++)
  {
    auto*pType=arr[i];
    auto&item=Space[pType->Self];
    item.system=true;
  }
  //
  for(int i=1;i<Space.size();i++)
  {
    auto&item=Space[i];
    if(!item.count)continue;
    if(item.system)continue;
    QapAssert(item.ptr.type->IsBasedOn(Yacc.pTType));
    arr.push_back((TType*)item.ptr.get());
  }
}

string GetTypeFullNamesFromPtrArray(vector<TType*>&arr)
{
  string tmp;
  for(int i=0;i<arr.size();i++)
  {
    if(i)tmp+=",\n";
    tmp+=arr[i]->GetFullName();
  }
  return std::move(tmp);
}

TType*QapFindDeclareTypeByTTypeFactory(TEnvRTTI&Env,TType*pType)
{
  TServerPtrSpace Space_Env_TTypeToDeclareType;
  TType*pValueBasedOnTType=QapFindTypeByFactory(Env,pType->Factory.get());
  TType*pValueBasedOnDeclareType=(TType*)Space_Env_TTypeToDeclareType[pValueBasedOnTType->Self].ptr_lnk.get();
  TType*pResult=QapFindTypeByFactory(Env,pValueBasedOnDeclareType->Factory.get());
  return pResult;
}

void QapBuildDeclareTypeFromTType(TEnvRTTI&Env,TSmartPtrDumper&Dumper,TAutoPtr<DeclareType>&Dest,TAutoPtr<TType>&Source)
{
  QapAssert(!Dest&&Source);
  auto*pType=Source.Product.pType.get();
  Dest.Product.pType=QapFindDeclareTypeByTTypeFactory(Env,pType);
  Dest.Product.Init();
  auto*pDest=Dest.get();
  auto*pSource=Source.get();
  TQapIO Buff;
  {
    TBinarySaver BS(Dumper,Buff,pSource);
    pType->Use(BS);
  }
  Buff.IO.pos=0;
  {
    TBinaryLoader BS(Dumper,Buff,pDest);
    pType->Use(BS);
  }
}

void QapCloneMetaType(TEnvRTTI&Env,TSmartPtrDumper&Dumper,TAutoPtr<TType>&Dest,TAutoPtr<TType>&Source)
{
  QapAssert(!Dest&&Source);
  auto*pType=Source.Product.pType.get();
  Dest.Product.pType=QapFindTypeByFactory(Env,pType->Factory.get());
  Dest.Product.Init();
  auto*pDest=Dest.get();
  auto*pSource=Source.get();
  TQapIO Buff;
  {
    TBinarySaver BS(Dumper,Buff,pSource);
    pType->Use(BS);
  }
  Buff.IO.pos=0;
  {
    TBinaryLoader BS(Dumper,Buff,pDest);
    pType->Use(BS);
  }
}

void QapCloneEnvRTTI(EnvAdapter::TMetaTypePack&TypePack,TEnvRTTI&Env,TEnvRTTI&SubEnv,vector<TType*>&DefList)
{
  QapAssert(SubEnv.Arr.empty());
  if(Env.Arr.empty())return;
  TServerPtrSpace ST_Space,LT_Space;
  TSmartPtrDumper Dumper(ST_Space,LT_Space);
  EnvAdapter::GoV2(ST_Space,Env,TypePack);
  EnvAdapter::FixEnvType(ST_Space,Env,TypePack);
  LT_Space.resize(ST_Space.size());
  auto&arr=Env.Arr;
  SubEnv.Arr.reserve(arr.size());
  int pass=0;
  for(int i=0;i<arr.size();i++)
  {
    auto&source=arr[i].Type;
    if(!FindTypeInPtrArrayByFactory(DefList,source->Factory.get()))continue;
    //if(source->GetFullName()!="int")continue;
    SubEnv.Arr.push_back(EnvType());
    auto&dest=SubEnv.Arr.back().Type;
    QapCloneMetaType(Env,Dumper,dest,source);
  }
  if(true)
  {
    auto&item=ST_Space[Env.Self];
    ST_Space.Del(item);
    item.ptr.ptr=EnvAdapter::get(SubEnv.Self);
    ST_Space.InsertTo(item.id,item);
  }
  if(true)
  {
    auto&item=ST_Space[Env.Alloc->Self];
    ST_Space.Del(item);
    item.ptr.ptr=EnvAdapter::get(SubEnv.Alloc->Self);
    ST_Space.InsertTo(item.id,item);
  }
  MarkEmptyAsSystem(LT_Space);
  pass=1;
  for(int i=0;i<SubEnv.Arr.size();i++)
  {
    auto&type=SubEnv.Arr[i].Type;
    Dumper.SolveClient(type.Product.pType.get(),type.get());
    if(type->Env.get()!=&SubEnv)
    {
      QapDebugMsg("AAA!!!");
    }
  }
  pass=2;
  //Env.PrintLog();
  string tmp=SubEnv.GetTypeFullNames();
  SafeClearSpace(LT_Space);
}

struct DeclareEnvHolder
{
  IEnvRTTI&Env;
  DeclareEnvRTTI&DeclEnv;
};

void ConvEnvRTTIToDeclareEnv(TBigMetaTypePack&TypePack,DeclareEnvHolder&Dest,IEnvRTTI&Source)
{
  TServerPtrSpace Space;
  EnvAdapter::GoV2(Space,Source,EnvAdapter::TMetaTypePack(TypePack));
  //TSpaceDependsTools Tools(Dest.Env,Space);
  TMegaSolver Solver(Dest.Env,Space);
  TClientPtrSolver::TwoMetaType tmt(Dest.Env);
  TSpaceDependsTools::BuildProxyEx(Solver,Space,tmt,Dest.DeclEnv);
  //Tools.BuildProxy();
}


class TDependsStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDependsStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,Value,SET,128,$)\
ADDVAR(1,string,Name,DEF,$,$)\
ADDEND()
//=====+>>>>>TDependsStruct
#include "QapGenStruct.inl"
//<<<<<+=====TDependsStruct
};

class TBadStruct;

class TSelfStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSelfStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>TSelfStruct
#include "QapGenStruct.inl"
//<<<<<+=====TSelfStruct
public:
  static void SysHasSelf();
};

class TOtherDependsStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TOtherDependsStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,char,Value,SET,'9',$)\
ADDVAR(1,TDependsStruct,DS,DEF,$,$)\
ADDVAR(2,string,key_word,DEF,$,$)\
ADDVAR(3,TSelfStruct,some,DEF,$,$)\
ADDEND()
//=====+>>>>>TOtherDependsStruct
#include "QapGenStruct.inl"
//<<<<<+=====TOtherDependsStruct
};

vector<TType*> GetDefTypePtrArray(TEnvRTTI&Env)
{
  vector<TType*> arr;
  #define F(TYPE)arr.push_back(Sys$$<TYPE>::GetRTTI(Env));
  F(TSelfStruct)F(TAutoPtr<DeclareEnvRTTI>)F(MiniMetaSpec)//F(TOtherDependsStruct)
  #undef F
  return std::move(arr);
}

void RunTestNext1(TEnvRTTI&Env)
{
  auto DefList=GetDefTypePtrArray(Env);
  {
    //auto&arr=DeclareTypeArray;
    auto addfunc=[&DefList](TType*pDeclareType,TType*pTType)
    {
      DefList.push_back(pTType);
      DefList.push_back(pDeclareType);
      //typedef std::pair<TType*,TType*> pair;
      //pair tmp(pDeclareType,pTType);
      //arr.push_back(std::move(tmp));
    };
    //addfunc(pDeclareType,pTType);
    TMegaSolver::DeclareVisitAll(Env,addfunc);
  }
  //stage 0
  TBigMetaTypePack BigTypePack((IEnvRTTI&)Env);
  EnvAdapter::TMetaTypePack TypePack((IEnvRTTI&)Env);
  {
    AddDependsToList(Env,DefList);
    string tmp=GetTypeFullNamesFromPtrArray(DefList);
  }
  //stage 1
  TStdAllocator Alloc;
  TEnvRTTI SubEnv;
  SubEnv.Alloc=&Alloc;
  SubEnv.OwnerEnv=&Env;
  QapCloneEnvRTTI(TypePack,Env,SubEnv,DefList);
  //stage 2
  TStdAllocator Alloc2;
  TEnvRTTI SubEnv2;
  SubEnv2.OwnerEnv=&SubEnv;
  SubEnv2.Alloc=&Alloc2;
  QapCloneEnvRTTI(TypePack,SubEnv,SubEnv2,DefList);
  //test
  {
    auto*pIntType_0=Sys$$<int>::GetRTTI(Env);
    auto*pIntType_1=Sys$$<int>::GetRTTI(SubEnv2);
    //auto*pVectorVectorIntType=Sys$$<vector<vector<int>>>::GetRTTI(SubEnv2);
    IEnvRTTI*arr[]={pIntType_0->Env.get(),pIntType_1->Env.get()};
    QapAssert(arr[0]==&Env);
    QapAssert(arr[1]==&SubEnv2);
  }
  //stage 3
  TAutoPtr<DeclareEnvRTTI> pDeclEnv=UberInit<DeclareEnvRTTI>(Env);
  DeclareEnvHolder DEH={SubEnv,*pDeclEnv.get()};
  ConvEnvRTTIToDeclareEnv(BigTypePack,DEH,SubEnv2);
  QapUberFullSaver(SubEnv,QapRawUberObject(pDeclEnv),UberSaveDeviceProto(TQapFileStream("decl_env.hpp",false)));  //<- not work :(
}

//void RunTestNext2(TEnvRTTI&Env)
//{
//  TSomeTestProgram STP;
//  STP.Go(Env);
//}

void RunTestNext3(TEnvRTTI&Env);
void RunTestNext4(TEnvRTTI&Env);
void RunTestNext5(TEnvRTTI&Env);
void RunTestNext6(TEnvRTTI&Env);

void EntryPoint_v05(TEnvRTTI&Env)
{
  RunTestNext6(Env);
}

class TMineStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMineStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TWeakPtr<TType>,Value,DEF,$,$)\
ADDVAR(1,int,price,SET,99,$)\
ADDVAR(2,DeclareEnvRTTI,DeclareEnv,DEF,$,$)\
ADDVAR(3,TAutoPtr<TMineStruct>,next,DEF,$,$)\
ADDEND()
//=====+>>>>>TMineStruct
#include "QapGenStruct.inl"
//<<<<<+=====TMineStruct
};

//ADDVAR(2,TChunkPtr<TMineStruct>,chunk,DEF,$,$)

bool IsInt(TType*pIntType)
{
  if(!pIntType)return false;
  auto*pEnv=pIntType->Env.get();
  if(!pEnv)return false;
  auto&Env=*pEnv;
  auto*p=Sys$$<int>::GetRTTI(Env);
  return p==pIntType;
}
static DeclareEnvRTTI tmp_variable_28_08_2012;
void RunTestNext3(TEnvRTTI&Env)
{
  /*
  TChunkPtr<TMineStruct> chunk;
  chunk.Leaf.build<TMineStruct>(chunk.SubEnv);
  TAutoPtr<TMineStruct>&pMS=chunk.Leaf->next;
  pMS.Product.pType=Sys$$<TMineStruct>::GetRTTI(Env);
  pMS.Product.Init();
  bool flag=IsInt(Sys$$<int>::GetRTTI(Env));
  pMS->Value=Sys$$<int>::GetRTTI(Env);
  pMS->next.build<TMineStruct>(Env);
  pMS->next->price=31456;
  */
  vector<string> chunk; chunk.push_back("object");
  THardPtr<TType> hard_ptr=Sys$$<DeclareTypeSys>::GetRTTI(Env);
  //TChunkPtr
  QapUberFullSaver(Env,QapRawUberObject(chunk),UberSaveDeviceProto(TQapFileStream("MineStruct.hpp",false)));
}

class TMeStruct20120829{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMeStruct20120829)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<SelfClass>,Next,DEF,$,$)\
ADDVAR(2,TWeakPtr<TType>,Type,DEF,$,$)\
ADDVAR(3,TAutoPtr<SelfClass>,Sub,DEF,$,$)\
ADDVAR(4,string,Caption,DEF,$,$)\
ADDEND()
//=====+>>>>>TMeStruct20120829
#include "QapGenStruct.inl"
//<<<<<+=====TMeStruct20120829
public:
  static void SysHasSelf();
public:
  void go1(){}
  void go2(){}
  void go3(){}
  void go4(){}
};

void Hehe_20120829(TEnvRTTI&Env,vector<TMeStruct20120829>&Arr)
{
  TServerPtrSpace Space;
  TVoidPtr::TRawPtr raw_ptr(Env,Arr);
  Space.AddPointsFromSys();
  Space.AddPointsFromEnv(Env);
  Space.AddPointsFrom(raw_ptr);
  SpaceMutator SM;
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      SM.arr.push_back(EnvAdapter::get(ex.Self));
    }
  }
  Space.Mutate(SM);
}

//int*pSaveIDValue_20120831=nullptr;

void RunTestNext4(TEnvRTTI&Env)
{
  vector<TMeStruct20120829> Arr;
  QapUberFullLoader(Env,QapRawUberObject(Arr),UberLoadDeviceBin(TQapFileStream("MeStruct20120829.dat",true)));
  Arr.resize(4);
  for(int i=0;i<Arr.size();i++)Arr[i].Caption="useritem["+IToS(i)+"]";
  Arr[0].Next=&Arr[1];
  Arr[1].Next=&Arr[2];
  Arr[2].Next=&Arr[3];
  Arr[3].Next=&Arr[0];
  Arr[0].Type=Sys$$<int>::GetRTTI(Env);
  Arr[1].Type=Sys$$<string>::GetRTTI(Env);
  Arr[2].Type=Sys$$<DeclareTypeStruct>::GetRTTI(Env);
  Arr[2].Sub.build<TMeStruct20120829>(Env)->Caption="Hello world";
  Arr[3].Type=Sys$$<TTypeStruct>::GetRTTI(Env);
  //pSaveIDValue_20120831=&Arr[0].Self.P.SaveID;
  QapUberFullSaver(Env,QapRawUberObject(Arr),UberSaveDeviceBin(TQapFileStream("MeStruct20120829.dat",false)));
  QapUberFullSaver(Env,QapRawUberObject(Arr),UberSaveDeviceProto(TQapFileStream("MeStruct20120829.hpp",false)));
  Hehe_20120829(Env,Arr);
}

class TEmptyStruct20120903{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyStruct20120903)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,Caption,SET,"crumb",$)\
ADDVAR(1,TWeakPtr<TType>,pType,DEF,$,$)\
ADDVAR(2,TAutoPtr<TType>,Value,DEF,$,$)\
ADDEND()
//=====+>>>>>TEmptyStruct20120903
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyStruct20120903
};

class TEmptyStruct20120903_16_04{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyStruct20120903_16_04)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,Caption,SET,"crumb",$)\
ADDVAR(1,TWeakPtr<DeclareType>,pType,DEF,$,$)\
ADDVAR(2,TAutoPtr<DeclareType>,Value,DEF,$,$)\
ADDEND()
//=====+>>>>>TEmptyStruct20120903_16_04
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyStruct20120903_16_04
};

class TEmptyStruct20120903_16_09{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyStruct20120903_16_09)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,Caption,SET,"crumb",$)\
ADDVAR(1,TWeakPtr<DeclareTypeWeakPtr>,pTypeA,DEF,$,$)\
ADDEND()
//=====+>>>>>TEmptyStruct20120903_16_09
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyStruct20120903_16_09
};
/*
class EnvDefTypeStr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypeStr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,string,Name,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypeStr
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypeStr
public:
  static void SysHasSelf();
};

class EnvDefTypePtr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypePtr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<DeclareType>,Link,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypePtr
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypePtr
public:
  static void SysHasSelf();
};*/

class TEmptyStruct20120904_14_34{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyStruct20120904_14_34)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,EnvDefTypeStr,Str,DEF,$,$)\
ADDVAR(1,EnvDefTypePtr,Ptr,DEF,$,$)\
ADDVAR(2,EnvType,Type,DEF,$,$)\
ADDVAR(3,DeclareEnvRTTI,DeclEnv,DEF,$,$)\
ADDVAR(4,TWeakPtr<DeclareTypeWeakPtr>,Troll,DEF,$,$)\
ADDVAR(5,TWeakPtr<TType>,TrollPtr,DEF,$,$)\
ADDEND()
//=====+>>>>>TEmptyStruct20120904_14_34
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyStruct20120904_14_34
};

void RunTestNext5(TEnvRTTI&Env)
{
  TEmptyStruct20120903_16_09 Root;
  //Root.TrollPtr=Sys$$<TWeakPtr<DeclareTypeWeakPtr>>::GetRTTI(Env);
  //QapUberFullLoader(Env,QapRawUberObject(Root),UberLoadDeviceBin(TQapFileStream("EmptyStruct20120903.dat",true)));
  //Root.Value.build<DeclareTypeStruct>(Env)->Name="QapPtr<QapItem>";
  //Root.pType=Root.Value.get();
  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceBin(TQapFileStream("EmptyStruct20120903.dat",false)));
  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceProto(TQapFileStream("EmptyStruct20120903.hpp",false)));
}

class TEmptyStruct20120912_11_31{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyStruct20120912_11_31)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,Str,SET,"egg",$)\
ADDVAR(1,int,RunCount,SET,0,$)\
ADDVAR(2,double,LoadTime,SET,0,$)\
ADDEND()
//=====+>>>>>TEmptyStruct20120912_11_31
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyStruct20120912_11_31
};


class TEmptyStruct20120913_11_46{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyStruct20120913_11_46)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,string,Str,SET,"egg",$)\
ADDVAR(2,int,RunCount,SET,0,$)\
ADDVAR(3,double,LoadTime,SET,0,$)\
ADDEND()
//=====+>>>>>TEmptyStruct20120913_11_46
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyStruct20120913_11_46
public:
  static void SysHasSelf();
public:
};

void RunTestNext6(TEnvRTTI&Env)
{
  QapClock Clock;
  TEmptyStruct20120913_11_46 Root;
  Root.Str="hello world";
  Clock.Start();
  QapUberFullLoader(Env,QapRawUberObject(Root),UberLoadDeviceBin(TQapFileStream("EmptyStruct20120913_11_46.dat",true))); 
  Clock.Stop();
  Root.RunCount++;
  Root.LoadTime=Clock.MS();
  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceProto(TQapFileStream("EmptyStruct20120913_11_46.hpp",false)));
  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceBin(TQapFileStream("EmptyStruct20120913_11_46.dat",false)));
}







//  QapClock Clock;
//  Clock.Start();
//  for(int i=0;i<arr.size();i++)
//  {
//    auto&dest=SubEnv.Arr[i].Type;
//    auto&source=arr[i].Type;
//    QapCloneMetaType(Env,ST_Space,LT_Space,dest,source);
//  }
//  Clock.Stop();
//  string result=FToS(Clock.MS());
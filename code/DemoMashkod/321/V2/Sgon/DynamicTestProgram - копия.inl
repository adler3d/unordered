#ifdef DEF_BUILD_MACRO
  #include "../Macro/DynamicTestProgram.h"
#else
//=====>>>>>DynamicTestProgram

template<class TYPE>
struct TChunkPtr
{
  TEnvRTTI SubEnv;
  TAutoPtr<TYPE> Leaf;
};

class TSomeBase{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeBase)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,Value,SET,10,$)\
ADDEND()
//=====+>>>>>TSomeBase
#include "QapGenStruct.inl"
//<<<<<+=====TSomeBase
public:
  virtual void Do(){};
};


class TSomeClassV00:public TSomeBase{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeClassV00)PARENT(TSomeBase)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>TSomeClassV00
#include "QapGenStruct.inl"
//<<<<<+=====TSomeClassV00
public:
  static void SysHasSelf();
};

struct TProxySolverBase
{
public:
  struct TRawPtrDeclare
  {
    TType*pType;
    DeclareType*pValue;
    TRawPtrDeclare():pType(nullptr),pValue(nullptr){}
    TRawPtrDeclare(const TRawPtrDeclare&ref)
    {
      this->pType=ref.pType;
      this->pValue=ref.pValue;
    }
    TRawPtrDeclare(TRawPtrDeclare&&ref)
    {
      this->pType=ref.pType;
      this->pValue=ref.pValue;
    }
    TRawPtrDeclare(const TAutoPtr<DeclareType>&ref):pType(nullptr),pValue(nullptr)
    {
      pType=ref.Product.pType.get();
      pValue=ref.get();
    }
  };
public:
  typedef vector<TAutoPtr<DeclareType>> TArray;
  typedef TVoidPtr::TRawPtr TRawPtr;
  typedef TServerPtrSpace TSpace;
  typedef vector<TRawPtrDeclare> TOutArray;
public:
  struct TContext{
    TSpace&Space;
    TArray&BLT;
  };
  struct TOutput{
    TOutArray Linked;
    TOutArray Other;
  public:
    void clear()
    {
      Linked.clear();
      Other.clear();
    }
    void eat(TOutput&&ref)
    {
      auto&inp=*this;
      auto&out=ref;
      inp.Linked=std::move(out.Linked);
      ToolsVectorEx(inp.Other)+=std::move(out.Other);
    }
  };
};

struct TLinkByName:public TProxySolverBase
{
public:
  static void pass(TContext&Context,TOutput&Output,TAutoPtr<DeclareType>&Value)
  {
    auto*pValue=Value.get();
    auto&Space=Context.Space;
    auto&item=Space[pValue->Self];
    string ValueFullName=pValue->GetFullName();
    item.name="Adv$$<"+ValueFullName+">::GetRTTI()";
    if(item.ptr_adv.IsValid())
    {
      QapDebugMsg(ValueFullName+" - WTF?");
      return;
    }
    bool Result=false;
    auto&arr=Context.BLT;
    for(int i=0;i<arr.size();i++)
    {
      auto*p=arr[i].get();
      if(p->GetFullName()==ValueFullName)
      {
        auto&jtem=Space[p->Self];
        TSpace::make_linked(item,jtem);
        Result=true;
        break;
      }
    }
    (Result?Output.Linked:Output.Other).push_back(Value);
  }
  static void pass_each(TContext&Context,TOutput&Output,TArray&arr)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(Context,Output,ex);
    }
  }
};

struct TLinkFilter:public TProxySolverBase
{
public:
  class TClientPtrFilter:public TSmartPtrVisitor::ICallBack{
  public:
    int SkipCount;
    int AddCount;
    TSpace&Space;
    TClientPtrFilter(TSpace&Space):Space(Space){AddCount=0;SkipCount=0;}
  public:
    void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
    void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
      MegaVisit(A,elemType);
    }
    void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
      MegaVisit(A,elemType);
    }
    void Visit(TClientPtr<IEsoteric>&A){
      MegaVisitEx(A);
    }
    void Visit(THardClientPtr<IEsoteric>&A){
      MegaVisitEx(A);
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
      bool good=item.ptr_adv.IsValid();
      if(!good)SkipCount++;
      return;
    }
  public:
    template<template<class> class SmartPtr>
    inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
    {
      static_assert(
        std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
        std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
      );
      if(!A)return;
      DoVisitSaveID(A.ptr->SaveID,true,elemType);
    }
    template<template<class> class SmartPtr>
    inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
    {
      static_assert(
        std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
        std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
      );
      if(!A)return;
      DoVisitSaveID(A.ptr->SaveID,false,nullptr);
    }
  };
public:
  static bool pass(TContext&Context,TOutput&Output,TRawPtrDeclare&ptr)
  {
    auto&Space=Context.Space;
    TClientPtrFilter CPF(Space);
    TSmartPtrVisitor SPV(CPF,ptr.pValue);
    ptr.pType->Use(SPV);
    if(CPF.SkipCount)
    {
      Output.Other.push_back(ptr);
      return false;
    }
    Output.Linked.push_back(ptr);
    return true;
  }
  static void pass_each(TContext&Context,TOutput&Output,TOutArray&arr)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(Context,Output,ex);
    }
  }
};

struct TLinkFullTesting:public TProxySolverBase
{
public:
  static bool Testing(TContext&Context,TSpaceDependsTools&Tools,TOutArray&arr)
  {
    auto get=[&](EnvVoidPtr&ptr)->DeclareType*
    {
      bool good=ptr.type->IsBasedOn(Tools.pDeclareType);
      QapAssert(good);
      return (DeclareType*)ptr.get();
    };
    auto&Space=Context.Space;
    DeclareDetail::IsEqualTo<TSpace> V(Space);
    V.Result=!arr.size();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pValue=ex.pValue;
      auto*pType=ex.pType;
      V.Result=false;
      V.pValue=pValue;
      auto&item=Space[pValue->Self];
      if(item.ptr_adv.IsValid())
      {
        auto*p=get(item.ptr_adv);
        auto&jtem=Space[p->Self];
        QapAssert(jtem.ptr_adv.get()==(void*)pValue);
        item.ptr_adv.set_zero();
        jtem.ptr_adv.set_zero();
        V.Result=false;
        p->Use(V);
        if(V.Result)
        {
          bool f0=item.ptr_adv.get()==jtem.ptr.get();
          bool f1=jtem.ptr_adv.get()==item.ptr.get();
          QapAssert(f0&&f1);
        }
      }else{
        QapDebugMsg("WTF?");
      }
      if(!V.Result)
      {
        QapDebugMsg("bad type : \""+pValue->GetFullName()+"\"");
        break;
      }
    }
    return V.Result;
  }
};

struct TSomeTestProgram
{
  TChunkPtr<TSomeBase> Code;
  DeclareEnvRTTI DeclEnv;
public:
  typedef vector<TAutoPtr<DeclareType>> TArray;
  typedef TVoidPtr::TRawPtr TRawPtr;
  typedef TServerPtrSpace TSpace;
public:
  //static bool Linking(TSpace&Space,TArray&BLT,TArray&LT)
  //{
  //  TLinkByName::TContext Context={Space,BLT};
  //  TLinkByName::TOutput Output;
  //  TLinkByName::pass_each(Context,Output,LT);
  //  string report_msg;
  //  auto&arr=Output.Other;
  //  for(int i=0;i<arr.size();i++)
  //  {
  //    auto&ex=arr[i];
  //    string&fn=ex.pValue->GetFullName();
  //    string msg="not found type : \""+fn+"\"";
  //    report_msg+=msg+"\n";
  //  }
  //  if(!arr.empty())
  //  {
  //    QapDebugMsg("report :\n"+report_msg);
  //  }
  //  return arr.empty();
  //}
  static bool LinkingAndTesting(TSpaceDependsTools&Tools,TSpace&Space,TArray&BLT,TArray&LT)
  {    
    TLinkByName::TContext Context={Space,BLT};
    TLinkByName::TOutput Output;
    TLinkByName::pass_each(Context,Output,LT);
    TLinkByName::TOutput OutputEx;
    TLinkByName::TOutArray NC[4];
    auto ExcludeUnknowProxy=[&]()->void
    {
      bool flag=true;
      TLinkByName::TOutput&inp=OutputEx;
      inp.Linked=Output.Linked;
      TLinkByName::TOutput out;
      while(flag)
      {
        out.clear();
        TLinkFilter::pass_each(Context,out,inp.Linked);
        flag=!out.Other.empty();
        inp.eat(std::move(out));
      }
    };
    ExcludeUnknowProxy();
    Output.eat(std::move(OutputEx));
    bool result=TLinkFullTesting::Testing(Context,Tools,Output.Linked);
    if(result&&false)
    {
      auto&arr=Output.Linked;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        string fn=ex.pValue->GetFullName();
        //Space передаваемый в ReverseSolver должен быть с пустым ptr_adv.
        TMegaSolverReverse ReverseSolver(Tools.Env,Space);
        EnvType env_type;
        ReverseSolver.PreConv(ex.pValue,env_type.Type);
        //env_type.Type->Factory=
        //так тут мы делаем копии.
        //вообще мы для всего делаем копии. так?
        //ex.pType->Use();
        //TDynStructFactory
      }
    }
    return result;
  }
public:
  struct TSomeClassV01{
    int a,b,c,d;
  };
  static void InitSubEnv(IEnvRTTI&Env,DeclareEnvRTTI&Source,IEnvRTTI&Target)
  {
    TQapBinaryObject qbo;
    TRawPtr raw_ptr(Env,Source);
    TConservationMachine Machine(Env,qbo);
    auto&Space=Machine.Space;
    auto&SpaceAdv=Machine.SpaceAdv;
    Machine.Tools.RemoveFromSpace(Space);
    SpaceAdv.CopyAdvFrom(Space);
    if(1)
    {
      auto&pType=raw_ptr.pType;
      auto&pValue=raw_ptr.pValue;
      GrabServerPtr(SpaceAdv,pType,pValue,true);
    }
    auto&ExpectedInLoadTime=Source.Arr;//все загруженные заместители.
    auto&ExpectedInBeforeLoadTime=Machine.Tools.DeclArr;//заместители известных на этапе перд-загрузки типов.
    LinkingAndTesting(Machine.Tools,SpaceAdv,ExpectedInBeforeLoadTime,ExpectedInLoadTime);
    EnvType me_ET;
    {
      auto*pdTypeSource=ExpectedInLoadTime[1].get();
      string fn=pdTypeSource->GetFullName();
      auto*pF=me_ET.Factory.build<TDynStructFactory>(Env);
      auto*pT=me_ET.Type.build<TTypeStruct>(Env);
      pF->pType=pT;
      pT->Env=&Target; //TODO : you sure?
      pT->Info.Name=fn;
      pT->Factory=pF;
      pT->Info.Size=-1;
      auto&arr=DeclareTypeStruct::UberCast(pdTypeSource)->Members;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        TTypeStruct::Member field;
        field.Mode=ex.Mode;
        field.Name=ex.Name;
        field.Number=ex.Number;
        field.Offset=-1;
        auto*t=SpaceAdv[ex.Type->Self].ptr_adv.type;
        auto*pd=(DeclareType*)SpaceAdv[ex.Type->Self].ptr_adv.get();
        auto*p=(TType*)Space[SpaceAdv[ex.Type->Self].ptr_adv.ptr->SaveID].ptr.get();
        field.Type=(TType*)p; //TODO : you sure?
        field.Value=ex.Value;
        pT->AddField(std::move(field));
      }
      pT->ReCalcMembersOffset();
      TAutoPtr<void> aptr;
      aptr.Product.pType=pT;
      aptr.Product.Init();
      TSomeClassV01*ptr=(TSomeClassV01*)aptr.Product.Memory.ptr;
    }
    Target.GetArr().push_back(std::move(me_ET));
  }
  void Go(IEnvRTTI&Env)
  {
    Sys$$<TSomeBase>::GetRTTI(Env);
    Sys$$<TSomeClassV00>::GetRTTI(Env);
    //GenV0(Env);
    GenV1(Env);
    TStdAllocator Alloc;
    Code.SubEnv.Alloc=&Alloc;
    InitSubEnv(Env,DeclEnv,Code.SubEnv);
    Code.SubEnv.clear();
    Code.SubEnv.Alloc=nullptr;
    auto find_type_by_name=[](IEnvRTTI&Env,const string&fn)->EnvType*
    {
      auto&arr=Env.GetArr();
      for(int i=0;i<arr.size();i++)
      {
        if(arr[i].Type->GetFullName()==fn)return &arr[i];
      }
      return nullptr;
    };
    auto*pInt=find_type_by_name(Env,"int");
    if(pInt)
    {
      TClientPtrSolver::TwoMetaType tmt(Env);
      auto*pTAutoType$$TType=Sys$$<TAutoPtr<TType>>::GetRTTI(Env);
    }
  }
  void GenV1(IEnvRTTI&Env)
  {
    auto&arr=DeclEnv.Arr;
    auto add_struct=[&arr,&Env](const string&name)->DeclareTypeStruct*
    {
      TAutoPtr<DeclareType> temp;
      auto*p=temp.build<DeclareTypeStruct>(Env);
      p->Name=name;
      arr.push_back(std::move(temp));
      return p;
    };
    auto add_sys=[&arr,&Env](const string&name)->DeclareTypeSys*
    {
      TAutoPtr<DeclareType> temp;
      auto*p=temp.build<DeclareTypeSys>(Env);
      p->FullName=name;
      arr.push_back(std::move(temp));
      return p;
    };
    //add_struct("TSomeClassV00");
    auto*pdInt=add_sys("int");
    auto*pV01=add_struct("TSomeClassV01");
    pV01->AddMember(0,pdInt,"Value0","SET","101");
    pV01->AddMember(1,pdInt,"Value1","SET","954");
    pV01->AddMember(2,pdInt,"Value2","SET","700");
    pV01->AddMember(3,pdInt,"Value3","SET","412");
    add_struct("TSomeClassV02");
    add_struct("TSomeClassV03");
    add_struct("TSomeClassV04");
    add_struct("TSomeClassV05");
  }
  void GenV0(IEnvRTTI&Env)
  {
    auto&arr=DeclEnv.Arr;
    auto add_struct=[&arr,&Env](const string&name)->DeclareTypeStruct*
    {
      TAutoPtr<DeclareType> temp;
      auto*p=temp.build<DeclareTypeStruct>(Env);
      p->Name=name;
      arr.push_back(std::move(temp));
      return p;
    };
    auto add_sys=[&arr,&Env](const string&name)->DeclareTypeSys*
    {
      TAutoPtr<DeclareType> temp;
      auto*p=temp.build<DeclareTypeSys>(Env);
      p->FullName=name;
      arr.push_back(std::move(temp));
      return p;
    };
    auto*pdBit=add_sys("bit");
    auto*pdInt=add_sys("int");
    auto*pdTSomeBase=add_struct("TSomeBase");
    pdTSomeBase->AddMember(0,pdInt,"Value","SET","10");
    auto*pdTRomeClass=add_struct("TRomeClass");
    auto*pdTSomeClass=add_struct("TSomeClass");
    pdTSomeClass->AddMember(0,pdTRomeClass,"Other","DEF","$");
    pdTSomeClass->SubType=pdTSomeBase;
    add_struct("TSomeClassV00")->AddMember(0,pdTRomeClass,"Rome","DEF","$");
  }
};

//<<<<<=====DynamicTestProgram
#endif //DEF_BUILD_MACRO//
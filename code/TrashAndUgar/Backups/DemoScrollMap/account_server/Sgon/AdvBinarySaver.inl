//MoveToEnv перемещат содержимое из pType в Env. Потом HackType следит за содержимым через hType.
class HackType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(HackType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IFactory>,pFactory,DEF,$,$)\
ADDVAR(TAutoPtr<TType>,pType,DEF,$,$)\
ADDVAR(THardPtr<TType>,hType,DEF,$,$)\
ADDVAR(vector<TAutoPtr<HackType>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>HackType
#include "QapGenStruct.inl"
//<<<<<+=====HackType
public:
  template<class METATYPE>
  METATYPE*Init(TEnvRTTI&Env)
  {
    auto*type=pType.build<METATYPE>(Env);
    auto*factory=pFactory.build<METATYPE::TDynamicFactory>(Env);
    type->Env=&Env;
    type->Factory=factory;
    factory->pType=type;
    return type;
  }
  //void AddSelfField(
  TTypeSelfPtr*MakeSelfPtr(TEnvRTTI&Env)
  {
    Items.push_back(TAutoPtr<HackType>());
    auto&ex=Items.back();
    auto*ht=ex.build<HackType>(Env);
    auto*type=ht->Init<TTypeSelfPtr>(Env);
    type->Info.Name="TSelfPtr";
    type->Info.Size=type->Factory->GetSize();
    type->Info.Align=detail::QapAlignOf<TSelfPtr<IEsoteric>>::value;
    type->ElementType=this->pType.get();
    return type;
  }
#define ToText(A)#A
  TTypeStruct*MakeQwertyStruct(TEnvRTTI&Env)
  {
    Items.push_back(TAutoPtr<HackType>());
    auto&ex=Items.back();
    auto*ht=ex.build<HackType>(Env);
    auto*type=ht->Init<TTypeStruct>(Env);
    type->Info.Name="QwertyStruct";
    type->Info.Size=-1;
    type->AddMemberSET(0,Sys$$<std::string>::GetRTTI(Env),"mega",-1,"SET",ToText("mega text"));
    type->AddMemberSET(1,Sys$$<std::string>::GetRTTI(Env),"word",-1,"SET",ToText("hello world"));
    type->AddMemberSET(2,Sys$$<bool>::GetRTTI(Env),"flag0",-1,"SET","true");
    type->AddMemberSET(3,Sys$$<bool>::GetRTTI(Env),"flag1",-1,"SET","false");
    type->AddMemberSET(4,Sys$$<bool>::GetRTTI(Env),"flag2",-1,"SET","true");
    type->AddMemberSET(5,Sys$$<bool>::GetRTTI(Env),"flag3",-1,"SET","false");
    type->ReCalcMembersOffset();
    type->Calc();
    return type;
  }
  TTypeStruct*MakeUserware(TEnvRTTI&Env)
  {
    auto*type=Init<TTypeStruct>(Env);
    type->Info.Name="UserwareStruct";
    type->Info.Size=-1;
    auto*selfptr=MakeSelfPtr(Env);
    auto*qwertystruct=MakeQwertyStruct(Env);
    type->AddMemberSET(0,Sys$$<double>::GetRTTI(Env),"d",-1,"SET","1.0");
    type->AddMemberSET(1,Sys$$<int>::GetRTTI(Env),"x",-1,"SET","0");
    type->AddMemberSET(2,Sys$$<int>::GetRTTI(Env),"y",-1,"SET","0");
    type->AddMemberSET(4,Sys$$<int>::GetRTTI(Env),"z",-1,"SET","0");
    type->AddMemberDEF(7,selfptr,"Self",-1,"DEF","$");
    type->AddMemberSET(8,Sys$$<std::string>::GetRTTI(Env),"s",-1,"SET",ToText("adler3d\r\n"));
    type->AddMemberDEF(9,qwertystruct,"q1",-1,"DEF","$");
    type->AddMemberSET(10,Sys$$<bool>::GetRTTI(Env),"flag",-1,"SET","true");
    type->AddMemberDEF(15,qwertystruct,"q2",-1,"DEF","$");
    type->ReCalcMembersOffset();
    type->Calc();
    return type;
  }
#undef ToText
public:
  void MoveFromEnv(int depth=0)
  {
    QapAssert(hType);
    if(hType)
    {
      auto*ptype=hType.get();
      auto*env=(TEnvRTTI*)ptype->Env.get();
      auto&arr=env->Arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.get()==ptype)
        {
          pType=std::move(ex);
          hType=nullptr;
        }
      }
    }
    QapAssert(pFactory);
    if(pFactory)
    {
      auto*fact=pFactory.get();
      auto&arr=TFactory<void>::GetFactorys();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.get()!=fact)continue;
        ex=nullptr;
      }
      vector_update(arr);
    }
    if(0==depth)return;
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(ex)ex->MoveFromEnv(depth-1);
    }
  }
  void unlink()
  {
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(ex)ex->unlink();
    }
    if(pFactory)
    {
      pFactory->unlink();
      //pFactory->pType=nullptr;
    }
    if(hType)MoveFromEnv();
    if(pType)
    {
      auto*type=TTypeStruct::UberCast(pType.get());
      if(type)type->Members.clear();
      pType->Factory=nullptr;
    }
  }
public:
  ~HackType()
  {
    unlink();
  }
public:
  void MoveToEnv(TEnvRTTI&Env)
  {
    QapAssert(!hType);
    QapAssert(&Env==pType->Env.get());
    hType=pType.get();
    Env.Arr.push_back(std::move(pType));
    auto&factorys=TFactory<void>::GetFactorys();
    factorys.push_back(pFactory.get());
    {
      IFactory*it=TFactory<void>::GetFactorys().back().get();
      string name="TFactory<"+it->GetElementType(Env)->GetFullName()+">::Get()";
      name+=" ";
    }
    for(int i=0;i<Items.size();i++)
    {
      auto&ex=Items[i];
      ex->MoveToEnv(Env);
    }
  }
};

template<class QAP_RTTI>
inline static bool QapAdvLoadFromFileEx(QAP_RTTI&Env,const string&fn,TType*pType,void*pValue)
{
  TQapIO Stream;
  Stream.IO.LoadFile(fn);
  if(Stream.IO.mem.empty())return false;
  return QapAdvLoadFromStreamEx(Env,Stream,pType,pValue);
}

template<class QAP_RTTI>
inline static bool QapAdvLoadFromStreamEx(QAP_RTTI&Env,TQapIO&Stream,TType*pType,void*pValue)
{
  TServerPtrSpace Space;
  IndirectLoader Ind(Env,Space);
  EnvAdapter::Go(Space,Env);
  Ind.LoadMetaSpace(Stream);
  if(!Ind.Space.IsValid())return false;
  if(Ind.LoadSpec(Stream)>0)return false;
  Ind.Load(Stream,pType,pValue);
  return true;
}
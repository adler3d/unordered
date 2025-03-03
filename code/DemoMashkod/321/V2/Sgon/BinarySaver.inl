//#include "BinarySaver.inl"

template<bool flag>
class ScopeBot{
public:
  TQapIO Stream;
  TQapIO&Owner;
public:
  ScopeBot(TQapIO&Owner):Owner(Owner){Init<flag>();}
  ~ScopeBot(){Free<flag>();}
  TQapIO*operator->(){return Stream;}
  operator TQapIO&(){return Stream;}
public:
  template<bool>void Init();
  template<>void Init<false>(){/*see Free<false>();*/}
  template<>void Init<true>(){Stream.LoadFrom(Owner);}
public:
  template<bool>void Free();
  template<>void Free<false>(){Stream.SaveTo(Owner);}
  template<>void Free<true>(){/*see Init<true>();*/}
public:
};

class ISmartPtrSolver{
public:
  bool Result;
  ISmartPtrSolver():Result(true){}
public:
  typedef int SaveIDType;
public:
  virtual void SolveClient(TType*pType,void*pValue){QapDebugMsg("no way.");}
public:
  virtual TType*PreSolve(THardPtr<TType>&pInput,TType*pBaseType){QapDebugMsg("no way.");return nullptr;}
  virtual TType*PreSolveEx(THardPtr<TType>&pInput){QapDebugMsg("no way.");return nullptr;}
public:
  virtual void GetSaveID(SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void GetSaveID(SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void GetSaveID(SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
public:
  virtual void SetSaveID(const SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void SetSaveID(const SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void SetSaveID(const SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
public:
  static TServerPtr<IEsoteric>*const&get(const SaveIDType&SaveID){return (TServerPtr<IEsoteric>*const&)(void*const&)SaveID;}
  static const SaveIDType&get(TServerPtr<IEsoteric>*const&serv){return (const SaveIDType&)(void*const&)serv;}
};

class TSmartPtrDumper:public ISmartPtrSolver{
public:
  TServerPtrSpace&ST_Space;
  TServerPtrSpace&LT_Space;
  TSmartPtrDumper(TServerPtrSpace&ST_Space,TServerPtrSpace&LT_Space):ST_Space(ST_Space),LT_Space(LT_Space){}
public:
  void SolveClient(TType*pType,void*pValue)
  {
    TDumpPtrSolver DPS(ST_Space,LT_Space);
    TSmartPtrVisitor SPV(DPS,pValue);
    pType->Use(SPV);
  }
public:
  TType*PreSolve(THardPtr<TType>&pInput,TType*pBaseType)
  {
    TType*pChunkType=pInput.get();
    QapAssert(pChunkType->IsBasedOn(pBaseType));
    return pChunkType;
  }
  TType*PreSolveEx(THardPtr<TType>&pInput)
  {
    TType*pChunkType=pInput.get();
    return pChunkType;
  }
public:
  void ST_CheckSaveID(SaveIDType&id,TType*pElemType)
  {
    auto&item=ST_Space[id];
    QapAssert(item.ptr.ptr);
    int&sid=item.ptr.ptr->SaveID;
    QapAssert(&sid==&id);
    if(item.system&&item.hidden)return;
    QapAssert(item.ptr.type->IsBasedOn(pElemType));
  }
  int ST_GetSID(TServerPtr<IEsoteric>*serv,TType*pElemType)
  {
    if(serv)
    {
      auto&id=serv->SaveID;
      if(id)ST_CheckSaveID(id,pElemType);
      if(!id)
      {
        QapAssert(id);
      }
      return id;
    }
    return 0;
  }
public:
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref)
  {
    auto&id=ref.P.SaveID;
    ST_CheckSaveID(id,pElemType);
    sid=id;
    typedef std::remove_reference<decltype(id)>::type id_type;
    static_assert(std::is_same<id_type,SaveIDType>::value,"WTF?");
  }
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref)
  {
    static_assert(std::is_same<int,SaveIDType>::value,"WTF?");
    TServerPtr<IEsoteric>*serv=ref.P.ptr;
    sid=ST_GetSID(serv,pElemType);
  }
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref)
  {
    static_assert(std::is_same<int,SaveIDType>::value,"WTF?");
    TServerPtr<IEsoteric>*serv=ref.P.ptr;
    sid=ST_GetSID(serv,pElemType);
  }
public:
  void LT_CheckSaveID(const SaveIDType&id,TType*pElemType)
  {
    if(!LT_Space.IsAllowed(id))
    {
      QapDebugMsg("bad id("+IToS(id)+")");
      Result=false;
      return;
    }
  }
public:
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,TSelfPtr<IEsoteric>&ref)
  {
    QapAssert(id);
    LT_CheckSaveID(id,pElemType);
    auto&item=LT_Space[id];
    QapAssert(item.ptr.IsNull());
    item.ptr.ptr=&ref.P;
    item.ptr.type=pElemType;
    ref.P.SaveID=id;
  }
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,TWeakPtr<IEsoteric>&ref)
  {
    static_assert(sizeof(id)==sizeof(void*),"WTF?");
    ref.P.ptr=get(id);
  }
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,THardPtr<IEsoteric>&ref)
  {
    static_assert(sizeof(id)==sizeof(void*),"WTF?");
    ref.P.ptr=get(id);
  }
};

class TSmartPtrSolver:public ISmartPtrSolver{
public:
  typedef TServerPtrSpace TSpace;
  typedef TClientPtrSolver::TwoMetaType TwoMetaType;
public:
  TSpace&Space;
  TType*pDeclareType;
  TType*pTType;
public:
  TSmartPtrSolver(TSpace&Space,TwoMetaType&tmt):Space(Space),pTType(tmt.pTType),pDeclareType(tmt.pDeclareType){};
public:
  void SolveClient(TType*pType,void*pValue)
  {
    TClientPtrSolver ClientSolver(Space,TwoMetaType(*this));
    TSmartPtrVisitor SPG(ClientSolver,pValue);
    pType->Use(SPG);
  }
public:
  //LoadTime
  TType*PreSolve(THardPtr<TType>&pInput,TType*pBaseType)
  {
    TType*pChunkType=nullptr;
    const int tid=int(pInput.P.ptr);
    bool flag=Space.CheckServTID(tid);
    QapAssert(flag);
    auto&item=Space[tid];
    QapAssert(item.ptr.type);
    bool good=item.ptr.type->IsBasedOn(pTType);
    if(!good)
    {
      QapDebugMsg("way is blocked");
      bool good=item.ptr.type->IsBasedOn(pDeclareType);
      QapAssert(good);
      if(!good)return pChunkType;
      auto*pdType=(DeclareType*)item.ptr.get();
      auto&ex=Space[pdType->Self];
      QapAssert(ex.ptr_lnk.type);
      QapAssert(ex.ptr_lnk.type->IsBasedOn(pTType));
      pChunkType=(TType*)ex.ptr_lnk.get();
    }else{
      pChunkType=(TType*)item.ptr.get();
    }
    QapAssert(pChunkType->IsBasedOn(pBaseType));
    return pChunkType;
  }
  //LoadTime
  TType*PreSolveEx(THardPtr<TType>&pInput)
  {
    TType*pChunkType=nullptr;
    const int tid=int(pInput.P.ptr);
    bool flag=Space.CheckServTID(tid);
    QapAssert(flag);
    auto&item=Space[tid];
    QapAssert(item.ptr.type);
    bool good=item.ptr.type->IsBasedOn(pTType);
    if(!good)
    {
      QapAssert(good);
      return nullptr;
    }else{
      pChunkType=(TType*)item.ptr.get();
    }
    return pChunkType;
  }
public:
  void ST_CheckSaveID(SaveIDType&id,TType*pElemType)
  {
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    QapAssert(item.ptr.ptr);
    int&sid=item.ptr.ptr->SaveID;
    if(!item.ptr.type->IsBasedOn(pElemType))
    {
      string pt_fn=item.ptr.type->GetFullName();
      string et_fn=pElemType->GetFullName();
      string msg="IsBasedOn(\""+pt_fn+"\",\""+et_fn+"\") == false";
      QapDebugMsg(msg);
    }
    QapAssert(&sid==&id);
  }
  int ST_GetSID(TServerPtr<IEsoteric>*serv,TType*pElemType)
  {
    if(serv)
    {
      auto&id=serv->SaveID;
      if(id)ST_CheckSaveID(id,pElemType);
      if(!id)
      {
        QapAssert(id);
      }
      return id;
    }
    return 0;
  }
public:
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref)
  {
    auto&id=ref.P.SaveID;
    ST_CheckSaveID(id,pElemType);
    QapAssert(&Space[id].ptr.ptr->SaveID==&id);
    sid=id;
    typedef std::remove_reference<decltype(id)>::type id_type;
    static_assert(std::is_same<id_type,SaveIDType>::value,"WTF?");
  }
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref)
  {
    static_assert(std::is_same<int,SaveIDType>::value,"WTF?");
    TServerPtr<IEsoteric>*serv=ref.P.ptr;
    sid=ST_GetSID(serv,pElemType);
  }
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref)
  {
    static_assert(std::is_same<int,SaveIDType>::value,"WTF?");
    TServerPtr<IEsoteric>*serv=ref.P.ptr;
    sid=ST_GetSID(serv,pElemType);
  }
public:
  void LT_CheckSaveID(const SaveIDType&id,TType*pElemType)
  {
    if(!Space.IsAllowed(id))
    {
      QapDebugMsg("bad id("+IToS(id)+")");
      Result=false;
      return;
    }
  }
public:
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,TSelfPtr<IEsoteric>&ref)
  {
    QapAssert(id);
    LT_CheckSaveID(id,pElemType);
    auto&item=Space[id];
    QapAssert(item.ptr.IsNull());
    item.ptr.ptr=&ref.P;
    item.ptr.type=pElemType;
    ref.P.SaveID=id;
  }
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,TWeakPtr<IEsoteric>&ref)
  {
    static_assert(sizeof(id)==sizeof(void*),"WTF?");
    if(ref.P.ptr){
      QapDebugMsg("new way detected");
      ref.P.ptr->Off(&ref.P);
    }
    ref.P.ptr=get(id);
  }
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,THardPtr<IEsoteric>&ref)
  {
    static_assert(sizeof(id)==sizeof(void*),"WTF?");
    if(ref.P.ptr){
      QapDebugMsg("new way detected");
      ref.P.ptr->Off(&ref.P);
    }
    ref.P.ptr=get(id);
  }
};

static TType*getSaveIDTypeFrom(TTypeVoidPtr*p)
{
  TType*pmPtrType=p->mPtr.Type.get();
  auto*pType=TTypeWeakPtr::UberCast(pmPtrType);
  QapAssert(pType);
  auto*pmSaveIDType=pType->mSaveID.Type.get();
  QapAssert(pmSaveIDType);
  return pmSaveIDType;
}

class TBinarySaver:public IVisitorRTTI{
public:
  typedef TBinarySaver SelfClass;
  typedef TQapIO Stream;
  typedef ScopeBot<false> StreamBot;//saver
public:
  ISmartPtrSolver&Solver;
  Stream&IO;
  void*pValue;
  TBinarySaver(ISmartPtrSolver&Solver,Stream&IO,void*pValue):Solver(Solver),IO(IO),pValue(pValue){}
  TBinarySaver(TBinarySaver&owner,void*pValue):Solver(owner.Solver),IO(owner.IO),pValue(pValue){}
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
      ex.Type->Use(next);
    }
  }
  void Do(TTypeSys*p)
  {
    p->BinIO->Save(IO,pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    auto Count=VecAPI->GetCount(pValue);
    {
      SelfClass next(*this,&Count);
      p->SizeType->Use(next);
    }
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(pValue,i);
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    for(int i=0;i<Count;i++){
      void*ptr=&((uchar*)pValue)[elemSize*i];
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    int id=0;
    Solver.GetSaveID(id,p->ElementType.get(),value);
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&type);
      pmTypeType->Use(next);
    }
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      StreamBot Stream(this->IO);
      SelfClass next(Solver,Stream.Stream,ptr);
      type->Use(next);
    }
  }
  void Do(TTypeWeakPtr*p)
  {
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    int id=0;
    Solver.GetSaveID(id,p->ElementType.get(),value);
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
  }
  void Do(TTypeHardPtr*p)
  {
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    int id=0;
    Solver.GetSaveID(id,p->ElementType.get(),value);
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
  }
  void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    if(!value.ptr&&value.type)
    {
      value.type=nullptr;
    }
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    if(!value.type)
    {
      QapAssert(!value.ptr);
      return;
    }
    if(true)
    {
      //hard code
      auto*value_type=value.type.get();
      auto*pSaveIDType=getSaveIDTypeFrom(p);
      int id=0;
      Solver.GetSaveID(id,value_type,value.ptr);
      {
        SelfClass next(*this,&id);
        pSaveIDType->Use(next);
      }
    }
    //TType*pmPtrType=p->mPtr.Type.get();
    //{
    //  SelfClass next(*this,&value.ptr);
    //  pmPtrType->Use(next);
    //}
    QapAssert(value.ptr.P.ptr);
  }
  void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    TType*pmObjectType=p->mObject.Type.get();
    {
      SelfClass next(*this,&value.object);
      pmObjectType->Use(next);
    }
    if(value.object)
    {
      TType*pmTypeType=p->mType.Type.get();
      {
        SelfClass next(*this,&value.type);
        pmTypeType->Use(next);
      }
      auto offset=value.offset;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      auto index=SubFieldsInfo::FieldInfoToIndex(object_type,Info);
      //TType*OffsetType=p->OffsetType.get();
      TType*pmIndexType=p->mIndex.Type.get();
      {
        SelfClass next(*this,&index);
        pmIndexType->Use(next);
      }
    }else{
      return;
    }
  }
public:
  template<template<class> class TEMPL,class U>
  void SaveSpyPtr(TEMPL<U>&value)
  {
    QapDebugMsg("no way");
    //static TBinIO<int>&pod=*THeadBinIO<int>::Get();
    //TServerPtr<U>*serv=value.P.ptr;
    //int id=0;
    //if(serv)
    //{
    //  id=serv->SaveID;
    //  if(!id)
    //    QapAssert(id);
    //}
    //pod.Save(IO,&id);
  }
};

namespace QapDetail{
  struct vftable{
    void*pArr[3];
  };
  struct TType{
    vftable*vfptr;
    unsigned int Self[sizeof(TSelfPtr<IEsoteric>)/sizeof(int)];
    unsigned int Env[sizeof(THardPtr<IEsoteric>)/sizeof(int)];
    unsigned int Factory[sizeof(THardPtr<IEsoteric>)/sizeof(int)];
    TTypeInfo Info;
  };
  static_assert(sizeof(QapDetail::TType)==sizeof(::TType),"bad");
  struct TTypeStruct:public TType{
    unsigned int SubType[sizeof(THardPtr<IEsoteric>)/sizeof(int)];
    unsigned int OwnType[sizeof(THardPtr<IEsoteric>)/sizeof(int)];
    vector<::TTypeStruct::Member> Members;
    vector<THardPtr<TType>> Nesteds;
    ::TTypeStruct::TExtInfo extInfo;
  };
  static_assert(sizeof(QapDetail::TTypeStruct)==sizeof(::TTypeStruct),"bad");
  static QapDetail::TTypeStruct var;
};

class TBinaryLoader:public IVisitorRTTI{
public:
  typedef TBinaryLoader SelfClass;
  typedef TQapIO Stream;
  typedef ScopeBot<true> StreamBot;//loader
public:
  ISmartPtrSolver&Solver;
  Stream&IO;
  void*pValue;
  TBinaryLoader(ISmartPtrSolver&Solver,Stream&IO,void*pValue):Solver(Solver),IO(IO),pValue(pValue){}
  TBinaryLoader(TBinaryLoader&owner,void*pValue):Solver(owner.Solver),IO(owner.IO),pValue(pValue){}
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
    }
    if(!Solver.Result)return;
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
      ex.Type->Use(next);
      if(!Solver.Result)break;
    }
  }
  void Do(TTypeSys*p)
  {
    p->BinIO->Load(IO,pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    IVectorAPI::SizeType Count=0;
    {
      SelfClass next(*this,&Count);
      p->SizeType->Use(next);
    }
    if(Count>(IO.IO.mem.size()-IO.IO.pos))
    {
      string fn=p->GetFullName();
      QapDebugMsg(fn+"::resize("+IToS(Count)+")");
    }
    VecAPI->SetCount(pValue,Count);
    TType*elemType=p->ElementType.get();
    for(IVectorAPI::SizeType i=0;i<Count;i++)
    {
      void*ptr=VecAPI->GetItem(pValue,i);
      SelfClass next(*this,ptr);
      elemType->Use(next);
      if(!Solver.Result)return;
    }
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    for(IVectorAPI::SizeType i=0;i<Count;i++)
    {
      void*ptr=&((uchar*)pValue)[elemSize*i];
      SelfClass next(*this,ptr);
      elemType->Use(next);
      if(!Solver.Result)return;
    }
  }
  void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    int id=0;
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
    Solver.SetSaveID(id,p->ElementType.get(),value);
  }
  virtual void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType)
    {
      QapAssert(p->ElementType);
      Solver.Result=false;
      return;
    }
    TType*elemType=p->ElementType.get();
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    if(value){
      value=nullptr;
    }
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&type);
      pmTypeType->Use(next);
    }
    if(!type)return;
    auto*ptype=Solver.PreSolve(type,elemType);
    {
      TRTTIProduct prod;
      prod.pType=ptype;
      prod.Init();
      value.Product.Memory=std::move(prod.Memory);
    }
    void*pvalue=value.get();
    {
      TQapIO Stream;
      Stream.LoadFrom(this->IO);
      SelfClass next(Solver,Stream,pvalue);
      ptype->Use(next);
    }
  }
  virtual void Do(TTypeWeakPtr*p)
  {
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    int id=0;
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
    Solver.SetSaveID(id,p->ElementType.get(),value);
  }
  virtual void Do(TTypeHardPtr*p)
  {
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    int id=0;
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
    Solver.SetSaveID(id,p->ElementType.get(),value);
  }
  virtual void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    if(!value.type.P.ptr)return;
    if(true)
    {
      //hard code
      auto*pSaveIDType=getSaveIDTypeFrom(p);
      int id=0;
      {
        SelfClass next(*this,&id);
        pSaveIDType->Use(next);
      }
      Solver.SetSaveID(id,pmTypeType,value.ptr);
    }
    //TType*pmPtrType=p->mPtr.Type.get();
    //{
    //  SelfClass next(*this,&value.ptr);
    //  pmPtrType->Use(next);
    //}
    QapAssert(value.ptr.P.ptr);
  }
  static bool LT_IsObjectValid(TVoidPtr&object)
  {
    const int oid=int(object.ptr.P.ptr);
    return oid;
  }
  virtual void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    TType*pmObjectType=p->mObject.Type.get();
    {
      SelfClass next(*this,&value.object);
      pmObjectType->Use(next);
    }
    if(!LT_IsObjectValid(value.object))return;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    auto index=-1;
    TType*pmIndexType=p->mIndex.Type.get();
    {
      SelfClass next(*this,&index);
      pmIndexType->Use(next);
    }
    {
      auto&object_type=value.object.type;
      //auto*pmObjectType=TTypeVoidPtr::UberCast(p->mObject.Type.get());
      //QapAssert(pmObjectType);
      //auto*pmObject_mType_Type=TTypeHardPtr::UberCast(pmObjectType->mType.Type.get());
      //QapAssert(pmObject_mType_Type);
      //auto*pmObject_mType_Type_elemtype=pmObject_mType_Type->ElementType.get();
      auto*pObjectType=Solver.PreSolveEx(object_type);
      {}
      auto&field_type=value.type;
      //auto*pmTypeType=TTypeHardPtr::UberCast(p->mType.Type.get());
      //QapAssert(pmTypeType);
      //auto*pmTypeType_elemtype=pmTypeType->ElementType.get();
      TType*pFieldType=Solver.PreSolveEx(field_type);
      {}
      const auto Info=SubFieldsInfo::IndexToFieldInfo(pObjectType,index); //TODO_Adler: need using index of DeclareType.
      if(Info.pType!=pFieldType)
      {
        //struct Goo{int x;float y;};
        //int Goo::*pX=&Goo::y;
        //int i=string("1");
        string base=pObjectType->GetFullName();
        string type1=(Info.pType?Info.pType->GetFullName():"void")+" "+base+"::*";
        string type2=pFieldType->GetFullName()+" "+base+"::*";
        QapDebugMsg("Index : "+IToS(index)+"\nOffset : "+IToS(Info.Offset)+"\ncannot convert from\n'"+type1+"'\nto\n'"+type2+"'");
        value.object.ptr.P.ptr=nullptr;
        value.object.type.P.ptr=nullptr;
        value.type.P.ptr=nullptr;
      }else{
        value.offset=Info.Offset;
      }
      //value.setIndex(pObjectType,pFieldType,index);
    }
    //value.getIndex();
    //TType*OffsetType=p->OffsetType.get();
  }
public:
  TType*UberPtrSolve(TWeakPtr<TType>&type)
  {
    QapDebugMsg("no way.");
    TType*result=nullptr;
    //const int tid=int(type.P.ptr);
    //bool flag=Space.CheckServTID(tid);
    //QapAssert(flag);
    //result=(TType*)Space.GetPtrByID(tid)->ptr;
    //QapAssert(result);
    return result;
  }
public:
  template<template<class> class TEMPL,class U>
  void LoadSpyPtr(TEMPL<U>&value)
  {
    QapDebugMsg("no way.");
    static TBinIO<int>&pod=*THeadBinIO<int>::Get();
    TServerPtr<U>*&serv=value.P.ptr;
    pod.Load(IO,&serv);
    //не пытайся тут решать клиентские указатели.
  }
};
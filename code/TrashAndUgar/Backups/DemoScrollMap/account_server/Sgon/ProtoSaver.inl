//pattern builder
class TProtoCodeGen{
public:
  string&content;
  string indent;
  string sep;
  vector<string> path;
  TProtoCodeGen(string&content):content(content){sep=" = ";}
public:
  virtual void Indent(){indent+="  ";}
  virtual void Outdent(){indent.resize(max(0,indent.size()-2));}
  //virtual void Print(string const&name,string const&data){s+=indent+name+sep+data+"\n";}
  virtual void AddLine(const string&data){content+=indent+data+"\n";}
  virtual void AddHead(const string&name){
    const string&back=this->back();
    AddLine(!back.empty()?(back+sep+name):(name));
  };
  virtual void push(const string&dir){path.push_back(dir);}
  virtual void push(){static const string empty;path.push_back(empty);}
  virtual void pop(){path.pop_back();}
  virtual const string back()const{return path.empty()?(string("")):path.back();}
};

#include "ProtoSmartPtrSolver.inl"

class TProtoSaver:public IVisitorRTTI{
public:
  typedef TServerPtrSpace TSpace;
  typedef TProtoSaver SelfClass;
  typedef TProtoCodeGen TSaveDev;
public:
  IProtoSmartPtrSolver&Solver;
  TSaveDev&dev;
  void*pValue;
public:
  TProtoSaver(IProtoSmartPtrSolver&Solver,TSaveDev&dev,void*pValue):Solver(Solver),dev(dev),pValue(pValue){}
  TProtoSaver(TProtoSaver&owner,void*pValue):Solver(owner.Solver),dev(owner.dev),pValue(pValue){}
public:
  void AddHead(TType*p)
  {
    string&fullname=p->GetFullName();
    dev.AddHead(fullname);
  }
  void AddData(TType*p,const string&data)
  {
    string&fullname=p->GetFullName();
    dev.AddHead(fullname+data);
  }
  void Do(TTypeStruct*p)
  {
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    if(!subtype&&arr.empty())
    {
      AddData(p,"()");
      return;
    }
    AddHead(p);
    DevScope devscope(dev);
    {
      if(subtype)
      {
        dev.push();
        SelfClass next(*this,pValue);
        subtype->Use(next);
        dev.pop();
      }
      auto&arr=p->Members;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        dev.push(ex.Name);
        SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
        ex.Type->Use(next);
        dev.pop();
      }
    }
  }
  void Do(TTypeSys*p)
  {
    if(p->TxtIO)
    {
      string value;
      p->TxtIO->Save(value,pValue);
      AddData(p,"("+value+")");
    }else{
      string fn=p->GetFullName();
      QapDebugMsg("Sys$$<"+fn+">::GetRTTI()->TxtIO == nullptr");
      AddData(p,"...error...");
    }
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    if(!Count)
    {
      AddData(p,"()");
      return;
    }
    TType*elemType=p->ElementType.get();
    AddHead(p);
    DevScope devscope(dev);
    for(int i=0;i<Count;i++){
      dev.AddLine("//"+IToS(i));
      void*ptr=VecAPI->GetItem(pValue,i);
      dev.push();
      SelfClass next(*this,ptr);
      elemType->Use(next);
      dev.pop();
      if(i+1!=Count)dev.AddLine(",");
    }
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    if(!Count)
    {
      AddData(p,"()");
      return;
    }
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    AddHead(p);
    DevScope devscope(dev);
    for(int i=0;i<Count;i++){
      dev.AddLine("//"+IToS(i));
      void*ptr=&((uchar*)pValue)[elemSize*i];
      dev.push();
      SelfClass next(*this,ptr);
      elemType->Use(next);
      dev.pop();
      if(i+1!=Count)dev.AddLine(",");
    }
  }
  void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    string str_value;
    Solver.GetSaveID(str_value,p->ElementType.get(),value);
    AddData(p,"("+str_value+")");
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
    if(!value)
    {
      AddData(p,"(nullptr)");
      return;
    }
    AddHead(p);
    DevScope devscope(dev);
    if(false)
    {
      dev.push(p->mType.Name);
      SelfClass next(*this,&type);
      pmTypeType->Use(next);
      dev.pop();
    }
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      dev.push("");
      SelfClass next(*this,ptr);
      type->Use(next);
      dev.pop();
    }
  }
  void Do(TTypeWeakPtr*p)
  {
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    string str_value;
    Solver.GetSaveID(str_value,p->ElementType.get(),value);
    AddData(p,"("+str_value+")");
  }
  void Do(TTypeHardPtr*p)
  {
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    string str_value;
    Solver.GetSaveID(str_value,p->ElementType.get(),value);
    AddData(p,"("+str_value+")");
  }
  void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    if(value.ptr)
    {
      QapAssert(value.type);
      TType*pmTypeType=p->mType.Type.get();
      AddHead(p);
      DevScope devscope(dev);
      {
        dev.push(p->mType.Name);
        SelfClass next(*this,&value.type);
        pmTypeType->Use(next);
        dev.pop();
      }
      {
        string str_value_ptr;
        dev.push(p->mPtr.Name);
        Solver.GetSaveID(str_value_ptr,value.type.get(),value.ptr);
        dev.AddHead("("+str_value_ptr+")");
        dev.pop();
      }
    }else{
      AddData(p,"(nullptr)");
    }
  }
  void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    if(value)
    {
      AddHead(p);
      DevScope devscope(dev);
      TType*pmObjectType=p->mObject.Type.get();
      {
        dev.push(p->mObject.Name);
        SelfClass next(*this,&value.object);
        pmObjectType->Use(next);
        dev.pop();
      }
      TType*pmTypeType=p->mType.Type.get();
      {
        dev.push(p->mType.Name);
        SelfClass next(*this,&value.type);
        pmTypeType->Use(next);
        dev.pop();
      }
      auto offset=value.offset;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      auto index=SubFieldsInfo::FieldInfoToIndex(object_type,Info);
      //TType*OffsetType=p->OffsetType.get();
      TType*pmIndexType=p->mIndex.Type.get();
      {
        dev.push(p->mIndex.Name);
        SelfClass next(*this,&index);
        pmIndexType->Use(next);
        dev.pop();
      }
    }else{
      AddData(p,"(nullptr)");
    }
  }
  void Do(TTypeFactory*p)
  {
    QapDebugMsg("under construction");
  }
public:
  //template<template<class> class TEMPL,class U>
  //string GetSpyPtr(TEMPL<U>&value)
  //{
  //  //static TBinIO<int> pod;
  //  TServerPtr<U>*serv=value.P.ptr;
  //  return std::move(GetServ(serv));
  //}
  //template<class U>
  //string GetSelfPtr(TSelfPtr<U>&value)
  //{
  //  TServerPtr<U>*serv=&value.P;
  //  return GetServ(serv);
  //}
  //inline string GetServNameByID(int id)
  //{
  //  const string&name=Space[id].name;
  //  //string comment;
  //  if(name.empty()){
  //    return IToH(id);
  //  }else{
  //    return name;
  //  }
  //}
  //string GetServ(nullptr_t)
  //{
  //  int id=0;
  //  return std::move(GetServNameByID(id));
  //}
  //template<class U>
  //string GetServ(TServerPtr<U>*serv)
  //{
  //  int id=0;
  //  if(serv)
  //  {
  //    id=serv->SaveID;
  //    if(!id)
  //    {
  //      auto&arr=TFactory<void>::GetFactorys();
  //      for(int i=0;i<arr.size();i++)
  //      {
  //        auto&ex=arr[i];
  //        void*ptr=ex.get();
  //        if(ptr==serv->ptr)
  //        {
  //          QapDebugMsg("good news");
  //        }
  //      }
  //    }
  //    if(!id)
  //    {
  //      QapAssert(id);
  //      id=-1;
  //    }
  //  }
  //  return std::move(GetServNameByID(id));
  //}
  struct DevScope
  {
    TSaveDev&dev;
    DevScope(TSaveDev&dev):dev(dev)
    {
      dev.AddLine("{");
      dev.Indent();
    }
   ~DevScope()
    {
      dev.Outdent();
      dev.AddLine("}");
    }
  };
};
struct IndirectProtoSaver
{
  typedef TProtoCodeGen TSaveDev;
  static void DoSave(IProtoSmartPtrSolver&Solver,TSaveDev&dev,TType*pType,void*pValue)
  {
    TProtoSaver PS(Solver,dev,pValue);
    pType->Use(PS);
  }
};
//class IndirectProtoSaver{
//public:
//  typedef IndirectProtoSaver SelfClass;
//  typedef TServerPtrSpace TSpace;
//  typedef TProtoCodeGen TSaveDev;
//  //typedef ScopeBot<false> StreamBlob;
//public:
//  IEnvRTTI&Env;
//  TSpace&Space;
//  TType*SmartType;
//  TType*IntType;
//  IndirectProtoSaver(IEnvRTTI&Env,TSpace&Space):Env(Env),Space(Space){
//    //SmartType=Sys$$<TAutoPtr<TType>>::GetRTTI(Env)->SmartType.get();
//    //IntType=Sys$$<int>::GetRTTI(Env);
//  }
//public:
//  static void DoSave(IProtoSmartPtrSolver&Solver,TSaveDev&dev,TType*pType,void*pValue){
//    TProtoSaver PS(Solver,dev,pValue);
//    pType->Use(PS);
//  }
//  //template<class IndirectSaver>
//  static void DoSave(SelfClass&Ind,TSaveDev&dev,TType*pType,void*pValue){
//    QapAssert("deprecated");
//    //TProtoSaver PS(Ind.Space,dev,pValue);
//    //pType->Use(PS);
//  }
//};

//template<class TYPE>
//inline static void ProtoSaveToFile(TEnvRTTI&Env,const string&fn,const string&name,TAutoPtr<TYPE>&Value)
//{
//  TQapIO Stream;
//  ProtoSaveToStream(Env,Stream,name,Value);
//  Stream.IO.SaveFile(fn);
//}
//
//template<class QAP_RTTI>
//inline static void ProtoSaveToFileEx(QAP_RTTI&Env,const string&fn,const string&name,TType*pType,void*pValue)
//{
//  TQapIO Stream;
//  ProtoSaveToStreamEx(Env,Stream,name,pType,pValue);
//  Stream.IO.SaveFile(fn);
//}
//
//template<class TYPE>
//inline static void ProtoSaveToStream(TEnvRTTI&Env,TQapIO&Stream,const string&name,TAutoPtr<TYPE>&value)
//{
//  typedef TAutoPtr<TYPE> type;
//  TType*pType=Sys$$<type>::GetRTTI(Env);
//  auto*pValue=&value;
//  ProtoSaveToStreamEx(Env,Stream,name,pType,pValue);
//}
//
//template<class QAP_RTTI>
//inline static void ProtoSaveToStreamEx(QAP_RTTI&Env,TQapIO&Stream,const string&name,TType*pType,void*pValue)
//{
//  string&mem=Stream.IO.mem;
//  TProtoCodeGen dev(mem);
//  TServerPtrSpace Space;
//  TClientPtrCounter ClientCounter(Env,Space);
//  DependsSolver DS(Env,ClientCounter);
//  IndirectProtoSaver Ind(Env,Space);
//  EnvAdapter::Go(Space,Env);
//  if(true)
//  {
//    GrabServerPtr(Space,pType,pValue,true);
//    ClientMarker(ClientCounter,pType,pValue);
//    MetaMarker(Space,pType,pValue);
//    Space.SolveDepends(DS);
//    Space.Repack();
//    Ind.SaveMetaSpace(dev);
//    Ind.SaveSpec(dev);
//    IndirectProtoSaver::DoSave(Ind,dev,pType,pValue);
//  }else{}
//}
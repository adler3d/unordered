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

class TConservationMachine;

struct IUberLoadDevice
{
  typedef IQapRawObject::TRawPtr TRawPtr;
  typedef TConservationMachine TMachine;
  virtual bool DoLoad(TMachine&machine,TRawPtr&raw_ptr){return false;}
  virtual bool Load(TMachine&machine,TRawPtr&raw_ptr){return false;}
};

struct IUberSaveDevice
{
  typedef IQapRawObject::TRawPtr TRawPtr;
  typedef TConservationMachine TMachine;
  virtual void DoSave(TMachine&machine,TRawPtr&raw_ptr){}
  virtual void Save(TMachine&machine,TRawPtr&raw_ptr){}
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

static TType*getSaveIDTypeFrom(TTypeVoidPtr*p)
{
  TType*pmPtrType=p->mPtr.Type.get();
  auto*pType=TTypeWeakPtr::UberCast(pmPtrType);
  QapAssert(pType);
  auto*pmSaveIDType=pType->mSaveID.Type.get();
  QapAssert(pmSaveIDType);
  return pmSaveIDType;
}

class TJsonCodeGen{
public:
  string&content;
  string indent;
  string sep;
  vector<string> path;
  TJsonCodeGen(string&content):content(content){sep=":";}
public:
  virtual void Indent(){indent+="  ";}
  virtual void Outdent(){indent.resize(max(0,indent.size()-2));}
  virtual void AddLine(const string&data){content+=indent+data+"\n";}
  virtual void AddHead(const string&name){
    const string&back=this->back();
    if(back.empty()&&name.empty())return;
    AddLine(!back.empty()?(back+sep+name):(name));
  };
  virtual void push(TType*p){
    push(p->GetFullName());
  }
  virtual void push(const string&dir){
    CppString str=dir;
    path.push_back("\""+str.data+"\"");
  }
  virtual void push(){static const string empty;path.push_back(empty);}
  virtual void pop(){path.pop_back();}
  virtual const string back()const{return path.empty()?(string("")):path.back();}
};

//static string g_all;

class TJsonSaver:public IVisitorRTTI{
public:
  typedef TJsonSaver SelfClass;
  typedef TJsonCodeGen TSaveDev;
  typedef ScopeBot<false> StreamBot;//saver
public:
  struct DevScope
  {
    TSaveDev&dev;
    bool square;
    bool enabled;
    DevScope(TSaveDev&dev,bool square=0,bool enabled=true):dev(dev),square(square),enabled(enabled)
    {
      if(!enabled)return;
      dev.AddLine(square?"[":"{");
      dev.Indent();
    }
   ~DevScope()
    {
      if(!enabled)return;
      dev.Outdent();
      dev.AddLine(square?"]":"}");
    }
  };
public:
  ISmartPtrSolver&Solver;
  TSaveDev&dev;
  void*pValue;
  bool hack_flag;
  TJsonSaver(ISmartPtrSolver&Solver,TSaveDev&dev,void*pValue):Solver(Solver),dev(dev),pValue(pValue),hack_flag(false){}
  TJsonSaver(TJsonSaver&owner,void*pValue):Solver(owner.Solver),dev(owner.dev),pValue(pValue),hack_flag(false){}
public:
  void Do(TTypeStruct*p)
  {
    auto*pSubtype=p->SubType.get();
    auto&arr=p->Members;
    if(!pSubtype&&arr.empty())
    {
      AddData(p,"{}");
      return;
    }
    if(!hack_flag)dev.AddHead("");
    DevScope devscope(dev,0,!hack_flag);
    {
      dev.push(p);
      dev.AddHead("");
      dev.push();
      DevScope devscope(dev);
      if(pSubtype)
      {
        //dev.push("\""+pSubtype->GetFullName()+"\"");
        SelfClass next(*this,pValue);next.hack_flag=true;
        pSubtype->Use(next);
        //dev.pop();
        if(!arr.empty())AddText(",");
      }
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
        dev.push(ex.Name);
        ex.Type->Use(next);
        if(i+1!=arr.size())AddText(",");
        dev.pop();
      }
      dev.pop();
      dev.pop();
    }
  }
public:
  struct t_func{
    static void get_int(string&out,void*pValue){
      int&ref=*(int*)pValue;
      out=IToS(ref);
    }
    static void get_string(string&out,void*pValue){
      string&ref=*(string*)pValue;
      CppString cpp=ref;
      out="\""+cpp.data+"\"";
    }
    static string FToSex(const real&val){char c[64];{_snprintf_s(c,32,32,"%e",val);}return string(c);}
    static void get_real(string&out,void*pValue){
      real&ref=*(real*)pValue;
      out=FToSex(ref);
    }
    static void get_bool(string&out,void*pValue){
      bool&ref=*(bool*)pValue;
      out=BToS(ref);
    }
    static void get_default(string&out,void*pValue){
      out="...default...";
    }
  };
  typedef decltype(&t_func::get_int) tproc;
  tproc GetFuncFromSysTypeName(const string&type){
    //if(type=="int"){return t_func::get_int;}
    #define F(TYPE)if(type==#TYPE){return t_func::get_##TYPE;}
    F(int)F(string)F(real)F(bool)
    #undef F
    return t_func::get_default;
  }
public:
  void AddHead(TType*p){
    dev.AddHead("\""+p->GetFullName()+"\":");
  }
  void AddData(TType*p,const string&data){
    dev.AddHead("{\""+p->GetFullName()+"\":"+data+"}");
  }
  void AddText(const string&text){
    dev.AddLine(text);
  }
  void Do(TTypeSys*p)
  {
    string fn=p->GetFullName();
    auto*func=GetFuncFromSysTypeName(fn);
    string out;
    func(out,pValue);
    //g_all+=out+"\n";
    AddData(p,out);
    //p->BinIO->Save(IO,pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*pVecAPI=p->VecAPI.get();
    int Count=pVecAPI->GetCount(pValue);
    if(!Count)
    {
      AddData(p,"{}");
      return;
    }
    dev.AddHead("");
    DevScope devscope(dev);
    {
      dev.push(p);
      dev.AddHead("");
      dev.push();
      DevScope devscope(dev);
      {
        SelfClass next(*this,&Count);
        dev.push("count");
        p->SizeType->Use(next);
        dev.pop();
      }
      dev.AddLine(",");
      dev.AddHead("\"items\":");
      {
        DevScope devscope(dev,true);
        TType*elemType=p->ElementType.get();
        for(int i=0;i<Count;i++){
          void*ptr=pVecAPI->GetItem(pValue,i);
          dev.push();
          SelfClass next(*this,ptr);
          elemType->Use(next);
          dev.pop();
          if(i+1!=Count)AddText(",");
        }
      }
      dev.pop();
      dev.pop();
    }
  }
  void Do(TTypeSelfPtr*p)
  {
    dev.AddHead("");
    DevScope devscope(dev);
    dev.push(p);
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    int id=0;
    Solver.GetSaveID(id,p->ElementType.get(),value);
    {
      SelfClass next(*this,&id);
      p->mSaveID.Type->Use(next);
    }
    dev.pop();
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    DevScope devscope(dev);
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*pmTypeType=p->mType.Type.get();
    {
      dev.push("type");
      SelfClass next(*this,&type);
      pmTypeType->Use(next);
      dev.pop();
    }
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      dev.AddLine(",");
      dev.push("object");
      auto&Stream=this->dev;
      //StreamBot Stream(this->IO);
      SelfClass next(Solver,Stream,ptr);
      type->Use(next);
      dev.pop();
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
    ref.P.ptr=get(id);
  }
  //LoadTime
  void SetSaveID(const SaveIDType&id,TType*pElemType,THardPtr<IEsoteric>&ref)
  {
    static_assert(sizeof(id)==sizeof(void*),"WTF?");
    ref.P.ptr=get(id);
  }
};

class EnvDefEntryPoint{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefEntryPoint)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefEntryPoint
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefEntryPoint
public:
  static void SysHasSelf();
};

class EnvDefTypeSymbol{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypeSymbol)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(EnvDefEntryPoint,Decl,DEF,$,$)\
ADDVAR(string,Name,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypeSymbol
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypeSymbol
};

class EnvDefTypeStr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypeStr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(EnvDefTypeSymbol,Decl,DEF,$,$)\
ADDVAR(EnvDefEntryPoint,Impl,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypeStr
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypeStr
};

class EnvDefTypePtr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypePtr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,Decl,DEF,$,$)\
ADDVAR(EnvDefEntryPoint,Impl,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypePtr
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypePtr
};

class FullDeclareEnvRTTI{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FullDeclareEnvRTTI)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(DeclareEnvRTTI,DeclEnv,DEF,$,$)\
ADDVAR(vector<EnvDefTypePtr>,ImplPtrs,DEF,$,$)\
ADDEND()
//=====+>>>>>FullDeclareEnvRTTI
#include "QapGenStruct.inl"
//<<<<<+=====FullDeclareEnvRTTI
public:
  typedef vector<EnvDefTypePtr> TImplPtrs;
public:
  void MakeImplPtrs()
  {
    auto&arr=DeclEnv.Arr;
    ImplPtrs.resize(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto*pdType=arr[i].get();
      ImplPtrs[i].Decl=pdType;
      string fn=pdType->GetFullName();
      int gg=1;
    }
  }
  void AddDeclToSpace(TServerPtrSpace&Space,TServerPtrSpace&SpaceFFDE)
  {
    QapDebugMsg("imposible");
    //auto&arr=DefPtrs;
    //for(int i=0;i<arr.size();i++)
    //{
    //  auto&ex=arr[i];
    //  Space[ex.Decl->Self];
    //}
  }
  void AddImplToSpace(TServerPtrSpace&Space,TServerPtrSpace&SpaceFFDE)
  {
    auto&arr=ImplPtrs;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&item=SpaceFFDE.AddExt(EnvAdapter::get(ex.Impl.Self),nullptr,"Sys$$<"+ex.Decl->GetFullName()+">::GetRTTI()");
      auto&jtem=Space[Space[ex.Decl->Self].ptr_lnk.ptr->SaveID];
      QapAssert(item.name==jtem.name);
      item.ptr_lnk=jtem.ptr;
    }
  }
};

class TQapBinaryObject{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TQapBinaryObject)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,SpaceSize,SET,0,$)\
ADDVAR(vector<EnvDefTypeStr>,MetaSpec,DEF,$,$)\
ADDVAR(FullDeclareEnvRTTI,FullDeclEnv,DEF,$,$)\
ADDVAR(THardPtr<TType>,RootType,DEF,$,$)\
ADDEND()
//=====+>>>>>TQapBinaryObject
#include "QapGenStruct.inl"
//<<<<<+=====TQapBinaryObject
public:
  typedef vector<EnvDefTypeStr> TMetaSpec;
  typedef TVoidPtr::TRawPtr TRawPtr;
  struct TRawPtrs
  {
    TRawPtr SpaceSize;
    TRawPtr MetaSpec;
    TRawPtr FullDeclEnv;
    TRawPtr RootType;
    TRawPtr Root;
  public:
    void Init(IEnvRTTI&Env,TQapBinaryObject&qbo)
    {
      #define F(FIELD)this->FIELD.set(Env,qbo.FIELD);
      F(SpaceSize);F(MetaSpec);F(FullDeclEnv);F(RootType);
      #undef F
      Root.setZero();
    }
  };
};

class TMegaConvBase{
public:
  #pragma region DEF_PRO_LIST_DECLARE_AND_TTYPE
  //---
  #define DEF_PRO_LIST_DECLARE_AND_TTYPE(ADDBEG,ADDFOO,ADDEND)\
  ADDBEG()\
  ADDFOO(DeclareTypeSys,TTypeSys)\
  ADDFOO(DeclareTypeSelfPtr,TTypeSelfPtr)\
  ADDFOO(DeclareTypeAutoPtr,TTypeAutoPtr)\
  ADDFOO(DeclareTypeWeakPtr,TTypeWeakPtr)\
  ADDFOO(DeclareTypeHardPtr,TTypeHardPtr)\
  ADDFOO(DeclareTypeVoidPtr,TTypeVoidPtr)\
  ADDFOO(DeclareTypeFieldPtr,TTypeFieldPtr)\
  ADDFOO(DeclareTypeVector,TTypeVector)\
  ADDFOO(DeclareTypeStruct,TTypeStruct)\
  ADDEND()
  //---
  template<class TYPE>
  struct TTypeToDeclare{};
  //---
  #define F()
  #define ADDFOO(DEST,SOURCE)template<>struct TTypeToDeclare<SOURCE>{typedef DEST type;};;
  DEF_PRO_LIST_DECLARE_AND_TTYPE(F,ADDFOO,F);
  #undef ADDFOO
  #undef F
  //---
  template<class TYPE>
  struct DeclareToTType{};
  //---
  #define F()
  #define ADDFOO(SOURCE,DEST)template<>struct DeclareToTType<SOURCE>{typedef DEST type;};;
  DEF_PRO_LIST_DECLARE_AND_TTYPE(F,ADDFOO,F);
  #undef ADDFOO
  #undef F
  //---
  template<class,class>
  struct InpTypeToOutType{};
  //---
  template<>
  struct InpTypeToOutType<DeclareType,TType>{
    template<class TYPE>
    struct Conv{typedef typename DeclareToTType<TYPE>::type type;};
  };
  template<>
  struct InpTypeToOutType<TType,DeclareType>{
    template<class TYPE>
    struct Conv{typedef typename TTypeToDeclare<TYPE>::type type;};
  };
  //---
  template<class FUNC>
  static void DeclareVisitAll(IEnvRTTI&Env,FUNC&func)
  {
    #define F()
    #define ADDFOO(DECLARE,TYPE)func(Sys$$<DECLARE>::GetRTTI(Env),Sys$$<TYPE>::GetRTTI(Env));
    DEF_PRO_LIST_DECLARE_AND_TTYPE(F,ADDFOO,F);
    #undef ADDFOO
    #undef F
  }
  //---
  #undef DEF_PRO_LIST_DECLARE_AND_TTYPE
  //---
  #pragma endregion
public:
};

class TMegaSolver:public TMegaConvBase{
public:
  template<class TYPE>
  static void DoPreConv(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
  {
    auto*pOutput=Ref.build<TTypeToDeclare<TYPE>::type>(Solver.Env);
    TType*pInp=p;
    DeclareType*pOut=pOutput;
    Solver.Solve(pInp->Self,pOut->Self,Ref.Product.pType.get());
  }
  template<class TYPE>
  static void CallDoConv(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
  {
    auto*pOut=(TTypeToDeclare<TYPE>::type*)Ref.get();
    Solver.DoConv(pOut,p);
  }
public:
  template<class TYPE>
  struct ProxyDoPreConv
  {
    static void call(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
    {
      DoPreConv(Solver,Ref,p);
    }
  };
  template<class TYPE>
  struct ProxyCallDoConv
  {
    static void call(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
    {
      CallDoConv(Solver,Ref,p);
    }
  };
  template<template<class> class ConvertFunc>
  class TMegaConvertVisitor:public IVisitorRTTI{
  public:
    TMegaSolver&Solver;
    TAutoPtr<DeclareType>&Ref;
    TMegaConvertVisitor(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref):Solver(Solver),Ref(Ref){}
  public:
    template<class TYPE>
    void ProxyFunc(TYPE*p)
    {
      ConvertFunc<TYPE>::call(Solver,Ref,p);
    }
  public:
    void Do(TTypeStruct*p){ProxyFunc(p);}
    void Do(TTypeSys*p){ProxyFunc(p);}
    void Do(TTypeVector*p){ProxyFunc(p);}
    void Do(TTypeSelfPtr*p){ProxyFunc(p);}
    void Do(TTypeAutoPtr*p){ProxyFunc(p);}
    void Do(TTypeWeakPtr*p){ProxyFunc(p);}
    void Do(TTypeHardPtr*p){ProxyFunc(p);}
    void Do(TTypeVoidPtr*p){ProxyFunc(p);}
    void Do(TTypeFieldPtr*p){ProxyFunc(p);}
    void Do(TTypeFactory*p){QapDebugMsg("no way.");}
  };
public:
  typedef TServerPtrSpace TSpace;
  IEnvRTTI&Env;
  TSpace&Space;
  TMegaSolver(IEnvRTTI&Env,TSpace&Space):Env(Env),Space(Space){}
public:
  void PreConv(TType*pInp,TAutoPtr<DeclareType>&ref)
  {
    //pInp->Use(Conv); создаЄт нужный объект и вызывает нужный нам DoConv
    ref=nullptr;
    TMegaConvertVisitor<ProxyDoPreConv> Conv(*this,ref);
    pInp->Use(Conv);
  }
  void UseConv(TType*pInp,TAutoPtr<DeclareType>&ref)
  {
    //pInp->Use(Conv); вызывает нужный нам DoConv
    TMegaConvertVisitor<ProxyCallDoConv> Conv(*this,ref);
    pInp->Use(Conv);
  }
public:
  void DoConv(DeclareTypeSys*pOut,TTypeSys*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    pOut->FullName=pInp->GetFullName();
  }
  void DoConv(DeclareTypeSelfPtr*pOut,TTypeSelfPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeAutoPtr*pOut,TTypeAutoPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeWeakPtr*pOut,TTypeWeakPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeHardPtr*pOut,TTypeHardPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeVoidPtr*pOut,TTypeVoidPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
  }
  void DoConv(DeclareTypeFieldPtr*pOut,TTypeFieldPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
  }
  void DoConv(DeclareTypeVector*pOut,TTypeVector*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeStruct*pOut,TTypeStruct*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    pOut->Name=pInp->Info.Name;
    Solve(pInp->SubType.get(),pOut->SubType);
    Solve(pInp->OwnType.get(),pOut->OwnType);
    Solve(pInp->Members,pOut->Members);
  }
public:
  void Solve(TTypeStruct::Member*pInp,DeclareMember*pOut)
  {
    pOut->Number=pInp->Number;
    pOut->Name=pInp->Name;
    Solve(pInp->Type.get(),pOut->Type);
    pOut->Mode=pInp->Mode;
    pOut->Value=pInp->Value;
  }
  void Solve(vector<TTypeStruct::Member>&InpArr,vector<DeclareMember>&OutArr)
  {
    OutArr.resize(InpArr.size());
    for(int i=0;i<InpArr.size();i++)
    {
      auto&ex=InpArr[i];
      auto&ax=OutArr[i];
      Solve(&ex,&ax);
    }
  }        
  void Solve(TType*pInp,TWeakPtr<DeclareType>&out)
  {
    //pInp - оригинал
    //out - возможо пустышка.
    if(!pInp){
      out=nullptr;
      return;
    }
    int id=pInp->Self.P.SaveID;
    QapAssert(id);
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    void*ptr=item.ptr.get();
    QapAssert(ptr==pInp);
    QapAssert(item.ptr_lnk.IsValid());
    out=(DeclareType*)item.ptr_lnk.get();
  }
  void Solve(const TSelfPtr<TType>&inp,TSelfPtr<DeclareType>&out,TType*pOutType=nullptr)
  {
    int id=inp.P.SaveID;
    QapAssert(id);
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    void*ptr=item.ptr.ptr;
    auto*pInp=&inp;
    QapAssert(ptr==pInp);
    bool ptr_lnk_is_null=item.ptr_lnk.IsNull();
    if(!ptr_lnk_is_null)
    {
      bool f[]={
        item.ptr_lnk.ptr==(void*)&out,
        (!pOutType&&bool(item.ptr_lnk.type)),
        (item.ptr_lnk.type==pOutType),
        item.ptr_lnk.get()->Self.P.SaveID!=id
      };
      bool flag=f[0]&&(f[1]||f[2])&&f[3];
      if(flag)return;
      QapDebugMsg("WTF?");
      return;
    }
    QapAssert(ptr_lnk_is_null);
    QapAssert(!out.P.SaveID);
    item.ptr_lnk.ptr=EnvAdapter::get(out);
    item.ptr_lnk.type=pOutType;
  }
};

struct TSpaceDependsTools{
public:
  typedef TServerPtrSpace TSpace;
  typedef vector<std::pair<TType*,TType*>> TDeclareTypeArray;
  IEnvRTTI&Env;
  TSpace&Space;
  TMegaSolver Solver;
  DeclareEnvRTTI DeclEnv;
  //vector<TAutoPtr<DeclareType>> DeclArr;
  TDeclareTypeArray DeclareTypeArray;
  TType*pTType;
  TType*pTypeSys;
  TType*pDeclareType;
  DeclareType*pdTType;
  DeclareType*pdDeclareType;
  TSpaceDependsTools(IEnvRTTI&Env,TSpace&Space):Env(Env),Space(Space),Solver(Env,Space)
  {
    Prepare(Env);
  }
public:
  typedef TClientPtrSolver::TwoMetaType TwoMetaType;
public:
  TwoMetaType get_tmt()const
  {
    TwoMetaType tmt;
    tmt.pTType=pTType;
    tmt.pDeclareType=pDeclareType;
    return tmt;
  }
  TwoDeclareMetaType get_tdmt()
  {
    TwoDeclareMetaType tdmt;
    tdmt.pdTType=pdTType;
    tdmt.pdDeclareType=pdDeclareType;
    return tdmt;
  }
public:
  void PrepareDeclareTypeArray()
  {
    auto&arr=DeclareTypeArray;
    auto addfunc=[&arr](TType*pDeclareType,TType*pTType)
    {// problem("error C2872: <lambda0>:") => solution("MSVS2010 + VS10sp1-KB983509.exe")
      typedef std::pair<TType*,TType*> pair;
      pair tmp(pDeclareType,pTType);
      arr.push_back(std::move(tmp));
    };
    addfunc(pDeclareType,pTType);
    TMegaSolver::DeclareVisitAll(Env,addfunc);
  }
  void Prepare(IEnvRTTI&Env)
  {
    pTypeSys=Sys$$<TTypeSys>::GetRTTI(Env);
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    pdTType=nullptr;
    pdDeclareType=nullptr;
    PrepareDeclareTypeArray();
  }
  void PrepareEx()
  {
    auto Get=[this](TType*pType)->DeclareType*
    {
      QapAssert(pType);
      auto&item=Space[pType->Self];
      bool good=item.ptr_lnk.type->IsBasedOn(pDeclareType);
      QapAssert(good);
      auto*pOut=(DeclareType*)item.ptr_lnk.get();
      QapAssert(pOut);
      return pOut;
    };
    pdTType=Get(pTType);
    pdDeclareType=Get(pDeclareType);
  }
  void ExcludeInternal()
  {
    auto&arr=Space.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=ex.ptr.type;
      if(!pType)continue;
      bool f[]=
      {
        pType->IsBasedOn(pTypeSys),
        pType->IsBasedOn(pDeclareType)
      };
      if(!f[0]&&!f[1])continue;
      ex.passed=true;//помечаем пройденым, ибо системный тип.
    }
  }
  void GuardTheDeclare()
  {
    auto&Space=this->Space;
    auto&arr=DeclareTypeArray;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pDeclareType=ex.first;
      auto*pTType=ex.second;
      auto pass=[&Space](TType*pType,bool inc)->void
      {
        auto&item=Space[pType->Self];
        item.passed=true;
        auto*p=(DeclareType*)item.ptr_lnk.get();
        auto&ex=Space[p->Self];
        if(inc)ex.count++;
        ex.passed=true;
      };
      pass(pDeclareType,true);
      pass(pTType,true);
    }
  }
  void BuildProxy()
  {
    BuildProxyEx(Solver,Space,TwoMetaType(*this),DeclEnv);
  }
  static void BuildProxyEx(TMegaSolver&Solver,TSpace&Space,TwoMetaType&tmt,DeclareEnvRTTI&DeclEnv)
  {
    FirstPass(Solver,Space,tmt,DeclEnv);
    SecondPass(Solver,Space,tmt,DeclEnv);
    //AddToSpace();
  }
  typedef TSpaceDependsTools SelfClass;
  static void FirstPass(TMegaSolver&Solver,TSpace&Space,TwoMetaType&tmt,DeclareEnvRTTI&DeclEnv)
  {
    auto*pTType=tmt.pTType;
    auto&DeclArr=DeclEnv.Arr;
    TAutoPtr<DeclareType> DeclNull;
    auto&arr=Space.Arr;
    int cur_size=arr.size();
    QapAssert(DeclArr.empty());
    DeclArr.reserve(cur_size);
    for(int i=0;i<cur_size;i++)
    {
      auto&ex=arr[i];
      auto*pType=TTypeStruct::UberCast(ex.ptr.type);
      if(!pType)continue;
      if(!EnvAdapter::IsBasedOn(pType,pTType))continue;
      auto*pValue=(TType*)ex.ptr.get();
      DeclArr.push_back(std::move(DeclNull));
      auto&back=DeclArr.back();
      Solver.PreConv(pValue,back);
      {
        auto&item=Space.AddExt(EnvAdapter::get(back.get()->Self),back.Product.pType.get());
        item.name="Def$$<"+pValue->GetFullName()+">::GetRTTI()";
        item.ptr_lnk.ptr=EnvAdapter::get(pValue->Self);
        item.ptr_lnk.type=pType;
      }
    }
  }
  static void SecondPass(TMegaSolver&Solver,TSpace&Space,TwoMetaType&tmt,DeclareEnvRTTI&DeclEnv)
  {
    auto*pTType=tmt.pTType;
    auto&DeclArr=DeclEnv.Arr;
    int j=0;
    auto&arr=Space.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=TTypeStruct::UberCast(ex.ptr.type);
      if(!pType)continue;
      if(!EnvAdapter::IsBasedOn(pType,pTType))continue;
      auto*pValue=(TType*)ex.ptr.get();
      auto&ref=DeclArr[j++];
      Solver.UseConv(pValue,ref);
    }
  }/*
  void AddToSpace()
  {
    QapDebugMsg("no way.");
    auto&arr=DeclEnv.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&item=Space.AddExt(EnvAdapter::get(ex.get()->Self),ex.Product.pType.get());
      item.name="Def$$<"+ex->GetFullName()+">::GetRTTI()";
    }
  }*/
  void RemoveFromSpace(TSpace&Space)
  {
    QapDebugMsg("no way.");
    //auto&arr=DeclEnv.Arr;
    //for(int i=0;i<arr.size();i++)
    //{
    //  auto&ex=arr[i];
    //  auto&item=Space[ex->Self];
    //  Space.Del(item);
    //}
  }
  void MegaPass()
  {
    auto&arr=DeclEnv.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pValue=ex.get();
      auto&item=Space[pValue->Self];
      bool f[]=
      {
        pValue->IsBasedOn(pdTType),
        pValue->IsBasedOn(pdDeclareType),
      };
      item.system=f[0]||f[1];
    }
  }
};

struct TConservationMachine 
{
  typedef IQapRawObject::TRawPtr TRawPtr;
  typedef TServerPtrSpace TSpace;
  typedef TQapBinaryObject::TRawPtrs TRawPtrs;
  TSpace Space;
  TSpaceDependsTools Tools;
  TClientPtrVcbCounter ClientCounter;
  TClientPtrVisitor ClientVisitor;
  DependsSolver DS;
  TQapBinaryObject&qbo;
  TRawPtrs ptrs;
  TConservationMachine(IEnvRTTI&Env,TQapBinaryObject&qbo):
    Tools(Env,Space),ClientCounter(Env,Space),ClientVisitor(ClientCounter),DS(Env,ClientVisitor),qbo(qbo)
  {
    ptrs.Init(Env,qbo);
    Space.AddPointsFromSys();
    Space.AddPointsFromEnv(Env);
    Tools.BuildProxy();
    Tools.PrepareEx();
    Tools.MegaPass();
  }
  ~TConservationMachine()
  {
    Space.clear();
  }
  static void Check_EachItemsOfTheSpaceIsNoPassed(TServerPtrSpace&Space)
  {
    vector<int> bad_items;
    auto&arr=Space.Arr;
    if(arr.empty())return;
    arr[0].CheckNullptr();
    for(int i=1;i<arr.size();i++)
    {
      auto&item=arr[i];
      if(item.passed)
      {
        string itemname=item.name.empty()?"{id="+IToS(i)+"}":item.name;
        QapDebugMsg("bad item -'"+itemname+"'");
        bad_items.push_back(i);
      }
    }
    if(bad_items.empty())return;
    QapDebugMsg("bad_items.size() == "+IToS(bad_items.size()));
  }
  struct TPointsHolder
  {
    vector<EnvItem> Arr;
    void move(TSpace&From,TSpace&To)
    {
      QapAssert(From.size()==To.size());
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(SaveID);
        QapAssert(From.CheckServSaveID(ex.ptr.ptr));
        QapAssert(To.IsAllowed(SaveID));
        auto&from=From[SaveID];
        auto&to=To[SaveID];
        QapAssert(from.id==to.id);
        QapAssert(to.ptr.IsNull()&&to.ptr_lnk.IsNull());
        From.Del(from);
        To.InsertTo(to.id,ex);
      }
      bool debug_flag=false;
      if(debug_flag)Arr.clear();
    }
    void on(TSpace&Space)const
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(!SaveID);
        QapAssert(Space.IsAllowed(ex.id));
        auto&item=Space[ex.id];
        QapAssert(item.ptr.IsNull()&&item.ptr_lnk.IsNull());
        Space.InsertTo(ex.id,ex);
        QapAssert(SaveID);
      }
    }
    void off_all_objects(TSpace&Space)const
    {
      //set object.SaveID to zero
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(SaveID);
        QapAssert(Space.CheckServSaveID(ex.ptr.ptr));
        auto&item=Space[SaveID];
        EnvItem temp;
        temp.copy(item);
        QapAssert(item.id==ex.id);
        Space.Del(item);
        QapAssert(!SaveID);
        item.copy(temp);
      }
    }
    void off_all_envitems(TSpace&Space,bool assert_objects_enabled=false)const
    {
      //set envitems.ptr to zero
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(assert_objects_enabled==bool(SaveID));
        QapAssert(Space.IsAllowed(ex.id));
        auto&item=Space[ex.id];
        QapAssert(item.ptr.IsValid()&&item.ptr_lnk.IsValid());
        item.ptr.set_zero();
        item.ptr_lnk.set_zero();
      }
    }
    void off(TSpace&Space)const
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(SaveID);
        QapAssert(Space.CheckServSaveID(ex.ptr.ptr));
        auto&item=Space[SaveID];
        QapAssert(item.id==ex.id);
        Space.Del(item);
      }
    }
    void insert_to_end(TSpace&Space)const
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(!SaveID);
        Space.Insert(ex);
      }
    }
  };
  struct TUserPointsHolder:TPointsHolder
  {
    void take(TSpace&Space)
    {
      auto&arr=Space.Arr;
      if(arr.empty())return;
      arr[0].CheckNullptr();
      for(int i=1;i<arr.size();i++)
      {
        auto&item=arr[i];
        if(item.passed)
        {
          int id=Arr.size();
          this->Arr.push_back(EnvItem());
          auto&back=this->Arr.back();
          back.copy(item);
          QapAssert(back.name.empty());
          back.name="userpoint["+IToS(id)+"]";
        }
      }
    }
  };
  struct TSyncPointsHolder:TPointsHolder
  {
    typedef TSyncPointsHolder SelfClass;
    void sync(TSpace&Space)
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        auto&item=Space[ex.ptr.ptr->SaveID];
        Space.Swap(ex.id,item.id);
      }
    }
    void copy(const TPointsHolder&ref)
    {
      this->Arr.resize(ref.Arr.size());
      for(int i=0;i<ref.Arr.size();i++)
      {
        Arr[i].copy(ref.Arr[i]);
      }
    }
    void copy_envitem_lnk(const TPointsHolder&ref,TSpace&Space)
    {
      this->Arr.resize(ref.Arr.size());
      for(int i=0;i<ref.Arr.size();i++)
      {
        auto&ex=ref.Arr[i];
        auto&ax=ex.get_lnk(Space);
        Arr[i].copy(ax);
      }
    }
    void copy_envitem_lnk_and_keep_id(const TPointsHolder&ref,TSpace&Space)
    {
      this->Arr.resize(ref.Arr.size());
      for(int i=0;i<ref.Arr.size();i++)
      {
        auto&ex=ref.Arr[i];
        auto&ax=ex.get_lnk(Space);
        Arr[i].copy(ax).id=ex.id;
      }
    }
    void update_id(const TSpace&Space)
    {
      auto&arr=Arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        QapAssert(ex.ptr.IsValid());
        QapAssert(Space.CheckServSaveID(ex.ptr.ptr));
        auto&SaveID=ex.ptr.ptr->SaveID;
        auto&item=Space[SaveID];
        QapAssert(item.oper_eq(ex,true));
        ex.id=SaveID;
      }
    }
    void insert_and_sync(TSpace&Space,TSpace&SpaceForIt)
    {
      auto&UpA=*this;
      UpA.off(Space);
      UpA.insert_to_end(SpaceForIt);
      SelfClass UpB;
      UpB.copy(UpA);
      UpB.update_id(SpaceForIt);
      UpB.off_all_objects(SpaceForIt);
      UpA.on(Space);
      UpB.sync(Space);
    }
  };
  static int get_lnk_id(TSpace&Space,TType*pType)
  {
    auto&item=Space[pType->Self];
    auto*p=(DeclareType*)item.ptr_lnk.get();
    return p->Self.P.SaveID;
  };
  /*
    out.MiniSpace - туда складыватс€ используемые(по версии Space) метатипы из arr, а потом они(используемые) привз€ываютс€ к SpaceForMetaSpec.
    TakeUsedMetatypesAndLinkHimWithSpace == InitMetaSpec
  */
  static void InitMetaSpec(TQapBinaryObject::TMetaSpec&out,TSpaceDependsTools::TDeclareTypeArray&arr,TSpace&Space,TSpace&SpaceForMetaSpec)
  {
    auto&SpaceFMS=SpaceForMetaSpec;
    {
      int count=arr.size();
      out.reserve(count);
      SpaceFMS.reserve(1+count+count);
    }
    auto get=[&Space](TType*pType)->int
    {
      return get_lnk_id(Space,pType);
    };
    auto copy_count_from_lnk_for_cur=[&Space,&get](TType*pType)
    {
      auto&cur_item=Space[pType->Self];
      auto&lnk_item=Space[get(pType)];
      QapAssert(!cur_item.count);
      if(cur_item.count==lnk_item.count)return;
      cur_item.count=lnk_item.count;
    };
    auto pass=[&Space,&SpaceFMS,&get,&out](TType*pType)
    {
      auto&sys_item=Space[pType->Self];
      auto&def_item=Space[get(pType)];
      if(!def_item.count)return;
      out.push_back(EnvDefTypeStr());
      auto&back=out.back();
      back.Decl.Name=pType->GetFullName();
      QapAssert(sys_item.name.substr(0,5)=="Sys$$");
      QapAssert(def_item.name.substr(0,5)=="Def$$");
      SpaceFMS.AddExt(EnvAdapter::get(back.Decl.Decl.Self),nullptr,"Def$$<"+back.Decl.Name+">::GetRTTI()").ptr_lnk=def_item.ptr;
      SpaceFMS.AddExt(EnvAdapter::get(back.Impl.Self),nullptr,"Sys$$<"+back.Decl.Name+">::GetRTTI()").ptr_lnk=sys_item.ptr;
    };
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      copy_count_from_lnk_for_cur(ex.first);
      copy_count_from_lnk_for_cur(ex.second);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(ex.first);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(ex.second);
    }
  }
  static void SyncTwoSpace_Stage1(TQapBinaryObject::TMetaSpec&Spec,TSpace&Space,TSpace&SpaceFMS)
  {
    auto do_swap=[&Space,&SpaceFMS](EnvDefEntryPoint&EP)
    {
      auto&item=SpaceFMS[EP.Self];
      auto&jtem=Space[item.ptr_lnk.ptr->SaveID];
      QapAssert(jtem.name==item.name);
      Space.Swap(jtem.id,item.id);
    };
    auto&arr=Spec;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      do_swap(ex.Decl.Decl);
      do_swap(ex.Impl);
    }
  }
  struct SpaceScopeBot
  {    
    typedef TConservationMachine TMachine;
    TMachine&machine;
    TSpace&Space;
    SpaceScopeBot(TMachine&machine,TSpace&Space):machine(machine),Space(Space){Init();}
   ~SpaceScopeBot(){Free();}
    void Init()
    {
      std::swap(machine.Space,Space);
    }
    static void CheckAssert(TMachine&machine){QapAssert(&machine.qbo.SpaceSize==machine.ptrs.SpaceSize.pValue);}
    static void Go(TMachine&machine,IUberSaveDevice&dev,TRawPtr&raw_ptr)
    {
      CheckAssert(machine);
      machine.qbo.SpaceSize=machine.Space.size();
      dev.DoSave(machine,machine.ptrs.SpaceSize);
      dev.DoSave(machine,raw_ptr);
    }
    static void Go(TMachine&machine,IUberLoadDevice&dev,TRawPtr&raw_ptr)
    {
      CheckAssert(machine);
      dev.DoLoad(machine,machine.ptrs.SpaceSize);
      machine.Space.resize(machine.qbo.SpaceSize);
      dev.DoLoad(machine,raw_ptr);
    }
    void Free()
    {
      std::swap(machine.Space,Space);
    }
  };
  #include "QapUberSaver_TConMachine_GP_Bots.inl"
  template<class TYPE>
  struct SelectGoooDevContext{typedef void type;};
  template<>
  struct SelectGoooDevContext<IUberSaveDevice>{typedef GP_BotContext_ST type;};
  template<>
  struct SelectGoooDevContext<IUberLoadDevice>{typedef GP_BotContext_LT type;};
  template<class IUberGoooDevice>
  bool Gooo(IUberGoooDevice&Dev,TRawPtr&raw_ptr)
  {
    typedef std::remove_reference<decltype(Dev)>::type IConcreteDevice;
    typedef SelectGoooDevContext<IConcreteDevice>::type TContext;
    typedef TContext::GP_BotA::SelfClass GP_BotA;
    typedef TContext::GP_BotB::SelfClass GP_BotB;
    typedef TContext::GP_BotC::SelfClass GP_BotC;
    typedef TContext::GP_BotD::SelfClass GP_BotD;
    //GP
    typedef SpaceScopeBot ScopeBot;
    auto&machine=*this;
    ptrs.Root=raw_ptr;
    //GP
    TContext context(machine,raw_ptr);
    //GP
    {
      GP_BotA gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.MetaSpec);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotB gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.FullDeclEnv);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotC gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.RootType);
    }  
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotD gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.Root);
    }
    return context.result;
  }
  bool Save(IUberSaveDevice&Dev,TRawPtr&raw_ptr)
  {
    //return Gooo(Dev,raw_ptr);
    typedef std::remove_reference<decltype(Dev)>::type IConcreteDevice;
    typedef SelectGoooDevContext<IConcreteDevice>::type TContext;
    typedef TContext::GP_BotA::SelfClass GP_BotA;
    typedef TContext::GP_BotB::SelfClass GP_BotB;
    typedef TContext::GP_BotC::SelfClass GP_BotC;
    typedef TContext::GP_BotD::SelfClass GP_BotD;
    //GP
    typedef SpaceScopeBot ScopeBot;
    auto&machine=*this;
    ptrs.Root=raw_ptr;
    //GP
    TContext context(machine,raw_ptr);
    //GP
    {
      GP_BotA gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.MetaSpec);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotB gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.FullDeclEnv);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotC gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.RootType);
    }  
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotD gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.Root);
    }
    return context.result;
  }
  bool Load(IUberLoadDevice&Dev,TRawPtr&raw_ptr)
  {
    return Gooo(Dev,raw_ptr);
  }
  bool FullLoad(IUberLoadDevice&Dev,TRawPtr&raw_ptr)
  {
    return Dev.Load(*this,raw_ptr);
  }
  void FullSave(IUberSaveDevice&Dev,TRawPtr&raw_ptr)
  {
    //Setup(raw_ptr);
    return Dev.Save(*this,raw_ptr);
  }
};

class QapJsonObject{
public:
  typedef TServerPtrSpace TSpace;
  static void DoSave(ISmartPtrSolver&Solver,TJsonCodeGen&OutDev,TType*pType,void*pValue)
  {
    TJsonSaver BS(Solver,OutDev,pValue);
    pType->Use(BS);
  }
  static bool DoLoad(ISmartPtrSolver&Solver,TQapIO&IO,TType*pType,void*pValue)
  {/*
    if(!Solver.Result)return false;
    TBinaryLoader BL(Solver,IO,pValue);
    pType->Use(BL);
    if(!Solver.Result)return false;
    Solver.SolveClient(pType,pValue);
    return Solver.Result;*/
    return false;
  }
};

struct UberSaveDeviceJson:IUberSaveDevice
{
  IQapStream&Stream;
  struct TContext
  {
    TJsonCodeGen&OutDev;
    TSmartPtrSolver&Solver;
  };
  TContext*pContext;
  UberSaveDeviceJson(IQapStream&Stream):Stream(Stream),pContext(nullptr){}
  void Begin(TContext&Ref){QapAssert(!pContext);pContext=&Ref;}
  void End(){QapAssert(pContext);pContext=nullptr;}
  void Save(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&Dev=*this;
    auto&Content=Stream.GetContent();
    {
      TSmartPtrSolver Solver(machine.Space,machine.Tools.get_tmt());
      TJsonCodeGen OutDev(Content.IO.mem);
      TContext Context={OutDev,Solver};
      Begin(Context);
      machine.Save(Dev,raw_ptr);
      End();
    }
    bool result=!Content.IO.mem.empty()&&Stream.Save();
  }
  void DoSave(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&OutDev=pContext->OutDev;
    auto&Solver=pContext->Solver;
    QapJsonObject::DoSave(Solver,OutDev,raw_ptr.pType,raw_ptr.pValue);
  }
};

bool QapUberFullSaver(IEnvRTTI&Env,IQapRawObject&&Object,IUberSaveDevice&Dev)
{
  typedef IQapRawObject::TRawPtr TRawPtr;
  auto&raw_ptr=Object.Get(Env);
  //begin
  {
    TQapBinaryObject qbo;
    TConservationMachine Machine(Env,qbo);
    Machine.FullSave(Dev,raw_ptr);
    auto&arr=qbo.FullDeclEnv.DeclEnv.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex->Self.P.SaveID)continue;
      string fn=ex->GetFullName();
      bool breakpoint=true;
    }
    qbo.FullDeclEnv.DeclEnv.Arr.clear();
  }
  //end
  return true;
}

bool QapPublicUberFullSaverJson(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullSaver(Env,std::move(Object),UberSaveDeviceJson(TQapFileStream(filename,false)));
}
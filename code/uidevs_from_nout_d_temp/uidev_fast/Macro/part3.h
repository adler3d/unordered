//part3
class IEsoteric
{
public:
//=====+>>>>>IEsoteric
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IEsoteric SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TSelfPtr<SelfClass> Self;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->Self);
  }
  //==Declaration Constructors==//
public:
  IEsoteric(const IEsoteric&)=delete;
  IEsoteric()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IEsoteric(IEsoteric&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IEsoteric&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->Self=std::move(_Right.Self);
    //[Line](<=)
  }
  //==Declaration GetRTTI==//
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      //[Line](=>)
      static const string Name="IEsoteric";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
      //[Line](<=)
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }
    static string GetFullName()
    {
      //[Line](=>)
      return "IEsoteric";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IEsoteric
public:
  static void SysHasSelf();
};
struct TRawPtr
{
  TType*pType;
  void*pValue;
  TRawPtr():pType(nullptr),pValue(nullptr) {}
  TRawPtr(TType*pType,void*pValue):pType(pType),pValue(pValue) {}
  template<class TYPE>
  TRawPtr(IEnvRTTI&Env,TYPE&Ref):pType(nullptr),pValue(nullptr)
  {
    set(Env,Ref);
  }
  template<class TYPE>
  TRawPtr(TAutoPtr<TYPE>&Ref)
  {
    set(Ref);
  }
  template<class TYPE>
  void set(IEnvRTTI&Env,TYPE&Ref)
  {
    pType=Sys$$<TYPE>::GetRTTI(Env);
    pValue=&Ref;
  }
  template<class TYPE>
  void set(TAutoPtr<TYPE>&Ref)
  {
    if (Ref)
    {
      pType=Ref.Product.pType.get();
      pValue=Ref.get();
    }
    else
    {
      setZero();
    }
  }
  void set(TType*pType,void*pValue)
  {
    this->pType=pType;
    this->pValue=pValue;
  }
  void setZero()
  {
    pType=nullptr;
    pValue=nullptr;
  }
  bool IsValid()
  {
    return pType&&pValue;
  }
};
class TVoidPtr
{
public:
//=====+>>>>>TVoidPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TVoidPtr SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> type;
  TWeakPtr<IEsoteric> ptr;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    (this->type)=(nullptr);
    (this->ptr)=(nullptr);
  }
  //==Declaration Constructors==//
public:
  TVoidPtr(const TVoidPtr&)=delete;
  TVoidPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
  //==Declaration GetRTTI==//
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      //[Line](=>)
      static const string Name="TVoidPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberSYS(0,nullptr,"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"SYS");
      Info->AddMemberSYS(0,nullptr,"ptr",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr))),"SYS");
      //[Line](<=)
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }
    static string GetFullName()
    {
      //[Line](=>)
      return "TVoidPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TVoidPtr
public:
  operator bool()const
  {
    return bool(ptr);
  }
public:
  void oper_set(SelfClass&&ref)
  {
    off();
    type=std::move(ref.type);
    ptr=std::move(ref.ptr);
  }
  void operator=(SelfClass&&ref)
  {
    oper_set(std::move(ref));
  }
public:
  //template<class TYPE>
  //TWeakPtr<TYPE>&get(TWeakPtr<IEsoteric>&Ref){return *(TWeakPtr<TYPE>*)(void*)&Ref;};
public:
  void off()
  {
    type=nullptr;
    ptr=nullptr;
  }
  void operator=(const nullptr_t&null)
  {
    off();
  }
  void mega_unsafe_connect(TType*pType,void*pValue)
  {
    off();
    if (!pType||!pValue)return;
    auto*ex=TTypeStruct::IsStruct::GetNearSelf(pType);
    if (!ex)
    {
      string fn=pType->GetFullName();
      QapDebugMsg("field \""+fn+"::Self\" not found");
      return;
    }
    TSelfPtr<IEsoteric>*self=(TSelfPtr<IEsoteric>*)ex->getValue(pValue);
    this->ptr.P=&self->P;
    this->type=pType;
  }
  void mega_unsafe_connect(const TRawPtr&ptr)
  {
    mega_unsafe_connect(ptr.pType,ptr.pValue);
  }
  template<class TYPE>
  void operator=(TAutoPtr<TYPE>&Ref)
  {
    off();
    if (!Ref)return;
    auto*pType=Ref.Product.pType.get();
    auto*pValue=Ref.get();
    mega_unsafe_connect(pType,pValue);
  }
};
struct SubFieldsInfo
{
public:
  class OutDeviceEx
  {
  public:
    //===>>===IVisitor
    class TMemberID;
    class TSubType;
    struct IVisitor
    {
      virtual void Do(TMemberID*p)=0;
      virtual void Do(TSubType*p)=0;
    };
    //===<<===IVisitor
    struct DevCmd
    {
      virtual void Use(IVisitor&A)=0;
    };
    class TMemberID:public DevCmd
    {
    public:
      int id;
    TMemberID(int id):id(id) {}public:
      void Use(IVisitor&A)
      {
        A.Do(this);
      }
    };
    class TSubType:public DevCmd
    {
    public:
      void Use(IVisitor&A)
      {
        A.Do(this);
      }
    };
    class TContext
    {
    public:
      DevCmd*pCmd;
    public:
      TType*pType;
      int Offset;
      const string*head;
    public:
      TContext():pCmd(nullptr),pType(nullptr),Offset(0),head(nullptr) {}
    };
    class TCmdVisitor:public IVisitor
    {
    public:
      TContext*pContext;
    public:
      void Do(TMemberID*p)
      {
        int id=p->id;
        TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
        QapAssert(pMetaType);
        auto&ex=pMetaType->Members[id];
        pContext->Offset+=ex.Offset;
        pContext->pType=ex.Type.get();
        pContext->head=&ex.Name;
      }
      void Do(TSubType*p)
      {
        pContext->Offset=pContext->Offset;
        pContext->pType=pContext->pType->GetSubType();
        pContext->head=nullptr;
        QapAssert(pContext->pType);
      }
    };
  public:
    class TCmdOffsetVisitor:public IVisitor
    {
    public:
      struct TContext
      {
        TType*pType;
        int Offset;
      };
      TContext*pContext;
    public:
      void Do(TMemberID*p)
      {
        int id=p->id;
        TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
        QapAssert(pMetaType);
        auto&ex=pMetaType->Members[id];
        pContext->Offset+=ex.Offset;
        pContext->pType=ex.Type.get();
      }
      void Do(TSubType*p)
      {
        pContext->pType=pContext->pType->GetSubType();
      }
    };
  public:
    TContext Context;
    vector<TContext> branch;
    // ----- ----- ----- ----- -----
    // ----- ----- ----- ----- -----
    // ----- ----- ----- ----- -----
  public:
    void push(DevCmd*pCmd)
    {
      branch.push_back(Context);
      Context.pCmd=pCmd;
      if (pCmd)
      {
        TCmdVisitor CV;
        CV.pContext=&Context;
        pCmd->Use(CV);
      }
    }
    void pop()
    {
      Context=branch.back();
      branch.pop_back();
    }
  public:
    string GetFullFieldNameByIdFromBranch(int id)
    {
      string path;
      for (int i=id;i<branch.size();i++)
      {
        auto&ex=branch[i];
        if (ex.head)path+=*ex.head+".";
      }
      if (Context.head)
      {
        path+=*Context.head;
      }
      else if (!path.empty()&&(path.back()=='.'))
      {
        path.pop_back();
      }
      return std::move(path);
    }
    int GetRelativeFieldOffsetByIdFromBranch(int id)
    {
      TType*pType=nullptr;
      {
        auto&ex=branch[id];
        pType=ex.pType;
      }
      TCmdOffsetVisitor::TContext Context={pType,0};
      TCmdOffsetVisitor COV;
      COV.pContext=&Context;
      for (int i=id+1;i<branch.size();i++)
      {
        auto&ex=branch[i];
        if (!ex.pCmd)return -1;
        ex.pCmd->Use(COV);
      }
      if (!this->Context.pCmd)
      {
        return -1;
      }
      this->Context.pCmd->Use(COV);
      return Context.Offset;
    }
  };
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  class TOffsetVerifier:public IVisitorRTTI
  {
  public:
    typedef TOffsetVerifier SelfClass;
    typedef OutDeviceEx TSaveDev;
  public:
    struct ICallBack
    {
      virtual bool Do(SelfClass&V,TType*p)=0;
    };
  public:
    struct TFieldInfo
    {
      TType*pType;
      int Offset;
      void setZero()
      {
        this->Offset=0;
        this->pType=nullptr;
      }
    };
    class IndexGetter:public ICallBack
    {
    public:
      bool Result;
      int Index;
      const TFieldInfo&Info;
      IndexGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1) {}
    public:
      bool Do(SelfClass&OV,TType*p)
      {
        if (Result)return false;
        if (Info.Offset!=OV.Offset)return true;
        Result=bool(Info.pType==p);
        if (Result)Index=OV.Index;
        return !Result;
      }
    };
    class InfoGetter:public ICallBack
    {
    public:
      bool Result;
      int Index;
      TFieldInfo&Info;
      InfoGetter(TFieldInfo&Info,int Index=-1):Info(Info),Result(false),Index(Index) {}
    public:
      bool Do(SelfClass&OV,TType*p)
      {
        if (Result)return false;
        if (OV.Index!=Index)return true;
        Info.Offset=OV.Offset;
        Info.pType=p;
        Result=true;
        return !Result;
      }
    };
    class FieldNameGetter:public ICallBack
    {
    public:
      bool Result;
      int Index;
      string fieldname;
      const TFieldInfo&Info;
      FieldNameGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1) {}
    public:
      bool Do(SelfClass&V,TType*p)
      {
        if (Result)return false;
        if (Info.Offset!=V.Offset)return true;
        Result=bool(Info.pType==p);
        if (Result)
        {
          Index=V.Index;
          fieldname=V.dev.GetFullFieldNameByIdFromBranch(0);
        }
        return !Result;
      }
    };
  public:
    TSaveDev&dev;
    ICallBack&CB;
    int Offset;
    int&Index;
    TOffsetVerifier(TSaveDev&dev,ICallBack&CB,int Offset,int&Index):dev(dev),CB(CB),Offset(Offset),Index(Index) {}
    TOffsetVerifier(SelfClass&owner,int Offset):dev(owner.dev),CB(owner.CB),Offset(Offset),Index(owner.Index)
    {
      Index++;
    }
  public:
    void Do(TTypeStruct*p)
    {
      if (!CB.Do(*this,p))return;
      if (p->SubType)
      {
        TSaveDev::TSubType tmp;
        dev.push(&tmp);
        SelfClass next(*this,Offset);
        p->SubType->Use(next);
        dev.pop();
      }
      auto&arr=p->Members;
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        TSaveDev::TMemberID tmp(i);
        dev.push(&tmp);
        SelfClass next(*this,Offset+ex.Offset);
        ex.Type->Use(next);
        dev.pop();
      }
    }
    void Do(TTypeSys*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeVector*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeArray*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeSelfPtr*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeAutoPtr*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeWeakPtr*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeHardPtr*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeVoidPtr*p)
    {
      if (!CB.Do(*this,p))return;
    }
    void Do(TTypeFieldPtr*p)
    {
      if (!CB.Do(*this,p))return;
    }
  };
public:
  typedef TOffsetVerifier::TFieldInfo TFieldInfo;
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  static string FieldInfoToFieldName(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
  {
    typedef TOffsetVerifier::FieldNameGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TCallBack CB(Info);
    int tmp=0;
    TOffsetVerifier Visitor(dev,CB,0,tmp);
    pType->Use(Visitor);
    return CB.fieldname;
  }
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  static int FieldInfoToIndex(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
  {
    typedef TOffsetVerifier::IndexGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TCallBack CB(Info);
    int tmp=0;
    TOffsetVerifier OV(dev,CB,0,tmp);
    pType->Use(OV);
    return CB.Index;
  }
  static TOffsetVerifier::TFieldInfo IndexToFieldInfo(TType*pType,int Index)
  {
    typedef TOffsetVerifier::InfoGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TFieldInfo Info;
    Info.setZero();
    TCallBack CB(Info,Index);
    int tmp=0;
    TOffsetVerifier OV(dev,CB,0,tmp);
    pType->Use(OV);
    return Info;
  }
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
};
class TFieldPtr
{
public:
//=====+>>>>>TFieldPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TFieldPtr SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TVoidPtr object;
  THardPtr<TType> type;
  int offset;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    (this->object)=(nullptr);
    (this->type)=(nullptr);
    (this->offset)=(-1);
  }
  //==Declaration Constructors==//
public:
  TFieldPtr(const TFieldPtr&)=delete;
  TFieldPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
  //==Declaration GetRTTI==//
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      //[Line](=>)
      static const string Name="TFieldPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberSYS(0,nullptr,"object",int(&(((SelfClass*)nullptr)->*(&SelfClass::object))),"SYS");
      Info->AddMemberSYS(0,nullptr,"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"SYS");
      Info->AddMemberSYS(0,nullptr,"offset",int(&(((SelfClass*)nullptr)->*(&SelfClass::offset))),"SYS");
      //[Line](<=)
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }
    static string GetFullName()
    {
      //[Line](=>)
      return "TFieldPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TFieldPtr
public:
  void off()
  {
    object=nullptr;
    type=nullptr;
    offset=-1;
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void ConnectToField(QAP_RTTI&RTTI,OBJECT_TYPE&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"bad");
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=&object;
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if (result)
    {
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void Connect(QAP_RTTI&RTTI,TAutoPtr<OBJECT_TYPE>&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    if (!object)return;
    auto*objecttype=object.Product.pType.get();
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=object.get();
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if (result)
    {
      this->object=object;
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE>
  void ConnectEx(QAP_RTTI&RTTI,OBJECT_TYPE&object)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"fail");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=objecttype;
    {
      string ot_fn=objecttype->GetFullName();
    }
    int offset=0;
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if (result)
    {
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
public:
  operator bool()
  {
    return object;
  }
  void*getValue()
  {
    void*pValue=object.ptr.get();
    return TTypeStruct::AddOffset(pValue,offset);
  }
  TType*getType()
  {
    if (!object)return nullptr;
    if (!type)return nullptr;
    return type.get();
  }
public:
  struct TInfo
  {
    TTypeStruct*pType;
    void*pValue;
    TType*pFieldType;
    int Offset;
    void SetToField(TFieldPtr&Field)
    {
      Field=*this;
    }
    operator bool()const
    {
      return pValue&&pType&&pFieldType&&(Offset>=0);
    }
    TInfo():pType(nullptr),pValue(nullptr),pFieldType(nullptr),Offset(-1) {}
    void set(TTypeStruct*pType,void*pValue,TType*pFieldType,int Offset)
    {
      this->pType=pType;
      this->pValue=pValue;
      this->pFieldType=pFieldType;
      this->Offset=Offset;
    }
    void GrabFrom(TFieldPtr&FP)
    {
      this->pType=TTypeStruct::UberCast(FP.object.type.get());
      this->pValue=FP.object.ptr.get();
      this->pFieldType=FP.type.get();
      this->Offset=FP.offset;
    }
  };
public:
  void oper_set(SelfClass&&ref)
  {
    off();
    object=std::move(ref.object);
    type=std::move(ref.type);
    offset=std::move(ref.offset);
    ref.offset=-1;
  }
  void operator=(SelfClass&&ref)
  {
    oper_set(std::move(ref));
  }
  TFieldPtr(SelfClass&&ref)
  {
    oper_set(std::move(ref));
  }
public:
  void operator=(const TInfo&ref)
  {
    off();
    if (!ref)return;
    bool result=IsValid(ref.pType,ref.pFieldType,ref.Offset);//SubFieldsInfo::IsValid(pType,pFieldType,Offset);
    //
    if (!result)QapDebugMsg("WTF?");
    //
    object.mega_unsafe_connect(ref.pType,ref.pValue);
    type=ref.pFieldType;
    offset=ref.Offset;
  }
public:
  static bool IsValid(TType*pType,TType*pFieldType,int Offset)
  {
    SubFieldsInfo::TOffsetVerifier::TFieldInfo Info={pFieldType,Offset};
    return 0<=SubFieldsInfo::FieldInfoToIndex(pType,Info);
  }
};

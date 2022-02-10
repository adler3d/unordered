//part2
class TTypeInfo
{
public:
//=====+>>>>>TTypeInfo
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeInfo SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  string Name;
  int Size;
  int Align;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    (this->Name)=("unnamed");
    (this->Size)=(0);
    (this->Align)=(0);
  }
  //==Declaration Constructors==//
public:
  TTypeInfo(const TTypeInfo&)=delete;
  TTypeInfo()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeInfo(TTypeInfo&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeInfo&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->Name=std::move(_Right.Name);
    this->Size=std::move(_Right.Size);
    this->Align=std::move(_Right.Align);
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
      static const string Name="TTypeInfo";
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
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Align",int(&(((SelfClass*)nullptr)->*(&SelfClass::Align))),"SET","0");
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
      return "TTypeInfo";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeInfo
public:
};
//не конкретный описатель метатипов.
class TType
{
public:
//=====+>>>>>TType
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TType SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TSelfPtr<SelfClass> Self;
  THardPtr<IEnvRTTI> Env;
  THardPtr<IFactory> Factory;
  TTypeInfo Info;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->Self);
    detail::FieldTryDoReset(this->Env);
    detail::FieldTryDoReset(this->Factory);
    detail::FieldTryDoReset(this->Info);
  }
  //==Declaration Constructors==//
public:
  TType(const TType&)=delete;
  TType()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TType(TType&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TType&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->Self=std::move(_Right.Self);
    this->Env=std::move(_Right.Env);
    this->Factory=std::move(_Right.Factory);
    this->Info=std::move(_Right.Info);
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
      static const string Name="TType";
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
      Info->AddMemberDEF(Sys$$<THardPtr<IEnvRTTI>>::GetRTTI(RTTI),"Env",int(&(((SelfClass*)nullptr)->*(&SelfClass::Env))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
      Info->AddMemberDEF(Sys$$<TTypeInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");
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
      return "TType";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TType
public:
  static void SysHasSelf();
public:
  virtual void Use(IVisitorRTTI&)
  {
    QapDebugMsg("no way.");
  }
  virtual string GetFullName()
  {
    return Info.Name;
  }
  virtual TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
  virtual TType*GetSubType()const
  {
    return nullptr;
  }
  bool ready()const
  {
    return Env&&Env->GetAlloc()&&Factory;
  }
  IAllocator*GetAlloc()
  {
    return Env?Env->GetAlloc():nullptr;
  }
  bool CanDestroy()const
  {
    return 1==Self.P.HardCount;
  }
public:
  bool IsBasedOn(TType*A)const
  {
    if (this==A)return true;
    TType*subtype=this->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};
//Описатель системных метатипов.
class TTypeSys:public TType
{
public:
//=====+>>>>>TTypeSys
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeSys SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<IBinIO> BinIO;
  THardPtr<ITxtIO> TxtIO;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->BinIO);
    detail::FieldTryDoReset(this->TxtIO);
  }
  //==Declaration Constructors==//
public:
  TTypeSys(const TTypeSys&)=delete;
  TTypeSys()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeSys(TTypeSys&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeSys&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->BinIO=std::move(_Right.BinIO);
    this->TxtIO=std::move(_Right.TxtIO);
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
      static const string Name="TTypeSys";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<IBinIO>>::GetRTTI(RTTI),"BinIO",int(&(((SelfClass*)nullptr)->*(&SelfClass::BinIO))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<ITxtIO>>::GetRTTI(RTTI),"TxtIO",int(&(((SelfClass*)nullptr)->*(&SelfClass::TxtIO))),"DEF","$");
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
      return "TTypeSys";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeSys
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  ~TTypeSys()
  {
    if (BinIO||TxtIO)
    {
      QapDebugMsg("bad idea");
    }
    BinIO=nullptr;
    TxtIO=nullptr;
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//Описатель метатипов описывающих вектор.
class TTypeVector:public TType
{
public:
//=====+>>>>>TTypeVector
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeVector SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> SizeType;
  THardPtr<TType> ElementType;
  THardPtr<IVectorAPI> VecAPI;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->SizeType);
    detail::FieldTryDoReset(this->ElementType);
    detail::FieldTryDoReset(this->VecAPI);
  }
  //==Declaration Constructors==//
public:
  TTypeVector(const TTypeVector&)=delete;
  TTypeVector()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeVector(TTypeVector&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeVector&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->SizeType=std::move(_Right.SizeType);
    this->ElementType=std::move(_Right.ElementType);
    this->VecAPI=std::move(_Right.VecAPI);
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
      static const string Name="TTypeVector";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SizeType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SizeType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<IVectorAPI>>::GetRTTI(RTTI),"VecAPI",int(&(((SelfClass*)nullptr)->*(&SelfClass::VecAPI))),"DEF","$");
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
      return "TTypeVector";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeVector
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//Описатель метатипов описывающих массив.
class TTypeArray:public TType
{
public:
//=====+>>>>>TTypeArray
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeArray SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  int Size;
  THardPtr<TType> ElementType;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    (this->Size)=(0);
    detail::FieldTryDoReset(this->ElementType);
  }
  //==Declaration Constructors==//
public:
  TTypeArray(const TTypeArray&)=delete;
  TTypeArray()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeArray(TTypeArray&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeArray&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->Size=std::move(_Right.Size);
    this->ElementType=std::move(_Right.ElementType);
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
      static const string Name="TTypeArray";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
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
      return "TTypeArray";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeArray
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+","+IToS(Size)+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//Описатель метатипов описывающих виртуальный коструктор.
class TTypeFactory:public TType
{
public:
//=====+>>>>>TTypeFactory
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeFactory SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> ElementType;
  THardPtr<TType> SubType;
  THardPtr<TType> SmartType;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->ElementType);
    detail::FieldTryDoReset(this->SubType);
    detail::FieldTryDoReset(this->SmartType);
  }
  //==Declaration Constructors==//
public:
  TTypeFactory(const TTypeFactory&)=delete;
  TTypeFactory()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeFactory(TTypeFactory&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeFactory&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->ElementType=std::move(_Right.ElementType);
    this->SubType=std::move(_Right.SubType);
    this->SmartType=std::move(_Right.SmartType);
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
      static const string Name="TTypeFactory";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SmartType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SmartType))),"DEF","$");
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
      return "TTypeFactory";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeFactory
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
  TType*GetSubType()const
  {
    return SubType?SubType.get():nullptr;
  }
};
class IEsoteric;
class QapSysMember
{
public:
//=====+>>>>>QapSysMember
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef QapSysMember SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  string Name;
  THardPtr<TType> Type;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    (this->Name)=("unnamed");
    detail::FieldTryDoReset(this->Type);
  }
  //==Declaration Constructors==//
public:
  QapSysMember(const QapSysMember&)=delete;
  QapSysMember()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  QapSysMember(QapSysMember&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(QapSysMember&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->Name=std::move(_Right.Name);
    this->Type=std::move(_Right.Type);
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
      static const string Name="QapSysMember";
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
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
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
      return "QapSysMember";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====QapSysMember
public:
  void set(const string&Name,TType*Type)
  {
    this->Name=Name;
    this->Type=Type;
  }
};
//Описатель метатипов описывающих умный указатель "точка входа".
class TTypeSelfPtr:public TType
{
public:
//=====+>>>>>TTypeSelfPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeSelfPtr SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> ElementType;
  QapSysMember mSaveID;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->ElementType);
    detail::FieldTryDoReset(this->mSaveID);
  }
  //==Declaration Constructors==//
public:
  TTypeSelfPtr(const TTypeSelfPtr&)=delete;
  TTypeSelfPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeSelfPtr(TTypeSelfPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeSelfPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->ElementType=std::move(_Right.ElementType);
    this->mSaveID=std::move(_Right.mSaveID);
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
      static const string Name="TTypeSelfPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");
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
      return "TTypeSelfPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeSelfPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    //=====+>>>>>mSaveIDType
    {
      //[Line](=>)
      typedef mSaveIDType ResultType;
      typedef TServerPtr<IEsoteric> ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
                   );
    }
    //<<<<<+=====mSaveIDType
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
public:
  typedef TDynSelfPtrFactory TDynamicFactory;
};
//Описатель метатипов описывающих "владеющий умный указатель".
class TTypeAutoPtr:public TType
{
public:
//=====+>>>>>TTypeAutoPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeAutoPtr SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> ElementType;
  QapSysMember mType;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->ElementType);
    detail::FieldTryDoReset(this->mType);
  }
  //==Declaration Constructors==//
public:
  TTypeAutoPtr(const TTypeAutoPtr&)=delete;
  TTypeAutoPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeAutoPtr(TTypeAutoPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeAutoPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->ElementType=std::move(_Right.ElementType);
    this->mType=std::move(_Right.mType);
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
      static const string Name="TTypeAutoPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");
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
      return "TTypeAutoPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeAutoPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TRTTIProduct mProductType;
    //=====+>>>>>mProductType
    {
      //[Line](=>)
      typedef mProductType ResultType;
      typedef TAutoPtr<IEsoteric> ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::Product))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mProductType""\" != \"""TAutoPtr<IEsoteric>"":"":""Product""\""
                   );
    }
    //<<<<<+=====mProductType
    {}
    typedef THardPtr<TType> mProduct_pTypeType;
    //=====+>>>>>mProduct_pTypeType
    {
      //[Line](=>)
      typedef mProduct_pTypeType ResultType;
      typedef mProductType ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::pType))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mProduct_pTypeType""\" != \"""mProductType"":"":""pType""\""
                   );
    }
    //<<<<<+=====mProduct_pTypeType
    {}
    mType.set("Product.pType",Sys$$<mProduct_pTypeType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//Описатель метатипов описывающих "слабый следящий умный указатель".
class TTypeWeakPtr:public TType
{
public:
//=====+>>>>>TTypeWeakPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeWeakPtr SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> ElementType;
  QapSysMember mSaveID;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->ElementType);
    detail::FieldTryDoReset(this->mSaveID);
  }
  //==Declaration Constructors==//
public:
  TTypeWeakPtr(const TTypeWeakPtr&)=delete;
  TTypeWeakPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeWeakPtr(TTypeWeakPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeWeakPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->ElementType=std::move(_Right.ElementType);
    this->mSaveID=std::move(_Right.mSaveID);
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
      static const string Name="TTypeWeakPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");
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
      return "TTypeWeakPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeWeakPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    //=====+>>>>>mSaveIDType
    {
      //[Line](=>)
      typedef mSaveIDType ResultType;
      typedef TServerPtr<IEsoteric> ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
                   );
    }
    //<<<<<+=====mSaveIDType
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//Описатель метатипов описывающих "сильный следящий умный указатель".
class TTypeHardPtr:public TType
{
public:
//=====+>>>>>TTypeHardPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeHardPtr SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> ElementType;
  QapSysMember mSaveID;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->ElementType);
    detail::FieldTryDoReset(this->mSaveID);
  }
  //==Declaration Constructors==//
public:
  TTypeHardPtr(const TTypeHardPtr&)=delete;
  TTypeHardPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeHardPtr(TTypeHardPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeHardPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->ElementType=std::move(_Right.ElementType);
    this->mSaveID=std::move(_Right.mSaveID);
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
      static const string Name="TTypeHardPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");
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
      return "TTypeHardPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeHardPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    //=====+>>>>>mSaveIDType
    {
      //[Line](=>)
      typedef mSaveIDType ResultType;
      typedef TServerPtr<IEsoteric> ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
                   );
    }
    //<<<<<+=====mSaveIDType
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetElementName()
  {
    return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
  }
  string GetFullName()
  {
    return std::move(Info.Name+"<"+GetElementName()+">");
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//SmartType - это TWeakPtr<TType> спецально для внутреностей.
class TTypeVoidPtr:public TType
{
public:
//=====+>>>>>TTypeVoidPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeVoidPtr SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  QapSysMember mType;
  QapSysMember mPtr;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->mType);
    detail::FieldTryDoReset(this->mPtr);
  }
  //==Declaration Constructors==//
public:
  TTypeVoidPtr(const TTypeVoidPtr&)=delete;
  TTypeVoidPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeVoidPtr(TTypeVoidPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeVoidPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->mType=std::move(_Right.mType);
    this->mPtr=std::move(_Right.mPtr);
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
      static const string Name="TTypeVoidPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mPtr",int(&(((SelfClass*)nullptr)->*(&SelfClass::mPtr))),"DEF","$");
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
      return "TTypeVoidPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeVoidPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef THardPtr<TType> mTypeType;
    //=====+>>>>>mTypeType
    {
      //[Line](=>)
      typedef mTypeType ResultType;
      typedef TVoidPtr ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::type))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mTypeType""\" != \"""TVoidPtr"":"":""type""\""
                   );
    }
    //<<<<<+=====mTypeType
    {}
    typedef TWeakPtr<IEsoteric> mPtrType;
    //=====+>>>>>mPtrType
    {
      //[Line](=>)
      typedef mPtrType ResultType;
      typedef TVoidPtr ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::ptr))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mPtrType""\" != \"""TVoidPtr"":"":""ptr""\""
                   );
    }
    //<<<<<+=====mPtrType
    {}
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mPtr.set("ptr",Sys$$<mPtrType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetFullName()
  {
    return Info.Name;
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
class TVoidPtr;
//костыль
class TTypeFieldPtr:public TType
{
public:
//=====+>>>>>TTypeFieldPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeFieldPtr SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  QapSysMember mObject;
  QapSysMember mType;
  QapSysMember mOffset;
  QapSysMember mIndex;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->mObject);
    detail::FieldTryDoReset(this->mType);
    detail::FieldTryDoReset(this->mOffset);
    detail::FieldTryDoReset(this->mIndex);
  }
  //==Declaration Constructors==//
public:
  TTypeFieldPtr(const TTypeFieldPtr&)=delete;
  TTypeFieldPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeFieldPtr(TTypeFieldPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeFieldPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->mObject=std::move(_Right.mObject);
    this->mType=std::move(_Right.mType);
    this->mOffset=std::move(_Right.mOffset);
    this->mIndex=std::move(_Right.mIndex);
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
      static const string Name="TTypeFieldPtr";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mObject",int(&(((SelfClass*)nullptr)->*(&SelfClass::mObject))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mOffset",int(&(((SelfClass*)nullptr)->*(&SelfClass::mOffset))),"DEF","$");
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mIndex",int(&(((SelfClass*)nullptr)->*(&SelfClass::mIndex))),"DEF","$");
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
      return "TTypeFieldPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeFieldPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TVoidPtr mObjectType;
    //=====+>>>>>mObjectType
    {
      //[Line](=>)
      typedef mObjectType ResultType;
      typedef TFieldPtr ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::object))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mObjectType""\" != \"""TFieldPtr"":"":""object""\""
                   );
    }
    //<<<<<+=====mObjectType
    {}
    typedef THardPtr<TType> mTypeType;
    //=====+>>>>>mTypeType
    {
      //[Line](=>)
      typedef mTypeType ResultType;
      typedef TFieldPtr ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::type))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mTypeType""\" != \"""TFieldPtr"":"":""type""\""
                   );
    }
    //<<<<<+=====mTypeType
    {}
    typedef int mOffsetType;
    //=====+>>>>>mOffsetType
    {
      //[Line](=>)
      typedef mOffsetType ResultType;
      typedef TFieldPtr ClassType;
      //[Line](<=)
      //[Line](=>)
      //[Line](<=)
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::offset))) realtype;
      //[Line](=>)
      //[Line](<=)
      typedef std::remove_reference<realtype>::type fieldtype;
      //[Line](=>)
      //[Line](<=)
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mOffsetType""\" != \"""TFieldPtr"":"":""offset""\""
                   );
    }
    //<<<<<+=====mOffsetType
    {}
    mObject.set("object",Sys$$<mObjectType>::GetRTTI(Env));
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mOffset.set("offset",Sys$$<mOffsetType>::GetRTTI(Env));
    {}
    mIndex.set("index",Sys$$<int>::GetRTTI(Env));
  }
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  string GetFullName()
  {
    return Info.Name;
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
};
//Описатель метатипов описывающих конкретные структуры.
class TTypeStruct:public TType
{
public:
  class Member
  {
  public:
    //=====+>>>>>Member
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef TTypeStruct OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef Member SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string Name;
    int Offset;
    THardPtr<TType> Type;
    string Mode;
    string Value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      (this->Name)=("unnamed");
      (this->Offset)=(0);
      detail::FieldTryDoReset(this->Type);
      detail::FieldTryDoReset(this->Mode);
      detail::FieldTryDoReset(this->Value);
    }
    //==Declaration Constructors==//
  public:
    Member(const Member&)=delete;
    Member()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    Member(Member&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(Member&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->Name=std::move(_Right.Name);
      this->Offset=std::move(_Right.Offset);
      this->Type=std::move(_Right.Type);
      this->Mode=std::move(_Right.Mode);
      this->Value=std::move(_Right.Value);
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
        static const string Name="Member";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Offset",int(&(((SelfClass*)nullptr)->*(&SelfClass::Offset))),"SET","0");
        Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mode))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Value",int(&(((SelfClass*)nullptr)->*(&SelfClass::Value))),"DEF","$");
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
        return "Member";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====Member
  public:
    void*getValue(void*pValue)
    {
      return (void*)(Offset+int(pValue));
    }
  };
  class TExtInfo
  {
  public:
    //=====+>>>>>TExtInfo
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef TTypeStruct OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef TExtInfo SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    int SelfId;
    string SpecInfo;
    bool Polymorph;
    bool Abstract;
    bool PoorDesign;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      (this->SelfId)=(-1);
      detail::FieldTryDoReset(this->SpecInfo);
      (this->Polymorph)=(false);
      (this->Abstract)=(false);
      (this->PoorDesign)=(false);
    }
    //==Declaration Constructors==//
  public:
    TExtInfo(const TExtInfo&)=delete;
    TExtInfo()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    TExtInfo(TExtInfo&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(TExtInfo&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->SelfId=std::move(_Right.SelfId);
      this->SpecInfo=std::move(_Right.SpecInfo);
      this->Polymorph=std::move(_Right.Polymorph);
      this->Abstract=std::move(_Right.Abstract);
      this->PoorDesign=std::move(_Right.PoorDesign);
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
        static const string Name="TExtInfo";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"SelfId",int(&(((SelfClass*)nullptr)->*(&SelfClass::SelfId))),"SET","-1");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"SpecInfo",int(&(((SelfClass*)nullptr)->*(&SelfClass::SpecInfo))),"DEF","$");
        Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Polymorph",int(&(((SelfClass*)nullptr)->*(&SelfClass::Polymorph))),"SET","false");
        Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Abstract",int(&(((SelfClass*)nullptr)->*(&SelfClass::Abstract))),"SET","false");
        Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"PoorDesign",int(&(((SelfClass*)nullptr)->*(&SelfClass::PoorDesign))),"SET","false");
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
        return "TExtInfo";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====TExtInfo
  public:
  };
public:
//=====+>>>>>TTypeStruct
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TTypeStruct SelfClass;
public:
  typedef TType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TType> SubType;
  THardPtr<TType> OwnType;
  vector<Member> Members;
  vector<THardPtr<TType>> Nesteds;
  TExtInfo extInfo;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
    detail::FieldTryDoReset(this->SubType);
    detail::FieldTryDoReset(this->OwnType);
    detail::FieldTryDoReset(this->Members);
    detail::FieldTryDoReset(this->Nesteds);
    detail::FieldTryDoReset(this->extInfo);
  }
  //==Declaration Constructors==//
public:
  TTypeStruct(const TTypeStruct&)=delete;
  TTypeStruct()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TTypeStruct(TTypeStruct&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TTypeStruct&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(TType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      TType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->SubType=std::move(_Right.SubType);
    this->OwnType=std::move(_Right.OwnType);
    this->Members=std::move(_Right.Members);
    this->Nesteds=std::move(_Right.Nesteds);
    this->extInfo=std::move(_Right.extInfo);
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
      static const string Name="TTypeStruct";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"OwnType",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<vector<Member>>::GetRTTI(RTTI),"Members",int(&(((SelfClass*)nullptr)->*(&SelfClass::Members))),"DEF","$");
      Info->AddMemberDEF(Sys$$<vector<THardPtr<TType>>>::GetRTTI(RTTI),"Nesteds",int(&(((SelfClass*)nullptr)->*(&SelfClass::Nesteds))),"DEF","$");
      Info->AddMemberDEF(Sys$$<TExtInfo>::GetRTTI(RTTI),"extInfo",int(&(((SelfClass*)nullptr)->*(&SelfClass::extInfo))),"DEF","$");
      //[Line](<=)
      {
        RTTI.OnRegEnd(Info);
      }
      {
        //[Line](=>)
        Info->AddNested(Sys$$<Member>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<TExtInfo>::GetRTTI(RTTI));
        //[Line](<=)
      }
      Info->SelfTesting();
      return Info;
    }
    static string GetFullName()
    {
      //[Line](=>)
      return "TTypeStruct";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TTypeStruct
public:
  void Use(IVisitorRTTI&A)
  {
    A.Do(this);
  }
  static string GetElementName(THardPtr<TType>&ElementType)
  {
    return std::move(ElementType?ElementType->GetFullName()+"::":"");
  }
  string GetFullName()
  {
    return std::move(GetElementName(OwnType)+Info.Name);
  }
public:
  string GetDebugInfo()
  {
    string fn=GetFullName();
    string code;
    auto&arr=Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      code+=(i?",":"")+ex.Name;
    }
    return fn+"={"+code+"}";
  }
public:
  bool TestField(const Member&it,int depth=0)
  {
    QapAssert((it.Mode=="DEF")||(it.Mode=="SET"));
    if (it.Mode=="DEF")do
      {
        auto*pFieldType=TTypeSys::UberCast(it.Type.get());
        if (!pFieldType)break;
        string ftfn=pFieldType->GetFullName();
        static const vector<string> white_list=split("bool|uint|int|float|real|char|uchar|string","|");
        bool white=false;
        for (int i=0;i<white_list.size();i++)
        {
          white=white||(ftfn==white_list[i]);
        }
        if (white)break;
        string fn=GetFullName();
        QapDebugMsg("field - \""+fn+"\"::"+it.Name+"\" has illegal DEF mode");
      }
      while (false);
    if (SubType)
    {
      auto*pSubType=TTypeStruct::UberCast(SubType.get());
      bool result=pSubType->TestField(it,depth+1);
      if (!result)return result;
    }
    auto&arr=Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int cmp_id=0;
      static string idToStr[]={"Name","Offset",};
      const int cmp_n=lenof(idToStr)-(depth?1:0);
      //[Line](=>)
      do
      {
        if (cmp_id<cmp_n)
        {
          if (it.Name==ex.Name)break;
          cmp_id++;
        }
        if (cmp_id<cmp_n)
        {
          if (it.Offset==ex.Offset)break;
          cmp_id++;
        }
        ;
      }
      while (false);
      //[Line](<=)
      if (cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        string fn=GetFullName();
        if (tmp=="Name")if (it.Name=="Self")if (fn=="QapWinProgram")continue;
        if ((-1==it.Offset)&&(-1==Info.Size))continue;
        QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
        return depth;
      }
    }
    return true;
  }
public:
  static SelfClass*UberCast(TType*ptr)
  {
    return IVisitorRTTI::UberCast<SelfClass>(ptr);
  };
public:
  template<class TYPE>
  static TYPE*AddOffset(TYPE*pValue,int offset)
  {
    return (TYPE*)(void*)(offset+int(pValue));
  }
  struct IsStruct
  {
    static Member*GetNearSelf(THardPtr<TType>&pType)
    {
      if (!pType)return nullptr;
      TType*type=pType.get();
      return GetNearSelf(type);
    }
    static Member*GetNearSelf(TType*type)
    {
      if (!type)return nullptr;
      auto*tmp=UberCast(type);
      if (!tmp)
      {
        return GetNearSelf(type->GetSubType());
      }
      return tmp->GetNearSelf();
    }
    struct MemberIndexByOffset
    {
      struct FieldInfo
      {
        TTypeStruct*base;
        int index;
        Member*get()
        {
          if (!base)return nullptr;
          auto&it=base->Members[index];
          return &it;
        }
      };
      struct Input
      {
        TType*type;
        int offset;
        TType*fieldtype;
      };
      struct Output
      {
        int index;
        FieldInfo info;
      };
      static bool get(Input&in,Output&out)
      {
        auto*base=UberCast(in.type);
        string in_ft_fn=in.fieldtype->GetFullName();
        if (base)
        {
          //проходим сверху.
          auto&arr=base->Members;
          for (int i=0;i<arr.size();i++,out.index++)
          {
            auto&it=arr[i];
            if (it.Offset!=in.offset)
            {
              TType*mt=it.Type.get();
              int mos=in.offset-it.Offset;
              Input input={mt,mos,in.fieldtype};
              bool result=get(input,out);
              if (!result)continue;
              return result;
            }
            auto*type=it.Type.get();
            {
              string type_fn=type->GetFullName();
              string base_fn=base->GetFullName();
              in_ft_fn=in_ft_fn;
            }
            if (type==in.fieldtype)
            {
              out.info.base=base;
              out.info.index=i;
              return true;
            }
            else
            {
              TType*mt=it.Type.get();
              int mos=in.offset-it.Offset;
              Input input={mt,mos,in.fieldtype};
              bool result=get(input,out);
              if (!result)continue;
              return result;
            }
            QapDebugMsg("breakpoint");
          }
        }
        if (!base&&in.type)
        {
          TType*SubType=in.type->GetSubType();
          if (SubType)
          {
            Input input={SubType,in.offset,in.fieldtype};
            return get(input,out);
          }
        }
        return false;
      }
    };
  };
  Member*GetNearSelf()
  {
    return extInfo.SelfId<0?IsStruct::GetNearSelf(GetSubType()):&Members[extInfo.SelfId];
  }
public:
  void AddField(Member&&field)
  {
    QapAssert(field.Type);
    QapAssert(TestField(field));
    QapAssert(field.Type&&field.Type->Info.Align>0);
    if (field.Name=="Self")
    {
      if (true)do
        {
          auto*type=TTypeSelfPtr::UberCast(field.Type.get());
          QapAssert(type);
          if (this!=type->ElementType.get())
          {
            string fn=GetFullName();
            QapDebugMsg("field - \""+fn+"\"::"+field.Name+"\" has wrong type");
          }
        }
        while (false);
      if (GetNearSelf())do
        {
          auto*type=field.Type.get();
          auto*pSubType=TTypeStruct::UberCast(SubType.get());
          string fn=GetFullName();
          string subtype=pSubType->GetFullName();
          if ("QapWinProgram"==subtype)if ("eWinProgram"==fn)break;
          if ("QapWinProgram"==subtype)if ("QapProgramD3D9"==fn)break;
          QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
        }
        while (false);
      extInfo.SelfId=Members.size();
    }
    Members.push_back(std::move(field));
  }
  void AddMemberSET(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
  {
    //if(FindMember(Number))MACRO_ADD_LOG("Member("+MemName+":"+MemType->GetName()+") id("+IToS(Number)+") not unique",lml_ERROR);
    //Members.push_back(Member(Number,MemType,MemName,Offset));
    Member tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Offset=Offset;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
  void AddMemberDEF(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
  {
    Member tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Offset=Offset;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
  void AddMemberSYS(...) {}
  void AddMemberSYD(...) {}
  void AddNested(TType*NestedType)
  {
    Nesteds.push_back(NestedType);
  }
public:
  static vector<string>&get_white_list()
  {
    static vector<string> arr;
    if (!arr.empty())return arr;
    string white_list[]=
    {
      "eWindow::TForm",
      "QapKeyboard",
      "QapD3DDev9",
      "QapTexMem",
      "QapTex",
      "QapFontInfo",
      "QapDev",
      "QapResourceDetector",
      "QapTreeDebugger",
      "TDownLoader",
      "TReloadDetector",
      "T20130410_GatewayServer",
      "T20130410_ServerCallback"
    };
    for (int i=0;i<lenof(white_list);i++)
    {
      arr.push_back(white_list[i]);
    };
    return arr;
  }
  static bool find_in_white_list(const string&type_fullname)
  {
    auto&arr=get_white_list();
    for (int i=0;i<arr.size();i++)
    {
      if (arr[i]==type_fullname)return true;
    }
    return false;
  }
  void SelfTesting()
  {
    static string all_messages;
    if (!Members.empty())
    {
      auto&front=Members.front();
      bool bad=!SubType&&front.Offset;
      bool mute=(extInfo.Polymorph&&!SubType)&&(front.Offset==Info.Align);
      if (bad)
      {
        string fn=this->GetFullName();
        string msg="\""+fn+"\" - offset of the first field of the type is "+IToS(front.Offset);
        all_messages+=msg+"\n";
        mute=mute||find_in_white_list(fn);
        if (!mute)QapDebugMsg(msg);
      }
    }
    if (!Members.empty())
    {
      auto&back=Members.back();
      int aligned_size=getAligned(back.Offset+back.Type->Info.Size,Info.Align);
      bool bad=aligned_size!=Info.Size;
      if (bad)
      {
        string fn=this->GetFullName();
        string msg="\""+fn+"\" - size of the type is "+IToS(Info.Size)+". expected aligned_size = "+IToS(aligned_size);
        all_messages+=msg+"\n";
        bool mute=find_in_white_list(fn);
        if (!mute)QapDebugMsg(msg);
      }
    }
    if (Members.empty())
    {
      int expected_size=0;
      {
        if (!SubType)
        {
          expected_size=1;
          if (extInfo.Polymorph)expected_size=Info.Align;
        }
        if (SubType)expected_size=SubType->Info.Size;
      }
      bool bad=expected_size!=Info.Size;
      if (bad)
      {
        string fn=this->GetFullName();
        string msg=(
              "\""+fn+"\" - size of the type is "+IToS(Info.Size)+"\n"
              "expected size: "+IToS(expected_size)+"\n"
              "PoorDesign?"
            );
        all_messages+=msg+"\n";
        bool mute=extInfo.PoorDesign||find_in_white_list(fn);
        if (!mute)QapDebugMsg(msg);
      }
    }
    if (OwnType&&!Nesteds.empty())
    {
      const string&parent=OwnType->Info.Name;
      auto&arr=Nesteds;
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if (parent!=ex->Info.Name)continue;
        QapDebugMsg(
          "Prohibited name of a nested type.\n"
          "parent type and one of the sub-types have equal names.\n"
          "  ParentClass: "+parent+"\n"
          "  SelfClass: "+Info.Name
        );
        *(int*)nullptr=0;
      }
    }
  }
public:
  void Calc()
  {
    QapAssert(Info.Size>0);
    QapAssert(Info.Align>0);
    auto*subtype=SubType.get();
    if (subtype)
    {
      QapAssert(subtype->Info.Size>0);
      QapAssert(subtype->Info.Align>0);
    }
    auto&arr=Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*type=ex.Type.get();
      QapAssert(type->Info.Size>0);
      QapAssert(type->Info.Align>0);
      QapAssert(ex.Offset>=0);
    }
    int gfdsq=0;
  }
  static int getAligned(int offset,int align)
  {
    QapAssert(offset>=0);
    int x=offset%align;
    return offset+(x?align-x:0);
  }
  void ReCalcMembersOffset()
  {
    //QapAssert(size);
    int Offset=0;
    int MaxAlign=0;
    auto*subtype=SubType.get();
    if (subtype)
    {
      int Size=subtype->Info.Size;
      int Align=subtype->Info.Align;
      QapAssert(Size>0);
      QapAssert(Align>0);
      Offset=getAligned(Offset,Align);
      Offset+=Size;
      MaxAlign=max(MaxAlign,Align);
    }
    auto&arr=this->Members;
    MaxAlign=max(MaxAlign,!arr.empty()?arr[0].Type->Info.Align:1);
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*type=ex.Type.get();
      int Size=type->Info.Size;
      int Align=type->Info.Align;
      QapAssert((Align>0)&&(Align<=1024));
      QapAssert(Size>0);
      QapAssert(-1==ex.Offset);
      ex.Offset=getAligned(Offset,Align);
      Offset=ex.Offset+Size;
      MaxAlign=max(MaxAlign,Align);
    }
    Info.Size=getAligned(Offset>0?Offset:1,MaxAlign);
    Info.Align=MaxAlign;
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
  TType*GetSubType()const
  {
    return SubType?SubType.get():nullptr;
  }
  bool IsEqual(TTypeStruct*type)
  {
    if (Members.size()!=type->Members.size())return false;
    for (int i=0;i<Members.size();i++)
    {
      auto&it=Members[i];
      auto&ex=type->Members[i];
      if (it.Type.get()!=ex.Type.get())do
        {
          const int&id1=it.Type->Self.P.SaveID;
          const int&id2=ex.Type->Self.P.SaveID;
          if ((id1&&id2)&&(id1==id2))break;
          return false;
        }
        while (false);
      int cmp_id=0;
      static string idToStr[]={"Name", "Mode",};
      static const int cmp_n=lenof(idToStr);
      //[Line](=>)
      do
      {
        if (it.Name!=ex.Name)break;
        cmp_id++;
        if (it.Mode!=ex.Mode)break;
        cmp_id++;
        ;
      }
      while (false);
      //[Line](<=)
      if (cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        QapDebugMsg("wrong "+tmp+" in "+GetFullName()+"::"+it.Name);
        return false;
      }
    }
    return true;
  }
  bool hasMember(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex)
    {
      return ex.Name==name;
    }
                     );
    if (arr.size()>1)
    {
      QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);
      return true;
    }
    return !arr.empty();
  }
  Member&unsafe_find_member(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex)
    {
      return ex.Name==name;
    }
                     );
    if (arr.size()!=1)
    {
      QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);
      return *(Member*)nullptr;
    }
    return Members[arr[0]];
  }
  Member*find_member(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex)
    {
      return ex.Name==name;
    }
                     );
    if (arr.empty())return nullptr;
    if (arr.size()>1)
    {
      QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);
      return nullptr;
    }
    return &Members[arr[0]];
  }
  Member*find_member_full(const string&name)
  {
    if (!SubType)return find_member(name);
    auto*pSubType=SubType.get();
    auto*p=TTypeStruct::UberCast(pSubType);
    if (!p)
    {
      QapDebugMsg("parent of type is not struct?\n"+GetFullName());
      return nullptr;
    }
    auto*fromSub=p->find_member_full(name);
    auto*fromThis=this->find_member(name);
    if (bool(fromSub)==bool(fromThis))
    {
      QapAssert(!fromSub&&!fromThis);
      return false;
    }
    return fromSub?fromSub:fromThis;
  }
public:
  typedef TDynStructFactory TDynamicFactory;
};

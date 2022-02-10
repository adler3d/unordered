//memory
struct noused_t
{
  noused_t(nullptr_t) {}};
class EnvType;
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
/*TMemory - дискриптор выделеной памяти*/
class TMemory
{
public:
  struct ptr_t {};
  ptr_t*ptr;
  int size;
  TMemory():ptr(nullptr),size(0) {}
  //TMemory(ptr_t*ptr,int size):ptr(ptr),size(size){}
  //TMemory(int size,void*ptr):ptr(ptr),size(size){}
  operator bool()const
  {
    QapAssert(bool(ptr)==bool(size));
    return ptr;
  }
  void operator=(nullptr_t)
  {
    ptr=nullptr;
    size=0;
  }
  void operator=(TMemory&&_Right)
  {
    ptr=_Right.ptr;
    _Right.ptr=nullptr;
    size=_Right.size;
    _Right.size=0;
  }
};
/*IProduct - дискриптор продукта(динамически объект)*/
class IProduct
{
public:
//#define DEF_PRO_MANUAL_RESET()
//#define DEF_PRO_MANUAL_CONSTRUCTOR()
//=====+>>>>>IProduct
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IProduct SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
  }
  //==Declaration Constructors==//
public:
  IProduct(const IProduct&)=delete;
  IProduct()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IProduct(IProduct&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IProduct&&_Right)
  {
    if (&_Right==this)return;
    {
    }
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
      static const string Name="IProduct";
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
      return "IProduct";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IProduct
public:
  virtual void safe_free()
  {
    if (bool(*this))Free();
  }
public:
  virtual const TMemory&GetMemory()const
  {
    QapDebugMsg("no way.");
    return *(TMemory*)nullptr;
  }
  virtual TMemory&GetMemory()
  {
    QapDebugMsg("no way.");
    return *(TMemory*)nullptr;
  }
  virtual IAllocator*GetAlloc()
  {
    QapDebugMsg("no way.");
    return nullptr;
  }
  virtual IFactory*GetFactory()
  {
    QapDebugMsg("no way.");
    return nullptr;
  }
  virtual TType*GetType()
  {
    QapDebugMsg("no way.");
    return nullptr;
  }
public:
  //[Line](=>)
  void Init()
  {
    weak_Init<0>();
  };
  ;
  template<int>void weak_Init()
  //[Line](<=)
  {
    //flag_init=true;
    //flag_free=false;
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(!Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Init(pAlloc,Memory);
  }
  struct {};
  //[Line](=>)
  void Free()
  {
    weak_Free<0>();
  };
  ;
  template<int>void weak_Free()
  //[Line](<=)
  {
    //if(!flag_init&&flag_free)
    //{
    //  QapAssert(flag_init);
    //}
    //flag_free=true;
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Free(pAlloc,Memory);
    QapAssert(!Memory);
  }
  operator bool()const
  {
    return bool(GetMemory());
  }
};
/*TProduct - дискриптор продукта(динамически объект)*/
class TProduct:public IProduct
{
public:
//=====+>>>>>TProduct
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TProduct SelfClass;
public:
  typedef IProduct ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TMemory Memory;
  THardPtr<IAllocator> Alloc;
  THardPtr<IFactory> Factory;
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
    detail::FieldTryDoReset(this->Memory);
    detail::FieldTryDoReset(this->Alloc);
    detail::FieldTryDoReset(this->Factory);
  }
  //==Declaration Constructors==//
public:
  TProduct(const TProduct&)=delete;
  TProduct()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TProduct(TProduct&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TProduct&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(IProduct(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      IProduct::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->Memory=std::move(_Right.Memory);
    this->Alloc=std::move(_Right.Alloc);
    this->Factory=std::move(_Right.Factory);
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
      static const string Name="TProduct";
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
      Info->AddMemberDEF(Sys$$<TMemory>::GetRTTI(RTTI),"Memory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Memory))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<IAllocator>>::GetRTTI(RTTI),"Alloc",int(&(((SelfClass*)nullptr)->*(&SelfClass::Alloc))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
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
      return "TProduct";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TProduct
public:
  const TMemory&GetMemory()const
  {
    return Memory;
  }
  TMemory&GetMemory()
  {
    return Memory;
  }
  IAllocator*GetAlloc()
  {
    return Alloc.get();
  }
  IFactory*GetFactory()
  {
    return Factory.get();
  }
  TType*GetType()
  {
    return nullptr;
  }
public:
  ~TProduct()
  {
    safe_free();
  }
};
/*TProduct - дискриптор продукта(динамически объект)*/
class TRTTIProduct:public IProduct
{
public:
//=====+>>>>>TRTTIProduct
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TRTTIProduct SelfClass;
public:
  typedef IProduct ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TMemory Memory;
  THardPtr<TType> pType;
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
    detail::FieldTryDoReset(this->Memory);
    detail::FieldTryDoReset(this->pType);
  }
  //==Declaration Constructors==//
public:
  TRTTIProduct(const TRTTIProduct&)=delete;
  TRTTIProduct()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TRTTIProduct(TRTTIProduct&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TRTTIProduct&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(IProduct(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      IProduct::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->Memory=std::move(_Right.Memory);
    this->pType=std::move(_Right.pType);
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
      static const string Name="TRTTIProduct";
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
      Info->AddMemberDEF(Sys$$<TMemory>::GetRTTI(RTTI),"Memory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Memory))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");
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
      return "TRTTIProduct";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TRTTIProduct
public:
  const TMemory&GetMemory()const
  {
    return Memory;
  }
  TMemory&GetMemory()
  {
    return Memory;
  }
  //[Line](=>)
  IAllocator* GetAlloc()
  {
    return weak_GetAlloc<0>();
  };
  ;
  template<int>IAllocator* weak_GetAlloc()
  {
    return pType->GetAlloc();
  }
  //[Line](<=)
  //[Line](=>)
  IFactory* GetFactory()
  {
    return weak_GetFactory<0>();
  };
  ;
  template<int>IFactory* weak_GetFactory()
  {
    return pType->Factory.get();
  }
  //[Line](<=)
  //[Line](=>)
  TType* GetType()
  {
    return weak_GetType<0>();
  };
  ;
  template<int>TType* weak_GetType()
  {
    return pType.get();
  }
  //[Line](<=)
public:
  ~TRTTIProduct()
  {
    safe_free();
  }
};
/*IFactory - завод объектов*/
class IFactory
{
public:
//=====+>>>>>IFactory
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IFactory SelfClass;
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
  IFactory(const IFactory&)=delete;
  IFactory()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IFactory(IFactory&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IFactory&&_Right)
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
      static const string Name="IFactory";
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
      return "IFactory";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IFactory
public:
  //IFactory(){}
  ~IFactory() {}
public:
  void operator=(const IFactory&)=delete;
public:
  //virtual constructor
  virtual void Init(IAllocator*pAlloc,TMemory&)
  {
    QapDebugMsg("no way.");
  }
  //virtual destructor
  virtual void Free(IAllocator*pAlloc,TMemory&)
  {
    QapDebugMsg("no way.");
  }
public:
  virtual string GetElementTypeFullName()const
  {
    QapDebugMsg("no way.");
    return "";
  }
  virtual TType*GetElementType(IEnvRTTI&Env)
  {
    QapDebugMsg("no way.");
    return nullptr;
  }
  virtual TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("no way.");
    return nullptr;
  }
public:
  virtual int GetSize()
  {
    QapDebugMsg("no way.");
    return 0;
  }
  virtual void UnsafeInit(const TMemory&)
  {
    QapDebugMsg("no way.");
  }
  virtual void UnsafeFree(const TMemory&)
  {
    QapDebugMsg("no way.");
  }
  virtual void UnsafeMove(const TMemory&Dest,const TMemory&Source)
  {
    QapDebugMsg("no way.");
  }
public:
  virtual void unlink() {};
};
/*IAllocator - владелец пузыря памяти*/
class IAllocator
{
public:
//=====+>>>>>IAllocator
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IAllocator SelfClass;
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
  IAllocator(const IAllocator&)=delete;
  IAllocator()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IAllocator(IAllocator&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IAllocator&&_Right)
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
      static const string Name="IAllocator";
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
      return "IAllocator";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IAllocator
public:
  static void SysHasSelf();
public:
  //allocate storage
  virtual void Alloc(TMemory&)
  {
    QapDebugMsg("no way.");
  };
  //deallocate storage
  virtual void Dealloc(TMemory&)
  {
    QapDebugMsg("no way.");
  };
public:
  class TMemInfo;
  virtual TMemInfo&GetMemInfo()
  {
    QapDebugMsg("no way.");
    return *(TMemInfo*)nullptr;
  }
public:
  class TMemInfo
  {
  public:
    //=====+>>>>>TMemInfo
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef IAllocator OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef TMemInfo SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    int AllocCount;
    int DeallocCount;
    int MemoryUsed;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      (this->AllocCount)=(0);
      (this->DeallocCount)=(0);
      (this->MemoryUsed)=(0);
    }
    //==Declaration Constructors==//
  public:
    TMemInfo(const TMemInfo&)=delete;
    TMemInfo()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    TMemInfo(TMemInfo&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(TMemInfo&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->AllocCount=std::move(_Right.AllocCount);
      this->DeallocCount=std::move(_Right.DeallocCount);
      this->MemoryUsed=std::move(_Right.MemoryUsed);
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
        static const string Name="TMemInfo";
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
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"AllocCount",int(&(((SelfClass*)nullptr)->*(&SelfClass::AllocCount))),"SET","0");
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"DeallocCount",int(&(((SelfClass*)nullptr)->*(&SelfClass::DeallocCount))),"SET","0");
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"MemoryUsed",int(&(((SelfClass*)nullptr)->*(&SelfClass::MemoryUsed))),"SET","0");
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
        return "TMemInfo";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====TMemInfo
  public:
    ~TMemInfo()
    {
      QapAssert(AllocCount==DeallocCount);
      QapAssert(!MemoryUsed);
    }
  public:
    inline void OnAlloc(TMemory&Mem)
    {
      AllocCount++;
      MemoryUsed+=Mem.size;
    }
    inline void OnDealloc(TMemory&Mem)
    {
      DeallocCount++;
      MemoryUsed-=Mem.size;
    }
  };
};
template<typename PARAM,typename TYPE>
void UberReset(PARAM*Param,TYPE&Ref)
{
  detail::Reset<PARAM,TYPE,detail::is_dynamic<PARAM,TYPE>::value>::Do(Param,Ref);
}
//=====implementation=====//
bool TDynStructFactory_set_not_sys_field_from_string(TType*p,const string&source,void*pValue);
class TDynStructFactory:public IFactory
{
public:
//=====+>>>>>TDynStructFactory
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TDynStructFactory SelfClass;
public:
  typedef IFactory ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TTypeStruct> pType;
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
    detail::FieldTryDoReset(this->pType);
  }
  //==Declaration Constructors==//
public:
  TDynStructFactory(const TDynStructFactory&)=delete;
  TDynStructFactory()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TDynStructFactory(TDynStructFactory&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TDynStructFactory&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(IFactory(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      IFactory::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->pType=std::move(_Right.pType);
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
      static const string Name="TDynStructFactory";
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
      Info->AddMemberDEF(Sys$$<THardPtr<TTypeStruct>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");
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
      return "TDynStructFactory";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TDynStructFactory
public:
  struct ptr_t {};
public:
  template<class TYPE>
  void Move(TYPE*pd,TYPE*ps)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if (subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)(void*)pd;
      dMem.size=subtype->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)(void*)ps;
      sMem.size=subtype->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
    auto&arr=type->Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)ex.getValue(pd);
      dMem.size=ty->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)ex.getValue(ps);
      sMem.size=ty->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
  }
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if (subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeInit(Mem);
    }
    auto&arr=type->Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeInit(Mem);
    }
    //DoReset();
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (ex.Mode!="SET")continue;
      void*p=ex.getValue(ptr);
      string&value=ex.Value;
      auto*fieldtype=TTypeSys::UberCast(ex.Type.get());
      if (fieldtype)
      {
        auto*txtio=fieldtype->TxtIO.get();
        txtio->Load(value,p);
      }
      else
      {
        auto*pcommontype=ex.Type.get();
        bool ok=TDynStructFactory_set_not_sys_field_from_string(pcommontype,value,p);
        if (!ok)
        {
          string msg=(
                "the type use SET mode with no sys type:\n"+pcommontype->GetFullName()+"\n\n"
                "and TDynStructFactory_set_not_sys_field_from_string return false"
              );
          QapDebugMsg(msg);
        }
        int gg=1;
      }
      int gg=1;
    }
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    auto&arr=type->Members;
    for (int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeFree(Mem);
    }
    if (subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeFree(Mem);
    }
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem)
  {
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create<ptr_t>(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem)
  {
    Destroy<ptr_t>(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  template<class TYPE>
  int weak_GetSize()
  {
    return pType->Info.Size;
  }
  int GetSize()
  {
    return weak_GetSize<void>();
  }
  void UnsafeInit(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Create<ptr_t>(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Destroy<ptr_t>(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source)
  {
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    Move<ptr_t>(get(Dest.ptr),get(Source.ptr));
  }
public:
  void unlink()
  {
    pType=nullptr;
  };
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if (!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }
  TType*GetElementType(IEnvRTTI&Env)
  {
    return weak_GetElementType(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("[2014.08.23]: it used?");
    return nullptr;
    //return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static inline ptr_t*get(TMemory::ptr_t*ptr)
  {
    return (ptr_t*)(void*)ptr;
  }
};
class TDynSelfPtrFactory:public IFactory
{
public:
//=====+>>>>>TDynSelfPtrFactory
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TDynSelfPtrFactory SelfClass;
public:
  typedef IFactory ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  THardPtr<TTypeSelfPtr> pType;
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
    detail::FieldTryDoReset(this->pType);
  }
  //==Declaration Constructors==//
public:
  TDynSelfPtrFactory(const TDynSelfPtrFactory&)=delete;
  TDynSelfPtrFactory()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TDynSelfPtrFactory(TDynSelfPtrFactory&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TDynSelfPtrFactory&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(IFactory(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      IFactory::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->pType=std::move(_Right.pType);
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
      static const string Name="TDynSelfPtrFactory";
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
      Info->AddMemberDEF(Sys$$<THardPtr<TTypeSelfPtr>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");
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
      return "TDynSelfPtrFactory";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TDynSelfPtrFactory
public:
  struct ptr_t {};
public:
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    QapAssert(type);
    auto*elemtype=TTypeStruct::UberCast(type->ElementType.get());
    auto&self=*elemtype->GetNearSelf();
    QapAssert(&self);
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    new(pSelfPtr) TSelfPtr<IEsoteric>;
    pSelfPtr->P=nullptr;
    IEsoteric*p=(IEsoteric*)(void*)(int(pSelfPtr)-self.Offset);
    pSelfPtr->P=p;
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    pSelfPtr->~TSelfPtr<IEsoteric>();
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem)
  {
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create<ptr_t>(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem)
  {
    Destroy<ptr_t>(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  template<class TYPE>
  TYPE weak_GetSize()
  {
    return sizeof(TSelfPtr<IEsoteric>);
  }
  int GetSize()
  {
    return weak_GetSize<int>();
  }
  void UnsafeInit(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Create<ptr_t>(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Destroy<ptr_t>(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source)
  {
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    //Move<ptr_t>(get(Dest.ptr),get(Source.ptr));
    QapDebugMsg("no way");
  }
public:
  void unlink()
  {
    pType=nullptr;
  };
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if (!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }
  TType*GetElementType(IEnvRTTI&Env)
  {
    return weak_GetElementType(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("[2014.08.23]: it used?");
    return nullptr;
    //return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
public:
  static inline ptr_t*get(TMemory::ptr_t*ptr)
  {
    return (ptr_t*)(void*)ptr;
  }
};
template<class TYPE>
class TFactory:public IFactory
{
public:
  typedef typename TFactory<TYPE> SelfClass;
  typedef IFactory ParentClass;
  typedef TYPE type;
public:
  void operator=(const TFactory<TYPE>&Ref)=delete;
public:
  void operator=(TFactory<TYPE>&&Ref)
  {
    this->Self=std::move(Ref.Self);
  }
public:
  static TFactory<TYPE>*Get()
  {
    static TFactory<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      TFactory<void>::GetFactorys().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
public:
  static void Create(TYPE*ptr)
  {
    new(ptr) TYPE;
    detail::FieldTryDoReset(*ptr);
  }
  static void Destroy(TYPE*ptr)
  {
    ptr->~TYPE();
  }
  template<class T>
  static void Move(T&dest,T&source)
  {
    dest=std::move(source);
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem)
  {
    Mem.size=sizeof(TYPE);
    pAlloc->Alloc(Mem);
    Create(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem)
  {
    Destroy(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  int GetSize()
  {
    return sizeof(TYPE);
  }
  void UnsafeInit(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Create(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Destroy(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source)
  {
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    auto*pd=get(Dest.ptr);
    auto*ps=get(Source.ptr);
    Move<type>(*pd,*ps);
  }
public:
  string GetElementTypeFullName()const
  {
    return std::move(Sys$$<type>::GetFullName());
  }
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
private:
  static inline TYPE*get(TMemory::ptr_t*ptr)
  {
    return (TYPE*)(void*)ptr;
  }
};
template<>
class TFactory<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<IFactory>>&GetFactorys()
  {
    static vector<TWeakPtr<IFactory>> tmp;
    return tmp;
  }
};
/*
class TAllocator:public IAllocator{
public:
  TMemInfo Info;
  uchar Blob[1024*256];
  int cur;
  TAllocator():cur(0){}
public:
  void Alloc(TProduct&P)
  {
    P.Memory.ptr=(TMemory::ptr_t*)&Blob[cur];
    cur+=P.Memory.size;
    Info.OnAlloc(P);
  }
  void Dealloc(TProduct&P)
  {
    Info.OnDealloc(P);
    memset(P.Memory.ptr,0,P.Memory.size);
    P.Memory.ptr=nullptr;
    P.Memory.size=0;
  }
  TMemInfo&GetMemInfo(){return Info;}
};
*/
class TStdAllocator:public IAllocator
{
public:
  //=====+>>>>>IAllocator
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TStdAllocator SelfClass;
public:
  typedef IAllocator ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TMemInfo Info;
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
    detail::FieldTryDoReset(this->Info);
  }
  //==Declaration Constructors==//
public:
  TStdAllocator(const TStdAllocator&)=delete;
  TStdAllocator()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TStdAllocator(TStdAllocator&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TStdAllocator&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(IAllocator(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      IAllocator::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
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
      static const string Name="TStdAllocator";
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
      Info->AddMemberDEF(Sys$$<TMemInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");
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
      return "TStdAllocator";
      //[Line](<=)
    }
  };
public:
  //<<<<<+=====IAllocator
public:
  void Alloc(TMemory&Mem)
  {
    Mem.ptr=(TMemory::ptr_t*)new uchar[Mem.size];
    Info.OnAlloc(Mem);
  }
  void Dealloc(TMemory&Mem)
  {
    Info.OnDealloc(Mem);
    memset(Mem.ptr,0,Mem.size);
    delete[] (uchar*)Mem.ptr;
    Mem.ptr=nullptr;
  }
  TMemInfo&GetMemInfo()
  {
    return Info;
  }
};

//IEnvRTTI
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
class TRTTIProduct;
//Менеджер-костыль.
template<class TYPE>
class RTTIManager
{
public:
  typedef std::pair<TWeakPtr<IEnvRTTI>,TWeakPtr<TType>> elem;
  vector<elem> Arr;
public:
  static RTTIManager<TYPE>*Get()
  {
    static RTTIManager<TYPE> global;
    return &global;
  }
public:
  elem*FindEnv(IEnvRTTI*Env)
  {
    for (int i=0;i<Arr.size();i++)
    {
      auto&EX=Arr[i];
      auto*ptr=EX.first.get();
      if (ptr==Env)return &EX;
    }
    return nullptr;
  }
  template<class U>
  bool GetPleaseInfo(IEnvRTTI*Env,U*(&val))
  {
    {
      U*u=nullptr;
      TType*t=nullptr;
      t=u;
    }
    elem*el=FindEnv(Env);
    val=(U*)(el?el->second.get():nullptr);
    return el;
  }
  template<class U>
  void SetPleaseInfo(IEnvRTTI*Env,U*val)
  {
    elem*el=FindEnv(Env);
    if (!el)
    {
      Arr.push_back(std::move(elem(Env,val)));
      if (Arr.size()>1)
      {
        QapDebugMsg("over 1 IEnvRTTI instance detected!");
      }
      return;
    }
    el->first=Env;
    el->second=val;
    return;
  }
};
template<class TYPE>
bool QapCanDestroy(TAutoPtr<TYPE>&Ref)
{
  return Ref&&Ref->Self.P.HardCount==1;
}
class EnvType
{
public:
//=====+>>>>>EnvType
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef EnvType SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TSelfPtr<SelfClass> Self;
  TAutoPtr<TType> Type;
  TAutoPtr<IFactory> Factory;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->Self);
    detail::FieldTryDoReset(this->Type);
    detail::FieldTryDoReset(this->Factory);
  }
  //==Declaration Constructors==//
public:
  EnvType(const EnvType&)=delete;
  EnvType()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  EnvType(EnvType&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(EnvType&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->Self=std::move(_Right.Self);
    this->Type=std::move(_Right.Type);
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
      static const string Name="EnvType";
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
      Info->AddMemberDEF(Sys$$<TAutoPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
      Info->AddMemberDEF(Sys$$<TAutoPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
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
      return "EnvType";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====EnvType
public:
  static void SysHasSelf();
public:
  //[Line](=>)
  bool CheckFactory()
  {
    return weak_CheckFactory<0>();
  };
  ;
  template<int>bool weak_CheckFactory()
  //[Line](<=)
  {
    if (Factory)
    {
      QapAssert(Type);
      return Type->Factory.get()==Factory.get();
    }
    if (!Factory)
    {
      QapAssert(Type&&Type->Factory);
      return true;
    }
    return false;
  }
public:
//  TType*GetType()
//  {
//    noway;
//    return Type.get();
//  }
//public:
//  #define MACRO_WEAK
//  #include "macro_scope.inl"
//  MACRO_WEAK_FUNC(IAllocator*,GetAlloc,(),()){return Env->GetAlloc();}
//  #include "macro_scope.inl"
//public:
//  IFactory*GetFactory()
//  {
//    noway;
//    return Factory.get();
//  }
//  EnvType*GetTypeProductEnvType()
//  {
//    noway;
//    return Type.getProductEnvType();
//  }
//  bool CanDestroy()
//  {
//    noway;
//    bool flag=Self.P.HardCount==1;
//    QapAssert(bool(Type)==bool(Factory));
//    if(QapCanDestroy(Type))return flag;
//    if(!Type&&!Factory)return flag;
//    return false;
//  }
};
//Окружение метатипов.
class IEnvRTTI
{
public:
//=====+>>>>>IEnvRTTI
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IEnvRTTI SelfClass;
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
  IEnvRTTI(const IEnvRTTI&)=delete;
  IEnvRTTI()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IEnvRTTI(IEnvRTTI&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IEnvRTTI&&_Right)
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
      static const string Name="IEnvRTTI";
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
      return "IEnvRTTI";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IEnvRTTI
public:
  static void SysHasSelf();
public:
  virtual IAllocator*GetAlloc()
  {
    QapDebugMsg("no way");
    return nullptr;
  }
  virtual int RegInfo(TAutoPtr<TType>&&_Right)
  {
    QapDebugMsg("no way");
    return 0;
  }
  virtual EnvType&GetEnvTypeById(int id)
  {
    QapDebugMsg("no way");
    return *(EnvType*)nullptr;
  }
  virtual vector<EnvType>&GetArr()
  {
    QapDebugMsg("no way");
    return *(vector<EnvType>*)nullptr;
  }
  virtual void OnRegBeg(TType*Info)
  {
    QapDebugMsg("no way");
  }
  virtual void OnRegRet(TType*Info)
  {
    QapDebugMsg("no way");
  }
  virtual void OnRegEnd(TType*Info)
  {
    QapDebugMsg("no way");
  }
  virtual IEnvRTTI*GetOwnerEnv()
  {
    QapDebugMsg("no way");
    return nullptr;
  }
public:
  template<int>
  struct template_detail
  {
    static bool campare_type_full_name(TType*pType,const string&fn)
    {
      return pType->GetFullName()==fn;
    }
  };
  struct TTypeFullNameComparator
  {
    const string&fn;
    TTypeFullNameComparator(const string&fn):fn(fn) {}
    bool operator()(EnvType&ex)
    {
      return template_detail<0>::campare_type_full_name(ex.Type.get(),fn);
    }
  };
public:
  TType*FindTypeByName_is_ug_but_work(const string&fn)
  {
    auto&types=GetArr();
    auto&arr=qap_find(types,TTypeFullNameComparator(fn));
    QapAssert(arr.size()<=1);
    if (arr.empty())return nullptr;
    return types[arr[0]].Type.get();
  }
  TType*FindTypeByFactory(IFactory*pFactory)
  {
    return weak_FindTypeByFactory<void>(pFactory);
  }
  template<class TYPE>
  TType*weak_FindTypeByFactory(IFactory*pFactory)
  {
    if (!pFactory)return nullptr;
    auto&arr=GetArr();
    for (int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if (pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
public:
  bool IsRootEnv()
  {
    return GetOwnerEnv()==this;
  }
  IEnvRTTI*GetRootEnv()
  {
    IEnvRTTI*pEnv=this;
    while (pEnv)
    {
      auto*p=pEnv->GetOwnerEnv();
      if (p==pEnv)return pEnv;
      pEnv=p;
    }
    QapDebugMsg("WTF?");
    return nullptr;
  }
public:
  template<class REG_TYPE,class INFO_TYPE>
  bool Register(INFO_TYPE*(&Info),const string&Name)
  {
    typedef RTTIManager<REG_TYPE> ManType;
    static_assert(std::is_base_of<TType,INFO_TYPE>::value,"bad");
    if (true)
    {
      auto*RootEnv=GetRootEnv();
      if (RootEnv!=this)
      {
        bool flag=RootEnv->Register<REG_TYPE>(Info,Name);
        TType*pType=Info;
        pType=FindTypeByFactory(pType->Factory.get());
        if (!flag)QapAssert(!pType);
        if (!pType)
        {
          QapDebugMsg("type '"+Sys$$<REG_TYPE>::GetFullName()+"' - not found");
        }
        Info=(INFO_TYPE*)pType;
        return true;
      }
    }
    ManType*Man=ManType::Get();
    Man->GetPleaseInfo(this,Info);
    if (Info)
    {
      if (false)OnRegRet(Info);
      return true;
    }
    else
    {
      {
        TProduct prod;
        prod.Alloc=GetAlloc();
        prod.Factory=TFactory<INFO_TYPE>::Get();
        prod.Init();
        Info=(INFO_TYPE*)prod.Memory.ptr;
        Man->SetPleaseInfo(this,Info);
        Info->Info.Name=Name;
        Info->Info.Size=sizeof(REG_TYPE);
        Info->Info.Align=detail::QapAlignOf<REG_TYPE>::value;
        this->OnRegBeg(Info);
        {
          TAutoPtr<INFO_TYPE> tmp;//=UberInit<INFO_TYPE>(*this);
          tmp.Product.Memory=std::move(prod.Memory);
          int id=RegInfo(std::move(tmp));
          TType*pType=Sys$$<INFO_TYPE>::GetRTTI(*this);// this is fucking design error
          GetEnvTypeById(id).Type.Product.pType=pType;
        }
        __if_exists(INFO_TYPE::extInfo)
        {
          Info->extInfo.SpecInfo=detail::GetSpecInfo<REG_TYPE>();
          Info->extInfo.Polymorph=std::is_polymorphic<REG_TYPE>::value;
          Info->extInfo.Abstract=std::is_abstract<REG_TYPE>::value;
        }
      }
      typedef detail::select<std::is_abstract<REG_TYPE>::value,void,REG_TYPE>::type select;
      Info->Factory=TFactory<select>::Get();
      Info->Env=this;
      //this->EndReg(Info);
      return false;
    }
  }
};
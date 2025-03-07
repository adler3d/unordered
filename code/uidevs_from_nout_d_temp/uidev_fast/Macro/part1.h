//part1
class IBinIO
{
public:
//=====+>>>>>IBinIO
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IBinIO SelfClass;
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
  IBinIO(const IBinIO&)=delete;
  IBinIO()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IBinIO(IBinIO&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IBinIO&&_Right)
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
      static const string Name="IBinIO";
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
      return "IBinIO";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IBinIO
public:
  static void SysHasSelf();
public:
  virtual void Save(QapIO&IO,void*p)
  {
    QapDebugMsg("no way.");
  }
  virtual void Load(QapIO&IO,void*p)
  {
    QapDebugMsg("no way.");
  }
public:
  virtual void Copy(void*pOut,void*pInp)
  {
    QapDebugMsg("no way.");
  }
  virtual bool IsSame(void*pA,void*pB)
  {
    QapDebugMsg("no way.");
    return *(bool*)nullptr;
  }
public:
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
  ~IBinIO() {}
};
class ITxtIO
{
public:
//=====+>>>>>ITxtIO
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef ITxtIO SelfClass;
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
  ITxtIO(const ITxtIO&)=delete;
  ITxtIO()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  ITxtIO(ITxtIO&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(ITxtIO&&_Right)
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
      static const string Name="ITxtIO";
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
      return "ITxtIO";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====ITxtIO
public:
  static void SysHasSelf();
public:
  virtual void Save(string&s,void*p)
  {
    QapDebugMsg("no way.");
  }
  virtual void Load(string&s,void*p)
  {
    QapDebugMsg("no way.");
  }
public:
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
  ~ITxtIO() {}
};
template<class TYPE>
class TBinIO:public IBinIO
{
public:
  typedef IBinIO ParentClass;
  typedef typename TYPE type;
  typedef typename TBinIO<TYPE> SelfClass;
public:
  void Save(QapIO&IO,void*p)
  {
    IO.SavePOD(p,sizeof(type));
  }
  void Load(QapIO&IO,void*p)
  {
    IO.LoadPOD(p,sizeof(type));
  }
public:
  void Copy(void*pOut,void*pInp)
  {
    TYPE&out=*(TYPE*)pOut;
    TYPE&inp=*(TYPE*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB)
  {
    TYPE&a=*(TYPE*)pA;
    TYPE&b=*(TYPE*)pB;
    return a==b;
  }
};
template<class TYPE>
class TTxtIO:public TBinIO<TYPE>
{
public:
  typedef void SelfClass;
public:
  virtual void Save(string&s,void*p)
  {
    static_assert(false,"not ready");
  }
  virtual void Load(string&s,void*p)
  {
    static_assert(false,"not ready");
  }
};
template<class TYPE>
class THeadBinIO:public TBinIO<TYPE>
{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<ParentClass>::GetRTTI(Env);
  };
public:
  static THeadBinIO<TYPE>*Get()
  {
    static THeadBinIO<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      THeadBinIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<class TYPE>
class THeadCppIO:public TTxtIO<TYPE>
{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<ParentClass>::GetRTTI(Env);
  };
public:
  static THeadCppIO<TYPE>*Get()
  {
    static THeadCppIO<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      THeadCppIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<>
class THeadBinIO<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<IBinIO>>&GetArr()
  {
    static vector<TWeakPtr<IBinIO>> tmp;
    return tmp;
  }
};
template<>
class THeadCppIO<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<ITxtIO>>&GetArr()
  {
    static vector<TWeakPtr<ITxtIO>> tmp;
    return tmp;
  }
};
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
class IVectorAPI
{
public:
//=====+>>>>>IVectorAPI
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef IVectorAPI SelfClass;
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
  IVectorAPI(const IVectorAPI&)=delete;
  IVectorAPI()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  IVectorAPI(IVectorAPI&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(IVectorAPI&&_Right)
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
      static const string Name="IVectorAPI";
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
      return "IVectorAPI";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====IVectorAPI
public:
  typedef int SizeType;
  //IVectorAPI(){}//please do not remove constructor
  ~IVectorAPI() {}//please do not remove destructor
  virtual SizeType GetCount(void*p)
  {
    QapDebugMsg("no way.");
    return 0;
  }//{vector<TYPE>&v=*(vector<TYPE>*)p;return v.size();}
  virtual void SetCount(void*p,SizeType c)
  {
    QapDebugMsg("no way.");
  }//{vector<TYPE>&v=*(vector<TYPE>*)p;v.resize(c);}
  virtual void*GetItem(void*p,SizeType i)
  {
    QapDebugMsg("no way.");
    return nullptr;
  }//{vector<TYPE>&v=*(vector<TYPE>*)p;return &v[i];}
public:
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
};
template<class TYPE>
class TVectorAPI:public IVectorAPI
{
public:
  typedef typename TYPE type;
  typedef IVectorAPI ParentClass;
  typedef TVectorAPI<type> SelfClass;
public:
  virtual SizeType GetCount(void*p)
  {
    vector<TYPE>&v=*(vector<TYPE>*)p;
    return v.size();
  }
  virtual void SetCount(void*p,SizeType c)
  {
    vector<TYPE>&v=*(vector<TYPE>*)p;
    v.resize(c);
  }
  virtual void*GetItem(void*p,SizeType i)
  {
    vector<TYPE>&v=*(vector<TYPE>*)p;
    return &v[i];
  }
public:
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("What does this code mean?");
    return nullptr;
    //return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
public:
  static TVectorAPI<TYPE>*Get()
  {
    static TVectorAPI<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      TVectorAPI<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<>
class TVectorAPI<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<IVectorAPI>>&GetArr()
  {
    static vector<TWeakPtr<IVectorAPI>> tmp;
    return tmp;
  }
};

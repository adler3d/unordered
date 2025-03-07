//part4
class DeclareType;
struct EnvVoidPtr
{
  typedef TServerPtr<IEsoteric>ptr_t;
  ptr_t*ptr;
  TType*type;
  EnvVoidPtr():ptr(nullptr),type(nullptr) {};
  EnvVoidPtr(ptr_t*ptr,TType*type=nullptr):ptr(ptr),type(type) {}
  ptr_t::ptr_t*get()const
  {
    return ptr?ptr->ptr:nullptr;
  }
  bool IsValid()const
  {
    return bool(ptr)&&bool(type);
  }
  bool IsNull()const
  {
    return bool(!ptr)&&bool(!type);
  }
  template<class TYPE>
  void set(const TAutoPtr<TYPE>&ref)
  {
    ptr=nullptr;
    type=nullptr;
    if (!ref)return;
    ptr=(ptr_t*)(void*)&ref.get()->Self;
    type=ref.Product.pType.get();
  }
  void set_zero()
  {
    ptr=nullptr;
    type=nullptr;
  }
  bool operator==(const EnvVoidPtr&ref)const
  {
    return oper_eq(ref);
  }
  bool operator!=(const EnvVoidPtr&ref)const
  {
    return !oper_eq(ref);
  }
  bool oper_eq(const EnvVoidPtr&ref)const
  {
    return (this->ptr==ref.ptr)&&(this->type==ref.type);
  }
  //template<class TYPE>
  //void set(TSelfPtr<TYPE>&ref){ptr=(ptr_t*)&ref.P;}
};
class EnvItem
{
public:
//=====+>>>>>EnvItem
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef EnvItem SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  int id;
  EnvVoidPtr ptr;
  EnvVoidPtr ptr_lnk;
  string name;
  int count;
  bool passed;
  bool system;
  bool hidden;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    (this->id)=(0);
    detail::FieldTryDoReset(this->ptr);
    detail::FieldTryDoReset(this->ptr_lnk);
    (this->name)=("");
    (this->count)=(0);
    (this->passed)=(false);
    (this->system)=(false);
    (this->hidden)=(false);
  }
  //==Declaration Constructors==//
public:
  EnvItem(const EnvItem&)=delete;
  EnvItem()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  EnvItem(EnvItem&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(EnvItem&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->id=std::move(_Right.id);
    this->ptr=std::move(_Right.ptr);
    this->ptr_lnk=std::move(_Right.ptr_lnk);
    this->name=std::move(_Right.name);
    this->count=std::move(_Right.count);
    this->passed=std::move(_Right.passed);
    this->system=std::move(_Right.system);
    this->hidden=std::move(_Right.hidden);
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
      static const string Name="EnvItem";
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
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","0");
      Info->AddMemberDEF(Sys$$<EnvVoidPtr>::GetRTTI(RTTI),"ptr",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr))),"DEF","$");
      Info->AddMemberDEF(Sys$$<EnvVoidPtr>::GetRTTI(RTTI),"ptr_lnk",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr_lnk))),"DEF","$");
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"SET","\"\"");
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"count",int(&(((SelfClass*)nullptr)->*(&SelfClass::count))),"SET","0");
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"passed",int(&(((SelfClass*)nullptr)->*(&SelfClass::passed))),"SET","false");
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"system",int(&(((SelfClass*)nullptr)->*(&SelfClass::system))),"SET","false");
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"hidden",int(&(((SelfClass*)nullptr)->*(&SelfClass::hidden))),"SET","false");
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
      return "EnvItem";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====EnvItem
public:
  EnvItem&copy(const EnvItem&source)
  {
    //hard code detected
    this->id=source.id;
    this->name=source.name;
    this->ptr=source.ptr;
    this->ptr_lnk=source.ptr_lnk;
    this->count=source.count;
    this->passed=source.passed;
    this->system=source.system;
    this->hidden=source.hidden;
    return *this;
  }
  void CheckNullptr()
  {
    QapAssert(id==0);
    QapAssert(ptr.IsNull());
    QapAssert(ptr_lnk.IsNull());
    QapAssert(name=="nullptr");
    QapAssert(count==1);
    QapAssert(passed==true);
    QapAssert(system==true);
    QapAssert(hidden==false);
  }
  bool oper_eq(const SelfClass&ref,bool ignore_id=false)const
  {
    bool result=ignore_id||(this->id==ref.id);
    result=result&&(this->name==ref.name);
    result=result&&(this->ptr==ref.ptr);
    result=result&&(this->ptr_lnk==ref.ptr_lnk);
    result=result&&(this->count==ref.count);
    result=result&&(this->passed==ref.passed);
    result=result&&(this->system==ref.system);
    result=result&&(this->hidden==ref.hidden);
    return result;
  }
  bool operator==(const SelfClass&ref)const
  {
    return oper_eq(ref);
  }
  bool IsNoUsed()
  {
    return id&&ptr.IsNull()&&ptr_lnk.IsNull();
  }
  void SetAsNullptr()
  {
    name="nullptr";
    count=1;
    passed=true;
    system=true;
    hidden=false;
  }
  template<class TYPE>
  EnvItem&weak_get_lnk(TServerPtrSpace&Space)const
  {
    QapAssert(ptr_lnk.IsValid());
    int SID=ptr_lnk.ptr->SaveID;
    QapAssert(Space.IsAllowed(SID));
    auto&item=Space[SID];
    QapAssert(this->ptr_lnk.ptr==item.ptr.ptr);
    QapAssert(this->ptr_lnk.type==item.ptr.type);
    return item;
  }
  EnvItem&get_lnk(TServerPtrSpace&Space)const
  {
    return weak_get_lnk<void>(Space);
  }
};
struct SpaceMutator
{
  vector<EnvVoidPtr::ptr_t*> arr;
  int find_key_by_value(EnvVoidPtr::ptr_t*ptr)
  {
    for (int i=0;i<arr.size();i++)
    {
      if (arr[i]==ptr)return i;
    }
    return -1;
  }
  bool has_value(EnvVoidPtr::ptr_t*ptr)
  {
    return find_key_by_value(ptr)!=-1;
  }
};
class TServerPtrSpace
{
public:
  typedef TServerPtrSpace SelfClass;
public:
  vector<EnvItem> Arr;
public:
  void operator=(SelfClass&&Ref)
  {
    clear();
    //hard code detected
    Arr=std::move(Ref.Arr);
  }
  TServerPtrSpace(SelfClass&&Ref)
  {
    clear();
    //hard code detected
    Arr=std::move(Ref.Arr);
  }
  TServerPtrSpace()
  {
    Arr.reserve(1024*128);
    auto&ex=UnsafeAdd(nullptr,nullptr);
    ex.SetAsNullptr();
  }
  ~TServerPtrSpace()
  {
    clear();
  }
public:
  void hack_clear()
  {
    for (int i=0;i<Arr.size();i++)
    {
      Del(Arr[i],true);
    }
    Arr.clear();
  }
  void clear()
  {
    for (int i=0;i<Arr.size();i++)
    {
      Del(Arr[i]);
    }
    Arr.clear();
  }
public:
  static void make_linked(EnvItem&a,EnvItem&b)
  {
    bool f0=a.ptr_lnk.IsNull();
    bool f1=b.ptr_lnk.IsNull();
    QapAssert(f0&&f1);
    a.ptr_lnk=b.ptr;
    b.ptr_lnk=a.ptr;
  };
public:
  bool CheckServTID(int tid)
  {
    if (!IsAllowed(tid))return false;
    auto&item=Arr[tid];
    bool flag=true;
    flag=item.ptr.ptr;
    QapAssert(flag);
    flag=tid==item.ptr.ptr->SaveID;
    QapAssert(flag);
    return flag;
  }
  bool CheckServSaveID(TServerPtr<IEsoteric>*pServ=nullptr)const
  {
    QapAssert(pServ);
    int SaveID=pServ->SaveID;
    {
      bool flag=(SaveID>0)&&(SaveID<Arr.size());
      if (!flag)
      {
        QapAssert(!SaveID);
        return false;
      }
    }
    auto&ex=Arr[SaveID];
    bool flag=ex.ptr.ptr==pServ;
    QapAssert(flag);
    return flag;
  }
  EnvItem&UnsafeAdd(const EnvVoidPtr&ptr)
  {
    // mod time : 29.06.2012
    int id=Arr.size();
    {
      if (id>=Arr.capacity())QapDebugMsg("grow are not allowed here.\n"+IToS(Arr.capacity()));
      EnvItem tmp;
      Arr.push_back(std::move(tmp));
    }
    auto&back=Arr.back();
    auto*pServ=ptr.ptr;
    if (pServ)pServ->SaveID=id;
    back.id=id;
    back.ptr=ptr;
    return back;
  }
  EnvItem&Insert(const EnvItem&item)
  {
    // mod time : 05.07.2012
    int id=Arr.size();
    {
      EnvItem tmp;
      Arr.push_back(std::move(tmp));
    }
    auto&back=Arr.back();
    back.copy(item).id=id;
    auto connect=[id](EnvVoidPtr&ptr)->void
    {
      auto*p=ptr.ptr;
      if (!p)return;
      int&sid=p->SaveID;
      QapAssert(!sid);
      sid=id;
    };
    connect(back.ptr);
    //neverconnect(back.ptr_adv);
    return back;
  }
  EnvItem&InsertTo(int id,const EnvItem&item)
  {
    auto&back=Arr[id];
    QapAssert(back.IsNoUsed());
    back.copy(item).id=id;
    auto connect=[id](EnvVoidPtr&ptr)->void
    {
      auto*p=ptr.ptr;
      if (!p)return;
      int&sid=p->SaveID;
      QapAssert(!sid);
      sid=id;
    };
    connect(back.ptr);
    //neverconnect(back.ptr_adv);
    return back;
  }
  EnvItem&UnsafeAdd(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr)
  {
    return UnsafeAdd(EnvVoidPtr(pServ,pType));
  }
  EnvItem&AddExt(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr,const string&name="")
  {
    QapAssert(pServ);
    if (true)
    {
      bool flag=CheckServSaveID(pServ);
      if (flag)
      {
        QapAssert(false);
        return Arr[pServ->SaveID];
      }
    }
    auto&back=UnsafeAdd(pServ,pType);
    back.name=name;
    return back;
  }
  void Del(EnvItem&item,bool hack_mode=false)
  {
    Del(item.ptr.ptr,hack_mode);
  }
  void Del(TServerPtr<IEsoteric>*pServ,bool hack_mode=false)
  {
    // mod time : 01.08.2012
    if (!pServ)return;
    QapAssert(pServ->SaveID);
    {
      const int&id=pServ->SaveID;
      QapAssert(IsAllowed(id));
      auto&ex=Arr[id];
      QapAssert(ex.id==id);
      if (1)
      {
        bool f[]=
        {
          ex.ptr.ptr==pServ,
          ex.ptr_lnk.ptr==pServ
        };
        QapAssert(f[0]!=f[1]);
      }
      ex.ptr=nullptr;
      if (!hack_mode)if (ex.ptr_lnk.ptr)
        {
          QapAssert(ex.ptr_lnk.ptr->SaveID!=id);
        }
      ex.ptr_lnk=nullptr;
    }
    pServ->SaveID=0;
  }
  EnvVoidPtr::ptr_t*GetPtrByID(int id)
  {
    return Arr[id].ptr.ptr;
  }
  EnvVoidPtr::ptr_t*GetAdvPtrByID(int id)
  {
    return Arr[id].ptr_lnk.ptr;
  }
public:
  //Item&operator[](const EnvItem&index){return Arr[index.id];}
  //const Item&operator[](const EnvItem&index)const{return Arr[index.id];}
  EnvItem&operator[](int index)
  {
    return Arr[index];
  }
  const EnvItem&operator[](int index)const
  {
    return Arr[index];
  }
public:
  template<class TYPE>
  EnvItem&operator[](const TSelfPtr<TYPE>&index)
  {
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
  template<class TYPE>
  const EnvItem&operator[](const TSelfPtr<TYPE>&index)const
  {
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
public:
  bool IsAllowed(int index)
  {
    return (0<=index)&&(index<Arr.size());
  }
  bool IsSolved(int index)
  {
    return IsAllowed(index)&&(Arr[index].ptr.ptr);
  }
  int size()
  {
    return Arr.size();
  }
public:
  void resize(int count)
  {
    QapAssert(count>=size());
    for (int i=size();i<count;i++)
    {
      UnsafeAdd(nullptr,nullptr);
    }
  }
public:
  void Repack()
  {
    //Эта штука выбрасывает из Arr все EnvItem'ы у которых count==0.
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    for (int i=0;i<tmpSpace.size();i++)
    {
      auto&item=tmpSpace[i];
      if (!item.count)continue;
      {
        EnvItem temp;
        temp.copy(item);
        tmpSpace.Del(item);
        auto&back=Space.Insert(temp);
        QapAssert(&back==&Space[back.id]);
      }
    }
  }
  /*
    RepackV2 разделяет одно пространство на два.
    примечание:
      нулевой элемент во всех проастарнства - nullptr. nullptr`ы мы не трогаем.
    Space0.size() == N.
    Space1.size() == X.
    Space2.size() == N.
    Space0: все N - элементов исправны.
    Space1: все X - элементов исправны.
    Space2: превые X - элементов не исправны. остальные исправны.
    Space0: this - до RepackV2
    Space1: this - после RepackV2
    Space2: Out - после RepackV2
  */
  void RepackV2(SelfClass&Out)
  {
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    Space=std::move(TSpace());
    Out=std::move(TSpace());
    Out.resize(tmpSpace.size());
    int X=1;
    for (int i=1;i<tmpSpace.size();i++)if (tmpSpace[i].count)X++;
    for (int i=1;i<tmpSpace.size();i++)
    {
      auto&item=tmpSpace[i];
      if (!item.count)
      {
        auto&space=Out;
        EnvItem temp;
        temp.copy(item);
        tmpSpace.Del(item);
        auto&back=space.InsertTo(X,temp);
        QapAssert(&back==&space[back.id]);
        X++;
        continue;
      }
      if (item.count)
      {
        auto&space=Space;
        EnvItem temp;
        temp.copy(item);
        tmpSpace.Del(item);
        auto&back=space.Insert(temp);
        QapAssert(&back==&space[back.id]);
        continue;
      }
    }
  }
public:
  void Mutate(SpaceMutator&SM)
  {
    //Эта штука выбрасывает из Arr все EnvItem'ы у которых count==0.
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    Space.reserve(tmpSpace.size());
    auto func=[&tmpSpace,&Space](int i)
    {
      auto&item=tmpSpace[i];
      if (item.id==-1)return;
      EnvItem temp;
      temp.copy(item);
      tmpSpace.Del(item);
      auto&back=Space.Insert(temp);
      QapAssert(&back==&Space[back.id]);
    };
    func(0);
    auto&arr=SM.arr;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      QapAssert(ex->SaveID);
      QapAssert(tmpSpace.IsAllowed(ex->SaveID));
      auto&item=tmpSpace[ex->SaveID];
      QapAssert(item.id>0);
      QapAssert(item.id==ex->SaveID);
      //if(!item.count)continue;
      {
        EnvItem temp;
        temp.copy(item);
        tmpSpace.Del(item);
        item.id=-1;
        auto&back=Space.Insert(temp);
        QapAssert(&back==&Space[back.id]);
      }
    }
    for (int i=1;i<tmpSpace.size();i++)func(i);
  }
public:
  void CopyAdvFrom(SelfClass&Source)
  {
    QapDebugMsg("deprecated");
    auto&arr=Source.Arr;
    clear();
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (ex.ptr_lnk.IsNull())
      {
        EnvItem tmp;
        Insert(tmp);
        continue;
      }
      //string&name=Source[ex.ptr_adv.ptr->SaveID].name;
      auto name=ex.name+"->getLink()";
      AddExt(ex.ptr_lnk.ptr,ex.ptr_lnk.type,name);
    }
  }
  void CopyAdvFromV2(SelfClass&Source,SelfClass&BigSpace)
  {
    auto&arr=Source.Arr;
    (*this)=std::move(SelfClass());
    for (int i=1;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (ex.ptr_lnk.IsNull())
      {
        EnvItem tmp;
        Insert(tmp);
        continue;
      }
      auto&item=BigSpace[ex.ptr_lnk.ptr->SaveID];
      EnvItem temp;
      temp.copy(item);
      BigSpace.Del(item);
      Insert(temp);
    }
  }
public:
  void Swap(int A,int B)
  {
    //QapAssert(A!=B);
    if (A==B)return;
    EnvItem ta;
    EnvItem tb;
    auto&Space=*this;
    auto&a=Space[A];
    auto&b=Space[B];
    ta.copy(a);
    tb.copy(b);
    Del(a);
    Del(b);
    InsertTo(A,tb);
    InsertTo(B,ta);
  }
public:
  template<class TYPE>
  static void ClientMarker(TYPE&Space,TType*pType,void*pValue)
  {
    ::ClientMarker(Space,pType,pValue);
  }
public:
  template<class TYPE>
  void SolveDepends(TYPE&temp)
  {
    static_assert(std::is_same<DependsSolver,TYPE>::value,"error");
    temp.SolveDepends(*this);
  }
public:
  string GetListOfNoPassed(bool all)
  {
    string log;
    auto&arr=Arr;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (!all)if (!ex.count||ex.passed)continue;
      log+=ex.name+"\n";
    }
    return log;
  };
  bool CheckHidden()
  {
    int errors=0;
    auto&arr=Arr;
    for (int i=0;i<arr.size();i++)
    {
      auto&item=arr[i];
      if (item.hidden&&item.count)
      {
        QapDebugMsg("item(\""+item.name+"\").count = "+IToS(item.count));
        errors++;
      }
    }
    return !errors;
  };
public:
  EnvItem*find_by_name(const string&name)
  {
    for (int i=0;i<size();i++)
    {
      EnvItem&EX=Arr[i];
      if (name==EX.name)return &EX;
    }
    return nullptr;
  }
public:
  bool IsValid()
  {
    if (Arr.empty())
    {
      QapAssert("undefine behevior. also: may be true");
      return true;
    }
    Arr[0].CheckNullptr();
    for (int i=1;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      if (!item.ptr.type&&!item.ptr.ptr)return false;
      if (1)
      {
        bool flag=bool(item.ptr_lnk.ptr)==bool(item.ptr_lnk.type);
        if (!flag)return false;
      }
    }
    return true;
  }
public:
  void reserve(int _Count)
  {
    Arr.reserve(_Count);
  }
public:
  void AddPointsFromSys()
  {
    weak_detail<void>::AddPointsFromSys(*this);
  }
  void AddPointsFromEnv(IEnvRTTI&Env)
  {
    weak_detail<void>::AddPointsFromEnv(*this,Env);
  }
  void AddPointsFrom(const TRawPtr&ptr)
  {
    weak_detail<void>::AddPointsFrom(*this,ptr);
  }
  void UpdatePointsTypeFrom(const TRawPtr&ptr)
  {
    weak_detail<void>::UpdatePointsTypeFrom(*this,ptr);
  }
  template<class TYPE>
  struct weak_detail
  {
    static void AddPointsFromSys(TServerPtrSpace&Space)
    {
      EnvAdapter::GoSys(Space);
    }
    static void AddPointsFromEnv(TServerPtrSpace&Space,IEnvRTTI&Env)
    {
      EnvAdapter::GoEnv(Space,Env,EnvAdapter::TMetaTypePack(Env));
    }
    static void AddPointsFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      GrabServerPtr(Space,ptr.pType,ptr.pValue,true);
    }
    struct UnnamedStruct
    {
      typedef TServerPtrSpace TSpace;
      TSpace&Space;
      UnnamedStruct(TSpace&Space):Space(Space) {}
      void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
      {
        if (!Space.CheckServSaveID(&Serv))
        {
          QapDebugMsg("bad news");
          return;
        }
        auto&ex=Space[Serv.SaveID];
        QapAssert(elemType);
        if (ex.ptr.type==elemType)
        {
          QapAssert(elemType);
          QapAssert(!ex.ptr.type);
          return;
        }
        ex.ptr.type=elemType;
      }
    };
    static void UpdatePointsTypeFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      class TServerPtrTypeUpdater:public TSmartPtrVisitor::ICallBack
      {
      public:
        UnnamedStruct Field;
        TServerPtrTypeUpdater(TServerPtrSpace&Space):Field(Space) {}
      public:
        void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
        {
          Field.Visit(Serv,elemType);
        }
        void Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
        void Visit(THardClientPtr<IEsoteric>&A,TType*elemType) {}
        void Visit(TClientPtr<IEsoteric>&A) {}
        void Visit(THardClientPtr<IEsoteric>&A) {}
      };
      TServerPtrTypeUpdater Updater(Space);
      TSmartPtrVisitor SPG(Updater,ptr.pValue);
      ptr.pType->Use(SPG);
    }
  };
};
class TBigMetaTypePack
{
public:
//=====+>>>>>TBigMetaTypePack
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TBigMetaTypePack SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TType*pEnvType;
  TType*pTType;
  TType*pTTypeStruct;
  TType*pTTypeSys;
  TType*pDeclareType;
  TType*pDeclareTypeStruct;
  TType*pDeclareTypeSys;
  //[Line](<=)
  //==Declaration DoReset==//
  void DoReset()
  {
    //[Line](=>)
    this->pEnvType=nullptr;
    this->pTType=nullptr;
    this->pTTypeStruct=nullptr;
    this->pTTypeSys=nullptr;
    this->pDeclareType=nullptr;
    this->pDeclareTypeStruct=nullptr;
    this->pDeclareTypeSys=nullptr;
    //[Line](<=)
  }
  //==Declaration Constructors==//
  TBigMetaTypePack(const SelfClass&ref)
  {
    DoReset();
    oper_set(ref);
  }
  TBigMetaTypePack()
  {
    DoReset();
  }
  TBigMetaTypePack(IEnvRTTI&Env)
  {
    DoReset();
    prepare(Env);
  }
  template<class TYPE>TBigMetaTypePack(const TYPE&ref)
  {
    DoReset();
    oper_set(ref);
  }
  //==Declaration prepare==//
  template<class QAP_RTTI>
  void prepare(QAP_RTTI&Env)
  {
    //[Line](=>)
    this->pEnvType=Sys$$<EnvType>::GetRTTI((IEnvRTTI&)Env);
    this->pTType=Sys$$<TType>::GetRTTI((IEnvRTTI&)Env);
    this->pTTypeStruct=Sys$$<TTypeStruct>::GetRTTI((IEnvRTTI&)Env);
    this->pTTypeSys=Sys$$<TTypeSys>::GetRTTI((IEnvRTTI&)Env);
    this->pDeclareType=Sys$$<DeclareType>::GetRTTI((IEnvRTTI&)Env);
    this->pDeclareTypeStruct=Sys$$<DeclareTypeStruct>::GetRTTI((IEnvRTTI&)Env);
    this->pDeclareTypeSys=Sys$$<DeclareTypeSys>::GetRTTI((IEnvRTTI&)Env);
    //[Line](<=)
  }
  //==Declaration oper_set==//
  void oper_set(const SelfClass&ref)
  {
    //[Line](=>)
    this->pEnvType=ref.pEnvType;
    this->pTType=ref.pTType;
    this->pTTypeStruct=ref.pTTypeStruct;
    this->pTTypeSys=ref.pTTypeSys;
    this->pDeclareType=ref.pDeclareType;
    this->pDeclareTypeStruct=ref.pDeclareTypeStruct;
    this->pDeclareTypeSys=ref.pDeclareTypeSys;
    //[Line](<=)
  }
  template<class TYPE>
  void oper_set(const TYPE&ref)
  {
    //[Line](=>)
    static_assert(std::is_same<std::remove_reference<decltype(this->pEnvType)>::type,std::remove_reference<decltype(ref.pEnvType)>::type>::value,"no way");
    this->pEnvType=ref.pEnvType;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");
    this->pTType=ref.pTType;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeStruct)>::type,std::remove_reference<decltype(ref.pTTypeStruct)>::type>::value,"no way");
    this->pTTypeStruct=ref.pTTypeStruct;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeSys)>::type,std::remove_reference<decltype(ref.pTTypeSys)>::type>::value,"no way");
    this->pTTypeSys=ref.pTTypeSys;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareType)>::type,std::remove_reference<decltype(ref.pDeclareType)>::type>::value,"no way");
    this->pDeclareType=ref.pDeclareType;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareTypeStruct)>::type,std::remove_reference<decltype(ref.pDeclareTypeStruct)>::type>::value,"no way");
    this->pDeclareTypeStruct=ref.pDeclareTypeStruct;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareTypeSys)>::type,std::remove_reference<decltype(ref.pDeclareTypeSys)>::type>::value,"no way");
    this->pDeclareTypeSys=ref.pDeclareTypeSys;
    //[Line](<=)
  }
  void operator=(const SelfClass&ref)
  {
    oper_set(ref);
  }
//<<<<<+=====TBigMetaTypePack
};
class EnvAdapter
{
public:
  template<class TYPE>
  static TServerPtr<IEsoteric>*get(TSelfPtr<TYPE>&ref)
  {
    return (TServerPtr<IEsoteric>*)&ref.P;
  }
public:
  class TMetaTypePack
  {
  public:
    //=====+>>>>>TMetaTypePack
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef TMetaTypePack SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    TType*pTType;
    TType*pTTypeStruct;
    //[Line](<=)
    //==Declaration DoReset==//
    void DoReset()
    {
      //[Line](=>)
      this->pTType=nullptr;
      this->pTTypeStruct=nullptr;
      //[Line](<=)
    }
    //==Declaration Constructors==//
    TMetaTypePack(const SelfClass&ref)
    {
      DoReset();
      oper_set(ref);
    }
    TMetaTypePack()
    {
      DoReset();
    }
    TMetaTypePack(IEnvRTTI&Env)
    {
      DoReset();
      prepare(Env);
    }
    template<class TYPE>TMetaTypePack(const TYPE&ref)
    {
      DoReset();
      oper_set(ref);
    }
    //==Declaration prepare==//
    template<class QAP_RTTI>
    void prepare(QAP_RTTI&Env)
    {
      this->pTType=Sys$$<TType>::GetRTTI((IEnvRTTI&)Env);
      this->pTTypeStruct=Sys$$<TTypeStruct>::GetRTTI((IEnvRTTI&)Env); ;
    }
    //==Declaration oper_set==//
    void oper_set(const SelfClass&ref)
    {
      //[Line](=>)
      this->pTType=ref.pTType;
      this->pTTypeStruct=ref.pTTypeStruct;
      //[Line](<=)
    }
    template<class TYPE>
    void oper_set(const TYPE&ref)
    {
      //[Line](=>)
      static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");
      this->pTType=ref.pTType;
      static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeStruct)>::type,std::remove_reference<decltype(ref.pTTypeStruct)>::type>::value,"no way");
      this->pTTypeStruct=ref.pTTypeStruct;
      //[Line](<=)
    }
    void operator=(const SelfClass&ref)
    {
      oper_set(ref);
    }
    //<<<<<+=====TMetaTypePack
  };
public:
  TType*FindTypeByFactory(IEnvRTTI&Env,IFactory*pFactory)
  {
    auto&arr=Env.GetArr();
    for (int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if (pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
  TType*FindTypeByFactoryFast(IEnvRTTI&Env,TServerPtrSpace&Space,IFactory*pFactory)
  {
    auto&ptr_lnk=Space[pFactory->Self].ptr_lnk;
    if (ptr_lnk.IsNull())
    {
      ptr_lnk=Space[FindTypeByFactory(Env,pFactory)->Self].ptr;
    }
    if (ptr_lnk.IsValid())return (TType*)ptr_lnk.get();
    return nullptr;
  }
public:
  static void GoV3(TServerPtrSpace&Space,IEnvRTTI&Env)
  {
    GoV2(Space,Env,TMetaTypePack(Env));
  }
  static void GoV2(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    Space.reserve(2048);
    {
      auto*it=&Env;
      auto&ex=Space.AddExt(get(it->Self),nullptr,"[Env]");
      ex.system=true;
      ex.hidden=true;
    }
    {
      IEnvRTTI&env=Env;
      auto*it=env.GetAlloc();
      auto&ex=Space.AddExt(get(it->Self),nullptr,"[Env.GetAlloc()]");
      ex.system=true;
      ex.hidden=true;
    }
    GoSys(Space);
    GoEnv(Space,Env,TypePack);
  }
  static void GoSys(TServerPtrSpace&Space)
  {
    GoFactory(Space);
    GoCppIO(Space);
    GoBinIO(Space);
    GoVectorAPI(Space);
  }
  static void GoFactory(TServerPtrSpace&Space)
  {
    auto&Arr=TFactory<void>::GetFactorys();
    for (int i=0;i<Arr.size();i++)
    {
      IFactory*it=Arr[i].get();
      string name="TFactory<"+it->GetElementTypeFullName()+">::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoCppIO(TServerPtrSpace&Space)
  {
    auto&Arr=THeadCppIO<void>::GetArr();
    for (int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="THeadCppIO<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoBinIO(TServerPtrSpace&Space)
  {
    auto&Arr=THeadBinIO<void>::GetArr();
    for (int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="THeadBinIO<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoVectorAPI(TServerPtrSpace&Space)
  {
    auto&Arr=TVectorAPI<void>::GetArr();
    for (int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="TVectorAPI<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  //template<class QAP_RTTI>
  //static void Go(TServerPtrSpace&Space,QAP_RTTI&Env)
  //{
  //  QapDebugMsg("deprecated");
  //  QapDebugMsg("see GoV2");
  //  Space.reserve(2048);
  //  {
  //    QAP_RTTI*it=&Env;
  //    auto&ex=Space.AddExt(get(it->Self),Sys$$<QAP_RTTI>::GetRTTI(Env),"[Env]");
  //    ex.system=true;
  //    ex.hidden=true;
  //  }
  //  {
  //    IEnvRTTI&env=Env;
  //    auto*it=env.GetAlloc();
  //    auto&ex=Space.AddExt(get(it->Self),Sys$$<IAllocator>::GetRTTI(Env),"[Env.GetAlloc()]");
  //    ex.system=true;
  //    ex.hidden=true;
  //  }
  //  {
  //    auto&Arr=TFactory<void>::GetFactorys();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      IFactory*it=Arr[i].get();
  //      string name="TFactory<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  if(true)
  //  {
  //    auto&Arr=THeadCppIO<void>::GetArr();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      auto*it=Arr[i].get();
  //      string name="THeadCppIO<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  if(true)
  //  {
  //    auto&Arr=THeadBinIO<void>::GetArr();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      auto*it=Arr[i].get();
  //      string name="THeadBinIO<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  if(true)
  //  {
  //    auto&Arr=TVectorAPI<void>::GetArr();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      auto*it=Arr[i].get();
  //      string name="TVectorAPI<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  GoEnv(Space,Env,TMetaTypePack((IEnvRTTI&)Env));
  //};
  static void GoEnv(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    auto*pTType=TypePack.pTType;
    auto*pTTypeStruct=TypePack.pTTypeStruct;
    auto&Arr=Env.GetArr();
    for (int i=0;i<Arr.size();i++)
    {
      TType*it=Arr[i].Type.get();
      string name="Sys$$<"+it->GetFullName()+">::GetRTTI()";
      TType*type=Arr[i].Type.Product.pType.get();
      QapAssert(IsBasedOn(type,pTType));
      bool flag1=IsBasedOn(type,pTTypeStruct);
      bool flag2=IsBasedOn(it,pTType);
      bool system=!flag1||flag2;
      Space.AddExt(get(it->Self),type,name).system=system;
    }
  }
  static void FixEnvType(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    auto*pTType=TypePack.pTType;
    auto*pTTypeStruct=TypePack.pTTypeStruct;
    auto&Arr=Env.GetArr();
    for (int i=0;i<Arr.size();i++)
    {
      TType*it=Arr[i].Type.get();
      TType*type=Arr[i].Type.Product.pType.get();
      QapAssert(IsBasedOn(type,pTType));
      bool flag1=IsBasedOn(type,pTTypeStruct);
      bool flag2=IsBasedOn(it,pTType);
      bool system=!flag1||flag2;
      auto&item=Space[it->Self];
      item.system=false;
    }
  }
  static bool IsFactoryEqual(TType*p,TType*b)
  {
    return p->Factory.get()==b->Factory.get();
  }
  static bool IsBasedOn(TType*p,TType*base)
  {
    if (IsFactoryEqual(p,base))return true;
    TType*subtype=p->GetSubType();
    return subtype?IsBasedOn(subtype,base):false;
  }
};
struct IQapStream
{
  virtual bool Load()
  {
    return false;
  }
  virtual bool Save()
  {
    return false;
  }
  virtual QapIO&GetContent()=0;
};
struct TQapFileStream:public IQapStream
{
  TDataIO IO;
  string fn;
  bool readonly;
  TQapFileStream(const string&fn,bool readonly=true):fn(fn),readonly(readonly) {}
  bool Load()
  {
    return IO.IO.LoadFile(fn);
  }
  bool Save()
  {
    if (readonly)
    {
      QapDebugMsg("yes?");
      return false;
    }
    return IO.IO.SaveFile(fn);
  }
  QapIO&GetContent()
  {
    return IO;
  };
};
struct TQapMemoryStream:public IQapStream
{
  TDataIO IO;
  TQapMemoryStream() {}
  bool Load()
  {
    return true;
  }
  bool Save()
  {
    return true;
  }
  QapIO&GetContent()
  {
    return IO;
  };
};
struct TDataIOStream:public IQapStream
{
  TDataIO&IO;
  TDataIOStream(TDataIO&IO):IO(IO) {}
  bool Load()
  {
    return true;
  }
  bool Save()
  {
    return true;
  }
  QapIO&GetContent()
  {
    return IO;
  };
};
struct IQapRawObject
{
  virtual TRawPtr&Get(IEnvRTTI&Env)=0;
};
struct TQapRawObject:public IQapRawObject
{
  TRawPtr raw_ptr;
  TQapRawObject(const TRawPtr&ptr)
  {
    raw_ptr=ptr;
  }
  TQapRawObject(TType*pType,void*pValue)
  {
    raw_ptr.pType=pType;
    raw_ptr.pValue=pValue;
  }
  TRawPtr&Get(IEnvRTTI&Env)
  {
    return raw_ptr;
  }
};
template<class TYPE>
struct TQapRawUberObject:public IQapRawObject
{
  TRawPtr raw_ptr;
  TQapRawUberObject(TYPE&value)
  {
    raw_ptr.pType=nullptr;
    raw_ptr.pValue=&value;
  }
  TRawPtr&Get(IEnvRTTI&Env)
  {
    TType*pType=Sys$$<TYPE>::GetRTTI(Env);
    raw_ptr.pType=pType;
    return raw_ptr;
  }
};
template<class TYPE>
TQapRawUberObject<TYPE> QapRawUberObject(TYPE&value)
{
  TQapRawUberObject<TYPE> tmp(value);
  return std::move(tmp);
}
//bool QapUberLoad(IEnvRTTI&Env,IQapRawObject&&Object,IQapStream&&Stream)
//{
//  if(!Stream.Load())return false;
//  auto&Content=Stream.GetContent();
//  auto&raw_ptr=Object.GetObject(Env);
//  auto&pType=raw_ptr.pType;
//  auto&pValue=raw_ptr.pValue;
//  //begin
//
//  //end
//  return true;
//}
//
//bool QapUberSave(IEnvRTTI&Env,IQapRawObject&&Object,IQapStream&&Stream)
//{
//  auto&Content=Stream.GetContent();
//  auto&raw_ptr=Object.GetObject(Env);
//  auto&pType=raw_ptr.pType;
//  auto&pValue=raw_ptr.pValue;
//  //begin
//
//  //end
//  return !Content.IO.mem.empty()&&Stream.Save();
//}
//===>>===IDeclareVisitorRTTI
class DeclareType;
class DeclareTypeSys;
class DeclareTypeSelfPtr;
class DeclareTypeAutoPtr;
class DeclareTypeWeakPtr;
class DeclareTypeHardPtr;
class DeclareTypeVoidPtr;
class DeclareTypeFieldPtr;
class DeclareTypeVector;
class DeclareTypeArray;
class DeclareTypeStruct;
class IDeclareVisitorRTTI
{
public:
  //#define ADD(TYPE)virtual void Do(TYPE*p)=0;
  //  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  //#undef ADD
  virtual void Do(DeclareTypeSys*p)=0;
  virtual void Do(DeclareTypeSelfPtr*p)=0;
  virtual void Do(DeclareTypeAutoPtr*p)=0;
  virtual void Do(DeclareTypeWeakPtr*p)=0;
  virtual void Do(DeclareTypeHardPtr*p)=0;
  virtual void Do(DeclareTypeVoidPtr*p)=0;
  virtual void Do(DeclareTypeFieldPtr*p)=0;
  virtual void Do(DeclareTypeVector*p)=0;
  virtual void Do(DeclareTypeArray*p)=0;
  virtual void Do(DeclareTypeStruct*p)=0;
public:
  template<class TYPE,class Visitor>
  struct Is:public Visitor
  {
    TYPE*ptr;
    Is():ptr(nullptr) {}
public:
    template<class U>static TYPE*get(U*p)
    {
      return nullptr;
    }
    template<>static TYPE*get<TYPE>(TYPE*p)
    {
      return p;
    }
public:
    void Do(DeclareTypeSys*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeSelfPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeAutoPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeWeakPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeHardPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeVoidPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeFieldPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeVector*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeArray*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeStruct*p)
    {
      ptr=get(p);
    }
  };
  template<class TYPE>
  static TYPE*UberCast(DeclareType*p)
  {
    if (!p)return nullptr;
    Is<TYPE,IDeclareVisitorRTTI> IS;
    p->Use(IS);
    return IS.ptr;
  }
};
//===<<===IDeclareVisitorRTTI
template<class TYPE>
struct QapDeclareDetail
{
  //typedef TYPE Impl;
  static string GetFullName(const DeclareType*ptr)
  {
    //typedef DeclareDetail Impl;
    DeclareDetail::GetFullName GFN;
    DeclareType*p=(DeclareType*)ptr;
    p->Use(GFN);
    return GFN.fullname;
  }
  static DeclareType*GetSubType(const DeclareType*ptr)
  {
    auto*p=DeclareTypeStruct::UberCast((DeclareType*)ptr);
    return p?p->SubType.get():nullptr;
  }
  static bool IsBasedOn(const DeclareType*ptr,const DeclareType*A)
  {
    if (ptr==A)return true;
    auto*subtype=ptr->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};
//struct IDeclareVisitorRTTI{};
class DeclareType
{
public:
//=====+>>>>>DeclareType
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareType SelfClass;
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
  DeclareType(const DeclareType&)=delete;
  DeclareType()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareType(DeclareType&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareType&&_Right)
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
      static const string Name="DeclareType";
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
      return "DeclareType";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareType
public:
  static void SysHasSelf();
public:
  virtual void Use(IDeclareVisitorRTTI&)
  {
    QapDebugMsg("no way.");
  }
  string GetFullName()const
  {
    return QapDeclareDetail<void>::GetFullName(this);
  }
  DeclareType*GetSubType()const
  {
    return QapDeclareDetail<void>::GetSubType(this);
  }
  bool IsBasedOn(const DeclareType*A)const
  {
    return QapDeclareDetail<void>::IsBasedOn(this,A);
  }
};
class DeclareTypeSys:public DeclareType
{
public:
//=====+>>>>>DeclareTypeSys
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeSys SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  string FullName;
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
    (this->FullName)=("unnamed");
  }
  //==Declaration Constructors==//
public:
  DeclareTypeSys(const DeclareTypeSys&)=delete;
  DeclareTypeSys()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeSys(DeclareTypeSys&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeSys&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->FullName=std::move(_Right.FullName);
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
      static const string Name="DeclareTypeSys";
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
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"FullName",int(&(((SelfClass*)nullptr)->*(&SelfClass::FullName))),"SET","\"unnamed\"");
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
      return "DeclareTypeSys";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeSys
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeSelfPtr:public DeclareType
{
public:
//=====+>>>>>DeclareTypeSelfPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeSelfPtr SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<DeclareType> ElementType;
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
  }
  //==Declaration Constructors==//
public:
  DeclareTypeSelfPtr(const DeclareTypeSelfPtr&)=delete;
  DeclareTypeSelfPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeSelfPtr(DeclareTypeSelfPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeSelfPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
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
      static const string Name="DeclareTypeSelfPtr";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
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
      return "DeclareTypeSelfPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeSelfPtr
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeAutoPtr:public DeclareType
{
//=====+>>>>>DeclareTypeAutoPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeAutoPtr SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<DeclareType> ElementType;
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
  }
  //==Declaration Constructors==//
public:
  DeclareTypeAutoPtr(const DeclareTypeAutoPtr&)=delete;
  DeclareTypeAutoPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeAutoPtr(DeclareTypeAutoPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeAutoPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
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
      static const string Name="DeclareTypeAutoPtr";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
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
      return "DeclareTypeAutoPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeAutoPtr
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeWeakPtr:public DeclareType
{
public:
//=====+>>>>>DeclareTypeWeakPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeWeakPtr SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<DeclareType> ElementType;
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
  }
  //==Declaration Constructors==//
public:
  DeclareTypeWeakPtr(const DeclareTypeWeakPtr&)=delete;
  DeclareTypeWeakPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeWeakPtr(DeclareTypeWeakPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeWeakPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
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
      static const string Name="DeclareTypeWeakPtr";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
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
      return "DeclareTypeWeakPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeWeakPtr
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeHardPtr:public DeclareType
{
//=====+>>>>>DeclareTypeHardPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeHardPtr SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<DeclareType> ElementType;
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
  }
  //==Declaration Constructors==//
public:
  DeclareTypeHardPtr(const DeclareTypeHardPtr&)=delete;
  DeclareTypeHardPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeHardPtr(DeclareTypeHardPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeHardPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
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
      static const string Name="DeclareTypeHardPtr";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
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
      return "DeclareTypeHardPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeHardPtr
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeFieldPtr:public DeclareType
{
public:
//=====+>>>>>DeclareTypeFieldPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeFieldPtr SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
  }
  //==Declaration Constructors==//
public:
  DeclareTypeFieldPtr(const DeclareTypeFieldPtr&)=delete;
  DeclareTypeFieldPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeFieldPtr(DeclareTypeFieldPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeFieldPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
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
      static const string Name="DeclareTypeFieldPtr";
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
      return "DeclareTypeFieldPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeFieldPtr
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeVoidPtr:public DeclareType
{
public:
//=====+>>>>>DeclareTypeVoidPtr
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeVoidPtr SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
      //[Line](=>)
      detail::TryDoReset<SelfClass>(this);
      //[Line](<=)
    }
  }
  //==Declaration Constructors==//
public:
  DeclareTypeVoidPtr(const DeclareTypeVoidPtr&)=delete;
  DeclareTypeVoidPtr()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeVoidPtr(DeclareTypeVoidPtr&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeVoidPtr&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
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
      static const string Name="DeclareTypeVoidPtr";
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
      return "DeclareTypeVoidPtr";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeVoidPtr
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeVector:public DeclareType
{
public:
//=====+>>>>>DeclareTypeVector
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeVector SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<DeclareType> ElementType;
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
  }
  //==Declaration Constructors==//
public:
  DeclareTypeVector(const DeclareTypeVector&)=delete;
  DeclareTypeVector()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeVector(DeclareTypeVector&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeVector&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
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
      static const string Name="DeclareTypeVector";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
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
      return "DeclareTypeVector";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeVector
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeArray:public DeclareType
{
public:
//=====+>>>>>DeclareTypeArray
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeArray SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<DeclareType> ElementType;
  int Size;
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
    (this->Size)=(0);
  }
  //==Declaration Constructors==//
public:
  DeclareTypeArray(const DeclareTypeArray&)=delete;
  DeclareTypeArray()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeArray(DeclareTypeArray&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeArray&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->ElementType=std::move(_Right.ElementType);
    this->Size=std::move(_Right.Size);
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
      static const string Name="DeclareTypeArray";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");
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
      return "DeclareTypeArray";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeArray
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareMember
{
public:
//=====+>>>>>DeclareMember
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareMember SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  string Name;
  TWeakPtr<DeclareType> Type;
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
    detail::FieldTryDoReset(this->Type);
    detail::FieldTryDoReset(this->Mode);
    detail::FieldTryDoReset(this->Value);
  }
  //==Declaration Constructors==//
public:
  DeclareMember(const DeclareMember&)=delete;
  DeclareMember()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareMember(DeclareMember&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareMember&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->Name=std::move(_Right.Name);
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
      static const string Name="DeclareMember";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
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
      return "DeclareMember";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareMember
public:
  bool IsEqual(SelfClass&other)
  {
    QapDebugMsg("no way.");
  }
};
class DeclareTypeStruct:public DeclareType
{
public:
//=====+>>>>>DeclareTypeStruct
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef DeclareTypeStruct SelfClass;
public:
  typedef DeclareType ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  string Name;
  TWeakPtr<DeclareType> SubType;
  TWeakPtr<DeclareType> OwnType;
  vector<DeclareMember> Members;
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
    (this->Name)=("unnamed");
    detail::FieldTryDoReset(this->SubType);
    detail::FieldTryDoReset(this->OwnType);
    detail::FieldTryDoReset(this->Members);
  }
  //==Declaration Constructors==//
public:
  DeclareTypeStruct(const DeclareTypeStruct&)=delete;
  DeclareTypeStruct()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  DeclareTypeStruct(DeclareTypeStruct&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(DeclareTypeStruct&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      DeclareType::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->Name=std::move(_Right.Name);
    this->SubType=std::move(_Right.SubType);
    this->OwnType=std::move(_Right.OwnType);
    this->Members=std::move(_Right.Members);
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
      static const string Name="DeclareTypeStruct";
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
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"OwnType",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnType))),"DEF","$");
      Info->AddMemberDEF(Sys$$<vector<DeclareMember>>::GetRTTI(RTTI),"Members",int(&(((SelfClass*)nullptr)->*(&SelfClass::Members))),"DEF","$");
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
      return "DeclareTypeStruct";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====DeclareTypeStruct
public:
  void Use(IDeclareVisitorRTTI&A)
  {
    A.Do(this);
  } static SelfClass*UberCast(DeclareType*ptr)
  {
    return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
  };
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  bool TestField(const DeclareMember&it,int depth=0)
  {
    if (SubType)
    {
      auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
      bool result=pSubType->TestField(it,depth+1);
      if (!result)return result;
    }
    auto&arr=Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int cmp_id=0;
      static string idToStr[]={"Name",};
      const int cmp_n=lenof(idToStr)-(depth?1:0);
      //[Line](=>)
      do
      {
        if (cmp_id<cmp_n)
        {
          if (it.Name==ex.Name)break;
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
        QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
        return depth;
      }
    }
    return true;
  }
  DeclareMember*GetNearSelf()
  {
    auto&arr=Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (ex.Name!="Self")continue;
      auto*pFieldType=DeclareTypeSelfPtr::UberCast(ex.Type.get());
      QapAssert(pFieldType);
      QapAssert(pFieldType->ElementType.get()==this);
      return &ex;
    }
    auto*pSubType=DeclareTypeStruct::UberCast(GetSubType());
    return pSubType?pSubType->GetNearSelf():nullptr;
  }
  void AddField(DeclareMember&&field)
  {
    QapAssert(TestField(field));
    if (field.Name=="Self")
    {
      if (true)do
        {
          auto*type=DeclareTypeSelfPtr::UberCast(field.Type.get());
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
          auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
          string fn=GetFullName();
          string subtype=pSubType->GetFullName();
          if ("QapWinProgram"==subtype)if ("eWinProgram"==fn)break;
          if ("QapWinProgram"==subtype)if ("QapProgramD3D9"==fn)break;
          QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
        }
        while (false);
    }
    Members.push_back(std::move(field));
  }
  void AddMember(DeclareType*MemType,const string&MemName,const string&Mode,const string&Value)
  {
    DeclareMember tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
};
class DeclareDetail
{
public:
  class StructTools
  {
  public:
    struct field_cmp_result_item
    {
      string fna;
      string fnb;
      int ida;
      int idb;
      void SetToDef()
      {
        ida=-1;
        idb=-1;
      }
    };
    static vector<field_cmp_result_item> CompareFieldsLists(const vector<DeclareMember>&A,const vector<DeclareMember>&B)
    {
      field_cmp_result_item tmp;
      tmp.SetToDef();
      vector<field_cmp_result_item> result;
      result.reserve(A.size()+B.size());
      vector<bool> passed;
      passed.resize(B.size(),false);
      for (int i=0;i<A.size();i++)
      {
        result.push_back(tmp);
        auto&ex=result.back();
        auto&ax=A[i];
        ex.ida=i;
        ex.fna=ax.Name;
        for (int j=0;j<B.size();j++)
        {
          if (passed[j])continue;
          auto&bx=B[j];
          if (ax.Name!=bx.Name)continue;
          ex.fnb=bx.Name;
          ex.idb=j;
          passed[j]=true;
        }
      }
      for (int j=0;j<B.size();j++)
      {
        if (passed[j])continue;
        result.push_back(tmp);
        auto&ex=result.back();
        auto&bx=B[j];
        ex.fnb=bx.Name;
        ex.idb=j;
        passed[j]=true;
      }
      return std::move(result);
    }
    static void Filter_RemoveEqual(vector<field_cmp_result_item>&arr)
    {
      vector<field_cmp_result_item> tmp;
      std::swap(tmp,arr);
      for (int i=0;i<tmp.size();i++)
      {
        auto&ex=tmp[i];
        if ((ex.ida<0)!=(ex.idb<0))
        {
          arr.push_back(std::move(ex));
        }
      }
    }
    static string CompareFieldsLists_ToString(const vector<field_cmp_result_item>&arr)
    {
      string out;
      int n_a=[&]()->size_t {size_t n=0;
          for (size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fna.size(),n);
          return n;
                            }();
      int n_b=[&]()->size_t {size_t n=0;
          for (size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fnb.size(),n);
          return n;
                            }();
      auto&f=[](const string&s,size_t n)->string {string tmp=s;
          for (size_t i=s.size();i<n;i++)tmp+=" ";
          return tmp;
                                                 };
    for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        out+=f(ex.fna,n_a)+" = "+f(ex.fnb,n_b)+"\n";
      }
      return out;
    }
  };
public:
  class GetFullName:public IDeclareVisitorRTTI
  {
  public:
    string fullname;
  public:
    void Do(DeclareTypeSys*p)
    {
      fullname=p->FullName;
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      string template_name="TSelfPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      string template_name="TAutoPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      string template_name="TWeakPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeHardPtr*p)
    {
      string template_name="THardPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      string name="TVoidPtr";
      fullname=name;
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      string name="TFieldPtr";
      fullname=name;
    }
    void Do(DeclareTypeVector*p)
    {
      string template_name="vector";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeArray*p)
    {
      string template_name="array";
      fullname=template_name+"<"+p->ElementType->GetFullName()+","+IToS(p->Size)+">";
    }
    void Do(DeclareTypeStruct*p)
    {
      string template_name="TSelfPtr";
      auto*pOwnType=p->OwnType.get();
      fullname=pOwnType?pOwnType->GetFullName()+"::"+p->Name:p->Name;
    }
  };
  class GetSubType:public IDeclareVisitorRTTI
  {
  public:
    DeclareType*pValue;
    GetSubType():pValue(nullptr) {}
  public:
    void Do(DeclareTypeSys*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeHardPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeVector*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeStruct*p)
    {
      pValue=p->SubType.get();
    }
  };
  template<class TSPACE>
  class IsEqualTo:public IDeclareVisitorRTTI
  {
  public:
    TSPACE&Space;
    bool Result;
    DeclareType*pValue;
    bool Mute;
    IsEqualTo(TSPACE&Space):Space(Space),Result(false),pValue(nullptr),Mute(false) {}
  public:
    struct EqualDetail
    {
      static bool Equal(TSPACE&Space,...)
      {
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeSys*pA,DeclareTypeSys*pB,bool Mute)
      {
        return pA->FullName==pB->FullName;
      }
      static bool Equal(TSPACE&Space,DeclareTypeSelfPtr*pA,DeclareTypeSelfPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeAutoPtr*pA,DeclareTypeAutoPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeWeakPtr*pA,DeclareTypeWeakPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeHardPtr*pA,DeclareTypeHardPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVoidPtr*pA,DeclareTypeVoidPtr*pB,bool Mute)
      {
        //QapDebugMsg("no way");
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeFieldPtr*pA,DeclareTypeFieldPtr*pB,bool Mute)
      {
        //QapDebugMsg("no way");
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVector*pA,DeclareTypeVector*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeArray*pA,DeclareTypeArray*pB,bool Mute)
      {
        if (pA->Size!=pB->Size)return false;
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeStruct*pA,DeclareTypeStruct*pB,bool Mute)
      {
        string fna=pA->GetFullName();
        string fnb=pB->GetFullName();
        bool flag=fna==fnb;
        if (!flag)return false;
        auto&A=pA->Members;
        auto&B=pB->Members;
        if (A.size()!=B.size())
        {
          string msg="type : \""+fna+"\"\n";
          msg+="A.size = "+IToS(A.size())+"\n";
          msg+="B.size = "+IToS(B.size())+"\n";
          if (!Mute)QapDebugMsg(msg);
          auto detail_result=StructTools::CompareFieldsLists(A,B);
          StructTools::Filter_RemoveEqual(detail_result);
          auto str_detail_result=StructTools::CompareFieldsLists_ToString(detail_result);
          if (!Mute)QapDebugMsg(msg+"\n"+str_detail_result);
          flag=false;
        }
        for (int i=0;i<std::min(A.size(),B.size());i++)
        {
          auto&a=A[i];
          auto&b=B[i];
          bool f[]=
          {
            a.Name==b.Name,
            a.Mode==b.Mode,
            a.Value==b.Value,
            //a.Type==b.Type
          };
          bool flag=true;
          for (int j=0;j<lenof(f);j++)
          {
            flag=flag&&f[j];
          }
          if (flag)
          {
            IsEqualTo<TSPACE> other(Space);
            other.Mute=Mute;
            other.pValue=a.Type.get();
            b.Type.get()->Use(other);
            flag=flag&&other.Result;
          }
          if (!flag)
          {
            if (!Mute)QapDebugMsg("type : \""+fna+"\"");
            return false;
          }
        }
        return flag;
      }
    };
    template<class TYPE>
    class IsEqual:public IDeclareVisitorRTTI
    {
    public:
      TSPACE&Space;
      TYPE*pInput;
      bool Result;
      bool Mute;
      IsEqual(TSPACE&Space):Space(Space),Result(false),pInput(nullptr),Mute(false) {}
    public:
      void Do(DeclareTypeSys*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeSelfPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeAutoPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeWeakPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeHardPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVoidPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeFieldPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVector*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeArray*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeStruct*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
    };
    template<class TYPE>
    static bool IsEqualFunc(TSPACE&Space,TYPE*pInput,DeclareType*pValue,bool Mute)
    {
      static_assert(std::is_same<TSPACE,TServerPtrSpace>::value,"renamed?");
      TServerPtrSpace&space=Space;
      if (pInput==pValue)return true;
      bool fA=space.IsAllowed(pInput->Self.P.SaveID);
      bool fB=space.IsAllowed(pValue->Self.P.SaveID);
      if (!fA||!fB)
      {
        QapDebugMsg("no way");
        return false;
      }
      auto&eA=space[pInput->Self];
      auto&eB=space[pValue->Self];
      EnvItem&A=eA;
      EnvItem&B=eB;
      bool f[]=
      {
        A.ptr_lnk.IsValid(),
        B.ptr_lnk.IsValid(),
        A.ptr.get()==(void*)pInput,
        B.ptr.get()==(void*)pValue,
      };
      QapAssert(f[2]&&f[3]);
      if (f[0]&&f[1])
      {
        bool g0=A.ptr_lnk.get()==B.ptr.get();
        bool g1=B.ptr_lnk.get()==A.ptr.get();
        QapAssert(g0==g1);
        return g0&&g1;
      }
      if (!f[0]&&!f[1])
      {
        //так... тут надо поставить замочек, чтобы там внутри pValue->Use(Is); не вызвать этоже с теме же параметрами.
        QapAssert(!A.system&&!B.system);
        A.system=true;
        B.system=true;
        //так. это не даст пройтись дважды по одному маршруту.
        //но мы не можем блокировать оба объекта для любых вызовов.
        //мы можем заблокировать только для этого же вызова.
        //готово.
        IsEqual<TYPE> Is(space);
        Is.pInput=pInput;
        Is.Mute=Mute;
        pValue->Use(Is);
        A.system=false;
        B.system=false;
        if (Is.Result||Mute)
        {
          A.ptr_lnk=B.ptr;
          B.ptr_lnk=A.ptr;
        }
        return Is.Result;
      }
      return false;
    }
    static bool IsEqualFuncEx(TSPACE&Space,DeclareType*pInput,DeclareType*pValue)
    {
      IsEqualTo<TSPACE> next(Space);
      next.pValue=pValue;
      pInput->Use(next);
      return next.Result;
    }
    void Do(DeclareTypeSys*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeHardPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVector*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeArray*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeStruct*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
  };
};
//#include "DeclareEnvRTTI.inl"
//#include "SmartPointerGraber.inl"
class TSmartPtrVisitor:public IVisitorRTTI
{
public:
  class ICallBack
  {
  public:
    virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A)=0;
  };
public:
  ICallBack&CB;
  void*pValue;
  typedef TSmartPtrVisitor SelfClass;
  TSmartPtrVisitor(ICallBack&CB,void*pValue):CB(CB),pValue(pValue) {}
  TSmartPtrVisitor(TSmartPtrVisitor&owner,void*pValue):CB(owner.CB),pValue(pValue) {}
public:
  void Do(TTypeStruct*p)
  {
    if (p->SubType)
    {
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
    }
    auto&arr=p->Members;
    //static bool debug=true;
    //if(debug)
    //{
    //  string fn=p->GetFullName();
    //  if(fn=="TTypeSys")
    //  {
    //    auto*pMetaType=(TTypeSys*)pValue;
    //    string mt_fn=pMetaType->GetFullName();
    //    if(mt_fn=="string")
    //    {
    //      int gg=1;
    //    }
    //  }
    //}
    static bool debug_flag=false;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
      if (debug_flag)
      {
        string fn=p->GetFullName();
        if (fn=="TType")if (ex.Name=="Factory")do
            {
              TType*pval=(TType*)(void*)pValue;
              string val_fn=pval->GetFullName();
              THardPtr<TType>&value=*(THardPtr<TType>*)(void*)next.pValue;
              auto*ptr=value.P.ptr;
              if (!ptr)break;
              int sid=ptr->SaveID;
              sid=sid+1-1;
            }
            while (false);
      }
      ex.Type->Use(next);
      if (debug_flag)
      {
        string fn=ex.Type->GetFullName();
        int ksjdlasd=0;
      }
    }
  }
  void Do(TTypeSys*p)
  {
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    for (int i=0;i<Count;i++)
    {
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
    for (int i=0;i<Count;i++)
    {
      void*ptr=&((uchar*)pValue)[elemSize*i];
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  virtual void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeAutoPtr*p)
  {
    if (!p->ElementType)
    {
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      SelfClass next(*this,&type);
      p->mType.Type->Use(next);
    }
    auto*ptr=value.get();
    if (ptr&&type)
    {
      SelfClass next(*this,ptr);
      type->Use(next);
    }
  }
  virtual void Do(TTypeWeakPtr*p)
  {
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeHardPtr*p)
  {
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    CB.Visit(value.ptr.P);
  }
  virtual void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    TType*pmObjectType=p->mObject.Type.get();
    {
      SelfClass next(*this,&value.object);
      pmObjectType->Use(next);
    }
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    TType*pmIndexType=p->mIndex.Type.get();
    {
      SelfClass next(*this,&value.offset);
      pmIndexType->Use(next);
    }
  }
  virtual void Do(TTypeFactory*p)
  {
    IFactory&value=*(IFactory*)pValue;
    TSelfPtr<IEsoteric>&Self=*(TSelfPtr<IEsoteric>*)(void*)&value.Self;
    TType*SmartType=p->SmartType.get();
    CB.Visit(Self.P,SmartType);
  }
public:
};
/*
  Увеличивает значение count в ячейке ассоциированной с серверным указателем
  на который ссылается клиенский указатель.
*/
class TClientPtrCounter:public TSmartPtrVisitor::ICallBack
{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("see TClientPtrUserCallBackCounter");
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  void Visit(TClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
public:
  template<template<class> class SmartPtr,class TYPE>
  inline static SmartPtr<IEsoteric>&get(SmartPtr<TYPE>&input)
  {
    static_assert(
      std::is_same<SmartPtr,TClientPtr>::value||
      std::is_same<SmartPtr,THardClientPtr>::value,"error"
    );
    return (SmartPtr<IEsoteric>&)input;
  }
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if (!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if (item.passed)return;
    if (item.count)return;
    if (true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType);
      if (trigger)//если item.ptr описатель обычный.
      {
        //ищем заместитель.
        auto*pValue=(TType*)item.ptr.get();
        auto&ex=Space[pValue->Self];
        QapAssert(ex.ptr_lnk.IsValid());
        bool good=ex.ptr_lnk.type->IsBasedOn(pDeclareType);
        QapAssert(good);
        //переходим к соответствующему наследнику DeclareType'а.
        bool f[]=
        {
          pValue->IsBasedOn(pTType),
          pValue->IsBasedOn(pDeclareType)
        };
        auto*pdValue=(DeclareType*)ex.ptr_lnk.get();
        auto&d=Space[pdValue->Self];
        d.count++;
        d.passed=f[0]||f[1];
        item.passed=true;//пройден.
        return;
      }
      QapAssert(!item.hidden);
      if (safe)
      {
        bool good=pType->IsBasedOn(elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if (!A)return;
    DoVisitSaveID(A.ptr->SaveID,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if (!A)return;
    DoVisitSaveID(A.ptr->SaveID,false,nullptr);
  }
};
class TServerPtrGraber:public TSmartPtrVisitor::ICallBack
{
public:
  bool automark;
  int SkipCount;
  int AddCount;
  TServerPtrSpace&Space;
  TServerPtrGraber(TServerPtrSpace&Space,bool automark):Space(Space),automark(automark)
  {
    AddCount=0;
    SkipCount=0;
  }
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
  {
    QapDebugMsg
    (
      "[2014.05.14 12:09]\n"
      "This class can not determine the actual type of the object and is no longer using.\n"
      "Look at 'TServerPtrGraberWithRealType'"
    );
    if (Space.CheckServSaveID(&Serv))
    {
      QapDebugMsg("the way used? ORL?");
      SkipCount++;
      auto&ex=Space[Serv.SaveID];
      if (automark)
      {
        ex.count++;
        ex.passed=true;
      }
      return;
    }
    auto&ex=Space.UnsafeAdd(&Serv,elemType);
    //ex.system=false; system=bool(ex.ptr_adv.ptr);
    AddCount++;
    if (automark)
    {
      ex.count++;
      ex.passed=true;
    }
  }
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType) {}
  virtual void Visit(TClientPtr<IEsoteric>&A) {}
  virtual void Visit(THardClientPtr<IEsoteric>&A) {}
};
class TServerPtrCounter:public TSmartPtrVisitor::ICallBack
{
public:
  int&count;
  TServerPtrCounter(int&count):count(count) {}
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
  {
    count++;
  }
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType) {}
  virtual void Visit(TClientPtr<IEsoteric>&A) {}
  virtual void Visit(THardClientPtr<IEsoteric>&A) {}
};
class TClientPtrSolver:public TSmartPtrVisitor::ICallBack
{
public:
  struct TwoMetaType
  {
    TType*pTType;
    TType*pDeclareType;
    TwoMetaType(const TwoMetaType&Ref):pTType(nullptr),pDeclareType(nullptr)
    {
      oper_set(Ref);
    }
    TwoMetaType():pTType(nullptr),pDeclareType(nullptr) {}
    TwoMetaType(IEnvRTTI&Env):pTType(nullptr),pDeclareType(nullptr)
    {
      prepare(Env);
    }
    template<class TYPE>
    TwoMetaType(TYPE&ref):pTType(ref.pTType),pDeclareType(ref.pDeclareType)
    {
      //[Line](=>)
      static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");
      //[Line](<=)
      //[Line](=>)
      static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareType)>::type,std::remove_reference<decltype(ref.pDeclareType)>::type>::value,"no way");
      //[Line](<=)
    }
    void prepare(IEnvRTTI&Env)
    {
      pTType=Sys$$<TType>::GetRTTI(Env);
      pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    }
    void oper_set(const TwoMetaType&Ref)
    {
      this->pTType=Ref.pTType;
      this->pDeclareType=Ref.pDeclareType;
    }
    void operator=(const TwoMetaType&Ref)
    {
      oper_set(Ref);
    }
  };
public:
  typedef TServerPtrSpace TSpace;
  TSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  //TClientPtrSolver(TSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr){}
  TClientPtrSolver(TSpace&Space,const TwoMetaType&tmt):Space(Space),pTType(tmt.pTType),pDeclareType(tmt.pDeclareType) {}
public:
  //void used_tmt(const TwoMetaType&tmt)
  //{
  //  this->pTType=tmt.pTType;
  //  this->pDeclareType=tmt.pDeclareType;
  //}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  void Visit(TClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if (!id)return nullptr;
    if (id<0||id>=Space.size())
    {
      QapDebugMsg("Error!\nWrong id:\n"+IToS(id));
      return nullptr;
    }
    auto&item=Space[id];
    if (item.ptr.type)
    {
      if (!safe)
      {
        //тут может быть проблема. Кто-то решит не безопасно решить указатель и получит не тот что хотел.
        //т.к сейчас у нас одному id соответствуют 2 совершенно разных объекта.
        //надо исправить эту ошибку проектирования.
        return item.ptr.ptr;
      }
      QapAssert(elemType);
      bool flag=elemType->IsBasedOn(pTType);
      if (!flag)
      {
        int gg=1;
      }
      if (flag)
      {
        bool f[]=
        {
          item.ptr.type->IsBasedOn(pTType),
          item.ptr.type->IsBasedOn(pDeclareType)
        };
        bool good=!f[0]&&f[1];
        if (!good)
        {
          auto*pType=item.ptr.type;
          QapAssert(pType->IsBasedOn(elemType));
          return item.ptr.ptr;
        }
        auto*pdType=(DeclareType*)item.ptr.get();
        auto&ex=Space[pdType->Self];
        QapAssert(ex.ptr_lnk.type);
        QapAssert(ex.ptr_lnk.type->IsBasedOn(pTType));
        auto*pType=ex.ptr_lnk.type;
        auto*pValue=(TType*)ex.ptr_lnk.get();
        QapAssert(pType->IsBasedOn(elemType));
        return EnvAdapter::get(pValue->Self);
      }
      auto*pType=item.ptr.type;
      QapAssert(pType->IsBasedOn(elemType));
      return item.ptr.ptr;
    }
    else
    {
      QapDebugMsg("norm");
      return item.ptr.ptr;
    }
    QapDebugMsg("no way.");
    return nullptr;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
};
class TClientPtrKiller:public TSmartPtrVisitor::ICallBack
{
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A)
  {
    MegaVisit(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A)
  {
    MegaVisit(A);
  }
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A)
  {
    if (!A)return;
    A=nullptr;
  }
};
class TDumpPtrSolver:public TSmartPtrVisitor::ICallBack
{
public:
  typedef TServerPtrSpace TSpace;
  TSpace&ST_Space;
  TSpace&LT_Space;
  TDumpPtrSolver(TSpace&ST_Space,TSpace&LT_Space):ST_Space(ST_Space),LT_Space(LT_Space) {}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if (LT_Space[id].system)return ST_Space[id].ptr.ptr;
    return LT_Space[id].ptr.ptr;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
};
class TClientPtrVisitor:public TSmartPtrVisitor::ICallBack
{
public:
  struct ICallBack
  {
    template<class TYPE>
    void DoVisitServerPtr(TServerPtr<TYPE>&Serv,bool safe,TType*elemType)
    {
      DoVisitServerPtr((TServerPtr<IEsoteric>*)&Serv,safe,elemType);
    }
    virtual void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe=false,TType*elemType=nullptr)
    {
      QapDebugMsg("no way.");
    }
  };
public:
  ICallBack&CB;
  TClientPtrVisitor(ICallBack&CB):CB(CB) {}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
  {
    MegaVisit(A,elemType);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A)
  {
    MegaVisitEx(A);
  }
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,false,nullptr);
  }
};
class THardClientSpace
{
public:
  vector<THardClientPtr<IEsoteric>*> Arr;
  void Do()
  {
    for (int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i];
      auto&ex=*it;
      if (ex)ex=nullptr;
    }
  }
};
class THardClientPtrGraber:public TSmartPtrVisitor::ICallBack
{
public:
  typedef THardClientSpace TSpace;
  TSpace&Space;
  THardClientPtrGraber(TSpace&Space):Space(Space) {}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
  {
    Space.Arr.push_back(&A);
  }
  void Visit(TClientPtr<IEsoteric>&A) {}
  void Visit(THardClientPtr<IEsoteric>&A)
  {
    Space.Arr.push_back(&A);
  }
public:
};
inline void ClientMarker(TSmartPtrVisitor::ICallBack&ClientCounter,TType*pType,void*pValue)
{
  TSmartPtrVisitor SPG(ClientCounter,pValue);
  pType->Use(SPG);
}
class TServerPtrGraberWithRealType:public IVisitorRTTI
{
public:
  typedef TServerPtrGraberWithRealType SelfClass;
  typedef TServerPtrSpace TSpace;
public:
  TSpace&Space;
  void*pValue;
  vector<void*> values;
  vector<TType*> types;
  bool automark;
  int AddCount;
  int SkipCount;
  TServerPtrGraberWithRealType(TSpace&Space,TType*pType,void*pValue,bool automark):Space(Space),pValue(pValue),automark(automark)
  {
    AddCount=0;
    SkipCount=0;
    push(pType);
  }
public:
  void push(TType*pType)
  {
    types.push_back(pType);
  }
  void pop(TType*pType)
  {
    QapAssert(!types.empty());
    QapAssert(pType==types.back());
    types.pop_back();
  }
  void ptr_push(void*ptr)
  {
    values.push_back(pValue);
    pValue=ptr;
  }
  void ptr_pop(void*ptr)
  {
    QapAssert(!values.empty());
    QapAssert(ptr==pValue);
    pValue=values.back();
    values.pop_back();
  }
public:
  void Do(TTypeStruct*p)
  {
    if (p->SubType)
    {
      auto*pSubType=p->SubType.get();
      ptr_push(pValue);
      pSubType->Use(*this);
      ptr_pop(pValue);
    }
    auto&arr=p->Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=(void*)(ex.Offset+int(pValue));
      auto*exType=ex.Type.get();
      push(exType);
      ptr_push(ptr);
      exType->Use(*this);
      ptr_pop(ptr);
      pop(exType);
    }
  }
  void Do(TTypeSys*p)
  {/*это вообще нас не интересует.*/}
  void Do(TTypeFactory*p)
  {/*это вообще нас не интересует.*/}
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    push(elemType);
    for (int i=0;i<Count;i++)
    {
      void*ptr=VecAPI->GetItem(pValue,i);
      ptr_push(ptr);
      elemType->Use(*this);
      ptr_pop(ptr);
    }
    pop(elemType);
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    push(elemType);
    for (int i=0;i<Count;i++)
    {
      void*ptr=&((uchar*)pValue)[elemSize*i];
      ptr_push(ptr);
      elemType->Use(*this);
      ptr_pop(ptr);
    }
    pop(elemType);
  }
  void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    auto&Serv=value.P;
    if (Space.CheckServSaveID(&Serv))
    {
      QapDebugMsg("the way used? ORL?");
      SkipCount++;
      auto&ex=Space[Serv.SaveID];
      if (automark)
      {
        ex.count++;
        ex.passed=true;
      }
      return;
    }
    QapAssert(types.size()>=2);
    auto*pElemType=p->ElementType.get();
    auto*type=types[types.size()-2];
    QapAssert(TTypeSelfPtr::UberCast(types.back()));
    QapAssert(type->IsBasedOn(pElemType));
    auto&ex=Space.UnsafeAdd(&Serv,type);
    //ex.system=false; system=bool(ex.ptr_adv.ptr);
    AddCount++;
    if (automark)
    {
      ex.count++;
      ex.passed=true;
    }
  }
  void Do(TTypeAutoPtr*p)
  {
    if (!p->ElementType)
    {
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      auto*ptr=(void*)&type;
      auto*pmTypeType=p->mType.Type.get();
      ptr_push(ptr);
      pmTypeType->Use(*this);
      ptr_pop(ptr);
    }
    auto*ptr=value.get();
    auto*pType=type.get();
    push(pType);
    if (ptr&&type)
    {
      ptr_push(ptr);
      pType->Use(*this);
      ptr_pop(ptr);
    }
    pop(pType);
  }
  void Do(TTypeWeakPtr*p)
  {/*это вообще нас не интересует.*/}
  void Do(TTypeHardPtr*p)
  {/*это вообще нас не интересует.*/}
  void Do(TTypeVoidPtr*p)
  {/*это вообще нас не интересует.*/}
  void Do(TTypeFieldPtr*p)
  {/*это вообще нас не интересует.*/}
};
inline void GrabServerPtr(TServerPtrSpace&Space,TType*pType,void*pValue,bool automark)
{
  TServerPtrGraberWithRealType SPGWRT(Space,pType,pValue,automark);
  pType->Use(SPGWRT);
  return;
  //[2014.05.14 12:34]
  //TServerPtrGraber SmartGraber(Space,automark);
  //TSmartPtrVisitor SPG(SmartGraber,pValue);
  //pType->Use(SPG);
}
class TClientPtrVcbCounter:public TClientPtrVisitor::ICallBack
{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrVcbCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if (!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if (item.passed)return;
    if (item.count)return;
    if (true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType);
      if (trigger)//если item.ptr описатель обычный.
      {
        //ищем заместитель.
        auto*pValue=(TType*)item.ptr.get();
        auto&ex=Space[pValue->Self];
        QapAssert(ex.ptr_lnk.IsValid());
        bool good=ex.ptr_lnk.type->IsBasedOn(pDeclareType);
        QapAssert(good);
        //переходим к соответствующему наследнику DeclareType'а.
        bool f[]=
        {
          pValue->IsBasedOn(pTType),
          pValue->IsBasedOn(pDeclareType)
        };
        auto*pdValue=(DeclareType*)ex.ptr_lnk.get();
        auto&d=Space[pdValue->Self];
        d.count++;
        d.passed=f[0]||f[1];
        item.passed=true;//пройден.
        return;
      }
      QapAssert(!item.hidden);
      if (safe)
      {
        //bool good=pType->IsBasedOn(elemType);
        bool good=EnvAdapter::IsBasedOn(pType,elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if (!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};
class TClientPtrVcbCounter20120828:public TClientPtrVisitor::ICallBack
{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  bool firstmode;
  TClientPtrVcbCounter20120828(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr),firstmode(true)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if (!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if (item.passed)return;
    if (item.count)return;
    if (item.system)return;
    if (true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType)||pType->IsBasedOn(pDeclareType);
      if (trigger)
      {
        int gg=1;
      }
      QapAssert(!item.hidden);
      if (safe)
      {
        //bool good=pType->IsBasedOn(elemType);
        bool good=EnvAdapter::IsBasedOn(pType,elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if (!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};
class DependsSolver
{
public:
  typedef TServerPtrSpace TSpace;
  //typedef TSmartPtrVisitor::ICallBack TClientPtrCounter;
  TClientPtrVisitor&CPC;
  TType*pTType;
  TType*pDeclareType;
  vector<int> Arr;
  bool fullprocess;
  DependsSolver(IEnvRTTI&Env,TClientPtrVisitor&CPC):CPC(CPC)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    fullprocess=false;
  }
  void prepare(TSpace&Space,bool force)
  {
    Arr.clear();
    for (int i=0;i<Space.size();i++)
    {
      auto&item=Space[i];
      //bool skip=!item.count||force?false:item.passed;
      if (item.hidden)QapAssert(item.system);
      bool skip=item.system||item.passed||!item.count;
      if (skip)continue;
      if (false)
      {
        bool skip=item.ptr.type->IsBasedOn(pTType);
        if (skip)
        {
          int gg=1;
          continue;
        }
      }
      if (!fullprocess)
      {
        //пропускаем заместителей.
        bool skip=item.ptr.type->IsBasedOn(pDeclareType);
        if (skip)
        {
          QapDebugMsg("WTF?");
          continue;
        }
      }
      Arr.push_back(item.id);
    }
  }
  void pass(TSpace&Space,const TRawPtr&ptr)
  {
    TType*pType=ptr.pType;
    void*pValue=ptr.pValue;
    if (true)
    {
      int sid=pType->Self.P.SaveID;
      QapAssert(sid);
      //помечаем описатель элемента, как достигнутый
      CPC.CB.DoVisitServerPtr(pType->Self.P,true,pTType);
    }
    //помечаем зависимые элементы, как достигнутые
    ClientMarker(CPC,pType,pValue);
  }
  TRawPtr get(const EnvVoidPtr&ptr)
  {
    TRawPtr tmp;
    tmp.pType=ptr.type;
    tmp.pValue=ptr.get();
    return tmp;
  }
  void step(TSpace&Space)
  {
    for (int i=0;i<Arr.size();i++)
    {
      int id=Arr[i];
      if (!id)continue;
      auto&item=Space[id];
      QapAssert(!item.system);
      if (!item.ptr.type)
      {
        QapAssert(item.passed&&item.ptr.type);
        item.passed=true;
        continue;
      }
      if (!fullprocess)
      {
        bool skip=item.ptr.type->IsBasedOn(pDeclareType);
        if (skip)
        {
          QapDebugMsg("WTF?");
          continue;
        }
      }
      //проходимся по элементу
      pass(Space,get(item.ptr));
      //помечаем элемент, как пройденный
      item.passed=true;
    }
  }
  void SolveDepends(TSpace&Space,bool fullprocess=true)
  {
    this->fullprocess=fullprocess;
    prepare(Space,false);
    //ищем новые цели и помечаем их пройденными
    for (int loop_counter=0;!Arr.empty()&&(loop_counter<1024);loop_counter++)
    {
      //посещаем все цели
      step(Space);
      //ищем новые цели
      prepare(Space,false);
    }
    QapAssert(Arr.empty());
    QapAssert(Space[0].count>0);
    this->fullprocess=false;
  }
  //operator bool(){return !Arr.empty();}
};
template<class TYPE>
class Sys$$<vector<TYPE>>
{
public:
  typedef TTypeVector metatype;
  typedef vector<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="vector";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->SizeType=Sys$$<IVectorAPI::SizeType>::GetRTTI(RTTI);
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->VecAPI=TVectorAPI<elemtype>::Get();
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "vector<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE,size_t Count>
class Sys$$<array<TYPE,Count>>
{
public:
  typedef TTypeArray metatype;
  typedef array<TYPE,Count> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="array";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->Size=Count;
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "array<"+Sys$$<TYPE>::GetFullName()+","+IToS(Count)+">";
  }
};
template<class TYPE>
class Sys$$<TFactory<TYPE>>
{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFactory";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->SubType=detail::GetParentClassOf<type>::GetRTTI(RTTI);
    typedef TSelfPtr<IFactory> SmartType;
    {
      typedef decltype((((type*)nullptr)->*(&type::Self))) realtype;
      typedef std::remove_reference<realtype>::type fieldtype;
      static_assert(std::is_same<SmartType,fieldtype>::value,"ok");
    }
    Info->SmartType=Sys$$<SmartType>::GetRTTI(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFactory<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TFactory<TFactory<TYPE>>>
{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TFactory<TYPE>> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    QapDebugMsg("WTF?");
    //metatype*Info=NULL;
    static string Name="TFactory";
    static metatype sys;
    static bool flag=true;
    if (flag)
    {
      sys.Info.Name=Name;
      sys.Info.Size=sizeof(Name);
      //if(RTTI.Register<type>(Info,Name))return Info;
      //Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
      //Info->SubType=Info->SubType=detail::GetParentClassOf<type>::GetRTTI(RTTI);
      flag=false;
    }
    //RTTI.OnRegEnd(Info);
    return &sys;
  }
  static string GetFullName()
  {
    return "TFactory<TFactory<"+Sys$$<TYPE>::GetFullName()+">>";
  }
};
template<class TYPE>
class Sys$$<TSelfPtr<TYPE>>
{
public:
  typedef TTypeSelfPtr metatype;
  typedef TSelfPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TSelfPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TSelfPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TAutoPtr<TYPE>>
{
public:
  typedef TTypeAutoPtr metatype;
  typedef TAutoPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TAutoPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TAutoPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TWeakPtr<TYPE>>
{
public:
  typedef TTypeWeakPtr metatype;
  typedef TWeakPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TWeakPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TWeakPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<THardPtr<TYPE>>
{
public:
  typedef TTypeHardPtr metatype;
  typedef THardPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="THardPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "THardPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<>
class Sys$$<TVoidPtr>
{
public:
  typedef TTypeVoidPtr metatype;
  typedef TVoidPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TVoidPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TVoidPtr";
  }
};
template<>
class Sys$$<TFieldPtr>
{
public:
  typedef TTypeFieldPtr metatype;
  typedef TFieldPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFieldPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFieldPtr";
  }
};
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
template<>
class TTxtIO<uint>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef uint type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=std::to_string(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    val=std::stoul(s);
  }
};
template<>
class TTxtIO<int>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef int type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    val=SToI(s);
  }
};
template<>
class TTxtIO<real>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef real type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    SToF(s,val);
  }
};
template<>
class TTxtIO<float>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef float type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    real tmp;
    SToF(s,tmp);
    val=tmp;
  }
};
template<>
class TTxtIO<bool>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef bool type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=BToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    SToB(s,val);
  }
};
template<>
class TTxtIO<char>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef char type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    if (CppString::IsValidCppChar(val))
    {
      char out[4]={'\'',val,'\'',0};
      s=out;
    }
    else
    {
      string tmp=CToH_raw(val);
      s="'\\x"+tmp+"'";
    }
  }
  void Load(string&s,void*p)
  {
    QapDebugMsg("under construction");
    return;
    type&val=*(type*)p;
    SToC(s,val);
  }
};
template<>
class TTxtIO<uchar>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef uchar type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p)
  {
    QapDebugMsg("under construction");
    return;
    type&val=*(type*)p;
    val=SToI(s);
  }
};
template<>
class TBinIO<string>:public IBinIO
{
public:
  typedef IBinIO ParentClass;
  typedef string type;
  typedef TBinIO<type> SelfClass;
public:
  void Save(QapIO&IO,void*p)
  {
    type&val=*(type*)p;
    int count=val.size();
    IO.SavePOD(&count,sizeof(count));
    if (!count)return;
    IO.SavePOD(&val[0],count);
  }
  void Load(QapIO&IO,void*p)
  {
    type&val=*(type*)p;
    int count=0;
    if (!IO.TryLoad(sizeof(count)))
    {
      IO.Crash();
      return;
    }
    IO.LoadPOD(&count,sizeof(count));
    if (!IO.TryLoad(count))
    {
      IO.Crash();
      return;
    }
    val.resize(count);
    if (!count)return;
    IO.LoadPOD(&val[0],count);
  }
public:
  void Copy(void*pOut,void*pInp)
  {
    string&out=*(string*)pOut;
    string&inp=*(string*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB)
  {
    string&a=*(string*)pA;
    string&b=*(string*)pB;
    return a==b;
  }
};
template<>
class TTxtIO<string>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef string type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    CppString cs=val;
    s="\""+cs.data+"\"";
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    if (s.size()<2)
    {
      QapDebugMsg("WTF?");
      return;
    }
    bool flag1=s.front()=='"';
    bool flag2=s.back()=='"';
    if (!flag1||!flag2)
    {
      QapDebugMsg("WTF?");
      return;
    }
    val=s.substr(1,int(s.size())-2);
    BinString bs=val;
    val=bs.data;
  }
};
//=====+++>>>>>TYPES(POD)
//[Line](=>)
template<> class Sys$$<uint>
{
public:
  typedef TTypeSys metatype;
  typedef uint type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="uint";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "uint";
  }
};
template<> class Sys$$<int>
{
public:
  typedef TTypeSys metatype;
  typedef int type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="int";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "int";
  }
};
template<> class Sys$$<real>
{
public:
  typedef TTypeSys metatype;
  typedef real type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="real";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "real";
  }
};
template<> class Sys$$<float>
{
public:
  typedef TTypeSys metatype;
  typedef float type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="float";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "float";
  }
};
template<> class Sys$$<bool>
{
public:
  typedef TTypeSys metatype;
  typedef bool type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="bool";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "bool";
  }
};
template<> class Sys$$<char>
{
public:
  typedef TTypeSys metatype;
  typedef char type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="char";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "char";
  }
};
template<> class Sys$$<uchar>
{
public:
  typedef TTypeSys metatype;
  typedef uchar type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="uchar";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "uchar";
  }
};
template<> class Sys$$<string>
{
public:
  typedef TTypeSys metatype;
  typedef string type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="string";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "string";
  }
};
//[Line](<=)
//<<<<<+++=====TYPES(POD)
class TPrinter
{
public:
  string&s;
  string indent;
  string sep;
  TPrinter(string&s):s(s)
  {
    sep=" = ";
  }
public:
  virtual void Indent()
  {
    indent+="  ";
  }
  virtual void Outdent()
  {
    indent.resize(max(0,indent.size()-2));
  }
  //virtual void Print(string const&name,string const&data){s+=indent+name+sep+data+"\n";}
  virtual void Print(string const&data)
  {
    s+=indent+data+"\n";
  }
};
class TMessage
{
public:
//=====+>>>>>TEnvRTTI
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TMessage SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  TWeakPtr<TType> type;
  int mode;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->type);
    (this->mode)=(mmRet);
  }
  //==Declaration Constructors==//
public:
  TMessage(const TMessage&)=delete;
  TMessage()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TMessage(TMessage&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TMessage&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->type=std::move(_Right.type);
    this->mode=std::move(_Right.mode);
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
      static const string Name="TMessage";
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
      Info->AddMemberDEF(Sys$$<TWeakPtr<TType>>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::mode))),"SET","mmRet");
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
      return "TMessage";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TEnvRTTI
public:
  enum TMode
  {
    mmBeg,
    mmRet,
    mmEnd
  };
};
class EnvTypeHolder
{
public:
//=====+>>>>>EnvTypeHolder
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef EnvTypeHolder SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  string FullName;
  TProduct Type;
  TProduct Factory;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->FullName);
    detail::FieldTryDoReset(this->Type);
    detail::FieldTryDoReset(this->Factory);
  }
  //==Declaration Constructors==//
public:
  EnvTypeHolder(const EnvTypeHolder&)=delete;
  EnvTypeHolder()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  EnvTypeHolder(EnvTypeHolder&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(EnvTypeHolder&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->FullName=std::move(_Right.FullName);
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
      static const string Name="EnvTypeHolder";
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
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"FullName",int(&(((SelfClass*)nullptr)->*(&SelfClass::FullName))),"DEF","$");
      Info->AddMemberDEF(Sys$$<TProduct>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
      Info->AddMemberDEF(Sys$$<TProduct>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
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
      return "EnvTypeHolder";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====EnvTypeHolder
public:
  static void hack_move(TProduct&out,TRTTIProduct&inp)
  {
    out.Alloc=inp.GetAlloc();
    out.Factory=inp.GetFactory();
    out.Memory=std::move(inp.Memory);
    inp.pType=nullptr;
  }
  void eat(EnvType&item)
  {
    FullName=item.Type->GetFullName();
    hack_move(Type,item.Type.Product);
    if (item.Factory)hack_move(Factory,item.Factory.Product);
  }
  void boom()
  {
    Type.Free();
    if (Factory)Factory.Free();
  }
  TType*GetType()
  {
    return (TType*)Type.Memory.ptr;
  }
  IFactory*GetFactory()
  {
    return (IFactory*)Factory.Memory.ptr;
  }
};
class TEnvRTTI:public IEnvRTTI
{
public:
//=====+>>>>>TEnvRTTI
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef TEnvRTTI SelfClass;
public:
  typedef IEnvRTTI ParentClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  vector<EnvType> Arr;
  THardPtr<IAllocator> Alloc;
  UniqueID ID;
  vector<TMessage> messages;
  THardPtr<IEnvRTTI> OwnerEnv;
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
    detail::FieldTryDoReset(this->Arr);
    detail::FieldTryDoReset(this->Alloc);
    detail::FieldTryDoReset(this->ID);
    detail::FieldTryDoReset(this->messages);
    detail::FieldTryDoReset(this->OwnerEnv);
  }
  //==Declaration Constructors==//
public:
  TEnvRTTI(const TEnvRTTI&)=delete;
  TEnvRTTI()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  TEnvRTTI(TEnvRTTI&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TEnvRTTI&&_Right)
  {
    //[Line](=>)
    struct hidden
    {
      static void foo(IEnvRTTI(*)=(SelfClass*)nullptr) {}};
    //[Line](<=)
    if (&_Right==this)return;
    {
      //[Line](=>)
      IEnvRTTI::operator=(std::move(_Right));
      //[Line](<=)
    }
    //[Line](=>)
    this->Arr=std::move(_Right.Arr);
    this->Alloc=std::move(_Right.Alloc);
    this->ID=std::move(_Right.ID);
    this->messages=std::move(_Right.messages);
    this->OwnerEnv=std::move(_Right.OwnerEnv);
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
      static const string Name="TEnvRTTI";
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
      Info->AddMemberDEF(Sys$$<vector<EnvType>>::GetRTTI(RTTI),"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<IAllocator>>::GetRTTI(RTTI),"Alloc",int(&(((SelfClass*)nullptr)->*(&SelfClass::Alloc))),"DEF","$");
      Info->AddMemberDEF(Sys$$<UniqueID>::GetRTTI(RTTI),"ID",int(&(((SelfClass*)nullptr)->*(&SelfClass::ID))),"DEF","$");
      Info->AddMemberDEF(Sys$$<vector<TMessage>>::GetRTTI(RTTI),"messages",int(&(((SelfClass*)nullptr)->*(&SelfClass::messages))),"DEF","$");
      Info->AddMemberDEF(Sys$$<THardPtr<IEnvRTTI>>::GetRTTI(RTTI),"OwnerEnv",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnerEnv))),"DEF","$");
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
      return "TEnvRTTI";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====TEnvRTTI
public:
  static void SysHasSelf();
public:
  string GetTypeFullNames()
  {
    string tmp;
    for (int i=0;i<Arr.size();i++)
    {
      if (i)tmp+=",\n";
      tmp+=Arr[i].Type->GetFullName();
    }
    return std::move(tmp);
  }
  void PrintLog(const string&fn="outlog.cpp")
  {
    CrutchIO io;
    TPrinter printer(io.mem);
    for (int i=0;i<messages.size();i++)
    {
      TMessage&EX=messages[i];
      TType*Info=EX.type.get();
      if (EX.mode==TMessage::mmBeg)
      {
        printer.Print("Register(\""+Info->GetFullName()+"\")");
        printer.Print("{");
        printer.Indent();
      }
      if (EX.mode==TMessage::mmRet)
      {
        printer.Print("Ret(\""+Info->GetFullName()+"\");");
      }
      if (EX.mode==TMessage::mmEnd)
      {
        printer.Outdent();
        printer.Print("}//"+Info->GetFullName());
      }
    }
    io.SaveFile(fn);
  }
  void OnRegBeg(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmBeg;
    messages.emplace_back(std::move(tmp));
  };
  void OnRegRet(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmRet;
    messages.emplace_back(std::move(tmp));
  };
  void OnRegEnd(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmEnd;
    messages.emplace_back(std::move(tmp));
  };
public:
  IAllocator*GetAlloc()
  {
    return Alloc.get();
  }
  virtual int RegInfo(TAutoPtr<TType>&&_Right)
  {
    EnvType tmp;
    tmp.Type=std::move(_Right);
    Arr.push_back(std::move(tmp));
    return Arr.size()-1;
  }
  virtual EnvType&GetEnvTypeById(int id)
  {
    return Arr[id];
  }
  virtual vector<EnvType>&GetArr()
  {
    return Arr;
  }
  ~TEnvRTTI()
  {
    clear();
  }
public:
  IEnvRTTI*GetOwnerEnv()
  {
    return OwnerEnv.get();
  }
public:
  void update()
  {
    QapCleanIf(Arr,[](EnvType&ex)
    {
      return !ex.Type;
    }
              );
  }
  bool IsValid()
  {
    for (int i=Arr.size()-1;i>=0;i--)
    {
      auto&ex=Arr[i].Type;
      if (!ex)
      {
        int temp=0;
        QapDebugMsg("fail");
        return false;
      }
    }
    return true;
  }
  void clear()
  {
    if (!IsValid())
    {
      QapDebugMsg("fail");
      update();
      QapAssert(IsValid());
    }
    unlink();
    int skip_count=0;
    for (int i=Arr.size()-1;i>=0;i=i?--i:i=Arr.size()-1)
    {
      skip_count++;
      auto&item=Arr[i];
      TAutoPtr<TType>&ex=item.Type;
      auto&nm=ex->Info.Name;
      auto&fn=ex->GetFullName();
      bool skip=!ex->CanDestroy();
      if (skip&&skip_count>Arr.size())break;
      if (skip)continue;
      item.Type=nullptr;
      item.Factory=nullptr;
      std::swap(item,Arr.back());
      Arr.pop_back();
      skip_count=0;
    }
    //CleanIf(Arr,[](EnvType&ex){return !ex.Type;});
    if (!Arr.empty())
    {
      PrintCur();
      QapAssert(Arr.empty());
      Arr.clear();
    }
  }
  //typedef vector<std::pair<string,TSaver_yEd::Container>> TScope_UG;
  static inline bool IsLegalChar(const unsigned char&c)
  {
    return InDip<char>('a',c,'z')||InDip<char>('A',c,'Z')||InDip<char>('0',c,'9');
  }
  static string string2xml(const string&str)
  {
    string tmp;
    tmp.reserve(str.size()*3);
    for (int i=0;i<str.size();i++)
    {
      tmp+=IsLegalChar(str[i])?CToS(str[i]):"&#"+IToS(str[i])+";";
    }
    return std::move(tmp);
  }
  void PrintCur()
  {
    for (int i=0;i<Arr.size();i++)
    {
      TAutoPtr<TType>&EX=Arr[i].Type;
      TType*pVal=EX.get();
      TType*pType=EX.Product.GetType();
      IAllocator*pAlloc=EX.Product.GetAlloc();
      IFactory*pFactory=EX.Product.GetFactory();
      auto&fn=EX->GetFullName();
    }
  }
  static void add_sniper_job(THardClientSpace&Space,TRawPtr&raw_ptr)
  {
    THardClientPtrGraber Graber(Space);
    TSmartPtrVisitor CPG(Graber,raw_ptr.pValue);
    raw_ptr.pType->Use(CPG);
  }
  void unlink()
  {
    if (Arr.empty())return;
    THardClientSpace Space;
    //ставим цели для снайперов
    for (int i=0;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      TRawPtr type(item.Type.Product.pType.get(),item.Type.get());
      add_sniper_job(Space,type);
      if (!item.Factory)continue;
      TRawPtr fact(item.Factory.Product.pType.get(),item.Factory.get());
      add_sniper_job(Space,fact);
    }
    //говорим метатипам метатипов, что мол всё хорошо и под контролем.
    //а сами отвязываем метатипы от владеющего указателя и привзываем к бочке с порохом.
    vector<EnvTypeHolder> holders;
    holders.resize(Arr.size());
    for (int i=0;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      auto&holder=holders[i];
      holder.eat(item);
    };
    //выбрасываем старые держатели метатипов
    Arr.clear();
    //снайперы снимают шляпы.
    Space.Do();
    //взрываем бочки с порохом.
    int skip_count=0;
    for (int i=int(holders.size())-1;skip_count<=int(holders.size());skip_count++,i=(!i?holders.size()-1:i-1))
    {
      auto&holder=holders[i];
      auto*pType=holder.GetType();
      bool skip=!pType->CanDestroy();
      if (skip)
      {
        QapDebugMsg("type : '"+holder.FullName+"'\nWTF?");
        continue;
      }
      //QAP_LOG(fn);
      holders[i].boom();
      std::swap(holder,holders.back());
      holders.pop_back();
      skip_count=0;
    }
    if (!holders.empty())
    {
      for (int i=0;i<holders.size();i++)
      {
        auto&holder=holders[i];
        auto&fn=holder.FullName;
        TType*pType=holder.GetType();
        int hc=pType->Self.P.HardCount;
      }
      bool please_no=true;
      QapAssert(holders.empty());
      holders.clear();//build a memory leak? lol
    }
  }
};
static TType*FindTypeByFullName(IEnvRTTI&Env,const string&FullName)
{
  auto&arr=Env.GetArr();
  for (int i=0;i<arr.size();i++)
  {
    auto*p=arr[i].Type.get();
    if (p->GetFullName()==FullName)
    {
      return p;
    }
  }
  return nullptr;
}

class TIsSameVisitor:public IVisitorRTTI{
public:
  typedef TIsSameVisitor SelfClass;
public:
  class TBranch:public TOutDev{
  public:
    TContext top;
    vector<TContext> items;
  public:
    void push_impl(){items.push_back(top);}
    void pop_impl(){top=items.back();items.pop_back();}
    TContext&back(){return items.back();}
    TContext&front(){return items.front();}
    int size(){return items.size();}
    TContext&operator[](int index){return items[index];}
  public:
    void push(DevCmd*pCmd)
    {
      QapAssert(!top.pCmd&&top.head.empty());
      push_impl();
      if(pCmd)
      {
        TCmdVisitor::t_dev dev;
        TCmdVisitor CV(dev,&top);
        pCmd->Use(CV);
        QapAssert(dev.ok);
        auto&back=this->back();
        back.head=std::move(top.head);
        back.pCmd=std::move(pCmd);
      }else{
        top.pType=nullptr;
        top.pValue=nullptr;
      }
      top.pCmd=nullptr;
      top.head.clear();
    }
    void pop()
    {
      QapAssert(!top.pCmd&&top.head.empty());
      pop_impl();
      top.pCmd=nullptr;
      top.head.clear();
    }
  };
  void fail(){ok=false;}
  typedef TOutDev::DevCmd DevCmd;
  void push(DevCmd*pCmd)
  {
    bef.push(pCmd);
    aft.push(pCmd);
  }
  void pop()
  {
    bef.pop();
    aft.pop();
  }
  template<class TYPE>
  static bool Exec(IEnvRTTI&Env,TYPE&bef,TYPE&aft)
  {
    TRawPtr rp_bef(Env,bef);
    TRawPtr rp_aft(Env,aft);
    TIsSameVisitor::TBranch branch_bef;
    TIsSameVisitor::TBranch branch_aft;
    branch_bef.top.pType=rp_bef.pType;
    branch_bef.top.pValue=rp_bef.pValue;
    branch_aft.top.pType=rp_aft.pType;
    branch_aft.top.pValue=rp_aft.pValue;
    TIsSameVisitor V(branch_bef,branch_aft);
    V.pTopType->Use(V);
    return V.ok;
  }
public:
  TBranch&bef;
  TBranch&aft;
  TType*&pTopType;
  bool ok;
public:
  TIsSameVisitor(TBranch&bef,TBranch&aft):bef(bef),aft(aft),ok(true),pTopType(bef.top.pType){}
public:
  void Do(TTypeStruct*p)
  {
    if(bef.top.pType!=aft.top.pType)return fail();
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    if(subtype)
    {
      TOutDev::TSubType tmp;
      push(&tmp);
      pTopType->Use(*this);
      pop();
      if(!ok)return;
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      TOutDev::TMemberID tmp(i);
      push(&tmp);
      pTopType->Use(*this);
      pop();
      if(!ok)return;
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeSys*p)
  {
    if(bef.top.pType!=aft.top.pType)return fail();
    auto*pbio=p->BinIO.get();
    auto result=pbio->IsSame(bef.top.pValue,aft.top.pValue);
    if(!result)return fail();
  }
  void Do(TTypeVector*p)
  {
    if(bef.top.pType!=aft.top.pType)return fail();
    auto*VecAPI=p->VecAPI.get();
    int CountBef=VecAPI->GetCount(bef.top.pValue);
    int CountAft=VecAPI->GetCount(aft.top.pValue);
    if(CountBef!=CountAft)return fail();
    if(!CountBef)return;
    TType*elemType=p->ElementType.get();
    //const string p_elemTypefullname=elemType->GetFullName();
    for(int i=0;i<CountBef;i++)
    {
      TOutDev::TVecID tmp(i);
      push(&tmp);
      pTopType->Use(*this);
      pop();
      if(!ok)return;
    }
  }
  void Do(TTypeSelfPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    TAutoPtr<void>&valueBef=*(TAutoPtr<void>*)bef.top.pValue;
    TAutoPtr<void>&valueAft=*(TAutoPtr<void>*)aft.top.pValue;
    if(bool(valueBef)!=bool(valueAft))return fail();
    if(!valueBef)return;
    TOutDev::TChunk tmp;
    push(&tmp);
    pTopType->Use(*this);
    pop();
  }
  void Do(TTypeWeakPtr*p){
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeHardPtr*p){
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");return fail();
  }
};
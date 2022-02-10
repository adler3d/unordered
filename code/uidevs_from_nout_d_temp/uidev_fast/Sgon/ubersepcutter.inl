class TUberSepCutterVisitor:public IVisitorRTTI,public TToolLexToStr{
public:
  typedef TUberSepCutterVisitor SelfClass;
public:
  class TBranch:public TOutDev{
  public:
    vector<string> out;
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
public:
  TBranch&dev;
public:
  TUberSepCutterVisitor(TBranch&dev):dev(dev){}
public:
  void Do(TTypeStruct*p)
  {
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    auto p_fullname=p->GetFullName();
    if(p_fullname==("t_sep"))for(;;)
    {
      int gg=1;
      auto&value=*(t_sep*)dev.top.pValue;
      auto&v=value.value;
      if(v.empty())break;
      if(v==" ")break;
      if(v=="\n")break;
      static const auto cm=CharMask::fromStr(" ");
      if(v.find("\t")!=string::npos)
      {
        v=fast_string_replace(v,"\t","  ");
      }
      if(cm.check(v))
      {
        v=" ";
      }
      auto a=split(v,"\n");
      if(a.size()>=2)
      {
        a[0]="";
        bool ok=cm.check(a.back());
        if(!ok)
        {
          a.back()="";
        }else{
          int hm=1;
        }
        a[1]=a.back();
        a.resize(2);
        v=join(a,"\n");
      }
      break;
    }
    if(subtype)
    {
      TOutDev::TSubType tmp;
      dev.push(&tmp);
      subtype->Use(*this);
      dev.pop();
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      TOutDev::TMemberID tmp(i);
      dev.push(&tmp);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSys*p)
  {
    return;
    TOutDev::TCmdHeadVisitor head;
    auto&arr=dev.items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      head.Context.pType=ex.pType;
      head.Context.pValue=ex.pValue;
      ex.pCmd->Use(head);
    }
    string s;
    p->TxtIO->Save(s,dev.top.pValue);
    dev.out.push_back("//"+head.out);
    dev.out.push_back(s);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(dev.top.pValue);
    if(!Count)return;
    TType*elemType=p->ElementType.get();
    const string p_elemTypefullname=elemType->GetFullName();
    for(int i=0;i<Count;i++)
    {
      TOutDev::TVecID tmp(i);
      dev.push(&tmp);
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSelfPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){QapAssert(p->ElementType);return;}
    TAutoPtr<void>&value=*(TAutoPtr<void>*)dev.top.pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*pmTypeType=p->mType.Type.get();
    if(!value)return;
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      TOutDev::TChunk tmp;
      dev.push(&tmp);
      type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeWeakPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");
  }
};
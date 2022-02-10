
template<typename TYPE>
class QapPool{
public:
  struct Rec
  {
    int id;
    int counter;
    bool used;
    Rec*prev;
    Rec*next;
    TYPE data;
    Rec():id(0),counter(0),used(false),prev(nullptr),next(nullptr){}
    void insert_me(){QapAssert(prev->next&&next->prev);prev->next=this;next->prev=this;}
    void remove_me(){QapAssert(prev->next&&next->prev);prev->next=next;next->prev=prev;}
    void insert_to(QapPool<TYPE>&owner,Rec*&pList)
    {
      QapAssert(!next&&!prev);
      QapAssert(this);
      if(!pList){
        pList=this;
        pList->next=this;
        pList->prev=this;
      }else{
        QapAssert(pList->prev);
        this->prev=pList->prev;
        this->next=pList;
        this->insert_me();
        pList=this;
      }
    }
    static Rec*remove(QapPool<TYPE>&arr,Rec*&pList)
    {
      Rec*result=pList;
      //QapAssert(pList->next&&pList->prev);
      {
        if(!pList->next){
          QapAssert(arr.pFront==pList);
          int n=arr.size();
          pList->next=&arr[pList->id+1%n];
          pList->next->prev=pList;
        }
        if(!pList->prev){
          QapAssert(arr.pFront==pList);
          int n=arr.size();
          pList->prev=&arr[pList->id+n-1%n];
          pList->prev->next=pList;
        }
        auto*next=pList->next;
        pList->remove_me();
        pList->next=nullptr;
        pList->prev=nullptr;
        auto old=pList;
        pList=next==pList?nullptr:next;
        if(!pList){
          int gg=1;
        }
      }
      return result;
    }
  };
  int pool_id;
  bool binded;
  TMemory mem;
  Rec*pFront;
  Rec*pList;
  int Size;
  int MaxSize;
  bool UseNewForEach;
public:
  void BuildDump(CrutchIO&IO)
  {
    string&out=IO.mem;
    QapAssert(out.empty());
    auto*cur=pFront;
    for(int i=0;i+Size<arr.size();i++)
    {
      string id=IToS(cur->id);
      string counter=IToS(cur->counter);
      out+=id+";"+counter+"\n";
      cur=cur->next;
    }
  }
  static int get_id()
  {
    static int cur_id=0;
    cur_id++;
    return cur_id;
  }
  QapPool(int MaxSize=0):Size(0),MaxSize(MaxSize),pFront(nullptr),pList(nullptr),binded(false),UseNewForEach(true){
    pool_id=get_id();mem.size=MaxSize*sizeof(Rec);mem.ptr=(TMemory::ptr_t*)new char[mem.size];

    //QapClock clock;clock.Start();
    memset(mem.ptr,0,mem.size);
    //clock.Stop();
    //QapDebugMsg(FToS(clock.MS()));

    Bind();
  }
 ~QapPool(){if(mem.ptr)delete[] mem.ptr;mem.ptr=nullptr;mem.size=0;}
  QapPool(const QapPool&){QapAssert(false);}
  void operator=(const QapPool&){QapAssert(false);}
  void operator=(QapPool&&ref){
    this->pool_id=std::move(ref.pool_id);
    this->binded=std::move(ref.binded);
    QapNoWay();//this->arr=std::move(ref.arr);
    this->pFront=std::move(ref.pFront);
    this->pList=std::move(ref.pList);
    this->Size=std::move(ref.Size);
    this->MaxSize=std::move(ref.MaxSize);
    this->UseNewForEach=std::move(UseNewForEach);
  }
  int size()const{return MaxSize;}
  const Rec&operator[](int id)const{auto*ptr=(Rec*)(void*)mem.ptr;return ptr[id];}
  Rec&operator[](int id){auto*ptr=(Rec*)(void*)mem.ptr;return ptr[id];}
  bool empty(){return !MaxSize;}
  Rec&front(){return operator[](0);}
  const Rec&front()const{return operator[](0);}
  const Rec&back()const{return operator[](MaxSize-1);}
  Rec&back(){return operator[](MaxSize-1);}
  void Bind()
  {
    auto&arr=*this;
    if(arr.empty())return;
    if(arr.size()<2)
    {
      QapAssert(arr.size()==1);
      pFront=&arr[0];
      pFront->next=pFront;
      pFront->prev=pFront;
      pFront->id=0;
      binded=true;
      return;
    }
    union {void*p;Rec (*z)[999];} g={&arr[0]};
    auto debugarr=g.z;
    pFront=&arr[0];
    pFront->id=0;
    auto*ptr=&arr[0];
    //QapClock clock;clock.Start();
    for(int i=0;i<MaxSize;i++)ptr[i].id=i;
    //clock.Stop();
    //QapDebugMsg(FToS(clock.MS()));
    //QapClock clock;clock.Start();
    if(0)
    {
      for(int i=1;i<arr.size();i++)
      {
        Rec&ax=arr[i-1];
        Rec&ex=arr[i-0];
        ax.next=&ex;
        ex.prev=&ax;
        ex.id=i;
      }
      Rec*pBack=&arr.back();
      pFront->prev=pBack;
      pBack->next=pFront;
    }
    //clock.Stop();
    //QapDebugMsg(FToS(clock.MS()));
    binded=true;
  }
  TYPE*add(){
    TYPE*p=nullptr;
    NewInstance(p);
    new(p) TYPE; 
    return p;
  }
  void del(TYPE*&ref){
    ref->~TYPE();
    FreeInstance(ref);
  }
  void NewInstance(TYPE*&pVar)
  {
    auto&arr=*this;
    if(Size>=MaxSize){QapDebugMsg("NoWay. QapPool is full. MaxSize = "+IToS(MaxSize));};
    QapAssert(pFront);
    QapAssert(!pFront->used);
    {
      pFront->used=true;
      pFront->counter++;
      pVar=&pFront->data;
      Size++;
      Rec::remove(*this,pFront)->insert_to(*this,pList);
    }
  }
  void FreeInstance(TYPE*&pVar)
  {
    auto&arr=*this;
    QapAssert(Size>0);
    int id=0?0:int((int)pVar-(int)&arr[0].data)/sizeof(arr[0]);
    for(int i=id;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(&ex.data==pVar)
      {
        QapAssert(ex.used);
        ex.used=false;
        {
          Rec*pTemp=&ex;
          Rec*&culprit=pTemp==pList?pList:pTemp;
          Rec::remove(*this,culprit)->insert_to(*this,pFront);
        }
        Size--;
        pVar=nullptr;
        return;
      }
    }
    QapAssert(!pVar);
    pVar=nullptr;
  }
  template<typename TYPE>
  void ForEach(TYPE&Func)
  {
    int c=Size;
    if(UseNewForEach){
      Rec*pCur=pList;
      for(int i=0;i<c;i++)
      {
        Rec*pNext=pCur->next;
        Rec&it=*pCur;
        if(it.used)
        {
          Func(&it.data);
        }
        pCur=pNext;
      }
    }else{
      for(int i=0;i<arr.size();i++)
      {
        if(!c)break;
        Rec&it=arr[i];
        if(it.used)
          Func(&it.data);
      }
    }
  }
};
template<class TYPE,int SIZE=1024*(1024+64)>
struct QapPoolPtr{
  TYPE*ptr;
  QapPoolPtr():ptr(nullptr){}
  QapPoolPtr(const QapPoolPtr&ref):ptr(nullptr){oper_set(ref);}
  QapPoolPtr(QapPoolPtr&&ref):ptr(nullptr){oper_set(std::move(ref));}
  TYPE*build(){free();return ptr=get_pool().add();}
  ~QapPoolPtr(){free();}
  void free(){if(ptr){get_pool().del(ptr);}}
  TYPE*get(){return ptr;}
  TYPE*operator->(){return ptr;}
  TYPE&operator*(){return*ptr;}
  void operator=(QapPoolPtr&&ref){oper_set(std::move(ref));}void oper_set(QapPoolPtr&&ref){free();ptr=ref.ptr;ref.ptr=nullptr;}
  void operator=(const QapPoolPtr&ref){return oper_set(ref);}void oper_set(const QapPoolPtr&ref){QapNoWay();*(int*)0=0;}
  static QapPool<TYPE>&get_pool(){static QapPool<TYPE> tmp(SIZE);if(!tmp.binded)tmp.Bind();return tmp;};
};
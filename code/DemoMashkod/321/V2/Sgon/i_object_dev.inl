struct t_clone_dev;

struct i_object_dev{
  struct i_cmd{
    template<class TYPE>
    static void init(TYPE*p){p->dev.push(*p);}
    template<class TYPE>
    static void free(TYPE*p){p->dev.pop(*p);}
  };
  #define IMPL_DEF(DEV,TYPE)\
  struct TYPE:public i_cmd{\
    typedef DEV t_dev;\
    DEV&dev;\
    TYPE(DEV&dev):dev(dev){init(this);}\
   ~TYPE(){free(this);}\
  };
  #define IMPL_INT(DEV,TYPE)\
  struct TYPE:public i_cmd{\
    typedef DEV t_dev;\
    DEV&dev;\
    int id;\
    TYPE(DEV&dev,int id):dev(dev),id(id){init(this);}\
   ~TYPE(){free(this);}\
  };
  //<LIST>
  IMPL_DEF(t_clone_dev,t_chunk);
  IMPL_DEF(t_clone_dev,t_chunk_type);
  IMPL_DEF(t_clone_dev,t_subtype);
  IMPL_INT(t_clone_dev,t_field);
  IMPL_INT(t_clone_dev,t_vec_id);
  IMPL_INT(t_clone_dev,t_arr_id);
  //</LIST>
  #undef IMPL_INT
  #undef IMPL_DEF
public:
};

/*-------------------------------------------------------------------------------------------------------------------------------*/
/*warining!*/struct t_object_dev:public i_object_dev{                                                        /*this is copy-paste*/
/*warining!*/public:                                                                                         /*this is copy-paste*/
/*warining!*/  typedef TVoidPtr::TRawPtr TRawPtr;                                                            /*this is copy-paste*/
/*warining!*/public:                                                                                         /*this is copy-paste*/
/*warining!*/  struct t_rec{                                                                                 /*this is copy-paste*/
/*warining!*/    TRawPtr ptr;                                                                                /*this is copy-paste*/
/*warining!*/    i_cmd*next;                                                                                 /*this is copy-paste*/
/*warining!*/  };                                                                                            /*this is copy-paste*/
/*warining!*/public:                                                                                         /*this is copy-paste*/
/*warining!*/  TRawPtr ptr;                                                                                  /*this is copy-paste*/
/*warining!*/  vector<t_rec> stack;                                                                          /*this is copy-paste*/
/*warining!*/public:                                                                                         /*this is copy-paste*/
/*warining!*/  void internal_push(i_cmd&ref){                                                                /*this is copy-paste*/
/*warining!*/    t_rec tmp={ptr,&ref};                                                                       /*this is copy-paste*/
/*warining!*/    stack.push_back(tmp);                                                                       /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/public:                                                                                         /*this is copy-paste*/
/*warining!*/  void push(t_subtype&ref)                                                                      /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    QapAssert(ptr.IsValid());                                                                   /*this is copy-paste*/
/*warining!*/    auto*pType=TTypeStruct::UberCast(ptr.pType);                                                /*this is copy-paste*/
/*warining!*/    QapAssert(pType);                                                                           /*this is copy-paste*/
/*warining!*/    auto*pSubType=pType->SubType.get();                                                         /*this is copy-paste*/
/*warining!*/    QapAssert(pSubType);                                                                        /*this is copy-paste*/
/*warining!*/    QapAssert(TTypeStruct::UberCast(pSubType));                                                 /*this is copy-paste*/
/*warining!*/    internal_push(ref);                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pType=pSubType;                                                                         /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/  void push(t_field&ref)                                                                        /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    QapAssert(ptr.IsValid());                                                                   /*this is copy-paste*/
/*warining!*/    auto*pType=TTypeStruct::UberCast(ptr.pType);                                                /*this is copy-paste*/
/*warining!*/    QapAssert(pType);                                                                           /*this is copy-paste*/
/*warining!*/    auto&arr=pType->Members;                                                                    /*this is copy-paste*/
/*warining!*/    QapAssert(ref.id>=0);                                                                       /*this is copy-paste*/
/*warining!*/    QapAssert(ref.id<arr.size());                                                               /*this is copy-paste*/
/*warining!*/    auto&field=arr[ref.id];                                                                     /*this is copy-paste*/
/*warining!*/    internal_push(ref);                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pType=field.Type.get();                                                                 /*this is copy-paste*/
/*warining!*/    ptr.pValue=field.getValue(ptr.pValue);                                                      /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/  void push(t_chunk&ref)                                                                        /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    QapAssert(ptr.IsValid());                                                                   /*this is copy-paste*/
/*warining!*/    auto*pType=TTypeAutoPtr::UberCast(ptr.pType);                                               /*this is copy-paste*/
/*warining!*/    QapAssert(pType);                                                                           /*this is copy-paste*/
/*warining!*/    auto*elemType=pType->ElementType.get();                                                     /*this is copy-paste*/
/*warining!*/    auto&value=*(TAutoPtr<void>*)ptr.pValue;                                                    /*this is copy-paste*/
/*warining!*/    auto*pNextType=value.Product.pType.get();                                                   /*this is copy-paste*/
/*warining!*/    QapAssert(value);                                                                           /*this is copy-paste*/
/*warining!*/    QapAssert(pNextType);                                                                       /*this is copy-paste*/
/*warining!*/    QapAssert(pNextType->IsBasedOn(elemType));                                                  /*this is copy-paste*/
/*warining!*/    internal_push(ref);                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pType=pNextType;                                                                        /*this is copy-paste*/
/*warining!*/    ptr.pValue=value.get();                                                                     /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/  void push(t_arr_id&ref)                                                                       /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    QapAssert(ptr.IsValid());                                                                   /*this is copy-paste*/
/*warining!*/    auto*pType=TTypeArray::UberCast(ptr.pType);                                                 /*this is copy-paste*/
/*warining!*/    QapAssert(pType);                                                                           /*this is copy-paste*/
/*warining!*/    auto*elemType=pType->ElementType.get();                                                     /*this is copy-paste*/
/*warining!*/    auto elemSize=elemType->Info.Size;                                                          /*this is copy-paste*/
/*warining!*/    auto Count=pType->Size;                                                                     /*this is copy-paste*/
/*warining!*/    QapAssert(elemType);                                                                        /*this is copy-paste*/
/*warining!*/    QapAssert(Count>0);                                                                         /*this is copy-paste*/
/*warining!*/    QapAssert(elemSize>0);                                                                      /*this is copy-paste*/
/*warining!*/    QapAssert(ref.id>=0);                                                                       /*this is copy-paste*/
/*warining!*/    QapAssert(ref.id<Count);                                                                    /*this is copy-paste*/
/*warining!*/    internal_push(ref);                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pType=elemType;                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pValue=&((uchar*)ptr.pValue)[elemSize*ref.id];                                          /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/  void push(t_vec_id&ref)                                                                       /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    QapAssert(ptr.IsValid());                                                                   /*this is copy-paste*/
/*warining!*/    auto*pType=TTypeVector::UberCast(ptr.pType);                                                /*this is copy-paste*/
/*warining!*/    QapAssert(pType);                                                                           /*this is copy-paste*/
/*warining!*/    auto*elemType=pType->ElementType.get();                                                     /*this is copy-paste*/
/*warining!*/    auto*VecAPI=pType->VecAPI.get();                                                            /*this is copy-paste*/
/*warining!*/    auto Count=VecAPI->GetCount(ptr.pValue);                                                    /*this is copy-paste*/
/*warining!*/    QapAssert(elemType);                                                                        /*this is copy-paste*/
/*warining!*/    QapAssert(Count>0);                                                                         /*this is copy-paste*/
/*warining!*/    QapAssert(ref.id>=0);                                                                       /*this is copy-paste*/
/*warining!*/    QapAssert(ref.id<Count);                                                                    /*this is copy-paste*/
/*warining!*/    internal_push(ref);                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pType=elemType;                                                                         /*this is copy-paste*/
/*warining!*/    ptr.pValue=VecAPI->GetItem(ptr.pValue,ref.id);                                              /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/  void push(t_chunk_type&ref)                                                                   /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    //also we can nothing to do, but for synchronize stack in memdev and tardev we must do this:/*this is copy-paste*/
/*warining!*/    internal_push(ref);                                                                         /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/  void pop(i_cmd&ref)                                                                           /*this is copy-paste*/
/*warining!*/  {                                                                                             /*this is copy-paste*/
/*warining!*/    QapAssert(!stack.empty());                                                                  /*this is copy-paste*/
/*warining!*/    {                                                                                           /*this is copy-paste*/
/*warining!*/      auto&back=stack.back();                                                                   /*this is copy-paste*/
/*warining!*/      auto*ptr_a=back.next;                                                                     /*this is copy-paste*/
/*warining!*/      auto*ptr_b=&ref;                                                                          /*this is copy-paste*/
/*warining!*/      QapAssert(ptr_a==ptr_b);                                                                  /*this is copy-paste*/
/*warining!*/      ptr=std::move(back.ptr);                                                                  /*this is copy-paste*/
/*warining!*/      back.ptr.setZero();                                                                       /*this is copy-paste*/
/*warining!*/      back.next=nullptr;                                                                        /*this is copy-paste*/
/*warining!*/    }                                                                                           /*this is copy-paste*/
/*warining!*/    stack.pop_back();                                                                           /*this is copy-paste*/
/*warining!*/  }                                                                                             /*this is copy-paste*/
/*warining!*/public:                                                                                         /*this is copy-paste*/
/*warining!*/  template<class TYPE>                                                                          /*this is copy-paste*/
/*warining!*/  TYPE*get(){return (TYPE*)ptr.pValue;}                                                         /*this is copy-paste*/
/*warining!*/};                                                                                              /*this is copy-paste*/
/*-------------------------------------------------------------------------------------------------------------------------------*/

struct t_clone_dev{
public:
  typedef TVoidPtr::TRawPtr TRawPtr;
public:/*
  struct t_list_of_conv{
    typedef void(*t_clone)(void*dest,void*source);
    static void clone_string(string&dest,string&source){dest=source;}
    static void clone_int(int&dest,int&source){dest=source;}
    static void clone_char(char&dest,char&source){dest=source;}
    static void clone_bool(bool&dest,bool&source){dest=source;}
    static void clone_real(real&dest,real&source){dest=source;}
    struct t_rec{
      string name;
      t_clone func;
    };
    typedef vector<t_rec> t_out;
    static t_rec make_rec(const string&name,void*func){t_rec tmp={name,(t_clone)func};return tmp;}
    static const t_out&get_all()
    {
      static t_out out;
      if(!out.empty())return out;
      #define F(TYPE)out.push_back(make_rec(#TYPE,(void*)&clone_##TYPE));
      F(string);
      F(char);
      F(bool);
      F(int);
      F(real);
      #undef F
      return out;
    }
  };*/
public:
  IEnvRTTI&Env;
  t_object_dev dest;
  t_object_dev source;
public:/*
  int get_func(TType*p){
    auto fn=p->GetFullName();
    auto&arr=t_list_of_conv::get_all();
    for(int i=0;i<arr.size();i++){if(arr[i].name==fn)return i;}
    return -1;
  }
  bool isSys(TType*p){
    return get_func(p)>=0;
  }
  void conv(TType*p){
    auto&arr=t_list_of_conv::get_all();
    int id=get_func(p);
    QapAssert(id>=0);
    auto&rec=arr[id];
    rec.func(dest.ptr.pValue,source.ptr.pValue);
  }*/
public:
  template<class TYPE>
  void push(TYPE&ref){
    source.push(ref);
    dest.push(ref);
  }
  template<class TYPE>
  void pop(TYPE&ref){
    source.pop(ref);
    dest.pop(ref);
  }
};

class TCloneVisitor:public IVisitorRTTI{
public:
  t_clone_dev&dev;
  TCloneVisitor(t_clone_dev&dev):dev(dev){}
public:
  void Do(TTypeStruct*p)
  {
    //bool sys_flag=dev.isSys(p);
    //if(sys_flag){dev.conv(p);return;}
    if(p->SubType){
      auto*ptr=TTypeStruct::UberCast(p->SubType.get());
      QapAssert(ptr);
      QapAssert(!ptr->SubType);
      QapAssert(ptr->Members.empty());
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      t_object_dev::t_field cmd(dev,i);
      ex.Type->Use(*this);
    }
  }
  void Do(TTypeSys*p)
  {
    auto*pBin=p->BinIO.get();
    if(!pBin){
      QapDebugMsg("no way");return;
    }
    pBin->Copy(dev.dest.ptr.pValue,dev.source.ptr.pValue);
    //V1.0{
    //  TQapIO IO;
    //  pBin->Save(IO,dev.source.ptr.pValue);
    //  IO.IO.pos=0;
    //  pBin->Load(IO,dev.dest.ptr.pValue);
    //}
    //V0.0{
    //  bool sys_flag=dev.isSys(p);
    //  if(sys_flag){dev.conv(p);return;}
    //  QapDebugMsg("no way");
    //}
  }
  void Do(TTypeVector*p)
  {
    //bool sys_flag=dev.isSys(p);
    //if(sys_flag){dev.conv(p);return;}
    auto*pElemType=p->ElementType.get();
    auto*api=p->VecAPI.get();
    auto count=api->GetCount(dev.source.ptr.pValue);
    api->SetCount(dev.dest.ptr.pValue,count);
    for(int i=0;i<count;i++){
      t_object_dev::t_vec_id cmd(dev,i);
      pElemType->Use(*this);
    }
  }
  void Do(TTypeArray*p)
  {
    //bool sys_flag=dev.isSys(p);
    //if(sys_flag){dev.conv(p);return;}
    auto*pElemType=p->ElementType.get();
    auto count=p->Size;
    for(int i=0;i<count;i++){
      t_object_dev::t_arr_id cmd(dev,i);
      pElemType->Use(*this);
    }
  }
  void Do(TTypeAutoPtr*p)
  {
    //bool sys_flag=dev.isSys(p);
    //if(sys_flag){dev.conv(p);return;}
    auto*pElemType=p->ElementType.get();
    auto&dest=*(TAutoPtr<void>*)dev.dest.ptr.pValue;
    auto&source=*(TAutoPtr<void>*)dev.source.ptr.pValue;
    if(!source)return;
    QapAssert(source.Product.pType->IsBasedOn(pElemType));
    QapAssert(!dest);
    dest.Product.pType=source.Product.pType.get();
    dest.Product.Init();
    t_object_dev::t_chunk cmd(dev);
    source.Product.pType->Use(*this);
  }
public:
  void Do(TTypeFactory*p){QapDebugMsg("no way");}
  void Do(TTypeSelfPtr*p){QapDebugMsg("no way");}
  void Do(TTypeWeakPtr*p){QapDebugMsg("no way");}
  void Do(TTypeHardPtr*p){QapDebugMsg("no way");}
  void Do(TTypeVoidPtr*p){QapDebugMsg("no way");}
  void Do(TTypeFieldPtr*p){QapDebugMsg("no way");}
public:
};
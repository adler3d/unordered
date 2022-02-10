class TOutDevEx{
public:
  //===>>===IVisitor
  #define LIST(F)F(TMemberID)F(TSubType)F(TVecID)F(TChunk)F(TField)

  #define F(TYPE)class TYPE;
  LIST(F)
  #undef F

  class DevCmd;

  class IVisitor{
  public:
    #define F(TYPE)virtual void Do(TYPE*p)=0;
      LIST(F)
    #undef F
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
      #define F(U)void Do(U*p){ptr=get(p);}
        LIST(F)
      #undef F
    };
    template<class TYPE>
    static TYPE*UberCast(DevCmd*p){
      if(!p)return nullptr;Is<TYPE,IVisitor> IS;p->Use(IS);return IS.ptr;
    }
  };

  #undef LIST
  //===<<===IVisitor
  class DevCmd{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DevCmd)OWNER(TOutDevEx)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
  //=====+>>>>>DevCmd
  #include "QapGenStruct.inl"
  //<<<<<+=====DevCmd
  public:
    virtual void Use(IVisitor&A){QapDebugMsg("no way.");};
  };

public:
//  Отличие TOutDevEx от TOutDev:
//    TOutDev::* - живут меньше одной итерации главного цикла. не изменяются после создания.
//    TOutDevEx::* - живут несколько итераций главного цикла. могут быть безопасно изменены после создания.
public:

  #define UBERCAST(TYPE)static TYPE*UberCast(DevCmd*p){return IVisitor::UberCast<TYPE>(p);}
  #define ADOTHIS()public:void Use(IVisitor&A){A.Do(this);}
  #define DEFCODE()ADOTHIS()UBERCAST(SelfClass)
    class TMemberID:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMemberID)PARENT(DevCmd)OWNER(TOutDevEx)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(int,id,SET,-1,$)\
      ADDEND()
    //=====+>>>>>TMemberID
    #include "QapGenStruct.inl"
    //<<<<<+=====TMemberID
    public:
      TMemberID(int id):id(id){}
    public:
      DEFCODE()
    };
    class TSubType:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSubType)PARENT(DevCmd)OWNER(TOutDevEx)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
    //=====+>>>>>TSubType
    #include "QapGenStruct.inl"
    //<<<<<+=====TSubType
    public:
      DEFCODE()
    };
    class TVecID:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TVecID)PARENT(DevCmd)OWNER(TOutDevEx)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(int,id,SET,-1,$)\
      ADDEND()
    //=====+>>>>>TVecID
    #include "QapGenStruct.inl"
    //<<<<<+=====TVecID
    public:
      TVecID(int id):id(id){}
    public:
      DEFCODE()
    };
    class TChunk:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TChunk)PARENT(DevCmd)OWNER(TOutDevEx)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TWeakPtr<TType>,pObjectType,DEF,$,$)\
      ADDEND()
    //=====+>>>>>TChunk
    #include "QapGenStruct.inl"
    //<<<<<+=====TChunk
    public:
      DEFCODE()
    };
    class TField:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TField)PARENT(DevCmd)OWNER(TOutDevEx)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TWeakPtr<TType>,pFieldType,DEF,$,$)\
      ADDEND()
    //=====+>>>>>TField
    #include "QapGenStruct.inl"
    //<<<<<+=====TField
    public:
      DEFCODE()
    };
  #undef DEFCODE
  #undef ADOTHIS
  #undef UBERCAST

public:

  class TContext{
  public:
    string head;//имя перехода вниз
    DevCmd*pCmd;//команда перехода вниз
  public:
    TType*pType;//тип источка
    void*pValue;//источник
  public:
    TContext():pCmd(nullptr),pType(nullptr),pValue(nullptr){}
  };

  class TCmdHeadVisitor:public IVisitor{
  public:
    TContext*pContext;
    bool error;
    string out;
    string error_string;
    TCmdHeadVisitor(){pContext=nullptr;error=false;out="Root";}
  public:
    void add_dot()
    {
      bool flag=out.substr(std::max<int>(0,int(out.size())-2))=="->";
      if(!flag)out.push_back('.');
    }
    void add_dot_head()
    {
      add_dot();
      add_head();
    }
    void add_head(...)
    {
      out+=pContext->head;
    }
    void add_text(const string&text)
    {
      out+=text;
    }
    void add_error(const string&msg)
    {
      QapAssert(!error);
      error=true;
      error_string=msg;
    }
  public:
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
      if(!pMetaType)
      {
        return add_error("bad input type");
      }
      //string debug_info=pMetaType->GetDebugInfo();
      if((id<0)||(id>=pMetaType->Members.size()))
      {
        return add_error("bad member index");
      }
      auto&ex=pMetaType->Members[id];
      //
      pContext->pValue=ex.getValue(pContext->pValue);
      pContext->pType=ex.Type.get();
      pContext->head=ex.Name;
      //
      add_dot_head();
    }
    void Do(TSubType*p)
    {
      auto*pSubType=pContext->pType->GetSubType();
      if(!pSubType)
      {
        return add_error("subtype not found");
      }
      //
      pContext->pValue=pContext->pValue;
      pContext->pType=pSubType;
      pContext->head="";
      //
      add_head();
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(pContext->pType);
      if(!pMetaType)
      {
        return add_error("bad input type");
      }
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(pContext->pValue);
      if((id<0)||(id>=count))
      {
        return add_error("bad index");
      }
      //
      pContext->pValue=pVecAPI->GetItem(pContext->pValue,id);
      pContext->pType=pElemType;
      pContext->head="["+IToS(id)+"]";
      //
      add_head();
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(pContext->pType);
      //QapAssert(pMetaType&&pMetaType->ElementType);
      if(!pMetaType||!pMetaType->ElementType)
      {
        return add_error("invalid chunk");
      }
      auto*pElemType=pMetaType->ElementType.get();
      TAutoPtr<void>&value=*(TAutoPtr<void>*)pContext->pValue;
      auto*pProductType=value.Product.pType.get();
      //
      if(!p->pObjectType)
      {
        return add_error("invalid chunk");
      }
      if(pProductType!=p->pObjectType.get())
      {
        return add_error("bad internal type");
      }
      //
      string fn=pProductType->GetFullName();
      //
      pContext->pValue=value.get();
      pContext->pType=pProductType;
      pContext->head="get<"+fn+">()";
      //
      //if(pProductType==pElemType)
      //{
      //  add_text("->");
      //  return;
      //}
      add_dot_head();
    }
    void Do(TField*p)
    {
      if(!p->pFieldType)
      {
        return add_error("invalid field_cmd");
      }
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(pContext->pType);
      if(!pMetaType)
      {
        return add_error("bad input type");
      }
      TFieldPtr&value=*(TFieldPtr*)pContext->pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      //
      if(p->pFieldType.get()!=field_type)
      {
        return add_error("bad fieldtype");
      }
      //
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      string code=fieldname.empty()?"object":"object."+fieldname;
      pContext->pValue=value.getValue();
      pContext->pType=field_type;
      pContext->head=code;
      string ft_fn=field_type->GetFullName();
      string ot_fn=object_type->GetFullName();
      if(true||object_type==field_type){
        add_dot();
        add_text("getValue<"+ft_fn+">()");
      }else{
        //add_dot();
        //add_text("getValue<"+ft_fn+">([]("+ot_fn+"&object)->void*{return &"+code+";})");
      }
    }
  };
public:
  class TCmdConverter:public TOutDev::IVisitor{
  public:
    TAutoPtr<TOutDevEx::DevCmd>pCmd;
    OutDevice::TCmdVisitor::t_dev dev;
    OutDevice::TCmdVisitor CV;
    OutDevice::TContext Context;
    IEnvRTTI*pEnv=nullptr;
    TCmdConverter():CV(dev,&Context){};
  public:
    void Init(IEnvRTTI*pEnv)
    {
      this->pEnv=pEnv;
      CV.pContext=&Context;
      //Go(nullptr);
    }
    void Go(TOutDev::DevCmd*p)
    {
      p->Use(CV);
      //pContext=CV.pContext;
      //QapAssert(p==pContext->pCmd);
    }
  public:
    void Do(TOutDev::TMemberID*p)
    {
      auto*ptr=pCmd.build<TMemberID>(*pEnv);
      ptr->id=p->id;
      Go(p);//after
    }
    void Do(TOutDev::TSubType*p)
    {
      auto*ptr=pCmd.build<TSubType>(*pEnv);
      Go(p);//after
    }
    void Do(TOutDev::TVecID*p)
    {
      auto*ptr=pCmd.build<TVecID>(*pEnv);
      ptr->id=p->id;
      Go(p);//after
    }
    void Do(TOutDev::TChunk*p)
    {
      Go(p);//before
      auto*ptr=pCmd.build<TChunk>(*pEnv);
      ptr->pObjectType=Context.pType;
    }
    void Do(TOutDev::TField*p)
    {
      Go(p);//before
      auto*ptr=pCmd.build<TField>(*pEnv);
      ptr->pFieldType=Context.pType;
    }
  };

  class TCmdConverterEx:public TOutDevEx::IVisitor{
  public:
    TAutoPtr<TOutDev::DevCmd>pCmd;
    TOutDevEx::TCmdHeadVisitor CV;
    TOutDevEx::TContext Context;
    IEnvRTTI*pEnv;
  public:
    void Init(IEnvRTTI*pEnv)
    {
      this->pEnv=pEnv;
      CV.pContext=&Context;
      //Go(nullptr);
    }
    void Go(TOutDevEx::DevCmd*p)
    {
      p->Use(CV);
      //pContext=CV.pContext;
      //QapAssert(p==pContext->pCmd);
    }
  public:
    void Do(TOutDevEx::TMemberID*p)
    {
      auto*ptr=pCmd.build<TOutDev::TMemberID>(*pEnv);
      ptr->id=p->id;
      Go(p);//after
    }
    void Do(TOutDevEx::TSubType*p)
    {
      auto*ptr=pCmd.build<TOutDev::TSubType>(*pEnv);
      Go(p);//after
    }
    void Do(TOutDevEx::TVecID*p)
    {
      auto*ptr=pCmd.build<TOutDev::TVecID>(*pEnv);
      ptr->id=p->id;
      Go(p);//after
    }
    void Do(TOutDevEx::TChunk*p)
    {
      Go(p);//before
      auto*ptr=pCmd.build<TOutDev::TChunk>(*pEnv);
    }
    void Do(TOutDevEx::TField*p)
    {
      Go(p);//before
      auto*ptr=pCmd.build<TOutDev::TField>(*pEnv);
    }
  };
public:
#define DEF_PRO_NESTED(F)F(DevCmd)F(TMemberID)F(TSubType)F(TVecID)F(TChunk)F(TField)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TOutDevEx)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TOutDevEx
#include "QapGenStruct.inl"
//<<<<<+=====TOutDevEx
public:
};
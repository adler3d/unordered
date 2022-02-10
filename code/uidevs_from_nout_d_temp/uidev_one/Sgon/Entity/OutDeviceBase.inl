class TOutDev{
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DevCmd)OWNER(TOutDev)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
  //=====+>>>>>DevCmd
  #include "QapGenStruct.inl"
  //<<<<<+=====DevCmd
  public:
    virtual void Use(IVisitor&A){QapDebugMsg("no way.");}
  };

  #define UBERCAST(TYPE)static TYPE*UberCast(DevCmd*p){return IVisitor::UberCast<TYPE>(p);}
  #define ADOTHIS()public:void Use(IVisitor&A){A.Do(this);}
  #define DEFCODE()ADOTHIS()UBERCAST(SelfClass)
    class TMemberID:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMemberID)PARENT(DevCmd)OWNER(TOutDev)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSubType)PARENT(DevCmd)OWNER(TOutDev)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TVecID)PARENT(DevCmd)OWNER(TOutDev)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TChunk)PARENT(DevCmd)OWNER(TOutDev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
    //=====+>>>>>TChunk
    #include "QapGenStruct.inl"
    //<<<<<+=====TChunk
    public:
      DEFCODE()
    };
    class TField:public DevCmd{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TField)PARENT(DevCmd)OWNER(TOutDev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
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

  class TCmdVisitor:public IVisitor{
  public:
    struct t_dev{
      bool ok=true;
      const char*pcode=nullptr;
      int line=-1;
      void err(const char*pcode,int line)
      {
        ok=false;
        this->pcode=pcode;
        this->line=line;
      }
    };
  public:
    t_dev&dev;
    TContext*pContext;
  public:
    TCmdVisitor(t_dev&dev,TContext*pContext):dev(dev),pContext(pContext){}
  public:
    #define CHECK(CODE)if(!(CODE)){dev.err(#CODE,__LINE__);return;}
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
      CHECK(pMetaType);
      //string debug_info=pMetaType->GetDebugInfo();
      CHECK(id<pMetaType->Members.size());
      CHECK(id>=0);
      auto&ex=pMetaType->Members[id];
      pContext->pValue=ex.getValue(pContext->pValue);
      pContext->pType=ex.Type.get();
      pContext->head=ex.Name;
    }
    void Do(TSubType*p)
    {
      pContext->pValue=pContext->pValue;
      pContext->pType=pContext->pType->GetSubType();
      pContext->head="";
      CHECK(pContext->pType);
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(pContext->pType);
      CHECK(pMetaType);
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(pContext->pValue);
      CHECK((id>=0)&&(id<count));
      pContext->pValue=pVecAPI->GetItem(pContext->pValue,id);
      pContext->pType=pElemType;
      pContext->head="["+IToS(id)+"]";
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(pContext->pType);
      CHECK(pMetaType);
      TAutoPtr<void>&value=*(TAutoPtr<void>*)pContext->pValue;
      pContext->pValue=value.get();
      pContext->pType=value.Product.pType.get();
      pContext->head="";
    }
    void Do(TField*p)
    {
      //QapDebugMsg("TFieldPtr is deprecated but used. lol :)");
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(pContext->pType);
      CHECK(pMetaType);
      TFieldPtr&value=*(TFieldPtr*)pContext->pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      pContext->pValue=value.getValue();
      pContext->pType=field_type;
      pContext->head=fieldname.empty()?"object":"object."+fieldname;
    }
    #undef CHECK
  };
public:
  class TCmdHeadVisitor:public IVisitor{
  public:
    TContext Context;
    string out;
    TCmdHeadVisitor(){out="Root";}
  public:
    void add_dot(){
      bool flag=out.substr(out.size()-2)=="->";
      if(!flag)out.push_back('.');
    };
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(Context.pType);
      QapAssert(pMetaType);
      auto&ex=pMetaType->Members[id];
      add_dot();
      out+=ex.Name;
    }
    void Do(TSubType*p)
    {
      //auto*pSubType=Context.pType->GetSubType();
      //string fn=pSubType->GetFullName();
      //out="static_cast<"+fn+">("+out+")";
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(Context.pType);
      QapAssert(pMetaType);
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(Context.pValue);
      QapAssert((id>=0)&&(id<count));
      out+="["+IToS(id)+"]";
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(Context.pType);
      QapAssert(pMetaType);
      TAutoPtr<void>&value=*(TAutoPtr<void>*)Context.pValue;
      auto*pObjectType=value.Product.pType.get();
      if(pObjectType==pMetaType)
      {
        out+="->";
        return;
      }
      string fn=pObjectType->GetFullName();
      //struct rec{int v};
      //rec v={5};
      //rec*pv=&v;
      //rec**ppv=&pv;
      //ppv->->v;
      add_dot();
      out+="get{"+fn+"}()";
    }
    void Do(TField*p)
    {
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(Context.pType);
      QapAssert(pMetaType);
      TFieldPtr&value=*(TFieldPtr*)Context.pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      string ft_fn=field_type->GetFullName();
      string ot_fn=object_type->GetFullName();
      string code=fieldname.empty()?"object":"object."+fieldname;
      if(true||object_type==field_type){
        add_dot();
        out=out+"getValue<"+ft_fn+">()";
      }else{
        //add_dot();
        //out=out+"getValue<"+ft_fn+">([]("+ot_fn+"&object)->void*{return &"+code+";})";
      }
    }
  };
public:
  class TCmdOffsetVisitorEx:public IVisitor{
  public:
    struct TContextPoint{
      TType*pType;
      void*pValue;
    };
    struct TContext{
      TContextPoint Object;
      TContextPoint Field;
      int Offset;
    };
    TContext*pContext;
  public:
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      auto&ex=pMetaType->Members[id];
      pContext->Offset+=ex.Offset;
      TContextPoint field={ex.Type.get(),ex.getValue(pContext->Field.pValue)};
      //pContext->Object=object;
      pContext->Field=field;
    }
    void Do(TSubType*p)
    {
      pContext->Field.pType=pContext->Field.pType->GetSubType();
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(pContext->Field.pValue);
      QapAssert((id>=0)&&(id<count));
      TContextPoint field={pElemType,pVecAPI->GetItem(pContext->Field.pValue,id)};
      pContext->Field=field;
      pContext->Object=field;
      pContext->Offset=0;
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      TAutoPtr<void>&value=*(TAutoPtr<void>*)pContext->Field.pValue;
      TType*pProductType=value.Product.pType.get();
      TContextPoint field={pProductType,value.get()};
      pContext->Field=field;
      pContext->Object=field;
      pContext->Offset=0;
    }
    void Do(TField*p)
    {
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      TFieldPtr&value=*(TFieldPtr*)pContext->Field.pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      TContextPoint object={object_type,value.object.ptr.get()};
      TContextPoint field={field_type,value.getValue()};
      pContext->Field=field;
      pContext->Object=object;
      pContext->Offset=offset;
    }
  };
public:
  class TCmdCloneVisitor:public IVisitor{
  public:
    //TType*pTypeMemberID;
    //TType*pTypeSubType;
    //TType*pTypeVecID;
    //TType*pTypeChunk;
    //TType*pTypeField;
    TAutoPtr<DevCmd>pCmd;
    IEnvRTTI*pEnv;
  public:
    void Init(IEnvRTTI*pEnv)
    {
      this->pEnv=pEnv;
      //pTypeMemberID=Sys$$<TMemberID>::GetRTTI(Env);
      //pTypeSubType=Sys$$<TSubType>::GetRTTI(Env);
      //pTypeVecID=Sys$$<TVecID>::GetRTTI(Env);
      //pTypeChunk=Sys$$<TChunk>::GetRTTI(Env);
      //pTypeField=Sys$$<TField>::GetRTTI(Env);
    }
  public:
    void Do(TMemberID*p)
    {
      auto*ptr=pCmd.build<TMemberID>(*pEnv);
      ptr->id=p->id;
    }
    void Do(TSubType*p)
    {
      auto*ptr=pCmd.build<TSubType>(*pEnv);
    }
    void Do(TVecID*p)
    {
      auto*ptr=pCmd.build<TVecID>(*pEnv);
      ptr->id=p->id;
    }
    void Do(TChunk*p)
    {
      auto*ptr=pCmd.build<TChunk>(*pEnv);
    }
    void Do(TField*p)
    {
      auto*ptr=pCmd.build<TField>(*pEnv);
    }
  };
public:
#define DEF_PRO_NESTED(F)F(DevCmd)F(TMemberID)F(TSubType)F(TVecID)F(TChunk)F(TField)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TOutDev)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TOutDev
#include "QapGenStruct.inl"
//<<<<<+=====TOutDev
public:
};
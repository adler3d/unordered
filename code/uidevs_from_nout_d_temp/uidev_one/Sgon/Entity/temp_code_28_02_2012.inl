/*
Self = TSelfPtr<QapRenderNode>(...)

string t=a[0]+" = "+a[1]+"<"+a[2]+">"+string("(")+a[3]+string(")");
*/

//===>>===ILineVisitor
#define LIST(F)F(LineText)F(LineTemplateType)F(LineField)

#define F(TYPE)class TYPE;
LIST(F)
#undef F

class ILineVisitor{
public:
#define F(TYPE)virtual void Do(TYPE*p)=0;
  LIST(F)
#undef F
};

#undef LIST
//===<<===ILineVisitor

class ILineObject{
public:
  virtual void Use(ILineVisitor&A)=0;
  virtual ~ILineObject(){}
};

class LineText:public ILineObject{
public:
  string text;
  string GetText(){return text;}
public:
  void Use(ILineVisitor&A){A.Do(this);}
};

class LineTemplateType:public ILineObject{
public:
  ILineObject*pTemplate;
  ILineObject*pType;
public:
  void Use(ILineVisitor&A){A.Do(this);}
};

class LineField:public ILineObject{
public:
  ILineObject*pVar;
  ILineObject*pType;
  ILineObject*pValue;
public:
  void Use(ILineVisitor&A){A.Do(this);}
};

class LineStringGraber:public ILineVisitor{
public:
  typedef LineStringGraber SelfClass;
public:
  string&out;
  LineStringGraber(string&out):out(out){}
  LineStringGraber(SelfClass*owner):out(owner->out){}
public:
  void Do(LineText*p){
    out+=p->text;
  }
  void Do(LineTemplateType*p){
    p->pTemplate->Use(*this);
    out+="<";
    p->pType->Use(*this);
    out+=">";
  }
  void Do(LineField*p){
    QapAssert(out.empty());
    p->pVar->Use(*this);
    out+=" = ";
    p->pType->Use(*this);
    out+="(";
    p->pValue->Use(*this);
    out+=")";
  }
};

class DataGen{
public:
  vector<ILineObject*> Arr;
public:
  void Clear()
  {
    for(int i=Arr.size()-1;i>=0;i--)delete Arr[i];
    Arr.clear();
  }
  template<class TYPE>
  TYPE*Build()
  {
    TYPE*p=new TYPE();
    Arr.push_back(p);
    return p;
  };
  template<class TYPE>
  TYPE*Build(ILineObject*&pOwner)
  {
    TYPE*p=new TYPE();
    Arr.push_back(p);
    pOwner=p;
    return p;
  };
  void BuildTestFieldWithDef(ILineObject*&pOwner)
  {
    #define GEN(TYPE)auto*pItem=Build<TYPE>();auto*pOwner=pItem;
    #define GEN_VAR(TYPE,NAME)auto*pItem=Build<TYPE>(NAME);auto*pOwner=pItem;
    #define GEN_TEXT(NAME,TEXT){GEN_VAR(LineText,NAME);pOwner->text=TEXT;}
    {
      GEN_VAR(LineField,pOwner);
      GEN_TEXT(pOwner->pVar,"Self");
      {
        GEN_VAR(LineTemplateType,pOwner->pType)
        GEN_TEXT(pOwner->pTemplate,"TSelfPtr");
        GEN_TEXT(pOwner->pType,"QapRenderNode");
      }
      GEN_TEXT(pOwner->pValue,"...");
    }
    #undef GEN
    #undef GEN_VAR
    #undef GEN_TEXT
  }
  void BuildTestField()
  {
    auto*pItem=Build<LineField>();
    auto*pOwner=pItem;
    {
      auto*pItem=Build<LineText>(pOwner->pVar);
      auto*pOwner=pItem;
      pOwner->text="Self";
    }
    {
      auto*pItem=Build<LineTemplateType>(pOwner->pType);
      auto*pOwner=pItem;
      {
        auto*pItem=Build<LineText>(pOwner->pTemplate);
        auto*pOwner=pItem;
        pOwner->text="TSelfPtr";
      }
      {
        auto*pItem=Build<LineText>(pOwner->pType);
        auto*pOwner=pItem;
        pOwner->text="QapRenderNode";
      }
    }
    {
      auto*pItem=Build<LineText>(pOwner->pValue);
      auto*pOwner=pItem;
      pOwner->text="...";
    }
  }
public:
  string Go()
  {
    string out;
    ILineObject*pOwner=nullptr;
    BuildTestFieldWithDef(pOwner);
    {
      LineStringGraber LSG(out);
      pOwner->Use(LSG);
    }
    pOwner=nullptr;
    Clear();
    return out;
  }
};
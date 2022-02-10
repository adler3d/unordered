
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
  virtual void DoReset()=0;
  virtual ~ILineObject(){}
};

class LineText:public ILineObject{
public:
  string text;
  string GetText(){return text;}
public:
  void Use(ILineVisitor&A){A.Do(this);}
  void DoReset(){
    text.clear();
  }
};

class LineTemplateType:public ILineObject{
public:
  ILineObject*pTemplate;
  ILineObject*pType;
public:
  void Use(ILineVisitor&A){A.Do(this);}
  void DoReset(){
    pTemplate=nullptr;
    pType=nullptr;
  }
};

class LineField:public ILineObject{
public:
  ILineObject*pVar;
  ILineObject*pType;
  ILineObject*pValue;
public:
  void Use(ILineVisitor&A){A.Do(this);}
  void DoReset(){
    pVar=nullptr;
    pType=nullptr;
    pValue=nullptr;
  }
};

class LineStringGraberEx:public ILineVisitor{
public:
  typedef LineStringGraberEx SelfClass;
public:
  struct Info
  {
    QapFont&font;
    vec2f&mpos;
  };
  struct Cmd{
    string out;
    vec2f pos;
  };
  Info&info;
  vec2f pos;
  vec2f dpos;
  string out;
  bool flag;
  string HL;
  string NL;
public:
  LineStringGraberEx(Info&info,const vec2f&pos):info(info),pos(pos){dpos.set_zero();flag=false;HL="^E";NL="^0";}
  LineStringGraberEx(SelfClass&owner):info(owner.info),pos(owner.pos+owner.dpos){dpos.set_zero();flag=false;HL="^E";NL="^0";}
public:
  bool add(const string&s)
  {
    bool flag=false;
    out+=s;
    int dx=QapQ3Text::GetLength(info.font,s);
    do{
      vec2f&mpos=info.mpos;
      vec2f pos=this->pos+dpos;
      int dy=info.font.Info.Coords[0].y;
      int h=dy-2;
      if(!InDip<int>(0,mpos.y-pos.y+dy,h))break;
      flag=InDip<int>(0,mpos.x-pos.x,dx-1);
    }while(false);
    dpos+=vec2f(dx,0);
    return flag;
  }
  bool addex(const string&s){return add(NL+s);}
  bool next(ILineObject*p,bool forceselect=false)
  {
    LineStringGraberEx LSG(*this);
    p->Use(LSG);
    string&s=LSG.out;
    QapAssert(!(LSG.flag&&flag));
    flag=LSG.flag||forceselect;
    s=(flag?HL:NL)+s;
    bool tmp=add(s);
    return tmp;
  }
public:
  void Do(LineText*p)
  {
    flag=add(p->text);
  }
  void Do(LineTemplateType*p)
  {
    QapAssert(!flag)
    
    LineStringGraberEx LSG(*this);
    bool q=false;
    q=q||LSG.next(p->pTemplate);
    q=q||LSG.addex("<");
    LSG.next(p->pType);
    q=q||LSG.addex(">");
    if(q){
      next(p->pTemplate,true);
      add(HL+"<");
      next(p->pType);
      add(HL+">");
    }else{
      add(LSG.out);
    }
  }
  void Do(LineField*p){
    QapAssert(out.empty());   
    if(p->pVar)next(p->pVar);
    bool q=false;
    LineStringGraberEx LSG(*this);
    if(p->pVar)q=q||LSG.addex(" = ");

    LSG.next(p->pType);

    if(p->pValue){
      q=q||LSG.addex("(");
      LSG.next(p->pValue);
      q=q||LSG.addex(")");
    }
    if(q){
      if(p->pVar)add(HL+" = ");
      next(p->pType);
      if(p->pValue){
        add(HL+"(");
        next(p->pValue);
        add(HL+")");
      }
    }else{
      add(LSG.out);
    }
  }
};


class DataGen{
public:
  vector<ILineObject*> Arr;
  ~DataGen(){Clear();}
public:
  void Clear()
  {
    for(int i=Arr.size()-1;i>=0;i--)delete Arr[i];
    Arr.clear();
  }
  template<class TYPE>
  TYPE*Build()
  {
    ILineObject*pOut=nullptr;
    return Build<TYPE>(pOut);
  };
  template<class TYPE>
  TYPE*Build(ILineObject*&pOut)
  {
    TYPE*p=new TYPE();
    Arr.push_back(p);
    pOut=p;
    pOut->DoReset();
    return p;
  };
  void BuildTestFieldWithDef(ILineObject*&pOut)
  {
    #define GEN(TYPE)auto*pItem=Build<TYPE>();auto*pOwner=pItem;
    #define GEN_VAR(TYPE,NAME)auto*pItem=Build<TYPE>(NAME);auto*pOwner=pItem;
    #define GEN_TEXT(NAME,TEXT){GEN_VAR(LineText,NAME);pOwner->text=TEXT;}
    {
      GEN_VAR(LineField,pOut)
      GEN_TEXT(pOwner->pVar,"Target")
      {
        GEN_VAR(LineTemplateType,pOwner->pType)
        GEN_TEXT(pOwner->pTemplate,"TAutoPtr")
        {
          GEN_VAR(LineTemplateType,pOwner->pType)
          GEN_TEXT(pOwner->pTemplate,"vector")
          {
            GEN_VAR(LineTemplateType,pOwner->pType)
            GEN_TEXT(pOwner->pTemplate,"TAutoPtr")
            GEN_TEXT(pOwner->pType,"ISubProgram")
          }
        }
      }
      GEN_TEXT(pOwner->pValue,"nullptr")
    }
    #undef GEN
    #undef GEN_VAR
    #undef GEN_TEXT
  }
public:
  string Go(QapFont&font,const vec2f&mpos,const vec2f&pos)
  {
    string out;
    ILineObject*pOwner=nullptr;
    BuildTestFieldWithDef(pOwner);
    {
      vec2f mousepos=mpos;
      LineStringGraberEx::Info info={font,mousepos};
      LineStringGraberEx LSG(info,pos);
      pOwner->Use(LSG);
      out=LSG.out;
    }
    pOwner=nullptr;
    Clear();
    return out;
  }
};
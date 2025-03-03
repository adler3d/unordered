class OutDevice:public TOutDev{
public:
  class TBranch{
  public:
    TContext top;
    vector<TContext> items;
    void push(){items.push_back(top);}
    void pop(){top=items.back();items.pop_back();}
    TContext&back(){return items.back();}
    TContext&front(){return items.front();}
    int size(){return items.size();}
    TContext&operator[](int index){return items[index];}
  };
public:
  TBranch branch;
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  class LineField{
  public:
    const string*pVar;
    const string*pType;
    const string*pValue;
  };
  struct ICallBack{
    typedef OutDevice::IVisitor IVisitor;
    typedef OutDevice::TMemberID TMemberID;
    typedef OutDevice::TSubType TSubType;
    typedef OutDevice::TVecID TVecID;
    typedef OutDevice::TChunk TChunk;
    typedef OutDevice::LineField LineField;
    virtual void OnVar(OutDevice&OD,LineField&Field){}
    virtual void OnType(OutDevice&OD,LineField&Field){}
    virtual void OnValue(OutDevice&OD,LineField&Field){}
    virtual void OnSys(OutDevice&OD,LineField&Field){}
  };
public:
  struct TDevContext
  {
    QapFont&font;
    vec2f mpos;
    vec2f pos;
    ICallBack&CB;
    int MaxDepth;
    int ScreenHieght;
    bool InScreenOptimization;
    bool SkipCommaInVector;
  };
  TDevContext DevContext;
  OutDevice(TDevContext&DevContext):DevContext(DevContext),indent(0){}
public:
  bool DepthTestPass()
  {
    bool passed=branch.size()<DevContext.MaxDepth;
    if(!passed)
    {
      AddValue("...depth_limit...");
    }
    return passed;
  }
public:
  //void push(DevCmd*pCmd)
  //{
  //  QapAssert(false);
  //  branch.push_back(Context);
  //  Context.pCmd=pCmd;
  //  if(pCmd)
  //  {
  //    TCmdVisitor CV;
  //    CV.pContext=&Context;
  //    pCmd->Use(CV);
  //  }
  //}
  void push(DevCmd*pCmd)
  {
    auto&top=branch.top;
    QapAssert(!top.pCmd&&top.head.empty());
    branch.push();
    if(pCmd)
    {
      TCmdVisitor CV;
      CV.pContext=&top;
      pCmd->Use(CV);
      auto&back=branch.back();
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
    auto&top=branch.top;
    QapAssert(!top.pCmd&&top.head.empty());
    branch.pop();
    top.pCmd=nullptr;
    top.head.clear();
  }
public:
  int indent;
  void Indent(){indent+=2;}
  void Outdent(){indent-=2;}
public:
  struct str_line{
    int indent;
    string text;
  };
  vector<str_line> lines;
  void AddText(const string&text)
  {
    LineField tmp;
    {}
      tmp.pVar=nullptr;
    {}
      //string type=Context.pType->GetFullName();
      tmp.pType=&text;
    {}
      tmp.pValue=nullptr;
    {}
    AddLineFromField(tmp);
  }
  void AddValue(const string&value)
  {
    auto&top=branch.top;
    auto&back=branch.back();
    LineField tmp;
    {}
      bool headempty=back.head.empty();
      tmp.pVar=headempty?nullptr:&back.head;
    {}
      string type=top.pType->GetFullName();
      tmp.pType=&type;
    {}
      tmp.pValue=&value;
    {}
    AddLineFromField(tmp);
  }
  void AddHead()
  {
    auto&top=branch.top;
    auto&back=branch.back();
    LineField tmp;
    {}
      bool headempty=back.head.empty();
      tmp.pVar=headempty?nullptr:&back.head;
    {}
      string type=top.pType->GetFullName();
      tmp.pType=&type;
    {}
      tmp.pValue=nullptr;
    {}
    AddLineFromField(tmp);
  }
public:
  struct SelectDetail
  {
    TDevContext&DC;
    vec2f dpos;
    string light_code[2];
    string&output;
    bool add(const string&s,bool force=false)
    {
      bool flag=force;
      int dx=QapQ3Text::GetLength(DC.font,s);
      int dy=DC.font.Info.Coords[0].y;
      if(!flag)do{
        vec2f&mpos=DC.mpos;
        vec2f pos=DC.pos+dpos;
        int h=dy-2;
        if(!InDip<int>(0,mpos.y-pos.y+dy,h))break;
        flag=InDip<int>(0,mpos.x-pos.x,dx-1);
      }while(false);
      dpos+=vec2f(dx,0);
      output+=light_code[flag]+s;
      return flag;
    }
    bool add(const string*p,bool force=false){return p?add(*p,force):force;}
    static bool go(string&out,const string*p){if(p)out+=*p;return p;}
  };
public:
  str_line&add_empty_line()
  {
    lines.push_back(std::move(str_line()));
    str_line&outline=lines.back();
    outline.indent=indent;
    return outline;
  }
  struct TGotoNextLineAtEnd
  {
    TDevContext&DevContext;
    ~TGotoNextLineAtEnd(){
      int dy=-DevContext.font.Info.Coords[0].y;
      DevContext.pos.y+=dy;
    }
  };
public:
  void AddLineFromField(LineField&line)
  {
    typedef SelectDetail UG;
    //
    TGotoNextLineAtEnd scope_end_detector={DevContext};
    //
    string&out=add_empty_line().text;
    //
    int dx=DevContext.font.Info.Coords[0].x;
    int dy=-DevContext.font.Info.Coords[0].y;
    int h=-dy-2;
    //
    if(DevContext.InScreenOptimization)
    {
      int ScreenHalfY=DevContext.ScreenHieght/2;
      int ScreenMaxY=+ScreenHalfY-dy;
      int ScreenMinY=-ScreenHalfY+dy;
      int y=DevContext.pos.y;
      if((y>ScreenMaxY)||(y<ScreenMinY))return;
    }
    if(!InDip<int>(0,DevContext.mpos.y-DevContext.pos.y-dy,h))
    {
      if(UG::go(out,line.pVar))out+=" = ";
      UG::go(out,line.pType);
      if(line.pValue){
        out+="(";
        out+=*line.pValue;
        out+=")";
      }
      return;
    }
    UG ug={DevContext,vec2f(indent*dx,0),{"^0","^E"},out};
    bool flag=false;
    if(ug.add(line.pVar)){DevContext.CB.OnVar(*this,line);}
    if(line.pVar)flag=ug.add(" = ",flag);
    if(ug.add(line.pType)){DevContext.CB.OnType(*this,line);}
    if(line.pValue)
    {
      flag=ug.add("(",flag);
      if(ug.add(line.pValue))
      {
        DevContext.CB.OnValue(*this,line);
      }
      flag=ug.add(")",flag);
    }  
    if(flag)
    {
      out.clear();
      ug.dpos=vec2f(indent*dx,0);
      if(ug.add(line.pVar)){}
      if(line.pVar)flag=ug.add(" = ",flag);
      if(ug.add(line.pType)){}
      if(line.pValue)
      {
        flag=ug.add("(",flag);
        if(ug.add(line.pValue)){}
        flag=ug.add(")",flag);
      }
    }
    if(flag)DevContext.CB.OnSys(*this,line);
  }
public:
  struct IExternalCallBack{
    virtual bool Pass(string&buff)=0;
    virtual void Next()=0;
    virtual void OnSelect()=0;
  };
public:
  void AddWithECB(IExternalCallBack&ECB)
  {
    typedef SelectDetail UG;
    //
    TGotoNextLineAtEnd scope_end_detector={DevContext};
    //
    string&out=add_empty_line().text;
    //
    int dx=DevContext.font.Info.Coords[0].x;
    int dy=-DevContext.font.Info.Coords[0].y;
    int h=-dy-2;
    //
    if(DevContext.InScreenOptimization)
    {
      int ScreenHalfY=DevContext.ScreenHieght/2;
      int ScreenMaxY=+ScreenHalfY-dy;
      int ScreenMinY=-ScreenHalfY+dy;
      int y=DevContext.pos.y;
      if((y>ScreenMaxY)||(y<ScreenMinY))return;
    }
    //if(!InDip<int>(0, ... y ... ,h))
    //
    UG ug={DevContext,vec2f(indent*dx,0),{"^0","^E"},out};
    //
    string buff;
    for(;ECB.Pass(buff);ECB.Next())
    {
      if(ug.add(buff))ECB.OnSelect();
    }
  }
};

class TProtoToolsEx:public IVisitorRTTI{
public:
  typedef TProtoToolsEx SelfClass;
  typedef OutDevice TSaveDev;
public:
  TSaveDev&dev;
  void*pValue;
public:
  TProtoToolsEx(TSaveDev&dev,void*pValue):dev(dev),pValue(pValue){}
  TProtoToolsEx(TProtoToolsEx&owner,void*pValue):dev(owner.dev),pValue(pValue){}
public:
  template<class TYPE>
  int weak_get_QTD_TPages_items_size()
  {
    QapTreeDebugger::TPages&value=*(QapTreeDebugger::TPages*)pValue;
    return value.Items.size();
  }
  void Do(TTypeStruct*p)
  { 
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    if(!subtype&&arr.empty())
    {
      dev.AddValue("");
      return;
    }
    if(!dev.DepthTestPass())return;
    const string p_fullname=p->GetFullName();
    if(p_fullname=="QapTreeDebugger::TPages")
    {
      int count=weak_get_QTD_TPages_items_size<void>();
      dev.AddValue("..."+IToS(count)+"...");
      return;
    }
    dev.AddHead();
    DevScope devscope(dev);
    {
      if(subtype)
      {
        TSaveDev::TSubType tmp;
        dev.push(&tmp);
        SelfClass next(*this,pValue);
        subtype->Use(next);
        dev.pop();
      }
      auto&arr=p->Members;
      if(p_fullname=="QapTreeDebugger::TBranch")
      {
        for(int i=0;i<arr.size();i++)
        {
          int max_depth;
          auto&ex=arr[i];
          if(i==0){
            max_depth=dev.DevContext.MaxDepth;
            dev.DevContext.MaxDepth=dev.branch.size()+2;
          }
          TSaveDev::TMemberID tmp(i);
          dev.push(&tmp); //dev.push("Sys$$<"+p->Name+">::GetRTTI()->Members["+IToS(i)+"].Name");
          SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
          ex.Type->Use(next);
          dev.pop();
          if(i==0){
            dev.DevContext.MaxDepth=max_depth;
          }
        }
        return;
      }
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        TSaveDev::TMemberID tmp(i);
        dev.push(&tmp); //dev.push("Sys$$<"+p->Name+">::GetRTTI()->Members["+IToS(i)+"].Name");
        SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
        ex.Type->Use(next);
        dev.pop();
      }
    }
  }
  void Do(TTypeSys*p)
  {
    if(p->TxtIO)
    {
      string value;
      p->TxtIO->Save(value,pValue);
      dev.AddValue(value);
    }else{
      string fn=p->GetFullName();
      QapDebugMsg("Sys$$<"+fn+">::GetRTTI()->TxtIO == nullptr");
      dev.AddValue("...error...");
    }
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    if(!Count)
    {
      dev.AddValue("");
      return;
    }
    if(!dev.DepthTestPass())return;
    TType*elemType=p->ElementType.get();
    dev.AddHead(); // implementation of dev.AddHead may be contents next code "value.resize(0
    if(!VecAPI->GetCount(pValue))return; //check it
    DevScope devscope(dev);
    for(int i=0;i<Count;i++)
    {
      //dev.AddText("//"+IToS(i));
      void*ptr=VecAPI->GetItem(pValue,i);
      TSaveDev::TVecID tmp(i);
      dev.push(&tmp);
      SelfClass next(*this,ptr);
      elemType->Use(next);
      dev.pop();
      if(!dev.DevContext.SkipCommaInVector)if(i+1!=Count)dev.AddText(",");
    }
  }
  void Do(TTypeSelfPtr*p){
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    dev.AddValue(GetSelfPtr(value));
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    if(!dev.DepthTestPass())return;
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*pmTypeType=p->mType.Type.get();
    if(!value)
    {
      dev.AddValue(GetServ(nullptr));
      return;
    }
    dev.AddHead();
    DevScope devscope(dev);
    //{
    //  dev.push(p->mType.Name);
    //  SelfClass next(*this,&type);
    //  pmTypeType->Use(next);
    //  dev.pop();
    //}
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      TSaveDev::TChunk tmp;
      dev.push(&tmp);
      SelfClass next(*this,ptr);
      type->Use(next);
      dev.pop();
    }
  }
  void Do(TTypeWeakPtr*p){
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    dev.AddValue(GetSpyPtr(value));
    //SaveSpyPtr("",value);
  }
  void Do(TTypeHardPtr*p){
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    dev.AddValue(GetSpyPtr(value));
    //SaveSpyPtr("",value);
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("deprecated");
    dev.AddValue("...deprecated...");
  }
  void Do(TTypeFieldPtr*p)
  {
    if(!dev.DepthTestPass())return;
    TFieldPtr&value=*(TFieldPtr*)pValue;
    if(value)
    {
      //auto index=SubFieldsInfo::OffsetToIndex(object_type,field_type,offset);
      //TType*OffsetType=p->OffsetType.get();
      //TType*IndexType=p->IndexType.get();
      static int max_recursion=2;
      if(value.object.ptr.get()==pValue)
      {
        dev.AddValue("...recursion...");
        return;
      }
      if(max_recursion<=0)
      {
        void*test_ptr=value.object.ptr.get();
        bool test_flag=pValue==test_ptr;
        dev.AddValue("...recursion...");
        return;
      }
      max_recursion--;
      //bool is_based_flag=object_type->IsBasedOn(field_type);
      //string fieldname=!is_based_flag?SubFieldsInfo::IndexToFieldName(object_type,field_type,index):"";
      auto offset=value.offset;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      for(;;)
      {
        //dev.AddText("under construction");
        dev.AddHead();  // implementation of dev.AddHead may be contents next code "value.off();"
        if(!value)break; //check it
        DevScope devscope(dev);
        {
          dev.push(nullptr);
          auto&top=dev.branch.top;
          top.pType=object_type;
          top.pValue=value.object.ptr.get();
          dev.branch.back().head="object";
          dev.AddValue("..."+GetServ(value.object.ptr.P.ptr)+"...");
          dev.pop();
        }
        void*pValue=value.getValue();
        {
          TSaveDev::TField tmp;
          dev.push(&tmp);
          SelfClass next(*this,pValue);
          field_type->Use(next);
          dev.pop();
        }
        break;
      }
      max_recursion++;
    }else{
      dev.AddValue(GetServ(nullptr));
    }
  }
public:
  template<template<class> class TEMPL,class U>
  string GetSpyPtr(TEMPL<U>&value)
  {
    TServerPtr<U>*serv=value.P.ptr;
    return std::move(GetServ(serv));
  }
  template<class U>
  string GetSelfPtr(TSelfPtr<U>&value)
  {
    TServerPtr<U>*serv=&value.P;
    return GetServ(serv);
  }
  string GetServ(nullptr_t)
  {
    return "nullptr";
  }
  template<class U>
  string GetServ(TServerPtr<U>*serv)
  {
    if(serv)
    {
      string HC=IToS(serv->HardCount);
      string WC=IToS(serv->RefCount);
      string UID=IToS(serv->UID.id);
      return "UID:"+UID+";WC:"+WC+";HC:"+HC;
    }
    //int id=0;
    //if(serv)
    //{
    //  id=serv->SaveID;
    //  if(!id)
    //  {
    //    QapAssert(id);
    //    id=-1;
    //  }
    //}
    //return std::move(GetServNameByID(id));
    return serv?"...":"nullptr";
  }
  struct DevScope{
    TSaveDev&dev;
    DevScope(TSaveDev&dev):dev(dev)
    {
      dev.AddText("{");
      dev.Indent();
    }
   ~DevScope()
    {
      dev.Outdent();
      dev.AddText("}");
    }
  };
};
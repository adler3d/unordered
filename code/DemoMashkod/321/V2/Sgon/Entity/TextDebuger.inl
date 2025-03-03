//
//   ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//
class TProtoViewGenEx{
public:
  struct str_line{
    int indent;
    string text;
  };
  struct ProtoLine{
    int indent;
    ILineObject*pLine;
  };
  vector<ProtoLine> Lines;
public:
  QapFont&font;
  vec2f mpos;
  vec2f pos;
  DataGen DG;
  int indent;
  struct way_elem{
    string name;
    TType*pType;
    void*pValue;
    int id;
    way_elem():pType(nullptr),id(-1),pValue(nullptr){}
    way_elem(const string&name):name(name),pType(nullptr),id(-1),pValue(nullptr){}
    way_elem(const string&name,int id,TType*pType,void*pValue):name(name),pType(pType),id(id),pValue(pValue){}
    way_elem(const way_elem&ref):name(ref.name),pType(ref.pType),id(ref.id),pValue(ref.pValue){}
    operator string()const{return name;}
  };
  vector<way_elem> path;
  //vector<int> way;
  TProtoViewGenEx(QapFont&font,const vec2f&mpos,const vec2f&pos):font(font),mpos(mpos),pos(pos),indent(0){}
public:
  /*
  string GenWihteSpace(int count)
  {
    string s;
    s.resize(count);
    for(int i=0;i<count;i++)s[i]=' ';
    return std::move(s);
  }
  void GrabTo(vector<string>&out)
  {
    int dy=-font.Info.Coords[0].y;
    int dx=font.Info.Coords[0].x;
    out.resize(Lines.size());
    for(int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      string&s=out[i];
      vec2d pos=this->pos+vec2f(dx+ex.indent*dx,i*dy);
      LineStringGraberEx::Info info={font,mpos};
      LineStringGraberEx LSG(info,pos);
      ex.pLine->Use(LSG);
      LSG.out=GenWihteSpace(ex.indent)+LSG.out;
      s=std::move(LSG.out);
    }
    Lines.clear();
  }*/
  void GrabToEx(vector<str_line>&out,LineStringGraberEx::IGrabCallBack&CB)
  {
    int dy=-font.Info.Coords[0].y;
    int dx=font.Info.Coords[0].x;
    out.resize(Lines.size());
    for(int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      auto&ax=out[i];
      vec2d pos=this->pos+vec2f(ex.indent*dx,i*dy);
      LineStringGraberEx::Info info={font,mpos};
      LineStringGraberEx LSG(info,pos,CB);
      ex.pLine->Use(LSG);
      ax.indent=ex.indent;
      ax.text=std::move(LSG.out);
    }
    Lines.clear();
  }
public:
  void Indent(){indent+=2;}
  void Outdent(){indent-=2;}
  void AddLine(ILineObject*pRoot)
  {
    ProtoLine PL={indent,pRoot};
    Lines.push_back(PL);
  }
  void AddText(const string&text){
    //QapDebugMsg("deprecated");
    auto*pRoot=DG.Build<LineField>();
    auto*pType=DG.Build<LineText>(pRoot->pType);
    pType->text=text;
    AddLine(pRoot);
  }
  void AddType(const string&type){
    const string&back=this->back(); 
    if(back.empty()){
      //auto*pRoot=DG.Build<LineText>();
      //pRoot->text=type;
      AddText(type);
    }else{
      auto*pRoot=DG.Build<LineField>();
      {
        auto*pVar=DG.Build<LineText>(pRoot->pVar);
        pVar->text=back;
      }
      {
        auto*pType=DG.Build<LineText>(pRoot->pType);
        pType->text=type;
      }
      pRoot->pValue=nullptr;
      AddLine(pRoot);
    }
  };
  void AddValue(const string&type,const string&value)
  {
    const string&back=this->back();
    DataGen&DG=this->DG;
    if(false){
      //QapDebugMsg("type : '"+type+"' ; value : '"+value+"'");
      //AddText("^2{...error...}");
    }else{
      auto*pRoot=DG.Build<LineField>();
      if(!back.empty())
      {
        auto*pVar=DG.Build<LineText>(pRoot->pVar);
        pVar->text=back;
      }else{pRoot->pVar=nullptr;}
      {
        auto*pType=DG.Build<LineText>(pRoot->pType);
        pType->text=type;
      }
      {
        auto*pValue=DG.Build<LineText>(pRoot->pValue);
        pValue->text=value;
      }
      AddLine(pRoot);
    }
  };
  struct ValueInfo{
    TType*pOwnerType;
    void*pOwnerValue;
    int member_id;
  };
  void AddTypeEx(const string&type,ValueInfo&info)
  {
    const string&back=this->back();
    DataGen&DG=this->DG;
    {
      auto*pRoot=DG.Build<LineFieldWithInfo>();
      if(!back.empty())
      {
        auto*pVar=DG.Build<LineText>(pRoot->pVar);
        pVar->text=back;
      }else{pRoot->pVar=nullptr;}
      {
        auto*pType=DG.Build<LineText>(pRoot->pType);
        pType->text=type;
      }
      {
        pRoot->pOwnerType=info.pOwnerType;
        pRoot->pOwnerValue=info.pOwnerValue;
        pRoot->member_id=info.member_id;
      }
      AddLine(pRoot);
    }
  };
  void AddValueEx(const string&type,const string&value,ValueInfo&info)
  {
    const string&back=this->back();
    DataGen&DG=this->DG;
    {
      auto*pRoot=DG.Build<LineFieldWithInfo>();
      if(!back.empty())
      {
        auto*pVar=DG.Build<LineText>(pRoot->pVar);
        pVar->text=back;
      }else{pRoot->pVar=nullptr;}
      {
        auto*pType=DG.Build<LineText>(pRoot->pType);
        pType->text=type;
      }
      {
        auto*pValue=DG.Build<LineText>(pRoot->pValue);
        pValue->text=value;
      }
      {
        pRoot->pOwnerType=info.pOwnerType;
        pRoot->pOwnerValue=info.pOwnerValue;
        pRoot->member_id=info.member_id;
      }
      AddLine(pRoot);
    }
  };
  void push(const string&dir){path.push_back(dir);}
  void push(const string&dir,int id,TType*pType,void*ptr){path.push_back(way_elem(dir,id,pType,ptr));}
  void push(){static const string empty;path.push_back(empty);}
  void pop(){path.pop_back();}
  const string back()const{return path.empty()?(string("")):path.back();}
};
//
//   --------------------------------------------------------------------------------
//
class TProtoTools:public IVisitorRTTI{
public:
  typedef TProtoTools SelfClass;
  typedef TProtoViewGenEx TSaveDev;
public:
  TSaveDev&dev;
  void*pValue;
public:
  TProtoTools(TSaveDev&dev,void*pValue):dev(dev),pValue(pValue){}
  TProtoTools(TProtoTools&owner,void*pValue):dev(owner.dev),pValue(pValue){}
public:
  void AddHead(TType*p)
  {
    string&fullname=p->GetFullName();
    dev.AddType(fullname);
  }
  void AddHeadEx(TType*p)
  {
    {
      string&fullname=p->GetFullName();
      auto&back=dev.path.back();
      if(!back.pType){AddHead(p);return;}
      TSaveDev::ValueInfo info;
      info.member_id=back.id;
      info.pOwnerType=back.pType;
      info.pOwnerValue=back.pValue;
      dev.AddTypeEx(fullname,info);
    }
    //
  }
  void AddData(TType*p,const string&data)
  {
    string&fullname=p->GetFullName();
    dev.AddValue(fullname,data);
  }
  void AddValue(TType*p,const string&data)
  {
    string&fullname=p->GetFullName();
    auto&back=dev.path.back();
    if(!back.pType){AddData(p,data);return;}
    TSaveDev::ValueInfo info;
    info.member_id=back.id;
    info.pOwnerType=back.pType;
    info.pOwnerValue=back.pValue;
    dev.AddValueEx(fullname,data,info);
  }
  void Do(TTypeStruct*p)
  {
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    if(!subtype&&arr.empty())
    {
      AddValue(p,"");
      return;
    }
    AddHeadEx(p);
    DevScope devscope(dev);
    {
      if(subtype)
      {
        dev.push("",-1,p,pValue);
        SelfClass next(*this,pValue);
        subtype->Use(next);
        dev.pop();
      }
      auto&arr=p->Members;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        dev.push(ex.Name,i,p,pValue); //dev.push("Sys$$<"+p->Name+">::GetRTTI()->Members["+IToS(i)+"].Name");
        SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
        ex.Type->Use(next);
        dev.pop();
      }
    }
  }
  void Do(TTypeSys*p)
  {
    if(p->SubType)
    {
      AddHead(p);
      DevScope devscope(dev);
      dev.push();
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
      dev.pop();
    };
    if(p->TxtIO)
    {
      string value;
      p->TxtIO->Save(value,pValue);
      string fn=p->GetFullName();
      bool is_string=fn=="string";
      if(is_string)
      {
        CppString cs=value;
        value="\""+cs.data+"\"";
      }
      AddValue(p,value);
    }
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    if(!Count)
    {
      AddValue(p,"");
      return;
    }
    TType*elemType=p->ElementType.get();
    AddHeadEx(p);
    DevScope devscope(dev);
    for(int i=0;i<Count;i++){
      dev.AddText("//"+IToS(i));
      void*ptr=VecAPI->GetItem(pValue,i);
      dev.push();
      SelfClass next(*this,ptr);
      elemType->Use(next);
      dev.pop();
      if(i+1!=Count)dev.AddText(",");
    }
  }
  virtual void Do(TTypeSelfPtr*p){
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    AddValue(p,GetSelfPtr(value));
  }
  virtual void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*SmartType=p->SmartType.get();
    if(!value)
    {
      AddValue(p,GetServ(nullptr));
      return;
    }
    AddHeadEx(p);
    DevScope devscope(dev);
    //{
    //  dev.push("pType");
    //  SelfClass next(*this,&type);
    //  SmartType->Use(next);
    //  dev.pop();
    //}
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      dev.push("");
      SelfClass next(*this,ptr);
      type->Use(next);
      dev.pop();
    }
  }
  virtual void Do(TTypeWeakPtr*p){
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    AddValue(p,GetSpyPtr(value));
    //SaveSpyPtr("",value);
  }
  virtual void Do(TTypeHardPtr*p){
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    AddValue(p,GetSpyPtr(value));
    //SaveSpyPtr("",value);
  }
  virtual void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    if(value.ptr)
    {
      TType*SmartType=p->SmartType.get();
      AddHead(p);
      DevScope devscope(dev);
      {
        dev.push("type");
        SelfClass next(*this,&value.type);
        SmartType->Use(next);
        dev.pop();
      }
      dev.push("ptr");
      dev.AddType(GetSpyPtr(value.ptr));
      dev.pop();
    }else{
      AddValue(p,GetServ(nullptr));
    }
  }
  virtual void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    if(value)
    {
      auto offset=value.offset;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto index=SubFieldsInfo::OffsetToIndex(object_type,field_type,offset);
      TType*OffsetType=p->OffsetType.get();
      TType*IndexType=p->IndexType.get();
      
      static int max_recursion=2;
      if(value.object.ptr.get()==pValue)
      {
        AddValue(p,"...recursion...");
        return;
      }
      if(max_recursion<=0)
      {
        void*test_ptr=value.object.ptr.get();
        bool test_flag=pValue==test_ptr;
        AddValue(p,"...recursion...");
        return;
      }
      max_recursion--;
      bool is_based_flag=object_type->IsBasedOn(field_type);
      string fieldname=!is_based_flag?SubFieldsInfo::IndexToFieldName(object_type,field_type,index):"";
      if(true)
      {
        AddHeadEx(p);
        DevScope devscope(dev);
        dev.push("object");
        AddValue(object_type,"...");
        dev.pop();
        void*pValue=value.getValue();
        dev.push("object"+fieldname);
        SelfClass next(*this,pValue);
        field_type->Use(next);
        dev.pop();
      }
      max_recursion++;
      //AddHead(p);
      //DevScope devscope(dev);
      //TType*VdptrType=p->VdptrType.get();
      //{
      //  dev.push("object");
      //  SelfClass next(*this,&value.object);
      //  VdptrType->Use(next);
      //  dev.pop();
      //}
      //TType*SmartType=p->SmartType.get();
      //{
      //  dev.push("type");
      //  SelfClass next(*this,&value.type);
      //  SmartType->Use(next);
      //  dev.pop();
      //}
      //auto offset=value.offset;
      //TType*object_type=value.object.type.get();
      //TType*field_type=value.type.get();
      //auto index=SubFieldsInfo::OffsetToIndex(object_type,field_type,offset);
      //TType*OffsetType=p->OffsetType.get();
      //TType*IndexType=p->IndexType.get();
      //{
      //  dev.push("index");
      //  SelfClass next(*this,&index);
      //  IndexType->Use(next);
      //  dev.pop();
      //}
    }else{
      AddValue(p,GetServ(nullptr));
    }
  }
public:
  template<template<class> class TEMPL,class U>
  string GetSpyPtr(TEMPL<U>&value)
  {
    //static TBinIO<int> pod;
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
      return WC+"/"+HC;
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
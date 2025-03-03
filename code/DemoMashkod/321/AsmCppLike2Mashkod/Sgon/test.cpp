#include "StdAfx.h"

#include "t_error_tool.inl"

string load_file(const string&fn){
  CrutchIO IO;
  IO.LoadFile(fn);
  return IO.mem;
}

template<class TYPE>
struct unique_ptr_arr{
  vector<TYPE*> arr;
  struct t_retval_add{
    bool found;
    int id;
    t_retval_add&set(bool found,int id){this->found=found;this->id=id;return *this;}
  };
  t_retval_add add(TYPE*value){
    t_retval_add out={false,-1};
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex==value){return out.set(true,i);}
    }
    out.set(false,arr.size());
    arr.push_back(value);
    return out;
  }
  bool find_ptr(void*ptr)const{
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex==ptr){return true;}
    }
    return false;
  }
};

struct unique_arr{
  vector<string> arr;
  struct t_retval_add{
    bool found;
    int id;
    t_retval_add&set(bool found,int id){this->found=found;this->id=id;return *this;}
  };
  t_retval_add add(const string&value){
    t_retval_add out={false,-1};
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex==value){return out.set(true,i);}
    }
    out.set(false,arr.size());
    arr.push_back(value);
    return out;
  }
};

#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "t_json.inl"
#include "t_json_str_tool.inl"

void run_app(){
  return;
  string input=load_file("test20131120.txt");
  string out=t_error_tool::get_codefrag(input,1);
  int gg=1;
}

template<class TYPE>
string vector_of_pair_to_json_object(const vector<TYPE>&arr){
  static_assert(false,"under construction");
  string out;
  for(int i=0;i<arr.size();i++){
    string&key=arr[i].key;
    string&value=arr[i].value;
  }
  return out;
}

struct t_json_pair{
  string key;
  string value;
};

vector<t_json_pair> type2arr_of_pair(TTypeStruct*p){
  vector<t_json_pair> out;
  auto&arr=p->Members;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    t_json_pair pair={ex.Name,ex.Type->GetFullName()};
    out.push_back(pair);
  }
  return out;
}

TType*find_ttype(IEnvRTTI&Env,const string&fullname){
  auto&arr=Env.GetArr();
  for(int i=0;i<arr.size();i++){
    auto*p=arr[i].Type.get();
    QapAssert(p);
    string fn=p->GetFullName();
    if(fn!=fullname)continue;
    return p;
  }
  return nullptr;
}

TTypeStruct*find_ttypestruct(IEnvRTTI&Env,const string&fullname){
  auto&arr=Env.GetArr();
  for(int i=0;i<arr.size();i++){
    auto*p=TTypeStruct::UberCast(arr[i].Type.get());
    if(!p)continue;
    string fn=p->GetFullName();
    if(fn!=fullname)continue;
    return p;
  }
  return nullptr;
}

vector<string> get_impls(IEnvRTTI&Env,const string&base){
  auto&arr=Env.GetArr();
  auto*pBase=find_ttypestruct(Env,base);
  QapAssert(pBase);
  vector<string> out;
  for(int i=0;i<arr.size();i++){
    auto*p=TTypeStruct::UberCast(arr[i].Type.get());
    if(!p)continue;
    auto*psub=TTypeStruct::UberCast(p->SubType.get());
    if(!psub)continue;
    if(psub!=pBase)continue;
    string subfn=psub->GetFullName();
    string fn=p->GetFullName();
    out.push_back(fn);
  }
  return out;
}

string type2json_pair(IEnvRTTI&Env,const string&type){
  auto*pType=find_ttypestruct(Env,type);
  QapAssert(pType);
  auto arr=type2arr_of_pair(pType);
  vector<string> out;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    out.push_back(Str2Json(ex.key)+":"+Str2Json(ex.value));
  }
  return Str2Json(type)+":{"+join(out,",")+"}";
}

struct TFooBarDev{
public:
  IEnvRTTI&Env;
  unique_ptr_arr<TType> arr;
public:
  void add_impls(const TType*pBase){
    auto&arr=Env.GetArr();
    QapAssert(pBase);
    for(int i=0;i<arr.size();i++){
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      auto*psub=TTypeStruct::UberCast(p->SubType.get());
      if(!psub)continue;
      if(psub!=pBase)continue;
      this->arr.add(p);
    }
  }
};

class TFooBarBaz:public IVisitorRTTI{
public:
  typedef TFooBarBaz SelfClass;
public:
  TFooBarDev&dev;
  TFooBarBaz(TFooBarDev&dev):dev(dev){}
  //TFooBarBaz(SelfClass&owner):dev(owner.dev){}
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      auto*pStruct=TTypeStruct::UberCast(p->SubType.get());
      if(pStruct){
        QapAssert(pStruct->Members.empty());
        QapAssert(!pStruct->SubType);
      }
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=ex.Type.get();
      dev.arr.add(pType);
    }
  }
  void Do(TTypeSys*p)
  {
    dev.arr.add(p);
  }
  void Do(TTypeVector*p)
  {
    TType*elemType=p->ElementType.get();
    dev.arr.add(elemType);
  }
  void Do(TTypeArray*p)
  {
    TType*elemType=p->ElementType.get();
    dev.arr.add(elemType);
  }
  void Do(TTypeAutoPtr*p)
  {
    TType*elemType=p->ElementType.get();
    dev.add_impls(elemType);
    dev.arr.add(elemType);
  }
  void Do(TTypeSelfPtr*p){QapDebugMsg("no way");}
  void Do(TTypeWeakPtr*p){QapDebugMsg("no way");}
  void Do(TTypeHardPtr*p){QapDebugMsg("no way");}
  void Do(TTypeVoidPtr*p){QapDebugMsg("no way");}
  void Do(TTypeFieldPtr*p){QapDebugMsg("no way");}
};

struct t_depends_solver{
  IEnvRTTI&Env;
  unique_arr impls;
  unique_arr interfaces;
  void add_depends_for(const string&type){
    auto*pType=find_ttype(Env,type);
    QapAssert(pType);
    TFooBarDev dev={Env};
    TFooBarBaz baz(dev);
    dev.arr.add(pType);
    auto&arr=dev.arr.arr;
    int count=0;
    for(int iter=0;arr.size()!=count;iter++){
      int prevcount=count;
      count=arr.size();
      for(int i=prevcount;i<count;i++){
        arr[i]->Use(baz);
      }
    }
    unique_ptr_arr<TTypeStruct> subs;
    for(int i=0;i<arr.size();i++){
      auto*ex=arr[i];
      auto*p=TTypeStruct::UberCast(ex);
      if(!p)continue;
      auto*parent=TTypeStruct::UberCast(p->SubType.get());
      if(!parent)continue;
      subs.add(parent);
    }
    for(int i=0;i<arr.size();i++){
      auto*ex=arr[i];
      auto*p=TTypeStruct::UberCast(ex);
      if(!p)continue;
      string fn=p->GetFullName();
      if(subs.find_ptr(p)){
        interfaces.add(fn);
        continue;
      }
      impls.add(fn);
    }
  }
};

string get_base_type(IEnvRTTI&Env,const string&type){
  auto&arr=Env.GetArr();
  auto*p=find_ttypestruct(Env,type);
  if(!p)return "";
  if(!p->SubType)return "";
  return p->SubType->GetFullName();
}

typedef TVoidPtr::TRawPtr TRawPtr;

class t_data_dev;
class t_json_dev;
class t_conv_dev;

struct i_type_dev{
  struct i_cmd{};
  #define IMPL_DEF(DEV,TYPE)\
  struct TYPE:public i_cmd{\
    typedef DEV t_dev;\
    DEV&dev;\
    TYPE(DEV&dev):dev(dev){init<0>();}\
   ~TYPE(){free<0>();}\
    template<int>void init(){dev.push(*this);}\
    template<int>void free(){dev.pop(*this);}\
  };
  #define IMPL_INT(DEV,TYPE)\
  struct TYPE:public i_cmd{\
    typedef DEV t_dev;\
    DEV&dev;\
    int id;\
    TYPE(DEV&dev,int id):dev(dev),id(id){init<0>();}\
   ~TYPE(){free<0>();}\
    template<int>void init(){dev.push(*this);}\
    template<int>void free(){dev.pop(*this);}\
  };
  //<LIST>
  IMPL_DEF(t_conv_dev,t_chunk);
  IMPL_DEF(t_conv_dev,t_chunk_type);
  IMPL_DEF(t_conv_dev,t_subtype);
  IMPL_INT(t_conv_dev,t_field);
  IMPL_INT(t_conv_dev,t_vec_id);
  IMPL_INT(t_conv_dev,t_arr_id);
  //</LIST>
  #undef IMPL_INT
  #undef IMPL_DEF
public:
  #define F(TYPE)typedef t_json_tree::TYPE TYPE;
  F(t_bool)F(t_null)F(t_string)F(t_number)F(t_array)F(t_pair)F(t_object)F(i_value)
  #undef F
public:
  struct t_ptr_builder{
    IEnvRTTI&Env;
    TRawPtr&ptr;
    TAutoPtr<i_value>&ref;
    void build(TType*pType)
    {
      if(TTypeSys::UberCast(pType))
      {
        string type=pType->GetFullName();
        #define F(TYPE,JSON_TYPE)if(#TYPE==type){\
          ptr.pType=Sys$$<JSON_TYPE>::GetRTTI(Env);\
          ptr.pValue=ref.build<JSON_TYPE>(Env);\
          return;\
        }
        //BEG
        F(int,t_number);
        F(string,t_string);
        F(bool,t_bool);
        F(char,t_string);
        //END
        #undef F
        QapDebugMsg(type+" - is under construction");
        return;
      }
      #define F(META_TYPE,JSON_TYPE)if(META_TYPE::UberCast(pType)){\
        ptr.pType=Sys$$<JSON_TYPE>::GetRTTI(Env);\
        ptr.pValue=ref.build<JSON_TYPE>(Env);\
        return;\
      }
      //BEG
      F(TTypeStruct,t_object);
      F(TTypeAutoPtr,t_array);
      F(TTypeArray,t_array);
      F(TTypeVector,t_array);
      //END
      #undef F
      string type=pType->GetFullName();
      QapDebugMsg(type+" - type is under construction");
      return;
    }
  };
};

struct t_data_dev:public i_type_dev{
public:
  struct t_rec{
    TRawPtr ptr;
    i_cmd*next;
  };
public:
  TRawPtr ptr;
  vector<t_rec> stack;
public:
  void internal_push(i_cmd&ref){
    t_rec tmp={ptr,&ref};
    stack.push_back(tmp);
  }
public:
  void push(t_subtype&ref)
  {
    QapAssert(ptr.IsValid());
    auto*pType=TTypeStruct::UberCast(ptr.pType);
    QapAssert(pType);
    auto*pSubType=pType->SubType.get();
    QapAssert(pSubType);
    QapAssert(TTypeStruct::UberCast(pSubType));
    internal_push(ref);
    ptr.pType=pSubType;
  }
  void push(t_field&ref)
  {
    QapAssert(ptr.IsValid());
    auto*pType=TTypeStruct::UberCast(ptr.pType);
    QapAssert(pType);
    auto&arr=pType->Members;
    QapAssert(ref.id>=0);
    QapAssert(ref.id<arr.size());
    auto&field=arr[ref.id];
    internal_push(ref);
    ptr.pType=field.Type.get();
    ptr.pValue=field.getValue(ptr.pValue);
  }
  void push(t_chunk&ref)
  {
    QapAssert(ptr.IsValid());
    auto*pType=TTypeAutoPtr::UberCast(ptr.pType);
    QapAssert(pType);
    auto*elemType=pType->ElementType.get();
    auto&value=*(TAutoPtr<void>*)ptr.pValue;
    auto*pNextType=value.Product.pType.get();
    QapAssert(value);
    QapAssert(pNextType);
    QapAssert(pNextType->IsBasedOn(elemType));
    internal_push(ref);
    ptr.pType=pNextType;
    ptr.pValue=value.get();
  }
  void push(t_arr_id&ref)
  {
    QapAssert(ptr.IsValid());
    auto*pType=TTypeArray::UberCast(ptr.pType);
    QapAssert(pType);
    auto*elemType=pType->ElementType.get();
    auto elemSize=elemType->Info.Size;
    auto Count=pType->Size;
    QapAssert(elemType);
    QapAssert(Count>0);
    QapAssert(elemSize>0);
    QapAssert(ref.id>=0);
    QapAssert(ref.id<Count);
    internal_push(ref);
    ptr.pType=elemType;
    ptr.pValue=&((uchar*)ptr.pValue)[elemSize*ref.id];
  }
  void push(t_vec_id&ref)
  {
    QapAssert(ptr.IsValid());
    auto*pType=TTypeVector::UberCast(ptr.pType);
    QapAssert(pType);
    auto*elemType=pType->ElementType.get();
    auto*VecAPI=pType->VecAPI.get();
    auto Count=VecAPI->GetCount(ptr.pValue);
    QapAssert(elemType);
    QapAssert(Count>0);
    QapAssert(ref.id>=0);
    QapAssert(ref.id<Count);
    internal_push(ref);
    ptr.pType=elemType;
    ptr.pValue=VecAPI->GetItem(ptr.pValue,ref.id);
  }
  void push(t_chunk_type&ref)
  {
    //also we can nothing to do, but for synchronize stack in memdev and tardev we must do this:
    internal_push(ref);
  }
  void pop(i_cmd&ref)
  {
    QapAssert(!stack.empty());
    {
      auto&back=stack.back();
      auto*ptr_a=back.next;
      auto*ptr_b=&ref;
      QapAssert(ptr_a==ptr_b);
      ptr=std::move(back.ptr);
      back.ptr.setZero();
      back.next=nullptr;
    }
    stack.pop_back();
  }
public:
  template<class TYPE>
  TYPE*get(){return (TYPE*)ptr.pValue;}
};

struct t_json_dev:public i_type_dev{
public:
  struct t_rec{
    TRawPtr ptr;
    i_cmd*next;
  };
public:
  TRawPtr ptr;
  vector<t_rec> stack;
  //TAutoPtr<t_json_tree::i_value> root;
  IEnvRTTI&Env;
  t_json_dev(IEnvRTTI&Env):Env(Env){}
public:
  template<class TYPE>
  void check(){
    QapAssert(Sys$$<TYPE>::GetRTTI(Env)==ptr.pType);
  }
public:
  void internal_push(i_cmd&ref){
    t_rec tmp={ptr,&ref};
    stack.push_back(tmp);
  }
public:
  void push(...){QapDebugMsg("not work. by design");}
  //void push(t_chunk_type&ref){}
  void pop(i_cmd&ref)
  {
    QapAssert(!stack.empty());
    {
      auto&back=stack.back();
      QapAssert(back.next==&ref);
      ptr=std::move(back.ptr);
      back.ptr.setZero();
      back.next=nullptr;
    }
    stack.pop_back();
  }
public:
  template<class TYPE>
  TYPE*get()
  {
    check<TYPE>();
    return (TYPE*)ptr.pValue;
  }
};

struct t_conv_dev:public i_type_dev{
public:
  IEnvRTTI&Env;
  bool load_mode;
  bool save_mode;
  t_json_dev memdev;
  t_data_dev tardev;
  t_conv_dev(IEnvRTTI&Env,bool load_mode):Env(Env),load_mode(load_mode),save_mode(!load_mode),memdev(Env){}
public:
  void push(...){}
  void pop(i_cmd&ref){
    tardev.pop(ref);
    memdev.pop(ref);
  }
public:
  void push(t_subtype&ref)
  {
    tardev.push(ref);
    memdev.internal_push(ref);
    //GP
    string fn=Str2Json(tardev.ptr.pType->GetFullName());
    auto*pObject=memdev.get<t_object>();
    QapAssert(pObject);
    //ST
    if(save_mode)
    {
      auto&pair=pObject->add_pair(fn);
      memdev.ptr.pValue=pair.value.build<t_object>(Env);
      memdev.ptr.pType=Sys$$<t_object>::GetRTTI(Env);
    }
    //LT
    if(load_mode)
    {
      auto&pair=pObject->find_pair(fn);
      memdev.ptr.pValue=&pair.value;
    }
  }
  void push(t_field&ref)
  {
    auto*pType=TTypeStruct::UberCast(tardev.ptr.pType);
    tardev.push(ref);
    memdev.internal_push(ref);
    //GP
    auto*pObject=memdev.get<t_object>();
    QapAssert(pObject);
    auto*pFieldType=pType->Members[ref.id].Type.get();
    QapAssert(pFieldType);
    const string&field_name=Str2Json(pType->Members[ref.id].Name);
    //ST
    if(save_mode)
    {
      auto&pair=pObject->add_pair(field_name);
      t_ptr_builder builder={Env,memdev.ptr,pair.value};
      builder.build(tardev.ptr.pType);
    }
    //LT
    if(load_mode)
    {
      auto*pValue=memdev.get<t_object>();
      QapAssert(pValue);
      auto&pair=pValue->find_pair(field_name);
      QapAssert(pair.value);
      QapAssert(pair.value.Product.pType->IsBasedOn(Sys$$<i_value>::GetRTTI(Env)));
      memdev.ptr.pType=pair.value.Product.pType.get();
      memdev.ptr.pValue=pair.value.get();
    }
  }
  void push(t_arr_id&ref)
  {
    tardev.push(ref);
    memdev.internal_push(ref);
    //GP
    string fn=tardev.ptr.pType->GetFullName();
    auto*pArray=memdev.get<t_array>();
    QapAssert(pArray);
    //ST
    if(save_mode)
    {
      auto&arr=pArray->arr;
      QapAssert(ref.id<arr.size());
      QapAssert(ref.id>=0);
      auto&item=pArray->arr[ref.id];
      QapAssert(!item);
      t_ptr_builder builder={Env,memdev.ptr,item};
      builder.build(tardev.ptr.pType);
      QapAssert(item);
    }
    //LT
    if(load_mode)
    {
      auto&item=pArray->arr[ref.id];
      QapAssert(item);
      QapAssert(item.Product.pType->IsBasedOn(Sys$$<i_value>::GetRTTI(Env)));
      memdev.ptr.pType=item.Product.pType.get();
      memdev.ptr.pValue=item.get();
    }
  }
  void push(t_vec_id&ref)
  {
    tardev.push(ref);
    memdev.internal_push(ref);
    //GP
    /*this is copy-past*/string fn=tardev.ptr.pType->GetFullName();
    /*this is copy-past*/auto*pArray=memdev.get<t_array>();
    /*this is copy-past*/QapAssert(pArray);
    /*this is copy-past*///ST
    /*this is copy-past*/if(save_mode)
    /*this is copy-past*/{
    /*this is copy-past*/  auto&arr=pArray->arr;
    /*this is copy-past*/  QapAssert(ref.id<arr.size());
    /*this is copy-past*/  QapAssert(ref.id>=0);
    /*this is copy-past*/  auto&item=pArray->arr[ref.id];
    /*this is copy-past*/  QapAssert(!item);
    /*this is copy-past*/  t_ptr_builder builder={Env,memdev.ptr,item};
    /*this is copy-past*/  builder.build(tardev.ptr.pType);
    /*this is copy-past*/  QapAssert(item);
    /*this is copy-past*/}
    /*this is copy-past*///LT
    /*this is copy-past*/if(load_mode)
    /*this is copy-past*/{
    /*this is copy-past*/  auto&item=pArray->arr[ref.id];
    /*this is copy-past*/  QapAssert(item);
    /*this is copy-past*/  QapAssert(item.Product.pType->IsBasedOn(Sys$$<i_value>::GetRTTI(Env)));
    /*this is copy-past*/  memdev.ptr.pType=item.Product.pType.get();
    /*this is copy-past*/  memdev.ptr.pValue=item.get();
    /*this is copy-past*/}
  }
  void push(t_chunk&ref)
  {
    tardev.push(ref);
    memdev.internal_push(ref);
    //GP
    auto*pValue=memdev.get<t_array>();
    auto&arr=pValue->arr;
    QapAssert(arr.size()==2);
    auto&value=arr[1];
    //ST
    if(save_mode)
    {
      QapAssert(!value);
      t_ptr_builder builder={Env,memdev.ptr,value};
      builder.build(tardev.ptr.pType);
      QapAssert(value);
    }
    //LT
    if(load_mode)
    {
      QapAssert(value);
      memdev.ptr.pType=value.Product.pType.get();
      memdev.ptr.pValue=value.get();
    }
  }
  void push(t_chunk_type&ref)
  {
    tardev.push(ref);
    memdev.internal_push(ref);
    //GP
    auto*pValue=memdev.get<t_array>();
    auto&arr=pValue->arr;
    QapAssert(arr.size()==2);
    auto&value=arr[0];
    //ST
    if(save_mode)
    {
      QapAssert(!value);
      memdev.ptr.pValue=value.build<t_string>(Env);
      memdev.ptr.pType=value.Product.pType.get();
      QapAssert(value);
    }
    //LT
    if(load_mode)
    {
      QapAssert(value);
      QapAssert(value.Product.pType->IsBasedOn(Sys$$<t_string>::GetRTTI(Env)));
      memdev.ptr.pType=value.Product.pType.get();
      memdev.ptr.pValue=value.get();
    }
  }
public:
  TType*find_type(const string&fn){
    return find_ttype(Env,fn);
  }
};

class TJsonVisitor:public IVisitorRTTI{
public:
  typedef TFooBarBaz SelfClass;
  typedef t_conv_dev TDevClass;
public:
  TDevClass&dev;
  TJsonVisitor(TDevClass&dev):dev(dev){}
  //TFooBarBaz(SelfClass&owner):dev(owner.dev){}
public:
  #define F(TYPE)typedef t_json_tree::TYPE TYPE;
  F(t_bool)F(t_null)F(t_string)F(t_number)F(t_array)F(t_pair)F(t_object)
  #undef F
public:
  template<class TYPE>
  void check_value(...){};
public:
  void Do(TTypeStruct*p)
  {
    check_value<t_object>();
    if(p->SubType)
    {
      TDevClass::t_subtype cmd(dev);
      auto*pSubType=p->SubType.get();
      pSubType->Use(*this);
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      TDevClass::t_field cmd(dev,i);
      ex.Type->Use(*this);
    }
  }
  void Do(TTypeSys*p)
  {
    auto fn=p->GetFullName();
    if(fn=="string")
    {
      auto*pValue=dev.memdev.get<t_string>();
      auto&value=*(string*)dev.tardev.ptr.pValue;
      //ST
      if(dev.save_mode)
      {
        pValue->body=Str2Json(value);
      }
      //LT
      if(dev.load_mode)
      {
        value=Json2Str(pValue->body);
      }
      return;
    }
    if(fn=="bool")
    {
      auto*pValue=dev.memdev.get<t_bool>();
      auto&value=*(bool*)dev.tardev.ptr.pValue;
      //ST
      if(dev.save_mode)
      {
        pValue->value=BToS(value);
      }
      //LT
      if(dev.load_mode)
      {
        bool ok=SToB(pValue->value,value);
        QapAssert(ok);
      }
      //GP
      return;
    }
    if(fn=="int")
    {
      auto*pValue=dev.memdev.get<t_number>();
      auto&value=*(int*)dev.tardev.ptr.pValue;
      //ST
      if(dev.save_mode)
      {
        pValue->body=IToS(value);
      }
      //LT
      if(dev.load_mode)
      {
        value=SToI(pValue->body);
      }
      //GP
      return;
    }
    if(fn=="char")
    {
      auto*pValue=dev.memdev.get<t_string>();
      auto&value=*(char*)dev.tardev.ptr.pValue;
      //ST
      if(dev.save_mode)
      {
        pValue->body=Str2Json(CToS(value));
      }
      //LT
      if(dev.load_mode)
      {
        SToC(Json2Str(pValue->body),value);
      }
      //GP
      return;
    }
    QapDebugMsg("[TTypeSys]: under construction");
  }
  void Do(TTypeVector*p)
  {
    check_value<t_array>();
    //GP
    auto*pArr=(t_array*)dev.memdev.ptr.pValue;
    void*pValue=dev.tardev.ptr.pValue;
    auto*VecAPI=p->VecAPI.get();
    size_t Count=0;
    //ST
    if(dev.save_mode)
    {
      Count=VecAPI->GetCount(pValue);
      pArr->arr.resize(Count);
    }
    //LT
    if(dev.load_mode)
    {
      Count=pArr->arr.size();
      VecAPI->SetCount(pValue,Count);
    }
    //GP
    auto*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++)
    {
      TDevClass::t_vec_id cmd(dev,i);
      elemType->Use(*this);
    }
  }
  void Do(TTypeArray*p)
  {
    check_value<t_array>();
    auto*pArr=(t_array*)dev.memdev.ptr.pValue;
    TType*elemType=p->ElementType.get();
    const auto&Count=p->Size;
    //ST
    if(dev.save_mode)
    {
      pArr->arr.resize(Count);
    }
    //LT
    if(dev.load_mode)
    {
      QapAssert(pArr->arr.size()==Count);
    }
    //GP
    for(int i=0;i<Count;i++)
    {
      TDevClass::t_arr_id cmd(dev,i);
      elemType->Use(*this);
    }
  }
  void Do(TTypeAutoPtr*p)
  {
    static const size_t JsonArrSize=2;
    auto&value=*(TAutoPtr<void>*)dev.tardev.ptr.pValue;
    {
      check_value<t_array>();
      auto*pValue=dev.memdev.get<t_array>();
      //ST
      if(dev.save_mode)
      {
        pValue->arr.resize(value?JsonArrSize:0);
        if(!value)return;
      }
      //LT
      if(dev.load_mode)
      {
        auto size=pValue->arr.size();
        if(!size){
          value=nullptr;
          return;
        }
        QapAssert(size==JsonArrSize);
      }
      //GP
    }
    {
      TDevClass::t_chunk_type cmd(dev);
      check_value<t_string>();
      //GP
      TType*elemType=p->ElementType.get();
      string basetype=elemType->GetFullName();
      auto&str=dev.memdev.get<t_string>()->body;
      auto&pType=value.Product.pType;
      //ST
      if(dev.save_mode)
      {
        auto&out=str;
        QapAssert(pType->IsBasedOn(elemType));
        out=Str2Json(pType->GetFullName());
      }
      //LT
      if(dev.load_mode)
      {
        auto inp=Json2Str(str);
        pType=dev.find_type(inp);
        if(!pType){
          QapDebugMsg(Str2Json(inp)+" is unknow type");
          return;
        }
        bool flag=pType->IsBasedOn(elemType);
        if(!flag){
          string msg=(
            "type A is not based on type B:\nwhere:\n"
            "A ="+Str2Json(pType->GetFullName())+"\n"
            "B = "+Str2Json(elemType->GetFullName())
          );
          QapDebugMsg(msg);
          return;
        }
        //QapAssert(pType->IsBasedOn(elemType));
        value.Product.Init();
      }
      //GP
    }
    auto*pType=value.Product.pType.get();
    TDevClass::t_chunk chunk(dev);
    pType->Use(*this);
  }
public:

public:
  void Do(TTypeSelfPtr*p){QapDebugMsg("no way");}
  void Do(TTypeWeakPtr*p){QapDebugMsg("no way");}
  void Do(TTypeHardPtr*p){QapDebugMsg("no way");}
  void Do(TTypeVoidPtr*p){QapDebugMsg("no way");}
  void Do(TTypeFieldPtr*p){QapDebugMsg("no way");}
};

string test20131204_chat_json(IEnvRTTI&Env,TVoidPtr::TRawPtr&ptr){
  t_json_tree::t_object json_object;
  t_conv_dev dev(Env,false);
  dev.memdev.ptr.set(Env,json_object);
  dev.tardev.ptr=std::move(ptr);
  TJsonVisitor V(dev);
  dev.tardev.ptr.pType->Use(V);
  string json_out;
  t_json_tree::t_save_dev save_dev(json_out,true);
  t_json_tree::t_visitor JsV(save_dev);
  json_object.Use(JsV);
  //vector<string> out;
  //out.push_back("time:"+cur_date_str());
  //out.push_back(toJsStr::fromStr(json_out));
  return json_out;
}

class T20131202_X{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131202_X)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,x,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131202_X
#include "QapGenStruct.inl"
//<<<<<+=====T20131202_X
public:
};

class T20131203_Y:public T20131202_X{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131203_Y)PARENT(T20131202_X)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,y,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131203_Y
#include "QapGenStruct.inl"
//<<<<<+=====T20131203_Y
public:
};

class T20131202_Test{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131202_Test)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,int,number,SET,0,$)\
ADDVAR(2,TAutoPtr<T20131202_Test>,next,DEF,$,$)\
ADDVAR(4,TAutoPtr<T20131202_X>,junk,DEF,$,$)\
ADDVAR(5,vector<T20131202_Test>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131202_Test
#include "QapGenStruct.inl"
//<<<<<+=====T20131202_Test
public:
  void init(IEnvRTTI&Env){
    name="def name";
    number=2013;
    next.build<T20131202_Test>(Env)->name="sad but true";
    arr.push_back(T20131202_Test());
    arr.back().name="first";
    arr.back().number=571;
    arr.back().junk.build<T20131202_X>(Env)->x="ho-ho!!!";
    arr.push_back(T20131202_Test());
    arr.back().name="second";
    arr.back().junk.build<T20131203_Y>(Env)->y="\":)'\"";
  }
};

template<class TYPE>
void load_obj_from_json(IEnvRTTI&Env,const string&json_text,TYPE&ref)
{
  TAutoPtr<t_json_tree::i_value> json_value;
  {
    TAutoPtr<t_json::i_value> value;
    string ok=load_obj_ex(Env,value,json_text);
    QapAssert(value);
    t_json_tree::clone(Env,json_value,value);
    int gg=1;
  }
  auto&json_object=[&]()->t_json_tree::t_object&
  {
    auto*p=t_json_tree::i_visitor::UberCast<t_json_tree::t_object>(json_value.get());
    QapAssert(p);
    return *p;
  }();
  {
    t_conv_dev dev(Env,true);
    dev.memdev.ptr.set(Env,json_object);
    dev.tardev.ptr.set(Env,ref);
    TJsonVisitor V(dev);
    dev.tardev.ptr.pType->Use(V);
  }
}

template<class TYPE>
void save_obj_to_json(IEnvRTTI&Env,string&json_out,TYPE&ref)
{
  t_json_tree::t_object json_object;
  t_conv_dev dev(Env,false);
  dev.memdev.ptr.set(Env,json_object);
  dev.tardev.ptr.set(Env,ref);
  TJsonVisitor V(dev);
  dev.tardev.ptr.pType->Use(V);
  t_json_tree::t_save_dev save_dev(json_out,true);
  t_json_tree::t_visitor JsV(save_dev);
  json_object.Use(JsV);
}

string type2lexdef(TTypeStruct*p){
  vector<string> out;
  auto&arr=p->Members;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    string type=ex.Type->GetFullName();
    string name=ex.Name;
    string value=ex.Mode=="DEF"?"":ex.Value;
    string line="  "+type+" "+name+(value.empty()?"":"="+value)+";";
    out.push_back(line);
  }
  auto*pSubType=p->SubType.get();
  return (
    p->GetFullName()+
    (pSubType?"=>"+pSubType->GetFullName():"")+
    (out.empty()?"{}":"{\n"+join(out,"\n")+"\n}")
  );
}

string depends2lexdef(IEnvRTTI&Env,const string&type){
  auto*pType=find_ttypestruct(Env,type);
  if(!pType)return "type - "+Str2Json(type)+" not found";
  t_depends_solver solver={Env};
  solver.add_depends_for(type);
  auto&arr=solver.impls.arr;
  vector<string> out;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto*p=find_ttypestruct(Env,ex);
    if(!p)continue;
    string buff=type2lexdef(p);
    out.push_back(buff);
  }
  return join(out,"\n");
}

string test2013_func(IEnvRTTI&Env,const string&param){
  //Sys$$<t_json_tree>::GetRTTI(Env);
  auto&arr=Env.GetArr();
  int offset=0;
  auto f=[&param,&offset](const string&name)->bool{
    string all="(?"+name+"\"";// (?name"...")
    offset=all.size();
    return param.find(all)==0;
  };
  if(f("depends2lexdef")){
    string code=param.substr(offset,param.size()-2-offset);
    vector<string> out;
    out.push_back(depends2lexdef(Env,code));
    return vector_to_json_array_ex(out,"value");
  }
  if(f("json_load")){
    string json_text=load_file("json_load.js");
    {
      auto&arr=json_text;
      string out;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex=='\r')continue;
        out.push_back(ex);
      }
      json_text=out;
    }
    T20131202_Test test_var;
    load_obj_from_json(Env,json_text,test_var);
    string json_out;
    save_obj_to_json(Env,json_out,test_var);
    vector<string> out;
    //out.push_back("time:"+cur_date_str());
    bool flag=json_out==json_text;
    if(!flag){
      two_text_diff(json_out,json_text);
    }
    out.push_back(BToS(flag));
    out.push_back(json_out);
    return vector_to_json_array_ex(out,"value");
  }
  if(f("2013.12.03")){
    T20131202_Test test_var;
    t_json_tree::t_object json_object;
    test_var.init(Env);
    t_conv_dev dev(Env,false);
    dev.memdev.ptr.set(Env,json_object);
    dev.tardev.ptr.set(Env,test_var);
    TJsonVisitor V(dev);
    dev.tardev.ptr.pType->Use(V);
    string json_out;
    t_json_tree::t_save_dev save_dev(json_out,true);
    t_json_tree::t_visitor JsV(save_dev);
    json_object.Use(JsV);
    vector<string> out;
    out.push_back("time:"+cur_date_str());
    out.push_back(toJsStr::fromStr(json_out));
    return vector_to_json_array(out,"value");
  }
  if(f("2013.12.02")){
    T20131202_Test test_var;
    t_json_tree::t_object json_object;
    test_var.init(Env);
    t_conv_dev dev(Env,false);
    dev.memdev.ptr.set(Env,json_object);
    dev.tardev.ptr.set(Env,test_var);
    TJsonVisitor V(dev);
    dev.tardev.ptr.pType->Use(V);
    vector<string> out;
    out.push_back("time:"+cur_date_str());
    string raw=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(json_object));
    out.push_back(toJsStr::fromStr(raw));
    return vector_to_json_array(out,"value");
    //return "ok. goto next setep.";
  }
  if(f("rtti2json")){
    string code=param.substr(offset,param.size()-2-offset);
    t_depends_solver solver={Env};
    solver.add_depends_for(code);
    vector<string> meta;
    {
      vector<string> out;
      auto&arr=solver.impls.arr;
      for(int i=0;i<arr.size();i++){out.push_back(type2json_pair(Env,arr[i]));}
      meta.push_back("\"typelist\":{"+join(out,",\n")+"}");
    }
    {
      vector<string> out;
      auto&arr=solver.impls.arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto base=get_base_type(Env,ex);
        if(base.empty())continue;
        out.push_back(Str2Json(ex)+":"+Str2Json(base));
      }
      meta.push_back("\"interfaces\":{"+join(out,",\n")+"}");
      meta.push_back("\"convertors\":{}");
    }
    return (
      "{"+Str2Json("meta")+":{\n"+join(meta,",\n")+"\n},\n"+
      Str2Json("data")+":{\n  "+Str2Json("type")+":\""+code+"\",\n  "+Str2Json("value")+":[]\n}\n}"
    );
  }
  if(f("all_depends")){
    string code=param.substr(offset,param.size()-2-offset);
    t_depends_solver solver={Env};
    solver.add_depends_for(code);
    //vector<string> out;
    //for(int i=0;i<arr.size();i++){out.push_back(Str2Json(arr[i]));}
    return vector_to_json_array(solver.impls.arr,"types");
  }
  if(f("type2json")){
    string code=param.substr(offset,param.size()-2-offset);
    return "{"+type2json_pair(Env,code)+"}";
  }
  if(f("impls")){
    string code=param.substr(offset,param.size()-2-offset);
    vector<string> out=get_impls(Env,code);
    return vector_to_json_array(out,"value");
  }
  if(param.find("\"")==0){
    BinString bin=param.substr(1,param.size()-2);
    TAutoPtr<t_json::i_value> obj;/*
    t_load_dev dev(Env,param);*/
    bool ok=load_obj(Env,obj,bin.data);
    TAutoPtr<t_json_tree::i_value> view_obj;
    t_json_tree::clone(Env,view_obj,obj);
    vector<string> out;
    out.push_back("result:"+BToS(ok));
    string raw=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(view_obj));
    out.push_back(toJsStr::fromStr(raw));
    return vector_to_json_array(out,"value");
  }
  if(param=="(?subtypes)"){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      auto*psub=TTypeStruct::UberCast(p->SubType.get());
      if(!psub)continue;
      string fn=psub->GetFullName();
      auto find=[&fn,&out]()->bool{for(int i=0;i<out.size();i++)if(out[i]==fn)return true;return false;};
      if(find())continue;
      out.push_back(fn);
    }
    return vector_to_json_array(out,"SubType");
  }
  if(param=="?"){
    vector<string> out;
    for(int i=0;i<arr.size();i++)out.push_back(arr[i].Type->GetFullName());
    return vector_to_json_array(out,"Name");
  }
  if(param=="(?outerclasses)"){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      if(p->Nesteds.empty())continue;
      out.push_back(arr[i].Type->GetFullName());
    }
    return vector_to_json_array(out,"Name");
  }
  if(param=="(?check)"){
    vector<vector<string>> nested;nested.resize(arr.size());
    vector<vector<string>> two;two.resize(arr.size());
    vector<string> errors;
    for(int i=0;i<arr.size();i++){
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      auto&out=nested[i];
      out.resize(p->Nesteds.size());
      for(int i=0;i<out.size();i++){
        string name=p->Nesteds[i]->GetFullName();
        out[i]=name;
        for(int j=0;j<i;j++){
          QapAssert(out[j]!=name);
        }
      }
    }
    for(int i=0;i<arr.size();i++){
      auto*p=TTypeStruct::UberCast(arr[i].Type.get());
      if(!p)continue;
      if(!p->OwnType)continue;
      auto type=p->GetFullName();
      auto*pOwnType=p->OwnType.get();
      auto fn=pOwnType->GetFullName();
      for(int i=0;i<arr.size();i++){
        if(arr[i].Type->GetFullName()!=fn)continue;
        auto&out=two[i];
        auto&nes=nested[i];
        int id=-1;
        for(int j=0;j<nes.size();j++){
          if(nes[j]!=type)continue;
          QapAssert(id<0);
          id=j;
        }
        if(id<0){
          errors.push_back(type);continue;
        }
        QapAssert(id>=0);
        out.resize(std::max<int>(out.size(),id+1));
        out[id]=type;
      }
    }
    QapAssert(two==nested);
    return vector_to_json_array(errors,"Name");
  }
  if(param.empty())return "param.empty() == true";
  for(int i=0;i<arr.size();i++){
    auto*p=TTypeStruct::UberCast(arr[i].Type.get());
    if(!p)continue;
    if(p->GetFullName()!=param)continue;
    vector<string> out;
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      vector<string> item;
      #define F(KEY,VALUE){CppString cpp=VALUE;item.push_back(Str2Json(#KEY)+":"+Str2Json(cpp.data));}
      F(Number,IToS(ex.Number));
      F(Type,ex.Type->GetFullName());
      F(Name,ex.Name);
      F(Mode,ex.Mode);
      F(Value,ex.Value);
      F(Offset,IToS(ex.Offset));
      #undef F
      out.push_back("{"+join(item,",")+"}");
    }
    return "["+join(out,",\n")+"]";
  }
  return "param not found:\n"+param;
}

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)\
        F(t_json)\
        F(t_json_tree)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){}
  };
  ThisCompileUnit ThisUnit;
}
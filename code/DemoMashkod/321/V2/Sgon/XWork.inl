
std::string quot="\"";
std::string text="text";
std::string backslash="\\";

std::string input=quot+"text"+quot+"\n";
std::string output=backslash+quot+"text"+backslash+quot+backslash+"n";

std::string input=quot+"text"+quot+"\n";
std::string output=backslash+quot+"text"+backslash+quot+backslash+"n";

было:
ADDVAR(0,int,x,SET,0,$)\
ADDVAR(1,int,y,SET,0,$)\

стало:
ADDVAR(0,int,x,SET,0,$)\
ADDVAR(1,int,y,SET,0,$)\
ADDVAR(2,int,z,SET,0,$)\

class Comp{
public:
  vector<Member> Members;
public:
  void Do()
  {
    
  }
};

надо сделать объект который будет эмулировать старую версию структуры.

надо сделать дополнительный виртуальный коструктор в каждой фабрике.

надо сделать хранить внутри фабрики дополнительный конструктор объекта вызывающий DoReset().

class IFactory{
public:
  virtual void Init(IAllocator*pAlloc,TMemory&)=0;
  virtual void Free(IAllocator*pAlloc,TMemory&)=0;
public:
  virtual TType*GetElementType(IEnvRTTI&Env)=0;
  virtual TType*GetMetaType(IEnvRTTI&Env)=0;
public:
  virtual int GetSize()=0;
  virtual void UnsafeInit(TMemory&)=0;
  virtual void UnsafeFree(TMemory&)=0;
};

class TDynFactory:public IFactory{
public:
  THardPtr<TTypeStruct> pType;
public:
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    int offset=0;
    if(subtype)
    {
      auto&ft=subtype->Factory.get();
      int size=ft->GetSize();
      TMemory Mem;
      Mem.ptr=(void*)(int(ptr)+offset);
      Mem.size=size;
      ft->UnsafeInit(Mem);
      offset+=size;
    }
    auto&arr=type->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&ft=ex.Type->Factory.get();
      int size+=ft->GetSize();
      TMemory Mem;
      Mem.ptr=(void*)(int(ptr)+offset);
      Mem.size=size;
      ex.Type->Factory->UnsafeInit(Mem);
      offset+=size;
    }
  }
  void Destroy(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    int offset=0;
    int subtype_size=0;
    if(subtype)
    {
      int size=subtype->GetSize();
      offset+=size;
      //TMemory Mem;
      //Mem.ptr=(void*)(int(ptr)+offset);
      //Mem.size=size;
      //ft->UnsafeInit(Mem);
      //offset+=size;
    }
    auto&arr=type->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&ft=ex.Type->Factory.get();
      int size+=ft->GetSize();
      offset+=size;
      //TMemory Mem;
      //Mem.ptr=(void*)(int(ptr)+offset);
      //Mem.size=size;
      //ex.Type->Factory->UnsafeFree(Mem);
      //offset+=size;
    }
    for(int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ex=arr[i];
      auto&ft=ex.Type->Factory.get();
      int size+=ft->GetSize();
      offset-=size;
      TMemory Mem;
      Mem.ptr=(void*)(int(ptr)+offset);
      Mem.size=size;
      ex.Type->Factory->UnsafeFree(Mem);
    }
    if(subtype)
    {
      auto&ft=subtype->Factory.get();
      int size=subtype->GetSize();
      offset-=size;
      TMemory Mem;
      Mem.ptr=(void*)(int(ptr)+offset);
      Mem.size=subtype_size;
      ex.Type->ft->UnsafeFree(Mem);
    }
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  int GetSize(){
    auto*type=pType.get();
    auto&arr=type->Members;
    int size=0;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      size+=ex.Type->Factory->GetSize();
    }
    return size;
  }
  void UnsafeInit(TMemory&Mem){
    QapAssert(Mem.size==sizeof(TYPE)));
    Create(get(Mem.ptr));
  }
  void UnsafeFree(TMemory&Mem){
    QapAssert(Mem.size==sizeof(TYPE)));
    Free(get(Mem.ptr));
  }
};

template<class TYPE>
class TFactory:public IFactory{
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=sizeof(TYPE);
    pAlloc->Alloc(Mem);
    Create(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  int GetSize(){
    return sizeof(TYPE);
  }
  void UnsafeInit(TMemory&Mem){
    QapAssert(Mem.size==sizeof(TYPE)));
    Create(get(Mem.ptr));
  }
  void UnsafeFree(TMemory&Mem){
    QapAssert(Mem.size==sizeof(TYPE)));
    Free(get(Mem.ptr));
  }
};









ADDVAR(29,vector<Method>,Methods,DEF,$,$)\


class TMethod{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMethod)OWNER(TTypeStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,THardPtr<TType>,SubType,DEF,$,$)\
ADDVAR(1,THardPtr<TType>,OwnType,DEF,$,$)\
ADDVAR(2,vector<Member>,Members,DEF,$,$)\
ADDVAR(4,vector<THardPtr<TType>>,Nesteds,DEF,$,$)\
ADDVAR(5,TExtInfo,extInfo,DEF,$,$)\
ADDEND()
//=====+>>>>>TMethod
#include "QapGenStruct.inl"
//<<<<<+=====TMethod
public:
  
  
};









#define DEF_PRO_FULL
//-------------------------------------------//
#if(defined(_CSTDLIB_)||defined(_WINDOWS_))
  static_assert(false,"fail");
#endif
//-------------------------------------------//
#if(!defined(DEF_BUILD_MICRO)&&!defined(DEF_BUILD_MACRO)&&!defined(DEF_BUILD_DEFAULT))
  #define DEF_BUILD_DEFAULT
  //`MICRO - compile with key /P /EP /C
  //`MACRO - full compile
#endif
//-------------------------------------------//
#ifdef DEF_BUILD_MICRO
  #define _WINDOWS_
  #define _D3D9_H_
#else
  //#define NOMENUS
  //#define NOHELP
  #define NOMENUS
  #define NOHELP
  #define NOPROFILER
  #define NOKANJI
  #define NOWH
  #define NOSERVICE
  #define NOMINMAX
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
  #include <d3d9.h>
  #pragma comment(lib,"d3d9")
  #pragma comment(lib,"user32")
  #pragma comment(lib,"gdi32")
#endif //DEF_BUILD_MICRO//
//-------------------------------------------//
#define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCTION__))_CrtDbgBreak();}
#define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCTION__))_CrtDbgBreak();}
#define QapNoWay(){QapDebugMsg("no way!");}
#pragma once
#include "QapMicro\QapType.h"
#pragma once
using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::iostream;
using std::stringstream;
using std::array;
using std::unique_ptr;
typedef double real;
typedef INT64 int64;
typedef UINT64 uint64;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef vector<string> StringArray;
typedef vector<void*> PtrArray;
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
#pragma once
#include "QapMicro\QapIO.h"
#include "QapMicro\QapClock.h"
#pragma once

struct TScreenMode
{
  int W,H,BPP,Freq;
};
template<class TYPE>
inline static TYPE max(const TYPE&a,const TYPE&b)
{
  return a>b?a:b;
}
template<class TYPE>
inline static TYPE min(const TYPE&a,const TYPE&b)
{
  return a<b?a:b;
}
template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT])
{
  return COUNT;
}
int max(int a,int b);
int min(int a,int b);
float max(float a,float b);
float min(float a,float b);
double max(double a,double b);
double min(double a,double b);
template<typename TYPE>TYPE Sign(TYPE value)
{
  if (value>0)
  {
    return TYPE(+1);
  }
  else
  {
    return TYPE(value<0?-1:0);
  }
  ;
};
template<typename TYPE>bool InDip(TYPE min,TYPE val,TYPE max)
{
  return (val>=min)&&(val<=max);
}
;
TScreenMode GetScreenMode();
class CharMask
{
public:
  bool mask[256];
  CharMask(CharMask&&ref);
  CharMask();
public:
  static CharMask fromStr(const string&str);
public:
  template<size_t COUNT>
  explicit CharMask(const char(&allowed)[COUNT])
  {
    string str;
    str.resize(COUNT-1);
    for (int i=0;i<str.size();i++)str[i]=*(char*)(void*)&allowed[i];
    prepare(str);
    if (false)
    {
      string unallowed;
      for (int i=1;i<256;i++)if (!mask[i])unallowed.push_back(i);
      QapDebugMsg(unallowed);
    }
  }void prepare(const std::string&allowed);;
  bool check(const std::string&str)const;
  bool operator[](uchar index)const;
};
real RndReal(const real&min,const real&max);;
string CToS(const char&val);;
string IToS(const int&val);
string UCToS(const unsigned char&val);
string HToS(const int&val);
string IToSex(const int&val);
string FToS(const real&val);
string BToS(const bool&val);;
string IToH(const int&val);
string IToH(const int&val,int n);
string IToH_raw(const int&val);
char HToC(const string&str);
bool SToF(const string&str,real&val);
bool SToB(const string&str,bool&val);
bool SToB(const string&str);
bool SToC(const string&str,char&val);
bool HToI(const string&str,int&val);
int HToI(const string&str);
int HToI_raw(const string&str);
string CToH_raw(const unsigned char&val);
string SToS(const string&s);
template<size_t COUNT> inline string SToS(const char(&lzstr)[COUNT])
{
  static_assert(COUNT,"WTF?");
  return string(&lzstr[0],size_t(COUNT-1));
}
string SToSex(const string&S,const int&l);
int SToI(const string&S);;
int SToI_fast(const string&S);;
string GetFileName(const string&filename);
bool IsRawDirName(const std::string&dirname);
string RemoveFileExt(const string&FN);
string ChangeFileExt(const string&FN,const string&Ext);
string BackSlashesToSlashes(const string&data);
string ScanParam(const string&Before,const string&Where,const string&After,int&Pos);
string GetDataTimeStr();
string GetFileExt(const string&FN);
string LowerStr(const string&s);
string UpperStr(const string&s);
bool IsNumChar(const uchar&c);
bool IsLegalChar(const uchar&c);
template<typename Callback>
class LineVisitor
{
public:
  int line;
  int pos;
  const string&mem;
  LineVisitor(const string&mem):mem(mem)
  {
    pos=0;
    line=0;
  }
  bool Next(Callback&callback)
  {
    line++;
    const string sepstr="\n";
    int npos=mem.find(sepstr,pos);
    if (npos<0)return false;
    string line=std::move(mem.substr(pos,npos-pos));
    callback(line);
    pos=npos+sepstr.size();
    return true;
  }
};
class Extractor
{
public:
  class Gripper
  {
  public:
    string before;
    string after;
    Gripper(const string&before,const string&after);
    string grip(const string&source)const;
  };
public:
  int pos;
  string source;
  Extractor(const string&source);
  string extract(const Gripper&ref);
  template<class TYPE>
  void extract_all(TYPE&visitor,const Gripper&ref)
  {
    while (pos>=0)
    {
      string s=extract(ref);
      if (pos<0)break;
      visitor.accept(s);
    }
  }
  operator bool();
};
template<class TYPE>
class FindData
{
public:
  WIN32_FIND_DATA ffd;
  string Dir;
  HANDLE hFind;
  char buff[1024];
  TYPE&Functor;
  FindData(const string&dir,TYPE&Functor,bool manual=false):hFind(nullptr),Functor(Functor)
  {
    Dir=dir;
    if (manual)return;
    Start();
    do {}
    while (Next());
    Stop();
  }
  void Start()
  {
    if (hFind)return;
    string filename=Dir+"/*";
    hFind=FindFirstFileA(filename.c_str(),&ffd);
    if (INVALID_HANDLE_VALUE==hFind)
    {
      QapDebugMsg("INVALID_HANDLE_VALUE");
      return;
    }
  }
  bool Next()
  {
    if (!hFind)return false;
    string fn=ffd.cFileName;
    {
      fn=Dir+"/"+fn;
      Functor(fn,bool(ffd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY));
    }
    if (!FindNextFile(hFind,&ffd))
    {
      auto dwError=GetLastError();
      if (dwError!=ERROR_NO_MORE_FILES)
      {
        QapDebugMsg("failed");
      }
      Stop();
      return false;
    }
    return true;
  }
  void Stop()
  {
    if (!hFind)FindClose(hFind);
    hFind=nullptr;
  }
  operator bool()
  {
    return hFind;
  }
  ~FindData()
  {
    Stop();
  }
};
string gen_dip(char from,char to);
string gen_dips(const string&rule);
string dip_inv(const string&dip);
vector<string> split(const string&s,const string&needle);
string join(const vector<string>&arr,const string&glue);
string StrReplace(const string&input,const string&sub,const string&now);
string urlencode(const string&str);
string urldecode(const string&s);
template<class TYPE>
static void subarr_in_place(vector<TYPE>&arr,int offset)
{
  if (offset==0)return;
  QapAssert(offset>0);
  QapAssert(offset<arr.size());
  for (int i=0;i+offset<arr.size();i++)
  {
    arr[i]=std::move(arr[i+offset]);
  }
  arr.resize(arr.size()-offset);
}
template<class TYPE>
vector<TYPE> qap_arr_slice(vector<TYPE>&arr,int offset)
{
  vector<TYPE> out;
  if (offset==0)return out;
  QapAssert(offset>0);
  QapAssert(offset<arr.size());
  offset=std::max<int>(0,std::min<int>(offset,arr.size()));
  for (int i=0;i<offset;i++)
  {
    out.push_back(std::move(arr[i]));
  }
  subarr_in_place(arr,offset);
  return out;
}
template<class TYPE>
void qap_arr_join(vector<TYPE>&arr,vector<TYPE>&end)
{
  arr.reserve(arr.size()+end.size());
  for (int i=0;i<end.size();i++)
  {
    arr.push_back(std::move(end[i]));
  }
}
template<class TYPE>class TAutoPtr;
template<class TYPE>class TWeakPtr;
template<class TYPE>
void QapClean(vector<TAutoPtr<TYPE>>&Arr)
{
  int last=0;
  for (int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if (!ex)continue;
    if (last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if (last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>
void QapClean(vector<TWeakPtr<TYPE>>&Arr)
{
  int last=0;
  for (int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if (!ex)continue;
    if (last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if (last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE,class FUNC>
void QapCleanIf(vector<TYPE>&Arr,FUNC&Pred)
{
  int last=0;
  for (int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if (Pred(ex))continue;
    if (last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if (last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>
void QapPopFront(vector<TYPE>&arr)
{
  int last=0;
  for (int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (last!=i)
    {
      auto&ax=arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if (last==arr.size())return;
  arr.resize(last);
}
template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr)
{
  arr.push_back(TYPE());
  return arr.back();
}
template<class TYPE,class FUNC>
static vector<int> qap_find(vector<TYPE>&arr,FUNC&func)
{
  vector<int> out;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (func(ex))out.push_back(i);
  }
  return out;
}
vector<int> qap_find_str(const vector<string>&arr,const string&value);
template<class TYPE,class FUNC>
static void qap_foreach(vector<TYPE>&inp,FUNC&func)
{
  auto&arr=inp;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    func(ex);
  }
}
template<class TYPE>
struct QapToolsVector
{
  vector<TYPE>&arr;
  void operator+=(vector<TYPE>&&ref)
  {
    arr.reserve(arr.size()+ref.size());
    for (int i=0;i<ref.size();i++)
    {
      arr.push_back(std::move(ref[i]));
    }
    ref.clear();
  }
};
template<class TYPE>
QapToolsVector<TYPE> QapToolsVectorEx(vector<TYPE>&ref)
{
  QapToolsVector<TYPE> tmp={ref};
  return std::move(tmp);
}
enum QapMsgBoxRetval
{
  qmbrSkip,qmbrBreak,qmbrIgnore
};
int WinMessageBox(const string&caption,const string&text);
typedef int(*TQapMessageBox)(const string&caption,const string&text);
struct TMessageBoxCaller
{
  static int Call(const string&caption,const string&text);
  static TQapMessageBox&Get();
  struct t_hack
  {
    TQapMessageBox old;
    t_hack(TQapMessageBox func);
    ~t_hack();
  };
};
bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
class CppString
{
public:
  string data;
  CppString();
  CppString(const string&ref);
public:
  void operator=(const string&ref);
public:
  static string toCode(uchar ch);;
  static const CharMask&getMask();
  void oper_set(const string&ref);
public:
  static bool IsValidCppChar(char c);
};
class BinString
{
public:
  string data;
  BinString();
  BinString(const string&ref);
public:
  void operator=(const string&ref);
public:
  static string fullCppStr2RawStr(const string&cpp);
  static string toCode(uchar ch);;
  void oper_set(const string&ref);
};
namespace detail {};
class IEnvRTTI;
class TType;
class TTypeSys;
class TTypeStruct;
class TTypeSys;
class TTypeFactory;
class TTypeVector;
class TTypeArray;
class TTypeSelfPtr;
class TTypeAutoPtr;
class TTypeWeakPtr;
class TTypeHardPtr;
class TTypeVoidPtr;
class TTypeFieldPtr;
class IVisitorRTTI
{
public:
  virtual void Do(TTypeStruct*p)=0;
  virtual void Do(TTypeSys*p)=0;
  virtual void Do(TTypeFactory*p);
  virtual void Do(TTypeVector*p)=0;
  virtual void Do(TTypeArray*p)=0;
  virtual void Do(TTypeSelfPtr*p)=0;
  virtual void Do(TTypeAutoPtr*p)=0;
  virtual void Do(TTypeWeakPtr*p)=0;
  virtual void Do(TTypeHardPtr*p)=0;
  virtual void Do(TTypeVoidPtr*p)=0;
  virtual void Do(TTypeFieldPtr*p)=0;
public:
  template<class TYPE,class Visitor>
  struct Is:public Visitor
  {
    TYPE*ptr;
    Is():ptr(nullptr) {}
public:
    template<class U>static TYPE*get(U*p)
    {
      return nullptr;
    }
    template<>static TYPE*get<TYPE>(TYPE*p)
    {
      return p;
    }
public:
    void Do(TTypeStruct*p)
    {
      ptr=get(p);
    }void Do(TTypeSys*p)
    {
      ptr=get(p);
    }void Do(TTypeFactory*p)
    {
      ptr=get(p);
    }void Do(TTypeVector*p)
    {
      ptr=get(p);
    }void Do(TTypeArray*p)
    {
      ptr=get(p);
    }void Do(TTypeSelfPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeAutoPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeWeakPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeHardPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeVoidPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeFieldPtr*p)
    {
      ptr=get(p);
    }
  };
  template<class TYPE>
  static TYPE*UberCast(TType*p)
  {
    if (!p)return nullptr;
    Is<TYPE,IVisitorRTTI> IS;
    p->Use(IS);
    return IS.ptr;
  }
};
template<class SYS_TYPE>class Sys$$;
namespace detail
{
  struct yes_type
  {
    char padding[1];
  };
  struct no_type
  {
    char padding[8];
  };
  template<bool condition,typename true_t,typename false_t>struct select;
  template<typename true_t,typename false_t>struct select<true,true_t,false_t>
  {
    typedef true_t type;
  };
  template<typename true_t,typename false_t>struct select<false,true_t,false_t>
  {
    typedef false_t type;
  };
  template<class U,U x>struct test;
  template<class TYPE>
  static void TryDoReset(void*) {}
  template<class TYPE>
  static void TryDoReset(TYPE*Self,void(TYPE::ParentClass::*pDoReset)()=&TYPE::ParentClass::DoReset)
  {
    (Self->*pDoReset)();
  }
  template<typename T>
  struct has_self
  {
    __if_not_exists(T::Self)
    {
      static const bool value=false;
    }
    __if_exists(T::Self)
    {
      static const bool value=true;
      __if_exists(TSelfPtr)
      {
        typedef decltype((*(T*)nullptr).Self) t_self_type;
        static_assert(
          std::is_same<TSelfPtr<T>,decltype((*(T*)nullptr).Self)>::value
          ||
          std::is_base_of<t_self_type::ptr_t,T>::value
          ,
          "must!"
        );
      }
    }
  };
  template<typename T>
  struct has_ParentClass
  {
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      typename U::ParentClass(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };
  template<class TYPE,bool flag=has_ParentClass<TYPE>::value>
  struct GetParentClassOf
  {
    typedef void type;
    static TType*GetRTTI(...)
    {
      return nullptr;
    };
  };
  template<class TYPE>
  struct GetParentClassOf<TYPE,true>
  {
    typedef typename TYPE::ParentClass type;
    template<class QAP_RTTI>
    static TType*GetRTTI(QAP_RTTI&RTTI)
    {
      return Sys$$<type>::GetRTTI(RTTI);
    };
  };
  template<typename T>
  struct has_ProxySys$$
  {
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      typename U::ProxySys$$(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };
  template<class TYPE>
  static void FieldTryDoReset(TYPE&p,...) {}
  template<class TYPE,size_t SIZE>static void FieldTryDoReset(array<TYPE,SIZE>&arr)
  {
    for (int i=0;i<SIZE;i++)FieldTryDoReset(arr[i]);
  }
  static void FieldTryDoReset(unsigned short&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(short&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(bool&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(int&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(size_t&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(float&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(double&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(char&ref)
  {
    ref=0;
  };;
  static void FieldTryDoReset(uchar&ref)
  {
    ref=0;
  };;
  template<typename TYPE,bool is_proxy>struct GetProxyMetaType;
  template<typename TYPE>
  struct GetProxyMetaType<TYPE,false>
  {
    typedef TType type;
  };
  template<typename TYPE>
  struct GetProxyMetaType<TYPE,true>
  {
    typedef typename TYPE::ProxySys$$::metatype type;
  };
  template<typename TYPE,bool is_proxy>
  struct GetProxyRTTI;
  template<typename TYPE>
  struct GetProxyRTTI<TYPE,true>
  {
    typedef typename TYPE::ProxySys$$::metatype type;
    template<class QAP_RTTI>
    static type*Do(QAP_RTTI&RTTI)
    {
      return TYPE::ProxySys$$::GetRTTI(RTTI);
    }
    static string GetFullName()
    {
      return std::move(TYPE::ProxySys$$::GetFullName());
    }
  };
  template<class TYPE,bool flag=std::is_abstract<TYPE>::value>
  struct QapAlignOf
  {
    struct proqap
    {
      TYPE f0;
      char f1;
      TYPE f2;
    };
    static const int value=sizeof(proqap)-2*sizeof(TYPE);
  };
  template<class TYPE>
  struct GetTemplParam
  {
    typedef void type;
  };
  template<template<class> class TEMPL,class TYPE>
  struct GetTemplParam<TEMPL<TYPE>>
  {
    typedef typename TYPE type;
  };
  template<class TYPE>
  struct TGetSpecInfoTool
  {
    __if_exists(TYPE::GetClassMetaSpecInfo)
    {
      static string GetSpecInfo()
      {
        return TYPE::GetClassMetaSpecInfo();
      }
    }__if_not_exists(TYPE::GetClassMetaSpecInfo)
    {
      static string GetSpecInfo()
      {
        return "";
      }
    }
  };
  template<class TYPE>
  static string GetSpecInfo()
  {
    return TGetSpecInfoTool<TYPE>::GetSpecInfo();
  }
};
template<class SYS_TYPE>
class Sys$$
{
public:
  static const bool is_proxy=detail::has_ProxySys$$<SYS_TYPE>::value;
  typedef typename detail::GetProxyMetaType<SYS_TYPE,is_proxy>::type metatype;
  typedef typename SYS_TYPE type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    static_assert(is_proxy,"not implemented");
    return detail::GetProxyRTTI<SYS_TYPE,is_proxy>::Do(RTTI);
  }
  static string GetFullName()
  {
    static_assert(is_proxy,"not implemented");
    return detail::GetProxyRTTI<SYS_TYPE,is_proxy>::GetFullName();
  }
};
template<>
class Sys$$<void>
{
public:
  static const bool is_proxy=detail::has_ProxySys$$<void>::value;
  typedef detail::GetProxyMetaType<void,is_proxy>::type metatype;
  typedef void type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    return nullptr;
  }
  static string GetFullName()
  {
    QapDebugMsg("WTF?");
    return "void";
  }
};
class UniqueID
{
private:
  static int GetID();
private:
  void operator=(const UniqueID&);;
  UniqueID(const UniqueID&);;
public:
  void on_init();;;;
  template<int>void weak_on_init()
  {
    ;
  }void on_free();;;;
  template<int>void weak_on_free()
  {
    ;
  }void on_move(int from,int to);;;;
  template<int>void weak_on_move(int from,int to)
  {
    ;
  }
public:
  ~UniqueID();
  UniqueID();
  UniqueID(UniqueID&&_Right);
  void operator=(UniqueID&&_Right);
  void oper_set(UniqueID&&_Right);
public:
  int id;
  typedef UniqueID SelfClass;
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      string Name="UniqueID";
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      RTTI.OnRegEnd(Info);
      return Info;
    }
  };
};
template<typename TYPE>class TServerPtr;
class TProduct;
class TRTTIProduct;
class IAllocator;
template<typename TYPE>
class TClientPtr
{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TClientPtr<TYPE>&)
  {
    QapAssert(0);
  };
  TClientPtr<TYPE>(const TClientPtr<TYPE>&)
  {
    QapAssert(0);
  };
public:
  void init()
  {
    TServerPtr<TYPE>::init_client(this);
  };
  void free()
  {
    TServerPtr<TYPE>::free_client(this);
  };
  void oper_set(TServerPtr<TYPE>*p)
  {
    if (ptr)ptr->Off(this);
    if (p)p->On(this);
  };
  void oper_set(TClientPtr<TYPE>&&_Right)
  {
    UID=std::move(_Right.UID);
    if (ptr)ptr->Off(this);
    if (_Right)
    {
      _Right.ptr->On(this);
      _Right.ptr->Off(&_Right);
    }
  };
public:
  TServerPtr<TYPE>*ptr;
  UniqueID UID;
  TClientPtr<TYPE>*next;
  TClientPtr<TYPE>*prev;
  ~TClientPtr()
  {
    free();
  }
  TClientPtr()
  {
    init();
  }
  TClientPtr(TServerPtr<TYPE>*p)
  {
    init();
    oper_set(p);
  }
  TClientPtr(TClientPtr<TYPE>&&_Right)
  {
    init();
    oper_set(std::move(_Right));
  }
  void operator=(TServerPtr<TYPE>*p)
  {
    oper_set(p);
  }
  void operator=(TClientPtr<TYPE>&&_Right)
  {
    oper_set(std::move(_Right));
  }
  operator bool()const
  {
    return ptr;
  }
};
template<typename TYPE>
class THardClientPtr
{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const THardClientPtr<TYPE>&)
  {
    QapAssert(0);
  };
  THardClientPtr<TYPE>(const THardClientPtr<TYPE>&)
  {
    QapAssert(0);
  };
public:
  void init()
  {
    TServerPtr<TYPE>::init_client(this);
  };
  void free()
  {
    TServerPtr<TYPE>::free_client(this);
  };
  void oper_set(TServerPtr<TYPE>*p)
  {
    if (ptr)ptr->Off(this);
    if (p)p->On(this);
  };
  void oper_set(THardClientPtr<TYPE>&&_Right)
  {
    UID=std::move(_Right.UID);
    if (ptr)ptr->Off(this);
    if (_Right)
    {
      _Right.ptr->On(this);
      _Right.ptr->Off(&_Right);
    }
  };
public:
  TServerPtr<TYPE>*ptr;
  UniqueID UID;
  THardClientPtr<TYPE>*next;
  THardClientPtr<TYPE>*prev;
  ~THardClientPtr()
  {
    free();
  }
  THardClientPtr()
  {
    init();
  }
  THardClientPtr(TServerPtr<TYPE>*p)
  {
    init();
    oper_set(p);
  }
  THardClientPtr(THardClientPtr<TYPE>&&_Right)
  {
    init();
    oper_set(std::move(_Right));
  }
  void operator=(TServerPtr<TYPE>*p)
  {
    oper_set(p);
  }
  void operator=(THardClientPtr<TYPE>&&_Right)
  {
    oper_set(std::move(_Right));
  }
  operator bool()const
  {
    return ptr;
  }
};
template<typename TYPE>
class TServerPtr
{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TServerPtr<TYPE>&)
  {
    QapAssert(0);
  };
  TServerPtr(const TServerPtr<TYPE>&)
  {
    QapAssert(0);
  };
private:
  template<class U>
  static void unsafe_init_client(U*p)
  {
    p->ptr=nullptr;
    p->next=nullptr;
    p->prev=nullptr;
  };
  template<class U>
  static void unsafe_free_client(U*p)
  {
    if (p->ptr)
    {
      p->ptr->Off(p);
    }
  };
public:
  static void init_client(TClientPtr<TYPE>*p)
  {
    unsafe_init_client(p);
  };
  static void free_client(TClientPtr<TYPE>*p)
  {
    unsafe_free_client(p);
  };
  static void init_client(THardClientPtr<TYPE>*p)
  {
    unsafe_init_client(p);
  };
  static void free_client(THardClientPtr<TYPE>*p)
  {
    unsafe_free_client(p);
  };
public:
  ptr_t*ptr;
  UniqueID UID;
  int SaveID;
  int RefCount;
  TClientPtr<TYPE> entry_point;
  int HardCount;
  THardClientPtr<TYPE> hard_point;
  ~TServerPtr()
  {
    if (entry_point||hard_point)
    {
      serv_off();
    }
    free();
  }
  TServerPtr()
  {
    init();
  }
  TServerPtr(ptr_t*p)
  {
    init();
    oper_set(p);
  }
  TServerPtr(TServerPtr<TYPE>&&_Right)
  {
    init();
    oper_set(std::move(_Right));
  }
public:
  void operator=(ptr_t*p)
  {
    oper_set(p);
  }
  void operator=(TServerPtr<TYPE>&&_Right)
  {
    oper_set(std::move(_Right));
  }
public:
  void oper_set(ptr_t*p)
  {
    if (p==ptr)return;
    serv_off();
    serv_on(p);
  }
  void oper_set(TServerPtr<TYPE>&&_Right)
  {
    serv_off();
    serv_on(_Right.ptr);
    _Right.ForEach(&_Right.entry_point,redirect(this));
    _Right.ForEach(&_Right.hard_point,redirect(this));
    _Right.serv_off();
    entry_point.UID=std::move(_Right.entry_point.UID);
    UID=std::move(_Right.UID);
  }
private:
  void init()
  {
    ptr=nullptr;
    RefCount=0;
    HardCount=0;
    SaveID=0;
  }
  void free()
  {
    ptr=nullptr;
  }
  ptr_t*get()const
  {
    return ptr;
  }
  void serv_off()
  {
    QapAssert(!SaveID);
    if (hard_point)
    {
      QapAssert(1==HardCount);
      hard_point=nullptr;
    };
    if (entry_point)
    {
      ForEach(&entry_point,Unmount);
      ptr=nullptr;
      entry_point=nullptr;
    }
    QapAssert(!ptr);
  }
  void serv_on(ptr_t*p)
  {
    ptr=p;
    On(&entry_point);
    On(&hard_point);
  }
  static void unsafe_insert_me(TClientPtr<TYPE>*p)
  {
    p->next->prev=p;
    p->prev->next=p;
  }
  static void unsafe_remove_me(TClientPtr<TYPE>*p)
  {
    p->next->prev=p->prev;
    p->prev->next=p->next;
  }
  static void unsafe_insert_me(THardClientPtr<TYPE>*p)
  {
    p->next->prev=p;
    p->prev->next=p;
  }
  static void unsafe_remove_me(THardClientPtr<TYPE>*p)
  {
    p->next->prev=p->prev;
    p->prev->next=p->next;
  }
public:
  void On(TClientPtr<TYPE>*p)
  {
    _On(p);
  }
  void Off(TClientPtr<TYPE>*p)
  {
    _Off(p);
  }
  void On(THardClientPtr<TYPE>*p)
  {
    _On(p);
  }
  void Off(THardClientPtr<TYPE>*p)
  {
    _Off(p);
  }
private:
  template<class U,bool flag>struct Hidden;
  template<class U>
  struct Hidden<U,true>
  {
    static int&get_counter(TServerPtr<TYPE>*self)
    {
      return self->RefCount;
    }
    static U&get_point(TServerPtr<TYPE>*self)
    {
      return self->entry_point;
    }
  };
  template<class U>
  struct Hidden<U,false>
  {
    static int&get_counter(TServerPtr<TYPE>*self)
    {
      return self->HardCount;
    }
    static U&get_point(TServerPtr<TYPE>*self)
    {
      return self->hard_point;
    }
  };
  template<template<class> class T,class U>
  int&get_counter(T<U>*)
  {
    return Hidden<T<U>,std::is_same<T<U>,TClientPtr<U>>::value>::get_counter(this);
  }
  template<template<class> class T,class U>
  T<U>&get_point(T<U>*)
  {
    return Hidden<T<U>,std::is_same<T<U>,TClientPtr<U>>::value>::get_point(this);
  }
  template<class U>
  void _On(U*p)
  {
    auto&point=get_point(p);
    auto&counter=get_counter(p);
    QapAssert(p);
    QapAssert(!p->ptr);
    p->ptr=this;
    if (p==&point)
    {
      p->next=p;
      p->prev=p;
    }
    else
    {
      QapAssert(point);
      p->next=point.next;
      p->prev=&point;
      unsafe_insert_me(p);
    }
    counter++;
  }
  template<class U>
  void _Off(U*p)
  {
    auto&point=get_point(p);
    auto&counter=get_counter(p);
    QapAssert(p);
    QapAssert(p->ptr);
    unsafe_remove_me(p);
    p->ptr=nullptr;
    p->next=nullptr;
    p->prev=nullptr;
    counter--;
  }
public:
  operator bool()const
  {
    return ptr;
  };
private:
  static void Unmount(TClientPtr<TYPE>*&it)
  {
    auto*next=it->next;
    *it=nullptr;
    it=next;
  }
  class redirect
  {
  public:
    TServerPtr<TYPE>*target;
    redirect(TServerPtr<TYPE>*target):target(target) {}
    void operator()(TClientPtr<TYPE>*&it)
    {
      auto*next=it->next;
      *it=target;
      it=next;
    }
    void operator()(THardClientPtr<TYPE>*&it)
    {
      auto*next=it->next;
      *it=target;
      it=next;
    }
  };
  template<typename U,typename FUNCTOR>
  void ForEach(U*scope,FUNCTOR&func)
  {
    auto&point=get_point(scope);
    if (!point)return;
    U*it=point.next;
    while (it!=&point)func(it);
  }
};
template<typename TYPE>
class UberInit
{
public:
  TRTTIProduct Product;
public:
  template<class QAP_RTTI>
  UberInit(QAP_RTTI&RTTI)
  {
    Product.pType=Sys$$<TYPE>::GetRTTI(RTTI);
    if (!Product.pType)
    {
      int breakpoint=true;
      QapAssert(Product.pType);
    }
  }
  UberInit(UberInit<TYPE>&&_Right)
  {
    QapDebugMsg("good!");
    this->Product=std::move(_Right.Product);
    int gg=0;
  }
  ~UberInit()
  {
    QapAssert(!Product.Memory.ptr);
    QapAssert(!Product.pType);
    Product.pType=nullptr;
  }
};
template<class TYPE>
class TAutoPtr
{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TAutoPtr<TYPE>&Ref)
  {
    QapAssert(0);
  }
  TAutoPtr(const TAutoPtr<TYPE>&Ref)
  {
    QapAssert(0);
  }
public:
  TRTTIProduct Product;
  TAutoPtr():Product() {}
  TAutoPtr(std::nullptr_t):Product()
  {
    oper_set(nullptr);
  }
  TAutoPtr(TAutoPtr<TYPE>&&_Right):Product()
  {
    oper_set(std::move(_Right));
  }
  TAutoPtr(UberInit<TYPE>&Ref):Product()
  {
    oper_set(Ref);
  }
  template<class U>TAutoPtr(TAutoPtr<U>&&_Right):Product()
  {
    oper_set<U>(std::move(_Right));
  }
  template<class U>TAutoPtr(UberInit<U>&Ref):Product()
  {
    oper_set<U>(Ref);
  }
public:
  template<class U,class QAP_RTTI>
  U*build(QAP_RTTI&RTTI)
  {
    IEnvRTTI&Env=RTTI;
    oper_set(UberInit<U>(Env));
    return (U*)get();
  }
  void*unsafe_build(TType*pType)
  {
    this->Off();
    Product.pType=pType;
    Product.Init();
    return get();
  }
public:
  void oper_set(const nullptr_t&)
  {
    Off();
  }
  void oper_set(TAutoPtr<TYPE>&&_Right)
  {
    this->Off();
    Product=std::move(_Right.Product);
  }
  void oper_set(UberInit<TYPE>&Ref)
  {
    Off();
    On(Ref.Product);
  }
public:
  template<class U>
  void oper_set(TAutoPtr<U>&&_Right)
  {
    static_assert(std::is_base_of<TYPE,U>::value,"fail");
    this->Off();
    Product=std::move(_Right.Product);
  }
  template<class U>
  void oper_set(UberInit<U>&Ref)
  {
    TryInit<U,std::is_base_of<TYPE,U>::value>::Do(this,&Ref);
  }
public:
  void operator=(const nullptr_t&)
  {
    oper_set(nullptr);
  }
  void operator=(TAutoPtr<TYPE>&&_Right)
  {
    oper_set(std::move(_Right));
  }
  void operator=(UberInit<TYPE>&Ref)
  {
    oper_set(Ref);
  }
  template<class U>
  void operator=(UberInit<U>&Ref)
  {
    oper_set<U>(Ref);
  }
private:
  void On(TRTTIProduct&A)
  {
    QapAssert(!A);
    QapAssert(!Product);
    Product=std::move(A);
    Product.Init();
  }
  void Off()
  {
    if (!Product.Memory.ptr)return;
    Product.Free();
    Product.pType=nullptr;
  }
public:
  TYPE*get()const
  {
    return (TYPE*)Product.Memory.ptr;
  }
  TYPE*operator->()const
  {
    return get();
  }
  operator bool()const
  {
    return Product.Memory.ptr;
  }
public:
  template<class U,bool flag=true>
  struct TryInit
  {
    static void Do(TAutoPtr<TYPE>*Self,UberInit<U>*Ref)
    {
      Self->Off();
      Self->On(Ref->Product);
    }
  };
  template<class U>struct TryInit<U,false>
  {
    static void Do(...)
  {
    static_assert(false,"U is not based on TYPE");
  }
  };
};
template<class TYPE>
class TSelfPtr
{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TSelfPtr<TYPE>&Ref)=delete;
  TSelfPtr(const TSelfPtr<TYPE>&Ref)=delete;
private:
  typename TServerPtr<TYPE>::ptr_t*get()
  {
    return (TServerPtr<TYPE>::ptr_t*)get(this);
  }
  static TYPE*get(TSelfPtr<TYPE>*ptr)
  {
    static const int field_offset=int(&(((TYPE*)nullptr)->*(&TYPE::Self)));
    return (TYPE*)(void*)(int(ptr)-field_offset);
  }
public:
  TServerPtr<TYPE> P;
  TSelfPtr()
  {
    P=get();
  }
  ~TSelfPtr() {}
  TYPE*operator->()const
  {
    return get();
  }
  operator bool()const
  {
    return P;
  }
public:
  TSelfPtr(TSelfPtr<TYPE>&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TSelfPtr<TYPE>&&_Right)
  {
    if (&_Right==this)return;
    this->P=std::move(_Right.P);
    _Right.P=_Right.get();
    P.ptr=get();
  }
};
template<class TYPE>
class TWeakPtr
{
public:
  typedef TYPE ptr_t;
public:
  TClientPtr<TYPE> P;
  TWeakPtr():P() {}
  TWeakPtr(TWeakPtr<TYPE>&&Ref):P()
  {
    oper_set(std::move(Ref));
  }
  TWeakPtr(const TWeakPtr<TYPE>&Ref):P()
  {
    oper_set(Ref);
  }
  TWeakPtr(TYPE*A):P()
  {
    oper_set(A);
  }
  TWeakPtr(const nullptr_t&):P()
  {
    oper_set(nullptr);
  }
  template<class U>
  TWeakPtr(const UberInit<U>&Ref)
  {
    static_assert(0,"epic fail");
  }
  template<class U>
  TWeakPtr(U*A):P()
  {
    oper_set<U>(A);
  }
  template<class U>
  TWeakPtr(const TWeakPtr<U>&Ref):P()
  {
    oper_set<U>(Ref);
  }
public:
  void oper_set(TWeakPtr<TYPE>&&Ref)
  {
    this->P=Ref?Ref.P.ptr:nullptr;
    Ref.P=nullptr;
  }
  void oper_set(const TWeakPtr<TYPE>&Ref)
  {
    if (&Ref==this)return;
    P=Ref.P.ptr;
  }
  void oper_set(TYPE*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<TYPE,true,true>::Do_Raw(this,A);
  }
  void oper_set(const nullptr_t&)
  {
    P=nullptr;
  }
  template<class U>
  void oper_set(U*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<
    U,
    std::is_base_of<TYPE,U>::value,
    std::is_base_of<U,TYPE>::value
    >::Do_Raw(this,A);
  }
  template<class U>
  void oper_set(const TWeakPtr<U>&Ref)
  {
    TryInit<
    U,
    std::is_base_of<TYPE,U>::value,
    std::is_base_of<U,TYPE>::value
    >::Do_Weak(this,&Ref);
  }
public:
  void operator=(TWeakPtr<TYPE>&&ref)
  {
    oper_set(std::move(ref));
  }
  void operator=(const TWeakPtr<TYPE>&Ref)
  {
    oper_set(Ref);
  }
  void operator=(TYPE*A)
  {
    oper_set(A);
  }
  void operator=(const nullptr_t&)
  {
    oper_set(nullptr);
  }
  template<class U>
  void operator=(const UberInit<U>&Ref)
  {
    static_assert(0,"epic fail");
  }
  template<class U>
  void operator=(U*A)
  {
    oper_set<U>(A);
  }
  template<class U>
  void operator=(const TWeakPtr<U>&Ref)
  {
    oper_set<U>(Ref);
  }
public:
  TYPE*get()const
  {
    return P?(TYPE*)P.ptr->ptr:nullptr;
  }
  TYPE*operator->()const
  {
    return get();
  }
  operator bool()const
  {
    return P;
  }
public:
  template<class U,bool dir,bool indir>
  struct TryInit
  {
    static void Do_Raw(...)
    {
      static_assert(0,"under construction");
    }
  };
  template<class U,bool indir>
  struct TryInit<U,true,indir>
  {
    static void Do_Raw(TWeakPtr<TYPE>*Self,U*Source)
    {
      Self->P=Source?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Weak(TWeakPtr<TYPE>*Self,const TWeakPtr<U>*Source)
    {
      QapDebugMsg("bug detected");
      Self->P=*Source?Source->P.ptr:nullptr;
    }
  };
  template<class U>
  struct TryInit<U,false,true>
  {
    static void Do_Raw(TWeakPtr<TYPE>*Self,U*Source)
    {
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      static_assert(0,"nax");
      U*tmp=Source;
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=Source&&!skip?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
  };
};
template<class TYPE>
class THardPtr
{
public:
  typedef TYPE ptr_t;
public:
  THardClientPtr<TYPE> P;
  THardPtr():P() {}
  THardPtr(const THardPtr<TYPE>&Ref):P()
  {
    oper_set(Ref);
  }
  THardPtr(THardPtr<TYPE>&&Ref):P()
  {
    oper_set(std::move(Ref));
  }
  THardPtr(TYPE*A):P()
  {
    oper_set(A);
  }
  THardPtr(const nullptr_t&):P()
  {
    oper_set(nullptr);
  }
  template<class U>
  THardPtr(const UberInit<U>&Ref)
  {
    static_assert(0,"from constant, you are sure?");
  }
  template<class U>
  THardPtr(U*A):P()
  {
    oper_set<U>(A);
  }
  template<class U>
  THardPtr(const THardPtr<U>&Ref):P()
  {
    oper_set<U>(Ref);
  }
public:
  void oper_set(const THardPtr<TYPE>&Ref)
  {
    if (&Ref==this)return;
    P=Ref.P.ptr;
  }
  void oper_set(TYPE*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<TYPE,true,true>::Do_Raw(this,A);
  }
  void oper_set(const nullptr_t&)
  {
    P=nullptr;
  }
  template<class U>
  void oper_set(U*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<
    U,
    std::is_base_of<TYPE,U>::value,
    std::is_base_of<U,TYPE>::value
    >::Do_Raw(this,A);
  }
  template<class U>
  void oper_set(const THardPtr<U>&Ref)
  {
    TryInit<
    U,
    std::is_base_of<TYPE,U>::value,
    std::is_base_of<U,TYPE>::value
    >::Do_Hrd(this,&Ref);
  }
  void oper_set(THardPtr<TYPE>&&Ref)
  {
    this->P=Ref?Ref.P.ptr:nullptr;
    Ref.P=nullptr;
  }
public:
  void operator=(THardPtr<TYPE>&&Ref)
  {
    oper_set(std::move(Ref));
  }
  void operator=(const THardPtr<TYPE>&Ref)
  {
    oper_set(Ref);
  }
  void operator=(TYPE*A)
  {
    oper_set(A);
  }
  void operator=(const nullptr_t&)
  {
    oper_set(nullptr);
  }
  template<class U>
  void operator=(const UberInit<U>&Ref)
  {
    static_assert(0,"from constant, you are sure?");
  }
  template<class U>
  void operator=(U*A)
  {
    oper_set<U>(A);
  }
  template<class U>
  void operator=(THardPtr<U>&Ref)
  {
    oper_set<U>(Ref);
  }
public:
public:
  TYPE*get()const
  {
    return P?(TYPE*)P.ptr->ptr:nullptr;
  }
  TYPE*operator->()const
  {
    return get();
  }
  operator bool()const
  {
    return P;
  }
public:
  template<class U,bool dir,bool indir>
  struct TryInit
  {
    static void Do_Raw(...)
    {
      static_assert(0,"under construction");
    }
    static void Do_Hrd(...)
    {
      static_assert(0,"under construction");
    }
  };
  template<class U,bool indir>
  struct TryInit<U,true,indir>
  {
    static void Do_Raw(THardPtr<TYPE>*Self,U*Source)
    {
      Self->P=Source?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Hrd(THardPtr<TYPE>*Self,const THardPtr<U>*Source)
    {
      QapDebugMsg("bug detected");
      Self->P=*Source?Source->P.ptr:nullptr;
    }
  };
  template<class U>
  struct TryInit<U,false,true>
  {
    static void Do_Raw(THardPtr<TYPE>*Self,U*Source)
    {
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      static_assert(0,"nax");
      U*tmp=Source;
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=Source&&!skip?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Hrd(THardPtr<TYPE>*Self,THardPtr<U>*Source)
    {
      static_assert(0,"under construction");
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      U*tmp=Source->get();
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=*Source&&!skip?&Source->P:nullptr;
    }
  };
};
class IBinIO
{
public:
  ;
public:
  typedef IBinIO SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  IBinIO(const IBinIO&)=delete;
  IBinIO();;
public:
  IBinIO(IBinIO&&_Right);
  void operator=(IBinIO&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IBinIO";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  virtual void Save(QapIO&IO,void*p);
  virtual void Load(QapIO&IO,void*p);
public:
  virtual void Copy(void*pOut,void*pInp);
  virtual bool IsSame(void*pA,void*pB);
public:
  virtual TType*GetElementType(IEnvRTTI&Env);
  virtual TType*GetMetaType(IEnvRTTI&Env);
public:
  ~IBinIO();
};
class ITxtIO
{
public:
  ;
public:
  typedef ITxtIO SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  ITxtIO(const ITxtIO&)=delete;
  ITxtIO();;
public:
  ITxtIO(ITxtIO&&_Right);
  void operator=(ITxtIO&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="ITxtIO";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  virtual void Save(string&s,void*p);
  virtual void Load(string&s,void*p);
public:
  virtual TType*GetElementType(IEnvRTTI&Env);
  virtual TType*GetMetaType(IEnvRTTI&Env);
public:
  ~ITxtIO();
};
template<class TYPE>
class TBinIO:public IBinIO
{
public:
  typedef IBinIO ParentClass;
  typedef typename TYPE type;
  typedef typename TBinIO<TYPE> SelfClass;
public:
  void Save(QapIO&IO,void*p)
  {
    IO.SavePOD(p,sizeof(type));
  }
  void Load(QapIO&IO,void*p)
  {
    IO.LoadPOD(p,sizeof(type));
  }
public:
  void Copy(void*pOut,void*pInp)
  {
    TYPE&out=*(TYPE*)pOut;
    TYPE&inp=*(TYPE*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB)
  {
    TYPE&a=*(TYPE*)pA;
    TYPE&b=*(TYPE*)pB;
    return a==b;
  }
};
template<class TYPE>
class TTxtIO:public TBinIO<TYPE>
{
public:
  typedef void SelfClass;
public:
  virtual void Save(string&s,void*p)
  {
    static_assert(false,"not ready");
  }
  virtual void Load(string&s,void*p)
  {
    static_assert(false,"not ready");
  }
};
template<class TYPE>
class THeadBinIO:public TBinIO<TYPE>
{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<ParentClass>::GetRTTI(Env);
  };
public:
  static THeadBinIO<TYPE>*Get()
  {
    static THeadBinIO<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      THeadBinIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<class TYPE>
class THeadCppIO:public TTxtIO<TYPE>
{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<ParentClass>::GetRTTI(Env);
  };
public:
  static THeadCppIO<TYPE>*Get()
  {
    static THeadCppIO<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      THeadCppIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<>
class THeadBinIO<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<IBinIO>>&GetArr()
  {
    static vector<TWeakPtr<IBinIO>> tmp;
    return tmp;
  }
};
template<>
class THeadCppIO<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<ITxtIO>>&GetArr()
  {
    static vector<TWeakPtr<ITxtIO>> tmp;
    return tmp;
  }
};
class IVectorAPI
{
public:
  ;
public:
  typedef IVectorAPI SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  IVectorAPI(const IVectorAPI&)=delete;
  IVectorAPI();;
public:
  IVectorAPI(IVectorAPI&&_Right);
  void operator=(IVectorAPI&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IVectorAPI";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  typedef int SizeType;
  ~IVectorAPI();
  virtual SizeType GetCount(void*p);
  virtual void SetCount(void*p,SizeType c);
  virtual void*GetItem(void*p,SizeType i);
public:
  virtual TType*GetElementType(IEnvRTTI&Env);
  virtual TType*GetMetaType(IEnvRTTI&Env);
};
template<class TYPE>
class TVectorAPI:public IVectorAPI
{
public:
  typedef typename TYPE type;
  typedef IVectorAPI ParentClass;
  typedef TVectorAPI<type> SelfClass;
public:
  virtual SizeType GetCount(void*p)
  {
    vector<TYPE>&v=*(vector<TYPE>*)p;
    return v.size();
  }
  virtual void SetCount(void*p,SizeType c)
  {
    vector<TYPE>&v=*(vector<TYPE>*)p;
    v.resize(c);
  }
  virtual void*GetItem(void*p,SizeType i)
  {
    vector<TYPE>&v=*(vector<TYPE>*)p;
    return &v[i];
  }
public:
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("What does this code mean?");
    return nullptr;
  };
public:
  static TVectorAPI<TYPE>*Get()
  {
    static TVectorAPI<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      TVectorAPI<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<>
class TVectorAPI<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<IVectorAPI>>&GetArr()
  {
    static vector<TWeakPtr<IVectorAPI>> tmp;
    return tmp;
  }
};
struct noused_t
{
  noused_t(nullptr_t);
};
class EnvType;
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
class TMemory
{
public:
  struct ptr_t {};
  ptr_t*ptr;
  int size;
  TMemory();
  operator bool()const;
  void operator=(nullptr_t);
  void operator=(TMemory&&_Right);
};
class IProduct
{
public:
  ;
public:
  typedef IProduct SelfClass;;
public:
public:
  void DoReset();
public:
  IProduct(const IProduct&)=delete;
  IProduct();;
public:
  IProduct(IProduct&&_Right);
  void operator=(IProduct&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IProduct";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual void safe_free();
public:
  virtual const TMemory&GetMemory()const;
  virtual TMemory&GetMemory();
  virtual IAllocator*GetAlloc();
  virtual IFactory*GetFactory();
  virtual TType*GetType();
public:
  void Init();;;;
  template<int>void weak_Init()
  {
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(!Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Init(pAlloc,Memory);
  }
  struct {};
  void Free();;;;
  template<int>void weak_Free()
  {
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Free(pAlloc,Memory);
    QapAssert(!Memory);
  }
  operator bool()const;
};
class TProduct:public IProduct
{
public:
  ;
public:
  typedef TProduct SelfClass;
public:
  typedef IProduct ParentClass;;
public:
  TMemory Memory;;
  THardPtr<IAllocator> Alloc;;
  THardPtr<IFactory> Factory;;
public:
  void DoReset();
public:
  TProduct(const TProduct&)=delete;
  TProduct();;
public:
  TProduct(TProduct&&_Right);
  void operator=(TProduct&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TProduct";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TMemory>::GetRTTI(RTTI),"Memory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Memory))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IAllocator>>::GetRTTI(RTTI),"Alloc",int(&(((SelfClass*)nullptr)->*(&SelfClass::Alloc))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  const TMemory&GetMemory()const;
  TMemory&GetMemory();
  IAllocator*GetAlloc();
  IFactory*GetFactory();
  TType*GetType();
public:
  ~TProduct();
};
class TRTTIProduct:public IProduct
{
public:
  ;
public:
  typedef TRTTIProduct SelfClass;
public:
  typedef IProduct ParentClass;;
public:
  TMemory Memory;;
  THardPtr<TType> pType;;
public:
  void DoReset();
public:
  TRTTIProduct(const TRTTIProduct&)=delete;
  TRTTIProduct();;
public:
  TRTTIProduct(TRTTIProduct&&_Right);
  void operator=(TRTTIProduct&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TRTTIProduct";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TMemory>::GetRTTI(RTTI),"Memory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Memory))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  const TMemory&GetMemory()const;
  TMemory&GetMemory();
  IAllocator* GetAlloc();;;;
  template<int>IAllocator* weak_GetAlloc()
  {
    return pType->GetAlloc();
  }IFactory* GetFactory();;;;
  template<int>IFactory* weak_GetFactory()
  {
    return pType->Factory.get();
  }TType* GetType();;;;
  template<int>TType* weak_GetType()
  {
    return pType.get();
  }
public:
  ~TRTTIProduct();
};
class IFactory
{
public:
  ;
public:
  typedef IFactory SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  IFactory(const IFactory&)=delete;
  IFactory();;
public:
  IFactory(IFactory&&_Right);
  void operator=(IFactory&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IFactory";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  ~IFactory();
public:
  void operator=(const IFactory&)=delete;
public:
  virtual void Init(IAllocator*pAlloc,TMemory&);
  virtual void Free(IAllocator*pAlloc,TMemory&);
public:
  virtual string GetElementTypeFullName()const;
  virtual TType*GetElementType(IEnvRTTI&Env);
  virtual TType*GetMetaType(IEnvRTTI&Env);
public:
  virtual int GetSize();
  virtual void UnsafeInit(const TMemory&);
  virtual void UnsafeFree(const TMemory&);
  virtual void UnsafeMove(const TMemory&Dest,const TMemory&Source);
public:
  virtual void unlink();;
};
class IAllocator
{
public:
  ;
public:
  typedef IAllocator SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  IAllocator(const IAllocator&)=delete;
  IAllocator();;
public:
  IAllocator(IAllocator&&_Right);
  void operator=(IAllocator&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IAllocator";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  virtual void Alloc(TMemory&);;
  virtual void Dealloc(TMemory&);;
public:
  class TMemInfo;
  virtual TMemInfo&GetMemInfo();
public:
  class TMemInfo
  {
  public:
  public:
    typedef IAllocator OwnerClass;;
  public:
    typedef TMemInfo SelfClass;;
  public:
    int AllocCount;;
    int DeallocCount;;
    int MemoryUsed;;
  public:
    void DoReset();
  public:
    TMemInfo(const TMemInfo&)=delete;
    TMemInfo();;
  public:
    TMemInfo(TMemInfo&&_Right);
    void operator=(TMemInfo&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TMemInfo";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"AllocCount",int(&(((SelfClass*)nullptr)->*(&SelfClass::AllocCount))),"SET","0");;
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"DeallocCount",int(&(((SelfClass*)nullptr)->*(&SelfClass::DeallocCount))),"SET","0");;
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"MemoryUsed",int(&(((SelfClass*)nullptr)->*(&SelfClass::MemoryUsed))),"SET","0");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    ~TMemInfo();
  public:
    void OnAlloc(TMemory&Mem);
    void OnDealloc(TMemory&Mem);
  };
};
template<typename PARAM,typename TYPE>
void UberReset(PARAM*Param,TYPE&Ref)
{
  detail::Reset<PARAM,TYPE,detail::is_dynamic<PARAM,TYPE>::value>::Do(Param,Ref);
}
bool TDynStructFactory_set_not_sys_field_from_string(TType*p,const string&source,void*pValue);
class TDynStructFactory:public IFactory
{
public:
  ;
public:
  typedef TDynStructFactory SelfClass;
public:
  typedef IFactory ParentClass;;
public:
  THardPtr<TTypeStruct> pType;;
public:
  void DoReset();
public:
  TDynStructFactory(const TDynStructFactory&)=delete;
  TDynStructFactory();;
public:
  TDynStructFactory(TDynStructFactory&&_Right);
  void operator=(TDynStructFactory&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TDynStructFactory";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TTypeStruct>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  struct ptr_t {};
public:
  template<class TYPE>
  void Move(TYPE*pd,TYPE*ps)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if (subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)(void*)pd;
      dMem.size=subtype->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)(void*)ps;
      sMem.size=subtype->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
    auto&arr=type->Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)ex.getValue(pd);
      dMem.size=ty->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)ex.getValue(ps);
      sMem.size=ty->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
  }
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if (subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeInit(Mem);
    }
    auto&arr=type->Members;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeInit(Mem);
    }
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (ex.Mode!="SET")continue;
      void*p=ex.getValue(ptr);
      string&value=ex.Value;
      auto*fieldtype=TTypeSys::UberCast(ex.Type.get());
      if (fieldtype)
      {
        auto*txtio=fieldtype->TxtIO.get();
        txtio->Load(value,p);
      }
      else
      {
        auto*pcommontype=ex.Type.get();
        bool ok=TDynStructFactory_set_not_sys_field_from_string(pcommontype,value,p);
        if (!ok)
        {
          string msg=(
                "the type use SET mode with no sys type:\n"+pcommontype->GetFullName()+"\n\n"
                "and TDynStructFactory_set_not_sys_field_from_string return false"
              );
          QapDebugMsg(msg);
        }
        int gg=1;
      }
      int gg=1;
    }
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    auto&arr=type->Members;
    for (int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeFree(Mem);
    }
    if (subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeFree(Mem);
    }
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem);
  void Free(IAllocator*pAlloc,TMemory&Mem);
public:
  template<class TYPE>
  int weak_GetSize()
  {
    return pType->Info.Size;
  }int GetSize();
  void UnsafeInit(const TMemory&Mem);
  void UnsafeFree(const TMemory&Mem);
  void UnsafeMove(const TMemory&Dest,const TMemory&Source);
public:
  void unlink();;
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if (!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }TType*GetElementType(IEnvRTTI&Env);
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static ptr_t*get(TMemory::ptr_t*ptr);
};
class TDynSelfPtrFactory:public IFactory
{
public:
  ;
public:
  typedef TDynSelfPtrFactory SelfClass;
public:
  typedef IFactory ParentClass;;
public:
  THardPtr<TTypeSelfPtr> pType;;
public:
  void DoReset();
public:
  TDynSelfPtrFactory(const TDynSelfPtrFactory&)=delete;
  TDynSelfPtrFactory();;
public:
  TDynSelfPtrFactory(TDynSelfPtrFactory&&_Right);
  void operator=(TDynSelfPtrFactory&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TDynSelfPtrFactory";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TTypeSelfPtr>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  struct ptr_t {};
public:
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    QapAssert(type);
    auto*elemtype=TTypeStruct::UberCast(type->ElementType.get());
    auto&self=*elemtype->GetNearSelf();
    QapAssert(&self);
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    new(pSelfPtr) TSelfPtr<IEsoteric>;
    pSelfPtr->P=nullptr;
    IEsoteric*p=(IEsoteric*)(void*)(int(pSelfPtr)-self.Offset);
    pSelfPtr->P=p;
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    pSelfPtr->~TSelfPtr<IEsoteric>();
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem);
  void Free(IAllocator*pAlloc,TMemory&Mem);
public:
  template<class TYPE>
  TYPE weak_GetSize()
  {
    return sizeof(TSelfPtr<IEsoteric>);
  }int GetSize();
  void UnsafeInit(const TMemory&Mem);
  void UnsafeFree(const TMemory&Mem);
  void UnsafeMove(const TMemory&Dest,const TMemory&Source);
public:
  void unlink();;
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if (!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }TType*GetElementType(IEnvRTTI&Env);
  TType*GetMetaType(IEnvRTTI&Env);;
public:
  static ptr_t*get(TMemory::ptr_t*ptr);
};
template<class TYPE>
class TFactory:public IFactory
{
public:
  typedef typename TFactory<TYPE> SelfClass;
  typedef IFactory ParentClass;
  typedef TYPE type;
public:
  void operator=(const TFactory<TYPE>&Ref)=delete;
public:
  void operator=(TFactory<TYPE>&&Ref)
  {
    this->Self=std::move(Ref.Self);
  }
public:
  static TFactory<TYPE>*Get()
  {
    static TFactory<TYPE>tmp;
    static bool flag=true;
    if (flag)
    {
      TFactory<void>::GetFactorys().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
public:
  static void Create(TYPE*ptr)
  {
    new(ptr) TYPE;
    detail::FieldTryDoReset(*ptr);
  }
  static void Destroy(TYPE*ptr)
  {
    ptr->~TYPE();
  }
  template<class T>
  static void Move(T&dest,T&source)
  {
    dest=std::move(source);
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem)
  {
    Mem.size=sizeof(TYPE);
    pAlloc->Alloc(Mem);
    Create(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem)
  {
    Destroy(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  int GetSize()
  {
    return sizeof(TYPE);
  }
  void UnsafeInit(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Create(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem)
  {
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Destroy(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source)
  {
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    auto*pd=get(Dest.ptr);
    auto*ps=get(Source.ptr);
    Move<type>(*pd,*ps);
  }
public:
  string GetElementTypeFullName()const
  {
    return std::move(Sys$$<type>::GetFullName());
  }
  TType*GetElementType(IEnvRTTI&Env)
  {
    return Sys$$<type>::GetRTTI(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
private:
  static inline TYPE*get(TMemory::ptr_t*ptr)
  {
    return (TYPE*)(void*)ptr;
  }
};
template<>
class TFactory<void>
{
public:
  static nullptr_t Get()
  {
    return nullptr;
  }
  static vector<TWeakPtr<IFactory>>&GetFactorys()
  {
    static vector<TWeakPtr<IFactory>> tmp;
    return tmp;
  }
};
class TStdAllocator:public IAllocator
{
public:
  ;
public:
  typedef TStdAllocator SelfClass;
public:
  typedef IAllocator ParentClass;;
public:
  TMemInfo Info;;
public:
  void DoReset();
public:
  TStdAllocator(const TStdAllocator&)=delete;
  TStdAllocator();;
public:
  TStdAllocator(TStdAllocator&&_Right);
  void operator=(TStdAllocator&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TStdAllocator";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TMemInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Alloc(TMemory&Mem);
  void Dealloc(TMemory&Mem);
  TMemInfo&GetMemInfo();
};
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
class TRTTIProduct;
template<class TYPE>
class RTTIManager
{
public:
  typedef std::pair<TWeakPtr<IEnvRTTI>,TWeakPtr<TType>> elem;
  vector<elem> Arr;
public:
  static RTTIManager<TYPE>*Get()
  {
    static RTTIManager<TYPE> global;
    return &global;
  }
public:
  elem*FindEnv(IEnvRTTI*Env)
  {
    for (int i=0;i<Arr.size();i++)
    {
      auto&EX=Arr[i];
      auto*ptr=EX.first.get();
      if (ptr==Env)return &EX;
    }
    return nullptr;
  }
  template<class U>
  bool GetPleaseInfo(IEnvRTTI*Env,U*(&val))
  {
    {
      U*u=nullptr;
      TType*t=nullptr;
      t=u;
    }
    elem*el=FindEnv(Env);
    val=(U*)(el?el->second.get():nullptr);
    return el;
  }
  template<class U>
  void SetPleaseInfo(IEnvRTTI*Env,U*val)
  {
    elem*el=FindEnv(Env);
    if (!el)
    {
      Arr.push_back(std::move(elem(Env,val)));
      if (Arr.size()>1)
      {
        QapDebugMsg("over 1 IEnvRTTI instance detected!");
      }
      return;
    }
    el->first=Env;
    el->second=val;
    return;
  }
};
template<class TYPE>
bool QapCanDestroy(TAutoPtr<TYPE>&Ref)
{
  return Ref&&Ref->Self.P.HardCount==1;
}
class EnvType
{
public:
  ;
public:
  typedef EnvType SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  TAutoPtr<TType> Type;;
  TAutoPtr<IFactory> Factory;;
public:
  void DoReset();
public:
  EnvType(const EnvType&)=delete;
  EnvType();;
public:
  EnvType(EnvType&&_Right);
  void operator=(EnvType&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="EnvType";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TAutoPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TAutoPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  bool CheckFactory();;;;
  template<int>bool weak_CheckFactory()
  {
    if (Factory)
    {
      QapAssert(Type);
      return Type->Factory.get()==Factory.get();
    }
    if (!Factory)
    {
      QapAssert(Type&&Type->Factory);
      return true;
    }
    return false;
  }
public:
};
class IEnvRTTI
{
public:
  ;
public:
  typedef IEnvRTTI SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  IEnvRTTI(const IEnvRTTI&)=delete;
  IEnvRTTI();;
public:
  IEnvRTTI(IEnvRTTI&&_Right);
  void operator=(IEnvRTTI&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IEnvRTTI";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  virtual IAllocator*GetAlloc();
  virtual int RegInfo(TAutoPtr<TType>&&_Right);
  virtual EnvType&GetEnvTypeById(int id);
  virtual vector<EnvType>&GetArr();
  virtual void OnRegBeg(TType*Info);
  virtual void OnRegRet(TType*Info);
  virtual void OnRegEnd(TType*Info);
  virtual IEnvRTTI*GetOwnerEnv();
public:
  template<int>
  struct template_detail
  {
    static bool campare_type_full_name(TType*pType,const string&fn)
    {
      return pType->GetFullName()==fn;
    }
  };
  struct TTypeFullNameComparator
  {
    const string&fn;
    TTypeFullNameComparator(const string&fn);
    bool operator()(EnvType&ex);
  };
public:
  TType*FindTypeByName_is_ug_but_work(const string&fn);
  TType*FindTypeByFactory(IFactory*pFactory);
  template<class TYPE>
  TType*weak_FindTypeByFactory(IFactory*pFactory)
  {
    if (!pFactory)return nullptr;
    auto&arr=GetArr();
    for (int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if (pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
public:
  bool IsRootEnv();
  IEnvRTTI*GetRootEnv();
public:
  template<class REG_TYPE,class INFO_TYPE>
  bool Register(INFO_TYPE*(&Info),const string&Name)
  {
    typedef RTTIManager<REG_TYPE> ManType;
    static_assert(std::is_base_of<TType,INFO_TYPE>::value,"bad");
    if (true)
    {
      auto*RootEnv=GetRootEnv();
      if (RootEnv!=this)
      {
        bool flag=RootEnv->Register<REG_TYPE>(Info,Name);
        TType*pType=Info;
        pType=FindTypeByFactory(pType->Factory.get());
        if (!flag)QapAssert(!pType);
        if (!pType)
        {
          QapDebugMsg("type '"+Sys$$<REG_TYPE>::GetFullName()+"' - not found");
        }
        Info=(INFO_TYPE*)pType;
        return true;
      }
    }
    ManType*Man=ManType::Get();
    Man->GetPleaseInfo(this,Info);
    if (Info)
    {
      if (false)OnRegRet(Info);
      return true;
    }
    else
    {
      {
        TProduct prod;
        prod.Alloc=GetAlloc();
        prod.Factory=TFactory<INFO_TYPE>::Get();
        prod.Init();
        Info=(INFO_TYPE*)prod.Memory.ptr;
        Man->SetPleaseInfo(this,Info);
        Info->Info.Name=Name;
        Info->Info.Size=sizeof(REG_TYPE);
        Info->Info.Align=detail::QapAlignOf<REG_TYPE>::value;
        this->OnRegBeg(Info);
        {
          TAutoPtr<INFO_TYPE> tmp;
          tmp.Product.Memory=std::move(prod.Memory);
          int id=RegInfo(std::move(tmp));
          TType*pType=Sys$$<INFO_TYPE>::GetRTTI(*this);
          GetEnvTypeById(id).Type.Product.pType=pType;
        }
        __if_exists(INFO_TYPE::extInfo)
        {
          Info->extInfo.SpecInfo=detail::GetSpecInfo<REG_TYPE>();
          Info->extInfo.Polymorph=std::is_polymorphic<REG_TYPE>::value;
          Info->extInfo.Abstract=std::is_abstract<REG_TYPE>::value;
        }
      }
      typedef detail::select<std::is_abstract<REG_TYPE>::value,void,REG_TYPE>::type select;
      Info->Factory=TFactory<select>::Get();
      Info->Env=this;
      return false;
    }
  }
};
#pragma once

class TTypeInfo
{
public:
  ;
public:
  typedef TTypeInfo SelfClass;;
public:
  string Name;;
  int Size;;
  int Align;;
public:
  void DoReset();
public:
  TTypeInfo(const TTypeInfo&)=delete;
  TTypeInfo();;
public:
  TTypeInfo(TTypeInfo&&_Right);
  void operator=(TTypeInfo&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeInfo";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Align",int(&(((SelfClass*)nullptr)->*(&SelfClass::Align))),"SET","0");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
};
class TType
{
public:
  ;
public:
  typedef TType SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  THardPtr<IEnvRTTI> Env;;
  THardPtr<IFactory> Factory;;
  TTypeInfo Info;;
public:
  void DoReset();
public:
  TType(const TType&)=delete;
  TType();;
public:
  TType(TType&&_Right);
  void operator=(TType&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TType";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IEnvRTTI>>::GetRTTI(RTTI),"Env",int(&(((SelfClass*)nullptr)->*(&SelfClass::Env))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TTypeInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  virtual void Use(IVisitorRTTI&);
  virtual string GetFullName();
  virtual TType*GetMetaType(IEnvRTTI&Env);;
  virtual TType*GetSubType()const;
  bool ready()const;
  IAllocator*GetAlloc();
  bool CanDestroy()const;
public:
  bool IsBasedOn(TType*A)const;
};
class TTypeSys:public TType
{
public:
  ;
public:
  typedef TTypeSys SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<IBinIO> BinIO;;
  THardPtr<ITxtIO> TxtIO;;
public:
  void DoReset();
public:
  TTypeSys(const TTypeSys&)=delete;
  TTypeSys();;
public:
  TTypeSys(TTypeSys&&_Right);
  void operator=(TTypeSys&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeSys";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<IBinIO>>::GetRTTI(RTTI),"BinIO",int(&(((SelfClass*)nullptr)->*(&SelfClass::BinIO))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<ITxtIO>>::GetRTTI(RTTI),"TxtIO",int(&(((SelfClass*)nullptr)->*(&SelfClass::TxtIO))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IVisitorRTTI&A);
  ~TTypeSys();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeVector:public TType
{
public:
  ;
public:
  typedef TTypeVector SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> SizeType;;
  THardPtr<TType> ElementType;;
  THardPtr<IVectorAPI> VecAPI;;
public:
  void DoReset();
public:
  TTypeVector(const TTypeVector&)=delete;
  TTypeVector();;
public:
  TTypeVector(TTypeVector&&_Right);
  void operator=(TTypeVector&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeVector";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SizeType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SizeType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IVectorAPI>>::GetRTTI(RTTI),"VecAPI",int(&(((SelfClass*)nullptr)->*(&SelfClass::VecAPI))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeArray:public TType
{
public:
  ;
public:
  typedef TTypeArray SelfClass;
public:
  typedef TType ParentClass;;
public:
  int Size;;
  THardPtr<TType> ElementType;;
public:
  void DoReset();
public:
  TTypeArray(const TTypeArray&)=delete;
  TTypeArray();;
public:
  TTypeArray(TTypeArray&&_Right);
  void operator=(TTypeArray&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeArray";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeFactory:public TType
{
public:
  ;
public:
  typedef TTypeFactory SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> ElementType;;
  THardPtr<TType> SubType;;
  THardPtr<TType> SmartType;;
public:
  void DoReset();
public:
  TTypeFactory(const TTypeFactory&)=delete;
  TTypeFactory();;
public:
  TTypeFactory(TTypeFactory&&_Right);
  void operator=(TTypeFactory&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeFactory";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SmartType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SmartType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
  TType*GetSubType()const;
};
class IEsoteric;
class QapSysMember
{
public:
  ;
public:
  typedef QapSysMember SelfClass;;
public:
  string Name;;
  THardPtr<TType> Type;;
public:
  void DoReset();
public:
  QapSysMember(const QapSysMember&)=delete;
  QapSysMember();;
public:
  QapSysMember(QapSysMember&&_Right);
  void operator=(QapSysMember&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapSysMember";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void set(const string&Name,TType*Type);
};
class TTypeSelfPtr:public TType
{
public:
  ;
public:
  typedef TTypeSelfPtr SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> ElementType;;
  QapSysMember mSaveID;;
public:
  void DoReset();
public:
  TTypeSelfPtr(const TTypeSelfPtr&)=delete;
  TTypeSelfPtr();;
public:
  TTypeSelfPtr(TTypeSelfPtr&&_Right);
  void operator=(TTypeSelfPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeSelfPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    {
      typedef mSaveIDType ResultType;;
      typedef TServerPtr<IEsoteric> ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
                   );
    }
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
public:
  typedef TDynSelfPtrFactory TDynamicFactory;
};
class TTypeAutoPtr:public TType
{
public:
  ;
public:
  typedef TTypeAutoPtr SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> ElementType;;
  QapSysMember mType;;
public:
  void DoReset();
public:
  TTypeAutoPtr(const TTypeAutoPtr&)=delete;
  TTypeAutoPtr();;
public:
  TTypeAutoPtr(TTypeAutoPtr&&_Right);
  void operator=(TTypeAutoPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeAutoPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TRTTIProduct mProductType;
    {
      typedef mProductType ResultType;;
      typedef TAutoPtr<IEsoteric> ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::Product))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mProductType""\" != \"""TAutoPtr<IEsoteric>"":"":""Product""\""
                   );
    }
    {}
    typedef THardPtr<TType> mProduct_pTypeType;
    {
      typedef mProduct_pTypeType ResultType;;
      typedef mProductType ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::pType))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mProduct_pTypeType""\" != \"""mProductType"":"":""pType""\""
                   );
    }
    {}
    mType.set("Product.pType",Sys$$<mProduct_pTypeType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeWeakPtr:public TType
{
public:
  ;
public:
  typedef TTypeWeakPtr SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> ElementType;;
  QapSysMember mSaveID;;
public:
  void DoReset();
public:
  TTypeWeakPtr(const TTypeWeakPtr&)=delete;
  TTypeWeakPtr();;
public:
  TTypeWeakPtr(TTypeWeakPtr&&_Right);
  void operator=(TTypeWeakPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeWeakPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    {
      typedef mSaveIDType ResultType;;
      typedef TServerPtr<IEsoteric> ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
                   );
    }
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeHardPtr:public TType
{
public:
  ;
public:
  typedef TTypeHardPtr SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> ElementType;;
  QapSysMember mSaveID;;
public:
  void DoReset();
public:
  TTypeHardPtr(const TTypeHardPtr&)=delete;
  TTypeHardPtr();;
public:
  TTypeHardPtr(TTypeHardPtr&&_Right);
  void operator=(TTypeHardPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeHardPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    {
      typedef mSaveIDType ResultType;;
      typedef TServerPtr<IEsoteric> ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
                   );
    }
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeVoidPtr:public TType
{
public:
  ;
public:
  typedef TTypeVoidPtr SelfClass;
public:
  typedef TType ParentClass;;
public:
  QapSysMember mType;;
  QapSysMember mPtr;;
public:
  void DoReset();
public:
  TTypeVoidPtr(const TTypeVoidPtr&)=delete;
  TTypeVoidPtr();;
public:
  TTypeVoidPtr(TTypeVoidPtr&&_Right);
  void operator=(TTypeVoidPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeVoidPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mPtr",int(&(((SelfClass*)nullptr)->*(&SelfClass::mPtr))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef THardPtr<TType> mTypeType;
    {
      typedef mTypeType ResultType;;
      typedef TVoidPtr ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::type))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mTypeType""\" != \"""TVoidPtr"":"":""type""\""
                   );
    }
    {}
    typedef TWeakPtr<IEsoteric> mPtrType;
    {
      typedef mPtrType ResultType;;
      typedef TVoidPtr ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::ptr))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mPtrType""\" != \"""TVoidPtr"":"":""ptr""\""
                   );
    }
    {}
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mPtr.set("ptr",Sys$$<mPtrType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A);
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TVoidPtr;
class TTypeFieldPtr:public TType
{
public:
  ;
public:
  typedef TTypeFieldPtr SelfClass;
public:
  typedef TType ParentClass;;
public:
  QapSysMember mObject;;
  QapSysMember mType;;
  QapSysMember mOffset;;
  QapSysMember mIndex;;
public:
  void DoReset();
public:
  TTypeFieldPtr(const TTypeFieldPtr&)=delete;
  TTypeFieldPtr();;
public:
  TTypeFieldPtr(TTypeFieldPtr&&_Right);
  void operator=(TTypeFieldPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeFieldPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mObject",int(&(((SelfClass*)nullptr)->*(&SelfClass::mObject))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mOffset",int(&(((SelfClass*)nullptr)->*(&SelfClass::mOffset))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mIndex",int(&(((SelfClass*)nullptr)->*(&SelfClass::mIndex))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TVoidPtr mObjectType;
    {
      typedef mObjectType ResultType;;
      typedef TFieldPtr ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::object))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mObjectType""\" != \"""TFieldPtr"":"":""object""\""
                   );
    }
    {}
    typedef THardPtr<TType> mTypeType;
    {
      typedef mTypeType ResultType;;
      typedef TFieldPtr ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::type))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mTypeType""\" != \"""TFieldPtr"":"":""type""\""
                   );
    }
    {}
    typedef int mOffsetType;
    {
      typedef mOffsetType ResultType;;
      typedef TFieldPtr ClassType;;;
      ;;;
      typedef decltype((((ClassType*)nullptr)->*(&ClassType::offset))) realtype;
      ;;;
      typedef std::remove_reference<realtype>::type fieldtype;
      ;;;
      static_assert(std::is_same<ResultType,fieldtype>::value,
          "\"""mOffsetType""\" != \"""TFieldPtr"":"":""offset""\""
                   );
    }
    {}
    mObject.set("object",Sys$$<mObjectType>::GetRTTI(Env));
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mOffset.set("offset",Sys$$<mOffsetType>::GetRTTI(Env));
    {}
    mIndex.set("index",Sys$$<int>::GetRTTI(Env));
  }void Use(IVisitorRTTI&A);
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);;
};
class TTypeStruct:public TType
{
public:
  class Member
  {
  public:
  public:
    typedef TTypeStruct OwnerClass;;
  public:
    typedef Member SelfClass;;
  public:
    string Name;;
    int Offset;;
    THardPtr<TType> Type;;
    string Mode;;
    string Value;;
  public:
    void DoReset();
  public:
    Member(const Member&)=delete;
    Member();;
  public:
    Member(Member&&_Right);
    void operator=(Member&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="Member";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");;
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Offset",int(&(((SelfClass*)nullptr)->*(&SelfClass::Offset))),"SET","0");;
        Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mode))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Value",int(&(((SelfClass*)nullptr)->*(&SelfClass::Value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    void*getValue(void*pValue);
  };
  class TExtInfo
  {
  public:
  public:
    typedef TTypeStruct OwnerClass;;
  public:
    typedef TExtInfo SelfClass;;
  public:
    int SelfId;;
    string SpecInfo;;
    bool Polymorph;;
    bool Abstract;;
    bool PoorDesign;;
  public:
    void DoReset();
  public:
    TExtInfo(const TExtInfo&)=delete;
    TExtInfo();;
  public:
    TExtInfo(TExtInfo&&_Right);
    void operator=(TExtInfo&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TExtInfo";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"SelfId",int(&(((SelfClass*)nullptr)->*(&SelfClass::SelfId))),"SET","-1");;
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"SpecInfo",int(&(((SelfClass*)nullptr)->*(&SelfClass::SpecInfo))),"DEF","$");;
        Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Polymorph",int(&(((SelfClass*)nullptr)->*(&SelfClass::Polymorph))),"SET","false");;
        Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Abstract",int(&(((SelfClass*)nullptr)->*(&SelfClass::Abstract))),"SET","false");;
        Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"PoorDesign",int(&(((SelfClass*)nullptr)->*(&SelfClass::PoorDesign))),"SET","false");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
  };
public:
  ;
public:
  typedef TTypeStruct SelfClass;
public:
  typedef TType ParentClass;;
public:
  THardPtr<TType> SubType;;
  THardPtr<TType> OwnType;;
  vector<Member> Members;;
  vector<THardPtr<TType>> Nesteds;;
  TExtInfo extInfo;;
public:
  void DoReset();
public:
  TTypeStruct(const TTypeStruct&)=delete;
  TTypeStruct();;
public:
  TTypeStruct(TTypeStruct&&_Right);
  void operator=(TTypeStruct&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TTypeStruct";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"OwnType",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<Member>>::GetRTTI(RTTI),"Members",int(&(((SelfClass*)nullptr)->*(&SelfClass::Members))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<THardPtr<TType>>>::GetRTTI(RTTI),"Nesteds",int(&(((SelfClass*)nullptr)->*(&SelfClass::Nesteds))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TExtInfo>::GetRTTI(RTTI),"extInfo",int(&(((SelfClass*)nullptr)->*(&SelfClass::extInfo))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<Member>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<TExtInfo>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IVisitorRTTI&A);
  static string GetElementName(THardPtr<TType>&ElementType);
  string GetFullName();
public:
  string GetDebugInfo();
public:
  bool TestField(const Member&it,int depth=0);
public:
  static SelfClass*UberCast(TType*ptr);;
public:
  template<class TYPE>
  static TYPE*AddOffset(TYPE*pValue,int offset)
  {
    return (TYPE*)(void*)(offset+int(pValue));
  }
  struct IsStruct
  {
    static Member*GetNearSelf(THardPtr<TType>&pType);
    static Member*GetNearSelf(TType*type);
    struct MemberIndexByOffset
    {
      struct FieldInfo
      {
        TTypeStruct*base;
        int index;
        Member*get();
      };
      struct Input
      {
        TType*type;
        int offset;
        TType*fieldtype;
      };
      struct Output
      {
        int index;
        FieldInfo info;
      };
      static bool get(Input&in,Output&out);
    };
  };
  Member*GetNearSelf();
public:
  void AddField(Member&&field);
  void AddMemberSET(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value);
  void AddMemberDEF(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value);
  void AddMemberSYS(...);
  void AddMemberSYD(...);
  void AddNested(TType*NestedType);
public:
  static vector<string>&get_white_list();
  static bool find_in_white_list(const string&type_fullname);
  void SelfTesting();
public:
  void Calc();
  static int getAligned(int offset,int align);
  void ReCalcMembersOffset();
  TType*GetMetaType(IEnvRTTI&Env);
  TType*GetSubType()const;
  bool IsEqual(TTypeStruct*type);
  bool hasMember(const string&name);
  Member&unsafe_find_member(const string&name);
  Member*find_member(const string&name);
  Member*find_member_full(const string&name);
public:
  typedef TDynStructFactory TDynamicFactory;
};
class IEsoteric
{
public:
  ;
public:
  typedef IEsoteric SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  IEsoteric(const IEsoteric&)=delete;
  IEsoteric();;
public:
  IEsoteric(IEsoteric&&_Right);
  void operator=(IEsoteric&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IEsoteric";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
};
struct TRawPtr
{
  TType*pType;
  void*pValue;
  TRawPtr();
  TRawPtr(TType*pType,void*pValue);
  template<class TYPE>
  TRawPtr(IEnvRTTI&Env,TYPE&Ref):pType(nullptr),pValue(nullptr)
  {
    set(Env,Ref);
  }
  template<class TYPE>
  TRawPtr(TAutoPtr<TYPE>&Ref)
  {
    set(Ref);
  }
  template<class TYPE>
  void set(IEnvRTTI&Env,TYPE&Ref)
  {
    pType=Sys$$<TYPE>::GetRTTI(Env);
    pValue=&Ref;
  }
  template<class TYPE>
  void set(TAutoPtr<TYPE>&Ref)
  {
    if (Ref)
    {
      pType=Ref.Product.pType.get();
      pValue=Ref.get();
    }
    else
    {
      setZero();
    }
  }void set(TType*pType,void*pValue);
  void setZero();
  bool IsValid();
};
class TVoidPtr
{
public:
  ;
public:
  typedef TVoidPtr SelfClass;;
public:
  THardPtr<TType> type;;
  TWeakPtr<IEsoteric> ptr;;
public:
  void DoReset();
public:
  TVoidPtr(const TVoidPtr&)=delete;
  TVoidPtr();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TVoidPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYS(0,nullptr,"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"ptr",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  operator bool()const;
public:
  void oper_set(SelfClass&&ref);
  void operator=(SelfClass&&ref);
public:
public:
  void off();
  void operator=(const nullptr_t&null);
  void mega_unsafe_connect(TType*pType,void*pValue);
  void mega_unsafe_connect(const TRawPtr&ptr);
  template<class TYPE>
  void operator=(TAutoPtr<TYPE>&Ref)
  {
    off();
    if (!Ref)return;
    auto*pType=Ref.Product.pType.get();
    auto*pValue=Ref.get();
    mega_unsafe_connect(pType,pValue);
  }
};
struct SubFieldsInfo
{
public:
  class OutDeviceEx
  {
  public:
    class TMemberID;
    class TSubType;
    struct IVisitor
    {
      virtual void Do(TMemberID*p)=0;
      virtual void Do(TSubType*p)=0;
    };
    struct DevCmd
    {
      virtual void Use(IVisitor&A)=0;
    };
    class TMemberID:public DevCmd
    {
    public:
      int id;
      TMemberID(int id);
    public:
      void Use(IVisitor&A);
    };
    class TSubType:public DevCmd
    {
    public:
      void Use(IVisitor&A);
    };
    class TContext
    {
    public:
      DevCmd*pCmd;
    public:
      TType*pType;
      int Offset;
      const string*head;
    public:
      TContext();
    };
    class TCmdVisitor:public IVisitor
    {
    public:
      TContext*pContext;
    public:
      void Do(TMemberID*p);
      void Do(TSubType*p);
    };
  public:
    class TCmdOffsetVisitor:public IVisitor
    {
    public:
      struct TContext
      {
        TType*pType;
        int Offset;
      };
      TContext*pContext;
    public:
      void Do(TMemberID*p);
      void Do(TSubType*p);
    };
  public:
    TContext Context;
    vector<TContext> branch;
  public:
    void push(DevCmd*pCmd);
    void pop();
  public:
    string GetFullFieldNameByIdFromBranch(int id);
    int GetRelativeFieldOffsetByIdFromBranch(int id);
  };
public:
public:
  class TOffsetVerifier:public IVisitorRTTI
  {
  public:
    typedef TOffsetVerifier SelfClass;
    typedef OutDeviceEx TSaveDev;
  public:
    struct ICallBack
    {
      virtual bool Do(SelfClass&V,TType*p)=0;
    };
  public:
    struct TFieldInfo
    {
      TType*pType;
      int Offset;
      void setZero();
    };
    class IndexGetter:public ICallBack
    {
    public:
      bool Result;
      int Index;
      const TFieldInfo&Info;
      IndexGetter(const TFieldInfo&Info);
    public:
      bool Do(SelfClass&OV,TType*p);
    };
    class InfoGetter:public ICallBack
    {
    public:
      bool Result;
      int Index;
      TFieldInfo&Info;
      InfoGetter(TFieldInfo&Info,int Index=-1);
    public:
      bool Do(SelfClass&OV,TType*p);
    };
    class FieldNameGetter:public ICallBack
    {
    public:
      bool Result;
      int Index;
      string fieldname;
      const TFieldInfo&Info;
      FieldNameGetter(const TFieldInfo&Info);
    public:
      bool Do(SelfClass&V,TType*p);
    };
  public:
    TSaveDev&dev;
    ICallBack&CB;
    int Offset;
    int&Index;
    TOffsetVerifier(TSaveDev&dev,ICallBack&CB,int Offset,int&Index);
    TOffsetVerifier(SelfClass&owner,int Offset);
  public:
    void Do(TTypeStruct*p);
    void Do(TTypeSys*p);
    void Do(TTypeVector*p);
    void Do(TTypeArray*p);
    void Do(TTypeSelfPtr*p);
    void Do(TTypeAutoPtr*p);
    void Do(TTypeWeakPtr*p);
    void Do(TTypeHardPtr*p);
    void Do(TTypeVoidPtr*p);
    void Do(TTypeFieldPtr*p);
  };
public:
  typedef TOffsetVerifier::TFieldInfo TFieldInfo;
public:
public:
  static string FieldInfoToFieldName(TType*pType,const TOffsetVerifier::TFieldInfo&Info);
public:
public:
  static int FieldInfoToIndex(TType*pType,const TOffsetVerifier::TFieldInfo&Info);
  static TOffsetVerifier::TFieldInfo IndexToFieldInfo(TType*pType,int Index);
public:
public:
};
class TFieldPtr
{
public:
  ;
public:
  typedef TFieldPtr SelfClass;;
public:
  TVoidPtr object;;
  THardPtr<TType> type;;
  int offset;;
public:
  void DoReset();
public:
  TFieldPtr(const TFieldPtr&)=delete;
  TFieldPtr();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TFieldPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYS(0,nullptr,"object",int(&(((SelfClass*)nullptr)->*(&SelfClass::object))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"offset",int(&(((SelfClass*)nullptr)->*(&SelfClass::offset))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void off();
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void ConnectToField(QAP_RTTI&RTTI,OBJECT_TYPE&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"bad");
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=&object;
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if (result)
    {
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void Connect(QAP_RTTI&RTTI,TAutoPtr<OBJECT_TYPE>&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    if (!object)return;
    auto*objecttype=object.Product.pType.get();
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=object.get();
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if (result)
    {
      this->object=object;
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE>
  void ConnectEx(QAP_RTTI&RTTI,OBJECT_TYPE&object)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"fail");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=objecttype;
    {
      string ot_fn=objecttype->GetFullName();
    }
    int offset=0;
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if (result)
    {
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
public:
  operator bool();
  void*getValue();
  TType*getType();
public:
  struct TInfo
  {
    TTypeStruct*pType;
    void*pValue;
    TType*pFieldType;
    int Offset;
    void SetToField(TFieldPtr&Field);
    operator bool()const;
    TInfo();
    void set(TTypeStruct*pType,void*pValue,TType*pFieldType,int Offset);
    void GrabFrom(TFieldPtr&FP);
  };
public:
  void oper_set(SelfClass&&ref);
  void operator=(SelfClass&&ref);
  TFieldPtr(SelfClass&&ref);
public:
  void operator=(const TInfo&ref);
public:
  static bool IsValid(TType*pType,TType*pFieldType,int Offset);
};
#pragma once

const real Pi =4.0*atan(1.0);
const real Pi2 =8.0*atan(1.0);
const real PiD2=2.0*atan(1.0);
const real PiD4=1.0*atan(1.0);
template<typename TYPE>inline TYPE Lerp(const TYPE&A,const TYPE&B,const real&v)
{
  return A+(B-A)*v;
}
template<class TYPE>inline TYPE Clamp(const TYPE&v,const TYPE&a,const TYPE&b)
{
  return max(a,min(v, b));
}
class vec2d
{
public:
  ;
public:
  typedef vec2d SelfClass;;
public:
  real x;;
  real y;;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="vec2d";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<real>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","0.0");;
      Info->AddMemberSET(Sys$$<real>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","0.0");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  vec2d();
  vec2d(const real&x,const real&y);
  vec2d(const vec2d&v);
  void operator=(const vec2d&v);
  vec2d operator+()const;
  vec2d operator-()const;
  void operator+=(const vec2d&v);
  void operator-=(const vec2d&v);
  void operator*=(const real&f);
  void operator/=(const real&f);
public:
  vec2d Rot(const vec2d&OX)const;
  vec2d UnRot(const vec2d&OX)const;
  vec2d Ort()const;
  vec2d Norm()const;
  vec2d SetMag(const real&val)const;
  vec2d Mul(const vec2d&v)const;
  vec2d Div(const vec2d&v)const;
  real GetAng()const;
  real Mag()const;
  real SqrMag()const;
public:
  friend vec2d operator+(const vec2d&u,const vec2d&v);
  friend vec2d operator-(const vec2d&u,const vec2d&v);
  friend vec2d operator*(const vec2d&u,const real&v);
  friend vec2d operator*(const real&u,const vec2d&v);
  friend bool operator==(const vec2d&u,const vec2d&v);
  friend bool operator!=(const vec2d&u,const vec2d&v);
public:
public:
  friend static real dot(const vec2d&a,const vec2d&b);
  friend static real cross(const vec2d&a,const vec2d&b);
public:
};
class QapColor
{
public:
  typedef uchar byte;
public:
  ;
public:
  typedef QapColor SelfClass;;
public:
  uchar b;;
  uchar g;;
  uchar r;;
  uchar a;;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapColor";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"b",int(&(((SelfClass*)nullptr)->*(&SelfClass::b))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"g",int(&(((SelfClass*)nullptr)->*(&SelfClass::g))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"r",int(&(((SelfClass*)nullptr)->*(&SelfClass::r))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"a",int(&(((SelfClass*)nullptr)->*(&SelfClass::a))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  QapColor();
  QapColor(byte A,byte R,byte G,byte B);
  QapColor(byte R,byte G,byte B);
  QapColor(const QapColor& v);
public:
  QapColor&operator=(const QapColor&v);
  QapColor operator+()const;
public:
  QapColor&operator*=(const QapColor&v);
  QapColor&operator+=(const QapColor&v);
  QapColor&operator-=(const QapColor&v);
  QapColor operator*(const QapColor&v)const;
  QapColor operator+(const QapColor&v)const;
  QapColor operator-(const QapColor&v)const;
public:
  QapColor&operator*=(real f);
  QapColor&operator/=(real r);
public:
  QapColor(const D3DCOLOR& v);
  operator D3DCOLOR&()const;;
public:
public:
  byte GetLuminance();
  static QapColor Mix(const QapColor&A,const QapColor&B,const real&t);
  static QapColor HalfMix(const QapColor&A,const QapColor&B);
};
class vec4i
{
public:
  ;
public:
  typedef vec4i SelfClass;;
public:
  int x;;
  int y;;
  int z;;
  int w;;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="vec4i";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"z",int(&(((SelfClass*)nullptr)->*(&SelfClass::z))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"w",int(&(((SelfClass*)nullptr)->*(&SelfClass::w))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  vec4i();
  vec4i(int x,int y,int z,int w);
  vec4i(const QapColor&ref);
  void operator+=(const vec4i&v);
  vec4i operator*(const int&v);
  vec4i operator/(const int&v);
  void operator/=(const int&v);
  void operator>>=(const int&v);
  vec4i operator+(const vec4i&v);
  QapColor unsafe_but_fast_GetColor();
};
struct vec3f
{
public:
  float x,y,z;
  vec3f();
  vec3f(float x,float y,float z);
};
struct vec4f
{
public:
  float b,g,r,a;
  vec4f();
  vec4f(float b,float g,float r,float a);
  vec4f(const QapColor&ref);
  vec4f&operator+=(const vec4f&v);
  friend vec4f operator*(const float&u,const vec4f&v);
  friend vec4f operator+(const vec4f&u,const vec4f&v);
  QapColor GetColor();
};
class vec2f
{
public:
  ;
public:
  typedef vec2f SelfClass;;
public:
  float x;;
  float y;;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="vec2f";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<float>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","0.0f");;
      Info->AddMemberSET(Sys$$<float>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","0.0f");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  vec2f();
  vec2f(const vec2d&v);
  vec2f(float x,float y);;
  void set_zero();
public:
  friend vec2f operator*(const vec2f&u,const float&v);
  friend vec2f operator*(const float&u,const vec2f&v);
  friend vec2f operator+(const vec2f&u,const vec2f&v);
  friend vec2f operator-(const vec2f&u,const vec2f&v);
public:
  void operator+=(const vec2d&v);
  void operator-=(const vec2d&v);
public:
  friend vec2f operator*(float u,const vec2f&v);
  operator vec2d()const;
};
class vec2i
{
public:
  ;
public:
  typedef vec2i SelfClass;;
public:
  int x;;
  int y;;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="vec2i";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","0");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","0");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  vec2i();
  vec2i(int x,int y);;
  friend vec2i operator*(int u,const vec2i&v);
  friend vec2i operator*(const vec2i&v,int u);
  friend vec2i operator/(const vec2i&v,int d);
  friend vec2i operator+(const vec2i&u,const vec2i&v);
  friend vec2i operator-(const vec2i&u,const vec2i&v);
  void operator+=(const vec2i&v);
  void operator-=(const vec2i&v);
  vec2i Mul(const vec2i&v)const;
  int SqrMag();
  float Mag();
  vec2i abs();
  bool dist_less(const vec2i&point,int dist);
  operator vec2d()const;
  operator vec2f()const;
  vec2i operator+()const;
  vec2i operator-()const;
  friend bool operator==(const vec2i&u,const vec2i&v);
  friend bool operator!=(const vec2i&u,const vec2i&v);
};
struct Dip2i
{
public:
  int a,b;
  Dip2i(int a,int b);;
  void Take(int x);
  Dip2i Norm()const;
  int Mag()const;
public:
  struct Transform
  {
    float x,s;
    Transform(float x,float s);
    Transform(const Dip2i&from,const Dip2i&to);
    float operator*(int v);
  };
};
struct rot2f
{
public:
  float s;
  float c;
  rot2f();
  explicit rot2f(float ang);
  void set(float ang);
  void set_ident();
  float GetAng()const;
  vec2f GetXAxis()const;
  vec2f GetYAxis()const;
public:
  friend vec2f operator*(const rot2f&q,const vec2d&v);
};
class QapMat22
{
public:
  vec2f col1;
  vec2f col2;
public:
  QapMat22();
  QapMat22(const vec2f&c1,const vec2f&c2);
  QapMat22(float a11,float a12,float a21,float a22);
  explicit QapMat22(float ang);
  void set(const vec2f&c1,const vec2f&c2);
  void set(float ang);
  void set_ident();
  void set_zero();
  float GetAngle()const;
};
class transform2f
{
public:
  vec2f p;
  QapMat22 r;
public:
  transform2f();
  transform2f(const vec2f&p,const QapMat22&r);
  explicit transform2f(const vec2f&p);
  void set_ident();
  void set(const vec2d&p,float ang);
  float getAng()const;
public:
  friend vec2f operator*(const transform2f&T,const vec2f&v);
};
const vec2d vec2d_zero(0.0,0.0);
const vec2i vec2i_zero(0,0);
const vec2f vec2f_zero(0,0);
const rot2f rot2f_ident(0.0);
typedef vector<QapColor> ColorArray;
typedef ColorArray* PColorArray;
typedef vector<vec2d> PointArray;
typedef PointArray* PPointArray;
typedef vector<int> IntArray;
typedef IntArray* PIntArray;
transform2f MakeZoomTransform(const vec2d&zoom);
union TLine
{
  struct
  {
    vec2d A,B;
  };
  struct
  {
    real ax,ay,bx,by;
  };
public:
  TLine();
  TLine(const vec2d&A,const vec2d&B);
  TLine(const real&ax,const real&ay,const real&bx,const real&by);
};
vec2d Vec2dEx(const real&ang,const real&mag);
real vec2d_cross(const vec2d&a,const vec2d&b);
int round(const real&val);
vec2d PToV(const POINT&v);
class TSpaceDependsTools;
class DeclareEnvRTTI;
class TServerPtrSpace;
class DeclareType;
class DeclareTypeStruct;
class DeclareTypeSys;
struct TwoDeclareMetaType
{
  DeclareType*pdTType;
  DeclareType*pdDeclareType;
  TwoDeclareMetaType();
};
template<class VOID_TYPE>
struct TDeclareEnvRTTI_WeakDetail
{
public:
  typedef TServerPtrSpace TSpace;
  static void GrabFrom(DeclareEnvRTTI&Dest,DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt)
  {
    auto&arr=Source.Arr;
    auto&out=Dest.Arr;
    QapAssert(out.empty());
    out.reserve(arr.size());
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      const auto&ex_SaveID=ex->Self.P.SaveID;
      bool skip=!Space.IsSolved(ex_SaveID);
      QapAssert(!skip);
      if (skip)continue;
      if (true)
      {
        auto&item=Space[ex_SaveID];
        if (!item.count)continue;
      }
      bool f0=ex.get()->IsBasedOn(tdmt.pdTType);
      bool f1=ex.get()->IsBasedOn(tdmt.pdDeclareType);
      QapAssert(!(f0&&f1));
      skip=f0||f1;
      if (skip)continue;
      out.push_back(std::move(ex));
    }
  }
  typedef vector<TAutoPtr<DeclareType>> TArray;
};
class DeclareEnvType
{
public:
  ;
public:
  typedef DeclareEnvType SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  TAutoPtr<DeclareType> Type;;
public:
  void DoReset();
public:
  DeclareEnvType(const DeclareEnvType&)=delete;
  DeclareEnvType();;
public:
  DeclareEnvType(DeclareEnvType&&_Right);
  void operator=(DeclareEnvType&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareEnvType";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TAutoPtr<DeclareType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  static bool IsEmpty(SelfClass&ref);
};
class DeclareEnvRTTI
{
public:
  ;
public:
  typedef DeclareEnvRTTI SelfClass;;
public:
  vector<TAutoPtr<DeclareType>> Arr;;
public:
  void DoReset();
public:
  DeclareEnvRTTI(const DeclareEnvRTTI&)=delete;
  DeclareEnvRTTI();;
public:
  DeclareEnvRTTI(DeclareEnvRTTI&&_Right);
  void operator=(DeclareEnvRTTI&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareEnvRTTI";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<DeclareType>>>::GetRTTI(RTTI),"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  typedef TServerPtrSpace TSpace;
  typedef vector<TAutoPtr<DeclareType>> TArray;
public:
  struct TwoDeclareType
  {
    DeclareType*pdTType;
    DeclareType*pdDeclareType;
    TwoDeclareType(const TwoDeclareType&Ref);
    TwoDeclareType();
    template<class TYPE>
    TwoDeclareType(TYPE&ref):pdTType(ref.pTType),pdDeclareType(ref.pDeclareType)
    {
      static_assert(std::is_same<std::remove_reference<decltype(this->pdTType)>::type,std::remove_reference<decltype(ref.pdTType)>::type>::value,"no way");;
      static_assert(std::is_same<std::remove_reference<decltype(this->pdDeclareType)>::type,std::remove_reference<decltype(ref.pdDeclareType)>::type>::value,"no way");;
    }void oper_set(const TwoDeclareType&Ref);
    void operator=(const TwoDeclareType&Ref);
  };
public:
  void GrabFrom(DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt);
  void RetAll(TSpaceDependsTools&Tools);
  bool ApplyTo(TSpaceDependsTools&Tools,TSpace&tmpSpace);
};
class DeclareType;
struct EnvVoidPtr
{
  typedef TServerPtr<IEsoteric>ptr_t;
  ptr_t*ptr;
  TType*type;
  EnvVoidPtr();;
  EnvVoidPtr(ptr_t*ptr,TType*type=nullptr);
  ptr_t::ptr_t*get()const;
  bool IsValid()const;
  bool IsNull()const;
  template<class TYPE>
  void set(const TAutoPtr<TYPE>&ref)
  {
    ptr=nullptr;
    type=nullptr;
    if (!ref)return;
    ptr=(ptr_t*)(void*)&ref.get()->Self;
    type=ref.Product.pType.get();
  }void set_zero();
  bool operator==(const EnvVoidPtr&ref)const;
  bool operator!=(const EnvVoidPtr&ref)const;
  bool oper_eq(const EnvVoidPtr&ref)const;
};
class EnvItem
{
public:
  ;
public:
  typedef EnvItem SelfClass;;
public:
  int id;;
  EnvVoidPtr ptr;;
  EnvVoidPtr ptr_lnk;;
  string name;;
  int count;;
  bool passed;;
  bool system;;
  bool hidden;;
public:
  void DoReset();
public:
  EnvItem(const EnvItem&)=delete;
  EnvItem();;
public:
  EnvItem(EnvItem&&_Right);
  void operator=(EnvItem&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="EnvItem";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","0");;
      Info->AddMemberDEF(Sys$$<EnvVoidPtr>::GetRTTI(RTTI),"ptr",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<EnvVoidPtr>::GetRTTI(RTTI),"ptr_lnk",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr_lnk))),"DEF","$");;
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"SET","\"\"");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"count",int(&(((SelfClass*)nullptr)->*(&SelfClass::count))),"SET","0");;
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"passed",int(&(((SelfClass*)nullptr)->*(&SelfClass::passed))),"SET","false");;
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"system",int(&(((SelfClass*)nullptr)->*(&SelfClass::system))),"SET","false");;
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"hidden",int(&(((SelfClass*)nullptr)->*(&SelfClass::hidden))),"SET","false");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  EnvItem&copy(const EnvItem&source);
  void CheckNullptr();
  bool oper_eq(const SelfClass&ref,bool ignore_id=false)const;
  bool operator==(const SelfClass&ref)const;
  bool IsNoUsed();
  void SetAsNullptr();
  template<class TYPE>
  EnvItem&weak_get_lnk(TServerPtrSpace&Space)const
  {
    QapAssert(ptr_lnk.IsValid());
    int SID=ptr_lnk.ptr->SaveID;
    QapAssert(Space.IsAllowed(SID));
    auto&item=Space[SID];
    QapAssert(this->ptr_lnk.ptr==item.ptr.ptr);
    QapAssert(this->ptr_lnk.type==item.ptr.type);
    return item;
  }EnvItem&get_lnk(TServerPtrSpace&Space)const;
};
struct SpaceMutator
{
  vector<EnvVoidPtr::ptr_t*> arr;
  int find_key_by_value(EnvVoidPtr::ptr_t*ptr);
  bool has_value(EnvVoidPtr::ptr_t*ptr);
};
class TServerPtrSpace
{
public:
  typedef TServerPtrSpace SelfClass;
public:
  vector<EnvItem> Arr;
public:
  void operator=(SelfClass&&Ref);
  TServerPtrSpace(SelfClass&&Ref);
  TServerPtrSpace();
  ~TServerPtrSpace();
public:
  void hack_clear();
  void clear();
public:
  static void make_linked(EnvItem&a,EnvItem&b);;
public:
  bool CheckServTID(int tid);
  bool CheckServSaveID(TServerPtr<IEsoteric>*pServ=nullptr)const;
  EnvItem&UnsafeAdd(const EnvVoidPtr&ptr);
  EnvItem&Insert(const EnvItem&item);
  EnvItem&InsertTo(int id,const EnvItem&item);
  EnvItem&UnsafeAdd(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr);
  EnvItem&AddExt(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr,const string&name="");
  void Del(EnvItem&item,bool hack_mode=false);
  void Del(TServerPtr<IEsoteric>*pServ,bool hack_mode=false);
  EnvVoidPtr::ptr_t*GetPtrByID(int id);
  EnvVoidPtr::ptr_t*GetAdvPtrByID(int id);
public:
  EnvItem&operator[](int index);
  const EnvItem&operator[](int index)const;
public:
  template<class TYPE>
  EnvItem&operator[](const TSelfPtr<TYPE>&index)
  {
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
  template<class TYPE>
  const EnvItem&operator[](const TSelfPtr<TYPE>&index)const
  {
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
public:
  bool IsAllowed(int index);
  bool IsSolved(int index);
  int size();
public:
  void resize(int count);
public:
  void Repack();
  void RepackV2(SelfClass&Out);
public:
  void Mutate(SpaceMutator&SM);
public:
  void CopyAdvFrom(SelfClass&Source);
  void CopyAdvFromV2(SelfClass&Source,SelfClass&BigSpace);
public:
  void Swap(int A,int B);
public:
  template<class TYPE>
  static void ClientMarker(TYPE&Space,TType*pType,void*pValue)
  {
    ::ClientMarker(Space,pType,pValue);
  }
public:
  template<class TYPE>
  void SolveDepends(TYPE&temp)
  {
    static_assert(std::is_same<DependsSolver,TYPE>::value,"error");
    temp.SolveDepends(*this);
  }
public:
  string GetListOfNoPassed(bool all);;
  bool CheckHidden();;
public:
  EnvItem*find_by_name(const string&name);
public:
  bool IsValid();
public:
  void reserve(int _Count);
public:
  void AddPointsFromSys();
  void AddPointsFromEnv(IEnvRTTI&Env);
  void AddPointsFrom(const TRawPtr&ptr);
  void UpdatePointsTypeFrom(const TRawPtr&ptr);
  template<class TYPE>
  struct weak_detail
  {
    static void AddPointsFromSys(TServerPtrSpace&Space)
    {
      EnvAdapter::GoSys(Space);
    }
    static void AddPointsFromEnv(TServerPtrSpace&Space,IEnvRTTI&Env)
    {
      EnvAdapter::GoEnv(Space,Env,EnvAdapter::TMetaTypePack(Env));
    }
    static void AddPointsFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      GrabServerPtr(Space,ptr.pType,ptr.pValue,true);
    }
    struct UnnamedStruct
    {
      typedef TServerPtrSpace TSpace;
      TSpace&Space;
      UnnamedStruct(TSpace&Space):Space(Space) {}
      void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
      {
        if (!Space.CheckServSaveID(&Serv))
        {
          QapDebugMsg("bad news");
          return;
        }
        auto&ex=Space[Serv.SaveID];
        QapAssert(elemType);
        if (ex.ptr.type==elemType)
        {
          QapAssert(elemType);
          QapAssert(!ex.ptr.type);
          return;
        }
        ex.ptr.type=elemType;
      }
    };
    static void UpdatePointsTypeFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      class TServerPtrTypeUpdater:public TSmartPtrVisitor::ICallBack
      {
      public:
        UnnamedStruct Field;
        TServerPtrTypeUpdater(TServerPtrSpace&Space):Field(Space) {}
      public:
        void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
        {
          Field.Visit(Serv,elemType);
        }
        void Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
        void Visit(THardClientPtr<IEsoteric>&A,TType*elemType) {}
        void Visit(TClientPtr<IEsoteric>&A) {}
        void Visit(THardClientPtr<IEsoteric>&A) {}
      };
      TServerPtrTypeUpdater Updater(Space);
      TSmartPtrVisitor SPG(Updater,ptr.pValue);
      ptr.pType->Use(SPG);
    }
  };
};
class TBigMetaTypePack
{
public:
public:
  typedef TBigMetaTypePack SelfClass;;
public:
  TType*pEnvType;;
  TType*pTType;;
  TType*pTTypeStruct;;
  TType*pTTypeSys;;
  TType*pDeclareType;;
  TType*pDeclareTypeStruct;;
  TType*pDeclareTypeSys;;;
  void DoReset();
  TBigMetaTypePack(const SelfClass&ref);
  TBigMetaTypePack();
  TBigMetaTypePack(IEnvRTTI&Env);
  template<class TYPE>TBigMetaTypePack(const TYPE&ref)
  {
    DoReset();
    oper_set(ref);
  }
  template<class QAP_RTTI>
  void prepare(QAP_RTTI&Env)
  {
    this->pEnvType=Sys$$<EnvType>::GetRTTI((IEnvRTTI&)Env);
    this->pTType=Sys$$<TType>::GetRTTI((IEnvRTTI&)Env);
    this->pTTypeStruct=Sys$$<TTypeStruct>::GetRTTI((IEnvRTTI&)Env);
    this->pTTypeSys=Sys$$<TTypeSys>::GetRTTI((IEnvRTTI&)Env);
    this->pDeclareType=Sys$$<DeclareType>::GetRTTI((IEnvRTTI&)Env);
    this->pDeclareTypeStruct=Sys$$<DeclareTypeStruct>::GetRTTI((IEnvRTTI&)Env);
    this->pDeclareTypeSys=Sys$$<DeclareTypeSys>::GetRTTI((IEnvRTTI&)Env);;
  }void oper_set(const SelfClass&ref);
  template<class TYPE>
  void oper_set(const TYPE&ref)
  {
    static_assert(std::is_same<std::remove_reference<decltype(this->pEnvType)>::type,std::remove_reference<decltype(ref.pEnvType)>::type>::value,"no way");;;;
    this->pEnvType=ref.pEnvType;;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");;;;
    this->pTType=ref.pTType;;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeStruct)>::type,std::remove_reference<decltype(ref.pTTypeStruct)>::type>::value,"no way");;;;
    this->pTTypeStruct=ref.pTTypeStruct;;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeSys)>::type,std::remove_reference<decltype(ref.pTTypeSys)>::type>::value,"no way");;;;
    this->pTTypeSys=ref.pTTypeSys;;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareType)>::type,std::remove_reference<decltype(ref.pDeclareType)>::type>::value,"no way");;;;
    this->pDeclareType=ref.pDeclareType;;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareTypeStruct)>::type,std::remove_reference<decltype(ref.pDeclareTypeStruct)>::type>::value,"no way");;;;
    this->pDeclareTypeStruct=ref.pDeclareTypeStruct;;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareTypeSys)>::type,std::remove_reference<decltype(ref.pDeclareTypeSys)>::type>::value,"no way");;;;
    this->pDeclareTypeSys=ref.pDeclareTypeSys;;;
  }
  void operator=(const SelfClass&ref);
};
class EnvAdapter
{
public:
  template<class TYPE>
  static TServerPtr<IEsoteric>*get(TSelfPtr<TYPE>&ref)
  {
    return (TServerPtr<IEsoteric>*)&ref.P;
  }
public:
  class TMetaTypePack
  {
  public:
  public:
    typedef TMetaTypePack SelfClass;;
  public:
    TType*pTType;;
    TType*pTTypeStruct;; ;
    void DoReset();
    TMetaTypePack(const SelfClass&ref);
    TMetaTypePack();
    TMetaTypePack(IEnvRTTI&Env);
    template<class TYPE>TMetaTypePack(const TYPE&ref)
    {
      DoReset();
      oper_set(ref);
    }
    template<class QAP_RTTI>
    void prepare(QAP_RTTI&Env)
    {
      this->pTType=Sys$$<TType>::GetRTTI((IEnvRTTI&)Env);
      this->pTTypeStruct=Sys$$<TTypeStruct>::GetRTTI((IEnvRTTI&)Env); ;
    }void oper_set(const SelfClass&ref);
    template<class TYPE>
    void oper_set(const TYPE&ref)
    {
      static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");;;;
      this->pTType=ref.pTType;;
      static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeStruct)>::type,std::remove_reference<decltype(ref.pTTypeStruct)>::type>::value,"no way");;;;
      this->pTTypeStruct=ref.pTTypeStruct;; ;
    }
    void operator=(const SelfClass&ref);
  };
public:
  TType*FindTypeByFactory(IEnvRTTI&Env,IFactory*pFactory);
  TType*FindTypeByFactoryFast(IEnvRTTI&Env,TServerPtrSpace&Space,IFactory*pFactory);
public:
  static void GoV3(TServerPtrSpace&Space,IEnvRTTI&Env);
  static void GoV2(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack);
  static void GoSys(TServerPtrSpace&Space);
  static void GoFactory(TServerPtrSpace&Space);
  static void GoCppIO(TServerPtrSpace&Space);
  static void GoBinIO(TServerPtrSpace&Space);
  static void GoVectorAPI(TServerPtrSpace&Space);
  static void GoEnv(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack);
  static void FixEnvType(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack);
  static bool IsFactoryEqual(TType*p,TType*b);
  static bool IsBasedOn(TType*p,TType*base);
};
struct IQapStream
{
  virtual bool Load();
  virtual bool Save();
  virtual QapIO&GetContent()=0;
};
struct TQapFileStream:public IQapStream
{
  TDataIO IO;
  string fn;
  bool readonly;
  TQapFileStream(const string&fn,bool readonly=true);
  bool Load();
  bool Save();
  QapIO&GetContent();;
};
struct TQapMemoryStream:public IQapStream
{
  TDataIO IO;
  TQapMemoryStream();
  bool Load();
  bool Save();
  QapIO&GetContent();;
};
struct TDataIOStream:public IQapStream
{
  TDataIO&IO;
  TDataIOStream(TDataIO&IO);
  bool Load();
  bool Save();
  QapIO&GetContent();;
};
struct IQapRawObject
{
  virtual TRawPtr&Get(IEnvRTTI&Env)=0;
};
struct TQapRawObject:public IQapRawObject
{
  TRawPtr raw_ptr;
  TQapRawObject(const TRawPtr&ptr);
  TQapRawObject(TType*pType,void*pValue);
  TRawPtr&Get(IEnvRTTI&Env);
};
template<class TYPE>
struct TQapRawUberObject:public IQapRawObject
{
  TRawPtr raw_ptr;
  TQapRawUberObject(TYPE&value)
  {
    raw_ptr.pType=nullptr;
    raw_ptr.pValue=&value;
  }
  TRawPtr&Get(IEnvRTTI&Env)
  {
    TType*pType=Sys$$<TYPE>::GetRTTI(Env);
    raw_ptr.pType=pType;
    return raw_ptr;
  }
};
template<class TYPE>
TQapRawUberObject<TYPE> QapRawUberObject(TYPE&value)
{
  TQapRawUberObject<TYPE> tmp(value);
  return std::move(tmp);
}
class DeclareType;
class DeclareTypeSys;
class DeclareTypeSelfPtr;
class DeclareTypeAutoPtr;
class DeclareTypeWeakPtr;
class DeclareTypeHardPtr;
class DeclareTypeVoidPtr;
class DeclareTypeFieldPtr;
class DeclareTypeVector;
class DeclareTypeArray;
class DeclareTypeStruct;
class IDeclareVisitorRTTI
{
public:
  virtual void Do(DeclareTypeSys*p)=0;
  virtual void Do(DeclareTypeSelfPtr*p)=0;
  virtual void Do(DeclareTypeAutoPtr*p)=0;
  virtual void Do(DeclareTypeWeakPtr*p)=0;
  virtual void Do(DeclareTypeHardPtr*p)=0;
  virtual void Do(DeclareTypeVoidPtr*p)=0;
  virtual void Do(DeclareTypeFieldPtr*p)=0;
  virtual void Do(DeclareTypeVector*p)=0;
  virtual void Do(DeclareTypeArray*p)=0;
  virtual void Do(DeclareTypeStruct*p)=0;
public:
  template<class TYPE,class Visitor>
  struct Is:public Visitor
  {
    TYPE*ptr;
    Is():ptr(nullptr) {}
public:
    template<class U>static TYPE*get(U*p)
    {
      return nullptr;
    }
    template<>static TYPE*get<TYPE>(TYPE*p)
    {
      return p;
    }
public:
    void Do(DeclareTypeSys*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeSelfPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeAutoPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeWeakPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeHardPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeVoidPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeFieldPtr*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeVector*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeArray*p)
    {
      ptr=get(p);
    }void Do(DeclareTypeStruct*p)
    {
      ptr=get(p);
    }
  };
  template<class TYPE>
  static TYPE*UberCast(DeclareType*p)
  {
    if (!p)return nullptr;
    Is<TYPE,IDeclareVisitorRTTI> IS;
    p->Use(IS);
    return IS.ptr;
  }
};
template<class TYPE>
struct QapDeclareDetail
{
  static string GetFullName(const DeclareType*ptr)
  {
    DeclareDetail::GetFullName GFN;
    DeclareType*p=(DeclareType*)ptr;
    p->Use(GFN);
    return GFN.fullname;
  }
  static DeclareType*GetSubType(const DeclareType*ptr)
  {
    auto*p=DeclareTypeStruct::UberCast((DeclareType*)ptr);
    return p?p->SubType.get():nullptr;
  }
  static bool IsBasedOn(const DeclareType*ptr,const DeclareType*A)
  {
    if (ptr==A)return true;
    auto*subtype=ptr->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};
class DeclareType
{
public:
  ;
public:
  typedef DeclareType SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  DeclareType(const DeclareType&)=delete;
  DeclareType();;
public:
  DeclareType(DeclareType&&_Right);
  void operator=(DeclareType&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareType";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  virtual void Use(IDeclareVisitorRTTI&);
  string GetFullName()const;
  DeclareType*GetSubType()const;
  bool IsBasedOn(const DeclareType*A)const;
};
class DeclareTypeSys:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeSys SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  string FullName;;
public:
  void DoReset();
public:
  DeclareTypeSys(const DeclareTypeSys&)=delete;
  DeclareTypeSys();;
public:
  DeclareTypeSys(DeclareTypeSys&&_Right);
  void operator=(DeclareTypeSys&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeSys";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"FullName",int(&(((SelfClass*)nullptr)->*(&SelfClass::FullName))),"SET","\"unnamed\"");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeSelfPtr:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeSelfPtr SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  TWeakPtr<DeclareType> ElementType;;
public:
  void DoReset();
public:
  DeclareTypeSelfPtr(const DeclareTypeSelfPtr&)=delete;
  DeclareTypeSelfPtr();;
public:
  DeclareTypeSelfPtr(DeclareTypeSelfPtr&&_Right);
  void operator=(DeclareTypeSelfPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeSelfPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeAutoPtr:public DeclareType
{
  ;
public:
  typedef DeclareTypeAutoPtr SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  TWeakPtr<DeclareType> ElementType;;
public:
  void DoReset();
public:
  DeclareTypeAutoPtr(const DeclareTypeAutoPtr&)=delete;
  DeclareTypeAutoPtr();;
public:
  DeclareTypeAutoPtr(DeclareTypeAutoPtr&&_Right);
  void operator=(DeclareTypeAutoPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeAutoPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeWeakPtr:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeWeakPtr SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  TWeakPtr<DeclareType> ElementType;;
public:
  void DoReset();
public:
  DeclareTypeWeakPtr(const DeclareTypeWeakPtr&)=delete;
  DeclareTypeWeakPtr();;
public:
  DeclareTypeWeakPtr(DeclareTypeWeakPtr&&_Right);
  void operator=(DeclareTypeWeakPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeWeakPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeHardPtr:public DeclareType
{
  ;
public:
  typedef DeclareTypeHardPtr SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  TWeakPtr<DeclareType> ElementType;;
public:
  void DoReset();
public:
  DeclareTypeHardPtr(const DeclareTypeHardPtr&)=delete;
  DeclareTypeHardPtr();;
public:
  DeclareTypeHardPtr(DeclareTypeHardPtr&&_Right);
  void operator=(DeclareTypeHardPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeHardPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeFieldPtr:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeFieldPtr SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
public:
  void DoReset();
public:
  DeclareTypeFieldPtr(const DeclareTypeFieldPtr&)=delete;
  DeclareTypeFieldPtr();;
public:
  DeclareTypeFieldPtr(DeclareTypeFieldPtr&&_Right);
  void operator=(DeclareTypeFieldPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeFieldPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeVoidPtr:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeVoidPtr SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
public:
  void DoReset();
public:
  DeclareTypeVoidPtr(const DeclareTypeVoidPtr&)=delete;
  DeclareTypeVoidPtr();;
public:
  DeclareTypeVoidPtr(DeclareTypeVoidPtr&&_Right);
  void operator=(DeclareTypeVoidPtr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeVoidPtr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeVector:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeVector SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  TWeakPtr<DeclareType> ElementType;;
public:
  void DoReset();
public:
  DeclareTypeVector(const DeclareTypeVector&)=delete;
  DeclareTypeVector();;
public:
  DeclareTypeVector(DeclareTypeVector&&_Right);
  void operator=(DeclareTypeVector&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeVector";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareTypeArray:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeArray SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  TWeakPtr<DeclareType> ElementType;;
  int Size;;
public:
  void DoReset();
public:
  DeclareTypeArray(const DeclareTypeArray&)=delete;
  DeclareTypeArray();;
public:
  DeclareTypeArray(DeclareTypeArray&&_Right);
  void operator=(DeclareTypeArray&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeArray";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
};
class DeclareMember
{
public:
  ;
public:
  typedef DeclareMember SelfClass;;
public:
  string Name;;
  TWeakPtr<DeclareType> Type;;
  string Mode;;
  string Value;;
public:
  void DoReset();
public:
  DeclareMember(const DeclareMember&)=delete;
  DeclareMember();;
public:
  DeclareMember(DeclareMember&&_Right);
  void operator=(DeclareMember&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareMember";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");;
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mode))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Value",int(&(((SelfClass*)nullptr)->*(&SelfClass::Value))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool IsEqual(SelfClass&other);
};
class DeclareTypeStruct:public DeclareType
{
public:
  ;
public:
  typedef DeclareTypeStruct SelfClass;
public:
  typedef DeclareType ParentClass;;
public:
  string Name;;
  TWeakPtr<DeclareType> SubType;;
  TWeakPtr<DeclareType> OwnType;;
  vector<DeclareMember> Members;;
public:
  void DoReset();
public:
  DeclareTypeStruct(const DeclareTypeStruct&)=delete;
  DeclareTypeStruct();;
public:
  DeclareTypeStruct(DeclareTypeStruct&&_Right);
  void operator=(DeclareTypeStruct&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="DeclareTypeStruct";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");;
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"OwnType",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnType))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<DeclareMember>>::GetRTTI(RTTI),"Members",int(&(((SelfClass*)nullptr)->*(&SelfClass::Members))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Use(IDeclareVisitorRTTI&A);
  static SelfClass*UberCast(DeclareType*ptr);;
public:
  bool TestField(const DeclareMember&it,int depth=0);
  DeclareMember*GetNearSelf();
  void AddField(DeclareMember&&field);
  void AddMember(DeclareType*MemType,const string&MemName,const string&Mode,const string&Value);
};
class DeclareDetail
{
public:
  class StructTools
  {
  public:
    struct field_cmp_result_item
    {
      string fna;
      string fnb;
      int ida;
      int idb;
      void SetToDef();
    };
    static vector<field_cmp_result_item> CompareFieldsLists(const vector<DeclareMember>&A,const vector<DeclareMember>&B);
    static void Filter_RemoveEqual(vector<field_cmp_result_item>&arr);
    static string CompareFieldsLists_ToString(const vector<field_cmp_result_item>&arr);
  };
public:
  class GetFullName:public IDeclareVisitorRTTI
  {
  public:
    string fullname;
  public:
    void Do(DeclareTypeSys*p);
    void Do(DeclareTypeSelfPtr*p);
    void Do(DeclareTypeAutoPtr*p);
    void Do(DeclareTypeWeakPtr*p);
    void Do(DeclareTypeHardPtr*p);
    void Do(DeclareTypeVoidPtr*p);
    void Do(DeclareTypeFieldPtr*p);
    void Do(DeclareTypeVector*p);
    void Do(DeclareTypeArray*p);
    void Do(DeclareTypeStruct*p);
  };
  class GetSubType:public IDeclareVisitorRTTI
  {
  public:
    DeclareType*pValue;
    GetSubType();
  public:
    void Do(DeclareTypeSys*p);
    void Do(DeclareTypeSelfPtr*p);
    void Do(DeclareTypeAutoPtr*p);
    void Do(DeclareTypeWeakPtr*p);
    void Do(DeclareTypeHardPtr*p);
    void Do(DeclareTypeVoidPtr*p);
    void Do(DeclareTypeFieldPtr*p);
    void Do(DeclareTypeVector*p);
    void Do(DeclareTypeStruct*p);
  };
  template<class TSPACE>
  class IsEqualTo:public IDeclareVisitorRTTI
  {
  public:
    TSPACE&Space;
    bool Result;
    DeclareType*pValue;
    bool Mute;
    IsEqualTo(TSPACE&Space):Space(Space),Result(false),pValue(nullptr),Mute(false) {}
  public:
    struct EqualDetail
    {
      static bool Equal(TSPACE&Space,...)
      {
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeSys*pA,DeclareTypeSys*pB,bool Mute)
      {
        return pA->FullName==pB->FullName;
      }
      static bool Equal(TSPACE&Space,DeclareTypeSelfPtr*pA,DeclareTypeSelfPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeAutoPtr*pA,DeclareTypeAutoPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeWeakPtr*pA,DeclareTypeWeakPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeHardPtr*pA,DeclareTypeHardPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVoidPtr*pA,DeclareTypeVoidPtr*pB,bool Mute)
      {
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeFieldPtr*pA,DeclareTypeFieldPtr*pB,bool Mute)
      {
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVector*pA,DeclareTypeVector*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeArray*pA,DeclareTypeArray*pB,bool Mute)
      {
        if (pA->Size!=pB->Size)return false;
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeStruct*pA,DeclareTypeStruct*pB,bool Mute)
      {
        string fna=pA->GetFullName();
        string fnb=pB->GetFullName();
        bool flag=fna==fnb;
        if (!flag)return false;
        auto&A=pA->Members;
        auto&B=pB->Members;
        if (A.size()!=B.size())
        {
          string msg="type : \""+fna+"\"\n";
          msg+="A.size = "+IToS(A.size())+"\n";
          msg+="B.size = "+IToS(B.size())+"\n";
          if (!Mute)QapDebugMsg(msg);
          auto detail_result=StructTools::CompareFieldsLists(A,B);
          StructTools::Filter_RemoveEqual(detail_result);
          auto str_detail_result=StructTools::CompareFieldsLists_ToString(detail_result);
          if (!Mute)QapDebugMsg(msg+"\n"+str_detail_result);
          flag=false;
        }
        for (int i=0;i<std::min(A.size(),B.size());i++)
        {
          auto&a=A[i];
          auto&b=B[i];
          bool f[]=
          {
            a.Name==b.Name,
            a.Mode==b.Mode,
            a.Value==b.Value,
          };
          bool flag=true;
          for (int j=0;j<lenof(f);j++)
          {
            flag=flag&&f[j];
          }
          if (flag)
          {
            IsEqualTo<TSPACE> other(Space);
            other.Mute=Mute;
            other.pValue=a.Type.get();
            b.Type.get()->Use(other);
            flag=flag&&other.Result;
          }
          if (!flag)
          {
            if (!Mute)QapDebugMsg("type : \""+fna+"\"");
            return false;
          }
        }
        return flag;
      }
    };
    template<class TYPE>
    class IsEqual:public IDeclareVisitorRTTI
    {
    public:
      TSPACE&Space;
      TYPE*pInput;
      bool Result;
      bool Mute;
      IsEqual(TSPACE&Space):Space(Space),Result(false),pInput(nullptr),Mute(false) {}
    public:
      void Do(DeclareTypeSys*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeSelfPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeAutoPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeWeakPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeHardPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVoidPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeFieldPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVector*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeArray*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeStruct*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
    };
    template<class TYPE>
    static bool IsEqualFunc(TSPACE&Space,TYPE*pInput,DeclareType*pValue,bool Mute)
    {
      static_assert(std::is_same<TSPACE,TServerPtrSpace>::value,"renamed?");
      TServerPtrSpace&space=Space;
      if (pInput==pValue)return true;
      bool fA=space.IsAllowed(pInput->Self.P.SaveID);
      bool fB=space.IsAllowed(pValue->Self.P.SaveID);
      if (!fA||!fB)
      {
        QapDebugMsg("no way");
        return false;
      }
      auto&eA=space[pInput->Self];
      auto&eB=space[pValue->Self];
      EnvItem&A=eA;
      EnvItem&B=eB;
      bool f[]=
      {
        A.ptr_lnk.IsValid(),
        B.ptr_lnk.IsValid(),
        A.ptr.get()==(void*)pInput,
        B.ptr.get()==(void*)pValue,
      };
      QapAssert(f[2]&&f[3]);
      if (f[0]&&f[1])
      {
        bool g0=A.ptr_lnk.get()==B.ptr.get();
        bool g1=B.ptr_lnk.get()==A.ptr.get();
        QapAssert(g0==g1);
        return g0&&g1;
      }
      if (!f[0]&&!f[1])
      {
        QapAssert(!A.system&&!B.system);
        A.system=true;
        B.system=true;
        IsEqual<TYPE> Is(space);
        Is.pInput=pInput;
        Is.Mute=Mute;
        pValue->Use(Is);
        A.system=false;
        B.system=false;
        if (Is.Result||Mute)
        {
          A.ptr_lnk=B.ptr;
          B.ptr_lnk=A.ptr;
        }
        return Is.Result;
      }
      return false;
    }
    static bool IsEqualFuncEx(TSPACE&Space,DeclareType*pInput,DeclareType*pValue)
    {
      IsEqualTo<TSPACE> next(Space);
      next.pValue=pValue;
      pInput->Use(next);
      return next.Result;
    }
    void Do(DeclareTypeSys*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeHardPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVector*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeArray*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeStruct*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
  };
};
class TSmartPtrVisitor:public IVisitorRTTI
{
public:
  class ICallBack
  {
  public:
    virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A)=0;
  };
public:
  ICallBack&CB;
  void*pValue;
  typedef TSmartPtrVisitor SelfClass;
  TSmartPtrVisitor(ICallBack&CB,void*pValue);
  TSmartPtrVisitor(TSmartPtrVisitor&owner,void*pValue);
public:
  void Do(TTypeStruct*p);
  void Do(TTypeSys*p);
  void Do(TTypeVector*p);
  void Do(TTypeArray*p);
  virtual void Do(TTypeSelfPtr*p);
  virtual void Do(TTypeAutoPtr*p);
  virtual void Do(TTypeWeakPtr*p);
  virtual void Do(TTypeHardPtr*p);
  virtual void Do(TTypeVoidPtr*p);
  virtual void Do(TTypeFieldPtr*p);
  virtual void Do(TTypeFactory*p);
public:
};
class TClientPtrCounter:public TSmartPtrVisitor::ICallBack
{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrCounter(IEnvRTTI&Env,TServerPtrSpace&Space);
public:
  void prepare(IEnvRTTI&Env);
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A);
  void Visit(THardClientPtr<IEsoteric>&A);
public:
  template<template<class> class SmartPtr,class TYPE>
  inline static SmartPtr<IEsoteric>&get(SmartPtr<TYPE>&input)
  {
    static_assert(
      std::is_same<SmartPtr,TClientPtr>::value||
      std::is_same<SmartPtr,THardClientPtr>::value,"error"
    );
    return (SmartPtr<IEsoteric>&)input;
  }void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr);
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if (!A)return;
    DoVisitSaveID(A.ptr->SaveID,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if (!A)return;
    DoVisitSaveID(A.ptr->SaveID,false,nullptr);
  }
};
class TServerPtrGraber:public TSmartPtrVisitor::ICallBack
{
public:
  bool automark;
  int SkipCount;
  int AddCount;
  TServerPtrSpace&Space;
  TServerPtrGraber(TServerPtrSpace&Space,bool automark);
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A);
  virtual void Visit(THardClientPtr<IEsoteric>&A);
};
class TServerPtrCounter:public TSmartPtrVisitor::ICallBack
{
public:
  int&count;
  TServerPtrCounter(int&count);
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A);
  virtual void Visit(THardClientPtr<IEsoteric>&A);
};
class TClientPtrSolver:public TSmartPtrVisitor::ICallBack
{
public:
  struct TwoMetaType
  {
    TType*pTType;
    TType*pDeclareType;
    TwoMetaType(const TwoMetaType&Ref);
    TwoMetaType();
    TwoMetaType(IEnvRTTI&Env);
    template<class TYPE>
    TwoMetaType(TYPE&ref):pTType(ref.pTType),pDeclareType(ref.pDeclareType)
    {
      static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");;
      static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareType)>::type,std::remove_reference<decltype(ref.pDeclareType)>::type>::value,"no way");;
    }void prepare(IEnvRTTI&Env);
    void oper_set(const TwoMetaType&Ref);
    void operator=(const TwoMetaType&Ref);
  };
public:
  typedef TServerPtrSpace TSpace;
  TSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrSolver(TSpace&Space,const TwoMetaType&tmt);
public:
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A);
  void Visit(THardClientPtr<IEsoteric>&A);
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr);
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
};
class TClientPtrKiller:public TSmartPtrVisitor::ICallBack
{
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A);
  virtual void Visit(THardClientPtr<IEsoteric>&A);
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A)
  {
    if (!A)return;
    A=nullptr;
  }
};
class TDumpPtrSolver:public TSmartPtrVisitor::ICallBack
{
public:
  typedef TServerPtrSpace TSpace;
  TSpace&ST_Space;
  TSpace&LT_Space;
  TDumpPtrSolver(TSpace&ST_Space,TSpace&LT_Space);
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A);
  virtual void Visit(THardClientPtr<IEsoteric>&A);
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr);
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if (!p)return;
    A=p;
  }
};
class TClientPtrVisitor:public TSmartPtrVisitor::ICallBack
{
public:
  struct ICallBack
  {
    template<class TYPE>
    void DoVisitServerPtr(TServerPtr<TYPE>&Serv,bool safe,TType*elemType)
    {
      DoVisitServerPtr((TServerPtr<IEsoteric>*)&Serv,safe,elemType);
    }virtual void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe=false,TType*elemType=nullptr);
  };
public:
  ICallBack&CB;
  TClientPtrVisitor(ICallBack&CB);
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  virtual void Visit(TClientPtr<IEsoteric>&A);
  virtual void Visit(THardClientPtr<IEsoteric>&A);
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,false,nullptr);
  }
};
class THardClientSpace
{
public:
  vector<THardClientPtr<IEsoteric>*> Arr;
  void Do();
};
class THardClientPtrGraber:public TSmartPtrVisitor::ICallBack
{
public:
  typedef THardClientSpace TSpace;
  TSpace&Space;
  THardClientPtrGraber(TSpace&Space);
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType);
  void Visit(TClientPtr<IEsoteric>&A);
  void Visit(THardClientPtr<IEsoteric>&A);
public:
};
void ClientMarker(TSmartPtrVisitor::ICallBack&ClientCounter,TType*pType,void*pValue);
class TServerPtrGraberWithRealType:public IVisitorRTTI
{
public:
  typedef TServerPtrGraberWithRealType SelfClass;
  typedef TServerPtrSpace TSpace;
public:
  TSpace&Space;
  void*pValue;
  vector<void*> values;
  vector<TType*> types;
  bool automark;
  int AddCount;
  int SkipCount;
  TServerPtrGraberWithRealType(TSpace&Space,TType*pType,void*pValue,bool automark);
public:
  void push(TType*pType);
  void pop(TType*pType);
  void ptr_push(void*ptr);
  void ptr_pop(void*ptr);
public:
  void Do(TTypeStruct*p);
  void Do(TTypeSys*p);
  void Do(TTypeFactory*p);
  void Do(TTypeVector*p);
  void Do(TTypeArray*p);
  void Do(TTypeSelfPtr*p);
  void Do(TTypeAutoPtr*p);
  void Do(TTypeWeakPtr*p);
  void Do(TTypeHardPtr*p);
  void Do(TTypeVoidPtr*p);
  void Do(TTypeFieldPtr*p);
};
void GrabServerPtr(TServerPtrSpace&Space,TType*pType,void*pValue,bool automark);
class TClientPtrVcbCounter:public TClientPtrVisitor::ICallBack
{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrVcbCounter(IEnvRTTI&Env,TServerPtrSpace&Space);
public:
  void prepare(IEnvRTTI&Env);
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr);
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType);
};
class TClientPtrVcbCounter20120828:public TClientPtrVisitor::ICallBack
{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  bool firstmode;
  TClientPtrVcbCounter20120828(IEnvRTTI&Env,TServerPtrSpace&Space);
public:
  void prepare(IEnvRTTI&Env);
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr);
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType);
};
class DependsSolver
{
public:
  typedef TServerPtrSpace TSpace;
  TClientPtrVisitor&CPC;
  TType*pTType;
  TType*pDeclareType;
  vector<int> Arr;
  bool fullprocess;
  DependsSolver(IEnvRTTI&Env,TClientPtrVisitor&CPC);
  void prepare(TSpace&Space,bool force);
  void pass(TSpace&Space,const TRawPtr&ptr);
  TRawPtr get(const EnvVoidPtr&ptr);
  void step(TSpace&Space);
  void SolveDepends(TSpace&Space,bool fullprocess=true);
};
template<class TYPE>
class Sys$$<vector<TYPE>>
{
public:
  typedef TTypeVector metatype;
  typedef vector<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="vector";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->SizeType=Sys$$<IVectorAPI::SizeType>::GetRTTI(RTTI);
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->VecAPI=TVectorAPI<elemtype>::Get();
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "vector<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE,size_t Count>
class Sys$$<array<TYPE,Count>>
{
public:
  typedef TTypeArray metatype;
  typedef array<TYPE,Count> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="array";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->Size=Count;
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "array<"+Sys$$<TYPE>::GetFullName()+","+IToS(Count)+">";
  }
};
template<class TYPE>
class Sys$$<TFactory<TYPE>>
{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFactory";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->SubType=detail::GetParentClassOf<type>::GetRTTI(RTTI);
    typedef TSelfPtr<IFactory> SmartType;
    {
      typedef decltype((((type*)nullptr)->*(&type::Self))) realtype;
      typedef std::remove_reference<realtype>::type fieldtype;
      static_assert(std::is_same<SmartType,fieldtype>::value,"ok");
    }
    Info->SmartType=Sys$$<SmartType>::GetRTTI(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFactory<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TFactory<TFactory<TYPE>>>
{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TFactory<TYPE>> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    QapDebugMsg("WTF?");
    static string Name="TFactory";
    static metatype sys;
    static bool flag=true;
    if (flag)
    {
      sys.Info.Name=Name;
      sys.Info.Size=sizeof(Name);
      flag=false;
    }
    return &sys;
  }
  static string GetFullName()
  {
    return "TFactory<TFactory<"+Sys$$<TYPE>::GetFullName()+">>";
  }
};
template<class TYPE>
class Sys$$<TSelfPtr<TYPE>>
{
public:
  typedef TTypeSelfPtr metatype;
  typedef TSelfPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TSelfPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TSelfPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TAutoPtr<TYPE>>
{
public:
  typedef TTypeAutoPtr metatype;
  typedef TAutoPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TAutoPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TAutoPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TWeakPtr<TYPE>>
{
public:
  typedef TTypeWeakPtr metatype;
  typedef TWeakPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TWeakPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TWeakPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<THardPtr<TYPE>>
{
public:
  typedef TTypeHardPtr metatype;
  typedef THardPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="THardPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "THardPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<>
class Sys$$<TVoidPtr>
{
public:
  typedef TTypeVoidPtr metatype;
  typedef TVoidPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TVoidPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TVoidPtr";
  }
};
template<>
class Sys$$<TFieldPtr>
{
public:
  typedef TTypeFieldPtr metatype;
  typedef TFieldPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFieldPtr";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFieldPtr";
  }
};
template<>
class TTxtIO<uint>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef uint type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=std::to_string(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    val=std::stoul(s);
  }
};
template<>
class TTxtIO<int>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef int type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    val=SToI(s);
  }
};
template<>
class TTxtIO<real>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef real type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    SToF(s,val);
  }
};
template<>
class TTxtIO<float>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef float type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    real tmp;
    SToF(s,tmp);
    val=tmp;
  }
};
template<>
class TTxtIO<bool>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef bool type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=BToS(val);
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    SToB(s,val);
  }
};
template<>
class TTxtIO<char>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef char type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    if (CppString::IsValidCppChar(val))
    {
      char out[4]={'\'',val,'\'',0};
      s=out;
    }
    else
    {
      string tmp=CToH_raw(val);
      s="'\\x"+tmp+"'";
    }
  }
  void Load(string&s,void*p)
  {
    QapDebugMsg("under construction");
    return;
    type&val=*(type*)p;
    SToC(s,val);
  }
};
template<>
class TTxtIO<uchar>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef uchar type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p)
  {
    QapDebugMsg("under construction");
    return;
    type&val=*(type*)p;
    val=SToI(s);
  }
};
template<>
class TBinIO<string>:public IBinIO
{
public:
  typedef IBinIO ParentClass;
  typedef string type;
  typedef TBinIO<type> SelfClass;
public:
  void Save(QapIO&IO,void*p)
  {
    type&val=*(type*)p;
    int count=val.size();
    IO.SavePOD(&count,sizeof(count));
    if (!count)return;
    IO.SavePOD(&val[0],count);
  }
  void Load(QapIO&IO,void*p)
  {
    type&val=*(type*)p;
    int count=0;
    if (!IO.TryLoad(sizeof(count)))
    {
      IO.Crash();
      return;
    }
    IO.LoadPOD(&count,sizeof(count));
    if (!IO.TryLoad(count))
    {
      IO.Crash();
      return;
    }
    val.resize(count);
    if (!count)return;
    IO.LoadPOD(&val[0],count);
  }
public:
  void Copy(void*pOut,void*pInp)
  {
    string&out=*(string*)pOut;
    string&inp=*(string*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB)
  {
    string&a=*(string*)pA;
    string&b=*(string*)pB;
    return a==b;
  }
};
template<>
class TTxtIO<string>:public ITxtIO
{
public:
  typedef ITxtIO ParentClass;
  typedef string type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p)
  {
    type&val=*(type*)p;
    CppString cs=val;
    s="\""+cs.data+"\"";
  }
  void Load(string&s,void*p)
  {
    type&val=*(type*)p;
    if (s.size()<2)
    {
      QapDebugMsg("WTF?");
      return;
    }
    bool flag1=s.front()=='"';
    bool flag2=s.back()=='"';
    if (!flag1||!flag2)
    {
      QapDebugMsg("WTF?");
      return;
    }
    val=s.substr(1,int(s.size())-2);
    BinString bs=val;
    val=bs.data;
  }
};
template<> class Sys$$<uint>
{
public:
  typedef TTypeSys metatype;
  typedef uint type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="uint";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "uint";
  }
};;
template<> class Sys$$<int>
{
public:
  typedef TTypeSys metatype;
  typedef int type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="int";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "int";
  }
};;
template<> class Sys$$<real>
{
public:
  typedef TTypeSys metatype;
  typedef real type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="real";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "real";
  }
};;
template<> class Sys$$<float>
{
public:
  typedef TTypeSys metatype;
  typedef float type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="float";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "float";
  }
};;
template<> class Sys$$<bool>
{
public:
  typedef TTypeSys metatype;
  typedef bool type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="bool";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "bool";
  }
};;
template<> class Sys$$<char>
{
public:
  typedef TTypeSys metatype;
  typedef char type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="char";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "char";
  }
};;
template<> class Sys$$<uchar>
{
public:
  typedef TTypeSys metatype;
  typedef uchar type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="uchar";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "uchar";
  }
};;
template<> class Sys$$<string>
{
public:
  typedef TTypeSys metatype;
  typedef string type;
  template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=nullptr;
    string Name="string";
    if (RTTI.Register<type>(Info,Name))return Info;
    Info->BinIO=THeadBinIO<type>::Get();
    Info->TxtIO=THeadCppIO<type>::Get();
    Info->Info.Size=sizeof(type);
    RTTI.OnRegEnd(Info);
    return Info;
  };
  static string GetFullName()
  {
    return "string";
  }
};;;
class TPrinter
{
public:
  string&s;
  string indent;
  string sep;
  TPrinter(string&s);
public:
  virtual void Indent();
  virtual void Outdent();
  virtual void Print(string const&data);
};
class TMessage
{
public:
  ;
public:
  typedef TMessage SelfClass;;
public:
  TWeakPtr<TType> type;;
  int mode;;
public:
  void DoReset();
public:
  TMessage(const TMessage&)=delete;
  TMessage();;
public:
  TMessage(TMessage&&_Right);
  void operator=(TMessage&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TMessage";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TWeakPtr<TType>>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::mode))),"SET","mmRet");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  enum TMode
  {
    mmBeg,
    mmRet,
    mmEnd
  };
};
class EnvTypeHolder
{
public:
  ;
public:
  typedef EnvTypeHolder SelfClass;;
public:
  string FullName;;
  TProduct Type;;
  TProduct Factory;;
public:
  void DoReset();
public:
  EnvTypeHolder(const EnvTypeHolder&)=delete;
  EnvTypeHolder();;
public:
  EnvTypeHolder(EnvTypeHolder&&_Right);
  void operator=(EnvTypeHolder&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="EnvTypeHolder";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"FullName",int(&(((SelfClass*)nullptr)->*(&SelfClass::FullName))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TProduct>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TProduct>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void hack_move(TProduct&out,TRTTIProduct&inp);
  void eat(EnvType&item);
  void boom();
  TType*GetType();
  IFactory*GetFactory();
};
class TEnvRTTI:public IEnvRTTI
{
public:
  ;
public:
  typedef TEnvRTTI SelfClass;
public:
  typedef IEnvRTTI ParentClass;;
public:
  vector<EnvType> Arr;;
  THardPtr<IAllocator> Alloc;;
  UniqueID ID;;
  vector<TMessage> messages;;
  THardPtr<IEnvRTTI> OwnerEnv;;
public:
  void DoReset();
public:
  TEnvRTTI(const TEnvRTTI&)=delete;
  TEnvRTTI();;
public:
  TEnvRTTI(TEnvRTTI&&_Right);
  void operator=(TEnvRTTI&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TEnvRTTI";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<EnvType>>::GetRTTI(RTTI),"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IAllocator>>::GetRTTI(RTTI),"Alloc",int(&(((SelfClass*)nullptr)->*(&SelfClass::Alloc))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<UniqueID>::GetRTTI(RTTI),"ID",int(&(((SelfClass*)nullptr)->*(&SelfClass::ID))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<TMessage>>::GetRTTI(RTTI),"messages",int(&(((SelfClass*)nullptr)->*(&SelfClass::messages))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<THardPtr<IEnvRTTI>>::GetRTTI(RTTI),"OwnerEnv",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnerEnv))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void SysHasSelf();
public:
  string GetTypeFullNames();
  void PrintLog(const string&fn="outlog.cpp");
  void OnRegBeg(TType*Info);;
  void OnRegRet(TType*Info);;
  void OnRegEnd(TType*Info);;
public:
  IAllocator*GetAlloc();
  virtual int RegInfo(TAutoPtr<TType>&&_Right);
  virtual EnvType&GetEnvTypeById(int id);
  virtual vector<EnvType>&GetArr();
  ~TEnvRTTI();
public:
  IEnvRTTI*GetOwnerEnv();
public:
  void update();
  bool IsValid();
  void clear();
  static bool IsLegalChar(const unsigned char&c);
  static string string2xml(const string&str);
  void PrintCur();
  static void add_sniper_job(THardClientSpace&Space,TRawPtr&raw_ptr);
  void unlink();
};
TType*FindTypeByFullName(IEnvRTTI&Env,const string&FullName);
class QapBitmapInfo
{
public:
  BITMAPINFO BI;
  BITMAPINFOHEADER&BH;
public:
  QapBitmapInfo(int W,int H);
};
class FastBMP
{
public:
  int W;
  int H;
  HDC MDC;
  QapColor*mem;
  HBITMAP BMP;
public:
  void Init(HDC DC,int W,int H);
  void Free();
};
#pragma once

struct QapMat4:public D3DMATRIX
{
public:
  QapMat4();
  QapMat4(
    const float m00, const float m01, const float m02, const float m03,
    const float m10, const float m11, const float m12, const float m13,
    const float m20, const float m21, const float m22, const float m23,
    const float m30, const float m31, const float m32, const float m33
  );
public:
  friend QapMat4 operator+(const QapMat4&m,const QapMat4&n);
  friend QapMat4 operator-(const QapMat4&m,const QapMat4&n);
  friend QapMat4 operator-(const QapMat4&m);
  friend QapMat4 operator*(const QapMat4&m,const QapMat4&n);
  friend QapMat4 operator*(const QapMat4 &m,float x);
};
QapMat4 Transpose(const QapMat4&m);
QapMat4 RotateZ(float angle);
QapMat4 Translate(const float x,const float y,const float z);
QapMat4 Scale(const float x,const float y,const float z);
QapMat4 Identity4();
class QapD3DPresentParameters
{
public:
  ;
public:
  typedef QapD3DPresentParameters SelfClass;;
public:
  D3DPRESENT_PARAMETERS pp;;
public:
  void DoReset();
public:
  QapD3DPresentParameters(const QapD3DPresentParameters&)=delete;
  QapD3DPresentParameters();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapD3DPresentParameters";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYS(0,nullptr,"pp",int(&(((SelfClass*)nullptr)->*(&SelfClass::pp))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class TYPE>
  static TYPE&Zero(TYPE&inout)
  {
    ZeroMemory(&inout,sizeof(inout));
    return inout;
  }D3DPRESENT_PARAMETERS&SetToDef(HWND hWnd,bool VSync=true);
};
class QapD3D9
{
public:
  ;
public:
  typedef QapD3D9 SelfClass;;
public:
  IDirect3D9* pD3D;;
public:
  void DoReset();
public:
  QapD3D9(const QapD3D9&)=delete;
  QapD3D9();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapD3D9";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
        Info->extInfo.PoorDesign=true;
      }
      Info->AddMemberSYS(0,nullptr,"pD3D",int(&(((SelfClass*)nullptr)->*(&SelfClass::pD3D))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  QapD3D9(QapD3D9&&Ref);
  ~QapD3D9();
public:
  void oper_set(QapD3D9&&Ref);
public:
  void operator=(QapD3D9&&Ref);
public:
  void Init();
  void Free();
};
class QapD3D9Resource
{
public:
  virtual void OnLost()=0;
  virtual void OnReset()=0;
};
class QapD3D9ResourceList
{
public:
  ;
public:
  typedef QapD3D9ResourceList SelfClass;;
public:
  vector<QapD3D9Resource*> Arr;;
  bool Lost;;
public:
  void DoReset();
public:
  QapD3D9ResourceList(const QapD3D9ResourceList&)=delete;
  QapD3D9ResourceList();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapD3D9ResourceList";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYS(0,nullptr,"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Lost",int(&(((SelfClass*)nullptr)->*(&SelfClass::Lost))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  QapD3D9ResourceList(QapD3D9ResourceList&&Ref);
  ~QapD3D9ResourceList();
public:
  void oper_set(QapD3D9ResourceList&&Ref);
public:
  void operator=(QapD3D9ResourceList&&Ref);
public:
  void Free();
public:
  void OnLost();
  void OnReset();
public:
  bool HasRes(QapD3D9Resource*pRes,int*pIndex=nullptr);
  void Reg(QapD3D9Resource*pRes);
  void UnReg(QapD3D9Resource*pRes);
};
class QapD3DDev9
{
public:
  ;
public:
  typedef QapD3DDev9 SelfClass;;
public:
  QapD3DPresentParameters PresParams;;
  IDirect3DDevice9* pDev;;
  QapD3D9ResourceList Resources;;
public:
  void DoReset();
public:
  QapD3DDev9(const QapD3DDev9&)=delete;
  QapD3DDev9();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapD3DDev9";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYS(0,nullptr,"PresParams",int(&(((SelfClass*)nullptr)->*(&SelfClass::PresParams))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"pDev",int(&(((SelfClass*)nullptr)->*(&SelfClass::pDev))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Resources",int(&(((SelfClass*)nullptr)->*(&SelfClass::Resources))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  QapD3DDev9(QapD3DDev9&&Ref);
  ~QapD3DDev9();
public:
  void oper_set(QapD3DDev9&&Ref);
public:
  void operator=(QapD3DDev9&&Ref);
public:
  void Init(HWND hWnd,QapD3D9&D3D);
  void Free();
public:
  void ResetStates();
public:
  bool BeginScene();
  bool EndScene();
  bool Present(const RECT*pSource=nullptr,const RECT*pDest=nullptr);
public:
  enum BlendType
  {
    BT_NONE,
    BT_SUB,
    BT_ADD,
  };
  enum AlphaType
  {
    AM_NONE,
    AM_GEQUAL_ONE,
    AM_NEQUAL_MAX,
  };
public:
  void Blend(BlendType Mode);
  void Alpha(AlphaType Mode);
public:
  static void OrthoLH(D3DMATRIX&out,float w,float h,float zn,float zf);
  void Set2D(vec2d CamPos=vec2d(0.0,0.0),real zoom=1.0,real ang=0.0,vec2i*pSize=nullptr);
  void Clear2D(const QapColor&Color);
};
#pragma once

#pragma once

#pragma warning(disable:4482)

class QapDev
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapDev OwnerClass;
    void operator=(OwnerClass*pOwner);
  public:
    TDynamicResource();;
    ~TDynamicResource();;
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev);
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost();
    void OnReset();
  };
public:
  struct Ver
  {
    float x,y,z;
    QapColor color;
    float tu,tv;
    Ver();
    Ver(float x,float y,const QapColor&color,float u=0.0,float v=0.0);
    Ver(const vec2f&pos,const QapColor&color,float u=0.0,float v=0.0);
    Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord);
    vec2f&get_pos();
    vec2f&get_pos()const;
    vec2f&get_tpos();
    vec2f&get_tpos()const;
  };
  struct BatchScope
  {
    QapDev&RD;
    bool flag;
    BatchScope(QapDev&RD);
    ~BatchScope();
  };
public:
  typedef QapD3DDev9::BlendType BlendType;
  typedef QapD3DDev9::AlphaType AlphaType;
public:
  ;
public:
  typedef QapDev SelfClass;;
public:
  TDynamicResource DynRes;;
  IDirect3DDevice9* pDev;;
  IDirect3DVertexBuffer9* VB;;
  IDirect3DIndexBuffer9* IB;;
  Ver* VBA;;
  int* IBA;;
  QapColor color;;
  int VPos;;
  int IPos;;
  int MaxVPos;;
  int MaxIPos;;
  int DIPs;;
  int Verts;;
  int Tris;;
  BlendType BlendMode;;
  AlphaType AlphaMode;;
  bool Batching;;
  bool Textured;;
  transform2f xf;;
  transform2f txf;;
public:
  void DoReset();
public:
  QapDev(const QapDev&)=delete;
  QapDev();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapDev";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYS(0,nullptr,"DynRes",int(&(((SelfClass*)nullptr)->*(&SelfClass::DynRes))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"pDev",int(&(((SelfClass*)nullptr)->*(&SelfClass::pDev))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"VB",int(&(((SelfClass*)nullptr)->*(&SelfClass::VB))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"IB",int(&(((SelfClass*)nullptr)->*(&SelfClass::IB))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"VBA",int(&(((SelfClass*)nullptr)->*(&SelfClass::VBA))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"IBA",int(&(((SelfClass*)nullptr)->*(&SelfClass::IBA))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"color",int(&(((SelfClass*)nullptr)->*(&SelfClass::color))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"VPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::VPos))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"IPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::IPos))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"MaxVPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::MaxVPos))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"MaxIPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::MaxIPos))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"DIPs",int(&(((SelfClass*)nullptr)->*(&SelfClass::DIPs))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Verts",int(&(((SelfClass*)nullptr)->*(&SelfClass::Verts))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Tris",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tris))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"BlendMode",int(&(((SelfClass*)nullptr)->*(&SelfClass::BlendMode))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"AlphaMode",int(&(((SelfClass*)nullptr)->*(&SelfClass::AlphaMode))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Batching",int(&(((SelfClass*)nullptr)->*(&SelfClass::Batching))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Textured",int(&(((SelfClass*)nullptr)->*(&SelfClass::Textured))),"SYS");;
      Info->AddMemberSYD(0,nullptr,"xf",int(&(((SelfClass*)nullptr)->*(&SelfClass::xf))),"SYD");;
      Info->AddMemberSYD(0,nullptr,"txf",int(&(((SelfClass*)nullptr)->*(&SelfClass::txf))),"SYD");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
protected:
  static const DWORD FVF=D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1;
public:
  ~QapDev();
public:
  void ReInit();
  void MountDev(QapD3DDev9&Dev);
  void Init(int VCount,int ICount);
  void Free();;
public:
  void BeginBatch();;
  void EndBatch();
  void DIP();
  bool IsBatching();
  int GetIPos();
  int GetVPos();
  int GetDIPs();
  int GetVerts();
  int GetTris();
  const QapColor&GetColor();
  void NextFrame();
public:
  void HackMode(bool Textured);
  template<class QAP_TEX>
  void BindTex(int Stage,QAP_TEX*pTex)
  {
    QapTex*Tex=pTex;
    pDev->SetTexture(Stage,Tex?Tex->Tex:nullptr);
    txf.set_ident();
    Textured=Tex?true:false;
  }void BindTex(int Stage,const nullptr_t);
public:
  Ver&AddVertexRaw();
  int AddVertex(const Ver&Source);
  int AddVertex(float x,float y,const QapColor&c,float u,float v);
  int AddVertex(const vec2f&pos,const QapColor&c,float u,float v);
  int AddVertex(const vec2f&pos,const QapColor&c,const vec2f&tpos);
  void AddTris(int A,int B,int C);;
public:
  void SetColor(const QapColor&C);
  void SetTransform(transform2f const&val);
  transform2f GetTransform();
  void SetTextureTransform(transform2f const&val);
  transform2f GetTextureTransform();
public:
  BlendType GetBlendMode();
  AlphaType GetAlphaMode();
  void SetBlendMode(BlendType Mode);
  void SetAlphaMode(AlphaType Mode);
public:
  void DrawSolidRect(const vec2d&a,const vec2d&b);
  void DrawRect(const vec2i&ap,const vec2i&bp,int line_size);
  void DrawRect(const vec2d&a,const vec2d&b,int line_size);
  void DrawRectAsQuad(const vec2i&pos,const vec2i&size,int line_size);
  void DrawRectAsQuad(const vec2d&pos,const vec2d&size,int line_size);
  void DrawQuadWithHalfPixelOffset(int x,int y,int w,int h);
  void DrawQuadWithHalfPixelOffset(const vec2i&p,int w,int h);
  void DrawQuadWithHalfPixelOffset(const vec2i&p,const vec2i&size);
  void DrawQuad(float x,float y,float w,float h);
  void DrawQuad(float x,float y,float w,float h,float a);
  void DrawQuad(float x,float y,const vec2d&size,float ang);
  void DrawQuad(const vec2d&pos,const vec2d&size,float ang);
  void DrawQuad(const vec2d&pos,const vec2d&size);
  void DrawQuad(const vec2d&pos,float w,float h,float ang);
  void DrawQuad(const vec2d&pos,float w,float h);
  void DrawTrigon(const vec2d&A,const vec2d&B,const vec2d&C);
  void DrawConvex(const vector<vec2d>&Points);
public:
  template<typename TYPE>
  void DrawPolyLine(const vector<TYPE>&PA,const real&LineSize,const bool&Loop)
  {
    if (PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      int c=Loop?Count:Count-1;
      for (int i=0;i<c;i++)
      {
        TYPE const&a=PA[(i+0)%Count];
        TYPE const&b=PA[(i+1)%Count];
        vec2d n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]=
        {
          AddVertex(a+n,color,0.5f,0.5f),
          AddVertex(b-n,color,0.5f,0.5f),
          AddVertex(a-n,color,0.5f,0.5f),
          AddVertex(b+n,color,0.5f,0.5f),
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawLineList(const vector<TYPE>&PA,const real&LineSize)
  {
    if (PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      for (int i=0;i+1<Count;i+=2)
      {
        TYPE const&a=PA[i+0];
        TYPE const&b=PA[i+1];
        TYPE n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]=
        {
          AddVertex(a+n,color,0.5,0.5),
          AddVertex(b-n,color,0.5,0.5),
          AddVertex(a-n,color,0.5,0.5),
          AddVertex(b+n,color,0.5,0.5),
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawMesh(const vector<TYPE>&VA,const vector<int>&IA)
  {
    QapDebugMsg("[2014.05.22]: way used?");
    if (VA.empty())return;
    BatchScope Scope(*this);
    {
      int base=GetVPos();
      static IntArray VID;
      VID.resize(VA.size());
      for (int i=0;i<VA.size();i++)VID[i]=AddVertex(MakeVer(VA[i],color,p.x,p.y));
      for (int i=0;i<IA.size();i+=3)AddTris(VID[IA[i+0]],VID[IA[i+1]],VID[IA[i+2]]);
    }
  }void DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg);
  void DrawCircle(const vec2d&pos,real r,real ang,real ls,int seg);
  void DrawCircleEx(const vec2d&pos,real r0,real r1,int seg,real ang);
};
template<class TYPE>
class QapArray
{
public:
  TMemory Mem;
  QapArray() {}
  ~QapArray()
  {
    Free();
  }
  QapArray(const QapArray<TYPE>&Ref)
  {
    oper_set(Ref);
  }
  void operator=(const QapArray<TYPE>&Ref)
  {
    oper_set(Ref);
  }
  void oper_set(const QapArray<TYPE>&Ref)
  {
    Free();
    if (!Ref)return;
    Init(Ref.Mem.size);
    QapAssert(Ref.Mem.size==this->Mem.size);
    memcpy_s(this->Mem.ptr,this->Mem.size*sizeof(TYPE),Ref.Mem.ptr,Ref.Mem.size*sizeof(TYPE));
  }
  QapArray(QapArray<TYPE>&&Ref)
  {
    oper_set(std::move(Ref));
  }
  void operator=(QapArray<TYPE>&&Ref)
  {
    oper_set(std::move(Ref));
  }
  void oper_set(QapArray<TYPE>&&Ref)
  {
    Free();
    this->Mem=std::move(Ref.Mem);
  }
  operator bool()const
  {
    return Mem.ptr;
  }
  TYPE&operator[](size_t index)
  {
    return (TYPE&)Mem.ptr[index*sizeof(TYPE)];
  }
  const TYPE&operator[](size_t index)const
  {
    return (const TYPE&)Mem.ptr[index*sizeof(TYPE)];
  }
  void Init(int size)
  {
    if (*this)Free();
    QapAssert(size>0);
    QapAssert(size<(1<<26));
    Mem.ptr=(TMemory::ptr_t*)(void*)new TYPE[size];
    Mem.size=size;
  }
  void Free()
  {
    if (!Mem.ptr)return;
    TYPE*p=(TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;
    delete[] p;
    Mem.ptr=nullptr;
    Mem.size=0;
  }
  TYPE*get()
  {
    return (TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;
  }
  const TYPE*get()const
  {
    return (TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;
  }
};
class QapTexMem
{
public:
  ;
public:
  typedef QapTexMem SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  QapArray<QapColor> Arr;;
  int W;;
  int H;;
public:
  void DoReset();
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapTexMem";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberSYD(0,nullptr,"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"SYD");;
      Info->AddMemberSYS(0,nullptr,"W",int(&(((SelfClass*)nullptr)->*(&SelfClass::W))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"H",int(&(((SelfClass*)nullptr)->*(&SelfClass::H))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  QapTexMem();
  QapTexMem(const QapTexMem&Ref);
  void operator=(const QapTexMem&Ref);
  void oper_set(const QapTexMem&Ref);
  QapTexMem(QapTexMem&&Ref);
  void operator=(QapTexMem&&Ref);
  void oper_set(QapTexMem&&Ref);
  QapTexMem Clone();
  void CopyDataFrom(const QapTexMem&Ref);
  void MoveDataFrom(QapTexMem&Ref);
  void Init(int W,int H);
  void Free();
  QapColor*get();
  const QapColor*get()const;
  operator bool()const;
public:
  void InvertY();
  void InvertX();
public:
  void GenRect(int TexSize);
  void GenBall(int TexSize);
  void GenQuad(int TexSize);
  void FillBorder(int x,int y,const QapTexMem&Source,int n=4);
  void FillMem(int x,int y,const QapTexMem&Source);
  void DrawInHalfScale(const QapTexMem&Source,int count);
  void DrawMemWithBlend(int x,int y,const QapTexMem&Source,const QapColor&color);
  void Clear(const QapColor&color=0xFF000000);
  void FillLine(const int Y,const QapColor&Color);
  void FillColumn(const int X,const QapColor&Color);
  void RectLine(int X,int Y,int W,int H,const QapColor&Color);
  void FillLineEx(const int Y,const int X0,const int X1,const QapColor&Color);
  void FillColomnEx(const int X,const int Y0,const int Y1,const QapColor&Color);
public:
  void CopyAlpha(QapTexMem&Alpha);
  void CalcAlpha();
  void CalcAlpha(const QapColor&Color,int threshold=0);
  void DrawSolidCircle(int x,int y,int r,const QapColor&color);
  void DrawSolidQuad(int x,int y,int w,int h,const QapColor&color);
  void FillChannel(const QapColor&Source,DWORD BitMask);
  void BlurTexture(int PassCount);
};
extern bool LoadTextureFromFile(QapTexMem&out,const string&FN);
extern void SaveTextureToFile(QapTexMem&in,const string&FN);
class QapTexFile
{
public:
  ;
public:
  typedef QapTexFile SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  string FN;;
  QapTexMem Mem;;
public:
  void DoReset();
public:
  QapTexFile(const QapTexFile&)=delete;
  QapTexFile();;
public:
  QapTexFile(QapTexFile&&_Right);
  void operator=(QapTexFile&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapTexFile";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"FN",int(&(((SelfClass*)nullptr)->*(&SelfClass::FN))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapTexMem>::GetRTTI(RTTI),"Mem",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mem))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Load();
  void Save();
};
class QapTex
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapTex OwnerClass;
    void operator=(OwnerClass*pOwner);
  public:
    TDynamicResource();;
    ~TDynamicResource();;
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev);
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost();
    void OnReset();
  };
public:
  ;
public:
  typedef QapTex SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  int W;;
  int H;;
  TDynamicResource DynRes;;
  IDirect3DTexture9* Tex;;
public:
  void DoReset();
public:
  QapTex(const QapTex&)=delete;
  QapTex();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapTex";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberSYS(0,nullptr,"W",int(&(((SelfClass*)nullptr)->*(&SelfClass::W))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"H",int(&(((SelfClass*)nullptr)->*(&SelfClass::H))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"DynRes",int(&(((SelfClass*)nullptr)->*(&SelfClass::DynRes))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  ~QapTex();
public:
  void ReInit();
  void MountDev(QapD3DDev9&Dev);
  void Init(int W,int H,int Levels);
  void Free();;
  operator bool()const;
  void Bind(int lvl=0);;
public:
  void operator=(const QapTex&);
};
class TResourceHolder
{
public:
  ;
public:
  typedef TResourceHolder SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  string Caption;;
public:
  void DoReset();
public:
  TResourceHolder(const TResourceHolder&)=delete;
  TResourceHolder();;
public:
  TResourceHolder(TResourceHolder&&_Right);
  void operator=(TResourceHolder&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TResourceHolder";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Caption",int(&(((SelfClass*)nullptr)->*(&SelfClass::Caption))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
};
class QapResource
{
public:
  ;
public:
  typedef QapResource SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  vector<TWeakPtr<TResourceHolder>> Holders;;
public:
  void DoReset();
public:
  QapResource(const QapResource&)=delete;
  QapResource();;
public:
  QapResource(QapResource&&_Right);
  void operator=(QapResource&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapResource";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<TWeakPtr<TResourceHolder>>>::GetRTTI(RTTI),"Holders",int(&(((SelfClass*)nullptr)->*(&SelfClass::Holders))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  class IEnv
  {
  public:
    IEnvRTTI&Env;
    QapD3DDev9*pDev;
    operator IEnvRTTI&();
  };
public:
  virtual void Do(IEnv&Env);
public:
  void Run(IEnvRTTI&Env,QapD3DDev9*pDev);
};
class QapResourceList:public QapResource
{
public:
  ;
public:
  typedef QapResourceList SelfClass;
public:
  typedef QapResource ParentClass;;
public:
  vector<TAutoPtr<QapResource>> Items;;
public:
  void DoReset();
public:
  QapResourceList(const QapResourceList&)=delete;
  QapResourceList();;
public:
  QapResourceList(QapResourceList&&_Right);
  void operator=(QapResourceList&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapResourceList";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<QapResource>>>::GetRTTI(RTTI),"Items",int(&(((SelfClass*)nullptr)->*(&SelfClass::Items))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env,TResourceHolder&ResHolder,const string&Caption)
  {
    Items.resize(Items.size()+1);
    TYPE*ret=Items.back().build<TYPE>(Env);
    ret->Holders.push_back(&ResHolder);
    QapAssert(ResHolder.Caption.empty());
    ResHolder.Caption=Caption;
    return ret;
  }void Del();
public:
  void Do(IEnv&Env);
};
class QapTexGen
{
public:
  ;
public:
  typedef QapTexGen SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  TWeakPtr<QapTexMem> Mem;;
  TWeakPtr<QapTex> Tex;;
public:
  void DoReset();
public:
  QapTexGen(const QapTexGen&)=delete;
  QapTexGen();;
public:
  QapTexGen(QapTexGen&&_Right);
  void operator=(QapTexGen&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapTexGen";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TWeakPtr<QapTexMem>>::GetRTTI(RTTI),"Mem",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mem))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TWeakPtr<QapTex>>::GetRTTI(RTTI),"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  static void Gen(QapTexMem*Mem,QapTex*Tex,int MaxLevelCount=16);
public:
  void Do();
};
class QapTexObject:public QapResource
{
public:
  ;
public:
  typedef QapTexObject SelfClass;
public:
  typedef QapResource ParentClass;;
public:
  QapTexFile File;;
  QapTex Tex;;
  QapTexGen Gen;;
public:
  void DoReset();
public:
  QapTexObject(const QapTexObject&)=delete;
  QapTexObject();;
public:
  QapTexObject(QapTexObject&&_Right);
  void operator=(QapTexObject&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapTexObject";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<QapTexFile>::GetRTTI(RTTI),"File",int(&(((SelfClass*)nullptr)->*(&SelfClass::File))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapTex>::GetRTTI(RTTI),"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapTexGen>::GetRTTI(RTTI),"Gen",int(&(((SelfClass*)nullptr)->*(&SelfClass::Gen))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void SetToDef();
  struct t_fn_parser
  {
    string fn;
    string func;
    string size;
    int value;
    bool main();
  };
  void Do(IEnv&Env);
};
class QapResourceDetector
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapResourceDetector OwnerClass;
    void operator=(OwnerClass*pOwner);
  public:
    TDynamicResource();;
    ~TDynamicResource();;
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev);
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost();
    void OnReset();
  };
public:
  ;
public:
  typedef QapResourceDetector SelfClass;;
public:
  bool needinit;;
  TDynamicResource DynRes;;
  bool used;;
public:
  void DoReset();
public:
  QapResourceDetector(const QapResourceDetector&)=delete;
  QapResourceDetector();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapResourceDetector";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"needinit",int(&(((SelfClass*)nullptr)->*(&SelfClass::needinit))),"SET","false");;
      Info->AddMemberSYS(0,nullptr,"DynRes",int(&(((SelfClass*)nullptr)->*(&SelfClass::DynRes))),"SYS");;
      Info->AddMemberSYS(0,nullptr,"used",int(&(((SelfClass*)nullptr)->*(&SelfClass::used))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  ~QapResourceDetector();
public:
  void MountDev(QapD3DDev9&Dev);
  void PreInit();
  void PreFree();
  void Init();
  void Free();;
  operator bool()const;
};
template<class TYPE,unsigned int SIZE>class ArrayTypeSolver {};
class QapFontInfo
{
public:
  typedef vec2i vec2i_256[256];
public:
  ;
public:
  typedef QapFontInfo SelfClass;;
public:
  vec2i_256 Coords;;
public:
  void DoReset();
public:
  QapFontInfo(const QapFontInfo&)=delete;
  QapFontInfo();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapFontInfo";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSYD(0,nullptr,"Coords",int(&(((SelfClass*)nullptr)->*(&SelfClass::Coords))),"SYD");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  vec2i&operator[](int index);
  const vec2i&operator[](int index)const;
};
class QapFont
{
public:
  ;
public:
  typedef QapFont SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  QapTexMem Mem;;
  QapFontInfo Info;;
public:
  void DoReset();
public:
  QapFont(const QapFont&)=delete;
  QapFont();;
public:
  QapFont(QapFont&&_Right);
  void operator=(QapFont&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapFont";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapTexMem>::GetRTTI(RTTI),"Mem",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mem))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapFontInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
};
class QapFontGen
{
public:
  ;
public:
  typedef QapFontGen SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  string Name;;
  int Size;;
  bool Bold;;
  int TexSize;;
  TWeakPtr<QapFont> Font;;
public:
  void DoReset();
public:
  QapFontGen(const QapFontGen&)=delete;
  QapFontGen();;
public:
  QapFontGen(QapFontGen&&_Right);
  void operator=(QapFontGen&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapFontGen";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","1?\"FixedSys\":\"Arial\"");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","1?10:14");;
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Bold",int(&(((SelfClass*)nullptr)->*(&SelfClass::Bold))),"SET","false");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"TexSize",int(&(((SelfClass*)nullptr)->*(&SelfClass::TexSize))),"SET","512");;
      Info->AddMemberDEF(Sys$$<TWeakPtr<QapFont>>::GetRTTI(RTTI),"Font",int(&(((SelfClass*)nullptr)->*(&SelfClass::Font))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Do(HWND hWnd);
public:
  static void CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize);
};
class QapFontObject:public QapResource
{
public:
  ;
public:
  typedef QapFontObject SelfClass;
public:
  typedef QapResource ParentClass;;
public:
  QapFont Font;;
  QapFontGen FontGen;;
  QapTex Tex;;
  QapTexGen TexGen;;
public:
  void DoReset();
public:
  QapFontObject(const QapFontObject&)=delete;
  QapFontObject();;
public:
  QapFontObject(QapFontObject&&_Right);
  void operator=(QapFontObject&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapFontObject";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<QapFont>::GetRTTI(RTTI),"Font",int(&(((SelfClass*)nullptr)->*(&SelfClass::Font))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapFontGen>::GetRTTI(RTTI),"FontGen",int(&(((SelfClass*)nullptr)->*(&SelfClass::FontGen))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapTex>::GetRTTI(RTTI),"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapTexGen>::GetRTTI(RTTI),"TexGen",int(&(((SelfClass*)nullptr)->*(&SelfClass::TexGen))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void SetToDef();
  void MountDev(QapD3DDev9*pDev);
  void DoGenFont(QapD3DDev9*pDev);
  void DoGenTex();
  void Do(IEnv&Env);
};
class QapQ3Text
{
public:
  static int GetLength(const QapFont&Font,const string&Text);
public:
  static string ToNormal(const string&Text);
public:
  static int AddVertexEx(QapDev*RD,float x,float y,QapColor c,float u,float v);
  static void DrawQapText(QapDev*RD,QapFont&Font,float X,float Y,const string&Text);
};
class QapText
{
public:
  static int GetLength(const QapFont&Font,const string&Text);
public:
  static int AddVertexEx(QapDev&qDev,float x,float y,QapColor c,float u,float v);
  struct t_draw_call
  {
    char c;
    vec2i pos;
    vec2i size;
  };
  static void add_draw_call(vector<t_draw_call>&out,char c,const vec2i&pos,const vec2i&size);
  template<class FUNC>
  static void PreDrawEx(QapFont&Font,float X,float Y,const string&Text,/*vector<t_draw_call>&out,*/FUNC&func)
  {
    float xp=0;
    int i=0;
    vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
    vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
    for (int i=0;i<Text.size();i++)
    {
      unsigned char UC=Text[i];
      float U=off.x+float(UC%16)/16;
      float V=off.y+float(UC/16)/16;
      auto c=Font.Info[UC];
      func(UC,vec2i(xp+X,Y),c);
      vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
      xp+=c.x;
    }
  }
  template<class FUNC>
  static void DrawEx(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text,FUNC&func)
  {
    QapDev::BatchScope Scope(qDev);
    {
      typedef QapDev::Ver Vertex;
      int QuadCount=0;
      int VPos=qDev.GetVPos();
      float xp=0;
      int i=0;
      vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
      vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5f;
      QapColor color=qDev.GetColor();
      for (int i=0;i<Text.size();i++)
      {
        unsigned char UC=Text[i];
        float U=off.x+float(UC%16)/16;
        float V=off.y+float(UC/16)/16;
        auto c=Font.Info[UC];
        func(UC,vec2i(xp+X,Y),c);
        vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
        int A=AddVertexEx(qDev,xp+X+(0.f),Y+(-c.y),color,U+(0.f),V+(+t.y));;
        int B=AddVertexEx(qDev,xp+X+(c.x),Y+(-c.y),color,U+(t.x),V+(+t.y));;
        int C=AddVertexEx(qDev,xp+X+(c.x),Y+(+0.f),color,U+(t.x),V+(+0.f));;
        int D=AddVertexEx(qDev,xp+X+(0.f),Y+(+0.f),color,U+(0.f),V+(+0.f));;
        qDev.AddTris(A,B,C);
        qDev.AddTris(C,D,A);
        xp+=c.x;
        QuadCount++;
      }
    }
  }static void DoNothing(unsigned char UC,const vec2i&p,const vec2i&s);
  static void Draw(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text);
};
#pragma once

extern bool QapPublicUberFullSaverBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullLoaderBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullSaverProto(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern string QapPublicUberFullSaverProtoToStr(IEnvRTTI&Env,IQapRawObject&&Object);
extern bool QapPublicUberFullSaverBinMem(IEnvRTTI&Env,IQapRawObject&&Object,string&Out);
extern bool QapPublicUberFullLoaderBinMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp);
extern bool QapPublicUberFullCloneBinMem(IEnvRTTI&Env,IQapRawObject&&Dest,IQapRawObject&&Source);
int&get_QapClone_counter();
real&QapClone_timer();
template<class TYPE>
inline bool QapClone(IEnvRTTI&Env,TYPE&dest,TYPE&source)
{
  static auto&counter=get_QapClone_counter();
  counter++;
  QapClock clock;
  clock.Start();
  bool ok=QapPublicUberFullCloneBinMem(Env,QapRawUberObject(dest),QapRawUberObject(source));
  clock.Stop();
  QapClone_timer()+=clock.MS();
  return ok;
}
struct ICompileUnit;
struct ICompileUnitMan
{
  virtual void add(ICompileUnit*pUnit)=0;
  static ICompileUnitMan&get_man();
};
struct ICompileUnit
{
  virtual const char*get_filename()const=0;
  virtual void RegAll(IEnvRTTI&Env)=0;
  virtual void Run(IEnvRTTI&Env)=0;
  ICompileUnit();
};
string cur_date_str();
class ISubProgram
{
public:
  ;
public:
  typedef ISubProgram SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  string Caption;;
  bool Enabled;;
  bool NeedRemove;;
public:
  void DoReset();
public:
  ISubProgram(const ISubProgram&)=delete;
  ISubProgram();;
public:
  ISubProgram(ISubProgram&&_Right);
  void operator=(ISubProgram&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="ISubProgram";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Caption",int(&(((SelfClass*)nullptr)->*(&SelfClass::Caption))),"DEF","$");;
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Enabled",int(&(((SelfClass*)nullptr)->*(&SelfClass::Enabled))),"SET","true");;
      Info->AddMemberDEF(Sys$$<bool>::GetRTTI(RTTI),"NeedRemove",int(&(((SelfClass*)nullptr)->*(&SelfClass::NeedRemove))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  class t_context
  {
  public:
    IEnvRTTI&Env;
    operator IEnvRTTI&();
  };
public:
  virtual void Update(t_context&Env);
  void TryUpdate(t_context&con);
};
class TProgramNode:public ISubProgram
{
public:
  ;
public:
  typedef TProgramNode SelfClass;
public:
  typedef ISubProgram ParentClass;;
public:
  vector<TAutoPtr<ISubProgram>> Programs;;
public:
  void DoReset();
public:
  TProgramNode(const TProgramNode&)=delete;
  TProgramNode();;
public:
  TProgramNode(TProgramNode&&_Right);
  void operator=(TProgramNode&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TProgramNode";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<ISubProgram>>>::GetRTTI(RTTI),"Programs",int(&(((SelfClass*)nullptr)->*(&SelfClass::Programs))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  typedef vector<TAutoPtr<ISubProgram>> TArray;
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Programs.resize(Programs.size()+1);
    return Programs.back().build<TYPE>(Env);
  }void ForceUpdate(t_context&con);
  void Update(t_context&con);
public:
  TAutoPtr<ISubProgram>&front();
  TAutoPtr<ISubProgram>&back();
public:
  bool empty()const;
};
class QapRenderProgram;
class QapPluginMan;
class IUnitProgram
{
public:
  ;
public:
  typedef IUnitProgram SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  bool Deaded;;
public:
  void DoReset();
public:
  IUnitProgram(const IUnitProgram&)=delete;
  IUnitProgram();;
public:
  IUnitProgram(IUnitProgram&&_Right);
  void operator=(IUnitProgram&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IUnitProgram";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Deaded",int(&(((SelfClass*)nullptr)->*(&SelfClass::Deaded))),"SET","false");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  struct TBuildContext
  {
    IEnvRTTI&Env;
    QapPluginMan&PluginMan;
    QapRenderProgram&Qrp;
  };
  virtual void OnBuild(TBuildContext&Context);
  virtual void Update(IEnvRTTI&Env);
};
class TReloadDetector
{
public:
public:
  ;
public:
  typedef TReloadDetector SelfClass;;
public:
  bool needinit;;
  bool fresh;;
public:
  void DoReset();
public:
  TReloadDetector(const TReloadDetector&)=delete;
  TReloadDetector();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TReloadDetector";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"needinit",int(&(((SelfClass*)nullptr)->*(&SelfClass::needinit))),"SET","false");;
      Info->AddMemberSYS(0,nullptr,"fresh",int(&(((SelfClass*)nullptr)->*(&SelfClass::fresh))),"SYS");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Init();
  void Free();;
  void Update();
};
class QapKeyboard
{
public:
  struct TKeyState
  {
    static const int MAX_KEY=263;
    bool data[MAX_KEY];
    TKeyState();
    void SetToDef();
    bool&operator[](int index);
    const bool&operator[](int index)const;
  };
public:
  ;
public:
  typedef QapKeyboard SelfClass;;
public:
  int LastKey;;
  char LastChar;;
  bool NeedReset;;
  bool News;;
  TKeyState Down;;
  TKeyState Changed;;
public:
  void DoReset();
public:
  QapKeyboard(const QapKeyboard&)=delete;
  QapKeyboard();;
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapKeyboard";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"LastKey",int(&(((SelfClass*)nullptr)->*(&SelfClass::LastKey))),"SET","0");;
      Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"LastChar",int(&(((SelfClass*)nullptr)->*(&SelfClass::LastChar))),"SET","0");;
      Info->AddMemberDEF(Sys$$<bool>::GetRTTI(RTTI),"NeedReset",int(&(((SelfClass*)nullptr)->*(&SelfClass::NeedReset))),"DEF","$");;
      Info->AddMemberSYS(0,nullptr,"News",int(&(((SelfClass*)nullptr)->*(&SelfClass::News))),"SYS");;
      Info->AddMemberSYD(0,nullptr,"Down",int(&(((SelfClass*)nullptr)->*(&SelfClass::Down))),"SYD");;
      Info->AddMemberSYD(0,nullptr,"Changed",int(&(((SelfClass*)nullptr)->*(&SelfClass::Changed))),"SYD");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void operator=(const QapKeyboard&);
  void try_reset();
  void reset();
  void KeyUpdate(int Key,bool Value);
  void CharUpdate(char c);
  void Sync();
  bool OnDown(int index)const;
};
class eQuad
{
public:
  ;
public:
  typedef eQuad SelfClass;;
public:
  int x;;
  int y;;
  int w;;
  int h;;
public:
  void DoReset();
public:
  eQuad(const eQuad&)=delete;
  eQuad();;
public:
  eQuad(eQuad&&_Right);
  void operator=(eQuad&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="eQuad";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","320");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","240");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"w",int(&(((SelfClass*)nullptr)->*(&SelfClass::w))),"SET","320");;
      Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"h",int(&(((SelfClass*)nullptr)->*(&SelfClass::h))),"SET","240");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  void Set(int x,int y,int w,int h);
  vec2i&GetPos();
  vec2i&GetSize();
  void SetAs(const vec2i&pos,const vec2i&size);
  RECT GetWinRect();
  void SetWinRect(const RECT&rect);
  void SetSize(const SIZE&size);
  static eQuad getFullScreen();
  void setAtCenter(const eQuad&quad);
  void subpos(const eQuad&q);
  void setAtCenterScreen();
};
enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};
class IProgramD3D9
{
public:
  ;
public:
  typedef IProgramD3D9 SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
  QapD3D9 D9;;
  QapD3DDev9 D9Dev;;
  TProgramNode UserCode;;
public:
  void DoReset();
public:
  IProgramD3D9(const IProgramD3D9&)=delete;
  IProgramD3D9();;
public:
  IProgramD3D9(IProgramD3D9&&_Right);
  void operator=(IProgramD3D9&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="IProgramD3D9";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapD3D9>::GetRTTI(RTTI),"D9",int(&(((SelfClass*)nullptr)->*(&SelfClass::D9))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<QapD3DDev9>::GetRTTI(RTTI),"D9Dev",int(&(((SelfClass*)nullptr)->*(&SelfClass::D9Dev))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<TProgramNode>::GetRTTI(RTTI),"UserCode",int(&(((SelfClass*)nullptr)->*(&SelfClass::UserCode))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual vec2i WindowGetClientSize();
  virtual QapKeyboard&GetKeyBoard();
  virtual vec2i WindowGetMousePos();
  virtual eQuad&WindowGetQuad();
  virtual void WindowUpdateMode();
  virtual void WindowFullScreen(bool fullscreen);
  virtual int WindowGetzDelta();
};
class ITreeDebuggerBranch
{
public:
  ;
public:
  typedef ITreeDebuggerBranch SelfClass;;
public:
  TSelfPtr<SelfClass> Self;;
public:
  void DoReset();
public:
  ITreeDebuggerBranch(const ITreeDebuggerBranch&)=delete;
  ITreeDebuggerBranch();;
public:
  ITreeDebuggerBranch(ITreeDebuggerBranch&&_Right);
  void operator=(ITreeDebuggerBranch&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="ITreeDebuggerBranch";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual TRawPtr GetRawPtr();
  virtual string GetCode();
};
class QapPluginMan:public ISubProgram
{
public:
  ;
public:
  typedef QapPluginMan SelfClass;
public:
  typedef ISubProgram ParentClass;;
public:
  vector<TAutoPtr<IUnitProgram>> Items;;
public:
  void DoReset();
public:
  QapPluginMan(const QapPluginMan&)=delete;
  QapPluginMan();;
public:
  QapPluginMan(QapPluginMan&&_Right);
  void operator=(QapPluginMan&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="QapPluginMan";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<IUnitProgram>>>::GetRTTI(RTTI),"Items",int(&(((SelfClass*)nullptr)->*(&SelfClass::Items))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }IUnitProgram*unsafe_AddItem(IEnvRTTI&Env,TType*pType);
  void MakeAll(IEnvRTTI&Env,QapRenderProgram*pQRP,TType*pIUnitProgram);
  void Update(t_context&con);
public:
  bool empty()const;
};
class GlobalEnv
{
public:
  HINSTANCE hInstance;
  HINSTANCE hPrevInstance;
  LPSTR lpCmdLine;
  int nCmdShow;
public:
  GlobalEnv(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
  );
public:
  static const GlobalEnv&Get(GlobalEnv*ptr=nullptr);
private:
  GlobalEnv(const GlobalEnv&);
  void operator=(const GlobalEnv&);
};
bool IsKeyDown(int vKey);
bool is_first_part_of(const string&text,const string&first_part);
string without_first_part(const string&text,const string&first_part);
bool remove_first_part_of(string&text,const string&first_part);
class TOutDev
{
public:
  class TMemberID;
  class TSubType;
  class TVecID;
  class TChunk;
  class TField;
  class DevCmd;
  class IVisitor
  {
  public:
    virtual void Do(TMemberID*p)=0;
    virtual void Do(TSubType*p)=0;
    virtual void Do(TVecID*p)=0;
    virtual void Do(TChunk*p)=0;
    virtual void Do(TField*p)=0;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(TMemberID*p)
      {
        ptr=get(p);
      }void Do(TSubType*p)
      {
        ptr=get(p);
      }void Do(TVecID*p)
      {
        ptr=get(p);
      }void Do(TChunk*p)
      {
        ptr=get(p);
      }void Do(TField*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(DevCmd*p)
    {
      if (!p)return nullptr;
      Is<TYPE,IVisitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
  class DevCmd
  {
  public:
  public:
    typedef TOutDev OwnerClass;;
  public:
    typedef DevCmd SelfClass;;
  public:
  public:
    void DoReset();
  public:
    DevCmd(const DevCmd&)=delete;
    DevCmd();;
  public:
    DevCmd(DevCmd&&_Right);
    void operator=(DevCmd&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DevCmd";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    virtual void Use(IVisitor&A);
  };
  class TMemberID:public DevCmd
  {
  public:
  public:
    typedef TOutDev OwnerClass;;
  public:
    typedef TMemberID SelfClass;
  public:
    typedef DevCmd ParentClass;;
  public:
    int id;;
  public:
    void DoReset();
  public:
    TMemberID(const TMemberID&)=delete;
    TMemberID();;
  public:
    TMemberID(TMemberID&&_Right);
    void operator=(TMemberID&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TMemberID";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","-1");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    TMemberID(int id);
  public:
  public:
    void Use(IVisitor&A);
    static SelfClass*UberCast(DevCmd*p);
  };
  class TSubType:public DevCmd
  {
  public:
  public:
    typedef TOutDev OwnerClass;;
  public:
    typedef TSubType SelfClass;
  public:
    typedef DevCmd ParentClass;;
  public:
  public:
    void DoReset();
  public:
    TSubType(const TSubType&)=delete;
    TSubType();;
  public:
    TSubType(TSubType&&_Right);
    void operator=(TSubType&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TSubType";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
  public:
    void Use(IVisitor&A);
    static SelfClass*UberCast(DevCmd*p);
  };
  class TVecID:public DevCmd
  {
  public:
  public:
    typedef TOutDev OwnerClass;;
  public:
    typedef TVecID SelfClass;
  public:
    typedef DevCmd ParentClass;;
  public:
    int id;;
  public:
    void DoReset();
  public:
    TVecID(const TVecID&)=delete;
    TVecID();;
  public:
    TVecID(TVecID&&_Right);
    void operator=(TVecID&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TVecID";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","-1");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    TVecID(int id);
  public:
  public:
    void Use(IVisitor&A);
    static SelfClass*UberCast(DevCmd*p);
  };
  class TChunk:public DevCmd
  {
  public:
  public:
    typedef TOutDev OwnerClass;;
  public:
    typedef TChunk SelfClass;
  public:
    typedef DevCmd ParentClass;;
  public:
  public:
    void DoReset();
  public:
    TChunk(const TChunk&)=delete;
    TChunk();;
  public:
    TChunk(TChunk&&_Right);
    void operator=(TChunk&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TChunk";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
  public:
    void Use(IVisitor&A);
    static SelfClass*UberCast(DevCmd*p);
  };
  class TField:public DevCmd
  {
  public:
  public:
    typedef TOutDev OwnerClass;;
  public:
    typedef TField SelfClass;
  public:
    typedef DevCmd ParentClass;;
  public:
  public:
    void DoReset();
  public:
    TField(const TField&)=delete;
    TField();;
  public:
    TField(TField&&_Right);
    void operator=(TField&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TField";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
  public:
    void Use(IVisitor&A);
    static SelfClass*UberCast(DevCmd*p);
  };
  class TContext
  {
  public:
    string head;
    DevCmd*pCmd;
  public:
    TType*pType;
    void*pValue;
  public:
    TContext();
  };
  class TCmdVisitor:public IVisitor
  {
  public:
    struct t_dev
    {
      bool ok=true;
      const char*pcode=nullptr;
      int line=-1;
      void err(const char*pcode,int line);
    };
  public:
    t_dev&dev;
    TContext*pContext;
  public:
    TCmdVisitor(t_dev&dev,TContext*pContext);
  public:
    void Do(TMemberID*p);
    void Do(TSubType*p);
    void Do(TVecID*p);
    void Do(TChunk*p);
    void Do(TField*p);
  };
public:
  class TCmdHeadVisitor:public IVisitor
  {
  public:
    TContext Context;
    string out;
    TCmdHeadVisitor();
  public:
    void add_dot();;
    void Do(TMemberID*p);
    void Do(TSubType*p);
    void Do(TVecID*p);
    void Do(TChunk*p);
    void Do(TField*p);
  };
public:
  class TCmdOffsetVisitorEx:public IVisitor
  {
  public:
    struct TContextPoint
    {
      TType*pType;
      void*pValue;
    };
    struct TContext
    {
      TContextPoint Object;
      TContextPoint Field;
      int Offset;
    };
    TContext*pContext;
  public:
    void Do(TMemberID*p);
    void Do(TSubType*p);
    void Do(TVecID*p);
    void Do(TChunk*p);
    void Do(TField*p);
  };
public:
  class TCmdCloneVisitor:public IVisitor
  {
  public:
    TAutoPtr<DevCmd>pCmd;
    IEnvRTTI*pEnv;
  public:
    void Init(IEnvRTTI*pEnv);
  public:
    void Do(TMemberID*p);
    void Do(TSubType*p);
    void Do(TVecID*p);
    void Do(TChunk*p);
    void Do(TField*p);
  };
public:
  ;
public:
  typedef TOutDev SelfClass;;
public:
public:
  void DoReset();
public:
  TOutDev(const TOutDev&)=delete;
  TOutDev();;
public:
  TOutDev(TOutDev&&_Right);
  void operator=(TOutDev&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="TOutDev";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<DevCmd>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<TMemberID>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<TSubType>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<TVecID>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<TChunk>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<TField>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
};
class TIsSameVisitor:public IVisitorRTTI
{
public:
  typedef TIsSameVisitor SelfClass;
public:
  class TBranch:public TOutDev
  {
  public:
    TContext top;
    vector<TContext> items;
  public:
    void push_impl();
    void pop_impl();
    TContext&back();
    TContext&front();
    int size();
    TContext&operator[](int index);
  public:
    void push(DevCmd*pCmd);
    void pop();
  };
  void fail();
  typedef TOutDev::DevCmd DevCmd;
  void push(DevCmd*pCmd);
  void pop();
  template<class TYPE>
  static bool Exec(IEnvRTTI&Env,TYPE&bef,TYPE&aft)
  {
    TRawPtr rp_bef(Env,bef);
    TRawPtr rp_aft(Env,aft);
    TIsSameVisitor::TBranch branch_bef;
    TIsSameVisitor::TBranch branch_aft;
    branch_bef.top.pType=rp_bef.pType;
    branch_bef.top.pValue=rp_bef.pValue;
    branch_aft.top.pType=rp_aft.pType;
    branch_aft.top.pValue=rp_aft.pValue;
    TIsSameVisitor V(branch_bef,branch_aft);
    V.pTopType->Use(V);
    return V.ok;
  }
public:
  TBranch&bef;
  TBranch&aft;
  TType*&pTopType;
  bool ok;
public:
  TIsSameVisitor(TBranch&bef,TBranch&aft);
public:
  void Do(TTypeStruct*p);
  void Do(TTypeArray*p);
  void Do(TTypeSys*p);
  void Do(TTypeVector*p);
  void Do(TTypeSelfPtr*p);
  void Do(TTypeAutoPtr*p);
  void Do(TTypeWeakPtr*p);
  void Do(TTypeHardPtr*p);
  void Do(TTypeVoidPtr*p);
  void Do(TTypeFieldPtr*p);
};
struct t_error_tool
{
  struct t_subline
  {
    string cpp;
    string low;
    string error;
public:
    static string toCpp(const string&raw);
    static int toCppLen(const string&raw);
    static string gen(size_t count,char c);
    static t_subline go(const string&line,size_t offset);
  };
  struct t_line_info
  {
    size_t line_id;
    size_t curpos;
    bool ok;
    static t_line_info get(const string&mem,size_t pos);
    void go(const string&mem,size_t pos);
  };
  static string get_codefrag(const string&code,size_t pos);
};
#pragma once
class QapStrFinder
{
public:
  struct t_cmd
  {
    int pos=-1;
    int next_line=-1;
    int arr_id=-1;
    int last_pos=-1;
  };
  struct t_line
  {
    t_cmd cmds[256];
  };
public:
  vector<vector<int>> vecs;
  vector<string> keywords;
  vector<t_line> lines;
public:
  static QapStrFinder fromArr(const vector<string>&arr);
  void build(const vector<string>&arr);
  void add_keyword(const string&keyword);
  int add(int line_id,int keyword_id,int pos,int&last_pos);
};
class QapStrFinderFast
{
public:
  struct t_cmd
  {
    int next=-1;
    int end_id=-1;
    void update(int next,bool eow,int kw_id);
    void write_eow(int kw_id);
  };
  struct t_node
  {
    t_cmd cmds[256];
    int read_cmd_next(uchar c)const;
    int go_next(uchar c,int&end_id)const;
    t_cmd&read_cmd(uchar c);
  };
  struct t_item
  {
    uchar c=0;
    t_cmd cmd;
    int read_cmd_next(uchar c)const;
    int go_next(uchar c,int&end_id)const;
    t_cmd&read_cmd(uchar c);
  };
  struct t_lazy
  {
    int kw_id=-1;
    int pos=-1;
  };
  struct t_proxy
  {
    char type='E';
    int id=-1;
    void set_node(int id);
    void set_item(int id);
    void set_lazy(int id);
  };
  struct t_find_result
  {
    bool ok;
    int kw_id;
    friend bool operator==(const t_find_result&a,const t_find_result&b);
  };
public:
  vector<string> keywords;
  vector<t_proxy> proxies;
  vector<t_node> nodes;
  vector<t_item> items;
  vector<t_lazy> lazys;
  vector<int> free_items;
  vector<int> free_lazys;
public:
  static QapStrFinderFast fromArr(const vector<string>&arr);
  void rebuild();
  void build(const vector<string>&arr);
  int add(int ptr,uchar c,int keyword_id,int pos,bool eow,bool&need_break);
  void add_loop(int ptr,int pos,int kid);
  void unpack(int ptr,int kb);
  void write_next(int ptr,uchar c,int next,bool eow,int kw_id,int pos,bool&need_break);
  t_cmd&unsafe_read_cmd(int ptr,uchar c);
  int read_next(int ptr,uchar c)const;
  int go_next_for_find(int ptr,uchar c,const string&mem,int&state,int&pos,int&next_pos,int&end_id)const;
  int new_proxy();
  int new_node();
  int new_item();
  int new_lazy();
  t_find_result find_impl(const string&mem,int&state,int&pos,int&next_pos,int&end_id);
  t_find_result find(const string&mem);
};
struct t_fallback;
class i_dev
{
public:
  virtual IEnvRTTI&getEnv();
public:
  virtual void push(t_fallback*ptr);
  virtual void pop(t_fallback*ptr);
  virtual void setPos(int pos);
  virtual void getPos(int&pos);
public:
  virtual bool isSave();
  virtual bool isLoad();
public:
  virtual bool go_any(string&body,const string&any);
  virtual bool go_any(string&body,const CharMask&any);
  virtual bool go_const_raw(const char*const ptr,size_t size);
  virtual bool go_const(const string&str);
  virtual bool go_end(string&body,const string&end);
  virtual bool go_any_char(char&c,const string&any);
  virtual bool go_any_char(char&c,const CharMask&any);
  virtual bool go_any_str_from_vec(string&ref,const vector<string>&arr);
  virtual bool go_any_str_from_vec(string&ref,const QapStrFinder&arr);
public:
  virtual bool go_blob(string&body,size_t count);
public:
  template<size_t SIZE>
  bool go_any_arr_char(array<char,SIZE>&body,const string&any)
  {
    bool ok=false;
    for (size_t i=0;i<body.size();i++)
    {
      ok=go_any_char(body[i],any);
      if (!ok)break;
    }
    return ok;
  }
public:
  template<class TYPE,size_t SIZE>
  bool go_auto(std::array<TYPE,SIZE>&arr)
  {
    bool ok=false;
    for (size_t i=0;i<arr.size();i++)
    {
      ok=go_auto(arr[i]);
      if (!ok)break;
    }
    return ok;
  }
public:
  template<size_t SIZE>
  bool go_const(const char(&ptr)[SIZE])
  {
    static const auto one=lenof("");
    return go_const_raw(&ptr[0],SIZE-one);
  }bool go_const(const char&ref);
public:
  template<class TYPE>
  bool go_auto(TYPE&ref)
  {
    return go_for_item(*this,ref);
  }
public:
  template<class TYPE>
  bool go_str_without(string&ref)
  {
    t_fallback scope(*this,__FUNCTION__);
    auto&ok=scope.ok;
    if (isLoad())
    {
      int ok_count=0;
      {
        t_fallback loadscope(*this,__FUNCTION__"::load");
        for (int i=0;;i++)
        {
          {
            t_fallback tmp(*this,__FUNCTION__"::load::for::temp");
            TYPE temp;
            tmp.ok=go_for_item(*this,temp);
            if (tmp.ok)
            {
              tmp.ok=false;
              tmp.pos=scope.pos+i;
              break;
            }
          }
          int next_pos;
          {
            getPos(next_pos);
            next_pos++;
          }
          {
            t_fallback tmp(*this,__FUNCTION__"::load::for::one");
            string one;
            tmp.ok=go_blob(one,1);
            if (!tmp.ok)
            {
              tmp.pos=scope.pos+i;
              break;
            }
          }
          ok_count++;
          int cur_pos;
          getPos(cur_pos);
          QapAssert(next_pos==cur_pos);
        }
        loadscope.ok=false;
        loadscope.log_clear();
      }
      scope.log_clear();
      ok=ok_count;
      if (!ok)return ok;
      ok=go_blob(ref,ok_count);
      if (!ok)return ok;
      return ok;
    }
    if (isSave())
    {
      auto&Env=getEnv();
      QapAssert(!ref.empty());
      {
        t_fallback tmp(*this,__FUNCTION__"::save");
        string tmp_mem=ref;
        t_load_dev dev(Env,tmp_mem);
        for (int i=0;i<ref.size();i++)
        {
          dev.pos=i;
          TYPE tmp;
          bool ok=dev.go_auto(tmp);
          QapAssert(!ok);
          if (ok)
          {
            (*(int*)nullptr)=0;
            return false;
          }
        }
      }
      scope.log_clear();
      ok=go_blob(ref,ref.size());
      return ok;
    }
    return ok;
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_diff(TYPE&ref)
  {
    TYPE_TEMP temp;
    int def_pos=0;
    getPos(def_pos);
    t_fallback scope(*this,__FUNCTION__);
    auto&ok=scope.ok;
    if (isLoad())
    {
      int tmp_pos=0;
      bool tmp_ok=false;
      {
        t_fallback tmp(*this,__FUNCTION__"::load");
        tmp.ok=go_for_item(*this,temp);
        tmp_ok=tmp.ok;
        if (tmp.ok)
        {
          getPos(tmp_pos);
          tmp.ok=false;
          ok=false;
          tmp.pos=def_pos;
        }
      }
      ok=go_for_item(*this,ref);
      if (!tmp_ok||!ok)return ok;
      int ref_pos=0;
      getPos(ref_pos);
      if (ref_pos<=tmp_pos)
      {
        ok=false;
        scope.pos=def_pos;
      }
      return ok;
    }
    if (isSave())
    {
      auto&Env=getEnv();
      string tmp_mem;
      {
        t_save_dev dev(Env,tmp_mem);
        bool ok=go_for_item(dev,ref);
        QapAssert(ok);
        if (!ok)return ok;
      }
      for (;;)
      {
        TYPE obj;
        t_load_dev dev(Env,tmp_mem);
        bool tmp_ok=dev.go_auto(temp);
        int tmp_pos=dev.pos;
        dev.pos=0;
        bool obj_ok=dev.go_auto(obj);
        int obj_pos=dev.pos;
        QapAssert(obj_ok);
        if (!tmp_ok)break;
        QapAssert(obj_pos>tmp_pos);
        break;
      }
    }
    ok=go_for_item(*this,ref);
    return ok;
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_minor(TYPE&ref)
  {
    return old_go_sep<TYPE_TEMP>(ref);
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool old_go_sep(TYPE&ref)
  {
    TYPE_TEMP temp;
    t_fallback scope(*this,__FUNCTION__);
    auto&ok=scope.ok;
    if (isLoad())
    {
      {
        t_fallback tmp(*this,__FUNCTION__"::load");
        tmp.ok=go_for_item(*this,temp);
        if (tmp.ok)
        {
          tmp.ok=false;
          ok=false;
          tmp.pos=scope.pos;
        }
      }
      if (!ok)return ok;
    }
    if (isSave())
    {
      auto&Env=getEnv();
      string tmp_mem;
      {
        t_save_dev dev(Env,tmp_mem);
        bool ok=go_for_item(dev,ref);
        QapAssert(ok);
      }
      {
        t_load_dev dev(Env,tmp_mem);
        bool ok=dev.go_auto(temp);
        QapAssert(!ok);
        TYPE obj;
        ok=dev.go_auto(obj);
        QapAssert(ok);
      }
    }
    ok=go_for_item(*this,ref);
    return ok;
  }
public:
  template<class TYPE>
  bool go_str(string&ref)
  {
    auto&Env=getEnv();
    if (isSave())
    {
      bool ok=false;
      {
        TYPE value;
        t_load_dev dev(Env,ref);
        ok=dev.go_auto(value);
        int pos=0;
        dev.getPos(pos);
        bool err=ref.size()!=pos;
        ok=!err;
        if (err)
        {
          string msg="problem detected:\n";
          msg+="  ref.size : "+IToS(ref.size())+"\n";
          msg+="  pos      : "+IToS(pos)+"\n";
          msg+=t_error_tool::get_codefrag(ref,pos);
          QapDebugMsg(msg);
        }
      }
      if (ok)
      {
        return go_blob(ref,ref.size());
      }
      return ok;
    }
    if (isLoad())
    {
      TYPE value;
      int pos=0;
      getPos(pos);
      bool ok=go_auto(value);
      if (!ok)return ok;
      int curpos=0;
      getPos(curpos);
      QapAssert(curpos>pos);
      setPos(pos);
      auto count=curpos-pos;
      ok=go_blob(ref,count);
      QapAssert(ok);
      return ok;
    }
    QapDebugMsg("no way");
    return false;
  }
public:
  template<class TYPE>
  bool go_vec(vector<TYPE>&arr,const string&sep)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    if (isLoad())
    {
      for (int i=0;;i++)
      {
        t_fallback subscope(*this,__FUNCTION__);
        bool&ok=subscope.ok;
        if (i)
        {
          ok=go_const(sep);
          if (!ok)break;
        }
        TYPE tmp;
        ok=go_auto(tmp);
        if (!ok)break;
        QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
        arr.push_back(std::move(tmp));
      }
      ok=!arr.empty();
      return ok;
    }
    if (isSave())
    {
      for (int i=0;i<arr.size();i++)
      {
        if (i)
        {
          t_fallback subscope(*this,__FUNCTION__);
          subscope.ok=go_const(sep);
          if (!subscope.ok)break;
        }
        t_fallback subscope(*this,__FUNCTION__);
        bool&ok=subscope.ok;
        auto&ex=arr[i];
        QapAssert(CheckTAutoPtrIsNotEmpty(ex));
        ok=go_auto(ex);
        if (!ok)break;
      }
      return ok;
    }
    return ok;
  }
public:
  template<class TYPE>
  bool go_bin_oper(vector<TYPE>&arr,const string&oper)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    ok=go_vec(arr,oper);
    if (!ok)return ok;
    if (ok)ok=arr.size()>=2;
    return ok;
  }
};
struct t_scope_tool
{
  bool ok=true;
  void operator+=(bool value);
};
int&get_qap_fallback_counter();
struct t_fallback
{
  i_dev&dev;
  bool&ok;
  size_t pos;
  t_scope_tool mandatory;
  t_scope_tool optional;
  t_fallback(i_dev&dev,const char*const ptr);
  ~t_fallback();
};
class t_load_dev:public i_dev
{
public:
  IEnvRTTI&Env;
  const string&mem;
  size_t pos;
  size_t maxpos;
public:
  t_load_dev(IEnvRTTI&Env,const string&mem,size_t pos=0);
public:
  void push(t_fallback*ptr);
  void pop(t_fallback*ptr);
  void setPos(int pos);
  void getPos(int&pos);
public:
  IEnvRTTI&getEnv();
public:
  bool isSave();
  bool isLoad();
public:
  bool go_any(string&body,const string&any);
  bool go_any(string&body,const CharMask&any);
  bool go_const_raw(const char*const ptr,size_t size);
  bool go_const(const string&body);
  bool go_end(string&body,const string&aft);
  bool go_any_char(char&body,const string&any);
  bool go_any_char(char&body,const CharMask&any);
public:
  bool go_blob(string&body,size_t count);
public:
  class t_keywords
  {
  public:
    struct t_func
    {
      const t_keywords&keywords;
      bool ok=false;
      bool next=false;
      bool fail=false;
      size_t pos=0;
      size_t ok_pos=0;
      size_t ok_way_id=-1;
      vector<int> items;
      t_func(const t_keywords&keywords);
      void operator()(char c);
      bool exec(const string&ref);
    };
  public:
    const vector<string>&arr;
  };
  bool go_any_str_from_vec(string&ref,const vector<string>&arr);
public:
  bool go_any_str_from_vec(string&ref,const QapStrFinder&arr);
public:
  bool go_any_str_from_vec_old_and_slow(string&ref,const vector<string>&arr);
};
class t_save_dev:public i_dev
{
public:
  IEnvRTTI&Env;
  string&mem;
public:
  t_save_dev(IEnvRTTI&Env,string&mem);
public:
  void push(t_fallback*ptr);
  void pop(t_fallback*ptr);
public:
  void setPos(int pos);
  void getPos(int&pos);
public:
  IEnvRTTI&getEnv();
public:
  bool isSave();
  bool isLoad();
public:
  bool go_any(string&body,const string&any);
  bool go_any(string&body,const CharMask&any);
  bool go_const_raw(const char*const ptr,size_t size);
  bool go_const(const string&body);
  bool go_end(string&body,const string&aft);
  bool go_any_char(char&body,const string&any);
  bool go_any_char(char&body,const CharMask&any);
public:
  bool go_blob(string&body,size_t count);
public:
  bool go_any_str_from_vec(string&ref,const vector<string>&arr);
  bool go_any_str_from_vec(string&ref,const QapStrFinder&arr);
};
template<class TYPE,class BASE>
static bool go_for_class(i_dev&dev,TAutoPtr<BASE>&out)
{
  TYPE tmp;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  ok=tmp.go(dev);
  if (!ok)return ok;
  auto*p=out.build<TYPE>(dev.getEnv());
  *p=std::move(tmp);
  return ok;
}
template<class TYPE>
static bool go_for_poly(i_dev&dev,TAutoPtr<TYPE>&ref)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (dev.isLoad())
  {
    ok=TYPE::t_poly_impl::go_lt(dev,ref);
  }
  if (dev.isSave())
  {
    ok=TYPE::t_poly_impl::go_st(dev,ref);
  }
  return ok;
}
template<class TYPE>
static bool go_for_item(i_dev&dev,const TYPE&ref,...)
{
  static_assert(false,"d:\\temp\\uidev_fct\\sgon\\QapLexer.inl"":"__FUNCTION__" => so bad :(");
  QapDebugMsg(Sys$$<TYPE>::GetRTTI(dev.getEnv())->GetFullName()+" => no way!");
  return false;
}
template<class T,T v>struct detail_test_value
{
  static const bool value=true;
};
template<class TYPE>struct detail_has_poly_impl
{
  __if_exists(TYPE::t_poly_impl)
{
  static const bool value = true;
}
__if_not_exists(TYPE::t_poly_impl)
{
  static const bool value = false;
}
};
template<
class TYPE,
bool flag=detail_has_poly_impl<TYPE>::value
>struct detail_go_lt_param_is_not_the_same_as_TYPE
{
  static const bool value=!std::is_same<typename get_go_lt_param_type<TYPE>::type,TYPE>::value;
};
template<class TYPE>struct detail_go_lt_param_is_not_the_same_as_TYPE<TYPE,false>
{
  static const bool value=false;
};
template<class TYPE>struct get_go_lt_param_type
{
  template<class U>
  static U func(bool(*)(i_dev&,TAutoPtr<U>&));
  typedef decltype(func(&TYPE::t_poly_impl::go_lt)) type;
};
template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<
  !std::is_polymorphic<TYPE>::value||detail_go_lt_param_is_not_the_same_as_TYPE<TYPE>::value
  ,
  void*
  >::type=nullptr
)
{
  TYPE tmp;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (dev.isSave())
  {
    if (!ref)
    {
      ok=false;
      return ok;
    }
    auto*p=ref.get();
    ok=p->go(dev);
    return ok;
  }
  ok=tmp.go(dev);
  if (!ok)return ok;
  auto*p=ref.build<TYPE>(dev.getEnv());
  *p=std::move(tmp);
  return ok;
}
template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<detail_test_value<bool(*)(i_dev&,TAutoPtr<TYPE>&),&TYPE::t_poly_impl::go_lt>::value,void*>::type=nullptr,
  bool(*pFunc)(i_dev&,TAutoPtr<TYPE>&)=&TYPE::t_poly_impl::go_lt,
  typename std::enable_if<std::is_polymorphic<TYPE>::value,void*>::type=nullptr
)
{
  return go_for_poly(dev,ref);
}
namespace detail
{
  template<class TYPE>struct isTAutoPtr
  {
    static const bool value=false;
  };
  template<class TYPE>struct isTAutoPtr<TAutoPtr<TYPE>>
  {
    static const bool value=true;
  };
};
template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TYPE&ref,
  bool(TYPE::*pFunc)(i_dev&)=&TYPE::go,
  typename std::enable_if<!detail::isTAutoPtr<TYPE>::value,void*>::type=nullptr
)
{
  return (ref.*pFunc)(dev);
}
template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TYPE&ref)
{
  return true;
}
template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TAutoPtr<TYPE>&ref)
{
  return ref;
}
template<class TYPE>
static bool internal_go_for_vec_lt(i_dev&dev,vector<TYPE>&arr)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for (int i=0;;i++)
  {
    t_fallback subscope(dev,__FUNCTION__);
    bool&ok=subscope.ok;
    TYPE tmp;
    ok=go_for_item(dev,tmp);
    if (!ok)break;
    QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
    arr.push_back(std::move(tmp));
  }
  ok=!arr.empty();
  return ok;
}
template<class TYPE>
static bool internal_go_for_vec_st(i_dev&dev,vector<TYPE>&arr)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    ok=go_for_item(dev,ex);
    if (!ok)break;
  }
  return ok;
}
template<class TYPE>
static bool go_for_arr_lt(i_dev&dev,vector<TYPE>&arr)
{
  return internal_go_for_vec_lt(dev,arr);
}
template<class TYPE>
static bool go_for_arr_st(i_dev&dev,vector<TYPE>&arr)
{
  return internal_go_for_vec_st(dev,arr);
}
template<class TYPE>
static bool go_for_item(i_dev&dev,vector<TYPE>&arr)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (dev.isLoad())
  {
    ok=go_for_arr_lt(dev,arr);
  }
  if (dev.isSave())
  {
    ok=go_for_arr_st(dev,arr);
  }
  return ok;
}
string two_text_diff(const string&out,const string&data);;
template<class TYPE>
bool load_obj(IEnvRTTI&Env,TYPE&out,const string&data,int*pmaxpos=nullptr)
{
  TYPE tmp;
  t_load_dev dev(Env,data);
  bool ok=dev.go_auto(tmp);
  if (ok)
  {
    string out;
    t_save_dev dev(Env,out);
    bool ret=dev.go_auto(tmp);
    QapAssert(ok==ret);
    if (ok&&ret)if (out!=data)
      {
        QapDebugMsg(two_text_diff(out,data));
      }
  }
  if (!ok&&pmaxpos)
  {
    *pmaxpos=Clamp<int>(dev.maxpos+1,1,data.size())-1;
  }
  out=std::move(tmp);
  return ok;
}
template<class TYPE>
string load_obj_ex(IEnvRTTI&Env,TYPE&obj,const string&data)
{
  int pos=0;
  bool ok=load_obj(Env,obj,data,&pos);
  string main="{\"ok\":"+BToS(ok)+",\"date\":\""+cur_date_str()+"\"}";
  if (ok)return main;
  auto out=t_error_tool::get_codefrag(data,pos);
  out="{\"offset\":"+IToS(pos)+"}\n"+out;
  return main+"@@@"+out;
}
struct t_load_obj_result
{
  bool ok;
  int pos;
  string msg;
};
template<class TYPE>
t_load_obj_result load_obj_full(IEnvRTTI&Env,TYPE&obj,const string&data)
{
  t_load_obj_result out;
  out.pos=0;
  out.ok=load_obj(Env,obj,data,&out.pos);
  out.msg="{\"ok\":"+BToS(out.ok)+",\"date\":\""+cur_date_str()+"\"}";
  if (out.ok)return out;
  auto buff=t_error_tool::get_codefrag(data,out.pos);
  buff="{\"offset\":"+IToS(out.pos)+"}\n"+buff;
  out.msg+="@@@"+buff;
  return out;
}
template<class TYPE>
bool save_obj(IEnvRTTI&Env,TYPE&inp,string&data)
{
  string mem;
  t_save_dev dev(Env,mem);
  bool ok=dev.go_auto(inp);
  QapAssert(ok);
  if (ok)for (;;)
    {
      TYPE tmp;
      t_load_dev tmp_dev(Env,mem);
      bool ok=tmp_dev.go_auto(tmp);
      QapAssert(ok||mem.empty());
      {
        bool result=TIsSameVisitor::Exec(Env,inp,tmp);
        if (result)break;
      }
      string bin_bef;
      string bin_aft;
      QapPublicUberFullSaverBinMem(Env,QapRawUberObject(inp),bin_bef);
      QapPublicUberFullSaverBinMem(Env,QapRawUberObject(tmp),bin_aft);
      bool err=bin_bef!=bin_aft;
      if (err)
      {
        string txt_bef=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(inp));
        string txt_aft=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(tmp));
        string msg=two_text_diff(txt_aft,txt_bef);
        QapDebugMsg("diff:\n"+msg);
        QapDebugMsg("before:\n"+txt_bef);
        QapDebugMsg("after:\n"+txt_aft);
        return false;
      }
      break;
    }
  data=std::move(mem);
  return ok;
}
class t_config_2013
{
public:
  class t_item
  {
  public:
  public:
    typedef t_config_2013 OwnerClass;;
  public:
    typedef t_item SelfClass;;
  public:
    string type;;
  public:
    void DoReset();
  public:
    t_item(const t_item&)=delete;
    t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_info
  {
  public:
  public:
    typedef t_config_2013 OwnerClass;;
  public:
    typedef t_info SelfClass;;
  public:
    string type;;
    string pos;;
  public:
    void DoReset();
  public:
    t_info(const t_info&)=delete;
    t_info();;
  public:
    t_info(t_info&&_Right);
    void operator=(t_info&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_info";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"pos",int(&(((SelfClass*)nullptr)->*(&SelfClass::pos))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_event
  {
  public:
  public:
    typedef t_config_2013 OwnerClass;;
  public:
    typedef t_event SelfClass;;
  public:
    string time;;
    t_info A;;
    t_info B;;
  public:
    void DoReset();
  public:
    t_event(const t_event&)=delete;
    t_event();;
  public:
    t_event(t_event&&_Right);
    void operator=(t_event&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_event";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"time",int(&(((SelfClass*)nullptr)->*(&SelfClass::time))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<t_info>::GetRTTI(RTTI),"A",int(&(((SelfClass*)nullptr)->*(&SelfClass::A))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<t_info>::GetRTTI(RTTI),"B",int(&(((SelfClass*)nullptr)->*(&SelfClass::B))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_line
  {
  public:
  public:
    typedef t_config_2013 OwnerClass;;
  public:
    typedef t_line SelfClass;;
  public:
    string head;;
    vector<t_item> arr;;
    vector<t_event> events;;
  public:
    void DoReset();
  public:
    t_line(const t_line&)=delete;
    t_line();;
  public:
    t_line(t_line&&_Right);
    void operator=(t_line&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_line";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        Info->AddMemberDEF(Sys$$<vector<t_event>>::GetRTTI(RTTI),"events",int(&(((SelfClass*)nullptr)->*(&SelfClass::events))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_doc
  {
  public:
  public:
    typedef t_config_2013 OwnerClass;;
  public:
    typedef t_doc SelfClass;;
  public:
    vector<t_line> lines;;
  public:
    void DoReset();
  public:
    t_doc(const t_doc&)=delete;
    t_doc();;
  public:
    t_doc(t_doc&&_Right);
    void operator=(t_doc&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_doc";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<vector<t_line>>::GetRTTI(RTTI),"lines",int(&(((SelfClass*)nullptr)->*(&SelfClass::lines))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
public:
  ;
public:
  typedef t_config_2013 SelfClass;;
public:
public:
  void DoReset();
public:
  t_config_2013(const t_config_2013&)=delete;
  t_config_2013();;
public:
  t_config_2013(t_config_2013&&_Right);
  void operator=(t_config_2013&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_config_2013";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<t_info>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<t_event>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<t_line>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<t_doc>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
};
struct t_poly_tool:public t_config_2013
{
  t_doc doc;
  static t_poly_tool&get(IEnvRTTI&Env);
  void save_doc(IEnvRTTI&Env,const string&fn);
public:
  t_line&find(const string&type);
  template<class TYPE>
  vector<t_item>&get_base_arr(IEnvRTTI&Env,const string&basetype,vector<TYPE>&inp)
  {
    auto&base=find(basetype);
    auto&arr=base.arr;
    if (arr.size()==inp.size())return arr;
    QapAssert(base.arr.empty());
    arr.resize(inp.size());
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.type=inp[i].info;
    }
    save_doc(Env,"config.cfg");
    return arr;
  }static int get_mass(const vector<t_item>&arr,const string&type);
public:
  struct t_point
  {
    int id;
    string name;
    vector<int> inp;
    vector<int> out;
    bool passed;
    int group;
  };
public:
  template<class TYPE>
  struct t_out_rec
  {
    string info;
    TAutoPtr<TYPE> object;
    int pos;
    int mass;
    t_out_rec()
    {
      pos=-1;
      mass=-1;
    }
    t_out_rec(t_out_rec&&ref)
    {
      info=std::move(ref.info);
      object=std::move(ref.object);
      pos=ref.pos;
      mass=ref.mass;
    }
  };
public:
  struct t_points
  {
    vector<t_point> arr;
    t_point&find(const string&name);
    void set_passed(bool value);
    void load_points(const vector<string>&inp);
    void load_edges_from_events(const vector<t_event>&events);
    struct t_wave
    {
      t_points&points;
      vector<int> prev;
      vector<int> next;
      int first_id;
      int group;
      bool result;
      void update(int id);
      void run();
    };
    bool isCyclical();
    vector<string> toList();
  };
public:
  typedef t_config_2013::t_event t_event;
  typedef t_config_2013::t_item t_item;
  static vector<string> list_apply_events(const vector<string>&arr,vector<t_event>&events);
  void remake(vector<t_item>&points,vector<t_event>&events);
public:
  template<class TYPE>
  struct go_poly
  {
    vector<t_out_rec<TYPE>>&out_arr;
    i_dev&dev;
    TAutoPtr<TYPE>&ref;
    t_fallback&scope;
    int&count;
    int&first_id;
    const string&strbasetype;
    IEnvRTTI&Env;
    template<class T>
    void go_for()
    {
      t_fallback scope(dev,__FUNCTION__);
      T tmp;
      scope.ok=tmp.go(dev);
      t_out_rec<TYPE> rec;
      static const string strtype=Sys$$<T>::GetRTTI(Env)->GetFullName();
      rec.info=strtype;
      if (scope.ok)
      {
        auto*p=rec.object.build<T>(dev.getEnv());
        *p=std::move(tmp);
        if (!count)first_id=out_arr.size();
        count++;
      }
      dev.getPos(rec.pos);
      out_arr.push_back(std::move(rec));
      scope.ok=false;
    }
    void main()
    {
      typedef t_poly_tool::t_out_rec<TYPE> t_out_rec;
      if (!count)
      {
        scope.ok=false;
        return;
      }
      auto use=[this](t_out_rec&ex)
      {
        QapAssert(ex.object);
        ref=std::move(ex.object);
        dev.setPos(ex.pos);
        scope.ok=true;
      };
      if (count==1)
      {
        auto&ex=out_arr[first_id];
        use(ex);
        return;
      }
      auto&tool=t_poly_tool::get(Env);
      auto&arr=tool.get_base_arr(Env,strbasetype,out_arr);
      vector<t_out_rec> out;
      auto update_mass=[&]()
      {
        for (int i=0;i<out.size();i++)
        {
          auto&ex=out[i];
          ex.mass=t_poly_tool::get_mass(arr,ex.info);
        }
      };
      for (int i=0;i<out_arr.size();i++)
      {
        auto&ex=out_arr[i];
        if (!ex.object)continue;
        out.push_back(std::move(ex));
      }
      update_mass();
      vector<int> idarr;
      idarr.resize(out.size());
      for (int i=0;i<out.size();i++)
      {
        idarr[i]=i;
      }
      if (true)
      {
        auto comp_pos=[&out](const int&a,const int&b)->bool {return out[a].pos>out[b].pos;
                                                            };
        std::sort(std::begin(idarr),std::end(idarr),comp_pos);
        QapAssert(out[idarr[0]].pos>out[idarr[1]].pos);
        int fix_count=0;
        for (int i=1;i<out.size();i++)
        {
          auto&pa=idarr[i-1];
          auto&pb=idarr[i-0];
          auto&a=out[pa];
          auto&b=out[pb];
          auto&base=tool.find(strbasetype);
          auto&events=base.events;
          auto find_event=[&events](const string&a,const string&b)->bool
          {
            for (int i=0;i<events.size();i++)
            {
              if (events[i].A.type!=a)continue;
              if (events[i].B.type!=b)continue;
              return true;
            }
            return false;
          };
          bool flag_ab=find_event(a.info,b.info);
          bool flag_ba=find_event(b.info,a.info);
          QapAssert(!flag_ba);
          if (flag_ab)continue;
          events.push_back(t_config_2013::t_event());
          auto&back=events.back();
          back.time=cur_date_str();
          back.A.pos=IToS(a.pos);
          back.A.type=a.info;
          back.B.pos=IToS(b.pos);
          back.B.type=b.info;
          fix_count++;
        }
        if (fix_count)
        {
          auto&base=tool.find(strbasetype);
          auto&events=base.events;
          tool.remake(base.arr,events);
          tool.save_doc(Env,"config.cfg");
          update_mass();
        }
      }
      auto comp_func=[&out](const int&a,const int&b)->bool {return out[a].mass<out[b].mass;
                                                           };
      std::sort(std::begin(idarr),std::end(idarr),comp_func);
      QapAssert(out[idarr[0]].mass<out[idarr[1]].mass);
      for (int i=1;i<out.size();i++)
      {
        auto&pa=idarr[i-1];
        auto&pb=idarr[i-0];
        auto&a=out[pa];
        auto&b=out[pb];
        if (a.pos>b.pos)continue;
        string msg="wrong mass for:\n";
        msg+="a.info = "+a.info+"\n";
        msg+="a.pos = "+IToS(a.pos)+"\n";
        msg+="b.info = "+b.info+"\n";
        msg+="b.pos = "+IToS(b.pos)+"\n";
        QapDebugMsg(msg);
      }
      use(out[idarr[0]]);
    }
  };
};
class t_number
{
public:
  ;
public:
  typedef t_number SelfClass;;
public:
  string body;;
public:
  void DoReset();
public:
  t_number(const t_number&)=delete;
  t_number();;
public:
  t_number(t_number&&_Right);
  void operator=(t_number&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_number";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class i_str_item
{
  ;
public:
  typedef i_str_item SelfClass;;
public:
public:
  void DoReset();
public:
  i_str_item(const i_str_item&)=delete;
  i_str_item();;
public:
  i_str_item(i_str_item&&_Right);
  void operator=(i_str_item&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="i_str_item";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual bool go(i_dev&dev);;
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_str_item_raw>();;
      go_for<t_str_item_hex>();;
      go_for<t_str_item_num>();;
      go_for<t_str_item_fix>();;
      (void)count;
      (void)first_id;
      (void)out_arr;
      (void)this;
      main();
      return scope.ok;
    }static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
    static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
  };
  virtual string get_code()const;
  virtual string get_value()const;
};
class t_str_item_raw:public i_str_item
{
public:
  ;
public:
  typedef t_str_item_raw SelfClass;
public:
  typedef i_str_item ParentClass;;
public:
  string body;;
public:
  void DoReset();
public:
  t_str_item_raw(const t_str_item_raw&)=delete;
  t_str_item_raw();;
public:
  t_str_item_raw(t_str_item_raw&&_Right);
  void operator=(t_str_item_raw&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_str_item_raw";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_str_item_hex:public i_str_item
{
public:
  ;
public:
  typedef t_str_item_hex SelfClass;
public:
  typedef i_str_item ParentClass;;
public:
  array<char,2> body;;
public:
  void DoReset();
public:
  t_str_item_hex(const t_str_item_hex&)=delete;
  t_str_item_hex();;
public:
  t_str_item_hex(t_str_item_hex&&_Right);
  void operator=(t_str_item_hex&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_str_item_hex";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<array<char,2>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_str_item_num:public i_str_item
{
public:
  ;
public:
  typedef t_str_item_num SelfClass;
public:
  typedef i_str_item ParentClass;;
public:
  array<char,2> body;;
public:
  void DoReset();
public:
  t_str_item_num(const t_str_item_num&)=delete;
  t_str_item_num();;
public:
  t_str_item_num(t_str_item_num&&_Right);
  void operator=(t_str_item_num&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_str_item_num";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<array<char,2>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_str_item_fix:public i_str_item
{
public:
  ;
public:
  typedef t_str_item_fix SelfClass;
public:
  typedef i_str_item ParentClass;;
public:
  char body;;
public:
  void DoReset();
public:
  t_str_item_fix(const t_str_item_fix&)=delete;
  t_str_item_fix();;
public:
  t_str_item_fix(t_str_item_fix&&_Right);
  void operator=(t_str_item_fix&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_str_item_fix";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"SET","'n'");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_str_item
{
public:
  class t_impl
  {
  public:
  public:
    typedef t_str_item OwnerClass;;
  public:
    typedef t_impl SelfClass;;
  public:
    vector<TAutoPtr<i_str_item>> arr;;
  public:
    void DoReset();
  public:
    t_impl(const t_impl&)=delete;
    t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_str_item>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
    string get_code()const;
    string get_value()const;
  };
public:
  ;
public:
  typedef t_str_item SelfClass;;
public:
  string value;;
public:
  void DoReset();
public:
  t_str_item(const t_str_item&)=delete;
  t_str_item();;
public:
  t_str_item(t_str_item&&_Right);
  void operator=(t_str_item&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_str_item";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class i_char_item
{
  ;
public:
  typedef i_char_item SelfClass;;
public:
public:
  void DoReset();
public:
  i_char_item(const i_char_item&)=delete;
  i_char_item();;
public:
  i_char_item(i_char_item&&_Right);
  void operator=(i_char_item&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="i_char_item";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual bool go(i_dev&dev);;
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_char_item_raw>();;
      go_for<t_char_item_hex>();;
      go_for<t_char_item_num>();;
      go_for<t_char_item_fix>();;
      (void)count;
      (void)first_id;
      (void)out_arr;
      (void)this;
      main();
      return scope.ok;
    }static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
    static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
  };
  virtual string get_code()const;
  virtual string get_value()const;
};
class t_char_item_raw:public i_char_item
{
public:
  ;
public:
  typedef t_char_item_raw SelfClass;
public:
  typedef i_char_item ParentClass;;
public:
  string body;;
public:
  void DoReset();
public:
  t_char_item_raw(const t_char_item_raw&)=delete;
  t_char_item_raw();;
public:
  t_char_item_raw(t_char_item_raw&&_Right);
  void operator=(t_char_item_raw&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_char_item_raw";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_char_item_hex:public i_char_item
{
public:
  ;
public:
  typedef t_char_item_hex SelfClass;
public:
  typedef i_char_item ParentClass;;
public:
  array<char,2> body;;
public:
  void DoReset();
public:
  t_char_item_hex(const t_char_item_hex&)=delete;
  t_char_item_hex();;
public:
  t_char_item_hex(t_char_item_hex&&_Right);
  void operator=(t_char_item_hex&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_char_item_hex";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<array<char,2>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_char_item_num:public i_char_item
{
public:
  ;
public:
  typedef t_char_item_num SelfClass;
public:
  typedef i_char_item ParentClass;;
public:
  array<char,4> body;;
public:
  void DoReset();
public:
  t_char_item_num(const t_char_item_num&)=delete;
  t_char_item_num();;
public:
  t_char_item_num(t_char_item_num&&_Right);
  void operator=(t_char_item_num&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_char_item_num";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<array<char,4>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_char_item_fix:public i_char_item
{
public:
  ;
public:
  typedef t_char_item_fix SelfClass;
public:
  typedef i_char_item ParentClass;;
public:
  char body;;
public:
  void DoReset();
public:
  t_char_item_fix(const t_char_item_fix&)=delete;
  t_char_item_fix();;
public:
  t_char_item_fix(t_char_item_fix&&_Right);
  void operator=(t_char_item_fix&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_char_item_fix";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"SET","'\\0'");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
class t_char_item
{
public:
  class t_impl
  {
  public:
  public:
    typedef t_char_item OwnerClass;;
  public:
    typedef t_impl SelfClass;;
  public:
    TAutoPtr<i_char_item> body;;
  public:
    void DoReset();
  public:
    t_impl(const t_impl&)=delete;
    t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<TAutoPtr<i_char_item>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
    string get_code()const;
    string get_value()const;
  };
public:
  ;
public:
  typedef t_char_item SelfClass;;
public:
  string value;;
public:
  void DoReset();
public:
  t_char_item(const t_char_item&)=delete;
  t_char_item();;
public:
  t_char_item(t_char_item&&_Right);
  void operator=(t_char_item&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_char_item";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get_code()const;
  string get_value()const;
};
void RegAllCppLex(IEnvRTTI&Env);
class i_sep
{
  ;
public:
  typedef i_sep SelfClass;;
public:
public:
  void DoReset();
public:
  i_sep(const i_sep&)=delete;
  i_sep();;
public:
  i_sep(i_sep&&_Right);
  void operator=(i_sep&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="i_sep";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual bool go(i_dev&dev);;
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_sep_seq>();;
      go_for<t_c_comment>();;
      go_for<t_cpp_comment>();;
      (void)count;
      (void)first_id;
      (void)out_arr;
      (void)this;
      main();
      return scope.ok;
    }static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
    static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
  };
  virtual string make_code()const;
};
class i_expr
{
  ;
public:
  typedef i_expr SelfClass;;
public:
public:
  void DoReset();
public:
  i_expr(const i_expr&)=delete;
  i_expr();;
public:
  i_expr(i_expr&&_Right);
  void operator=(i_expr&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="i_expr";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  virtual bool go(i_dev&dev);;
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_str>();;
      go_for<t_char>();;
      go_for<t_num>();;
      go_for<t_id>();;
      go_for<t_sign>();;
      go_for<t_soft_brackets>();;
      go_for<t_hard_brackets>();;
      go_for<t_curly_brackets>();;
      (void)count;
      (void)first_id;
      (void)out_arr;
      (void)this;
      main();
      return scope.ok;
    }static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
    static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
  };
};
class t_sep_seq:public i_sep
{
public:
  ;
public:
  typedef t_sep_seq SelfClass;
public:
  typedef i_sep ParentClass;;
public:
  string body;;
public:
  void DoReset();
public:
  t_sep_seq(const t_sep_seq&)=delete;
  t_sep_seq();;
public:
  t_sep_seq(t_sep_seq&&_Right);
  void operator=(t_sep_seq&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_sep_seq";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string make_code()const;
};
class t_c_comment:public i_sep
{
public:
  ;
public:
  typedef t_c_comment SelfClass;
public:
  typedef i_sep ParentClass;;
public:
  string body;;
public:
  void DoReset();
public:
  t_c_comment(const t_c_comment&)=delete;
  t_c_comment();;
public:
  t_c_comment(t_c_comment&&_Right);
  void operator=(t_c_comment&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_c_comment";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string make_code()const;
};
class t_cpp_comment:public i_sep
{
public:
  ;
public:
  typedef t_cpp_comment SelfClass;
public:
  typedef i_sep ParentClass;;
public:
  string body;;
public:
  void DoReset();
public:
  t_cpp_comment(const t_cpp_comment&)=delete;
  t_cpp_comment();;
public:
  t_cpp_comment(t_cpp_comment&&_Right);
  void operator=(t_cpp_comment&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_cpp_comment";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string make_code()const;
};
class t_sep
{
public:
  class t_impl
  {
  public:
  public:
    typedef t_sep OwnerClass;;
  public:
    typedef t_impl SelfClass;;
  public:
    vector<TAutoPtr<i_sep>> arr;;
  public:
    void DoReset();
  public:
    t_impl(const t_impl&)=delete;
    t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_sep>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
    string make_code()const;
  };
public:
  ;
public:
  typedef t_sep SelfClass;;
public:
  string value;;
public:
  void DoReset();
public:
  t_sep(const t_sep&)=delete;
  t_sep();;
public:
  t_sep(t_sep&&_Right);
  void operator=(t_sep&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_sep";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string make_code()const;
};
class t_str:public i_expr
{
public:
  ;
public:
  typedef t_str SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  t_str_item body;;
public:
  void DoReset();
public:
  t_str(const t_str&)=delete;
  t_str();;
public:
  t_str(t_str&&_Right);
  void operator=(t_str&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_str";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<t_str_item>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_char:public i_expr
{
public:
  ;
public:
  typedef t_char SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  t_char_item body;;
public:
  void DoReset();
public:
  t_char(const t_char&)=delete;
  t_char();;
public:
  t_char(t_char&&_Right);
  void operator=(t_char&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_char";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<t_char_item>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_num:public i_expr
{
public:
  ;
public:
  typedef t_num SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  t_number body;;
public:
  void DoReset();
public:
  t_num(const t_num&)=delete;
  t_num();;
public:
  t_num(t_num&&_Right);
  void operator=(t_num&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_num";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<t_number>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_name
{
public:
  class t_keyword
  {
  public:
    typedef t_name OwnerClass;;
  public:
    typedef t_keyword SelfClass;;
  public:
    string value;;
  public:
    void DoReset();
  public:
    t_keyword(const t_keyword&)=delete;
    t_keyword();;
  public:
    t_keyword(t_keyword&&_Right);
    void operator=(t_keyword&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_keyword";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_impl
  {
  public:
  public:
    typedef t_name OwnerClass;;
  public:
    typedef t_impl SelfClass;;
  public:
    char A;;
    string B;;
  public:
    void DoReset();
  public:
    t_impl(const t_impl&)=delete;
    t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"A",int(&(((SelfClass*)nullptr)->*(&SelfClass::A))),"SET","'A'");;
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"B",int(&(((SelfClass*)nullptr)->*(&SelfClass::B))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
    string get()const;
  };
  class t_impl_ex
  {
  public:
    typedef t_name OwnerClass;;
  public:
    typedef t_impl_ex SelfClass;;
  public:
    t_impl impl;;
  public:
    void DoReset();
  public:
    t_impl_ex(const t_impl_ex&)=delete;
    t_impl_ex();;
  public:
    t_impl_ex(t_impl_ex&&_Right);
    void operator=(t_impl_ex&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl_ex";;;
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"impl",int(&(((SelfClass*)nullptr)->*(&SelfClass::impl))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  ;
public:
  typedef t_name SelfClass;;
public:
  string value;;
public:
  void DoReset();
public:
  t_name(const t_name&)=delete;
  t_name();;
public:
  t_name(t_name&&_Right);
  void operator=(t_name&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_name";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
        Info->AddNested(Sys$$<t_keyword>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;
        Info->AddNested(Sys$$<t_impl_ex>::GetRTTI(RTTI));;;
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  string get()const;
};
class t_id:public i_expr
{
public:
  ;
public:
  typedef t_id SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  t_name body;;
public:
  void DoReset();
public:
  t_id(const t_id&)=delete;
  t_id();;
public:
  t_id(t_id&&_Right);
  void operator=(t_id&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_id";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<t_name>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_sign:public i_expr
{
public:
  ;
public:
  typedef t_sign SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  char body;;
public:
  void DoReset();
public:
  t_sign(const t_sign&)=delete;
  t_sign();;
public:
  t_sign(t_sign&&_Right);
  void operator=(t_sign&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_sign";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"SET","'?'");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_soft_brackets:public i_expr
{
public:
  ;
public:
  typedef t_soft_brackets SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  vector<TAutoPtr<i_expr>> arr;;
public:
  void DoReset();
public:
  t_soft_brackets(const t_soft_brackets&)=delete;
  t_soft_brackets();;
public:
  t_soft_brackets(t_soft_brackets&&_Right);
  void operator=(t_soft_brackets&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_soft_brackets";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_hard_brackets:public i_expr
{
public:
  ;
public:
  typedef t_hard_brackets SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  vector<TAutoPtr<i_expr>> arr;;
public:
  void DoReset();
public:
  t_hard_brackets(const t_hard_brackets&)=delete;
  t_hard_brackets();;
public:
  t_hard_brackets(t_hard_brackets&&_Right);
  void operator=(t_hard_brackets&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_hard_brackets";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_curly_brackets:public i_expr
{
public:
  ;
public:
  typedef t_curly_brackets SelfClass;
public:
  typedef i_expr ParentClass;;
public:
  vector<TAutoPtr<i_expr>> arr;;
public:
  void DoReset();
public:
  t_curly_brackets(const t_curly_brackets&)=delete;
  t_curly_brackets();;
public:
  t_curly_brackets(t_curly_brackets&&_Right);
  void operator=(t_curly_brackets&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_curly_brackets";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_param
{
public:
  ;
public:
  typedef t_param SelfClass;;
public:
  t_sep sep;;
  vector<TAutoPtr<i_expr>> body;;
public:
  void DoReset();
public:
  t_param(const t_param&)=delete;
  t_param();;
public:
  t_param(t_param&&_Right);
  void operator=(t_param&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_param";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
};
class t_line
{
public:
  ;
public:
  typedef t_line SelfClass;;
public:
  t_name cmd;;
  vector<t_param> params;;
public:
  void DoReset();
public:
  t_line(const t_line&)=delete;
  t_line();;
public:
  t_line(t_line&&_Right);
  void operator=(t_line&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      static const string Name="t_line";;;
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      Info->AddMemberDEF(Sys$$<t_name>::GetRTTI(RTTI),"cmd",int(&(((SelfClass*)nullptr)->*(&SelfClass::cmd))),"DEF","$");;
      Info->AddMemberDEF(Sys$$<vector<t_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");;
      {
        RTTI.OnRegEnd(Info);
      }
      {
      }
      Info->SelfTesting();
      return Info;
    }static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
  vector<string> get_raw_params(IEnvRTTI&Env);
};
void QapLexerRegAll(IEnvRTTI&Env);
#pragma once
class TSimpleBinarySaver:public IVisitorRTTI
{
public:
  typedef TSimpleBinarySaver SelfClass;
public:
  struct t_dev
  {
    QapIO&IO;
    void*pValue;
    vector<void*> stack;
    void push();
    void pop();
  };
public:
  t_dev&dev;
  TSimpleBinarySaver(t_dev&dev);
public:
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TYPE*p)
  {
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    TDataIO IO;
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return IO.IO.mem;
  }static string toStrEx(TType*pType,void*pValue);
  static void toIO(QapIO&IO,TRawPtr&ptr);
public:
  void Do(TTypeStruct*p);
  void Do(TTypeSys*p);
  void Do(TTypeVector*p);
  void Do(TTypeArray*p);
  void Do(TTypeSelfPtr*p);
  void Do(TTypeAutoPtr*p);
  void Do(TTypeWeakPtr*p);
  void Do(TTypeHardPtr*p);
  void Do(TTypeVoidPtr*p);
  void Do(TTypeFieldPtr*p);
};
class TSimpleBinaryLoader:public IVisitorRTTI
{
public:
  typedef TSimpleBinaryLoader SelfClass;
public:
  struct t_dev
  {
    QapIO&IO;
    void*pValue;
    vector<void*> stack;
    void push();
    void pop();
  };
public:
  t_dev&dev;
  TSimpleBinaryLoader(t_dev&dev);
public:
  template<class TYPE>
  static bool fromIO(IEnvRTTI&Env,TYPE*p,QapIO&IO)
  {
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }static bool fromIOEx(IEnvRTTI&Env,const TRawPtr&ptr,QapIO&IO);
  template<class TYPE>
  static bool fromStr(IEnvRTTI&Env,TYPE*p,const string&source)
  {
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }static bool fromStrEx(const string&source,TType*pType,void*pValue);
  static bool fromStrEx(const string&source,TRawPtr&ptr);
  static bool fromStrEx(QapIO&IO,TRawPtr&ptr);
public:
  void Do(TTypeStruct*p);
  void Do(TTypeSys*p);
  void Do(TTypeVector*p);
  void Do(TTypeArray*p);
  void Do(TTypeSelfPtr*p);
  void Do(TTypeAutoPtr*p);
  void Do(TTypeWeakPtr*p);
  void Do(TTypeHardPtr*p);
  void Do(TTypeVoidPtr*p);
  void Do(TTypeFieldPtr*p);
};
template<class TYPE>
static bool qap_simple_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source)
{
  string mem=TSimpleBinarySaver::toStr(Env,&source);
  return TSimpleBinaryLoader::fromStr(Env,&dest,mem);
}
bool qap_simple_clone_unsafe(TType*pType,void*pDest,void*pSource);

#include "t_inl_file_lexem.h"
#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//-------------------------------------------//
// Warning! This is result of code generation. Don't try to read it!
//-------------------------------------------//
#if(defined(_CSTDLIB_)||defined(_WINDOWS_))
  static_assert(false,"fail");
#endif
//-------------------------------------------//
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

#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <ws2tcpip.h>

#include <windows.h>
#undef DrawText
#include <d3d9.h>
#pragma comment(lib,"d3d9")
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <array>
#include <bitset>
#include <time.h>
#include <math.h>
#include <shellapi.h>
#pragma comment(lib,"shell32")
#pragma comment(lib,"Gdi32.lib")

#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::iostream;
using std::stringstream;
using std::array;
typedef double real;
typedef INT64 int64;
typedef UINT64 uint64;
typedef unsigned int uint;
typedef unsigned char uchar;
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
#ifndef DEF_BUILD_MICRO
  #if(defined(_DEBUG)||defined(QAP_DEBUG))
    #define QapDbgBreak(){struct t_open_mp_workaround{static void crash(){__asm{int 3}}};t_open_mp_workaround::crash();/*_CrtDbgBreak();*/}
    #define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}  
    #define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}
    #define QapNoWay(){QapDebugMsg("no way!");}
  #else
    #define QapAssert(_Expression)if(bool(_Expression)){};
    #define QapDebugMsg(_Message)
    #define QapNoWay()
  #endif
#endif //DEF_BUILD_MICRO//

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
inline static int max(int a,int b)
{
  return a>b?a:b;
}
inline static int min(int a,int b)
{
  return a<b?a:b;
}
inline static float max(float a,float b)
{
  return a>b?a:b;
}
inline static float min(float a,float b)
{
  return a<b?a:b;
}
inline static double max(double a,double b)
{
  return a>b?a:b;
}
inline static double min(double a,double b)
{
  return a<b?a:b;
}
template<typename TYPE>TYPE Sign(TYPE value)
{
  if(value>0)
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
};
inline TScreenMode GetScreenMode()
{
  HDC DC=GetDC(0);
  TScreenMode Res={GetDeviceCaps(DC,HORZRES),GetDeviceCaps(DC,VERTRES),GetDeviceCaps(DC,BITSPIXEL),GetDeviceCaps(DC,VREFRESH)};
  ReleaseDC(0,DC);
  return Res;
}
inline string IToS(const int&val)
{
  char c[16];
  _itoa_s(val,c,10);
  return string(c);
}
enum QapMsgBoxRetval
{
  qmbrSkip,qmbrBreak,qmbrIgnore
};
inline void QapShowCursor(bool bShow){if(bShow){while(ShowCursor(true)<0);}else{while(ShowCursor(false)>=0);}}
static bool g_need_show_cursor=true;
inline int WinMessageBox(const string&caption,const string&text)
{
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  #ifdef _OPENMP
    full_text="omp_get_thread_num() : "+IToS(omp_get_thread_num())+"\n\n"+full_text;
  #endif
  if(!g_need_show_cursor)QapShowCursor(true);
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  if(!g_need_show_cursor)QapShowCursor(false);
  QapMsgBoxRetval retval=qmbrSkip;
  if(IDCONTINUE==nCode)retval=qmbrIgnore;
  if(IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
}
#define ShowCursor(flag)QapShowCursor(g_need_show_cursor=(flag))
typedef int(*TQapMessageBox)(const string&caption,const string&text);
struct TMessageBoxCaller
{
  static int Call(const string&caption,const string&text)
  {
    return Get()(caption,text);
  }
  static TQapMessageBox&Get()
  {
    static TQapMessageBox func=WinMessageBox;
    return func;
  }
  struct t_hack
  {
    TQapMessageBox old;
    t_hack(TQapMessageBox func)
    {
      old=Get();
      Get()=func;
    }
    ~t_hack()
    {
      Get()=old;
    }
  };
};
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+IToS(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nAssertion failed :\n"+exp;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Assertion failed",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+IToS(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nDebug message :\n"+msg;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Debug message",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}

struct t_${
  template<class TYPE>static void set(vector<TYPE>&arr,const t_$&){arr.clear();}
  template<class TYPE>static void set(TYPE&,const t_$&){}
  template<class TYPE>static void set(TYPE&a,TYPE&b){a=b;}
  template<class TYPE>static void set(TYPE&a,const TYPE&b){a=b;}
  template<class TYPE>static void set(TYPE&a,typename TYPE::OwnerClass*b){a=b;}
  template<class TYPE>static void set(TYPE*&a,nullptr_t b){a=b;}
  static void set(int&a,int b){a=b;}
  static void set(unsigned&a,unsigned b){a=b;}
  static void set(char&a,char b){a=b;}
  static void set(uchar&a,uchar b){a=b;}
  static void set(real&a,real b){a=b;}
  static void set(real&a,int b){a=b;}
  static void set(float&a,real b){a=b;}
  static void set(float&a,int b){a=b;}
  #define T$LIST(F)F(int)F(unsigned)F(char)F(uchar)F(real)F(float)F(bool)
  #define F(TYPE)static void set(TYPE&a,const t_$&){a=0;}
  T$LIST(F)
  #undef F
  #undef T$LIST
  template<int n>
  static void set(string&a,const char(&b)[n]){a=b;}
};

inline string UpperStr(const string&s){string str=s;for(int i=0;i<int(str.size());i++)str[i]=toupper(str[i]);return std::move(str);}
inline string LowerStr(const string&s){string str=s;for(int i=0;i<str.size();i++)str[i]=tolower(str[i]);return std::move(str);}

static vector<string> split(const string&s,const string&needle)
{
  vector<string> arr;
  if(s.empty())return arr;
  size_t p=0;
  for(;;){
    auto pos=s.find(needle,p);
    if(pos==std::string::npos){arr.push_back(s.substr(p));return arr;}
    arr.push_back(s.substr(p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}
//-------------------------------------------//
static string join(const vector<string>&arr,const string&glue)
{
  string out;
  size_t c=0;
  size_t dc=glue.size();
  for(int i=0;i<arr.size();i++){if(i)c+=dc;c+=arr[i].size();}
  out.reserve(c);
  for(int i=0;i<arr.size();i++){if(i)out+=glue;out+=arr[i];}
  return out;
}

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
  template<class TYPE>
  static void FieldTryDoReset(TYPE&p,...) {}
  template<class TYPE,size_t SIZE>static void FieldTryDoReset(array<TYPE,SIZE>&arr)
  {
    for (int i=0;i<SIZE;i++)FieldTryDoReset(arr[i]);
  }
  static void FieldTryDoReset(unsigned short&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(short&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(bool&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(int&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(size_t&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(float&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(double&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(char&ref)
  {
    ref=0;
  };
  static void FieldTryDoReset(uchar&ref)
  {
    ref=0;
  };
};
/*TMemory - ���������� ��������� ������*/
class TMemory
{
public:
  struct ptr_t {};
  ptr_t*ptr;
  int size;
  TMemory():ptr(nullptr),size(0) {}
  operator bool()const
  {
    QapAssert(bool(ptr)==bool(size));
    return ptr;
  }
  void operator=(nullptr_t)
  {
    ptr=nullptr;
    size=0;
  }
  void operator=(TMemory&&_Right)
  {
    ptr=_Right.ptr;
    _Right.ptr=nullptr;
    size=_Right.size;
    _Right.size=0;
  }
};
#pragma once
const real Pi  =4.0*atan(1.0);
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
template<class TYPE,class FUNC>
void clean_if(vector<TYPE>&Arr,FUNC&Pred)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(Pred(ex))continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr){arr.push_back(TYPE());return arr.back();}
class vec2d
{
public:
public:
  typedef vec2d SelfClass;
public:
  real x;
  real y;
public:
public:
  vec2d():x(0.0),y(0.0) {}
  vec2d(const real&x,const real&y):x(x),y(y) {}
  vec2d(const vec2d&v):x(v.x),y(v.y) {}
  void operator=(const vec2d&v)
  {
    x=v.x;
    y=v.y;
  }
  vec2d operator+()const
  {
    return *this;
  }
  vec2d operator-()const
  {
    return vec2d(-x,-y);
  }
  void operator+=(const vec2d&v)
  {
    x+=v.x;
    y+=v.y;
  }
  void operator-=(const vec2d&v)
  {
    x-=v.x;
    y-=v.y;
  }
  void operator*=(const real&f)
  {
    x*=f;
    y*=f;
  }
  void operator/=(const real&f)
  {
    x/=f;
    y/=f;
  }
public:
  vec2d Rot(const vec2d&OX)const
  {
    real M=OX.Mag();
    return vec2d(((x*+OX.x)+(y*OX.y))/M,((x*-OX.y)+(y*OX.x))/M);
  }
  vec2d UnRot(const vec2d&OX)const
  {
    real M=OX.Mag();
    if(M==0.0f)
    {
      return vec2d(0,0);
    }
    ;
    return vec2d(((x*OX.x)+(y*-OX.y))/M,((x*OX.y)+(y*+OX.x))/M);
  }
  vec2d Ort()const
  {
    return vec2d(-y,x);
  }
  vec2d Norm()const
  {
    if((x==0)&&(y==0))
    {
      return vec2d(0,0);
    }
    auto inv_m=1.0/this->Mag();
    return vec2d(x*inv_m,y*inv_m);
  }
  vec2d SetMag(const real&val)const
  {
    return this->Norm()*val;
  }
  vec2d Mul(const vec2d&v)const
  {
    return vec2d(x*v.x,y*v.y);
  }
  vec2d Div(const vec2d&v)const
  {
    return vec2d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y);
  }
  real GetAng()const
  {
    return atan2(y,x);
  }
  real Mag()const
  {
    return sqrt(x*x+y*y);
  }
  real SqrMag()const
  {
    return x*x+y*y;
  }
public:
  friend vec2d operator+(const vec2d&u,const vec2d&v)
  {
    return vec2d(u.x+v.x,u.y+v.y);
  }
  friend vec2d operator-(const vec2d&u,const vec2d&v)
  {
    return vec2d(u.x-v.x,u.y-v.y);
  }
  friend vec2d operator*(const vec2d&u,const real&v)
  {
    return vec2d(u.x*v,u.y*v);
  }
  friend vec2d operator*(const real&u,const vec2d&v)
  {
    return vec2d(u*v.x,u*v.y);
  }
  friend bool operator==(const vec2d&u,const vec2d&v)
  {
    return (u.x==v.x)&&(u.y==v.y);
  }
  friend bool operator!=(const vec2d&u,const vec2d&v)
  {
    return (u.x!=v.x)||(u.y!=v.y);
  }
public:
  real dist_to(const vec2d&p)const{return (p-*this).Mag();}
  real sqr_dist_to(const vec2d&p)const{return (p-*this).SqrMag();}
  bool dist_to_point_less_that_r(const vec2d&p,real r)const{return (p-*this).SqrMag()<r*r;}
public:
  //static vec2d vec2d_min
  static vec2d min(const vec2d&a,const vec2d&b)
  {
    return vec2d(std::min(a.x,b.x),std::min(a.y,b.y));
  }
  //static vec2d vec2d_max
  static vec2d max(const vec2d&a,const vec2d&b)
  {
    return vec2d(std::max(a.x,b.x),std::max(a.y,b.y));
  }
  static void comin(vec2d&a,const vec2d&b){a=min(a,b);}
  static void comax(vec2d&a,const vec2d&b){a=max(a,b);}
  void comin(const vec2d&b){auto&a=*this;a=min(a,b);}
  void comax(const vec2d&b){auto&a=*this;a=max(a,b);}
  static vec2d sign(const vec2d&p){return vec2d(Sign(p.x),Sign(p.y));}
};
inline static real dot(const vec2d&a,const vec2d&b){return a.x*b.x+a.y*b.y;}
inline static real cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
class QapColor
{
public:
  typedef uchar byte;
public:
public:
  typedef QapColor SelfClass;
public:
  uchar b;
  uchar g;
  uchar r;
  uchar a;
public:
public:
  QapColor():b(255),g(255),r(255),a(255) {}
  QapColor(byte A,byte R,byte G,byte B):a(A),r(R),g(G),b(B) {}
  QapColor(byte R,byte G,byte B):a(255),r(R),g(G),b(B) {}
  QapColor(const QapColor& v):a(v.a),r(v.r),g(v.g),b(v.b) {}
public:
  QapColor&operator=(const QapColor&v)
  {
    a=v.a;
    r=v.r;
    g=v.g;
    b=v.b;
    return *this;
  }
  QapColor operator+()const
  {
    return *this;
  }
public:
  QapColor&operator*=(const QapColor&v)
  {
    {
      a=Clamp(int(a)*int(v.a)/int(255),int(0),int(255));
    }
    {
      r=Clamp(int(r)*int(v.r)/int(255),int(0),int(255));
    }
    {
      g=Clamp(int(g)*int(v.g)/int(255),int(0),int(255));
    }
    {
      b=Clamp(int(b)*int(v.b)/int(255),int(0),int(255));
    }
    return *this;
  }
  QapColor&operator+=(const QapColor&v)
  {
    {
      a=Clamp(int(a)+int(v.a),int(0),int(255));
    }
    {
      r=Clamp(int(r)+int(v.r),int(0),int(255));
    }
    {
      g=Clamp(int(g)+int(v.g),int(0),int(255));
    }
    {
      b=Clamp(int(b)+int(v.b),int(0),int(255));
    }
    return *this;
  }
  QapColor&operator-=(const QapColor&v)
  {
    {
      a=Clamp(int(a)-int(v.a),int(0),int(255));
    }
    {
      r=Clamp(int(r)-int(v.r),int(0),int(255));
    }
    {
      g=Clamp(int(g)-int(v.g),int(0),int(255));
    }
    {
      b=Clamp(int(b)-int(v.b),int(0),int(255));
    }
    return *this;
  }
  QapColor operator*(const QapColor&v)const
  {
    return QapColor(int(int(a)*int(v.a))/int(255),int(int(r)*int(v.r))/int(255),int(int(g)*int(v.g))/int(255),int(int(b)*int(v.b))/int(255));
  }
  QapColor operator+(const QapColor&v)const
  {
    return QapColor(Clamp(int(a)+int(v.a),int(0),int(255)),Clamp(int(r)+int(v.r),int(0),int(255)),Clamp(int(g)+int(v.g),int(0),int(255)),Clamp(int(b)+int(v.b),int(0),int(255)));
  }
  QapColor operator-(const QapColor&v)const
  {
    return QapColor(Clamp(int(a)-int(v.a),int(0),int(255)),Clamp(int(r)-int(v.r),int(0),int(255)),Clamp(int(g)-int(v.g),int(0),int(255)),Clamp(int(b)-int(v.b),int(0),int(255)));
  }
public:
  QapColor&operator*=(real f)
  {
    {
      b=byte(Clamp(real(b)*f,0.0,255.0));
    }
    ;
    {
      g=byte(Clamp(real(g)*f,0.0,255.0));
    }
    ;
    {
      r=byte(Clamp(real(r)*f,0.0,255.0));
    }
    ;
    return *this;
  }
  QapColor&operator/=(real r)
  {
    real f=1.0/r;
    {
      b=byte(Clamp(real(b)*f,0.0,255.0));
    }
    ;
    {
      g=byte(Clamp(real(g)*f,0.0,255.0));
    }
    ;
    {
      r=byte(Clamp(real(r)*f,0.0,255.0));
    }
    ;
    return *this;
  }
public:
  QapColor(const D3DCOLOR& v)
  {
    *((D3DCOLOR*)(void*)this)=v;
  }
  operator D3DCOLOR&()const
  {
    return *(DWORD*)this;
  };
public:
public:
  byte GetLuminance()const
  {
    return int(int(r)+int(g)+int(b))/int(3);
  }
  QapColor toGray()const
  {
    auto l=GetLuminance();
    return QapColor(a,l,l,l);
  }
  inline static QapColor Mix(const QapColor&A,const QapColor&B,const real&t)
  {
    real ct=Clamp(t,0.0,1.0);
    real tA=1.0-ct;
    real tB=ct;
    QapColor O;
    {
      O.b=byte(Clamp(real(A.b)*tA+real(B.b)*tB,0.0,255.0));
    }
    {
      O.g=byte(Clamp(real(A.g)*tA+real(B.g)*tB,0.0,255.0));
    }
    {
      O.r=byte(Clamp(real(A.r)*tA+real(B.r)*tB,0.0,255.0));
    }
    {
      O.a=byte(Clamp(real(A.a)*tA+real(B.a)*tB,0.0,255.0));
    }
    return O;
  }
  inline static QapColor HalfMix(const QapColor&A,const QapColor&B)
  {
    QapColor O;
    {
      O.b=(int(A.b)+int(B.b))>>1;
    }
    {
      O.g=(int(A.g)+int(B.g))>>1;
    }
    {
      O.r=(int(A.r)+int(B.r))>>1;
    }
    {
      O.a=(int(A.a)+int(B.a))>>1;
    }
    return O;
  }
  inline QapColor inv_rgb()const{return QapColor(a,0xff-r,0xff-g,0xff-b);}
  inline QapColor swap_rg()const{return QapColor(a,b,g,r);}
};
union vec4i
{
public:
  struct
  {
    int x,y,z,w;
  };
  struct
  {
    int b,g,r,a;
  };
  vec4i():x(0),y(0),z(0),w(0){}
  vec4i(int b,int g,int r,int a):b(b),g(g),r(r),a(a) {}
  vec4i(const QapColor&ref):b(ref.b),g(ref.g),r(ref.r),a(ref.a) {}
  vec4i&operator+=(const vec4i&v)
  {
    b+=v.b;
    g+=v.g;
    r+=v.r;
    a+=v.a;
    return *this;
  }
  vec4i operator*(const int&v)
  {
    return vec4i(x*v,y*v,z*v,w*v);
  }
  vec4i operator/(const int&v)
  {
    return vec4i(x/v,y/v,z/v,w/v);
  }
  vec4i operator+(const vec4i&v)
  {
    return vec4i(x+v.x,y+v.y,z+v.z,w+v.w);
  }
  void operator>>=(const int&v){x>>=v;y>>=v;z>>=v;w>>=v;}
  vec4i operator>>(const int&v){return vec4i(x>>v,y>>v,z>>v,w>>v);}
  QapColor GetColor()
  {
    return QapColor(Clamp(int(a),int(0),int(255)),Clamp(int(r),int(0),int(255)),Clamp(int(g),int(0),int(255)),Clamp(int(b),int(0),int(255)));
  }
  QapColor unsafe_but_fast_GetColor(){
    QapAssert(x>=0&&x<256);
    QapAssert(y>=0&&y<256);
    QapAssert(z>=0&&z<256);
    QapAssert(w>=0&&w<256);
    return QapColor(x,y,z,w);
  }
  QapColor unsafe_but_fast_GetColor_without_asserts(){
    return QapColor(x,y,z,w);
  }
};
struct vec3d{
public:
  real x,y,z;
public:
  typedef vec3d SelfClass;
  vec3d():x(0.0),y(0.0),z(0.0){}
  vec3d(const real&x,const real&y,const real&z):x(x),y(y),z(z){}
  vec3d(const vec3d&v):x(v.x),y(v.y),z(v.z){}
  vec3d operator+()const{return *this;}
  vec3d operator-()const{return vec3d(-x,-y,-z);}
public:
  #define LIST(F,G)F(x,G)F(y,G)F(z,G)
  #define F(x,OPER)x##OPER##v.x;
  #define U(OPER)void operator##OPER##(const SelfClass&v){LIST(F,OPER)}
  U(=)U(+=)U(-=)
  #undef U
  #undef F
  #undef LIST
  void operator*=(const real&f)
  {
    x*=f;
    y*=f;
    z*=f;
  }
  void operator/=(const real&f)
  {
    x/=f;
    y/=f;
    z/=f;
  }
public:
  vec3d Norm()const
  {
    if((x==0)&&(y==0)&&(z==0))
    {
      return vec3d(0,0,0);
    }
    auto inv_m=1.0/this->Mag();
    return vec3d(x*inv_m,y*inv_m,z*inv_m);
  }
  vec3d SetMag(const real&val)const
  {
    return this->Norm()*val;
  }
  vec3d Mul(const vec3d&v)const
  {
    return vec3d(x*v.x,y*v.y,z*v.z);
  }
  vec3d Div(const vec3d&v)const
  {
    return vec3d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y,v.z!=0?z/v.z:z);
  }
  real Mag()const
  {
    return sqrt(x*x+y*y+z*z);
  }
  real SqrMag()const
  {
    return x*x+y*y+z*z;
  }
public:
  friend vec3d operator+(const vec3d&u,const vec3d&v)
  {
    return vec3d(u.x+v.x,u.y+v.y,u.z+v.z);
  }
  friend vec3d operator-(const vec3d&u,const vec3d&v)
  {
    return vec3d(u.x-v.x,u.y-v.y,u.z-v.z);
  }
  friend vec3d operator*(const vec3d&u,const real&v)
  {
    return vec3d(u.x*v,u.y*v,u.z*v);
  }
  friend vec3d operator*(const real&u,const vec3d&v)
  {
    return vec3d(u*v.x,u*v.y,u*v.z);
  }
  friend bool operator==(const vec3d&u,const vec3d&v)
  {
    return (u.x==v.x)&&(u.y==v.y)&&(u.z==v.z);
  }
  friend bool operator!=(const vec3d&u,const vec3d&v)
  {
    return (u.x!=v.x)||(u.y!=v.y)||(u.z!=v.z);
  }
};
class vec3f:public D3DVECTOR{
public:
  //float x,y,z;
  vec3f(const D3DVECTOR&v):D3DVECTOR(v){}
  vec3f(){x=0;y=0;z=0;}
  vec3f(float x,float y,float z)
  {
    #define F(a)this->a=a;
    F(x);F(y);F(z);
    #undef F
  }
public:
  friend vec3f operator*(const float&u,const vec3f&v)
  {
    return vec3f(v.x*u,v.y*u,v.z*u);
  }
  friend vec3f operator*(const vec3f&v,const float&u)
  {
    return vec3f(v.x*u,v.y*u,v.z*u);
  }
  friend vec3f operator+(const vec3f&v,const vec3f&u)
  {
    return vec3f(v.x+u.x,v.y+u.y,v.z+u.z);
  }
  friend vec3f operator-(const vec3f&v,const vec3f&u)
  {
    return vec3f(v.x-u.x,v.y-u.y,v.z-u.z);
  }
  void operator*=(const float&k)
  {
    x*=k;
    y*=k;
    z*=k;
  }
  bool operator==(const vec3f&v)const
  {
    auto&a=*this;
    bool xok=a.x==v.x;
    bool yok=a.y==v.y;
    bool zok=a.z==v.z;
    return xok&&yok&&zok;
  }
  bool operator!=(const vec3f&v)const
  {
    return !operator==(v);
  }
  void operator+=(const vec3f&v)
  {
    x+=v.x;
    y+=v.y;
    z+=v.z;
  }
  void operator-=(const vec3f&v)
  {
    x-=v.x;
    y-=v.y;
    z-=v.z;
  }
  vec3f operator+()const{return *this;}
  vec3f operator-()const{return *this*-1;}
  vec3f RawMul(const vec3f&b)const
  {
    auto&a=*this;
    return vec3f(a.x*b.x,a.y*b.y,a.z*b.z);
  }
  vec3f RawMul(float x,float y,float z)const
  {
    auto&a=*this;
    return vec3f(a.x*x,a.y*y,a.z*z);
  }
  vec3f Mul(const vec3f&b)const
  {
    auto&a=*this;
    return vec3f(a.x*b.x,a.y*b.y,a.z*b.z);
  }
  vec3f Mul(float x,float y,float z)const
  {
    auto&a=*this;
    return vec3f(a.x*x,a.y*y,a.z*z);
  }
  float Mag()const
  {
    return sqrt(x*x+y*y+z*z);
  }
  float SqrMag()const
  {
    return x*x+y*y+z*z;
  }
  vec3f Norm()const
  {
    if((x==0)&&(y==0)&&(z==0))
    {
      return vec3f(0,0,0);
    }
    auto k=1.0f/Mag();
    return vec3f(x*k,y*k,z*k);
  }
  vec3f cross(const vec3f&b)const
  {
    auto&a=*this;
    return vec3f(
      +(a.y*b.z-a.z*b.y),
      -(a.x*b.z-a.z*b.x),
      +(a.x*b.y-a.y*b.x)
    );
  }
  float dot(const vec3f&b)const
  {
    auto&a=*this;
    return (
      a.x*b.x+
      a.y*b.y+
      a.z*b.z
    );
  }
};

inline float dot(const vec3f&a,const vec3f&b){return a.dot(b);}
inline vec3f cross(const vec3f&a,const vec3f&b){return a.cross(b);}

static const auto vec3f_zero=vec3f(0,0,0);
static const auto vec3f_one=vec3f(1,1,1);
struct vec4f
{
public:
  float b,g,r,a;
  vec4f():b(1.0),g(1.0),r(1.0),a(1.0) {}
  vec4f(float b,float g,float r,float a):b(b),g(g),r(r),a(a) {}
  vec4f(const QapColor&ref):b(ref.b/255.f),g(ref.g/255.f),r(ref.r/255.f),a(ref.a/255.f) {}
  vec4f&operator+=(const vec4f&v)
  {
    b+=v.b;
    g+=v.g;
    r+=v.r;
    a+=v.a;
    return *this;
  }
  friend vec4f operator*(const float&u,const vec4f&v)
  {
    return vec4f(u*v.b,u*v.g,u*v.r,u*v.a);
  }
  friend vec4f operator+(const vec4f&u,const vec4f&v)
  {
    return vec4f(u.b+v.b,u.g+v.g,u.r+v.r,u.a+v.a);
  }
  QapColor GetColor()
  {
    return QapColor(Clamp(int(a*255),int(0),int(255)),Clamp(int(r*255),int(0),int(255)),Clamp(int(g*255),int(0),int(255)),Clamp(int(b*255),int(0),int(255)));
  }
};
class vec2f
{
public:
public:
  typedef vec2f SelfClass;
public:
  float x;
  float y;
public:
public:
  vec2f():x(0),y(0) {}
  vec2f(const vec2d&v)
  {
    x=v.x;
    y=v.y;
  }
  vec2f(float x,float y):x(x),y(y) {};
  void set_zero()
  {
    x=0.0f;
    y=0.0f;
  }
public:
  friend vec2f operator*(const vec2f&u,const float&v)
  {
    return vec2f(u.x*v,u.y*v);
  }
  friend vec2f operator*(const float&u,const vec2f&v)
  {
    return vec2f(u*v.x,u*v.y);
  }
  friend vec2f operator+(const vec2f&u,const vec2f&v)
  {
    return vec2f(u.x+v.x,u.y+v.y);
  }
  friend vec2f operator-(const vec2f&u,const vec2f&v)
  {
    return vec2f(u.x-v.x,u.y-v.y);
  }
  friend void operator*=(vec2f&ref,float r){ref.x*=r;ref.y*=r;}
public:
  void operator+=(const vec2d&v)
  {
    x+=v.x;
    y+=v.y;
  }
  void operator-=(const vec2d&v)
  {
    x-=v.x;
    y-=v.y;
  }
public:
  friend vec2f operator*(float u,const vec2f&v)
  {
    return vec2f(u*v.x,u*v.y);
  }
  operator vec2d()const
  {
    return vec2d(x,y);
  }
public:
  friend bool operator==(const vec2f&u,const vec2f&v)
  {
    return (u.x==v.x)&&(u.y==v.y);
  }
  friend bool operator!=(const vec2f&u,const vec2f&v)
  {
    return (u.x!=v.x)||(u.y!=v.y);
  }

  vec2f operator-()const{
    return vec2f(-x,-y);
  }
};
inline static real dot(const vec2f&a,const vec2f&b){return a.x*b.x+a.y*b.y;}
inline static real cross(const vec2f&a,const vec2f&b){return a.x*b.y-a.y*b.x;}

class vec2i
{
public:
public:
  typedef vec2i SelfClass;
public:
  int x;
  int y;
public:
public:
  vec2i():x(0),y(0) {}
  vec2i(int x,int y):x(x),y(y) {};
  friend vec2i operator*(int u,const vec2i&v)
  {
    return vec2i(u*v.x,u*v.y);
  }
  friend vec2i operator*(const vec2i&v,int u)
  {
    return vec2i(u*v.x,u*v.y);
  }
  friend vec2i operator/(const vec2i&v,int d)
  {
    return vec2i(v.x/d,v.y/d);
  }
  friend vec2i operator+(const vec2i&u,const vec2i&v)
  {
    return vec2i(u.x+v.x,u.y+v.y);
  }
  friend vec2i operator-(const vec2i&u,const vec2i&v)
  {
    return vec2i(u.x-v.x,u.y-v.y);
  }
  void operator*=(int v){x*=v;y*=v;}
  void operator+=(const vec2i&v)
  {
    x+=v.x;
    y+=v.y;
  }
  void operator-=(const vec2i&v)
  {
    x-=v.x;
    y-=v.y;
  }
  int SqrMag()
  {
    return x*x+y*y;
  }
  float Mag()
  {
    return sqrt(float(x*x+y*y));
  }
  operator vec2d()const
  {
    return vec2d(x,y);
  }
  operator vec2f()const
  {
    return vec2f(x,y);
  }
  vec2i operator+()const
  {
    return vec2i(+x,+y);
  }
  vec2i operator-()const
  {
    return vec2i(-x,-y);
  }
  friend bool operator==(const vec2i&u,const vec2i&v)
  {
    return (u.x==v.x)&&(u.y==v.y);
  }
  friend bool operator!=(const vec2i&u,const vec2i&v)
  {
    return (u.x!=v.x)||(u.y!=v.y);
  }
  static vec2i fromVec2d(const vec2d&v){return vec2i(v.x,v.y);}
};
struct Dip2i
{
public:
  int a,b;
  Dip2i(int a,int b):a(a),b(b) {};
  void Take(int x)
  {
    a=min(a,x);
    b=max(b,x);
  }
  Dip2i Norm()const
  {
    return Dip2i(min(a,b),max(a,b));
  }
  int Mag()const
  {
    return b-a;
  }
public:
  struct Transform
  {
    float x,s;
    Transform(float x,float s):x(x),s(s) {}
    Transform(const Dip2i&from,const Dip2i&to)
    {
      s=float(to.Norm().Mag())/float(from.Norm().Mag());
      x=to.a-from.a;
    }
    float operator*(int v)
    {
      return x+v*s;
    }
  };
};
struct rot2f
{
public:
  float s;
  float c;
  rot2f():s(0.0f),c(1.0f) {}
  explicit rot2f(float ang)
  {
    set(ang);
  }
  void set(float ang)
  {
    s=sinf(ang);
    c=cosf(ang);
  }
  void set_ident()
  {
    s=0.0f;
    c=1.0f;
  }
  float GetAng()const
  {
    return std::atan2(s,c);
  }
  vec2f GetXAxis()const
  {
    return vec2f(+c,+s);
  }
  vec2f GetYAxis()const
  {
    return vec2f(-s,+c);
  }
public:
  friend vec2f operator*(const rot2f&q,const vec2d&v)
  {
    return vec2f(q.c*v.x-q.s*v.y,q.s*v.x+q.c*v.y);
  }
};
class QapMat22
{
public:
  vec2f col1;
  vec2f col2;
public:
  QapMat22():col1(1,0),col2(0,1) {}
  QapMat22(const vec2f&c1,const vec2f&c2)
  {
    col1=c1;
    col2=c2;
  }
  QapMat22(float a11,float a12,float a21,float a22)
  {
    col1.x=a11;
    col1.y=a21;
    col2.x=a12;
    col2.y=a22;
  }
  explicit QapMat22(float ang)
  {
    float c=cosf(ang);
    float s=sinf(ang);
    col1.x=c;
    col2.x=-s;
    col1.y=s;
    col2.y=+c;
  }
  void set(const vec2f&c1,const vec2f&c2)
  {
    col1=c1;
    col2=c2;
  }
  void set(float ang)
  {
    float c=cosf(ang);
    float s=sinf(ang);
    col1.x=c;
    col2.x=-s;
    col1.y=s;
    col2.y=+c;
  }
  void set_ident()
  {
    col1.x = 1.0f;
    col2.x = 0.0f;
    col1.y = 0.0f;
    col2.y = 1.0f;
  }
  void set_zero()
  {
    col1.x = 0.0f;
    col2.x = 0.0f;
    col1.y = 0.0f;
    col2.y = 0.0f;
  }
  float GetAngle()const
  {
    return atan2(col1.y, col1.x);
  }
  void mul(real r){col1*=r;col2*=r;}
};
class transform2f
{
public:
  vec2f p;
  QapMat22 r;
public:
  transform2f() {}
  transform2f(const vec2f&p,const QapMat22&r):p(p),r(r) {}
  explicit transform2f(const vec2f&p):p(p) {}
  void set_ident()
  {
    p.set_zero();
    r.set_ident();
  }
  void set(const vec2d&p,float ang)
  {
    this->p=p;
    this->r.set(ang);
  }
  float getAng()const
  {
    return atan2(r.col1.y,r.col1.x);
  }
public:
  friend vec2f operator*(const transform2f&T,const vec2f&v)
  {
    float x=(+T.r.col1.x*v.x+T.r.col2.x*v.y)+T.p.x;
    float y=(+T.r.col1.y*v.x+T.r.col2.y*v.y)+T.p.y;
    return vec2f(x,y);
  }
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
inline transform2f MakeZoomTransform(const vec2d&zoom)
{
  transform2f tmp(vec2f_zero,QapMat22(vec2f(zoom.x,0.f),vec2f(0.f,zoom.y)));
  return tmp;
}
inline vec2d Vec2dEx(const real&ang,const real&mag)
{
  return vec2d(cos(ang)*mag,sin(ang)*mag);
}
inline real vec2d_cross(const vec2d&a,const vec2d&b)
{
  return a.x*b.y-a.y*b.x;
}
struct QapMat4:public D3DMATRIX
{
public:
  QapMat4(){
    *this=QapMat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    );
  }
  QapMat4(const D3DMATRIX&ref):D3DMATRIX(ref){}
  QapMat4(
    const float m00, const float m01, const float m02, const float m03,
    const float m10, const float m11, const float m12, const float m13,
    const float m20, const float m21, const float m22, const float m23,
    const float m30, const float m31, const float m32, const float m33
  )
  {
    {
      {
        m[0][0]=m00;
      }
      ;
      {
        m[0][1]=m01;
      }
      ;
      {
        m[0][2]=m02;
      }
      ;
      {
        m[0][3]=m03;
      }
      ;
    };
    {
      {
        m[1][0]=m10;
      }
      ;
      {
        m[1][1]=m11;
      }
      ;
      {
        m[1][2]=m12;
      }
      ;
      {
        m[1][3]=m13;
      }
      ;
    };
    {
      {
        m[2][0]=m20;
      }
      ;
      {
        m[2][1]=m21;
      }
      ;
      {
        m[2][2]=m22;
      }
      ;
      {
        m[2][3]=m23;
      }
      ;
    };
    {
      {
        m[3][0]=m30;
      }
      ;
      {
        m[3][1]=m31;
      }
      ;
      {
        m[3][2]=m32;
      }
      ;
      {
        m[3][3]=m33;
      }
      ;
    };
  }
public:
  friend QapMat4 operator+(const QapMat4&m,const QapMat4&n)
  {
    QapMat4 O;
    for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=m.m[i][j]+n.m[i][j];
    return O;
  }
  friend QapMat4 operator-(const QapMat4&m,const QapMat4&n)
  {
    QapMat4 O;
    for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=m.m[i][j]-n.m[i][j];
    return O;
  }
  friend QapMat4 operator-(const QapMat4&m)
  {
    QapMat4 O;
    for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=-m.m[i][j];
    return O;
  }
  friend QapMat4 operator*(const QapMat4&m,const QapMat4&n)
  {
    return QapMat4(
          (m.m[0][0]*n.m[0][0]+m.m[0][1]*n.m[1][0]+m.m[0][2]*n.m[2][0]+m.m[0][3]*n.m[3][0]),(m.m[0][0]*n.m[0][1]+m.m[0][1]*n.m[1][1]+m.m[0][2]*n.m[2][1]+m.m[0][3]*n.m[3][1]),(m.m[0][0]*n.m[0][2]+m.m[0][1]*n.m[1][2]+m.m[0][2]*n.m[2][2]+m.m[0][3]*n.m[3][2]),(m.m[0][0]*n.m[0][3]+m.m[0][1]*n.m[1][3]+m.m[0][2]*n.m[2][3]+m.m[0][3]*n.m[3][3]),
          (m.m[1][0]*n.m[0][0]+m.m[1][1]*n.m[1][0]+m.m[1][2]*n.m[2][0]+m.m[1][3]*n.m[3][0]),(m.m[1][0]*n.m[0][1]+m.m[1][1]*n.m[1][1]+m.m[1][2]*n.m[2][1]+m.m[1][3]*n.m[3][1]),(m.m[1][0]*n.m[0][2]+m.m[1][1]*n.m[1][2]+m.m[1][2]*n.m[2][2]+m.m[1][3]*n.m[3][2]),(m.m[1][0]*n.m[0][3]+m.m[1][1]*n.m[1][3]+m.m[1][2]*n.m[2][3]+m.m[1][3]*n.m[3][3]),
          (m.m[2][0]*n.m[0][0]+m.m[2][1]*n.m[1][0]+m.m[2][2]*n.m[2][0]+m.m[2][3]*n.m[3][0]),(m.m[2][0]*n.m[0][1]+m.m[2][1]*n.m[1][1]+m.m[2][2]*n.m[2][1]+m.m[2][3]*n.m[3][1]),(m.m[2][0]*n.m[0][2]+m.m[2][1]*n.m[1][2]+m.m[2][2]*n.m[2][2]+m.m[2][3]*n.m[3][2]),(m.m[2][0]*n.m[0][3]+m.m[2][1]*n.m[1][3]+m.m[2][2]*n.m[2][3]+m.m[2][3]*n.m[3][3]),
          (m.m[3][0]*n.m[0][0]+m.m[3][1]*n.m[1][0]+m.m[3][2]*n.m[2][0]+m.m[3][3]*n.m[3][0]),(m.m[3][0]*n.m[0][1]+m.m[3][1]*n.m[1][1]+m.m[3][2]*n.m[2][1]+m.m[3][3]*n.m[3][1]),(m.m[3][0]*n.m[0][2]+m.m[3][1]*n.m[1][2]+m.m[3][2]*n.m[2][2]+m.m[3][3]*n.m[3][2]),(m.m[3][0]*n.m[0][3]+m.m[3][1]*n.m[1][3]+m.m[3][2]*n.m[2][3]+m.m[3][3]*n.m[3][3])
        );
  }
  friend QapMat4 operator*(const QapMat4 &m,float x)
  {
    QapMat4 O;
    for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=x*m.m[i][j];
    return O;
  }
  friend vec3f operator*(const vec3f&v,const QapMat4&m)
  {
    float arr[4]={v.x,v.y,v.z,1};
    float out[4]={0,0,0,0};
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)out[i]+=arr[j]*m.m[j][i];
    if(out[3]==0)return vec3f(0,0,0);
    return vec3f(out[0],out[1],out[2])*(1.0/out[3]);
  }
  bool operator==(const QapMat4&ref)const{
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(m[j][i]!=ref.m[j][i])return false;
    return true;
  }
  bool operator!=(const QapMat4&ref)const{
    return !operator==(ref);
  }
};
inline QapMat4 Transpose(const QapMat4&m)
{
  return QapMat4(
        m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
        m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
        m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
        m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
      );
}
inline QapMat4 make_matrix_from_vector(const vec3f&dir)
{
  QapDebugMsg("no way.not tested");
  auto w=0;
  auto x=dir.x;
  auto y=dir.y;
  auto z=dir.z;
  return QapMat4
  (
    1-2*y*y-2*z*z, 2*x*y+2*z*w,   2*x*z-2*y*w,   0,
    2*x*y-2*z*w,   1-2*x*x-2*z*z, 2*y*z+2*x*w  , 0,
    2*x*z+2*y*w,   2*y*z-2*x*w,   1-2*x*x-2*y*y, 0,
    0,0,0,1
  );
}
inline QapMat4 RotateX(float angle)
{
  float c=cosf(angle),s=sinf(angle);
  return QapMat4(
        +1,+0,+0,+0,
        +0,+c,+s,+0,
        +0,-s,+c,+0,
        +0,+0,+0,+1
      );
}
inline QapMat4 RotateY(float angle)
{
  float c=cosf(angle),s=sinf(angle);
  return QapMat4(
        +c,+0,-s,+0,
        +0,+1,+0,+0,
        +s,+0,+c,+0,
        +0,+0,+0,+1
      );
}
inline QapMat4 RotateZ(float angle)
{
  float c=cosf(angle),s=sinf(angle);
  return QapMat4(
        +c,+s,+0,+0,
        -s,+c,+0,+0,
        +0,+0,+1,+0,
        +0,+0,+0,+1
      );
}
inline QapMat4 Translate(const float x,const float y,const float z)
{
  return QapMat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        x,y,z,1
      );
}
inline QapMat4 Translate(const vec3f&pos)
{
  return Translate(pos.x,pos.y,pos.z);
}
inline QapMat4 Scale(const float x,const float y,const float z)
{
  return QapMat4(
        x,0,0,0,
        0,y,0,0,
        0,0,z,0,
        0,0,0,1
      );
}
inline QapMat4 Identity4()
{
  return QapMat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
      );
}
static QapMat4 MatrixLookAtLH(const vec3f&eye,const vec3f&at,const vec3f&up)
{
  //
  auto zaxis=(at-eye).Norm();
  auto xaxis=cross(up,zaxis).Norm();
  auto yaxis=cross(zaxis,xaxis);
  return QapMat4
  (
    xaxis.x,yaxis.x,zaxis.x,0,
    xaxis.y,yaxis.y,zaxis.y,0,
    xaxis.z,yaxis.z,zaxis.z,0,
    -dot(xaxis,eye),-dot(yaxis,eye),-dot(zaxis,eye),1
  );
}
static QapMat4 MatrixPerspectiveFovLH(float fovy,float aspect,float zn,float zf)
{
  auto yScale = 1.0f/tanf(fovy*0.5f);
  auto xScale = yScale/aspect;
  return QapMat4
  (
    xScale,   0  ,     0          , 0,
    0     , yScale,    0          , 0,
    0     ,   0   , zf/(zf-zn)    , 1,
    0     ,   0   , -zn*zf/(zf-zn), 0
  );
}
#include "qap_io.inl"
#include "qap_kb.inl"
#include "qap_sys.inl"

class QapD3DPresentParameters
{
public:
public:
  typedef QapD3DPresentParameters SelfClass;
public:
  D3DPRESENT_PARAMETERS pp;
public:
  void DoReset()
  {
    {
    }
    (this->pp)=(Zero(pp));
  }
public:
  QapD3DPresentParameters(const QapD3DPresentParameters&)
  {
    QapDebugMsg("QapD3DPresentParameters"" is noncopyable");
    DoReset();
  };
  QapD3DPresentParameters()
  {
    DoReset();
  };
public:
public:
  template<class TYPE>
  static TYPE&Zero(TYPE&inout)
  {
    ZeroMemory(&inout,sizeof(inout));
    return inout;
  }
  D3DPRESENT_PARAMETERS&SetToDef(HWND hWnd,bool VSync=true)
  {
    Zero(pp);
    TScreenMode SM=GetScreenMode();
    pp.BackBufferWidth=SM.W;
    pp.BackBufferHeight=SM.H;
    pp.BackBufferFormat=D3DFMT_X8R8G8B8;
    pp.BackBufferCount=1;
    pp.SwapEffect=D3DSWAPEFFECT_DISCARD;
    pp.EnableAutoDepthStencil=1;
    pp.AutoDepthStencilFormat=D3DFMT_D24X8;
    pp.PresentationInterval=VSync?D3DPRESENT_INTERVAL_ONE:D3DPRESENT_INTERVAL_IMMEDIATE;
    pp.hDeviceWindow=hWnd;
    pp.Windowed=true;
    pp.FullScreen_RefreshRateInHz=pp.Windowed?0:SM.Freq;
    return pp;
  }
};
class QapD3D9
{
public:
public:
  typedef QapD3D9 SelfClass;
public:
  IDirect3D9* pD3D;
public:
  void DoReset()
  {
    {
    }
    (this->pD3D)=(nullptr);
  }
public:
  QapD3D9(const QapD3D9&)
  {
    QapDebugMsg("QapD3D9"" is noncopyable");
    DoReset();
  };
  QapD3D9()
  {
    DoReset();
  };
public:
public:
  QapD3D9(QapD3D9&&Ref)
  {
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3D9()
  {
    Free();
  }
public:
  void oper_set(QapD3D9&&Ref)
  {
    Free();
    this->pD3D=Ref.pD3D;
    Ref.pD3D=nullptr;
  }
public:
  void operator=(QapD3D9&&Ref)
  {
    oper_set(std::move(Ref));
  }
public:
  void Init()
  {
    Free();
    pD3D=Direct3DCreate9(D3D_SDK_VERSION);
    if(!pD3D)
    {
      QapDebugMsg("Cannot create Direct3D9");
      return;
    }
  }
  void Free()
  {
    if(pD3D)pD3D->Release();
  }
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
public:
  typedef QapD3D9ResourceList SelfClass;
public:
  vector<QapD3D9Resource*> Arr;
  bool Lost;
public:
  void DoReset()
  {
    {
    }
    (this->Arr)=(vector<QapD3D9Resource*>());
    (this->Lost)=(false);
  }
public:
  QapD3D9ResourceList(const QapD3D9ResourceList&)
  {
    QapDebugMsg("QapD3D9ResourceList"" is noncopyable");
    DoReset();
  };
  QapD3D9ResourceList()
  {
    DoReset();
  };
public:
public:
  QapD3D9ResourceList(QapD3D9ResourceList&&Ref)
  {
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3D9ResourceList()
  {
    Free();
  }
public:
  void oper_set(QapD3D9ResourceList&&Ref)
  {
    Free();
    {
      this->Arr=std::move(Ref.Arr);
    }
    {
      this->Lost=std::move(Ref.Lost);
    }
  }
public:
  void operator=(QapD3D9ResourceList&&Ref)
  {
    oper_set(std::move(Ref));
  }
public:
  void Free()
  {
    Lost=false;
    QapAssert(Arr.empty());
  }
public:
  void OnLost()
  {
    Lost=true;
    for (int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex->OnLost();
    }
  }
  void OnReset()
  {
    Lost=false;
    for (int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex->OnReset();
    }
  }
public:
  bool HasRes(QapD3D9Resource*pRes,int*pIndex=nullptr)
  {
    for (int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      if(ex!=pRes)continue;
      if(pIndex)*pIndex=i;
      return true;
    }
    if(pIndex)*pIndex=-1;
    return false;
  }
  void Reg(QapD3D9Resource*pRes)
  {
    QapAssert(bool(pRes));
    QapAssert(!HasRes(pRes));
    Arr.push_back(pRes);
  }
  void UnReg(QapD3D9Resource*pRes)
  {
    int i=-1;
    bool flag=HasRes(pRes,&i);
    if(!flag)
    {
      QapAssert(flag);
      return;
    }
    std::swap(Arr[i],Arr.back());
    Arr.pop_back();
  }
};
class QapD3DDev9
{
public:
public:
  typedef QapD3DDev9 SelfClass;
public:
  QapD3DPresentParameters PresParams;
  IDirect3DDevice9* pDev;
  QapD3D9ResourceList Resources;
  bool DrawPass;
public:
  void DoReset()
  {
    {
    }
    (this->PresParams)=(QapD3DPresentParameters());
    (this->pDev)=(nullptr);
    (this->Resources)=(QapD3D9ResourceList());
    (this->DrawPass)=(false);
  }
public:
  QapD3DDev9(const QapD3DDev9&)
  {
    QapDebugMsg("QapD3DDev9"" is noncopyable");
    DoReset();
  };
  QapD3DDev9()
  {
    DoReset();
  };
public:
public:
  QapD3DDev9(QapD3DDev9&&Ref)
  {
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3DDev9()
  {
    Free();
  }
public:
  void oper_set(QapD3DDev9&&Ref)
  {
    Free();
    {
      this->PresParams=std::move(Ref.PresParams);
    }
    {
      this->pDev=std::move(Ref.pDev);
      Ref.pDev=nullptr;
    }
    {
      this->Resources=std::move(Ref.Resources);
    }
  }
public:
  void operator=(QapD3DDev9&&Ref)
  {
    oper_set(std::move(Ref));
  }
public:
  void Init(HWND hWnd,QapD3D9&D3D)
  {
    QapAssert(D3D.pD3D);
    Free();
    D3D.pD3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&PresParams.pp,&pDev);
    if(!pDev)
    {
      QapDebugMsg("Cannot create Direct3DDevice9");
      return;
    }
  }
  void Free()
  {
    if(pDev)pDev->Release();
  }
public:
  void ResetStates()
  {
    pDev->SetRenderState(D3DRS_LIGHTING,false);
    pDev->SetRenderState(D3DRS_ZENABLE,true);
    pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_CW);
    pDev->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
    pDev->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
    pDev->SetSamplerState(0,D3DSAMP_ADDRESSU,D3DTADDRESS_WRAP);
    pDev->SetSamplerState(0,D3DSAMP_ADDRESSV,D3DTADDRESS_WRAP);
    pDev->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_LINEAR);
  }
public:
  bool BeginScene()
  {
    if(Resources.Lost)
    {
      EndScene();
      return false;
    };
    pDev->BeginScene();
    DrawPass=true;
    ResetStates();
    return true;
  }
  bool EndScene()
  {
    DrawPass=false;
    if(Resources.Lost)
    {
      HRESULT hr=pDev->TestCooperativeLevel();
      if(hr!=D3DERR_DEVICENOTRESET)return false;
      pDev->Reset(&PresParams.pp);
      Resources.OnReset();
      return false;
    };
    pDev->EndScene();
    return !Resources.Lost;
  }
  bool Present(const RECT*pSource=nullptr,const RECT*pDest=nullptr)
  {
    if(!Resources.Lost)
    {
      Resources.Lost=D3DERR_DEVICELOST==pDev->Present(pSource,pDest,NULL,NULL);
      if(Resources.Lost)Resources.OnLost();
    }
    return !Resources.Lost;
  }
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
  void Blend(BlendType Mode)
  {
    pDev->SetRenderState(D3DRS_ALPHABLENDENABLE,Mode!=BT_NONE);
    if(Mode==BT_NONE)return;
    if(Mode==BT_SUB)
    {
      pDev->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
      pDev->SetTextureStageState(0, D3DTSS_COLOROP,  D3DTOP_MODULATE);
      pDev->SetTextureStageState(0, D3DTSS_COLORARG1,D3DTA_TEXTURE);
      pDev->SetTextureStageState(0, D3DTSS_COLORARG2,D3DTA_DIFFUSE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);
      pDev->SetRenderState(D3DRS_BLENDOP,D3DBLENDOP_ADD);
      pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
      pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      return;
    }
    if(Mode==BT_ADD)
    {
      pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
      return;
    }
  }
  void Alpha(AlphaType Mode)
  {
    pDev->SetRenderState(D3DRS_ALPHATESTENABLE,Mode!=AM_NONE);
    if(Mode==AM_NONE)return;
    if(Mode==AM_GEQUAL_ONE)
    {
      pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_GREATEREQUAL);
      pDev->SetRenderState(D3DRS_ALPHAREF,1);
      return;
    }
    if(Mode==AM_NEQUAL_MAX)
    {
      pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_NOTEQUAL);
      pDev->SetRenderState(D3DRS_ALPHAREF,255);
      return;
    }
  }
public:
  static void OrthoLH(D3DMATRIX&out,float w,float h,float zn,float zf)
  {
    QapMat4 mat=QapMat4(
          2.0/w,0,0,0,
          0,2.0/h,0,0,
          0,0,1/(zf-zn),0,
          0,0,-zn/(zf-zn),1
        );
    out=mat*Identity4();
  }
  void Set2D(vec2d CamPos=vec2d(0.0,0.0),real zoom=1.0,real ang=0.0,vec2i*pSize=nullptr)
  {
    auto&pp=PresParams.pp;
    vec2i v=pSize?*pSize:vec2i(pp.BackBufferWidth,pp.BackBufferHeight);
    QapMat4 matProj(Identity4());
    QapMat4 matView(Identity4());
    if((v.x%2)||(v.y%2))
    {
      if(v.x%2)CamPos.x+=0.5f;
      if(v.y%2)CamPos.y+=0.5f;
    }
    QapMat4 matWorld(Translate(-CamPos.x,-CamPos.y,0)*Scale(zoom,zoom,1.0)*RotateZ(ang));
    OrthoLH(matProj,float(v.x),float(v.y),-128.0,128.0);
    pDev->SetTransform(D3DTS_PROJECTION,&matProj);
    pDev->SetTransform(D3DTS_VIEW,&matView);
    pDev->SetTransform(D3DTS_WORLD,&matWorld);
  }
  void Clear2D(const QapColor&Color)
  {
    pDev->Clear(0,NULL,D3DCLEAR_TARGET,Color,std::numeric_limits<float>::max(),0);
  }
  void Clear3D(const QapColor&Color)
  {
    pDev->Clear(0,NULL,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,Color,std::numeric_limits<float>::max(),0);//std::numeric_limits<float>::max(),0);
  }
};


//#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\d3dx9.h"
//#pragma comment(lib,"C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86\\d3dx9.lib")

#include "t_quad.inl"
#pragma once
#pragma warning(disable:4482)
class QapDev
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapDev OwnerClass;
    void operator=(OwnerClass*pOwner)
    {
      this->pOwner=pOwner;
    }
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr)
    {
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource()
    {
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev)
    {
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost()
    {
      if(pOwner)
      {
        flag=bool(pOwner->VB);
        pOwner->Free();
      }
      else
      {
        QapDebugMsg("fail");
        flag=false;
      }
    }
    void OnReset()
    {
      if(pOwner&&flag)pOwner->ReInit();
    }
  };
public:
  struct Ver
  {
    float x,y,z;
    QapColor color;
    float tu,tv;
    Ver():x(0),y(0),z(0),tu(0),tv(0) {}
    Ver(float x,float y,const QapColor&color,float u=0.0,float v=0.0):x(x),y(y),z(0),color(color),tu(u),tv(v) {}
    Ver(const vec2f&pos,const QapColor&color,float u=0.0,float v=0.0):x(pos.x),y(pos.y),z(0),color(color),tu(u),tv(v) {}
    Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord):x(pos.x),y(pos.y),z(0),color(color),tu(texcoord.x),tv(texcoord.y) {}
    vec3f&get_vec3f()const{
      return *(vec3f*)&x;
    }
    vec2f&get_pos()
    {
      return *(vec2f*)&x;
    }
    vec2f&get_pos()const
    {
      return *(vec2f*)&x;
    }
    vec2f&get_tpos()
    {
      return *(vec2f*)&tu;
    }
    vec2f&get_tpos()const
    {
      return *(vec2f*)&tu;
    }
  };
  struct BatchScope
  {
    QapDev&RD;
    bool flag;
    BatchScope(QapDev&RD):RD(RD)
    {
      flag=!RD.Batching;
      if(flag)RD.BeginBatch();
    }
    ~BatchScope()
    {
      if(flag)RD.EndBatch();
    }
  };
  struct Xf4Scope
  {
    QapDev&RD;
    bool flag;
    QapMat4 backup;
    Xf4Scope(QapDev&RD):RD(RD)
    {
      RD.BeginXF4(*this);
    }
    ~Xf4Scope()
    {
      RD.EndXF4(*this);
    }
  };
public:
  typedef QapD3DDev9::BlendType BlendType;
  typedef QapD3DDev9::AlphaType AlphaType;
public:
public:
  typedef QapDev SelfClass;
public:
  TDynamicResource DynRes;
  IDirect3DDevice9*pDev;
  IDirect3DVertexBuffer9*VB;
  IDirect3DIndexBuffer9*IB;
  Ver* VBA;
  int* IBA;
  QapColor color;
  int VPos;
  int IPos;
  int MaxVPos;
  int MaxIPos;
  int DIPs;
  int Verts;
  int Tris;
  BlendType BlendMode;
  AlphaType AlphaMode;
  bool Batching;
  bool Textured;
  transform2f xf;
  transform2f txf;
  vector<t_quad> stack;
  t_quad viewport;
  bool use_viewport;
  QapMat4 xf4;
  bool use_xf4;
  bool use_xf2;
  bool auto_clamp;
  bool after_reinit;
public:
  void DoReset()
  {
    {
    }
    (this->DynRes)=(this);
    (this->pDev)=(nullptr);
    (this->VB)=(nullptr);
    (this->IB)=(nullptr);
    (this->VBA)=(nullptr);
    (this->IBA)=(nullptr);
    (this->color)=(0xFFFFFFFF);
    (this->VPos)=(0);
    (this->IPos)=(0);
    (this->MaxVPos)=(0);
    (this->MaxIPos)=(0);
    (this->DIPs)=(0);
    (this->Verts)=(0);
    (this->Tris)=(0);
    (this->BlendMode)=(BlendType::BT_SUB);
    (this->AlphaMode)=(AlphaType::AM_NONE);
    (this->Batching)=(false);
    (this->Textured)=(false);
    detail::FieldTryDoReset(this->xf);
    detail::FieldTryDoReset(this->txf);
    //... added ...
    (this->use_viewport=false);
    (this->use_xf4=false);
    (this->use_xf2=false);
    (this->auto_clamp=false);
    (this->after_reinit=false);
  }
public:
  QapDev(const QapDev&)
  {
    QapDebugMsg("QapDev"" is noncopyable");
    DoReset();
  };
  QapDev()
  {
    DoReset();
  };
public:
protected:
  static const DWORD FVF=D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1;
public:
  ~QapDev()
  {
    Free();
  }
public:
  bool OnReinit(){auto f=after_reinit;after_reinit=false;return f;}
  void ReInit()
  {
    Init(MaxVPos,MaxIPos);after_reinit=true;
  }
  void MountDev(QapD3DDev9&Dev)
  {
    this->pDev=Dev.pDev;
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int VCount,int ICount)
  {
    if(!VB)
    {
      MaxVPos=VCount;
      MaxIPos=ICount;
      pDev->CreateVertexBuffer(VCount*sizeof(Ver),D3DUSAGE_DYNAMIC,FVF,D3DPOOL_DEFAULT,&VB,NULL);
      pDev->CreateIndexBuffer(ICount*sizeof(int),D3DUSAGE_DYNAMIC,D3DFMT_INDEX32,D3DPOOL_DEFAULT,&IB,NULL);
      VBA=0;
      IBA=0;
      VPos=0;
      IPos=0;
      DIPs=0;
      Verts=0;
      Tris=0;
      xf.set_ident();
      txf.set_ident();
    };
  }
  void Free()
  {
    if(VB)
    {
      VB->Release();
      VB=nullptr;
      VBA=nullptr;
    }
    if(IB)
    {
      IB->Release();
      IB=nullptr;
      IBA=nullptr;
    }
    VPos=0;
    IPos=0;
    Batching=false;
    BlendMode=BlendType::BT_SUB;
    AlphaMode=AlphaType::AM_NONE;
  };
public:
  void BeginXF4(Xf4Scope&scope)
  {
    scope.backup=xf4;
    scope.flag=use_xf4;
    use_xf4=true;
  }
  void EndXF4(Xf4Scope&scope)
  {
    xf4=scope.backup;
    use_xf4=scope.flag;
  }
public:
  bool DrawPass(){return this->DynRes.pDev->DrawPass;}
  void BeginBatch()
  {
    QapAssert(DrawPass());
    Batching=true;
    VBA=0;
    IBA=0;
    VPos=0;
    IPos=0;
    if(!IB||!VB)return;
    IB->Lock(0,sizeof(int)*MaxIPos,(void **)&IBA,0);
    VB->Lock(0,sizeof(Ver)*MaxVPos,(void **)&VBA,0);
  };
  void EndBatch(bool call_dip=true)
  {
    Batching=false;
    if(!IB||!VB)return;
    IB->Unlock();
    VB->Unlock();
    if(VPos&&IPos)
    {
      if(call_dip)DIP();
    }
    VBA=0;
    IBA=0;
  }
  void DIP()
  {
    pDev->SetFVF(FVF);
    pDev->SetStreamSource(0,VB,0,sizeof(Ver));
    pDev->SetIndices(IB);
    pDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,VPos,0,IPos/3);
    DIPs++;
    Verts+=VPos;
    Tris+=IPos/3;
  }
  bool IsBatching()
  {
    return Batching;
  }
  int GetIPos()
  {
    return IPos;
  }
  int GetVPos()
  {
    return VPos;
  }
  int GetDIPs()
  {
    return DIPs;
  }
  int GetVerts()
  {
    return Verts;
  }
  int GetTris()
  {
    return Tris;
  }
  const QapColor&GetColor()
  {
    return color;
  }
  void push_viewport(const t_quad&quad)
  {
    stack.push_back(viewport);
    viewport=quad;
  }
  void pop_viewport()
  {
    QapAssert(!stack.empty());
    viewport=stack.back();
    stack.pop_back();
  }
  void NextFrame()
  {
    QapAssert(stack.empty());
    DIPs=0;
    Verts=0;
    Tris=0;
    use_xf2=false;
    use_viewport=false;
    SetBlendMode(BlendMode);
    SetAlphaMode(AlphaMode);
  }
public:
  void HackMode(bool Textured)
  {
    this->Textured=Textured;
  }
  template<class QAP_TEX>
  void BindTex(int Stage,QAP_TEX*pTex)
  {
    QapTex*Tex=pTex;
    pDev->SetTexture(Stage,Tex?Tex->Tex:nullptr);
    txf.set_ident();
    Textured=Tex?true:false;
  }
  void BindTex(int Stage,const nullptr_t)
  {
    pDev->SetTexture(Stage,nullptr);
    Textured=false;
  }
public:
  inline Ver&AddVertexRaw()
  {
    return VBA[VPos++];
  }
  inline int AddVertex(const Ver&Source)
  {
    QapAssert(VPos<MaxVPos);
    Ver&Dest=VBA[VPos];
    Dest=Source;
    if(use_xf4)
    {
      QapAssert(!use_xf2);
      auto&v=Dest.get_vec3f();
      v=v*xf4;
    }
    if(use_xf2)
    {
      QapDebugMsg("[2014.12.01 11:33] need add Xf2Scope");
      QapAssert(!use_xf4);
      vec2f&v=Dest.get_pos();
      v=xf*v;
    }
    if(use_viewport)
    {
      vec2f&v=Dest.get_pos();
      v+=viewport.pos;
    }
    if(Textured)
    {
      QapDebugMsg("[2014.12.01 11:33] need add Xf2tScope");
      vec2f&v=Dest.get_tpos();
      v=txf*v;
    }
    return VPos++;
  }
  inline int AddVertex(float x,float y,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec2f&pos,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.get_pos()=pos;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec3f&pos)
  {
    QapDev::Ver tmp;
    tmp.get_vec3f()=pos;
    tmp.color=color;
    tmp.tu=0;
    tmp.tv=0;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec3f&pos,const QapColor&c)
  {
    QapDev::Ver tmp;
    tmp.get_vec3f()=pos;
    tmp.color=c;
    tmp.tu=0;
    tmp.tv=0;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec3f&pos,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.get_vec3f()=pos;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec2f&pos,const QapColor&c,const vec2f&tpos)
  {
    QapDev::Ver tmp;
    tmp.get_pos()=pos;
    tmp.z=0;
    tmp.color=c;
    tmp.get_tpos()=tpos;
    auto id=AddVertex(tmp);
    return id;
  }
  inline void AddTris(int A,int B,int C)
  {
    QapAssert(IPos+2<MaxIPos);
    QapAssert(A>=0&&A<MaxVPos);
    QapAssert(B>=0&&B<MaxVPos);
    QapAssert(C>=0&&C<MaxVPos);
    IBA[IPos++]=A;
    IBA[IPos++]=B;
    IBA[IPos++]=C;
  };
  inline void AddTrisInv(int A,int B,int C)
  {
    QapAssert(IPos+2<MaxIPos);
    QapAssert(A>=0&&A<MaxVPos);
    QapAssert(B>=0&&B<MaxVPos);
    QapAssert(C>=0&&C<MaxVPos);
    IBA[IPos++]=C;
    IBA[IPos++]=B;
    IBA[IPos++]=A;
  };
public:
  inline void SetColor(const QapColor&C)
  {
    color=C;
  }
  inline void SetTransform(transform2f const&val)
  {
    QapDebugMsg("no way.\nuse Xf2Scope.");xf=val;
  }
  inline transform2f GetTransform()
  {
    return xf;
  }
  inline void SetTextureTransform(transform2f const&val)
  {
    QapDebugMsg("no way.\nuse Xf2tScope.");txf=val;
  }
  inline transform2f GetTextureTransform()
  {
    return txf;
  }
public:
  BlendType GetBlendMode()
  {
    return BlendMode;
  }
  AlphaType GetAlphaMode()
  {
    return AlphaMode;
  }
  void SetBlendMode(BlendType Mode)
  {
    DynRes.pDev->Blend(BlendMode=Mode);
  }
  void SetAlphaMode(AlphaType Mode)
  {
    DynRes.pDev->Alpha(AlphaMode=Mode);
  }
public:
  void DrawRect(const vec2d&a,const vec2d&b,int line_size)
  {
    BatchScope Scope(*this);
    {
      real x=(a.x+b.x)*0.5;
      real w=fabs(a.x-b.x);
      DrawQuad(x,a.y,line_size+w,line_size);
      DrawQuad(x,b.y,line_size+w,line_size);
      real y=(a.y+b.y)*0.5;
      real h=fabs(a.y-b.y);
      DrawQuad(a.x,y,line_size,-line_size+h);
      DrawQuad(b.x,y,line_size,-line_size+h);
    }
    int gg=1;
  }
  void DrawRectAsQuad(const vec2d&pos,const vec2d&size,int line_size)
  {
    auto hs=size*0.5;
    DrawRect(pos-hs,pos+hs,line_size);
  }
  void DrawQuadWithHalfPixelOffset(int x,int y,int w,int h)
  {
    DrawQuad(float(x)+0.5,float(y)-0.5,float(w),float(h));
  }
  void DrawQuadWithHalfPixelOffset(const vec2i&p,int w,int h)
  {
    DrawQuadWithHalfPixelOffset(p.x,p.y,w,h);
  }
  void AddQuadsIndices(int vpos,int n){
    int p=vpos;
    for(int i=0;i<n;i++){
      AddTris(p+1,p+0,p+3);
      AddTris(p+3,p+2,p+1);
      p+=4;
    }
  }
  void AddQuadVertices(float x,float y,float half_w,float half_h)
  {  
    BatchScope Scope(*this);
    {
      #define F(X,Y,U,V){AddVertex(x+(X##half_w),y+(Y##half_h),color,U,V);}
      //vec2d O(x,y);
      //int n=VPos;
      QapAssert(vec2d(-1,-1).Ort()==vec2d(+1,-1));
      F(-,-,0.0f,1.0f);
      F(+,-,1.0f,1.0f);
      F(+,+,1.0f,0.0f);
      F(-,+,0.0f,0.0f); 
      //AddTris(n+1,n+0,n+3);
      //AddTris(n+3,n+2,n+1);
      #undef F
    }
  }
  void DrawQuad(float x,float y,float w,float h)
  {
    BatchScope Scope(*this);
    {
      #define F(X,Y,U,V){AddVertex(x+(X)*w,y+(Y)*h,color,U,V);}
      vec2d O(x,y);
      int n=VPos;
      F(-0.5f,-0.5f,0.0f,1.0f);
      F(+0.5f,-0.5f,1.0f,1.0f);
      F(+0.5f,+0.5f,1.0f,0.0f);
      F(-0.5f,+0.5f,0.0f,0.0f); 
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
      #undef F
    }
  }
  void DrawQuad(float x,float y,float w,float h,float a)
  {
    BatchScope Scope(*this);
    {
      vec2d OZ=Vec2dEx(a,1.0);
      vec2d O(x,y);
      int n=VPos;
      {
        AddVertex(vec2f(O+vec2d(-0.5f*w,-0.5f*h).UnRot(OZ)),color,0.0f,1.0f);
      };
      {
        AddVertex(vec2f(O+vec2d(+0.5f*w,-0.5f*h).UnRot(OZ)),color,1.0f,1.0f);
      };
      {
        AddVertex(vec2f(O+vec2d(+0.5f*w,+0.5f*h).UnRot(OZ)),color,1.0f,0.0f);
      };
      {
        AddVertex(vec2f(O+vec2d(-0.5f*w,+0.5f*h).UnRot(OZ)),color,0.0f,0.0f);
      };
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
    }
  }
  void DrawQuad(float x,float y,const vec2d&size,float ang)
  {
    DrawQuad(x,y,size.x,size.y,ang);
  }
  void DrawQuad(const vec2d&pos,const vec2d&size,float ang)
  {
    DrawQuad(pos.x,pos.y,size.x,size.y,ang);
  }
  void DrawQuad(const vec2d&pos,const vec2d&size)
  {
    DrawQuad(pos.x,pos.y,size.x,size.y);
  }
  void DrawQuad(const vec2d&pos,float w,float h,float ang)
  {
    DrawQuad(pos.x,pos.y,w,h,ang);
  }
  void DrawQuad(const vec2d&pos,float w,float h)
  {
    DrawQuad(pos.x,pos.y,w,h);
  }
  void DrawTrigon(const vec2d&A,const vec2d&B,const vec2d&C)
  {
    BatchScope Scope(*this);
    {
      AddTris(
        AddVertex(Ver(A,color)),
        AddVertex(Ver(B,color)),
        AddVertex(Ver(C,color))
      );
    }
  }
  void DrawConvex(const vector<vec2d>&Points)
  {
    BatchScope Scope(*this);
    {
      if(Points.empty())return;
      int c=Points.size();
      int n=VPos;
      for (int i=0;i<c;i++)AddVertex(Points[i],color,0.5,0.5);
      for (int i=2;i<c;i++)AddTris(n,n+i-1,n+i-0);
    }
  }
public:
  void DrawDashLine(const vec2d&a,const vec2d&b,real dash_size,real line_size)
  {
    if(a.dist_to(b)<dash_size){DrawLine(a,b,line_size);return;}
    auto o=(a+b)*0.5;
    auto ob=b-o;
    auto ob05=o+ob.SetMag(dash_size*0.5);
    auto ob15=o+ob.SetMag(dash_size*1.5);
    DrawDashLineFromA(ob05,a,dash_size,line_size);
    if(dash_size*1.5<ob.Mag())DrawDashLineFromA(ob15,b,dash_size,line_size);
  }
  void DrawDashLineFromA(const vec2d&a,const vec2d&b,real dash_size,real line_size)
  {
    real k=dash_size;real inv_k=1.0/k;
    vector<vec2d> arr;int c=int(a.dist_to(b)*inv_k);
    for(int i=0;i<=c;i++)qap_add_back(arr)=a+(b-a).SetMag(i*k);
    if(c%2==0)qap_add_back(arr)=b;
    DrawLineList(arr,line_size);
  }
  void DrawLine(const vec2d&a,const vec2d&b,real line_size){DrawQuad((b+a)*0.5,(b-a).Mag(),line_size,(b-a).GetAng());}
  void DrawSolidCircle(const vec2d&pos,real r,int seg,real ang){DrawCircleEx(pos,r,0,seg,ang);}
  template<typename TYPE>
  void DrawPolyLine(const vector<TYPE>&PA,const real&LineSize,const bool&Loop)
  {
    if(PA.empty())return;
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
    if(PA.empty())return;
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
    //QapDebugMsg("[2014.05.22]: way used?");
    if(VA.empty())return;
    BatchScope Scope(*this);
    {
      int base=GetVPos();
      static IntArray VID;
      VID.resize(VA.size());
      for (int i=0;i<VA.size();i++){auto&p=VA[i];VID[i]=AddVertex(p,color,p.x,p.y);}
      for (int i=0;i<IA.size();i+=3)AddTris(VID[IA[i+0]],VID[IA[i+1]],VID[IA[i+2]]);
    }
  }
  void DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    static PointArray PA;
    PA.resize(seg);
    for (int i=0;i<seg;i++)
    {
      vec2d v=Vec2dEx((real)i/(real)seg*2.0*Pi,r);
      PA[i]=pos+v;
    };
    DrawPolyLine(PA,ls,true);
  }
  void DrawCircle(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    DrawCircleEx(pos,r-ls*0.5,r+ls*0.5,seg,ang);
  }
  void DrawCircleEx(const vec2d&pos,real r0,real r1,int seg,real ang)
  {
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;
    VID.resize(n*2);
    for (int i=0;i<n;i++)
    {
      vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[0+i]=AddVertex(pos+v*r0,color,0,0);
      VID[n+i]=AddVertex(pos+v*r1,color,0,0);
    }
    for (int i=0;i<n;i++)
    {
      int a=VID[0+(i+0)%n];
      int b=VID[0+(i+1)%n];
      int c=VID[n+(i+0)%n];
      int d=VID[n+(i+1)%n];
      AddTrisInv(a,b,d);
      AddTrisInv(d,c,a);
    }
  }
  static inline vec3f toVec3f(const vec2d&pos,float z=0){return vec3f(pos.x,pos.y,z);}
  void DrawTube(const vec3f&pos,real z_len,real r,real dr,int seg,real ang)
  {
    DrawTubeEx(pos,z_len*-0.5,z_len*0.5,r+dr*0.5,r-dr*0.5,seg,ang);
  }
  void DrawTubeEx(const vec3f&pos,real z0,real z1,real r0,real r1,int seg,real ang)
  {
    if(z0>z1)std::swap(z0,z1);
    if(r0<r1)std::swap(r0,r1);
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;
    VID.resize(n*4);
    auto pz0=pos+vec3f(0,0,z0);
    auto pz1=pos+vec3f(0,0,z1);
    for(int i=0;i<n;i++)
    {
      auto p=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[n*0+i]=AddVertex(pz0+toVec3f(p)*r0,color,0,0);
      VID[n*1+i]=AddVertex(pz0+toVec3f(p)*r1,color,0,0);
      VID[n*2+i]=AddVertex(pz1+toVec3f(p)*r0,color,0,0);
      VID[n*3+i]=AddVertex(pz1+toVec3f(p)*r1,color,0,0);
    }
    for(int i=0;i<n;i++)
    {
      //z0
      {
        int a=VID[n*0+(i+0)%n];
        int b=VID[n*0+(i+1)%n];
        int c=VID[n*1+(i+0)%n];
        int d=VID[n*1+(i+1)%n];
        AddQuad(0,a,b,d,c);
      }
      //z1
      {
        int a=VID[n*2+(i+0)%n];
        int b=VID[n*2+(i+1)%n];
        int c=VID[n*3+(i+0)%n];
        int d=VID[n*3+(i+1)%n];
        AddQuadInv(0,a,b,d,c);
      }
      int gg=1;
      {
        int a0=VID[n*0+(i+0)%n];
        int b0=VID[n*0+(i+1)%n];
        int c0=VID[n*1+(i+0)%n];
        int d0=VID[n*1+(i+1)%n];
        //
        int a1=VID[n*2+(i+0)%n];
        int b1=VID[n*2+(i+1)%n];
        int c1=VID[n*3+(i+0)%n];
        int d1=VID[n*3+(i+1)%n];
        {
          int a=a0;
          int b=a1;
          int c=b0;
          int d=b1;
          AddQuad(0,a,b,d,c);
        }
        //
        {
          int a=c0;
          int b=c1;
          int c=d0;
          int d=d1;
          AddQuadInv(0,a,b,d,c);
        }
      }
    }
    int gg=1;
  }

  void DrawSphereWithScale(const vec3f&pos,float r,const vec3f&scale,int seg=16,int cn=32)
  {
    /* this is copy-paste */QapAssert(cn>2&&seg>2);
    /* this is copy-paste */int axispoints=0;
    /* this is copy-paste */auto n=(1+cn)/2;
    /* this is copy-paste */auto zoom=1.0/n;
    /* this is copy-paste */auto point_color=color;
    /* this is copy-paste */vector<int> VID;
    /* this is copy-paste */VID.reserve(n*2*seg-seg);
    /* this is copy-paste */for(int j=-n+1;j<n;j++)
    /* this is copy-paste */{
    /* this is copy-paste */  auto z=sin((j*zoom)*PiD2);
    /* this is copy-paste */  auto m=sqrt(1-(z*z));
    /* this is copy-paste */  if(fabs(z)>=1)
    /* this is copy-paste */  {
    /* this is copy-paste */    axispoints++;
    /* this is copy-paste */    continue;
    /* this is copy-paste */  }
    /* this is copy-paste */  for(int i=0;i<seg;i++)
    /* this is copy-paste */  {
    /* this is copy-paste */    auto v=Vec2dEx(i*Pi2/seg,1);
    v.x*=scale.x;
    v.y*=scale.y;
    /* this is copy-paste */    vec3f dpos=vec3f(v.x*m,v.y*m,z*scale.z);
    /* this is copy-paste */    color=point_color;
    /* this is copy-paste */    qap_add_back(VID)=AddVertex(pos+r*dpos);
    /* this is copy-paste */  }
    /* this is copy-paste */  //color=0xff00bb00;
    /* this is copy-paste */  //DrawTube(pos+vec3f(0,0,z*r),r*0.005,r*m,r*0.005,seg,0);
    /* this is copy-paste */}
    /* this is copy-paste */color=point_color;
    /* this is copy-paste */auto A=AddVertex(pos+vec3f(0,0,r*scale.z));
    /* this is copy-paste */auto B=AddVertex(pos-vec3f(0,0,r*scale.z));
    /* this is copy-paste *///
    /* this is copy-paste */QapAssert(!axispoints);
    /* this is copy-paste *///
    /* this is copy-paste */int iter=0;
    /* this is copy-paste */for(int j=-n+1;j+1<n;j++)
    /* this is copy-paste */{
    /* this is copy-paste */  for(int i=0;i<seg;i++)
    /* this is copy-paste */  {
    /* this is copy-paste */    int base0=(iter+0)*seg;
    /* this is copy-paste */    int base1=(iter+1)*seg;
    /* this is copy-paste */    auto&a=VID[base0+(i+0)%seg];
    /* this is copy-paste */    auto&b=VID[base1+(i+0)%seg];
    /* this is copy-paste */    auto&c=VID[base1+(i+1)%seg];
    /* this is copy-paste */    auto&d=VID[base0+(i+1)%seg];
    /* this is copy-paste */    AddQuad(0,a,b,c,d);
    /* this is copy-paste */  }
    /* this is copy-paste */  iter++;
    /* this is copy-paste */}
    /* this is copy-paste */for(int i=0;i<seg;i++)
    /* this is copy-paste */{
    /* this is copy-paste */  {
    /* this is copy-paste */    int base=0;
    /* this is copy-paste */    auto&a=VID[base+(i+0)%seg];
    /* this is copy-paste */    auto&b=VID[base+(i+1)%seg];
    /* this is copy-paste */    AddTris(B,a,b);
    /* this is copy-paste */  }
    /* this is copy-paste */  {
    /* this is copy-paste */    int base=iter*seg;
    /* this is copy-paste */    auto&a=VID[base+(i+0)%seg];
    /* this is copy-paste */    auto&b=VID[base+(i+1)%seg];
    /* this is copy-paste */    AddTrisInv(A,a,b);
    /* this is copy-paste */  }
    /* this is copy-paste */}
    /* this is copy-paste */QapAssert(!axispoints);
  }
  void DrawSphere(const vec3f&pos,float r,int seg=16,int cn=32)
  {
    QapAssert(cn>2&&seg>2);
    int axispoints=0;
    auto n=(1+cn)/2;
    auto scale=1.0/n;
    auto point_color=color;
    vector<int> VID;
    VID.reserve(n*2*seg-seg);
    static vector<vector<vec2d>> seg_seg_id_to_dir;static const int max_buff=32;
    if(seg_seg_id_to_dir.empty())seg_seg_id_to_dir.resize(max_buff);
    vec2d*pid2vec=nullptr;
    if(seg<max_buff&&seg>1){
      auto&arr=seg_seg_id_to_dir[seg];
      if(arr.empty()){for(int i=0;i<seg;i++)qap_add_back(arr)=Vec2dEx(i*Pi2/seg,1);}
      pid2vec=&arr[0];
    }
    for(int j=-n+1;j<n;j++)
    {
      auto z=sin((j*scale)*PiD2);
      auto m=sqrt(1-(z*z));
      if(fabs(z)>=1)
      {
        axispoints++;
        continue;
      }
      for(int i=0;i<seg;i++)
      {
        auto v=pid2vec?pid2vec[i]:Vec2dEx(i*Pi2/seg,1);
        vec3f dpos=vec3f(v.x*m,v.y*m,z);
        color=point_color;
        qap_add_back(VID)=AddVertex(pos+r*dpos);
      }
      //color=0xff00bb00;
      //DrawTube(pos+vec3f(0,0,z*r),r*0.005,r*m,r*0.005,seg,0);
    }
    color=point_color;
    auto A=AddVertex(pos+vec3f(0,0,r));
    auto B=AddVertex(pos-vec3f(0,0,r));
    //
    QapAssert(!axispoints);
    //
    int iter=0;
    for(int j=-n+1;j+1<n;j++)
    {
      for(int i=0;i<seg;i++)
      {
        int base0=(iter+0)*seg;
        int base1=(iter+1)*seg;
        auto&a=VID[base0+(i+0)%seg];
        auto&b=VID[base1+(i+0)%seg];
        auto&c=VID[base1+(i+1)%seg];
        auto&d=VID[base0+(i+1)%seg];
        AddQuad(0,a,b,c,d);
      }
      iter++;
    }
    for(int i=0;i<seg;i++)
    {
      {
        int base=0;
        auto&a=VID[base+(i+0)%seg];
        auto&b=VID[base+(i+1)%seg];
        AddTris(B,a,b);
      }
      {
        int base=iter*seg;
        auto&a=VID[base+(i+0)%seg];
        auto&b=VID[base+(i+1)%seg];
        AddTrisInv(A,a,b);
      }
    }
    QapAssert(!axispoints);
    //color=0xffff0000;
    //DrawCube(pos,r*vec3f_one*0.04);
    //DrawCube(pos+vec3f(0,0,r),r*vec3f_one*0.02);
    //DrawCube(pos-vec3f(0,0,r),r*vec3f_one*0.02);
  }
  void DrawSphereWire(const vec3f&pos,float r,int seg=16,int cn=32)
  {
    QapAssert(cn>2&&seg>2);
    int axispoints=0;
    auto n=(1+cn)/2;
    auto scale=1.0/n;
    auto point_color=color;
    for(int j=-n+1;j<n;j++)
    {
      auto z=sin((j*scale)*PiD2);
      auto m=sqrt(1-(z*z));
      if(fabs(z)>=1)
      {
        axispoints++;
        continue;
      }
      for(int i=0;i<seg;i++)
      {
        auto v=Vec2dEx(i*Pi2/seg,1);
        vec3f dpos=vec3f(v.x*m,v.y*m,z);
        color=point_color;
        DrawCube(pos+r*dpos,r*vec3f_one*0.02);
      }
      color=0xff00bb00;
      DrawTube(pos+vec3f(0,0,z*r),r*0.005,r*m,r*0.005,seg,0);
    }
    QapAssert(!axispoints);
    color=0xffff0000;
    DrawCube(pos,r*vec3f_one*0.04);
    DrawCube(pos+vec3f(0,0,r),r*vec3f_one*0.02);
    DrawCube(pos-vec3f(0,0,r),r*vec3f_one*0.02);
  }
  void DrawCylinderAsLine(const vec3f&a,const vec3f&b,real r,int seg,real ang,bool full=true)
  {
    //QapDebugMsg("Check culling CC and C");
    auto zer=vec3f(0,0,0);
    auto ab=b-a;
    auto z_len=ab.Mag();
    if(!z_len)return;
    auto pos=(a+b)*0.5;
    auto dir=ab.Norm();
    auto up=vec3f(0,1,0);
    if(up==dir)up=vec3f(-1,0,0);
    auto tap=Translate(+pos);
    auto tsp=Translate(-pos);
    QapMat4 dxm;
    vec3f dxzer(zer);
    vec3f dxpos(pos);
    //D3DXQUATERNION dxdir(dir.x,dir.y,dir.x,1);
    
    auto dir_mag=dir.Mag();

    //D3DXQuaternion
    //D3DXMatrixAffineTransformation(&dxm,1,&dxzer,&dxdir,&dxpos);
    //auto at=vec3f(2,-1,2);
    //auto dxat=D3DXVECTOR3(at);
    auto dxup=vec3f(up);
    //D3DXMatrixLookAtLH(&dxm,&dxzer,&dxat,&dxup);
    auto m=MatrixLookAtLH(b,a,up);
    {
      //for(int i=1;i<32;i++)
      QapMat4 tmp;
      {
        //auto prev_r=r;
        //auto r=prev_r*0.1;
        QapDev::BatchScope scope(*this);
        Xf4Scope xf4scope(*this);
        auto rotx=[](const vec3f&dir)->QapMat4
        {
          //float c=dir.x,s=dir.y;
          return QapMat4(
                +1,+0,+0,+0,
                +0,-dir.z,+dir.y,+0,
                +0,-dir.y,-dir.z,+0,
                +0,+0,+0,+1
              );
        };
        auto roty=[](const vec3f&dir)->QapMat4 //top
        {
          float c=dir.z; float s=dir.x;//-dir.x,s=dir.y;
          return QapMat4(
                +c,+0,-s,+0,
                +0,+1,+0,+0,
                +s,+0,+c,+0,
                +0,+0,+0,+1
              );
        };
        auto new_mat=[](const vec3f&ox,const vec3f&oy,const vec3f&oz)
        {
          #define F(ot)ot.x,ot.y,ot.z,0,
          return QapMat4(
            F(ox)
            F(oy)
            F(oz)
            0,0,0,1
          );
          #undef F
        };
        auto rot=[&new_mat,&up](const vec3f&dir)->QapMat4
        {
          //vec3f up=vec3f(0,1,0);
          auto nz=cross(dir,up).Norm();
          auto ny=cross(dir,nz).Norm();
          float x=dir.x; float y=dir.y;float z=dir.z; //-dir.x,s=dir.y;
          return new_mat(nz,ny,dir);
        };
        //xf4=/ *rotx(dir)* /rot(dir)*Translate(pos);
        xf4=rot(dir)*Translate(pos);
        //xf4=MatrixLookAtLH(pos+dir,pos,up);
        //xf4=MatrixLookAtLH(vec3f(i*0.1,i*0.1,i*0.1),vec3f(i*0.1,i*0.1,i*0.2),up);
        DrawCylinder(zer,z_len,r,seg,ang,full);
      }
      return;
      auto prev_color=color;
      auto prev_r=r;
      auto r=prev_r*0.1;
      for(int x=-2;x<=2;x++)
      for(int i=-2;i<2;i++)
      {
        //auto xform=Translate(x,0,0);
        x=+2;
        i=-2;
        for(int u=0;u<16;u++){
        auto xform=Translate(u*0.1,0,0)*RotateX(i*0.4)*RotateY(x*0.4);
        {
          QapDev::BatchScope scope(*this);
          Xf4Scope xf4scope(*this);
          xf4=xform;
          color=prev_color;
          DrawCylinder(zer,z_len,r,seg,ang,full);
          color=0xff402020;
          DrawCube(z_len*vec3f(0,0,+0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          color=0xffffff00;
          DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5),vec3f_one*0.02);
        }
        {
          QapDev::BatchScope scope(*this);
          Xf4Scope xf4scope(*this);
          xf4=RotateX(i*0.4)*RotateY(x*0.4)*Translate(u*0.1,0,0);
          color=prev_color;
          DrawCylinder(zer,z_len,r,seg,ang,full);
          color=0xff402020;
          DrawCube(z_len*vec3f(0,0,+0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          color=0xffff8000;
          DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5),vec3f_one*0.02);
        }}
        color=0xffffffff;
        DrawCube(z_len*vec3f(0,0,+0.5)*(RotateX(i*0.4)*RotateY(x*0.4)),vec3f_one*0.03);
        x=100;break;
      }
    }
    auto backup_color=color;
    color=0xffff8000;
    DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.1);
    DrawCube(z_len*vec3f(0,0,-0.5),vec3f_one*0.1);
    color=backup_color;
  }
  void DrawCylinder(const vec3f&pos,real z_len,real r,int seg,real ang,bool full=true)
  {
    DrawCylinderEx(pos,z_len*-0.5,z_len*0.5,r,seg,ang,full);
  }
  void DrawCylinderEx(const vec3f&pos,real z0,real z1,real r,int seg,real ang,bool full=true)
  {
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;
    VID.resize(n*2);
    auto pz0=pos+vec3f(0,0,z0);
    auto pz1=pos+vec3f(0,0,z1);
    for(int i=0;i<n;i++)
    {
      auto p=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[n*0+i]=AddVertex(pz0+toVec3f(p)*r,color,0,0);
      VID[n*1+i]=AddVertex(pz1+toVec3f(p)*r,color,0,0);
    }
    for(int i=0;i<n;i++)
    {
      //z0
      if(full)
      {
        int o=VID[n*0+(0+0)%n];
        int a=VID[n*0+(i+1)%n];
        int b=VID[n*0+(i+2)%n];
        AddTris(o,a,b);
      }
      //z1
      if(full)
      {
        int o=VID[n*1+(0+0)%n];
        int a=VID[n*1+(i+1)%n];
        int b=VID[n*1+(i+2)%n];
        AddTrisInv(o,a,b);
      }
      //if(0)
      {
        int a=VID[n*0+(i+1)%n];
        int b=VID[n*0+(i+2)%n];
        //
        int c=VID[n*1+(i+1)%n];
        int d=VID[n*1+(i+2)%n];
        AddQuadInv(0,a,b,d,c);
      }
    }
    int gg=1;
  }
  void AddVidQuadInv(const vector<int>&VID,int a,int b,int c,int d)
  {
    AddVidTrisInv(VID,a,b,c);
    AddVidTrisInv(VID,c,d,a);
  }
  void AddVidQuad(const vector<int>&VID,int a,int b,int c,int d)
  {
    AddVidTris(VID,a,b,c);
    AddVidTris(VID,c,d,a);
  }
  void AddVidTris(const vector<int>&VID,int a,int b,int c)
  {
    AddTris(VID[a],VID[b],VID[c]);
  }
  void AddVidTrisInv(const vector<int>&VID,int a,int b,int c)
  {
    AddTrisInv(VID[a],VID[b],VID[c]);
  }
  void AddQuadEx(int mod,int offset,int base,int a,int b,int c,int d)
  {
    auto vp=base;
    AddTris(vp+(a+offset)%mod,vp+(b+offset)%mod,vp+(c+offset)%mod);
    AddTris(vp+(c+offset)%mod,vp+(d+offset)%mod,vp+(a+offset)%mod);
  }
  void AddQuad(int base,int a,int b,int c,int d)
  {
    auto vp=base;
    AddTris(vp+a,vp+b,vp+c);
    AddTris(vp+c,vp+d,vp+a);
  }
  void AddQuadInv(int base,int a,int b,int c,int d)
  {
    auto vp=base;
    AddTrisInv(vp+a,vp+b,vp+c);
    AddTrisInv(vp+c,vp+d,vp+a);
  }
  void DrawCubeFast(const vec3f&offset,const vec3f&size=vec3f(1,1,1))
  {
    QapDev::BatchScope scope(*this);
    vec2i arr[]={vec2i(-1,-1),vec2i(+1,-1),vec2i(+1,+1),vec2i(-1,+1)};
    auto vp=VPos;
    for(int i=0;i<4;i++)
    {
      auto a=QapDev::toVec3f(arr[i],-1).RawMul(size*0.5)+offset;
      auto b=QapDev::toVec3f(arr[i],+1).RawMul(size*0.5)+offset;
      AddVertex(a,color);
      AddVertex(b,color);
      AddQuadEx(8,i*2,vp,0,1,3,2);
    }
    AddQuad(vp+0,0,2,4,6);
    AddQuad(vp+1,6,4,2,0);
  }
  void DrawCube(const vec3f&offset,real size=1){
    DrawCube(offset,vec3f_one*size);
  }
  void DrawCube(const vec3f&offset,const vec3f&size)
  {
    DrawCubeFast(offset,size);
    return;
    QapDev::BatchScope scope(*this);
    real d;
    auto add_vertex=[&](float x,float y,float z)
    {
      AddVertex(vec3f(x,y,z).RawMul(size*0.5)+offset);
    };
    int n=VPos;
    auto add_tris=[&](){
      AddTris(n+0,n+1,n+2);
      AddTris(n+2,n+3,n+0);
    };
    #define GRAY(){color=gray;}
    #define YZ(Y,Z)add_vertex(d,Y,Z);
    #define XZ(X,Z)add_vertex(X,d,Z);
    #define XY(X,Y)add_vertex(X,Y,d);
    #define LIST(F){n=VPos;F(-1,-1);F(+1,-1);F(+1,+1);F(-1,+1);add_tris();}
    d=-1;
    LIST(XY);
    LIST(YZ);
    LIST(XZ);
    d=+1;
    LIST(XY);
    LIST(YZ);
    LIST(XZ);
    #undef LIST
    #undef XZ
    #undef YZ
    #undef XY
    #undef GRAY
  }
  void AddIndex(int id){IBA[IPos++]=id;}
public:
  #include "t_geom.inl"
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
    if(Ref.Mem.size==this->Mem.size){
      memcpy_s(this->Mem.ptr,this->Mem.size*sizeof(TYPE),Ref.Mem.ptr,Ref.Mem.size*sizeof(TYPE));
      return;
    }
    Free();
    if(!Ref)return;
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
    if(*this)Free();
    QapAssert(size>0);
    QapAssert(size<(1<<26));
    Mem.ptr=(TMemory::ptr_t*)(void*)new TYPE[size];
    Mem.size=size;
  }
  void Free()
  {
    if(!Mem.ptr)return;
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
public:
  typedef QapTexMem SelfClass;
public:
  QapArray<QapColor> Arr;
  int W;
  int H;
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->Arr);
    (this->W)=(0);
    (this->H)=(0);
  }
public:
public:
  QapTexMem()
  {
    DoReset();
  }
  QapTexMem(const QapTexMem&Ref)
  {
    oper_set(Ref);
  }
  void operator=(const QapTexMem&Ref)
  {
    oper_set(Ref);
  }
  void oper_set(const QapTexMem&Ref)
  {
    this->Arr=Ref.Arr;
    this->W=Ref.W;
    this->H=Ref.H;
  }
  QapTexMem(QapTexMem&&Ref)
  {
    oper_set(std::move(Ref));
  }
  void operator=(QapTexMem&&Ref)
  {
    oper_set(std::move(Ref));
  }
  void oper_set(QapTexMem&&Ref)
  {
    this->Arr=std::move(Ref.Arr);
    this->W=std::move(Ref.W);
    this->H=std::move(Ref.H);
  }
  QapTexMem Clone()
  {
    QapTexMem tmp;
    tmp=*this;
    return std::move(tmp);
  }
  void CopyDataFrom(const QapTexMem&Ref)
  {
    QapTexMem tmp;
    this->Arr=Ref.Arr;
    this->W=Ref.W;
    this->H=Ref.H;
  }
  void MoveDataFrom(QapTexMem&Ref)
  {
    QapTexMem tmp;
    this->Arr=std::move(Ref.Arr);
    this->W=std::move(Ref.W);
    Ref.W=0;
    this->H=std::move(Ref.H);
    Ref.H=0;
  }
  void Init(int W,int H)
  {
    this->W=W;
    this->H=H;
    Arr.Init(W*H);
  }
  void Free()
  {
    Arr.Free();
  }
  QapColor*get()
  {
    return Arr.get();
  }
  const QapColor*get()const
  {
    return Arr.get();
  }
  operator bool()const
  {
    return Arr;
  }
public:
  void InvertY()
  {
    QapColor*pBits=Arr.get();
    for (int i=0;i<H/2;i++)
    {
      int a=W*(i);
      int b=W*(H-i-1);
      for (int j=0;j<W;j++)
      {
        std::swap(pBits[a+j],pBits[b+j]);
      }
    }
  }
  void InvertX()
  {
    QapColor*pBits=Arr.get();
    for (int i=0;i<H;i++)
    {
      QapColor*pLine=&pBits[i*W];
      for (int j=0;j<W/2;j++)
      {
        int a=j;
        int b=W-j-1;
        std::swap(pLine[a],pLine[b]);
      }
    }
  }
public:
  void GenRect(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for (int i=0;i<TexSize;i++)
    {
      for (int j=0;j<TexSize;j++)
      {
        *pT=0x80000000;
        pT++;
      }
    }
    RectLine(0,0,TexSize,TexSize,0xffffffff);
  }
  void GenBall(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for (int i=0;i<TexSize;i++)
    {
      for (int j=0;j<TexSize;j++)
      {
        float x=i-TexSize/2;
        float y=j-TexSize/2;
        float r=(float)TexSize/2;
        float m=((x*x)+(y*y))/(r*r);
        if(m>1.0f)
        {
          *pT=0x00000000;
          pT++;
          continue;
        }
        m=std::max(0.0f,1.0f-(m*m*m));
        m=std::min(1.0f,m);
        float a=(m<0.5)?m*2:1;
        a=std::min(1.0f,a);
        a=std::max(0.0f,a);
        byte bm=m*255;
        pT->a=byte(a*255);
        pT->r=bm;
        pT->g=bm;
        pT->b=bm;
        pT++;
      }
    }
  }
  void GenQuad(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for (int i=0;i<TexSize;i++)
    {
      for (int j=0;j<TexSize;j++)
      {
        float x=i-TexSize/2+0.5f,y=j-TexSize/2+0.5f;
        float r=(float)TexSize/2;
        float m=((x*x*x*x)+(y*y*y*y))/(r*r*r*r);
        if(m>1.0f)
        {
          *pT=0x00000000;
          pT++;
          continue;
        }
        m=std::max(0.0f,1.0f-(m*m*m));
        m=std::min(1.0f,m);
        float a=(m<0.5)?m*2:1;
        a=std::min(1.0f,a);
        a=std::max(0.0f,a);
        byte bm=m*255;
        pT->a=byte(a*255);
        pT->r=bm;
        pT->g=bm;
        pT->b=bm;
        pT++;
      }
    }
  }
  void FillBorder(int x,int y,const QapTexMem&Source,int n=4)
  {
    auto&Target=*this;
    if(!Source)
    {
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    if(1)
    {
      {
        auto src=pS[(00-0)+(00-0)*sW];
        for (int i=0;i<n;i++)for (int j=0;j<n;j++)if((y+(j+(00-n)))>=0)if((y+(j+(00-n)))<H)if((x+(i+(00-n)))<W)if((x+(i+(00-n)))>=0)pT[(x+(i+(00-n)))+(y+(j+(00-n)))*W]=(src);
      };
      {
        auto src=pS[(sW-1)+(00-0)*sW];
        for (int i=0;i<n;i++)for (int j=0;j<n;j++)if((y+(j+(00-n)))>=0)if((y+(j+(00-n)))<H)if((x+(i+(sW-0)))<W)if((x+(i+(sW-0)))>=0)pT[(x+(i+(sW-0)))+(y+(j+(00-n)))*W]=(src);
      };
      {
        auto src=pS[(sW-1)+(sH-1)*sW];
        for (int i=0;i<n;i++)for (int j=0;j<n;j++)if((y+(j+(sH-0)))>=0)if((y+(j+(sH-0)))<H)if((x+(i+(sW-0)))<W)if((x+(i+(sW-0)))>=0)pT[(x+(i+(sW-0)))+(y+(j+(sH-0)))*W]=(src);
      };
      {
        auto src=pS[(00-0)+(sH-1)*sW];
        for (int i=0;i<n;i++)for (int j=0;j<n;j++)if((y+(j+(sH-0)))>=0)if((y+(j+(sH-0)))<H)if((x+(i+(00-n)))<W)if((x+(i+(00-n)))>=0)pT[(x+(i+(00-n)))+(y+(j+(sH-0)))*W]=(src);
      };
    }
    if(1)
    {
      for (int k=1;k<=n;k++)
      {
        {
          int j=00+y;
          if(InDip(0,j-k,H-1))for (int i=max(0,x);i<mX;i++)
            {
              pT[i+(j-k)*W]=pS[(i-x)+(j-y)*sW];
            }
        }
        {
          int j=mY-1;
          if(InDip(0,j+k,H-1))for (int i=max(0,x);i<mX;i++)
            {
              pT[i+(j+k)*W]=pS[(i-x)+(j-y)*sW];
            }
        }
        {
          int i=00+x;
          if(InDip(0,i-k,W-1))for (int j=max(0,y);j<mY;j++)
            {
              pT[(i-k)+j*W]=pS[(i-x)+(j-y)*sW];
            }
        }
        {
          int i=mX-1;
          if(InDip(0,i+k,W-1))for (int j=max(0,y);j<mY;j++)
            {
              pT[(i+k)+j*W]=pS[(i-x)+(j-y)*sW];
            }
        }
      }
    }
    return;
  }
  void FillMem(int x,int y,const QapTexMem&Source)
  {
    auto&Target=*this;
    if(!Source)
    {
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for (int j=max(0,y);j<mY;j++)
    {
      for (int i=max(0,x);i<mX;i++)
      {
        pT[i+j*W]=pS[(i-x)+(j-y)*sW];
      }
    }
    return;
  }
  void DrawInHalfScale(const QapTexMem&Source,int count)
  {
    if(count<0)return;
    if(!count)
    {
      CopyDataFrom(Source);
      return;
    }
    QapTexMem Src=Source;
    for (int i=0;i<count;i++)
    {
      QapTexMem Target;
      int sW=Src.W;
      int sH=Src.H;
      QapAssert(!(sW%2));
      QapAssert(!(sH%2));
      Target.Init(Src.W/2,Src.H/2);
      auto tW=Target.W;
      auto tH=Target.H;
      auto*pS=Src.get();
      auto*pT=Target.get();
      for (int y=0;y<tH;y++)for (int x=0;x<tW;x++)
        {
          auto&out=pT[x+y*tW];
          auto a=pS[(x*2+(0))+(y*2+(0))*sW];
          auto b=pS[(x*2+(1))+(y*2+(0))*sW];
          auto c=pS[(x*2+(0))+(y*2+(1))*sW];
          auto d=pS[(x*2+(1))+(y*2+(1))*sW];
          auto e=QapColor::HalfMix(a,b);
          auto f=QapColor::HalfMix(c,d);
          out=QapColor::HalfMix(e,f);
        }
      Src.MoveDataFrom(Target);
    }
    MoveDataFrom(Src);
  }
  void DrawMemWithBlend(int x,int y,const QapTexMem&Source)
  {
    auto&Target=*this;
    if(!Source)
    {
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for(int j=max(0,y);j<mY;j++)
    {
      for(int i=max(0,x);i<mX;i++)
      {
        auto inp=pS[(i-x)+(j-y)*sW];
        auto&out=pT[i+j*W];
        auto a=inp.a;
        auto b=255-a;
        out.a=inp.a;
        #define F(r)out.r=(out.r*b+inp.r*a)/255;
        F(r)F(g)F(b)
        #undef F
      }
    }
    return;
  }
  void DrawMemWithBlend(int x,int y,const QapTexMem&Source,const QapColor&color)
  {
    auto&Target=*this;
    if(!Source)
    {
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for (int j=max(0,y);j<mY;j++)
    {
      for (int i=max(0,x);i<mX;i++)
      {
        auto inp=pS[(i-x)+(j-y)*sW]*color;
        auto&out=pT[i+j*W];
        auto a=inp.a;
        auto b=255-a;
        out.a=inp.a;
        #define F(r)out.r=(out.r*b+inp.r*a)/255;
        F(r)F(g)F(b)
        #undef F
      }
    }
    return;
  }
  void Clear(const QapColor&color=0xFF000000)
  {
    auto*pBits=get();
    for (int i=0;i<W*H;i++)pBits[i]=color;
  }
  void FillLine(const int Y,const QapColor&Color)
  {
    auto*pBits=get();
    for (int i=0;i<W;i++)
    {
      QapColor&pix=pBits[Y*W+i];
      pix=Color;
    }
  }
  void FillColumn(const int X,const QapColor&Color)
  {
    auto*pBits=get();
    for (int i=0;i<H;i++)
    {
      QapColor&pix=pBits[i*W+X];
      pix=Color;
    }
  }
  void RectLine(int X,int Y,int W,int H,const QapColor&Color)
  {
    FillLineEx(Y+0-0,X+0,X+W,Color);
    FillLineEx(Y+H-1,X+0,X+W,Color);
    FillColomnEx(X+0-0,Y+0,Y+H,Color);
    FillColomnEx(X+W-1,Y+0,Y+H,Color);
  }
  void FillLineEx(const int Y,const int X0,const int X1,const QapColor&Color)
  {
    auto*pBits=get();
    int x0=Clamp<int>(X0,0,W);
    int x1=Clamp<int>(X1,0,W);
    if(x0>x1)std::swap(x0,x1);
    for (int i=x0;i<x1;i++)
    {
      QapColor&pix=pBits[Y*W+i];
      pix=Color;
    }
  }
  void FillColomnEx(const int X,const int Y0,const int Y1,const QapColor&Color)
  {
    auto*pBits=get();
    int y0=Clamp<int>(Y0,0,H);
    int y1=Clamp<int>(Y1,0,H);
    if(y0>y1)std::swap(y0,y1);
    for (int i=y0;i<y1;i++)
    {
      QapColor&pix=pBits[i*W+X];
      pix=Color;
    }
  }
public:
  void CopyAlpha(QapTexMem&Alpha)
  {
    auto*pBits=get();
    auto*pAlphaBits=get();
    if(Alpha.W!=W||Alpha.H!=H)return;
    for (int i=0;i<W*H;i++)pBits[i].a=pAlphaBits[i].a;
  }
  void CalcAlpha()
  {
    auto*pBits=get();
    for (int i=0;i<W*H;i++)pBits[i].a=pBits[i].GetLuminance();
  }
  void CalcAlpha(const QapColor&Color,int threshold=0)
  {
    auto*pBits=get();
    for (int i=0;i<W*H;i++)pBits[i].a=pBits[i]==Color?0:255;
    const QapColor&c=Color;
    int t=threshold;
    int t3=t*3;
    for (int i=0;i<W*H;i++)
    {
      QapColor&p=pBits[i];
      int fr=fabs(int(p.r)-int(c.r));
      int fg=fabs(int(p.g)-int(c.g));
      int fb=fabs(int(p.b)-int(c.b));
      int sum=fr+fg+fb;
      p.a=sum>t3?255:t3?255*sum/t3:0;
    }
  }
  void FillChannel(const QapColor&Source,DWORD BitMask)
  {
    auto*pBits=get();
    for (int i=0;i<W*H;i++)
    {
      QapColor&C=pBits[i];
      C=(~BitMask&C)|(BitMask&Source);
    };
  }/*
  struct t_blur_matrix{
    vector<int> mat;
    int r;
    int sum;
    void get_sum()const{int out=0;auto&arr=mat;for(int i=0;i<arr.size();i++)out+=arr[i];return out;}
    void make_circle(int radius)
    {
      r=radius;auto d=r+r;
      mat.resize(d*d);
      auto*p=&mat[0];
      for(int i=0;i<d;i++)for(int j=0;j<d;j++)
      {
        auto x=i-r;
        auto y=j-r;
        bool outside=(x*x)+(y*y)>r*r;
        *p=outside?0:1;
        p++;
      }
      sum=get_sum();
    }
  };
  
  the algo that blur image but assigne with space. look like full space blur. that nice. i can do it.
  the alog:
  {
    get space size
    make image for them
    fill black or bgcolor.
    so init finished
    let's go describe evry frame blur
    so we draw the world to image
    and the just blur image
    so now we done it - loop end;
    
    but one case still not disribed
    how we do render full world to image? the is most umbigouse part of algo.
    can i make render tatger with any size? not.
    can i make software image with almost any size? yup.
    can i write full indetical software render? i think no. but i can reach almost the same image. only lines is still problem for me.
    but i can write the algo. or just ignore them.
    i can exclude lines for the world and make circle insted of this.
    also i relly can draw circles instead of single line. this mean all problems solved? yes.
    all problem solved now. and solutions found.
    let's go write code?
    no? why?
    what wrong?
    how about the full software render?
    i mean stop using direct3d at all.
    this mean end of epoch direc3d?
    i'm not ready.
    fuck stupid dialog.
    no.
    
  }
  void ProBlur(const t_blur_matrix&mat)//only D3DFMT_A8R8G8B8
  {
    auto*pBits=get();
    if(!pBits||!W||!H)return;
    //static vector<QapColor> vMem;
    vMem.resize(W*H);
    if(W*H!=Arr.Mem.size)
    {
      QapDebugMsg("WTF?");return;
    }
    auto*pBuff=&vMem[0];
    for(int y=0;y<H;y++)for(int x=0;x<W;x++){
      vec4i buff;auto*p=&pBits[y*W+x-1];
      for(int i=0;i<mat.size();i++){
        buff+=vec4i()*mat[i];
      }
      #define F(dx,expr)buff+=vec4i(*p)##expr;p++;
      F(-1,;)F(0,*2)F(+1,;);
      #undef F
      tri[y*W+x]=(buff>>2).unsafe_but_fast_GetColor_without_asserts();
    }
    for(int j=1;j<H-1;j++)
    {
      for(int i=1;i<W-1;i++)
      {
        auto&out=pBits[j*W+i];
        //auto cur_id=j*W+i;
        vec4i buff;auto*p=&tri[(j-1)*W+i];
        #define F(dy,expr)buff+=vec4i(*p)##expr;p+=W;
        F(-1,;)F(0,*2)F(+1,;);
        #undef F
        out=(buff>>2).unsafe_but_fast_GetColor_without_asserts();
      }
    }
    return;
  }*/
  void BlurTextureV3(int PassCount)//only D3DFMT_A8R8G8B8
  {
    auto*pBits=get();
    if(!pBits||!W||!H)return;
    //static vector<QapColor> vMem;
    static vector<QapColor> vTri;
    //vMem.resize(W*H);
    vTri.resize(W*H);
    if(W*H!=Arr.Mem.size)
    {
      QapDebugMsg("WTF?");return;
    }
    //auto*pBuff=&vMem[0];
    auto*tri=&vTri[0];
    /*static const int BBM[]={
      1,2,1, 
      2,4,2, 
      1,2,1
    };
    static int MartixSum=0;
    if(!MartixSum){for(int i=0;i<lenof(BBM);i++)MartixSum+=BBM[i];}
    QapAssert(MartixSum==16);*/
    for(int PassId=0;PassId<PassCount;PassId++)
    {
      //memcpy_s(pBuff,sizeof(QapColor)*vMem.size(),pBits,Arr.Mem.size*sizeof(QapColor));//copy image
      for(int y=0;y<H;y++)for(int x=1;x+1<W;x++){
        vec4i buff;auto*p=&pBits[y*W+x-1];
        #define F(dx,expr)buff+=vec4i(*p)##expr;p++;
        F(-1,;)F(0,*2)F(+1,;);
        #undef F
        tri[y*W+x]=(buff>>2).unsafe_but_fast_GetColor_without_asserts();
      }
      for(int j=1;j<H-1;j++)
      {
        for(int i=1;i<W-1;i++)
        {
          auto&out=pBits[j*W+i];
          //auto cur_id=j*W+i;
          vec4i buff;auto*p=&tri[(j-1)*W+i];
          #define F(dy,expr)buff+=vec4i(*p)##expr;p+=W;
          F(-1,;)F(0,*2)F(+1,;);
          #undef F
          out=(buff>>2).unsafe_but_fast_GetColor_without_asserts();
        }
      }
    }
    return;
  }
  //-------------------------------------------------------------------- OLD BELOW------------------
  //-------------------------------------------------------------------- OLD BELOW------------------
  //-------------------------------------------------------------------- OLD BELOW------------------
  //-------------------------------------------------------------------- OLD BELOW------------------
  //-------------------------------------------------------------------- OLD BELOW------------------
  //-------------------------------------------------------------------- OLD BELOW------------------
  void BlurTextureV2(int PassCount)//only D3DFMT_A8R8G8B8
  {
    auto*pBits=get();
    if(!pBits||!W||!H)return;
    static vector<QapColor> vMem;
    vMem.resize(W*H);
    if(W*H!=Arr.Mem.size)
    {
      QapDebugMsg("WTF?");return;
    }
    auto*pBuff=&vMem[0];
    static const int BBM[]={
      1,2,1, 
      2,4,2, 
      1,2,1
    };
    static int MartixSum=0;
    if(!MartixSum){for(int i=0;i<lenof(BBM);i++)MartixSum+=BBM[i];}
    QapAssert(MartixSum==16);
    const int PosRange[]={
      -W-1,-W,-W+1,
      -1-0,+0,-0+1,
      +W-1,+W,+W+1
    };
    for(int PassId=0;PassId<PassCount;PassId++)
    {
      memcpy_s(pBuff,sizeof(QapColor)*vMem.size(),pBits,Arr.Mem.size*sizeof(QapColor));//copy image
      for(int j=1;j<H-1;j++)
      {
        for(int i=1;i<W-1;i++)
        {
          auto&out=pBits[j*W+i];
          auto cur_id=j*W+i;
          vec4i buff;
          for(int t=0;t<9;t++)
          {
            auto T=pBuff[cur_id+PosRange[t]];
            buff+=vec4i(T)*BBM[t];
          };    
          static_assert(1==(16>>4),"orly?");
          static_assert(16==(1<<4),"orly?");
          static_assert((1024/16)==(1024>>4),"orly?");
          buff>>=4;//buff/=MartixSum;
          out=buff.unsafe_but_fast_GetColor();
        }
      }
    }
    return;
  }
  //----OLD ABOVE------OLD ABOVE----------OLD ABOVE-------OLD ABOVE----- OLD ABOVE------------------
  //----OLD ABOVE------OLD ABOVE----------OLD ABOVE-------OLD ABOVE----- OLD ABOVE------------------
  //----OLD ABOVE------OLD ABOVE----------OLD ABOVE-------OLD ABOVE----- OLD ABOVE------------------
  //----OLD ABOVE------OLD ABOVE----------OLD ABOVE-------OLD ABOVE----- OLD ABOVE------------------
  //----OLD ABOVE------OLD ABOVE----------OLD ABOVE-------OLD ABOVE----- OLD ABOVE------------------
  //----OLD ABOVE------OLD ABOVE----------OLD ABOVE-------OLD ABOVE----- OLD ABOVE------------------
  void BlurTexture(int PassCount)
  {
    auto*pBits=get();
    struct QapARGB
    {
      BYTE B,G,R,A;
    };
    static QapARGB VoidMem[2048*2048*4];
    memcpy_s(VoidMem,sizeof(VoidMem),pBits,W*H*sizeof(QapARGB));
    static int BBM[9]=
    {
      1,2,1,
      2,4,2,
      1,2,1
    };
    static int MartixSum;
    {
      static bool _STATIC_SYS_FLAG=true;
      if(_STATIC_SYS_FLAG)
      {
        for (int i=0;i<9;i++)MartixSum+=BBM[i];
        _STATIC_SYS_FLAG=false;
      }
      ;
    };
    int PosRange[9]=
    {
      -W-1,-W,-W+1,
      -1,0,+1,
      +W-1,+W,+W+1
    };
    for (int PassId=0;PassId<PassCount;PassId++)
    {
      QapARGB *PC=0;
      QapARGB *VM=0;
      for (int j=1;j<H-1;j++)
        for (int i=1;i<W-1;i++)
        {
          PC=(QapARGB*)pBits+j*W+i;
          VM=(QapARGB*)VoidMem+j*W+i;
          float AF[4]={0,0,0,0};
          for (int t=0;t<9;t++)
          {
            QapARGB T=*(VM+PosRange[t]);
            AF[0]+=T.R*BBM[t];
            AF[1]+=T.G*BBM[t];
            AF[2]+=T.B*BBM[t];
            AF[3]+=T.A*BBM[t];
          };
          for (int i=0;i<4;i++)AF[i]/=MartixSum*255.0;
          QapColor PCC=D3DCOLOR_COLORVALUE(AF[0],AF[1],AF[2],AF[3]);
          *PC=*((QapARGB*)&PCC);
        }
      memcpy_s(VoidMem,sizeof(VoidMem),pBits,W*H*sizeof(QapARGB));
    }
    return;
  }
};
class QapTexFile
{
public:
public:
  typedef QapTexFile SelfClass;
public:
  string FN;
  QapTexMem Mem;
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->FN);
    detail::FieldTryDoReset(this->Mem);
  }
public:
  QapTexFile(const QapTexFile&)
  {
    QapDebugMsg("QapTexFile"" is noncopyable");
    DoReset();
  };
  QapTexFile()
  {
    DoReset();
  };
public:
  QapTexFile(QapTexFile&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(QapTexFile&&_Right)
  {
    if(&_Right==this)return;
    {
    }
    this->FN=std::move(_Right.FN);
    this->Mem=std::move(_Right.Mem);
  }
public:
public:
  void Load()
  {
  }
  void Save()
  {
  }
};
class QapTex
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapTex OwnerClass;
    void operator=(OwnerClass*pOwner)
    {
      this->pOwner=pOwner;
    }
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr)
    {
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource()
    {
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev)
    {
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost()
    {
      if(pOwner)
      {
        flag=bool(pOwner->Tex);
        pOwner->Free();
      }
      else
      {
        QapDebugMsg("fail");
        flag=false;
      }
    }
    void OnReset()
    {
      if(pOwner&&flag)pOwner->ReInit();
    }
  };
public:
public:
  typedef QapTex SelfClass;
public:
  int W;
  int H;
  int Levels;
  TDynamicResource DynRes;
  IDirect3DTexture9* Tex;
  bool after_reinit;
public:
  void DoReset()
  {
    {
    }
    (this->W)=(0);
    (this->H)=(0);
    (this->DynRes)=(this);
    (this->Tex)=(nullptr);
    //added:
    (this->after_reinit=false);
  }
public:
  QapTex(const QapTex&)
  {
    QapDebugMsg("QapTex"" is noncopyable");
    DoReset();
  };
  QapTex()
  {
    DoReset();
  };
public:
public:
  ~QapTex()
  {
    Free();
  }
public:
  bool OnReinit(){auto f=after_reinit;after_reinit=false;return f;}
  void ReInit(){after_reinit=true;Init(W,H,Levels);}
  void MountDev(QapD3DDev9&Dev)
  {
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int W,int H,int Levels)
  {
    Free();
    auto*Sys=DynRes.pDev;
    Sys->pDev->CreateTexture(W,H,Levels,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&Tex,NULL);
    this->W=W;this->H=H;this->Levels=Levels;
  }
  void Free()
  {
    if(!Tex)return;
    Tex->Release();
    Tex=nullptr;
  };
  operator bool()const
  {
    return Tex;
  }
  void Bind(int lvl=0)
  {
    auto*Sys=DynRes.pDev;
    if(!Sys)return;
    Sys->pDev->SetTexture(lvl,Tex);
  };
public:
  void QapTex::operator=(const QapTex&)
  {
    QapDebugMsg("fail");
  }
};
#pragma once
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
  ):
      hInstance(hInstance),
      hPrevInstance(hPrevInstance),
      lpCmdLine(lpCmdLine),
      nCmdShow(nCmdShow)
  {
    GlobalEnv::Get(this);
  }
public:
  static const GlobalEnv&Get(GlobalEnv*ptr=nullptr)
  {
    static GlobalEnv*pGE=nullptr;
    if(!pGE)std::swap(pGE,ptr);
    QapAssert(pGE&&!ptr);
    return *pGE;
  }
private:
  GlobalEnv(const GlobalEnv&);
  void operator=(const GlobalEnv&);
};
static bool IsKeyDown(int vKey)
{
  int i=GetAsyncKeyState(vKey);
  return i<0;
}
class TQuad
{
public:
public:
  typedef TQuad SelfClass;
public:
  int x;
  int y;
  int w;
  int h;
public:
  void DoReset()
  {
    {
    }
    (this->x)=(320);
    (this->y)=(240);
    (this->w)=(320);
    (this->h)=(240);
  }
public:
  TQuad(const TQuad&)
  {
    QapDebugMsg("TQuad"" is noncopyable");
    DoReset();
  };
  TQuad()
  {
    DoReset();
  };
public:
  TQuad(TQuad&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TQuad&&_Right)
  {
    if(&_Right==this)return;
    {
    }
    this->x=std::move(_Right.x);
    this->y=std::move(_Right.y);
    this->w=std::move(_Right.w);
    this->h=std::move(_Right.h);
  }
public:
public:
  void Set(int x,int y,int w,int h)
  {
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
  }
  vec2i&GetPos()
  {
    return *(vec2i*)(void*)(&this->x);
  }
  vec2i&GetSize()
  {
    return *(vec2i*)(void*)(&this->w);
  }
  void SetAs(const vec2i&pos,const vec2i&size)
  {
    GetPos()=pos;
    GetSize()=size;
  }
  RECT GetWinRect()
  {
    RECT tmp={x,y,x+w,y+h};
    return tmp;
  }
  void SetWinRect(const RECT&rect)
  {
    TQuad&r=*(TQuad*)(void*)(&rect);
    Set(r.x,r.y,r.w-r.x,r.h-r.y);
  }
  void SetSize(const SIZE&size)
  {
    w=size.cx;
    h=size.cy;
  }
  static TQuad getFullScreen()
  {
    TQuad tmp;
    auto mode=GetScreenMode();
    tmp.Set(0,0,mode.W,mode.H);
    return std::move(tmp);
  }
  void setAtCenter(const TQuad&quad)
  {
    QapAssert(quad.w>=w);
    QapAssert(quad.h>=h);
    x=(quad.w-w)/2;
    y=(quad.h-h)/2;
  }
  void subpos(const TQuad&q)
  {
    x-=q.x;
    y-=q.y;
  }
  void setAtCenterScreen()
  {
    setAtCenter(getFullScreen());
  }
};
class TD3DGameBox
{
public:
  class TForm
  {
  public:
    class WndClassPair
    {
    public:
      WNDPROC Proc;
      HWND hWnd;
      int ID;
      bool Used;
    public:
      WndClassPair():Proc(nullptr),hWnd(nullptr),ID(0),Used(false) {}
      WndClassPair(WNDPROC Proc,HWND hWnd,int ID,bool Used):Proc(Proc),hWnd(hWnd),ID(ID),Used(Used) {}
    public:
      void Init(TForm*Owner)
      {
        WndProcHeap::Get().Load(*this);
        QapAssert(!Used);
        QapAssert(!hWnd);
        Used=true;
        Proc((HWND)Owner,WMU_INIT,0,0);
      }
      void Free(TForm*Owner)
      {
        QapAssert(!hWnd);
        QapAssert(Used);
        Used=false;
        Proc((HWND)Owner,WMU_FREE,0,0);
        WndProcHeap::Get().Save(*this);
      }
    };
    class WndProcHeap
    {
    public:
      vector<WndClassPair> Arr;
      void Load(WndClassPair&WinPair)
      {
        QapAssert(!Arr.empty());
        WndClassPair&WCP=Arr.back();
        WinPair=std::move(WCP);
        Arr.pop_back();
      }
      void Save(WndClassPair&WinPair)
      {
        Arr.push_back(std::move(WinPair));
      }
      static WndProcHeap&Get()
      {
        static WndProcHeap Heap;
        static bool flag=false;
        if(!flag)
        {
          vector<WndClassPair>&Arr=Heap.Arr;
          {
            WndClassPair tmp(WndProc<0>,nullptr,0,false);
            Arr.push_back(tmp);
          };
          {
            WndClassPair tmp(WndProc<1>,nullptr,1,false);
            Arr.push_back(tmp);
          };
          flag=true;
        }
        return Heap;
      }
    };
  public:
  public:
    typedef TD3DGameBox OwnerClass;
  public:
    typedef TForm SelfClass;
  public:
    TD3DGameBox* Owner;
    ATOM ClassAtom;
    string ClassName;
    WndClassPair WinPair;
  public:
    void DoReset()
    {
      {
      }
      (this->Owner)=(nullptr);
      (this->ClassAtom)=(0);
      (this->ClassName)=("");
      (this->WinPair)=(WndClassPair());
    }
  public:
    TForm(const TForm&)
    {
      QapDebugMsg("TForm"" is noncopyable");
      DoReset();
    };
    TForm()
    {
      DoReset();
    };
  public:
  public:
    ~TForm()
    {
      if(WinPair.hWnd)Free();
    }
    void operator=(TD3DGameBox*Owner)
    {
      this->Owner=Owner;
    }
  public:
    void Init()
    {
      WinPair.hWnd=nullptr;
      auto tmp=CreateWindowA(
            (LPCSTR)ClassAtom,
            "Unnamed",
            WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN,
            0, 0, 320, 240, NULL, NULL, GlobalEnv::Get().hInstance, NULL
          );
      WinPair.hWnd=tmp;
      QapAssert(tmp);
    }
    void Free()
    {
      QapAssert(DestroyWindow(WinPair.hWnd));
      WinPair.hWnd=nullptr;
    }
  public:
    void Reg()
    {
      WinPair.Init(this);
      ClassName="TD3DGameBox_"+IToS(WinPair.ID);
      WNDCLASSEX wcx;
      ZeroMemory(&wcx,sizeof(wcx));
      wcx.cbSize        = sizeof(wcx);
      wcx.hInstance     = GlobalEnv::Get().hInstance;
      wcx.hIcon         = LoadIcon(0,IDI_ASTERISK);
      wcx.hIconSm       = wcx.hIcon;
      wcx.hCursor       = LoadCursor(0,IDC_ARROW);
      wcx.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
      wcx.style         = 0;
      wcx.lpfnWndProc   = WinPair.Proc;
      wcx.lpszClassName = ClassName.c_str();
      ClassAtom=RegisterClassExA(&wcx);
    }
    bool UnReg()
    {
      WinPair.Free(this);
      bool flag=UnregisterClassA((LPCSTR)ClassAtom,GlobalEnv::Get().hInstance);
      ClassAtom=0;
      ClassName.clear();
      return flag;
    }
  public:
    static const UINT WMU_INIT=WM_USER+1234;
    static const UINT WMU_FREE=WM_USER+4321;
  public:
    template<int Index>
    static LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
    {
      if(msg==WM_INPUTLANGCHANGEREQUEST)
      {
        int gg=1;
        return DefWindowProcA(hWnd,msg,wParam,lParam);
      }
      if(msg==WM_INPUTLANGCHANGE)
      {
        int gg=1;
        return DefWindowProcA(hWnd,msg,wParam,lParam);
      }
      if(msg==WM_WINDOWPOSCHANGING)
      {
        static bool flag=true;
        if(flag)return 0;
      }
      static TForm*pForm=nullptr;
      if(!pForm)
      {
        QapAssert(WMU_INIT==msg);
        pForm=(TForm*)hWnd;
        return 0;
      }
      if(WMU_FREE==msg)
      {
        QapAssert(pForm);
        QapAssert(pForm->Owner);
        QapAssert(hWnd==((HWND)pForm));
        pForm=nullptr;
        return 0;
      }
      QapAssert(pForm);
      QapAssert(pForm->Owner);
      long UD=GetWindowLongA(hWnd,GWL_USERDATA);
      if(!UD)
      {
        SetWindowLong(hWnd,GWL_USERDATA,(long)pForm);
      }
      else
      {
        long pF=(long)pForm;
        QapAssert(pF==UD);
      }
      if(msg==WM_WINDOWPOSCHANGING)
      {
        QapAssert("WTF?");
        return 0;
      }
      auto result=pForm->Owner->WndProc(hWnd,msg,wParam,lParam);
      return result;
    }
  };
public:
public:
  typedef TD3DGameBox SelfClass;
public:
  string Caption;
  bool NeedClose;
  bool Runned;
  bool Visible;
  bool FullScreen;
  TQuad Quad;
  TForm Form;
  QapKeyboard Keyboard;
  QapKeyboard sys_kb_cur;
  QapKeyboard sys_kb_new;
  int zDelta;
  vec2i mpos;
public:
  void DoReset()
  {
    {
    }
    (this->Caption)=("TD3DGameBox");
    (this->NeedClose)=(false);
    (this->Runned)=(false);
    (this->Visible)=(true);
    (this->FullScreen)=(true);
    detail::FieldTryDoReset(this->Quad);
    (this->Form)=(this);
    detail::FieldTryDoReset(this->Keyboard);
    detail::FieldTryDoReset(this->sys_kb_cur);
    detail::FieldTryDoReset(this->sys_kb_new);
    (this->zDelta)=(0);
    detail::FieldTryDoReset(this->mpos);
  }
public:
  TD3DGameBox(const TD3DGameBox&)
  {
    QapDebugMsg("TD3DGameBox"" is noncopyable");
    DoReset();
  };
  TD3DGameBox()
  {
    DoReset();
  };
public:
  TD3DGameBox(TD3DGameBox&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TD3DGameBox&&_Right)
  {
    if(&_Right==this)return;
    {
    }
    this->Caption=std::move(_Right.Caption);
    this->NeedClose=std::move(_Right.NeedClose);
    this->Runned=std::move(_Right.Runned);
    this->Visible=std::move(_Right.Visible);
    this->FullScreen=std::move(_Right.FullScreen);
    this->Quad=std::move(_Right.Quad);
    this->Form=std::move(_Right.Form);
    this->Keyboard=std::move(_Right.Keyboard);
    this->sys_kb_cur=std::move(_Right.sys_kb_cur);
    this->sys_kb_new=std::move(_Right.sys_kb_new);
    this->zDelta=std::move(_Right.zDelta);
    this->mpos=std::move(_Right.mpos);
  }
public:
public:
  bool IsWindow()
  {
    return Form.WinPair.hWnd;
  }
  void Init()
  {
    if(IsWindow())return;
    Form.Reg();
    Form.Init();
    UpdateWnd();
    Runned=true;
  }
  void UpdateWnd()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    SetWindowTextA(hWnd,Caption.c_str());
  }
  void WindowMode()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    TScreenMode SM=GetScreenMode();
    DWORD Style=true?WS_OVERLAPPED:WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
    SetWindowLong(hWnd,GWL_STYLE,Style);
    RECT Rect=Quad.GetWinRect();
    AdjustWindowRect(&Rect,Style,false);
    SetWindowPos(hWnd,0,Quad.x,Quad.y,Quad.w,Quad.h,SWP_FRAMECHANGED|SWP_NOOWNERZORDER);
    Sleep(16);
    ShowWindow(hWnd,SW_MAXIMIZE);
    ShowWindow(hWnd,Visible?SW_SHOW:SW_HIDE);
  }
  ~TD3DGameBox()
  {
    Free();
  }
  void Free()
  {
    if(!IsWindow())return;
    Runned=false;
    Form.Free();
    Form.UnReg();
    NeedClose=false;
  }
  void update_Keyboard()
  {
    if(sys_kb_cur!=Keyboard){
      QapDebugMsg("oh, look like somewhere Keyboard is modified, but now it will be rewrite with new state and all changes will be lost.");
    }
    sys_kb_cur=sys_kb_new;
    Keyboard=sys_kb_cur;
  }
  void Update()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    zDelta=0;
    sys_kb_new.Sync();
    if(GetForegroundWindow()==hWnd)if(GetActiveWindow()==hWnd)mpos=unsafe_GetMousePos();
    for(;;)
    {
      MSG msg;
      if(!PeekMessageA(&msg,NULL,0,0,PM_REMOVE))break;
      TranslateMessage(&msg);
      {
        DispatchMessageA(&msg);
      }
    }
    update_Keyboard();
  }
  void Close()
  {
    NeedClose=true;
  }
  void ScanWinPlacement()
  {
    WINDOWPLACEMENT PL;
    GetWindowPlacement(Form.WinPair.hWnd,&PL);
    Quad.SetWinRect(PL.rcNormalPosition);
    QapAssert(Quad.x>-1000);
  }
  static bool Equal(RECT&a,RECT&b)
  {
    if(a.left!=b.left)return false;
    if(a.top!=b.top)return false;
    if(a.right!=b.right)return false;
    if(a.bottom!=b.bottom)return false;
    return true;
  }
  static void KeyboardUpdate(QapKeyboard&Keyboard,const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam)
  {
    bool any_key_up=(msg==WM_KEYUP)||(msg==WM_SYSKEYUP);
    bool any_key_down=(msg==WM_KEYDOWN)||(msg==WM_SYSKEYDOWN);
    if(msg==WM_ACTIVATE){
      Keyboard=std::move(QapKeyboard());
    }
    if(any_key_up||any_key_down)
    {
      bool value=any_key_down;
      auto&KB=Keyboard;
      auto&Down=Keyboard.Down;
      auto KeyUpdate=[&KB,&Down](int key,const bool value)->void
      {
        if(Down[key]==value)return;
        if(value!=IsKeyDown(key))return;
        KB.KeyUpdate(key,value);
      };
      struct TSysKey
      {
        int Key,LKey,RKey;
      } key_array[]=
      {
        {VK_SHIFT,VK_LSHIFT,VK_RSHIFT},
        {VK_CONTROL,VK_LCONTROL,VK_RCONTROL},
        {VK_MENU,VK_LMENU,VK_RMENU}
      };
      for (int i=0;i<lenof(key_array);i++)
      {
        auto&ex=key_array[i];
        if(wParam==ex.Key)
        {
          KeyUpdate(ex.LKey,value);
          KeyUpdate(ex.RKey,value);
        }
      }
    }
    if((msg==WM_KEYUP)&&(wParam==VK_SNAPSHOT))
    {
      if(wParam==VK_SNAPSHOT)
      {
        Keyboard.KeyUpdate(VK_SNAPSHOT,true);
      };
      if(wParam==VK_SNAPSHOT)
      {
        Keyboard.KeyUpdate(VK_SNAPSHOT,false);
      };
    }
    if(any_key_up)
    {
      Keyboard.KeyUpdate(wParam,false);
    }
    if(any_key_down)
    {
      Keyboard.KeyUpdate(wParam,true);
    }
    if(msg==WM_LBUTTONUP)
    {
      Keyboard.KeyUpdate(mbLeft,false);
    }
    if(msg==WM_RBUTTONUP)
    {
      Keyboard.KeyUpdate(mbRight,false);
    }
    if(msg==WM_MBUTTONUP)
    {
      Keyboard.KeyUpdate(mbMiddle,false);
    }
    if(msg==WM_LBUTTONDOWN)
    {
      Keyboard.KeyUpdate(mbLeft,true);
    }
    if(msg==WM_RBUTTONDOWN)
    {
      Keyboard.KeyUpdate(mbRight,true);
    }
    if(msg==WM_MBUTTONDOWN)
    {
      Keyboard.KeyUpdate(mbMiddle,true);
    }
    if((msg==WM_CHAR)||(msg==WM_SYSCHAR))
    {
      Keyboard.CharUpdate(wParam);
    }
  }
  LRESULT WndProc(const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam)
  {
    //if(Form.WinPair.hWnd!=hWnd)return DefWindowProcA(hWnd,msg,wParam,lParam);
    KeyboardUpdate(sys_kb_new,hWnd,msg,wParam,lParam);
    if(msg==WM_MOUSEWHEEL)
    {
      zDelta=GET_WHEEL_DELTA_WPARAM(wParam);
    };
    if(msg==WM_CHAR)
    {
      auto kbl=GetKeyboardLayout(0);
      auto ENGLISH = 0x409;
      auto RUSSIAN = 0x419;
      char c=wParam;
      int gg=1;
    }
    if(msg==WM_CLOSE)
    {
      Close();
      if(Runned)return 0;
    }
    if(msg==WM_SHOWWINDOW)
    {
      Visible=wParam;
    }
    if(msg==WM_ERASEBKGND)
    {
      DoPaint();
    }
    return DefWindowProcA(hWnd,msg,wParam,lParam);
  }
  void DoPaint()
  {
    HWND hWnd=Form.WinPair.hWnd;
    HDC DC=GetDC(hWnd);
    RECT Rect;
    GetClientRect(Form.WinPair.hWnd,&Rect);
    FillRect(DC,&Rect,(HBRUSH)(COLOR_BTNFACE));
    ReleaseDC(hWnd,DC);
  }
  vec2i GetClientSize()
  {
    RECT Rect;
    GetClientRect(Form.WinPair.hWnd,&Rect);
    return vec2i(Rect.right-Rect.left,Rect.bottom-Rect.top);
  }
  vec2i GetMousePos()
  {
    return mpos;
  }
  vec2i unsafe_GetMousePos()
  {
    POINT P;
    GetCursorPos(&P);
    auto hWnd=Form.WinPair.hWnd;
    ScreenToClient(hWnd,&P);
    vec2i p(P.x,-P.y);
    vec2i z=GetClientSize();
    return p-vec2i(z.x/2,-z.y/2);
  }
  void Hide()
  {
    ShowWindow(Form.WinPair.hWnd,SW_HIDE);
  }
  void Show()
  {
    ShowWindow(Form.WinPair.hWnd,SW_SHOW);
  }
};
//---

struct QapFontInfo{
  typedef vec2i vec2i_256[256];
  vec2i_256 Coords;
  vec2i&operator[](int index){return Coords[index];}
  const vec2i&operator[](int index)const{return Coords[index];}
};

struct QapFont{
  QapTexMem Mem;
  QapFontInfo Info;
};

struct QapBitmapInfo{
  BITMAPINFO BI;
  BITMAPINFOHEADER&BH;
  QapBitmapInfo(int W,int H):BH(BI.bmiHeader){
    ZeroMemory(&BI,sizeof(BI));
    BH.biSize=sizeof(BI.bmiHeader);
    BH.biWidth=W;BH.biHeight=H;
    BH.biPlanes=1;BH.biBitCount=32;
    BH.biSizeImage=W*H*4;
  }
};

static void CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize,bool fixed_pitch)
{
  Out.Free();
  Out.Init(TexSize,TexSize);
  QapColor*pix=Out.get();
  {
    HDC DC=GetDC(hWnd);
    int W=Bold?FW_BOLD:FW_NORMAL;
    int H=-MulDiv(Size,GetDeviceCaps(DC,LOGPIXELSY),72);
    {
      HFONT FNT=CreateFontA(H,0,0,0,W,0,0,0,RUSSIAN_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,fixed_pitch?FIXED_PITCH:DEFAULT_PITCH,Name.c_str());
      {
        HDC MDC=CreateCompatibleDC(DC);
        {
          HBITMAP BMP=CreateCompatibleBitmap(DC,TexSize,TexSize);
          SelectObject(MDC,BMP);
          RECT Rect; SetRect(&Rect,0,0,TexSize,TexSize);
          FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
          SelectObject(MDC,FNT);
          SetBkMode(MDC,TRANSPARENT);
          SetTextColor(MDC,0xFFFFFF);
          for(int i=0;i<256;i++)TextOutA(MDC,i%16*(TexSize/16),i/16*(TexSize/16),(LPCSTR)&i,1);
          {QapBitmapInfo QBI(TexSize,TexSize);GetDIBits(MDC,BMP,0,TexSize,pix,&QBI.BI,DIB_RGB_COLORS);}
          for(int i=0;i<TexSize*TexSize;i++){pix[i].a=pix[i].r;pix[i].r=255;pix[i].g=255;pix[i].b=255;}
          for(int i=0;i<256;i++){SIZE cs;GetTextExtentPoint32A(MDC,(LPCSTR)&i,1,&cs);Info.Coords[i]=vec2i(cs.cx,cs.cy);}
          DeleteObject(BMP);
        }
        DeleteDC(MDC);
      }
      DeleteObject(FNT); 
    }
    ReleaseDC(hWnd,DC);
  }
  Out.InvertY();
}
class QapClock
{
public:
  int64 freq,beg,tmp;
  bool run;
public:
  QapClock(){QueryPerformanceFrequency((LARGE_INTEGER*)&freq);run=false;tmp=0;Start();}
  void Start(){QueryPerformanceCounter((LARGE_INTEGER*)&beg);run=true;}
  void Stop(){QueryPerformanceCounter((LARGE_INTEGER*)&tmp);run=false;tmp-=beg;}
  double Time(){if(run)QueryPerformanceCounter((LARGE_INTEGER*)&tmp);return run?double(tmp-beg)/double(freq):double(tmp)/double(freq);}
  double MS()
  {
    double d1000=1000.0;
    if(run)QueryPerformanceCounter((LARGE_INTEGER*)&tmp);
    if(run)return (double(tmp-beg)*d1000)/double(freq);
    if(!run)return (double(tmp)*d1000)/double(freq);
    return 0;
  }
};
class TD3DGameBoxBuilder;
class TD3DGameBoxBuilder
{
public:
public:
  typedef TD3DGameBoxBuilder SelfClass;
public:
  TD3DGameBox win;
  QapD3D9 D9;
  QapD3DDev9 D9Dev;
  QapDev qDev;
  int SleepMs;
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->win);
    detail::FieldTryDoReset(this->D9);
    detail::FieldTryDoReset(this->D9Dev);
    detail::FieldTryDoReset(this->qDev);
    (this->SleepMs)=(16);
  }
public:
  TD3DGameBoxBuilder(const TD3DGameBoxBuilder&)
  {
    QapDebugMsg("TD3DGameBoxBuilder"" is noncopyable");
    DoReset();
  };
  TD3DGameBoxBuilder()
  {
    DoReset();
  };
public:
  TD3DGameBoxBuilder(TD3DGameBoxBuilder&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(TD3DGameBoxBuilder&&_Right)
  {
    if(&_Right==this)return;
    {
    }
    this->win=std::move(_Right.win);
    this->D9=std::move(_Right.D9);
    this->D9Dev=std::move(_Right.D9Dev);
    this->qDev=std::move(_Right.qDev);
    this->SleepMs=std::move(_Right.SleepMs);
  }
public:
public:
  void DoNice()
  {
    auto&builder=*this;
    builder.init("2014.06.24");
    builder.win.Init();
    builder.init_d3d();
    builder.win.WindowMode();
    UpdateWindow(builder.win.Form.WinPair.hWnd);
    builder.loop();
  }
public:
  void SceneUpdate()
  {
    SceneUpdateEx();
    SceneRenderEx();
  }
public:
  void SceneUpdateEx()
  {
    SceneDoMove();
  }
  void SceneRenderEx()
  {
    auto&Dev=D9Dev;
    vec2i ClientSize=win.GetClientSize();
    if(!Dev.BeginScene())return;
    {
      D3DVIEWPORT9 ViewPort={0,0,ClientSize.x,ClientSize.y,0.0,1.0};
      Dev.pDev->SetViewport(&ViewPort);
      Dev.Set2D(vec2i(0,0),1.0,0,&ClientSize);
      Dev.Clear2D(0xffc8c8c8);
      qDev.NextFrame();
      SceneDoDraw();
    }
    if(!Dev.EndScene())return;
    RECT Rect={0,0,ClientSize.x,ClientSize.y};
    Dev.Present(&Rect,&Rect);
  }
public:
  virtual void DoMove() {};
  virtual void DoDraw() {};
public:
  void SceneDoMove()
  {
    auto&Dev=D9Dev;
    if(!qDev.DynRes.pDev)
    {
      qDev.MountDev(Dev);
      qDev.Init(1024*1024*16,1024*1024*16*3);
    }
    DoMove();
  }
  void SceneDoDraw()
  {
    DoDraw();
  }
public:
  void init_d3d()
  {
    HWND hwnd=win.Form.WinPair.hWnd;
    D9.Init();
    D9Dev.PresParams.SetToDef(hwnd,true);
    D9Dev.Init(hwnd,D9);
  }
  void init(const string&caption)
  {
    win.Caption=caption;
    win.Init();
    win.Visible=false;
    win.WindowMode();
    init_d3d();
    win.Visible=true;
    win.WindowMode();
    UpdateWindow(win.Form.WinPair.hWnd);
  }
  void loop()
  {
    for (int i=0;win.Runned;i++)
    {
      win.Update();
      SceneUpdate();
      Sleep(SleepMs);
      if(win.NeedClose)win.Runned=false;
    }
  }
public:
  #include "qap_text.inl"
};

template<class TYPE>
void QapPopFront(vector<TYPE>&arr)
{
  int last=0;
  for(int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(last!=i)
    {
      auto&ax=arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==arr.size())return;
  arr.resize(last);
}
template<class TYPE,class FUNC>
static vector<int> qap_find(vector<TYPE>&arr,FUNC&func){
  vector<int> out;
  for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(func(ex))out.push_back(i);}
  return out;
}
template<class TYPE>
static vector<int> qap_find_val(const vector<TYPE>&arr,const TYPE&val){
  vector<int> out;
  for(int i=0;i<arr.size();i++){if(val==arr[i])out.push_back(i);}
  return out;
}
static vector<int> qap_find_str(const vector<string>&arr,const string&value){
  vector<int> out;
  for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(ex==value)out.push_back(i);}
  return out;
}
template<class TYPE>
static bool qap_add_unique_val(vector<TYPE>&arr,const TYPE&value){
  if(qap_includes(arr,value))return false;
  arr.push_back(value);
  return true;
}
inline string FToS(const real&val){char c[64];if(fabs(val)>1e9){_snprintf_s(c,32,32,"%e",val);}else{sprintf_s(c,"%.2f",val);}return string(c);}
inline string CToS(const char&val){string tmp="";tmp.push_back(val);return tmp;};
template<class TYPE,class FUNC>
void QapCleanIf(vector<TYPE>&Arr,FUNC&Pred)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(Pred(ex))continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>static void qap_drop_by_id(vector<TYPE>&arr,int id){
  auto*ptr=qap_check_id(arr,id)?&arr[id]:nullptr;QapCleanIf(arr,[ptr](TYPE&ex){return &ex==ptr;});
}
template<class TYPE>
void qap_clean_if_deaded(vector<TYPE>&arr)
{
  int last=0;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(ex.deaded)continue;
    if(last!=i)
    {
      auto&ax=arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==arr.size())return;
  arr.resize(last);
}
template<class TYPE>static bool qap_check_id(const vector<TYPE>&arr,int id){return id>=0&&id<arr.size();}
//-------------------------------------------//
inline string file_get_contents(const string&fn){CrutchIO IO;IO.LoadFile(fn);return IO.mem;}
inline void file_put_contents(const string&fn,const string&data){CrutchIO IO;IO.mem=data;IO.SaveFile(fn);}
//-------------------------------------------//
#undef SAY
//-------------------------------------------//
static string conv_tm_to_str(const std::tm&t)
{
  auto*ptm=&t;
  char buff[128];
  sprintf(&buff[0],"%04u.%02u.%02u %02u:%02u:%02u\0",
    1900+ptm->tm_year,
    ptm->tm_mon+1,
    ptm->tm_mday,
    ptm->tm_hour,ptm->tm_min,ptm->tm_sec
  );
  return buff;
}
static string cur_date_str()
{
  time_t rawtime;
  time(&rawtime);
  auto tm=*gmtime(&rawtime);
  return conv_tm_to_str(tm);
}
std::tm conv_systime_to_tm(const SYSTEMTIME&st)
{
	std::tm tm;
	tm.tm_sec=st.wSecond;
	tm.tm_min=st.wMinute;
	tm.tm_hour=st.wHour;
	tm.tm_mday=st.wDay;
	tm.tm_mon=st.wMonth-1;
	tm.tm_year=st.wYear-1900;
	tm.tm_isdst=-1;
	return tm;
}
SYSTEMTIME conv_filetime_to_systime(const FILETIME&ft)
{
  SYSTEMTIME st;
  QapAssert(FileTimeToSystemTime(&ft,&st));
  return st;
}
string conv_filetime_to_str(const FILETIME&ft)
{
  return conv_tm_to_str(conv_systime_to_tm(conv_filetime_to_systime(ft)));
}
string get_file_last_write_time(const string&fn)
{
  auto hFile=CreateFile(fn.c_str(),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
  if(hFile==INVALID_HANDLE_VALUE){QapNoWay();return "XXXX.XX.XX XX:XX;XX";}
  FILETIME CreationTime;
  FILETIME LastAccessTime;
  FILETIME LastWriteTime;
  bool ok=GetFileTime(hFile,&CreationTime,&LastAccessTime,&LastWriteTime);
  if(!ok){QapNoWay();return "XXXX.XX.XX XX:XX;XX";}
  CloseHandle(hFile);
  return conv_filetime_to_str(LastWriteTime);
}
void DrawLine(QapDev&qDev,const vec2d&a,const vec2d&b,real line_size)
{
  qDev.DrawQuad((b+a)*0.5,(b-a).Mag(),line_size,(b-a).GetAng());
}
template<class TYPE>TYPE sqr(TYPE x){return x*x;}

class TQapGame:public TD3DGameBoxBuilder{public:QapKeyboard&kb;vec2i&mpos;TQapGame():kb(win.Keyboard),mpos(win.mpos){DoReset();}};

struct t_offcentric_scope{
  QapDev&qDev;
  const vec2d&unit_pos;
  const vec2d&unit_dir;
  const real scale;
  t_offcentric_scope(QapDev&qDev,const vec2d&unit_pos,const vec2d&unit_dir,real scale,bool unit_offcentric):
    qDev(qDev),unit_pos(unit_pos),unit_dir(unit_dir),scale(scale)
  {
    qDev.xf=make_xf(qDev.viewport,unit_pos,unit_dir,scale,unit_offcentric);
    QapAssert(!qDev.use_xf2);
    qDev.use_xf2=true;
  }
  static real get_koef(){return 0.25;}
  static transform2f make_xf(const t_quad&viewport,const vec2d&unit_pos,const vec2d&unit_dir,real scale,bool unit_offcentric)
  {
    static const real offcentric_koef=get_koef();
    vec2d offcentric=vec2d(0,viewport.size.y*offcentric_koef);
    auto base_offset=unit_pos;//+qDev.viewport.pos;
    transform2f xf;
    xf.r.set(unit_dir.GetAng());
    xf.r.mul(scale);
    xf.p.set_zero();
    xf.p=(xf*-base_offset)+vec2f(-(unit_offcentric?offcentric:vec2d_zero));
    return xf;
  }
  static vec2d screen_to_world(const t_quad&viewport,const vec2d&s2wpos,const vec2d&cam_pos,const vec2d&cam_dir,real scale,bool offcentric)
  {
    auto off_offset=offcentric?vec2d(0,viewport.size.y*t_offcentric_scope::get_koef()):vec2d(0,0);
    return cam_pos+(s2wpos+off_offset).Rot(cam_dir)*(1.0/scale);
  };
 ~t_offcentric_scope()
  {
    qDev.use_xf2=false;
    qDev.xf.set_ident();
  }
};

template<class MONSTER,class UNIT>
static const UNIT*get_near_unit(const MONSTER&a,const vector<UNIT>&arr)
{
  auto p=a.pos;int id=-1;real d=-1;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    if(ex.deaded)continue;
    auto m=(ex.pos-p).SqrMag();
    if(id>=0&&m>=d)continue;
    d=m;id=i;
  }
  return id<0?nullptr:&arr[id];
}
inline real SToF(const string&S){real r;sscanf_s(S.c_str(),"%lf",&r);return r;};
inline int SToI(const string&S){int i;sscanf_s(S.c_str(),"%i",&i);return i;};
inline string IToH(const int&val){char d[255]; sprintf_s(d,sizeof(d),"0x%08X",val); return string(d);}
inline string IToH(const int&val,int n){char d[255]; n=n<0?8:n>8?8:n; string c=IToS(n); sprintf_s(d,sizeof(d),("0x%0"+c+"X").c_str(),val); return string(d);}
inline string IToH_raw(const int&val){char d[255]; sprintf_s(d,sizeof(d),"%08X",val); return string(d);}
inline string CToH_raw(const unsigned char&val){char d[3]; sprintf_s(d,sizeof(d),"%02X",val); return string(d);}
inline int HToI_raw(const string&str){int val;sscanf_s(str.c_str(),"%08X",&val); return val;}
static inline bool IsLegalChar(const uchar&c)
{
  #define F(A,B)bool(uchar(A)<=c&&uchar(B)>=c)
  return F('a','z')||F('A','Z')||F('0','9');
  #undef F
}
inline string StrReplace(const string&input,const string&sub,const string&now)
{
  return join(split(input,sub),now);
}
static string gen_dip(char from,char to){
  QapAssert(from<to);
  string out;
  out.reserve(to-from);
  bool flag=from!=to;
  for(auto c=from;flag;c++){
    flag=flag&&(c!=to);
    out.push_back(c);
  }
  return out;
}
//-------------------------------------------//
static string gen_dips(const string&rule){
  QapAssert(!(rule.size()%2));
  string out;
  for(int i=0;i<rule.size();i+=2){
    out+=gen_dip(rule[i+0],rule[i+1]);
  }
  return out;
}
//-------------------------------------------//
static string dip_inv(const string&dip){
  string out;
  char min=std::numeric_limits<char>::min();
  char max=std::numeric_limits<char>::max();
  bool flag=min!=max;
  for(auto c=min;flag;c++){
    flag=flag&&(c!=max);
    auto e=dip.find(CToS(c));
    if(e!=std::string::npos)continue;
    out.push_back(c);
  }
  return out;
}

template<class TYPE>void reverse(vector<TYPE>&loop){auto c=loop.size();for(int i=0;i<c/2;i++)std::swap(loop[c-1-i],loop[i]);}

static bool rewind(vector<vec2d>&arr,int point_id){
  if(!qap_check_id(arr,point_id))return false;
  vector<vec2d> out;for(int i=0;i<arr.size();i++)qap_add_back(out)=arr[(i+point_id)%arr.size()];arr=out;
  return true;
}

template<class TYPE>
void operator+=(vector<TYPE>&arr,vector<TYPE>&&ref)
{
  //arr.reserve(arr.size()+ref.size());
  for(int i=0;i<ref.size();i++)
  {
    arr.push_back(std::move(ref[i]));
  }
  ref.clear();
}
template<class TYPE>void qap_sort(vector<TYPE>&arr){std::sort(arr.begin(),arr.end());}
template<class TYPE>void qap_subarr(vector<TYPE>&arr,int offset){
  if(offset<0)offset+=arr.size();
  if(!offset||!qap_check_id(arr,offset))return;
  int p=0;
  for(int i=offset;i<arr.size();i++)arr[p++]=std::move(arr[i]);
  arr.resize(arr.size()-offset);
}

template<int BLOCK_LENGTH=1024*1024>
class FsIO:public QapIO{
public:
  fstream f;
  string block;
  int bpos;
  int pos;
  int n;
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
  FsIO(const string&FN){
    using namespace std;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f){n=0;pos=0;bpos=0;return;}
    n=FileLength(f);
    pos=0;bpos=0;
    read_block();
  }
  void read_block(){
    int v=std::min(BLOCK_LENGTH,n-bpos);
    block.resize(v);
    f.read(&block[0],block.size());
    bpos+=block.size();
  }
public:
  virtual void SavePOD(void*p,int count){QapNoWay();}
  virtual void LoadPOD(void*ptr,int c)
  {
    auto*p=(char*)ptr;auto count=c;
    QapAssert(count>=1);
    QapAssert(pos+count<=n);
    for(;;)
    {
      if(pos+count<=bpos){
        auto addr=pos-(bpos-block.size());
        QapAssert(addr>=0&&addr<block.size());
        memcpy(p,&block[addr],count);
        pos+=count;
        return;
      }else{
        auto addr=pos-(bpos-block.size());
        auto bef_n=bpos-pos;
        QapAssert(bef_n<=block.size()-addr);
        if(block.size()!=addr&&bef_n!=0)
        {
          QapAssert(addr>=0&&addr<block.size());
          memcpy(p,&block[addr],bef_n);
        }
        read_block();
        p+=bef_n;
        count-=bef_n;
        pos+=bef_n;
      }
    }
    int gg=1;
  }
  virtual bool TryLoad(int count){return pos+count<=n;}
  virtual void Crash(){QapNoWay();}
  virtual bool IsCrashed(){return n<=0;}
  virtual bool IsSizeIO(){return false;}
  virtual int GetSize(){return n;}
  virtual void WriteTo(QapIO&ref){QapNoWay();}
};

class FsWrite:public QapIO{
public:
  fstream f;
  int pos;
  int n;
  FsWrite(const string&FN){
    using namespace std;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)QapNoWay();
    pos=0;//bpos=0;
  }
public:
  virtual void SavePOD(void*p,int count){
    f.write((char*)p,count);
    pos+=count;
  }
  virtual void LoadPOD(void*ptr,int c){QapNoWay();}
  virtual bool TryLoad(int count){QapNoWay();return false;}
  virtual void Crash(){QapNoWay();}
  virtual bool IsCrashed(){return false;}
  virtual bool IsSizeIO(){return false;}
  virtual int GetSize(){QapNoWay();return n;}
  virtual void WriteTo(QapIO&ref){QapNoWay();}
};

template<class TYPE>
struct t_looped_buffer_v2{
  vector<TYPE> frames;
  size_t n;
  size_t ptr;
public:
  t_looped_buffer_v2(){n=8;ptr=0;}
  void add(TYPE&&value)
  {
    QapAssert(n>0);
    if(frames.size()!=n)frames.resize(n);
    frames[ptr%n]=std::move(value);
    ptr++;
  }
  TYPE&operator[](size_t id){return frames[id%n];}
  void init(const TYPE&value){frames.resize(n,value);}
  void clear(){frames.clear();ptr=0;}
};

template<class TYPE>
struct t_looped_buffer{
  vector<TYPE> frames;
  int n;
  int ptr;
public:
  t_looped_buffer(){n=8;ptr=0;}
  void add(const TYPE&value)
  {
    QapAssert(n>0);
    if(frames.size()!=n)frames.resize(n);
    ptr=ptr%n;
    frames[ptr]=value;
    ptr++;
    ptr=ptr%n;
  }
  void init(const TYPE&value){frames.resize(n,value);}
  TYPE get_average()const{
    TYPE sum=0;for(int i=0;i<frames.size();i++){sum+=frames[i];}
    return frames.empty()?0:sum*(1.0/frames.size());
  }
};
#include "vector_view.inl"

static const auto VK_BACKSLASH=VK_OEM_5; // "\|"
static const auto VK_SLASH=VK_OEM_2;     // "/?"
//-------------------------------------------//
//   {<|          28.08.2017           |>}   //
//-------------------------------------------//
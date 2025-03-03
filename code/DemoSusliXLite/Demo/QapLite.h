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
#include <windows.h>
#include <d3d9.h>
#pragma comment(lib,"d3d9")
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <array>
#include <time.h>
#include <math.h>
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
#ifdef _DEBUG
#define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCTION__))_CrtDbgBreak();}
#else
#define QapAssert(_Expression)if(bool(_Expression)){};
#endif
#ifdef _DEBUG
#define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCTION__))_CrtDbgBreak();}
#else
#define QapDebugMsg(_Message)
#endif
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
inline int WinMessageBox(const string&caption,const string&text)
{
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  QapMsgBoxRetval retval=qmbrSkip;
  if(IDCONTINUE==nCode)retval=qmbrIgnore;
  if(IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
}
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
/*TMemory - дискриптор выделеной памяти*/
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
const real PiD2=1.0*atan(1.0);
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
template<class TYPE>static TYPE&vec_add_back(vector<TYPE>&arr){arr.push_back(TYPE());return arr.back();}
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
    return vec2d(x/this->Mag(),y/this->Mag());
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
public:
  friend inline static real dot(const vec2d&a,const vec2d&b)
  {
    return a.x*b.x+a.y*b.y;
  }
  friend inline static real cross(const vec2d&a,const vec2d&b)
  {
    return a.x*b.y-a.y*b.x;
  }
public:
};
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
  byte GetLuminance()
  {
    return int(int(r)+int(g)+int(b))/int(3);
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
  QapColor GetColor()
  {
    return QapColor(Clamp(int(a),int(0),int(255)),Clamp(int(r),int(0),int(255)),Clamp(int(g),int(0),int(255)),Clamp(int(b),int(0),int(255)));
  }
};
struct vec3f
{
public:
  float x,y,z;
  vec3f():x(0),y(0),z(0) {}
  vec3f(float x,float y,float z):x(x),y(y),z(z) {}
};
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
};
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
  QapMat4() {}
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
    pp.SwapEffect=D3DSWAPEFFECT_COPY;
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
public:
  void DoReset()
  {
    {
    }
    (this->PresParams)=(QapD3DPresentParameters());
    (this->pDev)=(nullptr);
    (this->Resources)=(QapD3D9ResourceList());
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
    pDev->SetRenderState(D3DRS_ZENABLE,false);
    pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
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
    ResetStates();
    return true;
  }
  bool EndScene()
  {
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
      pDev->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, 0 );
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
    OrthoLH(matProj,float(v.x),float(v.y),-1.0,1.0);
    pDev->SetTransform(D3DTS_PROJECTION,&matProj);
    pDev->SetTransform(D3DTS_VIEW,&matView);
    pDev->SetTransform(D3DTS_WORLD,&matWorld);
  }
  void Clear2D(const QapColor&Color)
  {
    pDev->Clear(0,NULL,D3DCLEAR_TARGET,Color,1.0f,0);
  }
};
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
public:
  typedef QapD3DDev9::BlendType BlendType;
  typedef QapD3DDev9::AlphaType AlphaType;
public:
public:
  typedef QapDev SelfClass;
public:
  TDynamicResource DynRes;
  IDirect3DDevice9* pDev;
  IDirect3DVertexBuffer9* VB;
  IDirect3DIndexBuffer9* IB;
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
  void ReInit()
  {
    Init(MaxVPos,MaxIPos);
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
  void QapDev::BeginBatch()
  {
    Batching=true;
    VBA=0;
    IBA=0;
    VPos=0;
    IPos=0;
    if(!IB||!VB)return;
    IB->Lock(0,sizeof(int)*MaxIPos,(void **)&IBA,0);
    VB->Lock(0,sizeof(Ver)*MaxVPos,(void **)&VBA,0);
  };
  void EndBatch()
  {
    Batching=false;
    if(!IB||!VB)return;
    IB->Unlock();
    VB->Unlock();
    if(VPos&&IPos)
    {
      DIP();
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
  void NextFrame()
  {
    DIPs=0;
    Verts=0;
    Tris=0;
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
    {
      vec2f&v=Dest.get_pos();
      v=xf*v;
    }
    if(Textured)
    {
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
public:
  inline void SetColor(const QapColor&C)
  {
    color=C;
  }
  inline void SetTransform(transform2f const&val)
  {
    xf=val;
  }
  inline transform2f GetTransform()
  {
    return xf;
  }
  inline void SetTextureTransform(transform2f const&val)
  {
    txf=val;
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
  void DrawQuad(float x,float y,float w,float h)
  {
    BatchScope Scope(*this);
    {
      vec2d O(x,y);
      int n=VPos;
      {
        AddVertex(x+(-0.5f)*w,y+(-0.5f)*h,color,0.0f,1.0f);
      };
      {
        AddVertex(x+(+0.5f)*w,y+(-0.5f)*h,color,1.0f,1.0f);
      };
      {
        AddVertex(x+(+0.5f)*w,y+(+0.5f)*h,color,1.0f,0.0f);
      };
      {
        AddVertex(x+(-0.5f)*w,y+(+0.5f)*h,color,0.0f,0.0f);
      };
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
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
    QapDebugMsg("[2014.05.22]: way used?");
    if(VA.empty())return;
    BatchScope Scope(*this);
    {
      int base=GetVPos();
      static IntArray VID;
      VID.resize(VA.size());
      for (int i=0;i<VA.size();i++)VID[i]=AddVertex(MakeVer(VA[i],color,p.x,p.y));
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
      AddTris(a,b,d);
      AddTris(d,c,a);
    }
  }
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
        out.r=(out.r*b+inp.r*a)/255;
        out.g=(out.g*b+inp.g*a)/255;
        out.b=(out.b*b+inp.b*a)/255;
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
      int fr=abs(int(p.r)-int(c.r));
      int fg=abs(int(p.g)-int(c.g));
      int fb=abs(int(p.b)-int(c.b));
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
  }
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
  TDynamicResource DynRes;
  IDirect3DTexture9* Tex;
public:
  void DoReset()
  {
    {
    }
    (this->W)=(0);
    (this->H)=(0);
    (this->DynRes)=(this);
    (this->Tex)=(nullptr);
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
  void ReInit() {}
  void MountDev(QapD3DDev9&Dev)
  {
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int W,int H,int Levels)
  {
    Free();
    auto*Sys=DynRes.pDev;
    Sys->pDev->CreateTexture(W,H,Levels,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&Tex,NULL);
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
class QapKeyboard
{
public:
  struct TKeyState
  {
    static const int MAX_KEY=263;
    bool data[MAX_KEY];
    TKeyState()
    {
      SetToDef();
    }
    void SetToDef()
    {
      for (int i=0;i<MAX_KEY;i++)data[i]=false;
    }
    bool&operator[](int index)
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    const bool&operator[](int index)const
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
  };
public:
public:
  typedef QapKeyboard SelfClass;
public:
  int LastKey;
  char LastChar;
  bool News;
  TKeyState Down;
  TKeyState Changed;
public:
  void DoReset()
  {
    {
    }
    (this->LastKey)=(0);
    (this->LastChar)=(0);
    (this->News)=(false);
    detail::FieldTryDoReset(this->Down);
    detail::FieldTryDoReset(this->Changed);
  }
public:
  QapKeyboard(const QapKeyboard&)
  {
    QapDebugMsg("QapKeyboard"" is noncopyable");
    DoReset();
  };
  QapKeyboard()
  {
    DoReset();
  };
public:
public:
  QapKeyboard&QapKeyboard::operator=(const QapKeyboard&)
  {
    QapAssert(0);
  }
  void KeyUpdate(int Key,bool Value)
  {
    if(Value)LastKey=Key;
    Down[Key]=Value;
    Changed[Key]=true;
  }
  void CharUpdate(char c)
  {
    LastChar=c;
    News=true;
  }
  void Sync()
  {
    this->News=false;
    Changed.SetToDef();
  }
  bool OnDown(int index)const
  {
    return Changed[index]&&Down[index];
  }
};
enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};
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
  void Update()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    zDelta=0;
    Keyboard.Sync();
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
    if(msg==WM_SYSKEYDOWN)
    {
      if(wParam==VK_F10)
      {
        Keyboard.KeyUpdate(VK_F10,true);
      };
      if(wParam==VK_MENU)
      {
        Keyboard.KeyUpdate(VK_MENU,true);
      };
    }
    if(msg==WM_SYSKEYUP)
    {
      if(wParam==VK_F10)
      {
        Keyboard.KeyUpdate(VK_F10,false);
      };
      if(wParam==VK_MENU)
      {
        Keyboard.KeyUpdate(VK_MENU,false);
      };
      if(wParam==VK_RETURN)
      {
        Keyboard.KeyUpdate(VK_RETURN,false);
      };
    }
    bool key_flags[]={msg==WM_KEYUP,msg==WM_KEYDOWN};
    if(key_flags[0]||key_flags[1])
    {
      bool value=key_flags[1];
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
    if(msg==WM_KEYDOWN)
    {
      Keyboard.KeyUpdate(wParam,true);
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
    if(msg==WM_KEYUP)
    {
      Keyboard.KeyUpdate(wParam,false);
    }
    if(msg==WM_KEYDOWN)
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
    if(msg==WM_CHAR)
    {
      Keyboard.CharUpdate(wParam);
    }
  }
  LRESULT WndProc(const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam)
  {
    KeyboardUpdate(Keyboard,hWnd,msg,wParam,lParam);
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
};
//class TD3DGameBoxBuilder;
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
      D3DVIEWPORT9 ViewPort={0,0,DWORD(ClientSize.x),DWORD(ClientSize.y),-1.f,+1.f};
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
      qDev.Init(1024*1024,1024*1024*3);
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
};
//-------------------------------------------//
//   {<|          28.09.2014           |>}   //
//-------------------------------------------//
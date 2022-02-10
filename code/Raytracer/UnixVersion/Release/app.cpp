#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <cstring>
#include <csignal>
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
struct t_gcc_nullptr_t{};
#define nullptr_t t_gcc_nullptr_t
#define nullptr 0
#ifndef PREPROC
  #if(defined(_DEBUG)||defined(QAP_DEBUG))
    #ifdef WIN32
    #else
      #define __FUNCSIG__ __PRETTY_FUNCTION__
    #endif //WIN32
    #ifdef WIN32
      #define QapDbgBreak(){struct t_open_mp_workaround{static void crash(){__builtin_trap();}};t_open_mp_workaround::crash();/*_CrtDbgBreak();*/}
    #else
      #define QapDbgBreak()printf("__builtin_trap();");
    #endif
    #define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}  
    #define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}
    #define QapNoWay(){QapDebugMsg("no way!");}
  #else
    #define QapAssert(_Expression)if(bool(_Expression)){};
    #define QapDebugMsg(_Message)
    #define QapNoWay()
  #endif
#endif //PREPROC//
#include "lodepng.cpp"
using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::iostream;
using std::stringstream;
using std::array;
typedef double real;
typedef long long int int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned char uchar;
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
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
  TScreenMode Res={1920,1200,32,60};
  return Res;
}
inline string FToS(const real&val){char c[64];if(abs(val)>1e9){snprintf(c,lenof(c),"%e",val);}else{snprintf(c,lenof(c),"%.2f",val);}return string(c);}
static inline string IToS(const int&val)
{
  if(!val)return "0";char c[16]={0};int p=0;int v=val;int n=10;if(val<0){v*=-1;}
  for(;v;){c[p++]='0'+v%n;v/=n;}if(val<0)c[p++]='-';
  string s;s.resize(p);for(int i=0;i<p;i++)s[i]=c[(p-1)-i];
  return s;
}
enum QapMsgBoxRetval
{
  qmbrSkip,qmbrBreak,qmbrIgnore
};
inline int WinMessageBox(const string&caption,const string&text)
{
  printf("WinMessageBox(%s):\n%s\n\n",caption.c_str(),(text+"\n\n    [Skip]            [Break]            [Ignore]\n").c_str());
  fflush(stdout);
  QapDbgBreak();
  return 0;
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
  static void set(int&a,const t_$&){a=0;}static void set(unsigned&a,const t_$&){a=0;}static void set(char&a,const t_$&){a=0;}static void set(uchar&a,const t_$&){a=0;}static void set(real&a,const t_$&){a=0;}static void set(float&a,const t_$&){a=0;}static void set(bool&a,const t_$&){a=0;}
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
void clean_if(vector<TYPE>&Arr,FUNC&&Pred)
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
template<class TYPE,class FUNC>
void clean_if(vector<TYPE>&Arr,const FUNC&Pred)
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
  static vec2d min(const vec2d&a,const vec2d&b)
  {
    return vec2d(std::min(a.x,b.x),std::min(a.y,b.y));
  }
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
  QapColor(const unsigned int&v){*(unsigned int*)this=v;}
  void operator=(const unsigned int&v){*(unsigned int*)this=v;}
public:
  friend bool operator==(const QapColor&u,const QapColor&v)
  {
      return (u.b==v.b)&&(u.g==v.g)&&(u.r==v.r)&&(u.a==v.a)&&true;
  }
  friend bool operator!=(const QapColor&u,const QapColor&v)
  {
      return (u.b!=v.b)||(u.g!=v.g)||(u.r!=v.r)||(u.a!=v.a)||false;
  }
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
  void operator=(const SelfClass&v){x=v.x;y=v.y;z=v.z;}void operator+=(const SelfClass&v){x+=v.x;y+=v.y;z+=v.z;}void operator-=(const SelfClass&v){x-=v.x;y-=v.y;z-=v.z;}
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
struct D3DVECTOR{float x,y,z;};
class vec3f{
public:
  float x,y,z;
  vec3f(const D3DVECTOR&v):x(v.x),y(v.y),z(v.z){}
  operator D3DVECTOR&(){return *(D3DVECTOR*)(void*)this;}
  vec3f(){x=0;y=0;z=0;}
  vec3f(float x,float y,float z)
  {
    this->x=x;;this->y=y;;this->z=z;;
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
struct D3DMATRIX{float m[4][4];};
struct QapMat4{
public:
  float m[4][4];
  QapMat4(const D3DMATRIX&v){for(int y=0;y<4;y++)for(int x=0;x<4;x++)m[y][x]=v.m[y][x];}
  operator D3DMATRIX&(){return *(D3DMATRIX*)(void*)this;}
public:
  QapMat4(){
    *this=QapMat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    );
  }
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
template<class TYPE>
static const string qap_def_pro_diff(const TYPE&a,const TYPE&b){
  QapNoWay();
  return "unsupported";
}
class CrutchIO{
public:
  static bool FileExist(const string&FN)
  {
    std::fstream f;
    f.open(FN.c_str(),std::ios::in|std::ios::binary);
    return f.is_open();
  }
private:
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
public:
  int pos;
  string mem;
  CrutchIO():mem(""),pos(0){};
  bool LoadFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f)return false;
    int L=FileLength(f);
    mem.resize(L);
    if(L)f.read(&mem[0],L);
    f.close(); pos=0;
    return true;
  };
  bool SaveFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)return false;
    if(!mem.empty())f.write(&mem[0],mem.size());
    f.close(); pos=0; int L=mem.size();
    return true;
  };
  void read(char*c,int count)
  {
    for(int i=0;i<count;i++)c[i]=mem[pos++];
  };
  void write(char*c,int count)
  {
    int n=mem.size();
    mem.resize(n+count);
    for(int i=0;i<count;i++)mem[n+i]=c[i];
    pos+=count;
  };
};
class QapIO{
public:
  QapIO(){}
public:
  virtual void SavePOD(void*p,int count)=0;
  virtual void LoadPOD(void*p,int count)=0;
  virtual bool TryLoad(int count)=0;
  virtual void Crash()=0;
  virtual bool IsCrashed()=0;
  virtual bool IsSizeIO()=0;
  virtual int GetSize()=0;
  virtual void WriteTo(QapIO&ref)=0;
public:
  void load(int&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(unsigned int&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(char&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(unsigned char&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(bool&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(int64&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(uint64&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(float&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(real&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(short&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(unsigned short&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(vec2i&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(vec2d&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}void load(vec2f&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}
  void save(int&ref){SavePOD(&ref,sizeof(ref));}void save(unsigned int&ref){SavePOD(&ref,sizeof(ref));}void save(char&ref){SavePOD(&ref,sizeof(ref));}void save(unsigned char&ref){SavePOD(&ref,sizeof(ref));}void save(bool&ref){SavePOD(&ref,sizeof(ref));}void save(int64&ref){SavePOD(&ref,sizeof(ref));}void save(uint64&ref){SavePOD(&ref,sizeof(ref));}void save(float&ref){SavePOD(&ref,sizeof(ref));}void save(real&ref){SavePOD(&ref,sizeof(ref));}void save(short&ref){SavePOD(&ref,sizeof(ref));}void save(unsigned short&ref){SavePOD(&ref,sizeof(ref));}void save(vec2i&ref){SavePOD(&ref,sizeof(ref));}void save(vec2d&ref){SavePOD(&ref,sizeof(ref));}void save(vec2f&ref){SavePOD(&ref,sizeof(ref));}
  void load(std::string&ref)
  {
    int size=0;
    load(size);
    if(size<0){Crash();return;}
    if(!size){ref.clear();return;}
    if(!TryLoad(size)){Crash();return;}
    ref.resize(size);
    LoadPOD(&ref[0],size);
  }
  void save(std::string&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    SavePOD(&ref[0],size);
  }
  template<class TYPE>
  void load(std::vector<TYPE>&ref)
  {
    int size=0;
    load(size);
    if(size<0){Crash();return;}
    ref.resize(size);
    for(int i=0;i<size;i++){
      load(ref[i]);
    }
  }
  template<class TYPE>
  void load_as_pod(std::vector<TYPE>&ref)
  {
    int size=0;
    load(size);
    if(size<0){Crash();return;}
    ref.resize(size);
    for(int i=0;i<size;i++){
      LoadPOD(&ref[i],sizeof(TYPE));
    }
  }
  template<class TYPE>
  void save(std::vector<TYPE>&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      save(ref[i]);
    }
  }
  template<class TYPE>
  void save_as_pod(std::vector<TYPE>&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      SavePOD(&ref[i],sizeof(TYPE));
    }
  }
  void write_raw_string(string&s){if(s.empty())return;SavePOD((void*)&s[0],s.size());}
};
class TDataIO:public QapIO{
public:
  CrutchIO IO;
  bool crashed;
  TDataIO():crashed(false),QapIO(){}
public:
  void SavePOD(void*p,int count)
  {
    this->IO.write((char*)p,count);
  }
  void LoadPOD(void*p,int count)
  {
    int max_count=int(this->IO.mem.size())-int(this->IO.pos);
    if(count>max_count)
    {
      QapAssert(count<=max_count);
      return;
    }
    this->IO.read((char*)p,count);
  }
  bool TryLoad(int count)
  {
    auto max_size=int(IO.mem.size())-int(IO.pos);
    return (count>=0)&&(max_size>=count);
  }
  void Crash()
  {
    IO.pos=IO.mem.size();
    crashed=true;
  }
  bool IsCrashed()
  {
    return crashed;
  }
  bool IsSizeIO()
  {
    return false;
  }
  int GetSize()
  {
    return IO.mem.size();
  }
  void SaveTo(QapIO&Stream)
  {
    int size=IO.mem.size();
    Stream.SavePOD(&size,sizeof(size));
    if(!size)return;
    Stream.SavePOD(&IO.mem.front(),size);
  }
  void LoadFrom(QapIO&Stream)
  {
    int size;
    Stream.LoadPOD(&size,sizeof(size));
    if(!size)return;
    IO.mem.resize(size);
    Stream.LoadPOD(&IO.mem.front(),size);
  }
  void WriteTo(QapIO&ref)
  {
    ref.write_raw_string(IO.mem);
  }
};
class TSizeIO:public QapIO{
public:
  int size;
  bool crashed;
public:
  TSizeIO():size(0),crashed(false),QapIO(){}
  void SavePOD(void*p,int count){size+=count;}
  void LoadPOD(void*p,int count){QapNoWay();Crash();}
  bool TryLoad(int count){QapNoWay();Crash();return false;}
  void Crash(){crashed=true;}
  bool IsCrashed(){return crashed;}
  bool IsSizeIO(){return true;}
  int GetSize()
  {
    return size;
  }
  void WriteTo(QapIO&ref)
  {
    if(!ref.IsSizeIO()){QapNoWay();Crash();return;}
    ref.SavePOD(nullptr,size);
  }
};
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
    pos=0;
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
static const int VK_LBUTTON  =1;
static const int VK_RBUTTON  =2;
static const int VK_CANCEL =3;
static const int VK_MBUTTON  =4;
static const int VK_XBUTTON1 =5;
static const int VK_XBUTTON2 =6;
static const int VK_BACK =8;
static const int VK_TAB  =9;
static const int VK_CLEAR  =12;
static const int VK_RETURN =13;
static const int VK_SHIFT  =16;
static const int VK_CONTROL  =17;
static const int VK_MENU =18;
static const int VK_PAUSE  =19;
static const int VK_CAPITAL  =20;
static const int VK_KANA =0x15;
static const int VK_HANGEUL  =0x15;
static const int VK_HANGUL =0x15;
static const int VK_JUNJA  =0x17;
static const int VK_FINAL  =0x18;
static const int VK_HANJA  =0x19;
static const int VK_KANJI  =0x19;
static const int VK_ESCAPE =0x1B;
static const int VK_CONVERT  =0x1C;
static const int VK_NONCONVERT =0x1D;
static const int VK_ACCEPT =0x1E;
static const int VK_MODECHANGE =0x1F;
static const int VK_SPACE  =32;
static const int VK_PRIOR  =33;
static const int VK_NEXT =34;
static const int VK_END  =35;
static const int VK_HOME =36;
static const int VK_LEFT =37;
static const int VK_UP =38;
static const int VK_RIGHT  =39;
static const int VK_DOWN =40;
static const int VK_SELECT =41;
static const int VK_PRINT  =42;
static const int VK_EXECUTE  =43;
static const int VK_SNAPSHOT =44;
static const int VK_INSERT =45;
static const int VK_DELETE =46;
static const int VK_HELP =47;
static const int VK_LWIN =0x5B;
static const int VK_RWIN =0x5C;
static const int VK_APPS =0x5D;
static const int VK_SLEEP  =0x5F;
static const int VK_NUMPAD0  =0x60;
static const int VK_NUMPAD1  =0x61;
static const int VK_NUMPAD2  =0x62;
static const int VK_NUMPAD3  =0x63;
static const int VK_NUMPAD4  =0x64;
static const int VK_NUMPAD5  =0x65;
static const int VK_NUMPAD6  =0x66;
static const int VK_NUMPAD7  =0x67;
static const int VK_NUMPAD8  =0x68;
static const int VK_NUMPAD9  =0x69;
static const int VK_MULTIPLY =0x6A;
static const int VK_ADD  =0x6B;
static const int VK_SEPARATOR  =0x6C;
static const int VK_SUBTRACT =0x6D;
static const int VK_DECIMAL  =0x6E;
static const int VK_DIVIDE =0x6F;
static const int VK_F1 =0x70;
static const int VK_F2 =0x71;
static const int VK_F3 =0x72;
static const int VK_F4 =0x73;
static const int VK_F5 =0x74;
static const int VK_F6 =0x75;
static const int VK_F7 =0x76;
static const int VK_F8 =0x77;
static const int VK_F9 =0x78;
static const int VK_F10  =0x79;
static const int VK_F11  =0x7A;
static const int VK_F12  =0x7B;
static const int VK_F13  =0x7C;
static const int VK_F14  =0x7D;
static const int VK_F15  =0x7E;
static const int VK_F16  =0x7F;
static const int VK_F17  =0x80;
static const int VK_F18  =0x81;
static const int VK_F19  =0x82;
static const int VK_F20  =0x83;
static const int VK_F21  =0x84;
static const int VK_F22  =0x85;
static const int VK_F23  =0x86;
static const int VK_F24  =0x87;
static const int VK_NUMLOCK  =0x90;
static const int VK_SCROLL =0x91;
static const int VK_LSHIFT =0xA0;
static const int VK_RSHIFT =0xA1;
static const int VK_LCONTROL =0xA2;
static const int VK_RCONTROL =0xA3;
static const int VK_LMENU  =0xA4;
static const int VK_RMENU  =0xA5;
static const int VK_BROWSER_BACK =0xA6;
static const int VK_BROWSER_FORWARD  =0xA7;
static const int VK_BROWSER_REFRESH  =0xA8;
static const int VK_BROWSER_STOP =0xA9;
static const int VK_BROWSER_SEARCH =0xAA;
static const int VK_BROWSER_FAVORITES  =0xAB;
static const int VK_BROWSER_HOME =0xAC;
static const int VK_VOLUME_MUTE  =0xAD;
static const int VK_VOLUME_DOWN  =0xAE;
static const int VK_VOLUME_UP  =0xAF;
static const int VK_MEDIA_NEXT_TRACK =0xB0;
static const int VK_MEDIA_PREV_TRACK =0xB1;
static const int VK_MEDIA_STOP =0xB2;
static const int VK_MEDIA_PLAY_PAUSE =0xB3;
static const int VK_LAUNCH_MAIL  =0xB4;
static const int VK_LAUNCH_MEDIA_SELECT  =0xB5;
static const int VK_LAUNCH_APP1  =0xB6;
static const int VK_LAUNCH_APP2  =0xB7;
static const int VK_OEM_1  =0xBA;
static const int VK_OEM_PLUS =0xBB;
static const int VK_OEM_COMMA  =0xBC;
static const int VK_OEM_MINUS  =0xBD;
static const int VK_OEM_PERIOD =0xBE;
static const int VK_OEM_2  =0xBF;
static const int VK_OEM_3  =0xC0;
static const int VK_OEM_4  =0xDB;
static const int VK_OEM_5  =0xDC;
static const int VK_OEM_6  =0xDD;
static const int VK_OEM_7  =0xDE;
static const int VK_OEM_8  =0xDF;
static const int VK_OEM_102  =0xE2;
static const int VK_PROCESSKEY =0xE5;
static const int VK_PACKET =0xE7;
static const int VK_ATTN =0xF6;
static const int VK_CRSEL  =0xF7;
static const int VK_EXSEL  =0xF8;
static const int VK_EREOF  =0xF9;
static const int VK_PLAY =0xFA;
static const int VK_ZOOM =0xFB;
static const int VK_NONAME =0xFC;
static const int VK_PA1  =0xFD;
static const int VK_OEM_CLEAR  =0xFE;
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
    bool&operator()(int index)
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    const bool&operator()(int index)const
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
    typedef TKeyState SelfClass;
    bool oper_eq(const SelfClass&ref)const{
      for(int i=0;i<lenof(data);i++)if(data[i]!=ref.data[i])return false;
      return true;
    }
    bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);}
    bool operator==(const SelfClass&ref)const{return oper_eq(ref);}
    bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
  };
public:
int LastKey; char LastChar; bool News; TKeyState Down; TKeyState Changed; void DoReset(){t_$ $;t_$::set(this->LastKey,0); t_$::set(this->LastChar,0); t_$::set(this->News,false); t_$::set(this->Down,$); t_$::set(this->Changed,$);}
  typedef QapKeyboard SelfClass;
  static const string qap_def_pro_get_class_name(){return "QapKeyboard";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} QapKeyboard(SelfClass&&ref){DoReset();oper_set(std::move(ref));} QapKeyboard(){DoReset();} QapKeyboard(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->LastKey=std::move(ref.LastKey); this->LastChar=std::move(ref.LastChar); this->News=std::move(ref.News); this->Down=std::move(ref.Down); this->Changed=std::move(ref.Changed);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->LastKey!=ref.LastKey){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"LastKey"+"\ndiff:\n"+qap_def_pro_diff(this->LastKey,ref.LastKey));ok=false; } if(this->LastChar!=ref.LastChar){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"LastChar"+"\ndiff:\n"+qap_def_pro_diff(this->LastChar,ref.LastChar));ok=false; } if(this->News!=ref.News){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"News"+"\ndiff:\n"+qap_def_pro_diff(this->News,ref.News));ok=false; } if(this->Down!=ref.Down){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"Down"+"\ndiff:\n"+qap_def_pro_diff(this->Down,ref.Down));ok=false; } if(this->Changed!=ref.Changed){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"Changed"+"\ndiff:\n"+qap_def_pro_diff(this->Changed,ref.Changed));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${ template<class QapIO> static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.LastKey); QapSave(IO,ref.LastChar); QapSave(IO,ref.News); QapSave(IO,ref.Down); QapSave(IO,ref.Changed);; } template<class QapIO> static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.LastKey); QapLoad(IO,ref.LastChar); QapLoad(IO,ref.News); QapLoad(IO,ref.Down); QapLoad(IO,ref.Changed);; } };
public:
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
  bool OnUp(int index)const
  {
    return Changed[index]&&!Down[index];
  }
  vec2d get_dir_from_wasd_and_arrows()const
  {
    vec2d dp=vec2d_zero;
    auto dir_x=vec2d(1,0);
    auto dir_y=vec2d(0,1);
    if(Down[VK_LEFT]||Down['A']){dp+=-dir_x;};
    if(Down[VK_RIGHT]||Down['D']){dp+=+dir_x;};
    if(Down[VK_UP]||Down['W']){dp+=+dir_y;};
    if(Down[VK_DOWN]||Down['S']){dp+=-dir_y;};
    return dp;
  }
  bool operator()(const string&hotkey)const{
    if(hotkey.size()==1)return OnDown(hotkey[0]);
    auto arr=split(hotkey,"+");
    QapAssert(arr.size()==2&&arr[1].size()==1);
    bool ok=false;
    auto f=[&](const char*p,int key){if(LowerStr(p)==LowerStr(arr[0]))ok=Down(key);};
    f("ALT",VK_MENU);
    f("CTRL",VK_CONTROL);
    f("SHIFT",VK_SHIFT);
    return ok&&OnDown(arr[1][0]);
  }
  bool any_down(const string&keys){
    for(int i=0;i<keys.size();i++)if(Down[keys[i]]){
      return true;
    }
    return false;
  }
  enum t_arrows{arrows};
  bool any_down(const t_arrows&){
    if(Down[VK_LEFT])return true;;
    if(Down[VK_RIGHT])return true;;
    if(Down[VK_UP])return true;;
    if(Down[VK_DOWN])return true;;
    return false;
  }
};
enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};
namespace detail{
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
};
template<typename TYPE,bool is_proxy>
struct ProxySys$$;
template<typename TYPE>
struct ProxySys$$<TYPE,true>
{
  static void Save(QapIO&IO,TYPE&ref){
    TYPE::ProxySys$$::Save(IO,ref);
  }
  static void Load(QapIO&IO,TYPE&ref){
    TYPE::ProxySys$$::Load(IO,ref);
  }
};
template<class TYPE>
struct Sys$${
  static void Save(QapIO&IO,TYPE&ref)
  {
    ProxySys$$<TYPE,detail::has_ProxySys$$<TYPE>::value>::Save(IO,ref);
  }
  static void Load(QapIO&IO,TYPE&ref)
  {
    ProxySys$$<TYPE,detail::has_ProxySys$$<TYPE>::value>::Load(IO,ref);
  }
};
template<class TYPE>void QapSave(QapIO&IO,TYPE&ref){Sys$$<TYPE>::Save(IO,ref);}
template<class TYPE>void QapLoad(QapIO&IO,TYPE&ref){Sys$$<TYPE>::Load(IO,ref);}
template<class TYPE>string QapSaveToStr(TYPE&ref){TDataIO IO;QapSave(IO,ref);return IO.IO.mem;}
template<class TYPE>void QapLoadFromStr(TYPE&ref,const string&data){TDataIO IO; IO.IO.mem=data;QapLoad(IO,ref);}
template<class TYPE>void QapSaveToFileOld(const string&fn,TYPE&ref){file_put_contents(fn,QapSaveToStr(ref));}
template<class TYPE>void QapLoadFromFileOld(const string&fn,TYPE&ref){QapLoadFromStr(ref,file_get_contents(fn));}
template<class TYPE>void QapSaveToFile(const string&fn,TYPE&ref){FsWrite IO(fn);return QapSave(IO,ref);}
template<class TYPE>void QapLoadFromFile(const string&fn,TYPE&ref){FsIO<> IO(fn);return QapLoad(IO,ref);}
template<class TYPE>int QapSizeOfSave(){TSizeIO IO;TYPE tmp;QapSave(IO,tmp);return IO.size;}
template<class TYPE>string QapSaveToStrWithSizeOfType(TYPE&ref)
{
  int size_of_type=QapSizeOfSave<TYPE>();
  TDataIO IO;QapSave(IO,size_of_type);QapSave(IO,ref);return IO.IO.mem;
}
template<class TYPE>void QapLoadFromStrWithSizeOfType(TYPE&ref,const string&data){
  int size_of_type=-1;
  TDataIO IO;IO.IO.mem=data;QapLoad(IO,size_of_type);
  int our_size=QapSizeOfSave<TYPE>();
  if(size_of_type!=our_size)return;
  QapLoad(IO,ref);
}
template<>
struct Sys$$<QapKeyboard::TKeyState>{
  static void Save(QapIO&IO,QapKeyboard::TKeyState&ref)
  {
    static_assert(QapKeyboard::TKeyState::MAX_KEY==263,"hm...");
    std::bitset<256+8> bs;
    for(int i=0;i<ref.MAX_KEY;i++){auto&ex=ref.data[i];QapAssert(1>=*(uchar*)(void*)&ex);bs[i]=ex;}
    IO.SavePOD(&bs,sizeof(bs));
  }
  static void Load(QapIO&IO,QapKeyboard::TKeyState&ref)
  {
    static_assert(QapKeyboard::TKeyState::MAX_KEY==263,"hm...");
    std::bitset<256+8> bs;
    IO.LoadPOD(&bs,sizeof(bs));
    for(int i=0;i<ref.MAX_KEY;i++){auto&ex=ref.data[i];ex=bs[i];}
  }
};
template<> struct Sys$$<QapColor>{ static void Save(QapIO&IO,QapColor&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,QapColor&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };template<> struct Sys$$<vec2i>{ static void Save(QapIO&IO,vec2i&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,vec2i&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };template<> struct Sys$$<vec2f>{ static void Save(QapIO&IO,vec2f&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,vec2f&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };template<> struct Sys$$<vec2d>{ static void Save(QapIO&IO,vec2d&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,vec2d&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };template<> struct Sys$$<vec3f>{ static void Save(QapIO&IO,vec3f&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,vec3f&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };template<> struct Sys$$<QapMat4>{ static void Save(QapIO&IO,QapMat4&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,QapMat4&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };template<> struct Sys$$<vec3d>{ static void Save(QapIO&IO,vec3d&ref) { IO.SavePOD(&ref,sizeof(ref)); } static void Load(QapIO&IO,vec3d&ref) { IO.LoadPOD(&ref,sizeof(ref)); } };
template<class TYPE>
struct Sys$$<vector<TYPE>>{
  static void Save(QapIO&IO,vector<TYPE>&ref)
  {
    int size=ref.size();
    IO.save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      auto&ex=ref[i];
      Sys$$<TYPE>::Save(IO,ex);
    }
  }
  static void Load(QapIO&IO,vector<TYPE>&ref)
  {
    int size=0;
    IO.load(size);
    if(size<0){IO.Crash();return;}
    ref.resize(size);
    for(int i=0;i<size;i++){
      auto&ex=ref[i];
      Sys$$<TYPE>::Load(IO,ex);
    }
  }
};
template<> struct Sys$$<int>{ static void Save(QapIO&IO,int&ref) { IO.save(ref); } static void Load(QapIO&IO,int&ref) { IO.load(ref); } };template<> struct Sys$$<unsigned int>{ static void Save(QapIO&IO,unsigned int&ref) { IO.save(ref); } static void Load(QapIO&IO,unsigned int&ref) { IO.load(ref); } };template<> struct Sys$$<char>{ static void Save(QapIO&IO,char&ref) { IO.save(ref); } static void Load(QapIO&IO,char&ref) { IO.load(ref); } };template<> struct Sys$$<unsigned char>{ static void Save(QapIO&IO,unsigned char&ref) { IO.save(ref); } static void Load(QapIO&IO,unsigned char&ref) { IO.load(ref); } };template<> struct Sys$$<bool>{ static void Save(QapIO&IO,bool&ref) { IO.save(ref); } static void Load(QapIO&IO,bool&ref) { IO.load(ref); } };template<> struct Sys$$<int64>{ static void Save(QapIO&IO,int64&ref) { IO.save(ref); } static void Load(QapIO&IO,int64&ref) { IO.load(ref); } };template<> struct Sys$$<uint64>{ static void Save(QapIO&IO,uint64&ref) { IO.save(ref); } static void Load(QapIO&IO,uint64&ref) { IO.load(ref); } };template<> struct Sys$$<float>{ static void Save(QapIO&IO,float&ref) { IO.save(ref); } static void Load(QapIO&IO,float&ref) { IO.load(ref); } };template<> struct Sys$$<real>{ static void Save(QapIO&IO,real&ref) { IO.save(ref); } static void Load(QapIO&IO,real&ref) { IO.load(ref); } };template<> struct Sys$$<short>{ static void Save(QapIO&IO,short&ref) { IO.save(ref); } static void Load(QapIO&IO,short&ref) { IO.load(ref); } };template<> struct Sys$$<unsigned short>{ static void Save(QapIO&IO,unsigned short&ref) { IO.save(ref); } static void Load(QapIO&IO,unsigned short&ref) { IO.load(ref); } };template<> struct Sys$$<string>{ static void Save(QapIO&IO,string&ref) { IO.save(ref); } static void Load(QapIO&IO,string&ref) { IO.load(ref); } };
struct t_quad;
bool point_in_quad(const t_quad&q,const vec2d&p);
struct t_quad{
vec2d pos; vec2d size; void DoReset(){t_$ $;t_$::set(this->pos,$); t_$::set(this->size,$);}
  typedef t_quad SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_quad";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_quad(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_quad(){DoReset();} t_quad(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->pos=std::move(ref.pos); this->size=std::move(ref.size);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->pos!=ref.pos){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"pos"+"\ndiff:\n"+qap_def_pro_diff(this->pos,ref.pos));ok=false; } if(this->size!=ref.size){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"size"+"\ndiff:\n"+qap_def_pro_diff(this->size,ref.size));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.pos); QapSave(IO,ref.size);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.pos); QapLoad(IO,ref.size);; } };
  t_quad&set(const vec2d&p,const vec2d&s){pos=p;size=s;return *this;}
  vec2d get_vertex_by_dir(const vec2d&dir)const{return pos+vec2d::sign(dir).Mul(size)*0.5;}
  vec2d get_left_top()const{return pos+vec2d(-1,+1).Mul(size)*0.5;}
  void set_pos_by_vertex_and_dir(const vec2d&vertex,const vec2d&dir)
  {
    auto d=vec2d::sign(dir);
    pos=vertex+d.Mul(size)*0.5;
  }
  t_quad add_size(real ds)const{t_quad q=*this;q.size+=vec2d(ds,ds);return q;}
  t_quad add_size(vec2d size)const{t_quad q=*this;q.size+=size;return q;}
  t_quad add_pos(const vec2d&pos)const{t_quad q=*this;q.pos+=pos;return q;}
  vec2d clamp(const vec2d&point)const
  {
    return clamp(point-pos,size)+pos;
  }
  static vec2d clamp(const vec2d&p,const vec2d&size)
  {
    return vec2d(Clamp<real>(p.x,-size.x*0.5,+size.x*0.5),Clamp<real>(p.y,-size.y*0.5,+size.y*0.5));
  }
  t_quad get_subquad(int w,int h,int x,int y)const{return get_subquad(vec2d(w,h),vec2d(x,y));}
  t_quad get_subquad(const vec2i&wh,const vec2i&xy)const{return get_subquad(vec2d(wh),vec2d(xy));}
  t_quad get_subquad(const vec2d&wh,const vec2d&xy)const{
    t_quad out=*this;
    out.size=size.Div(wh);
    out.pos+=xy.Div(wh).Mul(size)+(out.size-size)*0.5;
    return out;
  }
  vec2i get_xy(const vec2i&wh,const vec2d&point_from_subquad)const{
    vec2i out;
    auto base=pos-size*0.5;
    auto fc=(point_from_subquad-base).Div(size).Mul(wh);
    out=vec2i(fc.x,fc.y);
    QapAssert(point_in_quad(get_subquad(wh,out),point_from_subquad));
    return out;
  }
  struct t_points{vec2d a,b,c,d;};
  t_points get_points()const{
    auto hqs=0.5*size;
    t_points out={
      pos+vec2d(+1,+1).Mul(hqs),
      pos+vec2d(+1,-1).Mul(hqs),
      pos+vec2d(-1,-1).Mul(hqs),
      pos+vec2d(-1,+1).Mul(hqs)
    };
    return out;
  }
};
static bool check_point_in_half_interval(real x,real s){
  return -s<=x&&x<+s;
}
static bool point_in_quad_v_half_interval(const t_quad&q,const vec2d&p)
{
  auto s=q.size*0.5;
  auto o=p-q.pos;
  return check_point_in_half_interval(o.x,s.x)&&check_point_in_half_interval(o.y,s.y);
}
static bool point_in_quad(const t_quad&q,const vec2d&p)
{
  auto s=q.size*0.5;
  auto o=p-q.pos;
  return fabs(s.x)>=fabs(o.x)&&fabs(s.y)>=fabs(o.y);
}
static bool point_in_quad(const vec2d&p,const t_quad&q){return point_in_quad(q,p);}
static vec2d join_quads_by_y(const vector<t_quad>&arr)
{
  real total_y=0; real max_x=0;
  for(int i=0;i<arr.size();i++){auto&s=arr[i].size;total_y+=s.y;max_x=std::max<real>(max_x,s.x);}
  return vec2d(max_x,total_y);
}
static vec2d join_quads_by_x(const vector<t_quad>&arr)
{
  real total_x=0; real max_y=0;
  for(int i=0;i<arr.size();i++){auto&s=arr[i].size;total_x+=s.x;max_y=std::max<real>(max_y,s.y);}
  return vec2d(total_x,max_y);
}
static vec2d join_quads_by_dir(const vector<t_quad>&arr,char dir='x')
{
  if(dir=='x')return join_quads_by_x(arr);
  if(dir=='y')return join_quads_by_y(arr);
  QapNoWay();
  return vec2d_zero;
}
static vec2d join_quads_by_y_ex(const vector<t_quad>&arr,real space){return join_quads_by_y(arr)+vec2d(0,space*std::max<int>(0,int(arr.size())-1));}
static vec2d join_quads_by_x_ex(const vector<t_quad>&arr,real space){return join_quads_by_x(arr)+vec2d(space*std::max<int>(0,int(arr.size())-1),0);}
static vec2d join_quads_by_dir_ex(const vector<t_quad>&arr,char dir='x',real space=0)
{
  if(dir=='x')return join_quads_by_x_ex(arr,space);
  if(dir=='y')return join_quads_by_y_ex(arr,space);
  QapNoWay();
  return vec2d_zero;
}
static void layout_by_dir(vector<t_quad>&arr,char dir='x',real space=0)
{
  QapAssert(dir=='x'||dir=='y');
  t_quad q;
  q.size=join_quads_by_dir_ex(arr,dir,space);
  vec2d vdir=dir=='x'?vec2i(+1,0):vec2d(0,-1);
  auto p=q.get_vertex_by_dir(-vdir);
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    ex.set_pos_by_vertex_and_dir(p,vdir);
    auto dp=dir=='x'?vec2d(space+ex.size.x,0):vec2d(0,-space-ex.size.y);
    p+=dp;
  }
}
static vector<t_quad> split_quad_by_dir(t_quad q,char dir='x',int n=2)
{
  vector<t_quad> arr;
  vec2d dv=vec2d(dir=='x'?1:0,dir=='y'?1:0);
  vec2d dn=vec2d(dv.y,dv.x);
  auto d=dv*(1.0/n)+dn;
  auto size=q.size.Mul(d);
  for(int i=0;i<n;i++)qap_add_back(arr).size=size;
  layout_by_dir(arr,dir,0.0);
  return arr;
}
template<class TYPE>static bool qap_check_id(const vector<TYPE>&arr,int id){return id>=0&&id<arr.size();}
template<class TYPE>
struct vector_view{
  const TYPE*p;
  unsigned n;
  vector_view<TYPE>():p(nullptr),n(0){}
  const TYPE&operator[](int id)const{return p[id];}
  int size()const{return n;}
  bool empty()const{return !n;}
  vector_view<TYPE>(const vector<TYPE>&ref,int start,int n):p(nullptr),n(0)
  {
    if(!n)return;
    QapAssert(qap_check_id(ref,start));
    QapAssert(qap_check_id(ref,start+n-1));
    p=n?&ref[start]:nullptr;
    this->n=n;
  }
  vector_view<TYPE>(const vector<TYPE>&ref):p(nullptr),n(0)
  {
    if(!ref.size())return;
    p=&ref[0];n=ref.size();
  }
  template<size_t N>vector_view(const array<TYPE,N>&ref):p(&ref[0]),n(N){}
  template<size_t N>vector_view<TYPE>(const TYPE(&ref)[N]):p(&ref[0]),n(N){}
};
template<class TYPE>
vector_view<TYPE> make_view(vector<TYPE>&ref,int start,int n)
{
  vector_view<TYPE> vv;if(!n)return vv;
  QapAssert(qap_check_id(ref,start));
  QapAssert(qap_check_id(ref,start+n-1));
  vv.p=n?&ref[start]:nullptr;
  vv.n=n;
  return vv;
}
template<class TYPE>
const vector_view<TYPE> make_view(const vector<TYPE>&ref,int start,int n)
{
  vector_view<TYPE> vv;if(!n)return vv;
  if(!qap_check_id(ref,start)||!qap_check_id(ref,start+n-1)){
    QapNoWay();
  }
  vv.p=n?&ref[start]:nullptr;
  vv.n=n;
  return vv;
}
template<class TYPE>
vector_view<TYPE> make_view(vector<TYPE>&ref)
{
  vector_view<TYPE> vv={nullptr,0};if(!ref.size())return vv;
  vv.p=&ref[0];
  vv.n=ref.size();
  return vv;
}
template<class TYPE>
const vector_view<TYPE> make_view(const vector<TYPE>&ref){return ref;}
template<class TYPE,size_t N>
const vector_view<TYPE> make_view(const array<TYPE,N>&ref){return ref;}
template<class TYPE,size_t N>
const vector_view<TYPE> make_view(const TYPE(&ref)[N]){
  vector_view<TYPE> out;
  out.p=&ref[0];
  out.n=N;
  return out;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector_view<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector_view<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}
template<class TYPE>bool qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}
template<class TYPE>bool qap_includes(const vector_view<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}
template<class TYPE,class FUNC>void qap_foreach(vector<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const vector<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(vector_view<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const vector_view<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
class QapClock
{
public:
  double beg,tmp;
  bool run;
public:
  QapClock(){run=false;Start();}
  double em_perf_now(){
    timeval t;
    gettimeofday(&t,NULL);
    return (t.tv_sec*1e6+t.tv_usec)*1e-3;
  }
  void Start(){beg=em_perf_now();run=true;}
  void Stop(){tmp=em_perf_now();run=false;tmp-=beg;}
  double Time(){if(run)tmp=em_perf_now();return double(run?(tmp-beg):tmp)/1000.0;}
  double MS()
  {
    double d1000=1000.0;
    if(run)tmp=em_perf_now();
    if(run)return tmp-beg;
    if(!run)return tmp;
    return 0;
  }
};
inline string file_get_contents(const string&fn){CrutchIO IO;IO.LoadFile(fn);return IO.mem;}
inline void file_put_contents(const string&fn,const string&data){CrutchIO IO;IO.mem=data;IO.SaveFile(fn);}
inline real SToF(const string&S){real r;sscanf(S.c_str(),"%lf",&r);return r;};
inline int SToI(const string&S){int i;sscanf(S.c_str(),"%i",&i);return i;};
class QapDev{
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
  typedef QapDev SelfClass;
public:
  vector<Ver> VB;
  vector<int> IB;
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
    this->VB.clear();
    this->IB.clear();
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
    (this->Batching)=(false);
    (this->Textured)=(false);
    detail::FieldTryDoReset(this->xf);
    detail::FieldTryDoReset(this->txf);
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
  void Init(int VCount,int ICount)
  {
    if(VB.empty())
    {
      MaxVPos=VCount;
      MaxIPos=ICount;
      VB.resize(VCount);QapAssert(VCount);
      IB.resize(ICount);QapAssert(ICount);
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
    VB.clear();IB.clear();
    VBA=nullptr;
    IBA=nullptr;
    VPos=0;
    IPos=0;
    Batching=false;
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
  void BeginBatch()
  {
    Batching=true;
    VBA=0;
    IBA=0;
    VPos=0;
    IPos=0;
    if(!IB.size()||!VB.size())return;
    VBA=&VB[0];IBA=&IB[0];
  };
  void EndBatch(bool call_dip=true)
  {
    Batching=false;
    if(!IB.size()||!VB.size())return;
    if(VPos&&IPos)
    {
      if(call_dip)DIP();
    }
    VBA=0;
    IBA=0;
  }
  void DIP()
  {
    QapNoWay();
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
  }
public:
  void HackMode(bool Textured)
  {
    this->Textured=Textured;
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
      QapAssert(vec2d(-1,-1).Ort()==vec2d(+1,-1));
      {AddVertex(x+(-half_w),y+(-half_h),color,0.0f,1.0f);};
      {AddVertex(x+(+half_w),y+(-half_h),color,1.0f,1.0f);};
      {AddVertex(x+(+half_w),y+(+half_h),color,1.0f,0.0f);};
      {AddVertex(x+(-half_w),y+(+half_h),color,0.0f,0.0f);}; 
    }
  }
  void DrawQuad(float x,float y,float w,float h)
  {
    BatchScope Scope(*this);
    {
      vec2d O(x,y);
      int n=VPos;
      {AddVertex(x+(-0.5f)*w,y+(-0.5f)*h,color,0.0f,1.0f);};
      {AddVertex(x+(+0.5f)*w,y+(-0.5f)*h,color,1.0f,1.0f);};
      {AddVertex(x+(+0.5f)*w,y+(+0.5f)*h,color,1.0f,0.0f);};
      {AddVertex(x+(-0.5f)*w,y+(+0.5f)*h,color,0.0f,0.0f);}; 
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
      {
        int a=VID[n*0+(i+0)%n];
        int b=VID[n*0+(i+1)%n];
        int c=VID[n*1+(i+0)%n];
        int d=VID[n*1+(i+1)%n];
        AddQuad(0,a,b,d,c);
      }
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
    QapAssert(cn>2&&seg>2);
    int axispoints=0;
    auto n=(1+cn)/2;
    auto zoom=1.0/n;
    auto point_color=color;
    vector<int> VID;
    VID.reserve(n*2*seg-seg);
    for(int j=-n+1;j<n;j++)
    {
      auto z=sin((j*zoom)*PiD2);
      auto m=sqrt(1-(z*z));
      if(fabs(z)>=1)
      {
        axispoints++;
        continue;
      }
      for(int i=0;i<seg;i++)
      {
        auto v=Vec2dEx(i*Pi2/seg,1);
    v.x*=scale.x;
    v.y*=scale.y;
        vec3f dpos=vec3f(v.x*m,v.y*m,z*scale.z);
        color=point_color;
        qap_add_back(VID)=AddVertex(pos+r*dpos);
      }
    }
    color=point_color;
    auto A=AddVertex(pos+vec3f(0,0,r*scale.z));
    auto B=AddVertex(pos-vec3f(0,0,r*scale.z));
    QapAssert(!axispoints);
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
    }
    color=point_color;
    auto A=AddVertex(pos+vec3f(0,0,r));
    auto B=AddVertex(pos-vec3f(0,0,r));
    QapAssert(!axispoints);
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
    auto dir_mag=dir.Mag();
    auto dxup=vec3f(up);
    auto m=MatrixLookAtLH(b,a,up);
    {
      QapMat4 tmp;
      {
        QapDev::BatchScope scope(*this);
        Xf4Scope xf4scope(*this);
        auto rotx=[](const vec3f&dir)->QapMat4
        {
          return QapMat4(
                +1,+0,+0,+0,
                +0,-dir.z,+dir.y,+0,
                +0,-dir.y,-dir.z,+0,
                +0,+0,+0,+1
              );
        };
        auto roty=[](const vec3f&dir)->QapMat4 
        {
          float c=dir.z; float s=dir.x;
          return QapMat4(
                +c,+0,-s,+0,
                +0,+1,+0,+0,
                +s,+0,+c,+0,
                +0,+0,+0,+1
              );
        };
        auto new_mat=[](const vec3f&ox,const vec3f&oy,const vec3f&oz)
        {
          return QapMat4(
            ox.x,ox.y,ox.z,0,
            oy.x,oy.y,oy.z,0,
            oz.x,oz.y,oz.z,0,
            0,0,0,1
          );
        };
        auto rot=[&new_mat,&up](const vec3f&dir)->QapMat4
        {
          auto nz=cross(dir,up).Norm();
          auto ny=cross(dir,nz).Norm();
          float x=dir.x; float y=dir.y;float z=dir.z; 
          return new_mat(nz,ny,dir);
        };
        xf4=rot(dir)*Translate(pos);
        DrawCylinder(zer,z_len,r,seg,ang,full);
      }
      return;
      auto prev_color=color;
      auto prev_r=r;
      auto r=prev_r*0.1;
      for(int x=-2;x<=2;x++)
      for(int i=-2;i<2;i++)
      {
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
          color=0xffffff00;
          DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.02);
        }
        {
          QapDev::BatchScope scope(*this);
          Xf4Scope xf4scope(*this);
          xf4=RotateX(i*0.4)*RotateY(x*0.4)*Translate(u*0.1,0,0);
          color=prev_color;
          DrawCylinder(zer,z_len,r,seg,ang,full);
          color=0xff402020;
          DrawCube(z_len*vec3f(0,0,+0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          color=0xffff8000;
          DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.02);
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
      if(full)
      {
        int o=VID[n*0+(0+0)%n];
        int a=VID[n*0+(i+1)%n];
        int b=VID[n*0+(i+2)%n];
        AddTris(o,a,b);
      }
      if(full)
      {
        int o=VID[n*1+(0+0)%n];
        int a=VID[n*1+(i+1)%n];
        int b=VID[n*1+(i+2)%n];
        AddTrisInv(o,a,b);
      }
      {
        int a=VID[n*0+(i+1)%n];
        int b=VID[n*0+(i+2)%n];
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
    d=-1;
    {n=VPos;add_vertex(-1,-1,d);;add_vertex(+1,-1,d);;add_vertex(+1,+1,d);;add_vertex(-1,+1,d);;add_tris();};
    {n=VPos;add_vertex(d,-1,-1);;add_vertex(d,+1,-1);;add_vertex(d,+1,+1);;add_vertex(d,-1,+1);;add_tris();};
    {n=VPos;add_vertex(-1,d,-1);;add_vertex(+1,d,-1);;add_vertex(+1,d,+1);;add_vertex(-1,d,+1);;add_tris();};
    d=+1;
    {n=VPos;add_vertex(-1,-1,d);;add_vertex(+1,-1,d);;add_vertex(+1,+1,d);;add_vertex(-1,+1,d);;add_tris();};
    {n=VPos;add_vertex(d,-1,-1);;add_vertex(d,+1,-1);;add_vertex(d,+1,+1);;add_vertex(d,-1,+1);;add_tris();};
    {n=VPos;add_vertex(-1,d,-1);;add_vertex(+1,d,-1);;add_vertex(+1,d,+1);;add_vertex(-1,d,+1);;add_tris();};
  }
  void AddIndex(int id){IBA[IPos++]=id;}
public:
struct t_geom{
vector<vec2d> VA; vector<int> IA; void DoReset(){t_$ $;t_$::set(this->VA,$); t_$::set(this->IA,$);}
  typedef t_geom SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_geom";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_geom(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_geom(){DoReset();} t_geom(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->VA=std::move(ref.VA); this->IA=std::move(ref.IA);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->VA!=ref.VA){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"VA"+"\ndiff:\n"+qap_def_pro_diff(this->VA,ref.VA));ok=false; } if(this->IA!=ref.IA){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"IA"+"\ndiff:\n"+qap_def_pro_diff(this->IA,ref.IA));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.VA); QapSave(IO,ref.IA);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.VA); QapLoad(IO,ref.IA);; } };
  void AddTris(int a,int b,int c)
  {
    qap_add_back(IA)=a;
    qap_add_back(IA)=b;
    qap_add_back(IA)=c;
  }
  void AddVertex(real x,real y){VA.push_back(vec2d(x,y));}
  void AddVertex(const vec2d&pos){VA.push_back(pos);}
  int AddVertexAndRetVID(const vec2d&pos){VA.push_back(pos);return VA.size()-1;}
  void add(const t_geom&geom)
  {
    QapAssert(0==geom.IA.size()%3);
    auto vpos=VA.size();
    for(int i=0;i<geom.VA.size();i++)VA.push_back(geom.VA[i]);
    for(int i=0;i<geom.IA.size();i++)IA.push_back(vpos+geom.IA[i]);
  }
  void add_with_offset(const t_geom&geom,const vec2d&pos)
  {
    auto vpos=VA.size();
    for(int i=0;i<geom.VA.size();i++)
    {
      auto&ex=geom.VA[i];
      AddVertex(pos+ex);
    }
    QapAssert(0==geom.IA.size()%3);
    auto&IA=geom.IA;
    for(int i=0;i<IA.size();i+=3)
    {
      auto&a=IA[i+0];
      auto&b=IA[i+1];
      auto&c=IA[i+2];
      AddTris(vpos+a,vpos+b,vpos+c);
    }
  }
};
static t_geom GenGeomQuad(const vec2d&pos,float w,float h){return GenGeomQuad(pos.x,pos.y,w,h);}
static t_geom GenGeomQuad(float x,float y,float w,float h)
{
  t_geom geom;
  vec2d O(x,y);
  {geom.AddVertex(x+(-0.5f)*w,y+(-0.5f)*h);};
  {geom.AddVertex(x+(+0.5f)*w,y+(-0.5f)*h);};
  {geom.AddVertex(x+(+0.5f)*w,y+(+0.5f)*h);};
  {geom.AddVertex(x+(-0.5f)*w,y+(+0.5f)*h);}; 
  geom.AddTris(1,0,3);
  geom.AddTris(3,2,1);
  return geom;
}
static t_geom GenGeomCircleSolid(real r,int seg,real ang)
{
  t_geom geom;
  int n=seg;
  if(n<=0)return t_geom();
  for(int i=0;i<n;i++)
  {
    vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
    qap_add_back(geom.VA)=v*r;
  }
  for(int i=2;i<n;i++)
  {
    geom.AddTris(0,i-1,i);
  }
  return geom;
}
static t_geom GenGeomCircleEx(real r0,real r1,int seg,real ang)
{
  t_geom geom;
  int n=seg;
  if(n<=0)return t_geom();
  geom.VA.resize(n*2);
  for(int i=0;i<n;i++)
  {
    vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
    geom.VA[i+0]=v*r0;
    geom.VA[i+n]=v*r1;
  }
  for(int i=0;i<n;i++)
  {
    int a=0+(i+0)%n;
    int b=0+(i+1)%n;
    int c=n+(i+0)%n;
    int d=n+(i+1)%n;
    geom.AddTris(a,b,d);
    geom.AddTris(d,c,a);
  }
  return geom;
}
template<typename TYPE>
static t_geom GenGeomLineList(const vector<TYPE>&PA,const real&LineSize)
{
  t_geom geom;
  if(PA.empty())return geom;
  int Count=PA.size();
  for (int i=0;i+1<Count;i+=2)
  {
    auto&a=PA[i+0];
    auto&b=PA[i+1];
    TYPE n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
    int A=geom.AddVertexAndRetVID(a+n);
    int B=geom.AddVertexAndRetVID(b-n);
    int C=geom.AddVertexAndRetVID(a-n);
    int D=geom.AddVertexAndRetVID(b+n);
    geom.AddTris(A,B,C);
    geom.AddTris(A,B,D);
  }
  return geom;
}
void DrawGeomWithOffset(t_geom&geom,const vec2d&pos)
{
  auto&qDev=*this;
  QapDev::BatchScope Scope(qDev);
  auto vpos=qDev.VPos;
  for(int i=0;i<geom.VA.size();i++)
  {
    auto&ex=geom.VA[i];
    qDev.AddVertex(pos+ex,qDev.color,0,0);
  }
  QapAssert(0==geom.IA.size()%3);
  auto&IA=geom.IA;
  for(int i=0;i<IA.size();i+=3)
  {
    auto&a=IA[i+0];
    auto&b=IA[i+1];
    auto&c=IA[i+2];
    qDev.AddTris(vpos+a,vpos+b,vpos+c);
  }
}
};
void QapUserInfo(const string&msg)
{
  printf("%s",("QapUserInfo:\n"+msg+"\n").c_str());
  fflush(stdout);
}
struct t_app{
  static vec3f mirror(vec3f nn,vec3f light_dir)
  {
    auto v=cross(nn,light_dir);
    return light_dir+nn*2.0*sqrt(1-dot(v,v));
  }
  static real rnd(){return rand()/real(RAND_MAX);};
  static real rndreal(real min,real max){return min+rnd()*(max-min);}
  static void inv(bool&ref){ref=!ref;}
  struct t_photon{
vec3f pos; vec3f dir; void DoReset(){t_$ $;t_$::set(this->pos,$); t_$::set(this->dir,$);}
  typedef t_photon SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_photon";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_photon(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_photon(){DoReset();} t_photon(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->pos=std::move(ref.pos); this->dir=std::move(ref.dir);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->pos!=ref.pos){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"pos"+"\ndiff:\n"+qap_def_pro_diff(this->pos,ref.pos));ok=false; } if(this->dir!=ref.dir){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir"+"\ndiff:\n"+qap_def_pro_diff(this->dir,ref.dir));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.pos); QapSave(IO,ref.dir);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.pos); QapLoad(IO,ref.dir);; } };
  };
  struct t_raypoint{
real t; vec3f pos; vec3f n; QapColor c; void DoReset(){t_$ $;t_$::set(this->t,-1); t_$::set(this->pos,$); t_$::set(this->n,$); t_$::set(this->c,$);}
  typedef t_raypoint SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_raypoint";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_raypoint(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_raypoint(){DoReset();} t_raypoint(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->t=std::move(ref.t); this->pos=std::move(ref.pos); this->n=std::move(ref.n); this->c=std::move(ref.c);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->t!=ref.t){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"t"+"\ndiff:\n"+qap_def_pro_diff(this->t,ref.t));ok=false; } if(this->pos!=ref.pos){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"pos"+"\ndiff:\n"+qap_def_pro_diff(this->pos,ref.pos));ok=false; } if(this->n!=ref.n){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"n"+"\ndiff:\n"+qap_def_pro_diff(this->n,ref.n));ok=false; } if(this->c!=ref.c){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"c"+"\ndiff:\n"+qap_def_pro_diff(this->c,ref.c));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.t); QapSave(IO,ref.pos); QapSave(IO,ref.n); QapSave(IO,ref.c);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.t); QapLoad(IO,ref.pos); QapLoad(IO,ref.n); QapLoad(IO,ref.c);; } };
  };
  struct t_trigon{
vec3f a; vec2f A; vec2f B; vec2f C; vec3f oy; vec3f oz; vec3f ox; vector<float> dir2inv_dy; vector<int> dirs; vector<int> light_dirs; vector<int> light_dirs_counter; void DoReset(){t_$ $;t_$::set(this->a,$); t_$::set(this->A,$); t_$::set(this->B,$); t_$::set(this->C,$); t_$::set(this->oy,$); t_$::set(this->oz,$); t_$::set(this->ox,$); t_$::set(this->dir2inv_dy,$); t_$::set(this->dirs,$); t_$::set(this->light_dirs,$); t_$::set(this->light_dirs_counter,$);}
  typedef t_trigon SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_trigon";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_trigon(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_trigon(){DoReset();} t_trigon(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->a=std::move(ref.a); this->A=std::move(ref.A); this->B=std::move(ref.B); this->C=std::move(ref.C); this->oy=std::move(ref.oy); this->oz=std::move(ref.oz); this->ox=std::move(ref.ox); this->dir2inv_dy=std::move(ref.dir2inv_dy); this->dirs=std::move(ref.dirs); this->light_dirs=std::move(ref.light_dirs); this->light_dirs_counter=std::move(ref.light_dirs_counter);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->a!=ref.a){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"a"+"\ndiff:\n"+qap_def_pro_diff(this->a,ref.a));ok=false; } if(this->A!=ref.A){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"A"+"\ndiff:\n"+qap_def_pro_diff(this->A,ref.A));ok=false; } if(this->B!=ref.B){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"B"+"\ndiff:\n"+qap_def_pro_diff(this->B,ref.B));ok=false; } if(this->C!=ref.C){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"C"+"\ndiff:\n"+qap_def_pro_diff(this->C,ref.C));ok=false; } if(this->oy!=ref.oy){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"oy"+"\ndiff:\n"+qap_def_pro_diff(this->oy,ref.oy));ok=false; } if(this->oz!=ref.oz){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"oz"+"\ndiff:\n"+qap_def_pro_diff(this->oz,ref.oz));ok=false; } if(this->ox!=ref.ox){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"ox"+"\ndiff:\n"+qap_def_pro_diff(this->ox,ref.ox));ok=false; } if(this->dir2inv_dy!=ref.dir2inv_dy){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir2inv_dy"+"\ndiff:\n"+qap_def_pro_diff(this->dir2inv_dy,ref.dir2inv_dy));ok=false; } if(this->dirs!=ref.dirs){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dirs"+"\ndiff:\n"+qap_def_pro_diff(this->dirs,ref.dirs));ok=false; } if(this->light_dirs!=ref.light_dirs){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"light_dirs"+"\ndiff:\n"+qap_def_pro_diff(this->light_dirs,ref.light_dirs));ok=false; } if(this->light_dirs_counter!=ref.light_dirs_counter){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"light_dirs_counter"+"\ndiff:\n"+qap_def_pro_diff(this->light_dirs_counter,ref.light_dirs_counter));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.a); QapSave(IO,ref.A); QapSave(IO,ref.B); QapSave(IO,ref.C); QapSave(IO,ref.oy); QapSave(IO,ref.oz); QapSave(IO,ref.ox); QapSave(IO,ref.dir2inv_dy); QapSave(IO,ref.dirs); QapSave(IO,ref.light_dirs); QapSave(IO,ref.light_dirs_counter);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.a); QapLoad(IO,ref.A); QapLoad(IO,ref.B); QapLoad(IO,ref.C); QapLoad(IO,ref.oy); QapLoad(IO,ref.oz); QapLoad(IO,ref.ox); QapLoad(IO,ref.dir2inv_dy); QapLoad(IO,ref.dirs); QapLoad(IO,ref.light_dirs); QapLoad(IO,ref.light_dirs_counter);; } };
    vec3f normal()const{return -oy;}
  };
public:
  struct t_trigon_vec3f{
vec3f a; vec3f b; vec3f c; void DoReset(){t_$ $;t_$::set(this->a,$); t_$::set(this->b,$); t_$::set(this->c,$);}
  typedef t_trigon_vec3f SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_trigon_vec3f";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_trigon_vec3f(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_trigon_vec3f(){DoReset();} t_trigon_vec3f(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->a=std::move(ref.a); this->b=std::move(ref.b); this->c=std::move(ref.c);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->a!=ref.a){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"a"+"\ndiff:\n"+qap_def_pro_diff(this->a,ref.a));ok=false; } if(this->b!=ref.b){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"b"+"\ndiff:\n"+qap_def_pro_diff(this->b,ref.b));ok=false; } if(this->c!=ref.c){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"c"+"\ndiff:\n"+qap_def_pro_diff(this->c,ref.c));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.a); QapSave(IO,ref.b); QapSave(IO,ref.c);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.a); QapLoad(IO,ref.b); QapLoad(IO,ref.c);; } };
  };
  struct t_trigon_vec2f{
vec2f a; vec2f b; vec2f c; void DoReset(){t_$ $;t_$::set(this->a,$); t_$::set(this->b,$); t_$::set(this->c,$);}
  typedef t_trigon_vec2f SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_trigon_vec2f";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_trigon_vec2f(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_trigon_vec2f(){DoReset();} t_trigon_vec2f(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->a=std::move(ref.a); this->b=std::move(ref.b); this->c=std::move(ref.c);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->a!=ref.a){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"a"+"\ndiff:\n"+qap_def_pro_diff(this->a,ref.a));ok=false; } if(this->b!=ref.b){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"b"+"\ndiff:\n"+qap_def_pro_diff(this->b,ref.b));ok=false; } if(this->c!=ref.c){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"c"+"\ndiff:\n"+qap_def_pro_diff(this->c,ref.c));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.a); QapSave(IO,ref.b); QapSave(IO,ref.c);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.a); QapLoad(IO,ref.b); QapLoad(IO,ref.c);; } };
    t_trigon_vec2f(vec2f a,vec2f b,vec2f c):a(a),b(b),c(c){}
  };
  struct t_trigon_vec2f_with_circle:t_trigon_vec2f{
    vec2d p;real r;
  };
  struct t_axis{
vec3f dir; vec3f ox; vec3f oy; void DoReset(){t_$ $;t_$::set(this->dir,$); t_$::set(this->ox,$); t_$::set(this->oy,$);}
  typedef t_axis SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_axis";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_axis(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_axis(){DoReset();} t_axis(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->dir=std::move(ref.dir); this->ox=std::move(ref.ox); this->oy=std::move(ref.oy);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->dir!=ref.dir){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir"+"\ndiff:\n"+qap_def_pro_diff(this->dir,ref.dir));ok=false; } if(this->ox!=ref.ox){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"ox"+"\ndiff:\n"+qap_def_pro_diff(this->ox,ref.ox));ok=false; } if(this->oy!=ref.oy){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"oy"+"\ndiff:\n"+qap_def_pro_diff(this->oy,ref.oy));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.dir); QapSave(IO,ref.ox); QapSave(IO,ref.oy);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.dir); QapLoad(IO,ref.ox); QapLoad(IO,ref.oy);; } };
    vec2d get_vec2d(const vec3f&v)const{return vec2d(dot(v,ox),dot(v,oy));}
    vec3f get_vec3f(const vec3f&v)const{return vec3f(dot(v,ox),dot(v,oy),dot(v,dir));}
  };
  static vec3f get_updir(const vec3f&dir){auto up=vec3f(0,1,0);return dir==up?vec3f(0,0,+1):up;}
  static t_axis make_axis_from_dir(const vec3f&dir){
    t_axis out;
    out.dir=dir.Norm();
    out.ox=cross(dir,get_updir(dir)).Norm();
    out.oy=cross(dir,out.ox).Norm();
    return out;
  }
  struct t_dir_quad{
t_axis axis; t_quad q; void DoReset(){t_$ $;t_$::set(this->axis,$); t_$::set(this->q,$);}
  typedef t_dir_quad SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_dir_quad";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_dir_quad(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_dir_quad(){DoReset();} t_dir_quad(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->axis=std::move(ref.axis); this->q=std::move(ref.q);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->axis!=ref.axis){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"axis"+"\ndiff:\n"+qap_def_pro_diff(this->axis,ref.axis));ok=false; } if(this->q!=ref.q){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"q"+"\ndiff:\n"+qap_def_pro_diff(this->q,ref.q));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.axis); QapSave(IO,ref.q);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.axis); QapLoad(IO,ref.q);; } };
    t_dir_quad get_subquad(const vec2i&wh,const vec2i&xy)const{t_dir_quad out=*this;out.q=q.get_subquad(wh,xy);return out;}
    bool cd_test_vs(const t_trigon_vec2f&t){return CD_TrigonVsQuad(t,q);}
  };
  struct t_cell_quad{
int n; int ptr; void DoReset(){t_$ $;t_$::set(this->n,0); t_$::set(this->ptr,-1);}
  typedef t_cell_quad SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_cell_quad";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_cell_quad(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_cell_quad(){DoReset();} t_cell_quad(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->n=std::move(ref.n); this->ptr=std::move(ref.ptr);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->n!=ref.n){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"n"+"\ndiff:\n"+qap_def_pro_diff(this->n,ref.n));ok=false; } if(this->ptr!=ref.ptr){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"ptr"+"\ndiff:\n"+qap_def_pro_diff(this->ptr,ref.ptr));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.n); QapSave(IO,ref.ptr);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.n); QapLoad(IO,ref.ptr);; } };
    t_cell_quad&set_id(int id){this->ptr=id;return *this;}
  };
  struct t_dir_info{
t_dir_quad dq; vec2i dq_wh; vector<t_cell_quad> pos2info; vector<int> mem; void DoReset(){t_$ $;t_$::set(this->dq,$); t_$::set(this->dq_wh,$); t_$::set(this->pos2info,$); t_$::set(this->mem,$);}
  typedef t_dir_info SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_dir_info";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_dir_info(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_dir_info(){DoReset();} t_dir_info(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->dq=std::move(ref.dq); this->dq_wh=std::move(ref.dq_wh); this->pos2info=std::move(ref.pos2info); this->mem=std::move(ref.mem);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->dq!=ref.dq){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dq"+"\ndiff:\n"+qap_def_pro_diff(this->dq,ref.dq));ok=false; } if(this->dq_wh!=ref.dq_wh){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dq_wh"+"\ndiff:\n"+qap_def_pro_diff(this->dq_wh,ref.dq_wh));ok=false; } if(this->pos2info!=ref.pos2info){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"pos2info"+"\ndiff:\n"+qap_def_pro_diff(this->pos2info,ref.pos2info));ok=false; } if(this->mem!=ref.mem){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"mem"+"\ndiff:\n"+qap_def_pro_diff(this->mem,ref.mem));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.dq); QapSave(IO,ref.dq_wh); QapSave(IO,ref.pos2info); QapSave(IO,ref.mem);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.dq); QapLoad(IO,ref.dq_wh); QapLoad(IO,ref.pos2info); QapLoad(IO,ref.mem);; } };
    void init(const t_dir_quad&quad,const vec2i&wh){
      dq=quad;dq_wh=wh;
      pos2info.clear();
      pos2info.resize(wh.x*wh.y);
      mem.clear();
    }
    template<class FUNC>
    void map(FUNC func){
      auto w=dq_wh.x;auto h=dq_wh.y;
      for(int y=0;y<h;y++)for(int x=0;x<w;x++)func(pos2info[x+y*w],x,y);
    }
    t_cell_quad&get(int x,int y){
      QapAssert(x<dq_wh.x&&x>=0);
      QapAssert(y<dq_wh.y&&y>=0);
      return pos2info[x+y*dq_wh.x];
    }
    const vector_view<int> get_view(const t_cell_quad&cell)const{
      return make_view(mem,cell.ptr,cell.n);
    }
     t_cell_quad&unsafe_get(const vec2i&p){return pos2info[p.x+p.y*dq_wh.x];}
    const t_cell_quad&unsafe_get(const vec2i&p)const{return pos2info[p.x+p.y*dq_wh.x];}
    const vector_view<int> unsafe_get_arr(const vec2i&p)const{
      static const vector_view<int> empty;
      auto&cell=pos2info[p.x+p.y*dq_wh.x];
      return get_view(cell);
    }
    const vector_view<int> safe_get(const vec3f&pos)const{
      auto p=dq.axis.get_vec2d(pos);
      if(!point_in_quad_v_half_interval(dq.q,p))return vector_view<int>();
      auto xy=dq.q.get_xy(dq_wh,p);
      return unsafe_get_arr(xy);
    }
    static int find_end_id(const vector<int>&mem,const vector<int>&arr){
      auto it=std::find_end(mem.begin(),mem.end(),arr.begin(),arr.end());
      if(it==mem.end())return -1;
      return it-mem.begin();
    }
    void set(int x,int y,vector<int>&&arr)
    {
      if(!arr.size()){unsafe_get(vec2i(x,y)).set_id(-1).n=0;return;}
      int id=find_end_id(mem,arr);
      if(!qap_check_id(mem,id))
      {
        id=mem.size();
        qap_foreach(arr,[&](decltype(arr[0])&ex,int i){qap_add_back(mem)=ex;});
      }
      unsafe_get(vec2i(x,y)).set_id(id).n=arr.size();
    }
  };
  struct t_ray_env{
vector<vector<int>> dir_id_to_Ltris_list; vector<vector<int>> dir_id_to_Dtris_list; vector<t_trigon> tris; vector<QapColor> tris_colors; vector<int> is_light; vector<vec3f> dirs; vector<t_trigon_vec3f> trigons; vector<t_dir_info> dir2info; vector<t_dir_info> dir2back; vector<t_dir_info> dir2light; void DoReset(){t_$ $;t_$::set(this->dir_id_to_Ltris_list,$); t_$::set(this->dir_id_to_Dtris_list,$); t_$::set(this->tris,$); t_$::set(this->tris_colors,$); t_$::set(this->is_light,$); t_$::set(this->dirs,$); t_$::set(this->trigons,$); t_$::set(this->dir2info,$); t_$::set(this->dir2back,$); t_$::set(this->dir2light,$);}
  typedef t_ray_env SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_ray_env";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_ray_env(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_ray_env(){DoReset();} t_ray_env(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->dir_id_to_Ltris_list=std::move(ref.dir_id_to_Ltris_list); this->dir_id_to_Dtris_list=std::move(ref.dir_id_to_Dtris_list); this->tris=std::move(ref.tris); this->tris_colors=std::move(ref.tris_colors); this->is_light=std::move(ref.is_light); this->dirs=std::move(ref.dirs); this->trigons=std::move(ref.trigons); this->dir2info=std::move(ref.dir2info); this->dir2back=std::move(ref.dir2back); this->dir2light=std::move(ref.dir2light);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->dir_id_to_Ltris_list!=ref.dir_id_to_Ltris_list){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir_id_to_Ltris_list"+"\ndiff:\n"+qap_def_pro_diff(this->dir_id_to_Ltris_list,ref.dir_id_to_Ltris_list));ok=false; } if(this->dir_id_to_Dtris_list!=ref.dir_id_to_Dtris_list){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir_id_to_Dtris_list"+"\ndiff:\n"+qap_def_pro_diff(this->dir_id_to_Dtris_list,ref.dir_id_to_Dtris_list));ok=false; } if(this->tris!=ref.tris){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"tris"+"\ndiff:\n"+qap_def_pro_diff(this->tris,ref.tris));ok=false; } if(this->tris_colors!=ref.tris_colors){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"tris_colors"+"\ndiff:\n"+qap_def_pro_diff(this->tris_colors,ref.tris_colors));ok=false; } if(this->is_light!=ref.is_light){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"is_light"+"\ndiff:\n"+qap_def_pro_diff(this->is_light,ref.is_light));ok=false; } if(this->dirs!=ref.dirs){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dirs"+"\ndiff:\n"+qap_def_pro_diff(this->dirs,ref.dirs));ok=false; } if(this->trigons!=ref.trigons){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"trigons"+"\ndiff:\n"+qap_def_pro_diff(this->trigons,ref.trigons));ok=false; } if(this->dir2info!=ref.dir2info){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir2info"+"\ndiff:\n"+qap_def_pro_diff(this->dir2info,ref.dir2info));ok=false; } if(this->dir2back!=ref.dir2back){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir2back"+"\ndiff:\n"+qap_def_pro_diff(this->dir2back,ref.dir2back));ok=false; } if(this->dir2light!=ref.dir2light){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir2light"+"\ndiff:\n"+qap_def_pro_diff(this->dir2light,ref.dir2light));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.dir_id_to_Ltris_list); QapSave(IO,ref.dir_id_to_Dtris_list); QapSave(IO,ref.tris); QapSave(IO,ref.tris_colors); QapSave(IO,ref.is_light); QapSave(IO,ref.dirs); QapSave(IO,ref.trigons); QapSave(IO,ref.dir2info); QapSave(IO,ref.dir2back); QapSave(IO,ref.dir2light);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.dir_id_to_Ltris_list); QapLoad(IO,ref.dir_id_to_Dtris_list); QapLoad(IO,ref.tris); QapLoad(IO,ref.tris_colors); QapLoad(IO,ref.is_light); QapLoad(IO,ref.dirs); QapLoad(IO,ref.trigons); QapLoad(IO,ref.dir2info); QapLoad(IO,ref.dir2back); QapLoad(IO,ref.dir2light);; } };
  t_dir_quad make_dir_quad(int dir_id,const string&geom)
  {
    QapAssert(geom.size()<=2);
    auto dir=dirs[dir_id];
    t_dir_quad out;
    out.axis=make_axis_from_dir(dir);
    vec2d low,top;
    for(int i=0;i<geom.size();i++)
    {
      QapAssert(geom[i]=='L'||geom[i]=='D');
      auto&tris=(geom[i]=='D'?dir_id_to_Dtris_list:dir_id_to_Ltris_list)[dir_id];
      qap_foreach(tris,[&](decltype(tris[0])&ex,int i){{auto tmp=out.axis.get_vec2d(trigons[ex].a);low.comin(tmp);top.comax(tmp);}{auto tmp=out.axis.get_vec2d(trigons[ex].b);low.comin(tmp);top.comax(tmp);}{auto tmp=out.axis.get_vec2d(trigons[ex].c);low.comin(tmp);top.comax(tmp);};});
    }
    out.q.size=top-low;
    out.q.pos=0.5*(top+low);
    return out;
  }
  };
  t_trigon_vec2f make_2d_tris(const t_trigon_vec3f&t,const t_axis&axis){
    t_trigon_vec2f out;
    out.a=axis.get_vec2d(t.a);;out.b=axis.get_vec2d(t.b);;out.c=axis.get_vec2d(t.c);;
    return out;
  }
  t_trigon_vec2f_with_circle make_2d_tris_ex(const t_trigon_vec3f&t,const t_axis&axis){
    t_trigon_vec2f_with_circle out;
    out.a=axis.get_vec2d(t.a);;out.b=axis.get_vec2d(t.b);;out.c=axis.get_vec2d(t.c);;
    auto tmp=t_circle_from_points(out);
    out.p=tmp.pos;out.r=tmp.r;
    return out;
  }
  static vector<real> do_clamp_bottom_bound(const vector<real>&arr,real portion=0.1)
  {
    real low=1e20;real top=-low;
    int id=qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return +ex;});auto v=id<0?top:arr[id];
    qap_foreach(arr,[&](decltype(arr[0])&ex,int i){if(ex>v)low=std::min<real>(ex,low);});
    auto out=arr;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){if(ex<=v)ex=low;});
    return out;
  }
  static vector<real> do_clamp_upper_bound(const vector<real>&arr,real portion=0.1)
  {
    real low=1e20;real top=-low;
    int id=qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return -ex;});auto v=id<0?low:arr[id];
    qap_foreach(arr,[&](decltype(arr[0])&ex,int i){if(ex<v)top=std::max<real>(ex,top);});
    auto out=arr;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){if(ex>=v)ex=top;});
    return out;
  }
  static real vec3d_max(const vec3d&v){return std::max(std::max(v.x,v.y),v.z);}
  static real vec3d_min(const vec3d&v){return std::min(std::min(v.x,v.y),v.z);}
  static vec3d vec3d_max(const vec3d&a,const vec3d&b){return vec3d_max(a)<vec3d_max(b)?b:a;}
  static vec3d vec3d_min(const vec3d&a,const vec3d&b){return vec3d_min(a)>vec3d_min(b)?b:a;}
  static vector<vec3d> do_clamp_bottom_bound(const vector<vec3d>&arr)
  {
    auto out=arr;
    real low=1e20;real top=-low;bool fail=true;
    int id=qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return +vec3d_min(ex);});auto v=id<0?top:vec3d_min(arr[id]);
    qap_foreach(arr,[&](decltype(arr[0])&ex,int i){auto m=vec3d_min(ex);if(m>v){low=std::min<real>(m,low);fail=false;};});
    if(fail)return out;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){if(ex.x<=v)ex.x=low;if(ex.y<=v)ex.y=low;if(ex.z<=v)ex.z=low;;});
    return out;
  }
  static vector<vec3d> do_clamp_upper_bound(const vector<vec3d>&arr)
  {
    auto out=arr;
    real low=1e20;real top=-low;bool fail=true;
    int id=qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return -vec3d_max(ex);});auto v=id<0?low:vec3d_max(arr[id]);
    qap_foreach(arr,[&](decltype(arr[0])&ex,int i){auto m=vec3d_max(ex);if(m<v){top=std::max<real>(m,top);fail=false;};});
    if(fail)return out;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){if(ex.x>=v)ex.x=top;if(ex.y>=v)ex.y=top;if(ex.z>=v)ex.z=top;;});
    return out;
  }
  static vector<vec3d> hdr_pixmap(const vector<vec3d>&pix,real min=0x00,real max=0xff)
  {
    real low=1e20;real top=-low;
    qap_foreach(pix,[&](decltype(pix[0])&ex,int i){top=std::max<real>(vec3d_max(ex),top);low=std::min<real>(vec3d_min(ex),low);});
    real dip=max-min;
    real koef=(dip/(top-low));
    auto dno=vec3d(1,1,1)*low;auto min3d=vec3d(min,min,min);
    auto out=pix;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){ex=min3d+(ex-dno)*koef;});
    return out;
  }
  static vector<real> hdr_pixmap(const vector<real>&pix,real min=0x00,real max=0xff)
  {
    real low=1e20;real top=-low;
    qap_foreach(pix,[&](decltype(pix[0])&ex,int i){top=std::max<real>(ex,top);low=std::min<real>(ex,low);});
    real dip=max-min;
    real koef=(dip/(top-low));
    auto out=pix;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){ex=min+(ex-low)*koef;});
    return out;
  }
  static vector<QapColor> hdr_pixmap(const vector<QapColor>&pix)
  {
    int low=256;int top=-1;
    qap_foreach(pix,[&](decltype(pix[0])&ex,int i){if(ex.r!=255)top=std::max<int>(ex.r,top);if(ex.r)low=std::min<int>(ex.r,low);});
    real koef=low>255?1:(253.0/(top-low));
    auto f=[low,top,koef](const QapColor&c){
      auto out=c;
      out.r=c.r==255?255:(!c.r?0:1+std::min<int>(253,(c.r-low)*koef));out.g=c.g==255?255:(!c.g?0:1+std::min<int>(253,(c.g-low)*koef));out.b=c.b==255?255:(!c.b?0:1+std::min<int>(253,(c.b-low)*koef));
      return out;
    };
    auto out=pix;
    qap_foreach(out,[&](decltype(out[0])&ex,int i){ex=f(ex);});
    return out;
  }
  bool is_light(int tris_id)const{return env.is_light[tris_id];}
  void make(vector<t_dir_info>&out,const std::string&dm_geom,const string&order,const string&geom,int limit)
  {
    out.clear();out.resize(env.dirs.size());
    #pragma omp parallel for schedule(guided,8)
    for(int i=0;i<env.dirs.size();i++)
    {
      QapClock clock;
      auto&dir_id=i;
      auto&dir=env.dirs[i];
      auto dq=env.make_dir_quad(dir_id,dm_geom);
      auto dq_wh=vec2i(1,1)*2;
      auto&b=out[i];
      vector<t_trigon_vec2f_with_circle> arr;arr.reserve(env.trigons.size());
      vector<int> id2id;
      real order_k=order=="main"?+1:-1;bool inc_ld_counter=order=="back";
      bool need_light=geom=="light"||geom=="all";
      bool need_dark=geom=="dark"||geom=="all";
      {qap_foreach(env.trigons,[&](decltype(env.trigons[0])&ex,int i){{ auto LT=is_light(i); if(!need_light&&LT)return; if(!need_dark&&!LT)return; if(dot(env.tris[i].normal(),dir)*order_k<0)return; id2id.push_back(i); qap_add_back(arr)=make_2d_tris_ex(ex,dq.axis); };});}
      if(bool first_iter=1)
      {
        b.init(dq,dq_wh);
        auto qr=t_circle_from_points(dq.get_subquad(dq_wh,vec2i(0,0)).q).r;
        b.map([&](t_cell_quad&e,int x,int y){
          auto sq=dq.get_subquad(dq_wh,vec2i(x,y));
          vector<int> out;
          qap_foreach(arr,[&](decltype(arr[0])&ex,int i){if(CD_TrigonVsQuad(ex,sq.q,qr))qap_add_back(out)=i;});
          b.set(x,y,std::move(out));
        });
      }
      auto top=b;
      for(;dq_wh.x*2<=limit;)
      {
        dq_wh*=2;
        b.init(dq,dq_wh);
        auto qr=t_circle_from_points(dq.get_subquad(dq_wh,vec2i(0,0)).q).r;
        b.map([&](t_cell_quad&e,int x,int y){
          auto sq=dq.get_subquad(dq_wh,vec2i(x,y));
          vector<int> out;
          auto tmp=top.unsafe_get_arr(vec2i(x/2,y/2));
          qap_foreach(tmp,[&](decltype(tmp[0])&ex,int i){if(CD_TrigonVsQuad(arr[ex],sq.q,qr))qap_add_back(out)=ex;});
          b.set(x,y,std::move(out));
        });
        top=b;
      }
      b=top;
      qap_foreach(b.mem,[&](decltype(b.mem[0])&ex,int i){ex=id2id[ex];});
      if(inc_ld_counter)
      {
        auto atomic_inc=[](int&ref){
          #pragma omp atomic
          ref++;
        };
        qap_foreach(b.pos2info,[&](decltype(b.pos2info[0])&ex,int i){{ auto arr=b.get_view(ex); bool light_found=false;qap_foreach(arr,[&](decltype(arr[0])&ex,int i){if(is_light(ex))light_found=true;}); if(!light_found)return; qap_foreach(arr,[&](decltype(arr[0])&ex,int i){{ if(is_light(ex))return; auto&t=env.tris[ex]; atomic_inc(t.light_dirs_counter[dir_id]); };}); };});
      }
      if(bool need_imgs_debug=false&&order=="main")
      {
        vector<QapColor> out;
        qap_foreach(b.pos2info,[&](decltype(b.pos2info[0])&ex,int i){auto k=Clamp<int>(ex.n,0,0xff);qap_add_back(out)=QapColor(0xFF,k,k,k);;});
        out=hdr_pixmap(out);
        qap_foreach(out,[&](decltype(out[0])&ex,int i){ex=ex.inv_rgb().swap_rg();});
        foo(dq_wh.x,dq_wh.y,out,("raymaps/"+IToS(i)+".png").c_str());
        int gg=1;
      }
    }
  }
  void toplevel_algo(int limit)
  {
    qap_foreach(env.tris,[&](decltype(env.tris[0])&ex,int i){auto&c=ex.light_dirs_counter;c.clear();c.resize(env.dirs.size());});
    make(env.dir2info,"D","main","dark",limit); 
    make(env.dir2back,"D","back","all",limit); 
    env.dir2back.clear();
    make(env.dir2light,"L","main","light",std::max(8,limit/2)); 
  }
  void make_raymaps()
  {
    int limit=get_raymaps_limit();
    string fn=get_rayenv_fn(limit);
    if(access(fn.c_str(),0)!=0){
      QapUserInfo(fn+" - not found, but ok let's generate it!");
    }else{
      t_ray_env tmp;t_ray_env tmp2;
      QapLoadFromFile(fn,tmp);
      env=std::move(tmp);
      return;
    }
    QapClock clock;
    toplevel_algo(limit);
    qap_foreach(env.tris,[&](decltype(env.tris[0])&ex,int i){{ auto&t=ex; if(is_light(i))return; qap_foreach(t.dirs,[&](decltype(t.dirs[0])&ex,int i){{ if(t.light_dirs_counter[ex]>0){ qap_add_back(t.light_dirs)=ex; } };}); };});
    QapSaveToFile(fn,env);
  }
public:
static bool CD_TrigonVsTrigon(const t_trigon_vec2f&a,const t_trigon_vec2f&b){
  if(int(int(PointInTrigon(a.a,b))+int(PointInTrigon(a.b,b))+int(PointInTrigon(a.c,b)))%3!=0)return true;
  if(int(int(PointInTrigon(b.a,a))+int(PointInTrigon(b.b,a))+int(PointInTrigon(b.c,a)))%3!=0)return true;
}
static bool PointInTrigon(const vec2d&p,const t_trigon_vec2f&t){
  return PointInTrigon(p,t.a,t.b,t.c);
}
static bool PointInTrigon(const vec2d&p,const vec2d&a,const vec2d&b,const vec2d&c){
}
static bool point_in_tris(const vec2d&p,const t_trigon_vec2f&t){return point_in_tris(t,p);}
static bool point_in_tris(const vec2f&p,const t_trigon_vec2f&t){return point_in_tris(t,vec2d(p));}
static bool point_in_tris(const t_trigon_vec2f&t,const vec2d&p){
  int arr[3]={0,0,0};
  arr[int(Sign(cross(vec2d(t.b-t.a),p-vec2d(t.a)))+1)]++;;arr[int(Sign(cross(vec2d(t.c-t.b),p-vec2d(t.b)))+1)]++;;arr[int(Sign(cross(vec2d(t.a-t.c),p-vec2d(t.c)))+1)]++;;
  if(arr[0]&&arr[2])return false;
  return true;
}
static bool CD_LineVsLine(const vec2d&a,const vec2d&b,const vec2d&c,const vec2d&d,vec2d*out=nullptr){
  auto ox=b-a;auto v=d-c;auto v_ox=v.Rot(ox);
  if(!v_ox.y)return false;
  auto d_ox=(d-a).Rot(ox);
  auto t=d_ox.y/v_ox.y;
  if(t<0||t>1)return false;
  auto px=d_ox.x-t*v_ox.x;
  if(out)*out=vec2d(px,0).UnRot(ox)+a;
  return px>0&&px<ox.Mag();
}
struct t_circle_from_points{
  real r;
  vec2d pos;
  t_circle_from_points(const t_trigon_vec2f&t){vector_view<vec2f> arr;arr.p=&t.a;arr.n=3;calc(arr);}
  t_circle_from_points(const t_quad&q){auto qp=q.get_points();vector_view<vec2d> arr;arr.p=&qp.a;arr.n=4;calc(arr);}
  template<class T>
  void calc(const vector_view<T>&arr){
    pos=vec2d(0,0);qap_foreach(arr,[&](decltype(arr[0])&ex,int i){pos+=ex;});pos*=1.0/arr.size();
    auto id=qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return -(vec2d(ex)-pos).SqrMag();});
    r=(vec2d(arr[id])-pos).Mag();
  }
};
static bool CD_TrigonVsQuad_slow(const t_trigon_vec2f&t,const t_quad&q){
  if(point_in_quad(t.a,q))return true;;if(point_in_quad(t.b,q))return true;;if(point_in_quad(t.c,q))return true;;
  auto qp=q.get_points();
  if(point_in_tris(qp.a,t))return true;;if(point_in_tris(qp.b,t))return true;;if(point_in_tris(qp.c,t))return true;;if(point_in_tris(qp.d,t))return true;;
  if(CD_LineVsLine(qp.a,qp.b,t.a,t.b))return true;;if(CD_LineVsLine(qp.a,qp.b,t.b,t.c))return true;;if(CD_LineVsLine(qp.a,qp.b,t.c,t.a))return true;;;if(CD_LineVsLine(qp.b,qp.c,t.a,t.b))return true;;if(CD_LineVsLine(qp.b,qp.c,t.b,t.c))return true;;if(CD_LineVsLine(qp.b,qp.c,t.c,t.a))return true;;;if(CD_LineVsLine(qp.c,qp.d,t.a,t.b))return true;;if(CD_LineVsLine(qp.c,qp.d,t.b,t.c))return true;;if(CD_LineVsLine(qp.c,qp.d,t.c,t.a))return true;;;if(CD_LineVsLine(qp.d,qp.a,t.a,t.b))return true;;if(CD_LineVsLine(qp.d,qp.a,t.b,t.c))return true;;if(CD_LineVsLine(qp.d,qp.a,t.c,t.a))return true;;;
  return false;
}
static bool CD_TrigonVsQuad(const t_trigon_vec2f&t,const t_quad&q){
  auto tc=t_circle_from_points(t);
  auto qc=t_circle_from_points(q);
  auto m=(tc.pos-qc.pos).Mag();
  if(m>(tc.r+qc.r))return false;
  return CD_TrigonVsQuad_slow(t,q);
}
template<class TYPE>static TYPE sqr(TYPE x){return x*x;}
static bool CD_TrigonVsQuad(const t_trigon_vec2f_with_circle&t,const t_quad&q,real qr){
  auto mm=t.p.sqr_dist_to(q.pos);
  if(mm>sqr(t.r+qr))return false;
  return CD_TrigonVsQuad_slow(t,q);
}
static vec3d to_vec3d(const QapColor&c){return vec3d(c.r,c.g,c.b)*(1.0/255.0);}
static vec3d vec3d_pow(const vec3d&c,real v){return vec3d(pow(c.x,v),pow(c.y,v),pow(c.z,v));}
struct t_lights_rays_color{
  int n;
  vec3d c;
  t_lights_rays_color():n(0),c(vec3d(0,0,0)){}
  vec3d avg()const{return !n?c:c*(1.0/n);}
  void add(const t_lights_rays_color&ref){n+=ref.n;c+=ref.c;}
};
struct t_pix_info{int version;int size;int x;int y;int raw_wins;;t_lights_rays_color frag,only_details,simple_frag;real ms;};
inline float fast_raycast_to_trigon(vec3f pos,int tris_id,int dir_id){
  t_raypoint nope;
  auto dir=env.dirs[dir_id];
  auto&tris=env.tris[tris_id];
  auto&a=tris.a;;auto&oy=tris.oy;;auto&oz=tris.oz;;auto&ox=tris.ox;;auto&A=tris.A;;auto&B=tris.B;;auto&C=tris.C;;
  auto py=dot(oy,pos-tris.a);
  auto inv_dy=tris.dir2inv_dy[dir_id];
  if(!inv_dy)return -1;
  auto dist=-py*inv_dy;
  if(dist<0)return -1;
  auto point=pos+(dir*dist);
  auto P=vec2f(dot(ox,point),dot(oz,point));;
  int t[3]={0,0,0};
  t[int(Sign(cross(B-A,P-A))+1)]++;;t[int(Sign(cross(C-B,P-B))+1)]++;;t[int(Sign(cross(A-C,P-C))+1)]++;;
  if(t[0]&&t[2])return -1;
  return dist;
}
struct t_fast_raycast_out{float t;int id;};
t_lights_rays_color get_lights_rays_color_in(vec3f pos,int dir_id,int from_tris_id)
{
  t_lights_rays_color out;
  t_fast_raycast_out first_dtris={-1,-1};
  auto arr=env.dir2light[dir_id].safe_get(pos);
  bool ff_passed=false;
  for(int i=0;i<arr.size();i++)
  {
    int tris_id=arr[i];
    t_fast_raycast_out rp={fast_raycast_to_trigon(pos,tris_id,dir_id),tris_id};
    if(rp.t<0)continue;
    if(bool need_find_first_dtris=!ff_passed&&first_dtris.t<0)
    {
      ff_passed=true;
      auto&darr=env.dir2info[dir_id].safe_get(pos);
      for(int i=0;i<darr.size();i++)
      {
        int dtris_id=darr[i];
        if(from_tris_id==dtris_id)continue;
        QapAssert(!is_light(dtris_id));
        t_fast_raycast_out rp={fast_raycast_to_trigon(pos,dtris_id,dir_id),dtris_id};
        if(rp.t<0)continue;
        if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
        first_dtris=rp;
      }
    }
    if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
    out.c+=to_vec3d(env.tris_colors[rp.id]);
    out.n++;
  }
  return out;
}
t_lights_rays_color fast_do_raycast_v4(const vec3f&pos,int dir_id,int&end_tris_id,vec3f&end_pos)
{
  end_tris_id=-1;
  t_lights_rays_color out;
  t_fast_raycast_out first_dtris={-1,-1};
  auto arr=env.dir2light[dir_id].safe_get(pos);
  if(bool need_find_first_dtris=true)
  {
    auto&darr=env.dir2info[dir_id].safe_get(pos);
    for(int i=0;i<darr.size();i++)
    {
      int dtris_id=darr[i];
      QapAssert(!is_light(dtris_id));
      t_fast_raycast_out rp={fast_raycast_to_trigon(pos,dtris_id,dir_id),dtris_id};
      if(rp.t<0)continue;
      if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
      first_dtris=rp;
    }
    if(first_dtris.id>=0){
      end_tris_id=first_dtris.id;
      end_pos=pos+env.dirs[dir_id]*first_dtris.t;
    }
  }
  for(int i=0;i<arr.size();i++)
  {
    int tris_id=arr[i];
    t_fast_raycast_out rp={fast_raycast_to_trigon(pos,tris_id,dir_id),tris_id};
    if(rp.t<0)continue;
    if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
    out.c+=to_vec3d(env.tris_colors[rp.id]);
    out.n++;
  }
  return out;
}
static bool segment_axis_line_projection_ray_point(const vec2d&n,real zn,const vec2d&pos,const vec2d&p,vec2d*out=nullptr){
  auto ox=n.Ort();auto a=pos+n*zn;auto d=p;auto c=pos;
  auto v=d-c;
  auto v_ox=v.Rot(ox);
  if(!v_ox.y)return false;
  auto d_ox=(d-a).Rot(ox);
  auto t=d_ox.y/v_ox.y;
  if(t<0||t>1)return false;
  return true;
}
struct t_camplane{
  vec3f pos;
  t_axis axis;
  vec3f get_vec3f(const vec3f&p){
    auto v=axis.get_vec3f(p-pos);
  }
};
static inline t_raypoint raycast_to_trigon(const vec3f&pos,const vec3f&dir,const vec3f&a,const vec3f&b,const vec3f&c){
  t_raypoint nope;
  auto center=a;
  auto n=cross(b-a,c-a).Norm();
  if(dot(n,dir)<0)return nope;
  auto oy=-n;
  auto oz=cross(dir,n).Norm();
  auto ox=cross(oz,n).Norm();
  auto py=dot(oy,pos-center);
  auto dy=dot(oy,dir);
  if(!dy)return nope;
  if(py/dy>0)return nope;
  auto point=pos-(dir*(py/dy));
  auto A=vec2d(dot(ox,a),dot(oz,a));;auto B=vec2d(dot(ox,b),dot(oz,b));;auto C=vec2d(dot(ox,c),dot(oz,c));;auto P=vec2d(dot(ox,point),dot(oz,point));;
  int t[3]={0,0,0};
  t[int(Sign(cross(B-A,P-A))+1)]++;;t[int(Sign(cross(C-B,P-B))+1)]++;;t[int(Sign(cross(A-C,P-C))+1)]++;;
  if(t[0]&&t[2])return nope;
  t_raypoint out;out.pos=point;out.n=n;out.t=fabs(py/dy);
  return out;
}
t_raypoint do_raycast_fixed(const t_photon&inp,int*tris_id=nullptr)
{
  t_raypoint out;
  auto dir=inp.dir;
  auto pos=inp.pos;
  auto&arr=env.trigons;
  for(int i=0;i<arr.size();i++)
  {
    auto&t=arr[i];
    auto rp=raycast_to_trigon(pos,dir,t.a,t.b,t.c);
    if(rp.t<0)continue;
    if(out.t>0&&out.t<rp.t)continue;
    out=rp;
    out.c=env.tris_colors[i];
    if(tris_id)*tris_id=i;
  }
  return out;
}
public:
  struct t_sphere_n{
    static const vector<vec3f>&get(){
      static vector<vec3f> arr;
      if(!arr.empty())return arr;
      string fn="sphere4096.bin";
      if(access(fn.c_str(),0)!=0){QapDebugMsg(fn+" - not found");QapNoWay();}
      QapLoadFromFile(fn,arr);
      auto O=vec3f(0,0,0);qap_foreach(arr,[&](decltype(arr[0])&ex,int i){O+=ex;});O*=1.0/arr.size();
      qap_foreach(arr,[&](decltype(arr[0])&ex,int i){ex=(ex-O).Norm();});
      if(bool need_save_after_fix=false)QapSaveToFile(fn,arr);
      return arr;
    }
  };
public:
  t_ray_env env;
  QapDev qDev;
public:
  void update_env_tris(int beg=2)
  {
    env.tris_colors.clear();
    env.trigons.clear();
    QapColor light_colors[]={
      0xff00fe00,0xfffefefe
    };
    auto arr=make_view(light_colors);
    for(int i=beg;i<qDev.IPos;i+=3)
    {
      auto&a=qDev.VBA[qDev.IBA[i-2]].get_vec3f();
      auto&b=qDev.VBA[qDev.IBA[i-1]].get_vec3f();
      auto&c=qDev.VBA[qDev.IBA[i-0]].get_vec3f();
      if(a==b||b==c||c==a)continue;
      {auto&t=qap_add_back(env.trigons);t.a=a;t.b=b;t.c=c;}
      auto color=qDev.VBA[qDev.IBA[i-0]].color;
      qap_add_back(env.tris_colors)=color;
      qap_add_back(env.is_light)=qap_includes(arr,color);
    }
  }
  void update_env(int beg=2)
  {
    auto&dirs=t_sphere_n::get();
    env=t_ray_env();
    env.dirs=dirs;
    update_env_tris(beg);
    auto&inp=env.trigons;
    for(int i=0;i<inp.size();i++)
    {
      auto&t=inp[i];
      auto&a=t.a;
      auto&b=t.b;
      auto&c=t.c;
      auto&tris=qap_add_back(env.tris);
      tris.a=a;
      tris.oy=-cross(b-a,c-a).Norm();
      tris.oz=(b-a).Norm();
      tris.ox=cross(tris.oz,tris.oy).Norm();
      tris.A=vec2f(dot(tris.ox,a),dot(tris.oz,a));;tris.B=vec2f(dot(tris.ox,b),dot(tris.oz,b));;tris.C=vec2f(dot(tris.ox,c),dot(tris.oz,c));;
      if(bool need_calc_inv_dy=true)
      {
        auto&arr=tris.dir2inv_dy;auto&td=tris.dirs;
        arr.resize(dirs.size());
        for(int i=0;i<dirs.size();i++){auto dy=dot(tris.oy,dirs[i]);arr[i]=dy?1.0/dy:0;if(dy>0)qap_add_back(td)=i;}
      }
    }
    for(int dir_id=0;dir_id<dirs.size();dir_id++){
      auto&Larr=qap_add_back(env.dir_id_to_Ltris_list);
      auto&Darr=qap_add_back(env.dir_id_to_Dtris_list);
      auto&dir=dirs[dir_id];
      qap_foreach(env.tris,[&](decltype(env.tris[0])&ex,int i){if(dot(ex.oy,dir)<0)qap_add_back(is_light(i)?Larr:Darr)=i;;});
    }
    make_raymaps();
  }
  static vector<t_pix_info> get_pix_info_v2(const string&fn)
  {
    vector<t_pix_info> out;
    FsIO<> IO(fn);
    for(int i=0;i<IO.n/sizeof(t_pix_info);i++){
      t_pix_info tmp;tmp.size=0;
      IO.LoadPOD(&tmp,sizeof(tmp));
      if(tmp.size&&tmp.size!=sizeof(tmp)){QapNoWay();break;}
      out.push_back(tmp);
    }
    return out;
  }
  vector<string> get_mask_fn_list(){
    vector<string> out;
    out.push_back("mask_basepix_log.txt");
    out.push_back(proc_log_fn(proc_id));
    return out;
  }
  vector<vec2i> get_mask(int cx,int cy,bool mute=false){
    static vector<vec2i> tmp;
    if(tmp.size())return tmp;
    for(int j=0;j<cy;j++)for(int i=0;i<cx;i++)qap_add_back(tmp)=vec2i(i,j);
    int n=0;
    auto ready=get_pix_info_v2("");
    ready.clear();
    auto fn_list=get_mask_fn_list();
    qap_foreach(fn_list,[&](decltype(fn_list[0])&ex,int i){auto t=get_pix_info_v2(ex);qap_foreach(t,[&](decltype(t[0])&ex,int i){qap_add_back(ready)=ex;});});
    vector<int> img;img.resize(cx*cy);
    qap_foreach(ready,[&](decltype(ready[0])&ex,int i){auto id=ex.x+ex.y*cx;QapAssert(qap_check_id(img,id));img[id]++;;});
    clean_if(tmp,[&](vec2i&v)->bool{auto id=v.x+v.y*cx;QapAssert(qap_check_id(img,id));return img[id];});
    if(!mute)QapUserInfo("get_mask().size() = "+IToS(tmp.size()));
    return tmp;
  }
public:
  void prepare(){
    file_put_contents("rt_proc_log_fn.txt",proc_log_fn());
    system("chmod +x ./rt_prepare.sh;./rt_prepare.sh");
  }
public:
  static string proc_log_fn(int num=-1){return string("mask_pix_log_p"+IToS(num<0?proc_id:num)+".txt");}
  static void writeln(const string&s){
    #pragma omp critical(writeln)
    {
      static auto*f=fopen(proc_log_fn().c_str(),"ab");
      QapAssert(f);
      fwrite(s.c_str(),sizeof(char),s.size(),f);
      fflush(f);
    }
  }  
  struct t_proj_info{
vec3f pos; vec3f dir; vec2d wh; real zn; void DoReset(){t_$ $;t_$::set(this->pos,$); t_$::set(this->dir,$); t_$::set(this->wh,$); t_$::set(this->zn,$);}
  typedef t_proj_info SelfClass;
  static const string qap_def_pro_get_class_name(){return "t_proj_info";}
  void operator=(SelfClass&&ref){oper_set(std::move(ref));} t_proj_info(SelfClass&&ref){DoReset();oper_set(std::move(ref));} t_proj_info(){DoReset();} t_proj_info(const SelfClass&)=default; SelfClass&operator=(const SelfClass&ref)=default; void oper_set(SelfClass&&ref){this->pos=std::move(ref.pos); this->dir=std::move(ref.dir); this->wh=std::move(ref.wh); this->zn=std::move(ref.zn);;} bool oper_eq(const SelfClass&ref)const{bool ok=true;if(this->pos!=ref.pos){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"pos"+"\ndiff:\n"+qap_def_pro_diff(this->pos,ref.pos));ok=false; } if(this->dir!=ref.dir){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"dir"+"\ndiff:\n"+qap_def_pro_diff(this->dir,ref.dir));ok=false; } if(this->wh!=ref.wh){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"wh"+"\ndiff:\n"+qap_def_pro_diff(this->wh,ref.wh));ok=false; } if(this->zn!=ref.zn){ QapDebugMsg(qap_def_pro_get_class_name()+"::"+"zn"+"\ndiff:\n"+qap_def_pro_diff(this->zn,ref.zn));ok=false; };return ok;} bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);} bool operator==(const SelfClass&ref)const{return oper_eq(ref);} bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
    struct ProxySys$${  static void Save(QapIO&IO,SelfClass&ref){ QapSave(IO,ref.pos); QapSave(IO,ref.dir); QapSave(IO,ref.wh); QapSave(IO,ref.zn);; }  static void Load(QapIO&IO,SelfClass&ref){ QapLoad(IO,ref.pos); QapLoad(IO,ref.dir); QapLoad(IO,ref.wh); QapLoad(IO,ref.zn);; } };
  };
struct t_vertex_light_scope{
  int ipos;
  int beg;
  vec3f pos;
  QapDev&qDev;
  bool enabled;
  bool drop_color;
  t_vertex_light_scope(QapDev&qDev,vec3f pos,bool enabled=true,bool drop_color=false):qDev(qDev),pos(pos),enabled(enabled),drop_color(drop_color){ipos=qDev.IPos;beg=qDev.VPos;}
  ~t_vertex_light_scope()
  {
    if(!enabled)return;
    vec3f lightpos(0,0,3);
    vector<vec3f> NA;NA.resize(qDev.VPos-beg);
    vector<int> CA;CA.resize(qDev.VPos-beg);
    for(int i=ipos;i+2<qDev.IPos;i+=3){
      auto&A=qDev.IBA[i+0];auto&a=qDev.VBA[A].get_vec3f();auto&B=qDev.IBA[i+1];auto&b=qDev.VBA[B].get_vec3f();auto&C=qDev.IBA[i+2];auto&c=qDev.VBA[C].get_vec3f();
      auto n=-cross(b-a,c-a).Norm();
      NA[A-beg]+=n;CA[A-beg]++;NA[B-beg]+=n;CA[B-beg]++;NA[C-beg]+=n;CA[C-beg]++;
    }
    qap_foreach(NA,[&](decltype(NA[0])&ex,int i){ex*=(1.0/CA[i]);});
    for(int i=beg;i<qDev.VPos;i++)
    {
      auto&v=qDev.VBA[i];
      auto&p=v.get_vec3f();
      QapColor c0,c1;
      {
        auto dir=p-pos;
        auto n=NA[i-beg];
        auto k=dot(-dir.Norm(),n.Norm());if(k<0)k=0;if(k>1)k=1;
        c0=QapColor::Mix(0xffa8a8a8*0+0xff000000,0xffffffff,k);
      }
      {
        auto dir=p-lightpos;
        auto n=NA[i-beg];
        auto k=dot(-dir.Norm(),n.Norm());if(k<0)k=0;if(k>1)k=1;
        c1=QapColor::Mix(0xffa8a8a8,0xffffffff,k);
      }
      auto out=QapColor::HalfMix(c0,c1);
      v.color=drop_color?out:QapColor::HalfMix(out,v.color);
    }
  }
};
struct t_mesh{
  vector<vec3f> VA;
  vector<int> IA;
  vector<QapColor> CA;
  vector<QapColor> FCA;
  void make_vertex_unique()
  {
    vector<int> U;U.resize(VA.size());auto out=VA;QapAssert(FCA.size());CA.resize(IA.size());
    for(int i=0;i+2<IA.size();i+=3)
    {
      auto color=FCA[i/3];
      auto&A=IA[i+0];auto&a=VA[A];if(U[A]++){A=out.size();qap_add_back(out)=a;}CA[A]=color;auto&B=IA[i+1];auto&b=VA[B];if(U[B]++){B=out.size();qap_add_back(out)=b;}CA[B]=color;auto&C=IA[i+2];auto&c=VA[C];if(U[C]++){C=out.size();qap_add_back(out)=c;}CA[C]=color;
    }
    VA=out;
  }
  void draw_without_ca(QapDev&qDev)
  {
    auto base=qDev.VPos;
    for(int i=0;i<VA.size();i++)qDev.AddVertex(VA[i]);
    for(int i=0;i<IA.size();i++)qDev.AddIndex(base+IA[i]);
  }
  void draw(QapDev&qDev)
  {
    auto base=qDev.VPos;
    if(CA.size()!=VA.size()){
      QapDebugMsg(IToS(CA.size())+"\n"+IToS(VA.size()));
      draw_without_ca(qDev);
      return;
    }
    for(int i=0;i<VA.size();i++){
      qDev.color=CA[i];
      qDev.AddVertex(VA[i]);
    }
    for(int i=0;i<IA.size();i++)qDev.AddIndex(base+IA[i]);
  }
};
struct t_obj_face_item{int id;int tid;};
static t_obj_face_item get_obj_face_item(const string&s){
  if(string::npos==s.rfind('/')){
    t_obj_face_item out={SToI(s),-1};
    return out;
  }
  auto t=split(s,"/");
  t_obj_face_item out={SToI(t[0]),SToI(t[1])};
  return out;
}
struct t_obj_mtl_item{
  string name;
  vec3d Ka;
  vec3d Kd;
  QapColor get_diffuse()const{
    auto c=Kd*255;
    return QapColor(c.x,c.y,c.z);
  }
};
struct t_obj_mtllib{
  vector<t_obj_mtl_item> arr;
  t_obj_mtl_item*get(string value) { t_obj_mtl_item*p=nullptr; for(int i=0;i<arr.size();i++){ auto&ex=arr[i]; if(ex.name!=value)continue; QapAssert(!p); p=&ex; } if(!p){p=&qap_add_back(arr);p->name=value;} return p; };
  void load(const string&fn){
    auto s=file_get_contents(fn);
    s=join(split(s,"\t"),"");
    s=join(split(s,"\r"),"");
    s=join(split(s," \n"),"\n");
    auto lines=split(s,"\n");
    t_obj_mtl_item*p=nullptr;
    for(int i=0;i<lines.size();i++){
      auto&ex=lines[i];
      auto t=split(ex," ");
      if(t.empty())continue;
      if(t[0]=="newmtl"){
        if(t.size()!=2)QapDebugMsg("hm...\n"+ex);
        p=get(t[1]);
      }
      if(!p)continue;
      if(t[0]=="Ka"){
        QapAssert(t.size()==4);
        auto&k=p->Ka;
        for(int i=0;i<3;i++)(&k.x)[i]=SToF(t[1+i]);
      }
      if(t[0]=="Kd"){
        QapAssert(t.size()==4);
        auto&k=p->Kd;
        for(int i=0;i<3;i++)(&k.x)[i]=SToF(t[1+i]);
      }
    }
  }
};
static string get_fullname_of_near_file(const string&obj_fn,const string&mtl_fn)
{
  if(split(obj_fn,"/").size()!=1)QapNoWay();
  if(split(obj_fn,"\\").size()!=1)QapNoWay();
  return mtl_fn;
}
void draw_obj()
{
  static t_mesh out;
  QapColor diffuse=0xFFffffff;
  if(out.IA.empty())
  {
    t_obj_mtllib lib;
    string fn=get_obj_fn();
    string mtllib;
    auto s=file_get_contents(fn);
    s=join(split(s,"\t"),"");
    s=join(split(s,"\r"),"");
    s=join(split(s,"v  "),"v ");
    s=join(split(s," \n"),"\n");
    auto arr=split(s,"\n");
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto t=split(ex," ");
      if(t.empty())continue;
      if(t[0]=="mtllib"){
        if(t.size()!=2)QapDebugMsg("hm...\n"+ex);
        mtllib=t[1];
        lib.load(get_fullname_of_near_file(fn,mtllib));
      }
      if(t[0]=="usemtl"){
        if(t.size()!=2)QapDebugMsg("hm...\n"+ex);
        auto*p=lib.get(t[1]);
        diffuse=p->get_diffuse();
      }
      if(t.size()==4){
        if(t[0]=="v"){auto*f=&qap_add_back(out.VA).x;for(int i=0;i<3;i++)f[i]=SToF(t[1+i]);continue;}
      }
      if(t[0]=="f"&&t.size()>3)
      {
        vector<int> arr;
        qap_add_back(out.FCA)=diffuse;
        for(int i=1;i<t.size();i++)qap_add_back(arr)=get_obj_face_item(t[i]).id-1;
        for(int i=2;i<arr.size();i++){
          qap_add_back(out.IA)=arr[0];
          qap_add_back(out.IA)=arr[i-1];
          qap_add_back(out.IA)=arr[i-0];
        }
        continue;
      }
      if(t[0]=="v"||t[0]=="f")QapDebugMsg("hm...\n"+ex);
    }
    if(out.VA.empty())return;
    auto id=qap_minval_id_for_vec(out.VA,[&](decltype(out.VA[0])&ex,int i){return -ex.SqrMag();});
    auto m=out.VA[id].Mag();auto k=5.0/m;
    if(fn=="sponza.obj"){
      qap_foreach(out.VA,[&](decltype(out.VA[0])&ex,int i){ex*=k; ex.z*=-1;;});
    }else{
    qap_foreach(out.VA,[&](decltype(out.VA[0])&ex,int i){ex*=k;std::swap(ex.z,ex.y);});
    }
    out.make_vertex_unique();
  }
  out.draw(qDev);
}
void DrawScene()
{
  qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,1.7,00),vec3f(5,0.1,5)); 
  draw_obj();
}
  static const int proc_id=700;
  static int get_raymaps_limit(){return 64;}
  static string get_rayenv_fn(int limit){
    string fn="rayenv_L"+IToS(limit)+"_scene_v42.bin";
    return fn;
  }
  string get_obj_fn(){
    string fn="full_likesponza.obj";
    fn="tb5.obj";
    return fn;
  }
  void main()
  {
    prepare();
    qDev.Init(1024*64,1024*64*3);
    qDev.BeginBatch();
    DrawScene();
    update_env();
    t_proj_info log;
    string fn="proj_info.bin";
    if(access(fn.c_str(),0)!=0){
      QapDebugMsg(fn+" - not found");
      return;
    }
    QapLoadFromFile(fn,log);
    bool need_clamp_bounds=false;
    int msaa_q=8*0;bool only_edges=0||msaa_q;bool only_colorless_edges=false;
    real pn=1;bool two_bounce=1;bool need_writeln=two_bounce;
    auto sm=GetScreenMode();
    auto n=log.dir;
    auto wh=log.wh;
    auto up=vec3f(0,1,0);
    auto ox=cross(up,n).Norm();
    auto oy=cross(ox,n).Norm();
    auto pwh=vec2d(pn/sm.W,pn/sm.H).Mul(wh);
    auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);
    auto center=log.pos+n*log.zn;
    vector<vec3d> frags;
    frags.resize(cx*cy);
auto heds=env.dirs.size()/2;
struct t_info_at{
  int tris_id;
  real t;
  vec3f dir;
};
t_info_at info_at_by_def={-2,0};
vector<t_info_at> cell2tris_id;cell2tris_id.resize(cx*cy,info_at_by_def);
auto info_at=[&](int i,int j)->t_info_at
{
  int x=j;int y=i;
  bool wrong_addr=false;
  if(x<0||x>=cx||y<0||y>=cy)wrong_addr=true;
  if(!wrong_addr){
    auto&cell=cell2tris_id[x+y*cx];
    if(cell.tris_id!=-2)return cell;
  }
  auto offset=vec2d(x-cx/2,y-cy/2).Mul(pwh)*2+pwh;
  auto quad_center=center+ox*offset.x+oy*offset.y;
  t_photon inp;inp.pos=log.pos;inp.dir=(quad_center-log.pos).Norm();
  t_info_at out={-1,0};
  out.t=do_raycast_fixed(inp,&out.tris_id).t;
  out.dir=inp.dir;
  if(!wrong_addr)cell2tris_id[x+y*cx]=out;
  return out;
};
auto get_vec3d_color=[&](const vec3f&quad_center,int x,int y,t_pix_info*pinfo)->vec3d
{
  t_photon inp;inp.pos=log.pos;inp.dir=(quad_center-log.pos).Norm();
  t_lights_rays_color frag;
  t_lights_rays_color only_details;
  t_lights_rays_color simple_frag;
  int raw_wins=0;
  QapClock clock;
  for(;;)
  {
    int tris_id=-1;
    auto out=do_raycast_fixed(inp,&tris_id);
    if(tris_id<0)break;
    if(is_light(tris_id)){
      int gg=1;
      frag.n=1;
      frag.c=to_vec3d(env.tris_colors[tris_id])*(two_bounce?sqr(heds):heds);
      if(need_writeln)simple_frag.add(frag);
      break;
    }
    if(bool trigon_as_light_source=true)if(out.t>=0)
    {
      auto&td=two_bounce||0?env.tris[tris_id].dirs:env.tris[tris_id].light_dirs;
      int td_size=env.tris[tris_id].dirs.size();
      {for(int k=0;k<td.size();k++){
        auto dir_id=td[k];
        if(two_bounce)
        {
          int tris_id=-1;vec3f end_pos;
          auto LRC=fast_do_raycast_v4(out.pos,dir_id,tris_id,end_pos);
          LRC.c*=heds;
          frag.add(LRC);
          if(need_writeln)simple_frag.add(LRC);
          if(tris_id>=0)
          {
            t_lights_rays_color tris_frag;
            auto&td=env.tris[tris_id].light_dirs;
            {for(int k=0;k<td.size();k++){
              auto dir_id=td[k];
              auto LRC=get_lights_rays_color_in(end_pos,dir_id,tris_id);
              tris_frag.add(LRC);
              if(LRC.n)raw_wins++;
            }}
            tris_frag.n=1;
            tris_frag.c=(to_vec3d(env.tris_colors[tris_id])).Mul(tris_frag.c);
            only_details.add(tris_frag);
            frag.add(tris_frag);
          }
        }else{
          auto LRC=get_lights_rays_color_in(out.pos,dir_id,tris_id);
          frag.add(LRC);
        }
      }}
      auto tc=(to_vec3d(env.tris_colors[tris_id]));
      frag.c=tc.Mul(frag.c);
      if(need_writeln)simple_frag.c=tc.Mul(simple_frag.c);
    }
    break;
  }
  if(pinfo)
  {
    auto ms=clock.MS();
    auto&info=*pinfo;int size=sizeof(info);int version='v1';
    info.version=version;info.size=size;info.x=x;info.y=y;info.frag=frag;info.only_details=only_details;info.simple_frag=simple_frag;info.raw_wins=raw_wins;info.ms=ms;
  }
  return frag.c;
};
auto get_msaa_mass=[&](const vec2i&coords)->int{
  int fuf[9]={-1};vector_view<int> fmp=make_view(fuf);fmp.n=0;
  vec3f buf[9]={};vector_view<vec3f> tmp=make_view(buf);tmp.n=0;
  t_info_at ptr2info[9];{for(int i=0;i<9;i++)ptr2info[i]=info_at_by_def;}
  int ptr=-1;
  for(int dy=-1;dy<=+1;dy++)for(int dx=-1;dx<=+1;dx++){
    auto c=vec2i(dx,dy)+coords;ptr++;
    if(c.x<0||c.x>=cx||c.y<0||c.y>=cy)continue;
    auto info=info_at(c.y,c.x);ptr2info[ptr]=info;
    {auto v=info.tris_id;if(!qap_includes(fmp,v))fuf[fmp.n++]=v;}
    if(bool use_oy=true)
    {
      auto id=info.tris_id;auto v=id<0?vec3f(0,0,0):env.tris[id].oy;
      bool found=false;qap_foreach(tmp,[&](decltype(tmp[0])&ex,int i){if((ex-v).SqrMag()<1e-9)found=true;;});
      if(found)continue;
      buf[tmp.n++]=v;
    }
  }
  const int cx=3;const real esp=1e-5;
  if(fmp.size()>1)for(int i=0;i<3;i++)
  {
    {
      ptr=0+cx*i;auto&a=ptr2info[ptr];if(a.tris_id<0)continue;auto&an=env.tris[a.tris_id].oy;ptr=1+cx*i;auto&b=ptr2info[ptr];if(b.tris_id<0)continue;auto&bn=env.tris[b.tris_id].oy;ptr=2+cx*i;auto&c=ptr2info[ptr];if(c.tris_id<0)continue;auto&cn=env.tris[c.tris_id].oy;;
      {auto h=dot(-b.dir*b.t,an);auto v=dot(-a.dir,an);QapAssert(v);auto bt=h/v;QapAssert(bt>=0);if(fabs(a.t-bt)>esp)return 2;};
      {auto h=dot(-b.dir*b.t,an);auto v=dot(-c.dir,an);QapAssert(v);auto bt=h/v;QapAssert(bt>=0);if(fabs(c.t-bt)>esp)return 2;};
    }
    {
      ptr=i+cx*0;auto&a=ptr2info[ptr];if(a.tris_id<0)continue;auto&an=env.tris[a.tris_id].oy;;ptr=i+cx*1;auto&b=ptr2info[ptr];if(b.tris_id<0)continue;auto&bn=env.tris[b.tris_id].oy;;ptr=i+cx*2;auto&c=ptr2info[ptr];if(c.tris_id<0)continue;auto&cn=env.tris[c.tris_id].oy;;;
      {auto h=dot(-b.dir*b.t,an);auto v=dot(-a.dir,an);QapAssert(v);auto bt=h/v;QapAssert(bt>=0);if(fabs(a.t-bt)>esp)return 2;};
      {auto h=dot(-b.dir*b.t,an);auto v=dot(-c.dir,an);QapAssert(v);auto bt=h/v;QapAssert(bt>=0);if(fabs(c.t-bt)>esp)return 2;};
    }
  }
  return std::min<int>(2,tmp.size());
};
auto f=[&](int i,int j){
  t_pix_info info;bool subpixel=msaa_q;
  int x=j;int y=i;
  if(x<0||x>=cx||y<0||y>=cy)QapDebugMsg("look like point in mask[mask_id] go out of bounds");
  auto def_color=[&]()->vec3d{
    auto offset=vec2d(x-cx/2,y-cy/2).Mul(pwh)*2+pwh;
    auto quad_center=center+ox*offset.x+oy*offset.y;
    auto out=get_vec3d_color(quad_center,x,y,&info);
    if(need_writeln)writeln(string((char*)(void*)&info,sizeof(info)));
    return out;
  };
  if(!msaa_q&&!only_edges)
  {
    frags[x+y*cx]=def_color();
    return;
  }
  auto coords=vec2i(x,y);
  auto mm=get_msaa_mass(coords);
  if(only_colorless_edges)
  {
    frags[x+y*cx]=vec3d(1,1,1)*mm;
    return;
  }
  if(only_edges&&!msaa_q)
  {
    if(mm>1)frags[x+y*cx]=def_color();
    return;
  }
  if(mm<=1)
  {
    frags[x+y*cx]=def_color();
    return;
  }
  QapClock clock;
  vec3d accum;int n=0;int q=msaa_q/2;const real inv=1.0/(q+q);
  for(int dy=-q+1;dy<=+q;dy++)for(int dx=-q+1;dx<=+q;dx++){
    auto offset=vec2d(x+dx*inv-cx/2,y+dy*inv-cy/2).Mul(pwh)*2+pwh;
    auto quad_center=center+ox*offset.x+oy*offset.y;
    accum+=get_vec3d_color(quad_center,x,y,nullptr);n++;
  }
  frags[x+y*cx]=accum*(1.0/n);
  if(need_writeln)
  {
    auto ms=clock.MS();
    int raw_wins=0;
    t_lights_rays_color frag;frag.c=accum*(1.0/n);
    t_lights_rays_color only_details;
    t_lights_rays_color simple_frag;
    t_pix_info info;int size=sizeof(info);int version='v1';
    info.version=version;info.size=size;info.x=x;info.y=y;info.frag=frag;info.only_details=only_details;info.simple_frag=simple_frag;info.raw_wins=raw_wins;info.ms=ms;
    writeln(string((char*)(void*)&info,sizeof(info)));
  }
};
    auto mask=get_mask(cx,cy);int mask_size=mask.size();
    auto cur_num_of_cores=5;
    auto ncpu=4+5+5+2+2;
    QapUserInfo("mask_size = "+IToS(mask_size));
    real mask_id_pos=SToF(file_get_contents("mask_id_pos.txt"));
    QapUserInfo("mask_id_pos = "+FToS(mask_id_pos));
    if(mask_id_pos<0)mask_id_pos=0;
    QapUserInfo("mask_id = "+IToS(int(mask_id_pos*mask_size)));
    #pragma omp parallel for schedule(dynamic,16)
    for(int mask_id=int(mask_id_pos*mask_size);mask_id<mask_size;mask_id++)f(mask[mask_id].y,mask[mask_id].x);
    render(cx,cy,frags,("p"+IToS(proc_id)+"pn"+IToS(pn)+"_msaa"+IToS(msaa_q)+"_tb"+IToS(two_bounce)+"e"+IToS(only_edges)+".png").c_str());
  }
  void render(int cx,int cy,const vector<vec3d>&frags,const char*fn){
    static const real inv_gamma=1.0/2.2;
    auto arr=frags;
    qap_foreach(arr,[&](decltype(arr[0])&ex,int i){ex=vec3d_pow(ex,inv_gamma);});
    arr=do_clamp_upper_bound(do_clamp_bottom_bound(arr));
    arr=hdr_pixmap(arr,0.0,255.0);
    vector<QapColor> out;out.resize(cx*cy);
    qap_foreach(arr,[&](decltype(arr[0])&ex,int i){out[i]=QapColor(ex.x,ex.y,ex.z);});
    foo(cx,cy,out,fn);
  }
  void render_raw(int cx,int cy,const vector<vec3d>&frags,const char*fn){
    vector<QapColor> out;out.resize(cx*cy);
    qap_foreach(frags,[&](decltype(frags[0])&ex,int i){out[i]=QapColor(ex.x,ex.y,ex.z);});
    foo(cx,cy,out,fn);
  }
  void foo(int cx,int cy,const vector<QapColor>&arr,const char*fn)
  {
    unsigned width = cx, height = cy;
    std::vector<unsigned char> image;
    image.resize(width * height * 4);
    for(unsigned y = 0; y < height; y++)
    for(unsigned x = 0; x < width; x++)
    {
      auto c=arr[x+cx*y];
      auto&out=*(QapColor*)(void*)&image[4 * width * y + 4 * x + 0];
      out=c.swap_rg();
    }
    encodeOneStep(fn, image, width, height);
  }
  static void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
  {
    unsigned error = lodepng::encode(filename, image, width, height);
    if(error)QapDebugMsg("encoder error "+IToS(error)+": "+lodepng_error_text(error));
  }
};
int main(){
  t_app app;
  app.main();
  return 0;
}
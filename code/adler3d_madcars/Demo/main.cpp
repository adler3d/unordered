//*#include "main.i.cpp"
#if(1)
#define NEED_APPLY_UPD()if(1)
//#define AdlerOMP
//#undef Adler
#ifdef Adler
#define ADLER_DEBUG(CODE)CODE;
#else
#define ADLER_DEBUG(CODE)
#endif
#pragma region before_plan_generator
#pragma region before_app

void qap_cpBodyActivate_bef();
void qap_cpBodyActivate_aft();

#pragma region before_t_score

#pragma region qapstd

// ###_BUILD_TIME_###
//#undef Adler
#define QAP_DEBUG

#ifdef Adler
  //#define _ITERATOR_DEBUG_LEVEL 0
  #ifndef CLANG_QAPLITE
  #include "qaplite\QapLite.h"
  #endif
  #include "qaplite\TQapGameV2.inl"
  #include "qaplite\perf_sys.inl"
#else
  #ifdef WIN32
    #define NOMINMAX
    #include <Windows.h>
    class QapClock
    {
    public:
      INT64 freq,beg,tmp;
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
  #else
    #include <unistd.h>
    #include <sys/time.h>
    //struct  QapClock{double MS(){return 0;}};
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
        //timespec ts;clock_gettime(CLOCK_MONOTONIC,&ts);
        return 0;
      }
    };
  #endif
  #define QAP_PERF(NAME)
  #define QAP_PERF_CODE(CODE){CODE;}
  #define NO_QAP_PERF_CODE(CODE){CODE;}
#endif

#define _ALLOW_KEYWORD_MACROS
#if(!defined(_DEBUG)&&!defined(Adler))
#ifndef QAP_MSVC
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wreorder"
#pragma warning(push,1)
#endif
#include <cstring>
#endif
#ifndef NOMINMAX
  #define NOMINMAX
#endif
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <stack>
#include <set>
#include <memory>
#include <thread>
#include <mutex>
#include <fstream>
#include <bitset>
#include <atomic>
#include <map>
using std::vector;
using std::string;
//#undef Adler

#define MemoryBarrier()atomic_signal_fence(memory_order_acq_rel);

static bool unix_SaveFile(const string&FN,const string&mem)
{
  using namespace std;
  fstream f;
  f.open(FN.c_str(),ios::out|ios::binary);
  if(!f)return false;
  if(!mem.empty())f.write(&mem[0],mem.size());
  f.flush();
  f.close();
  return true;
};

#ifdef Adler
  #ifndef QAP_LITE_H
  #include <Windows.h>
  inline string IToS(const int&val){char c[16];_itoa_s(val,c,10);return string(c);}
  inline string FToS(const double&val){char c[64];if(abs(val)>1e9){_snprintf_s(c,32,32,"%e",val);}else{sprintf_s(c,"%f",val);}return string(c);}
  inline string FToS2(const double&val){char c[64];if(abs(val)>1e9){_snprintf_s(c,32,32,"%e",val);}else{sprintf_s(c,"%.2f",val);}return string(c);}
  static bool IsKeyDown(int vKey){int i=GetAsyncKeyState(vKey);return i<0;}
  #define KB_CODE(){auto mwta=game.getWizardMaxTurnAngle();if(IsKeyDown('Q'))move.setTurn(-mwta);if(IsKeyDown('E'))move.setTurn(+mwta);if(IsKeyDown('W'))move.setSpeed(+100);if(IsKeyDown('S'))move.setSpeed(-100);if(IsKeyDown('D'))move.setStrafeSpeed(+100);if(IsKeyDown('A'))move.setStrafeSpeed(-100);}
  static bool file_put_contents(const string&FN,const string&mem)
  {
    using namespace std;
    auto*f=fopen(FN.c_str(),"w+b");
    if(!f)return false;
    if(!mem.empty())fwrite(&mem[0],mem.size(),1,f);
    fclose(f);
    return true;
  };
  #endif
#else
  void KB_CODE(){}
  //#define file_put_contents(...)(true)
  static bool file_put_contents(const string&FN,const string&mem){std::fstream f(FN,std::ios::out|std::ios::trunc);f<<mem;return true;}
  string file_get_contents(const string&fn){
    std::ifstream file(fn);
    return std::string((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
  }
#endif
  
#ifndef QAP_LITE_H
  #ifdef UNIX_WITH_FS
    #define QapDebugMsg(MSG){printf("QapDebugMsg :: %s:%i :: %s\n",__FILE__,__LINE__,string(MSG).c_str());fflush(stdout);}//__debugbreak();
    #define QapAssert(COND)if(!(COND)){printf("QapAssert :: %s:%i :: %s\n",__FILE__,__LINE__,#COND);fflush(stdout);exit(0);}//__debugbreak();
    #define QapNoWay(){printf("QapNoWay :: %s:%i\n",__FILE__,__LINE__);fflush(stdout);exit(0);}//__debugbreak();
  #else
    #define QapDebugMsg(MSG)
    #define QapAssert(COND)
    #define QapNoWay()
  #endif
#endif

template<class TYPE,class FUNC>
void clean_if_v2(vector<TYPE>&Arr,FUNC&&Pred)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(Pred(ex,i))continue;
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
void qap_sort_v2(vector<TYPE>&arr,FUNC&&func){std::sort(arr.begin(),arr.end(),func);}

#if(__cplusplus>=201402L)
  #define QAP_SORT_BY_FIELD(ARR,FIELD,ELEM_TYPE)qap_sort_v2(ARR,[](const auto&a,const auto&b)->bool{return a.FIELD<b.FIELD;})
#else
  #ifdef Adler
    #define QAP_SORT_BY_FIELD(ARR,FIELD,ELEM_TYPE)qap_sort_v2(ARR,[](const decltype((ARR)[0])&&a,const decltype((ARR)[0])&&b)->bool{return a.FIELD<b.FIELD;})
  #else
    #define QAP_SORT_BY_FIELD(ARR,FIELD,ELEM_TYPE)qap_sort_v2(ARR,[](const ELEM_TYPE&a,const ELEM_TYPE&b)->bool{return a.FIELD<b.FIELD;})
  #endif
#endif

#define DEF_PRO_SORT_BY_FIELD(sort_by_field,TYPE,FIELD)\
  struct t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD{\
    static int __cdecl cmp_func(const void*a,const void*b){return cmp(*(TYPE*)a,*(TYPE*)b);}\
    static int cmp(const TYPE&a,const TYPE&b){return a.FIELD-b.FIELD;}\
  };\
  static void sort_by_field(vector<TYPE>&arr){\
    if(arr.empty())return;\
    std::qsort(&arr[0],arr.size(),sizeof(TYPE),t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD::cmp_func);\
  }

#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(rettype,adduni,arr,field_type,field)\
  rettype*adduni(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    if(!p){p=&qap_add_back(arr);p->field=value;}\
    return p;\
  }

template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  decltype(func(arr[0],0)) val;int id=-1;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(!i||tmp<val){
      val=tmp;id=i;
    }
  }
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  decltype(func(arr[0],0)) val;int id=-1;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(!i||tmp<val){
      val=tmp;id=i;
    }
  }
  return id;
}
#ifndef Adler
#include <array>
using std::array;
#include "qaplite/vector_view.inl"
#endif
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector_view<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  decltype(func(arr[0],0)) val;int id=-1;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(!i||tmp<val){
      val=tmp;id=i;
    }
  }
  return id;
}

template<class TYPE>
static void operator+=(vector<TYPE>&dest,const vector<TYPE>&arr){
  for(int i=0;i<arr.size();i++){
    dest.push_back(arr[i]);
  }
}

template<class TYPE>int qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}
template<class TYPE>int qap_includes_v2(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return i;}return -1;}

#define QAP_MINVAL_ID_OF_VEC(arr,code)qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return code;})

template<class TYPE,class FUNC>void qap_foreach(TYPE&&arr,FUNC func){auto n=arr.size();for(int i=0;i<n;i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const TYPE&arr,FUNC func){auto n=arr.size();for(int i=0;i<n;i++)func(arr[i],i);}
#define QAP_FOREACH(arr,code)qap_foreach(arr,[&](decltype(arr[0])&ex,int i){code;})

#ifndef QAP_LITE_H
static double sqr(double x){return x*x;}

inline int SToI(const string&S){return std::stoi(S,nullptr,10);};

inline string IToS(const int&v){return std::to_string(v);};
inline string FToS(const double&v){return std::to_string(v);};

template<class TYPE>void reverse(vector<TYPE>&loop){auto c=loop.size();for(int i=0;i<c/2;i++)std::swap(loop[c-1-i],loop[i]);}
template<class TYPE>void qap_sort(vector<TYPE>&arr){std::sort(arr.begin(),arr.end());}

template<class TYPE>
static bool qap_add_unique_val(vector<TYPE>&arr,const TYPE&value){
  if(qap_includes(arr,value))return false;
  arr.push_back(value);
  return true;
}

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

template<class TYPE>
static bool qap_find_val_once(const vector<TYPE>&arr,const TYPE&val){
  for(int i=0;i<arr.size();i++)if(val==arr[i])return true;
  return false;
}
template<class TYPE>
static bool qap_find_val_once(const std::set<TYPE>&arr,const TYPE&val){
  auto it=arr.find(val);
  return it!=arr.end();
}

template<typename TYPE,size_t COUNT>inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}

template<class TYPE>static bool qap_check_id(const vector<TYPE>&arr,int id){return id>=0&&id<arr.size();}
template<class TYPE,class FUNC>void clean_if(vector<TYPE>&Arr,FUNC&&Pred){int last=0;for(int i=0;i<Arr.size();i++){auto&ex=Arr[i];if(Pred(ex))continue;if(last!=i){auto&ax=Arr[last];ax=std::move(ex);}last++;}if(last==Arr.size())return;Arr.resize(last);}

template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr){arr.resize(arr.size()+1);return arr.back();}
template<typename TYPE>TYPE Sign(TYPE value){return (value>0)?TYPE(+1):TYPE(value<0?-1:0);}

typedef double real;const real Pi=3.14159265;const real Pi2=Pi*2;const real PiD2=Pi/2;const real PiD4=Pi/4;
template<class TYPE>inline TYPE Clamp(const TYPE&v,const TYPE&a,const TYPE&b){return std::max(a,std::min(v, b));}
template<typename TYPE>inline TYPE Lerp(const TYPE&A,const TYPE&B,const real&v){return A+(B-A)*v;}

class vec2d{
public:
  real x;real y;
  vec2d():x(0.0),y(0.0) {}
  vec2d(const real&x,const real&y):x(x),y(y) {}
  vec2d(const vec2d&v):x(v.x),y(v.y) {}
public:
  vec2d&operator=(const vec2d&v){x=v.x;y=v.y;return *this;}
  vec2d operator+()const{return *this;}
  vec2d operator-()const{return vec2d(-x,-y);}
  vec2d&operator+=(const vec2d&v){x+=v.x;y +=v.y;return *this;}
  vec2d&operator-=(const vec2d&v){x-=v.x; y-=v.y;return *this;}
  vec2d&operator*=(const real&f){x*=f;y*=f;return *this;}
  vec2d&operator/=(const real&f){x/=f;y/=f;return *this;}
public:
  vec2d Rot(const vec2d&OX)const{real M=OX.Mag();return vec2d(((x*+OX.x)+(y*OX.y))/M,((x*-OX.y)+(y*OX.x))/M);}
  vec2d UnRot(const vec2d&OX)const{real M=OX.Mag();if(M==0.0f){return vec2d(0,0);};return vec2d(((x*OX.x)+(y*-OX.y))/M,((x*OX.y)+(y*+OX.x))/M);}
  vec2d Ort()const{return vec2d(-y,x);}
  vec2d Norm()const{if((x==0)&&(y==0)){return vec2d(0,0);}return vec2d(x/this->Mag(),y/this->Mag());}
  vec2d SetMag(const real&val)const{return this->Norm().Mul(vec2d(val,val));}
  vec2d Mul(const vec2d&v)const{return vec2d(x*v.x,y*v.y);}
  vec2d Div(const vec2d&v)const{return vec2d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y);}
  real GetAng()const{return atan2(y,x);}
  real Mag()const{return sqrt(x*x+y*y);}
  real SqrMag()const{return x*x+y*y;}
public:
  real dist_to(const vec2d&p)const{return vec2d(p.x-x,p.y-y).Mag();}
  real sqr_dist_to(const vec2d&p)const{return vec2d(p.x-x,p.y-y).SqrMag();}
  bool dist_to_point_less_that_r(const vec2d&p,real r)const{return vec2d(p.x-x,p.y-y).SqrMag()<r*r;}
public:
  static vec2d min(const vec2d&a,const vec2d&b){return vec2d(std::min(a.x,b.x),std::min(a.y,b.y));}
  static vec2d max(const vec2d&a,const vec2d&b){return vec2d(std::max(a.x,b.x),std::max(a.y,b.y));}
  static void comin(vec2d&a,const vec2d&b){a=min(a,b);}
  static void comax(vec2d&a,const vec2d&b){a=max(a,b);}
  static vec2d sign(const vec2d&p){return vec2d(Sign(p.x),Sign(p.y));}
public:
  inline static real dot(const vec2d&a,const vec2d&b){return a.x*b.x+a.y*b.y;}
  inline static real cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
  vec2d fabs()const{return vec2d(::fabs(x),::fabs(y));}
  real max()const{return std::max(x,y);}
  real min()const{return std::min(x,y);}
  vec2d inv_x()const{return vec2d(-x,+y);}
  vec2d inv_y()const{return vec2d(+x,-y);}
  //string dump()const{return "{\"X\":"+FToS(x)+",\"Y\":"+FToS(y)+"}";}
};
vec2d operator+(const vec2d&u,const vec2d&v){return vec2d(u.x+v.x,u.y+v.y);}
vec2d operator-(const vec2d&u,const vec2d&v){return vec2d(u.x-v.x,u.y-v.y);}
vec2d operator*(const vec2d&u,const real&v){return vec2d(u.x*v,u.y*v);}
vec2d operator*(const real&u,const vec2d&v){return vec2d(u*v.x,u*v.y);}
bool operator==(const vec2d&u,const vec2d&v){return (u.x==v.x)&&(u.y==v.y);}
bool operator!=(const vec2d&u,const vec2d&v){return !(u==v);}

inline vec2d Vec2dEx(const real&ang,const real&mag){return vec2d(cos(ang)*mag,sin(ang)*mag);}


class vec2i{
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
  static vec2i fromVec2d(const vec2d&v){return vec2i(int(v.x),int(v.y));}
  vec2i Ort()const{return vec2i(-y,x);}
  vec2i Mul(const vec2i&v)const{return vec2i(x*v.x,y*v.y);}
  static vec2i sign(const vec2i&p){return vec2i(Sign(p.x),Sign(p.y));}
  static vec2i sign(const vec2d&p){return vec2i(Sign(p.x),Sign(p.y));}
};

static vec2i tovec2i(const vec2d&p){return vec2i(p.x,p.y);}
#endif

#include <iostream>
#include <string>
#include "chipmunk.inl"

struct i_two_stream{
  virtual string getline()=0;
  virtual bool eof()=0;
  virtual void send_with_endl(const string&s)=0;
};

struct t_cpp_style_io:i_two_stream{
  string getline(){string s;std::getline(std::cin,s);return s;}
  bool eof(){return false;}
  void send_with_endl(const string&s){std::cout<<s<<std::endl;}
};

static vector<FILE*> g_files;

template<size_t N=1024*1024>
struct t_two_stream:i_two_stream{
  FILE*p=nullptr;
  FILE*pout=nullptr;
  char buff[N];
  void init(){p=stdin;pout=stdout;}
  string getline(){
    if(!p)return "";
    auto out=fgets(buff,sizeof(buff),p);
    if(!out)return "";
    return out;
  }
  bool eof(){return feof(p);}
  void do_fopen(const char*fn,const char*mode){
    #ifdef Adler
    fopen_s(&p,fn,mode);
    qap_add_back(g_files)=p;
    #else
    p=fopen(fn,mode);
    #endif
  }
  void do_popen(const char*proc,const char*mode){
    #ifdef Adler
    p=_popen(proc,mode);
    qap_add_back(g_files)=p;
    #else
    p=popen(proc,mode);
    #endif
  }
  void send_with_endl(const string&s){
    auto s_with_endl=s+"\n";
    fwrite(s_with_endl.c_str(),1,s_with_endl.size(),pout);
    fflush(pout);
  }
};

#undef GetObject
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
using namespace rapidjson;
using namespace std;
#pragma endregion qap_std

#include <random>
#include <algorithm>

#ifdef Adler
#include <iterator>
#include <tlhelp32.h>
struct t_wipe_sys{
  static void wipe(DWORD pid){
    HANDLE hChildProc=::OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
    if(hChildProc)
    {
      ::TerminateProcess(hChildProc,1);
      ::CloseHandle(hChildProc);
    }
  };
  static void kill(std::map<DWORD,vector<DWORD>>&pid2arr,DWORD pid,bool killhost=true){
    QAP_FOREACH(pid2arr[pid],kill(pid2arr,ex););
    if(killhost)wipe(pid);
  }
};
void wipe_subprocs()
{
  DWORD myprocID=GetCurrentProcessId();
  PROCESSENTRY32 pe;
  memset(&pe,0,sizeof(PROCESSENTRY32));pe.dwSize=sizeof(PROCESSENTRY32);
  HANDLE hSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
  struct t_rec{DWORD pid;DWORD ppid;};
  vector<t_rec> arr;
  std::map<DWORD,vector<DWORD>> pid2arr;
  if(::Process32First(hSnap,&pe))
  {
    BOOL bContinue=TRUE;
    while(bContinue)
    {
      auto&b=qap_add_back(arr);
      b.pid=pe.th32ProcessID;
      b.ppid=pe.th32ParentProcessID;
      qap_add_back(pid2arr[b.ppid])=b.pid;
      bContinue=::Process32Next(hSnap,&pe);
    }     
  }
  t_wipe_sys::kill(pid2arr,myprocID,false);
}
#endif

template<class TYPE>vector<TYPE> copy_subarr(const vector<TYPE>&arr,size_t offset,size_t n){
  vector<TYPE> out;auto an=arr.size();if(!an)return out;
  out.resize(n);
  for(size_t i=0;i<n;i++)out[i]=arr[(offset+i)%an];
  return out;
}

static string jq(string value){static const string q="\"";return q+value+q;}
static string jobj(string value){return "{"+value+"}";}
static string jk(string key,string value){return jq(key)+":"+value;}
static string jk(string key,double value){return jq(key)+":"+std::to_string(value);}
static string dump(const vec2d&p){return jobj(jk("X",p.x)+","+jk("Y",p.y));}

static Document unsafe_get_doc(const string&s){
  Document out;
  if(out.Parse<0>(s.c_str()).HasParseError()){
    QapDebugMsg("this line is not json:\nbeg\n"+s+"\nend // s.size()="+IToS(s.size())+" // IToS(s[0])="+IToS(s[0]));
    return out;
  }
  return out;
}

#define doc (*((Document*)nullptr))
typedef decltype(doc["params"].GetObject()) Object;
typedef GenericObject<false,Value> json_obj_t;
typedef GenericArray<false,Value> json_arr;
#undef doc

#pragma endregion before_t_score

struct t_score{
  real rank=-1;
  #define LIST(ADD)\
  ADD(real,total_score,0)\
  ADD(real,total_energy,0)\
  ADD(real,total_btnH,0)\
  ADD(real,total_H,0)\
  ADD(real,score,0)\
  ADD(real,energy,0)\
  ADD(real,btnH,0)\
  ADD(real,H,0)\
  //===
  #define F(TYPE,NAME,VALUE)TYPE NAME=VALUE;
  LIST(F)
  #undef F
  //
  int id=-1;
  real probability=1.0;
  real sources=0.0;
  int ticks_to_deadline=0;
  void test_rank2probability(){
    auto f=rank2probability;
    QapAssert(f(1,3)==3.0/4);
    QapAssert(f(2,3)==2.0/4);
    QapAssert(f(3,3)==1.0/4);
    QapAssert(f(1,7)==0.875);
    QapAssert(f(7,7)==0.125);
  }
  static real rank2probability(real rank,int n){return 1.0-(rank)/(n+1);}
  void set_rank(real new_rank,int n){
    //test_rank2probability();
    rank=new_rank;
    probability=rank2probability(rank+1,n);
  }
  void wipe_score(){score=0;total_score=0;}
  void wipe_btnH(){btnH=0;total_btnH=0;}
  void enemy_blur(){
    #define MAJOR(SIGN,field)field=0;
    MAJOR(-,energy);
    MAJOR(-,total_energy);
    MAJOR(-,btnH);
    MAJOR(-,total_btnH);
    MAJOR(-,H);
    MAJOR(-,total_H);
    #undef MAJOR
  }
  real tot_btnH_and_energy()const{return total_btnH+total_energy;}
  real tot_btnH_and_H()const{return total_btnH+total_H;}
  bool operator!=(const t_score&ref)const{auto&src=*this;return (src<ref)!=(ref<src);}
  bool operator<(const t_score&ref)const{
    #define MAJOR(SIGN,field)if(field!=ref.field)return SIGN field<SIGN ref.field;
    MAJOR(-,total_score);
    //MAJOR(-,tot_btnH_and_energy());
    //MAJOR(-,tot_btnH_and_H());
    //MAJOR(-,total_btnH);
    MAJOR(-,total_energy);
    MAJOR(-,total_H);
    MAJOR(-,score);
    MAJOR(-,energy);
    MAJOR(-,btnH);
    MAJOR(-,H);
    #undef MAJOR
    return id>ref.id;
  }
  bool almost_equal_to(const t_score&ref){
    t_score a=*this;
    t_score b=ref;
    std::swap(a.id,b.id);
    return ((*this)<ref)!=(a<b);
  }
  void add(const t_score&ref)
  {
    sources+=ref.probability;
    #define F(TYPE,NAME,VALUE)this->NAME+=ref.NAME*ref.probability;
    LIST(F);
    #undef F
  }
  void add_mul(const t_score&ref,real probability)
  {
    sources+=probability;
    #define F(TYPE,NAME,VALUE)this->NAME+=ref.NAME*probability;
    LIST(F);
    #undef F
  }
  t_score get_average()const
  {
    t_score out=*this;
    #define F(TYPE,NAME,VALUE)out.NAME=real(this->NAME)/sources;
    LIST(F);
    #undef F
    return out;
  }
  template<class FUNC>
  void foreach(FUNC func){
    #define F(TYPE,NAME,VALUE)func(#NAME,this->NAME);
    LIST(F);
    #undef F
  }
  string to_str(bool json=true,const string&glue=",")const{
    vector<string> out;
    #define F(TYPE,NAME,VALUE)qap_add_back(out)="\""+string(#NAME)+"\":"+std::to_string(this->NAME);
    F(int,id,-1);
    F(int,rank,-1);
    F(real,probability,1.0);
    F(real,sources,0.0);
    LIST(F);
    #undef F
    auto s=join(out,glue);
    return json?"{"+s+"}":s;
  }
  //t_score&set(int id){this->id=id;return *this;}
  #undef LIST
};

#pragma region after_t_score

template<class VECTOR_TSCORE>
static void update_vec_score_rank(VECTOR_TSCORE&arr){
  int pos=-1;int n=0;if(arr.size())arr[0].rank=0;//bool dbg_even_happen=false;
  auto f=[&](){
    if(!n)return;
    if(1==n){arr[pos].rank=pos;pos=-1;n=0;return;}
    real avg_rank=0;
    for(int i=pos;i<pos+n;i++)avg_rank+=i;
    avg_rank/=n;
    for(int i=pos;i<pos+n;i++)arr[i].rank=avg_rank;
    #ifdef Adler
    //QapDebugMsg("got it\n n = "+IToS(n)+"\n pos = "+IToS(pos));dbg_even_happen=true;
    #endif
    pos=-1;n=0;
  };
  for(int i=1;i<arr.size();i++)
  {
    auto&a=arr[i-1];
    auto&b=arr[i-0];
    bool ok=a.almost_equal_to(b);
    if(ok)
    {
      if(!n){pos=i-1;n=1;}
      n++;
      int gg=1;
    }else{
      f();
      if(!n){pos=i;n=1;}
      f();
    }
    int gg=1;
  }
  f();
  int gg=1;
};

struct t_move{
  int dir;
  t_move&set(int dir){this->dir=dir;return *this;}
  //t_move operator=(const int&ref){dir=ref;return *this;}
  t_move(){dir=0;}
  //t_move(const int&ref){dir=ref;}
  //operator int&(){return dir;}
  bool operator==(const t_move&ref)const{return dir==ref.dir;}
  template<class t_mech>int get(t_mech&m,int pId)const{return dir;};
  //vec2d dir;
  //t_move&setang(real ang){this->dir=Vec2dEx(ang,1);return *this;}
  //template<class t_mech>
  //int get(t_mech&m,int pId)const{return Sign(Vec2dEx(m.get_car(pId).body->a,1).Rot(dir).y);}
};
struct t_plan_rec{
  int tick=-1;
  t_move move;
  t_plan_rec with_offset(int offset)const{t_plan_rec out=*this;out.tick+=offset;return out;}
  bool operator==(const t_plan_rec&ref)const{return tick==ref.tick&&move==ref.move;}
};
static real perf_a=0;
static real perf_b=0;QapClock perf_clock;
static int tick_limit=234;
static const int arr_limit=5;

struct t_plan{
  vector<t_plan_rec> arr;
  PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(t_plan_rec,tick2rec,arr,int,tick);
  t_plan&add(int tick,const t_move&move){auto&b=qap_add_back(arr);b.tick=tick;b.move=move;return *this;}
  struct t_rec{bool ok;t_plan_rec pr;const t_rec&fail(){thread_local t_rec t={false};return t;}};
  void sort(){QAP_SORT_BY_FIELD(arr,tick,t_plan_rec);}
  void update(){
    if(!valid())return;
    sort();
  }
  t_rec get_rec_v1(int tick)const{
    for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(tick<=ex.tick){return {true,ex};}}
    return {false};
  }
  t_rec get_rec_v2(int tick)const{
    //auto avg_dt=sim_limit/arr.size();
    //avg_dt*
    if(arr.size()<arr_limit||tick<=tick_limit)return get_rec_v1(tick);
    if(tick<=arr[0].tick)return {true,arr[0]};
    int low=0;
    int top=arr.size()-1;
    int avg=1+(low+top)/2;
    for(int iter=0;;iter++){
      int new_avg=(low+top)/2;
      avg=new_avg+(new_avg==avg?1:0);
      int p=avg-1;
      int c=avg-0;
      if(!qap_check_id(arr,c))break;//return {false};
      if(!qap_check_id(arr,p))break;//return {false,{-7001}};
      bool prev=tick<=arr[p].tick;
      bool curr=tick<=arr[c].tick;
      if(!prev&&curr)break;//return {true,arr[avg]};
      if(prev!=curr)break;//return {false,{-7000}};
      int&b=prev&&curr?top:low;
      b=avg;
    }
    return {false};
  }
  t_plan get_promoted(bool keep_length=false)const
  {
    t_plan out;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.tick<1)continue;
      auto&b=qap_add_back(out.arr);
      b=ex;
      b.tick--;
    }
    if(keep_length)if(out.valid())out.arr.back().tick++;
    return out;
  }
  bool try_save_move_and_promote(t_move&out,bool auto_promote=true,bool keep_length=true){
    auto rec=get_rec_v1(0);
    if(!rec.ok)return false;
    out=rec.pr.move;
    if(auto_promote){
      if(keep_length)if(!arr.empty())arr.back().tick++;
      *this=get_promoted();
    }
    return true;
  }
  bool valid()const{return !arr.empty();}
  bool operator==(const t_plan&ref)const{return arr==ref.arr;}
};

struct t_plan_runner{
  const t_plan*ptr=nullptr;
  int id=0;
  int tick=0;
  const t_move&next(){
    thread_local const t_move fail;
    auto&arr=ptr->arr;
    if(!qap_check_id(arr,id+0))return fail;
    auto&ex=arr[id];
    if(tick++<=ex.tick)return ex.move;
    id++;
    if(!qap_check_id(arr,id))return fail;
    return arr[id].move;
  };
  void restart(){id=0;tick=0;}
};

static cpVect cpv(const vec2d&p){return cpv(p.x,p.y);}

struct t_jsonobj2cpp{
  typedef const char*const_c_str;
  static void use(Value&doc,const_c_str field_name,real&out){
    #if Adler
    if(!doc.HasMember(field_name)){
      QapDebugMsg("field '"+string(field_name)+"' - not found");
    }
    #endif
    out=doc.HasMember(field_name)?doc[field_name].GetDouble():0;
  }
  static void use(Value&doc,const_c_str field_name,int&out){out=doc.HasMember(field_name)?doc[field_name].GetInt():0;}
  static void use(Value&doc,const_c_str field_name,bool&out){out=doc.HasMember(field_name)?doc[field_name].GetBool():false;}
  static void use(Value&doc,const_c_str field_name,vec2d&out){
    QapNoWay();
    auto obj=doc[field_name].GetArray();
    out.x=obj[0].GetDouble();
    out.y=obj[1].GetDouble();
  }
  template<class TYPE>static void use(Value&doc,const_c_str field_name,TYPE&out){
    out.load(doc[field_name]);
  }
  template<class TYPE>static void use(Value&doc,const_c_str field_name,vector<TYPE>&out)
  {
    auto arr=doc[field_name].GetArray();
    if(auto n=arr.Size())
    {
      for(int i=0;i<n;i++)
      {
        auto&ex=arr[i];
        useval(ex,qap_add_back(out));
      }
    }
  }
  template<class TYPE>
  static void useval(Value&doc,TYPE&out){out.load(doc);}
  static void useval(Value&arr,real&out){out=arr.GetDouble();}
  static void useval(Value&arr,int&out){out=arr.GetInt();}
  static void useval(Value&arr,bool&out){out=arr.GetBool();}
  static void useval(Value&arr,vec2d&out){
    out.x=arr[0].GetDouble();
    out.y=arr[1].GetDouble();
  }
public:
  template<class TYPE>
  static void use_save(Document&doc,const_c_str field_name,const TYPE&ref){
    Value obj;
    ref.save(doc,obj);
    doc.AddMember(GenericStringRef<char>(field_name),obj,doc.GetAllocator());
  }
  static void use_save(Document&doc,const_c_str field_name,const real&ref){
    Value obj;
    obj=ref;
    doc.AddMember(GenericStringRef<char>(field_name),obj,doc.GetAllocator());
  }
  template<class TYPE>
  static void use_save(Document&doc,Value&d,const TYPE&ref){
    ref.save(doc,d);
  }
  static void use_save(Document&doc,Value&d,const real&ref){d=ref;}
  static void use_save(Document&doc,Value&d,const int&ref){d=ref;}
  static void use_save(Document&doc,Value&d,const vec2d&ref){
    d.SetArray();
    d.PushBack(ref.x,doc.GetAllocator());
    d.PushBack(ref.y,doc.GetAllocator());
  }
};
template<class FUNC>
static void x_mul_foreach(const vector<vec2d>&arr,real k,real ang,vec2d pos,vec2d cog,FUNC func){
  vec2d ox=Vec2dEx(ang,1);QAP_FOREACH(arr,func(i,pos+(vec2d(ex.x*k,ex.y)-cog).UnRot(ox)););
  //inp=pos+vec2d(ex.x*k,ex.y).UnRot(ox);
  //pos=-inp+vec2d(ex.x*k,ex.y).UnRot(ox);
}
#define QAP_X_MUL_FOREACH(arr,k,ang,pos,cog,CODE)x_mul_foreach(arr,k,ang,pos,cog,[&](const int&i,const vec2d&ex){CODE;})
static vector<vec2d> x_mul(const vector<vec2d>&arr,real k,real ang,vec2d pos){
  auto out=arr;vec2d ox=Vec2dEx(ang,1);QAP_FOREACH(out,ex.x*=k;ex=pos+ex.UnRot(ox););return out;
}

static vec2d x_mul(vec2d ex,real k,real ang,vec2d pos){
  vec2d ox=Vec2dEx(ang,1);ex.x*=k;return pos+ex.UnRot(ox);
}

struct t_vec2d:vec2d{
  #define DEF_PRO_VARIABLE(ADD)\
  //===
  //#include "defprovar_v2.inl"
  #define ADD(TYPE,NAME,VALUE)TYPE NAME;
  DEF_PRO_VARIABLE(ADD)
  #undef ADD
  //===
  void load(Value&arr)
  {
    x=arr[0].GetDouble();
    y=arr[1].GetDouble();
  }
  //===
  #undef DEF_PRO_VARIABLE
  //===
};

struct t_segment{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,a,$)\
  ADD(vec2d,b,$)\
  ADD(real,h,$)\
  //===
  //#include "defprovar_v2.inl"
  #define ADD(TYPE,NAME,VALUE)TYPE NAME;
  DEF_PRO_VARIABLE(ADD)
  #undef ADD
  //===
  void load(Value&arr)
  {
    t_jsonobj2cpp::useval(arr[0],this->a);
    t_jsonobj2cpp::useval(arr[1],this->b);
    this->h=arr[2].GetDouble();
  }
  //===
  #undef DEF_PRO_VARIABLE
  //===
};

static const vec2d world_wh=vec2d(1200,800);
static const auto segment_height=10;

struct t_map_box{
  static bool check_point(const vec2d&p){
    auto w=world_wh.x;
    auto h=world_wh.y;
    auto bo=segment_height-1;
    if(p.x<=-bo)return false;
    if(p.y<=-bo)return false;
    if(p.x>=w+bo)return false;
    if(p.y>=h+bo)return false;
    return true;
  }
};

struct t_proto_map{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,external_id,-1)\
  ADD(vector<t_segment>,segments,$)\
  //===
  #include "defprovar_v2.inl"
  //===
  struct t_impl{
    vector<cpShape*> arr;
    cpShape*add(cpSpace*space,cpShape*p){
      qap_add_back(arr)=p;cpSpaceAddShape(space,p);
      return p;
    }
  };
  static void create_box(cpSpace*space,t_impl&out)
  {
    //auto w=world_wh.x;
    //auto h=world_wh.y;
    //auto bo=segment_height-1;
    //cpShapeSetSensor(out.add(space,cpSegmentShapeNew(space->staticBody,cpv(vec2d(0,0)+vec2d(-bo,-bo)),cpv(vec2d(0,h)+vec2d(-bo,+bo)),1)),true);
    //cpShapeSetSensor(out.add(space,cpSegmentShapeNew(space->staticBody,cpv(vec2d(0,h)+vec2d(-bo,+bo)),cpv(vec2d(w,h)+vec2d(+bo,+bo)),1)),true);
    //cpShapeSetSensor(out.add(space,cpSegmentShapeNew(space->staticBody,cpv(vec2d(w,h)+vec2d(+bo,+bo)),cpv(vec2d(w,0)+vec2d(+bo,-bo)),1)),true);
    //cpShapeSetSensor(out.add(space,cpSegmentShapeNew(space->staticBody,cpv(vec2d(w,0)+vec2d(+bo,-bo)),cpv(vec2d(0,0)+vec2d(-bo,-bo)),1)),true);
  }
  t_impl build(cpSpace*space)
  {
    t_impl out;
    create_box(space,out);
    auto segment_friction=1;
    auto segment_elasticity=0;
    auto&arr=segments;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*shape=out.add(space,cpSegmentShapeNew(space->staticBody,cpv(ex.a),cpv(ex.b),ex.h));
      cpShapeSetFriction(shape,segment_friction);
      cpShapeSetElasticity(shape,segment_elasticity);
    }
    return out;
  }
};

static void chipAdd(cpSpace*s,cpBody*p){cpSpaceAddBody(s,p);}
static void chipAdd(cpSpace*s,cpShape*p){cpSpaceAddShape(s,p);}
static void chipAdd(cpSpace*s,cpConstraint*p){cpSpaceAddConstraint(s,p);}
static void chipAdd(cpSpace*s,cpGrooveJoint*p){cpSpaceAddConstraint(s,&p->constraint);}
static void chipAdd(cpSpace*s,cpDampedSpring*p){cpSpaceAddConstraint(s,&p->constraint);}
static void chipAdd(cpSpace*s,cpSimpleMotor*p){cpSpaceAddConstraint(s,&p->constraint);}

struct t_wheel{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(real,r,0)\
  ADD(real,m,5)\
  ADD(vec2d,p,$)\
  ADD(real,fk,1)\
  ADD(real,ek,0.8)\
  ADD(real,groove_offset,$)\
  ADD(vec2d,damp_position,$)\
  ADD(real,damp_length,25)\
  ADD(real,damp_stiffness,60000)\
  ADD(real,damp_damping,900)\
  //===
  #include "defprovar_v2.inl"
  //===
  static bool is_motor(bool rear,int drive)
  {
    const auto d=drive;
    auto FF=1;auto FR=2;auto AWD=3;
    if(rear==1)return d==AWD||d==FR;
    if(rear==0)return d==AWD||d==FF;
    return false;
  }
  struct t_impl{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(cpBody*,body,$)\
    ADD(cpShape*,shape,$)\
    ADD(cpGrooveJoint*,groove,$)\
    ADD(cpDampedSpring*,damp,$)\
    ADD(cpSimpleMotor*,motor,$)\
    //===
    #define ADD(TYPE,NAME,VALUE)TYPE NAME=nullptr;
    DEF_PRO_VARIABLE(ADD)
    #undef ADD
    //===
    void add_to(cpSpace*space)
    {
      #define F(TYPE,NAME,VALUE)if(this->NAME)chipAdd(space,this->NAME);
      DEF_PRO_VARIABLE(F)
      #undef F
    }
    //===
    #undef DEF_PRO_VARIABLE
    //===
  };
  t_impl build(cpBody*car,int car_group,bool rear,int drive,int xmod,bool squared_wheels)
  {
    t_impl out;
    auto f=[xmod](const vec2d&p){return cpv(xmod<0?p.inv_x():p);};
    auto zero=cpv(0,0);
    auto&body=out.body;
    auto&shape=out.shape;
    auto&groove=out.groove;
    auto&damp=out.damp;
    auto&motor=out.motor;

    if(!squared_wheels){
      body=cpBodyNew(m,cpMomentForCircle(m,0,r,zero));
      shape=cpCircleShapeNew(body,r,zero);
    }else{
      body=cpBodyNew(m,cpMomentForBox(m,r*2,r*2));
      shape=cpBoxShapeNew(body,r*2,r*2,0);
    }
    cpBodySetPosition(body,f(p));

    cpShapeSetFilter(shape,cpShapeFilterNew(car_group,CP_ALL_CATEGORIES,CP_ALL_CATEGORIES));
    cpShapeSetFriction(shape,fk);
    cpShapeSetElasticity(shape,ek);
    auto fdp=f(damp_position);
    groove=(cpGrooveJoint*)cpGrooveJointNew(car,body,cpv(fdp.x,fdp.y-groove_offset),cpv(fdp.x,fdp.y-damp_length*1.5),zero);
    damp=(cpDampedSpring*)cpDampedSpringNew(body,car,zero,fdp,damp_length,damp_stiffness,damp_damping);
    cpVect tmp[]={
      zero,cpv(0,1),f(vec2d(2*r,1)),f(vec2d(2*r,0))
    };
    if(is_motor(rear,drive)){
      out.motor=(cpSimpleMotor*)cpSimpleMotorNew(body,car,0);
    }
    return out;
  }
};

struct t_proto_car_impl{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<vec2d>,car_body_poly,$)\
  ADD(vector<vec2d>,button_poly,$)\
  ADD(int,external_id,-1)\
  ADD(real,car_body_mass,200)\
  ADD(real,car_body_friction,0.9)\
  ADD(real,car_body_elasticity,0.5)\
  ADD(real,max_speed,70)\
  ADD(real,torque,0)\
  ADD(int,drive,2)\
  ADD(real,front_wheel_radius,0)\
  ADD(real,front_wheel_mass,5)\
  ADD(t_vec2d,front_wheel_position,$)\
  ADD(real,front_wheel_friction,1)\
  ADD(real,front_wheel_elasticity,0.8)\
  ADD(real,front_wheel_groove_offset,$)\
  ADD(t_vec2d,front_wheel_damp_position,$)\
  ADD(real,front_wheel_damp_length,25)\
  ADD(real,front_wheel_damp_stiffness,60000)\
  ADD(real,front_wheel_damp_damping,900)\
  ADD(real,rear_wheel_radius,1)\
  ADD(real,rear_wheel_mass,50)\
  ADD(t_vec2d,rear_wheel_position,$)\
  ADD(real,rear_wheel_friction,1)\
  ADD(real,rear_wheel_elasticity,0.8)\
  ADD(real,rear_wheel_groove_offset,$)\
  ADD(t_vec2d,rear_wheel_damp_position,$)\
  ADD(real,rear_wheel_damp_length,25)\
  ADD(real,rear_wheel_damp_stiffness,50000)\
  ADD(real,rear_wheel_damp_damping,3000)\
  ADD(bool,squared_wheels,false)\
  //===
  #include "defprovar_v2.inl"
  //===
};

struct t_proto_car{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<vec2d>,car_body_poly,$)\
  ADD(vector<vec2d>,button_poly,$)\
  ADD(int,external_id,-1)\
  ADD(real,car_body_mass,200)\
  ADD(real,car_body_friction,0.9)\
  ADD(real,car_body_elasticity,0.5)\
  ADD(real,max_speed,70)\
  ADD(real,torque,0)\
  ADD(int,drive,2)\
  ADD(t_wheel,front,$)\
  ADD(t_wheel,rear,$)\
  ADD(bool,squared_wheels,false)\
  //===
  #define ADD(TYPE,NAME,VALUE)TYPE NAME;
  DEF_PRO_VARIABLE(ADD)
  #undef ADD
  //===
  void load(Value&d)
  {
    auto&ref=(t_proto_car_impl&)*this;
    ref.load(d);
  }
  //===
  #undef DEF_PRO_VARIABLE
public:
  static vector<cpVect> use_xmod(const vector<vec2d>&arr,int xmod){
    auto f=[xmod](const vec2d&p){return cpv(xmod<0?p.inv_x():p);};
    vector<cpVect> out;out.reserve(arr.size());QAP_FOREACH(arr,qap_add_back(out)=f(ex));return out;
  }
  struct t_impl{
    int xmod=0;
    int car_group=-1;
    int button_collision_type=-1;
    cpBody*body=nullptr;
    cpShape*hull=nullptr;
    cpShape*btn=nullptr;
    t_wheel::t_impl r,f;
    //static real diff(cpBody*a,cpBody*b){
    //  a->
    //}
    //real diff(t_upd&ref)const{
    //  real out=0;
    //  out+=diff(car,ref.car);
    //  out+=r.diff(ref.r);
    //  out+=f.diff(ref.f);
    //  return out;
    //}
  };
  static cpBool chBegin(cpArbiter*arb,cpSpace*space,cpDataPointer userData){
    ((size_t&)space->userData)|=(size_t)userData;
    return false;
  }
  t_impl build(cpSpace*space,int car_group,int xmod,size_t space_user_data_bitmask)
  {
    //cpSpacePointQueryNearest(space,...);
    auto zero=cpv(0,0);
    vector<cpVect> car_out=use_xmod(car_body_poly,xmod);
    auto car_i=cpMomentForPoly(car_body_mass,car_out.size(),&car_out[0],zero,0);
    auto*body=cpBodyNew(car_body_mass,car_i);
    ADLER_DEBUG(body->userData=(cpDataPointer)space_user_data_bitmask;);

    auto*hull=cpPolyShapeNew(body,car_out.size(),&car_out[0],cpTransformIdentity,0);
    cpShapeSetFilter(hull,cpShapeFilterNew(car_group,CP_ALL_CATEGORIES,CP_ALL_CATEGORIES));
    cpShapeSetFriction(hull,car_body_friction);
    cpShapeSetElasticity(hull,car_body_elasticity);

    auto button_collision_type=car_group*10;
    vector<cpVect> btn_out=use_xmod(button_poly,xmod);
    auto*btn=cpPolyShapeNew(body,btn_out.size(),&btn_out[0],cpTransformIdentity,0);
    cpShapeSetFilter(btn,cpShapeFilterNew(car_group,CP_ALL_CATEGORIES,CP_ALL_CATEGORIES));
    cpShapeSetSensor(btn,true);
    cpShapeSetCollisionType(btn,button_collision_type);

    cpBodySetCenterOfGravity(body,cpShapeGetCenterOfGravity(hull));

    chipAdd(space,body);
    chipAdd(space,hull);
    chipAdd(space,btn);

    space->userData=nullptr;
    auto*co=cpSpaceAddWildcardHandler(space,button_collision_type);
    co->beginFunc=chBegin;
    co->userData=(cpDataPointer)space_user_data_bitmask;

    t_impl out;
    out.xmod=xmod;
    out.car_group=car_group;
    out.button_collision_type=button_collision_type;
    out.body=body;
    out.hull=hull;
    out.btn=btn;
    #define F(TYPE,FIELD)size_t(&(*(TYPE*)nullptr).FIELD)
    static_assert(F(t_proto_car,squared_wheels)==F(t_proto_car_impl,squared_wheels),"no?");
    #undef F
    //return out;
    out.r=rear.build(body,car_group,true,drive,xmod,squared_wheels);
    out.f=front.build(body,car_group,false,drive,xmod,squared_wheels);
    out.r.add_to(space);
    out.f.add_to(space);
    ADLER_DEBUG(
    out.r.body->userData=(cpDataPointer)space_user_data_bitmask;
    out.f.body->userData=(cpDataPointer)space_user_data_bitmask;
    )
    return out;
  }
};

struct t_new_match{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,my_lives,9)\
  ADD(int,enemy_lives,9)\
  ADD(t_proto_map,proto_map,$)\
  ADD(t_proto_car,proto_car,$)\
  //===
  #include "defprovar_v2.inl"
  //===
  void build(cpSpace*space)
  {
    proto_map.build(space);
    //auto car=proto_car.build(space);
  }
  size_t get_seg()const{size_t box=4;size_t dl=1;return proto_map.segments.size()+box+dl;}
};

static void update_shapes_aabb(cpSpace*space){cpSpatialIndexEach(space->dynamicShapes,(cpSpatialIndexIteratorFunc)cpShapeUpdateFunc,NULL);}

static vec2d to_vec2d(const cpVect&p){return vec2d(p.x,p.y);}

static const real diff_ang_sqrk=sqr(32.0/Pi);
static const real diff_eps_base=1.0/1024.0;
static const real diff_eps=sqr(diff_eps_base);//1.0/4096.0;
static const real diffang_eps=diff_eps/diff_ang_sqrk;
static const real chip_world_dt=0.016;
static const real chip_world_inv_dt=1.0/chip_world_dt;

static real sqrbody_diff(cpBody*b,const vec2d&pos,real ang){
  auto dir=Vec2dEx(ang,1);
  auto bnew_gpos=pos-to_vec2d(-b->cog).UnRot(dir);
  auto out=bnew_gpos.sqr_dist_to(to_vec2d(b->p));
  out+=sqr(ang-b->a)*diff_ang_sqrk;
  return out;
}

static void apply_upd_to_body(cpBody*b,const vec2d&pos,real ang,bool megasync){
  real d=sqrbody_diff(b,pos,ang);
  if(d<1e-9)return;
  if(d<0.5*239798.60174637783){
    ADLER_DEBUG(volatile real gg=d;)
  }
  if(megasync){
    auto nbp=pos-to_vec2d(-b->cog).UnRot(Vec2dEx(ang,1));
    auto dang=ang-b->a;
    auto dpos=nbp-to_vec2d(b->p);
    b->w+=dang*chip_world_inv_dt*0.5;
    b->v=b->v+cpv(dpos*chip_world_inv_dt*0.5);
  }
  cpBodySetAngle(b,ang);
  cpBodySetPosition(b,cpv(pos));
}

struct t_upd{
public:
  struct t_wheel{
    vec2d pos;real ang;
    void load(Value&d)
    {
      size_t i=0;
      t_jsonobj2cpp::useval(d[i++],pos.x);
      t_jsonobj2cpp::useval(d[i++],pos.y);
      t_jsonobj2cpp::useval(d[i++],ang);
    }
    void apply_to(::t_wheel::t_impl&ref,bool megasync)const{
      if(!ref.body)return;
      apply_upd_to_body(ref.body,pos,ang,megasync);
    }
    void grab_from(const ::t_wheel::t_impl&ref){
      if(!ref.body)return;
      pos=to_vec2d(cpBodyGetPosition(ref.body));
      ang=ref.body->a;
    }
    real diff_to(const ::t_wheel::t_impl&ref)const{
      if(!ref.body)return 0;
      real out=sqrbody_diff(ref.body,pos,ang);
      return out;
    }
    void save(Document&doc,Value&d)const
    {
      d.SetArray();
      #define F(NAME){Value v;t_jsonobj2cpp::use_save(doc,v,this->NAME);d.PushBack(v,doc.GetAllocator());}
      F(pos.x);
      F(pos.y);
      F(ang);
      #undef F
    }
  };
  struct t_car{
    vec2d pos;
    real ang;
    int xmod;
    t_wheel rear,front;
    void load(Value&d)
    {
      size_t i=0;
      t_jsonobj2cpp::useval(d[i++],pos);
      t_jsonobj2cpp::useval(d[i++],ang);
      t_jsonobj2cpp::useval(d[i++],xmod);
      t_jsonobj2cpp::useval(d[i++],rear);
      t_jsonobj2cpp::useval(d[i++],front);
    }
    void apply_to(t_proto_car::t_impl&ref,bool megasync)const{
      apply_upd_to_body(ref.body,pos,ang,megasync);
      rear.apply_to(ref.r,megasync);
      front.apply_to(ref.f,megasync);
    }
    void grab_from(const t_proto_car::t_impl&ref){
      if(!ref.body)return;
      pos=to_vec2d(cpBodyGetPosition(ref.body));
      ang=ref.body->a;
      rear.grab_from(ref.r);
      front.grab_from(ref.f);
      xmod=ref.xmod;
    }
    real diff_to(const t_proto_car::t_impl&ref)const{
      real out=sqrbody_diff(ref.body,pos,ang);
      out+=rear.diff_to(ref.r);
      out+=front.diff_to(ref.f);
      return out;
    }
    void save(Document&doc,Value&d)const
    {
      d.SetArray();
      #define F(NAME){Value v;t_jsonobj2cpp::use_save(doc,v,this->NAME);d.PushBack(v,doc.GetAllocator());}
      F(pos);
      F(ang);
      F(xmod);
      F(rear);
      F(front);
      #undef F
    }
  };
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_car,my_car,$)\
  ADD(t_car,enemy_car,$)\
  ADD(real,deadline_position,10)\
  //===
  #include "defprovar_v2.inl"
  //===
  template<class t_mech>
  void apply_to(t_mech&ref,bool megasync)const{
    my_car.apply_to(ref.mcar,megasync);
    enemy_car.apply_to(ref.ecar,megasync);
    update_shapes_aabb(ref.space);
    ref.dl.pos=deadline_position;
  }
  template<class t_mech>
  void grab_from(const t_mech&ref){
    my_car.grab_from(ref.mcar);
    enemy_car.grab_from(ref.ecar);
    deadline_position=ref.dl.pos;
  }
  template<class t_mech>
  real diff_to(t_mech&ref)const{
    real out=0;
    out+=my_car.diff_to(ref.mcar);
    out+=enemy_car.diff_to(ref.ecar);
    return out;
  }
  void save(Document&d)const
  {
    d.SetObject();
    #define F(TYPE,NAME,VALUE)t_jsonobj2cpp::use_save(d,#NAME,this->NAME);
    F(t_car,my_car,$)
    F(t_car,enemy_car,$)
    F(real,deadline_position,10)
    #undef F
  }
  string to_json()const{
    Document d;
    save(d);
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    return buffer.GetString();
  }
};

static void chipFree(cpSpace*&ref){cpSpaceFree(ref);ref=nullptr;}
static void chipFree(cpBody*&ref){cpBodyFree(ref);ref=nullptr;}
static void chipFree(cpShape*&ref){cpShapeFree(ref);ref=nullptr;}
static void chipFree(cpConstraint*&ref){if(ref)cpConstraintFree(ref);ref=nullptr;}
static void chipFree(cpGrooveJoint*p){chipFree((cpConstraint*&)p);}
static void chipFree(cpDampedSpring*p){chipFree((cpConstraint*&)p);}
static void chipFree(cpSimpleMotor*p){chipFree((cpConstraint*&)p);}

static void chipFree(t_wheel::t_impl&ref){
  chipFree(ref.body);
  chipFree(ref.damp);
  chipFree(ref.groove);
  chipFree(ref.motor);
  chipFree(ref.shape);
}
static void chipFree(t_proto_car::t_impl&ref){
  chipFree(ref.body);
  chipFree(ref.hull);
  chipFree(ref.btn);
  chipFree(ref.f);
  chipFree(ref.r);
}

#pragma endregion after_t_score

#ifdef Adler
static std::atomic<int64> mech_forktime=0;static std::atomic<int64> mech_forkn=0;
#endif

static cpSpace*build_space(){
  //QapClock clock;
  cpSpace*space=cpSpaceNew();
  //space_build_time+=int(clock.MS()*1e3);space_build_n++;
  cpSpaceSetGravity(space,cpv(0.0,-700));
  cpSpaceSetDamping(space,0.85);
  return space;
}

struct t_deadline{
public:
  static const auto MaxL=1800;
  static const auto MaxH=800;
  static const auto DL_R=2;
  static const auto DL_T=600;
  static const auto h=2;
  static real get_dl_dir(){return +0.5;}//ASC==+0.5;
public:
  //cpBody*body=nullptr;
  //cpShape*line=nullptr;
public:
  real DL_DIR=get_dl_dir();
  int ticks_rem=DL_T;
  real pos=0;
  bool ekill=false;
public:
  void build(cpSpace*space){
    //body=cpBodyNewKinematic();
    //cpVect rect[]={{0,2},{MaxL,2},{MaxL,-MaxH},{0,-MaxH}};
    //line=cpPolyShapeNew(body,lenof(rect),rect,cpTransformIdentity,0);
    //cpShapeSetSensor(line,true);
    //cpBodySetPosition(body,cpv(0,DL_DIR>0?10:MaxH-10));
    //chipAdd(space,body);
    //chipAdd(space,line);
    pos=DL_DIR>0?10:MaxH-10;
  }
  void move(){
    ticks_rem--;
    if(ticks_rem>0)return;
    //auto p=cpBodyGetPosition(body);
    pos+=DL_DIR;//p.y=pos;
    //cpBodySetPosition(body,p);
  }
  real get_h_after(int t=0)const{return pos+h+DL_DIR*t;}
};

struct t_world{
  t_new_match*conf=nullptr;
  t_upd upd;
};

struct t_world_log{
  struct t_rec{
    int pId=false;
    t_move m;
    t_upd upd;
    bool step=false;
    bool use_upd=false;
    void set(int id,const t_move&move){pId=id;m=move;}
    void set(const t_upd&ref){use_upd=true;upd=ref;}
  };
  t_world beg;
  vector<t_rec> recs;
};

struct i_mech{
  #define virtual
  #define NO_IMPL(){}
  virtual real diff(const t_upd&ref)NO_IMPL();
  virtual void reset()NO_IMPL();
  virtual void free()NO_IMPL();
  //
  virtual void load_from(t_world&ref)NO_IMPL();
  virtual void sync(t_upd&ref)NO_IMPL();
  virtual void apply_direct(bool me,const t_move&m)NO_IMPL();
  virtual void fork_to(i_mech&dest)NO_IMPL();
  virtual void tickEvent()NO_IMPL();
  #undef virtual
};

//#define CHIP_FOREACH(ARR,TYPE)for(size_t i=0;i<(ARR)->num;i++)if(auto*ex=(TYPE*)(ARR)->arr[i])

struct t_mech{
public:
  bool need_load=true;
  template<class t_zmech>
  void load(t_zmech&ref)
  {
    QapAssert(need_load);
    ref.save_to(*this);
    need_load=false;
  }
  template<class t_zmech>
  void save(t_zmech&ref)
  {
    QapAssert(!need_load);
    ref.load_from(*this);
    need_load=true;
  }
  void drop(){
    QapAssert(!need_load);
    need_load=true;
  }
public:
  t_new_match*conf=nullptr;
  cpSpace*space=nullptr;
  t_deadline dl;
  t_proto_car::t_impl mcar;
  t_proto_car::t_impl ecar;
  t_proto_map::t_impl buff;
  t_world_log log;
  bool ignore_log=false;
  real diff(const t_upd&ref)const{
    return ref.diff_to(*this);
  }
  void free(){
    chipFree(space);
    //chipFree(dl.body);
    //chipFree(dl.line);
    chipFree(mcar);
    chipFree(ecar);
    QAP_FOREACH(buff.arr,chipFree(ex));buff.arr.clear();
  }
  void reset(){free();*this=t_mech();}
  void load_from_log_beg(){
    dl.ticks_rem=dl.DL_T;
    conf=log.beg.conf;
    space=build_space();
    dl.build(space);
    auto&w=log.beg;
    buff=conf->proto_map.build(space);
    mcar=conf->proto_car.build(space,1,w.upd.my_car.xmod,pId2bit(1));
    ecar=conf->proto_car.build(space,2,w.upd.enemy_car.xmod,pId2bit(0));
    sync(w.upd,false);
  }
  void load_from(t_world&ref){
    log.recs.clear();
    log.beg=ref;
    load_from_log_beg();
  }
  size_t&space_user_data_bitmask(){return (size_t&)space->userData;}
  static size_t pId2bit(int pId){return pId==1?0x1:0x2;}
  static size_t mpId2bit(int pId){return pId==1?0x1:0x2;}
  static size_t epId2bit(int pId){return pId==1?0x2:0x1;}
  bool me_deaded(int pId){return space_user_data_bitmask()&pId2bit(pId==1?1:0);}
  bool en_deaded(int pId){return space_user_data_bitmask()&pId2bit(pId==1?0:1);}
  real get_score_diff(int pId){
    auto m=int(me_deaded(pId));auto e=int(en_deaded(pId));return m*1.5-e;
  }
  bool smb_deaded(){return space_user_data_bitmask();}
  struct t_btn{std::array<vec2d,4> arr;};
  void update_mapbox_for_player(int pId,const t_btn&btn){
    bool off=false;
    QAP_FOREACH(btn.arr,if(!t_map_box::check_point(ex))off=true);
    if(!off)return;
    t_proto_car::chBegin(nullptr,space,(cpDataPointer)pId2bit(pId));
  }
  void tickEvent(bool withlog=true){
    if(!me_deaded(1)){
      dl.move();
      cpSpaceStep(space,0.016);
      auto mbtn=get_btn(1);auto ebtn=get_btn(0);
      update_mapbox_for_player(1,mbtn);
      update_mapbox_for_player(0,ebtn);
      //mcar.bb
      if(dl.pos>10){
        if(get_btn_y(mbtn)<=dl.pos+dl.h){t_proto_car::chBegin(nullptr,space,(cpDataPointer)pId2bit(1));}
        if(get_btn_y(ebtn)<=dl.pos+dl.h){t_proto_car::chBegin(nullptr,space,(cpDataPointer)pId2bit(0));dl.ekill=true;}
      }
    }else{
      int gg=1;
    }
    if(withlog&&!ignore_log)qap_add_back(log.recs).step=true;
  }
  bool in_air(t_proto_car::t_impl&c)
  {
    if(!c.r.body||!c.f.body)return false;
    return !(
      cpSpacePointQueryNearest(space,c.r.body->p,conf->proto_car.rear.r+1,cpShapeFilterNew(c.car_group,CP_ALL_CATEGORIES,CP_ALL_CATEGORIES),nullptr)||
      cpSpacePointQueryNearest(space,c.f.body->p,conf->proto_car.front.r+1,cpShapeFilterNew(c.car_group,CP_ALL_CATEGORIES,CP_ALL_CATEGORIES),nullptr)
    );
  }
  void apply_direct_impl(int pId,const t_move&m)
  {
    if(me_deaded(pId))return;//if(smb_deaded())return;
    auto&c=get_car(pId);
    int dir=m.get(*this,pId);
    if(c.f.motor)cpSimpleMotorSetRate(&c.f.motor->constraint,-conf->proto_car.max_speed*dir);
    if(c.r.motor)cpSimpleMotorSetRate(&c.r.motor->constraint,-conf->proto_car.max_speed*dir);
    if(dir)if(in_air(c))cpBodySetTorque(c.body,conf->proto_car.torque*dir);
  }
  void apply_direct(int pId,const t_move&m,bool withlog=true){
    apply_direct_impl(pId,m);
    if(withlog&&!ignore_log)qap_add_back(log.recs).set(pId,m);
  }
  void make_all_alive(){space->userData=0;}
  void sync(t_upd&ref,bool withlog=true){
    ref.apply_to(*this,false);
    if(withlog&&!ignore_log)qap_add_back(log.recs).set(ref);
  }
  void megasync(t_upd&ref){
    ref.apply_to(*this,true);
  }
  void rebuild_from_log(){
    load_from_log_beg();
    auto&arr=log.recs;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.step){tickEvent(false);continue;}
      if(ex.use_upd){sync(ex.upd,false);continue;}
      apply_direct(ex.pId,ex.m,false);
    }
  }
  // TODO: нужно обнаруживать момент косания врага со своей машиной. 
  /* если он долго не трогал нашу машинку или если он быстро в неё прилетел. особенно - колесом.
     и перед этим моментом(или прям в этот момент) посмотреть что будет если враг начнёт менять свою траекторию.
  */
  t_mech fork(){
    ADLER_DEBUG(QapClock clock;);
    t_mech out=*this;
    out.conf=nullptr;
    out.space=nullptr;
    out.rebuild_from_log();
    ADLER_DEBUG(mech_forktime+=int(clock.MS()*1e3);mech_forkn++;);
    return out;
  }
  static real get_full_energy(cpBody&b){return cpBodyKineticEnergy(&b)*b.m_inv+(b.p.y+1000)*fabs(b.space->gravity.y);}
  static real get_full_energy(cpBody*p){return p?get_full_energy(*p):0;}
  real get_energy_diff(int pId){
    auto&e=pId==1?ecar:mcar;
    auto&m=pId==1?mcar:ecar;
    real k=1.0/(1024*64);
    return k*(get_full_energy(m.body)-get_full_energy(e.body));
  }
  real get_btnH_diff(int pId){
    auto epId=pId==1?0:1;
    return get_btn_y(get_btn(epId))-get_btn_y(get_btn(pId));
  }
  real get_cogH_diff(int pId){
    auto&e=pId==1?ecar:mcar;
    auto&m=pId==1?mcar:ecar;
    return get_y(e)-get_y(m);
  }
  static real get_y(t_proto_car::t_impl&c){return c.body->p.y;};
  t_proto_car::t_impl&get_car(int pId){return pId==1?mcar:ecar;}
  t_btn get_btn(int pId){
    auto&c=get_car(pId);
    auto&arr=conf->proto_car.button_poly;
    t_btn btn;QapAssert(btn.arr.size()==arr.size());
    QAP_X_MUL_FOREACH(arr,c.xmod,c.body->a,to_vec2d(c.body->p),to_vec2d(c.body->cog),btn.arr[i]=ex);
    return btn;
  }
  real get_btn_y_v2(int pId){return get_btn_y(get_btn(pId));}
  real get_btn_y(const t_btn&btn){
    auto id=QAP_MINVAL_ID_OF_VEC(make_view(btn.arr),ex.y);
    return btn.arr[id].y;
  };
};

bool operator==(const cpTransform&a,const cpTransform&b){typedef array<char,sizeof(a)> t;return ((t&)a)==((t&)b);}
bool operator==(const cpMat2x2&a,const cpMat2x2&b){typedef array<char,sizeof(a)> t;return ((t&)a)==((t&)b);}

//real sqrdiff(const vec2d&a,const vec2d&b){return a.sqr_dist_to(b);}
real sqrdiff(const cpFloat&a,const cpFloat&b){return sqr(a-b);}
real sqrdiff(const cpVect&a,const cpVect&b){return cpvdistsq(a,b);}
real sqrdiff(const cpTransform&a,const cpTransform&b){return 0;}// diff not required
real sqrdiff(const cpDataPointer&a,const cpDataPointer&b){return 0;}// diff not required
real sqrdiff(const cpMat2x2&a,const cpMat2x2&b){return 0;}// diff not required
real sqrdiff(const int&a,const int&b){return 0;}// diff not required
real sqrdiff(const bool&a,const bool&b){return 0;}// diff not required


template<class TYPE>real sqrdiff(const TYPE&a,const TYPE&b){return a.sqrdiff_to(b);}
template<class TYPE>real sqrdiff(const TYPE*a,const TYPE*b){return 0;}

struct t_zmech{
  struct t_body{
    typedef t_body SelfClass;
    typedef cpBody OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(cpVect,p,1)\
    ADD(cpVect,v,1)\
    ADD(cpFloat,a,10)\
    ADD(cpFloat,w,10)\
    ADD(cpTransform,transform,0)\
    ADD(cpDataPointer,userData,0)\
    ADD(cpVect,v_bias,0)\
    ADD(cpFloat,w_bias,0)\
    //===
    #include "defprovar_v3a.inl"
    //===
  };
  struct t_groove{
    typedef t_groove SelfClass;
    typedef cpGrooveJoint OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(cpVect,grv_tn,0)\
    ADD(cpVect,r1,0)\
    ADD(cpMat2x2,k,0)\
    ADD(cpVect,jAcc,0)\
    ADD(cpVect,bias,0)\
    //===
    #include "defprovar_v3a.inl"
    //===
  };
  struct t_damp{
    typedef t_damp SelfClass;
    typedef cpDampedSpring OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(cpFloat,target_vrn,0)\
    ADD(cpFloat,v_coef,0)\
    ADD(cpVect,r2,0)\
    ADD(cpFloat,nMass,0)\
    ADD(cpVect,n,0)\
    ADD(cpFloat,jAcc,0)\
    //===
    #include "defprovar_v3a.inl"
    //===
  };
  struct t_motor{
    typedef t_motor SelfClass;
    typedef cpSimpleMotor OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(cpFloat,rate,0)\
    ADD(cpFloat,iSum,0)\
    ADD(cpFloat,jAcc,0)\
    //===
    #include "defprovar_v3a.inl"
    //===
  };
  struct t_wheel{
    typedef t_wheel SelfClass;
    typedef ::t_wheel::t_impl OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_body,body,1)\
    ADD(t_groove,groove,0)\
    ADD(t_damp,damp,0)\
    ADD(t_motor,motor,0)\
    //===
    #include "defprovar_v3g.inl"
    //===
  };
  struct t_car{
    typedef t_car SelfClass;
    typedef t_proto_car::t_impl OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_body,body,1)\
    ADD(t_wheel,r,1)\
    ADD(t_wheel,f,1)\
    //===
    #include "defprovar_v3g.inl"
    //===
  };
  struct t_deadline{
    typedef t_deadline SelfClass;
    typedef ::t_deadline OtherSide;
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,ticks_rem,0)\
    ADD(real,pos,0)\
    ADD(bool,ekill,0)\
    //===
    #include "defprovar_v3a.inl"
    //===
    real get_h_after(int t=0)const{return pos+OtherSide::h+OtherSide::get_dl_dir()*(t-ticks_rem);}
  };
  struct t_arbiter{
    typedef cpCollisionHandler*t_collisionHandler;
    typedef const cpShape*p_shape;
    typedef cpBody*p_body;
    typedef std::array<cpContact,CP_MAX_CONTACTS_PER_ARBITER> t_contacts;
    typedef t_arbiter SelfClass;
    typedef cpArbiter OtherSide;
    //#define DEF_PRO_WITHOUT_PTR
    #define DEF_PRO_WITHOUT_DIFF
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(cpFloat,e,$)\
    ADD(cpFloat,u,$)\
    ADD(cpVect,surface_vr,$)\
    ADD(cpDataPointer,data,$)\
    ADD(p_shape,a,$)\
    ADD(p_shape,b,$)\
    ADD(p_body,body_a,$)\
    ADD(p_body,body_b,$)\
    ADD(int,count,$)\
    ADD(cpVect,n,$)\
    ADD(cpBool,swapped,$)\
    ADD(cpTimestamp,stamp,$)\
    ADD(cpArbiterState,state,$)\
    ADD(t_collisionHandler,handler,$)\
    ADD(t_collisionHandler,handlerA,$)\
    ADD(t_collisionHandler,handlerB,$)\
	  ADD(cpArbiterThread,thread_a,$)\
    ADD(cpArbiterThread,thread_b,$)\
    //===
    #include "defprovar_v3a.inl"
    //===
    //
    t_contacts contacts;
    //bool thread_a;
    //bool thread_b;
	  //cpArbiterThread thread_a;
    //cpArbiterThread thread_b;
  };
  struct t_cached_arbiters{
    vector<t_arbiter> arr;
    typedef t_cached_arbiters SelfClass;
    typedef cpHashSet OtherSide;
	  //cpHashSet*cachedArbiters;
    void load_from(OtherSide&ref,cpSpace*space){
      arr.clear();
      cpHashSetFilter(&ref,(cpHashSetFilterFunc)cb_c2cpp,(void*)&arr);
    }
    void save_to(OtherSide&ref,cpSpace*space,vector<cpArbiter*>&out){
      if(ref.entries){
        cpHashSetFilter(&ref,(cpHashSetFilterFunc)cb_wipe,space);// TODO: memory leak?
        QapAssert(!ref.entries);
      }
      for(int i=0;i<arr.size();i++){
        auto&arb=arr[i];
        auto&a=(cpShape*&)arb.a;auto&b=(cpShape*&)arb.b;
				const cpShape*shape_pair[]={a,b};
				cpHashValue arbHashID=CP_HASH_PAIR((cpHashValue)a,(cpHashValue)b);
        auto*parb=arbiter_init(space,a,b);
        cpHashSetInsert(space->cachedArbiters,arbHashID,shape_pair,NULL,parb);
        arb.save_to(parb);
        out.push_back(parb);
        //if(arb.thread_a)cpBodyPushArbiter(arb.body_a,parb);
        //if(arb.thread_b)cpBodyPushArbiter(arb.body_b,parb);
        if(!arb.count)continue;
        if(!space->contactBuffersHead){cpSpacePushFreshContactBuffer(space);}
	      parb->contacts=cpContactBufferGetArray(space);
        cpSpacePushContacts(space,arb.count);
        for(size_t i=0;i<arb.count;i++)parb->contacts[i]=arb.contacts[i];
      }
    }
    cpArbiter*arbiter_init(cpSpace*space,cpShape*a,cpShape*b){
      try_inc_pool(space);
      return cpArbiterInit((cpArbiter*)cpArrayPop(space->pooledArbiters),a,b);
    }
    static void try_inc_pool(cpSpace*space){
      if(space->pooledArbiters->num)return;
	    // arbiter pool is exhausted, make more
	    int count=CP_BUFFER_BYTES/sizeof(cpArbiter);
	    cpAssertHard(count,"Internal Error: Buffer size too small.");
	    cpArbiter*buffer=(cpArbiter*)cpcalloc(1,CP_BUFFER_BYTES);
	    cpArrayPush(space->allocatedBuffers,buffer);
	    for(int i=0;i<count;i++)cpArrayPush(space->pooledArbiters,buffer+i);
    }
    // like cpSpaceArbiterSetFilter
    static cpBool cb_c2cpp(cpArbiter*arb,vector<t_arbiter>&out){
      auto&b=qap_add_back(out);
      b.load_from(arb);
      if(!b.count)return true;
      int gg=1;
      for(size_t i=0;i<b.count;i++)b.contacts[i]=arb->contacts[i];
	    return true;
    }
    static bool empty(cpArbiterThread&ref){
      //this;
      //QapAssert(bool(ref.next)==bool(ref.prev));
      return !ref.next&&!ref.prev;
    }
    static void wipe(OtherSide&ref,cpSpace*space){
      cpHashSetFilter(&ref,(cpHashSetFilterFunc)cb_wipe,space);
    }
    //static cpBool cb_wipe_raw(cpArbiter*arb,cpSpace*space){
	  //  return false;
    //}
    static cpBool cb_wipe(cpArbiter*arb,cpSpace*space){
      cpArrayPush(space->pooledArbiters,arb);
      cpArbiterUnthread(arb);
      /*
      cpArrayPush(space->pooledArbiters,arb);
      bool a=empty(arb->thread_a);
      bool b=empty(arb->thread_b);
      if(a&&b)return false;
      if(!a)unthreadHelper(arb,arb->body_a);
      if(!b)unthreadHelper(arb,arb->body_b);
      */
      //cpSpaceStep;
      //arb->
	    return false;
    }
  };
  struct t_space{
    typedef t_space SelfClass;
    typedef cpSpace OtherSide;
    cpTimestamp stamp;
    //cpTimestamp ds_stamp;
    cpDataPointer userData;
    t_cached_arbiters cachedArbiters;
    static void clear_arbiters(cpSpace*space){
	    cpArray *arbiters = space->arbiters;
	    for(int i=0; i<arbiters->num; i++){
		    cpArbiter *arb = (cpArbiter *)arbiters->arr[i];
		    arb->state = CP_ARBITER_STATE_NORMAL;
		    //if(!cpBodyIsSleeping(arb->body_a) && !cpBodyIsSleeping(arb->body_b)){
			    cpArbiterUnthread(arb);
		    //}
	    }
	    arbiters->num = 0;
    }
    ADLER_DEBUG(static bool&need_save_arbiters(){static bool need_save_arbiters=true;return need_save_arbiters;});
    void load_from(OtherSide&ref){
      this->stamp=ref.stamp;
      this->userData=ref.userData;

      //auto&ref_ds_stamp=((cpBBTree*)ref.dynamicShapes)->stamp;
      //ds_stamp=ref_ds_stamp;

      //cachedArbiters.wipe(*ref.cachedArbiters);
      //
      ADLER_DEBUG(if(!need_save_arbiters())return;);
      clear_arbiters(&ref);
      this->cachedArbiters.load_from(*ref.cachedArbiters,&ref);
      //
      
      auto&arr=cachedArbiters.arr;
      QAP_FOREACH(arr,QapAssert(!ex.data);ex.data=to_dp(i););
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto f=[&](cpArbiter*&ptr){
          //auto&ptr=(cpArbiter*&)ref;
          if(ptr){
            QapAssert(ptr->data);
            int gg=1;
          }
          ptr=(cpArbiter*)(ptr?ptr->data:wrong_ptr());
        };
        f(ex.thread_a.next);
        f(ex.thread_a.prev);
        f(ex.thread_b.next);
        f(ex.thread_b.prev);
      }
      QAP_FOREACH(arr,ex.data=0;);
    }
    static const int smart_mega_offset=9000;
    static cpDataPointer to_dp(size_t id){return (cpDataPointer)(id+smart_mega_offset);}
    static size_t to_id(cpArbiter*ptr){return size_t(ptr)-smart_mega_offset;}
    static const cpDataPointer wrong_ptr(){return (cpDataPointer)8999;}
    static void wipe_space(cpSpace*space){
      clear_arbiters(space);
	    //cpArrayFree(space->arbiters);
	    //cpArrayFree(space->pooledArbiters);
	    //cpHashSetFree(space->cachedArbiters);
      t_cached_arbiters::wipe(*space->cachedArbiters,space);
	    //if(space->allocatedBuffers){
		  //  cpArrayFreeEach(space->allocatedBuffers,cpfree);
		  //  cpArrayFree(space->allocatedBuffers);
	    //}
      //space->arbiters=cpArrayNew(0);
	    //space->pooledArbiters=cpArrayNew(0);
	    //space->cachedArbiters=cpHashSetNew(0,(cpHashSetEqlFunc)arbiterSetEql);
      //
	    //space->contactBuffersHead=NULL;
      if(auto*beg=space->contactBuffersHead){
        for(auto*p=beg;p->next!=beg;p=p->next)p->stamp=0;
      }
    }
    void save_to(OtherSide&ref){
      ref.stamp=this->stamp;
      ref.userData=this->userData;

      update_shapes_aabb(&ref);

      //auto&ref_ds_stamp=((cpBBTree*)ref.dynamicShapes)->stamp;
      //ref_ds_stamp=ds_stamp;

      //
      thread_local vector<cpArbiter*> arr;arr.clear();//arr.reserve(cachedArbiters.arr.size());
      wipe_space(&ref);
      this->cachedArbiters.save_to(*ref.cachedArbiters,&ref,arr);
      //
      //QAP_FOREACH(arr,QapAssert(!ex.data);ex.data=(cpDataPointer)i;);
      for(int i=0;i<arr.size();i++){
        auto&ex=*arr[i];
        auto f=[&](cpArbiter*&ptr){
          //auto&ptr=(cpArbiter*&)ref;
          auto zero=ptr==(cpArbiter*)wrong_ptr();
          if(!zero){
            int gg=1;
          }
          auto id=to_id(ptr);
          if(!zero)QapAssert(qap_check_id(arr,id));
          ptr=!zero?arr[id]:(cpArbiter*)nullptr;
        };
        f(ex.thread_a.next);
        f(ex.thread_a.prev);
        f(ex.thread_b.next);
        f(ex.thread_b.prev);
      }
      bool gg=1;
      //QAP_FOREACH(arr,QapAssert(ex.data);ex.data=0;);
    }
    void load_from(OtherSide*ptr){if(ptr)load_from(*ptr);}
    void save_to(OtherSide*ptr){if(ptr)save_to(*ptr);}
    real sqrdiff_to(const SelfClass&ref)const{return 0;}
    bool is_equal_to(...){return false;}
  };
  typedef t_zmech SelfClass;
  typedef t_mech OtherSide;
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_deadline,dl,0)\
  ADD(t_car,mcar,1)\
  ADD(t_car,ecar,1)\
  ADD(t_space,space,0)\
  //===
  #include "defprovar_v3g.inl"
  //===
public:
  ADLER_DEBUG(bool endlog=false);
public:
  const t_zmech&fork(){return *this;}
  void reset(){*this=t_zmech();}
  string toBinStr(){
    string s;
    s.resize(sizeof(mcar));
    auto&out=(t_car&)s[0];
    out=mcar;
    return s;
  }
};
static const auto sizeof_t_zmech=sizeof(t_zmech); //1560

static void chipFree(t_mech&ref){ref.free();}

static QapClock cbat;real cbat_ms=0;int cbat_n=0;
void qap_cpBodyActivate_bef(){
  cbat.Start();
}
void qap_cpBodyActivate_aft(){
  cbat.Stop();
  cbat_ms+=cbat.MS();
  cbat_n++;
}

typedef vector<t_plan> t_movdirs;

struct t_sim_env{
  int pId=0;
  t_score score;
  t_plan plan;
  t_mech*pmech;
  t_zmech zmech;
  t_movdirs emd_bests;
  int sim_limit=0;
};

struct t_upd_ws{
  t_upd upd;
  int stamp=0;
  bool m,e;
  bool endlog=false;
  void load_from(t_mech&mech){
    upd.grab_from(mech);
    stamp=mech.space->stamp;
    m=mech.me_deaded(1);
    e=mech.me_deaded(0);
  }
};

struct t_plan_with_dbg{
  t_plan plan;
  string dbg;
  t_score score;
  vector<t_sim_env> envs;
  vector<t_upd_ws> log;
  int sim_limit=0;
  int base_stamp=0;
  t_plan_with_dbg&err(const string&msg){dbg+="err:"+msg;return *this;}
  t_plan_with_dbg&set(const t_plan&ref){plan=ref;return *this;}
};

#pragma endregion before_app

//=============================================================================================
//=============================================================================================
//=============================================================================================
#ifdef Adler
static t_mech*g_pmech=nullptr;
std::mutex g_app_cur_mech_mutex;
int g_curset_iter=0;
QapClock g_curset_clock;
#define QAP_MUTEX_GUARD_SCOPE()std::lock_guard<std::mutex> guard(g_app_cur_mech_mutex);
#define QAP_MUTEX_GUARD(CODE){QAP_MUTEX_GUARD_SCOPE();CODE;}
#else
#define QAP_MUTEX_GUARD_SCOPE();
#define QAP_MUTEX_GUARD(CODE)CODE;
#endif
struct t_app{
  #pragma region OLD_CORE
  static vector<t_plan> get_movdirs_v0(int sim_limit){
    vector<t_plan> out;int dirs=3;
    //for(int k=0;k<dirs;k++)
    {
      //auto dir3=k-1;
      for(int t=1;t<sim_limit-1;t+=2)
      for(int i=0;i<dirs;i++){
        auto dir1=i-1;
        for(int j=0;j<dirs;j++){
          auto dir2=j-1;
          qap_add_back(out).add(t,t_move().set(dir1)).add(sim_limit,t_move().set(dir2));/*.add(sim_limit,t_move().set(dir3));*/
        }
      }
    }
    return out;
  }
  struct t_msg{
    bool new_match;
    t_new_match match;
    t_upd upd;
    bool parse(const string&line)
    {
      auto doc=unsafe_get_doc(line);
      string doc_type=doc["type"].GetString();
      new_match="new_match"==doc_type;
      auto&params=doc["params"];
      if(new_match){
        match.load(params);
      }else{
        QapAssert("tick"==doc_type);
        if("tick"==doc_type)upd.load(params);
        ADLER_DEBUG(if(params["my_car"].GetArray().Size()==6)if(!params["my_car"][5].GetBool()||!params["enemy_car"][5].GetBool())return false;);
      }
      int gg=1;
      return true;
    }
  };
  typedef vector<t_move> t_moves;
  struct t_our_moves_with_base{
    t_zmech base;
    struct t_rec{
      t_upd upd;
      t_move m;
    };
    vector<t_rec> arr;
    int n=3;
    void reset(){base.reset();arr.clear();/*arr.resize(n);*/}
    void add(t_mech&mech,const t_move&move,t_moves&emoves,t_upd&upd)
    {
      bool ok=arr.size()==n;
      auto*p=ok?&arr.back():&qap_add_back(arr);
      if(ok)
      {
        QapAssert(emoves.size()==arr.size());
        mech.load(base);
        mech.make_all_alive();
        mech.apply_direct(true,arr[0].m);
        mech.apply_direct(false,emoves[0]);
        NEED_APPLY_UPD()mech.megasync(arr[0].upd);
        mech.tickEvent();
        mech.save(base);
        for(int i=1;i<arr.size();i++)arr[i-1]=arr[i-0];
      }
      p->m=move;p->upd=upd;
    }
  };
  static string tostr(t_moves&arr){
    string out;QAP_FOREACH(arr,out.push_back(toupper(tmove2str(ex)[0])));return out;
  }
  //=============================================================================================
  i_two_stream*pstream=nullptr;
  int match_id=-1;
  int gframe_id=-1;
  int frame_id=-1;
  t_new_match match;
  t_upd upd;
  unique_ptr<t_plan_with_dbg> prev_cmd;
  bool keep_cur_plan=false;
  t_plan cur_plan;
  t_zmech cur_mech;
  t_our_moves_with_base omwb;
  //---
  t_upd debug_upd;
  //=============================================================================================
  #define toStr std::to_string
  struct t_server_side_rec{
    int seg=0;
    int dirs=0;
    real ms_per_dir=0;
    string to_str()const{return "{seg:"+toStr(seg)+",dirs:"+toStr(dirs)+",ms:"+toStr(ms_per_dir)+"}";}
  };
  struct t_server_side_item{
    int segements=128;
    real ms=20.5;
    real total_ms=0;
    int n=0;
    real get_average()const{return !n?0:total_ms/n;}
    bool operator<(const t_server_side_item&ref)const{return segements<ref.segements;}
    string to_str()const{return "f("+toStr(segements)+","+toStr(get_average())+");";}
  };
  #undef toStr
  struct t_server_side{
    real TL=real(117*1000)/(1200*10);
    t_server_side_rec last;
    vector<t_server_side_item> items;
    vector<t_server_side_rec> arr;
    PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(t_server_side_item,add_item,items,int,segements);
    t_server_side(){fixed_config();}
    void add(int dirs,int seg,real ms){
      auto&b=*add_item(seg);
      b.n++;
      b.total_ms+=ms/dirs;
      auto&r=qap_add_back(arr);
      r.dirs=dirs;
      r.seg=seg;
      r.ms_per_dir=ms/dirs;
      last=r;
    }
    string to_str(const char*glue=""){
      vector<string> out;
      qap_sort(items);
      for(int i=0;i<items.size();i++){
        auto&ex=items[i];
        if(!ex.n)continue;
        qap_add_back(out)=ex.to_str();
      }
      return join(out,glue);
    }
    void clear()
    {
      items.clear();arr.clear();
    }
    void fixed_config()
    {//return;
      auto f=[this](int seg,real ms){auto&out=*add_item(seg);out.segements=seg;out.ms=ms;return out;};
      //unix server emdirsv0
      f(6,1.443058);f(67,1.579640);f(68,1.577182);f(97,2.127213);f(128,2.451806);
      //unix server emdirsv1
      f(6,6.199827);f(67,6.483378);f(68,6.192745);f(97,9.197100);f(128,9.566473);
      //orig
      f(6,6.581098);f(67,9.989724);f(68,10.480325);f(70,12.210772);f(97,11.379840);f(128,13.181646);
      //orig with arbiters
                    f(67,8.684359);               f(70,13.831697);f(97,10.076846);f(128,11.777444);
      f(6,6.154196);f(67,8.494312);f(68,7.886447);f(70,11.219274);f(97,10.854121);
      f(6,8.159112);/*67,7.918847*/f(68,9.241741);f(70,13.724821);//97,9.3158860);f(128,10.655651);
                                   f(68,10.58134);f(70,13.653905);f(97,14.310344);f(128,20.591040);
                    f(67,12.08844);f(68,11.82104);f(70,16.083895);//f(97,12.786660);
                    /*
                    SIMLIMIT:80
                    f(67,2.652363);f(68,2.652498);f(97,3.077664);f(128,4.002877);
                    */
    }
    real seg2ms(int seg){return add_item(seg)->ms;}
    real get_dirs_per_tick(int players_per_dir)
    {
      auto ms_per_dir=seg2ms(players_per_dir);
      return TL/ms_per_dir;
    }
    real get_dirs_per_tick_v2(int players_per_dir,real TL_koef)
    {
      auto ms_per_dir=seg2ms(players_per_dir);
      return TL*TL_koef/ms_per_dir;
    }
  };
  t_server_side server_side;
  //=============================================================================================
  t_move qap_run_apply(unique_ptr<t_plan_with_dbg>&&up_cmd)
  {
    t_move out;
    cur_plan=up_cmd->plan;
    cur_plan.try_save_move_and_promote(out,true);
    QAP_MUTEX_GUARD(prev_cmd=std::move(up_cmd););
    return out;
  }
  static const string&tmove2str(const t_move&m){
    static const string arr[]={"stop","left","right"};
    if(+0==m.dir)return arr[0];
    if(-1==m.dir)return arr[1];
    if(+1==m.dir)return arr[2];
    return arr[0];
  }
  static const t_move str2tmove(const string&m){
    static const string arr[]={"stop","left","right"};
    t_move out;out.dir=0;
    if(arr[0]==m)out.dir=+0;
    if(arr[1]==m)out.dir=-1;
    if(arr[2]==m)out.dir=+1;
    return out;
  }
  static string dump(const t_move&m,const string&raw_dbg){
    vector<string> out;
    qap_add_back(out)=jk("command",jq(tmove2str(m)));
    if(!raw_dbg.empty()&&jq("")!=raw_dbg)qap_add_back(out)=jk("debug",raw_dbg);
    return jobj(join(out,","));
  }
  static string string2json(const string&s){
    Document d;
    d.SetString(s.c_str(),d.GetAllocator());
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    return buffer.GetString();
  }
  //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------- APP::Main
  bool withSleep=false;
  const real time_limit_ms=120*1000.0;
  real total_ms=0;real match_ms=0;real total_GTL=0;
  static const int poor_ticks_n=4;int poor_ticks=poor_ticks_n;
  bool mcar_in_air=false;
  bool prev_mcar_in_air=false;
  void main()
  {
    t_moves emoves;
    real prev_iter_ms=0;
    real prev_glt_ms=0;
    vector<string> lines;
    string line;
    QapClock iter_clock;
    gframe_id=0;
    #ifdef Adler
    fstream dout,dlines;
    //("dout.json",ostream::out);
    dout.open("dout.json",std::ios::out|std::ios::trunc);
    dlines.open("lines.json",std::ios::out|std::ios::trunc);
    #endif
    ADLER_DEBUG(g_pmech=&g_mech);
    for(int i=0;!pstream->eof();i++)
    {
      iter_clock.Stop();
      prev_iter_ms=iter_clock.MS();
      ADLER_DEBUG(if(0)if(frame_id==7)pause=true;lock_step=false;while(pause&!lock_step){Sleep(16);});
      iter_clock.Start();
      QapClock get_line_time;
      line=pstream->getline();
      get_line_time.Stop();
      line=join(split(join(split(line,"\r"),""),"\n"),"");
      if(line.empty())continue;
      ADLER_DEBUG(dlines<<line<<"\n";dlines.flush(););
      qap_add_back(lines)=line;
      t_msg msg;
      bool ok=msg.parse(line);
      if(!ok)continue;
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      if(msg.new_match)
      {
        match=msg.match;
        match_id++;
        match_ms=0;
        frame_id=-1;
        total_ms+=iter_clock.MS();
        if(!keep_cur_plan)cur_plan=t_plan();
        cur_mech.reset();
        omwb.reset();
        poor_ticks=poor_ticks_n;
        mcar_in_air=false;
        prev_mcar_in_air=false;
        prev_glt_ms=get_line_time.MS();
        total_GTL+=prev_glt_ms;
        continue;
      }
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      frame_id++;
      upd=msg.upd;      
      ADLER_DEBUG(if(withoutbrain||withSleep)Sleep(16));
      if(0)if(poor_lvl()){
        t_move out;out.set(0);
        cur_plan.try_save_move_and_promote(out,true,false);
        pstream->send_with_endl(dump(out,string2json(--poor_ticks>0||(gframe_id%16==0)?"poor_lvl="+IToS(frame_id):"")));
        gframe_id++;
        continue;
      }
      real diff_bef=0;real diff_aft=0;
      QapClock clock_fuem;

      //auto&dmcbp=g_debugmech.mcar.body->p;
      //auto&umcp=upd.my_car.pos;
      //auto&cmmcbp=cur_mech.mcar.body.p;

      if(!frame_id){
        t_world world;world.conf=&match;world.upd=upd;
        auto reload_mech=[&world](t_mech&m){
          if(m.space){m.free();m=t_mech();}
          m.ignore_log=true;
          m.load_from(world);
          m.need_load=false;
        };
        auto reload=[&](t_mech&dm){
          reload_mech(dm);
          QAP_FOREACH(dm.buff.arr,cpSpaceRemoveShape(dm.space,ex));
        };
        
        ADLER_DEBUG(QAP_MUTEX_GUARD(reload_mech(g_debugmech);reload(g_debugmech_log);debug_upd=upd;));
        reload_mech(g_mech);
        g_mech.save(cur_mech);
        omwb.base=cur_mech.fork();
      }else if(!withoutbrain)
      {
        emoves=find_unk_enemy_moves(g_mech,upd,omwb);
        //QAP_FOREACH(emoves,ex.dir=0);
        g_mech.load(omwb.base);
        sim_steps_v3(g_mech,omwb.arr,emoves);
        diff_bef=g_mech.diff(upd);
        NEED_APPLY_UPD()g_mech.megasync(upd);
        g_mech.make_all_alive();
        diff_aft=g_mech.diff(upd);
        prev_mcar_in_air=mcar_in_air;
        mcar_in_air=g_mech.in_air(g_mech.mcar);
        g_mech.save(cur_mech);
        ADLER_DEBUG(QAP_MUTEX_GUARD(
          g_debugmech.drop();
          auto tmp=cur_mech;
          tmp.space.cachedArbiters.arr.clear();
          g_debugmech.load(tmp);
          debug_upd=upd;
        ));
        int gg=1;
      }
      clock_fuem.Stop();
      unique_ptr<t_plan_with_dbg> up_cmd;up_cmd.reset(new t_plan_with_dbg());auto&cmd=*up_cmd;
      if(!withoutbrain)on_tick(cmd);// <------------------------------------------------------------------------------- 90% cpu time here
      auto iter_dt=prev_iter_ms-prev_glt_ms;
      total_GTL+=prev_glt_ms;
      prev_glt_ms=get_line_time.MS();
      total_ms+=iter_dt;
      match_ms+=iter_dt;
      vector<string> timers;
      qap_add_back(timers)="FID:"+std::to_string(frame_id);
      qap_add_back(timers)="TGLT:"+to_string(int(total_GTL));
      qap_add_back(timers)="PREV:"+std::to_string(prev_iter_ms);
      qap_add_back(timers)="TOT:"+std::to_string(total_ms);
      qap_add_back(timers)="M4T:"+std::to_string(int(match_ms));
      qap_add_back(timers)="WIN:"+std::to_string(cmd.score.id);
      qap_add_back(timers)="EM:"+tostr(emoves);
      //qap_add_back(timers)="GLT:"+to_string(get_line_time.MS());
      qap_add_back(timers)="DB:"+to_string(diff_bef);
      qap_add_back(timers)="DA:"+to_string(diff_aft);
      qap_add_back(timers)="SC:"+to_string(cmd.score.score);
      bool full=gframe_id%500==499;
      if(!full)cmd.dbg=jobj(join(timers,","))+":@:"+cmd.dbg;
      if(0==frame_id)cmd.dbg="/* ###_BUILD_TIME_### */ "+cmd.dbg;
      if(!withoutbrain)
      {
        auto cur_move=qap_run_apply(std::move(up_cmd));
        //cur_move.dir=0;
        omwb.add(g_mech,cur_move,emoves,upd);
        string s=dump(cur_move,string2json(cmd.dbg));
        pstream->send_with_endl(s);
        
        #ifdef Adler
        dout<<s<<endl;dout.flush();
        #endif
      }
      gframe_id++;
    }
    pstream->send_with_endl(server_side.to_str());
    //file_put_contents("lines.json",join(lines,"\n"));
  }
  #pragma region FUEM
  static real calc_diff(const t_upd&a,const t_mech&b){
    return b.diff(a);
  }
  static void sim_steps_v3(t_mech&mech,vector<t_our_moves_with_base::t_rec>&m,t_moves&e){
    QapAssert(m.size()==e.size());
    for(int i=0;i<m.size();i++){
      mech.apply_direct(true,m[i].m);
      mech.apply_direct(false,e[i]);
      mech.tickEvent();
      int gg=1;
    }
  }
  static t_moves&get_all_possible_moves(){
    static t_moves arr;if(arr.empty()){arr.resize(3);for(int i=0;i<3;i++)arr[i].dir=i-1;std::swap(arr[0],arr[1]);}return arr;
  }
  struct t_moves_with_score{
    real score=0;
    t_moves arr;
    static void build(vector<t_moves_with_score>&out,int depth,t_moves*p=nullptr){
      vector<t_move> tmp;if(!p){p=&tmp;}
      if(depth==p->size()){if(depth)qap_add_back(out).arr=*p;return;}
      auto&arr=get_all_possible_moves();
      qap_add_back(*p);
      QAP_FOREACH(arr,p->back()=ex;build(out,depth,p));
      p->pop_back();
    }
  };
  static t_moves find_unk_enemy_moves(t_mech&mech,t_upd&cur,t_our_moves_with_base&omwb){
    //cur==prev+(our_move+unk_enemy_move);
    auto&prev=omwb.base;
    auto n=omwb.arr.size();
    thread_local vector<vector<t_moves_with_score>> n2arr;
    if(n2arr.size()!=omwb.n+1){n2arr.resize(omwb.n+1);}
    QapAssert(n>0&&qap_check_id(n2arr,n));
    auto&arr=n2arr[n];
    if(arr.empty()){t_moves_with_score::build(arr,n);}
    auto f=[&](t_moves_with_score&ex){
      mech.load(prev);
      sim_steps_v3(mech,omwb.arr,ex.arr);
      ex.score=calc_diff(cur,mech);
      mech.drop();
      return ex.score;
    };
    auto id=QAP_MINVAL_ID_OF_VEC(arr,f(ex));
    return arr[id].arr;
  }
  #pragma endregion
  struct t_cheap_trigger{
    int sync_period=48;
    int next_sync_frame_id=sync_period;
    real threshold=60;
    bool alarm=true;
    bool frozen=false;
    bool on_frozen=false;
    bool on_active=true;
    int prefered_sim_limit=0;
    vec2d mpos;
    vec2d epos;
    void load(t_zmech&m){mpos=to_vec2d(m.mcar.body.p);epos=to_vec2d(m.ecar.body.p);}
    void sync(const t_cheap_trigger&ref){
      #define F(NAME)this->NAME=ref.NAME;
      F(next_sync_frame_id);
      F(sync_period);
      F(threshold);
      F(alarm);
      F(frozen);
      #undef F
    }
    void weakup(t_app&a){
      next_sync_frame_id=a.frame_id+sync_period;
      bool new_frozen=next_sync_frame_id<a.frame_id;
      on_frozen= new_frozen&&!frozen;
      on_active=!new_frozen&& frozen;
      alarm=true;
      frozen=new_frozen;
    }
    void update(t_app&a){
      t_cheap_trigger tmp=*this;
      tmp.load(a.cur_mech);
      auto err=0.0;
      err+=tmp.epos.sqr_dist_to(epos);
      err+=tmp.mpos.sqr_dist_to(mpos);
      bool new_alarm=(err>threshold*threshold)||!is_safe_dist();
      bool new_frozen=next_sync_frame_id<a.frame_id;
      if(bool look_like_active=new_alarm){
        *this=tmp; // copy something like epos mpos
        next_sync_frame_id=a.frame_id+sync_period;
        new_frozen=false;
      }
      on_frozen= new_frozen&&!frozen;
      on_active=!new_frozen&& frozen;
      alarm=new_alarm;
      frozen=new_frozen;
      if(on_frozen)prefered_sim_limit=get_prefered_sim_limit();
    }
    bool is_safe_dist(){
      return true;//epos.dist_to(mpos)>400;
    }
    int get_prefered_sim_limit(){
      auto dist=std::min<int>(400,epos.dist_to(mpos));
      auto f=[](int dist){return 18+(64-18)*(1.0-dist/400.0);};
      QapAssert(f(400)==18);
      QapAssert(f(000)==64);
      return f(dist);
    }
  };
  t_cheap_trigger cheap_trigger;
  static const int our_id=1;
  static const int opp_id=0;
  struct t_sim_mech_logger;
  static const int hard_begin_frame_id=162;
  bool is_bus()const{return match.proto_car.external_id==2;}
  bool is_swb()const{return match.proto_car.squared_wheels;}
  bool is_buggy()const{return !is_bus()&&!is_swb();}
  bool is_pillplatform()const{return match.get_seg()==68;}//PillCarcassMap
  bool is_pillmap()const{return match.get_seg()==67;}//PillsMap
  bool is_pillhubble()const{return match.get_seg()==97;}//PillHubbleMap
  bool is_pillhill()const{return match.get_seg()==128;}//PillHillMap
  bool is_hole_map()const{return match.get_seg()==70;}//IslandHoleMap
  bool is_simple_map()const{return match.get_seg()==6;}//IslandMap
  bool is_map_with_toplvl()const{auto m=match.proto_map.external_id;return !is_simple_map();}
  bool is_begin()const{return frame_id<hard_begin_frame_id;}
  struct t_map_sim_limit{
    int beg=126;int norm=86;/*int begin_frame_diff=0;*/bool with_begin=true;
    t_map_sim_limit&set(int b,int n){beg=b;norm=n;return*this;}
    int get(bool is_begin){return is_begin&&with_begin?beg:norm;}
  };
  t_map_sim_limit get_map_sim_limit()const{
    if(is_pillplatform()&&is_buggy())return t_map_sim_limit().set(86,86);
    if(is_pillplatform())return t_map_sim_limit().set(155,86);
    if(is_pillhill())return t_map_sim_limit().set(155,86);
    if(is_pillhubble())return t_map_sim_limit().set(155,86);
    if(is_simple_map())return t_map_sim_limit().set(126,86);
    if(is_hole_map()&& is_bus())return t_map_sim_limit().set(64,64);
    if(is_hole_map()&&!is_bus())return t_map_sim_limit().set(126,86);
    return t_map_sim_limit();
  }
  const int get_sim_limit()const{return get_map_sim_limit().get(is_begin());}
  bool is_under_attack()const{return prev_cmd&&prev_cmd->score.score<0;}
  bool is_going_to_die()const{return prev_cmd&&prev_cmd->score.score<-1.89;}
  bool deadline_alarm(int sim_limit)const{auto&m=cur_mech;return m.mcar.body.p.y<m.dl.get_h_after(sim_limit);}
  t_movdirs movdirs;
  t_movdirs emovdirs,emdv2_bests,prev_alarm;
  std::array<t_movdirs,256> cache_mdirs[2];
  void build_mdirs(int sim_limit){
    if(!movdirs.empty())return;
    movdirs_sim_limit=sim_limit;
    auto&c=cache_mdirs[cheap_trigger.frozen][sim_limit];
    if(!c.empty()){movdirs=c;return;}
    if(cheap_trigger.frozen){
      movdirs=build_movdirs_v3(sim_limit);
    }else{
      movdirs=build_movdirs_v6d2(sim_limit);
    }
    c=movdirs;
  }
  t_movdirs&get_emovdirs(int edpt){
    emovdirs=copy_subarr(movdirs,frame_id*edpt,edpt);
    emdv2_bests.resize(std::min<int>(emdv2_bests.size(),1));
    QAP_FOREACH(prev_alarm,ex=ex.get_promoted());
    QAP_FOREACH(emdv2_bests,ex=ex.get_promoted());
    QAP_FOREACH(emdv2_bests,if(ex.valid())qap_add_unique_val(emovdirs,ex));
    return emovdirs;
  }
  bool is_prev_frame_under_attack=false;
  //std::stack<int> cur_sim_limits;
  int cur_sim_limit=0;
  int movdirs_sim_limit=0;
  void on_tick(t_plan_with_dbg&out)
  {
    if(keep_cur_plan){
      out.plan=cur_plan;
      return;
    }
    if(!frame_id){cheap_trigger=t_cheap_trigger();movdirs.clear();emovdirs.clear();emdv2_bests.clear();prev_alarm.clear();}
    cheap_trigger.update(*this);
    if(is_begin())cheap_trigger.weakup(*this);
    if(!is_bus()&&is_simple_map())cheap_trigger.weakup(*this);

    const int base_sim_limit=get_sim_limit();
    if(!frame_id){cur_sim_limit=base_sim_limit;}

    if(deadline_alarm(base_sim_limit))if(!(is_bus()&&(is_hole_map()||is_pillplatform())))cheap_trigger.weakup(*this);

    if(cheap_trigger.on_active)cur_sim_limit=base_sim_limit;
    if(cheap_trigger.on_frozen)cur_sim_limit=cheap_trigger.prefered_sim_limit;
    if(total_ms>100*1000)cur_sim_limit=86;
    const bool we_dont_havetime=total_ms>80*1000;

    const int sim_limit=cur_sim_limit;

    if(sim_limit!=movdirs_sim_limit){movdirs.clear();/*emovdirs.clear();emdv2_bests.clear();prev_alarm.clear();*/}
    build_mdirs(sim_limit);

    if(!is_prev_frame_under_attack&&is_under_attack()){
      prev_alarm=emdv2_bests;
      is_prev_frame_under_attack=true;
    }
    if(!is_under_attack())is_prev_frame_under_attack=false;

    bool on_ground_event=!mcar_in_air&&prev_mcar_in_air;
    if(total_ms>80*1000)on_ground_event=false;

    auto emovdirs_n=cheap_trigger.frozen?3:(is_under_attack()?8:4)*(on_ground_event?2:1);
    emovdirs_n=we_dont_havetime?1:emovdirs_n;

    auto&emovdirs=get_emovdirs(emovdirs_n);
    //QAP_FOREACH(emovdirs,ex=emovdirs[0]);

    const auto&cur_movdirs=movdirs;

    const auto seg=match.get_seg();
    auto dirs_per_tick=frame_id<16||on_ground_event?8:(is_under_attack()||deadline_alarm(sim_limit)?4:1);//server_side.get_dirs_per_tick(seg)*2.25;
    if(cheap_trigger.frozen)dirs_per_tick=deadline_alarm(sim_limit)?3:2;
    if(we_dont_havetime)dirs_per_tick=1;
    auto dpt=std::max<int>(1,dirs_per_tick);

    auto curset=copy_subarr(cur_movdirs,frame_id*dpt,dpt);
    //curset.clear();
    //curset=cur_movdirs;
    #ifdef Adler
    if(bool need_shuffle=false){
      std::random_device rd;
      std::mt19937 g(rd());
      std::shuffle(curset.begin(),curset.end(),g);
    }
    #endif
    //curset=cur_movdirs;if(frame_id%sim_limit!=0)curset.clear();
    

    if(cur_plan.valid())qap_add_back(curset)=cur_plan;
    QapClock server_side_clock;
    auto&envs=out.envs;
    envs.resize(curset.size());
    ADLER_DEBUG(g_curset_clock.Start(););
    #ifdef AdlerOMP
    #pragma omp parallel for schedule(dynamic,1)
    #endif

    for(int i=0;i<curset.size();i++)
    {
      ADLER_DEBUG(g_curset_iter=i;)
      auto&env=envs[i];
      env.score.id=i;
      env.pId=our_id;
      env.sim_limit=sim_limit;
      env.plan=curset[i];
      t_sim_mech_logger*plogger=nullptr;
      ADLER_DEBUG(if(bool need_logger=0){
        t_sim_mech_logger logger;
        logger.plog=&out.log;
        plogger=&logger;
      });
      sim_auto(emovdirs,env,plogger);
      int gg=1;
      env.score.id=i;
      QapAssert(env.score.id==i);
    }
    
    server_side.add(curset.size(),match.get_seg(),server_side_clock.MS());
    if(server_side.last.seg)
    {
      bool full=gframe_id%500==499;
      if(full)out.dbg="";
      out.dbg+=(out.dbg.empty()?"":":@:")+(
        full?server_side.to_str():server_side.last.to_str()
      );
      auto ms_allowed=server_side.seg2ms(seg);
      out.dbg+=":@:{C/F:"+std::to_string(!ms_allowed?-1:server_side.last.ms_per_dir/ms_allowed)+",'seg2ms':"+std::to_string(ms_allowed)+"}";
    }
    //out.dbg+=(out.dbg.empty()?"":":@:")+server_side.last.to_str();
    auto id=QAP_MINVAL_ID_OF_VEC(envs,ex.score);
    if(id<0)
    {
      out.err("curset.empty();");
      return;
    }
    auto&win=envs[id];
    out.plan=win.plan;
    out.score=win.score;
    emdv2_bests=win.emd_bests;
    //out.dbg+=":@:"+out.score.to_str();
    #ifdef Adler
    if(bool need_full_debug_info=1){
      //ok
      t_sim_env env;
      env.score.id=win.score.id;
      env.pId=our_id;
      env.sim_limit=sim_limit;
      env.plan=win.plan;
      t_sim_mech_logger logger;
      logger.plog=&out.log;
      sim_auto(emovdirs,env,&logger);
    }else{
      envs.clear(); //pointless but...
    }
    #endif
    //mwd.dbg=jobj("s:"+std::to_string(score[id]));
    int gg=1;
  }
  real get_ms_per_match(){
    auto t=frame_id;
    auto ML=match.my_lives;auto EL=match.enemy_lives;

    int n_match=(ML-1)/*+(EL-1)*/+1;
    if(!n_match)return true;
    real remaining_time=time_limit_ms-total_ms;
    real n_match_time=match_ms+remaining_time;
    real ms_per_match=n_match_time/n_match;
    return ms_per_match;
  }
  void sim_auto(t_movdirs&emovdirs,t_sim_env&env,t_sim_mech_logger*plogger=nullptr){
    env.pmech=&g_mech;
    env.zmech=cur_mech;
    
    t_sim_v7_env e;
    e.pmech=&g_mech;
    e.zmech=cur_mech;
    e.sim_limit=env.sim_limit;
    e.pemd_bests=&env.emd_bests;
    env.score=sim_v5_full_v2(emovdirs,e,env.plan,plogger);
  }
  // <--------------------------------------POOR LVL----------------------------------------------POOR LVL---------------------------POOR LVL-------------------------------------------- POOR LVL
  bool dont_leave(){
    if(!prev_cmd)return false;
    auto&cmd=*prev_cmd;
    if(cmd.score.score>+0.8)return true;
    if(cmd.score.score<-0.4)return true;
    return false;
  }
  bool poor_lvl(){
    //return false;
    if(!frame_id)return false;
    if(match.my_lives==1)return false;
    if(match.enemy_lives==1&&match.proto_map.segments.size()<100)return false;
    auto t=frame_id;
    real ms_per_match=get_ms_per_match();
    if(dont_leave())return match_ms>ms_per_match*2;
    if(match_ms>ms_per_match)return true;
    time_limit_ms;ms_per_match;match_ms;

    //map0 need 410 frames to win hard game no more;

    /*
    auto m=match.proto_map.external_id;
    bool buhanka=match.proto_car.external_id==2;
    bool a_lot_of_static_segments=m==2||m==3;
    bool norm=m==1;
    if(norm)t-=64;
    if(m==5)return false;
    if(t>=275)if(buhanka&&a_lot_of_static_segments)return true;
    return t>450;
    */
    return false;
  }
  t_mech g_mech,g_debugmech,g_debugmech_log;
  struct t_host;
  struct i_sim_elem{
    virtual void bef(t_mech&mech,int sim_limit){}
    virtual void aft(t_mech&mech){}
    virtual void apply_direct(t_mech&mech,int i){}
    virtual void iter_next(t_mech&mech,int i){}
  };
  struct t_sim_mech_logger:i_sim_elem{
    vector<t_upd_ws>*plog=nullptr;
    int last_id=0;
    int log_id=0;
    //===
    #ifdef Adler
    void iter_next(t_mech&mech,int i)
    {
      if(!plog)return;
      last_id=plog->size();
      auto&log=qap_add_back(*plog);
      t_zmech::t_space::need_save_arbiters()=false;
      log.load_from(mech);
      t_zmech::t_space::need_save_arbiters()=true;
    }
    void aft(t_mech&mech){
      if(!plog)return;
      ADLER_DEBUG(plog->at(last_id).endlog=true;);
      log_id++;
    }
    #endif
  };
  struct t_player_score_counter:i_sim_elem{
    int pId=1;
    t_score out;
    real time_koef=1.0;
    //---
    void iter_next(t_mech&mech,int i)
    {
      out.ticks_to_deadline=mech.dl.ticks_rem;

      out.score=-mech.get_score_diff(pId);
      out.btnH=-mech.get_btnH_diff(pId);
      out.H=-mech.get_cogH_diff(pId);
      out.energy=mech.get_energy_diff(pId);
      
      out.total_score+=out.score*time_koef;
      out.total_btnH+=out.btnH*time_koef;
      out.total_H+=out.H*time_koef;
      out.total_energy+=out.energy*time_koef;

      time_koef*=(127.0/128.0);
    }
  };
  struct t_sim_v7_env{
    t_mech*pmech=nullptr;
    t_zmech zmech;
    t_movdirs*pemd_bests=nullptr;
    int sim_limit=0;
  };
  static void sim_v7_core(t_mech&mech,int sim_limit,vector<i_sim_elem*>&elems)
  {
    QAP_FOREACH(elems,ex->bef(mech,sim_limit));
    //run simulation
    for(int iter=0;iter<sim_limit;iter++)
    {
      QAP_FOREACH(elems,ex->apply_direct(mech,iter));
      mech.tickEvent();
      QAP_FOREACH(elems,ex->iter_next(mech,iter));
    }
    QAP_FOREACH(elems,ex->aft(mech));
  }
  static void sim_v7_main(t_sim_v7_env&env,vector<i_sim_elem*>&elems)//
  {
    auto&zmech=env.zmech;
    auto&mech=*env.pmech;
    mech.load(zmech);
    sim_v7_core(mech,env.sim_limit,elems);
    mech.drop();
  }
  struct t_brains:i_sim_elem{
    struct t_rec{
      int pId=0;
      t_plan_runner PR;
    };
    vector<t_rec> recs;
    void bef(t_mech&mech,int sim_limit)
    {
      for(int i=0;i<recs.size();i++)
      {
        auto&ex=recs[i];
        ex.PR.restart();
      }
    }
    void apply_direct(t_mech&mech,int iter)
    {
      for(int i=0;i<recs.size();i++)
      {
        auto&ex=recs[i];
        auto&m=ex.PR.next();
        mech.apply_direct(ex.pId,m);
      }
    }
  };
  struct t_sim_core{
    t_sim_v7_env&env;
    const t_movdirs&emovdirs;
    const vector<int>&enemy_pIds;
    t_sim_mech_logger*plogger=nullptr;
    t_sim_core(
      t_sim_v7_env&env,
      const t_movdirs&emovdirs,
      const vector<int>&enemy_pIds,
      t_sim_mech_logger*plogger=nullptr
    ):env(env),emovdirs(emovdirs),enemy_pIds(enemy_pIds),plogger(plogger){}
    void enemy_brain_v3(vector<t_score>&out,t_brains&brains,int enemy_pId,vector<int>*p_best_eplans)
    {
      const auto&curset=emovdirs;
      vector<t_score> ms;ms.resize(curset.size());
      vector<t_score> es;es.resize(curset.size());
      for(int i=0;i<curset.size();i++)
      {
        t_player_score_counter mc;mc.pId=1;
        t_player_score_counter ec;ec.pId=0;ec.out.id=i;

        vector<i_sim_elem*> elems;
        qap_add_back(elems)=&brains;
        qap_add_back(elems)=&ec;
        qap_add_back(elems)=&mc;
        if(plogger)qap_add_back(elems)=plogger;

        if(bool need_sim=true)
        {
          auto&er=qap_add_back(brains.recs);
          er.pId=enemy_pId;
          er.PR.ptr=&curset[i];

          //t_player_score_counter;t_sim_mech_logger;t_brains

          sim_v7_main(env,elems);

          brains.recs.pop_back();
        }

        ms[i]=mc.out;
        es[i]=ec.out;
      }
      QAP_FOREACH(es,ex.enemy_blur());
      qap_sort(es);
      update_vec_score_rank(es);
      QAP_FOREACH(es,ms[ex.id].set_rank(ex.rank,es.size()));
      out=ms;
      if(p_best_eplans)p_best_eplans->resize(es.size());QAP_FOREACH(es,p_best_eplans->at(i)=ex.id);
    }
    t_score sim_v5_full_for_part(t_brains&brains,vector<int>*p_best_eplans)
    {
      if(enemy_pIds.size()!=1)QapDebugMsg("no way. or then need return vector<t_score>");
      t_score out;
      for(int i=0;i<enemy_pIds.size();i++){
        auto&epid=enemy_pIds[i];
        vector<t_score> arr;
        enemy_brain_v3(arr,brains,epid,p_best_eplans);
        QAP_FOREACH(arr,out.add(ex));
      }
      int gg=1;
      return out;
    }
  };
  t_score sim_v5_full_v2(t_movdirs&emovdirs,t_sim_v7_env&env,const t_plan&plan,t_sim_mech_logger*plogger)
  {
    auto enemy_pIds=get_enemy_pIds();
    QapAssert(!enemy_pIds.empty());
    //
    if(bool need_part1=true)
    {
      /*
      t_sim_v7_env&env;
      const t_movdirs&emovdirs;
      const vector<int>&enemy_pIds;
      t_sim_mech_logger*plogger=nullptr;
      */
      t_sim_core core(env,emovdirs,enemy_pIds,plogger);
      t_brains brains;
      auto&er=qap_add_back(brains.recs);
      er.pId=1;
      er.PR.ptr=&plan;
      vector<int> ids;
      auto out=core.sim_v5_full_for_part(brains,&ids);
      if(auto*peb=env.pemd_bests){
        auto&eb=*peb;
        eb.resize(ids.size());
        QAP_FOREACH(eb,ex=core.emovdirs[ids[i]]);
      }
      int gg=1;
      return out.get_average();
    }
    int gg=1;
    return t_score();
  }
  const vector<int>&get_enemy_pIds(){static vector<int> tmp{0};return tmp;}
  #pragma region buildmdirs
  static t_movdirs build_movdirs_for_enemy_v0(int sim_limit)
  {
    vector<t_plan> out;int dirs=3;
    for(int i=0;i<dirs;i++){
      auto dir=i-1;
      qap_add_back(out).add(sim_limit,t_move().set(dir));
    }
    return out;
  }
  static t_movdirs build_movdirs_for_enemy_v1(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=3;
    for(int i=0;i<dirs;i++){
      auto dir=i-1;
      qap_add_back(out).add(sim_limit,t_move().set(dir));
      for(int j=0;j<dirs;j++)if(i!=j){
        auto dir2=j-1;
        qap_add_back(out).add(sim_limit/2,t_move().set(dir)).add(sim_limit,t_move().set(dir2));
      }
    }
    return out;
  }
  static t_movdirs build_movdirs_for_enemy_v2(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=3;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n-1);CODE;}
    auto dt=sim_limit/3;
    DIRLOOP(3,
      DIRLOOP(2,
        DIRLOOP(1,
          qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3);
        )
      )
    );
    /*DIRLOOP(1,
      DIRLOOP(2,
        DIRLOOP(3,
          DIRLOOP(4,
            DIRLOOP(5,
              DIRLOOP(6,
                qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3).add(dt*4,d4).add(dt*5,d5).add(dt*6,d6)
    ))))));*/
    #undef DIRLOOP
    return out;
  }
  static t_movdirs build_movdirs_v3(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=3;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n-1);CODE;}
    auto dt=sim_limit/3;
    DIRLOOP(3,
      DIRLOOP(2,
        DIRLOOP(1,
          qap_add_back(out).add(0,d1).add(4,d2).add(sim_limit,d3);
        )
      )
    );
    #undef DIRLOOP
    return out;
  }
  static t_movdirs build_movdirs_v3d2(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=2;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n?-1:+1);CODE;}
    auto dt=sim_limit/3;
    DIRLOOP(3,
      DIRLOOP(2,
        DIRLOOP(1,
          qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3);
        )
      )
    );
    #undef DIRLOOP
    return out;
  }
  static t_movdirs build_movdirs_v6d2(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=2;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n?-1:+1);CODE;}
    auto dt=sim_limit/6;
    DIRLOOP(6,DIRLOOP(5,DIRLOOP(4,
    DIRLOOP(3,
      DIRLOOP(2,
        DIRLOOP(1,
          qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3).add(dt*4,d4).add(dt*5,d5).add(dt*6,d6)
        )
      )
    ))));
    #undef DIRLOOP
    return out;
  }
  static t_movdirs build_movdirs_v6d2_inv(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=2;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n?-1:+1);CODE;}
    auto dt=sim_limit/6;
    DIRLOOP(1,DIRLOOP(2,DIRLOOP(3,
    DIRLOOP(4,
      DIRLOOP(5,
        DIRLOOP(6,
          qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3).add(dt*4,d4).add(dt*5,d5).add(dt*6,d6)
        )
      )
    ))));
    #undef DIRLOOP
    return out;
  }
  static t_movdirs build_movdirs_v9d2_top(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=2;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n?-1:+1);CODE;}
    auto dt=sim_limit/9;
    DIRLOOP(9,DIRLOOP(8,DIRLOOP(7,DIRLOOP(6,DIRLOOP(5,DIRLOOP(4,
    DIRLOOP(3,
      DIRLOOP(2,
        DIRLOOP(1,
          qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3).add(dt*4,d4).add(dt*5,d5).add(dt*6,d6).add(dt*7,d7).add(dt*8,d8).add(dt*9,d9)
        )
      )
    )))))));
    #undef DIRLOOP
    return out;
  }
  static t_movdirs build_movdirs_v5d2(int sim_limit)
  {
    //return get_movdirs_v0(sim_limit);
    vector<t_plan> out;int dirs=2;
    #define DIRLOOP(n,CODE)for(int iter##n=0;iter##n<dirs;iter##n++){auto d##n=t_move().set(iter##n?-1:+1);CODE;}
    auto dt=sim_limit/5;
    DIRLOOP(5,DIRLOOP(4,
    DIRLOOP(3,
      DIRLOOP(2,
        DIRLOOP(1,
          qap_add_back(out).add(dt*1,d1).add(dt*2,d2).add(dt*3,d3).add(dt*4,d4).add(dt*5,d5);
        )
      )
    )));
    #undef DIRLOOP
    return out;
  }
  #pragma endregion buildmdirs
public:
  bool withoutbrain=false;
  bool pause=false;
  bool lock_step=false;
  struct t_world_parsed{
    t_new_match m;
    t_upd u;
  };
  vector<t_world_parsed> replay;
public:
  #pragma endregion OLD_CORE
public:
  //============================================================
  //===========================NBF==============================
  //============================================================
  static const int number_of_inputs=3;
  static const int number_of_subnodes=number_of_inputs*number_of_inputs;
  struct t_nbf{
    static const int sim_limit=21;
    static const int depth_limit=8;
    static const int node_limit=1000;//64*1000;
    static const size_t resources_per_step=64*8/sim_limit/9;
    static const auto memory_for_nodes=128*1024*1024+16*1024*1024;
    #define max_number_of_nodes (memory_for_nodes/sizeof(t_node))
    typedef size_t t_node_id;
    struct t_world_input{t_move m;t_move e;t_move get_me_move(int pId){return pId?m:e;}};
    struct t_inpid{int id;};
    //struct t_score{};
    struct t_node;
    struct t_growscore{
      t_node*pnode=nullptr;
      template<class t_growscore>
      bool operator<(const t_growscore&ref)const{
        auto&a=*pnode;auto&b=*ref.pnode;
        #define MAJOR(SIGN,field)if(a.field!=b.field)return SIGN (a.field)<SIGN (b.field);
        //MAJOR(     ,psc[1].out);
        MAJOR(     ,smart_score[1]);
        //MAJOR(+1.0*,arr.size());
        #undef MAJOR
        return pnode<ref.pnode;
      }
    };
    struct t_inpfrag{t_score our_score;};
    static t_world_input inpid2frag(t_inpid inpid){t_world_input out;out.m=get_move_for_player(inpid,our_id);out.e=get_move_for_player(inpid,opp_id);return out;}
    //struct t_average_score{
    //  t_score pId2score[2];
    //};
    struct t_node{
      //===
      t_node_id parent=-1;
      int depth=0;
      bool smart_done=false;
      bool deaded=true;
      int smart_intdir[2]={-1,-1};
      t_inpid inpid;
      std::array<t_player_score_counter,2> psc;
      real en_probability[2]={1,1};// en_probability[pId=our_id]=probability_by_enemy_choise[pId=our_id]
      t_growscore growscore;
      t_score smart_score[2];
      t_score megasmart;
      vector<t_node_id> arr;
      t_zmech mech;
      ADLER_DEBUG(vector<t_upd_ws> log;)
      //===
      t_world_input get_inpfrag(){return inpid2frag(inpid);}
      t_move get_move(int pId){return get_inpfrag().get_me_move(pId);};
      int unmount(t_node_id nid){int n=0;QAP_FOREACH(arr,if(ex==nid){n++;ex=-1;});return n;}
      void clear_smart(){
        for(int i=0;i<2;i++){smart_intdir[i]=-1;smart_score[i]=t_score();}
        smart_done=false;
      }
      void clear(){arr.clear();parent=-1;deaded=true;inpid.id=-1;clear_smart();depth=-1;}
      void init(t_node_id parent_nid,int new_depth){*this=t_node();deaded=false;parent=parent_nid;growscore.pnode=this;clear_smart();depth=new_depth;}
    };
    //===
    int nodes_alive=0;
    vector<t_node> nodes;
    vector<t_node_id> unused_nodes;
    vector<t_node_id> cur;
    vector<t_node_id> next;
    t_node_id root_nodeid=-1;
    t_node_id best_nodeid=-1;
    t_mech*g_mech;
    t_score dbg_score;
    vector<string> dbg;
    bool debug=false;
    //===
    bool is_valid(t_node_id nid){return qap_check_id(nodes,nid);}
    static bool check_dir(int dir){return dir>=-1&&dir<=1;}
    static int id2dir(int id){auto dir=id-1;QapAssert(check_dir(dir));return dir;}
    static int dir2id(int dir){QapAssert(check_dir(dir));return dir+1;}
    static t_move get_move_for_player(t_inpid inpid,int pId){
      //for(int m=0;m<number_of_inputs;m++)for(int e=0;e<number_of_inputs;e++){...};
      return t_move().set(id2dir(pId==1?inpid.id/3:inpid.id%3));
    }
    static t_inpid inp2id(t_world_input inp){t_inpid out;out.id=dir2id(inp.m.dir)*3+dir2id(inp.e.dir);return out;}
    void grow_once(t_node_id nid){
      auto&node=nodes[nid];
      QapAssert(node.arr.size()==0);
      node.arr.resize(number_of_subnodes,-1);
      QAP_FOREACH(node.arr,/*if(i/3==1)return;*/ex=new_node(nid);on_node_build(nid,ex,int2inpid(i)););
      update_smart(node,our_id);
      update_smart(node,opp_id);
      if(node.en_probability[1]!=node.en_probability[0]){
        int gg=1;
      }
      int gg=1;
    }
    t_score get_smart_avg_score_by_intdir(t_node&n,int pId,int intdir,bool megasmart){
      QapAssert(n.arr.size()==number_of_subnodes);
      auto mdirid=intdir;//mdirid=intdir=dir2id(dir);
      auto mk=pId==1?number_of_inputs:1;auto mid=pId;
      auto ek=pId==1?1:number_of_inputs;auto eid=pId==1?0:1;
      thread_local vector<t_score> ms;ms.resize(number_of_inputs);
      thread_local vector<t_score> es;es.resize(number_of_inputs);
      for(int e=0;e<number_of_inputs;e++)
      {
        auto&snid=n.arr[mdirid*mk+e*ek];
        if(snid==-1)continue;
        auto&sn=nodes[snid];
        if(megasmart){
          ms[e]=sn.smart_score[mid];
          es[e]=sn.smart_score[eid];
        }else{
          ms[e]=sn.psc[mid].out;
          es[e]=sn.psc[eid].out;
        }
        es[e].id=e;
      }
      QAP_FOREACH(es,ex.enemy_blur());
      qap_sort(es);
      update_vec_score_rank(es);
      t_score out;
      QAP_FOREACH(es,ms[ex.id].set_rank(ex.rank,es.size());out.add(ms[ex.id]););
      for(int i=0;i<number_of_inputs;i++)
      {
        auto&ex=es[i];auto e=ex.id;
        auto snid=n.arr[mdirid*mk+e*ek];
        if(snid==-1)continue;
        auto&sn=nodes[snid];
        sn.en_probability[pId]=ms[ex.id].probability*n.en_probability[pId];
      }
      return out.get_average();
    }
    void grow(t_node_id nid){
      auto&node=nodes[nid];
      QapAssert(node.arr.size()==number_of_subnodes);
      QapAssert(node.smart_intdir[our_id]>=0);
      QapAssert(!node.smart_done);
      //update_m_smart(node);
      auto olddir=node.smart_intdir[our_id];
      auto dirid=olddir;//get_best_dirid_for_player_at(nid,our_id);
      auto n=number_of_inputs;
      for(int e=0;e<n;e++){
        auto snid=node.arr[dirid*n+e];
        grow_once(snid);
      }
      node.smart_done=true;
    }
    void update_smart(t_node&node,int pId){
      QapAssert(node.arr.size()==number_of_subnodes);
      QapAssert(node.smart_intdir[pId]==-1);
      thread_local vector<t_score> buff;buff.resize(number_of_inputs);
      for(int m=0;m<number_of_inputs;m++){
        buff[m]=get_smart_avg_score_by_intdir(node,pId,m,false);
      }
      int win_intdir=QAP_MINVAL_ID_OF_VEC(buff,ex);
      node.smart_score[pId]=buff[win_intdir];
      node.smart_intdir[pId]=win_intdir;
    }
    static t_inpid int2inpid(int i){t_inpid out;out.id=i;return out;}
    void on_node_build(t_node_id pnid,t_node_id nid,t_inpid inpid){
      auto&parent=nodes[pnid];
      auto&node=nodes[nid];
      node.inpid=inpid;

      auto&psc=node.psc;
      if(is_valid(pnid)){
        psc=parent.psc;
      }else{
        QapNoWay();
        QAP_FOREACH(psc,ex=t_player_score_counter();ex.pId=i);
      }
      
      ADLER_DEBUG(node.log.clear(););

      auto&mech=*g_mech;
      mech.load(parent.mech);

      QAP_FOREACH(psc,ex.bef(mech,sim_limit));

      for(int iter=0;iter<sim_limit;iter++)
      {
        apply_directs(mech,inpid);
        mech.tickEvent();
        QAP_FOREACH(psc,ex.iter_next(mech,iter));
        ADLER_DEBUG(if(debug)if(!mech.smb_deaded())qap_add_back(node.log).load_from(mech));
      }

      QAP_FOREACH(psc,ex.aft(mech));

      mech.save(node.mech);
    }
    void apply_directs(t_mech&mech,t_inpid inpid){
      auto m=get_move_for_player(inpid,1);
      auto e=get_move_for_player(inpid,0);
      mech.apply_direct(1,m);
      mech.apply_direct(0,e);
    }
    static t_growscore node2growval(t_node&ex,t_node_id nid){return ex.growscore;};
    void branch_generator_v2(int n)
    {
      auto do_grow=[&](t_node_id nid){
        grow(nid);
      };
      // impl_b
      auto&node=nodes[root_nodeid];
      if(node.arr.empty()){
        grow_once(root_nodeid);
      }
      for(int iter=0;iter<depth_limit;iter++){
        if(nodes_alive*9>node_limit)return;
        if(nodes_alive*sim_limit*9>1024*1024*7*7)return;
        thread_local vector<t_node_id> out; out.clear();
        foreach(root_nodeid,[&](t_node&ex,t_node_id nid){
          if(root_nodeid==nid)return;
          if(!ex.arr.empty())return;
          if(ex.mech.space.userData)return;
          qap_add_back(out)=nid;
        });
        QAP_FOREACH(out,grow_once(ex));
      }
    }
    template<class FUNC>
    void foreach(t_node_id nid,FUNC&&func){
      if(!is_valid(nid))return;
      t_node&node=nodes[nid];
      func(node,nid);
      auto&arr=node.arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        foreach(ex,func);
      }
    }
    template<class NODE2VAL,class FUNC>
    void find_n_with_minval_and_do_func_foreach_of_it(size_t n,NODE2VAL&&node2val,FUNC&&func){
      struct t_rec{
        decltype(node2val(*(t_node*)nullptr,0)) score;
        t_node_id nid;//t_node*pnode; // int node_id;
      };
      vector<t_rec> buff;
      foreach(root_nodeid,[&](t_node&ex,t_node_id nid){
        //if(ex.arr.size()==number_of_subnodes)return;
        if(ex.smart_done)return;
        if(ex.mech.space.stamp>1500)return;
        if(ex.arr.size()!=number_of_subnodes)return;
        auto&b=qap_add_back(buff);b.nid=nid;b.score=node2val(ex,nid);
      });
      if(n==1&&buff.size()){auto id=QAP_MINVAL_ID_OF_VEC(buff,ex.score);func(buff[id].nid);return;}
      QapNoWay();
      /*
      QAp_SORT(buff,ex.score);
      for(int i=0;i<n;i++){func(buff[i].nid);}
      //QAP_FOREACH_N_MINVAL_ID_OF_VEC(buff,n,ex.score,func(*ex.node));
      */
    }
    t_node_id get_subnodeid_by_id(t_node_id nid,t_inpid inpid){return nodes[nid].arr[inpid.id];}
    t_node_id new_node(t_node_id parent){
      auto&A=unused_nodes;
      QapAssert(!A.empty());
      auto id=A.back();
      nodes[id].init(parent,is_valid(parent)?nodes[parent].depth+1:0);
      A.pop_back();
      nodes_alive++;
      return id;
    }
    void del(t_node_id nid){unused_nodes.push_back(nid);nodes[nid].clear();nodes_alive--;}
    void del_recursive(t_node_id nid){
      if(!is_valid(nid))return;
      auto&node=nodes[nid];
      auto&arr=node.arr;
      QAP_FOREACH(arr,del_recursive(ex));
      del(nid);
    }
    size_t count_recursive(t_node_id nid){
      if(!is_valid(nid))return 0;
      auto&node=nodes[nid];
      auto&arr=node.arr;
      size_t out=1;
      QAP_FOREACH(arr,out+=count_recursive(ex));
      return out;
    }
    void unmount(t_node_id nid,t_node_id snid)
    {
      auto&sn=nodes[snid];
      QapAssert(sn.parent==nid);
      auto nun=nodes[nid].unmount(snid);
      QapAssert(nun==1);
      sn.parent=-1;
    }
    real promote_v2(const t_zmech&cur_mech){
      auto&n=nodes[root_nodeid];
      auto id=QAP_MINVAL_ID_OF_VEC(n.arr,ex==-1?1e99:sqrdiff(cur_mech,nodes[ex].mech));
      auto win=n.arr[id];
      real dbg_val=sqrdiff(cur_mech,nodes[win].mech);
      auto mdir=nodes[win].get_move(1).dir;
      auto edir=nodes[win].get_move(0).dir;
      if(dbg_val>0.25){
        //QapDebugMsg("nbf.tree dropped\n" "dbg_val = "+FToS(dbg_val));
        #define QAP_SHOW_FLOATS(MSG,F)MSG("nbf.tree dropped")F(dbg_val)F(nodes_alive)F(id)F(win)F(mdir)F(edir)
        #include "qaplite/qap_show_floats.inl"
        del_recursive(root_nodeid);
        root_reset(cur_mech);
        auto&new_root=nodes[root_nodeid];
        int gg=1;
        return 0;
      }
      if(bool need_debug=false){
        auto bc=count_recursive(win);
        auto rc=count_recursive(root_nodeid);
        int gg=1;
      }
      unmount(root_nodeid,win);
      del_recursive(root_nodeid);
      root_nodeid=win;
      #define QAP_SHOW_FLOATS(MSG,F)MSG("nbf.tree promoted")F(dbg_val)F(nodes_alive)F(id)F(win)F(mdir)F(edir)
      #include "qaplite/qap_show_floats.inl"
      return dbg_val;
    }
    vector<t_node_id> get_branch(t_node_id nid){
      vector<t_node_id> out;
      auto cur=nid;
      for(int i=0;;i++){
        auto&n=nodes[nid];
        qap_add_back(out)=nid;
        if(n.parent==-1)return out;
        nid=n.parent;
      }
      return out;
    }
    t_move get_best_result_v1(int pId){
      QapDebugMsg("this is wrong. use wave based trre building algo. and use best me_inpfrag instead of best node");
      QapAssert(pId==our_id);
      QapAssert(qap_check_id(nodes,best_nodeid));
      auto&bn=nodes[best_nodeid];
      dbg_score=bn.psc[1].out;
      auto branch=get_branch(best_nodeid);
      
      reverse(branch);
      #ifdef Adler
      if(bool need_debug=false){
        vector<int> mdirs;QAP_FOREACH(branch,qap_add_back(mdirs)=nodes[ex].get_move(1).dir);
        vector<int> edirs;QAP_FOREACH(branch,qap_add_back(edirs)=nodes[ex].get_move(0).dir);
        QapPopFront(mdirs);QapPopFront(edirs);
        int gg=1;
      }
      #endif
      if(branch.size()<=1)return t_move().set(0);
      return nodes[branch[1]].get_move(pId);
    }
    // Это и есть алгоритм определения куда растить нод target_nid
    int get_best_dirid_for_player_at(int target_nid,int pId){
      QapAssert(pId==our_id);
      auto&n=nodes[target_nid];
      QapAssert(n.arr.size()==9);
      vector<t_score> scores;scores.resize(number_of_inputs);
      for(int i=0;i<number_of_inputs;i++)scores[i].id=-1;
      //root.get_front_wave().map(e=>score[e.get_root_next_moves().get_me_move().as_intdir()].add(e.megascore[1]));
      foreach(target_nid,[&](t_node&ex,t_node_id nid){
        if(target_nid==nid)return;
        if(ex.arr.empty())return;
        auto dirid=dir2id(ex.get_move(our_id).dir);
        auto&s=scores[dirid];
        s.id=dirid;
        s.add_mul(ex.smart_score[our_id],ex.en_probability[our_id]);
      });
      clean_if(scores,[](t_score&ex){return ex.id==-1;});
      auto id=QAP_MINVAL_ID_OF_VEC(scores,ex.get_average());
      return id<0?0:scores[id].id;
    }
    t_move get_best_inpfrag_for(int pId){
      return t_move().set(id2dir(get_best_dirid_for_player_at(root_nodeid,pId)));
    }
    void init(const t_zmech&cur_mech){
      nodes.resize(max_number_of_nodes);
      unused_nodes.resize(max_number_of_nodes);
      QAP_FOREACH(unused_nodes,ex=(max_number_of_nodes-1)-i);
      root_reset(cur_mech);
    }
    void root_reset(const t_zmech&cur_mech){
      root_nodeid=new_node(-1);
      auto&root=nodes[root_nodeid];
      for(int i=0;i<2;i++)root.psc[i].pId=i;
      root.mech=cur_mech;
      grow_once(root_nodeid);
    }
    t_move get_best_result_v2(int pId){
      QapAssert(pId==our_id);
      return best_move;
    };
    t_move best_move;
    void find_best_result_v2(){
      best_move=get_best_inpfrag_for(our_id);
      return;
      //QapDebugMsg("this is wrong. use root.best_me_inpfrag");
      //vector<t_node_id> out;
      //foreach(root_nodeid,[&](t_node&ex,t_node_id nid){
      //  if(root_nodeid==nid)return;
      //  if(ex.smart_intdir[1]<0)return;// TODO: u never select last-tick action at endgame 
      //  qap_add_back(out)=nid;
      //});
      //auto id=QAP_MINVAL_ID_OF_VEC(out,nodes[ex].smart_score[1]);
      //best_nodeid=out[id];
      //auto&win=nodes[out[id]];
      //int gg=1;
    }
  };
  //=====================NBF===================
  t_nbf nbf;
  //=====================NBF===================
  bool use_dout=true;bool use_dlines=true;void dont_use_dstreams(){use_dout=false;use_dlines=false;}
  void nbf_main_v2()
  {
    t_moves emoves;
    real prev_iter_ms=0;
    real prev_glt_ms=0;
    vector<string> lines;
    string line;
    QapClock iter_clock;
    gframe_id=0;
    #ifdef Adler
    fstream dout,dlines;
    //("dout.json",ostream::out);
    if(use_dout)dout.open("dout.json",std::ios::out|std::ios::trunc);
    if(use_dlines)dlines.open("lines.json",std::ios::out|std::ios::trunc);
    #endif
    ADLER_DEBUG(g_pmech=&g_mech);
    for(int i=0;!pstream->eof();i++)
    {
      iter_clock.Stop();
      prev_iter_ms=iter_clock.MS();
      ADLER_DEBUG(if(frame_id==pause_at_frame)pause=true;lock_step=false;while(pause&!lock_step){Sleep(16);});
      iter_clock.Start();
      QapClock get_line_time;
      line=pstream->getline();
      get_line_time.Stop();
      line=join(split(join(split(line,"\r"),""),"\n"),"");
      if(line.empty())continue;
      ADLER_DEBUG(dlines<<line<<"\n";dlines.flush(););
      qap_add_back(lines)=line;
      t_msg msg;
      bool ok=msg.parse(line);
      if(!ok)continue;
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      if(msg.new_match)
      {
        QAP_MUTEX_GUARD_SCOPE();
        match=msg.match;
        match_id++;
        match_ms=0;
        frame_id=-1;
        total_ms+=iter_clock.MS();
        if(!keep_cur_plan)cur_plan=t_plan();
        cur_mech.reset();
        omwb.reset();
        poor_ticks=poor_ticks_n;
        mcar_in_air=false;
        prev_mcar_in_air=false;
        prev_glt_ms=get_line_time.MS();
        total_GTL+=prev_glt_ms;
        continue;
      };
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
      frame_id++;
      upd=msg.upd;

      if(bool float2str_conv_test=false){
        auto lul=upd.to_json();
        bool tru=join(split(line," "),"").find(lul)!=string::npos;
        QapAssert(tru);
      }

      ADLER_DEBUG(if(withoutbrain||withSleep)Sleep(16));
      real diff_bef=0;real diff_aft=0;
      QapClock clock_fuem;

      {
      QAP_MUTEX_GUARD_SCOPE();
      
      if(!frame_id){
        t_world world;world.conf=&match;world.upd=upd;
        auto reload_mech=[&world](t_mech&m){
          if(m.space){m.free();m=t_mech();}
          m.ignore_log=true;
          m.load_from(world);
          m.need_load=false;
        };
        auto reload=[&](t_mech&dm){
          reload_mech(dm);
          QAP_FOREACH(dm.buff.arr,cpSpaceRemoveShape(dm.space,ex));
        };
        
        ADLER_DEBUG(reload_mech(g_debugmech);reload(g_debugmech_log);debug_upd=upd;);
        reload_mech(g_mech);
        g_mech.save(cur_mech);
        omwb.base=cur_mech.fork();
      }else if(!withoutbrain)
      {
        emoves=find_unk_enemy_moves(g_mech,upd,omwb);
        //QAP_FOREACH(emoves,ex.dir=0);
        g_mech.load(omwb.base);
        sim_steps_v3(g_mech,omwb.arr,emoves);
        diff_bef=g_mech.diff(upd);
        NEED_APPLY_UPD()g_mech.megasync(upd);
        g_mech.make_all_alive();
        diff_aft=g_mech.diff(upd);
        prev_mcar_in_air=mcar_in_air;
        mcar_in_air=g_mech.in_air(g_mech.mcar);
        g_mech.save(cur_mech);
        ADLER_DEBUG(
          g_debugmech.drop();
          auto tmp=cur_mech;
          tmp.space.cachedArbiters.arr.clear();
          g_debugmech.load(tmp);
          debug_upd=upd;
        );
        int gg=1;
      }
      //QAP_MUTEX_GUARD_SCOPE()
      }
      clock_fuem.Stop();
      unique_ptr<t_plan_with_dbg> up_cmd(new t_plan_with_dbg());
      real dbg_val=0;
      if(!withoutbrain)
      {
        QAP_MUTEX_GUARD_SCOPE();
        //========================NBF::on_tick
        if(!frame_id){
          nbf=t_nbf();
          nbf.g_mech=&this->g_mech;
          nbf.init(cur_mech);
        }else{
          if(frame_id%t_nbf::sim_limit==0)
            dbg_val=nbf.promote_v2(cur_mech);
        }
        auto&cmd=*up_cmd.get();
        nbf_update(cmd);
        //========================NBF::on_tick
      }
      auto iter_dt=prev_iter_ms-prev_glt_ms;
      total_GTL+=prev_glt_ms;
      prev_glt_ms=get_line_time.MS();
      total_ms+=iter_dt;
      match_ms+=iter_dt;
      vector<string> timers;
      qap_add_back(timers)="FID:"+std::to_string(frame_id);
      qap_add_back(timers)="TGLT:"+to_string(int(total_GTL));
      qap_add_back(timers)="PREV:"+std::to_string(prev_iter_ms);
      qap_add_back(timers)="TOT:"+std::to_string(total_ms);
      qap_add_back(timers)="M4T:"+std::to_string(int(match_ms));
      //qap_add_back(timers)="WIN:"+std::to_string(cmd.score.id);
      qap_add_back(timers)="EM:"+tostr(emoves);
      //qap_add_back(timers)="GLT:"+to_string(get_line_time.MS());
      qap_add_back(timers)="DB:"+to_string(diff_bef);
      qap_add_back(timers)="DA:"+to_string(diff_aft);
      qap_add_back(timers)="NN:"+to_string(nbf.nodes_alive);
      qap_add_back(timers)="PD:"+to_string(dbg_val);
      nbf.dbg.clear();
      if(0==frame_id){auto tmp=nbf.dbg;nbf.dbg.clear();qap_add_back(nbf.dbg)="/* ###_BUILD_TIME_### */ ";nbf.dbg+=tmp;}
      nbf.dbg+=timers;
      auto dbg_str=join(nbf.dbg,",");
      QAP_MUTEX_GUARD(ADLER_DEBUG(
        auto&out=*up_cmd.get();
        out.dbg=dbg_str;
        out.score=nbf.dbg_score;
        prev_cmd=std::move(up_cmd);
      ));
      if(!withoutbrain)
      {
        auto cur_move=nbf.get_best_result_v2(our_id);
        string s=dump(cur_move,string2json(dbg_str));
        omwb.add(g_mech,cur_move,emoves,upd);
        pstream->send_with_endl(s);
        
        #ifdef Adler
        if(use_dout){
          dout<<s<<endl;dout.flush();
        }
        #endif
      }
      gframe_id++;
    }
    pstream->send_with_endl(server_side.to_str());
    //file_put_contents("lines.json",join(lines,"\n"));
  }
  void nbf_update(t_plan_with_dbg&out){
    nbf.branch_generator_v2(t_nbf::resources_per_step);
    nbf.find_best_result_v2();//nbf.find_best_unsing_this_estimation_function(func);
    #ifdef Adler
      int SL=0;
      if(nbf.debug)nbf.foreach(nbf.root_nodeid,[&](t_nbf::t_node&ex,t_nbf::t_node_id nid){
        //if(!ex.m_smart_done)return;
        out.log+=ex.log;
        SL=std::max<int>(SL,ex.mech.space.stamp);
      });
      out.sim_limit=SL;
      out.base_stamp=cur_mech.space.stamp;
    #endif
    int gg=1;
  }
  void main_v2(){nbf_main_v2();}
  int pause_at_frame=-1024;
};

#ifdef QAP_LITE_H
  #include "ImgLoader.h"
  #include "Dynamic.h"
  #include "aviUtil.h"
  class TGame:public TQapGameV2{
  public:
    real scale=1.5804588547029366;//1.1949681043624878;//1.17;
    vec2d cam_pos=world_wh*0.5;//vec2d(+1,-1)*512;
  public:
    #include "aviSys2.inl"
    #include "qaplite\QapKbOnDownDoInvFlag.inl"
  public:
    bool need_init=true;
    t_app*app=nullptr;
    bool up_app=true;
    bool sync_frame=1;
    real ls=1;
    int future_length=128;
    void init(){
      static bool once=false;if(once)return;once=true;
      cam_pos=world_wh*0.5;
    }
  public:
    static void inv(volatile bool&flag){flag=!flag;}
    vec2d s2w(const vec2d&pos)
    {
      bool offcentric=false; auto cam_dir=vec2d(1,0);
      return t_offcentric_scope::screen_to_world(viewport,pos,cam_pos,cam_dir,scale,offcentric);
    }
    vec2d w2s(const vec2d&pos)
    {
      bool offcentric=false; auto cam_dir=vec2d(1,0);
      return t_offcentric_scope::make_xf(viewport,cam_pos,cam_dir,scale,offcentric)*pos;
    }
    int frame_id=0;int d_frame=1;
    void DoMove()
    {
      if(bool start_avirec=0){avirecsys2.start(this,"foo.avi");}
      QAP_FOREACH(kb_flags,if(kb.OnDown(ex.key))inv(ex.flag));
      if(kb.Down[VK_ESCAPE]){win.Close();app->pause=false;wipe_subprocs();TerminateProcess(GetCurrentProcess(),0);}
      if(kb.Down[VK_ESCAPE]&&kb.Down[VK_SHIFT]){app->pause=false;wipe_subprocs();TerminateProcess(GetCurrentProcess(),0);}
      if(kb.OnDown('T')){inv(app->withSleep);}
      if(kb.Down(VK_ADD))scale*=1.01;
      if(kb.Down(VK_SUBTRACT))scale/=1.01;
      if(kb.Down(VK_DIVIDE)){scale=1.19;cam_pos=world_wh*0.5;}
      if(kb.OnDown(VK_MULTIPLY))scale/=0.5;
      {cam_pos+=kb.get_dir_from_wasd_and_arrows()*(10.0/scale);}
      auto zK=1.5;
      if(zDelta>0){auto wp=s2w(mpos);scale*=zK;cam_pos+=(w2s(wp)-mpos)*(1.0/scale);}
      if(zDelta<0){auto wp=s2w(mpos);scale/=zK;cam_pos+=(w2s(wp)-mpos)*(1.0/scale);}
      //
      if(up_app)
      {
        //auto*app=&up_app.get()->app;
        if(kb.OnDown(VK_SPACE))inv(app->pause);
        {cam_pos+=kb.get_dir_from_wasd_and_arrows()*(10.0/scale);}
        if(kb.OnDown(VK_HOME))frame_id=0;
        if(kb.OnDown(VK_END))frame_id=std::max<int>(0,int(app->replay.size())-1);
        if(kb.OnDown(VK_UP)){d_frame++;d_frame=Clamp<int>(d_frame,-1,+1);}
        if(kb.OnDown(VK_DOWN)){d_frame--;d_frame=Clamp<int>(d_frame,-1,+1);}
        for(int i=0;i<=9;i++)if(kb.OnDown('0'+i))d_frame=Sign(d_frame)*i;
        if(kb.Down(mbRight)){frame_id=app->replay.size()*(mpos.x/viewport.size.x+0.5);}
        if(kb.Down(VK_CONTROL)||kb.Down(VK_SHIFT)){future_length=app->get_sim_limit()*(mpos.x*3/viewport.size.x+0.5);}
        frame_id+=d_frame;
        frame_id=app->replay.empty()?0:Clamp<int>(frame_id,0,int(app->replay.size())-1);
        if(kb.OnDown(VK_RIGHT)){
          if(frame_id<0)frame_id=int(app->replay.size())-1;
          frame_id++;
          if(frame_id>=app->replay.size()){
            frame_id=-1;
            app->lock_step=true;
          }
          //app->pause=true;
        }
        if(kb.OnDown('E')){inv(sync_frame);}
        if(sync_frame)if(!app->pause)app->lock_step=true;
        if(kb.OnDown(VK_LEFT)){
          if(frame_id<0)frame_id=int(app->replay.size())-1;
          frame_id--;
          if(frame_id<0)frame_id=0;
          //app->pause=true;
        }
        static vec2d drag_wp;
        if(kb.OnDown(mbLeft)){drag_wp=s2w(mpos);}
        if(kb.Down(mbLeft)){cam_pos+=-s2w(mpos)+drag_wp;}
      }
      //mechanic
      static auto seed="SEED100_norm 2018.09.04 15:45"; // <-------------------------------------------------------------------------------- SEED
      if(need_init)
      {
        need_init=false;
      }
      if(app->frame_id==4)future_length=app->get_sim_limit();
      int gg=1;
      //static int speed=1;
      //if(up_app)
      //{
      //  if(!app->pause||app->lock_step)
      //  for(int i=0;i<speed;i++)
      //  {
      //    //QapAssert(!mechanic.player_array.empty());
      //    //mechanic.tickEvent_v2();
      //    if(app->lock_step)break;
      //  }
      //  app->lock_step=false;
      //}
      //static int speed=1;
      //for(int i=0;i<=9;i++)if(kb.OnDown('0'+i))speed=i;
      UpdateAVISYS2();
    }
    bool need_restore_mech_from_file=false;

    void clear(){D9Dev.Clear3D(1?0xffc8c8c8:0xff000000);}
    
    #define DECLARE(FIELD)auto&FIELD=qap_check_id(app->replay,frame_id)?app->replay[frame_id].FIELD:get_w_empty().FIELD;
    void DoDraw()
    {
      auto&app=*this->app;
      D9Dev.Set2D();
    
      D9Dev.pDev->SetRenderState(D3DRS_LIGHTING,false);
      D9Dev.pDev->SetRenderState(D3DRS_ZENABLE,false);
      D9Dev.pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
    
      qDev.BindTex(0,nullptr);
      QapDev::BatchScope Scope(qDev);
      {
        t_offcentric_scope scope(qDev,/*obj.pos+*/cam_pos,vec2d(1,0),scale,false);
        render();
      }

      if(kb.Down(VK_CONTROL)||kb.Down(VK_SHIFT)){
        qDev.color=0x11000000;
        qDev.DrawQuad(vec2d(0,0),vec2d(viewport.size.x/3.0,100));
      }

      //
      consize=win.GetClientSize();
      int y=0;int dy=16;
      auto add=[&](const string&text){
        y-=dy;
        auto backup_color=qDev.color;
        qDev.color=0xFF000000;
        qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16+1,y-1),text,16);
        qDev.color=backup_color;
        qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y),text,16);
      };
      qDev.color=0xff004000;
      add("app.map.external_id = "+IToS(app.match.proto_map.external_id));
      add("app.car.external_id = "+IToS(app.match.proto_car.external_id));
      add("app.gframe_id = "+IToS(app.gframe_id));
      add("app.match_id = "+IToS(app.match_id));
      add("app.frame_id = "+IToS(app.frame_id));
      add("future_length = "+IToS(future_length));
      add("g_curset_iter = "+IToS(g_curset_iter));
      add("ms/g_curset_iter = "+FToS(g_curset_clock.MS()/g_curset_iter));
      vector<int> strategy_array={0,1};
      QAP_MUTEX_GUARD(
      QAP_FOREACH(strategy_array,qDev.color=player2color(ex);add("player_lives["+IToS(ex)+"] = "+IToS(i?app.match.my_lives:app.match.enemy_lives)));
      );
      qDev.color=0xff004000;
      add("frame_id = "+IToS(frame_id));
      add("kb.LastKey = "+IToS(kb.LastKey));
      add("mpos = "+dump(s2w(mpos)));
      add("mech_forktime = "+std::to_string(mech_forktime*1e-3)+"ms");
      add("mech_forkn = "+std::to_string(mech_forkn));
      add("cbat_ms = "+std::to_string(cbat_ms)+"ms");
      add("cbat_n = "+std::to_string(cbat_n));
      if(mech_forkn)add("avg_mech_fork = "+std::to_string(mech_forktime*1e-3/mech_forkn)+"ms");
      add("--- up_app ---");
      if(up_app)
      {
        auto f=[&](){
          auto&ass=app.server_side;
          if(ass.arr.size())
          {
            auto&b=ass.arr.back();
            add("dirs = "+IToS(b.dirs));
            add("ms/dir = "+std::to_string(b.ms_per_dir));
            add("ms = "+std::to_string(b.ms_per_dir*b.dirs));
            //add("players = "+std::to_string(b.ppd));
            if(app.prev_cmd){
              app.prev_cmd->score.foreach([&](const string&name,double&value){add(name+"="+FToS(value));});
            }
          }
          if(QapKbOnDownDoInvFlag("need_show_dbg",'G',1))if(app.prev_cmd){
            auto arr=split(app.prev_cmd->dbg,",");
            QAP_FOREACH(arr,add("dbg["+IToS(i)+"] = "+ex));
          }
        };
        QAP_MUTEX_GUARD(f());
      }
      DrawDownedKeys();
    }
    void render()
    {
      auto&app=*this->app;
      QAP_MUTEX_GUARD(if(!app.g_debugmech.space)return;);
      ls=2/scale;
      //QapDev::BatchScope scope(qDev);
      qDev.color=0xff000000;
      qDev.DrawRectAsQuad(world_wh*0.5,world_wh,2);
      qDev.color=0xff000000;
      if(auto tilda=VK_OEM_3)if(kb.OnDown(tilda))
      {
        volatile int gg=1;
      }

      qDev.color=0xff000000;
      {
        QAP_MUTEX_GUARD_SCOPE();
        if(QapKbOnDownDoInvFlag("need_draw_debug_upd",'U',true))draw(app.debug_upd,app.match.proto_map,false);
        auto dd=get_debug_draw();
        if(!app.withoutbrain)if(auto*space=app.g_debugmech.space)
        {
          auto&dm=app.g_debugmech_log;
          if(auto*pcmd=app.prev_cmd.get())
          {
            auto&arr=pcmd->log;
            bool only_selected=kb.Down(VK_SHIFT)==QapKbOnDownDoInvFlag("need_inv_shift",'I',0);
            //int FL=std::max(0,std::min(pcmd->sim_limit-1,future_length));
            if(QapKbOnDownDoInvFlag("need_draw_future",'F',1))
            {
              auto FL_id=QAP_MINVAL_ID_OF_VEC(arr,-ex.stamp);
              auto FL=FL_id<0?0:std::max(0,std::min(arr[FL_id].stamp-pcmd->base_stamp,future_length));
              vector<int> selected;
              for(int i=0;i<arr.size();i++){
                auto&ex=arr[i];
                auto based_stamp=pcmd->base_stamp;
                auto endstamp=FL+based_stamp;
                if(only_selected)if(ex.stamp!=endstamp)continue;
                if(ex.stamp>endstamp)continue;
                selected.push_back(i);
              }
              QAP_FOREACH(selected,draw(arr[ex].upd,app.match.proto_map,true,1.0/selected.size()));
            }
          }
          draw_btn_low_line();
          cpSpaceDebugDraw(space,&dd);
        }
      }
    }
    void draw(t_segment&ex){
      qDev.DrawLine(ex.a,ex.b,ex.h*2);
    }
    void draw(t_proto_map&m){
      qDev.color=0x70202020;
      QAP_FOREACH(m.segments,draw(ex));
    }
    void draw(t_upd&upd,t_proto_map&m,bool fast,real alpha=1){
      if(!fast)draw(m);
      draw(upd.my_car,0,fast,alpha);
      draw(upd.enemy_car,1,fast,alpha);
      //draw_user_input(upd.my_car);
      //draw_user_input(upd.enemy_car);
      if(bool need_draw_deadline=true){
        qDev.color=0x80EE0000;qDev.color.a=255*alpha;
        auto dpy=upd.deadline_position;
        qDev.DrawLine(vec2d(0,dpy),vec2d(t_deadline::MaxL,dpy),t_deadline::DL_R);
      }
      int gg=1;
    }
    int draw_fast=0;
    static QapColor to_qapcolor(const cpSpaceDebugColor&c){return QapColor(c.a,c.r,c.g,c.b);}
    static cpSpaceDebugColor to_chipcolor(const QapColor&c){cpSpaceDebugColor d;d.a=c.a;d.r=c.r;d.g=c.g;d.b=c.b;return d;}
    struct t_chip_debug_draw{
      #define HEADER()auto&g=*(TGame*)data;auto&qDev=g.qDev;
      static void drawCircle(cpVect pos,cpFloat angle,cpFloat radius,cpSpaceDebugColor outlineColor,cpSpaceDebugColor fillColor,cpDataPointer data){
        HEADER();
        qDev.color=to_qapcolor(fillColor);
        qDev.DrawSolidCircle(to_vec2d(pos),radius,16,angle);
        if(g.draw_fast)return;
        qDev.color=to_qapcolor(outlineColor);
        qDev.DrawCircle(to_vec2d(pos),radius,angle,g.ls,16);
        qDev.color=0x80ff0000;
        qDev.DrawLine(to_vec2d(pos),to_vec2d(pos)+Vec2dEx(angle,radius),g.ls*2);
      }
      static void drawSegment(cpVect a,cpVect b,cpSpaceDebugColor color,cpDataPointer data){
        HEADER();
        qDev.color=to_qapcolor(color);
        qDev.DrawLine(to_vec2d(a),to_vec2d(b),g.ls);
      }
      static void drawFatSegment(cpVect a,cpVect b,cpFloat radius,cpSpaceDebugColor outlineColor,cpSpaceDebugColor fillColor,cpDataPointer data){
        HEADER();
        auto A=to_vec2d(a);auto B=to_vec2d(b);
        qDev.color=to_qapcolor(fillColor);
        qDev.DrawLine(to_vec2d(a),to_vec2d(b),radius*2);
        //qDev.color=to_qapcolor(outlineColor);
        //qDev.DrawRectAsQuad((A+B)*0.5,(A-B).GetAng(),g.ls);
      }
      static void drawPolygon(int count,const cpVect*verts,cpFloat radius,cpSpaceDebugColor outlineColor,cpSpaceDebugColor fillColor,cpDataPointer data){
        HEADER();
        vector_view<vec2d> vv;
        static_assert(sizeof(cpVect)==sizeof(vec2d),"hm...");
        vv.p=(vec2d*)verts;
        vv.n=count;
        
        if(g.draw_fast!=1){
          qDev.color=to_qapcolor(fillColor);
          qDev.DrawConvex(vv);
        }
        qDev.color=g.draw_fast?QapColor::HalfMix(to_qapcolor(fillColor),to_qapcolor(outlineColor)):to_qapcolor(outlineColor);
        qDev.DrawPolyLine(vv,g.ls,true);
      }
      static void drawDot(cpFloat size,cpVect pos,cpSpaceDebugColor color,cpDataPointer data){
        HEADER();
        qDev.color=to_qapcolor(color);
        qDev.DrawSolidCircle(to_vec2d(pos),g.ls*2,8,0);
      }
      #define SHAPE_COLOR()QapColor::HalfMix(0xff000000,g.player2color(-1+(int)shape->body->userData));
      static cpSpaceDebugColor colorForShape(cpShape*shape,cpDataPointer data){
        HEADER();
        auto tmp=SHAPE_COLOR();
        tmp.a=0x20;
        return to_chipcolor(tmp);
      }
      static cpSpaceDebugColor colorForShape_fast(cpShape*shape,cpDataPointer data){
        HEADER();
        auto tmp=SHAPE_COLOR();
        tmp.a=0x01;
        return to_chipcolor(tmp);
      }
      static cpSpaceDebugColor colorForShape_fast2(cpShape*shape,cpDataPointer data){
        HEADER();
        auto tmp=SHAPE_COLOR();
        tmp.a=0x0A;
        return to_chipcolor(tmp);
      }
      #undef HEADER
    };
    cpSpaceDebugDrawOptions get_debug_draw(int fast=0){
      cpSpaceDebugDrawOptions out;
      #define F(FUNC)out.FUNC=t_chip_debug_draw::FUNC;
      F(drawCircle);
      F(drawSegment);
      F(drawFatSegment);
      F(drawPolygon);
      F(drawDot);
      F(colorForShape);
      #undef F
      if(fast==1)out.colorForShape=t_chip_debug_draw::colorForShape_fast;
      if(fast==2)out.colorForShape=t_chip_debug_draw::colorForShape_fast2;
      auto slow_flags=(cpSpaceDebugDrawFlags)(CP_SPACE_DEBUG_DRAW_SHAPES|CP_SPACE_DEBUG_DRAW_CONSTRAINTS|CP_SPACE_DEBUG_DRAW_COLLISION_POINTS);
      auto fast_flags=(cpSpaceDebugDrawFlags)(CP_SPACE_DEBUG_DRAW_SHAPES);
      out.flags=fast?fast_flags:slow_flags;
      if(fast==1){
        out.shapeOutlineColor=to_chipcolor(0x04008000);
        out.constraintColor=to_chipcolor(0x04000000);
        out.collisionPointColor=to_chipcolor(0x04FF0000);
      }
      if(fast==2){
        out.shapeOutlineColor=to_chipcolor(0x45008000);
        out.constraintColor=to_chipcolor(0x45000000);
        out.collisionPointColor=to_chipcolor(0x45FF0000);
      }
      if(fast==0)
      {
        out.shapeOutlineColor=to_chipcolor(0x80008000);
        out.constraintColor=to_chipcolor(0x80000000);
        out.collisionPointColor=to_chipcolor(0x80FF0000);
      }
      out.data=this;
      return out;
    }
    void draw_btn(t_proto_car&cd,t_upd::t_car&cu){
      qDev.color=0xee00ff11;
      auto va=x_mul(cd.button_poly,cu.xmod,cu.ang,cu.pos);
      qDev.DrawConvex(va);
      qDev.color=0xeeff0011;
      qDev.DrawPolyLine(va,ls,true);
    }
    void draw_btn_low_line(){
      auto y=app->g_debugmech.get_btn_y_v2(1);
      qDev.color=0xeeff0011;
      qDev.DrawQuad(vec2d(app->g_debugmech.mcar.body->p.x,y),vec2d(100,2)); // TODO: need mutex
    }
    void draw_user_input(t_upd::t_car&car)
    {
      auto&c=app->match.proto_car;
      auto cog=cpCentroidForPoly(c.car_body_poly);vec2d B=vec2d(0,0);auto EO=(cog-B)*0.75;EO.y=0;auto EN=EO.Ort()*0.25;
      auto xm=[&](vec2d p){return x_mul(p,car.xmod,car.ang,car.pos);};
      qDev.DrawSolidCircle(xm(cog),ls*2,8,0);
      qDev.DrawSolidCircle(xm(cog+EO),ls*2,8,0);
      qDev.DrawSolidCircle(xm(cog-EO),ls*2,8,0);
      qDev.DrawSolidCircle(xm(cog+EO+EN),ls*2,8,0);
      qDev.DrawSolidCircle(xm(cog-EO-EN),ls*2,8,0);
      qDev.color=0xFF008800;
      qDev.DrawLine(xm(cog+EO),xm(cog+EO+EN),ls*2);
      qDev.DrawLine(xm(cog-EO),xm(cog-EO-EN),ls*2);
    }
    void draw(t_upd::t_car&car,bool me,bool future=false,real alpha=1)
    {
      auto U8_a=uchar(std::min<int>(std::max<int>(1,255*alpha),255));
      auto&c=app->match.proto_car;
      if(!future)draw_btn(c,car);
      //qDev.color=0x40404040;
      auto pc=player2color(me?1:0);
      qDev.color=QapColor::HalfMix(0x40404040,pc);
      if(future)qDev.color.a=U8_a;
      if(bool need_draw_hull=true)
      {
        auto va=x_mul(c.car_body_poly,car.xmod,car.ang,car.pos);
        if(!future)qDev.DrawConvex(va);
        //if(!future)
        {
          qDev.color=QapColor::HalfMix(0xff000000,pc);
          if(future)qDev.color.a=U8_a;
          qDev.DrawPolyLine(va,ls,true);
        }
      }
      auto f=[&](auto&wu,auto&wd){
        //qDev.color=0x40804020;
        qDev.color=QapColor::HalfMix(0x40804020,pc);
        if(future)qDev.color.a=U8_a;
        if(!future)
        {
          if(c.squared_wheels){
            qDev.DrawQuad(wu.pos,vec2d(1,1)*wd.r*2,wu.ang);
          }else{
            qDev.DrawSolidCircle(wu.pos,wd.r,16,wu.ang);
          }
        }
        if(future)
        {
          if(c.squared_wheels){
            qDev.DrawQuad(wu.pos,vec2d(1,1)*wd.r*2,wu.ang);
          }else{
            qDev.DrawCircle(wu.pos,wd.r,wu.ang,ls,16);
          }
          return;
        }
        qDev.color=0x80ff0000;
        qDev.DrawLine(wu.pos,wu.pos+Vec2dEx(wu.ang,wd.r),ls);
      };
      f(car.front,c.front);
      f(car.rear,c.rear);
    }
    static vec2d cpCentroidForPoly(const vector<vec2d>&arr){return to_vec2d(::cpCentroidForPoly(arr.size(),(cpVect*)&arr[0]));}
    QapColor player2color(int player_id){
      QapColor out=0xff000000;
      auto f=[&](int id,QapColor color){if(id==player_id%4)out=color;};
      f(0,0xABFF0000);
      //f(1,0xABFFAA00);
      //f(2,0xABAAFF00);
      f(1,0xAB0000FF);
      return out;
    }
    template<class TYPE>
    vec2d get_pos(const TYPE&obj){return vec2d(obj.x,obj.y);}
    #undef DECLARE
    static string BToS(bool b){return b?"true":"false";}
  };
  void win_main(t_app&app)
  {
    static GlobalEnv global_env(GetModuleHandle(NULL),0,"",SW_SHOW);
    auto on_heap=std::make_unique<TGame>();
    TGame&builder=*on_heap;
    builder.app=&app;
    builder.init();
    builder.SleepMs=0;
    builder.DoNice();
  }
#endif

#include <queue>
#include <condition_variable>

struct t_blocking_queue{
  std::mutex m;
  std::condition_variable cv;
  std::queue<string> q;
  void push(const string&s){
    {std::lock_guard<std::mutex> g(m);q.push(s);}
    cv.notify_all();
  }
  string pop(){
    std::unique_lock<std::mutex> g;
    auto cond=[&]{return !q.empty();};
    for(;;){
      std::unique_lock<std::mutex> lk(m);
      cv.wait(lk,cond);
      if(cond()){g=std::move(lk);break;}
    }
    string s=q.front();
    q.pop();
    return s;
  }
};

struct t_wait_style_io:i_two_stream{
  t_blocking_queue inp,out;
  string getline(){return inp.pop();}
  bool eof(){return false;}
  void send_with_endl(const string&s){out.push(s);}
};

struct t_world_json{
  string match,upd;
/*
#define DEF_PRO_CLASSNAME()t_world_json
#define DEF_PRO_VARIABLE(ADD)\
ADD(string,match,$)\
ADD(string,updm,$)\
ADD(string,upde,$)\
//===
#include "defprovar.inl"
//===
*/
};

struct t_allworlds{
  vector<string> matchs;
  vector<string> upds;
  void load(const string&fn){
    auto arr=split(file_get_contents(fn),"\n");
    if(arr.empty())QapDebugMsg("t_allworlds::load::fn="+fn+"\n  but file is empty");
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.find("new_match")==string::npos){
        QapAssert(ex.find("tick")!=string::npos);
        qap_add_back(upds)=ex;
        continue;
      }
      qap_add_back(matchs)=ex;
    }
  }
  t_world_json get(int id){
    t_world_json wj;wj.match=matchs[id];
    QapAssert(upds.size()==2);
    auto bus=id/6==1;
    wj.upd=upds[bus?0:1];
    return wj;
  }
};

t_move get_move(const string&cmd){
  auto doc=unsafe_get_doc(cmd);
  return t_app::str2tmove(doc["command"].GetString());
}

string swap_cars(const string&upd_json,int pId=0){
  auto s=upd_json;
  if(!pId){
    s=join(split(s,"enemy_car"),"tmp_car");
    s=join(split(s,"my_car"),"enemy_car");
    s=join(split(s,"tmp_car"),"my_car");
  }
  return s;
}
string upd2str(const t_upd&upd,int pId){
  auto s=upd.to_json();
  s=swap_cars(s,pId);
  return jobj(jk("type","\"tick\"")+","+jk("params",s));
}

#pragma endregion before_plan_generator

#include "t_plan_generator_old.inl"

struct t_plan_generator{
  typedef t_plan_generator SelfClass;
  std::random_device rd;
  std::mt19937 rand;
  string seed;
  //
  size_t call_id=-1;
  vector<size_t> used;
  vector<size_t> tick2id;
  vector<t_plan_rec> recs;
  //
  t_plan_generator():rand(rd()){init_with();}
  void init_with(const string&new_seed="SEED 2018.10.15 14:48"){
    seed=new_seed;
    std::seed_seq seq(seed.begin(),seed.end());rand.seed(seq);
    used.clear();tick2id.clear();recs.clear();call_id=-1;
  }
  void write_n_kink_at_every_dt(t_plan&out,int&t,int dt,int n){
    for(int i=0;i<n;i++){
      out.add(t,t_move().set(rand()%3-1));t+=dt;
    }
  }
  void spawn_n_rnd_new(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000){
    static const int to_small_n=116;
    static const int to_xxxxx_n=6;
    static const int SIM_LIMIT=2200; //fast_rand(12,0xfff)%SIM_LIMIT
    QapAssert(out.arr.empty()&&ADD_RND_N);
    int n=BASE_N+rand()%ADD_RND_N;
    unsigned fast_buff=0;int fast_n=0;
    auto fast_rand=[&](int bits,unsigned bitmask){
      if(fast_n<bits){fast_n=32;fast_buff=rand();}
      fast_n-=bits;
      auto v=fast_buff&bitmask;
      fast_buff>>=bits;
      return v;
    };
    if(used.size()!=SIM_LIMIT){used.resize(SIM_LIMIT,call_id);tick2id.resize(SIM_LIMIT);}
    call_id++;
    bool to_small=n<to_small_n;
    bool use_update=to_small&&n>to_xxxxx_n;
    //auto&recs=to_small&&n>to_xxxxx_n?out.arr:this->recs;
    recs.clear();
    for(int i=0;i<n;i++){
      auto tick=t+fast_rand(12,0xfff)%SIM_LIMIT;
      if(used[tick]==call_id)continue;
      used[tick]=call_id;
      if(!use_update)tick2id[tick]=recs.size();
      auto&b=qap_add_back(recs);
      b.tick=tick;
      b.move=t_move().set(fast_rand(2,0x3)%3-1);
    }
    if(!use_update)
    {
      out.arr.reserve(recs.size());
      for(int i=0;i<used.size();i++){
        if(used[i]!=call_id)continue;
        auto&cur=recs[tick2id[i]];
        if(bool need_auto_pack=true&&out.arr.size()){
          if(out.arr.back().move==cur.move)continue;
        }
        qap_add_back(out.arr)=std::move(cur);
      }
    }else{
      out.arr.resize(recs.size());
      QAP_FOREACH(out.arr,ex=std::move(recs[i]));
      out.update();
    }
    t=out.arr.back().tick+1;
  }
  void spawn_n_rnd_old(t_plan&out,int&t,int BASE_N=4,int ADD_RND_N=1000,int SIM_LIMIT=2200){
    QapAssert(out.arr.empty()&&ADD_RND_N);
    int n=BASE_N+rand()%ADD_RND_N;
    for(int i=0;i<n;i++)out.tick2rec(t+rand()%SIM_LIMIT)->move=t_move().set(rand()%3-1);
    out.update();
    t=out.arr.back().tick+1;
  }
  t_plan rnd_plan(){
    t_plan out;
    int t=0;
    spawn_n_rnd_new(out,t,8,64);
    return out;
  }
  void skip_plan(){
    int t=0;
    skip_spawn_n_rnd_new(t,8,64);
  }
  void skip_spawn_n_rnd_new(int&t,int BASE_N=8,int ADD_RND_N=64){
    static const int SIM_LIMIT=2200; //fast_rand(12,0xfff)%SIM_LIMIT
    int n=BASE_N+rand()%ADD_RND_N;
    unsigned fast_buff=0;int fast_n=0;
    auto fast_rand=[&](int bits,unsigned bitmask){
      if(fast_n<bits){fast_n=32;fast_buff=rand();}
      fast_n-=bits;
      auto v=fast_buff&bitmask;
      fast_buff>>=bits;
      return v;
    };
    if(used.size()!=SIM_LIMIT){used.resize(SIM_LIMIT,call_id);tick2id.resize(SIM_LIMIT);}
    call_id++;
    for(int i=0;i<n;i++){
      auto tick=t+fast_rand(12,0xfff)%SIM_LIMIT;
      if(used[tick]==call_id)continue;
      used[tick]=call_id;
      fast_rand(2,0x3);
    }
  }
};

struct t_looped_runner{
  t_allworlds aw;
  t_looped_runner(){}
  void init(){
    string path="";
    ADLER_DEBUG(path="../Demo/");
    aw.load(path+"allworlds.json");
  }
  void set_mech(t_mech&mech,t_new_match&match,int id){
    auto world=aw.get(id);
    t_world w;
    w.conf=&match;
    {t_app::t_msg msg;bool ok=msg.parse(world.match);QapAssert(ok&&msg.new_match);match=msg.match;}
    {t_app::t_msg msg;bool ok=msg.parse(world.upd);QapAssert(ok&&!msg.new_match);w.upd=msg.upd;}
    auto reload_mech=[&w](t_mech&m){
      if(m.space){m.free();m=t_mech();}
      m.ignore_log=true;
      m.load_from(w);
      m.need_load=false;
    };
    reload_mech(mech);
  }
  struct t_plan_with_side{
    int pId=0;
    int plan_id=-1;
    string seed;
    string info;
    t_plan plan;
    string to_code(bool without_info=false)const{
      vector<string> out;
      #define F(FIELD)qap_add_back(out)=std::to_string(FIELD);
      F(plan_id);
      qap_add_back(out)=jq(seed);
      F(pId);
      qap_add_back(out)=jq(without_info?"":info);
      #undef F
      auto s=join(out,",");
      if(without_info)s=join(split(s,"\""),"\\\"");
      return seed=="empty"&&plan_id==-1?seed:"get_by_id("+s+");";
    }
  };
  struct i_sim_elem_v2{ 
    #define F(FUNC)FUNC(t_mech&mech,int iter)
    virtual void F(bef){}
    virtual void F(aft){}
    virtual void F(apply_direct){}
    virtual void F(iter_next){}
    virtual bool F(need_break){return false;};
    #undef F
  };
  struct t_result_c{
    std::atomic<size_t> iter;
    std::atomic<int> equals;
    std::atomic<int> fails;
    std::atomic<int> samples;
    t_result_c(){
      iter=0;
      equals=0;
      fails=0;
      samples=0;
    }
    void write_to(vector<string>&out)const{
      auto avg_iter=FToS(this->avg_iter());
      qap_add_back(out)="avg_iter:"+avg_iter;
      #define F(FIELD)qap_add_back(out)=string(#FIELD)+":"+std::to_string(FIELD);
      //F(avg_iter);
      F(equals);
      F(fails);
      F(samples);
      #undef F
    }
    real get_score()const{return -get_force()*1024*16+avg_iter();}
    bool operator<(const t_result_c&ref)const{
      #define MAJOR(SIGN,field)if(field!=ref.field)return SIGN field<SIGN ref.field;
      MAJOR(+,get_score());
      #undef MAJOR
      return this>&ref;
    }
    //int number_of_deads()const{return fails+equals;}
    real number_of_deads_v2()const{return fails+equals*0.5;}
    real get_winrate()const{return samples?100.0*(1.0-real(fails+equals)/samples):0;}
    real get_force()const{return samples?100.0*(1.0-real(fails+equals*0.5)/samples):0;}
    void add(const t_result_c&ref){
      #define F(FIELD)this->FIELD+=ref.FIELD;
      F(iter);
      F(equals);
      F(fails);
      F(samples);
      #undef F
    }
    void clear(){*this=t_result_c();}
    t_result_c(const t_result_c&ref){typedef std::array<char,sizeof(*this)> U;*(U*)this=*(U*)(void*)&ref;}
    t_result_c&operator=(const t_result_c&ref){typedef std::array<char,sizeof(*this)> U;*(U*)this=*(U*)(void*)&ref;return *this;}
    real avg_iter()const{return samples?iter*1.0/samples:0;}
  };
  struct t_result_b{
    size_t dflag=0;
    size_t world_id=4+6*0;
    real ms=0;
    real a_ms=0;
    real b_ms=0;
    void write_to(vector<string>&out)const{
      #define F(FIELD)qap_add_back(out)=string(#FIELD)+":"+std::to_string(FIELD);
      F(world_id);
      F(dflag);
      F(ms);
      F(a_ms);
      F(b_ms);
      #undef F
    }
  };
  struct t_ps_counter_v2:i_sim_elem_v2{
    t_plan_with_side pws;
    t_result_c res;
    t_result_c old;
    void aft(t_mech&mech,int iter){
      auto MD=mech.me_deaded(pws.pId);
      auto ED=mech.en_deaded(pws.pId);
      bool BD=MD&&ED;

      if(BD)res.equals++;
      if(MD&&!ED)res.fails++;
      res.samples++;
      res.iter+=iter;
    }
  };
  struct t_break:i_sim_elem_v2{
    bool need_break(t_mech&mech,int iter){return mech.smb_deaded();}
  };
  struct t_player:t_ps_counter_v2{
    string to_str(){
      vector<string> out;
      out.push_back("plan_id:"+IToS(pws.plan_id));
      out.push_back("force:"+FToS(res.get_force()));
      res.write_to(out);
      return join(out,"   ,");
    };
  };
  struct t_player_memory{
    int pId=-1;
    t_plan_runner PR;
    void bef(t_plan&plan,t_mech&mech){
      QapAssert(pId>=0);
      PR.ptr=&plan;
      PR.restart();
    }
    t_move get_direct(t_mech&mech){
      return PR.next();//get(plan,iter,mech);
    }
    void aft(t_mech&mech){
    }
  };
  struct t_brains:i_sim_elem_v2{
    t_player*pa=nullptr;
    t_player*pb=nullptr;
    //t_player buff;
    t_break br;
    t_result_b res;
    t_player_memory ma,mb;
    vector<i_sim_elem_v2*> elems;
    QapClock clock;
    void init_elems(){
      qap_add_back(elems)=&br;
      qap_add_back(elems)=this;
      qap_add_back(elems)=pa;
      qap_add_back(elems)=pb;
    }
    #define CLOCK_SCOPE(PLAYER,CODE)clock.Start();CODE;res.PLAYER##_ms+=clock.MS();
    void apply_direct(t_mech&mech,int iter)
    {
      CLOCK_SCOPE(a,auto ida=ma.get_direct(mech));
      CLOCK_SCOPE(b,auto idb=mb.get_direct(mech));

      mech.apply_direct(pa->pws.pId,ida,false);
      mech.apply_direct(pb->pws.pId,idb,false);
    }
    void bef(t_mech&mech,int iter){
      ma.pId=pa->pws.pId;
      mb.pId=pb->pws.pId;
      CLOCK_SCOPE(a,ma.bef(pa->pws.plan,mech));
      CLOCK_SCOPE(b,mb.bef(pb->pws.plan,mech));
    }
    void aft(t_mech&mech,int iter){
      res.dflag=size_t(mech.space->userData);
      CLOCK_SCOPE(a,ma.aft(mech));
      CLOCK_SCOPE(b,mb.aft(mech));
    }
    #undef CLOCK_SCOPE
    void put_players(t_player&a,t_player&b){
      pa=&a;
      pb=&b;
      QapAssert(pa->pws.pId!=pb->pws.pId);
      QapAssert(pa->pws.pId<=1&&pa->pws.pId>=0);
      QapAssert(pb->pws.pId<=1&&pb->pws.pId>=0);
    }
    string to_str(){
      vector<string> out;
      out.push_back("plan_id:"+IToS(pb->pws.plan_id));
      out.push_back("force:"+FToS(pb->res.get_force()));
      pb->res.write_to(out);
      res.write_to(out);
      return join(out,"   ,");
    };
  };
  static void sim_v10_core(t_mech&mech,vector<i_sim_elem_v2*>&elems)
  {
    int iter=-1;
    QAP_FOREACH(elems,ex->bef(mech,iter));
    for(bool need_break=false;;)
    {
      QAP_FOREACH(elems,need_break=need_break||ex->need_break(mech,iter));
      if(need_break)break;
      iter++;
      QAP_FOREACH(elems,ex->apply_direct(mech,iter));
      mech.tickEvent();
      QAP_FOREACH(elems,ex->iter_next(mech,iter));
    }
    QAP_FOREACH(elems,ex->aft(mech,iter));
  }
  struct t_result:t_brains{};
  void sim(t_result&out)
  {
    t_new_match match;
    t_mech mech;
    set_mech(mech,match,out.res.world_id);
    out.init_elems();
    sim_v10_core(mech,out.elems);
    mech.free();
  }
  void run_vs(int world_id,const string&host_name,t_player&host,vector<t_player>&earr,bool need_clean,bool mute=true){
    if(!mute)cout<<host_name<<" = "<<host.pws.to_code()<<"\n=====vvvvv"<<endl;
    host_vs_earr(world_id,host,earr,true);
    if(need_clean)clean_if(earr,[](t_player&ex)->int{return ex.res.number_of_deads_v2()>0;});
    if(!need_clean)QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
  };
  template<class t_plan_generator>
  static vector<t_plan_with_side>&ug_impl_main(vector<t_plan_with_side>&ids){
    std::map<string,vector<t_plan_with_side*>> seed2arr;
    QAP_FOREACH(ids,seed2arr[ex.seed].push_back(&ex));
    for(auto it:seed2arr){
      t_plan_generator PG;PG.init_with(it.first);
      ug_impl(PG,it.second);
    }
    return ids;
  }
  template<class t_plan_generator>
  static void ug_impl(t_plan_generator&pg,vector<t_plan_with_side*>&ids){
    auto best_id=QAP_MINVAL_ID_OF_VEC(ids,-ex->plan_id);
    int N=1+ids[best_id]->plan_id;
    //vector<t_player> arr;
    vector<t_plan_with_side*> id2pnv;
    id2pnv.resize(N);
    {
      QAP_FOREACH(ids,auto&dest=id2pnv[ex->plan_id];if(!dest)dest=ex;);
    }
    QAP_FOREACH(id2pnv,
      if(ex&&ex->plan_id>=0){
        ex->plan=pg.rnd_plan();
      }else{pg.skip_plan();}
    );
  }
  static vector<t_plan_with_side> get_all_winners_fast(const string&version="*"){
    vector<vector<t_plan_with_side>> ids;ids.resize(10);
    auto f=[&](int id,const string&seed,int pId,const string&info){
      if(id<0)return;
      if(t_plan_generator_old::is_old_seed(seed)){
        auto&b=qap_add_back(ids[0]);
        b.plan_id=id;
        b.seed=seed;
        b.pId=pId;
        b.info=info;
        return;
      }
      if(t_plan_generator_v3::is_your_seed(seed)){
        auto&b=qap_add_back(ids[1]);
        b.plan_id=id;
        b.seed=seed;
        b.pId=pId;
        b.info=info;
        return;
      }
      auto&b=qap_add_back(ids[2]);
      b.plan_id=id;
      b.seed=seed;
      b.pId=pId;
      b.info=info;
      return;
    };
    bool any=version=="*";
    #define get_by_id(plan_id,seed,pId,info)f(plan_id,seed,pId,info);
    #include "versions.inl"
    #undef get_by_id
    vector<t_plan_with_side> out;
    {out+=ug_impl_main<t_plan_generator_old>(ids[0]);}
    {out+=ug_impl_main<t_plan_generator_v3>(ids[1]);}
    {out+=ug_impl_main<t_plan_generator>(ids[2]);}
    return out;
  }
  typedef t_looped_runner OwnerClass;
  struct t_two_top{
    vector<t_player> earr,marr;
    void spawn(t_plan_generator&PG,size_t N=100){
      gen_players(PG,marr,N,1);
      gen_players(PG,earr,N,0);
    }
    void add_mega(){      
      QAP_FOREACH(get_all_winners_fast("mega1"),auto&b=qap_add_back(marr);b=pws2player(ex);b.pws.pId=1;);
      QAP_FOREACH(get_all_winners_fast("mega0"),auto&b=qap_add_back(earr);b=pws2player(ex);b.pws.pId=0;);
    }
    void add_each_from_versions(){
      auto all_winners=get_all_winners_fast("*");
      vector<string> sarr;
      QAP_FOREACH(all_winners,auto u=ex.to_code(true);qap_add_back(sarr)=qap_includes(sarr,u)?"fail":u;);
      clean_if_v2(all_winners,[&](const t_plan_with_side&ex,int id)->int{return sarr[id]=="fail";});
      sarr.clear();
      QAP_FOREACH(all_winners,auto u=ex.to_code();qap_add_back(sarr)=qap_includes(sarr,u)?"fail":u;);
      cout<<join(sarr,"\n")<<endl;
      
      QAP_FOREACH(all_winners,auto&b=qap_add_back(marr);b=pws2player(ex);b.pws.pId=1;);
      QAP_FOREACH(all_winners,auto&b=qap_add_back(earr);b=pws2player(ex);b.pws.pId=0;);
    }
    void resize(int N){
      marr.resize(N);
      earr.resize(N);
    }
    void clear_stats(){
      QAP_FOREACH(marr,ex.res.clear());
      QAP_FOREACH(earr,ex.res.clear());
    }
    void full_run(OwnerClass&owner,int world_id){
      QAP_FOREACH(marr,{
        owner.run_vs(world_id,"marr["+IToS(i)+"]",ex,earr,false);
      });
      QAP_SORT_BY_FIELD(marr,res.get_score(),t_player);
    }
    void run_vs_top(OwnerClass&owner,int world_id,t_two_top&top){
      say("top.marr");
      for(int i=0;i<top.marr.size();i++){
        auto&host=top.marr[i];
        owner.run_vs(world_id,"top.marr["+IToS(i)+"]",host,earr,true);
        if(earr.empty())break;
      }
      say("top.earr");
      for(int i=0;i<top.earr.size();i++){
        auto&host=top.earr[i];
        owner.run_vs(world_id,"top.earr["+IToS(i)+"]",host,marr,true);
        if(marr.empty())break;
      }
    }
    void draw(vector<t_player>&arr){
      vector<string> out;
      QAP_FOREACH(arr,ex.pws.info=ex.to_str());
      QAP_FOREACH(arr,qap_add_back(out)=ex.pws.to_code());
      cout<<join(out,"\n")<<endl;
    }
    void sort(){
      QAP_SORT_BY_FIELD(marr,res.get_score(),t_player);
      QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
    }
    void draw(){
      say("marr");
      draw(marr);
      say("earr");
      draw(earr);
    }
    static void say(const string&msg){cout<<"===["<<msg<<"]==="<<endl;}
    static void main(OwnerClass&owner,int world_id,t_plan_generator&PG){
      t_two_top megatop;
      #define SAY(CODE)say(#CODE);CODE;
      //SAY(megatop.add_mega());
      //SAY(megatop.add_each_from_versions(););
      //SAY(megatop.full_run(owner,world_id););
      //SAY(megatop.draw();                  );
      //SAY(megatop.resize(32);              );
      //SAY(megatop.clear_stats();           );
      //
      t_two_top top;
      SAY(top.spawn(PG,64);           );
      SAY(top.marr+=megatop.marr;      );
      SAY(top.earr+=megatop.earr;      );
      SAY(top.full_run(owner,world_id););
      SAY(top.draw();                  );
      //SAY(top.resize(10);              );
      SAY(top.draw();                  );
      say("begin");
      t_two_top super;
      for(int i=0;i<5;i++){
        t_two_top noobs;
        SAY(noobs.spawn(PG,40112););
        say("noobs.run_vs_top(owner,world_id,top); // i="+IToS(i));
        noobs.run_vs_top(owner,world_id,top);
        say("noobs.draw();");
        noobs.draw();
        super.marr+=noobs.marr;
        super.earr+=noobs.earr;
      }
      say("end");
      SAY(super.draw();                  );
      SAY(super.full_run(owner,world_id););
      SAY(super.draw();                  );
      say("done");
      #undef SAY
    }
    void cross_run(OwnerClass&owner,int world_id,t_two_top&other){
      QAP_FOREACH(earr,owner.run_vs(world_id,"unused",ex,other.marr,false));
      QAP_FOREACH(marr,owner.run_vs(world_id,"unused",ex,other.earr,false));
    }
    static void merge(OwnerClass&owner,const t_two_top&all,int world_id,t_plan_generator&PG,vector<t_plan_with_side>&out){
      t_two_top megatop=all;
      #define SAY(CODE)say(#CODE);CODE;
      //SAY(megatop.add_each_from_versions(););
      //SAY(megatop.draw();                  );
      t_two_top top;
      SAY(top.spawn(PG,128);           );
      SAY(top.full_run(owner,world_id););
      SAY(top.draw();                  );
      SAY(top.clear_stats();           );

      SAY(megatop.cross_run(owner,world_id,top););
      SAY(megatop.sort(););
      SAY(megatop.resize(10);megatop.draw(););
      SAY(megatop.clear_stats();           );
      //SAY(megatop.run_vs_top(owner,world_id,top););
      //SAY(megatop.draw();              );


      t_two_top rnd;
      SAY(rnd.spawn(PG,10000);            );
      SAY(megatop.cross_run(owner,world_id,rnd););
      SAY(megatop.sort(););

      SAY(megatop.draw(); );
      SAY(megatop.resize(1);megatop.draw(););
      if(megatop.marr.size())qap_add_back(out)=megatop.marr[0].pws;
      if(megatop.earr.size())qap_add_back(out)=megatop.earr[0].pws;
      //SAY(megatop.full_run(owner,world_id););
      //SAY(megatop.draw();              );
      #undef SAY
    }
  };
  template<class T_PG>
  static t_plan_with_side get_by_id_impl(int plan_id,const string&seed,int pId,const string&info,bool allow_skip){
    T_PG pg;pg.init_with(seed);
    if(allow_skip){
      for(int i=0;i<plan_id;i++)pg.skip_plan();
    }else{
      for(int i=0;i<plan_id;i++)pg.rnd_plan();
    }
    t_plan_with_side out;
    out.pId=pId;
    out.plan_id=plan_id;
    out.seed=seed;
    out.info=info;
    if(plan_id>=0)out.plan=pg.rnd_plan();
    return out;
  }
  static t_plan_with_side get_by_id(int plan_id,const string&seed,int pId,const string&info,bool allow_skip=true){
    if(t_plan_generator_old::is_old_seed(seed)){
      return get_by_id_impl<t_plan_generator_old>(plan_id,seed,pId,info,allow_skip);
    }
    if(t_plan_generator_v3::is_your_seed(seed)){
      return get_by_id_impl<t_plan_generator_v3>(plan_id,seed,pId,info,allow_skip);
    }
    return get_by_id_impl<t_plan_generator>(plan_id,seed,pId,info,allow_skip);
  }
  template<class t_plan_generator>
  static void gen_players(t_plan_generator&PG,vector<t_player>&out,size_t N,int pId){
    out.resize(N);
    QAP_FOREACH(out,auto&q=ex.pws;q.plan=PG.rnd_plan();q.plan_id=PG.call_id;q.seed=PG.seed;q.pId=pId;);
  }
  static t_player pws2player(const t_plan_with_side&pws){t_player q;q.pws=pws;return q;}
  void host_vs_earr(int world_id,t_player&host,vector<t_player>&earr,bool mute=false)
  {
    auto&hres=host.res;
    //#pragma omp critical
    int old_fails=hres.fails;
    auto s=", old_force = "+FToS(hres.get_force())+", prev_score = "+FToS(hres.get_score())+(!mute?"\n=====\n":"");
    auto f=[&](int id){
      auto&ex=earr[id];
      t_result out;
      out.res.world_id=world_id;
      out.put_players(host,ex);
      sim(out);
      if(earr.size()<90*1000)if(!mute&&!out.pb->res.number_of_deads_v2()){
        #pragma omp critical
        cout<<out.to_str()<<endl;
      }
    };
    //if(earr.size()==1||!mute){
    //  for(size_t i=0;i<earr.size();i++)f(i);
    //}else{
      #pragma omp parallel for schedule(dynamic,1)
      for(int i=0;i<earr.size();i++)f(i);
    //}
    //#pragma omp critical
    cout<<(!mute?"=====^^^^^\n":"")<<host.to_str()<<", dfails += "<<(hres.fails-old_fails)<<s<<endl;
  }
  struct t_WI{int map,car,side;string tostr()const{return "["+IToS(map)+","+IToS(car)+","+IToS(side)+"]";}};
  static t_plan_with_side get_winner_for(int map_id,int car_id,int side,const string&version){
    bool any=false;
    //static vector<t_plan_with_side> winners;
    const int win_id=map_id*2*3+car_id*2+side;
    //auto get_by_id=[](int plan_id,const string&seed,int pId,const string&info){qap_add_back(winners)=t_looped_runner::get_by_id(plan_id,seed,pId,info);};
    int g_id=0;
    #define get_by_id(plan_id,seed,pId,info)if(win_id==g_id++)return t_looped_runner::get_by_id(plan_id,seed,pId,info);
    #include "versions.inl"
    #undef get_by_id
    return t_looped_runner::get_by_id(-1,"empty",side,"");
  }
  static vector<t_plan_with_side> get_all_winners(const string&version){
    bool any=version=="*";
    vector<t_plan_with_side> out;
    #define get_by_id(plan_id,seed,pId,info)qap_add_back(out)=t_looped_runner::get_by_id(plan_id,seed,pId,info);
    #include "versions.inl"
    #undef get_by_id
    return out;
  }
  static void brain2k(i_two_stream&stream){
    t_app::t_msg msg;
    int frame_id=0;
    t_plan_with_side our;
    t_plan_runner PR;
    PR.ptr=&our.plan;
    for(int g_frame_id=0;;g_frame_id++){
      bool ok=msg.parse(stream.getline());
      QapAssert(ok);
      if(msg.new_match){
        frame_id=0;continue;
      }
      if(!frame_id){
        int map_id=msg.match.proto_map.external_id-1;
        int car_id=msg.match.proto_car.external_id-1;
        int side=msg.upd.my_car.xmod>0?1:0;
        //if(side==1)QapDebugMsg("i can't create game with side==1 at aicups.ru");
        our=get_winner_for(map_id,car_id,side,"merge2");
        PR.restart();
        //cerr<<"our=get_winner_for(map_id,car_id,side,'merge2'); our.plan.arr.size()=="<<our.plan.arr.size()<<endl;
      }
      stream.send_with_endl(t_app::dump(PR.next(),!frame_id?jq("build at ###_BUILD_TIME_###"):string("")));
      frame_id++;
    }
  }
  void improve(){
    auto make_pws=[](...){};
    //make_pws(63618,"SEED",1,WI,samples,force,avg_iter);
  }
  void new_brute_cycle(){
    /*
    result
      t_bots side2bests[2];

    side2bests[0].add_empty();
    side2bests[1].add_empty();

    for...
      for side
        put_bot_to(side,new_bot=gen_bot())
          bests=side2bests[side]
          bests.add(new_bot)
          get_top_enemy_for(bests.top1).mapfilter
            e is t_bot
            make_world(e,new_bot).sim()
            if(new_bot.number_of_deads()+n>bests.top1.number_of_deads())break;
            return 
    */
  }
  string seed="nope";
  void ML_v4(int N,size_t const_base_n=31){
    cout<<"ML_v4"<<endl;
    cout<<"build at ###_BUILD_TIME_###"<<endl;
    fstream wins_log;
    wins_log.open("wins"+IToS(N)+".log.cpp",std::ios::out|std::ios::trunc);
    vector<string> wins;int gid=-1;
    for(int map_id=0;map_id<6;map_id++)
      for(int car_id=0;car_id<3;car_id++)
        for(int side=0;side<2;side++)
    {
      gid++;
      if(bool need_skip_n_first=false)if(gid<35)continue;
      //if(side==1){qap_add_back(wins)="get_by_id(-1,\"empty\",0,\"nope\");";continue;}
      string WI="["+IToS(map_id)+","+IToS(car_id)+","+IToS(side)+"]";
      qap_add_back(wins)=ML_impl_v4({map_id,car_id,side},N,const_base_n).to_code();
      wins_log<<wins.back()<<endl;
      cout<<("=====["+WI+"]=====")<<endl;
    }
    file_put_contents("wins"+IToS(N)+".cpp",join(wins,"\n"));
  }
  void log_info_about_winners(){
    auto arr=get_all_winners("merge");
    vector<string> out;
    QAP_FOREACH(arr,qap_add_back(out)=IToS(ex.plan.arr.size())+"  "+ex.to_code());
    string s=join(out,"\n");
    file_put_contents("merge.plan_size.txt",s);return;
  }
  void mainloop(){
    /*
    {
      const int N=1;
      seed="SEED ML_v5 N="+IToS(N);
      cout<<"ML_v5"<<endl;
      cout<<"build at ###_BUILD_TIME_###"<<endl;
      fstream wins_log;
      wins_log.open("wins"+IToS(N)+".log.cpp",std::ios::out|std::ios::trunc);
      t_plan_generator PG;
      PG.init_with(string(seed));
      vector<t_plan_with_side> out;
      vector<string> wins;
      t_two_top all;
      all.add_each_from_versions();
      for(int world_id=0;world_id<6*3;world_id++){
        vector<t_plan_with_side> tmp;
        t_two_top::merge(*this,all,world_id,PG,tmp);
        QAP_FOREACH(tmp,ex.info+=", world_id="+IToS(world_id);qap_add_back(wins)=ex.to_code();wins_log<<wins.back()<<endl;);
        out+=tmp;
      }
      file_put_contents("wins"+IToS(N)+".cpp",join(wins,"\n"));
    }
    return;
    //{
    //  const int N=40112;
    //  seed="SEED ML_v5 N="+IToS(N);
    //  t_plan_generator PG;
    //  PG.init_with(string(seed));
    //  //t_two_top::main(*this,3+6*2,PG);
    //  t_two_top::merge(*this,3+6*2,PG);
    //}
    //return;
    //QapClock clock;
    //for(int i=0;i<64;i++){
    //  auto rnd=rand()%(1024*64);
    //  auto a=get_by_id(701001-rnd,"SEED ML_v3 N=150000"+IToS(i),0,"",false);
    //  auto b=get_by_id(701001-rnd,"SEED ML_v3 N=150000"+IToS(i),0,"",true);
    //  QapAssert(a.plan.arr==b.plan.arr);
    //}
    //get_by_id(700000,"SEED ML_v4 N=150000",0,"",true);
    //cout<<clock.MS()<<endl;return;
    const int N=900500;//(50174/126.0)*3600*14/36.0;
    seed="SEED ML_v4 N="+IToS(N);
    //seed="SEED 2018.10.06 20:46";
    //ML_impl_v4({0,0,0},N,31);return;
    */
    const int N=36;
    seed="SEED ML_v5 N="+IToS(N);
    ML_v4(N,100);
  }
  vector<t_plan_with_side> all_winners;
  t_plan_with_side ML_impl_v4(t_WI wi,size_t N=100,size_t const_base_n=2,t_plan_with_side*penemy=nullptr){
    string WI=wi.tostr();
    const int world_id=wi.map+6*wi.car;
    string head="world_id:"+IToS(world_id)+",side:"+IToS(wi.side);
    QapClock clock;

    vector<t_plan_with_side> winners;
    auto get_by_id=[this,&winners](int plan_id,const string&seed,int pId,const string&info){qap_add_back(winners)=this->get_by_id(plan_id,seed,pId,info);};
    auto empty=this->get_by_id(-1,"empty",wi.side,WI);
    qap_add_back(winners)=empty;
    //get_by_id(289560,"SEED ML_v2 N=300000",1,"win vs empty at iter 129, avg_iter 293.978957, force_vs_rnd is 91.730432%, host.force is 59.905660%, samples:12546, WI:[0,0,0], ms:249793");
    qap_add_back(winners)=get_winner_for(wi.map,wi.car,wi.side?0:1,"merge");
    //winners.clear();
    //winners+=get_all_winners("old_300T");
    //get_by_id(1281,"SEED 2018.10.12 22:05",1,"win vs get_by_id(6208,\"SEED ML_v3 N=9999\",0,\"\"); at iter 1150, avg_iter 133.51, force_vs_rnd is 97.37%, host.force is 72.94%, samples:457, WI:[3,2,0], ms:179975");

    size_t base_n=const_base_n;
    t_player host;
    host.pws=winners.back();
    host.pws.pId=wi.side;

    t_player empty_host;empty_host.pws=empty;

    t_plan_generator PG;
    PG.init_with(string(seed));
  
    vector<t_player> earr;

    bool use_winners_merger=true;

    if(use_winners_merger)
    {
      if(all_winners.empty()){
        all_winners+=get_all_winners("merge2");
        vector<string> sarr;
        QAP_FOREACH(all_winners,auto u=ex.to_code(true);qap_add_back(sarr)=qap_includes(sarr,u)?"fail":u;);
        clean_if_v2(all_winners,[&](const t_plan_with_side&ex,int id)->int{return sarr[id]=="fail";});
        sarr.clear();
        QAP_FOREACH(all_winners,auto u=ex.to_code();qap_add_back(sarr)=qap_includes(sarr,u)?"fail":u;);
        cout<<join(sarr,"\n")<<endl;
      }
    
      QAP_FOREACH(all_winners,auto&b=qap_add_back(earr);b=pws2player(ex);b.pws.pId=empty.pId?0:1);
    }else{
      /*
      auto head=earr;
      qap_add_back(head)=pws2player(
        this->get_by_id(19515,"SEED ML_v3 N=15000",0,"win vs get_by_id(289560,\"SEED ML_v2 N=300000\",1,\"\"); at iter 909, avg_iter 239.90, force_vs_rnd is 94.06%, host.force is 92.12%, samples:488, WI:[0,0,1], ms:200211")
      );
      qap_add_back(head)=pws2player(
        this->get_by_id(64731,"SEED ML_v3 N=150000",0,"win vs get_by_id(289560,\"SEED ML_v2 N=300000\",1,\"\"); at iter 910, avg_iter 189.40, force_vs_rnd is 98.05%, host.force is 92.33%, samples:128, WI:[0,0,1], ms:814463")
      );
      vector<t_plan_with_side> id2pnv700k;
      cout<<"id2pnv700k::bef"<<endl;
      id2pnv700k.resize(N);
      cout<<"id2pnv700k::aft"<<endl;
      {
        auto f=[&](int id){if(id==19515||id==64731)return;id2pnv700k[id].plan_id=id;};
        #include "some_ids.inl"
      }
      t_plan_generator pg;pg.init_with(seed);
      auto pId=wi.side?0:1;
      QAP_FOREACH(id2pnv700k,
        auto p=pg.rnd_plan();
        if(ex.plan_id>=0){
          ex.pId=pId;
          ex.plan_id=i;
          ex.seed=seed;
          ex.plan=p;
        }
      );
      auto f=[&](int id){if(id==19515||id==64731)return;qap_add_back(head)=pws2player(
        id2pnv700k[id]
      );};
      #include "some_ids.inl"
      //gen_players(PG,earr,N,empty.pId?0:1);
      head+=earr;
      earr=head;
      */
      gen_players(PG,earr,N,empty.pId?0:1);
    }

    auto drop_when_lose_vs_host=[&](const string&host_name,t_player&host,vector<t_player>&earr){
      cout<<host_name<<" = "<<host.pws.to_code()<<"\n"<<endl;
      host_vs_earr(world_id,host,earr,false);
      clean_if(earr,[](t_player&ex)->int{return ex.res.number_of_deads_v2()>0;});
    };

    if(!use_winners_merger)
    {
      drop_when_lose_vs_host("host",host,earr);
      QAP_FOREACH(earr,ex.old=ex.res);
      drop_when_lose_vs_host("empty_host",empty_host,earr);
    }else{
      drop_when_lose_vs_host("empty_host",empty_host,earr);
      QAP_FOREACH(earr,ex.old=ex.res);
    }
    
    for(bool start=true;;start=false)
    {
      cout<<"=====bef("+head+",LEFT:"<<earr.size()<<")"<<endl;
      QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
      if(!start){
        auto EN=earr.size();
        int deadline=std::max<int>(1,earr.size()*42/100);
        deadline=std::min<int>(deadline,4096);
        auto&top1=earr[0].res;auto top1_nd=top1.number_of_deads_v2();auto top1_force=top1.get_force();auto top1_samples=int(top1.samples);
        clean_if_v2(earr,[EN,deadline,top1_nd,const_base_n,top1_force](t_player&ex,int id){
          return id>=deadline&&(
            ex.res.number_of_deads_v2()>=top1_nd+const_base_n||
            (ex.res.get_force()+12.5<top1_force)||
            (EN>20000&&ex.res.number_of_deads_v2()>=top1_nd+1)||
            (EN>10000&&ex.res.number_of_deads_v2()>=top1_nd+2)||
            (EN>5000&&ex.res.number_of_deads_v2()>=top1_nd+3)
          );
        });
        if(earr.size()<=1||top1_samples>16000)break;
        //buff.resize(buff.size()/3);
        cout<<"=====aft("+head+",LEFT:"<<earr.size()<<")"<<endl;
      }
      base_n++;
      vector<t_player> tmp_earr;
      if(start&&earr.size()>1000){
        auto eh=pws2player(this->get_by_id(-1,"empty",wi.side?0:1,WI));
        gen_players(PG,tmp_earr,base_n*100,empty.pId);
        auto run_vs=[&](const string&host_name,t_player&host,vector<t_player>&earr,bool need_clean){
          //drop_when_lose_vs_host(host_name,host,earr);
          cout<<host_name<<" = "<<host.pws.to_code()<<"\n"<<endl;
          host_vs_earr(world_id,host,earr,false);
          if(need_clean)clean_if(earr,[](t_player&ex)->int{return ex.res.number_of_deads_v2()>0;});
          if(!need_clean)QAP_SORT_BY_FIELD(earr,res.get_score(),t_player);
        };
        vector<t_player> like_our;
        gen_players(PG,like_our,base_n*5,eh.pws.pId);
        run_vs("run_vs.host",eh,tmp_earr,true);
        QAP_FOREACH(like_our,{
          run_vs("run_vs.host["+IToS(i)+"]",ex,tmp_earr,false);
        });
        clean_if_v2(tmp_earr,[&](t_player&ex,int id){return id>=base_n;});
        QAP_FOREACH(tmp_earr,cout<<"like_tmp_host = "<<ex.pws.to_code()<<"\n"<<endl;);
      }else{
        gen_players(PG,tmp_earr,base_n,empty.pId);
      }
      for(int i=0;i<earr.size();i++){
        auto&ex=earr[i];
        host_vs_earr(world_id,ex,tmp_earr,true);
      }
    }
    cout<<"=====("+head+",LEFT:"<<earr.size()<<")"<<endl;
    auto id=QAP_MINVAL_ID_OF_VEC(earr,ex.res.get_score());
    auto&win=earr[id];
    auto&wpws=win.pws;
    auto&wres=win.res;
    auto&ores=win.old;
    string msg="win vs "+host.pws.to_code(true)+" at iter "+IToS(ores.iter)+", avg_iter "+FToS(wres.avg_iter())+", force_vs_rnd is "+FToS(wres.get_force())+"%";
      msg+=", host.force is "+FToS(host.res.get_force())+"%";
      msg+=", samples:"+IToS(wres.samples);
      msg+=", WI:"+WI;
      msg+=", ms:"+IToS(clock.MS());
    wpws.info=msg;
    cout<<"\n\n..........\n\n"<<endl;
    cout<<"clock.MS() = "<<clock.MS()<<endl;
    cout<<"      host.to_str() = "<<host.to_str()<<endl;
    cout<<"empty_host.to_str() = "<<empty_host.to_str()<<endl;
    cout<<"       win.to_str() = "<<win.to_str()<<endl;
    cout<<"host.pws.to_code() = "<<host.pws.to_code()<<endl;
    cout<<" win.pws.to_code() = "<<win.pws.to_code()<<endl;
    //cout<<msg<<endl;
    return win.pws;
  }
};

void localrunner(){
  t_looped_runner LR;
  LR.init();
  LR.mainloop();
  return;
}

void localrunner_old(){
  t_allworlds aw;
  string path="";
  ADLER_DEBUG(path="../Demo/");
  aw.load(path+"allworlds.json");
  QapClock clock;
  int map_id=3;int car_id=0;
  cout<<"localrunner_old waiting map_id and car_id in stdin";
  if(!cin.eof())cin>>map_id;
  if(!cin.eof())cin>>car_id;
  auto world=aw.get(map_id+6*car_id);
  t_wait_style_io sa,sb;t_app*papp=nullptr;
  bool async=true;
  vector<t_looped_runner::t_plan_with_side> winners;
  auto get_by_id=[&winners](int plan_id,const string&seed,int pId,const string&info){qap_add_back(winners)=t_looped_runner::get_by_id(plan_id,seed,pId,info);};
  /*
  //get_by_id(979,"SEED 2018.10.06 20:46",1,"win vs 839 at iter 241, avg_iter 513.40, force_vs_rnd is 90.93%, host.force is 87.79%, samples:546");
  //get_by_id(2813,"SEED 2018.10.06 20:46",0,"win vs 979 at iter 168, avg_iter 245.74, force_vs_rnd is 88.70%, host.force is 90.17%, samples:606");
  //get_by_id(6378,"SEED 2018.10.06 20:46",1,"win vs 2813 at iter 459, avg_iter 566.86, force_vs_rnd is 93.25%, host.force is 85.96%, samples:726");
  //get_by_id(7437,"SEED 2018.10.06 20:46",0,"win vs 6378 at iter 125, avg_iter 195.02, force_vs_rnd is 89.26%, host.force is 90.98%, samples:726");
  
  get_by_id(1201,"SEED 2018.10.06 20:46",1,"win vs 845 at iter 91, avg_iter 203.19, force_vs_rnd is 83.70%, host.force is 93.07%, samples:546");
  get_by_id(845,"SEED 2018.10.06 20:46",0,"win vs -1 at iter 912, avg_iter 560.36, force_vs_rnd is 93.65%, host.force is 74.39%, samples:1126");
  
  get_by_id(-1,"empty",1,"");
  //get_by_id(289560,"SEED ML_v2 N=300000",1,"win vs -1 at iter 129, avg_iter 323.503665, force_vs_rnd is 95.340314%, host.force is 74.185500%, samples:955, WI:[0,0,0], ms:16269261");
  get_by_id(-1,"empty",0,"");
  //get_by_id(287,"SEED 2018.10.06 20:46",1,"win vs 10252 at iter 151, avg_iter 271.81, force_vs_rnd is 87.72%, host.force is 93.41%, samples:916");
      //get_by_id(10252,"SEED 2018.10.06 20:46",0,"win vs -1 at iter 234, avg_iter 418.44, force_vs_rnd is 94.66%, host.force is 74.32%, samples:1846"); //map3
     // get_by_id(1946,"SEED 2018.10.06 20:46",0,"win vs -1 at iter 916, avg_iter 486.15, force_vs_rnd is 97.54%, host.force is 72.08%, samples:1846"); //map2
      //get_by_id(4629,"SEED 2018.10.06 20:46",0,"win vs -1 at iter 82, avg_iter 126.73, force_vs_rnd is 94.72%, host.force is 81.11%, samples:966"); //map5 this guy win vs me_final
     //get_by_id(5131,"SEED 2018.10.06 20:46",0,"win vs -1 at iter 112, avg_iter 315.12, force_vs_rnd is 92.28%, host.force is 45.90%, samples:1846"); //map1
     //get_by_id(704,"SEED 2018.10.06 20:46",1,"win vs 4629 at iter 116, avg_iter 186.95, force_vs_rnd is 86.90%, host.force is 93.60%, samples:916");
  get_by_id(-1,"empty",0,"");
  //get_by_id(-1,"empty",0,"");
  //qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,0);
  //get_by_id(4562,"SEED 2018.10.06 20:46",1,"win vs 573300 at iter 217, avg_iter 283.43, force_vs_rnd is 98.09%, host.force is 99.95%, samples:8020,");
  //qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,0);
  //get_by_id(613988,"SEED 2018.10.06 20:46",0,"win vs 104960");//get_by_id(573300,"SEED 2018.10.06 20:46",0,"win...");
  get_by_id(171401,"SEED ML_v2 N=300000",1,"win vs -1 at iter 896, avg_iter 598.400000, force_vs_rnd is 99.400000%, host.force is 61.828000%, samples:1000, WI:[0,1,0], ms:13987812");
  */
  //get_by_id(1,"A",1,"nope");
  get_by_id(-1,"empty",1,"nope");
  
  qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,0,"nuc.v3.9999");
  //get_by_id(-1,"empty",0,"nope");
  qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,1,"nwg.256k.5160m");

  qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,0,"merge");
  qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,1,"ML_v3_50174");//get_by_id(-1,"empty",0,"nope");
  //qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,0);
  //qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,0);//get_by_id(-1,"empty",0,"nope");
 //qap_add_back(winners)=t_looped_runner::get_winner_for(map_id,car_id,1);//get_by_id(289560,"SEED ML_v2 N=300000",1,"win vs -1 at iter 129, avg_iter 303.656117, force_vs_rnd is 94.750456%, host.force is 74.252500%, samples:3286, WI:[3,0,0], ms:16426225");
  //get_by_id(222103,"SEED ML_v2 N=262144",0,"win vs -1 at iter 910, avg_iter 306.048523, force_vs_rnd is 99.959565%, host.force is 83.579254%, samples:16075, WI:[3,2,1], ms:12069689");
  auto wn=winners.size();
  auto ws2=winners[wn-2];
  auto ws1=winners[wn-1];

  auto p1=ws2.pId==1?ws2:ws1;//blue
  auto p0=ws2.pId==1?ws1:ws2;//red

  if(async)
  {
    bool use_p1_vis=false;bool use_b2k=false;
    std::thread ta([&](){
      if(use_b2k&&!use_p1_vis)t_looped_runner::brain2k(sa);
      if(use_p1_vis){
        t_app app;app.pstream=&sa;app.dont_use_dstreams();papp=&app;
        app.cur_plan=p1.plan;
        app.keep_cur_plan=true;
        app.main();
        return;
      }
      auto our=p1;
      t_plan_runner PR;PR.ptr=&our.plan;
      //auto our=t_looped_runner::get_by_id(1593,"SEED 2018.10.06 20:46",1,"");
      if(1)for(int i=0;;i++){sa.getline();sa.send_with_endl(t_app::dump(PR.next(),""));}
      if(1)for(int i=0;;i++){sa.getline();sa.send_with_endl(t_app::dump(t_move().set(i<100?0:-1),""));}
      t_app app;app.pstream=&sa;app.dont_use_dstreams();papp=&app;
      app.pause_at_frame=2;
      //app.nbf.debug=true;
      app.main_v2();
    });
    std::thread tb([&](){
      if(use_b2k&&use_p1_vis)t_looped_runner::brain2k(sb);
      t_plan_runner PR;PR.ptr=&p0.plan;
      if(use_p1_vis)if(1)for(int i=0;;i++){sb.getline();sb.send_with_endl(t_app::dump(PR.next(),""));}
      //if(1)for(int i=0;;i++){sb.getline();sb.send_with_endl(t_app::dump(t_move().set(i<100?0:+1),""));}
      t_app app;app.pstream=&sb;app.dont_use_dstreams();papp=&app;
      app.cur_plan=p0.plan;//t_looped_runner::get_by_id(19,"SEED 2018.10.06 20:46",0,"").plan;
      app.keep_cur_plan=true;
      app.main();
    });
    ta.detach();
    tb.detach();
    #ifdef Adler
      std::thread tw([&](){
        for(;!papp;)Sleep(100);
        win_main(*papp);
      });
      tw.detach();
    #endif
  }
  t_new_match match;
  t_mech mech;
  {
    t_world w;
    w.conf=&match;
    {t_app::t_msg msg;bool ok=msg.parse(world.match);QapAssert(ok&&msg.new_match);match=msg.match;}
    {t_app::t_msg msg;bool ok=msg.parse(world.upd);QapAssert(ok&&!msg.new_match);w.upd=msg.upd;}
    auto reload_mech=[&w](t_mech&m){
      if(m.space){m.free();m=t_mech();}
      m.ignore_log=true;
      m.load_from(w);
      m.need_load=false;
    };
    reload_mech(mech);
  }
  sa.inp.push(world.match);
  sb.inp.push(world.match);
  for(int iter=0;;iter++)
  {
    if(mech.smb_deaded())
    {
      if(papp){ADLER_DEBUG(Sleep(100);continue;);}
      cerr<<"mech.space->userData="<<size_t(mech.space->userData)<<endl;
      cerr<<"iter="<<iter<<endl;
      cerr<<"ms="<<clock.MS()<<endl;
      return;
    }
    if(async)
    {
      t_upd upd;upd.grab_from(mech);
      auto au=upd2str(upd,1);
      auto bu=upd2str(upd,0);
      sa.inp.push(au);
      sb.inp.push(bu);
      cout<<au<<endl;
      if(papp)ADLER_DEBUG(Sleep(16););
    }
    if(!async)
    {      
      mech.apply_direct(1,t_move().set(iter<550?0:-1),false);
      mech.apply_direct(0,t_move().set(iter<600?0:+1),false);
    }else{
      mech.apply_direct(1,get_move(sa.out.pop()),false);
      mech.apply_direct(0,get_move(sb.out.pop()),false);
    }
    mech.tickEvent(false);
    if(mech.smb_deaded())continue;
  }
}

/*
var m={};
POST.data.split("\n").filter(e=>!e.includes("best")).map(e=>e.split("   ").map(e=>JSON.parse(e))).map(
  e=>getdef(m,e[0],[]).push(e[1])
);

mapkeys(m).map(e=>m[e]=qapavg(m[e]));
m=mapsort(keys_with_prefix(m,"_"),(k,v)=>-v);
return jstable(mapkeys(m).map(k=>{var u={key:k,v:m[k]};return u;}));
*/
int main_const_tuning(){
  vector<t_looped_runner::t_plan_with_side> out;out.reserve(10000);//105
  for(int iter=0;;iter++){
    out.clear();auto seed="foobar"+IToS(iter);
    vector<real> t;int base=0;
    for(int i=base;i<60;i++){
      auto ms=0.0;
      MemoryBarrier();QapClock clock;MemoryBarrier();
      //to_xxxxx_n=i;
      qap_add_back(out)=t_looped_runner::get_by_id(300*100,seed,0,"");
      MemoryBarrier();ms=clock.MS();MemoryBarrier();
      cout<<i<<"   "<<FToS(ms)<<endl;
      qap_add_back(t)=ms;
    }
    auto id=QAP_MINVAL_ID_OF_VEC(t,ex);
    cout<<"best = "<<int(base+id)<<endl;
  }
  return 0;
}

int main()
{
  //return main_const_tuning();
  //localrunner_old(); return 0;
  //localrunner(); return 0;//*/
  if(bool use_nk=true)
  {
    unique_ptr<t_two_stream<>> up_stream(new t_two_stream<>());
    auto&stream=*up_stream.get();stream.init();
    //stream.do_popen("node ..\\Demo\\LR.js wb","wb");
    //stream.pout=stream.p;
    //stream.do_popen("node ..\\Demo\\LR.js rb","rb");
    t_looped_runner::brain2k(stream);
    return 0;
  }
  #ifdef Adler
  for(bool need_wait_when_debuger_will_be_attached=0;need_wait_when_debuger_will_be_attached;)
  {
    Sleep(1);
    int gg=1;
  }
  #endif
  #ifdef Adler
    unique_ptr<t_two_stream<>> up_stream(new t_two_stream<>());
    auto&stream=*up_stream.get();stream.init();
  #else
    t_cpp_style_io stream;
  #endif
  t_app app;app.pstream=&stream;
  #ifdef Adler
    int game_id=373601;
    bool LR_js=1;
    if(int(LR_js)*game_id){
      stream.do_popen("node ..\\Demo\\LR.js wb","wb");
      stream.pout=stream.p;
      stream.do_popen("node ..\\Demo\\LR.js rb","rb");
    }else{
      //stream.do_fopen("lines2.json","rb");app.withoutbrain=true;
      //stream.do_fopen("debug.json","rb");
      //stream.do_fopen("pretty.readtimeout.json","rb");
      app.withSleep=true;
      //app.withoutbrain=true;
      stream.do_popen("node ..\\Demo\\visio_to_stdin.js 2 visio","rb");
      //stream.do_popen(("node ..\\Demo\\visio_to_stdin.js 2 "+IToS(game_id)).c_str(),"rb"); // не хватает длинны и частоты симуляции.
      /*
      стратегия при резком контакте с поверхностью должна тратить максимум вычеслительный ресурсов. без этого никуда.
      тоечнее, если происходит какой-то серьёзный обмен импульсами.
      
      нужно рисовать предсказаную траеторию.
      
      на U-карте очень тупо прыгать вниз если противник не собираеться поступать так же.
        предрасчитывать тупиковые места на карте? городить глобальную карту опасности? ну там места для простреллов...

      */
    }
    if(bool without_renderer=0){
      app.main_v2();
    }else{
      std::thread amt([&]{app.main_v2();});
      amt.detach();
      win_main(app);
    }
  #else
  app.main_v2();
  #endif
  // cerr<<"build at ###_BUILD_TIME_###\n";
  return 0;
}
#endif
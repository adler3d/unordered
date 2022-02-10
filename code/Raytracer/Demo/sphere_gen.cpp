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
using std::vector;
using std::string;

#include <iostream>
using namespace std;


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

typedef double real;

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
  #define F(x,OPER)x OPER v.x;
  #define U(OPER)void operator OPER(const SelfClass&v){LIST(F,OPER)}
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
    return sqrtf(x*x+y*y+z*z);
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

class vec3f{
public:
  float x,y,z;
  vec3f(){x=0;y=0;z=0;}
  vec3f(float x,float y,float z)
  {
    #define F(a)this->a=a;
    F(x);F(y);F(z);
    #undef F
  }
public:
  operator vec3d()const{return vec3d(x,y,z);}
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
  void operator+=(const vec3f&v){x+=v.x;y+=v.y;z+=v.z;}
  void operator-=(const vec3f&v){x-=v.x;y-=v.y;z-=v.z;}
  void operator+=(const vec3d&v){x+=v.x;y+=v.y;z+=v.z;}
  void operator-=(const vec3d&v){x-=v.x;y-=v.y;z-=v.z;}
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
    return sqrtf(x*x+y*y+z*z);
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


#ifndef QAP_LITE_H
#define QapDebugMsg(MSG){printf("QapDebugMsg :: %s:%i :: %s\n",__FILE__,__LINE__,string(MSG).c_str());fflush(stdout);}//__debugbreak();
#define QapAssert(COND)if(!(COND)){printf("QapAssert :: %s:%i :: %s\n",__FILE__,__LINE__,#COND);fflush(stdout);exit(0);}//__debugbreak();
#define QapNoWay(){printf("QapNoWay :: %s:%i\n",__FILE__,__LINE__);fflush(stdout);exit(0);}//__debugbreak();
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

template<class TYPE>
static void operator+=(vector<TYPE>&dest,const vector<TYPE>&arr){
  for(int i=0;i<arr.size();i++){
    dest.push_back(arr[i]);
  }
}

template<class TYPE>int qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}

#define QAP_MINVAL_ID_OF_VEC(arr,code)qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return code;})

template<class TYPE,class FUNC>void qap_foreach(TYPE&&arr,FUNC func){auto n=arr.size();for(int i=0;i<n;i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const TYPE&arr,FUNC func){auto n=arr.size();for(int i=0;i<n;i++)func(arr[i],i);}
#define QAP_FOREACH(arr,code)qap_foreach(arr,[&](decltype(arr[0])&ex,int i){code;})

#ifndef QAP_LITE_H
static double sqr(double x){return x*x;}

inline int SToI(const string&S){int i;sscanf(S.c_str(),"%i",&i);return i;};

inline string IToS(const int&v){return std::to_string(v);};
inline string FToS(const double&v){return std::to_string(v);};

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
#endif // QAP_LITE_H

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

struct t_ball{
  vec3f pos,v;
};

struct t_phys_sphere{
  vector<t_ball> balls;
  void update_link(t_ball&a,t_ball&b)
  {
    auto k=1.0/(balls.size()*2);
    auto ab=b.pos-a.pos;
    auto dist=2;
    auto f=ab.Mag()-dist;
    auto dv=ab.Norm()*(f*k);
    a.v+=+dv;
    b.v+=-dv;
  }
  string to_binstr()const{
    if(balls.empty())return "";
    string out;
    out.resize(balls.size()*sizeof(t_ball)+4);
    auto&n=*(int*)(void*)&out[0];n=balls.size();
    auto*p=(t_ball*)(void*)&out[4];
    for(int i=0;i<balls.size();i++)p[i]=balls[i];
    return out;
  }
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
  bool load(const string&FN){
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f)return false;
    int L=FileLength(f);
    string mem;
    mem.resize(L);
    if(L)f.read(&mem[0],L);
    f.close();
    auto&n=*(int*)(void*)&mem[0];
    if(4+n*sizeof(t_ball)!=L){printf("t_phys_sphere::load - failed\n");return false;}
    balls.resize(n);
    auto*p=(t_ball*)(void*)&mem[4];
    QAP_FOREACH(balls,ex=p[i]);
    return true;
  }
};

#include <mutex>
#include <atomic>
#include <omp.h>

typedef long long int int64;
typedef atomic<int64> atomic_int64;
// curl http://zqn0.now.sh/eval?nolog&code=exec_post_data();data=curl%20http://vm51.herokuapp.com/sphere_logs/sphere_at_iter11.bin>trash/sphere_at_iter2.bin
int main()
{
  printf("sphere_gen v2.6 16*4k\n");
  #define EXPR(CODE)printf("%s=%i\n",#CODE,CODE);
  EXPR(sizeof(t_ball));
  EXPR(omp_get_num_threads());
  EXPR(omp_get_num_procs());
  EXPR(omp_get_max_threads());
  #undef EXPR
  //return 0;
  t_phys_sphere phys_sphere;
  vector<vec3d> TV[128];
  auto&balls=phys_sphere.balls;
  phys_sphere.load("sphere_atm.bin");
  int n=balls.empty()?512*8*16:balls.size();auto k=0.005*512.0/real(n);
  if(balls.empty())
  {
    printf("sphere_atm.bin - not found\n");
    balls.resize(n);
    auto h=n/2;auto q=h/2;
    for(int i=0;i<balls.size();i++)balls[i].pos=vec3f((i-h)*k,3,0);
    balls[h-1].pos.y+=1;
    balls[h-0].pos.z+=1;
  }else{printf("sphere_atm.bin - ok // n=%i\n",balls.size());}
  atomic_int64 g_subiter(0);
  atomic_int64 iter(0);
  QapClock c2;
  for(;;)
  {
    QapClock clock;
    auto&arr=phys_sphere.balls;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex.pos+=ex.v;
      real di=2;
      ex.v*=real(di-1)/di;
    }
    {
      auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
      auto r=0.0;QAP_FOREACH(arr,r+=(ex.pos-O).Mag());r*=1.0/arr.size();
      QAP_FOREACH(arr,ex.pos=O+(ex.pos-O).Norm()*r);
    }
    int64 n=arr.size();
    //
    auto tn=omp_get_max_threads();
    for(int i=0;i<tn;i++){
      auto&out=TV[i];
      out.resize(0);
      out.resize(arr.size(),vec3d(0,0,0));
      //QAP_FOREACH(arr,out[i]=ex.v);
    }
    {
      atomic_int64 subiter(0);int64 max_subiter=((n+1)*(n*0.5));auto printf_every=std::max<int>(max_subiter/4096,150*1024*250);
      //std::mutex g_mutex;
      auto k=1.0/(n+1);
      #pragma omp parallel for schedule(dynamic,4)
      for(int i=0;i<n;i++)
      {
        auto&V=TV[omp_get_thread_num()];
        auto&VI=V[i];
        auto&a=arr[i];
        int dn=0;
        for(int j=i+1;j<n;j++)
        {
          auto&VJ=V[j];
          auto&b=arr[j];
          auto ab=b.pos-a.pos;
          auto dist=2;
          auto d=ab.Mag();
          d=d?d:0.00125;
          auto f=d-dist;
          auto dv=ab*(f*k/d);
          {
            //std::lock_guard<std::mutex> guard(g_mutex);
            VI+=+dv;
            VJ+=-dv;
            dn++;
          }
        }
        subiter+=dn;g_subiter+=dn;
        //if(subiter%printf_every==0)
        int64 cur_subiter=subiter;
        if((cur_subiter%printf_every)<(cur_subiter-dn)%printf_every)
        {
          #pragma omp critical(msg)
          {
            string msg="progress:"+FToS(100.0*subiter/max_subiter)+" %    iter:"+IToS(iter)/*+"    i:"+IToS(i)*/+"    tn:"+IToS(omp_get_thread_num())+"    avg:"+FToS(g_subiter/c2.MS())+" links/ms"+"    // time = "+FToS(clock.MS())+" ms";
            printf("%s\n",msg.c_str());
          }
        }
        int gg=1;
      }
    }
    //
    for(int i=0;i<tn;i++){
      auto&out=TV[i];
      QAP_FOREACH(out,arr[i].v+=ex);
    }
    iter++;
    unix_SaveFile("sphere_at_iter"+IToS(iter)+".bin",phys_sphere.to_binstr());
  }
}

void unused_function(){
/*
unlink sphere_gen.elf
ps -aux
wget nwg-nwg.193b.starter-ca-central-1.openshiftapps.com/sphere_gen.elf
chmod +x sphere_gen.elf
mkdir -p sphere_logs
ls -lh *.elf
cd sphere_logs
curl nwg-nwg.193b.starter-ca-central-1.openshiftapps.com/sphere_at_iter3.bin>sphere_atm.bin
../sphere_gen.elf|tee ../sphere_gen.log

*/
  // nope here
  /*
    // threadprivate.c
    #include <stdlib.h>
    #include <stdio.h>
    #include <omp.h>


    static int tp;


    int main(int argc,char **argv) {


      #pragma omp threadprivate(tp)


      #pragma omp parallel num_threads(7)
      tp = omp_get_thread_num();


      #pragma omp parallel num_threads(9)
      printf("Thread %d has %d\n",omp_get_thread_num(),tp);


      return 0;
    }
  */
  /*
  resp_off();
  async_cl_and_exec_cpp(POST.data," -fopenmp ");
  #include <stdlib.h>
  #include <stdio.h>
  #include <omp.h>

  int main(int argc,char **argv) {
    printf("%i\n",omp_get_num_procs());
    system("echo ok\nls -lh sphere_at*.bin\ntar -czvf out.tgz sphere_at_iter*\nls -lh *.tgz\nrm -rf sphere_at_iter*");
    return 0;
  }
  */
  /*
  
g++ -std=c++11 -O2 sphere_gen.cpp -osphere_gen.elf
ls -lh *.elf

  */
  /*
kill -9 175
unlink sphere_gen.elf
ps -aux
wget nwg-nwg.193b.starter-ca-central-1.openshiftapps.com/sphere_gen.elf
chmod +x sphere_gen.elf
mkdir -p sphere_logs
ls -lh *.elf
cd sphere_logs
../sphere_gen.elf|tee ../sphere_gen.log
  */
  
  /*
  return ""+execSync("echo rm -f sphere_logs/*.bin;du -hs sphere_logs;ls -lht sphere_logs");
  */
}
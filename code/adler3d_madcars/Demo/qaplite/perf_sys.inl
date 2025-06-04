#define PRO_FUNCGEN_GETP(rettype,getp,arr,name)\
  rettype*getp(string name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

struct t_perf_sys{
  struct t_rec{
    const char*name=nullptr;
    real ms=0;
    int n=0;
    bool old=true;
    //void set(const string&name,real ms){this->name=name;this->ms=ms;n=1;old=false;}
  };
  vector<t_rec> arr;
  vector<t_rec> old;
  //PRO_FUNCGEN_GETP(t_rec,getp,arr,name);
  //PRO_FUNCGEN_GETP(t_rec,getp_old,old,name);
  t_perf_sys(){
    arr.reserve(1024*64);
  }
  void next()
  {
    //for(int i=0;i<old.size();i++){old[i].old=true;}
    //for(int i=0;i<arr.size();i++)
    //{
    //  auto*p=getp_old(arr[i].name);
    //  if(!p){p=&qap_add_back(old);}
    //  *p=arr[i];
    //}
    //arr.clear();
  }
  void add(const char*name,int number,real ms)
  {
    if(arr.size()<number)arr.resize(number+1);
    auto&r=arr[number];
    r.name=name;
    r.ms+=ms;
    r.n++;
    r.old=false;
  }
};

struct t_clock{
  t_perf_sys&sys;
  QapClock clock;
  const char*name;
  int number;
  t_clock(t_perf_sys&sys,const char*name,int number):sys(sys),name(name),number(number){MemoryBarrier();clock.Start();MemoryBarrier();}
  ~t_clock(){MemoryBarrier();sys.add(name,number,clock.MS());MemoryBarrier();}
};
static t_perf_sys&get_global_perf(){static t_perf_sys global_perf;return global_perf;};
#define QAP_PERF(NAME)t_clock scope_clock(get_global_perf(),NAME,__LINE__);
#define QAP_PERF_CODE(CODE){t_clock scope_clock(get_global_perf(),#CODE,__LINE__);CODE;}
#define NO_QAP_PERF_CODE(CODE){CODE;}
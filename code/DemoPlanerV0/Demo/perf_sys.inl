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
    string name;
    real ms;
    int n;
    bool old;
    void set(const string&name,real ms){this->name=name;this->ms=ms;n=1;old=false;}
  };
  vector<t_rec> arr;
  vector<t_rec> old;
  PRO_FUNCGEN_GETP(t_rec,getp,arr,name);
  PRO_FUNCGEN_GETP(t_rec,getp_old,old,name);
  void next()
  {
    for(int i=0;i<old.size();i++){old[i].old=true;}
    for(int i=0;i<arr.size();i++)
    {
      auto*p=getp_old(arr[i].name);
      if(!p){p=&qap_add_back(old);}
      *p=arr[i];
    }
    arr.clear();
  }
  void add(string name,real ms)
  {
    auto*p=getp(name);
    if(!p){
      qap_add_back(arr).set(name,ms);
      return;
    }
    p->ms+=ms;
    p->n++;
    p->old=false;
  }
};

struct t_clock{
  t_perf_sys&sys;
  QapClock clock;
  string name;
  t_clock(t_perf_sys&sys,const string&name):sys(sys),name(name){MemoryBarrier();clock.Start();MemoryBarrier();}
  ~t_clock(){MemoryBarrier();sys.add(name,clock.MS());MemoryBarrier();}
};
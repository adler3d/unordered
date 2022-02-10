//it is only a draft
static bool CD_CircleAndWall(const vec2d&pos,vec2d&v,const real&r,const vec2d&a,const vec2d&b){
  if(abs((pos-a).Rot(b-a).y)>r)return false;
  if((pos-a).Rot(b-a).x<0)return false;
  if((pos-a).Rot(b-a).x>(b-a).Mag())return false;
  if(Sign(v.Rot(b-a).y)==Sign((pos-a).Rot(b-a).y))return false;
  v=vec2d(v.Rot(b-a).x,-v.Rot(b-a).y).UnRot(b-a);return true;
}

//it is only a draft
static bool CD_CircleAndWallCircle(const vec2d&pos,vec2d&v,const real&d,const vec2d&a){
  if((pos-a).Mag()>d)return false;
  if(v.Rot(pos-a).x>0)return false;
  v=vec2d(-v.Rot(pos-a).x,v.Rot(pos-a).y).UnRot(pos-a);
  return true;
}

static bool FastCD_CircleAndWallWithCircles(const vec2d&pos,vec2d&v,const real&r,const vec2d&a,const vec2d&b)
{
  vec2d c=(a+b)*0.5;
  if(c.sqr_dist_to(pos)>b.sqr_dist_to(a))return false;
  bool has_cd=false;
  has_cd=has_cd||CD_CircleAndWall(pos,v,r,a,b);
  has_cd=has_cd||CD_CircleAndWallCircle(pos,v,r,a);
  has_cd=has_cd||CD_CircleAndWallCircle(pos,v,r,b);
  return has_cd;
}

struct t_cd_pair{
  int a;
  int b;
  void set(int i,int j){
    //QapAssert(i!=j);
    a=i;b=j;
  }
  void fix_order(){if(a>b)std::swap(a,b);}
  static int __cdecl cmp_func(const void*a,const void*b){return cmp(*(t_cd_pair*)a,*(t_cd_pair*)b);}
  static int cmp(const t_cd_pair&a,const t_cd_pair&b)
  {
    auto da=a.a-b.a;
    auto db=a.b-b.b;
    return da?da:db;
  }
  bool operator==(const t_cd_pair&ref)const{return (a==ref.a&&b==ref.b);}
  //bool operator==(const t_cd_pair&ref)const{return (a==ref.a&&b==ref.b)||(b==ref.a&&a==ref.b);}
};
struct t_cd_debug_info{
  vec2d minp;
  vec2d maxp;
  int xn;
  int yn;
};

template<class t_point>
class t_cd_dev{
public:
  typedef vector<t_cd_pair> t_cd_arr;
  //typedef t_obj t_point;
public:
  #define DEF_PRO_UNSAVEABLE()
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_perf_sys&,perf_sys,$)\
  ADD(t_cd_arr&,cd_arr,$)\
  ADD(vector<t_point>&,points,$)\
  ADD(int,r,$)\
  ADD(t_cd_debug_info,info,$)\
  //===
  #include "defprovar.inl"
  //===
public:
  t_cd_dev(t_perf_sys&perf_sys,t_cd_arr&cd_arr,vector<t_point>&points,int r):perf_sys(perf_sys),cd_arr(cd_arr),points(points),r(r)
  {
    DoReset();
    cd_arr.reserve(points.size()*3);
  }
public:
  void cd_points(){return find_cd_in_points();}
  void find_cd_in_points()
  {
    QapAssert(r>0);
    auto d=r+r;
    auto dd=d*d;
    t_clock clock(perf_sys,"cd_finder");
    auto&arr=points;
    for(int i=0;i<arr.size();i++)
    {
      auto&a=arr[i];
      for(int j=i+1;j<arr.size();j++)
      {
        auto&b=arr[j];
        auto ox=b.pos-a.pos;
        //if(abs(ox.x)>r+r)continue;
        if(abs(ox.y)>d)continue;
        if(ox.SqrMag()>dd)continue;
        qap_add_back(cd_arr).set(i,j);
      }
    }
  }
public:
  void find_cd(const vector<int>&IA)
  {
    QapAssert(r>0);
    auto d=r+r;
    auto dd=d*d;
    for(int i=0;i<IA.size();i++)
    {
      auto&a=points[IA[i]];
      for(int j=i+1;j<IA.size();j++)
      {
        auto&b=points[IA[j]];
        auto ox=b.pos-a.pos;
        //if(abs(ox.x)>r+r)continue;
        if(abs(ox.y)>d)continue;
        if(ox.SqrMag()>dd)continue;
        qap_add_back(cd_arr).set(IA[i],IA[j]);
      }
    }
  }
  void find_cd_between(const vector<int>&IA,const vector<int>&IB)
  {
    //if(IA.empty()||IB.empty())return;
    QapAssert(r>0);
    auto d=r+r;
    auto dd=d*d;
    for(int i=0;i<IA.size();i++)
    {
      auto&a=points[IA[i]];
      for(int j=0;j<IB.size();j++)
      {
        auto&b=points[IB[j]];
        auto ox=b.pos-a.pos;
        //if(abs(ox.x)>r+r)continue;
        if(abs(ox.y)>d)continue;
        if(ox.SqrMag()>dd)continue;
        qap_add_back(cd_arr).set(IA[i],IB[j]);
      }
    }
  }
  void cd_line(int nc=0)
  {
    if(points.empty())return;
    auto&dev=*this;
    static vector<vector<int>> section;
    auto&arr=points;
    auto mm=get_minmax();
    auto n=get_n(mm,nc,r);
    {
      t_clock clock(perf_sys,"cd_init");
      section.resize(n.x);
      {
        auto avg_section_size=points.size()/section.size();
        for(int i=0;i<section.size();i++){section[i].clear();section[i].reserve(avg_section_size);}
      }
      auto f=vec2d(1,1)+mm.maxp-mm.minp;
      real dx=f.x/n.x;
      real sx=mm.minp.x;
      info.maxp=mm.maxp;
      info.minp=mm.minp;
      info.xn=n.x;
      info.yn=0;
      for(int i=0;i<arr.size();i++)
      {
        auto&a=arr[i];
        int id=(a.pos.x-sx)/dx;
        if(!qap_check_id(section,id)){
          QapAssert(false);
        }
        qap_add_back(section[id])=i;
      }
    }
    {
      t_clock clock(perf_sys,"cd_finder");
      for(int m=0;m<section.size();m++)
      {
        auto&ex=section[m];
        dev.find_cd(ex);
      }
      for(int m=0;m+1<section.size();m++)
      {
        auto&a=section[m+0];
        auto&b=section[m+1];
        dev.find_cd_between(a,b);
      }
    }
  }
  void cd_out()
  {
    {
      auto&arr=cd_arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.fix_order();
      }
    }
    {
      if(!cd_arr.empty())
      {
        qsort(&cd_arr[0],cd_arr.size(),sizeof(cd_arr[0]),t_cd_pair::cmp_func);
      }
    }
  }
  struct t_out_cd_rec{
    int arr[8];
    int n;
    t_out_cd_rec(){n=0;}
    inline bool add(int id)
    {
      if(n>=8)return false;
      arr[n++]=id;
      return true;
    }
    static int cmd_int(const void*a,const void*b){return (*(int*)a)-(*(int*)b);}
    void sort_std() //O2 = 25.06 ms
    {
      if(n<2)return;
      qsort(arr,n,sizeof(arr[0]),cmd_int);
    }
    void sort_by_id() // O2 = 29.12 ms
    {
      if(n<2)return;
      for(int i=0;i<n;i++)
      {
        int id=i;
        for(int j=i+1;j<n;j++)
        {
          if(arr[id]>arr[j]){id=j;}
        }
        std::swap(arr[i],arr[id]);
      }
    }
    void sort_by_value() //O2 = 27.20 ms
    {
      if(n<2)return;
      for(int i=0;i<n;i++)
      {
        int id=i;auto v=arr[id];
        for(int j=i+1;j<n;j++)
        {
          if(v>arr[j]){id=j;v=arr[j];}
        }
        std::swap(arr[i],arr[id]);
      }
    }
  };
  void cd_out_fast()
  {
    vector<t_out_cd_rec> pd;
    //vector<vector<int>> rd;
    pd.resize(points.size());
    {
      auto&arr=cd_arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.fix_order();
        if(!pd[ex.a].add(ex.b))return cd_out();
      }
    }
    int gg=1;
    {
      int id=0;
      for(int i=0;i<pd.size();i++)
      {
        auto&ex=pd[i];
        //if(ex.id>=0)cd_arr[id++].set(i,ex.id);
        //if(ex.vec<0)continue;
        auto&arr=ex.arr;
        ex.sort_std();
        for(int j=0;j<ex.n;j++)
        {
          cd_arr[id++].set(i,arr[j]);
        }
      }
    }
  }
public:
  void find_cd_om(const vector<vector<int>>&our_map)
  {
    for(int m=0;m<our_map.size();m++)
    {
      auto&ex=our_map[m];
      //if(ex.size()==2){qap_add_back(cd_arr).set(ex[0],ex[1]);continue;}
      find_cd(ex);
    }
    for(int m=0;m+1<our_map.size();m++)
    {
      auto&a=our_map[m+0];
      auto&b=our_map[m+1];
      find_cd_between(a,b);
    }
  }
  struct t_minmax{
    vec2d minp;
    vec2d maxp;
  };
  t_minmax get_minmax()
  {
    t_minmax out;
    auto&arr=points;
    for(int i=0;i<arr.size();i++)
    {
      auto&a=arr[i];
      if(!i)out.minp=a.pos;
      if(!i)out.maxp=a.pos;
      vec2d::comin(out.minp,a.pos);
      vec2d::comax(out.maxp,a.pos);
    }
    return out;
  }
  static vec2i get_n(t_minmax&mm,int nc,real r)
  {
    auto s=mm.maxp-mm.minp;
    auto f=vec2d(1,1)+s;
    auto koef=0.05+2+nc;
    auto n=f*(1.0/(koef*r));
    if(n.x<1)n.x=1;if(n.y<1)n.y=1;
    return vec2i(n.x,n.y);
  }
  void cd_grid(int nc)
  {
    auto mm=get_minmax();
    auto n=get_n(mm,nc,r);//n.x=8;n.y=8;
    cd_grid_raw(mm,n);
  }
  void cd_grid_raw(t_minmax mm,vec2i n)
  {
    if(points.empty())return;
    static vector<vector<vector<int>>> mmap;
    auto&arr=points;
    //n-=vec2i(20,20);
    {
      info.xn=n.x;
      info.yn=n.y;
      info.maxp=mm.maxp;
      info.minp=mm.minp;
      auto f=vec2d(1,1)+mm.maxp-mm.minp;
      real dy=f.y/n.y;
      real dx=f.x/n.x;
      real sx=mm.minp.x;
      real sy=mm.minp.y;
      mmap.resize(n.y);
      auto nxy=n.x*n.y;
      for(int i=0;i<mmap.size();i++)
      {
        auto&ex=mmap[i];
        //ex.clear();
        ex.resize(n.x);
        for(int i=0;i<ex.size();i++)
        {
          ex[i].clear();
          ex[i].reserve(2*points.size()/nxy);
          int gg=1;
        }
      }
      //info.oms=mmap.size();
      for(int i=0;i<arr.size();i++)
      {
        auto&a=arr[i];
        int y_id=(a.pos.y-sy)/dy;
        int x_id=(a.pos.x-sx)/dx;
        if(!qap_check_id(mmap,y_id)){
          QapAssert(false);
        }
        if(!qap_check_id(mmap[y_id],x_id)){
          QapAssert(false);
        }
        qap_add_back(mmap[y_id][x_id])=i;
      }
    }
    for(int m=0;m<n.y;m++)
    {
      auto&ex=mmap[m];
      find_cd_om(ex);
    }
    for(int m=0;m+1<n.y;m++)
    {
      auto&MIA=mmap[m+0];
      auto&MIB=mmap[m+1];
      QapAssert(MIA.size()==MIB.size());
      for(int i=0;i<n.x;i++)
      {
        auto&IA=MIA[i];
        auto&IB=MIB[i];
        find_cd_between(IA,IB);
      }
      for(int i=0;i+1<n.x;i++)
      {
        auto&a=MIA[i+0];
        auto&b=MIA[i+1];
        auto&c=MIB[i+0];
        auto&d=MIB[i+1];
        find_cd_between(a,d);
        find_cd_between(b,c);
      }
    }
  }
public:
  void find_cd_om_fast(const vector_view<vector<int>>&our_map)
  {
    for(int m=0;m<our_map.size();m++)
    {
      auto&ex=our_map[m];
      find_cd(ex);
    }
    for(int m=0;m+1<our_map.size();m++)
    {
      auto&a=our_map[m+0];
      auto&b=our_map[m+1];
      find_cd_between(a,b);
    }
  }
public:
  void cd_grid_fast(int nc)
  {
    auto mm=get_minmax();
    auto n=get_n(mm,nc,r);//n.x=8;n.y=8;
    cd_grid_fast_raw(mm,n);
  }
  void cd_grid_fast_raw(t_minmax mm,vec2i n)
  {
    if(points.empty())return;
    static vector<vector<int>> mmap;
    auto&arr=points;
    //n-=vec2i(20,20);
    {
      info.xn=n.x;
      info.yn=n.y;
      info.maxp=mm.maxp;
      info.minp=mm.minp;
      auto f=vec2d(1,1)+mm.maxp-mm.minp;
      real dy=f.y/n.y;
      real dx=f.x/n.x;
      real sx=mm.minp.x;
      real sy=mm.minp.y;
      auto nxy=n.x*n.y;
      auto avr_ex_size=2*points.size()/nxy;
      for(int i=0;i<mmap.size();i++){
        auto&ex=mmap[i];
        ex.clear();
        ex.reserve(avr_ex_size);
      }
      mmap.resize(nxy);
      for(int i=0;i<arr.size();i++)
      {
        auto&a=arr[i];
        int y_id=(a.pos.y-sy)/dy;
        int x_id=(a.pos.x-sx)/dx;
        int id=x_id+y_id*n.x;
        QapAssert(InDip<int>(0,x_id,n.x-1));
        QapAssert(InDip<int>(0,y_id,n.y-1));
        QapAssert(qap_check_id(mmap,id));
        qap_add_back(mmap[id])=i;
      }
    }
    auto get_view=[&n](vector<vector<int>>&mmap,int id){
      return make_view(mmap,id*n.x,n.x);
    };
    for(int m=0;m<n.y;m++)
    {
      //auto&ex=mmap[m];
      auto ex=get_view(mmap,m);
      find_cd_om_fast(ex);
    }
    for(int m=0;m+1<n.y;m++)
    {
      auto&MIA=get_view(mmap,m+0);
      auto&MIB=get_view(mmap,m+1);
      QapAssert(MIA.size()==MIB.size());
      for(int i=0;i<n.x;i++)
      {
        auto&IA=MIA[i];
        auto&IB=MIB[i];
        find_cd_between(IA,IB);
      }
      for(int i=0;i+1<n.x;i++)
      {
        auto&a=MIA[i+0];
        auto&b=MIA[i+1];
        auto&c=MIB[i+0];
        auto&d=MIB[i+1];
        find_cd_between(a,d);
        find_cd_between(b,c);
      }
    }
  }
public:
  void solve()
  {
    solve(perf_sys,points,cd_arr,r);
  }
  static void solve(t_perf_sys&perf_sys,vector<t_point>&points,t_cd_arr&cd_arr,real r)
  {
    auto d=r+r;
    auto inv_d=1.0/d;
    for(int i=0;i<cd_arr.size();i++)
    {
      auto&ex=cd_arr[i];
      auto&a=points[ex.a];
      auto&b=points[ex.b];
      auto ox=b.pos-a.pos;
      auto m=ox.Mag();
      auto k=1.0/m-inv_d;
      auto v=ox*k;
      a.v+=-v;
      b.v+=+v;
    }
  }
};
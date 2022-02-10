#include "QapLite.h"
#include "TQapGameV2.inl"
#include "perf_sys.inl"

static vec2i tovec2i(const vec2d&p){return vec2i(p.x,p.y);}
static vec2i vec2d_round(vec2d p,vec2d dir){
  vec2i r;r.x=p.x;r.y=p.y;
  if(dir.x>0)if(real(r.x)!=p.x)r.x++;if(dir.y>0)if(real(r.y)!=p.y)r.y++;return r;
}

#include "CD_Crap.inl"

struct t_point{
  #define DEF_PRO_CLASSNAME()t_point
  #define DEF_PRO_COMPAREABLE()
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,pos,$)\
  //===
  #include "defprovar.inl"
  //===
};

template<class t_world>
static t_world t_world_raw_sim(const t_world&src,const vec2d&cmd,int max_iter)
{
  auto cur=src;
  for(int iter=0;iter<max_iter;iter++)
  {
    cur.actor.a=cur.actor.wasd2a(cmd);
    cur.move_full();
  }
  return cur;
}

const real max_speed=3.0;
const real min_speed=1.0;
struct t_obj{
  #define DEF_PRO_CLASSNAME()t_obj
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,pos,$)\
  ADD(vec2d,v,$)\
  ADD(vec2d,a,$)\
  ADD(vector<t_point>,points,$)\
  //===
  #include "defprovar.inl"
  //===
  void apply_input()
  {
    //auto old_v=v;
    //v+=a;
    v=Vec2dEx(v.GetAng()-a.x*PiD2*1.5*0.25,v.Mag()+a.y);
    if(v.Mag()>max_speed)v=v.SetMag(max_speed);
    if(v.Mag()<min_speed)v=v.SetMag(min_speed);
  }
  void move_full(...)
  {
    apply_input();
    pos+=v;
    QapCleanIf(points,[&](t_point&p){return pos.dist_to_point_less_that_r(p.pos,32);});
  }
  static vec2d wasd2a(const vec2d&wasd){
    return wasd*(1.0/32.0);//wasd.SetMag(0.05).Ort().UnRot(-v);
  }
};

struct t_line{
  #define DEF_PRO_CLASSNAME()t_line
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,a,$)\
  ADD(vec2d,b,$)\
  //===
  #include "defprovar.inl"
  //===
  t_line&set_a(vec2d na){a=na;return *this;}
  t_line&set_b(vec2d nb){b=nb;return *this;}
  t_line&set_a(real x,real y){a=vec2d(x,y);return *this;}
  t_line&set_b(real x,real y){b=vec2d(x,y);return *this;}
};

struct t_world{
  typedef t_obj t_actor;
  #define DEF_PRO_CLASSNAME()t_world
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_actor,actor,$)\
  ADD(vector<t_line>,lines,$)\
  ADD(real,r,32)\
  //===
  #include "defprovar.inl"
  //===
  void set(t_world&ref){*this=ref;}
  void set(t_world&ref,...){*this=ref;}
  void move_full(...){
    actor.move_full();
  }
  bool sim_step()
  {
    actor.move_full(*this);
    bool has_cd=false;
    for(int i=0;i<lines.size();i++){
      auto&ex=lines[i];auto&a=ex.a;auto&b=ex.b;
      has_cd=has_cd||FastCD_CircleAndWallWithCircles(actor.pos,actor.v,r,a,b);
    }
    return !has_cd;
  }
};

//#include "fast_obj.inl"

static real get_branch_diff_pos_dist(int steps_per_pranch){
  t_world src;
  src.actor.v=vec2d(max_speed,0);
  src.actor.pos=vec2d(0,0);
  auto a=t_world_raw_sim(src,vec2d(0,0),steps_per_pranch);
  auto b=t_world_raw_sim(src,vec2d(1,0),steps_per_pranch);
  return a.actor.pos.dist_to(b.actor.pos);
}

static const int map_max_size=40+0*140/2;
static const int steps_per_pranch=24;
static real get_block_size(){static real bs=int(get_branch_diff_pos_dist(steps_per_pranch)*sqrt(2.0));return bs;}//return max_speed*steps_per_pranch;}

struct t_map_info{
  #define DEF_PRO_CLASSNAME()t_map_info
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,map_offset,$)\
  ADD(int,scale,1)\
  ADD(real,inv_block_size,$)\
  ADD(real,block_size,$)\
  //===
  #include "defprovar.inl"
  //===
};

class t_map_of_ways{
public:
  typedef int t_elem;
public:
  #define DEF_PRO_CLASSNAME()t_map_of_ways
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_elem>,mem,$)\
  ADD(int,w,0)\
  ADD(int,h,0)\
  ADD(t_map_info,info,$)\
  //===
  #include "defprovar.inl"
  //===
public:
  static void set_to_def(t_elem&elem){elem=t_elem();}
  void fill(int value){for(int i=0;i<w*h;i++)mem[i]=value;}
  #include "t_map_getters.inl"
};

static int&get_maxn(){static int maxn=0;return maxn;}
static real get_min_ang_dist(){const int max_dirs=1024;return (Vec2dEx(Pi2/real(max_dirs),min_speed)-vec2d(min_speed,0)).Mag();}
static real get_min_pos_dist(){return get_branch_diff_pos_dist(steps_per_pranch)*0.75;}

static const int map_n=32;//ang
static const int map_z=16;//speed
template<class TYPE,size_t N>
void qap_move(std::array<TYPE,N>&dest,std::array<TYPE,N>&ref){
  for(int i=0;i<dest.size();i++)dest[i]=std::move(ref[i]);
}
struct t_portable_map{
  #define DEF_PRO_CLASSNAME()t_portable_map
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_world,world,$)\
  ADD(vec2d,cam_pos,$)\
  ADD(vec2d,cam_dir,vec2d(1,0))\
  ADD(bool,cam_rot,false)\
  ADD(bool,cam_offcentric,false)\
  ADD(bool,show_map,true)\
  ADD(real,scale,1)\
  ADD(bool,pause,true)\
  ADD(vec2d,target_point,$)\
  //---
  template<class TGame>
  void save_to(TGame&ref){
    #define ADD(TYPE,NAME,VALUE)ref.NAME=this->NAME;
    DEF_PRO_VARIABLE(ADD);
    #undef ADD
  }
  template<class TGame>
  void load_from(TGame&ref){
    #define ADD(TYPE,NAME,VALUE)this->NAME=ref.NAME;
    DEF_PRO_VARIABLE(ADD);
    #undef ADD
  }
  //===
  #include "defprovar.inl"
  //===
};

#include "big_vector.inl"

struct t_nodebasedfinder{
public:
  typedef t_nodebasedfinder NBF; typedef QapDev::t_geom t_geom;
public:
  struct t_childs;
  //struct t_childs_ptr{
  //  t_childs*ptr;
  //  t_childs_ptr():ptr(nullptr){}
  //  t_childs*build(){return ptr=new t_childs();}
  //  void operator=(t_childs_ptr&&ref){
  //    if(ptr)delete ptr;
  //    ptr=ref.ptr;
  //    ref.ptr=nullptr;
  //  }
  //  ~t_childs_ptr(){if(ptr)delete ptr;}
  //  t_childs*get(){return ptr;}
  //  t_childs*operator->(){return ptr;}
  //  t_childs&operator*(){return*ptr;}
  //};
  struct t_small_node;
  struct t_small_node_ptr{
    //#define DEF_PRO_UNSAVEABLE()
    #define DEF_PRO_CLASSNAME()t_small_node_ptr
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(size_t,data,-1)\
    //===
    #include "defprovar.inl"
    //===
    static const size_t bit_in_dir=4;
    static const size_t bit_in_id=sizeof(size_t)*8-bit_in_dir;
    static const size_t maximum_number_of_directions=1<<bit_in_dir;
    struct t_impl{
      size_t id: bit_in_id;
      size_t dir:bit_in_dir;
    };
    union t_conv{
      size_t v;
      t_impl impl;
    };
    static_assert(sizeof(t_impl)==4,"WTF?");
    //t_small_node*get(TGame*game)const{
    //  //t_conv tmp={-1};QapAssert(tmp.impl.dir==3);
    //  if(id==-1)return nullptr;
    //  t_conv c={id};
    //  return game->small_nodes[c.impl];
    //}
    t_impl&as_impl(){return (t_impl&)data;};
    void set(size_t id,size_t dir){
      t_impl impl={id,dir};
      t_conv tmp;tmp.impl=impl;
      data=tmp.v;
    }
    size_t get_gen()const{t_conv c={data};return c.impl.dir;}
    size_t get_id()const{t_conv c={data};return c.impl.id;}
    operator bool()const{return data!=-1;}
    void operator=(nullptr_t){data=-1;}
  };
  struct t_small_node{
    #define DEF_PRO_CLASSNAME()t_small_node
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_small_node_ptr,parent,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_small_nodes{
    static const size_t maximum_number_of_directions=3*3;
    #define DEF_PRO_CLASSNAME()t_small_nodes
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(big_vector<array(t_small_node,maximum_number_of_directions)>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
    t_small_node&operator[](t_small_node_ptr::t_impl p){
      QapAssert(p.dir<maximum_number_of_directions);
      return arr[p.id][p.dir];
    }
    t_small_node&operator[](t_small_node_ptr p){return (*this)[p.as_impl()];}
    //t_small_node*get(vector<vector<t_small_node>>&arr,int id){
    //  int seg=id/block;
    //  int off=id%block;
    //  QapAssert(qap_check_id(arr,seg));
    //  auto&s=arr[seg];
    //  QapAssert(qap_check_id(s,off));
    //  return &s[off];
    //}
    //int add(int dir){
    //  QapAssert(dir>=0&&dir<3);
    //  auto&arr=(&N)[dir];
    //  if(arr.empty())qap_add_back(arr).reserve(block);
    //  auto*pb=&arr.back();
    //  int id=(-1+int(arr.size()))*block+pb->size();
    //  if(pb->size()==block)pb=&qap_add_back(arr);
    //  qap_add_back(*pb);
    //  return id;
    //}
    void clear(){arr.clear();}
  };
  struct t_full_genome{
    #define DEF_PRO_COMPAREABLE()
    #define DEF_PRO_CLASSNAME()t_full_genome
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,id,-1)\
    ADD(vector<size_t>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  t_small_node&operator()(const t_small_node_ptr&ref){return small_nodes[ref];}
  vector<size_t> p2genome(t_small_node_ptr p,size_t n=1){
    return vector<size_t>(n,p.get_gen());
  };
  t_full_genome full_genome(t_small_node_ptr snp,int n=1){
    auto&deref=*this;
    auto*ptr=&deref(snp);
    t_full_genome result;auto&out=result.arr;
    out+=p2genome(snp,n);
    for(auto p=ptr->parent;p;p=ptr->parent){
      ptr=&deref(p);
      if(!ptr->parent){QapAssert(p.get_gen()==0);result.id=p.get_id();break;}
      auto buff=p2genome(p,n);
      out+=std::move(buff);
    }
    reverse(out);
    return result;
  }
  struct t_node{
    #define DEF_PRO_CLASSNAME()t_node
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_world,world,$)\
    ADD(t_small_node_ptr,self,$)\
    ADD(int,t,0)\
    ADD(bool,deaded,false)\
    //===
    #include "defprovar.inl"
    //===
    void childs_build_sim_and_grab_if_ok(NBF*nbf)
    {
      static const auto&id2wasd=get_id2wasd();
      auto&small_nodes=nbf->small_nodes;
      auto smid=nbf->small_nodes.arr.add();
      auto&arr=small_nodes.arr[smid];
      auto&out=nbf->nodes_out;
      for(size_t i=0;i<arr.size();i++){
        t_node tmp;
        tmp.world=world;
        tmp.t=t;
        tmp.self.set(smid,i);
        QapAssert(&small_nodes[tmp.self]==&arr[i]);
        arr[i].parent=self;// equal_to "nbf->small_nodes[tmp.self].parent=self;"
        tmp.world.actor.a=id2wasd[i];
        tmp.deaded=!sim_n_steps(nbf,&tmp,steps_per_pranch);
        if(tmp.deaded)continue;
        //tmp.world.update_dir();
        auto node_id=out.size();
        out.push_back(std::move(tmp));
        //nbf->fullreg(node_id);
      }
    }
    static const vector<vec2d>&get_id2wasd(){
      static vector<vec2d> arr;if(arr.size())return arr;
      for(int y=-1;y<=1;y++)for(int x=-1;x<=1;x++)qap_add_back(arr)=t_world::t_actor::wasd2a(vec2d(x,y));
      return arr;
    }
    static vector<vec2d> full_genome2linelist(NBF*nbf,t_full_genome&ref)
    {
      static const auto&id2wasd=get_id2wasd();
      auto cur=nbf->root.world;auto&genome=ref.arr;
      vector<vec2d> out;
      int giter=0;bool need_add_point=false;
      for(int i=0;i<genome.size();i++)
      {
        cur.actor.a=id2wasd[genome[i]];
        for(int iter=0;iter<steps_per_pranch;iter++)
        {
          cur.move_full();need_add_point=giter++%8!=0;if(!need_add_point){out.push_back(cur.actor.pos);}
        }
      }
      if(need_add_point)out.push_back(cur.actor.pos);
      out=lineloop2linelist(out);
      return out;
    }
    /*
    static vector<vec2d> full_path(NBF*nbf,t_small_node_ptr&ptr)
    {
      static const auto&id2wasd=get_id2wasd();
      vector<vec2d> out,genome;
      if(!sn.self)return out;
      auto&parent=nbf->small_nodes[self].parent;
      if(!parent)return out;
      qap_add_back(genome)=id2wasd[self.get_gen()];
      auto*root=parent;
      for(auto*p=root;p;p=p->parent){
        if(p->parent)qap_add_back(genome)=p->dir;
        root=p;
      }
      reverse(genome);
      auto cur=root->world;
      int giter=0;
      for(int i=0;i<genome.size();i++){
        cur.actor.a=cur.actor.wasd2a(genome[i]);
        for(int iter=0;iter<steps_per_pranch;iter++)
        {
          cur.actor.move_full();if(giter%8==0)out.push_back(cur.actor.pos);giter++;
        }
      }
      out.push_back(cur.actor.pos);
      out=lineloop2linelist(out);
      return out;
    }*/
    static vector<vec2d> lineloop2linelist(const vector<vec2d>&arr){
      vector<vec2d> out;
      for(int i=1;i<arr.size();i++){out.push_back(arr[i-1]);out.push_back(arr[i-0]);}
      return out;
    }
    /*
    vector<vec2d> get_points(){
      vector<vec2d> out;
      if(!parent)return out;
      out.push_back(world.actor.pos);
      out.push_back(parent->world.actor.pos);
      return out;
    }
    vector<vec2d> full_path_old(){
      vector<vec2d> out=get_points();
      for(auto*p=parent;p;p=p->parent){
        auto buff=p->get_points();
        out+=std::move(buff);
      }
      return out;
    }*/
  };
  /*struct t_childs{
    std::array<t_node,3*3> arr;
  };*/
  class t_map_of_pnode{
  public:
    typedef t_small_node_ptr t_elem;
  public:
    //#define DEF_PRO_CLASSNAME()t_map_of_pnode
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_elem>,mem,$)\
    ADD(int,w,0)\
    ADD(int,h,0)\
    ADD(t_map_info,info,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_map_of_pnode(){DoReset();}
    static void set_to_def(t_elem&elem){elem=nullptr;}
    void fill(){for(int i=0;i<w*h;i++)mem[i]=nullptr;}
    #include "t_map_getters.inl"
  };
  struct t_vec_updater{
    int pos;
    int step;
    bool enabled;
    t_vec_updater(){pos=0;step=128;enabled=false;}
  };
public:
#define NBF_VAR_LIST(ADD)\
  ADD(t_node,root,$)\
  ADD(big_vector<t_node>,nodes,$)\
  ADD(big_vector<t_node>,nodes_out,$)\
  ADD(vector<t_map_of_ways>,maps,$)\
  ADD(t_map_of_ways,map,$)\
  ADD(t_vec_updater,vec_updater,$)\
  ADD(vector<t_map_of_pnode>,pnodemaps,$)\
  ADD(vector<vector<t_point>>,id2vec,$)\
  ADD(int,wave_id,0)\
  ADD(t_small_nodes,small_nodes,$)\
//---
  #define F(TYPE,NAME,VALUE)TYPE NAME;
  NBF_VAR_LIST(F);
  #undef F
  void DoReset()
  {
    t_$ $;
    #define ADD(TYPE,NAME,VALUE)t_$::set(this->NAME,VALUE);
    NBF_VAR_LIST(ADD)
    #undef ADD
  }
  NBF(){DoReset();}
  #define USE_NBF_VAR(TYPE,NAME,VALUE)auto&NAME=nbf.NAME;
  #define USE_NBF()NBF_VAR_LIST(USE_NBF_VAR);typedef t_nodebasedfinder NBF;typedef NBF::t_node t_node;auto&lines=world.lines;auto&r=world.r;typedef NBF::t_small_node_ptr t_small_node_ptr;typedef NBF::t_node t_node;
//---
public:
  void inc_size(){
    QapAssert(maps.size()==pnodemaps.size());
    auto base=maps.size();
    int dv=map_n*map_z;
    maps.resize(base+dv);pnodemaps.resize(base+dv);
    for(int i=0;i<dv;i++){
      auto id=base+i;
      maps[id].init();
      maps[id].fill(-1);
      pnodemaps[id].init();
      pnodemaps[id].fill();
    }
  }
  int pnt2id(const vector<t_point>&arr){
    auto a=qap_find_val(id2vec,arr);
    if(a.size()==1)return a[0];
    int id=id2vec.size();
    id2vec.push_back(arr);
    inc_size();
    return id;
  }
  int get_map_id(const t_world&world){
    auto&obj=world.actor;
    auto&dir=obj.v;
    //int vecid=pnt2id(obj.points);
    int vecid=pnt2id(obj.points);//order
    static const real inv_divider=(map_z-1)*1.0/(max_speed-min_speed);
    auto z=int((dir.Mag()-min_speed)*inv_divider)%map_z;//speed
    auto id=int((PiD4+Pi2+dir.GetAng())*map_n/Pi2)%map_n;//ang
    return id+z*map_n+vecid*map_n*map_z;
  }
  t_map_of_pnode&get_pnodemaps(const t_world&world){
    auto id=get_map_id(world);
    if(!qap_check_id(maps,id)){
      int gg=1;
    }
    return pnodemaps[id];
  }
  t_map_of_ways&get_map(const t_world&world){
    auto id=get_map_id(world);
    if(!qap_check_id(maps,id)){
      int gg=1;
    }
    return maps[id];
  }
  //CHECK BEFORE CALL:    if(!kb.OnDown(VK_F3)&&pause)return;
  void update_nodes(bool fast_node_draw,int steps,int ds=4)
  {
    static const int gaptime=1+(get_block_size()*sqrt(2.0)/max_speed);
    const int max_dirs=1024;
    const real min_ang_dist=(Vec2dEx(Pi2/real(max_dirs),max_speed)-vec2d(max_speed,0)).Mag();
    static const real min_pos_dist=get_branch_diff_pos_dist(steps_per_pranch)*0.75;
    auto&vu=vec_updater;vu.step=steps;
    if(!vu.enabled)return;
    auto&arr=nodes;
    vector<t_node*> out;
    auto arr_size=arr.size();
    auto limit=std::min<int>(vu.pos+vu.step,arr_size);
    for(int&i=vu.pos;i<limit;i++)
    {
      auto&ex=arr[i];
      if(ex.deaded){
        limit=std::min<int>(limit+1,arr_size);
        continue;
      }
      auto&map=get_map(ex.world);
      auto&ct=map.get(map.world_to_cell(ex.world.actor.pos));
      if(ct>=0&&ct+gaptime<=ex.t)continue;
      ex.childs_build_sim_and_grab_if_ok(this);
    }
    if(vu.pos>=arr.size()){
      nodes=std::move(nodes_out);vu.enabled=false;
      //old_tree=std::move(tree);QapDoReset(tree);
    }
  }
  template<class TYPE>static void QapDoReset(TYPE&ref){ref.~TYPE();new(&ref)TYPE();}
  t_geom tree,old_tree;
  static bool sim_n_steps(NBF*nbf,t_node*node,int max_iter){
    auto&world=node->world;
    bool fail=false;
    for(int iter=0;iter<max_iter;iter++)
    {
      fail=fail||!world.sim_step();
      if(fail)break;
      node->t++;
      //auto&map=nbf->map;
      auto&map=nbf->get_map(world);
      auto cc=tovec2i(map.world_to_cell(world.actor.pos));
      //if(cc==oc)continue;
      auto&ct=map.get(cc);
      {auto&ct=nbf->map.get(cc);if(ct<0||ct>node->t)ct=node->t;}
      if(ct>=0&&ct<node->t)continue;
      ct=node->t;//ct<0?node->t:std::min(node->t,ct);
      nbf->get_pnodemaps(world).get(cc)=node->self;
    }
    return !fail;
  }
  // wave_id == 14; 5053 ms; after 153 ms; 95x speed up
  //struct t_point{vec2d pos;};
  struct t_vec_of_points{
    vector<t_point> arr;
    vector<int> arrid2nodeid;
    void add(const vec2d&pos,int id){
      qap_add_back(arr).pos=pos;
      qap_add_back(arrid2nodeid)=id;
    }
  };
  void try_do_wave(t_perf_sys&sys)
  {
    if(vec_updater.enabled)return;
    if(nodes.size()){wave_id++;}else return;
    t_clock clock(sys,"try_do_wave");
    vec_updater.pos=0;
    vec_updater.enabled=true;
    if(bool need_wave_cd_cleaner=true)
    {
      if(nodes.size()==1){get_map_id(nodes[0].world);}
      vector<t_vec_of_points> np_vecs;np_vecs.resize(maps.size());
      {
        t_clock clock(sys,"nbf::tdw::prepare");
        for(int i=0;i<nodes.size();i++){
          auto&ex=nodes[i];
          if(ex.deaded)continue;
          np_vecs[get_map_id(ex.world)].add(ex.world.actor.pos,i);
        }
      }
      static const real min_ang_dist=get_min_ang_dist();
      static const real min_pos_dist=get_min_pos_dist();
      static int&maxn=get_maxn();int n=0;
      //t_perf_sys sys;
      for(int id=0;id<np_vecs.size();id++)
      {
        auto&rec=np_vecs[id];
        auto&nodepoints=rec.arr;
        auto&f=rec.arrid2nodeid;
        vector<t_cd_pair> cd_arr;
        t_cd_dev<t_point> cd_dev(sys,cd_arr,nodepoints,min_pos_dist*0.5);
        cd_dev.cd_grid_fast(4);
        cd_dev.cd_out();
        {
          //t_clock clock(sys,"wcd_clean");
          for(int i=0;i<cd_arr.size();i++)
          {
            auto&ex=cd_arr[i];
            auto&A=nodes[f[ex.a]];
            auto&B=nodes[f[ex.b]];
            if(A.deaded||B.deaded)continue;
            if(A.t!=B.t)continue;
            auto&a=A.world.actor;
            auto&b=B.world.actor;
            if(a.points!=b.points)continue;
            if(!a.v.dist_to_point_less_that_r(b.v,min_ang_dist))continue;
            B.deaded=true;n++;
          }
        }
      }
      //qap_clean_if_deaded(nodes);
      maxn=std::max<int>(maxn,n);
    }
  }
#if(0)
  void try_do_wave_old(t_perf_sys&sys)
  {
    if(vec_updater.enabled)return;
    t_clock clock(sys,"try_do_wave");
    wave_id++;
    vec_updater.pos=0;
    vec_updater.enabled=true;
    //points.clear();
    //old_tree=std::move(tree);
    //tree=t_geom();
    if(bool need_wave_cd_cleaner=true)
    {
      //t_clock clock(sys,"wave_cd_cleaner");
      struct t_point{vec2d pos;};
      vector<t_cd_pair> cd_arr;
      vector<t_point> nodepoints;
      {
        //t_clock clock(sys,"wcd_grab");
        for(int i=0;i<nodes.size();i++){
          auto*p=nodes[i];
          qap_add_back(nodepoints).pos=p->obj.pos;
        }
      }
      static const real min_ang_dist=get_min_ang_dist();
      static const real min_pos_dist=get_min_pos_dist();
      //t_perf_sys sys;
      t_cd_dev<t_point> cd_dev(sys,cd_arr,nodepoints,min_pos_dist*0.5);
      cd_dev.cd_grid_fast(4);
      cd_dev.cd_out();
      static int&maxn=get_maxn();int n=0;
      {
        //t_clock clock(sys,"wcd_clean");
        for(int i=0;i<cd_arr.size();i++)
        {
          auto&ex=cd_arr[i];
          auto&A=nodes[ex.a];
          auto&B=nodes[ex.b];
          if(!A||!B)continue;
          if(A->t!=B->t)continue;
          auto&a=A->obj;
          auto&b=B->obj;
          if(a.points!=b.points)continue;
          if(!a.v.dist_to_point_less_that_r(b.v,min_ang_dist))continue;
          B=nullptr;n++;
        }
        QapCleanIf(nodes,[](t_node*&p){return !p;});
      }
      maxn=std::max<int>(maxn,n);
    }
  }
#endif
};

class TGame:public TQapGameV2{
public:
  t_world world;
  vec2d cam_pos;
  real scale;
  bool end;
  bool show_way;
  //vector<vec2d> points;
  //t_geom old_tree;
  int depth;
  vec2d sp;
  real ds;
  bool pause;
  vec2d target_point;
  vec2d cam_dir;
  bool show_dir_way;
  bool show_map;
  bool fast_node_draw;
  bool cam_rot;
  bool cam_offcentric;
  bool endable;
  int total_nodes;
  int layer_id;
public:
  TGame()
  {
    USE_NBF();
    layer_id=1;
    total_nodes=0;
    endable=true;
    cam_dir=vec2d(1,0);
    fast_node_draw=false;
    cam_rot=false;
    cam_offcentric=false;
    show_map=true;
    show_dir_way=false;
    pause=true;
    ds=4;
    depth=512;
    show_way=false;
    end=false;
    scale=1.0;
    //obj.pos=vec2d(-150,+50);
    world.actor.v=vec2d(0.00,-max_speed).Ort();
    //a=vec2d(-200,-50);
    //b=vec2d(+200,+100);
    srand(time(0));
    real W=750*2;
    real H=W;
    qap_add_back(lines).set_a(-W,-H).set_b(+W,-H);
    qap_add_back(lines).set_a(-W,+H).set_b(+W,+H);
    qap_add_back(lines).set_a(-W,-H).set_b(-W,+H);
    qap_add_back(lines).set_a(+W,-H).set_b(+W,+H);
    for(int i=0;i<100;i++)
    {
      vec2d center=rndvec2d(-1,+1)*1200;
      vec2d dv=Vec2dEx(rndreal(0,Pi2),rndreal(50,150));
      auto&ex=qap_add_back(lines);
      ex.a=center+dv;
      ex.b=center-dv;
    }
    end=true;show_way=false;
    real bs=get_block_size();
    maps.resize(map_n*map_z);pnodemaps.resize(map_n*map_z);/*
    for(int i=0;i<maps.size();i++){
      maps[i].init();
      pnodemaps[i].init();
    }*/
    map.init();
    food_points_reset();
    maps_reset();
  }
  void food_points_reset()
  {
    world.actor.v=vec2d(max_speed,0);
    //srand(0*time(0));
    real hw=1366/2;
    real hh=768/2;
    int n=5;
    real d=sqrt(hw*hh*4/real(n));
    int w=2*hw/d;
    auto&points=world.actor.points;
    points.clear();
    for(int i=0;i<n;i++){
      qap_add_back(points).pos=0||rand()%5==0?(vec2d(i%int(w),i/int(w))*d-vec2d(hw,hh))*0.8:rndvec2d(-1,1).Mul(vec2d(hw,hh))*0.8;
    }
  }
  void maps_reset(bool ignore_ctrl=false)
  {
    USE_NBF();
    if(!ignore_ctrl)if(kb.Down(VK_CONTROL))food_points_reset();
    total_nodes=0;
    nodes.clear();nodes_out.clear();
    maps.clear();pnodemaps.clear();nbf.id2vec.clear();nbf.wave_id=0;
    /*for(int i=0;i<maps.size();i++){
      maps[i].fill(-1);pnodemaps[i].fill();
    }*/
    map.fill(-1);
    root=std::move(t_node());
    root.self=nullptr;
    root.world.set(world,nbf);
    root.t=0;
    root.deaded=false;
    auto&rn=qap_add_back(nodes);
    rn=root;
    small_nodes.clear();
    rn.self.set(small_nodes.arr.add(),0);
  }
public:
  vec2d s2w(const vec2d&pos)
  {
    bool offcentric=false; auto cam_dir=vec2d(1,0);
    return t_offcentric_scope::screen_to_world(viewport,pos,cam_pos+world.actor.pos,cam_dir,scale,offcentric);
  }
  static string get_map_fn(){return "v5.map.bin";}
  void DoPreMove()
  {
    USE_NBF();
    if(kb.Down[VK_ESCAPE])win.Close();
    if(kb.Down('R'))end=false;
    if(kb.OnDown('T'))cam_offcentric=!cam_offcentric;
    if(kb.Down('Z'))cam_dir=vec2d(1,0);
    if(cam_rot)
    {
      auto k=(1.0+(45-10)/75.0);
      real da=0;
      if(kb.Down('Q'))da=-1;
      if(kb.Down('E'))da=+1;
      cam_dir=Vec2dEx(cam_dir.GetAng()+k*(da*Pi/75.0),1);
    }
    if(kb("CTRL+H")){
      t_portable_map map;map.load_from(*this);
      file_put_contents(get_map_fn(),QapSaveToStrWithSizeOfType(map));return;
    }
    if((!kb.Down(VK_SHIFT))&&kb("CTRL+L")){
      t_portable_map map;
      QapLoadFromStrWithSizeOfType(map,file_get_contents(get_map_fn()));
      map.save_to(*this);
      maps_reset(true);
    }
    if(kb.OnDown(VK_F11))cam_rot=!cam_rot;
    if(kb.OnDown(VK_F6)){lines.clear();if(kb.Down(VK_CONTROL))world.actor.points.clear();}
    if(kb.Down(VK_ADD))scale*=1.01;
    if(kb.Down(VK_SUBTRACT))scale/=1.01;
    if(kb.Down(VK_DIVIDE))scale=1;
    if(kb.OnDown(VK_MULTIPLY))scale*=0.5;
    if(kb.OnDown(VK_SPACE))end=!end;
    if(kb.OnDown('I'))show_way=!show_way;
    if(kb.OnDown(mbRight))sp=s2w(mpos);
    if(kb.Down(mbLeft)||kb.Down(VK_SHIFT))target_point=map.map_to_world(tovec2i(map.world_to_cell(s2w(mpos))));
    if(kb.OnUp(mbRight)){
      bool flag=kb.Down(VK_CONTROL);
      if(!flag)qap_add_back(lines).set_a(s2w(mpos)).set_b(sp);
      if(flag)qap_add_back(world.actor.points).pos=s2w(mpos);
    }
    if(kb.OnDown(VK_F4))show_dir_way=!show_dir_way;
    if(kb.OnDown(VK_F7))show_map=!show_map;
    if(kb.OnDown(VK_F12))fast_node_draw=!fast_node_draw;
    if(kb.OnDown(VK_F10))endable=!endable;
    if(!endable)end=false;
    if(end){cam_pos+=kb.get_dir_from_wasd_and_arrows()*(5.0/scale);}else{cam_pos=vec2d_zero;}
    if(!end||kb.OnDown(VK_RIGHT))
    {
      world.actor.a=world.actor.wasd2a(kb.get_dir_from_wasd_and_arrows());
      for(int i=0;i<2;i++)
      {
        end=!world.sim_step();
      }
    }
    {
      auto&var=kb.Down(VK_CONTROL)?layer_id:depth;
      if(kb.OnDown(VK_F1))var++;
      if(kb.OnDown(VK_F2))var--;
      for(int numkey='0';numkey<='9';numkey++)if(kb.OnDown(numkey))var=numkey-'0';
    }
    if(kb.OnDown(VK_F5))
    {
      maps_reset();
    }
    if(kb.OnDown(VK_F3)||!pause)
    {
      t_clock clock(sys,"update_nodes");
      nbf.update_nodes(fast_node_draw,depth,ds);
    }
    if(kb.OnDown(VK_F9))pause=!pause;
    if(kb.OnDown(VK_F3)||!pause)
    {
      nbf.try_do_wave(sys);
    }
    sys.next();
    //if(kb.Down(mbRight)){map.get(map.world_to_cell(s2w(mpos)))=128;}
    //end=false;
  }
  t_nodebasedfinder nbf;
  #include "draw_map.inl"
  void DoPreDraw()
  {
    USE_NBF();auto&obj=world.actor;
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    {
      t_offcentric_scope scope(qDev,obj.pos+cam_pos,cam_rot?cam_dir.Rot(-obj.v.Ort()).Norm():cam_dir,scale,cam_offcentric);
      draw_map();
      for(int i=0;i<lines.size();i++){
        auto&ex=lines[i];auto&a=ex.a;auto&b=ex.b;
        qDev.SetColor(0xff505050);
        qDev.DrawLine(a,b,ds);
        qDev.SetColor(0xff505050);
        qDev.DrawSolidCircle(a,4,16,0);
        qDev.DrawSolidCircle(b,4,16,0);
      }
      for(int i=0;i<obj.points.size();i++){
        auto&ex=obj.points[i];
        qDev.SetColor(0x20508850);
        qDev.DrawSolidCircle(ex.pos,r,16,0);
        qDev.SetColor(0x2050aa50);
        qDev.DrawSolidCircle(ex.pos,r-2,16,0);
        qDev.SetColor(0xff000000);
        qDev.DrawSolidCircle(ex.pos,6,16,0);
        qDev.SetColor(0xff808080);
        qDev.DrawSolidCircle(ex.pos,4,16,0);
      }
      qDev.SetColor(0x80000000);
      if(show_way)
      {
        int iter=64;real k=1.5;//-mpos.x/100.0;
        //qDev.SetColor(0x80FF0000);sim_line("ASA"/*"NSN"*/,iter,k*PiD2,1.0);
        //qDev.SetColor(0x80FFFF00);sim_line("SA"/*"NSN"*/,iter,k*PiD2,1.0,vec2d(mpos).GetAng());
        //qDev.SetColor(0x80008F00);sim_line("SNSNSNSNSNSNSNSNSNSNSNSN"/*"NSN"*/,iter,k*PiD2,1.0,-vec2d(mpos).GetAng());
        //qDev.SetColor(0x800000FF);sim_line("NAN"/*"SAS"*/,iter,k*PiD2,1.0);
        qDev.SetColor(0x80000070);
        qDev.DrawGeomWithOffset(nbf.old_tree,vec2d_zero);
        qDev.SetColor(0x80000000);
        qDev.DrawGeomWithOffset(nbf.tree,vec2d_zero);
        //if(0)qDev.DrawLineList(points,ds);
        //auto q=qDev.GenGeomQuad(vec2d(0,0),ds,ds);
        //t_quad sq;sq.size=win.GetClientSize();
        //for(int i=0;i<points.size();i++){if(point_in_quad(sq,qDev.xf*points[i]))qDev.DrawGeomWithOffset(q,points[i]);}
      }
      qDev.SetColor(0xffbbbbbb);
      qDev.DrawSolidCircle(obj.pos,r,32,0);
      qDev.SetColor(0xff404040);
      qDev.DrawCircle(obj.pos,r,0,ds,32);
      qDev.DrawLine(obj.pos,obj.pos+obj.v*(r/max_speed),4);
      qDev.SetColor(0xffff4040);
      if(obj.a!=vec2d_zero)qDev.DrawLine(obj.pos,obj.pos+obj.a.SetMag(20).UnRot(-obj.v.Ort()),2);
      if(end){qDev.SetColor(0xff000000);qap_text_draw_at_x_center(qDev,obj.pos,"end",16);}
    }
    DrawDownedKeys();
    int y=0;int dy=16;
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"depth = "+IToS(depth),16);
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"nodes = "+IToS(nodes.size()),16);
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"total_nodes = "+IToS(total_nodes),16);
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"wave_id = "+IToS(wave_id),16);
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"vu.pos = "+FToS(nbf.vec_updater.pos*100.0/nodes.size()),16);
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"leayers_n = "+IToS(nbf.id2vec.size()),16);
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"leayer = "+(qap_check_id(nbf.id2vec,layer_id-1)?VToS(nbf.id2vec[layer_id-1]):"...error..."),16);
    
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y-=dy),"leayer_id = "+IToS(layer_id-1),16);
    perf_text_out(y); 
  }
  t_perf_sys sys;
  string VToS(const vector<t_point>&arr){
    vector<string> out;for(int i=0;i<arr.size();i++){auto&ex=arr[i];out.push_back("["+FToS(ex.pos.x)+","+FToS(ex.pos.y)+"]");}return join(out,",");
  }
  static string BToS(bool b){return b?"true":"false";}
  void perf_text_out(int y)
  {
    auto&perf_sys=sys;
    int textsize=16; int dy=-textsize*1;
    vec2i p(-win.GetClientSize().x/2+16,win.GetClientSize().y/2+y);p.y+=dy;
    #define F(MSG)qap_text::draw(qDev,p.x,p.y,MSG,textsize);p.y+=dy;
    F("---perf---");
    for(int pass_id=0;pass_id<2;pass_id++)
    for(int i=0;i<perf_sys.old.size();i++)
    {
      auto&ex=perf_sys.old[i];
      if(0==pass_id)if(ex.old)continue;
      if(1==pass_id)if(!ex.old)continue;
      qDev.color.a=ex.old?0x80:0xff;
      if(ex.n>1)
      {
        F(ex.name+" = "+FToS(ex.ms)+"/"+IToS(ex.n));
      }else{
        if(ex.name=="cd_num"){
          F(ex.name+" = "+IToS(int(ex.ms)));
        }else{
          F(ex.name+" = "+FToS(ex.ms)+" ms");
        }
      }
    }
    #undef F
  }
};
static const auto tnodesie=sizeof(t_nodebasedfinder::t_node);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}
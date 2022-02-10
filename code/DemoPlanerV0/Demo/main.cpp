#include "QapLite.h"
#include "TQapGameV2.inl"
#include "CD_Crap.inl"
#include "perf_sys.inl"
#include "genetic_algorithm.inl"
#include "ImgLoader.h"
#include <io.h>
#define QapCheckId(arr,id)
//#define QapCheckId(arr,id){QapAssert(qap_check_id(arr,id));}

//#include "qap_pool.inl"
#define IF_WITH_PNODEMAP(CODE)if(pnode_allowed){CODE;}
struct t_config{
  #define DEF_PRO_CLASSNAME()t_config
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(real,max_speed,3)\
  ADD(real,block_size_k,1)\
  ADD(real,min_pos_dist_k,1)\
  ADD(int,steps_per_branch,14)\
  ADD(int,seed,0)\
  ADD(int,loops_per_max_dirs,3)\
  ADD(int,max_dirs,1024)\
  ADD(int,map_n,64)\
  ADD(real,map_size,64)\
  ADD(int,cd_grid_n,4)\
  ADD(real,r,32)\
  ADD(real,pixmapscale,1)\
  ADD(real,wavemapscale,1)\
  ADD(real,scale,-1)\
  ADD(bool,auto_next_pos,false)\
  ADD(bool,frozen_allowed,false)\
  ADD(bool,pnode_allowed,true)\
  ADD(int,rndline_n,100)\
  ADD(real,rndline_pos_var,1200)\
  ADD(real,rndline_min_len,50)\
  ADD(real,rndline_max_len,150)\
  ADD(real,steps_per_update,2)\
  ADD(real,line_size,-1)\
  //---
  static string tostr(bool b){return b?"true":"false";}
  static string tostr(real v){char c[64];_snprintf_s(c,32,32,"%lf",v);return string(c);}
  static string tostr(int v){return IToS(v);}
  string escape(const string&s){auto&f=StrReplace;return f(f(f(f(s,"*-","*`"),"/-","/`"),"/+","/"),"*+","*");}
  string unescape(const string&s){return StrReplace(s,"`","-");}
  #define RET_LINE(real,SToF,OPER,fromstr_LD,fromstr_LN)real fromstr_LD(const string&s,const real&ref){\
    if(s.empty())return 0;\
    auto a=split(s,#OPER);real v=fromstr_LN(a[0],ref);for(int i=1;i<a.size();i++)(v)OPER##=fromstr_LN(a[i],ref);return v;\
  }
  #define EXPR_FROM_STR(real,SToF)\
  real fromstr_LN(const string&s,const real&ref){return s.empty()?0:SToF(unescape(s));}\
  RET_LINE(real,SToF,/,fromstr_LD,fromstr_LN);\
  RET_LINE(real,SToF,*,fromstr_LM,fromstr_LD);\
  RET_LINE(real,SToF,-,fromstr_LS,fromstr_LM);\
  RET_LINE(real,SToF,+,fromstr_LA,fromstr_LS);\
  void fromstr(real&ref,const string&s){ref=fromstr_LA(escape(s),ref);}
  //---
  EXPR_FROM_STR(double,SToF);
  EXPR_FROM_STR(int,SToI);
  #undef EXPR_FROM_STR
  #undef RET_LINE
  //void fromstr(int&ref,const string&s){ref=SToI(s);}
  void fromstr(bool&ref,const string&s){ref=(s=="1")||(s=="true");}
  void save(){
    vector<string> arr;
    #define ADD(TYPE,NAME,VALUE)qap_add_back(arr)=#NAME" = "+tostr(this->NAME);
    DEF_PRO_VARIABLE(ADD);
    #undef ADD
    file_put_contents(get_fn(),join(arr,"\n"));
  }
  static string get_fn(){return "game_config.txt";}
  void load(){
    auto content=file_get_contents(get_fn());
    if(content.empty()){save();return;}
    auto s=StrReplace(content,"\r","");s=StrReplace(content,"\t"," ");s=StrReplace(content,"  "," ");
    auto arr=split(s,"\n");
    int n=0;int max_n=0;;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];auto name=get_first_part(ex," = ");
      max_n=0;
      #define ADD(TYPE,NAME,VALUE)max_n++;if(name==#NAME){fromstr(this->NAME,(get_second_part(ex," = ")));n++;}
      DEF_PRO_VARIABLE(ADD);
      #undef ADD
    }
    if(n!=max_n)save();
  }
  //===
  #include "defprovar.inl"
  //===
  static t_config&get(){static t_config config;static bool need_load=true;if(need_load){config.load();need_load=false;}return config;}
};
const static bool pnode_allowed=t_config::get().pnode_allowed;

const real max_speed=t_config::get().max_speed;
//const real rot_speed=t_config::get().rot_speed;
//const real min_speed=1.0;

static const uint loops_per_max_dirs=t_config::get().loops_per_max_dirs;
static const uint max_dirs=t_config::get().max_dirs;

struct t_obj{
  #define DEF_PRO_CLASSNAME()t_obj
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,pos,$)\
  ADD(vec2d,v,$)\
  ADD(int,dir,0)\
  ADD(int,a,0)\
  //===
  #include "defprovar.inl"
  //===
  //t_obj&set_v(const vec2d&ref){v=ref;return *this;}
  bool is_v_changed()const{return a;}
  static vector<vec2d>&get(){
    static vector<vec2d> dirs;
    if(dirs.empty())for(int i=0;i<max_dirs;i++)qap_add_back(dirs)=Vec2dEx(Pi2*i*loops_per_max_dirs/max_dirs,max_speed);
    return dirs;
  }
  const vec2d&get_v()const{return v;}
  static const vec2d&dir2v(size_t dir){static vec2d*arr=&get()[0];return arr[dir%max_dirs];}
  static bool is_same_dir(int a,int b){return (uint(a)%max_dirs)==(uint(b)%max_dirs);}
  void update_dir(){dir=uint(dir)%max_dirs;}
  void apply_input()
  {
    //auto old_v=v;
    //v+=a;
    //if(v.Mag()>max_speed)v=v.SetMag(max_speed);
    //if(v.Mag()<min_speed)v=v.SetMag(min_speed);
    dir-=a;v=dir2v(dir);
    //if(a.x)v=Vec2dEx(v.GetAng()-a.x*Pi2*rot_speed,max_speed);
  }
  void move()
  {
    apply_input();
    pos+=v;
    //a=vec2d_zero;
  }
  vec2d wasd2a(const vec2d&wasd){
    return wasd;//wasd.SetMag(0.05).Ort().UnRot(-v);
  }
  static t_obj raw_sim(const t_obj&src,int cmd,int max_iter)
  {
    auto cur=src;
    for(int iter=0;iter<max_iter;iter++)
    {
      cur.a=cmd;
      cur.move();
    }
    return cur;
  }
};

//#include "cd_dev.inl"

static real get_branch_diff_pos_dist(int steps_per_branch){
  QapDebugMsg("No way! 2016.08.25 12:36");
  t_obj src;
  src.dir=0;//vec2d(max_speed,0);
  src.pos=vec2d(0,0);
  auto a=t_obj::raw_sim(src,0,steps_per_branch);
  auto b=t_obj::raw_sim(src,1,steps_per_branch);
  return a.pos.dist_to(b.pos);
}

static const int map_max_size=t_config::get().map_size;
static const int steps_per_branch=t_config::get().steps_per_branch;
static real get_block_size(){static real bs=max_speed*steps_per_branch*t_config::get().block_size_k/**sqrt(2.0)*/;return bs;}//return max_speed*steps_per_branch;}

struct t_map_info{
  #define DEF_PRO_CLASSNAME()t_map_info
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,map_offset,$)\
  ADD(real,scale,1)\
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
public:
  struct rgba{unsigned char r,g,b,a;};
  template<class CONV>
  void tofile_with_conv(const string&fn,CONV conv=CONV())
  {
    static TLoaderEnv Env;
    {
      ImgLoader::TextureMemory mem;
      Env.InitMemory(mem,w,h);
      rgba*ptr=(rgba*)mem.ptr;
      conv(*this);
      for(int i=0;i<w*h;i++){
        ptr[i]=conv(this->mem[i]);
      }
      Env.SaveTextureToFile(mem,fn);
      Env.FreeMemory(mem);
    }
  }
  void tofile(const string&fn){tofile_with_conv<t_conv_v000>(fn);}
  struct t_conv_v000{
    #define DEF_PRO_CLASSNAME()t_conv_v000
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,prevmin,-1)\
    ADD(int,prevmax,-1)\
    ADD(real,prevsum,0)\
    ADD(real,prevn,0)\
    ADD(real,prevr,0)\
    ADD(real,prevdiffsum,0)\
    //===
    #include "defprovar.inl"
    //===
    rgba operator()(int v)
    {
      if(v<0){rgba out={0,0,0,255};return out;}
      rgba out={255-v,255-v/4,255-v/256,255};return out;
    }
    void operator()(t_map_of_ways&ref){}
  };
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

struct t_snapshot{
  #define DEF_PRO_CLASSNAME()t_snapshot
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_obj,obj,$)\
  ADD(t_map_of_ways,map,$)\
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

struct t_portable_map{
  #define DEF_PRO_CLASSNAME()t_portable_map
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_line>,lines,$)\
  ADD(t_obj,obj,$)\
  ADD(vec2d,cam_pos,$)\
  ADD(vec2d,cam_dir,vec2d(1,0))\
  ADD(bool,cam_rot,false)\
  ADD(bool,cam_offcentric,false)\
  ADD(bool,show_map,true)\
  ADD(real,scale,1)\
  ADD(bool,pause,true)\
  ADD(vec2d,target_point,$)\
  ADD(int,pos_id,0)\
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

struct t_old_portable_map{
  #define DEF_PRO_CLASSNAME()t_old_portable_map
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_line>,lines,$)\
  ADD(vec2d,obj_pos,$)\
  ADD(vec2d,obj_v,$)\
  ADD(vec2d,obj_cmd,$)\
  ADD(vec2d,cam_pos,$)\
  ADD(vec2d,cam_dir,vec2d(1,0))\
  ADD(bool,cam_rot,false)\
  ADD(bool,cam_offcentric,false)\
  ADD(bool,show_map,true)\
  ADD(real,scale,1)\
  ADD(bool,pause,true)\
  ADD(vec2d,target_point,$)\
  ADD(int,pos_id,0)\
  //===
  #include "defprovar.inl"
  //===
  template<class TGame>
  void save_to(TGame&ref){
    #define ADD(TYPE,NAME,VALUE)ref.NAME=this->NAME;
    ADD(vector<t_line>,lines,$)
    ADD(vec2d,cam_pos,$)
    ADD(vec2d,cam_dir,vec2d(1,0))
    ADD(bool,cam_rot,false)
    ADD(bool,cam_offcentric,false)
    ADD(bool,show_map,true)
    ADD(real,scale,1)
    ADD(bool,pause,true)
    ADD(vec2d,target_point,$)
    ADD(int,pos_id,0)
    #undef ADD
    {
      auto&arr=t_obj::get();
      ref.obj.pos=obj_pos;
      auto ov=obj_v;
      ref.obj.dir=QAP_MINVAL_ID_OF_VEC(arr,ex.dist_to(ov));
      ref.obj.a=0;
    } 
  }
};

template<class TYPE,size_t block=(1024*1024*4)/sizeof(TYPE)>
struct big_vector{
  #define DEF_PRO_CLASSNAME()big_vector
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<vector<TYPE>>,arr,$)\
  //===
  #include "defprovar.inl"
  //===
  TYPE&operator[](size_t id){
    auto seg=id/block;
    auto off=id%block;
    QapCheckId(arr,seg);
    auto&sub=arr[seg];
    QapCheckId(sub,off);
    return sub[off];
  };
  const TYPE&operator[](size_t id)const{
    auto seg=id/block;
    auto off=id%block;
    QapCheckId(arr,seg);
    auto&sub=arr[seg];
    QapCheckId(sub,off);
    return s[off];
  };
  int add(){
    if(arr.empty())qap_add_back(arr).reserve(block);
    auto*pb=&arr.back();
    int id=-block+arr.size()*block+pb->size();
    if(pb->size()==block){pb=&qap_add_back(arr);pb->reserve(block);}
    qap_add_back(*pb);
    return id;
  }
  void push_back(TYPE&&ref){
    if(arr.empty())qap_add_back(arr).reserve(block);
    auto*pb=&arr.back();
    if(pb->size()==block){pb=&qap_add_back(arr);pb->reserve(block);}
    pb->push_back(std::move(ref));
  }
  void clear(){arr.clear();}
  TYPE&back(){return arr.back().back();}
  const TYPE&back()const{return arr.back().back();}
  size_t size()const{return arr.empty()?0:-block+arr.size()*block+arr.back().size();}
  void resize(size_t new_size){
    QapAssert(new_size<size());
    auto seg=new_size/block;
    auto off=new_size%block;
    arr.resize(seg+1);
    for(int i=0;i+1<seg;i++){
      arr[i].resize(block);
    }
    if(seg||off){auto&b=arr.back();b.reserve(block);b.resize(off);}
  }
  static friend void operator+=(big_vector<TYPE>&arr,vector<TYPE>&&ref)
  {
    //arr.reserve(arr.size()+ref.size());
    for(int i=0;i<ref.size();i++)
    {
      arr.push_back(std::move(ref[i]));
    }
    ref.clear();
  }
};

template<class TYPE>static TYPE&qap_add_back(big_vector<TYPE>&arr){arr.add();return arr.back();}

class TGame:public TQapGameV2{
public:
  struct t_small_node;
  //struct t_childs;
  //struct t_small_childs;
  //typedef QapPoolPtr<t_childs,1024*64> t_childs_ptr;
  //typedef QapPoolPtr<t_small_childs> t_small_childs_ptr;
  struct t_node_points{
    //#define DEF_PRO_UNSAVEABLE()
    #define DEF_PRO_CLASSNAME()t_node_points
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec2d,beg,$)\
    ADD(vec2d,end,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  //struct moe{char a;int b;};struct hue{int a;int b;};
  //static_assert(sizeof(hue)==sizeof(moe),"WUT?");
  struct t_small_node_ptr{
    //#define DEF_PRO_UNSAVEABLE()
    #define DEF_PRO_CLASSNAME()t_small_node_ptr
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,id,-1)\
    //===
    #include "defprovar.inl"
    //===
    struct t_impl{
      unsigned id:32-2;
      unsigned dir:2;
    };
    union t_conv{
      int v;
      t_impl impl;
    };
    static_assert(sizeof(t_impl)==4,"WTF?");
    t_small_node*get(TGame*game)const{
      //t_conv tmp={-1};QapAssert(tmp.impl.dir==3);
      if(id==-1)return nullptr;
      t_conv c={id};
      return game->small_nodes[c.impl];
    }
    char get_gen()const{t_conv c={id};return c.impl.dir;}
    int get_id()const{t_conv c={id};return c.impl.id;}
    operator bool()const{return id!=-1;}
    void operator=(nullptr_t){id=-1;}
  };
  t_small_node*operator()(const t_small_node_ptr&ref){return ref.get(this);}
  vector<char> p2genome(t_small_node_ptr p,int n=1){
    return vector<char>(n,p.get_gen());
  };
  struct t_full_genome{
    #define DEF_PRO_COMPAREABLE()
    #define DEF_PRO_CLASSNAME()t_full_genome
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,id,-1)\
    ADD(vector<char>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  t_full_genome full_genome(t_small_node_ptr snp,int n=1){
    auto&deref=*this;
    auto*ptr=deref(snp);
    t_full_genome result;auto&out=result.arr;
    out+=p2genome(snp,n);
    for(auto p=ptr->parent;p;p=ptr->parent){
      ptr=deref(p);
      if(!ptr->parent){QapAssert(p.get_gen()==0);result.id=p.get_id();break;}
      auto buff=p2genome(p,n);
      out+=std::move(buff);
    }
    reverse(out);
    return result;
  }
  struct t_small_node{
    #define DEF_PRO_CLASSNAME()t_small_node
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_small_node_ptr,parent,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_small_nodes{
    #define DEF_PRO_CLASSNAME()t_small_nodes
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<vector<t_small_node>>,N,$)\
    ADD(vector<vector<t_small_node>>,A,$)\
    ADD(vector<vector<t_small_node>>,S,$)\
    //===
    #include "defprovar.inl"
    //===
    static const unsigned block=1024*1024;
    t_small_node*operator[](t_small_node_ptr::t_impl p){
      QapAssert(p.dir<3);
      auto&arr=(&N)[p.dir];
      return get(arr,p.id);
    };
    t_small_node*get(vector<vector<t_small_node>>&arr,int id){
      int seg=id/block;
      int off=id%block;
      QapAssert(qap_check_id(arr,seg));
      auto&s=arr[seg];
      QapAssert(qap_check_id(s,off));
      return &s[off];
    }
    int add(int dir){
      QapAssert(dir>=0&&dir<3);
      auto&arr=(&N)[dir];
      if(arr.empty())qap_add_back(arr).reserve(block);
      auto*pb=&arr.back();
      int id=(-1+int(arr.size()))*block+pb->size();
      if(pb->size()==block)pb=&qap_add_back(arr);
      qap_add_back(*pb);
      return id;
    }
    void clear(){N.clear();A.clear();S.clear();}
  };
  struct t_node{
    //#define DEF_PRO_UNSAVEABLE()
    #define DEF_PRO_CLASSNAME()t_node
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_obj,obj,$)\
    ADD(t_small_node_ptr,self,$)\
    ADD(t_node_points,points,$)\
    ADD(int,t,0)\
    ADD(int,next,-1)\
    ADD(bool,deaded,false)\
    //===
    #include "defprovar.inl"
    //===
    void childs_build_sim_and_grab_if_ok(TGame*game){
      IF_WITH_PNODEMAP(QapAssert(self););
      {t_node tmp;tmp.init(game,this,+0).sim_and_grab_if_ok(game);}
      {t_node tmp;tmp.init(game,this,+1).sim_and_grab_if_ok(game);}
      {t_node tmp;tmp.init(game,this,-1).sim_and_grab_if_ok(game);}
      //arr[3].init(game,this,vec2d(-1,0)*0.5)->sim(game);
      //arr[4].init(game,this,vec2d(+1,0)*0.5)->sim(game);
      //arr[5].init(game,this,vec2d(-1,0)*0.25)->sim(game);
      //arr[6].init(game,this,vec2d(+1,0)*0.25)->sim(game);
      //arr[7].init(game,this,vec2d(-1,0)*0.75)->sim(game);
      //arr[8].init(game,this,vec2d(+1,0)*0.75)->sim(game);
    }
    t_node&init(TGame*game,t_node*pown,int ndir){
      obj=pown->obj;t=pown->t;
      IF_WITH_PNODEMAP(
        self=game->add_small_node((3+ndir)%3);
        t_small_node&ref=*self.get(game);
        ref.parent=pown->self;
      );
      obj.a=ndir;
      return *this;
    }
    void sim_and_grab_if_ok(TGame*game)
    {
      deaded=!sim_n_steps(game,this,steps_per_branch);
      if(deaded)return;
      obj.update_dir();
      auto&out=game->nodes_out;
      auto node_id=out.size();
      out.push_back(std::move(*this));
      game->fullreg(node_id);
    }
  };
  class t_map_of_pnode{
  public:
    typedef t_small_node_ptr t_elem;
  public:
    #define DEF_PRO_CLASSNAME()t_map_of_pnode
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_elem>,mem,$)\
    ADD(int,w,0)\
    ADD(int,h,0)\
    ADD(t_map_info,info,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    //t_map_of_pnode(){DoReset();}
    static void set_to_def(t_elem&elem){elem=nullptr;}
    void fill(){for(int i=0;i<w*h;i++)mem[i]=nullptr;}
    #include "t_map_getters.inl"
  };
  struct t_vec_updater{
    #define DEF_PRO_CLASSNAME()t_vec_updater
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,pos,0)\
    ADD(int,step,128)\
    ADD(bool,enabled,false)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_cell{
    uint id:32-3;
    uint type:3;
  };
  struct t_cdlinedev{
    #define DEF_PRO_CLASSNAME()t_cdlinedev
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_map_of_ways,map,$)\
    ADD(vector<array(int,2)>,vec2,$)\
    ADD(vector<array(int,3)>,vec3,$)\
    ADD(vector<array(int,4)>,vec4,$)\
    ADD(vector<array(int,5)>,vec5,$)\
    ADD(vector<array(int,6)>,vec6,$)\
    ADD(vector<vector<int>>,vecN,$)\
    //===
    #include "defprovar.inl"
    //===
    void clear(){
      vec2.clear();vec3.clear();vec4.clear();vec5.clear();vec6.clear();vecN.clear();
    }
    void get_cdline_vec(vector<int>&out,const vector<t_line>&lines,const vec2d&pos,real r)
    {
      for(int i=0;i<lines.size();i++){
        auto&ex=lines[i];auto&a=ex.a;auto&b=ex.b;
        bool has_cd=WithoutV_FastCD_CircleAndWallWithCircles(pos,r,a,b);
        if(!has_cd)continue;
        out.push_back(i);
      }
    }
    void get_cdline_vec(vector<int>&out,const vector<t_line>&mem,const vector_view<int>&lines,const vec2d&pos,real r)
    {
      for(int i=0;i<lines.size();i++){
        auto&id=lines[i];auto&ex=mem[id];auto&a=ex.a;auto&b=ex.b;
        bool has_cd=WithoutV_FastCD_CircleAndWallWithCircles(pos,r,a,b);
        if(!has_cd)continue;
        out.push_back(id);
      }
    }
    int write_vec_and_ret_id(vector<int>&&ref){
      auto&arr=ref;
      int arr_size=arr.size();
      int n=std::min<int>(arr_size,7);
      static auto debug_n=2;
      if(n>=debug_n){
        int gg=1;
      }
      int id=0;
      switch(n)
      {
        case 1:{id=arr[0];arr.clear();break;}
        #define F(N)case N:{auto&vec=vec##N;id=vec.size();qap_add_back(vec)=*(array<int,N>*)&arr[0];arr.clear();break;}
        F(2)F(3)F(4)F(5)F(6)
        #undef F
        case 7:{auto&vec=vecN;id=vec.size();qap_add_back(vec)=std::move(arr);break;}
      };
      t_cell out={id,n};
      return *(int*)&out;
    }
    int get_cdline_id(const vector<t_line>&lines,const vec2d&pos,real r,const vector_view<int>&pid2line)
    {
      static vector<int> arr;
      get_cdline_vec(arr,lines,pid2line,pos,r);
      return write_vec_and_ret_id(std::move(arr));
    }
    int get_cdline_id(const vector<t_line>&lines,const vec2d&pos,real r,const vector<int>*pid2line=nullptr)
    {
      static vector<int> arr;
      if(!pid2line)get_cdline_vec(arr,lines,pos,r);
      if(pid2line)get_cdline_vec(arr,lines,make_view(*pid2line),pos,r);
      return write_vec_and_ret_id(std::move(arr));
    }
    const vector_view<int> get_view_at(const t_obj&obj)const
    {
      auto c=*(t_cell*)&map.get(map.world_to_cell(obj.pos));
      return get_view_at(c);
    }
    const vector_view<int> get_view_at(t_cell c)const
    {
      vector_view<int> fail;
      if(!c.type)return fail;
      switch(c.type)
      {
        case 1:{static int t[1];t[0]=c.id;return t;break;}
        #define F(N)case N:{return vec##N[c.id];break;}
        F(2)F(3)F(4)F(5)F(6)
        #undef F
        case 7:{return vecN[c.id];}
      };
      QapNoWay();
      return fail;
    }
  };
public:
  #define DEF_PRO_CLASSNAME()TGame
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(t_obj,obj,$)\
  ADD(vec2d,cam_pos,$)\
  ADD(real,scale,1)\
  ADD(vector<t_line>,lines,$)\
  ADD(bool,end,true)\
  ADD(bool,show_way,true)\
  ADD(vector<vec2d>,points,$)\
  ADD(t_geom,tree,$)\
  ADD(t_geom,old_tree,$)\
  ADD(int,depth,1024*8)\
  ADD(vec2d,sp,$)\
  ADD(real,ds,4)\
  ADD(bool,pause,true)\
  ADD(vec2d,target_point,$)\
  ADD(vec2d,cam_dir,vec2d(1,0))\
  ADD(bool,show_dir_way,false)\
  ADD(bool,show_map,true)\
  ADD(bool,fast_node_draw,true)\
  ADD(bool,cam_rot,false)\
  ADD(bool,cam_offcentric,false)\
  ADD(bool,endable,true)\
  ADD(int64,total_nodes,0)\
  ADD(bool,need_init,true)\
  ADD(vector<int>,cdmapptrs,$)\
  ADD(t_map_of_ways,cdmap,$)\
  ADD(t_map_of_ways,map,$)\
  ADD(t_map_of_ways,pixmap,$)\
  ADD(t_map_of_ways,wavemap,$)\
  ADD(t_map_of_ways,wavemap_cur,$)\
  ADD(t_map_of_ways,layersmap,$)\
  ADD(bool,use_pixmap,false)\
  ADD(bool,use_wavemap,false)\
  ADD(bool,show_pixmap,false)\
  ADD(bool,show_wavemap,false)\
  ADD(bool,show_cdlinemap,false)\
  ADD(bool,use_layersmap,false)\
  ADD(bool,show_layersmap,false)\
  ADD(int,path_length,-1)\
  ADD(bool,path_optimization,false)\
  ADD(bool,show_both_path,false)\
  ADD(bool,auto_disable_path_optimization,false)\
  ADD(bool,show_near_point,false)\
  ADD(t_full_genome,optimized_path_bef,$)\
  ADD(t_full_genome,optimized_path_aft,$)\
  ADD(vector<string>,genomes,$)\
  ADD(bool,use_genomes,false)\
  ADD(bool,use_opt_by_parts,true)\
  ADD(string,status,$)\
  ADD(vector<t_node>,frozen,$)\
  ADD(big_vector<t_node>,nodes,$)\
  ADD(big_vector<t_node>,nodes_out,$)\
  ADD(vector<t_map_of_ways>,maps,$)\
  ADD(t_small_nodes,small_nodes,$)\
  ADD(vector<t_map_of_pnode>,pnodemaps,$)\
  ADD(bool,tex_auto_update,true)\
  ADD(bool,auto_scale_line_size,true)\
  ADD(bool,need_wave_cd_cleaner,true)\
  ADD(bool,wavemap_swaped,false)\
  ADD(real,step_time,0)\
  ADD(int,step_n,0)\
  ADD(real,run_time,0)\
  ADD(int,wave_id,0)\
  ADD(int,pos_id,0)\
  ADD(vector<t_snapshot>,snapshots,$)\
  ADD(t_vec_updater,vec_updater,$)\
  ADD(vector<t_obj>,wave_sources,$)\
  ADD(t_cdlinedev,cdlinedev,$)\
  ADD(int,frame_counter,0)\
  //===
  #include "defprovar.inl"
  //===
public:
  t_perf_sys sys;
public:
  const real line_size()const{return auto_scale_line_size?ds/scale:ds;}
  ~TGame(){if(win.NeedClose)on_free();}
  static string get_fn(){
    //#ifdef _DEBUG
    //return "game(debug).bin";
    //#else
    return "game.bin";
    //#endif
  }
  static string get_map_fn(){return "map.bin";}
  void sys_load()
  {
    root_fix();
    FsIO<> IO(get_fn());if(!IO.f)return;
    int size_of_type=-1;
    QapLoad(IO,size_of_type);
    int our_size=QapSizeOfSave<TGame>();
    if(size_of_type!=our_size)return;
    QapLoad(IO,*this);root_fix();
    return;
  }
  void sys_save(){
    int size_of_type=QapSizeOfSave<TGame>();FsWrite IO(get_fn());QapSave(IO,size_of_type);QapSave(IO,*this);
  }
  void on_init(){need_init=false;if(access(get_fn().c_str(),0)!=0)set_to_def();sys_load();need_init=false;}
  void on_free(){sys_save();}
  void root_fix()
  {
    {
      auto&v=t_config::get().scale;
      if(v>0)scale=v;
      auto&line_size=t_config::get().line_size;
      if(line_size>0)ds=line_size;
    }
    /*if(nodes.empty())return;
    auto&root=nodes[0];
    root.parent=nullptr;
    root.obj=obj;
    root.t=0;*/
  }
  void set_to_def()
  {
    obj.v=t_obj::dir2v(obj.dir);
    srand(t_config::get().seed+0*time(0));
    auto rndline_n=t_config::get().rndline_n;
    auto rndline_pos_var=t_config::get().rndline_pos_var;
    auto rndline_min_len=t_config::get().rndline_min_len;
    auto rndline_max_len=t_config::get().rndline_max_len;
    real W=rndline_pos_var+500;
    real H=W;
    qap_add_back(lines).set_a(-W,-H).set_b(+W,-H);
    qap_add_back(lines).set_a(-W,+H).set_b(+W,+H);
    qap_add_back(lines).set_a(-W,-H).set_b(-W,+H);
    qap_add_back(lines).set_a(+W,-H).set_b(+W,+H);
    for(int i=0;i<rndline_n;i++)
    {
      vec2d center=rndvec2d(-1,+1)*rndline_pos_var;
      vec2d dv=Vec2dEx(rndreal(0,Pi2),rndreal(rndline_min_len,rndline_max_len));
      auto&ex=qap_add_back(lines);
      ex.a=center+dv;
      ex.b=center-dv;
    }
    for(int i=0;i<40;i++)
    {
      vec2d center=rndvec2d(-1,+1)*rndline_pos_var;
      vec2d dv=Vec2dEx(rndreal(0,Pi2),rndreal(rndline_min_len*3,rndline_max_len*3));
      auto&ex=qap_add_back(lines);
      ex.a=center+dv;
      ex.b=center-dv;
    }
    if(bool need_gen_pentastar=false)
    {
      lines.clear();
      for(int i=0;i<5;i++){
        auto bef=Vec2dEx(Pi2*(real(i)-0.5)/5,max_speed*14*30).Ort();
        auto aft=Vec2dEx(Pi2*(real(i)+0.5)/5,max_speed*14*30).Ort();
        auto top=Vec2dEx(Pi2*i/5,max_speed*14*70).Ort();
        qap_add_back(lines).set_a(top).set_b(bef);
        qap_add_back(lines).set_a(!i?aft+(top-aft)*0.90:top).set_b(aft);
      }
    }
    int map_n=t_config::get().map_n;
    real bs=get_block_size();
    maps.resize(map_n);pnodemaps.resize(map_n);
    //for(int i=0;i<360;i++)get_map_normdir(Vec2dEx(Pi2*i/360,1));
    for(int i=0;i<maps.size();i++){
      maps[i].init();
      IF_WITH_PNODEMAP(pnodemaps[i].init(););
    }
    layersmap.init();
    cdlinedev.map.init();
    cdmap.init();
    map.init();
    pixmap.init(1.0/t_config::get().pixmapscale);
    wavemap.init(1.0/t_config::get().wavemapscale);
    wavemap_cur.init(1.0/t_config::get().wavemapscale);
    maps_reset();
  }
  void layersmap_reset()
  {
    int wh=map.w*map.h;
    for(int y=0;y<map.h;y++)for(int x=0;x<map.w;x++){
      int n=0;for(int i=0;i<maps.size();i++){if(maps[i].get(x,y)>=0)n++;}
      layersmap.get(x,y)=n?1024-n:-1;
    }
  }
  void layersmap_smart_recalc()
  {
    layersmap_reset();
    int wh=map.w*map.h;
    auto f=[&](int x,int y,int z)->bool{auto&ex=maps[z%maps.size()];return !ex.check(vec2i(x,y))?false:(ex.get(x,y)>=0);};
    auto last=maps.size()-1;
    for(int y=0;y<map.h;y++)for(int x=0;x<map.w;x++)
    {
      int n=0;
      for(int i=0;i<maps.size();i++)
      {
        int dx=
        (
          false
          #define F(dx,dy)||f(x+(dx),y+(dy),i-1)||f(x+(dx),y+(dy),i-0)||f(x+(dx),y+(dy),i+1)
                 F(-0,-1)
          F(-1,0)F(+0,+0)F(+1,0)
                 F(-0,+1)
          #undef F
        );
        n+=dx;
      }
      layersmap.get(x,y)=n?1024-n:-1;
    }
  }
  void cdlinedev_reset()
  {
    QapCleanIf(lines,[](t_line&ex){return ex.a==ex.b;});
    cdlinedev.clear();
    t_cdlinedev&tmp=cdlinedev;tmp.clear();
    //int def=16;
    QapAssert(map.w%16==0);QapAssert(map.h%16==0);
    int scale=map.w/2;
    tmp.map.init(scale);
    real ms[1024*4];for(int i=0;i<lenof(ms);i++)ms[i]=-1;QapClock clock;clock.Start();
    {
      QapClock clock;clock.Start();
      {
        auto&m=tmp.map;
        auto r=t_config::get().r+sqrt(2.0)*m.info.block_size*0.5;
        for(int y=0;y<m.h;y++)for(int x=0;x<m.w;x++){auto p=m.map_to_world(vec2d(x,y));m.get(x,y)=tmp.get_cdline_id(lines,p,r);}
      }
      clock.Stop();ms[scale]=clock.MS();
    }
    t_cdlinedev cur;
    auto f=[&](int scale)
    {
      QapClock clock;clock.Start();
      {
        cur.map.init(scale);
        auto r=t_config::get().r+sqrt(2.0)*cur.map.info.block_size*0.5;
        for(int y=0;y<cur.map.h;y++)for(int x=0;x<cur.map.w;x++){
          auto p=cur.map.map_to_world(vec2d(x,y));
          auto vv=tmp.get_view_at(*(t_cell*)&tmp.map.get(tmp.map.world_to_cell(p))/*get(x*scale/def,y*scale/def)*/);
          cur.map.get(x,y)=cur.get_cdline_id(lines,p,r,vv);
        }
        tmp=std::move(cur);
        QapAssert(cur.map.mem.empty());
      }
      clock.Stop();ms[scale]=clock.MS();
    };
    //
    for(scale/=2;scale>=1;scale/=2)f(scale);
    //f(8);f(4);f(2);f(1);
    //f(4);f(1);
    if(static bool need_show_cdlinedev_reset_perf_info=false)
    {
      vector<string> arr;for(int i=0;i<lenof(ms);i++)if(ms[i]>=0){qap_add_back(arr)="ms["+IToS(i)+"] = "+FToS(ms[i]);}
      QapDebugMsg("cdlinedev_reset:\n"+join(arr,"\n")+"\n\n total = "+FToS(clock.MS()));
    }
  }
  void maps_reset()
  {
    total_nodes=0;
    wave_sources.clear();
    cdlinedev_reset();
    nodes.clear();nodes_out.clear();frozen.clear();
    small_nodes.clear();
    cdmap.fill(-1);
    for(int i=0;i<maps.size();i++)maps[i].fill(-1);
    IF_WITH_PNODEMAP(for(int i=0;i<maps.size();i++)pnodemaps[i].fill(););
    map.fill(-1);pixmap.fill(-1);wavemap.fill(-1);wavemap_cur.fill(-1);
    auto&root=qap_add_back(nodes);
    root=std::move(t_node());
    root.self=add_small_node(0);
    root.obj=obj;
    root.t=0;
    layersmap_reset();
    qap_add_back(wave_sources)=root.obj;
    if(int number_of_random_wave_sources=0)for(int i=0;i<number_of_random_wave_sources;i++)
    {
      auto&root=qap_add_back(nodes);
      root=std::move(t_node());
      root.self=add_small_node(0);
      root.obj=obj;
      auto rndline_pos_var=t_config::get().rndline_pos_var;
      auto rndline_min_len=t_config::get().rndline_min_len;
      auto rndline_max_len=t_config::get().rndline_max_len;
      //vec2d dv=Vec2dEx(rndreal(0,Pi2),rndreal(rndline_min_len*3,rndline_max_len*3));
      root.obj.pos=rndvec2d(-1,+1)*rndline_pos_var;
      root.obj.dir=rand()%1024;
      root.t=0;
      qap_add_back(wave_sources)=root.obj;
    }
    run_time=0;wave_id=0;
  }
  t_small_node_ptr add_small_node(int dir)
  {
    t_small_node_ptr retval;
    t_small_node_ptr::t_conv c;
    c.impl.dir=dir;
    c.impl.id=small_nodes.add(dir);retval.id=c.v;return retval;
  }
public:
  int get_cdline_id_old(const vec2d&pos,real r)
  {
    static vec2d tmp;int counter=0;
    for(int i=0;i<lines.size();i++){
      auto&ex=lines[i];auto&a=ex.a;auto&b=ex.b;
      bool has_cd=FastCD_CircleAndWallWithCircles(pos,tmp,r,a,b);
      if(has_cd)counter++;//return i;
    }
    return counter?1024-counter:-1;
  }
  bool has_cd_with(t_obj&obj,int line_id){
    static const auto r=t_config::get().r;
    auto&ex=lines[line_id];auto&a=ex.a;auto&b=ex.b;
    return WithoutV_FastCD_CircleAndWallWithCircles(obj.pos,r,a,b);
  }
  bool has_cd_with(t_obj&obj,const vector_view<int>&arr){
    bool has_cd=false;
    for(int i=0;i<arr.size();i++){
      has_cd=has_cd||has_cd_with(obj,arr[i]);
    }
    return has_cd;
  }
  //bool has_cd_with(t_obj&obj,const vector<int>&arr){return has_cd_with(obj,make_view(arr));}
  bool has_cd_with(t_obj&obj,t_cdlinedev&dev)
  {
    auto&m=dev.map;
    auto c=*(t_cell*)&m.get(m.world_to_cell(obj.pos));
    if(!c.type)return false;
    auto vv=dev.get_view_at(c);
    return has_cd_with(obj,vv);
  }
  bool sim_step(t_obj&obj)
  {
    obj.move();
    return !has_cd_with(obj,cdlinedev);
    /*
    for(int i=0;i<lines.size();i++){
      auto&ex=lines[i];auto&a=ex.a;auto&b=ex.b;
      has_cd=has_cd||FastCD_CircleAndWallWithCircles(obj.pos,obj_v,r,a,b);
    }
    if(has_cd&&&obj==&this->obj){
      auto&arr=t_obj::get();
      obj.dir=QAP_MINVAL_ID_OF_VEC(arr,ex.dist_to(obj_v));
      obj.v=obj.dir2v(obj.dir);
    }
    return !has_cd;
    */
  }
  vec2d s2w(const vec2d&pos)
  {
    //bool offcentric=false; auto cam_dir=vec2d(1,0);
    return t_offcentric_scope::screen_to_world(viewport,pos,obj.pos+cam_pos,cam_rot?cam_dir.Rot(-obj.get_v().Ort()).Norm():cam_dir,scale,cam_offcentric);
  }
  static bool inv(bool&ref){ref=!ref;return ref;}
  void DoPreMove()
  {
    if(need_init)on_init();
    if(kb("SHIFT+U")){layersmap_smart_recalc();}
    if(kb("ALT+U")){if(inv(use_layersmap))layersmap_reset();}
    if(kb("CTRL+U"))inv(show_layersmap);
    if(kb("ALT+Y"))cdlinedev_reset();
    if(kb("CTRL+Y"))inv(show_cdlinemap);
    if(kb("ALT+P"))inv(use_pixmap);
    if(kb("CTRL+P"))inv(show_pixmap);
    if(kb("ALT+E"))inv(use_wavemap);
    if(kb("CTRL+E"))inv(show_wavemap);
    if(kb("ALT+F"))depth=(24/3)*step_n/step_time;
    if(kb("CTRL+F"))inv(need_wave_cd_cleaner);
    if(kb("X"))inv(tex_auto_update);
    if(kb("L"))inv(auto_scale_line_size);
    if(kb.OnDown('P'))inv(use_opt_by_parts);
    if(kb.OnDown('G'))inv(use_genomes);
    if(kb.OnDown('N'))inv(show_near_point);
    if(kb("CTRL+H")){
      t_portable_map map;map.load_from(*this);
      file_put_contents(get_map_fn(),QapSaveToStrWithSizeOfType(map));return;
    }
    if((kb.Down(VK_SHIFT))&&kb("CTRL+L")){
      t_old_portable_map map;
      QapLoadFromStrWithSizeOfType(map,file_get_contents(get_map_fn()));
      map.save_to(*this);
      maps_reset();
    }
    if((!kb.Down(VK_SHIFT))&&kb("CTRL+L")){
      t_portable_map map;
      QapLoadFromStrWithSizeOfType(map,file_get_contents(get_map_fn()));
      map.save_to(*this);
      maps_reset();
    }
    if(kb.OnDown('O')){inv(path_optimization);status="";}
    if(kb.Down[VK_ESCAPE])win.Close();
    if(kb.Down('R'))end=false;
    if(kb.OnDown('T'))inv(cam_offcentric);
    if(kb.Down('Z'))cam_dir=vec2d(1,0);
    if(cam_rot)
    {
      auto k=(1.0+(45-10)/75.0);
      real da=0;
      if(kb.Down('Q'))da=-1;
      if(kb.Down('E'))da=+1;
      cam_dir=Vec2dEx(cam_dir.GetAng()+k*(da*Pi/75.0),1);
    }
    if(kb.OnDown(VK_F11))inv(cam_rot);
    if(kb.OnDown(VK_F6)&&kb.Down(VK_CONTROL)){lines.clear();cdlinedev_reset();}
    if(kb.Down(VK_ADD))scale*=1.01;
    if(kb.Down(VK_SUBTRACT))scale/=1.01;
    if(kb.Down(VK_DIVIDE))scale=1;
    if(kb.OnDown(VK_MULTIPLY))scale*=0.5;
    if(kb.OnDown(VK_SPACE))end=!end;
    if(kb.OnDown('I'))show_way=!show_way;
    if(kb.OnDown(mbLeft))sp=s2w(mpos);
    if(kb.Down(mbRight)||kb.Down(VK_SHIFT))target_point=map.map_to_world(tovec2i(map.world_to_cell(s2w(mpos))));
    if(kb.OnUp(mbLeft)){qap_add_back(lines).set_a(s2w(mpos)).set_b(sp);/*cdlinemap_reset();*/}
    if(kb.OnDown(VK_F4))show_dir_way=!show_dir_way;
    if(kb.OnDown(VK_F7))show_map=!show_map;
    if(kb.OnDown(VK_F12))fast_node_draw=!fast_node_draw;
    if(kb.OnDown(VK_F10))endable=!endable;
    if(!endable)end=false;
    if(end){if(!kb.Down(VK_CONTROL))cam_pos+=kb.get_dir_from_wasd_and_arrows().Rot(cam_rot?cam_dir.Rot(-obj.get_v().Ort()).Norm():cam_dir)*(5.0/scale);}else{cam_pos=vec2d_zero;}
    if(kb.OnDown(VK_HOME))pos_id=0;
    if(kb.OnDown(VK_END))pos_id=snapshots.size();
    if(kb.OnDown(VK_PRIOR)){pos_id--;if(qap_check_id(snapshots,pos_id))snapshots[pos_id].save_to(*this);}
    if(kb.OnDown(VK_NEXT)){pos_id++;if(qap_check_id(snapshots,pos_id))snapshots[pos_id].save_to(*this);}
    static bool play_video=false;
    if(kb.OnDown(VK_APPS)&&kb.Down(VK_CONTROL))inv(play_video);
    if(play_video){
      pos_id++;
      auto old_pos=obj.pos;
      if(qap_check_id(snapshots,pos_id))snapshots[pos_id].save_to(*this);
      cam_pos+=old_pos-obj.pos;
    }
    bool need_snapshot=kb("CTRL+N");
    bool need_steep=kb("ALT+N");
    if(!nodes.size()&&!need_snapshot)need_snapshot=t_config::get().auto_next_pos;
    //if(wave_id==103)need_snapshot=true;
    if(!end||need_snapshot||need_steep)
    {
      obj.a=kb.get_dir_from_wasd_and_arrows().x;//obj.wasd2a(kb.get_dir_from_wasd_and_arrows());
      if(t_config::get().steps_per_update<1){
        int n=1.0/t_config::get().steps_per_update;
        if(frame_counter%n==0)end=!sim_step(obj);
      }
      for(int i=0;i<int(t_config::get().steps_per_update);i++)
      {
        end=!sim_step(obj);
      }
      if(show_way){points.clear();tree=qDev.GenGeomLineList(points,line_size());}
      if(need_snapshot)
      {
        qap_add_back(snapshots).load_from(*this);
        pos_id=snapshots.size();
        if(!kb.Down[VK_SHIFT])map.tofile("bmp_pos/"+IToS(pos_id)+".bmp");
        maps_reset();
        end=true;
      }
      if(need_steep){pos_id++;end=true;}
    }
    if(kb.OnDown(VK_F1))depth++;
    if(kb.OnDown(VK_F2))depth--;
    for(int numkey='0';numkey<='9';numkey++)if(kb.OnDown(numkey))depth=numkey-'0';
    if(kb.OnDown(VK_CONTROL)){
      {points.clear();tree=qDev.GenGeomLineList(points,line_size());}
    }
    if(kb.OnDown(VK_F5))
    {
      maps_reset();
    }
    if(vec_updater.enabled||nodes.size())
    {
      t_clock clock(sys,"update_nodes");
      update_nodes();
    }
    if(kb.OnDown(VK_F9)){
      pause=!pause;
      sys.next();
    }
    if(kb.OnDown(VK_F3)||!pause)if(!vec_updater.enabled)
    {
      start_wave();
      sys.next();
    }
  }
  vec2d get_map_dir(int id,real mag=1){
    real base_ang_offset=Pi2/(maps.size()*2);
    return Vec2dEx((id*2+1)*base_ang_offset,mag);
  }
  vec2d get_map_normdir(const vec2d&dir){
    int id=get_map_id(dir);
    auto eps=Vec2dEx(Pi2/(maps.size()*4),1);
    //QapAssert(get_map_id(get_map_dir(id,dir.Mag()).Rot(eps))==id);
    //QapAssert(get_map_id(get_map_dir(id,dir.Mag()).UnRot(eps))==id);
    return get_map_dir(id,dir.Mag());
  }
  int get_map_id(const vec2d&dir){
    auto id=int((Pi2+dir.GetAng())*maps.size()/Pi2)%maps.size();
    return id;
  }
  int get_map_id(const t_obj&obj){
    //static vector<size_t> obja2mapid;
    //if(obja2mapid.empty())for(int i=0;i<t_obj::max_dirs;i++)obja2mapid.push_back(get_map_id(t_obj::dir2v(i)));
    real ang_mul_maps_n=real((uint(obj.dir)%max_dirs)*loops_per_max_dirs*maps.size())/max_dirs;
    auto id=int(ang_mul_maps_n)%maps.size();
    return id;
  }
  t_map_of_pnode&get_pnodemaps(const vec2d&dir){
    auto id=get_map_id(dir);
    if(!qap_check_id(maps,id)){
      int gg=1;
    }
    return pnodemaps[id];
  }
  t_map_of_ways&get_map(const t_obj&obj){
    auto id=get_map_id(obj);
    return maps[id];
  }
  t_map_of_ways&get_map(const vec2d&dir){
    auto id=get_map_id(dir);
    if(!qap_check_id(maps,id)){
      int gg=1;
    }
    return maps[id];
  }
  //t_cd_dev<t_node>*pcddev;
  int cdround(vector<t_node*>&arr)
  {
    if(arr.size()<2)return 0;
    static const real min_pos_dist_k=t_config::get().min_pos_dist_k;
    //static const real sqr_min_ang_dist=get_min_ang_dist()*get_min_ang_dist();
    static const real min_pos_dist=get_min_pos_dist()*min_pos_dist_k;
    static const int cd_grid_n=t_config::get().cd_grid_n;
    int n=0;
    auto r=min_pos_dist;
    QapAssert(r>0);
    auto d=r+r;
    auto dd=d*d;
    {auto&n=get_maxcn();n=std::max<int>(n,arr.size());}
    auto arr_size=arr.size();
    //for(int i=0;i<arr.size();i++){auto&dir=nodes[arr[i]].obj.dir;dir=uint(dir)%t_obj::max_dirs;}
    for(size_t i=0;i<arr_size;i++)
    {
      auto&a=*arr[i];
      //QapAssert(!a.deaded);//if(a.deaded)continue;
      for(size_t j=i+1;j<arr_size;j++)
      {
        auto&b=*arr[j];
        //QapAssert(!b.deaded);//if(b.deaded)continue;
        //if(a.obj.dir!=b.obj.dir)continue;
        if(a.obj.dir!=b.obj.dir)continue;//if(!t_obj::is_same_dir(a.obj.dir,b.obj.dir))continue;
        auto ox=b.obj.pos-a.obj.pos;
        //if(abs(ox.y)>d)continue;
        if(ox.SqrMag()>dd)continue;
        if(a.t!=b.t)continue;
        //if(!a.obj.v.sqrdist_to_point_less_that_rr(b.obj.v,sqr_min_ang_dist))continue;
        a.deaded=true;n++;break;
      }
    }
    return n;
  }
  //vector<int> get_cdround(int head)
  //{
  //  auto&nodes=nodes_out;
  //  int cur=head;
  //  vector<int> out;
  //  for(;;)
  //  {
  //    qap_add_back(out)=cur;
  //    auto&id=nodes[cur].next;
  //    cur=id;
  //    if(cur==head)break;
  //  }
  //  return out;
  //}
  int cdroundwith(int head)
  {
    int cur=head;
    static vector<t_node*> out;
    for(;;)
    {
      auto*ptr=&nodes[cur];
      if(!ptr->deaded)qap_add_back(out)=ptr;
      auto&id=ptr->next;
      cur=id;id=-1;
      if(cur==head)break;
    }
    int n=cdround(out);
    out.clear();
    return n;
  }
  void fullreg(int node_id)
  {
    auto cc=tovec2i(cdmap.world_to_cell(nodes_out[node_id].obj.pos));
    if(!cdmap.check(cc)){nodes_out[node_id].deaded=true;return;}
    auto ptr=cdmap.conv_vec_to_id(cc);
    if(!reg(cdmap.mem[ptr],node_id))return;
    qap_add_back(cdmapptrs)=ptr;
  }
  bool reg(int&bef_id,int aft_id)
  {
    //if(wave_id==13&&(bef_id==143||aft_id==143)){
    //  int gg=1;
    //}
    auto&nodes=nodes_out;
    if(bef_id<0){bef_id=aft_id;nodes[aft_id].next=aft_id;return true;}
    t_node&bef=nodes[bef_id];
    t_node&aft=nodes[aft_id];
    //if(bool need_hard_debug=false){
    //  auto tmp=get_cdround(bef_id);
    //  int gg=1;
    //}
    aft.next=bef.next;
    bef.next=aft_id;
    return false;
  }
  void start_wave()
  {
    t_clock clock(sys,"start_wave");
    QapClock main_clock;main_clock.Start();
    vec_updater.pos=0;
    vec_updater.enabled=true;
    points.clear();
    old_tree=std::move(tree);
    tree=t_geom();
    static const real min_ang_dist=get_min_ang_dist();
    static const real min_pos_dist=get_min_pos_dist();
    static const real min_pos_dist_k=t_config::get().min_pos_dist_k;
    static const int cd_grid_n=t_config::get().cd_grid_n;
    
    static int&maxn=get_maxn();int n=0;int cells=0;
    {
      t_clock clock(sys,"cdrounds_pass");
      auto nodes_size=nodes.size();
      for(size_t i=0;i<nodes_size;i++){
        auto&ex=nodes[i];
        if(ex.deaded)continue;
        if(ex.next<0)continue;
        //QapAssert(ex.next>=i);
        if(i!=ex.next)
        {
          n+=cdroundwith(i);cells++;
        }
        ex.next=-1;
      }
    }
    if(cells)
    {
      t_clock clock(sys,"wave_clean");
      maxn=std::max<int>(maxn,n);
    
      //qap_clean_if_deaded(nodes);
    }
    if(bool need_clean_cdmaptrs=true)
    {
      t_clock clock(sys,"cdmapp_clean");
      //cdmap.fill(-1);
      for(int i=0;i<cdmapptrs.size();i++)cdmap.mem[cdmapptrs[i]]=-1;
      cdmapptrs.clear();
    }

    if(nodes.size()){run_time+=main_clock.MS();wave_id++;}
  }
  static int&get_maxcn(){static int maxcn=0;return maxcn;}
  static int&get_maxn(){static int maxn=0;return maxn;}
  static real get_min_ang_dist(){const int max_dirs=t_config::get().max_dirs;return (Vec2dEx(Pi2/real(max_dirs),max_speed)-vec2d(max_speed,0)).Mag();}
  static real get_min_pos_dist(){return max_speed*steps_per_branch;}
  void update_nodes()
  {
    static const int gaptime=1+(get_block_size()*sqrt(2.0)/max_speed);
    auto&vu=vec_updater;vu.step=depth;
    if(!vu.enabled)return;
    if(!kb.OnDown(VK_F3)&&pause)return;
    auto&arr=nodes;
    auto mid0=get_map_id(mpos);
    auto vp=viewport.add_pos(cam_pos+obj.pos);vp.size/=scale;
    static bool frozen_allowed=t_config::get().frozen_allowed;
    if(frozen_allowed)for(int i=0;i<frozen.size();i++)
    {
      auto&ex=frozen[i];
      if(!point_in_quad(vp,ex.obj.pos))continue;
      qap_add_back(nodes)=std::move(ex);
      ex.deaded=true;
    }
    qap_clean_if_deaded(frozen);
    QapClock clock;clock.Start();
    auto arr_size=arr.size();auto limit=std::min<int>(vu.pos+vu.step,arr_size);
    step_n=0;int nodes_out_beg_pos=nodes_out.size();
    for(int&i=vu.pos;i<limit;i++){
      auto&ex=arr[i];
      if(ex.deaded){limit+=int(limit!=arr_size);continue;}
      auto&map=get_map(ex.obj);
      auto&ct=map.get(map.world_to_cell(ex.obj.pos));
      if(ct>=0&&ct+gaptime<=ex.t)continue;
      //qaptime/2;
      //qaptime=get_block_size()*0.5/max_speed;ex.obj.pos.dist_to_point_less_that_r(map.world_to_cell(ex.obj.pos),get_block_size()*0.5);
      if(frozen_allowed)if(!point_in_quad(vp,ex.obj.pos)){qap_add_back(frozen)=std::move(ex);limit=std::min<int>(limit+1,arr.size());continue;}
      ex.childs_build_sim_and_grab_if_ok(this);step_n+=3;
    }
    if(!fast_node_draw)
    {
      vector<vec2d> tmp_points;
      for(int i=nodes_out_beg_pos;i<nodes_out.size();i++){
        auto&ex=nodes_out[i];
        if(fast_node_draw){continue;}
        auto tmp=ex.points;
        tmp_points.push_back(tmp.beg);
        tmp_points.push_back(tmp.end);
      }
      tree.add_with_offset(qDev.GenGeomLineList(tmp_points,line_size()),vec2d(0,0));
    }
    wavemap_swaped=false;
    if(vu.pos>=arr.size()){
      nodes=std::move(nodes_out);vu.enabled=false;
      if(use_wavemap)
      {
        std::swap(wavemap,wavemap_cur);
        wavemap_cur.fill(-1);
      }
      if(show_both_path)(use_wavemap?wavemap:(use_pixmap?pixmap:map)).tofile("bmp/"+IToS(wave_id)+".bmp");
      wavemap_swaped=true;
    }
    step_time=clock.MS();
    if(nodes.size())run_time+=step_time;
  }
  static void co_min(int&ref,int t){if(ref<0||ref>t)ref=t;}
  static void co_dec(int&ref,int t){if(ref<0)ref=1024*16;ref--;}
  static void layers_dec(int&ref){if(ref<0)ref=1024;ref--;}
  static bool sim_n_steps(TGame*game,t_node*node,int max_iter){
    game->total_nodes++;
    auto&obj=node->obj;
    //auto cmd=char2v(node->self.get_gen());
    //auto&points=node->points;
    node->points.beg=obj.pos;
    auto clone=obj;
    bool fail=false;vec2d prev=obj.pos;
    for(int iter=0;iter<max_iter;iter++)
    {
      //clone.a=clone.wasd2a(cmd);
      fail=fail||!game->sim_step(clone);
      if(fail)break;
      node->t++;
      auto id=game->get_map_id(clone);
      auto&map=game->maps[id];
      if(game->use_pixmap)co_min(game->pixmap.get(tovec2i(game->pixmap.world_to_cell(clone.pos))),node->t);
      if(game->use_wavemap)co_dec(game->wavemap_cur.get(tovec2i(game->wavemap_cur.world_to_cell(clone.pos))),node->t);
      auto cc=tovec2i(map.world_to_cell(clone.pos));
      {auto&ct=game->map.get(cc);if(ct<0||ct>node->t)ct=node->t;}
      auto&ct=map.get(cc);
      if(ct>=0&&ct<node->t)continue;
      if(ct<0)if(game->use_layersmap)layers_dec(game->layersmap.get(cc));
      ct=node->t;
      IF_WITH_PNODEMAP(game->pnodemaps[id].get(cc)=node->self;)
    }
    node->points.end=clone.pos;
    //{qap_add_back(points)=prev;qap_add_back(points)=clone.pos;prev=clone.pos;}
    node->obj=clone;
    return !fail;
  }
  #define DrawPolyLine DrawPolyLine2016
  #include "draw_map.inl"
  #undef DrawPolyLine
  void draw_test()
  {
    return;
    qDev.SetColor(0x50000000);
    vector<vec2d> arr;for(int i=0;i<lines.size();i++){auto&ex=lines[i];arr.push_back(ex.b);arr.push_back(ex.a);}
    qDev.DrawPolyLine2016(arr,100,false);
    t_soft_lineloop::DrawTris(qDev,arr,50,false);
  }
  void DoPreDraw()
  {
    static auto r=t_config::get().r;
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    {
      t_offcentric_scope scope(qDev,obj.pos+cam_pos,cam_rot?cam_dir.Rot(-obj.get_v().Ort()).Norm():cam_dir,scale,cam_offcentric);
      draw_map();draw_test();
      auto circle=QapDev::GenGeomCircleEx(0,4,16,0);
      for(int i=0;i<lines.size();i++){
        auto&ex=lines[i];auto&a=ex.a;auto&b=ex.b;
        qDev.SetColor(0xff101010);
        qDev.DrawLine(a,b,line_size());
        if(bool need_draw_circles=false)
        {
          qDev.SetColor(0xff505050);
          qDev.DrawGeomWithOffset(circle,a);
          qDev.DrawGeomWithOffset(circle,b);
        }
        //qDev.DrawSolidCircle(a,4,16,0);
        //qDev.DrawSolidCircle(b,4,16,0);
      }
      qDev.SetColor(0x80000000);
      if(show_way)
      {
        
        int iter=64;real k=1.5;
        qDev.SetColor(0x80000070);
        qDev.DrawGeomWithOffset(old_tree,vec2d_zero);
        qDev.SetColor(0x80000000);
        qDev.DrawGeomWithOffset(tree,vec2d_zero);
        qDev.SetColor(0x80000000);
        if(0)qDev.DrawLineList(points,line_size());
      }
      qDev.SetColor(0xffbbbbbb);
      qDev.DrawSolidCircle(obj.pos,r,32,0);
      qDev.SetColor(0xff404040);
      qDev.DrawCircle(obj.pos,r,0,line_size(),32);
      qDev.DrawLine(obj.pos,obj.pos+obj.get_v()*(r/max_speed),line_size());
      qDev.SetColor(0xffff4040);
      if(obj.is_v_changed())qDev.DrawLine(obj.pos,obj.pos+vec2d(obj.a,0).SetMag(20).UnRot(-obj.get_v().Ort()),line_size()*0.5);
      if(bool show_circle_ms=false)
      {
        if(end){qDev.SetColor(0xff000000);qap_text_draw_at_x_center(qDev,obj.pos,"end",16);}
      }
    }
    DrawDownedKeys();
    int y=-16;int dy=-16;
    static QapClock FPSClock;if(!FPSClock.run)FPSClock.Start();frame_counter++;
    auto FPS=real(frame_counter*1000)/FPSClock.MS();
    #define F(text,text_size)qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,y),text,text_size);y+=dy;
    F("FPS = "+FToS(FPS),16);
    F("frame_counter = "+IToS(frame_counter),16);
    F("nodes/frame = "+IToS(depth),16);
    F("nodes = "+IToS(nodes.size()),16);
    F("done = "+FToS(100*real(vec_updater.pos)/nodes.size())+" %",16);
    F("total_nodes = "+IToS(total_nodes),16);
    F("maxn = "+IToS(get_maxn()),16);
    F("frozen = "+IToS(frozen.size()),16);
    F("path_length_bef = "+IToS(optimized_path_bef.arr.size()),16);
    //F("path_length_aft = "+IToS(optimized_path_aft.size()),16);
    //F("aft/bef = "+FToS(real(optimized_path_aft.size()*100)/optimized_path_bef.size())+" %",16);
    //F("path_optimization = "+BToS(path_optimization),16);
    //F("show_both_path = "+BToS(show_both_path),16);
    F("show_near_point = "+BToS(show_near_point),16);
    //F("use_genomes = "+BToS(use_genomes),16);
    //F("use_opt_by_parts = "+BToS(use_opt_by_parts),16);
    //F("auto_disable_path_optimization = "+BToS(auto_disable_path_optimization),16);
    F("status = "+status,16);
    F("step_time = "+FToS(step_time),16);
    F("step_speed = "+FToS(step_n/step_time)+" n/ms",16);
    F("run_time = "+FToS(run_time)+" ms",16);
    F("wave_id = "+IToS(wave_id),16);
    F("pos_id = "+IToS(pos_id),16);
    F("avr.speed = "+FToS(steps_per_branch*total_nodes/run_time)+" pos/ms",16);
    F("need_wave_cd_cleaner = "+BToS(need_wave_cd_cleaner),16);
    F("maxcn = "+IToS(get_maxcn()),16);
    #define FLAG(flag)F(#flag" = "+BToS(flag),16);
    FLAG(use_pixmap);
    FLAG(show_pixmap);
    FLAG(use_wavemap);
    FLAG(show_wavemap);
    #undef FLAG
    #undef F
    perf_text_out(y);
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

void test()
{
  TGame game;
  vector<t_obj> arr;
  vector<t_map_of_ways> out;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    game.obj=ex;
    game.maps_reset();
    for(;;)
    {
      game.DoPreMove();
      if(!game.nodes.size())break;
    }
  }
}

//#include <queue>
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //QapDebugMsg(IToS(sizeof(void*)));
  //QapDebugMsg(IToS(sizeof(TGame::t_node)));
  //test();
  //std::queue<int> q;
  //q.push(0);q.push(1);q.pop();
  //QapDebugMsg(IToS(sizeof(QapPool<TGame::t_small_childs>::Rec))+"\n"+IToS(sizeof(QapPool<TGame::t_childs>::Rec)));
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}
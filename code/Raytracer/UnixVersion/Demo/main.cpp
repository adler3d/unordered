#include "qaplite_unix.inl"
#include "qap_dev.inl"
#ifdef WIN32
#include "lodepng.cpp"
#endif
void QapUserInfo(const string&msg)
{
  printf("%s",("QapUserInfo: "+msg+"\n").c_str());
  fflush(stdout);
}

int*p_urs_port=nullptr;

#ifdef WIN32
void on_write_rec(const string&s){}
void on_start(){}
#else
  #ifndef SERV
  void on_write_rec(const string&s){}
  void on_start(){}
  #else
  #include "unix_raw_server.inl"
  #endif
#endif

static bool SToB(const string&s){QapAssert(s=="true"||s=="1"||s=="false"||s=="0");return s=="true"||s=="1";}
static string BToS(const bool&b){return b?"true":"false";}

struct t_app{
  struct t_arg{
    #define DEF_PRO_CLASSNAME()t_arg
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,key,$)\
    ADD(string,v,$)\
    ADD(bool,from_arg,false)\
    ADD(string,fullname,$)\
    ADD(string,shortname,$)\
    ADD(string,def,$)\
    //===
    #include "defprovar.inl"
    //===
    t_arg&sync(string&out,const string&def){
      this->def=def;
      out=from_arg?v:def;
      QapUserInfo("t_arg::sync(); // "+key+" = "+out);
      return *this;
    }
    t_arg&sync(int&out,const int&def){
      this->def=def;
      out=from_arg?SToI(v):def;
      QapUserInfo("t_arg::sync(); // "+key+" = "+IToS(out));
      return *this;
    }
    t_arg&sync(bool&out,const bool&def){
      this->def=def;
      out=from_arg?SToB(v):def;
      QapUserInfo("t_arg::sync(); // "+key+" = "+BToS(out));
      return *this;
    }
  };
  vector<t_arg> args;
  //PRO_FUNCGEN_GETP_BY_FIELD(t_arg,key2arg,args,string,key);
  PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(t_arg,key2arg,args,string,key);
  void addarg(const string&s){
    auto arr=split(s,"=");auto n=arr.size();
    auto&arg=*key2arg(arr[0]);
    arg.from_arg=true;
    if(n==1)return;
    if(n!=2){QapDebugMsg("arr.size() = "+IToS(n)+" // s = "+s);return;}
    arg.v=arr[1];
  }
  static vec3f mirror(vec3f nn,vec3f light_dir)
  {
    auto v=cross(nn,light_dir);
    return light_dir+nn*2.0*sqrt(1-dot(v,v));
  }
  static real rnd(){return rand()/real(RAND_MAX);};
  static real rndreal(real min,real max){return min+rnd()*(max-min);}
  static void inv(bool&ref){ref=!ref;}
  struct t_photon{
    #define DEF_PRO_CLASSNAME()t_photon
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec3f,pos,$)\
    ADD(vec3f,dir,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_raypoint{
    #define DEF_PRO_CLASSNAME()t_raypoint
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(real,t,-1)\
    ADD(vec3f,pos,$)\
    ADD(vec3f,n,$)\
    ADD(QapColor,c,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_trigon{
    #define DEF_PRO_CLASSNAME()t_trigon
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec3f,a,$)\
    ADD(vec2f,A,$)\
    ADD(vec2f,B,$)\
    ADD(vec2f,C,$)\
    ADD(vec3f,oy,$)\
    ADD(vec3f,oz,$)\
    ADD(vec3f,ox,$)\
    ADD(vector<float>,dir2inv_dy,$)\
    ADD(vector<int>,dirs,$)\
    ADD(vector<int>,light_dirs,$)\
    ADD(vector<int>,light_dirs_counter,$)\
    //===
    #include "defprovar.inl"
    //===
    vec3f normal()const{return -oy;}
  };
public:
  #define DEF_PRO_FEATURE_BEFORE
  #include "raymaps_code.inl"
  struct t_ray_env{
    #define DEF_PRO_CLASSNAME()t_ray_env
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<vector<int>>,dir_id_to_Ltris_list,$)\
    ADD(vector<vector<int>>,dir_id_to_Dtris_list,$)\
    ADD(vector<t_trigon>,tris,$)\
    ADD(vector<QapColor>,tris_colors,$)\
    ADD(vector<int>,is_light,$)\
    ADD(vector<vec3f>,dirs,$)\
    ADD(vector<t_trigon_vec3f>,trigons,$)\
    ADD(vector<t_dir_info>,dir2info,$)\
    ADD(vector<t_dir_info>,dir2back,$)\
    ADD(vector<t_dir_info>,dir2light,$)\
    //===
    #include "defprovar.inl"
    //===
    #define DEF_PRO_FEATURE_INSIDE
    #include "raymaps_code.inl"
  };
  #define DEF_PRO_FEATURE_AFTER
  #include "raymaps_code.inl"
public:
  #include "cd_algos.inl"
  #include "raycast.inl"
public:
  struct t_sphere_n{
    static const vector<vec3f>&get(){
      static vector<vec3f> arr;
      if(!arr.empty())return arr;
      string fn="sphere4096.bin";
      if(access(fn.c_str(),0)!=0){QapDebugMsg(fn+" - not found");QapNoWay();}
      QapLoadFromFile(fn,arr);
      auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex);O*=1.0/arr.size();
      QAP_FOREACH(arr,ex=(ex-O).Norm());
      //QAP_FOREACH(arr,if(abs(ex.Mag()-1)>0.001)QapDebugMsg("t_sphere_n::dirs[i].Mag() = "+FToS(ex.Mag())););
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
      
      #define F(A,a)tris.A=vec2f(dot(tris.ox,a),dot(tris.oz,a));
      F(A,a);F(B,b);F(C,c);
      #undef F
      
      //tris.color=env.tris_colors[i];
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
      QAP_FOREACH(env.tris,if(dot(ex.oy,dir)<0)qap_add_back(is_light(i)?Larr:Darr)=i;);
    }
    make_raymaps();
  }

  static vector<t_pix_info> get_pix_info_v2(const string&fn)
  {
    int skip_count=0;int version='v1';QapUserInfo("version = "+IToS(version));
    vector<t_pix_info> out;
    FsIO<> IO(fn);
    for(int i=0;i<IO.n/sizeof(t_pix_info);i++){
      t_pix_info tmp;tmp.size=0;
      IO.LoadPOD(&tmp,sizeof(tmp));
      if(tmp.size&&tmp.size!=sizeof(tmp)){
        QapDebugMsg("wrong rec size in fn = "+fn+"\n  also: i="+IToS(i)+" tmp.size = "+IToS(tmp.size));
        if(skip_count>128)break;
        skip_count++;continue;
      }
      if(tmp.version!=version){
        QapDebugMsg("wrong version in fn = "+fn+"\n  also: i="+IToS(i)+" tmp.version="+IToS(tmp.version)+" tmp.size = "+IToS(tmp.size));
        if(skip_count>128)break;
        skip_count++;continue;
      }
      out.push_back(tmp);
    }
    if(skip_count)QapDebugMsg("skip_count = "+IToS(skip_count));
    return out;
  }
  static vector<vec2i> get_pix_info_v2_vec2i(const string&fn)
  {
    vector<vec2i> out;
    FsIO<> IO(fn);
    for(int i=0;i<IO.n/sizeof(t_pix_info);i++){
      t_pix_info tmp;tmp.size=0;
      IO.LoadPOD(&tmp,sizeof(tmp));
      if(tmp.size&&tmp.size!=sizeof(tmp)){QapNoWay();break;}
      out.push_back(vec2i(tmp.x,tmp.y));
    }
    return out;
  }
  static void make_recovery(const string&fn,const vector<t_pix_info>&arr,int cx,int cy){
    vector<int> img;img.resize(cx*cy,-1);
    QAP_FOREACH(arr,auto id=ex.x+ex.y*cx;QapAssert(qap_check_id(img,id));img[id]=i;);
    vector<t_pix_info> out; 
    QAP_FOREACH(img,if(ex<0)return;qap_add_back(out)=arr[ex];);
    if(!out.size())return;
    auto*f=fopen(fn.c_str(),"wb");
    QapAssert(f);
    fwrite((char*)(void*)&out[0],sizeof(char),sizeof(out[0])*out.size(),f);
    fflush(f);
    fclose(f);
  }
  vector<string> get_mask_fn_list(){
    vector<string> out;
    out.push_back(pbase);
    out.push_back(proc_log_fn(get_proc_id()));
    return out;
  }
  vector<vec2i> get_mask(int cx,int cy,bool mute=false){
    static vector<vec2i> tmp;
    if(need_load_mask)QapLoadFromFile("vector_vec2i.mask",tmp);
    if(tmp.size())return tmp;
    for(int j=0;j<cy;j++)for(int i=0;i<cx;i++)qap_add_back(tmp)=vec2i(i,j);
    int n=0;
    auto ready=get_pix_info_v2_vec2i("");
    ready.clear();
    auto fn_list=get_mask_fn_list();
    QAP_FOREACH(fn_list,auto t=get_pix_info_v2_vec2i(ex);QAP_FOREACH(t,qap_add_back(ready)=ex));
    vector<int> img;img.resize(cx*cy);
    QAP_FOREACH(ready,auto id=ex.x+ex.y*cx;QapAssert(qap_check_id(img,id));img[id]++;);
    clean_if(tmp,[&](vec2i&v)->bool{auto id=v.x+v.y*cx;QapAssert(qap_check_id(img,id));return img[id];});
    if(!mute)QapUserInfo("get_mask().size() = "+IToS(tmp.size()));
    QapSaveToFile("vector_vec2i.mask",tmp);
    return tmp;
  }
public:
  void do_recovery()
  {
    if(!need_recovery)return;
    auto sm=GetScreenMode();real pn=1;
    auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);
    //int cx=2048;int cy=cx;
    auto t=get_pix_info_v2(pbase);
    if(!t.size())return;
    make_recovery(pbase,t,cx,cy);
    get_mask(cx,cy);
    if(exit_after_recovery)exit(0);
  }
  void prepare(){
    do_recovery();
    //#ifndef WIN32
    //file_put_contents("rt_proc_log_fn.txt",proc_log_fn());
    //system("chmod +x ./rt_prepare.sh;./rt_prepare.sh");
    //#endif
  }
public:
  string proc_log_fn(int num=-1){return string("p"+IToS(num<0?get_proc_id():num)+".MPLOG");}
  void writeln(const string&s){
    #pragma omp critical(writeln)
    {
      static auto*f=fopen(proc_log_fn().c_str(),"ab");
      QapAssert(f);
      fwrite(s.c_str(),sizeof(char),s.size(),f);
      fflush(f);
      on_write_rec(s);
    }
  }
  /*struct t_log{
    vec3f pos;
    vec3f dir; // dir == n;  auto n=(arr[0].pos-log.pos).Norm();
    vec2d wh; // proj.get_wh();
    real zn; // proj.zn
    vector<vec2i> mask;
  };*/
  
  struct t_proj_info{
    #define DEF_PRO_CLASSNAME()t_proj_info
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec3f,pos,$)\
    ADD(vec3f,dir,$)\
    ADD(vec2d,wh,$)\
    ADD(real,zn,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  #include "vertex_light_scope.inl"
  #include "draw_obj.inl"
  int get_proc_id(){return proc_id;}
  int get_raymaps_limit(){return raymaps_limit;}
  string get_rayenv_fn(int limit){
    string fn="rayenv_L"+IToS(limit)+"_scene_v"+IToS(scene_version)+".bin";//fn="rayenv_L64_just_cube.bin";
    return fn;
  }
  string get_obj_fn(){return obj_fn;}
  #define QAP_CLI_ARGS(F)\
    F(string,pbase,"pbase.MPLOG","-pb")\
    F(string,obj_fn,"tb5.obj","-pb")\
    F(bool,need_recovery,true,"-r")\
    F(bool,need_load_mask,false,"-need_load_mask")\
    F(bool,exit_after_recovery,false,"-rexit")\
    F(int,proc_id,800,"-id")\
    F(int,raymaps_limit,64,"-limit")\
    F(int,scene_version,42,"-scene_version")\
    F(int,server_port,45631,"-server_port")\
    F(bool,run_server,true,"-run_server")\
    F(int,pixels_per_ray_number,1,"-pn")\
    F(bool,need_two_bounce,true,"-need_two_bounce")\
    F(bool,force_writeln,false,"-force_writeln")\
  // QAP_CLI_ARGS
  #define F(TYPE,NAME,VALUE,LIST)TYPE NAME;
  QAP_CLI_ARGS(F);
  #undef F
  void initargs(){
    #define F(TYPE,NAME,VALUE,LIST)key2arg(#NAME)->sync(NAME,VALUE);
    QAP_CLI_ARGS(F);
    #undef F
  }
  void main()
  {
    QapUserInfo("qap_ray_tracing_engine v1.0 // $build_timestamp");
    initargs();
    if(run_server){p_urs_port=&server_port;on_start();}
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
    int msaa_q=8*0;bool only_edges=0||msaa_q;bool only_colorless_edges=false;//bool subpixel=msaa_q;
    real pn=pixels_per_ray_number;bool two_bounce=need_two_bounce;bool need_writeln=two_bounce|force_writeln;
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

    #include "pixel_algo.inl"

    //auto&mask=log.mask;int mask_size=mask.size();

    //for(int mask_id=0;mask_id<mask_size;mask_id++)f(mask[mask_id].y,mask[mask_id].x);
    QapUserInfo("before get_mask");
    auto mask=get_mask(cx,cy);int mask_size=mask.size();
    QapUserInfo("after get_mask");
    auto cur_num_of_cores=5;
    auto ncpu=4+5+5+2+2;
    
    QapUserInfo("mask_size = "+IToS(mask_size));
    
    real mask_id_pos=SToF(file_get_contents("mask_id_pos.txt"));
    QapUserInfo("mask_id_pos = "+FToS(mask_id_pos));
    if(mask_id_pos<0)mask_id_pos=0;
    QapUserInfo("mask_id = "+IToS(int(mask_id_pos*mask_size)));
    #pragma omp parallel for schedule(dynamic,16)
    for(int mask_id=int(mask_id_pos*mask_size);mask_id<mask_size;mask_id++)f(mask[mask_id].y,mask[mask_id].x);// if(proc_id%2==mask_id%2) ... 
    
    //#pragma omp parallel for schedule(dynamic,8)
    //for(int i=485;i<cy;i++)for(int j=0;j<cx;j++)f(i,j);
    
    //QapSaveToFile("frags.bin",frags);
    render(cx,cy,frags,("p"+IToS(get_proc_id())+"pn"+IToS(pn)+"_msaa"+IToS(msaa_q)+"_tb"+IToS(two_bounce)+"e"+IToS(only_edges)+".png").c_str());
  }
  void render(int cx,int cy,const vector<vec3d>&frags,const char*fn){
    //frags.clear();QapLoadFromFile("frags.bin",frags);
    static const real inv_gamma=1.0/2.2;
    auto arr=frags;
    QAP_FOREACH(arr,ex=vec3d_pow(ex,inv_gamma));
    arr=do_clamp_upper_bound(do_clamp_bottom_bound(arr));
    arr=hdr_pixmap(arr,0.0,255.0);
    vector<QapColor> out;out.resize(cx*cy);
    QAP_FOREACH(arr,out[i]=QapColor(ex.x,ex.y,ex.z));
    foo(cx,cy,out,fn);
  }
  void render_raw(int cx,int cy,const vector<vec3d>&frags,const char*fn){
    vector<QapColor> out;out.resize(cx*cy);
    QAP_FOREACH(frags,out[i]=QapColor(ex.x,ex.y,ex.z));
    foo(cx,cy,out,fn);
  }
  //#ifndef WIN32
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
  //#else
  //void foo(int cx,int cy,const vector<QapColor>&frags,...){}
  //#endif
};

#ifdef WIN32
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  int s=sizeof(void*);
  t_app app;
  app.main();
  return 0;
}
#else
int main(int argc,const char**argv){
  t_app app;
  for(int i=0;i<argc;i++)app.addarg(argv[i]);
  app.main();
  //app.render(192*2,120*2);
  return 0;
}
#endif
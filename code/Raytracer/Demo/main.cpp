#include "QapLite.h"
#include <io.h>
#include "img_loader_main.inl"
#include "TQapGameV2.inl"
#include <atomic>
//#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\d3dx9.h"
//#pragma comment(lib,"C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86\\d3dx9.lib")

vec3f vec3f_ex(float x,float y,float z){vec3f tmp(x,y,z);return tmp;}

#define QapKbOnDownDoInvFlag(FLAG,KEY,VALUE)(add_kb_flag(FLAG)->update(KEY,VALUE))
class TGame:public TQapGameV2{
public:
  static const int pixels_per_revolution=1024;
public:
  //TGame(){SetCursorPos(GetScreenMode().W/2,GetScreenMode().H/2);restart();}
  void restart(){
  }
  TLoaderEnv Env;
  ImgLoader::TextureMemory mem;
  void init()
  {
    static bool once=false;
    if(once)return;
    once=true;
    Env.LoadTextureFromFile(mem,"so_old/world.png");
  }
public:
  bool prev_set_mpos_failed=true;
  void DoMove()
  {
    QAP_FOREACH(kb_flags,if(kb.OnDown(ex.key))inv(ex.flag));
    if(kb.OnDown('O')){inv(space);}
    if(kb.OnDown('R')){restart();}
    if(kb.OnDown('L')){inv(light);}
    if(QapKbOnDownDoInvFlag("use_buff",'B',false))our_mat_buff=get_matrics();
    if(kb.OnDown('G')){our_mat_buff=get_matrics();}
    for(int i=1;i<=9;i++)if(kb.OnDown('0'+i)){/*speed=i;if(i>7)*/speed=1<<(i-1);}
    //if(kb.OnDown('M')){speed=}
    auto sm=GetScreenMode();
    if(space)
    {
      tick++;
      ShowCursor(QapKbOnDownDoInvFlag("show_cursor",VK_DELETE,false));
      zoom+=Sign(win.zDelta)*0.1;
      zoom=Clamp<real>(zoom,0.1,4);
      //
      auto dp=vec3f(0,0,0);
      auto dir_x=vec3f(1,0,0)*RotateY(ang_x+PiD2);
      auto dir_z=vec3f(1,0,0)*(QapKbOnDownDoInvFlag("fly",'F',true)?RotateZ(ang_y):Identity4())*RotateY(ang_x);
      auto dir_y=vec3f(0,1,0);
      #define F(dir,key_a,key_b)if(kb.Down[key_a]||kb.Down[key_b]){dp+=dir;}
      F(-dir_x,VK_LEFT,'A');
      F(+dir_x,VK_RIGHT,'D');
      F(+dir_z,VK_UP,'W');
      F(-dir_z,VK_DOWN,'S');
      F(+dir_y,VK_SHIFT,VK_SPACE);
      F(-dir_y,VK_CONTROL,'X');
      #undef F
      //
      auto mpos_y_backup=mpos.y;
      bool fail=GetForegroundWindow()!=win.Form.WinPair.hWnd;
      if(!fail)
      {
        auto g_center=vec2i(sm.W/2,sm.H/2);
        auto center=win.screen2client_mouse_pos(g_center);
        auto new_mpos=prev_set_mpos_failed?center:win.unsafe_GetMousePos();
        mpos+=new_mpos-center;
        SetCursorPos(g_center.x,g_center.y);
        prev_set_mpos_failed=false;
        auto pixels_per_revolution=1024*1.5;

        ang_x=+mpos.x*(Pi2/pixels_per_revolution);
        auto backup=ang_y;
        ang_y=+mpos.y*(Pi2/pixels_per_revolution);
        if(ang_y>PiD2){ang_y=backup;mpos.y=mpos_y_backup;}
        if(ang_y<-PiD2){ang_y=backup;mpos.y=mpos_y_backup;}
        auto spd_k=0.01*speed*(QapKbOnDownDoInvFlag("ALT",VK_MENU,false)?0.1:1);
        auto dpos=dp.Norm()*spd_k;
        pos+=dpos;
        static auto v=vec3f(0,0,0);
        struct t_world{
          struct t_demping_law{
            vec3d use(vec3d v){return v*0.001;}
          };
          struct t_grav_law{
            vec3d g=vec3d(0,-1,0);
            vec3d use(vec3d v){return v+g;}
          };
          struct t_plane{
            vec3d p,n;
          };
          vec3d pos,v;
          vector<t_plane> planes;
          struct t_cmds{
            struct t_mov{vec3d dv;};
          };
          void use(t_cmds::t_mov&ref){}
          void step(){}
        };
        auto to3d=[](vec3f pos){return vec3d(pos.x,pos.y,pos.z);};
        auto to3f=[](vec3d pos){return vec3f(pos.x,pos.y,pos.z);};
        t_world w;
        w.pos=to3d(pos);
        w.v=to3d(v);
        w.use(t_world::t_cmds::t_mov{to3d(dpos)});
        w.step();
        pos=to3f(w.pos);
        v=to3f(w.v);
        if(!need_init_env_at_start){
          if(QapKbOnDownDoInvFlag("SHIFT",VK_SHIFT,false))
          {
            auto up=vec3f(0,1,0);
            real unit_r=std::max(spd_k,0.128);//spd_k;QapDebugMsg("spd_k="+std::to_string(spd_k));
            pos+=-up*spd_k*0.5;
            static vector<vec3f> dirs;
            t_sphere_n::get_impl(dirs,20);
            vec3f force=vec3f(0,0,0);int hits=0;
            real t=1e9;
            for(auto&dir:dirs){
              t_photon p;
              p.pos=pos;
              p.dir=dir;//-up;//get_view_dir();
              auto rp=do_raycast_fixed(p,nullptr);
              if(rp.t<0)continue;
              t=std::min<real>(t,rp.t);
              if(rp.t>unit_r)continue;
              //force+=-dir;
              force+=-rp.n*(unit_r-rp.t)*dot(dir,rp.n);
              pos+=force;
              //hits++;
            }
            if(hits){
              //pos+=force*(1.0/hits);
            }
          }
        }
      }else{
        prev_set_mpos_failed=true;
        int gg=1;
      }
    }
    if(kb.Down[VK_ESCAPE])win.Close();
    if(!need_init)return;
    need_init=false;
    SetCursorPos(sm.W/2,sm.H/2);
    mpos=vec2i_zero;
    mpos.x=pixels_per_revolution/4;
  }
  struct t_sphere{
    vec3d pos;
    real r;
  };
  struct t_edge{
    vec3d a,b;
    real r;
  };
  struct t_user_sphere:t_sphere{
    vec3d new_pos;
    bool cd_upd(const t_sphere&ref){
      auto dd=(pos-ref.pos).SqrMag();
      if(dd>sqr(r+ref.r))return false;
      
    }
    bool cd_upd(const t_edge&ref){
      #define VAR(V,EXPR)auto&V##_full=(EXPR);if((V##_full).SqrMag()<eps)return false;auto&V=V##_full.Norm();
      auto&a=ref.a;auto&b=ref.b;auto&c=pos;auto eps=1e-12;
      /*
        b
        ^  .c
        | /
        |/
        +---->cn
        a
      */
      VAR(ac,c-a);
      VAR(ab,b-a);
      VAR(az,cross(ab,ac));
      VAR(cn,cross(ab,-az));
      auto x=dot(ac,cn);
      auto y=dot(ac,ab);
      if(y<0||sqr(y)>ab_full.SqrMag())return false;
      if(x>r+ref.r)return false;
      new_pos=a+ac*y+cn*(r+ref.r);
      return true;
      #undef VAR
    }
    struct t_ray{vec3d pos;vec3d dir;};
    bool cd_ray2sphere(vec3d&out,const t_ray&ray,const t_sphere&sphere){
      auto p=ray.pos;auto dir=ray.dir;
      auto s=sphere.pos;auto r=sphere.r;
      auto ps=s-p;
      auto psx=dot(ps,dir.Norm());
      auto sqr_psy=ps.SqrMag()-sqr(psx);
      if(sqr_psy<0)return false;
      auto sqr_ry=sqr_psy;
      auto sqr_rx=sqrt(sqr(r)-sqr_ry);
      if(sqr_rx)return false;
      auto rx=sqrt(sqr_rx);
      out=s+(psx-rx)*dir.Norm();
      return true;
    }
  };
  struct t_mesh_2d{
    vector<vec2d> VA;
    vector<int> IA;
  };
  //(const vector<vec2d>&PA)
  struct t_quad_inv{
    int a=0,b=0,c=0,d=0;
  };
  struct t_extrude_dev{
    vector<t_quad_inv> quads;
  };
  template<class FUNC>
  void mk_extrude_surface_ia(int n,FUNC&&AddQuadInv){
    if(n<3)return;
    for(int i=0;i<n;i++)
    {
      int a=n*0+(i+1)%n;
      int b=n*0+(i+2)%n;
      //
      int c=n*1+(i+1)%n;
      int d=n*1+(i+2)%n;
      AddQuadInv(a,b,d,c);
    }
  }
  vector<vec2d> mk_circle(int n=16,real r=1.0,real ang=0.0){
    vector<vec2d> out;out.resize(n);
    for(int i=0;i<n;i++){
      out[i]=Vec2dEx(ang+Pi2*(real(i)/real(n)),r);
    }
    return out;
  }

  void DrawCylinder(const vec3f&pos,real z,real r,int seg,real ang,bool full=true){
    auto PA=mk_circle(seg,r,ang);
    auto vp=qDev.VPos;
    /*
    VA=to3D(PA);
    AddVA(VA);
    AddVA(mov(VA,z));
    mk_extrude_surface_ia(seg,[&](int a,int b,int c,int d){
      qDev.AddQuadInv(vp,a,b,c,d);
    });
    */
  }
  void foobar(){
    /*
      FORN(i,10)quads[i]=mk_random_quad();
      t_mesh_2d mesh2d=boolean_join(quads);
      t_mesh_3d mesh3d=extrude(m);
      ...
      extract_2d_geom(image_2d);
      voxs=extrude_in_3d(image_2d);
      mesh_3d=extract_3d_geom(voxs);
      
    */
  }
  struct TOurMatrics{
    #define DEF_PRO_CLASSNAME()TOurMatrics
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(QapMat4,proj,$)\
    ADD(QapMat4,world,$)\
    ADD(QapMat4,view,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  void clear()
  {
    D9Dev.Clear3D(1?0xffc8c8c8:0xff000000);
  }
  vec3f get_view_dir(){
    auto c=(PiD2)*0.95;
    if(ang_y>c){
      ang_y=c;
    }
    if(ang_y<-c){
      ang_y=-c;
    }
    return vec3f(1,0,0)*RotateZ(ang_y)*RotateY(ang_x);
  }
  TOurMatrics get_matrics()
  {
    TOurMatrics out;
    auto new_mat=[](const vec3f&ox,const vec3f&oy,const vec3f&oz)
    {
      #define F(ot)ot.x,ot.y,ot.z,0,
      return QapMat4(
        F(ox)
        F(oy)
        F(oz)
        0,0,0,1
      );
      #undef F
    };
    auto rot=[&new_mat](const vec3f&dir)->QapMat4
    {
      auto nx=dir;
      vec3f up=get_updir(dir);
      auto nz=dir.cross(up);
      auto ny=nz.cross(dir);
      auto out=new_mat(nx,ny,nz);
      return out;
    };
    vec3f eye(0,1,-5);
    vec3f at (0,1,0);
    vec3f up (0.0f, 1.0f,  +0.0f);
    if(space)
    {
      eye=pos;
      auto dpos=get_view_dir();
      at=pos+dpos;
    }
    out.view=MatrixLookAtLH(eye,at,up);
    if(kb.Down('Q')){pos=vec3f(0,0,-0.5);}
    out.proj=get_our_proj().get_mat();
    out.world=Identity4();
    if(!space)
    {
      float t = 0.0f;
      //if(0)
      {
        static DWORD dwTimeStart = 0;
        DWORD dwTimeCur = GetTickCount();
        if( dwTimeStart == 0 )
            dwTimeStart = dwTimeCur;
        t = ( dwTimeCur - dwTimeStart ) / 2000.0f;
      }
      out.world=RotateY(t);
    }
    if(QapKbOnDownDoInvFlag("bg_scene",'P',false))
    {
      float t = 0.0f;
      //if(0)
      {
        static DWORD dwTimeStart = 0;
        DWORD dwTimeCur = GetTickCount();
        if( dwTimeStart == 0 )
            dwTimeStart = dwTimeCur;
        t = ( dwTimeCur - dwTimeStart ) / 2000.0f;
      }
      vec2d d=Vec2dEx(t,0.2);
      out.world=RotateY(d.x);
    }
    return out;
  }
  struct t_perspective_proj{
    vec2i s;
    real fovy;
    real aspect;
    real zn;
    real zf;
    QapMat4 get_mat()const{return MatrixPerspectiveFovLH(fovy,aspect,zn,zf);}
    vec2d get_wh()const{
      auto h=zn*tan(fovy*0.5);
      return vec2d(aspect*h,h);
    }
    t_perspective_proj zn_mul(real k)const{auto out=*this;out.zn*=k;return out;}
  };
  t_perspective_proj get_our_proj()
  {
    t_perspective_proj out;
    auto s=win.GetClientSize();
    out.s=s;
    out.fovy=0?20.55*2*Pi/180:Pi*70/180;//20.55*2*Pi/180;
    out.aspect=s.x/float(s.y);
    out.zn=1.0/64;
    out.zf=speed<10?64:(speed+1)*64;
    return out;
  }
  void SetMatrix()
  {
    auto our=get_matrics();
    auto*pDev=this->D9Dev.pDev;
    pDev->SetTransform(D3DTS_PROJECTION,&our.proj);
    pDev->SetTransform(D3DTS_VIEW,&our.view);
    pDev->SetTransform(D3DTS_WORLD,&our.world);
  }
  void DrawCubeMono(const vec3f&offset,const QapColor&color,const vec3f&scale=vec3f(1,1,1))
  {
    qDev.SetColor(color);
    qDev.DrawCubeFast(offset,scale*2.0);
  }
  void DrawTubeWithWire(const vec3f&pos,real z_len=0.5,real r=1.0,real dr=0.4,int seg=32,real vls=0.025,const QapColor&wire_olor=0xff000000)
  {
    auto dpos=vec3f(0,0,z_len*0.5);
    qDev.DrawTube(pos,z_len,r,dr,seg,0);
    qDev.SetColor(wire_olor);
    auto ls=vls;//volume line size
    qDev.DrawTube(pos+dpos,ls,r+dr*0.5,ls,seg,0);
    qDev.DrawTube(pos-dpos,ls,r+dr*0.5,ls,seg,0);
    qDev.DrawTube(pos+dpos,ls,r-dr*0.5,ls,seg,0);
    qDev.DrawTube(pos-dpos,ls,r-dr*0.5,ls,seg,0);
  }
  vec3f get_size_of_cube(const vec3f&a,const vec3f&b,real ws)
  {
    auto c=(a+b)*0.5;
    auto d=a-b;auto m=d.Mag()*0.5;
    d.x=abs(Sign(d.x));d.y=abs(Sign(d.y));d.z=abs(Sign(d.z));
    vec3f out=ws*(vec3f_one-d)+d*(m+ws);
    return out;
  }
  void DrawCubeOnlyWire(const vec3f&offset,const vec3f&scale=vec3f(1,1,1),real ws=0.1)
  {
    QapDev::BatchScope scope(qDev);
    vec2i arr[]={vec2i(-1,-1),vec2i(+1,-1),vec2i(+1,+1),vec2i(-1,+1)};
    auto f=[&](const vec3f&a,const vec3f&b)
    {
      auto c=(a+b)*0.5;
      auto cs=get_size_of_cube(a,b,ws);
      DrawCubeMono(c,qDev.color,cs);
    };
    for(int i=0;i<4;i++)
    {
      auto a0=QapDev::toVec3f(arr[(i+0)%4],-1).RawMul(scale)+offset;
      auto b0=QapDev::toVec3f(arr[(i+1)%4],-1).RawMul(scale)+offset;
      auto a1=QapDev::toVec3f(arr[(i+0)%4],+1).RawMul(scale)+offset;
      auto b1=QapDev::toVec3f(arr[(i+1)%4],+1).RawMul(scale)+offset;
      f(a0,b0);
      f(a1,b1);
      f(a0,a1);
    }
  }
  void DrawCubeMonoWithWire(const vec3f&offset,const QapColor&color,const vec3f&scale=vec3f(1,1,1),real ws=0.1)
  {
    DrawCubeMono(offset,color,scale);
    qDev.SetColor(0xff000000);
    DrawCubeOnlyWire(offset,scale,ws);
    return;
  }
  void DrawVoxPlane(int cx,int cy,real scale,real offset_y=-1.575)
  {
    QapDev::BatchScope scope(qDev);
    for(int i=0;i<cy;i++)
    {
      for(int j=0;j<cx;j++)
      {
        qDev.color=(i+j)%3?0xff404040:0xff505050;
        qDev.DrawQuad(vec2i(i,j)*scale,scale,scale);
      }
    }
    return;
    auto vp=qDev.VPos;
    for(int i=0;i<cy;i++)
    {
      for(int j=0;j<cx;j++)
      {
        auto&v=qDev.AddVertexRaw();
        auto&p=v.get_vec3f();
        float&x=p.x;
        float&y=p.y;
        float&z=p.z;
        z=float(i)*1.0/float(cy-1)-0.5;
        x=float(j)*1.0/float(cx-1)-0.5;
        y=offset_y/scale;
        p*=scale;
        v.color=(i+j)%2?0xff000000:0xffffffff;
      }
    }
    for(int i=1;i<cy;i++)
    {
      for(int j=1;j<cx;j++)
      {
        int o=(i-1)*cx;
        int a=o+j-1;
        int b=o+j-0;
        int c=a+cx;
        int d=b+cx;
        qDev.AddQuad(vp,a,b,d,c);
      }
    }
    int gg=1;
  }
  void DrawPlane(int cx,int cy,real scale,real offset_y=-1.575)
  {
    return;
    QapDev::BatchScope scope(qDev);
    auto vp=qDev.VPos;
    for(int i=0;i<cy;i++)
    {
      for(int j=0;j<cx;j++)
      {
        //auto t=vec2f(float(j)*1.0/float(cx-1),float(i)*1.0/float(cy-1));
        auto&v=qDev.AddVertexRaw();
        auto&p=v.get_vec3f();
        float&x=p.x;
        float&y=p.y;
        float&z=p.z;
        z=float(i)*1.0/float(cy-1)-0.5;
        x=float(j)*1.0/float(cx-1)-0.5;
        y=offset_y/scale;
        p*=scale;
        v.color=qDev.color;//QapColor::Mix(qDev.color,0xff000000,(p-pos).SqrMag()*0.05);
        //{float rnd=0.01*float(rand())/float(RAND_MAX);x+=rnd;}
        //{float rnd=0.01*float(rand())/float(RAND_MAX);z+=rnd;}
        y+=0.4*((i+j)%3);
      }
    }
    for(int i=1;i<cy;i++)
    {
      for(int j=1;j<cx;j++)
      {
        int o=(i-1)*cx;
        int a=o+j-1;
        int b=o+j-0;
        int c=a+cx;
        int d=b+cx;
        qDev.AddQuad(vp,a,b,d,c);
      }
    }
    int gg=1;
  }
  void DrawXYZ()
  {
    QapColor colors[]={0xffff0000,0xff00ff00,0xff0000ff};
    vec3f vecs[]={vec3f(1,0,0),vec3f(0,1,0),vec3f(0,0,1)};
    real size=0.10;
    qDev.SetColor(0xff000000);
    qDev.DrawCube(vec3f(0,0,0),size);
    {
      int seg=8; int cn=4; real length=3.0; real ls=0.25*size;
      for(int i=0;i<3;i++)
      {
        auto dir=vecs[i];
        //qDev.SetColor(colors[i]);
        //qDev.DrawCube(dir*size,size*0.5);
        //qDev.DrawCube(dir*1,size*0.5);
        //qDev.DrawCube(dir*2,size*0.5);
        qDev.SetColor(QapColor::HalfMix(colors[i],0xff000000));
        for(int t=1;t<3*5;t++)
        {
          auto p=dir*(t*0.2);
          if(0==t%5)qDev.DrawCube(p,size*0.5);
          if(0!=t%5)qDev.DrawCube(p,size*0.3);
        }
        qDev.SetColor(colors[i]);
        //qDev.DrawSphere(dir*1,size*0.5,seg,cn);
        //qDev.DrawSphere(dir*2,size*0.5,seg,cn);
        qDev.DrawCube(dir*length*0.5,dir*length+vec3f_one*ls);
        qDev.SetColor(0xff000000);
        qDev.DrawCube(dir*length,size);
      }
    }
    return;
  }
  bool use_view_check;
  void DrawKastrula()
  {
    use_view_check=QapKbOnDownDoInvFlag("use_view_check",'V',false);
    int r=32;real s=8.0/real(r); auto sc=0xffb0b0b0;
    if(cubes.empty())
    {
      for(int x=-r;x<=+r;x++)for(int y=-r;y<=+r;y++)for(int z=-r;z<=+r;z++)
      {
        //if(y>r/4)continue;if(y<-r/4)continue;
        //if(z>0)continue;
        if(abs(x*x+y*y+z*z-r*r)>r-1)continue;
        //if(x*x+y*y+z*z>r*r)continue;
        cubes.push_back(vec3f(x,y,z));
      }
    }
    QAP_FOREACH(cubes,
      if(check_point(ex*s))
      {
        qDev.SetColor(int(ex.x+ex.y+ex.z)%2?0xffffffff:sc);
        //vmap.set(x,y,z,1);
        qDev.DrawCubeFast(ex*s,vec3f_one*s);
      }
    );
    if(0)for(int x=-r;x<=+r;x++)for(int y=-r;y<=+r;y++)
    {
      int g=r/4;int G=g*g;
      if(x*x+y*y>r*r)continue;if(x*x+y*y<G)continue;
      qDev.SetColor((x+y)%2?0xffffffff:sc);
      if(check_point(vec3f(x,-r/4-1,y)*s))qDev.DrawCubeFast(vec3f(x,-r/4-1,y)*s,vec3f_one*s);
    }
    
  }
  QapColor getPix(int x,int y)
  {
    auto src=((QapColor*)mem.ptr)[y*mem.W+x];
    std::swap(src.r,src.b);
    return src;
  }
  void DrawBibika()
  {
    qDev.SetColor(0xffff8000);
    auto p=this->tick*0.01;
    qDev.DrawSphereWithScale(vec3f(1+p,0,0),1,vec3f(2,1,2)*0.125,8,8);
    qDev.SetColor(0xff0000ff);
    qDev.DrawSphereWithScale(vec3f(1.25+p,0,0),1,vec3f(2,1,2)*0.125,8,8);
    //qDev.DrawSphereWithScale(vec3f(0,1,0),1,vec3f(0.500,0.125,0.500),8,8);
    //qDev.DrawSphereWithScale(vec3f(1,0,0),1,vec3f(0.125,0.500,0.500),12,8);
  }
  void DrawCellWorld()
  {
    init();
    auto sc=0xffb0b0b0; real s=0.75;
    for(int y=0;y<mem.H;y++)for(int x=0;x<mem.W;x++)
    {
      //if(x*x+y*y>r*r)continue;if(x*x+y*y<G)continue;
      //qDev.SetColor((x+y)%2?0xffffffff:sc);
      auto c=getPix(x,y);
      real z=0;
      if(c.r!=255)z=1;
      if(c.g!=255)z=1;
      if(c.b!=255)z=1;
      real sz=0+(c.r+c.g+c.b)*3.0/256.0/3.0; real sxy=1;
      if(0){
        sxy*=0.25;
        vec3f szv=vec3f(sxy,sz*2.0,sxy);
        qDev.color=c;
        qDev.DrawCubeFast(vec3f(-x+mem.W/2,-3+z*1.25,y-mem.H/2)*s,szv*s);
        continue;
      }
      //if(c.r==128)if(c.g==128)if(c.b==128){sz=0.5;z=0.75;}
      //if(z!=0){sxy=0.75;sz=0.75;}
      //if(!z)continue;
      if(z!=0)
      {
        qDev.color=0xffffffff;
        qDev.DrawCubeFast(vec3f(-x+mem.W/2,-3,y-mem.H/2)*s,vec3f_one*s);
      }
      vec3f szv=vec3f(sxy,sz,sxy);
      qDev.color=c;
      bool gneed=false;//true;
      if(c.r==128)if(c.g==128)if(c.b==128)gneed=false;
      if(z){
        if(gneed){
          qDev.DrawSphere(vec3f(-x+mem.W/2,-3+z*1.25,y-mem.H/2)*s,s*0.5,12,12);szv*=0;
          //gneed=false;
        }
      }
      if(z)
      {
        if(!gneed)qDev.DrawCubeFast(vec3f(-x+mem.W/2,-3+z*1.25,y-mem.H/2)*s,vec3f_one*s*0.85);
        bool need=true;
        if(c.r==128)if(c.g==128)if(c.b==128)need=false;
        if(need)
        {
          auto ns=vec3f_one*s*0.2;
          ns.y=3;
          qDev.color=QapColor::Mix(c,0xFF000000,0.125);
          for(int i=0;i<1;i++)qDev.DrawCubeFast(vec3f(-x+mem.W/2,-3+z*1.25+ns.y*1.25*1.1*i,y-mem.H/2)*s,ns);
        }
        qDev.color=QapColor::Mix(c,0xFF000000,0.5);
      }
      qDev.DrawCubeFast(vec3f(-x+mem.W/2,-3+z,y-mem.H/2)*s,szv*s);
    }
    qDev.color=0xffffffff;
  }
  bool check_point(const vec3f&point)
  {
    if(!use_view_check)return true;
    auto our=our_mat_buff;
    auto p=point*our.world*our.view*our.proj;
    if(p.z<1)for(;;)
    {
      if(p.x<-1)break;if(p.x>+1)break;
      if(p.y<-1)break;if(p.y>+1)break;
      return true;
      break;
    }
    return false;
  }
  static vec3f mirror(vec3f nn,vec3f light_dir)
  {
    auto v=cross(nn,light_dir);
    //auto m=sqrt(dot(v,v));
    //return light_dir+nn*2*sqrt(1-m*m);
    return light_dir+nn*2.0*sqrt(1-dot(v,v));
  }
  static real rnd(){return rand()/real(RAND_MAX);};
  static real rndreal(real min,real max){return min+rnd()*(max-min);}
  struct t_link{
    #define DEF_PRO_CLASSNAME()t_link
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,a,$)\
    ADD(int,b,$)\
    ADD(real,dist,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_ball{
    #define DEF_PRO_CLASSNAME()t_ball
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec3f,pos,$)\
    ADD(vec3f,v,$)\
    //===
    #include "defprovar.inl"
    //===
    void init(){
      real n=1;
      #define $ rndreal(-n,+n)
      pos=vec3f($+3,n+2+$,$+3);
      n=0.003;
      v=vec3f($,$,$);v=vec3f(0,0,0);
      #undef $
    }
  };
  struct t_phys_sphere{
    #define DEF_PRO_CLASSNAME()t_phys_sphere
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_ball>,balls,$)\
    ADD(vector<int>,IA,$)\
    //===
    #include "defprovar.inl"
    //===
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
    vector<int> get_tris_list(...)
    {
      vector<int> out;
      auto&arr=balls;auto O=vec3f(0,0,0);
      QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
      //bool full=kb.Down(VK_MENU);
      for(int i=0;i<arr.size();i++)for(int j=i+1;j<arr.size();j++)for(int g=j+1;g<arr.size();g++)
      {
        #define F(a,offset,A)int a=(0+offset)%arr.size();auto&A=arr[a].pos;
        F(a,i,A);
        F(b,j,B);
        F(c,g,C);
        #undef F
        auto center=(A+B+C)*(1.0/3.0);
        auto n=cross(B-A,C-A).Norm();
        /*if(!full)*/if(fabs(dot(n,(O-center).Norm()))<(1.0/512))continue;
        //auto plane=make_plane(center,n);
        int t[3]={0,0,0};
        for(int k=0;k<arr.size();k++)if(k!=a)if(k!=b)if(k!=c){
          auto&ex=arr[k];
          t[int(Sign(dot(n,ex.pos-center))+1)]++;
        }
        if(!t[0]||!t[2])
        {
          bool dir=dot(n,O-center)>0;
          if(!dir)std::swap(a,b);
          out.push_back(a);
          out.push_back(b);
          out.push_back(c);
          //break;
        }
      }
      return out;
    }
    void fix_small_holes()
    {
      vector<vector<int>> edges;edges.resize(balls.size());
      for(int i=2;i<IA.size();i+=3){
        auto a=IA[i-2];
        auto b=IA[i-1];
        auto c=IA[i-0];
        bool found=false;
        found=found||qap_includes(edges[a],b);
        found=found||qap_includes(edges[b],c);
        found=found||qap_includes(edges[c],a);
        if(found)continue;
        qap_add_back(edges[a])=b;
        qap_add_back(edges[b])=c;
        qap_add_back(edges[c])=a;
      }
      vector<vec2i> skipped;
      vector<vector<int>> sarr;sarr.resize(balls.size());
      for(int j=0;j<edges.size();j++){auto&ey=edges[j];for(int i=0;i<ey.size();i++){
        auto&ex=ey[i];
        if(qap_includes(edges[ex],j))continue;
        qap_add_back(skipped)=vec2i(j,ex);
        qap_add_back(sarr[j])=ex;
      }}
      {
        vector<int> out;auto add=[&](int a,int b,int c){
          qap_add_back(out)=b;
          qap_add_back(out)=a;
          qap_add_back(out)=c;
        };
        for(int j=0;j<sarr.size();j++){
          auto&a=sarr[j];
          for(int i=0;i<a.size();i++){
            auto&ex=a[i];
            #define F(ex,next,end)if(ex<0)continue;auto&next=sarr[ex];QapAssert(next.size()==1);auto&end=next[0];
            //if(ex<0)continue;auto&next=sarr[ex];QapAssert(next.size()==1);auto&end=next[0];
            //if(end<0)continue;auto&ea=sarr[end];QapAssert(ea.size()==1);auto&e=ea[0];
            F(ex,next,end);
            F(end,ea,e);
            if(e<0)continue;
            if(e!=j){
              QapDebugMsg("look like quad, ok, try do one more step");
              F(e,e2q,q);
              if(q<0)continue;
              if(q!=j){QapDebugMsg("no way, but, lol, still need one more step?");continue;}
              add(j,ex,end);
              add(end,e,j);
              ex=-1;
              end=-1;
              e=-1;
              q=-1;
              continue;
            }
            #undef F
            add(j,ex,end);
            ex=-1;
            end=-1;
            e=-1;
          }
        }
        IA+=std::move(out);
        int gg=1;
      }
    }
    vector<int> get_fast_tris_list(...)
    {
      vector<vector<int>> edges;edges.resize(balls.size());
      vector<int> out;
      auto&arr=balls;auto O=vec3f(0,0,0);
      if(arr.size()<2)return out;
      auto first_pos=arr[0].pos;
      int min_r_id=QAP_MINVAL_ID_OF_VEC(arr,!i?1e42:(ex.pos-first_pos).SqrMag());
      real opt_k=1;
      auto max_r=(arr[min_r_id].pos-first_pos).Mag()*1.75*opt_k;
      auto max_r3=max_r*3*opt_k;
      QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
      //bool full=kb.Down(VK_MENU);
      for(int i=0;i<arr.size();i++)
      {
        #define F(a,offset,A)int a=(0+offset)%arr.size();auto&A=arr[a].pos;
        F(a,i,A);
        for(int j=i+1;j<arr.size();j++)
        {
          F(b,j,B);
          if(fabs(A.x-B.x)>max_r)continue;
          if(!A.dist_to_point_less_that_r(B,max_r))continue;
          for(int g=j+1;g<arr.size();g++)
          {
            F(c,g,C);
            if(fabs(A.x-C.x)>max_r)continue;
            if(fabs(B.x-C.x)>max_r)continue;
            if(!A.dist_to_point_less_that_r(C,max_r))continue;
            if(!B.dist_to_point_less_that_r(C,max_r))continue;
            auto center=(A+B+C)*(1.0/3.0);
            auto n=cross(B-A,C-A).Norm();
            real fabs_val=fabs(dot(n,(O-center).Norm()));
            if(fabs_val<(1.0/7)){/*QapDebugMsg("some shit skipped\n fabs_val*1e9 = "+FToS(fabs_val*1e9));*/continue;}
            int t[3]={0,0,0};
            for(int k=0;k<arr.size();k++)if(k!=a)if(k!=b)if(k!=c){
              auto&ex=arr[k];
              if(fabs(ex.pos.x-center.x)>max_r3)continue;
              if(fabs(ex.pos.y-center.y)>max_r3)continue;
              t[int(Sign(dot(n,ex.pos-center))+1)]++;
            }
            if(t[1])QapDebugMsg(
              "t[0] = "+IToS(t[0])+"\n"
              "t[1] = "+IToS(t[1])+"\n"
              "t[2] = "+IToS(t[2])+"\n"
            );
            if(!t[0]||!t[2])
            {
              bool dir=dot(n,O-center)>0;
              if(!dir)std::swap(a,b);
              bool found=false;
              found=found||qap_includes(edges[a],b);
              found=found||qap_includes(edges[b],c);
              found=found||qap_includes(edges[c],a);
              /*static int lul=0;QapDebugMsg("lul there is bug but i don't know how to fix it");
              lul++;
              if(lul==1)found=1;
              if(lul==2)found=0;*/
              if(found){if(!dir)std::swap(a,b);continue;}
              out.push_back(a);
              out.push_back(b);
              out.push_back(c);
              qap_add_back(edges[a])=b;
              qap_add_back(edges[b])=c;
              qap_add_back(edges[c])=a;
              if(!dir)std::swap(a,b);
              //break;
            }
          }
        }
        #undef F
      }
      return out;
    }
    void recalc_IA(bool fast){IA=fast?get_fast_tris_list():get_tris_list();}
    void Draw(QapDev&qDev){
      auto base=qDev.VPos;
      for(int i=0;i<balls.size();i++)qDev.AddVertex(balls[i].pos);
      for(int i=0;i<IA.size();i++)qDev.IBA[qDev.IPos++]=base+IA[i];
    }
  };
  void rq(){qDev.color=0xFF404040;}
  static void inv(bool&ref){ref=!ref;}
  #include "vertex_light_scope.inl"
  void DrawLightedSphereV2(...)
  {
    int ipos=qDev.IPos;int beg=qDev.VPos;static auto bp=pos;if(!light)bp=pos;auto pos=bp;
    
    DrawCoolSphere();

    if(phys_sphere.IA.empty())return;

    auto&arr=phys_sphere.balls;auto O=vec3f(0,0,0);
    QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
    auto center=O;
    
    vec3f lightpos(0,0,3);
    auto c=0.05;
    for(int i=beg;i<qDev.VPos;i++)
    {
      auto&v=qDev.VBA[i];
      auto&p=v.get_vec3f();
      auto dir=p-pos;
      auto n=p-center;
      auto k=dot(-dir.Norm(),n.Norm());if(k<0)k=0;if(k>1)k=1;
      v.color=QapColor::Mix(0xffa8a8a8,0xffffffff,k);
    }
    //DrawRayCastSphere(ipos+2);
  }
  int debug_phys_sphere_ipos=0;
  void DrawCoolSphere(){
    qDev.color=0xFF000000;
    if(kb.OnDown(VK_F10))phys_sphere.IA.clear();
    if(kb.OnDown(VK_F7))phys_sphere.recalc_IA(!kb.Down(VK_F2));
    if(kb.OnDown(VK_PAUSE))phys_sphere.fix_small_holes();
    //if(kb.OnDown(VK_TAB))msg="";if(kb.OnDown('I'))msg="tris = "+IToS(phys_sphere.IA.size()/3);
    debug_phys_sphere_ipos=qDev.IPos;
    if(!phys_sphere.IA.empty())phys_sphere.Draw(qDev);
  }
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
  struct t_atomic_bits{
    #define DEF_PRO_CLASSNAME()t_atomic_bits
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<uchar>,mem,$)\
    ADD(size_t,n,0)\
    //===
    #include "defprovar.inl"
    //===
    void clear(){mem.clear();n=0;}
    void resize(size_t size){mem.resize(size/8+1);n=size;}
    bool atomic_set(size_t bit_id){
      auto elem=bit_id/8;
      QapAssert(qap_check_id(mem,elem));
      auto&a=*(std::atomic<uchar>*)(void*)&mem[elem];
      auto val=a.load();
      auto mask=(1<<(bit_id%8));
      while(!a.compare_exchange_weak(val,val|mask));
      return val&mask;
    }
    template<class FUNC>
    void for_each(FUNC func){
      size_t base=0;
      for(int i=0;i<mem.size();i++){
        for(int j=0;j<8;j++)if(base+j<n)func(base+j,mem[i]&(1<<j));
        base+=8;
      }
    }
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
    ADD(vector<int>,light_dirs,$)\
    ADD(t_atomic_bits,light_dirs_bits,$)\
    //===
    #include "defprovar.inl"
    //===
    
    /*
    vec3f a;
    //vec3f b;
    //vec3f c;
    
    vec2f A;
    vec2f B;
    vec2f C;
    
    vec3f oy;/// = -n
    vec3f oz;//auto oz=(b-a).Norm();
    vec3f ox;//auto ox=cross(oz,n).Norm();
    //QapColor color;
    //std::array<float,512> dir2inv_dy;
    vector<float> dir2inv_dy;
    vector<int> dirs;
    vector<int> light_dirs_counter;
    vector<int> light_dirs;
    
    */
    vec3f normal()const{return -oy;}
  };
  /*struct t_tris_info{
    float inv_dy;
  };*/
  #define DEF_PRO_FEATURE_BEFORE
  #include "raymaps_code.inl"
  struct t_aabb{
    vec2d wh;
  };
  struct t_light_mapper_part{
    t_aabb aabb(t_trigon&t){
    }
    void add(t_trigon&t){
      aabb(t);
    }
    /*
    some where need insert this code:
    каждый треугольник заворачиваем в аабб
    аабб вставляем в атлас размером....
    короче есть атлас размером 4к на 4к.
    есть аабб, у него есть площадь 
    */
  };
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
    /*added for lightmapper*/\
    ADD(real,area,0)\
    //===
    #include "defprovar.inl"
    //===
    #define DEF_PRO_FEATURE_INSIDE
    #include "raymaps_code.inl"
  };
  #define DEF_PRO_FEATURE_AFTER
  #include "raymaps_code.inl"
  /*struct t_tris_norm_info{
    std::bitset<512> arr;
  };
  t_tris_norm_info get_tris_norm_info(int tris_id){}
  // pos=vec3f(0,0); t_trigon t;
  inline bool fast_norm_check_raycast_dir_id_to_tris_id(int tris_id,int dir_id){
    return get_tris_norm_info(tris_id).arr[dir_id];
  }*/
  t_ray_env env;
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
  void update_env_v2(int beg=2)
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
      //if(bool need_calc_inv_dy=true)
      //{
      //  auto&arr=tris.dir2inv_dy;auto&td=tris.dirs;
      //  arr.resize(dirs.size());
      //  for(int i=0;i<dirs.size();i++){auto dy=dot(tris.oy,dirs[i]);arr[i]=dy?1.0/dy:0;if(dy>0)qap_add_back(td)=i;}
      //}
    }
    for(int dir_id=0;dir_id<dirs.size();dir_id++){
      auto&Larr=qap_add_back(env.dir_id_to_Ltris_list);
      auto&Darr=qap_add_back(env.dir_id_to_Dtris_list);
      auto&dir=dirs[dir_id];
      QAP_FOREACH(env.tris,if(dot(ex.oy,dir)<0)qap_add_back(is_light(i)?Larr:Darr)=i;);
    }
    if(bool need_calc_area=true)
    {
      auto&area=env.area;
      area=0;
      QAP_FOREACH(env.tris,area+=calc_area(ex));
    }
    int gg=1;
  }
  real calc_area(t_trigon&t)
  {
    auto b=t.B-t.A;
    auto c=t.C-t.A;
    return fabs(cross(b,c)*0.5);
  }
  void update_env(int beg=2)
  {
    static bool need_calc=true;if(kb.Down(VK_MENU))need_calc=true;if(!need_calc)return;need_calc=false;
    int limit=get_raymaps_limit();
    string fn=get_rayenv_fn(limit);
    bool ok=try_load_env(fn);
    if(ok)return;
    QapDebugMsg(fn+" - not found, but ok let's generate it!");
    update_env_v2(beg);
    make_raymaps(fn,limit);
  }
  inline float fast_raycast_to_trigon(vec3f pos,int tris_id,int dir_id){
    t_raypoint nope;
    auto dir=env.dirs[dir_id];
    auto&tris=env.tris[tris_id];
    #define F(a)auto&a=tris.a;
    F(a);F(oy);F(oz);F(ox);F(A);F(B);F(C);
    #undef F
    auto py=dot(oy,pos-tris.a);
    auto inv_dy=0.0;{auto dy=dot(oy,dir);if(dy)inv_dy=1.0/dy;}
    if(!inv_dy)return -1;
    auto dist=-py*inv_dy;
    if(dist<0)return -1;
    auto point=pos+(dir*dist);
    #define F(A,a)auto A=vec2f(dot(ox,a),dot(oz,a));
    /*F(A,a);F(B,b);F(C,c);*/F(P,point);
    #undef F
    int t[3]={0,0,0};
    #define F(A,B)t[int(Sign(cross(B-A,P-A))+1)]++;
    F(A,B);F(B,C);F(C,A);
    #undef F
    if(t[0]&&t[2])return -1;
    return dist;
  }
  struct t_fast_raycast_out{float t;int id;};/*
  bool fast_do_raycast_v1(vec3f pos,int dir_id)
  {
    t_fast_raycast_out out={-1,-1};
    QapColor light_color=0xff00fe00;
    for(int kind=0;kind<2;kind++)
    {
      auto&arr=!kind?env.dir_id_to_Ltris_list[dir_id]:env.dir_id_to_Dtris_list[dir_id];
      for(int i=0;i<arr.size();i++)
      {
        int tris_id=arr[i];
        t_fast_raycast_out rp={fast_raycast_to_trigon(pos,tris_id,dir_id),tris_id};
        if(rp.t<0)continue;
        if(out.t>0&&out.t<rp.t)continue;
        if(kind&&rp.t>0&&out.t>rp.t)return false;
        out=rp;
      }
      if(out.t<=0)break;
    }
    if(out.t>0)if(env.tris_colors[out.id]==light_color)return true;
    return false;
  }
  bool fast_do_raycast_v2(vec3f pos,int dir_id,int&end_tris_id,vec3f&end_pos)
  {
    t_fast_raycast_out out={-1,-1};
    QapColor light_color=0xff00fe00;
    for(int kind=0;kind<2;kind++)
    {
      auto&arr=!kind?env.dir_id_to_Ltris_list[dir_id]:env.dir_id_to_Dtris_list[dir_id];
      for(int i=0;i<arr.size();i++)
      {
        int tris_id=arr[i];
        t_fast_raycast_out rp={fast_raycast_to_trigon(pos,tris_id,dir_id),tris_id};
        if(rp.t<0)continue;
        if(out.t>0&&out.t<rp.t)continue;
        out=rp;end_pos=pos+env.dirs[dir_id]*out.t;end_tris_id=tris_id;
      }
    }
    if(out.t>0)if(env.tris_colors[out.id]==light_color)return true;
    return false;
  }*/
  static void check(int a,int b,int c,int d){
    if(a==b)return;
    QapDebugMsg("fail\n"
      "near   =  "+IToS(a)+"\n"
      "dir_id =  "+IToS(b)+"\n"
      "tris_id = "+IToS(c)+"\n"
      "id = "+IToS(d)+"\n"
    );
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
  //old fast_do_raycast_v3
  t_lights_rays_color get_lights_rays_color_in(vec3f pos,int dir_id)
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
  t_lights_rays_color get_LC_one(...)
  {
    t_lights_rays_color out;
    out.c+=vec3d(1,1,1);
    out.n++;
    return out;
  }
  t_lights_rays_color get_LC_n(vec3f pos,int dir_id)
  {
    t_lights_rays_color out;
    auto n=env.dir2light[dir_id].safe_get(pos).size();
    if(!n){n=1;}else{n+=env.dir2info[dir_id].safe_get(pos).size();}
    out.c+=vec3d(n,n,n);
    out.n+=n;
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
        //QapAssert(!is_light(first_dtris.id));
        end_pos=pos+env.dirs[dir_id]*first_dtris.t;
        //out.c+=to_vec3d(env.tris_colors[first_dtris.id]);
        //out.n++;
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
    //auto px=d_ox.x-t*v_ox.x;
    //if(out)*out=vec2d(px,0).UnRot(ox)+a;
    //return px>0&&px<ox.Mag();
  }
  struct t_camplane{
    vec3f pos;// pos=campos+dir*zn;
    t_axis axis;
    vec3f get_vec3f(const vec3f&p){
      auto v=axis.get_vec3f(p-pos);
      //if(v.z<0)return false;
      //CD_LineVsLine(pos,p,vec2d(0,h)*0.5);
      //v.get_xy_as_vec2f()*vz;
    }
  };
  static inline t_raypoint raycast_to_trigon(const vec3f&pos,const vec3f&dir,const vec3f&a,const vec3f&b,const vec3f&c){
    //auto&cross=cross;auto&dot=dot;
    t_raypoint nope;
    auto center=a;//(a+b+c)*(1.0/3.0);
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
    #define F(A,a)auto A=vec2d(dot(ox,a),dot(oz,a));
    F(A,a);F(B,b);F(C,c);F(P,point);
    #undef F
    int t[3]={0,0,0};
    #define F(A,B)t[int(Sign(cross(B-A,P-A))+1)]++;
    F(A,B);F(B,C);F(C,A);
    #undef F
    if(t[0]&&t[2])return nope;
    t_raypoint out;out.pos=point;out.n=n;out.t=abs(py/dy);
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
  struct t_raycast_log{
    #define DEF_PRO_CLASSNAME()t_raycast_log
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_raypoint>,arr,$)\
    ADD(t_photon,inp,$)\
    ADD(vec3f,pos,$)\
    ADD(vector<QapColor>,pix,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  void run_ray(t_raycast_log&log,t_photon inp,int limit)
  {
    vector<t_raypoint>&arr=log.arr;
    log.arr.clear();auto old=inp.pos;
    for(int i=0;i<limit;i++)
    {
      auto out=do_raycast_fixed(inp);
      if(out.t<0)break;
      qap_add_back(arr)=out;
      inp.pos=out.pos;
      inp.dir=mirror(-out.n,inp.dir).Norm();
    }
    log.inp=inp;
    log.pos=old;
  }
  bool not_in_dark(const vec3f&pos,const vec3f&dir,real dist){
    t_photon inp;inp.pos=pos;inp.dir=dir;
    auto out=do_raycast_fixed(inp);
    return out.t<0||out.t>dist;
  }
  static bool CD_TrigonVsTrigon(const t_trigon_vec2f&a,const t_trigon_vec2f&b){
    #define F(field)int(PointInTrigon(a.field,b))
    if(int(F(a)+F(b)+F(c))%3!=0)return true;
    #undef F
    #define F(field)int(PointInTrigon(b.field,a))
    if(int(F(a)+F(b)+F(c))%3!=0)return true;
    #undef F
  }
  /*static bool CD_TrigonVsTrigon(const t_trigon_vec2f&t,vec2f a,vec2f b,vec2f c){
    t_trigon_vec2f tmp;tmp.a=a;tmp.b=b;tmp.c=c;
    return CD_TrigonVsTrigon(t,tmp);
  }*/
  static bool PointInTrigon(const vec2d&p,const t_trigon_vec2f&t){
    return PointInTrigon(p,t.a,t.b,t.c);
  }
  static bool PointInTrigon(const vec2d&p,const vec2d&a,const vec2d&b,const vec2d&c){
    //
  }
  static bool point_in_tris(const vec2d&p,const t_trigon_vec2f&t){return point_in_tris(t,p);}
  static bool point_in_tris(const vec2f&p,const t_trigon_vec2f&t){return point_in_tris(t,vec2d(p));}
  static bool point_in_tris(const t_trigon_vec2f&t,const vec2d&p){
    int arr[3]={0,0,0};
    #define F(a,b)arr[int(Sign(cross(vec2d(t.b-t.a),p-vec2d(t.a)))+1)]++;
    F(a,b);F(b,c);F(c,a);
    #undef F
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
      pos=vec2d(0,0);QAP_FOREACH(arr,pos+=ex);pos*=1.0/arr.size();
      auto id=QAP_MINVAL_ID_OF_VEC(arr,-(vec2d(ex)-pos).SqrMag());
      r=(vec2d(arr[id])-pos).Mag();
    }
  };
  static bool CD_TrigonVsQuad_slow(const t_trigon_vec2f&t,const t_quad&q){
    #define F(a)if(point_in_quad(t.a,q))return true;
    F(a);F(b);F(c);
    #undef F
    auto qp=q.get_points();
    #define F(a)if(point_in_tris(qp.a,t))return true;
    F(a);F(b);F(c);F(d);
    #undef F
    #define U(qa,qb,ta,tb)if(CD_LineVsLine(qp.qa,qp.qb,t.ta,t.tb))return true;
    #define F(qa,qb)U(qa,qb,a,b);U(qa,qb,b,c);U(qa,qb,c,a);
    F(a,b);F(b,c);F(c,d);F(d,a);
    #undef F
    #undef U
    return false;
  }
  static bool CD_TrigonVsQuad(const t_trigon_vec2f&t,const t_quad&q){
    auto tc=t_circle_from_points(t);
    auto qc=t_circle_from_points(q);
    auto m=(tc.pos-qc.pos).Mag();
    if(m>(tc.r+qc.r))return false;
    return CD_TrigonVsQuad_slow(t,q);
  }
  static bool CD_TrigonVsQuad(const t_trigon_vec2f_with_circle&t,const t_quad&q,real qr){
    //return CD_TrigonVsQuad(t_trigon_vec2f(t),q);
    //auto qc=t_circle_from_points(q);
    auto mm=t.p.sqr_dist_to(q.pos);//(t.p-q.pos).SqrMag();
    if(mm>sqr(t.r+qr)){
      return false;
      //auto tc=t_circle_from_points(t);
      //auto qc=t_circle_from_points(q);
      //auto m=(tc.pos-qc.pos).Mag();
      //if(m>(tc.r+qc.r))return false;
      //#define F(VAR)string(#VAR " = "+FToS(VAR)+"\n")+
      //auto msg=string(
      //  F(mm)F(sqr(t.r+qr))F(m)F((tc.r+qc.r))""
      //);
      //#undef F
      //QapDebugMsg(msg);
    }
    return CD_TrigonVsQuad_slow(t,q);
  }
  //vector<t_c
  /*void nope()
  {
    //do using raymaps
    {
      env.tris.map(e=>aabb.update(e));
      env.dirs.map
      auto&b=qap_add_back(env.dir2info);
      struct t_dir_quad{
        vec3f dir; //mean oz;
        vec3f up_dir; // mean oy;
        vec3f center;
        vec2d size;
      };
      auto dq=env.make_dir_quad(dir_id);int dq_wh=16;
      b.pos2info.init(dq_wh,dq);
      b.pos2info.map([](t_dir_x_y_info&e,int x,int y){
        // e.arr is vector<int> where int is id for trigon2d
        auto cell_quad=dq.get_subquad(dq_wh,x,y);
        e.arr=env.get_array_of_tris_for("env.tris.map(e=>auto tris=make_2d_tris(e,cell_quad);cell_quad.cd_test_vs(tris))");
      }
    }
    //do using voxels
    {
      env.photons.map(e=>e.pos+=e.v);
      env.photons.map
      e is photon
      v=env.vox[e.pos]
      v is voxel
      v.geoms.arr.map
      e is id
      t=env.tris[e]
      t is tris
      CD_TrigonVsPhoton
      
    }
    
  }*/
  static string proc_log_fn(int num=-1){return string("p"+IToS(num<0?proc_id:num)+".MPLOG");}
  static void writeln(const string&s){
    #pragma omp critical(writeln)
    {
      static auto*f=fopen(proc_log_fn().c_str(),"ab");
      QapAssert(f);
      fwrite(s.c_str(),sizeof(char),s.size(),f);
      fflush(f);
    }
  }
  static bool always_true(...){return true;}
  #define LIST(F)F(version)F(size)F(x)F(y)F(raw_wins)
  #define F(var)int var;
  struct t_pix_info{LIST(F);t_lights_rays_color frag,only_details,simple_frag;real ms;};
  #undef F
  #undef LIST
  static vector<t_pix_info> get_pix_info_v2(const string&fn)
  {
    vector<t_pix_info> out;
    auto IO=FsIO<>(fn);
    for(int i=0;i<IO.n/sizeof(t_pix_info);i++){
      t_pix_info tmp;tmp.size=0;
      IO.LoadPOD(&tmp,sizeof(tmp));
      if(tmp.size&&tmp.size!=sizeof(tmp)){QapNoWay();break;}
      out.push_back(tmp);
    }
    return out;
  }
  static string get_pbase(){return "pbase.MPLOG";}
  static void make_recovery(const vector<t_pix_info>&arr,int cx,int cy){
    vector<int> img;img.resize(cx*cy,-1);
    QAP_FOREACH(arr,auto id=ex.x+ex.y*cx;QapAssert(qap_check_id(img,id));img[id]=i;);
    vector<t_pix_info> out; 
    QAP_FOREACH(img,if(ex<0)return;qap_add_back(out)=arr[ex];);
    if(!out.size())return;
    auto*f=fopen(get_pbase().c_str(),"wb");
    QapAssert(f);
    fwrite((char*)(void*)&out[0],sizeof(char),sizeof(out[0])*out.size(),f);
    fflush(f);
    fclose(f);
  }
  void do_recovery()
  {
    if(bool no_need_recovery=false)return;
    auto sm=GetScreenMode();real pn=1;
    auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);

    auto ready=get_pix_info_v2("");ready.clear();
    auto fn_list=get_mask_fn_list();
    QAP_FOREACH(fn_list,auto t=get_pix_info_v2(ex);QAP_FOREACH(t,qap_add_back(ready)=ex));
    if(!ready.size())return;
    make_recovery(ready,cx,cy);
    get_mask(cx,cy,true);
  }
  static vector<string> get_mask_fn_list(){
    vector<string> out;
    out.push_back(get_pbase());
    out.push_back("phub.MPLOG");
    out.push_back(proc_log_fn(proc_id));
    return out;
  }
  vector<vec2i> get_mask(int cx,int cy,bool mute=false){
    static vector<vec2i> tmp;
    if(tmp.size())return tmp;
    ImgLoader::TextureMemory A;string fn="mask.png";
    Env.LoadTextureFromFile(A,fn);
    auto*a=(QapColor*)A.ptr;
    if(!(A.H==cy&&A.W==cx)){
      QapDebugMsg(fn+" - ignored due to size\nneed: "+IToS(cx)+"x"+IToS(cy));
      for(int j=0;j<cy;j++)for(int i=0;i<cx;i++)qap_add_back(tmp)=vec2i(i,j);
    }else{
      for(int j=0;j<A.H;j++)for(int i=0;i<A.W;i++){auto id=i+j*A.W;auto&c=a[id];std::swap(c.r,c.b);}
      for(int j=0;j<cy;j++)for(int i=0;i<cx;i++){
        auto id=i+j*cx;auto&c=a[id];
        if((c.r==254)&&(!c.g)&&(!c.b))qap_add_back(tmp)=vec2i(i,j);
      }
      for(int j=0;j<cy;j++)for(int i=0;i<cx;i++){
        auto id=i+j*cx;auto&c=a[id];
        if((c.r==254)&&(!c.g)&&(!c.b))continue;
        if(c.r==255)continue;
        if(c.g==255)continue;
        if(c.b==255)continue;
        qap_add_back(tmp)=vec2i(i,j);
      }
    }
    int n=0;
    auto ready=get_pix_info_v2("");
    //auto readyb2=get_pix_info("mask_pix_log(b2).txt");QAP_FOREACH(readyb2,qap_add_back(ready)=ex);
    ready.clear();auto fn_list=get_mask_fn_list();QAP_FOREACH(fn_list,auto t=get_pix_info_v2(ex);/*make_recovery(t,cx,cy);*/QAP_FOREACH(t,qap_add_back(ready)=ex));
    //{for(int proc_id=0;proc_id<2;proc_id++){auto p=get_pix_info("mask_pix_log(p"+IToS(proc_id)+")_safe.txt");QAP_FOREACH(p,qap_add_back(ready)=ex);}}

    //QapDebugMsg("get_mask().size() after 254 = "+IToS(tmp.size()));
    vector<int> img;img.resize(cx*cy);
    QAP_FOREACH(ready,auto id=ex.x+ex.y*cx;QapAssert(qap_check_id(img,id));img[id]++;);
    //clean_if(tmp,[&](vec2i&v)->bool{bool found=0;QAP_FOREACH(ready,if(v==vec2i(ex.x,ex.y))found++);return found;});
    clean_if(tmp,[&](vec2i&v)->bool{auto id=v.x+v.y*cx;QapAssert(qap_check_id(img,id));return img[id];});
    if(!mute)QapDebugMsg("get_mask().size() = "+IToS(tmp.size()));
    QapSaveToFile("vector_vec2i.mask",tmp);
    return tmp;
  }
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
  #include "draw_obj.inl"
  static const int proc_id=950;
  static int get_raymaps_limit(){return 64;}
  static string get_rayenv_fn(int limit){
    string fn="rayenv_L"+IToS(limit)+"_scene_tbc_sky_light_"+IToS(t_sphere_n::get_n())+"dirs.bin";//fn="rayenv_L64_just_cube.bin";
    return fn;
  }
  vector<string> real_obj_fn;
  vector<string> get_all_obj_fn(){
    //string fn="scene_v2.obj";
    string fn="full_likesponza.obj";
    fn="raic5_colored3.obj";
    fn="aos4_minimaps.obj";
    if(real_obj_fn.empty()){
      auto s=file_get_contents("scene.txt");s=join(split(s,"\r"),"");
      real_obj_fn=split(s,"\n");
    }
    if(real_obj_fn.empty()){real_obj_fn.push_back(fn);}
    //fn="DogV3.obj";
    //fn="tbr_Moskvitch.obj";
    //fn="tb5.obj";
    //fn="gd_hum.obj";
    //string fn="somebuilding.obj";
    //string fn="platform.obj";
    //string fn="low_poly_car.obj";
    //string fn="drakon.obj";
    return real_obj_fn;
  }
  bool need_init_env_at_start=true;
  void DrawRayCastSphere(int beg=2)
  {
    auto&dirs=t_sphere_n::get();
    bool use_hdr=QapKbOnDownDoInvFlag("use_hdr",'H',true);
    QapColor light_color=0xff00fe00;
    int bounce_limit=128;
    auto&logs=raycast_logs;
    auto ps=vec3f(1,1,1)*0.03;
    if(logs.empty()){
      qap_add_back(logs);
    }
    if(kb.OnDown('M')){
      logs.clear();
      auto&arr=phys_sphere.balls;auto O=vec3f(0,0,0);
      QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        t_photon inp;inp.pos=O;inp.dir=(ex.pos-O).Norm();
        run_ray(qap_add_back(logs),inp,bounce_limit);
      }
    }
    if(kb.OnDown('Y')||kb.OnDown('U'))logs.clear();
    if(kb.OnDown('N')||kb.OnDown('U'))qap_add_back(logs);
    bool need_run_ray=kb.Down('C')||kb.OnDown('N')||kb.OnDown('U');
    bool need_init_env=need_init_env_at_start||need_run_ray;need_init_env_at_start=false;
    if(need_init_env){
      update_env_tris(beg);
    }
    if(need_run_ray)
    {
      auto&log=logs.back();
      auto dpos=get_view_dir();
      auto dir=dpos.Norm();
      t_photon inp;inp.pos=pos;inp.dir=dir;
      run_ray(log,inp,bounce_limit);
    }
    //msg="LastKey = "+CToH(kb.LastKey);
    auto znear=get_our_proj().zn;
    bool single_pixel=0;bool need_clamp_bounds=true&&!single_pixel;
    int msaa_q=8*0;bool only_edges=0||msaa_q;bool only_colorless_edges=false;//bool subpixel=msaa_q;
    real pn=1;bool two_bounce=0;bool need_writeln=two_bounce&&!single_pixel;bool reverse_y=0;bool use_mask=two_bounce;auto sm=GetScreenMode();
    auto light_pos=vec3f(3,9,0);
    if(kb.OnDown(VK_HOME)||kb.OnDown(VK_END)||kb.OnDown(VK_PRIOR)||kb.OnDown(VK_NEXT))for(int i=0;i<logs.size();i++)
    {
      auto&log=logs[i];auto&arr=log.arr;if(arr.empty())continue;
      /*
      auto fn="mask_pix_log.txt";auto bg="mask_pix_log(b1).txt";auto b2="mask_pix_log(b2).txt";
      auto out=get_pix_info(fn);
      auto obg=get_pix_info(bg);
      auto ob2=get_pix_info(b2);QAP_FOREACH(ob2,qap_add_back(out)=ex);
      {for(int proc_id=0;proc_id<2;proc_id++){auto p=get_pix_info("mask_pix_log(p"+IToS(proc_id)+").txt");QAP_FOREACH(p,qap_add_back(out)=ex);}}
      */
      auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);
      
      auto out=get_pix_info_v2("");out.clear();
      do_recovery();
      auto fn_list=get_mask_fn_list();QAP_FOREACH(fn_list,auto t=get_pix_info_v2(ex);QAP_FOREACH(t,qap_add_back(out)=ex));
      
      //auto ob2=get_pix_info(proc_log_fn(7));QAP_FOREACH(ob2,qap_add_back(out)=ex);
      
      log.pix.clear();
      log.pix.resize(cy*cx,0xff000000);
      vector<vec3d> frags;frags.resize(cx*cy);
      //QapDebugMsg(IToS(out.size()));
      //QAP_FOREACH(obg,auto k=real(ex.win)/   (ex.td_size);k*=1.5*(101.0/85);log.pix[ex.x+ex.y*cx]=QapColor::Mix(0xff000000,0xffffffff,k));
      #define CONV(out,expr){\
        vector<vec3d> tmp;tmp.resize(out.size());\
        QAP_FOREACH(out,tmp[i]=expr);\
        for(int i=0;i<16;i++)tmp=do_clamp_upper_bound(tmp);\
        for(int i=0;i<16;i++)tmp=do_clamp_bottom_bound(tmp);\
        QAP_FOREACH(out,frags[ex.x+ex.y*cx]=tmp[i]);\
      };
      if(kb.OnDown(VK_NEXT))
      {
        QAP_FOREACH(out,if(ex.ms>1e4)ex.ms*=1e-3;);
        CONV(out,vec3d(1,1,1)*ex.ms);
        auto t=0.0;int n=0;real ms_in_m=60*1000;real rw=0;
        QAP_FOREACH(out,t+=ex.ms;n++;rw+=ex.raw_wins;);
        auto cxcysubn=use_mask||kb.Down(VK_MENU)?get_mask(cx,cy,true).size():cx*cy-n;
        msg="{t:'"+FToS(t/ms_in_m)+" m',n:"+IToS(n)+",'t/n':'"+FToS(t/n)+" ms',time_left:'"+FToS((cxcysubn)*(t/n)/(ms_in_m))+" m',rw:"+FToS(rw)+
          ",cxcy-n:"+IToS(cxcysubn)+"}";
      }
      if(kb.OnDown(VK_PRIOR))
      {
        CONV(out,ex.simple_frag.c);
      }
      if(kb.OnDown(VK_HOME))
      {
        CONV(out,ex.frag.c);
      }
      if(kb.OnDown(VK_END))
      {
        CONV(out,ex.only_details.c);
        //QapLoadFromFile("../UnixVersion/Release/frags55.bin",frags);
        for(int i=0;i<16;i++)frags=do_clamp_upper_bound(do_clamp_bottom_bound(frags));
      }
      static const real inv_gamma=1.0/2.2;
      QAP_FOREACH(frags,ex=vec3d_pow(ex,inv_gamma));
      frags=hdr_pixmap(frags,0.0,255.0);
      QAP_FOREACH(frags,log.pix[i]=QapColor(ex.x,ex.y,ex.z));
      //static const real inv_gamma=1.0/2.2;
      //QAP_FOREACH(frags,log.pix[i]=QapColor::Mix(0xff000000,0xffffffff,pow(ex,inv_gamma)));
    }
    if(kb.OnDown('E')){
      update_env(beg);
    }
    if(kb.OnDown(VK_F6)||kb.OnDown('U'))for(int i=0;i<logs.size();i++)
    {
      if(!single_pixel)if(two_bounce)win.Hide();
      auto&log=logs[i];auto&arr=log.arr;if(arr.empty())continue;
      auto nznear=arr.size()?(arr[0].pos-log.pos).Norm()*znear:vec3f(0,0,0);
      auto old=log.pos+nznear;auto&inp=log.inp;
      auto n=(arr[0].pos-log.pos).Norm();
      auto proj=get_our_proj();
      auto wh=proj.get_wh();
      auto up=vec3f(0,1,0);
      auto ox=cross(up,n).Norm();
      auto oy=cross(ox,n).Norm();
      auto pwh=vec2d(pn/sm.W,pn/sm.H).Mul(wh);
      auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);
      auto center=log.pos+n*proj.zn;
      
      t_proj_info proj_info;
      proj_info.pos=pos;
      proj_info.dir=n;
      proj_info.wh=wh;
      proj_info.zn=proj.zn;
      QapSaveToFile("../UnixVersion/Release/proj_info.bin",proj_info);
      //QapDebugMsg("proj_info done!");
      log.pix.resize(cy*cx);
      //QapClock clock;
      update_env(beg);
      //QapDebugMsg("update_env time = "+FToS(clock.MS())+" ms");
      
      vector<vec3d> frags;frags.resize(cx*cy);
      //vector<int> tris_id;
      //vector<int> updated
      
      QapClock clock;
      
      #include "pixel_algo.inl"
      /*
      //static vector<std::thread> workers(worker);
      //int num_of_proc=2;
      //for(int i=1+workers.size();i<num_of_proc;i++)qap_add_back(workers)...
      std::thread worker(func);worker.detach();
      
      */
      if(single_pixel){
        
        vector<vec2i> arr;int n=32*4;
        /*
        for(int i=cy/2-n;i<=cy/2+n;i++)for(int j=cx/2-n;j<=cx/2+n;j++)qap_add_back(arr)=vec2i(j,i);
        #pragma omp parallel for schedule(dynamic,16)
        for(int i=0;i<arr.size();i++)f(arr[i].y,arr[i].x);
        */
        for(int i=cy/2-n;i<=cy/2+n;i++)for(int j=cx/2-n;j<=cx/2+n;j++){
          int x=j;int y=reverse_y?cy-i-1:i;
          auto coords=vec2i(x,y);
          auto mm=get_msaa_mass(coords);
          frags[x+y*cx]=vec3d(1,1,1)*mm;
          //f(y,x,tmp.size()>1);
        }
        
      }else{
        if(use_mask){
          auto mask=get_mask(cx,cy);int mask_size=mask.size();
          #pragma omp parallel for schedule(dynamic,16)
          for(int mask_id=0;mask_id<mask_size;mask_id++)f(mask[mask_id].y,mask[mask_id].x);// if(proc_id%2==mask_id%2) ... 
        }else{
          //f(93,29);
          int n=cx*cy;
          #pragma omp parallel for schedule(dynamic,64)
          for(int i=0;i<n;i++)f(i/cx,i%cx);
          //for(int i=0;i<cy;i++)for(int j=0;j<cx;j++)f(i,j);
        }
      }
      QapSaveToFile("frags.bin",frags);
      static const real inv_gamma=1.0/2.2;
      QAP_FOREACH(frags,ex=vec3d_pow(ex,inv_gamma));
      if(need_clamp_bounds)frags=do_clamp_upper_bound(do_clamp_bottom_bound(frags));
      frags=hdr_pixmap(frags,0.0,255.0);
      QAP_FOREACH(frags,log.pix[i]=QapColor(ex.x,ex.y,ex.z));

      string clock_fn="clock.txt";
      auto con=file_get_contents(clock_fn)+"\n["+cur_date_str()+"]dark["+IToS(pn)+"]    time = "+FToS(clock.MS())+" ms";
      file_put_contents(clock_fn,con);
      if(!single_pixel)if(two_bounce)win.Show();
    }
    if(kb.OnUp(VK_F11)||kb.OnDown(VK_F6)||kb.OnDown('U'))if(logs[0].pix.size())if(pn<80)
    {
      auto pix=logs[0].pix;
      //auto pix=use_hdr?hdr_pixmap(logs[0].pix):logs[0].pix;
      auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);
      ImgLoader::TextureMemory mem;
      Env.InitMemory(mem,cx,cy);
      for(int i=0;i<cx*cy;i++)((QapColor*)mem.ptr)[i]=pix[i].swap_rg();
      Env.SaveTextureToFile(mem,"out/rt("+IToS(pn)+"."+join(split(cur_date_str(),":"),"-")+"."+IToS(1000+rand()%9000)+").png");
    }
    for(int i=0;i<logs.size();i++)
    {
      auto&log=logs[i];auto&arr=log.arr;
      auto zn_mk=1.5;//257/256.0;
      auto nznear=arr.size()?(arr[0].pos-log.pos).Norm()*zn_mk*znear:vec3f(0,0,0);
      auto old=log.pos+nznear;auto&inp=log.inp;
      auto cs=0.005;
      {for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        qDev.color=0xFF000000;qDev.DrawCubeFast(ex.pos,ps);
        {qDev.color=!i?0xFF007700:0xFFFF0000;qDev.DrawCylinderAsLine(old,ex.pos,cs,16,0,i);}
        old=ex.pos;
      }}
      //if(!arr.empty())
      {
        auto b=arr.empty()?inp.pos:arr.back().pos;
        auto fin=b+inp.dir*30;
        {qDev.color=0xFF0000FF;qDev.DrawCylinderAsLine(old,fin,cs,16,0);}
      }
      if(!arr.empty())if(bool need_draw_cubes_at_vertex_of_camplane=true)
      {
        auto n=(arr[0].pos-log.pos).Norm();
        auto proj=get_our_proj().zn_mul(zn_mk);
        auto wh=proj.get_wh();
        auto up=vec3f(0,1,0);
        auto ox=cross(up,n).Norm();
        auto oy=cross(ox,n).Norm();
        auto pwh=vec2d(pn/sm.W,pn/sm.H).Mul(wh);
        auto cx=int(sm.W/pn);auto cy=int(sm.H/pn);
        auto center=log.pos+n*proj.zn;//*(257/256.0);
        //vec3f VA[4];for(int k=0;k<4;k++){auto d=ds[k].Mul(pwh);VA[k]=ox*d.x+oy*d.y;}
        if(QapKbOnDownDoInvFlag("need_draw_camplane_pixmap",'I',true)&&!i)
        {
          bool skip_black=QapKbOnDownDoInvFlag("pixmap_skip_black_pix",VK_BACKSLASH,false);
          auto hdr=!use_hdr?vector<QapColor>():hdr_pixmap(log.pix);
          auto size=wh*2;
          auto d=vec2d(size.x/(cx*2),size.y/(cy*2));auto p=center-(ox*size.x+oy*size.y)*0.5;
          if(bool need_parallel=true)
          {
            int base_vpos=qDev.VPos;
            #pragma omp parallel for schedule(guided,16)
            for(int i=0;i<cy;i++)for(int j=0;j<cx;j++){
              QapColor qdc;
              int base=base_vpos+(cx*i+j)*4;
              auto id=j+i*cx;
              bool ok=qap_check_id(log.pix,id);
              if(skip_black){if(!ok)break;auto&c=log.pix[id];qdc=c;if(!c.r&&!c.g&&!c.b)continue;}else{
                if(log.pix.size())qdc=ok?(use_hdr?hdr[id]:log.pix[id]):qdc;
              }
              if(!ok&&i>4)break;
              #define F(X,Y)qDev.WriteVertexUnsafe(base++,p+ox*(d.x*(j*2+2*(X<0?0:X)))+oy*(d.y*(i*2+2*(Y<0?0:Y))),qdc);
              F(+1,+1);
              F(+1,-1);
              F(-1,-1);
              F(-1,+1);
              #undef F
              //for(int k=0;k<4;k++)qDev.AddVertex(VA[k]+quad_center);
            }
            qDev.VPos+=cx*cy*4;
            for(int i=0;i<cy;i++)for(int j=0;j<cx;j++)qDev.AddQuad(base_vpos+(cx*i+j)*4,0,1,2,3);
          }else{
            for(int i=0;i<cy;i++)for(int j=0;j<cx;j++){
              //qDev.color=(i+j)%2?0xFFffffff:0xFF000000;
              int base=qDev.VPos;
              auto id=j+i*cx;
              bool ok=qap_check_id(log.pix,id);
              if(skip_black){if(!ok)break;auto&c=log.pix[id];qDev.color=c;if(!c.r&&!c.g&&!c.b)continue;}else{
                if(log.pix.size())qDev.color=ok?(use_hdr?hdr[id]:log.pix[id]):qDev.color;
              }
              if(!ok&&i>4)break;
              #define F(X,Y)qDev.AddVertex(p+ox*(d.x*(j*2+2*(X<0?0:X)))+oy*(d.y*(i*2+2*(Y<0?0:Y))));
              F(+1,+1);
              F(+1,-1);
              F(-1,-1);
              F(-1,+1);
              #undef F
              //for(int k=0;k<4;k++)qDev.AddVertex(VA[k]+quad_center);
              qDev.AddQuad(base,0,1,2,3);
            }
          }
        }
        if(bool look_at_pixel_cone_tracing=false)
        {
          for(int i=0;i<cy;i++)for(int j=0;j<cx;j++)if(abs(i-cy/2)<2)if(abs(j-cx/2)<2)
          {
            auto size=wh*2;
            auto d=vec2d(size.x/(cx*2),size.y/(cy*2));auto p=center-(ox*size.x+oy*size.y)*0.5;
            //int i=cy/2;int j=cx/2;//int X=+1;int Y=+1;
            auto f=[&](vec3f pos,vec3f some_pos){
              auto dir=(some_pos-pos).Norm();
              t_photon inp;inp.pos=pos;inp.dir=dir;
              auto out=do_raycast_fixed(inp);
              qDev.color=0xFF0000FF;qDev.DrawCylinderAsLine(pos,/*dir*30+log.pos*/out.pos,0.05,16,0);
              qDev.color=0xFF000000;qDev.DrawCubeFast(out.pos,ps);
              //return out.pos;
            };
            #define F(X,Y){auto some_pos=p+ox*(d.x*(j*2-1+2*(X<0?0:X)))+oy*(d.y*(i*2+1+2*(Y<0?0:Y)));f(log.pos,some_pos);}
            F(+1,+1);
            F(+1,-1);
            //F(-1,-1);
            //F(-1,+1);
            #undef F
          }
        }
        vec2d ds[]={
          vec2d(+1,+1),
          vec2d(+1,-1),
          vec2d(-1,-1),
          vec2d(-1,+1)
        };
        qDev.color=0xFF000000;
        for(int i=0;i<4;i++){
          auto d=ds[i].Mul(wh);
          auto cube_pos=log.pos+n*proj.zn+ox*d.x+oy*d.y;
          qDev.DrawCubeFast(cube_pos,ps*0.05);
        }
        qDev.color=0xFF000080;qDev.DrawCubeFast(log.pos,ps*0.01);
      }
    }
  }
  struct t_sphere_n{
    static const int def_n=512*8;//*16;
    static const int get_n(){return def_n;}
    static const vector<vec3f>&get(){
      static vector<vec3f> arr;
      if(!arr.empty())return arr;
      return get_impl(arr,get_n());
    }
    static const vector<vec3f>&get_impl(vector<vec3f>&arr,int n){
      string fn="sphere"+IToS(n)+".bin";
      if(access(fn.c_str(),0)!=0){QapDebugMsg(fn+" - not found");QapNoWay();}
      QapLoadFromStr(arr,file_get_contents(fn));
      auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex);O*=1.0/arr.size();
      QAP_FOREACH(arr,ex=(ex-O).Norm());
      QAP_FOREACH(arr,if(fabs(ex.Mag()-1)>0.001)QapDebugMsg("t_sphere_n::dirs[i].Mag() = "+FToS(ex.Mag())););
      if(bool need_save_after_fix=false)file_put_contents(fn,QapSaveToStr(arr));
      return arr;
    }
  };
  void make_sphere_n_bin()
  {
    auto&balls=phys_sphere.balls;
    static vector<vec3f> out;
    if(out.empty())
    {
      auto&arr=balls;
      auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
      QAP_FOREACH(arr,ex.pos-=O;ex.pos=ex.pos.Norm());
      QAP_FOREACH(arr,qap_add_back(out)=ex.pos);
      file_put_contents("sphere"+IToS(arr.size())+".bin",QapSaveToStr(out));
    }
  }
  void show_dirs(){
    auto&dirs=t_sphere_n::get();auto&balls=phys_sphere.balls;balls.clear();
    QAP_FOREACH(dirs,qap_add_back(balls).pos=ex;if(abs(ex.Mag()-1)>0.001)QapDebugMsg("dir.mag = "+FToS(ex.Mag())););
  }
  //void draw_
  int64 g_iter=0;
  int64 g_subiter=0;
  void DrawBall_V2()
  {
    qDev.color=0xFFffffff;
    auto&arr=phys_sphere.balls;
    real r=0.025*0.25;
    auto cuber_r=vec3f(1,1,1)*r;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      qDev.DrawCube(ex.pos,cuber_r);
    }
    rq();
    DrawBoxAndSky();
    //if(!kb.OnDown(VK_F1))return;
    /*
    make_4_vertex;
    align_it

    */
    auto tn=phys_sphere.IA.size()/3;
    if(tn)
    {
      vector<vec3f> out;
      real r=1;
      int nd=0;int a=0;int b=1;int c=2;int d=3;
      //if(arr.size()!=4){QapNoWay();return;}
      vec3f center;
      {
        auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();QAP_FOREACH(arr,ex.pos-=O);center=O;
        r=0.0;QAP_FOREACH(arr,r+=ex.pos.Mag());r*=1.0/arr.size();//r=2;
        QAP_FOREACH(arr,ex.pos=ex.pos.Norm()*r);
      }
      QAP_FOREACH(arr,qap_add_back(out)=ex.pos);
      for(int i=0;i+2<phys_sphere.IA.size();i+=3){
        int a=phys_sphere.IA[i+0];
        int b=phys_sphere.IA[i+1];
        int c=phys_sphere.IA[i+2];
        split_trigon(out,a,b,c,nd,r);
        //split_trigon(out,a,b,c,nd,r);
        //split_trigon(out,b,c,d,nd,r);
        //split_trigon(out,c,d,a,nd,r);
        //split_trigon(out,d,a,b,nd,r);
      }
      arr.clear();
      QAP_FOREACH(out,qap_add_back(arr).pos=center+ex);
    }
  }
  static vec3f gen_new_point(vec3f a,vec3f b,vec3f c,real r){return (a+b+c).Norm()*r;}
  static void split_trigon(vector<vec3f>&out,int a,int b,int c,int depth,real r){
    auto p=out.size();
    qap_add_back(out)=gen_new_point(out[a],out[b],out[c],r);
    if(!depth)return;
    auto nd=depth-1;
    split_trigon(out,a,b,p,nd,r);
    split_trigon(out,b,c,p,nd,r);
    split_trigon(out,c,a,p,nd,r);
  }
  void DrawBall()
  {
    if(kb.OnDown(mbMiddle))return DrawBall_V2();
    //show_dirs();
    auto&balls=phys_sphere.balls;
    //if(kb.OnDown(VK_TAB)){
    //  make_sphere_n_bin();
    //  int gg=1;
    //}
    if(kb.OnDown(VK_F1))balls.clear();//qaplite.h
    if(kb.OnDown(VK_F5))qap_add_back(balls).init();
    if(kb.OnDown(VK_F2))msg="phys_sphere.IA.size()/3="+IToS(phys_sphere.IA.size()/3)+"    phys_sphere.balls.size()="+IToS(phys_sphere.balls.size());
    if(kb.Down(VK_F2)&&kb.OnDown(mbRight)){
      QapSaveToFile("sphere_from_cpp.bin",balls);
      QapSaveToFile("phys_sphere.dump.bin",phys_sphere);
    }
    if(kb.Down(VK_F2))if(kb.OnDown(VK_F5)){
      static int id=0;id++;
      msg="trash8x4k/sphere_at_iter"+IToS(id)+".bin";
      QapLoadFromFile(msg,balls);
      //QapLoadFromFile("sphere_at_iter26.bin",balls);
      //QapLoadFromFile("../Demo/sphere_at_iter40.bin",balls);
    }
    auto auto_update=QapKbOnDownDoInvFlag("ball_auto_update",VK_F9,false);
    auto draw_points=QapKbOnDownDoInvFlag("ball_draw_points",VK_F12,true);
    if(balls.empty())
    {
      g_iter=0;
      g_subiter=0;
      int n=4;4096*16;(512*8)/64;auto k=0.005*512.0/real(n);
      for(int i=0;i<n;i++)qap_add_back(balls).init();
      auto h=n/2;auto q=h/2;
      QAP_FOREACH(balls,ex.pos=i<h?vec3f((i-q)*k,3,0):vec3f(0,3,(i-h-q)*k));balls[q-1].pos.y+=1;
      QAP_FOREACH(balls,ex.pos=vec3f((i-h)*k,3,0));
      balls[h-1].pos.y+=1;
      balls[h-0].pos.z+=1;
    }
    if(0)if(msg.empty())
    {
      msg="last = ";//balls.back().pos=vec3f(0,0,0);
      msg+=" "+FToS(balls.back().pos.x);
      msg+=" "+FToS(balls.back().pos.y);
      msg+=" "+FToS(balls.back().pos.z);
    }
    int seg=3;int cn=std::max<int>(1,seg-2);real r=0.025;
    if(QapKbOnDownDoInvFlag("need_show_dirs",VK_INSERT,false))
    {
      auto&arr=t_sphere_n::get();
      auto dpos=get_view_dir();
      auto id=QAP_MINVAL_ID_OF_VEC(arr,(dpos-ex).SqrMag());
      qDev.color=0xffffffff;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        DrawLightedSphere(ex+pos,r*0.1,3,1);
      }
      qDev.color=0xffffff00;
      DrawLightedSphere(arr[id]+pos,r*0.1,8,8);if(kb.OnDown(VK_MENU))msg="dir_id = "+IToS(id); //dir_id=2008 // tris_id=337
    }
    auto&arr=balls; auto sphere_r=2;auto sr=sphere_r;auto cuber_r=vec3f(1,1,1)*0.25*sqrt(sr*sr*4/real(balls.size())); //4*Pi*r*r=area;area/n=cr*cr*Pi;cr=sqrt((sr*sr*Pi*4)/(n*Pi));
    if(draw_points)for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      qDev.DrawCube(ex.pos,cuber_r);
      //qDev.DrawSphere(ex.pos,r,seg,cn);
      //DrawLightedSphere(ex.pos,r,seg,cn);
    }
    DrawLightedSphereV2();
    rq();
    if(0)for(int j=0;j<arr.size();j++)
    {
      auto c=arr[j].pos;
      auto id0=QAP_MINVAL_ID_OF_VEC(arr,i==j?1e16:(ex.pos-c).SqrMag());
      auto id1=QAP_MINVAL_ID_OF_VEC(arr,i==j||i==id0?1e16:(ex.pos-c).SqrMag());
      auto id2=QAP_MINVAL_ID_OF_VEC(arr,i==j||i==id0||i==id1?1e16:(ex.pos-c).SqrMag());
      auto id3=QAP_MINVAL_ID_OF_VEC(arr,i==j||i==id0||i==id1||i==id2?1e16:(ex.pos-c).SqrMag());
      auto id4=QAP_MINVAL_ID_OF_VEC(arr,i==j||i==id0||i==id1||i==id2||i==id3?1e16:(ex.pos-c).SqrMag());
      auto id5=QAP_MINVAL_ID_OF_VEC(arr,i==j||i==id0||i==id1||i==id2||i==id3||i==id4?1e16:(ex.pos-c).SqrMag());
      auto lw=1/16.0;auto tcn=0.3;
      qDev.DrawCylinderAsLine(arr[id0].pos,arr[j].pos,lw,tcn,0);
      qDev.DrawCylinderAsLine(arr[id1].pos,arr[j].pos,lw,tcn,0);
      qDev.DrawCylinderAsLine(arr[id2].pos,arr[j].pos,lw,tcn,0);
      qDev.DrawCylinderAsLine(arr[id3].pos,arr[j].pos,lw,tcn,0);
      qDev.DrawCylinderAsLine(arr[id4].pos,arr[j].pos,lw,tcn,0);
      qDev.DrawCylinderAsLine(arr[id5].pos,arr[j].pos,lw,tcn,0);
    }
    
    if(kb.OnDown('R'))
    {
      auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
      auto r=0.0;QAP_FOREACH(arr,r+=(ex.pos-O).Mag());r*=1.0/arr.size();
      QAP_FOREACH(arr,ex.pos=O+(ex.pos-O).Norm()*r);
    }
    auto stop_every=22*1024*15;//std::max<int>(max_subiter/4096,64*4096*2);
    if((!kb.Down[VK_F2]&&auto_update)||kb.OnDown(VK_F8))
    {
      QapClock clock;static QapClock c2;static int64 iter2=0;
      auto&iter=g_iter;
      int64 n=arr.size();
      for(;stop_every>0;)
      {
        if(iter>=arr.size()){iter=0;g_subiter=0;}
        if(!iter)
        {
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            ex.pos+=ex.v;
            if(kb.Down[VK_F3])ex.v.y-=0.01;
            if(ex.pos.y-r<0)ex.v.y+=abs(ex.pos.y-r);
            real di=2;//128;//1024*16;
            ex.v*=real(di-1)/di;
          }
          {
            auto O=vec3f(0,0,0);QAP_FOREACH(arr,O+=ex.pos);O*=1.0/arr.size();
            auto r=0.0;QAP_FOREACH(arr,r+=(ex.pos-O).Mag());r*=1.0/arr.size();
            QAP_FOREACH(arr,ex.pos=O+(ex.pos-O).Norm()*r);
          }
        }
        //rq();
      
        {
          auto k=1.0/(n+1);//(n*2);
          int64 i=iter;//for(int i=0;i<n;i++)
          {
            auto&a=arr[i];
            //#pragma omp parallel for schedule(guided,8*1024)
            for(int j=i+1;j<n;j++)
            {
              auto&b=arr[j];
              auto ab=b.pos-a.pos;
              auto dist=2;
              auto d=ab.Mag();
              d=d?d:0.00125;
              auto f=d-dist;
              auto dv=ab*(f*k/d);
              a.v+=+dv;
              b.v+=-dv;
              iter2++;g_subiter++;stop_every--;
              //phys_sphere.update_link(arr[i],arr[j]);
              //qDev.DrawCylinderAsLine(arr[i].pos,arr[j].pos,0.25,16,0);
            }
          }
        }
        iter++;
      }
      msg="progress:"+FToS(100.0*g_subiter/((n+1)*(n*0.5)))+" %    iter: "+IToS(g_iter)+"    avg:"+FToS(iter2/c2.MS())+" links/ms"+"    // time = "+FToS(clock.MS())+" ms";
    }
    /*
    update_link(arr[0],arr[1]);
    update_link(arr[2],arr[1]);
    update_link(arr[0],arr[2]);
    
    for(int i=0;i<3;i++)update_link(arr[i],arr[3]);
    
    qDev.color=0xFF0000FF;rq();qDev.DrawCylinderAsLine(arr[0].pos,arr[1].pos,0.5,16,0);
    qDev.color=0xFF00FF00;rq();qDev.DrawCylinderAsLine(arr[1].pos,arr[2].pos,0.5,16,0);
    qDev.color=0xFFFF0000;rq();qDev.DrawCylinderAsLine(arr[0].pos,arr[2].pos,0.5,16,0);
    qDev.color=0xFF8080FF;rq();qDev.DrawCylinderAsLine(arr[3].pos,arr[1].pos,0.5,16,0);
    qDev.color=0xFF80FF80;rq();qDev.DrawCylinderAsLine(arr[3].pos,arr[2].pos,0.5,16,0);
    qDev.color=0xFFFF8080;rq();qDev.DrawCylinderAsLine(arr[0].pos,arr[3].pos,0.5,16,0);
    */
    
    //DrawHuman();
    DrawBoxAndSky();
  }
  void DrawBoxAndSky()
  {
    if(kb.OnDown(VK_TAB))msg="";
    //if(kb.OnDown(VK_INSERT))msg="env.trigons.size() = "+IToS(env.trigons.size());
    
    auto ps=10.0;auto hps=ps*0.5;auto yps=ps*0.6;auto hhps=hps*0.5;auto walls_y=hhps-(yps-hps)*0.5;auto w=0.01;auto zhps=w+ps*0.5;auto xhps=+2*w+ps*0.5;
    if(bool need_draw_small_cube=false)
    {
      qDev.color=0xFF202020;qDev.DrawCubeFast(vec3f(-2,0.51,2),vec3f(1,1,1));
    }
    if(bool need_draw_walls_and_bottom=true)
    {
      qDev.color=0xFF808080;qDev.DrawCubeFast(vec3f(0,0,0),vec3f(ps,w,ps));
      //qDev.DrawCubeFast(vec3f(0,0,0),vec3f(ps,0.01,ps));
      qDev.color=0xFF909090;qDev.DrawCubeFast(vec3f(00000,walls_y,+zhps),vec3f(ps,yps,w));
      qDev.color=0xFF909090;qDev.DrawCubeFast(vec3f(00000,walls_y,-zhps),vec3f(ps,yps,w));
      qDev.color=0xFFa0a0a0;qDev.DrawCubeFast(vec3f(+xhps,walls_y,00000),vec3f(w,yps,ps));
      qDev.color=0xFFa0a0a0;qDev.DrawCubeFast(vec3f(-xhps,walls_y,00000),vec3f(w,yps,ps));
    }
    
    if(bool need_draw_two_line_of_cubes=false)
    {
      for(int i=0;i<6;i++){
        qDev.color=0xFF202020;qDev.DrawCubeFast(vec3f(-2+i*2-3,0.51,1.2+2),vec3f(1,1,1));
        qDev.color=0xFF202020;qDev.DrawCubeFast(vec3f(-2+i*2-3,1.51,1.2-2),vec3f(1,1,1));
      
        qDev.color=0xFF202020;qDev.DrawCubeFast(vec3f(-2+i*2-3,2.51,1.2-2),vec3f(1,1,1)*(0.5-i*0.01));
      }
    }
    if(bool need_draw_light_and_cube_and_cylinder=false)
    {
      //light
      qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,10,00),vec3f(40,1,40));
      //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(-1.5,1,-1.5),vec3f(0.5,0.5,0.5));
      /*
    
      qDev.color=0xff00fe00;qDev.DrawCube(vec3f(+1.5,0.5,-1.5),vec3f(0.5,4.5,0.5));
      qDev.color=0xff00fe00;qDev.DrawCube(vec3f(+2.0,0.5,-2.5),vec3f(0.5,3.5,0.5));
    
      qDev.color=0xff00fe00;qDev.DrawCube(vec3f(+1.5,0.5,+3.5),vec3f(0.5,4.5,0.5));*/
    
      //shit
    
      qDev.color=0xff555555;qDev.DrawCube(vec3f(-4.0,0.5,-2.25),vec3f(0.5,0.5,5));
      qDev.color=0xff454545;qDev.DrawCylinderAsLine(vec3f(-4.0,1.5,-2),vec3f(1.5,4,1.5),0.2,4,0);
    
      //DrawRayCastSphere();
    }
    if(kb.OnDown(VK_SLASH))
    {
      int beg=2;
      t_photon inp;inp.pos=pos;inp.dir=get_view_dir().Norm();
      int tris_id=-1;update_env_tris(beg);do_raycast_fixed(inp,&tris_id);
      msg="tris_id = "+IToS(tris_id)+"    "+string(qDev.IPos<debug_phys_sphere_ipos?"":"phys_sphere_tris_id = "+IToS(tris_id-debug_phys_sphere_ipos/3));
      //tris_rewrite_colors(tris_id);
    }
  }
  void make_lighted_scene(int sc=0){
    if(!kb.OnDown(VK_SLASH))return;
    lighted_scene.clear();
    lighted_scene.src.resize(env.tris.size()*3*ipow(3,sc));
    {
      auto&arr=env.tris;
      #pragma omp parallel for schedule(dynamic,64)
      for(int i=0;i<arr.size();i++){
        tris_rewrite_colors(i,sc);
      }
    }
    //QAP_FOREACH(env.tris,tris_rewrite_colors(i));
    msg="make_lighted_scene_done";
  }
  static size_t ipow(size_t base,size_t power){size_t out=1;for(size_t i=0;i<power;i++)out*=base;return out;}
  struct t_lighted_scene{
    struct t_rec{
      t_lights_rays_color LC;
      vec3f pos;
    };
    vector<t_rec> src;
    vector<QapDev::Ver> arr;
    void update()
    {
      vector<vec3d> frags;
      QAP_FOREACH(src,qap_add_back(frags)=ex.LC.c);
      static const real inv_gamma=1.0/2.2;
      QAP_FOREACH(frags,ex=vec3d_pow(ex,inv_gamma));
      frags=do_clamp_upper_bound(do_clamp_bottom_bound(frags));
      frags=hdr_pixmap(frags,0.0,255.0);
      arr.clear();arr.resize(src.size());
      QAP_FOREACH(arr,auto&s=src[i];auto&fc=frags[i];ex.get_vec3f()=s.pos;ex.color=QapColor(fc.x,fc.y,fc.z));
    }
    void draw(QapDev&qDev){
      if(src.size()&&arr.empty())update();
      QapAssert(arr.size()%3==0);
      auto base=qDev.VPos;
      QAP_FOREACH(arr,qDev.AddVertexRaw()=ex);
      for(int i=0;i<arr.size()/3;i++){
        qDev.AddTris(base+0,base+1,base+2);base+=3;
      }
    }
    void clear(){
      arr.clear();src.clear();
    }
  };
  t_lighted_scene lighted_scene;
  static vec3f gen_new_point_v2(vec3f a,vec3f b,vec3f c){return (a+b+c)*(1.0/3.0);}
  static void split_trigon_v2(const vector<vec3f>&VA,vector<vec3f>&out,int a,int b,int c){
    //auto p=out.size();
    //qap_add_back(out)=gen_new_point_v2(out[a],out[b],out[c]);
    auto p=gen_new_point_v2(VA[a],VA[b],VA[c]);
    #define F(a,b,p)qap_add_back(out)=VA[a];qap_add_back(out)=VA[b];qap_add_back(out)=p;
    F(a,b,p);
    F(b,c,p);
    F(c,a,p);
    #undef F
  }
  static void split_trigon_v3(const vector<vec3f>&VA,vector<vec3f>&out,int a,int b,int c){
    int arr[3]={a,b,c};auto vv=make_view(arr);
    auto id=QAP_MINVAL_ID_OF_VEC(vv,-(VA[ex]-VA[arr[(i+1)%3]]).SqrMag());
    auto A=VA[arr[(id+0)%3]];auto B=VA[arr[(id+1)%3]];auto C=VA[arr[(id+2)%3]];
    auto p=(A+B)*0.5;
    #define F(a,b,p)qap_add_back(out)=a;qap_add_back(out)=b;qap_add_back(out)=p;
    F(C,A,p);
    F(B,C,p);
    #undef F
  }
  void tris_rewrite_colors(int tris_id,int split_iters=0)
  {
    //QapClock clock;
    if(!qap_check_id(env.tris,tris_id)){QapDebugMsg("wrong tris_id - no way");return;}
    if(!qap_check_id(env.trigons,tris_id)){QapDebugMsg("wrong tris_id - no way");return;}
    auto&t=env.tris[tris_id];auto&tg=env.trigons[tris_id];

    auto light=is_light(tris_id);auto tc=to_vec3d(env.tris_colors[tris_id]);auto&td=t.light_dirs;
    vector<vec3f> cur,next;
    qap_add_back(next)=tg.a;
    qap_add_back(next)=tg.b;
    qap_add_back(next)=tg.c;
    for(int iter=0;iter<split_iters&&next.size();iter++){
      cur=std::move(next);
      for(int i=0;i<cur.size()/3;i++){
        auto base=i*3;
        split_trigon_v3(cur,next,base+0,base+1,base+2);
      }
    }
    cur=std::move(next);
    auto out_tris_n=cur.size()/3;
    for(int i=0;i<out_tris_n;i++){
      auto base=i*3;
      auto tga=cur[base+0];
      auto tgb=cur[base+1];
      auto tgc=cur[base+2];
      auto O=(tga+tgb+tgc)*0.3;
      auto a=O+(tga-O)*real(127.0/128.0);
      auto b=O+(tgb-O)*real(127.0/128.0);
      auto c=O+(tgc-O)*real(127.0/128.0);
      auto ar=tris_and_point_to_color(a,td,tc,light);
      auto br=tris_and_point_to_color(b,td,tc,light);
      auto cr=tris_and_point_to_color(c,td,tc,light);
      auto add=[&](int offset,const t_lights_rays_color&ar,const vec3f&pos){auto&v=lighted_scene.src[out_tris_n*3*tris_id+base+offset];v.pos=pos;v.LC=ar;};
      add(0,ar,tga);
      add(1,br,tgb);
      add(2,cr,tgc);
    }
    //QapDebugMsg("tris_rewrite_colors for "+IToS(tris_id)+" done in "+FToS(clock.MS()));
  }
  t_lights_rays_color tris_and_point_to_color(const vec3f&out_pos,vector<int>&tris_light_dirs,const vec3d&tc,bool light)
  {
    auto&td=tris_light_dirs;
    t_lights_rays_color frag;
    if(light)
    {
      auto heds=env.dirs.size()/2;
      frag.n=1;
      //frag.c=to_vec3d(env.tris_colors[tris_id])*heds;
      frag.c=tc*heds;
    }
    for(int k=0;k<td.size();k++){
      auto dir_id=td[k];
      auto LRC=get_lights_rays_color_in(out_pos,dir_id);
      frag.add(LRC);
    }
    //auto tc=to_vec3d(env.tris_colors[tris_id]);
    frag.c=tc.Mul(frag.c);
    return frag;
  }
  void DrawLightedSphere(vec3f center,real r,int seg,int cn)
  {
    int ipos=qDev.IPos;int beg=qDev.VPos;static auto bp=pos;if(!light)bp=pos;auto pos=bp;
    qDev.DrawSphere(center,r,seg,cn);
    vec3f lightpos(0,0,3);
    auto c=0.05;
    //msg="v = "+IToS(qDev.VPos-beg)+" tris = "+IToS((qDev.IPos-ipos)/3);
    for(int i=beg;i<qDev.VPos;i++)
    {
      auto&v=qDev.VBA[i];
      auto&p=v.get_vec3f();
      auto dir=p-pos;
      auto n=p-center;
      auto k=dot(-dir.Norm(),n.Norm());if(k<0)k=0;if(k>1)k=1;
      v.color=QapColor::Mix(0xffa8a8a8,0xffffffff,k);
    }
  }
  void DrawHuman()
  {
    int cn=6;int seg=cn;real r=0.25;real hr=0.5*r;int beg=qDev.VPos;vec3f lightpos(0,0,3);lightpos=pos*(1.0/pos.Mag())*3;
    qDev.color=0xFF000000;
    /*
    head
    shoulder+hans
    tits
    r
    r
    r
    ass
    pelvis
    legs
    */
    //#define DrawSphere DrawSphereWire
    auto dy=vec3f(0,1.7,1); auto p=vec3f(-1,0,0);
    {auto dx=0.90/0.80;for(int i=-1;i<=+1;i++)if(i)DrawLightedSphere(p+dy+vec3f(i*dx*r*2,1.3*r*+2.35,0),r*1.1,seg,cn);}
    for(int i=-1;i<=+1;i++)if(i)DrawLightedSphere(p+dy+vec3f(i*0.75*r,1.3*r*+2,0),r,seg,cn);
    for(int i=-1;i<=+1;i++)
    {
      DrawLightedSphere(p+dy+vec3f(0,1.5*r*i,0),r,seg,cn);
    }
    {auto dx=1-(0.47/0.80);for(int i=-1;i<=+1;i++)if(i)DrawLightedSphere(p+dy+vec3f(i*dx*r*2,1.3*r*-2,-r*0.5),r,seg,cn);}
    {auto dx=1-(0.23/0.80);for(int i=-1;i<=+1;i++)if(i)DrawLightedSphere(p+dy+vec3f(i*dx*r*2,1.3*r*-2.5,0),r,seg,cn);}
      
    {auto dx=1-(0.23/0.80);for(int i=-1;i<=+1;i++)if(i)for(int j=2;j<=5;j++)DrawLightedSphere(p+dy+vec3f(i*dx*r*2,1.3*r*-2.5-j*r*0.5,0),j==5?r:r*0.75,seg,cn);}
    /*
    for(int i=1;i<=3*2*5;i++){
      real leg_r=0.4*r;real hr=r*0.1;
      qDev.DrawSphere(vec3f(-r*0.5,-hr*i,0),leg_r,seg,cn);
      qDev.DrawSphere(vec3f(+r*0.5,-hr*i,0),leg_r,seg,cn);
    }*/
      beg=qDev.VPos;
    if(!light)
    {
      auto c=0.05;
      for(int i=beg;i<qDev.VPos;i++)
      {
        auto&v=qDev.VBA[i];
        auto&p=v.get_vec3f();
        v.color=QapColor::Mix(0?0xffc8c8c8:v.color,1?0xffc8c8c8:0xff000000,(p-lightpos).SqrMag()*c);
      }
    }
  }
  struct t_kb_flag{
    #define DEF_PRO_CLASSNAME()t_kb_flag
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(int,key,$)\
    ADD(bool,flag,$)\
    ADD(bool,need_init,true)\
    //===
    #include "defprovar.inl"
    //===
    bool update(int key,bool def_value){this->key=key;if(need_init){flag=def_value;need_init=false;}return flag;}
  };
  //(rettype,adduni,arr,field_type,field)
  PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(t_kb_flag,add_kb_flag,kb_flags,string,name);
  void DoDraw3D()
  {
    vec3f cube_pos=vec3f(-5,0,0);
    {
      SetMatrix();
      QapDev::BatchScope scope(qDev);
      
      t_vertex_light_scope lold(qDev,pos,QapKbOnDownDoInvFlag("global_vertex_light",VK_BACK,true));

      if(QapKbOnDownDoInvFlag("XYZ",'Z',true)){DrawXYZ();}

      if(QapKbOnDownDoInvFlag("VoxelSphere",'T',false))DrawKastrula();
      qDev.color=0xffffffff;
            
      /*
      qDev.color=0xffff0000;qDev.DrawCube(vec3f(10,00,00),vec3f_one);
      qDev.color=0xff00ff00;qDev.DrawCube(vec3f(00,10,00),vec3f_one);
      qDev.color=0xff0000ff;qDev.DrawCube(vec3f(00,00,10),vec3f_one);
      */
      
      qDev.SetColor(0xffffffff);
      
      //DrawHuman();
      //msg=IToS(kb.LastKey);
      auto VK_TILDA=192;
      if(QapKbOnDownDoInvFlag("DrawTilda",VK_TILDA,false)){
        lighted_scene.draw(qDev);
      }else{
        if(QapKbOnDownDoInvFlag("DrawBall",VK_MULTIPLY,true)){
          DrawBall();
        }else if(QapKbOnDownDoInvFlag("DrawScene",VK_DIVIDE,true))DrawScene();
      }
      if(bool mirror_test=false)
      {
        #define $ ((rand()%k)/real(k))*5
        static vector<vec3f> a,b;int n=0;int k=32*1024;
        if(a.empty())for(int i=0;i<n;i++){
          qap_add_back(a)=vec3f($,$,$);
          qap_add_back(b)=vec3f($,$,$);
        }
        for(int i=0;i<n;i++)
        {
          qDev.color=0xff000000+0x102080*(i%10);
          qDev.DrawCylinderAsLine(a[i],b[i],0.5,16,0);
        }
        static int u=(srand(GetTickCount()),0);
        static auto ld=vec3f($,$,$).Norm();
        static auto nn=vec3f($,$,$).Norm();
        qap_add_back(a)=ld;
        qap_add_back(a)=nn;
        /*
        +1+0+0
        +0+1+0
        +0+0+1
        */
        qap_add_back(a)=mirror(nn,-ld)*2;n=3;
        QapColor colors[3]={0xffff0000,0xff00ff00,0xff0000ff};
        //qap_add_back(a)
        //qap_add_back(a)=vec3f(-d.y,+d.x,+d.z);
        qap_add_back(a)=cross(-ld,nn).Norm();n=4;
        for(int i=0;i<n;i++)
        {
          qDev.color=i<3?colors[i]:0xff000000+0x102080*(i%10);
          qDev.DrawCylinderAsLine(a[i],vec3f_zero,0.5,16,0);
        }
        //qDev.DrawCylinderAsLine(vec3f(5,0,5),vec3f_zero,0.5,4,0);
        #undef $
      }
      //if(check_point(cube_pos))qDev.DrawCubeFast(cube_pos);
      //vmap.set(0,0,0,1);vmap.set(2,0,0,1);vmap.set(4,0,0,1);
      if(QapKbOnDownDoInvFlag("DrawCellWorld",VK_SUBTRACT,true))DrawCellWorld();
      if(0)
      {
        auto sc=0xffb0b0b0; real s=0.125;
        for(int y=0;y<mem.H;y++)for(int x=0;x<mem.W;x++)
        {
          //if(x*x+y*y>r*r)continue;if(x*x+y*y<G)continue;
          //qDev.SetColor((x+y)%2?0xffffffff:sc);
          auto c=getPix(x,y);
          real z=int((c.r+c.g+c.b)/3.0/256.0*32.0);
          qDev.color=c;
          //qDev.DrawCubeFast(vec3f(-x+mem.W/2,-3+z,y-mem.H/2)*s,vec3f_one*s);
          qDev.DrawCubeFast(vec3f(-x+mem.W/2,-8+z/2,y-mem.H/2)*s,vec3f(1,1+z,1)*s);
        }
      }
      //qDev.DrawSphere(vec3f(0,0,0),0.15,8,4);
      if(light)
      {
        auto c=0.3*0.015;
        for(int i=0;i<qDev.VPos;i++)
        {
          auto&v=qDev.VBA[i];
          auto&p=v.get_vec3f();
          v.color=QapColor::Mix(0?0xffc8c8c8:v.color,1?0xffc8c8c8:0xff000000,(p-pos).SqrMag()*c);
        }
      }
    }
    if(1)
    {
      auto our=get_matrics();
      D9Dev.Set2D();
      //D9Dev.pDev->SetRenderState(D3DRS_ZENABLE,false);
      //D9Dev.pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
      QapDev::BatchScope scope(qDev);
      qDev.SetColor(0xff000000);
      auto vertex_offset=vec3f(1,1,1)*0.5;
      vertex_offset=vec3f_zero;
      auto p=(cube_pos+vertex_offset)*our.world*our.view*our.proj;
      auto p2d=vec2d(p.x,p.y).Mul(win.GetClientSize())*0.5;
      //qDev.DrawCircle(vec2d(p.x,p.y).Mul(vec2d(1366,768)*0.5),16,0,2,32);
      if(p.z<1)for(;;)
      {
        if(p.x<-1)break;if(p.x>+1)break;
        if(p.y<-1)break;if(p.y>+1)break;
        //qDev.DrawQuad(p2d,32,32);
        break;
      }
    }
    SetMatrix();
    //D9Dev.pDev->SetRenderState(D3DRS_ZENABLE,true);
    int gg=1;
  }
  void Draw2DChessBoard()
  {
    qDev.color=0xFF000000;t_quad q;q.size=vec2d(800,600);qDev.DrawQuad(q.pos,q.size);auto wh=vec2i(3,16);
    for(int y=0;y<wh.y;y++)for(int x=0;x<wh.x;x++){
      qDev.color=(x+y)%2?0x80FFFFFF:0x800000FF;auto sq=q.get_subquad(wh,vec2d(x,y));qDev.DrawQuad(sq.pos,sq.size);
    }
  }
  void Draw2DDebug()
  {
    static t_trigon_vec2f t;
    static t_dir_quad dq;
    static bool once=true;if(once){once=false;
      QapLoadFromStr(t,file_get_contents("tris308.t_trigon_vec2f"));
      QapLoadFromStr(dq,file_get_contents("x0y16.dq.get_subquad"));
    }
    auto&q=dq.q;
    qDev.color=0xFF00FF00;real s=128;
    qDev.DrawQuad(q.pos*s,q.size*s);
    qDev.color=0xFFFFFF00;
    qDev.DrawTrigon(t.a*s,t.b*s,t.c*s);
  }
  void DoDraw()
  {
    clear();
    DoDraw3D();
    D9Dev.Set2D();
    
    D9Dev.pDev->SetRenderState(D3DRS_LIGHTING,false);
    D9Dev.pDev->SetRenderState(D3DRS_ZENABLE,false);
    D9Dev.pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
    
    qDev.color=0xFF000000;
    qap_text_draw_at_x_center(qDev,vec2d(0,-16),msg,16);
    //qap_text::draw(qDev,vec2d(0,0),msg,16);
    win.mpos=vec2i(0,0);
    DrawDownedKeys();
    //Draw2DDebug();
    //Draw2DChessBoard();
    return;
    D9Dev.Set2D();
    QapDev::BatchScope scope(qDev);
    qDev.SetColor(0xff000000);
    qDev.DrawCircle(vec2d_zero,20,0,3,32);
    DrawCubeMonoWithWire(vec3f(100,100,+2),0xff808080,vec3f_one*64,4);
  }
public:
// TGame
public:
  #define DEF_PRO_CLASSNAME()TGame
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(bool,need_init,true)\
  ADD(bool,space,true)\
  ADD(bool,light,false)\
  ADD(real,zoom,1)\
  ADD(vec3f,pos,$)\
  ADD(vec2i,mpos,$)\
  ADD(real,ang_x,$)\
  ADD(real,ang_y,$)\
  ADD(int,tick,0)\
  ADD(int,speed,5)\
  ADD(vector<vec3f>,cubes,$)\
  ADD(string,msg,$)\
  ADD(vector<t_link>,links,$)\
  ADD(t_phys_sphere,phys_sphere,$)\
  ADD(TOurMatrics,our_mat_buff,$)\
  ADD(vector<t_raycast_log>,raycast_logs,$)\
  ADD(vector<t_kb_flag>,kb_flags,$)\
  //===
  #include "defprovar.inl"
  //===
};
#include <memory.h>

void test_t_atomic_bits(){
  TGame::t_atomic_bits t;
  t.resize(0);
  t.resize(5);
  t.resize(7);
  t.resize(1);
  t.resize(8);
  t.resize(15);
  t.resize(16);
  t.resize(456);
  auto s0=t.atomic_set(2);
  auto s1=t.atomic_set(2);
  auto s2=t.atomic_set(9);
  auto s3=t.atomic_set(15);
  auto s5=t.atomic_set(455);
  string out;
  t.for_each([&](int i,bool ex){out+=ex?"1":"0";});
}

void test_qap_sys_with_arr_of_pod(){
  QapAssert(QapIsPOD<TGame::t_axis>());
  QapAssert(QapIsPOD<TGame::t_cell_quad>());
  QapAssert(QapIsPOD<int>());
  QapAssert(!QapIsPOD<string>());
  QapAssert(QapIsPOD<TGame::t_dir_quad>());
  vector<int> just_test;just_test.resize(19);
  auto un_used=QapSaveToStr(just_test);
  int gg=1;
  QapDebugMsg(
    "we can join several fields as single POD inside QapSave\n"
    "ADD(t_dir_quad,dq,$)                  POD            \n"
    "ADD(vec2i,dq_wh,$)                    POD            \n"
    "ADD(vector<t_cell_quad>,pos2info,$)   NOT_POD        \n"
    "ADD(vector<int>,mem,$)                NOT_POD        \n"
    "... so there first two 'IO.Save' can be done just in one call"
  );
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{

  srand(time(0));
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  SetCursorPos(GetScreenMode().W/2,GetScreenMode().H/2);
  TGame*on_heap(new TGame);
  TGame&builder=*on_heap;
  string fn="save_b2_10.sav";//"save_new.sav";
  if(access(fn.c_str(),0)==0)
  {
    QapLoadFromStrWithSizeOfType(builder,file_get_contents(fn));
  }
  builder.init();
  builder.DoNice();
  {
    file_put_contents(fn,QapSaveToStrWithSizeOfType(builder));
  }
}
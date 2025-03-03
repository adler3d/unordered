#include "StdAfx.h"

//template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr){arr.push_back(TYPE());return arr.back();}

class TBookPageWithRotQuad:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithRotQuad)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(real,ang,DEF,$,$)\
ADDVAR(int,speed,SET,1,$)\
ADDEND()
//=====+>>>>>TBookPageWithRotQuad
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithRotQuad
public:
  void Render(t_context&con)
  {
    con.qDev.SetColor(0x80000000);
    con.qDev.BindTex(0,nullptr);
    con.qDev.DrawQuad(con.pos,vec2d(20,80),ang);
  }
  void Update(t_context&con)
  {
    ang+=real(speed)*Pi/180.0;
  }
};

class t_looped_buffer{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_looped_buffer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<real>,frames,DEF,$,$)\
ADDVAR(int,n,SET,1024,$)\
ADDVAR(int,ptr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_looped_buffer
#include "QapGenStruct.inl"
//<<<<<+=====t_looped_buffer
public:
  void add(real value)
  {
    QapAssert(n>0);
    if(frames.size()!=n)frames.resize(n);
    ptr=ptr%n;
    frames[ptr]=value;
    ptr++;
    ptr=ptr%n;
  }
};

class TBookPageWithPerf:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithPerf)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,enabled,SET,true,$)\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(bool,auto_draw,SET,true,$)\
ADDVAR(bool,locked,DEF,$,$)\
ADDVAR(real,prev_value,DEF,$,$)\
ADDVAR(QapColor,color,SET,0x80000000,$)\
ADDVAR(t_looped_buffer,buff,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithPerf
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithPerf
public:
  void Render(t_context&con)
  {
    if(!auto_draw||!enabled)return;
    QapDev::BatchScope scope(con.qDev);
    con.qDev.SetColor(color);
    con.qDev.BindTex(0,nullptr);
    auto&arr=buff.frames; const auto n=buff.n; const auto ptr=buff.ptr;
    if(n==arr.size())
    {
      real maxv=*std::max_element(arr.begin(),arr.end());
      real minv=*std::min_element(arr.begin(),arr.end());
      //real h=maxv-minv;
      auto s=con.size;
      auto p=con.pos;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[(ptr+i)%n];
        real v=real(s.y)*ex/maxv;
        con.qDev.DrawQuad(p+vec2d(-s.x*0.5+s.x*real(i)/real(n),-s.y/2+v/2),vec2d(real(s.x)/real(n),v));
      }
    }
  }
  void Update(t_context&con)
  {
    if(!auto_move||!enabled)return;
    static QapClock clock;
    if(!clock.run)
    {
      clock.Start();
    }
    if(con.is_hovered()&&con.kb.OnDown('E'))
    {
      locked=!locked;
      prev_value=clock.MS();
    }
    if(locked){return;}
    if(buff.n<1)buff.n=1;
    auto ms=clock.MS();
    auto v=ms-prev_value;
    if(v>0)
    {
      buff.add(v);
    }
    prev_value=ms;
  }
};

class TBookPageWithFpsQuad:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithFpsQuad)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(real,ang,DEF,$,$)\
ADDVAR(int,speed,SET,1,$)\
ADDVAR(string,init_time,DEF,$,$)\
ADDVAR(string,start_time,DEF,$,$)\
ADDVAR(string,cur_time,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(real,dt,DEF,$,$)\
ADDVAR(real,uptime,DEF,$,$)\
ADDVAR(real,avg_dt,DEF,$,$)\
ADDVAR(int,lags,DEF,$,$)\
ADDVAR(real,lag_time,DEF,$,$)\
ADDVAR(real,avg_lag,DEF,$,$)\
ADDVAR(int,app_restart_counter,DEF,$,$)\
ADDVAR(int,app_tick,DEF,$,$)\
ADDVAR(real,app_uptime,DEF,$,$)\
ADDVAR(real,app_avg_dt,DEF,$,$)\
ADDVAR(int,app_lags,DEF,$,$)\
ADDVAR(real,app_lag_time,DEF,$,$)\
ADDVAR(real,app_avg_lag,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithFpsQuad
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithFpsQuad
public:
  void Render(t_context&con)
  {
    RenderText(con);
  }
  void Update(t_context&con)
  {
    if(con.kb.OnDown(mbLeft))if(con.is_hovered())auto_move=!auto_move;
    if(auto_move)ang+=real(speed)*Pi/180.0;
    if(init_time.empty()){init_time=cur_date_str();app_restart_counter=-1;}
    static QapClock clock;
    if(!clock.run)
    {
      clock.Start();
      app_restart_counter++;
      start_time=cur_date_str();
      uptime=0;
      tick=0;
      lags=0;
      lag_time=0;
    }
    cur_time=cur_date_str();
    auto t=clock.MS();
    dt=t-uptime;
    app_tick++;
    tick++;
    avg_dt=uptime/real(tick);
    app_avg_dt=app_uptime/real(tick);
    uptime=t;
    if(dt>1000)
    {
          lags++;
          avg_lag=lag_time/real(lags);
          lag_time+=dt;
      app_lags++;
      app_avg_lag=app_lag_time/real(app_lags);
      app_lag_time+=dt;
      return;
    }
    app_uptime+=dt;
  }
  void RenderText(t_context&con)
  {
    auto&qDev=con.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      QapDev::BatchScope scope(con.qDev);
      qDev.BindTex(0,&pFont->Tex);
      qDev.SetColor(0xff000000);
      vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      auto add=[&](const string&text){
        QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);p.y+=-font.Info[0].y;
      };
      add("ups: "+FToS(1000.0/dt));
      add("dt: "+FToS(dt));
      add("avg_dt: "+FToS(avg_dt));
      add("tick: "+IToS(tick));
      add("lags: "+IToS(lags));
      add("lag_time: "+FToS(lag_time));
      add("uptime: "+FToS(uptime));
      add("restarts: "+IToS(app_restart_counter));
    }
    qDev.BindTex(0,0);
  }
};
//
//class t_world;
//
//class t_world_editor{
//public:
//#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_world_editor)
//#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
//ADDBEG()\
//ADDVAR(bool,enabled,DEF,$,$)\
//ADDVAR(QapColor,buff,DEF,$,$)\
//ADDVAR(int,noused11,DEF,$,$)\
//ADDVAR(int,noused12,DEF,$,$)\
//ADDVAR(QapColor,select_rect_border_color,DEF,$,$)\
//ADDVAR(int,select_rect_border_size,SET,2,$)\
//ADDEND()
////=====+>>>>>t_world_editor
//#include "QapGenStruct.inl"
////<<<<<+=====t_world_editor
//public:
//  typedef IBookPage::t_context t_context;
//public:
//  //===>>>---
//  #define MACRO_WEAK
//  #include "macro_scope.inl"
//  MACRO_WEAK_FUNC(vec2i,get_gp_mpos,(t_context&con,t_world&world),(con,world))
//  {
//    return world.PagePointToGamePoint(con.get_mpos());
//  }
//  MACRO_WEAK_FUNC(vec2i,get_sp_mpos,(t_context&con,t_world&world),(con,world))
//  {
//    return world.GamePointToScreenPoint(con,world.PagePointToGamePoint(con.get_mpos()));
//  }
//  MACRO_WEAK_PROC(TryCopyToBuff,(t_context&con,t_world&world),(con,world))
//  {
//    if(!enabled)return;
//    auto mpos=get_gp_mpos(con,world);
//    auto*p=world.safe_get_ref_to_color_from_map_at(mpos);
//    if(!p)return;
//    buff=*p;
//  }
//  MACRO_WEAK_PROC(TryPasteFromBuff,(t_context&con,t_world&world),(con,world))
//  {
//    if(!enabled)return;
//    auto mpos=get_gp_mpos(con,world);
//    auto*p=world.safe_get_ref_to_color_from_map_at(mpos);
//    if(!p)return;
//    *p=buff;
//  }
//  MACRO_WEAK_PROC(Render,(t_context&con,t_world&world),(con,world))
//  {
//    if(!enabled)return;
//    if(!PointInQuad(con.get_mpos(),vec2i_zero,con.size+vec2i(1,1)*world.cell_size/2))return;
//    auto&qDev=con.qDev;
//    qDev.SetColor(select_rect_border_color);qDev.color.a=0x80;
//    qDev.BindTex(0,nullptr);
//    auto size=vec2i(1,1)*world.cell_size;
//    auto p=get_sp_mpos(con,world);
//    qDev.DrawQuadWithHalfPixelOffset(p,size.x,size.y);
//  }
//  #include "macro_scope.inl"
//  //---<<<===
//};
//
//class t_hero{
//public:
//#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hero)
//#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
//ADDBEG()\
//ADDVAR(vec2i,pos,DEF,$,$)\
//ADDVAR(vec2i,v,DEF,$,$)\
//ADDVAR(int,hp,SET,10,$)\
//ADDVAR(int,score,DEF,$,$)\
//ADDVAR(vec2i,sp,DEF,$,$)\
//ADDVAR(vec2i,sv,DEF,$,$)\
//ADDEND()
////=====+>>>>>t_hero
//#include "QapGenStruct.inl"
////<<<<<+=====t_hero
//public:
//};
//
//class t_world{
//public:
//#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_world)
//#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
//ADDBEG()\
//ADDVAR(string,info,DEF,$,$)\
//ADDVAR(int,W,DEF,$,$)\
//ADDVAR(int,H,DEF,$,$)\
//ADDVAR(int,cell_size,SET,16,$)\
//ADDVAR(bool,draw_back,SET,false,$)\
//ADDVAR(bool,cwMode,DEF,$,$)\
//ADDVAR(bool,show_perf_info,SET,true,$)\
//ADDVAR(bool,without_tex,DEF,$,$)\
//ADDVAR(bool,draw_cross_cells,SET,false,$)\
//ADDVAR(bool,draw_back_tex,SET,true,$)\
//ADDVAR(int,noused11,DEF,$,$)\
//ADDVAR(int,noused12,DEF,$,$)\
//ADDVAR(int,tick,DEF,$,$)\
//ADDVAR(int,max_tick,SET,8,$)\
//ADDVAR(int,dHS,SET,8,$)\
//ADDVAR(int,n_half_scale_steps,SET,1,$)\
//ADDVAR(int,noused13,DEF,$,$)\
//ADDVAR(int,noused14,DEF,$,$)\
//ADDVAR(t_hero,hero,DEF,$,$)\
//ADDVAR(int,noused33,DEF,$,$)\
//ADDVAR(int,noused34,DEF,$,$)\
//ADDVAR(vec2i,cam_pos,DEF,$,$)\
//ADDVAR(bool,cam_attached,DEF,$,$)\
//ADDVAR(int,noused21,DEF,$,$)\
//ADDVAR(int,noused22,DEF,$,$)\
//ADDVAR(bool,need_reset_tex,DEF,$,$)\
//ADDVAR(bool,need_swap_tex,DEF,$,$)\
//ADDVAR(string,hero_tex,SET,"ball",$)\
//ADDVAR(string,cell_tex,SET,"quad",$)\
//ADDVAR(string,cur_map_fn,SET,"cell_map.png",$)\
//ADDVAR(int,noused23,DEF,$,$)\
//ADDVAR(int,noused24,DEF,$,$)\
//ADDVAR(t_world_editor,editor,DEF,$,$)\
//ADDVAR(int,noused25,DEF,$,$)\
//ADDVAR(int,noused26,DEF,$,$)\
//ADDVAR(vector<QapColor>,map,DEF,$,$)\
//ADDEND()
////=====+>>>>>t_world
//#include "QapGenStruct.inl"
////<<<<<+=====t_world
//public:
//  typedef IBookPage::t_context t_context;
//public:
//  void SetToDef()
//  {
//    RestartWorld();
//  }
//  void LoadWorldFromPNG(const string&fn,bool keep_hero_pos=false)
//  {
//    static const QapColor color=get_start_color();
//    QapTexFile File;
//    File.FN=fn;
//    File.Load();
//    W=File.Mem.W;
//    H=File.Mem.H;
//    map.resize(W*H);
//    auto&arr=File.Mem.Arr;
//    for(int y=0;y<H;y++)for(int x=0;x<W;x++)
//    {
//      auto&out=map[y*W+x];
//      auto&inp=arr[x+W*y];
//      out=inp;
//      if(inp==color)
//      {
//        out=get_empty_color();
//        if(!keep_hero_pos)
//        {
//          hero.pos=vec2i(x,y);
//          cam_pos=hero.pos;
//        }
//      }
//    }
//    int gg=1;
//  }
//  static void AddBorder(QapTexMem&Mem,QapTexMem&OutMem,int dHS=8,const QapColor&Color=0xffffffff)
//  {
//    int dS=dHS*2;
//    OutMem.Init(Mem.W+dS,Mem.H+dS);
//    OutMem.Clear(Color);
//    OutMem.FillMem(dHS,dHS,Mem);
//  }
//  static void DoBlur(QapTexMem&Mem,QapTexMem&Out,int dHS=8)
//  {
//    int dS=dHS*2;
//    QapTexMem&MemWithBorder=Out;
//    AddBorder(Mem,MemWithBorder,dHS,QapColor(200,200,200));
//    //MemWithBorder.CalcAlpha(0xffffffff);
//    //MemWithBorder.FillChannel(0x00ffffff,0x00ffffff);
//    MemWithBorder.BlurTexture(dHS);
//  }
//  void SaveWorldToPNG(const string&fn)
//  {
//    static const QapColor color=get_start_color();
//    QapTexFile File;
//    File.FN=fn;
//    File.Mem.W=W;
//    File.Mem.H=H;
//    map.resize(W*H);
//    File.Mem.Init(W,H);
//    auto&arr=File.Mem.Arr;
//    for(int y=0;y<H;y++)for(int x=0;x<W;x++)
//    {
//      auto&inp=map[y*W+x];
//      auto&out=arr[x+W*y];
//      out=inp;
//      if(hero.pos==vec2i(x,y))out=color;
//      if(inp==color)
//      {
//        out=get_empty_color();
//      }
//    }
//    File.Save();/*
//    QapTexFile out;
//    DoBlur(File.Mem,out.Mem);
//    out.FN="with_blur.png";
//    out.Save();*/
//    int gg=1;
//  }
//  void DrawWorldToPng(t_context&con,QapTexObject*pBackTex)
//  {
//    QapTexMem quad;
//    quad.GenQuad(cell_size);
//    QapTexMem ball;
//    ball.GenBall(cell_size/2);
//    QapTexMem white_rect;
//    white_rect.Init(cell_size,cell_size);
//    white_rect.Clear(0x00000000);
//    static const QapColor color=get_start_color();
//    static const QapColor empty=get_empty_color();
//    QapTexFile File;
//    QapTexMem&Mem=File.Mem;
//    Mem.Init(W*cell_size,H*cell_size);
//    Mem.Clear(0x00000000);//QapColor(200,200,200));
//    for(int y=0;y<H;y++)for(int x=0;x<W;x++)
//    {
//      auto inp=map[y*W+x];
//      if(hero.pos==vec2i(x,y))inp=color;
//      if(inp==get_score_inc_color()){
//        /*inp=empty;*/Mem.DrawMemWithBlend(x*cell_size+cell_size/4,y*cell_size+cell_size/4,ball,inp);continue;
//      }
//      if(inp==get_hp_inc_color()){
//        /*inp=empty;*/Mem.DrawMemWithBlend(x*cell_size+cell_size/4,y*cell_size+cell_size/4,ball,inp);continue;
//      }
//      if(inp==empty){
//        continue;//Mem.FillMem(x*cell_size,y*cell_size,white_rect);continue;
//      }
//      Mem.DrawMemWithBlend(x*cell_size,y*cell_size,quad,inp);
//      //Mem.
//    }
//    File.FN="all_software_world.png";File.Save();
//    QapTexMem inp;
//    inp.DrawInHalfScale(Mem,n_half_scale_steps);
//    Mem.CopyDataFrom(inp);
//    File.FN="all_software_world(small_size).png";File.Save();
//    DoBlur(inp,Mem,dHS);
//    QapTexMem tmp=Mem;
//    auto next_power_of_two=[](int W)->int{int w=1;for(;;){if(w>=W)break;w<<=1;}return w;};
//    {
//      auto w=next_power_of_two(tmp.W);
//      auto h=next_power_of_two(tmp.H);
//      Mem.Init(w,h);
//    }
//    Mem.Clear(0xffffffff);
//    Mem.FillMem(0,0,tmp);
//    File.FN="all_software_world(blured).png";
//    File.Save();
//    pBackTex->File.Mem.CopyDataFrom(Mem);
//    pBackTex->Gen.Do();//Run(con.Env,&con.root.D9Dev);
//    /*
//    auto&arr=Mem.Arr;
//    for(int y=0;y<H;y++)for(int x=0;x<W;x++)
//    {
//      auto&inp=map[y*W+x];
//      auto&out=arr[x+W*y];
//      out=inp;
//      if(hero.pos==vec2i(x,y))out=color;
//      if(inp==color)
//      {
//        out=get_empty_color();
//      }
//    }*/
//
//  }
//  void RestartWorld()
//  {
//    hero=std::move(t_hero());
//    info="^7begin!";
//    LoadWorldFromPNG(cur_map_fn);
//  }
//  void ReloadMap()
//  {
//    LoadWorldFromPNG(cur_map_fn,true);
//  }
//  void SaveMap()
//  {
//    SaveWorldToPNG(cur_map_fn);
//  }
//public:
//  //vec2i get_ps_cam_pos(){return GameVecToPageVec(cam_pos);}
//  vec2i GameVecToPageVec(const vec2i&pos)
//  {
//    return vec2i(pos.x,-pos.y)*cell_size;
//  }
//  vec2i PageVecToGameVec(const vec2i&pos)
//  {
//    auto offset=vec2i(1,1)*1024*16;
//    auto big_offset=offset*cell_size;
//    auto t=(pos+big_offset+vec2i(1,1)*(cell_size/2))/cell_size-offset;
//    return vec2i(t.x,-t.y);
//  }
//  vec2i PagePointToGamePoint(const vec2i&p)
//  {
//    return PageVecToGameVec(p)+cam_pos;
//  }
//  vec2i GamePointToPagePoint(const vec2i&p)
//  {
//    return GameVecToPageVec(p-cam_pos);
//  }
//  vec2i GamePointToScreenPoint(t_context&con,const vec2i&p)
//  {
//    auto gs=p-cam_pos;
//    return con.PageSpaceToScreenSpace(GameVecToPageVec(gs));
//  }
//public:
//  QapColor*safe_get_ref_to_color_from_map_at(const vec2i&pos)
//  {
//    auto x=pos.x;auto y=pos.y;
//    bool a=x>=0&&x<W;
//    bool b=y>=0&&y<H;
//    if(!a||!b)return nullptr;
//    if(map.size()!=W*H)return nullptr;
//    if(map.empty())return nullptr;
//    return &map[W*y+x];
//  }
//public:
//  void DrawQuad(t_context&con,int x,int y)
//  {
//    auto p=GamePointToScreenPoint(con,vec2i(x,y));
//    con.qDev.DrawQuadWithHalfPixelOffset(p,cell_size,cell_size);
//  }
//  void DrawQuad(t_context&con,const vec2i&pos)
//  {
//    auto p=GamePointToScreenPoint(con,pos);
//    con.qDev.DrawQuadWithHalfPixelOffset(p,cell_size,cell_size);
//  }
//  void DrawQuad(t_context&con,const vec2i&pos,real scale)
//  {
//    auto p=GamePointToScreenPoint(con,pos);
//    con.qDev.DrawQuadWithHalfPixelOffset(p,cell_size*scale,cell_size*scale);
//  }
//  void DrawQuad_back(t_context&con,const vec2i&pos,real scale=1.2)
//  {
//    auto p=GamePointToScreenPoint(con,pos);
//    con.qDev.DrawQuadWithHalfPixelOffset(p,cell_size*scale,cell_size*scale);
//  }
//  void DrawQuad_back(t_context&con,int x,int y,real scale=1.2)
//  {
//    DrawQuad_back(con,vec2i(x,y),scale);
//  }
//  QapTex*get_quad(t_context&con){
//    if(!con.root.SysRes.QuadTex)return nullptr;
//    return &con.root.SysRes.QuadTex->Tex;
//  }
//  QapTex*get_ball(t_context&con){
//    if(!con.root.SysRes.BallTex)return nullptr;
//    return &con.root.SysRes.BallTex->Tex;
//  }
//  QapTex*get_hero_tex(t_context&con){
//    if(hero_tex=="ball")return get_ball(con);
//    if(hero_tex=="quad")return get_quad(con);
//    return nullptr;
//  }
//  QapTex*get_cell_tex(t_context&con){
//    if(cell_tex=="ball")return get_ball(con);
//    if(cell_tex=="quad")return get_quad(con);
//    return nullptr;
//  }
//  void RenderCellWorld(t_context&con)
//  {
//    if(map.size()!=W*H)return;
//    if(map.empty())return;
//    auto&qDev=con.qDev;
//    //auto ps_cam_pos=get_ps_cam_pos();
//    QapTex*ball=get_ball(con);
//    QapTex*quad=get_quad(con);
//    QapColor back_color=0xffffffff;
//    QapColor gray_color=0xff808080;
//    if(draw_back)
//    {
//      qDev.BindTex(0,nullptr);
//      qDev.SetColor(back_color);
//      auto p=con.pos-GameVecToPageVec(cam_pos)+cell_size*vec2i(W,-H)/2;
//      qDev.DrawQuadWithHalfPixelOffset(p,cell_size*W,cell_size*H);
//    }
//    if(ball)
//    {
//      qDev.BindTex(0,ball);
//      QapDev::BatchScope Scope(qDev);
//      for(int y=0;y<H;y++)for(int x=0;x<W;x++)
//      {
//        auto&ex=map[y*W+x];
//        if(ex==back_color)continue;
//        if(ex==gray_color)continue;
//        qDev.SetColor(ex);
//        DrawQuad(con,x,y);
//      }
//    }
//    if(quad)
//    {
//      qDev.BindTex(0,quad);
//      QapDev::BatchScope Scope(qDev);
//      for(int y=0;y<H;y++)for(int x=0;x<W;x++)
//      {
//        auto&ex=map[y*W+x];
//        if(ex!=gray_color)continue;
//        qDev.SetColor(ex);
//        DrawQuad(con,x,y);
//      }
//    }
//  }
//  void Render(t_context&con,QapTexObject*pBackTex)
//  {
//    QapClock clock;
//    clock.Start();
//    RenderWorld(con,pBackTex);
//    clock.Stop();
//    if(show_perf_info)RenderText(con,"^0RenderWorld = "+FToS(clock.MS())+" ms."+(info.empty()?"":"        "+info));
//  }
//  void RenderText(t_context&con,const string&text)
//  {
//    auto&qDev=con.qDev;
//    if(!con.root.SysRes.FontObj)return;
//    auto*pFont=con.root.SysRes.FontObj.get();
//    auto&font=con.root.SysRes.FontObj->Font;
//    {
//      qDev.BindTex(0,&pFont->Tex);
//      vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
//      auto add=[&](const string&text){
//        QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);
//      };
//      add(text);
//      qDev.BindTex(0,0);
//    }
//  }
//  static vec2i ClampPointToQuad(const vec2i&point,const vec2i&pos,const vec2i&size)
//  {
//    #define F(x)Clamp(point.x,pos.x-size.x/2,pos.x+size.x/2)
//    return vec2i(F(x),F(y));
//    #undef F
//  }
//  static vec2i ClampPointToRect(const vec2i&point,const vec2i&a,const vec2i&b)
//  {
//    #define F(x)Clamp(point.x,a.x,b.x)
//    return vec2i(F(x),F(y));
//    #undef F
//  }
//  struct TClipper{
//    struct t_rect{
//      vec2i a;
//      vec2i b;
//      void norm(){
//        if(a.x>b.x)std::swap(a.x,b.x);
//        if(a.y>b.y)std::swap(a.y,b.y);
//      }
//      vec2i clamp(const vec2i&ref){return vec2i(Clamp<int>(ref.x,a.x,b.x),Clamp<int>(ref.y,a.y,b.y));}
//      static real unlerp(real a,real b,real v){auto out=(v-a)/(b-a); QapAssert(out>=0&&out<=1.0);return out;}
//      vec2d unlerp(const vec2i&v){return vec2d(unlerp(a.x,b.x,v.x),unlerp(a.y,b.y,v.y));}
//    };
//    struct t_quad{
//      vec2i pos;
//      vec2i size;
//    };
//    QapDev&qDev;
//    vec2i pos;
//    vec2i size;
//    vec2i c_pos;
//    vec2i c_size;
//    static t_rect get_rect(const t_quad&ref){t_rect t={ref.pos-ref.size/2,ref.pos+ref.size/2};return t;}
//    //static t_rect get_quad(const t_quad&ref){t_rect t={ref.pos-ref.size/2,ref.pos+ref.size/2};return t;}
//    void main()
//    {
//      t_quad qa={pos,size}; t_quad qc={c_pos,c_size};
//      auto a=get_rect(qa);if(a.a.x==a.b.x)return;if(a.a.y==a.b.y)return;
//      auto c=get_rect(qc);
//      c.norm();
//      auto na=c.clamp(a.a);
//      auto nb=c.clamp(a.b);
//      if(na.x==nb.x)return;
//      if(na.y==nb.y)return;
//      auto ta=a.unlerp(na);ta.y=1.f-ta.y;
//      auto tb=a.unlerp(nb);tb.y=1.f-tb.y;
//      {
//        QapDev::BatchScope Scope(qDev);
//        qDev.SetColor(0xffffffff);
//        auto a=qDev.AddVertex(nb,qDev.color,vec2f(tb.x,tb.y));
//        auto b=qDev.AddVertex(vec2i(na.x,nb.y),qDev.color,vec2f(ta.x,tb.y));
//        auto c=qDev.AddVertex(na,qDev.color,vec2f(ta.x,ta.y));
//        auto d=qDev.AddVertex(vec2i(nb.x,na.y),qDev.color,vec2f(tb.x,ta.y));
//        qDev.AddTris(a,b,c);
//        qDev.AddTris(c,d,a);
//      }
//      //qDev.SetColor(0xff00ff00);
//      //qDev.DrawRect(na,nb,4);
//    }
//  };
//  void RenderWorld(t_context&con,QapTexObject*pBackTex)
//  {
//    auto check_point=[&](const vec2i&point){return PointInQuad(GamePointToPagePoint(point),vec2i_zero,con.size+vec2i(1,1)*cell_size/2);};
//    if(cwMode){RenderCellWorld(con);return;}
//    if(map.size()!=W*H)return;
//    if(map.empty())return;
//    auto&qDev=con.qDev;
//    //auto ps_cam_pos=get_ps_cam_pos();
//    QapTex*hero_tex=get_hero_tex(con);
//    QapTex*cell_tex=get_cell_tex(con);
//    QapTex*ball_tex=get_ball(con);
//    static const auto empty_color=get_empty_color();
//    static const auto score_inc_color=get_score_inc_color();
//    static const auto hp_inc_color=get_hp_inc_color();
//    static bool disable_all_for_debug=false;
//    if(hero_tex||without_tex)if(check_point(hero.pos))if(!disable_all_for_debug)
//    {
//      qDev.BindTex(0,without_tex?nullptr:hero_tex);
//      QapDev::BatchScope Scope(qDev);
//      qDev.SetColor(0xff909090);
//      qDev.color.a=0x80;
//      DrawQuad_back(con,hero.pos);
//    }
//    if(pBackTex&&draw_back_tex)if(pBackTex->Tex)
//    {
//      qDev.BindTex(0,&pBackTex->Tex);
//      auto p=GamePointToScreenPoint(con,vec2i(W/2-1,H/2-1));
//      qDev.SetColor(0xffffffff);
//      int tex_scale_for_blur=1;auto&tsfb=tex_scale_for_blur;
//      for(int i=0;i<n_half_scale_steps;i++)tsfb<<=1;
//      auto zoom=vec2d(vec2i(W,H)*cell_size/tsfb+vec2i(1,1)*dHS*2);
//      zoom.x*=1.0/real(pBackTex->Tex.W);
//      zoom.y*=1.0/real(pBackTex->Tex.H);
//      qDev.txf=MakeZoomTransform(zoom);
//      {
//        QapDev::BatchScope Scope(qDev);
//        vec2i quad_pos=p+vec2i(+1,-1)*(cell_size/2);
//        vec2i quad_size=vec2i(W*cell_size+(dHS*2)*tsfb,H*cell_size+(dHS*2)*tsfb);
//        //con.pos;con.size;
//        TClipper clipper={qDev,quad_pos,quad_size,con.pos,con.size};
//        clipper.main();
//      }
//      qDev.txf.set_ident();
//      qDev.BindTex(0,nullptr);
//    }
//    if(draw_back)if(!disable_all_for_debug)
//    {
//      qDev.BindTex(0,nullptr);
//      QapDev::BatchScope Scope(qDev);
//      auto top=PagePointToGamePoint(+vec2i(+con.size.x,-con.size.y)/2)+vec2i(1,1);
//      auto low=PagePointToGamePoint(-vec2i(+con.size.x,-con.size.y)/2);//-vec2i(1,1);
//      top=ClampPointToRect(top,vec2i_zero,vec2i(W,H));
//      low=ClampPointToRect(low,vec2i_zero,vec2i(W,H));
//      for(int y=low.y;y<top.y;y++)for(int x=low.x;x<top.x;x++)
//      {
//        auto&ex=map[y*W+x];
//        if(ex!=empty_color)continue;
//        qDev.SetColor(0x10000000);//qDev.color.a=0x20;
//        DrawQuad_back(con,x,y,0.5);
//      }
//    }
//    if(cell_tex||without_tex)if(!disable_all_for_debug)
//    {
//      qDev.BindTex(0,without_tex?nullptr:cell_tex);
//      QapDev::BatchScope Scope(qDev);
//      auto top=PagePointToGamePoint(+vec2i(+con.size.x,-con.size.y)/2)+vec2i(1,1);
//      auto low=PagePointToGamePoint(-vec2i(+con.size.x,-con.size.y)/2);//-vec2i(1,1);
//      top=ClampPointToRect(top,vec2i_zero,vec2i(W,H));
//      low=ClampPointToRect(low,vec2i_zero,vec2i(W,H));
//      for(int y=low.y;y<top.y;y++)for(int x=low.x;x<top.x;x++)
//      {
//        auto&ex=map[y*W+x];
//        if(ex==empty_color)continue;
//        if(ex==score_inc_color)continue;
//        if(ex==hp_inc_color)continue;
//        //if(!PointInQuad(GamePointToPagePoint(vec2i(x,y)),vec2i_zero,con.size+vec2i(1,1)*cell_size/2))continue;
//        qDev.SetColor(ex);
//        DrawQuad(con,x,y);
//      }
//    }
//    if(ball_tex||without_tex)if(!disable_all_for_debug)
//    {
//      qDev.BindTex(0,without_tex?nullptr:ball_tex);
//      QapDev::BatchScope Scope(qDev);
//      auto top=PagePointToGamePoint(+vec2i(+con.size.x,-con.size.y)/2)+vec2i(1,1);
//      auto low=PagePointToGamePoint(-vec2i(+con.size.x,-con.size.y)/2);//-vec2i(1,1);
//      top=ClampPointToRect(top,vec2i_zero,vec2i(W,H));
//      low=ClampPointToRect(low,vec2i_zero,vec2i(W,H));
//      for(int y=low.y;y<top.y;y++)for(int x=low.x;x<top.x;x++)
//      {
//        auto&ex=map[y*W+x];
//        if((ex!=score_inc_color)&&(ex!=hp_inc_color))continue;
//        qDev.SetColor(ex);
//        DrawQuad_back(con,x,y,0.5);
//      }
//    }
//    //pass for draw cross cells
//    if(draw_cross_cells)if(!disable_all_for_debug)
//    {
//      qDev.BindTex(0,nullptr);
//      QapDev::BatchScope Scope(qDev);
//      auto top=PagePointToGamePoint(+vec2i(+con.size.x,-con.size.y)/2)+vec2i(1,1);
//      auto low=PagePointToGamePoint(-vec2i(+con.size.x,-con.size.y)/2);//-vec2i(1,1);
//      top=ClampPointToRect(top,vec2i_zero,vec2i(W,H));
//      low=ClampPointToRect(low,vec2i_zero,vec2i(W,H));
//      for(int y=low.y;y<top.y;y++)for(int x=low.x;x<top.x;x++)
//      {
//        auto&ex=map[y*W+x];
//        if(ex==empty_color)continue;
//        if(ex==get_score_inc_color())continue;
//        static vector<int> carr;carr.clear();
//        int c=0;
//        auto add=[&](int X,int Y)
//        {
//          auto*ptr=safe_get_ref_to_color_from_map_at(vec2i(x+(X),y+(Y)));
//          if(!ptr){carr.push_back(0);return;}
//          carr.push_back(*ptr==ex);
//          if(carr.back())c++;
//        };
//        for(int i=0;i<9;i++){
//          auto dx=(i%3-1);
//          auto dy=(i/3-1);
//          if(!dx&&!dy){carr.push_back(1);continue;}
//          add(dx,dy);
//        }
//        if(!c)continue;
//        int bb=1;
//        auto draw=[&](const vec2d&offset,real kx,real ky)
//        {
//          qDev.SetColor(ex);
//          auto p=GamePointToScreenPoint(con,vec2i(x,y));
//          con.qDev.DrawQuadWithHalfPixelOffset(p+vec2i(offset.x*cell_size,-offset.y*cell_size),cell_size*kx,cell_size*ky);
//        };
//        if(c==8)
//        {
//          draw(vec2d_zero,1.0,1.0);
//          continue;
//        }
//        [&]()
//        {
//          struct t_info{real kx;real ky;real ox;real oy;string s;};
//          for(int i=0;i<9;i++){
//            auto dx=(i%3-1);
//            auto dy=(i/3-1);
//            if(!dx&&!dy)continue;
//            if(!carr[i])continue;
//            if(dx&&dy){
//              auto xy2id=[](int dx,int dy)->int{return dx+1+(dy+1)*3;};
//              bool x=carr[xy2id(dx,+0)];
//              bool y=carr[xy2id(+0,dy)];
//              if(x&&y)draw(vec2d(dx,dy)*0.75*0.5,0.25,0.25);
//            }
//            if(bool(dx)!=bool(dy))draw(vec2d(dx,dy)*0.25,0.5,0.5);
//          }
//        }();
//        int gg=1;
//      }
//    }
//    if(hero_tex||without_tex)if(check_point(hero.pos))if(!disable_all_for_debug)
//    {
//      qDev.BindTex(0,without_tex?nullptr:hero_tex);
//      QapDev::BatchScope Scope(qDev);
//      if(hero.hp<=0)
//      {
//        qDev.SetColor(0xfffffff50);
//        DrawQuad(con,hero.pos);
//      }else{
//        qDev.SetColor(0xff909090);
//        DrawQuad(con,hero.pos);
//        qDev.SetColor(0xff80ff00);//qDev.color.a=Clamp<int>((10-hero.hp)*32,0,255);
//        auto r=Lerp<real>(0,0.7,hero.hp*0.1);
//        DrawQuad_back(con,hero.pos,r);
//      }
//      /*else{
//        qDev.SetColor(0xff909090);
//        DrawQuad(con,hero.pos);
//        qDev.SetColor(0xffffffff);qDev.color.a=Clamp<int>((2-hero.hp)*128,0,255);
//        DrawQuad_back(con,hero.pos,2.0);
//        qDev.SetColor(0xffffff00);qDev.color.a=Clamp<int>((10-hero.hp)*16,0,255);
//        DrawQuad_back(con,hero.pos,1.5);
//        qDev.SetColor(0xffff0000);qDev.color.a=Clamp<int>((5-hero.hp)*32,0,255);
//        DrawQuad_back(con,hero.pos,0.5);
//      }*/
//    }
//    if(false)
//    {
//      QapDev::BatchScope Scope(qDev);
//      qDev.BindTex(0,nullptr);
//      qDev.SetColor(0xff000000);
//      auto hp_bar_pos=GamePointToScreenPoint(con,hero.pos)+vec2i(0,cell_size);
//      qDev.DrawQuadWithHalfPixelOffset(hp_bar_pos,34,8);
//      
//      qDev.SetColor(0xff00ff00);
//      auto size=Clamp<int>(hero.hp*3,0,30);
//      auto offset=vec2i(30/2-size/2,0);
//      qDev.DrawQuadWithHalfPixelOffset(hp_bar_pos-offset,size,4);
//    }
//    editor.Render(con,*this);
//    int gg=1;
//  }
//public:
//  void foo(){
//    struct t_color_info{
//      QapColor c;
//      string info;
//    };
//    #define F(INFO,R,G,B)
//    F("hero.hp--;",237,28,36);
//    F("hero.hp++;",239,228,176);
//    F("zero_grav();hero.hp--;",255,174,201);
//    F("nothing();",0,0,0);
//    F("zero_grav();",63,72,204);
//    F("to_empty();hero.score++;",255,242,0);
//    F("finish();",181,230,29);
//    #undef F
//  }
//  static QapColor get_empty_color(){
//    return QapColor(255,255,255);
//  }
//  static QapColor get_start_color(){
//    return QapColor(153,217,234);
//  }
//  static QapColor get_finish_color(){
//    return QapColor(181,230,29);
//  }
//  static QapColor get_zero_gravity_color(){
//    return QapColor(63,72,204);
//  }
//  static QapColor get_hp_dec_color(){
//    return QapColor(237,28,36);
//  }
//  static QapColor get_hp_inc_color(){
//    return QapColor(239,228,176);
//  }
//  static QapColor get_hp_dec_zg_color(){
//    return QapColor(255,174,201);
//  }
//  static QapColor get_score_inc_color(){
//    return QapColor(255,242,0);
//  }
//  bool is_upable_cell(const vec2i&pos)
//  {
//    static const QapColor arr[]={
//      get_zero_gravity_color(),
//    };
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    auto&c=*pc;
//    for(int i=0;i<lenof(arr);i++)if(c==arr[i])return true;
//    return false;
//  }
//  bool is_passable_cell(const vec2i&pos)
//  {
//    static const QapColor arr[]={
//      get_empty_color(),
//      get_zero_gravity_color(),
//      get_start_color(),
//      get_finish_color(),
//      get_hp_dec_color(),
//      get_hp_dec_zg_color(),
//      get_score_inc_color(),
//      get_hp_inc_color()
//    };
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    auto&c=*pc;
//    for(int i=0;i<lenof(arr);i++)if(c==arr[i])return true;
//    return false;
//  }
//  bool is_zero_gravity_cell(const vec2i&pos)
//  {
//    static const QapColor arr[]={
//      get_zero_gravity_color(),
//      get_hp_dec_zg_color()
//    };
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    auto&c=*pc;
//    for(int i=0;i<lenof(arr);i++)if(c==arr[i])return true;
//    return false;
//  }
//  bool is_finish_cell(const vec2i&pos)
//  {
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    static const QapColor color=get_finish_color();
//    return *pc==color;
//  }
//  bool is_hp_dec_cell(const vec2i&pos)
//  {
//    static const QapColor arr[]={
//      get_hp_dec_color(),
//      get_hp_dec_zg_color()
//    };
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    auto&c=*pc;
//    for(int i=0;i<lenof(arr);i++)if(c==arr[i])return true;
//    return false;
//  }
//  bool is_hp_inc_cell(const vec2i&pos)
//  {
//    static const QapColor arr[]={
//      get_hp_inc_color(),
//    };
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    auto&c=*pc;
//    for(int i=0;i<lenof(arr);i++)if(c==arr[i])return true;
//    return false;
//  }
//  bool is_score_inc_cell(const vec2i&pos)
//  {
//    auto*pc=safe_get_ref_to_color_from_map_at(pos);
//    if(!pc)return false;
//    static const QapColor color=get_score_inc_color();
//    return *pc==color;
//  }
//  vec2i get_v_form_keyboard_arrows(QapKeyboard&kb)
//  {
//    vec2i v;
//    #define F(dx,dy,key)if(kb.Down[key]){v.x+=dx;v.y+=dy;}
//    F(-1,+0,VK_LEFT);
//    F(+1,+0,VK_RIGHT);
//    F(+0,-1,VK_UP);
//    F(+0,+1,VK_DOWN);
//    #undef F
//    return v;
//  }
//  void Update_hero_keyboard(t_context&con)
//  {
//    auto old_v=hero.v;
//    hero.v=get_v_form_keyboard_arrows(con.kb);
//    auto&p=hero.pos;auto&v=hero.v;
//    //if(is_empty_cell(p+v)){p+=v;break;}
//    if(v.y<0)if(!is_upable_cell(p))v.y=0;
//    if(!is_zero_gravity_cell(p)&&!is_upable_cell(p+vec2i(0,1)))v.y=1;
//    //if(!is_zero_gravity_cell(p+vec2i(0,1)))v.y=1;
//    auto nx=vec2i(v.x,0);
//    auto ny=vec2i(0,v.y);
//    bool px=is_passable_cell(p+nx);
//    bool py=is_passable_cell(p+ny);
//    bool pv=is_passable_cell(p+v);
//    if(v.x&&v.y)
//    {
//      if(px&&py&&pv)return;
//      if(!py&&px){v.y=0;return;}
//      if(!px&&py){v.x=0;return;}
//      if(!pv&&px&&py)
//      {
//        if(old_v.x&&old_v.y){v.x=0;return;/*QapDebugMsg("not tested\nold_v.x&&old_v.y");*/}
//        if(old_v.x&&!old_v.y){v.x=0;return;}
//        if(old_v.y&&!old_v.x){v.y=0;return;}
//        if(!old_v.x&&!old_v.y){v.x=0;return;}
//        QapDebugMsg("not tested at all");
//        return;
//      }
//    }
//    if(v.x&&!v.y)if(px)return;
//    if(v.y&&!v.x)if(py)return;
//    //#define F(X,Y){auto nv=vec2i(v.x*X,v.y*Y);if(is_passable_cell(p+nv)){v=nv;return;}}
//    ////F(1,1);
//    //F(0,1);
//    //F(1,0);
//    //#undef F
//    v=vec2i(0,0);
//  }
//  void Update_hero_pos(t_context&con)
//  {
//    tick++;
//    if(tick%max_tick!=0){return;}
//    auto to_empty=[&](){*safe_get_ref_to_color_from_map_at(hero.pos)=get_empty_color();};
//    if(is_hp_dec_cell(hero.pos)){hero.hp--;info="hp : ^1"+IToS(hero.hp);}
//    if(is_hp_inc_cell(hero.pos)){hero.hp++;info="hp : ^2"+IToS(hero.hp);to_empty();}
//    if(is_score_inc_cell(hero.pos)){
//      hero.score++;
//      info="score : ^3"+IToS(hero.score);
//      to_empty();
//    }
//    if(hero.hp>0&&!is_finish_cell(hero.pos))
//    {
//      Update_hero_keyboard(con);
//      hero.pos+=hero.v;
//    }
//    if(is_finish_cell(hero.pos))info="^2win";
//    if(hero.hp<0){info="^1game over";hero.hp=0;}
//  }
//  void Update_cam_keyboard(t_context&con)
//  {
//    vec2i v=get_v_form_keyboard_arrows(con.kb);
//    cam_pos+=v;
//  }
//  void Update_keyboard(t_context&con)
//  {
//    if(!con.is_hovered())return;
//    con.kb.Down[VK_CONTROL]||cwMode||editor.enabled?Update_cam_keyboard(con):Update_hero_pos(con);
//  }
//  void Update_handle_flags()
//  {
//    if(!editor.enabled)if(cam_attached){cam_pos=hero.pos;}
//    if(need_reset_tex){need_reset_tex=false;hero_tex="quad";cell_tex="ball";}
//    if(need_swap_tex){need_swap_tex=false;std::swap(hero_tex,cell_tex);}
//    if(cwMode){cam_attached=false;}
//  }
//  void Update(t_context&con,QapTexObject*pBackTex)
//  {
//    Update_keyboard(con);
//    //if OnDown
//    #define F(KEY,CODE){if(con.kb.OnDown(KEY)){CODE}}
//    F('T',{cam_attached=!cam_attached;});
//    F('U',{ReloadMap();});
//    F('R',{RestartWorld();});
//    F('E',{editor.enabled=!editor.enabled;});
//    F('S',{SaveMap();});
//    F(VK_F12,{DrawWorldToPng(con,pBackTex);});
//    #undef F
//    //if Down
//    #define F(KEY,CODE){if(con.kb.Down[KEY]){CODE}}
//    F('C',{editor.TryCopyToBuff(con,*this);});
//    F('V',{editor.TryPasteFromBuff(con,*this);});
//    #undef F
//    Update_handle_flags();
//  }
//};
//
//class TBookPageWithPlatformer:public IBookPage{
//public:
//#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithPlatformer)PARENT(IBookPage)
//#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
//ADDBEG()\
//ADDVAR(TResourceHolder,ResHolder,DEF,$,$)\
//ADDVAR(TWeakPtr<QapTexObject>,pBackTex,DEF,$,$)\
//ADDVAR(bool,need_init,SET,true,$)\
//ADDVAR(string,info,DEF,$,$)\
//ADDVAR(t_world,world,DEF,$,$)\
//ADDEND()
////=====+>>>>>TBookPageWithPlatformer
//#include "QapGenStruct.inl"
////<<<<<+=====TBookPageWithPlatformer
//public:
//  void Render(t_context&con)
//  {
//    if(!pBackTex)return;
//    world.Render(con,pBackTex.get());
//  }
//  void Update(t_context&con)
//  {
//    if(need_init)
//    {
//      need_init=false;
//      Caption="Platformer";
//      world.SetToDef();
//      pBackTex=con.root.ResList.AddItem<QapTexObject>(con.Env,ResHolder,"TBookPageWithPlatformer");
//      pBackTex->SetToDef();
//      pBackTex->File.FN="all_software_world(blured).png";
//      pBackTex->Run(con.Env,&con.root.D9Dev);
//    }
//    world.Update(con,pBackTex.get());
//  }
//};
//
//class TBookPageTextFromFileV01:public IBookPage{
//public:
//  class TProfiler{
//  public:
//  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProfiler)OWNER(TBookPageTextFromFileV01)
//  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
//  ADDBEG()\
//  ADDVAR(bool,need_reset,DEF,$,$)\
//  ADDVAR(int,n,DEF,$,$)\
//  ADDVAR(real,total_rt,DEF,$,$)\
//  ADDVAR(real,rt,DEF,$,$)\
//  ADDVAR(real,total_pde,DEF,$,$)\
//  ADDVAR(real,pde,DEF,$,$)\
//  ADDEND()
//  //=====+>>>>>TProfiler
//  #include "QapGenStruct.inl"
//  //<<<<<+=====TProfiler
//  public:
//  };
//public:
//#define DEF_PRO_NESTED(F)F(TProfiler)
//#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageTextFromFileV01)PARENT(IBookPage)
//#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
//ADDBEG()\
//ADDVAR(string,text,DEF,$,$)\
//ADDVAR(string,fn,SET,"test_new.txt",$)\
//ADDVAR(bool,need_load_text,SET,true,$)\
//ADDVAR(int,border,SET,5,$)\
//ADDVAR(int,caret_pos,DEF,$,$)\
//ADDVAR(vec2i,car_pos,DEF,$,$)\
//ADDVAR(int,sel_caret_pos,DEF,$,$)\
//ADDVAR(int,tick,DEF,$,$)\
//ADDVAR(int,max_tick,SET,32,$)\
//ADDVAR(bool,caret_debug,DEF,$,$)\
//ADDVAR(bool,show_caret,SET,true,$)\
//ADDVAR(bool,readonly,DEF,$,$)\
//ADDVAR(vec2i,dc_mpos,DEF,$,$)\
//ADDVAR(int,dc_tick,DEF,$,$)\
//ADDVAR(int,dc_max_tick,SET,32,$)\
//ADDVAR(bool,is_double_click,DEF,$,$)\
//ADDVAR(int,scroll_y,DEF,$,$)\
//ADDVAR(int,scroll_lines,SET,3,$)\
//ADDVAR(bool,log_enabled,DEF,$,$)\
//ADDVAR(int,log_tick,DEF,$,$)\
//ADDVAR(vector<string>,logs,DEF,$,$)\
//ADDVAR(TProfiler,profiler,DEF,$,$)\
//ADDEND()
////=====+>>>>>TBookPageTextFromFileV01
//#include "QapGenStruct.inl"
////<<<<<+=====TBookPageTextFromFileV01
//public:
//  bool is_selected(){return caret_pos!=sel_caret_pos;}
//public:
//  struct t_text_renderer
//  {
//    const int scroll_y;
//    const int scroll_lines;
//    const vec2i con_pos;
//    const vec2i con_size;
//    const int border;
//    const string&text;
//    const int caret_pos;
//    const int sel_caret_pos;
//    bool caret_detected;
//    bool sel_car_detected;
//    vec2i caret_p;
//    vec2i sel_car_p;
//    int x;
//    int y;
//    int dx;
//    int dy;
//    int cx;
//    int cy;
//    int max_x;
//    int caret;
//    vec2i pos;
//    vec2i mpos;
//    int mpos_id;
//    bool need_find_mpos_id;
//    //vector<string> lines;
//    vector<QapText::t_draw_call> sel_calls;
//    void next_line(){y+=dy?dy:-cy;dy=0;x=pos.x;}
//    void operator()(unsigned char UC,const vec2i&p,const vec2i&size)
//    {
//      if(caret==text.size()){
//        int wtf=1;
//        return;
//      }
//      auto uc=(byte)text[caret];
//      QapAssert(uc==UC);
//      if(caret==caret_pos){caret_p=p;caret_detected=true;}
//      if(caret==sel_caret_pos){sel_car_p=p;sel_car_detected=true;}
//      if(caret_detected!=sel_car_detected)
//      {
//        QapText::add_draw_call(sel_calls,UC,p,vec2i(size.x,-size.y));
//      }
//      //
//      find_mpos(uc=='\n',p,size);
//      caret++;
//    }
//    void find_mpos(bool end_of_line,const vec2i&p,const vec2i&size)
//    {
//      if(need_find_mpos_id)
//      {
//        auto mp=mpos+con_pos;
//        auto b=p+vec2i(size.x,-size.y);
//        if(end_of_line)b.x=con_pos.x+con_size.x;
//        if(CD_Rect2Point(p,b,mp))
//        {
//          if(p.x!=mp.x)if(p.y!=mp.y)if(b.x!=mp.x)if(b.y!=mp.y)QapAssert(mpos_id==-1);
//          mpos_id=caret;
//          bool our_side=end_of_line||(mp.x*2<(p+b).x);
//          if(!our_side)mpos_id++;
//        }
//      }
//    }
//    void loop_ex(QapFont&font)
//    {
//      need_find_mpos_id=true;
//      QapDev&qDev=*(QapDev*)nullptr;
//      loop(qDev,font,false);
//    }
//    void loop(QapDev&qDev,QapFont&font,bool need_draw)
//    {
//      if(need_find_mpos_id)QapAssert(!need_draw);
//      mpos_id=-1;
//      auto&func=*this;
//      string raw=StrReplace(text,"\r","");
//      auto lines=split(raw,"\n");
//      pos=con_pos+vec2i(-con_size.x,+con_size.y)+vec2i(+1,-1)*border;
//      max_x=con_pos.x+con_size.x-border;
//      if(!need_draw)caret_detected=false;
//      if(!need_draw)sel_car_detected=false;
//      cx=+font.Info.Coords[0].x;
//      cy=font.Info.Coords[0].y;
//      x=pos.x;
//      y=pos.y-(scroll_y*cy*scroll_lines);
//      dx=cx;
//      dy=-cy;
//      caret=0;
//      auto is_end_of_context=[&]()->bool
//      {
//        bool end_of_context=y<con_pos.y-con_size.y;
//        bool is_selected=sel_caret_pos!=caret_pos;
//        if(!is_selected)if(end_of_context)return true;
//        if(is_selected)
//        {
//          if(caret_detected!=sel_car_detected)
//          {
//            int gg=1;
//          }
//          if(caret_detected&&sel_car_detected)if(end_of_context)return true;
//        }
//        return false;
//      };
//      for(int i=0;i<lines.size();i++)
//      {
//        auto&line=lines[i];
//        auto arr=split(line," ");
//        for(int j=0;j<arr.size();j++)
//        {
//          auto&ex=arr[j];
//          if(j)
//          {
//            if(!need_draw)func(' ',vec2i(x,y),vec2i(cx,cy));
//            x+=cx;
//          }
//          //if(ex.empty()){dy=std::min(dy,-cy);continue;}
//          vec2i size;
//          int cur_dy=0;
//          {
//            dx=QapText::GetLength(font,ex);
//            size=vec2i(dx,cy);
//            cur_dy=-size.y;
//          }
//          if(x+dx>max_x){
//            next_line();
//          }
//          dy=std::min(dy,cur_dy);
//          if(is_end_of_context())break;
//          if(!need_draw)QapText::PreDrawEx(font,int(x),int(y),ex,func);
//          if(need_draw)if(y<con_pos.y+con_size.y)QapText::Draw(qDev,font,int(x),int(y),ex);
//          x+=dx;
//        }
//        if(is_end_of_context())break;
//        if(i+1!=lines.size())
//        {
//          if(!need_draw)func('\n',vec2i(x,y),vec2i(cx,cy));
//          next_line();dx=cx;
//        }
//      }
//      find_mpos(true,vec2i(x,y),vec2i(cx,cy));
//      if(!need_draw)if(text.size()==caret_pos){caret_p=vec2i(x,y);caret_detected=true;}
//      if(!need_draw)if(text.size()==sel_caret_pos){sel_car_p=vec2i(x,y);sel_car_detected=true;}
//      int gg=1;
//    }
//  };
//public:
//  t_text_renderer make_tr(t_context&con)
//  {
//    t_text_renderer tr={
//      scroll_y,scroll_lines,
//      con.pos,con.size/2,
//      border,text,
//      caret_pos,sel_caret_pos
//    };
//    return std::move(tr);
//  }
//  void Render(t_context&con)
//  {
//    auto&qDev=con.qDev;
//    auto&pFontGen=con.book.pFontGen;
//    if(!pFontGen)return;
//    auto&font=pFontGen->Font;
//    QapClock clock;clock.Start();
//    if(false)
//    {
//      qDev.BindTex(0,nullptr);
//      qDev.SetColor(0xffffffff);
//      qDev.DrawQuad(con.pos,con.size);
//    }
//    auto tr=make_tr(con);
//    //
//    auto&caret_p=tr.caret_p;
//    auto&sel_car_p=tr.sel_car_p;
//    auto&caret_detected=tr.caret_detected;
//    auto&sel_car_detected=tr.sel_car_detected;
//    {
//      QapClock sub_clock;sub_clock.Start();
//      //pass for PreDrawEx
//      tr.loop(qDev,font,false);
//      //
//      sub_clock.Stop();
//      profiler.total_pde+=sub_clock.MS();
//      profiler.pde=profiler.total_pde/real(profiler.n+1);
//    }
//    //
//    if(show_caret&&sel_car_detected&&is_selected())
//    {
//      QapDev::BatchScope Scope(qDev);
//      qDev.BindTex(0,nullptr);
//      qDev.SetColor(0x99a0a0ff);
//      if(true)
//      {
//        auto&arr=tr.sel_calls;
//        for(int i=0;i<arr.size();i++)
//        {
//          auto&ex=arr[i];
//          if(!PointInQuad(ex.pos,con.pos,con.size))continue;
//          qDev.DrawQuadWithHalfPixelOffset(ex.pos+ex.size/2,ex.size);
//        }
//      }
//    }
//    //pass for DrawEx
//    qDev.BindTex(0,&pFontGen->Tex);
//    qDev.SetColor(0xff000000);
//    tr.loop(qDev,font,true);
//    //
//    qDev.BindTex(0,nullptr);
//    //
//    if(show_caret)if(caret_debug||(tick<=max_tick/2))if(caret_detected)if(PointInQuad(caret_p,con.pos,con.size))
//    {
//      QapDev::BatchScope Scope(qDev);
//      qDev.SetColor(0xff000000);
//      qDev.DrawQuadWithHalfPixelOffset(caret_p.x,caret_p.y-tr.cy/2,1,tr.cy);
//    }
//    //
//    clock.Stop();
//    if(profiler.need_reset)profiler.DoReset();
//    profiler.total_rt+=clock.MS();
//    profiler.rt=profiler.total_rt/real(profiler.n+1);
//    profiler.n++;
//  }
//  static vec2i get_caret_pos(const string&text,int caret_pos)
//  {
//    caret_pos=Clamp<int>(caret_pos,0,text.size());
//    int c=0;int sol=0;
//    for(int i=0;i<caret_pos;i++){
//      if(text[i]=='\n'){sol=i+1;c++;}
//    }
//    return vec2i(caret_pos-sol,c);
//  }
//  static bool is_allowed_char(char c)
//  {
//    static const string allowed=gen_dips("azAZàÿÀß09")+"¸"+" _=+-*/\\~!@#$%^&|()[]{}`'\"?.,<>;:";
//    return allowed.find(c)!=string::npos;
//  }
//  static bool is_char_from_word(char c)
//  {
//    static const string char_from_word=gen_dips("azAZàÿÀß09")+"¸"+"_@$";
//    return char_from_word.find(c)!=string::npos;
//  }
//  static size_t find_end_of_word(const string&text,size_t offset)
//  {
//    QapAssert(offset<text.size());
//    for(auto i=offset;i<text.size();i++)
//    {
//      if(!is_char_from_word(text[i]))return i;
//    }
//    return string::npos;
//  }
//  static size_t rfind_begin_of_word(const string&text,size_t offset)
//  {
//    QapAssert(offset<text.size());
//    for(auto i=offset;;)
//    {
//      if(!is_char_from_word(text[i]))return i;
//      if(!i)break;
//      i--;
//    }
//    return string::npos;
//  }
//  void UpdateCarPos(t_context&con)
//  {
//    auto&kb=con.kb;
//    bool ctrl=kb.Down[VK_CONTROL];
//    bool shift=kb.Down[VK_SHIFT];
//    bool mod=con.kb.OnDown(mbLeft);
//    bool md=con.kb.Down[mbLeft];
//    bool need_select=shift||(!mod&&md);
//    caret_pos=Clamp<int>(caret_pos,0,text.size());
//    car_pos=get_caret_pos(text,caret_pos);
//    if(!need_select||(kb.News&&is_allowed_char(kb.LastChar)))
//    {
//      sel_caret_pos=caret_pos;log("sel_caret_pos=caret_pos");
//    }
//  }
//  void UpdateText(t_context&con)
//  {
//    auto&kb=con.kb;
//    bool ctrl=kb.Down[VK_CONTROL];
//    bool shift=kb.Down[VK_SHIFT];
//    caret_pos=Clamp<int>(caret_pos,0,text.size());
//    if(kb.OnDown('A')&&ctrl)
//    {
//      sel_caret_pos=0;
//      caret_pos=text.size();
//    }
//    if(kb.OnDown('S')&&ctrl)if(!readonly)
//    {
//      file_put_contents(fn,text);
//    }
//    if(kb.OnDown('L')&&ctrl)
//    {
//      text=StrReplace(file_get_contents(fn),"\r","");
//    }
//    if(!text.empty())
//    {
//      if(kb.OnDown(VK_END))
//      {
//        if(ctrl)caret_pos=text.size();
//        if(!ctrl)
//        {
//          int eol=text.find("\n",caret_pos);
//          if(string::npos!=eol)caret_pos=eol;
//          if(string::npos==eol)caret_pos=text.size();
//        }
//        tick=0;UpdateCarPos(con);
//      }
//      if(kb.OnDown(VK_HOME))
//      {
//        if(ctrl)caret_pos=0;
//        if(!ctrl)
//        {
//          QapAssert(caret_pos);
//          int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
//          if(string::npos!=sol)caret_pos=sol+1;
//          if(string::npos==sol)caret_pos=0;
//        }
//        tick=0;UpdateCarPos(con);
//      }
//    }
//    caret_pos=Clamp<int>(caret_pos,0,text.size());
//    if(kb.OnDown(VK_DELETE))if(!readonly)
//    {
//      if(is_selected())
//      {
//        int a=std::min(caret_pos,sel_caret_pos);
//        int b=std::max(caret_pos,sel_caret_pos);
//        text=text.substr(0,a)+text.substr(b);
//        caret_pos=a;
//      }
//      if(!is_selected())
//      {
//        int offset=std::min<int>(caret_pos+1,text.size());
//        text=text.substr(0,caret_pos)+text.substr(offset);
//      }
//      tick=0;UpdateCarPos(con);
//    }
//    if(kb.OnDown(VK_BACK))if(caret_pos>0)if(!readonly)
//    {
//      bool selected=is_selected();
//      if(selected)
//      {
//        int a=std::min(caret_pos,sel_caret_pos);
//        int b=std::max(caret_pos,sel_caret_pos);
//        text=text.substr(0,a)+text.substr(b);
//        caret_pos=a;
//      }
//      if(!selected)
//      {
//        text=text.substr(0,caret_pos-1)+text.substr(caret_pos);
//        caret_pos--;
//      }
//      tick=0;UpdateCarPos(con);
//    }
//    if(kb.OnDown(VK_RETURN))if(!readonly)
//    {
//      text=text.substr(0,caret_pos)+"\n"+text.substr(caret_pos);
//      caret_pos++;tick=0;UpdateCarPos(con);
//    }
//    if(kb.News)if(is_allowed_char(kb.LastChar))if(!readonly)
//    {
//      if(is_selected())
//      {
//        int a=std::min(caret_pos,sel_caret_pos);
//        int b=std::max(caret_pos,sel_caret_pos);
//        text=text.substr(0,a)+text.substr(b);
//        caret_pos=a;
//        sel_caret_pos=a;
//      }
//      //if(!is_selected)
//      {
//        text=text.substr(0,caret_pos)+CToS(kb.LastChar)+text.substr(caret_pos);
//      }
//      caret_pos++;tick=0;UpdateCarPos(con);
//    }
//    if(kb.OnDown(VK_DOWN))[&]()
//    {
//      int car_pos_x=car_pos.x+1;
//      int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
//      int offset=0;
//      if(string::npos!=sol)offset=caret_pos-sol;
//      if(string::npos==sol)offset=caret_pos+1;
//      if(offset<car_pos_x)offset=car_pos_x;
//      int eol=text.find("\n",caret_pos);
//      if(string::npos==eol)return;//caret_pos=text.size();
//      if(string::npos!=eol)
//      {
//        int p=text.find("\n",eol+1);
//        if(p==string::npos)p=text.size();
//        int next_line_size=p-eol;
//        QapAssert(next_line_size);
//        if(next_line_size<offset)offset=next_line_size;
//        if(!offset)offset++;
//        caret_pos=eol+offset;
//      }
//      tick=0;UpdateCarPos(con);
//      car_pos.x=car_pos_x-1;
//    }();
//    if(kb.OnDown(VK_UP))[&]()
//    {
//      int car_pos_x=car_pos.x+1;
//      int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
//      int offset=0;
//      if(string::npos==sol)return;//sol=0;
//      if(string::npos!=sol)offset=caret_pos-sol;
//      if(offset<car_pos_x)offset=car_pos_x;
//      int sopl=text.rfind("\n",sol-1);
//      int next_line_size=sol-1;
//      if(string::npos==sopl)next_line_size=sol+1;
//      if(string::npos!=sopl)next_line_size=sol-sopl;
//      QapAssert(next_line_size);
//      if(next_line_size<offset)offset=next_line_size;
//      caret_pos=sopl+offset;
//      tick=0;UpdateCarPos(con);
//      car_pos.x=car_pos_x-1;
//    }();
//    if(kb.OnDown(VK_LEFT))if(!text.empty())if(caret_pos<=text.size()&&caret_pos>0)
//    {
//      bool hyper_jump=(caret_pos!=text.size())&&(text[caret_pos-1]==' ');
//      bool word_jump=ctrl&&!hyper_jump;
//      if(ctrl&&hyper_jump)
//      {
//        for(int i=caret_pos-1;i>=0;i--)
//        {
//          if(text[i]==' ')continue;
//          caret_pos=i+1;
//          break;
//        }
//      }
//      QapAssert(caret_pos);
//      bool inside_word=is_char_from_word(text[caret_pos-1]);
//      if(word_jump)if(caret_pos>0)
//      {
//        QapAssert(string("012").rfind('2',2)==2);
//        //auto p=text.rfind(' ',caret_pos-1);
//        auto p=rfind_begin_of_word(text,caret_pos-1);
//        if(p!=string::npos)caret_pos=p+1;
//        if(p==string::npos)caret_pos=0;
//      }
//      if(!inside_word||!ctrl){caret_pos--;}
//      tick=0;UpdateCarPos(con);
//    }
//    if(kb.OnDown(VK_RIGHT))if(!text.empty())if(caret_pos<text.size()&&caret_pos>=0)
//    {
//      bool hyper_jump=text[caret_pos]==' ';
//      bool word_jump=ctrl&&!hyper_jump;
//      if(ctrl&&hyper_jump)
//      {
//        for(int i=caret_pos;i<text.size();i++)
//        {
//          if(text[i]==' ')continue;
//          caret_pos=i;
//          break;
//        }
//      }
//      bool inside_word=is_char_from_word(text[caret_pos]);
//      if(word_jump)
//      {
//        QapAssert(string(" 12").find(' ',0)!=string::npos);
//        //auto p=text.find(' ',caret_pos);
//        auto p=find_end_of_word(text,caret_pos);
//        if(p!=string::npos)caret_pos=p;
//        if(p==string::npos)caret_pos=int(text.size());
//      }
//      if(!inside_word||!ctrl){caret_pos++;}
//      tick=0;UpdateCarPos(con);
//    }
//    caret_pos=Clamp<int>(caret_pos,0,text.size());
//  }
//  static string strpad(const string&s,int n){
//    QapAssert(n>s.size());
//    string tmp;tmp.resize(n-s.size(),'0');
//    return tmp+s;
//  }
//  static string toStr(const vec2i&v){return "{x:"+IToS(v.x)+",y:"+IToS(v.y);}
//  void log(const string&msg)
//  {
//    static QapClock clock;if(!clock.run)clock.Start();
//    if(!log_enabled)return;
//    logs.push_back("["+strpad(FToS(clock.MS()),11)+"] ["+strpad(IToS(log_tick),7)+"]["+strpad(IToS(dc_tick),3)+"] : "+msg);
//  };
//  void UpdateMouse(t_context&con)
//  {
//    if(dc_tick)dc_tick--;
//    if(con.kb.OnDown(mbRight))log("mbRight");
//    scroll_y+=Sign(con.root.win.zDelta);
//    if(!con.kb.Down[mbLeft])return;
//    auto&pFontGen=con.book.pFontGen;
//    if(!pFontGen)return;
//    auto&font=pFontGen->Font;
//    bool ctrl=con.kb.Down[VK_CONTROL];
//    bool mod=con.kb.OnDown(mbLeft);
//    bool mouse_moved=dc_mpos!=con.get_mpos();
//    if(!mod&&is_double_click)return;
//    is_double_click=(mod)&&(!mouse_moved)&&(dc_tick);
//    if(is_double_click){
//      log("is_double_click");
//    }
//    bool need_select_word=ctrl||is_double_click;
//    auto tr=make_tr(con);
//    tr.mpos=con.get_mpos();
//    tr.loop_ex(font);
//    if(tr.mpos_id<0)return;
//    caret_pos=tr.mpos_id;
//    if(mouse_moved)
//    {
//      tick=0;UpdateCarPos(con);
//    }
//    if(mod)
//    {
//      dc_tick=dc_max_tick;
//      vec2i dv=dc_mpos-con.get_mpos();
//      dc_mpos=con.get_mpos();
//      log("mod {dc_mpos:"+toStr(dc_mpos)+",dv:"+toStr(dv)+"}");
//    }
//    if(!need_select_word||text.empty()||caret_pos>=text.size())return;
//    log("select{mouse_moved:"+BToS(mouse_moved)+"}");
//    //DoSelectCurrentWorld();
//    if(text[caret_pos]==' ')
//    {
//      //std::swap
//    }
//    auto eow=find_end_of_word(text,caret_pos);//text.find(" ",caret_pos);
//    auto bow=rfind_begin_of_word(text,caret_pos);//text.rfind(" ",caret_pos);
//    if(eow==string::npos)eow=text.size();
//    if(eow==string::npos)bow=0;
//    sel_caret_pos=bow+1;
//    caret_pos=eow;
//  }
//  void Update(t_context&con)
//  {
//    log_tick++;
//    if(!caret_debug)tick++;
//    if(tick>max_tick)tick=0;
//    if(con.is_hovered()){
//      if(scroll_y>0)scroll_y=0;
//      UpdateText(con);UpdateMouse(con);
//      if(scroll_y>0)scroll_y=0;
//    }
//    if(!need_load_text)return;
//    Caption="PageWithTextFromFileV01";
//    need_load_text=false;
//    //text=file_get_contents(fn);
//    text=StrReplace(file_get_contents(fn),"\r","");
//  }
//};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TBookPageWithRotQuad)F(TBookPageWithFpsQuad)F(TBookPageWithPerf)
        //F(TBookPageWithPlatformer)F(TBookPageTextFromFileV01)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit()
    {
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}
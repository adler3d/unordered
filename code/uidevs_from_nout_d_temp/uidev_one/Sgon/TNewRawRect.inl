class TBookPageWithTest20140731:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTest20140731)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2i,offset,DEF,$,$)\
ADDVAR(bool,fixed,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(int,w,SET,128.0,$)\
ADDVAR(int,point_size,SET,16,$)\
ADDVAR(int,line_size,SET,4,$)\
ADDVAR(QapColor,point_color,SET,0xff404040,$)\
ADDVAR(bool,draw_points,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithTest20140731
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTest20140731
public:
  array<vec2i,2> get_arr(const vec2i&conp){return get_arr(conp,pos,w);}
  static array<vec2i,2> get_arr(const vec2i&conp,const vec2i&pos,int w)
  {
    array<vec2i,2> arr;
    auto dir=vec2i(1,0);
    arr[0]=conp+pos-dir*w/2;
    arr[1]=arr[0]+dir*w;
    return arr;
  }
  static array<int,2> get_arr_x(int cpx,int px,int w)
  {
    array<int,2> a;
    a[0]=cpx+px-w/2;
    a[1]=a[0]+w;
    return a;
  }
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    auto one=vec2i(1,1);
    auto&arr=get_arr(con.pos);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      qDev.SetColor(i==point_id?QapColor::HalfMix(point_color,0xffffffff):point_color);
      qDev.DrawCircle(ex,point_size,0,line_size,16);
    }
    qDev.SetColor(10==point_id?QapColor::HalfMix(point_color,0xffffffff):point_color);
    qDev.DrawCircle(con.pos+pos,point_size,0,line_size,16);
    qDev.BindTex(0,nullptr);
  }
  static int get_new_w(int mpx,int off,int px,int pid){return 2*(mpx-off-px)*(pid*2-1);}
  static void calc_new_w_and_pos(int mpx,int off,int&w,int&px,int pid){
    int c=mpx-off;int k=px-w/2+w*(1-pid);w=(c-k)*(pid*2-1);px=c+w/2-w*pid;
  }
  void Update(t_context&con)
  {
    if(!con.is_hovered()||fixed)return;
    bool d=con.kb.Down[mbLeft];
    bool ondown=con.kb.OnDown(mbLeft);
    bool shift=con.kb.Down[VK_SHIFT];
    auto mpos=con.get_mpos();
    if(ondown&&!down)
    {
      auto arr=get_arr(vec2i_zero);
      down=false;
      point_id=-1;
      for(int i=0;i<arr.size();i++)if((mpos-arr[i]).Mag()<point_size)
      {
        down=true;
        point_id=i;
        offset=mpos-arr[i];
      }
    }
    if(down&&d&&shift)
    {
      w=get_new_w(mpos.x,offset.x,pos.x,point_id);
      auto arr=get_arr_x(0,pos.x,w);
      QapAssert(arr[point_id]==mpos.x-offset.x);
    }
    if(down&&d&&!shift)
    {
      const auto before=get_arr_x(0,pos.x,w);
      calc_new_w_and_pos(mpos.x,offset.x,w,pos.x,point_id);
      auto arr=get_arr_x(0,pos.x,w);
      QapAssert(arr[point_id]==(mpos-offset).x);
      QapAssert(arr[1-point_id]==before[1-point_id]);
    }
    down=down&&d;
    if(!down)point_id=-1;
  }
};

class TNewRawRect:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TNewRawRect)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,case_id,SET,-1,$)\
ADDVAR(int,pid_a,SET,-1,$)\
ADDVAR(int,pid_b,SET,-1,$)\
ADDVAR(vec2i,off_a,DEF,$,$)\
ADDVAR(vec2i,off_b,DEF,$,$)\
ADDVAR(bool,fixed,DEF,$,$)\
ADDVAR(bool,down_a,DEF,$,$)\
ADDVAR(bool,down_b,DEF,$,$)\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(int,w,SET,128.0,$)\
ADDVAR(int,h,SET,64.0,$)\
ADDVAR(int,point_size,SET,10,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(QapColor,quad_color,SET,QapColor(80,128,128,0),$)\
ADDVAR(QapColor,rect_color,DEF,$,$)\
ADDVAR(QapColor,border_color,SET,QapColor(0,128,0),$)\
ADDVAR(bool,draw_quad,DEF,$,$)\
ADDVAR(bool,draw_rect,SET,true,$)\
ADDVAR(bool,draw_points,SET,false,$)\
ADDEND()
//=====+>>>>>TNewRawRect
#include "QapGenStruct.inl"
//<<<<<+=====TNewRawRect
public:
  vec2i get_size()const{return vec2i(w,h);}
  static void DrawRect(QapDev&qDev,const vec2i&a,const vec2i&b,const QapColor&color,int line_size)
  {
    qDev.SetColor(color);
    qDev.DrawRect(a,b,line_size);
  }
  vector<vec2i> get_arr(const vec2i&offset)
  {
    vec2i hs=vec2i(w,h)/2;
    return MakeQuadAABB(offset+pos-hs,offset+pos+hs);
  }
  void RenderBack(t_context&con)
  {
    auto&qDev=con.qDev;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vec2i p=pos+bpos;
    if(!draw_quad)return;
    qDev.SetColor(quad_color);
    qDev.DrawQuadWithHalfPixelOffset(p,w,h);
  }
  void RenderBorder(t_context&con)
  {
    if(!draw_rect)return;
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.SetColor(rect_color);
    auto s=get_size();
    auto a=con.pos+pos-s/2;
    auto b=a+s;
    qDev.DrawRect(a,b,line_size);
  }
  void RenderPoints(t_context&con)
  {
    if(!draw_points)return;
    auto&qDev=con.qDev;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vec2i p=vec2i(1,1)/2+pos+bpos;
    vec2i s=vec2i(w,h)/2;
    vec2i b=vec2i(1,1)*point_size;
    static const vec2i koef[]={
      vec2i(-1,-1),
      vec2i(+1,-1),
      vec2i(+1,+1),
      vec2i(-1,+1),
      vec2i(-1,00),
      vec2i(+1,00),
      vec2i(00,-1),
      vec2i(00,+1)
    };
    /*if(draw_points)for(int cur_id=0;cur_id<lenof(koef);cur_id++)
    {
      auto&kx=koef[cur_id].x;
      auto&ky=koef[cur_id].y;
      vec2i pos=p+vec2i(s.x*kx,s.y*ky);
      DrawRect(qDev,pos-b,pos+b,border_color,line_size);
    }*/
    qDev.SetColor(border_color);
    QapDev::BatchScope Scope(qDev);
    /*{
      auto arr=TBookPageWithTest20140731::get_arr_x(0,pos.x,w);
      for(int i=0;i<arr.size();i++)qDev.DrawRectAsQuad(con.pos+vec2i(arr[i],pos.y),b,line_size);
    }
    {
      auto arr=TBookPageWithTest20140731::get_arr_x(0,pos.y,h);
      for(int i=0;i<arr.size();i++)qDev.DrawRectAsQuad(con.pos+vec2i(pos.x,arr[i]),b,line_size);
    }*/
    {
      auto ax=TBookPageWithTest20140731::get_arr_x(pos.x,0,w);
      auto ay=TBookPageWithTest20140731::get_arr_x(0,pos.y,h);
      for(int i=0;i<2;i++)qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],pos.y),b,line_size);
      for(int i=0;i<2;i++)qDev.DrawRectAsQuad(con.pos+vec2i(pos.x,ay[i]),b,line_size);
      for(int i=0;i<2;i++)qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],ay[i]),b,line_size);
      for(int i=0;i<2;i++)qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],ay[1-i]),b,line_size);
    }
    qDev.BindTex(0,nullptr);
  }
  void Render(t_context&con)
  {
    RenderBack(con);
    RenderBorder(con);
    RenderPoints(con);
  }
  void Update(t_context&con)
  {
    UpdateNew(con);
  }/*
  void check_point(int cur_id,const vec2i&np,const vec2i&b,const vec2i&mpos)
  {
    if(!CD_Rect2Point(np-b,np+b,mpos))return;
    point_id=cur_id;
    down=true;
    offset=mpos-np;
  };*/
  static void update_point
  (
    int&pid,int point_size,
    int mpx,int mpy,
    bool&down,bool d,bool ondown,bool shift,
    vec2i&off,
    int&px,int py,
    int&w,int h,int&cid,int this_cid
  )
  {
    auto get_arr_x=TBookPageWithTest20140731::get_arr_x;
    auto get_new_w=TBookPageWithTest20140731::get_new_w;
    auto calc_new_w_and_pos=TBookPageWithTest20140731::calc_new_w_and_pos;
    if(ondown&&!down)
    {
      //auto arr=get_arr(vec2i_zero);
      auto arr_x=get_arr_x(0,px,w);
      auto arr_y=get_arr_x(py,0,h);
      if(this_cid==3)std::swap(arr_y[0],arr_y[1]);
      down=false;
      pid=-1;
      auto mpos=vec2i(mpx,mpy);
      for(int i=0;i<2;i++)
      {
        auto&ex=vec2i(arr_x[i],this_cid>1?arr_y[i]:py);
        if(ex.dist_less(mpos,point_size/2))
        {
          down=true;pid=i;cid=this_cid;
          off=mpos-ex;
        }
      }
    }
    if(down&&d&&shift)
    {
      w=get_new_w(mpx,off.x,px,pid);
      auto arr=get_arr_x(0,px,w);
      QapAssert(arr[pid]==mpx-off.x);
    }
    if(down&&d&&!shift)
    {
      auto before=get_arr_x(0,px,w);
      calc_new_w_and_pos(mpx,off.x,w,px,pid);
      auto arr=get_arr_x(0,px,w);
      QapAssert(arr[pid]==mpx-off.x);
      QapAssert(arr[1-pid]==before[1-pid]);
    }
    down=down&&d;
    if(!down){pid=-1;cid=-1;}
  }
  void UpdateNew(t_context&con,const vec2i*php=nullptr,const vec2i*phs=nullptr)
  {
    if(fixed)return;
    if(!con.is_hovered())return;
    auto&kb=con.kb;
    bool d=kb.Down[mbLeft];
    bool ondown=kb.OnDown(mbLeft);
    bool shift=kb.Down[VK_SHIFT];
    auto mpos=con.get_mpos();
    if(case_id<0||case_id==0)update_point(pid_a,point_size,mpos.x,mpos.y,down_a,d,ondown,shift,off_a,pos.x,pos.y,w,h,case_id,0);
    if(case_id<0||case_id==1)update_point(pid_a,point_size,mpos.y,mpos.x,down_a,d,ondown,shift,off_a,pos.y,pos.x,h,w,case_id,1);
    if(case_id<0||case_id==2)update_point(pid_a,point_size,mpos.x,mpos.y,down_a,d,ondown,shift,off_a,pos.x,pos.y,w,h,case_id,2);
    if(case_id<0||case_id==2)update_point(pid_b,point_size,mpos.y,mpos.x,down_b,d,ondown,shift,off_b,pos.y,pos.x,h,w,case_id,2);
    if(case_id<0||case_id==3)update_point(pid_a,point_size,mpos.y,mpos.x,down_a,d,ondown,shift,off_a,pos.y,pos.x,h,w,case_id,3);
    if(case_id<0||case_id==3)update_point(pid_b,point_size,mpos.x,mpos.y,down_b,d,ondown,shift,off_b,pos.x,pos.y,w,h,case_id,3);
    //for(int i=0;i<4;i+=2)
    //{
    //  auto xy=i%2;auto yx=!xy;
    //  if(case_id<0||xy)update_point(point_id,point_size,mpos.x,mpos.y,down,d,ondown,shift,offset,pos.x,pos.y,w,h,case_id,i+0);
    //  if(case_id<0||yx)update_point(point_id,point_size,mpos.y,mpos.x,down,d,ondown,shift,offset,pos.y,pos.x,h,w,case_id,i+1);
    //}
  }
};
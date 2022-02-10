#include "StdAfx.h"
#include <stdio.h>

class TTwoPointRect:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTwoPointRect)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,empty,DEF,$,$)\
ADDVAR(vec2i,a,DEF,$,$)\
ADDVAR(vec2i,b,DEF,$,$)\
ADDEND()
//=====+>>>>>TTwoPointRect
#include "QapGenStruct.inl"
//<<<<<+=====TTwoPointRect
public:
  vec2i get_size(){return empty?vec2i_zero:(a-b).abs()+vec2i(1,1);}
  vec2i get_pos(){QapAssert(!empty);return (a+b)/2;}
  vec2i get_min(){QapAssert(!empty);return vec2i(std::min(a.x,b.x),std::min(a.y,b.y));}
  vec2i get_max(){QapAssert(!empty);return vec2i(std::max(a.x,b.x),std::max(a.y,b.y));}
};

class TRawRectModeTwoPoint:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRawRectModeTwoPoint)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,fixed,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2i,offset,DEF,$,$)\
ADDVAR(TTwoPointRect,rect,DEF,$,$)\
ADDVAR(int,point_size,SET,16,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(int,border_ls,SET,16,$)\
ADDVAR(QapColor,quad_color,SET,QapColor(80,100,100,100),$)\
ADDVAR(QapColor,point_color,SET,0xff000000,$)\
ADDVAR(QapColor,border_color,SET,QapColor(32,32,32),$)\
ADDVAR(bool,draw_quad,DEF,$,$)\
ADDVAR(bool,draw_rect,SET,true,$)\
ADDVAR(bool,draw_blured_rect,SET,true,$)\
ADDVAR(bool,draw_points,SET,false,$)\
ADDEND()
//=====+>>>>>TRawRectModeTwoPoint
#include "QapGenStruct.inl"
//<<<<<+=====TRawRectModeTwoPoint
public:
  static void AddPixel(t_context&con,const vec2i&p){
    con.qDev.DrawQuad(con.pos+p,1,1);
  }
  static void RefDrawRectInside(QapDev&qDev,const vec2i&p,const vec2i&a,const vec2i&b,int bs)
  {
    QapDev::BatchScope Scope(qDev);
    for(int y=a.y;y<=b.y;y++)for(int x=a.x;x<=b.x;x++)
    {
      auto f0=y<a.y+bs||y>b.y-bs;
      auto f1=x<a.x+bs||x>b.x-bs;
      if(!f1&&!f0)continue;
      qDev.DrawQuad(vec2i(x,y)+p,1,1);
    }
  }
  void Render(t_context&con)
  {
    if(rect.empty)return;
    QapDev::BatchScope Scope(con.qDev);
    con.qDev.BindTex(0,nullptr);
    auto&p=con.pos;/*auto hp=vec2d(1,1)*0.5;*/auto bs=border_ls;
    auto a=rect.get_min();auto b=rect.get_max();
    con.qDev.SetColor(point_color);
    if(!draw_blured_rect)
    {
      for(int y=a.y;y<=b.y;y++)for(int x=a.x;x<=b.x;x++)
      {
        auto f0=y<a.y+bs||y>b.y-bs;
        auto f1=x<a.x+bs||x>b.x-bs;
        if(f1||f0)
        AddPixel(con,vec2i(x,y));
      }
      //for(int x=a.x;x<=b.x;x++)
      //{
      //  for(int y=a.y;y<=b.y-bs&&y<a.y+bs;y++)AddPixel(con,vec2i(x,y));
      //  for(int y=b.y;y>=a.y&&y>b.y-bs;y--)AddPixel(con,vec2i(x,y));
      //}
      //for(int y=a.y+bs;y<=b.y-bs;y++)
      //{
      //  for(int x=a.x;x<=b.x-bs&&x<a.x+bs;x++)AddPixel(con,vec2i(x,y));
      //  for(int x=b.x;x>=a.x&&x>b.x-bs;x--)AddPixel(con,vec2i(x,y));
      //}
    }
    if(draw_blured_rect)if(a==b)
    {
      con.qDev.DrawQuad(p+a,1,1);
    }
    if(draw_blured_rect)if(a!=b)
    {
      con.qDev.DrawSolidRect(p+vec2d(a.x,a.y+bs),p+vec2i(a.x+bs,b.y-bs));
      con.qDev.DrawSolidRect(p+vec2d(b.x,a.y+bs),p+vec2i(b.x-bs,b.y-bs));
      con.qDev.DrawSolidRect(p+vec2d(a.x,a.y),p+vec2i(b.x,a.y+bs));
      con.qDev.DrawSolidRect(p+vec2d(a.x,b.y),p+vec2i(b.x,b.y-bs));
    }
    //
    con.qDev.DrawRectAsQuad(a+p,vec2i(1,1)*point_size,line_size);
    con.qDev.DrawRectAsQuad(b+p,vec2i(1,1)*point_size,line_size);
    con.qDev.SetColor(border_color);
    //con.qDev.DrawRectAsQuad(p+rect.get_pos(),rect.get_size(),line_size);
  }
  void Update(t_context&con)
  {
    if(fixed||rect.empty)return;
    if(!con.is_hovered())return;
    auto&kb=con.kb;
    bool d=kb.Down[mbLeft];
    bool ondown=kb.OnDown(mbLeft);
    //bool shift=kb.Down[VK_SHIFT];
    auto mpos=con.get_mpos();
    auto ps=vec2i(1,1)*point_size;
    if(ondown&&!down&&PointInQuad(mpos,rect.a,ps)){offset=mpos-rect.a;point_id=0;down=true;}
    if(ondown&&!down&&PointInQuad(mpos,rect.b,ps)){offset=mpos-rect.b;point_id=1;down=true;}
    if(down&&d){
      (point_id?rect.b:rect.a)=mpos-offset;
    }
    down=down&&d;
    if(!down){offset=vec2i_zero;point_id=-1;}
  }
};

class TRawRect20140801:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRawRect20140801)PARENT(IBookPage)
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
ADDVAR(int,point_size,SET,16,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(int,border_size,SET,16,$)\
ADDVAR(QapColor,quad_color,SET,QapColor(80,100,100,100),$)\
ADDVAR(QapColor,rect_color,SET,0xff000000,$)\
ADDVAR(QapColor,border_color,SET,QapColor(32,32,32),$)\
ADDVAR(bool,draw_quad,DEF,$,$)\
ADDVAR(bool,draw_rect,SET,true,$)\
ADDVAR(bool,draw_blured_rect,SET,true,$)\
ADDVAR(bool,draw_points,SET,false,$)\
ADDEND()
//=====+>>>>>TRawRect20140801
#include "QapGenStruct.inl"
//<<<<<+=====TRawRect20140801
public:
  typedef IBookPage::t_context t_context;
public:
  vec2i get_size()const{return vec2i(w,h);}
  static array<int,2> get_arr_x(int cpx,int px,int w)
  {
    array<int,2> a;
    a[0]=cpx+px-w/2;
    a[1]=a[0]+w;
    return a;
  }
  static int get_new_w(int mpx,int off,int px,int pid){return 2*(mpx-off-px)*(pid*2-1);}
  static void calc_new_w_and_pos(int mpx,int off,int&w,int&px,int pid){
    int c=mpx-off;int k=px-w/2+w*(1-pid);w=(c-k)*(pid*2-1);px=c+w/2-w*pid;
  }
  void RenderBack(t_context&con)
  {
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    if(!draw_quad)return;
    qDev.SetColor(quad_color);
    qDev.DrawQuadWithHalfPixelOffset(pos+con.pos,w,h);
  }
  void RenderBorder(t_context&con)
  {
    if(!draw_rect)return;
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.SetColor(rect_color);
    auto s=get_size();
    auto a=con.pos+pos-s/2-vec2i(1,1)*line_size/2;
    auto b=a+s+vec2i(1,1)*line_size;
    qDev.DrawRect(a,b,line_size);
  }
  void RenderPoints(t_context&con)
  {
    if(!draw_points)return;
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.SetColor(border_color);
    QapDev::BatchScope Scope(qDev);
    auto b=vec2i(1,1)*point_size;
    auto ax=get_arr_x(pos.x,0,w);
    auto ay=get_arr_x(0,pos.y,h);
    for(int i=0;i<2;i++)
    {
      qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],pos.y),b,line_size);
      qDev.DrawRectAsQuad(con.pos+vec2i(pos.x,ay[i]),b,line_size);
      qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],ay[i]),b,line_size);
      qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],ay[1-i]),b,line_size);
    }
    qDev.BindTex(0,nullptr);
  }
  void RenderBluredRect(t_context&con)
  {
    if(!draw_blured_rect)return;
    auto&qDev=con.qDev;
    int n=border_size;
    QapDev::BatchScope Scope(qDev);
    qDev.SetColor(border_color);
    for(int i=0;i<n;i++){//if(i%2==0)continue;
      //qDev.color.a=255-abs((i-(n-1)/2)*255*2/n);
      qDev.DrawRectAsQuad(con.pos+pos,get_size()+vec2i(1,1)*i*2,1);
    }
  }
  void Render(t_context&con)
  {
    RenderBack(con);
    RenderBorder(con);
    RenderPoints(con);
    RenderBluredRect(con);
    //vec2d n=vec2d(w,h)*0.5;
    //auto g=con.root.win.GetClientSize();
    //auto a=vec2i(-g.x/2,-g.y/2+g.y);
    //auto b=vec2i(-g.x/2,-g.y/2+1);
    //con.qDev.DrawSolidRect(a-n,a+n);
    //con.qDev.DrawSolidRect(b-n,b+n);
    //con.qDev.DrawSolidRect(con.pos+pos-n,con.pos+pos+n);
  }
  void Update(t_context&con)
  {
    UpdateEx(con,pos,get_size());
  }
  static void update_point(
    int&pid,int point_size,
    int mpx,int mpy,
    bool&down,bool d,bool ondown,bool shift,
    vec2i&off,
    int&px,int py,
    int&w,int h,int&cid,int this_cid)
  {
    if(ondown&&!down)
    {
      auto arr_x=get_arr_x(0,px,w);
      auto arr_y=get_arr_x(py,0,h);
      if(this_cid==3)std::swap(arr_y[0],arr_y[1]);
      down=false;pid=-1;
      auto mpos=vec2i(mpx,mpy);
      for(int i=0;i<2;i++)
      {
        auto&ex=vec2i(arr_x[i],this_cid>1?arr_y[i]:py);
        if(!ex.dist_less(mpos,point_size/2))continue;
        down=true;pid=i;cid=this_cid;off=mpos-ex;
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
  void UpdateEx(t_context&con,const vec2i&hp,const vec2i&hs)
  {
    if(fixed)return;
    if(!con.is_hovered())return;
    auto&kb=con.kb;
    bool d=kb.Down[mbLeft];
    bool ondown=kb.OnDown(mbLeft);
    bool shift=kb.Down[VK_SHIFT];
    auto mpos=con.get_mpos();
    auto&cid=case_id;
    #define F(x,y,w,h,id,a)if(cid<0||cid==id)update_point(pid_##a,point_size,mpos.x,mpos.y,down_##a,d,ondown,shift,off_##a,pos.x,pos.y,w,h,cid,id);
    F(x,y,w,h,3,b);
    F(y,x,h,w,3,a);
    F(x,y,w,h,2,a);
    F(y,x,h,w,2,b);
    F(x,y,w,h,0,a);
    F(y,x,h,w,1,a);
    #undef F
    if(cid<0||cid==10)
    {
      if(ondown&&!down_a)if(PointInQuad(mpos,hp,hs)){off_a=mpos-hp;down_a=true;cid=10;}
      if(down_a&&d){pos=(mpos-off_a)-(hp-pos);}
      down_a=down_a&&d;
      if(!down_a){pid_a=-1;cid=-1;}
    }
  }
};

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
        F(TType)F(TRawRect20140801)F(TRawRectModeTwoPoint)
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
  ThisCompileUnit ThisUnit;
}
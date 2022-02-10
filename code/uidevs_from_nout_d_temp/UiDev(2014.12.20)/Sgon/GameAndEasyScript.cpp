#include "StdAfx.h"
#include <stdio.h>

class t_start_rect{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_start_rect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i,start,DEF,$,$)\
ADDVAR(vec2i,size,DEF,$,$)\
ADDEND()
//=====+>>>>>t_start_rect
#include "QapGenStruct.inl"
//<<<<<+=====t_start_rect
public:
  bool contains(const vec2i&point)
  {
    bool ax=point.x>=start.x;
    bool ay=point.y>=start.y;
    bool bx=point.x<start.x+size.x;
    bool by=point.y<start.y+size.y;
    return ax&&ay&&bx&&by;
  }
};

class t_aabb_quad{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_aabb_quad)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,n,DEF,$,$)\
ADDVAR(t_quad,quad,DEF,$,$)\
ADDEND()
//=====+>>>>>t_aabb_quad
#include "QapGenStruct.inl"
//<<<<<+=====t_aabb_quad
public:
  //void add(const t_quad&ref){QapDebugMsg("not tested");if(!n){quad=ref;n++;return;}n++;}
  //void add(const vec2i&point){}
};

class t_aabb_minmax{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_aabb_minmax)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,n,DEF,$,$)\
ADDVAR(vec2i,minp,DEF,$,$)\
ADDVAR(vec2i,maxp,DEF,$,$)\
ADDEND()
//=====+>>>>>t_aabb_minmax
#include "QapGenStruct.inl"
//<<<<<+=====t_aabb_minmax
public:
  //void add(const t_quad&ref){QapDebugMsg("not tested");if(!n){quad=ref;n++;return;}n++;}
  void add(const vec2i&p)
  {
    QapAssert(n>=0);
    if(!n){minp=p;maxp=p;n++;return;}
    minp.x=std::min(minp.x,p.x);
    minp.y=std::min(minp.y,p.y);
    maxp.x=std::max(maxp.x,p.x);
    maxp.y=std::max(maxp.y,p.y);
    n++;
  }
  void add(const vec2i&pos,const vec2i&size)
  {
    QapAssert(!(size.x%2));QapAssert(!(size.y%2));
    vec2i hs=size/2;
    add(pos+vec2i(+hs.x,+hs.y));
    add(pos+vec2i(+hs.x,-hs.y));
    add(pos+vec2i(-hs.x,-hs.y));
    add(pos+vec2i(-hs.x,+hs.y));
  }
  void add_ex(const vec2d&pos,const vec2d&size)
  {
    add(vec2i(pos.x,pos.y),vec2i(size.x,size.y));
  }
  vec2i get_size()const{QapAssert(n>0);return maxp-minp;}
};

struct QapTexMemMixer{
  static void mix_func(QapTexMem&out,QapTexMem&a,QapTexMem&b)
  {
    auto*pa=a.get();
    auto*pb=b.get();
    auto*po=out.get();
    auto W=a.W;
    auto H=a.H;
    for(int j=0;j<H;j++)for(int i=0;i<W;i++)
    {
      auto&ca=pa[i+W*j];
      auto&cb=pb[i+W*j];
      auto&co=po[i+W*j];
      co.r=(size_t(ca.r)+size_t(cb.r))>>1;
      co.g=(size_t(ca.g)+size_t(cb.g))>>1;
      co.b=(size_t(ca.b)+size_t(cb.b))>>1;
      co.a=(size_t(ca.a)+size_t(cb.a))>>1;
    }
  }
  static void mix_pass(vector<QapTexMem>&out,vector<QapTexMem>&inp)
  {
    if(inp.size()<2)return;
    out.resize(inp.size()/2);
    auto W=inp[0].W;
    auto H=inp[0].H;
    for(int i=0;i<inp.size();i+=2)
    {
      auto&ex=out[i/2];
      ex.Init(W,H);
      mix_func(ex,inp[i+0],inp[i+1]);
    }
  }
  static QapTexMem mix_arr(vector<QapTexMem>&inp)
  {
    if(inp.empty())return QapTexMem();
    vector<QapTexMem> prev=std::move(inp);
    for(int i=prev.size();1<prev.size();){
      vector<QapTexMem> next;
      mix_pass(next,prev);
      prev=std::move(next);
      next.clear();
    }
    return prev[0];
  }
  static string num8tostr(int num){
    char buff[128];
    sprintf(buff,"%08u",num);
    return buff;
  }
};

class TBookPageWithClock:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithClock)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,cur_clock,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithClock
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithClock
public:
  void RenderViewText(t_context&con)
  {
    auto&qDev=con.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      qDev.BindTex(0,&pFont->Tex);
      con.qDev.SetColor(0xff000000);
      //vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      auto add=[&](const string&text,int x,int y){
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+x),int(con.pos.y+y),text);//p.y+=-font.Info[0].y;
      };
      add(cur_clock,+8-con.size.x/2,+con.size.y/2-8);
      qDev.BindTex(0,0);
    }
    qDev.BindTex(0,nullptr);
  }
  void Render(t_context&con)
  {
    RenderViewText(con);
  }
  void Update(t_context&con)
  {
    cur_clock=cur_date_str();
  }
};

class TBookPageWithRectTest:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithRectTest)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithRectTest
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithRectTest
public:
  void Render(t_context&con){rect.Render(con);}
  void Update(t_context&con){rect.Update(con);}
};

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
      w=TRawRect::get_new_w(mpos.x,offset.x,pos.x,point_id);
      auto arr=get_arr_x(0,pos.x,w);
      QapAssert(arr[point_id]==mpos.x-offset.x);
    }
    if(down&&d&&!shift)
    {
      const auto before=get_arr_x(0,pos.x,w);
      TRawRect::calc_new_w_and_pos(mpos.x,offset.x,w,pos.x,point_id);
      auto arr=get_arr_x(0,pos.x,w);
      QapAssert(arr[point_id]==(mpos-offset).x);
      QapAssert(arr[1-point_id]==before[1-point_id]);
    }
    down=down&&d;
    if(!down)point_id=-1;
  }
};

class TBookPageWithEasyScript:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithEasyScript)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(TRawRect,editor_rect,DEF,$,$)\
ADDVAR(TRawRect,view_rect,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithEasyScript
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithEasyScript
public:
  bool is_int(const string&s)
  {
    static const CharMask mask("0123456789");
    if(s.empty())return false;
    if(s.size()>1)if(s[0]=='-')return mask.check(s.substr(1));
    if(s.size()>1)if(s[0]=='+')return mask.check(s.substr(1));
    return !s.empty()&&mask.check(s);
  }
  struct t_value{bool ok;int value;};
  t_value get_value(const string&s)
  {
    const t_value fail={false,0};
    if(s=="t"){t_value t={true,tick};return t;}
    if(s=="t%64"){t_value t={true,tick%64};return t;}
    //if(s=="(t%64-32)"){t_value t={true,tick%64-32};return t;}
    if(!is_int(s))return fail;
    {t_value t={true,SToI(s)};return t;}
  }
  void RenderViewText(t_context&con)
  {
    auto&lines=split(editor.text,"\n");
    auto&qDev=con.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      qDev.BindTex(0,&pFont->Tex);
      con.qDev.SetColor(0xff000000);
      //vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      auto add=[&](const string&text,int x,int y){
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+x),int(con.pos.y+y),text);//p.y+=-font.Info[0].y;
      };
      for(int j=0;j<lines.size();j++)
      {
        auto&line=lines[j];
        auto arr=split(line," ");
        if(arr.empty())continue;
        if(arr[0]!="text")continue;
        #define F(VAR,N)int VAR=0;if(N>=arr.size())continue;{auto tmp=get_value(arr[N]);if(!tmp.ok)continue;VAR=tmp.value;}
        F(x,1);F(y,2);
        #undef F
        string t;for(int i=3;i<arr.size();i++)t+=arr[i]+(i+1==arr.size()?"":" ");
        add(t,x,y);
      }
      qDev.BindTex(0,0);
    }
    qDev.BindTex(0,nullptr);
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
  static void RefDrawSolidRectInside(QapDev&qDev,const vec2i&p,const vec2i&ap,const vec2i&bp)
  {
    auto a=vec2i(std::min(ap.x,bp.x),std::min(ap.y,bp.y));
    auto b=vec2i(std::max(ap.x,bp.x),std::max(ap.y,bp.y));
    QapDev::BatchScope Scope(qDev);
    for(int y=a.y;y<=b.y;y++)for(int x=a.x;x<=b.x;x++)
    {
      qDev.DrawQuad(vec2i(x,y)+p,1,1);
    }
  }
  static void DrawRect(QapDev&qDev,const vec2i&ap,const vec2i&bp,int line_size)
  {
    QapDev::BatchScope Scope(qDev);
    {
      auto a=vec2i(std::min(ap.x,bp.x),std::min(ap.y,bp.y));
      auto b=vec2i(std::max(ap.x,bp.x),std::max(ap.y,bp.y));
      //vec2d n;
      auto ab=b-a;
      auto ls=std::min(line_size,std::min(ab.x+1,ab.y+1));
      auto hs=ls*0.5;
      //n=vec2d(+1,+1)*0.5*line_size;
      qDev.DrawSolidRect(vec2d(a.x-hs,a.y-hs),vec2d(b.x+hs,a.y+hs));
      qDev.DrawSolidRect(vec2d(a.x-hs,b.y+hs),vec2d(b.x+hs,b.y-hs));
      //n=vec2d(+1,-1)*0.5*line_size;
      qDev.DrawSolidRect(vec2d(a.x-hs,a.y+hs),vec2d(a.x+hs,b.y-hs));
      qDev.DrawSolidRect(vec2d(b.x-hs,a.y+hs),vec2d(b.x+hs,b.y-hs));
    }
    int gg=1;
  }
  void RenderView(t_context&con)
  {
    auto&lines=split(editor.text,"\n");
    {
      QapDev::BatchScope Scope(con.qDev);
      for(int j=0;j<lines.size();j++)
      {
        auto&line=lines[j];
        auto arr=split(line," ");
        //if(arr.empty())if(arr[0]=="text")
        #define F(VAR,N)int VAR=0;if(N>=arr.size())continue;{auto tmp=get_value(arr[N]);if(!tmp.ok)continue;VAR=tmp.value;}
        if(!arr.empty())if(arr[0]=="rect"){
          F(x,1);F(y,2);F(w,3);F(h,4);F(ls,5);F(c,6);
          con.qDev.SetColor(QapColor(c,c,c));
          con.qDev.DrawRectAsQuad(con.pos+vec2i(x,y),vec2i(w,h),ls);
          continue;
        }
        if(!arr.empty())if(arr[0]=="solid"){
          F(x0,1);F(y0,2);
          F(x1,3);F(y1,4);
          F(c,5);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          con.qDev.DrawSolidRect(p+vec2i(x0,y0),p+vec2i(x1,y1));
          continue;
        }
        if(!arr.empty())if(arr[0]=="sd"){
          F(x,1);F(y,2);
          F(dx,3);F(dy,4);
          F(c,5);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          con.qDev.DrawSolidRect(p+vec2i(x,y),p+vec2i(x+dx,y+dy));
          continue;
        }
        if(!arr.empty())if(arr[0]=="ref"){
          F(x,1);F(y,2);
          F(w,3);F(h,4);
          F(c,5);F(ls,6);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          auto pa=vec2i(x,y)-vec2i(w,h)/2;
          auto pb=pa+vec2i(w,h);//pa-=vec2i(w,h)/2;
          auto a=vec2i(std::min(pa.x,pb.x),std::min(pa.y,pb.y));
          auto b=vec2i(std::max(pa.x,pb.x),std::max(pa.y,pb.y));
          RefDrawRectInside(con.qDev,p,a,b,ls);
          continue;
        }
        if(!arr.empty())if(arr[0]=="re"){
          F(x,1);F(y,2);
          F(w,3);F(h,4);
          F(c,5);F(ls,6);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          {
            auto pos=p+vec2i(x,y);
            ls=std::min(ls,std::min(w,h));
            auto size=vec2i(w,h)+vec2i(1,1)*(2-ls);
            auto pa=pos-size/2;
            auto pb=pa+size;
            pb-=vec2i(1,1);
            auto a=vec2i(std::min(pa.x,pb.x),std::min(pa.y,pb.y));
            auto b=vec2i(std::max(pa.x,pb.x),std::max(pa.y,pb.y));
            a+=vec2i(1-(ls%2)+w%2,+h%2);
            b+=vec2i(1-(ls%2)+w%2,+h%2);
            if(false)//if((ls>w)||(ls>h))
            {
              con.qDev.DrawSolidRect(a,b+vec2i(1,1));
            }else{
              DrawRect(con.qDev,a,b,ls);
            }
          }
          //con.qDev.DrawRectAsQuad(p+vec2i(x,y),vec2i(w,h)-vec2i(1,1)*ls,ls);
          continue;
        }
        if(!arr.empty())if(arr[0]=="ref_old"){
          F(x0,1);F(y0,2);
          F(x1,3);F(y1,4);
          F(c,5);F(bs,6);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          auto pa=vec2i(x0,y0);
          auto pb=vec2i(x1,y1);
          auto a=vec2i(std::min(pa.x,pb.x),std::min(pa.y,pb.y));
          auto b=vec2i(std::max(pa.x,pb.x),std::max(pa.y,pb.y));
          RefDrawRectInside(con.qDev,p,a,b,bs);
          continue;
        }
        if(!arr.empty())if(arr[0]=="raqi"){
          F(x,1);F(y,2);
          F(w,3);F(h,4);
          F(c,5);F(ls,6);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          {
            auto pos=p+vec2i(x,y);
            auto size=vec2i(w,h)-vec2i(1,1)*ls;
            auto a=pos-size/2;
            auto b=a+size;
            con.qDev.DrawRect(a,b,ls);
          }
          //con.qDev.DrawRectAsQuad(p+vec2i(x,y),vec2i(w,h)-vec2i(1,1)*ls,ls);
          continue;
        }
        //if(!arr.empty())if(arr[0]=="rsri"){
        //  F(x,1);F(y,2);
        //  F(w,3);F(h,4);
        //  F(c,5);
        //  con.qDev.SetColor(QapColor(c,c,c));
        //  auto p=con.pos;
        //  RefDrawSolidRectInside(con.qDev,p,vec2i(x,y),vec2i(w,h));
        //  continue;
        //}
        if(!arr.empty())if(arr[0]=="raq"){
          F(x,1);F(y,2);
          F(w,3);F(h,4);
          F(c,5);F(ls,6);
          con.qDev.SetColor(QapColor(c,c,c));
          auto p=con.pos;
          con.qDev.DrawRectAsQuad(p+vec2i(x,y),vec2i(w,h),ls);
          continue;
        }
        F(x,0);F(y,1);F(w,2);
        #undef F
        #define F(VAR,N,V)int VAR=V;if(N<arr.size()){auto tmp=get_value(arr[N]);if(tmp.ok)VAR=tmp.value;}
        F(h,3,w);F(ang,4,0);F(r,5,0);F(g,6,0);F(b,7,0);
        #undef F
        vec2i pos=vec2i(x,y);
        con.qDev.SetColor(QapColor(r,g,b));
        if(!PointInQuad(pos,vec2d_zero,con.size))continue;
        con.qDev.DrawQuad(con.pos+pos,vec2i(w,h),ang*Pi/180.0);
      }
    }
    RenderViewText(con);
  }
  void Render(t_context&con)
  {
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      *(TDay20140605Book*)nullptr,
      editor_rect.pos,
      editor_rect.get_size(),
      con.path,
      con.context
    };
    context.pos=con.pos;
    context.size=con.size;
    editor_rect.Render(context);
    view_rect.Render(context);
    context.pos=con.pos+editor_rect.pos;
    context.size=editor_rect.get_size();
    editor.Render(context);
    context.pos=con.pos+view_rect.pos;
    context.size=view_rect.get_size();
    RenderView(context);
  }
  void Update(t_context&con)
  {
    tick++;
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      *(TDay20140605Book*)nullptr,
      editor_rect.pos,
      editor_rect.get_size(),
      con.path,
      con.context
    };
    context.pos=con.pos;
    context.size=con.size;
    editor_rect.Update(context);
    view_rect.Update(context);
    context.pos=con.pos+editor_rect.pos;
    context.size=editor_rect.get_size();
    editor.Update(context);
    if(con.kb.OnDown(VK_F4)&&con.is_hovered())
    {
      if(Caption.empty())Caption="EasyEditor";
      editor_rect.fixed=true;
      editor_rect.line_size=2;
      editor.border=16;
    }
  }
};

class TGameBrick{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameBrick)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,size,SET,vec2d(32,32),$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,script,DEF,$,$)\
ADDVAR(string,mem,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameBrick
#include "QapGenStruct.inl"
//<<<<<+=====TGameBrick
public:
};

class TGameAboutScriptUnits;

class TGameUnit{
public:
  typedef IBookPage::t_context t_context;
public:
  class TScriptContext{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TScriptContext)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,cmd_id,DEF,$,$)\
  ADDVAR(string,last_script,DEF,$,$)\
  ADDVAR(int,last_tick,DEF,$,$)\
  ADDEND()
  //=====+>>>>>TScriptContext
  #include "QapGenStruct.inl"
  //<<<<<+=====TScriptContext
  public:
    template<int>
    struct t_cmd_list
    {
      TGameAboutScriptUnits&game;
      t_context&con;
      TGameUnit&unit;
      vector<TGameUnit>&units;
      int id;
      TScriptContext&scon;
      vector<string>&lines;
      string&line;
      vector<string>&params;
      struct t_var{
        string type;
        string name;
        string value;
      };
      vector<t_var> vars;
      struct t_frame{
        int next_cmd_id;
        vector<t_var> vars;
      };
      vector<t_frame> frames;
      void AddItemToScene()
      {
        //con.root.Scene.AddItem<TRenderNode>(con.Env)->Caption="from_script";
        scon.cmd_id++;
      }
      void var()
      {
        if(params.size()<3)return;
        auto&back=qap_add_back(vars);
        back.type=params[1];
        back.name=params[2];
        scon.cmd_id++;
      }
      void If()
      {
        if(params.size()<2)return;
        auto&cond=unsafe_find_var(params[1]);
        if(cond.value!="true"){scon.cmd_id++;return;}
        QapPopFront(params);QapPopFront(params);
        sys_handle(params[0]);
      }
      t_var&unsafe_find_var(const string&name)
      {
        if(name.front()=='#')
        {
          static t_var tmp;tmp.type="int";tmp.value=sys_get_var(name);
          return tmp;
        }
        auto arr=qap_find(vars,[&name](t_var&var){return var.name==name;});
        if(arr.size()!=1){QapDebugMsg("found "+IToS(arr.size())+" var with name:\n"+name);return *(t_var*)nullptr;}
        return vars[arr[0]];
      }
      void div()
      {
        if(params.size()<4)return;
        if(params[3]=="2")
        {
          auto&out=unsafe_find_var(params[1]);
          auto&a=unsafe_find_var(params[2]);
          out.value=IToS(SToI(a.value)/2);
          scon.cmd_id++;
          return;
        }
        QapDebugMsg("no way");
        auto&out=unsafe_find_var(params[1]);
        auto&a=unsafe_find_var(params[2]);
        auto&b=unsafe_find_var(params[3]);
        QapAssert(out.type==a.type);
        QapAssert(a.type==b.type);
        out.value=IToS(SToI(a.value)/SToI(b.value));
        scon.cmd_id++;
      }
      void less()
      {
        if(params.size()<4)return;
        auto&out=unsafe_find_var(params[1]);
        auto&a=unsafe_find_var(params[2]);
        auto&b=unsafe_find_var(params[3]);
        out.value=BToS(SToI(a.value)<SToI(b.value));
        scon.cmd_id++;
      }
      void addbot()
      {
        if(params.size()<3)return;
        QapAssert(params[1]=="mpos");
        auto&back=qap_add_back(game.units);
        back.pos=con.get_mpos();
        back.name=params[2];
        scon.cmd_id++;
      }
      void fire()
      {
        if(params.size()<2)return;
        auto&back=qap_add_back(game.bullets);
        auto&target=game.unsafe_find_unit_by_name(params[1]);
        if(&target==&unit)return;
        back.v=(target.pos-unit.pos).SetMag(4.5);
        back.pos=unit.pos+back.v.SetMag(1+(game.unit_size+game.bullet_size)/2);
        back.name="[noname]";
        scon.cmd_id++;
      }
      void addsmartbot()
      {
        if(params.size()<4)return;
        QapAssert(params[1]=="mpos");
        auto&back=qap_add_back(game.units);
        back.pos=con.get_mpos();
        back.name="[noname]";
        back.script_context.build<TScriptContext>(con.Env);
        back.script="include "+params[2]+" "+params[3];
        scon.cmd_id++;
      }
      void addbrick()
      {
        //addbrick name x y w h
        if(params.size()<4)return;
        int w=0;int h=0;
        if(params.size()>=5)w=SToI(params[4]);
        h=w;
        if(params.size()>=6)h=SToI(params[5]);
        auto&back=qap_add_back(game.bricks);
        back.name=params[1];
        back.pos.x=SToI(params[2]);
        back.pos.y=SToI(params[3]);
        back.size=vec2d(w,h);
        scon.cmd_id++;
      }
      void bricksclear()
      {
        game.bricks.clear();
        scon.cmd_id++;
      }
      void delbot()
      {
        if(params.size()<2)return;
        QapAssert(params[1]=="this");
        unit.fuel=0;
        scon.cmd_id++;
      }
      void addpage()
      {
        if(params.size()<3)return;
        auto tn=params[1];
        auto page_name=params[2];
        auto&back=qap_add_back(con.book.pages);
        auto&types=con.Env.GetArr();
        auto&arr=qap_find(types,[&](EnvType&ex){return ex.Type->GetFullName()==tn;});
        if(!arr.empty())
        {
          int id=arr[0];
          auto&t=types[id].Type;
          auto*p=TTypeStruct::UberCast(t.get());
          QapAssert(p);
          QapAssert(p->IsBasedOn(Sys$$<IBookPage>::GetRTTI(con.Env)));
          back.unsafe_build(p);
          back->Caption=page_name;
        }
        scon.cmd_id++;
      }
      void genname()
      {
        if(params.size()<2)return;
        unit.name=params[1]+"_"+IToS(id);
        scon.cmd_id++;
      }
      void include()
      {
        if(params.size()<3)return;
        auto new_script=game.unsafe_find_unit_by_name(params[1]).script;
        lines=split(new_script,"\n");
        QapPopFront(params);
        nanocall();
        scon.cmd_id=0;
      }
      void mpdist()
      {
        unit.name="mpdist = "+FToS((con.get_mpos()-unit.pos).Mag());
        scon.cmd_id++;
      }
      void wait()
      {
        auto t=SToI(params[1]);
        if(scon.last_tick<0){scon.last_tick=t;/*unit.v=vec2d(0,0);*/}
        if(scon.last_tick){scon.last_tick--;return;}
        scon.cmd_id++;scon.last_tick=-1;
      }
      void boom()
      {
        if(params.size()<2)return;
        auto&ref=game.unsafe_find_explosion_by_name(params[1]);
        auto&back=qap_add_back(game.explosions);
        back=ref;
        back.pos=unit.pos;
        back.name+="[tick="+IToS(game.tick)+"]";
        scon.cmd_id++;
      }
      vector<int> sys_take()
      {
        return qap_find(units,[this](TGameUnit&ex)->bool{return (&unit!=&ex)&&((ex.pos-unit.pos).Mag()<game.unit_size);});
      }
      void take()
      {
        auto arr=sys_take();
        if(arr.empty()){scon.cmd_id++;return;}
        auto&src=units[arr[0]];
        scon.take(unit,src);
        scon.cmd_id++;
      }
      void take_all()
      {
        auto arr=sys_take();
        if(arr.empty()){scon.cmd_id++;return;}
        auto&src=units[arr[0]];
        if(scon.take(unit,src))return;
        scon.cmd_id++;
      }
      void setname(){if(params.size()<2)return;unit.name=sys_get_value(params[1]);scon.cmd_id++;}
      void setmem(){if(params.size()<2)return;unit.mem=sys_get_value(params[1]);scon.cmd_id++;}
      void GOTO(){if(params.size()<2)return;scon.cmd_id=SToI(params[1]);}
      void sys_handle(const string&cmd)
      {
        if(cmd.substr(0,2)=="//"){scon.cmd_id++;return;}
        if(cmd.substr(0,1)=="#"){
          auto s=join(params," ").substr(1);
          //lastpage
          auto fields=split(s,".");
          vector<string> f; bool mode=false;
          if(fields[1].find("++")!=std::string::npos){
            f=split(fields[1],"++");mode=true;}else{
            f=split(fields[1],"=");}
          auto field=f[0];
          
          auto*pType=con.book.pages.back().Product.pType.get();
          auto*pValue=con.book.pages.back().get();
          QapAssert(pType&&pValue);
          auto*ptr=TTypeStruct::UberCast(pType);
          QapAssert(ptr);
          auto*m=ptr->find_member(field);
          QapAssert(Sys$$<int>::GetRTTI(con.Env)==m->Type.get());
          auto&v=*(int*)m->getValue(pValue);
          if(mode){v++;}else{v=SToI(f[1]);}
          scon.cmd_id++;
          return;
        }
        #define F(METHOD)if(LowerStr(#METHOD)==LowerStr(cmd)){this->METHOD();return;}
        F(GOTO)F(setname)F(setmem)F(mpdist)F(wait)F(boom)F(take)F(take_all)F(proc)F(ondown)
        F(ret)F(call)F(nanocall)F(var)F(If)F(less)F(div)
        F(addbot)F(delbot)F(genname)F(include)F(addsmartbot)
        F(AddItemToScene)F(addbrick)F(bricksclear)F(fire)F(addpage)
        #undef F
        auto speed=2.5;
        #define F(x,y,dir)if(LowerStr(dir)==LowerStr(cmd)){unit.v=vec2d(x,y)*speed;scon.cmd_id++;return;}
        F(+0,+1,"up");
        F(+0,-1,"down");
        F(-1,+0,"left");
        F(+1,+0,"right");
        F(+0,+0,"stop");
        #undef F
      }
      string sys_get_var(const string&name)
      {
        if(name=="#unit_size")return IToS(game.unit_size);
        if(name=="#mpdist")return IToS((con.get_mpos()-unit.pos).Mag());
        return "";
      }
      string sys_get_value(const string&name)
      {
        if(name=="#fuel")return "fuel = "+IToS(unit.fuel);
        if(name=="#tick")return "tick = "+IToS(game.tick);
        if(name=="#mem")return "mem = "+unit.mem;
        if(name=="#id")return "id = "+IToS(id);
        return name;
      }
      void proc(){for(;scon.cmd_id<lines.size();scon.cmd_id++)if(lines[scon.cmd_id]=="RET")return;}
      bool sys_is_proc(const string&s){const static string kw="proc ";return s.substr(0,kw.size())==kw;}
      void ondown()
      {
        if(params.size()<3)return;
        int key=SToI(params[1]);
        #define F(KEY)if(LowerStr(params[1])==LowerStr(#KEY))key=KEY;
        F(VK_UP)F(VK_DOWN)F(VK_LEFT)F(VK_RIGHT)
        F(mbLeft)F(mbRight)F(mbMiddle)
        F(VK_DELETE)F(VK_RETURN)F(VK_BACK)
        #undef F
        if(con.kb.OnDown(key))
        {
          auto proc_name=params[2];
          QapPopFront(params);QapPopFront(params);
          sys_handle(params[0]);
          return;
        }
        scon.cmd_id++;
      }
      void ret()
      {
        if(frames.empty()){scon.cmd_id=0;return;}
        scon.cmd_id=frames.back().next_cmd_id;
        frames.pop_back();
      }
      void nanocall()
      {
        /*if(unit.name=="no")
        {
          unit.fuel++;
        }*/
        call();
        scon.cmd_id=0;
      }
      void call()
      {
        auto cmd_id=sys_get_proc_id(params[1]);
        if(cmd_id<0){QapDebugMsg("proc not found:\n"+params[1]);return;}
        qap_add_back(frames).next_cmd_id=scon.cmd_id+1;
        scon.cmd_id=cmd_id+1;
        for(int i=0;;i++)
        {
          if(frames.empty())return;
          int prev=scon.cmd_id;
          line=lines[scon.cmd_id];
          params=split(line," ");
          if(params[0]=="ret")
          {
            int gg=1;
          }
          sys_handle(params[0]);
          QapAssert(prev!=scon.cmd_id);
        }
      }
      int sys_get_proc_id(const string&proc)
      {
        for(int i=0;i<lines.size();i++)
        {
          if(!sys_is_proc(lines[i]))continue;
          auto arr=split(lines[i]," ");
          if(arr[1]!=proc)continue;
          return i;
        }
        return -1;
      }
    };
    #define MACRO_WEAK
    #include "macro_scope.inl"
    MACRO_WEAK_PROC(update,(TGameAboutScriptUnits&game,t_context&con,TGameUnit&unit,vector<TGameUnit>&units,int id),(game,con,unit,units,id))
    {
      auto&src=unit.script;
      auto&unit_size=game.unit_size;
      auto&tick=game.tick;
      if(last_script!=src){cmd_id=0;last_script=src;last_tick=-1;}
      auto lines=split(last_script,"\n");
      if(lines.empty())return;
      if(cmd_id>=lines.size())cmd_id=0;
      if(cmd_id<0)cmd_id=0;
      auto line=lines[cmd_id];
      auto arr=split(line," ");
      if(arr.empty())return;
      auto cmd=arr[0];
      t_cmd_list<0> cmd_list={game,con,unit,units,id,*this,lines,line,arr};
      cmd_list.sys_handle(cmd);
    }
    #include "macro_scope.inl"
  public:
    bool take(TGameUnit&dest,TGameUnit&src)
    {
      if(src.fuel<1)return false;
      src.fuel--;
      dest.fuel++;
      return true;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(TScriptContext)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameUnit)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(int,fuel,SET,1000,$)\
ADDVAR(int,charge,SET,1000,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,script,DEF,$,$)\
ADDVAR(string,mem,DEF,$,$)\
ADDVAR(TAutoPtr<TScriptContext>,script_context,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameUnit
#include "QapGenStruct.inl"
//<<<<<+=====TGameUnit
public:
};

class TGameBullet{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameBullet)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,script,DEF,$,$)\
ADDVAR(string,mem,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameBullet
#include "QapGenStruct.inl"
//<<<<<+=====TGameParticle
public:
};

class TGameParticle{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameParticle)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(real,t,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameParticle
#include "QapGenStruct.inl"
//<<<<<+=====TGameParticle
public:
};

class TGameExplosion{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameExplosion)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(bool,auto_draw,SET,true,$)\
ADDVAR(bool,blend_add,SET,true,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,64,$)\
ADDVAR(real,particle_beg_size,SET,2,$)\
ADDVAR(real,particle_end_size,SET,8,$)\
ADDVAR(QapColor,particle_beg_color,SET,0xff000000,$)\
ADDVAR(QapColor,particle_end_color,SET,0x00000000,$)\
ADDVAR(int,particle_life_time,SET,32,$)\
ADDVAR(int,particle_per_tick,SET,4,$)\
ADDVAR(real,particle_min_speed,SET,100.0/64.0,$)\
ADDVAR(real,particle_max_speed,SET,400.0/64.0,$)\
ADDVAR(real,particle_pos_dist,SET,32,$)\
ADDVAR(real,particle_pos_dist_var,SET,16,$)\
ADDVAR(vec2d,particle_grav,SET,vec2d_zero,$)\
ADDVAR(bool,undeadable,DEF,$,$)\
ADDVAR(vector<TGameParticle>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameExplosion
#include "QapGenStruct.inl"
//<<<<<+=====TGameExplosion
public:
};

//#include "TSimpleBinarySaver.inl"


class TGameAboutScriptUnits{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameAboutScriptUnits)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(bool,auto_draw,SET,true,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,select_id,SET,-1,$)\
ADDVAR(int,unit_size,SET,32,$)\
ADDVAR(int,bullet_size,SET,8,$)\
ADDVAR(bool,explosion_debug,DEF,$,$)\
ADDVAR(vector<TGameBrick>,bricks,DEF,$,$)\
ADDVAR(vector<TGameUnit>,units,DEF,$,$)\
ADDVAR(vector<TGameBullet>,bullets,DEF,$,$)\
ADDVAR(vector<TGameExplosion>,explosions,DEF,$,$)\
ADDVAR(vector<TGameExplosion>,ref_explosions,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameAboutScriptUnits
#include "QapGenStruct.inl"
//<<<<<+=====TGameAboutScriptUnits
public:
  typedef IBookPage::t_context t_context;
public:
  void GameDataBackup(t_context&con)
  {
    #define F(FIELD)QapPublicUberFullSaverBin(con.Env,QapRawUberObject(FIELD),"backup\\"#FIELD".qap");
    F(bricks)F(units)F(ref_explosions)
    #undef F
  }
  void GameDataLoad(t_context&con)
  {
    #define F(FIELD)QapPublicUberFullLoaderBin(con.Env,QapRawUberObject(FIELD),"backup\\"#FIELD".qap");
    F(bricks)F(units)F(ref_explosions)
    #undef F
  }
  void RenderViewText(t_context&con)
  {
    auto&qDev=con.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    auto cy=font.Info[0].y;
    {
      qDev.BindTex(0,&pFont->Tex);
      con.qDev.SetColor(0xff000000);
      //vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      auto add=[&](const string&text,int x,int y){
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+x),int(con.pos.y+y),text);//p.y+=-font.Info[0].y;
      };
      auto&arr=units;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        int w=QapQ3Text::GetLength(font,ex.name);
        qDev.SetColor(0xff000000);
        add(QapQ3Text::ToNormal(ex.name),ex.pos.x-w/2+2,ex.pos.y+cy*4/2-2);
        qDev.SetColor(0xffffffff);
        add(ex.name,ex.pos.x-w/2,ex.pos.y+cy*4/2);
      }
      qDev.BindTex(0,0);
    }
    qDev.BindTex(0,nullptr);
  }
  void render(t_context&con,vector<TGameUnit>&arr)
  {
    auto&texobj=con.root.SysRes.BallTex;
    if(texobj)
    {
      con.qDev.BindTex(0,&texobj->Tex);
    }
    QapDev::BatchScope Scope(con.qDev);
    con.qDev.SetColor(0xffffffff);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto p=vec2i(ex.pos.x,ex.pos.y)+con.pos;
      con.qDev.DrawQuad(p,vec2i(1,1)*unit_size);
    }
  }
  void render(t_context&con,vector<TGameBullet>&arr)
  {
    auto&texobj=con.root.SysRes.BallTex;
    if(texobj)
    {
      con.qDev.BindTex(0,&texobj->Tex);
    }
    QapDev::BatchScope Scope(con.qDev);
    con.qDev.SetColor(0xff000000);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto p=vec2i(ex.pos.x,ex.pos.y)+con.pos;
      con.qDev.DrawQuad(p,vec2i(2.5,1)*bullet_size,ex.v.GetAng());
    }
  }
  void render(t_context&con,TGameExplosion&ref)
  {
    if(!ref.auto_draw)return;
    QapAssert(!con.qDev.Batching);
    con.qDev.SetBlendMode(ref.blend_add?QapDev::BlendType::BT_ADD:QapDev::BlendType::BT_SUB);
    QapDev::BatchScope Scope(con.qDev);
    //con.qDev.SetColor(ref.particle_color);
    //render(con,ref.arr);
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[arr.size()-i-1];
      real t=1.0-ex.t/real(ref.particle_life_time);
      con.qDev.SetColor(QapColor::Mix(ref.particle_beg_color,ref.particle_end_color,t));
      con.qDev.DrawQuad(con.pos+ex.pos,vec2d(1,1)*Lerp(ref.particle_beg_size,ref.particle_end_size,t));
    }
    con.qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
  }
  void render(t_context&con,vector<TGameExplosion>&arr)
  {
    auto&texobj=con.root.SysRes.BallTex;
    if(texobj)
    {
      con.qDev.BindTex(0,&texobj->Tex);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      render(con,ex);
      //con.qDev.DrawQuad(con.pos+ex.pos,vec2d(1,1)*unit_size);
    }
  }
  void render(t_context&con,vector<TGameBrick>&arr)
  {
    QapDev::BatchScope Scope(con.qDev);
    con.qDev.BindTex(0,nullptr);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      con.qDev.SetColor(0xffa0a0a0);//4f4f4f);
      con.qDev.DrawQuad(con.pos+ex.pos,ex.size);
      con.qDev.SetColor(0xff808080);
      con.qDev.DrawRectAsQuad(con.pos+ex.pos,ex.size,2);
    }
  }
  void DrawBotSelection(t_context&con)
  {
    if(select_id<0)return;
    if(select_id>=units.size())return;
    con.qDev.BindTex(0,nullptr);
    con.qDev.SetColor(0xffffffff);
    con.qDev.DrawCircle(units[select_id].pos+con.pos,unit_size+8,tick*3.0*Pi/180.0,2,5);
  }
  void Render(t_context&con)
  {
    if(!auto_draw)return;
    con.qDev.SetColor(0xff000000);
    con.qDev.BindTex(0,nullptr);
    render(con,bricks);
    render(con,bullets);
    render(con,units);
    render(con,explosions);
    con.qDev.SetColor(0xff000000);
    con.qDev.BindTex(0,nullptr);
    DrawBotSelection(con);
    RenderViewText(con);
  }
  void update(t_context&con,vector<TGameUnit>&arr)
  {
    if(select_id>=0)if(select_id>=arr.size())select_id=-1;
    if(con.is_hovered())if(select_id>=0)if(!arr.empty())
    {
      auto&kb=con.kb;
      auto&ex=arr[select_id];
      auto v=vec2d_zero;
      auto speed=2.5;
      if(kb.Down[VK_LEFT])v+=vec2d(-speed,0);
      if(kb.Down[VK_RIGHT])v+=vec2d(+speed,0);
      if(kb.Down[VK_UP])v+=vec2d(0,+speed);
      if(kb.Down[VK_DOWN])v+=vec2d(0,-speed);
      if(v!=vec2d_zero||kb.Down[VK_SPACE])ex.v=v;
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(con.is_hovered())if(con.kb.OnDown(VK_RETURN))if(!ex.script_context)
      {
        ex.script_context.build<TGameUnit::TScriptContext>(con.Env);
      }
      if(ex.script_context)ex.script_context->update(*this,con,ex,units,i);
      arr[i].pos+=arr[i].v;
    }
    QapCleanIf(units,[](TGameUnit&ex){return ex.fuel<=0;});
  }
  void update(t_context&con,vector<TGameBullet>&arr)
  {
    QapCleanIf(arr,[](TGameBullet&ex){return ex.need_remove;});
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.pos+=ex.v;
    }
  }
  void update(t_context&con,vector<TGameExplosion>&arr)
  {
    QapCleanIf(arr,[](TGameExplosion&ex){return !ex.undeadable&&(ex.tick>=ex.max_tick)&&ex.arr.empty();});
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      update(con,ex);
    }
  }
  void update(t_context&con,TGameExplosion&ref)
  {
    if(!ref.auto_move)return;
    ref.tick++;
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.pos+=ex.v;
      ex.v+=ref.particle_grav;
      ex.t--;
    }
    QapCleanIf(ref.arr,[](TGameParticle&ex){return ex.t<=0;});
    if(!ref.undeadable)if(ref.tick>=ref.max_tick)return;
    auto rnd=[]()->real{int n=1024*16;return real(rand()%n)/real(n);};
    auto rnd_ang=[&rnd]()->real{return rnd()*Pi2;};
    for(int i=0;i<ref.particle_per_tick;i++)
    {
      auto&back=qap_add_back(ref.arr);//ex.arr.back();
      auto dist=ref.particle_pos_dist;
      auto dist_var=ref.particle_pos_dist_var;
      auto d=dist+dist_var*(-0.5+rnd());
      back.pos=ref.pos+Vec2dEx(rnd_ang(),d);
      auto ang=rnd_ang();
      auto mag=Lerp(ref.particle_min_speed,ref.particle_max_speed,rnd());
      back.v=Vec2dEx(ang,mag);
      back.t=ref.particle_life_time;
    }
  }
  TGameExplosion&unsafe_find_explosion_by_name(const string&name)
  {
    auto list=qap_find(ref_explosions,[&name](TGameExplosion&ex)->bool{return name==ex.name;});
    if(list.empty()){QapDebugMsg("ref_explosion not found:\n"+name);return *(TGameExplosion*)nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return ref_explosions[list[0]];
  }
  TGameUnit&unsafe_find_unit_by_name(const string&name)
  {
    auto list=qap_find(units,[&name](TGameUnit&ex)->bool{return name==ex.name;});
    if(list.size()!=1)
    {
      QapDebugMsg("found "+IToS(list.size())+" units with name:\n"+name);
      return *(TGameUnit*)nullptr;
    }
    return units[list[0]];
  }
  void TrySelectBot(t_context&con)
  {
    if(!con.kb.OnDown(mbLeft))return;
    if(!con.is_hovered())return;
    auto list=qap_find(units,[&](TGameUnit&ex)->bool{return (ex.pos-con.get_mpos()).Mag()*2.0<unit_size;});
    select_id=-1;
    if(list.empty())return;
    select_id=list[0];
  }
  static void line_vs_circle(const vec2d&a,const vec2d&b,vec2d&p,vec2d&v,real r)
  {
    vec2d ap=p-a;
    vec2d ab=b-a;
    auto ap_ox=ap.Rot(ab);
    if(ap_ox.x<0||ap_ox.x>ab.Mag())return;
    if(abs(ap_ox.y)>r)return;
    if(ap_ox.y>r)return;
    ap_ox.y=r;
    p=a+ap_ox.UnRot(ab);
    auto v_ox=v.Rot(ab);
    if(v_ox.y<0)v_ox.y*=-1;
    v=v_ox.UnRot(ab);
  }
  void DoCollide()
  {
    auto&arr=bricks;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto points=MakeQuadAABB(ex.pos-ex.size*0.5,ex.pos+ex.size*0.5);
      for(int j=0;j<units.size();j++)
      {
        auto&ey=units[j];
        auto r=unit_size*0.5;
        for(int k=0;k<points.size();k++)
        {
          int n=points.size();
          auto&a=points[(0+k)%n];
          auto&b=points[(1+k)%n];
          line_vs_circle(a,b,ey.pos,ey.v,r);//break;
        }
        for(int k=0;k<points.size();k++)
        {
          auto&a=points[k];
          auto&b=ey.pos;
          auto ab=b-a;
          if(ab.Mag()>=r)continue;
          b=a+ab.SetMag(r);
          auto&v=ey.v;
          auto v_ox=v.Rot(ab);
          if(v_ox.x<0)v_ox.x*=-1;
          v=v_ox.UnRot(ab);
        }
      }
    }
    //hard_joint(0,1);
    //hard_joint(2,3);
    for(int j=0;j<bullets.size();j++)
    {
      auto&bullet=bullets[j];
      for(int i=0;i<units.size();i++)
      {
        if(bullet.need_remove)continue;
        auto&unit=units[i];
        auto ab=unit.pos-bullet.pos;
        if(ab.Mag()*2>unit_size+bullet_size)continue;
        bullet.need_remove=true;
        unit.charge--;
        auto&back=qap_add_back(explosions);
        back=unsafe_find_explosion_by_name("short");
        back.pos=bullet.pos;
      }
      for(int i=0;i<bricks.size();i++)
      {
        if(bullet.need_remove)continue;
        auto&ex=bricks[i];
        if(!PointInQuad(bullet.pos,ex.pos,ex.size+vec2i(1,1)*bullet_size))continue;
        bullet.need_remove=true;
        auto&back=qap_add_back(explosions);
        back=unsafe_find_explosion_by_name("short");
        back.pos=bullet.pos;
      }
    }
    int gg=1;
  }
  void hard_joint(int id_a,int id_b)
  {
    auto&a=units[id_a].pos;
    auto&b=units[id_b].pos;
    auto ab=b-a;
    auto o=(a+b)*0.5;
    auto dp=ab.SetMag(unit_size/2);
    a=o-dp;
    b=o+dp;
    auto&av=units[id_a].v;
    auto&bv=units[id_b].v;
    auto av_ox=av.Rot(ab);
    auto bv_ox=bv.Rot(ab);
    std::swap(av_ox.x,bv_ox.x);
    av=av_ox.UnRot(ab);
    bv=bv_ox.UnRot(ab);
  }
  void Update(t_context&con){for(int i=0;i<1;i++)Update_old(con);}
  void Update_old(t_context&con)
  {
    if(!auto_move)return;
    if(con.is_hovered()&&con.kb.Down[VK_CONTROL]&&con.kb.Down[VK_SHIFT])
    {
      if(con.kb.OnDown(VK_PRIOR))GameDataBackup(con);
      if(con.kb.OnDown(VK_NEXT))GameDataLoad(con);
    }
    TrySelectBot(con);
    if(!tick)
    {
      qap_add_back(ref_explosions).name="mbLeft";
      qap_add_back(ref_explosions).name="mbRight";
    }
    update(con,bullets);
    update(con,units);
    update(con,explosions);
    UpdateExplosionDebug(con);
    DoCollide();
    //DoSoftwareDraw(con);
    tick++;
  }
  void UpdateExplosionDebug(t_context&con)
  {
    if(!explosion_debug)return;
    if(con.kb.OnDown(mbLeft)&&con.is_hovered())
    {
      auto&ref=unsafe_find_explosion_by_name("mbLeft");
      auto&back=qap_add_back(explosions);
      back=ref;
      //qap_simple_clone(con.Env,back,ref);
      back.name+="[tick="+IToS(tick)+"]";
      back.pos=con.get_mpos();
    }
    if(con.kb.OnDown(mbRight)&&con.is_hovered())
    {
      auto&ref=unsafe_find_explosion_by_name("mbRight");
      auto&back=qap_add_back(explosions);
      back=ref;
      //qap_simple_clone(con.Env,back,ref);
      back.name+="[tick="+IToS(tick)+"]";
      back.pos=con.get_mpos();
    }
  }
  void calc_surface_aabb_minmax(t_aabb_minmax&mm)
  {
    {auto&arr=bricks;for(int i=0;i<arr.size();i++){auto&ex=arr[i];mm.add_ex(ex.pos,ex.size);}}
    //{auto&arr=units; for(int i=0;i<arr.size();i++){auto&ex=arr[i];mm.add_ex(ex.pos,vec2d(1,1)*unit_size);}}
  }
  void DoSoftwareDraw(t_context&con)
  {
    static vector<QapTexMem> images;
    t_aabb_minmax mm;
    calc_surface_aabb_minmax(mm);
    vec2i surface_size=mm.get_size()+vec2i(1,1)*8;
    int W=surface_size.x;
    int H=surface_size.y;
    auto offset=-surface_size/2;
    QapTexMem mem;
    mem.Init(W,H);
    {
      auto&arr=bricks;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto p=ex.pos-offset;
        mem.DrawSolidQuad(p.x,p.y,ex.size.x,ex.size.y,0xff000000);
      }
    }
    //
    {
      auto&arr=units;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto p=ex.pos-offset;
        mem.DrawSolidCircle(p.x,p.y,unit_size/2,0xff000000);
      }
    }
    images.push_back(std::move(mem));
    if(images.size()<16)return;
    static int counter=0;
    vector<QapTexMem> tmp;tmp.resize(images.size());
    for(int i=0;i<tmp.size();i++){tmp[i].CopyDataFrom(images[i]);}
    auto result=QapTexMemMixer::mix_arr(tmp);
    SaveTextureToFile(result,"20140728\\"+QapTexMemMixer::num8tostr(counter)+".png");
    QapPopFront(images);
    counter++;//images.clear();
    int gg=1;
  }
};

class TBookPageWithGameAndEasyScript:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithGameAndEasyScript)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(TGameAboutScriptUnits,game,DEF,$,$)\
ADDVAR(TRawRect,editor_rect,DEF,$,$)\
ADDVAR(TRawRect,view_rect,DEF,$,$)\
ADDVAR(TScrollBar,bar,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithGameAndEasyScript
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithGameAndEasyScript
public:
  void Render(t_context&con)
  {
    bar.Render(con);
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      *(TDay20140605Book*)nullptr,
      editor_rect.pos,
      editor_rect.get_size(),
      con.path,
      con.context
    };
    context.pos=con.pos;
    context.size=con.size;
    editor_rect.Render(context);
    view_rect.Render(context);
    context.pos=con.pos+editor_rect.pos;
    context.size=editor_rect.get_size();
    editor.Render(context);
    context.pos=con.pos+view_rect.pos;
    context.size=view_rect.get_size();
    game.Render(context);
  }
  void UpdateRects(t_context&con,bool full)
  {
    auto bar_y=bar.get_quad(con).pos.y;
    auto CH=con.size.y;
    int ls=2;
    auto vs=-bar_y+CH/2-ls*2-bar.size/2;
    auto es=+bar_y+CH/2-ls*2-bar.size/2+CH%2;
    //int h=(con.size.y-ls*5)/2;
    int w=(con.size.x-ls*3);
    if(full)view_rect.fixed=true;
    if(full)view_rect.line_size=ls;
    if(view_rect.fixed)
    {
      int ls=view_rect.line_size;
      view_rect.pos.x=0;
      view_rect.pos.y=bar_y+vs-vs/2+ls+bar.size/2;
      view_rect.w=w;
      view_rect.h=vs;
    }
    if(full)editor.border=8;
    if(full)editor_rect.fixed=true;
    if(full)editor_rect.line_size=ls;
    if(editor_rect.fixed)
    {
      int ls=editor_rect.line_size;
      editor_rect.pos.x=0;
      editor_rect.pos.y=bar_y-es/2-ls-bar.size/2;
      editor_rect.w=w;
      editor_rect.h=es;
    }
  }
  void Update(t_context&con)
  {
    if(!tick||(con.kb.OnDown(VK_F4)&&con.is_hovered()))
    {
      if(!tick){bar.dir='y';bar.reverse=false;bar.value=5000;bar.maxv=10000;bar.color=0xff707070;bar.size=8;}
      if(Caption.empty())Caption="ScriptUnits";
      UpdateRects(con,true);
    }
    bar.Update(con);
    UpdateRects(con,false);
    tick++;
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      con.book,
      editor_rect.pos,
      editor_rect.get_size(),
      con.path,
      con.context
    };
    context.pos=con.pos;
    context.size=con.size;
    editor_rect.Update(context);
    view_rect.Update(context);
    context.pos=con.pos+editor_rect.pos;
    context.size=editor_rect.get_size();
    editor.Update(context);
    context.pos=con.pos+view_rect.pos;
    context.size=view_rect.get_size();
    game.Update(context);
    if(con.kb.OnDown(VK_F8)&&con.is_hovered())if(game.select_id>=0)if(game.select_id<game.units.size())
    {
      game.units[game.select_id].script=editor.text;
    }
    if(con.kb.OnDown(VK_F12)&&con.is_hovered())if(game.select_id>=0)if(game.select_id<game.units.size())
    {
      editor.text=game.units[game.select_id].script;
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
        F(TType)F(TBookPageWithEasyScript)F(TBookPageWithGameAndEasyScript)F(TBookPageWithScrollBar)\
        F(TBookPageWithClock)F(TBookPageWithColoredRect)\
        F(TBookPageWithTest20140731)F(TBookPageWithRectTest)F(TBookPageWithChat)
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
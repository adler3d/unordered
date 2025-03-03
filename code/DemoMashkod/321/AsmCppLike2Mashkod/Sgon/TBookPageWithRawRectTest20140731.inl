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
  array<vec2i,2> get_arr(const vec2i&offset)
  {
    array<vec2i,2> tmp; auto&a=tmp[0];auto&b=tmp[1];
    //tmp.reserve(2);
    //auto&a=qap_add_back(tmp);
    //auto&b=qap_add_back(tmp);
    auto dir=vec2i(1,0);
    a=offset+pos-dir*w/2;
    b=a+dir*w;
    return tmp;
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
      //auto res=qap_find(arr,[&](vec2i&ex){return (mpos-ex).Mag()<point_size;});
    }
    if(down&&d&&shift)
    {
      auto before=get_arr(vec2i_zero);
      if(point_id==0)
      {
        int c=(mpos-offset).x;
        //px-w/2=c
        //w=(c-px)*-2;
        w=(c-pos.x)*-2;
      }
      if(point_id==1)
      {
        int c=(mpos-offset).x;
        //px-w/2+w=c
        //w=c-px+w/2
        //2*w=2*(c-px)+w
        //w=2*(c-px)
        w=(c-pos.x)*2;
      }
      //int new_w=w;
      //for(w=-2000;w<2000;w++)
      //{
      //  auto arr=get_arr(vec2i_zero);
      //  if(arr[point_id].x!=(mpos-offset).x)continue;
      //  new_w=w;
      //  break;
      //}
      //w=new_w;
      auto arr=get_arr(vec2i_zero);
      QapAssert(arr[point_id].x==(mpos-offset).x);
    }
    if(down&&d&&!shift)
    {
      auto before=get_arr(vec2i_zero);
      if(point_id==0)
      {
        //pos.x=(mpos-offset).x+w/2
        //px=c+w/2;
        //
        //new.pos.x-new.w/2+new.w == old.pos.x-old.w/2+old.w
        //px-w/2+w=k
        //
        //c=(mpos-offset).x;
        //k=old.pos.x-old.w/2+old.w;
        //
        //solution:
        //px=c+w/2;
        //px-w/2+w=k
        //
        //w/2=px-k+w
        //px=c+(px-k+w)
        //0=c-k+w
        //w=k-c
        //
        //px=k+w/2-w
        int c=(mpos-offset).x;
        int k=pos.x-w/2+w;

        int new_w=k-c;
        int new_px=c+new_w/2;

        w=new_w;
        pos.x=new_px;
      }
      if(point_id==1)
      {
        //c=(mpos-offset).x;
        //k=old.pos.x-old.w/2
        //
        //px-w/2+w=c
        //k=px-w/2
        //
        //w/2=px-k
        //px-(px-k)+w=c
        //px-px+k+w=c
        //k+w=c
        //w=c-k
        //
        //px=c+w/2-w
        //
        int c=(mpos-offset).x;
        int k=pos.x-w/2;

        int new_w=c-k;
        int new_px=c+new_w/2-new_w;

        w=new_w;
        pos.x=new_px;
      }

      auto arr=get_arr(vec2i_zero);
      QapAssert(arr[point_id].x==(mpos-offset).x);
      QapAssert(arr[1-point_id].x==before[1-point_id].x);

      //static bool bruteforce=false;
      //if(bruteforce)
      //{
      //  auto new_pos=pos;
      //  auto new_w=w;
      //
      //  for(pos.x=-1000;pos.x<+1000;pos.x++)
      //  for(w=-2000;w<2000;w++)
      //  {
      //    auto arr=get_arr(vec2i_zero);
      //    if(arr[point_id].x!=(mpos-offset).x)continue;
      //    if(arr[1-point_id].x!=before[1-point_id].x)continue;
      //    new_w=w;new_pos=pos;
      //    goto end;
      //  }
      //  end:
      //  w=new_w;
      //  pos=new_pos;
      //}
      int gg=1;
    }
    down=down&&d;
    if(!down)point_id=-1;
  }
};
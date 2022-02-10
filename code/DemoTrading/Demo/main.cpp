#include "QapLite.h"

#define DEF_PRO_SORT_BY_FIELD(sort_by_field,TYPE,FIELD)\
  struct t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD{\
    static int __cdecl cmp_func(const void*a,const void*b){return cmp(*(TYPE*)a,*(TYPE*)b);}\
    static int cmp(const TYPE&a,const TYPE&b){return a.FIELD-b.FIELD;}\
  };\
  void sort_by_field(vector<TYPE>&arr){\
    if(arr.empty())return;\
    std::qsort(&arr[0],arr.size(),sizeof(t_id_with_dist),t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD::cmp_func);\
  }

struct t_quad{
  vec2d pos;
  vec2d size;
  void set(vec2d p,vec2d s){pos=p;size=s;}
};

static bool point_in_quad(t_quad q, vec2d p)
{
  auto s=q.size*0.5;
  auto o=p-q.pos;
  return abs(s.x)>=abs(o.x)&&abs(s.y)>=abs(o.y);
}

class TGame:public TQapGame{
public:
  struct t_unit{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec2d,pos,$)\
    ADD(string,name,$)\
    ADD(bool,deaded,false)\
    //===
    #include "defprovar.inl"
    //===
    t_unit(){DoReset();}
    t_unit&set(string nick){name=nick;return *this;}
  };
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_unit>,units,$)\
  ADD(string,status,"nothing")\
  ADD(int,r,24)\
  //===
  #include "defprovar.inl"
  //===
public:
  TGame(){
    DoReset();
    SetToDef();
  }
  void SetToDef(){
    qap_add_back(units).set("user").pos=vec2d(0,-250);
    qap_add_back(units).set("bot").pos=vec2d(0,+250);
    for(int i=0;i<10;i++)
    {
      qap_add_back(units).set("bot"+IToS(i)).pos=vec2d(-250+i*60,+300);
    }
  }
  void DoMove()
  {
    if(kb.Down[VK_ESCAPE])win.Close();
    for(int i=0;i<units.size();i++)
    {
      auto&ex=units[i];
      if(!i)ex.pos+=this->get_dir_from_keyboard_wasd_and_arrows().SetMag(3.5);
    }
    soListOfPlayers(false);
  }
  void DoDraw()
  {
    auto wcs=win.GetClientSize();
    QapDev::BatchScope Scope(qDev);
    qDev.BindTex(0,nullptr);
    for(int i=0;i<units.size();i++)
    {
      auto&ex=units[i]; auto&p=ex.pos;
      qDev.color=0xff000000;
      if(!i)qDev.color=0xffAA0000;
      qDev.DrawCircleEx(ex.pos,r,0,16,0);
      qDev.color=0xffffffff;
      DrawText(p.x-10,p.y+8,ex.name,16);
    }
    qDev.color=0xff000000;
    soListOfPlayers(true);
    qDev.color=0xff000000;
    for(;;)
    {
      qDev.SetColor(0xff000000);
      int textsize=16; int dy=-textsize*1;
      vec2i p(-wcs.x/2+64,wcs.y/2-16);p.y+=dy;
      #define F(MSG)DrawText(p.x,p.y,MSG,textsize);p.y+=dy;
      F("status = "+status);
      #undef F
      break;
    }
  }
  struct t_id_with_dist{
    int id;
    real dist;
  };
  DEF_PRO_SORT_BY_FIELD(sort_by_dist,t_id_with_dist,dist);
  void soListOfPlayers(bool drawpass)
  {
    auto userpos=units[0].pos;
    vector<t_id_with_dist> arr;
    for(int i=0;i<units.size();i++)
    {
      if(!i)continue;
      auto&ex=units[i];
      t_id_with_dist rec={i,(userpos-ex.pos).Mag()};
      qap_add_back(arr)=rec;
    }
    sort_by_dist(arr);
    auto wcs=win.GetClientSize();
    for(;;)
    {
      qDev.SetColor(0xff000000);
      int textsize=16; int dy=textsize*1;
      auto pix_from_right_border=200; auto pfrb=pix_from_right_border;
      vec2i p(+wcs.x/2-64-pfrb,-wcs.y/2+32);p.y+=dy;vec2i cur=p;
      #define F(MSG)if(drawpass){qDev.color=0xff000000;DrawText(p.x,p.y,MSG,textsize);}p.y+=dy;cur=p;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        t_quad q;
        q.pos=cur+vec2d(pfrb/2,-dy/2);
        q.size=vec2d(pfrb,dy);
        if(point_in_quad(q,mpos)){
          if(drawpass){qDev.color=0x20eeee00;qDev.DrawQuad(q.pos,q.size);}
          if(!drawpass)if(kb.OnDown(mbRight)){
            status="open menu for "+units[ex.id].name;
          }
        }
        //if(i==0)if(drawpass){qDev.color=0x20eeee00;qDev.DrawQuad(q.pos,q.size);qDev.color=0xff000000;}
        F(units[ex.id].name);
      }
      #undef F
      break;
    }
  }
  void DrawQuad(t_quad q)
  {
    qDev.DrawQuad(q.pos,q.size);
    qDev.color=QapColor::HalfMix(0xff000000,qDev.color);
    qDev.DrawRectAsQuad(q.pos,q.size,2);
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}
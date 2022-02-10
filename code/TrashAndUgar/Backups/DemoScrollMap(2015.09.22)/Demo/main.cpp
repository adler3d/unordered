#include "QapLite.h"
#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }
#include "TQapGameV2.inl"
#define DEF_PRO_PROXY_GAME_FIELD(VAR)auto&VAR=game.VAR;
#define DEF_PRO_PROXY_UNIT_FIELD(VAR)auto&VAR=unit.input.VAR;
#define DEF_PRO_FIELDS_FROM_GAME(F)F(drawpass)F(movepass)F(srvpass)F(cntpass)F(qDev)F(viewport)/*F(textsize)F(r)*/
#define DEF_PRO_FIELDS_FROM_UNIT(F)F(kb)F(mpos)F(consize)
#define SO_PASS()DEF_PRO_FIELDS_FROM_GAME(DEF_PRO_PROXY_GAME_FIELD);
#define SO_UNIT()DEF_PRO_FIELDS_FROM_UNIT(DEF_PRO_PROXY_UNIT_FIELD)
#define SO_HEAD()SO_PASS();SO_UNIT()

class TGame:public TQapGameV2{
public:
  struct t_unit{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_input,input,$)\
    ADD(string,name,$)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(int,tick,0)\
    ADD(bool,offcentric,false)\
    ADD(bool,camrot,true)\
    //===
    #include "defprovar.inl"
    //===
    t_unit(){DoReset();}
    t_unit&set(string nick){name=nick;return *this;}
    t_unit&set_pos(const vec2d&new_pos){pos=new_pos;return *this;}
    t_unit&set_pos(const real&x,const real&y){pos=vec2d(x,y);return *this;}
  };
  struct t_bullet{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,dist,0)\
    //===
    #include "defprovar.inl"
    //===
    t_bullet(){DoReset();}
  };
  struct t_map{
    vector<int> mem;
    int w;
    int h;
    void init(const int size=4)
    {
      w=size;
      h=size;
      mem.resize(w*h);
      for(int i=0;i<w*h;i++)
      {
        mem[i]=(i%w+i/h)%2?0x80:0xA8;
      }
    }
  };
  struct t_world{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_unit>,units,$)\
    ADD(vector<t_bullet>,bullets,$)\
    ADD(int,r,24)\
    ADD(int,textsize,16)\
    ADD(int,last_actor_id,-1)\
    ADD(t_input,input,$)\
    ADD(t_map,map,$)\
    //===
    #include "defprovar.inl"
    //===
    t_world(){DoReset();}
    PRO_FUNCGEN_GETP_BY_FIELD(t_unit,getp,units,int,input.actor_id);
    t_unit&add_unit(string name)
    {
      last_actor_id++;
      auto&ex=qap_add_back(units);
      ex.name=name;
      ex.input.actor_id=last_actor_id;
      return ex;
    }
    static void qap_text_draw_at_x_center(QapDev&qDev,const vec2d&pos,const string&msg,int textsize)
    {
      t_quad q;
      q.size=qap_text::get_size(qDev,msg,textsize);
      q.pos=pos;
      qap_text::draw(qDev,q.get_left_top(),msg,textsize);
    }
    void draw_unit_with_name(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      bool this_actor=unit.input.actor_id==input.actor_id;
      qDev.color=0xff000000;
      if(this_actor)qDev.color=0xffAA0000;
      qDev.DrawCircleEx(unit.pos,r,0,16,0);
      qDev.color=0xffffffff;
      qap_text_draw_at_x_center(qDev,unit.pos,unit.name,textsize);
    }
    static vec2i vec2d_round(vec2d p,vec2d dir){
      vec2i r;
      r.x=p.x;
      r.y=p.y;
      if(dir.x>0)if(real(r.x)!=p.x)r.x++;
      if(dir.y>0)if(real(r.y)!=p.y)r.y++;
      return r;
    }
    static vec2i tovec2i(vec2d p){return vec2i(p.x,p.y);}
    void soUnit(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      real blcok_size=64;
      if(srvpass&&movepass)
      {
        unit.tick++;
        if(unit.input)
        {
          if(unit.tick>30)if(unit.input.kb.Down(mbLeft))
          {
            {
              auto&b=qap_add_back(bullets);
              //auto xf=t_offcentric_scope::make_xf(viewport,unit.pos,unit.dir,unit.offcentric);
              auto off_offset=unit.offcentric?vec2d(0,viewport.size.y*t_offcentric_scope::get_koef()):vec2d(0,0);
              b.dir=(unit.input.mpos+off_offset).Rot(unit.dir);
              b.pos=unit.pos+b.dir.Ort().SetMag(8);
              b.dist=8.5*blcok_size;
              unit.tick=0;
            }
            {
              auto&b=qap_add_back(bullets);
              //auto xf=t_offcentric_scope::make_xf(viewport,unit.pos,unit.dir,unit.offcentric);
              auto off_offset=unit.offcentric?vec2d(0,viewport.size.y*t_offcentric_scope::get_koef()):vec2d(0,0);
              b.dir=(unit.input.mpos+off_offset).Rot(unit.dir);
              b.pos=unit.pos-b.dir.Ort().SetMag(8);;
              b.dist=8.5*blcok_size;
              unit.tick=0;
            }
          }
          if(unit.camrot)
          {
            if(unit.input.kb.Down('Z'))unit.dir=vec2d(1,0);
            if(unit.input.kb.OnDown('T'))unit.offcentric=!unit.offcentric;
            real da=0;
            if(unit.input.kb.Down('Q'))da-=1;
            if(unit.input.kb.Down('E'))da+=1;
            unit.dir=Vec2dEx(unit.dir.GetAng()+(da*Pi/64.0),1);
          }else{
            unit.dir=vec2d(1,0);
          }
          unit.pos+=unit.input.kb.get_dir_from_wasd_and_arrows().SetMag(3.5).Rot(unit.dir);
        }
        return;
      }
      if(!drawpass)return;
      bool this_actor=unit.input.actor_id==input.actor_id;
      QapAssert(cntpass);QapAssert(this_actor);
      static real draw_time=0;
      {
        QapClock clock;clock.Start();
        t_offcentric_scope offscope(qDev,unit.pos,unit.dir,unit.offcentric);
        //draw map
        qDev.color=0xff000000;
        vec2d offset=vec2d(map.w,map.h)*blcok_size*0.5;
        auto vp=viewport.add_size(vec2d(1,1)*blcok_size*sqrt(2.0));
        vec2i imin;vec2i imax;
        {
          //vp=vp.add_size(-vec2d(1,1)*s*sqrt(2.0)*4);
          vec2d minp;vec2d maxp;
          vec2d dir=vec2d(1,1);
          for(int i=0;i<4;i++)
          {
            dir=dir.Ort();
            vec2d qvp=vec2d(vp.get_vertex_by_dir(dir)-vp.pos-vec2d(qDev.xf.p)).Rot(qDev.xf.r.col1);
            vec2d mqc=(qvp+offset-dir*0.5*blcok_size)*(1.0/blcok_size);
            vec2i ic=vec2d_round(mqc,dir);
            //if(x==ic.x&&y==ic.y)qDev.color=0xffff0000;
            if(!i)
            {
              maxp=ic;
              minp=ic;
              continue;
            }
            vec2d::comax(maxp,ic);
            vec2d::comin(minp,ic);
          }
          imin=tovec2i(vec2d::max(vec2d_zero,minp));
          imax=tovec2i(vec2d::min(vec2d(map.w,map.h),maxp+vec2d(1,1)));
        }
        int c=0;
        for(int y=imin.y;y<imax.y;y++)for(int x=imin.x;x<imax.x;x++)
        {        
          auto pos=vec2d(qDev.xf*(vec2d(x,y)*blcok_size-offset))+qDev.viewport.pos;
          if(vp.clamp(pos)!=pos)continue;
          auto v=map.mem[x+y*map.w];
          qDev.color.a=0xff;
          //if(vp.clamp(pos)!=pos){qDev.color.a=0xff;v-=0x40;};
          qDev.color.r=v;
          qDev.color.g=v;
          qDev.color.b=v;
          qDev.DrawQuad(vec2d(x,y)*blcok_size-offset,blcok_size,blcok_size);c++;
        }
        //draw bullets
        for(int i=0;i<bullets.size();i++)
        {
          auto&ex=bullets[i];
          qDev.color=0xff884444;
          qDev.DrawCircleEx(ex.pos,7,0,7,0);
        }
        //draw units
        for(int i=0;i<units.size();i++)
        {
          auto&ex=units[i];
          draw_unit_with_name(game,ex);
        }
        //qDev.color=0xff000000;qDev.DrawQuad(circle_pos,64,64);
        //qDev.use_xf=false;
        clock.Stop();
        draw_time=clock.MS();
      }
      //draw gui
      for(;;)
      {
        qDev.SetColor(0xff000000);
        int dy=-textsize*1;
        vec2i p(-consize.x/2+64,consize.y/2-16);p.y+=dy;
        #define F(MSG)qap_text::draw(qDev,p.x,p.y,MSG,textsize);p.y+=dy;
        F("name = "+unit.name);
        F("pos = "+FToS(unit.pos.x)+"   "+FToS(unit.pos.y));
        F("mpos = "+FToS(unit.input.mpos.x)+"   "+FToS(unit.input.mpos.y));
        F("active = "+IToS(point_in_quad(t_quad().add_size(consize),mpos)));
        F("draw_time = "+FToS(draw_time));
        #undef F
        break;
      }
    }
    void soUpdate(TGame&game)
    {
      SO_PASS();
      QapAssert(drawpass!=movepass);
      if(srvpass&&drawpass&&!movepass)return;
      if(movepass&&cntpass)return;
      //client.draw or serv.move
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        bool this_actor=ex.input.actor_id==input.actor_id;
        if(!this_actor&&!srvpass)continue;
        soUnit(game,ex);
      }
      if(srvpass)
      {
        for(int i=0;i<bullets.size();i++)
        {
          auto&ex=bullets[i];
          auto bullets_mag=10.1;
          ex.pos+=ex.dir.SetMag(bullets_mag);
          ex.dist-=bullets_mag;
          if(ex.dist<0)ex.deaded=true;
        }
        qap_clean_if_deaded(bullets);
      }
    }
  };
};

class TMutiplayerGame:public TGame{
public:
  //#include "t_mutiplayer.inl"
  int client_id;
  t_world world;
  TMutiplayerGame(){
    DoReset();
    client_id=-1;
    world.input=world.add_unit("user").input;
    world.map.init();
    /*
    qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_a").set_pos(+100,0).input.actor_id;
    qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_b").set_pos(-100,0).input.actor_id;
    server.world.add_unit("bot_a").set_pos(0,200);
    server.world.map.init();*/
    //qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_c").set_pos(0,100).input.actor_id;
  }
  void soUpdate()
  {
    world.units[0].input.kb=kb;
    world.units[0].input.consize=consize;
    world.units[0].input.mpos=mpos;
    if(movepass){
      cntpass=false;
      srvpass=true;
      world.soUpdate(*this);
      srvpass=false;
      cntpass=true;
      //world.soUpdate(*this);
    }
    if(drawpass){
      cntpass=true;
      world.soUpdate(*this);
    }
  }
  void DoDraw(){

  }
  void DoMove(){
    if(kb.Down(VK_ESCAPE))win.Close();
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TMutiplayerGame builder;
  builder.DoNice();
}
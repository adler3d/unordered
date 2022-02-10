#define _ITERATOR_DEBUG_LEVEL 0
#define _HAS_ITERATOR_DEBUGGING 0
#define _SECURE_SCL 0
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
  struct t_mem{};
  /*
  struct t_keyvalue{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,key,$)\
    ADD(string,value,$)\
    //===
    #include "defprovar.inl"
    //===
    t_keyvalue(){DoReset();}
  };
  struct t_mem{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_keyvalue>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
    t_mem(){DoReset();}
  };*/
  struct t_cooldown{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,t,0)\
    ADD(int,cooldown,100)\
    //===
    #include "defprovar.inl"
    //===
    t_cooldown(){DoReset();}
    bool operator()(int tick){if(tick-t<cooldown)return false;t=tick;return true;}
    void operator=(int cd){cooldown=cd;}
  };
  struct t_weapon{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(string,bullet_type,$)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,dist,100)\
    ADD(t_cooldown,cooldown,$)\
    ADD(t_mem,mem,$)\
    //===
    #include "defprovar.inl"
    //===
    t_weapon(){DoReset();}
  };
  struct t_unit{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(t_input,input,$)\
    ADD(string,name,$)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,r,24)\
    ADD(real,speed,4.5)\
    ADD(int,hp,64)\
    ADD(int,tick,0)\
    ADD(t_weapon,weapon,$)\
    ADD(bool,offcentric,false)\
    ADD(bool,camrot,true)\
    ADD(bool,autofire,false)\
    //===
    #include "defprovar.inl"
    //===
    t_unit(){DoReset();}
    t_unit&set(string nick){name=nick;return *this;}
    t_unit&set_pos(const vec2d&new_pos){pos=new_pos;return *this;}
    t_unit&set_pos(const real&x,const real&y){pos=vec2d(x,y);return *this;}
  };
  struct t_monster{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,r,24)\
    ADD(real,dist,100)\
    ADD(real,speed,1.5)\
    ADD(int,hp,64)\
    ADD(int,tick,0)\
    ADD(t_mem,mem,$)\
    ADD(t_cooldown,spawn,$)\
    ADD(vector<t_weapon>,weapons,$)\
    ADD(string,behavior,"stay&fire")\
    //===
    #include "defprovar.inl"
    //===
    t_monster(){DoReset();}
  };
  struct t_bullet{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,bullet_speed,10.1)\
    ADD(real,dist,100)\
    ADD(real,r,7)\
    //===
    #include "defprovar.inl"
    //===
    t_bullet(){DoReset();}
  };
  static const int map_max_size=25;
  struct t_map{
    typedef int t_elem;
    vector<t_elem> mem;
    int w;
    int h;
    void to_zero(){for(int i=0;i<w*h;i++)mem[i]=0;}
    void init()
    {
      w=map_max_size;
      h=map_max_size;
      mem.resize(w*h);
      QapTexMem tm;tm.Init(w,h);
      for(int i=0;i<w*h;i++)
      {
        mem[i]=0x80+rand()%(0x90-0x80);//(i%w+i/h)%2?0x80:0xA8;
        if(rand()%32==0)mem[i]=0x50;
        if(rand()%128==0)mem[i]=0x5F;
      }
      //for(int i=0;i<24;i++)mem[118+i+122*w]=0x50;
      //mem[118+122*w]=0xD8;
      //mem[118+124*w]=0xD8;
      //get(132,127)=0x50;
      //get(133,128)=0x50;
      /*
      for(int i=0;i<w*h;i++){
        auto v=mem[i];
        tm.Arr[i]=QapColor(v,v,v);
      }
      tm.BlurTexture(8);
      for(int i=0;i<w*h;i++)
      {
        if(mem[i]!=0x50)if(tm.Arr[i].r!=0x50)mem[i]=tm.Arr[i].r;
      }*/
    }
    static void set_to_def(t_elem&elem){elem=0;}
    #include "t_map_getters.inl"
  };
  struct t_map_of_monsters{
    typedef vector<t_monster> t_elem;
    vector<t_elem> mem;
    int w;
    int h;
    void init()
    {
      w=map_max_size;
      h=map_max_size;
      mem.resize(w*h);
    }
    static void set_to_def(t_elem&elem){elem=t_elem();}
    #include "t_map_getters.inl"
  };
  #include "t_geom.inl"
  struct t_world{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_unit>,units,$)\
    ADD(vector<t_monster>,monsters,$)\
    ADD(vector<t_bullet>,bullets_to_units,$)\
    ADD(vector<t_bullet>,bullets_to_monsters,$)\
    ADD(vector<t_bullet>,particles,$)\
    ADD(int,r,24)\
    ADD(int,textsize,16)\
    ADD(int,last_actor_id,-1)\
    ADD(int,tick,0)\
    ADD(t_input,input,$)\
    ADD(t_map,map,$)\
    ADD(t_map_of_monsters,map_mon,$)\
    ADD(t_map,map_acc,$)\
    //---
    void copy(const t_world&from){
      auto&dest=*this;
      #define NOT(NAME,X)if(!is_same(&dest.NAME,&dest.X))
      #define F(TYPE,NAME,VALUE)NOT(NAME,map_mon)NOT(NAME,map_acc)NOT(NAME,map)dest.NAME=from.NAME;
      DEF_PRO_VARIABLE(F);
      #undef NOT
      #undef F
    }
    //===
    #include "defprovar.inl"
    //===
    bool is_same(void*a,void*b){return a==b;}
    //void operator=(const t_world&from){copy(from);}
    t_world(){DoReset();}
    PRO_FUNCGEN_GETP_BY_FIELD(t_unit,getp,units,int,input.actor_id);
    const t_unit*getp(int value)const
    {
      const t_unit*p=nullptr;
      for(int i=0;i<units.size();i++){
        auto&ex=units[i];
        if(ex.input.actor_id!=value)continue;
        QapAssert(!p);
        p=&ex;
      }
      return p;
    }
    t_unit&add_unit(string name)
    {
      last_actor_id++;
      auto&ex=qap_add_back(units);
      ex.name=name;
      ex.input.actor_id=last_actor_id;
      ex.weapon.cooldown=25;
      ex.weapon.bullet_type="two";
      ex.hp=100;
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
      auto tmp=qDev.xf;
      qDev.xf.r.set_ident();
      qDev.xf.p=tmp*unit.pos;
      qap_text_draw_at_x_center(qDev,vec2d(0,0),unit.name,textsize);
      qDev.xf=tmp;
    }
    static vec2i vec2d_round(vec2d p,vec2d dir){
      vec2i r;
      r.x=p.x;
      r.y=p.y;
      if(dir.x>0)if(real(r.x)!=p.x)r.x++;
      if(dir.y>0)if(real(r.y)!=p.y)r.y++;
      return r;
    }
    static real get_block_size(){return 50;}
    static vec2i tovec2i(vec2d p){return vec2i(p.x,p.y);}
    #include "solver.inl"
    static real get_bullets_r(){return 7;}
    vector<t_bullet>&get_bullets_container(char to){
      if(to=='P')return particles;
      if(to=='M')return bullets_to_monsters;
      if(to=='U')return bullets_to_units;
      static vector<t_bullet> fail;
      QapNoWay();
      return fail;
    };
    t_bullet&add_bullet(char to)
    {
      auto&b=qap_add_back(get_bullets_container(to));
      //b.dir=dir;b.pos=pos;
      b.dist=8.5*get_block_size();
      b.r=get_bullets_r();
      return b;
    }
    t_bullet&add_bullet_ex(char to,const vec2d&pos,const vec2d&dir){auto&b=add_bullet(to);b.pos=pos;b.dir=dir;return b;};
    void add_two_bullets(char to,const vec2d&dir,const vec2d&pos)
    {
      add_bullet_ex(to,pos+dir.Ort().SetMag(8),dir);
      add_bullet_ex(to,pos-dir.Ort().SetMag(8),dir);
    }
    t_monster&add_def_monster()
    {
      auto&b=qap_add_back(monsters);
      b.dir=vec2d(1,0);
      b.dist=get_block_size()*15;
      auto&w=qap_add_back(b.weapons);
      w.bullet_type="one";
      w.cooldown.cooldown=35;
      w.dist=b.dist;
      return b;
    }
    void soUnit(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      real block_size=get_block_size();
      auto screen_to_world=[&](const vec2d&pos)->vec2d{
        auto off_offset=unit.offcentric?vec2d(0,viewport.size.y*t_offcentric_scope::get_koef()):vec2d(0,0);
        return unit.pos+(pos+off_offset).Rot(unit.dir);
      };
      auto&g_map=map;auto&map=g_map;
      auto screen_to_map=[&](const vec2d&pos)->vec2d{return world_to_map(map,screen_to_world(pos));};
      if(srvpass&&movepass)
      {
        unit.tick++;
        if(unit.input&&!unit.deaded)
        {
          if(unit.input.kb.Down(mbLeft)||unit.autofire)if(unit.weapon.cooldown(unit.tick))
          {
            weapon_fire('M',unit.weapon,unit.pos,screen_to_world(unit.input.mpos)-unit.pos);
          }
          if(unit.input.kb.OnDown('I'))unit.autofire=!unit.autofire;
          //if(unit.input.kb.OnDown('H'))unit.pos.y=get_block_size()*map.h/2;
          if(unit.camrot)
          {
            if(unit.input.kb.Down('Z'))unit.dir=vec2d(1,0);
            if(unit.input.kb.OnDown('T'))unit.offcentric=!unit.offcentric;
            real da=0;
            if(unit.input.kb.Down('Q'))da-=1;
            if(unit.input.kb.Down('E'))da+=1;
            unit.dir=Vec2dEx(unit.dir.GetAng()+(da*Pi/75.0),1);
          }else{
            unit.dir=vec2d(1,0);
          }
          unit.pos+=unit.input.kb.get_dir_from_wasd_and_arrows().SetMag(unit.speed).Rot(unit.dir);
          solve_col_unit_vs_map(map,unit.pos,r,true);
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
        vec2d offset=vec2d(map.w,map.h)*block_size*0.5;
        auto vp=viewport.add_size(vec2d(1,1)*block_size*sqrt(2.0));
        vec2i imin;vec2i imax;
        {
          //vp=vp.add_size(-vec2d(1,1)*s*sqrt(2.0)*4);
          vec2d minp;vec2d maxp;
          vec2d dir=vec2d(1,1);
          for(int i=0;i<4;i++)
          {
            dir=dir.Ort();
            vec2d qvp=vec2d(vp.get_vertex_by_dir(dir)-vp.pos-vec2d(qDev.xf.p)).Rot(qDev.xf.r.col1);
            vec2d mqc=(qvp+offset-dir*0.5*block_size)*(1.0/block_size);
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
          auto pos=vec2d(qDev.xf*(vec2d(x,y)*block_size-offset))+qDev.viewport.pos;
          if(vp.clamp(pos)!=pos)continue;
          auto v=map.mem[x+y*map.w];
          qDev.color.a=0xff;
          //if(vp.clamp(pos)!=pos){qDev.color.a=0xff;v-=0x40;};
          qDev.color.r=v;
          qDev.color.g=v;
          qDev.color.b=v;
          qDev.DrawQuad(vec2d(x,y)*block_size-offset,block_size,block_size);c++;
          if(v==0x50){qDev.color=0xffFF0000;qDev.DrawQuad(map_to_world(map,vec2d(x,y)),vec2d(4,4));}
          if(v==0x5F){qDev.color=0xffFFFF00;qDev.DrawQuad(map_to_world(map,vec2d(x,y)),vec2d(4,4));}
        }
        //draw bullets
        auto br=get_bullets_r();
        auto circle=game.GenGeomCircleSolid(7,7,0);
        auto draw_bullets=[&](const vector<t_bullet>&bullets){
          for(int i=0;i<bullets.size();i++)
          {
            auto&ex=bullets[i];
            qDev.color=0xffd8d8d8;
            game.DrawGeomWithOffset(circle,ex.pos);
            //qDev.DrawCircleEx(ex.pos,ex.r,0,7,0);
          }
        };
        draw_bullets(bullets_to_units);
        draw_bullets(bullets_to_monsters);
        circle=game.GenGeomCircleSolid(3,5,0);
        draw_bullets(particles);
        //draw units
        for(int i=0;i<units.size();i++)
        {
          auto&ex=units[i];
          draw_unit_with_name(game,ex);
        }
        //draw monsters
        for(int i=0;i<monsters.size();i++)
        {
          auto&ex=monsters[i];
          qDev.color=0xff787878;
          auto r=ex.r;
          qDev.DrawCircleEx(ex.pos,r,r/2,7,-ex.tick*Pi2/120.0);
          qDev.color=0xffd8d8d8;
          qDev.DrawCircleEx(ex.pos,r,r*3/4,5,ex.tick*Pi2/80.0);
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
        {
          auto m=screen_to_map(unit.input.mpos);
          F("map(mpos) = "+FToS(m.x)+"   "+FToS(m.y));
        }
        F("active = "+IToS(point_in_quad(t_quad().add_size(consize),mpos)));
        F("draw_time = "+FToS(draw_time));
        F("hp = "+IToS(unit.hp));
        F("monsters = "+IToS(monsters.size()));
        F("bullets_to_monsters = "+IToS(bullets_to_monsters.size()));
        F("bullets_to_units = "+IToS(bullets_to_units.size()));
        F("particles = "+IToS(particles.size()));
        #undef F
        break;
      }
    }
    static int get_numbers_of_block_affected_by_players(){return 18;}
    //:soUpdate
    void soUpdate(TGame&game)
    {
      SO_PASS();
      QapAssert(drawpass!=movepass);
      if(srvpass&&drawpass&&!movepass)return;
      if(srvpass)tick++;
      if(movepass&&cntpass)return;
      auto br=get_bullets_r();
      vector<vec2d> sp;
      vector<real> sp_bs;
      //client.draw or serv.move
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        bool this_actor=ex.input.actor_id==input.actor_id;
        if(!this_actor&&!srvpass)continue;
        soUnit(game,ex);
        if(srvpass)
        {
          for(int i=0;i<bullets_to_units.size();i++)
          {
            auto&b=bullets_to_units[i];
            if(b.r>=br)if((b.pos-ex.pos).Mag()<b.r+r)
            {
              b.deaded=true;
              ex.hp--;
              qap_add_back(sp)=b.pos;
              qap_add_back(sp_bs)=b.bullet_speed;
            }
          }
          if(ex.hp<0)ex.deaded=true;
        }
        if(srvpass)
        {
          auto wp=tovec2i(world_to_map(map,ex.pos));
          auto d=get_numbers_of_block_affected_by_players();
          //update block affected by player
          for(int y=-d;y<=+d;y++)for(int x=-d;x<=+d;x++)
          {
            auto c=wp+vec2i(x,y);
            auto&cur=map_acc.get(c);
            if(&cur==&map_acc.fail_id())continue;
            if(!map_mon.get(c).empty()){
              auto&arr=map_mon.get(c);for(int i=0;i<arr.size();i++)qap_add_back(monsters)=arr[i];
              arr.clear();
            }
            if(cur==0){if(tick!=1){
              if(rand()%64==0)add_rnd_monster(map_to_world(map,c));
            }}else
            if(tick-cur>64*5){
              auto t=(tick-cur)/64;
              auto n=t/60;
              for(int i=0;i<n;i++)if(rand()%(64*5)==0)add_rnd_monster(map_to_world(map,c));
            }
            cur=tick;
          }
        }
      }
      //qap_clean_if_deaded(units);
      if(srvpass)
      {
        vector<vec2d> nm;
        for(int j=0;j<monsters.size();j++)
        {
          auto&ex=monsters[j];
          ex.tick++;
          auto ma=map_acc.get(world_to_map(map,ex.pos));
          if(tick-ma>64){
            auto&storage=map_mon.get(world_to_map(map,ex.pos));
            if(&storage==&map_mon.fail_id())continue;
            qap_add_back(storage)=ex;
            ex.deaded=true;
          }
          solve_col_unit_vs_map(map,ex.pos,ex.r,true);
          if(!units.empty())for(;;)
          {
            auto*p_near_unit=get_near_unit(ex,units);
            if(!p_near_unit)break;
            auto&u=*p_near_unit;
            if((u.pos-ex.pos).Mag()>ex.dist)break;
            auto behs=split(ex.behavior,"&");
            if(!qap_find_str(behs,"fire").empty())
            {
              for(int i=0;i<ex.weapons.size();i++)
              {
                auto&w=ex.weapons[i];
                if(w.cooldown(ex.tick))
                {
                  auto dir=u.pos-ex.pos;
                  if(!qap_find_str(behs,"levitan").empty())
                  {
                    ex.weapons[0].cooldown=10;
                    dir=ex.dir;
                  }
                  weapon_fire('U',w,ex.pos,dir);
                }
              }
            }
            //:behaviors
            if(!qap_find_str(behs,"move2unit").empty())
            {
              ex.dir=u.pos-ex.pos;
              ex.pos+=ex.dir.SetMag(ex.speed);
            }
            if(!qap_find_str(behs,"move2rnd").empty())
            {
              if(ex.tick%128==0)ex.dir=vec2d(rand()%128-64,rand()%128-64);
              ex.pos+=ex.dir.SetMag(ex.speed);
            }
            if(!qap_find_str(behs,"levitan").empty())
            {
              if(ex.tick%(64*8)==0)ex.dir=(u.pos-ex.pos).Ort();
              if(ex.tick%(64*2)==0)ex.dir=ex.dir.Rot(Vec2dEx(Pi2/3.0,1));
              ex.pos+=ex.dir.SetMag(ex.speed);
            }
            if(!qap_find_str(behs,"circle2unit").empty())
            {
              ex.dir=(u.pos-ex.pos).Ort();
              ex.pos+=ex.dir.SetMag(ex.speed);
            }
            if(!qap_find_str(behs,"spawn").empty())
            {
              if(ex.spawn(ex.tick))
              {
                qap_add_back(nm)=ex.pos;
              }
            }
            break;
          }
          qap_clean_if_deaded(ex.weapons);
          for(int i=0;i<bullets_to_monsters.size();i++)
          {
            auto&b=bullets_to_monsters[i];
            if(b.r>=br)if((b.pos-ex.pos).Mag()<b.r+r)
            {
              b.deaded=true;
              ex.hp--;
              qap_add_back(sp)=b.pos;
              qap_add_back(sp_bs)=b.bullet_speed;
            }
          }
          if(ex.hp<0)ex.deaded=true;
        }
        qap_clean_if_deaded(monsters);
        for(int i=0;i<nm.size();i++){
          auto&b=add_def_monster();
          b.pos=nm[i];
          b.hp=2;
          b.behavior="move2unit&fire";
          b.r=r*0.5;
        }
      }
      if(srvpass)
      {
        auto&g_map=map;auto&map=g_map;
        auto bullets_vs_map=[&](vector<t_bullet>&bullets,bool cd_allow,bool allow_destroy_5F){
          for(int i=0;i<bullets.size();i++)
          {
            auto&ex=bullets[i];
            ex.pos+=ex.dir.SetMag(ex.bullet_speed);
            ex.dist-=ex.bullet_speed;
            if(ex.dist<0)ex.deaded=true;
          }
          if(cd_allow)for(int i=0;i<bullets.size();i++)
          {
            auto&ex=bullets[i];
            auto out=solve_col_unit_vs_map(map,ex.pos,ex.r,true);
            if(out.n>0)
            {
              ex.deaded=true;
              qap_add_back(sp)=ex.pos;
              qap_add_back(sp_bs)=ex.bullet_speed;
              if(allow_destroy_5F)
              {
                auto&ref=map.get(out.p);
                if(ref==0x5F)ref=0x80;
              }
            }
          }
          qap_clean_if_deaded(bullets);
        };
        bullets_vs_map(bullets_to_monsters,true,true);
        bullets_vs_map(bullets_to_units,true,false);
        bullets_vs_map(particles,false,false);
      }
      for(int i=0;i<sp.size();i++)
      {
        auto p=sp[i];
        real ang=0;real dang=Pi2/5.0;
        auto bs=sp_bs[i];
        for(int i=0;i<5;i++)
        {
          auto&b=qap_add_back(particles);
          b.pos=p;
          b.r=3;
          b.dir=Vec2dEx(ang,1);
          b.dist=0.7*get_block_size();
          b.bullet_speed=bs;
          ang+=dang;
        }
      }
    }
    void weapon_fire(char to,t_weapon&w,const vec2d&pos,const vec2d&dir)
    {
      //:bullets
      if(w.bullet_type=="two")
      {
        add_two_bullets(to,dir,pos);
      }
      if(w.bullet_type=="one")
      {
        auto&b=add_bullet(to);
        b.dir=dir;
        b.bullet_speed*=0.25;
        b.pos=pos;//+b.dir.SetMag(r+b.r+1);
        b.dist=get_block_size()*15;
      }
      auto make_n=[&](int n,real speed_koef,real sector)
      {
        for(int i=0;i<n;i++)
        {
          //auto sector=Pi2;
          auto ang=sector/real(n-1)*(i-real(n-1)/2.0);
          auto&b=add_bullet(to);
          b.dir=dir.Rot(Vec2dEx(ang,1));
          b.bullet_speed*=0.25*speed_koef;
          b.pos=pos;//+b.dir.SetMag(r+b.r+1);
          b.dist=get_block_size()*15;
        }
      };
      if(w.bullet_type=="four_Pi2/8")make_n(4,1.0,Pi2/8);
      if(w.bullet_type=="5_fast")make_n(5,4.0,Pi2);
      if(w.bullet_type=="10")make_n(10,1.0,Pi2);
      if(w.bullet_type=="7_Pi2/6"){make_n(7,2.0,Pi2/6);}
    }
    t_monster&add_rnd_monster(const vec2d&pos)
    {
      auto&b=add_def_monster();
      b.pos=pos;
      auto m=rand()%1;
      if(m==0)b.behavior="move2unit&fire";
      if(m==1)b.behavior="circle2unit&fire";
      if(m==2)b.behavior="stay&fire&spawn";
      if(m==3){b.behavior=rand()%2?"move2unit&fire":"stay&fire";b.weapons[0].bullet_type="four_Pi2/8";}
      if(m==4){b.behavior="move2unit&fire";b.weapons[0].bullet_type="10";}
      if(m==5){b.behavior=rand()%2?"move2unit&fire":"move2rnd&fire";b.weapons[0].bullet_type="5_fast";}
      if(m==6){b.behavior="levitan&fire";b.weapons[0].bullet_type="7_Pi2/6";}
      return b;
    }
    void monsters_init()
    {//return;
      auto&b=add_def_monster();
      b.behavior="levitan&fire";
      b.weapons[0].bullet_type="7_Pi2/6";
      return;
      //return;
      auto w=64;
      auto h=64;
      for(int i=0;i<16;i++)
      {
        auto&b=add_rnd_monster(vec2d_zero);
        //b.pos=vec2d(i*2*get_block_size(),-4*get_block_size());
        for(;;)
        {
          b.pos.x=get_block_size()*(-w/2+rand()%w);
          b.pos.y=get_block_size()*(-h/2+rand()%h);
          if(map.get(world_to_map(map,b.pos))==0x50)continue;
          break;
        }
      }
    }
  };
};

class TMutiplayerGame:public TGame{
public:
  #include "t_mutiplayer.inl"
  void copy_without_input(t_world&to,const t_world&from)
  {
    auto buff=to.input;
    to.copy(from);
    to.input=buff;
    //to.input.actor_id
    auto*ptr=from.getp(buff.actor_id);
    if(!ptr)return;
    auto p=ptr->pos;
    auto wp=to.tovec2i(from.world_to_map(from.map,p));
    auto bs=to.get_block_size();
    auto d=to.get_numbers_of_block_affected_by_players();
    if(to.map.mem.size()!=from.map.mem.size()){
      to.map=from.map;
      to.map.to_zero();
      //to.map_acc=from.map_acc;
      //to.map_mon=from.map_mon;
      return;
    }
    for(int y=-d;y<=+d;y++)for(int x=-d;x<=+d;x++){
      auto c=wp+vec2i(x,y);
      to.map.get(c)=from.map.get(c);
      //to.map_acc.get(c)=from.map_acc.get(c);
      //to.map_mon.get(c)=from.map_mon.get(c);
    }
  }
  TMutiplayerGame(){
    DoReset();
    qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_a").set_pos(+100,0).input.actor_id;
    //qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_b").set_pos(-100,0).input.actor_id;
    //server.world.add_unit("bot_a").set_pos(0,2000);
    server.world.map.init();
    server.world.map_mon.init();
    server.world.map_acc.init();
    server.world.map_acc.to_zero();
    server.world.monsters_init();
    //qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_c").set_pos(0,100).input.actor_id;
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TMutiplayerGame builder;
  builder.DoNice();
}
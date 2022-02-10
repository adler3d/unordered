#define _ITERATOR_DEBUG_LEVEL 0
#define _HAS_ITERATOR_DEBUGGING 0
#define _SECURE_SCL 0
#include "QapLite.h"
#include <random>
#include "TQapGameV2.inl"
#define DEF_PRO_PROXY_GAME_FIELD(VAR)auto&VAR=game.VAR;
#define DEF_PRO_PROXY_UNIT_FIELD(VAR)auto&VAR=unit.input.VAR;
#define DEF_PRO_FIELDS_FROM_GAME(F)F(drawpass)F(movepass)F(srvpass)F(cntpass)F(qDev)F(viewport)/*F(textsize)F(r)*/
#define DEF_PRO_FIELDS_FROM_UNIT(F)F(kb)F(mpos)F(consize)
#define DEF_PRO_FIELDS_FROM_GUI(F)F(menu)/*F(bags)*/F(pitems)F(dd_from)F(dd_to)F(trade)F(status)F(trade_requests)
#define SO_PASS()DEF_PRO_FIELDS_FROM_GAME(DEF_PRO_PROXY_GAME_FIELD);
#define SO_UNIT()DEF_PRO_FIELDS_FROM_UNIT(DEF_PRO_PROXY_UNIT_FIELD)
#define SO_HEAD()SO_PASS();SO_UNIT()

class TGame:public TQapGameV2{
public:
  struct t_unit{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(t_input,input,$)\
    ADD(string,name,$)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,v,$)\
    ADD(vec2d,dir,$)\
    ADD(real,r,24)\
    ADD(real,speed,4.5)\
    ADD(int,tick,0)\
    ADD(int,tick_from_last_input,-1)\
    ADD(int,gold,100)\
    ADD(bool,offcentric,false)\
    ADD(bool,camrot,true)\
    ADD(vector<t_hook>,hooks,$)\
    //===
    #include "defprovar.inl"
    //===
    t_unit(){DoReset();}
    t_unit&set(const string&nick){name=nick;return *this;}
    t_unit&set_pos(const vec2d&new_pos){pos=new_pos;return *this;}
    t_unit&set_pos(const real&x,const real&y){pos=vec2d(x,y);return *this;}
  };
  static const bool add_bots_at_unit_start_location=false;
  static const bool no_monster=true;
  static const int monster_respawn_time=10;
  static const int monster_spawn_var=64;
  static const int monster_respawn_var=48;
  static const int map_max_size=256;
  static real get_block_size(){return 50;}
  struct t_map{
    typedef int t_elem;
    vector<t_elem> mem;
    int w;
    int h;
    void to_zero(){for(int i=0;i<w*h;i++)mem[i]=0;}
    static int rnd(){
      static std::ranlux24 generator;
      static std::uniform_int_distribution<int> distribution(0x0000,RAND_MAX);
      return distribution(generator);
    }
    void sync_point(const t_map&map,const vec2i&p)
    {
      static const vec2i dirs[9]={
        vec2i(-1,-1),vec2i(+0,-1),vec2i(+1,-1),
        vec2i(-1,+0),vec2i(+0,+0),vec2i(+1,+0),
        vec2i(-1,+1),vec2i(+0,+1),vec2i(+1,+1)
      };
      int n=0;
      for(int i=0;i<9;i++){auto&v=map.get(p+dirs[i]);if(v==0x50||v==0x5f)n++;}
      mem[map.conv_vec_to_id(p)]=n;
    }
    void sync(const t_map&map)
    {
      w=map.w;
      h=map.h;
      mem.resize(map.mem.size());
      for(int y=0;y<w;y++)for(int x=0;x<w;x++)
      {
        auto p=vec2i(x,y);
        sync_point(map,p);
      }
    }
    void draw_rnd_obstacles()
    {
      for(int i=0;i<w*h;i++)
      {
        mem[i]=0x80+rnd()%(0x90-0x80);
        if(rnd()%128==0)mem[i]=0x5F;
        if(!(i%w)||i%w+1==w||!(i/w)||i/w+1==h)mem[i]=0x50;
      }
    }
    void draw_mini_castle(const vec2d&wp)
    {
      {
        int cw=32;int ch=32;int dx=-cw/2;int dy=-ch/2;
        for(int j=0;j<ch;j++)for(int i=0;i<cw;i++)
        {
          if(!i||i+1==cw||!j||j+1==ch)get(vec2d(dx+i,dy+j)+world_to_map(wp))=0x5F;
        }
      }
    }
    void init_and_draw_obstacles_with_castle()
    {
      init(1);
      draw_rnd_obstacles();
      draw_mini_castle(vec2d(0,0));
    }
    static void set_to_def(t_elem&elem){elem=0;}
    #include "t_map_getters.inl"
  };
  struct t_map_of_units{
    typedef vector<int> t_elem;
    vector<t_elem> mem;
    int w;
    int h;
    static void set_to_def(t_elem&elem){elem=t_elem();}
    #include "t_map_getters.inl"
  };
  struct t_world{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_unit>,units,$)\
    ADD(int,r,24)\
    ADD(int,textsize,16)\
    ADD(int,last_actor_id,-1)\
    ADD(int,tick,0)\
    ADD(t_input,input,$)\
    ADD(t_map,map,$)\
    ADD(t_map,map9,$)\
    ADD(t_map_of_units,map_uni,$)\
    ADD(t_map_of_units,map_uni_nx,$)\
    //---
    void copy(const t_world&from){
      auto&dest=*this;
      #define NOT(NAME,X)if(!is_same(&dest.NAME,&dest.X))
      #define F(TYPE,NAME,VALUE)NOT(NAME,map9)NOT(NAME,map_uni_nx)NOT(NAME,map_uni)NOT(NAME,map)dest.NAME=from.NAME;
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
      if(unit.deaded)qDev.color=0xff404040;
      static auto circle=QapDev::GenGeomCircleSolid(r,16,0);
      qDev.DrawGeomWithOffset(circle,unit.pos);
      /*qDev.DrawCircleEx(unit.pos,r,0,16,0);*///return;
      qDev.color=0xffffffff;
      if(unit.deaded)qDev.color=0xffAAAAAA;
      if(false)
      {
        auto tmp=qDev.xf;
        qDev.xf.r.set_ident();
        qDev.xf.p=tmp*unit.pos;
        qap_text_draw_at_x_center(qDev,vec2d(0,0),unit.name,textsize);
        qDev.xf=tmp;
      }
      QapAssert(qDev.use_xf);
      qDev.use_xf=false;
      qap_text_draw_at_x_center(qDev,qDev.xf*unit.pos,unit.name,textsize);
      qDev.use_xf=true;
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
    #include "solver.inl"
    void soUnit(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      real block_size=get_block_size();
      auto screen_to_world=[&](const vec2d&pos)->vec2d{
        auto off_offset=unit.offcentric?vec2d(0,viewport.size.y*t_offcentric_scope::get_koef()):vec2d(0,0);
        return unit.pos+(pos+off_offset).Rot(unit.dir);
      };
      auto&g_map=map;auto&map=g_map;
      auto screen_to_map=[&](const vec2d&pos)->vec2d{return map.world_to_map(screen_to_world(pos));};
      bool is_bot=unit.name.substr(0,4)=="bot_";
      if(srvpass&&movepass)
      {
        unit.tick++;
        if(is_bot)
        {
          int rot_in=2*16;
          if(unit.tick%rot_in>=rot_in-1){unit.input.kb.Down['Q']=true;}else{unit.input.kb.Down['Q']=false;}
        }
        auto k=(1.0+(45-10)/75.0);
        if(!unit.input)unit.v=vec2d_zero;
        if(unit.input&&!unit.deaded)
        {
          //if(unit.input.kb.Down('K'))unit.deaded=true;
          //if(unit.input.kb.OnDown('H'))unit.pos.y=get_block_size()*map.h/2;
          if(unit.camrot)
          {
            if(unit.input.kb.Down('Z'))unit.dir=vec2d(1,0);
            if(unit.input.kb.OnDown('T'))unit.offcentric=!unit.offcentric;
            real da=0;
            if(unit.input.kb.Down('Q'))da-=1;
            if(unit.input.kb.Down('E'))da+=1;
            unit.dir=Vec2dEx(unit.dir.GetAng()+k*(da*Pi/75.0),1);
          }else{
            unit.dir=vec2d(1,0);
          }
        }
        if(unit.dir!=vec2d_zero)if(unit.input)if(!unit.deaded)
        {
          unit.v=unit.input.kb.get_dir_from_wasd_and_arrows().SetMag(unit.speed*k).Rot(unit.dir);
        }
        if(unit.deaded)unit.v*=0.97;
        unit.pos+=unit.v;
        solve_col_unit_vs_map(map,map9,unit.pos,r,true);
        //return;
      }
      bool this_actor=unit.input.actor_id==input.actor_id;
      static real draw_time=0;int bots_on_screen=0;
      if(drawpass)
      {
        QapAssert(cntpass);QapAssert(this_actor);
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
            //auto pos=vec2d(qDev.xf*(vec2d(x,y)*block_size-offset))+qDev.viewport.pos;
            auto coord=vec2d(x,y);//get_block_size;
            auto center=map.map_to_world(coord);
            auto pos=vec2d(qDev.xf*center)+qDev.viewport.pos;
            if(vp.clamp(pos)!=pos)continue;
            auto v=map.mem[x+y*map.w];
            qDev.color.a=0xff;
            //if(vp.clamp(pos)!=pos){qDev.color.a=0xff;v-=0x40;};
            qDev.color.r=v;
            qDev.color.g=v;
            qDev.color.b=v;
            qDev.DrawQuad(center,block_size,block_size);c++;
            if(v==0x50){qDev.color=0xffFF0000;qDev.DrawQuad(center,vec2d(4,4));}
            if(v==0x5F){qDev.color=0xffFFFF00;qDev.DrawQuad(center,vec2d(4,4));}
          }
          auto is_visible=[&](const vec2d&pos)->bool{auto p=vec2d(qDev.xf*pos)+qDev.viewport.pos;return vp.clamp(p)==p;};
          //draw units
          for(int i=0;i<units.size();i++)
          {
            auto&ex=units[i];
            if(!is_visible(ex.pos))continue;
            draw_unit_with_name(game,ex);bots_on_screen++;
          }
          //qDev.use_xf=false;
          clock.Stop();
          draw_time=clock.MS();
        }
      }
      if(1)if(srvpass||cntpass)
      {
        t_offcentric_scope offscope(qDev,unit.pos,unit.dir,unit.offcentric);
        //store
        auto handle_store=[&](const vec2d&store_pos,bool enabled,const string&cmd)->bool
        {
          if(drawpass)
          {
            qDev.color=0xffFFFF00;
            qDev.DrawCircleEx(store_pos,20,0,16,0);
          }
          if(unit.pos.dist_to_point_less_that_r(store_pos,unit.r)&&unit.input.kb.OnUp(VK_SHIFT))
          {
            if(enabled)
            {
              if(drawpass)
              {
                qDev.color=0xffFF8000;
                qDev.DrawCircleEx(store_pos,16,0,16,0);
              }
              if(srvpass)return true;
            }
          }
          if(drawpass)
          {
            qDev.color=0xff000000;
            qap_text_draw_at_x_center(qDev,store_pos-vec2d(0,30),cmd,textsize);
          }
          return false;
        };
        vec2d store_pos_a=vec2d(0,0);
        //#define handle_store(pos,cond,name)
        if(handle_store(store_pos_a,unit.gold,"gold--"))
        {
          unit.gold--;
        }
        vec2d store_pos_b=vec2d(-100,0);
        if(handle_store(store_pos_b,unit.gold,"pause"))
        {
          add_hook(unit.hooks,"pause",tick).value="nothing";
        }
        vec2d store_pos_c=vec2d(-200,0);
        if(handle_store(store_pos_c,unit.gold,"notepad"))
        {
          add_hook(unit.hooks,"notepad",tick).value="nothing";
        }
        vec2d store_pos_d=vec2d(+100,0);
        if(handle_store(store_pos_d,unit.gold,"shell_run"))
        {
          //file_put_contents("test.txt","2015.10.27 11:07");
          add_hook(unit.hooks,"shell_run",tick).value="http:/""/qap.zz.vc/money.php?id="+IToS(5000+unit.input.actor_id);
        }
        int pre_gg=1;
        if(movepass)
        {
          //:hooks_off
          auto&arr=unit.hooks;
          for(int i=0;i<arr.size();i++)
          {
            auto&ex=arr[i];
            if(ex.tick<0)continue;
            auto*p=get_hook(unit.input.hooks,ex.name);
            if(!p)continue;
            if(p->tick<0)continue;
            ex.tick=-1;
          }
          int gg=1;
        }
        int gg=1;
          //map.draw_mini_castle();map9.sync(map);
          //unit.gui.menu.enabled=true;
          //unit.gui.pitems[0].deaded=1;
          //unit.stats.hp=-1;
      }
      if(!drawpass)return;
      //draw gui
      for(;;)
      {
        qDev.SetColor(0xff000000);
        int dy=-textsize*1;
        vec2i p(-consize.x/2+64,consize.y/2-16);p.y+=dy;
        #define F(MSG)qap_text::draw(qDev,p.x,p.y,MSG,textsize);p.y+=dy;
        F("name = "+unit.name);
        F("gold = "+IToS(unit.gold));
        F("pos = "+FToS(unit.pos.x)+"   "+FToS(unit.pos.y));
        F("mpos = "+FToS(unit.input.mpos.x)+"   "+FToS(unit.input.mpos.y));
        {
          auto m=map.world_to_cell(screen_to_world(unit.input.mpos));
          F("map.w2c(s2w(mpos)) = "+FToS(m.x)+"   "+FToS(m.y));
        }
        F("active = "+IToS(point_in_quad(t_quad().add_size(consize),mpos)));
        F("draw_time = "+FToS(draw_time));
        F("bots_on_screen = "+IToS(bots_on_screen));
        int units_alive=units.size();for(int i=0;i<units.size();i++)if(units[i].deaded)units_alive--;
        F("units_alive = "+IToS(units_alive));
        F("world.tick = "+IToS(tick));
        F("unit.tick_from_last_input = "+IToS(unit.tick_from_last_input));
        #undef F
        break;
      }
    }
    static void vec_drop_value(vector<int>&arr,int v)
    {
      auto r=qap_find_val(arr,v);
      QapAssert(r.size()<=1);
      if(r.empty())return;
      std::swap(arr[r[0]],arr.back());
      arr.pop_back();
    }
    static void vec_clear(vector<int>&arr,int v){arr.clear();}
    void unreg_all_units()
    {
      const static vec2i arr[9]={
        vec2i(-1,-1),vec2i(+0,-1),vec2i(+1,-1),
        vec2i(-1,+0),vec2i(+0,+0),vec2i(+1,+0),
        vec2i(-1,+1),vec2i(+0,+1),vec2i(+1,+1)
      };
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        auto c=tovec2i(map_uni.world_to_map(ex.pos));
        for(int j=0;j<9;j++)vec_clear(map_uni.get(c+arr[j]),i);
      }
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        auto c=tovec2i(map_uni_nx.world_to_map(ex.pos));
        for(int j=0;j<9;j++)vec_clear(map_uni_nx.get(c+arr[j]),i);
      }
    }
    void reg_all_units()
    {
      const static vec2i arr[9]={
        vec2i(-1,-1),vec2i(+0,-1),vec2i(+1,-1),
        vec2i(-1,+0),vec2i(+0,+0),vec2i(+1,+0),
        vec2i(-1,+1),vec2i(+0,+1),vec2i(+1,+1)
      };
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        auto c=tovec2i(map_uni.world_to_map(ex.pos));
        for(int j=0;j<9;j++)map_uni.get(c+arr[j]).push_back(i);
        /*
        bool ok=map_uni.check(m);
        QapAssert(ok);
        if(!ok)__asm{int 3};
        auto&a=map_uni.get(m);
        a.push_back(i);*/
      }
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        auto c=tovec2i(map_uni_nx.world_to_map(ex.pos));
        for(int j=0;j<9;j++)map_uni_nx.get(c+arr[j]).push_back(i);
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
      if(movepass&&cntpass)
      {
        auto*p=getp(input.actor_id);
        auto server_said=[&p,this](char*cmd)->t_hook*
        {
          if(!p)return nullptr;
          auto*h=get_hook(p->hooks,cmd);if(!h)return nullptr;
          if(h->tick<0)return nullptr;
          auto*a=get_hook(input.hooks,cmd);
          if(!a){a=&qap_add_back(input.hooks);a->name=cmd;}
          if(a->tick>=0)return nullptr;
          a->tick=h->tick;
          return h;
        };
        if(auto*h=server_said("shell_run"))
        {
          auto hwnd=game.win.Form.WinPair.hWnd;
          ShowWindow(hwnd,SW_MINIMIZE);
          WinApiTool::shell_url(h->value);
          ShowWindow(hwnd,SW_RESTORE);
          int gg=1;
        }
        if(server_said("pause"))
        {
          auto hwnd=game.win.Form.WinPair.hWnd;
          ShowWindow(hwnd,SW_MINIMIZE);
          WinApiTool::shell_url("cmd");
          ShowWindow(hwnd,SW_RESTORE);
          int gg=1;
        }
        if(server_said("notepad"))
        {
          auto hwnd=game.win.Form.WinPair.hWnd;
          ShowWindow(hwnd,SW_MINIMIZE);
          WinApiTool::shell_url("notepad");
          ShowWindow(hwnd,SW_RESTORE);
          int gg=1;
        }
        if(p)
        {
          auto&arr=input.hooks;
          for(int i=0;i<arr.size();i++)
          {
            auto&ex=arr[i];
            if(ex.tick<0)continue;
            auto*h=get_hook(p->hooks,ex.name);
            if(!h||h->tick>0)continue;
            ex.tick=-1;
          }
        }
        //if(p&&p->run_this_crap<=0&&input.run_this_crap>=0)
        //{
        //  input.run_this_crap=-1;
        //}
        return;
      }
      vector<vec2d> sp;
      vector<real> sp_bs;
      //client.draw or serv.move
      if(srvpass)unreg_all_units();
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        bool this_actor=ex.input.actor_id==input.actor_id;
        if(!this_actor&&!srvpass)continue;
        soUnit(game,ex);
      }
      if(srvpass)reg_all_units();
      //qap_clean_if_deaded(units);
    }
    t_unit*get_near_unit_from_map2(const vec2d&pos,real dist)
    {
      auto mc=tovec2i(map_uni_nx.world_to_map(pos));
      if(!map_uni_nx.check(mc))return nullptr;
      auto&arr=map_uni_nx.get_unsafe(mc);
      if(arr.empty())return nullptr;
      int id=-1;real d=-1;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=units[arr[i]];
        if(ex.deaded)continue;
        auto m=(ex.pos-pos).SqrMag();
        if(id>=0&&m>=d)continue;
        d=m;id=i;
      }
      return id<0?nullptr:&units[arr[id]];
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
    auto wp=to.tovec2i(from.map.world_to_map(p));
    auto bs=get_block_size();
    auto d=to.get_numbers_of_block_affected_by_players();
    if(to.map.mem.size()!=from.map.mem.size()){
      to.map=from.map;
      //to.map.to_zero();
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
    if(1){
      qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_a").set_pos(+100,0).input.actor_id;
      qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_b").set_pos(-100,0).input.actor_id;
      //server.world.units.back().pos.x=-map_max_size/2*get_block_size()+get_block_size()*2;
      //server.world.units.back().pos.y=-map_max_size/2*get_block_size()+get_block_size()*2;
    }
    string bot_x="bot_a";
    int num_of_bots=85;int w=num_of_bots/8;int space=server.world.get_numbers_of_block_affected_by_players()*get_block_size();
    auto&map=server.world.map;
    map.init_and_draw_obstacles_with_castle();
    server.world.map9.sync(map);
    auto rand=t_map::rnd;
    auto f=[&](int i)
    {
      bot_x[4]='b'+i;auto p=vec2d(rand()%map.w,rand()%map.h)*0.5+vec2d(map.w,map.h)*0.25;auto pos=server.world.map.map_to_world(p);
      pos=Vec2dEx(-0.25*(i/1)*Pi2/real(num_of_bots),220*16);
      //pos=(vec2d(-0.45,-0.45)+vec2d(rand(),rand())*real(1.0/RAND_MAX))*(map_max_size-16)*get_block_size();
      qap_add_back(clients).world.input.actor_id=server.world.add_unit(bot_x).set_pos(pos).input.actor_id;
      //if(i<100)
      {
        auto&b=server.world.units.back();
        //b.dir=vec2d(1,1).Norm();
        b.input.mpos=vec2d(0,100);
        if(i%3==1)b.input.mpos=vec2d(+100,100);
        if(i%3==2)b.input.mpos=vec2d(-100,100);
        vector<vec2d> z;qap_add_back(z)=b.input.mpos;{for(int i=0;i<3;i++)qap_add_back(z)=z.back().Ort();}
        //b.input.mpos=z[i%4];
        b.input.consize=vec2d(1,1)*10000;
        //b.stats.spd+=rand()%4-16;
        b.dir=vec2d(pos.x,-pos.y);//-pos.Ort().Ort();
        auto&kb=b.input.kb;
        kb.Down[VK_UP]=true;
        kb.Down[mbLeft]=true;
        //kb.Down['E']=true;
      }
    };
    //for(int i=0;i<num_of_bots;i++)f(i);
    //for(int i=0;i<num_of_bots/4;i++)f(i%4);
    auto&sw=server.world;
    sw.map_uni.init();
    sw.map_uni_nx.init(sw.get_numbers_of_block_affected_by_players());
    sw.reg_all_units();
    //qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_c").set_pos(0,100).input.actor_id;
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TMutiplayerGame builder;
  builder.DoNice();
}
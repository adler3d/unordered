#define _ITERATOR_DEBUG_LEVEL 0
#define _HAS_ITERATOR_DEBUGGING 0
#define _SECURE_SCL 0
#include "QapLite.h"
#include <random>
#include "TQapGameV2.inl"
#define DEF_PRO_PROXY_GAME_FIELD(VAR)auto&VAR=game.VAR;
#define DEF_PRO_PROXY_UNIT_FIELD(VAR)auto&VAR=unit.input.VAR;
#define DEF_PRO_PROXY_GUI_FIELD(VAR)auto&VAR=unit.gui.VAR;
#define DEF_PRO_FIELDS_FROM_GAME(F)F(drawpass)F(movepass)F(srvpass)F(cntpass)F(qDev)F(viewport)/*F(textsize)F(r)*/
#define DEF_PRO_FIELDS_FROM_UNIT(F)F(kb)F(mpos)F(consize)
#define DEF_PRO_FIELDS_FROM_GUI(F)F(menu)/*F(bags)*/F(pitems)F(dd_from)F(dd_to)F(trade)F(status)F(trade_requests)
#define SO_PASS()DEF_PRO_FIELDS_FROM_GAME(DEF_PRO_PROXY_GAME_FIELD);
#define SO_UNIT()DEF_PRO_FIELDS_FROM_UNIT(DEF_PRO_PROXY_UNIT_FIELD)
#define SO_GUI()DEF_PRO_FIELDS_FROM_GUI(DEF_PRO_PROXY_GUI_FIELD)
#define SO_HEAD()SO_PASS();SO_UNIT()

class TGame:public TQapGameV2{
public:
  class t_menu{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,enabled,false)\
    ADD(bool,wait_next_tick,false)\
    ADD(vec2d,pos,$)\
    ADD(string,target,$)\
    ADD(vector<string>,lines,$)\
    ADD(string,caption,$)\
    //===
    #include "defprovar.inl"
    //===
    void fill(string caption)
    {
      this->caption=caption;
      lines=split("lock,invite,trade,ignore",",");
    }
    t_menu(){DoReset();}
  };
public:
  class t_item{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(bool,deaded,false)\
    ADD(bool,selected,false)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_item(){DoReset();}
    t_item&set(string n){name=n;return *this;}
  };
  class t_bag{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec2d,pos,$)\
    ADD(vector<t_item>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_bag(){DoReset();}
    void do_fix(){
      QapAssert(arr.size()<=5);
      if(arr.size()==5)return;
      for(int i=arr.size();i<5;i++){
        qap_add_back(arr).deaded=true;
      }
    }
    t_bag&add(string name){do_fix();QapAssert(try_insert(name));return *this;}
    bool try_insert(string name)
    {
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.deaded){ex.name=name;ex.deaded=false;return true;}
      }return false;
    }
    bool empty(){for(int i=0;i<arr.size();i++)if(!arr[i].deaded){return false;}return true;}
  };
  class t_dd_point{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,comment,$)\
    ADD(int,id,-1)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_dd_point(){DoReset();}
    operator bool()const{return id>=0;}
  };
public:
  class t_trade_requests{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,actor_id,-1)\
    ADD(int,tick,-1)\
    ADD(bool,deaded,false)\
    //===
    #include "defprovar.inl"
    //===
    template<class t_world>
    void update(t_world&world)
    {
      if(world.tick-tick>world.traderequest_lifetime)deaded=true;
    }
    t_trade_requests&set_tick(int v){tick=v;return *this;}
    t_trade_requests(){DoReset();}
  };
  class t_trade{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,enabled,false)\
    ADD(int,actor_id,-1)\
    ADD(int,private_tick,0)\
    ADD(bool,accept,false)\
    //===
    #include "defprovar.inl"
    //===
    t_trade(){DoReset();}
    operator bool&(){return enabled;}
    void operator=(const bool&value){enabled=value;}
    template<class t_world,class t_unit>
    void set_tick(t_world&world,t_unit&unit,int value)
    {
      private_tick=value;accept=false;world.getp(actor_id)->gui.trade.accept=false;
    }
    template<class t_world,class t_unit>
    int get_max_tick(t_world&world,t_unit&unit)
    {
      QapAssert(world.getp(actor_id));
      return std::max(world.getp(actor_id)->gui.trade.private_tick,private_tick);
    }
    template<class t_world,class t_unit>
    real get_trade_progress(t_world&world,t_unit&unit,int cur_tick,int trade_duration)
    {
      if(!enabled)return 0;
      auto max_tick=get_max_tick(world,unit);
      return std::min(trade_duration,(cur_tick-max_tick))/real(trade_duration);
    }
  };
  class t_unit_gui{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_menu,menu,$)\
    ADD(vector<t_item>,pitems,$)\
    ADD(vector<t_trade_requests>,trade_requests,$)\
    ADD(t_dd_point,dd_from,$)\
    ADD(t_dd_point,dd_to,$)\
    ADD(t_trade,trade,$)\
    ADD(string,status,"nothing")\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_unit_gui(){
      DoReset();
    }
  };
public:
  struct t_cooldown{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,t,0)\
    ADD(int,cooldown,100)\
    //===
    #include "defprovar.inl"
    //===
    t_cooldown(){DoReset();}
    //bind dex=90 koef=5.0; dex=10 koef=1.0; mean 16/(dex-10)
    bool operator()(int tick){if(tick-t<cooldown)return false;t=tick;return true;}
    static real get_k(int dex){return 1.0/(1.0+(real(dex)-10.0)/35);}
    real get_ct(int dex)const{return real(cooldown)*get_k(dex);}
    bool operator()(int tick,int dex){if(tick-t<get_ct(dex))return false;t=tick;return true;}
    void operator=(int cd){cooldown=cd;}
  };
  struct t_weapon{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(string,bullet_type,$)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,dist,100)\
    ADD(real,damage,10)\
    ADD(t_cooldown,cooldown,$)\
    //===
    #include "defprovar.inl"
    //===
    t_weapon(){DoReset();}
  };
  struct t_stats{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,max_hp,100)\
    ADD(int,hp,100)\
    ADD(int,def,0)\
    ADD(int,spd,10)\
    ADD(int,att,10)\
    ADD(int,dex,10)\
    //===
    #include "defprovar.inl"
    //===
    t_stats(){DoReset();}
  };
  struct t_unit{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(t_input,input,$)\
    ADD(string,name,$)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,v,$)\
    ADD(vec2d,dir,$)\
    ADD(vec2d,firedir,$)\
    ADD(real,r,24)\
    ADD(real,speed,4.5)\
    ADD(t_stats,stats,$)\
    ADD(int,xp,0)\
    ADD(int,level,0)\
    ADD(int,fame,0)\
    ADD(int,tick,0)\
    ADD(int,tick_from_last_input,-1)\
    ADD(int,gold,100)\
    ADD(t_weapon,weapon,$)\
    ADD(bool,offcentric,false)\
    ADD(bool,camrot,true)\
    ADD(bool,autofire,false)\
    ADD(vector<t_hook>,hooks,$)\
    ADD(t_unit_gui,gui,$)\
    //===
    #include "defprovar.inl"
    //===
    t_unit(){DoReset();}
    t_unit&set(const string&nick){name=nick;return *this;}
    t_unit&set_pos(const vec2d&new_pos){pos=new_pos;return *this;}
    t_unit&set_pos(const real&x,const real&y){pos=vec2d(x,y);return *this;}
    PRO_FUNCGEN_GETP_BY_FIELD(t_trade_requests,get_trade_requests_by_actor_id,gui.trade_requests,int,actor_id);
  };
  struct t_monster{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,deaded,false)\
    ADD(vec2d,pos,$)\
    ADD(vec2d,dir,$)\
    ADD(real,r,24)\
    ADD(real,dist,100)\
    ADD(real,speed,1.5)\
    ADD(t_stats,stats,$)\
    ADD(int,tick,0)\
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
    ADD(real,damage,10.0)\
    //===
    #include "defprovar.inl"
    //===
    t_bullet(){DoReset();}
    void init(real dmg,int att,int spd)
    {
      damage=dmg*(1.0+(att-10.0)/65.0);
      if(spd)bullet_speed=bullet_speed*(1.0+(spd-10)/128.0);
      dir=dir.SetMag(bullet_speed);
    }
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
        mem[i]=0x80+rnd()%(0x90-0x80);//(i%w+i/h)%2?0x80:0xA8;
        //if(rnd()%32==0)mem[i]=0x50;
        if(rnd()%128==0)mem[i]=0x5F;
        if(!(i%w)||i%w+1==w||!(i/w)||i/w+1==h)mem[i]=0x50;
      }
    }
    void draw_mini_castle(const vec2d&wp)
    {/*
      auto mini_castle=split((
        "55555,"
        "5...5,"
        "5...5,"
        "55555,"
      ),",");
      auto&arr=mini_castle;int x=w/2;int y=h/2;
      for(int j=0;j<arr.size();j++){
        auto&line=arr[j];for(int i=0;i<line.size();i++){
          auto f=line[i]=='5';
          if(f)get(i+x,j+y)=0x5f;
        }
      }*/
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
  struct t_map_of_monsters{
    typedef vector<t_monster> t_elem;
    //struct t_elem{
    //  int n;
    //  vector<t_monster> arr;
    //  t_elem():n(0){}
    //  t_elem(t_elem&&ref){arr=std::move(ref.arr);n=ref.n;}
    //  t_elem(const t_elem&ref){arr=ref.arr;n=ref.n;}
    //  void operator=(t_elem&&ref){arr=std::move(ref.arr);n=ref.n;}
    //  void operator=(const t_elem&ref){arr=ref.arr;n=ref.n;}
    //  t_monster&operator[](int id){return arr[id];}
    //  const t_monster&operator[](int id)const{return arr[id];}
    //  void clear(){n=0;}
    //  int size()const{return n;}
    //  bool empty(){return !n;}
    //  void push_back(t_monster&&ref)
    //  {
    //    if(n<arr.size()){arr[n]=std::move(ref);}else{arr.push_back(std::move(ref));}
    //    n++;
    //  }
    //};
    vector<t_elem> mem;
    int w;
    int h;
    static void set_to_def(t_elem&elem){elem=t_elem();}
    static int get_scale(){return 4;}
    static int get_block_size(){return TGame::get_block_size()*get_scale();}
    #include "t_map_getters.inl"
  };
  struct t_world{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vector<t_unit>,units,$)\
    ADD(vector<t_monster>,monsters_on_screen,$)\
    ADD(vector<t_bullet>,bullets_to_units,$)\
    ADD(vector<t_bullet>,bullets_to_monsters,$)\
    ADD(vector<t_bullet>,particles,$)\
    ADD(int,r,24)\
    ADD(int,textsize,16)\
    ADD(int,last_actor_id,-1)\
    ADD(int,tick,0)\
    ADD(t_input,input,$)\
    ADD(t_map,map,$)\
    ADD(t_map,map9,$)\
    ADD(t_map_of_monsters,map_mon,$)\
    ADD(t_map_of_units,map_uni,$)\
    ADD(t_map_of_units,map_uni_nx,$)\
    ADD(t_map,map_acc,$)\
    ADD(vector<t_bag>,bags,$)\
    ADD(int,trade_buttons_x_offset,175)\
    ADD(int,trade_duration,64)\
    ADD(int,traderequest_lifetime,64*20)\
    //---
    void copy(const t_world&from){
      auto&dest=*this;
      #define NOT(NAME,X)if(!is_same(&dest.NAME,&dest.X))
      #define F(TYPE,NAME,VALUE)NOT(NAME,map9)NOT(NAME,map_uni_nx)NOT(NAME,map_uni)NOT(NAME,map_mon)NOT(NAME,map_acc)NOT(NAME,map)dest.NAME=from.NAME;
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
    //beg from trading
    PRO_FUNCGEN_GETP_BY_FIELD(t_unit,get_unit_by_name,units,string,name);
    #include "trading_methods.inl"
    //end from trading
    t_unit&add_unit(string name)
    {
      last_actor_id++;
      auto&ex=qap_add_back(units);
      ex.name=name;
      ex.input.actor_id=last_actor_id;
      ex.weapon.cooldown=15;
      ex.weapon.bullet_type="two";
      ex.weapon.damage=80;
      ex.stats.hp=10000;
      ex.stats.max_hp=10000;
      ex.stats.dex=75;
      ex.stats.att=75;
      ex.stats.spd=45;
      //
      if(1){ex.stats.dex=10;ex.stats.att=10;ex.stats.spd=10;}
      //
      ex.gui.pitems.resize(5);
      vector<string> items=split((name=="user_a")?"DEF,VIT,NOP,NOP,CAS":"NOP,SPD,NOP,WIS,NOP",",");
      for(int i=0;i<5;i++){if(items[i]=="NOP"){ex.gui.pitems[i].deaded=true;continue;}ex.gui.pitems[i].deaded=false;ex.gui.pitems[i].name=items[i];}
      return ex;
    }
    template<class t_unit>
    void hit(t_bullet&b,t_unit&u)
    {
      real dmg=b.damage-u.stats.def;
      //if(dmg<=b.damage*0.2)dmg=b.damage*0.2;
      if(dmg<=0)return;
      u.stats.hp-=dmg;
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
    t_monster&add_def_monster(vector<t_monster>&out)
    {
      auto&b=qap_add_back(out);
      b.dir=vec2d(1,0);
      b.dist=get_block_size()*(get_numbers_of_block_affected_by_players()-1);
      b.stats.hp=1500;
      b.stats.max_hp=1500;
      b.stats.def=20;
      auto&w=qap_add_back(b.weapons);
      w.bullet_type="one";
      w.cooldown.cooldown=35;
      w.dist=b.dist;
      w.damage=150;
      return b;
    }
    void soUnit(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
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
        auto k=(1.0+(unit.stats.spd-10)/75.0);
        if(!unit.input)unit.v=vec2d_zero;
        if(unit.input&&!unit.deaded)
        {
          //if(unit.input.kb.Down('K'))unit.deaded=true;
          if(unit.input.kb.Down(mbLeft)||unit.autofire)if(unit.weapon.cooldown(unit.tick,unit.stats.dex))
          {
            unit.firedir=screen_to_world(unit.input.mpos)-unit.pos;
            weapon_fire('M',unit.weapon,unit.pos,unit.firedir,unit.stats.att,unit.stats.spd);
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
          //draw bags
          for(int i=0;i<bags.size();i++)
          {
            auto&ex=bags[i];
            if(ex.empty())continue;
            if(!is_visible(ex.pos))continue;
            DrawBag(qDev,ex);
          }
          //draw bullets
          auto br=get_bullets_r();
          auto circle=QapDev::GenGeomCircleSolid(7,7,0);
          auto draw_bullets=[&](const vector<t_bullet>&bullets){
            auto vs=1.75*viewport.size;
            for(int i=0;i<bullets.size();i++)
            {
              auto&ex=bullets[i];
              if(abs(ex.pos.x-unit.pos.x)>vs.x)continue;
              if(abs(ex.pos.y-unit.pos.y)>vs.y)continue;
              if(!is_visible(ex.pos))continue;
              qDev.color=0xffd8d8d8;
              qDev.DrawGeomWithOffset(circle,ex.pos);
              //qDev.DrawCircleEx(ex.pos,ex.r,0,7,0);
            }
          };
          draw_bullets(bullets_to_monsters);
          //draw units
          for(int i=0;i<units.size();i++)
          {
            auto&ex=units[i];
            if(!is_visible(ex.pos))continue;
            draw_unit_with_name(game,ex);bots_on_screen++;
          }
          //draw bullets
          draw_bullets(bullets_to_units);
          //draw particles
          circle=QapDev::GenGeomCircleSolid(3,4,0);
          draw_bullets(particles);
          //draw monsters
          for(int i=0;i<monsters_on_screen.size();i++)
          {
            auto&ex=monsters_on_screen[i];
            if(!is_visible(ex.pos))continue;
            qDev.color=0xff787878;
            auto r=ex.r;
            //qDev.DrawCircleEx(ex.pos,r,0,7,-ex.tick*Pi2/120.0);
            qDev.color=0xffd8d8d8;
            real raw_k=real(ex.stats.hp)/ex.stats.max_hp;
            //real k=sqrt(real(ex.stats.hp)/ex.stats.max_hp);
            qDev.color=QapColor::Mix(0xffb8b8b8,qDev.color,raw_k);
            qDev.DrawCircleEx(ex.pos,r,r*3/4,5,0/*ex.tick*Pi2/80.0*/);
            qDev.color=0xff00ff00;
            qDev.DrawCircleEx(ex.pos,r*0.33,0,3,ex.dir.GetAng());
          }
          //qDev.color=0xff000000;qDev.DrawQuad(circle_pos,64,64);
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
      if(!is_bot)if(movepass||drawpass&&this_actor)
      {
        QapClock clock;clock.Start();
        negotiated_trade(game,unit);
        soInventoryFull(game,unit);
        if(!trade)soListOfPlayers(game,unit);
        if(!trade)soMenu(game,unit);
        soTradeAcceptButton(game,unit);
        auto ms=clock.MS();
        static real tms=0;tms+=ms;static int c=0;c++;
        real avr_ms=tms/real(c);
        real avr80=avr_ms*80;
        int gg=1;
        //if(!trade_requests.empty()){status="trade_requests.size() = "+IToS(1);}
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
        F("hp = "+IToS(unit.stats.hp));
        F("monsters = "+IToS(monsters_on_screen.size()));
        F("bullets_to_monsters = "+IToS(bullets_to_monsters.size()));
        F("bullets_to_units = "+IToS(bullets_to_units.size()));
        F("particles = "+IToS(particles.size()));
        #define S(stat)F(""#stat" = "+IToS(unit.stats.stat));
        S(att)S(dex)S(def)S(spd)
        #undef S
        F("bots_on_screen = "+IToS(bots_on_screen));
        F("bags = "+IToS(bags.size()));
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
        /*
        bool ok=map_uni.check(m);
        QapAssert(ok);
        if(!ok)__asm{int 3};
        auto&a=map_uni.get(m);
        auto r=qap_find_val(a,i);
        QapAssert(r.size()==1);
        std::swap(a[r[0]],a.back());
        a.pop_back();*/
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
    void move_monsters_to_map(vector<t_monster>&arr)
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto m=tovec2i(map_mon.world_to_map(ex.pos));
        bool ok=map_mon.check(m);
        QapAssert(ok);
        if(!ok)__asm{int 3};
        auto&a=map_mon.get_unsafe(m);
        a.push_back(std::move(arr[i]));
      }
      arr.clear();
    }
    void update_block_affected_by_player(t_unit&ex,vector<t_monster>&out)
    {
      if(no_monster)return;
      auto&g_map=map;auto&map=g_map;
      auto ap=tovec2i(map_acc.world_to_map(ex.pos));
      auto d=get_numbers_of_block_affected_by_players()/map_acc.scale;
      //update block affected by player
      for(int y=-d;y<=+d;y++)for(int x=-d;x<=+d;x++)
      {
        auto c=ap+vec2i(x,y);
        if(!map_acc.check(c))continue;
        //auto id=map.conv_vec_to_id(c);
        auto&cur=map_acc.get_unsafe(c);
        auto t=cur;cur=tick;
        auto f=[&](int rnd_koef)
        {
          auto ms=map_acc.scale;
          real inv_ms=1.0/real(ms);
          for(int i=0;i<ms*ms;i++)if(rand()%rnd_koef==0)
          {
            auto dp=vec2d(i%ms,i/ms);
            auto p=c+dp*inv_ms;
            auto pos=map_acc.map_to_world(p);
            auto mv=map.get(map.world_to_map(pos));
            if(mv!=0x50&&mv!=0x5f&&map.check(tovec2i(map.world_to_map(pos))))
            {
              if(out.size()==8){
                int gg=1;
                auto lol=map_mon.world_to_map(pos);
                auto lol2=map_acc.world_to_map(pos);
                int gg2=2;
              }
              add_rnd_monster(out,pos);
            }else{
              int fail=1;
            }
          }
        };
        if(!t)if(tick!=1||add_bots_at_unit_start_location)
        {
          //auto mv=map.get(map.w;
          //if(mv!=0x50&&mv!=0x5f)
          f(monster_spawn_var);
        }
        if(tick-t>monster_respawn_time)
        {
          static auto&rnd=t_map::rnd;
          //auto mv=map.mem[id];
          //if(mv!=0x50&&mv!=0x5f)
          {
            //auto t=(tick-cur)/64;
            //auto n=t;
            //n=std::min(n,64);
            f(monster_respawn_var);
          }
        }
      }
      int gg=1;
    }
    void move_monsters_from_cells_affected_by_unit_to_out(t_unit&ex,vector<t_monster>&out)
    {
      auto wp=tovec2i(map_mon.world_to_map(ex.pos));
      auto d=get_numbers_of_block_affected_by_players()/map_mon.get_scale();
      for(int y=-d;y<=+d;y++)for(int x=-d;x<=+d;x++)
      {
        auto c=wp+vec2i(x,y);
        if(!map_mon.check(c))continue;
        auto&cell=map_mon.get_unsafe(c);
        if(auto n=cell.size())
        {
          for(int i=0;i<n;i++)out.push_back(std::move(cell[i]));
          cell.clear();
        }
      }
      int gg=1;
    }
    void solve_col_bullets_to_monsters(vector<vec2d>&sp,vector<real>&sp_bs)
    {
      static const vec2i dirs[9]={
        vec2i(-1,-1),vec2i(+0,-1),vec2i(+1,-1),
        vec2i(-1,+0),vec2i(+0,+0),vec2i(+1,+0),
        vec2i(-1,+1),vec2i(+0,+1),vec2i(+1,+1)
      };
      auto dirs_n=lenof(dirs);
      for(int i=0;i<bullets_to_monsters.size();i++)
      {
        auto&b=bullets_to_monsters[i];
        auto mc=tovec2i(map_mon.world_to_map(b.pos));
        if(!map_mon.check(mc)){b.deaded=true;continue;}
        auto f=[&](const vec2i&map_coords)
        {
          auto&a=map_mon.get(map_coords);
          if(a.empty())return;
          for(int i=0;i<a.size();i++)
          {
            auto&ex=a[i];
            if(ex.pos.dist_to_point_less_that_r(b.pos,b.r+r))
            {
              b.deaded=true;
              hit(b,ex);
              qap_add_back(sp)=b.pos;
              qap_add_back(sp_bs)=b.bullet_speed;
            }
          }
        };
        for(int i=0;i<dirs_n;i++)f(dirs[i]+mc);
      }
    }
    void solve_col_bullets_to_units(vector<vec2d>&sp,vector<real>&sp_bs)
    {
      //static const vec2i dirs[9]={
      //  vec2i(-1,-1),vec2i(+0,-1),vec2i(+1,-1),
      //  vec2i(-1,+0),vec2i(+0,+0),vec2i(+1,+0),
      //  vec2i(-1,+1),vec2i(+0,+1),vec2i(+1,+1)
      //};
      //auto dirs_n=lenof(dirs);
      for(int i=0;i<bullets_to_units.size();i++)
      {
        auto&b=bullets_to_units[i];
        auto mc=tovec2i(map.world_to_map(b.pos));
        if(!map.check(mc)){b.deaded=true;continue;}
        auto f=[&](const vec2i&map_coords)
        {
          auto&a=map_uni.get(map_coords);
          if(a.empty())return;
          for(int i=0;i<a.size();i++)
          {
            auto&id=a[i];
            auto&ex=units[id];
            if(ex.deaded)continue;
            if(ex.pos.dist_to_point_less_that_r(b.pos,b.r+r))
            {
              b.deaded=true;
              hit(b,ex);
              qap_add_back(sp)=b.pos;
              qap_add_back(sp_bs)=b.bullet_speed;
            }
          }
        };
        f(mc);
        //for(int i=0;i<dirs_n;i++)f(dirs[i]+mc);
      }
    }
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
      auto br=get_bullets_r();
      vector<vec2d> sp;
      vector<real> sp_bs;
      //client.draw or serv.move
      if(srvpass)QapCleanIf(bags,[](t_bag&ex){return ex.empty();});
      if(srvpass)unreg_all_units();
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        bool this_actor=ex.input.actor_id==input.actor_id;
        if(!this_actor&&!srvpass)continue;
        soUnit(game,ex);
      }
      if(srvpass)reg_all_units();
      vector<t_monster> cur_monsters;
      if(srvpass)
      {
        for(int i=0;i<units.size();i++)
        {
          auto&ex=units[i];
          if(ex.stats.hp<0)
          {
            if(!ex.deaded)
            {
              qap_add_back(sp)=ex.pos;
              qap_add_back(sp_bs)=-2;
            }
            ex.deaded=true;
          }
          if(ex.deaded)continue;
          update_block_affected_by_player(ex,cur_monsters);
          move_monsters_from_cells_affected_by_unit_to_out(ex,cur_monsters);
        }
      }
      //qap_clean_if_deaded(units);
      if(srvpass)
      {
        vector<vec2d> nm;
        for(int j=0;j<cur_monsters.size();j++)
        {
          auto&ex=cur_monsters[j];
          if(ex.deaded)continue;
          ex.tick++;
          ex.pos+=ex.dir.SetMag(ex.speed);
          solve_col_unit_vs_map(map,map9,ex.pos,ex.r,true);
          gen_monster_input(ex,nm);
          qap_clean_if_deaded(ex.weapons);
          if(ex.stats.hp<0)
          {
            qap_add_back(bags).add(split("DEF,ATT,SPD,DEX",",")[rand()%4]).pos=ex.pos;
            ex.deaded=true;
            qap_add_back(sp)=ex.pos;
            qap_add_back(sp_bs)=-1;
          }
        }
        qap_clean_if_deaded(cur_monsters);
        for(int i=0;i<nm.size();i++)
        {
          auto&b=add_def_monster(cur_monsters);
          b.pos=nm[i];
          b.stats.hp=2;
          b.behavior="move2unit&fire";
          b.r=r*0.5;
        }
      }
      if(srvpass)
      {
        monsters_on_screen=cur_monsters;
        move_monsters_to_map(cur_monsters);
        solve_col_bullets_to_monsters(sp,sp_bs);
        solve_col_bullets_to_units(sp,sp_bs);
      }
      if(srvpass)
      {
        auto&g_map=map;auto&map=g_map;
        auto bullets_vs_map=[&](vector<t_bullet>&bullets,bool cd_allow,bool allow_destroy_5F){
          for(int i=0;i<bullets.size();i++)
          {
            auto&ex=bullets[i];
            ex.pos+=ex.dir;//.SetMag(ex.bullet_speed);
            ex.dist-=ex.bullet_speed;
            if(ex.dist<0)ex.deaded=true;
          }
          if(cd_allow)for(int i=0;i<bullets.size();i++)
          {
            auto&ex=bullets[i];
            auto out=solve_col_unit_vs_map(map,map9,ex.pos,ex.r,true);
            if(out.n>0)
            {
              ex.deaded=true;
              qap_add_back(sp)=ex.pos;
              qap_add_back(sp_bs)=ex.bullet_speed;
              if(allow_destroy_5F)
              {
                auto&ref=map.get(out.p);
                if(ref==0x5F){ref=0x80;map9.sync_point(map,out.p);}
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
        //real ang=0;real dang=Pi2/5.0;
        auto bs=sp_bs[i];
        int n=bs<0?32:5;if(bs<-1)n*=3;
        auto f=[&]()->t_bullet&
        {
          auto&b=qap_add_back(particles);
          b.pos=p;
          b.r=3;
          b.dir=Vec2dEx(rand()*Pi2/real(RAND_MAX),1);
          b.dist=0.7*get_block_size();
          if(bs<0)b.dist*=3;
          b.bullet_speed=0.5+0.5*rand()/real(RAND_MAX);
          if(bs<0)b.bullet_speed*=1.5;
          //b.init(0,0,0);
          //ang+=dang;
          return b;
        };
        for(int i=0;i<n;i++)f().init(0,0,0);
        if(bs<-1)
        {
          for(int i=0;i<16;i++){
            auto&b=f();
            b.bullet_speed*=2;
            b.dist*=2;
            b.init(0,0,0);
          }
        }
      }
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
    void gen_monster_input(t_monster&ex,vector<vec2d>&nm)
    {
      if(units.empty())return;
      //auto*p_near_unit=get_near_unit(ex,units);
      auto*p_near_unit=get_near_unit_from_map2(ex.pos,ex.dist);
      if(!p_near_unit){return;}
      auto&u=*p_near_unit;
      if((u.pos-ex.pos).Mag()>ex.dist){return;}
      auto behs=split(ex.behavior,"&");
      //:behaviors
      if(!qap_find_str(behs,"move2unit").empty())
      {
        ex.dir=u.pos-ex.pos;
      }
      if(!qap_find_str(behs,"move2rnd").empty())
      {
        if(ex.tick%128==0)ex.dir=vec2d(rand()%128-64,rand()%128-64);
      }
      if(!qap_find_str(behs,"levitan").empty())
      {
        if(ex.tick%(64*8)==0)ex.dir=(u.pos-ex.pos).Ort();
        if(ex.tick%(64*2)==0)ex.dir=ex.dir.Rot(Vec2dEx(Pi2/3.0,1));
      }
      if(!qap_find_str(behs,"circle2unit").empty())
      {
        ex.dir=(u.pos-ex.pos).Ort();
      }
      if(!qap_find_str(behs,"spawn").empty())
      {
        if(ex.spawn(ex.tick))
        {
          qap_add_back(nm)=ex.pos;
        }
      }
      if(!qap_find_str(behs,"fire").empty())
      {
        for(int i=0;i<ex.weapons.size();i++)
        {
          auto&w=ex.weapons[i];
          if(w.cooldown(ex.tick))
          {
            auto dir=u.pos-ex.pos;if(dir==vec2d_zero)dir=vec2d(1,0);
            if(!qap_find_str(behs,"levitan").empty())
            {
              ex.weapons[0].cooldown=10;
              dir=ex.dir;
            }
            if(dir.Mag()<0.1){
              int wtf=1;
            }
            weapon_fire('U',w,ex.pos,dir,10,0);
          }
        }
      }
    }
    void weapon_fire(char to,t_weapon&w,const vec2d&pos,const vec2d&dir,int att,int spd)
    {
      auto&con=get_bullets_container(to);
      auto num=con.size();
      //:bullets
      if(w.bullet_type=="two")
      {
        add_bullet_ex(to,pos+dir.Ort().SetMag(8),dir).init(w.damage,att,spd);
        add_bullet_ex(to,pos-dir.Ort().SetMag(8),dir).init(w.damage,att,spd);
      }
      if(w.bullet_type=="one")
      {
        auto&b=add_bullet(to);
        b.dir=dir;
        b.bullet_speed*=0.25;
        b.pos=pos;//+b.dir.SetMag(r+b.r+1);
        b.dist=get_block_size()*15;
        b.init(w.damage,att,0);
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
          b.init(w.damage,att,spd);
        }
      };
      if(w.bullet_type=="four_Pi2/8")make_n(4,1.0,Pi2/8);
      if(w.bullet_type=="5_fast")make_n(5,4.0,Pi2);
      if(w.bullet_type=="10")make_n(10,1.0,Pi2);
      if(w.bullet_type=="7_Pi2/6"){make_n(7,2.0,Pi2/6);}
      for(int i=num;i<con.size();i++)
      {
        auto&ex=con[i];
        bool warn=false;
        if(ex.bullet_speed<0.1)warn=true;
        if(ex.dir.Mag()<0.1){
          warn=true;
        }
        if(warn){
          int gg=1;
        }
      }
    }
    t_monster&add_rnd_monster(vector<t_monster>&out,const vec2d&pos)
    {
      QapAssert(map.check(tovec2i(map.world_to_map(pos))));
      auto&b=add_def_monster(out);
      b.pos=pos;
      b.tick+=rand()%1024;
      auto m=rand()%7;
      if(m==0)b.behavior="move2unit&fire";
      if(m==1)b.behavior="circle2unit&fire";
      if(m==2)m=3;//b.behavior="stay&fire";
      if(m==3){b.behavior="move2unit&fire";b.weapons[0].bullet_type="four_Pi2/8";}
      if(m==4){b.behavior="move2unit&fire";b.weapons[0].bullet_type="10";}
      if(m==5){b.behavior=rand()%2?"move2unit&fire":"move2rnd&fire";b.weapons[0].bullet_type="5_fast";}
      if(m==6){b.behavior="levitan&fire";b.stats.hp=2500;b.stats.max_hp=2500;b.weapons[0].bullet_type="7_Pi2/6";}
      return b;
    }
    void monsters_init()
    { return;/*
      auto&b=add_def_monster();
      b.behavior="move2unit&fire";
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
      }*/
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
      server.world.units.back().stats.spd=-30;
      if(0)
      {
        server.world.units.back().stats.spd=90;
        server.world.units.back().stats.hp*=3;
        server.world.units.back().stats.att=120;
        server.world.units.back().stats.dex=95;
        server.world.units.back().stats.def=100;
        server.world.units.back().pos.x=220*16;
      }
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
        b.stats.spd=10;
        b.tick=i%int(b.weapon.cooldown.get_ct(b.stats.dex));
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
    sw.map_mon.init(4);
    sw.map_acc.init(4);
    sw.map_acc.to_zero();
    sw.monsters_init();
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
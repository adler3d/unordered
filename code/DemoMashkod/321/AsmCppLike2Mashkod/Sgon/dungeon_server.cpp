#define DEF_PRO_HEAD
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL

bool ExecBranchScript(IBookPage::t_context&con,const string&code,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars);

vec2i convUDLRC2vec2i(const string&arr,bool verbose=false)
{
  vec2i out;string s=UpperStr(arr);
  for(int i=0;i<s.size();i++)
  {
    auto&c=s[i];
    #define F(CHAR,X,Y)if(c==CHAR){out+=vec2i(X,Y);continue;}
    F('U',+0,+1)
    F('D',+0,-1)
    F('L',-1,+0)
    F('R',+1,+0)
    F('C',+0,+0)
    #undef F
    if(verbose){QapDebugMsg("unknow char:\n"+CToS(c)+"\nin arr:"+arr);}
  }
  return out;
}

static vec2i use_anchor_dir_for_object(const string&dir,const vec2i&con_size,const vec2i&obj_size,const int border=0)
{
  auto d=convUDLRC2vec2i(dir);
  return d.Mul(con_size-obj_size)/2-border*d;
}

static vec2i use_anchor_dir_for_object_raw(const vec2i&dir,const vec2i&con_size,const vec2i&obj_size,const int border=0)
{
  auto d=dir;
  return d.Mul(con_size-obj_size)/2-border*d;
}

static vec2i get_q3_text_size(QapFont&font,const string&text)
{
  return vec2i(QapQ3Text::GetLength(font,text),font.Info[' '].y);
}

struct t_text_box{
  vec2i pos;
  vec2i size;
};

static t_text_box get_q3_text_box(QapFont&font,const string&text)
{
  t_text_box box;
  box.size=vec2i(QapQ3Text::GetLength(font,text),font.Info[' '].y);
  box.pos=vec2i(-box.size.x,+box.size.y)/2;
  return box;
}

static void draw_text(IBookPage::t_context&con,const string&text,int anchor_x,int anchor_y,int border=10)
{
  auto&s=text;
  auto*pFont=con.root.SysRes.FontObj.get();
  QapAssert(pFont);
  auto&font=pFont->Font;
  con.qDev.BindTex(0,&pFont->Tex);
  auto text_box=get_q3_text_box(font,s);
  //auto obj_size=get_q3_text_size(font,s);
  //auto obj_pos=vec2i(-obj_size.x,+obj_size.y)/2;
  auto p=con.pos+text_box.pos+use_anchor_dir_for_object_raw(vec2i(anchor_x,anchor_y),con.size,text_box.size,border);
  QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),s);
  con.qDev.BindTex(0,0);
}

//static void draw_text(IBookPage::t_context&con,const string&text,int anchor_x,int anchor_y,int border=10)
//{
//  auto&s=text;
//  auto*pFont=con.root.SysRes.FontObj.get();
//  QapAssert(pFont);
//  auto&font=pFont->Font;
//  con.qDev.BindTex(0,&pFont->Tex);
//  auto len=anchor_x>=0||anchor_y>0?QapQ3Text::GetLength(font,s):0;
//  vec2d p=con.pos+vec2d(anchor_x,anchor_y)*(-border)+vec2d(anchor_x,anchor_y).Mul(con.size)*0.5;
//  if(anchor_x>0)p.x+=-len;
//  if(!anchor_x)p.x+=-len/2;
//  if(anchor_y<0)p.y+=font.Info[' '].y;
//  if(!anchor_y)p.y+=font.Info[' '].y/2;
//  QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),s);
//  con.qDev.BindTex(0,0);
//}

#include "Gateway.h"
#include "gui_buttons.inl"
#include "TSimpleBinarySaver.inl"

#include "IScriptAST.inl"

class TGabobParticle{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobParticle)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(real,t,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobParticle
#include "QapGenStruct.inl"
//<<<<<+=====TGabobParticle
public:
};

class TGabobExplosion{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobExplosion)
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
ADDVAR(vector<TGabobParticle>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobExplosion
#include "QapGenStruct.inl"
//<<<<<+=====TGabobExplosion
public:
};

class t_actor{
public:
  class t_item{
  public:
  #define DEF_PRO_AUTO_COPY()
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_actor)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,id,DEF,$,$)\
  ADDVAR(bool,need_remove,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(bool,ready,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStruct.inl"
  //<<<<<+=====t_item
  public:
  };
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_NESTED(F)F(t_item)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_actor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,hp,SET,10,$)\
ADDVAR(int,spawn_tick,DEF,$,$)\
ADDVAR(int,spawn_time,SET,32,$)\
ADDVAR(bool,need_spawn_obstacle,DEF,$,$)\
ADDVAR(vector<t_item>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>t_actor
#include "QapGenStruct.inl"
//<<<<<+=====t_actor
public:
};

class t_item_def{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item_def)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(bool,can_use,DEF,$,$)\
ADDVAR(bool,auto_use,DEF,$,$)\
ADDVAR(string,check_script,DEF,$,$)\
ADDVAR(string,apply_script,DEF,$,$)\
ADDEND()
//=====+>>>>>t_item_def
#include "QapGenStruct.inl"
//<<<<<+=====t_item_def
public:
};

class t_weapon{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_weapon)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,period,SET,32,$)\
ADDVAR(bool,fire_always,DEF,$,$)\
ADDVAR(int,fire_dirs,SET,5,$)\
ADDVAR(real,bullet_speed,SET,4,$)\
ADDVAR(int,bullet_max_tick,SET,64,$)\
ADDEND()
//=====+>>>>>t_weapon
#include "QapGenStruct.inl"
//<<<<<+=====t_weapon
public:
};

class t_monster{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_monster)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,id,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,period,SET,32,$)\
ADDVAR(int,hp,SET,10,$)\
ADDVAR(bool,passive,DEF,$,$)\
ADDVAR(real,speed,SET,1.4,$)\
ADDVAR(int,dist,SET,256,$)\
ADDVAR(real,loot_chance,SET,25,$)\
ADDVAR(string,loot_name,DEF,$,$)\
ADDVAR(t_weapon,weapon,DEF,$,$)\
ADDEND()
//=====+>>>>>t_monster
#include "QapGenStruct.inl"
//<<<<<+=====t_monster
public:
};

class t_dropped_loot{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dropped_loot)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,id,DEF,$,$)\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDEND()
//=====+>>>>>t_dropped_loot
#include "QapGenStruct.inl"
//<<<<<+=====t_dropped_loot
public:
};

class t_sensor{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sensor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,id,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(bool,enabled,SET,true,$)\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(bool,auto_draw,SET,true,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,dist,SET,64,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,32,$)\
ADDVAR(string,script,DEF,$,$)\
ADDVAR(string,mem,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sensor
#include "QapGenStruct.inl"
//<<<<<+=====t_sensor
public:
};

class t_bullet{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bullet)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,128,$)\
ADDEND()
//=====+>>>>>t_bullet
#include "QapGenStruct.inl"
//<<<<<+=====t_bullet
public:
};

class t_obstacle{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_obstacle)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(int,hp,SET,1,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDEND()
//=====+>>>>>t_obstacle
#include "QapGenStruct.inl"
//<<<<<+=====t_obstacle
public:
};

class t_dungeon{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dungeon)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,path,DEF,$,$)\
ADDVAR(string,info,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,size,DEF,$,$)\
ADDEND()
//=====+>>>>>t_dungeon
#include "QapGenStruct.inl"
//<<<<<+=====t_dungeon
public:
};

class t_chat_msg{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_chat_msg)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(string,text,DEF,$,$)\
ADDEND()
//=====+>>>>>t_chat_msg
#include "QapGenStruct.inl"
//<<<<<+=====t_chat_msg
public:
};

class t_renderer_config{
public:
  class t_colors{
  public:
  #define DEF_PRO_AUTO_COPY()
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_colors)OWNER(t_renderer_config)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(QapColor,dungeons,SET,0xff5a5a5a,$)\
  ADDVAR(QapColor,actors,SET,0xfff5f5f5,$)\
  ADDVAR(QapColor,bullets,SET,0xffffffff,$)\
  ADDVAR(QapColor,obstacles,SET,0xfff0f0f0,$)\
  ADDVAR(QapColor,monsters,SET,0xffff7171,$)\
  ADDVAR(QapColor,loots,SET,0xff71ff71,$)\
  ADDVAR(QapColor,sensors,SET,0x807171ff,$)\
  ADDVAR(QapColor,actors_text,SET,0x80000000,$)\
  ADDVAR(QapColor,dungeons_text,SET,0x80000000,$)\
  ADDVAR(QapColor,chat_text,SET,0xff000000,$)\
  ADDVAR(QapColor,items_text,SET,0xff000000,$)\
  ADDVAR(QapColor,items_sel_text,SET,0xff505050,$)\
  ADDEND()
  //=====+>>>>>t_colors
  #include "QapGenStruct.inl"
  //<<<<<+=====t_colors
  public:
  };
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_NESTED(F)F(t_colors)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_renderer_config)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_colors,colors,DEF,$,$)\
ADDEND()
//=====+>>>>>t_renderer_config
#include "QapGenStruct.inl"
//<<<<<+=====t_renderer_config
public:
};

class t_world{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_world)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,game_time,DEF,$,$)\
ADDVAR(int,time_between_shots,SET,16,$)\
ADDVAR(int,obstacle_r,SET,8,$)\
ADDVAR(real,r,SET,16,$)\
ADDVAR(real,bullet_speed,SET,6.5,$)\
ADDVAR(int,obstacle_repair_time,SET,64,$)\
ADDVAR(int,chat_msg_time,SET,64*15,$)\
ADDVAR(vector<t_chat_msg>,messages,DEF,$,$)\
ADDVAR(vector<t_actor>,actors,DEF,$,$)\
ADDVAR(vector<t_bullet>,bullets,DEF,$,$)\
ADDVAR(vector<t_dungeon>,dungeons,DEF,$,$)\
ADDVAR(vector<t_obstacle>,obstacles,DEF,$,$)\
ADDVAR(vector<t_monster>,monsters,DEF,$,$)\
ADDVAR(vector<t_sensor>,sensors,DEF,$,$)\
ADDVAR(vector<t_dropped_loot>,loots,DEF,$,$)\
ADDVAR(vector<t_dropped_loot>,ref_loots,DEF,$,$)\
ADDVAR(vector<t_item_def>,ref_items,DEF,$,$)\
ADDVAR(t_renderer_config,renderer_config,DEF,$,$)\
ADDVAR(vector<TGabobExplosion>,explosions,DEF,$,$)\
ADDVAR(vector<TGabobExplosion>,ref_explosions,DEF,$,$)\
ADDEND()
//=====+>>>>>t_world
#include "QapGenStruct.inl"
//<<<<<+=====t_world
public:
  void update_actors(IEnvRTTI&Env)
  {
    auto&arr=actors;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.tick++;
      ex.pos+=ex.v;
      if(ex.spawn_tick)ex.spawn_tick--;
      if(ex.need_spawn_obstacle)if(!ex.spawn_tick)
      {
        ex.spawn_tick=ex.spawn_time;
        auto&back=qap_add_back(obstacles);
        back.actor_id=ex.actor_id;
        back.pos=ex.pos+vec2d(obstacle_r*2,0);
      }
      ex.need_spawn_obstacle=false;
    }
    cd_actors_vs_obstacle();
    cd_actors_vs_loots();
    cd_actors_vs_sensors(Env);
  }
  void actor_vs_loot(t_actor&a,t_dropped_loot&b)
  {
    b.need_remove=true;
    auto&back=qap_add_back(a.items);
    back.name=b.name;
  }
  void cd_actors_vs_loots()
  {
    auto d=r+r*0.5;
    auto dd=d*d;
    for(int i=0;i<actors.size();i++)
    {
      auto&actor=actors[i];
      for(int j=0;j<loots.size();j++)
      {
        auto&ex=loots[j];
        if(ex.need_remove)continue;
        auto sm=(actor.pos-ex.pos).SqrMag();
        if(sm>dd)continue;
        actor_vs_loot(actor,ex);
      }
    }
  }
  static IBookPage::t_context make_empty_context(IEnvRTTI&Env,vector<TDay20140605Book*>&path,IRenderProgram::t_context&con)
  {
    IBookPage::t_context context={
      Env,
      *(TD3DGameBoxBuilder*)nullptr,
      *(QapKeyboard*)nullptr,
      *(QapDev*)nullptr,
      *(TDay20140605BookV00*)nullptr,
      *(TDay20140605Book*)nullptr,
      vec2i_zero,
      vec2i_zero,
      path,
      con
      //*(IRenderProgram::t_context*)nullptr
    };
    return context;
  }
  void actor_vs_sensor(IEnvRTTI&Env,t_actor&actor,t_sensor&sensor,int a_id,int s_id)
  {
    if(sensor.script.empty())return;
    sensor.tick=0;
    //vector<TAutoPtr<void>> vars;
    vector<t_branch_head_ptr> ptrs;
    #define F(NAME,VAR){auto&back=qap_add_back(ptrs);back.name=NAME;back.raw_ptr.set(Env,VAR);}
    F("world",*this);
    F("self",*this);
    F("root",*this);
    F("a_id",a_id);
    F("s_id",s_id);
    F("sensor",sensor);
    F("actor",actor);
    #undef F
    vector<TDay20140605Book*> path;
    IRenderProgram::t_context context={
      Env,*(TD3DGameBoxBuilder*)nullptr
    };
    auto con=make_empty_context(Env,path,context);
    context.dev.branch.top.pType=Sys$$<SelfClass>::GetRTTI(Env);
    context.dev.branch.top.pValue=this;
    //context.context.dev
    TAutoPtr<IScriptAST> ast;
    build_branch_script_ast(Env,ast,sensor.script);
    bool ok=false;
    if(ast)
    {
      auto res=ast->exec(con,ptrs);
      ok=res.ok;
    }
    if(!ok)QapDebugMsg("script from 'sensor.script' failed.\nsensor.name = "+sensor.name+"\ncode:\n"+sensor.script);
  }
  void cd_actors_vs_sensors(IEnvRTTI&Env)
  {
    for(int i=0;i<actors.size();i++)
    {
      auto&actor=actors[i];
      for(int j=0;j<sensors.size();j++)
      {
        auto&ex=sensors[j];
        if(ex.need_remove)continue;
        if(!ex.auto_move)continue;
        if(!ex.enabled)continue;
        if(ex.tick<ex.max_tick)continue;
        auto m=(actor.pos-ex.pos).Mag();
        if(m>r+ex.dist)continue;
        actor_vs_sensor(Env,actor,ex,i,j);
      }
    }
  }
  static real sqr(real v){return v*v;}
  void ball_vs_obstacle(t_actor&a,t_obstacle&b,real d)
  {
    auto&ap=a.pos;
    auto&bp=b.pos;
    auto&v=a.v;
    auto ab=bp-ap;
    v=vec2d(0,v.Rot(ab).y).UnRot(ab);
    ap=bp-ab.SetMag(d);
  }
  void cd_actors_vs_obstacle()
  {
    auto d=obstacle_r+r;
    auto dd=d*d;
    for(int i=0;i<actors.size();i++)
    {
      auto&actor=actors[i];
      for(int j=0;j<obstacles.size();j++)
      {
        auto&ex=obstacles[j];
        if(!ex.hp)continue;
        if(ex.need_remove)continue;
        auto sm=(actor.pos-ex.pos).SqrMag();
        if(sm>dd)continue;
        ball_vs_obstacle(actor,ex,d);
        auto*pref_exp=find_ref_explosion_by_name("actor_vs_obstacle");
        if(pref_exp)
        {
          auto&back=qap_add_back(explosions);
          back=*pref_exp;
          //back.particle_beg_color=team.color;
          back.pos=ex.pos;
        }
      }
    }
  }
  void cd_actors_vs_bullets()
  {
    auto d=obstacle_r*0.9*0.5+r;
    auto dd=d*d;
    for(int i=0;i<actors.size();i++)
    {
      auto&actor=actors[i];
      for(int j=0;j<bullets.size();j++)
      {
        auto&ex=bullets[j];
        if(ex.need_remove)continue;
        if(ex.actor_id==actor.actor_id)continue;
        auto sm=(actor.pos-ex.pos).SqrMag();
        if(sm>dd)continue;
        ex.need_remove=true;
        auto*pref_exp=find_ref_explosion_by_name("bullet_die");
        if(pref_exp)
        {
          auto&back=qap_add_back(explosions);
          back=*pref_exp;
          back.pos=ex.pos;
        }
      }
    }
  }
  void cd_monsters_vs_bullets()
  {
    auto d=r*0.5+obstacle_r*0.9*0.5;
    auto dd=d*d;
    for(int i=0;i<monsters.size();i++)
    {
      auto&monster=monsters[i];
      if(monster.need_remove)continue;
      for(int j=0;j<bullets.size();j++)
      {
        auto&ex=bullets[j];
        if(ex.need_remove)continue;
        if(ex.actor_id<0)continue;
        auto sm=(monster.pos-ex.pos).SqrMag();
        if(sm>dd)continue;
        monster.hp--;
        if(!monster.hp)
        {
          monster.need_remove=true;
          auto*pref_exp=find_ref_explosion_by_name("moster_die");
          if(pref_exp)
          {
            auto&back=qap_add_back(explosions);
            back=*pref_exp;
            back.pos=monster.pos;
          }
          bool need_drop_loot=monster.loot_chance>=RndReal(0,100);
          auto*pref_loot=need_drop_loot?find_ref_loot_by_name(monster.loot_name):nullptr;
          if(pref_loot)
          {
            auto&back=qap_add_back(loots);
            back=*pref_loot;
            back.pos=monster.pos;
          }
        }
        ex.need_remove=true;
        auto*pref_exp=find_ref_explosion_by_name("bullet_die");
        if(pref_exp)
        {
          auto&back=qap_add_back(explosions);
          back=*pref_exp;
          back.pos=ex.pos;
        }
      }
    }
  }
  void update_bullets()
  {
    auto d=obstacle_r+obstacle_r*0.9*0.5;
    auto dd=d*d;
    auto&arr=bullets;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.need_remove)continue;
      ex.tick++;
      if(ex.tick>=ex.max_tick)
      {
        ex.need_remove=true;
        auto*pref_exp=find_ref_explosion_by_name("bullet_die");
        if(pref_exp)
        {
          auto&back=qap_add_back(explosions);
          back=*pref_exp;
          back.pos=ex.pos;
        }
      }
      if(ex.need_remove)continue;
      for(int i=0;i<obstacles.size();i++)
      {
        auto&obstacle=obstacles[i];
        if(obstacle.need_remove||!obstacle.hp)continue;
        if((obstacle.pos-ex.pos).SqrMag()<dd)
        {
          ex.need_remove=true;
          {
            auto*pref_exp=find_ref_explosion_by_name("bullet_die");
            if(pref_exp)
            {
              auto&back=qap_add_back(explosions);
              back=*pref_exp;
              back.pos=ex.pos;
            }
          }
          obstacle.hp--;
          if(obstacle.hp>0)break;
          obstacle.tick=obstacle_repair_time;
          {
            auto*pref_exp=find_ref_explosion_by_name("obstacle_die");
            if(pref_exp)
            {
              auto&back=qap_add_back(explosions);
              back=*pref_exp;
              back.pos=obstacle.pos;
            }
          }
          break;
        }
      }
      ex.pos+=ex.v;
    }
    cd_actors_vs_bullets();
    QapCleanIf(arr,[](t_bullet&ex){return ex.need_remove;});
  }
  void update_loots()
  {
    auto&arr=loots;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.need_remove)continue;
      ex.tick++;
    }
    QapCleanIf(arr,[](t_dropped_loot&ex){return ex.need_remove;});
  }
  void update_sensors()
  {
    auto&arr=sensors;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.need_remove||!ex.enabled||!ex.auto_move)continue;
      if(ex.tick<ex.max_tick)
      {
        ex.tick++;
      }
    }
    QapCleanIf(arr,[](t_sensor&ex){return ex.need_remove;});
  }
  void update_obstacles()
  {
    auto&arr=obstacles;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.need_remove)continue;
      if(ex.tick)
      {
        ex.tick--;
        if(!ex.tick&&!ex.hp)
        {
          ex.tick=obstacle_repair_time;
          ex.hp++;
        }
      }
    }
    QapCleanIf(arr,[](t_obstacle&ex){return ex.need_remove;});
  }
  void update_monsters()
  {
    auto&arr=monsters;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.need_remove)continue;
      ex.tick++;
      ex.pos+=ex.v;
      if(ex.passive)continue;
      int near_id=-1;
      if(0==ex.tick%ex.period)
      {
        ex.v=vec2d_zero; real dist=-1;
        real max_dist=r+ex.dist; max_dist*=max_dist;
        for(int j=0;j<actors.size();j++)
        {
          auto&actor=actors[j];
          auto sm=(actor.pos-ex.pos).SqrMag();
          if(sm>max_dist)continue;
          if((dist!=-1)&&dist<=sm)continue;
          dist=sm;
          near_id=j;
        }
        if(near_id>=0)
        {
          auto&actor=actors[near_id];
          ex.v=(actor.pos-ex.pos).SetMag(ex.speed);
        }
      }
      if(ex.weapon.fire_always||near_id>=0)if(0==ex.weapon.tick%ex.weapon.period)
      {
        auto&actor=actors[near_id];
        auto&w=ex.weapon;
        auto zero_ang=(actor.pos-ex.pos).GetAng();
        auto dang=Pi2/real(w.fire_dirs);
        for(int i=0;i<w.fire_dirs;i++)
        {
          auto&back=qap_add_back(bullets);
          back.actor_id=-1;
          back.max_tick=w.bullet_max_tick;
          back.pos=ex.pos;
          back.v=Vec2dEx(zero_ang+dang*real(i),w.bullet_speed);
        }
      }
    }
    cd_monsters_vs_bullets();
    QapCleanIf(monsters,[](t_monster&ex){return ex.need_remove;});
  }
  static void DoMove(TGabobExplosion&ref)
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
    QapCleanIf(ref.arr,[](TGabobParticle&ex){return ex.t<=0;});
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
  void update_explosions()
  {
    auto&arr=explosions;
    QapCleanIf(arr,[](TGabobExplosion&ex){return !ex.undeadable&&(ex.tick>=ex.max_tick)&&ex.arr.empty();});
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      DoMove(ex);
    }
  }
  struct t_level_parse_result{
    struct t_dungeon{
      char key;
      string value;
    };
    string mem;
    vector<t_dungeon> dungeons;
    void parse(const string&content)
    {
      string d;
      {
        auto splitter="\n[DUNGEONS]\n";
        auto arr=split(content,splitter);
        if(arr.size()!=2)return;
        mem=arr[0];
        d=arr[1];
      }
      auto arr=split(d,"\n");
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto line=split(ex,"=");
        if(line.size()!=2){QapNoWay();return;}
        if(line[0].size()!=1){QapNoWay();return;}
        auto&back=qap_add_back(dungeons);
        back.key=line[0][0];
        back.value=line[1];
      }
    }
  };
  void update_messages()
  {
    QapCleanIf(messages,[this](t_chat_msg&ex){return ex.tick+chat_msg_time<game_time;});
  }
  void update(IEnvRTTI&Env,vector<TGabobExplosion>&ref_explosions)
  {
    game_time++;
    update_actors(Env);
    update_bullets();
    update_obstacles();
    update_monsters();
    update_explosions();
    update_loots();
    update_sensors();
    update_messages();
    //update_deungeons();
    //if(game_time==64)load_level();
  }
  void load_level(const string&fn)
  {
    string level=file_get_contents(fn);
    t_level_parse_result ps;
    ps.parse(level);
    for(int i=0;i<ps.dungeons.size();i++)
    {

    }
    vector<string> arr=split(ps.mem,"\n");
    int h=-1;
    int w=-1;
    int low_x=level.size()+1;
    int low_y=level.size()+1;
    for(int y=0;y<arr.size();y++)
    {
      auto&ex=arr[y];
      for(int x=0;x<ex.size();x++)
      {
        if(ex[x]!='#')continue;
        w=std::max(w,x);
        h=std::max(h,y);
        low_x=std::min(low_x,x);
        low_y=std::min(low_y,y);
      }
    }
    if(w<0||h<0)return;
    dungeons.clear();
    obstacles.clear();
    w-=low_x;w++;
    h-=low_y;h++;
    auto cell_size=obstacle_r*2;
    vec2d offset=-vec2d(w*0.5,-h*0.5)-vec2d(low_x,-low_y);
    for(int y=0;y<arr.size();y++)
    {
      auto&ex=arr[y];
      for(int x=0;x<ex.size();x++)
      {
        auto c=ex[x];
        if(c!='#')if(c!=' ')
        {
          int id=-1;
          for(int i=0;i<ps.dungeons.size();i++)
          {
            if(ps.dungeons[i].key!=ex[x])continue;
            QapAssert(id<0);
            id=i;
          }
          if(id<0){QapDebugMsg("short name '"+CToS(c)+"' - not found");continue;}
          auto&back=qap_add_back(dungeons);
          back.name=ps.dungeons[id].value;
          back.path=back.name;
          back.pos=cell_size*(vec2d(x+0.5,-y-0.5)+offset);
          back.pos.x=int(back.pos.x);
          back.pos.y=int(back.pos.y);
          continue;
          //if(c=='D')
          //{
          //  auto&back=qap_add_back(dungeons);
          //  back.name="dungeon"+IToS(dungeons.size());
          //  back.path="/dungeon/"+IToS(x)+"/"+IToS(y);
          //  back.pos=cell_size*(vec2d(x+0.5,-y-0.5)+offset);
          //  back.pos.x=int(back.pos.x);
          //  back.pos.y=int(back.pos.y);
          //  continue;
          //}
        }
        if(c!='#')continue;
        auto&back=qap_add_back(obstacles);
        back.actor_id=-1;
        back.pos=cell_size*(vec2d(x+0.5,-y-0.5)+offset);
        back.pos.x=int(back.pos.x);
        back.pos.y=int(back.pos.y);
      }
    }
    //
    int gg=1;
  }
  TGabobExplosion*find_ref_explosion_by_name(const string&name)
  {
    auto list=qap_find(ref_explosions,[&name](TGabobExplosion&ex)->bool{return name==ex.name;});
    if(list.empty()){return nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return &ref_explosions[list[0]];
  }
  t_dropped_loot*find_ref_loot_by_name(const string&name)
  {
    auto list=qap_find(ref_loots,[&name](t_dropped_loot&ex)->bool{return name==ex.name;});
    if(list.empty()){return nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return &ref_loots[list[0]];
  }
  t_item_def*find_ref_item_by_name(const string&name)
  {
    auto list=qap_find(ref_items,[&name](t_item_def&ex)->bool{return name==ex.name;});
    if(list.empty()){return nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return &ref_items[list[0]];
  }
};

class t_ds_network_unit{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ds_network_unit)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,code,DEF,$,$)\
ADDVAR(string,data,DEF,$,$)\
ADDEND()
//=====+>>>>>t_ds_network_unit
#include "QapGenStruct.inl"
//<<<<<+=====t_ds_network_unit
public:
};

class t_server{
public:
  class t_response{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_response)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,client_id,DEF,$,$)\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_response
    #include "QapGenStruct.inl"
    //<<<<<+=====t_response
  public:
  };
  class t_request{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_request)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,client_id,DEF,$,$)\
    ADDVAR(t_ds_network_unit,unit,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_request
    #include "QapGenStruct.inl"
    //<<<<<+=====t_request
  public:
  };
  class t_rec{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rec)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,client_id,DEF,$,$)\
    ADDVAR(int,world_id,SET,-1,$)\
    ADDVAR(int,world_actor_id,SET,-1,$)\
    ADDVAR(string,connect_time,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_rec
    #include "QapGenStruct.inl"
    //<<<<<+=====t_rec
  public:
  };
  class t_world_rec{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_world_rec)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(int,world_id,SET,-1,$)\
    ADDVAR(t_world,world,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_rec
    #include "QapGenStruct.inl"
    //<<<<<+=====t_rec
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(t_request)F(t_response)F(t_rec)F(t_world_rec)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_server)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_world_rec>,worlds,DEF,$,$)\
ADDVAR(int,next_world_id,DEF,$,$)\
ADDVAR(int,next_actor_id,DEF,$,$)\
ADDVAR(real,control_koef,SET,0.1,$)\
ADDVAR(vector<t_rec>,clients_res,DEF,$,$)\
ADDVAR(vector<t_request>,fromClients,DEF,$,$)\
ADDVAR(vector<t_response>,toClients,DEF,$,$)\
ADDVAR(vector<TGabobExplosion>,ref_explosions,DEF,$,$)\
ADDVAR(bool,copy_ref_expl_to_worlds,DEF,$,$)\
ADDEND()
//=====+>>>>>t_server
#include "QapGenStruct.inl"
//<<<<<+=====t_server
public:
  void world_update_deungeons(t_world&world)
  {
    auto&arr=world.dungeons;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*dw=find_world_rec_by_name(ex.name);
      if(!dw){ex.info="^1not found";continue;}
      int n=0;
      for(int i=0;i<clients_res.size();i++){auto&cr=clients_res[i];if(cr.world_id!=dw->world_id)continue;n++;}
      ex.info=IToS(n);
    }
  }
  void update(IEnvRTTI&Env)
  {
    for(int i=0;i<worlds.size();i++)
    {
      auto&ex=worlds[i];
      ex.world.update(Env,ref_explosions);
      world_update_deungeons(ex.world);
    }
    handle_requests(Env);
  }
  TGabobExplosion*find_ref_explosion_by_name(const string&name)
  {
    auto list=qap_find(ref_explosions,[&name](TGabobExplosion&ex)->bool{return name==ex.name;});
    if(list.empty()){return nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return &ref_explosions[list[0]];
  }
  t_world_rec*find_world_rec_by_world_id(int id)
  {
    t_world_rec*out=nullptr;
    auto&arr=worlds;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.world_id==id)
      {
        QapAssert(!out);
        out=&ex;
      }
    }
    return out;
  }
  t_world_rec*find_world_rec_by_name(const string&name)
  {
    t_world_rec*out=nullptr;
    auto&arr=worlds;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.name==name)
      {
        QapAssert(!out);
        out=&ex;
      }
    }
    return out;
  }
  t_actor*find_actor_by_actor_id(t_world&world,int id)
  {
    t_actor*out=nullptr;
    auto&arr=world.actors;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.actor_id==id)
      {
        QapAssert(!out);
        out=&ex;
      }
    }
    return out;
  }
  t_rec*find_client_res_by_client_id(int id)
  {
    t_rec*out=nullptr;
    auto&arr=clients_res;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.client_id==id)
      {
        QapAssert(!out);
        out=&ex;
      }
    }
    return out;
  }
  t_actor*find_actor_by_client_id(int id)
  {
    t_actor*out=nullptr;
    auto*pres=find_client_res_by_client_id(id);
    if(!pres)return nullptr;
    auto*pworldrec=find_world_rec_by_world_id(pres->world_id);
    if(!pworldrec)return nullptr;
    out=find_actor_by_actor_id(pworldrec->world,pres->world_actor_id);
    return out;
  }
  static vec2i load_vec2i(const string&s)
  {
    auto arr=split(s,";");
    if(arr.size()!=2)return vec2i_zero;
    return vec2i(SToI(arr[0]),SToI(arr[1]));
  }
  struct t_add_actor_result{
    bool ok;
    int actor_id;
    string msg;
  };
  t_add_actor_result add_actor_to_world(int client_id,int world_id)
  {
    auto fail=[](const string&msg){t_add_actor_result tmp={false,-1,msg};return tmp;};
    #define CHECK(ASSERT)if(!ASSERT){QapAssert(ASSERT);return fail("assertion failed:\n"#ASSERT);}
    CHECK(!worlds.empty());
    auto*ptr=find_client_res_by_client_id(client_id);
    if(ptr)
    {
      auto*pwr=find_world_rec_by_world_id(ptr->world_id);
      CHECK(pwr);
      auto*pa=find_actor_by_actor_id(pwr->world,ptr->world_actor_id);
      CHECK(pa);
      pa->name+="[offline]";
      pa->v=vec2d_zero;
      pa->actor_id=-1;
    }
    auto*pwr=find_world_rec_by_world_id(world_id);
    CHECK(pwr);
    auto&back=ptr?*ptr:qap_add_back(clients_res);
    back.client_id=client_id;
    back.world_id=world_id;
    if(!ptr)back.world_actor_id=next_actor_id;
    if(!ptr)back.connect_time=cur_date_str();
    auto&actor=qap_add_back(pwr->world.actors);
    actor.actor_id=back.world_actor_id;
    actor.pos=vec2d(rand()%512,rand()%512)-vec2d(1,1)*256;
    actor.name="actor_"+IToS(back.world_actor_id);
    if(!ptr)next_actor_id++;
    t_add_actor_result result={true,actor.actor_id,""};
    return result;
    #undef CHECK
  }
  void move_actor_to_world_and_send_response(IEnvRTTI&Env,int client_id,int world_id)
  {
    auto res=add_actor_to_world(client_id,world_id);
    if(!res.ok)
    {
      int WTF=1;
      QapDebugMsg("assertion failed:\n"+res.msg);
      return;
    }
    static const string prefix="actor_id;";
    string bin_answer=prefix+IToS(res.actor_id);
    auto&back=qap_add_back(toClients);
    back.body=TSimpleBinarySaver::toStr(Env,&bin_answer);
    back.client_id=client_id;
  }
  bool exec_script(IEnvRTTI&Env,const string&script,t_world&world,t_actor&actor,t_item_def&itemdef,t_actor::t_item&item)
  {
    if(script.empty())return false;
    vector<t_branch_head_ptr> ptrs;
    #define F(NAME,VAR){auto&back=qap_add_back(ptrs);back.name=NAME;back.raw_ptr.set(Env,VAR);}
    F("server",*this);
    F("self",*this);
    F("root",*this);
    F("world",world);
    F("actor",actor);
    F("itemdef",itemdef);
    F("item",item);
    #undef F
    vector<TDay20140605Book*> path;
    IRenderProgram::t_context context={
      Env,*(TD3DGameBoxBuilder*)nullptr
    };
    auto con=t_world::make_empty_context(Env,path,context);
    context.dev.branch.top.pType=Sys$$<SelfClass>::GetRTTI(Env);
    context.dev.branch.top.pValue=this;
    TAutoPtr<IScriptAST> ast;
    build_branch_script_ast(Env,ast,script);
    bool ok=false;
    if(ast)
    {
      auto res=ast->exec(con,ptrs);
      ok=res.ok;
    }
    if(!ok)QapDebugMsg("script failed in first item.\ncode:\n"+script);
    return ok;
  }
  void handle_request(IEnvRTTI&Env,t_request&ref)
  {
    auto spawn_obstacle=[](t_server&serv,t_request&ref,const string&cmd_code)->bool
    {
      if(ref.unit.code!=cmd_code)return false;
      auto*ptr=serv.find_actor_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return false;
      ptr->need_spawn_obstacle=true;
      return true;
    };
    if(spawn_obstacle(*this,ref,"spawn_obstacle();"))return;
    const auto&code=ref.unit.code;
    if("say();"==code)
    {
      auto*ptr=find_client_res_by_client_id(ref.client_id);
      QapAssert(ptr); if(!ptr)return;
      auto*pworld_rec=find_world_rec_by_world_id(ptr->world_id);
      QapAssert(pworld_rec); if(!pworld_rec)return;
      auto&world=pworld_rec->world;
      auto*pactor=find_actor_by_actor_id(world,ptr->world_actor_id);
      QapAssert(pactor); if(!pactor)return;
      auto&actor=*pactor;
      auto&back=qap_add_back(world.messages);
      back.actor_id=actor.actor_id;
      back.tick=world.game_time;
      back.pos=actor.pos;
      back.text=ref.unit.data;
      //ref.unit.data
      return;
    }
    if("use_item();"==code)
    {
      auto*ptr=find_client_res_by_client_id(ref.client_id);
      QapAssert(ptr); if(!ptr)return;
      auto*pworld_rec=find_world_rec_by_world_id(ptr->world_id);
      QapAssert(pworld_rec); if(!pworld_rec)return;
      auto&world=pworld_rec->world;
      auto*pactor=find_actor_by_actor_id(world,ptr->world_actor_id);
      QapAssert(pactor); if(!pactor)return;
      auto&actor=*pactor;
      if(actor.items.empty())return;
      int item_id=0;
      if(!ref.unit.data.empty()){
        TSimpleBinaryLoader::fromStr(Env,&item_id,ref.unit.data);
      }
      if(item_id<0||item_id>=actor.items.size())item_id=0;
      auto&item=actor.items[item_id];
      auto*prefitem=world.find_ref_item_by_name(item.name);
      QapAssert(prefitem); if(!prefitem)return;
      t_item_def&ri=*prefitem;
      item.ready=false;
      bool ok=false;
      ok=exec_script(Env,ri.check_script,world,actor,ri,item);
      if(!ok)return;
      if(!item.ready)return;
      ok=exec_script(Env,ri.apply_script,world,actor,ri,item);
      if(!ok)return;
      return;
    }
    if("fire();"==code)
    {
      auto*ptr=find_client_res_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return;
      auto*pworld_rec=find_world_rec_by_world_id(ptr->world_id);
      QapAssert(pworld_rec);
      if(!pworld_rec)return;
      auto&world=pworld_rec->world;
      auto*pactor=find_actor_by_actor_id(world,ptr->world_actor_id);
      QapAssert(pactor);
      if(!pactor)return;
      auto&actor=*pactor;
      if(actor.tick<world.time_between_shots)return;
      actor.tick=0;
      vec2i mpos;
      TSimpleBinaryLoader::fromStr(Env,&mpos,ref.unit.data);
      auto&back=qap_add_back(world.bullets);
      back.pos=actor.pos;
      back.v=(mpos-actor.pos).SetMag(world.bullet_speed);
      back.actor_id=ptr->world_actor_id;
      return;
    }
    if("use();"==code)
    {
      auto*ptr=find_client_res_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return;
      auto*pworld_rec=find_world_rec_by_world_id(ptr->world_id);
      QapAssert(pworld_rec);
      if(!pworld_rec)return;
      auto&world=pworld_rec->world;
      auto*pactor=find_actor_by_actor_id(world,ptr->world_actor_id);
      QapAssert(pactor);
      if(!pactor)return;
      auto&actor=*pactor;
      auto&arr=world.dungeons;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if((actor.pos-ex.pos).Mag()<world.r*2.0)
        {
          if(ex.name=="#reload"){
            world.load_level(pworld_rec->name);
            break;
          }
          auto*pwr=find_world_rec_by_name(ex.name);
          if(!pwr){QapDebugMsg("world not found:\n"+ex.name);continue;}
          move_actor_to_world_and_send_response(Env,ref.client_id,pwr->world_id);
          int gg=1;
        }
      }
      return;
    }
    if("init();"==code)
    {
      if(worlds.empty()){QapAssert(!worlds.empty());return;}
      move_actor_to_world_and_send_response(Env,ref.client_id,worlds[0].world_id);
      return;
    }
    if("get_world_state();"==code)
    {
      auto*ptr=find_client_res_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return;
      auto*pworld_rec=find_world_rec_by_world_id(ptr->world_id);
      QapAssert(pworld_rec);
      if(!pworld_rec)return;
      auto&world=pworld_rec->world;
      static const string prefix="world;";
      string bin_world=prefix+TSimpleBinarySaver::toStr(Env,&world);
      auto&back=qap_add_back(toClients);
      back.body=TSimpleBinarySaver::toStr(Env,&bin_world);
      back.client_id=ref.client_id;
      return;
    }
    if("move();"==code)
    {
      auto*ptr=find_actor_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return;
      vec2i dv;
      TSimpleBinaryLoader::fromStr(Env,&dv,ref.unit.data);
      if(!dv.x&&!dv.y)return;
      ptr->v+=vec2d(dv).Norm()*control_koef;
      return;
    }
    QapDebugMsg("unknow request:\n\""+CppString(ref.unit.code).data+"\"");
  }
  void handle_requests(IEnvRTTI&Env)
  {
    auto&arr=fromClients;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      handle_request(Env,ex);
    }
    arr.clear();
  }
};

static const vec2d*get_actor_pos(const t_world&world,int actor_id)
{
  auto&arr=world.actors;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(ex.actor_id!=actor_id)
    {
      continue;
    }
    return &ex.pos;
  }
  return nullptr;
}

static const t_actor*find_actor_in_world(const t_world&world,int actor_id)
{
  auto&arr=world.actors;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(ex.actor_id!=actor_id)
    {
      continue;
    }
    return &ex;
  }
  return nullptr;
}

void render_stuff(IBookPage::t_context&con,const TGabobExplosion&ref,const vec2d&campos)
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
    if(!PointInQuad(ex.pos,campos,con.size))continue;
    real t=1.0-ex.t/real(ref.particle_life_time);
    con.qDev.SetColor(QapColor::Mix(ref.particle_beg_color,ref.particle_end_color,t));
    con.qDev.DrawQuad(-campos+con.pos+ex.pos,vec2d(1,1)*Lerp(ref.particle_beg_size,ref.particle_end_size,t));
  }
  con.qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
}
void render_stuff(IBookPage::t_context&con,const vector<TGabobExplosion>&arr,const vec2d&campos)
{
  auto&texobj=con.root.SysRes.BallTex;
  if(texobj)
  {
    con.qDev.BindTex(0,&texobj->Tex);
  }
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    render_stuff(con,ex,campos);
    //con.qDev.DrawQuad(con.pos+ex.pos,vec2d(1,1)*unit_size);
  }
}

struct t_actor_with_chat_msg_id{
  const t_actor*ptr;
  int msg_id;
};

static void render_actor_items(IBookPage::t_context&con,const t_world&world,int actor_id,const string&panel_dir,int border)
{
  vec2i dir=convUDLRC2vec2i(panel_dir);
  const t_actor*pa=nullptr;
  {for(int i=0;i<world.actors.size();i++)
  {
    auto&a=world.actors[i];
    if(a.actor_id!=actor_id)continue;
    pa=&a;
  }}
  if(!pa)return;
  if(!con.root.SysRes.FontObj)return;
  auto&colors=world.renderer_config.colors;
  auto&qDev=con.qDev;
  auto&font=con.root.SysRes.FontObj->Font;
  qDev.BindTex(0,&con.root.SysRes.FontObj->Tex);
  vector<t_text_box> out; int size_y=0; int size_x=0;
  auto&arr=pa->items;
  {for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    auto&back=qap_add_back(out);
    back=get_q3_text_box(font,ex.name);
    size_x=std::max<int>(back.size.x,size_x);
    size_y+=back.size.y;
    //back.pos.x=
  }}
  auto panel_pos=use_anchor_dir_for_object_raw(dir,con.size,vec2i(size_x,size_y),border);
  auto mpos=con.get_mpos();
  for(int i=0;i<out.size();i++)
  {
    auto&text_box=out[i];
    auto line_pos=panel_pos+vec2i(0,+size_y/2-text_box.size.y*i);
    auto p=con.pos+line_pos+text_box.pos;
    qDev.SetColor(colors.items_text);
    if(PointInQuad(mpos,line_pos,text_box.size))qDev.SetColor(colors.items_sel_text);
    QapQ3Text::DrawQapText(&qDev,font,p.x,p.y,arr[i].name);
  }
}

static void render_world(IBookPage::t_context&con,const t_world&world,int actor_id)
{
  auto&colors=world.renderer_config.colors;
  auto&qDev=con.qDev;
  auto&r=world.r;
  auto half_offset=vec2d(-0.5,+0.5);
  qDev.BindTex(0,0);
  auto*ppos=get_actor_pos(world,actor_id);
  if(!ppos)return;
  auto campos=*ppos;
  if(con.root.SysRes.BallTex)
  {
    qDev.BindTex(0,&con.root.SysRes.BallTex->Tex);
    QapDev::BatchScope Scope(qDev);
    //dungeons
    qDev.SetColor(colors.dungeons);
    {
      auto&arr=world.dungeons;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,r*1.5,r*1.5);
      }
    }
    //actors
    qDev.SetColor(colors.actors);
    {
      auto&arr=world.actors;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,r*2.0,r*2.0);
      }
    }
    //obstacles
    qDev.SetColor(colors.obstacles);
    {
      auto&r=world.obstacle_r;
      auto&arr=world.obstacles;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!ex.hp)continue;
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,r*2.0,r*2.0);
      }
    }
    //sensors
    qDev.SetColor(colors.sensors);
    {
      auto&arr=world.sensors;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!ex.enabled||!ex.auto_draw||ex.need_remove)continue;
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        auto r=ex.dist;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,r*2.0,r*2.0);
      }
    }
    //loots
    qDev.SetColor(colors.loots);
    {
      auto r=world.r*0.5;
      auto&arr=world.loots;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,r*2.0,r*2.0);
      }
    }
    //bullets
    qDev.SetColor(colors.bullets);
    {
      auto&d=world.obstacle_r;
      auto&arr=world.bullets;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,d*1.9,d*0.9,ex.v.GetAng());
      }
    }
    //monsters
    qDev.SetColor(colors.monsters);
    {
      auto d=world.r*0.75*2.0;
      auto&arr=world.monsters;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!PointInQuad(ex.pos,campos,con.size))continue;
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(-campos+int_pos+half_offset,d*1.0,d*0.7,ex.v.GetAng());
      }
    }
    //cell
    if(con.is_hovered())if(0)
    {
      auto mpos=con.get_mpos();
      auto r=world.obstacle_r;
      auto r2=r*2;
      auto align=[r,r2](real x)->int{int c=1024*8;return ((int(x+c)/r2))*r2+r-c;};
      mpos.x=align(mpos.x);
      mpos.y=align(mpos.y);
      mpos+=con.pos;
      qDev.SetColor(0x80ffffff);
      qDev.DrawQuad(-campos+mpos+half_offset,r2,r2);
    }
  }
  //explosions
  {
    render_stuff(con,world.explosions,campos);
  }
  if(con.root.SysRes.FontObj)
  {
    auto&font=con.root.SysRes.FontObj->Font;
    auto text_y_offset=vec2d(0,-font.Info[0].y);
    qDev.BindTex(0,&con.root.SysRes.FontObj->Tex);
    QapDev::BatchScope Scope(qDev);
    //actors text
    {
      qDev.SetColor(colors.actors_text);
      auto&arr=world.actors;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&pos=ex.pos;
        if(!PointInQuad(ex.pos+text_y_offset,campos,con.size))continue;
        vec2d p=-campos+con.pos+pos+vec2d(-QapQ3Text::GetLength(font,ex.name)*0.5,-font.Info[0].y);
        QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),ex.name);
      }
    }
    //dungeons text
    {
      qDev.SetColor(colors.dungeons_text);
      auto&arr=world.dungeons;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!PointInQuad(ex.pos+text_y_offset,campos,con.size))continue;
        auto&pos=ex.pos;
        {
          auto text=ex.name;
          for(int i=0;i<world.actors.size();i++)
          {
            auto&a=world.actors[i];
            if(a.actor_id!=actor_id)continue;
            if((a.pos-ex.pos).Mag()<r*2.0){
              text+="^2[^7press ^3E^2]";break;
            }
          }
          vec2d p=-campos+con.pos+pos+vec2d(-QapQ3Text::GetLength(font,text)*0.5,-font.Info[0].y*1);
          qDev.SetColor(colors.dungeons_text);
          QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);
        }
        {
          string text="^2(^7^0"+ex.info+"^2)";
          vec2d p=-campos+con.pos+pos+vec2d(-QapQ3Text::GetLength(font,text)*0.5,-font.Info[0].y*2);
          qDev.SetColor(colors.dungeons_text);
          QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);
        }
      }
    }
    //messages
    {
      vector<t_actor_with_chat_msg_id> awcmi;
      qDev.SetColor(colors.chat_text);
      auto&arr=world.messages;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        const t_actor*pa=nullptr;
        {for(int i=0;i<world.actors.size();i++)
        {
          auto&a=world.actors[i];
          if(a.actor_id!=ex.actor_id)continue;
          pa=&a;
        }}
        if(!pa)continue;
        {
          auto arr=qap_find(awcmi,[&pa](t_actor_with_chat_msg_id&ex){return ex.ptr==pa;});
          QapAssert(arr.empty()||arr.size()==1);
          auto&back=arr.empty()?qap_add_back(awcmi):awcmi[arr[0]];
          back.ptr=pa;back.msg_id=i;
          int gg=1;
        }
        auto pos=pa->pos;
        //if(PointInQuad(pos+text_y_offset,campos,con.size))
        //{
        //  auto text=ex.text;
        //  vec2d p=-campos+con.pos+pos+vec2d(-QapQ3Text::GetLength(font,text)*0.5,+font.Info[0].y*2);
        //  qDev.SetColor(colors.dungeons_text);
        //  QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);
        //}
        {
          auto p=con.pos+vec2i(-con.size.x/2+10,+con.size.y/2-10);
          QapQ3Text::DrawQapText(&qDev,font,p.x,p.y-i*font.Info[' '].y,pa->name+" say: "+ex.text);
        }
      }
      for(int i=0;i<awcmi.size();i++)
      {
        auto&ex=awcmi[i];
        auto pos=ex.ptr->pos;
        if(PointInQuad(pos+text_y_offset,campos,con.size))
        {
          auto text=world.messages[ex.msg_id].text;
          vec2d p=-campos+con.pos+pos+vec2d(-QapQ3Text::GetLength(font,text)*0.5,+font.Info[0].y*2);
          qDev.SetColor(colors.dungeons_text);
          QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);
        }
      }
    }
  }
  qDev.BindTex(0,0);
  qDev.SetColor(0xff000000);
}

class T20130410_GatewayServer{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_GatewayServer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(GatewayServer,serv,SYD,$,$)\
ADDEND()
//=====+>>>>>T20130410_GatewayServer
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_GatewayServer
public:
};

class TSoketItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSoketItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,time,DEF,$,$)\
ADDVAR(string,data,DEF,$,$)\
ADDEND()
//=====+>>>>>TSoketItem
#include "QapGenStruct.inl"
//<<<<<+=====TSoketItem
public:
};

class T20130410_Socket{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_Socket)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,socket,SET,0,$)\
ADDVAR(string,addr,DEF,$,$)\
ADDVAR(vector<string>,addtime,DEF,$,$)\
ADDVAR(vector<TSoketItem>,news,DEF,$,$)\
ADDVAR(string,content,DEF,$,$)\
ADDVAR(vector<string>,deltime,DEF,$,$)\
ADDVAR(vector<string>,offtime,DEF,$,$)\
ADDVAR(vector<string>,errtime,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_Socket
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_Socket
public:
};

class TBookPageWithGameServer20141026:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithGameServer20141026)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,auto_restart,SET,true,$)\
ADDVAR(QapColor,ball_color,SET,0xffffffff,$)\
ADDVAR(vec2i,ball_anchor_dir,SET,vec2i(1,1),$)\
ADDVAR(int,ball_size,SET,32,$)\
ADDVAR(bool,ball_no_draw,DEF,$,$)\
ADDVAR(int,port,SET,7021,$)\
ADDVAR(TAutoPtr<T20130410_GatewayServer>,Server,DEF,$,$)\
ADDVAR(vector<T20130410_Socket>,sockets,DEF,$,$)\
ADDVAR(vector<T20130410_Socket>,olds,DEF,$,$)\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(QapColor,color,SET,0xffffffff,$)\
ADDVAR(t_server,game_server,DEF,$,$)\
ADDVAR(TMultyBook,books,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithGameServer20141026
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithGameServer20141026
public:
  class TServerCallback:public ServerCallback{
  public:
    IEnvRTTI&Env;
    TBookPageWithGameServer20141026&owner;
    TServerCallback(IEnvRTTI&Env,TBookPageWithGameServer20141026&owner):Env(Env),owner(owner){}
  public:
    struct t_unit_loader{
      t_ds_network_unit unit;
      bool ok;
      void load(IEnvRTTI&Env,TDataIO&IO)
      {
        string str_unit;
        ok=TSimpleBinaryLoader::fromIO(Env,&str_unit,IO);
        if(!ok)return;
        ok=TSimpleBinaryLoader::fromStr(Env,&unit,str_unit);
      }
    };
    void handle(Socket*client,T20130410_Socket&s)
    {
      TDataIO IO;
      IO.IO.mem=s.content;
      size_t last_pos=0;
      for(;;)
      {
        t_unit_loader loader;
        loader.load(Env,IO);
        if(!loader.ok||IO.crashed)break;
        t_server::t_request&request=qap_add_back(owner.game_server.fromClients);
        request.client_id=s.socket;
        request.unit=std::move(loader.unit);
        last_pos=IO.IO.pos;
      }
      s.content=s.content.substr(last_pos);
    }
  public:
    void OnRecvPack(Socket*client,std::string&data)
    {
      int id=owner.find_socket_id(owner.sockets,client->sock);
      QapAssert(id>=0);
      auto&s=owner.sockets[id];
      s.news.push_back(TSoketItem());
      s.news.back().time=cur_date_str();
      s.news.back().data=data;
      if(s.news.size()>128)subarr_in_place(s.news,1);
      s.content+=data;
      handle(client,s);
      return;
      string answer="answer";
      client->send_raw(answer);
      shutdown(client->sock,SD_BOTH);
    }
    void OnAddClient(Socket*client)
    {
      client->set_auto_flush(true);
      int id=owner.find_socket_id(owner.sockets,client->sock);
      QapAssert(id<0);
      owner.sockets.push_back(T20130410_Socket());
      auto&s=owner.sockets.back();
      s.socket=client->sock;
      s.addr=client->name();
      s.addtime.push_back(cur_date_str());
    }
    void OnDeleteClient(Socket*client)
    {
      int id=owner.find_socket_id(owner.sockets,client->sock);
      QapAssert(id>=0);
      owner.sockets[id].deltime.push_back(cur_date_str());
      vector<T20130410_Socket> tmp;
      auto&arr=owner.sockets;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(i!=id)tmp.push_back(std::move(ex));
        if(i==id)owner.olds.push_back(std::move(ex));
      }
      owner.sockets=std::move(tmp);
    }
  };
public:
  void Update(IEnvRTTI&Env)
  {
    if(!Enabled)return;
    if(Server&&!Server->serv.runned)
    {
      auto&arr=sockets;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.offtime.push_back(cur_date_str());
        olds.push_back(std::move(ex));
      }
      arr.clear();
      Server=nullptr;
    }
    if(auto_restart&&!Server)
    {
      auto*pServer=Server.build<T20130410_GatewayServer>(Env);
      auto&serv=pServer->serv;
      serv.port=port;
      serv.raw=true;
      serv.start_tcp();
      serv.start_udp();
    }
    if(Server)
    {
      auto*pServer=Server.get();
      auto&serv=pServer->serv;
      TServerCallback cb(Env,*this);
      serv.callback=&cb;
      serv.update_tcp();
      serv.update_lan();
      serv.callback=nullptr;
    }
  }
public:
  static int find_socket_id(vector<T20130410_Socket>&arr,int id)
  {
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i].socket!=id)continue;
      return i;
    }
    return -1;
  }
  static T20130410_Socket*find_socket_by_client_id(vector<T20130410_Socket>&arr,int id)
  {
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i].socket!=id)continue;
      return &arr[i];
    }
    return nullptr;
  }
  T20130410_Socket*find_socket_by_client_id(int id)
  {
    auto&arr=sockets;
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i].socket!=id)continue;
      return &arr[i];
    }
    return nullptr;
  }
public:
  void Render(t_context&con)
  {
    if(!ball_no_draw)
    {
      auto&qDev=con.qDev;
      qDev.BindTex(0,0);
      if(con.root.SysRes.BallTex)
      {
        qDev.SetColor(color);
        qDev.BindTex(0,&con.root.SysRes.BallTex->Tex);
        auto bs=ball_size;
        auto f=[&bs](int dir,int size){return dir*size-dir*bs;};
        auto cs=con.size; auto bad=ball_anchor_dir;
        auto dpos=vec2i(f(bad.x,cs.x),f(bad.y,cs.y))/2;
        auto pos=con.pos+dpos;
        qDev.DrawQuad(pos,ball_size,ball_size);
      }
      qDev.BindTex(0,0);
      qDev.SetColor(0xff000000);
    }
    books.Render(con);
  }
  void Update(t_context&con)
  {
    if(need_init)
    {
      need_init=false;
      Caption="GameServer";
      for(int i=0;i<128;i++)
      {
        string fn="level_"+IToS(i)+".h";
        if(file_get_contents(fn).empty())break;
        auto&wr=qap_add_back(game_server.worlds);
        wr.name=fn;
        wr.world_id=game_server.next_world_id;
        wr.world.load_level(wr.name);
        game_server.next_world_id++;
      }
    }
    Update(con.Env);
    game_server.update(con.Env);
    clean_clients();
    gs_update_toClients();
    //GatewayClient gc;
    //gc.start();
    int gg_books=1;
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::books);
      books.Update(con);
    }
    int gg=1;
  }
  void clean_clients()
  {
    auto&arr=game_server.clients_res;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*client=find_socket_by_client_id(sockets,ex.client_id);
      if(!client)
      {
        auto*ptr=game_server.find_actor_by_client_id(ex.client_id);
        if(ptr)
        {
          ptr->name+="[offline]";
          ptr->v=vec2d_zero;
          ptr->actor_id=-1;
        }
        ex.client_id=-1;
      }
    }
    QapCleanIf(arr,[](const t_server::t_rec&ref){return ref.client_id<0;});
    for(int i=0;i<game_server.worlds.size();i++)
    {
      auto&ex=game_server.worlds[i];
      QapCleanIf(ex.world.actors,[](const t_actor&ref){return ref.actor_id<0;});
    }
  }
  void gs_update_toClients()
  {
    auto&serv=Server->serv;
    auto&arr=game_server.toClients;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      QapAssert(ex.client_id>=0);
      auto*client=find_socket_by_client_id(sockets,ex.client_id);
      if(!client)continue;
      auto*client_sock=serv.getClientBySock(client->socket);
      QapAssert(client);
      serv.send_one(ex.body,client_sock);
    }
    arr.clear();
  }
};

class T20130410_GatewayClient{
public:
#define DEF_PRO_POOR_DESIGN()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_GatewayClient)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(GatewayClient,client,SYD,$,$)\
ADDEND()
//=====+>>>>>T20130410_GatewayClient
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_GatewayClient
public:
};

class t_cookie{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cookie)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cookie
#include "QapGenStruct.inl"
//<<<<<+=====t_cookie
public:
};

class t_items_panel{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_items_panel)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,dir,SET,"Y:R",$)\
ADDVAR(int,border,SET,8,$)\
ADDVAR(bool,item_down,DEF,$,$)\
ADDVAR(bool,item_moved,DEF,$,$)\
ADDVAR(int,item_id,SET,-1,$)\
ADDEND()
//=====+>>>>>t_items_panel
#include "QapGenStruct.inl"
//<<<<<+=====t_items_panel
public:
};

class TBookPageWithGameClient20141026:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithGameClient20141026)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,state,DEF,$,$)\
ADDVAR(vector<t_ds_network_unit>,requests,DEF,$,$)\
ADDVAR(bool,auto_reconnect,SET,true,$)\
ADDVAR(bool,auto_restart,SET,true,$)\
ADDVAR(bool,need_show_state,SET,true,$)\
ADDVAR(bool,auto_hide_state,SET,true,$)\
ADDVAR(bool,auto_send_mpos,SET,true,$)\
ADDVAR(bool,type_text,SET,false,$)\
ADDVAR(string,user_message,DEF,$,$)\
ADDVAR(string,say_prefix,SET,"say: ",$)\
ADDVAR(string,say_dir,SET,"DL",$)\
ADDVAR(QapColor,say_color,SET,0xff000000,$)\
ADDVAR(t_items_panel,items_panel,DEF,$,$)\
ADDVAR(string,mode,SET,"kb",$)\
ADDVAR(int,actor_id,SET,-1,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,port,SET,7021,$)\
ADDVAR(string,info,DEF,$,$)\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(bool,need_clear,DEF,$,$)\
ADDVAR(bool,need_clear_world,DEF,$,$)\
ADDVAR(bool,need_clear_items,DEF,$,$)\
ADDVAR(vector<t_cookie>,cookies,DEF,$,$)\
ADDVAR(TAutoPtr<T20130410_GatewayClient>,Client,DEF,$,$)\
ADDVAR(t_world,world,DEF,$,$)\
ADDVAR(string,buff,DEF,$,$)\
ADDVAR(int,max_items,SET,128,$)\
ADDVAR(vector<TSoketItem>,items,DEF,$,$)\
ADDVAR(TPageWithMenu,menu,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithGameClient20141026
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithGameClient20141026
public:
  class MeClientCallback:public ClientCallback{
  public:
    SelfClass&owner;
    MeClientCallback(SelfClass&owner):owner(owner){}
  public:
    void OnRecvPack(string&data){
      TSoketItem tmp;
      tmp.time=cur_date_str();
      tmp.data=data;
      owner.items.push_back(std::move(tmp));
      owner.buff+=data;
    }
    void OnSendPack(string&data){
    }
    void OnConnect(Socket*S){
    }
    void OnDisconnect(){
    }
  };
public:
  void Render(t_context&con)
  {
    if(!con.root.SysRes.FontObj)return;
    if(need_show_state)
    {
      draw_text(con,state,-1,+1);
      //auto*pFont=con.root.SysRes.FontObj.get();
      //auto&font=pFont->Font;
      //con.qDev.BindTex(0,&pFont->Tex);
      //vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      //QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),state);
      //con.qDev.BindTex(0,0);
    }
    render_world(con,world,actor_id);
    render_actor_items(con,world,actor_id,items_panel.dir,items_panel.border);
    menu.Render(con);
    if(type_text)
    {
      auto d=convUDLRC2vec2i(say_dir);
      con.qDev.SetColor(say_color);
      draw_text(con,say_prefix+user_message,d.x,d.y);
      //auto*pFont=con.root.SysRes.FontObj.get();
      //auto&font=pFont->Font;
      //con.qDev.BindTex(0,&pFont->Tex);
      //vec2d p=con.pos+vec2d(+10,+10+font.Info[' '].y)+vec2d(-con.size.x,-con.size.y)*0.5;
      //QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),user_message);
      //con.qDev.BindTex(0,0);
    }
  }
  void Update(t_context&con)
  {
    if(need_clear){need_clear=false;need_clear_world=true;need_clear_items=true;}
    if(need_clear_world)
    {
      need_clear_world=false;
      world=std::move(t_world());
    }
    if(need_clear_items)
    {
      need_clear_items=false;
      items.clear();
    }
    if(need_init)
    {
      need_init=false;
      Caption="GameClient";
    }
    UpdateFull(con);
    int gg_menu=1;
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::menu);
      menu.Update(con);
    }
    int gg=1;
  }
  void UpdateFull(t_context&con)
  {
    if(!Client&&auto_restart)
    {
      auto*ptr=Client.build<T20130410_GatewayClient>(con.Env);
      auto&c=ptr->client;
    }
    if(!Client){info="no client";return;}info="client";
    auto&c=Client->client;
    MeClientCallback cb(*this);
    QapAssert(!c.callback);
    c.callback=&cb;
    if(c.runned)if(c.port!=port){
      Client=nullptr;return;
    }
    if(!c.runned)
    {
      QapAssert(!c.server);
      c.port=port;
      c.start();
      c.scan_lan_begin();
      state="scan_lan";
    }
    c.scan_lan_result();
    if(c.runned)info+="|runned";
    if(!c.runned)info+="|no_runned";
    if(c.scanning_lan)info+="|scan";
    if(!c.scanning_lan)info+="|no_scan";
    if(c.server)info+="|serv";
    if(!c.server)info+="|no_serv";
    if(c.server)if(c.server->s.connected)info+="|connected";
    if(c.server)if(!c.server->s.connected)info+="|no_connected";
    if(c.server)if(!c.server->s.connected)if(state!="scan_lan")if(state!="connect_result")if(state!="disconnected")
    {
      need_show_state=true;
      state="disconnected";
      tick=128;
    }
    if(state=="disconnected")if(auto_reconnect)
    {
      if(!tick){Client=nullptr;return;}
      tick--;
    }
    if(state=="scan_lan")
    {
      if(tick>128){
        tick=0;
        c.scan_lan_end();
        c.scan_lan_begin();
      }else{tick++;}
    }
    if(state=="scan_lan")
    {
      c.scan_lan_result();
      if(!c.servers.empty())
      {
        c.select(0);
        c.connect_begin();
        c.scan_lan_end();
        state="connect_result";
      }
    }
    if(state=="connect_result")
    {
      if(c.connect_result())
      {
        cb.OnConnect(&c.server->s);
        c.server->s.set_auto_flush(true);
        state="send_to_server_raw_init";
        tick=0;
      }
    }
    if(state=="send_to_server_raw_init")
    {
      qap_add_back(requests).code="init();";
      state="send_to_server_raw";
    }
    if(state=="recv_from_server")
    {
      c.recv_from_server_raw();
    }
    load_world_from_buff(con);
    if(type_text)if(mode=="kb")if(con.is_hovered())for(;;)
    {
      auto&kb=con.kb;
      if(!kb.News)break;
      if(kb.OnDown(VK_BACK))if(!user_message.empty()){user_message.pop_back();break;}
      if(kb.Down[VK_ESCAPE]){con.kb.Down[VK_ESCAPE]=false;user_message="";type_text=false;break;}
      static string allowed=gen_dips("azAZ09àÿÀß")+" ~`¸!@#¹$%^&*()_+-={}[];':\"\\/,.<>?";
      bool ok=allowed.find(con.kb.LastChar)!=string::npos;
      if(!ok)break;
      user_message+=con.kb.LastChar;
      break;
    }
    if(state=="send_to_server_raw")
    {
      qap_add_back(requests).code="get_world_state();";
      state="recv_from_server";
      if(type_text)if(mode=="kb")if(con.is_hovered())for(;;)
      {
        auto&kb=con.kb;
        if(kb.OnDown(VK_RETURN))
        {
          type_text=false;
          auto&back=qap_add_back(requests);
          back.code="say();";
          back.data=user_message;
          break;
        }
        break;
      }
      if(!type_text)if(mode=="kb")if(con.is_hovered())
      {
        if(con.kb.Down[VK_SPACE]){
          qap_add_back(requests).code="spawn_obstacle();";
        }
        if(con.kb.Down['T']){
          type_text=true;user_message="";
        }
        if(con.kb.Down['E']){
          qap_add_back(requests).code="use();";
        }
        if(con.kb.Down['U']){
          qap_add_back(requests).code="use_item();";
        }
        if(con.kb.Down[mbLeft])for(;;)
        {
          auto*pa=find_actor_in_world(world,actor_id);
          if(!pa)break;
          //try use item
          {
            auto&qDev=con.qDev;
            auto&font=con.root.SysRes.FontObj->Font;
            vector<t_text_box> out; int size_y=0; int size_x=0;
            auto&arr=pa->items;
            {for(int i=0;i<arr.size();i++)
            {
              auto&ex=arr[i];
              auto&back=qap_add_back(out);
              back=get_q3_text_box(font,ex.name);
              size_x=std::max<int>(back.size.x,size_x);
              size_y+=back.size.y;
              //back.pos.x=
            }}
            auto dir=convUDLRC2vec2i(items_panel.dir);
            auto panel_pos=use_anchor_dir_for_object_raw(dir,con.size,vec2i(size_x,size_y),items_panel.border);
            auto mpos=con.get_mpos();
            int win_id=-1;
            for(int i=0;i<out.size();i++)
            {
              auto&text_box=out[i];
              auto line_pos=panel_pos+vec2i(0,size_y/2-text_box.size.y*i);
              auto p=con.pos+line_pos+text_box.pos;
              bool need_send=!PointInQuad(mpos,line_pos,text_box.size);
              if(need_send)continue;
              QapAssert(win_id==-1);
              win_id=i;
            }
            if(win_id>=0)
            {
              auto&back=qap_add_back(requests);
              back.code="use_item();";
              back.data=TSimpleBinarySaver::toStr(con.Env,&win_id);
              break;
            }
          }
          //try fire
          auto campos=pa->pos;
          vec2i mpos=con.get_mpos()+vec2i(campos.x,campos.y);
          auto&back=qap_add_back(requests);
          back.code="fire();";
          back.data=TSimpleBinarySaver::toStr(con.Env,&mpos);
          break;
        }
        //always
        {
          vec2i v;
          #define F(dx,dy,key_a,key_b)if(con.kb.Down[key_a]||con.kb.Down[key_b]){v.x+=dx;v.y+=dy;}
          F(-1,+0,VK_LEFT,'A');
          F(+1,+0,VK_RIGHT,'D');
          F(+0,+1,VK_UP,'W');
          F(+0,-1,VK_DOWN,'S');
          #undef F
          auto&back=qap_add_back(requests);
          back.code="move();";
          back.data=TSimpleBinarySaver::toStr(con.Env,&v);
        }
      }
      {
        int offset=int(items.size())-max_items;
        if(offset<0)offset=0;
        subarr_in_place(items,offset);
      }
    }
    if(!requests.empty())
    {
      vector<string> out;
      auto&arr=requests;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        QapAssert(!ex.code.empty());
        qap_add_back(out)=TSimpleBinarySaver::toStr(con.Env,&ex);
      }
      auto all=TSimpleBinarySaver::toStr(con.Env,&out);
      auto pack=all.substr(sizeof(int));//drop vector size
      c.send_to_server_raw(pack);
      requests.clear();
    }
    c.callback=nullptr;
  }
  bool exec_script(IEnvRTTI&Env,const string&script)
  {
    if(script.empty())return false;
    vector<t_branch_head_ptr> ptrs;
    #define F(NAME,VAR){auto&back=qap_add_back(ptrs);back.name=NAME;back.raw_ptr.set(Env,VAR);}
    F("client",*this);
    F("self",*this);
    F("root",*this);
    #undef F
    vector<TDay20140605Book*> path;
    IRenderProgram::t_context context={
      Env,*(TD3DGameBoxBuilder*)nullptr
    };
    auto con=t_world::make_empty_context(Env,path,context);
    context.dev.branch.top.pType=Sys$$<SelfClass>::GetRTTI(Env);
    context.dev.branch.top.pValue=this;
    TAutoPtr<IScriptAST> ast;
    build_branch_script_ast(Env,ast,script);
    bool ok=false;
    if(ast)
    {
      auto res=ast->exec(con,ptrs);
      ok=res.ok;
    }
    //if(!ok)QapDebugMsg("script from 'eval_request' failed:\n"+script);
    return ok;
  }
  void load_world_from_buff(t_context&con)
  {
    auto&Env=con.Env;
    for(;;)
    {
      if(buff.size()<4)return;
      auto&size=*(int*)&buff[0];
      if(size+4>buff.size())return;
      string response=buff.substr(4,size);
      const static string s_actor_id="actor_id;";
      const static string s_world="world;";
      const static string s_eval="eval;";
      if(is_first_part_of(response,s_eval))
      {
        //vector<TAutoPtr<void>> vars;
        //auto ptrs=get_ptrs(con);
        auto code=without_first_part(response,s_eval);
        bool ok=exec_script(con.Env,code);
        //bool ok=ExecBranchScript(con,code,ptrs,vars);
        if(!ok)QapDebugMsg("script from 'eval_request' failed:\n"+code);
      }
      if(is_first_part_of(response,s_actor_id))
      {
        auto str_actor_id=without_first_part(response,s_actor_id);
        actor_id=SToI(str_actor_id);
      }
      if(is_first_part_of(response,s_world))
      {
        auto str_world=without_first_part(response,s_world);
        TSimpleBinaryLoader::fromStr(Env,&world,str_world);
        state="send_to_server_raw";
        if(auto_hide_state)need_show_state=false;
      }
      buff=buff.substr(4+size);
    }
  }
};

class TBookPageWithServerRequestSender:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithServerRequestSender)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithServerRequestSender
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithServerRequestSender
public:
  void Render(t_context&con)
  {
    editor.Render(con);
    draw_text(con,"send message from server to all clients",+1,-1);
  }
  static string unsafe_get_curBranchAsStr(t_context&con,int start_id=0)
  {
    return con.GetCurBranchAsStr(con.context.dev.branch.top.pValue,start_id);
  }
  static TBookPageWithGameServer20141026*cbrft_for_TBookPageWithGameServer20141026(t_context&con)
  {
    auto&context=con.context;
    auto*pType=Sys$$<TBookPageWithGameServer20141026>::GetRTTI(con.Env);
    if(!pType)return nullptr;
    auto&arr=context.dev.branch;
    if(arr.empty()){QapNoWay();return nullptr;}
    for(int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ax=arr[i];
      if(ax.pType!=pType)continue;
      return (TBookPageWithGameServer20141026*)ax.pValue;
    }
    string msg="cbrft not found this type on current branch.\nbranch:\n"+unsafe_get_curBranchAsStr(con)+"\n\ntype:\n"+pType->GetFullName();
    QapDebugMsg(msg);
    return nullptr;
  }
  void Update(t_context&con)
  {
    if(con.is_hovered())
    {
      if(con.kb.Down[VK_CONTROL]&&con.kb.OnDown(VK_RETURN))
      {
        auto*pserv=cbrft_for_TBookPageWithGameServer20141026(con);
        if(!pserv)return;
        //auto&arr=pserv->sockets;
        auto&arr=pserv->game_server.clients_res;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          //auto*s=pserv->find_socket_by_client_id(ex.client_id);
          //if(!s)continue;
          auto&back=qap_add_back(pserv->game_server.toClients);
          back.client_id=ex.client_id;
          string request="eval;"+editor.text;
          back.body=TSimpleBinarySaver::toStr(con.Env,&request);
        }
        return;
      }
    }
    //
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::editor);
      editor.Update(con);
    }
    int gg=1;
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
        F(TType)F(TBookPageWithGameClient20141026)F(TBookPageWithGameServer20141026)F(TBookPageWithButtons)\
        F(TBookPageWithServerRequestSender)
        //F(TBookPageRectTable)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env){}
    ThisCompileUnit(){
      srand(time(nullptr));
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}
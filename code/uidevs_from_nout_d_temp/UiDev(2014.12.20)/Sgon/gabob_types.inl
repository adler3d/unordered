#ifdef DEF_BUILD_MACRO
  #include "../Macro/gabob_types.h"
#else
//=====>>>>>gabob_types

class TGabobClock{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobClock)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,interval,SET,16,$)\
ADDEND()
//=====+>>>>>TGabobClock
#include "QapGenStruct.inl"
//<<<<<+=====TGabobClock
public:
};

class TGabobPhys{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobPhys)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobPhys
#include "QapGenStruct.inl"
//<<<<<+=====TGabobPhys
public:
};

class TGabobUnit{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobUnit)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,target,DEF,$,$)\
ADDVAR(TGabobClock,clock,DEF,$,$)\
ADDVAR(TGabobPhys,phys,DEF,$,$)\
ADDVAR(int,need_help_tick,DEF,$,$)\
ADDVAR(int,life,SET,10,$)\
ADDVAR(int,frags,DEF,$,$)\
ADDVAR(int,total_hits,DEF,$,$)\
ADDVAR(int,total_shots,DEF,$,$)\
ADDVAR(int,frags_eat,DEF,$,$)\
ADDVAR(bool,wait_new_target,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobUnit
#include "QapGenStruct.inl"
//<<<<<+=====TGabobUnit
public:
};

class TGabobBulletRaw{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobBulletRaw)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,owner,DEF,$,$)\
ADDVAR(TGabobPhys,phys,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobBulletRaw
#include "QapGenStruct.inl"
//<<<<<+=====TGabobBulletRaw
public:
};

class TGabobBullets{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobBullets)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TGabobBulletRaw>,raws,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobBullets
#include "QapGenStruct.inl"
//<<<<<+=====TGabobBullets
public:
};

class TGabobTeam{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobTeam)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(bool,spamteam,DEF,$,$)\
ADDVAR(bool,always_spam,DEF,$,$)\
ADDVAR(bool,dummy,DEF,$,$)\
ADDVAR(bool,smart,DEF,$,$)\
ADDVAR(bool,workinteam,DEF,$,$)\
ADDVAR(bool,select_best_teammate,DEF,$,$)\
ADDVAR(bool,select_near_target,DEF,$,$)\
ADDVAR(bool,bullet_time_control,DEF,$,$)\
ADDVAR(bool,withoutrules,DEF,$,$)\
ADDVAR(bool,fire_when_target_is_empty,DEF,$,$)\
ADDVAR(bool,ai_withoutrules_use_trace_depth,DEF,$,$)\
ADDVAR(int,ai_withoutrules_trace_depth,SET,768,$)\
ADDVAR(int,number_of_dirs_for_trace,SET,720,$)\
ADDVAR(int,max_help_tick,SET,8,$)\
ADDVAR(int,help_dist,SET,150,$)\
ADDVAR(int,frags_eat,DEF,$,$)\
ADDVAR(int,unfrags,DEF,$,$)\
ADDVAR(int,frags,DEF,$,$)\
ADDVAR(int,shots,DEF,$,$)\
ADDVAR(int,hits,DEF,$,$)\
ADDVAR(int,unhits,DEF,$,$)\
ADDVAR(int,last_unit_id,DEF,$,$)\
ADDVAR(int,last_bullet_id,DEF,$,$)\
ADDVAR(QapColor,color,SET,0xffffffff,$)\
ADDVAR(vector<TGabobUnit>,units,DEF,$,$)\
ADDVAR(TGabobBullets,bullets,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobTeam
#include "QapGenStruct.inl"
//<<<<<+=====TGabobTeam
public:
};


class TGabobParticle{
public:
#define DEF_PRO_AUTO_EQUAL()
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
#define DEF_PRO_AUTO_EQUAL()
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

class TGabobReplayFrame{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobReplayFrame)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TGabobTeam>,teams,DEF,$,$)\
ADDVAR(vector<TGabobExplosion>,explosions,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobReplayFrame
#include "QapGenStruct.inl"
//<<<<<+=====TGabobReplayFrame
public:
};

//<<<<<=====gabob_types
#endif //DEF_BUILD_MICRO//
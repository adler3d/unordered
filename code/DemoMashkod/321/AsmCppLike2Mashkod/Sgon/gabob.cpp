#include "StdAfx.h"

#include "TSimpleBinarySaver.inl"

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

class TGabobClock{
public:
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
  void update()
  {
    if(tick>=interval)tick=0;
    tick++;
  }
  void rnd_reset()
  {
    tick=rand()%interval;
  }
  operator bool()const{return tick>=interval;}
};

class TGabobPhys{
public:
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

class TGabobReplayFrame{
public:
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

class TGabobReplay{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobReplay)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(vector<string>,frames,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobReplay
#include "QapGenStruct.inl"
//<<<<<+=====TGabobReplay
public:
};

class TGabobReplaySystem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobReplaySystem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TGabobReplay>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobReplaySystem
#include "QapGenStruct.inl"
//<<<<<+=====TGabobReplaySystem
public:
};

class TGabobExplosionSys{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobExplosionSys)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TGabobExplosion>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobExplosionSys
#include "QapGenStruct.inl"
//<<<<<+=====TGabobExplosionSys
public:
};

class TGabobGame{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGabobGame)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,locked,DEF,$,$)\
ADDVAR(bool,need_clear,DEF,$,$)\
ADDVAR(bool,need_step,DEF,$,$)\
ADDVAR(bool,no_update,DEF,$,$)\
ADDVAR(bool,no_render,DEF,$,$)\
ADDVAR(bool,no_render_text,DEF,$,$)\
ADDVAR(bool,use_extrafast_shot_dir_det_algo,DEF,$,$)\
ADDVAR(bool,use_fast_algo_for_detection_shot_dir,DEF,$,$)\
ADDVAR(bool,no_expl_if_no_render,SET,true,$)\
ADDVAR(bool,no_new_shot_in_sim,SET,true,$)\
ADDVAR(bool,use_pre_pass_before_full_sim,SET,true,$)\
ADDVAR(int,mpu,SET,1,$)\
ADDVAR(int,unit_radius,SET,8,$)\
ADDVAR(int,bullet_radius,SET,4,$)\
ADDVAR(real,unit_speed,SET,1,$)\
ADDVAR(real,bullet_speed,SET,4,$)\
ADDVAR(int,life_for_fragger,SET,20,$)\
ADDVAR(int,w,SET,1024,$)\
ADDVAR(int,h,SET,600,$)\
ADDVAR(bool,need_force_set_max_ang_diff,DEF,$,$)\
ADDVAR(real,info_max_ang_diff_force_value,SET,0.3,$)\
ADDVAR(real,info_max_ang_diff,DEF,$,$)\
ADDVAR(vec2i,info_text_pos,SET,vec2i(-400,0),$)\
ADDVAR(int,global_tick,DEF,$,$)\
ADDVAR(TGabobClock,income,DEF,$,$)\
ADDVAR(vector<TGabobTeam>,teams,DEF,$,$)\
ADDVAR(bool,show_names_from_units,DEF,$,$)\
ADDVAR(bool,no_render_selected,DEF,$,$)\
ADDVAR(bool,no_update_selected,DEF,$,$)\
ADDVAR(int,select_radius,SET,4,$)\
ADDVAR(QapColor,select_color,SET,0xffffffff,$)\
ADDVAR(vector<string>,selected,DEF,$,$)\
ADDVAR(int,rec_play_dpos,SET,1,$)\
ADDVAR(bool,rec_play,DEF,$,$)\
ADDVAR(bool,rec_start,DEF,$,$)\
ADDVAR(bool,rec_stop,DEF,$,$)\
ADDVAR(bool,rec_next,DEF,$,$)\
ADDVAR(bool,rec_prev,DEF,$,$)\
ADDVAR(bool,rec_setname,DEF,$,$)\
ADDVAR(string,rec_name_new,DEF,$,$)\
ADDVAR(string,rec_name_cur,DEF,$,$)\
ADDVAR(bool,rec_recording,DEF,$,$)\
ADDVAR(int,rec_frame_id,DEF,$,$)\
ADDVAR(int,rec_replay_id,DEF,$,$)\
ADDVAR(TAutoPtr<TGabobReplaySystem>,ReplaySys,DEF,$,$)\
ADDVAR(TGabobExplosionSys,ref_explosions,DEF,$,$)\
ADDVAR(TGabobExplosionSys,explosions,DEF,$,$)\
ADDEND()
//=====+>>>>>TGabobGame
#include "QapGenStruct.inl"
//<<<<<+=====TGabobGame
public:
  typedef IBookPage::t_context t_context;
public:
  void DoDraw(t_context&con,TGabobExplosion&ref)
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
  void DoDraw(t_context&con,vector<TGabobExplosion>&arr)
  {
    auto&texobj=con.root.SysRes.BallTex;
    if(texobj)
    {
      con.qDev.BindTex(0,&texobj->Tex);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      DoDraw(con,ex);
      //con.qDev.DrawQuad(con.pos+ex.pos,vec2d(1,1)*unit_size);
    }
  }
public:
  void DoDraw(t_context&con,TGabobBulletRaw&raw)
  {
    //auto offset=vec2d(1,1)*0.5;
    auto size=vec2d(1.75,0.75)*bullet_radius*2;
    vec2d p=con.pos+raw.phys.pos;
    //con.qDev.DrawQuadWithHalfPixelOffset(vec2i(p.x,p.y),size);
    con.qDev.DrawQuad(p,size,raw.phys.v.GetAng());
  }
  void DoDraw(t_context&con,TGabobBullets&bullets)
  {
    auto&arr=bullets.raws;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      DoDraw(con,ex);
    }
  }
  void DoDraw(t_context&con,TGabobUnit&unit)
  {
    auto size=vec2i(1,1)*unit_radius*2;
    vec2d p=con.pos+unit.phys.pos;
    //con.qDev.DrawQuadWithHalfPixelOffset(vec2i(p.x,p.y),size);
    //auto offset=vec2d(1,1)*0.5;
    con.qDev.DrawQuad(p,unit_radius*2,unit_radius*2);
  }
  void DoDraw(t_context&con,vector<TGabobUnit>&units)
  {
    for(int i=0;i<units.size();i++)
    {
      auto&ex=units[i];
      DoDraw(con,ex);
    }
  }
  void DoDraw(t_context&con,vector<TGabobTeam>&teams)
  {
    for(int i=0;i<teams.size();i++)
    {
      auto&ex=teams[i];
      DoDraw(con,ex);
    }
  }
  void DoDraw(t_context&con,TGabobTeam&team)
  {
    con.qDev.SetColor(team.color);
    {
      //DoDraw(con,team.bullets);
      DoDraw(con,team.units);
    }
    int gg=1;
  }
public:
  static string pad(const string&s,int v)
  {
    if(v<s.size())return s;
    string tmp;
    tmp.resize(v-s.size(),' ');
    return tmp+s;
  }
  void RenderText(t_context&con,vector<TGabobTeam>&teams)
  {
    auto&qDev=con.root.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      QapDev::BatchScope Scope(con.qDev);
      qDev.BindTex(0,&pFont->Tex);
      qDev.SetColor(0xff000000);
      vec2d p=con.pos+vec2d(+10,-10)+info_text_pos+vec2d(0/*-con.size.x*/,+con.size.y)*0.5;
      auto add=[&](const string&text){
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+p.x),int(con.pos.y+p.y),text);p.y+=-font.Info[0].y;
      };
      auto add_text=[&](const string&text,vec2d&p){
        auto len=QapQ3Text::GetLength(font,text);
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+p.x-len/2),int(con.pos.y+p.y),text);
      };
      //add("teams:");
      vector<vector<string>> colomns;colomns.reserve(32);
      #define F(stat)auto&for_##stat=qap_add_back(colomns);qap_add_back(for_##stat)=#stat;
      F(name)F(frags)F(units)F(lifes)F(cur_frags)F(max_life)F(max_frags)
      F(unfrags)F(frags_eat)
      F(unhits)F(hits)F(shots)
      auto&for_hitspershots=qap_add_back(colomns);qap_add_back(for_hitspershots)="hits/shots";
      #undef F
      {for(int i=0;i<colomns.size();i++)qap_add_back(colomns[i]);}
      //init
      {
        for(int i=0;i<teams.size();i++)
        {
          auto&ex=teams[i];
          qap_add_back(for_name)=ex.name;
          qap_add_back(for_frags)=IToS(ex.frags);
          qap_add_back(for_units)=IToS(ex.units.size());
          qap_add_back(for_unfrags)=IToS(ex.unfrags);
          qap_add_back(for_frags_eat)=IToS(ex.frags_eat);
          qap_add_back(for_unhits)=IToS(ex.unhits);
          qap_add_back(for_hits)=IToS(ex.hits);
          qap_add_back(for_shots)=IToS(ex.shots);
          qap_add_back(for_hitspershots)=FToS(100.0*ex.hits/real(ex.shots))+" %";
          {int v=0;for(int i=0;i<ex.units.size();i++){v+=ex.units[i].life;}qap_add_back(for_lifes)=IToS(v);}
          {int v=0;for(int i=0;i<ex.units.size();i++){v+=ex.units[i].frags;}qap_add_back(for_cur_frags)=IToS(v);}
          {int v=0;for(int i=0;i<ex.units.size();i++){v=std::max(v,ex.units[i].life);}qap_add_back(for_max_life)=IToS(v);}
          {int v=0;for(int i=0;i<ex.units.size();i++){v=std::max(v,ex.units[i].frags);}qap_add_back(for_max_frags)=IToS(v);}
        }
      }
      vector<int> cs; //int fs=0;
      for(int i=0;i<colomns.size();i++)
      {
        auto&colomn=colomns[i];
        int ms=0;
        for(int i=0;i<colomn.size();i++){ms=std::max<int>(ms,colomn[i].size());}
        qap_add_back(cs)=ms;
        //fs=std::max(ms,fs);
        colomn[1].resize(ms,'-');
      }
      int n=colomns[0].size();
      for(int j=0;j<n;j++)
      {
        string line;
        for(int i=0;i<colomns.size();i++)
        {
          auto&ex=colomns[i][j];
          if(i)line+="  ";
          int v=cs[i];
          line+=pad(ex,v);
        }
        add(line);
      }
      if(show_names_from_units)
      {
        for(int i=0;i<teams.size();i++)
        {
          auto&team=teams[i];
          auto&units=team.units;
          for(int j=0;j<units.size();j++)
          {
            auto&unit=units[j];
            add_text(team.name+"."+unit.name,unit.phys.pos);
          }
        }
        int gg=1;
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void RenderTeams(t_context&con,vector<TGabobTeam>&teams)
  {
    if(no_render)return;
    QapDev::BatchScope Scope(con.qDev);
    for(int i=0;i<teams.size();i++)
    {
      auto&team=teams[i];
      con.qDev.SetColor(team.color);
      for(int i=0;i<team.bullets.raws.size();i++)
      {
        auto&bullet=team.bullets.raws[i];
        DoDraw(con,bullet);
      }
    }
    DoDraw(con,teams);
    if(!no_render_selected)
    {
      auto&arr=selected;
      con.qDev.SetColor(select_color);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*ptr=find_unit_by_full_name(teams,ex);
        if(!ptr)continue;
        auto size=vec2i(1,1)*unit_radius*2;
        vec2d p=con.pos+ptr->phys.pos;
        con.qDev.DrawQuad(p,select_radius*2,select_radius*2);
      }
    }
  }
  void Render(t_context&con)
  {
    con.qDev.SetColor(0xffffffff);
    con.qDev.BindTex(0,nullptr);
    con.qDev.DrawRectAsQuad(con.pos,vec2i(w,h),2);
    con.qDev.BindTex(0,&con.context.root.SysRes.BallTex->Tex);
    TGabobReplayFrame frame;
    auto*pteams=&teams;
    auto*pexplosions=&explosions.arr;
    if(rec_play&&ReplaySys)for(;;)
    {
      if(no_render)break;
      auto&rs=*ReplaySys.get();
      if(rec_replay_id>=rs.arr.size())break;
      auto&replay=rs.arr[rec_replay_id];
      if(rec_frame_id>=replay.frames.size())break;
      auto&frame_str=replay.frames[rec_frame_id];
      TSimpleBinaryLoader::fromStr(con.Env,&frame,frame_str);
      pteams=&frame.teams;
      pexplosions=&frame.explosions;
      break;
    }
    RenderTeams(con,*pteams);
    if(!no_render)DoDraw(con,*pexplosions);
    if(!no_render_text)RenderText(con,*pteams);
    con.qDev.BindTex(0,nullptr);
  }
public:
  static TGabobBulletRaw*find_bullet_by_name(TGabobTeam&team,const string&name)
  {
    //QapAssert(!locked);
    auto&arr=team.bullets.raws;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.name==name)return &ex;
    }
    return nullptr;
  }
  static TGabobTeam*find_team_by_name(vector<TGabobTeam>&teams,const string&name)
  {
    //QapAssert(!locked);
    for(int i=0;i<teams.size();i++)
    {
      auto&ex=teams[i];
      if(ex.name==name)return &ex;
    }
    return nullptr;
  }
  static TGabobUnit*find_unit_by_name(TGabobTeam&team,const string&name)
  {
    auto&arr=team.units;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.name==name)return &ex;
    }
    return nullptr;
  }
  static TGabobTeam*find_team_by_unit_full_name(vector<TGabobTeam>&teams,const string&fullname)
  {
    //QapAssert(!locked);
    auto path=split(fullname,".");
    QapAssert(path.size()==2);
    return find_team_by_name(teams,path[0]);
  }
  static TGabobUnit*find_unit_by_full_name(vector<TGabobTeam>&teams,const string&fullname)
  {
    //QapAssert(!locked);
    auto path=split(fullname,".");
    QapAssert(path.size()==2);
    if(path.size()<2)return nullptr;
    auto*pt=find_team_by_name(teams,path[0]);
    if(!pt)return nullptr;
    return find_unit_by_name(*pt,path[1]);
  }
public:
  void DoMove(vector<TGabobExplosion>&arr)
  {
    QapCleanIf(arr,[](TGabobExplosion&ex){return !ex.undeadable&&(ex.tick>=ex.max_tick)&&ex.arr.empty();});
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      DoMove(ex);
    }
  }
  void DoMove(TGabobExplosion&ref)
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
  TGabobExplosion*find_ref_explosion_by_name(const string&name)
  {
    QapAssert(!locked);
    auto list=qap_find(ref_explosions.arr,[&name](TGabobExplosion&ex)->bool{return name==ex.name;});
    if(list.empty()){return nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return &ref_explosions.arr[list[0]];
  }
  TGabobExplosion&unsafe_find_explosion_by_name(const string&name)
  {
    QapAssert(!locked);
    auto list=qap_find(ref_explosions.arr,[&name](TGabobExplosion&ex)->bool{return name==ex.name;});
    if(list.empty()){QapDebugMsg("ref_explosion not found:\n"+name);return *(TGabobExplosion*)nullptr;}
    if(list.size()>1){QapDebugMsg("list.size()>1 for ref_explosion:\n"+name);}
    return ref_explosions.arr[list[0]];
  }
public:
  struct t_get_shot_dir_result{
    vec2d dir;
    int t;
    int id;
  };
  t_get_shot_dir_result get_shot_dir(const vec2d&tpos,const vec2d&v,const vec2d&bpos,bool dummy,bool smart,bool spamteam,int n)
  {
    if(spamteam)return {Vec2dEx(RndReal(0,Pi2),bullet_speed),-1,-1};
    auto defang=(tpos-bpos).GetAng();
    auto defdir=Vec2dEx(defang,bullet_speed);
    t_get_shot_dir_result def={defdir,-1,-1};
    if(dummy)return def;
    auto d=bullet_radius+unit_radius;d*=d;
    int bw2=w/2-bullet_radius;
    int bh2=h/2-bullet_radius;
    int uw2=w/2-unit_radius;
    int uh2=h/2-unit_radius;
    if(use_extrafast_shot_dir_det_algo)for(;;)
    {
      vec2d tp=tpos;
      vec2d tv=v;
      auto brur=bullet_radius+unit_radius;
      int time=-1;
      real bdist=0;
      for(int t=0;t<2048;t++)
      {
        auto cur_dist=(tp-bpos).Mag();
        auto left=abs(cur_dist-bdist);
        if(left<brur){time=t;break;}
        if(smart)
        {
          if(tp.x>+uw2){tp.x=+uw2;tv.x=-abs(tv.x);}
          if(tp.y>+uh2){tp.y=+uh2;tv.y=-abs(tv.y);}
          if(tp.x<-uw2){tp.x=-uw2;tv.x=+abs(tv.x);}
          if(tp.y<-uh2){tp.y=-uh2;tv.y=+abs(tv.y);}
        }else{
          if(tp.x>+uw2)break;
          if(tp.y>+uh2)break;
          if(tp.x<-uw2)break;
          if(tp.y<-uh2)break;
        }
        tp+=tv;bdist+=bullet_speed;
      }
      if(time>=0)return {(tp-bpos).SetMag(bullet_speed),time,-1};
      break;
    }
    static vector<int> arr;
    arr.resize(n);
    int best=-1;
    real base_ang=0;
    static int max_tick=-1;
    auto func=[&](int i)
    {
      auto ang=base_ang+Pi2*real(i)/real(n);
      vec2d bv=Vec2dEx(ang,bullet_speed);
      vec2d bp=bpos;
      vec2d tp=tpos;
      vec2d tv=v;
      arr[i]=-1;
      for(int t=0;t<2048;t++)
      {
        if((bp-tp).SqrMag()<d){arr[i]=t;if(best<0){best=i;}else{if(arr[best]>t)best=i;}break;}
        bp+=bv;tp+=tv;
        if(bp.x>+bw2)break;
        if(bp.x<-bw2)break;
        if(bp.y<-bh2)break;
        if(smart)
        {
          if(tp.x>+uw2){tp.x=+uw2;tv.x=-abs(tv.x);}
          if(tp.y>+uh2){tp.y=+uh2;tv.y=-abs(tv.y);}
          if(tp.x<-uw2){tp.x=-uw2;tv.x=+abs(tv.x);}
          if(tp.y<-uh2){tp.y=-uh2;tv.y=+abs(tv.y);}
        }
        max_tick=std::max(max_tick,t);
      }
    };
    auto find_best_ang=[&]()->real
    {
      int top=0;
      for(int i=best+1;;i++){
        i=i%n;
        if(i==best)break;
        if(arr[i]!=arr[best])break;
        top++;
      }
      int low=0;
      for(int i=best-1;;i--){
        i=(i+n)%n;
        if(i==best)break;
        if(arr[i]!=arr[best])break;
        low++;
      }
      if(top>n/2||low>n/2)
      {
        //void UberInfoBox(const string&caption,const string&text);
        //UberInfoBox("hm...","check it");
      }
      auto low_ang=base_ang+Pi2*real(best-low)/real(n);
      auto top_ang=base_ang+Pi2*real(best+top)/real(n);
      auto ang=(Vec2dEx(low_ang,1)+Vec2dEx(top_ang,1)).GetAng();
      auto diff_ang=[](real a,real b)->real{
        auto v=abs(Vec2dEx(a,1).Rot(Vec2dEx(b,1)).GetAng());;
        if(v>3)
        {
          int wtf=1;
        }
        return v;
      };
      info_max_ang_diff=std::max(info_max_ang_diff,diff_ang(low_ang,defang));
      info_max_ang_diff=std::max(info_max_ang_diff,diff_ang(top_ang,defang));
      return ang;
    };
    if(use_fast_algo_for_detection_shot_dir)
    {
      int diff_n=real(info_max_ang_diff*n)/Pi2;
      base_ang=Vec2dEx(defang-info_max_ang_diff,1).GetAng();
      base_ang-=Pi2*1.0/real(n);
      auto a=defang-info_max_ang_diff;
      auto b=defang+info_max_ang_diff;
      arr[0]=-1;
      int count=diff_n*2;
      if(count+1<n)
      for(int i=1;i<=count;i++)
      {
        func(i);
      }
      arr[count+1]=-1;
    }
    //short way
    if(best>=0)
    {
      auto ang=find_best_ang();
      vec2d bv=Vec2dEx(ang,bullet_speed);
      return {bv,arr[best],best};
    }
    //full way
    base_ang=0;
    for(int i=0;i<n;i++)
    {
      func(i);
    }
    if(best<0)return def;
    auto ang=find_best_ang();
    //auto ang=Pi2*real(best-low+(top+low)/2)/real(n);
    vec2d bv=Vec2dEx(ang,bullet_speed);
    return {bv,arr[best],best};
  }
  struct t_full_world_sim{
    SelfClass&owner;
    vector<TGabobTeam> teams;
    void fast_step()
    {
      bool&no_shot=owner.no_new_shot_in_sim;
      bool tmpflag=true;
      std::swap(no_shot,tmpflag);
      QapAssert(!owner.locked);
      owner.locked=true;
      owner.Collide(teams,true);
      owner.DoMove(teams,true);
      owner.locked=false;
      std::swap(no_shot,tmpflag);
    }
    void step()
    {
      QapAssert(!owner.locked);
      owner.locked=true;
      owner.DoMove(teams,true);
      owner.Collide(teams,true);
      owner.locked=false;
    }
    struct t_price{
      int enemy_hp;int total_hp;int enemy_units;int total_units;
      real get()
      {
        if(!enemy_hp||!enemy_units)return 0;
        auto hp=real(enemy_hp)/real(total_hp);
        auto u=real(enemy_units)/real(total_units);
        return u+hp;
      }
    };
    t_price calc_price(const string&our_team_name)
    {
      int enemy_hp=0;
      int total_hp=0;
      int enemy_units=0;
      int total_units=0;
      for(int i=0;i<teams.size();i++)
      {
        auto&team=teams[i];
        auto&units=team.units;
        bool enemy=team.name!=our_team_name;
        if(enemy)enemy_units+=units.size();
        total_units+=units.size();
        for(int i=0;i<units.size();i++)
        {
          auto&unit=units[i];
          total_hp+=unit.life;
          if(enemy)enemy_hp+=unit.life;
        }
      }
      return {enemy_hp,total_hp,enemy_units,total_units};
    }
  };
  struct t_idprice{int id=-1;real price;};
  struct t_sim{
    SelfClass&owner;
    TGabobUnit target;
    vector<TGabobBulletRaw> bullets;
    void load_bullets()
    {
      for(int j=0;j<owner.teams.size();j++)
      {
        auto&team=owner.teams[j];
        for(int i=0;i<team.bullets.raws.size();i++)
        {
          auto&ex=team.bullets.raws[i];
          bullets.push_back(ex);
        }
      }
      int gg=1;
    }
    void main(int max_time)
    {
      load_bullets();
      for(int i=0;i<max_time;i++)
      {
        if(target.need_remove)return;
        step();
      }
      return;
    }
    void step()
    {
      auto d=owner.bullet_radius+owner.unit_radius;d*=d;
      target.phys.pos+=target.phys.v;
      DoMoveBullets();
      vec2d&tp=target.phys.pos;
      vec2d&tv=target.phys.v;
      {
        int uw2=owner.w/2-owner.unit_radius;
        int uh2=owner.h/2-owner.unit_radius;
        if(tp.x>+uw2){tp.x=+uw2;tv.x=-abs(tv.x);}
        if(tp.y>+uh2){tp.y=+uh2;tv.y=-abs(tv.y);}
        if(tp.x<-uw2){tp.x=-uw2;tv.x=+abs(tv.x);}
        if(tp.y<-uh2){tp.y=-uh2;tv.y=+abs(tv.y);}
      }
      for(int i=0;i<bullets.size();i++)
      {
        auto&ex=bullets[i];
        if(ex.need_remove)continue;
        auto&bp=ex.phys.pos;
        if((bp-tp).SqrMag()<d)
        {
          target.life--;
          if(target.life<=0)target.need_remove=true;
          ex.need_remove=true;
          return;
        }
      }
    }
    void DoMoveBullets()
    {
      auto&arr=bullets;
      int w2=owner.w/2-owner.bullet_radius;
      int h2=owner.h/2-owner.bullet_radius;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.need_remove)continue;
        ex.phys.pos+=ex.phys.v;
        if(ex.phys.pos.x>+w2){ex.need_remove=true;}
        if(ex.phys.pos.y>+h2){ex.need_remove=true;}
        if(ex.phys.pos.x<-w2){ex.need_remove=true;}
        if(ex.phys.pos.y<-h2){ex.need_remove=true;}
      }
      QapCleanIf(arr,[](TGabobBulletRaw&ref){return ref.need_remove;});
    }
  };
  int sim_get_unit_life_at_time(TGabobUnit&target,int time)
  {
    t_sim sim={*this,target};
    sim.main(time);
    if(sim.target.life<0)
    {
      QapDebugMsg("sim.target.life = "+IToS(sim.target.life));
      return 0;
    }
    return sim.target.life;
  };
public:
  void DoMove(TGabobTeam&team,vector<TGabobBulletRaw>&arr,bool sim)
  {
    int w2=w/2-bullet_radius;
    int h2=h/2-bullet_radius;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.need_remove)continue;
      ex.phys.pos+=ex.phys.v;
      if(ex.phys.pos.x>+w2){ex.need_remove=true;}
      if(ex.phys.pos.y>+h2){ex.need_remove=true;}
      if(ex.phys.pos.x<-w2){ex.need_remove=true;}
      if(ex.phys.pos.y<-h2){ex.need_remove=true;}
      if(ex.need_remove)
      {
        auto*pref_exp=(no_expl_if_no_render&&no_render)||sim?nullptr:find_ref_explosion_by_name("bullet_die");
        if(pref_exp)
        {
          auto&back=qap_add_back(explosions.arr);
          back=*pref_exp;
          back.particle_beg_color=team.color;
          back.pos=ex.phys.pos;
        }
      }
    }
    QapCleanIf(arr,[](TGabobBulletRaw&ref){return ref.need_remove;});
  }
  void DoShots(vector<TGabobTeam>&teams,bool sim)
  {
    auto&arr=teams;
    for(int i=0;i<arr.size();i++)
    {
      auto&team=arr[i];
      DoShots(team,sim);
    }
  }
  void DoShots(TGabobTeam&team,bool sim)
  {
    auto&units=team.units;
    for(int unit_id=0;unit_id<units.size();unit_id++)
    {
      auto&ex=units[unit_id]; auto&unit_who_shot=ex;
      DoShots(team,unit_who_shot,sim);
    }
  }
  void DoShots(TGabobTeam&team,TGabobUnit&unit_who_shot,bool sim)
  {
    auto make_shot=[](TGabobGame&game,TGabobTeam&team,TGabobUnit&unit,const vec2d&dir)
    {
      auto&back=qap_add_back(team.bullets.raws);
      back.owner=/*team.name+"."+*/unit.name;
      back.name=IToS(team.last_bullet_id++);
      back.phys.pos=unit.phys.pos;
      back.phys.v=vec2d(dir).SetMag(game.bullet_speed);
      //back.phys.pos+=vec2d(back.phys.v).SetMag(bullet_radius*2+unit_radius-bullet_speed);
      //back.phys.v.x=2.5;
      unit.total_shots++;
      team.shots++;
    };
    if(!sim)if(unit_who_shot.clock&&team.withoutrules)for(;;)
    {
      if(!team.fire_when_target_is_empty)
      {
        if(unit_who_shot.target.empty())break;
        auto*pt=find_unit_by_full_name(teams,unit_who_shot.target);
        if(!pt)
        {
          //drop target
          unit_who_shot.target.clear();
          break;
        }
        if(pt->need_remove)break;
      }
      string sim_bullet="sim_bullet";
      t_full_world_sim fws={*this,teams};
      if(!fws.calc_price(team.name).enemy_units)break;
      int n=team.number_of_dirs_for_trace;
      //vector<t_full_world_sim::t_price> prices;
      vector<t_idprice> time2price;
      vector<int> bullets_id_for_full_sim;
      int max_time=0;
      //int best_id=-1;real best_price=0;int best_t=0;
      if(use_pre_pass_before_full_sim)
      {
        int w2=w/2-bullet_radius;
        int h2=h/2-bullet_radius;
        auto brur=unit_radius+bullet_radius;brur*=brur;
        t_full_world_sim fws={*this,teams};
        int our_team_id=qap_find(teams,[&team](TGabobTeam&ex){return &ex==&team;})[0];
        vector<TGabobBulletRaw> bullets;
        bullets.resize(n);
        for(int i=0;i<n;i++)
        {
          auto ang=Pi2*real(i)/real(n);
          vec2d bv=Vec2dEx(ang,bullet_speed);
          auto&bullet=bullets[i].phys;
          bullets[i].need_remove=false;
          bullet.pos=unit_who_shot.phys.pos;
          bullet.v=bv;
        }
        int depth=team.ai_withoutrules_trace_depth;
        for(int time=0;time<depth;time++)
        {
          fws.owner.Collide(fws.teams,true);
          fws.owner.DoMove(fws.teams,true);
          fws.owner.DoShots(fws.teams,true);
          for(int i=0;i<n;i++)
          {
            auto&bullet=bullets[i];
            int bullet_id=i;
            if(bullet.need_remove)continue;
            auto&bp=bullet.phys;
            bp.pos+=bp.v;
            if(bp.pos.x>+w2){bullet.need_remove=true;}
            if(bp.pos.y>+h2){bullet.need_remove=true;}
            if(bp.pos.x<-w2){bullet.need_remove=true;}
            if(bp.pos.y<-h2){bullet.need_remove=true;}
          }
          bool ok=false;
          for(int i=0;i<n;i++)
          {
            auto&bullet=bullets[i];
            int bullet_id=i;
            if(bullet.need_remove)continue;
            auto&bp=bullet.phys.pos;
            for(int i=0;i<fws.teams.size();i++)
            {
              auto&st=fws.teams[i];
              bool taktak=our_team_id==i;
              auto&arr=st.units;
              for(int i=0;i<arr.size();i++)
              {
                auto&upp=arr[i].phys.pos;
                if(arr[i].need_remove)continue;
                if(taktak)if(arr[i].name==unit_who_shot.name)continue;
                if((bp-upp).SqrMag()>brur)continue;
                bullet.need_remove=true;
                bullets_id_for_full_sim.push_back(bullet_id);
              }
            }
            ok=true;
          }
          if(!ok)
          {
            bool good=1;
            break;
          }
        }
        int gg=1;
        if(bullets_id_for_full_sim.empty())
        {
          int wtf=1;
        }
      }
      for(int i=0;i<n;i++)
      {
        auto ang=Pi2*real(i)/real(n);
        if(use_pre_pass_before_full_sim)
        {
          if(i>=bullets_id_for_full_sim.size())break;
          ang=Pi2*real(bullets_id_for_full_sim[i])/real(n);
        }
        vec2d bv=Vec2dEx(ang,bullet_speed);
        t_full_world_sim fws={*this,teams};
        auto*sim_team=find_team_by_name(fws.teams,team.name);
        auto*sim_unit=find_unit_by_name(*sim_team,unit_who_shot.name);
        make_shot(*this,*sim_team,*sim_unit,bv);
        sim_team->bullets.raws.back().name=sim_bullet;
        int time=0;
        int depth=team.ai_withoutrules_trace_depth;
        for(time=0;time<depth;time++)
        {
          fws.step();
          if(!team.ai_withoutrules_use_trace_depth)
          {
            auto*ptr=find_bullet_by_name(*sim_team,sim_bullet);
            if(!ptr)break;
          }
        }
        auto price=fws.calc_price(team.name);
        auto price_value=price.get();
        //prices.push_back(price);
        max_time=std::max(max_time,time);
        time2price.resize(max_time+1);
        auto&ref=time2price[time];
        //if(best_id<0||price_value<best_price){
        //  best_id=i;best_price=price_value;best_t=time;
        //}
        if(ref.id>=0)if(ref.price<price_value)continue;
        ref.id=i;
        ref.price=price_value;
        //fws.teams[
      }
      //if(best_id>=0){
      //  auto ang=Pi2*real(best_id)/real(n);
      //  vec2d bv=Vec2dEx(ang,bullet_speed);
      //  make_shot(*this,team,ex,bv);
      //  break;
      //}
      int best_t=-1;real best_dp=0;
      if(time2price.empty())
      {
        int gg=1;
        break;
      }
      for(int t=0;t<=max_time;t++)
      {
        fws.step();
        auto p=fws.calc_price(team.name);
        auto v=p.get();
        auto&ref=time2price[t];
        if(ref.id<0)continue;
        if(v>=ref.price)
        {
          ref.price-=v;
          if(best_t<0||best_dp<ref.price){best_t=t;best_dp=ref.price;}
          //auto ang=Pi2*real(ref.id)/real(n);
          //vec2d bv=Vec2dEx(ang,bullet_speed);
          //make_shot(*this,team,ex,bv);
          //break;
        }else{ref.id=-1;}
      }
      if(best_t>=0)
      {
        auto&ref=time2price[best_t];
        auto ang=Pi2*real(ref.id)/real(n);
        if(use_pre_pass_before_full_sim)
        {
          ang=Pi2*real(bullets_id_for_full_sim[ref.id])/real(n);
        }
        vec2d bv=Vec2dEx(ang,bullet_speed);
        make_shot(*this,team,unit_who_shot,bv);
        break;
      }
      break;
    }
    if(unit_who_shot.clock&&team.always_spam)if(!sim){make_shot(*this,team,unit_who_shot,Vec2dEx(RndReal(0,Pi2),1));}
    for(;;)
    {
      bool need_do_smart_shot=unit_who_shot.clock&&!unit_who_shot.target.empty()&&!team.always_spam;
      if(team.withoutrules&&!sim)break;
      if(!need_do_smart_shot)break;
      if(sim&&no_new_shot_in_sim)break;
      // do smart shot here
      auto*pt=find_unit_by_full_name(teams,unit_who_shot.target);
      if(!pt)
      {
        //drop target
        unit_who_shot.target.clear();
        break;
      }
      if(pt->need_remove)break;
      auto&tar=pt->phys;
      auto tar_sdr=get_shot_dir(tar.pos,tar.v,unit_who_shot.phys.pos,team.dummy,team.smart,team.spamteam,team.number_of_dirs_for_trace);
      int tar_life=pt->life;
      if(team.bullet_time_control)
      {
        tar_life=sim_get_unit_life_at_time(*pt,tar_sdr.t);
      }
      if(!tar_life)
      {
        int gg=1;
        unit_who_shot.wait_new_target=true; //ex.target.clear();
        break;
      }
      bool send_to_teammate=false;
      if(team.workinteam&&tar_life>2)for(;;)//if(try_shot_to_teammate)
      {
        bool try_shot_to_teammate=!unit_who_shot.need_help_tick;
        bool enemy_is_weak=pt->life*3<unit_who_shot.life;
        if(!try_shot_to_teammate||enemy_is_weak)break;
        int best=-1; real low_dist=+1E9;
        auto&arr=team.units;
        for(int i=0;i<arr.size();i++)
        {
          auto&teammate=arr[i];
          if(&teammate==&unit_who_shot)continue;
          if(!teammate.target.empty()&&!teammate.wait_new_target)continue;
          if(team.select_best_teammate&&team.bullet_time_control)
          {
            auto&tar=teammate.phys;
            auto tm_sdr=get_shot_dir(tar.pos,tar.v,unit_who_shot.phys.pos,team.dummy,team.smart,team.spamteam,team.number_of_dirs_for_trace);
            auto teammate_life=sim_get_unit_life_at_time(teammate,tar_sdr.t);
            if(teammate_life<2)continue;
            auto dist=tm_sdr.t; // this is time
            //if(tm_sdr.t>team.help_dist)continue;
            if(low_dist>dist||best<0){best=i;low_dist=dist;}
          }
          if(!team.select_best_teammate)
          {
            auto dist=(teammate.phys.pos-unit_who_shot.phys.pos).Mag();
            if(dist>team.help_dist)continue;
            if(low_dist>dist||best<0){best=i;low_dist=dist;}
          }
        }
        if(best>=0)
        {
          unit_who_shot.need_help_tick=team.max_help_tick*unit_who_shot.clock.interval;
          auto&arr_best=arr[best];
          auto&tar=arr_best.phys;
          auto new_tar_sdr=get_shot_dir(tar.pos,tar.v,unit_who_shot.phys.pos,team.dummy,team.smart,team.spamteam,team.number_of_dirs_for_trace);
          send_to_teammate=true;
          if(team.bullet_time_control)
          {
            auto new_tar_life=sim_get_unit_life_at_time(arr_best,new_tar_sdr.t);
            if(new_tar_life>1)
            {
              int gg=1;
              tar_life=new_tar_life;
              tar_sdr=new_tar_sdr;
            }
          }else{
            tar_sdr=new_tar_sdr;
          }
        }
        break;
      }
      unit_who_shot.wait_new_target=false;
      make_shot(*this,team,unit_who_shot,tar_sdr.dir);
      break;
    }
  }
  void DoMove(TGabobTeam&team,bool sim)
  {
    DoMove(team,team.bullets.raws,sim);
    auto&units=team.units;
    for(int unit_id=0;unit_id<units.size();unit_id++)
    {
      auto&ex=units[unit_id];
      ex.clock.update();
      if(ex.need_help_tick){ex.need_help_tick--;}
      ex.phys.pos+=ex.phys.v;
      int w2=w/2-unit_radius;
      int h2=h/2-unit_radius;
      if(ex.phys.pos.x>+w2){ex.phys.pos.x=+w2;ex.phys.v.x=-abs(ex.phys.v.x);}
      if(ex.phys.pos.y>+h2){ex.phys.pos.y=+h2;ex.phys.v.y=-abs(ex.phys.v.y);}
      if(ex.phys.pos.x<-w2){ex.phys.pos.x=-w2;ex.phys.v.x=+abs(ex.phys.v.x);}
      if(ex.phys.pos.y<-h2){ex.phys.pos.y=-h2;ex.phys.v.y=+abs(ex.phys.v.y);}
    }
    QapCleanIf(units,[](TGabobUnit&ref){return ref.need_remove;});
  }
  void DoMove(vector<TGabobTeam>&teams,bool sim)
  {
    for(int i=0;i<teams.size();i++)
    {
      auto&ex=teams[i];
      DoMove(ex,sim);
    }
  }
public:
  void Init()
  {
    teams.resize(2);
    teams[0].name="red";
    teams[0].color=0xffffC040;
    teams[1].name="green";
    teams[1].color=0xff40ff40;
    income.interval=64*2+32;
  }
public:
  void BulletsVsUnits(vector<TGabobTeam>&teams,TGabobTeam&bullets_team,TGabobTeam&units_team,bool sim)
  {
    auto d=unit_radius+bullet_radius;
    d*=d;
    auto&arr=bullets_team.bullets.raws;
    for(int i=0;i<arr.size();i++)
    {
      auto&bullet=arr[i];
      if(bullet.need_remove)continue;
      for(int j=0;j<units_team.units.size();j++)
      {
        auto&unit=units_team.units[j];
        if(unit.need_remove)continue;
        bool ok=(unit.phys.pos-bullet.phys.pos).SqrMag()>d;
        if(ok)continue;
        if(&units_team==&bullets_team)
        {
          if(bullet.owner==unit.name)continue;
        }
        if(&bullets_team==&units_team)
        {
          bullets_team.unhits++;
        }
        bullet.need_remove=true;
        bullets_team.hits++;
        if(!sim)
        {
          auto*pref_exp=(no_expl_if_no_render&&no_render)||sim?nullptr:find_ref_explosion_by_name("bullet_die");
          if(pref_exp)
          {
            auto&back=qap_add_back(explosions.arr);
            back=*pref_exp;
            back.particle_beg_color=bullets_team.color;
            back.pos=bullet.phys.pos;
          }
        }
        auto bullet_owner=bullets_team.name+"."+bullet.owner;
        auto*pbullet_owner=find_unit_by_name(bullets_team,bullet.owner);
        if(pbullet_owner&&!pbullet_owner->need_remove)
        {
          pbullet_owner->total_hits++;
        }
        auto set_target=[&](const string&new_target)->void
        {
          if(sim)return;
          if(new_target.empty())return;
          if(unit.wait_new_target||!units_team.select_near_target||unit.target.empty())
          {
            unit.target=new_target;
            return;
          }
          auto*pnew_target=find_unit_by_full_name(teams,new_target);
          auto*pcur_target=find_unit_by_full_name(teams,unit.target);
          if(!pnew_target)return;
          if(!pcur_target)
          {
            unit.target=new_target;
            return;
          }
          auto cur_dist=(pcur_target->phys.pos-unit.phys.pos).Mag();
          auto new_dist=(pnew_target->phys.pos-unit.phys.pos).Mag();
          if(new_dist<cur_dist)
          {
            unit.target=new_target;
          }
        };
        if(&units_team!=&bullets_team)
        {
          set_target(bullet_owner);
        }else if(pbullet_owner&&!pbullet_owner->need_remove)
        {
          set_target(pbullet_owner->target);
        }
        unit.life--;
        if(!unit.life)
        {
          unit.need_remove=true;
          bullets_team.frags++;
          if(&units_team==&bullets_team)bullets_team.unfrags++;
          auto*pref_exp=(no_expl_if_no_render&&no_render)||sim?nullptr:find_ref_explosion_by_name("unit_die");
          if(pref_exp)
          {
            auto&back=qap_add_back(explosions.arr);
            back=*pref_exp;
            back.particle_beg_color=units_team.color;
            back.pos=unit.phys.pos;
          }
          if(pbullet_owner&&!pbullet_owner->need_remove)
          {
            pbullet_owner->frags++;
            pbullet_owner->life+=unit.frags;
            pbullet_owner->life+=life_for_fragger;
            pbullet_owner->frags_eat+=unit.frags;
            bullets_team.frags_eat+=unit.frags;
          }
        }
      }
    }
  }
  void TeamVsTeam(vector<TGabobTeam>&teams,TGabobTeam&a,TGabobTeam&b,bool sim)
  {
    BulletsVsUnits(teams,a,b,sim);
    BulletsVsUnits(teams,b,a,sim);
    for(int i=0;i<a.units.size();i++)
    {
      auto&unit_a=a.units[i];
      auto&arr=b.units;
      for(int j=0;j<arr.size();j++)
      {
        auto&unit_b=arr[j];
        bool ok=BallVsBall(unit_a.phys,unit_b.phys);
        if(ok)continue;
        unit_a.target=b.name+"."+unit_b.name;
        unit_b.target=a.name+"."+unit_a.name;
      }
      int gg=1;
    }
  }
  bool BallVsBall(TGabobPhys&a,TGabobPhys&b)
  {
    auto d=unit_radius*2;
    d*=d;
    auto&ap=a.pos;
    auto&bp=b.pos;
    auto&va=a.v;
    auto&vb=b.v;
    auto ab=bp-ap;
    if(ab.SqrMag()>=d)return true;
    auto v=vb-va;
    //auto ab_va=va.Rot(ab);
    auto ab_v=v.Rot(ab);
    auto old_x=ab_v.x;
    if(old_x>0)return false;
    auto ab_dv=ab_v;
    ab_dv.y=0;
    v=ab_dv.UnRot(ab);
    vb-=v;
    va+=v;
    //auto now_x=(vb-va).Rot(ab).x;
    //auto sum=now_x+old_x;
    //QapAssert(abs(sum)<0.00001);
    return false;
  }
  void Collide(vector<TGabobTeam>&teams,bool sim)
  {
    for(int i=0;i<teams.size();i++)
    {
      auto&team=teams[i];
      {
        auto&arr=team.units;
        for(int i=0;i<arr.size();i++)
        {
          auto&a=arr[i];
          for(int j=i+1;j<arr.size();j++)
          {
            auto&b=arr[j];
            BallVsBall(a.phys,b.phys);
          }
        }
      }
      for(int j=i+1;j<teams.size();j++)
      {
        auto&other_team=teams[j];
        TeamVsTeam(teams,team,other_team,sim);
      }
      BulletsVsUnits(teams,team,team,sim);
    }
  }
  void UpdateSelected(t_context&con)
  {
    if(no_update_selected)return;
    auto mpos=con.get_mpos();
    selected.clear();
    for(int i=0;i<teams.size();i++)
    {
      auto&team=teams[i];
      auto&units=team.units;
      for(int j=0;j<units.size();j++)
      {
        auto&unit=units[j];
        auto dist=(unit.phys.pos-mpos).Mag();
        if(dist>unit_radius)continue;
        selected.push_back(team.name+"."+unit.name);
      }
    }
    int gg=1;
  }
  void Update(t_context&con)
  {
    if(rec_play){
      rec_frame_id+=rec_play_dpos;return;
    }
    UpdateSelected(con);
    if(need_step){Step(con);need_step=false;}
    if(!no_update)for(int i=0;i<mpu;i++)Step(con);
  }
  void Step(t_context&con)
  {
    if(need_force_set_max_ang_diff)
    {
      info_max_ang_diff=info_max_ang_diff_force_value;
    }
    if(need_clear)
    {
      need_clear=false;
      for(int i=0;i<teams.size();i++)
      {
        auto&ex=teams[i];
        ex.units.clear();
        ex.bullets.raws.clear();
        ex.last_bullet_id=0;
        ex.last_unit_id=0;
        ex.shots=0;
        ex.hits=0;
        ex.frags=0;
        ex.unfrags=0;
        ex.frags_eat=0;
        ex.unhits=0;
      }
      explosions.arr.clear();
    }
    income.update();global_tick++;
    if(teams.empty())Init();
    if(income)
    {
      for(int i=0;i<teams.size();i++)
      {
        auto&ex=teams[i];
        {
          auto&back=qap_add_back(ex.units);
          back.name=IToS(ex.last_unit_id++);
          back.phys.pos=vec2d(rand()%(w-unit_radius*2),rand()%(h-unit_radius*2))-vec2d(w-unit_radius*2,h-unit_radius*2)*0.5;
          back.phys.v=Vec2dEx(RndReal(0,Pi2),RndReal(0,unit_speed));
          back.clock.rnd_reset();
        }
      }
    }
    if(rec_recording)for(;;)
    {
      if(!ReplaySys){ReplaySys.build<TGabobReplaySystem>(con.Env);rec_replay_id=0;rec_frame_id=0;}
      QapAssert(ReplaySys);
      auto&rs=*ReplaySys.get();
      if(rec_replay_id>=rs.arr.size()){QapDebugMsg("no way");break;}
      auto&replay=rs.arr[rec_replay_id];
      rec_name_cur=replay.name;
      if(rec_setname)replay.name=rec_name_new;
      auto&back=qap_add_back(replay.frames);
      TGabobReplayFrame frame;
      frame.teams=teams;
      frame.explosions=explosions.arr;
      back=TSimpleBinarySaver::toStr(con.Env,&frame);
      bool need_save=false;
      if(need_save)
      {
        file_put_contents("frame_from_gabob.bin",back);
        if(replay.frames.size()>1256)
        {
          vector<string> a;
          for(int i=1000;i<1256;i++){
            qap_add_back(a)=replay.frames[i];
          }
          file_put_contents("frame_from_gabob.bin",TSimpleBinarySaver::toStr(con.Env,&a));
        }
      }
      break;
    }
    Collide(teams,false);
    DoMove(teams,false);
    DoShots(teams,false);
    DoMove(explosions.arr);
  }
};

class TBookPageWithGabob:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithGabob)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<TGabobGame>,game,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithGabob
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithGabob
public:
  void Render(t_context&con)
  {
    if(!game)return;
    game->Render(con);
  }
  void Update(t_context&con)
  {
    if(!game)if(con.kb.Down[VK_RETURN]){game.build<TGabobGame>(con.Env);Caption="Gabob";}
    if(!game)return;
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::game);
      game->Update(con);
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
        F(TType)F(TBookPageWithGabob)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){
      srand(time(0));
    }
  };
  ThisCompileUnit ThisUnit;
}
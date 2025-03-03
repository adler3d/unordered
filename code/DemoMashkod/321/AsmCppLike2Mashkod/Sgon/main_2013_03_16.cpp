//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//

class TGUI_ContentRenderHolder:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_ContentRenderHolder)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TAutoPtr<IGUI_Content>,Content,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_ContentRenderHolder
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_ContentRenderHolder
public:
  static void SysHasSelf();
public:
};

class TGUIbject001:public IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUIbject001)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,c32,SET,32,$)\
ADDVAR(1,int,r,SET,0,$)\
ADDVAR(2,int,g,SET,0,$)\
ADDVAR(3,int,b,SET,0,$)\
ADDVAR(4,int,a,SET,255,$)\
ADDVAR(5,bool,NeedBindZeroTex,SET,true,$)\
ADDVAR(6,bool,NeedBindColor,SET,true,$)\
ADDVAR(7,bool,Visible,SET,true,$)\
ADDEND()
//=====+>>>>>TGUIbject001
#include "QapGenStruct.inl"
//<<<<<+=====TGUIbject001
public:
  virtual void Render(TRenderContext&Context){
    auto&qDev=Context.qDev;
    if(NeedBindZeroTex)qDev.BindTex(0,0);
    if(NeedBindColor)qDev.SetColor(QapColor(a,r,g,b));
    if(Visible)qDev.DrawTrigon(Context.pos+vec2d(0,+c32*0.5),Context.pos+vec2d(-c32*0.5,0),Context.pos+vec2d(+c32*0.5,0));
  }
  virtual void Update(TUpdateContext&Context){
    //Context.
  }
public:
  virtual void GetSize(vec2d&size){
    size=vec2d(c32,c32);
  }
};

class TSomeObject003:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeObject003)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(1,real,x,SET,0,$)\
ADDVAR(2,real,y,SET,0,$)\
ADDVAR(3,real,w,SET,10,$)\
ADDVAR(4,real,h,SET,10,$)\
ADDVAR(5,int,tick,SET,0,$)\
ADDVAR(10,real,speed,SET,1.0,$)\
ADDVAR(11,int,r,SET,0,$)\
ADDVAR(12,int,g,SET,0,$)\
ADDVAR(13,int,b,SET,0,$)\
ADDVAR(14,int,a,SET,255,$)\
ADDVAR(15,bool,NeedBindZeroTex,SET,true,$)\
ADDVAR(16,bool,NeedSetColor,SET,true,$)\
ADDVAR(20,bool,Enabled,SET,true,$)\
ADDVAR(21,bool,Visible,SET,true,$)\
ADDEND()
//=====+>>>>>TSomeObject003
#include "QapGenStruct.inl"
//<<<<<+=====TSomeObject003
public:
  void Render(QapDev&qDev)
  {
    if(!Visible)return;
    if(NeedBindZeroTex)qDev.BindTex(0,0);
    if(NeedSetColor)qDev.SetColor(QapColor(a,r,g,b));
    real t=real(tick)*(speed/365.0);
    qDev.DrawQuad(x+sin(t*3.14)*16,y,w,h,t);
  }
  void Update(IEnv&Env)
  {
    if(!Enabled)return;
    tick++;
  }
};


class TSomeObject004:public IRenderProgram{
public:
  class TPoint{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPoint)OWNER(TSomeObject004)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vec2d,p,SET,vec2d(0,0),$)\
    ADDVAR(1,vec2d,v,SET,vec2d(0,0),$)\
    ADDEND()
  //=====+>>>>>TPoint
  #include "QapGenStruct.inl"
  //<<<<<+=====TPoint
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(TPoint)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeObject004)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TPoint>,arr,DEF,$,$)\
ADDVAR(1,vector<vector<vec2d>>,history,DEF,$,$)\
ADDVAR(2,int,point_size,SET,8,$)\
ADDVAR(3,int,history_size,SET,16,$)\
ADDVAR(5,int,tick,SET,0,$)\
ADDVAR(8,int,x_init_speed,SET,0,$)\
ADDVAR(9,int,y_init_speed,SET,0,$)\
ADDVAR(10,int,speed,SET,1,$)\
ADDVAR(11,int,r,SET,255,$)\
ADDVAR(12,int,g,SET,128,$)\
ADDVAR(13,int,b,SET,0,$)\
ADDVAR(14,int,a,SET,255,$)\
ADDVAR(15,bool,NeedBindZeroTex,SET,true,$)\
ADDVAR(16,bool,NeedSetColor,SET,true,$)\
ADDVAR(17,bool,NeedRestart,SET,false,$)\
ADDVAR(20,bool,Enabled,SET,true,$)\
ADDVAR(21,bool,Visible,SET,true,$)\
ADDEND()
//=====+>>>>>TSomeObject004
#include "QapGenStruct.inl"
//<<<<<+=====TSomeObject004
public:
  void Render(QapDev&qDev)
  {
    if(!Visible)return;
    //if(NeedBindZeroTex)
    qDev.BindTex(0,0);
    if(NeedSetColor)qDev.SetColor(QapColor(a,r,g,b));
    if(true)
    {
      QapDev::BatchScope Scope(qDev);
      for(int j=0;j<history.size();j++)
      {
        auto&ex=history[j];
        real hh=history.size();
        real koef=Lerp<real>(0.1,0.5,1.0-abs(j-hh)/hh);
        int mega_id=history.size()-1;
        //real koef=Lerp<real>(0.1,0.5,1.0-abs(j-hh)/hh);
        //int mega_id=history.size()/2;
        for(int i=0;i<ex.size();i++)
        {
          //qDev.DrawQuad(arr[i].p.x,arr[i].p.y,point_size,point_size,0);
          if(j==mega_id)qDev.DrawCircle(ex[i],point_size,0,1,16);
          if(j==mega_id)qDev.DrawCircle(ex[i],point_size*0.5,0,4,16);
          if(j!=mega_id)qDev.DrawCircle(ex[i],point_size*koef,0,1,3);
        }
      }
      qDev.SetColor(0xff303030);
      qDev.DrawCircle(vec2d(0,0),380,0,1,64);
    }
  }
  bool GoSimulate()
  {
    real dist=(arr[0].p-arr[1].p).Mag();
    real treshold=0.01;
    bool flag=false;
    for(int i=0;i<1024;i++)
    {
      OneStep();
      real d=(arr[0].p-arr[1].p).Mag();
      if(abs(d-dist)>treshold)
      {
        flag=true;
        break;
      }
    }
    return flag;
  }
  bool GoSimulateB()
  {
    real dist=((arr[0].p+arr[1].p)-(arr[2].p+arr[3].p)).Mag()*0.5;
    real treshold=0.01;
    bool flag=false;
    for(int i=0;i<64*1024;i++)
    {
      OneStep();
      real d=((arr[0].p+arr[1].p)-(arr[2].p+arr[3].p)).Mag()*0.5;
      if(abs(d-dist)>treshold)
      {
        flag=true;
        break;
      }
    }
    return flag;
  }
  bool GoSimulateC(int*out_inter_count)
  {
    real dist=(arr[0].p-arr[1].p).Mag();
    real treshold=0.1;
    bool flag=false;
    for(int i=0;i<32*1024;i++)
    {
      OneStep();
      real d=(arr[0].p-arr[1].p).Mag();
      if(abs(d-dist)>treshold)
      {
        flag=true;
        if(out_inter_count)*out_inter_count=i;
        break;
      }
    }
    return flag;
  }
  void SetTwoBody(real d,real vy)
  {
    arr.clear();
    //AddTwoBody(64,0.057939052581787109);
    AddTwoBody(d,vy);
  }
  void SetTwoBodyB(real d,real vy)
  {
    arr.clear();
    AddTwoBody(64*0.5,0.057939052581787109);
    MoveTwoBody(vec2d(+d*0.5,0),vec2d(0,+vy));
    AddTwoBody(64*0.5,-0.057939052581787109);
    MoveTwoBody(vec2d(-d*0.5,0),vec2d(0,-vy));
  }
  void SetTwoBodyC(real d,real vy,real vy2)
  {
    arr.clear();
    AddTwoBody(d,-vy);
    AddTwoBody(50*0.5,vy2);
    arr[2].p=arr[2].p.Ort();
    arr[2].v=arr[2].v.Ort();
    arr[3].p=arr[3].p.Ort();
    arr[3].v=arr[3].v.Ort();
    AddTwoBody(50*0.5,vy2);
  }
  void AddTwoBody(real d,real vy)
  {
    int n=arr.size();
    arr.resize(n+2);
    arr[n+0].p=vec2d(-d,0);
    arr[n+0].v=vec2d(0,-vy);
    arr[n+1].p=vec2d(+d,0);
    arr[n+1].v=vec2d(0,+vy);
    //64*0.5,0.057939052581787109
    //164*0.5,0.064843252301216125
    //512*0.5,0.042185351252555847
  }
  void MoveTwoBody(vec2d dp,vec2d dv){
    int n=arr.size();
    arr[n-1].p+=dp;
    arr[n-1].v+=dv;
    arr[n-2].p+=dp;
    arr[n-2].v+=dv;
  }
  int RestartC_Sub(const real&d,real&vy,real vy2)
  {
    real delta=vy*0.5;
    vector<real> dist_log;
    int result_iter_count=0;
    if(true)
    {
      int old_iter_count=0;
      real old_vy=vy;
      for(int k=0;k<10;k++)
      {
        real min_val=vy-delta;
        real max_val=vy+delta;
        int count=8;
        vector<int> log;
        for(int j=0;j<count;j++)
        {
          vy=Lerp<real>(min_val,max_val,real(j)/real(count-1));
          SetTwoBodyC(d,+vy,vy2);
          int iter_count=0;
          bool result=!GoSimulateC(&iter_count);
          log.push_back(iter_count);
        }
        struct he{
          int id;
          bool used;
        };
        he res={0,0};
        for(int j=0;j<count;j++)
        {
          if(res.id==j)continue;
          res.used=res.used||(log[res.id]!=log[j]);
          if(log[res.id]<log[j]){
            res.id=j;
          }
        }
        delta=(max_val-min_val)/real(count);
        bool flag=log[res.id]>old_iter_count;
        if(flag)
        {
          vy=Lerp<real>(min_val,max_val,real(res.id)/real(count-1));
          result_iter_count=log[res.id];
          old_vy=vy;
          old_iter_count=log[res.id];
        }else{
          vy=old_vy;
          result_iter_count=old_iter_count;
        }
        if(!res.used)break;
      }
    }
    return result_iter_count;
  }
  void RestartC()
  {
    real d=512*0.5;
    if(0)
    {
      real vy=0.17118607461452484;
      real vy2=0.11515096575021744;
      //int iter_count=RestartC_Sub(d,vy,vy2);
      SetTwoBodyC(d,vy,vy2);
      return;
    }
    real vy=1.0;
    real vy2=1.0;
    real delta=vy2;
    int old_iter_count=0;
    real old_vy2=vy2;
    for(int k=0;k<12;k++)
    {
      real min_val=vy2-delta;
      real max_val=vy2+delta;
      int count=8;
      vector<int> log;
      for(int j=0;j<count;j++)
      {
        vy2=Lerp<real>(min_val,max_val,real(j)/real(count-1));
        int iter_count=0;
        iter_count=RestartC_Sub(d,vy,vy2);
        log.push_back(iter_count);
      }
      struct he{
        int id;
        bool used;
      };
      he res={0,0};
      for(int j=1;j<count;j++)
      {
        if(res.id==j)continue;
        res.used=res.used||(log[res.id]!=log[j]);
        if(log[res.id]<log[j]){
          res.id=j;
        }
      }
      delta=(max_val-min_val)/real(count);
      bool flag=log[res.id]>old_iter_count;
      if(flag)
      {
        vy2=Lerp<real>(min_val,max_val,real(res.id)/real(count-1));
        old_vy2=vy2;
        old_iter_count=log[res.id];
      }else{
        vy2=old_vy2;
      }
      if(!res.used)break;
    }
    SetTwoBodyC(d,vy,vy2);
  }
  void RestartB()
  {
    real d=512;
    real vy=1.0;
    real delta=vy*0.5;
    vector<real> dist_log;
    for(int i=0;i<128;i++)
    {
      SetTwoBodyB(d,vy);
      dist_log.push_back(vy);
      bool result=!GoSimulateB();
      if(result)break;
      //real m=(arr[0].p-arr[1].p).Mag();
      real m=((arr[0].p+arr[1].p)-(arr[2].p+arr[3].p)).Mag()*0.5;
      if(m<d)vy+=delta;
      if(m>d)vy-=delta;
      delta*=0.5;
    }
    SetTwoBodyB(d,vy);
  }
  void RestartA()
  {
    real d=100*0.5;
    real vy=1.0;
    real delta=vy*0.5;
    vector<real> dist_log;
    for(int i=0;i<128;i++)
    {
      SetTwoBody(d,vy);
      dist_log.push_back(vy);
      bool result=!GoSimulate();
      if(result)break;
      real m=(arr[0].p-arr[1].p).Mag()*0.5;
      if(m<d)vy+=delta;
      if(m>d)vy-=delta;
      delta*=0.5;
    }
    SetTwoBody(d,vy);
  }
public:
  struct t_three_conf{
    real dist;
    vec2d va,vb,vc;
    real&read_dip(int id,real&min_val,real&max_val)
    {
      real h=0.5;
      #define F(N,VAR,A,B)if(N==id){min_val=A;max_val=B;return this->VAR;}
      F(0,va.x,-0,+1);
      F(1,va.y,+0,+1);
      F(2,vb.x,-1,+0);
      F(3,vb.y,+0,+1);
      F(4,vc.x,-1,+1);
      F(5,vc.y,-1,+1);
      #undef F
      return *(real*)nullptr;
    }
    void set(int id,int value)
    {
      #define F(N,VAR,A,B)if(N==id){this->VAR=value;return;}
      F(0,va.x,-0,+1);
      F(1,va.y,+0,+1);
      F(2,vb.x,-1,+0);
      F(3,vb.y,+0,+1);
      F(4,vc.x,-1,+1);
      F(5,vc.y,-1,+1);
      #undef F
    }
  };
  void SetThreeBody(const t_three_conf&conf)
  {
    arr.resize(3);
    arr[0].p=vec2d(-conf.dist*0.5,0);
    arr[1].p=vec2d(+conf.dist*0.5,0);
    arr[2].p=vec2d(0,0);
    arr[0].v=conf.va;
    arr[1].v=conf.vb;
    arr[2].v=conf.vc;
  }
public:
  bool GoSimulateD(int&out_iter_count)
  {
    bool flag=false;
    for(int i=0;i<32*1024;i++)
    {
      bool IsCollide=false;
      OneStep(&IsCollide);
      if(IsCollide)
      {
        flag=true;
        out_iter_count=i;
        break;
      }
    }
    return flag;
  }
  void RestartD()
  {
    t_three_conf conf;
    conf.dist=512;
    TestQ(conf,6);
    SetThreeBody(conf);
  }
  int ExecD(const t_three_conf&conf)
  {
    SetThreeBody(conf);
    int iter_count=0;
    bool flag=GoSimulateD(iter_count);
    return iter_count;
  }
  int TestQ(t_three_conf&conf,int depth)
  {
    if(!depth){
      return ExecD(conf);
    }
    int id=depth-1;
    real q_min_val=0;
    real q_max_val=0;
    real&value=conf.read_dip(id,q_min_val,q_max_val);
    value=q_max_val;
    real delta=(q_max_val-q_min_val)*0.5;
    int old_iter_count=0;
    real old_value=value;
    for(int k=0;k<2;k++)
    {
      real min_val=value-delta;
      real max_val=value+delta;
      int count=5;
      vector<int> log;
      for(int j=0;j<count;j++)
      {
        value=Lerp<real>(min_val,max_val,real(j)/real(count-1));
        int iter_count=0;
        conf.set(id,value);
        iter_count=TestQ(conf,id);
        log.push_back(iter_count);
      }
      struct he{
        int id;
        bool used;
      };
      he res={0,0};
      for(int j=1;j<count;j++)
      {
        if(res.id==j)continue;
        res.used=res.used||(log[res.id]!=log[j]);
        if(log[res.id]<log[j]){
          res.id=j;
        }
      }
      delta=(max_val-min_val)/real(count);
      bool flag=log[res.id]>old_iter_count;
      if(flag)
      {
        value=Lerp<real>(min_val,max_val,real(res.id)/real(count-1));
        old_value=value;
        old_iter_count=log[res.id];
      }else{
        value=old_value;
      }
      if(!res.used)break;
    }
    return old_iter_count;
  }
public:
  void Restart()
  {
    NeedRestart=false;
    RestartA();
    //return;
    return;
    arr.clear();
    arr.resize(3);
    arr[0].p=vec2d(-200,-100);
    arr[1].p=vec2d(+200,+50);
    arr[2].p=vec2d(0,100);
    arr[2].v=vec2d(+x_init_speed*0.01,+y_init_speed*0.01);
    arr[0].v=vec2d(-x_init_speed*0.01,-y_init_speed*0.01);
  }
  void OneStep(bool*IsCollide=nullptr)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      vec2d sum=vec2d(0,0);
      {
        vec2d f=vec2d(0,0);
        for(int j=0;j<arr.size();j++)
        {
          if(j==i)continue;
          vec2d d=arr[j].p-ex.p;
          real dist=d.Mag();
          vec2d df=d.Norm()*(1.0/(dist*dist));
          real koef=2.0/1.0;
          f+=df*koef;
        }
        sum+=f;
      }
      {
        vec2d f=vec2d(0,0);
        for(int j=0;j<arr.size();j++)
        {
          if(j==i)continue;
          vec2d d=arr[j].p-ex.p;
          real dist=d.Mag();
          vec2d df=d.Norm()*(1.0/(dist*dist*dist));
          real koef=64.0/1.0;
          f-=df*koef;
        }
        if(IsCollide){
          *IsCollide=f.SqrMag()>sum.SqrMag();
        }
        sum+=f;
      }
      ex.p+=ex.v;
      ex.v+=sum;
      if(arr[i].p.Mag()>380)
      {
        ex.p=arr[i].p.SetMag(380);
        ex.v=vec2d(0,ex.v.Rot(ex.p).y*0.9).UnRot(ex.p);
      }
    }
    if(NeedBindZeroTex)FixPos();
  }
  void FixPos()
  {
    vec2d sum_v=vec2d(0,0);
    vec2d sum_p=vec2d(0,0);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      sum_v+=ex.v;
      sum_p+=ex.p;
    }
    sum_v*=1.0/real(arr.size());
    sum_p*=1.0/real(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.v-=sum_v;
      ex.p-=sum_p;
    }
  }
  void Update(IEnv&Env)
  {
    if(!Enabled)return;
    if(NeedRestart)Restart();
    for(int k=0;k<speed;k++){
      OneStep();if(!(k%32))UpdateHistory(); 
    }
    tick++;
  }
  void UpdateHistory()
  {
    {
      vector<vec2d> tmp;
      tmp.resize(arr.size());
      for(int i=0;i<arr.size();i++)tmp[i]=arr[i].p;
      history.push_back(tmp);
    }
    vector<vector<vec2d>> buff;
    buff=std::move(history);
    int c=std::min<int>(buff.size(),history_size);
    int offset=buff.size()-c;
    history.resize(c);
    for(int i=0;i<c;i++){
      history[i]=std::move(buff[i+offset]);
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
      //F(MeUnit4)F(QapTextSelectorV0)F(QapTextSelectorV1)
      //F(QapTextSelectorV3)F(QapTextSelectorV4)F(QapTextSelectorV4OnDown)
      //F(MeUnit20121009)F(TGUI_PanelOwner)F(TGUI_Content_Q3Text)F(TGUI_ContentHolder)
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)\
        F(TSomeObject003)F(TSomeObject004)F(TGUIbject001)F(TGUI_ContentRenderHolder)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    virtual void Run(IEnvRTTI&Env)
    {

    }
    ThisCompileUnit(){
      int df=0;
    }
  };
  ThisCompileUnit ThisUnit;
}
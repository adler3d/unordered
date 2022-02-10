//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//

class T2014wPtrItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T2014wPtrItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<SelfClass>,Next,DEF,$,$)\
ADDEND()
//=====+>>>>>T2014wPtrItem
#include "QapGenStruct.inl"
//<<<<<+=====T2014wPtrItem
public:
};

class TWeakPtrTest2014:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWeakPtrTest2014)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(T2014wPtrItem,a,DEF,$,$)\
ADDVAR(T2014wPtrItem,b,DEF,$,$)\
ADDVAR(T2014wPtrItem,c,DEF,$,$)\
ADDVAR(TWeakPtr<T2014wPtrItem>,head,DEF,$,$)\
ADDEND()
//=====+>>>>>TWeakPtrTest2014
#include "QapGenStruct.inl"
//<<<<<+=====TWeakPtrTest2014
public:
  void Render(QapDev&qDev)
  {
    qDev.BindTex(0,0);
    qDev.SetColor(QapColor(128,0,0,0));
    qDev.DrawCircle(vec2d(0,0),100,0,1,128);
  }
  void Update(IEnv&Env)
  {

  }
};

const QapColor d3dc[]={0xFF252525,0xFFFF0000,0xFF00FF00,0xFFFFFF00,
  0xFF0000FF,0xFFFF00FF,0xFF00FFFF,0xFFFFFFFF,0xFFFFFFA8,0xFFFFA8FF};

class t_game_t2d{
public:
  class Tank{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Tank)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vec2d,p,DEF,$,$)\
  ADDVAR(real,w,DEF,$,$)\
  ADDVAR(real,h,DEF,$,$)\
  ADDVAR(vec2d,v,DEF,$,$)\
  ADDVAR(vec2d,ta,DEF,$,$)\
  ADDVAR(vec2d,dir,DEF,$,$)\
  ADDVAR(int,BanTick,DEF,$,$)\
  ADDVAR(bool,deaded,DEF,$,$)\
  ADDVAR(bool,bot,DEF,$,$)\
  ADDVAR(bool,IsMotor,DEF,$,$)\
  ADDVAR(bool,IsTower,DEF,$,$)\
  ADDVAR(bool,IsEvil,DEF,$,$)\
  ADDVAR(bool,Crafty,DEF,$,$)\
  ADDVAR(vec2d,bas,DEF,$,$)\
  ADDVAR(vec2d,btar,DEF,$,$)\
  ADDVAR(real,bspe,DEF,$,$)\
  ADDVAR(int,EvilTick,DEF,$,$)\
  ADDEND()
  //=====+>>>>>Tank
  #include "QapGenStruct.inl"
  //<<<<<+=====Tank
  };
  class Bullet{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Bullet)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vec2d,p,DEF,$,$)\
  ADDVAR(vec2d,v,DEF,$,$)\
  ADDVAR(real,r,DEF,$,$)\
  ADDVAR(bool,deaded,DEF,$,$)\
  ADDVAR(int,dcount,DEF,$,$)\
  ADDEND()
  //=====+>>>>>Bullet
  #include "QapGenStruct.inl"
  //<<<<<+=====Bullet
  };
  class Brick{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Brick)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vec2d,p,DEF,$,$)\
  ADDVAR(bool,IsHome,DEF,$,$)\
  ADDVAR(bool,deaded,DEF,$,$)\
  ADDVAR(bool,undead,DEF,$,$)\
  ADDEND()
  //=====+>>>>>Brick
  #include "QapGenStruct.inl"
  //<<<<<+=====Brick
  };
  class Effect{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Effect)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(array(vec2d,16),p,DEF,$,$)\
  ADDVAR(array(vec2d,16),v,DEF,$,$)\
  ADDVAR(int,count,DEF,$,$)\
  ADDVAR(int,tc,DEF,$,$)\
  ADDVAR(int,t,DEF,$,$)\
  ADDVAR(bool,deaded,DEF,$,$)\
  ADDVAR(bool,isAdd,DEF,$,$)\
  ADDVAR(QapColor,Color,DEF,$,$)\
  ADDEND()
  //=====+>>>>>Effect
  #include "QapGenStruct.inl"
  //<<<<<+=====Effect
  };
  class TankGen{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TankGen)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vec2d,p,DEF,$,$)\
  ADDVAR(int,count,DEF,$,$)\
  ADDVAR(int,type,DEF,$,$)\
  ADDEND()
  //=====+>>>>>TankGen
  #include "QapGenStruct.inl"
  //<<<<<+=====TankGen
  };
  class t_counter{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_counter)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(int,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_counter
  #include "QapGenStruct.inl"
  //<<<<<+=====t_counter
  };
  class World{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(World)OWNER(t_game_t2d)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(bool,Enabled,SET,true,$)\
  ADDVAR(bool,AutoMove,SET,true,$)\
  ADDVAR(bool,AutoDraw,SET,true,$)\
  ADDVAR(bool,need_restart,DEF,$,$)\
  ADDVAR(vector<Tank>,tanks,DEF,$,$)\
  ADDVAR(vector<Tank>,dtanks,DEF,$,$)\
  ADDVAR(vector<Bullet>,bullets,DEF,$,$)\
  ADDVAR(vector<Bullet>,dbullets,DEF,$,$)\
  ADDVAR(vector<Brick>,bricks,DEF,$,$)\
  ADDVAR(vector<TankGen>,TGL,DEF,$,$)\
  ADDVAR(vector<Effect>,effects,DEF,$,$)\
  ADDVAR(vec2d,mpos,DEF,$,$)\
  ADDVAR(TWeakPtr<QapTex>,TexQuad,DEF,$,$)\
  ADDVAR(TWeakPtr<QapTex>,TexBall,DEF,$,$)\
  ADDVAR(TWeakPtr<QapKeyboard>,Keyboard,DEF,$,$)\
  ADDVAR(TWeakPtr<IProgramD3D9>,pd3d9,DEF,$,$)\
  ADDVAR(vector<t_counter>,counters,DEF,$,$)\
  ADDEND()
  //=====+>>>>>World
  #include "QapGenStruct.inl"
  //<<<<<+=====World
  public:
    static QapColor DeadColor(const QapColor&C)
    {
      struct RGBA{unsigned char R,G,B,A;};
      RGBA A=*(RGBA*)((void*)(&C));
      real c=0;c+=A.R;c+=A.G;c+=A.B;c*=0.33;c*=0.5;
      RGBA X={int(c),int(c),int(c),255};
      return *(QapColor*)((void*)(&X));
    }
    static QapColor SetColorAlpha(const QapColor&C,real kof)
    {
      struct RGBA{unsigned char B,G,R,A;};
      RGBA A=*(RGBA*)((void*)(&C));
      return QapColor(int(kof*255),A.R,A.G,A.B);
    }
    static bool NullSpeed(const vec2d&s){return s.Mag()<=1e-2;};
    static real Vec2dCompareAngle(vec2d a,vec2d b){return a.Rot(b).x;};
    static bool Vec2dTurn(vec2d &d,const vec2d&s,real boost=1.0)
    {
      static const double pi=4.0*std::atan(1.0);
      const real eps=1e-4; const real steep=pi*0.5*0.02*boost;
      real dA=Vec2dCompareAngle(d.Norm(),s.Norm());
      if(fabs(dA)<eps){return true;};
      real z=dA>=0?+1:-1;
      d=Vec2dEx(d.GetAng()+z*min(fabs(dA),steep),d.Mag());
      return false;
    }
    static real RNDReal(real MinVaue=0.0,real MaxValue=1.0)
    {
      return MinVaue+(real(rand())/real(RAND_MAX))*(MaxValue-MinVaue);
    }
  public:
    bool no_user()
    {
      auto&arr=tanks;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.bot)continue;
        return false;
      }
      return true;
    }
    Tank&get_user()
    {
      auto&arr=tanks;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.bot)continue;
        return ex;
      }
      for(int i=0;i<dtanks.size();i++)
      {
        auto&ex=dtanks[i];
        if(ex.bot)continue;
        return ex;
      }
      QapDebugMsg("wtf?");
      return *(Tank*)nullptr;
    }
  public:
    class t_world_renderer{
    public:
      #define F(TYPE)typedef t_game_t2d::TYPE TYPE;
      F(Tank);
      F(Bullet);
      F(Brick);
      F(Effect);
      F(TankGen);
      F(World);
      #undef F
    public:
      QapDev&qDev;
      World&world;
    public:
      template<class TYPE>
      void Do(vector<TYPE>&arr)
      {
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          Do(ex);
        }
      }
    public:
      void Do(Tank&ref)
      {
        QapColor*C=nullptr;
        QapColor ColorSet[]={d3dc[1],d3dc[ref.bot?2:4],d3dc[3],d3dc[7]};
        C=&ColorSet[0];
        C[1]=ref.IsEvil?d3dc[9]:C[1];
        C[0]=ref.Crafty?d3dc[9]:C[0];
        C[1]=ref.Crafty?d3dc[3]:C[1];
        C[2]=ref.Crafty?0xFFFF8800:C[2];
        QapColor DeadSet[4];for(int i=0;i<4;i++)DeadSet[i]=DeadColor(ColorSet[i]);
        C[3]=ref.IsTower?C[3]:DeadColor(C[3]);
        C[0]=ref.IsMotor?C[0]:DeadColor(C[0]);
        if(ref.IsEvil)ref.h=50;
        if(ref.deaded)C=DeadSet;
        //C[0]=DeadColor(C[0]);
        qDev.BindTex(0,world.TexQuad.get());
        //track
        qDev.SetColor(C[0]);
        vec2d p1=ref.p+vec2d(+20,0).UnRot(ref.dir);
        vec2d p2=ref.p+vec2d(-20,0).UnRot(ref.dir);
        qDev.DrawQuad(p1.x,p1.y,ref.Crafty?15.0:10,ref.h+10.0,ref.dir.GetAng());
        qDev.DrawQuad(p2.x,p2.y,ref.Crafty?15.0:10,ref.h+10.0,ref.dir.GetAng());
        //hull
        qDev.SetColor(C[1]);
        qDev.DrawQuad(ref.p.x,ref.p.y,ref.w,ref.h,ref.dir.GetAng());
        //muzzle
        qDev.SetColor(C[2]);
        vec2d taurd=ref.ta.UnRot(ref.dir);
        vec2d tmp=ref.p+vec2d(0.0,30.0).UnRot(taurd);
        qDev.DrawQuad(tmp.x,tmp.y,7.0,50,taurd.GetAng());
        //tower
        qDev.SetColor(C[3]);
        qDev.BindTex(0,world.TexBall.get());
        qDev.DrawQuad(ref.p.x,ref.p.y,30,30,ref.ta.GetAng());
        qDev.BindTex(0,nullptr);
        return;
        qDev.SetColor(0xffff8000);
        qDev.DrawCircle(ref.p,30,0,1,32);
      }
      void Do(Bullet&ref)
      {
        qDev.SetColor(ref.deaded?DeadColor(d3dc[7]):d3dc[7]);
        qDev.BindTex(0,world.TexBall.get());
        qDev.DrawQuad(ref.p.x,ref.p.y,ref.deaded?8.0:14.0,ref.deaded?8.0:6.0,ref.v.GetAng());
        qDev.BindTex(0,nullptr);
      }
      void Do(Brick&ref)
      {
        qDev.SetColor(d3dc[7]);
        if(ref.undead)qDev.SetColor(d3dc[6]); 
        qDev.DrawQuad(ref.p.x,ref.p.y,25.0,25.0,0);
        if(!ref.IsHome)return;
        qDev.SetColor(d3dc[3]);
        qDev.DrawCircle(ref.p,20,0,1,6);
      }
      void Do(Effect&ref)
      {
        real kof=real(ref.tc-ref.t)/real(ref.tc);
        qDev.BindTex(0,world.TexBall.get());
        qDev.SetColor(SetColorAlpha(ref.Color,kof<0.5?kof*2.0:1.0));
        if(ref.isAdd)qDev.SetBlendMode(QapDev::BlendType::BT_ADD);
        for(int i=0;i<ref.count;i++)
        {
          qDev.DrawQuad(ref.p[i].x,ref.p[i].y,7.0*kof,7.0*kof,0);
        }
        if(ref.isAdd)qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
        qDev.BindTex(0,nullptr);
      }
      void Do(TankGen&ref)
      {
        qDev.BindTex(0,nullptr);
        qDev.SetColor(d3dc[2]);
        qDev.DrawCircle(ref.p,20,0,1,16);
      }
      void Render()
      {
        if(!world.AutoDraw||!world.Enabled)return;
        transform2f old=qDev.GetTransform();
        if(!world.no_user())
        {
          transform2f ff=old;
          ff.p-=world.get_user().p;
          //ff.r=MakeZoomTransform(vec2d(1.0,1.0)*0.8).r;
          qDev.SetTransform(ff);
        }else{
          transform2f ff=old;
          ff.r=MakeZoomTransform(vec2d(1.0,1.0)*0.75).r;
          qDev.SetTransform(ff);
        }
        #define QUADRUN(X){qDev.BindTex(0,world.TexQuad.get());X;qDev.BindTex(0,nullptr);};
        Do(world.TGL);
        QUADRUN
        (
          Do(world.tanks);
          Do(world.dtanks);
        );
        Do(world.bullets);
        Do(world.dbullets);
        Do(world.effects);
        QUADRUN
        (
          Do(world.bricks);
        );
        #undef QUADRUN
        qDev.SetTransform(old);
      }
    };
    public:
      int&get_counter(const string&s,int def=0)
      {
        auto&arr=counters;
        arr.reserve(1024);
        for(int i=0;i<arr.size();i++)if(arr[i].name==s)return arr[i].value;
        t_counter tmp;
        tmp.name=s;
        tmp.value=def;
        arr.push_back(std::move(tmp));
        return arr.back().value;
      }
    public:
    class t_world_updater{
    public:
      #define F(TYPE)typedef t_game_t2d::TYPE TYPE;
      F(Tank);
      F(Bullet);
      F(Brick);
      F(Effect);
      F(TankGen);
      F(World);
      #undef F
    public:
      World&world;
    public:
      template<class TYPE>
      void Do(vector<TYPE>&arr)
      {
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          Do(ex);
        }
      }
      template<class TYPE>
      static void Clean(vector<TYPE>&arr)
      {
        int c=arr.size();
        int j=-1;
        for(int i=0;i<c;i++)
        {
          if(!arr[i].deaded&&i!=j)arr[++j]=std::move(arr[i]);
        }
        arr.resize(j+1);
      }
      template<class TYPE>
      static void MoveDeadedObjects(vector<TYPE>&arr,vector<TYPE>&darr)
      {
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          if(!ex.deaded)continue;
          darr.push_back(std::move(ex));
          ex=std::move(arr.back());
          arr.pop_back();
          i--;
        }
      }
    public:
      void Do(Tank&ref)
      {
        if(ref.bot)
        {
          if(ref.BanTick)
          {
            ref.BanTick--;
            if(!ref.BanTick)
            {
              ref.BanTick=rand()%128+128;
              ref.bas=vec2d(rand()%3-1,rand()%3-1);
              ref.bspe=0.10;
              int target_count=world.no_user()?4:5;
              if(rand()%target_count==5)
              {
                ref.btar=world.get_user().p;
              }else{ref.btar=ref.p+vec2d(rand()%3-1,rand()%3-1).SetMag(50.0+(rand()%1000)*1.0);};
            }
          }
          LookOn(ref,ref.btar);
          MoveToDir(ref,ref.bas,ref.bspe);
        };
        if(!NullSpeed(ref.v))ref.p+=ref.v;
        if(!NullSpeed(ref.v))
        {
          vec2d tmp=ref.v.Rot(ref.dir);
          tmp.x*=0.2;
          tmp.y*=0.95;
          ref.v=tmp.UnRot(ref.dir);
        }
      }
      void Do(Bullet&ref)
      {
        if(!NullSpeed(ref.v))ref.p+=ref.v;
        if(!NullSpeed(ref.v)&&ref.deaded)ref.v*=0.7;
        if(ref.deaded)ref.dcount++;
      }
      void Do(Brick&ref)
      {
        if(ref.undead)ref.deaded=false;
      }
      void Do(Effect&ref)
      {
        for(int i=0;i<ref.count;i++)ref.p[i]+=ref.v[i];
        if(!ref.deaded)ref.t++;
        if(ref.t==ref.tc)ref.deaded=true;
        ref.isAdd=false;
      }
      void Do(TankGen&ref)
      {
        //nothing
      }
      bool Down(const string&s)
      {
        if(!world.Keyboard)return false;
        auto&kb=*world.Keyboard.get();
        #define Bind(NAME,VALUE)if(s==NAME)return kb.Down[VALUE];
        Bind("up",VK_UP);
        Bind("down",VK_DOWN);
        Bind("left",VK_LEFT);
        Bind("right",VK_RIGHT);
        Bind("R",'R');
        Bind("C",'C');
        Bind("Shot",mbLeft);
        #undef Bind
        return false;
      }
      void SetDown(const string&s,bool flag)
      {
        
      }
      void DoUserControl()
      {
        if(world.no_user())return;
        auto&user=world.get_user();
        const real Speed=0.1;
        if(true)
        {
          auto&tick=world.get_counter("user_shot_tick",0);
          if(tick)tick--;
          if(Down("Shot"))
          {
            if(!tick){world.TankShot(user);tick=64;}
          }
        }
        vec2d as=vec2d(0,0);
        //bool CapCam=true;
        //vec2d CamPos=vec2d(0,0);
        //if(CapCam)CamPos=-user.p;
        if(Down("up")){as+=vec2d(0,+1);}
        if(Down("down")){as+=vec2d(0,-1);}
        if(Down("right")){as+=vec2d(+1,0);}
        if(Down("left")){as+=vec2d(-1,0);}
        MoveToDir(user,as,Speed);
        LookOn(user,world.mpos);
        if(Down("R")){user.IsMotor=true;user.IsTower=true;};
        //if(Down("C")){SetDown("C",false);CapCam=!CapCam;};
      }
      void DoEnemyShot()
      {
        for(int i=0;i<world.tanks.size();i++)
        {
          if(!world.tanks[i].IsEvil&&!world.tanks[i].Crafty)continue;
          world.TankShot(world.tanks[i]);
        }
        if(true)
        {
          auto&tick=world.get_counter("enemy_shot_tick",32);
          if(tick)tick--;
          if(!tick)for(;;)
          {
            tick=32;
            int c=world.tanks.size();
            bool ok=c>1;
            ok=ok||(world.no_user()&&c>0);
            if(!ok)break;
            int id=rand()%c;
            Tank&ref=world.tanks[id].bot?world.tanks[id]:world.tanks[(id+1)%c];
            world.TankShot(ref);
            break;
          }
        }
        int gg=1;
      }
      void DoTankGen()
      {
        auto&tag=world.get_counter("tank_gen_tick",0);
        if(tag%128==0)
        for(int i=0;i<world.TGL.size();i++)if(world.TGL[i].count)
        {
          int c=world.tanks.size()-1; 
          if(c<world.TGL.size())
          {
            auto&ex=world.NewTank();
            ex.p=world.TGL[i].p;
            world.TGL[i].count--;
            ex.IsEvil=world.TGL[i].type==1;
            ex.Crafty=world.TGL[i].type==2;
          }
        }
      }
      void Update()
      {
        if(!world.AutoMove||!world.Enabled)return;
        if(!world.pd3d9||!world.Keyboard)return;
        if(world.need_restart)
        {
          world.need_restart=false;
          world.tanks.clear();
          world.bullets.clear();
          world.effects.clear();
          world.bricks.clear();
          world.dbullets.clear();
          world.dtanks.clear();
          world.TGL.clear();
          auto&user=world.NewTank();
          user.bot=false;
          //CamZoom=10;
          bool undead=false;bool IsHome=false;
          #define ADDTANK(x,y){Tank&ex=world.NewTank();ex.p=vec2d(x,y);};
          #define AddBrick(x,y){auto&ex=world.NewBrick();ex.p=vec2d(x,y);ex.undead=undead;ex.IsHome=IsHome;}
          #define ADDTankGen(COUNT,X,Y,TYPE){TankGen ex;ex.p=vec2d(X,Y);ex.count=COUNT;ex.type=TYPE;world.TGL.push_back(std::move(ex));};
          #define ADDSCOPE(X,Y,S){\
            AddBrick(X-S,Y-S);AddBrick(X+S,Y+S);AddBrick(X+S,Y-S);AddBrick(X-S,Y+S);\
            AddBrick(X+0,Y-S);AddBrick(X+0,Y+S);AddBrick(X-S,Y+0);AddBrick(X+S,Y+0);\
          };
          #define ADDHOME(X,Y)ADDSCOPE(X,Y,35.0);ADDSCOPE(X,Y,70);IsHome=true;AddBrick(X,Y);IsHome=false;
          //for(int i=-2;i<2;i++){ADDTANK(40,20*i);}
          //ADDTankGen(Count,X,Y,TYPE)
          user.p=vec2d(+200,0);
          ADDHOME(200,+300);
          for(int i=-2;i<2;i++){ADDSCOPE(-350,-180*i,40);ADDTankGen(3,-350,-180*i,0);};
          //AddRegion(vec2d(10,10),10,0);
          undead=false;
          ADDSCOPE(+250,-250,50);
          undead=false;
          ADDTANK(+250,-250);
          for(int i=-15;i<15;i++){
            AddBrick(i*30,+15*30);
            AddBrick(i*30,-15*30);
            AddBrick(+15*30,i*30);
            AddBrick(-15*30,i*30);
            undead=abs(i-5)>2;
            if(i>-15)AddBrick(i*30,-100);
            undead=false;
          };
          for(int i=-16;i<16;i++){
            AddBrick(i*30,+16*30);
            AddBrick(i*30,-16*30);
            AddBrick(+16*30,i*30);
            AddBrick(-16*30,i*30);
          };
          for(int i=-17;i<17;i++){
            undead=true;
            AddBrick(i*30,+17*30);
            AddBrick(i*30,-17*30);
            AddBrick(+17*30,i*30);
            AddBrick(-17*30,i*30);
            undead=false;
          };
          #undef ADDHOME
          #undef AddBrick
          #undef ADDTANK
          #undef ADDTankGen
        }
        if(world.tanks.empty())return;
        if(!world.no_user())world.mpos=world.pd3d9->WindowGetMousePos()+world.get_user().p;
        DoUserControl();
        DoEnemyShot();
        DoTankGen();
        world.DoColide();
        Do(world.tanks);
        Do(world.dtanks);
        Do(world.bricks);
        Do(world.bullets);
        Do(world.dbullets);
        Do(world.effects);
        MoveDeadedObjects(world.tanks,world.dtanks);
        MoveDeadedObjects(world.bullets,world.dbullets);
        Clean(world.bricks);
        Clean(world.effects);
        for(int i=0;i<world.dbullets.size();i++)
        {
          if(world.dbullets[i].dcount<=64*15)continue;
          world.NewEffect(world.dbullets[i].p,0);
          world.dbullets[i]=world.dbullets.back();
          world.dbullets.pop_back();
          i--;
        }
      }
    };

    class t_world_collider{
    public:
      World&world;
    public:
      template<class TYPE_A,class TYPE_B>
      void go(vector<TYPE_A>&arr_a,vector<TYPE_B>&arr_b)
      {
        void*a=&arr_a;
        void*b=&arr_b;
        if(a==b)
        {
          auto&arr=arr_a;
          for(int i=0;i<arr.size();i++)for(int j=i+1;j<arr.size();j++)
          {
            auto&a=arr[i];
            auto&b=arr[j];
            Do(a,b);
          }
        }
        if(a!=b)
        {
          for(int i=0;i<arr_a.size();i++)for(int j=0;j<arr_b.size();j++)
          {
            auto&a=arr_a[i];
            auto&b=arr_b[j];
            Do(a,b);
          }
        }
      }
    public:
      static bool check_dist(const vec2d&a,const vec2d&b,real dist)
      {
        return (a-b).Mag()<dist;
      }
    public:
      void Do(Tank&a,Bullet&b)
      {
        const real dist=20.0;
        if(!check_dist(a.p,b.p,dist))return;
        vec2d d=b.p-a.p;
        real dm=d.Mag();
        if(b.deaded)
        {
          b.p+=d.SetMag((dist-dm)*0.95);
          a.p-=d.SetMag((dist-dm)*0.05);
          return;
        }
        a.v-=d.SetMag((dist-dm)*0.3);
        if(!a.deaded)
        {
          int rnd=rand()%2;
          bool&m=a.IsMotor;
          bool&t=a.IsTower;
          if(!m&&!t)a.deaded=true;
          if(rnd==0)if(m){m=false;}else{t=false;};
          if(rnd==1)if(t){t=false;}else{m=false;};
          if(rnd>=2)a.deaded=true;
        }
        b.deaded=true;
        world.NewEffect((a.p+b.p)*0.5,1);
      }
      void Do(Tank&a,Brick&b)
      {
        const real dist=30.0+10.0;
        if(!check_dist(a.p,b.p,dist))return;
        vec2d d=a.p-b.p;
        real dm=d.Mag();
        a.p+=d.SetMag((dist-dm)*0.5);
      }
      void Do(Brick&a,Bullet&b)
      {
        const real dist=20.0+0.0;
        if(!check_dist(a.p,b.p,dist))return;
        a.deaded=true;
        world.NewEffect(b.p,2);
        if(a.IsHome&&world.no_user())
        {
          //QapDebugMsg("user->deaded=true;");
          world.get_user().deaded=true;
        }
        b.deaded=true;
      }
      void Do(Tank&a,Tank&b)
      {
        const real dist=30.0*2.0;
        if(!check_dist(a.p,b.p,dist))return;
        vec2d d=a.p-b.p;
        real dm=d.Mag();
        a.p+=d.SetMag((dist-dm)*0.5);
        b.p-=d.SetMag((dist-dm)*0.5);
      }
      void Do(Bullet&a,Bullet&b)
      {
        const real dist=10.0;
        if(!check_dist(a.p,b.p,dist))return;
        if(a.deaded){a.dcount=100400;return;}
        if(b.deaded){b.dcount=100400;return;}
        a.v=vec2d(0,0);
        b.v=vec2d(0,0);
        a.deaded=true;
        b.deaded=true;
        world.NewEffect((a.p+b.p)*0.5,3);
      }
      void Do(Brick&a,Brick&b)
      {
        QapDebugMsg("not used, but need for linker");
      }
    };

    void DoColide()
    {
      t_world_collider WC={*this};
      WC.go(tanks,bullets);
      WC.go(dtanks,bullets);
      WC.go(tanks,bricks);
      WC.go(dtanks,bricks);
      WC.go(bricks,bullets);
      WC.go(tanks,tanks);
      WC.go(tanks,dtanks);
      WC.go(dtanks,dtanks);
      WC.go(bullets,bullets);
      WC.go(bullets,dbullets);
      WC.go(tanks,dbullets);
      WC.go(dtanks,dbullets);
    }

    Effect&NewEffect(const vec2d&pos,int mode)
    {
      Effect tmp;
      if(mode==0)Init(tmp,pos,d3dc[0],50);
      if(mode==1)Init(tmp,pos,d3dc[1],64*2,9);
      if(mode==2)Init(tmp,pos,d3dc[3],64*2,5);
      if(mode==3)Init(tmp,pos,DeadColor(d3dc[7]),64*2,5);
      if(mode==4)Init(tmp,pos,d3dc[5],64*1,7);
      //if(mode==4)A->Init(pos,DeadColor(d3dc[0]),64*2,5);
      effects.push_back(std::move(tmp));
      return effects.back();
    }

    static void Init(Effect&ref,const vec2d&c,const QapColor&col,int tickcount=64*2,int n=3)
    {
      static const double pi=4.0*std::atan(1.0);
      ref.Color=col;
      ref.deaded=false;
      ref.count=n;
      ref.tc=tickcount;
      ref.t=0;
      real rndAng=RNDReal(0,pi);
      for(int i=0;i<ref.count;i++)
      {
        ref.v[i]=Vec2dEx(rndAng+(real)i/(real)n*2.0*pi,RNDReal(0.5,1.0));
        ref.p[i]=c;
      }
    }

    static void Init(Tank&ref)
    {
      ref.w=40;
      ref.h=60;
      ref.p=vec2d(2,0);
      ref.v=vec2d(0.01,0);
      ref.ta=vec2d(-1,0);
      ref.dir=vec2d(1,0);
      ref.BanTick=1;
      ref.deaded=false;
      ref.bot=true;
      ref.IsMotor=true;
      ref.IsTower=true;
      ref.IsEvil=false;
      ref.EvilTick=128+rand()%128;
      ref.Crafty=false;
    }

    static void LookOn(Tank&ref,const vec2d&target)
    {
      if(ref.deaded)return;
      if(!ref.IsTower)return;
      Vec2dTurn(ref.ta,(ref.p-target).Rot(ref.dir));
    }

    static void MoveToDir(Tank&ref,const vec2d&as,real speed)
    {
      if(ref.deaded)return;
      if(!ref.IsMotor)return;
      if(NullSpeed(as))return;
      ref.v+=as.SetMag(speed);
      Vec2dTurn(ref.dir,ref.v,3.0);
    }

    static void Shot(const Tank&ref,vec2d&bpos,vec2d&bv)
    {
      bpos=ref.p+vec2d(0,40).UnRot(ref.ta.UnRot(ref.dir));
      bv=ref.ta.UnRot(-ref.dir).SetMag(-5.0).Ort();
    }
    void TankShot(Tank&ref)
    {
      if(ref.deaded)return;
      if(ref.IsEvil||ref.Crafty)
      {
        if(ref.EvilTick>=0){if(ref.Crafty)ref.EvilTick--;ref.EvilTick--;return;}else{ref.EvilTick=50;}
      }
      Bullet b;b.r=10; b.deaded=false;
      Shot(ref,b.p,b.v);
      b.dcount=0;
      bullets.push_back(std::move(b));
    }
    Tank&NewTank(){
      Tank tmp;
      Init(tmp);
      tanks.push_back(std::move(tmp));
      return tanks.back();
    }
    Brick&NewBrick()
    {
      Brick tmp;
      Init(tmp);
      bricks.push_back(std::move(tmp));
      return bricks.back();
    }
    static void Init(Brick&ref)
    {
      ref.deaded=false;
      ref.undead=false;
      ref.IsHome=false;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(Tank   )\
  F(Bullet )\
  F(Brick  )\
  F(Effect )\
  F(TankGen)\
  F(World  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_game_t2d)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_game_t2d
#include "QapGenStruct.inl"
//<<<<<+=====t_game_t2d
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_game_t2d::TYPE TYPE;
  //  F(Tank);
  //  F(Bullet);
  //  F(Brick);
  //  F(Effect);
  //  F(TankGen);
  //  F(World);
  //  #undef F
  //public:
  //  void Do(Tank&ref){}
  //  void Do(Bullet&ref){}
  //  void Do(Brick&ref){}
  //  void Do(Effect&ref){}
  //  void Do(TankGen&ref){}
  //  void Do(World&ref){}
  //};
};

class TGameTank2D2014:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameTank2D2014)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_game_t2d::World,world,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameTank2D2014
#include "QapGenStruct.inl"
//<<<<<+=====TGameTank2D2014
public:
  void Render(QapDev&qDev)
  {
    /*qDev.BindTex(0,0);
    qDev.SetColor(QapColor(128,0,0,0));
    qDev.DrawCircle(vec2d(0,0),100,0,1,3);*/
    t_game_t2d::World::t_world_renderer wr={qDev,world};
    wr.Render();
  }
  void Update(IEnv&Env)
  {
    t_game_t2d::World::t_world_updater wu={world};
    for(int i=0;i<2;i++)
    {
      wu.Update();
    }
  }
};

class GenBallTexObject:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(GenBallTexObject)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(QapTexMem,Mem,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(QapTexGen,Gen,DEF,$,$)\
ADDVAR(int,TexSize,SET,128,$)\
ADDEND()
//=====+>>>>>GenBallTexObject
#include "QapGenStruct.inl"
//<<<<<+=====GenBallTexObject
public:
  void SetToDef()
  {
    Gen.Mem=&Mem;
    Gen.Tex=&Tex;
  }
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!Mem);
      Mem.GenBall(TexSize);
      Tex.MountDev(*Env.pDev);
    }
    if(!Gen.Tex->Tex)Gen.Do();
  }
};

class GenQuadTexObject:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(GenQuadTexObject)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(QapTexMem,Mem,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(QapTexGen,Gen,DEF,$,$)\
ADDVAR(int,TexSize,SET,128,$)\
ADDEND()
//=====+>>>>>GenQuadTexObject
#include "QapGenStruct.inl"
//<<<<<+=====GenQuadTexObject
public:
  void SetToDef()
  {
    Gen.Mem=&Mem;
    Gen.Tex=&Tex;
  }
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!Mem);
      Mem.GenQuad(TexSize);
      Tex.MountDev(*Env.pDev);
    }
    if(!Gen.Tex->Tex)Gen.Do();
  }
};

class TResourceHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TResourceHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDEND()
//=====+>>>>>TResourceHolder
#include "QapGenStruct.inl"
//<<<<<+=====TResourceHolder
public:
};

class IResourceItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IResourceItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(vector<TWeakPtr<TResourceHolder>>,Holders,DEF,$,$)\
ADDEND()
//=====+>>>>>IResourceItem
#include "QapGenStruct.inl"
//<<<<<+=====IResourceItem
public:
  typedef QapResource::IEnv IEnv;
public:
  virtual void Do(IEnv&Env)
  {
    
  }
  void Run(IEnvRTTI&Env,QapD3DDev9*pDev)
  {
    if(!pDev)return;
    IEnv env={Env,pDev};
    Do(env);
  }
};

class TResourceScope:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TResourceScope)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(vector<TAutoPtr<IResourceItem>>,items,DEF,$,$)\
ADDVAR(bool,need_collect,DEF,$,$)\
ADDEND()
//=====+>>>>>TResourceScope
#include "QapGenStruct.inl"
//<<<<<+=====TResourceScope
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    items.resize(items.size()+1);
    return items.back().build<TYPE>(Env);
  }
public:
  void Do(IEnv&Env)
  {
    auto&arr=items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*ptr=ex.get();
      ptr->Do(Env);
    }
  }
  void Update(IEnvRTTI&Env)
  {
    if(!need_collect)return;
    need_collect=false;
    auto&arr=items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto&holders=ex->Holders;
      QapClean(holders);
      if(!holders.empty())continue;
      ex=nullptr;
    }
    QapClean(arr);
  }
};

class TDay20140518Main;

class IDay20140518Item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IDay20140518Item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDEND()
//=====+>>>>>IDay20140518Item
#include "QapGenStruct.inl"
//<<<<<+=====IDay20140518Item
public:
  struct t_context{
    IEnvRTTI&Env;
    QapRenderProgram&qrp;
    IProgramD3D9&pd3d9;
    QapKeyboard&kb;
    QapDev&qDev;
    TResourceScope&rScope;
    TDay20140518Main&main;
  };
  virtual void Render(t_context&con){}
  virtual void Update(t_context&con){}
};

class TDay20140518Node:public IDay20140518Item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140518Node)PARENT(IDay20140518Item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<IDay20140518Item>>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140518Node
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140518Node
public:
  void Render(t_context&con)
  {
    if(items.empty())return;
    int gg=1;
    for(int i=0;i<items.size();i++)
    {
      auto&ex=items[i];
      if(!ex)continue;
      auto*ptr=ex.get();
      if(!ptr->Enabled)continue;
      if(!ptr->Visible)continue;
      ptr->Render(con);
    }
  }
  void Update(t_context&con)
  {
    if(items.empty())return;
    int gg=1;
    for(int i=0;i<items.size();i++)
    {
      auto&ex=items[i];
      if(!ex)continue;
      auto*ptr=ex.get();
      if(!ptr->Enabled)continue;
      if(!ptr->Moved)continue;
      ptr->Update(con);
    }
  }
};

class TDay20140518Main:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140518Main)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<QapRenderProgram>,qrp,DEF,$,$)\
ADDVAR(TDay20140518Node,Root,DEF,$,$)\
ADDVAR(TWeakPtr<TResourceScope>,ResScope,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140518Main
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140518Main
public:
  void Render(QapDev&qDev)
  {
    if(!qrp)return;
    auto*pQrp=qrp.get();
    if(!pQrp->Program)return;
    if(!ResScope)return;
    auto*pd3d9=pQrp->Program.get();
    IDay20140518Item::t_context con={
      *(IEnvRTTI*)nullptr,
      *pQrp,
      *pd3d9,
      pd3d9->GetKeyBoard(),
      qDev,
      *ResScope.get(),
      *this
    };
    if(Root.Enabled&&Root.Visible)Root.Render(con);
  }
  void Update(IEnv&Env)
  {
    if(!qrp)return;
    auto*pQrp=qrp.get();
    if(!pQrp->Program)return;
    if(!ResScope)
    {
      auto*pResScope=pQrp->ResList.AddItem<TResourceScope>(Env.Env);
      ResScope=pResScope;
    }
    auto*pd3d9=pQrp->Program.get();
    IDay20140518Item::t_context con={
      Env,
      *pQrp,
      *pd3d9,
      pd3d9->GetKeyBoard(),
      pQrp->qDev,
      *ResScope.get(),
      *this
    };
    if(Root.Enabled&&Root.Moved)Root.Update(con);
    if(!ResScope)return;
    auto*pResScope=ResScope.get();
    pResScope->Update(Env.Env);
  }
};

class TResItemGenTexObject:public IResourceItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TResItemGenTexObject)PARENT(IResourceItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapTexFile,File,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(QapTexGen,Gen,DEF,$,$)\
ADDEND()
//=====+>>>>>TResItemGenTexObject
#include "QapGenStruct.inl"
//<<<<<+=====TResItemGenTexObject
public:
  void SetToDef()
  {
    Gen.Mem=&File.Mem;
    Gen.Tex=&Tex;
  }
  struct t_fn_parser{
    string fn;
    string func;
    string size;
    int value;
    bool main()
    {
      if(fn.empty())return false;
      if(fn[0]!='?')return false;
      int e=0;
      func=ScanParam("?",fn,"(",e);
      if(e<0)return false;
      e+=func.size()+string("(").size();
      size=ScanParam("",fn,")",e);
      if(e<0)return false;
      value=SToI(size);
      return true;
    }
  };
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!File.Mem);
      for(;;)
      {
        t_fn_parser parser;
        parser.fn=File.FN;
        if(parser.main())
        {
          if(parser.func=="GenBall"){File.Mem.GenBall(parser.value);break;}
          if(parser.func=="GenQuad"){File.Mem.GenQuad(parser.value);break;}
          QapDebugMsg("texmem.func not found: "+parser.func+"\nFile.FN:\n"+File.FN);
          break;
        }
        File.Load();
        break;
      }
      Tex.MountDev(*Env.pDev);
    }
    if(!Gen.Tex->Tex)Gen.Do();
  }
};

class TDay20140518TestV00:public IDay20140518Item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140518TestV00)PARENT(IDay20140518Item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResItem,DEF,$,$)\
ADDVAR(TWeakPtr<TResItemGenTexObject>,pTexGen,DEF,$,$)\
ADDVAR(bool,need_init,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vector<vec2d>,points,DEF,$,$)\
ADDVAR(real,size,SET,64.0,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDVAR(bool,DrawQuadAtMPos,SET,true,$)\
ADDEND()
//=====+>>>>>TDay20140518TestV00
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140518TestV00
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    qDev.SetColor(color);
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.DrawCircle(pos,size,0,1,16);
    if(pTexGen)
    {
      qDev.BindTex(0,&pTexGen->Tex);
    }
    qDev.BeginBatch();
    qDev.DrawPolyLine(points,3,false);
    for(int i=0;i<points.size();i++)qDev.DrawQuad(points[i].x+0.5,points[i].y+0.5,16,16,0);
    qDev.EndBatch();
    auto mpos=pd3d9.WindowGetMousePos();
    if(DrawQuadAtMPos)
    {
      qDev.DrawQuad(mpos.x,mpos.y,16,16);
    }
    qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto mpos=pd3d9.WindowGetMousePos();
    {
      if(kb.Down[mbLeft]&&kb.Changed[mbLeft])
      {
        bool ok=true;
        for(int i=0;i<points.size();i++)
        {
          if((points[i]-mpos).Mag()*2<(16+16))
          {
            ok=false;
            points[i]=mpos;
          }
        }
        if(ok)points.push_back(mpos);
      }
      if(kb.Down[mbLeft]&&!kb.Changed[mbLeft])
      {
        for(int i=0;i<points.size();i++)
        {
          if((points[i]-mpos).Mag()*2<(16+16))
          {
            points[i]=mpos;
          }
        }
      }
    }
    if(!need_init)return;
    need_init=false;
    auto*p=con.rScope.AddItem<TResItemGenTexObject>(con.Env);
    if(pTexGen){
      ResItem=std::move(TResourceHolder());
      pTexGen=nullptr;
    }
    pTexGen=p;
    p->Holders.push_back(&ResItem);
    ResItem.Caption="TResItemGenTexObject";
    p->SetToDef();
    p->File.FN="?GenBall(128)";
    p->Run(con.Env,&con.pd3d9.D9Dev);
  }
};

class TResItemFontObject:public IResourceItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TResItemFontObject)PARENT(IResourceItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapFont,Font,DEF,$,$)\
ADDVAR(QapFontGen,FontGen,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(QapTexGen,TexGen,DEF,$,$)\
ADDEND()
//=====+>>>>>QapFontObject
#include "QapGenStruct.inl"
//<<<<<+=====QapFontObject
public:
  void SetToDef()
  {
    FontGen.Font=&Font;
    TexGen.Mem=&Font.Mem;
    TexGen.Tex=&Tex;
  }
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!Font.Mem);
      HWND hWnd=Env.pDev->PresParams.pp.hDeviceWindow;
      FontGen.Do(hWnd);
      Tex.MountDev(*Env.pDev);
    }
    if(!TexGen.Tex->Tex)TexGen.Do();
  }
};

class TDay20140518TestText:public IDay20140518Item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140518TestText)PARENT(IDay20140518Item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResItem,DEF,$,$)\
ADDVAR(TWeakPtr<TResItemFontObject>,pFontGen,DEF,$,$)\
ADDVAR(bool,need_init,DEF,$,$)\
ADDVAR(bool,half_x,DEF,$,$)\
ADDVAR(bool,half_y,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDVAR(bool,at_go,DEF,$,$)\
ADDVAR(bool,at_nm,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140518TestText
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140518TestText
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    auto old=qDev.GetAlphaMode();
    qDev.SetAlphaMode(QapDev::AlphaType::AM_NONE);
    if(at_go)
      qDev.SetAlphaMode(QapDev::AlphaType::AM_GEQUAL_ONE);
    if(at_nm)
      qDev.SetAlphaMode(QapDev::AlphaType::AM_NEQUAL_MAX);
    //qDev.BindTex(0,nullptr);
    if(pFontGen)
    {
      qDev.BindTex(0,nullptr);
      qDev.SetColor(0xffffffff);
      auto&font=pFontGen->Font;
      int L=QapQ3Text::GetLength(font,text);
      vec2d p=pos+vec2d(half_x?1:0,half_y?1:0)*0.5;
      qDev.DrawQuad(p.x+L/2.0+5,p.y,L+10,50,0);
      qDev.BindTex(0,&pFontGen->Tex);
      qDev.SetColor(color);
      QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),text);
    }
    qDev.BindTex(0,0);
    qDev.SetAlphaMode(old);
  }
  void Update(t_context&con)
  {
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto mpos=pd3d9.WindowGetMousePos();

    if(!need_init)return;
    text="Some text";
    need_init=false;
    auto*p=con.rScope.AddItem<TResItemFontObject>(con.Env);
    if(pFontGen){
      ResItem=std::move(TResourceHolder());
      pFontGen=nullptr;
    }
    pFontGen=p;
    p->Holders.push_back(&ResItem);
    ResItem.Caption="TResItemFontObject";
    p->SetToDef();
    p->FontGen.Name="Consolas";
    p->FontGen.Size=16;
    p->Run(con.Env,&con.pd3d9.D9Dev);
  }
};

class TDay20140601BookV00;
class TDay20140601Book;

class IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDVAR(bool,NeedRemove,DEF,$,$)\
ADDEND()
//=====+>>>>>IBookPage
#include "QapGenStruct.inl"
//<<<<<+=====IBookPage
public:
  struct t_context{
    IEnvRTTI&Env;
    QapRenderProgram&qrp;
    IProgramD3D9&pd3d9;
    QapKeyboard&kb;
    QapDev&qDev;
    TResourceScope&rScope;
    TDay20140518Main&main;
    TDay20140601BookV00&root;
    TDay20140601Book&book;
    vec2d pos;
    vec2d size;
    vector<TDay20140601Book*>&path;
    template<int>
    vec2d weak_get_mpos()
    {
      return pd3d9.WindowGetMousePos()-pos;
    }
    vec2d get_mpos()
    {
      return weak_get_mpos<0>();
    }
    template<int>
    bool weak_is_root_book()
    {
      return &root.book==&book;
    }
    bool is_root_book()
    {
      return weak_is_root_book<0>();
    }
    template<int>
    TResItemFontObject*weak_get_root_book_fontgen()
    {
      return root.book.pFontGen.get();
    }
    TResItemFontObject*get_root_book_fontgen()
    {
      return weak_get_root_book_fontgen<0>();
    }
  };
  virtual void Render(t_context&con){}
  virtual void Update(t_context&con){}
};

#include "GeomTools.h"

class TDay20140601Book{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140601Book)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResItem,DEF,$,$)\
ADDVAR(TWeakPtr<TResItemFontObject>,pFontGen,DEF,$,$)\
ADDVAR(bool,AutoInitIfItIsRootBook,SET,true,$)\
ADDVAR(bool,CopyFontGenFromRootBook,SET,true,$)\
ADDVAR(bool,need_init,DEF,$,$)\
ADDVAR(int,head_border_size,SET,4,$)\
ADDVAR(int,border_size,SET,2,$)\
ADDVAR(QapColor,border_color,DEF,$,$)\
ADDVAR(int,page_id,DEF,$,$)\
ADDVAR(vector<TAutoPtr<IBookPage>>,pages,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140601Book
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140601Book
public:
  typedef IBookPage::t_context t_context;
public:
  static void DrawBorder(QapDev&qDev,const vec2d&pos,const vec2d&size,real ls)
  {
    vec2d bsize=size*0.5+vec2d(1,1)*ls*0.5;
    //qDev.DrawPolyLine(MakeQuadAABB(pos-bsize,pos+bsize),ls,true);
    qDev.DrawRect(pos-bsize,pos+bsize,ls);
  }
  struct t_book_info
  {
    vec2d body_pos;
    vec2d body_size;
    vec2d header_pos;
    vec2d header_size;
  };
  t_book_info get_header_info(const vec2d&pos,const vec2d&size)
  {
    t_book_info tmp;
    if(!pFontGen)return tmp;
    auto&font=pFontGen->Font;
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy*0.5;
    int hbs=head_border_size;
    auto&arr=pages;
    //vec2d curpos=pos+vec2d(-size.x,+size.y)*0.5+vec2d(0,border_size);
    //tmp.body_pos=curpos;
    tmp.header_size=vec2d(size.x,border_size+hbs+cy+hbs);
    tmp.header_pos=pos+vec2d(-size.x+tmp.header_size.x,+size.y-tmp.header_size.y)*0.5;
    tmp.body_pos=pos+vec2d(0,-tmp.header_size.y*0.5);
    tmp.body_size=size-vec2d(border_size*2.0,tmp.header_size.y+border_size*2.0);
    return tmp;
  }
  void DrawOldText(QapDev&qDev,const string&text,const vec2d&pos)
  {
    if(!pFontGen)return;
    qDev.BindTex(0,nullptr);
    auto&font=pFontGen->Font;
    //string text="TDay20140601Book";
    int L=QapQ3Text::GetLength(font,text);
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy*0.5;
    vec2d p=pos+vec2d(-L/2.0,-cy);
    qDev.SetColor(0xffffffff);
    qDev.DrawQuad(p.x+L/2.0,p.y,L,cy,0);
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y+hcy),text);
  }
  void DrawHeader(QapDev&qDev,const vec2d&mpos,const vec2d&pos,const vec2d&size)
  {
    if(!pFontGen)return;
    auto&font=pFontGen->Font;
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy*0.5;
    int hbs=head_border_size;
    auto&arr=pages;
    vec2d curpos=pos+vec2d(-size.x,+size.y)*0.5+vec2d(0,border_size);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*ptr=ex.get();
      string text=ptr->Caption;
      //
      int L=QapQ3Text::GetLength(font,text);
      vec2d s=vec2d(L+hbs+hbs,hbs+hbs+cy);
      vec2d p=curpos+s*0.5;
      //
      bool ok=CD_Rect2Point(p-s*0.5,p+s*0.5,mpos);
      /*if(ok){
        string c="^7";
        text=c+"[^3"+text+c+"]";
      }else{
        string c="^1.";
        text=c+"^3"+text+c;
      }*/
      //DrawTextBackground(text);
      qDev.SetColor(border_color);
      qDev.BindTex(0,nullptr);
      DrawBorder(qDev,p,s,border_size);
      //DrawText(Text);
      qDev.SetColor(ok?0xE0ffffff:0x80ffffff);
      if(page_id==i){
        qDev.SetColor(0xffffffff);
      }
      qDev.DrawQuad(p.x,p.y,L,cy,0);
      qDev.BindTex(0,&pFontGen->Tex);
      qDev.SetColor(0xff000000);
      QapQ3Text::DrawQapText(&qDev,font,int(p.x-L*0.5),int(p.y+hcy),text);
      //
      curpos.x+=s.x+border_size;
    }
  }
  void DoDrawPageContent(t_context&con)
  {
    #define F(COND)if(COND){DrawOldText(con.qDev,"detected: "#COND,con.pos);return;}
    F(pages.empty());
    F(page_id<0);
    F(page_id+1>pages.size());
    F(!pages[page_id]);
    #undef F
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      con.root,
      *this,
      con.pos,
      con.size,
      con.path
    };
    auto*ptr=pages[page_id].get();
    ptr->Render(context);
  }
  void DoSelectPage(t_context&con)
  {
    if(!pFontGen)return;
    if(!con.kb.Down[mbLeft])return;
    if(!con.kb.Changed[mbLeft])return;
    auto&font=pFontGen->Font;
    auto mpos=con.pd3d9.WindowGetMousePos();
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy*0.5;
    int hbs=head_border_size;
    auto&arr=pages;
    vec2d curpos=con.pos+vec2d(-con.size.x,+con.size.y)*0.5+vec2d(0,border_size);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*ptr=ex.get();
      string text=ptr->Caption;
      //
      int L=QapQ3Text::GetLength(font,text);
      vec2d s=vec2d(L+hbs+hbs,hbs+hbs+cy);
      vec2d p=curpos+s*0.5;
      //
      bool ok=CD_Rect2Point(p-s*0.5,p+s*0.5,mpos);
      if(ok)
      {
        page_id=i;
        return;
      }
      //
      curpos.x+=s.x+border_size;
    }
  }
  void DoMovePageContent(t_context&con)
  {
    #define F(COND)if(COND)return;
    F(pages.empty());
    F(page_id<0);
    F(page_id+1>pages.size());
    F(!pages[page_id]);
    #undef F
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      con.root,
      *this,
      con.pos,
      con.size,
      con.path
    };
    auto*ptr=pages[page_id].get();
    ptr->Update(context);
  }
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto mpos=pd3d9.WindowGetMousePos();
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.SetColor(border_color);
    DrawBorder(qDev,con.pos,con.size,border_size);
    DrawHeader(qDev,mpos,con.pos,con.size);
    DoDrawPageContent(con);
    //DrawOldText(qDev);
    qDev.BindTex(0,0);
  }
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    pages.resize(pages.size()+1);
    return pages.back().build<TYPE>(Env);
  }
  template<int>
  void InitPages(IEnvRTTI&Env)
  {
    {auto*p=AddItem<TBookPageV00>(Env);p->Caption="Page00";p->text="text on page 01";}
    {auto*p=AddItem<TBookPageV00>(Env);p->Caption="Page01";p->text="book system is real good.";}
  }
  void DoClean()
  {
    QapCleanIf(pages,[](TAutoPtr<IBookPage>&ref){return ref&&ref->NeedRemove;});
  }
  void Update(t_context&con)
  {
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto mpos=pd3d9.WindowGetMousePos();
    DoSelectPage(con);
    DoMovePageContent(con);
    DoClean();
    if(!pFontGen&&AutoInitIfItIsRootBook)if(con.is_root_book())
    {
      need_init=true;
    }
    if(!pFontGen&&CopyFontGenFromRootBook){pFontGen=con.get_root_book_fontgen();}
    if(!need_init)return;
    need_init=false;
    InitPages<0>(con.Env);
    auto*p=con.rScope.AddItem<TResItemFontObject>(con.Env);
    if(pFontGen){
      ResItem=std::move(TResourceHolder());
      pFontGen=nullptr;
    }
    pFontGen=p;
    p->Holders.push_back(&ResItem);
    ResItem.Caption="TResItemFontObject";
    p->SetToDef();
    p->FontGen.Name="FixedSys";
    p->FontGen.Size=10;
    p->Run(con.Env,&con.pd3d9.D9Dev);
  }
};

class TRawRect{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRawRect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2d,point_offset,DEF,$,$)\
ADDVAR(bool,fixed,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,w,SET,128.0,$)\
ADDVAR(real,h,SET,64.0,$)\
ADDVAR(int,border_size,SET,10,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(QapColor,quad_color,SET,QapColor(80,128,128,0),$)\
ADDVAR(QapColor,rect_color,DEF,$,$)\
ADDVAR(QapColor,border_color,SET,QapColor(0,128,0),$)\
ADDVAR(bool,draw_quad,DEF,$,$)\
ADDVAR(bool,draw_rect,SET,true,$)\
ADDVAR(bool,draw_points,SET,true,$)\
ADDEND()
//=====+>>>>>TRawRect
#include "QapGenStruct.inl"
//<<<<<+=====TRawRect
public:
  typedef IBookPage::t_context t_context;
public:
  vec2d get_size()const{return vec2d(w,h);}
  static void DrawRect(QapDev&qDev,const vec2d&a,const vec2d&b,const QapColor&color,int line_size)
  {
    qDev.SetColor(color);
    qDev.DrawRect(a,b,line_size);
  }
  vector<vec2d> get_arr(const vec2d&offset)
  {
    vec2d hs=vec2d(w,h)*0.5;
    return MakeQuadAABB(offset+pos-hs,offset+pos+hs);
  }
  void RenderBack(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vec2d p=vec2d(1,1)*0.5+pos+bpos;
    vec2d s=vec2d(w,h)*0.5;
    vec2d b=vec2d(1,1)*border_size;
    if(draw_quad){qDev.SetColor(quad_color);qDev.DrawQuad(p.x,p.y,w,h,0);}
  }
  void RenderBorder(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vec2d p=vec2d(1,1)*0.5+pos+bpos;
    vec2d s=vec2d(w,h)*0.5;
    vec2d b=vec2d(1,1)*border_size;
    if(draw_rect)DrawRect(qDev,p-s,p+s,rect_color,line_size);
  }
  void RenderPoints(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vec2d p=vec2d(1,1)*0.5+pos+bpos;
    vec2d s=vec2d(w,h)*0.5;
    vec2d b=vec2d(1,1)*border_size;
    static const vec2d koef[]={
      vec2d(-1,-1),
      vec2d(+1,-1),
      vec2d(+1,+1),
      vec2d(-1,+1),
      vec2d(-1,00),
      vec2d(+1,00),
      vec2d(00,-1),
      vec2d(00,+1)
    };
    if(draw_points)for(int cur_id=0;cur_id<lenof(koef);cur_id++)
    {
      auto&kx=koef[cur_id].x;
      auto&ky=koef[cur_id].y;
      vec2d pos=p+vec2d(s.x*kx,s.y*ky);
      DrawRect(qDev,pos-b,pos+b,border_color,line_size);
    }
    qDev.BindTex(0,nullptr);
  }
  void Render(t_context&con)
  {
    RenderBack(con);
    RenderBorder(con);
    RenderPoints(con);
  }
  void UpdateEx(t_context&con,const vec2d&hp,const vec2d&hs)
  {
    Update(con,&hp,&hs);
  }
  void Update(t_context&con,const vec2d*php=nullptr,const vec2d*phs=nullptr)
  {
    if(fixed)return;
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto hsize=con.size*0.5;
    auto mpos=con.get_mpos();
    static const vec2d koef[]={
      vec2d(-1,-1),
      vec2d(+1,-1),
      vec2d(+1,+1),
      vec2d(-1,+1),
      vec2d(-1,00),
      vec2d(+1,00),
      vec2d(00,-1),
      vec2d(00,+1)
    };
    if(CD_Rect2Point(-hsize,+hsize,mpos))
    {
      bool d=kb.Down[mbLeft];
      bool c=kb.Changed[mbLeft];
      if(d&&c&&!down)
      {
        auto func=[this](int cur_id,const vec2d&np,const vec2d&b,const vec2d&mpos)->void
        {
          if(!CD_Rect2Point(np-b,np+b,mpos))return;
          point_id=cur_id;
          down=true;
          point_offset=mpos-np;
        };
        vec2d s=vec2d(w,h)*0.5;
        vec2d b=vec2d(1,1)*border_size;
        if(php&&phs){
          func(10,*php,*phs*0.5,mpos);
        }else{
          func(10,pos,s,mpos);
        }
        for(int cur_id=0;cur_id<lenof(koef);cur_id++)
        {
          if(down)break;
          auto&kx=koef[cur_id].x;
          auto&ky=koef[cur_id].y;
          vec2d np=pos+vec2d(s.x*kx,s.y*ky);
          func(cur_id,np,b,mpos);
        }
      }
      down=d&&down;
      if(down)
      {
        if(point_id==10){
          //pos=mpos-point_offset;
          if(php&&phs){
            pos=(mpos-point_offset)-(*php-pos);//func(10,*php,*phs*0.5,mpos);
          }else{
            pos=mpos-point_offset;
          }
        }
        for(int cur_id=0;cur_id<lenof(koef);cur_id++)
        {
          if(point_id!=cur_id)continue;
          auto&kx=koef[cur_id].x;
          auto&ky=koef[cur_id].y;
          vec2d s=vec2d(w,h)*0.5;
          vec2d t=mpos-point_offset;
          if(kb.Down[VK_SHIFT])
          {
            vec2d n=t-pos;
            vec2d ns=vec2d(kx*n.x,ky*n.y);
            if(kx)w=ns.x*2.0;
            if(ky)h=ns.y*2.0;
          }else{
            vec2d n=t-pos;
            vec2d ns=vec2d(kx*n.x,ky*n.y);
            vec2d ds=ns-s;
            if(kx)w+=ds.x;
            if(ky)h+=ds.y;
            if(kx)pos.x+=(n.x-s.x*kx)*0.5;
            if(ky)pos.y+=(n.y-s.y*ky)*0.5;
          }
        }
        int gg=1;
      }
    }
    int gg=1;
  }
};

class TDay20140601BookV00:public IDay20140518Item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140601BookV00)PARENT(IDay20140518Item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TDay20140601Book,book,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140601BookV00
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140601BookV00
public:
  void Render(t_context&con)
  {
    vector<TDay20140601Book*> path;
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      *this,
      book,
      rect.pos,
      rect.get_size(),
      path
    };
    context.pos=vec2d_zero;
    context.size=con.pd3d9.WindowGetClientSize();
    rect.Render(context);
    auto hi=book.get_header_info(rect.pos,rect.get_size());
    /*con.qDev.SetColor(0xffff0000);
    con.qDev.DrawRectAsQuad(hi.header_pos,hi.header_size,2);*/
    context.pos=hi.body_pos;
    context.size=hi.body_size;
    //context.pos=rect.pos;
    //context.size=rect.get_size();
    book.Render(context);
  }
  void Update(t_context&con)
  {
    vector<TDay20140601Book*> path;
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      *this,
      book,
      rect.pos,
      rect.get_size(),
      path
    };
    context.pos=vec2d_zero;
    context.size=con.pd3d9.WindowGetClientSize();
    {
      auto hi=book.get_header_info(rect.pos,rect.get_size());
      rect.UpdateEx(context,hi.header_pos,hi.header_size);
    }
    auto hi=book.get_header_info(rect.pos,rect.get_size());
    context.pos=hi.body_pos;
    context.size=hi.body_size;
    book.Update(context);
  }
};
class TBookPageV00:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageV00)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(bool,need_set_def_text,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageV00
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageV00
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pFontGen=con.book.pFontGen;
    if(!pFontGen)return;
    auto&font=pFontGen->Font;
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    auto s=con.size*0.5;
    QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x-s.x),int(con.pos.y+s.y),text);
  }
  void Update(t_context&con)
  {
    if(!need_set_def_text)return;
    need_set_def_text=false;
    text="some default text.";
  }
};

class TBookPageWithTex:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTex)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResItem,DEF,$,$)\
ADDVAR(TWeakPtr<TResItemGenTexObject>,pTexGen,DEF,$,$)\
ADDVAR(bool,need_init,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,size,SET,64.0,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithTex
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTex
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetColor(color);
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    //qDev.DrawCircle(pos,size,0,1,16);
    if(pTexGen)
    {
      qDev.BindTex(0,&pTexGen->Tex);
    }
    qDev.DrawQuad(bpos.x+pos.x+0.5,bpos.y+pos.y+0.5,size*2,size*2,0);
    //auto mpos=pd3d9.WindowGetMousePos();
    qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=pd3d9.WindowGetMousePos()-bpos;
    if(CD_Rect2Point(-hsize,+hsize,mpos))if(kb.Down[mbLeft])
    {
      if((pos-mpos).Mag()<size)
      {
        pos=mpos;
      }
    }
    if(!need_init)return;
    need_init=false;
    auto*p=con.rScope.AddItem<TResItemGenTexObject>(con.Env);
    if(pTexGen){
      ResItem=std::move(TResourceHolder());
      pTexGen=nullptr;
    }
    pTexGen=p;
    p->Holders.push_back(&ResItem);
    ResItem.Caption="TBookPageWithTex";
    p->SetToDef();
    p->File.FN="?GenBall(256)";
    p->Run(con.Env,&con.pd3d9.D9Dev);
  }
};

class TBookPageWithTexV01:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTexV01)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResItem,DEF,$,$)\
ADDVAR(TWeakPtr<TResItemGenTexObject>,pTexGen,DEF,$,$)\
ADDVAR(bool,need_init,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,size,SET,64.0,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithTexV01
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTexV01
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetColor(color);
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    //qDev.DrawCircle(pos,size,0,1,16);
    if(pTexGen)
    {
      qDev.BindTex(0,&pTexGen->Tex);
    }
    qDev.DrawQuad(bpos.x+pos.x+0.5,bpos.y+pos.y+0.5,size*2,size*2,0);
    //auto mpos=pd3d9.WindowGetMousePos();
    qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=pd3d9.WindowGetMousePos()-bpos;
    if(CD_Rect2Point(-hsize,+hsize,mpos))
    {
      bool d=kb.Down[mbLeft];
      bool c=kb.Changed[mbLeft];
      bool dist=(pos-mpos).Mag()<size;
      down=d&&(dist||down);
      if(down)
      {
        pos=mpos;
      }
    }
    if(!need_init)return;
    need_init=false;
    auto*p=con.rScope.AddItem<TResItemGenTexObject>(con.Env);
    if(pTexGen){
      ResItem=std::move(TResourceHolder());
      pTexGen=nullptr;
    }
    pTexGen=p;
    p->Holders.push_back(&ResItem);
    ResItem.Caption="TBookPageWithTex";
    p->SetToDef();
    p->File.FN="?GenBall(256)";
    p->Run(con.Env,&con.pd3d9.D9Dev);
  }
};

class TBookPageTextBlock:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageTextBlock)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(int,border,SET,5,$)\
ADDEND()
//=====+>>>>>TBookPageTextBlock
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageTextBlock
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pFontGen=con.book.pFontGen;
    if(!pFontGen)return;
    auto&font=pFontGen->Font;
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    auto bsize=con.size;
    auto s=bsize*0.5;
    auto bpos=con.pos;
    auto pos=bpos+vec2d(-s.x,+s.y)+vec2d(+1,-1)*border;
    string raw=StrReplace(text,"\r","");
    vector<string> arr=split(text,"\n");
    real x=pos.x;
    real y=pos.y;
    real dx=+font.Info.Coords[0].x;
    real dy=-font.Info.Coords[0].y;
    real max_x=bpos.x+s.x-border;
    qDev.BeginBatch();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.empty()){y+=dy;x=pos.x;continue;}
      auto arr=split(ex," ");
      for(int j=0;j<arr.size();j++)
      {
        auto&ex=arr[j];
        if(ex.empty()){x+=dx;continue;}
        auto L=QapQ3Text::GetLength(font,ex);
        if(x+L>max_x){
          y+=dy;x=pos.x;
        }
        QapQ3Text::DrawQapText(&qDev,font,int(x),int(y),ex);
        x+=L+dx;
      }
      y+=dy;x=pos.x;
    }
    qDev.EndBatch();
  }
  void Update(t_context&con)
  {

  }
};

class TBookPageTextFromFile:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageTextFromFile)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(string,fn,SET,"test.txt",$)\
ADDVAR(bool,need_load_text,DEF,$,$)\
ADDVAR(int,border,SET,5,$)\
ADDEND()
//=====+>>>>>TBookPageTextFromFile
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageTextFromFile
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pFontGen=con.book.pFontGen;
    if(!pFontGen)return;
    auto&font=pFontGen->Font;
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    auto bsize=con.size;
    auto s=bsize*0.5;
    auto bpos=con.pos;
    auto pos=bpos+vec2d(-s.x,+s.y)+vec2d(+1,-1)*border;
    string raw=StrReplace(text,"\r","");
    vector<string> arr=split(text,"\n");
    real x=pos.x;
    real y=pos.y;
    real dx=+font.Info.Coords[0].x;
    real dy=-font.Info.Coords[0].y;
    real max_x=bpos.x+s.x-border;
    qDev.BeginBatch();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.empty()){y+=dy;x=pos.x;continue;}
      auto arr=split(ex," ");
      for(int j=0;j<arr.size();j++)
      {
        auto&ex=arr[j];
        if(ex.empty()){x+=dx;continue;}
        auto L=QapQ3Text::GetLength(font,ex);
        if(x+L>max_x){
          y+=dy;x=pos.x;
        }
        QapQ3Text::DrawQapText(&qDev,font,int(x),int(y),ex);
        x+=L+dx;
      }
      y+=dy;x=pos.x;
    }
    qDev.EndBatch();
  }
  void Update(t_context&con)
  {
    if(!need_load_text)return;
    need_load_text=false;
    text=file_get_contents(fn);
  }
};

class TBookPageTextFromFileV01:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageTextFromFileV01)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(string,fn,SET,"test.txt",$)\
ADDVAR(bool,need_load_text,DEF,$,$)\
ADDVAR(int,border,SET,5,$)\
ADDEND()
//=====+>>>>>TBookPageTextFromFileV01
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageTextFromFileV01
public:
  struct t_item{
    vec2d p;
    vec2d s;
    string func;
    string params;
    void draw(QapDev&qDev)
    {
      if(func=="rect"){
        auto arr=split(params,",");
        if(arr.size()>2)qDev.SetColor(HToI(arr[2]));
        qDev.DrawQuad(p.x,p.y,s.x,s.y);
      }
      if(func=="circle"){
        auto arr=split(params,",");
        if(arr.size()>1)qDev.SetColor(HToI(arr[1]));
        qDev.DrawCircle(p,s.x*0.5,0,1,16);
      }
    }
  };
  struct t_word_parser{
    string word;
    string func;
    string params;
    //vector<string> params;
    //vector<int> value;
    bool main()
    {
      if(word.empty())return false;
      if(word[0]!='`')return false;
      int e=0;
      func=ScanParam("`",word,",",e);
      if(e<0)return false;
      e+=func.size()+string(",").size();
      params=ScanParam("",word,"`",e);
      if(e<0)return false;
      return true;
    }
    vec2d get_size()
    {
      if(func=="rect"){
        vector<string> arr=split(params,",");
        QapAssert(arr.size()>=2);
        return vec2d(SToI(arr[0]),SToI(arr[1]));
      }
      if(func=="circle"){
        vector<string> arr=split(params,",");
        QapAssert(arr.size()>=1);
        int r=SToI(arr[0]);
        return vec2d(r,r)*2.0;
      }
      QapDebugMsg(func+" - WTF?");
      return vec2d(0,0);
    }
  };
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pFontGen=con.book.pFontGen;
    if(!pFontGen)return;
    auto&font=pFontGen->Font;
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    auto bsize=con.size;
    auto s=bsize*0.5;
    auto bpos=con.pos;
    auto pos=bpos+vec2d(-s.x,+s.y)+vec2d(+1,-1)*border;
    vector<t_item> items;
    string raw=StrReplace(text,"\r","");
    vector<string> arr=split(text,"\n");
    real x=pos.x;
    real y=pos.y;
    real cx=+font.Info.Coords[0].x;
    real cy=font.Info.Coords[0].y;
    real dx=cx;
    real dy=-cy;
    real max_x=bpos.x+s.x-border;
    qDev.BeginBatch();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.empty()){y+=dy;x=pos.x;continue;}
      auto arr=split(ex," ");
      for(int j=0;j<arr.size();j++)
      {
        auto&ex=arr[j];
        if(ex.empty()){x+=cx;continue;}
        t_word_parser wp;
        wp.word=ex;
        bool no_text=wp.main();
        vec2d size;
        real cur_dy=0;
        if(no_text)
        {
          size=wp.get_size();
          dx=+size.x;
          cur_dy=size.y<cy?-size.y-cy*0.25:-size.y;
          t_item item;
          item.func=wp.func;
          item.params=wp.params;
          item.s=size;
          items.push_back(std::move(item));
        }
        if(!no_text)
        {
          dx=QapQ3Text::GetLength(font,ex);
          size=vec2d(dx,cy);
          cur_dy=-size.y;
        }
        if(x+dx>max_x){
          y+=dy;x=pos.x;dy=0;
        }
        dy=std::min(dy,cur_dy);
        if(no_text){
          items.back().p=vec2d(x,y)+vec2d(+size.x,-size.y)*0.5;
        }
        if(!no_text){
          QapQ3Text::DrawQapText(&qDev,font,int(x),int(y),ex);
        }
        x+=dx+cx;
      }
      y+=dy;dy=0;x=pos.x;dx=cx;
    }
    qDev.EndBatch();
    qDev.BindTex(0,nullptr);
    qDev.BeginBatch();
    for(int i=0;i<items.size();i++)
    {
      auto&ex=items[i];
      qDev.SetColor(0xffff8000);
      ex.draw(qDev);
      //qDev.DrawQuad(ex.p.x,ex.p.y,ex.s.x,ex.s.y);
    }
    qDev.EndBatch();
  }
  void Update(t_context&con)
  {
    if(!need_load_text)return;
    need_load_text=false;
    text=file_get_contents(fn);
  }
};

class TBookPageWithRect:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithRect)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,border_size,SET,10,$)\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2d,point_offset,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,w,SET,128.0,$)\
ADDVAR(real,h,SET,64.0,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(QapColor,quad_color,SET,QapColor(80,128,128,0),$)\
ADDVAR(QapColor,rect_color,DEF,$,$)\
ADDVAR(QapColor,border_color,SET,QapColor(0,128,0),$)\
ADDVAR(bool,draw_quad,DEF,$,$)\
ADDVAR(bool,draw_rect,SET,true,$)\
ADDEND()
//=====+>>>>>TBookPageWithRect
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithRect
public:
  static void DrawRect(QapDev&qDev,const vec2d&a,const vec2d&b,const QapColor&color,int line_size)
  {
    qDev.SetColor(color);
    qDev.DrawRect(a,b,line_size);
    /*
    real x=(a.x+b.x)*0.5;
    real w=fabs(a.x-b.x);
    qDev.DrawQuad(x,a.y,line_size+w,line_size);
    qDev.DrawQuad(x,b.y,line_size+w,line_size);
    real y=(a.y+b.y)*0.5;
    real h=fabs(a.y-b.y);
    qDev.DrawQuad(a.x,y,line_size,-line_size+h);
    qDev.DrawQuad(b.x,y,line_size,-line_size+h);
    */
  }
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    //auto mpos=pd3d9.WindowGetMousePos()-bpos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vec2d p=vec2d(1,1)*0.5+pos+bpos;
    vec2d s=vec2d(w,h)*0.5;
    vec2d b=vec2d(1,1)*border_size;
    if(draw_quad){qDev.SetColor(quad_color);qDev.DrawQuad(p.x,p.y,w,h,0);}
    if(draw_rect)DrawRect(qDev,p-s,p+s,rect_color,line_size);
    //point_id=CD_Rect2Point(p-s,p+s,mpos)?10:-1;
    //int cur_id=0;
    static const vec2d koef[]={
      vec2d(-1,-1),
      vec2d(+1,-1),
      vec2d(+1,+1),
      vec2d(-1,+1),
      vec2d(-1,00),
      vec2d(+1,00),
      vec2d(00,-1),
      vec2d(00,+1)
    };
    for(int cur_id=0;cur_id<lenof(koef);cur_id++)
    {
      auto&kx=koef[cur_id].x;
      auto&ky=koef[cur_id].y;
      vec2d pos=p+vec2d(s.x*kx,s.y*ky);
      DrawRect(qDev,pos-b,pos+b,border_color,line_size);
    }
    if(0)
    {
      #define F(x,y){vec2d pos=p+vec2d(x,y);DrawRect(qDev,pos-b,pos+b,border_color,line_size);/*if(CD_Rect2Point(pos-b,pos+b,mpos))point_id=cur_id;cur_id++;*/}
      F(-s.x,-s.y);
      F(+s.x,-s.y);
      F(+s.x,+s.y);
      F(-s.x,+s.y);
      //
      F(-s.x,0000);
      F(+s.x,0000);
      F(0000,-s.y);
      F(0000,+s.y);
      #undef F
    }
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=pd3d9.WindowGetMousePos()-bpos;
    static const vec2d koef[]={
      vec2d(-1,-1),
      vec2d(+1,-1),
      vec2d(+1,+1),
      vec2d(-1,+1),
      vec2d(-1,00),
      vec2d(+1,00),
      vec2d(00,-1),
      vec2d(00,+1)
    };
    if(CD_Rect2Point(-hsize,+hsize,mpos))
    {
      bool d=kb.Down[mbLeft];
      bool c=kb.Changed[mbLeft];
      if(d&&c&&!down)
      {
        auto func=[this](int cur_id,const vec2d&np,const vec2d&b,const vec2d&mpos)->void
        {
          if(!CD_Rect2Point(np-b,np+b,mpos))return;
          point_id=cur_id;
          down=true;
          point_offset=mpos-np;
        };
        vec2d s=vec2d(w,h)*0.5;
        vec2d b=vec2d(1,1)*border_size;
        {func(10,pos,s,mpos);}
        for(int cur_id=0;cur_id<lenof(koef);cur_id++)
        {
          if(down)break;
          auto&kx=koef[cur_id].x;
          auto&ky=koef[cur_id].y;
          vec2d np=pos+vec2d(s.x*kx,s.y*ky);
          func(cur_id,np,b,mpos);
        }
      }
      down=d&&down;
      if(down)
      {
        if(point_id==10)pos=mpos-point_offset;
        for(int cur_id=0;cur_id<lenof(koef);cur_id++)
        {
          if(point_id!=cur_id)continue;
          auto&kx=koef[cur_id].x;
          auto&ky=koef[cur_id].y;
          vec2d s=vec2d(w,h)*0.5;
          vec2d t=mpos-point_offset;// new np
          // t = pos + ns

          /*vec2d nhs=vec2d(w*0.5*kx,h*0.5*ky);
          vec2d nppos=t-(pos+nhs);
          QapAssert(0.1>fabs(nppos.x));
          QapAssert(0.1>fabs(nppos.y));*/
          //t=pos+n
          if(kb.Down[VK_SHIFT])
          {
            vec2d n=t-pos;
            vec2d ns=vec2d(kx*n.x,ky*n.y);
            if(kx)w=ns.x*2.0;
            if(ky)h=ns.y*2.0;
          }else{
            vec2d n=t-pos;
            vec2d ns=vec2d(kx*n.x,ky*n.y);
            vec2d ds=ns-s;
            if(kx)w+=ds.x;
            if(ky)h+=ds.y;
            if(kx)pos.x+=(n.x-s.x*kx)*0.5;
            if(ky)pos.y+=(n.y-s.y*ky)*0.5;
          }
        }
        int gg=1;
      }
    }
    int gg=1;
  }
};

class TBookPageWithLineLoop:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithLineLoop)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(bool,AutoAdd,SET,true,$)\
ADDVAR(bool,ShowLines,SET,true,$)\
ADDVAR(bool,ShowSysPoints,SET,true,$)\
ADDVAR(bool,ShowSysLines,SET,false,$)\
ADDVAR(bool,loop,DEF,$,$)\
ADDVAR(bool,debug_points,SET,true,$)\
ADDVAR(bool,soft,SET,true,$)\
ADDVAR(int,ang_seg,SET,8,$)\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,point_size,SET,16.0,$)\
ADDVAR(real,line_size_sys,SET,2.0,$)\
ADDVAR(real,line_size,SET,2.0,$)\
ADDVAR(QapColor,line_color,DEF,$,$)\
ADDVAR(QapColor,line_color_sys,SET,QapColor(208,57,51,0),$)\
ADDVAR(vector<vec2d>,points,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithLineLoop
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithLineLoop
public:
  vector<vec2d> get_arr(const vec2d&offset)
  {
    vector<vec2d> arr;
    arr.resize(points.size());
    for(int i=0;i<arr.size();i++)
    {
      arr[i]=points[i]+pos+vec2d(+0.5,-0.5)+offset;
    }
    return arr;
  }
  static inline bool IsLeft(const vec2d&o,const vec2d&a,const vec2d&b)
  {
    return (a.x-o.x)*(b.y-o.y)>(a.y-o.y)*(b.x-o.x);
  }
  /*real left_koef(const vec2d&o,const vec2d&a,const vec2d&b)
  {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
  }*/
  struct t_soft_lineloop{
    struct t_dot{
      real k;
      int a0,a1;
      int b0,b1;
    };
    vector<vec2d> arr;
    static void calc_points(real half_line_size,const vec2d&a,const vec2d&b,real koef,vec2d&pa,vec2d&pb)
    {
      vec2d ab=b-a;
      vec2d ab_ort=ab.Ort().SetMag(half_line_size*Sign(koef));
      pa=a+ab_ort;
      pb=b+ab_ort;
    }
    static void calc_points(real half_line_size,const vec2d&a,const vec2d&b,real koef,vec2d*pa,vec2d*pb)
    {
      vec2d ab=b-a;
      vec2d ab_ort=ab.Ort().SetMag(half_line_size*Sign(koef));
      if(pa)*pa=a+ab_ort;
      if(pb)*pb=b+ab_ort;
    }
    void Draw(QapDev&qDev,real half_line_size,const QapColor&body_color,QapColor&line_color_sys,real point_size,real line_size_sys,int soft,int ang_seg,bool debug_points)
    {
      QapDev::BatchScope Scope(qDev);
      vector<t_dot> dots;
      real hls=half_line_size;
      real point_r=point_size*0.5;
      int n=arr.size();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        {
          vec2d a=arr[(i+n-1)%n];
          vec2d o=arr[(i+n-0)%n];
          vec2d b=arr[(i+n+1)%n];
          vec2d ao_p0;
          vec2d ao_p1;
          vec2d ob_p0;
          vec2d ob_p1;
          real k=-vec2d_cross(b-o,o-a);
          //real k=left_koef(a,o,b);
          calc_points(hls,a,o,k,ao_p0,ao_p1);
          calc_points(hls,o,b,k,ob_p0,ob_p1);
          vec2d p;
          //way 1
          if(CD_Segment2Segment(ao_p0,ao_p1,ob_p0,ob_p1,p))
          {
            qDev.SetColor(0xffff0000);
            if(debug_points)qDev.DrawCircle(p,point_r,0,line_size_sys,16);
            vec2d p0;vec2d p1;
            calc_points(hls,a,o,-k,nullptr,&p0);
            calc_points(hls,o,b,-k,&p1,nullptr);
            qDev.SetColor(body_color);
            {
              QapDev::BatchScope Scope(qDev);
              int n=!soft||(ang_seg<1)?1:ang_seg;
              real r=half_line_size;
              real ang=(p0-o).GetAng();
              real dang=(p1-o).Rot(p0-o).GetAng();
              static vector<int> VID;VID.resize(n+1);
              for(int i=1;i<n;i++)
              {
                vec2d v=Vec2dEx(ang+dang*(real(i)/real(n)),1);
                VID[i]=qDev.AddVertex(o+v*r,body_color,0,0);
              }
              VID[0]=qDev.AddVertex(p0,body_color,0,0);
              VID[n]=qDev.AddVertex(p1,body_color,0,0);
              int oid=qDev.AddVertex(p,body_color,0,0);
              for(int i=0;i<n;i++)
              {
                int a=VID[i+0];
                int b=VID[i+1];
                qDev.AddTris(a,b,oid);
              }
              t_dot tmp;
              if(k<0){
                tmp.a0=VID[0];
                tmp.a1=VID[n];
                tmp.b0=oid;
                tmp.b1=oid;
              }else{
                tmp.a0=oid;
                tmp.a1=oid;
                tmp.b0=VID[0];
                tmp.b1=VID[n];
              }
              dots.push_back(tmp);
            }
          }else{
            qDev.SetColor(0xff0000ff);
            if(debug_points)qDev.DrawCircle(ao_p0,point_r,0,line_size_sys,16);
            if(debug_points)qDev.DrawCircle(ao_p1,point_r,0,line_size_sys,16);
            //QapDebugMsg("WTF?");
          }
          if(debug_points){qDev.SetColor(k<0?0xff00ff00:0xff000000);}else qDev.SetColor(line_color_sys);
        }
        //qDev.SetColor(line_color_sys);
        //if(IsLeft(arr[(i+n-1)%n],arr[(i-0)%n],arr[(i+1)%n]))
        //  qDev.SetColor(0xff00ff00);
        //qDev.DrawRect(ex+phs,ex-phs,line_size_sys);
        //qDev.SetColor(0xffff0000);
        qDev.DrawCircle(ex,point_r,0,line_size_sys,16);
        //qDev.DrawCircle(ex,point_size*0.5,0,line_size_sys,16);
      }
      n=dots.size();
      for(int i=0;i<dots.size();i++)
      {
        auto id0=(i+0)%n;
        auto id1=(i+1)%n;
        /*auto&p0=arr[id0];
        auto&p1=arr[id1];*/
        auto&d0=dots[id0];
        auto&d1=dots[id1];
        qDev.AddTris(d0.a1,d1.a0,d1.b0);
        qDev.AddTris(d1.b0,d0.b1,d0.a1);
      }
    }
  };
  void Render(t_context&con)
  {
    if(!Enabled||!Visible)return;
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    //auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vector<vec2d> arr=get_arr(con.pos);
    {
      QapDev::BatchScope Scope(qDev);
      if(ShowLines)
      {
        qDev.SetColor(line_color);
        qDev.DrawPolyLine(arr,line_size,loop);
      }
      if(ShowSysLines)
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawPolyLine(arr,line_size_sys,loop);
      }
      real half_line_size=line_size*0.5;
      real point_r=point_size*0.5;
      //vec2d phs=vec2d(1,1)*point_r;
      if(ShowSysPoints)
      {
        qDev.SetColor(line_color_sys);
        int n=arr.size();
        t_soft_lineloop sll;
        sll.arr=arr;
        sll.Draw(qDev,half_line_size,line_color,line_color_sys,point_size,line_size_sys,soft,ang_seg,debug_points);
      }
      //center
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawCircle(con.pos+pos,point_r,0,line_size_sys,16);
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    if(!Enabled||!Moved)return;
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    //auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=con.get_mpos();
    if(!CD_Rect2Point(-hsize,+hsize,mpos))return;
    {
      if(kb.Down[mbLeft]&&kb.Changed[mbLeft])
      {
        point_id=-1;
        bool ok=true;
        for(int i=0;i<points.size();i++)
        {
          if((points[i]+pos-mpos).Mag()<point_size)
          {
            ok=false;
            //points[i]=mpos-pos;
            point_id=i;
            down=true;
            break;
          }
        }
        if(ok)if((pos-mpos).Mag()<point_size)
        {
          ok=false;
          //pos=mpos;
          point_id=points.size();
          down=true;
        }
        if(ok&&AutoAdd)
        {
          point_id=points.size();
          points.push_back(mpos-pos);
          down=true;
        }
      }
      if(kb.Down[mbLeft]&&!kb.Changed[mbLeft])if(down)if(point_id>=0)
      {
        if(point_id<points.size())
        {
          points[point_id]=mpos-pos;
        }
        if(point_id==points.size())
        {
          if(kb.Down[VK_SHIFT])
          {
            for(int i=0;i<points.size();i++)
            {
              auto&ex=points[i];
              ex-=mpos-pos;
            }
          }
          pos=mpos;
        }
      }
    }
    if(!kb.Down[mbLeft])down=false;
    int gg=1;
  }
};

class TBookPageWithTrigon:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTrigon)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,AutoResize,SET,true,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(bool,AutoAdd,SET,true,$)\
ADDVAR(bool,ShowLines,SET,true,$)\
ADDVAR(bool,ShowSysPoints,SET,true,$)\
ADDVAR(bool,ShowSysLines,SET,false,$)\
ADDVAR(bool,draw_trigon,SET,false,$)\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,point_size,SET,16.0,$)\
ADDVAR(real,line_size_sys,SET,2.0,$)\
ADDVAR(real,line_size,SET,2.0,$)\
ADDVAR(QapColor,trigon_color,SET,QapColor(35,70,50,0),$)\
ADDVAR(QapColor,line_color,DEF,$,$)\
ADDVAR(QapColor,line_color_sys,SET,QapColor(208,57,51,0),$)\
ADDVAR(vector<vec2d>,points,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithTrigon
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTrigon
public:
  vector<vec2d> get_arr(const vec2d&offset)
  {
    vector<vec2d> arr;
    arr.resize(points.size());
    for(int i=0;i<arr.size();i++)
    {
      if(i>3)break;
      arr[i]=points[i]+pos+offset;
    }
    return arr;
  }
  void Render(t_context&con)
  {
    if(!Enabled||!Visible)return;
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vector<vec2d> arr=get_arr(con.pos);
    {
      QapDev::BatchScope Scope(qDev);
      if(draw_trigon)
      {
        qDev.SetColor(trigon_color);
        qDev.DrawTrigon(arr[0],arr[1],arr[2]);
      }
      if(ShowLines)
      {
        qDev.SetColor(line_color);
        qDev.DrawPolyLine(arr,line_size,true);
      }
      if(ShowSysLines)
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawPolyLine(arr,line_size_sys,true);
      }
      real half_line_size=line_size*0.5;
      real point_r=point_size*0.5;
      //vec2d phs=vec2d(1,1)*point_r;
      if(ShowSysPoints)
      {
        qDev.SetColor(line_color_sys);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
          auto&ex=arr[i];
          qDev.SetColor(line_color_sys);
          qDev.DrawCircle(ex,point_r,0,line_size_sys,16);
        }
      }
      //center
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawCircle(pos,point_r,0,line_size_sys,16);
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    if(!Enabled||!Moved)return;
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=pd3d9.WindowGetMousePos()-bpos;
    if(AutoResize&&points.size()>3)
    {
      points.resize(3);
    }
    if(!CD_Rect2Point(-hsize,+hsize,mpos))return;
    {
      if(kb.Down[mbLeft]&&kb.Changed[mbLeft])
      {
        point_id=-1;
        bool ok=true;
        for(int i=0;i<points.size();i++)
        {
          if(i>3)break;
          if((points[i]+pos-mpos).Mag()<point_size)
          {
            ok=false;
            //points[i]=mpos-pos;
            point_id=i;
            down=true;
            break;
          }
        }
        if(ok)if((pos-mpos).Mag()<point_size)
        {
          ok=false;
          //pos=mpos;
          point_id=points.size();
          down=true;
        }
        if(ok&&AutoAdd&&points.size()<3)
        {
          point_id=points.size();
          points.push_back(mpos-pos);
          down=true;
        }
      }
      if(kb.Down[mbLeft]&&!kb.Changed[mbLeft])if(down)if(point_id>=0)
      {
        if(point_id<points.size())
        {
          points[point_id]=mpos-pos;
        }
        if(point_id==points.size())
        {
          if(kb.Down[VK_SHIFT])
          {
            for(int i=0;i<points.size();i++)
            {
              auto&ex=points[i];
              ex-=mpos-pos;
            }
          }
          pos=mpos;
        }
      }
    }
    if(!kb.Down[mbLeft])down=false;
    int gg=1;
  }
};

class TBookPageWithTwoLine:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTwoLine)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,AutoResize,SET,true,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(bool,AutoAdd,SET,true,$)\
ADDVAR(bool,ShowLines,SET,true,$)\
ADDVAR(bool,ShowSysPoints,SET,true,$)\
ADDVAR(bool,draw_cross_point,SET,false,$)\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,point_size,SET,16.0,$)\
ADDVAR(real,line_size_sys,SET,2.0,$)\
ADDVAR(real,line_size,SET,2.0,$)\
ADDVAR(QapColor,cross_color,SET,QapColor(35,90,0,0),$)\
ADDVAR(QapColor,line_color,DEF,$,$)\
ADDVAR(QapColor,line_color_sys,SET,QapColor(208,57,51,0),$)\
ADDVAR(vector<vec2d>,points,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithTwoLine
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTwoLine
public:
  vector<vec2d> get_arr(const vec2d&offset)
  {
    vector<vec2d> arr;
    arr.resize(points.size());
    for(int i=0;i<arr.size();i++)
    {
      if(i>4)break;
      arr[i]=points[i]+pos+offset;
    }
    return arr;
  }
  void Render(t_context&con)
  {
    if(!Enabled||!Visible)return;
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vector<vec2d> arr=get_arr(con.pos);
    {
      QapDev::BatchScope Scope(qDev);
      real point_r=point_size*0.5;
      if(ShowLines)
      {
        qDev.SetColor(line_color);
        vector<vec2d> list;
        qDev.DrawLineList(arr,line_size);
      }
      real half_line_size=line_size*0.5;
      if(ShowSysPoints)
      {
        qDev.SetColor(line_color_sys);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
          auto&ex=arr[i];
          qDev.SetColor(line_color_sys);
          qDev.DrawCircle(ex,point_r,0,line_size_sys,16);
        }
      }
      if(draw_cross_point&&arr.size()>=4)
      {
        vec2d&a=arr[0];
        vec2d&b=arr[1];
        vec2d&c=arr[2];
        vec2d&d=arr[3];
        vec2d p;
        bool ok=CD_Segment2Segment(a,b,c,d,p);
        if(ok)
        {
          qDev.SetColor(cross_color);
          qDev.DrawCircle(p,point_r,0,line_size_sys,16);
        }
      }
      //center
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawCircle(con.pos+pos,point_r,0,line_size_sys,16);
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    if(!Enabled||!Moved)return;
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=pd3d9.WindowGetMousePos()-bpos;
    if(AutoResize&&points.size()>4)
    {
      points.resize(4);
    }
    if(!CD_Rect2Point(-hsize,+hsize,mpos))return;
    {
      if(kb.Down[mbLeft]&&kb.Changed[mbLeft])
      {
        point_id=-1;
        bool ok=true;
        for(int i=0;i<points.size();i++)
        {
          if(i>4)break;
          if((points[i]+pos-mpos).Mag()<point_size)
          {
            ok=false;
            //points[i]=mpos-pos;
            point_id=i;
            down=true;
            break;
          }
        }
        if(ok)if((pos-mpos).Mag()<point_size)
        {
          ok=false;
          //pos=mpos;
          point_id=points.size();
          down=true;
        }
        if(ok&&AutoAdd&&points.size()<4)
        {
          point_id=points.size();
          points.push_back(mpos-pos);
          down=true;
        }
      }
      if(kb.Down[mbLeft]&&!kb.Changed[mbLeft])if(down)if(point_id>=0)
      {
        if(point_id<points.size())
        {
          points[point_id]=mpos-pos;
        }
        if(point_id==points.size())
        {
          if(kb.Down[VK_SHIFT])
          {
            for(int i=0;i<points.size();i++)
            {
              auto&ex=points[i];
              ex-=mpos-pos;
            }
          }
          pos=mpos;
        }
      }
    }
    if(!kb.Down[mbLeft])down=false;
    int gg=1;
  }
};

class TRawTrigon{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRawTrigon)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,AutoResize,SET,true,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(bool,AutoAdd,SET,true,$)\
ADDVAR(bool,ShowLines,SET,true,$)\
ADDVAR(bool,ShowSysPoints,SET,true,$)\
ADDVAR(bool,ShowSysLines,SET,false,$)\
ADDVAR(bool,draw_trigon,SET,false,$)\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(real,point_size,SET,16.0,$)\
ADDVAR(real,line_size_sys,SET,2.0,$)\
ADDVAR(real,line_size,SET,2.0,$)\
ADDVAR(QapColor,trigon_color,SET,QapColor(35,70,50,0),$)\
ADDVAR(QapColor,line_color,DEF,$,$)\
ADDVAR(QapColor,line_color_sys,SET,QapColor(208,57,51,0),$)\
ADDVAR(vector<vec2d>,points,DEF,$,$)\
ADDEND()
//=====+>>>>>TRawTrigon
#include "QapGenStruct.inl"
//<<<<<+=====TRawTrigon
public:
  typedef IBookPage::t_context t_context;
public:
  vector<vec2d> get_arr(const vec2d&offset)
  {
    vector<vec2d> arr;
    arr.resize(points.size());
    for(int i=0;i<arr.size();i++)
    {
      if(i>3)break;
      arr[i]=points[i]+pos+offset;
    }
    return arr;
  }
  void Render(t_context&con)
  {
    if(!Enabled||!Visible)return;
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    vector<vec2d> arr=get_arr(con.pos);
    {
      QapDev::BatchScope Scope(qDev);
      if(draw_trigon)
      {
        qDev.SetColor(trigon_color);
        qDev.DrawTrigon(arr[0],arr[1],arr[2]);
      }
      if(ShowLines)
      {
        qDev.SetColor(line_color);
        qDev.DrawPolyLine(arr,line_size,true);
      }
      if(ShowSysLines)
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawPolyLine(arr,line_size_sys,true);
      }
      real half_line_size=line_size*0.5;
      real point_r=point_size*0.5;
      if(ShowSysPoints)
      {
        qDev.SetColor(line_color_sys);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
          auto&ex=arr[i];
          qDev.SetColor(line_color_sys);
          qDev.DrawCircle(ex,point_r,0,line_size_sys,16);
        }
      }
      //center
      {
        qDev.SetColor(line_color_sys);
        qDev.DrawCircle(pos,point_r,0,line_size_sys,16);
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    if(!Enabled||!Moved)return;
    auto&pd3d9=con.pd3d9;
    auto&kb=con.kb;
    auto&qrp=con.qrp;
    auto bpos=con.pos;
    auto hsize=con.size*0.5;
    auto mpos=pd3d9.WindowGetMousePos()-bpos;
    if(AutoResize&&points.size()>3)
    {
      points.resize(3);
    }
    if(!CD_Rect2Point(-hsize,+hsize,mpos))return;
    {
      if(kb.Down[mbLeft]&&kb.Changed[mbLeft])
      {
        point_id=-1;
        bool ok=true;
        for(int i=0;i<points.size();i++)
        {
          if(i>3)break;
          if((points[i]+pos-mpos).Mag()<point_size)
          {
            ok=false;
            point_id=i;
            down=true;
            break;
          }
        }
        if(ok)if((pos-mpos).Mag()<point_size)
        {
          ok=false;
          point_id=points.size();
          down=true;
        }
        if(ok&&AutoAdd&&points.size()<3)
        {
          point_id=points.size();
          points.push_back(mpos-pos);
          down=true;
        }
      }
      if(kb.Down[mbLeft]&&!kb.Changed[mbLeft])if(down)if(point_id>=0)
      {
        if(point_id<points.size())
        {
          points[point_id]=mpos-pos;
        }
        if(point_id==points.size())
        {
          if(kb.Down[VK_SHIFT])
          {
            for(int i=0;i<points.size();i++)
            {
              auto&ex=points[i];
              ex-=mpos-pos;
            }
          }
          pos=mpos;
        }
      }
    }
    if(!kb.Down[mbLeft])down=false;
    int gg=1;
  }
};

class TBookPageClipping:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageClipping)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TRawTrigon,trigon,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageClipping
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageClipping
public:
  void Render(t_context&con)
  {
    rect.Render(con);
    trigon.Render(con);
  }
  void Update(t_context&con)
  {
    rect.Update(con);
    trigon.Update(con);
  }
};

class TBookPageClippingV02:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageClippingV02)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TRawTrigon,trigon,DEF,$,$)\
ADDVAR(bool,draw_cross_point,SET,true,$)\
ADDVAR(QapColor,cross_color,SET,QapColor(80,90,0,0),$)\
ADDEND()
//=====+>>>>>TBookPageClippingV02
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageClippingV02
public:
  class t_edge_info{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_edge_info)OWNER(TBookPageClippingV02)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,count,DEF,$,$)\
    ADDVAR(int,a,SET,-1,$)\
    ADDVAR(int,b,SET,-1,$)\
    ADDEND()
    //=====+>>>>>t_edge_info
    #include "QapGenStruct.inl"
    //<<<<<+=====t_edge_info
  public:
    void add(int id){
      count++;
      if(count==1)a=id;
      if(count==2)b=id;
    }
  };
  struct t_dot{
    vec2d pos;
    int te;
    int re;
  };
public:
  void RenderBack(t_context&con)
  {
    rect.RenderBack(con);
    trigon.Render(con);
  }
  static bool PointInsideTrigon(const vec2d&a,const vec2d&b,const vec2d&c,const vec2d&p)
  {
    bool passed=false;
    #define F(o,a,b)real v_o##a##b=((a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x));bool o##a##b=v_o##a##b>0;passed=passed||v_o##a##b==0.0;
    F(p,a,b)F(p,b,c)F(p,c,a)
    #undef F
    if(passed){
      int gg=1;
      return true;
    }
    return (pab==pbc)&&(pab==pca);
  }
  template<typename TYPE>
  static bool InsideDip(TYPE min,TYPE val,TYPE max){
    bool retval=(val>min)&&(val<max);
    bool old_retval=InDip(min,val,max);
    if(retval!=old_retval)
    {
      int gg=1;
    }
    return retval;
  };
  static bool CD_Segment2SegmentEx(const vec2d&a,const vec2d&b,const vec2d&c,const vec2d&d,vec2d&out)
  {
    vec2d A[5]={a,b-a,c-a,d-a,out};
    real m=A[1].Mag();
    A[2]=A[2].Rot(A[1]);
    A[3]=A[3].Rot(A[1]);
    if(Sign(A[2].y)==(Sign(A[3].y)))return false;
    A[4].x=A[2].x-(A[2].x-A[3].x)*A[2].y/(A[2].y-A[3].y); A[4].y=0;
    if(!InsideDip(0.0,A[4].x,m))return false;
    out=A[4].UnRot(A[1])+a;
    if(a==out)return false;
    if(out==b)return false;
    if(c==out)return false;
    if(out==d)return false;
    return true;
  }
  static bool PointInsideRect(const vec2d&A,const vec2d&B,const vec2d&P)
  {
    const vec2d&p=P;vec2d a(min(A.x,B.x),min(A.y,B.y)),b(max(A.x,B.x),max(A.y,B.y));
    return InsideDip(a.x,p.x,b.x)&&InsideDip(a.y,p.y,b.y);
  }
  static bool PointAtRectEdge(const vec2d&a,const vec2d&b,const vec2d&p)
  {
    bool fax=(a.x==p.x)&&InsideDip(a.y,p.y,b.y);
    bool fbx=(b.x==p.x)&&InsideDip(a.y,p.y,b.y);
    bool fay=(a.y==p.y)&&InsideDip(a.x,p.x,b.x);
    bool fby=(b.y==p.y)&&InsideDip(a.x,p.x,b.x);
    return fax||fbx||fay||fby;
  }
  void RenderThis(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    auto bpos=con.pos;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    //
    auto tarr=trigon.get_arr(bpos);
    auto rarr=rect.get_arr(bpos);
    if(tarr.size()<3)return;
    //
    vector<t_edge_info> re2cd;    //rect_edge_id to info with cross_dot_id
    vector<int> cd2te;            //cross_dot_id to trigon_edge_id
    vector<int> cd2re;            //cross_dot_id to rect_edge_id
    vector<t_edge_info> te2cd;    //trigon_edge_id to info with cross_dot_id
    //vector<vec2d> cd2vec2d;       //cross_dot_id to vec2d
    vector<t_dot> dots;           //list of cross_dot;
    vector<bool> tpinside;        //trigon point is inside rect
    vector<bool> tpatedge;        //trigon point at rect edge
    int inside_counter=0;
    int atedge_counter=0;
    re2cd.resize(4);
    te2cd.resize(3);
    tpinside.resize(3);
    tpatedge.resize(3);
    for(int i=0;i<tarr.size();i++)
    {
      int n=tarr.size();
      vec2d&ta=tarr[(i+0)%n];
      vec2d&tb=tarr[(i+1)%n];
      vec2d s=vec2d(rect.w,rect.h);
      vec2d hs=s*0.5;
      bool ok=PointInsideRect(rect.pos-hs,rect.pos+hs,ta);
      if(ok)inside_counter++;
      tpinside[i]=ok;
      bool atedge=PointAtRectEdge(rect.pos-hs,rect.pos+hs,ta);
      tpatedge[i]=atedge;
      if(atedge)atedge_counter++;
      for(int j=0;j<rarr.size();j++)
      {
        if(atedge)break;
        int n=rarr.size();
        vec2d&ra=rarr[(j+0)%n];
        vec2d&rb=rarr[(j+1)%n];
        vec2d p;
        bool ok=CD_Segment2SegmentEx(ra,rb,ta,tb,p);
        if(ok)
        {
          int cd_id=dots.size();
          {auto&te=te2cd[i];te.add(cd_id);}
          {auto&re=re2cd[j];re.add(cd_id);}
          cd2te.push_back(i);
          cd2re.push_back(j);
          t_dot tmp;
          tmp.pos=p;
          tmp.te=i;
          tmp.re=j;
          dots.push_back(tmp);
          //
          qDev.SetColor(cross_color);
          if(draw_cross_point)qDev.DrawCircle(p,trigon.point_size*0.5,0,trigon.line_size_sys,16);
        }
      }
      if(atedge)
      {
        qDev.SetColor(0xff0000ff);
        qDev.DrawCircle(ta,trigon.point_size*0.5,0,trigon.line_size_sys,16);
      }
      if(ok)QapAssert(!atedge);
      if(ok)
      {
        qDev.SetColor(0xff00ff00);
        qDev.DrawCircle(ta,trigon.point_size*0.5,0,trigon.line_size_sys,16);
      }
    }
    int breakpoint=1;
    vector<bool> rpinside;rpinside.resize(rarr.size());
    int rp_inside_counter=0;
    for(int i=0;i<rarr.size();i++)
    {
      rpinside[i]=PointInsideTrigon(tarr[0],tarr[1],tarr[2],rarr[i]);
      if(rpinside[i])rp_inside_counter++;
    }/*
    if(dots.size()==2)if(inside_counter==1)if(rp_inside_counter==0)
    {
      int id=-1;
      for(int i=0;i<tpinside.size();i++){if(tpinside[i])id=i;}
      qDev.SetColor(0x32000000);
      qDev.DrawTrigon(dots[0].pos,dots[1].pos,tarr[id]);
      return;
    }
    if(dots.size()==0)if(inside_counter==0)if(rp_inside_counter==4)
    {
      int id=-1;
      qDev.SetColor(0x32000000);
      qDev.DrawQuad(rect.pos.x,rect.pos.y,rect.w,rect.h);
      return;
    }
    if(dots.size()==0)if(inside_counter==3)if(rp_inside_counter==0)
    {
      int id=-1;
      qDev.SetColor(0x32000000);
      qDev.DrawTrigon(tarr[0],tarr[1],tarr[2]);
      return;
    }
    if(dots.size()==2)if(inside_counter==1)if(rp_inside_counter==1)
    {
      int tid=-1;
      for(int i=0;i<tpinside.size();i++){if(tpinside[i])tid=i;}
      int rid=-1;
      for(int i=0;i<rpinside.size();i++){if(rpinside[i])rid=i;}
      qDev.SetColor(0x32000000);
      qDev.DrawTrigon(dots[0].pos,dots[1].pos,tarr[tid]);
      qDev.DrawTrigon(dots[0].pos,dots[1].pos,rarr[rid]);
      return;
    }*/
    //sorting
    for(int i=0;i<tarr.size();i++)
    {
      //if(!tpinside[i])continue;
      auto&te=te2cd[i];
      if(te.count!=2)continue;
      auto&pa=dots[te.a].pos;
      auto&pb=dots[te.b].pos;
      auto da=(pa-tarr[i]).Mag();
      auto db=(pb-tarr[i]).Mag();
      if(da>db)std::swap(te.a,te.b);
    }
    for(int i=0;i<rarr.size();i++)
    {
      //if(!tpinside[i])continue;
      auto&re=re2cd[i];
      if(re.count!=2)continue;
      auto&pa=dots[re.a].pos;
      auto&pb=dots[re.b].pos;
      auto da=(pa-rarr[i]).Mag();
      auto db=(pb-rarr[i]).Mag();
      if(da>db)std::swap(re.a,re.b);
    }
    //after sorting
    if(atedge_counter)
    {

    }
    //after sorting
    if(inside_counter>0)if(!atedge_counter)
    {
      vector<int> types;
      vector<int> ids;
      vector<vec2d> VA;
      auto add=[&VA,&ids,&types,&dots,&tarr,&rarr](int type,int id){
        types.push_back(type);
        ids.push_back(id);
        if(type==0)VA.push_back(dots[id].pos);
        if(type==1)VA.push_back(tarr[id]);
        if(type==2)VA.push_back(rarr[id]);
      };
      auto add_dot=[&add](int id){add(0,id);};
      auto add_tp=[&add](int id){add(1,id);};
      auto add_rp=[&add](int id){add(2,id);};
      int tid=-1;
      for(int i=0;i<tarr.size();i++)
      {
        if(!tpinside[i])continue;
        tid=i;
        break;
      }
      QapAssert(tid>=0);
      for(int i=0;i<tarr.size();i++)
      {
        int id=(tid+i)%tarr.size();
        int next_id=(id+1)%tarr.size();
        if(tpinside[id]&&tpinside[next_id])
        {
          QapAssert(te2cd[id].count==0);
          add_tp(id);
        }
        if(tpinside[id]&&!tpinside[next_id])
        {
          QapAssert(te2cd[id].count==1);
          if(te2cd[id].count==1)
          {
            auto&te=te2cd[id];
            auto&p=dots[te.a];
            QapAssert(p.te==id);
            add_tp(id);
            add_dot(te.a);
          }else{rect.down=false;trigon.down=false;}
        }
        if(!tpinside[id]&&!tpinside[next_id])
        {
          QapAssert(te2cd[id].count!=1);
          if(te2cd[id].count==2)
          {
            auto&te=te2cd[id];
            auto&a=dots[te.a];
            auto&b=dots[te.b];
            add_dot(te.a);
            add_dot(te.b);
          }else if(te2cd[id].count==1){rect.down=false;trigon.down=false;}
        }
        if(!tpinside[id]&&tpinside[next_id])
        {
          QapAssert(te2cd[id].count==1);
          if(te2cd[id].count==1)
          {
            auto&te=te2cd[id];
            auto&a=dots[te.a];
            add_dot(te.a);
          }else{rect.down=false;trigon.down=false;}
        }
        continue;
      }
      //add skiped rect points
      for(int i=0;i+1<types.size();i++)
      {
        int id=i;
        int next_id=(i+1)%types.size();
        if(types[id]==0)if(types[next_id]==0)
        {
          auto&a=dots[ids[id]];
          auto&b=dots[ids[next_id]];
          if(a.re!=b.re)if(a.te!=b.te)
          {
            vector<vec2d> VA_old=std::move(VA);
            for(int j=0;j<i+1;j++)
            {
              VA.push_back(VA_old[j]);
            }
            for(int j=a.re+1;;j++)
            {
              int id=j%rarr.size();
              VA.push_back(rarr[id]);
              if(id==b.re)break;
            }
            for(int j=i+1;j<VA_old.size();j++)
            {
              VA.push_back(VA_old[j]);
            }
          }
        }
      }
      //
      QapAssert(VA.size()>=3);
      qDev.SetColor(0x32000000);
      for(int i=1;i+1<VA.size();i++)
      {
        auto&o=VA[0];
        auto&a=VA[i+0];
        auto&b=VA[i+1];
        qDev.DrawTrigon(o,a,b);
      }
      return;
    }
    if(inside_counter==0)
    {
      vector<vec2d> VA;
      int rid=-1;
      for(int i=0;i<rarr.size();i++)
      {
        if(rpinside[i])continue;
        if(!re2cd[i].count)continue;
        rid=i;
        break;
      }
      rid=0;
      if(rid<0)return;
      for(int i=0;i<rarr.size();i++)
      {
        int id=(rid+i)%rarr.size();
        if(!rpinside[id]&&!re2cd[id].count)
        {
          continue;
        }
        if(rpinside[id]&&!re2cd[id].count)
        {
          VA.push_back(rarr[id]);
          continue;
        }
        if(!rpinside[id]&&re2cd[id].count==1)
        {
          int a_id=re2cd[id].a;
          VA.push_back(dots[a_id].pos);
          continue;
        }
        if(rpinside[id]&&re2cd[id].count==1)
        {
          int a_id=re2cd[id].a;
          VA.push_back(rarr[id]);
          VA.push_back(dots[a_id].pos);
          int te_id=dots[a_id].te;
          auto&te=te2cd[dots[a_id].te];
          QapAssert(te.count==2);/*
          {
            int id=(te_id+1)%tarr.size();
            QapAssert(tpinside[id]);
            VA.push_back(tarr[id]);
            int id2=(te_id+2)%tarr.size();
            if(tpinside[id2])
            {
              VA.push_back(tarr[id2]);
            }
          }*/
          continue;
        }
        if(!rpinside[id]&&re2cd[id].count==2)
        {
          int a_id=re2cd[id].a;
          int b_id=re2cd[id].b;
          VA.push_back(dots[a_id].pos);
          VA.push_back(dots[b_id].pos);
          continue;
        }
        QapDebugMsg("WTF?");
      }
      QapAssert(VA.size()>=3);
      qDev.SetColor(0x32000000);
      for(int i=1;i+1<VA.size();i++)
      {
        auto&o=VA[0];
        auto&a=VA[i+0];
        auto&b=VA[i+1];
        qDev.DrawTrigon(o,a,b);
      }
      return;
    }
    //after sorting
    if(dots.size()==2)if(inside_counter==0)if(rp_inside_counter==2)
    {
      int rid=-1;
      for(int i=0;i<rarr.size();i++)
      {
        if(rpinside[i])continue;
        if(!re2cd[i].count)continue;
        rid=i;
        break;
      }
      QapAssert(re2cd[rid].count==1);
      int a_id=re2cd[rid].a;
      vec2d a=dots[a_id].pos;
      int b_id=(rid+1)%rarr.size();
      vec2d b=rarr[b_id];
      QapAssert(!re2cd[b_id].count);
      int c_id=(rid+2)%rarr.size();
      vec2d c=rarr[c_id];
      QapAssert(re2cd[c_id].count==1);
      int d_id=re2cd[c_id].a;
      vec2d d=dots[d_id].pos;
      qDev.SetColor(0x32000000);
      qDev.DrawTrigon(a,b,c);
      qDev.DrawTrigon(c,d,a);
      return;
    }
    if(dots.size()==2)if(inside_counter==0)if(rp_inside_counter==1)
    {
      int rid=-1;
      for(int i=0;i<rpinside.size();i++){if(rpinside[i])rid=i;}
      qDev.SetColor(0x32000000);
      qDev.DrawTrigon(rarr[rid],dots[0].pos,dots[1].pos);
      return;
    }
    if(dots.size()==2)if(inside_counter==2)if(rp_inside_counter==0)
    {
      int id=-1;
      for(int i=0;i<re2cd.size();i++)
      {
        if(re2cd[i].count==2){id=i;}
      }
      if(id>=0)
      {
        auto&re=re2cd[id];
        vec2d a=dots[re.a].pos;
        vec2d b=dots[re.b].pos;
        int te_a=dots[re.b].te;
        int te_b=(te_a+1)%tarr.size();
        QapAssert(tpinside[te_a]!=tpinside[te_b]);
        int c_id=-1;
        if(tpinside[te_a])c_id=te_a;
        if(tpinside[te_b])c_id=te_b;
        int d_id=(c_id+1)%tarr.size();
        vec2d c=tarr[c_id];
        vec2d d=tarr[d_id];
        qDev.SetColor(0x32000000);
        qDev.DrawTrigon(a,b,c);
        qDev.DrawTrigon(c,d,a);
        return;
      }
    }
    int gg=1;
  }
  void RenderFront(t_context&con)
  {
    rect.RenderBorder(con);
    rect.RenderPoints(con);
  }
public:
  void Render(t_context&con)
  {
    RenderBack(con);
    RenderThis(con);
    RenderFront(con);
  }
  void Update(t_context&con)
  {
    rect.Update(con);
    trigon.Update(con);
  }
};

class TBookPageWithMultyRect:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithMultyRect)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TRawRect>,arr,DEF,$,$)\
ADDVAR(bool,AutoRenameIfEmpty,SET,true,$)\
ADDEND()
//=====+>>>>>TBookPageWithMultyRect
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithMultyRect
public:
  void Render(t_context&con)
  {
    for(int i=0;i<arr.size();i++)arr[i].Render(con);
  }
  void Update(t_context&con)
  {
    if(AutoRenameIfEmpty)if(Caption.empty())Caption="MultyRect";
    for(int i=0;i<arr.size();i++)arr[i].Update(con);
  }
};

class TBookPageWithBook:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithBook)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TDay20140601Book,book,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithBook
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithBook
public:
  void Render(t_context&con)
  {
    vector<TDay20140601Book*> path;
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      con.root,
      book,
      rect.pos,
      rect.get_size(),
      con.path
    };
    context.pos=con.pos;
    context.size=con.size;
    rect.Render(context);
    auto hi=book.get_header_info(rect.pos,rect.get_size());
    /*con.qDev.SetColor(0xffff0000);
    con.qDev.DrawRectAsQuad(hi.header_pos,hi.header_size,2);*/
    context.pos=con.pos+hi.body_pos;
    context.size=hi.body_size;
    //context.pos=rect.pos;
    //context.size=rect.get_size();
    book.Render(context);
  }
  void Update(t_context&con)
  {
    vector<TDay20140601Book*> path;
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      con.root,
      book,
      rect.pos,
      rect.get_size(),
      path
    };
    context.pos=con.pos;
    context.size=con.size;
    {
      auto hi=book.get_header_info(rect.pos,rect.get_size());
      rect.UpdateEx(context,hi.header_pos,hi.header_size);
    }
    auto hi=book.get_header_info(rect.pos,rect.get_size());
    context.pos=con.pos+hi.body_pos;
    context.size=hi.body_size;
    book.Update(context);
  }
};

class TBookPageWithMultyBook:public IBookPage{
public:
  class TBook{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBook)OWNER(TBookPageWithMultyBook)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,Caption,DEF,$,$)\
  ADDVAR(bool,NeedRemove,DEF,$,$)\
  ADDVAR(bool,Enabled,SET,true,$)\
  ADDVAR(bool,Moved,SET,true,$)\
  ADDVAR(bool,Visible,SET,true,$)\
  ADDVAR(TRawRect,rect,DEF,$,$)\
  ADDVAR(TDay20140601Book,book,DEF,$,$)\
  ADDEND()
  //=====+>>>>>TBook
  #include "QapGenStruct.inl"
  //<<<<<+=====TBook
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(TBook)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithMultyBook)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TBook>,books,DEF,$,$)\
ADDVAR(bool,AutoClean,SET,true,$)\
ADDEND()
//=====+>>>>>TBookPageWithMultyBook
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithMultyBook
public:
  void Render(t_context&con)
  {
    auto&arr=books;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex.Enabled||!ex.Visible||ex.NeedRemove)continue;
      RenderBook(con,ex);
    }
  }
  void Update(t_context&con)
  {
    auto&arr=books;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex.Enabled||!ex.Moved||ex.NeedRemove)continue;
      UpdateBook(con,ex);
    }
    if(!AutoClean)return;
    QapCleanIf(arr,[](TBook&ref){return ref.NeedRemove;});
  }
  static void RenderBook(t_context&con,TBook&Book)
  {
    auto&book=Book.book;
    auto&rect=Book.rect;
    vector<TDay20140601Book*> path;
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      con.root,
      book,
      rect.pos,
      rect.get_size(),
      con.path
    };
    context.pos=con.pos;
    context.size=con.size;
    rect.Render(context);
    auto hi=book.get_header_info(rect.pos,rect.get_size());
    /*con.qDev.SetColor(0xffff0000);
    con.qDev.DrawRectAsQuad(hi.header_pos,hi.header_size,2);*/
    context.pos=con.pos+hi.body_pos;
    context.size=hi.body_size;
    //context.pos=rect.pos;
    //context.size=rect.get_size();
    book.Render(context);
  }
  static void UpdateBook(t_context&con,TBook&Book)
  {
    auto&book=Book.book;
    auto&rect=Book.rect;
    vector<TDay20140601Book*> path;
    IBookPage::t_context context={
      con.Env,
      con.qrp,
      con.pd3d9,
      con.kb,
      con.qDev,
      con.rScope,
      con.main,
      con.root,
      book,
      rect.pos,
      rect.get_size(),
      path
    };
    context.pos=con.pos;
    context.size=con.size;
    {
      auto hi=book.get_header_info(rect.pos,rect.get_size());
      rect.UpdateEx(context,hi.header_pos,hi.header_size);
    }
    auto hi=book.get_header_info(rect.pos,rect.get_size());
    context.pos=con.pos+hi.body_pos;
    context.size=hi.body_size;
    book.Update(context);
  }
};

class TMPosRecorder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMPosRecorder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<vec2d>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TMPosRecorder
#include "QapGenStruct.inl"
//<<<<<+=====TMPosRecorder
public:
};


class TBookPageWithFullScreen:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithFullScreen)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,AutoRenameIfEmpty,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,32,$)\
ADDVAR(int,counter,DEF,$,$)\
ADDVAR(int,page_id,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithFullScreen
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithFullScreen
public:
  void Update(t_context&con)
  {
    if(!Enabled)return;
    if(AutoRenameIfEmpty)if(Caption.empty())Caption="Deselector";
    if(tick<0)return;
    if(tick<max_tick){tick++;return;}
    con.book.page_id=page_id;
    tick=0;
    counter++;
  }
};

class TBookPageWithSelector:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithSelector)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,AutoRenameIfEmpty,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,32,$)\
ADDVAR(int,counter,DEF,$,$)\
ADDVAR(int,page_id,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithSelector
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithSelector
public:
  void Update(t_context&con)
  {
    if(!Enabled)return;
    if(AutoRenameIfEmpty)if(Caption.empty())Caption="Deselector";
    if(tick<0)return;
    if(tick<max_tick){tick++;return;}
    con.book.page_id=page_id;
    tick=0;
    counter++;
  }
};

class TBookPageWithPageBuilder:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithPageBuilder)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,AutoRenameIfEmpty,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,32,$)\
ADDVAR(int,counter,DEF,$,$)\
ADDVAR(int,page_id,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithPageBuilder
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithPageBuilder
public:
  void Update(t_context&con)
  {
    if(!Enabled)return;
    if(AutoRenameIfEmpty)if(Caption.empty())Caption="PageBuilder";
    if(tick<0)return;
    if(tick<max_tick){tick++;return;}
    con.book.page_id=page_id;
    tick=0;
    counter++;
    con.book.AddItem<TBookPageWithSelector>(con.Env)->Caption="gp"+IToS(counter);
  }
};

class TBookPageWithMPosRecorders:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithMPosRecorders)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,AutoRenameIfEmpty,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(int,target_id,DEF,$,$)\
ADDVAR(QapColor,line_color,DEF,$,$)\
ADDVAR(QapColor,point_color,SET,0xff000000,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(int,point_size,SET,2,$)\
ADDVAR(bool,draw_line,SET,true,$)\
ADDVAR(bool,draw_points,SET,true,$)\
ADDVAR(int,render_count,SET,64,$)\
ADDVAR(bool,need_clean_target,DEF,$,$)\
ADDVAR(vector<TMPosRecorder>,recorders,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithMPosRecorders
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithMPosRecorders
public:
  static vector<vec2d> get_arr_with_offset(const vector<vec2d>&source,const vec2d&offset,int render_count)
  {
    vector<vec2d> out;
    out.reserve(source.size());
    auto&arr=source;
    int first=int(arr.size())-render_count;
    if(first<0)first=0;
    for(int i=first;i<arr.size();i++)out.push_back(arr[i]+offset);
    return std::move(out);
  }
  void Render(t_context&con)
  {
    if(!Enabled||!Visible)return;
    if(render_count<0)return;
    if(target_id<0)return;
    if(target_id>=recorders.size())return;
    auto&arr=recorders[target_id].arr;
    QapDev::BatchScope Scope(con.qDev);
    con.qDev.BindTex(0,nullptr);
    con.qDev.SetColor(line_color);
    if(draw_line)con.qDev.DrawPolyLine(get_arr_with_offset(arr,con.pos,render_count),line_size,false);
    int first=int(arr.size())-render_count;
    if(first<0)first=0;
    con.qDev.SetColor(point_color);
    if(draw_points)for(int i=first;i<arr.size();i++)
    {
      if(i>first+render_count)break;
      auto ex=arr[i]+con.pos;
      con.qDev.DrawQuad(ex.x,ex.y,point_size,point_size,0);
    }
    int gg=1;
  }
  void Update(t_context&con)
  {
    if(!Enabled||!Moved)return;
    if(AutoRenameIfEmpty)if(Caption.empty())Caption="MPosRecorders";
    if(target_id<0)return;
    if(target_id>=recorders.size())return;
    auto hsize=con.size*0.5;
    auto mpos=con.get_mpos();
    if(!CD_Rect2Point(-hsize,+hsize,mpos))return;
    auto&arr=recorders[target_id].arr;
    arr.push_back(con.get_mpos());
  }
};

class TDay20140518TestBlackBackBox:public IDay20140518Item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140518TestBlackBackBox)PARENT(IDay20140518Item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapColor,color,SET,QapColor(255,25,25,25),$)\
ADDEND()
//=====+>>>>>TDay20140518TestBlackBackBox
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140518TestBlackBackBox
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto&pd3d9=con.pd3d9;
    qDev.BindTex(0,0);
    qDev.SetColor(color);
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    auto v=pd3d9.WindowGetClientSize();
    qDev.DrawQuad(0,0,v.x,v.y);
  }
  void Update(t_context&con)
  {
    auto&kb=con.kb;
    if(!kb.Down[VK_F5]||!kb.Changed[VK_F5])return;
    Visible=!Visible;
  }
};

class TUnitDay20140518:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUnitDay20140518)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TDay20140518Main>,Main,DEF,$,$)\
ADDEND()
//=====+>>>>>TUnitDay20140518
#include "QapGenStruct.inl"
//<<<<<+=====TUnitDay20140518
public:
  void OnBuild(TBuildContext&Context)
  {
    auto&Env=Context.Env;
    auto&Qrp=Context.Qrp;
    auto&PluginMan=Context.PluginMan;
    auto*pMain=Qrp.Scene.AddItem<TDay20140518Main>(Env);
    pMain->qrp=&Qrp;
    Main=pMain;
  }
  void Update(IEnvRTTI&Env)
  {

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
        F(TWeakPtrTest2014)\
        F(TGameTank2D2014)\
        F(TDay20140518Main)F(TDay20140518TestV00)F(TDay20140518TestBlackBackBox)\
        F(TUnitDay20140518)F(TDay20140518TestText)F(TDay20140601BookV00)\
        F(TBookPageV00)F(TBookPageWithTex)F(TBookPageWithTexV01)\
        F(TBookPageTextBlock)F(TBookPageTextFromFile)F(TBookPageTextFromFileV01)\
        F(TBookPageWithRect)F(TBookPageWithTrigon)F(TBookPageWithLineLoop)\
        F(TBookPageClipping)\
        F(TBookPageClippingV02)F(TBookPageWithTwoLine)F(TBookPageWithMultyRect)\
        F(TBookPageWithMPosRecorders)F(TBookPageWithSelector)F(TBookPageWithPageBuilder)\
        F(TBookPageWithBook)F(TBookPageWithMultyBook)
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
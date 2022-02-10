//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//

#include "GeomTools.h"

class MeUnitHC2013;
class TGameHC2013Friend;

class QapAtlas{
public:
  class TFrame;
  class IFrameSource{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IFrameSource)OWNER(QapAtlas)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>IFrameSource
    #include "QapGenStruct.inl"
    //<<<<<+=====IFrameSource
  public:
    virtual void Restore(TFrame&Frame){}
  };
  class TFrame{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TFrame)OWNER(QapAtlas)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(int,x,SET,0,$)\
    ADDVAR(int,y,SET,0,$)\
    ADDVAR(int,w,SET,0,$)\
    ADDVAR(int,h,SET,0,$)\
    ADDVAR(TWeakPtr<QapAtlas>,Atlas,DEF,$,$)\
    ADDVAR(TAutoPtr<IFrameSource>,Source,DEF,$,$)\
    ADDEND()
    //=====+>>>>>TFrame
    #include "QapGenStruct.inl"
    //<<<<<+=====TFrame
  public:
    static void SysHasSelf();
  public:
    void Bind(QapDev*RD)
    {
      if(!Atlas)return;
      auto*pAtlas=Atlas.get();
      pAtlas->Bind(RD,this);
    }
    void Restore()
    {
      if(!Source||!Atlas)return;
      auto*pAtlas=Atlas.get();
      auto*pSource=Source.get();
      pSource->Restore(*this);
    }
  };
  class TFrameSrcFile:public IFrameSource{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TFrameSrcFile)PARENT(IFrameSource)OWNER(QapAtlas)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,FileName,DEF,$,$)\
    ADDEND()
    //=====+>>>>>TFrameSrcFile
    #include "QapGenStruct.inl"
    //<<<<<+=====TFrameSrcFile
  public:
    void Restore(TFrame&Frame)
    {
      if(!Frame.Atlas)return;
      auto*pAtlas=Frame.Atlas.get();
      QapTexMem Buff;
      LoadTextureFromFile(Buff,FileName);
      pAtlas->AddFrameRaw(Buff,Frame);
    }
  };
  class TFrameSrcFileWithShadow:public IFrameSource{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TFrameSrcFileWithShadow)PARENT(IFrameSource)OWNER(QapAtlas)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,FileName,DEF,$,$)\
    ADDVAR(int,dHS,SET,8,$)\
    ADDEND()
    //=====+>>>>>TFrameSrcFileWithShadow
    #include "QapGenStruct.inl"
    //<<<<<+=====TFrameSrcFileWithShadow
  public:
    void Restore(TFrame&Frame)
    {
      if(!Frame.Atlas)return;
      auto*pAtlas=Frame.Atlas.get();
      QapTexMem Buff,Out;
      LoadTextureFromFile(Buff,FileName);
      GenShadow(Buff,Out,dHS);
      pAtlas->AddFrameRaw(Out,Frame);
    }
  };
public:
#define DEF_PRO_NESTED(F)F(TFrame)F(IFrameSource)F(TFrameSrcFile)F(TFrameSrcFileWithShadow)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapAtlas)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(int,W,SET,512,$)\
ADDVAR(int,H,SET,512,$)\
ADDVAR(int,X,SET,0,$)\
ADDVAR(int,Y,SET,0,$)\
ADDVAR(int,Ident,SET,2,$)\
ADDVAR(int,DebugIdent,SET,1,$)\
ADDVAR(int,dY,SET,0,$)\
ADDVAR(QapTexMem,Mem,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(vector<TFrame>,Frames,DEF,$,$)\
ADDEND()
//=====+>>>>>QapAtlas
#include "QapGenStruct.inl"
//<<<<<+=====QapAtlas
public:
  static void SysHasSelf();
public:
  void InitMem()
  {
    Mem.Init(W,H); 
  }
  void AddFrameRaw(const QapTexMem&FrameMem,TFrame&Out)
  {
    auto&AtlasMem=Mem;
    if(!FrameMem)return;
    if(X<Ident||Ident*2+DebugIdent+X+FrameMem.W>W)
    {
      QapAssert(W>=FrameMem.W);
      X=0;
      if(dY)Y+=dY+Ident*2;
      AtlasMem.FillLine(Y,0xff000000);
      Y+=DebugIdent;
      dY=FrameMem.H;
    }
    {
      if(DebugIdent==1){
        int dS=2*Ident+DebugIdent*2;
        X+=DebugIdent;
        AtlasMem.RectLine(X-DebugIdent,Y-DebugIdent,FrameMem.W+dS,FrameMem.H+dS,0xff000000);
      }
      {
        Out.Atlas=this;
        Out.w=FrameMem.W;
        Out.h=FrameMem.H;
        Out.x=X+Ident;
        Out.y=Y+Ident;
      }
      AtlasMem.FillBorder(X+Ident,Y+Ident,FrameMem,Ident);
      AtlasMem.FillMem(X+Ident,Y+Ident,FrameMem);
      X+=FrameMem.W+Ident*2;dY=max(dY,FrameMem.H);
    }
  }
  TFrame*AddFrame(QapTexMem&FrameMem)
  {
    Frames.push_back(TFrame());
    auto&back=Frames.back();
    AddFrameRaw(FrameMem,back);
    return &back;
  }
  void Bind(QapDev*RD,TFrame*frame)
  {
    transform2f xf;
    float inv_w=1.f/float(W);
    float inv_h=1.f/float(H);
    xf.p=vec2f(float(frame->x)*inv_w,float(frame->y)*inv_h);
    xf.r=MakeZoomTransform(vec2f(float(frame->w)*inv_w,float(frame->h)*inv_h)).r;
    RD->SetTextureTransform(xf);
  }
  void RestoreMem()
  {
    X=0;
    Y=0;
    dY=0;
    InitMem();
    for(int i=0;i<Frames.size();i++)
    {
      auto&ex=Frames[i];
      ex.Restore();
    }
  }
public:/*
  static void QapTexMem_tools_IncSize(QapTexMem&Mem,QapTexMem&OutMem,int dHS=8)
  {
    int dS=dHS*2;
    OutMem.Init(Mem.W+dS,Mem.H+dS);
  }
  static void QapTexMem_tools_Clear(QapTexMem&Mem,QapTexMem&OutMem,const QapColor&Color=0xffffffff)
  {
    OutMem.Clear(Color);
  }
  static void QapTexMem_tools_FillMem(QapTexMem&Mem,QapTexMem&OutMem,int dX,int dY)
  {
    OutMem.FillMem(dX,dY,Mem);
  }*/
  static void AddBorder(QapTexMem&Mem,QapTexMem&OutMem,int dHS=8,const QapColor&Color=0xffffffff)
  {
    int dS=dHS*2;
    OutMem.Init(Mem.W+dS,Mem.H+dS);
    OutMem.Clear(Color);
    OutMem.FillMem(dHS,dHS,Mem);
  }
  static void GenShadow(QapTexMem&Mem,QapTexMem&Out,int dHS=8)
  {
    int dS=dHS*2;
    QapTexMem&MemWithBorder=Out;
    AddBorder(Mem,MemWithBorder,dHS,0xffffffff);
    MemWithBorder.CalcAlpha(0xffffffff);
    MemWithBorder.FillChannel(0x00ffffff,0x00ffffff);
    MemWithBorder.BlurTexture(dHS);
  }
};

class TBot{
public:
#define DEF_PRO_AUTO_COPY
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBot)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,p,SET,vec2d(0,0),$)\
ADDVAR(vec2d,v,SET,vec2d(0,0),$)\
ADDVAR(real,r,SET,8,$)\
ADDVAR(real,hp,SET,1.0,$)\
ADDVAR(real,power,SET,0.15,$)\
ADDVAR(bool,isuser,SET,false,$)\
ADDVAR(bool,deaded,SET,false,$)\
ADDVAR(int,bonus_bullets,SET,0,$)\
ADDVAR(TWeakPtr<QapAtlas::TFrame>,frame,DEF,$,$)\
ADDVAR(TWeakPtr<QapAtlas::TFrame>,frame_s,DEF,$,$)\
ADDEND()
//=====+>>>>>TBot
#include "QapGenStruct.inl"
//<<<<<+=====TBot
public:
};

class TBullet{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBullet)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,p,SET,vec2d(0,0),$)\
ADDVAR(vec2d,v,SET,vec2d(0,0),$)\
ADDVAR(real,r,SET,2,$)\
ADDVAR(real,damage,SET,1.0,$)\
ADDVAR(bool,deaded,SET,false,$)\
ADDEND()
//=====+>>>>>TBullet
#include "QapGenStruct.inl"
//<<<<<+=====TBullet
public:
};

class TRespawn{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRespawn)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,p,SET,vec2d(0,0),$)\
ADDVAR(real,r,SET,24,$)\
ADDVAR(int,tick,SET,0,$)\
ADDVAR(int,maxtick,SET,64,$)\
ADDVAR(int,GenCount,SET,0,$)\
ADDEND()
//=====+>>>>>TRespawn
#include "QapGenStruct.inl"
//<<<<<+=====TRespawn
public:
};

class TGameHC2013;

class TBonus{
public:
  class IAction{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IAction)OWNER(TBonus)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IAction
    #include "QapGenStruct.inl"
    //<<<<<+=====IAction
  public:
    static void SysHasSelf();
  public:
    virtual void Use(TBonus*Bonus,TGameHC2013*Game){}
  };
public:
#define DEF_PRO_NESTED(F)F(IAction)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBonus)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2d,p,SET,vec2d(0,0),$)\
ADDVAR(vec2d,v,SET,vec2d(0,0),$)\
ADDVAR(real,r,SET,16,$)\
ADDVAR(real,ang,SET,0,$)\
ADDVAR(bool,deaded,SET,false,$)\
ADDVAR(TWeakPtr<IAction>,action,DEF,$,$)\
ADDVAR(TWeakPtr<QapAtlas::TFrame>,frame,DEF,$,$)\
ADDVAR(TWeakPtr<QapAtlas::TFrame>,frame_s,DEF,$,$)\
ADDEND()
//=====+>>>>>TBonus
#include "QapGenStruct.inl"
//<<<<<+=====TBonus
public:
};
/*
class QapAtlasObject:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapAtlasObject)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(QapAtlas,Atlas,DEF,$,$)\
ADDVAR(QapTexGen,Gen,DEF,$,$)\
ADDEND()
//=====+>>>>>QapAtlasObject
#include "QapGenStruct.inl"
//<<<<<+=====QapAtlasObject
public:
  static void SysHasSelf();
public:
  void SetToDef()
  {
    Gen.Mem=&Atlas.Mem;
    Gen.Tex=&Atlas.Tex;
  }
  void Do(IEnv&Env)
  {
    if(!Atlas.Tex.DynRes.pDev)
    {
      QapAssert(!Atlas.Mem);
      Atlas.InitMem();
      Atlas.Tex.MountDev(*Env.pDev);
    }
    if(!Gen.Tex->Tex)Gen.Do();
  }
};*/

class QapGameObject:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapGameObject)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<TGameHC2013>,Game,DEF,$,$)\
ADDVAR(QapAtlas,Atlas,DEF,$,$)\
ADDVAR(QapFontObject,Norm,DEF,$,$)\
ADDVAR(QapFontObject,Blur,DEF,$,$)\
ADDEND()
//=====+>>>>>QapGameObject
#include "QapGenStruct.inl"
//<<<<<+=====QapGameObject 
public:
  static void SysHasSelf();
public:
  template<int>
  void WeakDo(IEnv&Env)
  {
    if(!Game)return;
    auto*game=Game.get();
    game->WakeUp(Env);
  }
  void Do(IEnv&Env)
  {
    if(!Atlas.Tex.DynRes.pDev){
      Atlas.Tex.MountDev(*Env.pDev);
    }
    if(!Norm.Tex.DynRes.pDev){
      Norm.Tex.MountDev(*Env.pDev);
    }
    if(!Blur.Tex.DynRes.pDev){
      Blur.Tex.MountDev(*Env.pDev);
    }
    if(!Atlas.Mem){
      WeakDo<0>(Env);
    }
    if(!Norm.Font.Mem){
      Norm.DoGenFont(Env.pDev);
    }
    if(!Blur.Font.Mem){
      Blur.Font.Mem=Norm.Font.Mem;
      Blur.Font.Info=Norm.Font.Info;
      Blur.Font.Mem.BlurTexture(4);
    }
    if(!Atlas.Tex&&Atlas.Mem){
      QapTexGen::Gen(&Atlas.Mem,&Atlas.Tex);
    }
    if(!Norm.Tex&&Norm.Font.Mem){
      QapTexGen::Gen(&Norm.Font.Mem,&Norm.Tex);
    }
    if(!Blur.Tex&&Blur.Font.Mem){
      QapTexGen::Gen(&Blur.Font.Mem,&Blur.Tex);
    }
  }
};

class TGameHC2013{
public:
  class BonusAction_AddBullet:public TBonus::IAction{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BonusAction_AddBullet)PARENT(TBonus::IAction)OWNER(TGameHC2013)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>BonusAction_AddBullet
    #include "QapGenStruct.inl"
    //<<<<<+=====BonusAction_AddBullet
  public:
    void Use(TBonus*Bonus,TGameHC2013*Game){Game->You.bonus_bullets+=128;}
  };
  class BonusAction_AddHP:public TBonus::IAction{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BonusAction_AddHP)PARENT(TBonus::IAction)OWNER(TGameHC2013)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>BonusAction_AddHP
    #include "QapGenStruct.inl"
    //<<<<<+=====BonusAction_AddHP
  public:
    void Use(TBonus*Bonus,TGameHC2013*Game){Game->You.hp++;}
  };
public:
  typedef QapAtlas::TFrame TFrame;
public:
#define DEF_PRO_NESTED(F)F(BonusAction_AddBullet)F(BonusAction_AddHP)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameHC2013)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<QapAtlas>,Atlas,DEF,$,$)\
ADDVAR(TWeakPtr<QapFontObject>,NormFontObject,DEF,$,$)\
ADDVAR(TWeakPtr<QapFontObject>,BlurFontObject,DEF,$,$)\
ADDVAR(vec2d,mapsize,SET,vec2d(768,768),$)\
ADDVAR(vec2d,winpos,SET,vec2d(0,0),$)\
ADDVAR(TBot,You,DEF,$,$)\
ADDVAR(bool,Winned,SET,false,$)\
ADDVAR(int,BotLeft,SET,0,$)\
ADDVAR(int,Shots,SET,0,$)\
ADDVAR(int,Frags,SET,0,$)\
ADDVAR(int,TickCount,SET,0,$)\
ADDVAR(int,ForceAdded,SET,0,$)\
ADDVAR(int,BonusAdded,SET,0,$)\
ADDVAR(bool,Stage2,SET,false,$)\
ADDVAR(bool,ShowInfo,SET,true,$)\
ADDVAR(vector<TBot>,Bots,DEF,$,$)\
ADDVAR(vector<TBot>,dBots,DEF,$,$)\
ADDVAR(vector<TRespawn>,Respawns,DEF,$,$)\
ADDVAR(vector<TBullet>,Bullets,DEF,$,$)\
ADDVAR(vector<TBonus>,Bonuses,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameWin,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameYou,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBotA,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBotB,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBotC,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FramedBotA,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FramedBotB,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FramedBotC,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameDeadBot,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameRespawn,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBullet,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBonus,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameHealth,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBonus_s,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameHealth_s,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameAtlas,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameBotA_s,DEF,$,$)\
ADDVAR(TWeakPtr<TFrame>,FrameYou_s,DEF,$,$)\
ADDVAR(TWeakPtr<QapKeyboard>,Keyboard,DEF,$,$)\
ADDVAR(TWeakPtr<MeUnitHC2013>,TheUnit,DEF,$,$)\
ADDVAR(BonusAction_AddBullet,ActionAddBullet,DEF,$,$)\
ADDVAR(BonusAction_AddHP,ActionAddHP,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameHC2013
#include "QapGenStruct.inl"
//<<<<<+=====TGameHC2013
public:
  static void SysHasSelf();
public:  
  typedef IRenderProgram::IEnv IEnv;
  void Render(QapDev&qDev){
    if(0)if(Atlas)
    {
      auto*atlas=Atlas.get();
      atlas->Tex.Bind(0);
      qDev.SetColor(0xFFffFFff);
      qDev.DrawQuad(0.5,0.5,512,512,0);
    }
    TEntityRenderer ER={qDev};
    auto&RD=qDev;
    auto hms=mapsize*0.5;
    {
      vec2d pmin(+hms),pmax(-hms);
      RD.SetBlendMode(QapDev::BlendType::BT_SUB);
      RD.SetColor(0xff008000);
      RD.BindTex(0,0);
      RD.DrawPolyLine(MakeQuadAABB(pmin,pmax),2,true);
      RD.SetColor(0xff00AF00);
      RD.DrawPolyLine(MakeQuadAABB(pmin,pmax),1,true);
    }
    auto*TexBlur=!BlurFontObject?nullptr:&BlurFontObject->Tex;
    auto*TexNorm=!NormFontObject?nullptr:&NormFontObject->Tex;
    if(0)
    {
      RD.SetBlendMode(QapDev::BlendType::BT_SUB);
      int w=TexBlur->W;
      int h=TexBlur->H;
      RD.BindTex(0,TexBlur);
      RD.SetColor(0xff000000);
      RD.DrawQuad(2.5,-1.5,w,h);
      RD.BindTex(0,TexNorm);
      RD.SetColor(0xffffffff);
      RD.DrawQuad(0.5,0.5,w,h);
    }
    auto*pAtlasTex=!Atlas?nullptr:&Atlas->Tex;
    {
      RD.SetBlendMode(QapDev::BlendType::BT_SUB);
      RD.SetColor(0xffffffff);
      RD.BindTex(0,pAtlasTex);
      if(FrameWin)FrameWin->Bind(&RD);
      RD.DrawQuad(winpos.x,winpos.y,64,64);
    }
    {
      RD.SetBlendMode(QapDev::BlendType::BT_SUB);
      RD.SetColor(0xffffffff);
      RD.BindTex(0,pAtlasTex);
      QapDev::BatchScope Scope(RD);
      {
        if(FrameRespawn)FrameRespawn->Bind(&RD);
        RenderEntities(ER,Respawns);
        RenderEntities(ER,Bots);
        RenderEntities(ER,dBots);
        if(FrameBullet)FrameBullet->Bind(&RD);
        RenderEntities(ER,Bullets);
        if(FrameYou)FrameYou->Bind(&RD);
        ER.Do(&You);
        RenderEntities(ER,Bonuses);
      }
    }
    static bool hack_flag=false;
    static bool need_hack=(RD.txf.r.col1.x==0)&&(RD.txf.r.col1.y==0);
    if(hack_flag&&need_hack)
    {
      RD.txf.set_ident();
    }
    
    RenderText(RD);
    RD.SetColor(0xffffffff);
    RD.BeginBatch();
    RD.EndBatch();
    RD.BindTex(0,0);
  }
public:
  template<int>
  QapResourceList&get_res_list(MeUnitHC2013&Unit){
    return Unit.RenderProgram->ResList;
  }
  template<int>
  void SetGameFriend(IEnvRTTI&Env,MeUnitHC2013&Unit){
    auto&Scene=Unit.RenderProgram->Scene;
    auto*GameFriend=Scene.AddItem<TGameHC2013Friend>(Env);
    GameFriend->Game=this;
  }
  template<int>
  QapD3DDev9*get_qD3DDev9(MeUnitHC2013&Unit){
    return &Unit.ProgramD3D9.get()->D9Dev;
  }
  void SetFontAsArial(IEnvRTTI&Env,QapD3DDev9*qD3DDev9,QapFontObject*FontObject)
  {
    FontObject->SetToDef();
    FontObject->FontGen.Name="Arial";
    FontObject->FontGen.Bold=false;
    FontObject->FontGen.Size=14;
    FontObject->FontGen.TexSize=512;
    return;
    bool blur=false;
    if(blur)
    {
      //FontObject->MountDev(qD3DDev9);
      FontObject->DoGenFont(qD3DDev9);
      FontObject->Font.Mem.BlurTexture(4);
      //FontObject->DoGenTex();
      //return;
    }
    //FontObject->Run(Env,qD3DDev9);
  }
  template<int>
  void WeakInit(IEnvRTTI&Env,MeUnitHC2013&Unit)
  {
    Keyboard=Unit.Keyboard.get();
  }
public:
  void Init(IEnvRTTI&Env,MeUnitHC2013&Unit)
  {
    WeakInit<0>(Env,Unit);

    auto*qD3DDev9=get_qD3DDev9<0>(Unit);

    auto&ResList=get_res_list<0>(Unit);

    SetGameFriend<0>(Env,Unit);

    auto*qGO=ResList.AddItem<QapGameObject>(Env);
    qGO->Game=this;

    auto*pAtlas=&qGO->Atlas;
    Atlas=pAtlas;

    InitAtlas(Env);

    QapResource::IEnv qrEnv={Env,qD3DDev9};
    WakeUp(qrEnv);

    auto*pNorm=&qGO->Norm;
    SetFontAsArial(Env,qD3DDev9,pNorm);
    auto*pBlur=&qGO->Blur;
    SetFontAsArial(Env,qD3DDev9,pBlur);

    NormFontObject=pNorm;
    BlurFontObject=pBlur;

    QapResource::IEnv tmpEnv={Env,qD3DDev9};
    qGO->Do(tmpEnv);

    RestartGame();

    //Scene.AddItem<
    //Context.Qrp.Program->UserCode
    //Context.Qrp.
  }
  void WakeUp(QapResource::IEnv&Env)
  {
    if(!Atlas)return;
    auto*pAtlas=Atlas.get();
    if(!pAtlas->Frames.empty())
    {
      pAtlas->RestoreMem();
    }
    SaveTextureToFile(pAtlas->Mem,"atlas.png");
  }
  void InitAtlas(IEnvRTTI&Env)
  {
    if(!Atlas)return;
    auto*pAtlas=Atlas.get();
    pAtlas->InitMem();
    QapTexMem Mem;
    auto LoadTexture=[&Mem](const string&FN)->QapTexMem&{
      LoadTextureFromFile(Mem,FN);
      return Mem;
    };
    //atlas->AddFrame(Mem);
    auto AddFrameFromFile=[&pAtlas,&Env](const string&fn)->QapAtlas::TFrame*
    {
      pAtlas->Frames.push_back(std::move(QapAtlas::TFrame()));
      auto&back=pAtlas->Frames.back();
      back.Atlas=pAtlas;
      auto*pSrc=back.Source.build<QapAtlas::TFrameSrcFile>(Env);
      pSrc->FileName=fn;
      return &back;
    };
    auto AddShadowFrameFromFile=[&pAtlas,&Env](const string&fn)->QapAtlas::TFrame*
    {
      pAtlas->Frames.push_back(std::move(QapAtlas::TFrame()));
      auto&back=pAtlas->Frames.back();
      back.Atlas=pAtlas;
      auto*pSrc=back.Source.build<QapAtlas::TFrameSrcFileWithShadow>(Env);
      pSrc->FileName=fn;
      pSrc->dHS=8;
      return &back;
    };
    #define F(NAME)AddFrameFromFile("GFX\\"NAME);
    FrameWin=F("Win.png");//64x64(48x48)
    FrameYou=F("You.png");//32x32
    FrameBotA=F("BotA.png");//16x16
    FrameBotB=F("BotB.png");//16x16
    FrameBotC=F("BotC.png");//16x16
    FramedBotA=F("dBotA.png");//16x16
    FramedBotB=F("dBotB.png");//16x16
    FramedBotC=F("dBotC.png");//16x16
    FrameRespawn=F("Respawn.png");//64x64(48x48)
    FrameBullet=F("Bullet.png");//64x64(4x4)
    FrameBonus=F("Bonus.png");//32x32
    FrameHealth=F("Health.png");//32x32
    #undef F
    FrameBotA_s=AddShadowFrameFromFile("GFX\\Bot4.png");
    FrameBonus_s=AddShadowFrameFromFile("GFX\\Bonus.png");
    FrameHealth_s=AddShadowFrameFromFile("GFX\\Health.png");
    FrameYou_s=AddShadowFrameFromFile("GFX\\You_s.png");
    //
    SaveTextureToFile(pAtlas->Mem,"atlas.png");
    //Atlas->
  }
public:
  class IVisitor{
  public:
    virtual void Do(TBot*p){}
    virtual void Do(TBullet*p){}
    virtual void Do(TRespawn*p){}
    virtual void Do(TBonus*p){}
  };
public:
  class TEntityRenderer{
  public:
    QapDev&RD;
  public:
    void Do(TBot*p)
    {
      if(p->frame_s)
      {
        RD.SetColor(0xff000000);
        p->frame_s->Bind(&RD);
        real dhs=8;
        real r=p->r+dhs;
        vec2d pos=p->p+vec2d(1,-1);
        RD.DrawQuad(pos.x+0.5,pos.y+0.5,r*2.0,r*2.0);
      }
      RD.SetColor(0xffffffff);
      if(p->frame)p->frame->Bind(&RD);
      auto&r=p->r;
      auto&pos=p->p;
      RD.DrawQuad(pos.x+0.5,pos.y+0.5,r*2.0,r*2.0);
    }
    void Do(TBullet*p)
    {
      auto&r=p->r;
      auto&pos=p->p;
      RD.SetColor(0xffffffff);
      RD.DrawQuad(pos.x+0.5,pos.y+0.5,r*8.0*(96.0/64.0),r*8.0,p->v.GetAng());
    }
    void Do(TRespawn*p)
    {
      auto&pos=p->p;
      RD.SetColor(0xffffffff);
      RD.DrawQuad(pos.x+0.5,pos.y+0.5,64,64);
    }
    void Do(TBonus*p)
    {
      auto&pos=p->p;
      auto&ang=p->ang;
      auto&r=p->r;
      if(p->frame_s)
      {
        RD.SetColor(0xff000000);
        p->frame_s->Bind(&RD);
        real dhs=8;
        real r=p->r+dhs;
        vec2d pos=p->p+vec2d(1,-1);
        RD.DrawQuad(pos.x+0.5,pos.y+0.5,r*2.0,r*2.0,ang);
      }
      RD.SetColor(0xffffffff);
      if(p->frame)p->frame->Bind(&RD);
      RD.DrawQuad(pos.x+0.5,pos.y+0.5,r*2.0,r*2.0,ang);
    }
  };
public:
  class TEntityUpdater{
  public:
    TGameHC2013*Game;
    QapKeyboard*Keyboard;
    vec2d hms;
  public:
    void Init(TGameHC2013*Game){
      this->Game=Game;
      hms=Game->mapsize*0.5;
      Keyboard=Game->Keyboard.get();
    }
    void Do(TBot*p)
    {
      if(!p->frame_s)p->frame_s=Game->FrameBotA_s;
      bool hack_flag=Keyboard->Down[mbRight]||Game->Stage2;
      if((p->p-Game->You.p).Mag()>256)hack_flag=false;
      auto dv=-(p->p-Game->You.p).SetMag(p->power);
      if(hack_flag)dv*=-1;
      if(!p->deaded&&!p->isuser)p->v+=dv;
      p->p+=p->v;
      if(p->deaded||p->v.Mag()>1.5){p->v*=0.90;}else{p->v*=0.98;}
    }
    void Do(TBullet*p)
    {
      auto&pos=p->p;
      auto&v=p->v;
      auto&deaded=p->deaded;
      pos+=v;
      deaded=!CD_Rect2Point(+hms,-hms,pos);
    }
    void Do(TRespawn*p)
    {
      p->tick--;
      if(p->tick<=0)
      {
        p->tick=p->maxtick;
        Game->AddBot(*p,Game->FrameBotA);
      }
    }
    void Do(TBonus*p)
    {
      auto&pos=p->p;
      auto&ang=p->ang;
      auto&r=p->r;
      auto&v=p->v;
      auto&deaded=p->deaded;
      auto&action=p->action;
      pos+=v;
      ang+=0.01;
      if((pos-Game->You.p).Mag()<Game->You.r+r)
      {
        action->Use(p,Game);
        deaded=true;
      }
    }
  };
public:
  typedef QapAtlas::TFrame TFrame;
  bool AddBot(TRespawn&Respawn,TWeakPtr<TFrame>&frame,real power=0.15)
  {
    auto*pFrame=frame.get();
    return AddBotRaw(Respawn,pFrame,power);
  }
  bool AddBotRaw(TRespawn&Respawn,TFrame*frame,real power=0.15)
  {
    vec2d&p=Respawn.p;
    real r=8.0;
    for(int i=0;i<Bots.size();i++)
      if((Bots[i].p-p).Mag()<Bots[i].r+r)return false;
    for(int i=0;i<dBots.size();i++)
      if((dBots[i].p-p).Mag()<dBots[i].r+r)return false;
    if(BotLeft<=0)return false;
    Bots.push_back(TBot());
    auto&back=Bots.back();
    back.p=p;
    back.frame=frame;
    back.frame_s=FrameBotA_s.get();
    back.power=power;
    BotLeft--;
    Respawn.GenCount++;
    return true;
  }
public:
  void RestartGame()
  {
    You.isuser=true;You.p=vec2d_zero;You.r=16;You.hp=16;You.deaded=false;You.v=vec2d_zero;You.bonus_bullets=0;
    You.frame=FrameYou.get();
    You.frame_s=FrameYou_s.get();
    Winned=false;BotLeft=240;Shots=0;Frags=0;ForceAdded=0;BonusAdded=0;
    Stage2=false;
    Bots.clear();
    Respawns.clear();
    Bullets.clear();
    dBots.clear();
    Bonuses.clear();
    mapsize=vec2d(768,768);
    //MapQuad=TQuad(vec2d_zero,mapsize);
    winpos=vec2d(0.0,-mapsize.y*0.5);
    {
      vec2d mm=mapsize*0.5-vec2d(48,48);
      PointArray PA=MakeQuadAABB(+mm,-mm);
      Respawns.resize(PA.size());
      for(int i=0;i<PA.size();i++)
      {
        auto&ex=Respawns[i];
        ex.p=PA[i];
        ex.r=24;
        ex.maxtick=64;
        ex.tick=ex.maxtick;
      }
    }
    //Clock.Stop();
    //Clock.Start();
    TickCount=0;
  }
  void Fail()
  {
    You.deaded=true;
  }
  void Win()
  {
    Winned=true;
    //Clock.Stop();
  }
  real GameTime(){return real(TickCount)/real(64);}
  real CalcAccuracy(){return !Shots?0:real(Frags)*100.0/real(Shots);}
public:
  class TextRender{
  public:
    QapDev*RD;
    struct TextLine{
    public:
      string text;
      int x,y;
    public:
      TextLine(int x,int y,const string&text):x(x),y(y),text(text){}
    public:
      #define HALF_PIXEL 0.0
      void DrawRaw(QapDev*RD,QapFont*Font,int dv){QapQ3Text::DrawQapText(RD,*Font,x+dv+HALF_PIXEL,y-dv+HALF_PIXEL,QapQ3Text::ToNormal(text));}
      void DrawSys(QapDev*RD,QapFont*Font,int dv){QapQ3Text::DrawQapText(RD,*Font,x+dv+HALF_PIXEL,y-dv+HALF_PIXEL,text);}
      #undef HALF_PIXEL
    };
    vector<TextLine> LV;
    TextRender(QapDev*RD):RD(RD){}
  public:
    int x,y,ident;
    QapFontObject*NormFont;
    QapFontObject*BlurFont;
 public:
    void BeginScope(int X,int Y,TWeakPtr<QapFontObject>&NormFont,TWeakPtr<QapFontObject>&BlurFont)
    {
      this->NormFont=nullptr;
      this->BlurFont=nullptr;
      if(NormFont)this->NormFont=NormFont.get();
      if(BlurFont)this->BlurFont=BlurFont.get();
      x=X;
      y=Y;
      ident=24;
    }
    void AddText(const string&text)
    {
      LV.push_back(TextLine(x,y,text));y-=ident;
    }
    void EndScope()
    {
      RD->SetBlendMode(QapDev::BlendType::BT_SUB);
      //RD->SetAlphaMode(QapDev::AlphaType::AM_NONE);
      if(BlurFont)
      {
        RD->BindTex(0,&BlurFont->Tex);
        RD->SetColor(0xff000000);
        RD->BeginBatch();
        for(int i=0;i<LV.size();i++)LV[i].DrawRaw(RD,&BlurFont->Font,1.0);
        RD->EndBatch();
      }
      if(NormFont)
      {
        RD->BindTex(0,&NormFont->Tex);
        RD->SetColor(0xffffffff);
        RD->BeginBatch();
        for(int i=0;i<LV.size();i++)LV[i].DrawSys(RD,&NormFont->Font,0.0);
        RD->EndBatch();
      }
      //RD->SetAlphaMode(QapDev::AlphaType::AM_NONE);
    }
  };
public:
  void RenderText(QapDev&RD)
  {
    if(!NormFontObject||!BlurFontObject)return;
    TextRender TE(&RD);
    //vec2d hs=vec2d(Sys.SM.W,Sys.SM.H)*0.5;
    vec2d hs=vec2d(1366,768)*0.5;
    real ident=24.0;
    real Y=0;
    RD.SetColor(0xff000000);
    TE.BeginScope(-hs.x+ident,+hs.y-ident,NormFontObject,BlurFontObject);
    {
      string PreesR=" ^7(^3press ^2R^7)";
      if(ShowInfo)
      {
        string BEG="^7";
        string SEP=" ^2: ^8";
        #define GOO(TEXT,VALUE)TE.AddText(BEG+TEXT+SEP+VALUE);
        TE.AddText("^7The ^2Game");
        GOO("Time",FToS(GameTime())+"s.");
        GOO("Bots left",IToS(max(0,BotLeft)));
        GOO("Bots alive",IToS(Bots.size()));
        GOO("Frags",IToS(Frags));
        GOO("Accuracy",FToS(CalcAccuracy())+"%");
        GOO("Rage",FToS(real(Shots)*100.0/(GameTime()*8.0))+"%");
        GOO("Bonus Bullets",IToS(You.bonus_bullets));
        GOO("Force Bots",IToS(ForceAdded));
        GOO("Hp",IToS(You.hp));
        GOO("-----","-----");
        //GOO("Update",FToS(ClockUpdate.MS()));
        //GOO("Collide",FToS(ClockCollide.MS()));
        //GOO("CD_Bots",FToS(ClockBots.MS()));
        TE.AddText("");
        #undef GOO
        if(You.deaded)TE.AddText("^1You loser!"+PreesR);
        if(Winned)TE.AddText("^2You win!"+PreesR);
      }
      if(You.deaded)
      {
        TE.x=You.p.x-64;
        TE.y=You.p.y+32;
        TE.AddText("^1You louse!");
      }
      if(Winned)
      {
        TE.x=You.p.x-64;
        TE.y=You.p.y+32;
        TE.AddText("^2You win!");
      }
      if(IsWin()&&!Winned)
      {
        TE.x=winpos.x-16;
        TE.y=winpos.y+48;
        TE.AddText("^2Here!");
      }
    }
    TE.EndScope();
  }
  template<class A,class B> bool CD_Test(A&a,B&b)
  {
    //return (a.p-b.p).Mag()<a.r+b.r;   
    real d=a.r+b.r;
    real dx=a.p.x-b.p.x;
    if(fabs(dx)>d)return false;
    real dy=a.p.y-b.p.y;
    if(fabs(dy)>d)return false;
    real dd=d*d;
    return dd>(dx*dx+dy*dy);
  }
  //vec2d ClampCircleToRect(vec2d pos,real r,vec2d rect_pos,vec2d rect_size)
  void CD_BotVsBot(TBot&ef,TBot&es)
  {
    if(CD_Test(ef,es))
    {
      real rr=ef.r+es.r;
      vec2d d=ef.p-es.p;
      real dm=d.Mag();
      real mf=ef.r*ef.r;
      real ms=es.r*es.r;
      real inv_m=1.0/(mf+ms);
      mf*=inv_m;
      ms*=inv_m;
      ef.v+=d.SetMag((rr-dm)*ms);
      es.v-=d.SetMag((rr-dm)*mf);
    }
  };
  void CD_BotVsBullet(TBot&ef,TBullet&es)
  {
    if(es.deaded)return;
    if(CD_Test(ef,es))
    {
      real rr=ef.r+es.r;
      if(ef.hp==es.damage)
      {
        ef.deaded=true;
        es.deaded=true;
        Frags++;
      }
      if(ef.hp<es.damage){
        ef.deaded=true;
        es.damage-=ef.hp;
        Frags++;
      }else if(ef.hp>es.damage){
        ef.hp-=es.damage;
        es.deaded=true;
      }
      vec2d d=ef.p-es.p;
      real dm=d.Mag();
      real mf=ef.r*ef.r;
      real ms=es.r*es.r;
      real inv_m=1.0/(mf+ms);
      mf*=inv_m*1.0;
      ms*=inv_m*1.0;
      ef.v+=d.SetMag((rr-dm)*ms);
      es.v-=d.SetMag((rr-dm)*mf);
    }
  };
  void CD_BotVsRespawn(TBot&ef,TRespawn&es)
  {
    if(CD_Test(ef,es))
    {
      //real rr=ef.r+es.r;
      vec2d d=ef.p-es.p;
      real dm=d.Mag();
      real mf=ef.r*ef.r;
      real ms=es.r*es.r;
      real inv_m=1.0/(mf+ms);
      mf*=inv_m;
      ms*=inv_m;
      ef.v+=d.SetMag(0.5);
      //es.v-=d.SetMag((rr-dm)*mf);
    }
  };
  void ClampBot(const TQuad&MapQuad,TBot&ex){ex.p=ClampCircleToQuad(ex.p,ex.r,MapQuad);}
  /*QapClock ClockBots;
  static void ToggleIf(bool&flag,DWORD key)
  {
    if(QapInput::Down[key]){
      flag=!flag;
      QapInput::Down[key]=false;
    }
  }*/
  void Collide()
  {
    //return;
    for(int j=0;j<Respawns.size();j++)CD_BotVsRespawn(You,Respawns[j]);
    for(int i=0;i<Bots.size();i++)for(int j=0;j<Respawns.size();j++)CD_BotVsRespawn(Bots[i],Respawns[j]);
    for(int i=0;i<dBots.size();i++)for(int j=0;j<Respawns.size();j++)CD_BotVsRespawn(dBots[i],Respawns[j]);
    //ClockBots.Start();
    for(int i=0;i<Bots.size();i++)for(int j=i+1;j<Bots.size();j++)CD_BotVsBot(Bots[i],Bots[j]);
    for(int i=0;i<dBots.size();i++)for(int j=i+1;j<dBots.size();j++)CD_BotVsBot(dBots[i],dBots[j]);
    for(int i=0;i<Bots.size();i++)for(int j=0;j<dBots.size();j++)CD_BotVsBot(Bots[i],dBots[j]);
    //ClockBots.Stop();
    for(int i=0;i<Bots.size();i++)for(int j=0;j<Bullets.size();j++)CD_BotVsBullet(Bots[i],Bullets[j]);
    //for(int i=0;i<dBots.size();i++)for(int j=0;j<Bullets.size();j++)CD_BotVsBullet(dBots[i],Bullets[j]);
    for(int i=0;i<dBots.size();i++)CD_BotVsBot(You,dBots[i]);
    for(int i=0;i<Bots.size();i++)
    {
      real rr=32/2+Bots[i].r;
      if((Bots[i].p-You.p).Mag()<rr)
      {
        Bots[i].deaded=true;
        You.hp--;
        Frags++;
      }
    }
    if(IsRunned())
    {
      for(int j=0;j<Bullets.size();j++)
      {
        real rr=48/2+Bullets[j].r;
        if((Bullets[j].p-winpos).Mag()<rr)
        {
          TBullet&ex=Bullets[j];
          vec2d ox=ex.p-winpos;
          vec2d vox=ex.v.Rot(ox);
          ex.v=vec2d(abs(vox.x),vox.y).UnRot(ox);
          //Bullets[j].deaded=true;
          int id=-1;int minv=-1;
          for(int i=0;i<Respawns.size();i++)if(id<0||minv>Respawns[i].GenCount){id=i;minv=Respawns[i].GenCount;}
          if(id==-1){
            int wtf=111;
          }
          int rnd_val=rand()%5;
          if(rnd_val<=2){
            AddBot(Respawns[id],FrameBotB,0.20);
          }else{
            AddBot(Respawns[id],FrameBotC,0.10);
          }
          ForceAdded++;
        }
      }
    }
    TQuad MapQuad(vec2d(0,0),mapsize);
    ClampBot(MapQuad,You);
    for(int i=0;i<Bots.size();i++)ClampBot(MapQuad,Bots[i]);
    for(int i=0;i<dBots.size();i++)ClampBot(MapQuad,dBots[i]);
  }
  bool IsRunned(){return (BotLeft>0);}
  bool IsWin(){return !IsRunned()&&!Bots.size();}
  template<class TYPE>
  static void UpdateEntities(TEntityUpdater&EU,vector<TYPE>&arr)
  {
    for(size_t i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      EU.Do(&ex);
    }
  }
  template<class TYPE>
  static void RenderEntities(TEntityRenderer&ER,vector<TYPE>&arr)
  {
    for(size_t i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ER.Do(&ex);
    }
  }
public:
  void AddBullet(const vec2d&p,const vec2d&v,real damage)
  {
    Bullets.push_back(TBullet());
    auto&back=Bullets.back();
    back.p=p;
    back.v=v;
    back.r=2;
    back.deaded=false;
    back.damage=damage;
  }
  TBonus&AddBonus(TWeakPtr<TFrame>&Frame,TWeakPtr<TFrame>&Frame_s,TBonus::IAction&Action)
  {
    TQuad MapQuad(vec2d_zero,mapsize);
    Bonuses.push_back(TBonus());
    auto&back=Bonuses.back();
    back.p=MapQuad.RndPoint();
    back.action=&Action;
    back.frame=Frame.get();
    back.frame_s=Frame_s.get();
    return back;
  }
public:
  template<int>
  vec2d Weak_GetMousePos()
  {
    if(!TheUnit)return vec2d(0,0);
    auto*pUnit=this->TheUnit.get();
    return pUnit->ProgramD3D9->WindowGetMousePos();
  }
  vec2d GetMousePos(){return Weak_GetMousePos<0>();}
public:
  template<class TYPE>
  inline static void Clean(TYPE&Arr)
  {
    int c=Arr.size();
    int j=-1;
    for(int i=0;i<c;i++)
    {
      if(!Arr[i].deaded&&i!=j)Arr[++j]=Arr[i];
    }
    Arr.resize(j+1);
  }
public:
  void Update(IEnv&Env)
  {
    if(!Keyboard)return;
    auto*pKeyboard=Keyboard.get();
    auto&Down=pKeyboard->Down;
    if(Frags==450){
      Stage2=true;
      for(int i=0;i<Respawns.size();i++)
      {
        Respawns[i].maxtick=8;
        Respawns[i].tick=10;
      }
    }
    if(Frags==1000){
      Stage2=false;
      for(int i=0;i<Respawns.size();i++)
      {
        Respawns[i].maxtick=5;
        Respawns[i].tick=10;
      }
    }
    if(Down[VK_END]){
      for(int i=0;i<Bots.size();i++)
      {
        Bots[i].deaded=true;
      }
      for(int i=0;i<Respawns.size();i++)
      {
        Respawns[i].maxtick=2;
        Respawns[i].tick=10;
      }
      //TickCount+=25000;
    }
    //ClockUpdate.Start();
    //if(Down[VK_ESCAPE]){Sys.Quit();}
    {
      if(Down['R']){RestartGame();}
      if(You.deaded||Winned)return;
    }
    {
      vec2d dv(vec2d_zero);
      if(Down[VK_LEFT])dv+=vec2d(-1,0);
      if(Down[VK_RIGHT])dv+=vec2d(+1,0);
      if(Down[VK_UP])dv+=vec2d(0,+1);
      if(Down[VK_DOWN])dv+=vec2d(0,-1);
      You.v+=dv.SetMag(0.22);
    }
    TEntityUpdater EU;
    EU.Init(this);
    {
      EU.Do(&You);
      UpdateEntities(EU,Bots);
      UpdateEntities(EU,dBots);
      UpdateEntities(EU,Bullets);
      UpdateEntities(EU,Bonuses);
      if(IsRunned())
      {
        UpdateEntities(EU,Respawns);
      }
    }
    //ClockCollide.Start();
    Collide();
    //ClockCollide.Stop();
    {
      if(You.hp<=0)Fail();
      if(IsWin()&&(You.p-winpos).Mag()<(24))Win();
    }
    {
      static int tickmax=64/8;
      static int tick=tickmax;
      tick--;
      if(Down[mbLeft]&&tick<=0)
      {
        tick=tickmax;
        int&bb=You.bonus_bullets;
        AddBullet(You.p,-(You.p-GetMousePos()).SetMag(6.25),bb>0?bb--,2.0+int(bb-1)/128:1.0);
        Shots++;
      }
    }
    if(ForceAdded/16>BonusAdded)
    {
      static bool used=false;
      BonusAdded++;
      int rnd=rand()%2;
      if(rnd==0)
      {
        AddBonus(FrameBonus,FrameBonus_s,ActionAddBullet);
      }
      if(rnd==1)
      {
        AddBonus(FrameHealth,FrameHealth_s,ActionAddHP);
      }
    }
    {
      for(int i=0;i<Bots.size();i++)if(Bots[i].deaded)
      {
        auto&ex=Bots[i];
        auto*frame=ex.frame.get();
        if(frame==FrameBotA.get())ex.frame=FramedBotA.get();
        if(frame==FrameBotB.get())ex.frame=FramedBotB.get();
        if(frame==FrameBotC.get())ex.frame=FramedBotC.get();
        dBots.push_back(std::move(ex));
        ex.deaded=true;
      }
      Clean(Bots);
      Clean(Bullets);
      Clean(Bonuses);
    }
    TickCount++;
    //ClockUpdate.Stop();
  }
};

class TGameHC2013Friend:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameHC2013Friend)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TGameHC2013>,Game,DEF,$,$)\
ADDVAR(int,GameSpeed,SET,1,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDEND()
//=====+>>>>>TGameHC2013Friend
#include "QapGenStruct.inl"
//<<<<<+=====TGameHC2013Friend
public:
  void Render(QapDev&qDev){
    if(!Visible)return;
    if(!Game)return;
    auto*game=Game.get();
    game->Render(qDev);
  }
  void Update(IEnv&Env){
    if(!Enabled)return;
    if(!Game)return;
    auto*game=Game.get();
    for(int i=GameSpeed;i>0;i--){
      game->Update(Env);
    }
  }
};

class TSomeObject001:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeObject001)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(real,x,SET,0,$)\
ADDVAR(real,y,SET,0,$)\
ADDVAR(real,w,SET,10,$)\
ADDVAR(real,h,SET,10,$)\
ADDVAR(int,tick,SET,0,$)\
ADDVAR(real,speed,SET,1.0,$)\
ADDVAR(int,r,SET,0,$)\
ADDVAR(int,g,SET,0,$)\
ADDVAR(int,b,SET,0,$)\
ADDVAR(int,a,SET,255,$)\
ADDVAR(bool,NeedBindZeroTex,SET,true,$)\
ADDVAR(bool,NeedSetColor,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDEND()
//=====+>>>>>TSomeObject001
#include "QapGenStruct.inl"
//<<<<<+=====TSomeObject001
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
    static bool flag=false;
    if(!flag){
      flag=true;
      save_as_json(Env.Env);
    }
  }
  void save_as_json(IEnvRTTI&Env)
  {
    QapPublicUberFullSaverProto(Env,std::move(QapRawUberObject(*this)),"some_onj.txt");
    auto*pType=Sys$$<SelfClass>::GetRTTI(Env);
    auto&arr=pType->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto*ptr=arr[i].getValue(this);
      //arr[i].Name+":"+arr[i].Type->
    }
  }
};

class TSomeObject002:public IRenderProgram{
public:
  class TPoint{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPoint)OWNER(TSomeObject002)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vec2d,p,SET,vec2d(0,0),$)\
    ADDVAR(vec2d,v,SET,vec2d(0,0),$)\
    ADDEND()
  //=====+>>>>>TPoint
  #include "QapGenStruct.inl"
  //<<<<<+=====TPoint
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(TPoint)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeObject002)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TPoint>,arr,DEF,$,$)\
ADDVAR(int,point_size,SET,8,$)\
ADDVAR(int,tick,SET,0,$)\
ADDVAR(int,x_init_speed,SET,0,$)\
ADDVAR(int,y_init_speed,SET,0,$)\
ADDVAR(int,speed,SET,1,$)\
ADDVAR(int,r,SET,255,$)\
ADDVAR(int,g,SET,128,$)\
ADDVAR(int,b,SET,0,$)\
ADDVAR(int,a,SET,255,$)\
ADDVAR(bool,NeedBindZeroTex,SET,true,$)\
ADDVAR(bool,NeedSetColor,SET,true,$)\
ADDVAR(bool,NeedRestart,SET,false,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDEND()
//=====+>>>>>TSomeObject002
#include "QapGenStruct.inl"
//<<<<<+=====TSomeObject002
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
      for(int i=0;i<arr.size();i++)
      {
        //qDev.DrawQuad(arr[i].p.x,arr[i].p.y,point_size,point_size,0);
        qDev.DrawCircle(arr[i].p,point_size,0,1,16);
        qDev.DrawCircle(arr[i].p,point_size*0.5,0,4,16);
      }
      qDev.SetColor(0xff303030);
      qDev.DrawCircle(vec2d(0,0),380,0,1,64);
    }
  }
  bool GoSimulate()
  {
    real dist=(arr[0].p-arr[1].p).Mag();
    real treshold=0.0001;
    bool flag=false;
    for(int i=0;i<16*1024;i++)
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
  void Restart()
  {
    NeedRestart=false;
    //return;
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
    return;
    arr.clear();
    arr.resize(3);
    arr[0].p=vec2d(-200,-100);
    arr[1].p=vec2d(+200,+50);
    arr[2].p=vec2d(0,100);
    arr[2].v=vec2d(+x_init_speed*0.01,+y_init_speed*0.01);
    arr[0].v=vec2d(-x_init_speed*0.01,-y_init_speed*0.01);
  }
  void OneStep()
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
        sum+=f;
      }
      //if(sum.Mag()>0.01)sum.SetMag(0.01);
      ex.p+=ex.v;
      //ex.v*=0.99999999;
      ex.v+=sum;
      if(arr[i].p.Mag()>380)
      {
        ex.p=arr[i].p.SetMag(380);
        ex.v=vec2d(0,ex.v.Rot(ex.p).y*0.9).UnRot(ex.p);
      }
    }
  }
  void Update(IEnv&Env)
  {
    if(!Enabled)return;
    if(NeedBindZeroTex)
    {
      //NeedBindZeroTex=false;
      vec2d sum_v=vec2d(0,0);
      vec2d sum_p=vec2d(0,0);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        sum_v+=ex.v;
        sum_p+=ex.p;
      }
      //sum_p*=0.5;
      //sum_v*=0.5;
      sum_v*=1.0/real(arr.size());
      sum_p*=1.0/real(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.v-=sum_v;
        ex.p-=sum_p;
      }
    }
    if(NeedRestart)Restart();
    for(int k=0;k<speed;k++)OneStep();    
    tick++;
    static bool flag=false;
    if(!flag){
      flag=true;
      save_as_json(Env.Env);
    }
  }
  void save_as_json(IEnvRTTI&Env)
  {
    QapPublicUberFullSaverProto(Env,std::move(QapRawUberObject(*this)),"some_obj.txt");
    auto*pType=Sys$$<SelfClass>::GetRTTI(Env);
    auto&arr=pType->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto*ptr=arr[i].getValue(this);
      //arr[i].Name+":"+arr[i].Type->
    }
  }
};

class MeUnitHC2013:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnitHC2013)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(int,value,SET,0,$)\
ADDVAR(string,str_value,DEF,$,$)\
ADDVAR(bool,auto_inc,SET,true,$)\
ADDVAR(bool,auto_itos,SET,true,$)\
ADDVAR(TWeakPtr<QapRenderProgram>,RenderProgram,DEF,$,$)\
ADDVAR(TWeakPtr<IProgramD3D9>,ProgramD3D9,DEF,$,$)\
ADDVAR(TWeakPtr<TProgramNode>,UserCode,DEF,$,$)\
ADDVAR(TWeakPtr<QapKeyboard>,Keyboard,DEF,$,$)\
ADDVAR(TGameHC2013,Game,DEF,$,$)\
ADDVAR(bool,need_init_game,SET,false,$)\
ADDEND()
//=====+>>>>>MeUnitHC2013
#include "QapGenStruct.inl"
//<<<<<+=====MeUnitHC2013
public:
  static void SysHasSelf();
public:
  void OnBuild(TBuildContext&Context)
  {
    auto&Env=Context.Env;
    auto&Qrp=Context.Qrp;
    auto&PluginMan=Context.PluginMan;
    //if(Qrp.Scene.Items.empty())
    {
      RenderProgram=&Qrp;
      ProgramD3D9=Qrp.Program.get();
      UserCode=&Qrp.Program->UserCode;
      Keyboard=&ProgramD3D9->GetKeyBoard();
    }
    Game.TheUnit=this;
  }
  void Update(IEnvRTTI&Env)
  {
    if(auto_inc)value++;
    if(auto_itos)str_value=IToS(value);
    if(Keyboard)
    {
      auto&keyboard=*Keyboard.get();
      if(keyboard.Down[VK_SPACE])
      {
        keyboard.Down[VK_SPACE]=false;
      }
    }
    if(need_init_game)
    {
      need_init_game=false;
      Game.Init(Env,*this);
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
        F(TRenderNodeEx)\
        F(MeUnitHC2013)F(TGameHC2013Friend)F(QapGameObject)F(TSomeObject001)F(TSomeObject002)
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
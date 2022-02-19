class TUserBody{
public:
#define PRO_VARIABLE()\
ADDVAR(vector<vec2d>,PA,vector<vec2d>())\
ADDVAR(bool,deaded,false)\
ADDVAR(int,n,1)\
ADDVAR(bool,use_mouse,false)\
ADDVAR(real,size,32);\
ADDVAR(real,Speed,2.5);\
ADDVAR(real,dAng,6.28/(2*Sys.UPS));\
ADDVAR(vec2d,p,vec2d_zero)\
ADDVAR(vec2d,v,vec2d(Speed,0))\
ADDVAR(TGame*,Game,NULL)
//=====+>>>>>TUserBody
#include "GenVar.inl"
//<<<<<+=====TUserBody
public:
  void Init(TGame*Game)
  {
    this->Game=Game;//костыль? да!!!
  }
  int CD_Points2Segment(const vec2d&A,const vec2d&B){
    //int Result=-1;
    const int C=int(size/Speed);
    const real dx=(PA[0]-p).Mag();
    for(int i=0;(i<n)&&(1+i*C<PA.size());i++)
    {
      auto a=PA[i*C];
      auto b=PA[1+i*C];
      a=b+(a-b).SetMag(dx);
      if(CD_Circle2Segment(a,A,B,16)){
        return i;
      }
    }
    return -1;
  }
  void Update(TGame*Game)
  {
    if(!deaded){
      real dk=0;
      if(QapInput::Down[VK_LEFT]||QapInput::Down['A']){dk=+1;}
      if(QapInput::Down[VK_RIGHT]||QapInput::Down['D']){dk=-1;}
      if(QapInput::Down['Q']){dk+=+0.5;}
      if(QapInput::Down['E']){dk+=-0.5;}
      if(QapInput::Down['Z']){dk=+1.5;}
      if(QapInput::Down['C']){dk=-1.5;}
      if(QapInput::Down['G']){dk=+3;}
      if(QapInput::Down['H']){dk=-3;}
      if(QapInput::Down['T']){dk=+5;}
      if(QapInput::Down['Y']){dk=-5;}
      if(QapInput::OnDown(VK_SPACE)){use_mouse=!use_mouse;}
      if(use_mouse){dk=(QapInput::MousePos-p).Norm().Rot(v).GetAng()/dAng;}
      if(dk)v=Vec2dEx(v.GetAng()+Clamp(dk,-5.0,+5.0)*dAng,Speed);
    }
    const int C=int(size/Speed);
    const real eps=1e-03;
    for(int i=2;(i<n)&&(1+i*C<PA.size());i++){
      if((PA[i*C]-p).Mag()<28)deaded=true;
    }
    if(v.Mag()>eps)v=v.SetMag(deaded?v.Mag()*0.99:Speed);
    p+=v;
    if(PA.empty()){PA.push_back(p);}else
    {
      const real dp=(PA[0]-p).Mag();
      int c=dp/(Speed-eps);
      if(c>2)DebugBreak();
      //if(c<1)_asm{int 3};
      vec2d curp=PA[0];
      vec2d dv=v.SetMag(Speed);
      for(int j=0;j<c;j++)
      {
        curp+=dv;
        if(PA.size()<n*C*2)PA.push_back(curp);
        for(int i=PA.size()-1;i>0;i--)PA[i]=PA[i-1];
        PA[0]=curp;
        if(PA.size()>n*C*2){PA.pop_back();}
      }
    }
  }
  static void DrawQuad(QapDev*RD,const vec2d&pos,const vec2d&prevpos,QapAtlas::TFrame*Frame,const vec2d&offset=vec2d(1.0,-1.0))
  {
    vec2d p=vec2d(int(pos.x),int(pos.y))+vec2d(0.5,0.5)+offset;
    RD->DrawQuad(p.x,p.y,Frame->w,Frame->h,(pos-prevpos).GetAng());
  }
  static void DrawQuadEx(QapDev*RD,const vec2d&pos,const vec2d&prevpos,QapAtlas::TFrame*Frame,const real dx,const vec2d&offset=vec2d(1.0,-1.0))
  {
    auto a=pos;auto b=prevpos;a=b+(a-b).SetMag(dx);
    //vec2d p=vec2d(int(pos.x),int(pos.y))+vec2d(0.5,0.5)+offset;
    vec2d p=pos+vec2d(0.5,0.5)+offset;
    RD->DrawQuad(a.x,a.y,Frame->w,Frame->h,(pos-prevpos).GetAng());
  }
  void Render(QapDev*RD)
  {
    const int C=int(size/Speed);
    const real eps=1e-03;
    if(PA.empty())return;
    //if(QapInput::Down[VK_SPACE]){_asm{int 3};}
    const real dp=(PA[0]-p).Mag();
    const real dx=dp;//-real(int(dp/Speed))*Speed;
    {
      RD->SetColor(0xff000000);
      Game->FrameBody_s->Bind(RD);
      for(int i=1;(i<n)&&(1+i*C<PA.size());i++)DrawQuadEx(RD,PA[i*C],PA[1+i*C],Game->FrameBody_s,dx);
      Game->FrameHead_s->Bind(RD);
      for(int i=0;(!i)&&(1+i*C<PA.size());i++)DrawQuadEx(RD,PA[i*C],PA[1+i*C],Game->FrameHead_s,dx);
    }
    {
      QapDev::BatchScope Scope(*RD);
      RD->SetColor(0xffffffff);
      Game->FrameBody->Bind(RD);
      for(int i=1;(i<n)&&(1+i*C<PA.size());i++)DrawQuadEx(RD,PA[i*C],PA[1+i*C],Game->FrameBody,dx,vec2d_zero);
      Game->FrameHead->Bind(RD);
      for(int i=0;(!i)&&(1+i*C<PA.size());i++)DrawQuadEx(RD,PA[i*C],PA[1+i*C],Game->FrameHead,dx,vec2d_zero);
    }
    if(use_mouse){
      RD->BindTex(0,0);
      auto mp=QapInput::MousePos;
      RD->color=0xff000000;
      RD->DrawQuad(mp.x,mp.y,16,16,PiD4);
      RD->color=0xffffffff;
      RD->BindTex(0,Game->Atlas.pTex);
    }
  }
};

static vec2d rndvec2d(real wh=768-64){return vec2d(RndReal(0,wh),RndReal(0,wh))-0.5*wh*vec2d(1,1);}
static vec2d rndvec2d(real w,real h){return vec2d(RndReal(0,w),RndReal(0,h))-0.5*vec2d(w,h);}
class TRock{
#define PRO_VARIABLE()\
ADDVAR(bool,dead,false)\
ADDVAR(QapColor,color,0xffffffff);\
ADDVAR(vec2d,p,vec2d_zero)\
ADDVAR(real,ang,0)\
ADDVAR(real,scale,1.0)\
ADDVAR(int,type,0)\
//=====+>>>>>TRock
#include "GenVar.inl"
//<<<<<+=====TRock
public:
};

class TCell{
#define PRO_VARIABLE()\
ADDVAR(bool,dead,false)\
ADDVAR(real,size,32);\
ADDVAR(QapColor,color,0xffffffff);\
ADDVAR(vec2d,p,vec2d_zero)\
ADDVAR(vec2d,p1,vec2d_zero)\
ADDVAR(vec2d,p2,vec2d_zero)\
ADDVAR(TGame*,Game,NULL)
//=====+>>>>>TCell
#include "GenVar.inl"
//<<<<<+=====TCell
public:
  void Init(TGame*Game){this->Game=Game;}
  void Render(QapDev*RD)
  {
    if(dead)return;
    auto*ptr=&p;
    for(int i=0;i<3;i++){
      auto&p=ptr[i];
      RD->SetColor(0xff000000);
      if(0==i)RD->color.a=0xff;
      if(1==i)RD->color.a=0x80;
      if(2==i)RD->color.a=0x20;
      Game->FramePoint_s->Bind(RD);
      TUserBody::DrawQuad(RD,p,p+vec2d(-1.0,0),Game->FramePoint_s);
      RD->SetColor(color);
      if(0==i)RD->color.a=0xff;
      if(1==i)RD->color.a=0x80;
      if(2==i)RD->color.a=0x20;
      Game->FramePoint->Bind(RD);
      TUserBody::DrawQuad(RD,p,p+vec2d(-1.0,0),Game->FramePoint,vec2d_zero);
    }
  }
  template<class CB>
  void Update(TUserBody&User,CB&&OnPickCell){
    if(dead)return;
    if((User.p-p).Mag()<32)
    {
      OnPickCell();
    }
  };
  void shift(){
    const real wh=768-64;
    auto newp=rndvec2d(wh);
    p=p1;
    p1=p2;
    p2=newp;
  }
};

class TCounterInc{
#define PRO_VARIABLE()\
ADDVAR(int,Value,0)\
ADDVAR(int,Minimum,0)\
ADDVAR(int,Maximum,32)
//=====+>>>>>TCounterInc
#include "GenVar.inl"
//<<<<<+=====TCounterInc
public:
  TCounterInc(){DoReset();}
  TCounterInc(int Value,int Minimum,int Maximum){this->Value=Value;this->Minimum=Minimum;this->Maximum=Maximum;}
  void Start(){Value=Minimum;}
  void Stop(){Value=Maximum;}
  operator bool(){return Value<Maximum;}
  void operator++(){Value++;}
  void operator++(int){Value++;}
  int DipSize(){return Maximum-Minimum;}
  operator string(){return IToS(Value)+"/"+IToS(DipSize());}
};

class TCounterIncEx{
#define PRO_VARIABLE()\
ADDVAR(int,Value,0)\
ADDVAR(int,Minimum,0)\
ADDVAR(int,Maximum,32)\
ADDVAR(bool,Runned,false);
//=====+>>>>>TCounterIncEx
#include "GenVar.inl"
//<<<<<+=====TCounterIncEx
public:
  TCounterIncEx(){DoReset();}
  TCounterIncEx(int Value,int Minimum,int Maximum){DoReset();this->Value=Value;this->Minimum=Minimum;this->Maximum=Maximum;}
  void Start(){Value=Minimum;Runned=true;}
  void Stop(){Value=Minimum;Runned=false;}
  operator bool(){return Value<Maximum;}
  void operator++(){if(Runned)Value++;}
  void operator++(int){if(Runned)Value++;}
  int DipSize(){return Maximum-Minimum;}
  operator string(){return IToS(Value)+"/"+IToS(DipSize());}
};
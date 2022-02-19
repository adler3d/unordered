static const int Sys_UPD=64;
//#define LEVEL_LIST(F)F(Level3);F(Level2);F(Level0);F(Level1);
#define LEVEL_LIST(F)F(Voronoi_diagram)F(Level0);F(Level1);F(Level2);F(Level3);F(Level_RT_Sprite_Test);
class Level0:public TGame::ILevel{
public:
#define PRO_VARIABLE()\
ADDVAR(TGame*,Game,NULL)\
ADDVAR(TCounterInc,PointCounter,TCounterInc(0,0,3))\
ADDVAR(int,frame,0)\
ADDVAR(real,Speed,2.5)\
ADDVAR(real,dAng,6.28/(2*Sys_UPD))\
ADDVAR(vec2d,p,vec2d_zero)\
ADDVAR(vec2d,v,vec2d(Speed,0))\
ADDVAR(vector<TCell>,cells,{})\
ADDVAR(vec2d,hms,vec2d(768,768)*0.5)\
ADDVAR(TUserBody,User,{})\
ADDVAR(vector<TRock>,rocks,{})\
//=====+>>>>>Level0
#include "GenVar.inl"
//<<<<<+=====Level0
public:
  #define ROCK_LIST(F)F(tank_hodun)F(Rock)F(Rock2)F(Rock3)F(Rock4)
  size_t rock_n(){
    #define F(NAME)+1
    return ROCK_LIST(F);
    #undef F
  }
  void Init(TGame*Game){
    DoReset();
    this->Game=Game;
    User.DoReset();
    User.Init(Game);
    User.Speed=Speed;
    User.dAng=dAng;
    User.p=p;
    User.v=v;
    User.n=15;
    cells.resize(3);
    {int i=0;QapColor colors[]={0xffffAA00,0xffAAff00,0xffff00};
    for(auto&cell:cells){
      cell.DoReset();
      cell.Init(Game);
      cell.shift();
      cell.shift();
      cell.shift();
      cell.color=colors[i];
      cell.color.a=0xff;
      i++;
    }}
    rocks.resize(128);
    for(auto&ex:rocks){
      ex.p=rndvec2d(1920);
      ex.ang=RndReal(0,Pi2);
      ex.type=rand()%rock_n();
      ex.scale=RndReal(0.5,1);
    }
  };
  static void draw_rock(QapDev*RD,QapAtlas::TFrame*pF,TRock&ex,bool shadow){
    RD->SetColor(shadow?0xff000000:0xffDDDDEE);
    pF->Bind(RD);
    auto p=ex.p;
    if(shadow)p+=vec2d(1.0,-1.0);
    RD->DrawQuad(p.x,p.y,pF->w*ex.scale,pF->h*ex.scale,ex.ang);
  }
  void Render(QapDev*RD){
    if(0)
    {
      vec2d hms=vec2d(768,768)*0.5;
      vec2d pmin(+hms),pmax(-hms);
      RD->SetBlendMode(QapDX::BT_SUB);
      RD->SetColor(0xff008000);
      RD->BindTex(0,0);
      //RD->DrawPolyLine(MakeQuadAABB(pmin,pmax),2,true);
    }
    if(bool need_draw_rock0_as_thrt=true){
      auto*pF=Game->th_rt_tex;auto&qDev=*RD;
      qDev.BindTex(0,pF);
      qDev.SetColor(0xffffffff);
      for(auto&ex:rocks)if(ex.type==0){
        RD->DrawQuad(ex.p.x,ex.p.y,pF->W*ex.scale*0.25,pF->H*ex.scale*0.25,ex.ang);
      }
      RD->BindTex(0,0);
    }
    RD->BindTex(0,Game->Atlas.pTex);
    if(bool need_draw_points=true){
      QapDev::BatchScope Scope(*RD);
      typedef std::pair<QapAtlas::TFrame*,QapAtlas::TFrame*> rock_pair;
      #define F(NAME)std::make_pair(Game->Frame##NAME,Game->Frame##NAME##_s),
      rock_pair r[]={ROCK_LIST(F)rock_pair(nullptr,nullptr)};
      #undef F
      for(auto&ex:rocks)if(ex.type!=0)draw_rock(RD,r[ex.type].second,ex,1);
      for(auto&ex:rocks)if(ex.type!=0)draw_rock(RD,r[ex.type].first,ex,0);
    }
    RD->SetColor(0xffffffff);
    for(auto&cell:cells)cell.Render(RD);
    if(bool need_draw_user=true)
    {
      RD->SetBlendMode(QapDX::BT_SUB);
      RD->SetColor(0xff000000);
      RD->BindTex(0,Game->Atlas.pTex);
      User.Render(RD);
    }
  }
  #undef ROCK_LIST
  static bool CollideWithPolySegment(TGame::TUserBody&User,PointArray&PA)
  {
    int c=PA.size();
    for(int i=0;i<c;i++)
      if(-1!=User.CD_Points2Segment(PA[(i+0)%c],PA[(i+1)%c]))
        return true;
    return false;
  }
  void Update(TGame*Game){
    if(Win()){User.deaded=true;}else{frame++;}
    User.Update(Game);
    for(auto&cell:cells)cell.Update(User,[&](){OnPickCell(cell);});
  };
  bool Win(){return !PointCounter;}
  bool Fail(){return User.deaded;}
  void OnPickCell(TCell&cell){
    if(!PointCounter)return;
    PointCounter++;
    User.n++;//dead=true;
    cell.dead=!PointCounter;
    cell.shift();
  };
  void AddText(TextRender*TE){
    string BEG="^7";
    string SEP=" ^2: ^8";
    #define GOO(TEXT,VALUE)TE->AddText(string(BEG)+string(TEXT)+string(SEP)+string(VALUE));
    GOO("PointCounter",PointCounter);
    GOO("frame",IToS(frame));
    GOO("frame/pc",PointCounter.Value?FToS(frame/PointCounter.Value):"0");
    #undef GOO
  }
};
class Level1:public Level0{
public:
#define PRO_VARIABLE()\
ADDVAR(TCounterInc,PointCounter,TCounterInc(0,0,15))\
ADDVAR(real,Speed,2.5)\
ADDVAR(real,dAng,6.28/(2*Sys_UPD))\
//=====+>>>>>Level1
#include "GenVar.inl"
//<<<<<+=====Level1
public:
  void Init(TGame*Game){
    Level0::Init(Game);
    Level0::PointCounter=PointCounter;
    User.Speed=Speed;
    User.dAng=dAng;
    User.n=3;
  };
};
class Level2:public Level0{
public:
#define PRO_VARIABLE()\
ADDVAR(TCounterInc,PointCounter,TCounterInc(0,0,55+90))\
ADDVAR(real,Speed,3.5)\
ADDVAR(real,dAng,0.3*6.28/(1.42*Sys_UPD))\
//=====+>>>>>Level1
#include "GenVar.inl"
//<<<<<+=====Level1
public:
  void Init(TGame*Game){
    Level0::Init(Game);
    Level0::PointCounter=PointCounter;
    User.Speed=Speed;
    User.dAng=dAng;
    User.n=2;
  };
};
class Level3:public TGame::ILevel{
public:
#define PRO_VARIABLE()\
ADDVAR(TGame*,Game,NULL)\
ADDVAR(int,t,0)\
ADDVAR(vector<vec2d>,points,{})\
ADDVAR(vector<vec2d>,reds,{})\
//=====+>>>>>Level3
#include "GenVar.inl"
//<<<<<+=====Level3
public:
  void Init(TGame*Game){
    this->Game=Game;
    t=0;
  };
  void Render(QapDev*RD){
    auto&qDev=*RD;
    qDev.BindTex(0,0);
    qDev.SetColor(0xffffffff);
    qDev.DrawQuad(0,0,400,400,t*0.01);
    qDev.DrawQuad(QapInput::MousePos.x,QapInput::MousePos.y,10,10,t*0.01);
    qDev.SetColor(0xff000000);
    for(int i=0;i<points.size();i++){auto&p=points[i];qDev.DrawQuad(p.x,p.y,10,10,-t*0.01);}
    qDev.SetColor(0xffff0000);
    for(int i=0;i<reds.size();i++){auto&p=reds[i];qDev.DrawQuad(p.x,p.y,10,10,-t*0.01);}
  };
  void Update(TGame*Game){
    t++;
    if(QapInput::Down[mbLeft]&&QapInput::Changed[mbLeft]){
      points.push_back(QapInput::MousePos);
    }
    if(QapInput::Down[mbRight])reds.push_back(QapInput::MousePos);
  };
  bool Win(){return abs(int(QapInput::MousePos.x)-128)<8;}
  bool Fail(){return false;}
  void AddText(TextRender*TE){
    string BEG="^7";
    string SEP=" ^2: ^8";
    #define GOO(TEXT,VALUE)TE->AddText(string(BEG)+string(TEXT)+string(SEP)+string(VALUE));
    GOO("t",IToS(t));
    GOO("px",IToS(QapInput::MousePos.x));
    GOO("py",IToS(QapInput::MousePos.y));
    #undef GOO
  }
};
class Voronoi_diagram:public TGame::ILevel{
public:
#define PRO_VARIABLE()\
ADDVAR(TGame*,Game,NULL)\
ADDVAR(int,t,0)\
ADDVAR(vector<vec2d>,points,{})\
ADDVAR(vector<vec2d>,reds,{})\
//=====+>>>>>Voronoi_diagram
#include "GenVar.inl"
//<<<<<+=====Voronoi_diagram
public:
  vector<VEdge> edges;
public:
  void Init(TGame*Game){
    this->Game=Game;
    t=0;

    points.push_back({-0.1, -0.1});
    points.push_back({0.1, 0.1});
    points.push_back({-0.5, 1});
    points.push_back({-0.5, -1});
    points.push_back({1, -0.5});
    points.push_back({-1, -0.5});
    points.push_back({0, 1});
    points.push_back({0, -1});
    points.push_back({1, 0});
    points.push_back({-1, 0});
    points.push_back({0.5, 1});
    points.push_back({0.5, -1});
    points.push_back({1, 0.5});
    points.push_back({-1, 0.5});
    points.push_back({-1, 1});
    points.push_back({-1, -1});
    points.push_back({1, 1});
    points.push_back({1, -1});

    points.push_back({2.017513020833333393, -0.574468085106383031});
    points.push_back({1.025000000000000355, -0.574468085106383031});
    points.push_back({1.851497395833333393, -0.489361702127659504});
    points.push_back({1.189388020833333837, -0.489361702127659504});
    points.push_back({1.680924479166666874, -0.404255319148936199});
    points.push_back({1.347265625000000355, -0.404255319148936199});
    points.push_back({1.520442708333333837, -0.361702127659574435});
    points.push_back({2.231705729166666874, -0.106382978723404298});
    points.push_back({1.963802083333333393, -0.106382978723404298});
    points.push_back({2.126562500000000355, -0.063829787234042534});
    points.push_back({1.800065104166666874, -0.063829787234042534});
    points.push_back({1.624934895833333393, -0.063829787234042534});
    points.push_back({1.458593750000000355, -0.063829787234042534});
    points.push_back({1.293554687500000355, -0.063829787234042534});
    points.push_back({1.139908854166666874, -0.063829787234042534});
    points.push_back({1.086848958333333837, 0.234042553191489366});
    points.push_back({2.152278645833333393, 0.446808510638297740});
    points.push_back({2.074479166666666874, 0.446808510638297740});
    points.push_back({1.825781250000000355, 0.446808510638297740});
    points.push_back({1.771419270833333393, 0.446808510638297740});
    points.push_back({1.711848958333333393, 0.446808510638297740});
    points.push_back({1.652929687500000355, 0.446808510638297740});
    points.push_back({1.598242187500000355, 0.446808510638297740});
    points.push_back({1.545833333333333837, 0.446808510638297740});
    points.push_back({1.489518229166666874, 0.446808510638297740});
    points.push_back({1.432877604166666874, 0.446808510638297740});
    points.push_back({1.377213541666666874, 0.446808510638297740});
    points.push_back({1.320247395833333837, 0.446808510638297740});
    points.push_back({1.266861979166666874, 0.446808510638297740});
    points.push_back({1.214778645833333837, 0.446808510638297740});
    points.push_back({1.164648437500000355, 0.446808510638297740});
    points.push_back({1.113541666666666874, 0.446808510638297740});
    points.push_back({1.055924479166666874, 0.446808510638297740});
    points.push_back({2.231705729166666874, 0.531914893617021267});
    points.push_back({2.178320312500000355, 0.531914893617021267});
    points.push_back({2.100520833333333393, 0.531914893617021267});
    points.push_back({2.045833333333333393, 0.531914893617021267});
    points.push_back({1.990494791666666874, 0.531914893617021267});
    points.push_back({1.911393229166666874, 0.531914893617021267});
    points.push_back({2.205013020833333393, 0.617021276595744794});
    points.push_back({2.126562500000000355, 0.617021276595744794});
    points.push_back({2.017513020833333393, 0.617021276595744794});
    points.push_back({1.937434895833333393, 0.617021276595744794});
    points.push_back({1.881445312500000355, 0.617021276595744794});
    points.push_back({1.139908854166666874, 0.617021276595744794});
    points.push_back({1.025000000000000355, 0.617021276595744794});
    points.push_back({1.963802083333333393, 0.659574468085106336});
    points.push_back({1.851497395833333837, 0.659574468085106336});
    points.push_back({1.293554687500000355, 0.659574468085106336});
    points.push_back({1.240169270833333837, 0.659574468085106336});
    points.push_back({1.189388020833333837, 0.659574468085106336});
    points.push_back({1.800065104166666874, 0.744680851063829863});
    points.push_back({1.742447916666666874, 0.744680851063829863});
    points.push_back({1.680924479166666874, 0.744680851063829863});
    points.push_back({1.458593750000000355, 0.744680851063829863});
    points.push_back({1.407486979166666874, 0.744680851063829863});
    points.push_back({1.347265625000000355, 0.744680851063829863});
    points.push_back({1.624934895833333837, 0.829787234042553168});
    points.push_back({1.571223958333333837, 0.829787234042553168});
    points.push_back({1.520442708333333837, 0.829787234042553168});
    points.push_back({-0.261194643490678224, 1.399999999999999911});
    points.push_back({-0.261194643490678224, -1.399999999999999911});
    points.push_back({-0.153893051668114067, 1.399999999999999911});
    points.push_back({-0.153893051668114067, -1.399999999999999911});
    points.push_back({-0.363659573355693988, 1.399999999999999911});
    points.push_back({-0.363659573355693988, -1.399999999999999911});
    points.push_back({-0.036153138739797752, 1.399999999999999911});
    points.push_back({-0.036153138739797752, -1.399999999999999911});
    points.push_back({-0.462967001241743947, 1.399999999999999911});
    points.push_back({-0.462967001241743947, -1.399999999999999911});
    points.push_back({0.097175131511157087, 1.399999999999999911});
    points.push_back({0.097175131511157087, -1.399999999999999911});
    points.push_back({-0.559942424040845044, 1.399999999999999911});
    points.push_back({-0.559942424040845044, -1.399999999999999911});
    points.push_back({0.208321571865569322, 1.399999999999999911});
    points.push_back({0.208321571865569322, -1.399999999999999911});
    points.push_back({-0.655076493418098149, 1.399999999999999911});
    points.push_back({-0.655076493418098149, -1.399999999999999911});
    points.push_back({0.312895577228335942, 1.399999999999999911});
    points.push_back({0.312895577228335942, -1.399999999999999911});
    points.push_back({-0.748693746906758495, 1.399999999999999911});
    points.push_back({-0.748693746906758495, -1.399999999999999911});
    points.push_back({0.413645344658276626, 1.399999999999999911});
    points.push_back({0.413645344658276626, -1.399999999999999911});
    points.push_back({-0.841024318393457371, 1.399999999999999911});
    points.push_back({-0.841024318393457371, -1.399999999999999911});
    points.push_back({0.511710405892882747, 1.399999999999999911});
    points.push_back({0.511710405892882747, -1.399999999999999911});
    points.push_back({-0.932239626539499433, 1.399999999999999911});
    points.push_back({-0.932239626539499433, -1.399999999999999911});
    points.push_back({0.607716545146089526, 1.399999999999999911});
    points.push_back({0.607716545146089526, -1.399999999999999911});
    points.push_back({-1.024999999999999467, 1.399999999999999911});
    points.push_back({-1.024999999999999467, -1.399999999999999911});
    points.push_back({0.702058651501696218, 1.399999999999999911});
    points.push_back({0.702058651501696218, -1.399999999999999911});
    points.push_back({-1.124999999999999556, 1.399999999999999911});
    points.push_back({-1.124999999999999556, -1.399999999999999911});
    points.push_back({0.795008061072074224, 1.399999999999999911});
    points.push_back({0.795008061072074224, -1.399999999999999911});
    points.push_back({-1.224999999999999645, 1.399999999999999911});
    points.push_back({-1.224999999999999645, -1.399999999999999911});
    points.push_back({0.886762354257207619, 1.399999999999999911});
    points.push_back({0.886762354257207619, -1.399999999999999911});
    points.push_back({-1.324999999999999734, 1.399999999999999911});
    points.push_back({-1.324999999999999734, -1.399999999999999911});
    points.push_back({0.977471613750350077, 1.399999999999999911});
    points.push_back({0.977471613750350077, -1.399999999999999911});
    points.push_back({-1.424999999999999822, 1.399999999999999911});
    points.push_back({-1.424999999999999822, -1.399999999999999911});
    points.push_back({1.075000000000000178, 1.399999999999999911});
    points.push_back({1.075000000000000178, -1.399999999999999911});
    points.push_back({-1.524999999999999467, 1.399999999999999911});
    points.push_back({-1.524999999999999467, -1.399999999999999911});
    points.push_back({1.175000000000000711, 1.399999999999999911});
    points.push_back({1.175000000000000711, -1.399999999999999911});
    points.push_back({-1.625000000000000000, 1.399999999999999911});
    points.push_back({-1.625000000000000000, -1.399999999999999911});
    points.push_back({1.275000000000000355, 1.399999999999999911});
    points.push_back({1.275000000000000355, -1.399999999999999911});
    points.push_back({-1.724999999999999645, 1.399999999999999911});
    points.push_back({-1.724999999999999645, -1.399999999999999911});
    points.push_back({1.375000000000000444, 1.399999999999999911});
    points.push_back({1.375000000000000444, -1.399999999999999911});
    points.push_back({-1.824999999999999734, 1.399999999999999911});
    points.push_back({-1.824999999999999734, -1.399999999999999911});
    points.push_back({1.475000000000000533, 1.399999999999999911});
    points.push_back({1.475000000000000533, -1.399999999999999911});
    points.push_back({1.924999999999999822, 1.399999999999999911});
    points.push_back({-1.924999999999999822, -1.399999999999999911});
    points.push_back({1.575000000000000178, 1.399999999999999911});
    points.push_back({1.575000000000000178, -1.399999999999999911});
    points.push_back({-2.024999999999999467, 1.399999999999999911});
    points.push_back({-2.024999999999999467, -1.399999999999999911});
    points.push_back({1.675000000000000711, 1.399999999999999911});
    points.push_back({1.675000000000000711, -1.399999999999999911});
    points.push_back({-2.125000000000000000, 1.399999999999999911});
    points.push_back({-2.125000000000000000, -1.399999999999999911});
    points.push_back({1.775000000000000355, 1.399999999999999911});
    points.push_back({1.775000000000000355, -1.399999999999999911});
    points.push_back({-2.224999999999999645, 1.399999999999999911});
    points.push_back({-2.224999999999999645, -1.399999999999999911});
    points.push_back({1.300000000000000044, -1.000000000000000000});
    points.push_back({-1.300000000000000044, -1.000000000000000000});
    points.push_back({1.300000000000000044, -0.900000000000000022});
    points.push_back({-1.300000000000000044, -0.900000000000000022});
    points.push_back({1.300000000000000044, -0.800000000000000044});
    points.push_back({-1.300000000000000044, -0.800000000000000044});
    points.push_back({1.300000000000000044, -0.699999999999999956});
    points.push_back({-1.300000000000000044, -0.699999999999999956});
    points.push_back({1.300000000000000044, -0.599999999999999978});
    points.push_back({-1.300000000000000044, -0.599999999999999978});
    points.push_back({1.300000000000000044, -0.500000000000000000});
    points.push_back({-1.300000000000000044, -0.500000000000000000});
    points.push_back({1.300000000000000044, -0.399999999999999911});
    points.push_back({-1.300000000000000044, -0.399999999999999911});
    points.push_back({1.300000000000000044, -0.299999999999999933});
    points.push_back({-1.300000000000000044, -0.299999999999999933});
    points.push_back({1.300000000000000044, -0.199999999999999956});
    points.push_back({-1.300000000000000044, -0.199999999999999956});
    points.push_back({1.300000000000000044, -0.099999999999999978});
    points.push_back({-1.300000000000000044, -0.099999999999999978});
    points.push_back({1.300000000000000044, 0.000000000000000000});
    points.push_back({-1.300000000000000044, 0.000000000000000000});
    points.push_back({1.300000000000000044, 0.100000000000000089});
    points.push_back({-1.300000000000000044, 0.100000000000000089});
    points.push_back({1.300000000000000044, 0.200000000000000178});
    points.push_back({-1.300000000000000044, 0.200000000000000178});
    points.push_back({1.300000000000000044, 0.300000000000000044});
    points.push_back({-1.300000000000000044, 0.300000000000000044});
    points.push_back({1.300000000000000044, 0.400000000000000133});
    points.push_back({-1.300000000000000044, 0.400000000000000133});
    points.push_back({1.300000000000000044, 0.500000000000000000});
    points.push_back({-1.300000000000000044, 0.500000000000000000});
    points.push_back({1.300000000000000044, 0.600000000000000089});
    points.push_back({-1.300000000000000044, 0.600000000000000089});
    points.push_back({1.300000000000000044, 0.700000000000000178});
    points.push_back({-1.300000000000000044, 0.700000000000000178});
    points.push_back({1.300000000000000044, 0.800000000000000044});
    points.push_back({-1.300000000000000044, 0.800000000000000044});
    points.push_back({1.300000000000000044, 0.900000000000000133});
    points.push_back({-1.300000000000000044, 0.900000000000000133});
    points.push_back({1.300000000000000044, 1.000000000000000000});
    points.push_back({-1.300000000000000044, 1.000000000000000000});
    for(auto&ex:points)ex*=250;
    points.resize(3);
    recalc();
  }
  #if(0)
  void recalc_old(){
    double minY=-1920*0.5;
    double maxY=1920*0.5;
    Voronoi vdg;
    QapClock clock;
    /*{auto*f=fopen("out.txt","wb+");
    fputs(("begin = "+FToS(clock.MS())+"\n").c_str(),f);
    fclose(f);}*/
    edges=vdg.ComputeVoronoiGraph(points,minY,maxY);
    auto*f=fopen("out.txt","wb+");
    fputs(("recalc_ms = "+FToS(clock.MS())+"\n").c_str(),f);
    fclose(f);
  }
  #endif
  typedef std::bitset<100000> vec_of_id;
  static vec_of_id bitwise_and(vec_of_id&a,vec_of_id&b){vec_of_id out=a;out&=b;return b;}
  struct t_vec1d{
    vector<vec_of_id> arr;
    real min=0;
    real max=0;
    vec2d ox;
    void add_from_pos_at_r(vec_of_id&out,vec2d tp,int r=0){
      auto n=arr.size();
      auto fid=(tp.Rot(ox).x-min)*n/(max-min);
      int id=int(fid);
      if(id<0)id=0;if(id>=n)id=n-1;
      if(r){
        {int x=id-r;if(x>=0&&x<n)out|=arr[x];}
        {int x=id+r;if(x>=0&&x<n)out|=arr[x];}
        return;
      }
      out|=arr[id];
    }
  };
  struct t_space{
    const vector<vec2d>&points;
    t_vec1d x,y;
    int max_r=1024;
    size_t get_nearst_id(vec2d tp){
      vec_of_id mx,my;
      for(int r=0;r<max_r;r++){
        x.add_from_pos_at_r(mx,tp,r);
        y.add_from_pos_at_r(my,tp,r);
        auto tmp=bitwise_and(mx,my);
        if(!tmp.count())continue;
        //auto win=qapminid(tmp.filter(e=>dist(e,tp)<(r+0.5)*cell_size),e=>tp.sqr_dist_to(e));
        //if(win<0)continue;return win;
      }
      return -1;
    }
  };
  t_vec1d get_vec1d(const vector<vec2d>&points,char axis){};
  t_space make_space(const vector<vec2d>&points){
    t_space space={points};
    space.x=get_vec1d(points,'X');
    space.y=get_vec1d(points,'Y');
    return space;
  }
  void new_algo(){
    auto space=make_space(points);
    vec2d target_point;
    auto tp=target_point;
    auto out=space.get_nearst_id(tp);
  }
  void recalc(){
    QapClock clock;
    double minY=-1920*0.5;
    double maxY=1920*0.5;
    double eps=1e-12;
    using value_type=double;
    /*struct point 
    { 
      value_type x, y; 
      bool operator < (point const & p) const
      { return std::tie(x, y) < std::tie(p.x, p.y); }
    };*/
    struct t_hacked_vec2d:vec2d{
      t_hacked_vec2d():vec2d(){}
      t_hacked_vec2d(real x,real y):vec2d(x,y){}
      //bool operator<=(t_hacked_vec2d&v){return vec2d_less_or_eq(*this,v);}
      bool operator<(const t_hacked_vec2d&p)const{return std::tie(x,y)<std::tie(p.x,p.y);}
    };
    using point=t_hacked_vec2d;
    using t_points=std::vector<point>;
    using site=typename t_points::const_iterator;
    using sweepline_type=sweepline<site,point,value_type>;
    auto arr=(vector<t_hacked_vec2d>&)points;
    sweepline_type SL{eps};
    // fill points_ with data
    std::sort(std::begin(arr), std::end(arr));
    //quick_sort(arr);
    SL(std::cbegin(arr),std::cend(arr));
    //SL.vertices_
    edges.clear();
    vector<vec2d> VA;
    for(auto&ex:SL.vertices_)VA.push_back(ex.c);
    for(auto&ex:SL.edges_){
      if(ex.b==SL.inf&&ex.e==SL.inf)continue;
      auto get=[&](size_t vid,int sign,size_t other){
        if(vid!=SL.inf){
          QapAssert(vid<VA.size());
          return VA[vid];
        }
        auto c=(*ex.l-*ex.r).Ort().SetMag(1920*sign);
        QapAssert(other<VA.size());
        return VA[other]+c;
      };
      edges.push_back({get(ex.b,-1,ex.e),get(ex.e,+1,ex.b),*ex.l,*ex.r});
    }
    // sweepline_.vertices_ - resulting vertices
    // sweepline_.edges_ - resulting edges

    //edges=vdg.ComputeVoronoiGraph(points,minY,maxY);
    //auto*f=fopen("out.txt","wb+");
    //fputs(("recalc_ms = "+FToS(clock.MS())+"\n").c_str(),f);
    //fclose(f);
  }
  static void draw_point(QapDev*RD,const vec2d&ex,real ang,bool shadow,QapColor c,QapAtlas::TFrame*pF){
    RD->SetColor(shadow?0xff000000:c);
    pF->Bind(RD);
    auto p=ex;
    if(shadow)p+=vec2d(1.0,-1.0);
    RD->DrawQuad(p.x,p.y,pF->w,pF->h,ang);
  }
  void Render(QapDev*RD){
    auto&qDev=*RD;
    //qDev.BindTex(0,0);
    qDev.BindTex(0,Game->Atlas.pTex);
    if(bool draw_big_rotated_quad_at_center=false){qDev.SetColor(0xffffffff);qDev.DrawQuad(0,0,400,400,t*0.01);}
    Game->FrameDot->Bind(&qDev);
    qDev.SetColor(0xff000000);qDev.DrawQuad(QapInput::MousePos.x,QapInput::MousePos.y,10,10,t*0.01);
    vector<vec2d> PA,SA;
    int diff_w=(Game->FrameLine_s->w-Game->FrameLine->w);
    auto draw_lns=[&](auto&A,QapColor c,real hls,bool shadow,QapAtlas::TFrame*pF){
      QapDev::BatchScope Scope(qDev);
      for(int i=1;i<A.size();i+=2){
        draw_nice_line(qDev,pF,A[i-1],A[i-0],hls,diff_w,c,shadow);
      }
    };
    if(bool draw_edges=1)for(auto&ex:edges){
      if(bool draw_edges=tumbler){PA.push_back(ex.VA);PA.push_back(ex.VB);}
      if(bool draw_line_to_vertex=0){
        auto&out=SA;
        out.push_back(ex.S0);out.push_back(ex.VA);
        out.push_back(ex.S0);out.push_back(ex.VB);
        out.push_back(ex.S1);out.push_back(ex.VA);
        out.push_back(ex.S1);out.push_back(ex.VB);
      }
      if(bool draw_center_edge_point=0){
        auto C=0.5*(ex.VA+ex.VB);
        SA.push_back(ex.S0);SA.push_back(C);
        SA.push_back(ex.S1);SA.push_back(C);
      }
      if(bool draw_s2s=1){
        SA.push_back(ex.S0);SA.push_back(ex.S1);
      }
    }
    if(bool draw_pa=1){
      draw_lns(PA,0xffFFFFFF,8,1,Game->FrameLine_s);
      draw_lns(PA,0xffFFFFFF,8,0,Game->FrameLine);
    }
    draw_lns(SA,0xff00df00,8,1,Game->FrameLine_s);
    draw_lns(SA,0xff00df00,8,0,Game->FrameLine);
    auto sel=get_point_id_under_mpos();
    for(int i=0;i<points.size();i++){auto&p=points[i];draw_point(&qDev,p,-t*0.01,1,0xffFFff00,Game->FrameDot_s);}
    for(int i=0;i<points.size();i++){auto&p=points[i];draw_point(&qDev,p,-t*0.01,0,i==sel?0xffff8000:0xffFFff00,Game->FrameDot);}
    qDev.SetColor(0xffff0000);
    for(int i=0;i<reds.size();i++){auto&p=reds[i];draw_point(&qDev,p,-t*0.01,1,0xffff0000,Game->FrameLine_s);}
    for(int i=0;i<reds.size();i++){auto&p=reds[i];draw_point(&qDev,p,-t*0.01,0,0xffff0000,Game->FrameLine);}
    if(bool draw_so=0)if(points.size()>=2){
      auto&A=points;
      for(int j=0;j<A.size();j++)
      for(int i=1;i<A.size();i++){
        auto&a=A[j];auto&b=A[i-0];
        auto c=(a*0.5+b*0.5);
        auto dx=(a-c).SetMag(10000).Ort();
        PA.push_back(+dx+c);PA.push_back(-dx+c);
      }
    }
    /*
    qDev.SetColor(0x80FFFFFF);
    qDev.DrawLineList(PA,3);
    qDev.SetColor(0x80803030);
    qDev.DrawLineList(SA,3);
    qDev.SetColor(0xff000000);*/
  }
  static void draw_line(QapDev&qDev,const vec2d&a,const vec2d&b,real hls){
    auto n=vec2d(b-a).Ort().SetMag(hls);
    int g=qDev.VPos;
    #define F(A,U,V)qDev.AddVertex(QapDev::Ver(A,qDev.color,U,V))
      F(a+n,1.f,1.f),
      F(b-n,0.f,0.f),
      F(a-n,1.f,0.f),
      F(b+n,0.f,1.f),
    #undef F
    qDev.AddTris(g+0,g+1,g+2);
    qDev.AddTris(g+0,g+1,g+3);
  }
  static void draw_nice_line(QapDev&qDev,QapAtlas::TFrame*pF,const vec2d&a,const vec2d&b,real ls,int diff_w,QapColor c,bool shadow){
    qDev.SetColor(shadow?0xff000000:c);
    pF->Bind(&qDev);
    auto pa=a;auto pb=b;auto offset=vec2d(1.0,-1.0);
    if(shadow){
      pa+=offset;pb+=offset;
      auto k=1.0+diff_w/real(pF->w-diff_w);ls*=k;
      auto ba=(a-b);
      auto ban=ba.SetMag((ba.Mag()/pF->w)*0.5*(k-1.0));
      pa+=ban;pb-=ban;
    }
    draw_line(qDev,pa,pb,ls*0.5);
  }
  bool tumbler=false;
  void Update(TGame*Game){
    t++;
    if(QapInput::Down[mbLeft]&&QapInput::Changed[mbLeft]){
      points.push_back(QapInput::MousePos);recalc();
    }
    auto&mpos=QapInput::MousePos;
    if(QapInput::Down[mbRight])if(reds.empty()||reds.back()!=mpos)reds.push_back(mpos);
    //if(QapInput::Down[VK_SHIFT])if(points.size())points[0]=QapInput::MousePos;
    if(QapInput::Down['S']){save_to_file();}
    if(QapInput::Down['L']){load_from_file();recalc();}
    if(QapInput::Down['R']){points.clear();edges.clear();}
    if(QapInput::OnDown('T')){tumbler=!tumbler;}
    if(QapInput::OnDown('C')){
      points.clear();
      int n=100000;real r=9000;
      for(int i=0;i<n;i++)
      {
        vec2d p=Vec2dEx(Pi2*i/n,r);
        points.push_back(p);
      }
      recalc();
    }
    if(QapInput::OnDown('G')){
      points.clear();
      int n=3+rand()%128;real minmag=64;
      for(int i=0;i<n;i++)
      {
        vec2d p;
        for(int i=0;i<128;i++){
          p=rndvec2d(1920-64,1200-64);
          bool ok=true;
          for(auto&ex:points)if((ex-p).Mag()<minmag){ok=false;break;};
          if(ok)break;
        }
        points.push_back(p);
      }
      recalc();
    }
    if(QapInput::Down['Q']){
      recalc();
    }
    bool down=QapInput::Down[VK_SHIFT];
    bool on_down=QapInput::OnDown(VK_SHIFT);
    if(down||on_down)
    {
      auto id=get_point_id_under_mpos(1e6);
      if(id>=0&&id<points.size())
      {
        auto&p=points[id];
        if(on_down||point_id>=0)if((p-mpos).Mag()<16){point_id=id;}
        if(down/*&&point_id==id*/){p=mpos;recalc();}
      }
    }
    if(!down)point_id=-1;
  }
  int get_point_id_under_mpos(real dist=16){
    auto&mpos=QapInput::MousePos;
    std::pair<int,real> tmp,out={-1,0};auto&[id,md]=out;
    for(int i=0;i<points.size();i++){
      auto&p=points[i];
      tmp={i,(mpos-p).Mag()};
      if(id<0||md>=tmp.second)out=tmp;
    }
    return md<dist?id:-1;
  }
  void save_to_file(){
    auto n=points.size();
    auto*f=fopen("points.bin","wb");
    fwrite(&n,sizeof(n),1,f);
    if(n)fwrite(points.data(),sizeof(points[0]),points.size(),f);
    fclose(f);
  }
  void load_from_file(){
    size_t n=0;
    auto*f=fopen("points.bin","rb");
    fread(&n,sizeof(n),1,f);points.resize(n);
    fread(points.data(),sizeof(points[0]),points.size(),f);
    fclose(f);
  }
  int point_id=-1;
  bool Win(){return abs(int(QapInput::MousePos.x)-128)<8;}
  bool Fail(){return false;}
  void AddText(TextRender*TE){
    string BEG="^7";
    string SEP=" ^2: ^8";
    #define GOO(TEXT,VALUE)TE->AddText(string(BEG)+string(TEXT)+string(SEP)+string(VALUE));
    GOO("t",IToS(t));
    GOO("px",IToS(QapInput::MousePos.x));
    GOO("py",IToS(QapInput::MousePos.y));
    #undef GOO
  }
};
class Level_RT_Sprite_Test:public TGame::ILevel{
public:
#define PRO_VARIABLE()\
ADDVAR(TGame*,Game,NULL)\
ADDVAR(int,t,0)\
ADDVAR(vec2d,pos,vec2d_zero)\
ADDVAR(vec2d,v,vec2d_zero)\
//=====+>>>>>Level1
#include "GenVar.inl"
//<<<<<+=====Level1
public:
  void Init(TGame*Game){
    this->Game=Game;
  }
  bool Win(){return abs(int(QapInput::MousePos.x)-128)<8;}
  bool Fail(){return false;}
  vec2d get_dir_from_keyboard_wasd_and_arrows()
  {
    vec2d dp=vec2d_zero;
    auto dir_x=vec2d(1,0);
    auto dir_y=vec2d(0,1);
    #define F(dir,key_a,key_b)if(QapInput::Down[key_a]||QapInput::Down[key_b]){dp+=dir;}
    F(-dir_x,VK_LEFT,'A');
    F(+dir_x,VK_RIGHT,'D');
    F(+dir_y,VK_UP,'W');
    F(-dir_y,VK_DOWN,'S');
    #undef F
    return dp;
  }
  void AddText(TextRender*TE){
    string BEG="^7";
    string SEP=" ^2: ^8";
    #define GOO(TEXT,VALUE)TE->AddText(string(BEG)+string(TEXT)+string(SEP)+string(VALUE));
    GOO("t",IToS(t));
    GOO("px",IToS(QapInput::MousePos.x));
    GOO("py",IToS(QapInput::MousePos.y));
    #undef GOO
  }
  void Render(QapDev*RD){
    if(bool need_draw_rock0_as_thrt=true){
      auto*pF=Game->th_rt_tex;auto&qDev=*RD;
      qDev.BindTex(0,pF);
      qDev.SetColor(0xffffffff);
      auto scale=0.25;
      RD->DrawQuad(pos.x,pos.y,pF->W*scale,pF->H*scale,(-v.Ort()).GetAng());
      RD->BindTex(0,0);
    }
  }
  void Update(TGame*Game){
    //v+=get_dir_from_keyboard_wasd_and_arrows()*0.003;
    auto dk=0.0;auto dAng=6.28*0.33/(2*Sys_UPD);
    if(QapInput::Down[VK_LEFT]||QapInput::Down['A']){dk=+1;}
    if(QapInput::Down[VK_RIGHT]||QapInput::Down['D']){dk=-1;}
    v=Vec2dEx(v.GetAng()+Clamp(dk,-5.0,+5.0)*dAng,1);
    pos+=v;
  }
};
#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : adler3d@gmail.com    |>}   //
//   {<| site   : adler3d.narod.ru     |>}   //
//-------------------------------------------//

extern bool QapPublicUberFullSaverBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullLoaderBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullSaverProto(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern string QapPublicUberFullSaverProtoToStr(IEnvRTTI&Env,IQapRawObject&&Object);

extern bool QapPublicUberFullSaverBinMem(IEnvRTTI&Env,IQapRawObject&&Object,string&Out);
extern bool QapPublicUberFullLoaderBinMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp);
extern bool QapPublicUberFullCloneBinMem(IEnvRTTI&Env,IQapRawObject&&Dest,IQapRawObject&&Source);

inline int&get_QapClone_counter(){static int counter=0;return counter;}
inline real&QapClone_timer(){static real time=0;return time;}

template<class TYPE>
inline bool QapClone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  static auto&counter=get_QapClone_counter();counter++;
  QapClock clock;
  clock.Start();
  bool ok=QapPublicUberFullCloneBinMem(Env,QapRawUberObject(dest),QapRawUberObject(source));
  clock.Stop();
  QapClone_timer()+=clock.MS();
  return ok;
}

struct ICompileUnit;

struct ICompileUnitMan
{
  virtual void add(ICompileUnit*pUnit)=0;
  static ICompileUnitMan&get_man();
};

struct ICompileUnit{
  virtual const char*get_filename()const=0;
  virtual void RegAll(IEnvRTTI&Env)=0;
  virtual void Run(IEnvRTTI&Env)=0;
  ICompileUnit(){ICompileUnitMan::get_man().add(this);}
};

static string cur_date_str()
{
  time_t rawtime;
  tm*ptm;
  time(&rawtime);
  ptm=gmtime(&rawtime);
  char buff[128];
  sprintf(&buff[0],"%04u.%02u.%02u %02u:%02u:%02u\0",
    1900+ptm->tm_year,
    ptm->tm_mon+1,
    ptm->tm_mday,
    ptm->tm_hour,ptm->tm_min,ptm->tm_sec
  );
  return buff;
}

class ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,NeedRemove,DEF,$,$)\
ADDEND()
//=====+>>>>>ISubProgram
#include "QapGenStruct.inl"
//<<<<<+=====ISubProgram
public:
  class t_context{
  public:
    IEnvRTTI&Env;
    //AppStarter*Starter;
    operator IEnvRTTI&(){return Env;}
  };
public:
  virtual void Update(t_context&Env){}
  void TryUpdate(t_context&con)
  {
    if(NeedRemove)return;
    if(!Enabled)return;
    Update(con);
  }
};

class TProgramNode:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramNode)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<ISubProgram>>,Programs,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramNode
#include "QapGenStruct.inl"
//<<<<<+=====TProgramNode
public:
  typedef vector<TAutoPtr<ISubProgram>> TArray;
public:
  //ISubProgram*front(){return Programs.front().get();}
  //ISubProgram*back(){return Programs.back().get();}
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Programs.resize(Programs.size()+1);
    return Programs.back().build<TYPE>(Env);
  }
  void ForceUpdate(t_context&con)
  {
    auto&arr=Programs;
    for(int i=0;i<arr.size();i++)
    {
      auto*ex=arr[i].get();
      if(!ex)continue;
      ex->TryUpdate(con);
    }
  }
  void Update(t_context&con)
  {
    if(!Enabled)return;
    ForceUpdate(con);
  }
public:
  TAutoPtr<ISubProgram>&front(){
    return Programs.front();
  }
  TAutoPtr<ISubProgram>&back(){
    return Programs.back();
  }
public:
  bool empty()const{return Programs.empty();}
};

class QapRenderProgram;
class QapPluginMan;

class IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(bool,Deaded,SET,false,$)\
ADDEND()
//=====+>>>>>IUnitProgram
#include "QapGenStruct.inl"
//<<<<<+=====IUnitProgram
public:
  struct TBuildContext{
    IEnvRTTI&Env;
    QapPluginMan&PluginMan;
    QapRenderProgram&Qrp;
  };
  virtual void OnBuild(TBuildContext&Context){}
  virtual void Update(IEnvRTTI&Env){}
};

class TReloadDetector{
public:
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TReloadDetector)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,needinit,SET,false,$)\
ADDVAR(bool,fresh,SYS,true,$)\
ADDEND()
//=====+>>>>>TReloadDetector
#include "QapGenStruct.inl"
//<<<<<+=====TReloadDetector
public:
  void Init(){fresh=false;needinit=false;}
  void Free(){fresh=true;};
  void Update(){needinit=fresh;}
};

class QapKeyboard{
public:
  struct TKeyState{
    static const int MAX_KEY=263;
    bool data[MAX_KEY];
    TKeyState(){SetToDef();}
    void SetToDef(){for(int i=0;i<MAX_KEY;i++)data[i]=false;}
    bool&operator[](int index)
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      { 
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    const bool&operator[](int index)const
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      { 
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
  };
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapKeyboard)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,LastKey,SET,0,$)\
ADDVAR(char,LastChar,SET,0,$)\
ADDVAR(bool,NeedReset,DEF,$,$)\
ADDVAR(bool,News,SYS,false,$)\
ADDVAR(TKeyState,Down,SYD,$,$)\
ADDVAR(TKeyState,Changed,SYD,$,$)\
ADDEND()
//=====+>>>>>QapKeyboard
#include "QapGenStruct.inl"
//<<<<<+=====QapKeyboard
public:
  void QapKeyboard::operator=(const QapKeyboard&){
    QapDebugMsg("QapKeyboard is noncopyable");
  }
  void try_reset()
  {
    if(!NeedReset)return;
    reset();
  }
  void reset()
  {
    NeedReset=false;
    LastKey=0;
    LastChar=0;
    News=false;
    Down.SetToDef();
    Changed.SetToDef();
  }
  void KeyUpdate(int Key,bool Value)
  {
    if(Value)LastKey=Key;
    Down[Key]=Value;Changed[Key]=true;
  }
  void CharUpdate(char c)
  {
    LastChar=c;News=true;
  }
  void Sync()
  {
    this->News=false;Changed.SetToDef();
  }
  bool OnDown(int index)const{
    return Changed[index]&&Down[index];
  }
};

class eQuad{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eQuad)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,SET,320,$)\
ADDVAR(int,y,SET,240,$)\
ADDVAR(int,w,SET,320,$)\
ADDVAR(int,h,SET,240,$)\
ADDEND()
//=====+>>>>>eQuad
#include "QapGenStruct.inl"
//<<<<<+=====eQuad
public:
  void Set(int x,int y,int w,int h)
  {
    #define F(FIELD)this->FIELD=FIELD;
    F(x)F(y)F(w)F(h)
    #undef F
  }
  vec2i&GetPos(){return *(vec2i*)(void*)(&this->x);}
  vec2i&GetSize(){return *(vec2i*)(void*)(&this->w);}
  void SetAs(const vec2i&pos,const vec2i&size){GetPos()=pos;GetSize()=size;}
  RECT GetWinRect(){RECT tmp={x,y,x+w,y+h};return tmp;}
  void SetWinRect(const RECT&rect){eQuad&r=*(eQuad*)(void*)(&rect);Set(r.x,r.y,r.w-r.x,r.h-r.y);}
  void SetSize(const SIZE&size){w=size.cx;h=size.cy;}
  static eQuad getFullScreen(){eQuad tmp;auto mode=GetScreenMode();tmp.Set(0,0,mode.W,mode.H);return std::move(tmp);}
  void setAtCenter(const eQuad&quad){
    QapAssert(quad.w>=w);
    QapAssert(quad.h>=h);
    x=(quad.w-w)/2;
    y=(quad.h-h)/2;
  }
  void subpos(const eQuad&q){
    x-=q.x;
    y-=q.y;
  }
  void setAtCenterScreen(){setAtCenter(getFullScreen());}
};

enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};

class IProgramD3D9{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IProgramD3D9)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(QapD3D9,D9,DEF,$,$)\
ADDVAR(QapD3DDev9,D9Dev,DEF,$,$)\
ADDVAR(TProgramNode,UserCode,DEF,$,$)\
ADDEND()
//=====+>>>>>IProgramD3D9
#include "QapGenStruct.inl"
//<<<<<+=====IProgramD3D9
public:
  virtual vec2i WindowGetClientSize(){QapDebugMsg("no way");return vec2i(128,128);}
  virtual QapKeyboard&GetKeyBoard(){QapDebugMsg("no way");return *(QapKeyboard*)nullptr;}
  virtual vec2i WindowGetMousePos(){QapDebugMsg("no way");return vec2i(128,128);}
  virtual eQuad&WindowGetQuad(){QapDebugMsg("no way");return *(eQuad*)nullptr;}
  virtual void WindowUpdateMode(){QapDebugMsg("no way");return;}
  virtual void WindowFullScreen(bool fullscreen){QapDebugMsg("no way");return;}
  virtual int WindowGetzDelta(){QapDebugMsg("no way");return 0;}
};

class ITreeDebuggerBranch{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ITreeDebuggerBranch)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>ITreeDebuggerBranch
#include "QapGenStruct.inl"
//<<<<<+=====ITreeDebuggerBranch
public:
  virtual TRawPtr GetRawPtr(){QapDebugMsg("no way.");TRawPtr tmp(nullptr,nullptr); return tmp;}
  virtual string GetCode(){QapDebugMsg("no way.");return "";}
};

class QapPluginMan:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapPluginMan)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<IUnitProgram>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>QapPluginMan
#include "QapGenStruct.inl"
//<<<<<+=====QapPluginMan
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }
  IUnitProgram*unsafe_AddItem(IEnvRTTI&Env,TType*pType)
  {
    Items.resize(Items.size()+1);
    auto&back=Items.back();
    back.Product.pType=pType;
    back.Product.Init();
    return back.get();
  }
  void MakeAll(IEnvRTTI&Env,QapRenderProgram*pQRP,TType*pIUnitProgram)
  {
    IUnitProgram::TBuildContext Context={Env,*this,*pQRP};
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=ex.Type.get();
      if(!pType->IsBasedOn(pIUnitProgram))continue;
      if(!pType->Factory)continue;
      unsafe_AddItem(Env,pType)->OnBuild(Context);
    }
  }
  void Update(t_context&con)
  {
    auto&arr=Items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*pItem=ex.get();
      pItem->Update(con.Env);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*pItem=ex.get();
      if(pItem->Deaded)ex=nullptr;
    }
    QapClean(Items);
  }
public:
  bool empty()const{return Items.empty();}
};

//-------------------------------------------//
//   {<|          03.06.2014           |>}   //
//-------------------------------------------//
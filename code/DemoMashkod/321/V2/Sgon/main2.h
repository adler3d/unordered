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

struct t_qap_eval_string{
  IEnvRTTI&Env;
  string code;
  string out;
  string load_status;
  string errcode;
  string retpath;
  real load_time;
  real exec_time;
  real full_time;
};

class i_eval_block{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_eval_block)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,code,DEF,$,$)\
ADDVAR(1,string,inp,DEF,$,$)\
ADDVAR(2,string,out,DEF,$,$)\
ADDVAR(3,string,load_status,DEF,$,$)\
ADDVAR(4,string,errcode,DEF,$,$)\
ADDVAR(5,string,retpath,DEF,$,$)\
ADDVAR(6,real,load_time,DEF,$,$)\
ADDVAR(7,real,exec_time,DEF,$,$)\
ADDVAR(8,real,full_time,DEF,$,$)\
ADDEND()
//=====+>>>>>i_eval_block
#include "QapGenStruct.inl"
//<<<<<+=====i_eval_block
public:
  virtual void block_clear(){QapDebugMsg("no way");}
  virtual void block_compile(IEnvRTTI&Env){QapDebugMsg("no way");}
  virtual void block_run(IEnvRTTI&Env){QapDebugMsg("no way");}
};

class i_sys_impl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sys_impl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_sys_impl
#include "QapGenStruct.inl"
//<<<<<+=====i_sys_impl
public:
  virtual void exec(){QapDebugMsg("no way");}
};

class i_sysfunc_with_rtti{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sysfunc_with_rtti)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_sysfunc_with_rtti
#include "QapGenStruct.inl"
//<<<<<+=====i_sysfunc_with_rtti
public:
  virtual void exec(IEnvRTTI&Env){QapDebugMsg("no way");}
};

class t_sys_opers_holder{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sys_opers_holder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_sys_opers_holder
#include "QapGenStruct.inl"
//<<<<<+=====t_sys_opers_holder
public:
};

class t_chat_node{
public:
  class t_msg{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_msg)OWNER(t_chat_node)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,time,DEF,$,$)\
  ADDVAR(1,string,message,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_msg
  #include "QapGenStruct.inl"
  //<<<<<+=====t_msg
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(t_msg)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_chat_node)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,vector<t_msg>,messages,DEF,$,$)\
ADDVAR(2,vector<t_chat_node>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>t_chat_node
#include "QapGenStruct.inl"
//<<<<<+=====t_chat_node
public:
  SelfClass&add(const string&name)
  {
    QapAssert(find(name)<0);
    items.push_back(SelfClass());
    auto&back=items.back();
    back.name=name;
    return back;
  }
  void addmsg(const string&msg){
    t_msg tmp;
    tmp.message=msg;
    tmp.time=cur_date_str();
    messages.push_back(std::move(tmp));
  }
  bool check(int i)const{return (i>=0)&&(i<items.size());}
  int find(const string&name)const{for(int i=0;i<items.size();i++){if(items[i].name==name)return i;}return -1;}
  static string drop_last_element(const string&path){
    auto p=path.rfind("/");
    QapAssert(p!=std::string::npos);
    string test=path.substr(0,p);
    QapAssert(test.back()!='/');
    QapAssert(!test.empty());
    return path.substr(0,p);
  }
  vector<string> get_all_path(){
    vector<string> out;
    out.push_back("/");
    auto arr=get_items_path();
    for(int i=0;i<arr.size();i++)out.push_back(arr[i]);
    return out;
  }
  vector<string> get_items_path(){
    vector<string> out;
    for(int i=0;i<items.size();i++){
      auto&ex=items[i];
      out.push_back("/"+ex.name);
      auto arr=ex.get_items_path();
      for(int i=0;i<arr.size();i++){
        out.push_back("/"+ex.name+arr[i]);
      }
    }
    return out;
  }
  int conv_way_to_id(vector<int>&arr)const
  {
    int out=0;
    auto*p=this;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(p->check(ex));
      for(int j=0;j<ex;j++){
        out+=p->items[j].get_total_childs();
      }
      p=&p->items[ex];
      out++;
    }
    return out;
  }
  int get_total_childs()const
  {
    int out=0;
    for(int i=0;i<items.size();i++){
      out+=items[i].get_total_childs();
    }
    return out;
  }
  std::pair<bool,vector<int>> try_get_way(const string&path)const
  {
    std::pair<bool,vector<int>> out(false,vector<int>());
    auto&ok=out.first;
    vector<int>&way=out.second;
    if(path=="/"){ok=true;return out;}
    QapAssert(!path.empty());
    QapAssert(path[0]=='/');
    auto arr=split(path.substr(1),"/");
    QapAssert(!arr.empty());
    auto*p=this;
    for(int i=0;i<arr.size();i++){
      QapAssert(!arr[i].empty());
      int id=p->find(arr[i]);
      if(id<0){return out;}
      way.push_back(id);
      p=&p->items[id];
    }
    ok=true;
    return out;
  }
  vector<int> get_way(const string&path)
  {
    vector<int> way;
    QapAssert(!path.empty());
    QapAssert(path[0]=='/');
    auto arr=split(path.substr(1),"/");
    QapAssert(!arr.empty());
    auto*p=this;
    for(int i=0;i<arr.size();i++){
      QapAssert(!arr[i].empty());
      int id=p->find(arr[i]);
      if(id<0){id=p->items.size();p->add(arr[i]);}
      way.push_back(id);
      p=&p->items[id];
    }
    return way;
  }
  SelfClass&traverse(const vector<int>&way)
  {
    auto*p=this;
    for(int i=0;i<way.size();i++){
      QapAssert(p->check(way[i]));
      p=&p->items[way[i]];
    }
    return *p;
  }
  SelfClass&get(const string&path)
  {
    auto&arr=get_way(path);
    auto&node=traverse(arr);
    return node;
  }
};

class TShellEnv{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TShellEnv)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_chat_node,root,DEF,$,$)\
ADDEND()
//=====+>>>>>TShellEnv
#include "QapGenStruct.inl"
//<<<<<+=====TShellEnv
public:

};

class IShellCommand{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IShellCommand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IShellCommand
#include "QapGenStruct.inl"
//<<<<<+=====IShellCommand
public:
  virtual string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
  {
    return "empty";
  }
};

/*
class AppStarter;

class ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>ISubProgram
#include "QapGenStruct.inl"
//<<<<<+=====ISubProgram
public:
  static void SysHasSelf();
public:
  class IEnv{
  public:
    IEnvRTTI&Env;
    AppStarter*Starter;
    operator IEnvRTTI&(){return Env;}
  };
public:
  virtual void Update(IEnv&Env){}
};

class TProgramNode:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramNode)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,vector<TAutoPtr<ISubProgram>>,Programs,DEF,$,$)\
ADDVAR(2,bool,Enabled,SET,true,$)\
ADDEND()
//=====+>>>>>TProgramNode
#include "QapGenStruct.inl"
//<<<<<+=====TProgramNode
public:
  static void SysHasSelf();
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
  void ForceUpdate(IEnv&Env)
  {
    auto&arr=Programs;
    for(int i=0;i<arr.size();i++)
    {
      auto&it=arr[i];
      if(!it)continue;
      auto*ex=arr[i].get();
      ex->Update(Env);
    }
  }
  void Update(IEnv&Env)
  {
    if(!Enabled)return;
    ForceUpdate(Env);
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

class IAppStarterImpl{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IAppStarterImpl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IAppStarterImpl
#include "QapGenStruct.inl"
//<<<<<+=====IAppStarterImpl
public:
  typedef ISubProgram::IEnv IEnv;
public:
  virtual void Save(IEnv&Env){}
  virtual void Load(IEnv&Env){}
  virtual void Update(IEnv&Env){}
};

class AppStarter:public ISubProgram{
public:
#define DEF_PRO_NESTED(F)F(DoLoad)F(DoSave)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(AppStarter)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,string,FileName,SET,"data.qap",$)\
ADDVAR(2,TAutoPtr<ISubProgram>,Root,DEF,$,$)\
ADDVAR(3,TAutoPtr<IAppStarterImpl>,Impl,DEF,$,$)\
ADDEND()
//=====+>>>>>AppStarter
#include "QapGenStruct.inl"
//<<<<<+=====AppStarter
public:
  static void SysHasSelf();
public:
  void Save(IEnv&Env)
  {
    if(!Impl)return;
    auto*pImpl=Impl.get();
    pImpl->Save(Env);
  }
  void Load(IEnv&Env)
  {
    if(!Impl)return;
    auto*pImpl=Impl.get();
    pImpl->Load(Env);
  }
  void Update(IEnv&Env)
  {
    IEnv SubEnv={Env.Env,this};
    if(Root)Root->Update(SubEnv);
  }
public:
  class DoLoad:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoLoad)PARENT(ISubProgram)OWNER(AppStarter)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>DoLoad
    #include "QapGenStruct.inl"
    //<<<<<+=====DoLoad
  public:
    void Update(IEnv&Env)
    {
      if(!Env.Starter)return;
      Env.Starter->Load(Env);
    }
  };
  class DoSave:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoSave)PARENT(ISubProgram)OWNER(AppStarter)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>DoSave
    #include "QapGenStruct.inl"
    //<<<<<+=====DoSave
  public:
    void Update(IEnv&Env)
    {
      if(!Env.Starter)return;
      Env.Starter->Save(Env);
    }
  };
};

class QapRenderProgram;
class QapPluginMan;

class IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,bool,Deaded,SET,false,$)\
ADDEND()
//=====+>>>>>IUnitProgram
#include "QapGenStruct.inl"
//<<<<<+=====IUnitProgram
public:
  struct TBuildContext{
    IEnvRTTI&Env;
  };
  virtual void OnBuild(TBuildContext&Context){}
  virtual void Update(IEnvRTTI&Env){}
};

class IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IRenderProgram
#include "QapGenStruct.inl"
//<<<<<+=====IRenderProgram
public:
  struct IEnv{
    IEnvRTTI&Env;
    QapD3DDev9&Dev;
    operator IEnvRTTI&(){return Env;}
  };
  virtual void Render(QapDev&qDev){}
  virtual void Update(IEnv&Env){}
};

class TRenderNode:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRenderNode)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,vector<TAutoPtr<IRenderProgram>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TRenderNode
#include "QapGenStruct.inl"
//<<<<<+=====TRenderNode
public:
  static void SysHasSelf();
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }
public:
  void Render(QapDev&qDev)
  {
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(!ex)continue;
      ex->Render(qDev);
    }
  }
  void Update(IEnv&Env)
  {
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(!ex)continue;
      ex->Update(Env);
    }
  }
public:
  TAutoPtr<IRenderProgram>&front(){
    return Items.front();
  }
  TAutoPtr<IRenderProgram>&back(){
    return Items.back();
  }
public:
  bool empty()const{return Items.empty();}
};

class TRenderNodeEx:public TRenderNode{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRenderNodeEx)PARENT(TRenderNode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,bool,Enabled,SET,true,$)\
ADDVAR(1,bool,AutoRender,SET,true,$)\
ADDVAR(2,bool,AutoUpdate,SET,true,$)\
ADDEND()
//=====+>>>>>TRenderNodeEx
#include "QapGenStruct.inl"
//<<<<<+=====TRenderNodeEx
public:
  void Render(QapDev&qDev)
  {
    if(!Enabled)return;
    if(!AutoRender)return;
    ParentClass::Render(qDev);
  }
  void Update(IEnv&Env)
  {
    if(!Enabled)return;
    if(!AutoUpdate)return;
    ParentClass::Update(Env);
  }
};

class IRenderItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IRenderItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IRenderItem
#include "QapGenStruct.inl"
//<<<<<+=====IRenderItem
public:
  static void SysHasSelf();
public:
  virtual void Render(QapDev&qDev){}
};

class TReloadDetector{
public:
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TReloadDetector)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,bool,needinit,SET,false,$)\
ADDVAR($,bool,fresh,SYS,true,$)\
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
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,int,LastKey,SET,0,$)\
ADDVAR(2,char,LastChar,SET,0,$)\
ADDVAR($,bool,News,SYS,false,$)\
ADDVAR($,TKeyState,Down,SYD,$,$)\
ADDVAR($,TKeyState,Changed,SYD,$,$)\
ADDEND()
//=====+>>>>>QapKeyboard
#include "QapGenStruct.inl"
//<<<<<+=====QapKeyboard
public:
  static void SysHasSelf();
public:
  QapKeyboard&QapKeyboard::operator=(const QapKeyboard&){
    QapAssert(0);
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
};


class KeyVisorProgram:public ISubProgram{
public:
  class ICallback:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ICallback)PARENT(ISubProgram)OWNER(KeyVisorProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>ICallback
    #include "QapGenStruct.inl"
    //<<<<<+=====ICallback
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env){}
    virtual void DoMove(KeyVisorProgram*pSender){}
  };
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(KeyVisorProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<QapKeyboard>,Keyboard,DEF,$,$)\
ADDVAR(2,int,Key,SET,0,$)\
ADDVAR(3,bool,Down,SET,false,$)\
ADDVAR(4,TWeakPtr<ICallback>,OnUp,DEF,$,$)\
ADDVAR(5,TWeakPtr<ICallback>,OnMove,DEF,$,$)\
ADDVAR(6,TWeakPtr<ICallback>,OnDown,DEF,$,$)\
ADDEND()
//=====+>>>>>KeyVisorProgram
#include "QapGenStruct.inl"
//<<<<<+=====KeyVisorProgram
public:
    static void SysHasSelf();
public:
  void CallAction(TWeakPtr<ICallback>&A)
  {
    if(!A)return;A->DoMove(this);
  }
public:
  void Update(IEnv&Env){DoMove();}
  void DoMove()
  {
    if(!Keyboard)return;
    auto*pKeyboard=Keyboard.get();
    if(!InDip<int>(0,Key,QapKeyboard::TKeyState::MAX_KEY-1))return;
    bool Flag=pKeyboard->Down[Key];
    if(Flag==Down)
    {
      if(pKeyboard->Changed[Key])
      {
        Down=!Down;if(Down){KeyDown();CallAction(OnDown);}else{KeyUp();CallAction(OnUp);}
        Down=!Down;if(Down){KeyDown();CallAction(OnDown);}else{KeyUp();CallAction(OnUp);}
      };
      if(Down){KeyMove();CallAction(OnMove);}
      return;
    }
    if(!Down&&Flag){Down=true;KeyDown();CallAction(OnDown);}
    if(Down&&!Flag){Down=false;KeyUp();CallAction(OnUp);}
    if(Down){KeyMove();CallAction(OnMove);}
  }
  virtual void KeyDown(){};
  virtual void KeyUp(){};
  virtual void KeyMove(){};
};

class eQuad{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eQuad)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,x,SET,320,$)\
ADDVAR(1,int,y,SET,240,$)\
ADDVAR(2,int,w,SET,320,$)\
ADDVAR(3,int,h,SET,240,$)\
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
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,QapD3D9,D9,DEF,$,$)\
ADDVAR(2,QapD3DDev9,D9Dev,DEF,$,$)\
ADDVAR(3,TProgramNode,UserCode,DEF,$,$)\
ADDEND()
//=====+>>>>>IProgramD3D9
#include "QapGenStruct.inl"
//<<<<<+=====IProgramD3D9
public:
  static void SysHasSelf();
public:
  virtual vec2i WindowGetClientSize(){QapDebugMsg("no way");return vec2i(128,128);}
  virtual QapKeyboard&GetKeyBoard(){QapDebugMsg("no way");return *(QapKeyboard*)nullptr;}
  virtual vec2i WindowGetMousePos(){QapDebugMsg("no way");return vec2i(128,128);}
  virtual eQuad&WindowGetQuad(){QapDebugMsg("no way");return *(eQuad*)nullptr;}
  virtual void WindowUpdateMode(){QapDebugMsg("no way");return;}
  virtual void WindowFullScreen(bool fullscreen){QapDebugMsg("no way");return;}
  virtual int WindowGetzDelta(){QapDebugMsg("no way");return 0;}
};

class QapRenderProgram:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapRenderProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<IProgramD3D9>,Program,DEF,$,$)\
ADDVAR(2,QapResourceList,ResList,DEF,$,$)\
ADDVAR(3,QapResourceDetector,Detector,DEF,$,$)\
ADDVAR(4,QapDev,qDev,DEF,$,$)\
ADDVAR(5,TRenderNode,Scene,DEF,$,$)\
ADDEND()
//=====+>>>>>QapRenderProgram
#include "QapGenStruct.inl"
//<<<<<+=====QapRenderProgram
public:
  static void SysHasSelf();
public:
  void Render(QapD3DDev9&Dev) 
  {
    if(!Program)return;
    vec2i ClientSize=Program->WindowGetClientSize();
    if(!Dev.BeginScene())return;
    {
      D3DVIEWPORT9 ViewPort={0,0,ClientSize.x,ClientSize.y,-1.f,+1.f};
      Dev.pDev->SetViewport(&ViewPort);
      Dev.Set2D(vec2d(0,0),1.0,0,&ClientSize);
      Dev.Clear2D(0xffc8c8c8);
      qDev.NextFrame();
      DoDraw(qDev);
    }
    if(!Dev.EndScene())return;
    RECT Rect={0,0,ClientSize.x,ClientSize.y};
    Dev.Present(&Rect,&Rect);
  }
  void Update(IEnv&Env)
  {
    if(!Program)return;
    DoMove(Env);
    auto&Dev=Program->D9Dev;
    Render(Dev);
  }
  void DoDraw(QapDev&qDev)
  {
    Scene.Render(qDev);
  }
  void DoMove(IEnv&Env)
  {
    auto&Dev=Program->D9Dev;
    if(!qDev.DynRes.pDev)
    {
      qDev.MountDev(Dev);
      qDev.Init(1024*64,1024*64*3);
      Detector.MountDev(Dev);
      Detector.needinit=true;
    }
    if(Detector.needinit)
    {
      Detector.Init();
      ResList.Run(Env.Env,&Dev);
    };
    //
    TRenderNode::IEnv env={Env.Env,Dev};
    Scene.Update(env);
  }
};

class ITreeDebuggerBranch{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ITreeDebuggerBranch)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>ITreeDebuggerBranch
#include "QapGenStruct.inl"
//<<<<<+=====ITreeDebuggerBranch
public:
  static void SysHasSelf();
public:
  typedef TVoidPtr::TRawPtr TRawPtr;
  virtual TRawPtr GetRawPtr(){QapDebugMsg("no way.");TRawPtr tmp(nullptr,nullptr); return tmp;}
  virtual string GetCode(){QapDebugMsg("no way.");return "";}
};

class IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IGUI_Content
#include "QapGenStruct.inl"
//<<<<<+=====IGUI_Content
public:
  static void SysHasSelf();
public:
  struct TRenderContext
  {
    vec2d pos;
    vec2d size;
    vec2d mpos;
    QapDev&qDev;
  };
public:
  virtual void Render(TRenderContext&Context){}
  struct TUpdateContext
  {
    vec2d pos;
    vec2d size;
    vec2d mpos;
    int zDelta;
    QapKeyboard&keyboard;
  };
  virtual void Update(TUpdateContext&Context){}
public:
  virtual void GetSize(vec2d&size){size=vec2d_zero;}
public:
  static void DrawGreenTrigon(TRenderContext&Context,int c32=32)
  {
    auto&qDev=Context.qDev;
    qDev.SetColor(0xFF50A050);
    qDev.DrawTrigon(vec2d(0,-c32),vec2d(-c32,0),vec2d(+c32,0));
  }
};


class QapPluginMan{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapPluginMan)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,vector<TAutoPtr<IUnitProgram>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>QapPluginMan
#include "QapGenStruct.inl"
//<<<<<+=====QapPluginMan
public:
  static void SysHasSelf();
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
  void MakeAll(IEnvRTTI&Env,TType*pIUnitProgram)
  {
    IUnitProgram::TBuildContext Context={Env,*pQRP};
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
  void Update(IEnv&Env)
  {
    auto&arr=Items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*pItem=ex.get();
      pItem->Update(Env.Env);
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
*/
//-------------------------------------------//
//   {<|          21.01.2013           |>}   //
//-------------------------------------------//
#ifdef DEF_BUILD_MACRO
  #include "../Macro/QapProgramD3D9.h"
#else
//=====>>>>>QapProgramD3D9

class QapWinProgram:public ISubProgram{
public:
#define DEF_PRO_NESTED(F)F(DoClose)F(DoInit)F(DoFree)F(ExitCondition)F(CloseTrigger)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapWinProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>QapWinProgram
#include "QapGenStruct.inl"
//<<<<<+=====QapWinProgram
public:
  static void SysHasSelf();
public:
  typedef QapWinProgram OwnerProgram;
public:
  virtual bool Runned(){return false;}
  virtual bool NeedClose(){return false;}
public:
  virtual void PreClose(){/*Window.NeedClose=false;*/}
  virtual void Close(){}
  virtual void Init(){}
  virtual void Free(){}
public:
public:
  class DoClose:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoClose)PARENT(ISubProgram)OWNER(OwnerProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TWeakPtr<OwnerProgram>,Win,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoClose
    #include "QapGenStruct.inl"
    //<<<<<+=====DoClose
  public:
    void Update(IEnv&Env)
    {
      if(!Win)return;
      auto*win=Win.get();
      win->Close();
    }
  };
  class DoInit:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoInit)PARENT(ISubProgram)OWNER(OwnerProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TWeakPtr<OwnerProgram>,Win,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoInit
    #include "QapGenStruct.inl"
    //<<<<<+=====DoInit
  public:
    void Update(IEnv&Env)
    {
      if(!Win)return;
      auto*win=Win.get();
      win->Init();
    }
  };
  class DoFree:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoFree)PARENT(ISubProgram)OWNER(OwnerProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TWeakPtr<OwnerProgram>,Win,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoFree
    #include "QapGenStruct.inl"
    //<<<<<+=====DoFree
  public:
    void Update(IEnv&Env)
    {
      if(!Win)return;
      auto*win=Win.get();
      win->Free();
    }
  };
public:
  class ExitCondition:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ExitCondition)PARENT(ISubProgram)OWNER(OwnerProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(1,TWeakPtr<OwnerProgram>,App,DEF,$,$)\
    ADDVAR(2,TWeakPtr<ProgramLoop>,Loop,DEF,$,$)\
    ADDEND()
    //=====+>>>>>ExitCondition
    #include "QapGenStruct.inl"
    //<<<<<+=====ExitCondition
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env)
    {
      if(!Loop)return;
      auto*loop=Loop.get();
      if(!App){loop->Condition=false;return;}
      auto*app=App.get();
      loop->Condition=app->Runned();
    }
  };
public:
  class CloseTrigger:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(CloseTrigger)PARENT(ISubProgram)OWNER(OwnerProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(1,TWeakPtr<OwnerProgram>,App,DEF,$,$)\
    ADDVAR(2,TAutoPtr<TProgramNodeEx>,Action,DEF,$,$)\
    ADDEND()
    //=====+>>>>>CloseTrigger
    #include "QapGenStruct.inl"
    //<<<<<+=====CloseTrigger
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env)
    {
      if(!Action||!App)return;
      auto*action=Action.get();
      auto*app=App.get();
      if(app->NeedClose())
      {
        app->PreClose();
        action->Enabled=true;
        action->Update(Env); //lol, nice job!
      }
    }
  };
public:
  template<class WinProgram>
  static void CreateDefaultProgram(IEnv&Env,TAutoPtr<ISubProgram>&Root)
  {
    //проверяем поддерживает ли WinProgram QapWinProgram.
    {QapWinProgram*QWP=(WinProgram*)nullptr;}
    if(Root)return;
    //создаём главный нод основной программы.
    auto*root=Root.build<TProgramNode>(Env);
    //создаём скрипт запускающий конструктор у окна.
    auto*init=root->AddItem<DoInit>(Env);
    //создаём скрипт включающий главный цикл.
    auto*start=root->AddItem<ProgramLoop::DoStart>(Env);
    //создаём главный цикл порграммы.
    auto*loop=root->AddItem<ProgramLoop>(Env);
    //создаём нод - тело цикла
    auto*body=loop->Body.build<TProgramNode>(Env);
    {}
      //создаём окно.
      auto*win=body->AddItem<WinProgram>(Env);
      //создаём счётчик. так, для забавы.
      auto*counter=body->AddItem<ProgramLoop::Counter>(Env);
      //создаём задержку в 10 мс. Тоже для забавы.
      auto*sleep=body->AddItem<ProgramSleep>(Env);
      //создаём тригер закрывающий программу.
      auto*trigger=body->AddItem<CloseTrigger>(Env);
      {}
        //создаём узел со сценарием сохранения.
        auto*action=trigger->Action.build<TProgramNodeEx>(Env);
        {}
          //создаём сценарий сохраняющий основную программу.
          auto*save=action->AddItem<AppStarter::DoSave>(Env);
          //создаём сценарий закрывающий программу
          auto*close=action->AddItem<DoClose>(Env);
        {}
      {}
      //создаём сценарий выключающий главный цикл.
      auto*cond=body->AddItem<ExitCondition>(Env);
    {}
    //создаём сценарий запускающий деструктор у окна.
    auto*free=root->AddItem<DoFree>(Env);
    //settings
    if(true)
    {
      init->Win=win;
      start->Loop=loop;
      trigger->App=win;
      action->Enabled=false;
      close->Win=win;
      cond->App=win;
      cond->Loop=loop;
      free->Win=win;
    }
  }
};

class eWinProgram:public QapWinProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eWinProgram)PARENT(QapWinProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,eWindow,Window,DEF,$,$)\
ADDEND()
//=====+>>>>>eWinProgram
#include "QapGenStruct.inl"
//<<<<<+=====eWinProgram
public:
  static void SysHasSelf();
public:
  typedef QapWinProgram OwnerProgram;
public:
  bool Runned()
  {
    return Window.Runned;
  }
  bool NeedClose()
  {
    return Window.NeedClose;
  }
public:
  void PreClose(){Window.NeedClose=false;}
  void Close()
  {
    if(!Window.IsWindow())return;
    Window.Runned=false;
  }
  void Init()
  {
    if(Window.IsWindow())return;
    Window.Init();
    Window.WindowMode();
  }
  void Free()
  {
    if(!Window.IsWindow())return;
    Window.Free();
  }
public:
  void Update(IEnv&Env)
  {
    Window.Update();
  }
};

class QapRenderProgram;
class QapProgramD3D9;

class TProgramD3D9:public IProgramD3D9{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramD3D9)PARENT(IProgramD3D9)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TWeakPtr<QapProgramD3D9>,pQapProgD3D9,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramD3D9
#include "QapGenStruct.inl"
//<<<<<+=====TProgramD3D9
public:  
  //===>>>---
  #define MACRO_WEAK
  #include "macro_scope.inl"
  MACRO_WEAK_FUNC(vec2i,WindowGetClientSize,(),())
  {
    if(!pQapProgD3D9)return ParentClass::WindowGetClientSize();
    return pQapProgD3D9->Window.GetClientSize();
  }
  MACRO_WEAK_FUNC(QapKeyboard&,GetKeyBoard,(),())
  {
    if(!pQapProgD3D9)return ParentClass::GetKeyBoard();
    return pQapProgD3D9->Window.Keyboard;
  }
  MACRO_WEAK_FUNC(vec2i,WindowGetMousePos,(),())
  {
    if(!pQapProgD3D9)return ParentClass::WindowGetMousePos();
    return pQapProgD3D9->Window.GetMousePos();
  }
  MACRO_WEAK_FUNC(eQuad&,WindowGetQuad,(),())
  {
    if(!pQapProgD3D9)return ParentClass::WindowGetQuad();
    return pQapProgD3D9->Window.Quad;
  }
  MACRO_WEAK_FUNC(void,WindowUpdateMode,(),())
  {
    if(!pQapProgD3D9)return ParentClass::WindowUpdateMode();
    return pQapProgD3D9->Window.WindowMode();
  }
  MACRO_WEAK_FUNC(void,WindowFullScreen,(bool fullscreen),(fullscreen))
  {
    if(!pQapProgD3D9)return;
    pQapProgD3D9->Window.FullScreen=fullscreen;
  }
  MACRO_WEAK_FUNC(int,WindowGetzDelta,(),())
  {
    if(!pQapProgD3D9)return ParentClass::WindowGetzDelta();
    return pQapProgD3D9->Window.zDelta;
  }
  #include "macro_scope.inl"
  //---<<<===
};

class QapProgramD3D9:public QapWinProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapProgramD3D9)PARENT(QapWinProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,eWindow,Window,DEF,$,$)\
ADDVAR(2,TProgramD3D9,Prog,DEF,$,$)\
ADDEND()
//=====+>>>>>QapProgramD3D9
#include "QapGenStruct.inl"
//<<<<<+=====QapProgramD3D9
public:
  static void SysHasSelf();
public:
  typedef QapProgramD3D9 OwnerProgram;
public:
  bool Runned()
  {
    return Window.Runned;
  }
  bool NeedClose()
  {
    return Window.NeedClose;
  }
public:
  void PreClose(){Window.NeedClose=false;}
  void Close()
  {
    if(!Window.IsWindow())return;
    Window.Runned=false;
  }
  void Init()
  {
    if(Window.IsWindow())return;
    Window.Init();
    Window.WindowMode();
    Prog.D9.Init();
    auto wnd=Window.Form.WinPair.hWnd;
    Prog.D9Dev.PresParams.SetToDef(wnd,true);
    Prog.D9Dev.Init(wnd,Prog.D9);
    Prog.pQapProgD3D9=this;
  }
  void Free()
  {
    if(!Window.IsWindow())return;
    Window.Free();
  }
public:
  void Update(IEnv&Env)
  {
    Window.Update();
    if(!Prog.UserCode.empty())
    {
      Prog.UserCode.Update(Env);
    }else{
      BuildUserCode<void>(Env);
    }
  }
  template<class TYPE>
  TYPE BuildUserCode(IEnv&Env)
  {
    auto*root=&Prog.UserCode;
    {auto*empty_node=root->AddItem<TProgramNode>(Env);}
    auto*node=root->AddItem<TProgramNode>(Env);
    {auto*empty_node=root->AddItem<TProgramNode>(Env);}
    auto*keyvisor=node->AddItem<TProgramNode>(Env)->AddItem<KeyVisorProgram>(Env);
    keyvisor->Key=VK_ESCAPE;
    keyvisor->Keyboard=&Window.Keyboard;
    auto*quit=node->AddItem<TProgramQuit>(Env);
    quit->Program=this;
    keyvisor->OnDown=quit;
    auto*qap_render_program=node->AddItem<QapRenderProgram>(Env);
    qap_render_program->Program=&this->Prog;
    {
      auto*pPluginMan=root->AddItem<QapPluginMan>(Env);
      auto*pIUnitProgram=Sys$$<IUnitProgram>::GetRTTI(Env.Env);
      pPluginMan->MakeAll(Env.Env,qap_render_program,pIUnitProgram);
    }
  }
};

class TProgramQuit:public KeyVisorProgram::ICallback{
public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramQuit)PARENT(KeyVisorProgram::ICallback)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
  ADDVAR(1,TWeakPtr<QapProgramD3D9>,Program,DEF,$,$)\
  ADDEND()
  //=====+>>>>>TProgramQuit
  #include "QapGenStruct.inl"
  //<<<<<+=====TProgramQuit
public:
  static void SysHasSelf();
public:
  void Update(IEnv&Env){}
  virtual void DoMove(KeyVisorProgram*pSender){
    auto*prog=Program.get();
    prog->Window.Close();//Close();
  }
};

// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----

//#include "temp_code_05_03_2012.inl"
//#include "TextDebuger.inl"
//#include "OutDeviceBase.inl"
#include "OutDevice.inl"
#include "OutDeviceEx.inl"


#include "qap_text_selector.inl"
#include "QapTypeSelector.inl"

class QapRenderProgram;

class QapTreeDebugger:public IRenderProgram{
public:
  class DoFieldCopy:public KeyVisorProgram::ICallback{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoFieldCopy)PARENT(KeyVisorProgram::ICallback)OWNER(QapTreeDebugger)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(1,TFieldPtr,Dest,DEF,$,$)\
    ADDVAR(2,TFieldPtr,Source,DEF,$,$)\
    ADDVAR(3,bool,Enabled,SET,false,$)\
    ADDVAR(4,bool,AutoDisable,SET,true,$)\
    ADDEND()
  //=====+>>>>>DoFieldCopy
  #include "QapGenStruct.inl"
  //<<<<<+=====DoFieldCopy
  public:
    void Update(IEnv&Env){
      if(!Enabled||!Source||!Dest)return;
      if(AutoDisable)Enabled=false;
      TType*pSourceType=Source.getType();
      TType*pDestType=Dest.getType();
      if(pSourceType!=pDestType)return;
      if(!pSourceType||!pDestType)return;
      void*pSourceValue=Source.getValue();
      void*pDestValue=Dest.getValue();
      if(!pSourceValue||!pDestValue)return;
      if(pSourceValue==pDestValue)return;
      QapClock Clock[3];
      QapDebugMsg("first pass");
      //Clock[0].Start();
      //{
      //  TQapIO Stream;
      //
      //  Clock[1].Start();
      //  QapSaveToFastStream(Env.Env,Stream,pSourceType,pSourceValue);
      //  Clock[1].Stop();
      //
      //  Stream.IO.pos=0;
      //
      //  Clock[2].Start();
      //  QapLoadFromFastStream(Env.Env,Stream,pDestType,pDestValue);
      //  Clock[2].Stop();
      //}
      //Clock[0].Stop();
      real ms[3];
      for(int i=0;i<lenof(Clock);i++)ms[i]=Clock[i].MS();
      if(ms[0]>500)
      {
        int omg=1;
      }
    }
    void DoMove(KeyVisorProgram*pSender)
    {
      Enabled=true;
    }
  };
  class DevCallBack:public KeyVisorProgram::ICallback{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DevCallBack)PARENT(KeyVisorProgram::ICallback)OWNER(QapTreeDebugger)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(1,bool,Enabled,SET,false,$)\
    ADDVAR(2,bool,AutoDisable,SET,true,$)\
    ADDEND()
  //=====+>>>>>DevCallBack
  #include "QapGenStruct.inl"
  //<<<<<+=====DevCallBack
  public:
    void Update(IEnv&Env){
      if(AutoDisable)Enabled=false;
    }
    void DoMove(KeyVisorProgram*pSender){Enabled=true;}
  };
  class DevTools:public ISubProgram{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DevTools)PARENT(ISubProgram)OWNER(QapTreeDebugger)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(4,DevCallBack,OnControl,DEF,$,$)\
    ADDVAR(5,DevCallBack,OnLControl,DEF,$,$)\
    ADDVAR(6,DevCallBack,OnRControl,DEF,$,$)\
    ADDVAR(7,KeyVisorProgram,KeyControl,DEF,$,$)\
    ADDVAR(8,KeyVisorProgram,KeyLControl,DEF,$,$)\
    ADDVAR(9,KeyVisorProgram,KeyRControl,DEF,$,$)\
    ADDEND()
  //=====+>>>>>DevTools
  #include "QapGenStruct.inl"
  //<<<<<+=====DevTools
  public:
    static void SysHasSelf();
  public:
    void SetToDef(IProgramD3D9&Program)
    {
      auto&Keyboard=Program.GetKeyBoard();
      KeyControl.Key=VK_CONTROL;
      KeyControl.Keyboard=&Keyboard;
      KeyControl.OnDown=&OnControl;
      KeyLControl.Key=VK_LCONTROL;
      KeyLControl.Keyboard=&Keyboard;
      KeyLControl.OnDown=&OnLControl;
      KeyRControl.Key=VK_RCONTROL;
      KeyRControl.Keyboard=&Keyboard;
      KeyRControl.OnDown=&OnRControl;
    }
    void Update(IEnv&Env)
    {
      {
        ISubProgram*Arr[]={&OnControl,&OnLControl,&OnRControl,&KeyControl,&KeyLControl,&KeyRControl};
        for(int i=0;i<lenof(Arr);i++)Arr[i]->Update(Env);
      }
    }
    bool IsOnDown(){return OnControl.Enabled;};
    bool IsOnLDown(){return OnLControl.Enabled;};
    bool IsOnRDown(){return OnRControl.Enabled;};
    bool IsDown(){return KeyControl.Down;}
    bool IsLDown(){return KeyLControl.Down;}
    bool IsRDown(){return KeyRControl.Down;}
  };
public:
  class TPage{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPage)OWNER(QapTreeDebugger)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(1,TFieldPtr,Select,DEF,$,$)\
    ADDVAR(2,vec2d,pos,SET,vec2d(0,0),$)\
    ADDVAR(3,int,zD,SET,0,$)\
    ADDVAR(4,int,MaxDepth,SET,3,$)\
    ADDVAR(5,bool,NeedRemove,SET,false,$)\
    ADDEND()
  //=====+>>>>>TPage
  #include "QapGenStruct.inl"
  //<<<<<+=====TPage
  public:
    static void SysHasSelf();
  };
  class TPages{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPages)OWNER(QapTreeDebugger)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<TPage>,Items,DEF,$,$)\
    ADDEND()
  //=====+>>>>>TPages
  #include "QapGenStruct.inl"
  //<<<<<+=====TPages
  public:
    void Update()
    {
      int last=0;
      for(int i=0;i<Items.size();i++)
      {
        auto&ex=Items[i];
        if(ex.NeedRemove)continue;
        if(last!=i)
        {
          auto&ax=Items[last];
          ax=std::move(ex);
        }
        last++;
      }
      if(last==Items.size())return;
      Items.resize(last);
    }
  };
public:
  class TBranch{
  public:
    typedef TOutDevEx::DevCmd DevCmd;
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBranch)OWNER(QapTreeDebugger)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TFieldPtr,Root,DEF,$,$)\
    ADDVAR(1,bool,NeedRemove,SET,false,$)\
    ADDVAR(2,vector<TAutoPtr<DevCmd>>,Items,DEF,$,$)\
    ADDVAR(3,string,Code,DEF,$,$)\
    ADDEND()
  //=====+>>>>>TBranch
  #include "QapGenStruct.inl"
  //<<<<<+=====TBranch
  public:
    struct TOutDevBuff
    {
      OutDevice&OD;
      vector<TAutoPtr<TOutDev::DevCmd>> out;
      TOutDevBuff(OutDevice&OD):OD(OD){}
      void push()
      {

        int count=out.size();
        for(int i=0;i<count;i++)
        {
          auto*p=out[i].get();
          OD.push(p);
        }
      }
      void pop()
      {
        int count=out.size();
        for(int i=0;i<count;i++)
        {
          OD.pop();
        }
      }
      bool grab(IEnvRTTI&Env,TBranch*p,TType*pTBranch)
      {
        if(!p||!p->Root)return false;
        auto&Items=p->Items;
        auto&Root=p->Root;
        auto&object=Root.object;
        auto&top=OD.branch.top;
        top.pType=pTBranch;
        top.pValue=p;
        //
        out.reserve(256);
        //
        static int RootFieldIndexInBranch=get_field_index_in_type(pTBranch,"Root");
        //
        {
          TAutoPtr<TOutDev::DevCmd> GotoMemberRoot;
          GotoMemberRoot.build<TOutDev::TMemberID>(Env)->id=RootFieldIndexInBranch;
          out.push_back(std::move(GotoMemberRoot));
          TAutoPtr<TOutDev::DevCmd> GotoRootValue;
          GotoRootValue.build<TOutDev::TField>(Env);
          out.push_back(std::move(GotoRootValue));
        }
        //
        //SubFieldsInfo::TFieldInfo Info={Root.getType(),Root.offset};
        //index=SubFieldsInfo::FieldInfoToIndex(Root.object.type.get(),Info);
        //QapAssert(index>=0); hidden::BST_CmdList_To_RT_CmdList(p->Items,OD);
        //
        TOutDevEx::TCmdConverterEx Conv;
        Conv.Context.pType=Root.getType();
        Conv.Context.pValue=Root.getValue();
        Conv.Init(&Env);
        //      
        {
          auto&arr=Items;
          for(int i=0;i<arr.size();i++)
          {
            auto&ex=arr[i];
            auto*p=ex.get();
            p->Use(Conv);
            if(Conv.CV.error)break;
            out.push_back(std::move(Conv.pCmd));
          }
          if(Conv.CV.error)
          {
            out.clear();
            return false;
          }
        }
        return true;
      }
    };
    struct TMeCallBack:OutDevice::IExternalCallBack
    {
      int index;
      TOutDevEx::TCmdHeadVisitor&Head;
      TBranch&Branch;
      DevTools&Tools;
      TMeCallBack(TOutDevEx::TCmdHeadVisitor&Head,TBranch&Branch,DevTools&Tools):Head(Head),Branch(Branch),Tools(Tools){index=-1;}
      bool Pass(string&buff)
      {
        if(index==-1)
        {
          buff=std::move(Head.out);
          return true;
        }
        auto&Items=Branch.Items;
        bool result=index<Items.size();
        if(!result)return false;
        auto&ex=Items[index];
        if(!ex)
        {
          Head.add_error("cmd is empty");
          return false;
        }
        auto*pCmd=ex.get();
        pCmd->Use(Head);
        if(Head.error)return false;
        buff=std::move(Head.out);
        return true;
      }
      void Next(){index++;}
      void OnSelect()
      {
        //use index here
        if(index<0)return;
        if(!Tools.IsOnRDown())return;
        Branch.Items.resize(index);
        Branch.UpdateCode();
      }
    };
    void UpdateCode()
    {
      TOutDevEx::TContext Context;
      Context.pType=Root.getType();
      Context.pValue=Root.getValue();
      TOutDevEx::TCmdHeadVisitor Head;
      Head.pContext=&Context;
      auto&arr=Items;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!ex)
        {
          Head.add_error("cmd is empty");
          break;
        }
        auto*pCmd=ex.get();
        pCmd->Use(Head);
        //
        if(Head.error)break;
      }
      if(Head.error)
      {
        Head.out+="{...error: "+Head.error_string+"...}";
      }
      Code=std::move(Head.out);
    }
    typedef TVoidPtr::TRawPtr TRawPtr;
    TRawPtr GetRawPtr()
    {
      TRawPtr raw_ptr;
      raw_ptr.setZero();
      //
      TOutDevEx::TContext Context;
      Context.pType=Root.getType();
      Context.pValue=Root.getValue();
      TOutDevEx::TCmdHeadVisitor Head;
      Head.pContext=&Context;
      auto&arr=Items;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!ex)
        {
          Head.add_error("cmd is empty");
          break;
        }
        auto*pCmd=ex.get();
        pCmd->Use(Head);
        //
        if(Head.error)break;
      }
      if(Head.error)
      {
        Head.out+="{...error: "+Head.error_string+"...}";
        return raw_ptr;
      }
      raw_ptr.pType=Context.pType;
      raw_ptr.pValue=Context.pValue;
      return raw_ptr;
    }
  };
  class TBranchEx:public ITreeDebuggerBranch{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBranchEx)PARENT(ITreeDebuggerBranch)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,QapTreeDebugger::TBranch,Branch,DEF,$,$)\
  ADDEND()
  //=====+>>>>>TBranchEx
  #include "QapGenStruct.inl"
  //<<<<<+=====TBranchEx
  public:
    typedef TVoidPtr::TRawPtr TRawPtr;
    virtual TRawPtr GetRawPtr()
    {
      return Branch.GetRawPtr();
    }
    virtual string GetCode()
    {
      Branch.UpdateCode();
      return Branch.Code;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(DoFieldCopy)F(DevTools)F(DevCallBack)F(TPage)F(TPages)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTreeDebugger)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<IProgramD3D9>,Program,DEF,$,$)\
ADDVAR(2,TWeakPtr<QapFontObject>,FontObject,DEF,$,$)\
ADDVAR(4,vec2d,pos,SET,vec2d(-665,385),$)\
ADDVAR(5,vec2d,mpos,SET,vec2d(-200,350),$)\
ADDVAR(10,bool,AutoUpdate,SET,true,$)\
ADDVAR(11,bool,NeedCallWindowMode,SET,false,$)\
ADDVAR(12,int,zD,SET,0,$)\
ADDVAR(14,int,MaxDepth,SET,3,$)\
ADDVAR(16,TWeakPtr<DevTools>,Tools,DEF,$,$)\
ADDVAR(20,TWeakPtr<TType>,pQapTreeDebugger,DEF,$,$)\
ADDVAR(21,TWeakPtr<TType>,pTBranch,DEF,$,$)\
ADDVAR(25,bool,InScreenOptimization,SET,true,$)\
ADDVAR(26,bool,SkipCommaInVector,SET,true,$)\
ADDVAR(31,bool,NeedClearPages,SET,false,$)\
ADDVAR(32,TPages,pages,DEF,$,$)\
ADDVAR(35,bool,NeedClearBranches,SET,false,$)\
ADDVAR(36,bool,AutoUpdateBranchesHead,SET,false,$)\
ADDVAR(37,vector<TBranch>,Branches,DEF,$,$)\
ADDVAR(38,TBranchEx,SelectBranch,DEF,$,$)\
ADDVAR(39,TBranchEx,DestBranch,DEF,$,$)\
ADDVAR(40,int,SelectBranchId,SET,0,$)\
ADDVAR(41,bool,SelectBranchEnabled,SET,false,$)\
ADDVAR(45,QapTextSelectorV4OnDown,OnDownSelect,DEF,$,$)\
ADDVAR(50,TFieldPtr,Select,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTreeDebugger
#include "QapGenStruct.inl"
//<<<<<+=====QapTreeDebugger
public:
  static void SysHasSelf();
public:
  typedef OutDevice::str_line str_line;
  vector<str_line> lines;
  void Render(QapDev&qDev)
  {
    if(!FontObject)return;
    auto*font_obj=FontObject.get();
    auto&font=font_obj->Font;
    qDev.SetColor(0xff000000);
    qDev.BindTex(0,&font_obj->Tex);
    real y=pos.y+zD;
    int dy=-font.Info.Coords[0].y;
    int dx=font.Info.Coords[0].x;
    QapDev::BatchScope Scope(qDev);
    {
      QapClock Clock;
      Clock.Start();
      for(int i=0;i<lines.size();i++)
      {
        auto&ex=lines[i];
        //qDev.SetColor(0xff000000);
        bool flag=false;
        int h=-dy-2;
        int x=pos.x-dx+dx*ex.indent;
        if(InDip<int>(0,mpos.y-y-dy,h))
        {
          int L=QapQ3Text::GetLength(font,".."+ex.text);
          if(InDip<int>(0,mpos.x-x,L))
          {
            //qDev.SetColor(0xff008100);
            flag=true;
          }
        }
        string line=!flag?"^1.^0"+ex.text+"^1.":"^7[^0"+ex.text+"^7]";
        do{
          string mono;
          bool flag=false;
          bool good=false;
          bool need=false;
          for(int i=0;i<line.size();i++)
          {
            auto&ex=line[i];
            if(ex=='^'){flag=true;continue;}
            if(!flag)
            {
              mono+=good?CToS(ex):" ";
              continue;
            }else{flag=false;}
            if(ex=='E'){good=true;need=true;continue;}
            good=false;
          }
          if(!need)break;
          //qDev.SetColor(0xffffffff);
          qDev.SetColor(0xff000000);
          //qDev.SetColor(0xff505050);
          //qDev.SetColor(0xffa8a8a8);
          QapQ3Text::DrawQapText(&qDev,font,x+1,y-1,mono);
          //QapQ3Text::DrawQapText(&qDev,font,x-1,y+1,mono);
          //QapQ3Text::DrawQapText(&qDev,font,x-1,y-1,mono);
          //QapQ3Text::DrawQapText(&qDev,font,x+1,y+1,mono);
        }while(false);

        QapQ3Text::DrawQapText(&qDev,font,x,y,line);
        y+=dy;
      }
      Clock.Stop();
      QapQ3Text::DrawQapText(&qDev,font,pos.x-dx,y,"^1.^0=====[render:"+FToS(Clock.MS())+"]=====^1.");
    }
  }
public:
  typedef TFieldPtr::TInfo TFieldPtrInfo;
  class TCallBack:public OutDevice::ICallBack{
  public:
    TFieldPtrInfo Info;
    bool UseInfo;
    DevTools*pTools;
    IEnvRTTI*pEnv;
    TBranch Branch;
    bool SelectBranch;
    bool DestBranch;
    TCallBack():UseInfo(false),SelectBranch(false),DestBranch(false){}
  public:
    void MicroCode(OutDevice&OD)
    {
      auto&top=OD.branch.top;
      auto&branch=OD.branch;
      UseInfo=true;
      if(true)do
      {
        OD.push(nullptr);
        {
          typedef OutDevice::TCmdOffsetVisitorEx TCove;
          typedef TCove::TContext TContext;
          auto&front=branch.front();
          TContext Context={{front.pType,front.pValue},{front.pType,front.pValue},0};
          TCove Cove;
          Cove.pContext=&Context;
          auto&arr=branch;
          for(int i=0;i+1<arr.size();i++)
          {
            auto&ex=arr[i+1];
            auto&ax=arr[i+0];
            auto*pCmd=ax.pCmd;
            if(!pCmd){
              TCove::TContext tmp={{ex.pType,ex.pValue},{ex.pType,ex.pValue},0};
              Context=tmp;
            }else{
              pCmd->Use(Cove);
            }
          }
          Info.set(TTypeStruct::UberCast(Context.Object.pType),Context.Object.pValue,Context.Field.pType,Context.Offset);
        }
        OD.pop();
      }while(false);
    }
    void BranchCode(OutDevice&OD)
    {
      auto&top=OD.branch.top;
      auto&branch=OD.branch;
      if(true)do
      {
        OD.push(nullptr);
        {
          typedef OutDevice::TCmdOffsetVisitorEx TCove;
          typedef TCove::TContext TContext;
          auto&front=branch.front();
          TContext Context={{front.pType,front.pValue},{front.pType,front.pValue},0};
          TCove Cove;
          Cove.pContext=&Context;
          TFieldPtrInfo FPI;
          if(branch.size()>1)
          {
            auto&ex=branch[1];
            QapAssert(ex.pType->GetFullName()=="TFieldPtr");
            TFieldPtr&FP=*(TFieldPtr*)ex.pValue;
            FPI.GrabFrom(FP);
          }
          //FPI
          auto*pContext=&branch[2];
          OutDevice::TCmdHeadVisitor Head;
          TOutDevEx::TCmdConverter Conv;
          Conv.Init(pEnv);
          auto&arr=OD.branch;
          for(int i=2;i+1<arr.size();i++)
          {
            auto&ex=arr[i+1];
            auto&ax=arr[i+0];
            auto*pCmd=ax.pCmd;
            Conv.Context=ax;
            pCmd->Use(Conv);
            Branch.Items.push_back(std::move(Conv.pCmd));
            Head.Context=ax;
            pCmd->Use(Head);
          }
          Branch.Code=std::move(Head.out);
          Branch.Root=FPI;
        }
        OD.pop();
      }while(false);
    }
  public:
    void OnVar(OutDevice&OD,LineField&Field){if(!pTools->IsOnDown())return;BranchCode(OD);}
    void OnType(OutDevice&OD,LineField&Field){if(!pTools->IsOnDown())return;MicroCode(OD);}
    void OnValue(OutDevice&OD,LineField&Field)
    {
      auto&top=OD.branch.top;
      OnValueAll(OD,Field);
      if(SelectBranch||DestBranch)
      {
        BranchCode(OD);
      }
      do
      {
        auto*pKB=pTools->KeyControl.Keyboard.get();
        auto&Down=pKB->Down;
        bool flag=false;
        flag=flag||pKB->News;
        flag=flag||Down[VK_BACK];
        flag=flag||Down[VK_DELETE];
        if(!flag)break;
        if("string"!=*Field.pType)break;
        auto&value=*(string*)top.pValue;
        if(Down[VK_BACK]){Down[VK_BACK]=false;if(!value.empty())value.resize(value.size()-1);break;}
        if(Down[VK_DELETE]){Down[VK_DELETE]=false;value="";break;}
        if(pKB->News)
        {
          value+=CToS(pKB->LastChar);
          pKB->News=false;
        }
      }while(0);
      if(!pTools->IsOnDown())return;
      if("bool"==*Field.pType)
      {
        auto&value=*(bool*)top.pValue;
        value=!value;
      }
      if("int"==*Field.pType)
      {
        auto&value=*(int*)top.pValue;
        if(pTools->IsLDown())value+=+1;
        if(pTools->IsRDown())value+=-1;
      }
      if("real"==*Field.pType)
      {
        auto&value=*(real*)top.pValue;
        if(pTools->IsLDown())value+=+1.0;
        if(pTools->IsRDown())value+=-1.0;
      }
      if("float"==*Field.pType)
      {
        auto&value=*(float*)top.pValue;
        if(pTools->IsLDown())value+=+1.0;
        if(pTools->IsRDown())value+=-1.0;
      }
    }
    void OnSys(OutDevice&OD,LineField&Field)
    {
      auto&top=OD.branch.top;
      auto&Down=pTools->KeyControl.Keyboard.get()->Down;
      OnSysAll(OD,Field);
      if(SelectBranch)
      {
        BranchCode(OD);
      }
    }
  public:
    struct KeyTools_WeakPtrToField
    {
      bool Passed;
      KeyTools_WeakPtrToField():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;
        if(!CB.pTools->IsOnLDown())return;          
        auto*p=TTypeWeakPtr::UberCast(top.pType);
        if(p)
        {
          Passed=true;
          CB.DestBranch=true;
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        TRawPtr raw_ptr=QTD.DestBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto&value=*(TWeakPtr<IEsoteric>*)pValue;
          // under construction
          return;
          // under designed
          vector<TBranch> WeakPtrs;
          WeakPtrs.push_back(std::move(CB.Branch));
          auto&arr=WeakPtrs;
          for(int i=0;i<arr.size();i++)
          {
            auto&ex=arr[i];
            auto raw_ptr=ex.GetRawPtr();
            if(!raw_ptr.IsValid())continue;
            auto*pValue=raw_ptr.pValue;
            auto*pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
            if(!pType||!pValue)continue;
            //nothing?
          }
          //value=nullptr;
        }
      }
    };
    struct KeyTools_SelfPtrConnect
    {
      bool Passed;
      KeyTools_SelfPtrConnect():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;
        if(!CB.pTools->IsOnDown())return;          
        auto*p=TTypeSelfPtr::UberCast(top.pType);
        if(p)
        {
          Passed=true;
          CB.SelectBranch=true;
        }
      }
      typedef TVoidPtr::TRawPtr TRawPtr;
      static TWeakPtr<IEsoteric>*get_weakptr(const TRawPtr&raw_ptr,TTypeWeakPtr*&pType)
      {
        auto*pValue=raw_ptr.pValue;
        pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          return (TWeakPtr<IEsoteric>*)pValue;
        }
        return nullptr;
      }
      static TSelfPtr<IEsoteric>*get_selfptr(const TRawPtr&raw_ptr,TTypeSelfPtr*&pType)
      {
        auto*pValue=raw_ptr.pValue;
        pType=TTypeSelfPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          return (TSelfPtr<IEsoteric>*)pValue;
        }
        return nullptr;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        auto get_source=[&](TTypeSelfPtr*&pType)->TSelfPtr<IEsoteric>*
        {
          TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
          return get_selfptr(raw_ptr,pType);
        };
        auto get_dest=[&](TTypeWeakPtr*&pType)->TWeakPtr<IEsoteric>*
        {
          TRawPtr raw_ptr=QTD.DestBranch.GetRawPtr();
          return get_weakptr(raw_ptr,pType);
        };
        TTypeWeakPtr*pDestType=nullptr;
        TTypeSelfPtr*pSourceType=nullptr;
        auto*pDest=get_dest(pDestType);
        auto*pSource=get_source(pSourceType);
        if(!pDest||!pSource||!pDestType||!pSourceType)return;
        auto*pDestElemType=pDestType->ElementType.get();
        auto*pSourceElemType=pSourceType->ElementType.get();
        if(!pDestElemType||!pSourceElemType)return;
        bool flag=pSourceElemType->IsBasedOn(pDestElemType);
        if(!flag)return;
        auto&dest=*pDest;
        auto&source=*pSource;
        dest=nullptr;
        dest.P=&source.P;
        //pDest->oper_set
        //(*pDest)
      }
    };
    struct KeyTools_WeakPtrClear
    {
      bool Passed;
      KeyTools_WeakPtrClear():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;
        if(Down[VK_DELETE])
        {
          auto*p=TTypeWeakPtr::UberCast(top.pType);
          if(p)
          {
            Down[VK_DELETE]=false;
            Passed=true;
            CB.SelectBranch=true;
          }
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto&value=*(TWeakPtr<IEsoteric>*)pValue;
          value=nullptr;
        }
      }
    };
    struct KeyTools_WeakPtrConnect
    {
      bool Passed;
      KeyTools_WeakPtrConnect():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;
        if(!CB.pTools->IsOnRDown())return;          
        auto*p=TTypeWeakPtr::UberCast(top.pType);
        if(p)
        {
          Passed=true;
          CB.SelectBranch=true;
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        auto get_weakptr=KeyTools_SelfPtrConnect::get_weakptr;
        auto get_source=[&](TTypeWeakPtr*&pType)->TWeakPtr<IEsoteric>*
        {
          TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
          return get_weakptr(raw_ptr,pType);
        };
        auto get_dest=[&](TTypeWeakPtr*&pType)->TWeakPtr<IEsoteric>*
        {
          TRawPtr raw_ptr=QTD.DestBranch.GetRawPtr();
          return get_weakptr(raw_ptr,pType);
        };
        TTypeWeakPtr*pDestType=nullptr;
        TTypeWeakPtr*pSourceType=nullptr;
        auto*pDest=get_dest(pDestType);
        auto*pSource=get_source(pSourceType);
        if(!pDest||!pSource||!pDestType||!pSourceType)return;
        auto*pDestElemType=pDestType->ElementType.get();
        auto*pSourceElemType=pSourceType->ElementType.get();
        if(!pDestElemType||!pSourceElemType)return;
        bool flag=pSourceElemType->IsBasedOn(pDestElemType);
        if(!flag)return;
        auto&dest=*pDest;
        auto&source=*pSource;
        dest=nullptr;
        dest.P=source.P.ptr;
        //pDest->oper_set
        //(*pDest)
      }
    };
  public:
    struct KeyTools_VectorClear
    {
      bool Passed;
      KeyTools_VectorClear():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;
        if(Down[VK_DELETE])
        {
          auto*p=TTypeVector::UberCast(top.pType);
          if(p)
          {
            Down[VK_DELETE]=false;
            Passed=true;
            CB.SelectBranch=true;
          }
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeVector::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto*pVecAPI=pType->VecAPI.get();
          int Count=pVecAPI->GetCount(pValue);
          pVecAPI->SetCount(pValue,0);
        }
      }
    };
    struct KeyTools_VectorIncDec
    {
      int dVecCount;
      KeyTools_VectorIncDec():dVecCount(0){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;     
        if(!Down[VK_SUBTRACT]&&!Down[VK_ADD])return;
        auto*p=TTypeVector::UberCast(top.pType);
        if(!p)return;
        dVecCount=(Down[VK_SUBTRACT]?-1:0)+(Down[VK_ADD]?+1:0);
        Down[VK_SUBTRACT]=false;
        Down[VK_ADD]=false;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!dVecCount)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeVector::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto*pVecAPI=pType->VecAPI.get();
          int Count=pVecAPI->GetCount(pValue);
          Count+=dVecCount;
          if(Count<0)Count=0;
          pVecAPI->SetCount(pValue,Count);
        }
      }
    };
    struct KeyTools_FieldPtrClear
    {
      bool Passed;
      KeyTools_FieldPtrClear():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;     
        if(!Down[VK_DELETE])return;
        auto*p=TTypeFieldPtr::UberCast(top.pType);
        if(!p)return;
        Down[VK_DELETE]=false;
        Passed=true;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeFieldPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto&value=*(TFieldPtr*)pValue;
          value.off();
        }
      }
    };
    struct KeyTools_AutoPtrClear
    {
      bool Passed;
      KeyTools_AutoPtrClear():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;     
        if(!Down[VK_DELETE])return;
        auto*p=TTypeAutoPtr::UberCast(top.pType);
        if(!p)return;
        Down[VK_DELETE]=false;
        Passed=true;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeAutoPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto&value=*(TAutoPtr<void>*)pValue;
          value=nullptr;
        }
      }
    };
    struct KeyTools_AutoPtrSelectBase
    {
      bool Passed;
      KeyTools_AutoPtrSelectBase():Passed(false){};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.pTools->KeyControl.Keyboard.get()->Down;     
        if(!CB.pTools->IsDown())return;
        auto*p=TTypeAutoPtr::UberCast(top.pType);
        if(!p)return;
        Passed=true;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if(!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeAutoPtr::UberCast(raw_ptr.pType);
        if(pValue&&pType)
        {
          auto&value=*(TAutoPtr<void>*)pValue;
          CB.SelectBranch=true;
        }
      }
    };
  public:
    void OnValueAll(OutDevice&OD,LineField&Field)
    {
      #define LIST(F)F(VectorClear)F(WeakPtrToField)F(SelfPtrConnect)F(WeakPtrClear)F(WeakPtrConnect)
      #define F(NAME)NAME.Before(*this,OD);
      LIST(F)
      #undef F
      #undef LIST
    }
    void OnSysAll(OutDevice&OD,LineField&Field)
    {
      #define LIST(F)F(VectorClear)F(VectorIncDec)F(FieldPtrClear)F(AutoPtrClear)F(AutoPtrSelectBase)
      #define F(NAME)NAME.Before(*this,OD);
      LIST(F)
      #undef F
      #undef LIST
    }
  public:
    //--==>>begin
    #define DEF_PRO_LIST(F)\
      F(VectorClear)F(VectorIncDec)F(FieldPtrClear)\
      F(AutoPtrClear)F(AutoPtrSelectBase)F(WeakPtrToField)\
      F(SelfPtrConnect)F(WeakPtrClear)F(WeakPtrConnect)
    //<<==--begin
    #define F(NAME)KeyTools_##NAME NAME;
    DEF_PRO_LIST(F)
    #undef F
    //
    void CallAfterAllKeyTools(QapTreeDebugger&QTD)
    {
      #define F(NAME)NAME.After(QTD,*this);
      DEF_PRO_LIST(F)
      #undef F
    }
    //--==>>end
    #undef DEF_PRO_LIST
    //<<==--end
  };
public:
  typedef TVoidPtr::TRawPtr TRawPtr;
  TBranch*GetSelectBranchId()
  {
    if(SelectBranchId<0)return nullptr;
    if(SelectBranchId>=Branches.size())return nullptr;
    auto&ex=Branches[SelectBranchId];
    return &ex;
  }
public:
  static int get_field_index_in_type(TType*pType,const string&field)
  {
    auto*p=Sys$$<SelfClass>::metatype::UberCast(pType);
    if(!p)return -1;
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      const auto&ex=arr[i];
      if(ex.Name==field)
      {
        QapAssert(TTypeFieldPtr::UberCast(ex.Type.get()));
        return i;
      }
    }
    return -1;
  }
  static int get_Select_field_index_in_QapTreeDebugger(TWeakPtr<TType>&pTypeThis)
  {
    static int field_select_index=-1;
    if(field_select_index<0)
    {
      auto*p=pTypeThis.get();
      if(!p)
      {
        QapAssert(p);
        return -1;
      }
      field_select_index=get_field_index_in_type(p,"Select");
    }
    return field_select_index;
  }
  void Update(IEnv&Env)
  {
    if(!FontObject||!Program||!Tools)return;
    auto&program=*Program.get();
    QapFont&font=FontObject->Font;
    QapKeyboard&Keyboard=program.GetKeyBoard();
    QapClock Clock;
    Clock.Start();
    if(!pQapTreeDebugger)
    {
      auto*p=Sys$$<SelfClass>::GetRTTI(Env.Env);
      pQapTreeDebugger=p;
    }
    if(!pTBranch)
    {
      auto*p=Sys$$<TBranch>::GetRTTI(Env.Env);
      pTBranch=p;
    }
    if(true)
    {
      zD-=64*Sign(program.WindowGetzDelta());
      vec2i pos=program.WindowGetMousePos();
      mpos=pos;
    }
    if(true)
    {
      OnDownSelect.UpdateEx();
    }
    if(Keyboard.Down[VK_F10])
    {
      Select.off();
      Select.ConnectEx(Env.Env,*this);
      Keyboard.Down[VK_F10]=false;
    }
    if(Keyboard.Down[VK_F11])
    {
      Select.off();
      auto*ex=Program.get();
      Select.ConnectEx(Env.Env,*ex);
      Keyboard.Down[VK_F11]=false;
    }
    for(int i='0';i<='9';i++)
    {
      auto&flag=Keyboard.Down[i];
      if(flag)
      {
        auto&arr=pages.Items;
        int id=i-'0';
        if(id>=arr.size())continue;
        auto&ex=arr[id];
        std::swap(Select,ex.Select);
        std::swap(MaxDepth,ex.MaxDepth);
        std::swap(pos,ex.pos);
        std::swap(zD,ex.zD);
        flag=false;
      }
    }
    if(NeedClearPages)
    {
      pages.Items.clear();
      NeedClearPages=false;
    }
    if(NeedClearBranches)
    {
      Branches.clear();
      NeedClearBranches=false;
    }
    if(AutoUpdateBranchesHead)
    {
      auto&arr=Branches;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.UpdateCode();
      }
    }
    if(Keyboard.Down[VK_F3])
    {
      Keyboard.Down[VK_F3]=false;
      SelectBranchEnabled=!SelectBranchEnabled;
    }
    if(Keyboard.Down[VK_F1])if(SelectBranchEnabled&&!Branches.empty())
    {
      Keyboard.Down[VK_F1]=false;
      int count=Branches.size();
      auto&id=SelectBranchId;
      id--;
      if(id<0)id=count-(-id-(-id/count)*count);
      id=id%count;
    }
    if(Keyboard.Down[VK_F2])if(SelectBranchEnabled&&!Branches.empty())
    {
      Keyboard.Down[VK_F2]=false;
      int count=Branches.size();
      auto&id=SelectBranchId;
      id++;
      if(id<0)id=count-(-id-(-id/count)*count);
      id=id%count;
    }
    if(Keyboard.Down[VK_F7])
    {
      program.WindowFullScreen(true);
      Keyboard.Down[VK_F7]=false;
      Select.off();
    }
    if(Keyboard.Down[VK_F6])
    {
      Keyboard.Down[VK_F6]=false;
      MaxDepth=6;
      Select.off();
      auto*ex=Program.get();
      Select.ConnectEx(Env.Env,*ex);
    }
    if(Keyboard.Down[VK_HOME])
    {
      const int Steep_zD=64;
      Keyboard.Down[VK_HOME]=false;
      zD=0;
    }
    if(Keyboard.Down[VK_END])
    {
      const int Steep_zD=64;
      Keyboard.Down[VK_END]=false;
      int h=(lines.size()+3)*font.Info.Coords[0].y;
      h-=program.WindowGetClientSize().y;
      zD=(h/Steep_zD)*Steep_zD;
    }
    if(Keyboard.Down[VK_NEXT])
    {
      const int Steep_zD=64;
      Keyboard.Down[VK_NEXT]=false;
      int dy=font.Info.Coords[0].y;
      int h=program.WindowGetClientSize().y-3*dy;
      zD+=h;
    }
    if(Keyboard.Down[VK_PRIOR])
    {
      const int Steep_zD=64;
      Keyboard.Down[VK_PRIOR]=false;
      int dy=font.Info.Coords[0].y;
      int h=program.WindowGetClientSize().y-3*dy;
      zD-=h;
    }
    static bool enabled_auto_scroll_bounce=true;
    if(enabled_auto_scroll_bounce&&!lines.empty())
    {
      const int Steep_zD=64;
      int dy=font.Info.Coords[0].y;
      int pwcsy=program.WindowGetClientSize().y;
      int h=pwcsy-3*dy;
      int min_h=-h;
      int max_h=(lines.size()+3)*dy;
      zD=Clamp<int>(zD,min_h,max_h);
    }
    if(NeedCallWindowMode)
    {
      NeedCallWindowMode=false;
      auto*ex=Program.get();
      auto&q=ex->WindowGetQuad();      
      q.x=int(-4);
      q.y=int(0);
      q.w=int(687);
      q.h=int(728);
      ex->WindowUpdateMode();
    }
    for(int i=0;i<3;i++)if(!lines.empty())lines.pop_back();
    if(!AutoUpdate)
    {
      if(Keyboard.Down[VK_F12])
      {
        AutoUpdate=true;
        Keyboard.Down[VK_F12]=false;
      }
    }else{
      TCallBack CB;
      CB.pTools=Tools.get();
      CB.pEnv=&Env.Env;
      OutDevice::TDevContext DevContext={
        font,mpos,pos+vec2d(0,zD),CB,MaxDepth,
        program.WindowGetClientSize().y,
        InScreenOptimization,
        SkipCommaInVector,
      };
      OutDevice OD(DevContext);
      OD.lines.reserve(300);
      OD.branch.items.reserve(32);
      auto&top=OD.branch.top;
      if(SelectBranchEnabled)
      {
        string end_line;
        auto*pBranch=GetSelectBranchId();
        if(pBranch||true)
        {
          OutDevice::str_line head_line;
          auto add_text=[&OD,&head_line,&font](const string&text)->string
          {
            OD.AddText(text);
            return text;
          };
          string Code;
          auto add_code=[&]()->string
          {
            if(pBranch&&pBranch->Root)
            {
              TOutDevEx::TContext Context;
              Context.pType=pBranch->Root.getType();
              Context.pValue=pBranch->Root.getValue();
              TOutDevEx::TCmdHeadVisitor Head;
              Head.pContext=&Context;
              auto&tools=*Tools.get();
              QapTreeDebugger::TBranch::TMeCallBack MCB(Head,*pBranch,tools);
              OD.AddWithECB(MCB);
            }
            return !pBranch?"pBranch = nullptr_t(nullptr)":"Root = nullptr_t(nullptr)";
          };
          string inner_code=pBranch?IToS(SelectBranchId+1)+" of "+IToS(Branches.size()):"none";
          string a=add_text("^3-----^2{ ^0Branch["+inner_code+"] ^2}^3-----");
          string b=add_code();
          string c=add_text("^3"+[&a](int c)->string{string s;s.resize(c);for(int i=0;i<c;i++){s[i]='-';}return s;}(QapQ3Text::ToNormal(a).size()));
          end_line=c;
          if(pBranch)OD.DevContext.MaxDepth=MaxDepth+pBranch->Items.size();
        }
        TBranch::TOutDevBuff buff(OD);
        bool flag=pBranch&&buff.grab(Env.Env,pBranch,pTBranch.get());
        if(flag)
        {
          buff.push();
          TProtoToolsEx ProtoTools(OD,top.pValue);
          top.pType->Use(ProtoTools);
          buff.pop();
        }else{
          OD.AddText("error");
        }
        OD.AddText(end_line);
      }else{
        //
        if(!Select){
          lines.clear();
          return;
        };
        //
        int field_select_index=get_Select_field_index_in_QapTreeDebugger(pQapTreeDebugger);
        if(field_select_index<0)AutoUpdate=false;
        //
        top.pValue=this;
        top.pType=pQapTreeDebugger.get();
        //
        OutDevice::TMemberID tmp(field_select_index);
        OD.push(&tmp);
        TProtoToolsEx ProtoTools(OD,top.pValue);
        top.pType->Use(ProtoTools);
        OD.pop();
      }
      lines=std::move(OD.lines);
      if(CB.UseInfo)
      {
        auto&Info=CB.Info;
        TPage page;
        page.pos=pos;
        page.Select=std::move(Select);
        page.zD=zD;
        page.MaxDepth=MaxDepth;
        Info.SetToField(Select);
        Info.pType=nullptr;
        Info.pValue=nullptr;
        Info.pFieldType=nullptr; 
        Info.Offset=-1;
        pages.Items.push_back(std::move(page));
      }
      if(CB.Branch.Root)do
      {
        auto*pBranch=GetSelectBranchId();
        auto&tools=*Tools.get();
        if(CB.SelectBranch||CB.DestBranch)
        {
          QapAssert(CB.SelectBranch!=CB.DestBranch);
          if(CB.DestBranch)DestBranch.Branch=std::move(CB.Branch);
          if(CB.SelectBranch)SelectBranch.Branch=std::move(CB.Branch);
          if(!OnDownSelect.Selector)break;
          auto*pSelector=OnDownSelect.Selector.get();
          pSelector->change_base_ex(SelectBranch);
          //--==>>CallAfterAllKeyTools
          CB.CallAfterAllKeyTools(*this);
          //<<==--CallAfterAllKeyTools
          break;
        }
        if(tools.IsOnLDown())
        {
          Branches.push_back(std::move(CB.Branch));
        }
        if(tools.IsOnRDown())
        {
          if(pBranch)
          {
            (*pBranch)=std::move(CB.Branch);
          }else{
            Branches.push_back(std::move(CB.Branch));
          }
        }
        break;
      }while(false);
    }
    Clock.Stop();
    {
      int count=0;
      for(int i=0;i<lines.size();i++)
      {
        count+=lines[i].text.size();
      }
      str_line tmp={0,"=====[bytes:"+IToS(count)+"]====="};
      lines.push_back(tmp);
    }
    {
      str_line tmp={0,"=====[lines:"+IToS(lines.size())+"]====="};
      lines.push_back(tmp);
    }
    {
      str_line tmp={0,"=====[update:"+FToS(Clock.MS())+"]====="};
      lines.push_back(tmp);
    }
    pages.Update();
    branches_update();
  }
  void branches_update()
  {
    auto&arr=Branches;
    int last=0;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.NeedRemove)continue;
      if(last!=i)
      {
        auto&ax=arr[last];
        ax=std::move(ex);
      }
      last++;
    }
    if(last==arr.size())return;
    arr.resize(last);
  }
};

#include "GUI_Panel.inl"

class MeUnitWithQapTreeDebugger:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnitWithQapTreeDebugger)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>MeUnitWithQapTreeDebugger
#include "QapGenStruct.inl"
//<<<<<+=====MeUnitWithQapTreeDebugger
public:
  void OnBuild(TBuildContext&Context)
  {
    auto&Env=Context.Env;
    auto&Qrp=Context.Qrp;
    auto&PluginMan=Context.PluginMan;
    //BT
    auto*pD3D9Prog=Qrp.Program.get();
    auto&UserCode=pD3D9Prog->UserCode;
    TProgramNode::TArray NodeArr=std::move(UserCode.Programs);
    //BT
    auto*pFontObj=Qrp.ResList.AddItem<QapFontObject>(Env);
    auto*pNode=Qrp.Scene.AddItem<TRenderNodeEx>(Env);
    auto*pDevTools=UserCode.AddItem<QapTreeDebugger::DevTools>(Env);
    auto*pTreeDebugger=pNode->AddItem<QapTreeDebugger>(Env);
    //BT
    pDevTools->SetToDef(*pD3D9Prog);
    //BT
    pFontObj->SetToDef();
    pFontObj->Run(Env,&pD3D9Prog->D9Dev);
    //BT
    pTreeDebugger->FontObject=pFontObj;
    pTreeDebugger->Tools=pDevTools;
    pTreeDebugger->Select.ConnectEx(Env,Qrp);
    pTreeDebugger->Program=pD3D9Prog;
    //BT
    MeUnit20121009::OnBuildEx(Context,pTreeDebugger);
    //BT
    QapToolsVectorEx(UserCode.Programs)+=std::move(NodeArr);
    //BT
  }
  void Update(IEnvRTTI&Env)
  {
    //nothing
  }
};

class QapStarter:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapStarter)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,AppStarter,Starter,DEF,$,$)\
ADDEND()
//=====+>>>>>QapStarter
#include "QapGenStruct.inl"
//<<<<<+=====QapStarter
public:
  static void RegAll(IEnvRTTI&Env)
  {
    #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
    #define LIST(F)F(eWinProgram)F(QapProgramD3D9)\
      F(QapPluginMan)F(QapRenderProgram)\
      F(QapTreeDebugger)\
      F(KeyVisorProgram)F(TProgramQuit)\
      F(TRenderNode)F(TOutDevEx)\
      F(MeUnitWithQapTreeDebugger)\
      F(TGUI_Content_Q3Text)F(TGUI_ContentHolder)F(TGUI_Panel)F(TGUI_PanelOwner)\
      F(QapTextSelectorV3)F(QapTextSelectorV4)F(QapTextSelectorV4OnDown)
    //===+>>>LIST
    LIST(F);
    //<<<+===LIST
    #undef LIST
    #undef F
  }
  void Update(IEnv&Env)
  {
    QapAssert(!Env.Starter);
    Env.Starter=&Starter;
    RegAll(Env.Env);
    Starter.Impl.build<TAppStarterImpl>(Env.Env);
    Starter.Load(Env);
    if(!Starter.Root)
    {
      QapWinProgram::CreateDefaultProgram<QapProgramD3D9>(Env,Starter.Root);
    }
    Starter.Update(Env);
  }
};

//<<<<<=====QapProgramD3D9
#endif //DEF_BUILD_MACRO//
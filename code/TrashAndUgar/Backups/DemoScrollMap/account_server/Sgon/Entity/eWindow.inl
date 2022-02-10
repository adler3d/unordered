#ifdef DEF_BUILD_MACRO
  #include "../Macro/eWindow.h"
#else
//=====>>>>>eWindow

template<class TYPE>
struct CrutchHolder{
  TYPE&src;
  TYPE buff;
  CrutchHolder(TYPE&src):src(src),buff(src){}
  ~CrutchHolder(){src=buff;}
};
/*
template<class TYPE>
struct RawPointer{
  TYPE* ptr;
  RawPointer(TYPE*ptr):ptr(ptr){}
  operator TYPE*&(){return ptr;}
};
*/

class AppStarter;

class TAppStarterImpl:public IAppStarterImpl{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TAppStarterImpl)PARENT(IAppStarterImpl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TAppStarterImpl
#include "QapGenStruct.inl"
//<<<<<+=====TAppStarterImpl
public:
  void Save(IEnv&Env)
  {
    auto&Root=Env.Starter->Root;
    auto&FileName=Env.Starter->FileName;
    if(!Root)return;
    if(GetFileName(FileName)!=FileName)return;
    QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceBin(TQapFileStream(FileName,false)));
    if(!IsKeyDown(VK_LSHIFT))return;
    QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceProto(TQapFileStream(ChangeFileExt(FileName,".h"),false)));
    //ToolsYED tools;
    //QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceYed(tools));
    //tools.SetLQ();
    //tools.load();
    //tools.gen();
    //tools.output.filename="YedLeaf.graphml";
    //tools.save();
  }
  void Load(IEnv&Env)
  {
    auto&Root=Env.Starter->Root;
    auto&FileName=Env.Starter->FileName;
    if(Root)return;
    QapUberFullLoader(Env,QapRawUberObject(Root),UberLoadDeviceBin(TQapFileStream(FileName,true)));
  }
};

class TProgramNodeEx:public TProgramNode{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramNodeEx)PARENT(TProgramNode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,AutoDisable,SET,true,$)\
ADDEND()
//=====+>>>>>TProgramNodeEx
#include "QapGenStruct.inl"
//<<<<<+=====TProgramNodeEx
public:
  static void SysHasSelf();
public:
  void Update(IEnv&Env)
  {
    if(!Enabled)return;
    if(AutoDisable)Enabled=false;
    ForceUpdate(Env);
  }
};

class ProgramLoop:public ISubProgram{
public:
#define DEF_PRO_NESTED(F)F(DoStart)F(DoStop)F(Counter)F(Pass)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ProgramLoop)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TAutoPtr<ISubProgram>,Body,DEF,$,$)\
ADDVAR(bool,Condition,SET,true,$)\
ADDEND()
//=====+>>>>>ProgramLoop
#include "QapGenStruct.inl"
//<<<<<+=====ProgramLoop
public:
  static void SysHasSelf();
public:
  void Update(IEnv&Env)
  {
    while(Condition)
    {
      if(!Body)break;
      auto*body=Body.get();
      body->Update(Env);
    }
  }
public:
  template<class TYPE>
  TYPE*CreateBody(IEnv&Env)
  {
    return Env.Create<TYPE>(Body);
  }
public:
  class DoStart:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoStart)PARENT(ISubProgram)OWNER(ProgramLoop)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(TWeakPtr<ProgramLoop>,Loop,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoStart
    #include "QapGenStruct.inl"
    //<<<<<+=====DoStart
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env){
      if(!Loop)return;
      auto*loop=Loop.get();
      loop->Condition=true;
    }
  };
  class DoStop:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoStop)PARENT(ISubProgram)OWNER(ProgramLoop)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(TWeakPtr<ProgramLoop>,Loop,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoStop
    #include "QapGenStruct.inl"
    //<<<<<+=====DoStop
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env){
      if(!Loop)return;
      auto*loop=Loop.get();
      loop->Condition=false;
    }
  };
  class Counter:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Counter)PARENT(ISubProgram)OWNER(ProgramLoop)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(int,value,SET,0,$)\
    ADDEND()
    //=====+>>>>>Counter
    #include "QapGenStruct.inl"
    //<<<<<+=====Counter
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env){value++;}
  };
  class Pass:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Pass)PARENT(ISubProgram)OWNER(ProgramLoop)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(int,PassCount,SET,0,$)\
    ADDVAR(TWeakPtr<ProgramLoop>,Loop,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Pass
    #include "QapGenStruct.inl"
    //<<<<<+=====Pass
  public:
    static void SysHasSelf();
  public:
    void Update(IEnv&Env){
      if(!Loop)return;
      auto*loop=Loop.get();
      loop->Condition=bool(PassCount>0);
      if(PassCount>0)PassCount--;
    }
  };
};

class ProgramSleep:public ISubProgram{
public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ProgramSleep)PARENT(ISubProgram)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
  ADDVAR(int,MS,SET,10,$)\
  ADDEND()
  //=====+>>>>>ProgramSleep
  #include "QapGenStruct.inl"
  //<<<<<+=====ProgramSleep
public:
  static void SysHasSelf();
public:
  void Update(IEnv&Env)
  {
    Sleep(MS);
  }
};

class eWindow
{
public:
  class TForm{
  public:
    class WndClassPair{
    public:
      WNDPROC Proc;
      HWND hWnd;
      int ID;
      bool Used;
    public:
      WndClassPair():Proc(nullptr),hWnd(nullptr),ID(0),Used(false){}
      WndClassPair(WNDPROC Proc,HWND hWnd,int ID,bool Used):Proc(Proc),hWnd(hWnd),ID(ID),Used(Used){}
    public:
      void Init(TForm*Owner){
        WndProcHeap::Get().Load(*this);
        QapAssert(!Used);
        QapAssert(!hWnd);
        Used=true;
        Proc((HWND)Owner,WMU_INIT,0,0);
      }
      void Free(TForm*Owner){
        QapAssert(!hWnd);
        QapAssert(Used);
        Used=false;
        Proc((HWND)Owner,WMU_FREE,0,0);
        WndProcHeap::Get().Save(*this);
      }
    };
    class WndProcHeap{
    public:
      vector<WndClassPair> Arr;
      void Load(WndClassPair&WinPair)
      {
        QapAssert(!Arr.empty());
        WndClassPair&WCP=Arr.back();
        WinPair=std::move(WCP);
        Arr.pop_back();
      }
      void Save(WndClassPair&WinPair)
      {
        Arr.push_back(std::move(WinPair));
      }
      static WndProcHeap&Get()
      {
        static WndProcHeap Heap;
        static bool flag=false;
        if(!flag)
        {
          vector<WndClassPair>&Arr=Heap.Arr;
          #define F(N){WndClassPair tmp(WndProc<N>,nullptr,N,false);Arr.push_back(tmp);}
            F(0);F(1);F(2);F(3);F(4);F(5);F(6);F(7);F(8);F(9);
            F(10);F(11);F(12);F(13);F(14);F(15);F(16);F(17);F(18);F(19);
            F(20);F(21);F(22);F(23);F(24);F(25);F(26);F(27);F(28);F(29);
          #undef F
          flag=true;
        }
        return Heap;
      }
    };
  public:
    #define DEF_PRO_MANUAL_MOVE()
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TForm)OWNER(eWindow)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(eWindow*,Owner,SYS,nullptr,$)\
    ADDVAR(ATOM,ClassAtom,SYS,0,$)\
    ADDVAR(string,ClassName,SYS,"",$)\
    ADDVAR(WndClassPair,WinPair,SYS,WndClassPair(),$)\
    ADDEND()
    //=====+>>>>>TForm
    #include "QapGenStruct.inl"
    //<<<<<+=====TForm
  public:
    ~TForm()
    {
      if(WinPair.hWnd)Free();
    }
    void operator=(eWindow*Owner){
      this->Owner=Owner;
    }
  public:
    void Init()
    {
      WinPair.hWnd=nullptr;
      auto tmp=CreateWindowA(
        (LPCSTR)ClassAtom,
        "Unnamed",
        WS_OVERLAPPEDWINDOW,
        0, 0, 320, 240, NULL, NULL, GlobalEnv::Get().hInstance, NULL
      );
      WinPair.hWnd=tmp;
      QapAssert(tmp);
      //WinPair
    }
    void Free()
    {
      QapAssert(DestroyWindow(WinPair.hWnd));
      WinPair.hWnd=nullptr;
    }
  public:
    void Reg()
    {
      WinPair.Init(this);
      ClassName="QapForm_"+IToS(WinPair.ID);
      WNDCLASSEX wcx;
      ZeroMemory(&wcx,sizeof(wcx));
      wcx.cbSize        = sizeof(wcx);
      wcx.hInstance     = GlobalEnv::Get().hInstance;
      wcx.hIcon         = LoadIcon(0,IDI_ASTERISK);
      wcx.hIconSm       = wcx.hIcon;
      wcx.hCursor       = LoadCursor(0,IDC_ARROW);
      wcx.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
      wcx.style         = 0;
      wcx.lpfnWndProc   = WinPair.Proc;
      wcx.lpszClassName = ClassName.c_str();
      ClassAtom=RegisterClassExA(&wcx);
    }
    bool UnReg()
    {
      WinPair.Free(this);
      bool flag=UnregisterClassA((LPCSTR)ClassAtom,GlobalEnv::Get().hInstance);
      ClassAtom=0;
      ClassName.clear();
      return flag;
    }
  public:
    static const UINT WMU_INIT=WM_USER+1234;
    static const UINT WMU_FREE=WM_USER+4321;
  public:
    template<int Index>
    static LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
    {
      static TForm*pForm=nullptr;
      if(!pForm){
        QapAssert(WMU_INIT==msg);
        pForm=(TForm*)hWnd;
        return 0;
      }
      if(WMU_FREE==msg)
      {
        QapAssert(pForm);
        QapAssert(pForm->Owner);
        QapAssert(hWnd==((HWND)pForm));
        pForm=nullptr;
        return 0;
      }
      QapAssert(pForm);
      QapAssert(pForm->Owner);
      if(WM_CREATE==msg){
        int i=0;
      }
      if(WM_DESTROY==msg){
        int i=0;
      }
      if(WM_GETMINMAXINFO==msg)
      {
        int i=0;
      }
      if(WM_NCCREATE==msg)
      {
        int i=0;
      }
      if(WM_NCDESTROY==msg)
      {
        int i=0;
      }
      long UD=GetWindowLongA(hWnd,GWL_USERDATA);
      if(!UD){
        SetWindowLong(hWnd,GWL_USERDATA,(long)pForm);
      }else{
        long pF=(long)pForm;
        QapAssert(pF==UD);
      }
      if(msg==WM_WINDOWPOSCHANGING)return 0;
      QapClock Clock;
      Clock.Start();
      static bool joint=false;
      //if(msg==274)return 0;
      //static bool ignore
      //bool flag=false||joint;
      //if(msg==274)if(wParam=61458)
      //{
      //  joint=true;//flag=true;
      //  if(joint)flag=false;
      //}
      //if(flag){return 1;}
      auto result=pForm->Owner->WndProc(hWnd,msg,wParam,lParam);
      Clock.Stop();
      real ms=Clock.MS();
      if(ms>400)
      {// 274 61458
        int skjhdklasd=SC_SIZE;
      }
      return result;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(TForm)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eWindow)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Caption,SET,"eWindow",$)\
ADDVAR(bool,OnTop,SET,false,$)\
ADDVAR(bool,FullScreen,SET,false,$)\
ADDVAR(bool,NeedClose,SET,false,$)\
ADDVAR(bool,Runned,SET,false,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,Maximized,SET,false,$)\
ADDVAR(bool,Minimized,SET,false,$)\
ADDVAR(eQuad,Quad,DEF,$,$)\
ADDVAR(TForm,Form,SET,this,$)\
ADDVAR(QapKeyboard,Keyboard,DEF,$,$)\
ADDVAR(int,zDelta,SET,0,$)\
ADDEND()
//=====+>>>>>eWindow
#include "QapGenStruct.inl"
//<<<<<+=====eWindow
public:
  bool IsWindow(){
    return Form.WinPair.hWnd;
  }
  void Init()
  {
    if(IsWindow())return;
    Form.Reg();
    Form.Init();
    UpdateWnd();
    Runned=true;
  }
  void UpdateWnd()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    SetWindowTextA(hWnd,Caption.c_str());
  }
  void WindowMode()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    TScreenMode SM=GetScreenMode();
    DWORD Style=!FullScreen?WS_OVERLAPPEDWINDOW:WS_OVERLAPPED;
    SetWindowLong(hWnd,GWL_STYLE,Style);
    RECT Rect=Quad.GetWinRect();
    AdjustWindowRect(&Rect,Style,false);
    {
      CrutchHolder<bool> mnd(Minimized);
      CrutchHolder<bool> mxd(Maximized);
      SetWindowPos(hWnd,0,Quad.x,Quad.y,Quad.w,Quad.h,SWP_FRAMECHANGED|SWP_NOOWNERZORDER);
    }
    //MoveWindow(hWnd,X,Y,W,H,true);
    QapAssert(!(Minimized&&Maximized));
    if(Minimized)ShowWindow(hWnd,SW_MINIMIZE);
    if(Maximized)ShowWindow(hWnd,SW_MAXIMIZE);
    ShowWindow(hWnd,Visible?SW_SHOW:SW_HIDE);
    //DoPaint();
  }
  ~eWindow(){
    Free();
  }
  void Free()
  {
    if(!IsWindow())return;
    Runned=false;
    Form.Free();
    Form.UnReg();
    NeedClose=false;
  }
  void Update()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    if(IsKeyDown(VK_SHIFT))
    {
      int igsdklgj=0;
    }
    zDelta=0;
    Keyboard.Sync();
    while(true)
    {
      MSG msg;
      if(!PeekMessageA(&msg,hWnd,0,0,PM_REMOVE))break;
      if(IsKeyDown(VK_SHIFT))
      {
        int igsdklgj=0;
      }
      TranslateMessage(&msg);
      if(IsKeyDown(VK_SHIFT))
      {
        int igsdklgj=0;
      }
      {
        QapClock Clock;
        Clock.Start();
        DispatchMessageA(&msg);
        Clock.Stop();
        real ms=Clock.MS();
        if(ms>100)
        {
          int dsljf=int(ms);
        }
      }
      if(IsKeyDown(VK_SHIFT))
      {
        int igsdklgj=0;
      }
    }
    if(IsKeyDown(VK_SHIFT))
    {
      int igsdklgj=0;
    }
  }
  void Close(){NeedClose=true;}
  void ScanWinPlacement()
  {
    WINDOWPLACEMENT PL;
    GetWindowPlacement(Form.WinPair.hWnd,&PL);
    Quad.SetWinRect(PL.rcNormalPosition);
    QapAssert(Quad.x>-1000);
    //GetWindowRect
  }
  static bool Equal(RECT&a,RECT&b)
  {
    #define F(FIELD)if(a.FIELD!=b.FIELD)return false;
    F(left);
    F(top);
    F(right);
    F(bottom);
    #undef F
    return true;
  }
  LRESULT WndProc(const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam)
  {
    if(msg==WM_WINDOWPOSCHANGED){ScanWinPlacement();}
    if(msg==WM_CLOSE){Close();if(Runned)return 0;}
    if(msg==WM_SHOWWINDOW){Visible=wParam;}
    if(msg==WM_MOVE){ScanWinPlacement();}
    if(msg==WM_SIZING){ScanWinPlacement();}
    if(msg==WM_SIZE)
    {
      do{
        Maximized=false;
        Minimized=false;
        if(wParam==SIZE_MINIMIZED){Minimized=true;break;}
        if(wParam==SIZE_MAXIMIZED){Maximized=true;break;}
      }while(false);
      if(!Maximized&&!Minimized)DoPaint();
    }
    if(msg==WM_PAINT){DoPaint();}
    // ----- ----- ----- ----- -----
    if(msg==WM_SYSKEYDOWN)
    {
      if(wParam==VK_F10){Keyboard.KeyUpdate(VK_F10,true);return 0;}
      if(wParam==VK_MENU){Keyboard.KeyUpdate(VK_MENU,true);return 0;}
    }
    if(msg==WM_SYSKEYUP)
    {
      if(wParam==VK_MENU){Keyboard.KeyUpdate(VK_MENU,false);return 0;}
      if(wParam==VK_F10){Keyboard.KeyUpdate(VK_F10,false);return 0;}
      if(wParam==VK_RETURN)
      {
        FullScreen=!FullScreen;
        WindowMode();
        return 0;
      }  
    }
    
    if(true)do
    {
      bool value=false;
      {
        bool flag=false;
        if(msg==WM_KEYUP){flag=true;value=false;}
        if(msg==WM_KEYDOWN){flag=true;value=true;}
        if(!flag)break;
      }
      auto&KB=Keyboard;
      auto&Down=Keyboard.Down;
      auto KeyUpdate=[&KB,&Down](int key,const bool value)->void
      {
        if(Down[key]!=value)if(value==IsKeyDown(key))
        {
          KB.KeyUpdate(key,value);
        }
      };
      struct TSysKey{int Key,LKey,RKey;} key_array[]={
        {VK_SHIFT,VK_LSHIFT,VK_RSHIFT},
        {VK_CONTROL,VK_LCONTROL,VK_RCONTROL},
        {VK_MENU,VK_LMENU,VK_RMENU}
      };
      for(int i=0;i<lenof(key_array);i++)
      {
        auto&ex=key_array[i];
        if(wParam==ex.Key)
        {
          KeyUpdate(ex.LKey,value);
          KeyUpdate(ex.RKey,value);
        }
      }
    }while(false);
    if(msg==WM_KEYDOWN){
      Keyboard.KeyUpdate(wParam,true);
    }
    if((msg==WM_KEYUP)&&(wParam==VK_SNAPSHOT)){
      Keyboard.KeyUpdate(VK_SNAPSHOT,true);
      Keyboard.KeyUpdate(VK_SNAPSHOT,false);
      return 0;
    }
    if(msg==WM_MOUSEWHEEL){zDelta=GET_WHEEL_DELTA_WPARAM(wParam);return 0;};
    if(msg==WM_KEYUP){Keyboard.KeyUpdate(wParam,false);return 0;}
    if(msg==WM_KEYDOWN){Keyboard.KeyUpdate(wParam,true);return 0;}
    if(msg==WM_LBUTTONUP){Keyboard.KeyUpdate(mbLeft,false);return 0;}
    if(msg==WM_RBUTTONUP){Keyboard.KeyUpdate(mbRight,false);return 0;}
    if(msg==WM_MBUTTONUP){Keyboard.KeyUpdate(mbMiddle,false);return 0;}
    if(msg==WM_LBUTTONDOWN){Keyboard.KeyUpdate(mbLeft,true);return 0;}
    if(msg==WM_RBUTTONDOWN){Keyboard.KeyUpdate(mbRight,true);return 0;}
    if(msg==WM_MBUTTONDOWN){Keyboard.KeyUpdate(mbMiddle,true);return 0;}
    if(msg==WM_CHAR){Keyboard.CharUpdate(wParam);return 0;}
    return DefWindowProcA(hWnd,msg,wParam,lParam);
  }
  void DoPaint()
  {
    HWND hWnd=Form.WinPair.hWnd;
    HDC DC=GetDC(hWnd);
    OnPaint(DC);
    ReleaseDC(hWnd,DC);
  }
  vec2i GetClientSize(){
    RECT Rect;
    GetClientRect(Form.WinPair.hWnd,&Rect);
    return vec2i(Rect.right-Rect.left,Rect.bottom-Rect.top);
  }
  vec2i GetMousePos()
  {
    POINT P;
    GetCursorPos(&P);
    auto hWnd=Form.WinPair.hWnd;
    ScreenToClient(hWnd,&P);
    vec2i p(P.x,-P.y);
    vec2i z=GetClientSize();
    return p-vec2i(z.x/2,-z.y/2);
  }
  void OnPaint(HDC DC)
  {
    //Beep(1000,250);
    //Sleep(100);
    if(IsKeyDown(VK_SHIFT))
    {
      int igsdklgj=0;
    }
    SelectObject(DC,GetStockObject(BLACK_PEN));
    SelectObject(DC,GetStockObject(WHITE_BRUSH));
    RECT Rect;
    GetClientRect(Form.WinPair.hWnd,&Rect);
    int w=Rect.right-Rect.left;
    int h=Rect.bottom-Rect.top;
    FillRect(DC,&Rect,(HBRUSH)GetStockObject(WHITE_BRUSH));
    Ellipse(DC,0,0,w,h);
  }
};
/*
class eWinProgram:public ISubProgram{
public:
#define DEF_PRO_NESTED(F)F(DoClose)F(DoInit)F(DoFree)F(ExitCondition)F(CloseTrigger)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eWinProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(eWindow,Window,DEF,$,$)\
ADDEND()
//=====+>>>>>eWinProgram
#include "QapGenStruct.inl"
//<<<<<+=====eWinProgram
public:
    static void SysHasSelf();
public:
  bool Runned()
  {
    return Window.Runned;//Window.IsWindow();
  }
  bool NeedClose()
  {
    return Window.NeedClose;
  }
public:
  void Close()
  {
    if(!Window.IsWindow())return;
    Window.Runned=false;
    //Window.Close();
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
public:
  class DoClose:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoClose)PARENT(ISubProgram)OWNER(eWinProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TWeakPtr<eWinProgram>,Win,DEF,$,$)\
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoInit)PARENT(ISubProgram)OWNER(eWinProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TWeakPtr<eWinProgram>,Win,DEF,$,$)\
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoFree)PARENT(ISubProgram)OWNER(eWinProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TWeakPtr<eWinProgram>,Win,DEF,$,$)\
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ExitCondition)PARENT(ISubProgram)OWNER(eWinProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(TWeakPtr<eWinProgram>,App,DEF,$,$)\
    ADDVAR(TWeakPtr<ProgramLoop>,Loop,DEF,$,$)\
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(CloseTrigger)PARENT(ISubProgram)OWNER(eWinProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(TWeakPtr<eWinProgram>,App,DEF,$,$)\
    ADDVAR(TAutoPtr<TProgramNodeEx>,Action,DEF,$,$)\
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
        app->Window.NeedClose=false;
        action->Enabled=true;
        action->Update(Env); //lol, nice job!
        //
        //if(Env.Starter)
        //{
        //  Env.Starter->Save(Env);
        //}
        //app->Close();
      }
    }
  };
public:
  static void CreateDefaultProgram(IEnv&Env,TAutoPtr<ISubProgram>&Root)
  {
    if(Root)return;
    //создаЄм главный нод основной программы.
    auto*root=Root.build<TProgramNode>(Env);
    //создаЄм скрипт запускающий конструктор у окна.
    auto*init=root->AddItem<DoInit>(Env);
    //создаЄм скрипт включающий главный цикл.
    auto*start=root->AddItem<ProgramLoop::DoStart>(Env);
    //создаЄм главный цикл порграммы.
    auto*loop=root->AddItem<ProgramLoop>(Env);
    //создаЄм нод - тело цикла
    auto*body=loop->Body.build<TProgramNode>(Env);
    {}
      //создаЄм окно.
      auto*win=body->AddItem<eWinProgram>(Env);
      //создаЄм счЄтчик. так, дл€ забавы.
      auto*counter=body->AddItem<ProgramLoop::Counter>(Env);
      //создаЄм задержку в 10 мс. “оже дл€ забавы.
      auto*sleep=body->AddItem<ProgramSleep>(Env);
      //создаЄм тригер закрывающий программу.
      auto*trigger=body->AddItem<CloseTrigger>(Env);
      {}
        //создаЄм нод со скриптом сохранени€.
        auto*action=trigger->Action.build<TProgramNodeEx>(Env);
        //создаЄм скрипт сохран€ющий основную программу.
        auto*save=action->AddItem<AppStarter::DoSave>(Env);
        //создаЄм скрипт сохран€ющий основную программу.
        auto*close=action->AddItem<DoClose>(Env);
      {}
      //создаЄм скрипт выключающий главный цикл.
      auto*cond=body->AddItem<ExitCondition>(Env);
    {}
    //создаЄм скрипт запускающий деструктор у окна.
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

class eBuildDefProgram:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eBuildDefProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<AppStarter>,Starter,DEF,$,$)\
ADDEND()
//=====+>>>>>eBuildDefProgram
#include "QapGenStruct.inl"
//<<<<<+=====eBuildDefProgram
public:
  void Update(IEnv&Env)
  {
    if(!Starter)return;
    auto*starter=Starter.get();
    eWinProgram::CreateDefaultProgram(Env,starter->Root);
  }
public:
  class IsNotRoot:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IsNotRoot)PARENT(ISubProgram)OWNER(eBuildDefProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TWeakPtr<AppStarter>,Starter,DEF,$,$)\
    ADDVAR(TAutoPtr<TProgramNodeEx>,Action,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IsNotRoot
    #include "QapGenStruct.inl"
    //<<<<<+=====IsNotRoot
  public:
    void Update(IEnv&Env)
    {
      if(!Starter||!Action)return;
      auto*starter=Starter.get();
      auto*action=Action.get();
      if(!starter->Root)
      {
        action->Enabled=true;
        action->Update(Env);
      }
    }
  };
  class DoLoad:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoLoad)PARENT(ISubProgram)OWNER(eBuildDefProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TWeakPtr<AppStarter>,Starter,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoLoad
    #include "QapGenStruct.inl"
    //<<<<<+=====DoLoad
  public:
    void Update(IEnv&Env)
    {
      if(!Starter)return;
      auto*starter=Starter.get();
      starter->Load(Env);
    }
  };
  class DoSave:public ISubProgram{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DoSave)PARENT(ISubProgram)OWNER(eBuildDefProgram)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TWeakPtr<AppStarter>,Starter,DEF,$,$)\
    ADDEND()
    //=====+>>>>>DoSave
    #include "QapGenStruct.inl"
    //<<<<<+=====DoSave
  public:
    void Update(IEnv&Env)
    {
      if(!Starter)return;
      auto*starter=Starter.get();
      starter->Save(Env);
    }
  };
public:
  static void CreateDefalutStarter(IEnv&Env,TAutoPtr<ISubProgram>&Root)
  {
    //создаЄм главный узел.
    auto*root=Root.build<TProgramNode>(Env);
    //создаЄм скрипт который запускает загрузку основной програмы в загрузщик.
    auto*doload=root->AddItem<DoLoad>(Env);
    //создаЄм скрипт который провер€ет загрузилась ли основна€ программа.
    auto*script=root->AddItem<IsNotRoot>(Env);
    //создаЄм защищЄнный нод
    auto*action=script->Action.build<TProgramNodeEx>(Env);
    {}
      //создаЄм установщик стандартной основной программы.
      auto*defbuild=action->AddItem<eBuildDefProgram>(Env);
    {}
    //создаЄм загрузщик, который и запустит основную программу.
    auto*starter=root->AddItem<AppStarter>(Env);
    //дальше скучна€ настройка.
    {
      doload->Starter=starter;
      script->Starter=starter;
      defbuild->Starter=starter;
    }
  }
};
*/
/*
class eAppStarter_v01:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(eAppStarter_v01)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,filename,SET,"data.qap",$)\
ADDVAR(bool,AutoLoad,SET,true,$)\
ADDVAR(bool,AutoSave,SET,true,$)\
ADDVAR(TAutoPtr<QapProgram>,Root,DEF,$,$)\
ADDEND()
//=====+>>>>>eAppStarter_v01
#include "QapGenStruct.inl"
//<<<<<+=====eAppStarter_v01
public:
  static void SysHasSelf();
public:
  void TryLoad(IEnv&Env)
  {
    if(Root)return;
    QapLoadFromFile(Env.Env,Root,filename);
  }
  void TrySave(IEnv&Env)
  {
    if(!Root)return;
    QapSaveToFile(Env.Env,Root,filename);
    ProtoSaveToFile(Env.Env,ChangeFileExt(filename,".h"),"data",Root);
  }
  void BuildDefaultProgram(IEnv&Env)
  {
    if(Root)return;
    Root.build<QapProgram>(Env);
    Root->pEnv=&Env.Env;
  }
  void Init(IEnv&Env)
  {  
    if(Root)return;
    if(AutoLoad)TryLoad(Env);
    if(!Root)
    {
      BuildDefaultProgram(Env);
    }
    Root->Init();
  }
  void Free(IEnv&Env)
  {
    if(!Root)return;
    if(AutoSave)TrySave(Env);
    Root->Free();
    Root=nullptr;
  }
  void Update(IEnv&Env)
  {
    if(!Root)return;
    if(!Root->Runned()){
      return;
    }else{
      Root->Update();
      if(Root->NeedClose())
      {  
        Root->Window->NeedClose=false;
        Free(Env);
      }
      Sleep(10);
    }
  }
  void RawLoop(IEnv&Env)
  {   
    while(Root)
    {
      Update(Env);
    }
  }
  void MainLoop(IEnv&Env)
  {
    Init(Env);
    RawLoop(Env);
    Free(Env);
  }
};
*/
#define STRUCT_LIST(F)\
  F(TProgramNode)F(AppStarter)F(eWinProgram)F(ProgramSleep)
struct eWindowList{
  template<class QAP_RTTI>
  static void RegAll(QAP_RTTI&Env)
  {
    #define DEF_MACRO(TYPE)Sys$$<TYPE>::GetRTTI(Env);;
    STRUCT_LIST(DEF_MACRO);
    #undef DEF_MACRO
  }
};
#undef STRUCT_LIST

//<<<<<=====eWindow
#endif //DEF_BUILD_MICRO//
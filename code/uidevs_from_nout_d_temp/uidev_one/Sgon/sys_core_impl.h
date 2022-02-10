#pragma once
#include "GlobalEnv.inl"

static bool IsKeyDown(int vKey)
{
  int i=GetAsyncKeyState(vKey);
  return i<0;
}
static bool is_first_part_of(const string&text,const string&first_part)
{
  return first_part==text.substr(0,first_part.size());
}
static string without_first_part(const string&text,const string&first_part)
{
  return text.substr(first_part.size());
}
static bool remove_first_part_of(string&text,const string&first_part)
{
  if (!is_first_part_of(text,first_part))return false;
  text=without_first_part(text,first_part);
  return true;
}

struct t_branch_head_ptr
{
  string name;
  TRawPtr raw_ptr;
};

class TIndentStrLine
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TIndentStrLine)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,indent,DEF,$,$)\
ADDVAR(string,text,DEF,$,$)\
ADDEND()
//=====+>>>>>TIndentStrLine
#include "QapGenStruct.inl"
//<<<<<+=====TIndentStrLine
public:
};

//---
#include "Entity/OutDeviceBase.inl"
#include "Entity/OutDevice.inl"
#include "Entity/OutDeviceEx.inl"
//#include "qap_text_selector.inl"
//#include "QapTypeSelector.inl"
//---

class TQuad
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TQuad)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,SET,320,$)\
ADDVAR(int,y,SET,240,$)\
ADDVAR(int,w,SET,320,$)\
ADDVAR(int,h,SET,240,$)\
ADDEND()
//=====+>>>>>TQuad
#include "QapGenStruct.inl"
//<<<<<+=====TQuad
public:
  void Set(int x,int y,int w,int h)
  {
#define F(FIELD)this->FIELD=FIELD;
    F(x)F(y)F(w)F(h)
#undef F
  }
  vec2i&GetPos()
  {
    return *(vec2i*)(void*)(&this->x);
  }
  vec2i&GetSize()
  {
    return *(vec2i*)(void*)(&this->w);
  }
  void SetAs(const vec2i&pos,const vec2i&size)
  {
    GetPos()=pos;
    GetSize()=size;
  }
  RECT GetWinRect()
  {
    RECT tmp={x,y,x+w,y+h};
    return tmp;
  }
  void SetWinRect(const RECT&rect)
  {
    TQuad&r=*(TQuad*)(void*)(&rect);
    Set(r.x,r.y,r.w-r.x,r.h-r.y);
  }
  void SetSize(const SIZE&size)
  {
    w=size.cx;
    h=size.cy;
  }
  static TQuad getFullScreen()
  {
    TQuad tmp;
    auto mode=GetScreenMode();
    tmp.Set(0,0,mode.W,mode.H);
    return std::move(tmp);
  }
  void setAtCenter(const TQuad&quad)
  {
    QapAssert(quad.w>=w);
    QapAssert(quad.h>=h);
    x=(quad.w-w)/2;
    y=(quad.h-h)/2;
  }
  void setAsFullScreen()
  {
    *this=getFullScreen();
  }
  void subpos(const TQuad&q)
  {
    x-=q.x;
    y-=q.y;
  }
  void setAtCenterScreen()
  {
    setAtCenter(getFullScreen());
  }
};

class TD3DGameBox
{
public:
  class TForm
  {
  public:
    class WndClassPair
    {
    public:
      WNDPROC Proc;
      HWND hWnd;
      int ID;
      bool Used;
    public:
      WndClassPair():Proc(nullptr),hWnd(nullptr),ID(0),Used(false) {}
      WndClassPair(WNDPROC Proc,HWND hWnd,int ID,bool Used):Proc(Proc),hWnd(hWnd),ID(ID),Used(Used) {}
    public:
      void Init(TForm*Owner)
      {
        WndProcHeap::Get().Load(*this);
        QapAssert(!Used);
        QapAssert(!hWnd);
        Used=true;
        Proc((HWND)Owner,WMU_INIT,0,0);
      }
      void Free(TForm*Owner)
      {
        QapAssert(!hWnd);
        QapAssert(Used);
        Used=false;
        Proc((HWND)Owner,WMU_FREE,0,0);
        WndProcHeap::Get().Save(*this);
      }
    };
    class WndProcHeap
    {
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
        if (!flag)
        {
          vector<WndClassPair>&Arr=Heap.Arr;
#define F(N){WndClassPair tmp(WndProc<N>,nullptr,N,false);Arr.push_back(tmp);}
          F(0);
          F(1);
#undef F
          flag=true;
        }
        return Heap;
      }
    };
  public:
#define DEF_PRO_POOR_DESIGN()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TForm)OWNER(TD3DGameBox)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TD3DGameBox*,Owner,SYS,nullptr,$)\
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
      if (WinPair.hWnd)Free();
    }
    void operator=(TD3DGameBox*Owner)
    {
      this->Owner=Owner;
    }
  public:
    void Init()
    {
      WinPair.hWnd=nullptr;
      auto tmp=CreateWindowA(
            (LPCSTR)ClassAtom,
            "Unnamed",
            WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN,
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
      ClassName="TD3DGameBox_"+IToS(WinPair.ID);
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
      if (msg==WM_INPUTLANGCHANGEREQUEST)
      {
        int gg=1;
        return DefWindowProcA(hWnd,msg,wParam,lParam);
      }
      if (msg==WM_INPUTLANGCHANGE)
      {
        int gg=1;
        return DefWindowProcA(hWnd,msg,wParam,lParam);
      }
      if (msg==WM_WINDOWPOSCHANGING)
      {
        //string wtf="WTF?";
        static bool flag=true;
        if (flag)return 0;
      }
      static TForm*pForm=nullptr;
      if (!pForm)
      {
        QapAssert(WMU_INIT==msg);
        pForm=(TForm*)hWnd;
        return 0;
      }
      if (WMU_FREE==msg)
      {
        QapAssert(pForm);
        QapAssert(pForm->Owner);
        QapAssert(hWnd==((HWND)pForm));
        pForm=nullptr;
        return 0;
      }
      QapAssert(pForm);
      QapAssert(pForm->Owner);
      long UD=GetWindowLongA(hWnd,GWL_USERDATA);
      if (!UD)
      {
        SetWindowLong(hWnd,GWL_USERDATA,(long)pForm);
      }
      else
      {
        long pF=(long)pForm;
        QapAssert(pF==UD);
      }
      if (msg==WM_WINDOWPOSCHANGING)
      {
        QapAssert("WTF?");
        return 0;
      }
      auto result=pForm->Owner->WndProc(hWnd,msg,wParam,lParam);
      return result;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(TForm)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TD3DGameBox)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Caption,SET,"TD3DGameBox",$)\
ADDVAR(bool,NeedClose,SET,false,$)\
ADDVAR(bool,Runned,SET,false,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(bool,FullScreen,SET,true,$)\
ADDVAR(TQuad,Quad,DEF,$,$)\
ADDVAR(TForm,Form,SET,this,$)\
ADDVAR(QapKeyboard,Keyboard,DEF,$,$)\
ADDVAR(int,zDelta,SET,0,$)\
ADDVAR(vec2i,mpos,DEF,$,$)\
ADDEND()
//=====+>>>>>TD3DGameBox
#include "QapGenStruct.inl"
//<<<<<+=====TD3DGameBox
public:
  bool IsWindow()
  {
    return Form.WinPair.hWnd;
  }
  void Init()
  {
    if (IsWindow())return;
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
    //TScreenMode SM=GetScreenMode();
    DWORD Style=true?WS_OVERLAPPED:WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
    SetWindowLong(hWnd,GWL_STYLE,Style);
    RECT Rect=Quad.GetWinRect();
    AdjustWindowRect(&Rect,Style,false);
    SetWindowPos(hWnd,0,Quad.x,Quad.y,Quad.w,Quad.h,SWP_FRAMECHANGED|SWP_NOOWNERZORDER);
    ShowWindow(hWnd,SW_MAXIMIZE);
    ShowWindow(hWnd,Visible?SW_SHOW:SW_HIDE);
  }
  ~TD3DGameBox()
  {
    Free();
  }
  void Free()
  {
    if (!IsWindow())return;
    Runned=false;
    Form.Free();
    Form.UnReg();
    NeedClose=false;
  }
  void Update()
  {
    HWND&hWnd=Form.WinPair.hWnd;
    zDelta=0;
    Keyboard.try_reset();
    Keyboard.Sync();
    if (GetForegroundWindow()==hWnd)if (GetActiveWindow()==hWnd)mpos=unsafe_GetMousePos();
    for (;;)
    {
      MSG msg;
      if (!PeekMessageA(&msg,0,0,0,PM_REMOVE))break;
      TranslateMessage(&msg);
      {
        QapClock Clock;
        Clock.Start();
        DispatchMessageA(&msg);
        Clock.Stop();
        real ms=Clock.MS();
        if (ms>100)
        {
          int dsljf=int(ms);
        }
      }
    }
    Keyboard.try_reset();
  }
  void Close()
  {
    NeedClose=true;
  }
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
  static void KeyboardUpdate(QapKeyboard&Keyboard,const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam)
  {
    if (msg==WM_ACTIVATE)
    {
      Keyboard.NeedReset=true;
    }
#define F(KEY,DOWN)if(wParam==KEY){Keyboard.KeyUpdate(KEY,DOWN);}
    if (msg==WM_SYSKEYDOWN)
    {
      F(VK_F10,true);
      F(VK_MENU,true);
      F(VK_RETURN,true);
    }
    if (msg==WM_SYSKEYUP)
    {
      F(VK_F10,false);
      F(VK_MENU,false);
      F(VK_RETURN,false);
    }
    //if(msg==WM_SYSKEYUP)if(wParam==VK_RETURN)
    //{
    //  FullScreen=!FullScreen;
    //  WindowMode();
    //}
    bool key_flags[]={msg==WM_KEYUP,msg==WM_KEYDOWN};
    if (key_flags[0]||key_flags[1])
    {
      bool value=key_flags[1];
      auto&KB=Keyboard;
      auto&Down=Keyboard.Down;
      auto KeyUpdate=[&KB,&Down](int key,const bool value)->void
      {
        if (Down[key]==value)return;
        if (value!=IsKeyDown(key))return;
        KB.KeyUpdate(key,value);
      };
      struct TSysKey
      {
        int Key,LKey,RKey;
      } key_array[]=
      {
        {VK_SHIFT,VK_LSHIFT,VK_RSHIFT},
        {VK_CONTROL,VK_LCONTROL,VK_RCONTROL},
        {VK_MENU,VK_LMENU,VK_RMENU}
      };
      for (int i=0;i<lenof(key_array);i++)
      {
        auto&ex=key_array[i];
        if (wParam==ex.Key)
        {
          KeyUpdate(ex.LKey,value);
          KeyUpdate(ex.RKey,value);
        }
      }
    }
    if (msg==WM_KEYDOWN)
    {
      Keyboard.KeyUpdate(wParam,true);
    }
    if ((msg==WM_KEYUP)&&(wParam==VK_SNAPSHOT))
    {
      F(VK_SNAPSHOT,true);
      F(VK_SNAPSHOT,false);
    }
#undef F
    //---
    if (msg==WM_KEYUP)
    {
      Keyboard.KeyUpdate(wParam,false);
    }
    if (msg==WM_KEYDOWN)
    {
      Keyboard.KeyUpdate(wParam,true);
    }
    if (msg==WM_LBUTTONUP)
    {
      Keyboard.KeyUpdate(mbLeft,false);
    }
    if (msg==WM_RBUTTONUP)
    {
      Keyboard.KeyUpdate(mbRight,false);
    }
    if (msg==WM_MBUTTONUP)
    {
      Keyboard.KeyUpdate(mbMiddle,false);
    }
    if (msg==WM_LBUTTONDOWN)
    {
      Keyboard.KeyUpdate(mbLeft,true);
    }
    if (msg==WM_RBUTTONDOWN)
    {
      Keyboard.KeyUpdate(mbRight,true);
    }
    if (msg==WM_MBUTTONDOWN)
    {
      Keyboard.KeyUpdate(mbMiddle,true);
    }
    if (msg==WM_CHAR)
    {
      //auto kbl=GetKeyboardLayout(0);
      //auto ENGLISH = 0x409;
      //auto RUSSIAN = 0x419;
      Keyboard.CharUpdate(wParam);
    }
    //---
  }
  LRESULT WndProc(const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam)
  {
    KeyboardUpdate(Keyboard,hWnd,msg,wParam,lParam);
    if (msg==WM_MOUSEWHEEL)
    {
      zDelta=GET_WHEEL_DELTA_WPARAM(wParam);
    };
    if (msg==WM_CHAR)
    {
      auto kbl=GetKeyboardLayout(0);
      auto ENGLISH = 0x409;
      auto RUSSIAN = 0x419;
      char c=wParam;
      //if(c!=27)QapDebugMsg(CToS(c));
      int gg=1;
      //return 0;
    }
    /*
    if(msg==WM_KEYUP){return 0;}
    if(msg==WM_KEYDOWN){return 0;}
    if(msg==WM_LBUTTONUP){return 0;}
    if(msg==WM_RBUTTONUP){return 0;}
    if(msg==WM_MBUTTONUP){return 0;}
    if(msg==WM_LBUTTONDOWN){return 0;}
    if(msg==WM_RBUTTONDOWN){return 0;}
    if(msg==WM_MBUTTONDOWN){return 0;}
    if(msg==WM_CHAR)
    {
      auto kbl=GetKeyboardLayout(0);
      auto ENGLISH = 0x409;
      auto RUSSIAN = 0x419;
      char c=wParam;
      QapDebugMsg(CToS(c));
      int gg=1;
      return 0;
    }
    if(msg==WM_SYSKEYDOWN)
    {
      if(wParam==VK_F10){return 0;}
      if(wParam==VK_MENU){return 0;}
    }
    if(msg==WM_SYSKEYUP)
    {
      if(wParam==VK_MENU){return 0;}
      if(wParam==VK_F10){return 0;}
      if(wParam==VK_RETURN)
      {
        WindowMode();
        return 0;
      }
    }*/
    if (msg==WM_CLOSE)
    {
      Close();
      if (Runned)return 0;
    }
    if (msg==WM_SHOWWINDOW)
    {
      Visible=wParam;
    }/*
    if(msg==WM_SIZE)
    {

    }*/
    if (msg==WM_ERASEBKGND)
    {
      DoPaint();
    }
    return DefWindowProcA(hWnd,msg,wParam,lParam);
  }
  void DoPaint()
  {
    HWND hWnd=Form.WinPair.hWnd;
    HDC DC=GetDC(hWnd);
    RECT Rect;
    GetClientRect(Form.WinPair.hWnd,&Rect);
    FillRect(DC,&Rect,(HBRUSH)(COLOR_BTNFACE));
    ReleaseDC(hWnd,DC);
  }
  vec2i GetClientSize()
  {
    RECT Rect;
    GetClientRect(Form.WinPair.hWnd,&Rect);
    return vec2i(Rect.right-Rect.left,Rect.bottom-Rect.top);
  }
  vec2i GetMousePos()
  {
    return mpos;
  }
  vec2i unsafe_GetMousePos()
  {
    POINT P;
    GetCursorPos(&P);
    auto hWnd=Form.WinPair.hWnd;
    ScreenToClient(hWnd,&P);
    vec2i p(P.x,-P.y);
    vec2i z=GetClientSize();
    return p-vec2i(z.x/2,-z.y/2);
  }
};

//-------------------------------------------//
/*
#include "Entity\OutDeviceBase.inl"
#include "Entity\eWindow.inl"
#include "Entity\QapProgramD3D9.inl"
*/
//-------------------------------------------//

class TSuperOutDevice:public TOutDev
{
public:
  class TBranch
  {
  public:
    TContext top;
    vector<TContext> items;
    bool ok=true;
    void push()
    {
      items.push_back(top);
    }
    void pop()
    {
      top=items.back();
      items.pop_back();
    }
    TContext&back()
    {
      return items.back();
    }
    TContext&front()
    {
      return items.front();
    }
    int size()const
    {
      return items.size();
    }
    bool empty()const
    {
      return items.empty();
    }
    TContext&operator[](int index)
    {
      return items[index];
    }
  };
public:
  TBranch branch;
public:
  void push(DevCmd&Cmd)
  {
    auto&top=branch.top;
    QapAssert(!top.pCmd&&top.head.empty());
    branch.push();
    TCmdVisitor::t_dev dev;
    TCmdVisitor CV(dev,&top);
    Cmd.Use(CV);
    if (!dev.ok)
    {
      QapAssert(branch.ok);
      branch.ok=false;
      return;
    }
    auto&back=branch.back();
    back.head=std::move(top.head);
    back.pCmd=std::move(&Cmd);
    top.pCmd=nullptr;
    top.head.clear();
  }
  void pop(DevCmd&Cmd)
  {
    auto&top=branch.top;
    QapAssert(!top.pCmd&&top.head.empty());
    QapAssert(!branch.empty());
    branch.pop();
    QapAssert(top.pCmd==&Cmd);
    top.pCmd=nullptr;
    top.head.clear();
  }
};

struct TOutDevScopeMemberID
{
  typedef int(*t_get_field_id_func)();
  TSuperOutDevice&dev;
  TOutDev::TMemberID devcmd;
  TOutDevScopeMemberID(TSuperOutDevice&dev,const t_get_field_id_func&func):dev(dev),devcmd(func())
  {
    dev.push(devcmd);
  }/*
  TOutDevScopeMemberID(TSuperOutDevice&dev,int id):dev(dev),devcmd(id){
    dev.push(devcmd);
  }*/
  ~TOutDevScopeMemberID()
  {
    dev.pop(devcmd);
  }
};

struct TOutDevScopeVecID
{
  TSuperOutDevice&dev;
  TOutDev::TVecID devcmd;
  TOutDevScopeVecID(TSuperOutDevice&dev,int id):dev(dev),devcmd(id)
  {
    dev.push(devcmd);
  }
  ~TOutDevScopeVecID()
  {
    dev.pop(devcmd);
  }
};

struct TOutDevScopeChunk
{
  TSuperOutDevice&dev;
  TOutDev::TChunk devcmd;
  TOutDevScopeChunk(TSuperOutDevice&dev):dev(dev)
  {
    dev.push(devcmd);
  }
  ~TOutDevScopeChunk()
  {
    dev.pop(devcmd);
  }
};
//#define DEF_PRO_SYS_GET_FIELD_ID(NAME)ProxySys$$::GetFieldId(int(&(((SelfClass*)nullptr)->*(&SelfClass::NAME))))

class TD3DGameBoxBuilder;

class IRenderProgram
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Caption,DEF,$,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,AutoRender,SET,true,$)\
ADDVAR(bool,AutoUpdate,SET,true,$)\
ADDVAR(bool,NeedRemove,DEF,$,$)\
ADDEND()
//=====+>>>>>IRenderProgram
#include "QapGenStruct.inl"
//<<<<<+=====IRenderProgram
public:
  struct t_context
  {
    IEnvRTTI&Env;
    TD3DGameBoxBuilder&root;
    TSuperOutDevice dev;
    operator IEnvRTTI&()
    {
      return Env;
    }
  };
  virtual void Render(t_context&con) {}
  virtual void Update(t_context&con) {}
  void TryRender(t_context&con)
  {
    if (NeedRemove)return;
    if (!Enabled||!AutoRender)return;
    Render(con);
  }
  void TryUpdate(t_context&con)
  {
    if (NeedRemove)return;
    if (!Enabled||!AutoUpdate)return;
    Update(con);
  }
};

class TRenderNode:public IRenderProgram
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRenderNode)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<IRenderProgram>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TRenderNode
#include "QapGenStruct.inl"
//<<<<<+=====TRenderNode
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }
public:
  void Render(t_context&con)
  {
    for (int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if (!ex)continue;
      ex->TryRender(con);
    }
  }
  void Update(t_context&con)
  {
    TOutDevScopeMemberID devscope(con.dev,ProxySys$$::GET_FIELD_ID::Items);
    for (int i=0;i<Items.size();i++)
    {
      auto&ex=Items[i];
      auto*ptr=ex.get();
      if (!ptr)continue;
      {
        TOutDevScopeVecID devscope(con.dev,i);
        {
          TOutDevScopeChunk devscope(con.dev);
          ptr->TryUpdate(con);
        }
      }
      if (ptr->NeedRemove)ex=nullptr;
    }
    //QapCleanIf(Items,[](TAutoPtr<IRenderProgram>&ref){return !ref||ref->NeedRemove;});
  }
public:
  TAutoPtr<IRenderProgram>&front()
  {
    return Items.front();
  }
  TAutoPtr<IRenderProgram>&back()
  {
    return Items.back();
  }
public:
  bool empty()const
  {
    return Items.empty();
  }
};

class TUberFullLoaderInfo
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUberFullLoaderInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,news,SET,true,$)\
ADDVAR(bool,build_tree,DEF,$,$)\
ADDVAR(bool,def_ok,DEF,$,$)\
ADDVAR(real,def_ms,DEF,$,$)\
ADDVAR(bool,hope_ok,DEF,$,$)\
ADDVAR(real,hope_ms,DEF,$,$)\
ADDEND()
//=====+>>>>>TUberFullLoaderInfo
#include "QapGenStruct.inl"
//<<<<<+=====TUberFullLoaderInfo
public:
};

class T20140604;
class QapTreeDebugger;

class TSysResourcePack
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSysResourcePack)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResHolderFontObj,DEF,$,$)\
ADDVAR(TResourceHolder,ResHolderBallTex,DEF,$,$)\
ADDVAR(TResourceHolder,ResHolderQuadTex,DEF,$,$)\
ADDVAR(TWeakPtr<QapFontObject>,FontObj,DEF,$,$)\
ADDVAR(TWeakPtr<QapTexObject>,BallTex,DEF,$,$)\
ADDVAR(TWeakPtr<QapTexObject>,QuadTex,DEF,$,$)\
ADDEND()
//=====+>>>>>TSysResourcePack
#include "QapGenStruct.inl"
//<<<<<+=====TSysResourcePack
public:
};

class TD3DGameBoxBuilder
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TD3DGameBoxBuilder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TD3DGameBox,win,DEF,$,$)\
ADDVAR(QapD3D9,D9,DEF,$,$)\
ADDVAR(QapD3DDev9,D9Dev,DEF,$,$)\
ADDVAR(bool,need_clean_reslist,DEF,$,$)\
ADDVAR(QapResourceList,ResList,DEF,$,$)\
ADDVAR(QapResourceDetector,Detector,DEF,$,$)\
ADDVAR(QapDev,qDev,DEF,$,$)\
ADDVAR(TRenderNode,Scene,DEF,$,$)\
ADDVAR(int,SleepMs,SET,16,$)\
ADDVAR(TSysResourcePack,SysRes,DEF,$,$)\
ADDVAR(TUberFullLoaderInfo,ufli,DEF,$,$)\
ADDEND()
//=====+>>>>>TD3DGameBoxBuilder
#include "QapGenStruct.inl"
//<<<<<+=====TD3DGameBoxBuilder
public:/*
  QapFontObject*AttachToSysFont(IEnvRTTI&Env,TResourceHolder&ResHolder,const string&Caption)
  {
    auto&arr=ResList.Items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      bool ok=ex.Product.pType->IsBasedOn(Sys$$<QapFontObject>::GetRTTI(Env));
      if(!ok)continue;
      auto*ptr=(QapFontObject*)ex.get();
      if(ptr->Caption!="SysFont")continue;
      ptr->Holders.push_back(&ResHolder);
      ResHolder.Caption=Caption;
      return ptr;
    }
    QapAssert("WTF?");
    return nullptr;
  }*/
  void InitSysRes(IEnvRTTI&Env)
  {
    SysRes.FontObj=ResList.AddItem<QapFontObject>(Env,SysRes.ResHolderFontObj,"SysRes.FontObj");
    SysRes.BallTex=ResList.AddItem<QapTexObject>(Env,SysRes.ResHolderBallTex,"SysRes.BallTex");
    SysRes.QuadTex=ResList.AddItem<QapTexObject>(Env,SysRes.ResHolderQuadTex,"SysRes.QuadTex");
    SysRes.FontObj->SetToDef();
    SysRes.BallTex->SetToDef();
    SysRes.QuadTex->SetToDef();
    SysRes.BallTex->File.FN="?GenBall(128)";
    SysRes.QuadTex->File.FN="?GenQuad(128)";
  }
public:
  void CleanResList()
  {
    if (!need_clean_reslist)return;
    need_clean_reslist=false;
    auto&arr=ResList.Items;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (!ex)continue;
      auto&holders=ex->Holders;
      QapClean(holders);
      if (!holders.empty())continue;
      ex=nullptr;
    }
    QapClean(arr);
  }
public:
  void SceneUpdate(IEnvRTTI&Env)
  {
    IRenderProgram::t_context context=
    {
      Env,
      *this,
    };
    context.dev.branch.items.reserve(128);
    context.dev.branch.top.pCmd=nullptr;
    context.dev.branch.top.pType=Sys$$<SelfClass>::GetRTTI(Env);
    context.dev.branch.top.pValue=this;
    SceneUpdateEx(context);
    SceneRenderEx(context);
  }
public:
  void SceneUpdateEx(IRenderProgram::t_context&con)
  {
    SceneDoMove(con);
  }
  void SceneRenderEx(IRenderProgram::t_context&con)
  {
    auto&Dev=con.root.D9Dev;
    vec2i ClientSize=con.root.win.GetClientSize();
    if (!Dev.BeginScene())return;
    {
      D3DVIEWPORT9 ViewPort={0,0,ClientSize.x,ClientSize.y,-1.f,+1.f};
      Dev.pDev->SetViewport(&ViewPort);
      Dev.Set2D(vec2i(0,0),1.0,0,&ClientSize);
      Dev.Clear2D(0xffc8c8c8);
      qDev.NextFrame();
      SceneDoDraw(con);
    }
    if (!Dev.EndScene())return;
    RECT Rect={0,0,ClientSize.x,ClientSize.y};
    Dev.Present(&Rect,&Rect);
  }
public:
  void SceneDoMove(IRenderProgram::t_context&con)
  {
    auto&Dev=con.root.D9Dev;
    if (!qDev.DynRes.pDev)
    {
      qDev.MountDev(Dev);
      qDev.Init(1024*1024,1024*1024*3);
      Detector.MountDev(Dev);
      Detector.needinit=true;
    }
    if (Detector.needinit)
    {
      Detector.Init();
      ResList.Run(con.Env,&Dev);
    };
    //
    {
      TOutDevScopeMemberID devscope(con.dev,ProxySys$$::GET_FIELD_ID::Scene);
      Scene.TryUpdate(con);
    }
    int gg=1;
  }
  void SceneDoDraw(IRenderProgram::t_context&con)
  {
    Scene.TryRender(con);
  }
public:
  void init_d3d()
  {
    //---
    HWND hwnd=win.Form.WinPair.hWnd;
    //---
    D9.Init();
    auto vsync=file_get_contents("vsync").substr(0,string("false").size())!="false";
    D9Dev.PresParams.SetToDef(hwnd,vsync);
    D9Dev.Init(hwnd,D9);
  }
  void init(IEnvRTTI&Env,const string&caption)
  {
    win.Caption=caption;
    win.Init();
    win.Visible=false;
    win.WindowMode();
    //---
    HWND hwnd=win.Form.WinPair.hWnd;
    //---
    init_d3d();
    //---
    win.Visible=true;
    win.WindowMode();
    UpdateWindow(hwnd);
  }
  static string get_file_name()
  {
    return "data.qap";
  }
  void loop(IEnvRTTI&Env)
  {
    for (int i=0;win.Runned;i++)
    {
      win.Update();
      //IRenderProgram::t_context context={Env,*this};
      SceneUpdate(Env);
      CleanResList();
      Sleep(SleepMs);
      if (win.NeedClose)
      {
        QapPublicUberFullSaverBin(Env,QapRawUberObject(*this),get_file_name());
        if (win.Keyboard.Down[VK_SHIFT])
        {
          QapPublicUberFullSaverProto(Env,QapRawUberObject(*this),ChangeFileExt(get_file_name(),".h"));
        }
        win.Free();
      }
    }
  }
};

class T20140604:public IRenderProgram
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20140604)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>T20140604
#include "QapGenStruct.inl"
//<<<<<+=====T20140604
public:
  void Render(t_context&con)
  {
    auto&qDev=con.root.qDev;
    qDev.BindTex(0,0);
    qDev.SetColor(QapColor(128,0,0,0));
    qDev.DrawCircle(vec2i(0,0),100,0,1,128);
    qDev.DrawRect(vec2i(-200,+200),vec2i(-300,+300),2);
  }
  void Update(t_context&con)
  {

  }
};

class TPressEscapeToClose:public IRenderProgram
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPressEscapeToClose)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TPressEscapeToClose
#include "QapGenStruct.inl"
//<<<<<+=====TPressEscapeToClose
public:
  void Update(t_context&con)
  {
    if (!con.root.win.Keyboard.OnDown(VK_ESCAPE))return;
    con.root.win.Close();
  }
};

//---
/*   QapTreeDebugger   */
//---

class TGUIRect
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUIRect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(vec2i,size,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUIRect
#include "QapGenStruct.inl"
//<<<<<+=====TGUIRect
public:
  TGUIRect(const vec2i&pos,const vec2i&size):pos(pos),size(size) {}
  TGUIRect(vec2i&&pos,vec2i&&size):pos(std::move(pos)),size(std::move(size)) {}
  vec2i getQuadPoint(bool x,bool y)const
  {
    return vec2i(pos.x+(size.x/2)*(x?+1:-1),pos.y+(size.y/2)*(y?-1:+1));
  }
  vec2i getQuadPoint(int id)const
  {
    //    y
    //    ^
    //   0|1
    //----.---->x
    //   2|3
    //    |
    return getQuadPoint((id==1)||(id==3),(id==2)||(id==3));
  }
  bool CheckPoint(const vec2i&p)const
  {
    return (abs(p.x-pos.x)<=size.x/2)&&(abs(p.y-pos.y)<=size.y/2);
  }
};

class IGUI_Content
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IGUI_Content
#include "QapGenStruct.inl"
//<<<<<+=====IGUI_Content
public:
  struct TRenderContext
  {
    vec2i pos;
    vec2i size;
    vec2i mpos;
    IRenderProgram::t_context&context;
    QapDev&qDev;
  };
public:
  virtual void Render(TRenderContext&Context) {}
  struct TUpdateContext
  {
    vec2i pos;
    vec2i size;
    vec2i mpos;
    int zDelta;
    IRenderProgram::t_context&context;
    QapKeyboard&keyboard;
  };
  virtual void Update(TUpdateContext&Context) {}
public:
  virtual void GetSize(IRenderProgram::t_context&context,vec2i&size)
  {
    size=vec2i_zero;
  }
public:
  static void DrawGreenTrigon(TRenderContext&Context,int c32=32)
  {
    auto&qDev=Context.qDev;
    qDev.SetColor(0xFF50A050);
    qDev.DrawTrigon(vec2i(0,-c32),vec2i(-c32,0),vec2i(+c32,0));
  }
};

class QapTextSelectorV20140605:public IGUI_Content
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV20140605)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,OnDown,DEF,$,$)\
ADDVAR(int,zDelta,SET,0,$)\
ADDVAR(int,SelectId,SET,-1,$)\
ADDVAR(vector<string>,Lines,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV20140605
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV20140605
public:
  static bool toMonoEx(const string&line,string&mono)
  {
    bool flag=false;
    bool good=false;
    bool need=false;
    mono.reserve(line.size());
    for (int i=0;i<line.size();i++)
    {
      auto&ex=line[i];
      if (ex=='^')
      {
        flag=true;
        continue;
      }
      if (!flag)
      {
        mono.push_back(good?ex:' ');
        continue;
      }
      else
      {
        flag=false;
      }
      if (ex=='E')
      {
        good=true;
        need=true;
        continue;
      }
      good=false;
    }
    return need;
  };
  struct SelectIdUpdater
  {
    int x;
    int y;
    int dy;
    int dx;
    QapFont&font;
    const vec2i&Pos;
    const vec2i&MPos;
    SelectIdUpdater(QapFont&font,int zDelta,const vec2i&Pos,const vec2i&MPos):font(font),Pos(Pos),MPos(MPos)
    {
      x=0;
      y=Pos.y+zDelta;
      dy=-font.Info.Coords[0].y;
      dx=font.Info.Coords[0].x;
    }
    bool skip_line(const TGUIRect&Rect)
    {
      int value=y-Rect.pos.y;
      return !InDip<int>(-Rect.size.y/2+font.Info[0].y,value,+Rect.size.y/2);// !Rect.CheckPoint(vec2i(Rect.pos.x+1,y-Rect.pos.y));
    }
    bool foo(TIndentStrLine&ex)
    {
      bool flag=false;
      int h=-dy-2;
      x=Pos.x+dx*ex.indent;
      if (InDip<int>(0,MPos.y-y-dy,h))
      {
        int L=QapQ3Text::GetLength(font,".."+ex.text);
        if (InDip<int>(0,MPos.x-x,L))
        {
          flag=true;
        }
      }
      return flag;
    }
    bool foo(const string&ex)
    {
      TIndentStrLine tmp;
      tmp.text=ex;
      return foo(tmp);
    }
    void next_line()
    {
      y+=dy;
    }
  };
  void Render(TRenderContext&Context)
  {
    if (!Context.context.root.SysRes.FontObj)return;
    auto&qDev=Context.qDev;
    auto&font=Context.context.root.SysRes.FontObj->Font;
    auto&tex=Context.context.root.SysRes.FontObj->Tex;
    vec2i pos=Context.pos-Context.size/2;
    pos.y+=Context.size.y;
    vec2i mpos=Context.pos+Context.mpos;
    SelectIdUpdater SIU(font,zDelta,pos,mpos);
    auto&x=SIU.x;
    auto&y=SIU.y;
    tex.Bind();
    TGUIRect ContextRect(Context.pos,Context.size);
    QapDev::BatchScope Scope(qDev);
    for (int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      if (SIU.skip_line(ContextRect))
      {
        SIU.next_line();
        continue;
      }
      SIU.foo(ex);
      bool flag=SelectId==i;
      string line=!flag?"^1.^0"+ex+"^1.":"^7[^E"+ex+"^7]";
      for (;;)
      {
        string mono;
        if (!toMonoEx(line,mono))break;
        qDev.SetColor(0xff000000);
        QapQ3Text::DrawQapText(&qDev,font,x+1,y-1,mono);
        break;
      }
      QapQ3Text::DrawQapText(&qDev,font,x,y,line);
      SIU.next_line();
    }
  }
  void GetSize(IRenderProgram::t_context&context,vec2i&size)
  {
    if (!context.root.SysRes.FontObj)return;
    if (Lines.empty())return;
    size=vec2i_zero;
    auto&font=context.root.SysRes.FontObj->Font;
    int dx=font.Info.Coords[0].x;
    int dy=font.Info.Coords[0].y;
    for (int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      int x=QapQ3Text::GetLength(font,ex+"..");
      size.x=std::max<int>(size.x,x);
      size.y+=dy;
    }
  }
  void Update(TUpdateContext&Context)
  {
    if (!Context.context.root.SysRes.FontObj)return;
    TGUIRect rect(Context.pos,Context.size);
    //
    vec2i pos=Context.pos-Context.size/2;
    pos.y+=Context.size.y;
    auto mpos=Context.pos+Context.mpos;
    //
    if (rect.CheckPoint(mpos))
    {
      zDelta-=64*Sign(Context.zDelta);
    }
    SelectId=-1;
    OnDown=false;
    if (!rect.CheckPoint(mpos))return;
    auto&Font=Context.context.root.SysRes.FontObj->Font;
    SelectIdUpdater SIU(Font,zDelta,pos,mpos);
    for (int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      //if(SIU.skip_line())
      bool flag=SIU.foo(ex);
      if (flag)
      {
        SelectId=i;
        OnDown=Context.keyboard.OnDown(mbLeft);
      }
      SIU.next_line();
    }
  }
};

class QapBaseSelector
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapBaseSelector)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TType>,base,DEF,$,$)\
ADDVAR(bool,need_refresh,SET,false,$)\
ADDVAR(vector<TWeakPtr<TType>>,arr,DEF,$,$)\
ADDVAR(TWeakPtr<QapTextSelectorV20140605>,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>QapBaseSelector
#include "QapGenStruct.inl"
//<<<<<+=====QapBaseSelector
public:
  void change_base(TWeakPtr<TType>&pBaseType)
  {
    change_base_raw(pBaseType.get());
  }
  void change_base_raw(TType*pBaseType)
  {
    if (!selector)return;
    arr.clear();
    selector->Lines.clear();
    base=pBaseType;
    need_refresh=true;
  }
  static TType*GetTAutoPtr_ElemType_From_RawPtr(TRawPtr&raw_ptr)
  {
    auto*value=raw_ptr.pValue;
    auto*type=TTypeAutoPtr::UberCast(raw_ptr.pType);
    if (!type||!value)return nullptr;
    if (!type->ElementType)return nullptr;
    auto*elem_type=type->ElementType.get();
    return elem_type;
  }
  void change_base_ex(ITreeDebuggerBranch&Branch)
  {
    auto*pBaseType=GetTAutoPtr_ElemType_From_RawPtr(Branch.GetRawPtr());
    if (!pBaseType)return;
    change_base_raw(pBaseType);
  }
public:
  struct Hidden
  {
    vector<TWeakPtr<TType>>&list;
    void add(TType*pType)
    {
      list.push_back(pType);
    }
    void render(QapDev&qDev,QapFont&font)
    {
      auto startpos=vec2i(10,10);
      QapQ3Text::DrawQapText(&qDev,font,startpos.x,startpos.y,"");
      //qDev.DrawT
    }
    void FindAllDerivedTypes(IEnvRTTI&Env,TType*pBaseType)
    {
      auto&arr=Env.GetArr();
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*p=ex.Type.get();
        if (!p->Factory)continue;
        if (!p->IsBasedOn(pBaseType))continue;
        add(p);
      }
    }
  };
public:
  template<int>
  void weak_update(IEnvRTTI&Env,QapTreeDebugger&qtd)
  {
    if (!selector)return;
    auto&sel=*selector.get();
    Update(Env);
    if (!base)return;
    if (!sel.OnDown)return;
    int id=sel.SelectId;
    if (id<0)return;
    if (id>=arr.size())return;
    if (!arr[id])return;
    auto*pType=arr[id].get();
    if (arr.size()!=sel.Lines.size())
    {
      QapDebugMsg("WTF?");
      return;
    }
    QapAssert(pType->GetFullName()==sel.Lines[id]);
    auto raw_ptr=qtd.SelectBranch.GetRawPtr();
    auto*elem_type=GetTAutoPtr_ElemType_From_RawPtr(raw_ptr);
    if (!elem_type)return;
    if (!pType->IsBasedOn(elem_type))return;
    TAutoPtr<void>&Value=*(TAutoPtr<void>*)raw_ptr.pValue;
    Value=nullptr;
    Value.unsafe_build(pType);/*
    auto&Product=Value.Product;
    Product.pType=pType;
    Product.Init();*/
  }
  void Update(IEnvRTTI&Env)
  {
    if (!selector)return;
    if (!base)
    {
      arr.clear();
      selector->Lines.clear();
    }
    if (need_refresh)
    {
      need_refresh=false;
      arr.clear();
      auto*pBaseType=base.get();
      Hidden hd={arr};
      hd.FindAllDerivedTypes(Env,pBaseType);
    }
    //if(auto_update)
    {
      selector->Lines.clear();
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if (!ex)
        {
          selector->Lines.push_back("");
          continue;
        }
        auto*p=ex.get();
        string pfn=p->GetFullName();
        selector->Lines.push_back(std::move(pfn));
      }
    }
    int gg=1;
  }
};

class QapTreeDebugger:public IRenderProgram
{
public:
  class TPage
  {
  public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPage)OWNER(QapTreeDebugger)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(TFieldPtr,Select,DEF,$,$)\
    ADDVAR(vec2i,pos,SET,vec2i(0,0),$)\
    ADDVAR(int,zD,SET,0,$)\
    ADDVAR(int,MaxDepth,SET,3,$)\
    ADDVAR(bool,NeedRemove,SET,false,$)\
    ADDEND()
    //=====+>>>>>TPage
#include "QapGenStruct.inl"
    //<<<<<+=====TPage
  };
  class TPages
  {
  public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPages)OWNER(QapTreeDebugger)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TPage>,Items,DEF,$,$)\
    ADDEND()
    //=====+>>>>>TPages
#include "QapGenStruct.inl"
    //<<<<<+=====TPages
  public:
    void Update()
    {
      int last=0;
      for (int i=0;i<Items.size();i++)
      {
        auto&ex=Items[i];
        if (ex.NeedRemove)continue;
        if (last!=i)
        {
          auto&ax=Items[last];
          ax=std::move(ex);
        }
        last++;
      }
      if (last==Items.size())return;
      Items.resize(last);
    }
  };
public:
  class TBranch
  {
  public:
    typedef TOutDevEx::DevCmd DevCmd;
  public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBranch)OWNER(QapTreeDebugger)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TFieldPtr,Root,DEF,$,$)\
    ADDVAR(bool,NeedRemove,SET,false,$)\
    ADDVAR(vector<TAutoPtr<DevCmd>>,Items,DEF,$,$)\
    ADDVAR(string,Code,DEF,$,$)\
    ADDEND()
    //=====+>>>>>TBranch
#include "QapGenStruct.inl"
    //<<<<<+=====TBranch
  public:
    struct TOutDevBuff
    {
      OutDevice&OD;
      vector<TAutoPtr<TOutDev::DevCmd>> out;
      TOutDevBuff(OutDevice&OD):OD(OD) {}
      void push()
      {

        int count=out.size();
        for (int i=0;i<count;i++)
        {
          auto*p=out[i].get();
          OD.push(p);
        }
      }
      void pop()
      {
        int count=out.size();
        for (int i=0;i<count;i++)
        {
          OD.pop();
        }
      }
      bool grab(IEnvRTTI&Env,TBranch*p,TType*pTBranch)
      {
        if (!p||!p->Root)return false;
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
          for (int i=0;i<arr.size();i++)
          {
            auto&ex=arr[i];
            auto*p=ex.get();
            p->Use(Conv);
            if (Conv.CV.error)break;
            out.push_back(std::move(Conv.pCmd));
          }
          if (Conv.CV.error)
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
      QapKeyboard&KB;
      TMeCallBack(TOutDevEx::TCmdHeadVisitor&Head,TBranch&Branch,QapKeyboard&KB):Head(Head),Branch(Branch),KB(KB)
      {
        index=-1;
      }
      bool Pass(string&buff)
      {
        if (index==-1)
        {
          buff=std::move(Head.out);
          return true;
        }
        auto&Items=Branch.Items;
        bool result=index<Items.size();
        if (!result)return false;
        auto&ex=Items[index];
        if (!ex)
        {
          Head.add_error("cmd is empty");
          return false;
        }
        auto*pCmd=ex.get();
        pCmd->Use(Head);
        if (Head.error)return false;
        buff=std::move(Head.out);
        return true;
      }
      void Next()
      {
        index++;
      }
      void OnSelect()
      {
        //use index here
        if (index<0)return;
        if (!KB.OnDown(VK_RCONTROL))return;
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
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if (!ex)
        {
          Head.add_error("cmd is empty");
          break;
        }
        auto*pCmd=ex.get();
        pCmd->Use(Head);
        //
        if (Head.error)break;
      }
      if (Head.error)
      {
        Head.out+="{...error: "+Head.error_string+"...}";
      }
      Code=std::move(Head.out);
    }
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
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if (!ex)
        {
          Head.add_error("cmd is empty");
          break;
        }
        auto*pCmd=ex.get();
        pCmd->Use(Head);
        //
        if (Head.error)break;
      }
      if (Head.error)
      {
        Head.out+="{...error: "+Head.error_string+"...}";
        return raw_ptr;
      }
      raw_ptr.pType=Context.pType;
      raw_ptr.pValue=Context.pValue;
      return raw_ptr;
    }
  };
  class TBranchEx:public ITreeDebuggerBranch
  {
  public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBranchEx)PARENT(ITreeDebuggerBranch)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(QapTreeDebugger::TBranch,Branch,DEF,$,$)\
  ADDEND()
    //=====+>>>>>TBranchEx
#include "QapGenStruct.inl"
    //<<<<<+=====TBranchEx
  public:
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
//#define DEF_PRO_NESTED(F)F(DoFieldCopy)F(DevTools)F(DevCallBack)F(TPage)F(TPages)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTreeDebugger)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i,pos,SET,vec2i(+15,-40),$)\
ADDVAR(vec2i,mpos,DEF,$,$)\
ADDVAR(bool,TextAutoUpdate,SET,true,$)\
ADDVAR(bool,NeedCallWindowMode,SET,false,$)\
ADDVAR(int,zD,SET,0,$)\
ADDVAR(int,MaxDepth,SET,5,$)\
ADDVAR(TWeakPtr<TType>,pQapTreeDebugger,DEF,$,$)\
ADDVAR(TWeakPtr<TType>,pTBranch,DEF,$,$)\
ADDVAR(bool,InScreenOptimization,SET,true,$)\
ADDVAR(bool,SkipCommaInVector,SET,true,$)\
ADDVAR(bool,NeedClearPages,SET,false,$)\
ADDVAR(TPages,pages,DEF,$,$)\
ADDVAR(bool,NeedClearBranches,SET,false,$)\
ADDVAR(bool,AutoUpdateBranchesHead,SET,false,$)\
ADDVAR(vector<TBranch>,Branches,DEF,$,$)\
ADDVAR(TBranchEx,SelectBranch,DEF,$,$)\
ADDVAR(TBranchEx,DestBranch,DEF,$,$)\
ADDVAR(int,SelectBranchId,SET,0,$)\
ADDVAR(bool,SelectBranchEnabled,SET,false,$)\
ADDVAR(TFieldPtr,Select,DEF,$,$)\
ADDVAR(int,empty_lines,DEF,$,$)\
ADDVAR(int,omitted_lines,DEF,$,$)\
ADDVAR(vector<TIndentStrLine>,lines,DEF,$,$)\
ADDVAR(QapBaseSelector,Selector,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTreeDebugger
#include "QapGenStruct.inl"
//<<<<<+=====QapTreeDebugger
public:
  vec2i get_pos(t_context&con)
  {
    auto size=con.root.win.GetClientSize();
    return pos+vec2i(-size.x,zD*2+size.y)/2;
  }
  void Render(t_context&con)
  {
    QapDev&qDev=con.root.qDev;
    if (!con.root.SysRes.FontObj)return;
    auto*font_obj=con.root.SysRes.FontObj.get();
    auto&font=font_obj->Font;
    qDev.SetColor(0xff000000);
    qDev.BindTex(0,&font_obj->Tex);
    real y=get_pos(con).y;
    int dy=-font.Info.Coords[0].y;
    int dx=font.Info.Coords[0].x;
    y+=dy*empty_lines;
    QapDev::BatchScope Scope(qDev);
    {
      QapClock Clock;
      Clock.Start();
      for (int i=0;i<lines.size();i++)
      {
        auto&ex=lines[i];
        //qDev.SetColor(0xff000000);
        bool flag=false;
        int h=-dy-2;
        int x=get_pos(con).x-dx+dx*ex.indent;
        if (InDip<int>(0,mpos.y-y-dy,h))
        {
          int L=QapQ3Text::GetLength(font,".."+ex.text);
          if (InDip<int>(0,mpos.x-x,L))
          {
            //qDev.SetColor(0xff008100);
            flag=true;
          }
        }
        string line=!flag?"^1.^0"+ex.text+"^1.":"^7[^0"+ex.text+"^7]";
        do
        {
          string mono;
          bool flag=false;
          bool good=false;
          bool need=false;
          for (int i=0;i<line.size();i++)
          {
            auto&ex=line[i];
            if (ex=='^')
            {
              flag=true;
              continue;
            }
            if (!flag)
            {
              mono+=good?CToS(ex):" ";
              continue;
            }
            else
            {
              flag=false;
            }
            if (ex=='E')
            {
              good=true;
              need=true;
              continue;
            }
            good=false;
          }
          if (!need)break;
          //qDev.SetColor(0xffffffff);
          qDev.SetColor(0xff000000);
          //qDev.SetColor(0xff505050);
          //qDev.SetColor(0xffa8a8a8);
          QapQ3Text::DrawQapText(&qDev,font,x+1,y-1,mono);
          //QapQ3Text::DrawQapText(&qDev,font,x-1,y+1,mono);
          //QapQ3Text::DrawQapText(&qDev,font,x-1,y-1,mono);
          //QapQ3Text::DrawQapText(&qDev,font,x+1,y+1,mono);
        }
        while (false);

        QapQ3Text::DrawQapText(&qDev,font,x,y,line);
        y+=dy;
      }
      Clock.Stop();
      QapQ3Text::DrawQapText(&qDev,font,get_pos(con).x-dx,y,"^1.^0=====[render:"+FToS(Clock.MS())+"]=====^1.");
    }
  }
public:
  typedef TFieldPtr::TInfo TFieldPtrInfo;
  class TCallBack:public OutDevice::ICallBack
  {
  public:
    QapKeyboard&KB;
    TFieldPtrInfo Info;
    bool UseInfo;
    //DevTools*pTools;
    IEnvRTTI*pEnv;
    TBranch Branch;
    bool SelectBranch;
    bool DestBranch;
    TCallBack(QapKeyboard&KB):KB(KB),UseInfo(false),pEnv(nullptr),SelectBranch(false),DestBranch(false) {}
  public:
    void MicroCode(OutDevice&OD)
    {
      auto&top=OD.branch.top;
      auto&branch=OD.branch;
      UseInfo=true;
      if (true)do
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
            for (int i=0;i+1<arr.size();i++)
            {
              auto&ex=arr[i+1];
              auto&ax=arr[i+0];
              auto*pCmd=ax.pCmd;
              if (!pCmd)
              {
                TCove::TContext tmp={{ex.pType,ex.pValue},{ex.pType,ex.pValue},0};
                Context=tmp;
              }
              else
              {
                pCmd->Use(Cove);
              }
            }
            Info.set(TTypeStruct::UberCast(Context.Object.pType),Context.Object.pValue,Context.Field.pType,Context.Offset);
          }
          OD.pop();
        }
        while (false);
    }
    void BranchCode(OutDevice&OD)
    {
      auto&top=OD.branch.top;
      auto&branch=OD.branch;
      if (true)do
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
            if (branch.size()>1)
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
            for (int i=2;i+1<arr.size();i++)
            {
              auto&ex=arr[i+1];
              auto&ax=arr[i+0];
              auto*pCmd=ax.pCmd;
              Conv.Context=ax;
              if (!pCmd)
              {
                QapDebugMsg("WTF?");
                continue;
              }
              pCmd->Use(Conv);
              QapAssert(Conv.CV.dev.ok)
              Branch.Items.push_back(std::move(Conv.pCmd));
              Head.Context=ax;
              pCmd->Use(Head);
            }
            Branch.Code=std::move(Head.out);
            Branch.Root=FPI;
          }
          OD.pop();
        }
        while (false);
    }
  public:
    void OnVar(OutDevice&OD,LineField&Field)
    {
      if (!KB.OnDown(VK_CONTROL))return;
      BranchCode(OD);
    }
    void OnType(OutDevice&OD,LineField&Field)
    {
      if (!KB.OnDown(VK_CONTROL))return;
      MicroCode(OD);
    }
    void OnValue(OutDevice&OD,LineField&Field)
    {
      auto&top=OD.branch.top;
      OnValueAll(OD,Field);
      if (SelectBranch||DestBranch)
      {
        BranchCode(OD);
      }
      for (;;)
      {
        auto&Down=KB.Down;
        bool flag=false;
        flag=flag||KB.News;
        flag=flag||Down[VK_BACK];
        flag=flag||Down[VK_DELETE];
        if (!flag)break;
        if ("string"!=*Field.pType)break;
        auto&value=*(string*)top.pValue;
        if (Down[VK_BACK])
        {
          Down[VK_BACK]=false;
          if (!value.empty())value.resize(value.size()-1);
          break;
        }
        if (Down[VK_DELETE])
        {
          Down[VK_DELETE]=false;
          value="";
          break;
        }
        if (KB.News)
        {
          value+=CToS(KB.LastChar);
          KB.News=false;
        }
        break;
      }
      auto&Down=KB.Down;
      auto&DownC=KB.Down[VK_CONTROL];
      if (!KB.Down[VK_CONTROL]&&!Down[VK_DELETE]&&!Down[VK_DIVIDE]&&!KB.News)return;
      if ("bool"==*Field.pType)if (KB.Changed[VK_CONTROL])if (DownC)
          {
            auto&value=*(bool*)top.pValue;
            value=!value;
            DownC=false;
          }
      auto&DownLC=KB.Down[VK_LCONTROL];
      auto&DownRC=KB.Down[VK_RCONTROL];
      auto&DownDel=KB.Down[VK_DELETE];
      auto&DownDiv=KB.Down[VK_DIVIDE];
      //const auto OnDownLC=KB.OnDown(VK_LCONTROL);
      //const auto OnDownRC=KB.OnDown(VK_RCONTROL);
      if ("int"==*Field.pType)
      {
        auto&value=*(int*)top.pValue;
        if (DownLC)value+=+1;
        if (DownRC)value+=-1;
        if (DownDel)value=0;
        for (;;)
        {
          if (KB.OnDown(VK_BACK))
          {
            value/=10;
          }
          if (KB.News)if (KB.LastChar=='-')
            {
              value*=-1;
              KB.News=false;
            }
          if (KB.News)if ((KB.LastChar>='0')&&(KB.LastChar<='9'))
            {
              value*=10;
              value+=value<0?-(KB.LastChar-'0'):KB.LastChar-'0';
              KB.News=false;
            }
          break;
        }
      }
      if ("char"==*Field.pType)
      {
        auto&value=*(char*)top.pValue;
        if (DownLC)value+=+1;
        if (DownRC)value+=-1;
        if (DownDel)value=0;
        if (KB.News)
        {
          value=KB.LastChar;
        }
      }
      if ("uchar"==*Field.pType)
      {
        auto&value=*(uchar*)top.pValue;
        if (DownLC)value+=+1;
        if (DownRC)value+=-1;
        if (DownDel)value=0;
      }
      if ("real"==*Field.pType)
      {
        auto&value=*(real*)top.pValue;
        if (DownLC)value+=+1.0;
        if (DownRC)value+=-1.0;
        if (DownDel)value=0.0;
        if (DownDiv)value=int(value);
      }
      if ("float"==*Field.pType)
      {
        auto&value=*(float*)top.pValue;
        if (DownLC)value+=+1.0f;
        if (DownRC)value+=-1.0f;
        if (DownDel)value=0.0f;
        if (DownDiv)value=int(value);
      }
      DownC=false;
      DownLC=false;
      DownRC=false;
      DownDel=false;
      DownDiv=false;
    }
    void OnSys(OutDevice&OD,LineField&Field)
    {
      auto&top=OD.branch.top;
      auto&Down=KB.Down;
      OnSysAll(OD,Field);
      if (SelectBranch)
      {
        BranchCode(OD);
      }
    }
  public:
    struct KeyTools_WeakPtrToField
    {
      bool Passed;
      KeyTools_WeakPtrToField():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.KB.Down;
        if (!Down[VK_LCONTROL])return;
        auto*p=TTypeWeakPtr::UberCast(top.pType);
        if (p)
        {
          Passed=true;
          CB.DestBranch=true;
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
        TRawPtr raw_ptr=QTD.DestBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          auto&value=*(TWeakPtr<IEsoteric>*)pValue;
          // under construction
          return;
          // under designed
          vector<TBranch> WeakPtrs;
          WeakPtrs.push_back(std::move(CB.Branch));
          auto&arr=WeakPtrs;
          for (int i=0;i<arr.size();i++)
          {
            auto&ex=arr[i];
            auto raw_ptr=ex.GetRawPtr();
            if (!raw_ptr.IsValid())continue;
            auto*pValue=raw_ptr.pValue;
            auto*pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
            if (!pType||!pValue)continue;
            //nothing?
          }
          //value=nullptr;
        }
      }
    };
    struct KeyTools_SelfPtrConnect
    {
      bool Passed;
      KeyTools_SelfPtrConnect():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.KB.Down;
        if (!Down[VK_CONTROL])return;
        auto*p=TTypeSelfPtr::UberCast(top.pType);
        if (p)
        {
          Passed=true;
          CB.SelectBranch=true;
        }
      }
      static TWeakPtr<IEsoteric>*get_weakptr(const TRawPtr&raw_ptr,TTypeWeakPtr*&pType)
      {
        auto*pValue=raw_ptr.pValue;
        pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          return (TWeakPtr<IEsoteric>*)pValue;
        }
        return nullptr;
      }
      static TSelfPtr<IEsoteric>*get_selfptr(const TRawPtr&raw_ptr,TTypeSelfPtr*&pType)
      {
        auto*pValue=raw_ptr.pValue;
        pType=TTypeSelfPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          return (TSelfPtr<IEsoteric>*)pValue;
        }
        return nullptr;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
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
        if (!pDest||!pSource||!pDestType||!pSourceType)return;
        auto*pDestElemType=pDestType->ElementType.get();
        auto*pSourceElemType=pSourceType->ElementType.get();
        if (!pDestElemType||!pSourceElemType)return;
        bool flag=pSourceElemType->IsBasedOn(pDestElemType);
        if (!flag)return;
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
      KeyTools_WeakPtrClear():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.KB.Down;
        if (Down[VK_DELETE])
        {
          auto*p=TTypeWeakPtr::UberCast(top.pType);
          if (p)
          {
            Down[VK_DELETE]=false;
            Passed=true;
            CB.SelectBranch=true;
          }
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeWeakPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          auto&value=*(TWeakPtr<IEsoteric>*)pValue;
          value=nullptr;
        }
      }
    };
    struct KeyTools_WeakPtrConnect
    {
      bool Passed;
      KeyTools_WeakPtrConnect():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        if (!CB.KB.Down[VK_RCONTROL])return;
        auto*p=TTypeWeakPtr::UberCast(top.pType);
        if (p)
        {
          Passed=true;
          CB.SelectBranch=true;
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
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
        if (!pDest||!pSource||!pDestType||!pSourceType)return;
        auto*pDestElemType=pDestType->ElementType.get();
        auto*pSourceElemType=pSourceType->ElementType.get();
        if (!pDestElemType||!pSourceElemType)return;
        bool flag=pSourceElemType->IsBasedOn(pDestElemType);
        if (!flag)return;
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
      KeyTools_VectorClear():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        if (CB.KB.Down[VK_DELETE])
        {
          auto*p=TTypeVector::UberCast(top.pType);
          if (p)
          {
            CB.KB.Down[VK_DELETE]=false;
            Passed=true;
            CB.SelectBranch=true;
          }
        }
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeVector::UberCast(raw_ptr.pType);
        if (pValue&&pType)
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
      KeyTools_VectorIncDec():dVecCount(0) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.KB.Down;
        if (!Down[VK_SUBTRACT]&&!Down[VK_ADD])return;
        auto*p=TTypeVector::UberCast(top.pType);
        if (!p)return;
        dVecCount=(Down[VK_SUBTRACT]?-1:0)+(Down[VK_ADD]?+1:0);
        Down[VK_SUBTRACT]=false;
        Down[VK_ADD]=false;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!dVecCount)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeVector::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          auto*pVecAPI=pType->VecAPI.get();
          int Count=pVecAPI->GetCount(pValue);
          Count+=dVecCount;
          if (Count<0)Count=0;
          pVecAPI->SetCount(pValue,Count);
        }
      }
    };
    struct KeyTools_FieldPtrClear
    {
      bool Passed;
      KeyTools_FieldPtrClear():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.KB.Down;
        if (!Down[VK_DELETE])return;
        auto*p=TTypeFieldPtr::UberCast(top.pType);
        if (!p)return;
        Down[VK_DELETE]=false;
        Passed=true;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeFieldPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          auto&value=*(TFieldPtr*)pValue;
          value.off();
        }
      }
    };
    struct KeyTools_AutoPtrClear
    {
      bool Passed;
      KeyTools_AutoPtrClear():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto&Down=CB.KB.Down;
        if (!Down[VK_DELETE])return;
        auto*p=TTypeAutoPtr::UberCast(top.pType);
        if (!p)return;
        Down[VK_DELETE]=false;
        Passed=true;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeAutoPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
        {
          auto&value=*(TAutoPtr<void>*)pValue;
          value=nullptr;
        }
      }
    };
    struct KeyTools_AutoPtrSelectBase
    {
      bool Passed;
      KeyTools_AutoPtrSelectBase():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD)
      {
        auto&top=OD.branch.top;
        auto OnDown=CB.KB.OnDown(VK_CONTROL);
        if (!OnDown)return;
        auto*p=TTypeAutoPtr::UberCast(top.pType);
        if (!p)return;
        Passed=true;
        CB.SelectBranch=true;
      }
      void After(QapTreeDebugger&QTD,TCallBack&CB)
      {
        if (!Passed)return;
        TRawPtr raw_ptr=QTD.SelectBranch.GetRawPtr();
        auto*pValue=raw_ptr.pValue;
        auto*pType=TTypeAutoPtr::UberCast(raw_ptr.pType);
        if (pValue&&pType)
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
  TBranch*GetSelectBranchId()
  {
    if (SelectBranchId<0)return nullptr;
    if (SelectBranchId>=Branches.size())return nullptr;
    auto&ex=Branches[SelectBranchId];
    return &ex;
  }
public:
  static int get_field_index_in_type(TType*pType,const string&field)
  {
    auto*p=Sys$$<SelfClass>::metatype::UberCast(pType);
    if (!p)return -1;
    auto&arr=p->Members;
    for (int i=0;i<arr.size();i++)
    {
      const auto&ex=arr[i];
      if (ex.Name==field)
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
    if (field_select_index<0)
    {
      auto*p=pTypeThis.get();
      if (!p)
      {
        QapAssert(p);
        return -1;
      }
      field_select_index=get_field_index_in_type(p,"Select");
    }
    return field_select_index;
  }
  void AddLine(int indent,const string&text)
  {
    TIndentStrLine tmp;
    tmp.indent=indent;
    tmp.text=text;
    lines.push_back(std::move(tmp));
  }
  void Update(t_context&con)
  {
    //if(need_init)
    //{
    //  //
    //  //ADDVAR(TResourceHolder,ResHolder,DEF,$,$)\
    //  //ADDVAR(TWeakPtr<QapFontObject>,FontObject,DEF,$,$)\
    //  //ADDVAR(bool,need_init,SET,true,$)\
    //  //
    //  need_init=false;
    //  FontObject=con.root.ResList.AddItem<QapFontObject>(con.Env,ResHolder,"QapTreeDebugger::FontObject");
    //  FontObject->SetToDef();
    //  FontObject->Run(con.Env,&con.root.D9Dev);
    //}
    if (!con.root.SysRes.FontObj)return;
    QapFont&font=con.root.SysRes.FontObj->Font;
    QapKeyboard&Keyboard=con.root.win.Keyboard;
    QapClock Clock;
    Clock.Start();
    if (!pQapTreeDebugger)
    {
      auto*p=Sys$$<SelfClass>::GetRTTI(con.Env);
      pQapTreeDebugger=p;
    }
    if (!pTBranch)
    {
      auto*p=Sys$$<TBranch>::GetRTTI(con.Env);
      pTBranch=p;
    }
    if (true)
    {
      zD-=64*Sign(con.root.win.zDelta);
      vec2i pos=con.root.win.GetMousePos();
      mpos=pos;
    }
    if (true)
    {
      Selector.weak_update<0>(con.Env,*this);
      //QapDebugMsg("OnDownSelect.UpdateEx();");//OnDownSelect.UpdateEx();
    }
    if (Keyboard.Down[VK_F10])
    {
      Select.off();
      Select.ConnectEx(con.Env,con.root);
      Keyboard.Down[VK_F10]=false;
    }
    if (NeedClearPages)
    {
      pages.Items.clear();
      NeedClearPages=false;
    }
    if (NeedClearBranches)
    {
      Branches.clear();
      NeedClearBranches=false;
    }
    if (AutoUpdateBranchesHead)
    {
      auto&arr=Branches;
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.UpdateCode();
      }
    }
    if (Keyboard.Down[VK_F3])
    {
      Keyboard.Down[VK_F3]=false;
      SelectBranchEnabled=!SelectBranchEnabled;
    }
    if (Keyboard.Down[VK_F1])if (SelectBranchEnabled&&!Branches.empty())
      {
        Keyboard.Down[VK_F1]=false;
        int count=Branches.size();
        auto&id=SelectBranchId;
        id--;
        if (id<0)id=count-(-id-(-id/count)*count);
        id=id%count;
      }
    if (Keyboard.Down[VK_F2])if (SelectBranchEnabled&&!Branches.empty())
      {
        Keyboard.Down[VK_F2]=false;
        int count=Branches.size();
        auto&id=SelectBranchId;
        id++;
        if (id<0)id=count-(-id-(-id/count)*count);
        id=id%count;
      }
    if (Keyboard.Down[VK_F7])
    {
      con.root.win.FullScreen=true;
      Keyboard.Down[VK_F7]=false;
      Select.off();
      Selector.base=nullptr;
    }
    /*if(Keyboard.Down[VK_F6])
    {
      Keyboard.Down[VK_F6]=false;
      MaxDepth=5;
      Select.off();
      auto*ex=Program.get();
      Select.ConnectEx(Env.Env,*ex);
    }*/
    if (Keyboard.OnDown(VK_HOME))
    {
      const int Steep_zD=64;
      //Keyboard.Down[VK_HOME]=false;
      zD=0;
    }
    if (Keyboard.OnDown(VK_END))
    {
      const int Steep_zD=64;
      //Keyboard.Down[VK_END]=false;
      int h=(lines.size()+empty_lines+omitted_lines+3)*font.Info.Coords[0].y;
      h-=con.root.win.GetClientSize().y;
      zD=(h/Steep_zD)*Steep_zD;
    }
    if (Keyboard.OnDown(VK_NEXT))
    {
      const int Steep_zD=64;
      //Keyboard.Down[VK_NEXT]=false;
      int dy=font.Info.Coords[0].y;
      int h=con.root.win.GetClientSize().y-3*dy;
      zD+=h;
    }
    if (Keyboard.OnDown(VK_PRIOR))
    {
      const int Steep_zD=64;
      //Keyboard.Down[VK_PRIOR]=false;
      int dy=font.Info.Coords[0].y;
      int h=con.root.win.GetClientSize().y-3*dy;
      zD-=h;
    }
    static bool enabled_auto_scroll_bounce=true;
    if (enabled_auto_scroll_bounce&&!lines.empty())
    {
      const int Steep_zD=64;
      int dy=font.Info.Coords[0].y;
      int pwcsy=con.root.win.GetClientSize().y;
      int h=pwcsy-3*dy;
      int min_h=-h;
      int max_h=(lines.size()+empty_lines+omitted_lines+3)*dy;
      zD=Clamp<int>(zD,min_h,max_h);
    }
    //if(con.root.win.Keyboard.Down[VK_ESCAPE])con.root.win.Close();//NeedClose=true;
    /*if(NeedCallWindowMode)
    {
      NeedCallWindowMode=false;
      auto*ex=Program.get();
      auto&q=ex->WindowGetQuad();
      q.x=int(-4);
      q.y=int(0);
      q.w=int(687);
      q.h=int(728);
      ex->WindowUpdateMode();
    }*/
    for (int i=0;i<3;i++)if (!lines.empty())lines.pop_back();
    if (!TextAutoUpdate)
    {
      if (Keyboard.Down[VK_F12])
      {
        TextAutoUpdate=true;
        Keyboard.Down[VK_F12]=false;
      }
    }
    else
    {
      TCallBack CB(con.root.win.Keyboard);
      CB.pEnv=&con.Env;
      OutDevice::TDevContext DevContext=
      {
        font,mpos,get_pos(con),CB,MaxDepth,
        con.root.win.GetClientSize().y,
        InScreenOptimization,
        SkipCommaInVector,
        false,false,0,0
      };
      OutDevice OD(DevContext);
      OD.lines.reserve(300);
      OD.branch.items.reserve(32);
      auto&top=OD.branch.top;
      if (SelectBranchEnabled)
      {
        string end_line;
        auto*pBranch=GetSelectBranchId();
        if (pBranch||true)
        {
          auto add_text=[&OD,&font](const string&text)->string
          {
            OD.AddText(text);
            return text;
          };
          string Code;
          auto add_code=[&]()->string
          {
            if (pBranch&&pBranch->Root)
            {
              TOutDevEx::TContext Context;
              Context.pType=pBranch->Root.getType();
              Context.pValue=pBranch->Root.getValue();
              TOutDevEx::TCmdHeadVisitor Head;
              Head.pContext=&Context;
              QapTreeDebugger::TBranch::TMeCallBack MCB(Head,*pBranch,con.root.win.Keyboard);
              OD.AddWithECB(MCB);
            }
            return !pBranch?"pBranch = nullptr_t(nullptr)":"Root = nullptr_t(nullptr)";
          };
          string inner_code=pBranch?IToS(SelectBranchId+1)+" of "+IToS(Branches.size()):"none";
          string a=add_text("^3-----^2{ ^0Branch["+inner_code+"] ^2}^3-----");
          string b=add_code();
          string c=add_text("^3"+[&a](int c)->string {string s;s.resize(c);for (int i=0;i<c;i++)
          {
            s[i]='-';
          }
          return s;}(QapQ3Text::ToNormal(a).size()));
          end_line=c;
          if (pBranch)OD.DevContext.MaxDepth=MaxDepth+pBranch->Items.size();
        }
        TBranch::TOutDevBuff buff(OD);
        bool flag=pBranch&&buff.grab(con.Env,pBranch,pTBranch.get());
        if (flag)
        {
          buff.push();
          TProtoToolsEx ProtoTools(OD,top.pValue);
          top.pType->Use(ProtoTools);
          buff.pop();
          empty_lines=OD.DevContext.empty_lines;
          omitted_lines=OD.DevContext.omitted_lines;
        }
        else
        {
          OD.AddText("error");
        }
        OD.AddText(end_line);
      }
      else
      {
        //
        if (!Select)
        {
          lines.clear();
          return;
        };
        //
        int field_select_index=get_Select_field_index_in_QapTreeDebugger(pQapTreeDebugger);
        if (field_select_index<0)TextAutoUpdate=false;
        //
        top.pValue=this;
        top.pType=pQapTreeDebugger.get();
        //
        OutDevice::TMemberID tmp(field_select_index);
        OD.push(&tmp);
        TProtoToolsEx ProtoTools(OD,top.pValue);
        top.pType->Use(ProtoTools);
        OD.pop();
        empty_lines=OD.DevContext.empty_lines;
        omitted_lines=OD.DevContext.omitted_lines;
      }
      lines=std::move(OD.lines);
      if (CB.UseInfo)
      {
        auto&Info=CB.Info;
        TPage page;
        page.pos=get_pos(con);
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
      if (CB.Branch.Root)do
        {
          auto*pBranch=GetSelectBranchId();
          //auto&tools=*Tools.get();
          if (CB.SelectBranch||CB.DestBranch)
          {
            QapAssert(CB.SelectBranch!=CB.DestBranch);
            if (CB.DestBranch)DestBranch.Branch=std::move(CB.Branch);
            if (CB.SelectBranch)SelectBranch.Branch=std::move(CB.Branch);
            Selector.change_base_ex(SelectBranch);
            /*QapDebugMsg("2014.06.04\nno way.");
            if(!OnDownSelect.Selector)break;
            auto*pSelector=OnDownSelect.Selector.get();
            pSelector->change_base_ex(SelectBranch);*/
            //--==>>CallAfterAllKeyTools
            CB.CallAfterAllKeyTools(*this);
            //<<==--CallAfterAllKeyTools
            break;
          }
          if (con.root.win.Keyboard.Down[VK_LCONTROL])
          {
            Branches.push_back(std::move(CB.Branch));
          }
          if (con.root.win.Keyboard.Down[VK_RCONTROL])
          {
            if (pBranch)
            {
              (*pBranch)=std::move(CB.Branch);
            }
            else
            {
              Branches.push_back(std::move(CB.Branch));
            }
          }
          break;
        }
        while (false);
    }
    Clock.Stop();
    {
      int count=0;
      for (int i=0;i<lines.size();i++)
      {
        count+=lines[i].text.size();
      }
      AddLine(0,"=====[bytes:"+IToS(count)+"]=====");
    }
    AddLine(0,"=====[lines:"+IToS(lines.size())+"]=====");
    AddLine(0,"=====[update:"+FToS(Clock.MS())+"]=====");
    pages.Update();
    branches_update();
  }
  void branches_update()
  {
    auto&arr=Branches;
    int last=0;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (ex.NeedRemove)continue;
      if (last!=i)
      {
        auto&ax=arr[last];
        ax=std::move(ex);
      }
      last++;
    }
    if (last==arr.size())return;
    arr.resize(last);
  }
};

#include "GUI_Panel.inl"

class T20140605PtrItem
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20140605PtrItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<SelfClass>,Next,DEF,$,$)\
ADDEND()
//=====+>>>>>T20140605PtrItem
#include "QapGenStruct.inl"
//<<<<<+=====T20140605PtrItem
public:
};

class TWeakPtrTest20140605:public IRenderProgram
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWeakPtrTest20140605)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(T20140605PtrItem,a,DEF,$,$)\
ADDVAR(T20140605PtrItem,b,DEF,$,$)\
ADDVAR(T20140605PtrItem,c,DEF,$,$)\
ADDVAR(TWeakPtr<T20140605PtrItem>,head,DEF,$,$)\
ADDEND()
//=====+>>>>>TWeakPtrTest20140605
#include "QapGenStruct.inl"
//<<<<<+=====TWeakPtrTest20140605
public:
  void Render(t_context&con)
  {
    auto&qDev=con.root.qDev;
    qDev.BindTex(0,0);
    qDev.SetColor(QapColor(128,0,0,0));
    qDev.DrawCircle(vec2i(0,0),150,0,1,128);
  }
  void Update(t_context&con)
  {

  }
};

class TDay20140605TestV00:public IRenderProgram
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140605TestV00)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(vector<vec2i>,points,DEF,$,$)\
ADDVAR(real,size,SET,64.0,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDVAR(bool,DrawQuadAtMPos,SET,true,$)\
ADDEND()
//=====+>>>>>TDay20140605TestV00
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140605TestV00
public:
  void Render(t_context&con)
  {
    auto&qDev=con.root.qDev;
    auto&pd3d9=con.root.D9Dev;
    qDev.SetColor(color);
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.DrawCircle(pos,size,0,1,16);
    if (con.root.SysRes.BallTex)
    {
      qDev.BindTex(0,&con.root.SysRes.BallTex->Tex);
    }
    qDev.BeginBatch();
    qDev.DrawPolyLine(points,3,false);
    for (int i=0;i<points.size();i++)qDev.DrawQuadWithHalfPixelOffset(points[i].x,points[i].y,16,16);
    qDev.EndBatch();
    auto mpos=con.root.win.GetMousePos();
    if (DrawQuadAtMPos)
    {
      qDev.DrawQuad(mpos.x,mpos.y,16,16);
    }
    qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    auto&kb=con.root.win.Keyboard;
    auto mpos=con.root.win.GetMousePos();
    {
      if (kb.Down[mbLeft]&&kb.Changed[mbLeft])
      {
        bool ok=true;
        for (int i=0;i<points.size();i++)
        {
          if ((points[i]-mpos).Mag()*2<(16+16))
          {
            ok=false;
            points[i]=mpos;
          }
        }
        if (ok)points.push_back(mpos);
      }
      if (kb.Down[mbLeft]&&!kb.Changed[mbLeft])
      {
        for (int i=0;i<points.size();i++)
        {
          if ((points[i]-mpos).Mag()*2<(16+16))
          {
            points[i]=mpos;
          }
        }
      }
    }
    int gg=1;
  }
};

class TDay20140605BookV00;
class TDay20140605Book;

#include "GeomTools.h"

class IBookPage
{
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
  struct t_context
  {
    IEnvRTTI&Env;
    TD3DGameBoxBuilder&root;
    QapKeyboard&kb;
    QapDev&qDev;
    TDay20140605BookV00&head;
    TDay20140605Book&book;
    vec2i pos;
    vec2i size;
    vector<TDay20140605Book*>&path;
    IRenderProgram::t_context&context;
    t_context fork()const
    {
      return *this;
    }
    template<class TRawRect>
    t_context&use_rect(TRawRect&rect)
    {
      pos=pos+rect.pos;
      size=rect.get_size();
      return *this;
    }
    template<class TRawRect>
    t_context make_sub_context(TRawRect&rect)
    {
      return fork().use_rect(rect);
    }
    template<int>
    vec2i weak_get_mpos()
    {
      return root.win.GetMousePos()-pos;
    }
    vec2i get_mpos()
    {
      return weak_get_mpos<0>();
    }
    template<int>
    bool weak_is_head_book()
    {
      if (&head==nullptr)return true;
      return &head.book==&book;
    }
    bool is_head_book()
    {
      return weak_is_head_book<0>();
    }
    template<int>
    QapFontObject*weak_get_head_book_fontgen()
    {
      if (&head==nullptr)return nullptr;
      return head.book.pFontGen.get();
    }
    QapFontObject*get_head_book_fontgen()
    {
      return weak_get_head_book_fontgen<0>();
    }
    bool is_hovered()
    {
      return PointInQuad(get_mpos(),vec2i_zero,size);
    }
    string GetCurBranchAsStr(void*pThis,int start_id=0)
    {
      QapAssert(pThis==context.dev.branch.top.pValue);
      OutDevice::TCmdHeadVisitor Head;
      auto&arr=context.dev.branch;
      for (int i=start_id;i<arr.size();i++)
      {
        auto&ax=arr[i];
        Head.Context=ax;
        ax.pCmd->Use(Head);
      }
      return Head.out;
    }
    vec2i ScreenSpaceToPageSpace(const vec2i&p)
    {
      return p-pos;
    }
    vec2i PageSpaceToScreenSpace(const vec2i&p)
    {
      return p+pos;
    }
  };
  virtual void Render(t_context&con) {}
  virtual void Update(t_context&con) {}
};

struct t_book_path_scope
{
  IBookPage::t_context&con;
  bool skip;
  TDay20140605Book*pBook;
  t_book_path_scope(IBookPage::t_context&con):con(con)
  {
    pBook=&con.book;
    skip=!con.path.empty()&&con.path.back()==pBook;
    if (skip)return;
    con.path.push_back(pBook);
  }
  ~t_book_path_scope()
  {
    if (skip)return;
    bool f0=!con.path.empty();
    if (!f0)
    {
      *(int*)nullptr=0;
    }
    bool f1=con.path.back()==pBook;
    QapAssert(f1);
    if (!f1)
    {
      *(int*)nullptr=0;
    }
    con.path.pop_back();
  }
};

class TDay20140605Book
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140605Book)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResItem,DEF,$,$)\
ADDVAR(TWeakPtr<QapFontObject>,pFontGen,DEF,$,$)\
ADDVAR(bool,AutoInitIfItIsRootBook,SET,true,$)\
ADDVAR(bool,CopyFontGenFromRootBook,SET,true,$)\
ADDVAR(bool,need_close,DEF,$,$)\
ADDVAR(bool,need_disable,DEF,$,$)\
ADDVAR(bool,need_init,DEF,$,$)\
ADDVAR(bool,full_screen,DEF,$,$)\
ADDVAR(int,head_border_size,SET,4,$)\
ADDVAR(int,border_size,SET,2,$)\
ADDVAR(QapColor,border_color,DEF,$,$)\
ADDVAR(int,page_id,DEF,$,$)\
ADDVAR(vector<TAutoPtr<IBookPage>>,pages,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140605Book
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140605Book
public:
  typedef IBookPage::t_context t_context;
public:
  static void DrawBorder(QapDev&qDev,const vec2i&pos,const vec2i&size,int ls)
  {
    qDev.DrawRectAsQuad(pos,size+vec2i(1,1)*ls,ls);
  }
  struct t_book_info
  {
    vec2i body_pos;
    vec2i body_size;
    vec2i header_pos;
    vec2i header_size;
  };
  t_book_info get_header_info(const vec2i&pos,const vec2i&size)
  {
    t_book_info tmp;
    if (!pFontGen)return tmp;
    auto&font=pFontGen->Font;
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy/2;
    int hbs=head_border_size;
    auto&arr=pages;
    tmp.header_size=vec2i(size.x,border_size+hbs+cy+hbs);
    tmp.header_pos=pos+vec2i(-size.x+tmp.header_size.x,+size.y-tmp.header_size.y)/2;
    tmp.body_pos=pos+vec2i(0,-tmp.header_size.y/2);
    tmp.body_size=size-vec2i(border_size*2,tmp.header_size.y+border_size*2);
    return tmp;
  }
  void DrawOldText(QapDev&qDev,const string&text,const vec2i&pos)
  {
    if (!pFontGen)return;
    qDev.BindTex(0,nullptr);
    auto&font=pFontGen->Font;
    //string text="TDay20140605Book";
    int L=QapQ3Text::GetLength(font,text);
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy/2;
    vec2i p=pos+vec2i(-L/2,-cy);
    qDev.SetColor(0xffffffff);
    qDev.DrawQuad(p.x+L/2,p.y,L,cy,0);
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y+hcy),text);
  }
  void DrawHeader(QapDev&qDev,const vec2i&mpos,const vec2i&pos,const vec2i&size)
  {
    if (!pFontGen)return;
    auto&font=pFontGen->Font;
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy/2;
    int hbs=head_border_size;
    auto&arr=pages;
    vec2i curpos=pos+vec2i(-size.x/2,-size.y/2+size.y)+vec2i(0,border_size);
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (!ex)continue;
      auto*ptr=ex.get();
      string text=ptr->Caption;
      //
      int L=QapQ3Text::GetLength(font,text);
      vec2i s=vec2i(L+hbs+hbs,hbs+hbs+cy);
      vec2i p=curpos+s/2;
      //
      bool ok=CD_Rect2Point(p-s/2,p+s/2,mpos);
      qDev.SetColor(border_color);
      qDev.BindTex(0,nullptr);
      DrawBorder(qDev,p,s,border_size);
      //DrawText(Text);
      qDev.SetColor(ok?0xE0ffffff:0x80ffffff);
      if (page_id==i)
      {
        qDev.SetColor(0xffffffff);
      }
      qDev.DrawQuad(p.x,p.y,L,cy,0);
      qDev.BindTex(0,&pFontGen->Tex);
      qDev.SetColor(0xff000000);
      QapQ3Text::DrawQapText(&qDev,font,int(p.x-L/2),int(p.y+hcy),text);
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
    t_book_path_scope scope(con);
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.qDev,
      con.head,
      *this,
      con.pos,
      con.size,
      con.path,
      con.context
    };
    auto*ptr=pages[page_id].get();
    ptr->Render(context);
  }
  void DoSelectPage(t_context&con)
  {
    if (!pFontGen)return;
    auto&kb=con.kb;
    bool need_remove=kb.Down[VK_CONTROL]&&kb.OnDown(VK_F4);
    bool need_select=kb.OnDown(mbLeft);
    bool need_full_screen=kb.OnDown(VK_F11);
    if (!need_select&&!need_remove&&!need_full_screen)return;
    auto&font=pFontGen->Font;
    auto mpos=con.root.win.GetMousePos();
    auto cy=font.Info.Coords[0].y;
    auto hcy=cy/2;
    int hbs=head_border_size;
    auto&arr=pages;
    vec2i curpos=con.pos+vec2i(-con.size.x,+con.size.y)/2+vec2i(0,border_size);
    if (need_full_screen)
    {
      vec2i s=vec2i(con.size.x,hbs+hbs+cy);
      if (PointInQuad(mpos,curpos+s/2,s))
      {
        full_screen=true;
      }
    }
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (!ex)continue;
      auto*ptr=ex.get();
      string text=ptr->Caption;
      //
      int L=QapQ3Text::GetLength(font,text);
      vec2i s=vec2i(L+hbs+hbs,hbs+hbs+cy);
      vec2i p=curpos+s/2;
      //
      bool ok=CD_Rect2Point(p-s/2,p+s/2,mpos);
      if (ok)
      {
        if (need_select)page_id=i;
        if (need_remove)
        {
          ex->NeedRemove=true;
        }
        return;
      }
      //
      curpos.x+=s.x+border_size;
    }
  }
  template<int>
  void DoFullScreen(t_context&con)
  {
    if (!full_screen)return;
    con.head.new_path=con.GetCurBranchAsStr(this,con.head.branch_size);
    full_screen=false;
  }
  void DoMovePageContent(t_context&con)
  {
#define F(COND)if(COND)return;
    F(pages.empty());
    F(page_id<0);
    F(page_id+1>pages.size());
    F(!pages[page_id]);
#undef F
    t_book_path_scope scope(con);
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.qDev,
      con.head,
      *this,
      con.pos,
      con.size,
      con.path,
      con.context
    };
    auto*ptr=pages[page_id].get();
    {
      auto&dev=con.context.dev;
      TOutDevScopeMemberID devscopeMember(dev,ProxySys$$::GET_FIELD_ID::pages);
      TOutDevScopeVecID devscopeVec(dev,page_id);
      TOutDevScopeChunk devscopeChunk(dev);
      ptr->Update(context);
    }
    DoFullScreen<0>(con);
    int gg=1;
  }
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    auto mpos=con.root.win.GetMousePos();
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
    if (!pages.empty())return;
    {
      auto*p=AddItem<TPageWithPageAdder>(Env);
      p->Caption=" + ";
    }
    {
      auto*p=AddItem<TBookPageWithQuit>(Env);
      p->Caption=" X ";
    }
    {
      auto*p=AddItem<TBookPageWithDisable>(Env);
      p->Caption=" _ ";
    }
  }
  void DoClean()
  {
    QapCleanIf(pages,[](TAutoPtr<IBookPage>&ref)
    {
      return ref&&ref->NeedRemove;
    }
              );
  }
  void Update(t_context&con)
  {
    auto&kb=con.kb;
    auto mpos=con.root.win.GetMousePos();
    DoSelectPage(con);
    DoMovePageContent(con);
    DoClean();
    for (int i=0;i<pages.size();i++)
    {
      auto&ex=pages[i];
      if (!ex||!ex->Caption.empty())continue;
      auto&caption=ex->Caption;
      caption=ex.Product.pType->GetFullName();
      bool ok0=remove_first_part_of(caption,"TBookPageWith");
      bool ok1=remove_first_part_of(caption,"TPageWith");
      int gg=1;
    }
    if (!pFontGen&&CopyFontGenFromRootBook)
    {
      pFontGen=con.get_head_book_fontgen();
      if (pages.empty())InitPages<0>(con.Env);
    }
    if (!pFontGen&&AutoInitIfItIsRootBook)if (con.is_head_book())
      {
        need_init=true;
      }
    if (!need_init)return;
    need_init=false;
    InitPages<0>(con.Env);
    if (pFontGen)
    {
      ResItem=std::move(TResourceHolder());
      pFontGen=nullptr;
    }
    auto*p=con.root.ResList.AddItem<QapFontObject>(con.Env,ResItem,"TDay20140605Book::Font");
    pFontGen=p;
    p->SetToDef();
    p->FontGen.Name="FixedSys";
    p->FontGen.Size=10;
    p->Run(con.Env,&con.root.D9Dev);
  }
};

class TRawRect
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRawRect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,case_id,SET,-1,$)\
ADDVAR(int,pid_a,SET,-1,$)\
ADDVAR(int,pid_b,SET,-1,$)\
ADDVAR(vec2i,off_a,DEF,$,$)\
ADDVAR(vec2i,off_b,DEF,$,$)\
ADDVAR(bool,fixed,DEF,$,$)\
ADDVAR(bool,down_a,DEF,$,$)\
ADDVAR(bool,down_b,DEF,$,$)\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(int,w,SET,128.0,$)\
ADDVAR(int,h,SET,64.0,$)\
ADDVAR(int,point_size,SET,16,$)\
ADDVAR(int,line_size,SET,1,$)\
ADDVAR(QapColor,quad_color,SET,QapColor(80,100,100,100),$)\
ADDVAR(QapColor,rect_color,DEF,$,$)\
ADDVAR(QapColor,border_color,SET,QapColor(32,32,32),$)\
ADDVAR(bool,draw_quad,DEF,$,$)\
ADDVAR(bool,draw_rect,SET,true,$)\
ADDVAR(bool,draw_points,SET,false,$)\
ADDEND()
//=====+>>>>>TRawRect
#include "QapGenStruct.inl"
//<<<<<+=====TRawRect
public:
  typedef IBookPage::t_context t_context;
public:
  vec2i get_size()const
  {
    return vec2i(w,h);
  }
  static array<int,2> get_arr_x(int cpx,int px,int w)
  {
    array<int,2> a;
    a[0]=cpx+px-w/2;
    a[1]=a[0]+w;
    return a;
  }
  static int get_new_w(int mpx,int off,int px,int pid)
  {
    return 2*(mpx-off-px)*(pid*2-1);
  }
  static void calc_new_w_and_pos(int mpx,int off,int&w,int&px,int pid)
  {
    int c=mpx-off;
    int k=px-w/2+w*(1-pid);
    w=(c-k)*(pid*2-1);
    px=c+w/2-w*pid;
  }
  void RenderBack(t_context&con)
  {
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    if (!draw_quad)return;
    qDev.SetColor(quad_color);
    qDev.DrawQuadWithHalfPixelOffset(pos+con.pos,w,h);
  }
  void RenderBorder(t_context&con)
  {
    if (!draw_rect)return;
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.SetColor(rect_color);
    auto s=get_size();
    auto a=con.pos+pos-s/2-vec2i(1,1)*line_size/2;
    auto b=a+s+vec2i(1,1)*line_size;
    qDev.DrawRect(a,b,line_size);
  }
  void RenderPoints(t_context&con)
  {
    if (!draw_points)return;
    auto&qDev=con.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    qDev.SetColor(border_color);
    QapDev::BatchScope Scope(qDev);
    auto b=vec2i(1,1)*point_size;
    auto ax=get_arr_x(pos.x,0,w);
    auto ay=get_arr_x(0,pos.y,h);
    for (int i=0;i<2;i++)
    {
      qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],pos.y),b,line_size);
      qDev.DrawRectAsQuad(con.pos+vec2i(pos.x,ay[i]),b,line_size);
      qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],ay[i]),b,line_size);
      qDev.DrawRectAsQuad(con.pos+vec2i(ax[i],ay[1-i]),b,line_size);
    }
    qDev.BindTex(0,nullptr);
  }
  void Render(t_context&con)
  {
    RenderBack(con);
    RenderBorder(con);
    RenderPoints(con);
  }
  void Update(t_context&con)
  {
    UpdateEx(con,pos,get_size());
  }
  static void update_point(
    int&pid,int point_size,
    int mpx,int mpy,
    bool&down,bool d,bool ondown,bool shift,
    vec2i&off,
    int&px,int py,
    int&w,int h,int&cid,int this_cid)
  {
    if (ondown&&!down)
    {
      auto arr_x=get_arr_x(0,px,w);
      auto arr_y=get_arr_x(py,0,h);
      if (this_cid==3)std::swap(arr_y[0],arr_y[1]);
      down=false;
      pid=-1;
      auto mpos=vec2i(mpx,mpy);
      for (int i=0;i<2;i++)
      {
        auto&ex=vec2i(arr_x[i],this_cid>1?arr_y[i]:py);
        if (!ex.dist_less(mpos,point_size/2))continue;
        down=true;
        pid=i;
        cid=this_cid;
        off=mpos-ex;
      }
    }
    if (down&&d&&shift)
    {
      w=get_new_w(mpx,off.x,px,pid);
      auto arr=get_arr_x(0,px,w);
      QapAssert(arr[pid]==mpx-off.x);
    }
    if (down&&d&&!shift)
    {
      auto before=get_arr_x(0,px,w);
      calc_new_w_and_pos(mpx,off.x,w,px,pid);
      auto arr=get_arr_x(0,px,w);
      QapAssert(arr[pid]==mpx-off.x);
      QapAssert(arr[1-pid]==before[1-pid]);
    }
    down=down&&d;
    if (!down)
    {
      pid=-1;
      cid=-1;
    }
  }
  void UpdateEx(t_context&con,const vec2i&hp,const vec2i&hs)
  {
    if (fixed)return;
    if (!con.is_hovered())return;
    auto&kb=con.kb;
    bool d=kb.Down[mbLeft];
    bool ondown=kb.OnDown(mbLeft);
    bool shift=kb.Down[VK_SHIFT];
    auto mpos=con.get_mpos();
    auto&cid=case_id;
#define F(x,y,w,h,id,a)if(cid<0||cid==id)update_point(pid_##a,point_size,mpos.x,mpos.y,down_##a,d,ondown,shift,off_##a,pos.x,pos.y,w,h,cid,id);
    F(x,y,w,h,3,b);
    F(y,x,h,w,3,a);
    F(x,y,w,h,2,a);
    F(y,x,h,w,2,b);
    F(x,y,w,h,0,a);
    F(y,x,h,w,1,a);
#undef F
    if (cid<0||cid==10)
    {
      if (ondown&&!down_a)if (PointInQuad(mpos,hp,hs))
        {
          off_a=mpos-hp;
          down_a=true;
          cid=10;
        }
      if (down_a&&d)
      {
        pos=(mpos-off_a)-(hp-pos);
      }
      down_a=down_a&&d;
      if (!down_a)
      {
        pid_a=-1;
        cid=-1;
      }
    }
  }
};


class TMultyBook
{
public:
  class TBook
  {
  public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBook)OWNER(TMultyBook)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,Caption,DEF,$,$)\
  ADDVAR(bool,NeedRemove,DEF,$,$)\
  ADDVAR(bool,Enabled,SET,true,$)\
  ADDVAR(bool,Moved,SET,true,$)\
  ADDVAR(bool,Visible,SET,true,$)\
  ADDVAR(string,script,DEF,$,$)\
  ADDVAR(TRawRect,rect,DEF,$,$)\
  ADDVAR(TDay20140605Book,book,DEF,$,$)\
  ADDEND()
    //=====+>>>>>TBook
#include "QapGenStruct.inl"
    //<<<<<+=====TBook
  public:
  };
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_NESTED(F)F(TBook)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMultyBook)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TBook>,books,DEF,$,$)\
ADDVAR(bool,AutoClean,SET,true,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(string,script,DEF,$,$)\
ADDEND()
//=====+>>>>>TMultyBook
#include "QapGenStruct.inl"
//<<<<<+=====TMultyBook
public:
  typedef IBookPage::t_context t_context;
public:
  void Render(t_context&con)
  {
    if (!Enabled||!Visible)return;
    auto&arr=books;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (!ex.Enabled||!ex.Visible||ex.NeedRemove)continue;
      RenderBook(con,ex);
    }
  }
  void Update(t_context&con)
  {
    if (!Enabled||!Moved)return;
    if (script=="x")
    {
      int gg=1;
      QapAssert(books.size()==2);
      auto&a=books[0].rect;
      auto&b=books[1].rect;
      int bs=2;
      int cx=con.size.x;
      a.pos.x=-cx/4-bs/2;
      b.pos.x=+cx/4+bs/2;
      a.w=(-4*bs+cx)/2;
      b.w=(-4*bs+cx)/2;
      a.h=-2*bs+con.size.y;
      b.h=-2*bs+con.size.y;
      a.pos.y=0;
      b.pos.y=0;
    }
    if (script=="y")
    {
      int gg=1;
      QapAssert(books.size()==2);
      auto&a=books[0].rect;
      auto&b=books[1].rect;
      int bs=2;
      int cx=con.size.x;
      int cy=con.size.y;
      a.pos.y=-cy/4-bs/2;
      b.pos.y=+cy/4+bs/2;
      a.h=(-4*bs+cy)/2;
      b.h=(-4*bs+cy)/2;
      a.w=-2*bs+cx;
      b.w=-2*bs+cx;
      a.pos.x=0;
      b.pos.x=0;
    }
    auto&arr=books;
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::books);
      for (int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if (!ex.Enabled||!ex.Moved||ex.NeedRemove)continue;
        TOutDevScopeVecID devscopeVec(con.context.dev,i);
        UpdateBook(con,ex);
        ex.NeedRemove=ex.NeedRemove|ex.book.need_close;
        if (!ex.book.need_disable)continue;
        ex.Enabled=false;
        ex.book.need_disable=false;
      }
    }
    if (!AutoClean)return;
    QapCleanIf(arr,[](TBook&ref)
    {
      return ref.NeedRemove;
    }
              );
    if (con.is_hovered()&&con.kb.Down[VK_CONTROL]&&con.kb.OnDown('N'))
    {
      con.kb.Down['N']=false;
      con.kb.Changed['N']=false;
      qap_add_back(books);
    }
  }
  static void RenderBook(t_context&con,TBook&Book)
  {
    auto&book=Book.book;
    auto&rect=Book.rect;
    t_book_path_scope scope(con);
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      book,
      rect.pos,
      rect.get_size(),
      con.path,
      con.context
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
  static void UpdateBook(t_context&con,TBook&ref)
  {
    auto&book=ref.book;
    auto&rect=ref.rect;
    t_book_path_scope scope(con);
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      book,
      rect.pos,
      rect.get_size(),
      con.path,
      con.context
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
    TOutDevScopeMemberID devscope(con.context.dev,TBook::ProxySys$$::GET_FIELD_ID::book);
    book.Update(context);
  }
};

class TBookPageWithMultyBook:public IBookPage
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithMultyBook)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TMultyBook,books,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithMultyBook
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithMultyBook
public:
  void Render(t_context&con)
  {
    books.Render(con);
  }
  void Update(t_context&con)
  {
    if (Caption.empty())Caption="PageWithMultyBook";
    TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::books);
    books.Update(con);
  }
};

struct t_booksys_exec_result
{
  bool ok;
  TRawPtr ptr;
};

t_booksys_exec_result
booksys_branch_exec_v00
(
  IEnvRTTI&Env,TSuperOutDevice&dev,
  TRawPtr&raw_ptr,
  const string&branch,
  vector<TAutoPtr<TOutDev::DevCmd>>&way
);

static bool super_dev_add_way_v00(TSuperOutDevice&dev,vector<TAutoPtr<TOutDev::DevCmd>>&way)
{
  if (!dev.branch.ok)return false;
  for (int i=0;i<way.size();i++)
  {
    auto&ex=way[i];
    auto*pway=ex.get();
    if (pway)
    {
      dev.push(*pway);
      if (dev.branch.ok)continue;
      dev.pop(*(TOutDev::DevCmd*)nullptr);
    }
    for (i--;i>=0;i--)
    {
      auto&ex=way[i];
      auto*pway=ex.get();
      dev.pop(*pway);
    }
    return false;
  }
  return true;
}

static void super_dev_del_way_v00(TSuperOutDevice&dev,vector<TAutoPtr<TOutDev::DevCmd>>&way)
{
  for (int i=int(way.size())-1;i>=0;i--)
  {
    dev.pop(*way[i].get());
  }
}

class TDay20140605BookV00:public IRenderProgram
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140605BookV00)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,full_screen,DEF,$,$)\
ADDVAR(string,cur_path,DEF,$,$)\
ADDVAR(string,new_path,DEF,$,$)\
ADDVAR(bool,need_build_way,DEF,$,$)\
ADDVAR(int,branch_size,DEF,$,$)\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TDay20140605Book,book,DEF,$,$)\
ADDVAR(vector<TAutoPtr<TOutDev::DevCmd>>,way_from_path,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140605BookV00
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140605BookV00
public:
  void Render(t_context&con)
  {
    vector<TDay20140605Book*> path;
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.root.qDev,
      *this,
      book,
      rect.pos,
      rect.get_size(),
      path,
      con
    };
    context.pos=vec2i_zero;
    context.size=con.root.win.GetClientSize();
    if (!full_screen)
    {
      rect.Render(context);
      auto hi=book.get_header_info(rect.pos,rect.get_size());
      context.pos=hi.body_pos;
      context.size=hi.body_size;
    }
    if (full_screen&&!cur_path.empty()&&!way_from_path.empty())
    {
      auto&Env=con.Env;
      //use way
      TSuperOutDevice con_dev;
      con_dev.branch.items.reserve(128);
      con_dev.branch.top.pCmd=nullptr;
      con_dev.branch.top.pType=Sys$$<SelfClass>::GetRTTI(Env);
      con_dev.branch.top.pValue=this;
      bool ok=super_dev_add_way_v00(con_dev,way_from_path);
      if (!ok)return;
      //check
      auto&top=con_dev.branch.top;
      for (;;)
      {
        auto*pValue=top.pValue;
        auto*pType=top.pType;
        if (!pType||!pValue)return;
        auto*pTDay20140605Book=Sys$$<TDay20140605Book>::GetRTTI(Env);
        if (!pType->IsBasedOn(pTDay20140605Book))
        {
          int fail=1;
          return;
        }
        break;
      }
      auto&the_book=*(TDay20140605Book*)top.pValue;
      the_book.Render(context);
      //rollback way
      //super_dev_del_way_v00(con_dev,way);
      return;
    }
    book.Render(context);
  }
  void update_fullscreen(QapKeyboard&kb)
  {
    bool onf11=kb.OnDown(VK_F11);
    if (onf11)
    {
      int gg=1;
    }
    if (onf11)
    {
      full_screen=!full_screen||!new_path.empty();
      if (full_screen)
      {
        if (new_path!=cur_path)
        {
          cur_path=new_path;
          new_path.clear();
          need_build_way=true;
        }
      }
    }
  }
  void Update(t_context&con)
  {
    vector<TDay20140605Book*> path;
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.root.qDev,
      *this,
      book,
      rect.pos,
      rect.get_size(),
      path,
      con
    };
    context.pos=vec2i_zero;
    context.size=con.root.win.GetClientSize();
    branch_size=con.dev.branch.size();
    new_path.clear();
    bool cur_full_screen=full_screen;
    if (!cur_full_screen)
    {
      static bool auto_clear_path=false;
      if (auto_clear_path)cur_path.clear();
      {
        auto hi=book.get_header_info(rect.pos,rect.get_size());
        rect.UpdateEx(context,hi.header_pos,hi.header_size);
      }
      auto hi=book.get_header_info(rect.pos,rect.get_size());
      context.pos=hi.body_pos;
      context.size=hi.body_size;
    }
    if (cur_full_screen&&!cur_path.empty())
    {
      //QapDebugMsg("no way!");
      auto&Env=con.Env;
      TRawPtr raw_ptr;
      raw_ptr.set(Env,*this);
      vector<TAutoPtr<TOutDev::DevCmd>> way=std::move(way_from_path);
      auto*pTDay20140605Book=Sys$$<TDay20140605Book>::GetRTTI(Env);
      auto build_way=[&way,&Env,&con,&raw_ptr,&pTDay20140605Book](const string&cur_path)->bool
      {
        way.clear();
        auto res=booksys_branch_exec_v00(Env,con.dev,raw_ptr,cur_path,way);
        bool ok=res.ptr.pType&&res.ptr.pType->IsBasedOn(pTDay20140605Book);
        if (!ok||!res.ok||!res.ptr.IsValid())
        {
          QapDebugMsg("no way");
          return false;
        }
        return true;
      };
      if (way.empty()||need_build_way)
      {
        bool ok=build_way(cur_path);
        if (!ok)
        {
          QapDebugMsg("wrong path:\n"+cur_path);
          full_screen=false;
          return;
        }
        need_build_way=false;
      }
      //use way
      bool ok=super_dev_add_way_v00(con.dev,way);
      //check
      for (;;)
      {
        auto*pValue=con.dev.branch.top.pValue;
        auto*pType=con.dev.branch.top.pType;
        if (!pType||!pValue)return;
        if (!ok||!pType->IsBasedOn(pTDay20140605Book))
        {
          if (ok)QapDebugMsg("way not teset at all");
          con.dev.branch.ok=true;
          bool build_ok=build_way(cur_path);
          if (!build_ok)
          {
            full_screen=false;
            con.dev.branch.ok=true;
            return;
          }
          QapAssert(branch_size==con.dev.branch.size())
          QapAssert(con.dev.branch.ok);
          bool super_ok=super_dev_add_way_v00(con.dev,way);
          if (!super_ok)
          {
            full_screen=false;
            con.dev.branch.ok=true;
            return;
          }
          break;
        }
        break;
      }
      auto&the_book=*(TDay20140605Book*)con.dev.branch.top.pValue;
      the_book.Update(context);
      //rollback way
      super_dev_del_way_v00(con.dev,way);
      //
      way_from_path=std::move(way);
      update_fullscreen(context.kb);
      return;
    }
    {
      TOutDevScopeMemberID devscope(con.dev,ProxySys$$::GET_FIELD_ID::book);
      book.Update(context);
    }
    update_fullscreen(context.kb);
    int gg=1;
  }
};

class TBookPageV00:public IBookPage
{
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
    if (!pFontGen)return;
    auto&font=pFontGen->Font;
    qDev.BindTex(0,&pFontGen->Tex);
    qDev.SetColor(0xff000000);
    auto s=con.size/2;
    QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x-s.x),int(con.pos.y+s.y),text);
  }
  void Update(t_context&con)
  {
    if (!need_set_def_text)return;
    need_set_def_text=false;
    text="some default text.";
  }
};

class TTextEditor
{
public:
  class t_log_item
  {
  public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_log_item)OWNER(TTextEditor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(bool,need_remove,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(int,n,DEF,$,$)\
  ADDVAR(real,rt,DEF,$,$)\
  ADDVAR(real,pde,DEF,$,$)\
  ADDEND()
    //=====+>>>>>t_log_item
#include "QapGenStruct.inl"
    //<<<<<+=====t_log_item
  public:
  };
  class TProfiler
  {
  public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProfiler)OWNER(TTextEditor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(bool,need_reset,DEF,$,$)\
  ADDVAR(int,n,DEF,$,$)\
  ADDVAR(real,total_rt,DEF,$,$)\
  ADDVAR(real,rt,DEF,$,$)\
  ADDVAR(real,total_pde,DEF,$,$)\
  ADDVAR(real,pde,DEF,$,$)\
  ADDVAR(bool,add_to_log,DEF,$,$)\
  ADDVAR(vector<t_log_item>,logs,DEF,$,$)\
  ADDEND()
    //=====+>>>>>TProfiler
#include "QapGenStruct.inl"
    //<<<<<+=====TProfiler
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(TProfiler)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTextEditor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(string,fn,SET,"test_new3.txt",$)\
ADDVAR(bool,need_load_text,SET,true,$)\
ADDVAR(int,border,SET,5,$)\
ADDVAR(int,caret_pos,DEF,$,$)\
ADDVAR(vec2i,car_pos,DEF,$,$)\
ADDVAR(int,sel_caret_pos,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,32,$)\
ADDVAR(bool,mouse_on_down_handled,DEF,$,$)\
ADDVAR(bool,mouse_on_down_handled_for_select_word,DEF,$,$)\
ADDVAR(bool,caret_debug,DEF,$,$)\
ADDVAR(bool,show_caret,SET,true,$)\
ADDVAR(bool,readonly,DEF,$,$)\
ADDVAR(vec2i,dc_mpos,DEF,$,$)\
ADDVAR(int,dc_tick,DEF,$,$)\
ADDVAR(int,dc_max_tick,SET,32,$)\
ADDVAR(bool,is_double_click,DEF,$,$)\
ADDVAR(int,scroll_y,DEF,$,$)\
ADDVAR(int,scroll_lines,SET,3,$)\
ADDVAR(string,buffer,DEF,$,$)\
ADDVAR(bool,log_enabled,DEF,$,$)\
ADDVAR(int,log_tick,DEF,$,$)\
ADDVAR(bool,use_new_loop,SET,true,$)\
ADDVAR(vector<string>,logs,DEF,$,$)\
ADDVAR(TProfiler,profiler,DEF,$,$)\
ADDEND()
//=====+>>>>>TTextEditor
#include "QapGenStruct.inl"
//<<<<<+=====TTextEditor
public:
  typedef IBookPage::t_context t_context;
public:
  bool is_selected()
  {
    return caret_pos!=sel_caret_pos;
  }
public:
  struct t_text_renderer
  {
    const int scroll_y;
    const int scroll_lines;
    const vec2i con_pos;
    const vec2i con_size;
    const int border;
    const string&text;
    const int caret_pos;
    const int sel_caret_pos;
    bool caret_detected;
    bool sel_car_detected;
    vec2i caret_p;
    vec2i sel_car_p;
    int x;
    int y;
    int dx;
    int dy;
    int cx;
    int cy;
    int max_x;
    int caret;
    vec2i pos;
    vec2i mpos;
    int mpos_id;
    bool need_find_mpos_id;
    bool use_new_loop;
    //vector<string> lines;
    vector<QapText::t_draw_call> sel_calls;
    void next_line()
    {
      y+=dy?dy:-cy;
      dy=0;
      x=pos.x;
    }
    void operator()(unsigned char UC,const vec2i&p,const vec2i&size)
    {
      if (caret==text.size())
      {
        int wtf=1;
        return;
      }
      auto uc=(byte)text[caret];
      QapAssert(uc==UC);
      if (caret==caret_pos)
      {
        caret_p=p;
        caret_detected=true;
      }
      if (caret==sel_caret_pos)
      {
        sel_car_p=p;
        sel_car_detected=true;
      }
      if (caret_detected!=sel_car_detected)
      {
        QapText::add_draw_call(sel_calls,UC,p,vec2i(size.x,-size.y));
      }
      //
      find_mpos(uc=='\n',p,size);
      caret++;
    }
    void find_mpos(bool end_of_line,const vec2i&p,const vec2i&size)
    {
      if (need_find_mpos_id)
      {
        auto mp=mpos+con_pos;
        auto b=p+vec2i(size.x,-size.y);
        if (end_of_line)b.x=con_pos.x+con_size.x;
        if (CD_Rect2Point(p,b,mp))
        {
          if (p.x!=mp.x)if (p.y!=mp.y)if (b.x!=mp.x)if (b.y!=mp.y)QapAssert(mpos_id==-1);
          mpos_id=caret;
          bool our_side=end_of_line||(mp.x*2<(p+b).x);
          if (!our_side)mpos_id++;
        }
      }
    }
    void loop_ex(QapFont&font)
    {
      need_find_mpos_id=true;
      QapDev&qDev=*(QapDev*)nullptr;
      loop(qDev,font,false);
    }
    struct t_dev
    {
      t_text_renderer&owner;
      const string&text;
      int offset;
      int size;
      vector<vec2i> stack;
      void push()
      {
        stack.push_back( {offset,size});
      }
      void pop()
      {
        auto&back=stack.back();
        offset=back.x;
        size=back.y;
        stack.pop_back();
      }
      bool go_end(char c)
      {
        QapAssert(size>=0);
        QapAssert(offset>=0);
        int n=std::min<int>(offset+size,text.size());
        for (int i=offset;i<n;i++)
        {
          if (text[i]==c)
          {
            size=i-offset;
            return true;
          }
        }
        size=n-offset;
        return false;
      }
      static int find_not(const string&text,int offset,char c)
      {
        int n=text.size();
        for (int i=offset;i<n;i++)
        {
          if (text[i]!=c)return i-offset;
        }
        return -1;
      }
    };
    bool is_end_of_context()const
    {
      bool end_of_context=y<con_pos.y-con_size.y+border;
      bool is_selected=sel_caret_pos!=caret_pos;
      if (!is_selected)if (end_of_context)return true;
      if (is_selected)
      {
        if (caret_detected!=sel_car_detected)
        {
          int gg=1;
        }
        if (caret_detected&&sel_car_detected)if (end_of_context)
          {
            int gg=1;
            return true;
          }
      }
      return false;
    }
    void handle_line(t_dev&dev,QapDev&qDev,QapFont&font,bool need_draw)
    {
      auto&func=*this;
      for (bool ok=true;ok;)
      {
        int word_size=0;
        dev.push();
        {
          ok=dev.go_end(' ');
          word_size=dev.size;
          string this_word_is=text.substr(dev.offset,dev.size);
          auto&ex=this_word_is;
          //if(ex.empty()){dy=std::min(dy,-cy);continue;}
          vec2i size;
          int cur_dy=0;
          {
            dx=QapText::GetLength(font,ex);
            size=vec2i(dx,cy);
            cur_dy=-size.y;
          }
          if (x+dx>max_x)
          {
            next_line();
          }
          dy=std::min(dy,cur_dy);
          if (is_end_of_context())
          {
            dev.pop();
            break;
          }
          if (!need_draw)QapText::PreDrawEx(font,int(x),int(y),ex,func);
          if (need_draw)if (y<con_pos.y+con_size.y)QapText::Draw(qDev,font,int(x),int(y),ex);
          x+=dx;
          int gg=1;
        }
        dev.pop();
        dev.offset+=word_size;
        dev.size-=word_size;
        auto e=t_dev::find_not(text,dev.offset,' ');
        if (e<0)
        {
          e=dev.size;/*QapDebugMsg("no way");*/
        }
        for (int i=0;i<e;i++)
        {
          if (!need_draw)
          {
            auto p=vec2i(x,y);
            auto s=vec2i(cx,cy);
            if (e==i+1)
            {
              dev.push();
              dev.offset+=e;
              dev.size-=e;
              dev.go_end(' ');
              string this_word_is=text.substr(dev.offset,dev.size);
              auto&ex=this_word_is;
              int dx=QapText::GetLength(font,ex);
              if (x+cx+dx>max_x)
              {
                s.x=max_x-x;
              }
              dev.pop();
            }
            func(' ',p,s);
          }
          x+=cx;
        }
        if (is_end_of_context())break;
        string this_sep_is=text.substr(dev.offset,e);
        dev.offset+=e;
        dev.size-=e;
      }
    }
    void handle_text(t_dev&dev,QapDev&qDev,QapFont&font,bool need_draw)
    {
      auto&func=*this;
      for (bool ok=true;ok;)
      {
        int cur_size=dev.size;
        int line_size=0;
        dev.push();
        {
          ok=dev.go_end('\n');
          line_size=dev.size;
          handle_line(dev,qDev,font,need_draw);
          if (is_end_of_context())
          {
            dev.pop();
            break;
          }
        }
        dev.pop();
        dev.offset+=line_size;
        dev.size-=line_size;
        auto e=t_dev::find_not(text,dev.offset,'\n');
        if (e<0)
        {
          e=dev.size;/*QapDebugMsg("no way");*/
        }
        for (int i=0;i<e;i++)
        {
          if (!need_draw)func('\n',vec2i(x,y),vec2i(cx,cy));
          next_line();
          dx=cx;
        }
        //string this_sep_is=text.substr(dev.offset,e);
        dev.offset+=e;
        dev.size-=e;
      }
      int hm=1;
      {
        find_mpos(true,vec2i(x,y),vec2i(cx,cy));
        if (need_find_mpos_id)
        {
          if (mpos_id==-1)
          {
            if (mpos.y-cy<y-con_pos.y)
            {
              mpos_id=caret;
            }
          }
        }
        if (!need_draw)if (text.size()==caret_pos)
          {
            caret_p=vec2i(x,y);
            caret_detected=true;
          }
        if (!need_draw)if (text.size()==sel_caret_pos)
          {
            sel_car_p=vec2i(x,y);
            sel_car_detected=true;
          }
        int gg=1;
      }
    }
    void new_loop(QapDev&qDev,QapFont&font,bool need_draw)
    {
      if (need_find_mpos_id)QapAssert(!need_draw);
      mpos_id=-1;
      auto&func=*this;
      string raw=StrReplace(text,"\r","");
      {
        pos=con_pos+vec2i(-con_size.x,+con_size.y)+vec2i(+1,-1)*border;
        max_x=con_pos.x+con_size.x-border;
        if (!need_draw)caret_detected=false;
        if (!need_draw)sel_car_detected=false;
        cx=+font.Info.Coords[0].x;
        cy=font.Info.Coords[0].y;
        x=pos.x;
        y=pos.y-(scroll_y*cy*scroll_lines);
        dx=cx;
        dy=-cy;
        caret=0;
      }
      t_dev dev={*this,raw,0,text.size()};
      dev.push();
      handle_text(dev,qDev,font,need_draw);
      dev.pop();
    }
    void loop(QapDev&qDev,QapFont&font,bool need_draw)
    {
      if (use_new_loop)
      {
        new_loop(qDev,font,need_draw);
        return;
      }
      if (need_find_mpos_id)QapAssert(!need_draw);
      mpos_id=-1;
      auto&func=*this;
      string raw=StrReplace(text,"\r","");
      auto lines=split(raw,"\n");
      pos=con_pos+vec2i(-con_size.x,+con_size.y)+vec2i(+1,-1)*border;
      max_x=con_pos.x+con_size.x-border;
      if (!need_draw)caret_detected=false;
      if (!need_draw)sel_car_detected=false;
      cx=+font.Info.Coords[0].x;
      cy=font.Info.Coords[0].y;
      x=pos.x;
      y=pos.y-(scroll_y*cy*scroll_lines);
      dx=cx;
      dy=-cy;
      caret=0;
      auto is_end_of_context=[&]()->bool
      {
        bool end_of_context=y<con_pos.y-con_size.y+border;
        bool is_selected=sel_caret_pos!=caret_pos;
        if (!is_selected)if (end_of_context)return true;
        if (is_selected)
        {
          if (caret_detected!=sel_car_detected)
          {
            int gg=1;
          }
          if (caret_detected&&sel_car_detected)if (end_of_context)return true;
        }
        return false;
      };
      for (int i=0;i<lines.size();i++)
      {
        auto&line=lines[i];
        auto arr=split(line," ");
        for (int j=0;j<arr.size();j++)
        {
          auto&ex=arr[j];
          if (j)
          {
            if (!need_draw)func(' ',vec2i(x,y),vec2i(cx,cy));
            x+=cx;
          }
          //if(ex.empty()){dy=std::min(dy,-cy);continue;}
          vec2i size;
          int cur_dy=0;
          {
            dx=QapText::GetLength(font,ex);
            size=vec2i(dx,cy);
            cur_dy=-size.y;
          }
          if (x+dx>max_x)
          {
            next_line();
          }
          dy=std::min(dy,cur_dy);
          if (is_end_of_context())break;
          if (!need_draw)QapText::PreDrawEx(font,int(x),int(y),ex,func);
          if (need_draw)if (y<con_pos.y+con_size.y)QapText::Draw(qDev,font,int(x),int(y),ex);
          x+=dx;
        }
        if (is_end_of_context())break;
        if (i+1!=lines.size())
        {
          if (!need_draw)func('\n',vec2i(x,y),vec2i(cx,cy));
          next_line();
          dx=cx;
        }
      }
      find_mpos(true,vec2i(x,y),vec2i(cx,cy));
      if (need_find_mpos_id)
      {
        if (mpos_id==-1)
        {
          if (mpos.y-cy<y-con_pos.y)
          {
            mpos_id=caret;
          }
        }
      }
      if (!need_draw)if (text.size()==caret_pos)
        {
          caret_p=vec2i(x,y);
          caret_detected=true;
        }
      if (!need_draw)if (text.size()==sel_caret_pos)
        {
          sel_car_p=vec2i(x,y);
          sel_car_detected=true;
        }
      int gg=1;
    }
  };
public:
  t_text_renderer make_tr(t_context&con)
  {
    t_text_renderer tr=
    {
      scroll_y,scroll_lines,
      con.pos,con.size/2,
      border,text,
      caret_pos,sel_caret_pos
    };
    tr.use_new_loop=use_new_loop;
    return std::move(tr);
  }
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    if (!con.root.SysRes.FontObj)return;
    auto*pfont_obj=con.root.SysRes.FontObj.get();
    auto&font=pfont_obj->Font;
    auto&tex=pfont_obj->Tex;
    QapClock clock;
    clock.Start();
    if (false)
    {
      qDev.BindTex(0,nullptr);
      qDev.SetColor(0xffffffff);
      qDev.DrawQuad(con.pos,con.size);
    }
    auto tr=make_tr(con);
    //
    auto active_size=con.size-vec2i(border,border)*0;
    //
    auto&caret_p=tr.caret_p;
    auto&sel_car_p=tr.sel_car_p;
    auto&caret_detected=tr.caret_detected;
    auto&sel_car_detected=tr.sel_car_detected;
    {
      QapClock sub_clock;
      sub_clock.Start();
      //pass for PreDrawEx
      tr.loop(qDev,font,false);
      //
      sub_clock.Stop();
      profiler.total_pde+=sub_clock.MS();
      profiler.pde=profiler.total_pde/real(profiler.n+1);
    }
    //
    if (show_caret&&sel_car_detected&&is_selected())
    {
      QapDev::BatchScope Scope(qDev);
      qDev.BindTex(0,nullptr);
      qDev.SetColor(0x99a0a0ff);
      if (true)
      {
        auto&arr=tr.sel_calls;
        for (int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          if (!PointInQuad(ex.pos,con.pos,active_size))continue;
          qDev.DrawQuadWithHalfPixelOffset(ex.pos+ex.size/2,ex.size);
        }
      }
    }
    //pass for DrawEx
    {
      QapDev::BatchScope Scope(qDev);
      qDev.BindTex(0,&tex);
      qDev.SetColor(0xff000000);
      tr.loop(qDev,font,true);
    }
    //
    qDev.BindTex(0,nullptr);
    //
    if (show_caret)if (caret_debug||(tick<=max_tick/2))if (caret_detected)if (PointInQuad(caret_p,con.pos,active_size))
          {
            QapDev::BatchScope Scope(qDev);
            qDev.SetColor(0xff000000);
            qDev.DrawQuadWithHalfPixelOffset(caret_p.x+1,caret_p.y-tr.cy/2,1,tr.cy);
          }
    //
    clock.Stop();
    if (profiler.need_reset)profiler.DoReset();
    if (profiler.add_to_log)
    {
      auto logs=profiler.logs;
      auto&back=qap_add_back(logs);
      back.n=profiler.n;
      back.rt=profiler.rt;
      back.pde=profiler.pde;
      profiler.DoReset();
      profiler.logs=logs;
    }
    QapCleanIf(profiler.logs,[](t_log_item&ex)
    {
      return ex.need_remove;
    }
              );
    profiler.total_rt+=clock.MS();
    profiler.rt=profiler.total_rt/real(profiler.n+1);
    profiler.n++;
  }
  static vec2i get_caret_pos(const string&text,int caret_pos)
  {
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    int c=0;
    int sol=0;
    for (int i=0;i<caret_pos;i++)
    {
      if (text[i]=='\n')
      {
        sol=i+1;
        c++;
      }
    }
    return vec2i(caret_pos-sol,c);
  }
  static bool is_allowed_char(char c)
  {
    static const string allowed=gen_dips("azAZàÿÀß09")+"¸"+" _=+-*/\\~!@#$%^&|()[]{}`'\"?.,<>;:";
    return allowed.find(c)!=string::npos;
  }
  static bool is_char_from_word(char c)
  {
    static const string char_from_word=gen_dips("azAZàÿÀß09")+"¸"+"_@$";
    return char_from_word.find(c)!=string::npos;
  }
  static size_t find_end_of_word(const string&text,size_t offset)
  {
    QapAssert(offset<text.size());
    for (auto i=offset;i<text.size();i++)
    {
      if (!is_char_from_word(text[i]))return i;
    }
    return string::npos;
  }
  static size_t rfind_begin_of_word(const string&text,size_t offset)
  {
    QapAssert(offset<text.size());
    for (auto i=offset;;)
    {
      if (!is_char_from_word(text[i]))return i;
      if (!i)break;
      i--;
    }
    return string::npos;
  }
  void UpdateCarPos(t_context&con)
  {
    auto&kb=con.kb;
    bool ctrl=kb.Down[VK_CONTROL];
    bool shift=kb.Down[VK_SHIFT];
    bool mod=con.kb.OnDown(mbLeft);
    bool md=con.kb.Down[mbLeft];
    bool need_select=false;
    if (shift)
    {
      need_select=true;
    }
    if (mod)
    {
      mouse_on_down_handled=true;//sel_caret_pos!=caret_pos;
    }
    if (md&&!mod&&mouse_on_down_handled)
    {
      need_select=true;
    }
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    sel_caret_pos=Clamp<int>(sel_caret_pos,0,text.size());
    car_pos=get_caret_pos(text,caret_pos);
    if (!need_select||(kb.News&&is_allowed_char(kb.LastChar)))
    {
      sel_caret_pos=caret_pos;
      log("sel_caret_pos=caret_pos");
    }
  }
  void insert_string(t_context&con,const string&content)
  {
    QapAssert(!is_selected())
    {
      text=text.substr(0,caret_pos)+content+text.substr(caret_pos);
    }
    caret_pos+=content.size();
    tick=0;
    UpdateCarPos(con);
  }
  void UpdateText(t_context&con)
  {
    auto&kb=con.kb;
    bool ctrl=kb.Down[VK_CONTROL];
    bool shift=kb.Down[VK_SHIFT];
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    sel_caret_pos=Clamp<int>(sel_caret_pos,0,text.size());
    auto copy_to_buffer=[&]()
    {
      if (!is_selected())return;
      int a=std::min(caret_pos,sel_caret_pos);
      int b=std::max(caret_pos,sel_caret_pos);
      a=Clamp<int>(a,0,text.size());
      b=Clamp<int>(b,0,text.size());
      QapAssert(b-a>0);
      buffer=text.substr(a,b-a);
    };
    auto remove_selected_text=[&]()
    {
      if (!is_selected())return;
      int a=std::min(caret_pos,sel_caret_pos);
      int b=std::max(caret_pos,sel_caret_pos);
      a=Clamp<int>(a,0,text.size());
      b=Clamp<int>(b,0,text.size());
      text=text.substr(0,a)+text.substr(b);
      caret_pos=a;
      sel_caret_pos=a;
    };
    if (kb.OnDown('C')&&ctrl)copy_to_buffer();
    if (kb.OnDown('X')&&ctrl)if (!readonly)
      {
        copy_to_buffer();
        remove_selected_text();
      }
    if (kb.OnDown('V')&&ctrl)if (!readonly)
      {
        remove_selected_text();
        insert_string(con,buffer);
      }
    if (kb.OnDown('A')&&ctrl)
    {
      sel_caret_pos=0;
      caret_pos=text.size();
    }
    if (kb.OnDown('S')&&ctrl)if (!readonly)
      {
        file_put_contents(fn,text);
      }
    if (kb.OnDown('L')&&ctrl)
    {
      text=StrReplace(file_get_contents(fn),"\r","");
    }
    if (!text.empty())
    {
      if (kb.OnDown(VK_END))
      {
        if (ctrl)caret_pos=text.size();
        if (!ctrl)
        {
          int eol=text.find("\n",caret_pos);
          if (string::npos!=eol)caret_pos=eol;
          if (string::npos==eol)caret_pos=text.size();
        }
        tick=0;
        UpdateCarPos(con);
      }
      if (kb.OnDown(VK_HOME))
      {
        if (ctrl)
        {
          caret_pos=0;
          scroll_y=0;
        }
        if (!ctrl)if (caret_pos)
          {
            int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
            if (string::npos!=sol)caret_pos=sol+1;
            if (string::npos==sol)caret_pos=0;
          }
        tick=0;
        UpdateCarPos(con);
      }
    }
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    if (kb.OnDown(VK_DELETE))if (!readonly)
      {
        bool selected=is_selected();
        remove_selected_text();
        if (!selected)
        {
          int offset=std::min<int>(caret_pos+1,text.size());
          text=text.substr(0,caret_pos)+text.substr(offset);
        }
        tick=0;
        UpdateCarPos(con);
      }
    if (kb.OnDown(VK_BACK))if (!readonly)
      {
        bool selected=is_selected();
        remove_selected_text();
        if (!selected)if (caret_pos>0)
          {
            text=text.substr(0,caret_pos-1)+text.substr(caret_pos);
            caret_pos--;
            sel_caret_pos=caret_pos;
          }
        tick=0;
        UpdateCarPos(con);
      }
    if (kb.OnDown(VK_RETURN))if (!readonly)
      {
        remove_selected_text();
        insert_string(con,"\n");
        //text=text.substr(0,caret_pos)+"\n"+text.substr(caret_pos);
        //caret_pos++;
        //tick=0;UpdateCarPos(con);
      }
    if (kb.News)if (is_allowed_char(kb.LastChar))if (!readonly)
        {
          remove_selected_text();
          insert_string(con,CToS(kb.LastChar));
          //if(!is_selected)
          //{
          //  text=text.substr(0,caret_pos)+CToS(kb.LastChar)+text.substr(caret_pos);
          //}
          //caret_pos++;tick=0;UpdateCarPos(con);
        }
    if (kb.OnDown(VK_DOWN))[&]()
    {
      int car_pos_x=car_pos.x+1;
      int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
      int offset=0;
      if (string::npos!=sol)offset=caret_pos-sol;
      if (string::npos==sol)offset=caret_pos+1;
      if (offset<car_pos_x)offset=car_pos_x;
      int eol=text.find("\n",caret_pos);
      if (string::npos==eol)return;//caret_pos=text.size();
      if (string::npos!=eol)
      {
        int p=text.find("\n",eol+1);
        if (p==string::npos)p=text.size();
        int next_line_size=p-eol;
        QapAssert(next_line_size);
        if (next_line_size<offset)offset=next_line_size;
        if (!offset)offset++;
        caret_pos=eol+offset;
      }
      tick=0;
      UpdateCarPos(con);
      car_pos.x=car_pos_x-1;
    }
    ();
    if (kb.OnDown(VK_UP))[&]()
    {
      int car_pos_x=car_pos.x+1;
      int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
      int offset=0;
      if (string::npos==sol)return;//sol=0;
      if (string::npos!=sol)offset=caret_pos-sol;
      if (offset<car_pos_x)offset=car_pos_x;
      int sopl=text.rfind("\n",sol-1);
      int next_line_size=sol-1;
      if (string::npos==sopl)next_line_size=sol+1;
      if (string::npos!=sopl)next_line_size=sol-sopl;
      //QapAssert(next_line_size);
      if (next_line_size<offset)offset=next_line_size;
      caret_pos=sopl+offset;
      tick=0;
      UpdateCarPos(con);
      car_pos.x=car_pos_x-1;
    }
    ();
    if (kb.OnDown(VK_LEFT))if (!text.empty())if (caret_pos<=text.size()&&caret_pos>0)
        {
          bool hyper_jump=(caret_pos!=text.size())&&(text[caret_pos-1]==' ');
          bool word_jump=ctrl&&!hyper_jump;
          if (ctrl&&hyper_jump)
          {
            for (int i=caret_pos-1;i>=0;i--)
            {
              if (text[i]==' ')continue;
              caret_pos=i+1;
              break;
            }
          }
          QapAssert(caret_pos);
          bool inside_word=is_char_from_word(text[caret_pos-1]);
          if (word_jump)if (caret_pos>0)
            {
              QapAssert(string("012").rfind('2',2)==2);
              //auto p=text.rfind(' ',caret_pos-1);
              auto p=rfind_begin_of_word(text,caret_pos-1);
              if (p!=string::npos)caret_pos=p+1;
              if (p==string::npos)caret_pos=0;
            }
          if (!inside_word||!ctrl)
          {
            caret_pos--;
          }
          tick=0;
          UpdateCarPos(con);
        }
    if (kb.OnDown(VK_RIGHT))if (!text.empty())if (caret_pos<text.size()&&caret_pos>=0)
        {
          bool hyper_jump=text[caret_pos]==' ';
          bool word_jump=ctrl&&!hyper_jump;
          if (ctrl&&hyper_jump)
          {
            for (int i=caret_pos;i<text.size();i++)
            {
              if (text[i]==' ')continue;
              caret_pos=i;
              break;
            }
          }
          bool inside_word=is_char_from_word(text[caret_pos]);
          if (word_jump)
          {
            QapAssert(string(" 12").find(' ',0)!=string::npos);
            //auto p=text.find(' ',caret_pos);
            auto p=find_end_of_word(text,caret_pos);
            if (p!=string::npos)caret_pos=p;
            if (p==string::npos)caret_pos=int(text.size());
          }
          if (!inside_word||!ctrl)
          {
            caret_pos++;
          }
          tick=0;
          UpdateCarPos(con);
        }
    caret_pos=Clamp<int>(caret_pos,0,text.size());
  }
  static string strpad(const string&s,int n)
  {
    QapAssert(n>s.size());
    string tmp;
    tmp.resize(n-s.size(),'0');
    return tmp+s;
  }
  static string toStr(const vec2i&v)
  {
    return "{x:"+IToS(v.x)+",y:"+IToS(v.y);
  }
  void log(const string&msg)
  {
    static QapClock clock;
    if (!clock.run)clock.Start();
    if (!log_enabled)return;
    logs.push_back("["+strpad(FToS(clock.MS()),11)+"] ["+strpad(IToS(log_tick),7)+"]["+strpad(IToS(dc_tick),3)+"] : "+msg);
  };
  void UpdateMouse(t_context&con)
  {
    if (dc_tick)dc_tick--;
    if (con.kb.OnDown(mbRight))log("mbRight");
    scroll_y+=Sign(con.root.win.zDelta);
    bool mod=con.kb.OnDown(mbLeft);
    bool md=con.kb.Down[mbLeft];
    if (md&&!mod&&!mouse_on_down_handled)
    {
      return;
    }
    if (!md)
    {
      mouse_on_down_handled=false;
      mouse_on_down_handled_for_select_word=false;
      return;
    }
    auto*pfont_obj=con.root.SysRes.FontObj.get();
    auto&font=pfont_obj->Font;
    bool ctrl=con.kb.Down[VK_CONTROL];
    bool mouse_moved=dc_mpos!=con.get_mpos();
    if (!mod&&is_double_click)return;
    is_double_click=(mod)&&(!mouse_moved)&&(dc_tick);
    if (is_double_click)
    {
      log("is_double_click");
    }
    bool need_select_word=false;
    if (is_double_click)need_select_word=true;
    if (ctrl&&mod)
    {
      mouse_on_down_handled_for_select_word=true;
    }
    if (mouse_on_down_handled_for_select_word)
    {
      need_select_word=true;
    }
    auto tr=make_tr(con);
    tr.mpos=con.get_mpos();
    tr.loop_ex(font);
    if (tr.mpos_id<0)return;
    caret_pos=tr.mpos_id;
    if (mouse_moved)
    {
      tick=0;
      UpdateCarPos(con);
    }
    if (mod)
    {
      dc_tick=dc_max_tick;
      vec2i dv=dc_mpos-con.get_mpos();
      dc_mpos=con.get_mpos();
      log("mod {dc_mpos:"+toStr(dc_mpos)+",dv:"+toStr(dv)+"}");
    }
    if (!need_select_word||text.empty()||caret_pos>=text.size())return;
    log("select{mouse_moved:"+BToS(mouse_moved)+"}");
    //DoSelectCurrentWorld();
    if (text[caret_pos]==' ')
    {
      //std::swap
    }
    auto eow=find_end_of_word(text,caret_pos);//text.find(" ",caret_pos);
    auto bow=rfind_begin_of_word(text,caret_pos);//text.rfind(" ",caret_pos);
    if (eow==string::npos)eow=text.size();
    if (eow==string::npos)bow=0;
    sel_caret_pos=bow+1;
    caret_pos=eow;
  }
  void Update(t_context&con)
  {
    log_tick++;
    if (!caret_debug)tick++;
    if (tick>max_tick)tick=0;
    if (con.is_hovered())
    {
      if (scroll_y>0)scroll_y=0;
      UpdateText(con);
      UpdateMouse(con);
      if (scroll_y>0)scroll_y=0;
    }
    if (!need_load_text)return;
    need_load_text=false;
    //text=file_get_contents(fn);
    text=StrReplace(file_get_contents(fn),"\r","");
  }
};

class TTextSelector
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTextSelector)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,OnDown,DEF,$,$)\
ADDVAR(int,zDelta,SET,-1,$)\
ADDVAR(int,SelectId,SET,-1,$)\
ADDVAR(vector<string>,Lines,DEF,$,$)\
ADDEND()
//=====+>>>>>TTextSelector
#include "QapGenStruct.inl"
//<<<<<+=====TTextSelector
public:
  typedef IBookPage::t_context t_context;
  typedef QapTextSelectorV20140605 QapTextSelector;
  typedef QapTextSelector::SelectIdUpdater SelectIdUpdater;
public:
  static string this_class_is_copypaste_of()
  {
    return "QapTextSelectorV20140605";
  }
  static bool toMonoEx(const string&line,string&mono)
  {
    return QapTextSelector::toMonoEx(line,mono);
  };
  void Render(t_context&con)
  {
    if (!con.root.SysRes.FontObj)return;
    auto&qDev=con.qDev;
    auto&font=con.root.SysRes.FontObj->Font;
    auto&tex=con.root.SysRes.FontObj->Tex;
    vec2i pos=con.pos-con.size/2;
    pos.y+=con.size.y;
    vec2i mpos=con.pos+con.get_mpos();
    SelectIdUpdater SIU(font,zDelta,pos,mpos);
    auto&x=SIU.x;
    auto&y=SIU.y;
    tex.Bind();
    TGUIRect ContextRect(con.pos,con.size);
    QapDev::BatchScope Scope(qDev);
    for (int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      if (SIU.skip_line(ContextRect))
      {
        SIU.next_line();
        continue;
      }
      SIU.foo(ex);
      bool flag=SelectId==i;
      string line=!flag?"^1.^0"+ex+"^1.":"^7[^E"+ex+"^7]";
      for (;;)
      {
        string mono;
        if (!toMonoEx(line,mono))break;
        qDev.SetColor(0xff000000);
        QapQ3Text::DrawQapText(&qDev,font,x+1,y-1,mono);
        break;
      }
      QapQ3Text::DrawQapText(&qDev,font,x,y,line);
      SIU.next_line();
    }
  }
  void Update(t_context&con)
  {
    if (!con.root.SysRes.FontObj)return;
    TGUIRect rect(con.pos,con.size);
    //
    vec2i pos=con.pos-con.size/2;
    pos.y+=con.size.y;
    auto mpos=con.pos+con.get_mpos();
    //
    if (rect.CheckPoint(mpos))
    {
      zDelta-=64*Sign(con.root.win.zDelta);
    }
    SelectId=-1;
    OnDown=false;
    if (!rect.CheckPoint(mpos))return;
    auto&Font=con.root.SysRes.FontObj->Font;
    SelectIdUpdater SIU(Font,zDelta,pos,mpos);
    for (int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      //if(SIU.skip_line())
      bool flag=SIU.foo(ex);
      if (flag)
      {
        SelectId=i;
        OnDown=con.kb.OnDown(mbLeft);
      }
      SIU.next_line();
    }
  }
};

class TRawRectAndMenuItems
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRawRectAndMenuItems)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,Moved,SET,true,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TTextSelector,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>TRawRectAndMenuItems
#include "QapGenStruct.inl"
//<<<<<+=====TRawRectAndMenuItems
public:
  typedef IBookPage::t_context t_context;
public:
  void Render(t_context&con)
  {
    if (!Enabled||!Visible)return;
    rect.Render(con);
    auto context=con.make_sub_context(rect);
    selector.Render(context);
  }
  void Update(t_context&con)
  {
    if (!Enabled||!Moved)return;
    rect.Update(con);
    auto context=con.make_sub_context(rect);
    {
      auto&dev=con.context.dev;
      TOutDevScopeMemberID devscopeMember(dev,ProxySys$$::GET_FIELD_ID::selector);
      selector.Update(context);
    }
  }
};

class TPageWithPageAdder:public IBookPage
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPageWithPageAdder)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,64*8,$)\
ADDVAR(TTextSelector,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>TPageWithPageAdder
#include "QapGenStruct.inl"
//<<<<<+=====TPageWithPageAdder
public:
  void Render(t_context&con)
  {
    selector.Render(con);
  }
  void Update(t_context&con)
  {
    {
      auto&dev=con.context.dev;
      TOutDevScopeMemberID devscopeMember(dev,ProxySys$$::GET_FIELD_ID::selector);
      selector.Update(con);
    }
    if (Caption.empty()&&selector.Lines.empty())
    {
      Caption=" + ";
    }
    if (con.is_hovered()&&con.kb.OnDown('R')&&con.kb.Down[VK_CONTROL])
    {
      tick=0;
    }
    tick--;
    if (tick<0)
    {
      tick=max_tick;
      auto*pIBookPage=Sys$$<IBookPage>::GetRTTI(con.Env);
      selector.Lines.clear();
      qap_foreach
      (
        con.Env.GetArr(),
        [&](EnvType&ex)
      {
        auto*pt=ex.Type.get();
        if (!pt)return;
        if (!pt->IsBasedOn(pIBookPage))return;
        selector.Lines.push_back(pt->GetFullName());
      }
      );
    }
    if (selector.OnDown)
    {
      OnDown(con);
    }
  }
  void OnDown(t_context&con)
  {
    auto*pIBookPage=Sys$$<IBookPage>::GetRTTI(con.Env);
    auto tn=selector.Lines[selector.SelectId];
    auto*pt=con.Env.FindTypeByName_is_ug_but_work(tn);
    if (!pt)return;
    auto*p=TTypeStruct::UberCast(pt);
    QapAssert(p);
    auto ok=p->IsBasedOn(pIBookPage);
    QapAssert(ok);
    if (!ok)return;
    auto page_id=con.book.page_id;
    auto&pages=con.book.pages;
    auto beg=qap_arr_slice(pages,page_id);
    qap_add_back(beg).unsafe_build(pt);
    qap_arr_join(beg,pages);
    pages=std::move(beg);
  }
};

class TBookPageWithQuit:public IBookPage
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithQuit)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDEND()
//=====+>>>>>TBookPageWithQuit
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithQuit
public:
  void Render(t_context&con)
  {
    if (!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=pFont->Font;
    con.qDev.BindTex(0,&pFont->Tex);
    auto p=con.pos+vec2i(+10,-10)+vec2i(-con.size.x,+con.size.y)/2;
    QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),"press F5");
    con.qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    if (need_init)
    {
      need_init=false;
      Caption=" X ";
    }
    if (!con.kb.OnDown(VK_F5)||!con.is_hovered())return;
    con.book.need_close=true;
  }
};

class TBookPageWithDisable:public IBookPage
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithDisable)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDEND()
//=====+>>>>>TBookPageWithDisable
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithDisable
public:
  void Render(t_context&con)
  {
    if (!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=pFont->Font;
    con.qDev.BindTex(0,&pFont->Tex);
    auto p=con.pos+vec2i(+10,-10)+vec2i(-con.size.x,+con.size.y)/2;
    QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),"press F5");
    con.qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    if (need_init)
    {
      need_init=false;
      Caption=" _ ";
    }
    if (!con.kb.OnDown(VK_F5)||!con.is_hovered())return;
    con.book.need_disable=true;
  }
};


class t_quad
{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_quad)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(vec2i,size,DEF,$,$)\
ADDEND()
//=====+>>>>>t_quad
#include "QapGenStruct.inl"
//<<<<<+=====t_quad
public:
  bool contains(const vec2i&point)
  {
    return PointInQuad(point,pos,size);
  }
};

class TScrollBar
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TScrollBar)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,minv,DEF,$,$)\
ADDVAR(int,maxv,SET,1000,$)\
ADDVAR(int,value,DEF,$,$)\
ADDVAR(char,dir,SET,'x',$)\
ADDVAR(bool,reverse,DEF,$,$)\
ADDVAR(int,size,SET,32,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDVAR(bool,readonly,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(vec2i,offset,DEF,$,$)\
ADDEND()
//=====+>>>>>TScrollBar
#include "QapGenStruct.inl"
//<<<<<+=====TScrollBar
public:
  typedef IBookPage::t_context t_context;
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    qDev.BindTex(0,nullptr);
    qDev.SetColor(color);
    auto quad=get_quad(con);
    qDev.DrawQuad(con.pos+quad.pos,quad.size);
  }
  t_quad get_quad(t_context&con)const
  {
    t_quad quad;
    quad.size=con.size;
    real x=real(value-minv)/real(maxv-minv);
    if (reverse)x=1-x;
    bool is_x='y'!=dir;
    bool is_y='y'==dir;
    if (is_x)
    {
      int W=con.size.x-size;
      quad.pos.x=-W/2+x*W;
      quad.size.x=size;
    }
    if (is_y)
    {
      int H=con.size.y-size;
      quad.pos.y=-H/2+x*H;
      quad.size.y=size;
    }
    return quad;
  }
  void set_quad(t_context&con)
  {
    auto mpos=con.get_mpos();//+con.pos;
    bool is_x='y'!=dir;
    bool is_y='y'==dir;
    if (is_x)
    {
      int W=con.size.x-size;
      if (!W)return;
      //pos.x=con.pos-W/2+x*W;
      //x=(value-minv)/maxv-minv;
      auto new_x=(mpos.x-offset.x+W/2);
      value=new_x*(maxv-minv)/W+minv;
      value=Clamp(value,minv,maxv);
      int the_x=get_quad(con).pos.x;
      //QapAssert(abs(the_x-(mpos.x-offset.x))<2);
    }
    if (is_y)
    {
      int H=con.size.y-size;
      if (!H)return;
      auto new_y=(mpos.y-offset.y+H/2);
      value=new_y*(maxv-minv)/H+minv;
      value=Clamp(value,minv,maxv);
    }
    if (reverse)value=maxv-value;
  }
  void Update(t_context&con)
  {
    if (!con.is_hovered()&&!down)
    {
      return;
    }
    auto&kb=con.kb;
    auto mpos=con.get_mpos();
    auto quad=get_quad(con);
    if (!down)if (quad.contains(mpos))if (kb.OnDown(mbLeft))
        {
          down=true;
          offset=mpos-quad.pos;
          return;
        }
    if (down&&!kb.Down[mbLeft])down=false;
    if (down)
    {
      set_quad(con);
    }
  }
};

class t_raw_rect_splitter_tool
{
public:
  typedef IBookPage::t_context t_context;
public:
#define IMPL_d(t_vec,t_comp)static t_comp&get_d(char dir,t_vec&v){if('x'==dir)return v.x;if('y'==dir)return v.y;QapDebugMsg("WTF?");return v.y;}
#define IMPL_n(t_vec,t_comp)static t_comp&get_n(char dir,t_vec&v){if('y'==dir)return v.x;if('x'==dir)return v.y;QapDebugMsg("WTF?");return v.x;}
#define F(t_vec,t_comp,mode)IMPL##mode(t_vec,t_comp)IMPL##mode(const t_vec,const t_comp)
#define U(t_vec,t_comp)F(t_vec,t_comp,_d)F(t_vec,t_comp,_n)
  //beg
  U(vec2d,real)
  U(vec2i,int)
  //end
#undef U
#undef F
#undef IMPL_n
#undef IMPL_d
  static int&get_d(char dir,TRawRect&rect)
  {
    if ('y'==dir)return rect.h;
    if ('x'==dir)return rect.w;
    QapDebugMsg("WTF?");
    return rect.w;
  }
  static int&get_n(char dir,TRawRect&rect)
  {
    if ('x'==dir)return rect.h;
    if ('y'==dir)return rect.w;
    QapDebugMsg("WTF?");
    return rect.w;
  }
  // if dir=='y' then 'd'=='y' or 'd'=='h' else 'd'=='x or 'd'=='w'
  static void update_rects(t_context&con,const TScrollBar&bar,TRawRect&view_rect,TRawRect&editor_rect,int ls)
  {
    auto dir=bar.dir;
    auto bar_d=get_d(dir,bar.get_quad(con).pos);
    auto CD=get_d(dir,con.size);
    //int ls=2;
    auto vs=-bar_d+CD/2-ls*2-bar.size/2;
    auto es=+bar_d+CD/2-ls*2-bar.size/2+CD%2;
    int n=(get_n(dir,con.size)-ls*3); //n == old w
    if (view_rect.fixed)
    {
      int ls=view_rect.line_size;
      get_n(dir,view_rect.pos)=0;
      get_d(dir,view_rect.pos)=bar_d+vs-vs/2+ls+bar.size/2;
      get_n(dir,view_rect)=n;
      get_d(dir,view_rect)=vs;
    }
    if (editor_rect.fixed)
    {
      int ls=editor_rect.line_size;
      get_n(dir,editor_rect.pos)=0;
      get_d(dir,editor_rect.pos)=bar_d-es/2-ls-bar.size/2;
      get_n(dir,editor_rect)=n;
      get_d(dir,editor_rect)=es;
    }
  }
};

class TProgramWithIBookPageAdopter:public IRenderProgram
{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramWithIBookPageAdopter)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IBookPage>,page,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramWithIBookPageAdopter
#include "QapGenStruct.inl"
//<<<<<+=====TProgramWithIBookPageAdopter
public:
  void Render(t_context&con)
  {
    vector<TDay20140605Book*> path;
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.root.qDev,
      *(TDay20140605BookV00*)nullptr,
      *(TDay20140605Book*)nullptr,
      vec2i_zero,
      vec2i_zero,
      path,
      con
    };
    context.pos=vec2i_zero;
    context.size=con.root.win.GetClientSize();
    PageRender(context);
  }
  void Update(t_context&con)
  {
    vector<TDay20140605Book*> path;
    IBookPage::t_context context=
    {
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.root.qDev,
      *(TDay20140605BookV00*)nullptr,
      *(TDay20140605Book*)nullptr,
      vec2i_zero,
      vec2i_zero,
      path,
      con
    };
    context.pos=vec2i_zero;
    context.size=con.root.win.GetClientSize();
    PageUpdate(context);
  }
  void PageRender(IBookPage::t_context&con)
  {
    if (!page)return;
    page->Render(con);
  }
  void PageUpdate(IBookPage::t_context&con)
  {
    if (!page)return;
    auto&dev=con.context.dev;
    TOutDevScopeMemberID devscopeMember(dev,ProxySys$$::GET_FIELD_ID::page);
    TOutDevScopeChunk devscopeChunk(dev);
    page->Update(con);
  }
};

//#undef DEF_PRO_SYS_GET_FIELD_ID
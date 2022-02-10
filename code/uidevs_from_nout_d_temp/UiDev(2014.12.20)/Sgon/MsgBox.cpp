#include "StdAfx.h"
#include <utility>

class TWinButton{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWinButton)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(int,id,SET,0,$)\
ADDVAR(int,hwnd,SET,0,$)\
ADDEND()
//=====+>>>>>TWinButton
#include "QapGenStruct.inl"
//<<<<<+=====TWinButton
public:
  void create(HWND owner,const string&text,int id,bool def=false)
  {
    this->text=text;
    this->id=id;
    HFONT fixed_sys=(HFONT)GetStockObject(SYSTEM_FIXED_FONT);
    SIZE size;
    HDC dc=GetDC(owner);
    SelectObject(dc,fixed_sys);
    GetTextExtentPoint32A(dc,text.c_str(),text.size(),&size);
    ReleaseDC(owner,dc);
    HWND hButton=CreateWindowA(
      "button",
      text.c_str(),
      WS_CHILD|WS_VISIBLE|(def?BS_DEFPUSHBUTTON:BS_PUSHBUTTON),
      0,0, 
      size.cx+20,size.cy+10,
      owner,(HMENU)id,
      GlobalEnv::Get().hInstance,NULL
    );
    this->hwnd=(int)hButton;
    SendMessage(hButton,WM_SETFONT,(WPARAM)fixed_sys,NULL);
  }
};

class TWinChat{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWinChat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(int,id,SET,0,$)\
ADDVAR(int,hwnd,SET,0,$)\
ADDEND()
//=====+>>>>>TWinChat
#include "QapGenStruct.inl"
//<<<<<+=====TWinChat
public:
  void create(HWND owner,const string&text,SIZE box)
  {
    this->text=text;
    this->id=id;
    HFONT fixed_sys=(HFONT)GetStockObject(SYSTEM_FIXED_FONT);
    SIZE size;
    HDC dc=GetDC(owner);
    SelectObject(dc,fixed_sys);
    GetTextExtentPoint32A(dc,text.c_str(),text.size(),&size);
    ReleaseDC(owner,dc);
    HWND hChat=CreateWindowA(
      "edit", "...empty...", 
      WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_READONLY|WS_VSCROLL|WS_HSCROLL, 
      0,0,box.cx,box.cy,
      owner,
      (HMENU)5000,GlobalEnv::Get().hInstance,NULL
    );
    QapAssert(hChat);
    QapAssert(SetWindowTextA(hChat,text.c_str()));
    this->hwnd=(int)hChat;
  }
};

class TMsgBox
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
            F(0);F(1);
          #undef F
          flag=true;
        }
        return Heap;
      }
    };
  public:
    #define DEF_PRO_POOR_DESIGN()
    #define DEF_PRO_MANUAL_MOVE()
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TForm)OWNER(TMsgBox)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TMsgBox*,Owner,SYS,nullptr,$)\
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
    void operator=(TMsgBox*Owner){
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
      ClassName="MsgBox_"+IToS(WinPair.ID);
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
      long UD=GetWindowLongA(hWnd,GWL_USERDATA);
      if(!UD){
        SetWindowLong(hWnd,GWL_USERDATA,(long)pForm);
      }else{
        long pF=(long)pForm;
        QapAssert(pF==UD);
      }
      if(msg==WM_WINDOWPOSCHANGING){
        QapAssert("WTF?");
        return 0;
      }
      auto result=pForm->Owner->WndProc(hWnd,msg,wParam,lParam);
      return result;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(TForm)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMsgBox)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Caption,SET,"TMsgBox",$)\
ADDVAR(bool,NeedClose,SET,false,$)\
ADDVAR(bool,Runned,SET,false,$)\
ADDVAR(bool,Visible,SET,true,$)\
ADDVAR(eQuad,Quad,DEF,$,$)\
ADDVAR(TForm,Form,SET,this,$)\
ADDVAR(int,zDelta,SET,0,$)\
ADDVAR(vector<TWinButton>,buttons,DEF,$,$)\
ADDVAR(TWinChat,chat,DEF,$,$)\
ADDVAR(int,retval,SET,0,$)\
ADDEND()
//=====+>>>>>TMsgBox
#include "QapGenStruct.inl"
//<<<<<+=====TMsgBox
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
    DWORD Style=WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
    SetWindowLong(hWnd,GWL_STYLE,Style);
    RECT Rect=Quad.GetWinRect();
    AdjustWindowRect(&Rect,Style,false);
    SetWindowPos(hWnd,0,Quad.x,Quad.y,Quad.w,Quad.h,SWP_FRAMECHANGED|SWP_NOOWNERZORDER);
    ShowWindow(hWnd,Visible?SW_SHOW:SW_HIDE);
  }
  ~TMsgBox(){
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
    zDelta=0;
    for(;;)
    {
      MSG msg;
      if(!PeekMessageA(&msg,0,0,0,PM_REMOVE))break;
      TranslateMessage(&msg);
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
    if(msg==WM_COMMAND){
      auto nc=HIWORD(wParam);
      if(nc==BN_CLICKED){
        this->retval=LOWORD(wParam);
        Close();
        int gg=1;
      }
    }
    if(msg==WM_CLOSE){
      Close();
      if(Runned)return 0;
    }
    if(msg==WM_SHOWWINDOW){Visible=wParam;}
    if(msg==WM_SIZE)
    {
      do{
        if(true)
        {
          int dx=15;
          auto&arr=buttons;
          int total_w=0;
          int total_h=0;
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            auto hButton=(HWND)ex.hwnd;
            eQuad q;{RECT rect;GetWindowRect(hButton,&rect);q.SetWinRect(rect);}
            total_w+=q.w;total_h=q.h+20;
            if(i)total_w+=dx;
          }
          auto chat_hwnd=(HWND)this->chat.hwnd;
          eQuad main;{RECT rect;GetClientRect(hWnd,&rect);main.SetWinRect(rect);}
          eQuad chat;{RECT rect;GetWindowRect(chat_hwnd,&rect);chat.SetWinRect(rect);}
          chat.w=main.w;
          int bar=total_h;
          chat.h=main.h-bar;
          chat.setAtCenter(main);
          chat.y=main.h-chat.h-bar;
          //chat.subpos(main);
          SetWindowPos(chat_hwnd,hWnd,chat.x,chat.y,chat.w,chat.h,SWP_FRAMECHANGED|SWP_NOZORDER);
          //For buttons
          int x=(main.w-total_w)/2;
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            auto hButton=(HWND)ex.hwnd;
            eQuad q;{RECT rect;GetWindowRect(hButton,&rect);q.SetWinRect(rect);}
            q.x=x;
            q.y=chat.h+chat.y+10;
            SetWindowPos(hButton,hWnd,q.x,q.y,q.w,q.h,SWP_FRAMECHANGED|SWP_NOZORDER);
            x+=dx+q.w;
            InvalidateRect(hButton,NULL,TRUE);
          }
          //InvalidateRect(g_hButton,NULL,TRUE);
          break;
        }
      }while(false);
    }
    if(msg==WM_ERASEBKGND){DoPaint();}
    if(msg==WM_KEYDOWN){
      if(IsKeyDown(VK_SHIFT))
      {
        for(int i=0;i<buttons.size();i++)
        {
          if(UpperStr(buttons[i].text.substr(0,1))==CToS(char(wParam))){
            retval=buttons[i].id;
            Close();
            break;
          }
        }
      }
      if(IsKeyDown(VK_CONTROL))
      {
        if('A'==char(wParam)){
          SendMessage((HWND)chat.hwnd,EM_SETSEL,0,-1);
          SetFocus((HWND)chat.hwnd);
          int gg=1;
        }
      }
      if(VK_RETURN==char(wParam))
      {
        Close();
      }
      if(VK_ESCAPE==char(wParam))
      {
        Close();
      }
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
};

struct TMsgBoxBuilder{
public:
  typedef TMsgBoxBuilder SelfClass;
public:
  TMsgBox win;
  HFONT font;
  HWND hwnd;
  WNDPROC pEditProc;
public:
  void main(const string&caption,const string&text,int ButtonCount=3)
  {
    TMessageBoxCaller::t_hack hack(WinMessageBox);
    win.Caption=caption;
    win.Init();
    win.Visible=false;
    win.WindowMode();
    hwnd=win.Form.WinPair.hWnd;
    init_font();
    init_chat(text);
    add_chat_wndproc();
    if(ButtonCount==3){
      init_buttons();
    };
    if(ButtonCount==1){
      add_button("OK",1000);
    }
    win.Visible=true;
    SendMessage(hwnd,WM_SIZE,0,0);
    win.WindowMode();
    UpdateWindow(hwnd);
    SetFocus((HWND)win.chat.hwnd);
    for(int i=0;win.Runned;i++){
      win.Update();
      Sleep(16);
      if(win.NeedClose)win.Free();
    }
    DeleteObject(font);font=0;
  }
  static LRESULT CALLBACK EditProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
  {
    auto*pBuilder=(SelfClass*)GetWindowLongA(hwnd,GWL_USERDATA);
    QapAssert(pBuilder);
    if(msg==WM_KEYDOWN)if(IsKeyDown(VK_CONTROL))if(wParam=='A'){
      SendMessage(hwnd,EM_SETSEL,0,-1);
      //QapDebugMsg("OK!");
    }
    if(msg==WM_KEYDOWN)if(VK_ESCAPE==char(wParam))
    {
      pBuilder->win.Close();
    }
    if(msg==WM_KEYDOWN)if(VK_RETURN==char(wParam))
    {
      pBuilder->win.Close();
    }
    if(msg==WM_KEYDOWN)
    {
      if(IsKeyDown(VK_SHIFT))
      {
        for(int i=0;i<pBuilder->win.buttons.size();i++)
        {
          if(UpperStr(pBuilder->win.buttons[i].text.substr(0,1))==CToS(char(wParam))){
            pBuilder->win.retval=pBuilder->win.buttons[i].id;
            pBuilder->win.Close();
            break;
          }
        }
      }
    }
    return CallWindowProcA(pBuilder->pEditProc,hwnd,msg,wParam,lParam);
  }
  void add_chat_wndproc()
  {
    if(SetWindowLongA((HWND)win.chat.hwnd,GWL_USERDATA,(LONG)this))
    {
      QapDebugMsg("WTF?");
    }
    pEditProc=(WNDPROC)SetWindowLongA((HWND)win.chat.hwnd,GWL_WNDPROC,(LONG)&EditProc);
    if(!pEditProc)
    {
      QapDebugMsg("WTF?");
    }
  }
  void add_button(const string&name,int id)
  {
    TWinButton tmp;
    tmp.create(hwnd,name,id);
    win.buttons.push_back(std::move(tmp));
  }
  void init_buttons()
  {
    add_button("Skip",1000);
    add_button("Break",1001);
    add_button("Ignore",1002);
  }
  void init_chat(const string&text)
  {
    auto box=get_size(text);
    win.chat.create(hwnd,text,box);
    RECT rect;
    auto chat_hwnd=(HWND)win.chat.hwnd;
    GetClientRect(chat_hwnd,&rect);
    eQuad bef;bef.SetSize(box);
    eQuad aft;aft.SetWinRect(rect);
    int dx=bef.w-aft.w;int dy=bef.h-aft.h;
    eQuad&n=win.Quad;
    n=std::move(bef);n.w+=dx+25; n.h+=105+dy;
    if(n.w<250)n.w=250;
    if(n.w>800)n.w=800;
    if(n.h>600)n.h=600;
    n.setAtCenterScreen();
    SetWindowPos(hwnd,0,n.x,n.y,n.w,n.h,SWP_FRAMECHANGED|SWP_NOOWNERZORDER);
    SendMessage(hwnd,WM_SETFONT,(WPARAM)font,NULL);
    SendMessage(chat_hwnd,WM_SETFONT,(WPARAM)font,NULL);
  }
  void init_font()
  {
    int Size=10;
    HDC DC=GetDC(hwnd);
    int H=-MulDiv(Size,GetDeviceCaps(DC,LOGPIXELSY),72);
    font=CreateFontA(H,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,DEFAULT_PITCH,"Consolas");
    ReleaseDC(hwnd,DC);
  }
  SIZE get_size(const string&text)
  {
    SIZE size={0,0};
    HDC dc=GetDC(hwnd);
    SelectObject(dc,font);
    vector<string> arr=split(join(split(text,"\r"),""),"\n");
    int dy=0;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      SIZE tmp;
      GetTextExtentPoint32A(dc,ex.c_str(),ex.size(),&tmp);
      size.cx=std::max<int>(size.cx,tmp.cx);
      if(tmp.cy)dy=tmp.cy;
    }
    size.cy=arr.size()*dy;
    ReleaseDC(hwnd,dc);
    return size;
  };
};

void UberInfoBox(const string&caption,const string&text){
  string out=join(split(join(split(text,"\r"),""),"\n"),"\r\n");
  TMsgBoxBuilder builder;
  builder.main(caption,out,1);
}

inline int MegaMessageBox(const string&caption,const string&text){
  string out=join(split(join(split(text,"\r"),""),"\n"),"\r\n");
  TMsgBoxBuilder builder;
  builder.main(caption,out);
  int retval=builder.win.retval;
  if(retval==1001)return qmbrBreak;
  if(retval==1002)return qmbrIgnore;
  return qmbrSkip;
}

static void starter(IEnvRTTI&Env)
{
  TMessageBoxCaller::Get()=MegaMessageBox;
  QapAssert(false);
  string str="\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n000001000\r\n0111\r\n2222\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n00000\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n00000";
  TMsgBoxBuilder builder;
  builder.main("devtest",str);
  //auto box=get_some(str,win.Form.WinPair.hWnd,font);
  //win.chat.create(win.Form.WinPair.hWnd,str);
  MessageBoxA(NULL,("retval="+IToS(builder.win.retval)).c_str(),"Message",MB_TASKMODAL);
  int gg=1;
}

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
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TMsgBox)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      //starter(Env);
    }
    ThisCompileUnit(){
      TMessageBoxCaller::Get()=MegaMessageBox;
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}
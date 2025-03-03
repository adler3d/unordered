#include "StdAfx.h"
#include <utility>

#include "GlobalEnv.inl"

#include "FastBMP.inl"

static bool IsKeyDown(int vKey){int i=GetAsyncKeyState(vKey); return i<0;}

class t_circle;
class t_line;
class t_trigon;
class t_rect;
class t_pixel;
class t_image;
class t_pen;
class t_brush;

class t_out_dev_pack{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_out_dev_pack)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<t_circle>,circles,DEF,$,$)\
ADDVAR(1,vector<t_line>,lines,DEF,$,$)\
ADDVAR(2,vector<t_trigon>,trigons,DEF,$,$)\
ADDVAR(3,vector<t_rect>,rects,DEF,$,$)\
ADDVAR(4,vector<t_pixel>,pixels,DEF,$,$)\
ADDVAR(5,vector<t_image>,images,DEF,$,$)\
ADDVAR(6,vector<t_pen>,pens,DEF,$,$)\
ADDVAR(7,vector<t_brush>,brushs,DEF,$,$)\
ADDEND()
//=====+>>>>>t_out_dev_pack
#include "QapGenStruct.inl"
//<<<<<+=====t_out_dev_pack
public:
};

class t_out_dev{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_out_dev)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_out_dev_pack,pack,DEF,$,$)\
ADDVAR(1,vector<int>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_out_dev
#include "QapGenStruct.inl"
//<<<<<+=====t_out_dev
public:
};

class t_circle{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_circle)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,x,DEF,$,$)\
ADDVAR(1,int,y,DEF,$,$)\
ADDVAR(2,int,r,DEF,$,$)\
ADDEND()
//=====+>>>>>t_circle
#include "QapGenStruct.inl"
//<<<<<+=====t_circle
public:
};

class t_line{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec2i,a,DEF,$,$)\
ADDVAR(1,vec2i,b,DEF,$,$)\
ADDEND()
//=====+>>>>>t_line
#include "QapGenStruct.inl"
//<<<<<+=====t_line
public:
};

class t_trigon{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_trigon)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec2i,a,DEF,$,$)\
ADDVAR(1,vec2i,b,DEF,$,$)\
ADDVAR(2,vec2i,c,DEF,$,$)\
ADDEND()
//=====+>>>>>t_trigon
#include "QapGenStruct.inl"
//<<<<<+=====t_trigon
public:
};

class t_rect{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec2i,a,DEF,$,$)\
ADDVAR(1,vec2i,b,DEF,$,$)\
ADDEND()
//=====+>>>>>t_rect
#include "QapGenStruct.inl"
//<<<<<+=====t_rect
public:
};

class vec3c{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(vec3c)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,char,r,DEF,$,$)\
ADDVAR(1,char,g,DEF,$,$)\
ADDVAR(2,char,b,DEF,$,$)\
ADDEND()
//=====+>>>>>t_pixel
#include "QapGenStruct.inl"
//<<<<<+=====t_pixel
public:
};

class t_pixel{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pixel)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec2i,p,DEF,$,$)\
ADDVAR(1,vec3c,color,DEF,$,$)\
ADDEND()
//=====+>>>>>t_pixel
#include "QapGenStruct.inl"
//<<<<<+=====t_pixel
public:
};

class t_image{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_image)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec2i,p,DEF,$,$)\
ADDVAR(1,int,w,DEF,$,$)\
ADDVAR(2,int,h,DEF,$,$)\
ADDVAR(3,vector<vec3c>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_image
#include "QapGenStruct.inl"
//<<<<<+=====t_image
public:
};

class t_pen{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pen)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,w,DEF,$,$)\
ADDVAR(1,vec3c,color,DEF,$,$)\
ADDVAR(2,t_out_dev,dev,DEF,$,$)\
ADDEND()
//=====+>>>>>t_pen
#include "QapGenStruct.inl"
//<<<<<+=====t_pen
public:
};

class t_brush{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_brush)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec3c,color,DEF,$,$)\
ADDVAR(1,t_out_dev,dev,DEF,$,$)\
ADDEND()
//=====+>>>>>t_brush
#include "QapGenStruct.inl"
//<<<<<+=====t_brush
public:
};

class TQuad2014{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TQuad2014)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,x,SET,320,$)\
ADDVAR(1,int,y,SET,240,$)\
ADDVAR(2,int,w,SET,320,$)\
ADDVAR(3,int,h,SET,240,$)\
ADDEND()
//=====+>>>>>TQuad2014
#include "QapGenStruct.inl"
//<<<<<+=====TQuad2014
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
  void SetWinRect(const RECT&rect){TQuad2014&r=*(TQuad2014*)(void*)(&rect);Set(r.x,r.y,r.w-r.x,r.h-r.y);}
  void SetSize(const SIZE&size){w=size.cx;h=size.cy;}
  static TQuad2014 getFullScreen(){TQuad2014 tmp;auto mode=GetScreenMode();tmp.Set(0,0,mode.W,mode.H);return std::move(tmp);}
  void setAtCenter(const TQuad2014&quad){
    QapAssert(quad.w>=w);
    QapAssert(quad.h>=h);
    x=(quad.w-w)/2;
    y=(quad.h-h)/2;
  }
  void subpos(const TQuad2014&q){
    x-=q.x;
    y-=q.y;
  }
  void setAtCenterScreen(){setAtCenter(getFullScreen());}
};

class TGameFrom2014
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TForm)OWNER(TGameFrom2014)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR($,TGameFrom2014*,Owner,SYS,nullptr,$)\
    ADDVAR($,ATOM,ClassAtom,SYS,0,$)\
    ADDVAR($,string,ClassName,SYS,"",$)\
    ADDVAR($,WndClassPair,WinPair,SYS,WndClassPair(),$)\
    ADDEND()
    //=====+>>>>>TForm
    #include "QapGenStruct.inl"
    //<<<<<+=====TForm
  public:
    ~TForm()
    {
      if(WinPair.hWnd)Free();
    }
    void operator=(TGameFrom2014*Owner){
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
#define DEF_PRO_POOR_DESIGN()
#define DEF_PRO_NESTED(F)F(TForm)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameFrom2014)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0x0,string,Caption,SET,"TGameFrom2014",$)\
ADDVAR(0x1,bool,NeedClose,SET,false,$)\
ADDVAR(0x2,bool,Runned,SET,false,$)\
ADDVAR(0x3,bool,Visible,SET,true,$)\
ADDVAR(0x4,TQuad2014,Quad,DEF,$,$)\
ADDVAR(0x5,TForm,Form,SET,this,$)\
ADDVAR(0x6,int,zDelta,DEF,$,$)\
ADDVAR(0x7,int,tick,DEF,$,$)\
ADDVAR(0x8,t_out_dev,outdev,DEF,$,$)\
ADDVAR(0xA,FastBMP,fast_bmp,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameFrom2014
#include "QapGenStruct.inl"
//<<<<<+=====TGameFrom2014
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
  void InitFastBMP(){
    auto DC=GetDC(Form.WinPair.hWnd);
    fast_bmp.Init(DC,Quad.w,Quad.h);
    ReleaseDC(Form.WinPair.hWnd,DC);
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
    Quad.SetWinRect(Rect);
    SetWindowPos(hWnd,0,Quad.x,Quad.y,Quad.w,Quad.h,SWP_FRAMECHANGED|SWP_NOOWNERZORDER);
    ShowWindow(hWnd,Visible?SW_SHOW:SW_HIDE);
  }
  ~TGameFrom2014(){
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
      if(!PeekMessageA(&msg,NULL,0,0,PM_REMOVE))break;
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
    if(msg==WM_CLOSE){
      Close();
      if(Runned)return 0;
    }
    if(msg==WM_SHOWWINDOW){Visible=wParam;}
    if(msg==WM_SIZE)
    {
      //TQuad2014 main;{RECT rect;GetClientRect(hWnd,&rect);main.SetWinRect(rect);}
      //ScanWinPlacement();
      //return 0;
    }
    //if(msg==WM_TIMER){tick++;DoPaint();}
    if(msg==WM_ERASEBKGND){DoPaint();}
    return DefWindowProcA(hWnd,msg,wParam,lParam);
  }
  struct t_out_dev_info
  {
    #define F(NUM,NAME)int NAME;
    F(0,circles)
    F(1,lines)
    F(2,trigons)
    F(3,rects)
    F(4,pixels)
    F(5,images)
    F(6,pens)
    F(7,brushs)
    #undef F
    t_out_dev_info(){DoReset();}
    void DoReset()
    {
      #define F(NUM,NAME)NAME=0;
      F(0,circles)
      F(1,lines)
      F(2,trigons)
      F(3,rects)
      F(4,pixels)
      F(5,images)
      F(6,pens)
      F(7,brushs)
      #undef F
    }
  };
  static void Draw(HDC DC,t_circle&ex)
  {
    Ellipse(DC,ex.x-ex.r,ex.y-ex.r,ex.x+ex.r,ex.y+ex.r);
  };
  static void Draw(HDC DC,t_line&ex)
  {
    MoveToEx(DC,ex.a.x,ex.a.y,nullptr);
    LineTo(DC,ex.b.x,ex.b.y);
  }
  static void Draw(HDC DC,t_trigon&ex)
  {
    Polygon(DC,(POINT*)&ex.a,3);
  }
  static void Draw(HDC DC,t_rect&ex)
  {
    Rectangle(DC,ex.a.x,ex.a.y,ex.b.x,ex.b.y);
  }
  static COLORREF get(vec3c&ref){
    struct rgba{char r,g,b,a;};
    auto&c=ref;
    rgba color={c.r,c.g,c.b,0xff};
    return RGB(ref.r,ref.g,ref.b);
    //return (COLORREF&)color;
  }
  static void Draw(HDC DC,t_pixel&ex)
  {
    SetPixel(DC,ex.p.x,ex.p.y,get(ex.color));
  }
  static void Draw(HDC DC,t_image&ex)
  {
    if(ex.w<0||ex.h<0){QapDebugMsg("no way");return;}
    if(ex.arr.size()!=ex.w*ex.h){QapDebugMsg("WTF?");return;}
    FastBMP bmp;
    bmp.Init(DC,ex.w,ex.h);
    for(int i=0;i<ex.arr.size();i++){
      auto&out=bmp.mem[i];
      auto&inp=ex.arr[i];
      out.r=inp.r;
      out.g=inp.g;
      out.b=inp.b;
      out.a=255;
    }
    bmp.mem_to_dc();
    bmp.render(DC,ex.p.x,ex.p.y);
    bmp.Free();
  }
  static void Draw(HDC DC,t_pen&ex)
  {
    //GetStockObject(OBJ_PEN);
    auto pen=CreatePen(PS_SOLID,ex.w,get(ex.color));
    auto old=SelectObject(DC,pen);
    Draw(DC,ex.dev);
    SelectObject(DC,old);
    DeleteObject(pen);
  }
  static void Draw(HDC DC,t_brush&ex)
  {
    LOGBRUSH log;
    log.lbColor=get(ex.color);
    log.lbStyle=BS_SOLID;
    auto brush=CreateBrushIndirect(&log);
    auto old=SelectObject(DC,brush);
    //auto old=SetDCBrushColor(DC,get(ex.color));
    Draw(DC,ex.dev);
    //SetDCBrushColor(DC,old);
    SelectObject(DC,old);
    DeleteObject(brush);
  }
  static void Draw(HDC DC,t_out_dev&outdev)
  {
    t_out_dev_info info;
    auto&arr=outdev.arr;
    for(int i=0;i<arr.size();i++){
      auto id=arr[i];
      #define F(NUM,NAME)if(id==NUM)if(info.NAME<outdev.pack.NAME.size()){Draw(DC,outdev.pack.NAME[info.NAME]);info.NAME++;};
      F(0,circles);
      F(1,lines);
      F(2,trigons);
      F(3,rects);
      F(4,pixels);
      F(5,images);
      F(6,pens);
      F(7,brushs);
      #undef F
    }
    int gg=1;
  }
  void Draw(HDC DC)
  {
    if(false)
    {
      //RECT Rect;
      //GetClientRect(Form.WinPair.hWnd,&Rect);
      //SetBkColor(DC,0xffffffff);
      //FillRect(DC,&Rect,(HBRUSH)(COLOR_BTNFACE));
    }
    LOGBRUSH log;
    log.lbStyle=BS_SOLID;
    auto brush=CreateBrushIndirect(&log);
    auto old=SelectObject(DC,brush);
    Draw(DC,outdev);
    SelectObject(DC,old);
    DeleteObject(brush);
  }
  void DoPaint()
  {//return;
    HWND hWnd=Form.WinPair.hWnd;
    HDC dc=GetDC(hWnd);
    if(fast_bmp.mem){
      Draw(fast_bmp.MDC);
      //fast_bmp.mem_to_dc();
      fast_bmp.render(dc);
    }else{
      Draw(dc);
    }
    ReleaseDC(hWnd,dc);
  }
};

extern i_eval_block*make_t_qap_eval_block(IEnvRTTI&Env,TAutoPtr<i_eval_block>&out);
extern bool qap_eval_string(IEnvRTTI&Env,t_qap_eval_string&ref);
extern void UberInfoBox(const string&caption,const string&text);

#include "TSimpleBinarySaver.inl"

class TGameBox2014Input{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameBox2014Input)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0x0,int,tick,DEF,$,$)\
ADDVAR(0x1,vec2i,mpos,DEF,$,$)\
ADDVAR(0x2,bool,mbLeft,DEF,$,$)\
ADDVAR(0x3,bool,mbMiddle,DEF,$,$)\
ADDVAR(0x4,bool,mbRight,DEF,$,$)\
ADDVAR(0x5,bool,kbEsc,DEF,$,$)\
ADDVAR(0x6,bool,kbLeft,DEF,$,$)\
ADDVAR(0x7,bool,kbRight,DEF,$,$)\
ADDVAR(0x8,bool,kbUp,DEF,$,$)\
ADDVAR(0x9,bool,kbDown,DEF,$,$)\
ADDVAR(0xA,string,userdata,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameBox2014Input
#include "QapGenStruct.inl"
//<<<<<+=====TGameBox2014Input
public:
  string toStr(IEnvRTTI&Env){
    return TSimpleBinarySaver::toStr(Env,this);
  }
  bool fromStr(IEnvRTTI&Env,const string&source){
    return TSimpleBinaryLoader::fromStr(Env,this,source);
  }
};

class TGameBox2014Output{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameBox2014Output)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_out_dev,dev,DEF,$,$)\
ADDVAR(1,string,userdata,DEF,$,$)\
ADDEND()
//=====+>>>>>TGameBox2014Output
#include "QapGenStruct.inl"
//<<<<<+=====TGameBox2014Output
public:
  string toStr(IEnvRTTI&Env){
    return TSimpleBinarySaver::toStr(Env,this);
  }
  bool fromStr(IEnvRTTI&Env,const string&source){
    return TSimpleBinaryLoader::fromStr(Env,this,source);
  }
};

//int&get_qap_fallback_counter();

struct TGameBoxBuilder2014{
public:
  typedef TGameBoxBuilder2014 SelfClass;
public:
  TGameFrom2014 win;
  HWND hwnd;
  TAutoPtr<i_eval_block> block;
  TGameBox2014Input input;
  TGameBox2014Output output;
public:
  bool build_code(IEnvRTTI&Env,const string&code)
  {
    auto*pBlock=make_t_qap_eval_block(Env,block);
    pBlock->code=code;
    pBlock->block_clear();
    pBlock->block_compile(Env);
    if(pBlock->load_status.find("true")>16){
      string out;
      out=(
        "--------------------\n"
        "load_time = "+FToS(pBlock->load_time)+"\n"
        "--------------------\n\n"+pBlock->load_status
      );
      UberInfoBox("load_status",out);
      return false;
    }
    if(false)
    {
      string out;
      out=(
        "load_time = "+FToS(pBlock->load_time)+"\n"
        ""+pBlock->load_status+"\n"
        //"get_qap_fallback_counter = "+IToS(get_qap_fallback_counter())
      );
      UberInfoBox("load_status",out);
    }
    return true;
  }
  bool run_code(IEnvRTTI&Env)
  {
    auto*pBlock=block.get();
    pBlock->block_run(Env);
    if(!pBlock->errcode.empty()){
      string out;
      out=(
        "--------------------\n"
        "load_time = "+FToS(pBlock->load_time)+" ms.\n"
        "retpath:\n"+pBlock->retpath+"\n"
        "--------------------\n\n"+pBlock->errcode
      );
      UberInfoBox("errcode",out);
      return false;
    }
    if(pBlock->out.empty())return false;
    //load_circles(pBlock->out);
    output.fromStr(Env,pBlock->out);
    //input.userdata=std::move(output.userdata);
    win.outdev=std::move(output.dev);
    return true;
  }
  void main(IEnvRTTI&Env,const string&caption)
  {
    /*for(;;){
      Sleep(16);
      if(IsKeyDown(VK_LBUTTON)){
        break;
      }
    }*/
    static string code=file_get_contents("game_box.h");
    //t_hack hack;
    //hack.code=code;
    //hack.ok=hack.check();
    //if(!hack.ok)
    {
      bool ok=build_code(Env,code);
      if(!ok)return;
      if(IsKeyDown(VK_SHIFT))
      {
        //string msg=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(block));
        //QapDebugMsg(msg);
        QapAssert(QapPublicUberFullSaverBin(Env,QapRawUberObject(block),"cpp_tree.qap"));
        int gg=1;
        TQapIO IO;
        Sys$$<int>::GetRTTI(Env)->BinIO->Save(IO,&gg);
      }
    }
    auto*pBlock=block.get();
    win.Quad.w=800;
    win.Quad.h=600;
    win.Quad.setAtCenterScreen();
    win.Caption=caption;
    win.Init();
    win.Visible=true;
    win.WindowMode();
    hwnd=win.Form.WinPair.hWnd;
    UpdateWindow(hwnd);
    SetTimer(hwnd,1000,16,nullptr);
    win.InitFastBMP();
    for(int i=0;win.Runned;i++)
    {
      POINT point;
      QapAssert(GetCursorPos(&point));
      ScreenToClient(hwnd,&point);
      win.tick++;
      {
        input.tick=win.tick;
        input.mpos=vec2i(point.x,point.y);
        input.kbEsc=IsKeyDown(VK_ESCAPE);
        input.mbLeft=IsKeyDown(VK_LBUTTON);
        input.mbMiddle=IsKeyDown(VK_MBUTTON);
        input.mbRight=IsKeyDown(VK_RBUTTON);
        input.kbLeft=IsKeyDown(VK_LEFT);
        input.kbRight=IsKeyDown(VK_RIGHT);
        input.kbUp=IsKeyDown(VK_UP);
        input.kbDown=IsKeyDown(VK_DOWN);
        input.userdata=output.userdata;
      }
      string inp=input.toStr(Env);//IToS(win.tick)+" "+IToS(point.x)+" "+IToS(point.y);
      /*if(hack.ok){
        hack.data=input;
        hack.out=hack.run();
        load_circles(hack.out);
      }else{*/
        pBlock->inp=inp;
        bool ok=run_code(Env);
        if(!ok)win.Close();
      //}
      win.DoPaint();
      //load_scene(Env,"{int tick="+IToS(win.tick)+";"+code+"}");
      win.Update();
      Sleep(0);
      if(win.NeedClose)win.Free();
    }
  }
};

class TGameBoxFuncsPack{
public:
  class t_for_real{
  public:
    class abs:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(abs)PARENT(i_sys_impl)OWNER(t_for_real)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,real,out,DEF,$,$)\
      ADDVAR(1,real,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>abs
      #include "QapGenStruct.inl"
      //<<<<<+=====abs
    public:
      void exec(){out=::fabs(inp);}
    };
    class FToBlob:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FToBlob)PARENT(i_sys_impl)OWNER(t_for_real)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,out,DEF,$,$)\
      ADDVAR(1,real,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>FToBlob
      #include "QapGenStruct.inl"
      //<<<<<+=====FToBlob
    public:
      void exec(){out=string((char*)(void*)&inp,sizeof(inp));}
    };
    class BlobToF:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlobToF)PARENT(i_sys_impl)OWNER(t_for_real)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,real,out,DEF,$,$)\
      ADDVAR(1,string,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>BlobToF
      #include "QapGenStruct.inl"
      //<<<<<+=====BlobToF
    public:
      void exec(){
        bool ok=inp.size()==sizeof(out);
        if(!ok){
          QapDebugMsg("inp.size() = "+IToS(inp.size()));
          return;
        }
        out=*(int*)(void*)&inp[0];
      }
    };
  public:
    #define DEF_PRO_NESTED(F)F(abs)F(FToBlob)F(BlobToF)
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_real)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_for_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_for_real
  };
  class t_for_int{
  public:
    class abs:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(abs)PARENT(i_sys_impl)OWNER(t_for_int)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,int,out,DEF,$,$)\
      ADDVAR(1,int,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>abs
      #include "QapGenStruct.inl"
      //<<<<<+=====abs
    public:
      void exec(){out=::abs(inp);}
    };
    class IToBlob:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IToBlob)PARENT(i_sys_impl)OWNER(t_for_int)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,out,DEF,$,$)\
      ADDVAR(1,int,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>IToBlob
      #include "QapGenStruct.inl"
      //<<<<<+=====IToBlob
    public:
      void exec(){out=string((char*)(void*)&inp,sizeof(inp));}
    };
    class BlobToI:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlobToI)PARENT(i_sys_impl)OWNER(t_for_int)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,int,out,DEF,$,$)\
      ADDVAR(1,string,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>BlobToI
      #include "QapGenStruct.inl"
      //<<<<<+=====BlobToI
    public:
      void exec(){
        bool ok=inp.size()==sizeof(out);
        if(!ok){
          QapDebugMsg("inp.size() = "+IToS(inp.size()));
          return;
        }
        out=*(int*)(void*)&inp[0];
      }
    };
  public:
    #define DEF_PRO_NESTED(F)F(abs)F(IToBlob)F(BlobToI)
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_int)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_for_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_for_int
  };
  class t_for_bool{
  public:
    class BToBlob:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BToBlob)PARENT(i_sys_impl)OWNER(t_for_bool)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,string,out,DEF,$,$)\
      ADDVAR(1,bool,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>BToBlob
      #include "QapGenStruct.inl"
      //<<<<<+=====BToBlob
    public:
      void exec(){out=string((char*)(void*)&inp,sizeof(inp));}
    };
    class BlobToB:public i_sys_impl{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlobToB)PARENT(i_sys_impl)OWNER(t_for_bool)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,bool,out,DEF,$,$)\
      ADDVAR(1,string,inp,DEF,$,$)\
      ADDEND()
      //=====+>>>>>BlobToB
      #include "QapGenStruct.inl"
      //<<<<<+=====BlobToB
    public:
      void exec(){
        bool ok=inp.size()==sizeof(out);
        if(!ok){
          QapDebugMsg("inp.size() = "+IToS(inp.size()));
          return;
        }
        out=(bool&)inp[0];
      }
    };
  public:
    #define DEF_PRO_NESTED(F)F(BToBlob)F(BlobToB)
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_bool)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_for_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_for_bool
  };
public:
  class BlobToS:public i_sys_impl{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlobToS)PARENT(i_sys_impl)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>BlobToS
    #include "QapGenStruct.inl"
    //<<<<<+=====BlobToS
  public:
    void exec(){
      bool ok=inp.size()>=sizeof(out.size());
      if(!ok){
        QapDebugMsg("inp.size() = "+IToS(inp.size()));
        return;
      }
      int count=(int&)inp[0];
      QapAssert(count>=0);
      QapAssert(count==inp.size()-sizeof(inp.size()));
      out=inp.substr(sizeof(inp.size()));
    }
  };
  class SToBlob:public i_sys_impl{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(SToBlob)PARENT(i_sys_impl)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>SToBlob
    #include "QapGenStruct.inl"
    //<<<<<+=====SToBlob
  public:
    void exec(){
      out.resize(4);
      ((int&)out[0])=inp.size();
      out+=inp;
    }
  };
  class BlobToHex:public i_sys_impl{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlobToHex)PARENT(i_sys_impl)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>BlobToHex
    #include "QapGenStruct.inl"
    //<<<<<+=====BlobToHex
  public:
    void exec(){
      out="";
      for(int i=0;i<inp.size();i++){
        out+=CToH_raw(inp[i]);
      }
    }
  };
  class HexToBlob:public i_sys_impl{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(HexToBlob)PARENT(i_sys_impl)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>HexToBlob
    #include "QapGenStruct.inl"
    //<<<<<+=====HexToBlob
  public:
    void exec(){
      out="";
      for(int i=0;i<inp.size();i+=2){
        out+=char(HToI_raw(inp.substr(i,2)));
      }
    }
  };
  class BlobToBin:public i_sys_impl{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlobToBin)PARENT(i_sys_impl)OWNER(TGameBoxFuncsPack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>BlobToBin
    #include "QapGenStruct.inl"
    //<<<<<+=====BlobToBin
  public:
    static string IntToBin(int inp){
      string out;out.resize(32);
      auto u=*(unsigned*)(void*)&inp;
      for(int i=0;i<32;i++){
        out[i]=u%2?'1':'0';
        u>>=1;
      }
      return out;
    }
    static string CharToBin(char inp){
      string out;out.resize(8);
      auto u=*(uchar*)(void*)&inp;
      for(int i=0;i<8;i++){
        out[i]=u%2?'1':'0';
        u>>=1;
      }
      return out;
    }
    void exec(){
      out="";
      for(int i=0;i<inp.size();i++){
        out+=CharToBin(inp[i]);
      }
    }
  };
public:
#define DEF_PRO_NESTED(F)F(t_for_real)F(t_for_int)F(t_for_bool)F(BlobToS)F(SToBlob)F(BlobToHex)F(BlobToBin)F(HexToBlob)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGameBoxFuncsPack)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TGameBoxFuncsPack
#include "QapGenStruct.inl"
//<<<<<+=====TGameBoxFuncsPack
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
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TGameFrom2014)F(TGameBoxFuncsPack)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      TGameBoxBuilder2014 root;
      root.main(Env,"Foo");
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}
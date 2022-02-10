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
  void Set(int x,int y,int w,int h);
  vec2i&GetPos();
  vec2i&GetSize();
  void SetAs(const vec2i&pos,const vec2i&size);
  RECT GetWinRect();
  void SetWinRect(const RECT&rect);
  void SetSize(const SIZE&size);
  static TQuad getFullScreen();
  void setAtCenter(const TQuad&quad);
  void setAsFullScreen();
  void subpos(const TQuad&q);
  void setAtCenterScreen();
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
      WndClassPair();
      WndClassPair(WNDPROC Proc,HWND hWnd,int ID,bool Used);
    public:
      void Init(TForm*Owner);
      void Free(TForm*Owner);
    };
    class WndProcHeap
    {
    public:
      vector<WndClassPair> Arr;
      void Load(WndClassPair&WinPair);
      void Save(WndClassPair&WinPair);
      static WndProcHeap&Get();
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
    ~TForm();
    void operator=(TD3DGameBox*Owner);
  public:
    void Init();
    void Free();
  public:
    void Reg();
    bool UnReg();
  public:
    static const UINT WMU_INIT=WM_USER+1234;
    static const UINT WMU_FREE=WM_USER+4321;
  public:
    template<int Index>
    static LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
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
  bool IsWindow();
  void Init();
  void UpdateWnd();
  void WindowMode();
  ~TD3DGameBox();
  void Free();
  void Update();
  void Close();
  void ScanWinPlacement();
  static bool Equal(RECT&a,RECT&b);
  static void KeyboardUpdate(QapKeyboard&Keyboard,const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam);
  LRESULT WndProc(const HWND hWnd,const UINT msg,const WPARAM wParam,const LPARAM lParam);
  void DoPaint();
  vec2i GetClientSize();
  vec2i GetMousePos();
  vec2i unsafe_GetMousePos();
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
    void push();
    void pop();
    TContext&back();
    TContext&front();
    int size()const;
    bool empty()const;
    TContext&operator[](int index);
  };
public:
  TBranch branch;
public:
  void push(DevCmd&Cmd);
  void pop(DevCmd&Cmd);
};

struct TOutDevScopeMemberID
{
  typedef int(*t_get_field_id_func)();
  TSuperOutDevice&dev;
  TOutDev::TMemberID devcmd;
  TOutDevScopeMemberID(TSuperOutDevice&dev,const t_get_field_id_func&func);
  ~TOutDevScopeMemberID();
};

struct TOutDevScopeVecID
{
  TSuperOutDevice&dev;
  TOutDev::TVecID devcmd;
  TOutDevScopeVecID(TSuperOutDevice&dev,int id);
  ~TOutDevScopeVecID();
};

struct TOutDevScopeChunk
{
  TSuperOutDevice&dev;
  TOutDev::TChunk devcmd;
  TOutDevScopeChunk(TSuperOutDevice&dev);
  ~TOutDevScopeChunk();
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
    operator IEnvRTTI&();
  };
  virtual void Render(t_context&con);
  virtual void Update(t_context&con);
  void TryRender(t_context&con);
  void TryUpdate(t_context&con);
};

class TRenderNode:public IRenderProgram
{
public:
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
  TYPE*AddItem(IEnvRTTI&Env);
public:
  void Render(t_context&con);
  void Update(t_context&con);
public:
  TAutoPtr<IRenderProgram>&front();
  TAutoPtr<IRenderProgram>&back();
public:
  bool empty()const;
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
public:
  void InitSysRes(IEnvRTTI&Env);
public:
  void CleanResList();
public:
  void SceneUpdate(IEnvRTTI&Env);
public:
  void SceneUpdateEx(IRenderProgram::t_context&con);
  void SceneRenderEx(IRenderProgram::t_context&con) ;
public:
  void SceneDoMove(IRenderProgram::t_context&con);
  void SceneDoDraw(IRenderProgram::t_context&con);
public:
  void init_d3d();
  void init(IEnvRTTI&Env,const string&caption);
  static string get_file_name()
  {
    return "data.qap";
  }
  void loop(IEnvRTTI&Env);
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
  void Render(t_context&con);
  void Update(t_context&con);
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
  void Update(t_context&con);
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
  TGUIRect(const vec2i&pos,const vec2i&size);
  TGUIRect(vec2i&&pos,vec2i&&size);
  vec2i getQuadPoint(bool x,bool y)const;
  vec2i getQuadPoint(int id)const;
  bool CheckPoint(const vec2i&p)const;
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
  virtual void Render(TRenderContext&Context);
  struct TUpdateContext
  {
    vec2i pos;
    vec2i size;
    vec2i mpos;
    int zDelta;
    IRenderProgram::t_context&context;
    QapKeyboard&keyboard;
  };
  virtual void Update(TUpdateContext&Context);
public:
  virtual void GetSize(IRenderProgram::t_context&context,vec2i&size);
public:
  static void DrawGreenTrigon(TRenderContext&Context,int c32=32);
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
  static bool toMonoEx(const string&line,string&mono);
  struct SelectIdUpdater
  {
    int x;
    int y;
    int dy;
    int dx;
    QapFont&font;
    const vec2i&Pos;
    const vec2i&MPos;
    SelectIdUpdater(QapFont&font,int zDelta,const vec2i&Pos,const vec2i&MPos);
    bool skip_line(const TGUIRect&Rect);
    bool foo(TIndentStrLine&ex);
    bool foo(const string&ex);
    void next_line();
  };
  void Render(TRenderContext&Context);
  void GetSize(IRenderProgram::t_context&context,vec2i&size);
  void Update(TUpdateContext&Context);
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
  void change_base(TWeakPtr<TType>&pBaseType);
  void change_base_raw(TType*pBaseType);
  static TType*GetTAutoPtr_ElemType_From_RawPtr(TRawPtr&raw_ptr);
  void change_base_ex(ITreeDebuggerBranch&Branch);
public:
  struct Hidden
  {
    vector<TWeakPtr<TType>>&list;
    void add(TType*pType);
    void render(QapDev&qDev,QapFont&font);
    void FindAllDerivedTypes(IEnvRTTI&Env,TType*pBaseType);
  };
public:
  template<int>
  void weak_update(IEnvRTTI&Env,QapTreeDebugger&qtd);
  void Update(IEnvRTTI&Env);
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
    void Update();
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
      TOutDevBuff(OutDevice&OD);
      void push();
      void pop();
      bool grab(IEnvRTTI&Env,TBranch*p,TType*pTBranch);
    };
    struct TMeCallBack:OutDevice::IExternalCallBack
    {
      int index;
      TOutDevEx::TCmdHeadVisitor&Head;
      TBranch&Branch;
      QapKeyboard&KB;
      TMeCallBack(TOutDevEx::TCmdHeadVisitor&Head,TBranch&Branch,QapKeyboard&KB);
      bool Pass(string&buff);
      void Next();
      void OnSelect();
    };
    void UpdateCode();
    TRawPtr GetRawPtr();
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
    virtual TRawPtr GetRawPtr();
    virtual string GetCode();
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
  vec2i get_pos(t_context&con);
  void Render(t_context&con);
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
    TCallBack(QapKeyboard&KB);
  public:
    void MicroCode(OutDevice&OD);
    void BranchCode(OutDevice&OD);
  public:
    void OnVar(OutDevice&OD,LineField&Field);
    void OnType(OutDevice&OD,LineField&Field);
    void OnValue(OutDevice&OD,LineField&Field);
    void OnSys(OutDevice&OD,LineField&Field);
  public:
    struct KeyTools_WeakPtrToField
    {
      bool Passed;
      KeyTools_WeakPtrToField();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_SelfPtrConnect
    {
      bool Passed;
      KeyTools_SelfPtrConnect();
      void Before(TCallBack&CB,OutDevice&OD);
      static TWeakPtr<IEsoteric>*get_weakptr(const TRawPtr&raw_ptr,TTypeWeakPtr*&pType);
      static TSelfPtr<IEsoteric>*get_selfptr(const TRawPtr&raw_ptr,TTypeSelfPtr*&pType);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_WeakPtrClear
    {
      bool Passed;
      KeyTools_WeakPtrClear();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_WeakPtrConnect
    {
      bool Passed;
      KeyTools_WeakPtrConnect():Passed(false) {};
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
  public:
    struct KeyTools_VectorClear
    {
      bool Passed;
      KeyTools_VectorClear();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_VectorIncDec
    {
      int dVecCount;
      KeyTools_VectorIncDec();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_FieldPtrClear
    {
      bool Passed;
      KeyTools_FieldPtrClear();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_AutoPtrClear
    {
      bool Passed;
      KeyTools_AutoPtrClear();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
    struct KeyTools_AutoPtrSelectBase
    {
      bool Passed;
      KeyTools_AutoPtrSelectBase();
      void Before(TCallBack&CB,OutDevice&OD);
      void After(QapTreeDebugger&QTD,TCallBack&CB);
    };
  public:
    void OnValueAll(OutDevice&OD,LineField&Field);
    void OnSysAll(OutDevice&OD,LineField&Field);
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
    void CallAfterAllKeyTools(QapTreeDebugger&QTD);
    //--==>>end
#undef DEF_PRO_LIST
    //<<==--end
  };
public:
  TBranch*GetSelectBranchId();
public:
  static int get_field_index_in_type(TType*pType,const string&field);
  static int get_Select_field_index_in_QapTreeDebugger(TWeakPtr<TType>&pTypeThis);
  void AddLine(int indent,const string&text);
  void Update(t_context&con);
  void branches_update();
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
  void Render(t_context&con);
  void Update(t_context&con);
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
  void Render(t_context&con);
  void Update(t_context&con);
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
    t_context fork()const;
    template<class TRawRect>
    t_context&use_rect(TRawRect&rect);
    template<class TRawRect>
    t_context make_sub_context(TRawRect&rect);
    template<int>
    vec2i weak_get_mpos();
    vec2i get_mpos();
    template<int>
    bool weak_is_head_book();
    bool is_head_book();
    template<int>
    QapFontObject*weak_get_head_book_fontgen();
    QapFontObject*get_head_book_fontgen();
    bool is_hovered();
    string GetCurBranchAsStr(void*pThis,int start_id=0);
    vec2i ScreenSpaceToPageSpace(const vec2i&p);
    vec2i PageSpaceToScreenSpace(const vec2i&p);
  };
  virtual void Render(t_context&con);
  virtual void Update(t_context&con);
};

struct t_book_path_scope
{
  IBookPage::t_context&con;
  bool skip;
  TDay20140605Book*pBook;
  t_book_path_scope(IBookPage::t_context&con);
  ~t_book_path_scope();
};

class TDay20140605Book
{
public:
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
  static void DrawBorder(QapDev&qDev,const vec2i&pos,const vec2i&size,int ls);
  struct t_book_info
  {
    vec2i body_pos;
    vec2i body_size;
    vec2i header_pos;
    vec2i header_size;
  };
  t_book_info get_header_info(const vec2i&pos,const vec2i&size);
  void DrawOldText(QapDev&qDev,const string&text,const vec2i&pos);
  void DrawHeader(QapDev&qDev,const vec2i&mpos,const vec2i&pos,const vec2i&size);
  void DoDrawPageContent(t_context&con);
  void DoSelectPage(t_context&con);
  template<int>
  void DoFullScreen(t_context&con);
  void DoMovePageContent(t_context&con);
  void Render(t_context&con);
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env);
  template<int>
  void InitPages(IEnvRTTI&Env);
  void DoClean();
  void Update(t_context&con);
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
  vec2i get_size()const;
  static array<int,2> get_arr_x(int cpx,int px,int w);
  static int get_new_w(int mpx,int off,int px,int pid);
  static void calc_new_w_and_pos(int mpx,int off,int&w,int&px,int pid);
  void RenderBack(t_context&con);
  void RenderBorder(t_context&con);
  void RenderPoints(t_context&con);
  void Render(t_context&con);
  void Update(t_context&con);
  static void update_point(
    int&pid,int point_size,
    int mpx,int mpy,
    bool&down,bool d,bool ondown,bool shift,
    vec2i&off,
    int&px,int py,
    int&w,int h,int&cid,int this_cid
  );
  void UpdateEx(t_context&con,const vec2i&hp,const vec2i&hs);
};


class TMultyBook
{
public:
  class TBook
  {
  public:
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
  void Render(t_context&con);
  void Update(t_context&con);
  static void RenderBook(t_context&con,TBook&Book);
  static void UpdateBook(t_context&con,TBook&ref);
};

class TBookPageWithMultyBook:public IBookPage
{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithMultyBook)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TMultyBook,books,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithMultyBook
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithMultyBook
public:
  void Render(t_context&con);
  void Update(t_context&con);
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

static bool super_dev_add_way_v00(TSuperOutDevice&dev,vector<TAutoPtr<TOutDev::DevCmd>>&way);

static void super_dev_del_way_v00(TSuperOutDevice&dev,vector<TAutoPtr<TOutDev::DevCmd>>&way);

class TDay20140605BookV00:public IRenderProgram
{
public:
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
  void Render(t_context&con);
  void update_fullscreen(QapKeyboard&kb);
  void Update(t_context&con);
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
  void Render(t_context&con);
  void Update(t_context&con);
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
  bool is_selected();
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
    void next_line();
    void operator()(unsigned char UC,const vec2i&p,const vec2i&size);
    void find_mpos(bool end_of_line,const vec2i&p,const vec2i&size);
    void loop_ex(QapFont&font);
    struct t_dev
    {
      t_text_renderer&owner;
      const string&text;
      int offset;
      int size;
      vector<vec2i> stack;
      void push();
      void pop();
      bool go_end(char c);
      static int find_not(const string&text,int offset,char c);
    };
    bool is_end_of_context()const;
    void handle_line(t_dev&dev,QapDev&qDev,QapFont&font,bool need_draw);
    void handle_text(t_dev&dev,QapDev&qDev,QapFont&font,bool need_draw);
    void new_loop(QapDev&qDev,QapFont&font,bool need_draw);
    void loop(QapDev&qDev,QapFont&font,bool need_draw);
  };
public:
  t_text_renderer make_tr(t_context&con);
  void Render(t_context&con);
  static vec2i get_caret_pos(const string&text,int caret_pos);
  static bool is_allowed_char(char c);
  static bool is_char_from_word(char c);
  static size_t find_end_of_word(const string&text,size_t offset);
  static size_t rfind_begin_of_word(const string&text,size_t offset);
  void UpdateCarPos(t_context&con);
  void insert_string(t_context&con,const string&content);
  void UpdateText(t_context&con);
  static string strpad(const string&s,int n);
  static string toStr(const vec2i&v);
  void log(const string&msg);
  void UpdateMouse(t_context&con);
  void Update(t_context&con);
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
  static string this_class_is_copypaste_of();
  static bool toMonoEx(const string&line,string&mono);
  void Render(t_context&con);
  void Update(t_context&con);
};

class TRawRectAndMenuItems
{
public:
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
  void Render(t_context&con);
  void Update(t_context&con);
};

class TPageWithPageAdder:public IBookPage
{
public:
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
  void Render(t_context&con);
  void Update(t_context&con);
  void OnDown(t_context&con);
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
  void Render(t_context&con);
  void Update(t_context&con);
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
  void Render(t_context&con);
  void Update(t_context&con);
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
  bool contains(const vec2i&point);
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
  void Render(t_context&con);
  t_quad get_quad(t_context&con)const;
  void set_quad(t_context&con);
  void Update(t_context&con);
};

class t_raw_rect_splitter_tool
{
public:
  typedef IBookPage::t_context t_context;
public:
#define IMPL_d(t_vec,t_comp)static t_comp&get_d(char dir,t_vec&v);
#define IMPL_n(t_vec,t_comp)static t_comp&get_n(char dir,t_vec&v);
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
  static int&get_d(char dir,TRawRect&rect);
  static int&get_n(char dir,TRawRect&rect);
  // if dir=='y' then 'd'=='y' or 'd'=='h' else 'd'=='x or 'd'=='w'
  static void update_rects(t_context&con,const TScrollBar&bar,TRawRect&view_rect,TRawRect&editor_rect,int ls);
};

class TProgramWithIBookPageAdopter:public IRenderProgram
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramWithIBookPageAdopter)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IBookPage>,page,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramWithIBookPageAdopter
#include "QapGenStruct.inl"
//<<<<<+=====TProgramWithIBookPageAdopter
public:
  void Render(t_context&con);
  void Update(t_context&con);
  void PageRender(IBookPage::t_context&con);
  void PageUpdate(IBookPage::t_context&con);
};

//#undef DEF_PRO_SYS_GET_FIELD_ID
#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#include "QapVec.h"
//-------------------------------------------//
#pragma warning(disable:4482) //QapD3DDev9::BlendType::BT_ADD vs QapD3DDev9::BT_ADD
//-------------------------------------------//

#ifdef DEF_BUILD_MACRO
  #include "../Macro/QapDev.h"
#else
//=====>>>>>QapDev

class QapDev
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapDev OwnerClass;
    void operator=(OwnerClass*pOwner);
  public:
    TDynamicResource();
    ~TDynamicResource();
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev);
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost();
    void OnReset();
  };
public:
  struct Ver
  {
    float x,y,z;
    QapColor color;
    float tu,tv;
    Ver();
    Ver(float x,float y,const QapColor&color,float u=0.0,float v=0.0);
    Ver(const vec2f&pos,const QapColor&color,float u=0.0,float v=0.0);
    Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord);
    vec2f&get_pos();
    vec2f&get_pos()const;
    vec2f&get_tpos();
    vec2f&get_tpos()const;
  };
  struct BatchScope{
    QapDev&RD;
    bool flag;
    BatchScope(QapDev&RD);
    ~BatchScope();
  };
public:
  typedef QapD3DDev9::BlendType BlendType;
  typedef QapD3DDev9::AlphaType AlphaType;
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapDev)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TDynamicResource,DynRes,SYS,this,$)\
ADDVAR(IDirect3DDevice9*,pDev,SYS,nullptr,$)\
ADDVAR(IDirect3DVertexBuffer9*,VB,SYS,nullptr,$)\
ADDVAR(IDirect3DIndexBuffer9*,IB,SYS,nullptr,$)\
ADDVAR(Ver*,VBA,SYS,nullptr,$)\
ADDVAR(int*,IBA,SYS,nullptr,$)\
ADDVAR(QapColor,color,SYS,0xFFFFFFFF,$)\
ADDVAR(int,VPos,SYS,0,$)\
ADDVAR(int,IPos,SYS,0,$)\
ADDVAR(int,MaxVPos,SYS,0,$)\
ADDVAR(int,MaxIPos,SYS,0,$)\
ADDVAR(int,DIPs,SYS,0,$)\
ADDVAR(int,Verts,SYS,0,$)\
ADDVAR(int,Tris,SYS,0,$)\
ADDVAR(BlendType,BlendMode,SYS,BlendType::BT_SUB,$)\
ADDVAR(AlphaType,AlphaMode,SYS,AlphaType::AM_NONE,$)\
ADDVAR(bool,Batching,SYS,false,$)\
ADDVAR(bool,Textured,SYS,false,$)\
ADDVAR(transform2f,xf,SYD,$,$)\
ADDVAR(transform2f,txf,SYD,$,$)\
ADDEND()
//=====+>>>>>QapDev
#include "QapGenStruct.inl"
//<<<<<+=====QapDev
protected:
  static const DWORD FVF=D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1;
public:
  ~QapDev(){Free();}
public:
  void ReInit();
  void MountDev(QapD3DDev9&Dev);
  void Init(int VCount,int ICount);
  void Free();
public:
  void QapDev::BeginBatch();
  void EndBatch();
  void DIP();
  bool IsBatching();
  int GetIPos();
  int GetVPos();
  int GetDIPs();
  int GetVerts();
  int GetTris();
  const QapColor&GetColor();
  void NextFrame();
public:
  void HackMode(bool Textured);
  template<class QAP_TEX>
  void BindTex(int Stage,QAP_TEX*pTex);
  void BindTex(int Stage,const nullptr_t);
public:
  inline Ver&AddVertexRaw();
  inline int AddVertex(const Ver&Source);
  inline int AddVertex(float x,float y,const QapColor&c,float u,float v);
  inline int AddVertex(const vec2f&pos,const QapColor&c,float u,float v);
  inline int AddVertex(const vec2f&pos,const QapColor&c,const vec2f&tpos);
  inline void AddTris(int A,int B,int C);
public:
  inline void SetColor(const QapColor&C);
  inline void SetTransform(transform2f const&val);
  inline transform2f GetTransform();
  inline void SetTextureTransform(transform2f const&val);
  inline transform2f GetTextureTransform();
public:
  BlendType GetBlendMode();
  AlphaType GetAlphaMode();
  void SetBlendMode(BlendType Mode);
  void SetAlphaMode(AlphaType Mode);
public:
  void DrawSolidRect(const vec2d&a,const vec2d&b);
  void DrawRect(const vec2i&ap,const vec2i&bp,int line_size);
  void DrawRect(const vec2d&a,const vec2d&b,int line_size);
  void DrawRectAsQuad(const vec2i&pos,const vec2i&size,int line_size);
  void DrawRectAsQuad(const vec2d&pos,const vec2d&size,int line_size);
  void DrawQuadWithHalfPixelOffset(int x,int y,int w,int h);
  void DrawQuadWithHalfPixelOffset(const vec2i&p,int w,int h);
  void DrawQuadWithHalfPixelOffset(const vec2i&p,const vec2i&size);
  void DrawQuad(float x,float y,float w,float h);
  void DrawQuad(float x,float y,float w,float h,float a);
  void DrawQuad(float x,float y,const vec2d&size,float ang);
  void DrawQuad(const vec2d&pos,const vec2d&size,float ang);
  void DrawQuad(const vec2d&pos,const vec2d&size);
  void DrawQuad(const vec2d&pos,float w,float h,float ang);
  void DrawQuad(const vec2d&pos,float w,float h);
  void DrawTrigon(const vec2d&A,const vec2d&B,const vec2d&C);
  void DrawConvex(const vector<vec2d>&Points);
public:
  template<typename TYPE>
  void DrawPolyLine(const vector<TYPE>&PA,const real&LineSize,const bool&Loop);
  template<typename TYPE>
  void DrawLineList(const vector<TYPE>&PA,const real&LineSize);
  template<typename TYPE>
  void DrawMesh(const vector<TYPE>&VA,const vector<int>&IA);
  void DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg);
  void DrawCircle(const vec2d&pos,real r,real ang,real ls,int seg);
  void DrawCircleEx(const vec2d&pos,real r0,real r1,int seg,real ang);
};

template<class TYPE>
class QapArray{
public:
  TMemory Mem;
  QapArray();
  ~QapArray();
  QapArray(const QapArray<TYPE>&Ref);
  void operator=(const QapArray<TYPE>&Ref);
  void oper_set(const QapArray<TYPE>&Ref);
  QapArray(QapArray<TYPE>&&Ref);
  void operator=(QapArray<TYPE>&&Ref);
  void oper_set(QapArray<TYPE>&&Ref);
  operator bool()const;
  TYPE&operator[](size_t index);
  const TYPE&operator[](size_t index)const;
  void Init(int size);
  void Free();
  TYPE*get();
  const TYPE*get()const;
};

class QapTexMem{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTexMem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(QapArray<QapColor>,Arr,SYD,$,$)\
ADDVAR(int,W,SYS,0,$)\
ADDVAR(int,H,SYS,0,$)\
ADDEND()
//=====+>>>>>QapTexMem
#include "QapGenStruct.inl"
//<<<<<+=====QapTexMem
public:
  QapTexMem();
  QapTexMem(const QapTexMem&Ref);
  void operator=(const QapTexMem&Ref);
  void oper_set(const QapTexMem&Ref);
  QapTexMem(QapTexMem&&Ref);
  void operator=(QapTexMem&&Ref);
  void oper_set(QapTexMem&&Ref);
  QapTexMem Clone();
  void CopyDataFrom(const QapTexMem&Ref);
  void MoveDataFrom(QapTexMem&Ref);
  void Init(int W,int H);
  void Free();
  QapColor*get();
  const QapColor*get()const;
  operator bool()const;
public:
  void InvertY();
  void InvertX();
public:
  void GenRect(int TexSize);
  void GenBall(int TexSize);
  void GenQuad(int TexSize);
  void FillBorder(int x,int y,const QapTexMem&Source,int n=4);
  void FillMem(int x,int y,const QapTexMem&Source);
  void DrawInHalfScale(const QapTexMem&Source,int count);
  void DrawMemWithBlend(int x,int y,const QapTexMem&Source,const QapColor&color);
  void Clear(const QapColor&color=0xFF000000);
  void FillLine(const int Y,const QapColor&Color);
  void FillColumn(const int X,const QapColor&Color);
  void RectLine(int X,int Y,int W,int H,const QapColor&Color);
  void FillLineEx(const int Y,const int X0,const int X1,const QapColor&Color);
  void FillColomnEx(const int X,const int Y0,const int Y1,const QapColor&Color);
public:
  void CopyAlpha(QapTexMem&Alpha);
  void CalcAlpha();
  void CalcAlpha(const QapColor&Color,int threshold=0);
  void DrawSolidCircle(int x,int y,int r,const QapColor&color);
  void DrawSolidQuad(int x,int y,int w,int h,const QapColor&color);
  void FillChannel(const QapColor&Source,DWORD BitMask);
  void BlurTexture(int PassCount);
};

#define DEF_ADD_HUMUS_HEAD
#include "QapHumus.inl"
#undef DEF_ADD_HUMUS_HEAD

class QapTexFile{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTexFile)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,FN,DEF,$,$)\
ADDVAR(QapTexMem,Mem,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTexFile
#include "QapGenStruct.inl"
//<<<<<+=====QapTexFile
public:
  void Load();
  void Save();
};

class QapTex{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapTex OwnerClass;
    void operator=(OwnerClass*pOwner);
  public:
    TDynamicResource();
    ~TDynamicResource();
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev);
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost();
    void OnReset();
  };
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(int,W,SYS,0,$)\
ADDVAR(int,H,SYS,0,$)\
ADDVAR(TDynamicResource,DynRes,SYS,this,$)\
ADDVAR(IDirect3DTexture9*,Tex,SYS,nullptr,$)\
ADDEND()
//=====+>>>>>QapTex
#include "QapGenStruct.inl"
//<<<<<+=====QapTex
public:
  ~QapTex();
public:
  void ReInit();
  void MountDev(QapD3DDev9&Dev);
  void Init(int W,int H,int Levels);
  void Free();
  operator bool()const;
  void Bind(int lvl=0);
public:
  void QapTex::operator=(const QapTex&);
};

class TResourceHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TResourceHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDEND()
//=====+>>>>>TResourceHolder
#include "QapGenStruct.inl"
//<<<<<+=====TResourceHolder
public:
};

class QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(vector<TWeakPtr<TResourceHolder>>,Holders,DEF,$,$)\
ADDEND()
//=====+>>>>>QapResource
#include "QapGenStruct.inl"
//<<<<<+=====QapResource
public:
  class IEnv{
  public:
    IEnvRTTI&Env;
    QapD3DDev9*pDev;
    operator IEnvRTTI&();
  };
public:
  virtual void Do(IEnv&Env);
public:
  void Run(IEnvRTTI&Env,QapD3DDev9*pDev);
};

// Владелец ресурсов.
class QapResourceList:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapResourceList)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<QapResource>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>QapResourceList
#include "QapGenStruct.inl"
//<<<<<+=====QapResourceList
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env,TResourceHolder&ResHolder,const string&Caption);
  void Del();
public:
  void Do(IEnv&Env);
};

class QapTexGen{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTexGen)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<QapTexMem>,Mem,DEF,$,$)\
ADDVAR(TWeakPtr<QapTex>,Tex,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTexGen
#include "QapGenStruct.inl"
//<<<<<+=====QapTexGen
public:
  static void Gen(QapTexMem*Mem,QapTex*Tex,int MaxLevelCount=16);
public:
  void Do();
};

class QapTexObject:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTexObject)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapTexFile,File,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(QapTexGen,Gen,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTexObject
#include "QapGenStruct.inl"
//<<<<<+=====QapTexObject
public:
  void SetToDef();
  struct t_fn_parser{
    string fn;
    string func;
    string size;
    int value;
    bool main();
  };
  void Do(IEnv&Env);
};

class QapResourceDetector{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapResourceDetector OwnerClass;
    void operator=(OwnerClass*pOwner);
  public:
    TDynamicResource();
    ~TDynamicResource();
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev);
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost();
    void OnReset();
  };
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapResourceDetector)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,needinit,SET,false,$)\
ADDVAR(TDynamicResource,DynRes,SYS,this,$)\
ADDVAR(bool,used,SYS,false,$)\
ADDEND()
//=====+>>>>>QapResourceDetector
#include "QapGenStruct.inl"
//<<<<<+=====QapResourceDetector
public:
  ~QapResourceDetector(){Free();}
public:
  void MountDev(QapD3DDev9&Dev);
  void PreInit();
  void PreFree();
  void Init();
  void Free();
  operator bool()const;
};

template<class TYPE,unsigned int SIZE>class ArrayTypeSolver{};

class QapFontInfo{
public:
  typedef vec2i vec2i_256[256];
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapFontInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i_256,Coords,SYD,$,$)\
ADDEND()
//=====+>>>>>QapFontInfo
#include "QapGenStruct.inl"
//<<<<<+=====QapFontInfo
public:
  vec2i&operator[](int index);
  const vec2i&operator[](int index)const;
};

class QapFont{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapFont)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(QapTexMem,Mem,DEF,$,$)\
ADDVAR(QapFontInfo,Info,DEF,$,$)\
ADDEND()
//=====+>>>>>QapFont
#include "QapGenStruct.inl"
//<<<<<+=====QapFont
public:
};

class QapFontGen{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapFontGen)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Name,SET,1?"FixedSys":"Arial",$)\
ADDVAR(int,Size,SET,1?10:14,$)\
ADDVAR(bool,Bold,SET,false,$)\
ADDVAR(int,TexSize,SET,512,$)\
ADDVAR(TWeakPtr<QapFont>,Font,DEF,$,$)\
ADDEND()
//=====+>>>>>QapFontGen
#include "QapGenStruct.inl"
//<<<<<+=====QapFontGen
public:
  void Do(HWND hWnd);
public:
  static void CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize);
};

class QapFontObject:public QapResource{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapFontObject)PARENT(QapResource)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapFont,Font,DEF,$,$)\
ADDVAR(QapFontGen,FontGen,DEF,$,$)\
ADDVAR(QapTex,Tex,DEF,$,$)\
ADDVAR(QapTexGen,TexGen,DEF,$,$)\
ADDEND()
//=====+>>>>>QapFontObject
#include "QapGenStruct.inl"
//<<<<<+=====QapFontObject
public:
  void SetToDef();
  void MountDev(QapD3DDev9*pDev);
  void DoGenFont(QapD3DDev9*pDev);
  void DoGenTex();
  void Do(IEnv&Env);
};

class QapQ3Text{
public:
  static int GetLength(const QapFont&Font,const string&Text);
public:
  static string ToNormal(const string&Text);
public:
  static int AddVertexEx(QapDev*RD,float x,float y,QapColor c,float u,float v);
  static void DrawQapText(QapDev*RD,QapFont&Font,float X,float Y,const string&Text);
};


class QapText{
public:
  static int GetLength(const QapFont&Font,const string&Text);
public:
  static int AddVertexEx(QapDev&qDev,float x,float y,QapColor c,float u,float v);
  struct t_draw_call{
    char c;
    vec2i pos;
    vec2i size;
  };
  static void add_draw_call(vector<t_draw_call>&out,char c,const vec2i&pos,const vec2i&size);
  template<class FUNC>
  static void PreDrawEx(QapFont&Font,float X,float Y,const string&Text,/*vector<t_draw_call>&out,*/FUNC&func);
  template<class FUNC>
  static void DrawEx(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text,FUNC&func);
  static void DoNothing(unsigned char UC,const vec2i&p,const vec2i&s);
  static void Draw(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text);
};

//<<<<<=====QapDev
#endif //DEF_BUILD_MACRO//

//-------------------------------------------//
//   {<|          04.06.2014           |>}   //
//-------------------------------------------//
#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
//#include <Box2D/box2d.h>
//#include "QapSys.h"
#include "QapVec.h"
//#include "QapMatrix.h"
//#include "QapDX.h"
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
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr){
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource(){
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost(){if(pOwner){flag=bool(pOwner->VB);pOwner->Free();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->ReInit();}
  };
public:
  struct Ver
  {
    float x,y,z;
    QapColor color;
    float tu,tv;
    Ver():x(0),y(0),z(0),tu(0),tv(0){}
    Ver(float x,float y,const QapColor&color,float u=0.0,float v=0.0):x(x),y(y),z(0),color(color),tu(u),tv(v){}
    Ver(const vec2f&pos,const QapColor&color,float u=0.0,float v=0.0):x(pos.x),y(pos.y),z(0),color(color),tu(u),tv(v){}
    Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord):x(pos.x),y(pos.y),z(0),color(color),tu(texcoord.x),tv(texcoord.y){}
    vec2f&get_pos(){return *(vec2f*)&x;}
    vec2f&get_pos()const{return *(vec2f*)&x;}
    vec2f&get_tpos(){return *(vec2f*)&tu;}
    vec2f&get_tpos()const{return *(vec2f*)&tu;}
  };
  struct BatchScope{
    QapDev&RD;
    bool flag;
    BatchScope(QapDev&RD):RD(RD){flag=!RD.Batching;if(flag)RD.BeginBatch();}
    ~BatchScope(){if(flag)RD.EndBatch();}
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
  void ReInit(){Init(MaxVPos,MaxIPos);}
  void MountDev(QapD3DDev9&Dev){
    this->pDev=Dev.pDev;
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int VCount,int ICount)
  {
    if(!VB)
    {
      MaxVPos=VCount; MaxIPos=ICount;
      pDev->CreateVertexBuffer(VCount*sizeof(Ver),D3DUSAGE_DYNAMIC,FVF,D3DPOOL_DEFAULT,&VB,NULL);
      pDev->CreateIndexBuffer(ICount*sizeof(int),D3DUSAGE_DYNAMIC,D3DFMT_INDEX32,D3DPOOL_DEFAULT,&IB,NULL);
      VBA=0; IBA=0; VPos=0; IPos=0; DIPs=0; Verts=0; Tris=0;
      xf.set_ident();
      txf.set_ident();
    };
  }
  void Free(){
    if(VB){
      VB->Release();
      VB=nullptr;
      VBA=nullptr;
    }
    if(IB){
      IB->Release();
      IB=nullptr;
      IBA=nullptr;
    }
    VPos=0;IPos=0;
    Batching=false;
    BlendMode=BlendType::BT_SUB;
    AlphaMode=AlphaType::AM_NONE;
  };
public:
  void QapDev::BeginBatch()
  {
    Batching=true;
    VBA=0;IBA=0;VPos=0;IPos=0;//Test it
    if(!IB||!VB)return;
    IB->Lock(0,sizeof(int)*MaxIPos,(void **)&IBA,0);
    VB->Lock(0,sizeof(Ver)*MaxVPos,(void **)&VBA,0);
  };
  void EndBatch()
  {
    Batching=false;
    if(!IB||!VB)return;
    IB->Unlock(); VB->Unlock();  
    if(VPos&&IPos){
      DIP();
    }
    VBA=0;IBA=0;
  }
  void DIP()
  {
    pDev->SetFVF(FVF);
    pDev->SetStreamSource(0,VB,0,sizeof(Ver));
    pDev->SetIndices(IB);
    pDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,VPos,0,IPos/3);
    DIPs++;Verts+=VPos;Tris+=IPos/3;
  }
  bool IsBatching(){return Batching;}
  int GetIPos(){return IPos;}
  int GetVPos(){return VPos;}
  int GetDIPs(){return DIPs;}
  int GetVerts(){return Verts;}
  int GetTris(){return Tris;}
  const QapColor&GetColor(){return color;}
  void NextFrame(){DIPs=0;Verts=0;Tris=0;SetBlendMode(BlendMode);SetAlphaMode(AlphaMode);}
public:
  void HackMode(bool Textured){this->Textured=Textured;}
  template<class QAP_TEX>
  void BindTex(int Stage,QAP_TEX*pTex){QapTex*Tex=pTex;pDev->SetTexture(Stage,Tex?Tex->Tex:nullptr);txf.set_ident();Textured=Tex?true:false;}
  void BindTex(int Stage,const nullptr_t){pDev->SetTexture(Stage,nullptr);Textured=false;}
public:
  inline Ver&AddVertexRaw(){return VBA[VPos++];}
  inline int AddVertex(const Ver&Source)
  {
    QapAssert(VPos<MaxVPos);
    Ver&Dest=VBA[VPos];
    Dest=Source;
    {vec2f&v=Dest.get_pos();v=xf*v;}
    if(Textured){vec2f&v=Dest.get_tpos();v=txf*v;}
    return VPos++;
  }
  inline int AddVertex(float x,float y,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec2f&pos,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.get_pos()=pos;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec2f&pos,const QapColor&c,const vec2f&tpos)
  {
    QapDev::Ver tmp;
    tmp.get_pos()=pos;
    tmp.z=0;
    tmp.color=c;
    tmp.get_tpos()=tpos;
    auto id=AddVertex(tmp);
    return id;
  }
  inline void AddTris(int A,int B,int C)
  {
    QapAssert(IPos+2<MaxIPos);
    QapAssert(A>=0&&A<MaxVPos);
    QapAssert(B>=0&&B<MaxVPos);
    QapAssert(C>=0&&C<MaxVPos);
    IBA[IPos++]=A;
    IBA[IPos++]=B;
    IBA[IPos++]=C;
  };
public:
  inline void SetColor(const QapColor&C){color=C;}
  inline void SetTransform(transform2f const&val){xf=val;}
  inline transform2f GetTransform(){return xf;}
  inline void SetTextureTransform(transform2f const&val){txf=val;}
  inline transform2f GetTextureTransform(){return txf;}
  //inline real GetZoom(){return vec2d(xf.q).Mag();}
public:
  BlendType GetBlendMode(){return BlendMode;}
  AlphaType GetAlphaMode(){return AlphaMode;}
  void SetBlendMode(BlendType Mode){DynRes.pDev->Blend(BlendMode=Mode);}
  void SetAlphaMode(AlphaType Mode){DynRes.pDev->Alpha(AlphaMode=Mode);}
public:
  void DrawSolidRect(const vec2d&a,const vec2d&b)
  {
    BatchScope Scope(*this);
    {
      #define F(X,Y,U,V){AddVertex(X,Y,color,U,V);}
      int n=VPos;
      F(a.x,a.y,0.0f,1.0f);
      F(b.x,a.y,1.0f,1.0f);
      F(b.x,b.y,1.0f,0.0f);
      F(a.x,b.y,0.0f,0.0f); 
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
      #undef F
    }
  }
  void DrawRect(const vec2i&ap,const vec2i&bp,int line_size)
  {
    BatchScope Scope(*this);
    {
      auto a=vec2i(std::min(ap.x,bp.x),std::min(ap.y,bp.y));
      auto b=vec2i(std::max(ap.x,bp.x),std::max(ap.y,bp.y));
      //vec2d n;
      auto hs=line_size*0.5;
      //n=vec2d(+1,+1)*0.5*line_size;
      DrawSolidRect(vec2d(a.x-hs,a.y-hs),vec2d(b.x+hs,a.y+hs));
      DrawSolidRect(vec2d(a.x-hs,b.y+hs),vec2d(b.x+hs,b.y-hs));
      //n=vec2d(+1,-1)*0.5*line_size;
      DrawSolidRect(vec2d(a.x-hs,a.y+hs),vec2d(a.x+hs,b.y-hs));
      DrawSolidRect(vec2d(b.x-hs,a.y+hs),vec2d(b.x+hs,b.y-hs));
    }
    int gg=1;
  }
  void DrawRect(const vec2d&a,const vec2d&b,int line_size)
  {
    BatchScope Scope(*this);
    {
      real x=(a.x+b.x)*0.5;
      real w=fabs(a.x-b.x);
      DrawQuad(x,a.y,line_size+w,line_size);
      DrawQuad(x,b.y,line_size+w,line_size);
      real y=(a.y+b.y)*0.5;
      real h=fabs(a.y-b.y);
      DrawQuad(a.x,y,line_size,-line_size+h);
      DrawQuad(b.x,y,line_size,-line_size+h);
    }
    int gg=1;
  }
  void DrawRectAsQuad(const vec2i&pos,const vec2i&size,int line_size)
  {
    auto a=pos-size/2;
    auto b=a+size;
    DrawRect(a,b,line_size);
  }
  void DrawRectAsQuad(const vec2d&pos,const vec2d&size,int line_size)
  {
    auto hs=size*0.5;
    DrawRect(pos-hs,pos+hs,line_size);
  }
  void DrawQuadWithHalfPixelOffset(int x,int y,int w,int h)
  {  
    DrawQuad(float(x)+0.5,float(y)-0.5,float(w),float(h));
  }
  void DrawQuadWithHalfPixelOffset(const vec2i&p,int w,int h)
  {  
    DrawQuadWithHalfPixelOffset(p.x,p.y,w,h);
  }
  void DrawQuadWithHalfPixelOffset(const vec2i&p,const vec2i&size)
  {  
    DrawQuadWithHalfPixelOffset(p.x,p.y,size.x,size.y);
  }
  void DrawQuad(float x,float y,float w,float h)
  {  
    BatchScope Scope(*this);
    {
      #define F(X,Y,U,V){AddVertex(x+(X)*w,y+(Y)*h,color,U,V);}
      //vec2d O(x,y);
      int n=VPos;
      F(-0.5f,-0.5f,0.0f,1.0f);
      F(+0.5f,-0.5f,1.0f,1.0f);
      F(+0.5f,+0.5f,1.0f,0.0f);
      F(-0.5f,+0.5f,0.0f,0.0f); 
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
      #undef F
    }
  }
  void DrawQuad(float x,float y,float w,float h,float a)
  {
    BatchScope Scope(*this);
    {
      vec2d OZ=Vec2dEx(a,1.0);
      vec2d O(x,y);
      int n=VPos;
      #define F(X,Y,U,V){AddVertex(vec2f(O+vec2d(X*w,Y*h).UnRot(OZ)),color,U,V);}
        F(-0.5f,-0.5f,0.0f,1.0f);
        F(+0.5f,-0.5f,1.0f,1.0f);
        F(+0.5f,+0.5f,1.0f,0.0f);
        F(-0.5f,+0.5f,0.0f,0.0f); 
      #undef F
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
    }
  }
  void DrawQuad(float x,float y,const vec2d&size,float ang)
  {
    DrawQuad(x,y,size.x,size.y,ang);
  }
  void DrawQuad(const vec2d&pos,const vec2d&size,float ang)
  {
    DrawQuad(pos.x,pos.y,size.x,size.y,ang);
  }
  void DrawQuad(const vec2d&pos,const vec2d&size)
  {
    DrawQuad(pos.x,pos.y,size.x,size.y);
  }
  void DrawQuad(const vec2d&pos,float w,float h,float ang)
  {
    DrawQuad(pos.x,pos.y,w,h,ang);
  }
  void DrawQuad(const vec2d&pos,float w,float h)
  {
    DrawQuad(pos.x,pos.y,w,h);
  }
  void DrawTrigon(const vec2d&A,const vec2d&B,const vec2d&C)
  {
    BatchScope Scope(*this);
    {
      AddTris(
        AddVertex(Ver(A,color)),
        AddVertex(Ver(B,color)),
        AddVertex(Ver(C,color))
      );
    }
  }
  void DrawConvex(const vector<vec2d>&Points)
  {
    BatchScope Scope(*this);
    {
      if(Points.empty())return;
      int c=Points.size();
      int n=VPos;
      for(int i=0;i<c;i++)AddVertex(Points[i],color,0.5,0.5);
      for(int i=2;i<c;i++)AddTris(n,n+i-1,n+i-0);
    }
  }
public:
  template<typename TYPE>
  void DrawPolyLine(const vector<TYPE>&PA,const real&LineSize,const bool&Loop)
  {
    if(PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      int c=Loop?Count:Count-1;
      for(int i=0;i<c;i++)
      {
        TYPE const&a=PA[(i+0)%Count];
        TYPE const&b=PA[(i+1)%Count];
        vec2d n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]={
        #define F(pos)AddVertex(pos,color,0.5f,0.5f)
          F(a+n),
          F(b-n),
          F(a-n),
          F(b+n),
        #undef F
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawLineList(const vector<TYPE>&PA,const real&LineSize)
  {
    if(PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      for(int i=0;i+1<Count;i+=2)
      {
        TYPE const&a=PA[i+0];
        TYPE const&b=PA[i+1];
        TYPE n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]={
        #define F(A)AddVertex(A,color,0.5,0.5)
          F(a+n),
          F(b-n),
          F(a-n),
          F(b+n),
        #undef F
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawMesh(const vector<TYPE>&VA,const vector<int>&IA)
  {
    QapDebugMsg("[2014.05.22]: way used?");
    if(VA.empty())return;
    BatchScope Scope(*this);
    {
      int base=GetVPos();
      static IntArray VID;VID.resize(VA.size());
      for(int i=0;i<VA.size();i++)VID[i]=AddVertex(MakeVer(VA[i],color,p.x,p.y));
      for(int i=0;i<IA.size();i+=3)AddTris(VID[IA[i+0]],VID[IA[i+1]],VID[IA[i+2]]);
    }
  }
  void DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    static PointArray PA; PA.resize(seg);
    for(int i=0;i<seg;i++)
    {
      vec2d v=Vec2dEx((real)i/(real)seg*2.0*Pi,r);
      PA[i]=pos+v;
    };
    DrawPolyLine(PA,ls,true);
  }
  void DrawCircle(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    DrawCircleEx(pos,r-ls*0.5,r+ls*0.5,seg,ang);
  }
  void DrawCircleEx(const vec2d&pos,real r0,real r1,int seg,real ang)
  {
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;VID.resize(n*2);
    for(int i=0;i<n;i++)
    {
      vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[0+i]=AddVertex(pos+v*r0,color,0,0);
      VID[n+i]=AddVertex(pos+v*r1,color,0,0);
    }
    for(int i=0;i<n;i++)
    {
      int a=VID[0+(i+0)%n];
      int b=VID[0+(i+1)%n];
      int c=VID[n+(i+0)%n];
      int d=VID[n+(i+1)%n];
      AddTris(a,b,d);
      AddTris(d,c,a);
    }
  }
};

template<class TYPE>
class QapArray{
public:
  TMemory Mem;
  QapArray(){}
  ~QapArray()
  {
    Free();
  }
  QapArray(const QapArray<TYPE>&Ref){oper_set(Ref);}
  void operator=(const QapArray<TYPE>&Ref){oper_set(Ref);}
  void oper_set(const QapArray<TYPE>&Ref)
  {
    Free();
    if(!Ref)return;
    Init(Ref.Mem.size);
    QapAssert(Ref.Mem.size==this->Mem.size);
    memcpy_s(this->Mem.ptr,this->Mem.size*sizeof(TYPE),Ref.Mem.ptr,Ref.Mem.size*sizeof(TYPE));
  }
  QapArray(QapArray<TYPE>&&Ref){oper_set(std::move(Ref));}
  void operator=(QapArray<TYPE>&&Ref){oper_set(std::move(Ref));}
  void oper_set(QapArray<TYPE>&&Ref)
  {
    Free();
    this->Mem=std::move(Ref.Mem);
  }
  operator bool()const{return Mem.ptr;}
  TYPE&operator[](size_t index){
    return (TYPE&)Mem.ptr[index*sizeof(TYPE)];
  }
  const TYPE&operator[](size_t index)const{
    return (const TYPE&)Mem.ptr[index*sizeof(TYPE)];
  }
  void Init(int size)
  {
    if(*this)Free();
    QapAssert(size>0);
    QapAssert(size<(1<<26));
    Mem.ptr=(TMemory::ptr_t*)(void*)new TYPE[size];
    Mem.size=size;
  }
  void Free()
  {
    if(!Mem.ptr)return;
    TYPE*p=(TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;
    delete[] p;
    Mem.ptr=nullptr;
    Mem.size=0;
  }
  TYPE*get(){return (TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;}
  const TYPE*get()const{return (TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;}
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
  QapTexMem(){DoReset();}
  QapTexMem(const QapTexMem&Ref){oper_set(Ref);}
  void operator=(const QapTexMem&Ref){oper_set(Ref);}
  void oper_set(const QapTexMem&Ref)
  {
    //`this->Self=this;
    this->Arr=Ref.Arr;
    this->W=Ref.W;
    this->H=Ref.H;
  }
  QapTexMem(QapTexMem&&Ref){oper_set(std::move(Ref));}
  void operator=(QapTexMem&&Ref){oper_set(std::move(Ref));}
  void oper_set(QapTexMem&&Ref)
  {
    this->Self=std::move(Ref.Self);
    this->Arr=std::move(Ref.Arr);
    this->W=std::move(Ref.W);
    this->H=std::move(Ref.H);
  }
  QapTexMem Clone(){
    QapTexMem tmp;
    tmp=*this;
    return std::move(tmp);
  }
  void CopyDataFrom(const QapTexMem&Ref){
    QapTexMem tmp;
    this->Arr=Ref.Arr;
    this->W=Ref.W;
    this->H=Ref.H;
  }
  void MoveDataFrom(QapTexMem&Ref){
    QapTexMem tmp;
    this->Arr=std::move(Ref.Arr);
    this->W=std::move(Ref.W);Ref.W=0;
    this->H=std::move(Ref.H);Ref.H=0;
  }
  void Init(int W,int H){this->W=W;this->H=H;Arr.Init(W*H);}
  void Free(){Arr.Free();}
  QapColor*get(){return Arr.get();}
  const QapColor*get()const{return Arr.get();}
  operator bool()const{return Arr;}
public:
  void InvertY()
  {
    QapColor*pBits=Arr.get();
    for(int i=0;i<H/2;i++)
    {
      int a=W*(i);
      int b=W*(H-i-1);
      for(int j=0;j<W;j++){std::swap(pBits[a+j],pBits[b+j]);}
    }
  }
  void InvertX()
  {
    QapColor*pBits=Arr.get();
    for(int i=0;i<H;i++)
    {
      QapColor*pLine=&pBits[i*W];
      for(int j=0;j<W/2;j++)
      {
        int a=j;
        int b=W-j-1;
        std::swap(pLine[a],pLine[b]);
      }
    }
  }
public:
  void GenRect(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for(int i=0;i<TexSize;i++)
    {
      for(int j=0;j<TexSize;j++)
      {
        *pT=0x80000000;
        pT++;
      }
    }
    RectLine(0,0,TexSize,TexSize,0xffffffff);
  }
  void GenBall(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for(int i=0;i<TexSize;i++)
    {
      for(int j=0;j<TexSize;j++)
      {
        //float x=i-TexSize/2+0.5f,y=j-TexSize/2+0.5f;
        float x=i-TexSize/2;float y=j-TexSize/2;
        float r=(float)TexSize/2;
        float m=((x*x)+(y*y))/(r*r);
        if(m>1.0f){
          *pT=0x00000000;pT++;continue;
        }
        //QapAssert(m<=1.0f);
        m=std::max(0.0f,1.0f-(m*m*m)); 
        //QapAssert(m<=1.0f);
        m=std::min(1.0f,m);
        float a=(m<0.5)?m*2:1;
        a=std::min(1.0f,a);
        a=std::max(0.0f,a);
        byte bm=m*255;
        pT->a=byte(a*255);
        pT->r=bm;
        pT->g=bm;
        pT->b=bm;
        pT++;
      }
    }
  }
  void GenQuad(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for(int i=0;i<TexSize;i++)
    {
      for(int j=0;j<TexSize;j++)
      {
        float x=i-TexSize/2+0.5f,y=j-TexSize/2+0.5f;
        float r=(float)TexSize/2;
        float m=((x*x*x*x)+(y*y*y*y))/(r*r*r*r);
        if(m>1.0f){
          *pT=0x00000000;pT++;continue;
        }
        m=std::max(0.0f,1.0f-(m*m*m)); 
        m=std::min(1.0f,m);
        float a=(m<0.5)?m*2:1;
        a=std::min(1.0f,a);
        a=std::max(0.0f,a);
        byte bm=m*255;
        pT->a=byte(a*255);
        pT->r=bm;
        pT->g=bm;
        pT->b=bm;
        pT++;
      }
    }
  }
  void FillBorder(int x,int y,const QapTexMem&Source,int n=4)
  {
    auto&Target=*this;
    if(!Source){
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    if(1)
    {
      #define F(i,j,v)if((y+(j))>=0)if((y+(j))<H)if((x+(i))<W)if((x+(i))>=0)pT[(x+(i))+(y+(j))*W]=(v);
      #define G(SX,SY,TX,TY){auto src=pS[(SX)+(SY)*sW];for(int i=0;i<n;i++)for(int j=0;j<n;j++)F(i+(TX),j+(TY),src);}
      G(00-0,00-0,00-n,00-n);
      G(sW-1,00-0,sW-0,00-n);
      G(sW-1,sH-1,sW-0,sH-0);
      G(00-0,sH-1,00-n,sH-0);
      #undef G
      #undef F
    }
    #define F(i,j)pS[(i-x)+(j-y)*sW]
    if(1)
    {
      for(int k=1;k<=n;k++)
      {
        {int j=00+y;if(InDip(0,j-k,H-1))for(int i=max(0,x);i<mX;i++){pT[i+(j-k)*W]=F(i,j);}}
        {int j=mY-1;if(InDip(0,j+k,H-1))for(int i=max(0,x);i<mX;i++){pT[i+(j+k)*W]=F(i,j);}}
        {int i=00+x;if(InDip(0,i-k,W-1))for(int j=max(0,y);j<mY;j++){pT[(i-k)+j*W]=F(i,j);}}
        {int i=mX-1;if(InDip(0,i+k,W-1))for(int j=max(0,y);j<mY;j++){pT[(i+k)+j*W]=F(i,j);}}
      }
    }
    #undef F
    return;
  }
  void FillMem(int x,int y,const QapTexMem&Source)
  {
    auto&Target=*this;
    if(!Source){
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for(int j=max(0,y);j<mY;j++){
      for(int i=max(0,x);i<mX;i++){
        pT[i+j*W]=pS[(i-x)+(j-y)*sW];
      }
    }
    return;
  } 
  void DrawInHalfScale(const QapTexMem&Source,int count)
  {
    if(count<0)return;
    if(!count){CopyDataFrom(Source);return;}
    //Init(Source.W/2,Source.H/2);
    QapTexMem Src=Source;
    for(int i=0;i<count;i++)
    {
      QapTexMem Target;
      int sW=Src.W;
      int sH=Src.H;
      QapAssert(!(sW%2));
      QapAssert(!(sH%2));
      Target.Init(Src.W/2,Src.H/2);
      auto tW=Target.W;
      auto tH=Target.H;
      //auto&Target=*this;
      auto*pS=Src.get();
      auto*pT=Target.get();
      for(int y=0;y<tH;y++)for(int x=0;x<tW;x++)
      {
        auto&out=pT[x+y*tW];
        #define F(X,Y)pS[(x*2+(X))+(y*2+(Y))*sW]
        auto a=F(0,0);
        auto b=F(1,0);
        auto c=F(0,1);
        auto d=F(1,1);
        #undef F
        auto e=QapColor::HalfMix(a,b);
        auto f=QapColor::HalfMix(c,d);
        out=QapColor::HalfMix(e,f);
      }
      Src.MoveDataFrom(Target);
    }
    MoveDataFrom(Src);
  }
  void DrawMemWithBlend(int x,int y,const QapTexMem&Source,const QapColor&color)
  {
    auto&Target=*this;
    if(!Source){
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for(int j=max(0,y);j<mY;j++){
      for(int i=max(0,x);i<mX;i++){
        auto inp=pS[(i-x)+(j-y)*sW]*color;
        auto&out=pT[i+j*W];
        auto a=inp.a;
        auto b=255-a;
        out.a=inp.a;
        #define F(r)out.r=(out.r*b+inp.r*a)/255;
        F(r)F(g)F(b)
        #undef F
      }
    }
    return;
  }
  void Clear(const QapColor&color=0xFF000000){
    auto*pBits=get();
    for(int i=0;i<W*H;i++)pBits[i]=color;
  }
  void FillLine(const int Y,const QapColor&Color){
    auto*pBits=get();
    for(int i=0;i<W;i++){QapColor&pix=pBits[Y*W+i];pix=Color;}
  }
  void FillColumn(const int X,const QapColor&Color){
    auto*pBits=get();
    for(int i=0;i<H;i++){QapColor&pix=pBits[i*W+X];pix=Color;}
  }
  void RectLine(int X,int Y,int W,int H,const QapColor&Color)
  {
    FillLineEx(Y+0-0,X+0,X+W,Color);
    FillLineEx(Y+H-1,X+0,X+W,Color);
    FillColomnEx(X+0-0,Y+0,Y+H,Color);
    FillColomnEx(X+W-1,Y+0,Y+H,Color);
  }
  void FillLineEx(const int Y,const int X0,const int X1,const QapColor&Color){
    auto*pBits=get();
    int x0=Clamp<int>(X0,0,W);
    int x1=Clamp<int>(X1,0,W);
    if(x0>x1)std::swap(x0,x1);
    for(int i=x0;i<x1;i++){QapColor&pix=pBits[Y*W+i];pix=Color;}
  }
  void FillColomnEx(const int X,const int Y0,const int Y1,const QapColor&Color){
    auto*pBits=get();
    int y0=Clamp<int>(Y0,0,H);
    int y1=Clamp<int>(Y1,0,H);
    if(y0>y1)std::swap(y0,y1);
    for(int i=y0;i<y1;i++){QapColor&pix=pBits[i*W+X];pix=Color;}
  }
public:
  void CopyAlpha(QapTexMem&Alpha){
    auto*pBits=get();
    auto*pAlphaBits=get();
    if(Alpha.W!=W||Alpha.H!=H)return;
    for(int i=0;i<W*H;i++)pBits[i].a=pAlphaBits[i].a;
  }
  void CalcAlpha(){
    auto*pBits=get();
    for(int i=0;i<W*H;i++)pBits[i].a=pBits[i].GetLuminance();
  }
  void CalcAlpha(const QapColor&Color,int threshold=0){
    auto*pBits=get();
    for(int i=0;i<W*H;i++)pBits[i].a=pBits[i]==Color?0:255;
    const QapColor&c=Color;
    int t=threshold;
    int t3=t*3;
    for(int i=0;i<W*H;i++){
      QapColor&p=pBits[i];
      #define F(r)int f##r=abs(int(p.r)-int(c.r));
      F(r);F(g);F(b);
      #undef F
      //int esqr=fr*fr+fg*fg+fb*fb;
      int sum=fr+fg+fb;
      p.a=sum>t3?255:t3?255*sum/t3:0;
    }
  }
  void DrawSolidCircle(int x,int y,int r,const QapColor&color)
  {
    auto rr=r*r;
    int mX=min(W,x+r);
    int mY=min(H,y+r);
    auto*pT=get();
    for(int j=max(0,y-r);j<mY;j++)
    {
      for(int i=max(0,x-r);i<mX;i++)
      {
        auto px=i-x;
        auto py=j-y;
        if(px*px+py*py>=rr)continue;
        auto&out=pT[i+j*W];
        out=color;
      }
    }
  }
  void DrawSolidQuad(int x,int y,int w,int h,const QapColor&color)
  {
    int mX=min(W,x+w/2);
    int mY=min(H,y+h/2);
    auto*pT=get();
    for(int j=max(0,y-h/2);j<mY;j++)
    {
      for(int i=max(0,x-w/2);i<mX;i++)
      {
        auto&out=pT[i+j*W];
        out=color;
      }
    }
  }
  void FillChannel(const QapColor&Source,DWORD BitMask){
    auto*pBits=get();
    for(int i=0;i<W*H;i++){QapColor&C=pBits[i];C=(~BitMask&C)|(BitMask&Source);};
  }
  void BlurTexture(int PassCount)//only D3DFMT_A8R8G8B8
  {
    auto*pBits=get();
    if(!pBits||!W||!H)return;
    static vector<QapColor> vMem;
    vMem.resize(W*H);
    if(W*H!=Arr.Mem.size)
    {
      QapDebugMsg("WTF?");return;
    }
    auto*pBuff=&vMem[0];
    static const int BBM[]={
      1,2,1, 
      2,4,2, 
      1,2,1
    };
    static int MartixSum=0;
    if(!MartixSum){for(int i=0;i<lenof(BBM);i++)MartixSum+=BBM[i];}
    QapAssert(MartixSum==16);
    const int PosRange[]={
      -W-1,-W,-W+1,
      -1-0,+0,-0+1,
      +W-1,+W,+W+1
    };
    for(int PassId=0;PassId<PassCount;PassId++)
    {
      memcpy_s(pBuff,sizeof(QapColor)*vMem.size(),pBits,Arr.Mem.size*sizeof(QapColor));//copy image
      for(int j=1;j<H-1;j++)
      {
        for(int i=1;i<W-1;i++)
        {
          auto&out=pBits[j*W+i];
          auto cur_id=j*W+i;
          vec4i buff;
          for(int t=0;t<9;t++)
          {
            auto T=pBuff[cur_id+PosRange[t]];
            buff+=vec4i(T)*BBM[t];
          };    
          static_assert(1==(16>>4),"orly?");
          static_assert(16==(1<<4),"orly?");
          static_assert((1024/16)==(1024>>4),"orly?");
          buff>>=4;//buff/=MartixSum;
          out=buff.unsafe_but_fast_GetColor();
        }
      }
    }
    return;
  }
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
  void Load()
  {
    LoadTextureFromFile(Mem,FN);
  }
  void Save()
  {
    //QapDebugMsg("You sure?");
    SaveTextureToFile(Mem,FN);
  }
};

class QapTex{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapTex OwnerClass;
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr){
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource(){
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost(){if(pOwner){flag=bool(pOwner->Tex);pOwner->Free();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->ReInit();}
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
  ~QapTex(){Free();}
public:
  void ReInit(){}
  void MountDev(QapD3DDev9&Dev){
    //this->pDev=Dev.pDev;
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int W,int H,int Levels)
  {
    Free();
    auto*Sys=DynRes.pDev;
    Sys->pDev->CreateTexture(W,H,Levels,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&Tex,NULL);
  }
  void Free()
  {
    if(!Tex)return;
    Tex->Release();
    Tex=nullptr;
  };
  operator bool()const{return Tex;}
  void Bind(int lvl=0){
    auto*Sys=DynRes.pDev;
    if(!Sys)return;
    Sys->pDev->SetTexture(lvl,Tex);
  };
public:
  void QapTex::operator=(const QapTex&){
    QapDebugMsg("fail");
  }
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
    operator IEnvRTTI&(){return Env;}
  };
public:
  virtual void Do(IEnv&Env){}
public:
  void Run(IEnvRTTI&Env,QapD3DDev9*pDev)
  {
    if(!pDev)return;
    IEnv env={Env,pDev};
    Do(env);
  }
};

// �������� ��������.
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
  TYPE*AddItem(IEnvRTTI&Env,TResourceHolder&ResHolder,const string&Caption)
  {
    Items.resize(Items.size()+1);
    TYPE*ret=Items.back().build<TYPE>(Env);
    ret->Holders.push_back(&ResHolder);
    QapAssert(ResHolder.Caption.empty());
    ResHolder.Caption=Caption;
    //QapResource*p=ret;
    //p->MountDev(*pDev.get());
    return ret;
  }
  void Del(){}
public:
  void Do(IEnv&Env)
  {
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(!ex)continue;
      ex->Do(Env);
    }
  }
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
  static void Gen(QapTexMem*Mem,QapTex*Tex,int MaxLevelCount=16)
  {
    if(!Tex||!Mem)return;
    int W=Mem->W;int H=Mem->H;QapColor*pBits=Mem->get();
    Tex->W=W;Tex->H=H;
    QapAssert(W*H==Mem->Arr.Mem.size);
    int SW=1,SWC=0;for(int &i=SWC;SW<W;i++)SW*=2;if(SW>W)goto fail;
    int SH=1,SHC=0;for(int &i=SHC;SH<H;i++)SH*=2;if(SH>H)goto fail;
    if(0){fail:QapDebugMsg("NPOT("+IToS(W)+"x"+IToS(H)+")");return;}
    int Levels=min(MaxLevelCount,min(SWC,SHC));
    IDirect3DTexture9*&tex=Tex->Tex;
    Tex->Init(W,H,Levels);
    if(!tex){QapDebugMsg("fail");return;}
    D3DLOCKED_RECT rect[16]; struct QapARGB{BYTE B,G,R,A;}; QapARGB* pBitsEx[16];
    for(int i=0;i<Levels;i++){tex->LockRect(i,&rect[i],NULL,0);pBitsEx[i]=(QapARGB*)rect[i].pBits;};
    {
      QapColor* pDestBits=(QapColor*)rect[0].pBits;
      memcpy_s(pDestBits,SW*SH*sizeof(QapColor),pBits,SW*SH*sizeof(QapColor));
      SW/=2; SH/=2;
    }
    for(int k=1;k<Levels;k++)
    {
      QapARGB *PC=(QapARGB*)rect[k].pBits;
      for(int j=0;j<SH;j++)
        for(int i=0;i<SW;i++)
        {
          #define F(X,Y)pBitsEx[k-1][X+2*Y*SW+2*i+4*j*SW]
            QapARGB A[4]={F(0,0),F(0,1),F(1,0),F(1,1)};
          #undef F
          float AF[4]={0,0,0,0};
          for(int t=0;t<4;t++)
          {
            AF[0]+=A[t].R;
            AF[1]+=A[t].G;
            AF[2]+=A[t].B;
            AF[3]+=A[t].A;
          };
          for(int t=0;t<4;t++)AF[t]*=0.25*(1.0/255.0);
          QapColor PCC=D3DCOLOR_COLORVALUE(AF[0],AF[1],AF[2],AF[3]);
          *PC=*((QapARGB*)&PCC);
          PC++;
        }
      SW/=2; SH/=2;
    }
    for(int i=0;i<Levels;i++)tex->UnlockRect(i);
  }
public:
  void Do()
  {
    if(!Mem||!Tex)return;
    auto*mem=Mem.get();
    auto*tex=Tex.get();
    Gen(mem,tex);
    if(0){static int i=0;i++;SaveTextureToFile(*mem,"hack"+IToS(i)+".png");}
  }
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
  void SetToDef()
  {
    Gen.Mem=&File.Mem;
    Gen.Tex=&Tex;
  }
  struct t_fn_parser{
    string fn;
    string func;
    string size;
    int value;
    bool main()
    {
      if(fn.empty())return false;
      if(fn[0]!='?')return false;
      int e=0;
      func=ScanParam("?",fn,"(",e);
      if(e<0)return false;
      e+=func.size()+string("(").size();
      size=ScanParam("",fn,")",e);
      if(e<0)return false;
      value=SToI(size);
      return true;
    }
  };
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!File.Mem);
      for(;;)
      {
        t_fn_parser parser;
        parser.fn=File.FN;
        if(parser.main())
        {
          if(parser.func=="GenRect"){File.Mem.GenRect(parser.value);break;}
          if(parser.func=="GenBall"){File.Mem.GenBall(parser.value);break;}
          if(parser.func=="GenQuad"){File.Mem.GenQuad(parser.value);break;}
          QapDebugMsg("texmem.func not found: "+parser.func+"\nFile.FN:\n"+File.FN);
          break;
        }
        File.Load();
        break;
      }
      Tex.MountDev(*Env.pDev);
    }
    if(!Gen.Tex->Tex)Gen.Do();
  }
};

class QapResourceDetector{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapResourceDetector OwnerClass;
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr){
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource(){
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost(){if(pOwner){flag=bool(pOwner->used);pOwner->PreFree();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->PreInit();}
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
  void MountDev(QapD3DDev9&Dev){this->DynRes.Mount(this,&Dev);}
  void PreInit(){needinit=true;}
  void PreFree(){Free();}
  void Init(){used=true;needinit=false;}
  void Free(){used=false;};
  operator bool()const{return used;}
  //void Bind(int lvl=0){Sys.pDev->SetTexture(lvl,Tex);};
};

/*
class ITexObject{
public:
  virtual vec2i GetSize()=0;
  virtual QapTex&GetTex()=0;
  virtual QapD3DDev9*GetDev()=0;
  virtual void MountDev(QapD3DDev9&Dev)=0;
public:
};*/

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
  vec2i&operator[](int index){return Coords[index];}
  const vec2i&operator[](int index)const{return Coords[index];}
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
  void Do(HWND hWnd)
  {
    if(!Font)return;
    auto&Out=Font->Mem;
    auto&Info=Font->Info;
    CreateFontMem(hWnd,Out,Info,Name,Size,Bold,TexSize);
  }
public:
  static void CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize)
  {
    Out.Free();
    Out.Init(TexSize,TexSize);
    QapColor*pix=Out.get();
    {
      HDC DC=GetDC(hWnd);
      int W=Bold?FW_BOLD:FW_NORMAL;
      int H=-MulDiv(Size,GetDeviceCaps(DC,LOGPIXELSY),72);
      {
        HFONT FNT=CreateFontA(H,0,0,0,W,0,0,0,RUSSIAN_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH,Name.c_str());
        {
          HDC MDC=CreateCompatibleDC(DC);
          {
            HBITMAP BMP=CreateCompatibleBitmap(DC,TexSize,TexSize);
            SelectObject(MDC,BMP);
            RECT Rect; SetRect(&Rect,0,0,TexSize,TexSize);
            FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
            SelectObject(MDC,FNT);
            SetBkMode(MDC,TRANSPARENT);
            SetTextColor(MDC,0xFFFFFF);
            for(int i=0;i<256;i++)TextOutA(MDC,i%16*(TexSize/16),i/16*(TexSize/16),(LPCSTR)&i,1);
            {QapBitmapInfo QBI(TexSize,TexSize);GetDIBits(MDC,BMP,0,TexSize,pix,&QBI.BI,DIB_RGB_COLORS);}
            for(int i=0;i<TexSize*TexSize;i++){pix[i].a=pix[i].r;pix[i].r=255;pix[i].g=255;pix[i].b=255;}
            for(int i=0;i<256;i++){SIZE cs;GetTextExtentPoint32A(MDC,(LPCSTR)&i,1,&cs);Info.Coords[i]=vec2i(cs.cx,cs.cy);}
            DeleteObject(BMP);
          }
          DeleteDC(MDC);
        }
        DeleteObject(FNT); 
      }
      ReleaseDC(hWnd,DC);
    }
    Out.InvertY();
    //QapTexMem*pMem=new QapTexMem("Font_"+Name+"_"+IToS(TexSize),TexSize,TexSize,(QapColor*)pix);
    //return pMem;
  }
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
  void SetToDef()
  {
    FontGen.Font=&Font;
    TexGen.Mem=&Font.Mem;
    TexGen.Tex=&Tex;
  }
  void MountDev(QapD3DDev9*pDev)
  {
    if(Tex.DynRes.pDev)return;
    Tex.MountDev(*pDev);
  }
  void DoGenFont(QapD3DDev9*pDev)
  {
    HWND hWnd=pDev->PresParams.pp.hDeviceWindow;
    FontGen.Do(hWnd);
  }
  void DoGenTex()
  {
    TexGen.Do();
  }
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!Font.Mem);
      HWND hWnd=Env.pDev->PresParams.pp.hDeviceWindow;
      FontGen.Do(hWnd);
      Tex.MountDev(*Env.pDev);
    }
    if(!TexGen.Tex->Tex)TexGen.Do();
  }
};

class QapQ3Text{
public:
  static int GetLength(const QapFont&Font,const string&Text)
  {
    float xp=0; int i=0;
    while(i<Text.size())
    {
      if(Text[i]!='^')
      {
        int I=(byte)Text[i];
        float cx=float(Font.Info[I].x);
        xp+=cx; i++; continue;
      };
      i++; if(i>Text.size())continue;
      if((Text[i]>='0')&&(Text[i]<='9')){i++; continue;};
      if((Text[i]>='A')&&(Text[i]<='F')){i++; continue;};
    }
    return xp;
  }
public:
  static string ToNormal(const string&Text)
  {
    string s; int i=0;
    while(i<Text.size())
    {
      if(Text[i]!='^'){s.push_back(Text[i++]);continue;}
      i++;if(i>Text.size())continue;
      if((Text[i]>='0')&&(Text[i]<='9')){i++;continue;};
      if((Text[i]>='A')&&(Text[i]<='F')){i++;continue;};
    }
    return s;
  }
public:
  static int AddVertexEx(QapDev*RD,float x,float y,QapColor c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=RD->AddVertex(tmp);
    return id;
  }
  static void DrawQapText(QapDev*RD,QapFont&Font,float X,float Y,const string&Text)
  {
    static QapColor CT[]={
      0xFF252525,0xFFFF0000,0xFF00FF00,0xFFFFFF00,
      0xFF0000FF,0xFFFF00FF,0xFF00FFFF,0xFFFFFFFF,
      0xFFFFFFA8,0xFFFFA8FF,
      0xFFFF8000,0xFF0080FF,0xFFA0A0A0,0xFF808080,0xFF008F00,0xFF0000A8,
    };
    //RD->SetAlphaMode(QapDev::AlphaType::AM_GEQUAL_ONE);
    QapDev::BatchScope Scope(*RD);
    //qDev.BeginBatch();
    {
      typedef QapDev::Ver Vertex;
      int QuadCount=0;
      int VPos=RD->GetVPos();
      float xp=0; int i=0;
      vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
      vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
      QapColor color=RD->GetColor();
      while(i<Text.size())
      {
        unsigned char UC=Text[i];
        if(UC!='^')
        {
          float U=off.x+float(UC%16)/16;
          float V=off.y+float(UC/16)/16;
          vec2f c=Font.Info[UC];
          vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
          #define F(var,x,y,z,color,u,v)int var=AddVertexEx(RD,xp+X+(x),Y+(y),color,U+(u),V+(v));
            F(A, 0.f, -c.y, 0, color, 0.f, +t.y);
            F(B, c.x, -c.y, 0, color, t.x, +t.y);
            F(C, c.x, +0.f, 0, color, t.x, +0.f);
            F(D, 0.f, +0.f, 0, color, 0.f, +0.f);
          #undef F
          RD->AddTris(A,B,C);
          RD->AddTris(C,D,A);
          xp+=c.x; QuadCount++; i++; continue;
        };
        i++; if(i>Text.size())continue;
        UC=Text[i];
        if((UC>='0')&&(UC<='9')){color=CT[UC-'0'+0x0]; i++; continue;};
        if((UC>='A')&&(UC<='F')){color=CT[UC-'A'+0xA]; i++; continue;};
      }
      if(0)RD->SetColor(color);
    }
    //qDev.EndBatch();
  }
};


class QapText{
public:
  static int GetLength(const QapFont&Font,const string&Text)
  {
    int out=0;
    for(int i=0;i<Text.size();i++)
    {
      auto id=(byte)Text[i];
      auto cx=Font.Info[id].x;
      out+=cx;
    }
    return out;
  }
public:
  static int AddVertexEx(QapDev&qDev,float x,float y,QapColor c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=qDev.AddVertex(tmp);
    return id;
  }
  struct t_draw_call{
    char c;
    vec2i pos;
    vec2i size;
  };
  static void add_draw_call(vector<t_draw_call>&out,char c,const vec2i&pos,const vec2i&size)
  {
    t_draw_call tmp;
    tmp.c=c;
    tmp.pos=pos;
    tmp.size=size;
    out.push_back(std::move(tmp));
  }
  template<class FUNC>
  static void PreDrawEx(QapFont&Font,float X,float Y,const string&Text,/*vector<t_draw_call>&out,*/FUNC&func)
  {
    float xp=0; int i=0;
    vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
    vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
    for(int i=0;i<Text.size();i++)
    {
      unsigned char UC=Text[i];
      float U=off.x+float(UC%16)/16;
      float V=off.y+float(UC/16)/16;
      auto c=Font.Info[UC];
      func(UC,vec2i(xp+X,Y),c);
      vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
      //add_draw_call(out,text[i],vec2i(xp+X,Y),c);
      xp+=c.x;
    }
  }
  template<class FUNC>
  static void DrawEx(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text,FUNC&func)
  {
    QapDev::BatchScope Scope(qDev);
    //qDev.BeginBatch();
    {
      typedef QapDev::Ver Vertex;
      int QuadCount=0;
      int VPos=qDev.GetVPos();
      float xp=0; int i=0;
      vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
      vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
      QapColor color=qDev.GetColor();
      for(int i=0;i<Text.size();i++)
      {
        unsigned char UC=Text[i];
        float U=off.x+float(UC%16)/16;
        float V=off.y+float(UC/16)/16;
        auto c=Font.Info[UC];
        func(UC,vec2i(xp+X,Y),c);
        vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
        #define F(var,x,y,z,color,u,v)int var=AddVertexEx(qDev,xp+X+(x),Y+(y),color,U+(u),V+(v));
          F(A, 0.f, -c.y, 0, color, 0.f, +t.y);
          F(B, c.x, -c.y, 0, color, t.x, +t.y);
          F(C, c.x, +0.f, 0, color, t.x, +0.f);
          F(D, 0.f, +0.f, 0, color, 0.f, +0.f);
        #undef F
        qDev.AddTris(A,B,C);
        qDev.AddTris(C,D,A);
        xp+=c.x; QuadCount++;
      }
    }
    //qDev.EndBatch();
  }
  static void DoNothing(unsigned char UC,const vec2i&p,const vec2i&s){}
  static void Draw(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text)
  {
    DrawEx(qDev,Font,X,Y,Text,DoNothing);
  }
};

//<<<<<=====QapDev
#endif //DEF_BUILD_MACRO//

//-------------------------------------------//
//   {<|          04.06.2014           |>}   //
//-------------------------------------------//
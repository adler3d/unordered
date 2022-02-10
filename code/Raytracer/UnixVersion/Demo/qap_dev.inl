class QapDev{
public:
  struct Ver
  {
    float x,y,z;
    QapColor color;
    float tu,tv;
    Ver():x(0),y(0),z(0),tu(0),tv(0) {}
    Ver(float x,float y,const QapColor&color,float u=0.0,float v=0.0):x(x),y(y),z(0),color(color),tu(u),tv(v) {}
    Ver(const vec2f&pos,const QapColor&color,float u=0.0,float v=0.0):x(pos.x),y(pos.y),z(0),color(color),tu(u),tv(v) {}
    Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord):x(pos.x),y(pos.y),z(0),color(color),tu(texcoord.x),tv(texcoord.y) {}
    vec3f&get_vec3f()const{
      return *(vec3f*)&x;
    }
    vec2f&get_pos()
    {
      return *(vec2f*)&x;
    }
    vec2f&get_pos()const
    {
      return *(vec2f*)&x;
    }
    vec2f&get_tpos()
    {
      return *(vec2f*)&tu;
    }
    vec2f&get_tpos()const
    {
      return *(vec2f*)&tu;
    }
  };
  struct BatchScope
  {
    QapDev&RD;
    bool flag;
    BatchScope(QapDev&RD):RD(RD)
    {
      flag=!RD.Batching;
      if(flag)RD.BeginBatch();
    }
    ~BatchScope()
    {
      if(flag)RD.EndBatch();
    }
  };
  struct Xf4Scope
  {
    QapDev&RD;
    bool flag;
    QapMat4 backup;
    Xf4Scope(QapDev&RD):RD(RD)
    {
      RD.BeginXF4(*this);
    }
    ~Xf4Scope()
    {
      RD.EndXF4(*this);
    }
  };
public:
  typedef QapDev SelfClass;
public:
  vector<Ver> VB;
  vector<int> IB;
  Ver* VBA;
  int* IBA;
  QapColor color;
  int VPos;
  int IPos;
  int MaxVPos;
  int MaxIPos;
  int DIPs;
  int Verts;
  int Tris;
  bool Batching;
  bool Textured;
  transform2f xf;
  transform2f txf;
  vector<t_quad> stack;
  t_quad viewport;
  bool use_viewport;
  QapMat4 xf4;
  bool use_xf4;
  bool use_xf2;
  bool auto_clamp;
  bool after_reinit;
public:
  void DoReset()
  {
    this->VB.clear();
    this->IB.clear();
    (this->VBA)=(nullptr);
    (this->IBA)=(nullptr);
    (this->color)=(0xFFFFFFFF);
    (this->VPos)=(0);
    (this->IPos)=(0);
    (this->MaxVPos)=(0);
    (this->MaxIPos)=(0);
    (this->DIPs)=(0);
    (this->Verts)=(0);
    (this->Tris)=(0);
    (this->Batching)=(false);
    (this->Textured)=(false);
    detail::FieldTryDoReset(this->xf);
    detail::FieldTryDoReset(this->txf);
    //... added ...
    (this->use_viewport=false);
    (this->use_xf4=false);
    (this->use_xf2=false);
    (this->auto_clamp=false);
    (this->after_reinit=false);
  }
public:
  QapDev(const QapDev&)
  {
    QapDebugMsg("QapDev"" is noncopyable");
    DoReset();
  };
  QapDev()
  {
    DoReset();
  };
public:
  ~QapDev()
  {
    Free();
  }
public:
  bool OnReinit(){auto f=after_reinit;after_reinit=false;return f;}
  void ReInit()
  {
    Init(MaxVPos,MaxIPos);after_reinit=true;
  }
  void Init(int VCount,int ICount)
  {
    if(VB.empty())
    {
      MaxVPos=VCount;
      MaxIPos=ICount;
      VB.resize(VCount);QapAssert(VCount);
      IB.resize(ICount);QapAssert(ICount);
      VBA=0;
      IBA=0;
      VPos=0;
      IPos=0;
      DIPs=0;
      Verts=0;
      Tris=0;
      xf.set_ident();
      txf.set_ident();
    };
  }
  void Free()
  {
    VB.clear();IB.clear();
    VBA=nullptr;
    IBA=nullptr;
    VPos=0;
    IPos=0;
    Batching=false;
  };
public:
  void BeginXF4(Xf4Scope&scope)
  {
    scope.backup=xf4;
    scope.flag=use_xf4;
    use_xf4=true;
  }
  void EndXF4(Xf4Scope&scope)
  {
    xf4=scope.backup;
    use_xf4=scope.flag;
  }
public:
  void BeginBatch()
  {
    Batching=true;
    VBA=0;
    IBA=0;
    VPos=0;
    IPos=0;
    if(!IB.size()||!VB.size())return;
    VBA=&VB[0];IBA=&IB[0];
  };
  void EndBatch(bool call_dip=true)
  {
    Batching=false;
    if(!IB.size()||!VB.size())return;
    if(VPos&&IPos)
    {
      if(call_dip)DIP();
    }
    VBA=0;
    IBA=0;
  }
  void DIP()
  {
    QapNoWay();
  }
  bool IsBatching()
  {
    return Batching;
  }
  int GetIPos()
  {
    return IPos;
  }
  int GetVPos()
  {
    return VPos;
  }
  int GetDIPs()
  {
    return DIPs;
  }
  int GetVerts()
  {
    return Verts;
  }
  int GetTris()
  {
    return Tris;
  }
  const QapColor&GetColor()
  {
    return color;
  }
  void push_viewport(const t_quad&quad)
  {
    stack.push_back(viewport);
    viewport=quad;
  }
  void pop_viewport()
  {
    QapAssert(!stack.empty());
    viewport=stack.back();
    stack.pop_back();
  }
  void NextFrame()
  {
    QapAssert(stack.empty());
    DIPs=0;
    Verts=0;
    Tris=0;
    use_xf2=false;
    use_viewport=false;
  }
public:
  void HackMode(bool Textured)
  {
    this->Textured=Textured;
  }
public:
  inline Ver&AddVertexRaw()
  {
    return VBA[VPos++];
  }
  inline int AddVertex(const Ver&Source)
  {
    QapAssert(VPos<MaxVPos);
    Ver&Dest=VBA[VPos];
    Dest=Source;
    if(use_xf4)
    {
      QapAssert(!use_xf2);
      auto&v=Dest.get_vec3f();
      v=v*xf4;
    }
    if(use_xf2)
    {
      QapDebugMsg("[2014.12.01 11:33] need add Xf2Scope");
      QapAssert(!use_xf4);
      vec2f&v=Dest.get_pos();
      v=xf*v;
    }
    if(use_viewport)
    {
      vec2f&v=Dest.get_pos();
      v+=viewport.pos;
    }
    if(Textured)
    {
      QapDebugMsg("[2014.12.01 11:33] need add Xf2tScope");
      vec2f&v=Dest.get_tpos();
      v=txf*v;
    }
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
  inline int AddVertex(const vec3f&pos)
  {
    QapDev::Ver tmp;
    tmp.get_vec3f()=pos;
    tmp.color=color;
    tmp.tu=0;
    tmp.tv=0;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec3f&pos,const QapColor&c)
  {
    QapDev::Ver tmp;
    tmp.get_vec3f()=pos;
    tmp.color=c;
    tmp.tu=0;
    tmp.tv=0;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec3f&pos,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.get_vec3f()=pos;
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
  inline void AddTrisInv(int A,int B,int C)
  {
    QapAssert(IPos+2<MaxIPos);
    QapAssert(A>=0&&A<MaxVPos);
    QapAssert(B>=0&&B<MaxVPos);
    QapAssert(C>=0&&C<MaxVPos);
    IBA[IPos++]=C;
    IBA[IPos++]=B;
    IBA[IPos++]=A;
  };
public:
  inline void SetColor(const QapColor&C)
  {
    color=C;
  }
  inline void SetTransform(transform2f const&val)
  {
    QapDebugMsg("no way.\nuse Xf2Scope.");xf=val;
  }
  inline transform2f GetTransform()
  {
    return xf;
  }
  inline void SetTextureTransform(transform2f const&val)
  {
    QapDebugMsg("no way.\nuse Xf2tScope.");txf=val;
  }
  inline transform2f GetTextureTransform()
  {
    return txf;
  }
public:
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
  void AddQuadsIndices(int vpos,int n){
    int p=vpos;
    for(int i=0;i<n;i++){
      AddTris(p+1,p+0,p+3);
      AddTris(p+3,p+2,p+1);
      p+=4;
    }
  }
  void AddQuadVertices(float x,float y,float half_w,float half_h)
  {  
    BatchScope Scope(*this);
    {
      #define F(X,Y,U,V){AddVertex(x+(X##half_w),y+(Y##half_h),color,U,V);}
      //vec2d O(x,y);
      //int n=VPos;
      QapAssert(vec2d(-1,-1).Ort()==vec2d(+1,-1));
      F(-,-,0.0f,1.0f);
      F(+,-,1.0f,1.0f);
      F(+,+,1.0f,0.0f);
      F(-,+,0.0f,0.0f); 
      //AddTris(n+1,n+0,n+3);
      //AddTris(n+3,n+2,n+1);
      #undef F
    }
  }
  void DrawQuad(float x,float y,float w,float h)
  {
    BatchScope Scope(*this);
    {
      #define F(X,Y,U,V){AddVertex(x+(X)*w,y+(Y)*h,color,U,V);}
      vec2d O(x,y);
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
      {
        AddVertex(vec2f(O+vec2d(-0.5f*w,-0.5f*h).UnRot(OZ)),color,0.0f,1.0f);
      };
      {
        AddVertex(vec2f(O+vec2d(+0.5f*w,-0.5f*h).UnRot(OZ)),color,1.0f,1.0f);
      };
      {
        AddVertex(vec2f(O+vec2d(+0.5f*w,+0.5f*h).UnRot(OZ)),color,1.0f,0.0f);
      };
      {
        AddVertex(vec2f(O+vec2d(-0.5f*w,+0.5f*h).UnRot(OZ)),color,0.0f,0.0f);
      };
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
      for (int i=0;i<c;i++)AddVertex(Points[i],color,0.5,0.5);
      for (int i=2;i<c;i++)AddTris(n,n+i-1,n+i-0);
    }
  }
public:
  void DrawDashLine(const vec2d&a,const vec2d&b,real dash_size,real line_size)
  {
    if(a.dist_to(b)<dash_size){DrawLine(a,b,line_size);return;}
    auto o=(a+b)*0.5;
    auto ob=b-o;
    auto ob05=o+ob.SetMag(dash_size*0.5);
    auto ob15=o+ob.SetMag(dash_size*1.5);
    DrawDashLineFromA(ob05,a,dash_size,line_size);
    if(dash_size*1.5<ob.Mag())DrawDashLineFromA(ob15,b,dash_size,line_size);
  }
  void DrawDashLineFromA(const vec2d&a,const vec2d&b,real dash_size,real line_size)
  {
    real k=dash_size;real inv_k=1.0/k;
    vector<vec2d> arr;int c=int(a.dist_to(b)*inv_k);
    for(int i=0;i<=c;i++)qap_add_back(arr)=a+(b-a).SetMag(i*k);
    if(c%2==0)qap_add_back(arr)=b;
    DrawLineList(arr,line_size);
  }
  void DrawLine(const vec2d&a,const vec2d&b,real line_size){DrawQuad((b+a)*0.5,(b-a).Mag(),line_size,(b-a).GetAng());}
  void DrawSolidCircle(const vec2d&pos,real r,int seg,real ang){DrawCircleEx(pos,r,0,seg,ang);}
  template<typename TYPE>
  void DrawPolyLine(const vector<TYPE>&PA,const real&LineSize,const bool&Loop)
  {
    if(PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      int c=Loop?Count:Count-1;
      for (int i=0;i<c;i++)
      {
        TYPE const&a=PA[(i+0)%Count];
        TYPE const&b=PA[(i+1)%Count];
        vec2d n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]=
        {
          AddVertex(a+n,color,0.5f,0.5f),
          AddVertex(b-n,color,0.5f,0.5f),
          AddVertex(a-n,color,0.5f,0.5f),
          AddVertex(b+n,color,0.5f,0.5f),
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
      for (int i=0;i+1<Count;i+=2)
      {
        TYPE const&a=PA[i+0];
        TYPE const&b=PA[i+1];
        TYPE n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]=
        {
          AddVertex(a+n,color,0.5,0.5),
          AddVertex(b-n,color,0.5,0.5),
          AddVertex(a-n,color,0.5,0.5),
          AddVertex(b+n,color,0.5,0.5),
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawMesh(const vector<TYPE>&VA,const vector<int>&IA)
  {
    //QapDebugMsg("[2014.05.22]: way used?");
    if(VA.empty())return;
    BatchScope Scope(*this);
    {
      int base=GetVPos();
      static IntArray VID;
      VID.resize(VA.size());
      for (int i=0;i<VA.size();i++){auto&p=VA[i];VID[i]=AddVertex(p,color,p.x,p.y);}
      for (int i=0;i<IA.size();i+=3)AddTris(VID[IA[i+0]],VID[IA[i+1]],VID[IA[i+2]]);
    }
  }
  void DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    static PointArray PA;
    PA.resize(seg);
    for (int i=0;i<seg;i++)
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
    static vector<int> VID;
    VID.resize(n*2);
    for (int i=0;i<n;i++)
    {
      vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[0+i]=AddVertex(pos+v*r0,color,0,0);
      VID[n+i]=AddVertex(pos+v*r1,color,0,0);
    }
    for (int i=0;i<n;i++)
    {
      int a=VID[0+(i+0)%n];
      int b=VID[0+(i+1)%n];
      int c=VID[n+(i+0)%n];
      int d=VID[n+(i+1)%n];
      AddTrisInv(a,b,d);
      AddTrisInv(d,c,a);
    }
  }
  static inline vec3f toVec3f(const vec2d&pos,float z=0){return vec3f(pos.x,pos.y,z);}
  void DrawTube(const vec3f&pos,real z_len,real r,real dr,int seg,real ang)
  {
    DrawTubeEx(pos,z_len*-0.5,z_len*0.5,r+dr*0.5,r-dr*0.5,seg,ang);
  }
  void DrawTubeEx(const vec3f&pos,real z0,real z1,real r0,real r1,int seg,real ang)
  {
    if(z0>z1)std::swap(z0,z1);
    if(r0<r1)std::swap(r0,r1);
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;
    VID.resize(n*4);
    auto pz0=pos+vec3f(0,0,z0);
    auto pz1=pos+vec3f(0,0,z1);
    for(int i=0;i<n;i++)
    {
      auto p=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[n*0+i]=AddVertex(pz0+toVec3f(p)*r0,color,0,0);
      VID[n*1+i]=AddVertex(pz0+toVec3f(p)*r1,color,0,0);
      VID[n*2+i]=AddVertex(pz1+toVec3f(p)*r0,color,0,0);
      VID[n*3+i]=AddVertex(pz1+toVec3f(p)*r1,color,0,0);
    }
    for(int i=0;i<n;i++)
    {
      //z0
      {
        int a=VID[n*0+(i+0)%n];
        int b=VID[n*0+(i+1)%n];
        int c=VID[n*1+(i+0)%n];
        int d=VID[n*1+(i+1)%n];
        AddQuad(0,a,b,d,c);
      }
      //z1
      {
        int a=VID[n*2+(i+0)%n];
        int b=VID[n*2+(i+1)%n];
        int c=VID[n*3+(i+0)%n];
        int d=VID[n*3+(i+1)%n];
        AddQuadInv(0,a,b,d,c);
      }
      int gg=1;
      {
        int a0=VID[n*0+(i+0)%n];
        int b0=VID[n*0+(i+1)%n];
        int c0=VID[n*1+(i+0)%n];
        int d0=VID[n*1+(i+1)%n];
        //
        int a1=VID[n*2+(i+0)%n];
        int b1=VID[n*2+(i+1)%n];
        int c1=VID[n*3+(i+0)%n];
        int d1=VID[n*3+(i+1)%n];
        {
          int a=a0;
          int b=a1;
          int c=b0;
          int d=b1;
          AddQuad(0,a,b,d,c);
        }
        //
        {
          int a=c0;
          int b=c1;
          int c=d0;
          int d=d1;
          AddQuadInv(0,a,b,d,c);
        }
      }
    }
    int gg=1;
  }

  void DrawSphereWithScale(const vec3f&pos,float r,const vec3f&scale,int seg=16,int cn=32)
  {
    /* this is copy-paste */QapAssert(cn>2&&seg>2);
    /* this is copy-paste */int axispoints=0;
    /* this is copy-paste */auto n=(1+cn)/2;
    /* this is copy-paste */auto zoom=1.0/n;
    /* this is copy-paste */auto point_color=color;
    /* this is copy-paste */vector<int> VID;
    /* this is copy-paste */VID.reserve(n*2*seg-seg);
    /* this is copy-paste */for(int j=-n+1;j<n;j++)
    /* this is copy-paste */{
    /* this is copy-paste */  auto z=sin((j*zoom)*PiD2);
    /* this is copy-paste */  auto m=sqrt(1-(z*z));
    /* this is copy-paste */  if(fabs(z)>=1)
    /* this is copy-paste */  {
    /* this is copy-paste */    axispoints++;
    /* this is copy-paste */    continue;
    /* this is copy-paste */  }
    /* this is copy-paste */  for(int i=0;i<seg;i++)
    /* this is copy-paste */  {
    /* this is copy-paste */    auto v=Vec2dEx(i*Pi2/seg,1);
    v.x*=scale.x;
    v.y*=scale.y;
    /* this is copy-paste */    vec3f dpos=vec3f(v.x*m,v.y*m,z*scale.z);
    /* this is copy-paste */    color=point_color;
    /* this is copy-paste */    qap_add_back(VID)=AddVertex(pos+r*dpos);
    /* this is copy-paste */  }
    /* this is copy-paste */  //color=0xff00bb00;
    /* this is copy-paste */  //DrawTube(pos+vec3f(0,0,z*r),r*0.005,r*m,r*0.005,seg,0);
    /* this is copy-paste */}
    /* this is copy-paste */color=point_color;
    /* this is copy-paste */auto A=AddVertex(pos+vec3f(0,0,r*scale.z));
    /* this is copy-paste */auto B=AddVertex(pos-vec3f(0,0,r*scale.z));
    /* this is copy-paste *///
    /* this is copy-paste */QapAssert(!axispoints);
    /* this is copy-paste *///
    /* this is copy-paste */int iter=0;
    /* this is copy-paste */for(int j=-n+1;j+1<n;j++)
    /* this is copy-paste */{
    /* this is copy-paste */  for(int i=0;i<seg;i++)
    /* this is copy-paste */  {
    /* this is copy-paste */    int base0=(iter+0)*seg;
    /* this is copy-paste */    int base1=(iter+1)*seg;
    /* this is copy-paste */    auto&a=VID[base0+(i+0)%seg];
    /* this is copy-paste */    auto&b=VID[base1+(i+0)%seg];
    /* this is copy-paste */    auto&c=VID[base1+(i+1)%seg];
    /* this is copy-paste */    auto&d=VID[base0+(i+1)%seg];
    /* this is copy-paste */    AddQuad(0,a,b,c,d);
    /* this is copy-paste */  }
    /* this is copy-paste */  iter++;
    /* this is copy-paste */}
    /* this is copy-paste */for(int i=0;i<seg;i++)
    /* this is copy-paste */{
    /* this is copy-paste */  {
    /* this is copy-paste */    int base=0;
    /* this is copy-paste */    auto&a=VID[base+(i+0)%seg];
    /* this is copy-paste */    auto&b=VID[base+(i+1)%seg];
    /* this is copy-paste */    AddTris(B,a,b);
    /* this is copy-paste */  }
    /* this is copy-paste */  {
    /* this is copy-paste */    int base=iter*seg;
    /* this is copy-paste */    auto&a=VID[base+(i+0)%seg];
    /* this is copy-paste */    auto&b=VID[base+(i+1)%seg];
    /* this is copy-paste */    AddTrisInv(A,a,b);
    /* this is copy-paste */  }
    /* this is copy-paste */}
    /* this is copy-paste */QapAssert(!axispoints);
  }
  void DrawSphere(const vec3f&pos,float r,int seg=16,int cn=32)
  {
    QapAssert(cn>2&&seg>2);
    int axispoints=0;
    auto n=(1+cn)/2;
    auto scale=1.0/n;
    auto point_color=color;
    vector<int> VID;
    VID.reserve(n*2*seg-seg);
    static vector<vector<vec2d>> seg_seg_id_to_dir;static const int max_buff=32;
    if(seg_seg_id_to_dir.empty())seg_seg_id_to_dir.resize(max_buff);
    vec2d*pid2vec=nullptr;
    if(seg<max_buff&&seg>1){
      auto&arr=seg_seg_id_to_dir[seg];
      if(arr.empty()){for(int i=0;i<seg;i++)qap_add_back(arr)=Vec2dEx(i*Pi2/seg,1);}
      pid2vec=&arr[0];
    }
    for(int j=-n+1;j<n;j++)
    {
      auto z=sin((j*scale)*PiD2);
      auto m=sqrt(1-(z*z));
      if(fabs(z)>=1)
      {
        axispoints++;
        continue;
      }
      for(int i=0;i<seg;i++)
      {
        auto v=pid2vec?pid2vec[i]:Vec2dEx(i*Pi2/seg,1);
        vec3f dpos=vec3f(v.x*m,v.y*m,z);
        color=point_color;
        qap_add_back(VID)=AddVertex(pos+r*dpos);
      }
      //color=0xff00bb00;
      //DrawTube(pos+vec3f(0,0,z*r),r*0.005,r*m,r*0.005,seg,0);
    }
    color=point_color;
    auto A=AddVertex(pos+vec3f(0,0,r));
    auto B=AddVertex(pos-vec3f(0,0,r));
    //
    QapAssert(!axispoints);
    //
    int iter=0;
    for(int j=-n+1;j+1<n;j++)
    {
      for(int i=0;i<seg;i++)
      {
        int base0=(iter+0)*seg;
        int base1=(iter+1)*seg;
        auto&a=VID[base0+(i+0)%seg];
        auto&b=VID[base1+(i+0)%seg];
        auto&c=VID[base1+(i+1)%seg];
        auto&d=VID[base0+(i+1)%seg];
        AddQuad(0,a,b,c,d);
      }
      iter++;
    }
    for(int i=0;i<seg;i++)
    {
      {
        int base=0;
        auto&a=VID[base+(i+0)%seg];
        auto&b=VID[base+(i+1)%seg];
        AddTris(B,a,b);
      }
      {
        int base=iter*seg;
        auto&a=VID[base+(i+0)%seg];
        auto&b=VID[base+(i+1)%seg];
        AddTrisInv(A,a,b);
      }
    }
    QapAssert(!axispoints);
    //color=0xffff0000;
    //DrawCube(pos,r*vec3f_one*0.04);
    //DrawCube(pos+vec3f(0,0,r),r*vec3f_one*0.02);
    //DrawCube(pos-vec3f(0,0,r),r*vec3f_one*0.02);
  }
  void DrawSphereWire(const vec3f&pos,float r,int seg=16,int cn=32)
  {
    QapAssert(cn>2&&seg>2);
    int axispoints=0;
    auto n=(1+cn)/2;
    auto scale=1.0/n;
    auto point_color=color;
    for(int j=-n+1;j<n;j++)
    {
      auto z=sin((j*scale)*PiD2);
      auto m=sqrt(1-(z*z));
      if(fabs(z)>=1)
      {
        axispoints++;
        continue;
      }
      for(int i=0;i<seg;i++)
      {
        auto v=Vec2dEx(i*Pi2/seg,1);
        vec3f dpos=vec3f(v.x*m,v.y*m,z);
        color=point_color;
        DrawCube(pos+r*dpos,r*vec3f_one*0.02);
      }
      color=0xff00bb00;
      DrawTube(pos+vec3f(0,0,z*r),r*0.005,r*m,r*0.005,seg,0);
    }
    QapAssert(!axispoints);
    color=0xffff0000;
    DrawCube(pos,r*vec3f_one*0.04);
    DrawCube(pos+vec3f(0,0,r),r*vec3f_one*0.02);
    DrawCube(pos-vec3f(0,0,r),r*vec3f_one*0.02);
  }
  void DrawCylinderAsLine(const vec3f&a,const vec3f&b,real r,int seg,real ang,bool full=true)
  {
    //QapDebugMsg("Check culling CC and C");
    auto zer=vec3f(0,0,0);
    auto ab=b-a;
    auto z_len=ab.Mag();
    if(!z_len)return;
    auto pos=(a+b)*0.5;
    auto dir=ab.Norm();
    auto up=vec3f(0,1,0);
    if(up==dir)up=vec3f(-1,0,0);
    auto tap=Translate(+pos);
    auto tsp=Translate(-pos);
    QapMat4 dxm;
    vec3f dxzer(zer);
    vec3f dxpos(pos);
    //D3DXQUATERNION dxdir(dir.x,dir.y,dir.x,1);
    
    auto dir_mag=dir.Mag();

    //D3DXQuaternion
    //D3DXMatrixAffineTransformation(&dxm,1,&dxzer,&dxdir,&dxpos);
    //auto at=vec3f(2,-1,2);
    //auto dxat=D3DXVECTOR3(at);
    auto dxup=vec3f(up);
    //D3DXMatrixLookAtLH(&dxm,&dxzer,&dxat,&dxup);
    auto m=MatrixLookAtLH(b,a,up);
    {
      //for(int i=1;i<32;i++)
      QapMat4 tmp;
      {
        //auto prev_r=r;
        //auto r=prev_r*0.1;
        QapDev::BatchScope scope(*this);
        Xf4Scope xf4scope(*this);
        auto rotx=[](const vec3f&dir)->QapMat4
        {
          //float c=dir.x,s=dir.y;
          return QapMat4(
                +1,+0,+0,+0,
                +0,-dir.z,+dir.y,+0,
                +0,-dir.y,-dir.z,+0,
                +0,+0,+0,+1
              );
        };
        auto roty=[](const vec3f&dir)->QapMat4 //top
        {
          float c=dir.z; float s=dir.x;//-dir.x,s=dir.y;
          return QapMat4(
                +c,+0,-s,+0,
                +0,+1,+0,+0,
                +s,+0,+c,+0,
                +0,+0,+0,+1
              );
        };
        auto new_mat=[](const vec3f&ox,const vec3f&oy,const vec3f&oz)
        {
          #define F(ot)ot.x,ot.y,ot.z,0,
          return QapMat4(
            F(ox)
            F(oy)
            F(oz)
            0,0,0,1
          );
          #undef F
        };
        auto rot=[&new_mat,&up](const vec3f&dir)->QapMat4
        {
          //vec3f up=vec3f(0,1,0);
          auto nz=cross(dir,up).Norm();
          auto ny=cross(dir,nz).Norm();
          float x=dir.x; float y=dir.y;float z=dir.z; //-dir.x,s=dir.y;
          return new_mat(nz,ny,dir);
        };
        //xf4=/ *rotx(dir)* /rot(dir)*Translate(pos);
        xf4=rot(dir)*Translate(pos);
        //xf4=MatrixLookAtLH(pos+dir,pos,up);
        //xf4=MatrixLookAtLH(vec3f(i*0.1,i*0.1,i*0.1),vec3f(i*0.1,i*0.1,i*0.2),up);
        DrawCylinder(zer,z_len,r,seg,ang,full);
      }
      return;
      auto prev_color=color;
      auto prev_r=r;
      auto r=prev_r*0.1;
      for(int x=-2;x<=2;x++)
      for(int i=-2;i<2;i++)
      {
        //auto xform=Translate(x,0,0);
        x=+2;
        i=-2;
        for(int u=0;u<16;u++){
        auto xform=Translate(u*0.1,0,0)*RotateX(i*0.4)*RotateY(x*0.4);
        {
          QapDev::BatchScope scope(*this);
          Xf4Scope xf4scope(*this);
          xf4=xform;
          color=prev_color;
          DrawCylinder(zer,z_len,r,seg,ang,full);
          color=0xff402020;
          DrawCube(z_len*vec3f(0,0,+0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          color=0xffffff00;
          DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5),vec3f_one*0.02);
        }
        {
          QapDev::BatchScope scope(*this);
          Xf4Scope xf4scope(*this);
          xf4=RotateX(i*0.4)*RotateY(x*0.4)*Translate(u*0.1,0,0);
          color=prev_color;
          DrawCylinder(zer,z_len,r,seg,ang,full);
          color=0xff402020;
          DrawCube(z_len*vec3f(0,0,+0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5)-vec3f(0,0,1)*0.025,vec3f_one*0.02);
          color=0xffff8000;
          DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.02);
          //DrawCube(z_len*vec3f(0,0,-0.5),vec3f_one*0.02);
        }}
        color=0xffffffff;
        DrawCube(z_len*vec3f(0,0,+0.5)*(RotateX(i*0.4)*RotateY(x*0.4)),vec3f_one*0.03);
        x=100;break;
      }
    }
    auto backup_color=color;
    color=0xffff8000;
    DrawCube(z_len*vec3f(0,0,+0.5),vec3f_one*0.1);
    DrawCube(z_len*vec3f(0,0,-0.5),vec3f_one*0.1);
    color=backup_color;
  }
  void DrawCylinder(const vec3f&pos,real z_len,real r,int seg,real ang,bool full=true)
  {
    DrawCylinderEx(pos,z_len*-0.5,z_len*0.5,r,seg,ang,full);
  }
  void DrawCylinderEx(const vec3f&pos,real z0,real z1,real r,int seg,real ang,bool full=true)
  {
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;
    VID.resize(n*2);
    auto pz0=pos+vec3f(0,0,z0);
    auto pz1=pos+vec3f(0,0,z1);
    for(int i=0;i<n;i++)
    {
      auto p=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[n*0+i]=AddVertex(pz0+toVec3f(p)*r,color,0,0);
      VID[n*1+i]=AddVertex(pz1+toVec3f(p)*r,color,0,0);
    }
    for(int i=0;i<n;i++)
    {
      //z0
      if(full)
      {
        int o=VID[n*0+(0+0)%n];
        int a=VID[n*0+(i+1)%n];
        int b=VID[n*0+(i+2)%n];
        AddTris(o,a,b);
      }
      //z1
      if(full)
      {
        int o=VID[n*1+(0+0)%n];
        int a=VID[n*1+(i+1)%n];
        int b=VID[n*1+(i+2)%n];
        AddTrisInv(o,a,b);
      }
      //if(0)
      {
        int a=VID[n*0+(i+1)%n];
        int b=VID[n*0+(i+2)%n];
        //
        int c=VID[n*1+(i+1)%n];
        int d=VID[n*1+(i+2)%n];
        AddQuadInv(0,a,b,d,c);
      }
    }
    int gg=1;
  }
  void AddVidQuadInv(const vector<int>&VID,int a,int b,int c,int d)
  {
    AddVidTrisInv(VID,a,b,c);
    AddVidTrisInv(VID,c,d,a);
  }
  void AddVidQuad(const vector<int>&VID,int a,int b,int c,int d)
  {
    AddVidTris(VID,a,b,c);
    AddVidTris(VID,c,d,a);
  }
  void AddVidTris(const vector<int>&VID,int a,int b,int c)
  {
    AddTris(VID[a],VID[b],VID[c]);
  }
  void AddVidTrisInv(const vector<int>&VID,int a,int b,int c)
  {
    AddTrisInv(VID[a],VID[b],VID[c]);
  }
  void AddQuadEx(int mod,int offset,int base,int a,int b,int c,int d)
  {
    auto vp=base;
    AddTris(vp+(a+offset)%mod,vp+(b+offset)%mod,vp+(c+offset)%mod);
    AddTris(vp+(c+offset)%mod,vp+(d+offset)%mod,vp+(a+offset)%mod);
  }
  void AddQuad(int base,int a,int b,int c,int d)
  {
    auto vp=base;
    AddTris(vp+a,vp+b,vp+c);
    AddTris(vp+c,vp+d,vp+a);
  }
  void AddQuadInv(int base,int a,int b,int c,int d)
  {
    auto vp=base;
    AddTrisInv(vp+a,vp+b,vp+c);
    AddTrisInv(vp+c,vp+d,vp+a);
  }
  void DrawCubeFast(const vec3f&offset,const vec3f&size=vec3f(1,1,1))
  {
    QapDev::BatchScope scope(*this);
    vec2i arr[]={vec2i(-1,-1),vec2i(+1,-1),vec2i(+1,+1),vec2i(-1,+1)};
    auto vp=VPos;
    for(int i=0;i<4;i++)
    {
      auto a=QapDev::toVec3f(arr[i],-1).RawMul(size*0.5)+offset;
      auto b=QapDev::toVec3f(arr[i],+1).RawMul(size*0.5)+offset;
      AddVertex(a,color);
      AddVertex(b,color);
      AddQuadEx(8,i*2,vp,0,1,3,2);
    }
    AddQuad(vp+0,0,2,4,6);
    AddQuad(vp+1,6,4,2,0);
  }
  void DrawCube(const vec3f&offset,real size=1){
    DrawCube(offset,vec3f_one*size);
  }
  void DrawCube(const vec3f&offset,const vec3f&size)
  {
    DrawCubeFast(offset,size);
    return;
    QapDev::BatchScope scope(*this);
    real d;
    auto add_vertex=[&](float x,float y,float z)
    {
      AddVertex(vec3f(x,y,z).RawMul(size*0.5)+offset);
    };
    int n=VPos;
    auto add_tris=[&](){
      AddTris(n+0,n+1,n+2);
      AddTris(n+2,n+3,n+0);
    };
    #define GRAY(){color=gray;}
    #define YZ(Y,Z)add_vertex(d,Y,Z);
    #define XZ(X,Z)add_vertex(X,d,Z);
    #define XY(X,Y)add_vertex(X,Y,d);
    #define LIST(F){n=VPos;F(-1,-1);F(+1,-1);F(+1,+1);F(-1,+1);add_tris();}
    d=-1;
    LIST(XY);
    LIST(YZ);
    LIST(XZ);
    d=+1;
    LIST(XY);
    LIST(YZ);
    LIST(XZ);
    #undef LIST
    #undef XZ
    #undef YZ
    #undef XY
    #undef GRAY
  }
  void AddIndex(int id){IBA[IPos++]=id;}
public:
  #include "t_geom.inl"
};

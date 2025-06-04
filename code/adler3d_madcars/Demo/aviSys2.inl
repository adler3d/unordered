void AVISceneRenderEx()
{
  auto&Dev=D9Dev;
  vec2i ClientSize=win.GetClientSize();
  if(!Dev.BeginScene())return;
  {
    D3DVIEWPORT9 ViewPort={0,0,DWORD(ClientSize.x),DWORD(ClientSize.y),-1.f,+1.f};
    Dev.pDev->SetViewport(&ViewPort);
    Dev.Set2D(vec2i(0,0),1.0,0,&ClientSize);
    Dev.Clear2D(0xffc8c8c8);
    qDev.NextFrame();
    SceneDoDraw();
  }
  if(!Dev.EndScene())return;
}
void UpdateAVISYS2(const string&fn="foo.avi",int FPS=60,int onkey=VK_F9){
  auto&rec=avirecsys2;
  if(kb.OnDown(onkey)){
    if(rec.enabled){rec.stop();}else{
      rec.start(this,fn);
    }
  }
  rec.update(FPS);
}
template<class TGame>
struct t_avirecsys2:t_avi{
public:
  class TDynamicResource:public QapD3D9Resource{
  public:
    typedef t_avirecsys2 OwnerClass;
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(QapD3DDev9*,pDev,nullptr)\
    ADD(OwnerClass*,pOwner,nullptr)\
    ADD(bool,flag,false)\
    //===
    #include "defprovar.inl"
    //===
    TDynamicResource(){DoReset();}
    ~TDynamicResource(){if(pDev)pDev->Resources.UnReg(this);};
  public:
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);QapAssert(pDev);this->pOwner=pOwner;this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    void OnLost(){if(pOwner){flag=bool(pOwner->surface);pOwner->Free();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->ReInit();}
  };
public:
  template<class TYPE>static void comfree(TYPE*&ptr){if(ptr)ptr->Release();ptr=nullptr;}
  void Free(){comfree(surface);comfree(rt);}
  static const unsigned bg_color=0xffc8c8c8;
  void ReInit(){
    QapAssert(!surface);
    QapAssert(!rt);
    auto sm=GetScreenMode();auto W=sm.W;auto H=sm.H;mem.Init(W,H);mem.Clear(0xff000000);cur.Init(W,H);crb.Init(W,H);prev.Init(W,H);prev.Clear(bg_color);
    auto&pDev=pgame->qDev.pDev;
    pDev->CreateRenderTarget(W,H,pgame->D9Dev.PresParams.pp.BackBufferFormat,D3DMULTISAMPLE_NONE,0,0,&rt,0);
    pDev->CreateOffscreenPlainSurface(W,H,pgame->D9Dev.PresParams.pp.BackBufferFormat,D3DPOOL_SYSTEMMEM,&surface,NULL);
    QapAssert(surface);
    QapAssert(rt)
  }
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(TDynamicResource,DynRes,this)\
  ADD(bool,enabled,false)\
  ADD(bool,avi_pass,false)\
  ADD(IDirect3DSurface9*,surface,nullptr)\
  ADD(IDirect3DSurface9*,rt,nullptr)\
  ADD(TGame*,pgame,nullptr)\
  ADD(QapTexMem,mem,mem)\
  ADD(QapTexMem,cur,mem)\
  ADD(QapTexMem,crb,mem)\
  ADD(QapTexMem,prev,mem)\
  //===
  #include "defprovar.inl"
  //===
  t_avirecsys2(){DoReset();}
 ~t_avirecsys2(){stop();}
  operator bool()const{return enabled;}
  void MountDev(QapD3DDev9&Dev){
    this->DynRes.Mount(this,&Dev);
  }
  void start(TGame*pgame,const string&fn){
    if(enabled)return;
    enabled=true;
    this->pgame=pgame;
    if(!DynRes.pDev)MountDev(pgame->D9Dev);
    ReInit();
    static int c=0;
    if(c==1)QapDebugMsg("taktak");
    c++;
    this->count=0;
    START_AVI(fn.c_str());
  }
  void stop(){
    if(!enabled)return;
    STOP_AVI();
    Free();
    enabled=false;
  }
  void good_blur_idea(){
    /*prev;
    cur=filter(dx);
    crb=blur(cur,2);
    to_avi=prev+crb+cur
    prev=blur(prev+crb,2);*/
    
  }
  void update(int FPS){
    if(!enabled){return;}
    if(!rt||!surface){/*QapNoWay();*/return;}
    auto&pDev=pgame->qDev.pDev;
    
    IDirect3DSurface9*pold=nullptr;
    pDev->GetRenderTarget(0,&pold);
    pDev->SetRenderTarget(0,rt);
    QapAssert(pold);
    avi_pass=true;
    pgame->AVISceneRenderEx();
    avi_pass=false;

    if(pDev->GetRenderTargetData(rt,surface)){QapDebugMsg("GetFrontBufferData - failed");comfree(pold);stop();return;}
    {
      D3DLOCKED_RECT LockedRect;
      surface->LockRect(&LockedRect,NULL,D3DLOCK_READONLY);
      auto*p=(QapColor*)LockedRect.pBits;
      auto W=mem.W;auto H=mem.H;QapColor*pix=mem.get();
      for(int y=0;y<H;y++)for(int x=0;x<W;x++)pix[(H-y-1)*W+x]=p[y*W+x];
      QapBitmapInfo QBI(W,H);ADD_FRAME_FROM_DIB_TO_AVI(&QBI.BH,pix,"XVID",FPS);
      surface->UnlockRect();
    }
    pDev->SetRenderTarget(0,pold);
    comfree(pold);
  }
};
t_avirecsys2<TGame> avirecsys2;
bool is_avi_pass()const{return avirecsys2.avi_pass;}
bool is_avi()const{return avirecsys2.enabled;}
bool is_device_lost()const{return avirecsys2.enabled&&!avirecsys2.rt;}
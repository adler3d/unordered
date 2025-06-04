void UpdateAVISYS(const string&fn="foo.avi",int FPS=60,int onkey=VK_F9){
  auto&rec=avirecsys;
  if(kb.OnDown(onkey)){
    inv(rec.enabled);
    if(rec.enabled)rec.start(qDev.pDev,fn);
    if(!rec.enabled)rec.stop();
  }
  rec.update(qDev.pDev,FPS);
}
struct t_avirecsys:t_avi{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(bool,enabled,false)\
  ADD(IDirect3DSurface9*,surface,NULL)\
  ADD(QapTexMem,mem,mem)\
  //===
  #include "defprovar.inl"
  //===
  t_avirecsys(){DoReset();}
 ~t_avirecsys(){stop();}
  template<class DEV>
  void start(DEV*pDev,const string&fn){
    QapAssert(!surface);
    //D3DDISPLAYMODE mode;pDev->GetDisplayMode(0,&mode);auto W=mode.Width;auto H=mode.Height;
    auto sm=GetScreenMode();auto W=sm.W;auto H=sm.H;mem.Init(W,H);
    pDev->CreateOffscreenPlainSurface(W,H,D3DFMT_A8R8G8B8,D3DPOOL_SCRATCH,&surface,NULL);
    START_AVI(fn.c_str());
  }
  void stop(){
    if(!surface)return;
    STOP_AVI();
    surface->Release();
    surface=nullptr;
  }
  template<class DEV>
  void update(DEV*pDev,int FPS){
    if(!enabled){return;}
    if(pDev->GetFrontBufferData(0,surface)!=D3D_OK){QapDebugMsg("GetFrontBufferData - failed");return;}
    {
      D3DLOCKED_RECT LockedRect;
      surface->LockRect(&LockedRect,NULL,D3DLOCK_READONLY);
      auto*p=(QapColor*)LockedRect.pBits;
      auto W=mem.W;auto H=mem.H;QapColor*pix=mem.get();
      for(int y=0;y<H;y++)for(int x=0;x<W;x++)pix[(H-y-1)*W+x]=p[y*W+x];
      QapBitmapInfo QBI(W,H);ADD_FRAME_FROM_DIB_TO_AVI(&QBI.BH,pix,"XVID",FPS);
      surface->UnlockRect();
    }
  }
};
t_avirecsys avirecsys;
// Interface. App_Side <=> DLL_Side

struct ImgLoader{
  struct string
  {
    const char*ptr;
    int size;
  };
  struct TextureMemory
  {
    void*ptr;
    int W;
    int H;
    TextureMemory(){ptr=0;W=0;H=0;}
    void Circle(unsigned color,int x,int y,int r,int hs)
    {
      vec2d pos(x,y);
      int minr=r-hs;
      int maxr=r+hs;
      int r1=minr*minr;
      int r2=maxr*maxr;
      int i0=std::max(0,x-r-hs);
      int iz=std::min(W-1,x+r+hs);
      int j0=std::max(0,y-r-hs);
      int jz=std::min(H-1,y+r+hs);
      unsigned*pBits=reinterpret_cast<unsigned*>(ptr);
      for(int j=j0;j<=jz;j++)
      {
        for(int i=i0;i<=iz;i++)
        {
          int mm=abs(r-(vec2d(i,j)-pos).SqrMag());
          if((r1<=mm)&&(mm<r2))
          {
            unsigned&FragColor=pBits[j*W+i];
            FragColor=color;
          }
        }
      }
      return;
    }
  };
  struct IEnv
  {
    virtual void InitMemory(TextureMemory&out,int W,int H)=0;
    virtual void FreeMemory(TextureMemory&in)=0;
  };
  virtual void LoadTextureFromFile(IEnv&Env,TextureMemory&Mem,string FileName)=0;
  virtual void SaveTextureToFile(IEnv&Env,TextureMemory&Mem,string FileName)=0;
  virtual bool KeepExt(string ext)=0;
};
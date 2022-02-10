#if(defined(DEF_ADD_HUMUS_HEAD))
extern bool LoadTextureFromFile(QapTexMem&out,const string&FN);
extern void SaveTextureToFile(QapTexMem&in,const string&FN);
#else
namespace QapHumus{
  #include "QapMicro\QapHumus\QapHumus.h"
};
inline bool LoadTextureFromFile(QapTexMem&out,const string&FN)
{
  using namespace QapHumus;
  Image Img;
  Img.loadImage(FN.c_str());
  if(Img.is2D()||Img.is1D())
  {
    int W=Img.getWidth();
    int H=Img.getHeight();
    FORMAT FMT=Img.getFormat();
    if((FMT!=FORMAT_RGB8)&&(FMT!=FORMAT_RGBA8))return false;
    out.Init(W,H);
    QapColor*pBits=out.get();
    QapColor*PC=(QapColor*)pBits;
    struct RGB{byte R,G,B;}; struct RGBA{byte R,G,B,A;};
    #define LOOP(TYPE,DATA,SET){TYPE *SC=(TYPE*)DATA;for(int i=0;i<H;i++)for(int j=0;j<W;j++){TYPE C=*SC;*PC=(SET);PC++;SC++;};};
      if(FMT==FORMAT_RGB8)LOOP(RGB,Img.getPixels(),D3DCOLOR_XRGB(C.R,C.G,C.B));
      if(FMT==FORMAT_RGBA8)LOOP(RGBA,Img.getPixels(),D3DCOLOR_ARGB(C.A,C.R,C.G,C.B));
    #undef LOOP
    return true;
  };
  QapDebugMsg("Error Loading \""+FN+"\"");
  return false;
}

inline void SaveTextureToFile(QapTexMem&in,const string&FN)
{
  using namespace QapHumus;
  Image Img;
  int W=in.W;
  int H=in.H;
  QapColor*pBits=in.get();
  Img.create(FORMAT_RGBA8,W,H,1,1);
  QapColor *C=(QapColor*)Img.getPixels();
  for(int i=0;i<W*H;i++){QapColor &S=pBits[i];C[i]=QapColor(S.a,S.b,S.g,S.r);}
  string ext=UpperStr(GetFileExt(FN));
  #define F(EXT)if(ext==(#EXT)){Img.save##EXT(FN.c_str());return;}
    F(PNG);F(TGA);F(BMP);
  #undef F
  QapDebugMsg("Error Saveing \""+FN+"\"");
}
#endif NO_HUMUS_IMPL
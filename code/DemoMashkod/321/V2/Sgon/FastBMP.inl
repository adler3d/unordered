#include "QapMicro/QapVec.h"

class QapBitmapInfo{
public:
  BITMAPINFO BI;
  BITMAPINFOHEADER&BH;
public:
  QapBitmapInfo(int W,int H):BH(BI.bmiHeader){
    ZeroMemory(&BI,sizeof(BI));
    BH.biSize=sizeof(BI.bmiHeader);
    BH.biWidth=W;  BH.biHeight=H;
    BH.biPlanes=1; BH.biBitCount=32;
    BH.biSizeImage=W*H*4;
  }
};

class FastBMP{
public:
#define DEF_PRO_POOR_DESIGN()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FastBMP)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR($,int,W,SYS,0,$)\
ADDVAR($,int,H,SYS,0,$)\
ADDVAR($,HDC,MDC,SYS,0,$)\
ADDVAR($,QapColor*,mem,SYS,nullptr,$)\
ADDVAR($,HBITMAP,BMP,SYS,0,$)\
ADDEND()
//=====+>>>>>FastBMP
#include "QapGenStruct.inl"
//<<<<<+=====FastBMP
public:
  struct t_rgbh{uchar R,G,B,H;static t_rgbh get_zero(){t_rgbh tmp={0,0,0,0};return tmp;}};
public:
  ~FastBMP(){Free();}
public:
  void Init(HDC DC,int W,int H)
  {
    this->H=H;
    this->W=W;
    MDC=CreateCompatibleDC(DC);
    BMP=CreateCompatibleBitmap(DC,W,H);
    RECT Rect;
    SetRect(&Rect,0,0,W,H);
    SelectObject(MDC,BMP);
    FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
    mem=new QapColor[W*H];
    QapBitmapInfo QBI(W,H);
    GetDIBits(MDC,BMP,0,H,mem,&QBI.BI,DIB_RGB_COLORS);
  }
  void Free()
  {
    if(BMP){QapAssert(DeleteObject(BMP));BMP=0;}
    if(MDC){QapAssert(DeleteDC(MDC));MDC=0;}
    if(mem){delete[] mem;mem=nullptr;}
  }
  void unsafe_setPixel(int x,int y,t_rgbh&color)
  {
    t_rgbh*p=(t_rgbh*)mem;
    p[y*W+x]=color;
  }
  t_rgbh unsafe_getPixel(int x,int y)const
  {
    t_rgbh*p=(t_rgbh*)mem;
    return p[y*W+x];
  }
  void setPixel(int x,int y,t_rgbh&color)
  {
    if((x>=W)||(x<0)||(y>=H)||(y<0))return;
    unsafe_setPixel(x,y,color);
  }
  t_rgbh getPixel(int x,int y,t_rgbh&color)const
  {
    if((x>=W)||(x<0)||(y>=H)||(y<0))return t_rgbh::get_zero();
    return unsafe_getPixel(x,y);
  }
  void dc_to_mem()
  {
    QapBitmapInfo QBI(W,H);
    GetDIBits(MDC,BMP,0,H,mem,&QBI.BI,DIB_RGB_COLORS);
  }
  void mem_to_dc()
  {
    QapBitmapInfo QBI(W,H);
    SetDIBits(MDC,BMP,0,H,mem,&QBI.BI,DIB_RGB_COLORS);
  }
  void renderEx(HDC DC,int Zoom)
  {
    QapBitmapInfo QBI(W,H);
    StretchDIBits(DC,0,0,W*Zoom,H*Zoom,0,0,W,H,mem,&QBI.BI,DIB_RGB_COLORS,SRCCOPY);
  }
  void render(HDC DC)
  {
    auto ok=BitBlt(DC,0,0,W,H,MDC,0,0,SRCCOPY);
    QapAssert(ok);
  }
  void render(HDC DC,int x,int y)
  {
    auto ok=BitBlt(DC,x,y,W,H,MDC,0,0,SRCCOPY);
    QapAssert(ok);
  }
};
#include "QapMicro/QapVec.h"

class QapBitmapInfo
{
public:
  BITMAPINFO BI;
  BITMAPINFOHEADER&BH;
public:
  QapBitmapInfo(int W,int H):BH(BI.bmiHeader)
  {
    ZeroMemory(&BI,sizeof(BI));
    BH.biSize=sizeof(BI.bmiHeader);
    BH.biWidth=W;
    BH.biHeight=H;
    BH.biPlanes=1;
    BH.biBitCount=32;
    BH.biSizeImage=W*H*4;
  }
};

class FastBMP
{
public:
  int W;
  int H;
  HDC MDC;
  QapColor*mem;
  HBITMAP BMP;
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
    QapAssert(DeleteObject(BMP));
    QapAssert(DeleteDC(MDC));
    delete[] mem;
  }
};
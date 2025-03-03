#include "stdafx.h"
#include "FastBMP.h"

FastBMP MountBMP(HDC DC,int W,int H)
{
  FastBMP F; F.H=H; F.W=W;
  ZeroMemory(&F.BI,sizeof(F.BI));
  BITMAPINFOHEADER &BIH=F.BI.bmiHeader;
  BIH.biSize=sizeof(BITMAPINFOHEADER);
  BIH.biWidth=F.W;
  BIH.biHeight=F.H;
  BIH.biPlanes=1;
  BIH.biBitCount=32;
  BIH.biSizeImage=BIH.biWidth*BIH.biHeight*BIH.biBitCount/8;
  F.MDC=CreateCompatibleDC(DC);
  F.BMP=CreateCompatibleBitmap(DC,F.W,F.H);
  RECT Rect; SetRect(&Rect,0,0,F.W,F.H);
  SelectObject(F.MDC,F.BMP); FillRect(F.MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
  F.mem=(COLORREF*)malloc(W*H*4); 
  GetDIBits(F.MDC,F.BMP,0,F.H,F.mem,&F.BI,DIB_RGB_COLORS);
  return F;
}

bool UnMountBMP(FastBMP F)
{
  DeleteObject(F.BMP);
  DeleteDC(F.MDC);
  free(F.mem);
  return true;
}

void FastSetPixel(FastBMP &F,int x,int y,RGBH &Color)
{
  RGBH* C=(RGBH*)F.mem; C+=y*F.W+x; *C=Color;
}

RGBH FastGetPixel(FastBMP &F,int x,int y)
{
  RGBH* C=(RGBH*)F.mem; C+=y*F.W+x; return *C;
}

void FastSetPixel_s(FastBMP &F,int x,int y,RGBH &Color)
{
  if((x>=F.W)||(x<0)||(y>=F.H)||(y<0))return;
  RGBH* C=(RGBH*)F.mem; C+=y*F.W+x; *C=Color;
}

void FastGet(FastBMP F)
{
  GetDIBits(F.MDC,F.BMP,0,F.H,F.mem,&F.BI,DIB_RGB_COLORS);
}

void FastSet(FastBMP F)
{
  SetDIBits(F.MDC,F.BMP,0,F.H,F.mem,&F.BI,DIB_RGB_COLORS);
}

void FastRenderEx(FastBMP F,HDC DC,int Zoom)
{
  StretchDIBits(DC,0,0,F.W*Zoom,F.H*Zoom,0,0,F.W,F.H,F.mem,&F.BI,DIB_RGB_COLORS,SRCCOPY);
}
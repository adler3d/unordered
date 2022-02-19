/*------------------------------------------*/
/*   {<|author : Adler3D(Kashin Ivan) |>   }*/
/*   {<|e-mail : Adler3D@gmail.com    |>   }*/
/*   {<|site   : Adler3d.narod.ru     |>   }*/
/*------------------------------------------*/
#pragma once
/************************************************************************/
/* ���������� ������ ������                                             */
/************************************************************************/
#include "QapSys.h"
#include "QapVec.h"
#include "QapDX.h"
//#include "D3DX9.h"
/************************************************************************/
/* ���������� �����                                                     */
/************************************************************************/
enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};
/************************************************************************/
/* ����������                                                           */
/************************************************************************/
extern QapSys Sys;
/************************************************************************/
/* ����������                                                           */
/************************************************************************/
namespace QapInput
{
  extern vec2d MousePos;
  extern bool Down[];
  extern bool Changed[];
  extern bool News;
  extern int zDelta;
  extern char LastChar;
  extern int LastKey;
  extern const int MAX_KEY;
  void InitMouse();
  void RenderMouse();
  void UpdateMouse();
  vec2d GetMousePos();
  void SysKeyUpdate(int Key,bool Value);
  void SysCharUpdate(char c);
  void Sync();
  inline bool OnDown(size_t key){return Down[key]&&Changed[key];}
}
/************************************************************************/
/* �����                                                                */
/************************************************************************/

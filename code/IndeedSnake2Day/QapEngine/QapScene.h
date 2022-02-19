/*------------------------------------------*/
/*   {<|author : Adler3D(Kashin Ivan) |>   }*/
/*   {<|e-mail : Adler3D@gmail.com    |>   }*/
/*   {<|site   : Adler3d.narod.ru     |>   }*/
/*------------------------------------------*/
#pragma once
/************************************************************************/
/* ���������� ������ ������                                             */
/************************************************************************/
#include "QapType.h"
#include "QapSys.h"
#include "QapDX.h"
//#include "QapVec.h"
/************************************************************************/
/* ����������                                                           */
/************************************************************************/
extern QapSys Sys;
/************************************************************************/
/* ����������                                                           */
/************************************************************************/
class Scene;
namespace SceneVIP
{
  extern QapDX::QapFont SysFont,NewFont;
  extern QapDX::QapTex *TexBall,*TexQuad,*TexQuadSL,*TexLatt;
  void Render();
  void Update();
  void DefRender();
  void DefUpdate();
  void Init();
  void Free();
  void SetActiveScene(Scene *Link);
  void RegScene(Scene *Link,string SceneName);
}
/************************************************************************/
/* ������                                                               */
/************************************************************************/
class Scene
{
protected:
  virtual void SystemUpdate();
  virtual void SystemRender();
public:
  virtual void Render();
  virtual void Update();
  virtual void Init(){SceneName="Unnamed";};
  virtual void Free(){};
public:
  string SceneName;
};
/************************************************************************/
/* �����                                                                */
/************************************************************************/
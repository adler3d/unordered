/*------------------------------------------*/
/*   {<|author : Adler3D(Kashin Ivan) |>   }*/
/*   {<|e-mail : Adler3D@gmail.com    |>   }*/
/*   {<|site   : Adler3d.narod.ru     |>   }*/
/*------------------------------------------*/
#pragma once
/************************************************************************/
/* Подключаем всякое разное                                             */
/************************************************************************/
#include "QapSys.h"
/************************************************************************/
/* Код                                                                  */
/************************************************************************/
#ifdef _DEBUG
#define QapAssert(_Expression)if(!bool(_Expression))do{static bool ignore=false;if(ignore)break;SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCTION__)?_CrtDbgBreak(),(void)0:(void)0;}while(false);
#else
#define QapAssert(_Expression)if(_Expression){};
#endif
inline bool SysQapAssert(const std::string&exp,bool&ignore,const std::string&filename,const int line,const std::string funcname)
{
  std::string text="Source file :\n"+filename
    +"\n\nLine : "+IToS(line)
    +"\n\nFunction :\n"+funcname
    +"\n\nAssertion failed :\n "+exp;
  int nCode = MessageBoxA(Sys.hWnd,text.c_str(),"Assertion failed",MB_ABORTRETRYIGNORE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  ignore=IDIGNORE==nCode;
  if(IDABORT==nCode)exit(3);
  return IDRETRY==nCode;
}
/************************************************************************/
/* Конец                                                                */
/************************************************************************/
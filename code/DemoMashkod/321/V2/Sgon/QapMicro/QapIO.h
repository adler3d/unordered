#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#include "QapType.h"
#include "QapMicro.h"
#include "QapVec.h"
#include "QapTools.h"
//-------------------------------------------//
#include "NakedIO.h"
//-------------------------------------------//
class QapIO
{
public:
  virtual void SavePlainData(void*value,uint count){data->write((char*)value,count);}
  virtual void LoadPlainData(void*value,uint count){data->read((char*)value,count);}
public:
   CrutchIO*data;
};
//-------------------------------------------//
class QapGoodIO:public QapIO
{
public:
  void clear(){mem.clear();pos=0;}
public:
  CrutchIO IO;
  int&pos;
  string&mem;
  QapGoodIO():pos(IO.pos),mem(IO.mem){data=&IO;}
}; 
//-------------------------------------------//
inline string VToS(vec2d Value){return FToS(Value.x)+" "+FToS(Value.y);}
inline string RealToCode(real value){std::stringstream ss;ss<<value;return ss.str();}
inline string Vec2dToCode(vec2d Value){return "vec2d("+RealToCode(Value.x)+","+RealToCode(Value.y)+")";}
inline string CharToCode(char c){return "'"+CToS(c)+"'";}
inline string StrToCode(string str){return "\""+str+"\"";}
//-------------------------------------------//
#ifdef NOUSE_MACRO_BUILD
  #include "..\Macro\HolyShit.h"
#else
//=====>>>>>HolyShit
//<<<<<=====HolyShit
#endif
//-------------------------------------------//
//   {<|          03.01.2014           |>}   //
//-------------------------------------------//
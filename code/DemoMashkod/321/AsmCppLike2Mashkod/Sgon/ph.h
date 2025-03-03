#pragma once
#define DEF_PRO_HEAD
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL
//-------------------------------------------//
#include "main.inl"
//-------------------------------------------//
#include "FastBMP.h"
#include "QapMicro\QapMatrix.h"
#include "D3D9Tools.inl"
#include "QapMicro\QapDev.h"
//-------------------------------------------//
#include "main2.h"
//-------------------------------------------//
#include "GlobalEnv.inl"
static bool IsKeyDown(int vKey){int i=GetAsyncKeyState(vKey); return i<0;}
static bool is_first_part_of(const string&text,const string&first_part){return first_part==text.substr(0,first_part.size());}
static string without_first_part(const string&text,const string&first_part){return text.substr(first_part.size());}
static bool remove_first_part_of(string&text,const string&first_part){if(!is_first_part_of(text,first_part))return false;text=without_first_part(text,first_part);return true;}
//#include "sys_core.h"
//-------------------------------------------//
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL
#include "Entity/OutDeviceBase.inl"
#include "IsSameVisitor.inl"
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
//#include "SpecInfoToolForLex.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"

//#include "t_inl_file_lexem.h"
#include "TSimpleBinarySaver.inl"
//#include "t_inl_file_lexem.h"
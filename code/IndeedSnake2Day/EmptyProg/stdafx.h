#pragma once
/************************************************************************/
/* ������ �����. ��� ����� �������                                       */
/************************************************************************/
#ifndef WINVER				
#define WINVER 0x0501		
#endif
#ifndef _WIN32_WINNT		
#define _WIN32_WINNT 0x0501	
#endif						
#ifndef _WIN32_WINDOWS		
#define _WIN32_WINDOWS 0x0410 
#endif
#ifndef _WIN32_IE			
#define _WIN32_IE 0x0600	
#endif
#define WIN32_LEAN_AND_MEAN
/************************************************************************/
/* ������ ������))))                                                    */
/************************************************************************/
#ifndef NOUSE_MACRO_BUILD
  #ifndef USE_MACRO_BUILD
    #define USE_MACRO_BUILD
  #endif
#endif
#define _USE_MATH_DEFINES
/************************************************************************/
/* ���-�� ��� ����� ������������ ����                                   */
/************************************************************************/
#define NOMINMAX
#include <windows.h>
//#include <Mmsystem.h>
#include <string>
#include <math.h>
//#include "Box2D.h"
/************************************************************************/
/* ���-�� ��� ����� ������������ ���                                    */
/************************************************************************/
#include <d3d9.h>
#define DIRECTINPUT_VERSION  0x0800
#include <dinput.h>
//#include <d3dx9.h>
//#include <d3dx9math.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dinput8.lib")
//#pragma comment(lib, "dxguid.lib")
//#pragma comment(lib, "d3dx9.lib")


#undef min
#undef max
#include <algorithm>
using std::min;using std::max;
#include <assert.h>
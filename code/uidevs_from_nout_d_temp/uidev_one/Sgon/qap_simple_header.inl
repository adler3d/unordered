//-------------------------------------------//
#define NOMENUS
#define NOHELP
#define NOPROFILER
#define NOKANJI
#define NOWH
#define NOSERVICE
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "QapMicro\QapAssert.h"
#include "QapMicro\QapIO.h"
#include "QapMicro\QapClock.h"
#include "part0.inl"
#include "detail.inl"
#include "part5.inl"
#include "ptr.inl"
#include "part1.inl"
#include "memory.inl"
#include "IEnvRTTI.inl"
#include "part2.inl"
class IEsoteric{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IEsoteric)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IEsoteric
#include "QapGenStruct.inl"
//<<<<<+=====IEsoteric
public:
  static void SysHasSelf();
};
// IEsoteric - from part3
#include "CppString.inl"
#include "reg_scope_fast.inl"
struct ICompileUnit{
  virtual const char*get_filename()const=0;
  virtual void RegAll(IEnvRTTI&Env)=0;
  virtual void Run(IEnvRTTI&Env)=0;
  ICompileUnit();
};
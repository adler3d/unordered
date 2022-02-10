//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//
#include "main2.inl"
//-------------------------------------------//
#include "GlobalEnv.inl"
#include "QapMicro\QapHumus.inl"
//-------------------------------------------//
bool IsKeyDown(int vKey){int i=GetAsyncKeyState(vKey); return i<0;}
//-------------------------------------------//
#include "MetaTypeGraber.inl"
#include "BinarySaver.inl"
#include "NewBinarySaver.inl"
//-------------------------------------------//
//`#include "UnitTest\Node\NodeStructures.inl"
//`#include "UnitTest\Node\Node_UT.inl"
#include "ProtoSaver.inl"
#include "Entity\OutDeviceBase.inl"
#include "Tools_yEd.inl"
#include "QapUberSaver.inl"
//#include "AdvBinarySaver.inl"
#include "Entity\eWindow.inl"
#include "Entity\QapProgramD3D9.inl"
//-------------------------------------------//
#include "EntryPoint_v02.inl"
//#include "EntryPoint_v04.inl"
//#include "DynamicTestProgram.inl"
//#include "EntryPoint_v05.inl"

bool QapPublicUberFullSaverBinMem(IEnvRTTI&Env,IQapRawObject&&Object,string&Out)
{
  TQapMemoryStream Stream;
  bool ok=QapUberFullSaver(Env,std::move(Object),UberSaveDeviceBin(Stream));
  Out=Stream.IO.IO.mem;
  return ok;
}

bool QapPublicUberFullLoaderBinMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp)
{
  TQapMemoryStream Stream;
  Stream.IO.IO.mem=Inp;
  bool ok=QapUberFullLoader(Env,std::move(Object),UberLoadDeviceBin(Stream));
  return ok;
}

bool QapPublicUberFullCloneBinMem(IEnvRTTI&Env,IQapRawObject&&Dest,IQapRawObject&&Source)
{
  string mem;
  {bool ok=QapPublicUberFullSaverBinMem(Env,std::move(Source),mem);
  QapAssert(ok);if(!ok)return ok;}
  {bool ok=QapPublicUberFullLoaderBinMem(Env,std::move(Dest),mem);
  QapAssert(ok);if(!ok)return ok;}
  return true;
}

bool QapPublicUberFullSaverBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullSaver(Env,std::move(Object),UberSaveDeviceBin(TQapFileStream(filename,false)));
}

bool QapPublicUberFullLoaderBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullLoader(Env,std::move(Object),UberLoadDeviceBin(TQapFileStream(filename,true)));
}

bool QapPublicUberFullSaverProto(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullSaver(Env,std::move(Object),UberSaveDeviceProto(TQapFileStream(filename,false)));
}

string QapPublicUberFullSaverProtoToStr(IEnvRTTI&Env,IQapRawObject&&Object)
{
  TQapMemoryStream stream;
  QapUberFullSaver(Env,std::move(Object),UberSaveDeviceProto(stream));
  return stream.IO.IO.mem;
}

#ifdef DEF_BUILD_MICRO
  #include "main_2013_12_20.cpp"
#endif

#ifndef DEF_BUILD_MACRO
namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      Sys$$<TType>::GetRTTI(Env);
    }
    virtual void Run(IEnvRTTI&Env)
    {
      EntryPoint_v02(Env);
    }
  };
  ThisCompileUnit ThisUnit;
};
#endif //DEF_BUILD_MACRO//

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //BlurTest();return 0;
  auto&comp_unit_man=TCompileUnitMan::get_man();
  string unit_name=comp_unit_man.arr[0]->get_filename();
  static GlobalEnv gEnv(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TStdAllocator MA;
  {
    TEnvRTTI Env;
    Env.Arr.reserve(1024);
    Env.Alloc=&MA;
    Env.OwnerEnv=&Env;
    TCompileUnitMan::reg_and_run_all(Env);
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}
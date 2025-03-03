#include "StdAfx.h"
/*
namespace dev_space_plain{
  #include "plain_dev_unit.h"
};

namespace dev_space_json{
  #include "json_dev_unit.h"
};

static void Update20130407(IEnvRTTI&Env)
{
  TAutoPtr<ISubProgram> root;
  string arr[]={"qap::bin","qap::proto","qap::plain","qap::json"};
  string filename="mega_file.qap";
  int mode=0;
  bool need_load=false;
  bool need_save=false;
  string mode_as_string=arr[abs(mode)%lenof(arr)];
  if(need_load){
    need_load=false;
    //if(mode_as_string=="qap::plain")dev_space_plain::QapPublicUberFullLoaderPlain(Env.Env,QapRawUberObject(root),filename);
    //if(mode_as_string=="qap::proto")QapPublicUberFullSaverProto(Env.Env,QapRawUberObject(root),filename);
    if(mode_as_string=="qap::bin")QapPublicUberFullLoaderBin(Env,QapRawUberObject(root),filename);
    //if(mode_as_string=="qap::json")dev_space_json::QapPublicUberFullSaverJson(Env.Env,QapRawUberObject(root),filename);
  }
  if(need_save){
    need_save=false;
    if(mode_as_string=="qap::plain")dev_space_plain::QapPublicUberFullSaverPlain(Env,QapRawUberObject(root),filename);
    if(mode_as_string=="qap::proto")QapPublicUberFullSaverProto(Env,QapRawUberObject(root),filename);
    if(mode_as_string=="qap::bin")QapPublicUberFullSaverBin(Env,QapRawUberObject(root),filename);
    if(mode_as_string=="qap::json")dev_space_json::QapPublicUberFullSaverJson(Env,QapRawUberObject(root),filename);
  }
}*/

static void Update20130407(IEnvRTTI&Env)
{
  TAutoPtr<ISubProgram> root;
  auto*p=root.build<ISubProgram>(Env);
  string filename="mega_file.qap";
  if(0)QapPublicUberFullLoaderBin(Env,QapRawUberObject(root),filename);
  if(1)QapPublicUberFullSaverBin(Env,QapRawUberObject(root),filename);
  for(int i=0;i<50;i++){
    //root=nullptr;
    QapPublicUberFullLoaderBin(Env,QapRawUberObject(root),filename);
  }
}

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
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(ISubProgram)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      Update20130407(Env);
    }
    ThisCompileUnit(){
      
    }
  };
  ThisCompileUnit ThisUnit;
}
#include "StdAfx.h"
#include <utility>
#include "Gateway.h"
#include "Gateway.cpp"
#include "InetDownloader.hpp"

void UberInfoBox(const string&caption,const string&text);

class t_network_funcs{
public:
  class NetDownload:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(NetDownload)PARENT(i_sysfunc_with_rtti)OWNER(t_network_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,host,DEF,$,$)\
  ADDVAR(2,string,path,DEF,$,$)\
  ADDEND()
  //=====+>>>>>NetDownload
  #include "QapGenStruct.inl"
  //<<<<<+=====NetDownload
  public:
    void exec(IEnvRTTI&Env)
    {
      DownLoader DL(host,path);
      DL.start();
      for(int i=0;DL.update();i++){
        Sleep(16);
        int wait_here=1;
      }
      out=DL.data;
      string content=DownLoader::GetContent(DL.data);
      DL.stop();
      int gg=1;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(NetDownload)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_network_funcs)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_network_funcs
#include "QapGenStruct.inl"
//<<<<<+=====t_network_funcs
public:
};

void test_2014_02_15(IEnvRTTI&Env)
{
  DownLoader DL("adler.hol.es","/GD/dir.png");
  DL.start();
  for(int i=0;DL.update();i++){
    Sleep(100);
    int wait_here=1;
  }
  string out=DL.data;
  string content=DownLoader::GetContent(out);
  DL.stop();
  int gg=1;
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
        F(TType)F(t_network_funcs)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
      static bool debug=false;
      if(debug){
        test_2014_02_15(Env);
      }
    }
    void Run(IEnvRTTI&Env)
    {
      //test_2014_02_09(Env);
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}
//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//
/*
namespace dev_space_json{
  #include "json_dev_unit.h"
};

namespace dev_space_plain{
  #include "plain_dev_unit.h"
};*/

#include "Gateway.cpp"
#include "InetDownloader.hpp"

class TDownLoader{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDownLoader)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(DownLoader,DL,SYD,$,$)\
ADDEND()
//=====+>>>>>TDownLoader
#include "QapGenStruct.inl"
//<<<<<+=====TDownLoader
public:
  static string CutHeader(const string&data)
  {
    const Extractor::Gripper tag_all("\r\n\r\n","");
    string all=Extractor(data).extract(tag_all);
    return all;
  }
  string get_without_header(){
    return CutHeader(DownLoader::GetContent(DL.data));
  }
};

#include "json_spirit\json_spirit_reader_template.h"
#include "json_spirit\json_spirit_writer_template.h"
#include "main3_qap.inl"

class TWebRecTimeIpId{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWebRecTimeIpId)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,time,DEF,$,$)\
ADDVAR(string,ip,DEF,$,$)\
ADDVAR(int,id,SET,0,$)\
ADDEND()
//=====+>>>>>TWebRecTimeIpId
#include "main3_json_spirit_impl.inl"
//<<<<<+=====TWebRecTimeIpId
public:
  static void process()
  {
    TWebRecTimeIpId wfb;
    
  }
};

class TWebProgram:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWebProgram)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TAutoPtr<TDownLoader>,loader,DEF,$,$)\
ADDVAR(string,webhost,DEF,$,$)\
ADDVAR(string,webpath,DEF,$,$)\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(bool,enabled,SET,true,$)\
ADDVAR(int,tick,SET,0,$)\
ADDVAR(int,loader_tick,SET,0,$)\
ADDVAR(int,prev_time,SET,0,$)\
ADDVAR(int,cur_delta,SET,0,$)\
ADDVAR(int,interval,SET,10000,$)\
ADDVAR(string,recv_buff,DEF,$,$)\
ADDVAR(bool,is_active_loader,SET,false,$)\
ADDEND()
//=====+>>>>>TWebProgram
#include "QapGenStruct.inl"
//<<<<<+=====TWebProgram
public:
  static void SysHasSelf();
public:
  void SetToDef()
  {
    is_active_loader=false;
    webhost="adler.hol.es";
    webpath="/test/?id="+IToS(10000+(rand()%(1024*32)));
    prev_time=GetTickCount();
  }
  void update_buff()
  {
    if(loader)
    {
      recv_buff=loader->get_without_header();
    }
  }
  void OnTick(IEnvRTTI&Env)
  {
    loader=nullptr;
    loader.build<TDownLoader>(Env);
    loader->DL.webhost=this->webhost;
    loader->DL.webpath=this->webpath;
    loader->DL.start();
    is_active_loader=true;
  }
  void Update(IEnv&Env)
  {
    if(!enabled)return;
    if(need_init)
    {
      need_init=false;
      SetToDef();
    }
    if(loader)if(loader->DL.update())
    {
      loader_tick++;
    }else{if(is_active_loader){update_buff();is_active_loader=false;}}
    {
      int time=GetTickCount();
      cur_delta=abs(time-prev_time);
      if(abs(interval)<cur_delta)
      {
        prev_time=time;
        tick++;
        OnTick(Env.Env);
      }
    }
  }
};

class TWebStatusIndicator:public IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWebStatusIndicator)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TWebProgram>,webapp,DEF,$,$)\
ADDVAR(vector<TWebRecTimeIpId>,recv_buff,DEF,$,$)\
ADDEND()
//=====+>>>>>TWebStatusIndicator
#include "QapGenStruct.inl"
//<<<<<+=====TWebStatusIndicator
public:
  void Render(TRenderContext&Context)
  {
    auto&qDev=Context.qDev;
    //qDev.SetColor(0xff001100);
    vec2d dpos=vec2d(20,0);
    int n=get_n();
    vec2d pos=vec2d(-Context.size.x*0.5+dpos.x,0);
    for(int i=0;i<n;i++){
      vec2d p=pos;
      qDev.SetColor((Context.mpos-p).Mag()>8?0xff001100:0xff008000);
      qDev.DrawCircle(Context.pos+p,8,0,1,9);
      pos+=dpos;
    }
  }
  int get_n()
  {
    map<int,int> id2c;
    auto&arr=recv_buff;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      id2c[ex.id]++;
    }
    return id2c.size();
  }
  void Update(TUpdateContext&Context)
  {
    if(!webapp)return;
    auto*pApp=webapp.get();
    string&buff=pApp->recv_buff;
    json_spirit::Value value;
    if(buff.empty())return;
    json_spirit::read_string(buff,value);
    qap_load(this->recv_buff,value);
    int gg=1;
  }
  void GetSize(vec2d&size){size=vec2d(20+get_n()*20,32);}
};

class TEmptyClass{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEmptyClass)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TEmptyClass
#include "QapGenStruct.inl"
//<<<<<+=====TEmptyClass
public:
};

class TDummyClass{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDummyClass)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TEmptyClass,empty,DEF,$,$)\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(vec2d,pos,SET,vec2d(0,0),$)\
ADDVAR(TWeakPtr<TType>,type,DEF,$,$)\
ADDEND()
//=====+>>>>>TDummyClass
#include "QapGenStruct.inl"
//<<<<<+=====TDummyClass
public:
};

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
        F(TType)F(TDummyClass)F(TWebProgram)F(TWebStatusIndicator)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      return;/*
      TWebProgram tmp;
      ISubProgram::IEnv env={Env,0};
      for(int i=0;i<100;i++){tmp.Update(env);Sleep(15);};
      QapPublicUberFullSaverProto(Env,QapRawUberObject(tmp),"out_2013_03_30.h");
      //dev_space_json::QapPublicUberFullSaverJson(Env,QapRawUberObject(tmp),"out_2013_03_28.h");
      //string all=local_storage::g_all;
      int gg=1;
      //QapPublicUberFullSaverProto(Env,QapRawUberObject(tmp),"out_2013_03_04.h");*/
    }
    ThisCompileUnit(){
      srand(time(0));
      int df=0;
    }
  };
  ThisCompileUnit ThisUnit;
}
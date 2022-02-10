#include "StdAfx.h"
#include <utility>
#include "Gateway.h"
#include "Gateway.cpp"

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_04_10.h"
#else
//=====>>>>>main_2013_04_10

//<<<<<=====main_2013_04_10
#endif //DEF_BUILD_MACRO//

#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_GETP(rettype,getp,arr,name)\
  rettype*getp(const string&name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_GETREF(rettype,getref,arr,name)\
  rettype&getref(const string&name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    QapAssert(p);\
    return *p;\
  }


struct HttpTool{
  static string urlencode(const string&str)
  {
    string tmp;tmp.reserve(str.size()*3);
    for(int i=0;i<str.size();i++)
      tmp+=IsLegalChar(str[i])?CToS(str[i]):"%"+CToH_raw(str[i]);
    return tmp;
  }
  static char HToC(const string&str){size_t val;sscanf_s(str.c_str(),"%02x",&val); return char(val);}
  static string urldecode(const string&s)
  {
    auto arr=split(s,"%");
    string out="";
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(i==0){out+=ex;continue;}
      QapAssert(ex.size()>=2);
      out.push_back(char(HToC(ex.substr(0,2))));
      out+=ex.substr(2);
    }
    return out;
  }
  static string get(const string&content,const string&key)
  {
    string out=get_raw(content,key);
    return urldecode(out);
  }
  static string get_raw(const string&content,const string&key){
    auto arr=split(content,"&");
    for(int i=0;i<arr.size();i++){
      auto ex=split(arr[i],"=");
      if(ex.size()<2)continue;
      if(ex[0]==key)return ex[1];
    }
    return "";
  }
  static string str2html(const string&s){
    string rule="&~&amp;#<~&lt;#>~&gt;";
    auto arr=split(rule,"#");
    string out=s;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto e=split(ex,"~");
      auto&from=e[0];
      auto&to=e[1];
      out=StrReplace(out,from,to);
    }
    return out;
  }
  static string str2pre(const string&s){
    return "<pre>"+str2html(s)+"</pre>";
  }
  static string get_all_20131110(){
    string out="";
    out+=gen_dips("azAZ09");
    out+="~|&=<>!:?;,.+-*/%^";
    out+="[]{}()";
    out+="\"\'";
    out+="\t\f\b\r\n\\";
    out+="_$@";
    out+=" `#";
    out+=gen_dips("àÿÀß")+"¸¨¹";
    return out;
  }
  struct t_map_20131110{
    struct t_rec{
      bool ok;
      int ptr;
    };
    vector<t_rec> arr;
  };
  static t_map_20131110 get_map_20131110(){
    t_map_20131110 out;
    auto&arr=out.arr;
    arr.resize(256);
    auto all=get_all_20131110();
    for(int i=0;i<all.size();i++){
      auto&ex=all[i];
      auto u=(uchar)ex;
      auto&ey=arr[u];
      ey.ok=true;
      ey.ptr=i;
    }
    return out;
  }
  static string HexStrToWin1251_20131110(const string&inp){
    QapAssert(!(inp.size()%2));
    string out="";
    static string all=get_all_20131110();
    for(int i=0;i<inp.size();i+=2){
      auto ex=inp.substr(i,2);
      int code=HToI_raw(ex);
      QapAssert(InDip<int>(1,code+1,all.size()))
      out+=all[code];
    }
    return out;
  }
  static string Win1251ToHexStr_20131110(const string&inp){
    string out;
    static auto m=get_map_20131110();
    out.reserve(inp.size()*2);
    for(int i=0;i<inp.size();i++){
      auto ex=(uchar)inp[i];
      QapAssert(m.arr[ex].ok);
      out+=CToH_raw(m.arr[ex].ptr);
    }
    return out;
  }
};
/*
struct WinApiTool{
  static void exec(string command,string arg)
  {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    string tmp_arg=arg;tmp_arg.push_back(0);
    if(CreateProcess(command.c_str(),&tmp_arg[0],NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi))
    {
      WaitForSingleObject(pi.hProcess, INFINITE);
      CloseHandle(pi.hProcess);
      CloseHandle(pi.hThread);
    }
  }
};*/

class T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>T20130410_IProgram
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_IProgram
public:
  virtual void Update(IEnvRTTI&Env){}
};

class T20130410_ProgramNode:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramNode)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(vector<TAutoPtr<T20130410_IProgram>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramNode
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramNode
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }
  void Update(IEnvRTTI&Env)
  {
    for(int i=0;i<Items.size();i++)
    {
      auto&ex=Items[i];
      if(!ex)continue;
      auto*p=ex.get();
      p->Update(Env);
    }
  }
};

class T20130410_ProgramLoop:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramLoop)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(T20130410_ProgramNode,Body,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramLoop
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramLoop
public:
  void Update(IEnvRTTI&Env)
  {
    while(Enabled)
    {
      Body.Update(Env);
    }
  }
};

class T20130410_ProgramLoopV2:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramLoopV2)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(T20130410_ProgramNode,Body,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramLoopV2
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramLoopV2
public:
  void Update(IEnvRTTI&Env)
  {
    while(Enabled)
    {
      Body.Update(Env);
    }
  }
};

class T20130410_ProgramLoopV2Starter:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramLoopV2Starter)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<T20130410_ProgramLoopV2>,loop,DEF,$,$)\
ADDVAR(int,rester_counter,SET,0,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramLoopV2Starter
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramLoopV2Starter
public:
  void Update(IEnvRTTI&Env)
  {
    if(!loop)return;
    rester_counter++;
    loop->Enabled=true;
  }
};

class T20130410_ProgramSleepMega:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramSleepMega)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(int,MS,SET,0,$)\
ADDVAR(int,Sec,SET,1,$)\
ADDVAR(int,Iter,SET,0,$)\
ADDVAR(real,perf_ms,SET,0,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramSleepMega
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramSleepMega
public:
  void Update(IEnvRTTI&Env)
  {
    if(!Enabled)return;
    Sleep(Sec*1000+MS);
    Iter++;
    static QapClock clock;if(!clock.run)clock.Start();
    perf_ms=clock.MS()/real(Iter);
  }
};

class T20130410_ProgramLoopWithIterCount:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramLoopWithIterCount)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(int,IterCount,SET,1,$)\
ADDVAR(T20130410_ProgramNode,Body,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramLoopWithIterCount
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramLoopWithIterCount
public:
  void Update(IEnvRTTI&Env)
  {
    if(!Enabled)return;
    int count=IterCount;
    for(int i=0;i<count;i++)
    {
      Body.Update(Env);
    }
  }
};
string get_first_part(const string&query,char needle){auto p=query.find(needle);if(p==std::string::npos)return query;return query.substr(0,p);}
string get_second_part(const string&query,char needle){auto p=query.find(needle);if(p==std::string::npos)return "";return query.substr(p+1);}
string get_query(const string&webpath){return get_second_part(webpath,'?');}
string get_param_value(const vector<string>&params,const string&param){
  vector<string> p;for(int i=0;i<params.size();i++){qap_add_back(p)=get_first_part(params[i],'=');}
  auto ids=qap_find_str(p,param);
  if(ids.empty())return "";
  return get_second_part(params[ids[0]],'=');
}
string get_decoded_param_value(const vector<string>&params,const string&param){
  return HttpTool::urldecode(get_param_value(params,param));
}

bool params_defined(const vector<string>&params,const string&list)
{
  vector<string> p;for(int i=0;i<params.size();i++){qap_add_back(p)=get_first_part(params[i],'=');}
  auto arr=split(list,",");
  for(int i=0;i<arr.size();i++){if(qap_find_str(p,arr[i]).empty())return false;}
  return true;
}

class T20131110_HttpAnswer{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131110_HttpAnswer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,type,DEF,$,$)\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131110_HttpAnswer
#include "QapGenStruct.inl"
//<<<<<+=====T20131110_HttpAnswer
public:
  static T20131110_HttpAnswer gen(const string&type,const string&body){
    T20131110_HttpAnswer tmp;
    tmp.type=type;
    tmp.body=body;
    return std::move(tmp);
  }
  string get(const string&connection,const string&origin)const{
    //u8;   => utf-8
    //win;  => windows-1251
    //html; => text/html;
    //raw;  => text/plain;
    //404;  => NOT FOUND
    //200;  => OK
    string code="200 OK";
    string content_type="text/plain";
    string charset="utf-8";
    #define f(KEY,CODE)if(string::npos!=type.find(KEY)){CODE;}
    f("200",code="200 OK");
    f("404",code="404 Not Found");
    f("html",content_type="text/html");
    f("raw",content_type="text/plain");
    f("png",content_type="image/png");
    f("u8",charset="utf-8");
    f("win",charset="windows-1251");
    #undef f
    auto con=connection;if(con.empty())con="close";
    string head(
      "HTTP/1.1 "+code+"\r\n"
      "Server: Respondent/1.0\r\n"
      "Content-Type: "+content_type+"; charset="+charset+"\r\n"
      "Transfer-Encoding: chunked\r\n"
      "Connection: "+con+"\r\n"
      +string(origin.empty()?"":"Access-Control-Allow-Origin: "+origin+"\r\n")+
      //"Connection: keep-alive\r\n"
      //"Connection: close\r\n"
      "Cache-Control: no-store, no-cache, must-revalidate\r\n"
      "Pragma: no-cache\r\n\r\n"
    );
    string end(
      "\r\n"
      "0"
      "\r\n\r\n"
    );
    return head+IToH_raw(body.size())+"\r\n"+body+end;
  }
};

class T20130410_GatewayServer{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_GatewayServer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(GatewayServer,serv,SYD,$,$)\
ADDEND()
//=====+>>>>>T20130410_GatewayServer
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_GatewayServer
public:
};

class T20131012_HttpRequest{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131012_HttpRequest)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,method,DEF,$,$)\
ADDVAR(string,host,DEF,$,$)\
ADDVAR(string,webpath,DEF,$,$)\
ADDVAR(string,content,DEF,$,$)\
ADDVAR(string,connection,DEF,$,$)\
ADDVAR(string,origin,DEF,$,$)\
ADDVAR(string,refferer,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131012_HttpRequest
#include "QapGenStruct.inl"
//<<<<<+=====T20131012_HttpRequest
public:
};

class T20150926_HttpTask{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20150926_HttpTask)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(T20131012_HttpRequest,request,DEF,$,$)\
ADDVAR(int,sock,SET,-1,$)\
ADDVAR(string,answer,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,info,DEF,$,$)\
ADDEND()
//=====+>>>>>T20150926_HttpTask
#include "QapGenStruct.inl"
//<<<<<+=====T20150926_HttpTask
public:
};


class TClientInfo{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TClientInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,nick,DEF,$,$)\
ADDVAR(string,addr,DEF,$,$)\
ADDEND()
//=====+>>>>>TClientInfo
#include "QapGenStruct.inl"
//<<<<<+=====TClientInfo
public:
};

class TServerInfo{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TServerInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(vector<string>,clients,DEF,$,$)\
ADDEND()
//=====+>>>>>TServerInfo
#include "QapGenStruct.inl"
//<<<<<+=====TServerInfo
public:
};

class TMachineInfo{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMachineInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(vector<string>,servers,DEF,$,$)\
ADDEND()
//=====+>>>>>TMachineInfo
#include "QapGenStruct.inl"
//<<<<<+=====TMachineInfo
public:
};
static bool add_unique_value(vector<string>&arr,const string&value)
{
  if(!qap_find_str(arr,value).empty())return false;
  qap_add_back(arr)=value;
  return true;
}

class T20150926_ServerMem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20150926_ServerMem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<T20150926_HttpTask>,tasks,DEF,$,$)\
ADDVAR(int,last_server_id,SET,2000,$)\
ADDVAR(int,last_client_id,SET,14000,$)\
ADDVAR(int,last_machine_id,SET,1000,$)\
ADDVAR(vector<TMachineInfo>,machines,DEF,$,$)\
ADDVAR(vector<TServerInfo>,servers,DEF,$,$)\
ADDVAR(vector<TClientInfo>,clients,DEF,$,$)\
ADDEND()
//=====+>>>>>T20150926_ServerMem
#include "QapGenStruct.inl"
//<<<<<+=====T20150926_ServerMem
public:
  PRO_FUNCGEN_GETP(T20150926_HttpTask,get_by_name,tasks,name);
  PRO_FUNCGEN_GETP_BY_FIELD(TMachineInfo,get_machine_by_name,machines,const string&,name);
  PRO_FUNCGEN_GETP_BY_FIELD(TServerInfo,get_server_by_name,servers,const string&,name);
  PRO_FUNCGEN_GETP_BY_FIELD(TClientInfo,get_client_by_name,clients,const string&,name);
  string get_new_server_id(){return IToS(last_server_id++);}
  string get_new_client_id(){return IToS(last_client_id++);}
  string get_new_machine_id(){return IToS(last_machine_id++);}
public:
  typedef T20131110_HttpAnswer t_answer;
public:
  bool update_task(GatewayServer&serv,T20150926_HttpTask&task)
  {
    auto&mem=*this;
    auto ret=[&](const string&answer){task.answer=t_answer::gen("200;raw;win",answer).get(task.request.connection,task.request.origin);return true;};
    auto&request=task.request;
    string q=get_query(request.webpath);
    auto params=split(q,"&");
    auto f=[&](const string&param){return get_decoded_param_value(params,param);};
    if(!servers.empty())if(params_defined(params,"client"))
    {
      string task_name="cnt"+f("client");
      auto id=f("client");
      if(id.empty()||id=="-1"){return ret("?client_id="+get_new_client_id());}
      auto&s=servers.back();
      auto*pc=get_client_by_name(id);
      if(!pc)if(auto*p=mem.get_by_name("srv"+s.name))
      {
        pc=&qap_add_back(clients);pc->name=id;pc->nick=id;pc->addr=s.name;
        p->answer=t_answer::gen("200;raw;win","?add_unit&id="+id+"&name="+id).get(p->request.connection,p->request.origin);
        return ret("?set_server_id="+pc->addr+"&set_actor_id="+id);
      }
      //pc->
      //add_unique_value(pm->servers,id);
    }
    if(params_defined(params,"machine"))
    {
      auto id=f("machine");
      if(id.empty()||id=="-1"){return ret("?machine_id="+get_new_machine_id());}
      auto*p=get_machine_by_name(id);
      if(!p)
      {
        p=&qap_add_back(machines);p->name=id;
        auto nsid=get_new_server_id();
        //qap_add_back(p->servers)=nsid;
        return ret("?add_server&id="+nsid);
      }
    }
    if(params_defined(params,"server,mid"))
    {
      auto id=f("server");auto mid=f("mid");
      if(id.empty()||id=="-1"){return ret("?server_id="+get_new_server_id());}
      auto*pm=get_machine_by_name(mid);
      QapAssert(pm);
      add_unique_value(pm->servers,id);
      auto*ps=get_server_by_name(id);
      if(!ps)
      {
        qap_add_back(servers).name=id;
      }
    }
    return false;
  }
  void update_tasks(GatewayServer&serv)
  {
    for(int i=0;i<tasks.size();i++)
    {
      auto&ex=tasks[i];
      if(!ex.answer.empty())continue;
      if(update_task(serv,ex))return;
    }
  }
  void update(GatewayServer&serv)
  {
    update_tasks(serv);
    for(int i=0;i<tasks.size();i++)
    {
      auto&ex=tasks[i];
      if(ex.answer.empty())continue;
      auto*p=serv.getClientBySock(ex.sock);
      if(p)
      {
        p->send_raw(ex.answer);
        shutdown(p->sock,SD_BOTH);
      }
      ex.sock=-1;
    }
    QapCleanIf(tasks,[&serv](T20150926_HttpTask&ex)->bool{auto*p=serv.getClientBySock(ex.sock);return !p||ex.sock==-1;});
  }
};

class T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>T20130410_IWebPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_IWebPage
public:
  typedef T20131110_HttpAnswer t_answer;
  virtual t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    return t_answer::gen("404;raw;u8","empty");
  }
  template<class TYPE>
  t_answer toProto(IEnvRTTI&Env,TYPE&Ref){
    return t_answer::gen("200;raw;win",QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(Ref)));
  }
};

class T20130410_PageHandler{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_PageHandler)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,page_name,DEF,$,$)\
ADDVAR(TAutoPtr<T20130410_IWebPage>,page_content,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_PageHandler
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_PageHandler
public:
  typedef T20131110_HttpAnswer t_answer;
  t_answer handle(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    if(!page_content)return t_answer::gen("200;raw;u8","page_content=nullptr;");
    return page_content->eval(Env,request,mem);
  }
};

class T20130410_TStaticWebPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TStaticWebPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,content,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TStaticWebPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TStaticWebPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    return t_answer::gen("200;raw;win",content);
  }
};

class T20130410_THtmlStaticWebPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_THtmlStaticWebPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,content,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_THtmlStaticWebPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_THtmlStaticWebPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    return t_answer::gen("200;html;win",content);
  }
};

class T20130410_TFsWebPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TFsWebPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,filename,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TFsWebPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TFsWebPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    if(!CrutchIO::FileExist(filename))return t_answer::gen("404;html;win","file not found:\n"+filename);
    auto content=file_get_contents(filename);
    string f="200;raw;win";
    bool raw=!qap_find_str(split("txt,h,hpp,cpp,c,inl,json,cfg,php,js,xml,css",","),GetFileExt(filename)).empty();
    if(raw)f="200;raw;win";
    bool html=!qap_find_str(split("htm,html,shtml,xhtml",","),GetFileExt(filename)).empty();
    if(html)f="200;html;win";
    return t_answer::gen(f,content);
  }
};

//#include "TSimpleBinarySaver.inl"

class T20130410_TContentWithCounter:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TContentWithCounter)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,content,DEF,$,$)\
ADDVAR(int,counter,SET,0,$)\
ADDVAR(bool,autoinc,SET,true,$)\
ADDEND()
//=====+>>>>>T20130410_TContentWithCounter
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TContentWithCounter
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    int gg=1;
    auto&params=split(request.webpath,"/?");
    string out;
    if(params.size()==2)for(;;)
    {
      auto&list=split(params[1],"&");
      if(list.size()<2)break;
      auto&name=list[0];
      auto&arr=mem.tasks;
      auto*p=mem.get_by_name(name);
      if(!p)break;
      p->answer=t_answer::gen("200;raw;win",request.webpath).get(p->request.connection,p->request.origin);
      out=p->info;
      break;
    }
    return t_answer::gen("200;js;win",out);
  }
};

class TKeyValue{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TKeyValue)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,key,DEF,$,$)\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>TKeyValue
#include "QapGenStruct.inl"
//<<<<<+=====TKeyValue
public:
  void set(const string&key,const string&value){this->key=key;this->value=value;}
};

class T20151006_TCore:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20151006_TCore)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TKeyValue>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>T20151006_TCore
#include "QapGenStruct.inl"
//<<<<<+=====T20151006_TCore
public:
  string get_dump()
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      qap_add_back(out)="\""+ex.key+"\":\n"+ex.value;
    }
    return "{"+join(out,",\n")+"}";
  }
  string to_file(const string&fn,const string&data)
  {
    if(split(fn,"/").size()>1)return "fail";
    if(split(fn,"\\").size()>1)return "fail";
    if(split(fn,":").size()>1)return "fail";
    if(split(fn,".").size()>1)return "fail";
    auto cur_date=split(cur_date_str()," ")[0];
    auto hr=CreateDirectoryA(("logs/"+cur_date).c_str(),0);
    file_put_contents("logs/"+cur_date+"/"+fn+".js",data);//xhr_post("http://localhost/core?tofile&fn=norm",norm());
    return "done";
  }
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    string q=get_query(request.webpath);
    auto params=split(q,"&");
    auto f=[&](const string&param){return get_decoded_param_value(params,param);};
    if(params_defined(params,"client"))
    {
      string task_name="cnt"+f("client");
      auto&t=qap_add_back(mem.tasks);
      t.name=task_name;
      t.request=request;
      t.info=cur_date_str();
      int gg=1;
      return t_answer::gen("task","");
    }
    if(params_defined(params,"machine"))
    {
      auto id=f("machine");
      //if(id.empty()||id=="-1"){return t_answer::gen("200;raw;win","?machine_id="+get_new_machine_id());}
      //auto*p=get_machine_by_name(id);
      //if(!p)
      //{
      //  p=&qap_add_back(machines);p->name=id;
      //  auto nsid=get_new_server_id();
      //  //qap_add_back(p->servers)=nsid;
      //  return t_answer::gen("200;raw;win","?add_server&id="+nsid);
      //}
      string task_name="m"+id;
      QapCleanIf(mem.tasks,[&task_name](T20150926_HttpTask&ex){return ex.name==task_name;});
      //if(machines.
      auto&t=qap_add_back(mem.tasks);
      t.name=task_name;
      t.request=request;
      t.info=cur_date_str();
      int gg=1;
      return t_answer::gen("task","");
    }
    if(params_defined(params,"server,mid"))
    {
      auto id=f("server");
      //auto mid=f("mid");
      //if(id.empty()||id=="-1"){return t_answer::gen("200;raw;win","?server_id="+get_new_server_id());}
      //auto*pm=get_machine_by_name(mid);
      //QapAssert(pm);
      //add_unique_value(pm->servers,id);
      string task_name="srv"+id;
      QapCleanIf(mem.tasks,[&task_name](T20150926_HttpTask&ex){return ex.name==task_name;});
      auto&t=qap_add_back(mem.tasks);
      t.name=task_name;
      t.request=request;
      t.info=cur_date_str();
      int gg=1;
      return t_answer::gen("task","");
    }
    if(params_defined(params,"serv,event"))
    {
      qap_add_back(arr).set(f("serv"),f("event"));
      return t_answer::gen("200;raw;win","/*\n"+cur_date_str()+"\n*/");
    }
    if(params_defined(params,"dump"))return t_answer::gen("200;raw;win",get_dump());
    if(params_defined(params,"tofile,fn"))return t_answer::gen("200;raw;win",to_file(f("fn"),request.content));
    if(params_defined(params,"clear")){auto n=arr.size();arr.clear();return t_answer::gen("200;raw;win","removed = "+IToS(n));};
    return t_answer::gen("200;raw;win","//fail");
  }
};

class T20130410_TArrayPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TArrayPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<string>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TArrayPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TArrayPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    arr.push_back(request.webpath);
    string out;
    for(int i=0;i<arr.size();i++)out+=arr[i]+"\n";
    return t_answer::gen("200;raw;win",out);
  }
};

class T20130410_TCloseServerPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TCloseServerPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<T20130410_ProgramLoopV2>,Loop,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TCloseServerPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TCloseServerPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    if(!Loop)return t_answer::gen("200;raw;win","loop not found");
    Loop->Enabled=false;
    return  t_answer::gen("200;raw;win","loop disabled. ["+cur_date_str()+"]");
  }
};

class TSoketItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSoketItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,time,DEF,$,$)\
ADDVAR(string,data,DEF,$,$)\
ADDEND()
//=====+>>>>>TSoketItem
#include "QapGenStruct.inl"
//<<<<<+=====TSoketItem
public:
};

class T20130410_Socket{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_Socket)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,socket,SET,0,$)\
ADDVAR(string,addr,DEF,$,$)\
ADDVAR(vector<string>,addtime,DEF,$,$)\
ADDVAR(vector<TSoketItem>,news,DEF,$,$)\
ADDVAR(string,content,DEF,$,$)\
ADDVAR(vector<string>,deltime,DEF,$,$)\
ADDVAR(vector<string>,offtime,DEF,$,$)\
ADDVAR(vector<string>,errtime,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_Socket
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_Socket
public:
};

class TProgramHTTPEmptyServerV3:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramHTTPEmptyServerV3)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,auto_restart,SET,true,$)\
ADDVAR(int,Port,SET,81,$)\
ADDVAR(TAutoPtr<T20130410_GatewayServer>,Server,DEF,$,$)\
ADDVAR(vector<T20130410_PageHandler>,pages,DEF,$,$)\
ADDVAR(T20150926_ServerMem,mem,DEF,$,$)\
ADDVAR(vector<T20130410_Socket>,sockets,DEF,$,$)\
ADDVAR(vector<T20130410_Socket>,olds,DEF,$,$)\
ADDVAR(TWeakPtr<T20130410_ProgramNode>,app,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramHTTPEmptyServerV3
#include "QapGenStruct.inl"
//<<<<<+=====TProgramHTTPEmptyServerV3
public:
  class TServerCallback:public ServerCallback{
  public:
    IEnvRTTI&Env;
    TProgramHTTPEmptyServerV3*pOwner;
    TServerCallback(IEnvRTTI&Env,TProgramHTTPEmptyServerV3*pOwner):Env(Env),pOwner(pOwner){}
  public:
    static string GetHeaderOK(const string&content){
      QapNoWay();
      string head(
        "HTTP/1.1 200 OK\r\n"
        "Server: Respondent/1.0\r\n"
        "Content-Type: text/html; charset=utf-8\r\n"
        "Transfer-Encoding: chunked\r\n"
        //"Connection: keep-alive\r\n"
        "Connection: close\r\n"
        "Cache-Control: no-store, no-cache, must-revalidate\r\n"
        "Pragma: no-cache\r\n\r\n"
      );
      string end(
        "\r\n"
        "0"
        "\r\n"
      );
      return head+IToH_raw(content.size())+"\r\n"+content+end;
    }
  public:
    typedef T20131110_HttpAnswer t_answer;
    t_answer GetAnswer(const T20131012_HttpRequest&request)
    {
      string page=Extractor(request.webpath).extract(Extractor::Gripper("","?"));
      if(page.empty())page=request.webpath;
      auto&pages=pOwner->pages;
      for(int i=0;i<pages.size();i++){if(pages[i].page_name==page){return pages[i].handle(Env,request,pOwner->mem);}}
      return t_answer::gen("404;raw;u8","page not found");
    }
    void OnRecvPack(Socket*client,std::string&data){
      int id=find_socket_id(pOwner->sockets,client->sock);
      QapAssert(id>=0);
      auto&s=pOwner->sockets[id];
      s.news.push_back(TSoketItem());
      s.news.back().time=cur_date_str();
      s.news.back().data=data;
      s.content+=data;
      //return;/*
      auto header_get_value=[](const string&header,const string&param)->string
      {
        auto arr=split(header,"\r\n");
        for(int i=1;i<arr.size();i++)
        {
          auto&ex=arr[i];
          if(param!=get_first_part(ex,':'))continue;
          return join(split(get_second_part(ex,':')," "),"");
        }
        return "";
      };
      //
      const Extractor::Gripper tag_method(""," ");
      const Extractor::Gripper tag_webpath(""," HTTP/1.");
      const Extractor::Gripper tag_header("","\r\n\r\n");
      Extractor all(s.content);
      auto header=all.extract(tag_header);
      if(!all)return;
      Extractor e(header);
      auto method=e.extract(tag_method);
      if(!e)return;
      auto webpath=e.extract(tag_webpath);
      if(!e)return;
      auto low_header=LowerStr(header);
      auto host=header_get_value(low_header,"host");
      if(method=="POST")
      {
        auto length=header_get_value(low_header,"content-length");
        length=StrReplace(length," ","");
        int l=SToI(length);
        int dl=(header.size()+tag_header.after.size());
        dl=int(s.content.size()-dl);
        if(l!=dl){
          return;
        }
      }
      string keepalive="keep-alive";
      string con=header_get_value(header,"Connection");
      if(con.empty())con="close";
      con=LowerStr(con);
      string origin=header_get_value(header,"Origin");
      QapAssert(con==keepalive||con=="close");
      T20131012_HttpRequest request;
      request.method=method;
      request.host=host;
      request.webpath=webpath;
      request.content=s.content.substr(all.pos);
      request.connection=con;
      request.origin=origin;
      auto answer=GetAnswer(request);
      auto&tasks=pOwner->mem.tasks;
      if(answer.type=="task"){
        T20150926_HttpTask e;
        tasks.back().sock=client->sock;/*
        e.request=request;
        e.sock=client->sock;
        tasks.push_back(e);*/
        return;
      }
      client->send_raw(answer.get(request.connection,request.origin));
      if(con!=keepalive)
      {
        shutdown(client->sock,SD_BOTH);
      }else{
        s.content="";
      }
    }
    static int find_socket_id(vector<T20130410_Socket>&arr,int id){
      for(int i=0;i<arr.size();i++){
        if(arr[i].socket==id){
          return i;
        }
      }
      return -1;
    }
    void OnAddClient(Socket*client)
    {
      client->set_auto_flush(true);
      int id=find_socket_id(pOwner->sockets,client->sock);
      QapAssert(id<0);
      pOwner->sockets.push_back(T20130410_Socket());
      auto&s=pOwner->sockets.back();
      s.socket=client->sock;
      s.addr=client->name();
      s.addtime.push_back(cur_date_str());
    }
    void OnDeleteClient(Socket*client)
    {
      int id=find_socket_id(pOwner->sockets,client->sock);
      QapAssert(id>=0);
      pOwner->sockets[id].deltime.push_back(cur_date_str());
      vector<T20130410_Socket> tmp;
      for(int i=0;i<pOwner->sockets.size();i++){
        if(i!=id)tmp.push_back(std::move(pOwner->sockets[i]));
        if(i==id)pOwner->olds.push_back(std::move(pOwner->sockets[i]));
      }
      pOwner->sockets=std::move(tmp);
    }
  };
public:
  void Update(IEnvRTTI&Env)
  {
    if(!Enabled)return;
    if(Server&&!Server->serv.runned)Server=nullptr;
    if(auto_restart&&!Server)
    {
      auto*pServer=Server.build<T20130410_GatewayServer>(Env);
      pServer->serv.port=Port;
      pServer->serv.raw=true;
      pServer->serv.start_tcp();
    }
    if(Server)
    {
      auto*pServer=Server.get();
      TServerCallback cb(Env,this);
      pServer->serv.callback=&cb;
      pServer->serv.update_tcp();
      pServer->serv.callback=nullptr;
      mem.update(pServer->serv);
    }
    bool debug_flag=false;
    if(debug_flag)
    {
      auto arr=split("JsTools.js|emails.js","|");
      for(int i=1;i<arr.size();i++){
        auto&ex=arr[i];AddPage<T20130410_TFsWebPage>(Env,"/"+ex)->filename=ex;
      }
    }
  }
  template<class TYPE>
  TYPE*AddPage(IEnvRTTI&Env,const string&name)
  {
    pages.resize(pages.size()+1);
    auto&back=pages.back();
    back.page_name=name;
    return back.page_content.build<TYPE>(Env);
  }
};

class T20131004_Smart:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131004_Smart)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TProgramHTTPEmptyServerV3>,http,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131004_Smart
#include "QapGenStruct.inl"
//<<<<<+=====T20131004_Smart
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request,T20150926_ServerMem&mem)
  {
    if(!http)return t_answer::gen("200;html;u8","http = nullptr;");
    auto*p=http.get();
    if(!p->app)return t_answer::gen("200;html;u8","http->app = nullptr;");
    auto*app=p->app.get();
    return toProto(Env,*app);
  }
};

class T20130410_ProgramHttpRestarter:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramHttpRestarter)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TProgramHTTPEmptyServerV3>,http,DEF,$,$)\
ADDVAR(string,passtime,DEF,$,$)\
ADDVAR(int,rester_counter,SET,0,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramHttpRestarter
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramHttpRestarter
public:
  void Update(IEnvRTTI&Env)
  {
    if(!http)return;
    passtime=cur_date_str();
    rester_counter++;
    auto&arr=http->sockets;
    for(int i=0;i<arr.size();i++){
      arr[i].offtime.push_back(cur_date_str());
      http->olds.push_back(std::move(arr[i]));
    }
    http->sockets.clear();
  }
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
        F(TType)\
        F(T20130410_ProgramNode)\
        F(T20130410_ProgramLoop)\
        F(T20130410_ProgramSleepMega)\
        F(T20130410_ProgramLoopWithIterCount)\
        F(T20130410_TStaticWebPage)\
        F(T20130410_THtmlStaticWebPage)\
        F(T20130410_TFsWebPage)\
        F(T20130410_TContentWithCounter)\
        F(T20130410_TArrayPage)F(TProgramHTTPEmptyServerV3)\
        F(T20130410_ProgramLoopV2)\
        F(T20130410_TCloseServerPage)\
        F(T20130410_ProgramLoopV2Starter)\
        F(T20130410_ProgramHttpRestarter)\
        F(T20131004_Smart)\
        F(T20131012_HttpRequest)\
        F(T20151006_TCore)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      TAutoPtr<T20130410_IProgram> root;
      string filename="mega_file.qap";
      QapPublicUberFullLoaderBin(Env,QapRawUberObject(root),filename);
      if(!root){
        auto*app=root.build<T20130410_ProgramNode>(Env);
        auto*httprestarter=app->AddItem<T20130410_ProgramHttpRestarter>(Env);
        auto*starter=app->AddItem<T20130410_ProgramLoopV2Starter>(Env);
        auto*loop=app->AddItem<T20130410_ProgramLoopV2>(Env);
        starter->loop=loop;
        auto*sleep=loop->Body.AddItem<T20130410_ProgramSleepMega>(Env);
        sleep->MS=16;
        sleep->Sec=0;
        auto*http=loop->Body.AddItem<TProgramHTTPEmptyServerV3>(Env);
        http->Port=7020;
        http->AddPage<T20130410_TCloseServerPage>(Env,"/close")->Loop=loop;
        http->AddPage<T20130410_TContentWithCounter>(Env,"/");
        http->AddPage<T20131004_Smart>(Env,"/smart")->http=http;
        {
          auto arr=split("gg.js","|");
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];http->AddPage<T20130410_TFsWebPage>(Env,"/"+ex)->filename=ex;
          }
        }
        http->AddPage<T20151006_TCore>(Env,"/money");
        http->AddPage<T20151006_TCore>(Env,"/account_server");
        http->app=app;
        httprestarter->http=http;
      }
      root->Update(Env);
      QapPublicUberFullSaverBin(Env,QapRawUberObject(root),filename);
      QapPublicUberFullSaverProto(Env,QapRawUberObject(root),"maga_file.h");
    }
    ThisCompileUnit(){
      
    }
  };
  ThisCompileUnit ThisUnit;
}

/*
auto cur_dir_str=[]()->string{
  char buff[255];
  GetModuleFileName(NULL,&buff[0],255);
  return &buff[0];
};
*/
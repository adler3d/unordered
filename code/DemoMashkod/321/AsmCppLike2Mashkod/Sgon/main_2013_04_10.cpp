#include "StdAfx.h"
#include <utility>
#include "Gateway.h"
#include "Gateway.cpp"

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_04_10.h"
#else
//=====>>>>>main_2013_04_10

#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
#include "meta_lexer.inl"
#include "t_simple_stat_lex.inl"
//#include "t_json.inl"

//<<<<<=====main_2013_04_10
#endif //DEF_BUILD_MACRO//

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
};

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
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,vector<TAutoPtr<T20130410_IProgram>>,Items,DEF,$,$)\
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
ADDVAR(0,bool,Enabled,SET,true,$)\
ADDVAR(1,T20130410_ProgramNode,Body,DEF,$,$)\
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
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,bool,Enabled,SET,true,$)\
ADDVAR(2,T20130410_ProgramNode,Body,DEF,$,$)\
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
ADDVAR(0,TWeakPtr<T20130410_ProgramLoopV2>,loop,DEF,$,$)\
ADDVAR(1,int,rester_counter,SET,0,$)\
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
ADDVAR(0,bool,Enabled,SET,true,$)\
ADDVAR(1,int,MS,SET,0,$)\
ADDVAR(2,int,Sec,SET,1,$)\
ADDEND()
//=====+>>>>>T20130410_ProgramSleepMega
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_ProgramSleepMega
public:
  void Update(IEnvRTTI&Env)
  {
    if(!Enabled)return;
    Sleep(Sec*1000+MS);
  }
};

class T20130410_ProgramLoopWithIterCount:public T20130410_IProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_ProgramLoopWithIterCount)PARENT(T20130410_IProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,bool,Enabled,SET,true,$)\
ADDVAR(1,int,IterCount,SET,1,$)\
ADDVAR(2,T20130410_ProgramNode,Body,DEF,$,$)\
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

class T20131110_HttpAnswer{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131110_HttpAnswer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,type,DEF,$,$)\
ADDVAR(1,string,body,DEF,$,$)\
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
  string get()const{
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
    f("u8",charset="utf-8");
    f("win",charset="windows-1251");
    #undef f
    string head(
      "HTTP/1.1 "+code+"\r\n"
      "Server: Respondent/1.0\r\n"
      "Content-Type: "+content_type+"; charset="+charset+"\r\n"
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
    return head+IToH_raw(body.size())+"\r\n"+body+end;
  }
};

class T20130410_GatewayServer{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_GatewayServer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR($,GatewayServer,serv,SYD,$,$)\
ADDEND()
//=====+>>>>>T20130410_GatewayServer
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_GatewayServer
public:
};

class T20131012_HttpRequest{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131012_HttpRequest)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,method,DEF,$,$)\
ADDVAR(1,string,host,DEF,$,$)\
ADDVAR(2,string,webpath,DEF,$,$)\
ADDVAR(3,string,content,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131012_HttpRequest
#include "QapGenStruct.inl"
//<<<<<+=====T20131012_HttpRequest
public:
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
  virtual t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
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
ADDVAR(0,string,page_name,DEF,$,$)\
ADDVAR(1,TAutoPtr<T20130410_IWebPage>,page_content,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_PageHandler
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_PageHandler
public:
  typedef T20131110_HttpAnswer t_answer;
  t_answer handle(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    if(!page_content)return t_answer::gen("200;raw;u8","page_content=nullptr;");
    return page_content->eval(Env,request);
  }
};

class T20130410_TStaticWebPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TStaticWebPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,content,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TStaticWebPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TStaticWebPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    return t_answer::gen("200;raw;win",content);
  }
};

class T20130410_TContentWithCounter:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TContentWithCounter)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,content,DEF,$,$)\
ADDVAR(1,int,counter,SET,0,$)\
ADDVAR(2,bool,autoinc,SET,true,$)\
ADDEND()
//=====+>>>>>T20130410_TContentWithCounter
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TContentWithCounter
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    if(autoinc)counter++;
    return t_answer::gen("200;raw;win",content+IToS(counter));
  }
};

class T20130410_TArrayPage:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_TArrayPage)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<string>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TArrayPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TArrayPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
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
ADDVAR(0,TWeakPtr<T20130410_ProgramLoopV2>,Loop,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_TCloseServerPage
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_TCloseServerPage
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
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
ADDVAR(0,string,time,DEF,$,$)\
ADDVAR(1,string,data,DEF,$,$)\
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
ADDVAR(0,int,socket,SET,0,$)\
ADDVAR(1,string,addr,DEF,$,$)\
ADDVAR(2,vector<string>,addtime,DEF,$,$)\
ADDVAR(3,vector<TSoketItem>,news,DEF,$,$)\
ADDVAR(4,string,content,DEF,$,$)\
ADDVAR(5,vector<string>,deltime,DEF,$,$)\
ADDVAR(6,vector<string>,offtime,DEF,$,$)\
ADDVAR(7,vector<string>,errtime,DEF,$,$)\
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
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,bool,Enabled,SET,true,$)\
ADDVAR(2,bool,auto_restart,SET,true,$)\
ADDVAR(3,int,Port,SET,81,$)\
ADDVAR(4,TAutoPtr<T20130410_GatewayServer>,Server,DEF,$,$)\
ADDVAR(5,vector<T20130410_PageHandler>,pages,DEF,$,$)\
ADDVAR(6,vector<T20130410_Socket>,sockets,DEF,$,$)\
ADDVAR(7,vector<T20130410_Socket>,olds,DEF,$,$)\
ADDVAR(8,TWeakPtr<T20130410_ProgramNode>,app,DEF,$,$)\
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
      for(int i=0;i<pages.size();i++){if(pages[i].page_name==page){return pages[i].handle(Env,request);}}
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
      const Extractor::Gripper tag_method(""," ");
      const Extractor::Gripper tag_webpath(""," HTTP/1.1\r\n");
      const Extractor::Gripper tag_host("Host: ","\r\n");
      const Extractor::Gripper tag_header("","\r\n\r\n");
      Extractor all(s.content);
      auto header=all.extract(tag_header);
      if(!all)return;
      Extractor e(header);
      auto method=e.extract(tag_method);
      if(!e)return;
      auto webpath=e.extract(tag_webpath);
      if(!e)return;
      auto host=e.extract(tag_host);
      if(!e)return;
      if(method=="POST"){
        Extractor e(LowerStr(header));
        const Extractor::Gripper tag_length("content-length:","\r\n");
        auto length=e.extract(tag_length);
        length=StrReplace(length," ","");
        int l=SToI(length);
        int dl=(header.size()+tag_header.after.size());
        dl=int(s.content.size()-dl);
        if(l!=dl){
          return;
        }
      }
      T20131012_HttpRequest request;
      request.method=method;
      request.host=host;
      request.webpath=webpath;
      request.content=s.content.substr(all.pos);
      client->send_raw(GetAnswer(request).get());
      shutdown(client->sock,SD_BOTH);//*/
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
    if(Server){
      auto*pServer=Server.get();
      TServerCallback cb(Env,this);
      pServer->serv.callback=&cb;
      pServer->serv.update_tcp();
      pServer->serv.callback=nullptr;
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
ADDVAR(0,TWeakPtr<TProgramHTTPEmptyServerV3>,http,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131004_Smart
#include "QapGenStruct.inl"
//<<<<<+=====T20131004_Smart
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
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
ADDVAR(0,TWeakPtr<TProgramHTTPEmptyServerV3>,http,DEF,$,$)\
ADDVAR(1,string,passtime,DEF,$,$)\
ADDVAR(2,int,rester_counter,SET,0,$)\
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

class t_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,int,next,SET,0,$)\
ADDEND()
//=====+>>>>>t_item
#include "QapGenStruct.inl"
//<<<<<+=====t_item
public:
};

class t_app{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_app)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_app
#include "QapGenStruct.inl"
//<<<<<+=====t_app
public:
};

class TItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,string,name,DEF,$,$)\
ADDVAR(2,TWeakPtr<TItem>,next,DEF,$,$)\
ADDEND()
//=====+>>>>>TItem
#include "QapGenStruct.inl"
//<<<<<+=====TItem
public:
};

class TApp{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TApp)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,vector<TItem>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TApp
#include "QapGenStruct.inl"
//<<<<<+=====TApp
public:
};

class TGateway{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGateway)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_app,a,DEF,$,$)\
ADDVAR(1,TApp,b,DEF,$,$)\
ADDEND()
//=====+>>>>>TGateway
#include "QapGenStruct.inl"
//<<<<<+=====TGateway
public:
  struct t_solver_AToB{
    vector<t_item>&a;
    vector<TItem>&b;
    TItem*ConvIdToPtr(int id){
      return &b[id];
    }
    static void ItemMove(t_solver_AToB&solver,t_item&a,TItem&b){
      b.name=a.name;
      b.next=solver.ConvIdToPtr(a.next);
    }
    static void ArrMove(t_solver_AToB&solver,vector<t_item>&a,vector<TItem>&b){
      b.resize(a.size());
      for(int i=0;i<a.size();i++){
        ItemMove(solver,a[i],b[i]);
      }
    }
    static void AppMove(t_solver_AToB&solver,t_app&a,TApp&b){
      b.name=a.name;
      ArrMove(solver,a.arr,b.arr);
    }
  };
public:
  struct t_solver_BToA{
    vector<t_item>&a;
    vector<TItem>&b;
    int ConvIdToPtr(TWeakPtr<TItem>&ptr){
      auto*p=ptr.get();
      for(int i=0;i<b.size();i++){if(&b[i]==p)return i;}
      QapAssert(false);
      return -1;
    }
    static void ItemMove(t_solver_BToA&solver,t_item&a,TItem&b){
      a.name=b.name;
      a.next=solver.ConvIdToPtr(b.next);
    }
    static void ArrMove(t_solver_BToA&solver,vector<t_item>&a,vector<TItem>&b){
      a.resize(b.size());
      for(int i=0;i<b.size();i++){
        ItemMove(solver,a[i],b[i]);
      }
    }
    static void AppMove(t_solver_BToA&solver,t_app&a,TApp&b){
      a.name=b.name;
      ArrMove(solver,a.arr,b.arr);
    }
  };
public:
  void go_ab(){
    t_solver_AToB solver={a.arr,b.arr};
    t_solver_AToB::AppMove(solver,a,b);
  }
  void go_ba(){
    t_solver_BToA solver={a.arr,b.arr};
    t_solver_BToA::AppMove(solver,a,b);
  }
};

class TNode{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TNode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,int,next,SET,-1,$)\
ADDVAR(2,vector<TNode>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>TNode
#include "QapGenStruct.inl"
//<<<<<+=====TNode
public:
  vector<string> get_all_path(){
    vector<string> out;
    out.push_back("/");
    auto arr=get_items_path();
    for(int i=0;i<arr.size();i++)out.push_back(arr[i]);
    return out;
  }
  vector<string> get_items_path(){
    vector<string> out;
    for(int i=0;i<items.size();i++){
      auto&ex=items[i];
      out.push_back("/"+ex.name);
      auto arr=ex.get_items_path();
      for(int i=0;i<arr.size();i++){
        out.push_back("/"+ex.name+arr[i]);
      }
    }
    return out;
  }
  vector<SelfClass*> get_all_ptrs(){
    vector<SelfClass*> out;
    out.push_back(this);
    for(int i=0;i<items.size();i++){
      auto arr=items[i].get_all_ptrs();
      for(int i=0;i<arr.size();i++){
        out.push_back(arr[i]);
      }
    }
    return out;
  }
};

class t_node{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_node)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,string,next,DEF,$,$)\
ADDVAR(2,vector<t_node>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>t_node
#include "QapGenStruct.inl"
//<<<<<+=====t_node
public:
  t_node&add(const string&name){return add(name,"");}
  t_node&add(const string&name,const string&next)
  {
    QapAssert(find(name)<0);
    items.push_back(t_node());
    auto&back=items.back();
    back.name=name;
    back.next=next;
    return back;
  }
  bool check(int i)const{return (i>=0)&&(i<items.size());}
  int find(const string&name)const{for(int i=0;i<items.size();i++){if(items[i].name==name)return i;}return -1;}
  static string drop_last_element(const string&path){
    auto p=path.rfind("/");
    QapAssert(p!=std::string::npos);
    string test=path.substr(0,p);
    QapAssert(test.back()!='/');
    QapAssert(!test.empty());
    return path.substr(0,p);
  }
  vector<string> get_all_path(){
    vector<string> out;
    out.push_back("/");
    auto arr=get_items_path();
    for(int i=0;i<arr.size();i++)out.push_back(arr[i]);
    return out;
  }
  vector<string> get_items_path(){
    vector<string> out;
    for(int i=0;i<items.size();i++){
      auto&ex=items[i];
      out.push_back("/"+ex.name);
      auto arr=ex.get_items_path();
      for(int i=0;i<arr.size();i++){
        out.push_back("/"+ex.name+arr[i]);
      }
    }
    return out;
  }
  int conv_way_to_id(vector<int>&arr)const
  {
    int out=0;
    auto*p=this;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(p->check(ex));
      for(int j=0;j<ex;j++){
        out+=p->items[j].get_total_childs();
      }
      p=&p->items[ex];
      out++;
    }
    return out;
  }
  int get_total_childs()const
  {
    int out=0;
    for(int i=0;i<items.size();i++){
      out+=items[i].get_total_childs();
    }
    return out;
  }
  std::pair<bool,vector<int>> try_get_way(const string&path)const
  {
    std::pair<bool,vector<int>> out(false,vector<int>());
    auto&ok=out.first;
    vector<int>&way=out.second;
    if(path=="/"){ok=true;return out;}
    QapAssert(!path.empty());
    QapAssert(path[0]=='/');
    auto arr=split(path.substr(1),"/");
    QapAssert(!arr.empty());
    auto*p=this;
    for(int i=0;i<arr.size();i++){
      QapAssert(!arr[i].empty());
      int id=p->find(arr[i]);
      if(id<0){return out;}
      way.push_back(id);
      p=&p->items[id];
    }
    ok=true;
    return out;
  }
  vector<int> get_way(const string&path)
  {
    vector<int> way;
    QapAssert(!path.empty());
    QapAssert(path[0]=='/');
    auto arr=split(path.substr(1),"/");
    QapAssert(!arr.empty());
    auto*p=this;
    for(int i=0;i<arr.size();i++){
      QapAssert(!arr[i].empty());
      int id=p->find(arr[i]);
      if(id<0){id=p->items.size();p->add(arr[i]);}
      way.push_back(id);
      p=&p->items[id];
    }
    return way;
  }
  t_node&traverse(const vector<int>&way)
  {
    auto*p=this;
    for(int i=0;i<way.size();i++){
      QapAssert(p->check(way[i]));
      p=&p->items[way[i]];
    }
    return *p;
  }
  t_node&get(const string&path)
  {
    auto&arr=get_way(path);
    auto&node=traverse(arr);
    return node;
  }
};

class T20131022Conv{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131022Conv)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_node,a,DEF,$,$)\
ADDVAR(1,TNode,b,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131022Conv
#include "QapGenStruct.inl"
//<<<<<+=====T20131022Conv
public:
  struct t_solver_AToB{
    t_node&a;
    TNode&b;
    int ConvPathToId(const string&path){
      auto&ret=a.try_get_way(path);
      QapAssert(ret.first);
      auto arr=a.get_all_path();
      for(int i=0;i<arr.size();i++)if(arr[i]==path)return i;
      return -1;
    }
    static void ItemsMove(t_solver_AToB&solver,vector<t_node>&a,vector<TNode>&b){
      b.resize(a.size());
      for(int i=0;i<a.size();i++){
        NodeMove(solver,a[i],b[i]);
      }
    }
    static void NodeMove(t_solver_AToB&solver,t_node&a,TNode&b){
      b.name=a.name;
      b.next=solver.ConvPathToId(a.next);
      ItemsMove(solver,a.items,b.items);
    }
  };
public:
  struct t_solver_BToA{
    t_node&a;
    TNode&b;
    string ConvIdToPath(int id){
      auto arr=b.get_all_path();
      QapAssert(id>=0);
      QapAssert(id<arr.size());
      return arr[id];
    }
    static void ItemsMove(t_solver_BToA&solver,vector<t_node>&a,vector<TNode>&b){
      a.resize(b.size());
      for(int i=0;i<b.size();i++){
        NodeMove(solver,a[i],b[i]);
      }
    }
    static void NodeMove(t_solver_BToA&solver,t_node&a,TNode&b){
      a.name=b.name;
      a.next=solver.ConvIdToPath(b.next);
      ItemsMove(solver,a.items,b.items);
    }
  };
public:
  void go_ab(){
    t_solver_AToB solver={a,b};
    t_solver_AToB::NodeMove(solver,a,b);
  }
  void go_ba(){
    t_solver_BToA solver={a,b};
    t_solver_BToA::NodeMove(solver,a,b);
  }
};

class TSmartNode{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSmartNode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,string,name,DEF,$,$)\
ADDVAR(2,TWeakPtr<TSmartNode>,next,DEF,$,$)\
ADDVAR(3,vector<TSmartNode>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>TSmartNode
#include "QapGenStruct.inl"
//<<<<<+=====TSmartNode
public:
  vector<SelfClass*> get_all_ptrs(){
    vector<SelfClass*> out;
    out.push_back(this);
    for(int i=0;i<items.size();i++){
      auto arr=items[i].get_all_ptrs();
      for(int i=0;i<arr.size();i++){
        out.push_back(arr[i]);
      }
    }
    return out;
  }
};

class T20131022SmartConv{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131022SmartConv)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TNode,a,DEF,$,$)\
ADDVAR(1,TSmartNode,b,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131022SmartConv
#include "QapGenStruct.inl"
//<<<<<+=====T20131022SmartConv
public:
  struct t_solver_AToB{
    TNode&a;
    TSmartNode&b;
    TSmartNode*ConvPathToId(const int&id){
      auto arr=b.get_all_ptrs();
      QapAssert(id>=0);
      QapAssert(id<arr.size());
      return arr[id];
    }
    static void ItemsMove(vector<TNode>&a,vector<TSmartNode>&b){
      b.resize(a.size());
      for(int i=0;i<a.size();i++){
        NodeMove(a[i],b[i]);
      }
    }
    static void NodeMove(TNode&a,TSmartNode&b){
      b.name=a.name;
      //b.next=solver.ConvPathToId(a.next);
      ItemsMove(a.items,b.items);
    }
    static void ItemsMovePtr(t_solver_AToB&solver,vector<TNode>&a,vector<TSmartNode>&b){
      //b.resize(a.size());
      for(int i=0;i<a.size();i++){
        NodeMovePtr(solver,a[i],b[i]);
      }
    }
    static void NodeMovePtr(t_solver_AToB&solver,TNode&a,TSmartNode&b){
      //b.name=a.name;
      b.next=solver.ConvPathToId(a.next);
      ItemsMovePtr(solver,a.items,b.items);
    }
  };
  struct t_solver_BToA{
    TNode&a;
    TSmartNode&b;
    int ConvPathToId(TWeakPtr<TSmartNode>&ref){
      auto*ptr=ref.get();
      if(!ptr)return -1;
      auto arr=b.get_all_ptrs();
      for(int i=0;i<arr.size();i++)if(arr[i]==ptr){return i;}
      QapDebugMsg("WTF?");
      return -1;
    }
    static void ItemsMove(vector<TNode>&a,vector<TSmartNode>&b){
      b.resize(a.size());
      for(int i=0;i<a.size();i++){
        NodeMove(a[i],b[i]);
      }
    }
    static void NodeMove(TNode&a,TSmartNode&b){
      b.name=a.name;
      //b.next=solver.ConvPathToId(a.next);
      ItemsMove(a.items,b.items);
    }
    static void ItemsMovePtr(t_solver_BToA&solver,vector<TNode>&a,vector<TSmartNode>&b){
      //b.resize(a.size());
      for(int i=0;i<a.size();i++){
        NodeMovePtr(solver,a[i],b[i]);
      }
    }
    static void NodeMovePtr(t_solver_BToA&solver,TNode&a,TSmartNode&b){
      //b.name=a.name;
      a.next=solver.ConvPathToId(b.next);
      ItemsMovePtr(solver,a.items,b.items);
    }
  };
  void go_ab(){
    t_solver_AToB solver={a,b};
    t_solver_AToB::NodeMove(a,b);
    t_solver_AToB::NodeMovePtr(solver,a,b);
  }
  void go_ba(){
    t_solver_BToA solver={a,b};
    t_solver_BToA::NodeMove(a,b);
    t_solver_BToA::NodeMovePtr(solver,a,b);
  }
};

#ifdef DEF_BUILD_MACRO
  #include "../Macro/T20131011_Gateway.h"
#else
//=====>>>>>T20131011_Gateway
#define array(TYPE,SIZE)array<TYPE,SIZE>
class T20131011_Gateway:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131011_Gateway)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TGateway,gateway,DEF,$,$)\
ADDVAR(1,T20131022Conv,conv,DEF,$,$)\
ADDVAR(2,T20131022SmartConv,smartconv,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131011_Gateway
#include "QapGenStruct.inl"
//<<<<<+=====T20131011_Gateway
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    const auto&webpath=request.webpath;
    if(webpath=="/gw?do=echo(conv.a)"){
      auto arr=conv.a.get_all_path();
      return t_answer::gen("200;raw;win",join(arr,"\n"));
    }
    if(webpath=="/gw?smartconv=move"){
      smartconv.a=std::move(conv.b);
      return toProto(Env,smartconv);
    }
    if(webpath=="/gw?smartconv=ret"){
      conv.b=std::move(smartconv.a);
      return toProto(Env,conv);
    }
    if(webpath=="/gw?smartconv=edit"){
      smartconv.b.items[0].next=&smartconv.b;
      return toProto(Env,smartconv);
    }
    if(webpath=="/gw?smartconv=AToB"){
      smartconv.go_ab();
      return toProto(Env,smartconv);
    }
    if(webpath=="/gw?smartconv=BToA"){
      smartconv.go_ba();
      return toProto(Env,smartconv);
    }
    if(webpath=="/gw?conv=AToB"){
      conv.go_ab();
      return toProto(Env,conv);
    }
    if(webpath=="/gw?conv=BToA"){
      conv.go_ba();
      return toProto(Env,conv);
    }
    if(webpath=="/gw?root"){
      auto&root=conv.a;
      root.name="root";
      root.next="/";
      root.get("/nullptr").next="/nullptr";
      root.get("/data").next="/nullptr";
      root.get("/data/0").next="/nullptr";
      root.get("/data/1").next="/nullptr";
      root.get("/node").next="/nullptr";
      root.get("/node/fs").next="/nullptr";
      root.get("/node/fs/file").next="/data/0";
      root.get("/node/fs/readme").next="/data/1";
      /*
      root.name="root";
      root.add("dev","/root/foo/bar");
      root.add("foo").add("bar");
      auto&node=root.add("node","/root/foo");
      node.add("system").add("empty");
      auto&fs=node.add("fs");
      fs.add("file");
      fs.add("readme","/root/fs/readme").add("line0","/root/fs/readme.txt/line0");
      */
      return toProto(Env,root);
    }
    if(webpath=="/gw?html"){
      CrutchIO IO;
      IO.LoadFile("http.html");
      return t_answer::gen("200;html;win",IO.mem);
    }
    if(webpath=="/gw?set=a"){
      gateway.a.arr.push_back(t_item());gateway.a.arr.back().name="p0";gateway.a.arr.back().next=1;
      gateway.a.arr.push_back(t_item());gateway.a.arr.back().name="p1";gateway.a.arr.back().next=2;
      gateway.a.arr.push_back(t_item());gateway.a.arr.back().name="p2";gateway.a.arr.back().next=0;
    }
    if(webpath=="/gw?AtoB"){
      gateway.go_ab();
    }
    if(webpath=="/gw?BtoA"){
      gateway.go_ba();
    }
    if(webpath=="/gw?hc=0"){
      gateway.b.arr.push_back(TItem());
      gateway.b.arr.back().name="p3";
      gateway.b.arr.back().next=&gateway.b.arr[2];
    }
    if(webpath=="/gw?hc=swap"){
      std::swap(gateway.b.arr[1],gateway.b.arr.back());
    }
    return toProto(Env,*this);
  }
};
#undef array
//<<<<<=====T20131011_Gateway
#endif //DEF_BUILD_MICRO//

class T20131012_Eval:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131012_Eval)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>T20131012_Eval
#include "QapGenStruct.inl"
//<<<<<+=====T20131012_Eval
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    const auto&webpath=request.webpath;
    const auto&content=request.content;
    string code=HttpTool::get(content,"code");
    string data=HttpTool::get(content,"data");
    CrutchIO IO;IO.mem=code;IO.SaveFile("Core/Sgon/test.inl");
    WinApiTool::exec("comp.bat","");
    IO.LoadFile("Core/Release/out.txt");
    return t_answer::gen("200;raw;win",IO.mem);
  }
};

class TShellCommand{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TShellCommand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDVAR(1,TAutoPtr<IShellCommand>,app,DEF,$,$)\
ADDEND()
//=====+>>>>>TShellCommand
#include "QapGenStruct.inl"
//<<<<<+=====TShellCommand
public:
  string use(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
  {
    if(!app)return "[TShellCommand::use]: !app => false";
    auto*p=app.get();
    return p->eval(Env,ShellEnv,Args);
  }
};

#include "templ_parser.inl"

extern string test2013_func(IEnvRTTI&Env,const string&param);

class TShellCommands{
public:
#define DEF_PRO_NESTED(F)F(ls)F(def)F(mkpath)F(sum)F(addmsg)F(cat)F(typelist)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TShellCommands)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TShellCommands
#include "QapGenStruct.inl"
//<<<<<+=====TShellCommands
public:
  class ls:public IShellCommand{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ls)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>ls
  #include "QapGenStruct.inl"
  //<<<<<+=====ls
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      if(Args.size()<2)return "[ls::eval]: params.size()<2 => true";
      string path=Args[1];
      auto&root=ShellEnv.root;
      auto ret=root.try_get_way(path);
      if(!ret.first)return "[ls:eval]: !ret.first => true";
      auto&node=root.traverse(ret.second);
      auto arr=node.get_all_path();
      return join(arr,"\n");
    }
  };
  class mkpath:public IShellCommand{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(mkpath)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>mkpath
  #include "QapGenStruct.inl"
  //<<<<<+=====mkpath
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      if(Args.size()<2)return "[mkpath::eval]: params.size()<2 => false";
      string path=Args[1];
      auto&root=ShellEnv.root;
      root.get(path);
      return "ok";
    }
  };
  class def:public IShellCommand{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(def)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>def
  #include "QapGenStruct.inl"
  //<<<<<+=====def
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      return "defecho "+join(Args," ");
    }
  };
  class sum:public IShellCommand{
  public:
  #define DEF_PRO_NESTED(F)F(Impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(sum)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>sum
  #include "QapGenStruct.inl"
  //<<<<<+=====sum
  public:
    class Impl{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Impl)OWNER(sum)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,a,SET,0,$)\
    ADDVAR(1,int,b,SET,0,$)\
    ADDEND()
    //=====+>>>>>Impl
    #include "QapGenStruct.inl"
    //<<<<<+=====Impl
    public:
      string eval(IEnvRTTI&Env,TShellEnv&ShellEnv)
      {
        return IToS(a+b);
      }
    };
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      Impl tmp;
      auto c=Args.size();
      if(c>1)tmp.a=SToI(Args[1]);
      if(c>2)tmp.b=SToI(Args[2]);
      return tmp.eval(Env,ShellEnv);
    }
  };
  class addmsg:public IShellCommand{
  public:
  #define DEF_PRO_NESTED(F)F(Impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(addmsg)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>addmsg
  #include "QapGenStruct.inl"
  //<<<<<+=====addmsg
  public:
    class Impl{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Impl)OWNER(addmsg)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,path,SET,"/",$)\
    ADDVAR(1,string,msg,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Impl
    #include "QapGenStruct.inl"
    //<<<<<+=====Impl
    public:
      string eval(IEnvRTTI&Env,TShellEnv&ShellEnv)
      {
        auto&root=ShellEnv.root;
        auto ret=root.try_get_way(path);
        if(!ret.first)return "[addmsg::Impl::eval]: !ret.first => true";
        auto&node=root.traverse(ret.second);
        node.addmsg(msg);
        return "ok:["+cur_date_str()+"]";
      }
    };
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      Impl tmp;
      auto c=Args.size();
      if(c>1)tmp.path=Args[1];
      if(c>2)tmp.msg=Args[2];
      return tmp.eval(Env,ShellEnv);
    }
  };
  class cat:public IShellCommand{
  public:
  #define DEF_PRO_NESTED(F)F(Impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(cat)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>cat
  #include "QapGenStruct.inl"
  //<<<<<+=====cat
  public:
    class Impl{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Impl)OWNER(cat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,path,SET,"/",$)\
    ADDEND()
    //=====+>>>>>Impl
    #include "QapGenStruct.inl"
    //<<<<<+=====Impl
    public:
      string eval(IEnvRTTI&Env,TShellEnv&ShellEnv)
      {
        auto&root=ShellEnv.root;
        auto ret=root.try_get_way(path);
        if(!ret.first)return "[cat::Impl::eval]: !ret.first => true";
        auto&node=root.traverse(ret.second);
        vector<string> lines;
        auto&arr=node.messages;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          CppString cpp=ex.message;
          lines.push_back("{\"time\":\""+ex.time+"\",\"message\":\""+cpp.data+"\"}");
        }
        return "["+join(lines,",")+"]";
      }
    };
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      Impl tmp;
      auto c=Args.size();
      if(c>1)tmp.path=Args[1];
      return tmp.eval(Env,ShellEnv);
    }
  };
  class typelist:public IShellCommand{
  public:
  #define DEF_PRO_NESTED(F)F(Impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(typelist)PARENT(IShellCommand)OWNER(TShellCommands)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>typelist
  #include "QapGenStruct.inl"
  //<<<<<+=====typelist
  public:
    class Impl{
    public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Impl)OWNER(typelist)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,param,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Impl
    #include "QapGenStruct.inl"
    //<<<<<+=====Impl
    public:
      string eval(IEnvRTTI&Env,TShellEnv&ShellEnv)
      {
        return test2013_func(Env,param);
      }
    };
  public:
    string eval(IEnvRTTI&Env,TShellEnv&ShellEnv,vector<string>&Args)
    {
      Impl tmp;
      auto c=Args.size();
      if(c>1)tmp.param=Args[1];
      return tmp.eval(Env,ShellEnv);
    }
  };
};

class T20131024_Shell :public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131024_Shell)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TShellCommand>,commands,DEF,$,$)\
ADDVAR(1,TShellCommand,defcmd,DEF,$,$)\
ADDVAR(2,TShellEnv,shellenv,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131024_Shell
#include "QapGenStruct.inl"
//<<<<<+=====T20131024_Shell
public:
  TShellCommand&find_func(const string&name){
    auto&arr=commands;
    for(int i=0;i<arr.size();i++){
      if(arr[i].name==name){
        return arr[i];
      }
    }
    return defcmd;
  }
  string call_ex(IEnvRTTI&Env,const string&cmd,vector<string>&arr){
    vector<string> out;
    out.push_back(cmd);
    for(int i=0;i<arr.size();i++){
      out.push_back(arr[i]);
    }
    return call(Env,out);
  }
  string call(IEnvRTTI&Env,vector<string>&arr){
    if(arr.empty())return "app not found";
    string func_name=arr[0];
    return find_func(func_name).use(Env,shellenv,arr);
  }
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    const auto&webpath=request.webpath;
    const auto&content=request.content;
    vector<string> out;
    if(webpath=="/sh?eval"){
      string data=HttpTool::get(content,"data");
      data=HttpTool::HexStrToWin1251_20131110(data);
      auto lines=split(data,"\n");
      for(int i=0;i<lines.size();i++){
        auto&line=lines[i];
        t_line line_obj;
        bool ok=load_obj(Env,line_obj,line);
        if(!ok)return t_answer::gen("200;raw;u8",HttpTool::Win1251ToHexStr_20131110("load_obj["+IToS(i)+"]- failed."));
        string cmd=line_obj.cmd.get();
        auto arr=line_obj.get_raw_params(Env);
        //auto arr=split(line," ");
        out.push_back(call_ex(Env,cmd,arr));
      }
      string retval=join(out,"\n");
      retval=HttpTool::Win1251ToHexStr_20131110(retval);
      return t_answer::gen("200;raw;u8",retval);
    }
    if(webpath=="/sh?html"){
      CrutchIO IO;
      IO.LoadFile("request.html");
      return t_answer::gen("200;html;win",IO.mem);
    }
    return toProto(Env,*this);
  }
  TShellCommand&addcmd(const string&name){
    commands.push_back(TShellCommand());
    auto&back=commands.back();
    back.name=name;
    return back;
  }
  void init(IEnvRTTI&Env)
  {
    defcmd.name="def";
    defcmd.app.build<TShellCommands::def>(Env);
    auto*pIShellCommand=Sys$$<IShellCommand>::GetRTTI(Env);
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=TTypeStruct::UberCast(ex.Type.get());
      if(!pType)continue;
      TType*pSubType=TTypeStruct::UberCast(pType->SubType.get());
      if(!pSubType)continue;
      if(pSubType!=pIShellCommand)continue;
      auto&back=addcmd(pType->Info.Name);
      back.app.Product.pType=pType;
      back.app.Product.Init();
    }
  }
};

class T20131027_Lexer:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131027_Lexer)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,data,DEF,$,$)\
ADDVAR(1,t_target,target,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131027_Lexer
#include "QapGenStruct.inl"
//<<<<<+=====T20131027_Lexer
public:
  static string move_block(const string&source,const string&sep){
    //string tmp=moveleft(source);
    auto arr=split(source,"\n");
    if(arr.empty())return source;
    return sep+join(arr,"\n"+sep);
  }
  static vector<string> get_parent_list(const vector<t_target_item::t_out>&arr)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.parent.empty())continue;
      bool flag=false;
      for(int j=0;j<out.size();j++)flag=flag||(ex.parent==out[j]);
      if(flag)continue;
      out.push_back(ex.parent);
    }
    return out;
  }
  static vector<string> get_child_list(const vector<t_target_item::t_out>&arr,const string&parent)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      if(arr[i].parent==parent){
        out.push_back(arr[i].name);
      }
    }
    return out;
  }
  static vector<string> get_nested_list(const vector<t_struct_body::t_target_item_out>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      out.push_back(ex.name);
    }
    return out;
  }
  static string get_nested_def(const vector<string>&arr){
    if(arr.empty())return "";
    vector<string> out;
    string line;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      line+="F("+ex+")";
      if(line.size()<80)continue;
      out.push_back(std::move(line));
    }
    if(!line.empty())out.push_back(std::move(line));
    return "#define DEF_PRO_NESTED(F)"+join(out,"\\\n")+"\n";
  }
  static string make_head(
    IEnvRTTI&Env,
    const vector<t_struct_body::t_target_item_out>&arr,
    const string&name,
    const string&parent,
    const string&owner,
    const vector<string>&nested_list
  ){
    string out;
    string parent_part=!parent.empty()?":public "+parent:"";
    string parent_info=!parent.empty()?"PARENT("+parent+")":"";
    string owner_info=!owner.empty()?"OWNER("+owner+")":"";
    string target_code=get_target_code(Env,arr,name);
    out+="class "+name+parent_part+"{\n";
    out+=target_code.empty()?"":"public:\n"+move_block(target_code,"  ")+"\n";
    out+=get_nested_def(nested_list);
    out+="#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)";
    out+="NAME("+name+")"+parent_info+owner_info+"\n";
    //out+="#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\\\n";
    return out;
  }
  static string class_to_code(IEnvRTTI&Env,const t_templ_sys&templ,const t_target_item::t_out&ex,const string&owner)
  {
    auto nested_list=get_nested_list(ex.out.nested);
    string out=make_head(Env,ex.out.nested,ex.name,ex.parent,owner,nested_list);
    t_templ_sys::t_inp inp;
    inp.add("NAME",ex.name);
    inp.add("PARENT",ex.parent);
    inp.add("OWNER",owner);
    inp.add("PROVARS",ex.out.provars);
    inp.add("PROCMDS",ex.out.procmds);
    inp.add("CPPCODE","\n"+ex.out.cppcode);
    out+=templ.eval(inp);
    return out;
  }
  static string iclass_to_code(IEnvRTTI&Env,const t_templ_sys&templ,const string&name,const vector<string>&arr,const string&owner)
  {
    string list;
    for(int i=0;i<arr.size();i++)list+="      F("+arr[i]+");\n";
    t_templ_sys::t_inp inp;
    inp.add("NAME",name);
    inp.add("LIST",list);
    inp.add("CPPCODE","\n");
    const vector<t_struct_body::t_target_item_out> no_arr;
    vector<string> no_nested;
    string out=make_head(Env,no_arr,name,"",owner,no_nested);
    out+=templ.eval(inp);
    return out;
  }
  static string load_string_from_file(const string&fn)
  {
    CrutchIO IO;
    IO.LoadFile(fn);
    return IO.mem;
  }
  static string get_target_code(IEnvRTTI&Env,const vector<t_target_item::t_out>&arr,const string&owner)
  {
    string class_body=load_string_from_file("class_body.inl");
    string iclass_body=load_string_from_file("iclass_body.inl");
    t_templ_sys templ_class_body;
    t_templ_sys templ_iclass_body;
    {bool ok=load_obj(Env,templ_class_body,class_body);QapAssert(ok);}
    {bool ok=load_obj(Env,templ_iclass_body,iclass_body);QapAssert(ok);}
    vector<string> out;
    auto parents=get_parent_list(arr);
    for(int i=0;i<parents.size();i++){
      auto&ex=parents[i];
      auto list=get_child_list(arr,ex);
      string tmp=iclass_to_code(Env,templ_iclass_body,ex,list,owner);
      out.push_back(tmp);
    }
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      string tmp=class_to_code(Env,templ_class_body,ex,owner);
      out.push_back(tmp);
    }
    return join(out,"\n");
  }
  static string to80charperline(const string&mem){
    vector<string> out;
    bool stop=false;
    for(int pos=0;pos<mem.size();pos+=80){
      out.push_back(mem.substr(pos,80));
    }
    return join(out,"\n");
  }
public:
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    const auto&webpath=request.webpath;
    const auto&content=request.content;
    vector<string> out;
    if(webpath=="/lex?make_code"){
      if(target.arr.empty())return t_answer::gen("200;raw;u8","!target");
      auto arr=target.make_code();
      vector<string> listoftypes;
      {
        string line;
        for(int i=0;i<arr.size();i++){
          line+="F("+arr[i].name+")";
          if(line.size()>80){
            listoftypes.push_back(std::move(line));
            line.clear();
          }
        }
        if(!line.empty())listoftypes.push_back(std::move(line));
      }
      string result=(
        get_target_code(Env,arr,"")+"\n"
        "\n"
        "/*\n"
        "//list of types:\n"+
        join(listoftypes,"\n")+"\n"
        "//app:\n"
        "adler3d.github.io/test2013/\n"
        "//code:\n"
        "return decodeURIComponent(POST['data'].split(\"\\n\").join(\"\"));\n"
        "//data:\n"+
        to80charperline(HttpTool::urlencode(this->data))+"\n"+
        "*/"
      );
      return t_answer::gen("200;raw;u8",result);
    }
    if(webpath=="/lex?templ_check")
    {
      t_templ_sys tmp;
      QapClock clock[3];
      clock[0].Start();
      bool ok=load_obj(Env,tmp,load_string_from_file("iclass_body.inl"));
      clock[0].Stop();
      clock[1].Start();
      auto fullcode=tmp.get_code();
      clock[1].Stop();
      clock[2].Start();
      auto code=t_templ_sys::optimize(fullcode);
      clock[2].Stop();
      return t_answer::gen(
        "200;raw;u8",
        "//ok:"+BToS(ok)+" ["+cur_date_str()+"] [build:"+FToS(clock[0].MS())+"ms,gen:"+FToS(clock[1].MS())+"ms,optimize:"+FToS(clock[2].MS())+"ms]\n\n"+
        QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(code))
      );
    }
    if(webpath=="/lex?eval")
    {
      data=HttpTool::get(content,"data");
      string main=load_obj_ex(Env,target,data);
      return t_answer::gen("200;raw;u8",main);
    }
    if(webpath=="/lex?html"){
      CrutchIO IO;
      IO.LoadFile("lex.html");
      return t_answer::gen("200;html;win",IO.mem);
    }
    return toProto(Env,*this);
  }
};

class t_stat_dev{
public:
  class t_var{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
    ADDVAR(2,string,value,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_var
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var
  public:
  };
  class t_func_param{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_param)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_func_param
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func_param
  public:
  };
  class t_func{
  public:
    typedef t_simple_stat_lex::t_func_body t_func_body;
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
    ADDVAR(2,vector<t_func_param>,params,DEF,$,$)\
    ADDVAR(3,t_func_body,body,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_func
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func
  public:
  };
  class t_state{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_state)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,value,SET,'N',$)\
    ADDEND()
  //=====+>>>>>t_state
  #include "QapGenStruct.inl"
  //<<<<<+=====t_state
  public:
  };
  class t_expr_result{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_result)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,type,DEF,$,$)\
    ADDVAR(1,string,value,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_expr_result
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_result
  public:
    void set_string(const string&value){
      this->type="string";
      this->value=value;
    }
    void set(const string&type,const string&value){
      this->type=type;
      this->value=value;
    }
    void set(const t_var&var){
      this->type=var.type;
      this->value=var.value;
    }
    void set(const t_expr_result&res){
      this->type=res.type;
      this->value=res.value;
    }
    bool isString()const{return "string"==type;}
  };
  class t_context{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_context)OWNER(t_stat_dev)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<t_var>,vars,DEF,$,$)\
    ADDEND()
  //=====+>>>>>t_context
  #include "QapGenStruct.inl"
  //<<<<<+=====t_context
  public:
    int find(const string&name){
      for(int i=0;i<vars.size();i++){
        auto&ex=vars[i];
        if(ex.name==name)return i;
      }
      return -1;
    }
    t_var&unsafe_find_ref(const string&name){
      for(int i=0;i<vars.size();i++){
        auto&ex=vars[i];
        if(ex.name==name)return ex;
      }
      QapAssert(false);
      return *(t_var*)nullptr;
    }
    t_var*find_ptr(const string&name){
      for(int i=0;i<vars.size();i++){
        auto&ex=vars[i];
        if(ex.name==name)return &ex;
      }
      return nullptr;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(t_var)F(t_context)F(t_func_param)F(t_func)F(t_expr_result)F(t_state)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_stat_dev)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<t_context>,stack,DEF,$,$)\
ADDVAR(1,vector<t_func>,funcs,DEF,$,$)\
ADDVAR(2,t_expr_result,expr_buff,DEF,$,$)\
ADDVAR(3,t_state,state,DEF,$,$)\
ADDEND()
//=====+>>>>>t_stat_dev
#include "QapGenStruct.inl"
//<<<<<+=====t_stat_dev
public:
  void push(){
    stack.push_back(t_context());
  }
  void pop(){
    stack.pop_back();
  }
  t_context&back(){
    return stack.back();
  }
  bool isRet()const{
    return state.value=='R';
  }
  bool isCon()const{
    return state.value=='C';
  }
  bool isBre()const{
    return state.value=='B';
  }
public:
  struct t_find_retval{
    bool ok;
    int stack_id;
    int var_id;
  };
  t_find_retval find(const string&name){
    t_find_retval retval={false,-1,-1};
    for(int i=0;i<stack.size();i++){
      auto id=stack.size()-1-i;
      auto&ex=stack[id];
      auto ret=ex.find(name);
      if(ret<0)continue;
      retval.ok=true;
      retval.stack_id=id;
      retval.var_id=ret;
      return retval;
    }
    return retval;
  }
  t_var&unsafe_find_ref(const string&name){
    auto retval=find(name);
    QapAssert(retval.ok);
    return stack[retval.stack_id].vars[retval.var_id];
  }
  t_var*find_ptr(const string&name){
    auto retval=find(name);
    if(!retval.ok)return nullptr;
    return &stack[retval.stack_id].vars[retval.var_id];
  }
public:
  t_func&find_func(const string&name){
    auto&arr=funcs;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.name==name)return ex;
    }
    QapAssert(false);
    return *(t_func*)nullptr;
  }
public:
  void add_var(const string&type,const string&name,const string&value){
    t_var tmp;
    tmp.type=type;
    tmp.name=name;
    tmp.value=value;
    auto&back=stack.back();
    QapAssert(!back.find_ptr(name));
    back.vars.push_back(std::move(tmp));
  }
  void oper_setadd(const string&name,const string&value){
    unsafe_find_ref(name).value+=value;
  }
  void oper_set(const string&name,const string&value){
    unsafe_find_ref(name).value=value;
  }
  void ret(const t_expr_result&result){
    expr_buff.set(result);
    QapAssert(state.value=='N');
    state.value='R';
  }
  void con(){
    QapAssert(state.value=='N');
    state.value='C';
  }
  void bre(){
    QapAssert(state.value=='N');
    state.value='B';
  }
  t_func&add_func(const string&type,const string&name,vector<t_func_param>&params){
    funcs.push_back(t_func());
    auto&back=funcs.back();
    back.type=type;
    back.name=name;
    back.params=std::move(params);
    return back;
  }
};

class t_stat_visitor;

class t_expr_visitor:public t_simple_stat_lex::i_expr_visitor{
public:
  typedef t_expr_visitor SelfClass;
  typedef i_expr_visitor ParentClass;
public:
  t_stat_dev&dev;
  t_expr_visitor(t_stat_dev&dev):dev(dev){}
public:
  typedef t_stat_dev::t_expr_result t_expr_result;
  static t_expr_result&get_expr_value(t_stat_dev&dev,TAutoPtr<i_expr>&ref){
    t_expr_visitor V(dev);
    auto*ptr=ref.get();
    ptr->Use(V);
    auto&retval=dev.expr_buff;
    return retval;
  }
  static t_expr_result&get_expr_value(t_stat_dev&dev,TAutoPtr<t_simple_stat_lex::t_without_add::i_expr>&ref){
    t_expr_visitor V(dev);
    t_simple_stat_lex::t_without_add::t_expr_visitor<t_expr_visitor> WoaV(V);
    auto*ptr=ref.get();
    ptr->Use(WoaV);
    auto&retval=dev.expr_buff;
    return retval;
  }
public:
  void Do(t_string_expr*p){
    BinString bin=p->body.value;
    //string value=BinString::fullCppStr2RawStr(p->value);
    dev.expr_buff.set_string(bin.data);
  }
  void Do(t_var_expr*p){
    string name=p->name.get();
    auto&ref=dev.unsafe_find_ref(name);
    dev.expr_buff.set(ref);
  }
  void Do(t_block_expr*p){
    auto&value=get_expr_value(dev,p->body);
    dev.expr_buff=value;
  }
  void Do(t_add_expr*p){
    vector<t_expr_result> out;
    auto add=[&](TAutoPtr<t_simple_stat_lex::t_without_add::i_expr>&ref)->void{
      t_expr_result tmp;
      tmp.set(get_expr_value(dev,ref));
      out.push_back(std::move(tmp));
    };
    auto&arr=p->arr;
    QapAssert(arr.size()>=2);
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      add(ex.body);
    }
    QapAssert(out[0].isString());
    auto&type=out[0].type;
    vector<string> result;
    for(int i=0;i<out.size();i++){
      auto&ex=out[i];
      QapAssert(ex.type==type);
      result.push_back(ex.value);
    }
    string full=join(result,"");
    dev.expr_buff.set_string(full);
  }
public:
  typedef t_simple_stat_lex::t_call_params t_call_params;
  typedef t_simple_stat_lex::t_call_param t_call_param;
  typedef t_stat_dev::t_expr_result t_expr_result;
public:
  static vector<t_expr_result> get_params_values(t_stat_dev&dev,TAutoPtr<t_call_params>&pParams){
    vector<t_stat_dev::t_expr_result> out;
    if(!pParams)return out;
    auto&params=*pParams.get();
    if(params.arr.empty()){
      QapDebugMsg("way no tested");
      return out;
    }
    auto add=[&out,&dev](t_call_param&param)->void{
      QapAssert(param.body);
      auto&value=t_expr_visitor::get_expr_value(dev,param.body);
      t_expr_result tmp;
      tmp.set(value);
      out.push_back(std::move(tmp));
    };
    auto&arr=params.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      add(ex);
    }
    return out;
  }
public:
  template<int>
  static void weak_do(t_stat_dev&temp_dev,vector<t_expr_result>&values,const string&func){
    if(func=="__cur_date_str"){
      QapAssert(values.empty());
      t_expr_result tmp;
      tmp.set_string(cur_date_str());
      temp_dev.ret(tmp);
      return;
    }
    temp_dev.push();
    auto&func_ref=temp_dev.find_func(func);
    {
      auto&params=func_ref.params;
      QapAssert(params.size()==values.size());
      auto&arr=values;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&param=params[i];
        QapAssert(ex.type==param.type);
        temp_dev.add_var(param.type,param.name,ex.value);
      }
    }
    t_stat_visitor V(temp_dev);
    auto&arr=func_ref.body.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*ptr=ex.get();
      ptr->Use(V);
      if(temp_dev.isRet())return;
    }
    temp_dev.pop();
  }
  void Do(t_call_expr*p){
    auto values=get_params_values(dev,p->params);
    t_stat_dev temp_dev;
    temp_dev.push();
    std::swap(temp_dev.funcs,dev.funcs);
    auto func=p->func.get();
    weak_do<0>(temp_dev,values,func);
    std::swap(temp_dev.funcs,dev.funcs);
    QapAssert(temp_dev.isRet());
    auto&result=temp_dev.expr_buff;
    dev.expr_buff.set(result);
  }
public:
};

class t_stat_visitor:public t_simple_stat_lex::i_stat_visitor{
public:
  typedef t_stat_visitor SelfClass;
  typedef i_stat_visitor ParentClass;
public:
  typedef t_simple_stat_lex::i_expr i_expr;
public:
  t_stat_dev&dev;
  t_stat_visitor(t_stat_dev&dev):dev(dev){}
public:
  typedef t_stat_dev::t_expr_result t_expr_result;
  t_expr_result&get_expr_value(TAutoPtr<i_expr>&ref){
    return t_expr_visitor::get_expr_value(dev,ref);
  }
public:
  void Do(t_var_stat*p){
    auto&value=get_expr_value(p->value);
    auto type=p->type.get();
    auto name=p->name.get();
    QapAssert(value.isString());
    QapAssert(type==value.type);
    dev.add_var(type,name,value.value);
  }
  void Do(t_setadd_stat*p){
    auto&value=get_expr_value(p->value);
    QapAssert(value.isString());
    dev.oper_setadd(p->name.get(),value.value);
  }
  void Do(t_set_stat*p){
    auto&value=get_expr_value(p->value);
    QapAssert(value.isString());
    dev.oper_set(p->name.get(),value.value);
  }
  void Do(t_null_stat*p){}
  void Do(t_sep_stat*p){}
  void Do(t_block_stat*p){
    dev.push();
    auto&arr=p->body.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*ptr=ex.get();
      ptr->Use(*this);
      if(dev.isRet())return;
      if(dev.isCon()||dev.isBre()){
        break;
        return;
      }
    }
    dev.pop();
  }
  void Do(t_ret_stat*p){
    auto&value=get_expr_value(p->body);
    QapAssert(value.isString());
    dev.ret(value);
  }
  void Do(t_func_stat*p){
    vector<t_stat_dev::t_func_param> params;
    if(p->params){
      auto*obj=p->params.get();
      auto&arr=obj->arr;
      t_stat_dev::t_func_param tmp;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        tmp.type=ex.type.get();
        tmp.name=ex.name.get();
        params.push_back(std::move(tmp));
      }
    }
    auto&ref=dev.add_func(p->type.get(),p->name.get(),params);
    ref.body=std::move(p->body);
  }
  void Do(t_expr_stat*p){
    auto&value=get_expr_value(p->body);
    int gg=1;
  }
  void Do(t_break_stat*p){
    dev.bre();
    int gg=1;
  }
  void Do(t_continue_stat*p){
    dev.con();
    int gg=1;
  }
  void Do(t_for_stat*p){
    /*auto drop_char=[](const string&s,char c)->string{
      string out;
      for(int i=0;i<s.size();i++){auto&ex=s[i];if(ex!=c)out.push_back(ex);}
      return out;
    };*/
    dev.push();
    Do(&p->init);
    for(;;){
      t_expr_result bef;
      t_expr_result aft;
      bef.set(get_expr_value(p->cond.bef));
      aft.set(get_expr_value(p->cond.aft));
      QapAssert(bef.type=="string");
      QapAssert(aft.type=="string");
      int b=SToI(bef.value);
      int a=SToI(aft.value);
      bool flag=b<a;
      if(!flag)break;
      Do(&p->body);
      if(dev.isRet()){
        return;
      }
      if(dev.isCon()){
        auto&v=dev.state.value;
        QapAssert('C'==v);
        v='N';
      }
      if(dev.isBre()){
        auto&v=dev.state.value;
        QapAssert('B'==v);
        v='N';
        break;
      }
      auto&var=dev.unsafe_find_ref(p->next.body.value);
      QapAssert(var.type=="string");
      var.value=IToS(SToI(var.value)+1);
    }
    int gg=1;
    dev.pop();
  }
  void Do(t_if_stat*p){
    t_expr_result bef;
    t_expr_result aft;
    bef.set(get_expr_value(p->cond.bef));
    aft.set(get_expr_value(p->cond.aft));
    QapAssert(bef.type=="string");
    QapAssert(aft.type=="string");
    if(bef.value==aft.value){
      Do(&p->bef);
    }else if(p->aft){
      Do(&p->aft.get()->body);
    }
    //auto&value=get_expr_value(p->body);
    int gg=1;
  }
public:
};

extern string test20131204_chat_json(IEnvRTTI&Env,TVoidPtr::TRawPtr&ptr);

class T20131110_Chat:public T20130410_IWebPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20131110_Chat)PARENT(T20130410_IWebPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TShellCommand>,commands,DEF,$,$)\
ADDVAR(1,string,code,DEF,$,$)\
ADDVAR(2,t_simple_stat_lex::t_block_stat,block,DEF,$,$)\
ADDEND()
//=====+>>>>>T20131110_Chat
#include "QapGenStruct.inl"
//<<<<<+=====T20131110_Chat
public:
  t_answer do_show_request(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    T20131012_HttpRequest tmp;
    tmp.method=request.method;
    tmp.host=request.host;
    tmp.webpath=request.webpath;
    tmp.content=request.content;
    return toProto(Env,tmp);
  }
  t_answer do_html(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    CrutchIO IO;
    IO.LoadFile("chat.html");
    return t_answer::gen("200;html;win",IO.mem);
  }
  t_answer do_eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    t_stat_dev dev;
    t_stat_visitor V(dev);
    dev.stack.reserve(2048);
    dev.stack.push_back(t_stat_dev::t_context());
    block.Use(V);
    CppString cpp=dev.expr_buff.value;
    return t_answer::gen("200;raw;win","[{\"time\":\""+cur_date_str()+"\",\"message\":\""+cpp.data+"\"}]");
  }
  t_answer do_lex(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    CrutchIO IO;
    IO.LoadFile("chat_lex.html");
    return t_answer::gen("200;html;win",IO.mem);
  }
  t_answer do_lexem(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    return toProto(Env,this->block);
  }
  t_answer do_lexeval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    code=HttpTool::get(request.content,"code");
    string load_status=load_obj_ex(Env,block,code);
    return t_answer::gen("200;raw;u8",load_status);
  }
  t_answer do_json(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    TVoidPtr::TRawPtr ptr;
    ptr.set(Env,block);
    string result=test20131204_chat_json(Env,ptr);
    return t_answer::gen("200;raw;u8",result);
  }
  t_answer eval(IEnvRTTI&Env,const T20131012_HttpRequest&request)
  {
    auto&webpath=request.webpath;
    #define F(method)if(webpath=="/chat?"#method){return this->do_##method(Env,request);}
      F(show_request);F(html);F(eval);F(lex);F(lexem);F(lexeval);F(json);
    #undef F
    return toProto(Env,*this);
  }
  void init(IEnvRTTI&Env){}
};

//#include "main_2013_06_22.cpp"
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
        F(T20130410_TStaticWebPage)F(T20130410_TContentWithCounter)\
        F(T20130410_TArrayPage)F(TProgramHTTPEmptyServerV3)\
        F(T20130410_ProgramLoopV2)\
        F(T20130410_TCloseServerPage)\
        F(T20130410_ProgramLoopV2Starter)\
        F(T20131110_Chat)\
        F(T20130410_ProgramHttpRestarter)\
        F(T20131004_Smart)\
        F(T20131011_Gateway)\
        F(TGateway)\
        F(T20131012_HttpRequest)\
        F(T20131012_Eval)\
        F(T20131024_Shell)\
        F(TShellCommands)\
        F(T20131027_Lexer)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
      QapLexerRegAll(Env);
      RegAllMetaLex(Env);
      RegAllCppLex(Env);
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
        http->Port=80;
        http->AddPage<T20130410_TCloseServerPage>(Env,"/close")->Loop=loop;
        http->AddPage<T20130410_TContentWithCounter>(Env,"/");
        http->AddPage<T20131004_Smart>(Env,"/smart")->http=http;
        http->AddPage<T20131011_Gateway>(Env,"/gw");
        http->AddPage<T20131110_Chat>(Env,"/chat")->init(Env);
        http->AddPage<T20131012_Eval>(Env,"/eval");
        http->AddPage<T20131024_Shell>(Env,"/sh")->init(Env);
        http->AddPage<T20131027_Lexer>(Env,"/lex");
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
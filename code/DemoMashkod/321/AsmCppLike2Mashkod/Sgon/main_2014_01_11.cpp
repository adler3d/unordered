#include "StdAfx.h"
#include <utility>/*
#include "Gateway.h"
#include "Gateway.cpp"*/

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_01_11.h"
#else
//=====>>>>>main_2013_01_11
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
//#include "t_simple_stat_lex.inl"
//<<<<<=====main_2013_01_11
#endif //DEF_BUILD_MACRO//

void UberInfoBox(const string&caption,const string&text);

void test_2014_01_11(IEnvRTTI&Env)
{/*
  t_simple_stat_lex::t_var_stat ug;
  string code="bool falser=true;";
  string load_status=load_obj_ex(Env,ug,code);
  if(load_status.find("true")>16){
    int fail=1;
    QapDebugMsg(load_status);
  }
  UberInfoBox("Info","End");
  int gg=1;*/
}

void test_2014_01_12(IEnvRTTI&Env)
{/*
  t_oper_name_tool ug;
  string code="t_bool_set_int_less_int";
  string load_status=load_obj_ex(Env,ug,code);
  if(load_status.find("true")>16){
    int fail=1;
    QapDebugMsg(load_status);
  }
  UberInfoBox("Info",QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug)));
  int gg=1;*/
}

void test_2014_01_17(IEnvRTTI&Env)
{/*
  t_simple_stat_lex::t_lev14 ug;
  string code="\"100\"+\" \"+\"lol :)\"";
  string load_status=load_obj_ex(Env,ug,code);
  if(load_status.find("true")>16){
    int fail=1;
    QapDebugMsg(load_status);
  }
  UberInfoBox("Info",QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug)));
  int gg=1;*/
}

#include "Lexem\t_asm_machine.inl"

class t_asmcmd_visitor:public t_asm_machine::i_cmd_visitor{
public:
  class t_dev{
  public:
    vector<TAutoPtr<i_cmd>>&cmds;
    vector<int> inp;
    vector<int> mem;
    vector<int> stack;
    vector<int> out;
    int ip;
    bool ret;
  };
  t_dev&dev;
  t_asmcmd_visitor(t_dev&dev):dev(dev){}
public:
  static int SToI(const string&s){
    QapAssert(!s.empty())
    if(s[0]!='0')return ::SToI(s);
    for(int i=0;i<s.size();i++)if(s[i]!='0'){return ::SToI(s.substr(i));}
    return 0;
  }
public:
  void Jump(const string&to)
  {
    auto&arr=dev.cmds;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=t_mrk::UberCast(ex.get());
      if(!ptr)continue;
      if(ptr->name!=to)continue;
      dev.ip=i+1;
      return;
    }
    QapDebugMsg("WTF?");
  }
public:
  void Do(t_nop*p){}
  void Do(t_mrk*p){}
  void Do(t_ret*p){if(dev.stack.empty()){dev.ret=true;return;}dev.ip=dev.stack.back();dev.stack.pop_back();}
  void Do(t_call*p){dev.stack.push_back(dev.ip);Jump(p->to.id);}
  void Do(t_jmp*p){Jump(p->to.id);}
  void Do(t_jnz*p){if(dev.mem[p->cond.id])Jump(p->to.id);}
  void Do(t_jz*p){if(!dev.mem[p->cond.id])Jump(p->to.id);}
  void Do(t_inc*p){dev.mem[p->reg.id]++;}
  void Do(t_add*p){dev.mem[p->out.id]=dev.mem[p->a.id]+dev.mem[p->b.id];}
  void Do(t_sub*p){dev.mem[p->out.id]=dev.mem[p->a.id]-dev.mem[p->b.id];}
  void Do(t_mul*p){dev.mem[p->out.id]=dev.mem[p->a.id]*dev.mem[p->b.id];}
  void Do(t_div*p){dev.mem[p->out.id]=dev.mem[p->a.id]/dev.mem[p->b.id];}
  void Do(t_mod*p){dev.mem[p->out.id]=dev.mem[p->a.id]%dev.mem[p->b.id];}
  void Do(t_more*p){dev.mem[p->out.id]=dev.mem[p->a.id]>dev.mem[p->b.id];}
  void Do(t_less*p){dev.mem[p->out.id]=dev.mem[p->a.id]<dev.mem[p->b.id];}
  void Do(t_mov_reg_reg*p){
    auto&check=dev.mem[p->out.id];
    dev.mem[p->out.id]=dev.mem[p->inp.id];
    int gg=1;
  }
  void Do(t_mov_const*p){
    auto&check=dev.mem[p->out.id];
    dev.mem[p->out.id]=SToI(p->value.value);
    int gg=1;
  }
  void Do(t_mov_inp_const*p){
    auto&check=dev.mem[p->out.id];
    dev.mem[p->out.id]=dev.inp[SToI(p->inp.offset)];
    int gg=1;
  }
  void Do(t_mov_out_const*p){
    int reg=SToI(p->out.offset);
    auto&check=dev.mem[reg];
    dev.out[reg]=dev.mem[p->inp.id];
    int gg=1;
  }
  void Do(t_mov_inp_reg*p){
    auto&check=dev.mem[p->out.id];
    dev.mem[p->out.id]=dev.inp[dev.mem[p->inp.id]];
    int gg=1;
  }
  void Do(t_mov_out_reg*p){
    int id=dev.mem[p->out.id];
    auto&check=dev.out[id];
    dev.out[id]=dev.mem[p->inp.id];
    int gg=1;
  }
  void Do(t_movc_reg_reg*p){
    auto*pout=(char*)&dev.mem[p->out.id];
    int out_id=dev.mem[p->out_id.id]%sizeof(int);
    pout+=out_id;
    auto*pinp=(char*)&dev.mem[p->inp.id];
    int inp_id=dev.mem[p->inp_id.id]%sizeof(int);
    pinp+=inp_id;
    *pout=*pinp;
  }
  void Do(t_movc_const_const*p){
    auto*pout=(char*)&dev.mem[p->out.id];
    int out_id=SToI(p->out_id.value)%sizeof(int);
    pout+=out_id;
    auto*pinp=(char*)&dev.mem[p->inp.id];
    int inp_id=SToI(p->inp_id.value)%sizeof(int);
    pinp+=inp_id;
    *pout=*pinp;
  }
  void Do(t_movc_reg_const*p){
    auto*pout=(char*)&dev.mem[p->out.id];
    int out_id=dev.mem[p->out_id.id]%sizeof(int);
    pout+=out_id;
    auto*pinp=(char*)&dev.mem[p->inp.id];
    int inp_id=SToI(p->inp_id.value)%sizeof(int);
    pinp+=inp_id;
    *pout=*pinp;
  }
  void Do(t_movc_const_reg*p){
    auto*pout=(char*)&dev.mem[p->out.id];
    int out_id=SToI(p->out_id.value)%sizeof(int);
    pout+=out_id;
    auto*pinp=(char*)&dev.mem[p->inp.id];
    int inp_id=dev.mem[p->inp_id.id]%sizeof(int);
    pinp+=inp_id;
    *pout=*pinp;
  }
};

class t_asm_funcs{
public:
  class call_asm_bin:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(call_asm_bin)PARENT(i_sysfunc_with_rtti)OWNER(t_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDVAR(2,string,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>call_asm_bin
  #include "QapGenStruct.inl"
  //<<<<<+=====call_asm_bin
  public:
    static vector<int> load_inp(const string&inp){
      vector<int> out;
      if(inp.size()<4)return out;
      int size=(int&)inp[0];
      if(size<0||size>1024*1024*16)return out;
      if(size*sizeof(int)+sizeof(size)!=inp.size())return out;
      out.resize(size);
      for(int i=0;i<size;i++){
        out[i]=(int&)inp[sizeof(int)*(i+1)];
      }
      return out;
    }
    static string save_out(const vector<int>&inp){
      string out;
      if(inp.size()<4)return out;
      int size=(int&)inp[0];
      if(size<0||size>1024*1024*16)return out;
      if(size+sizeof(int)>inp.size())return out;
      out.resize(size);
      char*ptr=(char*)&inp[1];
      for(int i=0;i<size;i++){
        out[i]=ptr[i];
      }
      return out;
    }
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start();
      t_asm_machine ug;
      //string code=file_get_contents("asm_test.asm");
      string load_status=load_obj_ex(Env,ug,code);
      if(load_status.find("true")>16){
        int fail=1;
        QapDebugMsg(load_status);return;
      }
      QapDebugMsg("loadtime = "+FToS(clock.MS()*1000.0));
      //out=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug));
      t_asmcmd_visitor::t_dev dev={ug.arr};
      t_asmcmd_visitor V(dev);
      dev.ip=0;
      dev.ret=false;
      dev.inp=load_inp(inp);
      dev.mem.resize(256);
      dev.out.resize(1024*512);
      real bef_run=clock.MS();
      for(int i=0;!dev.ret;i++){
        auto*ptr=dev.cmds[dev.ip].get();
        dev.ip++;
        ptr->Use(V);
      }
      QapDebugMsg("runtime = "+FToS((clock.MS()-bef_run)*1000.0));
      out=save_out(dev.out);
      int gg=1;
    }
  };
  class call_asm_test:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(call_asm_test)PARENT(i_sysfunc_with_rtti)OWNER(t_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDVAR(2,string,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>call_asm_test
  #include "QapGenStruct.inl"
  //<<<<<+=====call_asm_test
  public:
    static vector<int> load_inp(const string&inp){
      auto arr=split(inp," ");
      vector<int> out;
      for(int i=0;i<arr.size();i++){
        out.push_back(SToI(arr[i]));
      }
      return out;
    }
    static string save_out(const vector<int>&inp){
      auto&arr=inp;
      vector<string> out;
      for(int i=0;i<arr.size();i++){
        out.push_back(IToS(arr[i]));
      }
      return join(out," ");
    }
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start();
      t_asm_machine ug;
      //string code=file_get_contents("asm_test.asm");
      string load_status=load_obj_ex(Env,ug,code);
      if(load_status.find("true")>16){
        int fail=1;
        QapDebugMsg(load_status);return;
      }
      QapDebugMsg("loadtime = "+FToS(clock.MS()*1000.0));
      //out=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug));
      t_asmcmd_visitor::t_dev dev={ug.arr};
      t_asmcmd_visitor V(dev);
      dev.ip=0;
      dev.ret=false;
      dev.inp=load_inp(inp);
      dev.mem.resize(256);
      dev.out.resize(1024);
      real bef_run=clock.MS();
      for(int i=0;!dev.ret;i++){
        auto*ptr=dev.cmds[dev.ip].get();
        dev.ip++;
        ptr->Use(V);
      }
      QapDebugMsg("runtime = "+FToS((clock.MS()-bef_run)*1000.0));
      out=save_out(dev.out);
      int gg=1;
    }
  };
  class parse_asm_test:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(parse_asm_test)PARENT(i_sysfunc_with_rtti)OWNER(t_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>parse_asm_test
  #include "QapGenStruct.inl"
  //<<<<<+=====parse_asm_test
  public:
    void exec(IEnvRTTI&Env)
    {
      t_asm_machine ug;
      //string code=file_get_contents("asm_test.asm");
      string load_status=load_obj_ex(Env,ug,code);
      if(load_status.find("true")>16){
        int fail=1;
        QapDebugMsg(load_status);return;
      }
      out=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug));
      int gg=1;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(call_asm_bin)F(parse_asm_test)F(call_asm_test)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_asm_funcs)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_asm_funcs
#include "QapGenStruct.inl"
//<<<<<+=====t_asm_funcs
public:
};

void test_2014_02_09(IEnvRTTI&Env)
{
  t_asm_funcs::call_asm_test act;
  act.code=file_get_contents("asm_test.asm");
  act.inp="4 1 2 3 4";
  act.exec(Env);
  UberInfoBox("act.out",act.out);
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
        F(TType)F(t_asm_funcs)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      //test_2014_02_09(Env);
    }
    ThisCompileUnit(){
      int i=0;
      i>>=1;
      i<<=1;
      int gg=1+i;   
    }
  };
  ThisCompileUnit ThisUnit;
}
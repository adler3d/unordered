#include "StdAfx.h"

//#include "t_error_tool.inl"
//#include "QapLexer.inl"
//#include "t_config.inl"
//#include "t_poly_tool.inl"
//#include "templ_lexer_v02.inl"

extern void UberInfoBox(const string&caption,const string&text);

struct hhhh{
  int value;
  string abc;
};

static void vodf(IEnvRTTI&Env){
  Env.GetArr().push_back(EnvType());
  auto&et=Env.GetArr().back();
  auto*pDF=et.Factory.build<TDynStructFactory>(Env);
  TDynStructFactory&DF=*pDF;
  TTypeStruct&ts=*et.Type.build<TTypeStruct>(Env);
  DF.pType=&ts;
  ts.Factory=&DF;
  ts.Info.Name="noz";
  ts.Env=&Env;
  auto add=[&](TType*pType,const string&name){
    TTypeStruct::Member tmp;
    tmp.Mode="DEF";
    tmp.Name=name;
    tmp.Type=pType;
    tmp.Value="$";
    tmp.Offset=-1;
    tmp.Number=ts.Members.size();
    ts.Members.push_back(std::move(tmp));
  };
  add(Sys$$<int>::GetRTTI(Env),"value");
  add(Sys$$<string>::GetRTTI(Env),"abc");
  ts.ReCalcMembersOffset();
  ts.SelfTesting();
  TRTTIProduct p;
  p.pType=&ts;
  p.Init();
  auto*ptr=(hhhh*)p.Memory.ptr;
  ptr->abc="entry_point();";
  TQapRawObject ro(&ts,ptr);
  UberInfoBox("UserMsg",QapPublicUberFullSaverProtoToStr(Env,std::move(ro)));
  p.Free();
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
        F(TType)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      //return;
      //vodf(Env);return;
      Test20140128::exec(Env);
      //return;
      __if_exists(qap_eval_string)
      {
        t_qap_eval_string ref={Env};
        ref.code=file_get_contents("qapscript.h");
        bool ok=qap_eval_string(Env,ref);
        if(ref.load_status.find("true")>16){
          string out;
          out=(
            "--------------------\n"
            "load_time = "+FToS(ref.load_time)+"\n"
            "--------------------\n\n"+ref.load_status
          );
          UberInfoBox("load_status",out);
          return;
        }
        if(!ref.errcode.empty()){
          string out;
          out=(
            "--------------------\n"
            "load_time = "+FToS(ref.load_time)+" ms.\n"
            "retpath:\n"+ref.retpath+"\n"
            "--------------------\n\n"+ref.errcode
          );
          UberInfoBox("errcode",out);
          return;
        }
        string out=ref.out;
        out=(
          "--------------------\n"
          "load_time = "+FToS(ref.load_time)+" ms.\n"
          "exec_time = "+FToS(ref.exec_time)+" ms.\n"
          "full_time = "+FToS(ref.full_time)+" ms.\n"
          "--------------------\n\n"+out
        );
        if(out.size()>1024*128)
        {
          file_put_contents("big_out_file.h",out);return;
        }
        UberInfoBox("Output",out);
      }
      return;
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}
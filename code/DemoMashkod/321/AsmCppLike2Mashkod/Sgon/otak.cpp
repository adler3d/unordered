#include "ph.h"
#include "t_inl_file_lexem.h"
//#include "t_inl_file_lexem.inl"

void UberInfoBox(const string&caption,const string&text);
void InfoBox(const string&text){UberInfoBox("InfoBox",text);}

string fast_string_replace_impl(const string&src,const string&bef,const string&aft)
{
  string out;
  if(bef.empty())return src;
  if(src.empty())return out;
  out.resize(src.size()); auto os=out.size();
  auto*b=&src.front();
  auto*e=&src.back(); e++;
  auto f=bef[0]; auto bs=bef.size(); auto as=aft.size();
  auto o=&out[0]; auto*ob=&out[0];
  for(auto*p=b;p<e;p++)
  {
    if(*p==f)if(p+bs<=e)
    {
      bool fail=false;
      for(int i=1;i<bef.size();i++){
        if(p[i]!=bef[i]){fail=true;break;}
      }
      if(!fail)
      {
        p+=bs-1;
        if(o-ob+as>=os)
        {
          QapAssert(os<1024*1024*512);
          out.resize(as+os*2); os=out.size(); o=o-ob+&out[0]; ob=&out[0];
        }
        for(int i=0;i<as;i++)
        {
          *o=aft[i];
          o++;
        }
        continue;
      }
    }
    if(o-ob+1>=os)
    {
      QapAssert(os<1024*1024*512);
      out.resize(os*2); os=out.size(); o=o-ob+&out[0]; ob=&out[0];
    }
    *o=*p;
    o++;
  }
  out.resize(o-ob);
  return out;
}

string fast_string_replace(const string&src,const string&bef,const string&aft)
{
  auto fsrr=fast_string_replace_impl(src,bef,aft);
  //auto out=StrReplace(src,bef,aft);
  //QapAssert(out==fsrr);
  return fsrr;
}

static bool fsr_test()
{
  fast_string_replace("1001","0","..");
  fast_string_replace("","0","");
  fast_string_replace("0","0","");
  fast_string_replace("00","0","");
  fast_string_replace("000","0","");
  fast_string_replace("0000","0","");
  fast_string_replace("1","0","");
  fast_string_replace("11","0","");
  fast_string_replace("111","0","");
  fast_string_replace("1111","0","");
  fast_string_replace("1001","0","11");
  fast_string_replace("1001","0","1100");
  fast_string_replace("1001","0","11001");
  fast_string_replace("f","f","11001");
  fast_string_replace("1010","1","00000000");
  fast_string_replace("0000 0000"," ","-");
  fast_string_replace("0000 00001","00001","1");
  fast_string_replace("00001 0000","00001","1");
  fast_string_replace("100001 0000","00001","1");
  fast_string_replace("100001 0110","1100","1");
  fast_string_replace("1111","111","");
  fast_string_replace("1111","11","");
  fast_string_replace("1111","1","");
  fast_string_replace("1111","111","X");
  fast_string_replace("1111","11","X");
  fast_string_replace("1111","1","X");
  fast_string_replace("1111","111","1");
  fast_string_replace("1111","11","1");
  fast_string_replace("1111","1","1");
  fast_string_replace("1111","11111","");
  fast_string_replace("1111","11111","X");
  return true;
}
static bool fsr_test_result=fsr_test();

static const bool g_showInfoBox=file_get_contents("InfoBox.txt")!="0";
static const bool g_noqapfile=file_get_contents("noqapfile.txt")=="1";
static const bool g_showlog=file_get_contents("showlog.txt")!="0";
static string g_inpfn=file_get_contents("inpfn.txt");
static string g_outfn=file_get_contents("outfn.txt");

struct t_global_log{
  bool need_free=true;
  string data;
  ~t_global_log(){free();}
  void free(){if(!need_free)return;need_free=false;if(g_showlog)UberInfoBox("finish",data);file_put_contents("log.txt",data);}
};
static t_global_log g_static_global_log_var;
static string&g_log=g_static_global_log_var.data;

#define UberInfoBox(TITLE,MSG)if(g_showInfoBox){InfoBox(MSG);}else{g_log+="\n\n\n\n"+string(TITLE)+"\n"+string(MSG);}

#include "conv_codestylesort.inl"
#include "ubersepcutter.inl"

#undef UberInfoBox

#define InfoBox(MSG)if(g_showInfoBox){InfoBox(MSG);}else{g_log+="\n\n\n\n"+string(MSG);}
void xxx_remove_comments(IEnvRTTI&Env)
{
  if(g_inpfn.empty())g_inpfn="..\\Sgon\\trollex.i";
  auto d=file_get_contents(g_inpfn);
  {
    QapClock clock;
    clock.Start();
    d=fast_string_replace(d,"\r\n","\n");
    clock.Stop();
    InfoBox("fast_string_replace time:"+FToS(clock.MS())+"ms");
  }
  {
    QapClock clock;
    clock.Start();
    t_inl_file tmp; t_load_obj_result res; bool from_file=false;
    if(!g_noqapfile)if(file_get_contents("trollex.qap").size()>0){
      bool ok=QapPublicUberFullLoaderBin(Env,QapRawUberObject(tmp),"trollex.qap");
      res.msg=BToS(ok)+"\nfile_size = "+IToS(file_get_contents("trollex.qap").size());
      from_file=true;
    }
    if(!from_file){
      res=load_obj_full(Env,tmp,d);
    }
    clock.Stop();
    int gg=1;
    InfoBox("time:"+FToS(clock.MS())+"ms\n"+res.msg);
    if(!g_noqapfile)if(!from_file)
    {
      bool ok=QapPublicUberFullSaverBin(Env,QapRawUberObject(tmp),"trollex.qap");
      QapAssert(ok);
    }
    TUberSepCutterVisitor::TBranch dev;
    TUberSepCutterVisitor V(dev);
    TRawPtr ptr(Env,tmp);
    dev.top.pType=ptr.pType;
    dev.top.pValue=ptr.pValue;
    ptr.pType->Use(V);
    string tmp_out;
    auto ok=save_obj(Env,tmp,tmp_out);
    QapAssert(ok);
    if(g_outfn.empty())g_outfn="trollex.out.hpp";
    file_put_contents(g_outfn,tmp_out);
  }
  /*
  d=fast_string_replace(d,"\r\n","\n");
  d=fast_string_replace(d,"\r","");
  auto arr=split(d,"\n");
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int skip=0;
      for(int j=0;j<ex.size();j++)if(ex[j]!=' ')skip++;
      if(skip)continue;
      ex="";
    }
    int dest=0;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.empty())continue;
      if(dest!=i)arr[dest]=ex;
      dest++;
    }
    arr.resize(dest);
    d=join(arr,"\n");
  }
  file_put_contents("trollex.i",d);*/
  InfoBox("finish!");
}

void xxx_empty_unit_test_old(IEnvRTTI&Env)
{
  if(file_get_contents("remove_comments.txt")=="1"){xxx_remove_comments(Env);return;}
  //InfoBox("ph is cool!");TerminateProcess(GetCurrentProcess(),0);
  if(g_inpfn.empty())g_inpfn="../lex_gen/inl_parser_test.h";
  auto content=file_get_contents(g_inpfn);
  //auto content=file_get_contents(1?"../lex_gen/inl_parser_test.h":"../Macro/all.h");
  auto code=StrReplace(content,"\r","\n");
  //auto test_out=split(code,"\n//out\n")[1];
  //code=split(code,"\n//out\n")[0];
  QapClock clock;
  clock.Start();
  t_inl_file tmp; t_load_obj_result res; bool from_file=false;
  if(!g_noqapfile)if(file_get_contents("code.qap").size()>0){
    bool ok=QapPublicUberFullLoaderBin(Env,QapRawUberObject(tmp),"code.qap");
    res.msg=BToS(ok)+"\nfile_size = "+IToS(file_get_contents("code.qap").size());
    from_file=true;
  }
  if(!from_file)
  {
    res=load_obj_full(Env,tmp,code);
  }
  clock.Stop();
  int gg=1;
  InfoBox("time:"+FToS(clock.MS())+"ms\n"+res.msg);
  if(!g_noqapfile)if(!from_file)
  {
    bool ok=QapPublicUberFullSaverBin(Env,QapRawUberObject(tmp),"code.qap");
    QapAssert(ok);
  }
  {
    vector<string> out;
    t_hpp_to_cpp_conv_tool tool(Env,out);
    tool.first_pass(tmp.arr);
    tool.grab_all_class_name_form_tree(tmp.arr,"");
    string tree;
    QapAssert(save_obj(Env,tmp,tree));
    if(g_outfn.empty())g_outfn="out";
    auto out_hpp=tree;
    auto out_cpp="#include \"ph.h\"\n#include \""+g_outfn+".h\"\n\n"+join(out,"\n");
    auto msg=out_hpp+"\n//impl\n"+out_cpp;
    auto fnwoext=ChangeFileExt(g_outfn,"");
    if(fnwoext==g_outfn){
      file_put_contents(fnwoext+".cpp",out_cpp);
      file_put_contents(fnwoext+".hpp",out_hpp);
    }else{
      file_put_contents(g_outfn,msg);
    }
    InfoBox(msg);
  }
  //InfoBox(QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(tmp)));
  //TerminateProcess(GetCurrentProcess(),0);
  if(!res.ok)return;
}

#include "main2.inl"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //StartMemLeakTest();
  //BlurTest();return 0;
  auto&comp_unit_man=TCompileUnitMan::get_man();
  string unit_name=comp_unit_man.arr[0]->get_filename();
  static GlobalEnv gEnv(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TStdAllocator MA;
  {
    TEnvRTTI Env;
    Env.Arr.reserve(2048);
    Env.Alloc=&MA;
    Env.OwnerEnv=&Env;
    //TCompileUnitMan::reg_and_run_all(Env);
    xxx_empty_unit_test_old(Env);g_static_global_log_var.free();
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}
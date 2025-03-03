{
  if(false)
  {
    char c;
    string ttt(void s)
    {
      int aga=1;
      aga=3;
      char c;
      __UserMsg("Oh no!!!");
      return "";
    }
    ttt(c.fromBlob("e"));
    __UserMsg("ORLY?");
    void test;
    void foo(void omnomnom){}
    foo(test);
  }
  if(true)
  {
    array{array{array{vector{int},1},1},1} a3;
    vector{vec2i} arr;
    //arr.pop_back();
    //arr.resize(+0);
    //__UserMsg("arr.size = "+__IToS(arr.size()));
    //arr.resize(-1);
    struct vec2i{int x;int y;}; vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;}
    string join(vector{string} arr,string glue){
      bool bool(int i){return i!=0;}
      string out;
      for(int i=0;i<arr.size();i++){
        if(bool(i))out+=glue;
        out+=arr[i];
      }
      return out;
    }
    string IToS(int v){return __IToS(v);}
    string toStr(vector{vec2i} arr){
      vector{string} out;
      for(int i=0;i<arr.size();i++){
        auto ex=arr[i];
        out.push_back("["+IToS(ex.x)+","+IToS(ex.y)+"]");
      }
      return "["+join(out,",")+"]";
    }
    for(int i=0;i<5;i++){
      int x=i*2;
      int y=i*8+1;
      arr.push_back(vec2i(x,y));
    }
    //arr+=vec2i(10,10);
    //arr=arr+vec2i(10,10);
    arr.pop_back();
    //arr.resize(1);
    arr[0]=vec2i(5,5);
    __UserMsg(toStr(arr)+"\n"+arr.toProto());
    return "";
  }
  if(false)
  {
    template{class TYPE}TYPE max(TYPE a,TYPE b){if(a<b)return b;return a;}
    template{class ABC}struct t_bar{ABC value;}
    template{class TYPE}void foo(TYPE A){}
    //
    {
    }
    int a=10;
    int b=20;
    {array{int,10} arr;a=arr.size();}
    //auto c=max(a,b);
    //auto d=max{int}(a,b);
    string r=__IToS(a);
    __UserMsg("value: "+r);
    return "";
  }
  if(false)
  {
    //__UserMsg(__NetDownload("habrahabr.ru","/posts/top/daily/"));return "";
    //string a=__get_internal_funcs_list();__UserMsg(a);return "";
    /*void filter(string s){
      auto c=__StrLen(s);
      for(int i=0;i<c;i++){
        
      }
    }*/
    //string s="123";__UserMsg(__IToS(s.size()));return "";
    void f_img(string a,string b){__UserMsg(__to80cpl(__urlencode(__NetDownload(a,b))));}
    void f(string a,string b){__UserMsg(__NetDownload(a,b));}
    //f("habrahabr.ru","/posts/top/daily/");
    f("system.zz.mu","/out_gd.php");
    return "";
    auto bef=__microtime();
    for(int i=0;i<4;i++){
      //auto out=
      __NetDownload("localhost","/");
    }
    auto aft=__microtime();
    string msg="/add?cpc="+__FToS((aft-bef)/4.0);
    __NetDownload("polymorph.zz.mu",msg);
    //__UserMsg("cost = "+__FToS((aft-bef)/30.0));
    //__UserMsg("end");
    return "";
  }
  if(false)
  {
    int foo(int x,int y){
      int z=x+y;
      int u=z*z;
      for(int i=0;i<10;i++){
        u++;
        z*=2;
        z++;
        z%=128;
      }
      return (u+z)*(y%4);
    }
    real bef_time=__microtime();
    int result=foo(5,7);
    real aft_time=__microtime();
    string msg=__IToS(result);
    __UserMsg("time = "+__FToS(0.001*(aft_time-bef_time))+" ms.\n\n"+msg);
    return "";
  }
  if(false)
  {
    //string content=__file_get_contents("meta_lexer.mod.inl");
    //string content=__file_get_contents("../Sgon/meta_lexer.inl");
    //string content=__file_get_contents("../Sgon/t_simple_stat_lex.inl");
    string content=__file_get_contents("easy_ssl.h");
    content=__StrReplace(content,"\r","");
    real bef_time=__microtime();
    //string msg=__parse_cpp_file_with_lex(content);
    string msg=__conv_cpp_to_lex(content);
    real aft_time=__microtime();
    //msg=__StrReplace(msg,"t_file_with_lex::","");
    //msg=__ScanParamData("\nTHardPtr<TType>(Sys$$<t_file_with_lex>::GetRTTI())\n",msg,"\n}\n",0);
    __UserMsg("time = "+__FToS(0.001*(aft_time-bef_time))+" ms.\n\n"+msg);return "";
  }
//D:\Adler\My Doc\CodeGame\Predictable\Source\Sgon\templ_lexer_v03.inl
//D:\Adler\My Doc\CodeGame\Predictable\Source\Sgon\Lexem\i_code_with_sep.inl
  if(false)
  {
    string gen_lexem(string source){
      string inp=__StrReplace(source,"\r","");
      real bef_time=__microtime();
      string msg=__gen_lexem_v01(inp);
      real aft_time=__microtime();
      return "//time = "+__FToS(0.001*(aft_time-bef_time))+" ms.\n"+msg;
    }
    string genlexem_withmsg(string fn){
      __UserMsg(gen_lexem(__file_get_contents(fn))); return "";
    }
    genlexem_withmsg("t_simple_stat_lex(source).h"); return "";
    //genlexem_withmsg("t_template_stat_lex_dev.inl"); return "";
    //genlexem_withmsg("ADDVAR_PARSER.inl");return "";
    if(false)
    {
      string s;
      s+="t_name_code_with_sep=>i_code_with_sep{t_name_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}}\n";
      s+="t_num_code_with_sep=>i_code_with_sep{t_num_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}}\n";
      s+="t_str_code_with_sep=>i_code_with_sep{t_str_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}}\n";
      s+="t_char_code_with_sep=>i_code_with_sep{t_char_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}\n}";
      s+="t_sign_code_with_sep=>i_code_with_sep{t_sign_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}\n}";
      s+="t_soft_brackets_code_with_sep=>i_code_with_sep{t_soft_brackets_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}}\n";
      s+="t_hard_brackets_code_with_sep=>i_code_with_sep{t_hard_brackets_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}}\n";
      s+="t_curly_brackets_code_with_sep=>i_code_with_sep{t_curly_brackets_code body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}}";
      __UserMsg(gen_lexem(s));
    }
    //string e=__file_get_contents("..\\Sgon\\Lexem\\i_code_with_sep.inl");
    string e=__file_get_contents("ADDVAR_PARSER.inl");
    //__UserMsg(__IToS(__StrLen(e)));
    e=__StrReplace(e,"\r","");
    string code=__ScanParamData("//data:\n",e,"*/",0);__UserMsg("code = "+__IToS(__StrLen(code))+"\n\n"+code);
    code=__StrReplace(code,"\n","");
    string raw=__urldecode(code);
    __UserMsg(gen_lexem(raw));
    return "";
  }
  if(false)
  {
    //__UserMsg(__urlencode("<somthing is right!>"));
    //string code="t_foo{{go_const(\"t_foo\");}}";
    //auto fn="asm_lex_source.hpp";
    auto fn="t_target_lexem_source.inl";
    auto code=__file_get_contents(fn);
    real bef_time=__microtime();
    string msg=__gen_lexem_v01(code);
    real aft_time=__microtime();
    __UserMsg("time = "+__FToS(0.001*(aft_time-bef_time))+" ms.\n\n"+msg);return "";
  }
  if(false)
  {//return "";
    auto code=__file_get_contents("asm_test.asm");
    //auto input="7 1 2 3 4 5 1 1";
    //input="1000";
    string result=__call_asm_test(code,"1000");
    __UserMsg(result);return "";
    string proto=__parse_asm_test(code);
    __UserMsg(proto);
    string list=("t_mrk|t_ret|t_jmp|t_jnz|t_inc|t_add|t_less|t_mov_const|t_mov_inp_const|t_mov_out_const|t_mov_inp_reg|t_mov_out_reg");
    string s=__gen_visitor_v00("t_asm_machine","i_cmd",list);
    __UserMsg(s);
    //__UserMsg(__get_internal_stats());
    //__UserMsg(__parse_asm());
    //return "";
  }
  if(false)
  {
    string main(int w,int h)
    {
      string v="begin"+"\n";
      for(int y=0;y<h;y++)
      {
        v+="|"; int next_y=1+y;
        for(int x=0;x<w;x++)
        {
          string n=".";
          if(x==32){if(y<3){n=" ";}else{n="#";}}
          if(y==0){n="-";}
          if(next_y==h){n="-";}
          if(y==8){if(x<8){n=" ";}else{n="#";}}
          v+=n;
        }
        v+="|";
        if(next_y==h){continue;}
        v+="\n";
      }
      return v+"\nend";
    }
    real bef_time=__microtime();
    string out=main(64,16);
    real aft_time=__microtime();
    {
      string a=__get_internal_stats()+"\ntotal_time = "+__FToS(aft_time-bef_time)+"\n"+POST_TIME+"\n";
      __UserMsg(out+a);
      return "";
    }
    return "";
  }
  real bef_time=__microtime();
  t_circle operator=(t_circle out,t_circle inp){return inp;}
  struct t_circle{
    vec2i pos;
    int r;
  }
  t_line operator=(t_line out,t_line inp){return inp;}
  struct t_line{
    vec2i a;
    vec2i b;
  }
  t_ud operator=(t_ud out,t_ud inp){return inp;}
  struct t_ud{
    bool ldown;
    bool rdown;
    int cn;
    int ln;
    array{t_circle,2} circles;
    array{t_line,2} lines;
    real total_time;
  }
  struct t_inp{
    int tick;
    vec2i mpos;
    bool mbLeft;
    bool mbMiddle;
    bool mbRight;
    bool kbEsc;
    string ud;
  }
  t_inp inp;
  real inp_bef_time=__microtime();
  inp.fromBlob(POST_DATA);
  real inp_aft_time=__microtime();
  t_ud ud;
  if(__StrLen(inp.ud)>0){
    ud.fromBlob(inp.ud);
  }
  //
  vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;}
  vec2i vec2i(){vec2i tmp;return tmp;}
  vec2i operator=(vec2i out,vec2i inp){return inp;}
  struct vec2i{
    int x;
    int y;
  }
  //
  t_circle circle(vec2i pos,int r){t_circle tmp;tmp.pos=pos;tmp.r=r;return tmp;}
  t_line line(vec2i a,vec2i b){t_line tmp;tmp.a=a;tmp.b=b;return tmp;}
  //
  string arr2blob(array{t_circle,2} arr,int n){
    string out;for(int i=0;i<n;i++)out+=arr[i].toBlob();return out;
  }
  string arr2blob(array{t_line,2} arr,int n){//for(array{int,1} arr;;)break;
    string out;for(int i=0;i<n;i++)out+=arr[i].toBlob();return out;
  }
  int tick=inp.tick;
  if(inp.mbLeft&&!ud.ldown){
    ud.ldown=true;
    ud.circles[ud.cn]=circle(inp.mpos,10);
    ud.cn++;
  }
  if(!inp.mbLeft&&ud.ldown){ud.ldown=false;}
  if(inp.mbRight&&!ud.rdown){
    ud.rdown=true;
    ud.lines[ud.ln]=line(inp.mpos,inp.mpos);
    ud.ln++;
  }
  if(ud.rdown){ud.lines[ud.ln-1].b=inp.mpos;}
  if(!inp.mbRight&&ud.rdown){ud.rdown=false;}
  if(inp.kbEsc){
    return "";
  }
  t_circle mcirc=circle(inp.mpos,8);
  real t=__IToF(inp.tick);
  real g2rad=3.14/180.0;
  array{t_circle,5} arr;
  for(int i=0;i<5;i++){
    //t_circle ex;
    real mag=32.0;
    real offset=__IToF(i)*360.0/5.0;
    real ang=(t*5.0+offset)*g2rad;
    real x=__cos(ang)*mag;
    real y=__sin(ang)*mag;
    vec2i mpos=inp.mpos;
    if(ud.rdown){mpos=ud.lines[ud.ln-1].a;}
    arr[i]=circle(vec2i(__FToI(x)+mpos.x,__FToI(y)+mpos.y),4);
  }
  int cn=ud.cn+1+5;
  string c_out=   cn.toBlob()+arr2blob(ud.circles,ud.cn)+mcirc.toBlob()+arr.toBlob();
  string l_out=ud.ln.toBlob()+arr2blob(ud.lines,ud.ln);
  ud.total_time=ud.total_time+__microtime()-bef_time;
  if(false)
  {
    if(inp.tick==100){
      __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
      if(!inp.mbRight)return "";
    }
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  //
  //__UserMsg(__get_foo("int __FToI(real)"));
  if(inp.mbRight)
  {
    string a=__get_internal_stats()+"\ntotal_time = "+__FToS(ud.total_time)+"\n"+POST_TIME+"\n";
    string b="inp_time = "+__FToS(inp_aft_time-inp_bef_time)+"\n";
    __UserMsg(a+b);
    return "";
  }
  if(false){
    string out;
    int count=__get_internal_funcs_count();
    int maxlen;
    int max(int a,int b){if(a>b)return a;return b;}
    string pad(string s,int c){
      int n=c-__StrLen(s);
      string out;
      for(int i=0;i<n;i++)out+=" ";
      return s+out;
    }
    for(int i=0;i<count;i++)maxlen=max(maxlen,__StrLen(__get_internal_func_by_id(i)));
    for(int i=0;i<count;i++){
      auto func=__get_internal_func_by_id(i);
      out+=pad(func,maxlen)+"   =>   "+__get_foo(func)+"\n";
    }
    __UserMsg(out);
    //__UserMsg("list of internal functions:\n"+__get_internal_funcs_list());
    return "";
  }
  return out;
  /*void show(string blob){
    __UserMsg(__BlobToHex(blob));
  }*/
  //show(ud.cn.toBlob());
  //__UserMsg(__BlobToHex(out));

/*
old:
  total_time = 31880024.59
  avg = 318.80 ms.
old O2:
  total_time = 1481788.17
  avg = 14.82 ms.
new with debug:
  total_time = 25682798.05
  avg = 256.83 ms.
new without debug:
  total_time = 14698133.31
  avg = 146.98 ms.
new O2:
  total_time = 832309.08
  avg = 8.32 ms.
new Release:
  total_time = 3107167.14
  avg = 31.07 ms.
fin debug:
  total_time = 23617125.07
  avg = 236.17 ms.
fin no debug:
  total_time = 13593314.08
  avg = 135.93 ms.
fin release:
  total_time = 2919893.97
  avg = 29.20 ms.
fin O2:
  total_time = 759931.70
  avg = 7.60 ms.
max debug:
  total_time = 20622445.36
  avg = 206.22 ms.
max no debug:
  total_time = 12417895.08
  avg = 124.18 ms.
max release:
  total_time = 2622743.05
  avg = 26.23 ms.
max O2:
  total_time = 658728.15
  avg = 6.59 ms.
*/
}
{return "";
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
{
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
  inp.fromBlob(POST_DATA);
  t_ud ud;
  if(__StrLen(inp.ud)>0)ud.fromBlob(inp.ud);
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
  /*if(false)*/if(inp.tick==100){
    __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
    if(!inp.mbRight)return "";
  }
  string out=c_out+l_out+__SToBlob(ud.toBlob());
  return out;
}
}
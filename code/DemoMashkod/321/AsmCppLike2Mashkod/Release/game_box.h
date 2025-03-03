{
  vector{t_bullet} operator=(vector{t_bullet} out,vector{t_bullet} inp){return inp;}
  vector{t_button} operator=(vector{t_button} out,vector{t_button} inp){return inp;}
  real bef_time=__microtime();
  vec2d operator=(vec2d a,vec2d b){return b;}
  struct vec2d{
    real x;
    real y;
  }
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
  vec3c operator=(vec3c out,vec3c inp){return inp;}
  struct vec3c{
    char r;
    char g;
    char b;
  }
  t_trigon operator=(t_trigon out,t_trigon inp){return inp;}
  struct t_trigon{
    vec2i a;
    vec2i b;
    vec2i c;
  }
  t_rect operator=(t_rect out,t_rect inp){return inp;}
  struct t_rect{
    vec2i a;
    vec2i b;
  }
  t_pixel operator=(t_pixel out,t_pixel inp){return inp;}
  struct t_pixel{
    vec2i p;
    vec3c color;
  }
  t_image operator=(t_image out,t_image inp){return inp;}
  struct t_image{
    vec2i pos;
    int w;
    int h;
    vector{vec3c} arr;
  }
  t_pen operator=(t_pen out,t_pen inp){return inp;}
  struct t_pen{
    int w=1;
    vec3c color;
    t_out_dev dev;
  }
  t_brush operator=(t_brush out,t_brush inp){return inp;}
  struct t_brush{
    vec3c color;
    t_out_dev dev;
  }
  t_bullet operator=(t_bullet out,t_bullet inp){return inp;}
  struct t_bullet{
    vec2d p;
    vec2d v;
  }
  t_button update(t_button inp,vec2i mpos,bool mb){
    auto out=inp;
    out.hover=vec2d_mag(vec2d(out.pos-mpos))<real(out.r);
    out.now=false;
    if(!out.hover)out.down=false;
    if(out.hover&&(out.mb!=mb)){
      out.down=!out.down;
      out.now=true;
      if(out.down)out.counter++;
    }
    out.mb=mb;
    return out;
  }
  t_button operator=(t_button out,t_button inp){return inp;}
  struct t_button{
    vec2i pos;
    int r;
    int counter;
    bool mb;
    bool down;
    bool now;
    bool hover;
  }
  t_ud operator=(t_ud out,t_ud inp){return inp;}
  struct t_ud{
    vec2d p;
    vec2d v;
    int shottick;
    vector{t_bullet} bullets;
    vector{t_button} buttons;
    bool mode;
    real total_time;
  }
  //t_inp
  t_inp operator=(t_inp out,t_inp inp){return inp;}
  struct t_inp{
    int tick;
    vec2i mpos;
    bool mbLeft;
    bool mbMiddle;
    bool mbRight;
    bool kbEsc;
    bool kbLeft;
    bool kbRight;
    bool kbUp;
    bool kbDown;
    string ud;
  }
  t_out_dev operator=(t_out_dev out,t_out_dev inp){return inp;}
  struct t_out_dev{
    t_out_dev_pack pack;
    vector{int} arr;
  }
  t_out_dev_pack operator=(t_out_dev_pack out,t_out_dev_pack inp){return inp;}
  struct t_out_dev_pack{
    vector{t_circle} circles;
    vector{t_line} lines;
    vector{t_trigon} trigons;
    vector{t_rect} rects;
    vector{t_pixel} pixels;
    vector{t_image} images;
    vector{t_pen} pens;
    vector{t_brush} brushs;
  }
  t_out operator=(t_out out,t_out inp){return inp;}
  struct t_out{
    t_out_dev dev;
    string ud;
  }
  //-----|||||||||||||||-----//
  vec3c operator=(vec3c out,string hex){auto tmp=out;tmp.fromBlob(__HexToBlob(hex));return tmp;}
  //-----|||||||||||||||-----//
  t_out_dev operator+=(t_out_dev out,t_circle item){auto tmp=out;tmp.pack.circles.push_back(item);tmp.arr.push_back(0);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_line   item){auto tmp=out;tmp.pack.lines.push_back(item);tmp.arr.push_back(1);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_trigon item){auto tmp=out;tmp.pack.trigons.push_back(item);tmp.arr.push_back(2);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_rect   item){auto tmp=out;tmp.pack.rects.push_back(item);tmp.arr.push_back(3);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_pixel  item){auto tmp=out;tmp.pack.pixels.push_back(item);tmp.arr.push_back(4);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_image  item){auto tmp=out;tmp.pack.images.push_back(item);tmp.arr.push_back(5);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_pen    item){auto tmp=out;tmp.pack.pens.push_back(item);tmp.arr.push_back(6);return tmp;}
  t_out_dev operator+=(t_out_dev out,t_brush  item){auto tmp=out;tmp.pack.brushs.push_back(item);tmp.arr.push_back(7);return tmp;}
  //-----|||||||||||||||-----//
  t_out operator+=(t_out out,t_circle item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_line   item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_trigon item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_rect   item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_pixel  item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_image  item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_pen    item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_out operator+=(t_out out,t_brush  item){auto tmp=out;tmp.dev+=item;return tmp;}
  //-----|||||||||||||||-----//
  t_pen operator+=(t_pen out,t_circle item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_line   item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_trigon item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_rect   item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_pixel  item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_image  item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_pen    item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_pen operator+=(t_pen out,t_brush  item){auto tmp=out;tmp.dev+=item;return tmp;}
  //-----|||||||||||||||-----// 
  t_brush operator+=(t_brush out,t_circle item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_line   item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_trigon item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_rect   item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_pixel  item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_image  item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_pen    item){auto tmp=out;tmp.dev+=item;return tmp;}
  t_brush operator+=(t_brush out,t_brush  item){auto tmp=out;tmp.dev+=item;return tmp;}
  //-----BEGIN_OF_SCRIPT-----//
  t_inp inp;
  t_out out;
  real inp_bef_time=__microtime();
  inp.fromBlob(POST_DATA);
  real inp_aft_time=__microtime();
  //if(inp.kbEsc){return "";}
  t_ud ud;
  
  if(false)
  {
    string join(vector{string} arr,string needle){
      string out="";
      for(int i=0;i<arr.size();i++)if(i!=0){out+=needle+arr[i];}else{out+=arr[i];}
      return out;
    }
    string to80cpl(string mem){
      vector{string} out;
      bool stop=false;
      for(int pos=0;pos<mem.size();pos+=80){
        out.push_back(__StrSubStr(mem,pos,80));
      }
      return join(out,"\n");
    }
    struct t_userdata{
      string code;
      real total_time;
    };
    t_userdata ud;
    auto code=inp.ud;
    if(__StrLen(code)==0){
      code=__file_get_contents("gbox_asm.asm");
      code=__StrReplace(code,"\r","");
      //code=__gen_inl_smart_asm(code,"noused");
      if(false)
      {
        auto bef_time=__microtime();
        code=__build_smart_asm_hack(code);
        __UserMsg("build_smart_asm_hack.time : "+__FToS(__microtime()-bef_time));
      }
      //code=__conv_smart_asm_code_ast_to_str(code);
      //__UserMsg(to80cpl(__urlencode(code)));
      //__UserMsg(__conv_smart_asm_code_ast_toProto(code));
      ud.code=code;
      //__UserMsg(code);
    }else{
      ud.fromBlob(code);
      code=ud.code;
    }
    struct t_gbsasm_inp{
      int tick;
      vec2i pos;
    }
    t_gbsasm_inp gb_inp;
    gb_inp.tick=inp.tick;
    gb_inp.pos=inp.mpos;
    auto bef_time=__microtime();
    string s;
    int mode=0;
    if(__StrSubStr(code,0,4)=="app{")mode=2;
    if(mode==0){
      //41.89 ms.
      //24.96 ms.
      s=__run_gb_smart_asm(code,gb_inp.toBlob());
    }
    if(mode==1){
      //81.03 ms.
      s=__run_gb_smart_asm_code_ast(code,gb_inp.toBlob());
    }
    if(mode==2){
      //12.69 ms.
      s=__exec_gb_smart_asm_hack(code,gb_inp.toBlob());
    }
    if(mode==3){
      array{t_circle,128} operator=(array{t_circle,128} out,array{t_circle,128} inp){return inp;}
      //377.44 ms.
      //173.61 ms.
      vector{t_circle} arr;
      for(int i=0;i<127;i++){
        int x_offset=gb_inp.tick%16;
        int x=80+40*(i%16);
        if(x_offset<8){
          x+=x_offset;
        }else{
          x+=16-x_offset;
        }
        int y=500-40*(i/16);
        arr.push_back(circle(vec2i(x,y),8));
      }
      arr.push_back(circle(gb_inp.pos,16));
      s=arr.toBlob();
    }
    ud.total_time+=__microtime()-bef_time;
    //if(false)
    {
      string bgcolor="E1E1E1";
      auto brush=brush(bgcolor);
      auto pen=pen(1,bgcolor);
      pen+=rect(vec2i(0,0),vec2i(800,600));
      brush+=pen;
      bool fast=true;
      if(fast)
      {
        int count=0;count.fromBlob(__StrSubStr(s,0,4));
        brush.dev.pack.circles.fromBlob(__StrSubStr(s,0,4+count*3*4));
        vector{int} operator=(vector{int} out,vector{int} inp){return inp;}
        vector{int} arr;
        arr.resize(count+1);arr[0]=6;//for(int i=0;i<count;i++)arr[i]=0;
        brush.dev.arr=arr;
      }
      if(!fast)
      {
        struct t_gbsasm_out{
          int count;
          array{t_circle,128} circles;
        }
        t_gbsasm_out gb_out;
        gb_out.fromBlob(s);
        for(int i=0;i<gb_out.count;i++)
        {
          auto ex=gb_out.circles[i];
          //out+=circle_ex(ex.pos,ex.r,2,"707070","E1E1E1");
          brush+=circle(ex.pos,ex.r);
        }
      }
      out+=brush;
    }
    if(inp.tick==100){
      __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
      __destroy_smart_asm_hack(code);
      return "";
    }
    if(inp.kbEsc){__destroy_smart_asm_hack(code);return "";}
    out.ud=ud.toBlob();
    return out.toBlob();
  }
  
  if(inp.ud.size()>0){ud.fromBlob(inp.ud);}
  //
  char char(int v){return __IToC(v);}
  vec3c vec3c(int r,int g,int b){vec3c tmp;tmp.r=char(r);tmp.g=char(g);tmp.b=char(b);return tmp;}
  t_pen pen(int w,string color){t_pen tmp;tmp.w=w;tmp.color=color;return tmp;}
  t_brush brush(string color){t_brush tmp;tmp.color=color;return tmp;}
  t_brush brush(vec3c color){t_brush tmp;tmp.color=color;return tmp;}
  t_pixel pixel(vec2i p,string color){t_pixel tmp;tmp.p=p;tmp.color=color;return tmp;}
  t_pixel pixel(vec2i p,vec3c color){t_pixel tmp;tmp.p=p;tmp.color=color;return tmp;}
  t_rect rect(vec2i a,vec2i b){t_rect tmp;tmp.a=a;tmp.b=b;return tmp;}
  t_trigon trigon(vec2i a,vec2i b,vec2i c){t_trigon tmp;tmp.a=a;tmp.b=b;tmp.c=c;return tmp;}
  t_image image(vec2i pos,int w,int h,vector{vec3c} arr){t_image tmp;tmp.pos=pos;tmp.w=w;tmp.h=h;tmp.arr=arr;return tmp;}
  t_pen circle_ex(vec2i p,int r,int w,string pc,string bc){
    auto pen=pen(w,pc);
    auto brush=brush(bc);
    brush+=circle(p,r);
    pen+=brush;
    return pen;
  }
  //
  //if(false)
  {
    t_button button(vec2i pos,int r){t_button tmp;tmp.pos=pos;tmp.r=r;return tmp;}
    vector{t_button} operator+=(vector{t_button} out,t_button item){auto tmp=out;tmp.push_back(item);return tmp;}
    if(inp.tick==1){
      ud.buttons+=button(vec2i(300,45),16);
      ud.buttons+=button(vec2i(350,45),16);
      ud.buttons+=button(vec2i(500,45),16);
      ud.buttons+=button(vec2i(550,45),16);
      ud.buttons+=button(vec2i(650,50),12);
      ud.buttons+=button(vec2i(700,50),12);
      ud.buttons+=button(vec2i(700,100),12);
      ud.buttons+=button(vec2i(700,130),12);
    }
  }
  //
  if(!btn(ud,5)){ud.buttons.resize(0);}
  //
  bool btn(t_ud ud,int id){if(id>=ud.buttons.size())return false;return ud.buttons[id].counter%2==0;}
  //
  auto mpos=inp.mpos;
  auto tick=inp.tick;
  //
  vector{vec3c} operator=(vector{vec3c} out,vector{vec3c} inp){return inp;}
  //
  string bgcolor="E1E1E1";
  
  if(btn(ud,6))
  {
    auto brush=brush(bgcolor);
    auto pen=pen(1,bgcolor);
    pen+=rect(vec2i(0,0),vec2i(800,600));
    brush+=pen;
    out+=brush;
  }
  auto white=brush(bgcolor);

  if(btn(ud,4)){auto brush=brush(vec3c(64,128,64));brush+=rect(vec2i(400,400),vec2i(450,450));white+=brush;}
  if(btn(ud,3))
  {
    t_bullet bullet(vec2d p,vec2d v){t_bullet tmp;tmp.p=p;tmp.v=v;return tmp;}
    real operator+(real v){return v;}
    auto brush=brush("A1A1A1");
    auto border=20;
    auto h=10;
    auto a=vec2i(  0+border,600-border-0);
    auto b=vec2i(800-border,600-border-h);
    brush+=rect(a,b);
    auto r=16;
    if(tick==1)ud.p=vec2d((a.x+b.x)/2,a.y-r-h);
    brush+=circle(vec2i(ud.p),r);
    if(false)
    {
      auto bc="E0A0A0";
      auto p=vec2i(50,50);
      int w=1;
      if(vec2d_mag(vec2d(p-mpos))<real(7+10)){bc="A04040";w=2;}
      brush+=circle_ex(p,10,w,"D0B0B0",bc);
    }
    //
    auto v=ud.v;
    auto dv=0.1;
    if(inp.kbLeft)v.x+=-dv;
    if(inp.kbRight)v.x+=+dv;
    if(inp.kbUp)v.y+=-dv;
    if(inp.kbDown)v.y+=+dv;
    ud.v=v;
    ud.p+=ud.v;
    ud.v*=0.98;
    ud.v.y+=0.05;
    if(ud.p.y>real(a.y-r-h)){ud.p.y=real(a.y-r-h);ud.v.y=0.0;}
    if(ud.shottick>0)ud.shottick--;
    if(inp.mbLeft&&ud.shottick==0)
    {
      ud.shottick=16;
      auto v=vec2d_set_mag(vec2d(mpos)-ud.p,7.5);
      ud.bullets.push_back(bullet(ud.p,v));
    }
    //if(false)
    {
      auto arr=ud.bullets;
      for(int i=0;i<arr.size();i++)
      {
        auto ex=arr[i];
        ex.p+=ex.v;
        arr[i]=ex;
        brush+=circle(vec2i(ex.p),4);//return "";
      }
      vector{t_bullet} clean(vector{t_bullet} arr){
        vector{t_bullet} out;
        for(int i=0;i<arr.size();i++){
          auto ex=arr[i];
          auto p=ex.p;
          if(p.x<0.0||p.x>800.0||p.y<0.0||p.y>600.0)continue;
          out.push_back(ex);
        }
        return out;
      }
      ud.bullets=clean(arr);
    }
    white+=brush;
    //
  }
  if(btn(ud,1))
  {
    auto brush=brush(vec3c(96,128,96));
    vec2i d=vec2i(20,20);
    for(int i=0;i<3;i++){
      vec2i p=vec2i(50+i*150,150);
      brush+=rect(p,p+d);
    }
    white+=brush;
  }
  //white.dev+=rect(vec2i(0,0),vec2i(800,600));
  if(btn(ud,7))
  {
    auto pen=pen(4,"101010");
    pen+=line(vec2i(110,120),vec2i(510,200));
    white+=pen;
  }
  if(false)white+=circle_ex(vec2i(250,250),64,4,"718071","107010");
  white+=circle(inp.mpos,7);
  if(false)
  {
    auto brush=brush("ff8000");
    brush+=circle(mpos+vec2i(+40,+40),8);
    brush+=circle(mpos+vec2i(-40,+40),8);
    brush+=circle(mpos+vec2i(-40,-40),8);
    brush+=circle(mpos+vec2i(+40,-40),8);
    white+=brush;
  }
  if(btn(ud,2))
  {
    auto brush=brush("E07010");
    brush+=trigon(vec2i(50,50),vec2i(150,50),vec2i(100,100));
    white+=brush;
  }
  //for(int i=0;i<16;i++){white+=pixel(vec2i(100+i*3,100),"000000");}
  //white+=pixel(vec2i(100,100),"000000");
  //
  out+=white;
  //
  if(false)
  {
    out+=pixel(mpos,"ff8000");
    int count=8;
    int t0=tick*count;
    for(int i=0;i<count;i++){
      auto t=(t0+i)*4;
      out+=pixel(vec2i(100,100)+vec2i((t/4)%64,((t/4)/64)%64),vec3c(t%256,t/64,0));
    }
    auto brush=brush(vec3c(0,255,0));
    brush+=rect(vec2i(400,400),vec2i(450,450));
    out+=brush;
    //return out.toBlob();
  }
  //if(false)
  {
    auto bc="E0A0A0";
    auto p=vec2i(400,75);
    int w=1;
    if(vec2d_mag(vec2d(p-mpos))<real(7+10)){bc="A04040";w=2;if(inp.mbRight){ud.mode=true;}}
    out+=circle_ex(p,10,w,"D0B0B0",bc);
  }
  //if(false)
  {
    auto arr=ud.buttons;
    for(int i=0;i<arr.size();i++)
    {
      auto ex=arr[i];
      ex=update(ex,mpos,inp.mbLeft);
      arr[i]=ex;
      auto w=2;
      auto bc="a0a0a0";
      if(ex.hover)bc="d0d0d0";
      if(ex.down)bc="d0f0d0";
      out+=circle_ex(ex.pos,ex.r,w,"808080",bc);
    }
    ud.buttons=arr;
  }
  if(btn(ud,0))
  {
    real t=real(inp.tick);
    real g2rad=3.14/180.0;
    auto brush=brush("A0A0A0");
    for(int i=0;i<5;i++){
      //t_circle ex;
      real mag=32.0;
      real offset=__IToF(i)*360.0/5.0;
      real ang=(t*5.0+offset)*g2rad;
      auto p=vec2i(vec2d(__cos(ang),__sin(ang))*mag);
      vec2i mpos=vec2i(400,75);
      auto tmp=circle(p+mpos,4);
      brush+=tmp;
    }
    out+=brush;
  }
  out.ud=ud.toBlob();
  return out.toBlob();
  //
  int int(real inp){return __FToI(inp);}
  real real(int inp){return __IToF(inp);}
  vec2i vec2i(vec2d inp){return vec2i(int(inp.x),int(inp.y));}
  vec2d vec2d(vec2i inp){return vec2d(real(inp.x),real(inp.y));}
  //
  vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;}
  vec2i vec2i(){vec2i tmp;return tmp;}
  vec2i operator+=(vec2i out,vec2i inp){auto tmp=out;tmp.x+=inp.x;tmp.y+=inp.y;return tmp;}
  vec2i operator+(vec2i a,vec2i b){return vec2i(a.x+b.x,a.y+b.y);}
  vec2i operator-(vec2i a,vec2i b){return vec2i(a.x-b.x,a.y-b.y);}
  vec2i operator=(vec2i out,vec2i inp){return inp;}
  struct vec2i{
    int x;
    int y;
  }
  //
  t_circle circle(vec2i pos,int r){t_circle tmp;tmp.pos=pos;tmp.r=r;return tmp;}
  t_line line(vec2i a,vec2i b){t_line tmp;tmp.a=a;tmp.b=b;return tmp;}
  //
  int tick=inp.tick;
  if(inp.mbLeft&&!ud.ldown){
    ud.ldown=true;
    ud.circles.push_back(circle(inp.mpos,10));
  }
  if(!inp.mbLeft&&ud.ldown){ud.ldown=false;}
  if(inp.mbRight&&!ud.rdown){
    ud.rdown=true;
    ud.lines.push_back(line(inp.mpos,inp.mpos));
  }
  if(ud.rdown){ud.lines[ud.lines.size()-1].b=inp.mpos;}
  if(!inp.mbRight&&ud.rdown){ud.rdown=false;}
  if(inp.kbEsc){return "";}
  for(int i=0;i<ud.circles.size();i++){auto ex=ud.circles[i];out.circles.push_back(ex);}
  for(int i=0;i<ud.lines.size();i++){auto ex=ud.lines[i];out.lines.push_back(ex);}
  ud.total_time=ud.total_time+__microtime()-bef_time;
  //if(false)
  //if(ud.circles.size()>=4)
  {
    vec2d a=vec2d(450, 50);
    vec2d b=vec2d(650,150);
    vec2d c=vec2d(300,500);
    vec2d d=vec2d(390,550);
    b=vec2d(inp.mpos);
    out.circles.push_back(circle(vec2i(a),6));
    out.circles.push_back(circle(vec2i(b),6));
    out.circles.push_back(circle(vec2i(c),6));
    out.circles.push_back(circle(vec2i(d),6));
    /*
    vec2d a=vec2d(ud.circles[0].pos);
    vec2d b=vec2d(ud.circles[1].pos);
    vec2d c=vec2d(ud.circles[2].pos);
    vec2d d=vec2d(ud.circles[3].pos);*/
    b=vec2d(inp.mpos);
    int point_count=4;
    vector{vec2i} PA;
    for(int i=0;i<point_count;i++)
    {
      real t=IToF(i)/IToF(point_count);
      auto p=CatmullRom(a,b,c,d,t);
      //out+=add(p,5);
      out.circles.push_back(circle(vec2i(p),3));
      PA.push_back(vec2i(p));
    }
    PA.push_back(vec2i(CatmullRom(a,b,c,d,1.0)));
    for(int i=1;i<PA.size();i++){
      auto a=PA[i-1];
      auto b=PA[i-0];
      out.lines.push_back(line(a,b));
    }
    t_line line(vec2d a,vec2d b){return line(vec2i(a),vec2i(b));}
    out.lines.push_back(line(a,b));
    out.lines.push_back(line(c,d));
  }
  if(false)
  {
    if(inp.tick==100){
      __UserMsg("total_time = "+__FToS(ud.total_time)+"\navg = "+__FToS(ud.total_time*0.001/__IToF(inp.tick))+" ms.");
      if(!inp.mbRight)return "";
    }
  }
  out.ud=ud.toBlob();
  return out.toBlob();
  //------------------------------------
  //funcs-------------------------------
  //------------------------------------
  real abs(real v){return __abs(v);}
  real sin(real v){return __sin(v);}
  real cos(real v){return __cos(v);}
  real IToF(int v){return __IToF(v);}
  //real operator=(real out,int inp){return IToF(inp);}
  real operator+(real a,int b){return a+IToF(b);}
  real operator+(int a,real b){return IToF(a)+b;}
  real operator-(real a,int b){return a-IToF(b);}
  real operator-(int a,real b){return IToF(a)-b;}
  real operator*(real a,int b){return a*IToF(b);}
  real operator*(int a,real b){return b*IToF(a);}
  real operator/(real a,int b){return a/IToF(b);}
  vec2d operator*(vec2d a,real b){return vec2d(a.x*b,a.y*b);}
  vec2d operator+(vec2d a,vec2d b){return vec2d(a.x+b.x,a.y+b.y);}
  vec2d operator-(vec2d a,vec2d b){return vec2d(a.x-b.x,a.y-b.y);}
  vec2d operator+=(vec2d out,vec2d inp){auto tmp=out;tmp.x+=inp.x;tmp.y+=inp.y;return tmp;}
  vec2d operator*=(vec2d out,real k){auto tmp=out;tmp.x*=k;tmp.y*=k;return tmp;}
  vec2d vec2d(real x,real y){vec2d tmp;tmp.x=x;tmp.y=y;return tmp;}
  vec2d vec2d(int x,int y){return vec2d(IToF(x),IToF(y));}
  vec2d vec2d(){vec2d tmp;return tmp;}
  real vec2d_mag(vec2d v){return __sqrt(v.x*v.x+v.y*v.y);}
  vec2d vec2d_set_mag(vec2d v,real mag){return vec2d_norm(v)*mag;}
  vec2d vec2d_norm(vec2d v){if((v.x==0.0)&&(v.y==0.0)){return vec2d(0.0,0.0);}return vec2d(v.x/vec2d_mag(v),v.y/vec2d_mag(v));}
  real CatmullRomEx(real p1,real p2,real p3,real p4,real t){
    real t2=t*t;real t3=t2*t;return 0.5*((2.0*p2)+(p3-p1)*t+(2.0*p1-5.0*p2+4*p3-p4)*t2+(3.0*p2-3.0*p3+p4-p1)*t3);
  }
  vec2d CatmullRom(vec2d p1,vec2d p2,vec2d p3,vec2d p4,real t){
    p1=p2+vec2d_set_mag(p1-p2,abs(vec2d_mag(p3-p2)));p4=p3+vec2d_set_mag(p4-p3,abs(vec2d_mag(p2-p3)));
    return vec2d(CatmullRomEx(p1.x,p2.x,p3.x,p4.x,t),CatmullRomEx(p1.y,p2.y,p3.y,p4.y,t));
  }
}
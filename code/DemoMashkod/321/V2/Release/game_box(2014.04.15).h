{
  if(false)
  {
    auto code=__file_get_contents("smart_asm.asm");
    code=__StrReplace(code,"\r","");
    auto s=__run_smart_asm(code,32);
    __UserMsg("runned...");
    return "";
  }
  if(false)
  {
    auto s=__file_get_contents("2014.04.04.h");
    __UserMsg(__StrReplace(s,"][","],\n["));return "";
  }
  if(false)
  {
    //string code="t_foo{{go_const(\"t_foo\");}}";
    //auto fn="asm_lex_source.hpp";
    auto fn="smart_asm_lex_src.hpp";
    //auto fn="t_target_lexem_source.inl";
    auto code=__file_get_contents(fn);
    real bef_time=__microtime();
    string msg=__gen_lexem_v01(code);
    real aft_time=__microtime();
    __UserMsg("//time = "+__FToS(0.001*(aft_time-bef_time))+" ms.\n\n"+msg);return "";
  }
  if(false)
  {
    string gen(int r)
    {
      bool f(int x,int y,int r){return x*x+y*y>r*r;}
      vector{vec3c} arr;
      int w=r*2;
      int c=w*w;
      int dc=256/w;
      for(int i=0;i<c;i++){
        int x=i%w;
        int y=i/w;
        vec3c out;
        out.r=char(x*dc);
        out.g=char(y*dc);
        if(f(x-r,y-r,r)){vec3c bgcolor;bgcolor="E1E1E1";arr.push_back(bgcolor);continue;}
        arr.push_back(out);
      }
      return arr.toBlob();
    }
    void check(string s,int r)
    {
      __UserMsg("checking");/*
      struct vec4c{char r;char g;char b;char a;}
      vector{int} arr;
      arr.fromBlob(s);
      vec3c f(int i){
        vec4c c;c.fromBlob(i.toBlob());
        vec3c tmp;
        tmp.r=c.r;
        tmp.g=c.g;
        tmp.b=c.b;
        return tmp;
      }
      vector{vec3c} out;
      int c=arr.size();
      for(int i=0;i<c;i++)out.push_back(f(arr[i]));*/
      vector{vec3c} out; out.fromBlob(s);
      string hex_load(string fn){
        string s=__file_get_contents(fn);
        s=__StrReplace(s,"\r","");
        s=__StrReplace(s,"\n","");
        s=__HexToBlob(s);
        return s;
      }
      auto c32_bin=gen(r);
      auto cur=out.toBlob();
      __UserMsg("check_result : "+__BToS(c32_bin==cur));
      //__UserMsg("check_result : "+__BToS(c32_bin==cur)+"\nsrc:"+__BlobToHex(c32_bin)+"\ncur:"+__BlobToHex(cur));
    }
    auto code=__file_get_contents("asm_bin.asm");
    code=__StrReplace(code,"\r","");
    struct t_inp{int size;int r;};
    t_inp inp;inp.size=2;inp.r=128;
    auto input=inp.toBlob()+__HexToBlob("E1E1E1E1");
    real bef_time=__microtime();
    auto ret=__call_asm_bin(code,input);
    real aft_time=__microtime();
    __UserMsg("time = "+__FToS(0.001*(aft_time-bef_time))+" ms.");return "";
    check(ret,inp.r);
    string result="answer:\n"+__BlobToHex(ret)+"\nend";
    //string result="answer:\n"+__call_asm_test(code,"1000")+"\nend";
    __UserMsg(result);
    return "";
  }
  if(false)
  {
    string join(vector{string} arr,string glue){
      bool bool(int i){return i!=0;}
      string out;
      for(int i=0;i<arr.size();i++){
        if(bool(i))out+=glue;
        out+=arr[i];
      }
      return out;
    }

    vector{string} split(string s,string needle)
    {
      vector{string} arr;
      auto p=0;
      for(;;){
        auto pos=__StrFind(s,needle,p);
        if(pos<0){arr.push_back(__StrSubStr(s,p,s.size()-p));return arr;}
        arr.push_back(__StrSubStr(s,p,pos-p));
        p=pos+needle.size();
      }
      return arr;
    }

    vector{int} load(string s){
      return load(split(s," "));
    }

    vector{int} load(vector{string} arr){
      vector{int} out;
      for(int i=0;i<arr.size();i++)out.push_back(__SToI(arr[i]));
      return out;
    }

    vector{int} clean(vector{int} arr){
      vector{int} out;
      for(int i=0;i<arr.size();i++)if(arr[i]>0)out.push_back(arr[i]);
      return out;
    }
    
    string print(vector{int} arr){
      vector{string} out;
      for(int i=0;i<arr.size();i++)out.push_back(__IToS(arr[i]));
      return join(out," ");
    }
    
    vector{int} operator=(vector{int} out,vector{int} inp){return inp;}
    
    auto arr=load("1 0 2 0 0 5");
    string s=print(arr)+"\n";
    arr=clean(arr);
    string x=print(arr)+"\n";
    __UserMsg(s+x);
    return "";
  }
  //string s; s.resize(1); s[0]='a'; __UserMsg(__BlobToHex(s)); return "";
  if(false)
  {//return "";
    auto code=__file_get_contents("asm_test.asm");
    //auto input="7 1 2 3 4 5 1 1";
    //input="1000";
    string result=__call_asm_test(code,"5");
    __UserMsg(result);return "";
  }
  if(false)
  {
    if(false)
    {
      string s;
      for(int i=0;i<64;i++){
        //s+="struct t"+__IToS(i)+"{t"+__IToS(i+1)+" a;};\n";
        s+=".a";
      }
      __UserMsg(s);
    }
    struct t0{t1 a;};
    struct t1{t2 a;};
    struct t2{t3 a;};
    struct t3{t4 a;};
    struct t4{t5 a;};
    struct t5{t6 a;};
    struct t6{t7 a;};
    struct t7{t8 a;};
    struct t8{t9 a;};
    struct t9{t10 a;};
    struct t10{t11 a;};
    struct t11{t12 a;};
    struct t12{t13 a;};
    struct t13{t14 a;};
    struct t14{t15 a;};
    struct t15{t16 a;};
    struct t16{t17 a;};
    struct t17{t18 a;};
    struct t18{t19 a;};
    struct t19{t20 a;};
    struct t20{t21 a;};
    struct t21{t22 a;};
    struct t22{t23 a;};
    struct t23{t24 a;};
    struct t24{t25 a;};
    struct t25{t26 a;};
    struct t26{t27 a;};
    struct t27{t28 a;};
    struct t28{t29 a;};
    struct t29{t30 a;};
    struct t30{t31 a;};
    struct t31{t32 a;};
    struct t32{t33 a;};
    struct t33{t34 a;};
    struct t34{t35 a;};
    struct t35{t36 a;};
    struct t36{t37 a;};
    struct t37{t38 a;};
    struct t38{t39 a;};
    struct t39{t40 a;};
    struct t40{t41 a;};
    struct t41{t42 a;};
    struct t42{t43 a;};
    struct t43{t44 a;};
    struct t44{t45 a;};
    struct t45{t46 a;};
    struct t46{t47 a;};
    struct t47{t48 a;};
    struct t48{t49 a;};
    struct t49{t50 a;};
    struct t50{t51 a;};
    struct t51{t52 a;};
    struct t52{t53 a;};
    struct t53{t54 a;};
    struct t54{t55 a;};
    struct t55{t56 a;};
    struct t56{t57 a;};
    struct t57{t58 a;};
    struct t58{t59 a;};
    struct t59{t60 a;};
    struct t60{t61 a;};
    struct t61{t62 a;};
    struct t62{t63 a;};
    struct t63{int a;};
    int count=100;
    real bef_time=__microtime();
    t0 t;
    int u=0;
    for(int i=0;i<count;i++){
      //t.a.a.a.a=i;
      t.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a=i;
      //u=i;
    }
    real aft_time=__microtime();
    __UserMsg("time : "+__FToS(aft_time-bef_time));
    return "";
  }
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
  if(inp.kbEsc){return "";}
  t_ud ud;
  //if(inp.ud.size()>0){ud.fromBlob(inp.ud);}
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
  /*
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
  out.ud=ud.toBlob();*/
  //if("1"!="2")return __UserMsg(":)");;
  if(false)
  {
    string gen_src(int w,vec3c bgcolor)
    {
      bool f(int x,int y,int r){return x*x+y*y>r*r;}
      vector{vec3c} arr;
      int r=w/2;
      int c=w*w;
      int dc=256/w;
      for(int i=0;i<c;i++){
        int x=i%w;
        int y=i/w;
        vec3c out;
        out.r=char(x*dc);
        out.g=char(y*dc);
        if(f(x-r,y-r,r)){/*vec3c bgcolor;bgcolor="E1E1E1";*/arr.push_back(bgcolor);continue;}
        arr.push_back(out);
      }
      return arr.toBlob();
    }
    vector{vec3c} gen_asm(int w,vec3c color)
    {
      auto code=__file_get_contents("asm_bin.asm");
      code=__StrReplace(code,"\r","");
      struct t_asm_inp{int size;int r;vec3c color;char unused;};
      t_asm_inp inp;inp.size=2;inp.r=w/2;inp.color=color;
      auto input=inp.toBlob();
      real bef_time=__microtime();
      auto ret=__call_asm_bin(code,input);
      vector{vec3c} out;
      out.fromBlob(ret);
      return out;
    }
    vector{vec3c} gen_smart_asm(int w,vec3c color)
    {
      auto code=__file_get_contents("smart_asm.asm");
      code=__StrReplace(code,"\r","");
      auto r=w/2;
      auto s=__run_smart_asm(code,r);
      s=__StrSubStr(s,4,4+4+r*r*3*4);
      vector{vec3c} out;
      out.fromBlob(s);
      return out;
    }
    vector{vec3c} gen(int w,vec3c color)
    {
      vector{vec3c} arr;
      int c=w*w;
      for(int i=0;i<c;i++)arr.push_back(color);
      return arr;
    }
    vector{vec3c} gen_str(int w,vec3c color)
    {
      vector{vec3c} arr;
      string s=color.toBlob();
      int c=w*w;
      string out=c.toBlob();
      for(int i=0;i<c;i++)out+=s;
      arr.fromBlob(out);
      return arr;
    }
    vector{vec3c} gen_sft(int w,vec3c color)
    {
      vector{vec3c} arr;
      string s=color.toBlob();
      int c=w*w;
      string out=s;
      for(int i=1;i<c;i*=2)out+=out;
      if(out.size()/3!=c)__UserMsg(__IToS(out.size()));
      arr.fromBlob(c.toBlob()+out);
      return arr;
    }
    bool operator!=(vec3c a,vec3c b){
      return (a.r!=b.r)||(a.g!=b.g)||(a.b!=b.b);
    }
    bool operator!=(vector{vec3c} a,vector{vec3c} b){
      if(a.size()!=b.size())return true;
      for(int i=0;i<a.size();i++)if(a[i]!=b[i])return true;
      return false;
    }
    array{vec3c,1024} fill(vec3c color){
      array{vec3c,1024} tmp;
      for(int i=0;i<1024;i++)tmp[i]=color;
      return tmp;
    }
    vector{vec3c} gen_arr(int w,vec3c color)
    {
      vector{vec3c} arr;
      int c=w*w;
      string out=c.toBlob();
      auto a=fill(color);
      arr.fromBlob(out+a.toBlob());
      //if(gen(w,color)!=arr)__UserMsg("bad");
      return arr;
    }
    vector{vec3c} arr;
    int w=32;
    vec3c color;color="E1E1E1";
    real bef_time=__microtime();
    //{arr.resize(w*w);int c=w*w;for(int i=0;i<c;i++)arr[i]=color;}
    {arr=gen(w,color);} //time : 2814511.86
    real aft_time=__microtime();
    {auto tmp=arr;}
    real end_time=__microtime();

    real gsf_time;
    {
      gsf_time=__microtime();
      {auto y=gen_sft(w,color);}
      gsf_time=__microtime()-gsf_time;
    }

    real str_time;
    real tob_time;
    {
      tob_time=__microtime();
      auto x=arr.toBlob();
      tob_time=__microtime()-tob_time;
      str_time=__microtime();
      auto y=x;
      str_time=__microtime()-str_time;
    }
    real gas_time;
    {
      gas_time=__microtime();
      {auto y=gen_str(w,color);}
      gas_time=__microtime()-gas_time;
    }
    real gaa_time;
    {
      gaa_time=__microtime();
      {auto y=gen_arr(w,color);}
      gaa_time=__microtime()-gaa_time;
    }
    real gsr_time;
    {
      gsr_time=__microtime();
      {auto y=gen_src(w,color);}
      gsr_time=__microtime()-gsr_time;
    }
    real gam_time;
    {
      gam_time=__microtime();
      {auto y=gen_asm(w,color);}
      gam_time=__microtime()-gam_time;
    }
    real gsa_time;
    {
      gsa_time=__microtime();
      {auto y=gen_smart_asm(w,color);}
      gsa_time=__microtime()-gsa_time;
    }
    //
    string msg;
    msg+="gen_time     : "+__FToS(aft_time-bef_time)+"\n";
    msg+="gen_time/pix : "+__FToS((aft_time-bef_time)/real(w*w))+"\n";
    msg+="cpy_time     : "+__FToS(end_time-aft_time)+"\n";
    msg+="cpy_time/pix : "+__FToS((end_time-aft_time)/real(w*w))+"\n";
    msg+="str_time     : "+__FToS(str_time)+"\n";
    msg+="str_time/pix : "+__FToS(str_time/real(w*w))+"\n";
    msg+="tob_time     : "+__FToS(tob_time)+"\n";
    msg+="tob_time/pix : "+__FToS(tob_time/real(w*w))+"\n";
    msg+="gas_time     : "+__FToS(gas_time)+"\n";
    msg+="gas_time/pix : "+__FToS(gas_time/real(w*w))+"\n";
    msg+="gaa_time     : "+__FToS(gaa_time)+"\n";
    msg+="gaa_time/pix : "+__FToS(gaa_time/real(w*w))+"\n";
    msg+="gsf_time     : "+__FToS(gsf_time)+"\n";
    msg+="gsf_time/pix : "+__FToS(gsf_time/real(w*w))+"\n";
    msg+="gsr_time     : "+__FToS(gsr_time)+"\n";
    msg+="gsr_time/pix : "+__FToS(gsr_time/real(w*w))+"\n";
    msg+="gam_time     : "+__FToS(gam_time)+"\n";
    msg+="gam_time/pix : "+__FToS(gam_time/real(w*w))+"\n";
    msg+="gsa_time     : "+__FToS(gsa_time)+"\n";
    msg+="gas_time/pix : "+__FToS(gsa_time/real(w*w))+"\n";
    real gt=aft_time-bef_time;
    real ct=end_time-aft_time;
    msg+="gen/cpy      : "+__FToS(gt/ct)+"\n";
    msg+="cpy/str      : "+__FToS(ct/str_time)+"\n";
    msg+="tob/str      : "+__FToS(tob_time/str_time)+"\n";
    msg+="gas/cpy      : "+__FToS(gas_time/ct)+"\n";
    msg+="gaa/cpy      : "+__FToS(gaa_time/ct)+"\n";
    msg+="gsf/cpy      : "+__FToS(gsf_time/ct)+"\n";
    msg+="gsr/cpy      : "+__FToS(gsr_time/ct)+"\n";
    msg+="gam/cpy      : "+__FToS(gam_time/ct)+"\n";
    msg+="gsa/cpy      : "+__FToS(gsa_time/ct)+"\n";
    __UserMsg(msg);
    return "";
  }
  //if(false)
  {
    string bgcolor="E1E1E1";
    auto brush=brush(bgcolor);
    auto pen=pen(1,bgcolor);
    pen+=rect(vec2i(0,0),vec2i(800,600));
    brush+=pen;
    out+=brush;
  }
  //if(false)
  {
    int r=8;
    int w=r*2;
    bool regen=true;
    //regen=false;
    if(!regen){r=32;w=r*2;}
    if(tick==1)
    {
      if(regen)
      {
        if(false)
        {
          bool f(int x,int y,int r){return x*x+y*y>r*r;}
          vector{vec3c} arr;
          int c=w*w;
          int dc=256/w;
          for(int i=0;i<c;i++){
            int x=i%w;
            int y=i/w;
            vec3c out;
            out.r=char(x*dc);
            out.g=char(y*dc);
            if(f(x-r,y-r,r)){vec3c bgcolor;bgcolor="E1E1E1";arr.push_back(bgcolor);continue;}
            arr.push_back(out);
          }
          inp.ud=arr.toBlob();
        }
        string gen_asm(int r,string color)
        {
          auto code=__file_get_contents("asm_bin.asm");
          code=__StrReplace(code,"\r","");
          struct t_asm_inp{int size;int r;vec3c color;char unused;};
          t_asm_inp inp;inp.size=2;inp.r=r;inp.color=color;
          auto input=inp.toBlob();
          real bef_time=__microtime();
          auto ret=__call_asm_bin(code,input);
          return ret;
        }
        string smart_asm_gen(int r,string color){
          auto code=__file_get_contents("smart_asm.asm");
          code=__StrReplace(code,"\r","");
          auto s=__run_smart_asm(code,r);/*
          s=__StrSubStr(s,4,4);
          int v=1;
          v.fromBlob(s);
          __UserMsg(__IToS(v));*/
          s=__StrSubStr(s,4,4+4+r*r*3*4);
          return s;
        }
        //inp.ud=gen_asm(r,"E1E1E1");
        inp.ud=smart_asm_gen(r,"E1E1E1");
      }
      if(!regen)
      {
        string hex_load(string fn){
          string s=__file_get_contents(fn);
          s=__StrReplace(s,"\r","");
          s=__StrReplace(s,"\n","");
          s=__HexToBlob(s);
          return s;
        }
        //auto c32_bin=urle_load("url_enc.h");
        auto c32_bin=hex_load("hex.txt");
        inp.ud=c32_bin;
      }
      int gg=1;
    }
    //if(false)
    {
      //__UserMsg("2.0");
      vector{vec3c} arr;
      arr.fromBlob(inp.ud);
      out+=image(inp.mpos-vec2i(r,r),w,w,arr);//__UserMsg("2.1");
      out.ud=inp.ud;
    }
  }
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
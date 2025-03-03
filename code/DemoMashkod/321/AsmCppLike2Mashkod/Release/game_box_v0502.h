{
  //array{array{int,2},2} mat22; //mat22[1][1]=10;__UserMsg(mat22.toProto());
  if(false)
  {
    struct t_rec{
      real bef;
      real aft;
      real time;
    }
    t_rec operator=(t_rec out,t_rec inp){return inp;}
    t_rec calc(t_rec r){t_rec tmp;tmp.bef=r.bef;tmp.aft=r.aft;tmp.time=r.aft-r.bef;return tmp;}
    struct t_out{
      t_rec a32;
      t_rec a256;
    }
    t_out out;
    {
      struct t_gama{
        array{vec2i,32} arr;
      }
      t_gama game;
      out.a32.bef=__microtime();
      for(int i=0;i<16;i++)
      {
        game.arr[i]=vec2i(i,99);
      }
      out.a32.aft=__microtime();
      out.a32=calc(out.a32);
    }
    {
      struct t_game{
        array{vec2i,256} arr;
      }
      t_game game;
      out.a256.bef=__microtime();
      for(int i=0;i<16;i++)
      {
        game.arr[i]=vec2i(i,99);
      }
      out.a256.aft=__microtime();
      out.a256=calc(out.a256);
    }
    string toStr(t_rec v){return __FToS(v.time);}
    __UserMsg("a32 = "+toStr(out.a32)+"\na256 = "+toStr(out.a256)+"\nk = "+__FToS(out.a256.time/out.a32.time));
    return "";  
  }
  if(false)
  {
    string pad(int v,int count){auto s=__IToS(v);for(;__StrLen(s)<count;s="0"+s);return s;}
    array{int,4} arr;arr[1]=1<<5;arr[2]=(1<<16)-1;
    char a='A';
    string out;int count=0;
    for(int i=0;i<16;i++){
      out+="id:"+pad(i,2)+" => "+__BlobToBin(a.toBlob());
      out+="\n";
      a++;count++;
    }
    //__UserMsg("count = "+__IToS(count)+"\n"+__IToS(__StrLen(out)));
    //out=__BlobToHex(out);
    __UserMsg("result:\n"+__BlobToHex(arr.toBlob())+"\nout[17:16]:\n"+out+"\nend");
  }
  //return "";
  if(false)
  {
    struct ug{
      array{int,2} e;
    }
    array{ug,2} arr;
    auto u=arr[0].e[0];
    {
      vec2i tmp;
      tmp.x=5;
      tmp.y=7;
      tmp=vec2i(3,5);
    }
  }
  if(false)
  {
    struct t_foo{
      array{vec2i,64} arr;
    }
    {
      t_foo foo;
      foo.arr[10]=vec2i(2,3);
    }
    if(true)
    {
      array{int,2} arr;
      arr[1]=999;
      {
        int i=15;
        arr[i-14]-=15;
      }
      //__UserMsg(arr.toProto());
      auto a0=arr[0];
    }
    {
      auto v=vec2i(1,1);
    }
  }
  vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;}
  vec2i vec2i(){vec2i tmp;return tmp;}
  vec2i operator=(vec2i out,vec2i inp){return inp;}
  struct vec2i{
    int x;
    int y;
  }
  /*vector{int} arr;
  array{int,50} e;
  vector{int}::type e;*/
  auto inp=POST_DATA;
  string toBlob(vec2i v){return __IToBlob(v.x)+__IToBlob(v.y);}
  int get_int(string s,int offset){return __BlobToI(__StrSubStr(s,offset,4));}
  bool get_bool(string s,int offset){return __BlobToB(__StrSubStr(s,offset,1));}
  vec2i get_vec2i(string s,int offset){return vec2i(get_int(s,offset+0),get_int(s,offset+4));}
  string get_string(string s,int offset){return __BlobToS(__StrSubStr(s,offset,__StrLen(s)));}
  string add_circle(int x,int y,int r){return __IToBlob(x)+__IToBlob(y)+__IToBlob(r);}
  string add_line(vec2i a,vec2i b){return toBlob(a)+toBlob(b);}
  int tick=get_int(inp,0);
  int x=get_int(inp,4);
  int y=get_int(inp,8);
  bool mbLeft=get_bool(inp,12);
  //bool mbMiddle=get_bool(inp,13);
  bool mbRight=get_bool(inp,14);
  //bool kbEsc=get_bool(inp,15);
  string userdata=get_string(inp,16);
  string ud_circles;
  int user_cc=0;
  string ud_lines;
  int user_lc=0;
  bool down=false;
  bool rdown=false;
  //
  int out_cc=0;
  int circles_count=0;
  string circles;
  int lines_count=0;
  string lines;
  //
  circles+=add_circle(x,y,10);circles_count++;
  lines+=add_line(vec2i(10,20),vec2i(700,20));lines_count++;
  if(__StrLen(userdata)>0)
  {
    down=get_bool(userdata,0);
    rdown=get_bool(userdata,1);
    user_cc=get_int(userdata,2);
    int offset=6;
    vec2i mpos=vec2i(x,y);
    for(int i=0;i<user_cc;i++){
      int x=get_int(userdata,offset+i*12+0);
      int y=get_int(userdata,offset+i*12+4);
      int r=get_int(userdata,offset+i*12+8);
      if(mbLeft&&!down){
        auto dx=mpos.x-x;
        auto dy=mpos.y-y;
        auto d=dx*dx+dy*dy;
        if(d<(r*r))continue;
      }
      circles+=add_circle(x,y,r);circles_count++;
      ud_circles+=add_circle(x,y,r);out_cc++;
    }
    offset+=user_cc*3*4;
    user_lc=get_int(userdata,offset);
    offset+=4;
    for(int i=0;i<user_lc;i++){
      auto a=get_vec2i(userdata,offset+i*16+0);
      auto b=get_vec2i(userdata,offset+i*16+8);
      lines+=add_line(a,b);lines_count++;
      ud_lines+=add_line(a,b);//__UserMsg(ud_lines.toProto());
    }
  }
  if(mbLeft&&!down){
    ud_circles+=add_circle(x,y,10);out_cc++;
    circles+=add_circle(x,y,10);circles_count++;down=true;
  };
  if(down){
    ud_circles=__StrSubStr(ud_circles,0,__StrLen(ud_circles)-12)+__IToBlob(x)+__IToBlob(y)+__StrSubStr(ud_circles,__StrLen(ud_circles)-4,4);
    circles=__StrSubStr(circles,0,__StrLen(circles)-12)+__IToBlob(x)+__IToBlob(y)+__StrSubStr(circles,__StrLen(circles)-4,4);
  }
  if(!mbLeft)down=false;
  if(mbRight&&!rdown){
    ud_lines+=add_line(vec2i(x,y),vec2i(x+10,y));user_lc++;
    lines+=add_line(vec2i(x,y),vec2i(x,y));lines_count++;rdown=true;
  };
  if(rdown){
    ud_lines=__StrSubStr(ud_lines,0,__StrLen(ud_lines)-8)+__IToBlob(x)+__IToBlob(y);
    lines=__StrSubStr(lines,0,__StrLen(lines)-8)+__IToBlob(x)+__IToBlob(y);
  }
  if(!mbRight&&rdown){
    rdown=false;
  }
  string ud_out=__BToBlob(down)+__BToBlob(rdown)+__IToBlob(out_cc)+ud_circles+__IToBlob(user_lc)+ud_lines;
  return __IToBlob(circles_count)+circles+__IToBlob(lines_count)+lines+__SToBlob(ud_out);
}
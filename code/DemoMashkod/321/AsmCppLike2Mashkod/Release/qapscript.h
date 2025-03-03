{
  struct quad{
    vec2d pos;
    vec2d r;
    bool flag;
    char c='Q';
  }
  quad qj; return qj.toJson();//return ""+qj;//return qj.toJson();
  /*
  {pos:{x:0.00,y:0.00},r:{x:0.00,y:0.00},flag:false,c:Q}
  */
  struct vec2d
  {
    real x;
    real y;
    string u(){return "vec2d::u";}
    //int operator*=(int){return 0;}
  }
  vec2d v;// rooot::block_id[3]
  //auto s=v.toProto();return s;
  //return v.u();
  //vec2d::u();
  v.x=+10.0;
  v.y=-20.0;
  v.x=50.0;
  auto x=v.x;
  auto y=v.y;
  {
    auto gg=vec2d();
  }
  auto msg="v = "+v;
  msg+="\n";
  quad q;
  q.pos=v;
  q.pos.y=35.0;
  q.r=vec2d(1.5,0.2);
  q.c='d';
  msg+="q = "+q;//auto s=q.toProto();return s;
  return msg;
  //
  real operator+(real v){return v;}
  real operator-(real v){return v*__IToF(-1);}
  string operator+(string s,real v){return s+__FToS(v);}
  string operator+(string s,bool v){return s+__BToS(v);}
  string operator+(string s,vec2d v){return s+"{x:"+v.x+",y:"+v.y+"}";}
  vec2d operator=(vec2d a,vec2d b){return b;}
  vec2d vec2d(real x,real y){vec2d tmp;tmp.x=x;tmp.y=y;return tmp;}
  vec2d vec2d(){vec2d tmp;return tmp;}
  string operator+(string s,quad q){return s+"{pos:"+q.pos+",r:"+q.r+",flag:"+q.flag+",c:"+__CToS(q.c)+"}";}
}
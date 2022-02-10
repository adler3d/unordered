struct t_fast_obj{
  #define DEF_PRO_CLASSNAME()t_fast_obj
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,pos,$)\
  ADD(vec2d,v,$)\
  ADD(vec2d,a,$)\
  ADD(int,points,0)\
  //===
  #include "defprovar.inl"
  //===
  template<class NBF>
  void set(NBF&nbf,const t_obj&ref){
    pos=ref.pos;
    v=ref.v;
    a=ref.a;
    points=0;
    points=nbf.pnt2id(ref.points);
  }
  void apply_input()
  {
    auto old_v=v;
    //v+=a;
    v=Vec2dEx(v.GetAng()-a.x*PiD2*1.5*0.25,v.Mag()+a.y);
    if(v.Mag()>max_speed)v=v.SetMag(max_speed);
    if(v.Mag()<min_speed)v=v.SetMag(min_speed);
  }
  void move_fast()
  {
    apply_input();
    pos+=v;
  }
  template<class NBF>
  void move_full(NBF&nbf){
    move_fast();
    const auto&orig=nbf.id2vec[points];
    bool need_del=false;
    for(int i=0;i<orig.size();i++)if(pos.dist_to_point_less_that_r(orig[i].pos,32)){
      need_del=true;break;
    }
    if(!need_del)return;
    auto arr=orig;
    QapCleanIf(arr,[&](t_point&p){return pos.dist_to_point_less_that_r(p.pos,32);});
    if(arr==orig)return;
    points=nbf.pnt2id(arr);
  }
  vec2d wasd2a(const vec2d&wasd){
    return wasd*(1.0/32.0);//wasd.SetMag(0.05).Ort().UnRot(-v);
  }
  static t_fast_obj raw_sim(const t_fast_obj&src,vec2d cmd,int max_iter)
  {
    auto cur=src;
    for(int iter=0;iter<max_iter;iter++)
    {
      cur.a=cur.wasd2a(cmd);
      cur.move_fast();
    }
    return cur;
  }
};
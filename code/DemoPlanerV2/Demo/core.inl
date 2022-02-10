struct t_obj{
  #define DEF_PRO_CLASSNAME()t_obj
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,pos,$)\
  ADD(vec2d,v,$)\
  ADD(vec2d,a,$)\
  ADD(bool,v_changed,false)\
  //===
  #include "defprovar.inl"
  //===
  t_obj&set_v(const vec2d&ref){v=ref;return *this;}
  void apply_input()
  {
    auto old_v=v;
    //v+=a;
    v=Vec2dEx(v.GetAng()-a.x*PiD2*1.5*0.25,max_speed);
    v_changed=v!=old_v;
  }
  void move()
  {
    apply_input();
    pos+=v;
    //a=vec2d_zero;
  }
  vec2d wasd2a(const vec2d&wasd){
    return wasd*(1.0/32.0);
  }
  static t_obj raw_sim(const t_obj&src,vec2d cmd,int max_iter)
  {
    auto cur=src;
    for(int iter=0;iter<max_iter;iter++)
    {
      cur.a=cur.wasd2a(cmd);
      cur.move();
    }
    return cur;
  }
  void draw_object(QapDev&qDev,bool end=false,real r=32,real ds=4)
  {
    auto&obj=*this;
    qDev.SetColor(0xffbbbbbb);
    qDev.DrawSolidCircle(obj.pos,r,32,0);
    qDev.SetColor(0xff404040);
    qDev.DrawCircle(obj.pos,r,0,ds,32);
    qDev.DrawLine(obj.pos,obj.pos+obj.v*(r/max_speed),4);
    qDev.SetColor(0xffff4040);
    if(obj.v_changed)qDev.DrawLine(obj.pos,obj.pos+obj.a.SetMag(20).UnRot(-obj.v.Ort()),2);
    if(end){qDev.SetColor(0xff000000);qap_text_draw_at_x_center(qDev,obj.pos,"end",16);}
  }
};
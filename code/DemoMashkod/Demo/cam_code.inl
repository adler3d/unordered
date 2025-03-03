struct t_cam{
  #define DEF_PRO_CLASSNAME()t_cam
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2d,pos,$)\
  ADD(vec2d,dir,vec2d(1,0))\
  ADD(bool,rot,false)\
  ADD(bool,offcentric,false)\
  ADD(real,scale,1)\
  //===
  #include "defprovar.inl"
  //===
};

void cam_kb_move()
{
  if(cam.rot)
  {
    auto k=(1.0+(45-10)/75.0);
    real da=0;
    if(kb.Down('Q'))da=-1;
    if(kb.Down('E'))da=+1;
    cam.dir=Vec2dEx(cam.dir.GetAng()+k*(da*Pi/75.0),1);
  }
  if(bool end=true){cam.pos+=kb.get_dir_from_wasd_and_arrows()*(5.0/cam.scale);}else{cam.pos=vec2d_zero;}
  if(kb.Down(VK_ADD))cam.scale*=1.01;
  if(kb.Down(VK_SUBTRACT))cam.scale/=1.01;
  if(kb.Down(VK_DIVIDE))cam.scale=1;
  if(kb.OnDown(VK_MULTIPLY))cam.scale*=0.5;
  if(kb.Down(VK_SHIFT)&&kb.OnDown(VK_DIVIDE))cam.pos=vec2d_zero;
  if(kb.Down(VK_SHIFT)&&kb.OnDown(VK_MULTIPLY))cam.pos=vec2d_zero;
}
#define OFFCENTRIC_SCOPE_IMPL()struct{vec2d v;} obj={vec2d(1,0)};t_offcentric_scope scope(qDev,cam.pos,cam.rot?cam.dir.Rot(-obj.v.Ort()).Norm():cam.dir,cam.scale,cam.offcentric);
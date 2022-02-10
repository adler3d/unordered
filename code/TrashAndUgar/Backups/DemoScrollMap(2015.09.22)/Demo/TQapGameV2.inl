class TQapGameV2:public TQapGame{
public:
  struct t_input{
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,actor_id,-1)\
    ADD(QapKeyboard,kb,$)\
    ADD(vec2d,mpos,$)\
    ADD(vec2d,consize,$)\
    ADD(int,zDelta,0)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_input(){DoReset();}
    operator bool()const{return point_in_quad(t_quad().add_size(consize),mpos);}
  };
public:
#define DEF_PRO_VARIABLE(ADD)\
ADD(bool,drawpass,false)\
ADD(bool,movepass,false)\
ADD(bool,srvpass,false)\
ADD(bool,cntpass,false)\
ADD(t_quad&,viewport,qDev.viewport)\
ADD(vec2d&,consize,viewport.size)\
//===
#include "defprovar.inl"
//===
public:
  TQapGameV2():viewport(qDev.viewport),consize(viewport.size){DoReset();}
public:
  void DoDraw(){qDev.auto_clamp=true;consize=win.GetClientSize();drawpass=true;soUpdate();drawpass=false;}
  void DoMove(){qDev.auto_clamp=true;consize=win.GetClientSize();movepass=true;soUpdate();movepass=false;}
  virtual void soUpdate(){}
public:
  static void DrawQuadWithBorder(QapDev&qDev,t_quad q)
  {
    qDev.DrawQuad(q.pos,q.size);
    DrawQuadBorder(qDev,q);
  }
  static void DrawQuadBorder(QapDev&qDev,t_quad q){qDev.color=QapColor::HalfMix(0xff000000,qDev.color);qDev.DrawRectAsQuad(q.pos,q.size,2);}
  void DrawQuadWithBorder(t_quad q){DrawQuadWithBorder(qDev,q);}
  void DrawQuadBorder(t_quad q){DrawQuadBorder(qDev,q);}
  static void DrawQuad(QapDev&qDev,t_quad q){qDev.DrawQuad(q.pos,q.size);}
};
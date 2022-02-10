class TQapGameV2:public TQapGame{
public:
  struct t_input{
    int actor_id=-1;
    QapKeyboard kb;
    vec2d mpos;
    vec2d consize;
    int zDelta=0;
    operator bool()const{return point_in_quad(t_quad().add_size(consize),mpos);}
  };
public:
  bool drawpass=false;
  bool movepass=false;
  bool srvpass=false;
  bool cntpass=false;
  t_quad&viewport=qDev.viewport;
  vec2d&consize=viewport.size;
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
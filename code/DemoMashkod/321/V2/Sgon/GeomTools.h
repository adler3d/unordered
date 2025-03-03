template<class TYPE>
class TWeakCopy{
public:
  TYPE&Ref;
  TWeakCopy(TYPE&Ref):Ref(Ref){}
public:
  operator TYPE(){return *Ref;}
};

union TQuad;

union TRect{
  struct{vec2d a,b;};
  struct{real ax,ay,bx,by;};
public:
  TRect(){}
  TRect(const vec2d&a,const vec2d&b):a(a),b(b){}
  TRect(const real&ax,const real&ay,const real&bx,const real&by):ax(ax),ay(ay),bx(bx),by(by){}
public:
  template<typename TYPE>operator TWeakCopy<TYPE>(){return TWeakCopy<TYPE>(TQuad(0.5*(a+b),b-a));}
public:
   TRect Norm(){return TRect(min(ax,bx),min(ay,by),max(ax,bx),max(ay,by));}
};

union TQuad{
  struct{vec2d pos,size;};
  struct{real x,y,w,h;};
public:
  TQuad(){}
  TQuad(const vec2d&pos,const vec2d&size):pos(pos),size(size){}
  TQuad(const real&x,const real&y,const real&w,const real&h):x(x),y(y),w(w),h(h){}
public:
  operator TRect(){return TRect(x-w,y-h,x+w,y+h);}
public:
  TQuad Norm(){return TQuad(x,y,abs(w),abs(h));}
  vec2d RndPoint(){return vec2d(x+RndReal(-w*0.5,+w*0.5),y+RndReal(-h*0.5,+h*0.5));}
};

inline vec2d ClampCircleToQuad(const vec2d&p,const real&r,const TQuad&q){return q.pos+vec2d(Clamp(p.x-q.x,-q.w*0.5+r,q.w*0.5-r),Clamp(p.y-q.y,-q.h*0.5+r,q.h*0.5-r));}
inline PointArray MakeQuadAABB(const vec2d&Min,const vec2d&Max){
  PointArray PA;PA.resize(4);
  PA[0]=vec2d(Min.x,Min.y);PA[1]=vec2d(Min.x,Max.y);
  PA[2]=vec2d(Max.x,Max.y);PA[3]=vec2d(Max.x,Min.y);
  return PA;
}
inline bool CD_Rect2Point(vec2d A,vec2d B,vec2d P)
{
  vec2d &p=P;vec2d a(min(A.x,B.x),min(A.y,B.y)),b(max(A.x,B.x),max(A.y,B.y));
  return InDip(a.x,p.x,b.x)&&InDip(a.y,p.y,b.y);
}
template<class TYPE>
class TWeakCopy
{
public:
  TYPE&Ref;
  TWeakCopy(TYPE&Ref):Ref(Ref) {}
public:
  operator TYPE()
  {
    return *Ref;
  }
};

//union TQuad;

union TRect
{
  struct
  {
    vec2d a,b;
  };
  struct
  {
    real ax,ay,bx,by;
  };
public:
  TRect() {}
  TRect(const vec2d&a,const vec2d&b):a(a),b(b) {}
  TRect(const real&ax,const real&ay,const real&bx,const real&by):ax(ax),ay(ay),bx(bx),by(by) {}
public:
  template<typename TYPE>operator TWeakCopy<TYPE>()
  {
    return TWeakCopy<TYPE>(TQuad(0.5*(a+b),b-a));
  }
public:
  TRect Norm()
  {
    return TRect(min(ax,bx),min(ay,by),max(ax,bx),max(ay,by));
  }
};
/*
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
};*/

//inline vec2d ClampCircleToQuad(const vec2d&p,const real&r,const TQuad&q){return q.pos+vec2d(Clamp(p.x-q.x,-q.w*0.5+r,q.w*0.5-r),Clamp(p.y-q.y,-q.h*0.5+r,q.h*0.5-r));}
inline vector<vec2d> MakeQuadAABB(const vec2d&Min,const vec2d&Max)
{
  vector<vec2d> PA;
  PA.resize(4);
  PA[0]=vec2d(Min.x,Min.y);
  PA[1]=vec2d(Min.x,Max.y);
  PA[2]=vec2d(Max.x,Max.y);
  PA[3]=vec2d(Max.x,Min.y);
  return PA;
}
inline vector<vec2i> MakeQuadAABB(const vec2i&Min,const vec2i&Max)
{
  vector<vec2i> PA;
  PA.resize(4);
  PA[0]=vec2i(Min.x,Min.y);
  PA[1]=vec2i(Min.x,Max.y);
  PA[2]=vec2i(Max.x,Max.y);
  PA[3]=vec2i(Max.x,Min.y);
  return PA;
}
inline bool CD_Rect2Point(const vec2d&A,const vec2d&B,const vec2d&P)
{
  const vec2d&p=P;
  vec2d a(min(A.x,B.x),min(A.y,B.y)),b(max(A.x,B.x),max(A.y,B.y));
  return InDip(a.x,p.x,b.x)&&InDip(a.y,p.y,b.y);
}

inline bool PointInQuad(const vec2d&point,const vec2d&pos,const vec2d&size)
{
  auto hw=abs(size.x)*0.5;
  auto hh=abs(size.y)*0.5;
  vec2d p=point-pos;
  if (abs(p.x)>hw)return false;
  if (abs(p.y)>hh)return false;
  return true;
}

inline bool CD_Segment2Segment(const vec2d&a,const vec2d&b,const vec2d&c,const vec2d&d,vec2d&out)
{
  vec2d A[5]={a,b-a,c-a,d-a,out};
  real m=A[1].Mag();
  A[2]=A[2].Rot(A[1]);
  A[3]=A[3].Rot(A[1]);
  if (Sign(A[2].y)==(Sign(A[3].y)))return false;
  A[4].x=A[2].x-(A[2].x-A[3].x)*A[2].y/(A[2].y-A[3].y);
  A[4].y=0;
  if (!InDip(0.0,A[4].x,m))return false;
  out=A[4].UnRot(A[1])+a;
  return true;
}

inline bool PointInTrigon(const vec2d&a,const vec2d&b,const vec2d&c,const vec2d&p)
{
#define F(o,a,b)bool o##a##b=(((a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x))>0);
  F(p,a,b)F(p,b,c)F(p,c,a)
#undef F
  return (pab==pbc)&&(pab==pca);
}
static bool CD_TrigonVsTrigon(const t_trigon_vec2f&a,const t_trigon_vec2f&b){
  #define F(field)int(PointInTrigon(a.field,b))
  if(int(F(a)+F(b)+F(c))%3!=0)return true;
  #undef F
  #define F(field)int(PointInTrigon(b.field,a))
  if(int(F(a)+F(b)+F(c))%3!=0)return true;
  #undef F
}
static bool PointInTrigon(const vec2d&p,const t_trigon_vec2f&t){
  return PointInTrigon(p,t.a,t.b,t.c);
}
static bool PointInTrigon(const vec2d&p,const vec2d&a,const vec2d&b,const vec2d&c){
  //
}
static bool point_in_tris(const vec2d&p,const t_trigon_vec2f&t){return point_in_tris(t,p);}
static bool point_in_tris(const vec2f&p,const t_trigon_vec2f&t){return point_in_tris(t,vec2d(p));}
static bool point_in_tris(const t_trigon_vec2f&t,const vec2d&p){
  int arr[3]={0,0,0};
  #define F(a,b)arr[int(Sign(cross(vec2d(t.b-t.a),p-vec2d(t.a)))+1)]++;
  F(a,b);F(b,c);F(c,a);
  #undef F
  if(arr[0]&&arr[2])return false;
  return true;
}
static bool CD_LineVsLine(const vec2d&a,const vec2d&b,const vec2d&c,const vec2d&d,vec2d*out=nullptr){
  auto ox=b-a;auto v=d-c;auto v_ox=v.Rot(ox);
  if(!v_ox.y)return false;
  auto d_ox=(d-a).Rot(ox);
  auto t=d_ox.y/v_ox.y;
  if(t<0||t>1)return false;
  auto px=d_ox.x-t*v_ox.x;
  if(out)*out=vec2d(px,0).UnRot(ox)+a;
  return px>0&&px<ox.Mag();
}
struct t_circle_from_points{
  real r;
  vec2d pos;
  t_circle_from_points(const t_trigon_vec2f&t){vector_view<vec2f> arr;arr.p=&t.a;arr.n=3;calc(arr);}
  t_circle_from_points(const t_quad&q){auto qp=q.get_points();vector_view<vec2d> arr;arr.p=&qp.a;arr.n=4;calc(arr);}
  template<class T>
  void calc(const vector_view<T>&arr){
    pos=vec2d(0,0);QAP_FOREACH(arr,pos+=ex);pos*=1.0/arr.size();
    auto id=QAP_MINVAL_ID_OF_VEC(arr,-(vec2d(ex)-pos).SqrMag());
    r=(vec2d(arr[id])-pos).Mag();
  }
};
static bool CD_TrigonVsQuad_slow(const t_trigon_vec2f&t,const t_quad&q){
  #define F(a)if(point_in_quad(t.a,q))return true;
  F(a);F(b);F(c);
  #undef F
  auto qp=q.get_points();
  #define F(a)if(point_in_tris(qp.a,t))return true;
  F(a);F(b);F(c);F(d);
  #undef F
  #define U(qa,qb,ta,tb)if(CD_LineVsLine(qp.qa,qp.qb,t.ta,t.tb))return true;
  #define F(qa,qb)U(qa,qb,a,b);U(qa,qb,b,c);U(qa,qb,c,a);
  F(a,b);F(b,c);F(c,d);F(d,a);
  #undef F
  #undef U
  return false;
}
static bool CD_TrigonVsQuad(const t_trigon_vec2f&t,const t_quad&q){
  auto tc=t_circle_from_points(t);
  auto qc=t_circle_from_points(q);
  auto m=(tc.pos-qc.pos).Mag();
  if(m>(tc.r+qc.r))return false;
  return CD_TrigonVsQuad_slow(t,q);
}
template<class TYPE>static TYPE sqr(TYPE x){return x*x;}

static bool CD_TrigonVsQuad(const t_trigon_vec2f_with_circle&t,const t_quad&q,real qr){
  auto mm=t.p.sqr_dist_to(q.pos);
  if(mm>sqr(t.r+qr))return false;
  return CD_TrigonVsQuad_slow(t,q);
}
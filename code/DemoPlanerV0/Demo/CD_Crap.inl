//it is only a draft
static bool CD_CircleAndWall(const vec2d&pos,vec2d&v,const real&r,const vec2d&a,const vec2d&b){
  if(abs((pos-a).Rot(b-a).y)>r)return false;
  if((pos-a).Rot(b-a).x<0)return false;
  if((pos-a).Rot(b-a).x>(b-a).Mag())return false;
  if(Sign(v.Rot(b-a).y)==Sign((pos-a).Rot(b-a).y))return false;
  v=vec2d(v.Rot(b-a).x,-v.Rot(b-a).y).UnRot(b-a);return true;
}

//it is only a draft
static bool CD_CircleAndWallCircle(const vec2d&pos,vec2d&v,const real&d,const vec2d&a){
  if((pos-a).Mag()>d)return false;
  if(v.Rot(pos-a).x>0)return false;
  v=vec2d(-v.Rot(pos-a).x,v.Rot(pos-a).y).UnRot(pos-a);
  return true;
}

static bool FastCD_CircleAndWallCircle(const vec2d&pos,vec2d&v,const real&r,const vec2d&a){
  if(pos.dist_to_point_more_that_r(a,r))return false;
  if(v.Rot(pos-a).x>0)return false;
  v=vec2d(-v.Rot(pos-a).x,v.Rot(pos-a).y).UnRot(pos-a);
  return true;
}

static bool FastCD_CircleAndWallWithCircles(const vec2d&pos,vec2d&v,const real&r,const vec2d&a,const vec2d&b)
{
  vec2d c=(a+b)*0.5;
  if(c.sqr_dist_to(pos)>b.sqr_dist_to(a))return false;
  bool has_cd=false;
  has_cd=has_cd||CD_CircleAndWall(pos,v,r,a,b);
  has_cd=has_cd||FastCD_CircleAndWallCircle(pos,v,r,a);
  has_cd=has_cd||FastCD_CircleAndWallCircle(pos,v,r,b);
  return has_cd;
}

static bool WithoutV_CD_CircleAndWall(const vec2d&pos,const real&r,const vec2d&a,const vec2d&b){
  if(abs((pos-a).Rot(b-a).y)>r)return false;
  if((pos-a).Rot(b-a).x<0)return false;
  if((pos-a).Rot(b-a).x>(b-a).Mag())return false;
  return true;
}

static bool WithoutV_FastCD_CircleAndWallCircle(const vec2d&pos,const real&r,const vec2d&a){
  if(pos.dist_to_point_more_that_r(a,r))return false;
  return true;
}

static bool WithoutV_FastCD_CircleAndWallWithCircles(const vec2d&pos,const real&r,const vec2d&a,const vec2d&b)
{
  //vec2d c=(a+b)*0.5;
  //if(c.sqr_dist_to(pos)>b.sqr_dist_to(a))return false;
  bool has_cd=false;
  has_cd=has_cd||WithoutV_CD_CircleAndWall(pos,r,a,b);
  has_cd=has_cd||WithoutV_FastCD_CircleAndWallCircle(pos,r,a);
  has_cd=has_cd||WithoutV_FastCD_CircleAndWallCircle(pos,r,b);
  return has_cd;
}

static vec3d to_vec3d(const QapColor&c){return vec3d(c.r,c.g,c.b)*(1.0/255.0);}
static vec3d vec3d_pow(const vec3d&c,real v){return vec3d(pow(c.x,v),pow(c.y,v),pow(c.z,v));}
struct t_lights_rays_color{
  int n;
  vec3d c;
  t_lights_rays_color():n(0),c(vec3d(0,0,0)){}
  vec3d avg()const{return !n?c:c*(1.0/n);}
  void add(const t_lights_rays_color&ref){n+=ref.n;c+=ref.c;}
};

#define LIST(F)F(version)F(size)F(x)F(y)F(raw_wins)
#define F(var)int var;
struct t_pix_info{LIST(F);t_lights_rays_color frag,only_details,simple_frag;real ms;};
#undef F
#undef LIST

inline float fast_raycast_to_trigon(vec3f pos,int tris_id,int dir_id){
  t_raypoint nope;
  auto dir=env.dirs[dir_id];
  auto&tris=env.tris[tris_id];
  #define F(a)auto&a=tris.a;
  F(a);F(oy);F(oz);F(ox);F(A);F(B);F(C);
  #undef F
  auto py=dot(oy,pos-tris.a);
  auto inv_dy=tris.dir2inv_dy[dir_id];//auto dy=dot(oy,dir);
  if(!inv_dy)return -1;
  auto dist=-py*inv_dy;
  if(dist<0)return -1;
  auto point=pos+(dir*dist);
  #define F(A,a)auto A=vec2f(dot(ox,a),dot(oz,a));
  /*F(A,a);F(B,b);F(C,c);*/F(P,point);
  #undef F
  int t[3]={0,0,0};
  #define F(A,B)t[int(Sign(cross(B-A,P-A))+1)]++;
  F(A,B);F(B,C);F(C,A);
  #undef F
  if(t[0]&&t[2])return -1;
  return dist;
}
struct t_fast_raycast_out{float t;int id;};

//old fast_do_raycast_v3
t_lights_rays_color get_lights_rays_color_in(vec3f pos,int dir_id,int from_tris_id)
{
  t_lights_rays_color out;
  t_fast_raycast_out first_dtris={-1,-1};
  auto arr=env.dir2light[dir_id].safe_get(pos);
  bool ff_passed=false;
  for(int i=0;i<arr.size();i++)
  {
    int tris_id=arr[i];
    t_fast_raycast_out rp={fast_raycast_to_trigon(pos,tris_id,dir_id),tris_id};
    if(rp.t<0)continue;
    if(bool need_find_first_dtris=!ff_passed&&first_dtris.t<0)
    {
      ff_passed=true;
      auto&darr=env.dir2info[dir_id].safe_get(pos);
      for(int i=0;i<darr.size();i++)
      {
        int dtris_id=darr[i];
        if(from_tris_id==dtris_id)continue;
        QapAssert(!is_light(dtris_id));
        t_fast_raycast_out rp={fast_raycast_to_trigon(pos,dtris_id,dir_id),dtris_id};
        if(rp.t<0)continue;
        if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
        first_dtris=rp;
      }
    }
    if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
    out.c+=to_vec3d(env.tris_colors[rp.id]);
    out.n++;
  }
  return out;
}
t_lights_rays_color fast_do_raycast_v4(const vec3f&pos,int dir_id,int&end_tris_id,vec3f&end_pos)
{
  end_tris_id=-1;
  t_lights_rays_color out;
  t_fast_raycast_out first_dtris={-1,-1};
  auto arr=env.dir2light[dir_id].safe_get(pos);

  if(bool need_find_first_dtris=true)
  {
    auto&darr=env.dir2info[dir_id].safe_get(pos);
    for(int i=0;i<darr.size();i++)
    {
      int dtris_id=darr[i];
      QapAssert(!is_light(dtris_id));
      t_fast_raycast_out rp={fast_raycast_to_trigon(pos,dtris_id,dir_id),dtris_id};
      if(rp.t<0)continue;
      if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
      first_dtris=rp;
    }
    if(first_dtris.id>=0){
      end_tris_id=first_dtris.id;
      //QapAssert(!is_light(first_dtris.id));
      end_pos=pos+env.dirs[dir_id]*first_dtris.t;
      //out.c+=to_vec3d(env.tris_colors[first_dtris.id]);
      //out.n++;
    }
  }
  for(int i=0;i<arr.size();i++)
  {
    int tris_id=arr[i];
    t_fast_raycast_out rp={fast_raycast_to_trigon(pos,tris_id,dir_id),tris_id};
    if(rp.t<0)continue;
    if(first_dtris.t>0&&first_dtris.t<=rp.t)continue;
    out.c+=to_vec3d(env.tris_colors[rp.id]);
    out.n++;
  }
  return out;
}
static bool segment_axis_line_projection_ray_point(const vec2d&n,real zn,const vec2d&pos,const vec2d&p,vec2d*out=nullptr){
  auto ox=n.Ort();auto a=pos+n*zn;auto d=p;auto c=pos;
  auto v=d-c;
  auto v_ox=v.Rot(ox);
  if(!v_ox.y)return false;
  auto d_ox=(d-a).Rot(ox);
  auto t=d_ox.y/v_ox.y;
  if(t<0||t>1)return false;
  return true;
  //auto px=d_ox.x-t*v_ox.x;
  //if(out)*out=vec2d(px,0).UnRot(ox)+a;
  //return px>0&&px<ox.Mag();
}
struct t_camplane{
  vec3f pos;// pos=campos+dir*zn;
  t_axis axis;
  vec3f get_vec3f(const vec3f&p){
    auto v=axis.get_vec3f(p-pos);
    //if(v.z<0)return false;
    //CD_LineVsLine(pos,p,vec2d(0,h)*0.5);
    //v.get_xy_as_vec2f()*vz;
  }
};
static inline t_raypoint raycast_to_trigon(const vec3f&pos,const vec3f&dir,const vec3f&a,const vec3f&b,const vec3f&c){
  //auto&cross=cross;auto&dot=dot;
  t_raypoint nope;
  auto center=a;//(a+b+c)*(1.0/3.0);
  auto n=cross(b-a,c-a).Norm();
  if(dot(n,dir)<0)return nope;
  auto oy=-n;
  auto oz=cross(dir,n).Norm();
  auto ox=cross(oz,n).Norm();
  auto py=dot(oy,pos-center);
  auto dy=dot(oy,dir);
  if(!dy)return nope;
  if(py/dy>0)return nope;
  auto point=pos-(dir*(py/dy));
  #define F(A,a)auto A=vec2d(dot(ox,a),dot(oz,a));
  F(A,a);F(B,b);F(C,c);F(P,point);
  #undef F
  int t[3]={0,0,0};
  #define F(A,B)t[int(Sign(cross(B-A,P-A))+1)]++;
  F(A,B);F(B,C);F(C,A);
  #undef F
  if(t[0]&&t[2])return nope;
  t_raypoint out;out.pos=point;out.n=n;out.t=fabs(py/dy);
  return out;
}
t_raypoint do_raycast_fixed(const t_photon&inp,int*tris_id=nullptr)
{
  t_raypoint out;
  auto dir=inp.dir;
  auto pos=inp.pos;
  auto&arr=env.trigons;
  for(int i=0;i<arr.size();i++)
  {
    auto&t=arr[i];
    auto rp=raycast_to_trigon(pos,dir,t.a,t.b,t.c);
    if(rp.t<0)continue;
    if(out.t>0&&out.t<rp.t)continue;
    out=rp;
    out.c=env.tris_colors[i];
    if(tris_id)*tris_id=i;
  }
  return out;
}
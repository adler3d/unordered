static vec2d world_to_map(const t_map&map,const vec2d&pos){
  real block_size=get_block_size();
  vec2d map_offset=vec2d(map.w,map.h)*block_size*0.5+vec2d(1,1)*0.5*block_size;
  return (map_offset+pos)*(1.0/block_size);
}
static vec2d map_to_world(const t_map&map,const vec2d&pos){
  real block_size=get_block_size();
  vec2d map_offset=vec2d(map.w,map.h)*block_size*0.5;
  return pos*block_size-map_offset;
};
struct t_col_solver_result{
  int n;
  int n50;
  int n5F;
  vec2i p;
};
static t_col_solver_result solve_col_unit_vs_map(t_map&map,vec2d&unit_pos,int r,int allow_5F)
{
  t_col_solver_result out={0,0,0,vec2i(0,0)};
  auto&cd=out.n;auto&cell_on_map=out.p;
  real block_size=get_block_size();
  auto mp=tovec2i(world_to_map(map,unit_pos));
  vec2i arr[9]={
    vec2i(-1,-1),vec2i(+0,-1),vec2i(+1,-1),
    vec2i(-1,+0),vec2i(+0,+0),vec2i(+1,+0),
    vec2i(-1,+1),vec2i(+0,+1),vec2i(+1,+1)
  };
  auto p2op_solver=[&cd,&cell_on_map](const vec2i&com,vec2d&pos,const vec2d&op,real dist)->bool{
    auto wu=pos-op;
    auto m=wu.Mag();
    if(m<dist)
    {
      auto dv=wu.SetMag(dist);
      pos=op+dv;
      cd++;
      cell_on_map=com;
      return true;
    }
    return false;
  };
  auto c=r+block_size*0.5;int n50=0;int n5F=0;
  for(int i=0;i<9;i++)
  {
    auto p=mp+arr[i];
    auto mgpv=map.get(p);
    auto inc_50=mgpv==0x50;
    auto inc_5F=allow_5F?mgpv==0x5F:false;
    if(!inc_50&&!inc_5F)continue;
    if(inc_50)n50++;if(inc_5F)n5F++;
    auto wp=map_to_world(map,p);
    p2op_solver(p,unit_pos,wp,c);
    auto sc=r+block_size*0.25;
    auto n=vec2d(1,1)*block_size*0.25;
    for(int i=0;i<4;i++){p2op_solver(p,unit_pos,wp+n,sc);n=n.Ort();}
  }
  if(n50+n5F<2)return out;
  auto m2w=[&](const vec2d&p){return map_to_world(map,vec2d(int(p.x),int(p.y)));};
  auto f=[&](const vec2d&a,const vec2d&b){return (m2w(a)+m2w(b))*0.5;};
  auto mgp=[&](const vec2i&p)->bool{auto v=map.get(p);return allow_5F?v==0x50||v==0x5F:v==0x50;};
  for(int y=0;y<3;y++){
    auto p0=mp+arr[y*3+0];auto f0=mgp(p0);
    auto p1=mp+arr[y*3+1];auto f1=mgp(p1);
    auto p2=mp+arr[y*3+2];auto f2=mgp(p2);
    if(f0&&f1)p2op_solver(p0,unit_pos,f(p0,p1),c);
    if(f1&&f2)p2op_solver(p1,unit_pos,f(p1,p2),c);
  }
  for(int x=0;x<3;x++){
    auto p0=mp+arr[x+0*3];auto f0=mgp(p0);
    auto p1=mp+arr[x+1*3];auto f1=mgp(p1);
    auto p2=mp+arr[x+2*3];auto f2=mgp(p2);
    if(f0&&f1)p2op_solver(p0,unit_pos,f(p0,p1),c);
    if(f1&&f2)p2op_solver(p1,unit_pos,f(p1,p2),c);
  }
  return out;
}
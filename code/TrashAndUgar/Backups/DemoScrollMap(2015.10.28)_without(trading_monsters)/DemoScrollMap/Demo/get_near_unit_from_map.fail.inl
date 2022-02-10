vector<int> get_units_from_map_around_point(const vec2d&pos,real dist)
{
  vector<int> out;
  auto mc=tovec2i(world_to_map(map,pos));
  if(!map.check(mc))return out;
  auto n=1+dist/real(get_block_size());int c=0;
  for(int y=-n;y<=+n;y++)for(int x=-n;x<=+n;x++)
  {
    auto p=mc+vec2i(x,y);c++;
    if(!map.check(p))continue;
    auto&a=map_uni.get_unsafe(p.x,p.y);
    for(int i=0;i<a.size();i++){
      out.push_back(a[i]);
    }
  }
  int gg=1;
  return out;
}
t_unit*get_near_unit_from_map(const vec2d&pos,real dist)
{
  auto arr=get_units_from_map_around_point(pos,dist);
  if(arr.empty())return nullptr;
  int id=-1;
  real d=-1;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=units[arr[i]];
    if(ex.deaded)continue;
    auto m=(ex.pos-pos).SqrMag();
    if(id>=0&&m>=d)continue;
    d=m;id=i;
  }
  return id<0?nullptr:&units[arr[id]];
}
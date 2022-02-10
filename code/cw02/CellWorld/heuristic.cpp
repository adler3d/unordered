
struct cell_point{
  int x;
  int y;
  unsigned type;
};

struct map_frag{
  vector<cell_point> cells;
  int result;
};

struct t_heuristic{};
struct t_some_class{
  vector<int> celltypes;
  vector<cell_point> arr;
  void inc_type(bool&overflow,unsigned&type)
  {
    result=type==celltypes.back();
    for(int i=0;i<celltype.size();i++)if(celltypes[i]==type)type=celltypes[(i+1)%celltype.size()];
  }
  void inc(bool&overflow)
  {
    overflow=false;
    for(int i=0;i<arr.size();i++)
    {
      bool flag=false;
      inc_type(flag,arr[i].type);
      if(!flag)return;
    }
    result=true;
  }
};

int main()
{
  man.addrule(from[0],to[0]);
  man.addrule(from[1],to[1]);
  man.addrule(from[2],to[2]);
  man.compile();
  t_rule_heuristic h;
  t_rule_analyzer ra;
  vector<int> celltypes;
  vector<vec2i> affected_map;
  vec2i cur_point={0,0};
  for(;;)
  {
    rule->eval(proxy,result);// => affected_map.add(x[i],y[i]);
    inc_map(affected_map);
  }
}
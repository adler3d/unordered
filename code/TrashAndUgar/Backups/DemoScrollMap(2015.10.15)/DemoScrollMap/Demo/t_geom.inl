struct t_geom{
  vector<vec2d> VA;
  vector<int> IA;
  void AddTris(int a,int b,int c)
  {
    qap_add_back(IA)=a;
    qap_add_back(IA)=b;
    qap_add_back(IA)=c;
  }
};
t_geom GenGeomCircleSolid(real r,int seg,real ang)
{
  t_geom geom;
  int n=seg;
  if(n<=0)return t_geom();
  for(int i=0;i<n;i++)
  {
    vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
    qap_add_back(geom.VA)=v*r;
  }
  for(int i=2;i<n;i++)
  {
    geom.AddTris(0,i-1,i);
  }
  return geom;
}
t_geom GenGeomCircleEx(real r0,real r1,int seg,real ang)
{
  t_geom geom;
  int n=seg;
  if(n<=0)return t_geom();
  geom.VA.resize(n*2);
  for(int i=0;i<n;i++)
  {
    vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
    geom.VA[i+0]=v*r0;
    geom.VA[i+n]=v*r1;
  }
  for(int i=0;i<n;i++)
  {
    int a=0+(i+0)%n;
    int b=0+(i+1)%n;
    int c=n+(i+0)%n;
    int d=n+(i+1)%n;
    geom.AddTris(a,b,d);
    geom.AddTris(d,c,a);
  }
  return geom;
}
void DrawGeomWithOffset(t_geom&geom,const vec2d&pos)
{
  QapDev::BatchScope Scope(qDev);
  auto vpos=qDev.VPos;
  for(int i=0;i<geom.VA.size();i++)
  {
    auto&ex=geom.VA[i];
    //auto&v=qDev.AddVertexRaw();
    //v.get_pos()=pos+ex;
    //v.color=qDev.color;
    qDev.AddVertex(pos+ex,qDev.color,0,0);
  }
  QapAssert(0==geom.IA.size()%3);
  auto&IA=geom.IA;
  for(int i=0;i<IA.size();i+=3)
  {
    auto&a=IA[i+0];
    auto&b=IA[i+1];
    auto&c=IA[i+2];
    qDev.AddTris(vpos+a,vpos+b,vpos+c);
  }
}
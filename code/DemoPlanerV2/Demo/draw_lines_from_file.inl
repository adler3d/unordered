void sim_line(const string&s="ASA",const int n=32){sim_line(vec2d_zero,vec2d(1,0),s,n);}
void sim_line(const vec2d&p,const vec2d&v,const string&s="ASA",const int n=32)
{
  string cmds=join(split(s,"\n"),"");
  vector<vec2d> arr;
  t_obj obj;obj.pos=p;obj.v=v;
  for(int i=0;i<cmds.size();i++){
    auto cmd=char2v(cmds[i]);
    for(int iter=0;iter<n;iter++){
      obj.a=obj.wasd2a(cmd);
      obj.move();
      qap_add_back(arr)=obj.pos;
    }
  }
  qDev.DrawPolyLine(arr,4,false);
}
void DrawLinesFromFile(bool draw_asn=true,const char*pnums="")
{
  QapColor colors[]={0xff880000,0xff008800,0xff000088};
  static string nums=pnums;//"1096";//"1096,1582";
  static vector<string> lines;
  static bool once=true;
  if(once)
  {
    once=false;
    auto arr=split(nums,",");
    for(int i=0;i<arr.size();i++)qap_add_back(lines)=file_get_contents(get_path()+arr[i]+".txt");
  }
  for(int i=0;i<lines.size();i++){
    qDev.color=colors[i%lines.size()];sim_line(lines[i],1);
  }
  if(!draw_asn)return;
  qDev.color=0xff000000;sim_line(obj.pos,obj.v,"A",64);
  qDev.color=0xff000000;sim_line(obj.pos,obj.v,"S",64);
  qDev.color=0xff000000;sim_line(obj.pos,obj.v,"N",64);
}
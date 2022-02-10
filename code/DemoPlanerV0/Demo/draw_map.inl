static vec2i vec2d_round(vec2d p,vec2d dir){
  vec2i r;r.x=p.x;r.y=p.y;
  if(dir.x>0)if(real(r.x)!=p.x)r.x++;if(dir.y>0)if(real(r.y)!=p.y)r.y++;return r;
}

static vec2d char2v(char c){
  vec2d cmd;
  if(c=='A')cmd.x=+1;
  if(c=='S')cmd.x=-1;
  if(c=='N')cmd.x=0;
  if(c==1)cmd.x=+1;
  if(c==2)cmd.x=-1;
  if(c==0)cmd.x=0;
  return cmd;
}
static char v2char(const vec2d&v){
  QapAssert(v.y==0);
  if(v.x>0)return 'A';
  if(v.x<0)return 'S';
  return 'N';
}
static int v2int(const vec2d&v){
  QapAssert(v.y==0);
  if(v.x>0)return 1;
  if(v.x<0)return 2;
  return 0;
}

struct t_soft_lineloop{
  static void calc_points(real half_line_size,const vec2d&a,const vec2d&b,real koef,vec2d&pa,vec2d&pb)
  {
    vec2d ab=b-a;
    vec2d ab_ort=ab.Ort().SetMag(half_line_size*Sign(koef));
    pa=a+ab_ort;
    pb=b+ab_ort;
  }
  static void calc_points(real half_line_size,const vec2d&a,const vec2d&b,real koef,vec2d*pa,vec2d*pb)
  {
    vec2d ab=b-a;
    vec2d ab_ort=ab.Ort().SetMag(half_line_size*Sign(koef));
    if(pa)*pa=a+ab_ort;
    if(pb)*pb=b+ab_ort;
  }
  static void DrawTris(QapDev&qDev,const vector<vec2d>&arr,real half_line_size,bool loop)
  {
    QapDev::BatchScope Scope(qDev);
    real hls=half_line_size;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
      auto&ex=arr[i];
      {
        vec2d a=arr[(i+n-1)%n];
        vec2d o=arr[(i+n-0)%n];
        vec2d b=arr[(i+n+1)%n];
        vec2d ao_p0;
        vec2d ao_p1;
        vec2d ob_p0;
        vec2d ob_p1;
        real k=vec2d_cross(b-o,o-a);
        calc_points(hls,a,o,k,ao_p0,ao_p1);
        calc_points(hls,o,b,k,ob_p0,ob_p1);
        vec2d p;
        auto ends=!i||i+1==n;
        if(!loop&&ends)continue;
        qDev.DrawTrigon(o,ao_p1,ob_p0);
      }
    }
  }
};
//void sim_line(const string&s="ASA",const int n=32){sim_line(vec2d_zero,vec2d(1,0),s,n);}
void sim_line(const t_full_genome&ref,const int n=32)
{
  if(!qap_check_id(wave_sources,ref.id))return;
  auto&obj=wave_sources[ref.id];
  sim_line(obj,tostr(ref.arr),n);
}
void sim_line(const t_obj&src,const string&s="ASA",const int n=32)
{
  string cmds=join(split(s,"\n"),"");
  vector<vec2d> arr;
  t_obj obj=src;
  for(int i=0;i<s.size();i++){
    auto cmd=char2v(cmds[i]);
    for(int iter=0;iter<n;iter++){
      obj.a=cmd.x;
      obj.move();
      qap_add_back(arr)=obj.pos;
    }
  }
  qDev.DrawPolyLine(arr,line_size(),false);
  //t_soft_lineloop::DrawTris(qDev,arr,line_size()*0.5,false);
  if(show_near_point)if(!arr.empty())
  {
    auto mp=s2w(mpos);
    auto id=QAP_MINVAL_ID_OF_VEC(arr,ex.dist_to(mp));
    qDev.color=0xFFFFFFFF;
    qDev.DrawQuad(arr[id],10,10);
  }
  if(status.find("seg.p = ")!=string::npos){
    int p=SToI(get_first_part(get_second_part(status,"seg.p = ")," "));
    int e=p+SToI(get_first_part(get_second_part(status,"seg.n = ")," "));
    qDev.color=0xFF00FF00;
    if(qap_check_id(arr,p))draw_black_green_point(arr[p]);
    if(qap_check_id(arr,e))draw_black_green_point(arr[e]);
  }
}
void draw_black_green_point(const vec2d&pos){
  qDev.color=0xFF000000;qDev.DrawQuad(pos,10,10);
  qDev.color=0xFF00FF00;qDev.DrawQuad(pos,6,6);
}
#if(0)
struct t_result_estimate{
  float value;
  int iter;
};

t_result_estimate estimate(const vec2d&p,const vec2d&v,const vector<char>&arr,const int n=1)
{
  t_result_estimate retval={0,0};
  static auto r=get_block_size();t_quad q;q.pos=target_point;q.size=vec2d(r,r);
  t_obj obj;obj.pos=p;obj.v=v;
  int cost=0;
  for(int i=0;i<arr.size();i++)
  {
    if(qap_check_id(arr,i))obj.a=obj.wasd2a(char2v(arr[i]));
    for(int iter=0;iter<n;iter++)
    {
      bool ok=sim_step(obj);
      if(!ok)
      {
        retval.value=cost-1e8-(obj.pos.dist_to(target_point)*0.1/r)*1024;
        return retval;
      }
      if(point_in_quad(q,obj.pos))
      {
        retval.value=cost-(obj.pos.dist_to(target_point)*0.5/q.size.Mag());
        return retval;
      }
      cost--;
    }
    retval.iter=abs(cost);
  }
  retval.value=cost-1e9-(obj.pos.dist_to(target_point)*0.1/r)*1024;
  return retval;
}

float dir_law(const t_obj&a,const t_obj&b){
  //QapAssert(cross(vec2d(1,0),vec2d(1,0))==0);
  //QapAssert(abs(cross(vec2d(1,0),vec2d(0,1)))>abs(cross(vec2d(1,0),vec2d(1,1).Norm())));
  return abs(a.v.Rot(b.v).GetAng())/Pi2;//1.0-abs(cross(a.v.Norm(),b.v.Norm()));
}

float estimate_with_dir(const t_obj&bef,const t_obj&aft,const vector<char>&arr,const int n=1,float dang=0.05,float maxdirbon=20)
{
  static auto r=get_block_size();
  t_obj obj=bef;
  int cost=0;
  for(int i=0;i<arr.size();i++)
  {
    auto cmd=char2v(arr[i]);
    obj.a=obj.wasd2a(cmd);
    for(int iter=0;iter<n;iter++)
    {
      bool ok=sim_step(obj);
      if(!ok)return cost-1e8-(obj.pos.dist_to(aft.pos)*0.1/r)*1024-dir_law(obj,aft)*20*1024;
      if(obj.pos.dist_to_point_less_that_r(aft.pos,1.5))if(dir_law(obj,aft)<dang){
        return cost-(obj.pos.dist_to(aft.pos)*0.1/r)-dir_law(obj,aft)*maxdirbon;
      }
      cost--;
    }
  }
  return cost-1e9-(obj.pos.dist_to(aft.pos)*0.1/r)*1024-dir_law(obj,aft)*20*1024;
}

string qap_scope(string s){return "["+s+"]";}
string pad(const string&s,int n){return string(std::max<int>(0,n-int(s.size())),' ')+s;};
string diff_vec(const Genome&A,const Genome&B){
  auto&a=A.arr;auto&b=B.arr;
  string prefix="      UP  ";
  if(a.size()!=b.size())return string(prefix.size(),' ')+qap_scope(string(std::max<int>(a.size(),b.size()),'N'));
  if(A.fitness==B.fitness)prefix=string(prefix.size(),' ');
  if(A.fitness>B.fitness)prefix="    DOWN  ";
  string out;out.resize(a.size());
  bool rewrite=true;
  for(int i=0;i<a.size();i++){auto d=a[i]-b[i];if(!d){out[i]=' ';rewrite=false;continue;}out[i]=v2char(char2v(b[i]));}
  if(rewrite){prefix="^_^"+prefix.substr(3);}
  return prefix+qap_scope(out)+"  "+pad(FToS((B.fitness-A.fitness)*100/fabs(B.fitness)),12)+"%";
}

struct t_vec_seg{int p;int n;int end()const{return p+n;}};
template<class TYPE>t_vec_seg rand_seg(const vector<TYPE>&arr){
  t_vec_seg out={0,0};
  int as=int(arr.size())-1;
  int n=rand()%as;
  if(n>=arr.size()||n<2)return out;
  int id=rand()%(arr.size()-n);
  out.p=id;out.n=n;
  return out;
};

void apply_inp_sequence(t_obj&obj,const vector_view<char>&arr,int n=steps_per_branch){
  for(int i=0;i<arr.size();i++)
  {
    auto cmd=char2v(arr[i]);
    for(int iter=0;iter<n;iter++)
    {
      obj.a=obj.wasd2a(cmd);
      bool ok=sim_step(obj);
      QapAssert(ok);
    }
  }
}
struct t_result_optimize_by_parts{
  t_vec_seg seg;
  vector<string> genomes;
};
t_result_optimize_by_parts optimize_by_parts(const vector<char>&inp,int n=steps_per_branch){
  auto seg=rand_seg(inp);
  //seg.p=0;
  //seg.n=std::min<int>(int(inp.size())-1,400);
  t_result_optimize_by_parts retval={seg};
  if(!use_opt_by_parts)return retval;
  /*int rndv=rand()%3;
  int is=inp.size()/4;is--;
  if(rndv==0){seg.p=0;seg.n=is*2;}
  if(rndv==1){seg.p=inp.size()/2;seg.n=is*2;}
  if(rndv==2){seg.p=((rand()>>2)%4)*is;seg.n=is;}*/
  //seg.n=std::min<int>(inp.size()/2,512);
  //seg.p=0;
  if(!seg.end())return retval;auto arr=inp;
  t_obj bef=obj;
  apply_inp_sequence(bef,make_view(arr,0,seg.p),n);
  t_obj aft=bef;
  apply_inp_sequence(aft,make_view(arr,seg.p,seg.n),n);
  auto target_arr=tovec(tostr(inp).substr(seg.p,seg.end()));
  auto bef_seg=tostr(inp).substr(0,seg.p);
  auto opt_seg=optimize_full(target_arr,bef,aft,n);
  auto aft_seg=tostr(inp).substr(seg.end()+1);
  if(tostr(target_arr)!=opt_seg)
  {
    qap_add_back(retval.genomes)=bef_seg+opt_seg+aft_seg;
    //opt_seg.pop_back();
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"N"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"A"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"S"+aft_seg;
    //opt_seg.pop_back();
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"NN"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"AA"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"SS"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"AN"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"SN"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"NA"+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"NS"+aft_seg;
    //opt_seg.pop_back();
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"NNN"+aft_seg;
    //opt_seg.pop_back();
    qap_add_back(retval.genomes)=bef_seg+opt_seg+"NNNN"+aft_seg;
    //
    qap_add_back(retval.genomes)=bef_seg+"N"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"A"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"S"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"NN"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"AA"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"SS"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"NNN"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"AAA"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"SSS"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"NNNN"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"AAAA"+opt_seg+aft_seg;
    qap_add_back(retval.genomes)=bef_seg+"SSSS"+opt_seg+aft_seg;
    //
    for(;;)
    {
      if(opt_seg.empty())break;
      opt_seg.pop_back();
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"N"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"A"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"S"+aft_seg;
      if(opt_seg.empty())break;opt_seg.pop_back();
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"NN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"NA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"NS"+aft_seg;
      if(opt_seg.empty())break;opt_seg.pop_back();
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"NNN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAN"+aft_seg;
      if(opt_seg.empty())break;opt_seg.pop_back();
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"NNNN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSSS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAAA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSSN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAAN"+aft_seg;
      if(opt_seg.empty())break;opt_seg.pop_back();
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"NNNNN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSSS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAAA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSSSS"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAAAA"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"SSSSSN"+aft_seg;
      qap_add_back(retval.genomes)=bef_seg+opt_seg+"AAAAAN"+aft_seg;
      break;
    };
    for(int i=0;i<retval.genomes.size();i++)retval.genomes[i]+="N";
  }//else QapNoWay();
  return retval;
}

string optimize_full(const vector<char>&inp,const t_obj&bef,const t_obj&aft,int n=steps_per_branch,bool for_by_part=true){
  GeneticAlgorithm ga;
  auto&arr=ga.arr;
  qap_add_back(arr).arr=inp;
  for(int i=0;i<2;i++){
    qap_add_back(arr).set_arr(inp).mutate();
    qap_add_back(arr).set_arr(inp).mutateTwo();
    qap_add_back(arr).set_arr(inp).mutateSoft();
  }
  for(int epoch=0;epoch<3;epoch++)
  {
    auto leader=arr[0];
    if(!epoch&&!leader.fitness)leader.fitness=(bef,aft,leader.arr,n,0.5/real(maps.size()),for_by_part?20:25);
    if(epoch)ga.breed();
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex.fitness=estimate_with_dir(bef,aft,ex.arr,n,0.5/real(maps.size()),for_by_part?20:25);
    }
    ga.deadline(6);
    if(ga.arr[0].arr!=leader.arr)
    {
      qap_add_back(ga.arr)=leader;
      ga.sort();
    }
    leader=ga.arr[0];
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];auto d=abs(ex.fitness)+n;
      if(ex.arr.size()*n>d)ex.arr.resize(1+d/n);
    }
  }
  ga.deadline(1);
  return tostr(ga.arr[0].arr);
}

#define DEBUG_CODE(A);
string optimize(const vector<char>&inp,int n=steps_per_branch){
  GeneticAlgorithm ga;
  auto&arr=ga.arr;
  qap_add_back(arr).arr=inp;{auto&ex=arr.back();ex.fitness=estimate(obj.pos,obj.v,ex.arr,n).value;}
  if(use_genomes&&genomes.size()&&(genomes[0]==tostr(inp)))
  {
    for(int i=1;i<genomes.size();i++)qap_add_back(arr).arr=tovec(genomes[i]);
    /*if(arr.size()<6)for(int i=0;i<2;i++)
    {
      qap_add_back(arr).set_arr(inp).mutate();
      qap_add_back(arr).set_arr(inp).mutateTwo();
      qap_add_back(arr).set_arr(inp).mutateSoft();
    }*/
  }
  if(inp!=tovec(optimized_path_bef)){
    qap_add_back(arr).arr=tovec(optimized_path_bef);
    {auto&ex=arr.back();ex.fitness=estimate(obj.pos,obj.v,ex.arr,n).value;}
  }
  auto obp=optimize_by_parts(inp,n);
  if(use_opt_by_parts){
    for(int i=0;i<obp.genomes.size();i++){
      qap_add_back(arr).arr=tovec(obp.genomes[i]);
      {auto&ex=arr.back();ex.fitness=estimate(obj.pos,obj.v,ex.arr,n).value;}
    }
  }
  if(!use_genomes&&obp.genomes.size())
  {
    auto leader=arr[0];
    ga.sort();
    if(qap_find_val(obp.genomes,tostr(arr[0].arr)).size())if(arr[0].fitness>leader.fitness)
    {
      status="["+cur_date_str()+"] seg.p = "+IToS(obp.seg.p)+"   seg.n = "+IToS(obp.seg.n)+"   profit:"+FToS(abs(arr[0].fitness-leader.fitness));
      if(auto_disable_path_optimization)path_optimization=false;
    }
    arr[0].arr.resize(std::min<int>(estimate(obj.pos,obj.v,arr[0].arr,n).iter+1,arr[0].arr.size()));
    return tostr(arr[0].arr);
  }
  DEBUG_CODE(vector<string> reports;);
  for(int epoch=0;epoch<1;epoch++)
  {
    auto leader=arr[0];
    if(!epoch&&!leader.fitness)leader.fitness=estimate(obj.pos,obj.v,leader.arr,n).value;
    if(epoch||use_genomes)ga.breed();
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex.fitness=estimate(obj.pos,obj.v,ex.arr,n).value;
    }
    ga.deadline(6);
    if(ga.arr[0].arr!=leader.arr)
    {
      qap_add_back(ga.arr)=leader;
      ga.sort();
    }
    DEBUG_CODE(
      auto report=diff_vec(leader,ga.arr[0]);
      qap_add_back(reports)=report;
    );
    leader=ga.arr[0];
    /*for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];auto d=abs(ex.fitness)+n;
      if(ex.arr.size()*n>d)ex.arr.resize(1+d/n);
    }*/
  }
  DEBUG_CODE(
  auto s=join(reports,"\n");
  );
  ga.deadline(6);
  if(use_genomes){genomes.clear();for(int i=0;i<arr.size();i++)qap_add_back(genomes)=tostr(arr[i].arr);}
  arr[0].arr.resize(std::min<int>(estimate(obj.pos,obj.v,arr[0].arr,n).iter+1,arr[0].arr.size()));
  return tostr(arr[0].arr);
}
#endif

static vec2i tovec2i(vec2d p){return vec2i(p.x,p.y);}
string tostr(const vector<char>&ref){string out;out.resize(ref.size());for(int i=0;i<out.size();i++)out[i]=ref[i];return out;}
vector<char> tovec(const string&ref){vector<char> out;out.resize(ref.size());for(int i=0;i<out.size();i++)out[i]=ref[i];return out;}

void draw_dirway_from_strs(int spb=1)
{
  if(kb.OnDown('Y'))inv(auto_disable_path_optimization);
  if(kb.OnDown('B'))inv(show_both_path);
  if(kb.OnDown('V')){
    optimized_path_aft=optimized_path_bef;
    genomes.clear();
  }
  if(path_optimization||show_both_path)
  {
    qDev.color=0xA0FF8100;
    //auto tmp=tovec(optimized_path_aft);
    vec2d dir=s2w(mpos)-target_point;
    //t_obj aft=obj;aft.v=get_map_normdir(dir.SetMag(obj.get_v().Mag()));aft.pos=target_point;
    //if(path_optimization)optimized_path_aft=show_dir_way?optimize_full(tmp,obj,aft,spb,false):optimize(tmp,spb);
    sim_line(optimized_path_aft,spb);
  }
  if(!show_dir_way)if(!path_optimization||show_both_path)
  {
    qDev.color=0x80FF0000;
    sim_line(optimized_path_bef,spb);
  }
}
void draw_dirway()
{
  const int spb=1;
  auto block_size=get_block_size();
  qDev.color=0x80008000;
  qDev.DrawQuad(target_point,block_size*0.99*vec2d(1,1));
  auto base=target_point;
  vec2d dir=s2w(mpos)-target_point;
  {
    auto&map=get_pnodemaps(dir);
    auto cc=map.world_to_cell(target_point);
    //auto minid=qap_minval_id_for_vec(pnodemaps,[&](t_map_of_pnode&ex){return ex.get(cc)->t;});
    auto minid=QAP_MINVAL_ID_OF_VEC(pnodemaps,ex.get(cc)?maps[i].get(cc):1e6);
    if(minid>=0)if(auto pnode=pnodemaps[minid].get(cc))
    {
      auto tmp=full_genome(pnode,spb==1?steps_per_branch:1);
      path_length=tmp.arr.size();
      if(show_dir_way){
        qDev.color=0x80FF0000;
        sim_line(tmp,spb);
      }else{
        if(optimized_path_bef!=tmp){optimized_path_aft=tmp;optimized_path_bef=tmp;}
      }
    }
    draw_dirway_from_strs(spb);
    if(show_dir_way)if(auto pnode=map.get(cc)){
      auto tmp=full_genome(pnode,spb==1?steps_per_branch:1);
      if(optimized_path_bef!=tmp){optimized_path_aft=tmp;optimized_path_bef=tmp;}
      qDev.color=0x80004000;sim_line(tmp,spb!=1?steps_per_branch:1);
    }
  }
  qDev.color=0xff000000;
  if(show_dir_way)
  {
    int rays=1024;
    for(int i=0;i<rays;i++){
      auto v=Vec2dEx(i*Pi2/real(rays),100);
      if(get_map_id(v)!=get_map_id(dir))continue;
      qDev.DrawLine(base,base+v,1);
    }
  }
}
void draw_map()
{
  draw_map_impl();
  draw_dirway();
}
QapTex sys_res_qt;QapDev sys_res_qd;
t_map_of_ways&get_visibled_map()
{
  #define F(FLAG,MAP)if(FLAG)return MAP;
  F(show_layersmap,layersmap);
  F(show_cdlinemap,cdlinedev.map);
  F(show_wavemap,wavemap);
  F(show_pixmap,pixmap);
  #undef F
  return map;
}
struct TClipper{
  struct t_rect{
    vec2d a;
    vec2d b;
    void norm(){
      if(a.x>b.x)std::swap(a.x,b.x);
      if(a.y>b.y)std::swap(a.y,b.y);
    }
    vec2i clamp(const vec2i&ref){return vec2i(Clamp<int>(ref.x,a.x,b.x),Clamp<int>(ref.y,a.y,b.y));}
    vec2d clamp(const vec2d&ref){return vec2i(Clamp<real>(ref.x,a.x,b.x),Clamp<real>(ref.y,a.y,b.y));}
    static real unlerp(real a,real b,real v){auto out=(v-a)/(b-a);/*QapAssert(out>=0&&out<=1.0);*/return out;}
    vec2d unlerp(const vec2i&v){return vec2d(unlerp(a.x,b.x,v.x),unlerp(a.y,b.y,v.y));}
    vec2d unlerp(const vec2d&v){return vec2d(unlerp(a.x,b.x,v.x),unlerp(a.y,b.y,v.y));}
  };
  struct t_quad{
    vec2d pos;
    vec2d size;
  };
  QapDev&qDev;
  vec2d pos;
  vec2d size;
  vec2d c_pos;
  vec2d c_size;
  static t_rect get_rect(const t_quad&ref){t_rect t={ref.pos-ref.size*0.5,ref.pos+ref.size*0.5};return t;}
  //static t_rect get_quad(const t_quad&ref){t_rect t={ref.pos-ref.size/2,ref.pos+ref.size/2};return t;}
  void main()
  {
    t_quad qa={pos,size}; t_quad qc={c_pos,c_size};
    auto a=get_rect(qa);if(a.a.x==a.b.x)return;if(a.a.y==a.b.y)return;
    auto c=get_rect(qc);
    c.norm();
    auto na=c.clamp(a.a);
    auto nb=c.clamp(a.b);
    if(na.x==nb.x)return;
    if(na.y==nb.y)return;
    auto ta=a.unlerp(na);ta.y=1.f-ta.y;
    auto tb=a.unlerp(nb);tb.y=1.f-tb.y;
    {
      QapDev::BatchScope Scope(qDev);
      qDev.SetColor(0xffffffff);
      auto a=qDev.AddVertex(vec2d(nb.x,nb.y),qDev.color,vec2f(tb.x,tb.y));
      auto b=qDev.AddVertex(vec2d(na.x,nb.y),qDev.color,vec2f(ta.x,tb.y));
      auto c=qDev.AddVertex(vec2d(na.x,na.y),qDev.color,vec2f(ta.x,ta.y));
      auto d=qDev.AddVertex(vec2d(nb.x,na.y),qDev.color,vec2f(tb.x,ta.y));
      qDev.AddTris(a,b,c);
      qDev.AddTris(c,d,a);
    }
    //qDev.SetColor(0xff00ff00);
    //qDev.DrawRect(na,nb,4);
  }
};
void draw_map_impl()
{
  auto&map=get_visibled_map();
  auto wavemap_now=&map==&wavemap;
  //draw map
  auto block_size=map.info.block_size;
  if(!show_map)return;
  //auto&map=get_map(dir);
  vec2d offset=vec2d(map.w,map.h)*block_size*0.5;
  auto vp=viewport;
  vp.size/=scale;
  vp=vp.add_size(vec2d(1,1)*block_size*sqrt(2.0));
  vec2i imin;vec2i imax;
  {
    //vp=vp.add_size(-vec2d(1,1)*s*sqrt(2.0)*4);
    vec2d minp;vec2d maxp;
    vec2d dir=vec2d(1,1);
    for(int i=0;i<4;i++)
    {
      dir=dir.Ort();
      vec2d qvp=vec2d(vp.get_vertex_by_dir(dir)-vp.pos-vec2d(qDev.xf.p)*(1.0/scale)).Rot(qDev.xf.r.col1);
      vec2d mqc=(qvp+offset-dir*0.5*block_size)*(1.0/block_size);
      vec2i ic=vec2d_round(mqc,dir);
      //if(x==ic.x&&y==ic.y)qDev.color=0xffff0000;
      if(!i)
      {
        maxp=ic;
        minp=ic;
        continue;
      }
      vec2d::comax(maxp,ic);
      vec2d::comin(minp,ic);
    }
    imin=tovec2i(vec2d::max(vec2d_zero,minp));
    imax=tovec2i(vec2d::min(vec2d(map.w,map.h),maxp+vec2d(1,1)));
    //if(scale>1){imax+=vec2i(2,2);imin-=vec2i(2,2);}
  }
  //auto quad=qDev.GenGeomQuad(0,0,block_size,block_size);
  //int vpos=qDev.VPos;auto hbs=0.5*block_size*vec2d(qDev.xf.r.col1).Mag();
  //qDev.use_xf=false;vector<QapColor> log;
  //QapDev::Ver def;def.x=0;def.y=0;def.z=0;def.color=qDev.color;def.tu=0;def.tv=0;
  auto&qt=sys_res_qt;
  if(kb("CTRL+U")||map.w!=qt.W||map.h!=qt.H){
    qt.HardReset();
  }
  if(!qt.DynRes.pDev){
    qt.MountDev(D9Dev);
    qt.Init(map.w,map.h,1);
    qt.after_reinit=true;
    if(!qt.Tex)QapDebugMsg("No way!\ntexmap.size = "+IToS(map.w)+"x"+IToS(map.h));
  }
  if(qt.OnReinit()||(tex_auto_update&&!wavemap_now)||(tex_auto_update&&wavemap_swaped)||kb.Down(VK_MENU))if(qt.Tex)if(map.mem.size())for(;;)
  {
    //#include "old_draw_to_texture.inl"
    auto*ptr=&map.mem[0];auto mem_size=map.mem.size();
    //auto v2i=[](int i){return i;};
    auto v2i=[this](int i)->int{auto c=(*(t_cell*)&i);int v=(int)c.type;return v?(v==7?1024-cdlinedev.vecN[c.id].size():1024-v):-1;};
    int begin=-1;
    bool the_is_cdlinemap=&map==&cdlinedev.map;
    if(the_is_cdlinemap){
      for(int i=0;i<mem_size;i++){if(v2i(*ptr)>=0){begin=i;break;}ptr++;}
    }else{
      for(int i=0;i<mem_size;i++){if(*ptr>=0){begin=i;break;}ptr++;}
    }
    static const auto def_alpha=0x22;
    if(begin<0)
    {
      auto&tex=*qt.Tex;
      D3DLOCKED_RECT rect;
      tex.LockRect(0,&rect,NULL,0);auto*pBits=(QapColor*)rect.pBits;
      for(int i=0;i<mem_size;i++)pBits[i]=def_alpha<<8*3;
      tex.UnlockRect(0);
      break;
    }
    int low=ptr[0];int top=ptr[0];int64 sum=0;int n=0;int dip=192;
    if(the_is_cdlinemap){
      low=v2i(low);top=v2i(top);
      for(int i=begin;i<mem_size;i++){auto v=v2i(*ptr);if(v>=0){low=std::min(low,v);top=std::max(top,v);sum+=v;n++;}ptr++;}
    }else
      for(int i=begin;i<mem_size;i++){auto v=*ptr;if(v>=0){low=std::min(low,v);top=std::max(top,v);sum+=v;n++;}ptr++;}
    //int curavr=sum/n;
    //int curlow=curavr
    int base=255-dip;
    auto diff=top-low;if(!diff)diff=1;
    auto k=dip/real(diff);
    //--
    auto&tex=*qt.Tex;
    D3DLOCKED_RECT rect;
    tex.LockRect(0,&rect,NULL,0);auto*pBits=(QapColor*)rect.pBits;
    if(the_is_cdlinemap){
      /*this is almos copy-paste */ for(int y=0;y<map.h;y++)for(int x=0;x<map.w;x++)
      /*this is almos copy-paste */ {
      /*this is almos copy-paste */   auto coord=vec2d(x,y);
      /*this is almos copy-paste */   auto center=map.map_to_world(coord);
      /*this is almos copy-paste */   auto pos=vec2d(qDev.xf*center)+qDev.viewport.pos;
      /*this is almos copy-paste */   //if(!point_in_quad(vp,pos))continue;
      /*this is almos copy-paste */   int mem_id=x+y*map.w;
      /*this is almos copy-paste */   auto&out=pBits[x+(map.h-y-1)*map.w];
      /*this is almos copy-paste */   auto v=v2i(map.mem[mem_id]);
      /*this is almos copy-paste */   int z=0;
      /*this is almos copy-paste */   if(v>=0){
      /*this is almos copy-paste */     z=base+int(dip*(top-v)/diff);
      /*this is almos copy-paste */   }
      /*this is almos copy-paste */   out.a=v>=0?0xFF:def_alpha;
      /*this is almos copy-paste */   out.r=z;
      /*this is almos copy-paste */   out.g=z;
      /*this is almos copy-paste */   out.b=z;
      /*this is almos copy-paste */ }
    }else
    for(int y=0;y<map.h;y++)for(int x=0;x<map.w;x++)
    {
      auto coord=vec2d(x,y);
      auto center=map.map_to_world(coord);
      auto pos=vec2d(qDev.xf*center)+qDev.viewport.pos;
      //if(!point_in_quad(vp,pos))continue;
      int mem_id=x+y*map.w;
      auto&out=pBits[x+(map.h-y-1)*map.w];
      auto v=map.mem[mem_id];
      int z=0;
      if(v>=0){
        z=base+int(dip*(top-v)/diff);
      }
      out.a=v>=0?0xFF:def_alpha;
      out.r=z;
      out.g=z;
      out.b=z;
    }
    tex.UnlockRect(0);
    break;
  }
  auto&qd=sys_res_qd;
  if(!qd.DynRes.pDev){
    int cells=1;
    qd.MountDev(D9Dev);qd.Init(cells*4,cells*6);
    qd.after_reinit=true;
  }
  if(qd.OnReinit())
  {
    qd.BeginBatch();
    qd.color=0xFFFFFFFF;
    qd.DrawQuad(0,0,map.w*map.info.block_size,-map.h*map.info.block_size);
    /*for(int y=0;y<map.h;y++)for(int x=0;x<map.w;x++){
      auto coord=vec2d(x,y);auto center=map.map_to_world(coord);
      qd.color=0xFF000000;
      qd.DrawQuad(center,block_size,block_size);
    }*/
    qd.EndBatch(false);
  }
  real zoom=vec2d(qDev.xf.r.col1).Mag();
  vec2d ox=vec2d(qDev.xf.r.col1);
  auto cur_cam_pos=vec2d(-qDev.xf.p*(1.0f/zoom)).Rot(ox);
  D9Dev.Set2D(cur_cam_pos,zoom,ox.GetAng());
  qd.pDev->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_POINT);
  qd.pDev->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_POINT);
  qd.pDev->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_POINT);
  qd.SetBlendMode(QapDev::BlendType::BT_SUB);
  qt.Bind();
  {
    qd.NextFrame();
    auto old=qd.BlendMode;
    qd.SetBlendMode(QapDev::BlendType::BT_SUB);
    {
      qd.SetColor(0xffffffff);
      //{
      //  vec2d z=vec2d(1,1);
      //  z.x*=1.0/real(map.w);
      //  z.y*=1.0/real(map.h);
      //  qd.txf=MakeZoomTransform(z);
      //}
      {
        auto scale=this->scale*0.90;
        auto ls=line_size();
        auto quad_ox=Vec2dEx(-vec2d(qDev.xf.r.col1).GetAng(),1);
        auto ns=get_max_quad_vertex(viewport.size,quad_ox)*(1/scale);
        {
          QapDev::BatchScope Scope(qd);
          auto quad_pos=vec2d(0,0);
          auto quad_size=vec2d(map.w,map.h)*map.info.block_size;
          //con.pos;con.size;
          //TClipper clipper={qd,-(obj.pos+cam_pos).UnRot(qDev.xf.r.col1)*scale,quad_size,vec2d_zero,viewport.size};
          TClipper clipper={qd,vec2d_zero,quad_size,cur_cam_pos,ns};
          clipper.main();
          //for(int i=0;i<4;i++)qd.VBA[qd.VPos-i].tv*=-1;
        }
        qd.BindTex(0,nullptr);
        if(static bool need_debug=false)
        {
          qDev.SetColor(0xffffffff);qDev.DrawRectAsQuad(cur_cam_pos,ns,ls);
          qDev.SetColor(0xff000000);qDev.DrawRectAsQuad(cur_cam_pos,viewport.size*(1/scale),ls,-vec2d(qDev.xf.r.col1).GetAng());
        }
      }
      //qDev.txf.set_ident();
    }
    qd.SetBlendMode(old);
  }
  qd.BindTex(0,nullptr);
  D9Dev.Set2D();
  /*
  for(int y=imin.y;y<imax.y;y++)for(int x=imin.x;x<imax.x;x++)
  {        
    //auto pos=vec2d(qDev.xf*(vec2d(x,y)*block_size-offset))+qDev.viewport.pos;
    auto coord=vec2d(x,y);//get_block_size;
    auto center=map.map_to_world(coord);
    auto pos=vec2d(qDev.xf*center)+qDev.viewport.pos;
    //if(!point_in_quad(vp,pos))continue;
    int mem_id=x+y*map.w;
    //auto minid=QAP_MINVAL_ID_OF_VEC(maps,ex.mem[mem_id]<0?100500:ex.mem[mem_id]);
    auto v=map.mem[mem_id];//maps[minid].mem[x+y*map.w]/2;
    int z=-1;
    if(v>=0){
      //if(vp.pos.dist_to_point_less_that_r(pos,r))
      {
        real dist=vp.pos.dist_to(pos);
        real mass=dist<cr?1:((dist-cr)*invcr);
        diffsum+=abs(v-avr)*mass;
        n+=mass;sum+=v*mass;//*vp.pos.dist_to(pos)*invr;
        maxv=maxv<0?v:std::max(maxv,v);
        minv=minv<0?v:std::min(minv,v);
      }
      z=v<low?0:(v>top?0xff:int(float(v-low)*invd));
    }
    if(z<0){
      if(v<low)z=0xff;
      if(v>top)z=0x00;
    }
    qDev.color.a=0xFF;
    //if(vp.clamp(pos)!=pos){qDev.color.a=0xff;v-=0x40;};
    qDev.color.r=255-z;
    qDev.color.g=255-z;
    qDev.color.b=255-z;
    //qDev.AddQuadVertices(pos.x,pos.y,hbs,hbs);c++;
    //qDev.DrawGeomWithOffset(quad,center);c++;
    //qDev.DrawQuad(center,block_size,block_size);c++;
    //if(v==0x50){qDev.color=0xffFF0000;qDev.DrawQuad(center,vec2d(4,4));}
    //if(v==0x5F){qDev.color=0xffFFFF00;qDev.DrawQuad(center,vec2d(4,4));}
  }*/
  //qDev.use_xf=true;
  //qDev.AddQuadsIndices(vpos,c);
  //prevmin=minv;prevmax=maxv;prevr=r;prevn=n;prevsum=sum;prevdiffsum=diffsum;
}
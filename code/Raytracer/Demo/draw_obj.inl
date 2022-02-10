struct t_obj_face_item{int id;int tid;};
static t_obj_face_item get_obj_face_item(const string&s){
  if(string::npos==s.rfind('/')){
    t_obj_face_item out={SToI(s),-1};
    return out;
  }
  auto t=split(s,"/");
  //QapAssert(t.size()==2);
  t_obj_face_item out={SToI(t[0]),SToI(t[1])};
  return out;
}
struct t_obj_mtl_item{
  string name;
  vec3d Ka;
  vec3d Kd;
  QapColor get_diffuse()const{
    auto c=Kd*255;
    return QapColor(c.x,c.y,c.z);
  }
};
static string get_without_first_part(const vector<string>&arr){auto tmp=arr;QapPopFront(tmp);return join(tmp," ");}
static string get_fullname_of_near_file(const string&obj_fn,const string&mtl_fn)
{
  //if(split(obj_fn,"/").size()!=1)QapNoWay();
  {auto delim="/";auto a=split(obj_fn,delim);if(a.size()!=1){a.back()=mtl_fn;return join(a,delim);}}
  {auto delim="\\";auto a=split(obj_fn,delim);if(a.size()!=1){a.back()=mtl_fn;return join(a,delim);}}
  return mtl_fn;
}
struct t_obj_mtllib{
  vector<t_obj_mtl_item> arr;
  PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(t_obj_mtl_item,get,arr,string,name);
  void load(const string&fn){
    auto s=file_get_contents(fn);
    s=join(split(s,"\t"),"");
    s=join(split(s,"\r"),"");
    s=join(split(s," \n"),"\n");
    auto lines=split(s,"\n");
    t_obj_mtl_item*p=nullptr;
    for(int i=0;i<lines.size();i++){
      auto&ex=lines[i];
      auto t=split(ex," ");
      if(t.empty())continue;
      if(t[0]=="newmtl"){
        if(t.size()!=2){
          p=get(get_without_first_part(t));
        }else p=get(t[1]);
      }
      if(!p)continue;
      if(t[0]=="Ka"){
        QapAssert(t.size()==4);
        auto&k=p->Ka;
        for(int i=0;i<3;i++)(&k.x)[i]=SToF(t[1+i]);
      }
      if(t[0]=="Kd"){
        QapAssert(t.size()==4);
        auto&k=p->Kd;
        for(int i=0;i<3;i++)(&k.x)[i]=SToF(t[1+i]);
      }
    }
  }
};
struct t_mesh{
  vector<vec3f> VA;
  vector<int> IA;
  vector<QapColor> CA;
  vector<QapColor> FCA;
  void make_vertex_unique()
  {
    vector<int> U;U.resize(VA.size());auto out=VA;QapAssert(FCA.size());CA.resize(VA.size());
    for(int i=0;i+2<IA.size();i+=3)
    {
      auto color=FCA[i/3];
      for(int id=0;id<3;id++)
      {
        auto&A=IA[i+id];
        QapAssert(qap_check_id(VA,A));
        auto&a=VA[A];
        if(U[A]++)
        {
          A=out.size();
          qap_add_back(out)=a;
          QapAssert(CA.size()==A);
          CA.push_back(color);
          continue;
        }
        if(!qap_check_id(CA,A))QapDebugMsg("if(!qap_check_id(CA,A))\nA = "+IToS(A));
        CA[A]=color;
      }
    }
    VA=out;
  }
  void draw_without_ca(QapDev&qDev)
  {
    auto base=qDev.VPos;
    for(int i=0;i<VA.size();i++)qDev.AddVertex(VA[i]);
    for(int i=0;i<IA.size();i++)qDev.AddIndex(base+IA[i]);
  }
  void draw(QapDev&qDev)
  {
    auto base=qDev.VPos;
    if(CA.size()!=VA.size()){
      QapDebugMsg(IToS(CA.size())+"\n"+IToS(VA.size()));
      draw_without_ca(qDev);
      return;
    }
    for(int i=0;i<VA.size();i++){
      qDev.color=CA[i];
      qDev.AddVertex(VA[i]);
    }
    for(int i=0;i<IA.size();i++)qDev.AddIndex(base+IA[i]);
  }
  bool empty()const{return IA.empty();}
};
void load_mesh_obj(t_mesh&out,const string&fn){
  if(!out.IA.empty())return;
  QapColor diffuse=0xFFffffff;
  t_obj_mtllib lib;
  string mtllib;
  real scale=10.0;string shift_algo="upper_ground";bool use_per_vertex_color=false;vector<std::pair<bool,QapColor>> pvc;
  auto s=file_get_contents(fn);
  s=join(split(s,"\t"),"");
  s=join(split(s,"\r"),"");
  s=join(split(s,"v  "),"v ");
  s=join(split(s," \n"),"\n");
  auto arr=split(s,"\n");
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto t=split(ex," ");
    if(t.empty())continue;
    if(t.size()==2)if(t[0]=="#scale"){scale=SToF(t[1]);}
    if(t.size()==2)if(t[0]=="#shift_algo"){shift_algo=t[1];}
    if(t[0]=="mtllib"){
      mtllib=t.size()!=2?get_without_first_part(t):t[1];
      lib.load(get_fullname_of_near_file(fn,mtllib));
    }
    if(t[0]=="usemtl"){
      auto*p=lib.get(get_without_first_part(t));
      diffuse=p->get_diffuse();
    }
    if(t.size()==4||t.size()==4+3){
      if(t[0]=="v"){
        auto*f=&qap_add_back(out.VA).x;for(int i=0;i<3;i++)f[i]=SToF(t[1+i]);
        if(t.size()==4+3){
          if(!use_per_vertex_color)pvc.resize(out.VA.size()-1,{false,0});
          use_per_vertex_color=true;
          auto&[ok,vc]=qap_add_back(pvc);ok=true;
          auto*p=&vc.b;
          for(int i=0;i<3;i++)p[i]=SToI(t[4+i]);
          /*hm... CA[vertex_id]=read_color(); //??? */
        }else if(use_per_vertex_color){auto&[ok,vc]=qap_add_back(pvc);ok=false;}
        continue;
      }
      //if(t[0]=="f"){for(int i=0;i<3;i++)qap_add_back(out.IA)=get_obj_face_item(t[1+i]).id-1;continue;}
    }
    if(t[0]=="f"&&t.size()>3)
    {
      vector<int> arr;struct{vec4i c;int n=0;QapColor get()const{return QapColor(c.a/n,c.r/n,c.g/n,c.b/n);}} tris;
      qap_add_back(out.FCA)=diffuse;
      for(int i=1;i<t.size();i++)qap_add_back(arr)=get_obj_face_item(t[i]).id-1;
      if(arr.size()!=3)QapDebugMsg("no way. // need bug with out.FCA.size();");
      for(int i=2;i<arr.size();i++){
        auto add=[&](int id){qap_add_back(out.IA)=id;if(use_per_vertex_color)if(auto&[ok,vc]=pvc[id];ok){tris.c+=vc;tris.n++;}};
        add(arr[0]);
        add(arr[i-1]);
        add(arr[i-0]);
      }
      if(use_per_vertex_color&&tris.n){
        out.FCA.back()=tris.get().swap_rg();
      }
      continue;
    }
    if(t[0]=="v"||t[0]=="f")QapDebugMsg("hm...\n"+ex);
  }
  if(out.VA.empty())return;
    
  vec3f avg_pos;
  QAP_FOREACH(out.VA,avg_pos+=ex);
  if(!out.VA.empty())avg_pos*=1.0/out.VA.size();
  QAP_FOREACH(out.VA,ex-=avg_pos);
  
  auto id=QAP_MINVAL_ID_OF_VEC(out.VA,-ex.SqrMag());
  auto m=out.VA[id].Mag();auto k=5.0/(m*scale);
  if(fn=="tb6_Moskvitch.obj"){
    QAP_FOREACH(out.VA,ex*=k;std::swap(ex.z,ex.y));k=1;
  }
  if(fn=="sponza.obj"){
    QAP_FOREACH(out.VA,ex*=k;/*std::swap(ex.z,ex.y)*/ex.z*=-1;);
  }else{
    QAP_FOREACH(out.VA,ex*=k;std::swap(ex.z,ex.y));
  }

  if(shift_algo=="under_ground"){
    auto id=QAP_MINVAL_ID_OF_VEC(out.VA,-ex.y);
    auto offset=vec3f(0,-1,0)*out.VA[id].y;
    QAP_FOREACH(out.VA,ex+=offset);
  }
  if(shift_algo=="upper_ground"){
    auto id=QAP_MINVAL_ID_OF_VEC(out.VA,+ex.y);
    auto offset=vec3f(0,-1,0)*out.VA[id].y;
    QAP_FOREACH(out.VA,ex+=offset);
  }
  out.make_vertex_unique();
}
/*
newmtl color_16448250
Ka 0 0 0 
Kd 0.9803921568627451 0.9803921568627451 0.9803921568627451
*/
void draw_obj()
{
  //static t_mesh out;
  static vector<t_mesh> out;
  if(out.empty()){
    auto arr=get_all_obj_fn();
    out.resize(arr.size());
    QAP_FOREACH(arr,load_mesh_obj(out[i],ex));
  }
  //t_vertex_light_scope vertex_light_scope(qDev,pos,true,true);
  //qDev.color=diffuse;
  QAP_FOREACH(out,ex.draw(qDev));
}
void DrawScene2()
{
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,4,00),vec3f(5,1,5));
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(5,2.7,00),vec3f(1,5,5));
    
    
    qDev.color=0xffffff00;qDev.DrawCube(vec3f(02,0.25,00),vec3f(1,1,1)*0.5);
    qDev.color=0xffffff00;qDev.DrawCube(vec3f(02,0.25,-0.7),vec3f(1,1,1)*0.5);
    qDev.color=0xff00ffff;qDev.DrawCube(vec3f(02-0.8,0.25,-0.7),vec3f(1,1,1)*0.5);
    qDev.color=0xff00ff00;qDev.DrawCube(vec3f(02-0.8,0.25,0),vec3f(1,3,1)*0.25);
    qDev.color=0xffffffff;qDev.DrawCube(vec3f(02.7,0.1,00),vec3f(1,1,30)*0.2);
    
    qDev.color=0xffff0000;qDev.DrawCube(vec3f(00,2,02),vec3f(2.1,4,2.1));
    for(int k=-2;k<3;k++){
    auto u=-k*0.3;real i=k*0.75;
    qDev.color=0xffe0e0e0;qDev.DrawCylinderAsLine(vec3f(i,0.0,i),vec3f(i,1.2+u,i),0.1,16,0);//qDev.DrawCube(vec3f(00,0.5,00),vec3f(2,10,2)*0.1);
    qDev.color=0xffe0e0e0;qDev.DrawCylinderAsLine(vec3f(i,0.8+u,i),vec3f(i,1.0+u,i),0.25,16,0);
    }
    //qDev.color=0xffffffff;qDev.DrawCube(vec3f(00,-1,00),vec3f(1000,2,1000));
    qDev.color=0xffffffff;qDev.DrawCylinderAsLine(vec3f(00,-2,00),vec3f(00,00,00),5,32,0);
}
void SetupLightAndGround()
{
  /*
  if(get_obj_fn()=="tb6_Moskvitch.obj")
  {
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,+8.0,00),vec3f(1,0.01,1)*40); // sky light
    qDev.color=0xffffffff;qDev.DrawCube(vec3f(0,-0.73,00),vec3f(1,0.1,1)*15); // ground for car
    return;
  }
  if(get_obj_fn()=="tb8_Moskvitch.obj")
  {
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,4.0,00),vec3f(5,0.1,5)); // new at top like sky
    return;
  }
  if(get_obj_fn()=="tb9_Moskvitch.obj")
  {
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,4.0,00),vec3f(8,0.1,8)); // new at top like sky
    return;
  }
  if(get_obj_fn()=="tbx_Moskvitch.obj")
  {
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,4.0,00),vec3f(8,0.1,8)); // new at top like sky
    return;
  }
  if(get_obj_fn()=="tbr_Moskvitch.obj")
  {
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,4.0,00),vec3f(8,0.1,8)); // new at top like sky
    return;
  }
  if(get_obj_fn()=="raic4_colored.obj")
  {
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,4.0,00),vec3f(8,0.1,8)); // new at top like sky
    return;
  }
  */
  //qDev.color=0xfffefefe;qDev.DrawCube(vec3f(5,2.7,00),vec3f(1,5,5));// old light at right
  //qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,1.7,00),vec3f(0.5,0.1,0.5)); // new at top like point
  qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,1.7,00),vec3f(5,0.1,5)); // new at top like sky
  //qDev.color=0xffffffff;qDev.DrawCylinderAsLine(vec3f(00,-2,00),vec3f(00,00,00),5,32,0);    
}
void DrawScene()
{
  SetupLightAndGround();
  if(QapKbOnDownDoInvFlag("draw_obj",'E',true)){
    draw_obj();
  }else{
    DrawScene2();
  }
  DrawRayCastSphere();
  if(kb.OnDown(VK_TAB))msg="";
  make_lighted_scene();
  return;
  if(QapKbOnDownDoInvFlag("draw_obj",'E',true)){
    
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,4,00),vec3f(5,1,5));
    qDev.color=0xfffefefe;qDev.DrawCube(vec3f(5,2.7,00),vec3f(1,5,5));
    
    
    qDev.color=0xffffff00;qDev.DrawCube(vec3f(02,0.25,00),vec3f(1,1,1)*0.5);
    qDev.color=0xffffffff;qDev.DrawCube(vec3f(02.7,0.1,00),vec3f(1,1,30)*0.2);
    
    qDev.color=0xffff0000;qDev.DrawCube(vec3f(00,2,02),vec3f(2.1,4,2.1));
    for(int k=-2;k<3;k++){
    auto u=-k*0.3;real i=k*0.75;
    qDev.color=0xffe0e0e0;qDev.DrawCylinderAsLine(vec3f(i,0.0,i),vec3f(i,1.2+u,i),0.1,16,0);//qDev.DrawCube(vec3f(00,0.5,00),vec3f(2,10,2)*0.1);
    qDev.color=0xffe0e0e0;qDev.DrawCylinderAsLine(vec3f(i,0.8+u,i),vec3f(i,1.0+u,i),0.25,16,0);
    }
    //qDev.color=0xffffffff;qDev.DrawCube(vec3f(00,-1,00),vec3f(1000,2,1000));
    qDev.color=0xffffffff;qDev.DrawCylinderAsLine(vec3f(00,-2,00),vec3f(00,00,00),5,32,0);
    if(0)
    {
      auto B=qDev.VPos;
      
      auto dir=get_view_dir().Norm();
      auto ox=-cross(pos+dir,get_updir(pos+dir));
      
      qDev.AddVertex(pos+dir*3);
      qDev.AddVertex(pos+dir*1+ox*3);
      qDev.AddVertex(pos+dir*3+ox*3);
      qDev.AddTris(B,B+1,B+2);
      qDev.AddTris(B+2,B+1,B);
      {
      qDev.color=0xff00ff00;
      
      auto B=qDev.VPos;
      qDev.AddVertex(pos+dir*3);
      qDev.AddVertex(pos+ox*3);
      qDev.AddVertex(pos+dir*3+ox*3);
      qDev.AddTris(B,B+1,B+2);
      qDev.AddTris(B+2,B+1,B);}
    }
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,3,00),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(+5,3,00),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(-5,3,00),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,3,-5),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,3,+5),vec3f(5,1,5)*0.2);

    //draw_obj();
    DrawRayCastSphere();
    return;
  }
  DrawBall();
}
/*
void DrawSceneOld()
{
  if(QapKbOnDownDoInvFlag("draw_obj",'E',true)){
    qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,4,00),vec3f(5,1,5));
    
    
    qDev.color=0xff707070;qDev.DrawCube(vec3f(02,0.25,00),vec3f(1,1,1)*0.5);
    for(int k=-2;k<3;k++){
    auto u=-k*0.3;real i=k*0.75;
    qDev.color=0xff707070;qDev.DrawCylinderAsLine(vec3f(i,0.0,i),vec3f(i,1.2+u,i),0.1,16,0);//qDev.DrawCube(vec3f(00,0.5,00),vec3f(2,10,2)*0.1);
    qDev.color=0xff707070;qDev.DrawCylinderAsLine(vec3f(i,0.8+u,i),vec3f(i,1.0+u,i),0.25,16,0);
    }
    //qDev.color=0xffffffff;qDev.DrawCube(vec3f(00,-1,00),vec3f(1000,2,1000));
    qDev.color=0xffffffff;qDev.DrawCylinderAsLine(vec3f(00,-2,00),vec3f(00,00,00),5,32,0);
    
    
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,3,00),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(+5,3,00),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(-5,3,00),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,3,-5),vec3f(5,1,5)*0.2);
    //qDev.color=0xff00fe00;qDev.DrawCube(vec3f(00,3,+5),vec3f(5,1,5)*0.2);

    //draw_obj();
    DrawRayCastSphere();
    return;
  }
  DrawBall();
}*/
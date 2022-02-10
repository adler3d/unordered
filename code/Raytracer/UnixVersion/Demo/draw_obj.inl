struct t_mesh{
  vector<vec3f> VA;
  vector<int> IA;
  vector<QapColor> CA;
  vector<QapColor> FCA;
  void make_vertex_unique()
  {
    vector<int> U;U.resize(VA.size());auto out=VA;QapAssert(FCA.size());CA.resize(IA.size());
    for(int i=0;i+2<IA.size();i+=3)
    {
      auto color=FCA[i/3];
      #define F(A,a,id)auto&A=IA[i+id];auto&a=VA[A];if(U[A]++){A=out.size();qap_add_back(out)=a;}CA[A]=color;
      F(A,a,0)F(B,b,1)F(C,c,2)
      #undef F
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
};
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
        if(t.size()!=2)QapDebugMsg("hm...\n"+ex);
        p=get(t[1]);
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
static string get_fullname_of_near_file(const string&obj_fn,const string&mtl_fn)
{
  if(split(obj_fn,"/").size()!=1)QapNoWay();
  if(split(obj_fn,"\\").size()!=1)QapNoWay();
  return mtl_fn;
}
/*
newmtl color_16448250
Ka 0 0 0 
Kd 0.9803921568627451 0.9803921568627451 0.9803921568627451
*/
void draw_obj()
{
  static t_mesh out;
  QapColor diffuse=0xFFffffff;
  if(out.IA.empty())
  {
    t_obj_mtllib lib;
    string fn=get_obj_fn();
    string mtllib;
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
      if(t[0]=="mtllib"){
        if(t.size()!=2)QapDebugMsg("hm...\n"+ex);
        mtllib=t[1];
        lib.load(get_fullname_of_near_file(fn,mtllib));
      }
      if(t[0]=="usemtl"){
        if(t.size()!=2)QapDebugMsg("hm...\n"+ex);
        auto*p=lib.get(t[1]);
        diffuse=p->get_diffuse();
      }
      if(t.size()==4){
        if(t[0]=="v"){auto*f=&qap_add_back(out.VA).x;for(int i=0;i<3;i++)f[i]=SToF(t[1+i]);continue;}
        //if(t[0]=="f"){for(int i=0;i<3;i++)qap_add_back(out.IA)=get_obj_face_item(t[1+i]).id-1;continue;}
      }
      if(t[0]=="f"&&t.size()>3)
      {
        vector<int> arr;
        qap_add_back(out.FCA)=diffuse;
        for(int i=1;i<t.size();i++)qap_add_back(arr)=get_obj_face_item(t[i]).id-1;
        for(int i=2;i<arr.size();i++){
          qap_add_back(out.IA)=arr[0];
          qap_add_back(out.IA)=arr[i-1];
          qap_add_back(out.IA)=arr[i-0];
        }
        continue;
      }
      if(t[0]=="v"||t[0]=="f")QapDebugMsg("hm...\n"+ex);
    }
    if(out.VA.empty())return;
    auto id=QAP_MINVAL_ID_OF_VEC(out.VA,-ex.SqrMag());
    auto m=out.VA[id].Mag();auto k=5.0/m;
    if(fn=="sponza.obj"){
      QAP_FOREACH(out.VA,ex*=k;/*std::swap(ex.z,ex.y)*/ex.z*=-1;);
    }else{
    QAP_FOREACH(out.VA,ex*=k;std::swap(ex.z,ex.y));
    }
    out.make_vertex_unique();
  }
  //t_vertex_light_scope vertex_light_scope(qDev,pos,true,true);
  //qDev.color=diffuse;
  out.draw(qDev);
}
void DrawScene()
{
  //qDev.color=0xfffefefe;qDev.DrawCube(vec3f(5,2.7,00),vec3f(1,5,5)); old light at right
  qDev.color=0xfffefefe;qDev.DrawCube(vec3f(0,1.7,00),vec3f(5,0.1,5)); // new at top like sky
  //qDev.color=0xffffffff;qDev.DrawCylinderAsLine(vec3f(00,-2,00),vec3f(00,00,00),5,32,0);
  draw_obj();
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
#include "QapLite.h"
#include "TQapGameV2.inl"

const real max_speed=3.0;

#include "core.inl"

class TGame:public TQapGameV2{
public:
  #define DEF_PRO_CLASSNAME()TGame
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(bool,need_init,true)\
  ADD(real,ds,4)\
  ADD(real,ls,4)\
  ADD(t_obj,obj,$)\
  ADD(vector<vec2d>,points,$)\
  ADD(vector<vec2d>,kbi,$)\
  ADD(int,tick,0)\
  ADD(bool,pause,true)\
  ADD(vec2d,cam_pos,$)\
  //===
  #include "defprovar.inl"
  //===
public:
  ~TGame(){on_free();}
  void sys_load(){return;QapLoadFromStrWithSizeOfType(*this,file_get_contents("game.bin"));}
  void sys_save(){file_put_contents("game.bin",QapSaveToStrWithSizeOfType(*this));}
  void on_init(){need_init=false;set_to_def();sys_load();need_init=false;}
  void on_free(){sys_save();}
public:
  static int get_n(){return 1?14:64;}
  static string get_path(){return IToS(get_n())+"\\";}
  void set_to_def()
  {
    obj.v=vec2d(max_speed,0);
    srand(0*time(0));
    real hw=1366/2;
    real hh=768/2;
    int n=get_n();//1024*4*2;
    real d=sqrt(hw*hh*4/real(n));
    int w=2*hw/d;
    for(int i=0;i<n;i++){
      qap_add_back(points)=0||rand()%5==0?(vec2d(i%int(w),i/int(w))*d-vec2d(hw,hh))*0.8:rndvec2d(-1,1).Mul(vec2d(hw,hh))*0.8;
    }
  }
public:
  static vec2d char2v(char c){
    vec2d cmd;
    if(c=='A')cmd.x=+1;
    if(c=='S')cmd.x=-1;
    if(c=='N')cmd.x=0;
    return cmd;
  }
  static string v2char(const vec2d&v){
    QapAssert(v.y==0);
    if(v.x>0)return "A";
    if(v.x<0)return "S";
    return "N";
  }
  static string kvi2str(const vector<vec2d>&arr){
    string out;
    for(int i=0;i<arr.size();i++){if(i&&i%64==0)out+="\n";out+=v2char(arr[i]);}
    return out;
  }
  void DoPreMove()
  {
    if(need_init)on_init();
    if(kb.Down[VK_ESCAPE])win.Close();
    if(kb.OnDown(VK_PAUSE)||kb.OnDown(VK_SPACE))pause=!pause;
    if(kb.Down('C'))cam_pos=vec2d(0,0);
    bool control_from_file=kb.Down(VK_CONTROL)||kb.OnDown(VK_F5);
    {
      if(!points.empty()&&(!pause||kb.OnDown(VK_F3)||control_from_file))
      {
        static auto cmds=StrReplace(get_path()+file_get_contents("3723.txt"),"\n","");
        auto kbv=!control_from_file||cmds.empty()?kb.get_dir_from_wasd_and_arrows():char2v(cmds[tick%cmds.size()]);
        qap_add_back(kbi)=kbv;
        obj.a=obj.wasd2a(kbv);
        obj.move();
        QapCleanIf(points,[&](vec2d&p){return obj.pos.dist_to_point_less_that_r(p,32);});
        tick++;
      }else{
        if(kb.Down(VK_SHIFT))cam_pos+=kb.get_dir_from_wasd_and_arrows()*6;
      }
      if(points.empty())
      {
        static bool once=true;
        if(once){once=false;file_put_contents(get_path()+IToS(tick)+".txt",kvi2str(kbi));}
      }
    }
  }
  void DoPreDraw()
  {
    real ds=3;real r=32;
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    {
      t_offcentric_scope scope(qDev,obj.pos+cam_pos,vec2d(1,0),1,false);
      qDev.SetColor(0xff000000);
      static t_geom sc=qDev.GenGeomCircleSolid(ds,7,0);real mr=ds+r;
      for(int i=0;i<points.size();i++)
      {
        if(!obj.pos.dist_to_point_less_that_r(points[i],mr))
        {
          qDev.DrawGeomWithOffset(sc,points[i]);
          continue;
        }
        qDev.DrawSolidCircle(points[i],std::min<real>(ds,obj.pos.dist_to(points[i])-r),7,0);
      }
      DrawLinesFromFile(false,"1096,1409");
      obj.draw_object(qDev,false,r);
    }
    //
    qDev.color=0xff000000;qap_text::draw(qDev,viewport.get_vertex_by_dir(vec2d(-1,1))+vec2d(16,-16),"tick = "+IToS(tick),16);
    DrawDownedKeys();
  }
  #include "draw_lines_from_file.inl"
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}
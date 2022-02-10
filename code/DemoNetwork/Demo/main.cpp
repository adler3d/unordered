#include "QapLite.h"
bool isRight(const vec2d&prev,const vec2d&o,const vec2d&next){return (next-o).Rot(prev-o).y>0;}

struct t_${
  template<class TYPE>static void set(TYPE&,const t_$&){}
  template<class TYPE>static void set(TYPE&a,TYPE&b){a=b;}
  template<class TYPE>static void set(TYPE&a,const TYPE&b){a=b;}
  static void set(int&a,int b){a=b;}
};

#define PRO_FUNCGEN_GETP(rettype,getp,arr,name)\
  rettype*getp(string name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_GETREF(rettype,getref,arr,name)\
  rettype&getref(string name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    QapAssert(p);\
    return *p;\
  }

template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(tmp>=val)continue;
    val=tmp;id=i;
  }
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(tmp>=val)continue;
    val=tmp;id=i;
  }
  return id;
}

template<class TYPE>int qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}

#define QAP_MINVAL_ID_OF_VEC(arr,code)qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return code;})
#define QAP_MINVAL_ID_OF_VEC_V2(arr,code)qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){code;})

inline int SToI(const string&S){return std::stoi(S,nullptr,10);};

class TGame:public TD3DGameBoxBuilder{
public:
  struct t_msg
  {
    int time=0;
    string from;
    string data;
  };
  struct t_cmd
  {
    string to;
    string data;
    void set(string to,string data){this->to=to;this->data=data;}
  };
  struct t_route
  {
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(int,t,-1)\
    ADD(bool,primary,false)\
    //===
    #include "defprovar.inl"
    //===
    t_route(){DoReset();}
    void set(string name)
    {
      this->name=name;
    }
  };
  struct t_link_info
  {
    string name;
    int time=0;
    vector<t_route> routes;
    //vector<string> mem;
    PRO_FUNCGEN_GETP(t_route,get_route,routes,name);
  };
  struct t_point
  {
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(vec2d,pos,$)\
    ADD(int,last_send,0)\
    ADD(vector<t_msg>,msgs,$)\
    ADD(vector<t_link_info>,links,$)\
    ADD(vector<t_cmd>,cmds,$)\
    ADD(bool,deaded,false)\
    //===
    #include "defprovar.inl"
    //===
    t_point(){DoReset();}
    PRO_FUNCGEN_GETP(t_link_info,get_link,links,name);
    void send(string to,string data)
    {
      qap_add_back(cmds).set(to,data);
    }
    void set(string name,vec2d pos){this->name=name;this->pos=pos;}
    void sys_add_msg(string from,string data,int time)
    {
      auto&ex=qap_add_back(msgs);
      ex.data=data;
      ex.from=from;
      ex.time=time;
    }
    t_link_info*get_link_to(string to){
      struct t_rec{
        t_link_info*link=nullptr;
        t_route*route=nullptr;
        int cost=-1;
        void calc_cost(){cost=link->time+route->t;}
      };
      t_rec best;
      for(int i=0;i<links.size();i++)
      {
        auto&ex=links[i];
        if(ex.name==to)return &ex;
        auto*route=ex.get_route(to);
        if(!route)continue;
        t_rec cur={&ex,route};cur.calc_cost();
        if(!best.link||best.cost>cur.cost)best=cur;
      }
      return best.link;
    }
    bool try_send_tfa(string to,string about,int t)
    {
      auto*p=get_link(to);
      QapAssert(p);
      auto&link=*p;
      //bool need_send=qap_add_unique_str(link.mem,about);
      //if(!need_send)return false;
      /*auto*pdest=get_link_to(about);
      if(pdest&&pdest->name!=about){
        auto time=pdest->get_route(about)->t;
        if(time<t)return false;
      }*/
      send(to,"TFA  "+about+"  "+IToS(t));
      return true;
    }
    void up(string name,int time)
    {
      auto*p=get_link(name);
      if(!p)
      {/*
        auto*pr=get_primary_link(name);
        if(pr)
        {
          auto*r=pr->get_route(name);
          QapAssert(r);
          r->primary=false;
        }*/
        auto&b=qap_add_back(links);
        b.name=name;
        b.time=time;
        //tfa(name,name);
        for(int i=0;i<links.size();i++)
        {
          auto&link=links[i];
          if(link.name==b.name)continue;
          try_send_tfa(link.name,b.name,b.time);
          try_send_tfa(b.name,link.name,link.time);
          auto&routes=link.routes;
          for(int i=0;i<routes.size();i++)
          {
            auto&route=routes[i];
            if(route.name==b.name)continue;
            if(route.name==this->name){continue;}
            try_send_tfa(b.name,route.name,link.time+route.t);
          }
        }
        return;
      }
      QapAssert(false);// no impl
    }
    void rnd(string from,string head,string payload){
      if(links.empty())return;
      auto&L=links[rand()%links.size()];
      send(L.name,"RND  "+head+"  "+payload);
    }
    void txt(string from,string head,string payload){
      auto t=split(head,"->");
      if(t.size()!=2)return;
      auto*p=get_link_to(t[1]);
      if(!p)return;
      send(p->name,"TXT  "+head+"  "+payload);
    }
    void tfa(int t,string from,string name,string ct)
    {
      if(this->name=="A")if(name=="A3")
      {
        int gg=1;
      }
      auto*p=get_link(from);
      QapAssert(p);
      auto cost=SToI(ct);//+t;
      auto*route=p->get_route(name);
      if(route){
        if(cost>route->t)return;
        route->t=cost;
      }else{
        auto&b=qap_add_back(p->routes);
        b.name=name;
        b.t=cost;
      }
      for(int i=0;i<links.size();i++)
      {
        auto&link=links[i];
        if(link.name==from)continue;
        if(link.name==name)continue;
        try_send_tfa(link.name,name,cost+t);
      }
      return;
      QapAssert(false);// no impl
    }
  };
  struct t_obj{
    bool deaded=false;
    string data;
    int pos=0;
    int v=0;
    int time=0;
  };
  struct t_link
  {
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,a,$)\
    ADD(string,b,$)\
    ADD(vector<t_obj>,objs,$)\
    ADD(bool,deaded,false)\
    //===
    #include "defprovar.inl"
    //===
    t_link(){DoReset();}
    t_link&set(string a,string b){this->a=a;this->b=b;return *this;}
    bool cmp(string a,string b){return raw_cmp(a,b)||raw_cmp(b,a);}
    bool raw_cmp(string a,string b){
      bool fa=a==this->a;
      bool fb=b==this->b;
      return fa&&fb;
    }
    void do_up_to_both_side(TGame&game)
    {
      send(a,"UP",game);
      send(b,"UP",game);
    }
    void send(string from,string data,TGame&game)
    {
      auto&ex=qap_add_back(objs);
      ex.deaded=false;
      ex.data=data;
      ex.pos=0;
      ex.v=from==a?+1:-1;
    }
    int dist(TGame&game)
    {
      auto*pa=game.getp(a);
      auto*pb=game.getp(b);
      QapAssert(pa&&pb);
      auto ab=pa->pos-pb->pos;
      return ab.Mag();
    }
    t_point&get_from(TGame&game,t_obj&obj)
    {
      if(obj.v<0)return game.getref(b);
      if(obj.v>0)return game.getref(a);
      QapAssert(false);
      return *(t_point*)nullptr;
    }
    t_point&get_to(TGame&game,t_obj&obj)
    {
      if(obj.v<0)return game.getref(a);
      if(obj.v>0)return game.getref(b);
      QapAssert(false);
      return *(t_point*)nullptr;
    }
    string other(string name)
    {
      if(name==a)return b;
      if(name==b)return a;
      return "";
    }
    bool with(string name)
    {
      if(name==a)return true;
      if(name==b)return true;
      return false;
    }
    bool without(string name)
    {
      return !with(name);
    }
    bool is_down(TGame&game)
    {
      if(deaded)return true;
      auto*pa=game.getp(a);
      auto*pb=game.getp(b);
      if(!pa||!pb)return true;
      if(pa->deaded||pb->deaded)return true;
      return false;
    }
    void update(TGame&game)
    {
      if(is_down(game))return;
      for(int i=0;i<objs.size();i++)
      {
        auto&ex=objs[i];
        if(ex.deaded)continue;
        ex.pos+=ex.v;
        ex.time++;
        if(/*abs(abs(*/abs(ex.pos)<dist(game)/*)>1.05*game.get_point_r()*/)continue;
        auto&to=get_to(game,ex);
        auto&from=get_from(game,ex);
        to.sys_add_msg(from.name,ex.data,ex.time);
        ex.deaded=true;
      }
      qap_clean_if_deaded(objs);
    }
  };
  int get_point_r(){return 24;}
public:
#define DEF_PRO_VARIABLE(ADD)\
ADD(int,tick,0)\
ADD(int,speed,2)\
ADD(bool,pause,false)\
ADD(int,sel_point,-1)\
ADD(int,start_point,-1)\
ADD(int,scroll,0)\
ADD(vector<t_point>,points,$)\
ADD(vector<t_link>,links,$)\
//===
#include "defprovar.inl"
//===
public:
  void make_link_info()
  {
    vector<string> out;
    for(int i=0;i<links.size();i++)
    {
      auto&ex=links[i];
      qap_add_back(out)=ex.a+","+ex.b;
    }
    vector<string> out2;
    for(int i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      qap_add_back(out2)="    F("+ex.name+","+IToS(ex.pos.x)+","+IToS(ex.pos.y)+");";
    }
    string result=join(out2,"\n")+"\n    string decl_links=\""+join(out,"  ")+"\";\n";
    int gg=1;
  }
  void load()
  {
    int scale=1;
    #define F(NAME,X,Y)qap_add_back(points).set(#NAME,vec2d(X,Y)*scale);

    F(P0,0,0);
    F(P1,-406,45);
    F(P2,-282,389);
    string decl_links="P1,P0  P2,P1  P2,P0";

    gen_links(decl_links);
    #undef F
  }
  void load2()
  {
    int scale=1;
    #define F(NAME,X,Y)qap_add_back(points).set(#NAME,vec2d(X,Y)*scale);
    F(P0,0,0);
    F(P1,-192,230);
    F(P2,259,205);
    F(P3,-73,373);
    F(P4,-614,145);
    F(P5,-556,-244);
    F(P6,266,-244);
    F(P7,578,63);
    F(P8,441,333);
    F(P9,193,457);
    F(P10,-409,480);
    F(P11,-761,147);
    F(P12,-793,-329);
    F(P13,-179,-458);
    string decl_links=(
      "P1,P0  P2,P0  P2,P1  P3,P1  P2,P3  P4,P1  P5,P4  P6,P5  P7,P6  P8,P7  P9,P8  P10,P9  "
      "P11,P10  P12,P11  P13,P12  P6,P13  P5,P13  P0,P13  P6,P2  P7,P2  P8,P2  P9,P2  P10,P3  P10,P1  P0,P5  P4,P0"
    );
    gen_links(decl_links);
    #undef F
  }
  void load3(){
    int scale=1;
    #define F(NAME,X,Y)qap_add_back(points).set(#NAME,vec2d(X,Y)*scale);
    F(P0,700,-500);return;
    F(P1,648,-468);
    F(P2,401,-354);
    F(P3,775,-376);
    F(P4,614,-21);
    F(P5,654,180);
    F(P6,493,364);
    F(P7,250,449);
    F(P8,30,451);
    F(P9,-234,412);
    F(P10,-365,355);
    F(P11,-474,207);
    F(P12,-518,-6);
    F(P13,-483,-156);
    F(P14,-403,-262);
    F(P15,-157,-331);
    F(P16,335,-351);
    F(P17,324,-462);
    F(P18,386,-480);
    F(P19,-86,333);
    F(P20,-81,233);
    string decl_links="P1,P0  P2,P1  P3,P0  P4,P3  P5,P4  P6,P5  P7,P6  P8,P7  P9,P8  P10,P9  P11,P10  P12,P11  P13,P12  P14,P13  P15,P14  P16,P15  P17,P16  P18,P2  P4,P16  P2,P16  P19,P9  P19,P8  P20,P19  P5,P14  P14,P9";
    gen_links(decl_links);
    #undef F
  }
  void load4(){
    int scale=1;
    #define F(NAME,X,Y)qap_add_back(points).set(#NAME,vec2d(X,Y)*scale);
    F(P0,-24,12);
    F(P1,-20,172);
    F(P2,-188,86);
    F(P3,132,86);
    F(P4,113,-98);
    F(P5,-31,-173);
    F(P6,-181,-82);
    F(P7,80,488);
    F(P8,422,359);
    F(P9,508,-111);
    F(P10,292,-417);
    F(P11,-537,-61);
    F(P12,-553,101);
    F(P13,-658,13);
    F(P14,594,126);
    F(P15,757,132);
    F(P16,-788,8);
    F(P17,590,435);
    F(P18,879,132);
    F(P19,672,-273);
    F(P20,761,-219);
    F(P21,762,-333);
    F(P22,824,-474);
    string decl_links="P1,P0  P2,P0  P3,P0  P4,P0  P5,P0  P6,P0  P7,P1  P8,P3  P9,P4  P10,P5  P11,P6  P12,P2  P13,P12  P13,P11  P14,P8  P9,P14  P15,P14  P16,P13  P17,P7  P15,P17  P18,P15  P19,P10  P20,P18  P21,P19  P21,P20  P22,P21";
    gen_links(decl_links);
    #undef F
  }
  void gen_links(string decl_links)
  {
    auto arr=split(decl_links,"  ");
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto a=split(ex,",");
      QapAssert(a.size()==2);
      qap_add_back(links).set(a[0],a[1]);
    }
  }
  TGame()
  {
    DoReset();
    if(1){load4();}else{
      qap_add_back(points).set("P0",vec2d_zero);
    }
    if(0)
    {
      int scale=350;
      #define F(NAME,X,Y)qap_add_back(points).set(#NAME,vec2d(X,Y)*scale);
      //F(A,-1,-1);
      //F(B,+1,-1);
      //F(C,+1,+1);
      //F(D,-1,+1);
      //F(X,+0,+0);
      F(A,-1,-1);
      F(B,+1,-1);
      F(C,+1,+1);
      F(D,-1,+1);
      F(H,+2,+1);
      F(Z,+2,-0.5);
      #undef F
      string decl_links="A,B  B,C  C,A  C,D  A,D  B,Z  H,C";
      gen_links(decl_links);
    }
    //qap_add_back(links).set("A","B");
    //qap_add_back(links).set("B","C");
    //qap_add_back(links).set("C","D");
    //qap_add_back(links).set("D","A");
    //qap_add_back(links).set("X","A");
    //qap_add_back(links).set("X","B");
    //qap_add_back(links).set("X","C");
    //qap_add_back(links).set("X","D");
    if(0)
    {
      qap_add_back(points).set("A",vec2d(-100,0));
      qap_add_back(points).set("A1",vec2d(-250,+100));
      qap_add_back(points).set("A2",vec2d(-250,-100));
      qap_add_back(points).set("A3",vec2d(-400,0));
      qap_add_back(points).set("B",vec2d(+100,0));
      qap_add_back(points).set("B1",vec2d(-100,+100));
      qap_add_back(points).set("B2",vec2d(-100,-100));
      qap_add_back(points).set("B2x",vec2d(-100,-400));
      qap_add_back(points).set("B2y",vec2d(+100,-300));
      qap_add_back(points).set("Z",vec2d(+400,-300));
      qap_add_back(points).set("H",vec2d(+400,+300));
      qap_add_back(points).set("R",vec2d(-400,+300));
      qap_add_back(points).set("Ax",vec2d(-400,+150));
      qap_add_back(points).set("C",vec2d(+250,+100));
      qap_add_back(points).set("D",vec2d(+300,-100));
      qap_add_back(links).set("A","A1");
      qap_add_back(links).set("A","A2");
      qap_add_back(links).set("A1","A3");
      qap_add_back(links).set("A2","A3");
      qap_add_back(links).set("B","B1");
      qap_add_back(links).set("B","B2");
      qap_add_back(links).set("B2","B2x");
      qap_add_back(links).set("B2","B2y");
      qap_add_back(links).set("B2y","Z");
      qap_add_back(links).set("Z","H");
      qap_add_back(links).set("H","R");
      qap_add_back(links).set("R","Ax");
      qap_add_back(links).set("Ax","A3");
      qap_add_back(links).set("A","B");
      qap_add_back(links).set("B","C");
      qap_add_back(links).set("C","D");
    }
  }
public:
  PRO_FUNCGEN_GETP(t_point,getp,points,name);
  PRO_FUNCGEN_GETREF(t_point,getref,points,name);
public:
  static void DrawLine(QapDev&qDev,const vec2d&a,const vec2d&b,real line_size){
    qDev.DrawQuad((b+a)*0.5,(b-a).Mag(),line_size,(b-a).GetAng());
  }
  void step()
  {
    if(tick==64)
    {
      for(int i=0;i<points.size();i++)
      {
        auto&ex=points[i];
        //if(ex.deaded)continue;
        for(int i=0;i<links.size();i++)
        {
          auto&link=links[i];
          if(link.deaded)continue;
          auto cond=link.with(ex.name);
          if(cond)ex.send(link.other(ex.name),"UP");
        }
      }
    }
    tick++;
    for(int i=0;i<links.size();i++)
    {
      auto&ex=links[i];
      if(ex.deaded)continue;
      ex.update(*this);
    }
    for(int i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      if(ex.deaded)continue;
      if(!ex.cmds.empty())if(tick>ex.last_send+64)
      {
        auto&cmds=ex.cmds;
        for(int i=0;i<cmds.size();i++)
        {
          auto&cmd=cmds[i];
          auto*p=getplink(ex.name,cmd.to);
          QapAssert(p);
          p->send(ex.name,cmd.data,*this);break;
        }
        QapPopFront(ex.cmds);
        //ex.cmds.clear();
        ex.last_send=tick;
      }
      auto&msgs=ex.msgs;
      for(int i=0;i<msgs.size();i++)
      {
        auto&msg=msgs[i];
        if(msg.data=="UP")
        {
          ex.up(msg.from,msg.time);
        }
        auto a=split(msg.data,"  ");
        if(a.size()==3)
        {
          if(a[0]=="TFA"){ex.tfa(msg.time,msg.from,a[1],a[2]);}
        }
        if(a.size()==3)
        {
          if(a[0]=="TXT"){ex.txt(msg.from,a[1],a[2]);}
        }
        if(a.size()==3)
        {
          if(a[0]=="RND"){ex.rnd(msg.from,a[1],a[2]);}
        }
      }
      ex.msgs.clear();
    }
    //qap_clean_if_deaded(links);
    //qap_clean_if_deaded(points);
  }
  void DoMove()
  {
    auto&kb=win.Keyboard;
    scroll+=Sign(win.zDelta)*8;
    if(kb.OnDown(VK_HOME))scroll=0;
    if(kb.OnDown(VK_ESCAPE))win.Close();
    if(kb.OnDown(VK_SPACE))
    {
      pause=!pause;
      //getref("A3").send("A1","HI");
    }
    if(kb.OnDown(VK_F4))
    {
      make_link_info();
    }
    if((tick*0==50)||kb.OnDown(VK_F1))if(!kb.Down[VK_CONTROL])
    {
      for(int i=0;i<1024*5;i++){
        step();
      }
    }
    if(bool need_send_msg=true){
      bool on_R=kb.OnDown('R');
      bool on_T=kb.OnDown('T');
      if(on_R||on_T){
        auto dest_id=get_point_id_under_mouse(win.mpos);
        if(qap_check_id(points,dest_id)&&qap_check_id(points,sel_point))if(dest_id!=sel_point){
          auto&beg=points[sel_point];
          auto&end=points[dest_id];
          if(on_R)beg.rnd("DoMove::kb::R",beg.name+"->"+end.name,":D");
          if(on_T)beg.txt("DoMove::kb::T",beg.name+"->"+end.name,"HI");
        }
      }
    }
    if(kb.OnDown(mbLeft)&&(kb.Down[VK_SHIFT]||kb.Down[VK_CONTROL]))if(qap_check_id(points,sel_point))
    {
      auto&back=qap_add_back(points);
      back.name="P"+IToS(points.size()-1);
      back.pos=win.mpos;
      auto N=points[sel_point].name;
      qap_add_back(links).set(back.name,N).do_up_to_both_side(*this);
    }
    if(kb.OnDown(mbRight))
    {
      start_point=get_point_id_under_mouse(win.mpos);
    }
    if(kb.OnUp(mbRight)&&qap_check_id(points,start_point))
    {
      auto dest_id=get_point_id_under_mouse(win.mpos);
      if(qap_check_id(points,dest_id)&&qap_check_id(points,start_point))if(dest_id!=start_point)
      {
        qap_add_back(links).set(points[dest_id].name,points[start_point].name).do_up_to_both_side(*this);
      }
      start_point=-1;
    }
    if(qap_check_id(points,sel_point))
    {
      points[sel_point].pos+=4*get_dir_from_keyboard_wasd_and_arrows();
    }
    if(kb.OnDown('C'))for(;;)
    {
      //auto id=get_point_id_under_mouse(win.mpos);
      if(!qap_check_id(points,sel_point))break;
      points[sel_point].deaded=!points[sel_point].deaded;
      //sel_point=-1;
      break;
    }
    if(kb.OnDown(VK_ADD))
    {
      speed++;
    }
    if(kb.OnDown(VK_SUBTRACT))
    {
      speed--;
    }
    if(pause)
    {
      return;
    }
    for(int i=0;i<speed;i++)step();
  }
  void DoDraw()
  {
    auto&kb=win.Keyboard;
    int tc=8;
    auto r=get_point_r();
    QapDev::BatchScope Scope(qDev);
    vec2d mpos=win.GetMousePos();
    qDev.BindTex(0,nullptr);
    qDev.SetColor(0xff000000);
    DrawText(-win.GetClientSize().x/2+64,win.GetClientSize().y/2-64,"DemoNetwork.",16);
    for(int i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      bool is_start=start_point==i;
      bool is_selected=sel_point==i;
      qDev.SetColor(is_selected?0xffaa0000:0xff000000);
      if(is_start){
        qDev.SetColor(0xff00aa00);
      }
      if(ex.deaded)qDev.color.a=0x20;
      qDev.DrawCircle(ex.pos,r,0,is_selected?4:2,32);
      //qDev.SetColor(0xffffffff);
      qDev.SetColor(0xff000000);
      DrawText(ex.pos.x-tc,ex.pos.y+tc/*+r*2*/,ex.name,16);
    }
    if(qap_check_id(points,start_point))
    {
      auto dest_id=get_point_id_under_mouse(win.mpos);
      vec2d a=win.mpos;
      if(qap_check_id(points,dest_id))a=points[dest_id].pos;
      qDev.SetColor(0xff00aa00);
      auto b=points[start_point].pos;
      vec2d o=(a-b).Ort().SetMag(r);
      DrawLine(qDev,a+o,b+o,2);
      DrawLine(qDev,a-o,b-o,2);
    }
    if(kb.Down[VK_SHIFT]||kb.Down[VK_CONTROL])if(qap_check_id(points,sel_point))
    {
      qDev.SetColor(0xff000000);
      qDev.DrawCircle(win.mpos,r,0,1,32);
      auto a=mpos;auto b=points[sel_point].pos;
      vec2d o=(a-b).Ort().SetMag(r);
      DrawLine(qDev,a+o,b+o,1);
      DrawLine(qDev,a-o,b-o,1);
    }
    for(int i=0;i<links.size();i++)
    {
      auto&link=links[i];
      auto*pa=getp(link.a);
      auto*pb=getp(link.b);
      if(!pa||!pb)continue;
      auto a=pa->pos;auto b=pb->pos;
      qDev.SetColor(0xff000000);
      if(link.is_down(*this))qDev.color.a=0x20;
      vec2d o=(a-b).Ort().SetMag(r);
      DrawLine(qDev,a+o,b+o,2);
      DrawLine(qDev,a-o,b-o,2);
      auto&objs=link.objs;
      for(int i=0;i<objs.size();i++)
      {
        auto&ex=objs[i];
        auto from=link.get_from(*this,ex).pos;
        auto to=link.get_to(*this,ex).pos;
        auto p=from+(to-from).SetMag(abs(ex.pos));
        p+=o*ex.v;
        qDev.DrawCircleEx(p,r/2,0,3,(to-from).GetAng());
        DrawText(p.x,p.y+r*2,ex.data,16);
      }
    }
    if(kb.OnDown(mbLeft)&&!kb.Down[VK_CONTROL])
    {
      auto&mpos=win.mpos;
      int id=get_point_id_under_mouse(mpos);
      sel_point=id;
    }
    if(!qap_check_id(points,sel_point))sel_point=0;
    if(qap_check_id(points,sel_point))
    {
      qDev.SetColor(0xff000000);
      int textsize=16; int dy=-textsize*1;
      vec2i p(-win.GetClientSize().x/2+64,dy*scroll+win.GetClientSize().y/2-64);p.y+=dy;
      #define F(MSG)DrawText(p.x,p.y,MSG,textsize);p.y+=dy;
      F("tick = "+IToS(tick));
      F("speed = "+IToS(speed));
      F("sel_point = "+IToS(sel_point));
      F("name = "+points[sel_point].name);
      auto&ref=points[sel_point];
      for(int j=0;j<ref.links.size();j++)
      {
        auto&link=ref.links[j];
        F("link["+IToS(j)+"].name = "+link.name);
        F("link["+IToS(j)+"].time = "+IToS(link.time));
        auto&arr=link.routes;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          F("time[\""+link.name+"->"+ex.name+"\"] = "+IToS(link.time+ex.t));
        }
      }
      #undef F
    }
  }
public:
  int get_point_id_under_mouse(vec2i pos)
  {
    auto r=get_point_r();
    for(int i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      if((ex.pos-pos).Mag()>r)continue;
      return i;
    }
    return -1;
  }
  t_link*getplink(string a,string b)
  {
    t_link*p=nullptr;
    for(int i=0;i<links.size();i++){
      auto&ex=links[i];
      auto ok=ex.cmp(a,b);
      if(!ok)continue;
      QapAssert(!p);
      p=&ex;
    }
    return p;
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}
#include "StdAfx.h"

class TBookPageWithALotOfBalls:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithALotOfBalls)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TResourceHolder,ResHolder,DEF,$,$)\
ADDVAR(TWeakPtr<QapTexObject>,pTex,DEF,$,$)\
ADDVAR(int,n,SET,1,$)\
ADDVAR(real,r,SET,64,$)\
ADDVAR(QapColor,color,SET,0xffffffff,$)\
ADDEND()
//=====+>>>>>TBookPageWithALotOfBalls
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithALotOfBalls
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    qDev.BindTex(0,0);
    //auto&pTex=con.root.SysRes.BallTex
    auto&pTex=this->pTex;
    if(pTex)
    {
      auto&tex=pTex->Tex;
      //auto toffset=vec2f(+0.5/real(tex.W),+0.5/real(tex.H));
      qDev.SetColor(color);
      qDev.BindTex(0,&tex);
      auto&p=con.pos;
      vec2i pos=vec2i(p.x,p.y);
      //auto tt=qDev.GetTextureTransform();
      //qDev.SetTextureTransform(transform2f(toffset));
      for(int i=0;i<n;i++)qDev.DrawQuad(pos+vec2d(-0.5,+0.5),r*2.0,r*2.0);
      //qDev.SetTextureTransform(tt);
    }
    qDev.BindTex(0,0);
    qDev.SetColor(0xff000000);
  }
  void Update(t_context&con)
  {
    if(pTex)return;
    pTex=con.root.ResList.AddItem<QapTexObject>(con.Env,ResHolder,"TBookPageWithALotOfBalls");
    pTex->SetToDef();
    pTex->File.FN="?GenRect(128)";
    pTex->Run(con.Env,&con.root.D9Dev);
  }
};

#include "Gateway.h"
#include "Gateway.cpp"

#include "TSimpleBinarySaver.inl"

class t_actor{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_actor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,spawn_tick,DEF,$,$)\
ADDVAR(int,spawn_time,SET,32,$)\
ADDVAR(bool,need_spawn_obstacle,DEF,$,$)\
ADDEND()
//=====+>>>>>t_actor
#include "QapGenStruct.inl"
//<<<<<+=====t_actor
public:/*
  void copy_from(const t_actor&ref)
  {
    this->name=ref.name;
    this->actor_id=ref.actor_id;
    this->pos=ref.pos;
    this->v=ref.v;
    this->tick=ref.tick;
  }
  static string toBin(const string&str)
  {
    string out;
    out.resize(sizeof(int));
    *((int*)&out[0])=str.size();
    out+=str;
    return out;
  }
  static string toBin(const int&v)
  {
    string out;
    out.resize(sizeof(v));
    *((int*)&out[0])=v;
    return out;
  }
  static string toBin(const vec2d&v)
  {
    string out;
    out.resize(sizeof(v));
    *((vec2d*)&out[0])=v;
    return out;
  }
  static string toBin(const t_actor&ref)
  {
    string out;
    out+=toBin(ref.name);
    out+=toBin(ref.actor_id);
    out+=toBin(ref.pos);
    out+=toBin(ref.v);
    out+=toBin(ref.tick);
    return out;
  }
  static void fromBin(TQapIO&IO,t_actor&ref)
  {
    IO.load(ref.name);
    IO.load(ref.actor_id);
    IO.load(ref.pos.x);
    IO.load(ref.pos.y);
    IO.load(ref.v.x);
    IO.load(ref.v.y);
    IO.load(ref.tick);
  }*/
};

class t_bullet{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bullet)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,v,DEF,$,$)\
ADDEND()
//=====+>>>>>t_bullet
#include "QapGenStruct.inl"
//<<<<<+=====t_bullet
public:
};

class t_obstacle{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_obstacle)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDEND()
//=====+>>>>>t_obstacle
#include "QapGenStruct.inl"
//<<<<<+=====t_obstacle
public:
};

class t_rect{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,actor_id,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,size,DEF,$,$)\
ADDVAR(vector<t_obstacle>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_rect
#include "QapGenStruct.inl"
//<<<<<+=====t_rect
public:
};

class t_world{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_world)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,game_time,DEF,$,$)\
ADDVAR(vector<t_actor>,actors,DEF,$,$)\
ADDVAR(vector<t_bullet>,bullets,DEF,$,$)\
ADDVAR(vector<t_obstacle>,obstacles,DEF,$,$)\
ADDVAR(int,obstacle_r,SET,8,$)\
ADDEND()
//=====+>>>>>t_world
#include "QapGenStruct.inl"
//<<<<<+=====t_world
public:
  void update_actors()
  {
    auto&arr=actors;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.tick++;
      ex.pos+=ex.v;
      if(ex.spawn_tick)ex.spawn_tick--;
      if(ex.need_spawn_obstacle)if(!ex.spawn_tick)
      {
        ex.spawn_tick=ex.spawn_time;
        auto&back=qap_add_back(obstacles);
        back.actor_id=ex.actor_id;
        back.pos=ex.pos+vec2d(obstacle_r*2,0);
      }
      ex.need_spawn_obstacle=false;
    }
  }
  void update_bullets()
  {
    auto&arr=bullets;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.pos+=ex.v;
    }
  }
  void load_level()
  {
    string level=file_get_contents("level_0.h");
    vector<string> arr=split(level,"\n");
    int h=-1;
    int w=-1;
    int low_x=level.size()+1;
    int low_y=level.size()+1;
    for(int y=0;y<arr.size();y++)
    {
      auto&ex=arr[y];
      for(int x=0;x<ex.size();x++)
      {
        if(ex[x]!='#')continue;
        w=std::max(w,x);
        h=std::max(h,y);
        low_x=std::min(low_x,x);
        low_y=std::min(low_y,y);
      }
    }
    if(w<0||h<0)return;
    w-=low_x;w++;
    h-=low_y;h++;
    auto cell_size=obstacle_r*2;
    vec2d offset=-vec2d(w*0.5,-h*0.5)-vec2d(low_x,-low_y);
    for(int y=0;y<arr.size();y++)
    {
      auto&ex=arr[y];
      for(int x=0;x<ex.size();x++)
      {
        if(ex[x]!='#')continue;
        auto&back=qap_add_back(obstacles);
        back.actor_id=-1;
        back.pos=cell_size*(vec2d(x+0.5,-y-0.5)+offset);
        back.pos.x=int(back.pos.x);
        back.pos.y=int(back.pos.y);
      }
    }
    //
    int gg=1;
  }
  void update()
  {
    game_time++;
    update_actors();
    update_bullets();
    if(game_time==64)load_level();
  }
};

class t_server{
public:
  class t_response{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_response)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,client_id,DEF,$,$)\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_response
    #include "QapGenStruct.inl"
    //<<<<<+=====t_response
  public:
  };
  class t_request{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_request)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,client_id,DEF,$,$)\
    ADDVAR(string,cmd,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_request
    #include "QapGenStruct.inl"
    //<<<<<+=====t_request
  public:
  };
  class t_rec{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rec)OWNER(t_server)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,client_id,DEF,-1,$)\
    ADDVAR(int,world_actor_id,SET,-1,$)\
    ADDVAR(string,connect_time,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_rec
    #include "QapGenStruct.inl"
    //<<<<<+=====t_rec
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(t_request)F(t_response)F(t_rec)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_server)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_world,world,DEF,$,$)\
ADDVAR(int,next_actor_id,DEF,$,$)\
ADDVAR(vector<t_rec>,clients_res,DEF,$,$)\
ADDVAR(vector<t_request>,fromClients,DEF,$,$)\
ADDVAR(vector<t_response>,toClients,DEF,$,$)\
ADDEND()
//=====+>>>>>t_server
#include "QapGenStruct.inl"
//<<<<<+=====t_server
public:
  void update(IEnvRTTI&Env)
  {
    world.update();
    handle_requests(Env);
  }
  void add_from_client(int client_id,const string&cmd)
  {
    fromClients.resize(fromClients.size()+1);
    fromClients.back().client_id=client_id;
    fromClients.back().cmd=cmd;
  }
  t_actor*find_actor_by_actor_id(int id)
  {
    t_actor*out=nullptr;
    auto&arr=world.actors;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.actor_id==id)
      {
        QapAssert(!out);
        out=&ex;
      }
    }
    return out;
  }
  t_actor*find_actor_by_client_id(int id)
  {
    t_actor*out=nullptr;
    auto&arr=clients_res;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.client_id==id)
      {
        QapAssert(!out);
        auto*ptr=find_actor_by_actor_id(ex.world_actor_id);
        QapAssert(ptr);
        out=ptr;
      }
    }
    return out;
  }
  void handle_request(IEnvRTTI&Env,t_request&ref)
  {
    auto spawn_obstacle=[](t_server&serv,t_request&ref,const string&cmd_code)->bool
    {
      if(ref.cmd!=cmd_code)return false;
      auto*ptr=serv.find_actor_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return false;
      ptr->need_spawn_obstacle=true;
      return true;
    };
    if(spawn_obstacle(*this,ref,"spawn_obstacle();"))return;
    if(ref.cmd=="init();")
    {
      clients_res.push_back(std::move(t_rec()));
      auto&back=clients_res.back();
      back.client_id=ref.client_id;
      back.world_actor_id=next_actor_id;
      back.connect_time=cur_date_str();
      world.actors.resize(world.actors.size()+1);
      auto&actor=world.actors.back();
      actor.actor_id=next_actor_id;
      actor.pos=vec2d(rand()%512,rand()%512)-vec2d(1,1)*256;
      actor.name="client_"+IToS(next_actor_id);
      next_actor_id++;
      return;
    }
    if(ref.cmd=="get_world_state();")
    {
      toClients.resize(toClients.size()+1);
      /*static real ta=0;static real tb=0;static int passed=0;passed++;
      QapClock a;
      a.Start();
      string a_result=TSimpleBinarySaver::toStr(Env,&world);
      a.Stop();
      ta+=a.MS();
      QapClock b;
      b.Start();
      string b_result=world.toBin();
      b.Stop();
      tb+=b.MS();
      //
      real taps=ta/real(passed);
      real tbps=tb/real(passed);
      {
        int gg=1;
      }
      //
      QapAssert(a_result==b_result);*/
      string bin_world=TSimpleBinarySaver::toStr(Env,&world);
      //string bin_world=world.toBin();
      toClients.back().body=TSimpleBinarySaver::toStr(Env,&bin_world);
      toClients.back().client_id=ref.client_id;
      return;
    }
    auto func=[](t_server&serv,t_request&ref,const string&cmd_code)->vec2d*
    {
      if(ref.cmd!=cmd_code)return nullptr;
      auto*ptr=serv.find_actor_by_client_id(ref.client_id);
      QapAssert(ptr);
      if(!ptr)return nullptr;
      return &ptr->v;
    };
    #define F(CODE){vec2d*pv=func(*this,ref,#CODE);if(pv){*p##CODE;return;}}
    F(v=vec2d(+1,+0);)
    F(v=vec2d(+0,+1);)
    F(v=vec2d(-1,+0);)
    F(v=vec2d(+0,-1);)
    F(v=vec2d(+0,+0);)
    F(v=vec2d(+1,+1);)
    F(v=vec2d(-1,+1);)
    F(v=vec2d(-1,-1);)
    F(v=vec2d(+1,-1);)
    #undef F
    QapDebugMsg("unknow request:\n\""+CppString(ref.cmd).data+"\"");
  }
  void handle_requests(IEnvRTTI&Env)
  {
    auto&arr=fromClients;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      handle_request(Env,ex);
    }
    arr.clear();
  }
};

static void render_world(IBookPage::t_context&con,const t_world&world,const QapColor&color,real r)
{
  auto&qDev=con.qDev;
  auto half_offset=vec2d(-0.5,+0.5);
  qDev.BindTex(0,0);
  if(con.root.SysRes.BallTex)
  {
    qDev.SetColor(color);
    qDev.BindTex(0,&con.root.SysRes.BallTex->Tex);
    QapDev::BatchScope Scope(qDev);
    //actors
    {
      auto&arr=world.actors;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(int_pos+half_offset,r*2.0,r*2.0);
      }
    }
    //obstacles
    {
      auto&r=world.obstacle_r;
      auto&arr=world.obstacles;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&pos=ex.pos;
        auto p=con.pos+pos;
        vec2i int_pos=vec2i(p.x,p.y);
        qDev.DrawQuad(int_pos+half_offset,r*2.0,r*2.0);
      }
    }
    //cell
    if(con.is_hovered())
    {
      auto mpos=con.get_mpos();
      auto r=world.obstacle_r;
      auto r2=r*2;
      auto align=[r,r2](real x)->int{int c=1024*8;return ((int(x+c)/r2))*r2+r-c;};
      mpos.x=align(mpos.x);
      mpos.y=align(mpos.y);
      mpos+=con.pos;
      qDev.SetColor(0x80ffffff);
      qDev.DrawQuad(mpos+half_offset,r2,r2);
    }
  }
  if(con.root.SysRes.FontObj)
  {
    qDev.SetColor(color);
    qDev.BindTex(0,&con.root.SysRes.FontObj->Tex);
    QapDev::BatchScope Scope(qDev);
    auto&font=con.root.SysRes.FontObj->Font;
    auto&arr=world.actors;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&pos=ex.pos;
      vec2d p=con.pos+pos+vec2d(-QapQ3Text::GetLength(font,ex.name)*0.5,-font.Info[0].y);
      QapQ3Text::DrawQapText(&qDev,font,int(p.x),int(p.y),ex.name);
    }
  }
  qDev.BindTex(0,0);
  qDev.SetColor(0xff000000);
}

class T20130410_GatewayServer{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_GatewayServer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(GatewayServer,serv,SYD,$,$)\
ADDEND()
//=====+>>>>>T20130410_GatewayServer
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_GatewayServer
public:
};

class TSoketItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSoketItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,time,DEF,$,$)\
ADDVAR(string,data,DEF,$,$)\
ADDEND()
//=====+>>>>>TSoketItem
#include "QapGenStruct.inl"
//<<<<<+=====TSoketItem
public:
};

class T20130410_Socket{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_Socket)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,socket,SET,0,$)\
ADDVAR(string,addr,DEF,$,$)\
ADDVAR(vector<string>,addtime,DEF,$,$)\
ADDVAR(vector<TSoketItem>,news,DEF,$,$)\
ADDVAR(string,content,DEF,$,$)\
ADDVAR(vector<string>,deltime,DEF,$,$)\
ADDVAR(vector<string>,offtime,DEF,$,$)\
ADDVAR(vector<string>,errtime,DEF,$,$)\
ADDEND()
//=====+>>>>>T20130410_Socket
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_Socket
public:
};

class TBookPageWithGameServer20140611:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithGameServer20140611)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,auto_restart,SET,true,$)\
ADDVAR(int,Port,SET,81,$)\
ADDVAR(TAutoPtr<T20130410_GatewayServer>,Server,DEF,$,$)\
ADDVAR(vector<T20130410_Socket>,sockets,DEF,$,$)\
ADDVAR(vector<T20130410_Socket>,olds,DEF,$,$)\
ADDVAR(real,r,SET,16,$)\
ADDVAR(real,ls,SET,4,$)\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(QapColor,color,SET,0xffffffff,$)\
ADDVAR(t_server,game_server,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithGameServer20140611
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithGameServer20140611
public:
  class TServerCallback:public ServerCallback{
  public:
    IEnvRTTI&Env;
    TBookPageWithGameServer20140611&owner;
    TServerCallback(IEnvRTTI&Env,TBookPageWithGameServer20140611&owner):Env(Env),owner(owner){}
  public:
    void handle(Socket*client,T20130410_Socket&s)
    {
      for(;;)
      {
        int e=0;
        string key=ScanParam("",s.content,"\n",e);
        if(e<0)return;
        e+=key.size()+string("\n").size();
        s.content=s.content.substr(e);
        t_server::t_request request;
        request.client_id=s.socket;
        request.cmd=key;
        owner.game_server.fromClients.push_back(std::move(request));
      }
    }
  public:
    void OnRecvPack(Socket*client,std::string&data)
    {
      int id=owner.find_socket_id(owner.sockets,client->sock);
      QapAssert(id>=0);
      auto&s=owner.sockets[id];
      s.news.push_back(TSoketItem());
      s.news.back().time=cur_date_str();
      s.news.back().data=data;
      if(s.news.size()>128)subarr_in_place(s.news,1);
      s.content+=data;
      handle(client,s);
      return;
      string answer="answer";
      client->send_raw(answer);
      shutdown(client->sock,SD_BOTH);
    }
    void OnAddClient(Socket*client)
    {
      client->set_auto_flush(true);
      int id=owner.find_socket_id(owner.sockets,client->sock);
      QapAssert(id<0);
      owner.sockets.push_back(T20130410_Socket());
      auto&s=owner.sockets.back();
      s.socket=client->sock;
      s.addr=client->name();
      s.addtime.push_back(cur_date_str());
    }
    void OnDeleteClient(Socket*client)
    {
      int id=owner.find_socket_id(owner.sockets,client->sock);
      QapAssert(id>=0);
      owner.sockets[id].deltime.push_back(cur_date_str());
      vector<T20130410_Socket> tmp;
      auto&arr=owner.sockets;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(i!=id)tmp.push_back(std::move(ex));
        if(i==id)owner.olds.push_back(std::move(ex));
      }
      owner.sockets=std::move(tmp);
    }
  };
public:
  void Update(IEnvRTTI&Env)
  {
    if(!Enabled)return;
    if(Server&&!Server->serv.runned)
    {
      auto&arr=sockets;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.offtime.push_back(cur_date_str());
        olds.push_back(std::move(ex));
      }
      arr.clear();
      Server=nullptr;
    }
    if(auto_restart&&!Server)
    {
      auto*pServer=Server.build<T20130410_GatewayServer>(Env);
      auto&serv=pServer->serv;
      serv.port=Port;
      serv.raw=true;
      serv.start_tcp();
      serv.start_udp();
    }
    if(Server)
    {
      auto*pServer=Server.get();
      auto&serv=pServer->serv;
      TServerCallback cb(Env,*this);
      serv.callback=&cb;
      serv.update_tcp();
      serv.update_lan();
      serv.callback=nullptr;
    }
  }
public:
  static int find_socket_id(vector<T20130410_Socket>&arr,int id)
  {
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i].socket!=id)continue;
      return i;
    }
    return -1;
  }
  static T20130410_Socket*find_socket_by_client_id(vector<T20130410_Socket>&arr,int id)
  {
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i].socket!=id)continue;
      return &arr[i];
    }
    return nullptr;
  }
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    qDev.BindTex(0,0);
    if(con.root.SysRes.BallTex)
    {
      qDev.SetColor(color);
      qDev.BindTex(0,&con.root.SysRes.BallTex->Tex);
      qDev.DrawQuad(con.pos,r*2.0,r*2.0);
    }
    qDev.BindTex(0,0);
    qDev.SetColor(0xff000000);
  }
  void Update(t_context&con)
  {
    if(need_init){
      need_init=false;
      Caption="GameServer";
    }
    Update(con.Env);
    game_server.update(con.Env);
    clean_clients();
    gs_update_toClients();
    //GatewayClient gc;
    //gc.start();
  }
  void clean_clients()
  {
    auto&arr=game_server.clients_res;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*client=find_socket_by_client_id(sockets,ex.client_id);
      if(!client)
      {
        ex.client_id=-1;
        auto*ptr=game_server.find_actor_by_actor_id(ex.world_actor_id);
        if(ptr){
          ptr->name+="[offline]";
          ptr->v=vec2d_zero;
          ptr->actor_id=-1;
        }
      }
    }
    QapCleanIf(arr,[](const t_server::t_rec&ref){return ref.client_id<0;});
    QapCleanIf(game_server.world.actors,[](const t_actor&ref){return ref.actor_id<0;});
  }
  void gs_update_toClients()
  {
    auto&serv=Server->serv;
    auto&arr=game_server.toClients;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      QapAssert(ex.client_id>=0);
      auto*client=find_socket_by_client_id(sockets,ex.client_id);
      if(!client)continue;
      auto*client_sock=serv.getClientBySock(client->socket);
      QapAssert(client);
      serv.send_one(ex.body,client_sock);
    }
    arr.clear();
  }
};

class T20130410_GatewayClient{
public:
#define DEF_PRO_POOR_DESIGN()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(T20130410_GatewayClient)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(GatewayClient,client,SYD,$,$)\
ADDEND()
//=====+>>>>>T20130410_GatewayClient
#include "QapGenStruct.inl"
//<<<<<+=====T20130410_GatewayClient
public:
};

class TBookPageWithGameClient20140609:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithGameClient20140609)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,state,DEF,$,$)\
ADDVAR(bool,auto_reconnect,SET,true,$)\
ADDVAR(bool,auto_restart,SET,true,$)\
ADDVAR(bool,need_show_state,SET,true,$)\
ADDVAR(bool,auto_hide_state,SET,true,$)\
ADDVAR(string,mode,SET,"kb",$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,Port,SET,81,$)\
ADDVAR(string,info,DEF,$,$)\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(TAutoPtr<T20130410_GatewayClient>,Client,DEF,$,$)\
ADDVAR(t_world,world,DEF,$,$)\
ADDVAR(real,r,SET,16,$)\
ADDVAR(QapColor,color,SET,0xffffffff,$)\
ADDVAR(string,buff,DEF,$,$)\
ADDVAR(int,max_items,SET,128,$)\
ADDVAR(vector<TSoketItem>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithGameClient20140609
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithGameClient20140609
public:
  class MeClientCallback:public ClientCallback{
  public:
    SelfClass&owner;
    MeClientCallback(SelfClass&owner):owner(owner){}
  public:
    void OnRecvPack(string&data){
      TSoketItem tmp;
      tmp.time=cur_date_str();
      tmp.data=data;
      owner.items.push_back(std::move(tmp));
      owner.buff+=data;
    }
    void OnSendPack(string&data){
    }
    void OnConnect(Socket*S){
    }
    void OnDisconnect(){
    }
  };
public:
  void Render(t_context&con)
  {
    if(!con.root.SysRes.FontObj)return;
    if(need_show_state)
    {
      auto*pFont=con.root.SysRes.FontObj.get();
      auto&font=pFont->Font;
      con.qDev.BindTex(0,&pFont->Tex);
      vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),state);
      con.qDev.BindTex(0,0);
    }
    render_world(con,world,color,r);
  }
  void Update(t_context&con)
  {
    if(need_init)
    {
      need_init=false;
      Caption="GameClient";
    }
    UpdateFull(con);
  }
  void UpdateFull(t_context&con)
  {
    if(!Client&&auto_restart)
    {
      auto*ptr=Client.build<T20130410_GatewayClient>(con.Env);
      auto&c=ptr->client;
    }
    if(!Client){info="no client";return;}info="client";
    auto&c=Client->client;
    MeClientCallback cb(*this);
    QapAssert(!c.callback);
    c.callback=&cb;
    if(c.runned)if(c.port!=Port){
      Client=nullptr;return;
    }
    if(!c.runned)
    {
      QapAssert(!c.server);
      c.port=81;
      c.start();
      c.scan_lan_begin();
      state="scan_lan";
    }
    c.scan_lan_result();
    if(c.runned)info+="|runned";
    if(!c.runned)info+="|no_runned";
    if(c.scanning_lan)info+="|scan";
    if(!c.scanning_lan)info+="|no_scan";
    if(c.server)info+="|serv";
    if(!c.server)info+="|no_serv";
    if(c.server)if(c.server->s.connected)info+="|connected";
    if(c.server)if(!c.server->s.connected)info+="|no_connected";
    if(c.server)if(!c.server->s.connected)if(state!="scan_lan")if(state!="connect_result")if(state!="disconnected")
    {
      need_show_state=true;
      state="disconnected";
      tick=128;
    }
    if(state=="disconnected")if(auto_reconnect)
    {
      if(!tick){Client=nullptr;return;}
      tick--;
    }
    if(state=="scan_lan")
    {
      if(tick>128){
        tick=0;
        c.scan_lan_end();
        c.scan_lan_begin();
      }else{tick++;}
    }
    if(state=="scan_lan")
    {
      c.scan_lan_result();
      if(!c.servers.empty())
      {
        c.select(0);
        c.connect_begin();
        c.scan_lan_end();
        state="connect_result";
      }
    }
    if(state=="connect_result")
    {
      if(c.connect_result())
      {
        cb.OnConnect(&c.server->s);
        c.server->s.set_auto_flush(true);
        state="send_to_server_raw_init";
        tick=0;
      }
    }
    string request;
    if(state=="send_to_server_raw_init")
    {
      request+="init();\n";
      state="send_to_server_raw";
    }
    if(state=="recv_from_server")
    {
      c.recv_from_server_raw();
    }
    load_world_from_buff(con.Env);
    if(state=="send_to_server_raw")
    {
      request+="get_world_state();\n";
      state="recv_from_server";
      if(mode=="kb")if(con.is_hovered())
      {
        vec2i v;
        #define F(dx,dy,key)if(con.kb.Down[key]){v.x+=dx;v.y+=dy;}
        F(-1,+0,VK_LEFT);
        F(+1,+0,VK_RIGHT);
        F(+0,+1,VK_UP);
        F(+0,-1,VK_DOWN);
        #undef F
        if(con.kb.Down[VK_SPACE]){
          request+="spawn_obstacle();\n";
        }
        auto f=[](int i){return i>=0?"+"+IToS(i):IToS(i);};
        request+="v=vec2d("+f(v.x)+","+f(v.y)+");\n";
      }
      if(mode=="m0")
      {
        QapAssert(tick>=0);
        auto t=tick/64;
        static string arr[]={
          "v=vec2d(+1,+0);",
          "v=vec2d(+0,+0);",
          "v=vec2d(+0,+0);",
          "v=vec2d(-1,+0);",
          "v=vec2d(+0,+0);",
          "v=vec2d(-1,+0);",
          "v=vec2d(+0,+0);",
          "v=vec2d(+1,+0);",
        };
        request+=arr[t%lenof(arr)]+"\n";
        tick++;
      }
      {
        int offset=int(items.size())-max_items;
        if(offset<0)offset=0;
        subarr_in_place(items,offset);
      }
    }
    if(!request.empty())
    {
      c.send_to_server_raw(request);
    }
    c.callback=nullptr;
  }
  void load_world_from_buff(IEnvRTTI&Env)
  {
    for(;;)
    {
      if(buff.size()<4)return;
      auto&size=*(int*)&buff[0];
      if(size+4>buff.size())return;
      string response=buff.substr(4,size);
      TSimpleBinaryLoader::fromStr(Env,&world,response);
      buff=buff.substr(4+size);
      state="send_to_server_raw";
      if(auto_hide_state)need_show_state=false;
    }
  }
};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TBookPageWithGameServer20140611)F(TBookPageWithGameClient20140609)\
        F(TBookPageWithALotOfBalls)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit()
    {
    }
  };
  ThisCompileUnit ThisUnit;
}
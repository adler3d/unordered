#include "QapLite.h"

#define DEF_PRO_SORT_BY_FIELD(sort_by_field,TYPE,FIELD)\
  struct t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD{\
    static int __cdecl cmp_func(const void*a,const void*b){return cmp(*(TYPE*)a,*(TYPE*)b);}\
    static int cmp(const TYPE&a,const TYPE&b){return a.FIELD-b.FIELD;}\
  };\
  void sort_by_field(vector<TYPE>&arr){\
    if(arr.empty())return;\
    std::qsort(&arr[0],arr.size(),sizeof(t_id_with_dist),t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD::cmp_func);\
  }
#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#include "TQapGameV2.inl"

#define DEF_PRO_PROXY_GAME_FIELD(VAR)auto&VAR=game.VAR;
#define DEF_PRO_PROXY_UNIT_FIELD(VAR)auto&VAR=unit.input.VAR;
#define DEF_PRO_PROXY_GUI_FIELD(VAR)auto&VAR=unit.gui.VAR;
#define DEF_PRO_FIELDS_FROM_GAME(F)F(drawpass)F(movepass)F(srvpass)F(cntpass)F(qDev)F(viewport)/*F(textsize)F(r)*/
#define DEF_PRO_FIELDS_FROM_UNIT(F)F(kb)F(mpos)F(consize)
#define DEF_PRO_FIELDS_FROM_GUI(F)F(menu)/*F(bags)*/F(pitems)F(dd_from)F(dd_to)F(trade)F(status)F(trade_requests)
#define SO_PASS()DEF_PRO_FIELDS_FROM_GAME(DEF_PRO_PROXY_GAME_FIELD);
#define SO_UNIT()DEF_PRO_FIELDS_FROM_UNIT(DEF_PRO_PROXY_UNIT_FIELD)
#define SO_GUI()DEF_PRO_FIELDS_FROM_GUI(DEF_PRO_PROXY_GUI_FIELD)
#define SO_HEAD()SO_PASS();SO_UNIT()

class TGame:public TQapGameV2{
public:
  struct t_menu{
    bool enabled=false;
    bool wait_next_tick=false;
    vec2d pos;
    string target;
    vector<string> lines;
    string caption;
    void fill(string caption)
    {
      this->caption=caption;
      lines=split("lock,invite,trade,ignore",",");
    }
  };
public:
  class t_item{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(bool,deaded,false)\
    ADD(bool,selected,false)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_item(){DoReset();}
    t_item&set(string n){name=n;return *this;}
  };
  class t_bag{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec2d,pos,$)\
    ADD(vector<t_item>,arr,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_bag(){DoReset();}
    void do_fix(){
      QapAssert(arr.size()<=5);
      if(arr.size()==5)return;
      for(int i=arr.size();i<5;i++){
        qap_add_back(arr).deaded=true;
      }
    }
    t_bag&add(string name){do_fix();QapAssert(try_insert(name));return *this;}
    bool try_insert(string name)
    {
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.deaded){ex.name=name;ex.deaded=false;return true;}
      }return false;
    }
    bool empty(){for(int i=0;i<arr.size();i++)if(!arr[i].deaded){return false;}return true;}
  };
  class t_dd_point{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,comment,$)\
    ADD(int,id,-1)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_dd_point(){DoReset();}
    operator bool()const{return id>=0;}
  };
public:
  class t_trade_requests{
  public:
    int actor_id=-1;
    int tick=-1;
    bool deaded=false;
    template<class t_world>
    void update(t_world&world)
    {
      if(world.tick-tick>world.traderequest_lifetime)deaded=true;
    }
    t_trade_requests&set_tick(int v){tick=v;return *this;}
  };/*
  struct t_accept{
    vector<char> arr;
    bool empty()const{QapAssert(arr.size()<=1);return arr.empty();}
    bool is_accept()const{QapAssert(arr.size()<=1);return empty()?false:arr[0]=='A';}
    void clear(){arr.clear();}
    void set_true(){QapAssert(arr.size()==0);arr.push_back('A');}
    void set_false(){QapAssert(arr.size()==0);arr.push_back('D');}
   
  }; */
  class t_trade{
  public:
    bool enabled=false;
    int actor_id=-1;
    int private_tick=0;
    bool accept=false;
    operator bool&(){return enabled;}
    void operator=(const bool&value){enabled=value;}
    template<class t_world,class t_unit>
    void set_tick(t_world&world,t_unit&unit,int value)
    {
      private_tick=value;accept=false;world.getp(actor_id)->gui.trade.accept=false;
    }
    template<class t_world,class t_unit>
    int get_max_tick(t_world&world,t_unit&unit)
    {
      QapAssert(world.getp(actor_id));
      return std::max(world.getp(actor_id)->gui.trade.private_tick,private_tick);
    }
    template<class t_world,class t_unit>
    real get_trade_progress(t_world&world,t_unit&unit,int cur_tick,int trade_duration)
    {
      if(!enabled)return 0;
      auto max_tick=get_max_tick(world,unit);
      return std::min(trade_duration,(cur_tick-max_tick))/real(trade_duration);
    }
  };
  class t_unit_gui{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_menu,menu,$)\
    ADD(vector<t_item>,pitems,$)\
    /*ADD(vector<t_item>,bitems,$)*/\
    ADD(vector<t_trade_requests>,trade_requests,$)\
    ADD(t_dd_point,dd_from,$)\
    ADD(t_dd_point,dd_to,$)\
    ADD(t_trade,trade,$)\
    ADD(string,status,"nothing")\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_unit_gui(){
      DoReset();
    }
  };
  struct t_unit{
    t_input input;
    string name;
    vec2d pos;
    bool deaded=false;
    t_unit_gui gui;
    t_unit&set(string nick){name=nick;return *this;}
    t_unit&set_pos(const vec2d&new_pos){pos=new_pos;return *this;}
    t_unit&set_pos(const real&x,const real&y){pos=vec2d(x,y);return *this;}
    PRO_FUNCGEN_GETP_BY_FIELD(t_trade_requests,get_trade_requests_by_actor_id,gui.trade_requests,int,actor_id);
  };
  class t_world{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,tick,0)\
    ADD(vector<t_unit>,units,$)\
    ADD(vector<t_bag>,bags,$)\
    ADD(int,last_actor_id,-1)\
    ADD(t_input,input,$)\
    ADD(int,r,24)\
    ADD(int,trade_buttons_x_offset,175)\
    ADD(int,textsize,16)\
    ADD(int,trade_duration,64)\
    ADD(int,traderequest_lifetime,64*20)\
    //===
    #include "defprovar.inl"
    //===
  public:
    t_world(){
      DoReset();SetToDef();
    }
    void SetToDef(){
      //qap_add_back(units).set("user").pos=vec2d(0,-250);
      //qap_add_back(units).set("bot").pos=vec2d(0,+250);
    }
    PRO_FUNCGEN_GETP_BY_FIELD(t_unit,getp,units,int,input.actor_id);
    PRO_FUNCGEN_GETP_BY_FIELD(t_unit,get_unit_by_name,units,string,name);
    t_unit&add_unit(string name)
    {
      last_actor_id++;
      auto&ex=qap_add_back(units);
      ex.name=name;
      ex.input.actor_id=last_actor_id;
      ex.gui.pitems.resize(5);
      //vector<string> items=split((name=="user_a")?"DEF,VIT,DEF,VIT,WIS":"SPD,NOP,NOP,NOP,NOP",",");
      vector<string> items=split((name=="user_a")?"DEF,VIT,NOP,NOP,NOP":"NOP,SPD,NOP,WIS,NOP",",");
      for(int i=0;i<5;i++){if(items[i]=="NOP"){ex.gui.pitems[i].deaded=true;continue;}ex.gui.pitems[i].deaded=false;ex.gui.pitems[i].name=items[i];}
      /*if(last_actor_id==0)
      {
        ex.gui.bitems.resize(5);
        for(int i=0;i<5;i++)ex.gui.bitems[i].deaded=true;
        ex.gui.bitems[3].name="SPD";
        ex.gui.bitems[3].deaded=false;
      }*/
      return ex;
    }
    void deselected_items(t_unit&unit)
    {
      SO_GUI();
      for(int i=0;i<pitems.size();i++)pitems[i].selected=false;
      //for(int i=0;i<bitems.size();i++)bitems[i].selected=false;
    }
    void SendBegTradeRequest(t_unit&from,const string&to_unit)
    {
      auto*p=get_unit_by_name(to_unit);
      QapAssert(p);
      SendBegTradeRequest(from,*p);
    }
    void SendEndTradeRequest(t_unit&from,const string&to_unit,bool finished)
    {
      auto*p=get_unit_by_name(to_unit);
      QapAssert(p);
      SendEndTradeRequest(from,*p,finished);
    }
    void SendBegTradeRequest(t_unit&from,t_unit&to)
    {
      auto*p=to.get_trade_requests_by_actor_id(from.input.actor_id);
      if(p){
        from.gui.status="hi from tick "+IToS(p->tick);
      }else{
        from.gui.status="trade requested";
        p=&qap_add_back(to.gui.trade_requests);
        p->actor_id=from.input.actor_id;
      }
      p->tick=tick;
    }
    vector<int> get_selected_id(const vector<t_item>&arr)
    {
      vector<int> out;
      for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(ex.selected)out.push_back(i);}
      return out;
    }
    vector<int> get_free_id(const vector<t_item>&arr)
    {
      vector<int> out;
      for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(ex.deaded)out.push_back(i);}
      return out;
    }
    void DoItemsExchangeStage2(vector<t_item>&a,vector<t_item>&b)
    {
      auto sa=get_selected_id(a);
      auto sb=get_selected_id(b);
      auto fa=get_free_id(a);
      auto fb=get_free_id(b);
      if(sb.empty())
      {
        QapAssert(fb.size()>=sa.size());
        for(int i=0;i<sa.size();i++)
        {
          auto&ea=a[sa[i]];
          auto&eb=b[fb[i]];
          std::swap(ea,eb);
          int gg=1;
        }
        int gg=1;
        return;
      }
    }
    void DoItemsExchange(t_unit&from,t_unit&to)
    {
      auto&a=from.gui.pitems;
      auto&b=to.gui.pitems;
      auto sa=get_selected_id(a);
      auto sb=get_selected_id(b);
      if(!sa.empty()||!sb.empty())
      {
        int n=std::min(sa.size(),sb.size());
        for(int i=0;i<n;i++)
        {
          auto&ea=a[sa[i]];
          auto&eb=b[sb[i]];
          std::swap(ea,eb);
          ea.selected=false;
          eb.selected=false;
          int gg=1;
        }
        int bp=1;
        sa=get_selected_id(a);
        sb=get_selected_id(b);
        int gg=1;
      }
      if(sb.empty()){DoItemsExchangeStage2(a,b);}
      if(sa.empty()){DoItemsExchangeStage2(b,a);}
    }
    //static bool&is_trade_accept(const t_unit&unit){return unit.gui.trade.accept;}
    void SendEndTradeRequest(t_unit&from,t_unit&to,bool finished)
    {
      //QapNoWay();
      from.gui.status=finished?"trade finished":"trade canceled";
      if(finished)
      {
        from.gui.trade.accept=true;
        if(!to.gui.trade.accept)return;
      }
      if(finished)DoItemsExchange(from,to);
      deselected_items(from);
      deselected_items(to);
      from.gui.trade=t_trade();
      to.gui.trade=t_trade();
    }
    void negotiated_trade(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      if(!movepass)return;
      QapAssert(srvpass);
      auto&trs=trade_requests;
      qap_clean_if_deaded(trs);
      for(int i=0;i<trs.size();i++)
      {
        auto&ex=trs[i];
        ex.update(*this);
        if(tick-ex.tick>traderequest_lifetime)ex.deaded=true;
        if(ex.deaded)continue;
        auto*p=getp(ex.actor_id);
        QapAssert(p);
        auto*tr2=p->get_trade_requests_by_actor_id(unit.input.actor_id);
        if(!tr2){status="trade request received from "+p->name;continue;}
        if(tr2->deaded)continue;
        p->gui.status="trade with "+p->name+" negotiated";
        QapAssert(!trade);
        trade=true;
        trade.actor_id=p->input.actor_id;
        QapAssert(!p->gui.trade);
        p->gui.trade=true;
        p->gui.trade.actor_id=unit.input.actor_id;
        tr2->deaded=true;
        ex.deaded=true;
        /*
        if(drawpass)
        {
          qDev.SetColor(0x80ff0000);
          qDev.DrawQuad(vec2d_zero,vec2d(10,100));
        }*/
        return;
      }
      return;
    }
    void soTradeAcceptButton(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      if(trade)return;
      if(trade_requests.empty())return;
      vector<string> buttons=split("cancel,trade",",");
      auto space=10;
      vector<t_quad> btns;btns.resize(buttons.size());
      auto x_pos=0-trade_buttons_x_offset-128;
      //auto x_offset=64;
      for(int i=0;i<2;i++){btns[i].size=qap_text::get_size(qDev,buttons[i],textsize);}
      join_quads_by_dir_ex(btns,'x',16);
      layout_by_dir(btns,'x',16);
      btns[0].pos+=vec2d(0,-consize.y/2+24);
      btns[1].pos+=vec2d(0,-consize.y/2+24);
      if(drawpass)
      {
        auto text="do you want trade with "+getp(trade_requests[0].actor_id)->name+" ?";
        t_quad q;
        q.pos=(btns[0].pos+btns[1].pos)*0.5+vec2d(0,32);
        q.size=qap_text::get_size(qDev,text,textsize);
        qap_text::draw(qDev,q.get_left_top(),text,textsize);
      }
      for(int i=0;i<2;i++){btns[i].size=qap_text::get_size(qDev,buttons[i],textsize);}
      if(drawpass)for(int i=0;i<2;i++)
      {
        QapColor col_hov=0xfffff0e0;
        QapColor col_def=0xffe8e8e8;
        bool hovered=point_in_quad(btns[i],mpos);
        qDev.color=point_in_quad(btns[i],mpos)?0xfffff0e0:0xffe8e8e8;
        DrawQuad(qDev,btns[i].add_size(space));
        DrawQuadBorder(qDev,btns[i].add_size(space));
      }
      if(drawpass)for(int i=0;i<2;i++)
      {
        qDev.color=0xff000000;
        qap_text::draw(qDev,btns[i].get_left_top(),buttons[i],textsize);
      }
      if(movepass)if(kb.OnDown(mbLeft))for(int i=0;i<2;i++)if(point_in_quad(btns[i],mpos))
      {
        if(buttons[i]=="cancel"){QapPopFront(trade_requests);}
        if(buttons[i]=="trade")
        {
          auto*p=getp(trade_requests[0].actor_id);
          SendBegTradeRequest(unit,*p);
        }
      }
    }
    void soUnit(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      if(srvpass&&movepass&&unit.input)
      {
        //if(kb.OnDown(VK_SPACE)){Starttrade(unit);}
        unit.pos+=unit.input.kb.get_dir_from_wasd_and_arrows().SetMag(3.5);
      }
      bool this_actor=unit.input.actor_id==input.actor_id;
      if(movepass||drawpass&&this_actor)
      {
        negotiated_trade(game,unit);
        soInventoryFull(game,unit);
        if(!trade)soListOfPlayers(game,unit);
        if(!trade)soMenu(game,unit);
        soTradeAcceptButton(game,unit);
        //if(!trade_requests.empty()){status="trade_requests.size() = "+IToS(1);}
      }
      if(drawpass)
      {
        qDev.color=0xff000000;
        if(this_actor)qDev.color=0xffAA0000;
        qDev.DrawCircleEx(unit.pos,r,0,16,0);
        qDev.color=0xffffffff;
        t_quad q;
        q.size=qap_text::get_size(qDev,unit.name,textsize);
        q.pos=unit.pos;
        qap_text::draw(qDev,q.get_left_top(),unit.name,textsize);
      }
      if(drawpass&&this_actor)
      {
        //draw_bags
        for(int i=0;i<bags.size();i++)
        {
          auto&ex=bags[i];
          if(ex.empty())continue;
          DrawBag(qDev,ex);
        }
        //draw text info
        QapAssert(cntpass);
        qDev.color=0xff000000;
        qDev.DrawQuad(0,0,10,10);
        for(;;)
        {
          qDev.SetColor(0xff000000);
          int dy=-textsize*1;
          vec2i p(-consize.x/2+64,consize.y/2-16);p.y+=dy;
          #define F(MSG)qap_text::draw(qDev,p.x,p.y,MSG,textsize);p.y+=dy;
          F("name = "+unit.name);
          F("pos = "+FToS(unit.pos.x)+"   "+FToS(unit.pos.y));
          F("active = "+IToS(point_in_quad(t_quad().add_size(consize),mpos)));
          F("status = "+status);
          #undef F
          break;
        }
      }
    }
    void make_trade_between(const string&nick_a,const string&nick_b)
    {
      auto&a=*get_unit_by_name(nick_a);
      auto&b=*get_unit_by_name(nick_b);
      SendBegTradeRequest(a,b);
      SendBegTradeRequest(b,a);
      //qap_add_back(a.gui.trade_requests).set_tick(tick).actor_id=b.input.actor_id;
      //qap_add_back(b.gui.trade_requests).set_tick(tick).actor_id=a.input.actor_id;
    }
    void soUpdate(TGame&game)
    {
      SO_PASS();
      QapAssert(drawpass!=movepass);
      if(srvpass&&drawpass&&!movepass)return;
      if(movepass&&game.kb.OnDown(VK_SPACE))
      {
        make_trade_between("user_a","user_b");
      }
      if(movepass&&cntpass)return;
      //client.draw or serv.move
      if(movepass)
      {
        tick++;
        QapCleanIf(bags,[](t_bag&ex){return ex.empty();});
      }
      for(int i=0;i<units.size();i++)
      {
        auto&ex=units[i];
        soUnit(game,ex);
      }
    }
    public:
      #include "inventory.inl"
    public:
      #include "menu.inl"
    struct t_inv_info{
      int n=0;
      int i=0;
      int s=0;
      int f=0;
    };
    static t_inv_info make_info(const vector<t_item>&arr)
    {
      t_inv_info res;
      res.n=arr.size();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.deaded)continue;
        res.i++;
        if(ex.selected)res.s++;
      }
      res.f=res.n-res.i;
      return res;
    }
    void soInventoryFull(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      soInv(game,unit);
      soTradeFull(game,unit);
      soItemDragAndDrop(game,unit);
    }
    void soInv(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      soInventory(game,unit,pitems,3,drawpass,"user");
      if(!trade&&trade_requests.empty())
      {
        auto&user=unit;
        auto id=get_item_id_under_point(user,user.pos,r*1.5);
        if(id>=0)
        {
          auto&arr=bags[id].arr;
          soInventory(game,unit,arr,1,drawpass,"bag");
        }
      }
    }
    void soTradeFull(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      auto progress=trade.get_trade_progress(*this,unit,tick,trade_duration);
      bool trade_disabled=false;
      bool trade_ready=progress==1.0;
      bool trade_accept=trade.accept;
      if(trade)
      {
        auto*pb=getp(trade.actor_id);
        QapAssert(pb);
        auto&bitems=pb->gui.pitems;
        auto p=make_info(pitems);
        auto b=make_info(bitems);
        if(p.f+p.s<b.s)trade_disabled=true;
        if(b.f+b.s<p.s)trade_disabled=true;
        if(trade_disabled)QapAssert(!trade_accept);
        bool trade_accept_from_other_side=getp(trade.actor_id)->gui.trade.accept;
        if(trade_accept_from_other_side)if(drawpass)
        {
          string msg="trade accepted";
          t_quad q;
          q.size=qap_text::get_size(qDev,msg,textsize);
          q.pos=vec2d(0,-consize.y/2+64+32);
          qDev.color=0xff000000;
          qap_text::draw(qDev,q.get_left_top()+vec2d(1,-1),msg,textsize);
          qDev.color=0xff80ee00;
          qap_text::draw(qDev,q.get_left_top(),msg,textsize);
        }
      //}
      //if(trade)
      //{
        soInventory(game,unit,bitems,1,drawpass,"bot");
        qDev.color=0xff000000;
        vector<string> buttons=split(trade_accept?"cancel,accept":"cancel,trade",",");
        auto space=10;
        vector<t_quad> btns;btns.resize(buttons.size());
        btns[0].pos=vec2d(-trade_buttons_x_offset,-consize.y/2+64);
        btns[1].pos=vec2d(+trade_buttons_x_offset,-consize.y/2+64);
        for(int i=0;i<2;i++){btns[i].size=qap_text::get_size(qDev,buttons[i],textsize);}
        if(drawpass)for(int i=0;i<2;i++)
        {
          QapColor col_acc=0xffffe088;
          QapColor col_hov=0xfffff0e0;
          QapColor col_def=0xffe8e8e8;
          bool hovered=point_in_quad(btns[i],mpos);
          qDev.color=hovered?col_hov:col_def;
          bool acc_or_tra=(buttons[i]=="accept")||(buttons[i]=="trade");
          if(acc_or_tra)
          {
            QapColor col_dis=0xffc0c0c0;
            if(!trade_ready)
            {
              if(trade_disabled)progress=0;
              auto hsx=btns[i].add_size(space).size.x*.5;
              auto pa=btns[i].add_size(space);
              auto pb=btns[i].add_size(space);
              pa.size.x*=progress;
              pa.pos.x+=-hsx+pa.size.x*0.5;
              pb.size.x*=1-progress;
              pb.pos.x+=+hsx-pb.size.x*0.5;
              qDev.color=col_def;
              DrawQuad(qDev,pa);
              qDev.color=col_dis;
              DrawQuad(qDev,pb);
            }
            if(trade_ready)
            {
              qDev.color=trade_disabled?col_dis:qDev.color;
              if(trade_accept)qDev.color=col_acc;
              DrawQuad(qDev,btns[i].add_size(space));
            }
          }
          qDev.color=point_in_quad(btns[i],mpos)?0xfffff0e0:0xffe8e8e8;
          if(acc_or_tra){if(trade_disabled)qDev.color=0xffc0c0c0;}else{DrawQuad(qDev,btns[i].add_size(space));}
          DrawQuadBorder(qDev,btns[i].add_size(space));
        }
        if(drawpass)for(int i=0;i<2;i++)
        {
          bool acc_or_tra=(buttons[i]=="accept")||(buttons[i]=="trade");
          qDev.color=trade_disabled&&acc_or_tra?0xff808080:0xff000000;
          qap_text::draw(qDev,btns[i].get_left_top(),buttons[i],textsize);
        }
        if(movepass)if(kb.OnDown(mbLeft))for(int i=0;i<2;i++)if(point_in_quad(btns[i],mpos))
        {
          if(buttons[i]=="cancel"){SendEndTradeRequest(unit,*getp(trade.actor_id),false);}
          if(buttons[i]=="trade")if(!trade_disabled&&trade_ready){SendEndTradeRequest(unit,*getp(trade.actor_id),true);}
        }
      }
    }
    void soItemDragAndDrop(TGame&game,t_unit&unit)
    {
      SO_HEAD();
      SO_GUI();
      if(drawpass)if(dd_from){DrawItem(qDev,mpos,get_item(*this,unit,dd_from)->name);}
      if(movepass)
      {
        if(dd_from&&!dd_to&&kb.OnUp(mbLeft))
        {
          auto id=get_item_id_under_point(unit,unit.pos,r*1.5);
          t_bag*pb=id>=0?&bags[id]:&qap_add_back(bags);
          auto*pi=get_item(*this,unit,dd_from);
          if(pi)
          {
            pb->add(pi->name);
            if(id)pb->pos=unit.pos+vec2d(16,-16);
            pi->deaded=true;
            dd_from=t_dd_point();
            dd_to=t_dd_point();
          }
        }
        if(dd_from&&dd_to)
        {
          auto*pf=get_item(*this,unit,dd_from);
          auto*pt=get_item(*this,unit,dd_to);
          if(pf&&pt)
          {
            std::swap(*pf,*pt);
          }
          dd_from=t_dd_point();
          dd_to=t_dd_point();
        }
      }
    }
  };
public:
};

class TMutiplayerGame:public TGame{
public:
  #include "t_mutiplayer.inl"
  TMutiplayerGame(){
    DoReset();
    qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_a").set_pos(+100,0).input.actor_id;
    qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_b").set_pos(-100,0).input.actor_id;
    server.world.add_unit("bot_a").set_pos(0,200);
    qap_add_back(clients).world.input.actor_id=server.world.add_unit("user_c").set_pos(0,100).input.actor_id;
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TMutiplayerGame builder;
  builder.DoNice();
}
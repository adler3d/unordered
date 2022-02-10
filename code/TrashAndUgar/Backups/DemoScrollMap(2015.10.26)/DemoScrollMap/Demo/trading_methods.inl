
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
//part2
    void make_trade_between(const string&nick_a,const string&nick_b)
    {
      auto&a=*get_unit_by_name(nick_a);
      auto&b=*get_unit_by_name(nick_b);
      SendBegTradeRequest(a,b);
      SendBegTradeRequest(b,a);
      //qap_add_back(a.gui.trade_requests).set_tick(tick).actor_id=b.input.actor_id;
      //qap_add_back(b.gui.trade_requests).set_tick(tick).actor_id=a.input.actor_id;
    }
    public:
      #include "inventory.inl"
    public:
      #include "menu.inl"
    struct t_inv_info{
      #define DEF_PRO_VARIABLE(ADD)\
      ADD(int,n,0)\
      ADD(int,i,0)\
      ADD(int,s,0)\
      ADD(int,f,0)\
      //===
      #include "defprovar.inl"
      //===
      t_inv_info(){DoReset();}
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
        auto id=get_item_id_under_point(user.pos,r*1.5);
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
          auto id=get_item_id_under_point(unit.pos,r*1.5);
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
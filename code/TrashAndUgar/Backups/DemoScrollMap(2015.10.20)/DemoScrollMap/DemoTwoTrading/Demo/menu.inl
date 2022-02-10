struct t_id_with_dist{
  int id;
  real dist;
};
DEF_PRO_SORT_BY_FIELD(sort_by_dist,t_id_with_dist,dist);
void soListOfPlayers(TGame&game,t_unit&unit,int pix_from_right_border=95)
{
  SO_HEAD();
  auto&menu=unit.gui.menu;
  auto userpos=unit.pos;
  vector<t_id_with_dist> arr;
  for(int i=0;i<units.size();i++)
  {
    if(&units[i]==&unit)continue;
    auto&ex=units[i];
    t_id_with_dist rec={i,(userpos-ex.pos).Mag()};
    qap_add_back(arr)=rec;
  }
  sort_by_dist(arr);
  for(;;)
  {
    qDev.color=0xff000000;
    int textsize=16; int dy=textsize*1;
    auto pfrb=pix_from_right_border;
    vec2i p(+consize.x/2-pfrb,-consize.y/2+32);p.y+=dy;vec2i cur=p;
    #define F(MSG)if(drawpass){qDev.color=0xff000000;qap_text::draw(qDev,p.x,p.y,MSG,textsize);}p.y+=dy;cur=p;
    bool selected=false;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      t_quad q;
      q.pos=cur+vec2d(pfrb/2,-dy/2);
      q.size=vec2d(pfrb,dy);
      if(!selected&&!menu.enabled&&point_in_quad(q,mpos))
      {
        selected=true;
        if(drawpass){qDev.color=0x20eeee00;qDev.DrawQuad(q.pos,q.size);}
        if(!drawpass)if(kb.OnDown(mbLeft)){
          menu.enabled=true;
          menu.wait_next_tick=true;
          menu.fill(units[ex.id].name);
          menu.pos=mpos;
          menu.target=units[ex.id].name;
          unit.gui.status="open menu for "+units[ex.id].name+" at x="+IToS(mpos.x)+" and y="+IToS(mpos.y);
        }
      }
      F(units[ex.id].name);
    }
    #undef F
    break;
  }
}
/*
void update_menupos(vec2d&menupos,const vec2d&size)
{
  auto wcs=win.GetClientSize();
  menupos=t_quad::clamp(menupos,wcs-size);
  int gg=1;
}*/
void soMenu(TGame&game,t_unit&unit)
{
  SO_HEAD();
  auto&menu=unit.gui.menu;
  if(!drawpass)if(menu.wait_next_tick){menu.wait_next_tick=false;return;}
  if(!menu.enabled)return;
  auto&arr=menu.lines;
  vector<t_quad> quads;quads.resize(arr.size());
  for(int i=0;i<arr.size();i++)quads[i].size=qap_text::get_size(qDev,arr[i],textsize);
  auto space=10;
  auto raw_size=join_quads_by_y_ex(quads,space);
  auto pad=vec2d(1,1)*space*2;
  vector<t_quad> top_quads;top_quads.resize(2);
  auto&caption=top_quads[0];
  auto&list=top_quads[1];
  caption.size=qap_text::get_size(qDev,menu.caption,textsize)+pad*0.5;
  list.size=raw_size+pad;
  layout(top_quads,0);
  t_quad root;
  root.size=join_quads_by_y_ex(top_quads,0)+pad;
  root.pos=menu.pos;
  root.pos=t_quad::clamp(menu.pos,consize-root.size);
  caption.pos+=root.pos;
  caption.pos.x=root.pos.x;
  //caption
  {
    auto&q=caption;
    if(drawpass){qDev.color=0xffd8d8d8;DrawQuad(qDev,q);}
    q.size-=pad*0.5;
    if(drawpass){qDev.color=point_in_quad(q,mpos)?0xffd0d0d0:0xfff8f8f8;DrawQuad(qDev,q);}
    if(!drawpass)if(point_in_quad(q,mpos))if(kb.OnDown(mbLeft)){menu.enabled=false;}
    if(drawpass){qDev.color=0xff000000;qap_text::draw(qDev,q.get_left_top(),menu.caption,textsize);}
  }
  layout(quads,space);
  list.pos+=root.pos;
  list.pos.x=root.pos.x;
  if(drawpass){qDev.color=0xffe0e0e0;DrawQuad(qDev,list);}
  for(int i=0;i<quads.size();i++)
  {
    t_quad subquad=quads[i].add_pos(list.pos).add_size(space*0.75);
    subquad.pos.x=list.pos.x;
    subquad.size.x=list.size.x-2*space+space*0.75;
    if(drawpass)
    {
      qDev.color=point_in_quad(subquad,mpos)?0xfffff0e0:0xfff8f8f8;
      DrawQuad(qDev,subquad);
      qDev.color=0xff000000;
      qap_text::draw(qDev,quads[i].add_pos(list.pos).get_left_top(),arr[i],textsize);
    }
    if(!drawpass)if(point_in_quad(subquad,mpos))if(kb.OnDown(mbLeft))
    {
      unit.gui.status="do "+arr[i]+" with "+menu.caption;
      if(arr[i]=="trade")SendBegTradeRequest(unit,menu.caption);
      menu.enabled=false;
    }
  }
  if(!drawpass)if(kb.OnDown(mbLeft))menu.enabled=false;
}
static void layout(vector<t_quad>&arr,/*const vec2d&pos,*/real space){
  t_quad q;
  //q.pos=pos;
  q.size=join_quads_by_y_ex(arr,space);
  vec2d dir=vec2i(1,-1);
  auto p=q.get_vertex_by_dir(-dir);
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    ex.set_pos_by_vertex_and_dir(p,dir);
    p.y-=space+ex.size.y;
  }
}/*
void DrawQuadWithBorder(t_quad q)
{
  qDev.DrawQuad(q.pos,q.size);
  DrawQuadBorder(q);
}
void DrawQuadBorder(t_quad q)
{
  qDev.color=QapColor::HalfMix(0xff000000,qDev.color);
  qDev.DrawRectAsQuad(q.pos,q.size,2);
}
void DrawQuad(t_quad q)
{
  qDev.DrawQuad(q.pos,q.size);
}*/
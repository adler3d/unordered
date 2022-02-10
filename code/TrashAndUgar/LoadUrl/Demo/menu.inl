struct t_id_with_dist{
  int id;
  real dist;
};
DEF_PRO_SORT_BY_FIELD(sort_by_dist,t_id_with_dist,dist);
int max_by_dist(vector<t_id_with_dist>&arr)
{
  if(arr.empty())return -1;
  int top=0;
  for(int i=1;i<arr.size();i++){
    auto&ex=arr[i];
    if(ex.dist<arr[top].dist)continue;
    top=i;
  }
  return top;
}
void move_max_by_dist_to_back(vector<t_id_with_dist>&arr)
{
  if(arr.empty())return;
  auto id=max_by_dist(arr);
  if(1+id==arr.size())return;
  std::swap(arr.back(),arr[id]);
}

struct t_retval{
  t_menu&menu;
  int id;
  bool down;
  bool flag;
  t_retval is_select()const{auto tmp=*this;tmp.flag=id>=0;return tmp;}
  t_retval is_down()const{auto tmp=*this;tmp.flag=down;return tmp;}
  operator bool()const{return flag;}
};

t_retval soMenu(TGame&game,t_menu&menu,int textsize=32)
{
  //SO_HEAD();
  t_retval result={menu,-1,false,false};
  //auto&menu=game.menu;
  if(!drawpass)if(menu.wait_next_tick){menu.wait_next_tick=false;return result;}
  if(!menu.enabled)return result;
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
    bool piq=point_in_quad(subquad,mpos);
    if(!drawpass&&piq)result.id=i;
    if(drawpass)
    {
      qDev.color=piq?0xfffff0e0:0xfff8f8f8;
      DrawQuad(qDev,subquad);
      qDev.color=0xff000000;
      qap_text::draw(qDev,quads[i].add_pos(list.pos).get_left_top(),arr[i],textsize);
    }
    if(!drawpass)if(piq)if(kb.OnDown(mbLeft))
    {
      //unit.gui.status="do "+arr[i]+" with "+menu.caption;
      //if(arr[i]=="trade")SendBegTradeRequest(unit,menu.caption);
      result.down=true;
      menu.enabled=false;
    }
  }
  if(!drawpass)if(kb.OnDown(mbLeft))menu.enabled=false;
  return result;
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
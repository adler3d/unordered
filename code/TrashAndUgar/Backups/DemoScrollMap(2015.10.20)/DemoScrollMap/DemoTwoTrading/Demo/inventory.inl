string get_item_info(string name){return "+1 "+name;}
int get_item_id_under_point(t_unit&unit,vec2d pos,real r)
{
  auto&arr=bags;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if((ex.pos-pos).Mag()>r)continue;
    return i;
  }
  return -1;
}
t_item*get_item(t_world&world,t_unit&unit,t_dd_point&p)
{
  auto&pitems=unit.gui.pitems;
  if(p.comment=="bot")
  {
    auto*pb=world.getp(unit.gui.trade.actor_id);
    QapAssert(pb);
    auto&bitems=pb->gui.pitems;
    auto b=make_info(bitems);
    auto&arr=unit.gui.pitems;
    return &arr[p.id];
  }
  //auto&bitems=unit.gui.bitems;
  auto id=get_item_id_under_point(unit,unit.pos,r*3);
  if(id<0)if(p.comment=="bag")return nullptr;
  auto&arr=p.comment=="user"?pitems:(/*p.comment=="bot"?bitems:*/bags[id].arr);
  return &arr[p.id];
}
void DrawBag(QapDev&qDev,t_bag&bag)
{
  real r=8;
  qDev.color=0xff804020;
  qDev.DrawCircleEx(bag.pos,r*1.5,0,32,0);
  qDev.color=0xffffffff;
  qap_text::draw(qDev,bag.pos.x-10,bag.pos.y+8," ~",16);
}
void DrawItem(QapDev&qDev,vec2d pos,string name)
{
  real r=8;
  qDev.color=0xff000000;
  qDev.DrawCircleEx(pos,r*2,0,32,0);
  qDev.color=0xffffffff;
  qap_text::draw(qDev,pos.x-10,pos.y+8,name,16);
}
void soInventory(TGame&game,t_unit&unit,vector<t_item>&arr,int y=3,bool need_draw=true,string comment="")
{
  SO_HEAD();
  SO_GUI();
  //for(int pass_id=1;pass_id<=2;pass_id++)
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    auto cs=48;
    auto pos=vec2i((i-2)*cs*1.0,-consize.y*0.5+cs*y);
    t_quad q;
    q.set(pos,vec2d(1,1)*cs);
    if(need_draw){qDev.color=ex.selected?0xffffd0c0:0xffe8e8e8;DrawQuadWithBorder(qDev,q);}
    if(!ex.deaded)
    {
      if(need_draw)if(dd_from.comment==comment&&i==dd_from.id){}else{DrawItem(qDev,pos,ex.name);}
      if(point_in_quad(q,mpos))
      {
        if(need_draw)
        {
          qDev.color=0x80000000;
          qDev.DrawQuad(pos+vec2d(0,48),80,32);
          qDev.color=0xffffffff;
          qap_text::draw(qDev,pos.x-32,pos.y+64,get_item_info(ex.name),16);
        }
        if(!need_draw)for(;;)
        {
          if(!trade)
          {
            if(kb.OnDown(mbLeft)&&kb.Down[VK_SHIFT])
            {
              status=arr[i].name;
              break;
            }
            if(kb.OnDown(mbLeft)&&!dd_from)
            {
              dd_from.comment=comment;
              dd_from.id=i;
              break;
            }
            if(kb.OnUp(mbLeft))if(dd_from){
              dd_to.comment=comment;
              dd_to.id=i;
              break;
            }
          }
          if(trade)if(comment=="user")
          {
            if(kb.OnDown(mbLeft))
            {
              status="item selected";
              ex.selected=!ex.selected;
              trade.set_tick(*this,unit,tick);
              break;
            }
          }
          break;
        }
      }
    }
    if(!need_draw)if(ex.deaded)if(dd_from)if(kb.OnUp(mbLeft))if(point_in_quad(q,mpos))
    {
      dd_to.comment=comment;
      dd_to.id=i;
    }
  }
}
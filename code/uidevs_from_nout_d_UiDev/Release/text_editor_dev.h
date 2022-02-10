
t_select_info{
  int start;
  int stop;
}

t_text_editor{
  int pos;
  int tick;
  int max_tick;
  t_select_info info;
  void render(){
    if(tick*2/max_tick>1)qDev.DrawQuad(at pos);
    
  }
  void update()
  {
    kb.OnDown(VK_LEFT) then try_inc_pos();
    kb.OnDown(VK_RIGHT) then try_dec_pos();
    if(kb.OnDown(mbLeft)){mtpos=pos;}
    if(kb.OnUp(mbLeft)){info.start=mtpos;info.stop=pos;}
  }
}


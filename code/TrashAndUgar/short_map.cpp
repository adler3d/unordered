struct t_world{
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<t_unit>,units,$)\
  ADD(vector<t_monster>,monsters,$)\
  ADD(vector<t_bullet>,bullets,$)\
  ADD(vector<t_bullet>,particles,$)\
  ADD(int,r,24)\
  ADD(int,textsize,16)\
  ADD(int,last_actor_id,-1)\
  ADD(int,tick,0)\
  ADD(t_input,input,$)\
  ADD(t_map,map,$)\
  //===
  #include "defprovar.inl"
  //===
  t_world(){DoReset();}
  void soUnit(TGame&game,t_unit&unit)
  {
    if(srvpass&&movepass)
    {
      ���� �������� � ���������.
      return;
    }
    if(!drawpass)return;
    bool this_actor=unit.input.actor_id==input.actor_id;
    QapAssert(cntpass);QapAssert(this_actor);
    static real draw_time=0;
    {
      ����������� ������� ���������.
      draw_map();
      draw_bullets();
      draw_particles();
      draw_units()
      draw_monsters();
    }
  }
  //:soUpdate
  void soUpdate(TGame&game)
  {
    if(srvpass&&drawpass&&!movepass)return;
    if(movepass&&cntpass)return;
    if(cntpass)if(drawpass)������ �� �� �����.
    if(srvpass) 
    {
      tick++;
      ��� ������������ ������ ������(��������+���������).
      ��� ������������ ������ ��������(�����������+��������).
      ������� particles.
      ��������� ����������.(�����,�������,�����,����,��������)
      ������ ���������������.
      ������� ���������.
    }
  }
};
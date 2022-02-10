

t_galcon_game{
  t_node{
    int owner_id;
    int ships;
  }
  t_ship{
    int owner_id;
    int n;
  }
  vector<t_node> nodes;
  int tick;
}

можно всё это сделать на поверхности клеточного автомата.
тоесть все корабли будут двигаться пошагово.

тоесть вообще всё будет двигаться по сетке.

это удобно.
короче если всё сделать на сетке то тогда будет намного проще оптимизировать игру.

for(int i=0;i<arr.size();i++){
  auto&ex=arr[i];
  add_nigtbours_to_next_step(ex);
}

t_cell{
  bool is_full;
  bool passed;
  int prev_id;
  int dist;
}



t_node{
  int owner_id;
  int n;
  int rank;
  bool need_shot;
  int mode; //if(mode<10){n_for_send=!mode?n:int(n*mode)/10;}else{n_for_send=0;}
  int target_id;
}
t_owner{
  int n;
}
vector<t_node> nodes;
vector<t_owner> owners;
#define forarr(ARR,CODE)auto&arr=ARR;for(int i=0;i<arr.size();i++){auto&ex=arr[i];{CODE;}}
void update_owners(){
  forarr(owners,ex.n=0;);
  forarr(nodes,if(ex.owner_id>=0)owners[ex.owner_id].n++;);
}
void update_node(t_node&ex)
{
  if(!ex.need_shot)return;
  if(ex.target_id<0)return;
  if(ex.target_id>=nodes.size())return;
  if(&ex==&nodes[ex.target_id])return;
  ex.need_shot=false;
  int n_for_send=0;
  if(ex.mode<10){n_for_send=!ex.mode?ex.n:int(ex.n*ex.mode)/10;}else{n_for_send=0;}
  QapAssert(n_for_send<=ex.n);
  auto&target=nodes[ex.target_id];
  ex.n-=n_for_send;
  if(target.owner_id==ex.owner_id){
    target.n+=n_for_send;
  }else{
    target.n-=n_for_send;
  }
  if(target.n<0){
    target.n=abs(target.n);
    target.owner_id=ex.owner_id;
  }
}
void update_nodes(){
  forarr(nodes,update_node(ex););
  if(world.tick%64==0)forarr(nodes,ex.n+=ex.rank;);
}
bool is_end(){
  update_owners();
  int c=0;
  forarr(owners,if(ex.n>0)c++;);
  return c>1;
}
void build_map()
{
  for(int i=0;i<10+owners.size();i++){
    auto&back=qap_add_back(nodes);
    back.owner_id=-1;
    if(i<owners.size())back.owner_id=i;
    back.n=rand()%128;
    back.rank=rand()%4;
  }
}

что может сделать каждый пользователь?
сказать номер узла из которого отправлять. сказать сколько отправлять и сказать куда отправлять.
сколько таких комманд можно за одну итерацию сделать? сколько угодно?

можно в каждый нод встроить механизм, который выпустит заряд в какой-то другой нод.

вообще я договарился что заряд выпускаеться мгновенно.


#undef forarr
































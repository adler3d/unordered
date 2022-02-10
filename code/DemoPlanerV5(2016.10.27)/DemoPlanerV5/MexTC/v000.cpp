
//выкинуть статику
drop("r;lines")





NBF.id2obj


t_world world;
...
t_world cur;
cur=world;
cur.sim_step();
select("lines;actor.points").diff(cur,world)
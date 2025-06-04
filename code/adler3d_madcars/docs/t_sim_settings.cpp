


t_plan
add field like: vector<int> storage; or; vector<vector<t_rec>> others;
t_move

int dir=0;
int version=0;
union{
  int use_sim_and_select_bests_of_others_atm; but looklike other must be without version just simple trajectory.
  int keep_ang=0;
}


also look like now we can`t run sim from t_plan; but if we provide all info... still can`t if already in sim
  but if now we is not inside sim then we can start a lot of new simulations
 
 
on_tick
  //need replace this:
    if(keep_cur_plan){...;return;}
  //to this:
    t_sim_settings simset;// simlimit,plans,
    for(;;)if(keep_cur_plan){
      auto&cur_plan=this_match_cur_plan; //or full_game_cur_plan
      if(!cur_plan.get_rec(frame_id).pr.move.keep_cur_plan()){
        simset=cur_plan.get_rec(frame_id).pr.move.get_simset();
        break; // mean go
      }
      ...
      return;
    }else break;
bool special_cd_func(t_food&food)
{
  vector<int> out;
  for(int i=0;i<arr.size();i++)if(food.pos.dist_to_point_less_that_r(arr[i].pos,r))
  {
    qap_add_back(out)=i;
  }
  if(out.size()>1)
  {
    for(int i=0;i<out.size();i++)
    {
      arr[out[i]].n--;
    }
  }
  return out.size();
};
bool fast_special_cd_func(t_food&food)
{
  int id=-1;
  for(int i=0;i<arr.size();i++)if(food.pos.dist_to_point_less_that_r(arr[i].pos,r))
  {
    if(id>=0){
      QapDebugMsg("food conflict detected");
      return special_cd_func(food);
    }
    id=i;
    //return true;// получаетсья UB. тот кто первый в списке тот и соберёт еду в случии конфликта.
  }
  if(id<0)return false;
  arr[id].n++;
  return true;
};
void do_cd()
{
  QapCleanIf(foods,[&](t_food&food){return fast_special_cd_func(food);});
}
template<t_elem>
struct t_id_poll{
  vector<t_elem> arr;
  vector<int> free;
  int add(){if(!free.empty()){auto id=free.back();free.pop_back();return id;}auto id=arr.size();arr.emplace_back();return id;}
  t_elem&add_and_ret_elem(){QapAssert(qap_find_val(free,id).empty());return arr[add()];}
  void del(int id){QapAssert(id>=0&&id<arr.size());free.push_back(id);}
};
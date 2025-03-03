t_raw=>i_item{
  string body;
  {
    go_any(body,gen_dips("09azAZ")+"+-*/=~%@$&|^,.!?:;<>{}()[]");
  }
}

t_str=>i_item{
  string body;
  {
    go_str<t_str_item>(body);
  }
}

t_cpp_item=>i_item{
  string body;
  {
    go_str<t_cpp_comment>(body);
  }
}

t_c_item=>i_item{
  string body;
  {
    go_str<t_c_comment>(body);
  }
}

t_item=>i_code{
  TAutoPtr<i_item> body;
  {
    go_auto(body);
  }
}

t_hack=>i_code{
  {
    go_const("\\\n");
  }
}

t_cpp_pre_text{
  vector<TAutoPtr<i_code>> arr;
  {
    go_auto(arr);
  }
}

// next step

t_item_visitor=>i_item_visitor{
  [::]public:
  t_dev&dev;
  t_code_visitor(t_dev&dev):dev(dev){}
  void Do(t_raw*p){
    dev.add(p->body);
  }
  void Do(t_c_item*p){
    dev.add(p->body);
  }
  void Do(t_cpp_item*p){
    dev.add(p->body);
  }
  void Do(t_str_item*p){
    dev.add(p->body);
  }
}

t_code_visitor=>i_code_visitor{
  [::]public:
  t_dev&dev;
  t_code_visitor(t_dev&dev):dev(dev){}
  void Do(t_hack*p){
    //do nothing.
  }
  void Do(t_item*p){
    t_item_visitor V(dev);
    p->Use(V);
  }
}

void foo(){
  vector<TAutoPtr<i_code>> arr;
  load_obj(Env,arr,data);
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    {
      auto*p=t_hack::UberCast(ex.get());
      if(p){
        continue;
      }
    }
    {
      auto*p=t_item::UberCast(ex.get());
      if(p){
        continue;
      }
    }
  }
}
//==========
t_define{
  t_param{
    t_sep sep0;
    t_name body;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      M+=go_auto(body);
      O+=go_auto(sep1);
    }
  }
  t_params=>i_params{
    vector<t_param> arr;
    {
      M+=go_const("(");
      O+=go_arr(arr,",");
      M+=go_const(")");
    }
  }
  t_body{
    t_sep=>i_elem{string body;{go_str<t_sep>(sep);}}
    t_keyword=>i_elem{string body;{go_str<t_name::t_impl>(body);}
    t_tostr=>i_elem{
      string name;
      {
        go_const("#");
        go_str<t_name::t_impl>(name);
      }
    }
    t_cat=>i_elem{
      {
        go_const("##");
      }
    }
    vector<TAutoPtr<i_elem>> arr;
  }
  t_name name;
  TAutoPtr<t_params> params;
  string body;
  {
    M+=go_const("#");
    M+=go_const("define ");
    M+=go_auto(name);
    M+=go_auto(params);
    O+=go_end(body,"\n");
  }
  [::]public:
  void main(){
    body.split("##").join(""); ?
    
  }
}
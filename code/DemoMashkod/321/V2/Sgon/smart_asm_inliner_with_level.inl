/*#error
... not used ...
work in progress
*/
class t_smart_asm_level_inliner:public t_smart_asm{
public:
  struct t_var{
    string name;
    string type;
    vector<int> path;
    string prefix;
    void set_prefix(const vector<int>&arr){path=arr;gen_prefix();}
    void gen_prefix()
    {
      prefix="v"+path_to_raw_prefix(path)+"__";
    }
    static string path_to_raw_prefix(const vector<int>&path){
      vector<string> out;
      auto&arr=path;
      for(int i=0;i<arr.size();i++){
        out.push_back(IToS(arr[i]));
      }
      return join(out,"_");
    }
  };
  class t_stackframe{
  public:
    vector<t_var> vars;
  public:
    int find_var(const string&name){for(int i=0;i<vars.size();i++){auto&ex=vars[i];if(ex.name==name)return i;}return -1;}
  };
public:
  struct t_label_info{
    string type;
    string name;
    static t_label_info make(const string&type,const string&name){t_label_info tmp;tmp.type=type;tmp.name=name;return tmp;}
    bool operator==(const t_label_info&ref)const{return (ref.type==type)&&(ref.name==name);}
  };
public:
  bool is_systype(const string&type)
  {
    const static vector<string> arr=split("int,char,bool",",");
    for(int i=0;i<arr.size();i++)if(arr[i]==type)return true;
    return false;
  }
  bool is_array(const string&type){
    string v="array{";
    return v==type.substr(0,v.size());
  }
  void reg_type(const string&type)
  {
    auto&arr=all_types;
    for(int i=0;i<arr.size();i++)if(arr[i]==type)return;
    all_types.push_back(type);
    add_user_type(type);
  }
  void add_user_type_from_array(const string&type)
  {
    t_type obj;
    bool ok=load_obj(Env,obj,type);
    if(!ok){
      QapDebugMsg("WTF?\n"+type);
      return;
    }
    QapAssert(obj.params);
    string&subtype=obj.params->type;
    reg_type(subtype);
  }
  void add_user_type(const string&type)
  {
    if(is_systype(type))return;
    if(is_array(type))
    {
      add_user_type_from_array(type);
      return;
    }
    user_types.push_back(type);
    auto&ref=unsafe_find_struct(type);
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      reg_type(ex.type);
    }
    int gg=1;
  }
public:
  int add_var(const string&type,const string&name)
  {
    reg_type(type);
    int id=head.vars.size();
    t_var tmp;tmp.name=name;
    tmp.type=type;
    head.vars.push_back(std::move(tmp));
    head.vars[id].set_prefix(stat_path);
    return id;
  }
public:
  void push_frame(){
    frames.push_back(std::move(head));
    head=t_stackframe();
  }
  void pop_frame(){
    QapAssert(!frames.empty());
    head=std::move(frames.back());
    frames.pop_back();
  }
public:
  t_struct_node*find_struct(const string&name){
    auto&arr=scope.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=ex.get();
      auto*p=t_struct_node::UberCast(ptr);
      if(!p)continue;
      if(p->name!=name)continue;
      return p;
    }
    return nullptr;
  }
  t_struct_node&unsafe_find_struct(const string&name){
    auto*p=find_struct(name);
    if(p)return *p;
    QapDebugMsg("type not found:\n"+name);
    return *(t_struct_node*)nullptr;
  }
public:
  template<class TYPE>
  string toStr_impl(TYPE&ref){
    string result;
    bool ok=save_obj(Env,ref,result);
    QapAssert(ok);
    return result;
  }
  template<class TYPE>
  string toStr(TAutoPtr<TYPE>&ref){
    if(!ref)return "";
    return toStr_impl(ref);
  }
  template<class TYPE>
  string toStr(TYPE&ref){
    return toStr_impl(ref);
  }
  void add(const string&code)
  {
    if(code=="}")
    {
      pop_frame();
    }
    int fc=frames.size();
    if(code=="{")
    {
      push_frame();
    }
    string ident;
    ident.resize(fc*2,' ');
    out+=ident+code+"\n";
  }
  template<class TYPE>
  void toDev(TYPE*p){
    add(toStr(*p));
  }
  template<class TYPE>
  void clone(TYPE&dest,TYPE&source){
    unsafe_easy_clone(Env,dest,source);
  }
public:
  void with_prefix_mod(string&var_name){
    var_name=with_prefix(var_name);
  }
  void with_prefix_mod(t_var_stat&var){
    with_prefix_mod(var.name.value);
  }
  void with_prefix_mod(TAutoPtr<t_reg_expr::i_ext>&ref){
    if(!t_reg_expr::t_id::UberCast(ref.get()))return;
    auto&idexpr=t_reg_expr::t_id::UberCast(ref.get())->idexpr;
    auto*p=t_reg_expr::t_id::t_reg::UberCast(idexpr.get());
    if(!p)return;
    auto&value=p->value;
    with_prefix_mod(value);
  }
  void with_prefix_mod(t_reg_expr&expr){
    auto&name=expr.name;
    name=with_prefix(name);
    if(!expr.ext)return;
    auto&ext=expr.ext.get()->body;
    with_prefix_mod(ext);
  }
  void with_prefix_mod(TAutoPtr<i_expr>&expr){
    if(!t_reg_expr::UberCast(expr.get()))return;
    auto&ref=*t_reg_expr::UberCast(expr.get());
    with_prefix_mod(ref);
  }
  string toStr_with_prefix(TAutoPtr<i_expr>&ref){
    TAutoPtr<i_expr> expr;
    clone(expr,ref);
    with_prefix_mod(expr);
    return toStr(expr);
  }
  string toStr_with_prefix(t_reg_expr&ref){
    t_reg_expr expr;
    clone(expr,ref);
    with_prefix_mod(expr);
    return toStr(expr);
  }
public:
  bool isCond()const{
    QapAssert(!labels.empty());
    auto&back=labels.back();
    bool flag=back.type=="cond";
    return flag;
  }
  bool isMain()const{
    QapAssert(!labels.empty());
    int counter=0;
    for(int i=0;i<labels.size();i++){
      auto&ex=labels[i];
      if(ex.type!="func")continue;
      counter++;
    }
    QapAssert(counter>0);
    return counter==1;
  }
  string gen_prefix(const string&var_name){
    auto&r=unsafe_find_reg(var_name);
    return r.prefix;
  }
  string with_prefix(const string&var_name){
    return gen_prefix(var_name)+var_name;
  }
public:
  class t_stat_visitor:public t_smart_asm::i_stat_visitor{
  public:
    typedef t_smart_asm_level_inliner t_dev;
    t_dev&dev;
    t_stat_visitor(t_dev&dev):dev(dev){}
  public:
    template<class TYPE>string toStr(TYPE&ref){return dev.toStr(ref);}
    template<class TYPE>void toDev(TYPE*p){dev.toDev(p);}
    template<class TYPE>void clone(TYPE&dest,TYPE&source){dev.clone(dest,source);}
    void add(const string&code){dev.add(code);}
    void add_label(const string&block,TAutoPtr<t_label>&label){
      string ext="";
      if(label){
        ext=":"+label.get()->name;
      }
      add(block+ext);
    }
  public:
    void Do(t_nop_stat*p){toDev(p);}
    void Do(t_ret_stat*p){
      auto t=dev.DoDeclType(p->expr);
      dev.ret(t);
      if(dev.isMain()||dev.isCond()){
        add("ret "+toStr_with_prefix(p->expr));
        return;
      }
      QapAssert(!dev.retvars.empty())
      add("call \"mov\" "+dev.retvars.back()+" "+toStr_with_prefix(p->expr)+"{break:func_body}");
    }
  public:
    struct t_calc_params_tool
    {
      typedef t_smart_asm::t_call_stat::t_params t_params;
      vector<string> types;
      void calc(t_smart_asm_level_inliner&dev,t_params&params)
      {
        //calc types
        auto&arr=params.arr;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          string t=dev.DoDeclType(ex);
          types.push_back(t);
        }
      }
      void calc(t_smart_asm_level_inliner&dev,TAutoPtr<t_params>&params){
        if(!params)return;
        auto&ref=*params.get();
        calc(dev,ref);
      }
    };
  public:
    typedef t_smart_asm::t_call_stat::t_params t_call_stat_params;
    typedef t_smart_asm::t_func_node::t_param t_func_node_param;
    typedef vector<t_func_node_param> t_func_node_params;
    //
    /*string get_top_var_name(const vector<int>&path,int id,const string&var_name){
      return "v"+t_var::path_to_raw_prefix(dev.stat_path)+"_t"+IToS(id)+"_"+var_name;
    }*/
    string var_name_local2global(const string&var_name){
      return with_prefix(var_name);
    }
    void gen_func_params(t_call_stat_params&params,t_func_node_params&fparams){
      static const string quote="\"";
      static const string mov=quote+"mov"+quote;
      QapAssert(fparams.size()==params.arr.size());
      auto&arr=params.arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&fex=fparams[i];
        auto source=toStr_with_prefix(ex);
        auto&var=dev.head.vars[dev.add_var(fex.type,fex.name)];
        auto dest=with_prefix(fex.name);
        //get_top_var_name(dev.stat_path,i,fex.name);
        auto init="{call "+mov+" "+dest+" "+source+"}";
        add("var "+fex.type+" "+dest+init);
      }
    }
    void gen_func_params(TAutoPtr<t_call_stat_params>&params,t_func_node_params&fparams){
      if(!params)return;
      auto&ref=*params.get();
      gen_func_params(ref,fparams);
    }
    void gen_func_param_proxy(t_func_node_params&fparams){
      return;/*
      static const string quote="\"";
      static const string mov=quote+"mov"+quote;
      auto prev_path=dev.stat_path;
      prev_path.pop_back();
      auto&arr=fparams;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto dest=with_prefix(ex.name);
        auto source=get_top_var_name(prev_path,i,ex.name);
        auto init="{call "+mov+" "+dest+" "+source+"}";
        auto type=ex.type;
        add("var "+type+" "+dest+init);
        dev.add_var(type,dest);
      }*/
    }
  public:
    string with_prefix(const string&var_name){return dev.with_prefix(var_name);}
    void with_prefix_mod(t_var_stat&var){dev.with_prefix_mod(var);}
    void with_prefix_mod(TAutoPtr<i_expr>&expr){dev.with_prefix_mod(expr);}
    string toStr_with_prefix(TAutoPtr<i_expr>&ref){return dev.toStr_with_prefix(ref);}
    string toStr_with_prefix(t_reg_expr&ref){return dev.toStr_with_prefix(ref);}
  public:
    void add_stat(vector<TAutoPtr<i_stat>>&out,const string&code)
    {
      TAutoPtr<i_stat> ptr;
      load_obj(dev.Env,ptr,code);
      out.push_back(std::move(ptr));
    }
  public:
    void Do(t_call_stat*p)
    {
      static const string quote="\"";
      static const string mov=quote+"mov"+quote;
      //sys way
      if(true)
      {
        static const vector<string> sys_funcs=split("mov,add,sub,div,mod,mul,more,less,eq,neq,inc,dec",",");
        bool ok=false;
        for(int i=0;i<sys_funcs.size();i++)if(sys_funcs[i]==p->func.value)ok=true;
        if(ok)
        {
          t_call_stat stat;
          clone(stat,*p);
          auto&arr=stat.params.get()->arr;
          for(int i=0;i<arr.size();i++)
          {
            auto&expr=arr[i];
            with_prefix_mod(expr);
          }
          dev.with_prefix_mod(stat.out);
          add(toStr(stat));
          return;
        }
        int gg=1;
      }
      t_calc_params_tool tool;
      tool.calc(dev,p->params);
      auto&f=dev.unsafe_find_func(p->func.value,tool.types);
      auto info=t_label_info::make("func",f.name.value+"()");
      add("loop:func_body");
      add("{");
      {
        gen_func_params(p->params,f.params);
        dev.retvars.push_back(toStr_with_prefix(p->out));
        //dev.add_var(f.type,"$");
        //add("var "+f.type+" "+with_prefix("$"));
        {
          dev.push_label(info);
          t_block fcode;
          clone(fcode,f.code);
          //add_stat(fcode.arr,"\n");
          //add_stat(fcode.arr,"{break:func_body}");
          dev.Do(fcode);
          dev.pop_label(info);
        }
        dev.retvars.pop_back();
        //add("call "+mov+" "+toStr_with_prefix(p->out)+" "+with_prefix("$"));
      }
      add("}");
    }
    void Do(t_block_stat*p){
      dev.Do(p->body);
    }
    void Do(t_break_stat*p){
      QapDebugMsg("no way");
      return;
    }
    void Do(t_continue_stat*p){
      QapDebugMsg("no way");
      return;
    }
    void Do(t_loop_stat*p)
    {
      QapDebugMsg("no way");
      return;
    }
    void Do(t_if_stat*p)
    {
      QapDebugMsg("no way");
      return;
    }
    void Do(t_for_stat*p)
    {
      QapDebugMsg("no way");
      return;
    }
  public:
    void Do(t_auto_stat*p){
      QapDebugMsg("no way");
      return;
    }
    void Do(t_var_stat*p){
      auto&ref=*p;
      string fulltype=toStr(ref.type);
      auto id=dev.add_var(fulltype,p->name.value);
      //
      t_var_stat stat;
      clone(stat,*p);
      auto&name=stat.name.value;
      name=with_prefix(name);
      add(toStr(stat));
    }
    void Do(t_sep_stat*p){
      //toDev(p);
    }
  };
public:
  struct t_reg_id{
    int frame_id;
    int id;
    void init(){frame_id=-1;id=-1;}
    bool isOK(){return id>=0;}
    t_var&get(t_smart_asm_level_inliner&ref)const{
      auto&frame=frame_id<0?ref.head:ref.frames[frame_id];
      return frame.vars[id];
    }
  };
  t_reg_id find_reg(const string&name)
  {
    t_reg_id result;
    result.init();
    auto&frame_id=result.frame_id;
    auto&id=result.id;
    result.id=head.find_var(name);
    if(result.id>=0)return result;
    for(int i=0;i<frames.size();i++){
      frame_id=frames.size()-i-1;
      auto&ex=frames[frame_id];
      id=ex.find_var(name);
      if(id>=0)return result;
    }
    result.init();
    return result;
  }
  t_var&unsafe_find_reg(const string&name)
  {
    auto v=find_reg(name);
    if(v.isOK())return v.get(*this);
    QapDebugMsg("regiser not found:\n"+name);
    return *(t_var*)nullptr;
  }
public:
  void ret(const string&type)
  {
    //QapDebugMsg("no way");
  }
public:
  /*copy-paste*/class t_expr_decltype:public t_smart_asm::i_expr_visitor{
  /*copy-paste*/public:
  /*copy-paste*/  class t_dev{
  /*copy-paste*/  public:
  /*copy-paste*/    t_smart_asm_level_inliner&machine;
  /*copy-paste*/    string retval;
  /*copy-paste*/  };
  /*copy-paste*/  t_dev&dev;
  /*copy-paste*/  t_expr_decltype(t_dev&dev):dev(dev){}
  /*copy-paste*/public:
  /*copy-paste*/  void Do(t_num_expr*p){
  /*copy-paste*/    dev.retval="int";
  /*copy-paste*/  }
  /*copy-paste*/  void Do(t_reg_expr*p)
  /*copy-paste*/  {
  /*copy-paste*/    dev.retval=dev.machine.DoDeclType(*p);
  /*copy-paste*/  }
  /*copy-paste*/};
  /*copy-paste*/t_func_node&unsafe_find_func(const string&func,const vector<string>&types)
  /*copy-paste*/{
  /*copy-paste*/  auto&arr=scope.arr;
  /*copy-paste*/  for(int i=0;i<arr.size();i++)
  /*copy-paste*/  {
  /*copy-paste*/    auto&ex=arr[i];
  /*copy-paste*/    auto*ptr=ex.get();
  /*copy-paste*/    auto*p=t_func_node::UberCast(ptr);
  /*copy-paste*/    if(!p)continue;
  /*copy-paste*/    if(p->name.value!=func)continue;
  /*copy-paste*/    //compare
  /*copy-paste*/    {
  /*copy-paste*/      auto&arr=p->params;
  /*copy-paste*/      if(arr.size()!=types.size())continue;
  /*copy-paste*/      int ok=-1;
  /*copy-paste*/      for(int i=0;i<arr.size();i++){
  /*copy-paste*/        if(arr[i].type!=types[i])break;
  /*copy-paste*/        ok=i;
  /*copy-paste*/      }
  /*copy-paste*/      if(ok+1!=types.size())continue;
  /*copy-paste*/    }
  /*copy-paste*/    return *p;
  /*copy-paste*/  }
  /*copy-paste*/  QapDebugMsg("function not found:\n"+func+"("+join(types,",")+")");
  /*copy-paste*/  return *(t_func_node*)nullptr;
  /*copy-paste*/}
  /*copy-paste*/string DoDeclType(TAutoPtr<i_expr>&expr){
  /*copy-paste*/  t_expr_decltype::t_dev dev={*this};
  /*copy-paste*/  t_expr_decltype V(dev);
  /*copy-paste*/  auto*p=expr.get();
  /*copy-paste*/  p->Use(V);
  /*copy-paste*/  return dev.retval;
  /*copy-paste*/}
  /*copy-paste*/string DoDeclType(t_reg_expr&expr)
  /*copy-paste*/{
  /*copy-paste*/  auto&ref=unsafe_find_reg(expr.name);
  /*copy-paste*/  if(!expr.ext)
  /*copy-paste*/  {
  /*copy-paste*/    return ref.type;
  /*copy-paste*/  }
  /*copy-paste*/  auto*ptr=expr.ext->body.get();
  /*copy-paste*/  auto*p=t_reg_expr::t_field::UberCast(ptr);
  /*copy-paste*/  QapAssert(p);
  /*copy-paste*/  auto&v=unsafe_find_struct(ref.type);
  /*copy-paste*/  auto&arr=v.arr;
  /*copy-paste*/  for(int i=0;i<arr.size();i++)
  /*copy-paste*/  {
  /*copy-paste*/    auto&ex=arr[i];
  /*copy-paste*/    if(ex.name==p->field)
  /*copy-paste*/    {
  /*copy-paste*/      return ex.type;
  /*copy-paste*/    }
  /*copy-paste*/  }
  /*copy-paste*/  QapDebugMsg("no way.");
  /*copy-paste*/  int gg=1;
  /*copy-paste*/  return *(string*)nullptr;
  /*copy-paste*/}
public:
  t_func_node&unsafe_find_func_by_name(const string&func)//copy-paste
  {                                                      //copy-paste
    auto&arr=scope.arr;                                  //copy-paste
    for(int i=0;i<arr.size();i++)                        //copy-paste
    {                                                    //copy-paste
      auto&ex=arr[i];                                    //copy-paste
      auto*ptr=ex.get();                                 //copy-paste
      auto*p=t_func_node::UberCast(ptr);                 //copy-paste
      if(!p)continue;                                    //copy-paste
      if(p->name.value!=func)continue;                   //copy-paste
      return *p;                                         //copy-paste
    }                                                    //copy-paste
    QapDebugMsg("function not found:\n"+func);           //copy-paste
    return *(t_func_node*)nullptr;                       //copy-paste
  }                                                      //copy-paste
public:
  void push_label(const t_label_info&info){
    labels.push_back(info);
  }
  void pop_label(const t_label_info&info){
    QapAssert(!labels.empty())
    QapAssert(labels.back()==info);
    labels.pop_back();
  }
public:
  // DEF_PRO_VARIABLE <----------
public:
  IEnvRTTI&Env;
  t_smart_asm::t_asm_scope scope;
  t_stackframe head;
  vector<t_stackframe> frames;
  vector<t_label_info> labels;
  vector<string> user_types;
  vector<string> all_types;
  string out;
  vector<string> retvars;
  vector<int> stat_path;
public:
  t_smart_asm_level_inliner(IEnvRTTI&Env):Env(Env){}
public:
  void Do(t_block&block){
    stat_path.reserve(1024*8);
    stat_path.push_back(0);
    auto&id=stat_path.back();
    add("{");
    t_stat_visitor V(*this);
    auto&arr=block.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(!t_sep_stat::UberCast(ex.get()))id++;
      ex->Use(V);
    }
    add("}");
    stat_path.pop_back();
  }
public:
  void Do()
  {
    auto&f=unsafe_find_func_by_name("main");
    auto info=t_label_info::make("func",f.name.value+"()");
    push_label(info);
    {
      string params_code;
      if(!f.params.empty())
      {
        vector<t_func_node::t_param> params;
        clone(params,f.params);
        for(int i=0;i<params.size();i++){
          auto&ex=params[i];
          auto&name=ex.name;
          name=with_prefix(name);
          add_var(ex.type,ex.name);
        }
        params_code=toStr(params);
      }
      add(f.type+" "+toStr(f.name)+"("+params_code+")asm");
      Do(f.code);
    }
    pop_label(info);
    //add user types
    string out_types;
    {
      auto&arr=user_types;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&ref=unsafe_find_struct(ex);
        out_types+=toStr(ref)+"\n";
      }
    }
    out=out_types+out;
  }
};
class t_diff_apply:public IVisitorRTTI,public t_diff_sys,public t_type_diff_tool{
public:
  struct t_item{
    TRawPtr from;
    TRawPtr to;
  };
  struct t_struct_patch{
    TTypeStruct*pType;
    string fields;
    int n;
  };
public:
  IEnvRTTI&Env;
  string out_msg;
  vector<t_item> stack;
  t_item top;
  TQapIO IO;
  vector<t_struct_patch> patches;
public:
  t_diff_apply(IEnvRTTI&Env):Env(Env)
  {}
public:
  void clear()
  {
    out_msg.clear();
  }
  TRawPtr getValue(TTypeStruct::Member&ex,TRawPtr&ptr){
    TRawPtr out;
    out.pType=ex.Type.get();
    out.pValue=ex.getValue(ptr.pValue);
    return out;
  }
  void push(){
    stack.push_back(top);
  }
  void pop(){
    QapAssert(!stack.empty());
    top=stack.back();
    stack.pop_back();
  }
  void set_outmsg(char c){
    static auto arr=split("def|new|patch|xpatch|resize|+1|-1|update|#num|0|1|less_n","|");
    for(int i=0;i<arr.size();i++){
      if(c==arr[i][0]){out_msg=arr[i];return;}
    }
    QapDebugMsg("no way.");
  }
  void loadmsg()
  {
    char c;
    IO.LoadPOD(&c,1);
    set_outmsg(c);
  }
  void load_header()
  {
    QapDebugMsg("no way");
    return;
    vector<t_diff_fields_info> arr;
    bool ok=TSimpleBinaryLoader::fromIO(Env,&arr,IO);
    QapAssert(ok);
    patches.resize(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&out=patches[i];
      auto&inp=arr[i];
      auto*pt=Env.FindTypeByName_is_ug_but_work(inp.type);
      auto*pType=TTypeStruct::UberCast(pt);
      QapAssert(pType);
      out.pType=pType;
      out.fields=inp.fields;
      out.n=0;
    }
  }
  void load_short_header()
  {
    string typelist;
    char nextline;
    string tmp;
    IO.load(typelist); IO.load(nextline); IO.load(tmp);
    vector<string> types=split(typelist,"\n");
    vector<string> fields=split(tmp,"\n");
    for(int i=0;i<fields.size();i++)
    {
      auto t=split(fields[i],".");
      auto fn=types[t[0][0]];
      auto*pt=Env.FindTypeByName_is_ug_but_work(fn);
      auto*pType=TTypeStruct::UberCast(pt);
      QapAssert(pType);
      auto&out=qap_add_back(patches);
      out.pType=pType;
      out.fields=t[1];
      out.n=0;
    }
  }
  void load()
  {
    load_short_header();
    loadmsg();
  }
  int find_patch_id(TTypeStruct*p,char id)
  {
    int n=id;
    for(int i=0;i<patches.size();i++)
    {
      auto&ex=patches[i];
      if(ex.pType!=p)continue;
      if(!n)
      {
        ex.n++;
        return i;
      }
      n--;
    }
    return -1;
  }
  t_struct_patch&load_patch_id(TTypeStruct*p)
  {
    char c;
    IO.LoadPOD(&c,1);
    auto id=find_patch_id(p,c);
    QapAssert(id>=0);
    return patches[id];
    //find_patch(
  }
public:
  void Do(TTypeStruct*p)
  {
    QapDebugMsg("WTF?");
  }
  void Do(TTypeSys*p)
  {
    if(out_msg=="1")
    {
      if(is_int(p))
      {
        auto&aft=*(int*)top.to.pValue;
        aft=1;
        return;
      }
      if(is_real(p))
      {
        auto&aft=*(real*)top.to.pValue;
        aft=1.0;
        return;
      }
      QapDebugMsg("no way");
      return;
    }
  }
  void Do(TTypeVector*p)
  {
    QapDebugMsg("WTF?");
  }
  void Do(TTypeFactory*p){QapDebugMsg("no way");}
  void Do(TTypeArray*p){QapDebugMsg("no way");}
  void Do(TTypeSelfPtr*p){QapDebugMsg("no way");}
  void Do(TTypeAutoPtr*p){QapDebugMsg("no way");}
  void Do(TTypeWeakPtr*p){QapDebugMsg("no way");}
  void Do(TTypeHardPtr*p){QapDebugMsg("no way");}
  void Do(TTypeVoidPtr*p){QapDebugMsg("no way");}
  void Do(TTypeFieldPtr*p){QapDebugMsg("no way");}
};

template<class TYPE>
void apply_diff(IEnvRTTI&Env,const string&diff,TYPE&from,TYPE&to)
{
  TRawPtr pFrom(Env,from);
  TRawPtr pTo(Env,to);
  t_diff_apply V(Env);
  V.IO.IO.mem=diff;
  V.top.from=pFrom;
  V.top.to=pTo;
  V.load();
  pTo.pType->Use(V);
}
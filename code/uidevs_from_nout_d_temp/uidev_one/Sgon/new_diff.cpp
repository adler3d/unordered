#include "StdAfx.h"

#include "TSimpleBinarySaver.inl"
#include "gabob_types.inl"

class t_diff_cmd{
public:
#define DEF_PRO_AUTO_EQUAL()
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_cmd)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,cmd,DEF,$,$)\
ADDVAR(bool,ok,DEF,$,$)\
ADDVAR(string,type,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,info,DEF,$,$)\
ADDVAR(real,ms,DEF,$,$)\
ADDVAR(real,gen_cmds_ms,DEF,$,$)\
ADDVAR(vector<t_diff_cmd>,arr,DEF,$,$)\
ADDVAR(vector<t_diff_cmd>,all,DEF,$,$)\
ADDEND()
//=====+>>>>>t_diff_cmd
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_cmd
public:
};

#define CMDFUNC_LIST(F)\
  F(t_def_cmdfunc)F(t_new_cmdfunc)F(t_struct_cmdfunc)F(t_vector_cmdfunc)F(t_struct_short_cmdfunc)\
  F(t_vector_resize_cmdfunc)F(t_vector_skip_n_cmdfunc)\
  F(t_int_add_cmdfunc)F(t_int_dec_cmdfunc)F(t_real_dec_cmdfunc)F(t_real_add_cmdfunc)\
  F(t_int_zero_cmdfunc)F(t_int_one_cmdfunc)F(t_real_zero_cmdfunc)F(t_real_one_cmdfunc)\
  F(t_phys_move_cmdfunc)F(t_particle_move_cmdfunc)\
  F(t_vector_init_cmdfunc)F(t_vector_resize_as_empty_cmdfunc)\
  F(t_particle_get_pos_from_parent_cmdfunc)\
  F(t_real_as_byte_cmdfunc)F(t_real_inv_cmdfunc)\
  F(t_string_empty_cmdfunc)F(t_string_short_cmdfunc)F(t_int_as_byte_cmdfunc)

//#define CMDFUNC_LIST(F)F(t_def_cmdfunc)F(t_new_cmdfunc)F(t_struct_cmdfunc)F(t_vector_cmdfunc)F(t_vector_resize_cmdfunc)

struct TQapIOGrabber:public QapIO{
public:
  QapIO&IO;
  string&data;
  TQapIOGrabber(QapIO&IO,string&data):IO(IO),data(data){if(IO.IsSizeIO())QapNoWay();}
public:
  void SavePOD(void*p,int count)
  {
    IO.SavePOD(p,count);
    QapAssert(count>=0);
    int size=data.size();
    data.resize(size+count);
    for(int i=0;i<count;i++){data[size+i]=((char*)p)[i];}
  }
  void LoadPOD(void*p,int count)
  {
    IO.LoadPOD(p,count);
    QapAssert(count>=0);
    int size=data.size();
    data.resize(size+count);
    for(int i=0;i<count;i++){data[size+i]=((char*)p)[i];}
  }
  bool TryLoad(int count){return IO.TryLoad(count);}
  void Crash(){IO.Crash();}
  bool IsCrashed(){return IO.IsCrashed();}
  bool IsSizeIO(){return IO.IsSizeIO();}
  int GetSize(){return IO.GetSize();}
  QapPolyIO MakeIO(){return IO.MakeIO();}
  void WriteTo(QapIO&IO){return IO.WriteTo(IO);}
};

class t_type_diff_tool{
public:
  static bool is_int(TTypeSys*p)
  {
    if(p->BinIO.get()!=THeadBinIO<int>::Get())return false;
    QapAssert(p->GetFullName()=="int");
    return true;
  }
  static bool is_int(TType*p){auto*ptr=TTypeSys::UberCast(p);return ptr?is_int(ptr):false;}
  static bool is_real(TTypeSys*p)
  {
    if(p->BinIO.get()!=THeadBinIO<real>::Get())return false;
    QapAssert(p->GetFullName()=="real");
    return true;
  }
  static bool is_real(TType*p){auto*ptr=TTypeSys::UberCast(p);return ptr?is_real(ptr):false;}
  static bool is_real(TWeakPtr<TType>&p){return is_real(p.get());}
  static bool is_real(THardPtr<TType>&p){return is_real(p.get());}
  static bool is_real(TTypeStruct::Member&member){return is_real(member.Type);}
  static bool is_string(TTypeSys*p)
  {
    if(p->BinIO.get()!=THeadBinIO<string>::Get())return false;
    QapAssert(p->GetFullName()=="string");
    return true;
  }
  static bool is_string(TType*p){auto*ptr=TTypeSys::UberCast(p);return ptr?is_string(ptr):false;}
  static bool is_vec2d(TTypeStruct*p)
  {
    auto&v=p->Members;
    if(v.size()!=2)return false;
    if(!is_same_type(v[0],v[1]))return false;
    return is_real(v[0]);
  }
  static bool is_vec2d(TType*p){auto*ptr=TTypeStruct::UberCast(p);return ptr?is_vec2d(ptr):false;}
  static bool is_vec2d(THardPtr<TType>&p){return is_vec2d(p.get());}
  static bool is_vec2d(TTypeStruct::Member&member){return is_vec2d(member.Type);}
  static bool is_same_type(TTypeStruct::Member&a,TTypeStruct::Member&b){return a.Type.get()==b.Type.get();}
public:
  int&get_int(TRawPtr&ptr){QapAssert(is_int(ptr.pType));return *(int*)ptr.pValue;}
  real&get_real(TRawPtr&ptr){QapAssert(is_real(ptr.pType));return *(real*)ptr.pValue;}
  string&get_string(TRawPtr&ptr){QapAssert(is_string(ptr.pType));return *(string*)ptr.pValue;}
};

template<class TYPE>
static vector<int> qap_find_by_value(vector<TYPE>&arr,TYPE&ref)
{
  vector<int> out;
  for(int i=0;i<arr.size();i++)if(arr[i]==ref)qap_add_back(out)=i;
  return out;
}

class t_cmd;
class i_diff_dev;
class i_cmdfunc;

struct t_cmd{
  i_cmdfunc*cmdfunc;
  int size;
  bool ok;
  string type;
  string name;
  string info;
  string data;
  real ms;
  real gen_cmds_ms;
  vector<t_cmd> arr;
  vector<t_cmd> all;
  void DoReset()
  {
    cmdfunc=nullptr;
    size=-1;
    ok=false;
    type.clear();
    name.clear();
    info.clear();
    data.clear();
    arr.clear();
    ms=0;
    gen_cmds_ms=0;
  }/*
  int get_size()
  {
    if(size==-1)calc_size();
    return size;
  }
  void calc_size()
  {
    QapAssert(ok);
    if(size>=0)return;
    int v=0;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      v+=ex.get_size();
    }
    size=data.size()+v;
  }*/
  static void conv(vector<t_cmd>&bef,vector<t_diff_cmd>&aft,bool hide_def)
  {
    if(hide_def)
    {
      for(int i=0;i<bef.size();i++)
      {
        if(get_func_name<0>(bef[i].cmdfunc)=="t_def_cmdfunc")continue;
        qap_add_back(aft);
        conv(bef[i],aft.back());
      }
    }
    if(!hide_def)
    {
      aft.resize(bef.size());
      for(int i=0;i<bef.size();i++)
      {
        conv(bef[i],aft[i]);
      }
    }
  }
  template<int> static string&get_func_name(i_cmdfunc*func){return func->name;}
  static void conv(t_cmd&bef,t_diff_cmd&aft)
  {
    aft.cmd=!bef.cmdfunc?"nullptr":get_func_name<0>(bef.cmdfunc);
    aft.ok=bef.ok;
    aft.type=bef.type;
    aft.name=bef.name;
    aft.info=bef.info;
    aft.ms=bef.ms;
    aft.gen_cmds_ms=bef.gen_cmds_ms;
    static bool hide_def=false;
    conv(bef.arr,aft.arr,hide_def);
    conv(bef.all,aft.all,hide_def);
  }
  string toStr(IEnvRTTI&Env)
  {
    t_diff_cmd out;
    conv(*this,out);
    auto t=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(out));
    //t=StrReplace(t,"t_diff_sys::","");
    t=t.substr(t.find("\nTHardPtr<TType>(Sys$$<t_diff_cmd>::GetRTTI())\n"));
    return t;
  }
};

class i_cmdfunc:public t_type_diff_tool{
public:
  string name;
  int n;
  int ok;
  real fail_time;
  real total_time;
  real time_ok_raw;
  int lock;
  i_cmdfunc():n(0),ok(0),total_time(0),lock(0),time_ok_raw(0){}
public:
  virtual void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeStruct*p){}
  virtual void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p){}
  virtual void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeVector*p){}
  virtual void call(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TType*p)
  {
    auto*a=TTypeStruct::UberCast(p);auto*b=TTypeSys::UberCast(p);auto*c=TTypeVector::UberCast(p);
    if(a){go(dev,IO,ref,a);return;}
    if(b){go(dev,IO,ref,b);return;}
    if(c){go(dev,IO,ref,c);return;}
  }
  virtual void main(i_diff_dev&dev,QapIO&IO,t_cmd&ref)
  {
    auto*pType=weak_dev_get_top_bef_type(dev);
    call(dev,IO,ref,pType);
  }
  template<class i_diff_dev>static TType*weak_dev_get_top_bef_type(i_diff_dev&dev)
  {
    return dev.top.bef.pType;
  }
  template<class i_diff_dev>static void weak_dev_save_cmdfunc(i_diff_dev&dev,QapIO&IO,i_cmdfunc*func)
  {
    dev.save_cmdfunc(IO,func);
  }
  template<class TYPE>
  static i_cmdfunc*get(char*p)
  {
    static TYPE cmdfunc;
    static bool need_init=true;
    if(!need_init)return &cmdfunc;
    need_init=false;
    cmdfunc.name=p;
    return &cmdfunc;
  }
};

class i_diff_dev{
public:
public:
  struct t_item{
    TRawPtr bef;
    TRawPtr aft;
    void set(TType*pType,void*pBef,void*pAft){bef.set(pType,pBef);aft.set(pType,pAft);}
  };
  struct t_struct_patch{
    TTypeStruct*pType;
    string fields;
  };
public:
  IEnvRTTI&Env;
  //t_cmd out;
  t_item top;
  vector<t_item> stack;
  vector<string> way;
  vector<t_struct_patch>*ppatches;
  vector<i_cmdfunc*> cmdfuncs;
  int depth;
public:
  i_diff_dev(IEnvRTTI&Env):Env(Env),depth(0){}
public:
  template<int>
  static vector<i_cmdfunc*> weak_get_cmdfuncs()
  {
    vector<i_cmdfunc*> arr;
    #define F(CMDFUNC)qap_add_back(arr)=i_cmdfunc::get<CMDFUNC>(#CMDFUNC);
    CMDFUNC_LIST(F)
    #undef F
    return arr;
  }
  void init()
  {
    cmdfuncs=weak_get_cmdfuncs<0>();
  }
public:
  virtual bool isSave(){QapNoWay();return false;}
  virtual bool isLoad(){QapNoWay();return false;}
  virtual bool isDebug(){QapNoWay();return false;}
public:
  template<class TYPE>
  string toBin(IEnvRTTI&Env,TYPE&ref)
  {
    return TSimpleBinarySaver::toStr(Env,ref);
  }
  string toBinEx(TRawPtr&ref)
  {
    return TSimpleBinarySaver::toStrEx(ref.pType,ref.pValue);
  }
public:
  //void ret(){out.ok=true;}
public:
  TRawPtr getValue(TTypeStruct::Member&ex,TRawPtr&ptr)
  {
    TRawPtr out;
    out.pType=ex.Type.get();
    out.pValue=ex.getValue(ptr.pValue);
    return out;
  }
  static int&get_push_counter(){
    static int counter=0;
    return counter;
  }
  void push(TTypeStruct::Member&ex)
  {
    if(isDebug())
    {
      way.push_back(ex.Name);get_push_counter()++;
    }
    stack.push_back(top);
    top.bef=getValue(ex,top.bef);
    top.aft=getValue(ex,top.aft);
  }
  void pop(TTypeStruct::Member&ex)
  {
    if(isDebug())
    {
      QapAssert(way.back()==ex.Name);get_push_counter()++;
      way.pop_back();
    }
    pop();
  }
  void push(int i)
  {
    if(isDebug())
    {
      way.push_back(IToS(i));
    }
    push();
  }
  void pop(int i)
  {
    if(isDebug())
    {
      QapAssert(way.back()==IToS(i));
      way.pop_back();
    }
    pop();
  }
  void push()
  {
    stack.push_back(top);
  }
  void pop()
  {
    QapAssert(!stack.empty());
    top=stack.back();
    stack.pop_back();
  }
public:
  char get_struct_patch_id(TTypeStruct*p,const string&fi)
  {
    auto&arr=*ppatches;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.pType!=p)continue;
      if(ex.fields!=fi)continue;
      return i;
    }
    int id=arr.size();
    QapAssert(id<=255);
    auto&back=qap_add_back(arr);
    back.pType=p;
    back.fields=fi;
    return id;
  }
  void save_cmdfunc(QapIO&IO,i_cmdfunc*ptr)
  {
    char id=get_cmdfunc_id(ptr);
    IO.save(id);
  }
  void load_cmdfunc(QapIO&IO,i_cmdfunc*&ptr)
  {
    char id;
    IO.load(id);
    QapAssert(id>=0&&id<cmdfuncs.size());
    ptr=cmdfuncs[id];
  }
  char get_cmdfunc_id(i_cmdfunc*ptr)
  {
    auto arr=qap_find_by_value(cmdfuncs,ptr);//(cmdfuncs,[ptr](t_cmdfunc_info&ex){return ex.ptr==ptr;});
    if(arr.empty())
    {
      QapNoWay();
      //qap_add_back(arr)=cmdfuncs.size();
      //qap_add_back(cmdfuncs)={ptr,};
    }
    QapAssert(arr.size()==1);
    QapAssert(cmdfuncs.size()<=0xff);
    return arr[0];
  }
public:
  struct t_call_log_item{
    TType*pt;
    int n;
    string way;
    void*pb;
    void*pa;
    bool lock;
    int depth;
    bool operator==(t_call_log_item&ref)const
    {
      #define F(NAME)if(ref.NAME!=NAME)return false;
      F(way)F(depth)F(pt)F(pb)F(pa)
      #undef F
      return true;
    }
  };
  //template<class TYPE>static qap_find_and_ret_
  static vector<t_call_log_item>&get_info_arr()
  {
    static vector<t_call_log_item> tmp;
    tmp.reserve(1024*1024);
    return tmp;
  }
  static t_call_log_item&get_call_ref(t_item&item,const string&curway,int depth)
  {
    QapAssert(item.aft.pType==item.bef.pType);
    auto*pType=item.bef.pType;
    auto*pb=item.bef.pValue;
    auto*pa=item.aft.pValue;
    t_call_log_item tmp={pType,0,curway,pb,pa,false,depth};
    auto&arr=get_info_arr();
    auto t=qap_find_by_value(arr,tmp);
    if(t.empty())
    {
      qap_add_back(t)=arr.size();
      qap_add_back(arr)=tmp;
    }
    if(t.size()>1)
    {
      int wtf=1;
    }
    auto&ref=arr[t[0]];
    return ref;
  }
  void gen_cmds(vector<t_cmd>&cmds,vector<QapPolyIO>&IOs,QapIO&ParentIO)
  {
    auto curway="root"+(way.empty()?"":"."+join(way,"."));
    auto*pcallref=true?nullptr:&get_call_ref(top,curway,depth);
    if(pcallref)
    {
      auto&callref=*pcallref;
      if(!callref.n)
      {
        int gg=1;
      }
      callref.n++;
      if(callref.lock)
      {
        int wtf=1;
      }
      callref.lock=true;
      if(callref.n>1)
      {
        int gg=1;
      }
    }
    string name;
    if(isDebug())name=(way.empty()?"root":way.back());
    QapAssert(cmds.empty());
    cmds.clear();
    cmds.resize(cmdfuncs.size());
    IOs.resize(cmdfuncs.size());
    for(int i=0;i<cmdfuncs.size();i++)
    {
      QapClock clock; clock.Start();
      auto&ex=*cmdfuncs[i];
      auto&cmd=cmds[i];
      auto&IO=IOs[i];
      IO.impl=std::move(ParentIO.MakeIO().impl);
      cmd.DoReset();//ex.lock++;
      ex.main(*this,IO,cmd);
      cmd.cmdfunc=&ex;
      clock.Stop();
      cmd.ms=clock.MS();//ex.lock--;
      //ex.n++;
      //ex.total_time+=clock.MS();
      if(!cmd.ok)
      {
        //ex.fail_time+=clock.MS();
        IO.impl=nullptr;
        continue;
      }
      //ex.ok++;
      //if(!ex.lock)ex.time_ok_raw+=clock.MS();
      if(isDebug())cmd.name=name;
      if(isDebug())cmd.type=top.aft.pType->GetFullName();
      cmd.size=IO.GetSize();
      if(!cmd.size)
      {
        int gg=1;
        cmds.resize(i+1);
        IOs.resize(i+1);
        break;
      }
    }
    if(pcallref)pcallref->lock=false;
  }
  void find_best_cmd(t_cmd&out,QapIO&IO)
  {
    static bool zdebug=false;
    vector<t_cmd> arr;
    if(zdebug)if(top.bef.pType->GetFullName()=="TGabobPhys"){
      int wtf=1;
    }
    vector<QapPolyIO> IOs;static int inc=0;inc++;
    QapClock clock; clock.Start();
    gen_cmds(arr,IOs,IO);
    clock.Stop();
    if(zdebug)if(top.bef.pType->GetFullName()=="TGabobPhys"){
      int wtf=1;
    }
    inc--;
    if(!inc)if(0)
    {
      t_cmd t;t.DoReset();t.cmdfunc=cmdfuncs[0];
      for(int i=0;i<arr.size();i++)arr[i].cmdfunc=cmdfuncs[i];
      //t.arr=std::move(arr);
      auto s=t.toStr(Env);
      int gg=1;
    }
    //out.arr=std::move(arr);
    //return;
    int best=-1;real sum=0;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];sum+=ex.ms;
      if(!ex.ok)continue;
      if(best>=0&&IOs[i].GetSize()>=IOs[best].GetSize())continue;
      best=i;
    }
    if(best<0){out.DoReset();return;}
    out=std::move(arr[best]);arr[best].cmdfunc=nullptr;arr[best].info=FToS(sum);
    out.gen_cmds_ms=clock.MS();
    //out.all=std::move(arr);
    IOs[best].WriteTo(IO);
  }
public:
  void load_from_top(t_cmd&ref,QapIO&IO)
  {
    ref.cmdfunc->main(*this,IO,ref);
    //QapNoWay();
    //string name=way.empty()?"root":way.back();
    //out.cmdfunc->main(*this);
    //out.p=top.bef.pType;
    //out.name=name;
    //out.type=top.aft.pType->GetFullName();
  }
};

class t_save_diff_dev:public i_diff_dev{
public:
  bool debug;
  t_save_diff_dev(IEnvRTTI&Env,bool debug):i_diff_dev(Env),debug(debug){}
public:
  bool isSave(){return true;}
  bool isLoad(){return false;}
  bool isDebug(){return debug;}
};

class t_load_diff_dev:public i_diff_dev{
public:
  bool debug;
  t_load_diff_dev(IEnvRTTI&Env,bool debug):i_diff_dev(Env),debug(debug){}
public:
  bool isSave(){return false;}
  bool isLoad(){return true;}
  bool isDebug(){return debug;}
};

template<class TYPE>
string compute_diff(IEnvRTTI&Env,TYPE&bef,TYPE&aft,bool debug=false,int depth=0)
{
  TRawPtr pbef;
  TRawPtr paft;
  pbef.set(Env,bef);
  paft.set(Env,aft);
  {
    TDataIO IO;
    compute_diff_ex(Env,IO,pbef,paft,debug,depth);
    return IO.IO.mem;
  }
  return "";
}

void compute_diff_ex(IEnvRTTI&Env,QapIO&IO,TRawPtr&bef,TRawPtr&aft,bool debug=false,int depth=0)
{
  vector<i_diff_dev::t_struct_patch> struct_patches;
  t_save_diff_dev dev(Env,debug);
  dev.ppatches=&struct_patches;
  dev.init();
  dev.depth=depth;
  //dev.need_save=true;
  dev.top.bef=bef;
  dev.top.aft=aft;
  t_cmd cmd;
  auto tmpIO=IO.MakeIO(); QapClock clock;clock.Start();
  dev.find_best_cmd(cmd,tmpIO);          clock.Stop();
  dev.save_cmdfunc(IO,cmd.cmdfunc);
  tmpIO.WriteTo(IO);
  if(debug&&!depth)
  {
    file_put_contents("info.h",FToS(clock.MS())+cmd.toStr(Env));
  }
}
template<class TYPE>
string fast_diff_compute_ex(IEnvRTTI&Env,TYPE&rbef,TYPE&raft,bool debug=false,int depth=0)
{
  TRawPtr bef;
  TRawPtr aft;
  bef.set(Env,rbef);
  aft.set(Env,raft);
  TSizeIO IO;
  vector<i_diff_dev::t_struct_patch> struct_patches;
  t_save_diff_dev dev(Env,debug);
  dev.ppatches=&struct_patches;
  dev.init();
  dev.depth=depth;
  //dev.need_save=true;
  dev.top.bef=bef;
  dev.top.aft=aft;
  t_cmd cmd;
  auto tmpIO=IO.MakeIO();
  dev.find_best_cmd(cmd,tmpIO);
  dev.save_cmdfunc(IO,cmd.cmdfunc);
  tmpIO.WriteTo(IO);
  if(debug)
  {
    file_put_contents("info.h",cmd.toStr(Env));
  }
  return "";
}

#include "new_diff_cmds.inl"
#include "new_diff_sys_cmds.inl"

template<class TYPE>
void use_diff(IEnvRTTI&Env,string&diff,TYPE&bef,TYPE&aft)
{
  TRawPtr pbef;
  TRawPtr paft;
  pbef.set(Env,bef);
  paft.set(Env,aft);
  TDataIO IO;IO.IO.mem=diff;
  use_diff_ex(Env,IO,pbef,paft,diff);
}

template<class TYPE>
void use_diff_ex(IEnvRTTI&Env,QapIO&IO,TYPE&bef,TYPE&aft,string&diff)
{
  vector<i_diff_dev::t_struct_patch> struct_patches;
  t_load_diff_dev dev(Env,true);
  dev.ppatches=&struct_patches;
  dev.init();
  //dev.need_save=true;
  dev.top.bef=bef;
  dev.top.aft=aft;
  t_cmd cmd;
  dev.load_cmdfunc(IO,cmd.cmdfunc);
  dev.load_from_top(cmd,IO);
  int gg=1;
}

void UberInfoBox(const string&caption,const string&text);

static string str(const string&s){return "\""+s+"\"";};
static void save_table(const string&file_name,const string&head,vector<string>&lines)
{
  auto a=split(head,",");
  for(int i=0;i<a.size();i++){a[i]=str(a[i]);}
  string all="["+join(a,",")+"],\n"+join(lines,",\n");
  auto out=StrReplace(StrReplace(file_get_contents("json2table.html"),"##TIME##",cur_date_str()),"##TARGET##",all);
  file_put_contents(file_name,out);
}

void fast_main(IEnvRTTI&Env)
{
  auto data=file_get_contents("frames.bin");
  vector<string> frames;
  TSimpleBinaryLoader::fromStr(Env,&frames,data);
  vector<string> diffs; vector<int> ds;
  QapClock clock;
  
  qap_add_back(diffs)="\nseqhead:\n"+frames[0]+"\nseqdiff:\n";
  for(int i=0;i<frames.size();i++)
  {
    TGabobReplayFrame a;
    TGabobReplayFrame b;
    TGabobReplayFrame c;
    if(i)TSimpleBinaryLoader::fromStr(Env,&a,frames[i-1]);
    TSimpleBinaryLoader::fromStr(Env,&b,frames[i+0]);auto src_size=frames[i+0].size();
    {
      real a=0,b=0;TSimpleBinaryLoader::fromStr(Env,&b,"¨u^hñÐdÀ");
      //TGabobPhys a;
      //TGabobPhys b;
      //TSimpleBinaryLoader::fromStr(Env,&b,"¨u^hñÐdÀ\x0F$VYg\x8Fu@i\4Cá¸\x89\x9F?înZ`Ðá\xB4?");
      clock.Start();
      auto diff=compute_diff(Env,a,b,true,0);
      clock.Stop();
      int gg=1;
    }
    clock.Start();
    auto diff=compute_diff(Env,a,b,true,0);
    clock.Stop();
    real ms=clock.MS();
    {
      int gg=1;
    }
    if(false)
    {
      auto arr=i_diff_dev::get_info_arr();vector<string> log;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        vector<string> line;
        #define adds(V)qap_add_back(line)=str(V);
        #define addi(V)qap_add_back(line)=IToS(V);
        #define addf(V)qap_add_back(line)=FToS(V);
        {
          adds(ex.pt->GetFullName())
          adds(ex.way);
          addi(ex.n);
          addi(ex.depth);
        }
        #undef addf
        #undef addi
        #undef adds
        qap_add_back(log)="["+join(line,",")+"]";
      }
      save_table("info_arr.html","type,way,n,depth",log);
      int gg=1;
    }
    ;
    if(false)
    {
      auto arr=i_diff_dev::weak_get_cmdfuncs<0>();vector<string> log;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=*arr[i];
        vector<string> line;
        #define adds(V)qap_add_back(line)=str(V);
        #define addi(V)qap_add_back(line)=IToS(V);
        #define addf(V)qap_add_back(line)=FToS(V);
        {
          adds(ex.name)
          addi(ex.n);
          addi(ex.ok);
          addf(ex.total_time);
          addf(ex.fail_time);
          addf(ex.total_time-ex.fail_time);
          addf(ex.time_ok_raw);
        }
        #undef addf
        #undef addi
        #undef adds
        qap_add_back(log)="["+join(line,",")+"]";
      }
      save_table("out.html","name,n,ok,total_time,fail_time,ok_time,time_ok_raw",log);
      int gg=1;
    }
    //c=a;
    //use_diff(Env,diff,a,c);
    //QapAssert(b==c);
    //real ratio=real(diff.size()*100.0)/real(frames[i].size());
    //file_put_contents("qd_bef.bin",frames[i]);
    //file_put_contents("qd_aft.bin",diff);
    UberInfoBox(
      "Info(Pack)",
      "------------------------------\n"
      "date : "+cur_date_str()+"\n"
      "push_counter : "+IToS(i_diff_dev::get_push_counter())+"\n"
      "total_time : "+FToS(ms)+" ms\n"
      "outsize : "+IToS(diff.size())+"\n"
      "inpsize : "+IToS(frames[i].size())+"\n"
      "g_diff_n : "+IToS(g_diff_n)+"\n"
      "g_diff_time : "+FToS(g_diff_time)+"\n"
      "g_diff_time/g_diff_n : "+FToS(g_diff_time/real(g_diff_n))+"\n"
      "ratio : "+FToS(100.0*real(diff.size())/real(frames[i].size()))+"%"
    );
    int gg=1;
    break;
  }
}

void foobarbaz(IEnvRTTI&Env)
{
  int i=0x7f800001;
  float u=*(float*)(void*)&i;
  vec2d a=vec2d(u,2);
  vec2d b=vec2d(u+1,-2);
  QapClock clock;
  clock.Start();
  auto diff=compute_diff(Env,a,b,true,0);
  clock.Stop();real ms=clock.MS();
  vec2d c=a;
  use_diff(Env,diff,a,c);
  QapAssert(qap_bin_equal(c,b));
  int gg=1;
}

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TGabobReplayFrame)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      foobarbaz(Env);
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}

#include "main2.inl"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //BlurTest();return 0;
  auto&comp_unit_man=TCompileUnitMan::get_man();
  string unit_name=comp_unit_man.arr[0]->get_filename();
  static GlobalEnv gEnv(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TStdAllocator MA;
  {
    TEnvRTTI Env;
    Env.Arr.reserve(1024);
    Env.Alloc=&MA;
    Env.OwnerEnv=&Env;
    TCompileUnitMan::reg_and_run_all(Env);
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}
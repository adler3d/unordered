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
ADDVAR(string,type,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(string,info,DEF,$,$)\
ADDVAR(vector<t_diff_cmd>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_diff_cmd
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_cmd
public:
};

#define CMDFUNC_LIST(F)\
  F(t_def_cmdfunc)F(t_new_cmdfunc)F(t_struct_cmdfunc)F(t_vector_cmdfunc)F(t_struct_short_cmdfunc)\
  F(t_int_add_cmdfunc)F(t_int_dec_cmdfunc)F(t_real_dec_cmdfunc)F(t_real_add_cmdfunc)\
  F(t_int_zero_cmdfunc)F(t_int_one_cmdfunc)F(t_real_zero_cmdfunc)F(t_real_one_cmdfunc)

class t_type_diff_tool{
public:
  static void save_string_without_size(QapIO&IO,string&s)
  {
    if(s.empty())return;
    IO.SavePOD(&s[0],s.size());
  }
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
  TType*p;
  int size;
  bool ok;
  string type;
  string name;
  string info;
  string data;
  vector<t_cmd> arr;
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
  }
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
  }
  template<int> static string&get_func_name(i_cmdfunc*func){return func->name;}
  static void conv(t_cmd&bef,t_diff_cmd&aft)
  {
    aft.cmd=get_func_name<0>(bef.cmdfunc);
    aft.type=bef.type;
    aft.name=bef.name;
    aft.info=bef.info;
    aft.arr.resize(bef.arr.size());
    for(int i=0;i<bef.arr.size();i++)
    {
      conv(bef.arr[i],aft.arr[i]);
    }
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
public:
  virtual void go(i_diff_dev&dev,TTypeStruct*p){}
  virtual void go(i_diff_dev&dev,TTypeSys*p){}
  virtual void go(i_diff_dev&dev,TTypeVector*p){}
  virtual void call(i_diff_dev&dev,TType*p)
  {
    auto*a=TTypeStruct::UberCast(p);auto*b=TTypeSys::UberCast(p);auto*c=TTypeVector::UberCast(p);
    if(a){go(dev,a);return;}
    if(b){go(dev,b);return;}
    if(c){go(dev,c);return;}
  }
  virtual void main(i_diff_dev&dev)
  {
    auto*pType=weak_dev_get_top_bef_type(dev);
    call(dev,pType);
  }
  virtual void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){QapNoWay();}
  //virtual void load(i_diff_dev&dev,QapIO&IO,t_cmd&ref){}
  template<class i_diff_dev>
  static TType*weak_dev_get_top_bef_type(i_diff_dev&dev)
  {
    return dev.top.bef.pType;
  }
  template<class i_diff_dev>
  static void weak_dev_save_cmdfunc(i_diff_dev&dev,QapIO&IO,i_cmdfunc*func)
  {
    dev.save_cmdfunc(IO,func);
  }
  static void def_save(i_diff_dev&dev,QapIO&IO,t_cmd&ref)
  {
    save_string_without_size(IO,ref.data);
    for(int i=0;i<ref.arr.size();i++)
    {
      auto&ex=ref.arr[i];
      weak_dev_save_cmdfunc(dev,IO,ex.cmdfunc);
      ex.cmdfunc->save(dev,IO,ex);
    }
  }
};

class i_diff_dev{
public:
  struct t_cmdfunc_info{
    i_cmdfunc*ptr;
    string name;
  };
public:
  struct t_item{
    TRawPtr bef;
    TRawPtr aft;
  };
  struct t_struct_patch{
    TTypeStruct*pType;
    string fields;
  };
public:
  IEnvRTTI&Env;
  t_cmd out;
  t_item top;
  vector<t_item> stack;
  vector<string> way;
  vector<t_struct_patch>*ppatches;
  vector<t_cmdfunc_info> cmdfuncs;
public:
  i_diff_dev(IEnvRTTI&Env):Env(Env){}
public:
  template<int>
  void weak_init()
  {
    #define F(CMDFUNC){static CMDFUNC tmp; auto&back=qap_add_back(cmdfuncs);back.ptr=&tmp;back.name=#CMDFUNC;tmp.name=back.name;}
    CMDFUNC_LIST(F)
    #undef F
  }
public:
  virtual bool isSave(){QapNoWay();return false;}
  virtual bool isLoad(){QapNoWay();return false;}
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
  void ret(){out.ok=true;}
public:
  TRawPtr getValue(TTypeStruct::Member&ex,TRawPtr&ptr)
  {
    TRawPtr out;
    out.pType=ex.Type.get();
    out.pValue=ex.getValue(ptr.pValue);
    return out;
  }
  void push(TTypeStruct::Member&ex)
  {
    way.push_back(ex.Name);
    stack.push_back(top);
    top.bef=getValue(ex,top.bef);
    top.aft=getValue(ex,top.aft);
  }
  void pop(TTypeStruct::Member&ex)
  {
    QapAssert(way.back()==ex.Name);
    way.pop_back();
    pop();
  }
  void push(int i)
  {
    way.push_back(IToS(i));
    push();
  }
  void pop(int i)
  {
    QapAssert(way.back()==IToS(i));
    way.pop_back();
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
    ptr=cmdfuncs[id].ptr;
  }
  char get_cmdfunc_id(i_cmdfunc*ptr)
  {
    auto arr=qap_find(cmdfuncs,[ptr](t_cmdfunc_info&ex){return ex.ptr==ptr;});
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
  string get_result()
  {
    string result;
    TQapIO IO;
    save_cmdfunc(IO,out.cmdfunc);
    out.cmdfunc->save(*this,IO,out);
    result=IO.IO.mem;
    int gg=1;
    return result;
  }
  void gen_cmds(vector<t_cmd>&cmds)
  {
    string name=way.empty()?"root":way.back();
    QapAssert(cmds.empty());
    for(int i=0;i<cmdfuncs.size();i++)
    {
      auto&ex=cmdfuncs[i].ptr;
      out.DoReset();
      ex->main(*this);
      if(!out.ok)continue;
      out.p=top.bef.pType;
      out.cmdfunc=ex;
      out.name=name;
      out.type=top.aft.pType->GetFullName();
      out.calc_size();
      qap_add_back(cmds)=std::move(out);
    }
  }
  void find_best_cmd()
  {
    vector<t_cmd> arr;
    if(0)if(top.bef.pType->GetFullName()=="QapColor"){
      int wtf=1;
    }
    gen_cmds(arr);
    int best=-1;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(best>=0&&ex.get_size()>=arr[best].get_size())continue;
      best=i;
    }
    if(best<0){out.DoReset();return;}
    out=std::move(arr[best]);
  }
public:
  void load_from_top()
  {
    string name=way.empty()?"root":way.back();
    out.cmdfunc->main(*this);
    out.p=top.bef.pType;
    out.name=name;
    out.type=top.aft.pType->GetFullName();
  }
};

class t_save_diff_dev:public i_diff_dev{
public:
  t_save_diff_dev(IEnvRTTI&Env):i_diff_dev(Env){}
public:
  bool isSave(){return true;}
  bool isLoad(){return false;}
};

class t_load_diff_dev:public i_diff_dev{
public:
  t_load_diff_dev(IEnvRTTI&Env):i_diff_dev(Env){}
public:
  bool isSave(){return false;}
  bool isLoad(){return true;}
};

#include "new_diff_cmds.inl"

template<class TYPE>
string compute_diff(IEnvRTTI&Env,TYPE&bef,TYPE&aft)
{
  TRawPtr pbef;
  TRawPtr paft;
  pbef.set(Env,bef);
  paft.set(Env,aft);
  return compute_diff_ex(Env,pbef,paft);
}

string compute_diff_ex(IEnvRTTI&Env,TRawPtr&bef,TRawPtr&aft)
{
  vector<i_diff_dev::t_struct_patch> struct_patches;
  t_save_diff_dev dev(Env);
  dev.ppatches=&struct_patches;
  dev.weak_init<0>();
  //dev.need_save=true;
  dev.top.bef=bef;
  dev.top.aft=aft;
  dev.find_best_cmd();
  auto res=dev.get_result();
  file_put_contents("info.h",dev.out.toStr(Env));
  int gg=1;
  return res;
}

template<class TYPE>
void use_diff(IEnvRTTI&Env,TYPE&bef,TYPE&aft,string&diff)
{
  TRawPtr pbef;
  TRawPtr paft;
  pbef.set(Env,bef);
  paft.set(Env,aft);
  return use_diff_ex(Env,pbef,paft,diff);
}

template<class TYPE>
void use_diff_ex(IEnvRTTI&Env,TYPE&bef,TYPE&aft,string&diff)
{
  vector<i_diff_dev::t_struct_patch> struct_patches;
  t_load_diff_dev dev(Env);
  dev.ppatches=&struct_patches;
  dev.weak_init<0>();
  //dev.need_save=true;
  dev.top.bef=bef;
  dev.top.aft=aft;
  TQapIO IO;IO.IO.mem=diff;
  dev.load_cmdfunc(IO,dev.out.cmdfunc);
  dev.load_from_top();
  int gg=1;
}

void UberInfoBox(const string&caption,const string&text);

void fast_main(IEnvRTTI&Env)
{
  auto data=file_get_contents("frames.bin");
  vector<string> frames;
  TSimpleBinaryLoader::fromStr(Env,&frames,data);
  vector<string> diffs; vector<int> ds;
  QapClock clock;
  clock.Start();
  qap_add_back(diffs)="\nseqhead:\n"+frames[0]+"\nseqdiff:\n";
  for(int i=1;i<frames.size();i++)
  {
    TGabobReplayFrame a;
    TGabobReplayFrame b;
    TGabobReplayFrame c;c=a;
    if(i)TSimpleBinaryLoader::fromStr(Env,&a,frames[i-1]);
    TSimpleBinaryLoader::fromStr(Env,&b,frames[i+0]);auto src_size=frames[i+0].size();
    auto diff=compute_diff(Env,a,b);
    use_diff(Env,a,c,diff);
    QapAssert(b==c);
    real ratio=real(diff.size()*100.0)/real(frames[i].size());
    file_put_contents("qd_bef.bin",frames[i]);
    file_put_contents("qd_aft.bin",diff);
    int gg=1;
    break;
  }
  clock.Stop();
  real ms=clock.MS();
  UberInfoBox(
    "Info(Pack)",
    "------------------------------\n"
    "date : "+cur_date_str()+"\n"
    "n : "+IToS(frames.size())+"\n"
    "total_time : "+FToS(ms)+" ms\n"
    "time/frame : "+FToS(ms/real(frames.size()))+"\n"
    "outsize : "+IToS(0)+"\n"
    "inpsize : "+IToS(data.size())+"\n"
    "ratio : "+FToS(100.0*real(0)/real(data.size()))+"%"
  );
  //auto diff=compute_diff(Env,a,b);
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
      ;
      fast_main(Env);
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}
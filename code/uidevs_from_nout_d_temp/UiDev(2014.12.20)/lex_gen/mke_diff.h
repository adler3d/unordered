#include "StdAfx.h"

#include "TSimpleBinarySaver.inl"

#include "qap_diff_types.inl"
#include "gabob_types.inl"

class i_cmdfunc;

struct t_cmd{
  i_cmdfunc*cmdfunc;
  bool ok;
  string type;
  string name;
  string info;
  string data;
  vector<t_cmd> arr;
  void init()
  {
    cmdfunc=nullptr;
    ok=false;
    type.clear();
    name.clear();
    info.clear();
    data.clear();
    arr.clear();
  }
};

class i_dev{
public:
  struct t_item{
    TRawPtr bef;
    TRawPtr aft;
  };
public:
  vector<i_cmdfunc*> funcs;
  t_cmd out;
  t_item top;
  vector<t_item> stack;
};

class i_cmdfunc{
public:
  virtual void go(i_dev&dev,TTypeStruct*p){}
  virtual void go(i_dev&dev,TTypeSys*p){}
  virtual void go(i_dev&dev,TTypeVector*p){}
  virtual void call(i_dev&dev,TType*p)
  {
    {auto*ptr=TTypeStruct::UberCast(p);if(ptr){go(dev,ptr);return;}}
    {auto*ptr=TTypeSys::UberCast(p);if(ptr){go(dev,ptr);return;}}
    {auto*ptr=TTypeVector::UberCast(p);if(ptr){go(dev,ptr);return;}}
  }
  virtual void main(i_dev&dev)
  {
    call(dev,dev.bef.pType);
  }
};

class t_dev:public i_dev{
public:
  void init()
  {
    {static t_def_cmd tmp; funcs.push_back(&tmp);}
  }
  void run()
  {
    string name=out.name;
    vector<t_out> arr;
    for(int i=0;i<funcs.size();i++)
    {
      out.reset();
      funcs[i]->call(*this);
      qap_add_back(arr)=std::move(out);
    }
    
    out.type=bef.pType->GetFullName();
    out.name=name;
  }
  void ret(){out.ok=true;}
};

class t_def_cmdfunc:public i_cmdfunc{
public:
  void call(i_dev&dev,TType*ptr)
  {
    if(dev.isSave())
    {
      if(dev.toBin(dev.top.bef)!=dev.toBin(dev.top.aft))return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      dev.ret();
    }
  }
};

class t_int_add_cmdfunc:public i_cmdfunc{
public:
  void go(i_dev&dev,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef+1)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=bef+1;
      dev.ret();
    }
  }
};

vec2d a=vec2d(1,2);
vec2d b=vec2d(1,4);

void compute_diff(IEnvRTTI&Env,TRawPtr&bef,TRawPtr&aft)
{
  t_dev dev;
  dev.top.bef=bef;
  dev.top.aft=aft;
  dev.run();
}

auto diff=compute_diff(Env,a,b);


class t_diff_builder:public IVisitorRTTI,public t_diff_sys,public t_type_diff_tool{
public:
  struct t_item{
    TRawPtr from;
    TRawPtr to;
  };
  struct t_struct_patch{
    TTypeStruct*pType;
    string fields;
  };
public:
  IEnvRTTI&Env;
  t_cmd out;
  string out_msg;
  string binout;
  vector<string> way;
  vector<t_item> stack;
  vector<t_struct_patch>*ppatches;
  int depth;
  t_item top;
public:
  t_diff_builder(IEnvRTTI&Env):Env(Env)
  {}
public:
  void init_out(TType*p){out.type=p->GetFullName();out.cmd=out_msg;out.data=binout;out.name=way.empty()?"root":way.back();}
  void say_one(TType*p){out_msg="1";init_out(p);}
public:
  void Do(TTypeStruct*p)
  {
    QapDebugMsg("no way");
  }
  t_struct_def{
    (TTypeStruct*p)
    {
      //save
      if(toBin(top.bef)!=toBin(top.aft))return;
      ret();
      //load
      ret();
    }
  }
  t_struct_patch{
    (TTypeStruct*p)
    {
      if(p->SubType)return;
      auto&arr=p->Members;
      //save
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*pType=ex.Type.get()
        push(ex);
        pType->Use(*this); тут надо попробовать сжать не одним способом а всеми способам, а затем выбрать лучший.
        тоесть просто вызвать как сейчас не достаточно. надо сделать это несколько раз. сделать это внутри системной функции.
        pop(ex);
        qap_add_back(out.arr)=std::move(out);
      }
      //load
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*pType=ex.Type.get()
        push(ex);
        pType->Use(*this);
        pop(ex);
      }
    }
  }
      out.arr
      {
        if(use_patch==best)
        {
          out=t_cmd();
          out.arr=std::move(members);
          binout=fi;
          say_patch(p);
          binout=fi+join(bins,"");
          return;
        }
        if(use_xpatch==best)
        {
          auto patch_id=find_patch(p,fi);
          if(patch_id<0){
            patch_id=patches.size();
            auto&back=qap_add_back(patches);
            back.pType=p;
            back.fields=fi;
          }
          vector<t_cmd> m;
          string full_bin;
          for(int i=0;i<fi.size();i++)
          {
            if(fi[i]=='d')continue;
            full_bin+=bins[i];
            qap_add_back(m)=std::move(members[i]);
          }
          out=t_cmd();
          binout="int("+IToS(patch_id)+") but saved as int("+IToS(patch_id_to_bin(p,patch_id)[0])+") also: "+fi;
          out.arr=std::move(m);
          say_xpatch(p);
          binout=patch_id_to_bin(p,patch_id)+full_bin;
          return;
        }
      }
    }
  }
  t_real_one{
    (TTypeSys*p)
    {
      if(!is_real(p))return;
      auto&aft=get_real(top.aft);
      //save
      if(aft!=1.0)return;
      {empty();}
      //load
      {aft=1.0;}
    }
  }
  t_int_add{
    (TTypeSys*p)
    {
      if(!is_int(p))return;
      auto&bef=get_int(top.bef);
      auto&aft=get_int(top.aft);
      //save
      if(aft!=bef+1)return;
      {empty();}
      //load
      {aft=bef+1;}
    }
  }
  t_int_num{
    (TTypeSys*p)
    {
      if(!is_int(p))return;
      auto&aft=get_int(top.aft);
      char tmp=aft;
      //save
      if(aft<0x80)return;
      info="int("+IToS(char(aft))+")";
      IO.save(tmp);
      //load
      IO.load(tmp);
      aft=tmp;
    }
  }
  void Do(TTypeSys*p)
  {
    bool eq=p->BinIO->IsSame(top.from.pValue,top.to.pValue);
    if(eq)
    {
      out=t_cmd();
      binout.clear();
      say_def(p);
      return;
    }
    if(is_real(p))
    {
      auto&bef=*(real*)top.from.pValue;
      auto&aft=*(real*)top.to.pValue;
      if(aft==1.0)
      {
        out=t_cmd();
        binout.clear();
        say_one(p);
        return;
      }
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

void UberInfoBox(const string&caption,const string&text);

template<class TYPE>
string build_diff(IEnvRTTI&Env,TYPE&from,TYPE&to)
{
  TRawPtr pFrom(Env,from);
  TRawPtr pTo(Env,to);
  vector<t_diff_builder::t_struct_patch> patches;
  t_diff_builder V(Env);V.ppatches=&patches;V.depth=0;
  V.top.bef.set(Env,from);
  V.top.aft.set(Env,to);
  QapClock clock;
  clock.Start();
  V.top.bef.pType->Use(V);
  clock.Stop();
  auto ms=clock.MS();
  auto raw=TSimpleBinarySaver::toStr(Env,&to);
  auto binout=V.gen_out();
  int gg=1;
  return binout;
}
#include "StdAfx.h"
//time = 9.54 ms.

#include "TSimpleBinarySaver.inl"

#include "qap_diff_types.inl"
#include "gabob_types.inl"

class t_diff_fields_info{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_fields_info)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,type,DEF,$,$)\
ADDVAR(string,fields,DEF,$,$)\
ADDEND()
//=====+>>>>>t_diff_fields_info
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_fields_info
public:
};

class t_diff_fields_info_ex{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_fields_info_ex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,type,DEF,$,$)\
ADDVAR(string,fields,DEF,$,$)\
ADDVAR(int,n,DEF,$,$)\
ADDEND()
//=====+>>>>>t_diff_fields_info_ex
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_fields_info_ex
public:
};

class t_diff_result{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_result)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_diff_fields_info>,arr,DEF,$,$)\
ADDVAR(t_diff_sys::t_cmd,root,DEF,$,$)\
ADDEND()
//=====+>>>>>t_diff_result
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_result
public:
};

class t_diff_result_ex{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_result_ex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_diff_fields_info_ex>,arr,DEF,$,$)\
ADDVAR(t_diff_sys::t_cmd,root,DEF,$,$)\
ADDEND()
//=====+>>>>>t_diff_result_ex
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_result_ex
public:
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
};

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
  void clear()
  {
    out_msg.clear();
    binout.clear();
    out=t_cmd();
  }
  string get_diff_log()
  {
    t_diff_result res;
    res.arr=sys_get_raw_header();
    res.root=out;
    auto t=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(res));
    t=StrReplace(t,"t_diff_sys::","");
    t=t.substr(t.find("\nTHardPtr<TType>(Sys$$<t_diff_result>::GetRTTI())\n"));
    return t;
  }
  //template<int>
  //string get_diff_log_ex()
  //{
  //  t_diff_result_ex res;
  //  t_diff_apply V(Env);
  //  V.IO.IO.mem=gen_out();
  //}
  vector<t_diff_fields_info> get_raw_header()
  {
    QapDebugMsg("no way");
    return vector<t_diff_fields_info>();
  }
  vector<t_diff_fields_info> sys_get_raw_header()
  {
    auto&patches=*ppatches;
    vector<t_diff_fields_info> arr;
    arr.resize(patches.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=patches[i];
      auto&out=arr[i];
      out.type=ex.pType->GetFullName();
      out.fields=ex.fields;
    }
    return arr;
  }
  string get_short_header()
  {
    auto arr=sys_get_raw_header();
    vector<string> types;
    vector<string> fields;
    vector<int> id2tid; id2tid.resize(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto t=qap_find_str(types,arr[i].type);
      if(t.empty())
      {
        qap_add_back(t)=types.size();
        qap_add_back(types)=arr[i].type;
        QapAssert(types.size()<0x80);
      }
      id2tid[i]=t[0];
      qap_add_back(fields)=CToS(t[0])+"."+arr[i].fields;
    }
    string typelist=join(types,"\n");
    TQapIO IO; IO.save(typelist);
    char nextline='\n';
    IO.save(nextline);
    string tmp=join(fields,"\n");
    IO.save(tmp);
    return IO.IO.mem;
  }
  string get_header()
  {
    auto arr=get_raw_header();
    return TSimpleBinarySaver::toStr(Env,&arr);
  }
  string gen_out()
  {
    return get_short_header()+get_binout();
  }
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
    top.from=getValue(ex,top.from);
    top.to=getValue(ex,top.to);
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
  void init_out(TType*p){out.type=p->GetFullName();out.cmd=out_msg;out.data=binout;out.name=way.empty()?"root":way.back();}
  void say_def(TType*p){out_msg="def";init_out(p);}
  void say_new(TType*p){out_msg="new";init_out(p);}
  void say_inc(TType*p){out_msg="+1";init_out(p);}
  void say_dec(TType*p){out_msg="-1";init_out(p);}
  void say_zero(TType*p){out_msg="0";init_out(p);}
  void say_one(TType*p){out_msg="1";init_out(p);}
  void say_patch(TType*p){out_msg="patch";init_out(p);}
  void say_xpatch(TType*p){out_msg="xpatch";init_out(p);}
  void say_resize(TType*p){out_msg="resize";init_out(p);}
  void say_update(TType*p){out_msg="update";init_out(p);}
  void say_number(TType*p){out_msg="#num";init_out(p);}
  void say_less_n(TType*p){out_msg="less_n";init_out(p);}
  int find_patch(TTypeStruct*p,const string&fi)
  {
    auto&patches=*ppatches;
    for(int i=0;i<patches.size();i++)
    {
      auto&ex=patches[i];
      if(ex.pType!=p)continue;
      if(ex.fields!=fi)continue;
      return i;
    }
    return -1;
  }
public:
  string get_binout()
  {
    auto tag=out_msg.substr(0,1);
    return tag+binout;
    return "\n["+tag+":"+IToS(binout.size())+"]\n"+binout+"\n[/"+tag+"]\n";
  }
  string patch_id_to_bin(TTypeStruct*p,int patch_id)
  {
    int n=0;
    auto&patches=*ppatches;
    for(int i=0;i<patches.size();i++){
      if(i==patch_id)break;
      if(patches[i].pType!=p)continue;
      n++;QapAssert(n<256);
    }
    return CToS(n); 
  }
public:
  template<class TYPE>
  static TYPE&qap_min_value(vector<TYPE>&arr){int best=0;for(int i=1;i<arr.size();i++){if(arr[best]>arr[i])best=i;}return arr[best];}
  template<class TYPE>
  static TYPE&qap_max_value(vector<TYPE>&arr){int best=0;for(int i=1;i<arr.size();i++){if(arr[best]<arr[i])best=i;}return arr[best];}
  template<class TYPE>
  static int qap_min_value_id(vector<TYPE>&arr){if(arr.empty())return -1;int best=0;for(int i=1;i<arr.size();i++){if(arr[best]>arr[i])best=i;}return best;}
  template<class TYPE>
  static int qap_max_value_id(vector<TYPE>&arr){if(arr.empty())return -1;int best=0;for(int i=1;i<arr.size();i++){if(arr[best]<arr[i])best=i;}return best;}
public:
  void Do(TTypeStruct*p)
  {
    auto&patches=*ppatches;
    if(p->GetFullName()=="TGabobPhys")
    {
      auto&members=p->Members;
      QapAssert(members.size()==2);
      QapAssert(is_same_type(members[0],members[1]));
      QapAssert(is_vec2d(members[0]));
      auto&bef=*(TGabobPhys*)top.from.pValue;
      auto&aft=*(TGabobPhys*)top.to.pValue;
      auto np=bef.pos+bef.v;
      bool ca=TSimpleBinarySaver::toStr(Env,&np)==TSimpleBinarySaver::toStr(Env,&aft.pos);
      bool cb=aft.v==bef.v;
      if(ca&&cb)
      {
        out=t_cmd();
        binout.clear();
        say_inc(p);
        return;
      }
      int gg=1;
    }
    if(p->GetFullName()=="TGabobParticle")
    {
      auto&members=p->Members;
      QapAssert(members.size()==3);
      QapAssert(is_same_type(members[0],members[1]));
      QapAssert(is_vec2d(members[0]));
      QapAssert(is_real(members[2]));
      auto&bef=*(TGabobParticle*)top.from.pValue;
      auto&aft=*(TGabobParticle*)top.to.pValue;
      auto np=bef.pos+bef.v;
      bool ca=TSimpleBinarySaver::toStr(Env,&np)==TSimpleBinarySaver::toStr(Env,&aft.pos);
      bool cb=aft.v==bef.v;
      bool cd=bef.t-1.0==aft.t;
      if(ca&&cb&&cd)
      {
        out=t_cmd();
        binout.clear();
        say_inc(p);
        return;
      }
      int gg=1;
    }
    ;
    int n=p->Members.size();
    int nd=0; int bins_total=0;
    string fi;
    {
      //auto&patch=*pout->cmd.build<t_struct_patch_cmd>(Env);
      QapAssert(!p->SubType);
      auto&arr=p->Members;
      vector<t_cmd> members;
      vector<string> bins;
      members.resize(arr.size());
      bins.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        push(ex);
        binout.clear();
        ex.Type->Use(*this);
        bins[i]=binout;
        pop(ex);
        members[i]=std::move(out);
        if(out_msg=="def"){n--;}else{nd++;bins_total+=binout.size();}
        fi+=out_msg[0];
      }
      if(!n)
      {
        out=t_cmd();
        binout.clear();
        say_def(p);
        return;
      }
      int use_new=TSimpleBinarySize::toSizeEx(top.to.pType,top.to.pValue);
      int use_xpatch=1+bins_total;
      int use_patch=fi.size()+bins_total;
      vector<int> tmp_arr={use_new,use_xpatch,use_patch};
      auto best_id=qap_min_value_id(tmp_arr);
      auto&best=tmp_arr[best_id];
      if(use_new==best)
      {
        out=t_cmd();
        binout=TSimpleBinarySaver::toStrEx(top.to.pType,top.to.pValue);
        say_new(p);
        return;
      }
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
    int wtf=1;
    QapDebugMsg("no way");
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
      if(bef+1.0==aft)
      {
        out=t_cmd();
        binout.clear();
        say_inc(p);
        return;
      }
      if(bef-1.0==aft)
      {
        out=t_cmd();
        binout.clear();
        say_dec(p);
        return;
      }
      if(aft==0.0)
      {
        out=t_cmd();
        binout.clear();
        say_zero(p);
        return;
      }
      if(aft==1.0)
      {
        out=t_cmd();
        binout.clear();
        say_one(p);
        return;
      }
    }
    if(is_int(p))
    {
      //QapAssert(p->GetFullName()=="int");
      auto&bef=*(int*)top.from.pValue;
      auto&aft=*(int*)top.to.pValue;
      if(aft==0)
      {
        out=t_cmd();
        binout.clear();
        say_zero(p);
        return;
      }
      if(aft==1)
      {
        out=t_cmd();
        binout.clear();
        say_one(p);
        return;
      }
      if(bef+1==aft)
      {
        out=t_cmd();
        binout.clear();
        say_inc(p);
        return;
      }
      if(bef-1==aft)
      {
        out=t_cmd();
        binout.clear();
        say_dec(p);
        return;
      }
      if(aft<0x80)
      {
        out=t_cmd();
        binout="int("+IToS(char(aft))+")";
        say_number(p);
        binout=CToS(char(aft));
        return;
      }
      int gg=1;
    }
    if(!eq)
    {
      out=t_cmd();
      binout=TSimpleBinarySaver::toStrEx(top.to.pType,top.to.pValue);
      say_new(p);
      return;
    }
  }
  void Do(TTypeVector*p)
  {
    auto fc=p->VecAPI->GetCount(top.from.pValue);
    auto tc=p->VecAPI->GetCount(top.to.pValue);
    auto eq=fc==tc;
    auto*pElemType=p->ElementType.get();
    auto get_diff_size=[&](int id_a,int id_b)
    {
      t_diff_builder V(Env);
      int patches_size=ppatches->size();
      V.ppatches=ppatches;
      V.depth=depth++;
      V.top.from.pType=pElemType;
      V.top.from.pValue=p->VecAPI->GetItem(top.from.pValue,id_a);
      V.top.to.pType=pElemType;
      V.top.to.pValue=p->VecAPI->GetItem(top.to.pValue,id_b);
      pElemType->Use(V);
      ppatches->resize(patches_size);
      return V.get_binout().size();
    };
    if(!fc)if(tc>1)
    {
      if(!depth)
      {
        int gg=1;
      }
      auto*pfirst=p->VecAPI->GetItem(top.to.pValue,0);
      auto first=TSimpleBinarySaver::toStrEx(pElemType,pfirst);
      vector<t_cmd> buff;
      vector<string> bins;bins.resize(tc-1); int use_patch=0; int n=tc-1;
      for(int i=1;i<tc;i++)
      {
        auto*pt0=p->VecAPI->GetItem(top.to.pValue,i-1);
        auto*pt1=p->VecAPI->GetItem(top.to.pValue,i-0);
        push(i);
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pt0;
        top.to.pValue=pt1;
        binout.clear();
        pElemType->Use(*this);
        bins[i-1]=get_binout();use_patch+=bins[i-1].size();
        pop(i);
        qap_add_back(buff)=std::move(out);
        if(out_msg=="def"){n--;}
      }
      if(!n)
      {
        QapNoWay();
        return;
      }
      out=t_cmd();
      binout="int("+IToS(tc)+");"+first;
      out.arr=buff;
      say_update(p);out_msg="init";
      binout=TSimpleBinarySaver::toStr(Env,&tc)+first+join(bins,"");
      int gg=1;
      return;
    }
    if(tc&&fc)for(;;)
    {
      if(tc!=fc)break;
      if(fc<2)break;
      auto a=get_diff_size(0,0);
      auto b=get_diff_size(1,0);
      if(a<=b)break;
      //old item is removed from the beginning of the array, and a new element is added at the end.
      int n=fc;
      vector<t_cmd> buff;
      vector<string> bins;bins.resize(fc); int use_patch=0;
      for(int i=0;i<fc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,std::min(i+1,fc-1));
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push(i);
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        binout.clear();
        pElemType->Use(*this);
        bins[i]=get_binout();use_patch+=bins[i].size();
        pop(i);
        qap_add_back(buff)=std::move(out);
        if(out_msg=="def"){n--;}
      }
      int use_new=TSimpleBinarySize::toSizeEx(top.to.pType,top.to.pValue);
      int use_best=std::min<int>(use_new,use_patch);
      if(use_new==use_best)
      {
        out=t_cmd();
        binout=TSimpleBinarySaver::toStrEx(top.to.pType,top.to.pValue);
        say_new(p);
        return;
      }
      if(!n)
      {
        out=t_cmd();
        binout.clear();
        say_def(p);
        return;
      }
      out=t_cmd();
      binout.clear();
      out.arr=buff;
      say_update(p);
      binout=join(bins,"");
      int gg=1;
      return;
    }
    if(eq)
    {
      int n=fc;
      vector<t_cmd> buff;
      vector<string> bins;bins.resize(fc); int use_patch=0;
      for(int i=0;i<fc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,i);
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push(i);
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        binout.clear();
        pElemType->Use(*this);
        bins[i]=get_binout();use_patch+=bins[i].size();
        pop(i);
        qap_add_back(buff)=std::move(out);
        if(out_msg=="def"){n--;}
      }
      int use_new=TSimpleBinarySize::toSizeEx(top.to.pType,top.to.pValue);
      int use_best=std::min<int>(use_new,use_patch);
      if(use_new==use_best)
      {
        out=t_cmd();
        binout=TSimpleBinarySaver::toStrEx(top.to.pType,top.to.pValue);
        say_new(p);
        return;
      }
      if(!n)
      {
        out=t_cmd();
        binout.clear();
        say_def(p);
        return;
      }
      out=t_cmd();
      out.arr=std::move(buff);
      binout.clear();
      say_patch(p);
      binout=join(bins,"");
      int gg=1;
      return;
    }
    if(tc&&tc+1==fc)for(;;)
    {
      bool found=false; int id=-1;
      for(int i=0;i<tc;i++)
      {
        auto a=get_diff_size(i+0,i);
        auto b=get_diff_size(i+1,i);
        if(a<b)continue;
        id=i;
        found=true;
        break;
      }
      if(!found)break;
      //pop_front
      int n=tc;
      vector<t_cmd> buff;
      vector<string> bins;
      bins.resize(tc);
      for(int i=0;i<tc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,i<id?i:i+1);
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push(i);
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        binout.clear();
        pElemType->Use(*this);
        bins[i]=get_binout();
        pop(i);
        qap_add_back(buff)=std::move(out);
        if(out_msg=="def")n--;
      }
      if(!n)
      {
        QapDebugMsg("nice!");
        out=t_cmd();
        binout.clear();
        say_def(p);
        return;
      }
      out=t_cmd();
      out.arr=std::move(buff);
      if(id>=0x80){QapDebugMsg("way not tested");}
      string prefix=id<0x80?CToS(char(id)):TSimpleBinarySaver::toStr(Env,&id);
      binout=prefix;
      say_dec(p);
      binout=prefix+join(bins,"");
      int gg=1;
      return;
    }
    if(tc&&tc<fc)for(;;)
    {
      int need=fc-tc;
      int found=0; int offset=0;
      vector<int> skip;
      for(int i=0;i<tc;i++)
      {
        auto a=get_diff_size(i+0+offset,i);
        auto b=get_diff_size(i+1+offset,i);
        if(a<b)continue;
        offset++;
        skip.push_back(i);
        need--;
        if(!need)break;
      }
      if(need>0)if(need!=fc-tc)
      {
        for(int i=0;i<need;i++)skip.push_back(tc+i);
        need=0;
      }
      if(need>0)break;
      //pop_front n
      offset=0;
      int n=tc;
      vector<t_cmd> buff;
      vector<string> bins;
      bins.resize(tc);
      for(int i=0;i<tc;i++)
      {
        for(int j=i;offset!=skip.size()&&skip[offset]==j;j++)offset++;
        auto*pf=p->VecAPI->GetItem(top.from.pValue,i+offset);
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push(i);
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        binout.clear();
        pElemType->Use(*this);
        bins[i]=get_binout();
        pop(i);
        qap_add_back(buff)=std::move(out);
        if(out_msg=="def")n--;
      }
      if(!n)
      {
        QapDebugMsg("nice!"); // TODO: it is wrong
        out=t_cmd();
        binout.clear();
        say_def(p);
        return;
      }
      out=t_cmd();
      out.arr=std::move(buff);
      string prefix;{vector<string> a;a.resize(skip.size());for(int i=0;i<skip.size();i++)a[i]=IToS(skip[i]);prefix=join(a,",");}
      binout=prefix;
      say_less_n(p);
      prefix=TSimpleBinarySaver::toStr(Env,&skip);
      binout=prefix+join(bins,"");
      int gg=1;
      return;
    }
    if(fc&&tc&&!eq)
    {
      int n=tc;
      vector<t_cmd> buff;
      vector<string> bins;
      bins.resize(tc);
      for(int i=0;i<tc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,std::min<int>(fc-1,i));
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push(i);
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        binout.clear();
        pElemType->Use(*this);
        bins[i]=get_binout();
        pop(i);
        qap_add_back(buff)=std::move(out);
        if(out_msg=="def")n--;
      }
      if(!n)
      {
        QapDebugMsg("nice!");
        out=t_cmd();
        binout.clear();
        say_def(p);
        return;
      }
      out=t_cmd();
      out.arr=std::move(buff);
      binout="int("+IToS(tc)+") also it is "+string(tc-fc>0?"+":"")+IToS(tc-fc);
      say_resize(p);
      binout=TSimpleBinarySaver::toStr(Env,&tc)+join(bins,"");
      int gg=1;
      return;
    }
    if(!eq)
    {
      out=t_cmd();
      binout=TSimpleBinarySaver::toStrEx(top.to.pType,top.to.pValue);
      say_new(p);
      return;
    }
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
  V.top.from=pFrom;
  V.top.to=pTo;
  QapClock clock;clock.Start();
  pFrom.pType->Use(V);
  clock.Stop();
  auto ms=clock.MS();
  //UberInfoBox("info","time = "+FToS(ms)+"ms");
  auto raw=TSimpleBinarySaver::toStr(Env,&to);
  auto binout=V.gen_out();
  auto ratio=100.0*binout.size()/real(raw.size());
  bool need_proto=false;
  if(need_proto)
  {
    auto sh=V.get_short_header();
    file_put_contents("packedheader.bin",sh);
    auto fproto=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(from));
    auto tproto=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(to));
    auto out=V.get_diff_log();
    file_put_contents("log.h",out);
    file_put_contents("binout.bin",binout);
    file_put_contents("bef_proto.h",fproto);
    file_put_contents("aft_proto.h",tproto);
    int gg=1;
  }
  int gg=1;
  return binout;
}

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
    if(out_msg=="+1")if(p->GetFullName()=="TGabobPhys")
    {
      auto&members=p->Members;
      QapAssert(members.size()==2);
      QapAssert(is_same_type(members[0],members[1]));
      QapAssert(is_vec2d(members[0]));
      auto&bef=*(TGabobPhys*)top.from.pValue;
      auto&aft=*(TGabobPhys*)top.to.pValue;
      auto np=bef.pos+bef.v;
      aft.pos=np;
      int gg=1;
      return;
    }
    if(out_msg=="+1")if(p->GetFullName()=="TGabobParticle")
    {
      auto&members=p->Members;
      QapAssert(members.size()==3);
      QapAssert(is_same_type(members[0],members[1]));
      QapAssert(is_vec2d(members[0]));
      QapAssert(is_real(members[2]));
      auto&bef=*(TGabobParticle*)top.from.pValue;
      auto&aft=*(TGabobParticle*)top.to.pValue;
      auto np=bef.pos+bef.v;
      aft.pos=np;
      aft.t=bef.t-1.0;
      int gg=1;
      return;
    }
    QapAssert(!p->SubType);
    if(out_msg=="xpatch")
    {
      auto&patch=load_patch_id(p);
      auto&arr=patch.fields;
      for(int i=0;i<arr.size();i++)
      {
        auto&m=arr[i];
        if(m=='d')continue;
        set_outmsg(m);
        auto&ex=p->Members[i];
        push();
        top.from=getValue(ex,top.from);
        top.to=getValue(ex,top.to);
        auto*ptr=ex.Type.get();
        ptr->Use(*this);
        pop();
      }
      int gg=1;
      return;
    }
    if(out_msg=="patch")
    {
      auto&arr=p->Members;
      for(int i=0;i<arr.size();i++)
      {
        loadmsg();
        auto&ex=arr[i];
        push();
        top.from=getValue(ex,top.from);
        top.to=getValue(ex,top.to);
        auto*ptr=ex.Type.get();
        ptr->Use(*this);
        pop();
      }
      int gg=1;
      return;
    }
    if(out_msg=="new")
    {
      int gg=1;
      TSimpleBinaryLoader::fromIOEx(Env,top.to,IO);
      return;
    }
    if(out_msg=="def")
    {
      int gg=1;
      return;
    }
    //IO.LoadPOD(&c,1);
  }
  void Do(TTypeSys*p)
  {
    if(out_msg=="#num")
    {
      char c;
      IO.load(c);
      QapAssert(c<0x80);
      QapAssert(is_int(p));
      auto&aft=*(int*)top.to.pValue;
      aft=c;
      return;
    }
    if(out_msg=="0")
    {
      if(is_int(p))
      {
        auto&aft=*(int*)top.to.pValue;
        aft=0;
        return;
      }
      if(is_real(p))
      {
        auto&aft=*(real*)top.to.pValue;
        aft=0.0;
        return;
      }
      QapDebugMsg("no way");
      return;
    }
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
    if(out_msg=="+1")
    {
      if(is_real(p))
      {
        auto&bef=*(real*)top.from.pValue;
        auto&aft=*(real*)top.to.pValue;
        aft=bef+1.0;
        return;
      }
      if(is_int(p))
      {
        auto&bef=*(int*)top.from.pValue;
        auto&aft=*(int*)top.to.pValue;
        aft=bef+1;
        return;
      }
      QapDebugMsg("no way");
      return;
    }
    if(out_msg=="-1")
    {
      if(is_real(p))
      {
        auto&bef=*(real*)top.from.pValue;
        auto&aft=*(real*)top.to.pValue;
        aft=bef-1.0;
        return;
      }
      if(is_int(p))
      {
        auto&bef=*(int*)top.from.pValue;
        auto&aft=*(int*)top.to.pValue;
        aft=bef-1;
        return;
      }
      QapDebugMsg("no way");
      return;
    }
    if(out_msg=="def")
    {
      int gg=1;
      return;
    }
    if(out_msg=="new")
    {
      p->BinIO->Load(IO,top.to.pValue);
      return;
    }
  }
  void Do(TTypeVector*p)
  {
    if(out_msg=="def")
    {
      int gg=1;
      return;
    }
    if(out_msg=="new")
    {
      TSimpleBinaryLoader::fromIOEx(Env,top.to,IO);
      return;
    }
    if(out_msg=="less_n")
    {
      auto fc=p->VecAPI->GetCount(top.from.pValue);
      auto tc=p->VecAPI->GetCount(top.to.pValue);
      vector<int> skip;
      IO.load(skip);
      QapAssert(fc>skip.size());
      tc=fc-skip.size();
      p->VecAPI->SetCount(top.to.pValue,tc);
      int offset=0;
      auto*pElemType=p->ElementType.get();
      for(int i=0;i<tc;i++)
      {
        for(int j=i;offset!=skip.size()&&skip[offset]==j;j++)offset++;
        auto*pf=p->VecAPI->GetItem(top.from.pValue,i+offset);
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push();
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        loadmsg();
        auto bef=TSimpleBinarySaver::toStrEx(pElemType,pf);
        qap_simple_clone_unsafe(pElemType,pt,pf);
        auto aft=TSimpleBinarySaver::toStrEx(pElemType,pf);
        pElemType->Use(*this);
        pop();
      }
      int gg=1;
      return;
    }
    if(out_msg=="update")
    {
      auto fc=p->VecAPI->GetCount(top.from.pValue);
      auto tc=p->VecAPI->GetCount(top.to.pValue);
      QapAssert(fc==tc);
      auto*pElemType=p->ElementType.get();
      for(int i=0;i<fc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,std::min(i+1,fc-1));
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push();
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        loadmsg();
        auto bef=TSimpleBinarySaver::toStrEx(pElemType,pf);
        qap_simple_clone_unsafe(pElemType,pt,pf);
        auto aft=TSimpleBinarySaver::toStrEx(pElemType,pf);
        pElemType->Use(*this);
        pop();
      }
      return;
    }
    if(out_msg=="patch")
    {
      auto fc=p->VecAPI->GetCount(top.from.pValue);
      auto tc=p->VecAPI->GetCount(top.to.pValue);
      QapAssert(fc==tc);
      auto*pElemType=p->ElementType.get();
      for(int i=0;i<fc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,i);
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push();
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        loadmsg();
        pElemType->Use(*this);
        pop();
      }
      return;
    }
    if(out_msg=="-1")
    {
      {
        auto fc=p->VecAPI->GetCount(top.from.pValue);
        auto tc=p->VecAPI->GetCount(top.to.pValue);
        QapAssert(fc==tc);
        QapAssert(fc>0);
        p->VecAPI->SetCount(top.to.pValue,fc-1);
      }
      int id=0;
      {
        char c;
        IO.load(c);
        id=c;
        if(c>=0x80)
        {
          QapDebugMsg("way no tested");
          IO.IO.pos--;IO.load(id);
        }
      }
      auto fc=p->VecAPI->GetCount(top.from.pValue);
      auto tc=p->VecAPI->GetCount(top.to.pValue);
      auto*pElemType=p->ElementType.get();
      for(int i=0;i<tc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,i<id?i:i+1);
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push();
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        loadmsg();
        auto bef=TSimpleBinarySaver::toStrEx(pElemType,pf);
        qap_simple_clone_unsafe(pElemType,pt,pf);
        auto aft=TSimpleBinarySaver::toStrEx(pElemType,pf);
        QapAssert(bef==aft);
        pElemType->Use(*this);
        pop();
      }
      return;
    }
    if(out_msg=="resize")
    {
      {
        int count=0;
        IO.load(count);
        auto fc=p->VecAPI->GetCount(top.from.pValue);
        auto tc=p->VecAPI->GetCount(top.to.pValue);
        QapAssert(fc==tc);
        p->VecAPI->SetCount(top.to.pValue,count);
      }
      auto fc=p->VecAPI->GetCount(top.from.pValue);
      auto tc=p->VecAPI->GetCount(top.to.pValue);
      auto*pElemType=p->ElementType.get();
      for(int i=0;i<tc;i++)
      {
        auto*pf=p->VecAPI->GetItem(top.from.pValue,std::min<int>(fc-1,i));
        auto*pt=p->VecAPI->GetItem(top.to.pValue,i);
        push();
        top.from.pType=pElemType;
        top.to.pType=pElemType;
        top.from.pValue=pf;
        top.to.pValue=pt;
        loadmsg();
        auto bef=TSimpleBinarySaver::toStrEx(pElemType,pf);
        qap_simple_clone_unsafe(pElemType,pt,pf);
        auto aft=TSimpleBinarySaver::toStrEx(pElemType,pf);
        QapAssert(bef==aft);
        pElemType->Use(*this);
        pop();
      }
      return;
    }
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

class t_test_class{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_test_class)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(vec2i,v,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDEND()
//=====+>>>>>t_test_class
#include "QapGenStruct.inl"
//<<<<<+=====t_test_class
public:
};

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
      auto np_fc=file_get_contents("need_pack.txt");
      auto pack_start_frame=file_get_contents("pack_start_frame.txt").empty()?1:SToI(file_get_contents("pack_start_frame.txt"));
      bool need_pack=file_get_contents("need_pack.txt")=="true"||file_get_contents("need_pack.txt")=="1";
      bool need_full_debug=file_get_contents("need_full_debug.txt")=="true"||file_get_contents("need_full_debug.txt")=="1";
      if(need_pack)
      {
        auto data=file_get_contents("frames.bin");
        vector<string> frames;
        TSimpleBinaryLoader::fromStr(Env,&frames,data);
        vector<string> diffs; vector<int> ds;
        vector<t_diff_builder::t_struct_patch> patches;
        t_diff_builder V(Env);V.ppatches=&patches;V.depth=0;
        QapClock clock;
        clock.Start();
        qap_add_back(diffs)="\nseqhead:\n"+frames[0]+"\nseqdiff:\n";
        for(int i=pack_start_frame;i<frames.size();i++)//105
        {
          TGabobReplayFrame a;
          TGabobReplayFrame b;
          TSimpleBinaryLoader::fromStr(Env,&a,frames[i-1]);
          TSimpleBinaryLoader::fromStr(Env,&b,frames[i+0]);
          if(need_full_debug)
          {
            TGabobReplayFrame c;
            auto the_diff=build_diff(Env,a,b);
            c=a;
            apply_diff(Env,the_diff,a,c);
            QapAssert(b==c);
          }
          V.top.from.set(Env,a);
          V.top.to.set(Env,b);
          V.top.from.pType->Use(V);
          qap_add_back(diffs)=V.get_binout(); ds.push_back(diffs.back().size());
          V.clear();
        }
        clock.Stop();
        int min_ds_id=t_diff_builder::qap_min_value_id(ds); auto&min_ds=t_diff_builder::qap_min_value(ds);
        int max_ds_id=t_diff_builder::qap_max_value_id(ds); auto&max_ds=t_diff_builder::qap_max_value(ds);
        real ms=clock.MS();
        auto outfiledata=V.get_short_header()+TSimpleBinarySaver::toStr(Env,&diffs);
        file_put_contents("packedframes.bin",outfiledata);
        UberInfoBox(
          "Info(Pack)",
          "------------------------------\n"
          "date : "+cur_date_str()+"\n"
          "n : "+IToS(frames.size())+"\n"
          "total_time : "+FToS(ms)+" ms\n"
          "time/frame : "+FToS(ms/real(frames.size()))+"\n"
          "outsize : "+IToS(outfiledata.size())+"\n"
          "inpsize : "+IToS(data.size())+"\n"
          "ratio : "+FToS(100.0*real(outfiledata.size())/real(data.size()))+"%"
        );
      }
      ;
      {
        vector<string> real_frames;
        TSimpleBinaryLoader::fromStr(Env,&real_frames,file_get_contents("frames.bin"));
        auto packed_data=file_get_contents("packedframes.bin");
        t_diff_apply V(Env);
        V.IO.IO.mem=packed_data;
        V.load_short_header();
        vector<string> diffs;
        TSimpleBinaryLoader::fromIOEx(Env,TRawPtr(Env,diffs),V.IO);
        vector<string> frames;
        frames.resize(diffs.size());
        QapClock clock;
        clock.Start();
        string seqhead="\nseqhead:\n";
        string seqdiff="\nseqdiff:\n";
        frames[0]=diffs.front().substr(seqdiff.size(),diffs.front().size()-seqhead.size()-seqdiff.size());
        TGabobReplayFrame curframe;
        TSimpleBinaryLoader::fromStr(Env,&curframe,frames[0]);
        for(int i=pack_start_frame;i<diffs.size();i++)
        {
          TGabobReplayFrame next;
          next=curframe;
          V.top.from.set(Env,curframe);
          V.top.to.set(Env,next);
          V.clear();
          V.IO.IO.mem=diffs[i];
          V.IO.IO.pos=0;
          V.loadmsg();
          V.top.from.pType->Use(V);
          frames[i]=TSimpleBinarySaver::toStr(Env,&next);
          QapAssert(real_frames[i]==frames[i]);
          curframe=next;
        }
        clock.Stop();
        real ms=clock.MS();
        auto outfiledata=TSimpleBinarySaver::toStr(Env,&frames);
        file_put_contents("unpackedframes.bin",outfiledata);
        UberInfoBox(
          "Info(Unpack)",
          "------------------------------\n"
          "date : "+cur_date_str()+"\n"
          "n : "+IToS(frames.size())+"\n"
          "total_time : "+FToS(ms)+" ms\n"
          "time/frame : "+FToS(ms/real(frames.size()))+"\n"
          "outsize : "+IToS(outfiledata.size())+"\n"
          "inpsize : "+IToS(packed_data.size())+"\n"
          "ratio : "+FToS(100.0*real(outfiledata.size())/real(packed_data.size()))+"%"
        );
      }
      __asm{int 3};return;
      ;
      //{
      //  auto data=file_get_contents("frames.bin");
      //  vector<string> frames;
      //  TSimpleBinaryLoader::fromStr(Env,&frames,data);
      //  vector<string> diffs;
      //  t_diff_builder V(Env);
      //  int fpk=128-32;
      //  if(file_get_contents("fpk.txt").size()>0)fpk=SToI(file_get_contents("fpk.txt"));
      //  QapClock clock;
      //  clock.Start();
      //  for(int i=0;i<frames.size();i++)
      //  {
      //    if(i%fpk==0){
      //      diffs.push_back("\nraw:"+frames[i/fpk]);
      //      continue;
      //    }
      //    TGabobReplayFrame a;
      //    TGabobReplayFrame b;
      //    TSimpleBinaryLoader::fromStr(Env,&a,frames[i/fpk]);
      //    TSimpleBinaryLoader::fromStr(Env,&b,frames[i]);
      //    V.top.from.set(Env,a);
      //    V.top.to.set(Env,b);
      //    V.top.from.pType->Use(V);
      //    qap_add_back(diffs)="\ndif:"+V.get_binout();
      //    V.clear();
      //  }
      //  clock.Stop();
      //  real ms=clock.MS();
      //  auto outfiledata=V.get_header()+TSimpleBinarySaver::toStr(Env,&diffs);
      //  file_put_contents("packedframes.bin",outfiledata);
      //  UberInfoBox(
      //    "Info!",
      //    "------------------------------\n"
      //    "date : "+cur_date_str()+"\n"
      //    "fpk : "+IToS(fpk)+"\n"
      //    "n : "+IToS(frames.size())+"\n"
      //    "total_time : "+FToS(ms)+" ms\n"
      //    "time/frame : "+FToS(ms/real(frames.size()))+"\n"
      //    "outsize : "+IToS(outfiledata.size())+"\n"
      //    "inpsize : "+IToS(data.size())+"\n"
      //    "ratio : "+FToS(100.0*real(outfiledata.size())/real(data.size()))+"%"
      //  );
      //}
      //__asm{int 3};
      //;
      //auto data=file_get_contents("frames.bin");
      //vector<string> frames;
      //TSimpleBinaryLoader::fromStr(Env,&frames,data);
      //vector<string> diffs;
      //vector<int> diff_sizes;
      //QapClock clock;
      //clock.Start();
      ////32 == 63%
      //int fpk=128-32;
      //if(file_get_contents("fpk.txt").size()>0)fpk=SToI(file_get_contents("fpk.txt"));
      //for(int i=0;i<frames.size();i++)
      //{
      //  if(i%fpk==0){
      //    diffs.push_back("\nraw:"+frames[i/fpk]);
      //    diff_sizes.push_back(diffs.back().size());
      //    continue;
      //  }
      //  TGabobReplayFrame a;
      //  TGabobReplayFrame b;
      //  TGabobReplayFrame c;
      //  TSimpleBinaryLoader::fromStr(Env,&a,frames[i/fpk]);
      //  c=a;
      //  TSimpleBinaryLoader::fromStr(Env,&b,frames[i]);
      //  auto diff=build_diff(Env,a,b);
      //  apply_diff(Env,diff,a,c);
      //  bool ok=b==c;
      //  if(!ok){UberInfoBox("error","no way");}
      //  diffs.push_back("\ndif:"+diff);
      //  diff_sizes.push_back(diffs.back().size());
      //}
      //clock.Stop();
      //real ms=clock.MS();
      //auto outfiledata=join(diffs,"");
      //file_put_contents("packedframes.bin",outfiledata);
      //UberInfoBox(
      //  "Info!",
      //  "------------------------------\n"
      //  "date : "+cur_date_str()+"\n"
      //  "fpk : "+IToS(fpk)+"\n"
      //  "n : "+IToS(frames.size())+"\n"
      //  "total_time : "+FToS(ms)+" ms\n"
      //  "time/frame : "+FToS(ms/real(frames.size()))+"\n"
      //  "outsize : "+IToS(outfiledata.size())+"\n"
      //  "inpsize : "+IToS(data.size())+"\n"
      //  "ratio : "+FToS(100.0*real(outfiledata.size())/real(data.size()))+"%"
      //);
      //;
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}
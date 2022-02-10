#define DEF_PRO_HEAD
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL

#include "Entity/OutDeviceBase.inl"
#include "IsSameVisitor.inl"
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
//#include "SpecInfoToolForLex.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"

//#include "t_type_expr_lexem.inl"

//void t_type_expr_build(IEnvRTTI&Env,t_type_expr&out,const string&code)
//{
//  t_type_expr::t_main_test tmp;
//  auto res=load_obj_full(Env,tmp,code);
//  int gg=1;
//  QapDebugMsg(res.msg);
//  QapDebugMsg(QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(tmp)));
//  if(!res.ok)return;
//}
#if(1)
  #ifdef DEF_BUILD_MACRO
    #include "../Macro/t_inl_file_lexem.h"
  #else
  //=====>>>>>t_inl_file_lexem
  #include "t_inl_file_lexem.inl"
  //<<<<<=====t_inl_file_lexem
  #endif //DEF_BUILD_MACRO//
#else
  #include "t_inl_file_lexem.h"
#endif
void UberInfoBox(const string&caption,const string&text);
void InfoBox(const string&text){UberInfoBox("InfoBox",text);}

class TToolLexToStr{
public:
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TAutoPtr<TYPE>&inp){
    if(!inp)return "";
    string out;
    auto ok=save_obj(Env,inp,out);
    QapAssert(ok);
    return out;
  }
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TYPE&inp){
    string out;
    auto ok=save_obj(Env,inp,out);
    QapAssert(ok);
    return out;
  }
};

class TUberVisitor:public IVisitorRTTI,public TToolLexToStr{
public:
  typedef TUberVisitor SelfClass;
public:
  class TBranch:public TOutDev{
  public:
    vector<string> out;
  public:
    TContext top;
    vector<TContext> items;
  public:
    void push_impl(){items.push_back(top);}
    void pop_impl(){top=items.back();items.pop_back();}
    TContext&back(){return items.back();}
    TContext&front(){return items.front();}
    int size(){return items.size();}
    TContext&operator[](int index){return items[index];}
  public:
    void push(DevCmd*pCmd)
    {
      QapAssert(!top.pCmd&&top.head.empty());
      push_impl();
      if(pCmd)
      {
        TCmdVisitor::t_dev dev;
        TCmdVisitor CV(dev,&top);
        pCmd->Use(CV);
        QapAssert(dev.ok);
        auto&back=this->back();
        back.head=std::move(top.head);
        back.pCmd=std::move(pCmd);
      }else{
        top.pType=nullptr;
        top.pValue=nullptr;
      }
      top.pCmd=nullptr;
      top.head.clear();
    }
    void pop()
    {
      QapAssert(!top.pCmd&&top.head.empty());
      pop_impl();
      top.pCmd=nullptr;
      top.head.clear();
    }
  };
public:
  TBranch&dev;
public:
  TUberVisitor(TBranch&dev):dev(dev){}
public:
  void Do(TTypeStruct*p)
  {
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    auto p_fullname=p->GetFullName()+"\1";
    if(p_fullname.find("t_fv_stat\1")!=string::npos)
    {
      int gg=1;
      auto&value=*(t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat*)dev.top.pValue;
      if(auto*pf=t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(value.way.get()))
      {
        auto&Env=*value.way.Product.pType->Env.get();
        string bef;
        #define F(FIELD)bef+=toStr(Env,value.FIELD);
        F(keywords);
        F(type);
        F(cv);
        F(sep0);
        F(path);
        F(sep1);
        #undef F
        auto aft=toStr(Env,pf->params)+toStr(Env,pf->cv1);
        for(;;)
        {
          {int pos=bef.find_first_not_of('\n');if(pos>0){bef=bef.substr(pos);}else break;}
          {int pos=bef.find_first_not_of(' ');if(pos>0){bef=bef.substr(pos);}else break;}
        }
        //t_inl_file::t_fv_class_stat::t_fv_class_stat::
        auto*rnp=t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::UberCast(
          value.name.body.get()
        );
        if(rnp)
        {
          qap_add_back(dev.out)=bef+rnp->name+aft+";";//+"//way.pType="+value.way.Product.pType->GetFullName();
        }
      }
    }
    if(subtype)
    {
      TOutDev::TSubType tmp;
      dev.push(&tmp);
      subtype->Use(*this);
      dev.pop();
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      TOutDev::TMemberID tmp(i);
      dev.push(&tmp);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSys*p)
  {
    return;
    TOutDev::TCmdHeadVisitor head;
    auto&arr=dev.items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      head.Context.pType=ex.pType;
      head.Context.pValue=ex.pValue;
      ex.pCmd->Use(head);
    }
    string s;
    p->TxtIO->Save(s,dev.top.pValue);
    dev.out.push_back("//"+head.out);
    dev.out.push_back(s);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(dev.top.pValue);
    if(!Count)return;
    TType*elemType=p->ElementType.get();
    const string p_elemTypefullname=elemType->GetFullName();
    for(int i=0;i<Count;i++)
    {
      TOutDev::TVecID tmp(i);
      dev.push(&tmp);
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSelfPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){QapAssert(p->ElementType);return;}
    TAutoPtr<void>&value=*(TAutoPtr<void>*)dev.top.pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*pmTypeType=p->mType.Type.get();
    if(!value)return;
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      TOutDev::TChunk tmp;
      dev.push(&tmp);
      type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeWeakPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");
  }
};

void empty_unit_test_forIsSameVisitor(IEnvRTTI&Env)
{
  //InfoBox(Sys$$<THiAllClass>::GetRTTI(Env)->extInfo.SpecInfo);
  /*TAutoPtr<t_inl_file::i_class_stat> cs;load_obj_full(Env,cs,"struct ttt{typedef ttt*pttt;};");*/
  t_inl_file inp;
  t_inl_file tmp;
  string cmd_test_code=file_get_contents("../lex_gen/inl_parser_cmp_test.h");
  cmd_test_code=StrReplace(cmd_test_code,"\r\n","\n");
  cmd_test_code=StrReplace(cmd_test_code,"\r","\n");
  auto arr=split(cmd_test_code,"\n");
  for(int i=0;i+1<arr.size();i+=2)
  {
    auto&a=arr[i+0];
    auto&b=arr[i+1];
    QapAssert(load_obj_full(Env,inp,a).ok);
    QapAssert(load_obj_full(Env,tmp,b).ok);
    bool ok=TIsSameVisitor::Exec(Env,inp,tmp);
    if(ok!=(a==b))InfoBox("wrong answer on test:\nret_value: "+BToS(ok)+"\ni = "+IToS(i)+"\na:\n"+a+"\nb:\n"+b);
  }
  InfoBox("arr.size() = "+IToS(arr.size()));
}
#include "TSimpleBinarySaver.inl"

struct t_some_shit_grabber_tool:public TToolLexToStr,public t_inl_file{
  IEnvRTTI&Env;
  vector<string>&out;
  t_some_shit_grabber_tool(IEnvRTTI&Env,vector<string>&out):Env(Env),out(out){}
  typedef vector<TAutoPtr<i_class_stat>> t_class_stats;
  struct t_mem{
    struct t_elem{
      t_class_stats*parr;
      string name;
    };
    vector<t_elem> stack;
    void push(t_class_stats&arr,const string&name)
    {
      auto&back=qap_add_back(stack);
      back.parr=&arr;
      back.name=name;
    }
    void pop(t_class_stats&arr,const string&name)
    {
      QapAssert(!stack.empty());
      QapAssert(&arr==stack.back().parr);
      QapAssert(name==stack.back().name);
      stack.pop_back();
    }
    string get_sub(int n)
    {
      string out;
      for(int i=0;i<std::min<int>(n,stack.size());i++){
        out+=stack[i].name+"::";
      }
      return out;
    }
  };
  t_mem mem;
  static string without_first_sep(const string&src)
  {
    string out=src;
    for(;;)
    {
      {int pos=out.find_first_not_of('\n');if(pos>0){out=out.substr(pos);}else break;}
      {int pos=out.find_first_not_of(' ');if(pos>0){out=out.substr(pos);}else break;}
    }
    return out;
  }
  static string without_last_part(const string&text,const string&last_part){
    QapAssert(text.size()>last_part.size());
    QapAssert(text.substr(text.size()-last_part.size())==last_part);
    return text.substr(0,last_part.size());
  }
  typedef t_fv_class_stat::t_type_expr::t_keyword t_keyword;
  bool drop_keyword(vector<t_keyword>&arr,const string&kw){
    bool ok=false;
    QapCleanIf(arr,[&kw,&ok](t_keyword&ex){if(ex.keyword!=kw)return false;ok=true; return true;});
    return ok;
  }
  t_class_class_stat*find_type_in_stats_by_name(t_class_stats&arr,const string&name)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(auto*p=t_class_class_stat::UberCast(ex.get()))
      {
        if(p->body.name==name)return p;
      }
    }
    return nullptr;
  }
  typedef t_fv_class_stat::t_type_expr::t_raw_name_part t_raw_name_part;
  typedef t_fv_class_stat::t_type_expr::t_scopes t_scopes;
  t_typedef_class_stat*find_typedef_in_stats_by_name(t_class_stats&arr,const string&name)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(auto*p=t_typedef_class_stat::UberCast(ex.get()))
      {
        if(auto*prn=t_raw_name_part::UberCast(p->body.name.body.get()))
        {
          if(prn->name==name)return p;
          continue;
        }
        QapDebugMsg("no way");
      }
    }
    return nullptr;
  }
  string find_type_in_mem_by_name(const string&name)
  {
    auto&arr=mem.stack;
    for(int i=0;i<arr.size();i++)
    {
      auto id=arr.size()-i-1;
      auto&ex=arr[id];
      auto*ptype=find_type_in_stats_by_name(*ex.parr,name);
      auto*ptypedef=find_typedef_in_stats_by_name(*ex.parr,name);
      if(!ptype&&!ptypedef)continue;
      return mem.get_sub(id+1);
      //ptype->body.
    }
    return "";
  }
  struct t_bot_with_t_scopes{
    t_scopes&src;
    bool used;
    t_scopes buf;
    void rollback()
    {
      if(!used)return;
      src=std::move(buf);
    }
  };
  /*struct t_tmp_obj{
    t_fv_class_stat&src;
    bool used;
    t_fv_class_stat buf;
    ~t_tmp_obj()
    {
      if(!used)return;
      src=std::move(buf);
    }
  };*/
  void foo(t_fv_class_stat&value,const string&prefix)
  {
    auto*pw=t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(value.body.way.get());
    if(!pw)return;
    typedef t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body t_impl_func_body;
    if(!t_impl_func_body::UberCast(pw->body.get()))return;
    auto*rnp=t_raw_name_part::UberCast(
      value.body.name.body.get()
    );
    if(!rnp)return;
    #define qap_decltype(EXPR)std::remove_reference<decltype(EXPR)>::type
    typedef qap_decltype(value.body.type.get()->scopes.arr[0].body) t_body;
    #undef qap_decltype
    QapAssert(value.body.type);
    //t_tmp_obj tmp_obj={value,false};
    t_bot_with_t_scopes ret_type_bot={value.body.type.get()->scopes,false};
    if(!prefix.empty())for(;;)
    {
      auto&t=*value.body.type.get();
      QapAssert(!t.first);
      auto&scopes=t.scopes;
      vector<string> out;
      auto f=[&out](t_body&b){
        QapAssert(!b.params);
        qap_add_back(out)=b.name;
      };
      f(scopes.first);
      auto&arr=scopes.arr;
      for(int i=0;i<arr.size();i++)
      {
        f(arr[i].body);
      }
      auto path=split(prefix,"::");path.pop_back();
      auto res=qap_find_str(path,out[0]);
      if(res.empty())
      {
        //find_class_stat_by_name_in_arr
        auto pre_path=find_type_in_mem_by_name(out[0]);
        string out_type=pre_path+join(out,"::");
        {
          ret_type_bot.buf=std::move(t.scopes);
          ret_type_bot.used=true;
          auto res=load_obj_full(Env,t.scopes,out_type);
          QapAssert(res.ok);
        }
        int gg=1;
        break;
      }
      auto subpath=qap_arr_slice(path,res.back());
      vector<string> fullpath;
      QapToolsVectorEx(fullpath)+=std::move(subpath);
      QapToolsVectorEx(fullpath)+=std::move(out);
      auto out_type=join(fullpath,"::");
      {
        ret_type_bot.buf=std::move(t.scopes);
        ret_type_bot.used=true;
        auto res=load_obj_full(Env,t.scopes,out_type);
        QapAssert(res.ok);
      }
      int gg=1;
      break;
    }
    //typedef qap_decltype(value.body.keywords[0]) t_elem;
    //typedef qap_decltype(value.body.keywords) t_arr;
    vector<t_keyword> buff_arr; bool need_restore=false; bool friend_dropped=false; bool virtual_dropped=false;
    {
      vector<t_keyword>&arr=value.body.keywords;
      drop_keyword(arr,"inline");
      if(prefix.empty())drop_keyword(arr,"static");
      int gg=1;
      qap_simple_clone(Env,buff_arr,arr);
      static auto starr=split("explicit,static",",");
      for(int i=0;i<starr.size();i++)need_restore=need_restore||drop_keyword(arr,starr[i]);
      friend_dropped=drop_keyword(arr,"friend");
      virtual_dropped=drop_keyword(arr,"virtual");
      need_restore=need_restore||friend_dropped||virtual_dropped;
    }
    auto f=[&]()->string{
      string out;
      #define F(FIELD)out+=toStr(Env,value.body.FIELD);
      F(keywords);
      F(type);
      F(cv);
      F(sep0);
      F(path);
      F(sep1);
      #undef F
      return out;
    };
    if(!prefix.empty())if(value.body.path)
    {
      auto prefix_back=split(prefix.substr(0,prefix.size()-2),"::").back();
      auto path_back=value.body.path.get()->arr.back().value;
      if(path_back!=prefix_back)
      {
        QapNoWay();
      }
      QapAssert(value.body.path.get()->arr.size()==1);
      value.body.path=nullptr;
    }
    if(!prefix.empty())QapAssert(!value.body.path);
    auto impl_bef=f();
    ret_type_bot.rollback();
    if(need_restore)value.body.keywords=std::move(buff_arr);
    auto ast_bef=f();
    QapAssert(pw->params);
    string aft;
    //remove def value from params
    if(pw->params)
    {
      auto&arr=pw->params.get()->arr;
      #define qap_decltype(EXPR)std::remove_reference<decltype(EXPR)>::type
      typedef qap_decltype(arr[0].value) t_item;
      #undef qap_decltype
      vector<t_item> items;items.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        items[i]=std::move(ex.value);
        ex.value=nullptr;
      }
      //
      aft=toStr(Env,*pw);
      //
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.value=std::move(items[i]);
      }
    }
    impl_bef=without_first_sep(impl_bef);
    auto short_aft=toStr(Env,pw->params)+toStr(Env,pw->cv1);
    string new_path=prefix;if(friend_dropped)new_path.clear();
    qap_add_back(out)=impl_bef+new_path+rnp->name+aft;
    //change tree
    t_fv_class_stat tmp;
    auto tmp_src=ast_bef+rnp->name+short_aft+";";
    auto tmp_res=load_obj_full(Env,tmp,tmp_src);
    QapAssert(tmp_res.ok);
    value=std::move(tmp);
  }
  template<class T_FUNC_LIKE_STAT_IMPL>
  void bar(T_FUNC_LIKE_STAT_IMPL&value,const string&prefix)
  {
    auto*pimpl=t_impl_func_body::UberCast(value.body.get());
    if(!pimpl)return;
    __if_exists(T_FUNC_LIKE_STAT_IMPL::prefix)
    {
      TAutoPtr<t_ctor_class_stat::t_impl::t_explicit>&value_prefix=value.prefix;
      TAutoPtr<t_ctor_class_stat::t_impl::t_explicit> backup_value_prefix=std::move(value_prefix);
    }
    vector<t_keyword> buff_arr; bool need_restore=false; bool friend_dropped=false; bool virtual_dropped=false;
    {
      __if_exists(T_FUNC_LIKE_STAT_IMPL::keywords)
      {
        vector<t_keyword>&arr=value.keywords;
        drop_keyword(arr,"inline");
        if(prefix.empty())drop_keyword(arr,"static");
        int gg=1;
        qap_simple_clone(Env,buff_arr,arr);
        static auto starr=split("explicit,static",",");
        for(int i=0;i<starr.size();i++)need_restore=need_restore||drop_keyword(arr,starr[i]);
        friend_dropped=drop_keyword(arr,"friend");
        virtual_dropped=drop_keyword(arr,"virtual");
        need_restore=need_restore||friend_dropped||virtual_dropped;
      }
    }
    if(!prefix.empty())if(value.path)
    {
      auto prefix_back=split(prefix.substr(0,prefix.size()-2),"::").back();
      auto path_back=value.path.get()->arr.back().value;
      if(path_back!=prefix_back)
      {
        QapNoWay();
      }
      QapAssert(value.path.get()->arr.size()==1);
      value.path=nullptr;
    }
    if(!prefix.empty())QapAssert(!value.path);
    if(prefix.empty()&&value.path)return;
    QapAssert(!value.path);
    int gg=1;
    //auto pre=without_last_part(prefix,"::");
    if(!friend_dropped)
    {
      TAutoPtr<t_func_path> tmp;
      auto res=load_obj_full(Env,tmp,prefix);
      QapAssert(res.ok);
      value.path=std::move(tmp);
    }
    if(friend_dropped)QapAssert(!value.path);
    if(true)
    {
      auto&arr=value.params.arr;
      #define qap_decltype(EXPR)std::remove_reference<decltype(EXPR)>::type
      typedef qap_decltype(arr[0].value) t_item;
      #undef qap_decltype
      vector<t_item> items;items.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        items[i]=std::move(ex.value);
        ex.value=nullptr;
      }
      //
      qap_add_back(out)=without_first_sep(toStr(Env,value));
      //
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.value=std::move(items[i]);
      }
    }
    value.path=nullptr;
    value.body.build<t_null_func_body>(Env);
    __if_exists(T_FUNC_LIKE_STAT_IMPL::keywords){if(need_restore)value.keywords=std::move(buff_arr);}
    __if_exists(T_FUNC_LIKE_STAT_IMPL::prefix)
    {
      value_prefix=std::move(backup_value_prefix);
    }
  }
  void grab_all_class_name_form_tree(t_class_stats&arr,const string&prefix)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto*ptr=arr[i].get();
      if(auto*p=t_fv_class_stat::UberCast(ptr))
      {
        foo(*p,prefix);
      }
      if(auto*p=t_ctor_class_stat::UberCast(ptr))
      {
        bar(p->body,prefix);
      }
      if(auto*p=t_common_oper_class_stat::UberCast(ptr))
      {
        bar(p->body,prefix);
      }
      if(auto*p=t_oper_cast_class_stat::UberCast(ptr))
      {
        bar(*p,prefix);
      }
      if(auto*p=t_dtor_class_stat::UberCast(ptr))
      {
        bar(*p,prefix);
      }
      auto*cs=t_class_class_stat::UberCast(ptr);
      if(!cs)continue;
      //qap_add_back(out)="//"+prefix+cs->body.name;
      auto*b=cs->body.body.get();
      if(!b)continue;
      mem.push(b->arr,cs->body.name);
      grab_all_class_name_form_tree(b->arr,prefix+cs->body.name+"::");
      mem.pop(b->arr,cs->body.name);
    }
  }
};

void xxx_empty_unit_test_old(IEnvRTTI&Env)
{
  auto content=file_get_contents("../lex_gen/inl_parser_test.h");
  auto code=StrReplace(content,"\r","\n");
  auto test_out=split(code,"\n//out\n")[1];
  code=split(code,"\n//out\n")[0];
  QapClock clock;
  clock.Start();
  t_inl_file tmp;
  auto res=load_obj_full(Env,tmp,code);
  clock.Stop();
  int gg=1;
  InfoBox("time:"+FToS(clock.MS())+"ms\n"+res.msg);
  {
    vector<string> out;
    t_some_shit_grabber_tool tool(Env,out);
    tool.grab_all_class_name_form_tree(tmp.arr,"");
    string tree;
    QapAssert(save_obj(Env,tmp,tree));
    InfoBox(tree+"\n//impl\n"+join(out,"\n"));
  }
  {
    TUberVisitor::TBranch dev;
    TUberVisitor uv(dev);
    TRawPtr ptr(Env,tmp);
    dev.top.pType=ptr.pType;
    dev.top.pValue=ptr.pValue;
    clock.Start();
    ptr.pType->Use(uv);
    clock.Stop();
    string s="time:"+FToS(clock.MS())+"ms\n"+join(dev.out,"\n");
    InfoBox(s);
    file_put_contents("out.txt",s);
    //t_inl_file::t_class_class_stat::UberCast(tmp.arr[0].get())->body.name
    //t_inl_file::i_class_stat_visitor
  }
  InfoBox(QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(tmp)));
  TerminateProcess(GetCurrentProcess(),0);
  if(!res.ok)return;
}

class TRandomClass2{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRandomClass2)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,DEF,$,$)\
ADDVAR(int,y,DEF,$,$)\
ADDVAR(int,z,DEF,$,$)\
ADDEND()
//=====+>>>>>TRandomClass2
#include "QapGenStruct.inl"
//<<<<<+=====TRandomClass2
public:
};

#if(0)
class TRandomBookPage2:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRandomBookPage2)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRandomClass2,rc2,DEF,$,$)\
ADDEND()
//=====+>>>>>TRandomBookPage2
#include "QapGenStruct.inl"
//<<<<<+=====TRandomBookPage2
public:
  void Render(t_context&con){
    con.qDev.BindTex(0,nullptr);
    con.qDev.SetColor(0xff000000);
    con.qDev.DrawQuad(con.pos+vec2d_zero,vec2d(100,20));
  }
  void Update(t_context&con){
    rc2.x++;
    int gg=1;
    //t_type_expr tmp;
    //auto content=file_get_contents("../lex_gen/inl_parser_test.h");
    //content=StrReplace(content,"\r","\n");
    //t_type_expr_build(con.Env,tmp,content);
  }
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
        F(TType)//F(TRandomBookPage2)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
      empty_unit_test(Env);
    }
    void Run(IEnvRTTI&Env)
    {

    }
    ThisCompileUnit(){

    }
  };
  ThisCompileUnit ThisUnit;
}
#endif

#include "main2.inl"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //StartMemLeakTest();
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
    xxx_empty_unit_test_old(Env);
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}
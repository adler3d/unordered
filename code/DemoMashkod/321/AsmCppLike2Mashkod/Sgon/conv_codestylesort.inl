
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

struct t_hpp_to_cpp_conv_tool:public TToolLexToStr,public t_inl_file{
  IEnvRTTI&Env;
  vector<string>&out;
  t_hpp_to_cpp_conv_tool(IEnvRTTI&Env,vector<string>&out):Env(Env),out(out){}
  typedef vector<TAutoPtr<i_class_stat>> t_class_stats;
  struct t_mem{
    struct t_elem{
      t_class_class_stat*pclass;
      t_class_stats*parr;
      string name;
    };
    vector<t_elem> stack;
    void push(t_class_class_stat*pclass,t_class_stats&arr,const string&name)
    {
      auto&back=qap_add_back(stack);
      back.pclass=pclass;
      back.parr=&arr;
      back.name=name;
    }
    void pop(t_class_class_stat*pclass,t_class_stats&arr,const string&name)
    {
      QapAssert(!stack.empty());
      QapAssert(pclass==stack.back().pclass);
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
    static const auto internal_types=split("void,bool,char,int,float,double,string",",");
    if(!qap_find_str(internal_types,name).empty())return "";
    if(is_first_part_of(name,"vector"))
    {
      int gg=1;
      bool c=name=="vector<field_cmp_result_item>";
    }
    auto&arr=mem.stack;
    for(int i=0;i<arr.size();i++)
    {
      auto id=arr.size()-i-1;
      auto&ex=arr[id];
      if(ex.pclass)if(auto*pp=ex.pclass->body.parents.get())
      {
        auto fn=dev.get(ex.pclass)->get_full_name(dev);
        auto pc=dev.get(ex.pclass);
        auto&parr=pc->parents;
        for(int i=0;i<parr.size();i++)
        {
          auto&ex=parr[i];
          bool is_fd=!ex->body.body;
          auto*p=is_fd?dev.get_with_body(ex):dev.get(ex);
          QapAssert(p);
          QapAssert(p->ptr->body.body);
          auto n=p->get_name();
          if(n=="TOutDev")
          {
            int gg=1;
          }
          auto*pt=p->find_in_scope(dev,name);
          if(pt)
          {
            int gg=1;
            auto*out_t=dev.get(pt);
            auto pt_fn=out_t->get_full_name(dev);
            auto path=out_t->get_path(dev);
            return path;
          }
        }
        int gg=1;
      }
      auto*ptype=find_type_in_stats_by_name(*ex.parr,name);
      auto*ptypedef=find_typedef_in_stats_by_name(*ex.parr,name);
      if(!ptype&&!ptypedef)continue;
      return mem.get_sub(id+1);
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
      src=std::move(buf);used=false;
    }
  };
  typedef t_fv_class_stat::t_type_expr t_type_expr;
  typedef t_type_expr::t_impl_typeexpr t_impl_typeexpr;
  static t_impl_typeexpr*safe_get_impl(TAutoPtr<t_type_expr>&t)
  {
    QapAssert(t);
    auto*pt=t.get();
    auto*pimpltype=t_impl_typeexpr::UberCast(pt->body.get());
    if(!pimpltype)return nullptr;
    return pimpltype;
  }
  static t_impl_typeexpr*get_impl(t_type_expr&t)
  {
    auto*pimpltype=t_impl_typeexpr::UberCast(t.body.get());
    QapAssert(pimpltype);
    return pimpltype;
  }
  void init_ret_type_bot(t_bot_with_t_scopes&ret_type_bot,t_fv_class_stat&value,const string&prefix)
  {
    auto&t=*get_impl(*value.body.type.get());
    init_ret_type_bot_impl(ret_type_bot,t,prefix);
  }
  void init_ret_type_bot_impl(t_bot_with_t_scopes&ret_type_bot,t_impl_typeexpr&t,const string&prefix)
  {
    typedef t_type_with_sep t_body;
    bool ok=true;
    QapAssert(!t.global);
    auto&scopes=t.scopes;
    vector<string> out;
    auto f=[&out](t_body&b)->bool{
      if(b.concrete_params)return false;
      qap_add_back(out)=b.name;
      return true;
    };
    ok=f(scopes.first);
    if(!ok)
    {
      string backup;t_impl_typeexpr tmp;
      {bool ok=save_obj(Env,t,backup);QapAssert(ok);}
      load_obj_full(Env,tmp,backup);
      auto&scopes=tmp.scopes;
      //std::swap(tmp,t);
      auto&arr=scopes.first.concrete_params.get()->arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*pb=ex.body.get();
        QapAssert(pb);
        auto*ptr=t_type_concrete_param_way::UberCast(pb);
        if(!ptr)continue;
        auto*pvb=ptr->value.body.get();
        auto*pimpl=get_impl(*pvb);
        t_bot_with_t_scopes rtb={pimpl->scopes,false};
        init_ret_type_bot_impl(rtb,*pimpl,prefix);
        if(!rtb.used)continue;
        if(!ret_type_bot.used)
        {
          ret_type_bot.used=true;
          ret_type_bot.buf=std::move(t.scopes);
        }
        //QapDebugMsg("under construction.");
        int gg=1;
      }
      if(ret_type_bot.used)
      {
        t.scopes=std::move(tmp.scopes);
      }
      int gg=1;
      return;
    }
    auto&arr=scopes.arr;
    for(int i=0;i<arr.size();i++)
    {
      ok=f(arr[i].body);
      if(!ok)return;
    }
    if(!ok)
    {
      QapDebugMsg("no way!\ntype use concrete_params:\n"+toStr(Env,t)+"\n\nprefix:\n"+prefix);
      return;
    }
    auto path=split(prefix,"::");path.pop_back();
    auto res=qap_find_str(path,out[0]);
    if(res.empty())
    {
      auto pre_path=find_type_in_mem_by_name(out[0]);
      string out_type=pre_path+join(out,"::");
      {
        ret_type_bot.buf=std::move(t.scopes);
        ret_type_bot.used=true;
        auto res=load_obj_full(Env,t.scopes,out_type);
        QapAssert(res.ok);
      }
      int gg=1;
      return;
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
    return;
  }
  typedef t_type_expr::t_func_param t_func_param;
  typedef t_type_expr::t_func_param_value t_func_param_value;
  struct t_remove_def_values_from_params{
    t_hpp_to_cpp_conv_tool&owner;
    vector<t_func_param>&src;
    bool used;
    bool bots_used;
    vector<TAutoPtr<t_func_param_value>> buf;
    /*struct t_bot{
      bool used;
      t_scopes buf;
    };*/
    vector<TAutoPtr<t_scopes>> bots;
    void prepare()
    {
      used=true;
      buf.resize(src.size());
      for(int i=0;i<src.size();i++)
      {
        auto&ex=src[i];
        buf[i]=std::move(ex.value);
        ex.value=nullptr;
      }
    }
    static t_impl_typeexpr*getimpltypeexpr_from_param(t_func_param&param)
    {
      auto*ptr=param.body.get();
      auto*p=t_type_expr::t_type_func_param::UberCast(ptr);
      auto*pimpl=safe_get_impl(p->type.body);
      if(!pimpl){
        QapDebugMsg("ok.");
        return nullptr;
      }
      if(pimpl->global){
        QapDebugMsg("this way used? ok.");
        return nullptr;
      }
      return pimpl;
    }
    void update_params_types(const string&prefix)
    {
      bots.resize(src.size());
      for(int i=0;i<src.size();i++)
      {
        auto&ex=src[i];
        auto&b=bots[i];
        auto*pimpl=getimpltypeexpr_from_param(ex);
        t_bot_with_t_scopes bot={pimpl->scopes,false};
        owner.init_ret_type_bot_impl(bot,*pimpl,prefix);
        if(!bot.used)continue;
        *b.build<t_scopes>(owner.Env)=std::move(bot.buf);
        bots_used=true;
      }
    }
    void rollback()
    {
      if(bots_used)
      {
        for(int i=0;i<src.size();i++)
        {
          auto&ex=src[i];
          auto&b=bots[i];
          if(!b)continue;
          auto*pimpl=getimpltypeexpr_from_param(ex);
          t_bot_with_t_scopes bot={pimpl->scopes,true};
          bot.buf=std::move(*b.get());
          bot.rollback();
        }
        bots_used=false;
      }
      if(!used)return;
      used=false;
      for(int i=0;i<src.size();i++)
      {
        auto&ex=src[i];
        ex.value=std::move(buf[i]);
      }
    }
  };
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
    QapAssert(value.body.type);
    auto*pimpltype=get_impl(*value.body.type.get());
    QapAssert(pimpltype);
    //t_tmp_obj tmp_obj={value,false};
    t_bot_with_t_scopes ret_type_bot={pimpltype->scopes,false};
    if(!prefix.empty())
    {
      init_ret_type_bot(ret_type_bot,value,prefix);
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
      F(sep_wa);
      F(keywords);
      F(type);
      F(cv);
      F(sep0);
      F(path);
      F(callconv);
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
    t_remove_def_values_from_params rdvfp_bot={*this,pw->params.get()->arr,false,false};
    rdvfp_bot.prepare();
    if(friend_dropped){
      rdvfp_bot.update_params_types(prefix);
    }
    aft=toStr(Env,*pw);
    rdvfp_bot.rollback();
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
    __if_exists(T_FUNC_LIKE_STAT_IMPL::type)
    {
      t_type_expr&vt=value.type;
      auto*pimpltype=get_impl(vt);
      QapAssert(pimpltype);
      t_bot_with_t_scopes ret_type_bot={pimpltype->scopes,false};
      if(!prefix.empty())
      {
        init_ret_type_bot_impl(ret_type_bot,*pimpltype,prefix);
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
    t_type_expr::t_func_params&params=value.params;
    t_remove_def_values_from_params rdvfp_bot={*this,params.arr,false,false};
    rdvfp_bot.prepare();
    if(friend_dropped){
      rdvfp_bot.update_params_types(prefix);
    }
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
    rdvfp_bot.rollback();
    value.path=nullptr;
    value.body.build<t_null_func_body>(Env);
    __if_exists(T_FUNC_LIKE_STAT_IMPL::keywords){if(need_restore)value.keywords=std::move(buff_arr);}
    __if_exists(T_FUNC_LIKE_STAT_IMPL::prefix)
    {
      value_prefix=std::move(backup_value_prefix);
    }
    __if_exists(T_FUNC_LIKE_STAT_IMPL::type)
    {
      ret_type_bot.rollback();
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
        bar(p->body,prefix);
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
      mem.push(cs,b->arr,cs->body.name);
      grab_all_class_name_form_tree(b->arr,prefix+cs->body.name+"::");
      mem.pop(cs,b->arr,cs->body.name);
    }
  }
  struct t_uberdev{
    struct t_class_item{
      t_class_class_stat*ptr=nullptr;
      vector<t_class_class_stat*> path; 
      vector<t_class_class_stat*> parents;
      vector<t_class_class_stat*> subs;
      void rescan(t_uberdev&dev)
      {
        path=dev.stack;
        auto backup=ptr;
        scan_parents(dev);
        auto*p=dev.get(backup);
        p->scan_class(dev);
      }
      void scan_class(t_uberdev&dev)
      {
        scan_subs(dev);
        scan_defs(dev);
      }
      void scan_parents(t_uberdev&dev)
      {
        if(!ptr->body.parents)return;
        auto&arr=ptr->body.parents.get()->arr;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          auto*p=dev.find_target_in_outers(ex.name);
          if(!p)
          {
            static bool first=true;
            if(first)
            {
              first=false; InfoBox("parent class no found:\n"+ex.name);
            }
          }
          qap_add_back(parents)=p;
        }
      }
      void scan_subs(t_uberdev&dev)
      {
        if(!ptr->body.body)return;
        auto&arr=ptr->body.body.get()->arr;
        dev.push(ptr);
        auto backup=ptr;
        dev.rescan(arr);
        auto*p=dev.get(backup);
        dev.pop(p->ptr);
      }
      void scan_defs(t_uberdev&dev){}
      t_class_class_stat*find_in_class(t_uberdev&dev,const string&name)
      {
        auto s=find_in_subs(dev,name);
        if(s)return s;
        auto p=find_in_parents(dev,name);
        if(p)
        {
          QapDebugMsg("hmm ... it's a good idea to do a search through the list of parents here?");
          QapDebugMsg("debug it!");
        }
        if(p)return p;
        return nullptr;
      }
      t_class_class_stat*find_in_scope(t_uberdev&dev,const string&name)
      {
        auto*pout=find_in_subs(dev,name);
        if(pout)return pout;
        for(int i=0;i<parents.size();i++)
        {
          auto&ex=parents[i];
          pout=dev.get(ex)->find_in_scope(dev,name);
          if(pout)return pout;
        }
        return nullptr;
      }
      t_class_class_stat*find_in_subs(t_uberdev&dev,const string&name)
      {
        for(int i=0;i<subs.size();i++)
        {
          auto&ex=subs[i];
          auto ex_name=dev.get(ex)->get_name();
          if(name==ex_name)return ex;
        }
        return nullptr;
      }
      t_class_class_stat*find_in_parents(t_uberdev&dev,const string&name)
      {
        for(int i=0;i<parents.size();i++)
        {
          auto&ex=parents[i];
          auto fn=dev.get(ex)->get_full_name(dev);
          if(fn==name)return ex;
        }
        return nullptr;
      }
      string get_path(t_uberdev&dev)
      {
        vector<string> out;
        for(int i=0;i<path.size();i++)
        {
          qap_add_back(out)=dev.get(path[i])->get_name();
        }
        return out.empty()?"":join(out,"::")+"::";
      }
      string get_full_name(t_uberdev&dev)
      {
        return get_path(dev)+get_name();
      }
      string get_name()
      {
        return ptr->body.name;
      }
    };
    struct t_typedef_item{
      t_typedef_class_stat*ptr;
      vector<t_class_class_stat*> path;
      t_typedef_class_stat*pTarget0;
      t_class_class_stat*pTarget1;
    };
    vector<t_class_item> items;
    vector<t_typedef_item> def_items;
    vector<t_class_class_stat*> stack;
    void rescan(t_class_class_stat*pclass)
    {
      get(pclass)->rescan(*this);
    }
    vector<t_class_class_stat*> types;
    void rescan(t_class_stats&arr)
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(auto*p=t_class_class_stat::UberCast(ex.get()))
        {
          rescan(p);
          if(stack.empty())
          {
            qap_add_back(types)=p;
          }
          if(!stack.empty())
          {
            qap_add_back(get(stack.back())->subs)=p;
          }
        }
      }
    }
    int safe_get(t_class_class_stat*ptr)
    {
      for(int i=0;i<items.size();i++)
      {
        auto&ex=items[i];
        if(ex.ptr==ptr)return i;
      }
      auto n=items.size();
      qap_add_back(items).ptr=ptr;
      return n;
    }
    t_class_item*get(t_class_class_stat*ptr)
    {
      auto id=safe_get(ptr);
      return id<0?nullptr:&items[id];
    }
    int safe_get_with_body(t_class_class_stat*ptr)
    {
      auto fn=get(ptr)->get_full_name(*this);
      vector<int> out;
      for(int i=0;i<items.size();i++)
      {
        auto&ex=items[i];
        if(!ex.ptr->body.body)continue;
        if(ex.get_full_name(*this)==fn){
          qap_add_back(out)=i;
        }
      }
      QapAssert(!out.empty());
      return out.back();
      return -1;
    }
    t_class_item*get_with_body(t_class_class_stat*ptr)
    {
      auto id=safe_get_with_body(ptr);
      return id<0?nullptr:&items[id];
    }
    t_class_class_stat*find_target_in_outers(const string&name)
    {
      auto a=split(name,"::");
      auto a0=a[0];
      for(int i=0;i<stack.size();i++)
      {
        //if(!i)continue;//skip our class;
        auto id=stack.size()-i-1;
        auto&ex=stack[id];
        auto*t=get(ex);
        auto p=t->find_in_scope(*this,a0);
        if(!p)continue;;
        return p;
      }
      for(int i=0;i<types.size();i++)
      {
        auto&ex=types[i];
        if(a0!=get(ex)->get_name())continue;
        auto*retval=find_by_full_name(get(ex)->get_path(*this)+name);
        return retval;
      }
      return nullptr;
    }
    t_class_class_stat*find_by_full_name(const string&fullname)
    {
      vector<string> out;
      for(int i=0;i<items.size();i++)
      {
        auto&ex=items[i];
        auto fn=ex.get_full_name(*this);
        if(fn==fullname)return ex.ptr;
      }
      QapNoWay();
      return nullptr;
    }
    void push(t_class_class_stat*ptr)
    {
      qap_add_back(stack)=ptr;
    }
    void pop(t_class_class_stat*ptr)
    {
      QapAssert(!stack.empty());
      QapAssert(stack.back()==ptr);
      stack.pop_back();
    }
    struct t_stont_stack_item{
      int iter;
      vector<t_class_class_stat*>*ptr;
    };
    void show_tree_of_nested_types()
    {
      string prefix;
      vector<t_stont_stack_item> stack;
      vector<string> out;
      {
        auto&head=qap_add_back(stack);
        head.iter=0;
        head.ptr=&types;
      }
      for(;!stack.empty();)
      {
        //{auto&sbi=stack.back().iter;if(sbi)stack.back().iter++;}
        auto cur=stack.back();
        for(;cur.iter<cur.ptr->size();cur.iter++)
        {
          auto&ex=cur.ptr->at(cur.iter);
          auto t=get(ex);
          qap_add_back(out)=prefix+get(ex)->get_name();
          if(t->subs.empty())continue;
          cur.iter++;
          stack.back()=cur;
          auto&back=qap_add_back(stack);
          back.iter=0;
          back.ptr=&t->subs;
          prefix+="  ";
          break;
        }
        if(cur.ptr==stack.back().ptr)if(cur.iter==cur.ptr->size())
        {
          prefix=prefix.substr(0,prefix.size()-2);
          stack.pop_back();
        }
      }
      UberInfoBox("tree of nested types",join(out,"\n"));
      int gg=1;
    }
  };
  t_uberdev dev;
  void first_pass(t_class_stats&arr)
  {
    dev.rescan(arr);
    vector<string> out;
    for(int i=0;i<dev.items.size();i++)
    {
      auto&ex=dev.items[i];
      if(ex.parents.empty())continue;
      auto fn=ex.get_full_name(dev);
      qap_add_back(out)=fn;
      auto&arr=ex.parents;
      for(int i=0;i<arr.size();i++)
      {
        if(!(arr[i])){qap_add_back(out)="  `parent not found`";continue;}
        qap_add_back(out)="  "+dev.get(arr[i])->get_full_name(dev);
      }
    }
    string types=join(out,"\n");
    UberInfoBox("types with parents",types);
    int gg=1;
    dev.show_tree_of_nested_types();
  }
};
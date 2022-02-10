class t_expr_visitor:public t_branch_lexem::i_expr_visitor{
public:
  t_context&con;
  vector<t_branch_head_ptr>&ptrs;
public:
  void Do(t_var_expr*p)
  {
    int temp_int_b=0;int temp_int_b=0;
    auto res=branch_exec(con.Env,ptrs,*p,false,temp_int_b);
  }
  void Do(t_string_expr*p){QapNoWay();}
  void Do(t_num_expr*p){QapNoWay();}
};
class t_oper_visitor:public t_branch_lexem::i_oper_visitor{
public:
  t_context&con;
  vector<t_branch_head_ptr>&ptrs;
public:
  void Do(t_set_oper*p)
  {
    t_expr_visitor::t_dev dev{con,ptrs};
    t_expr_visitor V{dev};
    p->value->Use(V);
  }
  void Do(t_inc_oper*p){QapNoWay();}
  void Do(t_dec_oper*p){QapNoWay();}
};
class t_line_visitor:public t_branch_lexem::i_line_visitor{
public:
  t_context&con;
  vector<t_branch_head_ptr>&ptrs;
  bool ok;
  vector<TAutoPtr<void>> vars;
public:
  void Do(t_alias*p)
  {
    ok=TPageWithBranchLexV03::add_alias_form_ast(con,p->body,ptrs,vars);
  }
  void varexpr_set_varexpr(t_line*p,t_var_expr*pvarexpr)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    auto b=branch_exec(con.Env,ptrs,*pvarexpr,false,temp_int_b);
    if(!b.ok)return;
    QapAssert(a.ok&&b.ok);
    if(!a.ok||!b.ok)return;
    auto the_same_types=a.ptr.pType==b.ptr.pType;
    if(!the_same_types)
    {
      string line;
      bool ok=save_obj(con.Env,*p,line);
      QapAssert(ok);
      string msg=(
        "end types of expression not equal:\n"
        "bef.type:\n  "
        +a.ptr.pType->GetFullName()+"\n\n"
        "aft.type:\n  "
        +b.ptr.pType->GetFullName()+"\n\n"
        "in this code line:\n  "+
        line
      );
      QapDebugMsg(msg);
      return;
    }
    if(the_same_types)
    {
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=*(TYPE*)b.ptr.pValue;ok=true;return;}
      F(int)F(string)F(bool)F(real)F(char)F(uchar)F(QapColor)
      #undef F
    }
    auto ok=unsafe_QapClone(con.Env,a.ptr,b.ptr);
    QapAssert(ok);
    int gg=1;
    ok=true;
  }
  bool do_varexpr_set_varexpr(t_line*p)
  {
    auto*popt=p->opt.get();if(!popt)return false;
    #define F(TYPE,NAME,VALUE)auto*NAME=UberGet<TYPE>(VALUE);if(!NAME)return false;
    F(t_set_oper,psetoper,popt->value);
    F(t_var_expr,pvarexpr,psetoper->value);
    #undef F
    varexpr_set_varexpr(p,pvarexpr);
    return true;
  }
  void varexpr_set_numexpr(t_line*p,t_num_expr*pexpr)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    auto v=SToI(pexpr->value);
    auto*a_type_factory=a.ptr.pType->Factory.get();
    #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=v;ok=true;return;}
    F(int)F(bool)F(real)F(char)F(uchar)F(QapColor)
    #undef F
    // fail
    {
      string line;
      bool ok=save_obj(con.Env,*p,line);
      QapAssert(ok);
      string msg=(
        "attempt to set 'int' into '"+a.ptr.pType->GetFullName()+"' failed:\n"
        "in this code line:\n  "+
        line
      );
      QapDebugMsg(msg);
    }
    ok=false;
  }
  bool do_varexpr_set_numexpr(t_line*p)
  {
    auto*popt=p->opt.get();if(!popt)return false;
    #define F(TYPE,NAME,VALUE)auto*NAME=UberGet<TYPE>(VALUE);if(!NAME)return false;
    F(t_set_oper,psetoper,popt->value);
    F(t_num_expr,pnumexpr,psetoper->value);
    #undef F
    varexpr_set_numexpr(p,pnumexpr);
    return true;
  }
  bool do_varexpr_dec(t_line*p)
  {
    auto*popt=p->opt.get();if(!popt)return false;
    #define F(TYPE,NAME,VALUE)auto*NAME=UberGet<TYPE>(VALUE);if(!NAME)return false;
    F(t_dec_oper,pdecoper,popt->value);
    #undef F
    varexpr_dec(p);
    return true;
  }
  void varexpr_dec(t_line*p)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    //check
    {
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){auto&v=*(TYPE*)a.ptr.pValue;v--;ok=true;return;}
      F(int)F(real)F(char)F(uchar)
      #undef F
    }
    ok=false;
  }
  bool do_varexpr_inc(t_line*p)
  {
    auto*popt=p->opt.get();if(!popt)return false;
    #define F(TYPE,NAME,VALUE)auto*NAME=UberGet<TYPE>(VALUE);if(!NAME)return false;
    F(t_inc_oper,pincoper,popt->value);
    #undef F
    varexpr_inc(p);
    return true;
  }
  void varexpr_inc(t_line*p)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    //check
    {
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){auto&v=*(TYPE*)a.ptr.pValue;v++;ok=true;return;}
      F(int)F(real)F(char)F(uchar)
      #undef F
    }
    ok=false;
  }
  void varexpr_single(t_line*p)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    ok=true;
  }
  void Do(t_line*p)
  {
    bool ok_vv=do_varexpr_set_varexpr(p);
    if(ok_vv)return;
    bool ok_vn=do_varexpr_set_numexpr(p);
    if(ok_vn)return;
    bool ok_vd=do_varexpr_dec(p);
    if(ok_vd)return;
    bool ok_vi=do_varexpr_inc(p);
    if(ok_vi)return;
    if(!p->opt)
    {
      varexpr_single(p);
    }
    int wtf=1;
  }
};
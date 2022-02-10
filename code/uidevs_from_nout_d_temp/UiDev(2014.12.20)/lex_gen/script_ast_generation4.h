class t_line_visitor:public t_branch_lexem::i_line_visitor{
public:
  class t_expr_visitor:public t_branch_lexem::i_expr_visitor{
  public:
    t_line_visitor&dev;
  public:
    void Do(t_var_expr*p){dev.Do(p);}
    void Do(t_string_expr*p){dev.Do(p);}
    void Do(t_num_expr*p){dev.Do(p);}
  };
  class t_oper_visitor:public t_branch_lexem::i_oper_visitor{
  public:
    t_line_visitor&dev;
  public:
    void Do(t_set_oper*p){dev.Do(p);}
    void Do(t_inc_oper*p){dev.Do(p);}
    void Do(t_dec_oper*p){dev.Do(p);}
  };
public:
  t_context&con;
  vector<t_branch_head_ptr>&ptrs;
  t_line*pline;
  bool ok;
  vector<TAutoPtr<void>> vars;
public:
  //t_line_visitor
public:
  void Do(t_alias*p)
  {
    ok=TPageWithBranchLexV03::add_alias_form_ast(con,p->body,ptrs,vars);
  }
  void Do(t_var_expr*p)
  {
    //auto*pline=get<t_line>();
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
    if(!a.ok)return;
    auto b=branch_exec(con.Env,ptrs,*p,false,temp_int_b);
    if(!b.ok)return;
    QapAssert(a.ok&&b.ok);
    if(!a.ok||!b.ok)return;
    auto the_same_types=a.ptr.pType==b.ptr.pType;
    if(!the_same_types)
    {
      string line;
      bool ok=save_obj(con.Env,*pline,line);
      QapAssert(ok);
      string msg=(
        "end types of expression not equal:\n"
        "bef.type:\n  "
        +a.ptr.pType->GetFullName()+"\n\n"
        "aft.type:\n  "
        +b.ptr.pType->GetFullName()+"\n\n"
        "in this line of code:\n  "+
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
  void Do(t_line*p)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    if(!p->opt){ok=true;return;}
    pline=p;
    t_oper_visitor V{*this};
    p->opt->Use(V);
  }
public:
  //t_oper_visitor
public:
  void Do(t_set_oper*p)
  {
    t_expr_visitor V{*this};
    p->value->Use(V);
  }
  void Do(t_inc_oper*p)
  {
    DoIncDec(pline,+1);
  }
  void Do(t_dec_oper*p)
  {
    DoIncDec(pline,-1);
  }
  void DoIncDec(t_line*p,int dv)
  {
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
    if(!a.ok)return;
    //check
    {
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){auto&v=*(TYPE*)a.ptr.pValue;v+=dv;ok=true;return;}
      F(int)F(real)F(char)F(uchar)
      #undef F
    }
    ok=false;
  }
public:
  //t_expr_visitor
public:
  void Do(t_num_expr*p)
  {
    //auto*pline=get<t_line>();
    int temp_int_a=0;int temp_int_b=0;
    auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
    if(!a.ok)return;
    auto v=SToI(p->value);
    auto*a_type_factory=a.ptr.pType->Factory.get();
    #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=TYPE(v);ok=true;return;}
    F(int)F(bool)F(real)F(char)F(uchar)F(QapColor)
    #undef F
    // fail
    {
      string line;
      bool ok=save_obj(con.Env,*p,line);
      QapAssert(ok);
      string msg=(
        "attempt to set 'int' into '"+a.ptr.pType->GetFullName()+"' failed:\n"
        "in this line of code:\n  "+
        line
      );
      QapDebugMsg(msg);
    }
    ok=false;
  }
};
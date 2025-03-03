struct t_field{
  string type;
  string name;
  int offset;
  t_field():offset(-1){}
  void set(const string&t,const string&n){type=t;name=n;}
};
struct t_struct{
  string name;
  int size;
  vector<t_field> fields;
  t_struct():size(-1){}
  PRO_FUNCGEN_GETP_BY_FIELD(t_field,name2field,fields,const string&,name);
};
struct t_ctti{
  vector<t_struct> structs;
  PRO_FUNCGEN_GETP_BY_FIELD(t_struct,name2struct,structs,const string&,name);
  t_field*field2field(const string&struct_type,const string&field)
  {
    auto*p=name2struct(struct_type);QapAssert(p);
    auto*pf=p->name2field(field);QapAssert(pf);
    return pf;
  }
  string field2type(const string&struct_type,const string&field)
  {
    return field2field(struct_type,field)->type;
  }
  int field2offset(const string&struct_type,const string&field)
  {
    return field2field(struct_type,field)->offset;
  }
  int type2size(const string&type)
  {
    if(type=="int")return 1;
    auto*p=name2struct(type);QapAssert(p);
    if(p->size==-1){
      calc_size(*p);
    }else{QapAssert(p->size>0);}
    return p->size;
  }
  void calc_size(t_struct&ref){
    static const int WIP=-2;
    ref.size=WIP;
    int out=0;auto&arr=ref.fields;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex.offset=out;
      auto tmp_size=type2size(ex.type);
      if(WIP==tmp_size)QapDebugMsg("recursion detected:\n  type: "+ex.type);
      if(-1==tmp_size)
      {
        calc_size(*name2struct(ex.type));
        tmp_size=type2size(ex.type);
      }
      out+=tmp_size;
    }
    ref.size=out;
  }
  void calc_size()
  {
    auto&arr=structs;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(-1!=ex.size)continue;
      calc_size(ex);
    }
  }
};
#define t_struct_xxx(xxx)struct t_##xxx{int v;t_ctti&ctti;t_##xxx(t_ctti&ctti):v(0),ctti(ctti){}t_##xxx(int v,t_ctti&ctti):v(v),ctti(ctti){}t_struct_xx_oper(xxx,[]);t_struct_xx_oper(xxx,());};
#define t_struct_xx_oper(xxx,oper)t_##xxx operator##oper##(int value)const{return t_##xxx(value,ctti);}
t_struct_xxx(reg);t_struct_xxx(mem);t_struct_xxx(raw);t_struct_xxx(ptr_reg);
#define t_struct_xx_oper_reg(oper)t_ptr operator##oper##(t_reg&reg)const{return t_ptr(reg.v);}
struct t_reg_offset{
  int reg;
  int offset;
  string type;
  t_ctti&ctti;
  t_reg_offset(t_ctti&ctti):ctti(ctti){}
  t_reg_offset&set_type(const string&tn){type=tn;return *this;};
};
struct t_ptr_reg_offset:t_reg_offset{
  t_ptr_reg_offset(const t_reg_offset&ref):t_reg_offset(ref){}
  t_ptr_reg_offset(const t_ptr_reg_offset&ref):t_reg_offset(ref){}
  t_ptr_reg_offset operator[](const char*field_name)const{
    t_ptr_reg_offset tmp(*this);
    tmp.offset+=ctti.field2offset(type,field_name);
    tmp.type=ctti.field2type(type,field_name);
    //QapDebugMsg("tmp.offset+=field2offset(field_name)");
    return tmp;
  }
  t_ptr_reg_offset&set_type(const string&tn){type=tn;return *this;};
};
friend t_reg_offset operator-(const t_reg&a,int offset){t_reg_offset tmp(a.ctti);tmp.reg=a.v;tmp.offset=-offset;return tmp;}
friend t_reg_offset operator+(const t_reg&a,int offset){t_reg_offset tmp(a.ctti);tmp.reg=a.v;tmp.offset=+offset;return tmp;}
friend t_reg_offset operator-(const t_reg&a,const t_raw&offset){t_reg_offset tmp(a.ctti);tmp.reg=a.v;tmp.offset=-offset.v;return tmp;}
friend t_reg_offset operator+(const t_reg&a,const t_raw&offset){t_reg_offset tmp(a.ctti);tmp.reg=a.v;tmp.offset=+offset.v;return tmp;}
struct t_ptr{
  t_ctti&ctti;
  t_ptr(t_ctti&ctti):ctti(ctti){}
  //int v;t_ptr():v(0){}t_ptr(int v):v(v){}
  t_ptr_reg operator[](const int&reg)const{return t_ptr_reg(reg,ctti);}
  t_ptr_reg operator()(const int&reg)const{return t_ptr_reg(reg,ctti);}
  t_ptr_reg operator[](const t_reg&reg)const{return t_ptr_reg(reg.v,ctti);}
  t_ptr_reg operator()(const t_reg&reg)const{return t_ptr_reg(reg.v,ctti);}
  t_ptr_reg_offset operator[](const t_reg_offset&ref)const{return ref;}
  t_ptr_reg_offset operator()(const t_reg_offset&ref)const{return ref;}
  
};
#undef t_struct_xx_oper_reg
#define t_struct_xx_oper_pro(oper)template<unsigned N>t_raw_pro operator##oper##(const char(&arr)[N])const{return t_raw_pro(arr);}
struct t_raw_pro:t_raw{
  string label;
  t_raw_pro(t_ctti&ctti):t_raw(ctti){}
  t_raw_pro(const string&s,t_ctti&ctti):label(s),t_raw(ctti){}
  t_struct_xx_oper(raw,[]);t_struct_xx_oper(raw,());
  t_struct_xx_oper_pro([]);t_struct_xx_oper_pro(());
};
#undef t_struct_xx_oper_pro
#undef t_struct_xx_oper
#undef t_struct_xxx
static bool test_cmd(const string&cmd,const char*p)
{
  string s=p;
  auto e=s.find('(');
  if(e!=s.npos)return s.substr(0,e)==cmd;
  QapNoWay();
  return false;
}

struct i_conv_label_to_cmd{
  virtual int conv(const string&s)const=0;
  int conv(unsigned value)const{return value;}
  int conv(int value)const{return value;}
  int conv(const char*p)const{return conv(string(p));}
  int conv(const t_raw&ref)const{return ref.v;}
  int conv(const t_reg&ref)const{return ref.v;}
  int conv(const t_mem&ref)const{return ref.v;}
  int conv(const t_ptr_reg&ref)const{return ref.v;}
  int conv(const t_raw_pro&ref)const{return conv(ref.label);}
};

struct t_crap_base{
  string cmd;int id;
  t_crap_base(const string&cmd):cmd(cmd),id(-1){}
  template<class TYPE>static TYPE*ref2ptr(TYPE&ref);
  template<class TYPE>static int conv(TYPE*pself,const string&cmd){
    int id=-1;
    int cur_id=0;
    auto&ctti=*(t_ctti*)nullptr;
    t_reg reg(ctti);
    t_mem mem(ctti);
    t_raw raw(ctti);
    t_ptr ptr(ctti);
    int dest=0;int src=0;int a=0;int b=0;
    //#define ptr(REG)mem[reg[REG]]
    #define IS_SAME(A,B)std::is_same<decltype(A),decltype(B)>::value
    #define F(BODY)if(IS_SAME(pself,ref2ptr(x##BODY)))if(test_cmd(cmd,#BODY)){id=cur_id;}cur_id++;
    CMDS(F);
    #undef F
    #undef IS_SAME
    //#undef ptr
    if(id<0)QapDebugMsg("cmd \""+cmd+"\" - not found");
    return id;
  }
  virtual t_cmd get_cmd(const i_conv_label_to_cmd&cl2cmd)=0;
  virtual bool is_lable()const{return false;}
};

template<class TYPE>struct t_str{int v;static const bool flag=false;};template<int N>struct t_str<const char(&)[N]>{int v;typedef int cstr_label;static const bool flag=true;};

#define GET_CMD_IMPL(CODE)t_cmd get_cmd(const i_conv_label_to_cmd&cl2cmd){t_cmd cmd;cmd.id=id;{CODE};return cmd;}
#define CONV_PARAM(cmd,dest,a){cmd.dest=cl2cmd.conv(a);}
/*
{
  typedef decltype(a) type_of_a;\
  typedef t_str<decltype(a)> cstr_of_a;\
  __if_not_exists(cstr_of_a::v){cmd.dest=cl2cmd.conv(a);}\
  __if_exists(type_of_a::v){cmd.dest=a.v;}\
  __if_exists(type_of_a::label){cmd.dest=cl2cmd.conv(a.label);}\
  __if_exists(cstr_of_a::cstr_label){cmd.dest=cl2cmd.conv(a);}\
}*/

template<class T>struct is_castable_to_raw{static const bool value=false;};
#define F(TYPE)template<>struct is_castable_to_raw<TYPE>{static const bool value=true;};
F(int)F(unsigned)F(char const*)F(char*)F(string)//F(const int&)F(const unsigned&)
#undef F

template<class T,bool pro=std::is_same<T,t_raw_pro>::value,bool num=is_castable_to_raw<T>::value||t_str<T>::flag>struct unpro{
  typedef typename std::remove_const<T>::type type;
};
template<class T>struct unpro<T,true,false>{typedef t_raw type;};
template<class T>struct unpro<T,false,true>{typedef t_raw type;};

#define F(T)unpro<T>::type
template<class A,class B,class C>static int conv_crap3_to_cmd(const string&cmd){return t_crap_base::conv((t_crap3<F(A),F(B),F(C)>*)nullptr,cmd);}
template<class A,class B        >static int conv_crap2_to_cmd(const string&cmd){return t_crap_base::conv((t_crap2<F(A),F(B)>     *)nullptr,cmd);}
template<class A                >static int conv_crap1_to_cmd(const string&cmd){return t_crap_base::conv((t_crap1<F(A)>          *)nullptr,cmd);}
#undef F

#define CTOR_IMPL0()t_crap_base(cmd){id=conv(this,cmd);}
#define CTOR_IMPL1()t_crap_base(cmd){id=conv_crap1_to_cmd<decltype(a)    >(cmd);}
#define CTOR_IMPL2()t_crap_base(cmd){id=conv_crap2_to_cmd<decltype(a),decltype(b)  >(cmd);}
#define CTOR_IMPL3()t_crap_base(cmd){id=conv_crap3_to_cmd<decltype(a),decltype(b),decltype(c)>(cmd);}

struct t_crap0:public t_crap_base{
  t_crap0(const string&cmd):CTOR_IMPL0();
  GET_CMD_IMPL({});
};
template<class A>
struct t_crap1:public t_crap_base{
  A a;
  t_crap1<A>(const string&cmd,A na):a(na),CTOR_IMPL1();
  GET_CMD_IMPL(CONV_PARAM(cmd,dest,a));
};
template<>
struct t_crap1<t_ptr_reg_offset>:public t_crap_base{
  typedef t_ptr_reg_offset A;
  A a;
  t_crap1<A>(const string&cmd,A na):a(na),CTOR_IMPL1();
  t_cmd get_cmd(const i_conv_label_to_cmd&cl2cmd)
  {
    t_cmd cmd;cmd.id=id;
    cmd.dest=a.reg;
    cmd.a=a.offset;
    return cmd;
  }
};

template<class A,class B>
struct t_crap2:public t_crap_base{
  A a;B b;
  t_crap2<A,B>(const string&cmd,A na,B nb):a(na),b(nb),CTOR_IMPL2();
  GET_CMD_IMPL({CONV_PARAM(cmd,dest,a);CONV_PARAM(cmd,a,b);});
};
template<class A>
struct t_crap2<A,t_ptr_reg_offset>:public t_crap_base{
  typedef t_ptr_reg_offset B;
  A a;B b;
  t_crap2<A,B>(const string&cmd,A na,B nb):a(na),b(nb),CTOR_IMPL2();
  t_cmd get_cmd(const i_conv_label_to_cmd&cl2cmd)
  {
    t_cmd cmd;cmd.id=id;
    CONV_PARAM(cmd,dest,a);
    cmd.a=b.reg;
    cmd.b=b.offset;
    return cmd;
  }
};
template<class B>
struct t_crap2<t_ptr_reg_offset,B>:public t_crap_base{
  typedef t_ptr_reg_offset A;
  A a;B b;
  t_crap2<A,B>(const string&cmd,A na,B nb):a(na),b(nb),CTOR_IMPL2();
  t_cmd get_cmd(const i_conv_label_to_cmd&cl2cmd)
  {
    t_cmd cmd;cmd.id=id;
    cmd.dest=a.reg;
    cmd.a=a.offset;
    CONV_PARAM(cmd,b,b);
    return cmd;
  }
};
template<class A,class B,class C>
struct t_crap3:public t_crap_base{
  A a;B b;C c;
  t_crap3<A,B,C>(const string&cmd,A na,B nb,C nc):a(na),b(nb),c(nc),CTOR_IMPL3();
  GET_CMD_IMPL({CONV_PARAM(cmd,dest,a);CONV_PARAM(cmd,a,b);CONV_PARAM(cmd,b,c)});
};
#undef CTOR_IMPL

#define F(UNUSED,CMD)template<class A,class B>static t_crap2<A,B> x##CMD(A a,B b){return t_crap2<A,B>(#CMD,a,b);};
CMDS_LIKE_MOV(UNUSED,F)
F(UNUSED,lea)
#undef F

#define F(UNUSED,CMD)template<class A>static t_crap1<A> x##CMD(A a){return t_crap1<A>(#CMD,a);};
CMDS_ONEPARAM_IS_INP(UNUSED,F)
CMDS_ONEPARAM_IS_OUT(UNUSED,F)
F(UNUSED,pushlea)
#undef F

#define F(UNUSED,CMD)static t_crap0 x##CMD(){return t_crap0(#CMD);};
CMDS_ZERO(UNUSED,F)
#undef F

#define F(UNUSED,CMD)template<class A,class B,class C>static t_crap3<A,B,C> x##CMD(A a,B b,C c){return t_crap3<A,B,C>(#CMD,a,b,c);};
CMDS_LIKE_ADD(UNUSED,F)
#undef F

struct t_label:public t_crap_base{
  string name;
  int pos;
  t_label(const string&name,int pos):t_crap_base("label"){this->name=name;this->pos=pos;id=t_crap0("label").id;}
  GET_CMD_IMPL({})
  virtual bool is_lable()const{return true;}
};

struct t_esp_info{
  bool inside_call_scope;
  vector<string>*parr;
  int n;
  t_esp_info():inside_call_scope(false),parr(nullptr),n(0){};
  void caller_scope_bef(){
    QapAssert(!inside_call_scope);inside_call_scope=true;
    static auto allowed=split("push,pushlea,nop,call,label,mov,lea",",");
    parr=&allowed;
    n=0;
  }
  void caller_scope_aft(){QapAssert(inside_call_scope);inside_call_scope=false;parr=nullptr;}
};

struct t_app_builder:i_conv_label_to_cmd{
  vector<unique_ptr<t_crap_base>> out; // NOTE: beg_eip=prov->out.size(); //loop(beg_eip); 
  t_ctti ctti;
  t_esp_info esp_info;
  t_app_builder&label(const string&name){qap_add_back(out).reset(new t_label(name,out.size()));return *this;}

  #define ADD(CMD,DELC_PARAMS,PARAMS)t_app_builder&CMD##DELC_PARAMS{auto v=x##CMD##PARAMS;esp_check(v);qap_add_back(out).reset(new decltype(v)(v));return *this;}

  #define F(UNUSED,CMD)template<class A,class B>ADD(CMD,(A a,B b),(a,b));
  CMDS_LIKE_MOV(UNUSED,F)
  F(UNUSED,lea);
  #undef F

  #define F(UNUSED,CMD)template<class A>ADD(CMD,(A a),(a));
  CMDS_ONEPARAM_IS_INP(UNUSED,F)
  CMDS_ONEPARAM_IS_OUT(UNUSED,F)
  F(UNUSED,pushlea)
  #undef F

  #define F(UNUSED,CMD)ADD(CMD,(),());
  CMDS_ZERO(UNUSED,F)
  #undef F

  #define FOR_CMD_LIKE_ADD(UNUSED,CMD)template<class A,class B,class C>ADD(CMD,(A a,B b,C c),(a,b,c));
  CMDS_LIKE_ADD(UNUSED,FOR_CMD_LIKE_ADD)
  #undef FOR_CMD_LIKE_ADD
  
  #undef ADD
  bool esp_check(t_crap_base&ref)
  {
    if(!esp_info.parr)return true;
    auto name=split(ref.cmd,"(")[0];
    if(qap_find_str(*esp_info.parr,name).size())return true;
    QapDebugMsg("this cmd unallowed inside caller scope.\n  cmd: "+name+"\n\n"+ref.cmd);
    return false;
  }
  vector<t_cmd> get()const{
    vector<t_cmd> tmp;
    for (int i=0;i<out.size();i++){
      auto&ex=out[i];
      t_crap_base*ptr=ex.get();
      auto cmd=ptr->get_cmd(*this);
      qap_add_back(tmp)=cmd;
    }
    return tmp;
  }
  int conv(const string&s)const{return conv_label_to_cmd(s);}
  int conv_label_to_cmd(const string&label)const{
    for(int i=0;i<out.size();i++)if(out[i]->is_lable())if(auto*p=(t_label*)out[i].get())if(p->name==label)return i;
    QapNoWay();
    return -1;
  }
};
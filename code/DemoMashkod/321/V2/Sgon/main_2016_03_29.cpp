#include "StdAfx.h"

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_12_20.h"
#else
//=====>>>>>main_2016_03_29
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
#include "t_simple_stat_lex.inl"
//<<<<<=====main_2016_03_29
#endif //DEF_BUILD_MACRO//

#define PRO_FUNCGEN_OVERLOAD_VEC(func)template<class TYPE>void func(const vector<TYPE>&arr){for(int i=0;i<arr.size();i++)func(arr[i]);}

#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_CHECK_BY_FIELD(check_vec_obj_field_value,arr,field_type,field)\
  bool check_vec_obj_field_value(field_type value)\
  {\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      return true;\
    }\
    return false;\
  }

#define STAT_LIST(F)\
F(t_var_stat)\
F(t_sep_stat)\
F(t_block_stat)\
F(t_expr_stat)\
F(t_set_oper_stat)\
F(t_func_stat)\
F(t_oper_stat)\
F(t_ret_stat)\
F(t_null_stat)\
F(t_postfix_oper_stat)\
F(t_break_stat)\
F(t_continue_stat)\
F(t_for_stat)\
F(t_if_stat)\
F(t_struct_stat)\
F(t_template_stat)\
// STAT_LIST //

#define EXPR_LIST(F)\
F(t_int_expr)\
F(t_char_expr)\
F(t_bool_expr)\
F(t_string_expr)\
F(t_real_expr)\
F(t_var_expr)\
F(t_block_expr)\
F(t_call_expr)\
// EXPR_LIST //

struct t_core:t_simple_stat_lex{
  struct t_var;struct t_func;struct t_field;struct t_tmpvar;struct t_frame;struct t_struct;
  template<class TYPE>string lex2str(TYPE&ref){string out;save_obj(Env,ref,out);return out;}
  template<class TYPE>void EstimateFuncIsNoImplForLexer(TYPE&ref){
    string out=lex2str(ref);
    QapDebugMsg("no impl. TYPE = \""+Sys$$<TYPE>::GetRTTI(Env)->GetFullName()+"\"\nContent:\n"+out);
  }
  struct t_ecxval_scope{
    string&ref;string old;
    t_ecxval_scope(string&ref,const string&newval):ref(ref){old=std::move(ref);ref=newval;}
    ~t_ecxval_scope(){ref=std::move(old);}
  };
  #define QapLexError(msg)QapDebugMsg(string(msg)+"\n\ninside function: \""+get_cur_full_proc_name()+"\"\n\n----------\n"+lex2str(ref));
  #define ECX_VAL_SCOPE(VALUE)t_ecxval_scope ecxval_scope(ecxval,VALUE);
  #define T_FRAME_SCOPE_STAT()t_frame_scope sys_frame_scope(*this,true);
  #define T_FRAME_SCOPE()t_frame_scope sys_frame_scope(*this,false);
  static bool has_scope(const string&s){
    auto n=s.size();
    if(n<2)return false;
    if(s[0]!='{')return false;
    if(s[n-1]=='}')return true;
    if(s[n-1]!='\n')return false;
    return s[n-2]=='}';
  };
  static bool need_declare_tmpvars(const vector<t_tmpvar>&arr){for(int i=0;i<arr.size();i++)if(need_declare(arr[i]))return true;return false;}
  struct t_frame_scope{
    t_core&core;
    t_frame_scope(t_core&core,bool tmpvar_owner=false):core(core){core.frames_push();core.top.is_tmpvar_owner=tmpvar_owner;}
    ~t_frame_scope(){bool skip=(core.top.out.empty()||has_scope(core.top.out))&&!need_declare_tmpvars(core.top.tmpvars);if(!skip)core.add(1)+="{";core.frames_pop();if(!skip)core.add()+="}";}
  };
  #define T_FRAME_GRAB(out)t_frame_scope_grab sys_frame_scope_grab(*this,out);
  struct t_frame_scope_grab{
    t_core&core;
    string&out;
    t_frame_scope_grab(t_core&core,string&out):core(core),out(out){core.frames_push();}
   ~t_frame_scope_grab(){out=std::move(core.top.out);core.frames_pop();}
  };
  void grab_funcs(t_command_block&ref){
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*ptr=ex.get();
      if(!ptr)continue;
      auto*pfs=t_func_stat::UberCast(ptr);
      if(!pfs)continue;
      auto&func=pfs->body;
      qap_add_back(top.funcs).set(func.type,func.name.value,func.params.arr);
    }
  }
  typedef t_simple_stat_lex::t_struct t_struct_lex;
  void grab_method(t_struct*ps,t_struct_lex::t_method&method_ref)
  {
    auto&ref=method_ref.body;
    qap_add_back(ps->methods).set(ref.type,ref.name.value,ref.params.arr);
  }
  void grab_field(t_struct_lex::t_field&field_ref)
  {
    auto&ref=field_ref.body;
    auto type=lex2str(ref.type);
    auto name=ref.name.value;
    qap_add_back(top.fields).set(type,name);
  }
  void grab_struct(t_struct_lex&ref)
  {
    t_struct out;
    QapAssert(get_cur_struct_name().empty());
    out.name=ref.name.value;
    QapAssert(ref.arr.empty());
    //use_arr(ref.fields);
    {
      QapAssert(top.fields.empty());
      auto&arr=ref.fields;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        grab_field(ex);
      }
    }
    out.fields=std::move(top.fields);
    //use_arr(ref.methods);
    {
      auto*ps=&out;
      auto&arr=ref.methods;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        grab_method(ps,ex);
      }
    }
    qap_add_back(structs)=out;
    add()+="{STRUCT("+quote(out.name)+"){";
    {
      frames_push();
      auto&arr=out.fields;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];add()+="FIELD("+quote(ex.type)+","+quote(ex.name)+");";
      }
      frames_pop();
    }
    add()+="}}\n";
  }
  void grab_structs(t_command_block&ref){
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*ptr=ex.get();
      if(!ptr)continue;
      auto*ps=t_struct_stat::UberCast(ptr);
      if(!ps)continue;
      grab_struct(ps->body);
    }
  }
  t_frame&get_cur_stat_frame(){if(top.is_tmpvar_owner)return top;for(int i=frames.size()-1;i>=0;i--){auto&ex=frames[i];if(ex.is_tmpvar_owner)return ex;}QapNoWay();return *(t_frame*)nullptr;}
  string get_cur_proc_name(){if(!top.proc_name.empty())return top.proc_name;for(int i=frames.size()-1;i>=0;i--){auto&ex=frames[i];if(!ex.proc_name.empty())return ex.proc_name;}QapNoWay();return "";}
  string get_cur_full_proc_name(){
    string params_str;
    for(int i=frames.size();i>=0;i--){
      auto&ex=qap_check_id(frames,i)?frames[i]:top;
      if(params_str.empty())params_str=ex.params.empty()?"":"("+ex.get_params_types_str()+")";
      if(ex.proc_name.empty())continue;
      return ex.proc_name+params_str;
    }
    QapNoWay();return "";
  }
  string get_cur_struct_name(){if(!top.struct_name.empty())return top.struct_name;for(int i=frames.size()-1;i>=0;i--){auto&ex=frames[i];if(!ex.struct_name.empty())return ex.struct_name;}return "";}
  string get_for_name(){for(int i=frames.size()-1;i>=0;i--){auto&ex=frames[i];if(!ex.for_name.empty())return ex.for_name;}QapNoWay();return "";}
  string get_if_name(){for(int i=frames.size()-1;i>=0;i--){auto&ex=frames[i];if(!ex.if_name.empty())return ex.if_name;}QapNoWay();return "";}
  t_struct*get_cur_struct(){
    auto cur_struct=get_cur_struct_name();
    if(cur_struct.empty())return nullptr;
    return name2struct(cur_struct);
  }
  t_func*get_method_by_fullname_and_params_types(const string&name,const vector<string>&params_types){
    if(name.find("::")==string::npos)return nullptr;
    auto parts=split(name,"::");auto sn=parts[0];QapAssert(parts.size()==2);
    auto*ps=name2struct(sn);
    if(!ps)return nullptr;
    return ps->get_method_by_name_and_params_types(parts[1],params_types);
  }
  bool check_method_fullname(const string&name){
    if(name.find("::")==string::npos)return nullptr;
    auto parts=split(name,"::");auto sn=parts[0];QapAssert(parts.size()==2);
    auto*ps=name2struct(sn);
    if(!ps)return nullptr;
    return ps->check_method(parts[1]);
  }
  t_func*get_func_by_name_and_params_types_raw(const string&name,const vector<string>&params_types){
    if(auto*p=top.get_func_by_name_and_params_types(name,params_types))return p;
    for(int i=frames.size()-1;i>=0;i--){
      auto&ex=frames[i];
      if(auto*p=ex.get_func_by_name_and_params_types(name,params_types))return p;
    }
    return nullptr;
  }
  t_func*get_func_by_name_and_params_types(const string&name,const vector<string>&params_types){
    if(auto*p=get_func_by_name_and_params_types_raw(name,params_types))return p;
    if(auto*ps=get_cur_struct()){
      if(auto*p=ps->get_method_by_name_and_params_types(name,params_types)){
        return p;
      }
    }
    if(auto*p=get_method_by_fullname_and_params_types(name,params_types))return p;
    if(auto*p=get_sys_func_by_name_and_params_types(name,params_types))return p;
    return nullptr;
  }
  bool get_func_by_name(const string&name){return check_func_name(name);}
  bool check_func_name(const string&name){
    if(auto ok=top.check_func_name(name))return ok;
    for(int i=frames.size()-1;i>=0;i--){
      auto&ex=frames[i];
      if(auto ok=ex.check_func_name(name))return ok;
    }
    if(auto*ps=get_cur_struct()){
      if(auto ok=ps->check_method(name))return ok;
    }
    if(auto ok=check_method_fullname(name))return ok;
    return check_sys_func_name(name);
  }
  string get_cur_result_type(){
    string rt=top.result_type;
    if(!rt.empty()||!top.proc_name.empty())return rt;         
    for(int i=frames.size()-1;i>=0;i--){           
      auto&ex=frames[i];                    
      string rt=ex.result_type;
      if(!rt.empty()||!ex.proc_name.empty())return rt;              
    }                                              
    return rt;                                      
  }
  #define NAME2PTR(t_field,field)                   \
  t_field*get_##field##_by_name(const string&name){ \
    auto*p=top.get_##field##_by_name(name);         \
    if(p||!top.proc_name.empty())return p;          \
    for(int i=frames.size()-1;i>=0;i--){            \
      auto&ex=frames[i];                            \
      if(p=ex.get_##field##_by_name(name))break;    \
      if(!ex.proc_name.empty())break;               \
    }                                               \
    return p;                                       \
  }                                                 \
  // NAME2PTR //
  NAME2PTR(t_field,field);
  NAME2PTR(t_var,param);
  NAME2PTR(t_var,var);
  NAME2PTR(t_tmpvar,tmpvar);
  #undef NAME2PTR
  bool is_reg(const string&s){
    return !qap_find_str(split("eax,ebx,ecx,edx",","),s).empty();
  }
  //string withnameprefix(const string&name){
  //  auto pv=get_var_by_name(name);
  //  auto pp=get_param_by_name(name);
  //  if(!pp&&!pv){QapDebugMsg("var or param not found!\n with name:\n"+name);}
  //  return (pp?param_prefix:varprefix)+name;
  //}
  void frames_push(){
    qap_add_back(frames)=top; top=t_frame();
  }
  static string str_shift(const string&text){
    const string ident="  ";
    if(text.empty())return "";
    bool tru=text.back()=='\n';
    auto t=tru?text.substr(0,text.size()-1):text;
    return ident+join(split(t,"\n"),"\n"+ident)+(tru?"\n":"");
  }
  void frames_pop(){
    QapAssert(frames.size());
    string tmp_var_decls;
    if(top.tmpvars.size())
    {
      auto tmpvars=top.tmpvars;
      frames_push();
      declare(tmpvars);
      tmp_var_decls=top.out;top=frames.back();
      frames.pop_back();
    }
    auto&b=frames.back();;
    auto tmp=tmp_var_decls+top.out;
    if(!has_scope(tmp))tmp=str_shift(tmp);
    auto top_out=b.out+tmp;
    if(!top_out.empty()){
      int gg=1;
    }
    top=b;
    top.out=top_out;
    frames.pop_back();
  }
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  template<class TYPE>void use(TYPE*ptr){if(!ptr)return;use(*ptr);}
  template<class TYPE>void use(TAutoPtr<TYPE>&ap){auto*ptr=ap.get();use(ptr);}
  template<class TYPE>void use_arr(vector<TYPE>&arr){
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      use(ex);
    }
  }
  template<class TYPE>void use_arr(vector<TAutoPtr<TYPE>>&arr){
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*ptr=ex.get();
      if(!ptr)continue;
      use(*ptr);
    }
  }
  static bool is_same_str(const string&a,const string&b,const string&c){return a==b&&b==c;}
  template<class TYPE>
  void use_lev(TYPE&ref)
  {
    use(ref.expr);
    t_retval accum;
    for(int i=0;i<ref.arr.size();i++)
    {
      accum=std::move(retval);
      auto&ex=ref.arr[i];
      bool empty_scope=false;
      {
        T_FRAME_SCOPE();
        use(ex.expr);
        auto rt=retval.getType();
        auto at=accum.getType();
        if(!is_same_str(rt,at,"int"))QapLexError("no impl for binoper: "+ex.oper.value+"\nwith types: ("+at+","+rt+")");
        //QapAssert(retval.is_int()&&accum.is_int());
        if(top.out.empty())empty_scope=true;
        if(!empty_scope&&!accum.reg.empty()){
          add(1)+="push("+accum.toStr()+");";
        }
      }
      //if(retval.reg.empty()){
      //  add()+="mov(eax,"+retval.toStr()+");";
      //  retval.set_reg("eax");
      //}
      string free_reg="eax";
      if(retval.reg=="eax")free_reg="ebx";
      if(!empty_scope&&!accum.reg.empty()){
        accum.set_reg(free_reg);
        add()+="pop("+accum.toStr()+");";
      }
      if(accum.reg.empty()){
        add()+="mov("+free_reg+","+accum.toStr()+");";
        accum.set_reg(free_reg);
      }
      #define F(OPER,NAME)if(#OPER==ex.oper.value){add()+=#NAME"("+accum.toStr()+","+retval.toStr()+");";retval=std::move(accum);continue;}
      F(+,add)F(-,sub)F(*,mul)F(/,div)F(%,mod)F(<=,nmore)F(>=,nless)F(>,more)F(<,less)F(==,eq)F(!=,neq)F(>>,shr)F(<<,shl)F(&,bwand)F(|,bwor)F(&&,and)F(||,or);
      #undef F
      QapLexError("no impl for binoper: "+ex.oper.value);
    }
  }
  void use(t_lev03&ref){
    use(ref.expr);
    if(ref.oper.empty())return;
    string value=retval.toStr();
    for(;;)
    {
      if("-"==ref.oper){add()+="inv(eax,"+retval.toStr()+");";retval.set_reg("eax");break;}
      if("!"==ref.oper){add()+="not(eax,"+retval.toStr()+");";retval.set_reg("eax");break;}
      if("+"==ref.oper){break;}
      QapLexError("no impl for unary operator: "+ref.oper);
      break;
    }
    //if(dev.isErr())return;
    //const auto&oper=p->oper;
    //if(oper.empty())return;
    //call_oneoper(oper,std::move(dev.expr_buff));
  }
  void use(t_lev05&ref){use_lev(ref);}
  void use(t_lev06&ref){use_lev(ref);}
  void use(t_lev07&ref){use_lev(ref);}
  void use(t_lev08&ref){use_lev(ref);}
  void use(t_lev09&ref){use_lev(ref);}
  void use(t_lev10&ref){use_lev(ref);}
  void use(t_lev11&ref){use_lev(ref);}
  void use(t_lev12&ref){use_lev(ref);}
  void use(t_lev13&ref){use_lev(ref);}
  void use(t_lev14&ref){use_lev(ref);}
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  struct t_retval{
    #define LIST(F)\
    F(reg  )\
    F(var  )\
    F(tmpvar)\
    F(param)\
    F(field)\
    F(num  )\
    F(str  )\
    F(func )\
    // LIST //
    #define F(reg)struct t_##reg{string value;t_##reg(const string&s){value=s;}};
    LIST(F);
    #undef F
    #define F(reg)string reg;
    LIST(F);
    #undef F
    t_core*pcore;
    t_retval(t_core*pcore=nullptr):pcore(pcore){off();}
    void off()
    {
      #define F(reg)reg="";
      LIST(F);
      #undef F
    }
    #define F(reg)void operator=(const t_##reg&ref){QapAssert(!ref.value.empty());off();reg=ref.value;}
    LIST(F);
    #undef F
    #define F(reg)void set_##reg(const string&ref){QapAssert(!ref.empty());off();reg=ref;}
    LIST(F);
    #undef F
    bool is_empty()const{
      #define F(reg)if(!reg.empty())return false;
      LIST(F);
      #undef F
      return true;
    }
    string toStr()const{
      #define F(reg)if(!reg.empty())return expr2str(pcore->reg##_prefix+reg);
      LIST(F);
      #undef F
      QapNoWay();
      return "";
    }
    string expr2str(const string&expr)const{auto arr=split(expr,".");string out=arr[0];for(int i=1;i<arr.size();i++)out+="[\""+arr[i]+"\"]";return out;}
    #define F(v,var)                                   \
    string v##expr2type()const{                        \
      auto arr=split(var,".");                         \
      auto head=arr[0];                                \
      auto*ptr=pcore->get_##var##_by_name(head);       \
      if(!ptr){QapDebugMsg("no way!\nhead = "+head);}  \
      if(arr.size()==1)return ptr->type;               \
      QapAssert(ptr->type!="int");                     \
      return usefields(ptr->type,arr);                 \
    }                                                  \
    // F //
    F(v,var);
    F(p,param);
    F(f,field);
    F(t,tmpvar);
    #undef F
    string usefields(const string&type,const vector<string>&arr)const{
      string cur_type=type;
      for(int i=1;i<arr.size();i++){
        auto*pt=pcore->name2struct(cur_type);QapAssert(pt);
        auto*pf=pt->name2field(arr[i]);if(!pf)QapDebugMsg(pt->name+"::"+arr[i]+" - field no found.expr:\n"+join(arr,"."));
        cur_type=pf->type;
      }
      return cur_type;
    }
    void add_field(const string&ref)
    {
      if(!var.empty())var+="."+ref;
      if(!param.empty())param+="."+ref;
      if(!field.empty())field+="."+ref;
    }
    void set_name(const string&name){
      off();
      #define NAMES(F)F(var)F(param)F(field)F(func)
      #define F(var)if(auto p=pcore->get_##var##_by_name(name)){var=name;return;};;
      NAMES(F);
      #undef F
      vector<string> arr;
      #define F(var)arr.push_back(#var);
      NAMES(F);
      #undef F
      #undef NAMES
      QapDebugMsg(join(arr," or ")+" not found!\n with name: "+name+"\n inside function: "+pcore->get_cur_full_proc_name());
    }
    bool is_eax()const{return reg=="eax";}
    bool is_ebx()const{return reg=="ebx";}
    bool is_ecx()const{return reg=="ecx";}
    bool is_edx()const{return reg=="edx";}
    bool is_complex()const{return !var.empty()||!param.empty()||!tmpvar.empty()||!field.empty();}
    bool is_int()const{return "int"==getType();}
    bool readonly()const{return !num.empty()||!func.empty()||!str.empty();}
    string get_non_empty_field_name()const{
      string out;
      #define F(reg)if(!reg.empty())out=#reg;
      LIST(F);
      #undef F
      return out;
    }
    string getType()const{
      string out=get_non_empty_field_name();
      if(out=="reg")return "int";// TODO: use assigned type from: get_reg_by_name()->type;
      if(out=="num")return "int";
      if(out=="str")return "string";
      if(out=="var")return vexpr2type();
      if(out=="tmpvar")return texpr2type();
      if(out=="param")return pexpr2type();
      if(out=="field")return fexpr2type();
      QapDebugMsg("no impl in t_retval::getType(): when !this->"+out+".empty()");
      return out;
    }
    #undef LIST
  };

  struct t_tmpvar{
    string type;
    string name;
    string out;
    t_retval retval;
    t_tmpvar&set(const string&t,const string&n,const string&o,const t_retval&r){type=t;name=n;out=o;retval=r;return *this;}
  };

  //void copy(...){QapNoWay();}

  struct t_var{
    string type;
    string name;
    void set(const string&t,const string&n){type=t;name=n;}
  };
  struct t_field{
    string type;
    string name;
    void set(const string&t,const string&n){type=t;name=n;}
  };
  struct t_func{
    string rettype;
    string name;
    vector<t_var> params; 
    PRO_FUNCGEN_GETP_BY_FIELD(t_var,get_param_by_name,params,const string&,name);
    void set(const string&rt,const string&n,const vector<t_param>&arr)
    {
      rettype=rt;
      name=n;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        qap_add_back(params).set(ex.type,ex.name.value);
      }
    }
    bool check(const vector<string>&params_types)const{
      if(params_types.size()!=params.size())return false;
      auto&arr=params_types;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(params[i].type!=ex)return false;
      }
      return true;
    }
    vector<string> get_params_types()const{vector<string> out;out.resize(params.size());for(int i=0;i<params.size();i++)out[i]=params[i].type;return out;}
    string get_params_types_str()const{return join(get_params_types(),",");}
    vector<string> get_params_names()const{vector<string> out;out.resize(params.size());for(int i=0;i<params.size();i++)out[i]=params[i].name;return out;}
    string get_params_names_str()const{return join(get_params_names(),",");}
  };
  struct t_struct{
    string name;
    vector<t_field> fields;
    vector<t_func> methods;
    PRO_FUNCGEN_GETP_BY_FIELD(t_field,name2field,fields,const string&,name);
    PRO_FUNCGEN_CHECK_BY_FIELD(check_method,methods,const string&,name);
    t_func*get_method_by_name_and_params_types(const string&method,const vector<string>&params_types){
      for(int i=0;i<methods.size();i++){
        auto&ex=methods[i];
        if(ex.name!=method)continue;
        if(ex.check(params_types))return &ex;
      }
      return nullptr;
    }
  };
  struct t_frame{
    string out;
    string ctor_impl;
    string proc_name;
    string if_name;
    string for_name;
    string struct_name;
    string result_type;
    vector<t_field> fields;
    vector<t_var> vars;
    vector<t_tmpvar> tmpvars;
    vector<t_var> params;
    vector<t_func> funcs;
    vector<t_tmpvar> call_params;
    bool is_tmpvar_owner;
    t_frame():is_tmpvar_owner(false){}
    PRO_FUNCGEN_GETP_BY_FIELD(t_tmpvar,get_tmpvar_by_name,tmpvars,const string&,name);
    PRO_FUNCGEN_GETP_BY_FIELD(t_var,get_var_by_name,vars,const string&,name);
    PRO_FUNCGEN_GETP_BY_FIELD(t_var,get_param_by_name,params,const string&,name);
    PRO_FUNCGEN_GETP_BY_FIELD(t_field,get_field_by_name,fields,const string&,name);
    PRO_FUNCGEN_CHECK_BY_FIELD(check_func_name,funcs,const string&,name);
    t_func*get_func_by_name_and_params_types(const string&name,const vector<string>&params_types){
      for(int i=0;i<funcs.size();i++){
        auto&ex=funcs[i];
        if(ex.name!=name)continue;
        if(ex.check(params_types))return &ex;
      }
      return nullptr;
    }
    //vector<string> get_list_of_params_types
    vector<string> get_params_types()const{vector<string> out;out.resize(params.size());for(int i=0;i<params.size();i++)out[i]=params[i].type;return out;}
    string get_params_types_str()const{return join(get_params_types(),",");}
    vector<string> get_params_names()const{vector<string> out;out.resize(params.size());for(int i=0;i<params.size();i++)out[i]=params[i].name;return out;}
    string get_params_names_str()const{return join(get_params_names(),",");}
    t_tmpvar&add_tmpvar(t_retval&retval,const string&out){return qap_add_back(tmpvars).set(retval.getType(),"tmp"+IToS(tmpvars.size()+100),out,retval);}
    t_tmpvar&add_tmpvar(const string&type){t_retval tmp;return qap_add_back(tmpvars).set(type,"tmp"+IToS(tmpvars.size()+100),"",tmp);}
    vector<string> get_call_params_types(){vector<string> out;auto&arr=call_params;for(int i=0;i<arr.size();i++){out.push_back(arr[i].type);}return out;}
  };
  //------------------------------------------------------------------------------
  vector<t_func> sysfuncs;
  vector<t_struct> structs;
  t_frame top;
  t_retval retval;
  string ecxval;
  vector<t_frame> frames;
  int for_counter;
  int if_counter;
  IEnvRTTI&Env;
  string tmpvar_prefix;string struct_prefix;string field_prefix;string var_prefix;string param_prefix;string reg_prefix;string num_prefix;string func_prefix;string str_prefix;
  t_core(IEnvRTTI&Env):Env(Env),struct_prefix("struct_"),field_prefix("field_"),var_prefix("var_"),param_prefix("param_"),func_prefix("func_"),for_counter(8000),if_counter(1000){retval.pcore=this;init();}
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  PRO_FUNCGEN_CHECK_BY_FIELD(check_sys_func_name,sysfuncs,const string&,name);
  PRO_FUNCGEN_GETP_BY_FIELD(t_struct,name2struct,structs,const string&,name);
  t_func*get_sys_func_by_name_and_params_types(const string&name,const vector<string>&params_types){
    for(int i=0;i<sysfuncs.size();i++){
      auto&ex=sysfuncs[i];
      if(ex.name!=name)continue;
      if(ex.check(params_types))return &ex;
    }
    return nullptr;
  }
  void addsysfunc(const string&func_stat_source){
    t_func_stat fs;
    string result=load_obj_ex(Env,fs,func_stat_source);
    auto&func=fs.body;
    qap_add_back(sysfuncs).set(func.type,func.name.value,func.params.arr);
  }
  void init()
  {
    addsysfunc("void __asm(string name){}");
  }
  struct t_adder{string&out;void operator+=(const string&s){out+=s+"\n";}void operator*=(const string&s){if(s.empty())return;out+=s+"\n";}};
  t_adder add(int id=0){t_adder tmp={!id?top.out:frames[frames.size()-id].out};return tmp;}
  t_adder ctor_impl(int id=0){t_adder tmp={!id?top.ctor_impl:frames[frames.size()-id].ctor_impl};return tmp;}
  void use(t_param&ref)
  {
    add()+="PARAM("+quote(ref.type)+","+param_prefix+ref.name.value+");";
    QapAssert(!get_cur_proc_name().empty())
    qap_add_back(top.params).set(ref.type,ref.name.value);
  }
  void use(t_func_stat::t_impl&ref)
  {
    frames_push();
    auto curstruct=get_cur_struct_name();
    auto proc_name=func_prefix+(curstruct.empty()?"":curstruct+"::")+ref.name.value;
    top.proc_name=proc_name;
    declare_result(ref.type);
    use_arr(ref.params.arr);
    add(1)+="{proc(\""+proc_name+"("+top.get_params_types_str()+")\"){";
    use(ref.body);
    frames_pop();
    add()+="}}\n";
  }
  // === I_EXPR === //
  void use(i_expr&ref){
    #define F(T)if(auto*ptr=T::UberCast(&ref))return use(*ptr);
    EXPR_LIST(F);
    #undef F
  }
  void use(t_int_expr&ref){retval.set_num(ref.value);}
  static string char_to_num(const string&s){
    QapAssert(s.size()>2);QapAssert(s.front()=='\'');QapAssert(s.back()=='\'');
    auto tmp=s;tmp[0]='"';tmp.back()='"';
    return IToS(BinString::fullCppStr2RawStr(tmp)[0]);
  }
  void use(t_char_expr&ref){retval.set_num(char_to_num(lex2str(ref)));}
  void use(t_bool_expr&ref){retval.set_num(ref.value=="true"?"1":"0");}
  void use(t_string_expr&ref){retval.set_str("\""+ref.body.value+"\"");}
  void use(t_real_expr&ref){QapNoWay();}
  //void use(t_var_expr::t_item&ref){}
  void use(t_var_expr::t_impl&ref){
    QapAssert(ref.arr.size()>=1);
    for(int i=0;i<ref.arr.size();i++){
      auto&ex=ref.arr[i];
      QapAssert(ex.arr.empty());
      if(!i){retval.set_name(ex.name.value);continue;}
      retval.add_field(ex.name.value);
    }
  }
  void use(t_var_expr&ref){use(ref.body);}
  void use(t_block_expr&ref){use(ref.body);}
  bool try_conv_retval_func_to_full_method_name()
  {
    if(retval.func.empty())return false;
    auto*ps=get_cur_struct();
    if(!ps)return false;
    if(!ps->check_method(retval.func))return false;
    retval.func=ps->name+"::"+retval.func;
    return true;
  }
  void use(t_call_expr::t_dot&ref)
  {
    auto&arr=ref.body.arr;
    auto buff=retval;
    buff.off();
    QapAssert(arr.size()>=1);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      QapAssert(ex.arr.empty());
      if(!i)
      {
        if(arr.size()==1)
        {
          retval.set_name(ex.name.value);
          return;
        }
        buff.set_name(ex.name.value);continue;
      }
      auto nefn=buff.get_non_empty_field_name();
      static const auto allowed=split("var,tmpvar,field,param",",");
      if(qap_find_str(allowed,nefn).empty()){QapLexError("detected unexpected content in t_call_expr::t_dot:\n"+buff.toStr()+"\n non_empty_field_name = "+nefn);return;}
      auto tn=buff.getType();
      auto*ps=name2struct(tn);
      if(!ps){QapLexError("struct not found with name:\n"+tn);return;}
      auto*pf=ps->name2field(ex.name.value);
      auto pm=ps->check_method(ex.name.value);
      if(!pf&&!pm){QapLexError("field or method not found:\n member = "+ex.name.value+"\nstruct = "+tn);return;}
      QapAssert(bool(pf)!=bool(pm));
      if(pf)buff.add_field(pf->name);
      if(pm)
      {
        QapAssert(i+1==arr.size());
        ecxval=buff.toStr();
        //add()+="lea(ecx,"+buff.toStr()+");";
        retval.set_name(tn+"::"+ex.name.value);
      }
      int gg=1;
    }
  }
  void use(t_call_expr::t_colon&ref){QapNoWay();}
  void use(t_call_expr::i_call&ref){
    if(auto*ptr=t_call_expr::t_dot::UberCast(&ref))return use(*ptr);
    if(auto*ptr=t_call_expr::t_colon::UberCast(&ref))return use(*ptr);
  }
  ////void use_arr_call(vector<t_call_param>&arr){
  ////  for(int i=0;i<arr.size();i++){
  ////    auto&ex=arr[i];
  ////    callexpr_params_retval_handler(ex);
  ////  }
  ////}
  ////void callexpr_params_retval_handler(t_call_param&param)
  //void use(t_call_param&ref)
  //{
  //  use(ref.body);
  //  add()+="push("+retval.toStr()+");";
  //  qap_add_back(top.call_params_types)=retval.getType();
  //}
  bool is_result(const t_tmpvar&ref){return !ref.retval.pcore;}
  //bool is_proxy(const t_tmpvar&ref){return ref.retval.pcore&&!ref.out.empty();}
  static bool is_out_empty(const t_tmpvar&ref){return ref.retval.pcore&& ref.out.empty();}
  void conv_into_proxy(t_tmpvar&tmp,string&out){
    tmp.out=std::move(out);
    tmp.retval.off();
    tmp.retval.pcore=this;
  }
  void use(t_call_param&ref)
  {
    string out;
    {
      T_FRAME_GRAB(out);
      use(ref.body);
    }
    if(!retval.tmpvar.empty()){
      auto&tmp=*get_tmpvar_by_name(retval.tmpvar);
      conv_into_proxy(tmp,out);
      qap_add_back(top.call_params)=tmp;
      return;
    }
    qap_add_back(top.call_params)=get_cur_stat_frame().add_tmpvar(retval,out);
  }
  PRO_FUNCGEN_OVERLOAD_VEC(declare);
  static bool need_declare(const t_tmpvar&ref)
  {
    if(is_out_empty(ref))return false;
    if(ref.type=="void")return false;
    return true;
  }
  void declare(const t_tmpvar&ref)
  {
    if(!need_declare(ref))return;
    add()+="VAR("+quote(ref.type)+","+ref.name+");";
  }
  PRO_FUNCGEN_OVERLOAD_VEC(push);
  void push(const t_tmpvar&ref){
    QapAssert(!is_result(ref));
    string value=ref.name;
    if(is_out_empty(ref)){value=ref.retval.toStr();}
    add()+="push("+value+");";
  }
  PRO_FUNCGEN_OVERLOAD_VEC(emit);
  void emit(const t_tmpvar&ref)
  {
    if(is_out_empty(ref))return;
    //if(!ref.retval.is_empty())get_cur_stat_frame().out+="VAR("+quote(ref.type)+","+ref.name+");\n";
    top.out+=ref.out;
    if(!ref.retval.is_empty())add()+="copy("+ref.name+","+ref.retval.toStr()+");";
    return;
  }
  static string str_copy(const string&ref){return ref;}
  void use(t_call_expr&ref)
  {
    QapAssert(ecxval.empty()||ecxval=="this_ptr");
    ECX_VAL_SCOPE(str_copy(ecxval));
    auto ecxval_old=ecxval;ecxval.clear();
    use(ref.call);
    auto accum=retval;retval.off();
    auto accum_ecx=ecxval;ecxval=ecxval_old;
    auto&func=accum.func;
    QapAssert(!func.empty());
    for(;;)
    {
      QapAssert(top.call_params.empty());
      use_arr(ref.params.arr);
      retval=accum;
      bool ok=try_conv_retval_func_to_full_method_name();
      if(ok)accum_ecx="this_ptr";

      auto params_types=top.get_call_params_types();
      auto method=retval.func;

      t_func*pfunc=nullptr;
      for(;;)
      {
        pfunc=get_method_by_fullname_and_params_types(method,params_types);
        if(pfunc){func=method;break;}
        // if(accum_ecx=="this_ptr")if(auto*ps=get_cur_struct()){
        //   pfunc=ps->get_method_by_name_and_params_types(func,params_types);
        // }
        pfunc=get_func_by_name_and_params_types_raw(func,params_types);
        if(pfunc)break;
        pfunc=get_sys_func_by_name_and_params_types(func,params_types);
        if(try_sysfunc_call(ref,func))return;
        QapLexError("function not found!\n function:\n"+func+"("+join(params_types,",")+")");
        return;
      }
      vector<t_tmpvar> call_params=std::move(top.call_params);
      if(func=="getmem"){
        int gg=1;
      }
      emit(call_params);
      auto params_str=pfunc->get_params_types_str();
      auto tmpvar=get_cur_stat_frame().add_tmpvar(pfunc->rettype);
      {
        T_FRAME_GRAB(tmpvar.out);
        {
          T_FRAME_SCOPE();
          add()+="CALLER_SCOPE();";
          QapAssert(!tmpvar.name.empty());
          add()+="pushlea("+tmpvar.name+");";
          push(call_params);
          QapAssert(ecxval==ecxval_old);
          //if(accum_ecx!=ecxval_old)
          emit_mov_ecx_val(accum_ecx);
          add()+="call(\""+accum.toStr()+"("+params_str+")\");";
          //if(accum_ecx!=ecxval_old)
          emit_mov_ecx_val(ecxval_old);
        }
        //add()+="lea(esp,"+tmpvar.name+");";
      }

      emit(tmpvar);
      *get_cur_stat_frame().get_tmpvar_by_name(tmpvar.name)=tmpvar;
      retval.set_tmpvar(tmpvar.name);
      break;
    }
  }
  string mov_ecx_ecxval(const string&value){
    ecxval=value;
    if(value.empty())return "";
    string cmd="lea";
    if(value=="this_ptr")cmd="mov";
    return cmd+"(ecx,"+value+");";
  }
  void emit_mov_ecx_val(const string&value)
  {
    add()*=mov_ecx_ecxval(value);
  }
  //template<class TYPE>
  bool try_sysfunc_call(t_call_expr&ref,const string&func)
  {
    auto*psysfunc=get_sys_func_by_name_and_params_types(func,top.get_call_params_types());
    if(!psysfunc)return false;
    if(func=="__asm"&&(psysfunc->get_params_types_str()=="string"))
    {
      auto*pparam0=ref.params.arr[0].body.expr.expr.expr.expr.expr.expr.expr.expr.expr.expr.expr.get();
      QapAssert(t_string_expr::UberCast(pparam0));
      auto v="\""+t_string_expr::UberCast(pparam0)->body.value+"\"";
      add(1)+=BinString::fullCppStr2RawStr(v);
      top.out="";
      return true;
    }
    QapNoWay();
    return true;
  }
  // === I_STAT::HEAD === //
  void use(t_command_block&ref){grab_funcs(ref);grab_structs(ref);use_arr(ref.arr);}
  void use(i_stat&ref){
    //i_stat::t_proxy_visitor<SelfClass>::call(ref);
    #define F(T)if(auto*ptr=T::UberCast(&ref))return use(*ptr);
    STAT_LIST(F);
    #undef F
  }
  void use(t_var_stat::t_value&ref){use(ref.value);}
  void use(t_var_stat::t_type_impl&ref){
    //top.is_tmpvar_owner=true;
    QapAssert(ref.type.arr.empty());
    QapAssert(!ref.type.first.params);
    auto type=lex2str(ref.type);
    auto name=ref.name.value;
    qap_add_back(top.vars).set(type,name);
    add()+="VAR("+quote(type)+","+var_prefix+name+");";
    {
      T_FRAME_SCOPE_STAT();
      init_identifier(type,var_prefix,name,ref.value);
    }
  }
  void use(t_var_stat::t_auto_impl&ref)
  {
    auto name=ref.name.value;
    qap_add_back(top.vars).set("void",name);
    {
      T_FRAME_SCOPE_STAT();
      auto type=init_identifier("",var_prefix,name,ref.value);
      add(1)+="VAR("+quote(type)+","+var_prefix+name+");";
      get_var_by_name(name)->type=type;
    }
  }
  void use(t_var_stat::i_impl&ref){
    if(auto*ptr=t_var_stat::t_auto_impl::UberCast(&ref))return use(*ptr);
    if(auto*ptr=t_var_stat::t_type_impl::UberCast(&ref))return use(*ptr);
  }
  // === I_STAT === //
  void use(t_var_stat::t_impl&ref){use(ref.impl);}
  void use(t_var_stat&ref){use(ref.body.impl);}
  void use(t_sep_stat&ref){}
  void use(t_block_stat&ref){
    T_FRAME_SCOPE();
    use(ref.body);
  }
  void use(t_expr_stat&ref){
    T_FRAME_SCOPE_STAT();
    use(ref.body);
  }
  void use(t_set_oper&ref){
    T_FRAME_SCOPE_STAT();
    use(ref.var);
    auto accum=retval;retval.off();
    {
      T_FRAME_SCOPE();
      use(ref.expr);
      bool hard_case=retval.toStr()=="eax";
      if(hard_case)
      {
        top.out="push(eax);\n"+top.out;
        add()+="mov(ebx,eax);";
        add()+="pop(eax);";
        retval.set_reg("ebx");
      }else{
        int gg=1;
      }
    }
    string cmd;
    for(;;)
    {
      #define F(OPER,CMD)if(OPER==ref.oper){cmd=CMD;break;}
      F("+=","add");
      F("-=","sub");
      F("*=","mul");
      F("/=","div");
      F("%=","mod");
      F("=","mov");
      F("<<=","shl");
      F(">>=","shr");
      F("|=","bwor");
      F("&=","bwand");
      #undef F
      QapLexError("no impl for setoper: "+ref.oper);
      break;
    }
    QapAssert(!accum.readonly());
    bool is_int=accum.is_int()&&retval.is_int();
    if(accum.is_complex()&&retval.is_complex())
    {
      if(is_int){
        mov_ebx_retval();
      }
      if(!is_int)
      {
        QapAssert(cmd=="mov");
        cmd="copy";
      }
    }
    add()+=cmd+"("+accum.toStr()+","+retval.toStr()+");";
    retval.off();
  }
  void use(t_set_oper_stat&ref){use(ref.body);}
  void use(t_func_stat&ref){use(ref.body);}
  void use(t_oper_stat&ref){
    top.out;
    EstimateFuncIsNoImplForLexer(ref);
  }
  void use(t_ret_stat&ref){
    T_FRAME_SCOPE_STAT();
    use(ref.body);
    auto rt=retval.getType();
    auto crt=get_cur_result_type();
    if(rt!=crt){
      QapLexError("cannot convert from '"+rt+"' to '"+crt+"'");return;
    }
    //if(rt!="int"){
      add()+="copy(result,"+retval.toStr()+");";//lea(eax,result);lea(ebx,"+retval.toStr()+");mov(ecx,ctti.type2size("+quote(rt)+"));memcopy();";
    //}else{
    //  add()+="mov(eax,"+retval.toStr()+");";
    //}
    add()+="ret();";
  }
  void use(t_null_stat&ref){}
  void use(t_postfix_oper&ref){
    use(ref.var);
    if("++"==ref.oper){
      QapAssert(!retval.reg.empty()||!retval.var.empty()||!retval.field.empty()||!retval.tmpvar.empty());
      QapAssert(retval.is_int()&&!retval.readonly());
      add()+="inc("+retval.toStr()+");";
    }
    if("--"==ref.oper){
      QapAssert(!retval.reg.empty()||!retval.var.empty()||!retval.field.empty()||!retval.tmpvar.empty());
      QapAssert(retval.is_int()&&!retval.readonly());
      add()+="dec("+retval.toStr()+");";
    }
  }
  void use(t_postfix_oper_stat&ref){use(ref.body);}
  void use(t_break_stat&ref){add()+="jmp(\""+get_for_name()+"::break\");";}
  void use(t_continue_stat&ref){add()+="jmp(\""+get_for_name()+"::continue\");";}
  void use(t_for_stat::i_next&ref){
    if(auto*ptr=t_for_stat::t_set::UberCast(&ref))return use(ptr->body);
    if(auto*ptr=t_for_stat::t_postfix::UberCast(&ref))return use(ptr->body);
  }
  void use(t_for_stat::t_next&ref){use(ref.body);}
  void use(t_for_stat&ref){
    T_FRAME_SCOPE_STAT();
    top.for_name="for_"+IToS(for_counter++);auto fn=top.for_name;
    use(ref.init);
    add()+="jmp(\""+fn+"::condition\");";
    add()+="label(\""+fn+"::continue\");";
    {
      T_FRAME_SCOPE_STAT();
      use(ref.next);
    }
    add()+="label(\""+fn+"::condition\");";
    {
      T_FRAME_SCOPE_STAT();
      use(ref.cond);
      add()+="jz(\""+fn+"::break\","+retval.toStr()+");";
    }
    {
      T_FRAME_SCOPE_STAT();
      use(ref.body);
      add()+="jmp(\""+fn+"::continue\");";
    }
    add()+="label(\""+fn+"::break\");";
  }
  void use(t_if_stat::t_else&ref){use(ref.body);}
  void use(t_if_stat&ref){
    T_FRAME_SCOPE_STAT();
    top.if_name="if_"+IToS(if_counter++);auto cur=top.if_name;
    use(ref.cond);
    //if(retval.toStr()=="eax")add()+="mov(ebx,eax)";
    auto*pelse=ref.aft.get();
    add()+="jz(\""+cur+string(pelse?"::else":"::end")+"\","+retval.toStr()+");";
    {
      T_FRAME_SCOPE_STAT();
      use(ref.bef);
      add()+="jmp(\""+cur+"::end\");";
    }
    if(pelse)
    {
      add()+="label(\""+cur+"::else\");";
      T_FRAME_SCOPE_STAT();
      use(*pelse);
    }
    add()+="label(\""+cur+"::end\");";
  }
  void declare_result(const string&type){top.result_type=type;add()+="PARAM_RESULT("+quote(type)+");";}
  void declare_link_to_fields(const string&type){
    auto*pt=name2struct(type);QapAssert(pt);auto&arr=pt->fields;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];add()+="MEMBER("+quote(ex.type)+","+field_prefix+ex.name+");";
    }
    QapAssert(top.fields.empty());
    top.fields=arr;
  }
  void use(t_struct_lex::t_method&method_ref){
    auto&ref=method_ref.body;
    frames_push();
    auto curstruct=get_cur_struct_name();
    auto proc_name=func_prefix+curstruct+"::"+ref.name.value;
    top.proc_name=proc_name;
    declare_result(ref.type);
    auto*ps=get_cur_struct();QapAssert(ps);
    //qap_add_back(ps->methods).set(ref.type,ref.name.value,ref.params.arr); // MOVED TO GRAB_STRUCTS
    declare_link_to_fields(curstruct);
    ECX_VAL_SCOPE("this_ptr");
    add()+="VAR_THIS_PTR();";
    {
      T_FRAME_SCOPE();
      use_arr(ref.params.arr);
      add(2)+="{proc(\""+proc_name+"("+top.get_params_types_str()+")\"){";
      use(ref.body);
    }
    frames_pop();
    add()+="}}\n";
  }
  /*
  four independet steps:
  declare fields; //for ctti only
  declare links to members; //for methods|ctor|dtor
  call ctors; //for ctor only
  set initial values; //for ctor only
  call destructors; //for dtor only;
  
  in single function.
  also we need to use general code
  */
  void use(t_struct_lex::t_field&field_ref){
    auto&ref=field_ref.body;
    QapAssert(ref.type.arr.empty());
    QapAssert(!ref.type.first.params);
    auto type=lex2str(ref.type);
    auto name=ref.name.value;
    //qap_add_back(top.fields).set(type,name); // MOVED TO GRAB_STRUCTS
    string buff;
    {
      T_FRAME_GRAB(buff);
      init_identifier(type,field_prefix,name,ref.value);
    }
    top.ctor_impl+=buff;
  }
  string init_identifier(const string&type,const string&prefix,const string&name,TAutoPtr<t_var_stat::t_value>&value)
  {//
    auto id=prefix+name;
    if(!value){
      if(type=="int"){
        add()+="mov("+id+",0);";
      }else{
        add()+="lea(ecx,"+id+");";
        add()+="call("+ctor(type)+");";
        add()*=mov_ecx_ecxval(ecxval);
      }
    }
    if(!value)return "void";
    use(value);
    auto rt=retval.getType();
    if(!type.empty())if(rt!=type){
      auto&ref=value;QapLexError("cannot convert from '"+rt+"' to '"+type+"'");return "";
    }
    bool is_int=rt=="int";
    if(retval.is_complex()&&is_int)
    {
      mov_eax_retval();
    }
    string cmd="mov";
    if(!is_int)cmd="copy";
    add()+=cmd+"("+id+","+retval.toStr()+");";
    retval.off();
    return rt;
  }
  void use(t_struct_lex&ref){
    ECX_VAL_SCOPE("this_ptr");
    //add(0)+="{STRUCT("+quote(ref.name.value)+"){"; // MOVED TO GRAB_STRUCTS
    string ctor_code;
    frames_push();
    QapAssert(get_cur_struct_name().empty());
    auto struct_name=ref.name.value;
    top.struct_name=struct_name;
    auto*ps=get_cur_struct();QapAssert(ps);
    use_arr(ref.arr);
    use_arr(ref.fields);
    //declare_fields(ps->fields); // MOVED TO GRAB_STRUCTS
    ctor_code=top.ctor_impl;
    //out.fields=top.fields;      // MOVED TO GRAB_STRUCTS
    //qap_add_back(structs)=out;  // MOVED TO GRAB_STRUCTS
    use_arr(ref.methods);
    frames_pop();
    //add()+="}}\n";                // MOVED TO GRAB_STRUCTS
    //auto obj=use_code(out.name+" hack(){vec2i out;"+ctor_code+"return out;}"); obj.name=out.name+"::`ctor()"; use(obj);
    add()+="{proc("+ctor(struct_name)+"){";
    frames_push();
    declare_link_to_fields(struct_name);
    add()+="VAR_THIS_PTR();";
    top.out+=ctor_code;
    frames_pop();
    add()+="}}\n";
  }
  void use(t_sep_struct&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_struct_stat&ref){use(ref.body);}
  void use(t_template_stat&ref){EstimateFuncIsNoImplForLexer(ref);}
  //
  string ctor(const string&type){return quote(func_prefix+type+"::`ctor()");}
  static string quote(const string&s){auto q="\"";return q+s+q;}
  void mov_reg_retval(const string&reg)
  {
    auto t=retval.getType();
    if(t!="int")QapDebugMsg("no way.\ntype = "+t+"\ninside function: "+get_cur_proc_name());
    add()+="mov("+reg+","+retval.toStr()+");";
    retval.set_reg(reg);
  }
  void mov_eax_retval(){mov_reg_retval("eax");}
  void mov_ebx_retval(){mov_reg_retval("ebx");}
  void mov_ecx_retval(){mov_reg_retval("ecx");}
  void mov_edx_retval(){mov_reg_retval("edx");}
};


















void UberInfoBox(const string&caption,const string&text);

bool is_ok(string s){string head="{\"ok\":"+BToS(true)+",";return head==s.substr(0,head.size());}

#include "GlobalEnv.inl"

void main2016(IEnvRTTI&Env,struct t_conv_cpp2asm(*)=0)
{
  t_simple_stat_lex::t_block_stat block;
  string result=load_obj_ex(Env,block,file_get_contents("test2016.h"));
  if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
  //auto s=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(block));
  auto&a0=block.body.arr[0];
  auto*p=a0.get();
  t_core core(Env);
  core.use(block);
  string text=core.top.out;
  while(text.back()=='\n')text.pop_back();
  int gg=1;
  file_put_contents("qapcppout.asm",text);
  auto cmdline=string(GlobalEnv::Get().lpCmdLine);
  auto last_param=cmdline.empty()?"":split(cmdline," ").back();
  if(last_param!="HIDE"){
    UberInfoBox("result",text);
    TerminateProcess(GetCurrentProcess(),0);
  }
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
        F(TType)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
      QapLexerRegAll(Env);
      RegAllCppLex(Env);
    }
    void Run(IEnvRTTI&Env)
    {
      main2016(Env);
    }
    ThisCompileUnit(){
      
    }
  };
  ThisCompileUnit ThisUnit;
}
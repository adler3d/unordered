#include "StdAfx.h"

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2016_03_29.h"
#else
//=====>>>>>main_2016_03_29
#include "Entity/OutDeviceBase.inl"
#include "IsSameVisitor.inl"
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
#include "t_asmcpplike2016_lexer.inl"
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

#define I_PARAM_LIST(F)\
F(t_char_param)\
F(t_str_param)\
F(t_num_param)\
F(t_ptr_reg_soft_param)\
F(t_ptr_reg_raw_param)\
F(t_reg_param)\
F(t_ptr_raw_param)\
F(t_mem_param)\
F(t_raw_param)\
F(t_ptr_reg_offset_param)\
F(t_ptr_reg_param)\
F(t_ptr_num_param)\
F(t_name_param)\
// I_PARAM_LIST //

#define I_STAT_LIST(F)\
F(t_cmd_stat)\
F(t_block_stat)\
F(t_sep_stat)\
// I_STAT_LIST //

#define I_ITEM_LIST(F)\
F(t_proc_item)\
F(t_sep_item)\
F(t_struct_item)\
// I_ITEM_LIST //
struct t_ctti{
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
  int get_params_size(const vector<string>&arr){
    int out=0;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      out+=type2size(ex);
    }
    return out;
  }
  int get_params_size(const string&s){return get_params_size(split(s,","));}
};

bool is_ok(string s);
static string IntToStrWithSign(int i){return (i<0?"-":"+")+IToS(abs(i));}

struct t_core:t_asmcpplike2016{
  static const int int_size=1;
  static const int phs=int_size+int_size;
  template<class TYPE>string lex2str(TYPE&ref){string out;save_obj(Env,ref,out);return out;}
  template<class TYPE>void EstimateFuncIsNoImplForLexer(TYPE&ref){
    string out=lex2str(ref);
    QapDebugMsg("no impl. TYPE = \""+Sys$$<TYPE>::GetRTTI(Env)->GetFullName()+"\"\nContent:\n"+out);
  }
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
  struct t_type_and_name{string type;string name;void set(const string&t,const string&n){type=t;name=n;}};
  struct t_cmd_param{
    string type;
    string ast;//ast=expr.toAST();
    string expr;
    void set(const string&t,const string&a,const string&e){type=t;ast=a;expr=e;}
  };
  struct t_param{
    t_type_and_name tn;
    int pos_param;
    void set(t_core&core,const t_type_and_name&tn){pos_param=core.pos_param;this->tn=tn;}
    string get_param(int offset=0)const{QapAssert(phs+pos_param>=0);return "ptr[ebp+"+IToS(phs+pos_param+offset)+"]";}
  };
  struct t_member{
    t_type_and_name tn;
    int pos_member;
    void set(t_core&core,const t_type_and_name&tn){pos_member=core.pos_member;this->tn=tn;}
    string get_param(int offset=0)const{return "ptr[ecx+"+IToS(pos_member+offset)+"]";}
  };
  struct t_var_scope{
    t_type_and_name tn;
    int size;
    int pos_var;
    void set_and_start(t_core&core,t_type_and_name type_and_name){
      tn=type_and_name;
      size=core.ctti.type2size(tn.type);
      start(core);
      pos_var=core.pos_var;
    }
    string get_param(int offset=0)const{return "ptr[ebp-"+IToS(pos_var-offset)+"]";}
    void start(t_core&core){
      core.pos_var+=size;
      core.emit(1==size?"dec(esp);":"sub(esp,"+IToS(size)+");");
    }
    void finish(t_core&core){
      core.pos_var-=size;
      core.emit(1==size?"inc(esp);":"add(esp,"+IToS(size)+");");
    }
  };
  struct t_loop_scope{
    int beg_eip;
    void start(t_core&core){
      beg_eip=core.out.size();
    }
    void finish(t_core&core){
      core.emit("loop("+IToS(beg_eip)+");");
    }
  };
  struct t_caller_scope{
    int old_pos;
    void start(t_core&core){
      old_pos=core.pos_var;
      core.esp_info.caller_scope_bef();
    }
    void finish(t_core&core){
      core.esp_info.caller_scope_aft();
      QapAssert(core.pos_var==old_pos);
      core.emit("add(esp,"+IToS(old_pos-core.pos_var+core.esp_info.n)+");");
    }
  };
  #define NAME2PTR(t_field,field)                   \
  t_field*get_##field##_by_name(const string&name){ \
    auto*p=top.name2##field(name);                  \
    if(p)return p;                                  \
    for(int i=frames.size()-1;i>=0;i--){            \
      auto&ex=frames[i];                            \
      if(p=ex.name2##field(name))break;             \
    }                                               \
    return p;                                       \
  }                                                 \
  // NAME2PTR //
  NAME2PTR(t_var_scope,var);
  NAME2PTR(t_param,param);
  NAME2PTR(t_member,member);
  #undef NAME2PTR
  struct t_frame{
    vector<t_loop_scope> loops;
    vector<t_caller_scope> callers;
    vector<t_var_scope> vars;
    //
    vector<t_param> params;
    vector<t_member> members;
    void finish(t_core&core)
    {
      {auto&arr=vars;while(arr.size()){arr.back().finish(core);arr.pop_back();}}
      {auto&arr=loops;while(arr.size()){arr.back().finish(core);arr.pop_back();}}
      {auto&arr=callers;while(arr.size()){arr.back().finish(core);arr.pop_back();}}
    }
    PRO_FUNCGEN_GETP_BY_FIELD(t_var_scope,name2var,vars,const string&,tn.name);
    PRO_FUNCGEN_GETP_BY_FIELD(t_param,name2param,params,const string&,tn.name);
    PRO_FUNCGEN_GETP_BY_FIELD(t_member,name2member,members,const string&,tn.name);
  };
  void frames_push(){
    qap_add_back(frames)=std::move(top);top=t_frame();
  }
  void frames_pop(){
    QapAssert(frames.size());
    top.finish(*this);
    top=std::move(frames.back());
    frames.pop_back();
  }
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
  struct t_result{
    string type;
    int offset;
    void set_and_start(t_core&core,const string&type){this->type=type;start(core);}
    void reserve_mem_for_result(t_core&core,const string&type){core.pos_param+=core.ctti.type2size(type);}
    void start(t_core&core){
      reserve_mem_for_result(core,"int");
      core.pos_param-=core.ctti.type2size("int");
      offset=core.pos_param;
    }
    string get_presult(){
      return "ptr[ebp"+IntToStrWithSign(phs+offset)+"]";//.set_type("int");
    }
  };
  struct t_label{
    int pos;
    string name;
    void set(int id,const string&n){pos=id;name=n;}
  };
  //------------------------------------------------------------------------------
  IEnvRTTI&Env;
  t_ctti ctti;
  int pos_member;int pos_var;int pos_param;
  vector<string> regs;
  vector<string> cmds;
  t_frame top;
  vector<t_frame> frames;
  vector<t_cmd_param> cmd_params;
  vector<string> out;
  vector<t_label> labels;
  t_esp_info esp_info;
  t_result result;
  string proc_name;
  t_core(IEnvRTTI&Env):Env(Env){init();}
  //------------------------------------------------------------------------------
  PRO_FUNCGEN_GETP_BY_FIELD(t_label,name2label,labels,const string&,name);
  void pos_to_zeros(){pos_member=0;pos_var=0;pos_param=0;}
  void init(){
    pos_to_zeros();load_regs_and_cmds();
  };
  void load_regs_and_cmds()
  {
    cmds=split(file_get_contents("regs_and_cmds.txt"),"\n");
    QapAssert(cmds.size()>1);
    regs=split(cmds[0],",");
    QapPopFront(cmds);
  }
  //------------------------------------------------------------------------------ 
  //void use(i_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  // === I_PARAM === //
  void use(i_param&ref){
    #define F(T)if(auto*ptr=T::UberCast(&ref))return use(*ptr);
    I_PARAM_LIST(F);
    #undef F
  }
  void use(t_char_param&ref){EstimateFuncIsNoImplForLexer(ref);qap_add_back(cmd_params).set("char","raw",lex2str(ref));}
  void use(t_str_param&ref){qap_add_back(cmd_params).set("string","raw",lex2str(ref));}
  void use(t_num_param&ref){qap_add_back(cmd_params).set("int","raw",lex2str(ref));}
  void use(t_ptr_reg_soft_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_ptr_reg_raw_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_reg_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_ptr_raw_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_mem_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_raw_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_ptr_reg_offset_param&ref){qap_add_back(cmd_params).set("int","ptr|reg|raw",lex2str(ref));}
  void use(t_ptr_reg_param&ref){qap_add_back(cmd_params).set("int","ptr|reg",lex2str(ref));}
  void use(t_ptr_num_param&ref){qap_add_back(cmd_params).set("int","ptr|raw",lex2str(ref));}
  template<class TYPE>void add_param_by_ptr(t_name_param&ref,TYPE*p)
  {
    auto&b=qap_add_back(cmd_params);
    auto type=p->tn.type;
    int offset=0;
    for(int i=0;i<ref.arr.size();i++){
      auto&ex=ref.arr[i];
      offset+=ctti.field2offset(type,ex.field);
      type=ctti.field2type(type,ex.field);
    }
    b.set(type,"ptr|reg|raw",p->get_param(offset));
  }
  void use(t_name_param&ref){
    //if(ref.arr.empty())
    auto n=ref.name.value;
    if(auto*p=get_var_by_name(n)){add_param_by_ptr(ref,p);return;}
    if(auto*p=get_param_by_name(n)){add_param_by_ptr(ref,p);return;}
    if(auto*p=get_member_by_name(n)){add_param_by_ptr(ref,p);return;}
    if(n=="result"){qap_add_back(cmd_params).set(result.type,"result",result.get_presult());return;}
    bool is_reg=qap_find_str(regs,n).size()==1;
    if(!is_reg)
    {
      #define F(C)if(#C==n){qap_add_back(cmd_params).set("int","raw",IToS(C));return;}
      F(VK_LEFT);F(VK_RIGHT);F(VK_UP);F(VK_DOWN);F(VK_SHIFT);F(VK_CONTROL);F(VK_MENU);
      #undef F
      EstimateFuncIsNoImplForLexer(ref);
    }
    qap_add_back(cmd_params).set("int","reg",lex2str(ref));
  }
  // I_PARAM //
  // === I_STAT === //
  void use(i_stat&ref){
    #define F(T)if(auto*ptr=T::UberCast(&ref))return use(*ptr);
    I_STAT_LIST(F);
    #undef F
  }
  static t_type_and_name get_type_and_name(vector<TAutoPtr<i_param>>&arr){
    t_type_and_name out;
    QapAssert(arr.size()==2);
    auto*pt=t_str_param::UberCast(arr[0].get());QapAssert(pt);
    out.type=get(pt->value);
    auto*pn=t_name_param::UberCast(arr[1].get());QapAssert(pn);
    QapAssert(pn->arr.empty());
    out.name=pn->name.value;
    return out;
  }
  //
  void check_pop_allowed(){QapAssert(!esp_info.inside_call_scope);}
  //
  void use(t_cmd_stat&ref)
  {
    auto cmd=ref.cmd;
    if(!proc_name.empty())if(cmd=="ret")
    {
      emit("jmp("+toCpp(proc_name+"::ret")+");");
      return;
    }
    if(cmd=="PARAM_RESULT")
    {
      QapAssert(ref.arr.size()==1);
      auto*pt=t_str_param::UberCast(ref.arr[0].get());QapAssert(pt);
      auto type=get(pt->value);
      result.set_and_start(*this,type);
      return;
    }
    if(cmd=="VAR")
    {
      QapAssert(ref.arr.size()==2);
      auto tn=get_type_and_name(ref.arr);
      qap_add_back(top.vars).set_and_start(*this,tn);
      return;
    }
    if(cmd=="LOOP_SCOPE")
    {
      QapAssert(ref.arr.size()==0);
      qap_add_back(top.loops).start(*this);
      return;
    }
    if(cmd=="CALLER_SCOPE")
    {
      QapAssert(ref.arr.size()==0);
      qap_add_back(top.callers).start(*this);
      return;
    }
    if(cmd=="VAR_THIS_PTR")
    {
      QapAssert(ref.arr.size()==0);
      emit("VAR(\"int\",this_ptr);mov(this_ptr,ecx);");
      return;
    }
    if(cmd=="PARAM")
    {
      QapAssert(ref.arr.size()==2);
      auto tn=get_type_and_name(ref.arr);
      pos_param-=ctti.type2size(tn.type);QapAssert(pos_param>=0);
      qap_add_back(top.params).set(*this,tn);
      return;
    }
    if(cmd=="MEMBER")
    {
      QapAssert(ref.arr.size()==2);
      auto tn=get_type_and_name(ref.arr);
      qap_add_back(top.members).set(*this,tn);
      pos_member+=ctti.type2size(tn.type);
      return;
    }
    //
    cmd_params.clear();
    use_arr(ref.arr);
    //
    if(cmd=="push")
    {
      QapAssert(ref.arr.size()==1);
      QapAssert(cmd_params.size()==1);
      auto&dest=cmd_params[0];
      if(dest.type!="int"&&dest.ast=="ptr|reg|raw")
      {
        auto n=ctti.type2size(dest.type);
        t_ptr_reg_offset_param obj;
        string result=load_obj_ex(Env,obj,dest.expr);
        if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
        int offset=SToI(obj.offset)+n;
        for(int i=0;i<n;i++)
        {
          offset--;
          emit("push(ptr["+obj.reg+IntToStrWithSign(offset)+"]);");
        }
        return;
      }
      if(dest.type!="int")if(dest.ast=="ptr|reg"||dest.ast=="ptr|raw")EstimateFuncIsNoImplForLexer(ref);
    }
    if(cmd=="pop")
    {
      QapAssert(ref.arr.size()==1);
      QapAssert(cmd_params.size()==1);
      auto&dest=cmd_params[0];
      check_pop_allowed();
      auto n=ctti.type2size(dest.type);
      if(dest.ast=="result"){/*qap_add_back(out)="mov(edx,"+dest.expr+");";*/dest.ast="ptr|reg|raw";dest.expr="ptr[edx+0]";}
      if(n>1&&dest.type!="int"&&dest.ast=="ptr|reg|raw")
      {
        t_ptr_reg_offset_param obj;
        string result=load_obj_ex(Env,obj,dest.expr);
        if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
        int offset=SToI(obj.offset);
        for(int i=n-1;i>=0;i--){
          emit("pop(ptr["+obj.reg+IntToStrWithSign(offset)+"]);");
          offset++;
        }
        return;
      }
      if(dest.type!="int")if(dest.ast=="ptr|reg"||dest.ast=="ptr|raw")EstimateFuncIsNoImplForLexer(ref);
    }
    if(cmd=="copy")
    {
      QapAssert(ref.arr.size()==2);
      QapAssert(cmd_params.size()==2);
      auto&dest=cmd_params[0];
      auto&src=cmd_params[1];
      for(;;)
      {
        #define F(T)
        if(dest.ast=="ptr|reg|raw")if(qap_is_unique_str_from("raw|reg","|",src.ast))if(is_same_str(dest.type,src.type,"int")){
          cmd="mov";break;
        }
        if(dest.ast=="result"){qap_add_back(out)="mov(edx,"+dest.expr+");";dest.ast="ptr|reg|raw";dest.expr="ptr[edx+0]";continue;}
        if(dest.ast=="ptr|reg|raw"&&dest.ast==src.ast){
          auto dest=lex2str(ref.arr[0]);
          auto src=lex2str(ref.arr[1]);
          emit("push("+src+");pop("+dest+");");
          return;
        }
        #undef F
        return;
      }
    }
    if(cmd=="label")
    {
      QapAssert(ref.arr.size()==1);
      QapAssert(cmd_params.size()==1);
      qap_add_back(labels).set(out.size(),cmd_params[0].expr);
      //cmd_params.clear();
    }
    if(cmd=="pushlea"||cmd=="push"){esp_info.n++;}
    qap_add_back(out)=cmd+"("+get_cmd_params_exprs_str()+");";
    /*t_name = ptr_reg_offset or reg or const;
    t_ptr_num = ptr_const
    t_ptr_reg = ptr_reg*/
  }
  static bool qap_is_unique_str_from(const string&s,const string&needle,const string&value){
    return qap_find_str(split(s,needle),value).size()==1;
  }
  static bool is_same_str(const string&a,const string&b,const string&c){return a==b&&b==c;}
  string get_cmd_params_exprs_str()const{
    vector<string> out;
    auto&arr=cmd_params;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      qap_add_back(out)=ex.expr;
    }
    return join(out,",");
  }
  string get_cmd_params_ast_str()const{
    vector<string> out;
    auto&arr=cmd_params;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      qap_add_back(out)=ex.ast;
    }
    return join(out,",");
  }
  void use(t_block_stat&ref){frames_push();use_arr(ref.arr);frames_pop();}
  void use(t_sep_stat&ref){int nothing=1;}
  // I_STAT //
  // === I_ITEM === //
  void use(i_item&ref){
    #define F(T)if(auto*ptr=T::UberCast(&ref))return use(*ptr);
    I_ITEM_LIST(F);
    #undef F
  }
  void use(t_proc_item&ref){
    pos_to_zeros();
    auto name=get(ref.name);
    if(split(name,"(").size()>1)
    {
      pos_param=ctti.get_params_size(split(split(name,"(")[1],")")[0]);
    }
    QapAssert(proc_name.empty());
    proc_name=name;
    emit("label("+toCpp(name)+");push(ebp);mov(ebp,esp);");
    frames_push();
    use_arr(ref.arr);
    frames_pop();
    pos_to_zeros();
    QapAssert(!proc_name.empty());
    proc_name.clear();
    emit("label("+toCpp(name+"::ret")+");mov(esp,ebp);pop(ebp);ret();");
  }
  void use(t_sep_item&ref){int nothing=1;}
  void use(t_struct_item&ref){
    auto name=get(ref.name);
    qap_add_back(ctti.structs).name=name;
    use_arr(ref.arr);
  }
  static string get(t_str&ref){return BinString::fullCppStr2RawStr(ref.body.value);}
  static string toCpp(const string&s){return "\""+CppString(s).data+"\"";}
  void use(t_field&ref)
  {
    auto name=get(ref.name);
    auto type=get(ref.type);
    auto&b=ctti.structs.back();
    auto&f=qap_add_back(b.fields);
    f.name=name;
    f.type=type;
  }
  // I_ITEM //
  // === MAIN === //
  void use(t_asmcpplike2016&ref)
  {
    use_arr(ref.arr);
  }
public:
  void emit(const string&code)
  {
    vector<TAutoPtr<i_stat>> arr;
    string result=load_obj_ex(Env,arr,code);
    if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
    use_arr(arr);
    int gg=1;
  }
public:
  //stage2
  vector<string> lines;
  vector<string> cmds_types;
  void update_cmds()
  {
    for(int i=0;i<cmds.size();i++)
    {
      auto&ex=cmds[i];
      t_core::t_cmd_stat obj;
      auto result=load_obj_ex(Env,obj,ex+";");
      if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
      auto&arr=obj.arr;
      vector<string> params;
      qap_add_back(params)=obj.cmd;
      for(int i=0;i<arr.size();i++)
      {
        auto*ptr=arr[i].get();
        string t;
        #define F(S,T)if(auto*p=T::UberCast(ptr)){t=S;}
        F("ptr|reg"    ,t_ptr_reg_soft_param);
        F("ptr|reg|raw",t_ptr_reg_raw_param);
        F("reg"        ,t_reg_param);
        F("ptr|raw",    t_ptr_raw_param);
        F("ptr|raw",    t_mem_param);
        F("raw",        t_raw_param);
        if(t.empty())EstimateFuncIsNoImplForLexer(arr[i]);
        qap_add_back(params)=t;
        #undef F
      }
      qap_add_back(cmds_types)=join(params,",");
    }
  }
};













struct t_core_stage2:t_core{
  void use(i_param&ref){
    #define F(T)if(auto*ptr=T::UberCast(&ref))return use(*ptr);
    I_PARAM_LIST(F);
    #undef F
  }
  void use(t_char_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_str_param&ref){qap_add_back(cmd_params).set("int","raw",IToS(name2label(lex2str(ref))->pos));}
  void use(t_num_param&ref){qap_add_back(cmd_params).set("int","raw",ref.value.value);}
  void use(t_ptr_reg_soft_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_ptr_reg_raw_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_reg_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_ptr_raw_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_mem_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_raw_param&ref){EstimateFuncIsNoImplForLexer(ref);}
  void use(t_ptr_reg_offset_param&ref){qap_add_back(cmd_params).set("int","ptr|reg|raw",reg2id(ref.reg)+","+ref.offset);}
  void use(t_ptr_reg_param&ref){qap_add_back(cmd_params).set("int","ptr|reg",reg2id(ref.reg));}
  void use(t_ptr_num_param&ref){qap_add_back(cmd_params).set("int","ptr|raw",ref.num);}
  void use(t_name_param&ref){
    auto n=ref.name.value;
    qap_add_back(cmd_params).set("int","reg",reg2id(n));
  }
  void use(t_cmd_stat&ref)
  {
    auto&arr=ref.arr;
    cmd_params.clear();
    qap_add_back(cmd_params).set("int",ref.cmd,ref.cmd);
    
    if(ref.cmd!="label")
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=*arr[i].get();
        use(ex);
      }
    }
    auto cmdt=get_cmd_params_ast_str();
    cmd_params[0].expr=cmdt2id(cmdt);
    auto str_cmd=get_cmd_params_exprs_str();
    qap_add_back(lines)=norm(str_cmd);
  }
  string norm(const string&cmd)
  {
    auto a=split(cmd,",");
    a.resize(4);
    for(int i=0;i<a.size();i++){
      auto&ex=a[i];
      ex=ex.empty()?"0":IToS(SToI(ex));
    }
    return join(a,",");
  }
  string cmdt2id(const string&t)const{
    auto v=qap_find_str(cmds_types,t);
    bool is_single=v.size()==1;
    QapAssert(is_single);
    auto id=v[0];
    return IToS(id);
  }
  string reg2id(const string&reg)const{
    auto v=qap_find_str(regs,reg);
    bool is_reg=v.size()==1;
    QapAssert(is_reg);
    auto id=v[0];
    return IToS(id);
  }
};

void UberInfoBox(const string&caption,const string&text);

bool is_ok(string s){string head="{\"ok\":"+BToS(true)+",";return head==s.substr(0,head.size());}

#include "GlobalEnv.inl"

void main2016(IEnvRTTI&Env)
{
  t_asmcpplike2016 tree;
  string result=load_obj_ex(Env,tree,file_get_contents("asm2mashkod2016.h"));
  if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
  //auto s=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(block));
  //auto&a0=block.body.arr[0];
  //auto*p=a0.get();
  t_core core(Env);
  #define F(CODE)core.emit(#CODE)
  F(jmp("begin"););
  core.use(tree);
  F(label("begin");{VAR("int",var_eax);pushlea(var_eax);push(ecx);call("func_main(int)");add(esp,2);mov(eax,var_eax);}mov(err,1););
  #undef F
  auto out=join(core.out,"\n");
  auto&cs2=(t_core_stage2&)core;cs2.update_cmds();
  for(int i=0;i<core.out.size();i++){
    auto&ex=core.out[i];
    t_core::t_cmd_stat obj;
    auto result=load_obj_ex(Env,obj,ex);
    if(!is_ok(result)){QapDebugMsg(result);TerminateProcess(GetCurrentProcess(),2);}
    cs2.use(obj);
  }
  auto lines=join(core.lines,"\n");
  //auto cmds_types=join(core.cmds_types,"\n");
  auto text="/*\n"+lines+"\n*/\n"+out;
  int gg=1;
  file_put_contents("mashkod.asm",text);
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
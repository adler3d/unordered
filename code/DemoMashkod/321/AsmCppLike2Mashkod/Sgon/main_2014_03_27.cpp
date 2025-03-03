#include "StdAfx.h"
#include <utility>/*
#include "Gateway.h"
#include "Gateway.cpp"*/

#ifdef DEF_BUILD_MACRO
  #include "../Macro/main_2013_01_11.h"
#else
//=====>>>>>main_2013_01_11
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
//#include "t_simple_stat_lex.inl"
//<<<<<=====main_2013_01_11
#endif //DEF_BUILD_MACRO//

void UberInfoBox(const string&caption,const string&text);

#include "Lexem\t_smart_asm.inl"

class t_smart_asm_machine:public t_smart_asm{
public:
  class t_str2sys{
  public:
    string&s;
    t_str2sys(string&s):s(s){}
    operator int&(){QapAssert(s.size()==sizeof(int));return *(int*)&s[0];}
    operator char&(){QapAssert(s.size()==sizeof(char));return s[0];}
    operator bool&(){QapAssert(s.size()==sizeof(bool));return *(bool*)&s[0];}
  };
  class t_sys2str{
  public:
    string s;
    t_sys2str(string&s):s(s){}
    t_sys2str(const int&ref){s.resize(sizeof(int));*(int*)&s[0]=ref;}
    t_sys2str(const char&ref){s.resize(sizeof(char));s[0]=ref;}
    t_sys2str(const bool&ref){s.resize(sizeof(bool));*(bool*)&s[0]=ref;}
    operator string&(){return s;}
  };
public:
  struct t_retval{
    string type;
    string value;
    #define F(TYPE)TYPE get_##TYPE(){QapAssert(type==#TYPE);return t_str2sys(value);}
    F(int);
    F(char);
    F(bool);
    #undef F
  };
public:
  struct t_var{
    string name;
    string type;
    string value;
  };
  class t_stackframe{
  public:
    vector<t_var> vars;
  public:
    int find_var(const string&name){for(int i=0;i<vars.size();i++){auto&ex=vars[i];if(ex.name==name)return i;}return -1;}
  };
public:
  struct t_label_info{
    string type;
    string name;
    static t_label_info make(const string&type,const string&name){t_label_info tmp;tmp.type=type;tmp.name=name;return tmp;}
    bool operator==(const t_label_info&ref)const{return (ref.type==type)&&(ref.name==name);}
  };
public:
  int add_var(const string&type,const string&name)
  {
    int id=head.vars.size();
    t_var tmp;tmp.name=name;
    tmp.type=type;
    head.vars.push_back(std::move(tmp));
    auto&var=head.vars[id];
    var.value=make_def_value_from_type_impl(var.type);
    return id;
  }
  t_struct_node*find_struct(const string&name){
    auto&arr=scope.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=ex.get();
      auto*p=t_struct_node::UberCast(ptr);
      if(!p)continue;
      if(p->name!=name)continue;
      return p;
    }
    return nullptr;
  }
  t_struct_node&unsafe_find_struct(const string&name){
    auto*p=find_struct(name);
    if(p)return *p;
    QapDebugMsg("type not found:\n"+name);
    return *(t_struct_node*)nullptr;
  }
  t_retval make_retval_from_type(const string&type){
    t_retval tmp;
    tmp.type=type;
    tmp.value=make_def_value_from_type_impl(type);
    return std::move(tmp);
  }
  struct t_array_parser{
    string subtype;
    string count;
    bool go(const string&type)
    {
      const string arr="array{";
      auto pos=type.find(arr);
      if(pos!=0)return false;
      QapAssert(type.back()=='}');
      int c=int(type.size())-int(sizeof('}')+arr.size());
      QapAssert(c>=0);
      auto t=type.substr(arr.size(),c);
      QapAssert(!t.empty());
      auto params=split(t,",");
      QapAssert(params.size()==2);
      subtype=params[0];
      count=params[1];
      return true;
    }
  };
  static bool is_array(const string&type){
    t_array_parser parser;
    return parser.go(type);
  }
  int calc_sizeof_type(const string&type){
    int size=make_def_value_from_type_impl(type).size();
    QapAssert(size>0);
    return size;
  }
  string make_def_value_from_type_impl(const string&type)
  {
    string retval;
    #define POD(TYPE)if(type==#TYPE){retval.resize(sizeof(TYPE));return retval;}
    {
      POD(bool);
      POD(int);
      POD(char);
      POD(real);
    }
    #undef POD
    auto*p=find_struct(type);
    if(p)return DoStructInit(*p);
    if(is_array(type)){
      t_array_parser parser;
      QapAssert(parser.go(type));
      int count=SToI(parser.count);
      string retval;
      string one=make_def_value_from_type_impl(parser.subtype);
      for(int i=0;i<count;i++){
        retval+=one;
      }
      int gg=1;
      return retval;
    }
    QapDebugMsg("type not found:\n"+type);
    return "";
  }
public:
  t_asm_scope scope;
  t_stackframe head;
  vector<t_stackframe> frames;
  vector<t_retval> retval;
  vector<t_label_info> labels;
  string label_name;
  char state;
public:
  //void jump(const string&name){
  //  QapAssert(next_step.empty());
  //  next_step=name;
  //}
public:
  bool isRet()const{return state=='R';}
  bool isErr()const{return state=='E';}
  bool isBre()const{return state=='B';}
  bool isCon()const{return state=='C';}
public:
  void ret(const string&type,const string&value)
  {
    QapAssert(!retval.empty());
    auto&back=retval.back();
    QapAssert(back.type==type);
    QapAssert(back.value.empty());
    back.value=value;
    QapAssert('N'==state);
    state='R';
    QapAssert(label_name.empty());
  }
  void bre(const string&label){
    QapAssert('N'==state);
    state='B';
    QapAssert(label_name.empty());
    label_name=label;
  }
  void con(const string&label){
    QapAssert('N'==state);
    state='C';
    QapAssert(label_name.empty());
    label_name=label;
  }
public:
  void push_label(const t_label_info&info){
    labels.push_back(info);
  }
  void pop_label(const t_label_info&info){
    QapAssert(!labels.empty())
    QapAssert(labels.back()==info);
    labels.pop_back();
  }
public:
  void bef_ret_scope(const t_retval&value)
  {
    t_retval tmp;
    tmp.type=value.type;
    retval.push_back(std::move(tmp));
    QapAssert(label_name.empty());
    QapAssert('N'==state);
  }
  void aft_ret_scope(t_retval&out)
  {
    if(!label_name.empty()){
      QapDebugMsg("label_name not found:\n"+label_name);
      state='E';return;
    }
    QapAssert(label_name.empty());
    QapAssert('R'==state);
    state='N';
    QapAssert(!retval.empty());
    {
      auto&back=retval.back();
      QapAssert(back.type==out.type);
      //QapAssert(!out.value.empty());
      QapAssert(back.value.size()==out.value.size());
      out.value=std::move(back.value);
      QapAssert(out.value.size()==make_def_value_from_type_impl(out.type).size());
    }
    retval.pop_back();
  }
public:
  void push_frame(){
    frames.push_back(std::move(head));
    head=t_stackframe();
  }
  void pop_frame(){
    QapAssert(!frames.empty());
    head=std::move(frames.back());
    frames.pop_back();
  }
public:
  void Do(t_string&ref){}
  void Do(t_number&ref){}
  void Do(t_num_expr&ref){}
  void Do(t_reg_expr&ref){}
public:
  class t_expr_decltype:public t_smart_asm::i_expr_visitor{
  public:
    class t_dev{
    public:
      t_smart_asm_machine&machine;
      string retval;
    };
    t_dev&dev;
    t_expr_decltype(t_dev&dev):dev(dev){}
  public:
    void Do(t_num_expr*p){
      dev.retval="int";
    }
    void Do(t_reg_expr*p)
    {
      dev.retval=dev.machine.DoDeclType(*p);
    }
  };
  class t_expr_calcvalue:public t_smart_asm::i_expr_visitor{
  public:
    class t_dev{
    public:
      t_smart_asm_machine&machine;
      t_retval retval;
      void set_int(int value){
        retval.value.resize(sizeof(value));
        *(int*)& retval.value[0]=value;
        retval.type="int";
      }
    };
    t_dev&dev;
    t_expr_calcvalue(t_dev&dev):dev(dev){}
  public:
    void Do(t_num_expr*p){
      int value=SToI(p->value);
      dev.set_int(value);
      dev.retval.type="int";
    }
    void Do(t_reg_expr*p){
      dev.retval=dev.machine.DoCalcValue(*p);
    }
  };
public:
  class t_stat_visitor:public t_smart_asm::i_stat_visitor{
  public:
    typedef t_smart_asm_machine t_dev;
    t_dev&dev;
    t_stat_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_nop_stat*p){}
    void Do(t_ret_stat*p){
      auto v=dev.DoCalcValue(p->expr);
      dev.ret(v.type,v.value);
    }
  public:
    struct t_calc_params_tool
    {
      vector<string> types;
      vector<t_retval> values;
      void calc(t_smart_asm_machine&dev,t_smart_asm::t_call_stat::t_params&params)
      {
        //calc types
        auto&arr=params.arr;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          string t=dev.DoDeclType(ex);
          types.push_back(t);
        }
        //calc values
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          auto value=dev.DoCalcValue(ex);
          values.push_back(value);
        }
      }
      bool try_call_interal_funcs(t_smart_asm_machine&dev,const string&func,const t_reg_expr&out)
      {
        static vector<string> two_int=split("int,int",",");
        static vector<string> one_int=split("int",",");
        static vector<string> one_char=split("char",",");
        if("mov"==func)if(types.size()==1)
        {
          auto&str_a=values[0];
          dev.DoSetValue(out,str_a);
          return true;
        }
        if("char"==func)if(one_int==types)
        {
          auto&str_a=values[0];
          auto a=(char)str_a.get_int();
          dev.DoSetValue(out,a);
          return true;
        }
        if("inc"==func)if(one_int==types)
        {
          auto str_a=values[0];
          int a=t_str2sys(str_a.value);
          int value=a+1;
          dev.DoSetValue(out,value);
          return true;
        }
        if("inc"==func)if(one_char==types)
        {
          auto str_a=values[0];
          char a=t_str2sys(str_a.value);
          char value=a+1;
          dev.DoSetValue(out,value);
          return true;
        }
        if("dec"==func)if(one_int==types)
        {
          auto str_a=values[0];
          int a=t_str2sys(str_a.value);
          int value=a-1;
          dev.DoSetValue(out,value);
          return true;
        }
        if("eq"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          bool value=a==b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("neq"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          bool value=a!=b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("mod"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          int value=a%b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("div"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          int value=a/b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("mul"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          int value=a*b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("sub"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          int value=a-b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("add"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          int value=a+b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("less"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          bool value=a<b;
          dev.DoSetValue(out,value);
          return true;
        }
        if("more"==func)if(two_int==types)
        {
          auto str_a=values[0];
          auto str_b=values[1];
          int a=t_str2sys(str_a.value);
          int b=t_str2sys(str_b.value);
          bool value=a>b;
          dev.DoSetValue(out,value);
          return true;
        }
        int gg=1;
        return false;
      }
    };
    void Do(t_call_stat*p)
    {
      auto&func_name=p->func.value;
      t_calc_params_tool tool;
      //dev.push_frame();
      for(;;)
      {
        if(p->params)
        {
          auto&params=*p->params.get();
          tool.calc(dev,params);
        }
        //sys_way
        if(true)
        {
          bool ok=tool.try_call_interal_funcs(dev,func_name,p->out);
          if(ok)break;
        }
        //usr_way
        if(true)
        {
          auto&f=dev.unsafe_find_func(func_name,tool.types);
          t_retval value=dev.make_retval_from_type(f.type);
          dev.push_frame();
          {
            auto&arr=f.params;
            for(int i=0;i<arr.size();i++)
            {
              auto&param=arr[i];
              auto&vars=dev.head.vars;
              auto id=dev.add_var(param.type,param.name);
              auto&var=vars[id];
              auto&val=tool.values[i];
              var.value=val.value;
              var.type=val.type;
              QapAssert(param.type==val.type);
            }
            //
            dev.bef_ret_scope(value);
            dev.Do(f.code);
            dev.aft_ret_scope(value);
          }
          dev.pop_frame();
          dev.DoSetValue(p->out,value);
          int gg=1;
          break;
        }
        int gg=1;
        QapDebugMsg("WTF?");
        break;
      }
      //dev.pop_frame();
      return;
    }
    void Do(t_block_stat*p){
      dev.push_frame();
      {
        dev.Do(p->body);
      }
      dev.pop_frame();
    }
    void Do(t_break_stat*p){
      string label="";
      if(p->label){
        label=p->label->name;
      }
      dev.bre(label);
      int gg=1;
    }
    void Do(t_continue_stat*p){
      string label="";
      if(p->label){
        label=p->label->name;
      }
      dev.con(label);
      int gg=1;
    }
    void Do(t_loop_stat*p)
    {
      auto info=t_label_info::make("loop","");
      if(p->label)info.name=p->label->name;
      dev.push_label(info);
      for(;;)
      {
        dev.Do(p->code);
        if(dev.isRet()||dev.isErr())break;
        if(!dev.label_name.empty())
        {
          bool ok=info.name==dev.label_name;
          if(ok)dev.label_name.clear();
          if(!ok)if(dev.isCon()||dev.isBre()){break;}
        }
        if(dev.label_name.empty())
        {
          if(dev.isCon()){dev.state='N';continue;}
          if(dev.isBre()){dev.state='N';break;}
          QapDebugMsg("WTF?");
        }
        int gg=1;
      }
      dev.pop_label(info);
    }
    void Do(t_if_stat*p)
    {
      dev.push_frame();
      {
        t_retval cond=dev.make_retval_from_type("bool");
        dev.bef_ret_scope(cond);
        //do for cond
        {
          auto&block=p->cond.body;
          dev.Do(block);
        }
        dev.aft_ret_scope(cond);
        bool flag=cond.get_bool();
        //do for bef
        if(flag&&p->bef){
          auto&block=p->bef.get()->body;
          dev.Do(block);
        }
        //do for aft
        if(!flag&&p->aft){
          auto&block=p->aft.get()->body;
          dev.Do(block);
        }
      }
      dev.pop_frame();
      int gg=1;
    }
    void Do(t_for_stat*p)
    {
      auto info=t_label_info::make("for","");
      if(p->label)info.name=p->label->name;
      dev.push_label(info);
      {
        QapAssert('N'==dev.state);
        dev.push_frame();
        //do for vars
        {
          auto&arr=p->arr;
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            Do(&ex.var);
          }
        }
        //do for init
        if(p->init)
        {
          auto info=t_label_info::make("init","");
          dev.push_label(info);
          {
            auto&block=p->init.get()->body;
            dev.Do(block);
            QapAssert('N'==dev.state);
          }
          dev.pop_label(info);
        }
        //loop body
        for(int iter=0;;iter++)
        {
          //do for cond
          if(p->cond)
          {
            t_retval cond=dev.make_retval_from_type("bool");
            dev.bef_ret_scope(cond);
            {
              auto info=t_label_info::make("cond","");
              dev.push_label(info);
              {
                auto&block=p->cond.get()->body;
                dev.Do(block);
              }
              dev.pop_label(info);
            }
            dev.aft_ret_scope(cond);
            bool flag=cond.get_bool();
            if(!flag)break;
          }
          //do for body
          if(p->body)
          {
            auto&block=p->body.get()->body;
            dev.Do(block);
          }
          if(dev.isRet()||dev.isErr())break;
          if(!dev.label_name.empty())
          {
            bool ok=info.name==dev.label_name;
            if(ok)dev.label_name.clear();
            if(!ok)if(dev.isCon()||dev.isBre()){break;}
          }
          if(dev.label_name.empty())
          {
            if(dev.isCon()){dev.state='N';}
            if(dev.isBre()){dev.state='N';break;}
          }
          //do for next
          if(p->next)
          {
            auto info=t_label_info::make("next","");
            dev.push_label(info);
            {
              auto&block=p->next.get()->body;
              dev.Do(block);
              QapAssert('N'==dev.state);
            }
            dev.pop_label(info);
          }
          int gg=1;
        }
        dev.pop_frame();
      }
      dev.pop_label(info);
      int gg=1;
    }
  public:
    void Do(t_auto_stat*p){
      QapDebugMsg("no way");
      return;
      auto&source=dev.unsafe_find_reg(p->name.value);
      auto id=dev.add_var(source.type,source.name);
      auto&value=dev.head.vars[id].value;
      value=source.value;
      int gg=1;
    }
    void Do(t_var_stat*p){
      auto&ref=*p;
      string fulltype=ref.type.name.value;
      if(ref.type.params){
        auto*params=ref.type.params.get();
        fulltype+="{"+params->type+","+params->count.value+"}";
      }
      auto id=dev.add_var(fulltype,ref.name.value);
      auto&value=dev.head.vars[id].value;
      int gg=1;
    }
    void Do(t_sep_stat*p){}
  };
public:
  void Do(t_block&ref)
  {
    push_frame();
    t_stat_visitor V(*this);
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=ex.get();
      ptr->Use(V);
      if(isRet())break;
      if(isCon())break;
      if(isBre())break;
      if(isErr())break;
    }
    pop_frame();
    int gg=1;
  }
  void Do(t_type&ref){}
  void Do(t_func_node&ref){
    Do(ref.code);
  }
  void Do(t_struct_node&ref){}
  void Do(t_sep_node&ref){}
  void Do(t_asm_scope&ref){}
public:
  class t_calc_idexpr:public t_reg_expr::t_id::i_case_visitor{
  public:
    class t_dev{
    public:
      t_smart_asm_machine&machine;
      int retval;
    };
    t_dev&dev;
    t_calc_idexpr(t_dev&dev):dev(dev){}
  public:
    void Do(t_num*p){
      dev.retval=SToI(p->value);
      QapAssert(dev.retval>=0);
    }
    void Do(t_reg*p){
      auto&var=dev.machine.unsafe_find_reg(p->value);
      if(var.type!="int"){
        QapDebugMsg("no way.");
        dev.retval=-1;
        return;
      }
      dev.retval=t_str2sys(var.value);
      QapAssert(dev.retval>=0);
    }
  };
public:
  int calc_idexpr(t_smart_asm::t_reg_expr::t_id::i_case*pexpr)
  {
    t_calc_idexpr::t_dev dev={*this};
    t_calc_idexpr V(dev);
    pexpr->Use(V);
    return dev.retval;
  };
public:
  t_func_node&unsafe_find_func_by_name(const string&func)
  {
    auto&arr=scope.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=ex.get();
      auto*p=t_func_node::UberCast(ptr);
      if(!p)continue;
      if(p->name.value!=func)continue;
      return *p;
    }
    QapDebugMsg("function not found:\n"+func);
    return *(t_func_node*)nullptr;
  }
  t_func_node&unsafe_find_func(const string&func,const vector<string>&types)
  {
    auto&arr=scope.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=ex.get();
      auto*p=t_func_node::UberCast(ptr);
      if(!p)continue;
      if(p->name.value!=func)continue;
      //compare
      {
        auto&arr=p->params;
        if(arr.size()!=types.size())continue;
        int ok=-1;
        for(int i=0;i<arr.size();i++){
          if(arr[i].type!=types[i])break;
          ok=i;
        }
        if(ok+1!=types.size())continue;
      }
      return *p;
    }
    QapDebugMsg("function not found:\n"+func+"("+join(types,",")+")");
    return *(t_func_node*)nullptr;
  }
  string DoDeclType(TAutoPtr<i_expr>&expr){
    t_expr_decltype::t_dev dev={*this};
    t_expr_decltype V(dev);
    auto*p=expr.get();
    p->Use(V);
    return dev.retval;
  }
  string DoDeclType(t_reg_expr&expr)
  {
    auto&ref=unsafe_find_reg(expr.name);
    if(!expr.ext)
    {
      return ref.type;
    }
    auto*ptr=expr.ext->body.get();
    auto*p=t_reg_expr::t_field::UberCast(ptr);
    QapAssert(p);
    auto&v=unsafe_find_struct(ref.type);
    auto&arr=v.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.name==p->field)
      {
        return ex.type;
      }
    }
    QapDebugMsg("no way.");
    int gg=1;
    return *(string*)nullptr;
  }
  t_retval DoCalcValue(TAutoPtr<i_expr>&expr){
    t_expr_calcvalue::t_dev dev={*this};
    t_expr_calcvalue V(dev);
    auto*p=expr.get();
    p->Use(V);
    return dev.retval;
  }
  t_retval DoCalcValue(const t_reg_expr&expr)
  {
    t_retval tmp;
    auto&ref=unsafe_find_reg(expr.name);
    if(!expr.ext)
    {
      tmp.type=ref.type;
      tmp.value=ref.value;
      return tmp;
    }
    auto*ptr=expr.ext->body.get();
    auto*p=t_reg_expr::t_field::UberCast(ptr);
    QapAssert(p);
    auto&v=unsafe_find_struct(ref.type);
    int offset=0;
    auto&arr=v.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.name==p->field)
      {
        //QapAssert(ex.type=="int");
        if(ex.type!="int"){
          int gg=1;
        }
        int size=calc_sizeof_type(ex.type);
        QapAssert(ref.value.size()>=offset+size);
        tmp.value=ref.value.substr(offset,size);
        tmp.type=ex.type;
        return tmp;
        break;
      }
      offset+=calc_sizeof_type(ex.type);
    }
    QapDebugMsg("no way.");
    int gg=1;
    return tmp;
  }
  void DoSetValue(const t_reg_expr&expr,int value){
    typedef decltype(value) value_type;
    t_retval retval;
    retval.type="int";
    retval.value.resize(sizeof(value));
    *(value_type*)&retval.value[0]=value;
    DoSetValue(expr,retval);
  }
  void DoSetValue(const t_reg_expr&expr,bool value){
    typedef decltype(value) value_type;
    t_retval retval;
    retval.type="bool";
    retval.value.resize(sizeof(value));
    *(value_type*)&retval.value[0]=value;
    DoSetValue(expr,retval);
  }
  void DoSetValue(const t_reg_expr&expr,char value){
    typedef decltype(value) value_type;
    t_retval retval;
    retval.type="char";
    retval.value.resize(sizeof(value));
    *(value_type*)&retval.value[0]=value;
    DoSetValue(expr,retval);
  }
  void DoSetValue(const t_reg_expr&expr,real value){
    typedef decltype(value) value_type;
    t_retval retval;
    retval.type="real";
    retval.value.resize(sizeof(value));
    *(value_type*)&retval.value[0]=value;
    DoSetValue(expr,retval);
  }
  void DoSetValue(const t_reg_expr&expr,const t_retval&retval)
  {
    //QapAssert(!expr.ext);
    auto&ref=unsafe_find_reg(expr.name);
    if(!expr.ext)
    {
      QapAssert(ref.value.size()==retval.value.size());
      QapAssert(ref.type==retval.type);
      ref.value=retval.value;
      return;
    }
    //QapAssert(retval.type=="int");
    {
      int size=calc_sizeof_type(retval.type);
      QapAssert(retval.value.size()==size);
    }
    auto*ptr=expr.ext->body.get();
    //t_field
    if(t_reg_expr::t_field::UberCast(ptr))
    {
      auto*p=t_reg_expr::t_field::UberCast(ptr);
      QapAssert(p);
      auto&v=unsafe_find_struct(ref.type);
      int offset=0;
      auto&arr=v.arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.name==p->field)
        {
          //QapAssert(retval.type=="int");
          int size=calc_sizeof_type(retval.type);
          QapAssert(retval.value.size()==size);
          QapAssert(ex.type==retval.type);
          QapAssert(ref.value.size()>=offset+size);
          string tmp=retval.value;
          auto*pDest=&ref.value[offset];
          auto*pSource=&tmp[0];
          for(int i=0;i<size;i++)pDest[i]=pSource[i];
          break;
        }
        offset+=calc_sizeof_type(ex.type);
      }
      int gg=1;
      return;
    }
    //t_id
    if(t_reg_expr::t_id::UberCast(ptr))
    {
      auto*p=t_reg_expr::t_id::UberCast(ptr);
      QapAssert(p);
      auto*pexpr=p->idexpr.get();
      int id=calc_idexpr(pexpr);
      QapAssert(is_array(ref.type));
      t_array_parser parser;
      parser.go(ref.type);
      QapAssert(parser.subtype==retval.type);
      int one_size=calc_sizeof_type(parser.subtype);
      int size=SToI(parser.count);
      QapAssert(id<size&&id>=0);
      int offset=id*one_size;
      if(id>=0)
      {
        string tmp=retval.value;
        auto*pDest=&ref.value[offset];
        auto*pSource=&tmp[0];
        for(int i=0;i<one_size;i++)pDest[i]=pSource[i];
      }
      int gg=1;
      return;
    }
  }
  string DoStructInit(t_struct_node&ref){
    string result;
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      result+=make_def_value_from_type_impl(ex.type);
    }
    return result;
  }
  t_var&unsafe_find_reg(const string&name)
  {
    auto id=head.find_var(name);
    if(id>=0)return head.vars[id];
    for(int i=0;i<frames.size();i++){
      auto frame_id=frames.size()-i-1;
      auto&ex=frames[frame_id];
      id=ex.find_var(name);
      if(id>=0)return ex.vars[id];
    }
    QapDebugMsg("regiser not found:\n"+name);
    return *(t_var*)nullptr;
  }
public:
  struct vec3c{char r,g,b;};
  struct t_mem{int count;std::array<vec3c,65536> arr;};
  t_mem main(int r)
  {
    state='N';
    auto result=make_retval_from_type("t_mem");
    auto&f=unsafe_find_func_by_name("main");
    push_frame();
    this->head.vars[add_var("int","r")].value=t_sys2str(r);
    bef_ret_scope(result);
    Do(f);
    aft_ret_scope(result);
    pop_frame();
    QapAssert(result.value.size()==sizeof(t_mem));
    return *(t_mem*)&result.value[0];
  }
  string gb_main(string inp)
  {
    state='N';
    auto&f=unsafe_find_func_by_name("main");
    if(f.params.size()!=1){
      QapDebugMsg("f.params.size = "+IToS(f.params.size())+"\nneed 1");
      return "";
    }
    auto&rettype=f.type;
    auto result=make_retval_from_type(rettype);
    auto&input=f.params[0];
    push_frame();
    auto&value=this->head.vars[add_var(input.type,input.name)].value;
    if(value.size()!=inp.size())
    {
      QapDebugMsg(
        "inp.size is wrong:\n"
        "  inp.size = "+IToS(inp.size())+"\n"
        "  value.size = "+IToS(value.size())
      );
      return "";
    }
    value=inp;
    bef_ret_scope(result);
    Do(f);
    aft_ret_scope(result);
    pop_frame();
    //string str_size=t_sys2str(int(result.value.size()));
    return result.value;
  }
};

void test_2014_03_27(IEnvRTTI&Env)
{
  t_smart_asm_machine machine;
  t_smart_asm::t_asm_scope&scope=machine.scope;
  string content=file_get_contents("smart_asm.asm");
  auto load_status=load_obj_ex(Env,scope,content);
  if(load_status.find("true")>16){
    int fail=1;
    UberInfoBox("load_status",load_status);
  }
  //if(false)
  {
    auto result=machine.main(32);
    int gg=1;
  }
  //UberInfoBox("t_smart_asm::result",load_status+"\n"+QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(scope)));
}

#include "i_object_dev.inl"

template<class TYPE>
static void unsafe_easy_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  t_clone_dev dev={Env};
  dev.dest.ptr.set(Env,dest);
  dev.source.ptr.set(Env,source);
  TCloneVisitor V(dev);
  dev.source.ptr.pType->Use(V);
}

class t_smart_asm_inliner:public t_smart_asm{
public:
  struct t_var{
    string name;
    string type;
  };
  class t_stackframe{
  public:
    vector<t_var> vars;
  public:
    int find_var(const string&name){for(int i=0;i<vars.size();i++){auto&ex=vars[i];if(ex.name==name)return i;}return -1;}
  };
public:
  struct t_label_info{
    string type;
    string name;
    static t_label_info make(const string&type,const string&name){t_label_info tmp;tmp.type=type;tmp.name=name;return tmp;}
    bool operator==(const t_label_info&ref)const{return (ref.type==type)&&(ref.name==name);}
  };
public:
  bool is_systype(const string&type)
  {
    const static vector<string> arr=split("int,char,bool",",");
    for(int i=0;i<arr.size();i++)if(arr[i]==type)return true;
    return false;
  }
  bool is_array(const string&type){
    string v="array{";
    return v==type.substr(0,v.size());
  }
  void reg_type(const string&type)
  {
    auto&arr=all_types;
    for(int i=0;i<arr.size();i++)if(arr[i]==type)return;
    all_types.push_back(type);
    add_user_type(type);
  }
  void add_user_type_from_array(const string&type)
  {
    t_type obj;
    bool ok=load_obj(Env,obj,type);
    if(!ok){
      QapDebugMsg("WTF?\n"+type);
      return;
    }
    QapAssert(obj.params);
    string&subtype=obj.params->type;
    reg_type(subtype);
  }
  void add_user_type(const string&type)
  {
    if(is_systype(type))return;
    if(is_array(type))
    {
      add_user_type_from_array(type);
      return;
    }
    user_types.push_back(type);
    auto&ref=unsafe_find_struct(type);
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      reg_type(ex.type);
    }
    int gg=1;
  }
public:
  int add_var(const string&type,const string&name)
  {
    reg_type(type);
    int id=head.vars.size();
    t_var tmp;tmp.name=name;
    tmp.type=type;
    head.vars.push_back(std::move(tmp));
    return id;
  }
public:
  void push_frame(){
    frames.push_back(std::move(head));
    head=t_stackframe();
  }
  void pop_frame(){
    QapAssert(!frames.empty());
    head=std::move(frames.back());
    frames.pop_back();
  }
public:
  t_struct_node*find_struct(const string&name){
    auto&arr=scope.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=ex.get();
      auto*p=t_struct_node::UberCast(ptr);
      if(!p)continue;
      if(p->name!=name)continue;
      return p;
    }
    return nullptr;
  }
  t_struct_node&unsafe_find_struct(const string&name){
    auto*p=find_struct(name);
    if(p)return *p;
    QapDebugMsg("type not found:\n"+name);
    return *(t_struct_node*)nullptr;
  }
public:
  template<class TYPE>
  string toStr_impl(TYPE&ref){
    string result;
    bool ok=save_obj(Env,ref,result);
    QapAssert(ok);
    return result;
  }
  template<class TYPE>
  string toStr(TAutoPtr<TYPE>&ref){
    if(!ref)return "";
    return toStr_impl(ref);
  }
  template<class TYPE>
  string toStr(TYPE&ref){
    return toStr_impl(ref);
  }
  void add(const string&code)
  {
    if(code=="}")
    {
      pop_frame();
    }
    int fc=frames.size();
    if(code=="{")
    {
      push_frame();
    }
    string ident;
    ident.resize(fc*2,' ');
    out+=ident+code+"\n";
  }
  template<class TYPE>
  void toDev(TYPE*p){
    add(toStr(*p));
  }
  template<class TYPE>
  void clone(TYPE&dest,TYPE&source){
    unsafe_easy_clone(Env,dest,source);
  }
public:
  void with_prefix_mod(string&var_name){
    var_name=with_prefix(var_name);
  }
  void with_prefix_mod(t_var_stat&var){
    with_prefix_mod(var.name.value);
  }
  void with_prefix_mod(TAutoPtr<t_reg_expr::i_ext>&ref){
    if(!t_reg_expr::t_id::UberCast(ref.get()))return;
    auto&idexpr=t_reg_expr::t_id::UberCast(ref.get())->idexpr;
    auto*p=t_reg_expr::t_id::t_reg::UberCast(idexpr.get());
    if(!p)return;
    auto&value=p->value;
    with_prefix_mod(value);
  }
  void with_prefix_mod(t_reg_expr&expr){
    auto&name=expr.name;
    name=with_prefix(name);
    if(!expr.ext)return;
    auto&ext=expr.ext.get()->body;
    with_prefix_mod(ext);
  }
  void with_prefix_mod(TAutoPtr<i_expr>&expr){
    if(!t_reg_expr::UberCast(expr.get()))return;
    auto&ref=*t_reg_expr::UberCast(expr.get());
    with_prefix_mod(ref);
  }
  string toStr_with_prefix(TAutoPtr<i_expr>&ref){
    TAutoPtr<i_expr> expr;
    clone(expr,ref);
    with_prefix_mod(expr);
    return toStr(expr);
  }
  string toStr_with_prefix(t_reg_expr&ref){
    t_reg_expr expr;
    clone(expr,ref);
    with_prefix_mod(expr);
    return toStr(expr);
  }
public:
  bool isCond()const{
    QapAssert(!labels.empty());
    auto&back=labels.back();
    bool flag=back.type=="cond";
    return flag;
  }
  bool isMain()const{
    QapAssert(!labels.empty());
    int counter=0;
    for(int i=0;i<labels.size();i++){
      auto&ex=labels[i];
      if(ex.type!="func")continue;
      counter++;
    }
    QapAssert(counter>0);
    return counter==1;
  }
  string with_prefix(const string&var_name){
    if(isMain())return "_"+var_name;
    return "sub_"+var_name;
  }
public:
  class t_stat_visitor:public t_smart_asm::i_stat_visitor{
  public:
    typedef t_smart_asm_inliner t_dev;
    t_dev&dev;
    t_stat_visitor(t_dev&dev):dev(dev){}
  public:
    template<class TYPE>string toStr(TYPE&ref){return dev.toStr(ref);}
    template<class TYPE>void toDev(TYPE*p){dev.toDev(p);}
    template<class TYPE>void clone(TYPE&dest,TYPE&source){dev.clone(dest,source);}
    void add(const string&code){dev.add(code);}
    void add_label(const string&block,TAutoPtr<t_label>&label){
      string ext="";
      if(label){
        ext=":"+label.get()->name;
      }
      add(block+ext);
    }
  public:
    void Do(t_nop_stat*p){toDev(p);}
    void Do(t_ret_stat*p){
      auto t=dev.DoDeclType(p->expr);
      dev.ret(t);
      if(dev.isMain()||dev.isCond()){
        add("ret "+toStr_with_prefix(p->expr));
        return;
      }
      add("call \"mov\" $ "+toStr_with_prefix(p->expr));
    }
  public:
    struct t_calc_params_tool
    {
      typedef t_smart_asm::t_call_stat::t_params t_params;
      vector<string> types;
      void calc(t_smart_asm_inliner&dev,t_params&params)
      {
        //calc types
        auto&arr=params.arr;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          string t=dev.DoDeclType(ex);
          types.push_back(t);
        }
      }
      void calc(t_smart_asm_inliner&dev,TAutoPtr<t_params>&params){
        if(!params)return;
        auto&ref=*params.get();
        calc(dev,ref);
      }
    };
  public:
    typedef t_smart_asm::t_call_stat::t_params t_call_stat_params;
    typedef t_smart_asm::t_func_node::t_param t_func_node_param;
    typedef vector<t_func_node_param> t_func_node_params;
    //
    void gen_func_params(t_call_stat_params&params,t_func_node_params&fparams){
      static const string quote="\"";
      static const string mov=quote+"mov"+quote;
      QapAssert(fparams.size()==params.arr.size());
      auto&arr=params.arr;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&fex=fparams[i];
        auto dest="top_"+fex.name;
        auto source=toStr_with_prefix(ex);
        auto init="{call "+mov+" "+dest+" "+source+"}";
        auto type=fex.type;
        add("var "+type+" "+dest+init);
        dev.add_var(type,dest);
      }
    }
    void gen_func_params(TAutoPtr<t_call_stat_params>&params,t_func_node_params&fparams){
      if(!params)return;
      auto&ref=*params.get();
      gen_func_params(ref,fparams);
    }
    void gen_func_param_proxy(t_func_node_params&fparams){
      static const string quote="\"";
      static const string mov=quote+"mov"+quote;
      auto&arr=fparams;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto dest=with_prefix(ex.name);
        auto source="top_"+ex.name;
        auto init="{call "+mov+" "+dest+" "+source+"}";
        auto type=ex.type;
        add("var "+type+" "+dest+init);
        dev.add_var(type,dest);
      }
    }
  public:
    string with_prefix(const string&var_name){return dev.with_prefix(var_name);}
    void with_prefix_mod(t_var_stat&var){dev.with_prefix_mod(var);}
    void with_prefix_mod(TAutoPtr<i_expr>&expr){dev.with_prefix_mod(expr);}
    string toStr_with_prefix(TAutoPtr<i_expr>&ref){return dev.toStr_with_prefix(ref);}
    string toStr_with_prefix(t_reg_expr&ref){return dev.toStr_with_prefix(ref);}
  public:
    void Do(t_call_stat*p)
    {
      static const string quote="\"";
      static const string mov=quote+"mov"+quote;
      //sys way
      if(true)
      {
        static const vector<string> sys_funcs=split("mov,add,sub,div,mod,mul,more,less,eq,neq,inc,dec",",");
        bool ok=false;
        for(int i=0;i<sys_funcs.size();i++)if(sys_funcs[i]==p->func.value)ok=true;
        if(ok)
        {
          t_call_stat stat;
          clone(stat,*p);
          auto&arr=stat.params.get()->arr;
          for(int i=0;i<arr.size();i++)
          {
            auto&expr=arr[i];
            with_prefix_mod(expr);
          }
          dev.with_prefix_mod(stat.out);
          add(toStr(stat));
          return;
        }
        int gg=1;
      }
      t_calc_params_tool tool;
      tool.calc(dev,p->params);
      auto&f=dev.unsafe_find_func(p->func.value,tool.types);
      auto info=t_label_info::make("func",f.name.value+"()");
      add("{");
      {
        gen_func_params(p->params,f.params);
        add("var "+f.type+" $");
        dev.add_var(f.type,"$");
        {
          add("{");
          {
            dev.push_label(info);
            gen_func_param_proxy(f.params);
            dev.Do(f.code);
            dev.pop_label(info);
          }
          add("}");
          add("call "+mov+" "+toStr_with_prefix(p->out)+" $");
        }
      }
      add("}");
    }
    void Do(t_block_stat*p){
      dev.Do(p->body);
    }
    void Do(t_break_stat*p){
      add_label("break",p->label);
    }
    void Do(t_continue_stat*p){
      add_label("continue",p->label);
    }
    void Do(t_loop_stat*p)
    {
      auto info=t_label_info::make("loop","");
      if(p->label)info.name=p->label->name;
      dev.push_label(info);
      {
        add_label("loop",p->label);
        dev.Do(p->code);
      }
      dev.pop_label(info);
      int gg=1;
    }
    void Do(t_if_stat*p)
    {
      auto info=t_label_info::make("if","");
      dev.push_label(info);
      {
        add("if");
        add("{");
        if(true)
        {
          auto info=t_label_info::make("cond","");
          dev.push_label(info);
          {
            add("cond");
            dev.Do(p->cond.body);
          }
          dev.pop_label(info);
        }
        if(p->bef)
        {
          auto info=t_label_info::make("then","");
          dev.push_label(info);
          {
            add("then");
            dev.Do(p->bef->body);
          }
          dev.pop_label(info);
        }
        if(p->aft)
        {
          auto info=t_label_info::make("else","");
          dev.push_label(info);
          {
            add("else");
            dev.Do(p->aft->body);
          }
          dev.pop_label(info);
        }
        add("}");
      }
      dev.pop_label(info);
      int gg=1;
    }
    void Do(t_for_stat*p)
    {
      auto info=t_label_info::make("for","");
      if(p->label)info.name=p->label->name;
      dev.push_label(info);
      {
        add_label("for",p->label);
        add("{");
        {
          auto&arr=p->arr;
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            t_var_stat tmp;
            clone(tmp,ex.var);
            with_prefix_mod(tmp);
            add(toStr(tmp));
            dev.add_var(toStr(tmp.type),tmp.name.value);
          }
        }
        #define F(NAME)\
          /*BEG*/\
          if(p->NAME)\
          {\
            static const string name=#NAME;\
            auto info=t_label_info::make(name,"");\
            dev.push_label(info);\
            add(name);\
            dev.Do(p->NAME->body);\
            dev.pop_label(info);\
          }\
          /*END*/
        //
        F(init);
        F(cond);
        F(body);
        F(next);
        //
        #undef F
        add("}");
      }
      dev.pop_label(info);
      int gg=1;
    }
  public:
    void Do(t_auto_stat*p){
      QapDebugMsg("no way");
      return;
      t_auto_stat stat;
      clone(stat,*p);
      auto&name=stat.name.value;
      name="sub_"+name;
      add(toStr(stat));
      //
      auto&reg=dev.find_reg(name);
      QapAssert(reg.isOK());
      if(reg.frame_id<0){
        QapDebugMsg(
          "t_auto_stat refer to register in head.\n"
          "it is wrong.\n"
          "for p->name:\n"+p->name.value
        );
        return;
      }
      auto&source=reg.get(dev);
      auto id=dev.add_var(source.type,source.name);
      int gg=1;
    }
    void Do(t_var_stat*p){
      t_var_stat stat;
      clone(stat,*p);
      auto&name=stat.name.value;
      name=with_prefix(name);
      add(toStr(stat));
      //
      auto&ref=*p;
      string fulltype=toStr(ref.type);
      auto id=dev.add_var(fulltype,name);
    }
    void Do(t_sep_stat*p){
      //toDev(p);
    }
  };
public:
  struct t_reg_id{
    int frame_id;
    int id;
    void init(){frame_id=-1;id=-1;}
    bool isOK(){return id>=0;}
    t_var&get(t_smart_asm_inliner&ref)const{
      auto&frame=frame_id<0?ref.head:ref.frames[frame_id];
      return frame.vars[id];
    }
  };
  t_reg_id find_reg(const string&name)
  {
    t_reg_id result;
    result.init();
    auto&frame_id=result.frame_id;
    auto&id=result.id;
    result.id=head.find_var(name);
    if(result.id>=0)return result;
    for(int i=0;i<frames.size();i++){
      frame_id=frames.size()-i-1;
      auto&ex=frames[frame_id];
      id=ex.find_var(name);
      if(id>=0)return result;
    }
    result.init();
    return result;
  }
  t_var&unsafe_find_reg(const string&name)
  {
    auto v=find_reg(name);
    if(v.isOK())return v.get(*this);
    QapDebugMsg("regiser not found:\n"+name);
    return *(t_var*)nullptr;
  }
public:
  void ret(const string&type)
  {
    //QapDebugMsg("no way");
  }
public:
  /*copy-paste*/class t_expr_decltype:public t_smart_asm::i_expr_visitor{
  /*copy-paste*/public:
  /*copy-paste*/  class t_dev{
  /*copy-paste*/  public:
  /*copy-paste*/    t_smart_asm_inliner&machine;
  /*copy-paste*/    string retval;
  /*copy-paste*/  };
  /*copy-paste*/  t_dev&dev;
  /*copy-paste*/  t_expr_decltype(t_dev&dev):dev(dev){}
  /*copy-paste*/public:
  /*copy-paste*/  void Do(t_num_expr*p){
  /*copy-paste*/    dev.retval="int";
  /*copy-paste*/  }
  /*copy-paste*/  void Do(t_reg_expr*p)
  /*copy-paste*/  {
  /*copy-paste*/    dev.retval=dev.machine.DoDeclType(*p);
  /*copy-paste*/  }
  /*copy-paste*/};
  /*copy-paste*/t_func_node&unsafe_find_func(const string&func,const vector<string>&types)
  /*copy-paste*/{
  /*copy-paste*/  auto&arr=scope.arr;
  /*copy-paste*/  for(int i=0;i<arr.size();i++)
  /*copy-paste*/  {
  /*copy-paste*/    auto&ex=arr[i];
  /*copy-paste*/    auto*ptr=ex.get();
  /*copy-paste*/    auto*p=t_func_node::UberCast(ptr);
  /*copy-paste*/    if(!p)continue;
  /*copy-paste*/    if(p->name.value!=func)continue;
  /*copy-paste*/    //compare
  /*copy-paste*/    {
  /*copy-paste*/      auto&arr=p->params;
  /*copy-paste*/      if(arr.size()!=types.size())continue;
  /*copy-paste*/      int ok=-1;
  /*copy-paste*/      for(int i=0;i<arr.size();i++){
  /*copy-paste*/        if(arr[i].type!=types[i])break;
  /*copy-paste*/        ok=i;
  /*copy-paste*/      }
  /*copy-paste*/      if(ok+1!=types.size())continue;
  /*copy-paste*/    }
  /*copy-paste*/    return *p;
  /*copy-paste*/  }
  /*copy-paste*/  QapDebugMsg("function not found:\n"+func+"("+join(types,",")+")");
  /*copy-paste*/  return *(t_func_node*)nullptr;
  /*copy-paste*/}
  /*copy-paste*/string DoDeclType(TAutoPtr<i_expr>&expr){
  /*copy-paste*/  t_expr_decltype::t_dev dev={*this};
  /*copy-paste*/  t_expr_decltype V(dev);
  /*copy-paste*/  auto*p=expr.get();
  /*copy-paste*/  p->Use(V);
  /*copy-paste*/  return dev.retval;
  /*copy-paste*/}
  /*copy-paste*/string DoDeclType(t_reg_expr&expr)
  /*copy-paste*/{
  /*copy-paste*/  auto&ref=unsafe_find_reg(with_prefix(expr.name));
  /*copy-paste*/  if(!expr.ext)
  /*copy-paste*/  {
  /*copy-paste*/    return ref.type;
  /*copy-paste*/  }
  /*copy-paste*/  auto*ptr=expr.ext->body.get();
  /*copy-paste*/  auto*p=t_reg_expr::t_field::UberCast(ptr);
  /*copy-paste*/  QapAssert(p);
  /*copy-paste*/  auto&v=unsafe_find_struct(ref.type);
  /*copy-paste*/  auto&arr=v.arr;
  /*copy-paste*/  for(int i=0;i<arr.size();i++)
  /*copy-paste*/  {
  /*copy-paste*/    auto&ex=arr[i];
  /*copy-paste*/    if(ex.name==p->field)
  /*copy-paste*/    {
  /*copy-paste*/      return ex.type;
  /*copy-paste*/    }
  /*copy-paste*/  }
  /*copy-paste*/  QapDebugMsg("no way.");
  /*copy-paste*/  int gg=1;
  /*copy-paste*/  return *(string*)nullptr;
  /*copy-paste*/}
public:
  t_func_node&unsafe_find_func_by_name(const string&func)//copy-paste
  {                                                      //copy-paste
    auto&arr=scope.arr;                                  //copy-paste
    for(int i=0;i<arr.size();i++)                        //copy-paste
    {                                                    //copy-paste
      auto&ex=arr[i];                                    //copy-paste
      auto*ptr=ex.get();                                 //copy-paste
      auto*p=t_func_node::UberCast(ptr);                 //copy-paste
      if(!p)continue;                                    //copy-paste
      if(p->name.value!=func)continue;                   //copy-paste
      return *p;                                         //copy-paste
    }                                                    //copy-paste
    QapDebugMsg("function not found:\n"+func);           //copy-paste
    return *(t_func_node*)nullptr;                       //copy-paste
  }                                                      //copy-paste
public:
  void push_label(const t_label_info&info){
    labels.push_back(info);
  }
  void pop_label(const t_label_info&info){
    QapAssert(!labels.empty())
    QapAssert(labels.back()==info);
    labels.pop_back();
  }
public:
  // DEF_PRO_VARIABLE <----------
public:
  IEnvRTTI&Env;
  t_smart_asm::t_asm_scope scope;
  t_stackframe head;
  vector<t_stackframe> frames;
  vector<t_label_info> labels;
  vector<string> user_types;
  vector<string> all_types;
  string out;
public:
  t_smart_asm_inliner(IEnvRTTI&Env):Env(Env){}
public:
  void Do(t_block&block){
    add("{");
    t_stat_visitor V(*this);
    auto&arr=block.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex->Use(V);
    }
    add("}");
  }
public:
  void Do()
  {
    auto&f=unsafe_find_func_by_name("main");
    auto info=t_label_info::make("func",f.name.value+"()");
    push_label(info);
    {
      string params_code;
      if(!f.params.empty())
      {
        vector<t_func_node::t_param> params;
        clone(params,f.params);
        for(int i=0;i<params.size();i++){
          auto&ex=params[i];
          auto&name=ex.name;
          name=with_prefix(name);
          add_var(ex.type,ex.name);
        }
        params_code=toStr(params);
      }
      add(f.type+" "+toStr(f.name)+"("+params_code+")asm");
      Do(f.code);
    }
    pop_label(info);
    //add user types
    string out_types;
    {
      auto&arr=user_types;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&ref=unsafe_find_struct(ex);
        out_types+=toStr(ref)+"\n";
      }
    }
    out=out_types+out;
  }
};

void test_2014_04_17(IEnvRTTI&Env)
{
  t_smart_asm_inliner machine(Env);
  t_smart_asm::t_asm_scope&scope=machine.scope;
  string code=file_get_contents("smart_asm_inliner_test.asm");
  auto load_status=load_obj_ex(Env,scope,code);
  if(load_status.find("true")>16){
    int fail=1;
    UberInfoBox("load_status",load_status);return;
  }
  machine.Do();
  auto out=machine.out;
  UberInfoBox("2014.04.18 smart asm inliner test",out);
  int gg=1;
}

#include "smart_asm_inliner_with_level.inl"

void test_2014_04_24(IEnvRTTI&Env)
{
  t_smart_asm_level_inliner machine(Env);
  t_smart_asm::t_asm_scope&scope=machine.scope;
  string code=file_get_contents("smart_asm_level_inliner_test.asm");
  auto load_status=load_obj_ex(Env,scope,code);
  if(load_status.find("true")>16){
    int fail=1;
    UberInfoBox("load_status",load_status);return;
  }
  machine.Do();
  auto out=machine.out;
  UberInfoBox("2014.04.24 smart asm level inliner test",out);
  int gg=1;
}

class t_smart_asm_funcs{
public:
  class gen_inl_smart_asm:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(gen_inl_smart_asm)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDVAR(2,string,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>gen_inl_smart_asm
  #include "QapGenStruct.inl"
  //<<<<<+=====gen_inl_smart_asm
  public:
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start();
      t_smart_asm_inliner machine(Env);
      t_smart_asm::t_asm_scope&scope=machine.scope;
      auto load_status=load_obj_ex(Env,scope,code);
      if(load_status.find("true")>16){
        int fail=1;
        UberInfoBox("load_status",load_status);return;
      }
      machine.Do();
      out=machine.out;
      int gg=1;
    }
  };
  class build_smart_asm_hack:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(build_smart_asm_hack)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>build_smart_asm_hack
  #include "QapGenStruct.inl"
  //<<<<<+=====build_smart_asm_hack
  public:
    class t_app{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_app)OWNER(build_smart_asm_hack)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,name,DEF,$,$)\
    ADDVAR(1,string,code,DEF,$,$)\
    ADDVAR(2,t_smart_asm::t_asm_scope,scope,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_app
    #include "QapGenStruct.inl"
    //<<<<<+=====t_app
    public:
    };
    static vector<t_app>&hack(){
      static vector<t_app> arr;
      arr.reserve(128);
      return arr;
    }
    static bool destroy_app(const string&name)
    {
      auto&arr=hack();
      vector<build_smart_asm_hack::t_app> out;
      int count=0;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.name==name){
          count++;
          continue;
        }
        out.push_back(std::move(ex));
      }
      arr=std::move(out);
      return count>0;
    }
    static void init_machine(t_smart_asm_machine&machine,const string&name){
      auto&arr=hack();
      for(int i=0;i<arr.size();i++){
        if(arr[i].name==name){
          machine.scope=std::move(arr[i].scope);
          return;
        }
      }
    }
    static void free_machine(t_smart_asm_machine&machine,const string&name){
      auto&arr=hack();
      for(int i=0;i<arr.size();i++){
        if(arr[i].name==name){
          arr[i].scope=std::move(machine.scope);
          return;
        }
      }
    }
    void exec(IEnvRTTI&Env)
    {
      t_app app;
      t_smart_asm::t_asm_scope&scope=app.scope;
      auto load_status=load_obj_ex(Env,scope,code);
      if(load_status.find("true")>16){
        int fail=1;
        UberInfoBox("load_status",load_status);return;
      }
      out="app{"+cur_date_str()+","+IToS(hack().size())+"}";
      app.code=code;
      app.name=out;
      hack().push_back(std::move(app));
      int gg=1;
    }
  };
  class destroy_smart_asm_hack:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(destroy_smart_asm_hack)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,bool,ok,DEF,$,$)\
  ADDVAR(1,string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>destroy_smart_asm_hack
  #include "QapGenStruct.inl"
  //<<<<<+=====destroy_smart_asm_hack
  public:
    void exec(IEnvRTTI&Env)
    {
      ok=build_smart_asm_hack::destroy_app(name);
      int gg=1;
    }
  };
  class exec_gb_smart_asm_hack:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(exec_gb_smart_asm_hack)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,name,DEF,$,$)\
  ADDVAR(2,string,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>exec_gb_smart_asm_hack
  #include "QapGenStruct.inl"
  //<<<<<+=====exec_gb_smart_asm_hack
  public:
    void exec(IEnvRTTI&Env)
    {
      t_smart_asm_machine machine;
      build_smart_asm_hack::init_machine(machine,name);
      out=machine.gb_main(inp);
      build_smart_asm_hack::free_machine(machine,name);
      int gg=1;
    }
  };
  class run_gb_smart_asm_code_ast:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(run_gb_smart_asm_code_ast)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,ast,DEF,$,$)\
  ADDVAR(2,string,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>run_gb_smart_asm_code_ast
  #include "QapGenStruct.inl"
  //<<<<<+=====run_gb_smart_asm_code_ast
  public:
    void exec(IEnvRTTI&Env)
    {
      t_smart_asm_machine machine;
      t_smart_asm::t_asm_scope&scope=machine.scope;
      bool ok=QapPublicUberFullLoaderBinMem(Env,QapRawUberObject(scope),ast);
      QapAssert(ok);
      out.clear();
      out=machine.gb_main(inp);
      int gg=1;
    }
  };
  class conv_smart_asm_code_ast_toProto:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(conv_smart_asm_code_ast_toProto)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,ast,DEF,$,$)\
  ADDEND()
  //=====+>>>>>conv_smart_asm_code_ast_toProto
  #include "QapGenStruct.inl"
  //<<<<<+=====conv_smart_asm_code_ast_toProto
  public:
    void exec(IEnvRTTI&Env)
    {
      t_smart_asm_machine machine;
      t_smart_asm::t_asm_scope&scope=machine.scope;
      bool ok=QapPublicUberFullLoaderBinMem(Env,QapRawUberObject(scope),ast);
      QapAssert(ok);
      out=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(scope));
      int gg=1;
    }
  };
  class conv_smart_asm_code_ast_to_str:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(conv_smart_asm_code_ast_to_str)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>conv_smart_asm_code_ast_to_str
  #include "QapGenStruct.inl"
  //<<<<<+=====conv_smart_asm_code_ast_to_str
  public:
    void exec(IEnvRTTI&Env)
    {
      t_smart_asm_machine machine;
      t_smart_asm::t_asm_scope&scope=machine.scope;
      auto load_status=load_obj_ex(Env,scope,code);
      if(load_status.find("true")>16){
        int fail=1;
        UberInfoBox("load_status",load_status);return;
      }
      out.clear();
      bool ok=QapPublicUberFullSaverBinMem(Env,QapRawUberObject(scope),out);
      QapAssert(ok);
      int gg=1;
    }
  };
  class run_gb_smart_asm:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(run_gb_smart_asm)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDVAR(2,string,inp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>run_gb_smart_asm
  #include "QapGenStruct.inl"
  //<<<<<+=====run_gb_smart_asm
  public:
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start();
      t_smart_asm_machine machine;
      t_smart_asm::t_asm_scope&scope=machine.scope;
      auto load_status=load_obj_ex(Env,scope,code);
      if(load_status.find("true")>16){
        int fail=1;
        UberInfoBox("load_status",load_status);return;
      }
      if(0)QapDebugMsg("loadtime = "+FToS(clock.MS()*1000.0));
      real bef_run=clock.MS();
      out=machine.gb_main(inp);
      if(0)QapDebugMsg("runtime = "+FToS((clock.MS()-bef_run)*1000.0));
      //UberInfoBox("t_smart_asm::result",load_status+"\n"+QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(scope)));
      int gg=1;
    }
  };
  class run_smart_asm:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(run_smart_asm)PARENT(i_sysfunc_with_rtti)OWNER(t_smart_asm_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,code,DEF,$,$)\
  ADDVAR(2,int,r,DEF,$,$)\
  ADDEND()
  //=====+>>>>>run_smart_asm
  #include "QapGenStruct.inl"
  //<<<<<+=====run_smart_asm
  public:
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start();

      t_smart_asm_machine machine;
      t_smart_asm::t_asm_scope&scope=machine.scope;
      auto load_status=load_obj_ex(Env,scope,code);
      if(load_status.find("true")>16){
        int fail=1;
        UberInfoBox("load_status",load_status);return;
      }
      QapDebugMsg("loadtime = "+FToS(clock.MS()*1000.0));
      real bef_run=clock.MS();
      //if(false)
      {
        auto result=machine.main(r);
        out.resize(sizeof(result));
        for(int i=0;i<out.size();i++)out[i]=((char*)&result)[i];
        string size_str=t_smart_asm_machine::t_sys2str(int(out.size()));
        out=size_str+out;
        //int gg=1;
      }
    
      QapDebugMsg("runtime = "+FToS((clock.MS()-bef_run)*1000.0));
      //UberInfoBox("t_smart_asm::result",load_status+"\n"+QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(scope)));
      int gg=1;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(run_smart_asm)F(run_gb_smart_asm)F(gen_inl_smart_asm)\
  F(run_gb_smart_asm_code_ast)F(conv_smart_asm_code_ast_toProto)F(conv_smart_asm_code_ast_to_str)\
  F(build_smart_asm_hack)F(exec_gb_smart_asm_hack)F(destroy_smart_asm_hack)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_smart_asm_funcs)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_smart_asm_funcs
#include "QapGenStruct.inl"
//<<<<<+=====t_smart_asm_funcs
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
        F(TType)F(t_smart_asm)F(t_smart_asm_funcs)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      //test_2014_03_27(Env);
      //test_2014_04_17(Env);
      //test_2014_04_24(Env);
    }
    ThisCompileUnit(){
      int i=0;
      i>>=1;
      i<<=1;
      int gg=1+i;   
    }
  };
  ThisCompileUnit ThisUnit;
}
class i_templ_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_templ_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_templ_item
#include "QapGenStruct.inl"
//<<<<<+=====i_templ_item
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load()
    {
      F(t_templ_char);
      F(t_templ_var);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
    #include "QapLexPolyEnd.inl"
  };
  virtual bool isVar()const{return false;}
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
};

class t_templ_var;

class t_any_char{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_any_char)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,char,body,SET,'\0',$)\
ADDEND()
//=====+>>>>>t_any_char
#include "QapGenStruct.inl"
//<<<<<+=====t_any_char
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    static const string any_dip=dip_inv("");
    D+=dev.go_any_char(body,any_dip);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return CToS(body);}
};

class t_templ_char:public i_templ_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_char)PARENT(i_templ_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_any_char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_char
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_char
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_minor<t_templ_var>(body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body.get_code();}
};

class t_templ_var:public i_templ_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_var)PARENT(i_templ_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,t_name,name,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_var
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_var
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    static const string c3="^^^";
    D+=dev.go_const(c3);
    if(!ok)return ok;
    D+=dev.go_auto(name);
    if(!ok)return ok;
    D+=dev.go_const(c3);
    if(!ok)return ok;
    return ok;
  }
  bool isVar()const{return true;}
  string get_code()const{return name.get();}
};

class t_templ_sys{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_sys)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TAutoPtr<i_templ_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_sys
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_sys
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
public:
  class t_out{
  public:
    class t_rec{
    public:
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rec)OWNER(t_out)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(0,bool,var,SET,false,$)\
      ADDVAR(1,string,data,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_rec
      #include "QapGenStruct.inl"
      //<<<<<+=====t_rec
    public:
    };
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_out)OWNER(t_templ_sys)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,vector<t_rec>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_out
    #include "QapGenStruct.inl"
    //<<<<<+=====t_out
  public:
  };
public:
  t_out get_code()const{
    t_out out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto var=ex->isVar();
      auto code=ex->get_code();
      out.arr.push_back(t_out::t_rec());
      out.arr.back().var=var;
      out.arr.back().data=code;
    }
    return out;
  }
  static t_out optimize(const t_out&inp){
    t_out out;
    auto&arr=inp.arr;
    if(arr.empty())return std::move(out);
    string buff;
    typedef t_out::t_rec t_rec;
    auto update=[&out,&buff]()->void{
      if(buff.empty())return;
      t_rec tmp;
      tmp.data=buff;
      tmp.var=false;
      out.arr.push_back(std::move(tmp));
      buff.clear();
    };
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(!ex.var){
        buff+=ex.data;continue;
      }
      update();
      t_out::t_rec tmp;
      tmp.data=ex.data;
      tmp.var=ex.var;
      out.arr.push_back(std::move(tmp));
    }
    update();
    return out;
  }
public:
  struct t_inp{
    struct t_rec{
      string from;
      string to;
    };
    vector<t_rec> arr;
    void add(const string&from,const string&to){
      t_rec tmp={from,to};
      arr.push_back(std::move(tmp));
    }
    string lookup(const string&var)const{
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.from==var)return ex.to;
      }
      QapAssert(false);
      return "";
    }
  };
  string eval(const t_inp&inp)const
  {
    string out;
    auto const tmp=get_code().arr;
    for(int i=0;i<tmp.size();i++){
      auto&ex=tmp[i];
      if(!ex.var){
        out+=ex.data;
        continue;
      }
      out+=inp.lookup(ex.data);
    }
    return out;
  }
};
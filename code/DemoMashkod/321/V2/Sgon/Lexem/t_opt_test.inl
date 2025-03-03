//time = 7.93 ms.

class t_opt_test_lex_scope{
public:
  class t_mov{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_mov)OWNER(t_opt_test_lex_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,bef,DEF,$,$)\
  ADDVAR(1,vector<t_name>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_mov
  #include "QapGenStruct.inl"
  //<<<<<+=====t_mov
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_name>(bef);
      if(!ok)return ok;
      D+=dev.go_const("=");
      if(!ok)return ok;
      D+=dev.go_vec(arr," ");
      if(!ok)return ok;
      D+=dev.go_const("\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_ret{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret)OWNER(t_opt_test_lex_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,var,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ret
  #include "QapGenStruct.inl"
  //<<<<<+=====t_ret
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("ret ");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(var);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_program{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_program)OWNER(t_opt_test_lex_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<t_mov>,arr,DEF,$,$)\
  ADDVAR(1,t_ret,ret,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_program
  #include "QapGenStruct.inl"
  //<<<<<+=====t_program
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      D+=dev.go_auto(ret);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_mov    )\
  F(t_ret    )\
  F(t_program)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_opt_test_lex_scope)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_opt_test_lex_scope
#include "QapGenStruct.inl"
//<<<<<+=====t_opt_test_lex_scope
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_opt_test_lex_scope::TYPE TYPE;
  //  F(t_mov);
  //  F(t_ret);
  //  F(t_program);
  //  #undef F
  //public:
  //  void Do(t_mov&ref){}
  //  void Do(t_ret&ref){}
  //  void Do(t_program&ref){}
  //};
};

/*
//list of types:
F(t_opt_test_lex_scope)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fopt%5Ftest%5Flex%5Fscope%7B%0D%0At%5Fmov%7B%0D%0A%20%20string%20bef%3B%0D%0A
%20%20vector%3Ct%5Fname%3E%20arr%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fstr%3Ct
%5Fname%3E%28bef%29%3B%0D%0A%20%20%20%20go%5Fconst%28%22%3D%22%29%3B%0D%0A%20%20
%20%20go%5Fvec%28arr%2C%22%20%22%29%3B%0D%0A%20%20%20%20go%5Fconst%28%22%5Cn%22%
29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fret%7B%0D%0A%20%20string%20var%3B%0
D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fconst%28%22ret%20%22%29%3B%0D%0A%20%20%20%20
go%5Fstr%3Ct%5Fname%3E%28var%29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%0D%0At%5Fprogra
m%7B%0D%0A%20%20vector%3Ct%5Fmov%3E%20arr%3B%0D%0A%20%20t%5Fret%20ret%3B%0D%0A%2
0%20%7B%0D%0A%20%20%20%20go%5Fauto%28arr%29%3B%0D%0A%20%20%20%20go%5Fauto%28ret%
29%3B%0D%0A%20%20%7D%0D%0A%7D%0D%0A%7D
*/
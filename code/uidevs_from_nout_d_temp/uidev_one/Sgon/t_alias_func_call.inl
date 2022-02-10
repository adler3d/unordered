//time = 6.57 ms.

class t_alias_func_call{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_alias_func_call)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,alias,DEF,$,$)\
ADDVAR(string,func,DEF,$,$)\
ADDVAR(string,str_param,DEF,$,$)\
ADDEND()
//=====+>>>>>t_alias_func_call
#include "QapGenStruct.inl"
//<<<<<+=====t_alias_func_call
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("auto ");
    if(!ok)return ok;
    D+=dev.go_str<t_name>(alias);
    if(!ok)return ok;
    D+=dev.go_const("=");
    if(!ok)return ok;
    D+=dev.go_str<t_name>(func);
    if(!ok)return ok;
    D+=dev.go_const("(");
    if(!ok)return ok;
    D+=dev.go_str<t_str_item::t_impl>(str_param);
    if(!ok)return ok;
    D+=dev.go_const(")");
    if(!ok)return ok;
    return ok;
  }
};

/*
//list of types:
F(t_alias_func_call)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Falias%5Ffunc%5Fcall%7B%0A%20%20string%20alias%3B%0A%20%20string%20func%3B%0A
%20%20string%20str%5Fparam%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22auto%20%
22%29%3B%0A%20%20%20%20go%5Fstr%3Ct%5Fname%3E%28alias%29%3B%0A%20%20%20%20go%5Fc
onst%28%22%3D%22%29%3B%0A%20%20%20%20go%5Fstr%3Ct%5Fname%3E%28func%29%3B%0A%20%2
0%20%20go%5Fconst%28%22%28%22%29%3B%0A%20%20%20%20go%5Fstr%3Ct%5Fstr%5Fitem%3A%3
At%5Fimpl%3E%28str%5Fparam%29%3B%0A%20%20%20%20go%5Fconst%28%22%29%22%29%3B%0A%2
0%20%7D%0A%7D
*/
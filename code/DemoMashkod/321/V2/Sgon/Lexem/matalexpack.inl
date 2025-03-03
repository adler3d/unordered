class t_matalexpack{
public:
  class t_num{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)OWNER(t_matalexpack)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num
  #include "QapGenStruct.inl"
  //<<<<<+=====t_num
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const string g_static_dip_0=gen_dips("09");
      D+=dev.go_any(body,g_static_dip_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_rec{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_rec)OWNER(t_matalexpack)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,t_num,bef,DEF,$,$)\
  ADDVAR(1,t_str_item,aft,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_rec
  #include "QapGenStruct.inl"
  //<<<<<+=====t_rec
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(bef);
      if(!ok)return ok;
      D+=dev.go_const(":");
      if(!ok)return ok;
      D+=dev.go_auto(aft);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_list{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_list)OWNER(t_matalexpack)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<t_rec>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_list
  #include "QapGenStruct.inl"
  //<<<<<+=====t_list
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_vec(arr,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)F(t_num)F(t_rec)F(t_list)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_matalexpack)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_matalexpack
#include "QapGenStruct.inl"
//<<<<<+=====t_matalexpack
public:
};

/*
//list of types:
F(t_matalexpack)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fmatalexpack%7B%0A%20%20t%5Fnum%7Bstring%20body%3B%7Bgo%5Fany%28body%2Cgen%5F
dips%28%2209%22%29%29%3B%7D%7D%0A%20%20t%5Frec%7B%0A%20%20%20%20t%5Fnum%20bef%3B
%0A%20%20%20%20t%5Fstr%5Fitem%20aft%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%
5Fauto%28bef%29%3B%0A%20%20%20%20%20%20go%5Fconst%28%22%3A%22%29%3B%0A%20%20%20%
20%20%20go%5Fauto%28aft%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Flist%7B%
0A%20%20%20%20vector%3Ct%5Frec%3E%20arr%3B%7Bgo%5Fvec%28arr%2C%22%5Cn%22%29%3B%7
D%0A%20%20%7D%0A%7D
*/
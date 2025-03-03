class t_stat_cmds{
public:
  class i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_cmd)OWNER(t_stat_cmds)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====i_cmd
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_block_id);
        F(t_func);
        F(t_oper);
        F(t_for);
        F(t_if);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_block_id:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_id)PARENT(i_cmd)OWNER(t_stat_cmds)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,int,id,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_id
  #include "QapGenStruct.inl"
  //<<<<<+=====t_block_id
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      return ok;
    }
  };
  class t_func:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func)PARENT(i_cmd)OWNER(t_stat_cmds)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_func
  #include "QapGenStruct.inl"
  //<<<<<+=====t_func
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      return ok;
    }
  };
  class t_oper:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)PARENT(i_cmd)OWNER(t_stat_cmds)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStruct.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      return ok;
    }
  };
  class t_for:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for)PARENT(i_cmd)OWNER(t_stat_cmds)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_for
  #include "QapGenStruct.inl"
  //<<<<<+=====t_for
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      return ok;
    }
  };
  class t_if:public i_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_if)PARENT(i_cmd)OWNER(t_stat_cmds)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_if
  #include "QapGenStruct.inl"
  //<<<<<+=====t_if
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)F(t_block_id)F(t_func)F(t_oper)F(t_for)F(t_if)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_stat_cmds)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_stat_cmds
#include "QapGenStruct.inl"
//<<<<<+=====t_stat_cmds
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    return ok;
  }
};

/*
//list of types:
F(t_stat_cmds)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fstat%5Fcmds%7B%0A%20%20t%5Fblock%5Fid%3D%3Ei%5Fcmd%7Bint%20id%3B%7D%0A%20%20
t%5Ffunc%3D%3Ei%5Fcmd%7B%7D%0A%20%20t%5Foper%3D%3Ei%5Fcmd%7B%7D%0A%20%20t%5Ffor%
3D%3Ei%5Fcmd%7B%7D%0A%20%20t%5Fif%3D%3Ei%5Fcmd%7B%7D%0A%7D
*/
class t_diff_sys{
public:
  class t_cmd{
  public:
  #define DEF_PRO_AUTO_EQUAL()
  #define DEF_PRO_AUTO_COPY()
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd)OWNER(t_diff_sys)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,cmd,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,data,DEF,$,$)\
  ADDVAR(vector<t_cmd>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cmd
  #include "QapGenStruct.inl"
  //<<<<<+=====t_cmd
  public:
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_cmd)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_diff_sys)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_diff_sys
#include "QapGenStruct.inl"
//<<<<<+=====t_diff_sys
};
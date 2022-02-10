class qap_tron{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_tron)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(real,field_a,SET,0.0,$)\
ADDEND()
//=====+>>>>>qap_tron
#include "QapGenStruct.inl"
//<<<<<+=====qap_tron
public:
  /*internal code*/
};

class qap_tor:public qap_tron{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_tor)PARENT(qap_tron)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>qap_tor
#include "QapGenStruct.inl"
//<<<<<+=====qap_tor
public:
  /*internal code*/
};

class qap_los{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_los)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,beg_time,SET,0,$)\
ADDVAR(int,end_time,SET,0,$)\
ADDVAR(string,mem,SET,"0",$)\
ADDEND()
//=====+>>>>>qap_los
#include "QapGenStruct.inl"
//<<<<<+=====qap_los
public:
  /*internal code*/
};

class qap_combine{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_combine)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(qap_los,los,DEF,$,$)\
ADDVAR(qap_tor,tor,DEF,$,$)\
ADDEND()
//=====+>>>>>qap_combine
#include "QapGenStruct.inl"
//<<<<<+=====qap_combine
public:
  /*internal code*/
};

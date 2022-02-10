
class qapvec2i{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qapvec2i)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,SET,0,$)\
ADDVAR(int,y,SET,0,$)\
ADDEND()
//=====+>>>>>qapvec2i
#include "QapGenStruct.inl"
//<<<<<+=====qapvec2i
public:
};

class qapv0{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qapv0)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(qapvec2i,a,DEF,$,$)\
ADDEND()
//=====+>>>>>qapv0
#include "QapGenStruct.inl"
//<<<<<+=====qapv0
public:
};

class qapv1{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qapv1)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(qapv0,a,DEF,$,$)\
ADDVAR(qapv0,b,DEF,$,$)\
ADDEND()
//=====+>>>>>qapv1
#include "QapGenStruct.inl"
//<<<<<+=====qapv1
public:
};

class qapv2{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qapv2)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(qapv1,a,DEF,$,$)\
ADDEND()
//=====+>>>>>qapv2
#include "QapGenStruct.inl"
//<<<<<+=====qapv2
public:
};

class qapv3{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qapv3)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(qapv2,a,DEF,$,$)\
ADDVAR(qapvec2i,b,DEF,$,$)\
ADDEND()
//=====+>>>>>qapv3
#include "QapGenStruct.inl"
//<<<<<+=====qapv3
public:
};
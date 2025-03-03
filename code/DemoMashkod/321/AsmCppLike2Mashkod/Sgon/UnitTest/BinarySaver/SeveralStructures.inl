class TStruct7zip
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TStruct7zip)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,char,v,SET,'7',$)\
ADDVAR(1,char,z,SET,'z',$)\
ADDVAR(2,char,i,SET,'i',$)\
ADDVAR(3,char,p,SET,'p',$)\
ADDEND()
//=====+>>>>>TStruct7zip
#include "QapGenStruct.inl"
//<<<<<+=====TStruct7zip
public:
};

class TSiteHi3
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteHi3)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,value,SET,19,$)\
ADDVAR(1,string,name,SET,"default",$)\
ADDVAR(2,TStruct7zip,zip,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteHi3
#include "QapGenStruct.inl"
//<<<<<+=====TSiteHi3
public:
};

class TSiteX
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteX)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteX
#include "QapGenStruct.inl"
//<<<<<+=====TSiteX
public:
  static void SysHasSelf();
public:
  virtual void specail_for_debugger(){};
};

class TSiteX1:public TSiteX
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteX1)PARENT(TSiteX)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteX1
#include "QapGenStruct.inl"
//<<<<<+=====TSiteX1
public:
};

class TSiteX2:public TSiteX
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteX2)PARENT(TSiteX)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TAutoPtr<TSiteX>,Next,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteX2
#include "QapGenStruct.inl"
//<<<<<+=====TSiteX2
public:
};

class TSiteX3:public TSiteX
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteX3)PARENT(TSiteX)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vector<TAutoPtr<TSiteX>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteX3
#include "QapGenStruct.inl"
//<<<<<+=====TSiteX3
public:
  TAutoPtr<TSiteX>&Add(){Items.push_back(std::move(TAutoPtr<TSiteX>()));return Items.back();}
};

class TSiteX4:public TSiteX
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteX4)PARENT(TSiteX)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSiteHi3,Hi3,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteX4
#include "QapGenStruct.inl"
//<<<<<+=====TSiteX4
public:
};

class TSiteHi4
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSiteHi4)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,THardPtr<TType>,pType,DEF,$,$)\
ADDVAR(1,TSiteX2,S2,DEF,$,$)\
ADDEND()
//=====+>>>>>TSiteHi4
#include "QapGenStruct.inl"
//<<<<<+=====TSiteHi4
public:
};

static const int inpv=('i'<<0)+('n'<<8)+('p'<<16)+('v'<<24);
class TExampleRoom
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TExampleRoom)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,magic,SET,inpv,$)\
ADDVAR(1,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(2,int,GDID,SET,31456,$)\
ADDVAR(4,TAutoPtr<TExampleRoom>,Next,DEF,$,$)\
ADDVAR(5,string,text,DEF,$,$)\
ADDVAR(6,TStruct7zip,vzip,DEF,$,$)\
ADDEND()
//=====+>>>>>TExampleRoom
#include "QapGenStruct.inl"
//<<<<<+=====TExampleRoom
public:
  static void SysHasSelf();
public:
  void MakeNext(IEnvRTTI&Env,const string&text)
  {
    Next=UberInit<TExampleRoom>(Env);
    Next->text=text;
  }
};

class TExampleCom
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TExampleCom)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,Count,SET,123456,$)\
ADDVAR(1,string,SubName,SET,"Первая строка",$)\
ADDVAR(2,real,ExPi,SET,3.14,$)\
ADDVAR(4,string,SupName,SET,"Вторая строка",$)\
ADDVAR(5,TAutoPtr<TExampleRoom>,Room,DEF,$,$)\
ADDEND()
//=====+>>>>>TExampleCom
#include "QapGenStruct.inl"
//<<<<<+=====TExampleCom
public:
  void MakeRoom(IEnvRTTI&Env)
  {
    Room=UberInit<TExampleRoom>(Env);
    Room->MakeNext(Env,"NextItem[0]");
    Room->text="you ready?";
  }
};

//`#define DEF_PRO_REG_TYPES_STRUCT(F)F(TStruct7zip)F(TExampleRoom)F(TExampleCom)\
//`  F(TSiteHi3)F(TSiteHi4)\
//`  F(TSiteX)F(TSiteX1)F(TSiteX2)F(TSiteX3)F(TSiteX4)
//`//=====+++>>>>>TYPES(STRUCT)
//`#include "DefGenReg.inl"
//`//<<<<<+++=====TYPES(STRUCT)
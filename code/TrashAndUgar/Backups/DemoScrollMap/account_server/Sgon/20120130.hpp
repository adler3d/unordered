class qap_2012_01_30:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_2012_01_30)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<QapProgramD3D9>,Program,DEF,$,$)\
ADDEND()
//=====+>>>>>qap_2012_01_30
#include "QapGenStruct.inl"
//<<<<<+=====qap_2012_01_30
public:
  static void SysHasSelf();
public:
  void Update(IEnv&Env)
  {
    if(!Program)return;
    //Program
  }
};
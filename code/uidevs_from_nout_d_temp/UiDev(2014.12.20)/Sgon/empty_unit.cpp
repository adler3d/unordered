#define DEF_PRO_HEAD
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL

class TRandomClass2{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRandomClass2)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,DEF,$,$)\
ADDVAR(int,y,DEF,$,$)\
ADDVAR(int,z,DEF,$,$)\
ADDEND()
//=====+>>>>>TRandomClass2
#include "QapGenStruct.inl"
//<<<<<+=====TRandomClass2
public:
};

class TRandomBookPage2:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRandomBookPage2)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRandomClass2,rc2,DEF,$,$)\
ADDEND()
//=====+>>>>>TRandomBookPage2
#include "QapGenStruct.inl"
//<<<<<+=====TRandomBookPage2
public:
  void Render(t_context&con){
    con.qDev.BindTex(0,nullptr);
    con.qDev.SetColor(0xff000000);
    con.qDev.DrawQuad(con.pos+vec2d_zero,vec2d(100,20));
  }
  void Update(t_context&con){
    rc2.x++;
    int gg=1;
  }
};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TRandomBookPage2)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {

    }
    ThisCompileUnit(){

    }
  };
  ThisCompileUnit ThisUnit;
}
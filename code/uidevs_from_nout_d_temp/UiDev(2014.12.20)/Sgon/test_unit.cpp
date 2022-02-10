#define DEF_PRO_HEAD
//#define DEF_PRO_FULL
#include "qap_simple_header.inl"
#include <d3d9.h>
#include "QapMicro\QapVec.h"
#include "FastBMP.h"
#include "QapMicro\QapMatrix.h"
#include "D3D9Tools.inl"
#include "QapMicro\QapDev.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL

//#define DEF_BUILD_MACRO
#ifdef DEF_BUILD_MACRO
  #include "../Macro/test_uint.h"
#else
//=====>>>>>test_uint

class IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDVAR(bool,NeedRemove,DEF,$,$)\
ADDEND()
//=====+>>>>>IBookPage
#include "QapGenStruct.inl"
//<<<<<+=====IBookPage
public:
  struct t_context{
    IEnvRTTI&Env;
    void*root;
    void*kb;
    QapDev&qDev;
    void*head;
    void*book;
    vec2i pos;
    vec2i size;
    void*path;
    void*context;
  };
  virtual void Render(t_context&con){}
  virtual void Update(t_context&con){}
};

class IRandomClass{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IRandomClass)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IRandomClass
#include "QapGenStruct.inl"
//<<<<<+=====IRandomClass
public:
  static void foo()
  {
    auto c=file_get_contents("../Sgon/test_unit.cpp");
    int gg=1;
  }
};

class TRandomClass:public IRandomClass{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRandomClass)PARENT(IRandomClass)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,a,DEF,$,$)\
ADDVAR(int,b,DEF,$,$)\
ADDVAR(int,c,DEF,$,$)\
ADDEND()
//=====+>>>>>TRandomClass
#include "QapGenStruct.inl"
//<<<<<+=====TRandomClass
public:
};

class TRandomBookPage:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRandomBookPage)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRandomClass,rc,DEF,$,$)\
ADDEND()
//=====+>>>>>TRandomBookPage
#include "QapGenStruct.inl"
//<<<<<+=====TRandomBookPage
public:
  void Render(t_context&con){
    con.qDev.BindTex(0,nullptr);
    con.qDev.SetColor(0xff00ff00);
    con.qDev.DrawQuad(con.pos+vec2d_zero,vec2d(100,20));
  }
  void Update(t_context&con){
    rc.a++;
    int gg=1;
  }
};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const{return __FILE__;}
    virtual void RegAll(IEnvRTTI&Env)
    {
      IRandomClass::foo();
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TRandomBookPage)//F(TRandomClass)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}

//<<<<<=====test_unit
#endif //DEF_BUILD_MACRO//
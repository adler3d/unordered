#include "StdAfx.h"

class TPageWithSimpleRectTest:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPageWithSimpleRectTest)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRectAndMenuItems,rectandmenu,DEF,$,$)\
ADDEND()
//=====+>>>>>TPageWithSimpleRectTest
#include "QapGenStruct.inl"
//<<<<<+=====TPageWithSimpleRectTest
public:
  void Render(t_context&con)
  {
    rectandmenu.Render(con);
  }
  void Update(t_context&con)
  {
    auto&dev=con.context.dev;
    TOutDevScopeMemberID devscopeMember(dev,ProxySys$$::GET_FIELD_ID::rectandmenu);
    rectandmenu.Update(con);
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
        F(TType)F(TPageWithSimpleRectTest)
        //F(TBookPageRectTable)
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
  ThisCompileUnit ThisCompileUnitInstance;
}
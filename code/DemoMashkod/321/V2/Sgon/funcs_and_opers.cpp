#include "StdAfx.h"
class TFuncsAndOpersPack{
public:
  class t_funcs{
  public:
    class CatmullRomEx:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(CatmullRomEx)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,p1,DEF,$,$)\
    ADDVAR(2,real,p2,DEF,$,$)\
    ADDVAR(3,real,p3,DEF,$,$)\
    ADDVAR(4,real,p4,DEF,$,$)\
    ADDVAR(5,real,t,DEF,$,$)\
    ADDEND()
    //=====+>>>>>CatmullRomEx
    #include "QapGenStruct.inl"
    //<<<<<+=====CatmullRomEx
    public:
      void exec()
      {
        real t2=t*t;real t3=t2*t;
        out=0.5*((2.0*p2)+(p3-p1)*t+(2.0*p1-5.0*p2+4*p3-p4)*t2+(3.0*p2-3.0*p3+p4-p1)*t3);
      }
    };
    class ScanParamData:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ScanParamData)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,bef,DEF,$,$)\
    ADDVAR(2,string,inp,DEF,$,$)\
    ADDVAR(3,string,aft,DEF,$,$)\
    ADDVAR(4,int,pos,DEF,$,$)\
    ADDEND()
    //=====+>>>>>ScanParamData
    #include "QapGenStruct.inl"
    //<<<<<+=====ScanParamData
    public:
      void exec(){int e=pos;out=::ScanParam(bef,inp,aft,e);}
    };
    class urlencode:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(urlencode)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>urlencode
    #include "QapGenStruct.inl"
    //<<<<<+=====urlencode
    public:
      void exec(){out=::urlencode(inp);}
    };
    class urldecode:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(urldecode)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>urldecode
    #include "QapGenStruct.inl"
    //<<<<<+=====urldecode
    public:
      void exec(){out=::urldecode(inp);}
    };
    class sqrt:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(sqrt)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>sqrt
    #include "QapGenStruct.inl"
    //<<<<<+=====sqrt
    public:
      void exec(){out=::sqrt(inp);}
    };
    class sin:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(sin)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>sin
    #include "QapGenStruct.inl"
    //<<<<<+=====sin
    public:
      void exec(){out=::sin(inp);}
    };
    class cos:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(cos)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>cos
    #include "QapGenStruct.inl"
    //<<<<<+=====cos
    public:
      void exec(){out=::cos(inp);}
    };
    class tan:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(tan)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>tan
    #include "QapGenStruct.inl"
    //<<<<<+=====tan
    public:
      void exec(){out=::tan(inp);}
    };
    class atan:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(atan)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>atan
    #include "QapGenStruct.inl"
    //<<<<<+=====atan
    public:
      void exec(){out=::atan(inp);}
    };
    class atan2:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(atan2)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,y,DEF,$,$)\
    ADDVAR(2,real,x,DEF,$,$)\
    ADDEND()
    //=====+>>>>>atan2
    #include "QapGenStruct.inl"
    //<<<<<+=====atan2
    public:
      void exec(){out=::atan2(y,x);}
    };
    class file_get_contents:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(file_get_contents)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,filename,DEF,$,$)\
    ADDEND()
    //=====+>>>>>file_get_contents
    #include "QapGenStruct.inl"
    //<<<<<+=====file_get_contents
    public:
      void exec(){out=::file_get_contents(filename);}
    };
    class microtime:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(microtime)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDEND()
    //=====+>>>>>microtime
    #include "QapGenStruct.inl"
    //<<<<<+=====microtime
    public:
      void exec(){
        static QapClock clock;
        if(!clock.run)clock.Start();
        out=clock.MS()*1000.0;
      }
    };
    class FToS:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FToS)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>FToS
    #include "QapGenStruct.inl"
    //<<<<<+=====FToS
    public:
      void exec(){out=::FToS(inp);}
    };
    class SToF:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(SToF)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>SToF
    #include "QapGenStruct.inl"
    //<<<<<+=====SToF
    public:
      void exec(){::SToF(inp,out);}
    };
    class cur_date_str:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(cur_date_str)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDEND()
    //=====+>>>>>cur_date_str
    #include "QapGenStruct.inl"
    //<<<<<+=====cur_date_str
    public:
      void exec(){out=::cur_date_str();}
    };
    class IToS:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IToS)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IToS
    #include "QapGenStruct.inl"
    //<<<<<+=====IToS
    public:
      void exec(){out=::IToS(inp);}
    };
    class SToI:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(SToI)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>SToI
    #include "QapGenStruct.inl"
    //<<<<<+=====SToI
    public:
      void exec(){out=::SToI(inp);}
    };
    class CToI:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(CToI)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,char,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>CToI
    #include "QapGenStruct.inl"
    //<<<<<+=====CToI
    public:
      void exec(){out=inp;}
    };
    class IToC:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IToC)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IToC
    #include "QapGenStruct.inl"
    //<<<<<+=====IToC
    public:
      void exec(){out=inp;}
    };
    class BToS:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BToS)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,bool,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>BToS
    #include "QapGenStruct.inl"
    //<<<<<+=====BToS
    public:
      void exec(){out=inp?"true":"false";}
    };
    class SToB:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(SToB)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>SToB
    #include "QapGenStruct.inl"
    //<<<<<+=====SToB
    public:
      void exec(){bool ok=::SToB(inp,out);QapAssert(ok);}
    };
    class BToI:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BToI)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,bool,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>BToI
    #include "QapGenStruct.inl"
    //<<<<<+=====BToI
    public:
      void exec(){out=inp;}
    };
    class IToB:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IToB)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IToB
    #include "QapGenStruct.inl"
    //<<<<<+=====IToB
    public:
      void exec(){out=inp;}
    };
    class CToS:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(CToS)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,char,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>CToS
    #include "QapGenStruct.inl"
    //<<<<<+=====CToS
    public:
      void exec(){out=::CToS(inp);}
    };
    class SToC:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(SToC)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>SToC
    #include "QapGenStruct.inl"
    //<<<<<+=====SToC
    public:
      void exec(){
        QapAssert(!inp.empty());
        QapAssert(1==inp.size());
        out=inp.front();
      }
    };
    class FToI:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FToI)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>FToI
    #include "QapGenStruct.inl"
    //<<<<<+=====FToI
    public:
      void exec(){
        out=int(inp);
      }
    };
    class IToF:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IToF)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IToF
    #include "QapGenStruct.inl"
    //<<<<<+=====IToF
    public:
      void exec(){
        out=real(inp);
      }
    };
    class StrLen:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(StrLen)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>StrLen
    #include "QapGenStruct.inl"
    //<<<<<+=====StrLen
    public:
      void exec(){
        out=inp.size();
      }
    };
    class StrGetCharAt:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(StrGetCharAt)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDVAR(2,int,pos,DEF,$,$)\
    ADDEND()
    //=====+>>>>>StrGetCharAt
    #include "QapGenStruct.inl"
    //<<<<<+=====StrGetCharAt
    public:
      void exec(){
        QapAssert(pos>=0);
        QapAssert(pos<inp.size());
        out=inp[pos];
      }
    };
    class StrSetCharAt:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(StrSetCharAt)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDVAR(2,int,pos,DEF,$,$)\
    ADDVAR(3,char,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>StrSetCharAt
    #include "QapGenStruct.inl"
    //<<<<<+=====StrSetCharAt
    public:
      void exec(){
        QapAssert(pos>=0);
        QapAssert(pos<inp.size());
        out=inp;
        out[pos]=value;
      }
    };
    class StrSubStr:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(StrSubStr)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDVAR(2,int,offset,DEF,$,$)\
    ADDVAR(3,int,count,DEF,$,$)\
    ADDEND()
    //=====+>>>>>StrSubStr
    #include "QapGenStruct.inl"
    //<<<<<+=====StrSubStr
    public:
      void exec(){
        QapAssert(offset>=0);
        QapAssert(offset<inp.size());
        QapAssert(count>=0)
        out=inp.substr(offset,count);
      }
    };
    class StrFind:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(StrFind)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDVAR(2,string,ref,DEF,$,$)\
    ADDVAR(3,int,offset,DEF,$,$)\
    ADDEND()
    //=====+>>>>>StrFind
    #include "QapGenStruct.inl"
    //<<<<<+=====StrFind
    public:
      void exec(){
        out=-1;
        QapAssert(offset>=0);
        QapAssert(offset<inp.size());
        auto e=inp.find(ref,offset);
        if(e==std::string::npos)return;
        out=e;
      }
    };
    class StrReplace:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(StrReplace)PARENT(i_sys_impl)OWNER(t_funcs)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDVAR(2,string,bef,DEF,$,$)\
    ADDVAR(3,string,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>StrReplace
    #include "QapGenStruct.inl"
    //<<<<<+=====StrReplace
    public:
      void exec(){
        out=::StrReplace(inp,bef,aft);
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(CatmullRomEx     )\
    F(ScanParamData    )\
    F(urlencode        )\
    F(urldecode        )\
    F(sqrt             )\
    F(sin              )\
    F(cos              )\
    F(tan              )\
    F(atan             )\
    F(atan2            )\
    F(file_get_contents)\
    F(microtime        )\
    F(FToS             )\
    F(SToF             )\
    F(cur_date_str     )\
    F(IToS             )\
    F(SToI             )\
    F(CToI             )\
    F(IToC             )\
    F(BToS             )\
    F(SToB             )\
    F(BToI             )\
    F(IToB             )\
    F(CToS             )\
    F(SToC             )\
    F(FToI             )\
    F(IToF             )\
    F(StrLen           )\
    F(StrGetCharAt     )\
    F(StrSetCharAt     )\
    F(StrSubStr        )\
    F(StrFind          )\
    F(StrReplace       )\
    /*</DEF_PRO_NESTED>*/
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_funcs)OWNER(TFuncsAndOpersPack)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_funcs
  #include "QapGenStruct.inl"
  //<<<<<+=====t_funcs
  public:
  };
public:
  class t_opers:public t_sys_opers_holder{
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_int_set_int_add_int           )\
    F(t_int_set_int_sub_int           )\
    F(t_string_set_string_add_string  )\
    F(t_bool_set_string_set_set_string)\
    F(t_bool_set_string_not_set_string)\
    F(t_char_set_char_add_char        )\
    F(t_bool_set_int_less_int         )\
    F(t_bool_set_int_more_int         )\
    F(t_bool_set_int_less_set_int     )\
    F(t_bool_set_int_more_set_int     )\
    F(t_bool_set_int_set_set_int      )\
    F(t_bool_set_int_not_set_int      )\
    F(t_int_set_int_xor_int           )\
    F(t_int_set_int_or_int            )\
    F(t_int_set_int_and_int           )\
    F(t_bool_set_bool_set_set_bool    )\
    F(t_bool_set_bool_not_set_bool    )\
    F(t_int_add_set_int               )\
    F(t_int_sub_set_int               )\
    F(t_int_xor_set_int               )\
    F(t_int_and_set_int               )\
    F(t_int_or_set_int                )\
    F(t_string_add_set_string         )\
    F(t_string_set_string             )\
    F(t_int_set_int                   )\
    F(t_char_set_char                 )\
    F(t_bool_set_bool                 )\
    F(t_real_set_real                 )\
    F(t_bool_set_bool_or_or_bool      )\
    F(t_bool_set_bool_and_and_bool    )\
    F(t_bool_set_bool_and_bool        )\
    F(t_bool_set_bool_or_bool         )\
    F(t_int_add_add                   )\
    F(t_int_sub_sub                   )\
    F(t_char_add_add                  )\
    F(t_char_sub_sub                  )\
    F(t_real_set_real_add_real        )\
    F(t_real_set_real_sub_real        )\
    F(t_bool_set_real_less_real       )\
    F(t_bool_set_real_more_real       )\
    F(t_bool_set_real_less_set_real   )\
    F(t_bool_set_real_more_set_real   )\
    F(t_bool_set_real_set_set_real    )\
    F(t_bool_set_char_set_set_char    )\
    F(t_bool_set_char_not_set_char    )\
    F(t_bool_set_real_not_set_real    )\
    F(t_real_set_real_div_real        )\
    F(t_real_set_real_mul_real        )\
    F(t_int_set_int_mul_int           )\
    F(t_int_set_int_div_int           )\
    F(t_int_set_int_mod_int           )\
    F(t_int_mod_set_int               )\
    F(t_int_div_set_int               )\
    F(t_int_set_int_less_less_int     )\
    F(t_int_set_int_more_more_int     )\
    F(t_int_less_less_set_int         )\
    F(t_int_more_more_set_int         )\
    F(t_int_set_inv_int               )\
    F(t_bool_set_not_int              )\
    F(t_bool_set_not_bool             )\
    F(t_bool_set_not_char             )\
    F(t_bool_set_not_string           )\
    F(t_int_set_add_int               )\
    F(t_int_set_sub_int               )\
    F(t_char_set_sub_char             )\
    F(t_char_set_add_char             )\
    F(t_char_set_inv_char             )\
    F(t_real_set_add_real             )\
    F(t_real_set_sub_real             )\
    F(t_real_add_set_real             )\
    F(t_real_sub_set_real             )\
    F(t_int_mul_set_int               )\
    F(t_real_mul_set_real             )\
    /*</DEF_PRO_NESTED>*/
  public:
    //static string conv_type_name_to_oper_name(const string&name)
    //{
    //  #define F(TYPE)if(name=="__"#TYPE)return t_stat_dev::t_opers::TYPE::get_oper_name();
    //  DEF_PRO_NESTED(F);
    //  #undef F
    //  QapDebugMsg(name+" - unknow oper_impl type.");
    //  return name;
    //}
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_opers)PARENT(t_sys_opers_holder)OWNER(TFuncsAndOpersPack)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_opers
  #include "QapGenStruct.inl"
  //<<<<<+=====t_opers
  public:
    class t_int_set_int_add_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_add_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_add_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_add_int
    public:
      void exec(){
        out=bef+aft;
      }
      static string get_oper_name(){return "+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_sub_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_sub_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_sub_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_sub_int
    public:
      void exec(){out=bef-aft;}
      static string get_oper_name(){return "-";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_string_set_string_add_string:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_set_string_add_string)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,bef,DEF,$,$)\
    ADDVAR(2,string,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_string_set_string_add_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_string_set_string_add_string
    public:
      void exec(){out=bef+aft;}
      static string get_oper_name(){return "+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_string_set_set_string:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_string_set_set_string)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,string,bef,DEF,$,$)\
    ADDVAR(2,string,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_string_set_set_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_string_set_set_string
    public:
      void exec(){out=bef==aft;}
      static string get_oper_name(){return "==";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_string_not_set_string:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_string_not_set_string)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,string,bef,DEF,$,$)\
    ADDVAR(2,string,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_string_not_set_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_string_not_set_string
    public:
      void exec(){out=bef!=aft;}
      static string get_oper_name(){return "!=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_set_char_add_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_set_char_add_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,bef,DEF,$,$)\
    ADDVAR(2,char,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_set_char_add_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_set_char_add_char
    public:
      void exec(){out=bef+aft;}
      static string get_oper_name(){return "+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_int_less_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_int_less_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_int_less_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_int_less_int
    public:
      void exec(){out=bef<aft;}
      static string get_oper_name(){return "<";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_int_more_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_int_more_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_int_more_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_int_more_int
    public:
      void exec(){out=bef>aft;}
      static string get_oper_name(){return ">";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_int_less_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_int_less_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_int_less_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_int_less_set_int
    public:
      void exec(){out=bef<=aft;}
      static string get_oper_name(){return "<=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_int_more_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_int_more_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_int_more_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_int_more_set_int
    public:
      void exec(){out=bef>=aft;}
      static string get_oper_name(){return ">=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_int_set_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_int_set_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_int_set_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_int_set_set_int
    public:
      void exec(){out=bef==aft;}
      static string get_oper_name(){return "==";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_int_not_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_int_not_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_int_not_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_int_not_set_int
    public:
      void exec(){out=bef!=aft;}
      static string get_oper_name(){return "!=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_xor_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_xor_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_xor_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_xor_int
    public:
      void exec(){out=bef^aft;}
      static string get_oper_name(){return "^";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_or_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_or_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_or_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_or_int
    public:
      void exec(){out=bef|aft;}
      static string get_oper_name(){return "|";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_and_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_and_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_and_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_and_int
    public:
      void exec(){out=bef&aft;}
      static string get_oper_name(){return "&";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool_set_set_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool_set_set_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool_set_set_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool_set_set_bool
    public:
      void exec(){out=bef==aft;}
      static string get_oper_name(){return "==";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool_not_set_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool_not_set_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool_not_set_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool_not_set_bool
    public:
      void exec(){out=bef!=aft;}
      static string get_oper_name(){return "!=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_add_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_add_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_add_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_add_set_int
    public:
      void exec(){out=bef;out+=aft;}
      static string get_oper_name(){return "+=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_sub_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_sub_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_sub_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_sub_set_int
    public:
      void exec(){out=bef;out-=aft;}
      static string get_oper_name(){return "-=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_xor_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_xor_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_xor_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_xor_set_int
    public:
      void exec(){out=bef;out^=aft;}
      static string get_oper_name(){return "^=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_and_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_and_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_and_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_and_set_int
    public:
      void exec(){out=bef;out&=aft;}
      static string get_oper_name(){return "&=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_or_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_or_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_or_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_or_set_int
    public:
      void exec(){out=bef;out|=aft;}
      static string get_oper_name(){return "|=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_string_add_set_string:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_add_set_string)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,bef,DEF,$,$)\
    ADDVAR(2,string,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_string_add_set_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_string_add_set_string
    public:
      void exec(){out=bef;out+=aft;}
      static string get_oper_name(){return "+=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_string_set_string:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_set_string)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,out,DEF,$,$)\
    ADDVAR(1,string,bef,DEF,$,$)\
    ADDVAR(2,string,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_string_set_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_string_set_string
    public:
      void exec(){out=aft;}
      static string get_oper_name(){return "=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int
    public:
      void exec(){out=aft;}
      static string get_oper_name(){return "=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_set_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_set_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,bef,DEF,$,$)\
    ADDVAR(2,char,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_set_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_set_char
    public:
      void exec(){out=aft;}
      static string get_oper_name(){return "=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool
    public:
      void exec(){out=aft;}
      static string get_oper_name(){return "=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_real
    public:
      void exec(){out=aft;}
      static string get_oper_name(){return "=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool_or_or_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool_or_or_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool_or_or_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool_or_or_bool
    public:
      void exec(){out=bef||aft;}
      static string get_oper_name(){return "||";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool_and_and_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool_and_and_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool_and_and_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool_and_and_bool
    public:
      void exec(){out=bef&&aft;}
      static string get_oper_name(){return "&&";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool_and_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool_and_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool_and_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool_and_bool
    public:
      void exec(){out=bef&aft;}
      static string get_oper_name(){return "&";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_bool_or_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_bool_or_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,bef,DEF,$,$)\
    ADDVAR(2,bool,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_bool_or_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_bool_or_bool
    public:
      void exec(){out=bef|aft;}
      static string get_oper_name(){return "|";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_add_add:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_add_add)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_add_add
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_add_add
    public:
      void exec(){out=bef+1;}
      static string get_oper_name(){return "++";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_sub_sub:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_sub_sub)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_sub_sub
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_sub_sub
    public:
      void exec(){out=bef-1;}
      static string get_oper_name(){return "--";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_add_add:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_add_add)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_add_add
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_add_add
    public:
      void exec(){out=bef+1;}
      static string get_oper_name(){return "++";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_sub_sub:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_sub_sub)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_sub_sub
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_sub_sub
    public:
      void exec(){out=bef-1;}
      static string get_oper_name(){return "--";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_real_add_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_real_add_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_real_add_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_real_add_real
    public:
      void exec(){out=bef+aft;}
      static string get_oper_name(){return "+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_real_sub_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_real_sub_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_real_sub_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_real_sub_real
    public:
      void exec(){out=bef-aft;}
      static string get_oper_name(){return "-";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_real_less_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_real_less_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_real_less_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_real_less_real
    public:
      void exec(){out=bef<aft;}
      static string get_oper_name(){return "<";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_real_more_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_real_more_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_real_more_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_real_more_real
    public:
      void exec(){out=bef>aft;}
      static string get_oper_name(){return ">";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_real_less_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_real_less_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_real_less_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_real_less_set_real
    public:
      void exec(){out=bef>=aft;}
      static string get_oper_name(){return "<=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_real_more_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_real_more_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_real_more_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_real_more_set_real
    public:
      void exec(){out=bef>=aft;}
      static string get_oper_name(){return ">=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_real_set_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_real_set_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_real_set_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_real_set_set_real
    public:
      void exec(){out=bef==aft;}
      static string get_oper_name(){return "==";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_char_set_set_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_char_set_set_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,char,bef,DEF,$,$)\
    ADDVAR(2,char,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_char_set_set_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_char_set_set_char
    public:
      void exec(){out=bef==aft;}
      static string get_oper_name(){return "==";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_char_not_set_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_char_not_set_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,char,bef,DEF,$,$)\
    ADDVAR(2,char,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_char_not_set_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_char_not_set_char
    public:
      void exec(){out=bef!=aft;}
      static string get_oper_name(){return "!=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_real_not_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_real_not_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_real_not_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_real_not_set_real
    public:
      void exec(){out=bef!=aft;}
      static string get_oper_name(){return "!=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_real_div_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_real_div_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_real_div_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_real_div_real
    public:
      void exec(){out=bef/aft;}
      static string get_oper_name(){return "/";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_real_mul_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_real_mul_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_real_mul_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_real_mul_real
    public:
      void exec(){out=bef*aft;}
      static string get_oper_name(){return "*";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_mul_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_mul_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_mul_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_mul_int
    public:
      void exec(){out=bef*aft;}
      static string get_oper_name(){return "*";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_div_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_div_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_div_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_div_int
    public:
      void exec(){
        QapAssert(aft);
        if(!aft)return;
        out=bef/aft;
      }
      static string get_oper_name(){return "/";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_mod_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_mod_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_mod_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_mod_int
    public:
      void exec(){
        QapAssert(aft);
        if(!aft)return;
        out=bef%aft;
      }
      static string get_oper_name(){return "%";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_mod_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_mod_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_mod_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_mod_set_int
    public:
      void exec(){
        QapAssert(aft);
        if(!aft)return;
        out=bef;
        out%=aft;
      }
      static string get_oper_name(){return "%=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_div_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_div_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_div_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_div_set_int
    public:
      void exec(){
        QapAssert(aft);
        if(!aft)return;
        out=bef;
        out/=aft;
      }
      static string get_oper_name(){return "/=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_less_less_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_less_less_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_less_less_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_less_less_int
    public:
      void exec(){
        QapAssert(aft>=0&&aft<30);
        out=bef<<aft;
      }
      static string get_oper_name(){return "<<";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_int_more_more_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_int_more_more_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_int_more_more_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_int_more_more_int
    public:
      void exec(){
        QapAssert(aft>=0&&aft<30);
        out=bef>>aft;
      }
      static string get_oper_name(){return ">>";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_less_less_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_less_less_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_less_less_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_less_less_set_int
    public:
      void exec(){
        QapAssert(aft>=0&&aft<30);
        out=bef<<aft;
      }
      static string get_oper_name(){return "<<=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_more_more_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_more_more_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_more_more_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_more_more_set_int
    public:
      void exec(){
        QapAssert(aft>=0&&aft<30);
        out=bef>>aft;
      }
      static string get_oper_name(){return ">>=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_inv_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_inv_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_inv_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_inv_int
    public:
      void exec(){
        out=~inp;
      }
      static string get_oper_name(){return "~";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_not_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_not_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_not_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_not_int
    public:
      void exec(){
        out=!inp;
      }
      static string get_oper_name(){return "!";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_not_bool:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_not_bool)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,bool,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_not_bool
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_not_bool
    public:
      void exec(){out=!inp;}
      static string get_oper_name(){return "!";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_not_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_not_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,char,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_not_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_not_char
    public:
      void exec(){out=!inp;}
      static string get_oper_name(){return "!";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_bool_set_not_string:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_set_not_string)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,bool,out,DEF,$,$)\
    ADDVAR(1,string,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_bool_set_not_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_bool_set_not_string
    public:
      void exec(){out=inp.empty();}
      static string get_oper_name(){return "!";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_add_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_add_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_add_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_add_int
    public:
      void exec(){out=+inp;}
      static string get_oper_name(){return "+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_set_sub_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_set_sub_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_set_sub_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_set_sub_int
    public:
      void exec(){out=-inp;}
      static string get_oper_name(){return "-";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_set_sub_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_set_sub_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_set_sub_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_set_sub_char
    public:
      void exec(){out=-inp;}
      static string get_oper_name(){return "-";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_set_add_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_set_add_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_set_add_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_set_add_char
    public:
      void exec(){out=+inp;}
      static string get_oper_name(){return "+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_char_set_inv_char:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_set_inv_char)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,char,out,DEF,$,$)\
    ADDVAR(1,char,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_char_set_inv_char
    #include "QapGenStruct.inl"
    //<<<<<+=====t_char_set_inv_char
    public:
      void exec(){
        out=~inp;
      }
      static string get_oper_name(){return "~";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_sub_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_sub_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_sub_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_sub_real
    public:
      void exec(){out=-inp;}
      static string get_oper_name(){return "-";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_set_add_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_set_add_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,inp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_set_add_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_set_add_real
    public:
      void exec(){out=+inp;}
      static string get_oper_name(){return "=+";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_add_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_add_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_add_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_add_set_real
    public:
      void exec(){out=bef;out+=aft;}
      static string get_oper_name(){return "+=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_sub_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_sub_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_sub_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_sub_set_real
    public:
      void exec(){out=bef;out-=aft;}
      static string get_oper_name(){return "-=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_int_mul_set_int:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_mul_set_int)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,int,out,DEF,$,$)\
    ADDVAR(1,int,bef,DEF,$,$)\
    ADDVAR(2,int,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_int_mul_set_int
    #include "QapGenStruct.inl"
    //<<<<<+=====t_int_mul_set_int
    public:
      void exec(){out=bef;out*=aft;}
      static string get_oper_name(){return "*=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
    class t_real_mul_set_real:public i_sys_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_mul_set_real)PARENT(i_sys_impl)OWNER(t_opers)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,real,out,DEF,$,$)\
    ADDVAR(1,real,bef,DEF,$,$)\
    ADDVAR(2,real,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_real_mul_set_real
    #include "QapGenStruct.inl"
    //<<<<<+=====t_real_mul_set_real
    public:
      void exec(){out=bef;out*=aft;}
      static string get_oper_name(){return "*=";}
      static string GetClassMetaSpecInfo(){return get_oper_name();}
    };
  };
public:
#define DEF_PRO_NESTED(F)F(t_opers)F(t_funcs)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TFuncsAndOpersPack)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TFuncsAndOpersPack
#include "QapGenStruct.inl"
//<<<<<+=====TFuncsAndOpersPack
public:
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
        F(TType)F(TFuncsAndOpersPack)
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
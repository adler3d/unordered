#ifdef DEF_GLOBAL

class FooBar{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FooBar)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,string,name1,DEF,$,$)\
ADDVAR(1,string,name2,DEF,$,$)\
ADDVAR(2,string,name4,DEF,$,$)\
ADDVAR(3,string,name3,DEF,$,$)\
ADDEND()
//=====+>>>>>FooBar
#include "QapGenStruct.inl"
//<<<<<+=====FooBar
public:
};

#endif

#ifdef DEF_TESTMAIN

auto*p=Sys$$<FooBar>::GetRTTI(Env);
auto&arr=p->Members;
vector<string> out;
for(int i=0;i<arr.size();i++)
{
  vector<string> rec; auto toStr=[](const string&ref){return "\""+ref+"\"";};
  #define F(FIELD,CONV)rec.push_back(string("\""#FIELD"\":")+CONV(arr[i].FIELD));
  F(Number,IToS);
  F(Name,toStr);
  F(Mode,toStr);
  F(Value,toStr);
  #undef F
  out.push_back("{"+join(rec,",")+"}");
}
return "["+join(out,",")+"]";
#endif

#ifdef DEF_REGALL
F(TType)F(FooBar)
#endif
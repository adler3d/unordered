#ifndef DEF_BUILD_MICRO
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <map>
#include <bitset>
#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include "vec2d.inl"
//#include "img_loader_main.inl"
#include "QapClockMini.inl"
#endif

using std::vector;
using std::fstream;
using std::string;
using std::map;
using std::bitset;
using std::string;
using std::fstream;
using std::iostream;
using std::stringstream;
using std::array;

typedef double real;
typedef int64_t int64;
typedef uint64_t uint64;
typedef unsigned int uint;
typedef unsigned char uchar;

#ifndef WIN32
  #ifdef UNIX_WITH_FS
    #define QapDebugMsg(MSG){printf("QapDebugMsg :: %s:%i :: %s\n",__FILE__,__LINE__,string(MSG).c_str());fflush(stdout);}//__debugbreak();
    #define QapAssert(COND)if(!(COND)){printf("QapAssert :: %s:%i :: %s\n",__FILE__,__LINE__,#COND);fflush(stdout);exit(0);}//__debugbreak();
    #define QapNoWay(){printf("QapNoWay :: %s:%i\n",__FILE__,__LINE__);fflush(stdout);exit(0);}//__debugbreak();
  #else
    #define QapDebugMsg(MSG)
    #define QapAssert(COND)
    #define QapNoWay()
  #endif
#else

inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
#ifndef DEF_BUILD_MICRO
  #if(defined(_DEBUG)||defined(QAP_DEBUG))
    #include <assert.h>
    #define QapDbgBreak()__debugbreak();//assert(0);//__asm{int 3}//{struct t_open_mp_workaround{static void crash(){__asm{int 3}}};t_open_mp_workaround::crash();/*_CrtDbgBreak();*/}
    #define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}  
    #define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}
    #define QapNoWay(){QapDebugMsg("no way!");}
  #else
    #define QapAssert(_Expression)if(bool(_Expression)){};
    #define QapDebugMsg(_Message)
    #define QapNoWay()
  #endif
#endif //DEF_BUILD_MICRO//


enum QapMsgBoxRetval
{
  qmbrSkip,qmbrBreak,qmbrIgnore
};
inline void QapShowCursor(bool bShow){if(bShow){while(ShowCursor(true)<0);}else{while(ShowCursor(false)>=0);}}
static bool g_need_show_cursor=true;
inline int WinMessageBox(const string&caption,const string&text)
{
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  #ifdef _OPENMP
    full_text="omp_get_thread_num() : "+IToS(omp_get_thread_num())+"\n\n"+full_text;
  #endif
  if(!g_need_show_cursor)QapShowCursor(true);
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  if(!g_need_show_cursor)QapShowCursor(false);
  QapMsgBoxRetval retval=qmbrSkip;
  if(IDCONTINUE==nCode)retval=qmbrIgnore;
  if(IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
}
#define ShowCursor(flag)QapShowCursor(g_need_show_cursor=(flag))
typedef int(*TQapMessageBox)(const string&caption,const string&text);
struct TMessageBoxCaller
{
  static int Call(const string&caption,const string&text)
  {
    return Get()(caption,text);
  }
  static TQapMessageBox&Get()
  {
    static TQapMessageBox func=WinMessageBox;
    return func;
  }
  struct t_hack
  {
    TQapMessageBox old;
    t_hack(TQapMessageBox func)
    {
      old=Get();
      Get()=func;
    }
    ~t_hack()
    {
      Get()=old;
    }
  };
};

inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+std::to_string(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nAssertion failed :\n"+exp;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Assertion failed",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+std::to_string(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nDebug message :\n"+msg;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Debug message",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}


#endif //WIN32

inline int SToI(const string&S){return std::stoi(S,nullptr,10);};

//inline string IToS(const int&val){char c[16];_itoa_s(val,c,10);return string(c);}
inline string IToS(const int&v){return std::to_string(v);};
inline string FToS(const double&v){return std::to_string(v);};

static vector<string> split(const string&s,const string&needle)
{
  vector<string> arr;
  if(s.empty())return arr;
  size_t p=0;
  for(;;){
    auto pos=s.find(needle,p);
    if(pos==std::string::npos){arr.push_back(s.substr(p));return arr;}
    arr.push_back(s.substr(p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}
//-------------------------------------------//
static string join(const vector<string>&arr,const string&glue)
{
  string out;
  size_t c=0;
  size_t dc=glue.size();
  for(int i=0;i<arr.size();i++){if(i)c+=dc;c+=arr[i].size();}
  out.reserve(c);
  for(int i=0;i<arr.size();i++){if(i)out+=glue;out+=arr[i];}
  return out;
}

#include "ImgLoader.h"
#include "Dynamic.h"
#include "json.hpp"

double random()
{
  double max=double(RAND_MAX);
  double a=double(rand());
  return a/max;
  //double b=double(rand());
  //return (a+b/max)/(max+1.0);
}
template<class TYPE,unsigned count>
size_t lenof(const TYPE(&)[count]){return count;}

#ifdef DEF_BUILD_MACRO
  #include "../Macro/CellWorld.h"
#else
//=====>>>>>CellWorld
inline string IToSex(const int&val,int pad){char c[32];_snprintf_c(c,sizeof(c),("%0"+IToS(pad)+"i").c_str(),val);return c;}

struct vec2i{int x,y;};

class CellWorld{
public:
  vector<unsigned> arr;
  vector<unsigned> out;
  vector<unsigned> msk;
  TLoaderEnv Env;
  size_t m_w;
  size_t m_h;
public:
  struct rgba{unsigned char r,g,b,a;};
public:
  struct t_rules{
    std::map<string,size_t> c2t;
    struct t_rec{
      size_t level;
      string from;
      string to;
    };
    vector<t_rec> arr;
    static string as_single_str(nlohmann::json&arr_of_str){
      if(arr_of_str.is_string())return arr_of_str.get<std::string>();
      vector<string> out;for(auto&ex:arr_of_str)out.push_back(ex.get<std::string>());
      return join(out,"\n");
    }
    void load_from_str(const string&str){
      auto j=nlohmann::json::parse(str);
      for(auto&[k,v]:j["c2t"].items()){
        c2t[k]=v.get<size_t>();
      }
      for(auto&ex:j["rules"]){
        QapAssert("......."==ex[0].get<string>());
        arr.push_back({ex[1].get<size_t>(),as_single_str(ex[2]),as_single_str(ex[3])});
      }
    }
  };
  t_rules rules;
public:
  #define CELL_TYPE_LIST(BEG,ADD,END)\
  BEG()\
  ADD(0x0,'X',0xff,0xff,0xff)\
  ADD(0x1,'R',0xff,0x00,0x00)\
  ADD(0x2,'G',0x00,0xff,0x00)\
  ADD(0x3,'B',0x00,0x00,0xff)\
  ADD(0x4,'N',0x00,0x00,0x00)\
  ADD(0x5,'O',0x80,0x80,0x80)\
  ADD(0x6,'Y',0xff,0xff,0x00)\
  ADD(0x7,'E',0xff,0x80,0x00)\
  ADD(0x8,'T',0xff,0x80,0xff)\
  ADD(0x9,'H',0xff,0x40,0x00)\
  ADD(0x10,'0',0xff,0xA0,0x00)\
  ADD(0x11,'1',0xff,0xA5,0x00)\
  ADD(0x12,'2',0xff,0xB0,0x00)\
  ADD(0x13,'3',0xff,0xB5,0x00)\
  ADD(0x14,'4',0xff,0xC0,0x00)\
  ADD(0x15,'5',0xff,0xC5,0x00)\
  ADD(0x16,'6',0xff,0xD0,0x00)\
  ADD(0x17,'7',0xff,0xD5,0x20)\
  ADD(0x18,'8',0xff,0xE0,0x40)\
  ADD(0x19,'9',0xff,0xE5,0x80)\
  ADD(0xCC,'C',0xff,0xC0,0xC0)\
  ADD(0xFF,'I',0xC8,0xC8,0xC8)\
  ADD(0xFE,'Z',0x99,0xD9,0xEA)\
  END()
  #define BLANK()
  struct CellTypeRec{
    unsigned Value;
    char Char;
    unsigned char r;
    unsigned char g;
    unsigned char b;
  };
  static void GetCellTypes(vector<CellTypeRec>&out)
  {
    #define F(VALUE,CHAR,R,G,B){CellTypeRec tmp={VALUE,CHAR,R,G,B};out.push_back(tmp);}
    CELL_TYPE_LIST(BLANK,F,BLANK)
    #undef F
  }
  static unsigned ColorToCellType(const rgba&c)
  {
    if(c.a!=255)return 0;
    #define F(VALUE,CHAR,R,G,B)if(c.r==R)if(c.g==G)if(c.b==B){return VALUE;}
    CELL_TYPE_LIST(BLANK,F,BLANK)
    #undef F
    return 0;
  }
  static rgba CellTypeToColor(const unsigned&c)
  {
    #define F(VALUE,CHAR,R,G,B)if(VALUE==c){rgba tmp={R,G,B,255};return tmp;}
    CELL_TYPE_LIST(BLANK,F,BLANK)
    #undef F
    {rgba tmp={0,0,0,255};return tmp;}
  }
  static unsigned CharToCellType(char c)
  {
    #define F(VALUE,CHAR,R,G,B)if(CHAR==c){return VALUE;}
    CELL_TYPE_LIST(BLANK,F,BLANK)
    #undef F
    return 0;
  }
  static void safe_CharToCellType(char c,bool&ok,unsigned&value)
  {
    ok=true;
    #define F(VALUE,CHAR,R,G,B)if(CHAR==c){value=VALUE;return;}
    CELL_TYPE_LIST(BLANK,F,BLANK)
    #undef F
    ok=false;
  }
  static char CellTypeToChar(const unsigned&c)
  {
    #define F(VALUE,CHAR,R,G,B)if(VALUE==c){return CHAR;}
    CELL_TYPE_LIST(BLANK,F,BLANK)
    #undef F
    return 0;
  }
  #undef BLANK
  #undef CELL_TYPE_LIST
public:
  void load(const string&fn)
  {
    //TLoaderEnv Env;
    {
      ImgLoader::TextureMemory mem;
      Env.LoadTextureFromFile_v2(mem,fn);
      rgba*ptr=(rgba*)mem.ptr;
      m_w=mem.W;
      m_h=mem.H;
      arr.resize(m_h*m_w);
      out.resize(m_h*m_w);
      for(int y=0;y<m_h;y++)
      {
        for(int x=0;x<m_w;x++)
        {
          unsigned int id=x+y*m_w;
          auto&c=ptr[id];
          arr[id]=ColorToCellType(c);
        }
      }
      Env.FreeMemory(mem);
    }
    out=arr;
  }
  void save(const string&fn)
  {
    //TLoaderEnv Env;
    {
      ImgLoader::TextureMemory mem;
      Env.InitMemory(mem,m_w,m_h);
      rgba*ptr=(rgba*)mem.ptr;
      for(int i=0;i<arr.size();i++){
        ptr[i]=CellTypeToColor(arr[i]);
      }
      Env.SaveTextureToFile_v2(mem,fn);
      Env.FreeMemory(mem);
    }
  }
public:
  unsigned get_pos_with_offset(unsigned x,unsigned y,unsigned dx,unsigned dy){
    return (dx+x+m_w)%m_w+m_w*((dy+y+m_h)%m_h);
  }
  void Boom(unsigned x,unsigned y)
  {
    auto X=CharToCellType('X');
    auto R=CharToCellType('R');
    auto G=CharToCellType('G');
    auto B=CharToCellType('B');
    auto N=CharToCellType('N');
    auto O=CharToCellType('O');
    auto Y=CharToCellType('Y');
    auto E=CharToCellType('E');
    auto T=CharToCellType('T');
    auto H=CharToCellType('H');
    auto c0=CharToCellType('0');
    auto c1=CharToCellType('1');
    auto c2=CharToCellType('2');
    auto c3=CharToCellType('3');
    auto c4=CharToCellType('4');
    auto c5=CharToCellType('5');
    auto c6=CharToCellType('6');
    auto c7=CharToCellType('7');
    auto c8=CharToCellType('8');
    auto c9=CharToCellType('9');;
    auto id=get_pos_with_offset(x,y,0,0);
    if(T==arr[id])
    {
      int c=0;
      #define F(dX,dY){unsigned id=get_pos_with_offset(x,y,dX,dY);if(arr[id]==R)c++;if(arr[id]==G)c++;if(arr[id]==B)c++;}
      F(+1,0)
      F(-1,0)
      F(0,+1)
      F(0,-1)
      #undef F
      if(!c)return;
      msk[id]=true;
      out[id]=H;
      return;
    }
    if(N==arr[id])return;
    if(Y==arr[id])return;
    if(1)if(O==arr[id])return;
    if(0)if(O==arr[id])
    {
      int c=0;
      #define F(dX,dY){unsigned id=get_pos_with_offset(x,y,dX,dY);if(arr[id]==c8)c++;}
      F(+1,0)
      F(-1,0)
      F(0,+1)
      F(0,-1)
      #undef F
      if(!c)return;
      msk[id]=true;
      out[id]=c9;
      return;
    }
    #define F(PREV,NEXT)if(PREV==arr[id]){msk[id]=true;out[id]=NEXT;return;}
    F(H,E)
    F(E,c0)
    F(c0,c1)
    F(c1,c2)
    F(c2,c3)
    F(c3,c4)
    F(c4,c5)
    F(c5,c6)
    F(c6,c7)
    F(c7,c8)
    F(c8,c9)
    F(c9,X)
    #undef F
    if(true)
    {
      int c=0;
      #define F(dX,dY){unsigned id=get_pos_with_offset(x,y,dX,dY);if(arr[id]==H)c++;}
      F(+1,0)
      F(-1,0)
      F(0,+1)
      F(0,-1)
      #undef F
      if(!c)return;
      msk[id]=true;
      out[id]=H;
      return;
    }
  }
  bool TestError9(unsigned x,unsigned y)
  {
    auto X=CharToCellType('X');
    auto R=CharToCellType('R');
    auto G=CharToCellType('G');
    auto B=CharToCellType('B');
    auto C=CharToCellType('C');
    auto id=get_pos_with_offset(x,y,0,0);
    {
      int c=0;
      #define F(dX,dY){unsigned id=get_pos_with_offset(x,y,dX,dY);if(TestError(id%m_w,id/m_w))c++;}
      F(+0,+0)
      F(+1,+0)
      F(-1,+0)
      F(+0,+1)
      F(+0,-1)
      F(+1,+1)
      F(-1,-1)
      F(-1,+1)
      F(+1,-1)
      #undef F
      return c>0;
    }
  }
  bool TestError(unsigned x,unsigned y)
  {
    auto X=CharToCellType('X');
    auto R=CharToCellType('R');
    auto G=CharToCellType('G');
    auto B=CharToCellType('B');
    auto C=CharToCellType('C');
    auto id=get_pos_with_offset(x,y,0,0);
    if(X!=arr[id])return false;
    {
      int c=0;
      int n=0;
      #define F(dX,dY){unsigned id=get_pos_with_offset(x,y,dX,dY);if(arr[id]==C)n++;if(arr[id]==R)c++;if(arr[id]==G)c++;if(arr[id]==B)c++;}
      F(+1,0)
      F(-1,0)
      F(0,+1)
      F(0,-1)
      F(+1,+1)
      F(-1,-1)
      F(-1,+1)
      F(+1,-1)
      #undef F
      if(!n||!c)return false;
      return true;
    }
  }
  void ErrorDetector(unsigned x,unsigned y)
  {
    auto X=CharToCellType('X');
    auto R=CharToCellType('R');
    auto G=CharToCellType('G');
    auto B=CharToCellType('B');
    auto C=CharToCellType('C');
    auto id=get_pos_with_offset(x,y,0,0);
    if(TestError(x,y))
    {
      msk[id]=true;
      out[id]=C;
      return;
    }
  }
public:
  struct t_view_mode{
    bool invx;
    bool invy;
    bool swap;
    t_view_mode():invx(false),invy(false),swap(false){}
    void set(unsigned mode_id)
    {
      invx=(mode_id>>0)%2;
      invy=(mode_id>>1)%2;
      swap=(mode_id>>2)%2;
    }
    unsigned get()const
    {
      unsigned value=0;
      if(invx)value+=1<<0;
      if(invy)value+=1<<1;
      if(swap)value+=1<<2;
      return value;
    }
    void use(unsigned&dx,unsigned&dy)const
    {
      if(invx)dx=-dx;
      if(invy)dy=-dy;
      if(swap)std::swap(dx,dy);
    }
    void inv_use(unsigned&dx,unsigned&dy,unsigned w,unsigned h)const
    {
      if(invx)dx=w-dx-1;
      if(invy)dy=h-dy-1;
      if(swap)std::swap(dx,dy);
    }
  };
  struct IFieldView{
    //const vector<unsigned> arr;
    virtual void init(unsigned w,unsigned h){}
    virtual unsigned at(unsigned dx,unsigned dy)const{return 0;}
  };
  struct TRuleEvalResult{
    bool ok;
    unsigned value;
    TRuleEvalResult():ok(false),value(0){}
  };
  struct IFieldRule{
    virtual bool dir_test(const t_view_mode&mode)const{return true;}
    virtual void eval(IFieldView&view,TRuleEvalResult&result)const{}
  };
  struct TField{
    vector<unsigned>&arr;
    unsigned m_w;
    unsigned m_h;
    unsigned get_pos_with_offset(unsigned x,unsigned y,unsigned dx,unsigned dy)const
    {
      return (dx+x+m_w)%m_w+m_w*((dy+y+m_h)%m_h);
    }
  };
  struct TFieldView:public IFieldView{
    const TField&field;
    unsigned x;
    unsigned y;
    t_view_mode mode;
    TFieldView(const TField&field,unsigned x,unsigned y):field(field),x(x),y(y),mode(){}
    unsigned at(unsigned dx,unsigned dy)const
    {
      mode.use(dx,dy);
      auto pos_id=field.get_pos_with_offset(x,y,dx,dy);
      return field.arr[pos_id];
    }
  };
  #define TIME_INFO_CODE(A)//A
  static void UseRules(TField&dest,const TField&source,const vector<const IFieldRule*>&rules,double**p_celltimes=nullptr)
  {
    TIME_INFO_CODE(static double celltimes[1024*512];)
    QapClock clock_total;
    clock_total.Start();
    QapClock clock;
    struct graber
    {
      double&out;
      QapClock&ref;
      graber(double&out,QapClock&ref):out(out),ref(ref){ref.Start();}
      ~graber(){ref.Stop();out=ref.MS();}
    };
    //vector<TRuleEvalResult> results;
    TRuleEvalResult result; TRuleEvalResult result_buff; int count=0;
    for(unsigned y=0;y<source.m_h;y++)
    {
      for(unsigned x=0;x<source.m_w;x++)
      {
        TIME_INFO_CODE(graber time_graber(celltimes[x+y*source.m_w],clock);)
        TFieldView view(source,x,y);
        count=0;//results.clear();
        for(unsigned i=0;i<rules.size();i++)
        {
          auto&rule=*rules[i];
          for(unsigned mode_id=0;mode_id<8;mode_id++)
          {
            view.mode.set(mode_id);
            if(!rule.dir_test(view.mode))continue;
            result.ok=false;
            result.value=0;
            rule.eval(view,result);
            if(result.ok)
            {
              result_buff=result;//results.push_back(result);
              count++;
            }
          }
        }
        if(count>1)//if(results.size()>1)
        {
          int bad=1;QapAssert(false);continue;
        }
        if(count!=1)continue;
        auto&result=result_buff;//results.front();
        auto id=view.field.get_pos_with_offset(view.x,view.y,0,0);
        dest.arr[id]=result.value;
      }
    }
    TIME_INFO_CODE(if(p_celltimes)*p_celltimes=celltimes;)
    clock_total.Stop();
    printf("calc_time = %0.3lfms\n",clock_total.MS());
  }
public:
  static void UseRulesV2(TField&dest,const TField&source,const vector<const IFieldRule*>&rules,double**p_celltimes=nullptr)
  {
    const auto CellType_I=CharToCellType('I');
    QapClock clock_total;
    clock_total.Start();
    TRuleEvalResult result_buff;
    int count=0;
    vector<const IFieldRule*> resgen;
    for(unsigned y=0;y<source.m_h;y++)
    {
      for(unsigned x=0;x<source.m_w;x++)
      {
        if(CellType_I==source.arr[source.get_pos_with_offset(x,y,0,0)])continue;
        TFieldView view(source,x,y);
        count=0;
        resgen.clear();
        for(unsigned i=0;i<rules.size();i++)
        {
          auto*prule=rules[i];
          auto&rule=*rules[i];
          for(unsigned mode_id=0;mode_id<8;mode_id++)
          {
            view.mode.set(mode_id);
            if(!rule.dir_test(view.mode))continue;
            TRuleEvalResult result;
            result.ok=false;
            result.value=0;
            rule.eval(view,result);
            if(result.ok)
            {
              if(!count)result_buff=result;resgen.push_back(prule);
              count++;
            }
          }
        }
        if(count>1)
        {
          string msg;
          for(int i=0;i<resgen.size();i++)
          {
            CellWorld::TFieldRuleV02*p=(CellWorld::TFieldRuleV02*)resgen[i];
            msg+="\n-----[RULE{id:"+IToS(p->id)+"]-----\n\n"+p->tools.preview;
          }
          int bad=1;QapAssert(false);
        }
        if(!count)continue;
        auto&result=result_buff;
        auto id=view.field.get_pos_with_offset(view.x,view.y,0,0);
        dest.arr[id]=result.value;
      }
    }
    clock_total.Stop();
    printf("calc_time = %0.3lfms\n",clock_total.MS());
  }
public:
  struct TUseRulesV3{
    vector<vector<vec2i>>&depends;
    vector<vector<vec2i>>&subscribers;
    TField&dest;
    const TField&source;
    const vector<const IFieldRule*>&rules;
    vector<unsigned>&msk;
    vector<unsigned> curmsk;
    int cell_alive;
    void stats()
    {
      const auto CellType_I=CharToCellType('I');
      {
        int count=0;
        for(unsigned y=0;y<source.m_h;y++)
        {
          for(unsigned x=0;x<source.m_w;x++)if(CellType_I==source.arr[source.get_pos_with_offset(x,y,0,0)])count++;
        }
        printf("all_count = %i\n",source.arr.size());
        printf("off_count = %i\n",count);
        printf(" on_count = %i\n",source.arr.size()-count);
        printf("off_count/all_count = %.2lf%%\n",double(count)*100./double(source.arr.size()));
      }
    }
    void prepare()
    {
      cell_alive=0;
      if(msk.empty())
      {
        curmsk.resize(source.arr.size(),1);
        msk=curmsk;
      }
      if(depends.empty())
      {
        subscribers.resize(source.arr.size());
        depends.resize(source.arr.size());
      }
    }
    static bool find_pos(const vector<vec2i>&arr,const vec2i&p)
    {
      return find_pos_index(arr,p)>=0;
    }
    static int find_pos_index(const vector<vec2i>&arr,const vec2i&p)
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.x!=p.x)continue;
        if(ex.y!=p.y)continue;
        return i;
      }
      return -1;
    }
    static void remove_from_vector(vector<vec2i>&arr,int index)
    {
      QapAssert(index>=0);
      QapAssert(index<arr.size());
      std::swap(arr.back(),arr[index]);
      arr.resize(arr.size()-1);
    }
    void exclude_item(int x,int y)
    {
      vec2i pos={x,y};
      auto id=source.get_pos_with_offset(x,y,0,0);
      if(curmsk[id]==msk[id])return;
      QapAssert(curmsk[id]);
      QapAssert(!msk[id]);
      auto&points=depends[id];
      QapAssert(points.empty());
      points.clear();
      TFieldView view(source,x,y);
      get_depends_points(view,rules,points);
      for(int i=0;i<points.size();i++)
      {
        auto&ex=points[i];
        if(!ex.x)if(!ex.y)continue;
        auto id=source.get_pos_with_offset(x,y,ex.x,ex.y);
        auto&ex_arr=subscribers[id];
        if(find_pos(ex_arr,pos)){
          QapAssert(false);//WTF?
          continue;
        }
        ex_arr.push_back(pos);
      }
    }
    void include_item(int x,int y)
    {
      vec2i pos={x,y};
      auto id=source.get_pos_with_offset(x,y,0,0);
      //QapAssert(curmsk[id]);
      QapAssert(msk[id]);
      auto&points=depends[id];
      for(int i=0;i<points.size();i++)
      {
        auto&ex=points[i];
        if(!ex.x)if(!ex.y)continue;
        auto id=source.get_pos_with_offset(x,y,ex.x,ex.y);
        auto&ex_arr=subscribers[id];
        int index=find_pos_index(ex_arr,pos);
        if(index<0){
          QapAssert(false);//WTF?
          continue;
        }
        remove_from_vector(ex_arr,index);
        //QapAssert(!find_pos(ex_arr,pos));
      }
      points.clear();
    }
    void evalute_item(unsigned x,unsigned y)
    {
      auto id=source.get_pos_with_offset(x,y,0,0);
      if(!curmsk[id])return;
      cell_alive++;
      msk[id]=0;
      TFieldView view(source,x,y);
      TRuleEvalResult result_buff;
      int count=0;
      for(unsigned i=0;i<rules.size();i++)
      {
        auto*prule=rules[i];
        auto&rule=*rules[i];
        for(unsigned mode_id=0;mode_id<8;mode_id++)
        {
          view.mode.set(mode_id);
          if(!rule.dir_test(view.mode))continue;
          TRuleEvalResult result;
          result.ok=false;
          result.value=0;
          rule.eval(view,result);
          if(result.ok)
          {
            if(!count)result_buff=result;
            count++;
          }
        }
      }
      if(count>1)
      {
        int bad=1;QapAssert(false);
      }
      if(!count)
      {
        msk[id]=0;
        //off_item(x,y);
        return;
      }
      //auto id=view.field.get_pos_with_offset(view.x,view.y,0,0);
      auto&result=result_buff;
      QapAssert(dest.arr[id]!=result.value);
      dest.arr[id]=result.value;
      msk[id]=1;
    }
    void update()
    {
      prepare();
      curmsk=msk;
      QapClock clock_total;
      clock_total.Start();
      pre_update();
      for(unsigned y=0;y<source.m_h;y++)
      {
        for(unsigned x=0;x<source.m_w;x++)
        {
          evalute_item(x,y);
        }
      }
      post_update();
      clock_total.Stop();
      printf("calc_time = %0.3lfms        cell_alive=%8i\n",clock_total.MS(),cell_alive);
    }
    void post_update()
    {
      for(unsigned y=0;y<source.m_h;y++)
      {
        for(unsigned x=0;x<source.m_w;x++)
        {
          auto id=source.get_pos_with_offset(x,y,0,0);
          if(msk[id])continue;
          exclude_item(x,y);
        }
      }
    }
    void pre_update()
    {
      int gg=1;
      for(unsigned y=0;y<source.m_h;y++)
      {
        for(unsigned x=0;x<source.m_w;x++)
        {
          auto id=source.get_pos_with_offset(x,y,0,0);
          if(!curmsk[id])continue;
          auto&you_subs=subscribers[id];
          auto subs_points=you_subs;
          for(int i=0;i<subs_points.size();i++)
          {
            auto&ex=subs_points[i];
            auto point_id=source.get_pos_with_offset(ex.x,ex.y,0,0);
            msk[point_id]=1;
            include_item(ex.x%source.m_w,ex.y%source.m_h);
          }
          QapAssert(you_subs.empty());
        }
      }
      curmsk=msk;
      int bb=1;
    }
  };
public:
  struct TFieldViewProxy:public IFieldView{
    const IFieldView&view;
    unsigned x;
    unsigned y;
    t_view_mode mode;
    TFieldViewProxy(const IFieldView&view,unsigned x,unsigned y):view(view),x(x),y(y){}
    virtual unsigned at(unsigned dx,unsigned dy)const
    {
      mode.use(dx,dy);
      return view.at(x+dx,y+dy);
    }
  };
  struct TRuleTools{
    struct rec{
      unsigned from;
      unsigned to;
      unsigned x;
      unsigned y;
    };
    vector<rec> arr;
    vector<vector<const TRuleTools*>> pre_eval_rules;
    vector<bool> usefullmodes;
    bool is_pre_eval_only;
    unsigned level;
    string preview;
    string inp_view;
    string out_view;
    void add(unsigned from,unsigned to,unsigned x,unsigned y)
    {
      rec tmp;
      tmp.from=from;
      tmp.to=to;
      tmp.x=x;
      tmp.y=y;
      arr.push_back(tmp);
    }
    unsigned get_way_count(TFieldViewProxy&view,unsigned id)const
    {
      int count=0;
      for(int k=0;k<8;k++)
      {
        if(!usefullmodes[k])continue;
        view.mode.set(k);
        if(pre_eval(view,id))count++;
      }
      return count;
    }
    unsigned get_total_way_count(TFieldViewProxy&view)const
    {
      int count=0;
      for(unsigned i=0;i<arr.size();i++)
      {
        int way_count=get_way_count(view,i);
        count+=way_count;
      }
      return count;
    }
    bool test_way(TFieldViewProxy&view,unsigned id)const
    {
      QapAssert(!pre_eval_rules.empty());
      QapAssert(pre_eval_rules.size()==arr.size());
      auto&subarr=pre_eval_rules[id];
      int count=0;
      for(int i=0;i<subarr.size();i++)
      {
        auto*p=subarr[i];
        count+=p->get_total_way_count(view);
      }
      return 1==count;
    }
    bool pre_eval(const IFieldView&view,unsigned id)const
    {
      id=id%arr.size();
      auto&o=arr[id];
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto dx=ex.x-o.x;
        auto dy=ex.y-o.y;
        if(ex.from!=view.at(dx,dy))return false;
      }
      return true;
    }
    void eval(const IFieldView&view,unsigned id,bool&ok,unsigned&value)const
    {
      ok=false;
      if(is_pre_eval_only)return;
      id=id%arr.size();
      auto&o=arr[id];
      if(o.from==o.to)return;
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto dx=ex.x-o.x;
        auto dy=ex.y-o.y;
        if(ex.from!=view.at(dx,dy))return;
      }
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.from!=ex.to)
        {
          auto dx=ex.x-o.x;
          auto dy=ex.y-o.y;
          TFieldViewProxy proxy_view(view,dx,dy);
          bool result=test_way(proxy_view,i);
          int gg=1;
          if(!result)return;
        }
      }
      ok=true;
      value=o.to;
    }
    void get_size(
      unsigned&minx,
      unsigned&miny,
      unsigned&maxx,
      unsigned&maxy
    )const
    {
      minx=-1;
      miny=-1;
      maxx=+0;
      maxy=+0;
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        minx=std::min(minx,ex.x);
        miny=std::min(miny,ex.y);
        maxx=std::max(maxx,ex.x);
        maxy=std::max(maxy,ex.y);
      }
    }
    void init_field(TField&field,unsigned mode_id)const
    {
      unsigned minx;
      unsigned miny;
      unsigned maxx;
      unsigned maxy;
      get_size(minx,miny,maxx,maxy);
      field.m_w=maxx-minx+1;
      field.m_h=maxy-miny+1;
      t_view_mode mode;
      mode.set(mode_id);
      mode.invx=false;
      mode.invy=false;
      mode.use(field.m_w,field.m_h);
      field.arr.resize(field.m_w*field.m_h);
    }
    void draw_field(TField&field,unsigned mode_id)const
    {
      unsigned minx;
      unsigned miny;
      unsigned maxx;
      unsigned maxy;
      get_size(minx,miny,maxx,maxy);
      t_view_mode mode;
      mode.set(mode_id);
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto dx=ex.x-minx;
        auto dy=ex.y-miny;
        if(!mode.swap)mode.inv_use(dx,dy,field.m_w,field.m_h);
        if(mode.swap)mode.inv_use(dx,dy,field.m_h,field.m_w);
        auto pos=field.get_pos_with_offset(0,0,dx,dy);
        field.arr[pos]=ex.from;
      }
    }
    static bool is_equal(const TField&a,const TField&b)
    {
      if(a.m_w!=b.m_w)return false;
      if(a.m_h!=b.m_h)return false;
      return a.arr==b.arr;
    }
    void upadte_usefullmodes()
    {
      usefullmodes.resize(8);
      for(unsigned mode_id=0;mode_id<8;mode_id++)usefullmodes[mode_id]=true;
      vector<unsigned> arr[8];
      TField fields[8]={{arr[0]},{arr[1]},{arr[2]},{arr[3]},{arr[4]},{arr[5]},{arr[6]},{arr[7]}};
      for(unsigned mode_id=0;mode_id<8;mode_id++)
      {
        auto&field=fields[mode_id];
        init_field(field,mode_id);
      }
      for(unsigned mode_id=0;mode_id<8;mode_id++)
      {
        auto&field=fields[mode_id];
        draw_field(field,mode_id);
      }
      for(unsigned i=0;i<8;i++)
      {
        auto&a=fields[i];
        for(unsigned j=i+1;j<8;j++)
        {
          auto&b=fields[j];
          if(is_equal(a,b))
          {
            usefullmodes[j]=false;
          }
        }
      }
    }
    void upadte_is_pre_eval_only()
    {
      is_pre_eval_only=false;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.from!=ex.to){return;}
      }
      is_pre_eval_only=true;
    }
    void update()
    {
      upadte_usefullmodes();
      upadte_is_pre_eval_only();
    }
    bool dir_test(const t_view_mode&mode)const
    {
      auto input_mode_id=mode.get();
      if(usefullmodes.empty())
      {
        int bad=1;QapAssert(false);
        return false;
      }
      return usefullmodes[input_mode_id];
    }
    unsigned count_cell_with_type(unsigned celltype_from)const
    {
      int count=0;
      for(int j=0;j<arr.size();j++)
      {
        if(celltype_from==arr[j].from)count++;
      }
      return count;
    }
    void add_pre_eval_rule(const TRuleTools*p_rule)
    {
      if(pre_eval_rules.empty())
      {
        pre_eval_rules.resize(arr.size());
      }
      for(int i=0;i<arr.size();i++)
      {
        auto&celltype_from=arr[i].from;
        auto count=p_rule->count_cell_with_type(celltype_from);
        if(!count)continue;
        auto&subarr=pre_eval_rules[i];
        subarr.push_back(p_rule);
      }
    }
  };
public:
  struct TFieldRuleV02:public IFieldRule{
    const TRuleTools&tools;
    unsigned id;
    TFieldRuleV02(const TRuleTools&tools,unsigned id):tools(tools),id(id){}
    bool dir_test(const t_view_mode&mode)const{
      return tools.dir_test(mode);
    }
    void eval(IFieldView&view,TRuleEvalResult&result)const
    {
      tools.eval(view,id,result.ok,result.value);
    }
  };
  struct TFieldRulesMan{
    vector<const IFieldRule*> out_rules;
    vector<TFieldRuleV02> field_rules;
    vector<TRuleTools> rules_tools;
    TFieldRulesMan()
    {
      rules_tools.reserve(1024*4);
      field_rules.reserve(1024*4);
    }
    TRuleTools&add_new_tools()
    {
      rules_tools.resize(rules_tools.size()+1);
      auto&back=rules_tools.back();
      back.level=0xff;
      return back;
    }
    void add_rules_from_tools(TRuleTools&tools)
    {
      for(unsigned i=0;i<tools.arr.size();i++)
      {
        TFieldRuleV02 rule(tools,i);
        field_rules.push_back(std::move(rule));
        out_rules.push_back(&field_rules.back());
      }
    }
    void gen_rule_from_str(TRuleTools&tools,const string&inp,const string&out)
    {
      QapAssert(inp.size()==out.size());
      unsigned x=0;
      unsigned y=0;
      for(int i=0;i<inp.size();i++)
      {
        auto&a=inp[i];
        auto&b=out[i];
        bool next_line='\n'==a;
        if(next_line)
        {
          QapAssert('\n'==b);
          y++;x=0;
          continue;
        }
        if('.'==a)
        {
          QapAssert('.'==b);
          x++;
          continue;
        }
        unsigned a_code;
        {bool ok=false;safe_CharToCellType(a,ok,a_code);QapAssert(ok);}
        unsigned b_code;
        {bool ok=false;safe_CharToCellType(b,ok,b_code);QapAssert(ok);}
        tools.add(a_code,b_code,x,y);
        x++;
      }
    }
    void add_rule_from_str(const string&inp,const string&out)
    {
      auto&tools=add_new_tools();
      gen_rule_from_str(tools,inp,out);
      tools.update();
      tools.add_pre_eval_rule(&tools);
      add_rules_from_tools(tools);
    }
    void add_rule(unsigned level,const string&inp,const string&out)
    {
      add_rule_from_str(inp,out);
      rules_tools.back().level=level;
    }
    static void get_min(const vector<bool>&msk,const vector<TRuleTools>&arr,vector<int>&out)
    {
      bool first=true;
      int id=-1;
      out.clear();
      for(int i=0;i<arr.size();i++)
      {
        if(!msk[i])continue;
        if(first){out.push_back(i);id=i;first=false;continue;}
        if(arr[id].level<arr[i].level)continue;
        if(arr[id].level==arr[i].level){out.push_back(i);continue;}
        out.clear();
        out.push_back(i);
        id=i;
      }
    }
    void compile()
    {
      vector<bool> msk;
      msk.resize(rules_tools.size());
      for(int i=0;i<msk.size();i++)msk[i]=true;
      vector<int> passed;
      vector<int> list;
      for(;;)
      {
        list.clear();
        get_min(msk,rules_tools,list);
        if(list.empty())break;
        for(int i=0;i<list.size();i++)
        {
          const auto&id=list[i];
          passed.push_back(id);
          msk[id]=false;
        }
        for(int i=0;i<list.size();i++)
        {
          const auto&id=list[i];
          auto&ex=rules_tools[id];
          ex.pre_eval_rules.clear();
          for(int j=0;j<passed.size();j++)
          {
            auto&tools=rules_tools[passed[j]];
            ex.add_pre_eval_rule(&tools);
          }
        }
      }
    }
    void printf_all_rules()
    {
      for(int i=0;i<rules_tools.size();i++)
      {
        printf("\n-----=====[%i]=====-----\n",i);
        tools_print(rules_tools[i]);
      }
      printf("\n-----=====[end]=====-----\n");
    }
  };
public:
  struct t_proccessor_rule_gen{
    //G = read = 0
    //E = write = 1
    struct t_context{
      bool cmd;
      bool addr;
      bool value;
      bool a;
      bool b;
    };
    struct t_rule_gen{
      t_context&inp;
      t_context&out;
      void read()
      {
        const auto&flag=inp.addr?inp.b:inp.a;
        out.value=flag;
      }
      void write()
      {
        auto&flag=inp.addr?out.b:out.a;
        flag=inp.value;
      }
      void go()
      {
        out=inp;
        if(inp.cmd){write();}else{read();}
      }
    };
    static void char_replace(string&str,char from,char to){
      for(int i=0;i<str.size();i++){
        if(str[i]==from)str[i]=to;
      }
    }
    struct bool5
    {
      bool arr[5];
      int get()
      {
        int result=0;
        for(int i=0;i<5;i++)result+=arr[4-i]<<i;
        return result;
      }
      void set(int value)
      {
        for(int i=0;i<5;i++)arr[4-i]=(value>>i)%2;
      }
      t_context&toContext(){
        return *(t_context*)(void*)this;
      }
      static char BoolToChar(bool flag){return flag?'E':'G';}
      string use(const string&s)
      {
        string str=s;
        for(int i=0;i<5;i++)char_replace(str,'0'+i,BoolToChar(arr[i]));
        return str;
      }
    };
    struct bool3
    {
      bool arr[3];
      int get()
      {
        int result=0;
        for(int i=0;i<lenof(arr);i++)result+=arr[lenof(arr)-i-1]<<i;
        return result;
      }
      void set(int value)
      {
        for(int i=0;i<lenof(arr);i++)arr[lenof(arr)-i-1]=(value>>i)%2;
      }
      t_context&toContext(){
        return *(t_context*)(void*)this;
      }
      static char BoolToChar(bool flag){return flag?'E':'G';}
      string use(const string&s)
      {
        string str=s;
        for(int i=0;i<lenof(arr);i++)char_replace(str,'0'+i,BoolToChar(arr[i]));
        return str;
      }
    };
  public:
    static void start(unsigned level,TFieldRulesMan&man)
    {
      for(int i=0;i<(1<<3);i++)
      {
        bool3 state;
        state.set(i);
        string fixed=state.use(
          "....B0X\n"
          "..OOO..\n"
          ".B1Y2B.\n"
        );
        man.add_rule(0x4D,fixed,fixed);
      }
      for(int i=0;i<(1<<5);i++)
      {
        bool5 input,output;
        input.set(i);
        auto&inp=input.toContext();
        auto&out=output.toContext();
        t_rule_gen rule_gen={inp,out};
        rule_gen.go();
        //if(input.get()==output.get())continue;
        string from=input.use(
          "B2B1B0X\n"
          "..OOO..\n"
          ".B4Y3B.\n"
        );
        string to=output.use(
          "XB2B1B0\n"
          "..OOO..\n"
          ".B4Y3B.\n"
        );
        man.add_rule(level,from,to);
      }
      for(int i=0;i<(1<<3);i++)
      {
        bool3 fixed;
        fixed.set(i);
        string from=fixed.use(
          "B2B1B0X\n"
        );
        string to=fixed.use(
          "XB2B1B0\n"
        );
        man.add_rule(0x4D,from,to);
      }
      if(0)for(int k=1;k<6;k++)
      for(int i=0;i<(1<<5);i++)
      {
        bool5 fixed;
        fixed.set(i);
        string prefix;prefix.resize(k,'.');
        string from=fixed.use(
          prefix+"B2B1B0X\n"
          "..OOO..\n"+
          ".B4Y3B.\n"
        );
        string to=fixed.use(
          prefix+"XB2B1B0\n"
          "..OOO..\n"
          ".B4Y3B.\n"
        );
        man.add_rule(level,from,to);
      }
    }
  };
public:
  static TFieldRulesMan&get_man()
  {
    static TFieldRulesMan man;
    return man;
  }
  static vector<const IFieldRule*>&get_rules()
  {
    auto&man=get_man();
    vector<const IFieldRule*>&rules=man.out_rules;
    if(!rules.empty())return rules;
    if(false)
    {
      man.printf_all_rules();
      man.compile();
      return rules;
    }
    man.add_rule(0x50,"BGX\n","XBG\n");
    man.add_rule(0x50,"BEX\n","XBE\n");
    man.add_rule
    (
      0x20,
      ".O\n"
      "BE\n"
      ".X\n"
      ,
      ".O\n"
      "XB\n"
      ".E\n"
    );
    man.add_rule
    (
      0x20,
      ".O\n"
      "BG\n"
      ".X\n"
      ,
      ".O\n"
      "XB\n"
      ".G\n"
    );
    //
    //man.add_rule(0x50,"BGYX","XBGY");
    //man.add_rule(0x50,"BGYOX","XBGYO");
    //man.add_rule(0x50,"BEYX","XBEY");
    //man.add_rule(0x50,"BEYOX","XBEYO");
    //
    man.add_rule
    (
      0x50,
      ".B\n"
      "XG\n"
      ".O\n"
      "GY\n"
      ,
      ".X\n"
      "GB\n"
      ".O\n"
      "GY\n"
    );
    man.add_rule
    (
      0x50,
      ".B\n"
      "XE\n"
      ".O\n"
      "EY\n"
      ,
      ".X\n"
      "EB\n"
      ".O\n"
      "EY\n"
    ); 
    man.add_rule
    (  
      0x10,
      "BGX\n"
      ".O.\n"
      ".YG\n"
      ,
      "XBG\n"
      ".O.\n"
      ".YG\n"
    );
    man.add_rule
    (
      0x10,
      "BEX\n"
      ".O.\n"
      ".YE\n"
      ,
      "XBE\n"
      ".O.\n"
      ".YE\n"
    );
    man.add_rule(0x1a,"OGYOE","OEYOE");
    man.add_rule(0x1a,"OEYOG","OGYOG");
    man.add_rule(0x1d,"GOEYO","EOEYO");
    man.add_rule(0x1d,"EOGYO","GOGYO");
    man.add_rule(0x2a,"GOGYOE","EOEYOE");
    man.add_rule(0x2a,"EOEYOG","GOGYOG");
    auto&g_man=man;
    man.add_rule
    (
      0x49,
      "B.....\n"
      "GOBBOX\n"
      ,
      "B.....\n"
      "GOBBOX\n"
    );
    man.add_rule
    (
      0x49,
      "B.....\n"
      "EOBBOX\n"
      ,
      "B.....\n"
      "EOBBOX\n"
    );
    auto add_full_sync=[&](char A,char B)
    {
      auto&man=g_man;
      auto f=[](string&str,char from,char to){for(int i=0;i<str.size();i++){if(str[i]==from)str[i]=to;}};
      auto g=[&f,&A,&B](const string&s)->string{string str=s;f(str,'1',A);f(str,'2',B);return str;};
      auto add=[&](unsigned level,const string&from,const string&to){
        string stra=g(from);
        string strb=g(to);
        man.add_rule(level,stra,strb);
      };
      add
      (
        0x30,
        ".....B\n"
        "B....2\n"
        "1OBBOX\n"
        ,
        ".....X\n"
        "B....B\n"
        "1OBBO2\n"
      );
    };
    add_full_sync('E','E');
    add_full_sync('E','G');
    add_full_sync('G','E');
    add_full_sync('G','G');
    
    if(bool use_remover=true)
    {
      man.add_rule(
        0x80,
        "NON\n"
        "..G\n"
        "..B\n"
        ,
        "NON\n"
        "..B\n"
        "..X\n"
      );
      man.add_rule(
        0x80,
        "NON\n"
        "..E\n"
        "..B\n"
        ,
        "NON\n"
        "..B\n"
        "..X\n"
      );
      man.add_rule(
        0x80,
        "NON\n"
        "..B\n"
        ,
        "NON\n"
        "..X\n"
      );
    }
    if(bool use_swither=true)
    {
      man.add_rule(
        0x80,
        "..O.\n"
        "..Y.\n"
        "..O.\n"
        "BGNX\n"
        ,
        "..O.\n"
        "..Y.\n"
        "..O.\n"
        "XBNE\n"
      );
      man.add_rule(
        0x80,
        ".O..\n"
        ".Y..\n"
        ".O..\n"
        "BNEX\n"
        ,
        ".O..\n"
        ".Y..\n"
        ".O..\n"
        "XNBE\n"
      );
      man.add_rule(
        0x80,
        "..O.\n"
        "..Y.\n"
        "..O.\n"
        "BENX\n"
        ,
        "..O.\n"
        "..Y.\n"
        "..O.\n"
        "XBNG\n"
      );
      man.add_rule(
        0x80,
        ".O..\n"
        ".Y..\n"
        ".O..\n"
        "BNGX\n"
        ,
        ".O..\n"
        ".Y..\n"
        ".O..\n"
        "XNBG\n"
      );
    }
    //t_proccessor_rule_gen::start(0x4A,man);
    man.printf_all_rules();
    man.compile();
    return rules;
  }
  void RunV01()
  {
    TField dest={out,m_w,m_h};
    const TField source={arr,m_w,m_h};
    vector<const IFieldRule*>&rules=get_rules();
    double*ptimeinfo=nullptr;
    UseRulesV2(dest,source,rules,&ptimeinfo);
    if(ptimeinfo){
      static int counter=0;
      save_timeinfo(get_timeinfo_fn(counter),ptimeinfo);
      counter++;
    }
  }

  static vector<vector<vec2i>>&get_depends()
  {
    static vector<vector<vec2i>> tmp;
    return tmp;
  }
  static vector<vector<vec2i>>&get_subscribers()
  {
    static vector<vector<vec2i>> tmp;
    return tmp;
  }
  void RunV02()
  {
    TField dest={out,m_w,m_h};
    const TField source={arr,m_w,m_h};
    vector<const IFieldRule*>&rules=get_rules();
    vector<vector<vec2i>>&depends=get_depends();
    auto&subscribers=get_subscribers();
    TUseRulesV3 v3={depends,subscribers,dest,source,rules,msk};
    v3.update();
  }
  string get_timeinfo_fn(int i){
    char buff[64]={0};
    sprintf_s(buff,"timeinfo%05i.png",i);
    return buff;
  }
  void save_timeinfo(const string&fn,double*ptimeinfo)
  {
    double minv=+1E10;
    double maxv=-1E10;
    for(int i=0;i<m_w*m_h;i++)
    {
      minv=std::min(ptimeinfo[i],minv);
      maxv=std::max(ptimeinfo[i],maxv);
    }
    {
      ImgLoader::TextureMemory mem;
      Env.InitMemory(mem,m_w,m_h);
      rgba*ptr=(rgba*)mem.ptr;
      for(int i=0;i<arr.size();i++){
        ptr[i].a=255;
        ptr[i].r=255-int(255.0*(ptimeinfo[i]-minv)/(maxv-minv));
        ptr[i].g=255-int(255.0*(ptimeinfo[i]-minv)/(maxv-minv));
        ptr[i].b=255-int(255.0*(ptimeinfo[i]-minv)/(maxv-minv));
      }
      Env.SaveTextureToFile_v2(mem,fn);
      Env.FreeMemory(mem);
    }
  }
public:
  bool step()
  {
    RunV02();
    std::swap(arr,out);
    bool result=arr!=out;
    out=arr;
    return result;
  }
  string get_fn(int i){
    char buff[64]={0};
    sprintf_s(buff,"frames/%05i.png",i);
    return buff;
  }
  void run(int sim_limit=1024*8)
  {
    //get_man().rules_tools[0].;
    auto frame200=arr;
    for(int i=0;;i++){
      if(sim_limit>=0)if(i>=sim_limit){printf("CellWorld::run::sim_limit_reached();\n");break;}
      save(get_fn(i));printf("frame = %i\n",i);
      if(!step()){printf("CellWorld::run::step_failed(); // cellworld state is the same!\n");break;}
      int gg=1;
      if(frame200==arr){
        int gg=1;
        printf("CellWorld::run::loop_detected();\n");
        break;
      }
      if(i%200==0){
        frame200=arr;
      }
    }
    int gg=10;
  }
  static void tools_print(TRuleTools&tools)
  {
    int minx=1000;
    int miny=1000;
    int maxx=-1000;
    int maxy=-1000;
    auto pass=[&minx,&miny,&maxx,&maxy](const TRuleTools::rec&ex){
      {int x=ex.x;int y=ex.y;minx=std::min(minx,x);miny=std::min(miny,y);}
      {int x=ex.x;int y=ex.y;maxx=std::max(maxx,x);maxy=std::max(maxy,y);}
    };
    auto&arr=tools.arr;
    for(unsigned i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(ex);
    }
    {
      int w=maxx-minx+1;
      int h=maxy-miny+1;
      string buff;
      buff.resize(w*h);
      auto draw=[&w,&h](const string&buff,string&out){
        for(int i=0;i<h;i++)
        {
          for(int j=0;j<w;j++)
          {
            char c=buff[i*w+j];
            out.push_back(c?c:'.');
          }
          out+="\n";
        }
      };
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        buff[ex.x-minx+(ex.y-miny)*w]=CellTypeToChar(ex.from);
      }
      string&preview=tools.preview;
      draw(buff,preview);
      {preview+="\n";for(int i=0;i<w;i++)preview+="=";preview+="\n\n";}
      for(unsigned i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        buff[ex.x-minx+(ex.y-miny)*w]=CellTypeToChar(ex.to);
      }
      draw(buff,preview);
      printf("%s",preview.c_str());
    }
  }
public:
  struct TFieldViewProxyAna:public IFieldView
  {
    struct point{unsigned x;unsigned y;unsigned value;};
    const TFieldView&view;
    vector<point>*arr;
    TFieldViewProxyAna(const TFieldView&view,vector<point>*arr):view(view),arr(arr){}
    unsigned at(unsigned dx,unsigned dy)const
    {
      point p={dx,dy,view.at(dx,dy)};
      arr->push_back(p);
      return p.value;
    }
    void print()
    {
      int minx=1000;
      int miny=1000;
      int maxx=-1000;
      int maxy=-1000;
      auto pass=[&minx,&miny,&maxx,&maxy](point&ex){
        {int x=ex.x;int y=ex.y;minx=std::min(minx,x);miny=std::min(miny,y);}
        {int x=ex.x;int y=ex.y;maxx=std::max(maxx,x);maxy=std::max(maxy,y);}
      };
      std::map<string,int> pass_count;
      for(unsigned i=0;i<arr->size();i++)
      {
        auto&ex=arr->at(i);
        static char buff[1024]={0};
        sprintf_s(buff,"x: %+d,     y: %+d,     ret: %d",ex.x,ex.y,ex.value);
        printf("x: %+d,     y: %+d,     ret: %d\n",ex.x,ex.y,ex.value);
        string key=buff;
        pass_count[key]++;
        pass(ex);
      }
      printf("==========[info]==========\n");
      {
        printf("minx: %+i,     miny: %+i\n",minx,miny);
        printf("maxx: %+i,     maxy: %+i\n",maxx,maxy);
        printf("==========\n");
        int w=maxx-minx+1;
        int h=maxy-miny+1;
        printf("w: %i,     h: %i\n",w,h);
        printf("==========\n");
        static char buff[1024]={0};
        for(unsigned i=0;i<arr->size();i++)
        {
          auto&ex=arr->at(i);
          buff[ex.x-minx+(ex.y-miny)*w]=CellTypeToChar(ex.value);
        }
        for(int i=0;i<h;i++)
        {
          for(int j=0;j<w;j++)
          {
            char c=buff[i*w+j];
            if(c=='X')c='.';
            if(c=='O')c='*';
            if(c=='N')c='#';
            if(c==0x0)c=' ';
            printf("%c",c);
          }
          printf("\n");
        }
      }
      printf("==========[map]==========\n");
      for(auto it=std::begin(pass_count);it!=std::end(pass_count);it++)printf("%s,     count: %d\n",it->first.c_str(),it->second);
    }
  };
  struct TFieldViewProxyAnaV2:public IFieldView
  {
    typedef TFieldViewProxyAna::point point;
    const TFieldView&view;
    vector<point>*arr;
    TFieldViewProxyAnaV2(const TFieldView&view,vector<point>*arr):view(view),arr(arr){}
    unsigned at(unsigned dx,unsigned dy)const
    {
      point p={dx,dy,view.at(dx,dy)};
      view.mode.use(p.x,p.y);
      arr->push_back(p);
      return p.value;
    }
  };
  void goAnaEP()
  {
    static TFieldRulesMan man;
    static vector<const IFieldRule*>&rules=man.out_rules;
    man.add_rule(0x00,"BGBGX","XBGBG");
    man.compile();
    goAna(*man.out_rules[0]);
  }
  void goAna(const IFieldRule&rule)
  {
    printf("start\n");
    TField field={out,m_w,m_h};
    TFieldView view(field,8,5);
    vector<TFieldViewProxyAna::point> arr;
    TFieldViewProxyAna mega_view(view,&arr);
    TRuleEvalResult result;
    rule.eval(mega_view,result);
    mega_view.print();
    printf("end\n");
  }
  struct t_proxyana_points{
    vector<TFieldViewProxyAna::point>&arr;
    vector<vec2i>&out;
    void find(const vec2i&p,bool&result)const
    {
      result=true;
      for(int i=0;i<out.size();i++)
      {
        auto&ex=out[i];
        if(ex.x!=p.x)continue;
        if(ex.y!=p.y)continue;
        return;
      }
      result=false;
    }
    void go()
    {
      bool ok;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        vec2i p={int(ex.x),int(ex.y)};
        find(p,ok);
        if(ok)continue;
        out.push_back(p);
      }
    }
  };
  static void get_result_for_view(TFieldView&view,const vector<const IFieldRule*>&rules,TRuleEvalResult&result)
  {
    TRuleEvalResult result_buff;
    result_buff.ok=false;
    int count=0;
    for(unsigned i=0;i<rules.size();i++)
    {
      auto*prule=rules[i];
      auto&rule=*rules[i];
      for(unsigned mode_id=0;mode_id<8;mode_id++)
      {
        view.mode.set(mode_id);
        if(!rule.dir_test(view.mode))continue;
        TRuleEvalResult result_tmp;
        result_tmp.ok=false;
        result_tmp.value=0;
        rule.eval(view,result_tmp);
        if(result_tmp.ok)
        {
          if(!count)result_buff=result_tmp;
          count++;
        }
      }
    }
    if(count>1)
    {
      int bad=1;
      QapAssert(false);
    }
    result=result_buff;
  }
  static void get_depends_points(TFieldView&view,const vector<const IFieldRule*>&rules,vector<vec2i>&out)
  {
    TRuleEvalResult result_buff;
    int count=0;
    vector<TFieldViewProxyAna::point> arr;
    for(unsigned i=0;i<rules.size();i++)
    {
      auto*prule=rules[i];
      auto&rule=*rules[i];
      for(unsigned mode_id=0;mode_id<8;mode_id++)
      {
        view.mode.set(mode_id);
        if(!rule.dir_test(view.mode))continue;
        TFieldViewProxyAnaV2 mega_view(view,&arr);
        TRuleEvalResult result;
        result.ok=false;
        result.value=0;
        rule.eval(mega_view,result);
        if(result.ok)
        {
          if(!count)result_buff=result;
          count++;
        }
      }
    }
    if(count>1)
    {
      string msg;
      int bad=1;QapAssert(false);
    }
    t_proxyana_points points={arr,out};
    points.go();
  }
  void experiment()
  {
    static TFieldRulesMan man;
    static vector<const IFieldRule*>&rules=man.out_rules;
    /*man.add_rule(
      0x00,
      ".X.\n"
      "XBX\n"
      ".X.\n"
      ,
      ".X.\n"
      "XRX\n"
      ".X.\n"
    );*/
    man.add_rule(0x00,"BGX","XBG");
    man.printf_all_rules();
    man.compile();
    //vector<const IFieldRule*>&rules=get_rules();
    TField field={out,m_w,m_h};
    TFieldView view(field,14,65);
    {
      for(int i=0;i<rules.size();i++)
      {
        auto*ex=(CellWorld::TFieldRuleV02*)rules[i];
        vector<TFieldViewProxyAna::point> arr;
        TFieldViewProxyAna mega_view(view,&arr);
        TRuleEvalResult result;
        ex->eval(mega_view,result);
        if(result.ok)
        {
          string str_rule=ex->tools.preview;
          mega_view.print();
          int gg=1;
        }
      }
    }
    int gg=1;
  }
  static void draw_tool_to_png(TLoaderEnv&Env,const TRuleTools&tool,const string&fn,bool is_from)
  {
    unsigned x0,y0,x1,y1;
    tool.get_size(x0,y0,x1,y1);
    unsigned w=x1-x0+1;
    unsigned h=y1-y0+1;
    {
      TLoaderEnv::TextureMemory mem;
      Env.InitMemory(mem,w,h);
      rgba*ptr=(rgba*)mem.ptr;
      for(int y=0;y<h;y++)
      {
        for(int x=0;x<w;x++)
        {
          rgba no_color={0,0,0,0};
          unsigned int id=x+y*w;
          auto&c=ptr[id];
          c=no_color;
        }
      }
      auto&arr=tool.arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto color=CellTypeToColor(is_from?ex.from:ex.to);
        ptr[(ex.x-x0)+(ex.y-y0)*w]=color;
      }
      //Env.SaveTextureToFile(mem,fn);
      Env.SaveTextureToFile_v2(mem,fn);
      Env.FreeMemory(mem);
    }
  }
  void draw_all_rules()
  {
    get_rules();
    auto&man=get_man();
    auto&tools=man.rules_tools;
    system("mkdir rules");
    for(int i=0;i<tools.size();i++)
    {
      auto&tool=tools[i];
      draw_tool_to_png(Env,tool,"rules\\0x"+IToSex(i,2)+"_a.png",true);
      draw_tool_to_png(Env,tool,"rules\\0x"+IToSex(i,2)+"_b.png",false);
    }
  }
  struct cell_point{
    int x;
    int y;
    unsigned type;
  };

  struct map_frag{
    vector<cell_point> cells;
    unsigned result;
  };

  struct t_heuristic{};
  struct t_field_iterator{
    vector<unsigned>&celltypes;
    vector<cell_point>&arr;
    void inc_type(bool&overflow,unsigned&type)
    {
      overflow=type==celltypes.back();
      for(int i=0;i<celltypes.size();i++)if(celltypes[i]==type){type=celltypes[(i+1)%celltypes.size()];break;}
    }
    void inc(bool&overflow)
    {
      overflow=false;
      for(int i=0;i<arr.size();i++)
      {
        bool flag=false;
        auto&ex=arr[i];
        inc_type(flag,ex.type);
        if(!flag)return;
      }
      overflow=true;
    }
  };
  void get_cell_points_field_size(
    const vector<cell_point>&points,
    int&minx,
    int&miny,
    int&maxx,
    int&maxy
  )const
  {
    minx=std::numeric_limits<int>::max();
    miny=std::numeric_limits<int>::max();
    maxx=std::numeric_limits<int>::min();
    maxy=std::numeric_limits<int>::min();
    for(unsigned i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      minx=std::min(minx,ex.x);
      miny=std::min(miny,ex.y);
      maxx=std::max(maxx,ex.x);
      maxy=std::max(maxy,ex.y);
    }
  }
  void print_some(const vector<cell_point>&points,string*output=0)
  {
    int minx=0;
    int miny=0;
    int maxx=0;
    int maxy=0;
    get_cell_points_field_size(points,minx,miny,maxx,maxy);
    int w=maxx-minx+1;
    int h=maxy-miny+1;
    string buff;buff.resize(w*h);
    for(unsigned i=0;i<buff.size();i++)buff[i]=0;
    for(unsigned i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      auto id=(ex.x-minx)+(ex.y-miny)*w;
      buff[id]=CellTypeToChar(ex.type);
    }
    string out;
    auto draw=[&w,&h](const string&buff,string&out)
    {
      for(int i=0;i<h;i++)
      {
        for(int j=0;j<w;j++)
        {
          char c=buff[i*w+j];
          out.push_back(c?c:'.');
        }
        out+="\n";
      }
    };
    draw(buff,out);
    if(output){
      *output=out;return;
    }
    printf("%s\n",out.c_str());
  }
  void start_heuristics()
  {
    vector<unsigned> field_arr;
    TField field={field_arr};
    field.m_w=128;
    field.m_h=128;
    field.arr.resize(field.m_w*field.m_h);
    vector<CellTypeRec> celltypes_raw;
    GetCellTypes(celltypes_raw);
    //
    auto&source=field;
    auto&man=get_man();
    man.add_rule(0x80,"BX","XG");
    //man.add_rule(0x80,"G","X");
    //man.add_rule(0x80,"X","B");
    //man.add_rule(0x80,"BGX","XBG");
    auto&rules=man.out_rules;
    man.printf_all_rules();
    man.compile();
    //
    vector<unsigned> celltypes;
    vector<unsigned> celltypes_used;
    celltypes_used.resize(celltypes_raw.size(),0);
    celltypes.resize(celltypes_raw.size());
    for(int i=0;i<celltypes_raw.size();i++)celltypes[i]=celltypes_raw[i].Value;
    for(int i=0;i<man.rules_tools.size();i++)
    {
      auto&ex=man.rules_tools[i];
      for(int j=0;j<ex.arr.size();j++)
      {
        auto find=[&celltypes](unsigned type)->int{for(int i=0;i<celltypes.size();i++)if(celltypes[i]==type)return i;return -1;};
        celltypes_used[find(ex.arr[j].from)]=1;
        celltypes_used[find(ex.arr[j].to)]=1;
      }
    }
    bool need_optimized_set_of_celltypes=true;
    if(need_optimized_set_of_celltypes)
    {
      auto tmp=celltypes;celltypes.clear();
      for(int i=0;i<tmp.size();i++)if(celltypes_used[i])celltypes.push_back(tmp[i]);
    }
    for(int i=0;i<field.arr.size();i++)field.arr[i]=celltypes[0]; 
    //
    vec2i pos={int(field.m_w/2),int(field.m_h/2)};
    auto id=source.get_pos_with_offset(pos.x,pos.y,0,0);
    vector<vec2i> points;
    TFieldView view(source,pos.x,pos.y);
    {
      get_depends_points(view,rules,points);
      TRuleEvalResult result;
      get_result_for_view(view,rules,result);
    }
    //fetch
    vector<cell_point> cellpoints;
    cellpoints.resize(points.size());
    for(int i=0;i<cellpoints.size();i++)
    {
      auto&out=cellpoints[i];
      auto&ex=points[i];
      out.x=ex.x;
      out.y=ex.y;
      out.type=view.at(ex.x,ex.y);
    }
    //iterate
    t_field_iterator iterator={celltypes,cellpoints};
    bool exit_flag=false;
    vector<map_frag> frags;
    vector<string> str_frags;
    int passed=0;
    int iter_count=0;
    while(!exit_flag)
    {
      for(int i=0;i<cellpoints.size();i++)
      {
        auto&ex=cellpoints[i];
        auto id=source.get_pos_with_offset(pos.x,pos.y,ex.x,ex.y);
        source.arr[id]=ex.type;
      }
      {}
      {
        points.clear();
        get_depends_points(view,rules,points);
        {
          for(int i=0;i<points.size();i++)
          {
            auto&ex=points[i];
            auto find=[&cellpoints](int x,int y)->int
            {
              for(int i=0;i<cellpoints.size();i++)
              {
                auto&ex=cellpoints[i];
                bool flag=(x==ex.x)&&(y==ex.y);
                if(flag){
                  return i;
                }
              }
              return -1;
            };
            int point_id=find(ex.x,ex.y);
            if(point_id<0)
            {
              cell_point tmp;
              auto id=source.get_pos_with_offset(pos.x,pos.y,ex.x,ex.y);
              auto&type=source.arr[id];
              QapAssert(type==celltypes[0]);
              tmp.type=type;
              tmp.x=ex.x;
              tmp.y=ex.y;
              cellpoints.push_back(tmp);
            }
          }
        }
        TRuleEvalResult result;
        get_result_for_view(view,rules,result);
        if(result.ok)
        {
          bool ok=view.at(0,0)!=result.value;
          QapAssert(ok);
          if(ok)
          {
            passed++;
            //map_frag frag;
            //frag.cells=cellpoints;
            //frag.result=result.value;
            //frags.push_back(frag);
            str_frags.push_back("");
            print_some(cellpoints,&str_frags.back());
            //print_some(cellpoints);
          }
          //print_some(cellpoints);
        }
      }
      {}      
      if(iter_count%(1024)==0)
      {
        //print_some(cellpoints);
        string s="";
        for(int i=0;i<cellpoints.size();i++)s+=CellTypeToChar(cellpoints[i].type);
        printf("%s\n",s.c_str());
        printf("iter = %8i        passed = %8i\n",iter_count,passed);
      }
      iter_count++;
      iterator.inc(exit_flag);
    }
    printf("iter = %8i        passed = %8i\n",iter_count,passed);
    for(int i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      //if(!ex.x)if(!ex.y)continue;
      auto id=source.get_pos_with_offset(pos.x,pos.y,ex.x,ex.y);
      //ex_arr.push_back(pos);
    }
  }
};

//<<<<<=====CellWorld
#endif //DEF_BUILD_MICRO//

#include <io.h>
bool FileExists(const string&fn)
{
	_finddata_t data;
  long nFind=_findfirst(fn.c_str(),&data);
	if(nFind!=-1){_findclose(nFind);return true;}
	return false;
}

void copy_world_to_example()
{
  int id=0;
  for(auto&i=id;i<0xff;i++)
  {
    if(!FileExists("0x"+IToSex(i,2)+".png"))break;
  }
  string fn="0x"+IToSex(id,2)+".png";
  system(("copy ..\\Release\\world.png "+fn).c_str());
}
#include <fstream>
string file_get_contents(const string&fn){
  std::ifstream file(fn,std::ios::binary);
  return std::string((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
}

int main(int argc,char**argv)
{
  //copy_world_to_example(); return 0;
  srand(time(0));
  CellWorld World;
  auto s=file_get_contents("rules.json");
  World.rules.load_from_str(s);
  //World.draw_all_rules();
  int sim_limit=1024*16;
  if(argc==3){sim_limit=std::stoi(argv[2]);}
  printf("sim_limit == %i\n",sim_limit);
  auto fn=argc>=2?argv[1]:"world.png";
  if(bool debug=0){fn="bug.png";}
  World.load(fn);
  //World.start_heuristics();
  World.run(sim_limit);
  return 0;
}
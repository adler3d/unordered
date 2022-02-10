#pragma once
#pragma once
using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::iostream;
using std::stringstream;
using std::array;
using std::unique_ptr;
typedef double real;
typedef INT64 int64;
typedef UINT64 uint64;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef vector<string> StringArray;
typedef vector<void*> PtrArray;
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
#pragma once
struct TScreenMode{int W,H,BPP,Freq;};
template<class TYPE>
inline static TYPE max(const TYPE&a,const TYPE&b){return a>b?a:b;}
template<class TYPE>
inline static TYPE min(const TYPE&a,const TYPE&b){return a<b?a:b;}
template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}
inline static int max(int a,int b){return a>b?a:b;}
inline static int min(int a,int b){return a<b?a:b;}
inline static float max(float a,float b){return a>b?a:b;}
inline static float min(float a,float b){return a<b?a:b;}
inline static double max(double a,double b){return a>b?a:b;}
inline static double min(double a,double b){return a<b?a:b;}
template<typename TYPE>TYPE Sign(TYPE value){if(value>0){return TYPE(+1);}else{return TYPE(value<0?-1:0);};};
template<typename TYPE>bool InDip(TYPE min,TYPE val,TYPE max){return (val>=min)&&(val<=max);};
inline TScreenMode GetScreenMode()
{
  HDC DC=GetDC(0); 
  TScreenMode Res={GetDeviceCaps(DC,HORZRES),GetDeviceCaps(DC,VERTRES),GetDeviceCaps(DC,BITSPIXEL),GetDeviceCaps(DC,VREFRESH)};
  ReleaseDC(0,DC);
  return Res;
}
class CharMask{
public:
  bool mask[256];
  CharMask(CharMask&&ref){for(uint i=0;i<sizeof(mask);i++)mask[i]=ref.mask[i];}
  CharMask(){for(uint i=0;i<sizeof(mask);i++)mask[i]=false;}
public:
  static CharMask fromStr(const string&str)
  {
    CharMask tmp;
    tmp.prepare(str);
    return std::move(tmp);
  }
public:
  template<size_t COUNT>
  explicit CharMask(const char(&allowed)[COUNT]){
    string str;
    str.resize(COUNT-1);
    for(int i=0;i<str.size();i++)str[i]=*(char*)(void*)&allowed[i];
    prepare(str);
    if(false)
    {
      string unallowed;
      for(int i=1;i<256;i++)if(!mask[i])unallowed.push_back(i);
      QapDebugMsg(unallowed);
    }
  }
  void prepare(const std::string&allowed)
  {
    for(uint i=0;i<sizeof(mask);i++)mask[i]=false;
    for(uint i=0;i<uint(allowed.size());i++)
    {
      unsigned char uc=uchar(allowed[i]);
      bool&flag=mask[uc];
      QapAssert(!flag);
      flag=true;
    }
  };
  bool check(const std::string&str)const
  {
    auto n=str.size();
    if(!n)return true;
    const auto*p=&str[0];
    auto e=p+n;
    for(;p<e;p++)
    {
      if(!mask[uchar(*p)])return false;
    }
    return true;
  }
  bool operator[](uchar index)const{return mask[index];}
};
inline real RndReal(const real&min,const real&max){return min+(max-min)*(real)rand()/(real)RAND_MAX;};
inline string CToS(const char&val){string tmp="";tmp.push_back(val);return tmp;};
inline string IToS(const int&val){char c[16];_itoa_s(val,c,10);return string(c);}
inline string UCToS(const unsigned char&val){char d[8]; sprintf_s(d,sizeof(d),"%u",val); return string(d);}
inline string HToS(const int&val){char c[16];_itoa_s(val,c,16);return "0x"+string(c);}
inline string IToSex(const int&val){char c[40];sprintf_s(c,"%08i",val);int i=0;while(c[i]=='0')c[i++]='-';return string(c);}
inline string FToS(const real&val){char c[64];if(abs(val)>1e9){_snprintf_s(c,32,32,"%e",val);}else{sprintf_s(c,"%.2f",val);}return string(c);}
inline string BToS(const bool&val){return val?"true":"false";};
inline string IToH(const int&val){char d[255]; sprintf_s(d,sizeof(d),"0x%08X",val); return string(d);}
inline string IToH(const int&val,int n){char d[255]; n=n<0?8:n>8?8:n; string c=IToS(n); sprintf_s(d,sizeof(d),("0x%0"+c+"X").c_str(),val); return string(d);}
inline string IToH_raw(const int&val){char d[255]; sprintf_s(d,sizeof(d),"%08X",val); return string(d);}
inline char HToC(const string&str){size_t val;sscanf_s(str.c_str(),"%02x",&val); return char(val);}
inline bool SToF(const string&str,real&val){sscanf_s(str.c_str(),"%lf",&val);return true;}
inline bool SToB(const string&str,bool&val){val=str=="true";return true;}
inline bool SToB(const string&str){return str=="true";}
inline bool SToC(const string&str,char&val){if(str.size()!=1)return false;val=str[0];return true;}
inline bool HToI(const string&str,int&val){sscanf_s(str.c_str(),"0x%08X",&val); return true;}
inline int HToI(const string&str){int val;sscanf_s(str.c_str(),"0x%08X",&val); return val;}
inline int HToI_raw(const string&str){int val;sscanf_s(str.c_str(),"%08X",&val); return val;}
inline string CToH_raw(const unsigned char&val){char d[3]; sprintf_s(d,sizeof(d),"%02X",val); return string(d);}
inline string SToS(const string&s){return s;}
template<size_t COUNT> inline string SToS(const char(&lzstr)[COUNT]){static_assert(COUNT,"WTF?");return string(&lzstr[0],size_t(COUNT-1));}
inline string SToSex(const string&S,const int&l){string s(l,' ');for(int i=0;i<int(S.size());i++)s[i]=S[i];return s;}
inline int SToI(const string&S){int i;sscanf_s(S.c_str(),"%i",&i);return i;};
inline int SToI_fast(const string&S){
  int i;sscanf_s(S.c_str(),"%i",&i);return i;
};
inline string GetFileName(const string&filename)
{
  static CharMask mask("\\/");
  if(filename.empty())return filename;
  int c=0;
  for(int i=filename.size()-1;i>=0;i--)
  {
    if(mask.mask[filename[i]])
    {
      string out=filename.substr(i+1,c);
      return out;
    }
    c++;
  }
  return filename;
}
inline bool IsRawDirName(const std::string&dirname)
{
  static CharMask mask(".");
  const string&raw=GetFileName(dirname);
  return !mask.check(raw);
}
inline string RemoveFileExt(const string&FN)
{
  const int pos=FN.rfind(".");
  return std::move(FN.substr(0,pos));
}
inline string ChangeFileExt(const string&FN,const string&Ext)
{
  string tmp=RemoveFileExt(FN)+Ext;
  return std::move(tmp);
}
inline string BackSlashesToSlashes(const string&data)
{
  string tmp=data;
  for(int i=0;i<tmp.size();i++)
  {
    char&c=tmp[i];
    if(c=='\\'){
      c='/';
    }
  }
  return std::move(tmp);
}
inline string ScanParam(const string&Before,const string&Where,const string&After,int&Pos)
{
  int E=Where.find(Before, Pos);
  if(E==-1){Pos=-1; return "";}
  Pos=Where.find(Before,Pos)+Before.length();
  E=After.empty()?Where.size():Where.find(After,Pos);
  if(E==-1){Pos=-1; return "";}
  string result; result.assign(Where,Pos,E-Pos);
  return std::move(result);
}
inline string GetDataTimeStr()
{
  class UG{public:static inline string X(int val,string fs){char c[40];sprintf_s(c,fs.c_str(),val);return string(c);}};
  SYSTEMTIME LT;
  GetLocalTime(&LT);
  string Str;
    Str=UG::X(LT.wYear,"%0""2""i")+"-"+UG::X(LT.wMonth,"%0""2""i")+"-"+UG::X(LT.wDay,"%0""2""i")+" "
      +UG::X(LT.wHour,"%0""2""i")+"-"+UG::X(LT.wMinute,"%0""2""i")+"-"+UG::X(LT.wSecond,"%0""2""i")+"-"+UG::X(LT.wMilliseconds,"%0""3""i");
  Str.resize(Str.size()-1);
  return Str;
}
inline string GetFileExt(const string&FN){int e=FN.rfind(".");string ext=ScanParam(".",FN,"",e);return ext;}
inline string LowerStr(const string&s){string str=s;for(int i=0;i<int(str.size());i++)str[i]=tolower(str[i]);return std::move(str);}
inline string UpperStr(const string&s){string str=s;for(int i=0;i<int(str.size());i++)str[i]=toupper(str[i]);return std::move(str);}
inline bool IsNumChar(const uchar&c)
{
  return bool(uchar('0')<=c&&uchar('9')>=c);
}
inline bool IsLegalChar(const uchar&c)
{
  return bool(uchar('a')<=c&&uchar('z')>=c)||bool(uchar('A')<=c&&uchar('Z')>=c)||bool(uchar('0')<=c&&uchar('9')>=c);
}
template<typename Callback>
class LineVisitor{
public:
  int line;
  int pos;
  const string&mem;
  LineVisitor(const string&mem):mem(mem){pos=0;line=0;}
  bool Next(Callback&callback)
  {
    line++;
    const string sepstr="\n";
    int npos=mem.find(sepstr,pos);
    if(npos<0)return false;
    string line=std::move(mem.substr(pos,npos-pos));
    callback(line);
    pos=npos+sepstr.size();
    return true;
  }
};
class Extractor{
public:
  class Gripper{
  public:
    string before;
    string after;
    Gripper(const string&before,const string&after):before(before),after(after){}
    string grip(const string&source)const{return before+source+after;}
  };
public:
  int pos;
  string source;
  Extractor(const string&source):pos(0),source(source){}
  string extract(const Gripper&ref){
    string s=ScanParam(ref.before,source,ref.after,pos);
    if(pos>=0)pos+=s.size()+ref.after.size();
    return s;
  }
  template<class TYPE>
  void extract_all(TYPE&visitor,const Gripper&ref)
  {
    while(pos>=0){
      string s=extract(ref);
      if(pos<0)break;
      visitor.accept(s);
    }
  }
  operator bool(){return pos>=0;}
};
template<class TYPE>
class FindData{
public:
  WIN32_FIND_DATA ffd;
  string Dir;
  HANDLE hFind;
  char buff[1024];
  TYPE&Functor;
  FindData(const string&dir,TYPE&Functor,bool manual=false):hFind(nullptr),Functor(Functor){
    Dir=dir;
    if(manual)return;
    Start();
    do{}while(Next());
    Stop();
  }
  void Start(){
    if(hFind)return;
    string filename=Dir+"/*";
    hFind=FindFirstFileA(filename.c_str(),&ffd);
    if(INVALID_HANDLE_VALUE==hFind){QapDebugMsg("INVALID_HANDLE_VALUE");return;}
  }
  bool Next(){
    if(!hFind)return false;
    string fn=ffd.cFileName;
    {
      fn=Dir+"/"+fn;
      Functor(fn,bool(ffd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY));
    }
    if(!FindNextFile(hFind,&ffd))
    {
      auto dwError=GetLastError();
      if(dwError!=ERROR_NO_MORE_FILES){
        QapDebugMsg("failed");
      }
      Stop();
      return false;
    }
    return true;
  }
  void Stop(){
    if(!hFind)FindClose(hFind);hFind=nullptr;
  }
  operator bool(){return hFind;}
  ~FindData(){
    Stop();
  }
};
static string gen_dip(char from,char to){
  QapAssert(from<to);
  string out;
  out.reserve(to-from);
  bool flag=from!=to;
  for(auto c=from;flag;c++){
    flag=flag&&(c!=to);
    out.push_back(c);
  }
  return out;
}
static string gen_dips(const string&rule){
  QapAssert(!(rule.size()%2));
  string out;
  for(int i=0;i<rule.size();i+=2){
    out+=gen_dip(rule[i+0],rule[i+1]);
  }
  return out;
}
static string dip_inv(const string&dip){
  string out;
  char min=std::numeric_limits<char>::min();
  char max=std::numeric_limits<char>::max();
  bool flag=min!=max;
  for(auto c=min;flag;c++){
    flag=flag&&(c!=max);
    auto e=dip.find(CToS(c));
    if(e!=std::string::npos)continue;
    out.push_back(c);
  }
  return out;
}
static vector<string> split(const string&s,const string&needle)
{
  vector<string> arr;
  if(s.empty())return arr;
  size_t p=0;
  for(;
  ){
    auto pos=s.find(needle,p);
    if(pos==std::string::npos){arr.push_back(s.substr(p));return arr;}
    arr.push_back(s.substr(p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}
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
inline string StrReplace(const string&input,const string&sub,const string&now)
{
  return join(split(input,sub),now);
}
static string urlencode(const string&str)
{
  string tmp;tmp.reserve(str.size()*3);
  for(int i=0;i<str.size();i++)
    tmp+=IsLegalChar(str[i])?CToS(str[i]):"%"+CToH_raw(str[i]);
  return tmp;
}
static string urldecode(const string&s)
{
  auto arr=split(s,"%");
  string out="";
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    if(i==0){out+=ex;continue;}
    QapAssert(ex.size()>=2);
    out.push_back(char(HToC(ex.substr(0,2))));
    out+=ex.substr(2);
  }
  return out;
}
/*
template<class TYPE>
static vector<TYPE> subarr(const vector<TYPE>&arr,int offset,int count)
{
  QapAssert(offset>=0);QapAssert(count>=0);
  vector<TYPE*> out;
  int limit=std::min<int>(arr.size(),offset+count);
  for(int i=offset;i<limit;i++){
    out.push_back(arr[i]);
  }
  return std::move(out);
}
template<class TYPE>
static vector<TYPE*> subarr(const vector<TYPE>&arr,int offset)
{
  QapAssert(offset>=0);
  return std::move(subarr(arr,offset,arr.size()-offset));
}
*/
template<class TYPE>
static void subarr_in_place(vector<TYPE>&arr,int offset)
{
  if(offset==0)return;
  QapAssert(offset>0);QapAssert(offset<arr.size());
  for(int i=0;i+offset<arr.size();i++){
    arr[i]=std::move(arr[i+offset]);
  }
  arr.resize(arr.size()-offset);
}
template<class TYPE>
vector<TYPE> qap_arr_slice(vector<TYPE>&arr,int offset)
{
  vector<TYPE> out;
  if(offset==0)return out;
  QapAssert(offset>0);QapAssert(offset<arr.size());
  offset=std::max<int>(0,std::min<int>(offset,arr.size()));
  for(int i=0;i<offset;i++){
    out.push_back(std::move(arr[i]));
  }
  subarr_in_place(arr,offset);
  return out;
}
template<class TYPE>
void qap_arr_join(vector<TYPE>&arr,vector<TYPE>&end)
{
  arr.reserve(arr.size()+end.size());
  for(int i=0;i<end.size();i++){
    arr.push_back(std::move(end[i]));
  }
}
template<class TYPE>class TAutoPtr;
template<class TYPE>class TWeakPtr;
template<class TYPE>
void QapClean(vector<TAutoPtr<TYPE>>&Arr)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(!ex)continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>
void QapClean(vector<TWeakPtr<TYPE>>&Arr)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(!ex)continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE,class FUNC>
void QapCleanIf(vector<TYPE>&Arr,FUNC&Pred)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(Pred(ex))continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>
void QapPopFront(vector<TYPE>&arr)
{
  int last=0;
  for(int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(last!=i)
    {
      auto&ax=arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==arr.size())return;
  arr.resize(last);
}
template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr){arr.push_back(TYPE());return arr.back();}
template<class TYPE,class FUNC>
static vector<int> qap_find(vector<TYPE>&arr,FUNC&func){
  vector<int> out;
  for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(func(ex))out.push_back(i);}
  return out;
}
static vector<int> qap_find_str(const vector<string>&arr,const string&value){
  vector<int> out;
  for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(ex==value)out.push_back(i);}
  return out;
}
template<class TYPE,class FUNC>
static void qap_foreach(vector<TYPE>&inp,FUNC&func)
{
  auto&arr=inp;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    func(ex);
  }
}
template<class TYPE>
struct QapToolsVector
{
  vector<TYPE>&arr;
  void operator+=(vector<TYPE>&&ref)
  {
    arr.reserve(arr.size()+ref.size());
    for(int i=0;i<ref.size();i++)
    {
      arr.push_back(std::move(ref[i]));
    }
    ref.clear();
  }
};
template<class TYPE>
QapToolsVector<TYPE> QapToolsVectorEx(vector<TYPE>&ref)
{
  QapToolsVector<TYPE> tmp={ref};return std::move(tmp);
}
enum QapMsgBoxRetval{
  qmbrSkip,qmbrBreak,qmbrIgnore
};
inline int WinMessageBox(const string&caption,const string&text){
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  QapMsgBoxRetval retval=qmbrSkip;
  if(IDCONTINUE==nCode)retval=qmbrIgnore;
  if(IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
}
typedef int(*TQapMessageBox)(const string&caption,const string&text);
struct TMessageBoxCaller{
  static int Call(const string&caption,const string&text){
    return Get()(caption,text);
  }
  static TQapMessageBox&Get(){
    static TQapMessageBox func=WinMessageBox;
    return func;
  }
  struct t_hack{
    TQapMessageBox old;
    t_hack(TQapMessageBox func){old=Get();Get()=func;}
   ~t_hack(){Get()=old;}
  };
};
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
    +"\n\nLine : "+IToS(line)
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
    +"\n\nLine : "+IToS(line)
    +"\n\nFunction :\n"+funcname
    +"\n\nDebug message :\n"+msg;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Debug message",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
class CppString{
public:
  string data;
  CppString(){}
  CppString(const string&ref){oper_set(ref);}
public:
  void operator=(const string&ref){oper_set(ref);}
public:
  static string toCode(uchar ch){
    string tmp=CToH_raw(ch);
    string out="\\x"+tmp;
    return out;
  };
  static const CharMask&getMask()
  {
    static CharMask mask(
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "0123456789"
      "_ №"
      "+-*/=|~!@#$%^&()[]{}<>.,:?;`"
      "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
      "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
    );
    return mask;
  }
  void oper_set(const string&ref)
  {
    int linestart=0;
    const CharMask&mask=CppString::getMask();
    data.clear();
    data.reserve(ref.size());
    struct Hidden{
      string&data;
      string line;
      int line_count;
      Hidden(string&data):data(data){line_count=0;}
      ~Hidden()
      {
        if(!line.empty())next();
        if(line.size()<=64)return;
        string beg="BEGIN()\n";
        string end="END()\n";
        data=beg+data+end;
      }
      void next(){
        static const int c8k=2<<12;
        line_count++;
        data+=line;
        line.clear();
        if(!(line_count%c8k))
        {
          QapDebugMsg("big line");
          data+="END()\nBEGIN()\n";
        }
      }
      void check(){
        const int linesize=line.size();
        if(linesize>80)next();
      }
    } HD(data);
    string&line=HD.line;
    for(int i=0;i<ref.size();i++)
    {
      uchar ex=ref[i];
      HD.check();
      if(!mask[ex])
      {
        if(ex=='\\'){line+="\\\\";continue;}
        if(ex=='\"'){line+="\\\"";continue;}
        if(ex=='\''){line+="\\\'";continue;}
        if(ex=='\n'){line+="\\n";continue;}
        if(ex=='\r'){line+="\\r";continue;}
        if(ex=='\t'){line+="\\t";continue;}
        if(ex=='\b'){line+="\\b";continue;}
        if(ex=='\f'){line+="\\f";continue;}
        if(ex=='\0'){line+="\\0";continue;}
        if(ex=='\1'){line+="\\1";continue;}
        if(ex=='\2'){line+="\\2";continue;}
        if(ex=='\3'){line+="\\3";continue;}
        if(ex=='\4'){line+="\\4";continue;}
        if(ex=='\5'){line+="\\5";continue;}
        if(ex=='\6'){line+="\\6";continue;}
        if(ex=='\7'){line+="\\7";continue;}
          line+=toCode(ex);
      }else{
        line.push_back(ex);
      }
    }
  }
public:
  static bool IsValidCppChar(char c)
  {
    const CharMask&mask=CppString::getMask();
    unsigned char uc=*(unsigned char*)(void*)&c;
    return mask.mask[uc];
  }
};
class BinString{
public:
  string data;
  BinString(){}
  BinString(const string&ref){oper_set(ref);}
public:
  void operator=(const string&ref){oper_set(ref);}
public:
  static string fullCppStr2RawStr(const string&cpp){
    QapAssert(cpp.size()>2);
    QapAssert(cpp.front()=='"');
    QapAssert(cpp.back()=='"');
    BinString bin=cpp.substr(1,cpp.size()-2);
    return bin.data;
  }
  static string toCode(uchar ch){
    string tmp=CToH_raw(ch);
    string out="'\\x"+tmp+"'";
    return out;
  };
  void oper_set(const string&ref)
  {
    int linestart=0;
    const CharMask&mask=CppString::getMask();
    data.clear();
    data.reserve(ref.size());
    uchar prev=0;
    for(int i=0;i<ref.size();i++)
    {
      uchar ex=ref[i];
      if((!mask[ex])||(prev=='\\'))
      {
        {if((prev=="\\\\"[0])&&(ex=="\\\\"[1])){data.push_back('\\');prev=0;continue;}}
        {if((prev=="\\\""[0])&&(ex=="\\\""[1])){data.push_back('\"');prev=0;continue;}}
        {if((prev=="\\\'"[0])&&(ex=="\\\'"[1])){data.push_back('\'');prev=0;continue;}}
        {if((prev=="\\n"[0])&&(ex=="\\n"[1])){data.push_back('\n');prev=0;continue;}}
        {if((prev=="\\r"[0])&&(ex=="\\r"[1])){data.push_back('\r');prev=0;continue;}}
        {if((prev=="\\t"[0])&&(ex=="\\t"[1])){data.push_back('\t');prev=0;continue;}}
        {if((prev=="\\b"[0])&&(ex=="\\b"[1])){data.push_back('\b');prev=0;continue;}}
        {if((prev=="\\f"[0])&&(ex=="\\f"[1])){data.push_back('\f');prev=0;continue;}}
        {if((prev=="\\0"[0])&&(ex=="\\0"[1])){data.push_back('\0');prev=0;continue;}}
        {if((prev=="\\1"[0])&&(ex=="\\1"[1])){data.push_back('\1');prev=0;continue;}}
        {if((prev=="\\2"[0])&&(ex=="\\2"[1])){data.push_back('\2');prev=0;continue;}}
        {if((prev=="\\3"[0])&&(ex=="\\3"[1])){data.push_back('\3');prev=0;continue;}}
        {if((prev=="\\4"[0])&&(ex=="\\4"[1])){data.push_back('\4');prev=0;continue;}}
        {if((prev=="\\5"[0])&&(ex=="\\5"[1])){data.push_back('\5');prev=0;continue;}}
        {if((prev=="\\6"[0])&&(ex=="\\6"[1])){data.push_back('\6');prev=0;continue;}}
        {if((prev=="\\7"[0])&&(ex=="\\7"[1])){data.push_back('\7');prev=0;continue;}}
        if((prev!='\\')&&ex=='\\'){prev=ex;continue;}
        QapDebugMsg("bad char("+toCode(ex)+") = \'"+CToS(ex)+"\'");
        return;
      }else{
        data.push_back(ex);
      }
      prev=ex;
    }
  }
};
namespace detail{};
class IEnvRTTI;
class TType;
class TTypeSys;
class TTypeStruct;class TTypeSys;class TTypeFactory;class TTypeVector;class TTypeArray;class TTypeSelfPtr;class TTypeAutoPtr;class TTypeWeakPtr;class TTypeHardPtr;class TTypeVoidPtr;class TTypeFieldPtr;
class IVisitorRTTI{
public:
  virtual void Do(TTypeStruct*p)=0;
  virtual void Do(TTypeSys*p)=0;
  virtual void Do(TTypeFactory*p){}
  virtual void Do(TTypeVector*p)=0;
  virtual void Do(TTypeArray*p)=0;
  virtual void Do(TTypeSelfPtr*p)=0;
  virtual void Do(TTypeAutoPtr*p)=0;
  virtual void Do(TTypeWeakPtr*p)=0;
  virtual void Do(TTypeHardPtr*p)=0;
  virtual void Do(TTypeVoidPtr*p)=0;
  virtual void Do(TTypeFieldPtr*p)=0;
public:
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr;
    Is():ptr(nullptr){}
  public:
    template<class U>static TYPE*get(U*p){return nullptr;}
    template<>static TYPE*get<TYPE>(TYPE*p){return p;}
  public:
    void Do(TTypeStruct*p){ptr=get(p);}void Do(TTypeSys*p){ptr=get(p);}void Do(TTypeFactory*p){ptr=get(p);}void Do(TTypeVector*p){ptr=get(p);}void Do(TTypeArray*p){ptr=get(p);}void Do(TTypeSelfPtr*p){ptr=get(p);}void Do(TTypeAutoPtr*p){ptr=get(p);}void Do(TTypeWeakPtr*p){ptr=get(p);}void Do(TTypeHardPtr*p){ptr=get(p);}void Do(TTypeVoidPtr*p){ptr=get(p);}void Do(TTypeFieldPtr*p){ptr=get(p);}
  };
  template<class TYPE>
  static TYPE*UberCast(TType*p){
    if(!p)return nullptr;Is<TYPE,IVisitorRTTI> IS;p->Use(IS);return IS.ptr;
  }
};
template<class SYS_TYPE>class Sys$$;
namespace detail {
  struct yes_type{char padding[1];};
  struct no_type{char padding[8];};
	template<bool condition,typename true_t,typename false_t>struct select;
	template<typename true_t,typename false_t>struct select<true,true_t,false_t>{typedef true_t type;};
	template<typename true_t,typename false_t>struct select<false,true_t,false_t>{typedef false_t type;};
  template<class U,U x>struct test;
  template<class TYPE>
  static void TryDoReset(void*){}
  template<class TYPE>
  static void TryDoReset(TYPE*Self,void(TYPE::ParentClass::*pDoReset)()=&TYPE::ParentClass::DoReset)
  {
    (Self->*pDoReset)();
  }
  /*
  template<typename T>
  struct has_self{
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      detail::test<void(*)(),&U::SysHasSelf>(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };*/
  template<typename T>
  struct has_self{
    __if_not_exists(T::Self){
      static const bool value=false;
    }
    __if_exists(T::Self){
      static const bool value=true;
      __if_exists(TSelfPtr){
          typedef decltype((*(T*)nullptr).Self) t_self_type;
          static_assert(
            std::is_same<TSelfPtr<T>,decltype((*(T*)nullptr).Self)>::value
            ||
            std::is_base_of<t_self_type::ptr_t,T>::value
            ,
            "must!"
          );
      }
    }
  };
  template<typename T>
  struct has_ParentClass{
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      typename U::ParentClass(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };
  template<class TYPE,bool flag=has_ParentClass<TYPE>::value>
  struct GetParentClassOf{
    typedef void type;
    static TType*GetRTTI(...){return nullptr;};
  };
  template<class TYPE>
  struct GetParentClassOf<TYPE,true>{
    typedef typename TYPE::ParentClass type;
    template<class QAP_RTTI>
    static TType*GetRTTI(QAP_RTTI&RTTI){
      return Sys$$<type>::GetRTTI(RTTI);
    };
  };
  template<typename T>
  struct has_ProxySys$$
  {
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      typename U::ProxySys$$(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };
  template<class TYPE>
  static void FieldTryDoReset(TYPE&p,...){}
  template<class TYPE,size_t SIZE>static void FieldTryDoReset(array<TYPE,SIZE>&arr){for(int i=0;i<SIZE;i++)FieldTryDoReset(arr[i]);}
  static void FieldTryDoReset(unsigned short&ref){ref=0;};
  static void FieldTryDoReset(short&ref){ref=0;};
  static void FieldTryDoReset(bool&ref){ref=0;};
  static void FieldTryDoReset(int&ref){ref=0;};
  static void FieldTryDoReset(size_t&ref){ref=0;};
  static void FieldTryDoReset(float&ref){ref=0;};
  static void FieldTryDoReset(double&ref){ref=0;};
  static void FieldTryDoReset(char&ref){ref=0;};
  static void FieldTryDoReset(uchar&ref){ref=0;};
  template<typename TYPE,bool is_proxy>struct GetProxyMetaType;
  template<typename TYPE>
  struct GetProxyMetaType<TYPE,false>
  {
    typedef TType type;
  };
  template<typename TYPE>
  struct GetProxyMetaType<TYPE,true>
  {
    typedef typename TYPE::ProxySys$$::metatype type;
  };
  template<typename TYPE,bool is_proxy>
  struct GetProxyRTTI;
  template<typename TYPE>
  struct GetProxyRTTI<TYPE,true>
  {
    typedef typename TYPE::ProxySys$$::metatype type;
    template<class QAP_RTTI>
    static type*Do(QAP_RTTI&RTTI){return TYPE::ProxySys$$::GetRTTI(RTTI);}
    static string GetFullName(){return std::move(TYPE::ProxySys$$::GetFullName());}
  };
  template<class TYPE,bool flag=std::is_abstract<TYPE>::value>
  struct QapAlignOf{
    struct proqap{
      TYPE f0;
      char f1;
      TYPE f2;
    };
    static const int value=sizeof(proqap)-2*sizeof(TYPE);
  };
  template<class TYPE>
  struct GetTemplParam
  {
    typedef void type;
  };
  template<template<class> class TEMPL,class TYPE>
  struct GetTemplParam<TEMPL<TYPE>>
  {
    typedef typename TYPE type;
  };
  /*
  template<class TYPE>
  class HasGetClassMetaSpecInfo{
  public:
    template<class T,T v>...
  public:
    template<class U>
    static yes_type test(
      U*,
      string(*)()=&U::GetClassMetaSpecInfo
    );
    template<class U>
    static no_type test(...);
    static const bool value=sizeof(test<TYPE>(0))==sizeof(yes_type);
  };*/
  template<class TYPE>
  struct TGetSpecInfoTool{
    __if_exists(TYPE::GetClassMetaSpecInfo){
      static string GetSpecInfo(){return TYPE::GetClassMetaSpecInfo();}
    }__if_not_exists(TYPE::GetClassMetaSpecInfo){
      static string GetSpecInfo(){return "";}
    }
  };
  template<class TYPE>
  static string GetSpecInfo(){return TGetSpecInfoTool<TYPE>::GetSpecInfo();}
};
template<class SYS_TYPE>
class Sys$${
public:
  static const bool is_proxy=detail::has_ProxySys$$<SYS_TYPE>::value;
  typedef typename detail::GetProxyMetaType<SYS_TYPE,is_proxy>::type metatype;
  typedef typename SYS_TYPE type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    static_assert(is_proxy,"not implemented");
    return detail::GetProxyRTTI<SYS_TYPE,is_proxy>::Do(RTTI);
  }
  static string GetFullName()
  {
    static_assert(is_proxy,"not implemented");
    return detail::GetProxyRTTI<SYS_TYPE,is_proxy>::GetFullName();
  }
};
template<>
class Sys$$<void>{
public:
  static const bool is_proxy=detail::has_ProxySys$$<void>::value;
  typedef detail::GetProxyMetaType<void,is_proxy>::type metatype;
  typedef void type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    return nullptr;
  }
  static string GetFullName()
  {
    QapDebugMsg("WTF?");
    return "void";
  }
};
/*class UniqueData{
public:
  typedef std::string data_t;
private:
  void operator=(const UniqueData&){QapAssert(0);};
  UniqueData(const UniqueData&){QapAssert(0);};
public:
#define MACRO_WEAK
#include "macro_scope.inl"
  MACRO_WEAK_PROC(on_init,(),()){DEF_LOG("add "+this->data);}
  MACRO_WEAK_PROC(on_free,(),()){DEF_LOG("del "+this->data);}
  MACRO_WEAK_PROC(on_move,(),()){DEF_LOG("mov "+this->data);}
#include "macro_scope.inl"
public:
 ~UniqueData(){if(*this){on_free();}}
  UniqueData(){}
  UniqueData(data_t&&data){this->data=data;on_init();}
  UniqueData(UniqueData&&_Right){oper_set(std::move(_Right));}
  void operator=(UniqueData&&_Right){oper_set(std::move(_Right));}
  void oper_set(UniqueData&&_Right){printf("mov %s[%p->%p]\n",_Right.data.c_str(),&_Right,this);data=std::move(_Right.data);_Right.data=data_t();}
public:
  data_t data;
  operator bool(){return !data.empty();}
};*/
class UniqueID{
private:
  static int GetID(){static int SysID=0;return ++SysID;}
private:
  void operator=(const UniqueID&){QapAssert(0);};
  UniqueID(const UniqueID&){QapAssert(0);};
public:
  void on_init(){weak_on_init<0>();};
  ;template<int>void weak_on_init(){;}
  void on_free(){weak_on_free<0>();};
  ;template<int>void weak_on_free(){;}
  void on_move(int from,int to){weak_on_move<0>(from,to);};
  ;template<int>void weak_on_move(int from,int to){;}
public:                                                                                
 ~UniqueID(){on_free();}
  UniqueID(){id=GetID();on_init();}
  UniqueID(UniqueID&&_Right){oper_set(std::move(_Right));}
  void operator=(UniqueID&&_Right){oper_set(std::move(_Right));}
  void oper_set(UniqueID&&_Right){on_move(_Right.id,id);}
public:
  int id;
  typedef UniqueID SelfClass;
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      string Name="UniqueID";
      TTypeStruct*Info=nullptr;
      if(RTTI.Register<SelfClass>(Info,Name)){
        return Info;
      }else{
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      RTTI.OnRegEnd(Info);
      return Info;
    }
  };
};
template<typename TYPE>class TServerPtr;
class TProduct;
class TRTTIProduct;
class IAllocator;
template<typename TYPE>
class TClientPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TClientPtr<TYPE>&){QapAssert(0);};  
  TClientPtr<TYPE>(const TClientPtr<TYPE>&){QapAssert(0);};    
public:
  void init(){TServerPtr<TYPE>::init_client(this);};
  void free(){TServerPtr<TYPE>::free_client(this);};
  void oper_set(TServerPtr<TYPE>*p)
  {
    if(ptr)ptr->Off(this);if(p)p->On(this);
  };
  void oper_set(TClientPtr<TYPE>&&_Right)
  {
    UID=std::move(_Right.UID);
    if(ptr)ptr->Off(this);
    if(_Right){_Right.ptr->On(this);
    _Right.ptr->Off(&_Right);}
  };
public:
  TServerPtr<TYPE>*ptr;
  UniqueID UID;
  TClientPtr<TYPE>*next;
  TClientPtr<TYPE>*prev;
 ~TClientPtr(){free();}
  TClientPtr(){init();}
  TClientPtr(TServerPtr<TYPE>*p){init();oper_set(p);}
  TClientPtr(TClientPtr<TYPE>&&_Right){init();oper_set(std::move(_Right));}
  void operator=(TServerPtr<TYPE>*p){oper_set(p);}
  void operator=(TClientPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  operator bool()const{return ptr;}
};
template<typename TYPE>
class THardClientPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const THardClientPtr<TYPE>&){QapAssert(0);};  
  THardClientPtr<TYPE>(const THardClientPtr<TYPE>&){QapAssert(0);};    
public:
  void init(){TServerPtr<TYPE>::init_client(this);};
  void free(){TServerPtr<TYPE>::free_client(this);};
  void oper_set(TServerPtr<TYPE>*p)
  {
    if(ptr)ptr->Off(this);if(p)p->On(this);
  };
  void oper_set(THardClientPtr<TYPE>&&_Right)
  {
    UID=std::move(_Right.UID);
    if(ptr)ptr->Off(this);
    if(_Right){_Right.ptr->On(this);
    _Right.ptr->Off(&_Right);}
  };
public:
  TServerPtr<TYPE>*ptr;
  UniqueID UID;
  THardClientPtr<TYPE>*next;
  THardClientPtr<TYPE>*prev;
 ~THardClientPtr(){free();}
  THardClientPtr(){init();}
  THardClientPtr(TServerPtr<TYPE>*p){init();oper_set(p);}
  THardClientPtr(THardClientPtr<TYPE>&&_Right){init();oper_set(std::move(_Right));}
  void operator=(TServerPtr<TYPE>*p){oper_set(p);}
  void operator=(THardClientPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  operator bool()const{return ptr;}
};
template<typename TYPE>
class TServerPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TServerPtr<TYPE>&){QapAssert(0);};
  TServerPtr(const TServerPtr<TYPE>&){QapAssert(0);};
private:
  template<class U>
  static void unsafe_init_client(U*p){p->ptr=nullptr;p->next=nullptr;p->prev=nullptr;};
  template<class U>
  static void unsafe_free_client(U*p){if(p->ptr){p->ptr->Off(p);}};
public:
  static void init_client(TClientPtr<TYPE>*p){unsafe_init_client(p);};
  static void free_client(TClientPtr<TYPE>*p){unsafe_free_client(p);};
  static void init_client(THardClientPtr<TYPE>*p){unsafe_init_client(p);};
  static void free_client(THardClientPtr<TYPE>*p){unsafe_free_client(p);};
public:
  ptr_t*ptr;
  UniqueID UID;
  int SaveID;
  int RefCount;
  TClientPtr<TYPE> entry_point;
  int HardCount;
  THardClientPtr<TYPE> hard_point;
  ~TServerPtr(){if(entry_point||hard_point){serv_off();}free();}
  TServerPtr(){init();}
  TServerPtr(ptr_t*p){init();oper_set(p);}
  TServerPtr(TServerPtr<TYPE>&&_Right){init();oper_set(std::move(_Right));}
public:
  void operator=(ptr_t*p){oper_set(p);}
  void operator=(TServerPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
public:
  void oper_set(ptr_t*p){
    if(p==ptr)return;
    serv_off();serv_on(p);
  }
  void oper_set(TServerPtr<TYPE>&&_Right){
    serv_off();
    serv_on(_Right.ptr);
    _Right.ForEach(&_Right.entry_point,redirect(this));
    _Right.ForEach(&_Right.hard_point,redirect(this));
    _Right.serv_off();
    entry_point.UID=std::move(_Right.entry_point.UID);
    UID=std::move(_Right.UID);
  }
private:
  void init(){ptr=nullptr;RefCount=0;HardCount=0;SaveID=0;}
  void free(){ptr=nullptr;}
  ptr_t*get()const{return ptr;}
  void serv_off()
  {
    QapAssert(!SaveID);
    if(hard_point)
    {
      QapAssert(1==HardCount);
      hard_point=nullptr;
    };
    if(entry_point)
    {
      ForEach(&entry_point,Unmount);
      ptr=nullptr;
      entry_point=nullptr;
    }
    QapAssert(!ptr);
  }
  void serv_on(ptr_t*p)
  {
    ptr=p;
    On(&entry_point);
    On(&hard_point);
  }
  static void unsafe_insert_me(TClientPtr<TYPE>*p){
    p->next->prev=p;
    p->prev->next=p;
  }
  static void unsafe_remove_me(TClientPtr<TYPE>*p){
    p->next->prev=p->prev;
    p->prev->next=p->next;
  }
  static void unsafe_insert_me(THardClientPtr<TYPE>*p){
    p->next->prev=p;
    p->prev->next=p;
  }
  static void unsafe_remove_me(THardClientPtr<TYPE>*p){
    p->next->prev=p->prev;
    p->prev->next=p->next;
  }
public:
  void On(TClientPtr<TYPE>*p){_On(p);}
  void Off(TClientPtr<TYPE>*p){_Off(p);}
  void On(THardClientPtr<TYPE>*p){_On(p);}
  void Off(THardClientPtr<TYPE>*p){_Off(p);}
private:
  template<class U,bool flag>struct Hidden;
  template<class U>
  struct Hidden<U,true>{
    static int&get_counter(TServerPtr<TYPE>*self){return self->RefCount;}
    static U&get_point(TServerPtr<TYPE>*self){return self->entry_point;}
  };
  template<class U>
  struct Hidden<U,false>{
    static int&get_counter(TServerPtr<TYPE>*self){return self->HardCount;}
    static U&get_point(TServerPtr<TYPE>*self){return self->hard_point;}
  };
  template<template<class> class T,class U>
  int&get_counter(T<U>*)
  {
    return Hidden<T<U>,std::is_same<T<U>,TClientPtr<U>>::value>::get_counter(this);
  }
  template<template<class> class T,class U>
  T<U>&get_point(T<U>*)
  {
    return Hidden<T<U>,std::is_same<T<U>,TClientPtr<U>>::value>::get_point(this);
  }
  template<class U>
  void _On(U*p){
    auto&point=get_point(p);
    auto&counter=get_counter(p);
    QapAssert(p);
    QapAssert(!p->ptr);
    p->ptr=this;
    if(p==&point){
      p->next=p;
      p->prev=p;
    }else{
      QapAssert(point);
      p->next=point.next;
      p->prev=&point;
      unsafe_insert_me(p);
    }
    counter++;
  }
  template<class U>
  void _Off(U*p){
    auto&point=get_point(p);
    auto&counter=get_counter(p);
    QapAssert(p);
    QapAssert(p->ptr);
    unsafe_remove_me(p);
    p->ptr=nullptr;
    p->next=nullptr;
    p->prev=nullptr;
    counter--;
  }
public:
  operator bool()const{return ptr;};
private:
  static void Unmount(TClientPtr<TYPE>*&it){auto*next=it->next;*it=nullptr;it=next;}
  class redirect{
  public:
    TServerPtr<TYPE>*target;
    redirect(TServerPtr<TYPE>*target):target(target){}
    void operator()(TClientPtr<TYPE>*&it){
      auto*next=it->next;
      *it=target;
      it=next;
    }
    void operator()(THardClientPtr<TYPE>*&it){
      auto*next=it->next;
      *it=target;
      it=next;
    }
  };
  template<typename U,typename FUNCTOR>
  void ForEach(U*scope,FUNCTOR&func){
    auto&point=get_point(scope);
    if(!point)return;
	  U*it=point.next;
    while(it!=&point)func(it);
  }
};
template<typename TYPE>
class UberInit{
public:
  TRTTIProduct Product;
public:
  template<class QAP_RTTI>
  UberInit(QAP_RTTI&RTTI){
    Product.pType=Sys$$<TYPE>::GetRTTI(RTTI);
    if(!Product.pType)
    {
      int breakpoint=true;
      QapAssert(Product.pType);
    }
  }
  UberInit(UberInit<TYPE>&&_Right)
  {
    QapDebugMsg("good!");
    this->Product=std::move(_Right.Product);
    int gg=0;
  }
  ~UberInit()
  {
    QapAssert(!Product.Memory.ptr);
    QapAssert(!Product.pType);
    Product.pType=nullptr;
  }
};
template<class TYPE>
class TAutoPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TAutoPtr<TYPE>&Ref){QapAssert(0);}
  TAutoPtr(const TAutoPtr<TYPE>&Ref){QapAssert(0);}
public:
  TRTTIProduct Product;
  TAutoPtr():Product(){}
  TAutoPtr(std::nullptr_t):Product(){oper_set(nullptr);}
  TAutoPtr(TAutoPtr<TYPE>&&_Right):Product(){oper_set(std::move(_Right));}
  TAutoPtr(UberInit<TYPE>&Ref):Product(){oper_set(Ref);}
  template<class U>TAutoPtr(TAutoPtr<U>&&_Right):Product(){oper_set<U>(std::move(_Right));}
  template<class U>TAutoPtr(UberInit<U>&Ref):Product(){oper_set<U>(Ref);}
public:
  template<class U,class QAP_RTTI>
  U*build(QAP_RTTI&RTTI)
  {
    IEnvRTTI&Env=RTTI;
    oper_set(UberInit<U>(Env));
    return (U*)get();
  }
  void*unsafe_build(TType*pType)
  {
    this->Off();
    Product.pType=pType;
    Product.Init();
    return get();
  }
public:
  void oper_set(const nullptr_t&){Off();}
  void oper_set(TAutoPtr<TYPE>&&_Right){this->Off();Product=std::move(_Right.Product);}
  void oper_set(UberInit<TYPE>&Ref){Off();On(Ref.Product);}
public:
  template<class U>
  void oper_set(TAutoPtr<U>&&_Right)
  {
    static_assert(std::is_base_of<TYPE,U>::value,"fail");
    this->Off();
    Product=std::move(_Right.Product);
  }
  template<class U>
  void oper_set(UberInit<U>&Ref){TryInit<U,std::is_base_of<TYPE,U>::value>::Do(this,&Ref);}
public:
  void operator=(const nullptr_t&){oper_set(nullptr);}
  void operator=(TAutoPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  void operator=(UberInit<TYPE>&Ref){oper_set(Ref);}
  template<class U>
  void operator=(UberInit<U>&Ref){oper_set<U>(Ref);}
private:
  void On(TRTTIProduct&A){
    QapAssert(!A);
    QapAssert(!Product);
    Product=std::move(A);
    Product.Init();
  }
  void Off(){
    if(!Product.Memory.ptr)return;
    Product.Free();
    Product.pType=nullptr;
  }
public:
  TYPE*get()const{return (TYPE*)Product.Memory.ptr;}
  TYPE*operator->()const{return get();}
  operator bool()const{return Product.Memory.ptr;}
public:
  template<class U,bool flag=true>
  struct TryInit{
    static void Do(TAutoPtr<TYPE>*Self,UberInit<U>*Ref){Self->Off();Self->On(Ref->Product);}
  };
  template<class U>struct TryInit<U,false>{static void Do(...){static_assert(false,"U is not based on TYPE");}};
};
template<class TYPE>
class TSelfPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TSelfPtr<TYPE>&Ref)=delete;
  TSelfPtr(const TSelfPtr<TYPE>&Ref)=delete;
private:
  typename TServerPtr<TYPE>::ptr_t*get(){return (TServerPtr<TYPE>::ptr_t*)get(this);}
  static TYPE*get(TSelfPtr<TYPE>*ptr)
  {
    static const int field_offset=int(&(((TYPE*)nullptr)->*(&TYPE::Self)));
    return (TYPE*)(void*)(int(ptr)-field_offset);
  }
public:
  TServerPtr<TYPE> P;
  TSelfPtr(){P=get();}
  ~TSelfPtr(){}
  TYPE*operator->()const{return get();}
  operator bool()const{return P;}
public:
  TSelfPtr(TSelfPtr<TYPE>&&_Right){
    operator=(std::move(_Right));
  }
  void operator=(TSelfPtr<TYPE>&&_Right){
    if(&_Right==this)return;
    this->P=std::move(_Right.P);
    _Right.P=_Right.get();
    P.ptr=get();
  }
};
template<class TYPE>
class TWeakPtr{
public:
  typedef TYPE ptr_t;
public:
  TClientPtr<TYPE> P;
  TWeakPtr():P(){}
  TWeakPtr(TWeakPtr<TYPE>&&Ref):P(){oper_set(std::move(Ref));}
  TWeakPtr(const TWeakPtr<TYPE>&Ref):P(){oper_set(Ref);}
  TWeakPtr(TYPE*A):P(){oper_set(A);}
  TWeakPtr(const nullptr_t&):P(){oper_set(nullptr);}
  template<class U>
  TWeakPtr(const UberInit<U>&Ref){static_assert(0,"epic fail");}
  template<class U>
  TWeakPtr(U*A):P(){oper_set<U>(A);}
  template<class U>
  TWeakPtr(const TWeakPtr<U>&Ref):P(){oper_set<U>(Ref);}
public:
  void oper_set(TWeakPtr<TYPE>&&Ref){
    this->P=Ref?Ref.P.ptr:nullptr;
    Ref.P=nullptr;
  }
  void oper_set(const TWeakPtr<TYPE>&Ref){if(&Ref==this)return;P=Ref.P.ptr;}
  void oper_set(TYPE*A){
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<TYPE,true,true>::Do_Raw(this,A);
  }
  void oper_set(const nullptr_t&){P=nullptr;}
  template<class U>
  void oper_set(U*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Raw(this,A);
  }
  template<class U>
  void oper_set(const TWeakPtr<U>&Ref)
  {
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Weak(this,&Ref);
  }
public:
  void operator=(TWeakPtr<TYPE>&&ref){oper_set(std::move(ref));}
  void operator=(const TWeakPtr<TYPE>&Ref){oper_set(Ref);}
  void operator=(TYPE*A){oper_set(A);}
  void operator=(const nullptr_t&){oper_set(nullptr);}
  template<class U>
  void operator=(const UberInit<U>&Ref){static_assert(0,"epic fail");}
  template<class U>
  void operator=(U*A){oper_set<U>(A);}
  template<class U>
  void operator=(const TWeakPtr<U>&Ref){oper_set<U>(Ref);}
public:
  TYPE*get()const{return P?(TYPE*)P.ptr->ptr:nullptr;}
  TYPE*operator->()const{return get();}
  operator bool()const{return P;}
public:
  template<class U,bool dir,bool indir>
  struct TryInit
  {
    static void Do_Raw(...){static_assert(0,"under construction");}
  };
  template<class U,bool indir>
  struct TryInit<U,true,indir>{
    static void Do_Raw(TWeakPtr<TYPE>*Self,U*Source)
    {
      Self->P=Source?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Weak(TWeakPtr<TYPE>*Self,const TWeakPtr<U>*Source)
    {
      QapDebugMsg("bug detected");
      Self->P=*Source?Source->P.ptr:nullptr;
    }
  };
  template<class U>
  struct TryInit<U,false,true>
  {
    static void Do_Raw(TWeakPtr<TYPE>*Self,U*Source)
    {
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      static_assert(0,"nax");
      U*tmp=Source;
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=Source&&!skip?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
  };
};
template<class TYPE>
class THardPtr{
public:
  typedef TYPE ptr_t;
public:
  THardClientPtr<TYPE> P;
  THardPtr():P(){}
  THardPtr(const THardPtr<TYPE>&Ref):P(){oper_set(Ref);}
  THardPtr(THardPtr<TYPE>&&Ref):P(){oper_set(std::move(Ref));}
  THardPtr(TYPE*A):P(){oper_set(A);}
  THardPtr(const nullptr_t&):P(){oper_set(nullptr);}
  template<class U>
  THardPtr(const UberInit<U>&Ref){static_assert(0,"from constant, you are sure?");}
  template<class U>
  THardPtr(U*A):P(){oper_set<U>(A);}
  template<class U>
  THardPtr(const THardPtr<U>&Ref):P(){oper_set<U>(Ref);}
public:
  void oper_set(const THardPtr<TYPE>&Ref){if(&Ref==this)return;P=Ref.P.ptr;}
  void oper_set(TYPE*A){
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<TYPE,true,true>::Do_Raw(this,A);
  }
  void oper_set(const nullptr_t&){P=nullptr;}
  template<class U>
  void oper_set(U*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Raw(this,A);
  }
  template<class U>
  void oper_set(const THardPtr<U>&Ref)
  {
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Hrd(this,&Ref);
  }
  void oper_set(THardPtr<TYPE>&&Ref)
  {
    this->P=Ref?Ref.P.ptr:nullptr;
    Ref.P=nullptr;
  }
public:
  void operator=(THardPtr<TYPE>&&Ref){oper_set(std::move(Ref));}
  void operator=(const THardPtr<TYPE>&Ref){oper_set(Ref);}
  void operator=(TYPE*A){oper_set(A);}
  void operator=(const nullptr_t&){oper_set(nullptr);}
  template<class U>
  void operator=(const UberInit<U>&Ref){static_assert(0,"from constant, you are sure?");}
  template<class U>
  void operator=(U*A){oper_set<U>(A);}
  template<class U>
  void operator=(THardPtr<U>&Ref){oper_set<U>(Ref);}
public:
  TYPE*get()const{return P?(TYPE*)P.ptr->ptr:nullptr;}
  TYPE*operator->()const{return get();}
  operator bool()const{return P;}
public:
  template<class U,bool dir,bool indir>
  struct TryInit
  {
    static void Do_Raw(...){static_assert(0,"under construction");}
    static void Do_Hrd(...){static_assert(0,"under construction");}
  };
  template<class U,bool indir>
  struct TryInit<U,true,indir>{
    static void Do_Raw(THardPtr<TYPE>*Self,U*Source)
    {
      Self->P=Source?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Hrd(THardPtr<TYPE>*Self,const THardPtr<U>*Source)
    {
      QapDebugMsg("bug detected");
      Self->P=*Source?Source->P.ptr:nullptr;
    }
  };
  template<class U>
  struct TryInit<U,false,true>
  {
    static void Do_Raw(THardPtr<TYPE>*Self,U*Source)
    {
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      static_assert(0,"nax");
      U*tmp=Source;
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=Source&&!skip?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Hrd(THardPtr<TYPE>*Self,THardPtr<U>*Source)
    {
      static_assert(0,"under construction");
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      U*tmp=Source->get();
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=*Source&&!skip?&Source->P:nullptr;
    }
  };
};
class IBinIO{
public:
  public:typedef IBinIO SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    IBinIO(const IBinIO&)=delete;IBinIO(){DoReset();};
  public:
    IBinIO(IBinIO&&_Right){operator=(std::move(_Right));}
    void operator=(IBinIO&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IBinIO";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IBinIO";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  virtual void Save(QapIO&IO,void*p){QapDebugMsg("no way.");}
  virtual void Load(QapIO&IO,void*p){QapDebugMsg("no way.");}
public:
  virtual void Copy(void*pOut,void*pInp){QapDebugMsg("no way.");}
  virtual bool IsSame(void*pA,void*pB){QapDebugMsg("no way.");return *(bool*)nullptr;}
public:
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
public:
  ~IBinIO(){}
};
class ITxtIO{
public:
  public:typedef ITxtIO SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    ITxtIO(const ITxtIO&)=delete;ITxtIO(){DoReset();};
  public:
    ITxtIO(ITxtIO&&_Right){operator=(std::move(_Right));}
    void operator=(ITxtIO&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="ITxtIO";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "ITxtIO";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  virtual void Save(string&s,void*p){QapDebugMsg("no way.");}
  virtual void Load(string&s,void*p){QapDebugMsg("no way.");}
public:
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
public:
  ~ITxtIO(){}
};
template<class TYPE>
class TBinIO:public IBinIO{
public:
  typedef IBinIO ParentClass;
  typedef typename TYPE type;
  typedef typename TBinIO<TYPE> SelfClass;
public:
  void Save(QapIO&IO,void*p){
    IO.SavePOD(p,sizeof(type));
  }
  void Load(QapIO&IO,void*p){
    IO.LoadPOD(p,sizeof(type));
  }
public:
  void Copy(void*pOut,void*pInp){
    TYPE&out=*(TYPE*)pOut;
    TYPE&inp=*(TYPE*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB){
    TYPE&a=*(TYPE*)pA;
    TYPE&b=*(TYPE*)pB;
    return a==b;
  }
};
template<class TYPE>
class TTxtIO:public TBinIO<TYPE>{
public:
  typedef void SelfClass;
public:
  virtual void Save(string&s,void*p){static_assert(false,"not ready");}
  virtual void Load(string&s,void*p){static_assert(false,"not ready");}
};
template<class TYPE>
class THeadBinIO:public TBinIO<TYPE>{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<ParentClass>::GetRTTI(Env);};
public:
  static THeadBinIO<TYPE>*Get(){
    static THeadBinIO<TYPE>tmp;
    static bool flag=true;
    if(flag){
      THeadBinIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<class TYPE>
class THeadCppIO:public TTxtIO<TYPE>{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<ParentClass>::GetRTTI(Env);};
public:
  static THeadCppIO<TYPE>*Get(){
    static THeadCppIO<TYPE>tmp;
    static bool flag=true;
    if(flag){
      THeadCppIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<>
class THeadBinIO<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<IBinIO>>&GetArr(){
    static vector<TWeakPtr<IBinIO>> tmp; return tmp;
  }
};
template<>
class THeadCppIO<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<ITxtIO>>&GetArr(){
    static vector<TWeakPtr<ITxtIO>> tmp; return tmp;
  }
};
class IVectorAPI{
public:
  public:typedef IVectorAPI SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    IVectorAPI(const IVectorAPI&)=delete;IVectorAPI(){DoReset();};
  public:
    IVectorAPI(IVectorAPI&&_Right){operator=(std::move(_Right));}
    void operator=(IVectorAPI&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IVectorAPI";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IVectorAPI";
      }
    };
  public:
public:
  typedef int SizeType;
  ~IVectorAPI(){}
  virtual SizeType GetCount(void*p){QapDebugMsg("no way.");return 0;}
  virtual void SetCount(void*p,SizeType c){QapDebugMsg("no way.");}
  virtual void*GetItem(void*p,SizeType i){QapDebugMsg("no way.");return nullptr;}
public:
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
};
template<class TYPE>
class TVectorAPI:public IVectorAPI{
public:
  typedef typename TYPE type;
  typedef IVectorAPI ParentClass;
  typedef TVectorAPI<type> SelfClass;
public:
  virtual SizeType GetCount(void*p){vector<TYPE>&v=*(vector<TYPE>*)p;return v.size();}
  virtual void SetCount(void*p,SizeType c){vector<TYPE>&v=*(vector<TYPE>*)p;v.resize(c);}
  virtual void*GetItem(void*p,SizeType i){vector<TYPE>&v=*(vector<TYPE>*)p;return &v[i];}
public:
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("What does this code mean?");
    return nullptr;
  };
public:
  static TVectorAPI<TYPE>*Get(){
    static TVectorAPI<TYPE>tmp;
    static bool flag=true;
    if(flag){
      TVectorAPI<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};
template<>
class TVectorAPI<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<IVectorAPI>>&GetArr(){
    static vector<TWeakPtr<IVectorAPI>> tmp; return tmp;
  }
};
struct noused_t{noused_t(nullptr_t){}};
class EnvType;
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
/*TMemory - дискриптор выделеной памяти*/
class TMemory{
public:
  struct ptr_t{};
  ptr_t*ptr;
  int size;
  TMemory():ptr(nullptr),size(0){}
  operator bool()const
  {
    QapAssert(bool(ptr)==bool(size));
    return ptr;
  }
  void operator=(nullptr_t){ptr=nullptr;size=0;}
  void operator=(TMemory&&_Right){
    ptr=_Right.ptr;
    _Right.ptr=nullptr;
    size=_Right.size;
    _Right.size=0;
  }
};
/*IProduct - дискриптор продукта(динамически объект)*/
class IProduct{
public:
  public:typedef IProduct SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    IProduct(const IProduct&)=delete;IProduct(){DoReset();};
  public:
    IProduct(IProduct&&_Right){operator=(std::move(_Right));}
    void operator=(IProduct&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IProduct";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IProduct";
      }
    };
  public:
public:
  virtual void safe_free()
  {
    if(bool(*this))Free();
  }
public:
  virtual const TMemory&GetMemory()const{QapDebugMsg("no way.");return *(TMemory*)nullptr;}
  virtual TMemory&GetMemory(){QapDebugMsg("no way.");return *(TMemory*)nullptr;}
  virtual IAllocator*GetAlloc(){QapDebugMsg("no way.");return nullptr;}
  virtual IFactory*GetFactory(){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetType(){QapDebugMsg("no way.");return nullptr;}
public:
  void Init(){weak_Init<0>();};
  ;template<int>void weak_Init()
  {
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(!Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Init(pAlloc,Memory);
  }
  struct{};
  void Free(){weak_Free<0>();};
  ;template<int>void weak_Free()
  {
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Free(pAlloc,Memory);
    QapAssert(!Memory);
  }
  operator bool()const{return bool(GetMemory());}
};
/*TProduct - дискриптор продукта(динамически объект)*/
class TProduct:public IProduct{
public:
  public:typedef TProduct SelfClass;public:typedef IProduct ParentClass;
  public:
  TMemory Memory;
  THardPtr<IAllocator> Alloc;
  THardPtr<IFactory> Factory;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Memory);detail::FieldTryDoReset(this->Alloc);detail::FieldTryDoReset(this->Factory);
    }
  public:
    TProduct(const TProduct&)=delete;TProduct(){DoReset();};
  public:
    TProduct(TProduct&&_Right){operator=(std::move(_Right));}
    void operator=(TProduct&&_Right)
    {
      struct hidden{static void foo(IProduct(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        IProduct::operator=(std::move(_Right));
      }
  this->Memory=std::move(_Right.Memory);
  this->Alloc=std::move(_Right.Alloc);
  this->Factory=std::move(_Right.Factory);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TProduct";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TMemory>::GetRTTI(RTTI),"Memory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Memory))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IAllocator>>::GetRTTI(RTTI),"Alloc",int(&(((SelfClass*)nullptr)->*(&SelfClass::Alloc))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TProduct";
      }
    };
  public:
public:
  const TMemory&GetMemory()const{return Memory;}
  TMemory&GetMemory(){return Memory;}
  IAllocator*GetAlloc(){return Alloc.get();}
  IFactory*GetFactory(){return Factory.get();}
  TType*GetType(){return nullptr;}
public:
  ~TProduct(){safe_free();}
};
/*TProduct - дискриптор продукта(динамически объект)*/
class TRTTIProduct:public IProduct{
public:
  public:typedef TRTTIProduct SelfClass;public:typedef IProduct ParentClass;
  public:
  TMemory Memory;
  THardPtr<TType> pType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Memory);detail::FieldTryDoReset(this->pType);
    }
  public:
    TRTTIProduct(const TRTTIProduct&)=delete;TRTTIProduct(){DoReset();};
  public:
    TRTTIProduct(TRTTIProduct&&_Right){operator=(std::move(_Right));}
    void operator=(TRTTIProduct&&_Right)
    {
      struct hidden{static void foo(IProduct(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        IProduct::operator=(std::move(_Right));
      }
  this->Memory=std::move(_Right.Memory);
  this->pType=std::move(_Right.pType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TRTTIProduct";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TMemory>::GetRTTI(RTTI),"Memory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Memory))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TRTTIProduct";
      }
    };
  public:
public:
  const TMemory&GetMemory()const{return Memory;}
  TMemory&GetMemory(){return Memory;}
  IAllocator* GetAlloc(){return weak_GetAlloc<0>();};
  ;template<int>IAllocator* weak_GetAlloc(){return pType->GetAlloc();}
  IFactory* GetFactory(){return weak_GetFactory<0>();};
  ;template<int>IFactory* weak_GetFactory(){return pType->Factory.get();}
  TType* GetType(){return weak_GetType<0>();};
  ;template<int>TType* weak_GetType(){return pType.get();}
public:
  ~TRTTIProduct(){safe_free();}
};
/*IFactory - завод объектов*/
class IFactory{
public:
  public:typedef IFactory SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    IFactory(const IFactory&)=delete;IFactory(){DoReset();};
  public:
    IFactory(IFactory&&_Right){operator=(std::move(_Right));}
    void operator=(IFactory&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IFactory";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IFactory";
      }
    };
  public:
public:
  ~IFactory(){}
public:
  void operator=(const IFactory&)=delete;
public:
  virtual void Init(IAllocator*pAlloc,TMemory&){QapDebugMsg("no way.");}
  virtual void Free(IAllocator*pAlloc,TMemory&){QapDebugMsg("no way.");}
public:
  virtual string GetElementTypeFullName()const{QapDebugMsg("no way.");return "";}
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
public:
  virtual int GetSize(){QapDebugMsg("no way.");return 0;}
  virtual void UnsafeInit(const TMemory&){QapDebugMsg("no way.");}
  virtual void UnsafeFree(const TMemory&){QapDebugMsg("no way.");}
  virtual void UnsafeMove(const TMemory&Dest,const TMemory&Source){QapDebugMsg("no way.");}
public:
  virtual void unlink(){};
};
/*IAllocator - владелец пузыря памяти*/
class IAllocator{
public:
  public:typedef IAllocator SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    IAllocator(const IAllocator&)=delete;IAllocator(){DoReset();};
  public:
    IAllocator(IAllocator&&_Right){operator=(std::move(_Right));}
    void operator=(IAllocator&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IAllocator";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IAllocator";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  virtual void Alloc(TMemory&){QapDebugMsg("no way.");};
  virtual void Dealloc(TMemory&){QapDebugMsg("no way.");};
public:
  class TMemInfo;
  virtual TMemInfo&GetMemInfo(){QapDebugMsg("no way.");return *(TMemInfo*)nullptr;}
public:
  class TMemInfo{
  public:
  public:typedef IAllocator OwnerClass;
  public:typedef TMemInfo SelfClass;
  public:
   int AllocCount;
    int DeallocCount;
    int MemoryUsed;
    public:
    void DoReset()
    {
      {
      }
   (this->AllocCount)=(0); (this->DeallocCount)=(0); (this->MemoryUsed)=(0); 
    }
  public:
    TMemInfo(const TMemInfo&)=delete;TMemInfo(){DoReset();};
  public:
    TMemInfo(TMemInfo&&_Right){operator=(std::move(_Right));}
    void operator=(TMemInfo&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->AllocCount=std::move(_Right.AllocCount);
    this->DeallocCount=std::move(_Right.DeallocCount);
    this->MemoryUsed=std::move(_Right.MemoryUsed);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TMemInfo";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"AllocCount",int(&(((SelfClass*)nullptr)->*(&SelfClass::AllocCount))),"SET","0");
    Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"DeallocCount",int(&(((SelfClass*)nullptr)->*(&SelfClass::DeallocCount))),"SET","0");
    Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"MemoryUsed",int(&(((SelfClass*)nullptr)->*(&SelfClass::MemoryUsed))),"SET","0");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TMemInfo";
      }
    };
  public:
  public:
    ~TMemInfo()
    {
      QapAssert(AllocCount==DeallocCount);
      QapAssert(!MemoryUsed);
    }
  public:
    inline void OnAlloc(TMemory&Mem){
      AllocCount++;
      MemoryUsed+=Mem.size;
    }
    inline void OnDealloc(TMemory&Mem){
      DeallocCount++;
      MemoryUsed-=Mem.size;
    }
  };
};
template<typename PARAM,typename TYPE>
void UberReset(PARAM*Param,TYPE&Ref){
  detail::Reset<PARAM,TYPE,detail::is_dynamic<PARAM,TYPE>::value>::Do(Param,Ref);
}
bool TDynStructFactory_set_not_sys_field_from_string(TType*p,const string&source,void*pValue);
class TDynStructFactory:public IFactory{
public:
  public:typedef TDynStructFactory SelfClass;public:typedef IFactory ParentClass;
  public:
  THardPtr<TTypeStruct> pType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->pType);
    }
  public:
    TDynStructFactory(const TDynStructFactory&)=delete;TDynStructFactory(){DoReset();};
  public:
    TDynStructFactory(TDynStructFactory&&_Right){operator=(std::move(_Right));}
    void operator=(TDynStructFactory&&_Right)
    {
      struct hidden{static void foo(IFactory(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        IFactory::operator=(std::move(_Right));
      }
  this->pType=std::move(_Right.pType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TDynStructFactory";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TTypeStruct>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TDynStructFactory";
      }
    };
  public:
public:
  struct ptr_t{};
public:
  template<class TYPE>
  void Move(TYPE*pd,TYPE*ps)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if(subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)(void*)pd;
      dMem.size=subtype->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)(void*)ps;
      sMem.size=subtype->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
    auto&arr=type->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)ex.getValue(pd);
      dMem.size=ty->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)ex.getValue(ps);
      sMem.size=ty->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
  }
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if(subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeInit(Mem);
    }
    auto&arr=type->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeInit(Mem);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.Mode!="SET")continue;
      void*p=ex.getValue(ptr);
      string&value=ex.Value;
      auto*fieldtype=TTypeSys::UberCast(ex.Type.get());
      if(fieldtype)
      {
        auto*txtio=fieldtype->TxtIO.get();
        txtio->Load(value,p);
      }else{
        auto*pcommontype=ex.Type.get();
        bool ok=TDynStructFactory_set_not_sys_field_from_string(pcommontype,value,p);
        if(!ok)
        {
          string msg=(
            "the type use SET mode with no sys type:\n"+pcommontype->GetFullName()+"\n\n"
            "and TDynStructFactory_set_not_sys_field_from_string return false"
          );
          QapDebugMsg(msg);
        }
        int gg=1;
      }
      int gg=1;
    }
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    auto&arr=type->Members;
    for(int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeFree(Mem);
    }
    if(subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeFree(Mem);
    }
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create<ptr_t>(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy<ptr_t>(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  template<class TYPE>
  int weak_GetSize()
  {
    return pType->Info.Size;
  }
  int GetSize()
  {
    return weak_GetSize<void>();
  }
  void UnsafeInit(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Create<ptr_t>(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Destroy<ptr_t>(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source){
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    Move<ptr_t>(get(Dest.ptr),get(Source.ptr));
  }
public:
  void unlink(){pType=nullptr;};
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if(!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }
  TType*GetElementType(IEnvRTTI&Env){
    return weak_GetElementType(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env){
    QapDebugMsg("[2014.08.23]: it used?");
    return nullptr;
  }
public:
  static inline ptr_t*get(TMemory::ptr_t*ptr){return (ptr_t*)(void*)ptr;}
};
class TDynSelfPtrFactory:public IFactory{
public:
  public:typedef TDynSelfPtrFactory SelfClass;public:typedef IFactory ParentClass;
  public:
  THardPtr<TTypeSelfPtr> pType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->pType);
    }
  public:
    TDynSelfPtrFactory(const TDynSelfPtrFactory&)=delete;TDynSelfPtrFactory(){DoReset();};
  public:
    TDynSelfPtrFactory(TDynSelfPtrFactory&&_Right){operator=(std::move(_Right));}
    void operator=(TDynSelfPtrFactory&&_Right)
    {
      struct hidden{static void foo(IFactory(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        IFactory::operator=(std::move(_Right));
      }
  this->pType=std::move(_Right.pType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TDynSelfPtrFactory";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TTypeSelfPtr>>::GetRTTI(RTTI),"pType",int(&(((SelfClass*)nullptr)->*(&SelfClass::pType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TDynSelfPtrFactory";
      }
    };
  public:
public:
  struct ptr_t{};
public:
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    QapAssert(type);
    auto*elemtype=TTypeStruct::UberCast(type->ElementType.get());
    auto&self=*elemtype->GetNearSelf();
    QapAssert(&self);
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    new(pSelfPtr) TSelfPtr<IEsoteric>;
    pSelfPtr->P=nullptr;
    IEsoteric*p=(IEsoteric*)(void*)(int(pSelfPtr)-self.Offset);
    pSelfPtr->P=p;
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    pSelfPtr->~TSelfPtr<IEsoteric>();
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create<ptr_t>(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy<ptr_t>(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  template<class TYPE>
  TYPE weak_GetSize()
  {
    return sizeof(TSelfPtr<IEsoteric>);
  }
  int GetSize()
  {
    return weak_GetSize<int>();
  }
  void UnsafeInit(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Create<ptr_t>(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Destroy<ptr_t>(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source){
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    QapDebugMsg("no way");
  }
public:
  void unlink(){pType=nullptr;};
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if(!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }
  TType*GetElementType(IEnvRTTI&Env){
    return weak_GetElementType(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("[2014.08.23]: it used?");
    return nullptr;
  };
public:
  static inline ptr_t*get(TMemory::ptr_t*ptr){return (ptr_t*)(void*)ptr;}
};
template<class TYPE>
class TFactory:public IFactory{
public:
  typedef typename TFactory<TYPE> SelfClass;
  typedef IFactory ParentClass;
  typedef TYPE type;
public:
  void operator=(const TFactory<TYPE>&Ref)=delete;
public:
  void operator=(TFactory<TYPE>&&Ref)
  {
    this->Self=std::move(Ref.Self);
  }
public:
  static TFactory<TYPE>*Get(){
    static TFactory<TYPE>tmp;
    static bool flag=true;
    if(flag){
      TFactory<void>::GetFactorys().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
public:
  static void Create(TYPE*ptr){new(ptr) TYPE;detail::FieldTryDoReset(*ptr);}
  static void Destroy(TYPE*ptr){ptr->~TYPE();}
  template<class T>
  static void Move(T&dest,T&source)
  {
    dest=std::move(source);
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=sizeof(TYPE);
    pAlloc->Alloc(Mem);
    Create(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  int GetSize(){
    return sizeof(TYPE);
  }
  void UnsafeInit(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Create(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Destroy(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source){
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    auto*pd=get(Dest.ptr);
    auto*ps=get(Source.ptr);
    Move<type>(*pd,*ps);
  }
public:
  string GetElementTypeFullName()const{return std::move(Sys$$<type>::GetFullName());}
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<SelfClass>::GetRTTI(Env);};
private:
  static inline TYPE*get(TMemory::ptr_t*ptr){return (TYPE*)(void*)ptr;}
};
template<>
class TFactory<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<IFactory>>&GetFactorys(){
    static vector<TWeakPtr<IFactory>> tmp; return tmp;
  }
};
/*
class TAllocator:public IAllocator{
public:
  TMemInfo Info;
  uchar Blob[1024*256];
  int cur;
  TAllocator():cur(0){}
public:
  void Alloc(TProduct&P)
  {
    P.Memory.ptr=(TMemory::ptr_t*)&Blob[cur];
    cur+=P.Memory.size;
    Info.OnAlloc(P);
  }
  void Dealloc(TProduct&P)
  {
    Info.OnDealloc(P);
    memset(P.Memory.ptr,0,P.Memory.size);
    P.Memory.ptr=nullptr;
    P.Memory.size=0;
  }
  TMemInfo&GetMemInfo(){return Info;}
};
*/
class TStdAllocator:public IAllocator{
public:
  public:typedef TStdAllocator SelfClass;public:typedef IAllocator ParentClass;
  public:
   TMemInfo Info;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
   detail::FieldTryDoReset(this->Info); 
    }
  public:
    TStdAllocator(const TStdAllocator&)=delete;TStdAllocator(){DoReset();};
  public:
    TStdAllocator(TStdAllocator&&_Right){operator=(std::move(_Right));}
    void operator=(TStdAllocator&&_Right)
    {
      struct hidden{static void foo(IAllocator(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        IAllocator::operator=(std::move(_Right));
      }
   this->Info=std::move(_Right.Info);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TStdAllocator";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
   Info->AddMemberDEF(Sys$$<TMemInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TStdAllocator";
      }
    };
  public:
public:
  void Alloc(TMemory&Mem)
  {
    Mem.ptr=(TMemory::ptr_t*)new uchar[Mem.size];
    Info.OnAlloc(Mem);
  }
  void Dealloc(TMemory&Mem)
  {
    Info.OnDealloc(Mem);
    memset(Mem.ptr,0,Mem.size);
    delete[] (uchar*)Mem.ptr;
    Mem.ptr=nullptr;
  }
  TMemInfo&GetMemInfo(){return Info;}
};
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
class TRTTIProduct;
template<class TYPE>
class RTTIManager{
public:
  typedef std::pair<TWeakPtr<IEnvRTTI>,TWeakPtr<TType>> elem;
  vector<elem> Arr;
public:
  static RTTIManager<TYPE>*Get(){static RTTIManager<TYPE> global;return &global;}
public:
  elem*FindEnv(IEnvRTTI*Env)
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto&EX=Arr[i];
      auto*ptr=EX.first.get();
      if(ptr==Env)return &EX;
    }
    return nullptr;
  }
  template<class U>
  bool GetPleaseInfo(IEnvRTTI*Env,U*(&val))
  {
    {U*u=nullptr;TType*t=nullptr;t=u;}
    elem*el=FindEnv(Env);
    val=(U*)(el?el->second.get():nullptr);
    return el;
  }
  template<class U>
  void SetPleaseInfo(IEnvRTTI*Env,U*val)
  {
    elem*el=FindEnv(Env);
    if(!el)
    {
      Arr.push_back(std::move(elem(Env,val)));
      if(Arr.size()>1)
      {
        QapDebugMsg("over 1 IEnvRTTI instance detected!");
      }
      return;
    }
    el->first=Env;
    el->second=val;
    return;
  }
};
template<class TYPE>
bool QapCanDestroy(TAutoPtr<TYPE>&Ref)
{
  return Ref&&Ref->Self.P.HardCount==1;
}
class EnvType{
public:
  public:typedef EnvType SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  TAutoPtr<TType> Type;
  TAutoPtr<IFactory> Factory;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Type);detail::FieldTryDoReset(this->Factory);
    }
  public:
    EnvType(const EnvType&)=delete;EnvType(){DoReset();};
  public:
    EnvType(EnvType&&_Right){operator=(std::move(_Right));}
    void operator=(EnvType&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Type=std::move(_Right.Type);
  this->Factory=std::move(_Right.Factory);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="EnvType";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "EnvType";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  bool CheckFactory(){return weak_CheckFactory<0>();};
  ;template<int>bool weak_CheckFactory()
  {
    if(Factory)
    {
      QapAssert(Type);
      return Type->Factory.get()==Factory.get();
    }
    if(!Factory)
    {
      QapAssert(Type&&Type->Factory);
      return true;
    }
    return false;
  }
public:
};
class IEnvRTTI{
public:
  public:typedef IEnvRTTI SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    IEnvRTTI(const IEnvRTTI&)=delete;IEnvRTTI(){DoReset();};
  public:
    IEnvRTTI(IEnvRTTI&&_Right){operator=(std::move(_Right));}
    void operator=(IEnvRTTI&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IEnvRTTI";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IEnvRTTI";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  virtual IAllocator*GetAlloc(){QapDebugMsg("no way");return nullptr;}
  virtual int RegInfo(TAutoPtr<TType>&&_Right){QapDebugMsg("no way");return 0;}
  virtual EnvType&GetEnvTypeById(int id){QapDebugMsg("no way");return *(EnvType*)nullptr;}
  virtual vector<EnvType>&GetArr(){QapDebugMsg("no way");return *(vector<EnvType>*)nullptr;}
  virtual void OnRegBeg(TType*Info){QapDebugMsg("no way");}
  virtual void OnRegRet(TType*Info){QapDebugMsg("no way");}
  virtual void OnRegEnd(TType*Info){QapDebugMsg("no way");}
  virtual IEnvRTTI*GetOwnerEnv(){QapDebugMsg("no way");return nullptr;}
public:
  template<int>
  struct template_detail{
    static bool campare_type_full_name(TType*pType,const string&fn)
    {
      return pType->GetFullName()==fn;
    }
  };
  struct TTypeFullNameComparator{
    const string&fn;
    TTypeFullNameComparator(const string&fn):fn(fn){}
    bool operator()(EnvType&ex){
      return template_detail<0>::campare_type_full_name(ex.Type.get(),fn);
    }
  };
public:
  TType*FindTypeByName_is_ug_but_work(const string&fn)
  {
    auto&types=GetArr();
    auto&arr=qap_find(types,TTypeFullNameComparator(fn));
    QapAssert(arr.size()<=1);
    if(arr.empty())return nullptr;
    return types[arr[0]].Type.get();
  }
  TType*FindTypeByFactory(IFactory*pFactory)
  {
    return weak_FindTypeByFactory<void>(pFactory);
  }
  template<class TYPE>
  TType*weak_FindTypeByFactory(IFactory*pFactory)
  {
    if(!pFactory)return nullptr;
    auto&arr=GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if(pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
public:
  bool IsRootEnv()
  {
    return GetOwnerEnv()==this;
  }
  IEnvRTTI*GetRootEnv()
  {
    IEnvRTTI*pEnv=this;
    while(pEnv)
    {
      auto*p=pEnv->GetOwnerEnv();
      if(p==pEnv)return pEnv;
      pEnv=p;
    }
    QapDebugMsg("WTF?");
    return nullptr;
  }
public:
  template<class REG_TYPE,class INFO_TYPE>
  bool Register(INFO_TYPE*(&Info),const string&Name)
  {
    typedef RTTIManager<REG_TYPE> ManType;
    static_assert(std::is_base_of<TType,INFO_TYPE>::value,"bad");
    if(true)
    {
      auto*RootEnv=GetRootEnv();
      if(RootEnv!=this)
      {
        bool flag=RootEnv->Register<REG_TYPE>(Info,Name);
        TType*pType=Info;
        pType=FindTypeByFactory(pType->Factory.get());
        if(!flag)QapAssert(!pType);
        if(!pType)
        {
          QapDebugMsg("type '"+Sys$$<REG_TYPE>::GetFullName()+"' - not found");
        }
        Info=(INFO_TYPE*)pType;
        return true;
      }
    }
    ManType*Man=ManType::Get();
    Man->GetPleaseInfo(this,Info);
    if(Info){
      if(false)OnRegRet(Info);
      return true;
    }else{
      {
        TProduct prod;
        prod.Alloc=GetAlloc();
        prod.Factory=TFactory<INFO_TYPE>::Get();
        prod.Init();
        Info=(INFO_TYPE*)prod.Memory.ptr;
        Man->SetPleaseInfo(this,Info);
        Info->Info.Name=Name;
        Info->Info.Size=sizeof(REG_TYPE);
        Info->Info.Align=detail::QapAlignOf<REG_TYPE>::value;
        this->OnRegBeg(Info);
        {
          TAutoPtr<INFO_TYPE> tmp;
          tmp.Product.Memory=std::move(prod.Memory);
          int id=RegInfo(std::move(tmp));
          TType*pType=Sys$$<INFO_TYPE>::GetRTTI(*this);
          GetEnvTypeById(id).Type.Product.pType=pType;
        }
        __if_exists(INFO_TYPE::extInfo){
          Info->extInfo.SpecInfo=detail::GetSpecInfo<REG_TYPE>();
          Info->extInfo.Polymorph=std::is_polymorphic<REG_TYPE>::value;
          Info->extInfo.Abstract=std::is_abstract<REG_TYPE>::value;
        }
      }
      typedef detail::select<std::is_abstract<REG_TYPE>::value,void,REG_TYPE>::type select;
      Info->Factory=TFactory<select>::Get();
      Info->Env=this;
      return false;
    }
  }
};
#pragma once
class TTypeInfo{
public:
  public:typedef TTypeInfo SelfClass;
  public:
  string Name;
  int Size;
  int Align;
    public:
    void DoReset()
    {
      {
      }
  (this->Name)=("unnamed");(this->Size)=(0);(this->Align)=(0);
    }
  public:
    TTypeInfo(const TTypeInfo&)=delete;TTypeInfo(){DoReset();};
  public:
    TTypeInfo(TTypeInfo&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeInfo&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Name=std::move(_Right.Name);
  this->Size=std::move(_Right.Size);
  this->Align=std::move(_Right.Align);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeInfo";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Align",int(&(((SelfClass*)nullptr)->*(&SelfClass::Align))),"SET","0");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeInfo";
      }
    };
  public:
public:
};
class TType{
public:
  public:typedef TType SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  THardPtr<IEnvRTTI> Env;
  THardPtr<IFactory> Factory;
  TTypeInfo Info;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Env);detail::FieldTryDoReset(this->Factory);detail::FieldTryDoReset(this->Info);
    }
  public:
    TType(const TType&)=delete;TType(){DoReset();};
  public:
    TType(TType&&_Right){operator=(std::move(_Right));}
    void operator=(TType&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Env=std::move(_Right.Env);
  this->Factory=std::move(_Right.Factory);
  this->Info=std::move(_Right.Info);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TType";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IEnvRTTI>>::GetRTTI(RTTI),"Env",int(&(((SelfClass*)nullptr)->*(&SelfClass::Env))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IFactory>>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TTypeInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TType";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  virtual void Use(IVisitorRTTI&){QapDebugMsg("no way.");}
  virtual string GetFullName(){return Info.Name;}
  virtual TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<SelfClass>::GetRTTI(Env);};
  virtual TType*GetSubType()const{return nullptr;}
  bool ready()const{return Env&&Env->GetAlloc()&&Factory;}
  IAllocator*GetAlloc(){return Env?Env->GetAlloc():nullptr;}
  bool CanDestroy()const{return 1==Self.P.HardCount;}
public:
  bool IsBasedOn(TType*A)const{
    if(this==A)return true;
    TType*subtype=this->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};
class TTypeSys:public TType{
public:
  public:typedef TTypeSys SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<IBinIO> BinIO;
  THardPtr<ITxtIO> TxtIO;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->BinIO);detail::FieldTryDoReset(this->TxtIO);
    }
  public:
    TTypeSys(const TTypeSys&)=delete;TTypeSys(){DoReset();};
  public:
    TTypeSys(TTypeSys&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeSys&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->BinIO=std::move(_Right.BinIO);
  this->TxtIO=std::move(_Right.TxtIO);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeSys";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<IBinIO>>::GetRTTI(RTTI),"BinIO",int(&(((SelfClass*)nullptr)->*(&SelfClass::BinIO))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<ITxtIO>>::GetRTTI(RTTI),"TxtIO",int(&(((SelfClass*)nullptr)->*(&SelfClass::TxtIO))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeSys";
      }
    };
  public:
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  ~TTypeSys()
  {
    if(BinIO||TxtIO)
    {
      QapDebugMsg("bad idea");
    }
    BinIO=nullptr;
    TxtIO=nullptr;
  }
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeVector:public TType{
public:
  public:typedef TTypeVector SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> SizeType;
  THardPtr<TType> ElementType;
  THardPtr<IVectorAPI> VecAPI;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->SizeType);detail::FieldTryDoReset(this->ElementType);detail::FieldTryDoReset(this->VecAPI);
    }
  public:
    TTypeVector(const TTypeVector&)=delete;TTypeVector(){DoReset();};
  public:
    TTypeVector(TTypeVector&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeVector&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->SizeType=std::move(_Right.SizeType);
  this->ElementType=std::move(_Right.ElementType);
  this->VecAPI=std::move(_Right.VecAPI);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeVector";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SizeType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SizeType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IVectorAPI>>::GetRTTI(RTTI),"VecAPI",int(&(((SelfClass*)nullptr)->*(&SelfClass::VecAPI))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeVector";
      }
    };
  public:
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeArray:public TType{
public:
  public:typedef TTypeArray SelfClass;public:typedef TType ParentClass;
  public:
  int Size;
  THardPtr<TType> ElementType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  (this->Size)=(0);detail::FieldTryDoReset(this->ElementType);
    }
  public:
    TTypeArray(const TTypeArray&)=delete;TTypeArray(){DoReset();};
  public:
    TTypeArray(TTypeArray&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeArray&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->Size=std::move(_Right.Size);
  this->ElementType=std::move(_Right.ElementType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeArray";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeArray";
      }
    };
  public:
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+","+IToS(Size)+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeFactory:public TType{
public:
  public:typedef TTypeFactory SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> ElementType;
  THardPtr<TType> SubType;
  THardPtr<TType> SmartType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);detail::FieldTryDoReset(this->SubType);detail::FieldTryDoReset(this->SmartType);
    }
  public:
    TTypeFactory(const TTypeFactory&)=delete;TTypeFactory(){DoReset();};
  public:
    TTypeFactory(TTypeFactory&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeFactory&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
  this->SubType=std::move(_Right.SubType);
  this->SmartType=std::move(_Right.SmartType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeFactory";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SmartType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SmartType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeFactory";
      }
    };
  public:
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
  TType*GetSubType()const{return SubType?SubType.get():nullptr;}
};
class IEsoteric;
class QapSysMember{
public:
  public:typedef QapSysMember SelfClass;
  public:
  string Name;
  THardPtr<TType> Type;
    public:
    void DoReset()
    {
      {
      }
  (this->Name)=("unnamed");detail::FieldTryDoReset(this->Type);
    }
  public:
    QapSysMember(const QapSysMember&)=delete;QapSysMember(){DoReset();};
  public:
    QapSysMember(QapSysMember&&_Right){operator=(std::move(_Right));}
    void operator=(QapSysMember&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Name=std::move(_Right.Name);
  this->Type=std::move(_Right.Type);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapSysMember";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapSysMember";
      }
    };
  public:
public:
  void set(const string&Name,TType*Type)
  {
    this->Name=Name;
    this->Type=Type;
  }
};
class TTypeSelfPtr:public TType{
public:
  public:typedef TTypeSelfPtr SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> ElementType;
  QapSysMember mSaveID;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);detail::FieldTryDoReset(this->mSaveID);
    }
  public:
    TTypeSelfPtr(const TTypeSelfPtr&)=delete;TTypeSelfPtr(){DoReset();};
  public:
    TTypeSelfPtr(TTypeSelfPtr&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeSelfPtr&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
  this->mSaveID=std::move(_Right.mSaveID);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeSelfPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeSelfPtr";
      }
    };
  public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
  {
    typedef mSaveIDType ResultType;
    typedef TServerPtr<IEsoteric> ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
    );
  }
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  typedef TDynSelfPtrFactory TDynamicFactory;
};
class TTypeAutoPtr:public TType{
public:
  public:typedef TTypeAutoPtr SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> ElementType;
  QapSysMember mType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);detail::FieldTryDoReset(this->mType);
    }
  public:
    TTypeAutoPtr(const TTypeAutoPtr&)=delete;TTypeAutoPtr(){DoReset();};
  public:
    TTypeAutoPtr(TTypeAutoPtr&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeAutoPtr&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
  this->mType=std::move(_Right.mType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeAutoPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeAutoPtr";
      }
    };
  public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TRTTIProduct mProductType;
  {
    typedef mProductType ResultType;
    typedef TAutoPtr<IEsoteric> ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::Product))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mProductType""\" != \"""TAutoPtr<IEsoteric>"":"":""Product""\""
    );
  }
    {}
    typedef THardPtr<TType> mProduct_pTypeType;
  {
    typedef mProduct_pTypeType ResultType;
    typedef mProductType ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::pType))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mProduct_pTypeType""\" != \"""mProductType"":"":""pType""\""
    );
  }
    {}
    mType.set("Product.pType",Sys$$<mProduct_pTypeType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeWeakPtr:public TType{
public:
  public:typedef TTypeWeakPtr SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> ElementType;
  QapSysMember mSaveID;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);detail::FieldTryDoReset(this->mSaveID);
    }
  public:
    TTypeWeakPtr(const TTypeWeakPtr&)=delete;TTypeWeakPtr(){DoReset();};
  public:
    TTypeWeakPtr(TTypeWeakPtr&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeWeakPtr&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
  this->mSaveID=std::move(_Right.mSaveID);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeWeakPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeWeakPtr";
      }
    };
  public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
  {
    typedef mSaveIDType ResultType;
    typedef TServerPtr<IEsoteric> ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
    );
  }
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeHardPtr:public TType{
public:
  public:typedef TTypeHardPtr SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> ElementType;
  QapSysMember mSaveID;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);detail::FieldTryDoReset(this->mSaveID);
    }
  public:
    TTypeHardPtr(const TTypeHardPtr&)=delete;TTypeHardPtr(){DoReset();};
  public:
    TTypeHardPtr(TTypeHardPtr&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeHardPtr&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
  this->mSaveID=std::move(_Right.mSaveID);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeHardPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mSaveID",int(&(((SelfClass*)nullptr)->*(&SelfClass::mSaveID))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeHardPtr";
      }
    };
  public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
  {
    typedef mSaveIDType ResultType;
    typedef TServerPtr<IEsoteric> ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::SaveID))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mSaveIDType""\" != \"""TServerPtr<IEsoteric>"":"":""SaveID""\""
    );
  }
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeVoidPtr:public TType{
public:
  public:typedef TTypeVoidPtr SelfClass;public:typedef TType ParentClass;
  public:
  QapSysMember mType;
  QapSysMember mPtr;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->mType);detail::FieldTryDoReset(this->mPtr);
    }
  public:
    TTypeVoidPtr(const TTypeVoidPtr&)=delete;TTypeVoidPtr(){DoReset();};
  public:
    TTypeVoidPtr(TTypeVoidPtr&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeVoidPtr&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->mType=std::move(_Right.mType);
  this->mPtr=std::move(_Right.mPtr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeVoidPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mPtr",int(&(((SelfClass*)nullptr)->*(&SelfClass::mPtr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeVoidPtr";
      }
    };
  public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef THardPtr<TType> mTypeType;
  {
    typedef mTypeType ResultType;
    typedef TVoidPtr ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::type))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mTypeType""\" != \"""TVoidPtr"":"":""type""\""
    );
  }
    {}
    typedef TWeakPtr<IEsoteric> mPtrType;
  {
    typedef mPtrType ResultType;
    typedef TVoidPtr ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::ptr))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mPtrType""\" != \"""TVoidPtr"":"":""ptr""\""
    );
  }
    {}
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mPtr.set("ptr",Sys$$<mPtrType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetFullName(){return Info.Name;}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TVoidPtr;
class TTypeFieldPtr:public TType{
public:
  public:typedef TTypeFieldPtr SelfClass;public:typedef TType ParentClass;
  public:
  QapSysMember mObject;
  QapSysMember mType;
  QapSysMember mOffset;
  QapSysMember mIndex;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->mObject);detail::FieldTryDoReset(this->mType);detail::FieldTryDoReset(this->mOffset);detail::FieldTryDoReset(this->mIndex);
    }
  public:
    TTypeFieldPtr(const TTypeFieldPtr&)=delete;TTypeFieldPtr(){DoReset();};
  public:
    TTypeFieldPtr(TTypeFieldPtr&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeFieldPtr&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->mObject=std::move(_Right.mObject);
  this->mType=std::move(_Right.mType);
  this->mOffset=std::move(_Right.mOffset);
  this->mIndex=std::move(_Right.mIndex);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeFieldPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mObject",int(&(((SelfClass*)nullptr)->*(&SelfClass::mObject))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mType",int(&(((SelfClass*)nullptr)->*(&SelfClass::mType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mOffset",int(&(((SelfClass*)nullptr)->*(&SelfClass::mOffset))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapSysMember>::GetRTTI(RTTI),"mIndex",int(&(((SelfClass*)nullptr)->*(&SelfClass::mIndex))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeFieldPtr";
      }
    };
  public:
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TVoidPtr mObjectType;
  {
    typedef mObjectType ResultType;
    typedef TFieldPtr ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::object))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mObjectType""\" != \"""TFieldPtr"":"":""object""\""
    );
  }
    {}
    typedef THardPtr<TType> mTypeType;
  {
    typedef mTypeType ResultType;
    typedef TFieldPtr ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::type))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mTypeType""\" != \"""TFieldPtr"":"":""type""\""
    );
  }
    {}
    typedef int mOffsetType;
  {
    typedef mOffsetType ResultType;
    typedef TFieldPtr ClassType;
    typedef decltype((((ClassType*)nullptr)->*(&ClassType::offset))) realtype;
    typedef std::remove_reference<realtype>::type fieldtype;
    static_assert(std::is_same<ResultType,fieldtype>::value,
      "\"""mOffsetType""\" != \"""TFieldPtr"":"":""offset""\""
    );
  }
    {}
    mObject.set("object",Sys$$<mObjectType>::GetRTTI(Env));
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mOffset.set("offset",Sys$$<mOffsetType>::GetRTTI(Env));
    {}
    mIndex.set("index",Sys$$<int>::GetRTTI(Env));
  }
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetFullName(){return Info.Name;}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class TTypeStruct:public TType{
public:
  class Member{
  public:
  public:typedef TTypeStruct OwnerClass;
  public:typedef Member SelfClass;
  public:
   string Name;
    int Offset;
    THardPtr<TType> Type;
    string Mode;
    string Value;
    public:
    void DoReset()
    {
      {
      }
   (this->Name)=("unnamed"); (this->Offset)=(0); detail::FieldTryDoReset(this->Type); detail::FieldTryDoReset(this->Mode); detail::FieldTryDoReset(this->Value); 
    }
  public:
    Member(const Member&)=delete;Member(){DoReset();};
  public:
    Member(Member&&_Right){operator=(std::move(_Right));}
    void operator=(Member&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->Name=std::move(_Right.Name);
    this->Offset=std::move(_Right.Offset);
    this->Type=std::move(_Right.Type);
    this->Mode=std::move(_Right.Mode);
    this->Value=std::move(_Right.Value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="Member";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
    Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Offset",int(&(((SelfClass*)nullptr)->*(&SelfClass::Offset))),"SET","0");
    Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
    Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mode))),"DEF","$");
    Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Value",int(&(((SelfClass*)nullptr)->*(&SelfClass::Value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "Member";
      }
    };
  public:
  public:
    void*getValue(void*pValue)
    {
      return (void*)(Offset+int(pValue));
    }
  };
  class TExtInfo{
  public:
  public:typedef TTypeStruct OwnerClass;
  public:typedef TExtInfo SelfClass;
  public:
   int SelfId;
    string SpecInfo;
    bool Polymorph;
    bool Abstract;
    bool PoorDesign;
    public:
    void DoReset()
    {
      {
      }
   (this->SelfId)=(-1); detail::FieldTryDoReset(this->SpecInfo); (this->Polymorph)=(false); (this->Abstract)=(false); (this->PoorDesign)=(false); 
    }
  public:
    TExtInfo(const TExtInfo&)=delete;TExtInfo(){DoReset();};
  public:
    TExtInfo(TExtInfo&&_Right){operator=(std::move(_Right));}
    void operator=(TExtInfo&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->SelfId=std::move(_Right.SelfId);
    this->SpecInfo=std::move(_Right.SpecInfo);
    this->Polymorph=std::move(_Right.Polymorph);
    this->Abstract=std::move(_Right.Abstract);
    this->PoorDesign=std::move(_Right.PoorDesign);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TExtInfo";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"SelfId",int(&(((SelfClass*)nullptr)->*(&SelfClass::SelfId))),"SET","-1");
    Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"SpecInfo",int(&(((SelfClass*)nullptr)->*(&SelfClass::SpecInfo))),"DEF","$");
    Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Polymorph",int(&(((SelfClass*)nullptr)->*(&SelfClass::Polymorph))),"SET","false");
    Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Abstract",int(&(((SelfClass*)nullptr)->*(&SelfClass::Abstract))),"SET","false");
    Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"PoorDesign",int(&(((SelfClass*)nullptr)->*(&SelfClass::PoorDesign))),"SET","false");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TExtInfo";
      }
    };
  public:
  public:
  };
public:
  public:typedef TTypeStruct SelfClass;public:typedef TType ParentClass;
  public:
  THardPtr<TType> SubType;
  THardPtr<TType> OwnType;
  vector<Member> Members;
  vector<THardPtr<TType>> Nesteds;
  TExtInfo extInfo;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->SubType);detail::FieldTryDoReset(this->OwnType);detail::FieldTryDoReset(this->Members);detail::FieldTryDoReset(this->Nesteds);detail::FieldTryDoReset(this->extInfo);
    }
  public:
    TTypeStruct(const TTypeStruct&)=delete;TTypeStruct(){DoReset();};
  public:
    TTypeStruct(TTypeStruct&&_Right){operator=(std::move(_Right));}
    void operator=(TTypeStruct&&_Right)
    {
      struct hidden{static void foo(TType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        TType::operator=(std::move(_Right));
      }
  this->SubType=std::move(_Right.SubType);
  this->OwnType=std::move(_Right.OwnType);
  this->Members=std::move(_Right.Members);
  this->Nesteds=std::move(_Right.Nesteds);
  this->extInfo=std::move(_Right.extInfo);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TTypeStruct";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<TType>>::GetRTTI(RTTI),"OwnType",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<Member>>::GetRTTI(RTTI),"Members",int(&(((SelfClass*)nullptr)->*(&SelfClass::Members))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<THardPtr<TType>>>::GetRTTI(RTTI),"Nesteds",int(&(((SelfClass*)nullptr)->*(&SelfClass::Nesteds))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TExtInfo>::GetRTTI(RTTI),"extInfo",int(&(((SelfClass*)nullptr)->*(&SelfClass::extInfo))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<Member>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<TExtInfo>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TTypeStruct";
      }
    };
  public:
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  static string GetElementName(THardPtr<TType>&ElementType)
  {
    return std::move(ElementType?ElementType->GetFullName()+"::":"");
  }
  string GetFullName(){return std::move(GetElementName(OwnType)+Info.Name);}
public:
  string GetDebugInfo()
  {
    string fn=GetFullName();
    string code;
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      code+=(i?",":"")+ex.Name;
    }
    return fn+"={"+code+"}";
  }
public:
  bool TestField(const Member&it,int depth=0)
  {
    QapAssert((it.Mode=="DEF")||(it.Mode=="SET"));
    if(it.Mode=="DEF")do
    {
      auto*pFieldType=TTypeSys::UberCast(it.Type.get());
      if(!pFieldType)break;
      string ftfn=pFieldType->GetFullName();
      static const vector<string> white_list=split("bool|uint|int|float|real|char|uchar|string","|");
      bool white=false;
      for(int i=0;i<white_list.size();i++)
      {
        white=white||(ftfn==white_list[i]);
      }
      if(white)break;
      string fn=GetFullName();
      QapDebugMsg("field - \""+fn+"\"::"+it.Name+"\" has illegal DEF mode");
    }while(false);
    if(SubType)
    {
      auto*pSubType=TTypeStruct::UberCast(SubType.get());
      bool result=pSubType->TestField(it,depth+1);
      if(!result)return result;
    }
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int cmp_id=0;
        static string idToStr[]={"Name","Offset",};
      const int cmp_n=lenof(idToStr)-(depth?1:0);
        do{if(cmp_id<cmp_n){if(it.Name==ex.Name)break;cmp_id++;
        }if(cmp_id<cmp_n){if(it.Offset==ex.Offset)break;cmp_id++;
        };}while(false);
      if(cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        string fn=GetFullName();
        if(tmp=="Name")if(it.Name=="Self")if(fn=="QapWinProgram")continue;
        if((-1==it.Offset)&&(-1==Info.Size))continue;
        QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
        return depth;
      }
    }
    return true;
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  template<class TYPE>
  static TYPE*AddOffset(TYPE*pValue,int offset){return (TYPE*)(void*)(offset+int(pValue));}
  struct IsStruct
  {
    static Member*GetNearSelf(THardPtr<TType>&pType)
    {
      if(!pType)return nullptr;
      TType*type=pType.get();
      return GetNearSelf(type);
    }
    static Member*GetNearSelf(TType*type)
    {
      if(!type)return nullptr;
      auto*tmp=UberCast(type);
      if(!tmp){
        return GetNearSelf(type->GetSubType());
      }
      return tmp->GetNearSelf();
    }
    struct MemberIndexByOffset
    {
      struct FieldInfo{
        TTypeStruct*base;
        int index;
        Member*get()
        {
          if(!base)return nullptr;
          auto&it=base->Members[index];
          return &it;
        }
      };
      struct Input{
        TType*type;
        int offset;
        TType*fieldtype;
      };
      struct Output{
        int index;
        FieldInfo info;
      };
      static bool get(Input&in,Output&out)
      {
        auto*base=UberCast(in.type);
        string in_ft_fn=in.fieldtype->GetFullName();
        if(base)
        {
          auto&arr=base->Members;
          for(int i=0;i<arr.size();i++,out.index++)
          {
            auto&it=arr[i];
            if(it.Offset!=in.offset)
            {
              TType*mt=it.Type.get();
              int mos=in.offset-it.Offset;
              Input input={mt,mos,in.fieldtype};
              bool result=get(input,out);
              if(!result)continue;
              return result;
            }
            auto*type=it.Type.get();
            {
              string type_fn=type->GetFullName();
              string base_fn=base->GetFullName();
              in_ft_fn=in_ft_fn;
            }
            if(type==in.fieldtype)
            {
              out.info.base=base;
              out.info.index=i;
              return true;
            }else{
              TType*mt=it.Type.get();
              int mos=in.offset-it.Offset;
              Input input={mt,mos,in.fieldtype};
              bool result=get(input,out);
              if(!result)continue;
              return result;
            }
            QapDebugMsg("breakpoint");
          }
        }
        if(!base&&in.type)
        {
          TType*SubType=in.type->GetSubType();
          if(SubType)
          {
            Input input={SubType,in.offset,in.fieldtype};
            return get(input,out);
          }
        }
        return false;
      }
    };
  };
  Member*GetNearSelf()
  {
    return extInfo.SelfId<0?IsStruct::GetNearSelf(GetSubType()):&Members[extInfo.SelfId];
  }
public:
  void AddField(Member&&field)
  {
    QapAssert(field.Type);
    QapAssert(TestField(field));
    QapAssert(field.Type&&field.Type->Info.Align>0);
    if(field.Name=="Self")
    {
      if(true)do
      {
        auto*type=TTypeSelfPtr::UberCast(field.Type.get());
        QapAssert(type);
        if(this!=type->ElementType.get())
        {
          string fn=GetFullName();
          QapDebugMsg("field - \""+fn+"\"::"+field.Name+"\" has wrong type");
        }
      }while(false);
      if(GetNearSelf())do
      {
        auto*type=field.Type.get();
        auto*pSubType=TTypeStruct::UberCast(SubType.get());
        string fn=GetFullName();
        string subtype=pSubType->GetFullName();
          if("QapWinProgram"==subtype)if("eWinProgram"==fn)break;
          if("QapWinProgram"==subtype)if("QapProgramD3D9"==fn)break;
        QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
      }while(false);
      extInfo.SelfId=Members.size();
    }
    Members.push_back(std::move(field));
  }
  void AddMemberSET(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
  {
    Member tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Offset=Offset;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
  void AddMemberDEF(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
  {
    Member tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Offset=Offset;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
  void AddMemberSYS(...){}
  void AddMemberSYD(...){}
  void AddNested(TType*NestedType)
  {
    Nesteds.push_back(NestedType);
  }
public:
  static vector<string>&get_white_list()
  {
    static vector<string> arr;
    if(!arr.empty())return arr;
    string white_list[]={
      "eWindow::TForm",
      "QapKeyboard",
      "QapD3DDev9",
      "QapTexMem",
      "QapTex",
      "QapFontInfo",
      "QapDev",
      "QapResourceDetector",
      "QapTreeDebugger",
      "TDownLoader",
      "TReloadDetector",
      "T20130410_GatewayServer",
      "T20130410_ServerCallback"
    };
    for(int i=0;i<lenof(white_list);i++)
    {
      arr.push_back(white_list[i]);
    };
    return arr;
  }
  static bool find_in_white_list(const string&type_fullname)
  {
    auto&arr=get_white_list();
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i]==type_fullname)return true;
    }
    return false;
  }
  void SelfTesting()
  { 
    static string all_messages;
    if(!Members.empty())
    {
      auto&front=Members.front();
      bool bad=!SubType&&front.Offset;
      bool mute=(extInfo.Polymorph&&!SubType)&&(front.Offset==Info.Align);
      if(bad)
      {
        string fn=this->GetFullName();
        string msg="\""+fn+"\" - offset of the first field of the type is "+IToS(front.Offset);
        all_messages+=msg+"\n";
        mute=mute||find_in_white_list(fn);
        if(!mute)QapDebugMsg(msg);
      }
    }
    if(!Members.empty())
    {
      auto&back=Members.back();
      int aligned_size=getAligned(back.Offset+back.Type->Info.Size,Info.Align);
      bool bad=aligned_size!=Info.Size;
      if(bad)
      {
        string fn=this->GetFullName();
        string msg="\""+fn+"\" - size of the type is "+IToS(Info.Size)+". expected aligned_size = "+IToS(aligned_size);
        all_messages+=msg+"\n";
        bool mute=find_in_white_list(fn);
        if(!mute)QapDebugMsg(msg);
      }
    }
    if(Members.empty())
    {
      int expected_size=0;
      {
        if(!SubType){
          expected_size=1;
          if(extInfo.Polymorph)expected_size=Info.Align;
        }
        if(SubType)expected_size=SubType->Info.Size;
      }
      bool bad=expected_size!=Info.Size;
      if(bad)
      {
        string fn=this->GetFullName();
        string msg=(
          "\""+fn+"\" - size of the type is "+IToS(Info.Size)+"\n"
          "expected size: "+IToS(expected_size)+"\n"
          "PoorDesign?"
        );
        all_messages+=msg+"\n";
        bool mute=extInfo.PoorDesign||find_in_white_list(fn);
        if(!mute)QapDebugMsg(msg);
      }
    }
    if(OwnType&&!Nesteds.empty())
    {
      const string&parent=OwnType->Info.Name;
      auto&arr=Nesteds;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(parent!=ex->Info.Name)continue;
        QapDebugMsg(
          "Prohibited name of a nested type.\n"
          "parent type and one of the sub-types have equal names.\n"
          "  ParentClass: "+parent+"\n"
          "  SelfClass: "+Info.Name
        );
        *(int*)nullptr=0;
      }
    }
  }
public:
  void Calc()
  {
    QapAssert(Info.Size>0);
    QapAssert(Info.Align>0);
    auto*subtype=SubType.get();
    if(subtype)
    {
      QapAssert(subtype->Info.Size>0);
      QapAssert(subtype->Info.Align>0);
    }
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*type=ex.Type.get();
      QapAssert(type->Info.Size>0);
      QapAssert(type->Info.Align>0);
      QapAssert(ex.Offset>=0);
    }
    int gfdsq=0;
  }
  static int getAligned(int offset,int align)
  {
    QapAssert(offset>=0);
    int x=offset%align;
    return offset+(x?align-x:0);
  }
  void ReCalcMembersOffset()
  {
    int Offset=0;
    int MaxAlign=0;
    auto*subtype=SubType.get();
    if(subtype)
    {
      int Size=subtype->Info.Size;
      int Align=subtype->Info.Align;
      QapAssert(Size>0);
      QapAssert(Align>0);
      Offset=getAligned(Offset,Align);
      Offset+=Size;
      MaxAlign=max(MaxAlign,Align);
    }
    auto&arr=this->Members;
    MaxAlign=max(MaxAlign,!arr.empty()?arr[0].Type->Info.Align:1);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*type=ex.Type.get();
      int Size=type->Info.Size;
      int Align=type->Info.Align;
      QapAssert((Align>0)&&(Align<=1024));
      QapAssert(Size>0);
      QapAssert(-1==ex.Offset);
      ex.Offset=getAligned(Offset,Align);
      Offset=ex.Offset+Size;
      MaxAlign=max(MaxAlign,Align);
    }
    Info.Size=getAligned(Offset>0?Offset:1,MaxAlign);
    Info.Align=MaxAlign;
  }
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
  TType*GetSubType()const{return SubType?SubType.get():nullptr;}
  bool IsEqual(TTypeStruct*type)
  {
    if(Members.size()!=type->Members.size())return false;
    for(int i=0;i<Members.size();i++)
    {
      auto&it=Members[i];
      auto&ex=type->Members[i];
      if(it.Type.get()!=ex.Type.get())do
      {
        const int&id1=it.Type->Self.P.SaveID;
        const int&id2=ex.Type->Self.P.SaveID;
        if((id1&&id2)&&(id1==id2))break;
        return false;
      }while(false);
      int cmp_id=0;
        static string idToStr[]={"Name", "Mode",};
      static const int cmp_n=lenof(idToStr);
        do{if(it.Name!=ex.Name)break;cmp_id++;
         if(it.Mode!=ex.Mode)break;cmp_id++;
        ;}while(false);
      if(cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        QapDebugMsg("wrong "+tmp+" in "+GetFullName()+"::"+it.Name);
        return false;
      }
    }
    return true;
  }
  bool hasMember(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex){return ex.Name==name;});
    if(arr.size()>1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);return true;}
    return !arr.empty();
  }
  Member&unsafe_find_member(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex){return ex.Name==name;});
    if(arr.size()!=1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);return *(Member*)nullptr;}
    return Members[arr[0]];
  }
  Member*find_member(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex){return ex.Name==name;});
    if(arr.empty())return nullptr;
    if(arr.size()>1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);return nullptr;}
    return &Members[arr[0]];
  }
  Member*find_member_full(const string&name)
  {
    if(!SubType)return find_member(name);
    auto*pSubType=SubType.get();
    auto*p=TTypeStruct::UberCast(pSubType);
    if(!p){
      QapDebugMsg("parent of type is not struct?\n"+GetFullName());
      return nullptr;
    }
    auto*fromSub=p->find_member_full(name);
    auto*fromThis=this->find_member(name);
    if(bool(fromSub)==bool(fromThis))
    {
      QapAssert(!fromSub&&!fromThis);
      return false;
    }
    return fromSub?fromSub:fromThis;
  }
public:
  typedef TDynStructFactory TDynamicFactory;
};
class IEsoteric{
public:
  public:typedef IEsoteric SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    IEsoteric(const IEsoteric&)=delete;IEsoteric(){DoReset();};
  public:
    IEsoteric(IEsoteric&&_Right){operator=(std::move(_Right));}
    void operator=(IEsoteric&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IEsoteric";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IEsoteric";
      }
    };
  public:
public:
  static void SysHasSelf();
};
struct TRawPtr
{
  TType*pType;
  void*pValue;
  TRawPtr():pType(nullptr),pValue(nullptr){}
  TRawPtr(TType*pType,void*pValue):pType(pType),pValue(pValue){}
  template<class TYPE>
  TRawPtr(IEnvRTTI&Env,TYPE&Ref):pType(nullptr),pValue(nullptr)
  {
    set(Env,Ref);
  }
  template<class TYPE>
  TRawPtr(TAutoPtr<TYPE>&Ref)
  {
    set(Ref);
  }
  template<class TYPE>
  void set(IEnvRTTI&Env,TYPE&Ref)
  {
    pType=Sys$$<TYPE>::GetRTTI(Env);
    pValue=&Ref;
  }
  template<class TYPE>
  void set(TAutoPtr<TYPE>&Ref)
  {
    if(Ref){
      pType=Ref.Product.pType.get();
      pValue=Ref.get();
    }else{
      setZero();
    }
  }
  void set(TType*pType,void*pValue){this->pType=pType;this->pValue=pValue;}
  void setZero()
  {
    pType=nullptr;
    pValue=nullptr;
  }
  bool IsValid()
  {
    return pType&&pValue;
  }
};
class TVoidPtr{
public:
  public:typedef TVoidPtr SelfClass;
  public:
  THardPtr<TType> type;
  TWeakPtr<IEsoteric> ptr;
    public:
    void DoReset()
    {
      {
      }
  (this->type)=(nullptr);(this->ptr)=(nullptr);
    }
  public:
    TVoidPtr(const TVoidPtr&)=delete;TVoidPtr(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TVoidPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYS(0,nullptr,"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"SYS");
  Info->AddMemberSYS(0,nullptr,"ptr",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TVoidPtr";
      }
    };
  public:
public:
  operator bool()const{return bool(ptr);}
public:
  void oper_set(SelfClass&&ref){
    off();
    type=std::move(ref.type);
    ptr=std::move(ref.ptr);
  }
  void operator=(SelfClass&&ref){oper_set(std::move(ref));}
public:
public:
  void off(){type=nullptr;ptr=nullptr;}
  void operator=(const nullptr_t&null){off();}
  void mega_unsafe_connect(TType*pType,void*pValue){
    off();
    if(!pType||!pValue)return;
    auto*ex=TTypeStruct::IsStruct::GetNearSelf(pType);
    if(!ex)
    {
      string fn=pType->GetFullName();
      QapDebugMsg("field \""+fn+"::Self\" not found");
      return;
    }
    TSelfPtr<IEsoteric>*self=(TSelfPtr<IEsoteric>*)ex->getValue(pValue);
    this->ptr.P=&self->P;
    this->type=pType;
  }
  void mega_unsafe_connect(const TRawPtr&ptr){
    mega_unsafe_connect(ptr.pType,ptr.pValue);
  }
  template<class TYPE>
  void operator=(TAutoPtr<TYPE>&Ref)
  {
    off();
    if(!Ref)return;
    auto*pType=Ref.Product.pType.get();
    auto*pValue=Ref.get();
    mega_unsafe_connect(pType,pValue);
  }
};
struct SubFieldsInfo{
public:
  class OutDeviceEx{
  public:
    class TMemberID;class TSubType;
    struct IVisitor{
        virtual void Do(TMemberID*p)=0;virtual void Do(TSubType*p)=0;
    };
    struct DevCmd{virtual void Use(IVisitor&A)=0;};
    class TMemberID:public DevCmd{public:int id;TMemberID(int id):id(id){}public:void Use(IVisitor&A){A.Do(this);}};
    class TSubType:public DevCmd{public:void Use(IVisitor&A){A.Do(this);}};
    class TContext{
    public:
      DevCmd*pCmd;
    public:
      TType*pType;
      int Offset;
      const string*head;
    public:
      TContext():pCmd(nullptr),pType(nullptr),Offset(0),head(nullptr){}
    };
    class TCmdVisitor:public IVisitor{
    public:
      TContext*pContext;
    public:
      void Do(TMemberID*p)
      {
        int id=p->id;
        TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
        QapAssert(pMetaType);
        auto&ex=pMetaType->Members[id];
        pContext->Offset+=ex.Offset;
        pContext->pType=ex.Type.get();
        pContext->head=&ex.Name;
      }
      void Do(TSubType*p)
      {
        pContext->Offset=pContext->Offset;
        pContext->pType=pContext->pType->GetSubType();
        pContext->head=nullptr;
        QapAssert(pContext->pType);
      }
    };
  public:
    class TCmdOffsetVisitor:public IVisitor{
    public:
      struct TContext{
        TType*pType;
        int Offset;
      };
      TContext*pContext;
    public:
      void Do(TMemberID*p)
      {
        int id=p->id;
        TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
        QapAssert(pMetaType);
        auto&ex=pMetaType->Members[id];
        pContext->Offset+=ex.Offset;
        pContext->pType=ex.Type.get();
      }
      void Do(TSubType*p){
        pContext->pType=pContext->pType->GetSubType();
      }
    };
  public:
    TContext Context;
    vector<TContext> branch;
  public:
    void push(DevCmd*pCmd)
    {
      branch.push_back(Context);
      Context.pCmd=pCmd;
      if(pCmd)
      {
        TCmdVisitor CV;
        CV.pContext=&Context;
        pCmd->Use(CV);
      }
    }
    void pop()
    {
      Context=branch.back();
      branch.pop_back();
    }
  public:
    string GetFullFieldNameByIdFromBranch(int id)
    {
      string path;
      for(int i=id;i<branch.size();i++)
      {
        auto&ex=branch[i];
        if(ex.head)path+=*ex.head+".";
      }
      if(Context.head)
      {
        path+=*Context.head;
      }else if(!path.empty()&&(path.back()=='.')){
        path.pop_back();
      }
      return std::move(path);
    }
    int GetRelativeFieldOffsetByIdFromBranch(int id)
    {
      TType*pType=nullptr;
      {
        auto&ex=branch[id];
        pType=ex.pType;
      }
      TCmdOffsetVisitor::TContext Context={pType,0};
      TCmdOffsetVisitor COV;
      COV.pContext=&Context;
      for(int i=id+1;i<branch.size();i++)
      {
        auto&ex=branch[i];
        if(!ex.pCmd)return -1;
        ex.pCmd->Use(COV);
      }
      if(!this->Context.pCmd)
      {
        return -1;
      }
      this->Context.pCmd->Use(COV);
      return Context.Offset;
    }
  };
public:
public:
  class TOffsetVerifier:public IVisitorRTTI{
  public:
    typedef TOffsetVerifier SelfClass;
    typedef OutDeviceEx TSaveDev;
  public:
    struct ICallBack{virtual bool Do(SelfClass&V,TType*p)=0;};
  public:
    struct TFieldInfo{
      TType*pType;
      int Offset;
      void setZero()
      {
        this->Offset=0;
        this->pType=nullptr;
      }
    };
    class IndexGetter:public ICallBack{
    public:
      bool Result;
      int Index;
      const TFieldInfo&Info;
      IndexGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1){}
    public:
      bool Do(SelfClass&OV,TType*p){
        if(Result)return false;
        if(Info.Offset!=OV.Offset)return true;
        Result=bool(Info.pType==p);
        if(Result)Index=OV.Index;
        return !Result;
      }
    };
    class InfoGetter:public ICallBack{
    public:
      bool Result;
      int Index;
      TFieldInfo&Info;
      InfoGetter(TFieldInfo&Info,int Index=-1):Info(Info),Result(false),Index(Index){}
    public:
      bool Do(SelfClass&OV,TType*p){
        if(Result)return false;
        if(OV.Index!=Index)return true;
        Info.Offset=OV.Offset;
        Info.pType=p;
        Result=true;
        return !Result;
      }
    };
    class FieldNameGetter:public ICallBack{
    public:
      bool Result;
      int Index;
      string fieldname;
      const TFieldInfo&Info;
      FieldNameGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1){}
    public:
      bool Do(SelfClass&V,TType*p){
        if(Result)return false;
        if(Info.Offset!=V.Offset)return true;
        Result=bool(Info.pType==p);
        if(Result)
        {
          Index=V.Index;
          fieldname=V.dev.GetFullFieldNameByIdFromBranch(0);
        }
        return !Result;
      }
    };
  public:
    TSaveDev&dev;
    ICallBack&CB;
    int Offset;
    int&Index;
    TOffsetVerifier(TSaveDev&dev,ICallBack&CB,int Offset,int&Index):dev(dev),CB(CB),Offset(Offset),Index(Index){}
    TOffsetVerifier(SelfClass&owner,int Offset):dev(owner.dev),CB(owner.CB),Offset(Offset),Index(owner.Index){Index++;}
  public:
    void Do(TTypeStruct*p)
    {
      if(!CB.Do(*this,p))return;
      if(p->SubType)
      {
        TSaveDev::TSubType tmp;
        dev.push(&tmp);
        SelfClass next(*this,Offset);
        p->SubType->Use(next);
        dev.pop();
      }
      auto&arr=p->Members;  
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        TSaveDev::TMemberID tmp(i);
        dev.push(&tmp);
        SelfClass next(*this,Offset+ex.Offset);
        ex.Type->Use(next);
        dev.pop();
      }
    }
    void Do(TTypeSys*p)
    {
      if(!CB.Do(*this,p))return;
    }
    void Do(TTypeVector*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeArray*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeSelfPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeAutoPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeWeakPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeHardPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeVoidPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeFieldPtr*p){if(!CB.Do(*this,p))return;}
  };
public:
  typedef TOffsetVerifier::TFieldInfo TFieldInfo;
public:
public:
  static string FieldInfoToFieldName(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
  {
    typedef TOffsetVerifier::FieldNameGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TCallBack CB(Info);
    int tmp=0;
    TOffsetVerifier Visitor(dev,CB,0,tmp);
    pType->Use(Visitor);
    return CB.fieldname;
  }
public:
public:
  static int FieldInfoToIndex(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
  {
    typedef TOffsetVerifier::IndexGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TCallBack CB(Info);
    int tmp=0;
    TOffsetVerifier OV(dev,CB,0,tmp);
    pType->Use(OV);
    return CB.Index;
  }
  static TOffsetVerifier::TFieldInfo IndexToFieldInfo(TType*pType,int Index)
  {
    typedef TOffsetVerifier::InfoGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TFieldInfo Info;
    Info.setZero();
    TCallBack CB(Info,Index);
    int tmp=0;
    TOffsetVerifier OV(dev,CB,0,tmp);
    pType->Use(OV);
    return Info;
  }
public:
public:
};
class TFieldPtr{
public:
  public:typedef TFieldPtr SelfClass;
  public:
  TVoidPtr object;
  THardPtr<TType> type;
  int offset;
    public:
    void DoReset()
    {
      {
      }
  (this->object)=(nullptr);(this->type)=(nullptr);(this->offset)=(-1);
    }
  public:
    TFieldPtr(const TFieldPtr&)=delete;TFieldPtr(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TFieldPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYS(0,nullptr,"object",int(&(((SelfClass*)nullptr)->*(&SelfClass::object))),"SYS");
  Info->AddMemberSYS(0,nullptr,"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"SYS");
  Info->AddMemberSYS(0,nullptr,"offset",int(&(((SelfClass*)nullptr)->*(&SelfClass::offset))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TFieldPtr";
      }
    };
  public:
public:
  void off(){
    object=nullptr;
    type=nullptr;
    offset=-1;
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void ConnectToField(QAP_RTTI&RTTI,OBJECT_TYPE&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"bad");
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=&object;
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if(result){
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void Connect(QAP_RTTI&RTTI,TAutoPtr<OBJECT_TYPE>&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    if(!object)return;
    auto*objecttype=object.Product.pType.get();
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=object.get();
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if(result){
      this->object=object;
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE>
  void ConnectEx(QAP_RTTI&RTTI,OBJECT_TYPE&object)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"fail");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=objecttype;
    {
      string ot_fn=objecttype->GetFullName();
    }
    int offset=0;
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if(result){
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
public:
  operator bool(){return object;}
  void*getValue(){
    void*pValue=object.ptr.get();
    return TTypeStruct::AddOffset(pValue,offset);
  }
  TType*getType()
  {
    if(!object)return nullptr;
    if(!type)return nullptr;
    return type.get();
  }
public:
  struct TInfo
  {
    TTypeStruct*pType;
    void*pValue;
    TType*pFieldType;
    int Offset;
    void SetToField(TFieldPtr&Field){Field=*this;}
    operator bool()const{return pValue&&pType&&pFieldType&&(Offset>=0);}
    TInfo():pType(nullptr),pValue(nullptr),pFieldType(nullptr),Offset(-1){}
    void set(TTypeStruct*pType,void*pValue,TType*pFieldType,int Offset)
    {
      this->pType=pType;
      this->pValue=pValue;
      this->pFieldType=pFieldType;
      this->Offset=Offset;
    }
    void GrabFrom(TFieldPtr&FP)
    {
      this->pType=TTypeStruct::UberCast(FP.object.type.get());
      this->pValue=FP.object.ptr.get();
      this->pFieldType=FP.type.get();
      this->Offset=FP.offset;
    }
  };
public:
  void oper_set(SelfClass&&ref){
    off();
    object=std::move(ref.object);
    type=std::move(ref.type);
    offset=std::move(ref.offset);ref.offset=-1;
  }
  void operator=(SelfClass&&ref){oper_set(std::move(ref));}
  TFieldPtr(SelfClass&&ref){oper_set(std::move(ref));}
public:
  void operator=(const TInfo&ref)
  {
    off();
    if(!ref)return;
    bool result=IsValid(ref.pType,ref.pFieldType,ref.Offset);
    if(!result)QapDebugMsg("WTF?");
    object.mega_unsafe_connect(ref.pType,ref.pValue);
    type=ref.pFieldType;
    offset=ref.Offset;
  }
public:
  static bool IsValid(TType*pType,TType*pFieldType,int Offset)
  {
    SubFieldsInfo::TOffsetVerifier::TFieldInfo Info={pFieldType,Offset};
    return 0<=SubFieldsInfo::FieldInfoToIndex(pType,Info);
  }
};
#pragma once
const real Pi  =4.0*atan(1.0);
const real Pi2 =8.0*atan(1.0);
const real PiD2=2.0*atan(1.0);
const real PiD4=1.0*atan(1.0);
template<typename TYPE>inline TYPE Lerp(const TYPE&A,const TYPE&B,const real&v){return A+(B-A)*v;}
template<class TYPE>inline TYPE Clamp(const TYPE&v,const TYPE&a,const TYPE&b){return max(a,min(v, b));}
class vec2d{
public:
  public:typedef vec2d SelfClass;
  public:
  real x;
  real y;
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="vec2d";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<real>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","0.0");
  Info->AddMemberSET(Sys$$<real>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","0.0");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "vec2d";
      }
    };
  public:
public:
  vec2d():x(0.0),y(0.0){}
  vec2d(const real&x,const real&y):x(x),y(y){}
  vec2d(const vec2d&v):x(v.x),y(v.y){}
  void operator=(const vec2d&v){x=v.x;y=v.y;}
  vec2d operator+()const{return *this;}
  vec2d operator-()const{return vec2d(-x,-y);}
  void operator+=(const vec2d&v){x+=v.x; y+=v.y;}
  void operator-=(const vec2d&v){x-=v.x; y-=v.y;}
  void operator*=(const real&f){x*=f;y*=f;}
  void operator/=(const real&f){x/=f;y/=f;}
public:
  vec2d Rot(const vec2d&OX)const{real M=OX.Mag();return vec2d(((x*+OX.x)+(y*OX.y))/M,((x*-OX.y)+(y*OX.x))/M);}
  vec2d UnRot(const vec2d&OX)const{real M=OX.Mag();if(M==0.0f){return vec2d(0,0);};return vec2d(((x*OX.x)+(y*-OX.y))/M,((x*OX.y)+(y*+OX.x))/M);}
  vec2d Ort()const{return vec2d(-y,x);}
  vec2d Norm()const{if((x==0)&&(y==0)){return vec2d(0,0);}return vec2d(x/this->Mag(),y/this->Mag());}
  vec2d SetMag(const real&val)const{return this->Norm()*val;}
  vec2d Mul(const vec2d&v)const{return vec2d(x*v.x,y*v.y);}
  vec2d Div(const vec2d&v)const{return vec2d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y);}
  real GetAng()const{return atan2(y,x);}
  real Mag()const{return sqrt(x*x+y*y);}
  real SqrMag()const{return x*x+y*y;}
public:
  friend vec2d operator+(const vec2d&u,const vec2d&v){return vec2d(u.x+v.x,u.y+v.y);}
  friend vec2d operator-(const vec2d&u,const vec2d&v){return vec2d(u.x-v.x,u.y-v.y);}
  friend vec2d operator*(const vec2d&u,const real&v){return vec2d(u.x*v,u.y*v);}
  friend vec2d operator*(const real&u,const vec2d&v){return vec2d(u*v.x,u*v.y);}
  friend bool operator==(const vec2d&u,const vec2d&v){return (u.x==v.x)&&(u.y==v.y);}
  friend bool operator!=(const vec2d&u,const vec2d&v){return (u.x!=v.x)||(u.y!=v.y);}
public:
public:
  friend inline static real dot(const vec2d&a,const vec2d&b){return a.x*b.x+a.y*b.y;}
  friend inline static real cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
public:
};
class QapColor{
public:
  typedef uchar byte;
public:
  public:typedef QapColor SelfClass;
  public:
  uchar b;
  uchar g;
  uchar r;
  uchar a;
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapColor";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"b",int(&(((SelfClass*)nullptr)->*(&SelfClass::b))),"DEF","$");
  Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"g",int(&(((SelfClass*)nullptr)->*(&SelfClass::g))),"DEF","$");
  Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"r",int(&(((SelfClass*)nullptr)->*(&SelfClass::r))),"DEF","$");
  Info->AddMemberDEF(Sys$$<uchar>::GetRTTI(RTTI),"a",int(&(((SelfClass*)nullptr)->*(&SelfClass::a))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapColor";
      }
    };
  public:
public:
  QapColor():b(255),g(255),r(255),a(255){}
  QapColor(byte A,byte R,byte G,byte B):a(A),r(R),g(G),b(B){}
  QapColor(byte R,byte G,byte B):a(255),r(R),g(G),b(B){}
  QapColor(const QapColor& v):a(v.a),r(v.r),g(v.g),b(v.b){}
public:
  QapColor&operator=(const QapColor&v){a=v.a;r=v.r;g=v.g;b=v.b;return *this;}
  QapColor operator+()const{return *this;}
public:
  QapColor&operator*=(const QapColor&v){
    {a=Clamp(int(a)*int(v.a)/int(255),int(0),int(255));}{r=Clamp(int(r)*int(v.r)/int(255),int(0),int(255));}{g=Clamp(int(g)*int(v.g)/int(255),int(0),int(255));}{b=Clamp(int(b)*int(v.b)/int(255),int(0),int(255));}
    return *this;
  }
  QapColor&operator+=(const QapColor&v){
    {a=Clamp(int(a)+int(v.a),int(0),int(255));}{r=Clamp(int(r)+int(v.r),int(0),int(255));}{g=Clamp(int(g)+int(v.g),int(0),int(255));}{b=Clamp(int(b)+int(v.b),int(0),int(255));}
    return *this;
  }
  QapColor&operator-=(const QapColor&v){
    {a=Clamp(int(a)-int(v.a),int(0),int(255));}{r=Clamp(int(r)-int(v.r),int(0),int(255));}{g=Clamp(int(g)-int(v.g),int(0),int(255));}{b=Clamp(int(b)-int(v.b),int(0),int(255));}
    return *this;
  }
  QapColor operator*(const QapColor&v)const{
    return QapColor(int(int(a)*int(v.a))/int(255),int(int(r)*int(v.r))/int(255),int(int(g)*int(v.g))/int(255),int(int(b)*int(v.b))/int(255));
  }
  QapColor operator+(const QapColor&v)const{
    return QapColor(Clamp(int(a)+int(v.a),int(0),int(255)),Clamp(int(r)+int(v.r),int(0),int(255)),Clamp(int(g)+int(v.g),int(0),int(255)),Clamp(int(b)+int(v.b),int(0),int(255)));
  }
  QapColor operator-(const QapColor&v)const{
    return QapColor(Clamp(int(a)-int(v.a),int(0),int(255)),Clamp(int(r)-int(v.r),int(0),int(255)),Clamp(int(g)-int(v.g),int(0),int(255)),Clamp(int(b)-int(v.b),int(0),int(255)));
  }
public:
    QapColor&operator*=(real f){{b=byte(Clamp(real(b)*f,0.0,255.0));};{g=byte(Clamp(real(g)*f,0.0,255.0));};{r=byte(Clamp(real(r)*f,0.0,255.0));};return *this;}
    QapColor&operator/=(real r){real f=1.0/r;{b=byte(Clamp(real(b)*f,0.0,255.0));};{g=byte(Clamp(real(g)*f,0.0,255.0));};{r=byte(Clamp(real(r)*f,0.0,255.0));};return *this;}
public:
    QapColor(const D3DCOLOR& v){*((D3DCOLOR*)(void*)this)=v;}
    operator D3DCOLOR&()const{return *(DWORD*)this;};
public:
public:
  byte GetLuminance(){return int(int(r)+int(g)+int(b))/int(3);}
  inline static QapColor Mix(const QapColor&A,const QapColor&B,const real&t){
    real ct=Clamp(t,0.0,1.0);
    real tA=1.0-ct;
    real tB=ct;
    QapColor O;
    {O.b=byte(Clamp(real(A.b)*tA+real(B.b)*tB,0.0,255.0));}{O.g=byte(Clamp(real(A.g)*tA+real(B.g)*tB,0.0,255.0));}{O.r=byte(Clamp(real(A.r)*tA+real(B.r)*tB,0.0,255.0));}{O.a=byte(Clamp(real(A.a)*tA+real(B.a)*tB,0.0,255.0));}
    return O;
  }
  inline static QapColor HalfMix(const QapColor&A,const QapColor&B)
  {
    QapColor O;
    {O.b=(int(A.b)+int(B.b))>>1;}{O.g=(int(A.g)+int(B.g))>>1;}{O.r=(int(A.r)+int(B.r))>>1;}{O.a=(int(A.a)+int(B.a))>>1;}
    return O;
  }
};
class vec4i{
public:
  public:typedef vec4i SelfClass;
  public:
  int x;
  int y;
  int z;
  int w;
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="vec4i";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"DEF","$");
  Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"DEF","$");
  Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"z",int(&(((SelfClass*)nullptr)->*(&SelfClass::z))),"DEF","$");
  Info->AddMemberDEF(Sys$$<int>::GetRTTI(RTTI),"w",int(&(((SelfClass*)nullptr)->*(&SelfClass::w))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "vec4i";
      }
    };
  public:
public:
  vec4i():x(0),y(0),z(0),w(0){}
  vec4i(int x,int y,int z,int w):x(x),y(y),z(z),w(w){}
  vec4i(const QapColor&ref):x(ref.a),y(ref.r),z(ref.g),w(ref.b){}
  void operator+=(const vec4i&v){x+=v.x;y+=v.y;z+=v.z;w+=v.w;}
  vec4i operator*(const int&v){return vec4i(x*v,y*v,z*v,w*v);}
  vec4i operator/(const int&v){return vec4i(x/v,y/v,z/v,w/v);}
  void operator/=(const int&v){x/=v;y/=v;z/=v;w/=v;}
  void operator>>=(const int&v){x>>=v;y>>=v;z>>=v;w>>=v;}
  vec4i operator+(const vec4i&v){return vec4i(x+v.x,y+v.y,z+v.z,w+v.w);}
  QapColor unsafe_but_fast_GetColor(){
    QapAssert(x>=0&&x<256);
    QapAssert(y>=0&&y<256);
    QapAssert(z>=0&&z<256);
    QapAssert(w>=0&&w<256);
    return QapColor(x,y,z,w);
  }
};
struct vec3f{
public:
  float x,y,z;
  vec3f():x(0),y(0),z(0){}
  vec3f(float x,float y,float z):x(x),y(y),z(z){}
};
struct vec4f{
public:
  float b,g,r,a;
  vec4f():b(1.0),g(1.0),r(1.0),a(1.0){}
  vec4f(float b,float g,float r,float a):b(b),g(g),r(r),a(a){}
  vec4f(const QapColor&ref):b(ref.b/255.f),g(ref.g/255.f),r(ref.r/255.f),a(ref.a/255.f){}
  vec4f&operator+=(const vec4f&v){b+=v.b;g+=v.g;r+=v.r;a+=v.a;return *this;}
  friend vec4f operator*(const float&u,const vec4f&v){return vec4f(u*v.b,u*v.g,u*v.r,u*v.a);}
  friend vec4f operator+(const vec4f&u,const vec4f&v){return vec4f(u.b+v.b,u.g+v.g,u.r+v.r,u.a+v.a);}
  QapColor GetColor(){return QapColor(Clamp(int(a*255),int(0),int(255)),Clamp(int(r*255),int(0),int(255)),Clamp(int(g*255),int(0),int(255)),Clamp(int(b*255),int(0),int(255)));}
};
class vec2f{
public:
  public:typedef vec2f SelfClass;
  public:
  float x;
  float y;
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="vec2f";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<float>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","0.0f");
  Info->AddMemberSET(Sys$$<float>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","0.0f");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "vec2f";
      }
    };
  public:
public:
  vec2f():x(0),y(0){}
  vec2f(const vec2d&v){x=v.x;y=v.y;}
  vec2f(float x,float y):x(x),y(y){};
  void set_zero(){x=0.0f;y=0.0f;}
public:
  friend vec2f operator*(const vec2f&u,const float&v){return vec2f(u.x*v,u.y*v);}
  friend vec2f operator*(const float&u,const vec2f&v){return vec2f(u*v.x,u*v.y);}
  friend vec2f operator+(const vec2f&u,const vec2f&v){return vec2f(u.x+v.x,u.y+v.y);}
  friend vec2f operator-(const vec2f&u,const vec2f&v){return vec2f(u.x-v.x,u.y-v.y);}
public:
  void operator+=(const vec2d&v){x+=v.x;y+=v.y;}
  void operator-=(const vec2d&v){x-=v.x;y-=v.y;}
public:
  friend vec2f operator*(float u,const vec2f&v){return vec2f(u*v.x,u*v.y);}
  operator vec2d()const{return vec2d(x,y);}
};
class vec2i{
public:
  public:typedef vec2i SelfClass;
  public:
  int x;
  int y;
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="vec2i";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","0");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","0");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "vec2i";
      }
    };
  public:
public:
  vec2i():x(0),y(0){}
  vec2i(int x,int y):x(x),y(y){};
  friend vec2i operator*(int u,const vec2i&v){return vec2i(u*v.x,u*v.y);}
  friend vec2i operator*(const vec2i&v,int u){return vec2i(u*v.x,u*v.y);}
  friend vec2i operator/(const vec2i&v,int d){return vec2i(v.x/d,v.y/d);}
  friend vec2i operator+(const vec2i&u,const vec2i&v){return vec2i(u.x+v.x,u.y+v.y);}
  friend vec2i operator-(const vec2i&u,const vec2i&v){return vec2i(u.x-v.x,u.y-v.y);}
  void operator+=(const vec2i&v){x+=v.x; y+=v.y;}
  void operator-=(const vec2i&v){x-=v.x; y-=v.y;}
  vec2i Mul(const vec2i&v)const{return vec2i(x*v.x,y*v.y);}
  int SqrMag(){return x*x+y*y;}
  float Mag(){return sqrt(float(x*x+y*y));}
  vec2i abs(){return vec2i(std::abs(x),std::abs(y));}
  bool dist_less(const vec2i&point,int dist){return (point-*this).SqrMag()<dist*dist;}
  operator vec2d()const{return vec2d(x,y);}
  operator vec2f()const{return vec2f(x,y);}
  vec2i operator+()const{return vec2i(+x,+y);}
  vec2i operator-()const{return vec2i(-x,-y);}
  friend bool operator==(const vec2i&u,const vec2i&v){return (u.x==v.x)&&(u.y==v.y);}
  friend bool operator!=(const vec2i&u,const vec2i&v){return (u.x!=v.x)||(u.y!=v.y);}
};
struct Dip2i{
public:
  int a,b;
  Dip2i(int a,int b):a(a),b(b){};
  void Take(int x){a=min(a,x);b=max(b,x);}
  Dip2i Norm()const{return Dip2i(min(a,b),max(a,b));}
  int Mag()const{return b-a;}
public:
  struct Transform{
    float x,s;
    Transform(float x,float s):x(x),s(s){}
    Transform(const Dip2i&from,const Dip2i&to){s=float(to.Norm().Mag())/float(from.Norm().Mag());x=to.a-from.a;}
    float operator*(int v){return x+v*s;}
  };
};
struct rot2f
{
public:
	float s;
  float c;
	rot2f():s(0.0f),c(1.0f){}
	explicit rot2f(float ang){set(ang);}
  void set(float ang){s=sinf(ang);c=cosf(ang);}
	void set_ident(){s=0.0f;c=1.0f;}
	float GetAng()const{return std::atan2(s,c);}
	vec2f GetXAxis()const{return vec2f(+c,+s);}
	vec2f GetYAxis()const{return vec2f(-s,+c);}
public:
  friend vec2f operator*(const rot2f&q,const vec2d&v){return vec2f(q.c*v.x-q.s*v.y,q.s*v.x+q.c*v.y);}
};/*
class transform2f{
public:
	vec2f p;
	rot2f q;
	transform2f(){}
	transform2f(const vec2f&pos,const rot2f&rot):p(pos),q(rot){}
	void set_ident(){p.set_zero();q.set_ident();}
	void set(const vec2f&pos,float ang){p=pos;q.set(ang);}
public:
  friend vec2f operator*(const transform2f&T,const vec2f&v)
  {
	  float x=(+T.q.c*v.x-T.q.s*v.y)+T.p.x;
	  float y=(+T.q.s*v.x+T.q.c*v.y)+T.p.y;
	  return vec2f(x,y);
  }
};*/
class QapMat22{
public:
	vec2f col1;
  vec2f col2;
public:
	QapMat22():col1(1,0),col2(0,1){}
	QapMat22(const vec2f&c1,const vec2f&c2)
	{
		col1=c1;
		col2=c2;
	}
	QapMat22(float a11,float a12,float a21,float a22)
	{
		col1.x=a11;col1.y=a21;
		col2.x=a12;col2.y=a22;
	}
	explicit QapMat22(float ang)
	{
		float c=cosf(ang);float s=sinf(ang);
		col1.x=c; col2.x=-s;
		col1.y=s; col2.y=+c;
	}
	void set(const vec2f&c1,const vec2f&c2)
	{
		col1=c1;
		col2=c2;
	}
	void set(float ang)
	{
		float c=cosf(ang);float s=sinf(ang);
		col1.x=c; col2.x=-s;
		col1.y=s; col2.y=+c;
	}
	void set_ident()
	{
		col1.x = 1.0f; col2.x = 0.0f;
		col1.y = 0.0f; col2.y = 1.0f;
	}
	void set_zero()
	{
		col1.x = 0.0f; col2.x = 0.0f;
		col1.y = 0.0f; col2.y = 0.0f;
	}
	float GetAngle()const
	{
		return atan2(col1.y, col1.x);
	}
};
class transform2f{
public:
	vec2f p;
  QapMat22 r;
public:
	transform2f(){}
	transform2f(const vec2f&p,const QapMat22&r):p(p),r(r){}
	explicit transform2f(const vec2f&p):p(p){}
	void set_ident()
	{
    p.set_zero();
    r.set_ident();
	}
	void set(const vec2d&p,float ang)
	{
		this->p=p;
		this->r.set(ang);
	}
	float getAng()const
	{
		return atan2(r.col1.y,r.col1.x);
	}
public:
  friend vec2f operator*(const transform2f&T,const vec2f&v)
  {
    float x=(+T.r.col1.x*v.x+T.r.col2.x*v.y)+T.p.x;
	  float y=(+T.r.col1.y*v.x+T.r.col2.y*v.y)+T.p.y;
	  return vec2f(x,y);
  }
};
const vec2d vec2d_zero(0.0,0.0);
const vec2i vec2i_zero(0,0);
const vec2f vec2f_zero(0,0);
const rot2f rot2f_ident(0.0);
typedef vector<QapColor> ColorArray;
typedef ColorArray* PColorArray;
typedef vector<vec2d> PointArray;
typedef PointArray* PPointArray;
typedef vector<int> IntArray;
typedef IntArray* PIntArray;
inline transform2f MakeZoomTransform(const vec2d&zoom)
{
  transform2f tmp(vec2f_zero,QapMat22(vec2f(zoom.x,0.f),vec2f(0.f,zoom.y)));
  return tmp;
}
union TLine{
    struct{vec2d A,B;};
    struct{real ax,ay,bx,by;};
public:
  TLine(){}
  TLine(const vec2d&A,const vec2d&B):A(A),B(B){}
  TLine(const real&ax,const real&ay,const real&bx,const real&by):ax(ax),ay(ay),bx(bx),by(by){}
};
inline vec2d Vec2dEx(const real&ang,const real&mag){return vec2d(cos(ang)*mag,sin(ang)*mag);}
inline real vec2d_cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
inline int round(const real&val){return int(val>=0?val+0.5:val-0.5);}
inline vec2d PToV(const POINT&v){return vec2d(v.x,v.y);}
class TSpaceDependsTools;
class DeclareEnvRTTI;
class TServerPtrSpace;
class DeclareType;
class DeclareTypeStruct;
class DeclareTypeSys;
struct TwoDeclareMetaType{
  DeclareType*pdTType;
  DeclareType*pdDeclareType;
  TwoDeclareMetaType():pdTType(nullptr),pdDeclareType(nullptr){}
};
template<class VOID_TYPE>
struct TDeclareEnvRTTI_WeakDetail
{
public:
  typedef TServerPtrSpace TSpace;
  static void GrabFrom(DeclareEnvRTTI&Dest,DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt)
  {
    auto&arr=Source.Arr;
    auto&out=Dest.Arr;
    QapAssert(out.empty());
    out.reserve(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      const auto&ex_SaveID=ex->Self.P.SaveID;
      bool skip=!Space.IsSolved(ex_SaveID);
      QapAssert(!skip);
      if(skip)continue;
      if(true)
      {
        auto&item=Space[ex_SaveID];
        if(!item.count)continue;
      }
      bool f0=ex.get()->IsBasedOn(tdmt.pdTType);
      bool f1=ex.get()->IsBasedOn(tdmt.pdDeclareType);
      QapAssert(!(f0&&f1));
      skip=f0||f1;
      if(skip)continue;
      out.push_back(std::move(ex));
    }
  }
  typedef vector<TAutoPtr<DeclareType>> TArray;
};
class DeclareEnvType{
public:
  public:typedef DeclareEnvType SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  TAutoPtr<DeclareType> Type;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Type);
    }
  public:
    DeclareEnvType(const DeclareEnvType&)=delete;DeclareEnvType(){DoReset();};
  public:
    DeclareEnvType(DeclareEnvType&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareEnvType&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Type=std::move(_Right.Type);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareEnvType";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<DeclareType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareEnvType";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  static bool IsEmpty(SelfClass&ref)
  {
    return !bool(ref.Type);
  }
};
class DeclareEnvRTTI{
public:
  public:typedef DeclareEnvRTTI SelfClass;
  public:
  vector<TAutoPtr<DeclareType>> Arr;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Arr);
    }
  public:
    DeclareEnvRTTI(const DeclareEnvRTTI&)=delete;DeclareEnvRTTI(){DoReset();};
  public:
    DeclareEnvRTTI(DeclareEnvRTTI&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareEnvRTTI&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Arr=std::move(_Right.Arr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareEnvRTTI";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<DeclareType>>>::GetRTTI(RTTI),"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareEnvRTTI";
      }
    };
  public:
public:
  typedef TServerPtrSpace TSpace;
  typedef vector<TAutoPtr<DeclareType>> TArray;
public:
  struct TwoDeclareType
  {
    DeclareType*pdTType;
    DeclareType*pdDeclareType;
    TwoDeclareType(const TwoDeclareType&Ref):pdTType(nullptr),pdDeclareType(nullptr){oper_set(Ref);}
    TwoDeclareType():pdTType(nullptr),pdDeclareType(nullptr){}
    template<class TYPE>
    TwoDeclareType(TYPE&ref):pdTType(ref.pTType),pdDeclareType(ref.pDeclareType)
    {
      static_assert(std::is_same<std::remove_reference<decltype(this->pdTType)>::type,std::remove_reference<decltype(ref.pdTType)>::type>::value,"no way");
      static_assert(std::is_same<std::remove_reference<decltype(this->pdDeclareType)>::type,std::remove_reference<decltype(ref.pdDeclareType)>::type>::value,"no way");
    }
    void oper_set(const TwoDeclareType&Ref)
    {
      this->pdTType=Ref.pdTType;
      this->pdDeclareType=Ref.pdDeclareType;
    }
    void operator=(const TwoDeclareType&Ref){oper_set(Ref);}
  };
public:
  void GrabFrom(DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt)
  {
    TDeclareEnvRTTI_WeakDetail<void>::GrabFrom(*this,Source,Space,tdmt);
  }
  void RetAll(TSpaceDependsTools&Tools)
  {
    QapDebugMsg("no used?");
  }
  bool ApplyTo(TSpaceDependsTools&Tools,TSpace&tmpSpace)
  {
    QapDebugMsg("no used?");
    return false;
  }
};
class DeclareType;
struct EnvVoidPtr
{
  typedef TServerPtr<IEsoteric>ptr_t;
  ptr_t*ptr;
  TType*type;
  EnvVoidPtr():ptr(nullptr),type(nullptr){};
  EnvVoidPtr(ptr_t*ptr,TType*type=nullptr):ptr(ptr),type(type){}
  ptr_t::ptr_t*get()const{return ptr?ptr->ptr:nullptr;}
  bool IsValid()const{return bool(ptr)&&bool(type);}
  bool IsNull()const{return bool(!ptr)&&bool(!type);}
  template<class TYPE>
  void set(const TAutoPtr<TYPE>&ref)
  {
    ptr=nullptr;
    type=nullptr;
    if(!ref)return;
    ptr=(ptr_t*)(void*)&ref.get()->Self;
    type=ref.Product.pType.get();
  }
  void set_zero(){ptr=nullptr;type=nullptr;}
  bool operator==(const EnvVoidPtr&ref)const{return oper_eq(ref);}
  bool operator!=(const EnvVoidPtr&ref)const{return !oper_eq(ref);}
  bool oper_eq(const EnvVoidPtr&ref)const
  {
    return (this->ptr==ref.ptr)&&(this->type==ref.type);
  }
};
class EnvItem{
public:
  public:typedef EnvItem SelfClass;
  public:
  int id;
  EnvVoidPtr ptr;
  EnvVoidPtr ptr_lnk;
  string name;
  int count;
  bool passed;
  bool system;
  bool hidden;
    public:
    void DoReset()
    {
      {
      }
  (this->id)=(0);detail::FieldTryDoReset(this->ptr);detail::FieldTryDoReset(this->ptr_lnk);(this->name)=("");(this->count)=(0);(this->passed)=(false);(this->system)=(false);(this->hidden)=(false);
    }
  public:
    EnvItem(const EnvItem&)=delete;EnvItem(){DoReset();};
  public:
    EnvItem(EnvItem&&_Right){operator=(std::move(_Right));}
    void operator=(EnvItem&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->id=std::move(_Right.id);
  this->ptr=std::move(_Right.ptr);
  this->ptr_lnk=std::move(_Right.ptr_lnk);
  this->name=std::move(_Right.name);
  this->count=std::move(_Right.count);
  this->passed=std::move(_Right.passed);
  this->system=std::move(_Right.system);
  this->hidden=std::move(_Right.hidden);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="EnvItem";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","0");
  Info->AddMemberDEF(Sys$$<EnvVoidPtr>::GetRTTI(RTTI),"ptr",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<EnvVoidPtr>::GetRTTI(RTTI),"ptr_lnk",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptr_lnk))),"DEF","$");
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"SET","\"\"");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"count",int(&(((SelfClass*)nullptr)->*(&SelfClass::count))),"SET","0");
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"passed",int(&(((SelfClass*)nullptr)->*(&SelfClass::passed))),"SET","false");
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"system",int(&(((SelfClass*)nullptr)->*(&SelfClass::system))),"SET","false");
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"hidden",int(&(((SelfClass*)nullptr)->*(&SelfClass::hidden))),"SET","false");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "EnvItem";
      }
    };
  public:
public:
  EnvItem&copy(const EnvItem&source)
  {
    this->id=source.id;this->name=source.name;this->ptr=source.ptr;this->ptr_lnk=source.ptr_lnk;this->count=source.count;this->passed=source.passed;this->system=source.system;this->hidden=source.hidden;
    return *this;
  }
  void CheckNullptr()
  {
    QapAssert(id==0);
    QapAssert(ptr.IsNull());
    QapAssert(ptr_lnk.IsNull());
    QapAssert(name=="nullptr");
    QapAssert(count==1);
    QapAssert(passed==true);
    QapAssert(system==true);
    QapAssert(hidden==false);
  }
  bool oper_eq(const SelfClass&ref,bool ignore_id=false)const
  {
    bool result=ignore_id||(this->id==ref.id);
    result=result&&(this->name==ref.name);result=result&&(this->ptr==ref.ptr);result=result&&(this->ptr_lnk==ref.ptr_lnk);result=result&&(this->count==ref.count);result=result&&(this->passed==ref.passed);result=result&&(this->system==ref.system);result=result&&(this->hidden==ref.hidden);
    return result;
  }
  bool operator==(const SelfClass&ref)const{return oper_eq(ref);}
  bool IsNoUsed()
  {
    return id&&ptr.IsNull()&&ptr_lnk.IsNull();
  }
  void SetAsNullptr()
  {
    name="nullptr";
    count=1;
    passed=true;
    system=true;
    hidden=false;
  }
  template<class TYPE>
  EnvItem&weak_get_lnk(TServerPtrSpace&Space)const
  {
    QapAssert(ptr_lnk.IsValid());
    int SID=ptr_lnk.ptr->SaveID;
    QapAssert(Space.IsAllowed(SID));
    auto&item=Space[SID];
    QapAssert(this->ptr_lnk.ptr==item.ptr.ptr);
    QapAssert(this->ptr_lnk.type==item.ptr.type);
    return item;
  }
  EnvItem&get_lnk(TServerPtrSpace&Space)const{return weak_get_lnk<void>(Space);}
};
struct SpaceMutator
{
  vector<EnvVoidPtr::ptr_t*> arr;
  int find_key_by_value(EnvVoidPtr::ptr_t*ptr)
  {
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i]==ptr)return i;
    }
    return -1;
  }
  bool has_value(EnvVoidPtr::ptr_t*ptr)
  {
    return find_key_by_value(ptr)!=-1;
  }
};
class TServerPtrSpace{
public:
  typedef TServerPtrSpace SelfClass;
public:
  vector<EnvItem> Arr;
public:
  void operator=(SelfClass&&Ref)
  {
    clear();
    Arr=std::move(Ref.Arr);
  }
  TServerPtrSpace(SelfClass&&Ref)
  {
    clear();
    Arr=std::move(Ref.Arr);
  }
  TServerPtrSpace()
  {
    Arr.reserve(1024*128);
    auto&ex=UnsafeAdd(nullptr,nullptr);
    ex.SetAsNullptr();
  }
  ~TServerPtrSpace(){clear();}
public:
  void hack_clear()
  {
    for(int i=0;i<Arr.size();i++)
    {
      Del(Arr[i],true);
    }
    Arr.clear();
  }
  void clear()
  {
    for(int i=0;i<Arr.size();i++)
    {
      Del(Arr[i]);
    }
    Arr.clear();
  }
public:
  static void make_linked(EnvItem&a,EnvItem&b)
  {
    bool f0=a.ptr_lnk.IsNull();
    bool f1=b.ptr_lnk.IsNull();
    QapAssert(f0&&f1);
    a.ptr_lnk=b.ptr;
    b.ptr_lnk=a.ptr;
  };
public:
  bool CheckServTID(int tid)
  {
    if(!IsAllowed(tid))return false;
    auto&item=Arr[tid];
    bool flag=true;
    flag=item.ptr.ptr;
    QapAssert(flag);
    flag=tid==item.ptr.ptr->SaveID;
    QapAssert(flag);
    return flag;
  }
  bool CheckServSaveID(TServerPtr<IEsoteric>*pServ=nullptr)const
  {
    QapAssert(pServ);
    int SaveID=pServ->SaveID;
    {
      bool flag=(SaveID>0)&&(SaveID<Arr.size());
      if(!flag){
        QapAssert(!SaveID);
        return false;
      }
    }
    auto&ex=Arr[SaveID];
    bool flag=ex.ptr.ptr==pServ;
    QapAssert(flag);
    return flag;
  }
  EnvItem&UnsafeAdd(const EnvVoidPtr&ptr)
  {
    int id=Arr.size();
    {
      if(id>=Arr.capacity())QapDebugMsg("grow are not allowed here.\n"+IToS(Arr.capacity()));
      EnvItem tmp;
      Arr.push_back(std::move(tmp));
    }
    auto&back=Arr.back();
    auto*pServ=ptr.ptr;
    if(pServ)pServ->SaveID=id;
    back.id=id;
    back.ptr=ptr;
    return back;
  }
  EnvItem&Insert(const EnvItem&item)
  {
    int id=Arr.size();
    {
      EnvItem tmp;
      Arr.push_back(std::move(tmp));
    }
    auto&back=Arr.back();
    back.copy(item).id=id;
    auto connect=[id](EnvVoidPtr&ptr)->void
    {
      auto*p=ptr.ptr;
      if(!p)return;
      int&sid=p->SaveID;
      QapAssert(!sid);
      sid=id;
    };
    connect(back.ptr);
    return back;
  }
  EnvItem&InsertTo(int id,const EnvItem&item)
  {
    auto&back=Arr[id];
    QapAssert(back.IsNoUsed());
    back.copy(item).id=id;
    auto connect=[id](EnvVoidPtr&ptr)->void
    {
      auto*p=ptr.ptr;
      if(!p)return;
      int&sid=p->SaveID;
      QapAssert(!sid);
      sid=id;
    };
    connect(back.ptr);
    return back;
  }
  EnvItem&UnsafeAdd(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr)
  {
    return UnsafeAdd(EnvVoidPtr(pServ,pType));
  }
  EnvItem&AddExt(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr,const string&name="")
  {
    QapAssert(pServ);
    if(true)
    {
      bool flag=CheckServSaveID(pServ);
      if(flag)
      {
        QapAssert(false);
        return Arr[pServ->SaveID];
      }
    }
    auto&back=UnsafeAdd(pServ,pType);
    back.name=name;
    return back;
  }
  void Del(EnvItem&item,bool hack_mode=false)
  {
    Del(item.ptr.ptr,hack_mode);
  }
  void Del(TServerPtr<IEsoteric>*pServ,bool hack_mode=false)
  {
    if(!pServ)return;
    QapAssert(pServ->SaveID);
    {
      const int&id=pServ->SaveID;
      QapAssert(IsAllowed(id));
      auto&ex=Arr[id];
      QapAssert(ex.id==id);
      if(1)
      {
        bool f[]={
          ex.ptr.ptr==pServ,
          ex.ptr_lnk.ptr==pServ
        };
        QapAssert(f[0]!=f[1]);
      }
      ex.ptr=nullptr;
      if(!hack_mode)if(ex.ptr_lnk.ptr)
      {
        QapAssert(ex.ptr_lnk.ptr->SaveID!=id);
      }
      ex.ptr_lnk=nullptr;
    }
    pServ->SaveID=0;
  }
  EnvVoidPtr::ptr_t*GetPtrByID(int id){return Arr[id].ptr.ptr;}
  EnvVoidPtr::ptr_t*GetAdvPtrByID(int id){return Arr[id].ptr_lnk.ptr;}
public:
  EnvItem&operator[](int index){return Arr[index];}
  const EnvItem&operator[](int index)const{return Arr[index];}
public:
  template<class TYPE>
  EnvItem&operator[](const TSelfPtr<TYPE>&index){
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
  template<class TYPE>
  const EnvItem&operator[](const TSelfPtr<TYPE>&index)const{
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
public:
  bool IsAllowed(int index){
    return (0<=index)&&(index<Arr.size());
  }
  bool IsSolved(int index){
    return IsAllowed(index)&&(Arr[index].ptr.ptr);
  }
  int size(){return Arr.size();}
public:
  void resize(int count)
  {
    QapAssert(count>=size());
    for(int i=size();i<count;i++)
    {
      UnsafeAdd(nullptr,nullptr);
    }
  }
public:
  void Repack()
  {
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    for(int i=0;i<tmpSpace.size();i++)
    {
      auto&item=tmpSpace[i];
      if(!item.count)continue;
      {
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        auto&back=Space.Insert(temp);
        QapAssert(&back==&Space[back.id]);
      }
    }
  }
  /*
    RepackV2 разделяет одно пространство на два.
    примечание:
      нулевой элемент во всех проастарнства - nullptr. nullptr`ы мы не трогаем.
    Space0.size() == N.
    Space1.size() == X.
    Space2.size() == N.
    Space0: все N - элементов исправны.
    Space1: все X - элементов исправны.
    Space2: превые X - элементов не исправны. остальные исправны.
    Space0: this - до RepackV2
    Space1: this - после RepackV2
    Space2: Out - после RepackV2
  */
  void RepackV2(SelfClass&Out)
  {
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    Space=std::move(TSpace());
    Out=std::move(TSpace());
    Out.resize(tmpSpace.size());
    int X=1;for(int i=1;i<tmpSpace.size();i++)if(tmpSpace[i].count)X++;
    for(int i=1;i<tmpSpace.size();i++)
    {
      auto&item=tmpSpace[i];
      if(!item.count)
      {
        auto&space=Out;
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        auto&back=space.InsertTo(X,temp);
        QapAssert(&back==&space[back.id]);
        X++;
        continue;
      }
      if(item.count)
      {
        auto&space=Space;
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        auto&back=space.Insert(temp);
        QapAssert(&back==&space[back.id]);
        continue;
      }
    }
  }
public:
  void Mutate(SpaceMutator&SM)
  {
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    Space.reserve(tmpSpace.size());
    auto func=[&tmpSpace,&Space](int i)
    {
      auto&item=tmpSpace[i];
      if(item.id==-1)return;
      EnvItem temp; temp.copy(item);
      tmpSpace.Del(item);
      auto&back=Space.Insert(temp);
      QapAssert(&back==&Space[back.id]);
    };
    func(0);
    auto&arr=SM.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      QapAssert(ex->SaveID);
      QapAssert(tmpSpace.IsAllowed(ex->SaveID));
      auto&item=tmpSpace[ex->SaveID];
      QapAssert(item.id>0);
      QapAssert(item.id==ex->SaveID);
      {
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        item.id=-1;
        auto&back=Space.Insert(temp);
        QapAssert(&back==&Space[back.id]);
      }
    }
    for(int i=1;i<tmpSpace.size();i++)func(i);
  }
public:
  void CopyAdvFrom(SelfClass&Source)
  {
    QapDebugMsg("deprecated");
    auto&arr=Source.Arr;
    clear();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.ptr_lnk.IsNull())
      {
        EnvItem tmp;
        Insert(tmp);
        continue;
      }
      auto name=ex.name+"->getLink()";
      AddExt(ex.ptr_lnk.ptr,ex.ptr_lnk.type,name);
    }
  }
  void CopyAdvFromV2(SelfClass&Source,SelfClass&BigSpace)
  {
    auto&arr=Source.Arr;
    (*this)=std::move(SelfClass());
    for(int i=1;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.ptr_lnk.IsNull())
      {
        EnvItem tmp;
        Insert(tmp);
        continue;
      }
      auto&item=BigSpace[ex.ptr_lnk.ptr->SaveID];
      EnvItem temp;
      temp.copy(item);
      BigSpace.Del(item);
      Insert(temp);
    }
  }
public:
  void Swap(int A,int B)
  {
    if(A==B)return;
    EnvItem ta;
    EnvItem tb;
    auto&Space=*this;
    auto&a=Space[A];
    auto&b=Space[B];
    ta.copy(a);
    tb.copy(b);
    Del(a);
    Del(b);
    InsertTo(A,tb);
    InsertTo(B,ta);
  }
public:
  template<class TYPE>
  static void ClientMarker(TYPE&Space,TType*pType,void*pValue)
  {
    ::ClientMarker(Space,pType,pValue);
  }
public:
  template<class TYPE>
  void SolveDepends(TYPE&temp)
  {
    static_assert(std::is_same<DependsSolver,TYPE>::value,"error");
    temp.SolveDepends(*this);
  }
public:
  string GetListOfNoPassed(bool all)
  {
    string log;
    auto&arr=Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!all)if(!ex.count||ex.passed)continue;
      log+=ex.name+"\n";
    }
    return log;
  };
  bool CheckHidden()
  {
    int errors=0;
    auto&arr=Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&item=arr[i];
      if(item.hidden&&item.count)
      {
        QapDebugMsg("item(\""+item.name+"\").count = "+IToS(item.count));
        errors++;
      }
    }
    return !errors;
  };
public:
  EnvItem*find_by_name(const string&name)
  {
    for(int i=0;i<size();i++)
    {
      EnvItem&EX=Arr[i];
      if(name==EX.name)return &EX;
    }
    return nullptr;
  }
public:
  bool IsValid()
  {
    if(Arr.empty())
    {
      QapAssert("undefine behevior. also: may be true");
      return true;
    }
    Arr[0].CheckNullptr();
    for(int i=1;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      if(!item.ptr.type&&!item.ptr.ptr)return false;
      if(1)
      {
        bool flag=bool(item.ptr_lnk.ptr)==bool(item.ptr_lnk.type);
        if(!flag)return false;
      }
    }
    return true;
  }
public:
  void reserve(int _Count)
  {
    Arr.reserve(_Count);
  }
public:
  void AddPointsFromSys()
  {
    weak_detail<void>::AddPointsFromSys(*this);
  }
  void AddPointsFromEnv(IEnvRTTI&Env)
  {
    weak_detail<void>::AddPointsFromEnv(*this,Env);
  }
  void AddPointsFrom(const TRawPtr&ptr)
  {
     weak_detail<void>::AddPointsFrom(*this,ptr);
  }
  void UpdatePointsTypeFrom(const TRawPtr&ptr)
  {
    weak_detail<void>::UpdatePointsTypeFrom(*this,ptr);
  }
  template<class TYPE>
  struct weak_detail
  {
    static void AddPointsFromSys(TServerPtrSpace&Space)
    {
      EnvAdapter::GoSys(Space);
    }
    static void AddPointsFromEnv(TServerPtrSpace&Space,IEnvRTTI&Env)
    {
      EnvAdapter::GoEnv(Space,Env,EnvAdapter::TMetaTypePack(Env));
    }
    static void AddPointsFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      GrabServerPtr(Space,ptr.pType,ptr.pValue,true);
    }
    struct UnnamedStruct
    {
      typedef TServerPtrSpace TSpace;
      TSpace&Space;
      UnnamedStruct(TSpace&Space):Space(Space){}
      void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
      {
        if(!Space.CheckServSaveID(&Serv))
        {
          QapDebugMsg("bad news");return;
        }
        auto&ex=Space[Serv.SaveID];
        QapAssert(elemType);
        if(ex.ptr.type==elemType)
        {
          QapAssert(elemType);
          QapAssert(!ex.ptr.type);
          return;
        }
        ex.ptr.type=elemType;
      }
    };
    static void UpdatePointsTypeFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      class TServerPtrTypeUpdater:public TSmartPtrVisitor::ICallBack{
      public:
        UnnamedStruct Field;
        TServerPtrTypeUpdater(TServerPtrSpace&Space):Field(Space){}
      public:
        void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
        {
          Field.Visit(Serv,elemType);
        }
        void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
        void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
        void Visit(TClientPtr<IEsoteric>&A){}
        void Visit(THardClientPtr<IEsoteric>&A){}
      };
      TServerPtrTypeUpdater Updater(Space);
      TSmartPtrVisitor SPG(Updater,ptr.pValue);
      ptr.pType->Use(SPG);
    }
  };
};
class TBigMetaTypePack{
public:
  public:typedef TBigMetaTypePack SelfClass;
  public:
    TType*pEnvType;
    TType*pTType;
    TType*pTTypeStruct;
    TType*pTTypeSys;
    TType*pDeclareType;
    TType*pDeclareTypeStruct;
    TType*pDeclareTypeSys;
    void DoReset()
    {
      this->pEnvType=nullptr;
      this->pTType=nullptr;
      this->pTTypeStruct=nullptr;
      this->pTTypeSys=nullptr;
      this->pDeclareType=nullptr;
      this->pDeclareTypeStruct=nullptr;
      this->pDeclareTypeSys=nullptr;
    }
    TBigMetaTypePack(const SelfClass&ref){DoReset();oper_set(ref);}
    TBigMetaTypePack(){DoReset();}
    TBigMetaTypePack(IEnvRTTI&Env){DoReset();prepare(Env);}
    template<class TYPE>TBigMetaTypePack(const TYPE&ref){DoReset();oper_set(ref);}
  template<class QAP_RTTI>
  void prepare(QAP_RTTI&Env)
  {
    this->pEnvType=Sys$$<EnvType>::GetRTTI((IEnvRTTI&)Env);this->pTType=Sys$$<TType>::GetRTTI((IEnvRTTI&)Env);this->pTTypeStruct=Sys$$<TTypeStruct>::GetRTTI((IEnvRTTI&)Env);this->pTTypeSys=Sys$$<TTypeSys>::GetRTTI((IEnvRTTI&)Env);this->pDeclareType=Sys$$<DeclareType>::GetRTTI((IEnvRTTI&)Env);this->pDeclareTypeStruct=Sys$$<DeclareTypeStruct>::GetRTTI((IEnvRTTI&)Env);this->pDeclareTypeSys=Sys$$<DeclareTypeSys>::GetRTTI((IEnvRTTI&)Env);
  }
  void oper_set(const SelfClass&ref)
  {
    this->pEnvType=ref.pEnvType;
    this->pTType=ref.pTType;
    this->pTTypeStruct=ref.pTTypeStruct;
    this->pTTypeSys=ref.pTTypeSys;
    this->pDeclareType=ref.pDeclareType;
    this->pDeclareTypeStruct=ref.pDeclareTypeStruct;
    this->pDeclareTypeSys=ref.pDeclareTypeSys;
  }
  template<class TYPE>
  void oper_set(const TYPE&ref)
  {
    static_assert(std::is_same<std::remove_reference<decltype(this->pEnvType)>::type,std::remove_reference<decltype(ref.pEnvType)>::type>::value,"no way");
    this->pEnvType=ref.pEnvType;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");
    this->pTType=ref.pTType;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeStruct)>::type,std::remove_reference<decltype(ref.pTTypeStruct)>::type>::value,"no way");
    this->pTTypeStruct=ref.pTTypeStruct;
    static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeSys)>::type,std::remove_reference<decltype(ref.pTTypeSys)>::type>::value,"no way");
    this->pTTypeSys=ref.pTTypeSys;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareType)>::type,std::remove_reference<decltype(ref.pDeclareType)>::type>::value,"no way");
    this->pDeclareType=ref.pDeclareType;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareTypeStruct)>::type,std::remove_reference<decltype(ref.pDeclareTypeStruct)>::type>::value,"no way");
    this->pDeclareTypeStruct=ref.pDeclareTypeStruct;
    static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareTypeSys)>::type,std::remove_reference<decltype(ref.pDeclareTypeSys)>::type>::value,"no way");
    this->pDeclareTypeSys=ref.pDeclareTypeSys;
  }
  void operator=(const SelfClass&ref){oper_set(ref);}
};
class EnvAdapter{
public:
  template<class TYPE>
  static TServerPtr<IEsoteric>*get(TSelfPtr<TYPE>&ref){
    return (TServerPtr<IEsoteric>*)&ref.P;
  }
public:
  class TMetaTypePack{
  public:
  public:typedef TMetaTypePack SelfClass;
  public:
     TType*pTType;
      TType*pTTypeStruct;
    void DoReset()
    {
       this->pTType=nullptr;
        this->pTTypeStruct=nullptr;
    }
    TMetaTypePack(const SelfClass&ref){DoReset();oper_set(ref);}
    TMetaTypePack(){DoReset();}
    TMetaTypePack(IEnvRTTI&Env){DoReset();prepare(Env);}
    template<class TYPE>TMetaTypePack(const TYPE&ref){DoReset();oper_set(ref);}
  template<class QAP_RTTI>
  void prepare(QAP_RTTI&Env)
  {
     this->pTType=Sys$$<TType>::GetRTTI((IEnvRTTI&)Env); this->pTTypeStruct=Sys$$<TTypeStruct>::GetRTTI((IEnvRTTI&)Env); ;
  }
  void oper_set(const SelfClass&ref)
  {
     this->pTType=ref.pTType;
      this->pTTypeStruct=ref.pTTypeStruct;
  }
  template<class TYPE>
  void oper_set(const TYPE&ref)
  {
     static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");
     this->pTType=ref.pTType;
      static_assert(std::is_same<std::remove_reference<decltype(this->pTTypeStruct)>::type,std::remove_reference<decltype(ref.pTTypeStruct)>::type>::value,"no way");
     this->pTTypeStruct=ref.pTTypeStruct;
  }
  void operator=(const SelfClass&ref){oper_set(ref);}
  };
public:
  TType*FindTypeByFactory(IEnvRTTI&Env,IFactory*pFactory)
  {
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if(pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
  TType*FindTypeByFactoryFast(IEnvRTTI&Env,TServerPtrSpace&Space,IFactory*pFactory)
  {
    auto&ptr_lnk=Space[pFactory->Self].ptr_lnk;
    if(ptr_lnk.IsNull()){
      ptr_lnk=Space[FindTypeByFactory(Env,pFactory)->Self].ptr;
    }
    if(ptr_lnk.IsValid())return (TType*)ptr_lnk.get();
    return nullptr;
  }
public:
  static void GoV3(TServerPtrSpace&Space,IEnvRTTI&Env)
  {
    GoV2(Space,Env,TMetaTypePack(Env));
  }
  static void GoV2(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    Space.reserve(2048);
    {
      auto*it=&Env;
      auto&ex=Space.AddExt(get(it->Self),nullptr,"[Env]");
      ex.system=true;
      ex.hidden=true;
    }
    {
      IEnvRTTI&env=Env;
      auto*it=env.GetAlloc();
      auto&ex=Space.AddExt(get(it->Self),nullptr,"[Env.GetAlloc()]");
      ex.system=true;
      ex.hidden=true;
    }
    GoSys(Space);
    GoEnv(Space,Env,TypePack);
  }
  static void GoSys(TServerPtrSpace&Space)
  {
    GoFactory(Space);
    GoCppIO(Space);
    GoBinIO(Space);
    GoVectorAPI(Space);
  }
  static void GoFactory(TServerPtrSpace&Space)
  {
    auto&Arr=TFactory<void>::GetFactorys();
    for(int i=0;i<Arr.size();i++)
    {
      IFactory*it=Arr[i].get();
      string name="TFactory<"+it->GetElementTypeFullName()+">::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoCppIO(TServerPtrSpace&Space)
  {
    auto&Arr=THeadCppIO<void>::GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="THeadCppIO<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoBinIO(TServerPtrSpace&Space)
  {
    auto&Arr=THeadBinIO<void>::GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="THeadBinIO<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoVectorAPI(TServerPtrSpace&Space)
  {
    auto&Arr=TVectorAPI<void>::GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="TVectorAPI<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoEnv(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    auto*pTType=TypePack.pTType;
    auto*pTTypeStruct=TypePack.pTTypeStruct;
    auto&Arr=Env.GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      TType*it=Arr[i].Type.get();
      string name="Sys$$<"+it->GetFullName()+">::GetRTTI()";
      TType*type=Arr[i].Type.Product.pType.get();
      QapAssert(IsBasedOn(type,pTType));
      bool flag1=IsBasedOn(type,pTTypeStruct);
      bool flag2=IsBasedOn(it,pTType);
      bool system=!flag1||flag2;
      Space.AddExt(get(it->Self),type,name).system=system;
    }
  }
  static void FixEnvType(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    auto*pTType=TypePack.pTType;
    auto*pTTypeStruct=TypePack.pTTypeStruct;
    auto&Arr=Env.GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      TType*it=Arr[i].Type.get();
      TType*type=Arr[i].Type.Product.pType.get();
      QapAssert(IsBasedOn(type,pTType));
      bool flag1=IsBasedOn(type,pTTypeStruct);
      bool flag2=IsBasedOn(it,pTType);
      bool system=!flag1||flag2;
      auto&item=Space[it->Self];
      item.system=false;
    }
  }
  static bool IsFactoryEqual(TType*p,TType*b)
  {
    return p->Factory.get()==b->Factory.get();
  }
  static bool IsBasedOn(TType*p,TType*base)
  {
    if(IsFactoryEqual(p,base))return true;
    TType*subtype=p->GetSubType();
    return subtype?IsBasedOn(subtype,base):false;
  }
};
struct IQapStream{
  virtual bool Load(){return false;}
  virtual bool Save(){return false;}
  virtual QapIO&GetContent()=0;
};
struct TQapFileStream:public IQapStream{
  TDataIO IO;
  string fn;
  bool readonly;
  TQapFileStream(const string&fn,bool readonly=true):fn(fn),readonly(readonly){}
  bool Load(){
    return IO.IO.LoadFile(fn);
  }
  bool Save(){
    if(readonly)
    {
      QapDebugMsg("yes?");
      return false;
    }
    return IO.IO.SaveFile(fn);
  }
  QapIO&GetContent(){return IO;};
};
struct TQapMemoryStream:public IQapStream{
  TDataIO IO;
  TQapMemoryStream(){}
  bool Load(){
    return true;
  }
  bool Save(){
    return true;
  }
  QapIO&GetContent(){return IO;};
};
struct TDataIOStream:public IQapStream{
  TDataIO&IO;
  TDataIOStream(TDataIO&IO):IO(IO){}
  bool Load(){return true;}
  bool Save(){return true;}
  QapIO&GetContent(){return IO;};
};
struct IQapRawObject{
  virtual TRawPtr&Get(IEnvRTTI&Env)=0;
};
struct TQapRawObject:public IQapRawObject{
  TRawPtr raw_ptr;
  TQapRawObject(const TRawPtr&ptr){raw_ptr=ptr;}
  TQapRawObject(TType*pType,void*pValue){raw_ptr.pType=pType;raw_ptr.pValue=pValue;}
  TRawPtr&Get(IEnvRTTI&Env){return raw_ptr;}
};
template<class TYPE>
struct TQapRawUberObject:public IQapRawObject{
  TRawPtr raw_ptr;
  TQapRawUberObject(TYPE&value)
  {
    raw_ptr.pType=nullptr;
    raw_ptr.pValue=&value;
  }
  TRawPtr&Get(IEnvRTTI&Env)
  {
    TType*pType=Sys$$<TYPE>::GetRTTI(Env);
    raw_ptr.pType=pType;
    return raw_ptr;
  }
};
template<class TYPE>
TQapRawUberObject<TYPE> QapRawUberObject(TYPE&value){
  TQapRawUberObject<TYPE> tmp(value);
  return std::move(tmp);
}
class DeclareType;
class DeclareTypeSys;class DeclareTypeSelfPtr;class DeclareTypeAutoPtr;class DeclareTypeWeakPtr;class DeclareTypeHardPtr;class DeclareTypeVoidPtr;class DeclareTypeFieldPtr;class DeclareTypeVector;class DeclareTypeArray;class DeclareTypeStruct;
class IDeclareVisitorRTTI{
public:
  virtual void Do(DeclareTypeSys*p)=0;
  virtual void Do(DeclareTypeSelfPtr*p)=0;
  virtual void Do(DeclareTypeAutoPtr*p)=0;
  virtual void Do(DeclareTypeWeakPtr*p)=0;
  virtual void Do(DeclareTypeHardPtr*p)=0;
  virtual void Do(DeclareTypeVoidPtr*p)=0;
  virtual void Do(DeclareTypeFieldPtr*p)=0;
  virtual void Do(DeclareTypeVector*p)=0;
  virtual void Do(DeclareTypeArray*p)=0;
  virtual void Do(DeclareTypeStruct*p)=0;
public:
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr;
    Is():ptr(nullptr){}
  public:
    template<class U>static TYPE*get(U*p){return nullptr;}
    template<>static TYPE*get<TYPE>(TYPE*p){return p;}
  public:
    void Do(DeclareTypeSys*p){ptr=get(p);}void Do(DeclareTypeSelfPtr*p){ptr=get(p);}void Do(DeclareTypeAutoPtr*p){ptr=get(p);}void Do(DeclareTypeWeakPtr*p){ptr=get(p);}void Do(DeclareTypeHardPtr*p){ptr=get(p);}void Do(DeclareTypeVoidPtr*p){ptr=get(p);}void Do(DeclareTypeFieldPtr*p){ptr=get(p);}void Do(DeclareTypeVector*p){ptr=get(p);}void Do(DeclareTypeArray*p){ptr=get(p);}void Do(DeclareTypeStruct*p){ptr=get(p);}
  };
  template<class TYPE>
  static TYPE*UberCast(DeclareType*p){
    if(!p)return nullptr;Is<TYPE,IDeclareVisitorRTTI> IS;p->Use(IS);return IS.ptr;
  }
};
template<class TYPE>
struct QapDeclareDetail
{
  static string GetFullName(const DeclareType*ptr)
  {
    DeclareDetail::GetFullName GFN;
    DeclareType*p=(DeclareType*)ptr;
    p->Use(GFN);
    return GFN.fullname;
  }
  static DeclareType*GetSubType(const DeclareType*ptr)
  {
    auto*p=DeclareTypeStruct::UberCast((DeclareType*)ptr);
    return p?p->SubType.get():nullptr;
  }
  static bool IsBasedOn(const DeclareType*ptr,const DeclareType*A)
  {
    if(ptr==A)return true;
    auto*subtype=ptr->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};
class DeclareType{
public:
  public:typedef DeclareType SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    DeclareType(const DeclareType&)=delete;DeclareType(){DoReset();};
  public:
    DeclareType(DeclareType&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareType&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareType";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareType";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  virtual void Use(IDeclareVisitorRTTI&){QapDebugMsg("no way.");}
  string GetFullName()const
  {
    return QapDeclareDetail<void>::GetFullName(this);
  }
  DeclareType*GetSubType()const
  {
    return QapDeclareDetail<void>::GetSubType(this);
  }
  bool IsBasedOn(const DeclareType*A)const
  {
    return QapDeclareDetail<void>::IsBasedOn(this,A);
  }
};
class DeclareTypeSys:public DeclareType{
public:
  public:typedef DeclareTypeSys SelfClass;public:typedef DeclareType ParentClass;
  public:
  string FullName;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  (this->FullName)=("unnamed");
    }
  public:
    DeclareTypeSys(const DeclareTypeSys&)=delete;DeclareTypeSys(){DoReset();};
  public:
    DeclareTypeSys(DeclareTypeSys&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeSys&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->FullName=std::move(_Right.FullName);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeSys";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"FullName",int(&(((SelfClass*)nullptr)->*(&SelfClass::FullName))),"SET","\"unnamed\"");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeSys";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeSelfPtr:public DeclareType
{
public:
  public:typedef DeclareTypeSelfPtr SelfClass;public:typedef DeclareType ParentClass;
  public:
  TWeakPtr<DeclareType> ElementType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);
    }
  public:
    DeclareTypeSelfPtr(const DeclareTypeSelfPtr&)=delete;DeclareTypeSelfPtr(){DoReset();};
  public:
    DeclareTypeSelfPtr(DeclareTypeSelfPtr&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeSelfPtr&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeSelfPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeSelfPtr";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeAutoPtr:public DeclareType
{
  public:typedef DeclareTypeAutoPtr SelfClass;public:typedef DeclareType ParentClass;
  public:
  TWeakPtr<DeclareType> ElementType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);
    }
  public:
    DeclareTypeAutoPtr(const DeclareTypeAutoPtr&)=delete;DeclareTypeAutoPtr(){DoReset();};
  public:
    DeclareTypeAutoPtr(DeclareTypeAutoPtr&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeAutoPtr&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeAutoPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeAutoPtr";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeWeakPtr:public DeclareType
{
public:
  public:typedef DeclareTypeWeakPtr SelfClass;public:typedef DeclareType ParentClass;
  public:
  TWeakPtr<DeclareType> ElementType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);
    }
  public:
    DeclareTypeWeakPtr(const DeclareTypeWeakPtr&)=delete;DeclareTypeWeakPtr(){DoReset();};
  public:
    DeclareTypeWeakPtr(DeclareTypeWeakPtr&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeWeakPtr&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeWeakPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeWeakPtr";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeHardPtr:public DeclareType
{
  public:typedef DeclareTypeHardPtr SelfClass;public:typedef DeclareType ParentClass;
  public:
  TWeakPtr<DeclareType> ElementType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);
    }
  public:
    DeclareTypeHardPtr(const DeclareTypeHardPtr&)=delete;DeclareTypeHardPtr(){DoReset();};
  public:
    DeclareTypeHardPtr(DeclareTypeHardPtr&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeHardPtr&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeHardPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeHardPtr";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeFieldPtr:public DeclareType
{
public:
  public:typedef DeclareTypeFieldPtr SelfClass;public:typedef DeclareType ParentClass;
  public:
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
    }
  public:
    DeclareTypeFieldPtr(const DeclareTypeFieldPtr&)=delete;DeclareTypeFieldPtr(){DoReset();};
  public:
    DeclareTypeFieldPtr(DeclareTypeFieldPtr&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeFieldPtr&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeFieldPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeFieldPtr";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeVoidPtr:public DeclareType
{
public:
  public:typedef DeclareTypeVoidPtr SelfClass;public:typedef DeclareType ParentClass;
  public:
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
    }
  public:
    DeclareTypeVoidPtr(const DeclareTypeVoidPtr&)=delete;DeclareTypeVoidPtr(){DoReset();};
  public:
    DeclareTypeVoidPtr(DeclareTypeVoidPtr&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeVoidPtr&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeVoidPtr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeVoidPtr";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeVector:public DeclareType
{
public:
  public:typedef DeclareTypeVector SelfClass;public:typedef DeclareType ParentClass;
  public:
  TWeakPtr<DeclareType> ElementType;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);
    }
  public:
    DeclareTypeVector(const DeclareTypeVector&)=delete;DeclareTypeVector(){DoReset();};
  public:
    DeclareTypeVector(DeclareTypeVector&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeVector&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeVector";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeVector";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareTypeArray:public DeclareType
{
public:
  public:typedef DeclareTypeArray SelfClass;public:typedef DeclareType ParentClass;
  public:
  TWeakPtr<DeclareType> ElementType;
  int Size;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->ElementType);(this->Size)=(0);
    }
  public:
    DeclareTypeArray(const DeclareTypeArray&)=delete;DeclareTypeArray(){DoReset();};
  public:
    DeclareTypeArray(DeclareTypeArray&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeArray&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->ElementType=std::move(_Right.ElementType);
  this->Size=std::move(_Right.Size);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeArray";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"ElementType",int(&(((SelfClass*)nullptr)->*(&SelfClass::ElementType))),"DEF","$");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","0");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeArray";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};
class DeclareMember{
public:
  public:typedef DeclareMember SelfClass;
  public:
  string Name;
  TWeakPtr<DeclareType> Type;
  string Mode;
  string Value;
    public:
    void DoReset()
    {
      {
      }
  (this->Name)=("unnamed");detail::FieldTryDoReset(this->Type);detail::FieldTryDoReset(this->Mode);detail::FieldTryDoReset(this->Value);
    }
  public:
    DeclareMember(const DeclareMember&)=delete;DeclareMember(){DoReset();};
  public:
    DeclareMember(DeclareMember&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareMember&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Name=std::move(_Right.Name);
  this->Type=std::move(_Right.Type);
  this->Mode=std::move(_Right.Mode);
  this->Value=std::move(_Right.Value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareMember";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mode))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Value",int(&(((SelfClass*)nullptr)->*(&SelfClass::Value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareMember";
      }
    };
  public:
public:
  bool IsEqual(SelfClass&other)
  {
    QapDebugMsg("no way.");
  }
};
class DeclareTypeStruct:public DeclareType{
public:
  public:typedef DeclareTypeStruct SelfClass;public:typedef DeclareType ParentClass;
  public:
  string Name;
  TWeakPtr<DeclareType> SubType;
  TWeakPtr<DeclareType> OwnType;
  vector<DeclareMember> Members;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  (this->Name)=("unnamed");detail::FieldTryDoReset(this->SubType);detail::FieldTryDoReset(this->OwnType);detail::FieldTryDoReset(this->Members);
    }
  public:
    DeclareTypeStruct(const DeclareTypeStruct&)=delete;DeclareTypeStruct(){DoReset();};
  public:
    DeclareTypeStruct(DeclareTypeStruct&&_Right){operator=(std::move(_Right));}
    void operator=(DeclareTypeStruct&&_Right)
    {
      struct hidden{static void foo(DeclareType(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DeclareType::operator=(std::move(_Right));
      }
  this->Name=std::move(_Right.Name);
  this->SubType=std::move(_Right.SubType);
  this->OwnType=std::move(_Right.OwnType);
  this->Members=std::move(_Right.Members);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DeclareTypeStruct";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","\"unnamed\"");
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"SubType",int(&(((SelfClass*)nullptr)->*(&SelfClass::SubType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TWeakPtr<DeclareType>>::GetRTTI(RTTI),"OwnType",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnType))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<DeclareMember>>::GetRTTI(RTTI),"Members",int(&(((SelfClass*)nullptr)->*(&SelfClass::Members))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DeclareTypeStruct";
      }
    };
  public:
public:
  void Use(IDeclareVisitorRTTI&A){A.Do(this);} static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  bool TestField(const DeclareMember&it,int depth=0)
  {
    if(SubType)
    {
      auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
      bool result=pSubType->TestField(it,depth+1);
      if(!result)return result;
    }
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int cmp_id=0;
        static string idToStr[]={"Name",};
      const int cmp_n=lenof(idToStr)-(depth?1:0);
        do{if(cmp_id<cmp_n){if(it.Name==ex.Name)break;cmp_id++;
        };}while(false);
      if(cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        string fn=GetFullName();
        if(tmp=="Name")if(it.Name=="Self")if(fn=="QapWinProgram")continue;
        QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
        return depth;
      }
    }
    return true;
  }
  DeclareMember*GetNearSelf()
  {
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.Name!="Self")continue;
      auto*pFieldType=DeclareTypeSelfPtr::UberCast(ex.Type.get());
      QapAssert(pFieldType);
      QapAssert(pFieldType->ElementType.get()==this);
      return &ex;
    }
    auto*pSubType=DeclareTypeStruct::UberCast(GetSubType());
    return pSubType?pSubType->GetNearSelf():nullptr;
  }
  void AddField(DeclareMember&&field)
  {
    QapAssert(TestField(field));
    if(field.Name=="Self")
    {
      if(true)do
      {
        auto*type=DeclareTypeSelfPtr::UberCast(field.Type.get());
        QapAssert(type);
        if(this!=type->ElementType.get())
        {
          string fn=GetFullName();
          QapDebugMsg("field - \""+fn+"\"::"+field.Name+"\" has wrong type");
        }
      }while(false);
      if(GetNearSelf())do
      {
        auto*type=field.Type.get();
        auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
        string fn=GetFullName();
        string subtype=pSubType->GetFullName();
          if("QapWinProgram"==subtype)if("eWinProgram"==fn)break;
          if("QapWinProgram"==subtype)if("QapProgramD3D9"==fn)break;
        QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
      }while(false);
    }
    Members.push_back(std::move(field));
  }
  void AddMember(DeclareType*MemType,const string&MemName,const string&Mode,const string&Value)
  {
    DeclareMember tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
};
class DeclareDetail{
public:
  class StructTools{
  public:
    struct field_cmp_result_item{
      string fna;
      string fnb;
      int ida;
      int idb;
      void SetToDef(){
        ida=-1;
        idb=-1;
      }
    };
    static vector<field_cmp_result_item> CompareFieldsLists(const vector<DeclareMember>&A,const vector<DeclareMember>&B)
    {
      field_cmp_result_item tmp;
      tmp.SetToDef();
      vector<field_cmp_result_item> result;
      result.reserve(A.size()+B.size());
      vector<bool> passed;
      passed.resize(B.size(),false);
      for(int i=0;i<A.size();i++)
      {
        result.push_back(tmp);
        auto&ex=result.back();
        auto&ax=A[i];
        ex.ida=i;
        ex.fna=ax.Name;
        for(int j=0;j<B.size();j++)
        {
          if(passed[j])continue;
          auto&bx=B[j];
          if(ax.Name!=bx.Name)continue;
          ex.fnb=bx.Name;
          ex.idb=j;
          passed[j]=true;
        }
      }
      for(int j=0;j<B.size();j++)
      {
        if(passed[j])continue;
        result.push_back(tmp);
        auto&ex=result.back();
        auto&bx=B[j];
        ex.fnb=bx.Name;
        ex.idb=j;
        passed[j]=true;
      }
      return std::move(result);
    }
    static void Filter_RemoveEqual(vector<field_cmp_result_item>&arr)
    {
      vector<field_cmp_result_item> tmp;
      std::swap(tmp,arr);
      for(int i=0;i<tmp.size();i++)
      {
        auto&ex=tmp[i];
        if((ex.ida<0)!=(ex.idb<0))
        {
          arr.push_back(std::move(ex));
        }
      }
    }
    static string CompareFieldsLists_ToString(const vector<field_cmp_result_item>&arr)
    {
      string out;
      int n_a=[&]()->size_t{size_t n=0;for(size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fna.size(),n);return n;}();
      int n_b=[&]()->size_t{size_t n=0;for(size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fnb.size(),n);return n;}();
      auto&f=[](const string&s,size_t n)->string{string tmp=s;for(size_t i=s.size();i<n;i++)tmp+=" ";return tmp;};
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        out+=f(ex.fna,n_a)+" = "+f(ex.fnb,n_b)+"\n";
      }
      return out;
    }
  };
public:
  class GetFullName:public IDeclareVisitorRTTI{
  public:
    string fullname;
  public:
    void Do(DeclareTypeSys*p)
    {
      fullname=p->FullName;
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      string template_name="TSelfPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      string template_name="TAutoPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      string template_name="TWeakPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeHardPtr*p)
    {
      string template_name="THardPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      string name="TVoidPtr";
      fullname=name;
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      string name="TFieldPtr";
      fullname=name;
    }
    void Do(DeclareTypeVector*p)
    {
      string template_name="vector";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeArray*p)
    {
      string template_name="array";
      fullname=template_name+"<"+p->ElementType->GetFullName()+","+IToS(p->Size)+">";
    }
    void Do(DeclareTypeStruct*p)
    {
      string template_name="TSelfPtr";
      auto*pOwnType=p->OwnType.get();
      fullname=pOwnType?pOwnType->GetFullName()+"::"+p->Name:p->Name;
    }
  };
  class GetSubType:public IDeclareVisitorRTTI{
  public:
    DeclareType*pValue;
    GetSubType():pValue(nullptr){}
  public:
    void Do(DeclareTypeSys*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeHardPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeVector*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeStruct*p)
    {
      pValue=p->SubType.get();
    }
  };
  template<class TSPACE>
  class IsEqualTo:public IDeclareVisitorRTTI{
  public:
    TSPACE&Space;
    bool Result;
    DeclareType*pValue;
    bool Mute;
    IsEqualTo(TSPACE&Space):Space(Space),Result(false),pValue(nullptr),Mute(false){}
  public:
    struct EqualDetail
    {
      static bool Equal(TSPACE&Space,...){return false;}
      static bool Equal(TSPACE&Space,DeclareTypeSys*pA,DeclareTypeSys*pB,bool Mute)
      {
        return pA->FullName==pB->FullName;
      }
      static bool Equal(TSPACE&Space,DeclareTypeSelfPtr*pA,DeclareTypeSelfPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeAutoPtr*pA,DeclareTypeAutoPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeWeakPtr*pA,DeclareTypeWeakPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeHardPtr*pA,DeclareTypeHardPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVoidPtr*pA,DeclareTypeVoidPtr*pB,bool Mute)
      {
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeFieldPtr*pA,DeclareTypeFieldPtr*pB,bool Mute)
      {
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVector*pA,DeclareTypeVector*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeArray*pA,DeclareTypeArray*pB,bool Mute)
      {
        if(pA->Size!=pB->Size)return false;
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeStruct*pA,DeclareTypeStruct*pB,bool Mute)
      {
        string fna=pA->GetFullName();
        string fnb=pB->GetFullName();
        bool flag=fna==fnb;
        if(!flag)return false;
        auto&A=pA->Members;
        auto&B=pB->Members;
        if(A.size()!=B.size())
        {
          string msg="type : \""+fna+"\"\n";
          msg+="A.size = "+IToS(A.size())+"\n";
          msg+="B.size = "+IToS(B.size())+"\n";
          if(!Mute)QapDebugMsg(msg);
          auto detail_result=StructTools::CompareFieldsLists(A,B);
          StructTools::Filter_RemoveEqual(detail_result);
          auto str_detail_result=StructTools::CompareFieldsLists_ToString(detail_result);
          if(!Mute)QapDebugMsg(msg+"\n"+str_detail_result);
          flag=false;
        }
        for(int i=0;i<std::min(A.size(),B.size());i++)
        {
          auto&a=A[i];
          auto&b=B[i];
          bool f[]=
          {
            a.Name==b.Name,
            a.Mode==b.Mode,
            a.Value==b.Value,
          };
          bool flag=true;
          for(int j=0;j<lenof(f);j++)
          {
            flag=flag&&f[j];
          }
          if(flag)
          {
            IsEqualTo<TSPACE> other(Space);
            other.Mute=Mute;
            other.pValue=a.Type.get();
            b.Type.get()->Use(other);
            flag=flag&&other.Result;
          }
          if(!flag)
          {
            if(!Mute)QapDebugMsg("type : \""+fna+"\"");
            return false;
          }
        }
        return flag;
      }
    };
    template<class TYPE>
    class IsEqual:public IDeclareVisitorRTTI{
    public:
      TSPACE&Space;
      TYPE*pInput;
      bool Result;
    bool Mute;
      IsEqual(TSPACE&Space):Space(Space),Result(false),pInput(nullptr),Mute(false){}
    public:
      void Do(DeclareTypeSys*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeSelfPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeAutoPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeWeakPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeHardPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVoidPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeFieldPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVector*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeArray*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeStruct*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
    };
    template<class TYPE>
    static bool IsEqualFunc(TSPACE&Space,TYPE*pInput,DeclareType*pValue,bool Mute)
    {
      static_assert(std::is_same<TSPACE,TServerPtrSpace>::value,"renamed?");
      TServerPtrSpace&space=Space;
      if(pInput==pValue)return true;
      bool fA=space.IsAllowed(pInput->Self.P.SaveID);
      bool fB=space.IsAllowed(pValue->Self.P.SaveID);
      if(!fA||!fB)
      {
        QapDebugMsg("no way");
        return false;
      }
      auto&eA=space[pInput->Self];
      auto&eB=space[pValue->Self];
      EnvItem&A=eA;
      EnvItem&B=eB;
      bool f[]=
      {
        A.ptr_lnk.IsValid(),
        B.ptr_lnk.IsValid(),
        A.ptr.get()==(void*)pInput,
        B.ptr.get()==(void*)pValue,
      };
      QapAssert(f[2]&&f[3]);
      if(f[0]&&f[1])
      {
        bool g0=A.ptr_lnk.get()==B.ptr.get();
        bool g1=B.ptr_lnk.get()==A.ptr.get();
        QapAssert(g0==g1);
        return g0&&g1;
      }
      if(!f[0]&&!f[1])
      {
        QapAssert(!A.system&&!B.system);
        A.system=true;
        B.system=true;
        IsEqual<TYPE> Is(space);
        Is.pInput=pInput;
        Is.Mute=Mute;
        pValue->Use(Is);
        A.system=false;
        B.system=false;
        if(Is.Result||Mute)
        {
          A.ptr_lnk=B.ptr;
          B.ptr_lnk=A.ptr;
        }
        return Is.Result;
      }
      return false;
    }
    static bool IsEqualFuncEx(TSPACE&Space,DeclareType*pInput,DeclareType*pValue)
    {
      IsEqualTo<TSPACE> next(Space);
      next.pValue=pValue;
      pInput->Use(next);
      return next.Result;
    }
    void Do(DeclareTypeSys*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeHardPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVector*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeArray*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeStruct*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
  };
};
class TSmartPtrVisitor:public IVisitorRTTI{
public:
  class ICallBack{
  public:
    virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A)=0;
  };
public:
  ICallBack&CB;
  void*pValue;
  typedef TSmartPtrVisitor SelfClass;
  TSmartPtrVisitor(ICallBack&CB,void*pValue):CB(CB),pValue(pValue){}
  TSmartPtrVisitor(TSmartPtrVisitor&owner,void*pValue):CB(owner.CB),pValue(pValue){}
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
    }
    auto&arr=p->Members;
    static bool debug_flag=false;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
      if(debug_flag)
      {
        string fn=p->GetFullName();
        if(fn=="TType")if(ex.Name=="Factory")do
        {
          TType*pval=(TType*)(void*)pValue;
          string val_fn=pval->GetFullName();
          THardPtr<TType>&value=*(THardPtr<TType>*)(void*)next.pValue;
          auto*ptr=value.P.ptr;
          if(!ptr)break;
          int sid=ptr->SaveID;
          sid=sid+1-1;
        }while(false);
      }
      ex.Type->Use(next);
      if(debug_flag)
      {
        string fn=ex.Type->GetFullName();
        int ksjdlasd=0;
      }
    }
  }
  void Do(TTypeSys*p)
  {
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(pValue,i);
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    for(int i=0;i<Count;i++){
      void*ptr=&((uchar*)pValue)[elemSize*i];
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  virtual void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      SelfClass next(*this,&type);
      p->mType.Type->Use(next);
    }
    auto*ptr=value.get();
    if(ptr&&type)
    {
      SelfClass next(*this,ptr);
      type->Use(next);
    }
  }
  virtual void Do(TTypeWeakPtr*p)
  {
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeHardPtr*p)
  {
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    CB.Visit(value.ptr.P);
  }
  virtual void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    TType*pmObjectType=p->mObject.Type.get();
    {
      SelfClass next(*this,&value.object);
      pmObjectType->Use(next);
    }
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    TType*pmIndexType=p->mIndex.Type.get();
    {
      SelfClass next(*this,&value.offset);
      pmIndexType->Use(next);
    }
  }
  virtual void Do(TTypeFactory*p)
  {
    IFactory&value=*(IFactory*)pValue;
    TSelfPtr<IEsoteric>&Self=*(TSelfPtr<IEsoteric>*)(void*)&value.Self;
    TType*SmartType=p->SmartType.get();
    CB.Visit(Self.P,SmartType);
  }
public:
};
/*
  Увеличивает значение count в ячейке ассоциированной с серверным указателем
  на который ссылается клиенский указатель.
*/
class TClientPtrCounter:public TSmartPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("see TClientPtrUserCallBackCounter");
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  template<template<class> class SmartPtr,class TYPE>
  inline static SmartPtr<IEsoteric>&get(SmartPtr<TYPE>&input)
  {
    static_assert(
      std::is_same<SmartPtr,TClientPtr>::value||
      std::is_same<SmartPtr,THardClientPtr>::value,"error"
    );
    return (SmartPtr<IEsoteric>&)input;
  }
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if(item.passed)return;
    if(item.count)return;
    if(true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType);
      if(trigger)
      {
        auto*pValue=(TType*)item.ptr.get();
        auto&ex=Space[pValue->Self];
        QapAssert(ex.ptr_lnk.IsValid());
        bool good=ex.ptr_lnk.type->IsBasedOn(pDeclareType);
        QapAssert(good);
        bool f[]=
        { 
          pValue->IsBasedOn(pTType),
          pValue->IsBasedOn(pDeclareType)
        };
        auto*pdValue=(DeclareType*)ex.ptr_lnk.get();
        auto&d=Space[pdValue->Self];
        d.count++;
        d.passed=f[0]||f[1];
        item.passed=true;
        return;
      }
      QapAssert(!item.hidden);
      if(safe)
      {
        bool good=pType->IsBasedOn(elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if(!A)return;
    DoVisitSaveID(A.ptr->SaveID,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if(!A)return;
    DoVisitSaveID(A.ptr->SaveID,false,nullptr);
  }
};
class TServerPtrGraber:public TSmartPtrVisitor::ICallBack{
public:
  bool automark;
  int SkipCount;
  int AddCount;
  TServerPtrSpace&Space;
  TServerPtrGraber(TServerPtrSpace&Space,bool automark):Space(Space),automark(automark){AddCount=0;SkipCount=0;}
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
  {
    QapDebugMsg
    (
      "[2014.05.14 12:09]\n"
      "This class can not determine the actual type of the object and is no longer using.\n"
      "Look at 'TServerPtrGraberWithRealType'"
    );
    if(Space.CheckServSaveID(&Serv))
    {
      QapDebugMsg("the way used? ORL?");
      SkipCount++;
      auto&ex=Space[Serv.SaveID];
      if(automark)
      {
        ex.count++;
        ex.passed=true;
      }
      return;
    }
    auto&ex=Space.UnsafeAdd(&Serv,elemType);
    AddCount++;
    if(automark)
    {
      ex.count++;
      ex.passed=true;
    }
  }
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(TClientPtr<IEsoteric>&A){}
  virtual void Visit(THardClientPtr<IEsoteric>&A){}
};
class TServerPtrCounter:public TSmartPtrVisitor::ICallBack{
public:
  int&count;
  TServerPtrCounter(int&count):count(count){}
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){count++;}
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(TClientPtr<IEsoteric>&A){}
  virtual void Visit(THardClientPtr<IEsoteric>&A){}
};
class TClientPtrSolver:public TSmartPtrVisitor::ICallBack{
public:
  struct TwoMetaType
  {
    TType*pTType;
    TType*pDeclareType;
    TwoMetaType(const TwoMetaType&Ref):pTType(nullptr),pDeclareType(nullptr){oper_set(Ref);}
    TwoMetaType():pTType(nullptr),pDeclareType(nullptr){}
    TwoMetaType(IEnvRTTI&Env):pTType(nullptr),pDeclareType(nullptr){prepare(Env);}
    template<class TYPE>
    TwoMetaType(TYPE&ref):pTType(ref.pTType),pDeclareType(ref.pDeclareType)
    {
      static_assert(std::is_same<std::remove_reference<decltype(this->pTType)>::type,std::remove_reference<decltype(ref.pTType)>::type>::value,"no way");
      static_assert(std::is_same<std::remove_reference<decltype(this->pDeclareType)>::type,std::remove_reference<decltype(ref.pDeclareType)>::type>::value,"no way");
    }
    void prepare(IEnvRTTI&Env)
    {
      pTType=Sys$$<TType>::GetRTTI(Env);
      pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    }
    void oper_set(const TwoMetaType&Ref)
    {
      this->pTType=Ref.pTType;
      this->pDeclareType=Ref.pDeclareType;
    }
    void operator=(const TwoMetaType&Ref){oper_set(Ref);}
  };
public:
  typedef TServerPtrSpace TSpace;
  TSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrSolver(TSpace&Space,const TwoMetaType&tmt):Space(Space),pTType(tmt.pTType),pDeclareType(tmt.pDeclareType){}
public:
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)return nullptr;
    if(id<0||id>=Space.size()){QapDebugMsg("Error!\nWrong id:\n"+IToS(id));return nullptr;}
    auto&item=Space[id];
    if(item.ptr.type)
    {
      if(!safe){
        return item.ptr.ptr;
      }
      QapAssert(elemType);
      bool flag=elemType->IsBasedOn(pTType);
      if(!flag)
      {
        int gg=1;
      }
      if(flag)
      {
        bool f[]=
        {
          item.ptr.type->IsBasedOn(pTType),
          item.ptr.type->IsBasedOn(pDeclareType)
        };
        bool good=!f[0]&&f[1];
        if(!good)
        {
          auto*pType=item.ptr.type;
          QapAssert(pType->IsBasedOn(elemType));
          return item.ptr.ptr;
        }
        auto*pdType=(DeclareType*)item.ptr.get();
        auto&ex=Space[pdType->Self];
        QapAssert(ex.ptr_lnk.type);
        QapAssert(ex.ptr_lnk.type->IsBasedOn(pTType));
        auto*pType=ex.ptr_lnk.type;
        auto*pValue=(TType*)ex.ptr_lnk.get();
        QapAssert(pType->IsBasedOn(elemType));
        return EnvAdapter::get(pValue->Self);
      }
      auto*pType=item.ptr.type;
      QapAssert(pType->IsBasedOn(elemType));
      return item.ptr.ptr;
    }else{
      QapDebugMsg("norm");
      return item.ptr.ptr;
    }
    QapDebugMsg("no way.");
    return nullptr;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
};
class TClientPtrKiller:public TSmartPtrVisitor::ICallBack{
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A){
    MegaVisit(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisit(A);
  }
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A)
  {
    if(!A)return;
    A=nullptr;
  }
};
class TDumpPtrSolver:public TSmartPtrVisitor::ICallBack{
public:
  typedef TServerPtrSpace TSpace;
  TSpace&ST_Space;
  TSpace&LT_Space;
  TDumpPtrSolver(TSpace&ST_Space,TSpace&LT_Space):ST_Space(ST_Space),LT_Space(LT_Space){}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(LT_Space[id].system)return ST_Space[id].ptr.ptr;
    return LT_Space[id].ptr.ptr;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
};
class TClientPtrVisitor:public TSmartPtrVisitor::ICallBack{
public:
  struct ICallBack{
    template<class TYPE>
    void DoVisitServerPtr(TServerPtr<TYPE>&Serv,bool safe,TType*elemType){
      DoVisitServerPtr((TServerPtr<IEsoteric>*)&Serv,safe,elemType);
    }
    virtual void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe=false,TType*elemType=nullptr){
      QapDebugMsg("no way.");
    }
  };
public:
  ICallBack&CB;
  TClientPtrVisitor(ICallBack&CB):CB(CB){}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,false,nullptr);
  }
};
class THardClientSpace{
public:
  vector<THardClientPtr<IEsoteric>*> Arr;
  void Do()
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i];
      auto&ex=*it;
      if(ex)ex=nullptr;
    }
  }
};
class THardClientPtrGraber:public TSmartPtrVisitor::ICallBack{
public:
  typedef THardClientSpace TSpace;
  TSpace&Space;
  THardClientPtrGraber(TSpace&Space):Space(Space){}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    Space.Arr.push_back(&A);
  }
  void Visit(TClientPtr<IEsoteric>&A){}
  void Visit(THardClientPtr<IEsoteric>&A){
    Space.Arr.push_back(&A);
  }
public:
};
inline void ClientMarker(TSmartPtrVisitor::ICallBack&ClientCounter,TType*pType,void*pValue)
{
  TSmartPtrVisitor SPG(ClientCounter,pValue);
  pType->Use(SPG);
}
class TServerPtrGraberWithRealType:public IVisitorRTTI{
public:
  typedef TServerPtrGraberWithRealType SelfClass;
  typedef TServerPtrSpace TSpace;
public:
  TSpace&Space;
  void*pValue;
  vector<void*> values;
  vector<TType*> types;
  bool automark;
  int AddCount;
  int SkipCount;
  TServerPtrGraberWithRealType(TSpace&Space,TType*pType,void*pValue,bool automark):Space(Space),pValue(pValue),automark(automark)
  {
    AddCount=0;
    SkipCount=0;
    push(pType);
  }
public:
  void push(TType*pType)
  {
    types.push_back(pType);
  }
  void pop(TType*pType)
  {
    QapAssert(!types.empty());
    QapAssert(pType==types.back());
    types.pop_back();
  }
  void ptr_push(void*ptr)
  {
    values.push_back(pValue);
    pValue=ptr;
  }
  void ptr_pop(void*ptr)
  {
    QapAssert(!values.empty());
    QapAssert(ptr==pValue);
    pValue=values.back();
    values.pop_back();
  }
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      auto*pSubType=p->SubType.get();
      ptr_push(pValue);
      pSubType->Use(*this);
      ptr_pop(pValue);
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=(void*)(ex.Offset+int(pValue));
      auto*exType=ex.Type.get();
      push(exType);
      ptr_push(ptr);
      exType->Use(*this);
      ptr_pop(ptr);
      pop(exType);
    }
  }
  void Do(TTypeSys*p){/*это вообще нас не интересует.*/}
  void Do(TTypeFactory*p){/*это вообще нас не интересует.*/}
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    push(elemType);
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(pValue,i);
      ptr_push(ptr);
      elemType->Use(*this);
      ptr_pop(ptr);
    }
    pop(elemType);
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    push(elemType);
    for(int i=0;i<Count;i++){
      void*ptr=&((uchar*)pValue)[elemSize*i];
      ptr_push(ptr);
      elemType->Use(*this);
      ptr_pop(ptr);
    }
    pop(elemType);
  }
  void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    auto&Serv=value.P;
    if(Space.CheckServSaveID(&Serv))
    {
      QapDebugMsg("the way used? ORL?");
      SkipCount++;
      auto&ex=Space[Serv.SaveID];
      if(automark)
      {
        ex.count++;
        ex.passed=true;
      }
      return;
    }
    QapAssert(types.size()>=2);
    auto*pElemType=p->ElementType.get();
    auto*type=types[types.size()-2];
    QapAssert(TTypeSelfPtr::UberCast(types.back()));
    QapAssert(type->IsBasedOn(pElemType));
    auto&ex=Space.UnsafeAdd(&Serv,type);
    AddCount++;
    if(automark)
    {
      ex.count++;
      ex.passed=true;
    }
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      auto*ptr=(void*)&type;
      auto*pmTypeType=p->mType.Type.get();
      ptr_push(ptr);
      pmTypeType->Use(*this);
      ptr_pop(ptr);
    }
    auto*ptr=value.get();
    auto*pType=type.get();
    push(pType);
    if(ptr&&type)
    {
      ptr_push(ptr);
      pType->Use(*this);
      ptr_pop(ptr);
    }
    pop(pType);
  }
  void Do(TTypeWeakPtr*p){/*это вообще нас не интересует.*/}
  void Do(TTypeHardPtr*p){/*это вообще нас не интересует.*/}
  void Do(TTypeVoidPtr*p){/*это вообще нас не интересует.*/}
  void Do(TTypeFieldPtr*p){/*это вообще нас не интересует.*/}
};
inline void GrabServerPtr(TServerPtrSpace&Space,TType*pType,void*pValue,bool automark)
{
  TServerPtrGraberWithRealType SPGWRT(Space,pType,pValue,automark);
  pType->Use(SPGWRT);
  return;
}
class TClientPtrVcbCounter:public TClientPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrVcbCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if(item.passed)return;
    if(item.count)return;
    if(true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType);
      if(trigger)
      {
        auto*pValue=(TType*)item.ptr.get();
        auto&ex=Space[pValue->Self];
        QapAssert(ex.ptr_lnk.IsValid());
        bool good=ex.ptr_lnk.type->IsBasedOn(pDeclareType);
        QapAssert(good);
        bool f[]=
        { 
          pValue->IsBasedOn(pTType),
          pValue->IsBasedOn(pDeclareType)
        };
        auto*pdValue=(DeclareType*)ex.ptr_lnk.get();
        auto&d=Space[pdValue->Self];
        d.count++;
        d.passed=f[0]||f[1];
        item.passed=true;
        return;
      }
      QapAssert(!item.hidden);
      if(safe)
      {
        bool good=EnvAdapter::IsBasedOn(pType,elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if(!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};
class TClientPtrVcbCounter20120828:public TClientPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  bool firstmode;
  TClientPtrVcbCounter20120828(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr),firstmode(true)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if(item.passed)return;
    if(item.count)return;
    if(item.system)return;
    if(true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType)||pType->IsBasedOn(pDeclareType);
      if(trigger)
      {
        int gg=1;
      }
      QapAssert(!item.hidden);
      if(safe)
      {
        bool good=EnvAdapter::IsBasedOn(pType,elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if(!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};
class DependsSolver{
public:
  typedef TServerPtrSpace TSpace;
  TClientPtrVisitor&CPC;
  TType*pTType;
  TType*pDeclareType;
  vector<int> Arr;
  bool fullprocess;
  DependsSolver(IEnvRTTI&Env,TClientPtrVisitor&CPC):CPC(CPC)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    fullprocess=false;
  }
  void prepare(TSpace&Space,bool force)
  {
    Arr.clear();
    for(int i=0;i<Space.size();i++)
    {
      auto&item=Space[i];
      if(item.hidden)QapAssert(item.system);
      bool skip=item.system||item.passed||!item.count;
      if(skip)continue;
      if(false)
      {
        bool skip=item.ptr.type->IsBasedOn(pTType);
        if(skip)
        {
          int gg=1;
          continue;
        }
      }
      if(!fullprocess)
      {
        bool skip=item.ptr.type->IsBasedOn(pDeclareType);
        if(skip)
        {
          QapDebugMsg("WTF?");
          continue;
        }
      }
      Arr.push_back(item.id);
    }
  }
  void pass(TSpace&Space,const TRawPtr&ptr)
  {
    TType*pType=ptr.pType;
    void*pValue=ptr.pValue;
    if(true)
    {
      int sid=pType->Self.P.SaveID;
      QapAssert(sid);
      CPC.CB.DoVisitServerPtr(pType->Self.P,true,pTType);
    }
    ClientMarker(CPC,pType,pValue);
  }
  TRawPtr get(const EnvVoidPtr&ptr)
  {
    TRawPtr tmp;
    tmp.pType=ptr.type;
    tmp.pValue=ptr.get();
    return tmp;
  }
  void step(TSpace&Space)
  {
    for(int i=0;i<Arr.size();i++)
    {
      int id=Arr[i];
      if(!id)continue;
      auto&item=Space[id];
      QapAssert(!item.system);
      if(!item.ptr.type)
      {
        QapAssert(item.passed&&item.ptr.type);
        item.passed=true;
        continue;
      }
      if(!fullprocess)
      {
        bool skip=item.ptr.type->IsBasedOn(pDeclareType);
        if(skip)
        {
          QapDebugMsg("WTF?");
          continue;
        }
      }
      pass(Space,get(item.ptr));
      item.passed=true;
    }
  }
  void SolveDepends(TSpace&Space,bool fullprocess=true)
  {
    this->fullprocess=fullprocess;
    prepare(Space,false);
    for(int loop_counter=0;!Arr.empty()&&(loop_counter<1024);loop_counter++)
    {
      step(Space);
      prepare(Space,false);
    }
    QapAssert(Arr.empty());
    QapAssert(Space[0].count>0);
    this->fullprocess=false;
  }
};
template<class TYPE>
class Sys$$<vector<TYPE>>{
public:
  typedef TTypeVector metatype;
  typedef vector<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="vector";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->SizeType=Sys$$<IVectorAPI::SizeType>::GetRTTI(RTTI);
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->VecAPI=TVectorAPI<elemtype>::Get();
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "vector<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE,size_t Count>
class Sys$$<array<TYPE,Count>>{
public:
  typedef TTypeArray metatype;
  typedef array<TYPE,Count> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="array";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->Size=Count;
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "array<"+Sys$$<TYPE>::GetFullName()+","+IToS(Count)+">";
  }
};
template<class TYPE>
class Sys$$<TFactory<TYPE>>{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFactory";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->SubType=detail::GetParentClassOf<type>::GetRTTI(RTTI);
    typedef TSelfPtr<IFactory> SmartType;
    {
      typedef decltype((((type*)nullptr)->*(&type::Self))) realtype;
      typedef std::remove_reference<realtype>::type fieldtype;
      static_assert(std::is_same<SmartType,fieldtype>::value,"ok");
    }
    Info->SmartType=Sys$$<SmartType>::GetRTTI(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFactory<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TFactory<TFactory<TYPE>>>{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TFactory<TYPE>> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    QapDebugMsg("WTF?");
    static string Name="TFactory";
    static metatype sys;
    static bool flag=true;
    if(flag){
      sys.Info.Name=Name;
      sys.Info.Size=sizeof(Name);
      flag=false;
    }
    return &sys;
  }
  static string GetFullName()
  {
    return "TFactory<TFactory<"+Sys$$<TYPE>::GetFullName()+">>";
  }
};
template<class TYPE>
class Sys$$<TSelfPtr<TYPE>>{
public:
  typedef TTypeSelfPtr metatype;
  typedef TSelfPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TSelfPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TSelfPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TAutoPtr<TYPE>>{
public:
  typedef TTypeAutoPtr metatype;
  typedef TAutoPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TAutoPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TAutoPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<TWeakPtr<TYPE>>{
public:
  typedef TTypeWeakPtr metatype;
  typedef TWeakPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TWeakPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TWeakPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<class TYPE>
class Sys$$<THardPtr<TYPE>>{
public:
  typedef TTypeHardPtr metatype;
  typedef THardPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="THardPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "THardPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};
template<>
class Sys$$<TVoidPtr>{
public:
  typedef TTypeVoidPtr metatype;
  typedef TVoidPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TVoidPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TVoidPtr";
  }
};
template<>
class Sys$$<TFieldPtr>{
public:
  typedef TTypeFieldPtr metatype;
  typedef TFieldPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFieldPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFieldPtr";
  }
};
template<>
class TTxtIO<uint>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef uint type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=std::to_string(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    val=std::stoul(s);
  }
};
template<>
class TTxtIO<int>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef int type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    val=SToI(s);
  }
};
template<>
class TTxtIO<real>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef real type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    SToF(s,val);
  }
};
template<>
class TTxtIO<float>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef float type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    real tmp;
    SToF(s,tmp);
    val=tmp;
  }
};
template<>
class TTxtIO<bool>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef bool type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=BToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    SToB(s,val);
  }
};
template<>
class TTxtIO<char>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef char type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    if(CppString::IsValidCppChar(val)){
      char out[4]={'\'',val,'\'',0};
      s=out;
    }else{
      string tmp=CToH_raw(val);
      s="'\\x"+tmp+"'";
    }
  }
  void Load(string&s,void*p){
    QapDebugMsg("under construction");return;
    type&val=*(type*)p;
    SToC(s,val);
  }
};
template<>
class TTxtIO<uchar>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef uchar type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p){
    QapDebugMsg("under construction");return;
    type&val=*(type*)p;
    val=SToI(s);
  }
};
template<>
class TBinIO<string>:public IBinIO{
public:
  typedef IBinIO ParentClass;
  typedef string type;
  typedef TBinIO<type> SelfClass;
public:
  void Save(QapIO&IO,void*p){
    type&val=*(type*)p;
    int count=val.size();
    IO.SavePOD(&count,sizeof(count));
    if(!count)return;
    IO.SavePOD(&val[0],count);
  }
  void Load(QapIO&IO,void*p){
    type&val=*(type*)p;
    int count=0;
    if(!IO.TryLoad(sizeof(count)))
    {
      IO.Crash();
      return;
    }
    IO.LoadPOD(&count,sizeof(count));
    if(!IO.TryLoad(count))
    {
      IO.Crash();
      return;
    }
    val.resize(count);
    if(!count)return;
    IO.LoadPOD(&val[0],count);
  }
public:
  void Copy(void*pOut,void*pInp){
    string&out=*(string*)pOut;
    string&inp=*(string*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB){
    string&a=*(string*)pA;
    string&b=*(string*)pB;
    return a==b;
  }
};
template<>
class TTxtIO<string>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef string type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    CppString cs=val;
    s="\""+cs.data+"\"";
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    if(s.size()<2){QapDebugMsg("WTF?");return;}
    bool flag1=s.front()=='"';
    bool flag2=s.back()=='"';
    if(!flag1||!flag2){
      QapDebugMsg("WTF?");return;
    }
    val=s.substr(1,int(s.size())-2);
    BinString bs=val;
    val=bs.data;
  }
};
  template<> class Sys$$<uint>{ public: typedef TTypeSys metatype; typedef uint type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="uint"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "uint"; } };
  template<> class Sys$$<int>{ public: typedef TTypeSys metatype; typedef int type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="int"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "int"; } };
  template<> class Sys$$<real>{ public: typedef TTypeSys metatype; typedef real type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="real"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "real"; } };
  template<> class Sys$$<float>{ public: typedef TTypeSys metatype; typedef float type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="float"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "float"; } };
  template<> class Sys$$<bool>{ public: typedef TTypeSys metatype; typedef bool type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="bool"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "bool"; } };
  template<> class Sys$$<char>{ public: typedef TTypeSys metatype; typedef char type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="char"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "char"; } };
  template<> class Sys$$<uchar>{ public: typedef TTypeSys metatype; typedef uchar type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="uchar"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "uchar"; } };
  template<> class Sys$$<string>{ public: typedef TTypeSys metatype; typedef string type; template<class QAP_RTTI> static metatype*GetRTTI(QAP_RTTI&RTTI){ metatype*Info=nullptr; string Name="string"; if(RTTI.Register<type>(Info,Name))return Info; Info->BinIO=THeadBinIO<type>::Get(); Info->TxtIO=THeadCppIO<type>::Get(); Info->Info.Size=sizeof(type); RTTI.OnRegEnd(Info); return Info; }; static string GetFullName() { return "string"; } };
class TPrinter{
public:
  string&s;
  string indent;
  string sep;
  TPrinter(string&s):s(s){sep=" = ";}
public:
  virtual void Indent(){indent+="  ";}
  virtual void Outdent(){indent.resize(max(0,indent.size()-2));}
  virtual void Print(string const&data){s+=indent+data+"\n";}
};
class TMessage{
public:
  public:typedef TMessage SelfClass;
  public:
  TWeakPtr<TType> type;
  int mode;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->type);(this->mode)=(mmRet);
    }
  public:
    TMessage(const TMessage&)=delete;TMessage(){DoReset();};
  public:
    TMessage(TMessage&&_Right){operator=(std::move(_Right));}
    void operator=(TMessage&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->type=std::move(_Right.type);
  this->mode=std::move(_Right.mode);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TMessage";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TWeakPtr<TType>>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"mode",int(&(((SelfClass*)nullptr)->*(&SelfClass::mode))),"SET","mmRet");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TMessage";
      }
    };
  public:
public:
  enum TMode{
    mmBeg,
    mmRet,
    mmEnd
  };
};
class EnvTypeHolder{
public:
  public:typedef EnvTypeHolder SelfClass;
  public:
  string FullName;
  TProduct Type;
  TProduct Factory;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->FullName);detail::FieldTryDoReset(this->Type);detail::FieldTryDoReset(this->Factory);
    }
  public:
    EnvTypeHolder(const EnvTypeHolder&)=delete;EnvTypeHolder(){DoReset();};
  public:
    EnvTypeHolder(EnvTypeHolder&&_Right){operator=(std::move(_Right));}
    void operator=(EnvTypeHolder&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->FullName=std::move(_Right.FullName);
  this->Type=std::move(_Right.Type);
  this->Factory=std::move(_Right.Factory);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="EnvTypeHolder";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"FullName",int(&(((SelfClass*)nullptr)->*(&SelfClass::FullName))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TProduct>::GetRTTI(RTTI),"Type",int(&(((SelfClass*)nullptr)->*(&SelfClass::Type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TProduct>::GetRTTI(RTTI),"Factory",int(&(((SelfClass*)nullptr)->*(&SelfClass::Factory))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "EnvTypeHolder";
      }
    };
  public:
public:
  static void hack_move(TProduct&out,TRTTIProduct&inp)
  {
    out.Alloc=inp.GetAlloc();
    out.Factory=inp.GetFactory();
    out.Memory=std::move(inp.Memory);
    inp.pType=nullptr;
  }
  void eat(EnvType&item)
  {
    FullName=item.Type->GetFullName();
    hack_move(Type,item.Type.Product);
    if(item.Factory)hack_move(Factory,item.Factory.Product);
  }
  void boom()
  {
    Type.Free();
    if(Factory)Factory.Free();
  }
  TType*GetType(){return (TType*)Type.Memory.ptr;}
  IFactory*GetFactory(){return (IFactory*)Factory.Memory.ptr;}
};
class TEnvRTTI:public IEnvRTTI{
public:
  public:typedef TEnvRTTI SelfClass;public:typedef IEnvRTTI ParentClass;
  public:
  vector<EnvType> Arr;
  THardPtr<IAllocator> Alloc;
  UniqueID ID;
  vector<TMessage> messages;
  THardPtr<IEnvRTTI> OwnerEnv;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Arr);detail::FieldTryDoReset(this->Alloc);detail::FieldTryDoReset(this->ID);detail::FieldTryDoReset(this->messages);detail::FieldTryDoReset(this->OwnerEnv);
    }
  public:
    TEnvRTTI(const TEnvRTTI&)=delete;TEnvRTTI(){DoReset();};
  public:
    TEnvRTTI(TEnvRTTI&&_Right){operator=(std::move(_Right));}
    void operator=(TEnvRTTI&&_Right)
    {
      struct hidden{static void foo(IEnvRTTI(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        IEnvRTTI::operator=(std::move(_Right));
      }
  this->Arr=std::move(_Right.Arr);
  this->Alloc=std::move(_Right.Alloc);
  this->ID=std::move(_Right.ID);
  this->messages=std::move(_Right.messages);
  this->OwnerEnv=std::move(_Right.OwnerEnv);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TEnvRTTI";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<EnvType>>::GetRTTI(RTTI),"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IAllocator>>::GetRTTI(RTTI),"Alloc",int(&(((SelfClass*)nullptr)->*(&SelfClass::Alloc))),"DEF","$");
  Info->AddMemberDEF(Sys$$<UniqueID>::GetRTTI(RTTI),"ID",int(&(((SelfClass*)nullptr)->*(&SelfClass::ID))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<TMessage>>::GetRTTI(RTTI),"messages",int(&(((SelfClass*)nullptr)->*(&SelfClass::messages))),"DEF","$");
  Info->AddMemberDEF(Sys$$<THardPtr<IEnvRTTI>>::GetRTTI(RTTI),"OwnerEnv",int(&(((SelfClass*)nullptr)->*(&SelfClass::OwnerEnv))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TEnvRTTI";
      }
    };
  public:
public:
  static void SysHasSelf();
public:
  string GetTypeFullNames()
  {
    string tmp;
    for(int i=0;i<Arr.size();i++)
    {
      if(i)tmp+=",\n";
      tmp+=Arr[i].Type->GetFullName();
    }
    return std::move(tmp);
  }
  void PrintLog(const string&fn="outlog.cpp")
  {
    CrutchIO io;
    TPrinter printer(io.mem);
    for(int i=0;i<messages.size();i++)
    {
      TMessage&EX=messages[i];
      TType*Info=EX.type.get();
      if(EX.mode==TMessage::mmBeg){
        printer.Print("Register(\""+Info->GetFullName()+"\")");
        printer.Print("{");
        printer.Indent();
      }
      if(EX.mode==TMessage::mmRet){
        printer.Print("Ret(\""+Info->GetFullName()+"\");");
      }
      if(EX.mode==TMessage::mmEnd){
        printer.Outdent();
        printer.Print("}//"+Info->GetFullName());
      }
    }
    io.SaveFile(fn);
  }
  void OnRegBeg(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmBeg;
    messages.emplace_back(std::move(tmp));
  };
  void OnRegRet(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmRet;
    messages.emplace_back(std::move(tmp));
  };
  void OnRegEnd(TType*Info){
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmEnd;
    messages.emplace_back(std::move(tmp));
  };
public:
  IAllocator*GetAlloc(){return Alloc.get();}
  virtual int RegInfo(TAutoPtr<TType>&&_Right)
  {
    EnvType tmp;
    tmp.Type=std::move(_Right);
    Arr.push_back(std::move(tmp));
    return Arr.size()-1;
  }
  virtual EnvType&GetEnvTypeById(int id)
  {
    return Arr[id];
  }
  virtual vector<EnvType>&GetArr(){
    return Arr;
  }
  ~TEnvRTTI(){clear();}
public:
  IEnvRTTI*GetOwnerEnv()
  {
    return OwnerEnv.get();
  }
public:
  void update()
  {
    QapCleanIf(Arr,[](EnvType&ex){return !ex.Type;});
  }
  bool IsValid()
  {
    for(int i=Arr.size()-1;i>=0;i--)
    {
      auto&ex=Arr[i].Type;
      if(!ex)
      {
        int temp=0;
        QapDebugMsg("fail");
        return false;
      }
    }
    return true;
  }
  void clear()
  {
    if(!IsValid())
    {
      QapDebugMsg("fail");
      update();
      QapAssert(IsValid());
    }
    unlink();
    int skip_count=0;
    for(int i=Arr.size()-1;i>=0;i=i?--i:i=Arr.size()-1)
    {
      skip_count++;
      auto&item=Arr[i];
      TAutoPtr<TType>&ex=item.Type;
      auto&nm=ex->Info.Name;
      auto&fn=ex->GetFullName();
      bool skip=!ex->CanDestroy();
      if(skip&&skip_count>Arr.size())break;
      if(skip)continue;
      item.Type=nullptr;
      item.Factory=nullptr;
      std::swap(item,Arr.back());
      Arr.pop_back();
      skip_count=0;
    }
    if(!Arr.empty())
    {
      PrintCur();
      QapAssert(Arr.empty());
      Arr.clear();
    }
  }
  static inline bool IsLegalChar(const unsigned char&c){
    return InDip<char>('a',c,'z')||InDip<char>('A',c,'Z')||InDip<char>('0',c,'9');
  }
  static string string2xml(const string&str)
  {
    string tmp;tmp.reserve(str.size()*3);
    for(int i=0;i<str.size();i++){
      tmp+=IsLegalChar(str[i])?CToS(str[i]):"&#"+IToS(str[i])+";";
    }
    return std::move(tmp);
  }
  void PrintCur()
  {
    for(int i=0;i<Arr.size();i++)
    {
      TAutoPtr<TType>&EX=Arr[i].Type;
      TType*pVal=EX.get();
      TType*pType=EX.Product.GetType();
      IAllocator*pAlloc=EX.Product.GetAlloc();
      IFactory*pFactory=EX.Product.GetFactory();
      auto&fn=EX->GetFullName();
    }
  }
  static void add_sniper_job(THardClientSpace&Space,TRawPtr&raw_ptr)
  {
    THardClientPtrGraber Graber(Space);
    TSmartPtrVisitor CPG(Graber,raw_ptr.pValue);
    raw_ptr.pType->Use(CPG);
  }
  void unlink()
  {
    if(Arr.empty())return;
    THardClientSpace Space;
    for(int i=0;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      TRawPtr type(item.Type.Product.pType.get(),item.Type.get());
      add_sniper_job(Space,type);
      if(!item.Factory)continue;
      TRawPtr fact(item.Factory.Product.pType.get(),item.Factory.get());
      add_sniper_job(Space,fact);
    }
    vector<EnvTypeHolder> holders;
    holders.resize(Arr.size());
    for(int i=0;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      auto&holder=holders[i];
      holder.eat(item);
    };
    Arr.clear();
    Space.Do();
    int skip_count=0;
    for(int i=int(holders.size())-1;skip_count<=int(holders.size());skip_count++,i=(!i?holders.size()-1:i-1))
    {
      auto&holder=holders[i];
      auto*pType=holder.GetType();
      bool skip=!pType->CanDestroy();
      if(skip)
      {
        QapDebugMsg("type : '"+holder.FullName+"'\nWTF?");
        continue;
      }
      holders[i].boom();
      std::swap(holder,holders.back());
      holders.pop_back();
      skip_count=0;
    }
    if(!holders.empty())
    {
      for(int i=0;i<holders.size();i++)
      {
        auto&holder=holders[i];
        auto&fn=holder.FullName;
        TType*pType=holder.GetType();
        int hc=pType->Self.P.HardCount;
      }
      bool please_no=true;
      QapAssert(holders.empty());
      holders.clear();
    }
  }
};
static TType*FindTypeByFullName(IEnvRTTI&Env,const string&FullName)
{
  auto&arr=Env.GetArr();
  for(int i=0;i<arr.size();i++)
  {
    auto*p=arr[i].Type.get();
    if(p->GetFullName()==FullName)
    {
      return p;
    }
  }
  return nullptr;
}
class QapBitmapInfo{
public:
  BITMAPINFO BI;
  BITMAPINFOHEADER&BH;
public:
  QapBitmapInfo(int W,int H):BH(BI.bmiHeader){
    ZeroMemory(&BI,sizeof(BI));
    BH.biSize=sizeof(BI.bmiHeader);
    BH.biWidth=W;BH.biHeight=H;
    BH.biPlanes=1;BH.biBitCount=32;
    BH.biSizeImage=W*H*4;
  }
};
class FastBMP{
public:
  int W;
  int H;
  HDC MDC;
  QapColor*mem;
  HBITMAP BMP;
public:
  void Init(HDC DC,int W,int H)
  {
    this->H=H;
    this->W=W;
    MDC=CreateCompatibleDC(DC);
    BMP=CreateCompatibleBitmap(DC,W,H);
    RECT Rect;
    SetRect(&Rect,0,0,W,H);
    SelectObject(MDC,BMP);
    FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
    mem=new QapColor[W*H];
    QapBitmapInfo QBI(W,H);
    GetDIBits(MDC,BMP,0,H,mem,&QBI.BI,DIB_RGB_COLORS);
  }
  void Free()
  {
    QapAssert(DeleteObject(BMP));
    QapAssert(DeleteDC(MDC));
    delete[] mem;
  }
};
#pragma once
/*==========================================================================;
 *
 *  Copyright (C) Microsoft Corporation.  All Rights Reserved.
 *
 *  File:   d3d9.h
 *  Content:    Direct3D include file
 *
 ****************************************************************************/
struct QapMat4:public D3DMATRIX
{
public:
	QapMat4(){}
	QapMat4(
     const float m00, const float m01, const float m02, const float m03,
		 const float m10, const float m11, const float m12, const float m13,
		 const float m20, const float m21, const float m22, const float m23,
		 const float m30, const float m31, const float m32, const float m33
  )
  {
      {{m[0][0]=m00;};{m[0][1]=m01;};{m[0][2]=m02;};{m[0][3]=m03;};};
      {{m[1][0]=m10;};{m[1][1]=m11;};{m[1][2]=m12;};{m[1][3]=m13;};};
      {{m[2][0]=m20;};{m[2][1]=m21;};{m[2][2]=m22;};{m[2][3]=m23;};};
      {{m[3][0]=m30;};{m[3][1]=m31;};{m[3][2]=m32;};{m[3][3]=m33;};};
	}
public:
  friend QapMat4 operator+(const QapMat4&m,const QapMat4&n){
    QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=m.m[i][j]+n.m[i][j]; return O;
  }
  friend QapMat4 operator-(const QapMat4&m,const QapMat4&n){
    QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=m.m[i][j]-n.m[i][j]; return O;
  }
  friend QapMat4 operator-(const QapMat4&m){
	  QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=-m.m[i][j]; return O;
  }
  friend QapMat4 operator*(const QapMat4&m,const QapMat4&n){
	  return QapMat4(
		  (m.m[0][0]*n.m[0][0]+m.m[0][1]*n.m[1][0]+m.m[0][2]*n.m[2][0]+m.m[0][3]*n.m[3][0]),(m.m[0][0]*n.m[0][1]+m.m[0][1]*n.m[1][1]+m.m[0][2]*n.m[2][1]+m.m[0][3]*n.m[3][1]),(m.m[0][0]*n.m[0][2]+m.m[0][1]*n.m[1][2]+m.m[0][2]*n.m[2][2]+m.m[0][3]*n.m[3][2]),(m.m[0][0]*n.m[0][3]+m.m[0][1]*n.m[1][3]+m.m[0][2]*n.m[2][3]+m.m[0][3]*n.m[3][3]),
		  (m.m[1][0]*n.m[0][0]+m.m[1][1]*n.m[1][0]+m.m[1][2]*n.m[2][0]+m.m[1][3]*n.m[3][0]),(m.m[1][0]*n.m[0][1]+m.m[1][1]*n.m[1][1]+m.m[1][2]*n.m[2][1]+m.m[1][3]*n.m[3][1]),(m.m[1][0]*n.m[0][2]+m.m[1][1]*n.m[1][2]+m.m[1][2]*n.m[2][2]+m.m[1][3]*n.m[3][2]),(m.m[1][0]*n.m[0][3]+m.m[1][1]*n.m[1][3]+m.m[1][2]*n.m[2][3]+m.m[1][3]*n.m[3][3]),
		  (m.m[2][0]*n.m[0][0]+m.m[2][1]*n.m[1][0]+m.m[2][2]*n.m[2][0]+m.m[2][3]*n.m[3][0]),(m.m[2][0]*n.m[0][1]+m.m[2][1]*n.m[1][1]+m.m[2][2]*n.m[2][1]+m.m[2][3]*n.m[3][1]),(m.m[2][0]*n.m[0][2]+m.m[2][1]*n.m[1][2]+m.m[2][2]*n.m[2][2]+m.m[2][3]*n.m[3][2]),(m.m[2][0]*n.m[0][3]+m.m[2][1]*n.m[1][3]+m.m[2][2]*n.m[2][3]+m.m[2][3]*n.m[3][3]),
		  (m.m[3][0]*n.m[0][0]+m.m[3][1]*n.m[1][0]+m.m[3][2]*n.m[2][0]+m.m[3][3]*n.m[3][0]),(m.m[3][0]*n.m[0][1]+m.m[3][1]*n.m[1][1]+m.m[3][2]*n.m[2][1]+m.m[3][3]*n.m[3][1]),(m.m[3][0]*n.m[0][2]+m.m[3][1]*n.m[1][2]+m.m[3][2]*n.m[2][2]+m.m[3][3]*n.m[3][2]),(m.m[3][0]*n.m[0][3]+m.m[3][1]*n.m[1][3]+m.m[3][2]*n.m[2][3]+m.m[3][3]*n.m[3][3])
    );
  }
  friend QapMat4 operator*(const QapMat4 &m,float x){
    QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=x*m.m[i][j]; return O;
  }
};
inline QapMat4 Transpose(const QapMat4&m)
{
	return QapMat4(
		m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
		m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
		m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
		m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
  );
}
inline QapMat4 RotateZ(float angle)
{
  float c=cosf(angle),s=sinf(angle);
  return QapMat4(
    +c,+s,+0,+0,
    -s,+c,+0,+0,
    +0,+0,+1,+0,
    +0,+0,+0,+1
  );
}
inline QapMat4 Translate(const float x,const float y,const float z)
{
  return QapMat4(
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    x,y,z,1
  );
}
inline QapMat4 Scale(const float x,const float y,const float z)
{
  return QapMat4(
    x,0,0,0,
    0,y,0,0,
    0,0,z,0,
    0,0,0,1
  );
}
inline QapMat4 Identity4()
{
	return QapMat4(
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  );
}
class QapD3DPresentParameters{
public:
  public:typedef QapD3DPresentParameters SelfClass;
  public:
  D3DPRESENT_PARAMETERS pp;
    public:
    void DoReset()
    {
      {
      }
  (this->pp)=(Zero(pp));
    }
  public:
    QapD3DPresentParameters(const QapD3DPresentParameters&)=delete;QapD3DPresentParameters(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapD3DPresentParameters";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYS(0,nullptr,"pp",int(&(((SelfClass*)nullptr)->*(&SelfClass::pp))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapD3DPresentParameters";
      }
    };
  public:
public:
  template<class TYPE>
  static TYPE&Zero(TYPE&inout)
  {
    ZeroMemory(&inout,sizeof(inout));
    return inout;
  }
  D3DPRESENT_PARAMETERS&SetToDef(HWND hWnd,bool VSync=true)
  {
    Zero(pp);
    TScreenMode SM=GetScreenMode();
    pp.BackBufferWidth=SM.W;
    pp.BackBufferHeight=SM.H;
    pp.BackBufferFormat=D3DFMT_X8R8G8B8;
    pp.BackBufferCount=1;
    pp.SwapEffect=D3DSWAPEFFECT_COPY;
    pp.PresentationInterval=VSync?D3DPRESENT_INTERVAL_ONE:D3DPRESENT_INTERVAL_IMMEDIATE;
    pp.hDeviceWindow=hWnd;
    pp.Windowed=true;
    pp.FullScreen_RefreshRateInHz=pp.Windowed?0:SM.Freq;
    return pp;
  }
};
class QapD3D9{
public:
  public:typedef QapD3D9 SelfClass;
  public:
  IDirect3D9* pD3D;
    public:
    void DoReset()
    {
      {
      }
  (this->pD3D)=(nullptr);
    }
  public:
    QapD3D9(const QapD3D9&)=delete;QapD3D9(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapD3D9";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
            Info->extInfo.PoorDesign=true;
        }
  Info->AddMemberSYS(0,nullptr,"pD3D",int(&(((SelfClass*)nullptr)->*(&SelfClass::pD3D))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapD3D9";
      }
    };
  public:
public:
  QapD3D9(QapD3D9&&Ref){
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3D9(){Free();}
public:
  void oper_set(QapD3D9&&Ref){
    Free();
    this->pD3D=Ref.pD3D;
    Ref.pD3D=nullptr;
  }
public:
  void operator=(QapD3D9&&Ref){
    oper_set(std::move(Ref));
  }
public:
  void Init()
  {
    Free();
    pD3D=Direct3DCreate9(D3D_SDK_VERSION);
    if(!pD3D)
    {
      QapDebugMsg("Cannot create Direct3D9");
      return;
    }
  }
  void Free()
  {
    if(pD3D)pD3D->Release();
  }
};
class QapD3D9Resource{
public:
  virtual void OnLost()=0;
  virtual void OnReset()=0;
};
class QapD3D9ResourceList{
public:
  public:typedef QapD3D9ResourceList SelfClass;
  public:
  vector<QapD3D9Resource*> Arr;
  bool Lost;
    public:
    void DoReset()
    {
      {
      }
  (this->Arr)=(vector<QapD3D9Resource*>());(this->Lost)=(false);
    }
  public:
    QapD3D9ResourceList(const QapD3D9ResourceList&)=delete;QapD3D9ResourceList(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapD3D9ResourceList";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYS(0,nullptr,"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Lost",int(&(((SelfClass*)nullptr)->*(&SelfClass::Lost))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapD3D9ResourceList";
      }
    };
  public:
public:
  QapD3D9ResourceList(QapD3D9ResourceList&&Ref){
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3D9ResourceList(){Free();}
public:
  void oper_set(QapD3D9ResourceList&&Ref){
    Free();
    {this->Arr=std::move(Ref.Arr);}
    {this->Lost=std::move(Ref.Lost);}
  }
public:
  void operator=(QapD3D9ResourceList&&Ref){
    oper_set(std::move(Ref));
  }
public:
  void Free()
  {
    Lost=false;
    QapAssert(Arr.empty());
  }
public:
  void OnLost()
  {
    Lost=true;
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex->OnLost();   
    }
  }
  void OnReset()
  {
    Lost=false;
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex->OnReset();   
    }
  }
public:
  bool HasRes(QapD3D9Resource*pRes,int*pIndex=nullptr)
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      if(ex!=pRes)continue;
      if(pIndex)*pIndex=i;
      return true;
    }
    if(pIndex)*pIndex=-1;
    return false;
  }
  void Reg(QapD3D9Resource*pRes)
  {
    QapAssert(bool(pRes));
    QapAssert(!HasRes(pRes));
    Arr.push_back(pRes);
  }
  void UnReg(QapD3D9Resource*pRes)
  {
    int i=-1;
    bool flag=HasRes(pRes,&i);
    if(!flag){
      QapAssert(flag);
      return;
    }
    std::swap(Arr[i],Arr.back());
    Arr.pop_back();
  }
};
class QapD3DDev9{
public:
  public:typedef QapD3DDev9 SelfClass;
  public:
  QapD3DPresentParameters PresParams;
  IDirect3DDevice9* pDev;
  QapD3D9ResourceList Resources;
    public:
    void DoReset()
    {
      {
      }
  (this->PresParams)=(QapD3DPresentParameters());(this->pDev)=(nullptr);(this->Resources)=(QapD3D9ResourceList());
    }
  public:
    QapD3DDev9(const QapD3DDev9&)=delete;QapD3DDev9(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapD3DDev9";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYS(0,nullptr,"PresParams",int(&(((SelfClass*)nullptr)->*(&SelfClass::PresParams))),"SYS");
  Info->AddMemberSYS(0,nullptr,"pDev",int(&(((SelfClass*)nullptr)->*(&SelfClass::pDev))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Resources",int(&(((SelfClass*)nullptr)->*(&SelfClass::Resources))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapD3DDev9";
      }
    };
  public:
public:
  QapD3DDev9(QapD3DDev9&&Ref){
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3DDev9(){Free();}
public:
  void oper_set(QapD3DDev9&&Ref){
    Free();
    {this->PresParams=std::move(Ref.PresParams);}
    {this->pDev=std::move(Ref.pDev);Ref.pDev=nullptr;}
    {this->Resources=std::move(Ref.Resources);}
  }
public:
  void operator=(QapD3DDev9&&Ref){
    oper_set(std::move(Ref));
  }
public:
  void Init(HWND hWnd,QapD3D9&D3D)
  {
    QapAssert(D3D.pD3D);
    Free();
    D3D.pD3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&PresParams.pp,&pDev);
    if(!pDev)
    {
      QapDebugMsg("Cannot create Direct3DDevice9");
      return;
    }
  }
  void Free()
  {
    if(pDev)pDev->Release();
  }
public:
  void ResetStates()
  {
    pDev->SetRenderState(D3DRS_LIGHTING,false);
    pDev->SetRenderState(D3DRS_ZENABLE,false);
    pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
    pDev->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
    pDev->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
    pDev->SetSamplerState(0,D3DSAMP_ADDRESSU,D3DTADDRESS_WRAP);
    pDev->SetSamplerState(0,D3DSAMP_ADDRESSV,D3DTADDRESS_WRAP);
    pDev->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_LINEAR);
  }
public:
  bool BeginScene()
  {
    if(Resources.Lost){EndScene();return false;};
    pDev->BeginScene();
    ResetStates();
    return true;
  }
  bool EndScene()
  {
    if(Resources.Lost){
      HRESULT hr=pDev->TestCooperativeLevel();
      if(hr!=D3DERR_DEVICENOTRESET)return false;
      pDev->Reset(&PresParams.pp);
      Resources.OnReset();
      return false;
    };
    pDev->EndScene(); 
    return !Resources.Lost;
  }
  bool Present(const RECT*pSource=nullptr,const RECT*pDest=nullptr)
  {
    if(!Resources.Lost)
    {
      Resources.Lost=D3DERR_DEVICELOST==pDev->Present(pSource,pDest,NULL,NULL);
      if(Resources.Lost)Resources.OnLost();
    }
    return !Resources.Lost;
  }
public:
  enum BlendType
  {
    BT_NONE,
    BT_SUB,
    BT_ADD,
  };
  enum AlphaType
  {
    AM_NONE,
    AM_GEQUAL_ONE,
    AM_NEQUAL_MAX,
  };
public:
  void Blend(BlendType Mode)
  {
    pDev->SetRenderState(D3DRS_ALPHABLENDENABLE,Mode!=BT_NONE);
    if(Mode==BT_NONE)return;
    if(Mode==BT_SUB)
    {
      pDev->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, 0 );
      pDev->SetTextureStageState(0, D3DTSS_COLOROP,  D3DTOP_MODULATE);
      pDev->SetTextureStageState(0, D3DTSS_COLORARG1,D3DTA_TEXTURE);
      pDev->SetTextureStageState(0, D3DTSS_COLORARG2,D3DTA_DIFFUSE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);
      pDev->SetRenderState(D3DRS_BLENDOP,D3DBLENDOP_ADD);
      pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
      pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      return;
    }
    if(Mode==BT_ADD)
    {
      pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
      return;
    }
  }
  void Alpha(AlphaType Mode)
  {
    pDev->SetRenderState(D3DRS_ALPHATESTENABLE,Mode!=AM_NONE);
    if(Mode==AM_NONE)return;
    if(Mode==AM_GEQUAL_ONE)
    {
      pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_GREATEREQUAL);
      pDev->SetRenderState(D3DRS_ALPHAREF,1);
      return;
    }
    if(Mode==AM_NEQUAL_MAX)
    {
      pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_NOTEQUAL);
      pDev->SetRenderState(D3DRS_ALPHAREF,255);
      return;
    }
  }
public:
  static void OrthoLH(D3DMATRIX&out,float w,float h,float zn,float zf)
  {
    QapMat4 mat=QapMat4(
        2.0/w,0,0,0,
        0,2.0/h,0,0,
        0,0,1/(zf-zn),0,
        0,0,-zn/(zf-zn),1
      );
    out=mat*Identity4();
  }
  void Set2D(vec2d CamPos=vec2d(0.0,0.0),real zoom=1.0,real ang=0.0,vec2i*pSize=nullptr)
  {
    auto&pp=PresParams.pp;
    vec2i v=pSize?*pSize:vec2i(pp.BackBufferWidth,pp.BackBufferHeight);
    QapMat4 matProj(Identity4());
    QapMat4 matView(Identity4());
    if((v.x%2)||(v.y%2))
    {
      if(v.x%2)CamPos.x+=0.5f;
      if(v.y%2)CamPos.y+=0.5f;
    }
    QapMat4 matWorld(Translate(-CamPos.x,-CamPos.y,0)*Scale(zoom,zoom,1.0)*RotateZ(ang));
    OrthoLH(matProj,float(v.x),float(v.y),-1.0,1.0);
    pDev->SetTransform(D3DTS_PROJECTION,&matProj); 
    pDev->SetTransform(D3DTS_VIEW,&matView);
    pDev->SetTransform(D3DTS_WORLD,&matWorld);
  }
  void Clear2D(const QapColor&Color)
  {
    pDev->Clear(0,nullptr,D3DCLEAR_TARGET,Color,1.0f,0);
  }
};
/*
class qap_color{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_color)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,a,SET,0,$)\
ADDVAR(char,r,SET,0,$)\
ADDVAR(char,g,SET,0,$)\
ADDVAR(char,b,SET,0,$)\
ADDEND()
#include "QapGenStruct.inl"
public:
};*/
#pragma once
#pragma once
#pragma warning(disable:4482) 
class QapDev
{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapDev OwnerClass;
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr){
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource(){
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost(){if(pOwner){flag=bool(pOwner->VB);pOwner->Free();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->ReInit();}
  };
public:
  struct Ver
  {
    float x,y,z;
    QapColor color;
    float tu,tv;
    Ver():x(0),y(0),z(0),tu(0),tv(0){}
    Ver(float x,float y,const QapColor&color,float u=0.0,float v=0.0):x(x),y(y),z(0),color(color),tu(u),tv(v){}
    Ver(const vec2f&pos,const QapColor&color,float u=0.0,float v=0.0):x(pos.x),y(pos.y),z(0),color(color),tu(u),tv(v){}
    Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord):x(pos.x),y(pos.y),z(0),color(color),tu(texcoord.x),tv(texcoord.y){}
    vec2f&get_pos(){return *(vec2f*)&x;}
    vec2f&get_pos()const{return *(vec2f*)&x;}
    vec2f&get_tpos(){return *(vec2f*)&tu;}
    vec2f&get_tpos()const{return *(vec2f*)&tu;}
  };
  struct BatchScope{
    QapDev&RD;
    bool flag;
    BatchScope(QapDev&RD):RD(RD){flag=!RD.Batching;if(flag)RD.BeginBatch();}
    ~BatchScope(){if(flag)RD.EndBatch();}
  };
public:
  typedef QapD3DDev9::BlendType BlendType;
  typedef QapD3DDev9::AlphaType AlphaType;
public:
  public:typedef QapDev SelfClass;
  public:
  TDynamicResource DynRes;
  IDirect3DDevice9* pDev;
  IDirect3DVertexBuffer9* VB;
  IDirect3DIndexBuffer9* IB;
  Ver* VBA;
  int* IBA;
  QapColor color;
  int VPos;
  int IPos;
  int MaxVPos;
  int MaxIPos;
  int DIPs;
  int Verts;
  int Tris;
  BlendType BlendMode;
  AlphaType AlphaMode;
  bool Batching;
  bool Textured;
  transform2f xf;
  transform2f txf;
    public:
    void DoReset()
    {
      {
      }
  (this->DynRes)=(this);(this->pDev)=(nullptr);(this->VB)=(nullptr);(this->IB)=(nullptr);(this->VBA)=(nullptr);(this->IBA)=(nullptr);(this->color)=(0xFFFFFFFF);(this->VPos)=(0);(this->IPos)=(0);(this->MaxVPos)=(0);(this->MaxIPos)=(0);(this->DIPs)=(0);(this->Verts)=(0);(this->Tris)=(0);(this->BlendMode)=(BlendType::BT_SUB);(this->AlphaMode)=(AlphaType::AM_NONE);(this->Batching)=(false);(this->Textured)=(false);detail::FieldTryDoReset(this->xf);detail::FieldTryDoReset(this->txf);
    }
  public:
    QapDev(const QapDev&)=delete;QapDev(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapDev";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYS(0,nullptr,"DynRes",int(&(((SelfClass*)nullptr)->*(&SelfClass::DynRes))),"SYS");
  Info->AddMemberSYS(0,nullptr,"pDev",int(&(((SelfClass*)nullptr)->*(&SelfClass::pDev))),"SYS");
  Info->AddMemberSYS(0,nullptr,"VB",int(&(((SelfClass*)nullptr)->*(&SelfClass::VB))),"SYS");
  Info->AddMemberSYS(0,nullptr,"IB",int(&(((SelfClass*)nullptr)->*(&SelfClass::IB))),"SYS");
  Info->AddMemberSYS(0,nullptr,"VBA",int(&(((SelfClass*)nullptr)->*(&SelfClass::VBA))),"SYS");
  Info->AddMemberSYS(0,nullptr,"IBA",int(&(((SelfClass*)nullptr)->*(&SelfClass::IBA))),"SYS");
  Info->AddMemberSYS(0,nullptr,"color",int(&(((SelfClass*)nullptr)->*(&SelfClass::color))),"SYS");
  Info->AddMemberSYS(0,nullptr,"VPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::VPos))),"SYS");
  Info->AddMemberSYS(0,nullptr,"IPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::IPos))),"SYS");
  Info->AddMemberSYS(0,nullptr,"MaxVPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::MaxVPos))),"SYS");
  Info->AddMemberSYS(0,nullptr,"MaxIPos",int(&(((SelfClass*)nullptr)->*(&SelfClass::MaxIPos))),"SYS");
  Info->AddMemberSYS(0,nullptr,"DIPs",int(&(((SelfClass*)nullptr)->*(&SelfClass::DIPs))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Verts",int(&(((SelfClass*)nullptr)->*(&SelfClass::Verts))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Tris",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tris))),"SYS");
  Info->AddMemberSYS(0,nullptr,"BlendMode",int(&(((SelfClass*)nullptr)->*(&SelfClass::BlendMode))),"SYS");
  Info->AddMemberSYS(0,nullptr,"AlphaMode",int(&(((SelfClass*)nullptr)->*(&SelfClass::AlphaMode))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Batching",int(&(((SelfClass*)nullptr)->*(&SelfClass::Batching))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Textured",int(&(((SelfClass*)nullptr)->*(&SelfClass::Textured))),"SYS");
  Info->AddMemberSYD(0,nullptr,"xf",int(&(((SelfClass*)nullptr)->*(&SelfClass::xf))),"SYD");
  Info->AddMemberSYD(0,nullptr,"txf",int(&(((SelfClass*)nullptr)->*(&SelfClass::txf))),"SYD");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapDev";
      }
    };
  public:
protected:
  static const DWORD FVF=D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1;
public:
  ~QapDev(){Free();}
public:
  void ReInit(){Init(MaxVPos,MaxIPos);}
  void MountDev(QapD3DDev9&Dev){
    this->pDev=Dev.pDev;
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int VCount,int ICount)
  {
    if(!VB)
    {
      MaxVPos=VCount; MaxIPos=ICount;
      pDev->CreateVertexBuffer(VCount*sizeof(Ver),D3DUSAGE_DYNAMIC,FVF,D3DPOOL_DEFAULT,&VB,NULL);
      pDev->CreateIndexBuffer(ICount*sizeof(int),D3DUSAGE_DYNAMIC,D3DFMT_INDEX32,D3DPOOL_DEFAULT,&IB,NULL);
      VBA=0; IBA=0; VPos=0; IPos=0; DIPs=0; Verts=0; Tris=0;
      xf.set_ident();
      txf.set_ident();
    };
  }
  void Free(){
    if(VB){
      VB->Release();
      VB=nullptr;
      VBA=nullptr;
    }
    if(IB){
      IB->Release();
      IB=nullptr;
      IBA=nullptr;
    }
    VPos=0;IPos=0;
    Batching=false;
    BlendMode=BlendType::BT_SUB;
    AlphaMode=AlphaType::AM_NONE;
  };
public:
  void QapDev::BeginBatch()
  {
    Batching=true;
    VBA=0;IBA=0;VPos=0;IPos=0;
    if(!IB||!VB)return;
    IB->Lock(0,sizeof(int)*MaxIPos,(void **)&IBA,0);
    VB->Lock(0,sizeof(Ver)*MaxVPos,(void **)&VBA,0);
  };
  void EndBatch()
  {
    Batching=false;
    if(!IB||!VB)return;
    IB->Unlock(); VB->Unlock();  
    if(VPos&&IPos){
      DIP();
    }
    VBA=0;IBA=0;
  }
  void DIP()
  {
    pDev->SetFVF(FVF);
    pDev->SetStreamSource(0,VB,0,sizeof(Ver));
    pDev->SetIndices(IB);
    pDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,VPos,0,IPos/3);
    DIPs++;Verts+=VPos;Tris+=IPos/3;
  }
  bool IsBatching(){return Batching;}
  int GetIPos(){return IPos;}
  int GetVPos(){return VPos;}
  int GetDIPs(){return DIPs;}
  int GetVerts(){return Verts;}
  int GetTris(){return Tris;}
  const QapColor&GetColor(){return color;}
  void NextFrame(){DIPs=0;Verts=0;Tris=0;SetBlendMode(BlendMode);SetAlphaMode(AlphaMode);}
public:
  void HackMode(bool Textured){this->Textured=Textured;}
  template<class QAP_TEX>
  void BindTex(int Stage,QAP_TEX*pTex){QapTex*Tex=pTex;pDev->SetTexture(Stage,Tex?Tex->Tex:nullptr);txf.set_ident();Textured=Tex?true:false;}
  void BindTex(int Stage,const nullptr_t){pDev->SetTexture(Stage,nullptr);Textured=false;}
public:
  inline Ver&AddVertexRaw(){return VBA[VPos++];}
  inline int AddVertex(const Ver&Source)
  {
    QapAssert(VPos<MaxVPos);
    Ver&Dest=VBA[VPos];
    Dest=Source;
    {vec2f&v=Dest.get_pos();v=xf*v;}
    if(Textured){vec2f&v=Dest.get_tpos();v=txf*v;}
    return VPos++;
  }
  inline int AddVertex(float x,float y,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec2f&pos,const QapColor&c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.get_pos()=pos;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=AddVertex(tmp);
    return id;
  }
  inline int AddVertex(const vec2f&pos,const QapColor&c,const vec2f&tpos)
  {
    QapDev::Ver tmp;
    tmp.get_pos()=pos;
    tmp.z=0;
    tmp.color=c;
    tmp.get_tpos()=tpos;
    auto id=AddVertex(tmp);
    return id;
  }
  inline void AddTris(int A,int B,int C)
  {
    QapAssert(IPos+2<MaxIPos);
    QapAssert(A>=0&&A<MaxVPos);
    QapAssert(B>=0&&B<MaxVPos);
    QapAssert(C>=0&&C<MaxVPos);
    IBA[IPos++]=A;
    IBA[IPos++]=B;
    IBA[IPos++]=C;
  };
public:
  inline void SetColor(const QapColor&C){color=C;}
  inline void SetTransform(transform2f const&val){xf=val;}
  inline transform2f GetTransform(){return xf;}
  inline void SetTextureTransform(transform2f const&val){txf=val;}
  inline transform2f GetTextureTransform(){return txf;}
public:
  BlendType GetBlendMode(){return BlendMode;}
  AlphaType GetAlphaMode(){return AlphaMode;}
  void SetBlendMode(BlendType Mode){DynRes.pDev->Blend(BlendMode=Mode);}
  void SetAlphaMode(AlphaType Mode){DynRes.pDev->Alpha(AlphaMode=Mode);}
public:
  void DrawSolidRect(const vec2d&a,const vec2d&b)
  {
    BatchScope Scope(*this);
    {
      int n=VPos;
      {AddVertex(a.x,a.y,color,0.0f,1.0f);};
      {AddVertex(b.x,a.y,color,1.0f,1.0f);};
      {AddVertex(b.x,b.y,color,1.0f,0.0f);};
      {AddVertex(a.x,b.y,color,0.0f,0.0f);}; 
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
    }
  }
  void DrawRect(const vec2i&ap,const vec2i&bp,int line_size)
  {
    BatchScope Scope(*this);
    {
      auto a=vec2i(std::min(ap.x,bp.x),std::min(ap.y,bp.y));
      auto b=vec2i(std::max(ap.x,bp.x),std::max(ap.y,bp.y));
      auto hs=line_size*0.5;
      DrawSolidRect(vec2d(a.x-hs,a.y-hs),vec2d(b.x+hs,a.y+hs));
      DrawSolidRect(vec2d(a.x-hs,b.y+hs),vec2d(b.x+hs,b.y-hs));
      DrawSolidRect(vec2d(a.x-hs,a.y+hs),vec2d(a.x+hs,b.y-hs));
      DrawSolidRect(vec2d(b.x-hs,a.y+hs),vec2d(b.x+hs,b.y-hs));
    }
    int gg=1;
  }
  void DrawRect(const vec2d&a,const vec2d&b,int line_size)
  {
    BatchScope Scope(*this);
    {
      real x=(a.x+b.x)*0.5;
      real w=fabs(a.x-b.x);
      DrawQuad(x,a.y,line_size+w,line_size);
      DrawQuad(x,b.y,line_size+w,line_size);
      real y=(a.y+b.y)*0.5;
      real h=fabs(a.y-b.y);
      DrawQuad(a.x,y,line_size,-line_size+h);
      DrawQuad(b.x,y,line_size,-line_size+h);
    }
    int gg=1;
  }
  void DrawRectAsQuad(const vec2i&pos,const vec2i&size,int line_size)
  {
    auto a=pos-size/2;
    auto b=a+size;
    DrawRect(a,b,line_size);
  }
  void DrawRectAsQuad(const vec2d&pos,const vec2d&size,int line_size)
  {
    auto hs=size*0.5;
    DrawRect(pos-hs,pos+hs,line_size);
  }
  void DrawQuadWithHalfPixelOffset(int x,int y,int w,int h)
  {  
    DrawQuad(float(x)+0.5,float(y)-0.5,float(w),float(h));
  }
  void DrawQuadWithHalfPixelOffset(const vec2i&p,int w,int h)
  {  
    DrawQuadWithHalfPixelOffset(p.x,p.y,w,h);
  }
  void DrawQuadWithHalfPixelOffset(const vec2i&p,const vec2i&size)
  {  
    DrawQuadWithHalfPixelOffset(p.x,p.y,size.x,size.y);
  }
  void DrawQuad(float x,float y,float w,float h)
  {  
    BatchScope Scope(*this);
    {
      int n=VPos;
      {AddVertex(x+(-0.5f)*w,y+(-0.5f)*h,color,0.0f,1.0f);};
      {AddVertex(x+(+0.5f)*w,y+(-0.5f)*h,color,1.0f,1.0f);};
      {AddVertex(x+(+0.5f)*w,y+(+0.5f)*h,color,1.0f,0.0f);};
      {AddVertex(x+(-0.5f)*w,y+(+0.5f)*h,color,0.0f,0.0f);}; 
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
    }
  }
  void DrawQuad(float x,float y,float w,float h,float a)
  {
    BatchScope Scope(*this);
    {
      vec2d OZ=Vec2dEx(a,1.0);
      vec2d O(x,y);
      int n=VPos;
        {AddVertex(vec2f(O+vec2d(-0.5f*w,-0.5f*h).UnRot(OZ)),color,0.0f,1.0f);};
        {AddVertex(vec2f(O+vec2d(+0.5f*w,-0.5f*h).UnRot(OZ)),color,1.0f,1.0f);};
        {AddVertex(vec2f(O+vec2d(+0.5f*w,+0.5f*h).UnRot(OZ)),color,1.0f,0.0f);};
        {AddVertex(vec2f(O+vec2d(-0.5f*w,+0.5f*h).UnRot(OZ)),color,0.0f,0.0f);}; 
      AddTris(n+1,n+0,n+3);
      AddTris(n+3,n+2,n+1);
    }
  }
  void DrawQuad(float x,float y,const vec2d&size,float ang)
  {
    DrawQuad(x,y,size.x,size.y,ang);
  }
  void DrawQuad(const vec2d&pos,const vec2d&size,float ang)
  {
    DrawQuad(pos.x,pos.y,size.x,size.y,ang);
  }
  void DrawQuad(const vec2d&pos,const vec2d&size)
  {
    DrawQuad(pos.x,pos.y,size.x,size.y);
  }
  void DrawQuad(const vec2d&pos,float w,float h,float ang)
  {
    DrawQuad(pos.x,pos.y,w,h,ang);
  }
  void DrawQuad(const vec2d&pos,float w,float h)
  {
    DrawQuad(pos.x,pos.y,w,h);
  }
  void DrawTrigon(const vec2d&A,const vec2d&B,const vec2d&C)
  {
    BatchScope Scope(*this);
    {
      AddTris(
        AddVertex(Ver(A,color)),
        AddVertex(Ver(B,color)),
        AddVertex(Ver(C,color))
      );
    }
  }
  void DrawConvex(const vector<vec2d>&Points)
  {
    BatchScope Scope(*this);
    {
      if(Points.empty())return;
      int c=Points.size();
      int n=VPos;
      for(int i=0;i<c;i++)AddVertex(Points[i],color,0.5,0.5);
      for(int i=2;i<c;i++)AddTris(n,n+i-1,n+i-0);
    }
  }
public:
  template<typename TYPE>
  void DrawPolyLine(const vector<TYPE>&PA,const real&LineSize,const bool&Loop)
  {
    if(PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      int c=Loop?Count:Count-1;
      for(int i=0;i<c;i++)
      {
        TYPE const&a=PA[(i+0)%Count];
        TYPE const&b=PA[(i+1)%Count];
        vec2d n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]={
          AddVertex(a+n,color,0.5f,0.5f),
          AddVertex(b-n,color,0.5f,0.5f),
          AddVertex(a-n,color,0.5f,0.5f),
          AddVertex(b+n,color,0.5f,0.5f),
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawLineList(const vector<TYPE>&PA,const real&LineSize)
  {
    if(PA.empty())return;
    BatchScope Scope(*this);
    {
      int Count=PA.size();
      for(int i=0;i+1<Count;i+=2)
      {
        TYPE const&a=PA[i+0];
        TYPE const&b=PA[i+1];
        TYPE n=vec2d(b-a).Ort().SetMag(LineSize*0.5);
        int A[4]={
          AddVertex(a+n,color,0.5,0.5),
          AddVertex(b-n,color,0.5,0.5),
          AddVertex(a-n,color,0.5,0.5),
          AddVertex(b+n,color,0.5,0.5),
        };
        AddTris(A[0],A[1],A[2]);
        AddTris(A[0],A[1],A[3]);
      }
    }
  }
  template<typename TYPE>
  void DrawMesh(const vector<TYPE>&VA,const vector<int>&IA)
  {
    QapDebugMsg("[2014.05.22]: way used?");
    if(VA.empty())return;
    BatchScope Scope(*this);
    {
      int base=GetVPos();
      static IntArray VID;VID.resize(VA.size());
      for(int i=0;i<VA.size();i++)VID[i]=AddVertex(MakeVer(VA[i],color,p.x,p.y));
      for(int i=0;i<IA.size();i+=3)AddTris(VID[IA[i+0]],VID[IA[i+1]],VID[IA[i+2]]);
    }
  }
  void DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    static PointArray PA; PA.resize(seg);
    for(int i=0;i<seg;i++)
    {
      vec2d v=Vec2dEx((real)i/(real)seg*2.0*Pi,r);
      PA[i]=pos+v;
    };
    DrawPolyLine(PA,ls,true);
  }
  void DrawCircle(const vec2d&pos,real r,real ang,real ls,int seg)
  {
    DrawCircleEx(pos,r-ls*0.5,r+ls*0.5,seg,ang);
  }
  void DrawCircleEx(const vec2d&pos,real r0,real r1,int seg,real ang)
  {
    int n=seg;
    if(n<=0)return;
    BatchScope Scope(*this);
    static vector<int> VID;VID.resize(n*2);
    for(int i=0;i<n;i++)
    {
      vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
      VID[0+i]=AddVertex(pos+v*r0,color,0,0);
      VID[n+i]=AddVertex(pos+v*r1,color,0,0);
    }
    for(int i=0;i<n;i++)
    {
      int a=VID[0+(i+0)%n];
      int b=VID[0+(i+1)%n];
      int c=VID[n+(i+0)%n];
      int d=VID[n+(i+1)%n];
      AddTris(a,b,d);
      AddTris(d,c,a);
    }
  }
};
template<class TYPE>
class QapArray{
public:
  TMemory Mem;
  QapArray(){}
  ~QapArray()
  {
    Free();
  }
  QapArray(const QapArray<TYPE>&Ref){oper_set(Ref);}
  void operator=(const QapArray<TYPE>&Ref){oper_set(Ref);}
  void oper_set(const QapArray<TYPE>&Ref)
  {
    Free();
    if(!Ref)return;
    Init(Ref.Mem.size);
    QapAssert(Ref.Mem.size==this->Mem.size);
    memcpy_s(this->Mem.ptr,this->Mem.size*sizeof(TYPE),Ref.Mem.ptr,Ref.Mem.size*sizeof(TYPE));
  }
  QapArray(QapArray<TYPE>&&Ref){oper_set(std::move(Ref));}
  void operator=(QapArray<TYPE>&&Ref){oper_set(std::move(Ref));}
  void oper_set(QapArray<TYPE>&&Ref)
  {
    Free();
    this->Mem=std::move(Ref.Mem);
  }
  operator bool()const{return Mem.ptr;}
  TYPE&operator[](size_t index){
    return (TYPE&)Mem.ptr[index*sizeof(TYPE)];
  }
  const TYPE&operator[](size_t index)const{
    return (const TYPE&)Mem.ptr[index*sizeof(TYPE)];
  }
  void Init(int size)
  {
    if(*this)Free();
    QapAssert(size>0);
    QapAssert(size<(1<<26));
    Mem.ptr=(TMemory::ptr_t*)(void*)new TYPE[size];
    Mem.size=size;
  }
  void Free()
  {
    if(!Mem.ptr)return;
    TYPE*p=(TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;
    delete[] p;
    Mem.ptr=nullptr;
    Mem.size=0;
  }
  TYPE*get(){return (TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;}
  const TYPE*get()const{return (TYPE*)(void*)(TMemory::ptr_t*)Mem.ptr;}
};
class QapTexMem{
public:
  public:typedef QapTexMem SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  QapArray<QapColor> Arr;
  int W;
  int H;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Arr);(this->W)=(0);(this->H)=(0);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapTexMem";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberSYD(0,nullptr,"Arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::Arr))),"SYD");
  Info->AddMemberSYS(0,nullptr,"W",int(&(((SelfClass*)nullptr)->*(&SelfClass::W))),"SYS");
  Info->AddMemberSYS(0,nullptr,"H",int(&(((SelfClass*)nullptr)->*(&SelfClass::H))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapTexMem";
      }
    };
  public:
public:
  QapTexMem(){DoReset();}
  QapTexMem(const QapTexMem&Ref){oper_set(Ref);}
  void operator=(const QapTexMem&Ref){oper_set(Ref);}
  void oper_set(const QapTexMem&Ref)
  {
    this->Arr=Ref.Arr;
    this->W=Ref.W;
    this->H=Ref.H;
  }
  QapTexMem(QapTexMem&&Ref){oper_set(std::move(Ref));}
  void operator=(QapTexMem&&Ref){oper_set(std::move(Ref));}
  void oper_set(QapTexMem&&Ref)
  {
    this->Self=std::move(Ref.Self);
    this->Arr=std::move(Ref.Arr);
    this->W=std::move(Ref.W);
    this->H=std::move(Ref.H);
  }
  QapTexMem Clone(){
    QapTexMem tmp;
    tmp=*this;
    return std::move(tmp);
  }
  void CopyDataFrom(const QapTexMem&Ref){
    QapTexMem tmp;
    this->Arr=Ref.Arr;
    this->W=Ref.W;
    this->H=Ref.H;
  }
  void MoveDataFrom(QapTexMem&Ref){
    QapTexMem tmp;
    this->Arr=std::move(Ref.Arr);
    this->W=std::move(Ref.W);Ref.W=0;
    this->H=std::move(Ref.H);Ref.H=0;
  }
  void Init(int W,int H){this->W=W;this->H=H;Arr.Init(W*H);}
  void Free(){Arr.Free();}
  QapColor*get(){return Arr.get();}
  const QapColor*get()const{return Arr.get();}
  operator bool()const{return Arr;}
public:
  void InvertY()
  {
    QapColor*pBits=Arr.get();
    for(int i=0;i<H/2;i++)
    {
      int a=W*(i);
      int b=W*(H-i-1);
      for(int j=0;j<W;j++){std::swap(pBits[a+j],pBits[b+j]);}
    }
  }
  void InvertX()
  {
    QapColor*pBits=Arr.get();
    for(int i=0;i<H;i++)
    {
      QapColor*pLine=&pBits[i*W];
      for(int j=0;j<W/2;j++)
      {
        int a=j;
        int b=W-j-1;
        std::swap(pLine[a],pLine[b]);
      }
    }
  }
public:
  void GenRect(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for(int i=0;i<TexSize;i++)
    {
      for(int j=0;j<TexSize;j++)
      {
        *pT=0x80000000;
        pT++;
      }
    }
    RectLine(0,0,TexSize,TexSize,0xffffffff);
  }
  void GenBall(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for(int i=0;i<TexSize;i++)
    {
      for(int j=0;j<TexSize;j++)
      {
        float x=i-TexSize/2;float y=j-TexSize/2;
        float r=(float)TexSize/2;
        float m=((x*x)+(y*y))/(r*r);
        if(m>1.0f){
          *pT=0x00000000;pT++;continue;
        }
        m=std::max(0.0f,1.0f-(m*m*m)); 
        m=std::min(1.0f,m);
        float a=(m<0.5)?m*2:1;
        a=std::min(1.0f,a);
        a=std::max(0.0f,a);
        byte bm=m*255;
        pT->a=byte(a*255);
        pT->r=bm;
        pT->g=bm;
        pT->b=bm;
        pT++;
      }
    }
  }
  void GenQuad(int TexSize)
  {
    Init(TexSize,TexSize);
    auto*pT=get();
    for(int i=0;i<TexSize;i++)
    {
      for(int j=0;j<TexSize;j++)
      {
        float x=i-TexSize/2+0.5f,y=j-TexSize/2+0.5f;
        float r=(float)TexSize/2;
        float m=((x*x*x*x)+(y*y*y*y))/(r*r*r*r);
        if(m>1.0f){
          *pT=0x00000000;pT++;continue;
        }
        m=std::max(0.0f,1.0f-(m*m*m)); 
        m=std::min(1.0f,m);
        float a=(m<0.5)?m*2:1;
        a=std::min(1.0f,a);
        a=std::max(0.0f,a);
        byte bm=m*255;
        pT->a=byte(a*255);
        pT->r=bm;
        pT->g=bm;
        pT->b=bm;
        pT++;
      }
    }
  }
  void FillBorder(int x,int y,const QapTexMem&Source,int n=4)
  {
    auto&Target=*this;
    if(!Source){
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    if(1)
    {
      {auto src=pS[(00-0)+(00-0)*sW];for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((y+(j+(00-n)))>=0)if((y+(j+(00-n)))<H)if((x+(i+(00-n)))<W)if((x+(i+(00-n)))>=0)pT[(x+(i+(00-n)))+(y+(j+(00-n)))*W]=(src);
      };
      {auto src=pS[(sW-1)+(00-0)*sW];for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((y+(j+(00-n)))>=0)if((y+(j+(00-n)))<H)if((x+(i+(sW-0)))<W)if((x+(i+(sW-0)))>=0)pT[(x+(i+(sW-0)))+(y+(j+(00-n)))*W]=(src);
      };
      {auto src=pS[(sW-1)+(sH-1)*sW];for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((y+(j+(sH-0)))>=0)if((y+(j+(sH-0)))<H)if((x+(i+(sW-0)))<W)if((x+(i+(sW-0)))>=0)pT[(x+(i+(sW-0)))+(y+(j+(sH-0)))*W]=(src);
      };
      {auto src=pS[(00-0)+(sH-1)*sW];for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((y+(j+(sH-0)))>=0)if((y+(j+(sH-0)))<H)if((x+(i+(00-n)))<W)if((x+(i+(00-n)))>=0)pT[(x+(i+(00-n)))+(y+(j+(sH-0)))*W]=(src);
      };
    }
    if(1)
    {
      for(int k=1;k<=n;k++)
      {
        {int j=00+y;if(InDip(0,j-k,H-1))for(int i=max(0,x);i<mX;i++){pT[i+(j-k)*W]=pS[(i-x)+(j-y)*sW];}}
        {int j=mY-1;if(InDip(0,j+k,H-1))for(int i=max(0,x);i<mX;i++){pT[i+(j+k)*W]=pS[(i-x)+(j-y)*sW];}}
        {int i=00+x;if(InDip(0,i-k,W-1))for(int j=max(0,y);j<mY;j++){pT[(i-k)+j*W]=pS[(i-x)+(j-y)*sW];}}
        {int i=mX-1;if(InDip(0,i+k,W-1))for(int j=max(0,y);j<mY;j++){pT[(i+k)+j*W]=pS[(i-x)+(j-y)*sW];}}
      }
    }
    return;
  }
  void FillMem(int x,int y,const QapTexMem&Source)
  {
    auto&Target=*this;
    if(!Source){
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for(int j=max(0,y);j<mY;j++){
      for(int i=max(0,x);i<mX;i++){
        pT[i+j*W]=pS[(i-x)+(j-y)*sW];
      }
    }
    return;
  } 
  void DrawInHalfScale(const QapTexMem&Source,int count)
  {
    if(count<0)return;
    if(!count){CopyDataFrom(Source);return;}
    QapTexMem Src=Source;
    for(int i=0;i<count;i++)
    {
      QapTexMem Target;
      int sW=Src.W;
      int sH=Src.H;
      QapAssert(!(sW%2));
      QapAssert(!(sH%2));
      Target.Init(Src.W/2,Src.H/2);
      auto tW=Target.W;
      auto tH=Target.H;
      auto*pS=Src.get();
      auto*pT=Target.get();
      for(int y=0;y<tH;y++)for(int x=0;x<tW;x++)
      {
        auto&out=pT[x+y*tW];
        auto a=pS[(x*2+(0))+(y*2+(0))*sW];
        auto b=pS[(x*2+(1))+(y*2+(0))*sW];
        auto c=pS[(x*2+(0))+(y*2+(1))*sW];
        auto d=pS[(x*2+(1))+(y*2+(1))*sW];
        auto e=QapColor::HalfMix(a,b);
        auto f=QapColor::HalfMix(c,d);
        out=QapColor::HalfMix(e,f);
      }
      Src.MoveDataFrom(Target);
    }
    MoveDataFrom(Src);
  }
  void DrawMemWithBlend(int x,int y,const QapTexMem&Source,const QapColor&color)
  {
    auto&Target=*this;
    if(!Source){
      QapAssert(false);
      return;
    }
    int sW=Source.W;
    int sH=Source.H;
    int mX=min(W,x+sW);
    int mY=min(H,y+sH);
    auto*pS=Source.get();
    auto*pT=Target.get();
    for(int j=max(0,y);j<mY;j++){
      for(int i=max(0,x);i<mX;i++){
        auto inp=pS[(i-x)+(j-y)*sW]*color;
        auto&out=pT[i+j*W];
        auto a=inp.a;
        auto b=255-a;
        out.a=inp.a;
        out.r=(out.r*b+inp.r*a)/255;out.g=(out.g*b+inp.g*a)/255;out.b=(out.b*b+inp.b*a)/255;
      }
    }
    return;
  }
  void Clear(const QapColor&color=0xFF000000){
    auto*pBits=get();
    for(int i=0;i<W*H;i++)pBits[i]=color;
  }
  void FillLine(const int Y,const QapColor&Color){
    auto*pBits=get();
    for(int i=0;i<W;i++){QapColor&pix=pBits[Y*W+i];pix=Color;}
  }
  void FillColumn(const int X,const QapColor&Color){
    auto*pBits=get();
    for(int i=0;i<H;i++){QapColor&pix=pBits[i*W+X];pix=Color;}
  }
  void RectLine(int X,int Y,int W,int H,const QapColor&Color)
  {
    FillLineEx(Y+0-0,X+0,X+W,Color);
    FillLineEx(Y+H-1,X+0,X+W,Color);
    FillColomnEx(X+0-0,Y+0,Y+H,Color);
    FillColomnEx(X+W-1,Y+0,Y+H,Color);
  }
  void FillLineEx(const int Y,const int X0,const int X1,const QapColor&Color){
    auto*pBits=get();
    int x0=Clamp<int>(X0,0,W);
    int x1=Clamp<int>(X1,0,W);
    if(x0>x1)std::swap(x0,x1);
    for(int i=x0;i<x1;i++){QapColor&pix=pBits[Y*W+i];pix=Color;}
  }
  void FillColomnEx(const int X,const int Y0,const int Y1,const QapColor&Color){
    auto*pBits=get();
    int y0=Clamp<int>(Y0,0,H);
    int y1=Clamp<int>(Y1,0,H);
    if(y0>y1)std::swap(y0,y1);
    for(int i=y0;i<y1;i++){QapColor&pix=pBits[i*W+X];pix=Color;}
  }
public:
  void CopyAlpha(QapTexMem&Alpha){
    auto*pBits=get();
    auto*pAlphaBits=get();
    if(Alpha.W!=W||Alpha.H!=H)return;
    for(int i=0;i<W*H;i++)pBits[i].a=pAlphaBits[i].a;
  }
  void CalcAlpha(){
    auto*pBits=get();
    for(int i=0;i<W*H;i++)pBits[i].a=pBits[i].GetLuminance();
  }
  void CalcAlpha(const QapColor&Color,int threshold=0){
    auto*pBits=get();
    for(int i=0;i<W*H;i++)pBits[i].a=pBits[i]==Color?0:255;
    const QapColor&c=Color;
    int t=threshold;
    int t3=t*3;
    for(int i=0;i<W*H;i++){
      QapColor&p=pBits[i];
      int fr=abs(int(p.r)-int(c.r));
      int fg=abs(int(p.g)-int(c.g));
      int fb=abs(int(p.b)-int(c.b));
      int sum=fr+fg+fb;
      p.a=sum>t3?255:t3?255*sum/t3:0;
    }
  }
  void DrawSolidCircle(int x,int y,int r,const QapColor&color)
  {
    auto rr=r*r;
    int mX=min(W,x+r);
    int mY=min(H,y+r);
    auto*pT=get();
    for(int j=max(0,y-r);j<mY;j++)
    {
      for(int i=max(0,x-r);i<mX;i++)
      {
        auto px=i-x;
        auto py=j-y;
        if(px*px+py*py>=rr)continue;
        auto&out=pT[i+j*W];
        out=color;
      }
    }
  }
  void DrawSolidQuad(int x,int y,int w,int h,const QapColor&color)
  {
    int mX=min(W,x+w/2);
    int mY=min(H,y+h/2);
    auto*pT=get();
    for(int j=max(0,y-h/2);j<mY;j++)
    {
      for(int i=max(0,x-w/2);i<mX;i++)
      {
        auto&out=pT[i+j*W];
        out=color;
      }
    }
  }
  void FillChannel(const QapColor&Source,DWORD BitMask){
    auto*pBits=get();
    for(int i=0;i<W*H;i++){QapColor&C=pBits[i];C=(~BitMask&C)|(BitMask&Source);};
  }
  void BlurTexture(int PassCount)
  {
    auto*pBits=get();
    if(!pBits||!W||!H)return;
    static vector<QapColor> vMem;
    vMem.resize(W*H);
    if(W*H!=Arr.Mem.size)
    {
      QapDebugMsg("WTF?");return;
    }
    auto*pBuff=&vMem[0];
    static const int BBM[]={
      1,2,1, 
      2,4,2, 
      1,2,1
    };
    static int MartixSum=0;
    if(!MartixSum){for(int i=0;i<lenof(BBM);i++)MartixSum+=BBM[i];}
    QapAssert(MartixSum==16);
    const int PosRange[]={
      -W-1,-W,-W+1,
      -1-0,+0,-0+1,
      +W-1,+W,+W+1
    };
    for(int PassId=0;PassId<PassCount;PassId++)
    {
      memcpy_s(pBuff,sizeof(QapColor)*vMem.size(),pBits,Arr.Mem.size*sizeof(QapColor));
      for(int j=1;j<H-1;j++)
      {
        for(int i=1;i<W-1;i++)
        {
          auto&out=pBits[j*W+i];
          auto cur_id=j*W+i;
          vec4i buff;
          for(int t=0;t<9;t++)
          {
            auto T=pBuff[cur_id+PosRange[t]];
            buff+=vec4i(T)*BBM[t];
          };    
          static_assert(1==(16>>4),"orly?");
          static_assert(16==(1<<4),"orly?");
          static_assert((1024/16)==(1024>>4),"orly?");
          buff>>=4;
          out=buff.unsafe_but_fast_GetColor();
        }
      }
    }
    return;
  }
};
extern bool LoadTextureFromFile(QapTexMem&out,const string&FN);
extern void SaveTextureToFile(QapTexMem&in,const string&FN);
class QapTexFile{
public:
  public:typedef QapTexFile SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  string FN;
  QapTexMem Mem;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->FN);detail::FieldTryDoReset(this->Mem);
    }
  public:
    QapTexFile(const QapTexFile&)=delete;QapTexFile(){DoReset();};
  public:
    QapTexFile(QapTexFile&&_Right){operator=(std::move(_Right));}
    void operator=(QapTexFile&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->FN=std::move(_Right.FN);
  this->Mem=std::move(_Right.Mem);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapTexFile";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"FN",int(&(((SelfClass*)nullptr)->*(&SelfClass::FN))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapTexMem>::GetRTTI(RTTI),"Mem",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mem))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapTexFile";
      }
    };
  public:
public:
  void Load()
  {
    LoadTextureFromFile(Mem,FN);
  }
  void Save()
  {
    SaveTextureToFile(Mem,FN);
  }
};
class QapTex{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapTex OwnerClass;
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr){
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource(){
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost(){if(pOwner){flag=bool(pOwner->Tex);pOwner->Free();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->ReInit();}
  };
public:
  public:typedef QapTex SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  int W;
  int H;
  TDynamicResource DynRes;
  IDirect3DTexture9* Tex;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);(this->W)=(0);(this->H)=(0);(this->DynRes)=(this);(this->Tex)=(nullptr);
    }
  public:
    QapTex(const QapTex&)=delete;QapTex(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapTex";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberSYS(0,nullptr,"W",int(&(((SelfClass*)nullptr)->*(&SelfClass::W))),"SYS");
  Info->AddMemberSYS(0,nullptr,"H",int(&(((SelfClass*)nullptr)->*(&SelfClass::H))),"SYS");
  Info->AddMemberSYS(0,nullptr,"DynRes",int(&(((SelfClass*)nullptr)->*(&SelfClass::DynRes))),"SYS");
  Info->AddMemberSYS(0,nullptr,"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapTex";
      }
    };
  public:
public:
  ~QapTex(){Free();}
public:
  void ReInit(){}
  void MountDev(QapD3DDev9&Dev){
    this->DynRes.Mount(this,&Dev);
  }
  void Init(int W,int H,int Levels)
  {
    Free();
    auto*Sys=DynRes.pDev;
    Sys->pDev->CreateTexture(W,H,Levels,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&Tex,NULL);
  }
  void Free()
  {
    if(!Tex)return;
    Tex->Release();
    Tex=nullptr;
  };
  operator bool()const{return Tex;}
  void Bind(int lvl=0){
    auto*Sys=DynRes.pDev;
    if(!Sys)return;
    Sys->pDev->SetTexture(lvl,Tex);
  };
public:
  void QapTex::operator=(const QapTex&){
    QapDebugMsg("fail");
  }
};
class TResourceHolder{
public:
  public:typedef TResourceHolder SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  string Caption;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Caption);
    }
  public:
    TResourceHolder(const TResourceHolder&)=delete;TResourceHolder(){DoReset();};
  public:
    TResourceHolder(TResourceHolder&&_Right){operator=(std::move(_Right));}
    void operator=(TResourceHolder&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Caption=std::move(_Right.Caption);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TResourceHolder";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Caption",int(&(((SelfClass*)nullptr)->*(&SelfClass::Caption))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TResourceHolder";
      }
    };
  public:
public:
};
class QapResource{
public:
  public:typedef QapResource SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  vector<TWeakPtr<TResourceHolder>> Holders;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Holders);
    }
  public:
    QapResource(const QapResource&)=delete;QapResource(){DoReset();};
  public:
    QapResource(QapResource&&_Right){operator=(std::move(_Right));}
    void operator=(QapResource&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Holders=std::move(_Right.Holders);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapResource";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<TWeakPtr<TResourceHolder>>>::GetRTTI(RTTI),"Holders",int(&(((SelfClass*)nullptr)->*(&SelfClass::Holders))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapResource";
      }
    };
  public:
public:
  class IEnv{
  public:
    IEnvRTTI&Env;
    QapD3DDev9*pDev;
    operator IEnvRTTI&(){return Env;}
  };
public:
  virtual void Do(IEnv&Env){}
public:
  void Run(IEnvRTTI&Env,QapD3DDev9*pDev)
  {
    if(!pDev)return;
    IEnv env={Env,pDev};
    Do(env);
  }
};
class QapResourceList:public QapResource{
public:
  public:typedef QapResourceList SelfClass;public:typedef QapResource ParentClass;
  public:
  vector<TAutoPtr<QapResource>> Items;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Items);
    }
  public:
    QapResourceList(const QapResourceList&)=delete;QapResourceList(){DoReset();};
  public:
    QapResourceList(QapResourceList&&_Right){operator=(std::move(_Right));}
    void operator=(QapResourceList&&_Right)
    {
      struct hidden{static void foo(QapResource(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        QapResource::operator=(std::move(_Right));
      }
  this->Items=std::move(_Right.Items);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapResourceList";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<QapResource>>>::GetRTTI(RTTI),"Items",int(&(((SelfClass*)nullptr)->*(&SelfClass::Items))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapResourceList";
      }
    };
  public:
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env,TResourceHolder&ResHolder,const string&Caption)
  {
    Items.resize(Items.size()+1);
    TYPE*ret=Items.back().build<TYPE>(Env);
    ret->Holders.push_back(&ResHolder);
    QapAssert(ResHolder.Caption.empty());
    ResHolder.Caption=Caption;
    return ret;
  }
  void Del(){}
public:
  void Do(IEnv&Env)
  {
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(!ex)continue;
      ex->Do(Env);
    }
  }
};
class QapTexGen{
public:
  public:typedef QapTexGen SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  TWeakPtr<QapTexMem> Mem;
  TWeakPtr<QapTex> Tex;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Mem);detail::FieldTryDoReset(this->Tex);
    }
  public:
    QapTexGen(const QapTexGen&)=delete;QapTexGen(){DoReset();};
  public:
    QapTexGen(QapTexGen&&_Right){operator=(std::move(_Right));}
    void operator=(QapTexGen&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Mem=std::move(_Right.Mem);
  this->Tex=std::move(_Right.Tex);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapTexGen";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TWeakPtr<QapTexMem>>::GetRTTI(RTTI),"Mem",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mem))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TWeakPtr<QapTex>>::GetRTTI(RTTI),"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapTexGen";
      }
    };
  public:
public:
  static void Gen(QapTexMem*Mem,QapTex*Tex,int MaxLevelCount=16)
  {
    if(!Tex||!Mem)return;
    int W=Mem->W;int H=Mem->H;QapColor*pBits=Mem->get();
    Tex->W=W;Tex->H=H;
    QapAssert(W*H==Mem->Arr.Mem.size);
    int SW=1,SWC=0;for(int &i=SWC;SW<W;i++)SW*=2;if(SW>W)goto fail;
    int SH=1,SHC=0;for(int &i=SHC;SH<H;i++)SH*=2;if(SH>H)goto fail;
    if(0){fail:QapDebugMsg("NPOT("+IToS(W)+"x"+IToS(H)+")");return;}
    int Levels=min(MaxLevelCount,min(SWC,SHC));
    IDirect3DTexture9*&tex=Tex->Tex;
    Tex->Init(W,H,Levels);
    if(!tex){QapDebugMsg("fail");return;}
    D3DLOCKED_RECT rect[16]; struct QapARGB{BYTE B,G,R,A;}; QapARGB* pBitsEx[16];
    for(int i=0;i<Levels;i++){tex->LockRect(i,&rect[i],NULL,0);pBitsEx[i]=(QapARGB*)rect[i].pBits;};
    {
      QapColor* pDestBits=(QapColor*)rect[0].pBits;
      memcpy_s(pDestBits,SW*SH*sizeof(QapColor),pBits,SW*SH*sizeof(QapColor));
      SW/=2; SH/=2;
    }
    for(int k=1;k<Levels;k++)
    {
      QapARGB *PC=(QapARGB*)rect[k].pBits;
      for(int j=0;j<SH;j++)
        for(int i=0;i<SW;i++)
        {
            QapARGB A[4]={pBitsEx[k-1][0+2*0*SW+2*i+4*j*SW],pBitsEx[k-1][0+2*1*SW+2*i+4*j*SW],pBitsEx[k-1][1+2*0*SW+2*i+4*j*SW],pBitsEx[k-1][1+2*1*SW+2*i+4*j*SW]};
          float AF[4]={0,0,0,0};
          for(int t=0;t<4;t++)
          {
            AF[0]+=A[t].R;
            AF[1]+=A[t].G;
            AF[2]+=A[t].B;
            AF[3]+=A[t].A;
          };
          for(int t=0;t<4;t++)AF[t]*=0.25*(1.0/255.0);
          QapColor PCC=D3DCOLOR_COLORVALUE(AF[0],AF[1],AF[2],AF[3]);
          *PC=*((QapARGB*)&PCC);
          PC++;
        }
      SW/=2; SH/=2;
    }
    for(int i=0;i<Levels;i++)tex->UnlockRect(i);
  }
public:
  void Do()
  {
    if(!Mem||!Tex)return;
    auto*mem=Mem.get();
    auto*tex=Tex.get();
    Gen(mem,tex);
    if(0){static int i=0;i++;SaveTextureToFile(*mem,"hack"+IToS(i)+".png");}
  }
};
class QapTexObject:public QapResource{
public:
  public:typedef QapTexObject SelfClass;public:typedef QapResource ParentClass;
  public:
  QapTexFile File;
  QapTex Tex;
  QapTexGen Gen;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->File);detail::FieldTryDoReset(this->Tex);detail::FieldTryDoReset(this->Gen);
    }
  public:
    QapTexObject(const QapTexObject&)=delete;QapTexObject(){DoReset();};
  public:
    QapTexObject(QapTexObject&&_Right){operator=(std::move(_Right));}
    void operator=(QapTexObject&&_Right)
    {
      struct hidden{static void foo(QapResource(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        QapResource::operator=(std::move(_Right));
      }
  this->File=std::move(_Right.File);
  this->Tex=std::move(_Right.Tex);
  this->Gen=std::move(_Right.Gen);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapTexObject";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<QapTexFile>::GetRTTI(RTTI),"File",int(&(((SelfClass*)nullptr)->*(&SelfClass::File))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapTex>::GetRTTI(RTTI),"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapTexGen>::GetRTTI(RTTI),"Gen",int(&(((SelfClass*)nullptr)->*(&SelfClass::Gen))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapTexObject";
      }
    };
  public:
public:
  void SetToDef()
  {
    Gen.Mem=&File.Mem;
    Gen.Tex=&Tex;
  }
  struct t_fn_parser{
    string fn;
    string func;
    string size;
    int value;
    bool main()
    {
      if(fn.empty())return false;
      if(fn[0]!='?')return false;
      int e=0;
      func=ScanParam("?",fn,"(",e);
      if(e<0)return false;
      e+=func.size()+string("(").size();
      size=ScanParam("",fn,")",e);
      if(e<0)return false;
      value=SToI(size);
      return true;
    }
  };
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!File.Mem);
      for(;
      )
      {
        t_fn_parser parser;
        parser.fn=File.FN;
        if(parser.main())
        {
          if(parser.func=="GenRect"){File.Mem.GenRect(parser.value);break;}
          if(parser.func=="GenBall"){File.Mem.GenBall(parser.value);break;}
          if(parser.func=="GenQuad"){File.Mem.GenQuad(parser.value);break;}
          QapDebugMsg("texmem.func not found: "+parser.func+"\nFile.FN:\n"+File.FN);
          break;
        }
        File.Load();
        break;
      }
      Tex.MountDev(*Env.pDev);
    }
    if(!Gen.Tex->Tex)Gen.Do();
  }
};
class QapResourceDetector{
public:
  class TDynamicResource:public QapD3D9Resource
  {
  public:
    typedef QapResourceDetector OwnerClass;
    void operator=(OwnerClass*pOwner){this->pOwner=pOwner;}
  public:
    TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr){
      if(pDev)pDev->Resources.Reg(this);
    };
    ~TDynamicResource(){
      if(pDev)pDev->Resources.UnReg(this);
    };
  public:
    QapD3DDev9*pDev;
    void Mount(OwnerClass*pOwner,QapD3DDev9*pDev){
      QapAssert(pOwner);
      QapAssert(pDev);
      this->pOwner=pOwner;
      this->pDev=pDev;
      if(pDev)pDev->Resources.Reg(this);
    }
  public:
    OwnerClass*pOwner;
    bool flag;
    void OnLost(){if(pOwner){flag=bool(pOwner->used);pOwner->PreFree();}else{QapDebugMsg("fail");flag=false;}}
    void OnReset(){if(pOwner&&flag)pOwner->PreInit();}
  };
public:
  public:typedef QapResourceDetector SelfClass;
  public:
  bool needinit;
  TDynamicResource DynRes;
  bool used;
    public:
    void DoReset()
    {
      {
      }
  (this->needinit)=(false);(this->DynRes)=(this);(this->used)=(false);
    }
  public:
    QapResourceDetector(const QapResourceDetector&)=delete;QapResourceDetector(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapResourceDetector";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"needinit",int(&(((SelfClass*)nullptr)->*(&SelfClass::needinit))),"SET","false");
  Info->AddMemberSYS(0,nullptr,"DynRes",int(&(((SelfClass*)nullptr)->*(&SelfClass::DynRes))),"SYS");
  Info->AddMemberSYS(0,nullptr,"used",int(&(((SelfClass*)nullptr)->*(&SelfClass::used))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapResourceDetector";
      }
    };
  public:
public:
  ~QapResourceDetector(){Free();}
public:
  void MountDev(QapD3DDev9&Dev){this->DynRes.Mount(this,&Dev);}
  void PreInit(){needinit=true;}
  void PreFree(){Free();}
  void Init(){used=true;needinit=false;}
  void Free(){used=false;};
  operator bool()const{return used;}
};
/*
class ITexObject{
public:
  virtual vec2i GetSize()=0;
  virtual QapTex&GetTex()=0;
  virtual QapD3DDev9*GetDev()=0;
  virtual void MountDev(QapD3DDev9&Dev)=0;
public:
};*/
template<class TYPE,unsigned int SIZE>class ArrayTypeSolver{};
class QapFontInfo{
public:
  typedef vec2i vec2i_256[256];
public:
  public:typedef QapFontInfo SelfClass;
  public:
  vec2i_256 Coords;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Coords);
    }
  public:
    QapFontInfo(const QapFontInfo&)=delete;QapFontInfo(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapFontInfo";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSYD(0,nullptr,"Coords",int(&(((SelfClass*)nullptr)->*(&SelfClass::Coords))),"SYD");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapFontInfo";
      }
    };
  public:
public:
  vec2i&operator[](int index){return Coords[index];}
  const vec2i&operator[](int index)const{return Coords[index];}
};
class QapFont{
public:
  public:typedef QapFont SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  QapTexMem Mem;
  QapFontInfo Info;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Mem);detail::FieldTryDoReset(this->Info);
    }
  public:
    QapFont(const QapFont&)=delete;QapFont(){DoReset();};
  public:
    QapFont(QapFont&&_Right){operator=(std::move(_Right));}
    void operator=(QapFont&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Mem=std::move(_Right.Mem);
  this->Info=std::move(_Right.Info);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapFont";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapTexMem>::GetRTTI(RTTI),"Mem",int(&(((SelfClass*)nullptr)->*(&SelfClass::Mem))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapFontInfo>::GetRTTI(RTTI),"Info",int(&(((SelfClass*)nullptr)->*(&SelfClass::Info))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapFont";
      }
    };
  public:
public:
};
class QapFontGen{
public:
  public:typedef QapFontGen SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  string Name;
  int Size;
  bool Bold;
  int TexSize;
  TWeakPtr<QapFont> Font;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);(this->Name)=(1?"FixedSys":"Arial");(this->Size)=(1?10:14);(this->Bold)=(false);(this->TexSize)=(512);detail::FieldTryDoReset(this->Font);
    }
  public:
    QapFontGen(const QapFontGen&)=delete;QapFontGen(){DoReset();};
  public:
    QapFontGen(QapFontGen&&_Right){operator=(std::move(_Right));}
    void operator=(QapFontGen&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Name=std::move(_Right.Name);
  this->Size=std::move(_Right.Size);
  this->Bold=std::move(_Right.Bold);
  this->TexSize=std::move(_Right.TexSize);
  this->Font=std::move(_Right.Font);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapFontGen";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberSET(Sys$$<string>::GetRTTI(RTTI),"Name",int(&(((SelfClass*)nullptr)->*(&SelfClass::Name))),"SET","1?\"FixedSys\":\"Arial\"");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"Size",int(&(((SelfClass*)nullptr)->*(&SelfClass::Size))),"SET","1?10:14");
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Bold",int(&(((SelfClass*)nullptr)->*(&SelfClass::Bold))),"SET","false");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"TexSize",int(&(((SelfClass*)nullptr)->*(&SelfClass::TexSize))),"SET","512");
  Info->AddMemberDEF(Sys$$<TWeakPtr<QapFont>>::GetRTTI(RTTI),"Font",int(&(((SelfClass*)nullptr)->*(&SelfClass::Font))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapFontGen";
      }
    };
  public:
public:
  void Do(HWND hWnd)
  {
    if(!Font)return;
    auto&Out=Font->Mem;
    auto&Info=Font->Info;
    CreateFontMem(hWnd,Out,Info,Name,Size,Bold,TexSize);
  }
public:
  static void CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize)
  {
    Out.Free();
    Out.Init(TexSize,TexSize);
    QapColor*pix=Out.get();
    {
      HDC DC=GetDC(hWnd);
      int W=Bold?FW_BOLD:FW_NORMAL;
      int H=-MulDiv(Size,GetDeviceCaps(DC,LOGPIXELSY),72);
      {
        HFONT FNT=CreateFontA(H,0,0,0,W,0,0,0,RUSSIAN_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH,Name.c_str());
        {
          HDC MDC=CreateCompatibleDC(DC);
          {
            HBITMAP BMP=CreateCompatibleBitmap(DC,TexSize,TexSize);
            SelectObject(MDC,BMP);
            RECT Rect; SetRect(&Rect,0,0,TexSize,TexSize);
            FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
            SelectObject(MDC,FNT);
            SetBkMode(MDC,TRANSPARENT);
            SetTextColor(MDC,0xFFFFFF);
            for(int i=0;i<256;i++)TextOutA(MDC,i%16*(TexSize/16),i/16*(TexSize/16),(LPCSTR)&i,1);
            {QapBitmapInfo QBI(TexSize,TexSize);GetDIBits(MDC,BMP,0,TexSize,pix,&QBI.BI,DIB_RGB_COLORS);}
            for(int i=0;i<TexSize*TexSize;i++){pix[i].a=pix[i].r;pix[i].r=255;pix[i].g=255;pix[i].b=255;}
            for(int i=0;i<256;i++){SIZE cs;GetTextExtentPoint32A(MDC,(LPCSTR)&i,1,&cs);Info.Coords[i]=vec2i(cs.cx,cs.cy);}
            DeleteObject(BMP);
          }
          DeleteDC(MDC);
        }
        DeleteObject(FNT); 
      }
      ReleaseDC(hWnd,DC);
    }
    Out.InvertY();
  }
};
class QapFontObject:public QapResource{
public:
  public:typedef QapFontObject SelfClass;public:typedef QapResource ParentClass;
  public:
  QapFont Font;
  QapFontGen FontGen;
  QapTex Tex;
  QapTexGen TexGen;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Font);detail::FieldTryDoReset(this->FontGen);detail::FieldTryDoReset(this->Tex);detail::FieldTryDoReset(this->TexGen);
    }
  public:
    QapFontObject(const QapFontObject&)=delete;QapFontObject(){DoReset();};
  public:
    QapFontObject(QapFontObject&&_Right){operator=(std::move(_Right));}
    void operator=(QapFontObject&&_Right)
    {
      struct hidden{static void foo(QapResource(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        QapResource::operator=(std::move(_Right));
      }
  this->Font=std::move(_Right.Font);
  this->FontGen=std::move(_Right.FontGen);
  this->Tex=std::move(_Right.Tex);
  this->TexGen=std::move(_Right.TexGen);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapFontObject";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<QapFont>::GetRTTI(RTTI),"Font",int(&(((SelfClass*)nullptr)->*(&SelfClass::Font))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapFontGen>::GetRTTI(RTTI),"FontGen",int(&(((SelfClass*)nullptr)->*(&SelfClass::FontGen))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapTex>::GetRTTI(RTTI),"Tex",int(&(((SelfClass*)nullptr)->*(&SelfClass::Tex))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapTexGen>::GetRTTI(RTTI),"TexGen",int(&(((SelfClass*)nullptr)->*(&SelfClass::TexGen))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapFontObject";
      }
    };
  public:
public:
  void SetToDef()
  {
    FontGen.Font=&Font;
    TexGen.Mem=&Font.Mem;
    TexGen.Tex=&Tex;
  }
  void MountDev(QapD3DDev9*pDev)
  {
    if(Tex.DynRes.pDev)return;
    Tex.MountDev(*pDev);
  }
  void DoGenFont(QapD3DDev9*pDev)
  {
    HWND hWnd=pDev->PresParams.pp.hDeviceWindow;
    FontGen.Do(hWnd);
  }
  void DoGenTex()
  {
    TexGen.Do();
  }
  void Do(IEnv&Env)
  {
    if(!Tex.DynRes.pDev)
    {
      QapAssert(!Font.Mem);
      HWND hWnd=Env.pDev->PresParams.pp.hDeviceWindow;
      FontGen.Do(hWnd);
      Tex.MountDev(*Env.pDev);
    }
    if(!TexGen.Tex->Tex)TexGen.Do();
  }
};
class QapQ3Text{
public:
  static int GetLength(const QapFont&Font,const string&Text)
  {
    float xp=0; int i=0;
    while(i<Text.size())
    {
      if(Text[i]!='^')
      {
        int I=(byte)Text[i];
        float cx=float(Font.Info[I].x);
        xp+=cx; i++; continue;
      };
      i++; if(i>Text.size())continue;
      if((Text[i]>='0')&&(Text[i]<='9')){i++; continue;};
      if((Text[i]>='A')&&(Text[i]<='F')){i++; continue;};
    }
    return xp;
  }
public:
  static string ToNormal(const string&Text)
  {
    string s; int i=0;
    while(i<Text.size())
    {
      if(Text[i]!='^'){s.push_back(Text[i++]);continue;}
      i++;if(i>Text.size())continue;
      if((Text[i]>='0')&&(Text[i]<='9')){i++;continue;};
      if((Text[i]>='A')&&(Text[i]<='F')){i++;continue;};
    }
    return s;
  }
public:
  static int AddVertexEx(QapDev*RD,float x,float y,QapColor c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=RD->AddVertex(tmp);
    return id;
  }
  static void DrawQapText(QapDev*RD,QapFont&Font,float X,float Y,const string&Text)
  {
    static QapColor CT[]={
      0xFF252525,0xFFFF0000,0xFF00FF00,0xFFFFFF00,
      0xFF0000FF,0xFFFF00FF,0xFF00FFFF,0xFFFFFFFF,
      0xFFFFFFA8,0xFFFFA8FF,
      0xFFFF8000,0xFF0080FF,0xFFA0A0A0,0xFF808080,0xFF008F00,0xFF0000A8,
    };
    QapDev::BatchScope Scope(*RD);
    {
      typedef QapDev::Ver Vertex;
      int QuadCount=0;
      int VPos=RD->GetVPos();
      float xp=0; int i=0;
      vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
      vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
      QapColor color=RD->GetColor();
      while(i<Text.size())
      {
        unsigned char UC=Text[i];
        if(UC!='^')
        {
          float U=off.x+float(UC%16)/16;
          float V=off.y+float(UC/16)/16;
          vec2f c=Font.Info[UC];
          vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
            int A=AddVertexEx(RD,xp+X+(0.f),Y+(-c.y),color,U+(0.f),V+(+t.y));
            int B=AddVertexEx(RD,xp+X+(c.x),Y+(-c.y),color,U+(t.x),V+(+t.y));
            int C=AddVertexEx(RD,xp+X+(c.x),Y+(+0.f),color,U+(t.x),V+(+0.f));
            int D=AddVertexEx(RD,xp+X+(0.f),Y+(+0.f),color,U+(0.f),V+(+0.f));
          RD->AddTris(A,B,C);
          RD->AddTris(C,D,A);
          xp+=c.x; QuadCount++; i++; continue;
        };
        i++; if(i>Text.size())continue;
        UC=Text[i];
        if((UC>='0')&&(UC<='9')){color=CT[UC-'0'+0x0]; i++; continue;};
        if((UC>='A')&&(UC<='F')){color=CT[UC-'A'+0xA]; i++; continue;};
      }
      if(0)RD->SetColor(color);
    }
  }
};
class QapText{
public:
  static int GetLength(const QapFont&Font,const string&Text)
  {
    int out=0;
    for(int i=0;i<Text.size();i++)
    {
      auto id=(byte)Text[i];
      auto cx=Font.Info[id].x;
      out+=cx;
    }
    return out;
  }
public:
  static int AddVertexEx(QapDev&qDev,float x,float y,QapColor c,float u,float v)
  {
    QapDev::Ver tmp;
    tmp.x=x;
    tmp.y=y;
    tmp.z=0;
    tmp.color=c;
    tmp.tu=u;
    tmp.tv=v;
    auto id=qDev.AddVertex(tmp);
    return id;
  }
  struct t_draw_call{
    char c;
    vec2i pos;
    vec2i size;
  };
  static void add_draw_call(vector<t_draw_call>&out,char c,const vec2i&pos,const vec2i&size)
  {
    t_draw_call tmp;
    tmp.c=c;
    tmp.pos=pos;
    tmp.size=size;
    out.push_back(std::move(tmp));
  }
  template<class FUNC>
  static void PreDrawEx(QapFont&Font,float X,float Y,const string&Text,/*vector<t_draw_call>&out,*/FUNC&func)
  {
    float xp=0; int i=0;
    vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
    vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
    for(int i=0;i<Text.size();i++)
    {
      unsigned char UC=Text[i];
      float U=off.x+float(UC%16)/16;
      float V=off.y+float(UC/16)/16;
      auto c=Font.Info[UC];
      func(UC,vec2i(xp+X,Y),c);
      vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
      xp+=c.x;
    }
  }
  template<class FUNC>
  static void DrawEx(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text,FUNC&func)
  {
    QapDev::BatchScope Scope(qDev);
    {
      typedef QapDev::Ver Vertex;
      int QuadCount=0;
      int VPos=qDev.GetVPos();
      float xp=0; int i=0;
      vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
      vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5;
      QapColor color=qDev.GetColor();
      for(int i=0;i<Text.size();i++)
      {
        unsigned char UC=Text[i];
        float U=off.x+float(UC%16)/16;
        float V=off.y+float(UC/16)/16;
        auto c=Font.Info[UC];
        func(UC,vec2i(xp+X,Y),c);
        vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
          int A=AddVertexEx(qDev,xp+X+(0.f),Y+(-c.y),color,U+(0.f),V+(+t.y));
          int B=AddVertexEx(qDev,xp+X+(c.x),Y+(-c.y),color,U+(t.x),V+(+t.y));
          int C=AddVertexEx(qDev,xp+X+(c.x),Y+(+0.f),color,U+(t.x),V+(+0.f));
          int D=AddVertexEx(qDev,xp+X+(0.f),Y+(+0.f),color,U+(0.f),V+(+0.f));
        qDev.AddTris(A,B,C);
        qDev.AddTris(C,D,A);
        xp+=c.x; QuadCount++;
      }
    }
  }
  static void DoNothing(unsigned char UC,const vec2i&p,const vec2i&s){}
  static void Draw(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text)
  {
    DrawEx(qDev,Font,X,Y,Text,DoNothing);
  }
};
#pragma once
extern bool QapPublicUberFullSaverBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullLoaderBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullSaverProto(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern string QapPublicUberFullSaverProtoToStr(IEnvRTTI&Env,IQapRawObject&&Object);
extern bool QapPublicUberFullSaverBinMem(IEnvRTTI&Env,IQapRawObject&&Object,string&Out);
extern bool QapPublicUberFullLoaderBinMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp);
extern bool QapPublicUberFullCloneBinMem(IEnvRTTI&Env,IQapRawObject&&Dest,IQapRawObject&&Source);
inline int&get_QapClone_counter(){static int counter=0;return counter;}
inline real&QapClone_timer(){static real time=0;return time;}
template<class TYPE>
inline bool QapClone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  static auto&counter=get_QapClone_counter();counter++;
  QapClock clock;
  clock.Start();
  bool ok=QapPublicUberFullCloneBinMem(Env,QapRawUberObject(dest),QapRawUberObject(source));
  clock.Stop();
  QapClone_timer()+=clock.MS();
  return ok;
}
struct ICompileUnit;
struct ICompileUnitMan
{
  virtual void add(ICompileUnit*pUnit)=0;
  static ICompileUnitMan&get_man();
};
struct ICompileUnit{
  virtual const char*get_filename()const=0;
  virtual void RegAll(IEnvRTTI&Env)=0;
  virtual void Run(IEnvRTTI&Env)=0;
  ICompileUnit(){ICompileUnitMan::get_man().add(this);}
};
static string cur_date_str()
{
  time_t rawtime;
  tm*ptm;
  time(&rawtime);
  ptm=gmtime(&rawtime);
  char buff[128];
  sprintf(&buff[0],"%04u.%02u.%02u %02u:%02u:%02u\0",
    1900+ptm->tm_year,
    ptm->tm_mon+1,
    ptm->tm_mday,
    ptm->tm_hour,ptm->tm_min,ptm->tm_sec
  );
  return buff;
}
class ISubProgram{
public:
  public:typedef ISubProgram SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  string Caption;
  bool Enabled;
  bool NeedRemove;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->Caption);(this->Enabled)=(true);detail::FieldTryDoReset(this->NeedRemove);
    }
  public:
    ISubProgram(const ISubProgram&)=delete;ISubProgram(){DoReset();};
  public:
    ISubProgram(ISubProgram&&_Right){operator=(std::move(_Right));}
    void operator=(ISubProgram&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Caption=std::move(_Right.Caption);
  this->Enabled=std::move(_Right.Enabled);
  this->NeedRemove=std::move(_Right.NeedRemove);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="ISubProgram";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"Caption",int(&(((SelfClass*)nullptr)->*(&SelfClass::Caption))),"DEF","$");
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Enabled",int(&(((SelfClass*)nullptr)->*(&SelfClass::Enabled))),"SET","true");
  Info->AddMemberDEF(Sys$$<bool>::GetRTTI(RTTI),"NeedRemove",int(&(((SelfClass*)nullptr)->*(&SelfClass::NeedRemove))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "ISubProgram";
      }
    };
  public:
public:
  class t_context{
  public:
    IEnvRTTI&Env;
    operator IEnvRTTI&(){return Env;}
  };
public:
  virtual void Update(t_context&Env){}
  void TryUpdate(t_context&con)
  {
    if(NeedRemove)return;
    if(!Enabled)return;
    Update(con);
  }
};
class TProgramNode:public ISubProgram{
public:
  public:typedef TProgramNode SelfClass;public:typedef ISubProgram ParentClass;
  public:
  vector<TAutoPtr<ISubProgram>> Programs;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Programs);
    }
  public:
    TProgramNode(const TProgramNode&)=delete;TProgramNode(){DoReset();};
  public:
    TProgramNode(TProgramNode&&_Right){operator=(std::move(_Right));}
    void operator=(TProgramNode&&_Right)
    {
      struct hidden{static void foo(ISubProgram(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        ISubProgram::operator=(std::move(_Right));
      }
  this->Programs=std::move(_Right.Programs);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TProgramNode";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<ISubProgram>>>::GetRTTI(RTTI),"Programs",int(&(((SelfClass*)nullptr)->*(&SelfClass::Programs))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TProgramNode";
      }
    };
  public:
public:
  typedef vector<TAutoPtr<ISubProgram>> TArray;
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Programs.resize(Programs.size()+1);
    return Programs.back().build<TYPE>(Env);
  }
  void ForceUpdate(t_context&con)
  {
    auto&arr=Programs;
    for(int i=0;i<arr.size();i++)
    {
      auto*ex=arr[i].get();
      if(!ex)continue;
      ex->TryUpdate(con);
    }
  }
  void Update(t_context&con)
  {
    if(!Enabled)return;
    ForceUpdate(con);
  }
public:
  TAutoPtr<ISubProgram>&front(){
    return Programs.front();
  }
  TAutoPtr<ISubProgram>&back(){
    return Programs.back();
  }
public:
  bool empty()const{return Programs.empty();}
};
class QapRenderProgram;
class QapPluginMan;
class IUnitProgram{
public:
  public:typedef IUnitProgram SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  bool Deaded;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);(this->Deaded)=(false);
    }
  public:
    IUnitProgram(const IUnitProgram&)=delete;IUnitProgram(){DoReset();};
  public:
    IUnitProgram(IUnitProgram&&_Right){operator=(std::move(_Right));}
    void operator=(IUnitProgram&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->Deaded=std::move(_Right.Deaded);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IUnitProgram";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"Deaded",int(&(((SelfClass*)nullptr)->*(&SelfClass::Deaded))),"SET","false");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IUnitProgram";
      }
    };
  public:
public:
  struct TBuildContext{
    IEnvRTTI&Env;
    QapPluginMan&PluginMan;
    QapRenderProgram&Qrp;
  };
  virtual void OnBuild(TBuildContext&Context){}
  virtual void Update(IEnvRTTI&Env){}
};
class TReloadDetector{
public:
  public:typedef TReloadDetector SelfClass;
  public:
  bool needinit;
  bool fresh;
    public:
    void DoReset()
    {
      {
      }
  (this->needinit)=(false);(this->fresh)=(true);
    }
  public:
    TReloadDetector(const TReloadDetector&)=delete;TReloadDetector(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TReloadDetector";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<bool>::GetRTTI(RTTI),"needinit",int(&(((SelfClass*)nullptr)->*(&SelfClass::needinit))),"SET","false");
  Info->AddMemberSYS(0,nullptr,"fresh",int(&(((SelfClass*)nullptr)->*(&SelfClass::fresh))),"SYS");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TReloadDetector";
      }
    };
  public:
public:
  void Init(){fresh=false;needinit=false;}
  void Free(){fresh=true;};
  void Update(){needinit=fresh;}
};
class QapKeyboard{
public:
  struct TKeyState{
    static const int MAX_KEY=263;
    bool data[MAX_KEY];
    TKeyState(){SetToDef();}
    void SetToDef(){for(int i=0;i<MAX_KEY;i++)data[i]=false;}
    bool&operator[](int index)
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      { 
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    const bool&operator[](int index)const
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      { 
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
  };
public:
  public:typedef QapKeyboard SelfClass;
  public:
  int LastKey;
  char LastChar;
  bool NeedReset;
  bool News;
  TKeyState Down;
  TKeyState Changed;
    public:
    void DoReset()
    {
      {
      }
  (this->LastKey)=(0);(this->LastChar)=(0);detail::FieldTryDoReset(this->NeedReset);(this->News)=(false);detail::FieldTryDoReset(this->Down);detail::FieldTryDoReset(this->Changed);
    }
  public:
    QapKeyboard(const QapKeyboard&)=delete;QapKeyboard(){DoReset();};
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapKeyboard";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"LastKey",int(&(((SelfClass*)nullptr)->*(&SelfClass::LastKey))),"SET","0");
  Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"LastChar",int(&(((SelfClass*)nullptr)->*(&SelfClass::LastChar))),"SET","0");
  Info->AddMemberDEF(Sys$$<bool>::GetRTTI(RTTI),"NeedReset",int(&(((SelfClass*)nullptr)->*(&SelfClass::NeedReset))),"DEF","$");
  Info->AddMemberSYS(0,nullptr,"News",int(&(((SelfClass*)nullptr)->*(&SelfClass::News))),"SYS");
  Info->AddMemberSYD(0,nullptr,"Down",int(&(((SelfClass*)nullptr)->*(&SelfClass::Down))),"SYD");
  Info->AddMemberSYD(0,nullptr,"Changed",int(&(((SelfClass*)nullptr)->*(&SelfClass::Changed))),"SYD");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapKeyboard";
      }
    };
  public:
public:
  void QapKeyboard::operator=(const QapKeyboard&){
    QapDebugMsg("QapKeyboard is noncopyable");
  }
  void try_reset()
  {
    if(!NeedReset)return;
    reset();
  }
  void reset()
  {
    NeedReset=false;
    LastKey=0;
    LastChar=0;
    News=false;
    Down.SetToDef();
    Changed.SetToDef();
  }
  void KeyUpdate(int Key,bool Value)
  {
    if(Value)LastKey=Key;
    Down[Key]=Value;Changed[Key]=true;
  }
  void CharUpdate(char c)
  {
    LastChar=c;News=true;
  }
  void Sync()
  {
    this->News=false;Changed.SetToDef();
  }
  bool OnDown(int index)const{
    return Changed[index]&&Down[index];
  }
};
class eQuad{
public:
  public:typedef eQuad SelfClass;
  public:
  int x;
  int y;
  int w;
  int h;
    public:
    void DoReset()
    {
      {
      }
  (this->x)=(320);(this->y)=(240);(this->w)=(320);(this->h)=(240);
    }
  public:
    eQuad(const eQuad&)=delete;eQuad(){DoReset();};
  public:
    eQuad(eQuad&&_Right){operator=(std::move(_Right));}
    void operator=(eQuad&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->x=std::move(_Right.x);
  this->y=std::move(_Right.y);
  this->w=std::move(_Right.w);
  this->h=std::move(_Right.h);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="eQuad";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"SET","320");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"y",int(&(((SelfClass*)nullptr)->*(&SelfClass::y))),"SET","240");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"w",int(&(((SelfClass*)nullptr)->*(&SelfClass::w))),"SET","320");
  Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"h",int(&(((SelfClass*)nullptr)->*(&SelfClass::h))),"SET","240");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "eQuad";
      }
    };
  public:
public:
  void Set(int x,int y,int w,int h)
  {
    this->x=x;this->y=y;this->w=w;this->h=h;
  }
  vec2i&GetPos(){return *(vec2i*)(void*)(&this->x);}
  vec2i&GetSize(){return *(vec2i*)(void*)(&this->w);}
  void SetAs(const vec2i&pos,const vec2i&size){GetPos()=pos;GetSize()=size;}
  RECT GetWinRect(){RECT tmp={x,y,x+w,y+h};return tmp;}
  void SetWinRect(const RECT&rect){eQuad&r=*(eQuad*)(void*)(&rect);Set(r.x,r.y,r.w-r.x,r.h-r.y);}
  void SetSize(const SIZE&size){w=size.cx;h=size.cy;}
  static eQuad getFullScreen(){eQuad tmp;auto mode=GetScreenMode();tmp.Set(0,0,mode.W,mode.H);return std::move(tmp);}
  void setAtCenter(const eQuad&quad){
    QapAssert(quad.w>=w);
    QapAssert(quad.h>=h);
    x=(quad.w-w)/2;
    y=(quad.h-h)/2;
  }
  void subpos(const eQuad&q){
    x-=q.x;
    y-=q.y;
  }
  void setAtCenterScreen(){setAtCenter(getFullScreen());}
};
enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};
class IProgramD3D9{
public:
  public:typedef IProgramD3D9 SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
  QapD3D9 D9;
  QapD3DDev9 D9Dev;
  TProgramNode UserCode;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);detail::FieldTryDoReset(this->D9);detail::FieldTryDoReset(this->D9Dev);detail::FieldTryDoReset(this->UserCode);
    }
  public:
    IProgramD3D9(const IProgramD3D9&)=delete;IProgramD3D9(){DoReset();};
  public:
    IProgramD3D9(IProgramD3D9&&_Right){operator=(std::move(_Right));}
    void operator=(IProgramD3D9&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
  this->D9=std::move(_Right.D9);
  this->D9Dev=std::move(_Right.D9Dev);
  this->UserCode=std::move(_Right.UserCode);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="IProgramD3D9";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapD3D9>::GetRTTI(RTTI),"D9",int(&(((SelfClass*)nullptr)->*(&SelfClass::D9))),"DEF","$");
  Info->AddMemberDEF(Sys$$<QapD3DDev9>::GetRTTI(RTTI),"D9Dev",int(&(((SelfClass*)nullptr)->*(&SelfClass::D9Dev))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TProgramNode>::GetRTTI(RTTI),"UserCode",int(&(((SelfClass*)nullptr)->*(&SelfClass::UserCode))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "IProgramD3D9";
      }
    };
  public:
public:
  virtual vec2i WindowGetClientSize(){QapDebugMsg("no way");return vec2i(128,128);}
  virtual QapKeyboard&GetKeyBoard(){QapDebugMsg("no way");return *(QapKeyboard*)nullptr;}
  virtual vec2i WindowGetMousePos(){QapDebugMsg("no way");return vec2i(128,128);}
  virtual eQuad&WindowGetQuad(){QapDebugMsg("no way");return *(eQuad*)nullptr;}
  virtual void WindowUpdateMode(){QapDebugMsg("no way");return;}
  virtual void WindowFullScreen(bool fullscreen){QapDebugMsg("no way");return;}
  virtual int WindowGetzDelta(){QapDebugMsg("no way");return 0;}
};
class ITreeDebuggerBranch{
public:
  public:typedef ITreeDebuggerBranch SelfClass;
  public:
  TSelfPtr<SelfClass> Self;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->Self);
    }
  public:
    ITreeDebuggerBranch(const ITreeDebuggerBranch&)=delete;ITreeDebuggerBranch(){DoReset();};
  public:
    ITreeDebuggerBranch(ITreeDebuggerBranch&&_Right){operator=(std::move(_Right));}
    void operator=(ITreeDebuggerBranch&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->Self=std::move(_Right.Self);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="ITreeDebuggerBranch";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<TSelfPtr<SelfClass>>::GetRTTI(RTTI),"Self",int(&(((SelfClass*)nullptr)->*(&SelfClass::Self))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "ITreeDebuggerBranch";
      }
    };
  public:
public:
  virtual TRawPtr GetRawPtr(){QapDebugMsg("no way.");TRawPtr tmp(nullptr,nullptr); return tmp;}
  virtual string GetCode(){QapDebugMsg("no way.");return "";}
};
class QapPluginMan:public ISubProgram{
public:
  public:typedef QapPluginMan SelfClass;public:typedef ISubProgram ParentClass;
  public:
  vector<TAutoPtr<IUnitProgram>> Items;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->Items);
    }
  public:
    QapPluginMan(const QapPluginMan&)=delete;QapPluginMan(){DoReset();};
  public:
    QapPluginMan(QapPluginMan&&_Right){operator=(std::move(_Right));}
    void operator=(QapPluginMan&&_Right)
    {
      struct hidden{static void foo(ISubProgram(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        ISubProgram::operator=(std::move(_Right));
      }
  this->Items=std::move(_Right.Items);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="QapPluginMan";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<IUnitProgram>>>::GetRTTI(RTTI),"Items",int(&(((SelfClass*)nullptr)->*(&SelfClass::Items))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "QapPluginMan";
      }
    };
  public:
public:
  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }
  IUnitProgram*unsafe_AddItem(IEnvRTTI&Env,TType*pType)
  {
    Items.resize(Items.size()+1);
    auto&back=Items.back();
    back.Product.pType=pType;
    back.Product.Init();
    return back.get();
  }
  void MakeAll(IEnvRTTI&Env,QapRenderProgram*pQRP,TType*pIUnitProgram)
  {
    IUnitProgram::TBuildContext Context={Env,*this,*pQRP};
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=ex.Type.get();
      if(!pType->IsBasedOn(pIUnitProgram))continue;
      if(!pType->Factory)continue;
      unsafe_AddItem(Env,pType)->OnBuild(Context);
    }
  }
  void Update(t_context&con)
  {
    auto&arr=Items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*pItem=ex.get();
      pItem->Update(con.Env);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      auto*pItem=ex.get();
      if(pItem->Deaded)ex=nullptr;
    }
    QapClean(Items);
  }
public:
  bool empty()const{return Items.empty();}
};
class GlobalEnv{
public:
  HINSTANCE hInstance;
  HINSTANCE hPrevInstance;
  LPSTR lpCmdLine;
  int nCmdShow;
public:
  GlobalEnv(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
  ):
    hInstance(hInstance),
    hPrevInstance(hPrevInstance),
    lpCmdLine(lpCmdLine),
    nCmdShow(nCmdShow)
  {GlobalEnv::Get(this);}
public:
  static const GlobalEnv&Get(GlobalEnv*ptr=nullptr)
  {
    static GlobalEnv*pGE=nullptr;
    if(!pGE)std::swap(pGE,ptr);
    QapAssert(pGE&&!ptr);
    return *pGE;
  }
private:
  GlobalEnv(const GlobalEnv&);
  void operator=(const GlobalEnv&);
};
static bool IsKeyDown(int vKey){int i=GetAsyncKeyState(vKey); return i<0;}
static bool is_first_part_of(const string&text,const string&first_part){return first_part==text.substr(0,first_part.size());}
static string without_first_part(const string&text,const string&first_part){return text.substr(first_part.size());}
static bool remove_first_part_of(string&text,const string&first_part){if(!is_first_part_of(text,first_part))return false;text=without_first_part(text,first_part);return true;}
class TOutDev{
public:
  class TMemberID;class TSubType;class TVecID;class TChunk;class TField;
  class DevCmd;
  class IVisitor{
  public:
      virtual void Do(TMemberID*p)=0;virtual void Do(TSubType*p)=0;virtual void Do(TVecID*p)=0;virtual void Do(TChunk*p)=0;virtual void Do(TField*p)=0;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
        void Do(TMemberID*p){ptr=get(p);}void Do(TSubType*p){ptr=get(p);}void Do(TVecID*p){ptr=get(p);}void Do(TChunk*p){ptr=get(p);}void Do(TField*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(DevCmd*p){
      if(!p)return nullptr;Is<TYPE,IVisitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  class DevCmd{
  public:
  public:typedef TOutDev OwnerClass;
  public:typedef DevCmd SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    DevCmd(const DevCmd&)=delete;DevCmd(){DoReset();};
  public:
    DevCmd(DevCmd&&_Right){operator=(std::move(_Right));}
    void operator=(DevCmd&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="DevCmd";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "DevCmd";
      }
    };
  public:
  public:
    virtual void Use(IVisitor&A){QapDebugMsg("no way.");}
  };
    class TMemberID:public DevCmd{
    public:
  public:typedef TOutDev OwnerClass;
  public:typedef TMemberID SelfClass;public:typedef DevCmd ParentClass;
  public:
   int id;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
   (this->id)=(-1); 
    }
  public:
    TMemberID(const TMemberID&)=delete;TMemberID(){DoReset();};
  public:
    TMemberID(TMemberID&&_Right){operator=(std::move(_Right));}
    void operator=(TMemberID&&_Right)
    {
      struct hidden{static void foo(DevCmd(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DevCmd::operator=(std::move(_Right));
      }
   this->id=std::move(_Right.id);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TMemberID";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","-1");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TMemberID";
      }
    };
  public:
    public:
      TMemberID(int id):id(id){}
    public:
      public:void Use(IVisitor&A){A.Do(this);}static SelfClass*UberCast(DevCmd*p){return IVisitor::UberCast<SelfClass>(p);}
    };
    class TSubType:public DevCmd{
    public:
  public:typedef TOutDev OwnerClass;
  public:typedef TSubType SelfClass;public:typedef DevCmd ParentClass;
  public:
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
    }
  public:
    TSubType(const TSubType&)=delete;TSubType(){DoReset();};
  public:
    TSubType(TSubType&&_Right){operator=(std::move(_Right));}
    void operator=(TSubType&&_Right)
    {
      struct hidden{static void foo(DevCmd(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DevCmd::operator=(std::move(_Right));
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TSubType";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TSubType";
      }
    };
  public:
    public:
      public:void Use(IVisitor&A){A.Do(this);}static SelfClass*UberCast(DevCmd*p){return IVisitor::UberCast<SelfClass>(p);}
    };
    class TVecID:public DevCmd{
    public:
  public:typedef TOutDev OwnerClass;
  public:typedef TVecID SelfClass;public:typedef DevCmd ParentClass;
  public:
   int id;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
   (this->id)=(-1); 
    }
  public:
    TVecID(const TVecID&)=delete;TVecID(){DoReset();};
  public:
    TVecID(TVecID&&_Right){operator=(std::move(_Right));}
    void operator=(TVecID&&_Right)
    {
      struct hidden{static void foo(DevCmd(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DevCmd::operator=(std::move(_Right));
      }
   this->id=std::move(_Right.id);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TVecID";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberSET(Sys$$<int>::GetRTTI(RTTI),"id",int(&(((SelfClass*)nullptr)->*(&SelfClass::id))),"SET","-1");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TVecID";
      }
    };
  public:
    public:
      TVecID(int id):id(id){}
    public:
      public:void Use(IVisitor&A){A.Do(this);}static SelfClass*UberCast(DevCmd*p){return IVisitor::UberCast<SelfClass>(p);}
    };
    class TChunk:public DevCmd{
    public:
  public:typedef TOutDev OwnerClass;
  public:typedef TChunk SelfClass;public:typedef DevCmd ParentClass;
  public:
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
    }
  public:
    TChunk(const TChunk&)=delete;TChunk(){DoReset();};
  public:
    TChunk(TChunk&&_Right){operator=(std::move(_Right));}
    void operator=(TChunk&&_Right)
    {
      struct hidden{static void foo(DevCmd(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DevCmd::operator=(std::move(_Right));
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TChunk";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TChunk";
      }
    };
  public:
    public:
      public:void Use(IVisitor&A){A.Do(this);}static SelfClass*UberCast(DevCmd*p){return IVisitor::UberCast<SelfClass>(p);}
    };
    class TField:public DevCmd{
    public:
  public:typedef TOutDev OwnerClass;
  public:typedef TField SelfClass;public:typedef DevCmd ParentClass;
  public:
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
    }
  public:
    TField(const TField&)=delete;TField(){DoReset();};
  public:
    TField(TField&&_Right){operator=(std::move(_Right));}
    void operator=(TField&&_Right)
    {
      struct hidden{static void foo(DevCmd(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        DevCmd::operator=(std::move(_Right));
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TField";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TField";
      }
    };
  public:
    public:
      public:void Use(IVisitor&A){A.Do(this);}static SelfClass*UberCast(DevCmd*p){return IVisitor::UberCast<SelfClass>(p);}
    };
  class TContext{
  public:
    string head;
    DevCmd*pCmd;
  public:
    TType*pType;
    void*pValue;
  public:
    TContext():pCmd(nullptr),pType(nullptr),pValue(nullptr){}
  };
  class TCmdVisitor:public IVisitor{
  public:
    struct t_dev{
      bool ok=true;
      const char*pcode=nullptr;
      int line=-1;
      void err(const char*pcode,int line)
      {
        ok=false;
        this->pcode=pcode;
        this->line=line;
      }
    };
  public:
    t_dev&dev;
    TContext*pContext;
  public:
    TCmdVisitor(t_dev&dev,TContext*pContext):dev(dev),pContext(pContext){}
  public:
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
      if(!(pMetaType)){dev.err("pMetaType",159);return;};
      if(!(id<pMetaType->Members.size())){dev.err("id<pMetaType->Members.size()",161);return;};
      if(!(id>=0)){dev.err("id>=0",162);return;};
      auto&ex=pMetaType->Members[id];
      pContext->pValue=ex.getValue(pContext->pValue);
      pContext->pType=ex.Type.get();
      pContext->head=ex.Name;
    }
    void Do(TSubType*p)
    {
      pContext->pValue=pContext->pValue;
      pContext->pType=pContext->pType->GetSubType();
      pContext->head="";
      if(!(pContext->pType)){dev.err("pContext->pType",173);return;};
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(pContext->pType);
      if(!(pMetaType)){dev.err("pMetaType",179);return;};
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(pContext->pValue);
      if(!((id>=0)&&(id<count))){dev.err("(id>=0)&&(id<count)",183);return;};
      pContext->pValue=pVecAPI->GetItem(pContext->pValue,id);
      pContext->pType=pElemType;
      pContext->head="["+IToS(id)+"]";
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(pContext->pType);
      if(!(pMetaType)){dev.err("pMetaType",191);return;};
      TAutoPtr<void>&value=*(TAutoPtr<void>*)pContext->pValue;
      pContext->pValue=value.get();
      pContext->pType=value.Product.pType.get();
      pContext->head="";
    }
    void Do(TField*p)
    {
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(pContext->pType);
      if(!(pMetaType)){dev.err("pMetaType",201);return;};
      TFieldPtr&value=*(TFieldPtr*)pContext->pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      pContext->pValue=value.getValue();
      pContext->pType=field_type;
      pContext->head=fieldname.empty()?"object":"object."+fieldname;
    }
  };
public:
  class TCmdHeadVisitor:public IVisitor{
  public:
    TContext Context;
    string out;
    TCmdHeadVisitor(){out="Root";}
  public:
    void add_dot(){
      bool flag=out.substr(out.size()-2)=="->";
      if(!flag)out.push_back('.');
    };
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(Context.pType);
      QapAssert(pMetaType);
      auto&ex=pMetaType->Members[id];
      add_dot();
      out+=ex.Name;
    }
    void Do(TSubType*p)
    {
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(Context.pType);
      QapAssert(pMetaType);
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(Context.pValue);
      QapAssert((id>=0)&&(id<count));
      out+="["+IToS(id)+"]";
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(Context.pType);
      QapAssert(pMetaType);
      TAutoPtr<void>&value=*(TAutoPtr<void>*)Context.pValue;
      auto*pObjectType=value.Product.pType.get();
      if(pObjectType==pMetaType)
      {
        out+="->";
        return;
      }
      string fn=pObjectType->GetFullName();
      add_dot();
      out+="get{"+fn+"}()";
    }
    void Do(TField*p)
    {
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(Context.pType);
      QapAssert(pMetaType);
      TFieldPtr&value=*(TFieldPtr*)Context.pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      string ft_fn=field_type->GetFullName();
      string ot_fn=object_type->GetFullName();
      string code=fieldname.empty()?"object":"object."+fieldname;
      if(true||object_type==field_type){
        add_dot();
        out=out+"getValue<"+ft_fn+">()";
      }else{
      }
    }
  };
public:
  class TCmdOffsetVisitorEx:public IVisitor{
  public:
    struct TContextPoint{
      TType*pType;
      void*pValue;
    };
    struct TContext{
      TContextPoint Object;
      TContextPoint Field;
      int Offset;
    };
    TContext*pContext;
  public:
    void Do(TMemberID*p)
    {
      int id=p->id;
      TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      auto&ex=pMetaType->Members[id];
      pContext->Offset+=ex.Offset;
      TContextPoint field={ex.Type.get(),ex.getValue(pContext->Field.pValue)};
      pContext->Field=field;
    }
    void Do(TSubType*p)
    {
      pContext->Field.pType=pContext->Field.pType->GetSubType();
    }
    void Do(TVecID*p)
    {
      int id=p->id;
      TTypeVector*pMetaType=TTypeVector::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      TType*pElemType=pMetaType->ElementType.get();
      auto*pVecAPI=pMetaType->VecAPI.get();
      int count=pVecAPI->GetCount(pContext->Field.pValue);
      QapAssert((id>=0)&&(id<count));
      TContextPoint field={pElemType,pVecAPI->GetItem(pContext->Field.pValue,id)};
      pContext->Field=field;
      pContext->Object=field;
      pContext->Offset=0;
    }
    void Do(TChunk*p)
    {
      TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      TAutoPtr<void>&value=*(TAutoPtr<void>*)pContext->Field.pValue;
      TType*pProductType=value.Product.pType.get();
      TContextPoint field={pProductType,value.get()};
      pContext->Field=field;
      pContext->Object=field;
      pContext->Offset=0;
    }
    void Do(TField*p)
    {
      TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(pContext->Field.pType);
      QapAssert(pMetaType);
      TFieldPtr&value=*(TFieldPtr*)pContext->Field.pValue;
      TType*object_type=value.object.type.get();
      TType*field_type=value.type.get();
      auto offset=value.offset;
      SubFieldsInfo::TFieldInfo Info={field_type,offset};
      string fieldname=SubFieldsInfo::FieldInfoToFieldName(object_type,Info);
      TContextPoint object={object_type,value.object.ptr.get()};
      TContextPoint field={field_type,value.getValue()};
      pContext->Field=field;
      pContext->Object=object;
      pContext->Offset=offset;
    }
  };
public:
  class TCmdCloneVisitor:public IVisitor{
  public:
    TAutoPtr<DevCmd>pCmd;
    IEnvRTTI*pEnv;
  public:
    void Init(IEnvRTTI*pEnv)
    {
      this->pEnv=pEnv;
    }
  public:
    void Do(TMemberID*p)
    {
      auto*ptr=pCmd.build<TMemberID>(*pEnv);
      ptr->id=p->id;
    }
    void Do(TSubType*p)
    {
      auto*ptr=pCmd.build<TSubType>(*pEnv);
    }
    void Do(TVecID*p)
    {
      auto*ptr=pCmd.build<TVecID>(*pEnv);
      ptr->id=p->id;
    }
    void Do(TChunk*p)
    {
      auto*ptr=pCmd.build<TChunk>(*pEnv);
    }
    void Do(TField*p)
    {
      auto*ptr=pCmd.build<TField>(*pEnv);
    }
  };
public:
  public:typedef TOutDev SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    TOutDev(const TOutDev&)=delete;TOutDev(){DoReset();};
  public:
    TOutDev(TOutDev&&_Right){operator=(std::move(_Right));}
    void operator=(TOutDev&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="TOutDev";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<DevCmd>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<TMemberID>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<TSubType>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<TVecID>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<TChunk>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<TField>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "TOutDev";
      }
    };
  public:
public:
};
class TIsSameVisitor:public IVisitorRTTI{
public:
  typedef TIsSameVisitor SelfClass;
public:
  class TBranch:public TOutDev{
  public:
    TContext top;
    vector<TContext> items;
  public:
    void push_impl(){items.push_back(top);}
    void pop_impl(){top=items.back();items.pop_back();}
    TContext&back(){return items.back();}
    TContext&front(){return items.front();}
    int size(){return items.size();}
    TContext&operator[](int index){return items[index];}
  public:
    void push(DevCmd*pCmd)
    {
      QapAssert(!top.pCmd&&top.head.empty());
      push_impl();
      if(pCmd)
      {
        TCmdVisitor::t_dev dev;
        TCmdVisitor CV(dev,&top);
        pCmd->Use(CV);
        QapAssert(dev.ok);
        auto&back=this->back();
        back.head=std::move(top.head);
        back.pCmd=std::move(pCmd);
      }else{
        top.pType=nullptr;
        top.pValue=nullptr;
      }
      top.pCmd=nullptr;
      top.head.clear();
    }
    void pop()
    {
      QapAssert(!top.pCmd&&top.head.empty());
      pop_impl();
      top.pCmd=nullptr;
      top.head.clear();
    }
  };
  void fail(){ok=false;}
  typedef TOutDev::DevCmd DevCmd;
  void push(DevCmd*pCmd)
  {
    bef.push(pCmd);
    aft.push(pCmd);
  }
  void pop()
  {
    bef.pop();
    aft.pop();
  }
  template<class TYPE>
  static bool Exec(IEnvRTTI&Env,TYPE&bef,TYPE&aft)
  {
    TRawPtr rp_bef(Env,bef);
    TRawPtr rp_aft(Env,aft);
    TIsSameVisitor::TBranch branch_bef;
    TIsSameVisitor::TBranch branch_aft;
    branch_bef.top.pType=rp_bef.pType;
    branch_bef.top.pValue=rp_bef.pValue;
    branch_aft.top.pType=rp_aft.pType;
    branch_aft.top.pValue=rp_aft.pValue;
    TIsSameVisitor V(branch_bef,branch_aft);
    V.pTopType->Use(V);
    return V.ok;
  }
public:
  TBranch&bef;
  TBranch&aft;
  TType*&pTopType;
  bool ok;
public:
  TIsSameVisitor(TBranch&bef,TBranch&aft):bef(bef),aft(aft),ok(true),pTopType(bef.top.pType){}
public:
  void Do(TTypeStruct*p)
  {
    if(bef.top.pType!=aft.top.pType)return fail();
    auto*subtype=p->SubType.get();
    auto&arr=p->Members;
    if(subtype)
    {
      TOutDev::TSubType tmp;
      push(&tmp);
      pTopType->Use(*this);
      pop();
      if(!ok)return;
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      TOutDev::TMemberID tmp(i);
      push(&tmp);
      pTopType->Use(*this);
      pop();
      if(!ok)return;
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeSys*p)
  {
    if(bef.top.pType!=aft.top.pType)return fail();
    auto*pbio=p->BinIO.get();
    auto result=pbio->IsSame(bef.top.pValue,aft.top.pValue);
    if(!result)return fail();
  }
  void Do(TTypeVector*p)
  {
    if(bef.top.pType!=aft.top.pType)return fail();
    auto*VecAPI=p->VecAPI.get();
    int CountBef=VecAPI->GetCount(bef.top.pValue);
    int CountAft=VecAPI->GetCount(aft.top.pValue);
    if(CountBef!=CountAft)return fail();
    if(!CountBef)return;
    TType*elemType=p->ElementType.get();
    for(int i=0;i<CountBef;i++)
    {
      TOutDev::TVecID tmp(i);
      push(&tmp);
      pTopType->Use(*this);
      pop();
      if(!ok)return;
    }
  }
  void Do(TTypeSelfPtr*p){
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    TAutoPtr<void>&valueBef=*(TAutoPtr<void>*)bef.top.pValue;
    TAutoPtr<void>&valueAft=*(TAutoPtr<void>*)aft.top.pValue;
    if(bool(valueBef)!=bool(valueAft))return fail();
    if(!valueBef)return;
    TOutDev::TChunk tmp;
    push(&tmp);
    pTopType->Use(*this);
    pop();
  }
  void Do(TTypeWeakPtr*p){
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeHardPtr*p){
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");return fail();
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("no way");return fail();
  }
};
struct t_error_tool{
  struct t_subline{
    string cpp;
    string low;
    string error;
  public:
    static string toCpp(const string&raw){CppString cpp=raw;return cpp.data;}
    static int toCppLen(const string&raw){CppString cpp=raw;return cpp.data.size();}
    static string gen(size_t count,char c){string tmp;tmp.resize(count,c);return tmp;}
    static t_subline go(const string&line,size_t offset){
      t_subline out;
      QapAssert(line.size()<=1024);
      if(offset>=line.size()){
        out.error="offset<=line.size()";
        return out;
      }
      string target=CToS(line[offset]);
      int len=toCppLen(target);
      string top=toCpp(line.substr(0,offset));
      string low=gen(top.size(),'-')+gen(len,'^');
      top+=toCpp(line.substr(offset));
      out.cpp=top;
      out.low=low;
      return out;
    }
  };
  struct t_line_info{
    size_t line_id;
    size_t curpos;
    bool ok;
    static t_line_info get(const string&mem,size_t pos){
      t_line_info out={0,0,false};
      out.go(mem,pos);
      return out;
    }
    void go(const string&mem,size_t pos){
      QapAssert(pos<mem.size());
      line_id=0;
      curpos=0;
      ok=true;
      for(int i=0;i<pos;i++){
        if(mem[i]=='\n'){line_id++;curpos=i+1;ok=true;}
      }
    }
  };
  static string get_codefrag(const string&code,size_t pos){
    auto subline_go=t_subline::go;
    auto go=[&subline_go,&pos](const t_line_info&info,const string&line,size_t offset,const string&sep)->string{
      auto sub=subline_go(line,offset);
      QapAssert(sub.error.empty());
      return "{\"line\":"+IToS(info.line_id)+",\"pos\":"+IToS(pos-info.curpos)+"}\n\""+sub.cpp+"\" "+sep+"\n-"+sub.low;
    };
    QapAssert(!code.empty());
    QapAssert(pos<code.size());
    auto info=t_line_info::get(code,pos);
    if(!info.ok){
      QapAssert(false);
    }
    int offset=pos-info.curpos;
    auto eol=code.find('\n',info.curpos);
    if(eol==string::npos){
      auto line=code.substr(info.curpos,string::npos);
      return go(info,line,offset,"EOD");
    }
    auto line=code.substr(info.curpos,eol-info.curpos+1);
    return go(info,line,offset,"...");
  }
};
#pragma once
class QapStrFinder{
public:
  struct t_cmd{
    int pos=-1;
    int next_line=-1;
    int arr_id=-1;
    int last_pos=-1;
  };
  struct t_line{
    t_cmd cmds[256];
  };
public:
  vector<vector<int>> vecs;
  vector<string> keywords;
  vector<t_line> lines;
public:
  static QapStrFinder fromArr(const vector<string>&arr)
  {
    QapStrFinder tmp;
    tmp.build(arr);
    return std::move(tmp);
  }
  void build(const vector<string>&arr)
  {
    vecs.reserve(1024*8);
    qap_add_back(lines);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      add_keyword(ex);
    }
  }
  void add_keyword(const string&keyword)
  {
    auto id=keywords.size();
    keywords.push_back(keyword);
    int state=0; int last_pos=-1;
    for(int i=0;i<keyword.size();i++)
    {
      state=add(state,id,i,last_pos);
    }
  }
  int add(int line_id,int keyword_id,int pos,int&last_pos)
  {
    const auto next_pos=pos+1;
    auto&kw=keywords[keyword_id];
    const auto c=kw[pos];
    int next_line=lines[line_id].cmds[c].next_line;
    bool eow=(next_pos==kw.size());
    bool need_new_line=(next_line==-1)&&!eow;
    if(need_new_line)
    {
      next_line=lines.size();
      auto&back=qap_add_back(lines);
    }
    auto&ex=lines[line_id].cmds[c];
    if(ex.arr_id<0){ex.arr_id=vecs.size();qap_add_back(vecs);}
    auto&arr=vecs[ex.arr_id];
    arr.push_back(keyword_id);
    if(ex.pos==-1){ex.pos=pos;}
    QapAssert(ex.pos==pos);
    ex.next_line=next_line;
    if(eow)
    {
      QapAssert(ex.last_pos!=next_pos);
      ex.last_pos=next_pos;
      QapAssert(last_pos!=next_pos);
      last_pos=next_pos;
    }
    if(last_pos!=-1)
    {
      ex.last_pos=last_pos;
    }
    if(ex.last_pos!=-1)last_pos=ex.last_pos;
    return ex.next_line;
  }
};
class QapStrFinderFast{
public:
  struct t_cmd{
    int next=-1;
    int end_id=-1;
    void update(int next,bool eow,int kw_id)
    {
      auto&cmd=*this;
      QapAssert(cmd.next==-1||next==cmd.next);
      cmd.next=next;
      if(!eow)return;
      write_eow(kw_id);
    }
    void write_eow(int kw_id)
    {
      if(kw_id==end_id)return;
      QapAssert(-1==end_id);
      end_id=kw_id;
    }
  };
  struct t_node{
    t_cmd cmds[256];
    int read_cmd_next(uchar c)const
    {
      return cmds[c].next;
    }
    int go_next(uchar c,int&end_id)const
    {
      auto&cmd=cmds[c];
      end_id=cmd.end_id;
      return cmd.next;
    }
    t_cmd&read_cmd(uchar c){
      return cmds[c];
    }
  };
  struct t_item{
    uchar c=0;
    t_cmd cmd;
    int read_cmd_next(uchar c)const
    {
      if(this->c!=c)return -1;
      return cmd.next;
    }
    int go_next(uchar c,int&end_id)const
    {
      if(this->c!=c)return -1;
      end_id=cmd.end_id;
      return cmd.next;
    }
    t_cmd&read_cmd(uchar c){
      QapAssert(this->c==c);
      return cmd;
    }
  };
  struct t_lazy{
    int kw_id=-1;
    int pos=-1;
  };
  struct t_proxy{
    char type='E';
    int id=-1;
    void set_node(int id)
    {
      this->id=id;
      this->type='N';
    }
    void set_item(int id)
    {
      this->id=id;
      this->type='I';
    }
    void set_lazy(int id)
    {
      this->id=id;
      this->type='L';
    }
  };
  struct t_find_result{
    bool ok;
    int kw_id;
    friend bool operator==(const t_find_result&a,const t_find_result&b)
    {
      if(a.ok!=b.ok)return false;
      if(a.kw_id!=b.kw_id)return false;
      return true;
    }
  };
public:
  vector<string> keywords;
  vector<t_proxy> proxies;
  vector<t_node> nodes;
  vector<t_item> items;
  vector<t_lazy> lazys;
  vector<int> free_items;
  vector<int> free_lazys;
public:
  static QapStrFinderFast fromArr(const vector<string>&arr)
  {
    QapStrFinderFast tmp;
    tmp.build(arr);
    return std::move(tmp);
  }
  void rebuild()
  {
    proxies.clear();
    nodes.clear();
    items.clear();
    lazys.clear();
    free_items.clear();
    free_lazys.clear();
    proxies.reserve(keywords.size()*3);
    nodes.reserve(keywords.size()/8);
    qap_add_back(nodes);
    qap_add_back(proxies).set_node(0);
    for(int i=0;i<keywords.size();i++)
    {
      auto&ex=keywords[i];
      add_loop(0,0,i);
    }
    int gg=1;
  }
  void build(const vector<string>&arr)
  {
    keywords=arr;
    rebuild();
  }
  int add(int ptr,uchar c,int keyword_id,int pos,bool eow,bool&need_break)
  {
    if(proxies[ptr].type=='L')
    {
      if(lazys[proxies[ptr].id].kw_id==keyword_id)
      {
        need_break=true;
        return -1;
      }
      unpack(ptr,keyword_id);
      QapAssert(proxies[ptr].type!='L');
    }
    int next=read_next(ptr,c);
    if(-1!=next)
    {
      if(!eow){return next;}
      QapAssert(eow);
      unsafe_read_cmd(ptr,c).write_eow(keyword_id);
      return next;
    }
    bool need_new_line=(next==-1)&&!eow;
    if(need_new_line)
    {
      next=new_proxy();
    }
    write_next(ptr,c,next,eow,keyword_id,pos,need_break);
    return read_next(ptr,c);
  }
  void add_loop(int ptr,int pos,int kid)
  {
    int state=ptr;
    auto&kw=keywords[kid];
    bool nb=false;
    for(int i=pos;i<kw.size();i++)
    {
      uchar c=kw[i];
      auto eow=kw.size()==i+1;
      state=add(state,c,kid,i,eow,nb);
      if(nb)break;
    }
  }
  void unpack(int ptr,int kb)
  {
    QapAssert(proxies[ptr].type=='L');
    qap_add_back(free_lazys)=proxies[ptr].id;
    auto pos=lazys[proxies[ptr].id].pos;
    auto ka=lazys[proxies[ptr].id].kw_id;
    proxies[ptr].set_item(new_item());
    items[proxies[ptr].id].c=keywords[ka][pos];
    items[proxies[ptr].id].cmd.update(new_proxy(),pos+1==keywords[ka].size(),ka);
    add_loop(ptr,pos,ka);
    add_loop(ptr,pos,kb);
  }
  void write_next(int ptr,uchar c,int next,bool eow,int kw_id,int pos,bool&need_break)
  {
    QapAssert(proxies[ptr].type!='L');
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    if(t=='E')
    {
      QapAssert(-1==id);
      if(eow)
      {
        p.set_item(new_item());
        auto&item=items[id];
        item.c=c;
        item.cmd.update(next,eow,kw_id);
        return;
      }
      p.set_lazy(new_lazy());
      auto&lazy=lazys[id];
      lazy.pos=pos;
      lazy.kw_id=kw_id;
      need_break=true;
      return;
    }
    if(t=='N')
    {
      auto&node=nodes[id];
      auto&cmd=node.cmds[c];
      cmd.update(next,eow,kw_id);
      return;
    }
    if(t=='I')
    {
      auto&item=items[id];
      if(item.c==c)
      {
        auto&cmd=item.cmd;
        cmd.update(next,eow,kw_id);
        return;
      }
      if(item.c!=c)
      {
        qap_add_back(free_items)=id;
        auto nid=new_node();
        nodes[nid].cmds[item.c]=item.cmd;
        p.set_node(nid);
        nodes[nid].cmds[c].update(next,eow,kw_id);
        item=t_item();
      }
      return;
    }
    QapDebugMsg("no way");
    return;
  }
  t_cmd&unsafe_read_cmd(int ptr,uchar c)
  {
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    if(t=='N')return nodes[id].read_cmd(c);
    if(t=='I')return items[id].read_cmd(c);
    QapDebugMsg("no way");
    return *(t_cmd*)nullptr;
  }
  int read_next(int ptr,uchar c)const
  {
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    if(t=='E')return -1;
    if(t=='N')return nodes[id].read_cmd_next(c);
    if(t=='I')return items[id].read_cmd_next(c);
    if(t=='L')return -1;
    QapDebugMsg("no way");
    return -1;
  }
  int go_next_for_find(int ptr,uchar c,const string&mem,int&state,int&pos,int&next_pos,int&end_id)const
  {
    end_id=-1;
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    QapAssert(t!='E');
    if(t=='N')return nodes[id].go_next(c,end_id);
    if(t=='I')return items[id].go_next(c,end_id);
    if(t=='L')
    {
      int gg=1;
      auto&L=lazys[id];
      QapAssert(L.pos==pos);
      auto&kw=keywords[L.kw_id];
      if(kw==mem){pos=kw.size()-1;end_id=L.kw_id;return -1;}
      return -1;
    }
    QapDebugMsg("no way");
    return -1;
  }
  int new_proxy()
  {
    int id=proxies.size();
    proxies.emplace_back();
    return id;
  }
  int new_node()
  {
    int id=nodes.size();
    nodes.emplace_back();
    return id;
  }
  int new_item()
  {
    if(!free_items.empty()){int id=free_items.back();free_items.pop_back();return id;};
    int id=items.size();
    items.emplace_back();
    return id;
  }
  int new_lazy()
  {
    if(!free_lazys.empty()){int id=free_lazys.back();free_lazys.pop_back();return id;};
    int id=lazys.size();
    lazys.emplace_back();
    return id;
  }
  t_find_result find_impl(const string&mem,int&state,int&pos,int&next_pos,int&end_id)
  {
    t_find_result fail={false,-1};
    auto n=mem.size();
    if(pos>=n)return fail;
    for(;pos<n;pos=next_pos)
    {
      next_pos=pos+1;
      const uchar c=mem[pos];
      state=go_next_for_find(state,c,mem,state,pos,next_pos,end_id);
      if(state!=-1)continue;
      if(end_id==-1)return fail;
      auto len=1+pos;
      if(n!=len)return fail;
      return {true,end_id};
    }
    QapAssert(state>=0);
    if(end_id==-1)return fail;
    return {true,end_id};
  }
  t_find_result find(const string&mem)
  {
    int pos=0;
    int state=0;
    int next_pos=1;
    int end_id=-1;
    return find_impl(mem,state,pos,next_pos,end_id);
  }
};
struct t_fallback;
class i_dev{
public:
  virtual IEnvRTTI&getEnv(){QapDebugMsg("no way.");return *(IEnvRTTI*)nullptr;}
public:
  virtual void push(t_fallback*ptr){QapDebugMsg("no way.");}
  virtual void pop(t_fallback*ptr){QapDebugMsg("no way.");}
  virtual void setPos(int pos){QapDebugMsg("no way.");}
  virtual void getPos(int&pos){QapDebugMsg("no way.");}
public:
  virtual bool isSave(){QapDebugMsg("no way.");return false;}
  virtual bool isLoad(){QapDebugMsg("no way.");return false;}
public:
  virtual bool go_any(string&body,const string&any){QapDebugMsg("no way.");return false;}
  virtual bool go_any(string&body,const CharMask&any){QapDebugMsg("no way.");return false;}
  virtual bool go_const_raw(const char*const ptr,size_t size){QapDebugMsg("no way.");return false;}
  virtual bool go_const(const string&str){QapDebugMsg("no way.");return false;}
  virtual bool go_end(string&body,const string&end){QapDebugMsg("no way.");return false;}
  virtual bool go_any_char(char&c,const string&any){QapDebugMsg("no way.");return false;}
  virtual bool go_any_char(char&c,const CharMask&any){QapDebugMsg("no way.");return false;}
  virtual bool go_any_str_from_vec(string&ref,const vector<string>&arr){QapDebugMsg("no way.");return false;}
  virtual bool go_any_str_from_vec(string&ref,const QapStrFinder&arr){QapDebugMsg("no way.");return false;}
public:
  virtual bool go_blob(string&body,size_t count){QapDebugMsg("no way.");return false;}
public:
  template<size_t SIZE>
  bool go_any_arr_char(array<char,SIZE>&body,const string&any){
    bool ok=false;
    for(size_t i=0;i<body.size();i++){
      ok=go_any_char(body[i],any);
      if(!ok)break;
    }
    return ok;
  }
public:
  template<class TYPE,size_t SIZE>
  bool go_auto(std::array<TYPE,SIZE>&arr){
    bool ok=false;
    for(size_t i=0;i<arr.size();i++){
      ok=go_auto(arr[i]);
      if(!ok)break;
    }
    return ok;
  }
public:
  template<size_t SIZE>
  bool go_const(const char(&ptr)[SIZE]){
    static const auto one=lenof("");
    return go_const_raw(&ptr[0],SIZE-one);
  }
  bool go_const(const char&ref){
    return go_const_raw(&ref,sizeof(ref));
  }
public:
  template<class TYPE>
  bool go_auto(TYPE&ref){
    return go_for_item(*this,ref);
  }
public:
  template<class TYPE>
  bool go_str_without(string&ref)
  {
    t_fallback scope(*this,__FUNCTION__);
    auto&ok=scope.ok;
    if(isLoad())
    {
      int ok_count=0;
      {
        t_fallback loadscope(*this,__FUNCTION__"::load");
        for(int i=0;
        i++)
        {
          {
            t_fallback tmp(*this,__FUNCTION__"::load::for::temp");
            TYPE temp;
            tmp.ok=go_for_item(*this,temp);
            if(tmp.ok){
              tmp.ok=false;
              tmp.pos=scope.pos+i;
              break;
            }
          }
          int next_pos;{getPos(next_pos);next_pos++;}
          {
            t_fallback tmp(*this,__FUNCTION__"::load::for::one");
            string one;
            tmp.ok=go_blob(one,1);
            if(!tmp.ok){
              tmp.pos=scope.pos+i;
              break;
            }
          }
          ok_count++;
          int cur_pos;getPos(cur_pos);
          QapAssert(next_pos==cur_pos);
        }
        loadscope.ok=false;
        loadscope.log_clear();
      }
      scope.log_clear();
      ok=ok_count;
      if(!ok)return ok;
      ok=go_blob(ref,ok_count);
      if(!ok)return ok;
      return ok;
    }
    if(isSave())
    {
      auto&Env=getEnv();
      QapAssert(!ref.empty());
      {
        t_fallback tmp(*this,__FUNCTION__"::save");
        string tmp_mem=ref;
        t_load_dev dev(Env,tmp_mem);
        for(int i=0;i<ref.size();i++)
        {
          dev.pos=i;
          TYPE tmp;
          bool ok=dev.go_auto(tmp);
          QapAssert(!ok);
          if(ok){
            (*(int*)nullptr)=0;
            return false;
          }
        }
      }
      scope.log_clear();
      ok=go_blob(ref,ref.size());
      return ok;
    }
    return ok;
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_diff(TYPE&ref)
  {
    TYPE_TEMP temp;
    int def_pos=0;
    getPos(def_pos);
    t_fallback scope(*this,__FUNCTION__);
    auto&ok=scope.ok;
    if(isLoad())
    {
      int tmp_pos=0;
      bool tmp_ok=false;
      {
        t_fallback tmp(*this,__FUNCTION__"::load");
        tmp.ok=go_for_item(*this,temp);
        tmp_ok=tmp.ok;
        if(tmp.ok){
          getPos(tmp_pos);
          tmp.ok=false;ok=false;
          tmp.pos=def_pos;
        }
      }
      ok=go_for_item(*this,ref);
      if(!tmp_ok||!ok)return ok;
      int ref_pos=0;
      getPos(ref_pos);
      if(ref_pos<=tmp_pos){ok=false;scope.pos=def_pos;}
      return ok;
    }
    if(isSave())
    {
      auto&Env=getEnv();
      string tmp_mem;
      {
        t_save_dev dev(Env,tmp_mem);
        bool ok=go_for_item(dev,ref);
        QapAssert(ok);
        if(!ok)return ok;
      }
      for(;
      )
      {
        TYPE obj;
        t_load_dev dev(Env,tmp_mem);
        bool tmp_ok=dev.go_auto(temp);
        int tmp_pos=dev.pos;
        dev.pos=0;
        bool obj_ok=dev.go_auto(obj);
        int obj_pos=dev.pos;
        QapAssert(obj_ok);
        if(!tmp_ok)break;
        QapAssert(obj_pos>tmp_pos);
        break;
      }
    }
    ok=go_for_item(*this,ref);
    return ok;
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_minor(TYPE&ref){
    return old_go_sep<TYPE_TEMP>(ref);
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool old_go_sep(TYPE&ref)
  {
    TYPE_TEMP temp;
    t_fallback scope(*this,__FUNCTION__);
    auto&ok=scope.ok;
    if(isLoad())
    {
      {
        t_fallback tmp(*this,__FUNCTION__"::load");
        tmp.ok=go_for_item(*this,temp);
        if(tmp.ok){
          tmp.ok=false;ok=false;
          tmp.pos=scope.pos;
        }
      }
      if(!ok)return ok;
    }
    if(isSave())
    {
      auto&Env=getEnv();
      string tmp_mem;
      {
        t_save_dev dev(Env,tmp_mem);
        bool ok=go_for_item(dev,ref);
        QapAssert(ok);
      }
      {
        t_load_dev dev(Env,tmp_mem);
        bool ok=dev.go_auto(temp);
        QapAssert(!ok);
        TYPE obj;
        ok=dev.go_auto(obj);
        QapAssert(ok);
      }
    }
    ok=go_for_item(*this,ref);
    return ok;
  }
public:
  template<class TYPE>
  bool go_str(string&ref)
  {
    auto&Env=getEnv();
    if(isSave())
    {
      bool ok=false;
      {
        TYPE value;
        t_load_dev dev(Env,ref);
        ok=dev.go_auto(value);
        int pos=0;dev.getPos(pos);
        bool err=ref.size()!=pos;
        ok=!err;
        if(err)
        {
          string msg="problem detected:\n";
          msg+="  ref.size : "+IToS(ref.size())+"\n";
          msg+="  pos      : "+IToS(pos)+"\n";
          msg+=t_error_tool::get_codefrag(ref,pos);
          QapDebugMsg(msg);
        }
      }
      if(ok)
      {
        return go_blob(ref,ref.size());
      }
      return ok;
    }
    if(isLoad())
    {
      TYPE value;
      int pos=0;getPos(pos);
      bool ok=go_auto(value);
      if(!ok)return ok;
      int curpos=0;getPos(curpos);
      QapAssert(curpos>pos);
      setPos(pos);
      auto count=curpos-pos;
      ok=go_blob(ref,count);
      QapAssert(ok);
      return ok;
    }
    QapDebugMsg("no way");
    return false;
  }
public:
  template<class TYPE>
  bool go_vec(vector<TYPE>&arr,const string&sep)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    if(isLoad())
    {
      for(int i=0;
      i++)
      {
        t_fallback subscope(*this,__FUNCTION__);
        bool&ok=subscope.ok;
        if(i)
        {
          ok=go_const(sep);
          if(!ok)break;
        }
        TYPE tmp;
        ok=go_auto(tmp);
        if(!ok)break;
        QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
        arr.push_back(std::move(tmp));
      }
      ok=!arr.empty();
      return ok;
    }
    if(isSave())
    {
      for(int i=0;i<arr.size();i++)
      {
        if(i)
        {
          t_fallback subscope(*this,__FUNCTION__);
          subscope.ok=go_const(sep);
          if(!subscope.ok)break;
        }
        t_fallback subscope(*this,__FUNCTION__);
        bool&ok=subscope.ok;
        auto&ex=arr[i];
        QapAssert(CheckTAutoPtrIsNotEmpty(ex));
        ok=go_auto(ex);
        if(!ok)break;
      }
      return ok;
    }
    return ok;
  }
public:
  template<class TYPE>
  bool go_bin_oper(vector<TYPE>&arr,const string&oper)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    ok=go_vec(arr,oper);
    if(!ok)return ok;
    if(ok)ok=arr.size()>=2;
    return ok;
  }
};
struct t_scope_tool{
  bool ok=true;
  void operator+=(bool value){
    ok=value;
  }
};
static int&get_qap_fallback_counter(){static int counter=0;return counter;}
struct t_fallback{
  i_dev&dev;
  bool&ok;
  size_t pos;
  t_scope_tool mandatory;
  t_scope_tool optional;
  t_fallback(i_dev&dev,const char*const ptr):dev(dev),ok(mandatory.ok),pos(-1){
    dev.push(this);
  }
 ~t_fallback(){
    dev.pop(this);
    get_qap_fallback_counter()++;
  }
};
class t_load_dev:public i_dev{
public:
  IEnvRTTI&Env;
  const string&mem;
  size_t pos;
  size_t maxpos;
public:
  t_load_dev(IEnvRTTI&Env,const string&mem,size_t pos=0):Env(Env),mem(mem),pos(pos),maxpos(pos){}
public:
  void push(t_fallback*ptr){
    ptr->pos=pos;
    maxpos=std::max(maxpos,pos);
  }
  void pop(t_fallback*ptr){
    if(ptr->ok)return;
    if(pos==ptr->pos)return;
    pos=ptr->pos;
  }
  void setPos(int pos){this->pos=pos;}
  void getPos(int&pos){pos=this->pos;}
public:
  IEnvRTTI&getEnv(){return Env;}
public:
  bool isSave(){return false;}
  bool isLoad(){return true;}
public:
  bool go_any(string&body,const string&any){
    for(auto i=pos;i<mem.size();i++){
      auto e=any.find(CToS(mem[i]));
      if(e!=string::npos)continue;
      body=mem.substr(pos,i-pos);
      pos=i;
      return !body.empty();
    }
    body=mem.substr(pos);
    pos+=body.size();
    return !body.empty();
  }
  bool go_any(string&body,const CharMask&any){
    auto n=mem.size();
    if(pos>=n)return false;
    const auto*p=&mem[pos];
    auto e=p+n;
    auto&mask=any.mask;
    for(;p<e;p++)
    {
      if(mask[uchar(*p)])continue;
      auto body_size=p-&mem[pos];
      body=mem.substr(pos,body_size);
      pos+=body_size;
      return body_size;
    }
    body=mem.substr(pos);
    pos+=body.size();
    return !body.empty();
  }
  bool go_const_raw(const char*const ptr,size_t size){
    auto end=pos+size;
    if(end>mem.size())return false;
    for(int i=0;i<size;i++){
      if(mem[pos+i]==ptr[i])continue;
      return false;
    }
    pos+=size;
    return true;
  }
  bool go_const(const string&body){
    auto size=body.size();
    auto end=pos+size;
    if(end>mem.size())return false;
    for(int i=0;i<size;i++){
      if(mem[pos+i]==body[i])continue;
      return false;
    }
    pos+=body.size();
    return true;
  }
  bool go_end(string&body,const string&aft){
    auto e=mem.find(aft,pos);
    if(e==string::npos)return false;
    body=mem.substr(pos,e-pos);
    pos=e;
    bool ok=go_const(aft);
    QapAssert(ok);
    return ok;
  }
  bool go_any_char(char&body,const string&any){
    if(mem.empty())return false;
    if(pos>=mem.size())return false;
    auto e=any.find(CToS(mem[pos]));
    if(e==string::npos)return false;
    body=mem[pos];
    pos++;
    return true;
  }
  bool go_any_char(char&body,const CharMask&any){
    if(mem.empty())return false;
    if(pos>=mem.size())return false;
    auto ok=any[mem[pos]];
    if(!ok)return false;
    body=mem[pos];
    pos++;
    return true;
  }
public:
  bool go_blob(string&body,size_t count){
    bool ok=count<=mem.size()-pos;
    if(!ok)return ok;
    body=mem.substr(pos,count);
    pos+=count;
    return true;
  }
public:
  class t_keywords{
  public:
    struct t_func{
      const t_keywords&keywords;
      bool ok=false;
      bool next=false;
      bool fail=false;
      size_t pos=0;
      size_t ok_pos=0;
      size_t ok_way_id=-1;
      vector<int> items;
      t_func(const t_keywords&keywords):keywords(keywords)
      {
        auto&arr=keywords.arr;
        int n=arr.size();items.resize(n);
        for(int i=0;i<n;i++)
        {
          items[i]=i;
        }
      }
      void operator()(char c)
      {
        auto&arr=keywords.arr;
        bool need_clean=false;
        int cur_pos=pos; pos++;
        for(size_t i=0;i<items.size();i++)
        {
          auto&id=items[i];
          auto&ex=arr[id];
          if(c!=ex[cur_pos])
          {
            id=-1;
            need_clean=true;
            continue;
          }
        }
        if(need_clean)
        {
          QapCleanIf(items,[](int id){return id<0;});
          need_clean=false;
        }
        if(items.empty())
        {
          fail=true;
          return;
        }
        if(items.size()==1)
        {
          next=pos<arr[items[0]].size();
          ok=ok||!next;
          return;
        }
        next=true;
        for(int i=0;i<items.size();i++)
        {
          auto&id=items[i];
          if(pos!=arr[id].size())continue;
          ok=true;
          QapAssert(ok_pos!=pos);
          ok_pos=pos;
          ok_way_id=id;
          id=-1;
          need_clean=true;
        }
        if(need_clean)
        {
          QapCleanIf(items,[](int id){return id<0;});
          QapAssert(!items.empty());
          QapAssert(ok);
        }
        int gg=1;
      }
      bool exec(const string&ref)
      {
        auto&func=*this;
        for(int i=0;i<ref.size();i++)
        {
          func(ref[i]);
          if(fail){return false;}
          if(func.next)continue;
          QapAssert(ok);
          return true;
        }
        return ok;
      }
    };
  public:
    const vector<string>&arr;
  };
  bool go_any_str_from_vec(string&ref,const vector<string>&arr)
  {
    return go_any_str_from_vec_old_and_slow(ref,arr);
    QapAssert(!arr.empty());
    t_keywords keywords={arr};
    auto&body=ref;
    auto n=mem.size();
    if(pos>=n)return false;
    const auto*p=&mem[pos];
    auto e=p+n;
    t_keywords::t_func func(keywords);
    for(;p<e;p++)
    {
      func(*p);
      if(func.fail)
      {
        if(!func.ok)return false;
        body=mem.substr(pos,func.ok_pos);
        pos+=body.size();
        return true;
      }
      if(func.next)continue;
      QapAssert(func.ok);
      p++;
      auto body_size=p-&mem[pos];
      body=mem.substr(pos,body_size);
      pos+=body_size;
      return true;
    }
    if(!func.ok)return false;
    body=mem.substr(pos);
    pos+=body.size();
    return !body.empty();
  }
public:
  bool go_any_str_from_vec(string&ref,const QapStrFinder&arr)
  {
    auto&body=ref; auto&tool=arr; auto&lines=tool.lines;
    auto n=mem.size();
    if(pos>=n)return false;
    const auto*p=&mem[pos];
    auto e=p+n;
    int state=0;
    int last_pos=-1;
    for(;p<e;p++)
    {
      auto c=*p;
      auto&ex=lines[state].cmds[c];
      state=ex.next_line;
      if(ex.last_pos!=-1)last_pos=ex.last_pos;
      if(state!=-1)continue;
      if(last_pos==-1)return false;
      body=mem.substr(pos,last_pos);
      pos+=body.size();
      return true;
    }
    QapAssert(state>=0);
    if(last_pos==-1)return false;
    body=mem.substr(pos,last_pos);
    pos+=body.size();
    return !body.empty();
  }
public:
  bool go_any_str_from_vec_old_and_slow(string&ref,const vector<string>&arr)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    QapAssert(!arr.empty());
    vector<int> out;out.resize(arr.size());
    int count=0;
    int id=-1;int winpos=-1;
    int def_pos=0;
    getPos(def_pos);
    for(int i=0;i<arr.size();i++)
    {
      t_fallback scope(*this,__FUNCTION__"::loop");
      auto&ex=arr[i];
      QapAssert(!ex.empty());
      scope.ok=this->go_const(ex);
      int dev_pos=0;
      getPos(dev_pos);
      out[i]=dev_pos;
      if(scope.ok)
      {
        id=i;
        count++;
        winpos=dev_pos;
      }
      scope.ok=false;
    }
    ok=count;
    if(!ok)return ok;
    if(count>1)
    {
      int best=0;
      for(int i=1;i<out.size();i++)
      {
        if(out[i]==def_pos)continue;
        bool error_detected=out[i]==out[best];
        if(error_detected)
        {
          CppString cpp=arr[i];
          string msg="error detected:\n";
          msg+="arr["+IToS(i)+"] == arr["+IToS(best)+"]\n";
          msg+="value = \""+cpp.data+"\"";
          QapDebugMsg(msg)
        }
        if(out[i]>out[best])best=i;
      }
      QapAssert(def_pos!=out[best]);
      ref=arr[best];
      ok=go_const(ref);
      return ok;
    }
    ref=arr[id];
    ok=go_const(ref);
    return ok;
  }
};
class t_save_dev:public i_dev{
public:
  IEnvRTTI&Env;
  string&mem;
public:
  t_save_dev(IEnvRTTI&Env,string&mem):Env(Env),mem(mem){}
public:
  void push(t_fallback*ptr){
    ptr->pos=mem.size();
  }
  void pop(t_fallback*ptr){
    if(ptr->ok)return;
    mem.resize(ptr->pos);
  }
public:
  void setPos(int pos){QapNoWay();this->mem.resize(pos);}
  void getPos(int&pos){pos=this->mem.size();}
public:
  IEnvRTTI&getEnv(){return Env;}
public:
  bool isSave(){return true;}
  bool isLoad(){return false;}
public:
  bool go_any(string&body,const string&any){
    if(body.empty())return false;
    string tmp=body;
    for(int i=0;i<any.size();i++)tmp=join(split(tmp,CToS(any[i])),"");
    bool ok=tmp.empty();
    QapAssert(ok);
    mem+=body;
    return ok;
  }
  bool go_any(string&body,const CharMask&any)
  {
    if(body.empty())return false;
    bool ok=any.check(body);
    QapAssert(ok);
    mem+=body;
    return ok;
  }
  bool go_const_raw(const char*const ptr,size_t size){
    mem+=string(ptr,size);
    return true;
  }
  bool go_const(const string&body){
    mem+=body;
    return true;
  }
  bool go_end(string&body,const string&aft){
    auto e=body.find(aft);
    bool ok=e==string::npos;
    QapAssert(ok);
    if(!ok)return false;
    mem+=body;
    ok=go_const(aft);
    QapAssert(ok);
    return ok;
  }
  bool go_any_char(char&body,const string&any){
    auto ok=any.find(body)!=string::npos;
    QapAssert(ok)
    mem.push_back(body);
    return ok;
  }
  bool go_any_char(char&body,const CharMask&any){
    auto ok=any[body];
    QapAssert(ok)
    mem.push_back(body);
    return ok;
  }
public:
  bool go_blob(string&body,size_t count){
    bool ok=count==body.size();
    QapAssert(ok);
    if(!ok)return ok;
    mem+=body;
    return true;
  }
public:
  bool go_any_str_from_vec(string&ref,const vector<string>&arr)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    QapAssert(!arr.empty());
    int id=-1;
    int count=0;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(!ex.empty());
      if(ex==ref){count++;id=i;}
    }
    QapAssert(count<=1);
    ok=count;
    if(!ok)return ok;
    ok=go_const(arr[id]);
    QapAssert(ok);
    return ok;
  }
  bool go_any_str_from_vec(string&ref,const QapStrFinder&arr)
  {
    return go_any_str_from_vec(ref,arr.keywords);
  }
};
template<class TYPE,class BASE>
static bool go_for_class(i_dev&dev,TAutoPtr<BASE>&out){
  TYPE tmp;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  ok=tmp.go(dev);
  if(!ok)return ok;
  auto*p=out.build<TYPE>(dev.getEnv());
  *p=std::move(tmp);
  return ok;
}
/*
template<class TYPE> static void try_do_weak_go_for_poly(i_dev&dev,void*){}
template<class TYPE>
static void try_do_weak_go_for_poly(i_dev&dev,TYPE*Self,void(*pFunc)(i_dev&,TYPE*)=&TYPE::weak_go_for_poly_lt<i_dev>)
{
  (*pFunc)(dev,Self);
}*/
template<class TYPE>
static bool go_for_poly(i_dev&dev,TAutoPtr<TYPE>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=TYPE::t_poly_impl::go_lt(dev,ref);
  }
  if(dev.isSave()){
    ok=TYPE::t_poly_impl::go_st(dev,ref);
  }
  return ok;
}
template<class TYPE>
static bool go_for_item(i_dev&dev,const TYPE&ref,...){
  static_assert(false,"d:\\temp\\uidev_fct\\sgon\\QapLexer.inl"":"__FUNCTION__" => so bad :(");
  QapDebugMsg(Sys$$<TYPE>::GetRTTI(dev.getEnv())->GetFullName()+" => no way!");
  return false;
}
template<class T,T v>struct detail_test_value{static const bool value=true;};
template<class TYPE>struct detail_has_poly_impl{
  __if_exists(TYPE::t_poly_impl)
  {
    static const bool value = true;
  }
  __if_not_exists(TYPE::t_poly_impl)
  {
    static const bool value = false;
  }
};
template<
  class TYPE,
  bool flag=detail_has_poly_impl<TYPE>::value
>struct detail_go_lt_param_is_not_the_same_as_TYPE{
  static const bool value=!std::is_same<typename get_go_lt_param_type<TYPE>::type,TYPE>::value;
};
template<class TYPE>struct detail_go_lt_param_is_not_the_same_as_TYPE<TYPE,false>{static const bool value=false;};
template<class TYPE>struct get_go_lt_param_type{
  template<class U>
  static U func(bool(*)(i_dev&,TAutoPtr<U>&));
  typedef decltype(func(&TYPE::t_poly_impl::go_lt)) type;
};
template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<
    !std::is_polymorphic<TYPE>::value||detail_go_lt_param_is_not_the_same_as_TYPE<TYPE>::value
    ,
    void*
  >::type=nullptr
){
  TYPE tmp;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isSave()){
    if(!ref){
      ok=false;
      return ok;
    }
    auto*p=ref.get();
    ok=p->go(dev);
    return ok;
  }
  ok=tmp.go(dev);
  if(!ok)return ok;
  auto*p=ref.build<TYPE>(dev.getEnv());
  *p=std::move(tmp);
  return ok;
}
template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<detail_test_value<bool(*)(i_dev&,TAutoPtr<TYPE>&),&TYPE::t_poly_impl::go_lt>::value,void*>::type=nullptr,
  bool(*pFunc)(i_dev&,TAutoPtr<TYPE>&)=&TYPE::t_poly_impl::go_lt,
  typename std::enable_if<std::is_polymorphic<TYPE>::value,void*>::type=nullptr
){
  return go_for_poly(dev,ref);
}
namespace detail{
  template<class TYPE>struct isTAutoPtr{static const bool value=false;};
  template<class TYPE>struct isTAutoPtr<TAutoPtr<TYPE>>{static const bool value=true;};
};
template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TYPE&ref,
  bool(TYPE::*pFunc)(i_dev&)=&TYPE::go,
  typename std::enable_if<!detail::isTAutoPtr<TYPE>::value,void*>::type=nullptr
){
  return (ref.*pFunc)(dev);
}
template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TYPE&ref){return true;}
template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TAutoPtr<TYPE>&ref){return ref;}
template<class TYPE>
static bool internal_go_for_vec_lt(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for(int i=0;
  i++){
    t_fallback subscope(dev,__FUNCTION__);
    bool&ok=subscope.ok;
    TYPE tmp;
    ok=go_for_item(dev,tmp);
    if(!ok)break;
    QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
    arr.push_back(std::move(tmp));
  }
  ok=!arr.empty();
  return ok;
}
template<class TYPE>
static bool internal_go_for_vec_st(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    ok=go_for_item(dev,ex);
    if(!ok)break;
  }
  return ok;
}
template<class TYPE>
static bool go_for_arr_lt(i_dev&dev,vector<TYPE>&arr){
  return internal_go_for_vec_lt(dev,arr);
}
template<class TYPE>
static bool go_for_arr_st(i_dev&dev,vector<TYPE>&arr){
  return internal_go_for_vec_st(dev,arr);
}
template<class TYPE>
static bool go_for_item(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=go_for_arr_lt(dev,arr);
  }
  if(dev.isSave()){
    ok=go_for_arr_st(dev,arr);
  }
  return ok;
}
static string two_text_diff(const string&out,const string&data)
{
  auto maxval=std::max(out.size(),data.size());
  auto minval=std::min(out.size(),data.size());
  auto ds=maxval-minval;
  int pos=-1;
  for(int i=0;i<minval;i++){
    if(out[i]!=data[i]){pos=i;break;}
  }
  string msg="diff:\n  min_size="+IToS(minval)+"  diff_size="+IToS(ds)+"  pos="+IToS(pos)+"\n";
  if(pos<0){
    QapAssert(minval==out.size());
    auto out=t_error_tool::get_codefrag(data,minval);
    out="{\"offset\":"+IToS(minval)+"}\n"+out;
    msg+=out;
  }
  if(pos>=0){
    int count=10;
    CppString a_cpp=data.substr(std::max<int>(pos-count,0),count*2);
    CppString b_cpp=out.substr(std::max<int>(pos-count,0),count*2);
    msg+="  inp: \""+a_cpp.data+"\"\n";
    msg+="  out: \""+b_cpp.data+"\"\n";
  }
  QapDebugMsg(msg);
  return msg;
};
template<class TYPE>
bool load_obj(IEnvRTTI&Env,TYPE&out,const string&data,int*pmaxpos=nullptr)
{
  TYPE tmp;
  t_load_dev dev(Env,data);
  bool ok=dev.go_auto(tmp);
  if(ok)
  {
    string out;
    t_save_dev dev(Env,out);
    bool ret=dev.go_auto(tmp);
    QapAssert(ok==ret);
    if(ok&&ret)if(out!=data)
    {
      QapDebugMsg(two_text_diff(out,data));
    }
  }
  if(!ok&&pmaxpos){
    *pmaxpos=Clamp<int>(dev.maxpos+1,1,data.size())-1;
  }
  out=std::move(tmp);
  return ok;
}
template<class TYPE>
string load_obj_ex(IEnvRTTI&Env,TYPE&obj,const string&data){
  int pos=0;
  bool ok=load_obj(Env,obj,data,&pos);
  string main="{\"ok\":"+BToS(ok)+",\"date\":\""+cur_date_str()+"\"}";
  if(ok)return main;
  auto out=t_error_tool::get_codefrag(data,pos);
  out="{\"offset\":"+IToS(pos)+"}\n"+out;
  return main+"@@@"+out;
}
struct t_load_obj_result{
  bool ok;
  int pos;
  string msg;
};
template<class TYPE>
t_load_obj_result load_obj_full(IEnvRTTI&Env,TYPE&obj,const string&data){
  t_load_obj_result out;
  out.pos=0;
  out.ok=load_obj(Env,obj,data,&out.pos);
  out.msg="{\"ok\":"+BToS(out.ok)+",\"date\":\""+cur_date_str()+"\"}";
  if(out.ok)return out;
  auto buff=t_error_tool::get_codefrag(data,out.pos);
  buff="{\"offset\":"+IToS(out.pos)+"}\n"+buff;
  out.msg+="@@@"+buff;
  return out;
}
template<class TYPE>
bool save_obj(IEnvRTTI&Env,TYPE&inp,string&data)
{
  string mem;
  t_save_dev dev(Env,mem);
  bool ok=dev.go_auto(inp);
  QapAssert(ok);
  if(ok)for(;
  )
  {
    TYPE tmp;
    t_load_dev tmp_dev(Env,mem);
    bool ok=tmp_dev.go_auto(tmp);
    QapAssert(ok||mem.empty());
    {
      bool result=TIsSameVisitor::Exec(Env,inp,tmp);
      if(result)break;
    }
    string bin_bef;
    string bin_aft;
    QapPublicUberFullSaverBinMem(Env,QapRawUberObject(inp),bin_bef);
    QapPublicUberFullSaverBinMem(Env,QapRawUberObject(tmp),bin_aft);
    bool err=bin_bef!=bin_aft;
    if(err)
    {
      string txt_bef=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(inp));
      string txt_aft=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(tmp));
      string msg=two_text_diff(txt_aft,txt_bef);
      QapDebugMsg("diff:\n"+msg);
      QapDebugMsg("before:\n"+txt_bef);
      QapDebugMsg("after:\n"+txt_aft);
      return false;
    }
    break;
  }
  data=std::move(mem);
  return ok;
}
class t_config_2013{
public:
  class t_item{
  public:
  public:typedef t_config_2013 OwnerClass;
  public:typedef t_item SelfClass;
  public:
   string type;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->type); 
    }
  public:
    t_item(const t_item&)=delete;t_item(){DoReset();};
  public:
    t_item(t_item&&_Right){operator=(std::move(_Right));}
    void operator=(t_item&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->type=std::move(_Right.type);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_item";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_item";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("\n");
      if(!ok)return ok;
      D+=dev.go_any(type,gen_dips("azAZ09")+"_$@:");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_info{
  public:
  public:typedef t_config_2013 OwnerClass;
  public:typedef t_info SelfClass;
  public:
   string type;
    string pos;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->pos); 
    }
  public:
    t_info(const t_info&)=delete;t_info(){DoReset();};
  public:
    t_info(t_info&&_Right){operator=(std::move(_Right));}
    void operator=(t_info&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->type=std::move(_Right.type);
    this->pos=std::move(_Right.pos);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_info";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
    Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"pos",int(&(((SelfClass*)nullptr)->*(&SelfClass::pos))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_info";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_any(type,gen_dips("azAZ09")+"_$@:");
      if(!ok)return ok;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_any(pos,gen_dips("09"));
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_event{
  public:
  public:typedef t_config_2013 OwnerClass;
  public:typedef t_event SelfClass;
  public:
   string time;
    t_info A;
    t_info B;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->time); detail::FieldTryDoReset(this->A); detail::FieldTryDoReset(this->B); 
    }
  public:
    t_event(const t_event&)=delete;t_event(){DoReset();};
  public:
    t_event(t_event&&_Right){operator=(std::move(_Right));}
    void operator=(t_event&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->time=std::move(_Right.time);
    this->A=std::move(_Right.A);
    this->B=std::move(_Right.B);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_event";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"time",int(&(((SelfClass*)nullptr)->*(&SelfClass::time))),"DEF","$");
    Info->AddMemberDEF(Sys$$<t_info>::GetRTTI(RTTI),"A",int(&(((SelfClass*)nullptr)->*(&SelfClass::A))),"DEF","$");
    Info->AddMemberDEF(Sys$$<t_info>::GetRTTI(RTTI),"B",int(&(((SelfClass*)nullptr)->*(&SelfClass::B))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_event";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("\n+[");
      if(!ok)return ok;
      D+=dev.go_any(time,gen_dips("09")+".: ");
      if(!ok)return ok;
      D+=dev.go_const("] ");
      if(!ok)return ok;
      D+=dev.go_auto(A);
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(B);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_line{
  public:
  public:typedef t_config_2013 OwnerClass;
  public:typedef t_line SelfClass;
  public:
   string head;
    vector<t_item> arr;
    vector<t_event> events;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->head); detail::FieldTryDoReset(this->arr); detail::FieldTryDoReset(this->events); 
    }
  public:
    t_line(const t_line&)=delete;t_line(){DoReset();};
  public:
    t_line(t_line&&_Right){operator=(std::move(_Right));}
    void operator=(t_line&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->head=std::move(_Right.head);
    this->arr=std::move(_Right.arr);
    this->events=std::move(_Right.events);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_line";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");
    Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
    Info->AddMemberDEF(Sys$$<vector<t_event>>::GetRTTI(RTTI),"events",int(&(((SelfClass*)nullptr)->*(&SelfClass::events))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_line";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_any(head,gen_dips("azAZ09")+"_$@:");
      if(!ok)return ok;
      M+=dev.go_const("\n====>");
      if(!ok)return ok;
      M+=dev.go_const("\n[arr]");
      if(!ok)return ok;
      M+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("\n[events]");
      if(!ok)return ok;
      O+=dev.go_auto(events);
      if(!ok)return ok;
      M+=dev.go_const("\n<====\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_doc{
  public:
  public:typedef t_config_2013 OwnerClass;
  public:typedef t_doc SelfClass;
  public:
   vector<t_line> lines;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->lines); 
    }
  public:
    t_doc(const t_doc&)=delete;t_doc(){DoReset();};
  public:
    t_doc(t_doc&&_Right){operator=(std::move(_Right));}
    void operator=(t_doc&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->lines=std::move(_Right.lines);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_doc";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_line>>::GetRTTI(RTTI),"lines",int(&(((SelfClass*)nullptr)->*(&SelfClass::lines))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_doc";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(lines);
      if(!ok)return ok;
      return ok;
    }
  };
  /*
  F(t_item)F(t_info)F(t_event)F(t_line)F(t_doc)
  adler3d.github.io/test2013/
  return decodeURIComponent(POST['data'].split("\n").join(""));
  t%5Fitem%7B%0A%20%20string%20type%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%
  5Cn%22%29%3B%0A%20%20%20%20go%5Fany%28type%2Cgen%5Fdips%28%22azAZ09%22%29%2B%22%
  5F%24%40%3A%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Finfo%7B%0A%20%20string%20type%3B
  %0A%20%20string%20pos%3B%0A%20%20%7B%0A%20%20%20%20go%5Fany%28type%2Cgen%5Fdips%
  28%22azAZ09%22%29%2B%22%5F%24%40%3A%22%29%3B%0A%20%20%20%20go%5Fconst%28%22%28%2
  2%29%3B%0A%20%20%20%20go%5Fany%28pos%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%2
  0%20go%5Fconst%28%22%29%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fevent%7B%0A%20%20str
  ing%20time%3B%0A%20%20t%5Finfo%20A%3B%0A%20%20t%5Finfo%20B%3B%0A%20%20%7B%0A%20%
  20%20%20go%5Fconst%28%22%5Cn%2B%5B%22%29%3B%0A%20%20%20%20go%5Fany%28time%2Cgen%
  5Fdips%28%2209%22%29%2B%22%2E%3A%20%22%29%3B%0A%20%20%20%20go%5Fconst%28%22%5D%2
  0%22%29%3B%0A%20%20%20%20go%5Fauto%28A%29%3B%0A%20%20%20%20go%5Fconst%28%22%20%2
  2%29%3B%0A%20%20%20%20go%5Fauto%28B%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fline%7B%0A%
  20%20string%20head%3B%0A%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20vector%3Ct%5
  Fevent%3E%20events%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fany%28head%2Cgen%5Fd
  ips%28%22azAZ09%22%29%2B%22%5F%24%40%3A%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst
  %28%22%5Cn%3D%3D%3D%3D%3E%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5Cn%5Ba
  rr%5D%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3Dg
  o%5Fconst%28%22%5Cn%5Bevents%5D%22%29%3B%0A%20%20%20%20O%3D%2Bgo%5Fauto%28events
  %29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5Cn%3C%3D%3D%3D%3D%5Cn%22%29%3B%0A%
  20%20%7D%0A%7D%0A%0At%5Fdoc%7B%0A%20%20vector%3Ct%5Fline%3E%20lines%3B%0A%20%20%
  7B%0A%20%20%20%20go%5Fauto%28lines%29%3B%0A%20%20%7D%0A%7D
  */
public:
  public:typedef t_config_2013 SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    t_config_2013(const t_config_2013&)=delete;t_config_2013(){DoReset();};
  public:
    t_config_2013(t_config_2013&&_Right){operator=(std::move(_Right));}
    void operator=(t_config_2013&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_config_2013";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_info>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_event>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_line>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_doc>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_config_2013";
      }
    };
  public:
};
struct t_poly_tool:public t_config_2013{
  t_doc doc;
  static t_poly_tool&get(IEnvRTTI&Env){
    static const string fn="config.cfg";
    static t_poly_tool tool;
    static t_doc&doc=tool.doc;
    static QapClock clock;
    static bool first=true;
    if(first){clock.Start();/*doc.lines.reserve(2048);*/}
    if(clock.MS()<360*1000)if(!first)return tool;
    first=false;
    clock.Stop();clock.Start();
    CrutchIO IO;
    bool ok=IO.LoadFile(fn);
    if(ok){t_doc tmp;doc=std::move(tmp);/*doc.lines.reserve(2048);*/}
    if(!ok){
      IO.mem.clear();
      QapAssert(save_obj(Env,doc,IO.mem));
      IO.SaveFile(fn);
      return tool;
    }
    clock.Stop();clock.Start();
    QapAssert(load_obj(Env,doc,IO.mem));clock.Stop();clock.Start();
    real time=clock.MS();
    clock.Stop();clock.Start();
    return tool;
  }
  void save_doc(IEnvRTTI&Env,const string&fn){
    CrutchIO IO;
    QapAssert(save_obj(Env,this->doc,IO.mem));
    IO.SaveFile(fn);
  }
public:
  t_line&find(const string&type){
    auto&arr=doc.lines;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.head==type)return ex;
    }
    arr.push_back(t_line());
    auto&back=arr.back();
    back.head=type;
    return back;
  }
  template<class TYPE>
  vector<t_item>&get_base_arr(IEnvRTTI&Env,const string&basetype,vector<TYPE>&inp){
    auto&base=find(basetype);
    auto&arr=base.arr;
    if(arr.size()==inp.size())return arr;
    QapAssert(base.arr.empty());
    arr.resize(inp.size());
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex.type=inp[i].info;
    }
    save_doc(Env,"config.cfg");
    return arr;
  }
  static int get_mass(const vector<t_item>&arr,const string&type){
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.type==type)return i;
    }
    QapAssert(false);
    return -1;
  }
public:
  struct t_point{
    int id;
    string name;
    vector<int> inp;
    vector<int> out;
    bool passed;
    int group;
  };
public:
  template<class TYPE>
  struct t_out_rec{
    string info;
    TAutoPtr<TYPE> object;
    int pos;
    int mass;
    t_out_rec(){pos=-1;mass=-1;}
    t_out_rec(t_out_rec&&ref){info=std::move(ref.info);object=std::move(ref.object);pos=ref.pos;mass=ref.mass;}
  };
public:
  struct t_points{
    vector<t_point> arr;
    t_point&find(const string&name){
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(name==ex.name)return ex;
      }
      QapAssert(false);
      return *(t_point*)nullptr;
    }
    void set_passed(bool value){
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        ex.passed=value;
      }
    }
    void load_points(const vector<string>&inp){
      arr.resize(inp.size());
      for(int i=0;i<inp.size();i++){
        auto&ex=inp[i];
        auto&p=arr[i];
        p.name=ex;
        p.id=i;
        p.passed=false;
        p.group=-1;
      }
    }
    void load_edges_from_events(const vector<t_event>&events){
      for(int i=0;i<events.size();i++){
        auto&ex=events[i];
        auto&pa=find(ex.A.type);
        auto&pb=find(ex.B.type);
        pa.inp.push_back(pb.id);
        pb.out.push_back(pa.id);
      }
    }
    struct t_wave{
      t_points&points;
      vector<int> prev;
      vector<int> next;
      int first_id;
      int group;
      bool result;
      void update(int id)
      {
        auto&ex=points.arr[id];
        ex.group=group;
        ex.passed=true;
        auto&arr=ex.out;
        for(int i=0;i<arr.size();i++){
          auto&id=arr[i];
          auto&ex=points.arr[id];
          QapAssert(id!=first_id);
          if(first_id==id)result=true;
          next.push_back(ex.id);
        }
      }
      void run()
      {
        points.set_passed(false);
        next.push_back(first_id);
        for(int iter=0;!next.empty();iter++)
        {
          prev=std::move(next);
          for(int i=0;i<prev.size();i++){
            auto&id=prev[i];
            auto&ex=points.arr[id];
            if(ex.passed)continue;
            update(ex.id);
          }
        }
      }
    };
    bool isCyclical(){
      t_wave wave={*this};
      wave.result=false;
      string view;view.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        for(int i=0;i<arr.size();i++){view[i]=arr[i].group<0?'N':'0'+arr[i].group;}
        if(ex.group>=0)continue;
        wave.first_id=ex.id;
        wave.group=ex.id;
        wave.run();
      }
      return wave.result;
    }
    vector<string> toList(){
      vector<string> out;
      set_passed(false);
      vector<int> heads;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(!ex.out.empty())continue;
        heads.push_back(ex.id);
      }
      vector<int> next;
      for(int iter=0;!heads.empty();iter++)
      {
        vector<int> next_heads;
        for(int i=0;i<heads.size();i++){
          auto&id=heads[i];
          auto&ex=arr[id];
          auto&inp=ex.inp;
          for(int i=0;i<inp.size();i++){
            auto&id=inp[i];
            auto&ex=arr[id];
            if(ex.passed)continue;
            bool found=false;
            for(int i=0;i<next_heads.size();i++)if(next_heads[i]==ex.id)found=true;
            if(found)continue;
            next_heads.push_back(ex.id);
          }
        }
        for(int i=0;i<next_heads.size();i++){
          auto&id=next_heads[i];
          auto&ex=arr[id];
          auto&out=ex.out;
          bool ok=true;
          for(int i=0;i<out.size();i++){
            auto&id=out[i];
            for(int i=0;i<next_heads.size();i++){
              if(next_heads[i]==id)ok=false;
            }
          }
          if(!ok)continue;
          next.push_back(ex.id);
        }
        for(int i=0;i<next.size();i++){
          auto&id=next[i];
          auto&ex=arr[id];
          ex.passed=true;
        }
        std::sort(heads.begin(),heads.end());
        for(int i=0;i<heads.size();i++){
          auto&id=heads[i];
          auto&ex=arr[id];
          out.push_back(ex.name);
        }
        heads=std::move(next);
      }
      return out;
    }
  };
public:
  typedef t_config_2013::t_event t_event;
  typedef t_config_2013::t_item t_item;
  static vector<string> list_apply_events(const vector<string>&arr,vector<t_event>&events){
    t_points points;
    points.load_points(arr);
    points.load_edges_from_events(events);
    bool ok=!points.isCyclical();
    QapAssert(ok);
    auto list=points.toList();
    return list;
  }
  void remake(vector<t_item>&points,vector<t_event>&events){
    vector<string> arr;
    arr.resize(points.size());
    for(int i=0;i<arr.size();i++){
      arr[i]=points[i].type;
    }
    auto out=list_apply_events(arr,events);
    QapAssert(out.size()==points.size());
    for(int i=0;i<arr.size();i++){
      points[i].type=out[i];
    }
  }
public:
  template<class TYPE>
  struct go_poly{
    vector<t_out_rec<TYPE>>&out_arr;
    i_dev&dev;
    TAutoPtr<TYPE>&ref;
    t_fallback&scope;
    int&count;
    int&first_id;
    const string&strbasetype;
    IEnvRTTI&Env;
    template<class T>
    void go_for(){
      t_fallback scope(dev,__FUNCTION__);
      T tmp;
      scope.ok=tmp.go(dev);
      t_out_rec<TYPE> rec;
      static const string strtype=Sys$$<T>::GetRTTI(Env)->GetFullName();
      rec.info=strtype;
      if(scope.ok)
      {
        auto*p=rec.object.build<T>(dev.getEnv());
        *p=std::move(tmp);
        if(!count)first_id=out_arr.size();
        count++;
      }
      dev.getPos(rec.pos);
      out_arr.push_back(std::move(rec));
      scope.ok=false;
    }
    void main()
    {
      typedef t_poly_tool::t_out_rec<TYPE> t_out_rec;
      if(!count){scope.ok=false;return;}
      auto use=[this](t_out_rec&ex){
        QapAssert(ex.object);
        ref=std::move(ex.object);
        dev.setPos(ex.pos);
        scope.ok=true;
      };
      if(count==1)
      {
        auto&ex=out_arr[first_id];
        use(ex);
        return;
      }
      auto&tool=t_poly_tool::get(Env);
      auto&arr=tool.get_base_arr(Env,strbasetype,out_arr);
      vector<t_out_rec> out;
      auto update_mass=[&](){
        for(int i=0;i<out.size();i++){
          auto&ex=out[i];
          ex.mass=t_poly_tool::get_mass(arr,ex.info);
        }
      };
      for(int i=0;i<out_arr.size();i++){
        auto&ex=out_arr[i];
        if(!ex.object)continue;
        out.push_back(std::move(ex));
      }
      update_mass();
      vector<int> idarr;idarr.resize(out.size());
      for(int i=0;i<out.size();i++){idarr[i]=i;}
      if(true)
      {
        auto comp_pos=[&out](const int&a,const int&b)->bool{return out[a].pos>out[b].pos;};
        std::sort(std::begin(idarr),std::end(idarr),comp_pos);
        QapAssert(out[idarr[0]].pos>out[idarr[1]].pos);
        int fix_count=0;
        for(int i=1;i<out.size();i++){
          auto&pa=idarr[i-1];
          auto&pb=idarr[i-0];
          auto&a=out[pa];
          auto&b=out[pb];
          auto&base=tool.find(strbasetype);
          auto&events=base.events;
          auto find_event=[&events](const string&a,const string&b)->bool{
            for(int i=0;i<events.size();i++){
              if(events[i].A.type!=a)continue;
              if(events[i].B.type!=b)continue;
              return true;
            }
            return false;
          };
          bool flag_ab=find_event(a.info,b.info);
          bool flag_ba=find_event(b.info,a.info);
          QapAssert(!flag_ba);
          if(flag_ab)continue;
          events.push_back(t_config_2013::t_event());
          auto&back=events.back();
          back.time=cur_date_str();
          back.A.pos=IToS(a.pos);
          back.A.type=a.info;
          back.B.pos=IToS(b.pos);
          back.B.type=b.info;
          fix_count++;
        }
        if(fix_count){
          auto&base=tool.find(strbasetype);
          auto&events=base.events;
          tool.remake(base.arr,events);
          tool.save_doc(Env,"config.cfg");
          update_mass();
        }
      }
      auto comp_func=[&out](const int&a,const int&b)->bool{return out[a].mass<out[b].mass;};
      std::sort(std::begin(idarr),std::end(idarr),comp_func);
      QapAssert(out[idarr[0]].mass<out[idarr[1]].mass);
      for(int i=1;i<out.size();i++){
        auto&pa=idarr[i-1];
        auto&pb=idarr[i-0];
        auto&a=out[pa];
        auto&b=out[pb];
        if(a.pos>b.pos)continue;
        string msg="wrong mass for:\n";
        msg+="a.info = "+a.info+"\n";
        msg+="a.pos = "+IToS(a.pos)+"\n";
        msg+="b.info = "+b.info+"\n";
        msg+="b.pos = "+IToS(b.pos)+"\n";
        QapDebugMsg(msg);
      }
      use(out[idarr[0]]);
    }
  };
};
class t_number{
public:
  public:typedef t_number SelfClass;
  public:
  string body;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_number(const t_number&)=delete;t_number(){DoReset();};
  public:
    t_number(t_number&&_Right){operator=(std::move(_Right));}
    void operator=(t_number&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_number";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_number";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any(body,gen_dips("09"));
    if(!ok)return ok;
    return ok;
  }
};
class i_str_item{
  public:typedef i_str_item SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    i_str_item(const i_str_item&)=delete;i_str_item(){DoReset();};
  public:
    i_str_item(i_str_item&&_Right){operator=(std::move(_Right));}
    void operator=(i_str_item&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="i_str_item";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "i_str_item";
      }
    };
  public:
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_str_item_raw>();
      go_for<t_str_item_hex>();
      go_for<t_str_item_num>();
      go_for<t_str_item_fix>();
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
  vector<t_out_rec> out_arr;
  static int out_arr_size=0;
  out_arr.reserve(out_arr_size);
  t_fallback scope(dev,__FUNCTION__);
  int count=0;
  int first_id=-1;
  auto&Env=dev.getEnv();
  static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
  };
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
  virtual string get_value()const{QapDebugMsg("no way.");return "";}
};
class t_str_item_raw:public i_str_item{
public:
  public:typedef t_str_item_raw SelfClass;public:typedef i_str_item ParentClass;
  public:
  string body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_str_item_raw(const t_str_item_raw&)=delete;t_str_item_raw(){DoReset();};
  public:
    t_str_item_raw(t_str_item_raw&&_Right){operator=(std::move(_Right));}
    void operator=(t_str_item_raw&&_Right)
    {
      struct hidden{static void foo(i_str_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_str_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_str_item_raw";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_str_item_raw";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    static const auto dip_for_body=CharMask::fromStr(dip_inv("\"\\\n"));
    D+=dev.go_any(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body;}
  string get_value()const{return body;}
};
class t_str_item_hex:public i_str_item{
public:
  public:typedef t_str_item_hex SelfClass;public:typedef i_str_item ParentClass;
  public:
  array<char,2> body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_str_item_hex(const t_str_item_hex&)=delete;t_str_item_hex(){DoReset();};
  public:
    t_str_item_hex(t_str_item_hex&&_Right){operator=(std::move(_Right));}
    void operator=(t_str_item_hex&&_Right)
    {
      struct hidden{static void foo(i_str_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_str_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_str_item_hex";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<array<char,2>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_str_item_hex";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\x");
    if(!ok)return ok;
    static const string dip_for_body=gen_dips("09afAF");
    D+=dev.go_any_arr_char(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    auto value=CToS(n);
    return value;
  }
};
class t_str_item_num:public i_str_item{
public:
  public:typedef t_str_item_num SelfClass;public:typedef i_str_item ParentClass;
  public:
  array<char,2> body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_str_item_num(const t_str_item_num&)=delete;t_str_item_num(){DoReset();};
  public:
    t_str_item_num(t_str_item_num&&_Right){operator=(std::move(_Right));}
    void operator=(t_str_item_num&&_Right)
    {
      struct hidden{static void foo(i_str_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_str_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_str_item_num";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<array<char,2>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_str_item_num";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\u");
    if(!ok)return ok;
    static const string dip_for_body=gen_dips("09");
    D+=dev.go_any_arr_char(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    auto value=CToS(n);
    return value;
  }
};
class t_str_item_fix:public i_str_item{
public:
  public:typedef t_str_item_fix SelfClass;public:typedef i_str_item ParentClass;
  public:
  char body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  (this->body)=('n');
    }
  public:
    t_str_item_fix(const t_str_item_fix&)=delete;t_str_item_fix(){DoReset();};
  public:
    t_str_item_fix(t_str_item_fix&&_Right){operator=(std::move(_Right));}
    void operator=(t_str_item_fix&&_Right)
    {
      struct hidden{static void foo(i_str_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_str_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_str_item_fix";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"SET","'n'");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_str_item_fix";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\");
    if(!ok)return ok;
    static const string dip_for_body="tfbrn\\\"\'"+gen_dips("07");
    D+=dev.go_any_char(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=SelfClass::get_code();
    BinString str=code;
    return str.data;
  }
};
class t_str_item{
public:
  class t_impl{
  public:
  public:typedef t_str_item OwnerClass;
  public:typedef t_impl SelfClass;
  public:
   vector<TAutoPtr<i_str_item>> arr;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->arr); 
    }
  public:
    t_impl(const t_impl&)=delete;t_impl(){DoReset();};
  public:
    t_impl(t_impl&&_Right){operator=(std::move(_Right));}
    void operator=(t_impl&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->arr=std::move(_Right.arr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_str_item>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_impl";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("\"");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("\"");
      if(!ok)return ok;
      return ok;
    }
    string get_code()const{
      string out;
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->get_code();
      }
      return out;
    }
    string get_value()const{
      string out;
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->get_value();
      }
      return out;
    }
  };
public:
  public:typedef t_str_item SelfClass;
  public:
  string value;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->value);
    }
  public:
    t_str_item(const t_str_item&)=delete;t_str_item(){DoReset();};
  public:
    t_str_item(t_str_item&&_Right){operator=(std::move(_Right));}
    void operator=(t_str_item&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->value=std::move(_Right.value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_str_item";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_str_item";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_str<t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl");return "";}
};
class i_char_item{
  public:typedef i_char_item SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    i_char_item(const i_char_item&)=delete;i_char_item(){DoReset();};
  public:
    i_char_item(i_char_item&&_Right){operator=(std::move(_Right));}
    void operator=(i_char_item&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="i_char_item";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "i_char_item";
      }
    };
  public:
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_char_item_raw>();
      go_for<t_char_item_hex>();
      go_for<t_char_item_num>();
      go_for<t_char_item_fix>();
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
  vector<t_out_rec> out_arr;
  static int out_arr_size=0;
  out_arr.reserve(out_arr_size);
  t_fallback scope(dev,__FUNCTION__);
  int count=0;
  int first_id=-1;
  auto&Env=dev.getEnv();
  static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
  };
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
  virtual string get_value()const{QapDebugMsg("no way.");return "";}
};
class t_char_item_raw:public i_char_item{
public:
  public:typedef t_char_item_raw SelfClass;public:typedef i_char_item ParentClass;
  public:
  string body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_char_item_raw(const t_char_item_raw&)=delete;t_char_item_raw(){DoReset();};
  public:
    t_char_item_raw(t_char_item_raw&&_Right){operator=(std::move(_Right));}
    void operator=(t_char_item_raw&&_Right)
    {
      struct hidden{static void foo(i_char_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_char_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_char_item_raw";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_char_item_raw";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any(body,dip_inv("\'\\\n"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body;}
  string get_value()const{return body;}
};
class t_char_item_hex:public i_char_item{
public:
  public:typedef t_char_item_hex SelfClass;public:typedef i_char_item ParentClass;
  public:
  array<char,2> body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_char_item_hex(const t_char_item_hex&)=delete;t_char_item_hex(){DoReset();};
  public:
    t_char_item_hex(t_char_item_hex&&_Right){operator=(std::move(_Right));}
    void operator=(t_char_item_hex&&_Right)
    {
      struct hidden{static void foo(i_char_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_char_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_char_item_hex";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<array<char,2>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_char_item_hex";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\x");
    if(!ok)return ok;
    D+=dev.go_any_arr_char(body,gen_dips("09afAF"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    auto value=CToS(n);
    return value;
  }
};
class t_char_item_num:public i_char_item{
public:
  public:typedef t_char_item_num SelfClass;public:typedef i_char_item ParentClass;
  public:
  array<char,4> body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_char_item_num(const t_char_item_num&)=delete;t_char_item_num(){DoReset();};
  public:
    t_char_item_num(t_char_item_num&&_Right){operator=(std::move(_Right));}
    void operator=(t_char_item_num&&_Right)
    {
      struct hidden{static void foo(i_char_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_char_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_char_item_num";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<array<char,4>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_char_item_num";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\u");
    if(!ok)return ok;
    D+=dev.go_any_arr_char(body,gen_dips("09"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    auto value=CToS(n);
    return value;
  }
};
class t_char_item_fix:public i_char_item{
public:
  public:typedef t_char_item_fix SelfClass;public:typedef i_char_item ParentClass;
  public:
  char body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  (this->body)=('\0');
    }
  public:
    t_char_item_fix(const t_char_item_fix&)=delete;t_char_item_fix(){DoReset();};
  public:
    t_char_item_fix(t_char_item_fix&&_Right){operator=(std::move(_Right));}
    void operator=(t_char_item_fix&&_Right)
    {
      struct hidden{static void foo(i_char_item(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_char_item::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_char_item_fix";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"SET","'\\0'");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_char_item_fix";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\");
    if(!ok)return ok;
    D+=dev.go_any_char(body,"tfbrn\\\"\'"+gen_dips("07"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=SelfClass::get_code();
    BinString str=code;
    return str.data;
  }
};
class t_char_item{
public:
  class t_impl{
  public:
  public:typedef t_char_item OwnerClass;
  public:typedef t_impl SelfClass;
  public:
   TAutoPtr<i_char_item> body;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->body); 
    }
  public:
    t_impl(const t_impl&)=delete;t_impl(){DoReset();};
  public:
    t_impl(t_impl&&_Right){operator=(std::move(_Right));}
    void operator=(t_impl&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<i_char_item>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_impl";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("\'");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const("\'");
      if(!ok)return ok;
      return ok;
    }
    string get_code()const{return "\'"+body->get_code()+"\'";}
    string get_value()const{
      return body->get_value();
    }
  };
public:
  public:typedef t_char_item SelfClass;
  public:
  string value;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->value);
    }
  public:
    t_char_item(const t_char_item&)=delete;t_char_item(){DoReset();};
  public:
    t_char_item(t_char_item&&_Right){operator=(std::move(_Right));}
    void operator=(t_char_item&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->value=std::move(_Right.value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_char_item";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_char_item";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl>(value);
    return ok;
  }
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl");return "";}
};
static void RegAllCppLex(IEnvRTTI&Env){
  {Sys$$<t_char_item_raw>::GetRTTI(Env);};
  {Sys$$<t_char_item_hex>::GetRTTI(Env);};
  {Sys$$<t_char_item_num>::GetRTTI(Env);};
  {Sys$$<t_char_item_fix>::GetRTTI(Env);};
  {Sys$$<t_str_item_raw>::GetRTTI(Env);};
  {Sys$$<t_str_item_hex>::GetRTTI(Env);};
  {Sys$$<t_str_item_num>::GetRTTI(Env);};
  {Sys$$<t_str_item_fix>::GetRTTI(Env);};
}
class i_sep{
  public:typedef i_sep SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    i_sep(const i_sep&)=delete;i_sep(){DoReset();};
  public:
    i_sep(i_sep&&_Right){operator=(std::move(_Right));}
    void operator=(i_sep&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="i_sep";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "i_sep";
      }
    };
  public:
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_sep_seq>();
      go_for<t_c_comment>();
      go_for<t_cpp_comment>();
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
  vector<t_out_rec> out_arr;
  static int out_arr_size=0;
  out_arr.reserve(out_arr_size);
  t_fallback scope(dev,__FUNCTION__);
  int count=0;
  int first_id=-1;
  auto&Env=dev.getEnv();
  static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
  };
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
};
class i_expr{
  public:typedef i_expr SelfClass;
  public:
    public:
    void DoReset()
    {
      {
      }
    }
  public:
    i_expr(const i_expr&)=delete;i_expr(){DoReset();};
  public:
    i_expr(i_expr&&_Right){operator=(std::move(_Right));}
    void operator=(i_expr&&_Right)
    {
      if(&_Right==this)return;
      {
      }
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="i_expr";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "i_expr";
      }
    };
  public:
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
    template<int>
    bool load()
    {
      go_for<t_str>();
      go_for<t_char>();
      go_for<t_num>();
      go_for<t_id>();
      go_for<t_sign>();
      go_for<t_soft_brackets>();
      go_for<t_hard_brackets>();
      go_for<t_curly_brackets>();
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
  vector<t_out_rec> out_arr;
  static int out_arr_size=0;
  out_arr.reserve(out_arr_size);
  t_fallback scope(dev,__FUNCTION__);
  int count=0;
  int first_id=-1;
  auto&Env=dev.getEnv();
  static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
  };
};
class t_sep_seq:public i_sep{
public:
  public:typedef t_sep_seq SelfClass;public:typedef i_sep ParentClass;
  public:
  string body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_sep_seq(const t_sep_seq&)=delete;t_sep_seq(){DoReset();};
  public:
    t_sep_seq(t_sep_seq&&_Right){operator=(std::move(_Right));}
    void operator=(t_sep_seq&&_Right)
    {
      struct hidden{static void foo(i_sep(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_sep::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_sep_seq";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_sep_seq";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any(body," \t\r\n");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body;
  }
};
class t_c_comment:public i_sep{
public:
  public:typedef t_c_comment SelfClass;public:typedef i_sep ParentClass;
  public:
  string body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_c_comment(const t_c_comment&)=delete;t_c_comment(){DoReset();};
  public:
    t_c_comment(t_c_comment&&_Right){operator=(std::move(_Right));}
    void operator=(t_c_comment&&_Right)
    {
      struct hidden{static void foo(i_sep(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_sep::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_c_comment";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_c_comment";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("/*");
    if(!ok)return ok;
    D+=dev.go_end(body,"*/");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return "/*"+body+"*/";
  }
};
class t_cpp_comment:public i_sep{
public:
  public:typedef t_cpp_comment SelfClass;public:typedef i_sep ParentClass;
  public:
  string body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_cpp_comment(const t_cpp_comment&)=delete;t_cpp_comment(){DoReset();};
  public:
    t_cpp_comment(t_cpp_comment&&_Right){operator=(std::move(_Right));}
    void operator=(t_cpp_comment&&_Right)
    {
      struct hidden{static void foo(i_sep(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_sep::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_cpp_comment";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_cpp_comment";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("//");
    if(!ok)return ok;
    D+=dev.go_end(body,"\n");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return "//"+body+"\n";
  }
};
class t_sep{
public:
  class t_impl{
  public:
  public:typedef t_sep OwnerClass;
  public:typedef t_impl SelfClass;
  public:
   vector<TAutoPtr<i_sep>> arr;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->arr); 
    }
  public:
    t_impl(const t_impl&)=delete;t_impl(){DoReset();};
  public:
    t_impl(t_impl&&_Right){operator=(std::move(_Right));}
    void operator=(t_impl&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->arr=std::move(_Right.arr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_sep>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_impl";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
      string out="";
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->make_code();
      }
      return out;
    }
  };
public:
  public:typedef t_sep SelfClass;
  public:
  string value;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->value);
    }
  public:
    t_sep(const t_sep&)=delete;t_sep(){DoReset();};
  public:
    t_sep(t_sep&&_Right){operator=(std::move(_Right));}
    void operator=(t_sep&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->value=std::move(_Right.value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_sep";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_sep";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return value;}
};
class t_str:public i_expr{
public:
  public:typedef t_str SelfClass;public:typedef i_expr ParentClass;
  public:
  t_str_item body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_str(const t_str&)=delete;t_str(){DoReset();};
  public:
    t_str(t_str&&_Right){operator=(std::move(_Right));}
    void operator=(t_str&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_str";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<t_str_item>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_str";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
class t_char:public i_expr{
public:
  public:typedef t_char SelfClass;public:typedef i_expr ParentClass;
  public:
  t_char_item body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_char(const t_char&)=delete;t_char(){DoReset();};
  public:
    t_char(t_char&&_Right){operator=(std::move(_Right));}
    void operator=(t_char&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_char";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<t_char_item>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_char";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
class t_num:public i_expr{
public:
  public:typedef t_num SelfClass;public:typedef i_expr ParentClass;
  public:
  t_number body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_num(const t_num&)=delete;t_num(){DoReset();};
  public:
    t_num(t_num&&_Right){operator=(std::move(_Right));}
    void operator=(t_num&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_num";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<t_number>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_num";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
class t_name{
public:
  class t_keyword{
  public:typedef t_name OwnerClass;
  public:typedef t_keyword SelfClass;
  public:
   string value;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->value); 
    }
  public:
    t_keyword(const t_keyword&)=delete;t_keyword(){DoReset();};
  public:
    t_keyword(t_keyword&&_Right){operator=(std::move(_Right));}
    void operator=(t_keyword&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->value=std::move(_Right.value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_keyword";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_keyword";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_split_arr_0=QapStrFinder::fromArr(split(
        "false,true,this,struct,class,for,if,while,const,else,operator,auto,continue,"
        "break,return,goto,virtual,template,typedef,using,typename,explicit,nullptr,switch,case,"
        "do,throw,try,catch,inline,enum",
        ","
      ));
      D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_impl{
  public:
  public:typedef t_name OwnerClass;
  public:typedef t_impl SelfClass;
  public:
   char A;
    string B;
    public:
    void DoReset()
    {
      {
      }
   (this->A)=('A'); detail::FieldTryDoReset(this->B); 
    }
  public:
    t_impl(const t_impl&)=delete;t_impl(){DoReset();};
  public:
    t_impl(t_impl&&_Right){operator=(std::move(_Right));}
    void operator=(t_impl&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->A=std::move(_Right.A);
    this->B=std::move(_Right.B);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"A",int(&(((SelfClass*)nullptr)->*(&SelfClass::A))),"SET","'A'");
    Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"B",int(&(((SelfClass*)nullptr)->*(&SelfClass::B))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_impl";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto dip_for_a=CharMask::fromStr(gen_dips("azAZ")+"_$@");
      M+=dev.go_any_char(A,dip_for_a);
      if(!ok)return ok;
      static const auto dip_for_b=CharMask::fromStr(gen_dips("azAZ09")+"_$@");
      O+=dev.go_any(B,dip_for_b);
      if(!ok)return ok;
      return ok;
    }
    string get()const{return CToS(A)+B;}
  };
  class t_impl_ex{
  public:typedef t_name OwnerClass;
  public:typedef t_impl_ex SelfClass;
  public:
   t_impl impl;
    public:
    void DoReset()
    {
      {
      }
   detail::FieldTryDoReset(this->impl); 
    }
  public:
    t_impl_ex(const t_impl_ex&)=delete;t_impl_ex(){DoReset();};
  public:
    t_impl_ex(t_impl_ex&&_Right){operator=(std::move(_Right));}
    void operator=(t_impl_ex&&_Right)
    {
      if(&_Right==this)return;
      {
      }
   this->impl=std::move(_Right.impl);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_impl_ex";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"impl",int(&(((SelfClass*)nullptr)->*(&SelfClass::impl))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_impl_ex";
      }
    };
  public:
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_diff<t_keyword>(impl);
      if(!ok)return ok;
      return ok;
    }
  };
  public:typedef t_name SelfClass;
  public:
  string value;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->value);
    }
  public:
    t_name(const t_name&)=delete;t_name(){DoReset();};
  public:
    t_name(t_name&&_Right){operator=(std::move(_Right));}
    void operator=(t_name&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->value=std::move(_Right.value);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_name";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_keyword>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_impl_ex>::GetRTTI(RTTI));
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_name";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl_ex>(value);
    if(!ok)return ok;
    return ok;
  }
  string get()const{return value;}
};
class t_id:public i_expr{
public:
  public:typedef t_id SelfClass;public:typedef i_expr ParentClass;
  public:
  t_name body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->body);
    }
  public:
    t_id(const t_id&)=delete;t_id(){DoReset();};
  public:
    t_id(t_id&&_Right){operator=(std::move(_Right));}
    void operator=(t_id&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_id";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<t_name>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_id";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
class t_sign:public i_expr{
public:
  public:typedef t_sign SelfClass;public:typedef i_expr ParentClass;
  public:
  char body;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  (this->body)=('?');
    }
  public:
    t_sign(const t_sign&)=delete;t_sign(){DoReset();};
  public:
    t_sign(t_sign&&_Right){operator=(std::move(_Right));}
    void operator=(t_sign&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_sign";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberSET(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"SET","'?'");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_sign";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any_char(body,"~|&=<>!:?;,.+-*/%^");
    if(!ok)return ok;
    return ok;
  }
};
class t_soft_brackets:public i_expr{
public:
  public:typedef t_soft_brackets SelfClass;public:typedef i_expr ParentClass;
  public:
  vector<TAutoPtr<i_expr>> arr;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->arr);
    }
  public:
    t_soft_brackets(const t_soft_brackets&)=delete;t_soft_brackets(){DoReset();};
  public:
    t_soft_brackets(t_soft_brackets&&_Right){operator=(std::move(_Right));}
    void operator=(t_soft_brackets&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->arr=std::move(_Right.arr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_soft_brackets";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_soft_brackets";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("(");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const(")");
    if(!ok)return ok;
    return ok;
  }
};
class t_hard_brackets:public i_expr{
public:
  public:typedef t_hard_brackets SelfClass;public:typedef i_expr ParentClass;
  public:
  vector<TAutoPtr<i_expr>> arr;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->arr);
    }
  public:
    t_hard_brackets(const t_hard_brackets&)=delete;t_hard_brackets(){DoReset();};
  public:
    t_hard_brackets(t_hard_brackets&&_Right){operator=(std::move(_Right));}
    void operator=(t_hard_brackets&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->arr=std::move(_Right.arr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_hard_brackets";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_hard_brackets";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("[");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("]");
    if(!ok)return ok;
    return ok;
  }
};
class t_curly_brackets:public i_expr{
public:
  public:typedef t_curly_brackets SelfClass;public:typedef i_expr ParentClass;
  public:
  vector<TAutoPtr<i_expr>> arr;
    public:
    void DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);
      }
  detail::FieldTryDoReset(this->arr);
    }
  public:
    t_curly_brackets(const t_curly_brackets&)=delete;t_curly_brackets(){DoReset();};
  public:
    t_curly_brackets(t_curly_brackets&&_Right){operator=(std::move(_Right));}
    void operator=(t_curly_brackets&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));
      }
  this->arr=std::move(_Right.arr);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_curly_brackets";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_curly_brackets";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
};
class t_param{
public:
  public:typedef t_param SelfClass;
  public:
  t_sep sep;
  vector<TAutoPtr<i_expr>> body;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->sep);detail::FieldTryDoReset(this->body);
    }
  public:
    t_param(const t_param&)=delete;t_param(){DoReset();};
  public:
    t_param(t_param&&_Right){operator=(std::move(_Right));}
    void operator=(t_param&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->sep=std::move(_Right.sep);
  this->body=std::move(_Right.body);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_param";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_expr>>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_param";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
class t_line{
public:
  public:typedef t_line SelfClass;
  public:
  t_name cmd;
  vector<t_param> params;
    public:
    void DoReset()
    {
      {
      }
  detail::FieldTryDoReset(this->cmd);detail::FieldTryDoReset(this->params);
    }
  public:
    t_line(const t_line&)=delete;t_line(){DoReset();};
  public:
    t_line(t_line&&_Right){operator=(std::move(_Right));}
    void operator=(t_line&&_Right)
    {
      if(&_Right==this)return;
      {
      }
  this->cmd=std::move(_Right.cmd);
  this->params=std::move(_Right.params);
    }
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        static const string Name="t_line";
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<t_name>::GetRTTI(RTTI),"cmd",int(&(((SelfClass*)nullptr)->*(&SelfClass::cmd))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        return "t_line";
      }
    };
  public:
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(cmd);
    if(!ok)return ok;
    O+=dev.go_auto(params);
    if(!ok)return ok;
    return ok;
  }
  vector<string> get_raw_params(IEnvRTTI&Env){
    vector<string> out;
    for(int i=0;i<params.size();i++){
      auto&ex=params[i];
      string mem;
      bool ok=save_obj(Env,ex.body,mem);
      QapAssert(ok);
      out.push_back(mem);
    }
    return std::move(out);
  }
};
static void QapLexerRegAll(IEnvRTTI&Env){
  {Sys$$<t_sep_seq>::GetRTTI(Env);};
  {Sys$$<t_c_comment>::GetRTTI(Env);};
  {Sys$$<t_cpp_comment>::GetRTTI(Env);};
  {Sys$$<t_sep>::GetRTTI(Env);};
  {Sys$$<t_str>::GetRTTI(Env);};
  {Sys$$<t_char>::GetRTTI(Env);};
  {Sys$$<t_num>::GetRTTI(Env);};
  {Sys$$<t_name>::GetRTTI(Env);};
  {Sys$$<t_id>::GetRTTI(Env);};
  {Sys$$<t_sign>::GetRTTI(Env);};
  {Sys$$<t_soft_brackets>::GetRTTI(Env);};
  {Sys$$<t_hard_brackets>::GetRTTI(Env);};
  {Sys$$<t_curly_brackets>::GetRTTI(Env);};
  {Sys$$<t_line>::GetRTTI(Env);};
  {Sys$$<t_param>::GetRTTI(Env);};
}
/*
F(t_sep_seq);
F(t_c_comment);
F(t_cpp_comment);
F(t_sep);
F(t_raw_item);
F(t_hex_item);
F(t_num_item);
F(t_fix_item);
F(t_str);
F(t_raw_char);
F(t_hex_char);
F(t_num_char);
F(t_fix_char);
F(t_char);
F(t_number);
F(t_name);
F(t_id);
F(t_sign);
F(t_soft_brackets);
F(t_hard_brackets);
F(t_curly_brackets);
F(t_line);
F(t_param);
adler3d.github.io/test2013/
return decodeURIComponent(POST['data'].split("\n").join(""));
t%5Fsep%5Fseq%3D%3Ei%5Fsep%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20%20%2
0go%5Fany%28body%2C%22%20%5Ct%5Cr%5Cn%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fc%5Fco
mment%3D%3Ei%5Fsep%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fco
nst%28%22%2F%2A%22%29%3B%0A%20%20%20%20go%5Fend%28body%2C%22%2A%2F%22%29%3B%0A%2
0%20%7D%0A%7D%0A%0At%5Fcpp%5Fcomment%3D%3Ei%5Fsep%7B%0A%20%20string%20body%3B%0A
%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%2F%2F%22%29%3B%0A%20%20%20%20go%5Fend%2
8body%2C%22%5Cn%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fsep%7B%0A%20%20vector%3CTAut
oPtr%3Ci%5Fsep%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28arr%29%3B%0A
%20%20%7D%0A%7D%0A%0At%5Fraw%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%20string%20body
%3B%0A%20%20%7B%0A%20%20%20%20go%5Fany%28body%2Cdip%5Finv%28%22%5C%22%5C%5C%5Cn%
22%29%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fhex%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%2
0array%28char%2C2%29%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cx
%22%29%3B%0A%20%20%20%20go%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209afAF%22
%29%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fnum%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%20a
rray%28char%2C2%29%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cu%2
2%29%3B%0A%20%20%20%20go%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209%22%29%29
%3B%0A%20%20%7D%0A%7D%0A%0At%5Ffix%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%20char%20
body%3D%27%5Cx00%27%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5C%22%29%3B
%0A%20%20%20%20go%5Fany%5Fchar%28body%2C%22tfbrn%5C%5C%5C%22%5C%27%22%2Bgen%5Fdi
ps%28%2209%22%29%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fstr%3D%3Ei%5Fparam%7B%0A%20%20
vector%3CTAutoPtr%3Ci%5Fstr%5Fitem%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20M%2B
%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A
%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fra
w%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20%2
0%20go%5Fany%28body%2Cdip%5Finv%28%22%5C%27%5C%5C%5Cn%22%29%29%3B%0A%20%20%7D%0A
%7D%0A%0At%5Fhex%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20array%28char%2C2%29%20bo
dy%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cx%22%29%3B%0A%20%20%20%20g
o%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209afAF%22%29%29%3B%0A%20%20%7D%0A%
7D%0A%0At%5Fnum%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20array%28char%2C4%29%20bod
y%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cu%22%29%3B%0A%20%20%20%20go
%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%7D%0A%7D%0A
%0At%5Ffix%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20char%20body%3B%0A%20%20%7B%0A%
20%20%20%20go%5Fconst%28%22%5C%5C%22%29%3B%0A%20%20%20%20go%5Fany%5Fchar%28body%
2C%22tfbrn%5C%5C%5C%22%5C%27%22%2Bgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%7D%0A%
7D%0A%0At%5Fchar%3D%3Ei%5Fparam%7B%0A%20%20TAutoPtr%3Ci%5Fchar%5Fitem%3E%20body%
3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%27%22%29%3B%0A%20%20%20%20go%5F
auto%28dev%2Cbody%29%3B%0A%20%20%20%20go%5Fconst%28%22%5C%27%22%29%3B%0A%20%20%7
D%0A%7D%0A%0At%5Fnumber%3D%3Ei%5Fparam%7B%0A%20%20string%20body%3B%0A%20%20%7B%0
A%20%20%20%20go%5Fany%28body%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%7D%0A%7D%
0A%0At%5Fname%7B%0A%20%20char%20A%3D%270x00%27%3B%0A%20%20string%20B%3B%0A%20%20
%7B%0A%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28A%2Cgen%5Fdips%28%22azAZ%22%29%2B%22%
5F%24%40%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fany%28B%2Cgen%5Fdips%28%22azAZ09%22%
29%2B%22%5F%24%40%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fid%3D%3Ei%5Fparam%7B%0A%20
%20t%5Fname%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%
7D%0A%7D%0A%0At%5Fsign%3D%3Ei%5Fparam%7B%0A%20%20char%20body%3B%0A%20%20%7B%0A%2
0%20%20%20go%5Fany%5Fchar%28body%2C%22%7E%7C%26%3D%3C%3E%21%3A%3F%3B%2C%2E%2B%2D
%2A%2F%25%5E%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fsoft%5Fbrackets%3D%3Ei%5Fparam%
7B%0A%20%20vector%3CTAutoPtr%3Ci%5Fparam%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%
20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B
%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fha
rd%5Fbrackets%3D%3Ei%5Fparam%7B%0A%20%20vector%3CTAutoPtr%3Ci%5Fparam%3E%3E%20ar
r%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5B%22%29%3B%0A%20%20%20%2
0O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5D%22%29%3B%
0A%20%20%7D%0A%7D%0A%0At%5Fcurly%5Fbrackets%3D%3Ei%5Fparam%7B%0A%20%20vector%3CT
AutoPtr%3Ci%5Fparam%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%2
8%22%7B%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3
Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fline%7B%0A%20%20t%5Fnam
e%20cmd%3B%0A%20%20vector%3Ct%5Fparam%3E%20params%3B%0A%20%20%7B%0A%20%20%20%20g
o%5Fauto%28cmd%29%3B%0A%20%20%20%20go%5Fauto%28params%29%3B%0A%20%20%7D%0A%7D%0A
%0At%5Fparam%7B%0A%20%20t%5Fsep%20sep%3B%0A%20%20TAutoPtr%3Ci%5Fparam%3E%20body%
3B%0A%20%20%7B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dg
o%5Fauto%28body%29%3B%0A%20%20%7D%0A%7D
*/
class t_inl_file
{
public:
  class i_class_stat;
  class t_access_mod_class_stat;
  class t_fv_class_stat;
  class t_typedef_class_stat;
  class t_dtor_class_stat;
  class t_ctor_class_stat;
  class t_oper_cast_class_stat;
  class t_common_oper_class_stat;
  class t_namespace_class_stat;
  class t_template_class_stat;
  class t_enum_class_stat;
  class t_using_class_stat;
  class t_pragma_class_stat;
  class t_include_class_stat;
  class t_preproc_if_class_stat;
  class t_preproc_else_class_stat;
  class t_preproc_endif_class_stat;
  class t_define_class_stat;
  class t_undef_class_stat;
  class t_sep_class_stat;
  class t_null_class_stat;
  class t_class_class_stat;
  class i_class_stat_visitor
  {
  public:
    typedef t_inl_file::i_class_stat i_class_stat;
  public:
    virtual void Do(t_access_mod_class_stat*p)=0;
    virtual void Do(t_fv_class_stat*p)=0;
    virtual void Do(t_typedef_class_stat*p)=0;
    virtual void Do(t_dtor_class_stat*p)=0;
    virtual void Do(t_ctor_class_stat*p)=0;
    virtual void Do(t_oper_cast_class_stat*p)=0;
    virtual void Do(t_common_oper_class_stat*p)=0;
    virtual void Do(t_namespace_class_stat*p)=0;
    virtual void Do(t_template_class_stat*p)=0;
    virtual void Do(t_enum_class_stat*p)=0;
    virtual void Do(t_using_class_stat*p)=0;
    virtual void Do(t_pragma_class_stat*p)=0;
    virtual void Do(t_include_class_stat*p)=0;
    virtual void Do(t_preproc_if_class_stat*p)=0;
    virtual void Do(t_preproc_else_class_stat*p)=0;
    virtual void Do(t_preproc_endif_class_stat*p)=0;
    virtual void Do(t_define_class_stat*p)=0;
    virtual void Do(t_undef_class_stat*p)=0;
    virtual void Do(t_sep_class_stat*p)=0;
    virtual void Do(t_null_class_stat*p)=0;
    virtual void Do(t_class_class_stat*p)=0;
  public:
    typedef t_inl_file::t_access_mod_class_stat t_access_mod_class_stat;
    typedef t_inl_file::t_fv_class_stat t_fv_class_stat;
    typedef t_inl_file::t_typedef_class_stat t_typedef_class_stat;
    typedef t_inl_file::t_dtor_class_stat t_dtor_class_stat;
    typedef t_inl_file::t_ctor_class_stat t_ctor_class_stat;
    typedef t_inl_file::t_oper_cast_class_stat t_oper_cast_class_stat;
    typedef t_inl_file::t_common_oper_class_stat t_common_oper_class_stat;
    typedef t_inl_file::t_namespace_class_stat t_namespace_class_stat;
    typedef t_inl_file::t_template_class_stat t_template_class_stat;
    typedef t_inl_file::t_enum_class_stat t_enum_class_stat;
    typedef t_inl_file::t_using_class_stat t_using_class_stat;
    typedef t_inl_file::t_pragma_class_stat t_pragma_class_stat;
    typedef t_inl_file::t_include_class_stat t_include_class_stat;
    typedef t_inl_file::t_preproc_if_class_stat t_preproc_if_class_stat;
    typedef t_inl_file::t_preproc_else_class_stat t_preproc_else_class_stat;
    typedef t_inl_file::t_preproc_endif_class_stat t_preproc_endif_class_stat;
    typedef t_inl_file::t_define_class_stat t_define_class_stat;
    typedef t_inl_file::t_undef_class_stat t_undef_class_stat;
    typedef t_inl_file::t_sep_class_stat t_sep_class_stat;
    typedef t_inl_file::t_null_class_stat t_null_class_stat;
    typedef t_inl_file::t_class_class_stat t_class_class_stat;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_access_mod_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_fv_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_typedef_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_dtor_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_ctor_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_oper_cast_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_common_oper_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_namespace_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_template_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_enum_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_using_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_pragma_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_include_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_preproc_if_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_preproc_else_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_preproc_endif_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_define_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_undef_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_sep_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_null_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_class_class_stat*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_class_stat*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_class_stat_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
public:
  class i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_class_stat SelfClass;
  public:
    void DoReset();
  public:
    i_class_stat(const i_class_stat&)=delete;
    i_class_stat();
  public:
    i_class_stat(i_class_stat&&_Right);
    void operator=(i_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    typedef i_class_stat_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_expr;
  class t_call_expr;
  class t_block_expr;
  class t_bool_expr;
  class t_string_expr;
  class t_char_expr;
  class t_num_expr;
  class t_real_expr;
  class t_nullptr_expr;
  class t_or_expr;
  class t_hex_expr;
  class t_var_expr;
  class i_expr_visitor
  {
  public:
    typedef t_inl_file::i_expr i_expr;
  public:
    virtual void Do(t_call_expr*p)=0;
    virtual void Do(t_block_expr*p)=0;
    virtual void Do(t_bool_expr*p)=0;
    virtual void Do(t_string_expr*p)=0;
    virtual void Do(t_char_expr*p)=0;
    virtual void Do(t_num_expr*p)=0;
    virtual void Do(t_real_expr*p)=0;
    virtual void Do(t_nullptr_expr*p)=0;
    virtual void Do(t_or_expr*p)=0;
    virtual void Do(t_hex_expr*p)=0;
    virtual void Do(t_var_expr*p)=0;
  public:
    typedef t_inl_file::t_call_expr t_call_expr;
    typedef t_inl_file::t_block_expr t_block_expr;
    typedef t_inl_file::t_bool_expr t_bool_expr;
    typedef t_inl_file::t_string_expr t_string_expr;
    typedef t_inl_file::t_char_expr t_char_expr;
    typedef t_inl_file::t_num_expr t_num_expr;
    typedef t_inl_file::t_real_expr t_real_expr;
    typedef t_inl_file::t_nullptr_expr t_nullptr_expr;
    typedef t_inl_file::t_or_expr t_or_expr;
    typedef t_inl_file::t_hex_expr t_hex_expr;
    typedef t_inl_file::t_var_expr t_var_expr;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_call_expr*p)
      {
        ptr=get(p);
      } void Do(t_block_expr*p)
      {
        ptr=get(p);
      } void Do(t_bool_expr*p)
      {
        ptr=get(p);
      } void Do(t_string_expr*p)
      {
        ptr=get(p);
      } void Do(t_char_expr*p)
      {
        ptr=get(p);
      } void Do(t_num_expr*p)
      {
        ptr=get(p);
      } void Do(t_real_expr*p)
      {
        ptr=get(p);
      } void Do(t_nullptr_expr*p)
      {
        ptr=get(p);
      } void Do(t_or_expr*p)
      {
        ptr=get(p);
      } void Do(t_hex_expr*p)
      {
        ptr=get(p);
      } void Do(t_var_expr*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_expr*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_expr_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
public:
  class i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_expr SelfClass;
  public:
    void DoReset();
  public:
    i_expr(const i_expr&)=delete;
    i_expr();
  public:
    i_expr(i_expr&&_Right);
    void operator=(i_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_func_body;
  class t_zero_func_body;
  class t_null_func_body;
  class t_delete_func_body;
  class t_impl_func_body;
  class i_func_body_visitor
  {
  public:
    typedef t_inl_file::i_func_body i_func_body;
  public:
    virtual void Do(t_zero_func_body*p)=0;
    virtual void Do(t_null_func_body*p)=0;
    virtual void Do(t_delete_func_body*p)=0;
    virtual void Do(t_impl_func_body*p)=0;
  public:
    typedef t_inl_file::t_zero_func_body t_zero_func_body;
    typedef t_inl_file::t_null_func_body t_null_func_body;
    typedef t_inl_file::t_delete_func_body t_delete_func_body;
    typedef t_inl_file::t_impl_func_body t_impl_func_body;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_zero_func_body*p)
      {
        ptr=get(p);
      } void Do(t_null_func_body*p)
      {
        ptr=get(p);
      } void Do(t_delete_func_body*p)
      {
        ptr=get(p);
      } void Do(t_impl_func_body*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_func_body*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_func_body_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
public:
  class i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_func_body SelfClass;
  public:
    void DoReset();
  public:
    i_func_body(const i_func_body&)=delete;
    i_func_body();
  public:
    i_func_body(i_func_body&&_Right);
    void operator=(i_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    typedef i_func_body_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_tmpl_expr;
  class t_call_tmpl_expr;
  class t_block_tmpl_expr;
  class t_bool_tmpl_expr;
  class t_string_tmpl_expr;
  class t_char_tmpl_expr;
  class t_num_tmpl_expr;
  class t_real_tmpl_expr;
  class t_nullptr_tmpl_expr;
  class t_or_tmpl_expr;
  class t_hex_tmpl_expr;
  class t_var_tmpl_expr;
  class i_tmpl_expr_visitor
  {
  public:
    typedef t_inl_file::i_tmpl_expr i_tmpl_expr;
  public:
    virtual void Do(t_call_tmpl_expr*p)=0;
    virtual void Do(t_block_tmpl_expr*p)=0;
    virtual void Do(t_bool_tmpl_expr*p)=0;
    virtual void Do(t_string_tmpl_expr*p)=0;
    virtual void Do(t_char_tmpl_expr*p)=0;
    virtual void Do(t_num_tmpl_expr*p)=0;
    virtual void Do(t_real_tmpl_expr*p)=0;
    virtual void Do(t_nullptr_tmpl_expr*p)=0;
    virtual void Do(t_or_tmpl_expr*p)=0;
    virtual void Do(t_hex_tmpl_expr*p)=0;
    virtual void Do(t_var_tmpl_expr*p)=0;
  public:
    typedef t_inl_file::t_call_tmpl_expr t_call_tmpl_expr;
    typedef t_inl_file::t_block_tmpl_expr t_block_tmpl_expr;
    typedef t_inl_file::t_bool_tmpl_expr t_bool_tmpl_expr;
    typedef t_inl_file::t_string_tmpl_expr t_string_tmpl_expr;
    typedef t_inl_file::t_char_tmpl_expr t_char_tmpl_expr;
    typedef t_inl_file::t_num_tmpl_expr t_num_tmpl_expr;
    typedef t_inl_file::t_real_tmpl_expr t_real_tmpl_expr;
    typedef t_inl_file::t_nullptr_tmpl_expr t_nullptr_tmpl_expr;
    typedef t_inl_file::t_or_tmpl_expr t_or_tmpl_expr;
    typedef t_inl_file::t_hex_tmpl_expr t_hex_tmpl_expr;
    typedef t_inl_file::t_var_tmpl_expr t_var_tmpl_expr;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_call_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_block_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_bool_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_string_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_char_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_num_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_real_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_nullptr_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_or_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_hex_tmpl_expr*p)
      {
        ptr=get(p);
      } void Do(t_var_tmpl_expr*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_tmpl_expr*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_tmpl_expr_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
public:
  class i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_tmpl_expr SelfClass;
  public:
    void DoReset();
  public:
    i_tmpl_expr(const i_tmpl_expr&)=delete;
    i_tmpl_expr();
  public:
    i_tmpl_expr(i_tmpl_expr&&_Right);
    void operator=(i_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    typedef i_tmpl_expr_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
  class t_lev03
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev03 SelfClass;
  public:
    string oper;
    TAutoPtr<i_expr> expr;
  public:
    void DoReset();
  public:
    t_lev03(const t_lev03&)=delete;
    t_lev03();
  public:
    t_lev03(t_lev03&&_Right);
    void operator=(t_lev03&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev05
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev05 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev05 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev03 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev05 SelfClass;
  public:
    t_lev03 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev05(const t_lev05&)=delete;
    t_lev05();
  public:
    t_lev05(t_lev05&&_Right);
    void operator=(t_lev05&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev06
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev06 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev06 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev05 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev06 SelfClass;
  public:
    t_lev05 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev06(const t_lev06&)=delete;
    t_lev06();
  public:
    t_lev06(t_lev06&&_Right);
    void operator=(t_lev06&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev07
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev07 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev07 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev06 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev07 SelfClass;
  public:
    t_lev06 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev07(const t_lev07&)=delete;
    t_lev07();
  public:
    t_lev07(t_lev07&&_Right);
    void operator=(t_lev07&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev08
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev08 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev08 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev07 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev08 SelfClass;
  public:
    t_lev07 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev08(const t_lev08&)=delete;
    t_lev08();
  public:
    t_lev08(t_lev08&&_Right);
    void operator=(t_lev08&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev09
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev09 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev09 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev08 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev09 SelfClass;
  public:
    t_lev08 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev09(const t_lev09&)=delete;
    t_lev09();
  public:
    t_lev09(t_lev09&&_Right);
    void operator=(t_lev09&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev10
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev10 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev10 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev09 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev10 SelfClass;
  public:
    t_lev09 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev10(const t_lev10&)=delete;
    t_lev10();
  public:
    t_lev10(t_lev10&&_Right);
    void operator=(t_lev10&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev11
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev11 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev11 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev10 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev11 SelfClass;
  public:
    t_lev10 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev11(const t_lev11&)=delete;
    t_lev11();
  public:
    t_lev11(t_lev11&&_Right);
    void operator=(t_lev11&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev12
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev12 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev12 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev11 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev12 SelfClass;
  public:
    t_lev11 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev12(const t_lev12&)=delete;
    t_lev12();
  public:
    t_lev12(t_lev12&&_Right);
    void operator=(t_lev12&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev13
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev13 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev13 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev12 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev13 SelfClass;
  public:
    t_lev12 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev13(const t_lev13&)=delete;
    t_lev13();
  public:
    t_lev13(t_lev13&&_Right);
    void operator=(t_lev13&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_lev14
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev14 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev14 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev13 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev14 SelfClass;
  public:
    t_lev13 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev14(const t_lev14&)=delete;
    t_lev14();
  public:
    t_lev14(t_lev14&&_Right);
    void operator=(t_lev14&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_expr SelfClass;
  public:
    t_lev14 body;
  public:
    void DoReset();
  public:
    t_expr(const t_expr&)=delete;
    t_expr();
  public:
    t_expr(t_expr&&_Right);
    void operator=(t_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev03
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev03 SelfClass;
  public:
    string oper;
    TAutoPtr<i_tmpl_expr> expr;
  public:
    void DoReset();
  public:
    t_tmpl_lev03(const t_tmpl_lev03&)=delete;
    t_tmpl_lev03();
  public:
    t_tmpl_lev03(t_tmpl_lev03&&_Right);
    void operator=(t_tmpl_lev03&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev05
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev05 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev05 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev03 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev05 SelfClass;
  public:
    t_tmpl_lev03 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev05(const t_tmpl_lev05&)=delete;
    t_tmpl_lev05();
  public:
    t_tmpl_lev05(t_tmpl_lev05&&_Right);
    void operator=(t_tmpl_lev05&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev06
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev06 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev06 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev05 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev06 SelfClass;
  public:
    t_tmpl_lev05 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev06(const t_tmpl_lev06&)=delete;
    t_tmpl_lev06();
  public:
    t_tmpl_lev06(t_tmpl_lev06&&_Right);
    void operator=(t_tmpl_lev06&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev09
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev09 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev09 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev06 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev09 SelfClass;
  public:
    t_tmpl_lev06 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev09(const t_tmpl_lev09&)=delete;
    t_tmpl_lev09();
  public:
    t_tmpl_lev09(t_tmpl_lev09&&_Right);
    void operator=(t_tmpl_lev09&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev10
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev10 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev10 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev09 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev10 SelfClass;
  public:
    t_tmpl_lev09 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev10(const t_tmpl_lev10&)=delete;
    t_tmpl_lev10();
  public:
    t_tmpl_lev10(t_tmpl_lev10&&_Right);
    void operator=(t_tmpl_lev10&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev11
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev11 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev11 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev10 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev11 SelfClass;
  public:
    t_tmpl_lev10 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev11(const t_tmpl_lev11&)=delete;
    t_tmpl_lev11();
  public:
    t_tmpl_lev11(t_tmpl_lev11&&_Right);
    void operator=(t_tmpl_lev11&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev12
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev12 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev12 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev11 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev12 SelfClass;
  public:
    t_tmpl_lev11 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev12(const t_tmpl_lev12&)=delete;
    t_tmpl_lev12();
  public:
    t_tmpl_lev12(t_tmpl_lev12&&_Right);
    void operator=(t_tmpl_lev12&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev13
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev13 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev13 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev12 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev13 SelfClass;
  public:
    t_tmpl_lev12 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev13(const t_tmpl_lev13&)=delete;
    t_tmpl_lev13();
  public:
    t_tmpl_lev13(t_tmpl_lev13&&_Right);
    void operator=(t_tmpl_lev13&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_lev14
  {
  public:
    class t_oper
    {
    public:
      typedef t_tmpl_lev14 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_tmpl_lev14 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_tmpl_lev13 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_lev14 SelfClass;
  public:
    t_tmpl_lev13 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_tmpl_lev14(const t_tmpl_lev14&)=delete;
    t_tmpl_lev14();
  public:
    t_tmpl_lev14(t_tmpl_lev14&&_Right);
    void operator=(t_tmpl_lev14&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_expr SelfClass;
  public:
    t_tmpl_lev14 body;
  public:
    void DoReset();
  public:
    t_tmpl_expr(const t_tmpl_expr&)=delete;
    t_tmpl_expr();
  public:
    t_tmpl_expr(t_tmpl_expr&&_Right);
    void operator=(t_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_access_mod
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_access_mod SelfClass;
  public:
    string keyword;
  public:
    void DoReset();
  public:
    t_access_mod(const t_access_mod&)=delete;
    t_access_mod();
  public:
    t_access_mod(t_access_mod&&_Right);
    void operator=(t_access_mod&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_access_mod_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_access_mod_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_access_mod mod;
    t_sep sep;
  public:
    void DoReset();
  public:
    t_access_mod_class_stat(const t_access_mod_class_stat&)=delete;
    t_access_mod_class_stat();
  public:
    t_access_mod_class_stat(t_access_mod_class_stat&&_Right);
    void operator=(t_access_mod_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_raw_func_body
  {
  public:
    class i_item;
    class t_sep_item;
    class t_s_item;
    class t_c_item;
    class t_code_item;
    class t_div_item;
    class t_block_item;
    class i_item_visitor
    {
    public:
      typedef t_raw_func_body::i_item i_item;
    public:
      virtual void Do(t_sep_item*p)=0;
      virtual void Do(t_s_item*p)=0;
      virtual void Do(t_c_item*p)=0;
      virtual void Do(t_code_item*p)=0;
      virtual void Do(t_div_item*p)=0;
      virtual void Do(t_block_item*p)=0;
    public:
      typedef t_raw_func_body::t_sep_item t_sep_item;
      typedef t_raw_func_body::t_s_item t_s_item;
      typedef t_raw_func_body::t_c_item t_c_item;
      typedef t_raw_func_body::t_code_item t_code_item;
      typedef t_raw_func_body::t_div_item t_div_item;
      typedef t_raw_func_body::t_block_item t_block_item;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_sep_item*p)
        {
          ptr=get(p);
        } void Do(t_s_item*p)
        {
          ptr=get(p);
        } void Do(t_c_item*p)
        {
          ptr=get(p);
        } void Do(t_code_item*p)
        {
          ptr=get(p);
        } void Do(t_div_item*p)
        {
          ptr=get(p);
        } void Do(t_block_item*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_item*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_item_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
  public:
    class i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef i_item SelfClass;
    public:
      void DoReset();
    public:
      i_item(const i_item&)=delete;
      i_item();
    public:
      i_item(i_item&&_Right);
      void operator=(i_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      typedef i_item_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_sep_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_sep_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      t_sep sep;
    public:
      void DoReset();
    public:
      t_sep_item(const t_sep_item&)=delete;
      t_sep_item();
    public:
      t_sep_item(t_sep_item&&_Right);
      void operator=(t_sep_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_s_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_s_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_s_item(const t_s_item&)=delete;
      t_s_item();
    public:
      t_s_item(t_s_item&&_Right);
      void operator=(t_s_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_c_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_c_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_c_item(const t_c_item&)=delete;
      t_c_item();
    public:
      t_c_item(t_c_item&&_Right);
      void operator=(t_c_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_code_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_code_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      string code;
    public:
      void DoReset();
    public:
      t_code_item(const t_code_item&)=delete;
      t_code_item();
    public:
      t_code_item(t_code_item&&_Right);
      void operator=(t_code_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_div_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_div_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      void DoReset();
    public:
      t_div_item(const t_div_item&)=delete;
      t_div_item();
    public:
      t_div_item(t_div_item&&_Right);
      void operator=(t_div_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_block_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_block_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      TAutoPtr<t_raw_func_body> body;
    public:
      void DoReset();
    public:
      t_block_item(const t_block_item&)=delete;
      t_block_item();
    public:
      t_block_item(t_block_item&&_Right);
      void operator=(t_block_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_raw_func_body SelfClass;
  public:
    t_sep sep;
    vector<TAutoPtr<i_item>> arr;
  public:
    void DoReset();
  public:
    t_raw_func_body(const t_raw_func_body&)=delete;
    t_raw_func_body();
  public:
    t_raw_func_body(t_raw_func_body&&_Right);
    void operator=(t_raw_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_func_path
  {
  public:
    class t_item
    {
    public:
      typedef t_func_path OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      string value;
      t_sep sep0;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_func_path SelfClass;
  public:
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_func_path(const t_func_path&)=delete;
    t_func_path();
  public:
    t_func_path(t_func_path&&_Right);
    void operator=(t_func_path&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_fv_class_stat:public i_class_stat
  {
  public:
    class t_type_expr
    {
    public:
      class i_name_part;
      class t_brackets_name_part;
      class t_raw_name_part;
      class i_name_part_visitor
      {
      public:
        typedef t_type_expr::i_name_part i_name_part;
      public:
        virtual void Do(t_brackets_name_part*p)=0;
        virtual void Do(t_raw_name_part*p)=0;
      public:
        typedef t_type_expr::t_brackets_name_part t_brackets_name_part;
        typedef t_type_expr::t_raw_name_part t_raw_name_part;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_brackets_name_part*p)
          {
            ptr=get(p);
          } void Do(t_raw_name_part*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_name_part*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_name_part_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
    public:
      class i_name_part
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef i_name_part SelfClass;
      public:
        void DoReset();
      public:
        i_name_part(const i_name_part&)=delete;
        i_name_part();
      public:
        i_name_part(i_name_part&&_Right);
        void operator=(i_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        typedef i_name_part_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    public:
      class i_func_param;
      class t_pfunc_func_param;
      class t_var_args_func_param;
      class t_type_func_param;
      class t_expr_func_param;
      class i_func_param_visitor
      {
      public:
        typedef t_type_expr::i_func_param i_func_param;
      public:
        virtual void Do(t_pfunc_func_param*p)=0;
        virtual void Do(t_var_args_func_param*p)=0;
        virtual void Do(t_type_func_param*p)=0;
        virtual void Do(t_expr_func_param*p)=0;
      public:
        typedef t_type_expr::t_pfunc_func_param t_pfunc_func_param;
        typedef t_type_expr::t_var_args_func_param t_var_args_func_param;
        typedef t_type_expr::t_type_func_param t_type_func_param;
        typedef t_type_expr::t_expr_func_param t_expr_func_param;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_pfunc_func_param*p)
          {
            ptr=get(p);
          } void Do(t_var_args_func_param*p)
          {
            ptr=get(p);
          } void Do(t_type_func_param*p)
          {
            ptr=get(p);
          } void Do(t_expr_func_param*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_func_param*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_func_param_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
    public:
      class i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef i_func_param SelfClass;
      public:
        void DoReset();
      public:
        i_func_param(const i_func_param&)=delete;
        i_func_param();
      public:
        i_func_param(i_func_param&&_Right);
        void operator=(i_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        typedef i_func_param_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    public:
      class i_func_param_value;
      class t_expr_func_param_value;
      class t_ref_func_param_value;
      class i_func_param_value_visitor
      {
      public:
        typedef t_type_expr::i_func_param_value i_func_param_value;
      public:
        virtual void Do(t_expr_func_param_value*p)=0;
        virtual void Do(t_ref_func_param_value*p)=0;
      public:
        typedef t_type_expr::t_expr_func_param_value t_expr_func_param_value;
        typedef t_type_expr::t_ref_func_param_value t_ref_func_param_value;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_expr_func_param_value*p)
          {
            ptr=get(p);
          } void Do(t_ref_func_param_value*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_func_param_value*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_func_param_value_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
    public:
      class i_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef i_func_param_value SelfClass;
      public:
        void DoReset();
      public:
        i_func_param_value(const i_func_param_value&)=delete;
        i_func_param_value();
      public:
        i_func_param_value(i_func_param_value&&_Right);
        void operator=(i_func_param_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        typedef i_func_param_value_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
      class t_first_scope
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_first_scope SelfClass;
      public:
        string body;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_first_scope(const t_first_scope&)=delete;
        t_first_scope();
      public:
        t_first_scope(t_first_scope&&_Right);
        void operator=(t_first_scope&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_const_with_sep
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_const_with_sep SelfClass;
      public:
        t_sep sep;
        string keyword;
      public:
        void DoReset();
      public:
        t_const_with_sep(const t_const_with_sep&)=delete;
        t_const_with_sep();
      public:
        t_const_with_sep(t_const_with_sep&&_Right);
        void operator=(t_const_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_type_with_sep
      {
      public:
        class i_param;
        class t_type_param;
        class t_num_param;
        class i_param_visitor
        {
        public:
          typedef t_type_with_sep::i_param i_param;
        public:
          virtual void Do(t_type_param*p)=0;
          virtual void Do(t_num_param*p)=0;
        public:
          typedef t_type_with_sep::t_type_param t_type_param;
          typedef t_type_with_sep::t_num_param t_num_param;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_type_param*p)
            {
              ptr=get(p);
            } void Do(t_num_param*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_param*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_param_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
      public:
        class i_param
        {
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef i_param SelfClass;
        public:
          void DoReset();
        public:
          i_param(const i_param&)=delete;
          i_param();
        public:
          i_param(i_param&&_Right);
          void operator=(i_param&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          typedef i_param_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_type_param:public i_param
        {
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef t_type_param SelfClass;
        public:
          typedef i_param ParentClass;
        public:
          vector<t_const_with_sep> cvs;
          TAutoPtr<t_type_expr> body;
        public:
          void DoReset();
        public:
          t_type_param(const t_type_param&)=delete;
          t_type_param();
        public:
          t_type_param(t_type_param&&_Right);
          void operator=(t_type_param&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_num_param:public i_param
        {
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef t_num_param SelfClass;
        public:
          typedef i_param ParentClass;
        public:
          string body;
        public:
          void DoReset();
        public:
          t_num_param(const t_num_param&)=delete;
          t_num_param();
        public:
          t_num_param(t_num_param&&_Right);
          void operator=(t_num_param&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_params
        {
        public:
          class t_type_expr_with_sep
          {
          public:
            typedef t_params OwnerClass;
          public:
            typedef t_type_expr_with_sep SelfClass;
          public:
            t_sep sep_bef;
            TAutoPtr<i_param> param;
            t_sep sep_aft;
          public:
            void DoReset();
          public:
            t_type_expr_with_sep(const t_type_expr_with_sep&)=delete;
            t_type_expr_with_sep();
          public:
            t_type_expr_with_sep(t_type_expr_with_sep&&_Right);
            void operator=(t_type_expr_with_sep&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnvRTTI&RTTI);
              static string GetFullName();
            };
          public:
            bool go(i_dev&dev);
          };
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef t_params SelfClass;
        public:
          t_sep sep;
          vector<t_type_expr_with_sep> arr;
        public:
          void DoReset();
        public:
          t_params(const t_params&)=delete;
          t_params();
        public:
          t_params(t_params&&_Right);
          void operator=(t_params&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          bool go(i_dev&dev);
        };
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_type_with_sep SelfClass;
      public:
        t_sep sep;
        string name;
        TAutoPtr<t_params> params;
      public:
        void DoReset();
      public:
        t_type_with_sep(const t_type_with_sep&)=delete;
        t_type_with_sep();
      public:
        t_type_with_sep(t_type_with_sep&&_Right);
        void operator=(t_type_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      public:
      };
      class t_scope_with_sep
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_scope_with_sep SelfClass;
      public:
        t_sep sep;
      public:
        void DoReset();
      public:
        t_scope_with_sep(const t_scope_with_sep&)=delete;
        t_scope_with_sep();
      public:
        t_scope_with_sep(t_scope_with_sep&&_Right);
        void operator=(t_scope_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_scope
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_scope SelfClass;
      public:
        void DoReset();
      public:
        t_scope(const t_scope&)=delete;
        t_scope();
      public:
        t_scope(t_scope&&_Right);
        void operator=(t_scope&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_ptr
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_ptr SelfClass;
      public:
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_ptr(const t_ptr&)=delete;
        t_ptr();
      public:
        t_ptr(t_ptr&&_Right);
        void operator=(t_ptr&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_ref
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_ref SelfClass;
      public:
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep;
        string ref;
      public:
        void DoReset();
      public:
        t_ref(const t_ref&)=delete;
        t_ref();
      public:
        t_ref(t_ref&&_Right);
        void operator=(t_ref&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_scopes
      {
      public:
        class t_item
        {
        public:
          typedef t_scopes OwnerClass;
        public:
          typedef t_item SelfClass;
        public:
          t_scope_with_sep sws;
          t_type_with_sep body;
        public:
          void DoReset();
        public:
          t_item(const t_item&)=delete;
          t_item();
        public:
          t_item(t_item&&_Right);
          void operator=(t_item&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          bool go(i_dev&dev);
        };
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_scopes SelfClass;
      public:
        t_type_with_sep first;
        vector<t_item> arr;
      public:
        void DoReset();
      public:
        t_scopes(const t_scopes&)=delete;
        t_scopes();
      public:
        t_scopes(t_scopes&&_Right);
        void operator=(t_scopes&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_keyword
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_keyword SelfClass;
      public:
        string keyword;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_keyword(const t_keyword&)=delete;
        t_keyword();
      public:
        t_keyword(t_keyword&&_Right);
        void operator=(t_keyword&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_type_expr_with_sep_and_cv
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_type_expr_with_sep_and_cv SelfClass;
      public:
        vector<t_const_with_sep> cvs;
        TAutoPtr<t_type_expr> body;
      public:
        void DoReset();
      public:
        t_type_expr_with_sep_and_cv(const t_type_expr_with_sep_and_cv&)=delete;
        t_type_expr_with_sep_and_cv();
      public:
        t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right);
        void operator=(t_type_expr_with_sep_and_cv&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_name_part
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_name_part SelfClass;
      public:
        TAutoPtr<i_name_part> body;
      public:
        void DoReset();
      public:
        t_name_part(const t_name_part&)=delete;
        t_name_part();
      public:
        t_name_part(t_name_part&&_Right);
        void operator=(t_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_arr_body
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_arr_body SelfClass;
      public:
        t_sep sep0;
        t_sep sep1;
        t_expr expr;
        t_sep sep2;
        t_sep sep3;
      public:
        void DoReset();
      public:
        t_arr_body(const t_arr_body&)=delete;
        t_arr_body();
      public:
        t_arr_body(t_arr_body&&_Right);
        void operator=(t_arr_body&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_brackets_name_part:public i_name_part
      {
      public:
        class i_part;
        class t_amp_part;
        class t_star_part;
        class i_part_visitor
        {
        public:
          typedef t_brackets_name_part::i_part i_part;
        public:
          virtual void Do(t_amp_part*p)=0;
          virtual void Do(t_star_part*p)=0;
        public:
          typedef t_brackets_name_part::t_amp_part t_amp_part;
          typedef t_brackets_name_part::t_star_part t_star_part;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_amp_part*p)
            {
              ptr=get(p);
            } void Do(t_star_part*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_part*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_part_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
      public:
        class i_part
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef i_part SelfClass;
        public:
          void DoReset();
        public:
          i_part(const i_part&)=delete;
          i_part();
        public:
          i_part(i_part&&_Right);
          void operator=(i_part&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          typedef i_part_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_amp
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef t_amp SelfClass;
        public:
          string body;
        public:
          void DoReset();
        public:
          t_amp(const t_amp&)=delete;
          t_amp();
        public:
          t_amp(t_amp&&_Right);
          void operator=(t_amp&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          bool go(i_dev&dev);
        };
        class t_amp_part:public i_part
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef t_amp_part SelfClass;
        public:
          typedef i_part ParentClass;
        public:
          t_amp body;
        public:
          void DoReset();
        public:
          t_amp_part(const t_amp_part&)=delete;
          t_amp_part();
        public:
          t_amp_part(t_amp_part&&_Right);
          void operator=(t_amp_part&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_star_part:public i_part
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef t_star_part SelfClass;
        public:
          typedef i_part ParentClass;
        public:
          string stars;
          TAutoPtr<t_amp> amp;
        public:
          void DoReset();
        public:
          t_star_part(const t_star_part&)=delete;
          t_star_part();
        public:
          t_star_part(t_star_part&&_Right);
          void operator=(t_star_part&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_brackets_name_part SelfClass;
      public:
        typedef i_name_part ParentClass;
      public:
        TAutoPtr<i_part> stamp_part;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
        TAutoPtr<t_arr_body> arrbody;
      public:
        void DoReset();
      public:
        t_brackets_name_part(const t_brackets_name_part&)=delete;
        t_brackets_name_part();
      public:
        t_brackets_name_part(t_brackets_name_part&&_Right);
        void operator=(t_brackets_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      public:
      };
      class t_raw_name_part:public i_name_part
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_raw_name_part SelfClass;
      public:
        typedef i_name_part ParentClass;
      public:
        string name;
      public:
        void DoReset();
      public:
        t_raw_name_part(const t_raw_name_part&)=delete;
        t_raw_name_part();
      public:
        t_raw_name_part(t_raw_name_part&&_Right);
        void operator=(t_raw_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_pfunc_func_param:public i_func_param
      {
      public:
        class t_addr
        {
        public:
          typedef t_pfunc_func_param OwnerClass;
        public:
          typedef t_addr SelfClass;
        public:
          t_type_expr_with_sep_and_cv type;
        public:
          void DoReset();
        public:
          t_addr(const t_addr&)=delete;
          t_addr();
        public:
          t_addr(t_addr&&_Right);
          void operator=(t_addr&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          bool go(i_dev&dev);
        };
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_pfunc_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        t_type_expr_with_sep_and_cv type;
        t_addr addr;
        string name;
      public:
        void DoReset();
      public:
        t_pfunc_func_param(const t_pfunc_func_param&)=delete;
        t_pfunc_func_param();
      public:
        t_pfunc_func_param(t_pfunc_func_param&&_Right);
        void operator=(t_pfunc_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_var_args_func_param:public i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_var_args_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        void DoReset();
      public:
        t_var_args_func_param(const t_var_args_func_param&)=delete;
        t_var_args_func_param();
      public:
        t_var_args_func_param(t_var_args_func_param&&_Right);
        void operator=(t_var_args_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_type_func_param:public i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_type_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        t_type_expr_with_sep_and_cv type;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
      public:
        void DoReset();
      public:
        t_type_func_param(const t_type_func_param&)=delete;
        t_type_func_param();
      public:
        t_type_func_param(t_type_func_param&&_Right);
        void operator=(t_type_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_expr_func_param:public i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_expr_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        t_expr body;
      public:
        void DoReset();
      public:
        t_expr_func_param(const t_expr_func_param&)=delete;
        t_expr_func_param();
      public:
        t_expr_func_param(t_expr_func_param&&_Right);
        void operator=(t_expr_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_expr_func_param_value:public i_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_expr_func_param_value SelfClass;
      public:
        typedef i_func_param_value ParentClass;
      public:
        t_expr body;
      public:
        void DoReset();
      public:
        t_expr_func_param_value(const t_expr_func_param_value&)=delete;
        t_expr_func_param_value();
      public:
        t_expr_func_param_value(t_expr_func_param_value&&_Right);
        void operator=(t_expr_func_param_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_ref_func_param_value:public i_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_ref_func_param_value SelfClass;
      public:
        typedef i_func_param_value ParentClass;
      public:
        t_sep sep;
        t_type_expr_with_sep_and_cv type;
      public:
        void DoReset();
      public:
        t_ref_func_param_value(const t_ref_func_param_value&)=delete;
        t_ref_func_param_value();
      public:
        t_ref_func_param_value(t_ref_func_param_value&&_Right);
        void operator=(t_ref_func_param_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_param_value SelfClass;
      public:
        t_sep sep;
        TAutoPtr<i_func_param_value> value;
      public:
        void DoReset();
      public:
        t_func_param_value(const t_func_param_value&)=delete;
        t_func_param_value();
      public:
        t_func_param_value(t_func_param_value&&_Right);
        void operator=(t_func_param_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_param SelfClass;
      public:
        t_sep sep0;
        TAutoPtr<i_func_param> body;
        t_sep sep1;
        TAutoPtr<t_func_param_value> value;
        t_sep sep2;
      public:
        void DoReset();
      public:
        t_func_param(const t_func_param&)=delete;
        t_func_param();
      public:
        t_func_param(t_func_param&&_Right);
        void operator=(t_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_func_params
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_params SelfClass;
      public:
        t_sep sep;
        vector<t_func_param> arr;
      public:
        void DoReset();
      public:
        t_func_params(const t_func_params&)=delete;
        t_func_params();
      public:
        t_func_params(t_func_params&&_Right);
        void operator=(t_func_params&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_fv_stat
      {
      public:
        class i_fv_body;
        class t_impl_func_body;
        class t_zero_func_body;
        class t_delete_func_body;
        class i_fv_body_visitor
        {
        public:
          typedef t_fv_stat::i_fv_body i_fv_body;
        public:
          virtual void Do(t_impl_func_body*p)=0;
          virtual void Do(t_zero_func_body*p)=0;
          virtual void Do(t_delete_func_body*p)=0;
        public:
          typedef t_fv_stat::t_impl_func_body t_impl_func_body;
          typedef t_fv_stat::t_zero_func_body t_zero_func_body;
          typedef t_fv_stat::t_delete_func_body t_delete_func_body;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_impl_func_body*p)
            {
              ptr=get(p);
            } void Do(t_zero_func_body*p)
            {
              ptr=get(p);
            } void Do(t_delete_func_body*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_body*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_fv_body_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
      public:
        class i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef i_fv_body SelfClass;
        public:
          void DoReset();
        public:
          i_fv_body(const i_fv_body&)=delete;
          i_fv_body();
        public:
          i_fv_body(i_fv_body&&_Right);
          void operator=(i_fv_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          typedef i_fv_body_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
      public:
        class i_fv_end;
        class t_func_fv_end;
        class t_var_fv_end;
        class i_fv_end_visitor
        {
        public:
          typedef t_fv_stat::i_fv_end i_fv_end;
        public:
          virtual void Do(t_func_fv_end*p)=0;
          virtual void Do(t_var_fv_end*p)=0;
        public:
          typedef t_fv_stat::t_func_fv_end t_func_fv_end;
          typedef t_fv_stat::t_var_fv_end t_var_fv_end;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_func_fv_end*p)
            {
              ptr=get(p);
            } void Do(t_var_fv_end*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_end*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_fv_end_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
      public:
        class i_fv_end
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef i_fv_end SelfClass;
        public:
          void DoReset();
        public:
          i_fv_end(const i_fv_end&)=delete;
          i_fv_end();
        public:
          i_fv_end(i_fv_end&&_Right);
          void operator=(i_fv_end&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          typedef i_fv_end_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_impl_func_body:public i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_impl_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
        public:
          t_sep sep;
          t_raw_func_body body;
        public:
          void DoReset();
        public:
          t_impl_func_body(const t_impl_func_body&)=delete;
          t_impl_func_body();
        public:
          t_impl_func_body(t_impl_func_body&&_Right);
          void operator=(t_impl_func_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_zero_func_body:public i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_zero_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
        public:
          void DoReset();
        public:
          t_zero_func_body(const t_zero_func_body&)=delete;
          t_zero_func_body();
        public:
          t_zero_func_body(t_zero_func_body&&_Right);
          void operator=(t_zero_func_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_delete_func_body:public i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_delete_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
        public:
          void DoReset();
        public:
          t_delete_func_body(const t_delete_func_body&)=delete;
          t_delete_func_body();
        public:
          t_delete_func_body(t_delete_func_body&&_Right);
          void operator=(t_delete_func_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_func_fv_end:public i_fv_end
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_func_fv_end SelfClass;
        public:
          typedef i_fv_end ParentClass;
        public:
          TAutoPtr<t_func_params> params;
          TAutoPtr<t_const_with_sep> cv1;
          t_sep sep1;
          TAutoPtr<i_fv_body> body;
        public:
          void DoReset();
        public:
          t_func_fv_end(const t_func_fv_end&)=delete;
          t_func_fv_end();
        public:
          t_func_fv_end(t_func_fv_end&&_Right);
          void operator=(t_func_fv_end&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_var_fv_end:public i_fv_end
        {
        public:
          class i_fv_item;
          class t_func_fv_item;
          class t_var_fv_item;
          class i_fv_item_visitor
          {
          public:
            typedef t_var_fv_end::i_fv_item i_fv_item;
          public:
            virtual void Do(t_func_fv_item*p)=0;
            virtual void Do(t_var_fv_item*p)=0;
          public:
            typedef t_var_fv_end::t_func_fv_item t_func_fv_item;
            typedef t_var_fv_end::t_var_fv_item t_var_fv_item;
          public:
            template<class TYPE,class Visitor>
            struct Is:public Visitor
            {
              TYPE*ptr;
              Is():ptr(nullptr) {}
public:
              template<class U>static TYPE*get(U*p)
              {
                return nullptr;
              }
              template<>static TYPE*get<TYPE>(TYPE*p)
              {
                return p;
              }
public:
              void Do(t_func_fv_item*p)
              {
                ptr=get(p);
              } void Do(t_var_fv_item*p)
              {
                ptr=get(p);
              }
            };
            template<class TYPE>
            static TYPE*UberCast(i_fv_item*p)
            {
              if (!p)return nullptr;
              Is<TYPE,i_fv_item_visitor> IS;
              p->Use(IS);
              return IS.ptr;
            }
          };
        public:
          class i_fv_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef i_fv_item SelfClass;
          public:
            void DoReset();
          public:
            i_fv_item(const i_fv_item&)=delete;
            i_fv_item();
          public:
            i_fv_item(i_fv_item&&_Right);
            void operator=(i_fv_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnvRTTI&RTTI);
              static string GetFullName();
            };
          public:
            typedef i_fv_item_visitor i_visitor;
            virtual void Use(i_visitor&A);
          public:
            virtual bool go(i_dev&dev);
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              bool load();
              static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
              static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
            };
          };
          class t_func_fv_item:public i_fv_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_func_fv_item SelfClass;
          public:
            typedef i_fv_item ParentClass;
          public:
            TAutoPtr<t_func_params> params;
            TAutoPtr<t_const_with_sep> cv1;
          public:
            void DoReset();
          public:
            t_func_fv_item(const t_func_fv_item&)=delete;
            t_func_fv_item();
          public:
            t_func_fv_item(t_func_fv_item&&_Right);
            void operator=(t_func_fv_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnvRTTI&RTTI);
              static string GetFullName();
            };
          public:
            void Use(i_visitor&A);
            static SelfClass*UberCast(ParentClass*ptr);
          public:
            bool go(i_dev&dev);
          };
          class t_var_fv_item:public i_fv_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_var_fv_item SelfClass;
          public:
            typedef i_fv_item ParentClass;
          public:
            TAutoPtr<t_arr_body> arrbody;
            TAutoPtr<t_func_param_value> value;
          public:
            void DoReset();
          public:
            t_var_fv_item(const t_var_fv_item&)=delete;
            t_var_fv_item();
          public:
            t_var_fv_item(t_var_fv_item&&_Right);
            void operator=(t_var_fv_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnvRTTI&RTTI);
              static string GetFullName();
            };
          public:
            void Use(i_visitor&A);
            static SelfClass*UberCast(ParentClass*ptr);
          public:
            bool go(i_dev&dev);
          };
          class t_body
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_body SelfClass;
          public:
            TAutoPtr<i_fv_item> body;
          public:
            void DoReset();
          public:
            t_body(const t_body&)=delete;
            t_body();
          public:
            t_body(t_body&&_Right);
            void operator=(t_body&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnvRTTI&RTTI);
              static string GetFullName();
            };
          public:
            bool go(i_dev&dev);
          };
          class t_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_item SelfClass;
          public:
            t_sep sep0;
            TAutoPtr<t_const_with_sep> cv;
            t_sep sep1;
            string name;
            t_sep sep2;
            t_body body;
            t_sep sep3;
          public:
            void DoReset();
          public:
            t_item(const t_item&)=delete;
            t_item();
          public:
            t_item(t_item&&_Right);
            void operator=(t_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnvRTTI&RTTI);
              static string GetFullName();
            };
          public:
            bool go(i_dev&dev);
          };
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_var_fv_end SelfClass;
        public:
          typedef i_fv_end ParentClass;
        public:
          TAutoPtr<t_body> body;
          vector<t_item> arr;
        public:
          void DoReset();
        public:
          t_var_fv_end(const t_var_fv_end&)=delete;
          t_var_fv_end();
        public:
          t_var_fv_end(t_var_fv_end&&_Right);
          void operator=(t_var_fv_end&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnvRTTI&RTTI);
            static string GetFullName();
          };
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        public:
        };
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_fv_stat SelfClass;
      public:
        t_sep sep_wa;
        vector<t_keyword> keywords;
        TAutoPtr<t_type_expr> type;
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep0;
        TAutoPtr<t_func_path> path;
        t_name_part name;
        t_sep sep1;
        TAutoPtr<i_fv_end> way;
      public:
        void DoReset();
      public:
        t_fv_stat(const t_fv_stat&)=delete;
        t_fv_stat();
      public:
        t_fv_stat(t_fv_stat&&_Right);
        void operator=(t_fv_stat&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      public:
      };
    public:
      typedef t_fv_class_stat OwnerClass;
    public:
      typedef t_type_expr SelfClass;
    public:
      TAutoPtr<t_first_scope> first;
      t_scopes scopes;
      vector<t_ptr> ptrs;
      TAutoPtr<t_ref> ref;
    public:
      void DoReset();
    public:
      t_type_expr(const t_type_expr&)=delete;
      t_type_expr();
    public:
      t_type_expr(t_type_expr&&_Right);
      void operator=(t_type_expr&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    public:
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_fv_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_type_expr::t_fv_stat body;
  public:
    void DoReset();
  public:
    t_fv_class_stat(const t_fv_class_stat&)=delete;
    t_fv_class_stat();
  public:
    t_fv_class_stat(t_fv_class_stat&&_Right);
    void operator=(t_fv_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_typedef_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_typedef_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep;
    t_fv_class_stat::t_type_expr::t_fv_stat body;
  public:
    void DoReset();
  public:
    t_typedef_class_stat(const t_typedef_class_stat&)=delete;
    t_typedef_class_stat();
  public:
    t_typedef_class_stat(t_typedef_class_stat&&_Right);
    void operator=(t_typedef_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_real
  {
  public:
    class t_f
    {
    public:
      typedef t_real OwnerClass;
    public:
      typedef t_f SelfClass;
    public:
      char body;
    public:
      void DoReset();
    public:
      t_f(const t_f&)=delete;
      t_f();
    public:
      t_f(t_f&&_Right);
      void operator=(t_f&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_real SelfClass;
  public:
    string bef;
    string aft;
    TAutoPtr<t_f> ext;
  public:
    void DoReset();
  public:
    t_real(const t_real&)=delete;
    t_real();
  public:
    t_real(t_real&&_Right);
    void operator=(t_real&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_call_param
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_call_param SelfClass;
  public:
    t_sep sep0;
    t_expr expr;
    t_sep sep1;
  public:
    void DoReset();
  public:
    t_call_param(const t_call_param&)=delete;
    t_call_param();
  public:
    t_call_param(t_call_param&&_Right);
    void operator=(t_call_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_call_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_call_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string func;
    t_sep sep;
    vector<t_call_param> arr;
  public:
    void DoReset();
  public:
    t_call_expr(const t_call_expr&)=delete;
    t_call_expr();
  public:
    t_call_expr(t_call_expr&&_Right);
    void operator=(t_call_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_block_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_block_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    t_sep sep0;
    t_expr expr;
    t_sep sep1;
  public:
    void DoReset();
  public:
    t_block_expr(const t_block_expr&)=delete;
    t_block_expr();
  public:
    t_block_expr(t_block_expr&&_Right);
    void operator=(t_block_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_bool_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_bool_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_bool_expr(const t_bool_expr&)=delete;
    t_bool_expr();
  public:
    t_bool_expr(t_bool_expr&&_Right);
    void operator=(t_bool_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_string_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_string_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_string_expr(const t_string_expr&)=delete;
    t_string_expr();
  public:
    t_string_expr(t_string_expr&&_Right);
    void operator=(t_string_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_char_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_char_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_char_expr(const t_char_expr&)=delete;
    t_char_expr();
  public:
    t_char_expr(t_char_expr&&_Right);
    void operator=(t_char_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_num_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_num_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_num_expr(const t_num_expr&)=delete;
    t_num_expr();
  public:
    t_num_expr(t_num_expr&&_Right);
    void operator=(t_num_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_real_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_real_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_real_expr(const t_real_expr&)=delete;
    t_real_expr();
  public:
    t_real_expr(t_real_expr&&_Right);
    void operator=(t_real_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_nullptr_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_nullptr_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    void DoReset();
  public:
    t_nullptr_expr(const t_nullptr_expr&)=delete;
    t_nullptr_expr();
  public:
    t_nullptr_expr(t_nullptr_expr&&_Right);
    void operator=(t_nullptr_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_or_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_or_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    vector<t_name> arr;
  public:
    void DoReset();
  public:
    t_or_expr(const t_or_expr&)=delete;
    t_or_expr();
  public:
    t_or_expr(t_or_expr&&_Right);
    void operator=(t_or_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_hex_expr:public i_expr
  {
  public:
    class t_impl
    {
    public:
      typedef t_hex_expr OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      char x;
      string value;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_hex_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_hex_expr(const t_hex_expr&)=delete;
    t_hex_expr();
  public:
    t_hex_expr(t_hex_expr&&_Right);
    void operator=(t_hex_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_var_expr:public i_expr
  {
  public:
    class t_item
    {
    public:
      typedef t_var_expr OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_fv_class_stat::t_type_expr::t_type_with_sep body;
      t_sep sep;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_field
    {
    public:
      typedef t_var_expr OwnerClass;
    public:
      typedef t_field SelfClass;
    public:
      t_sep bef;
      string name;
      t_sep aft;
    public:
      void DoReset();
    public:
      t_field(const t_field&)=delete;
      t_field();
    public:
      t_field(t_field&&_Right);
      void operator=(t_field&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_impl
    {
    public:
      typedef t_var_expr OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      vector<t_item> items;
      t_sep sep;
      vector<t_field> arr;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_var_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string name;
  public:
    void DoReset();
  public:
    t_var_expr(const t_var_expr&)=delete;
    t_var_expr();
  public:
    t_var_expr(t_var_expr&&_Right);
    void operator=(t_var_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_ctor_init_list
  {
  public:
    class t_init_param
    {
    public:
      typedef t_ctor_init_list OwnerClass;
    public:
      typedef t_init_param SelfClass;
    public:
      t_sep sep0;
      string name;
      vector<t_call_param> arr;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_init_param(const t_init_param&)=delete;
      t_init_param();
    public:
      t_init_param(t_init_param&&_Right);
      void operator=(t_init_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_ctor_init_list SelfClass;
  public:
    vector<t_init_param> params;
    t_sep sep;
  public:
    void DoReset();
  public:
    t_ctor_init_list(const t_ctor_init_list&)=delete;
    t_ctor_init_list();
  public:
    t_ctor_init_list(t_ctor_init_list&&_Right);
    void operator=(t_ctor_init_list&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_zero_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_zero_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
    void DoReset();
  public:
    t_zero_func_body(const t_zero_func_body&)=delete;
    t_zero_func_body();
  public:
    t_zero_func_body(t_zero_func_body&&_Right);
    void operator=(t_zero_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_null_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_null_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
    t_sep sep;
  public:
    void DoReset();
  public:
    t_null_func_body(const t_null_func_body&)=delete;
    t_null_func_body();
  public:
    t_null_func_body(t_null_func_body&&_Right);
    void operator=(t_null_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_delete_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_delete_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
    void DoReset();
  public:
    t_delete_func_body(const t_delete_func_body&)=delete;
    t_delete_func_body();
  public:
    t_delete_func_body(t_delete_func_body&&_Right);
    void operator=(t_delete_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_impl_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_impl_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
    t_sep sep;
    TAutoPtr<t_ctor_init_list> init_list;
    t_raw_func_body body;
  public:
    void DoReset();
  public:
    t_impl_func_body(const t_impl_func_body&)=delete;
    t_impl_func_body();
  public:
    t_impl_func_body(t_impl_func_body&&_Right);
    void operator=(t_impl_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_dtor_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_dtor_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep0;
    TAutoPtr<t_func_path> path;
    string name;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<i_func_body> body;
  public:
    void DoReset();
  public:
    t_dtor_class_stat(const t_dtor_class_stat&)=delete;
    t_dtor_class_stat();
  public:
    t_dtor_class_stat(t_dtor_class_stat&&_Right);
    void operator=(t_dtor_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_ctor_class_stat:public i_class_stat
  {
  public:
    class t_impl
    {
    public:
      class t_explicit
      {
      public:
        typedef t_impl OwnerClass;
      public:
        typedef t_explicit SelfClass;
      public:
        t_sep sep;
      public:
        void DoReset();
      public:
        t_explicit(const t_explicit&)=delete;
        t_explicit();
      public:
        t_explicit(t_explicit&&_Right);
        void operator=(t_explicit&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
    public:
      typedef t_ctor_class_stat OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      TAutoPtr<t_explicit> prefix;
      TAutoPtr<t_func_path> path;
      string name;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<i_func_body> body;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_ctor_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_impl body;
  public:
    void DoReset();
  public:
    t_ctor_class_stat(const t_ctor_class_stat&)=delete;
    t_ctor_class_stat();
  public:
    t_ctor_class_stat(t_ctor_class_stat&&_Right);
    void operator=(t_ctor_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_oper_cast_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_oper_cast_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    TAutoPtr<t_func_path> path;
    t_sep sep0;
    t_fv_class_stat::t_type_expr type;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv;
    TAutoPtr<i_func_body> body;
  public:
    void DoReset();
  public:
    t_oper_cast_class_stat(const t_oper_cast_class_stat&)=delete;
    t_oper_cast_class_stat();
  public:
    t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right);
    void operator=(t_oper_cast_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_common_oper_class_stat:public i_class_stat
  {
  public:
    class t_impl
    {
    public:
      typedef t_common_oper_class_stat OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      vector<t_fv_class_stat::t_type_expr::t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv0;
      t_sep sep0;
      TAutoPtr<t_func_path> path;
      t_sep sep1;
      string oper;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_common_oper_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_impl body;
  public:
    void DoReset();
  public:
    t_common_oper_class_stat(const t_common_oper_class_stat&)=delete;
    t_common_oper_class_stat();
  public:
    t_common_oper_class_stat(t_common_oper_class_stat&&_Right);
    void operator=(t_common_oper_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_parents
  {
  public:
    class t_item
    {
    public:
      class t_pub
      {
      public:
        typedef t_item OwnerClass;
      public:
        typedef t_pub SelfClass;
      public:
        t_access_mod mod;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_pub(const t_pub&)=delete;
        t_pub();
      public:
        t_pub(t_pub&&_Right);
        void operator=(t_pub&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
    public:
      typedef t_parents OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_sep sep;
      TAutoPtr<t_pub> pub;
      string name;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_parents SelfClass;
  public:
    t_sep sep;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_parents(const t_parents&)=delete;
    t_parents();
  public:
    t_parents(t_parents&&_Right);
    void operator=(t_parents&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_class_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_class_body SelfClass;
  public:
    vector<TAutoPtr<i_class_stat>> arr;
  public:
    void DoReset();
  public:
    t_class_body(const t_class_body&)=delete;
    t_class_body();
  public:
    t_class_body(t_class_body&&_Right);
    void operator=(t_class_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_class
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_class SelfClass;
  public:
    string keyword;
    t_sep sep0;
    string name;
    t_sep sep1;
    TAutoPtr<t_parents> parents;
    t_sep sep2;
    TAutoPtr<t_class_body> body;
    t_sep sep3;
  public:
    void DoReset();
  public:
    t_class(const t_class&)=delete;
    t_class();
  public:
    t_class(t_class&&_Right);
    void operator=(t_class&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_namespace_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_namespace_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep0;
    string name;
    t_sep sep1;
    t_class_body body;
  public:
    void DoReset();
  public:
    t_namespace_class_stat(const t_namespace_class_stat&)=delete;
    t_namespace_class_stat();
  public:
    t_namespace_class_stat(t_namespace_class_stat&&_Right);
    void operator=(t_namespace_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_template_class_stat:public i_class_stat
  {
  public:
    class i_template_body;
    class t_common_oper_template_body;
    class t_ctor_template_body;
    class t_func_template_body;
    class class_template_body;
    class i_template_body_visitor
    {
    public:
      typedef t_template_class_stat::i_template_body i_template_body;
    public:
      virtual void Do(t_common_oper_template_body*p)=0;
      virtual void Do(t_ctor_template_body*p)=0;
      virtual void Do(t_func_template_body*p)=0;
      virtual void Do(class_template_body*p)=0;
    public:
      typedef t_template_class_stat::t_common_oper_template_body t_common_oper_template_body;
      typedef t_template_class_stat::t_ctor_template_body t_ctor_template_body;
      typedef t_template_class_stat::t_func_template_body t_func_template_body;
      typedef t_template_class_stat::class_template_body class_template_body;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_common_oper_template_body*p)
        {
          ptr=get(p);
        } void Do(t_ctor_template_body*p)
        {
          ptr=get(p);
        } void Do(t_func_template_body*p)
        {
          ptr=get(p);
        } void Do(class_template_body*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_body*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_template_body_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
  public:
    class i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef i_template_body SelfClass;
    public:
      void DoReset();
    public:
      i_template_body(const i_template_body&)=delete;
      i_template_body();
    public:
      i_template_body(i_template_body&&_Right);
      void operator=(i_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      typedef i_template_body_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
  public:
    class i_template_param;
    class t_name_template_param;
    class t_type_template_param;
    class i_template_param_visitor
    {
    public:
      typedef t_template_class_stat::i_template_param i_template_param;
    public:
      virtual void Do(t_name_template_param*p)=0;
      virtual void Do(t_type_template_param*p)=0;
    public:
      typedef t_template_class_stat::t_name_template_param t_name_template_param;
      typedef t_template_class_stat::t_type_template_param t_type_template_param;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_name_template_param*p)
        {
          ptr=get(p);
        } void Do(t_type_template_param*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_param*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_template_param_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
  public:
    class i_template_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef i_template_param SelfClass;
    public:
      void DoReset();
    public:
      i_template_param(const i_template_param&)=delete;
      i_template_param();
    public:
      i_template_param(i_template_param&&_Right);
      void operator=(i_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      typedef i_template_param_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_template_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_template_param SelfClass;
    public:
      t_sep bef;
      TAutoPtr<i_template_param> body;
      t_sep aft;
    public:
      void DoReset();
    public:
      t_template_param(const t_template_param&)=delete;
      t_template_param();
    public:
      t_template_param(t_template_param&&_Right);
      void operator=(t_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_concrete_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_concrete_param SelfClass;
    public:
      t_sep sep0;
      t_tmpl_expr body;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_concrete_param(const t_concrete_param&)=delete;
      t_concrete_param();
    public:
      t_concrete_param(t_concrete_param&&_Right);
      void operator=(t_concrete_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_concrete_params
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_concrete_params SelfClass;
    public:
      vector<t_concrete_param> arr;
      t_sep sep;
    public:
      void DoReset();
    public:
      t_concrete_params(const t_concrete_params&)=delete;
      t_concrete_params();
    public:
      t_concrete_params(t_concrete_params&&_Right);
      void operator=(t_concrete_params&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_common_oper_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_common_oper_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      t_common_oper_class_stat::t_impl body;
    public:
      void DoReset();
    public:
      t_common_oper_template_body(const t_common_oper_template_body&)=delete;
      t_common_oper_template_body();
    public:
      t_common_oper_template_body(t_common_oper_template_body&&_Right);
      void operator=(t_common_oper_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_ctor_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_ctor_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      t_ctor_class_stat::t_impl body;
    public:
      void DoReset();
    public:
      t_ctor_template_body(const t_ctor_template_body&)=delete;
      t_ctor_template_body();
    public:
      t_ctor_template_body(t_ctor_template_body&&_Right);
      void operator=(t_ctor_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_func_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_func_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      vector<t_fv_class_stat::t_type_expr::t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv0;
      t_sep sep0;
      string func_name;
      TAutoPtr<t_concrete_params> concrete_params;
      t_sep sep1;
      t_fv_class_stat::t_type_expr::t_func_params params;
      t_sep sep2;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
    public:
      void DoReset();
    public:
      t_func_template_body(const t_func_template_body&)=delete;
      t_func_template_body();
    public:
      t_func_template_body(t_func_template_body&&_Right);
      void operator=(t_func_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class class_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef class_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      string keyword;
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_concrete_params> params;
      TAutoPtr<t_parents> parents;
      t_sep sep2;
      TAutoPtr<t_class_body> body;
      t_sep sep3;
    public:
      void DoReset();
    public:
      class_template_body(const class_template_body&)=delete;
      class_template_body();
    public:
      class_template_body(class_template_body&&_Right);
      void operator=(class_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_name_template_param:public i_template_param
    {
    public:
      class t_unsgnd
      {
      public:
        typedef t_name_template_param OwnerClass;
      public:
        typedef t_unsgnd SelfClass;
      public:
        t_sep sep;
      public:
        void DoReset();
      public:
        t_unsgnd(const t_unsgnd&)=delete;
        t_unsgnd();
      public:
        t_unsgnd(t_unsgnd&&_Right);
        void operator=(t_unsgnd&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
      class t_value
      {
      public:
        typedef t_name_template_param OwnerClass;
      public:
        typedef t_value SelfClass;
      public:
        t_expr body;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_value(const t_value&)=delete;
        t_value();
      public:
        t_value(t_value&&_Right);
        void operator=(t_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_name_template_param SelfClass;
    public:
      typedef i_template_param ParentClass;
    public:
      string unsgnd0;
      t_sep sep0;
      string type;
      t_sep sep1;
      string unsgnd1;
      t_sep sep2;
      string name;
      t_sep sep3;
      TAutoPtr<t_value> value;
    public:
      void DoReset();
    public:
      t_name_template_param(const t_name_template_param&)=delete;
      t_name_template_param();
    public:
      t_name_template_param(t_name_template_param&&_Right);
      void operator=(t_name_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_head
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_head SelfClass;
    public:
      t_sep sep0;
      vector<t_template_param> params;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_head(const t_head&)=delete;
      t_head();
    public:
      t_head(t_head&&_Right);
      void operator=(t_head&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_type_template_param:public i_template_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_type_template_param SelfClass;
    public:
      typedef i_template_param ParentClass;
    public:
      TAutoPtr<t_head> head;
      string type;
      t_sep sep;
      string name;
    public:
      void DoReset();
    public:
      t_type_template_param(const t_type_template_param&)=delete;
      t_type_template_param();
    public:
      t_type_template_param(t_type_template_param&&_Right);
      void operator=(t_type_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_template_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_head head;
    TAutoPtr<i_template_body> body;
  public:
    void DoReset();
  public:
    t_template_class_stat(const t_template_class_stat&)=delete;
    t_template_class_stat();
  public:
    t_template_class_stat(t_template_class_stat&&_Right);
    void operator=(t_template_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_enum_class_stat:public i_class_stat
  {
  public:
    class i_body;
    class t_impl_body;
    class t_empty_body;
    class i_body_visitor
    {
    public:
      typedef t_enum_class_stat::i_body i_body;
    public:
      virtual void Do(t_impl_body*p)=0;
      virtual void Do(t_empty_body*p)=0;
    public:
      typedef t_enum_class_stat::t_impl_body t_impl_body;
      typedef t_enum_class_stat::t_empty_body t_empty_body;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_impl_body*p)
        {
          ptr=get(p);
        } void Do(t_empty_body*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_body*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_body_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
  public:
    class i_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef i_body SelfClass;
    public:
      void DoReset();
    public:
      i_body(const i_body&)=delete;
      i_body();
    public:
      i_body(i_body&&_Right);
      void operator=(i_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      typedef i_body_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_value
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_value SelfClass;
    public:
      t_sep sep0;
      t_expr expr;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_value(const t_value&)=delete;
      t_value();
    public:
      t_value(t_value&&_Right);
      void operator=(t_value&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_value> value;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_comma_with_sep
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_comma_with_sep SelfClass;
    public:
      t_sep sep;
    public:
      void DoReset();
    public:
      t_comma_with_sep(const t_comma_with_sep&)=delete;
      t_comma_with_sep();
    public:
      t_comma_with_sep(t_comma_with_sep&&_Right);
      void operator=(t_comma_with_sep&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_impl_body:public i_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_impl_body SelfClass;
    public:
      typedef i_body ParentClass;
    public:
      vector<t_item> arr;
      TAutoPtr<t_comma_with_sep> comma;
    public:
      void DoReset();
    public:
      t_impl_body(const t_impl_body&)=delete;
      t_impl_body();
    public:
      t_impl_body(t_impl_body&&_Right);
      void operator=(t_impl_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_empty_body:public i_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_empty_body SelfClass;
    public:
      typedef i_body ParentClass;
    public:
      void DoReset();
    public:
      t_empty_body(const t_empty_body&)=delete;
      t_empty_body();
    public:
      t_empty_body(t_empty_body&&_Right);
      void operator=(t_empty_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_body SelfClass;
    public:
      TAutoPtr<i_body> body;
    public:
      void DoReset();
    public:
      t_body(const t_body&)=delete;
      t_body();
    public:
      t_body(t_body&&_Right);
      void operator=(t_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_enum_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep0;
    string name;
    t_sep sep1;
    t_body body;
  public:
    void DoReset();
  public:
    t_enum_class_stat(const t_enum_class_stat&)=delete;
    t_enum_class_stat();
  public:
    t_enum_class_stat(t_enum_class_stat&&_Right);
    void operator=(t_enum_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_using_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_using_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep;
    t_fv_class_stat::t_type_expr type;
  public:
    void DoReset();
  public:
    t_using_class_stat(const t_using_class_stat&)=delete;
    t_using_class_stat();
  public:
    t_using_class_stat(t_using_class_stat&&_Right);
    void operator=(t_using_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_tmpl_call_param
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_tmpl_call_param SelfClass;
  public:
    t_sep sep0;
    t_tmpl_expr expr;
    t_sep sep1;
  public:
    void DoReset();
  public:
    t_tmpl_call_param(const t_tmpl_call_param&)=delete;
    t_tmpl_call_param();
  public:
    t_tmpl_call_param(t_tmpl_call_param&&_Right);
    void operator=(t_tmpl_call_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
  class t_call_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_call_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string func;
    t_sep sep;
    vector<t_tmpl_call_param> arr;
  public:
    void DoReset();
  public:
    t_call_tmpl_expr(const t_call_tmpl_expr&)=delete;
    t_call_tmpl_expr();
  public:
    t_call_tmpl_expr(t_call_tmpl_expr&&_Right);
    void operator=(t_call_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_block_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_block_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    t_sep sep0;
    t_tmpl_expr expr;
    t_sep sep1;
  public:
    void DoReset();
  public:
    t_block_tmpl_expr(const t_block_tmpl_expr&)=delete;
    t_block_tmpl_expr();
  public:
    t_block_tmpl_expr(t_block_tmpl_expr&&_Right);
    void operator=(t_block_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_bool_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_bool_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_bool_tmpl_expr(const t_bool_tmpl_expr&)=delete;
    t_bool_tmpl_expr();
  public:
    t_bool_tmpl_expr(t_bool_tmpl_expr&&_Right);
    void operator=(t_bool_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_string_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_string_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_string_tmpl_expr(const t_string_tmpl_expr&)=delete;
    t_string_tmpl_expr();
  public:
    t_string_tmpl_expr(t_string_tmpl_expr&&_Right);
    void operator=(t_string_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_char_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_char_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_char_tmpl_expr(const t_char_tmpl_expr&)=delete;
    t_char_tmpl_expr();
  public:
    t_char_tmpl_expr(t_char_tmpl_expr&&_Right);
    void operator=(t_char_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_num_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_num_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_num_tmpl_expr(const t_num_tmpl_expr&)=delete;
    t_num_tmpl_expr();
  public:
    t_num_tmpl_expr(t_num_tmpl_expr&&_Right);
    void operator=(t_num_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_real_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_real_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_real_tmpl_expr(const t_real_tmpl_expr&)=delete;
    t_real_tmpl_expr();
  public:
    t_real_tmpl_expr(t_real_tmpl_expr&&_Right);
    void operator=(t_real_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_nullptr_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_nullptr_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    void DoReset();
  public:
    t_nullptr_tmpl_expr(const t_nullptr_tmpl_expr&)=delete;
    t_nullptr_tmpl_expr();
  public:
    t_nullptr_tmpl_expr(t_nullptr_tmpl_expr&&_Right);
    void operator=(t_nullptr_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_or_tmpl_expr:public i_tmpl_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_or_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    vector<t_name> arr;
  public:
    void DoReset();
  public:
    t_or_tmpl_expr(const t_or_tmpl_expr&)=delete;
    t_or_tmpl_expr();
  public:
    t_or_tmpl_expr(t_or_tmpl_expr&&_Right);
    void operator=(t_or_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_hex_tmpl_expr:public i_tmpl_expr
  {
  public:
    class t_impl
    {
    public:
      typedef t_hex_tmpl_expr OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      char x;
      string value;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_hex_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_hex_tmpl_expr(const t_hex_tmpl_expr&)=delete;
    t_hex_tmpl_expr();
  public:
    t_hex_tmpl_expr(t_hex_tmpl_expr&&_Right);
    void operator=(t_hex_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_var_tmpl_expr:public i_tmpl_expr
  {
  public:
    class i_param;
    class t_param;
    class t_num_param;
    class i_param_visitor
    {
    public:
      typedef t_var_tmpl_expr::i_param i_param;
    public:
      virtual void Do(t_param*p)=0;
      virtual void Do(t_num_param*p)=0;
    public:
      typedef t_var_tmpl_expr::t_param t_param;
      typedef t_var_tmpl_expr::t_num_param t_num_param;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_param*p)
        {
          ptr=get(p);
        } void Do(t_num_param*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_param*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_param_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
  public:
    class i_param
    {
    public:
      typedef t_var_tmpl_expr OwnerClass;
    public:
      typedef i_param SelfClass;
    public:
      void DoReset();
    public:
      i_param(const i_param&)=delete;
      i_param();
    public:
      i_param(i_param&&_Right);
      void operator=(i_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      typedef i_param_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_params
    {
    public:
      class t_param_with_sep
      {
      public:
        typedef t_params OwnerClass;
      public:
        typedef t_param_with_sep SelfClass;
      public:
        t_sep sep_bef;
        TAutoPtr<i_param> param;
        t_sep sep_aft;
      public:
        void DoReset();
      public:
        t_param_with_sep(const t_param_with_sep&)=delete;
        t_param_with_sep();
      public:
        t_param_with_sep(t_param_with_sep&&_Right);
        void operator=(t_param_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnvRTTI&RTTI);
          static string GetFullName();
        };
      public:
        bool go(i_dev&dev);
      };
    public:
      typedef t_var_tmpl_expr OwnerClass;
    public:
      typedef t_params SelfClass;
    public:
      t_sep sep0;
      vector<t_param_with_sep> arr;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_params(const t_params&)=delete;
      t_params();
    public:
      t_params(t_params&&_Right);
      void operator=(t_params&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_var_tmpl_expr OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_sep sep0;
      string type;
      t_sep sep1;
      TAutoPtr<t_params> params;
      t_sep sep2;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_impl
    {
    public:
      typedef t_var_tmpl_expr OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      vector<t_item> items;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      bool go(i_dev&dev);
    };
    class t_param:public i_param
    {
    public:
      typedef t_var_tmpl_expr OwnerClass;
    public:
      typedef t_param SelfClass;
    public:
      typedef i_param ParentClass;
    public:
      vector<t_fv_class_stat::t_type_expr::t_const_with_sep> cvs;
      TAutoPtr<t_impl> body;
    public:
      void DoReset();
    public:
      t_param(const t_param&)=delete;
      t_param();
    public:
      t_param(t_param&&_Right);
      void operator=(t_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_num_param:public i_param
    {
    public:
      typedef t_var_tmpl_expr OwnerClass;
    public:
      typedef t_num_param SelfClass;
    public:
      typedef i_param ParentClass;
    public:
      string body;
    public:
      void DoReset();
    public:
      t_num_param(const t_num_param&)=delete;
      t_num_param();
    public:
      t_num_param(t_num_param&&_Right);
      void operator=(t_num_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnvRTTI&RTTI);
        static string GetFullName();
      };
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_var_tmpl_expr SelfClass;
  public:
    typedef i_tmpl_expr ParentClass;
  public:
    string name;
  public:
    void DoReset();
  public:
    t_var_tmpl_expr(const t_var_tmpl_expr&)=delete;
    t_var_tmpl_expr();
  public:
    t_var_tmpl_expr(t_var_tmpl_expr&&_Right);
    void operator=(t_var_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_pragma_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_pragma_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_pragma_class_stat(const t_pragma_class_stat&)=delete;
    t_pragma_class_stat();
  public:
    t_pragma_class_stat(t_pragma_class_stat&&_Right);
    void operator=(t_pragma_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_include_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_include_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_include_class_stat(const t_include_class_stat&)=delete;
    t_include_class_stat();
  public:
    t_include_class_stat(t_include_class_stat&&_Right);
    void operator=(t_include_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_preproc_if_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_preproc_if_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_preproc_if_class_stat(const t_preproc_if_class_stat&)=delete;
    t_preproc_if_class_stat();
  public:
    t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right);
    void operator=(t_preproc_if_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_preproc_else_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_preproc_else_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_preproc_else_class_stat(const t_preproc_else_class_stat&)=delete;
    t_preproc_else_class_stat();
  public:
    t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right);
    void operator=(t_preproc_else_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_preproc_endif_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_preproc_endif_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_preproc_endif_class_stat(const t_preproc_endif_class_stat&)=delete;
    t_preproc_endif_class_stat();
  public:
    t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right);
    void operator=(t_preproc_endif_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_define_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_define_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_define_class_stat(const t_define_class_stat&)=delete;
    t_define_class_stat();
  public:
    t_define_class_stat(t_define_class_stat&&_Right);
    void operator=(t_define_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_undef_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_undef_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_undef_class_stat(const t_undef_class_stat&)=delete;
    t_undef_class_stat();
  public:
    t_undef_class_stat(t_undef_class_stat&&_Right);
    void operator=(t_undef_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_sep_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_sep_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep;
  public:
    void DoReset();
  public:
    t_sep_class_stat(const t_sep_class_stat&)=delete;
    t_sep_class_stat();
  public:
    t_sep_class_stat(t_sep_class_stat&&_Right);
    void operator=(t_sep_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_null_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_null_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    void DoReset();
  public:
    t_null_class_stat(const t_null_class_stat&)=delete;
    t_null_class_stat();
  public:
    t_null_class_stat(t_null_class_stat&&_Right);
    void operator=(t_null_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_class_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_class_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_class body;
  public:
    void DoReset();
  public:
    t_class_class_stat(const t_class_class_stat&)=delete;
    t_class_class_stat();
  public:
    t_class_class_stat(t_class_class_stat&&_Right);
    void operator=(t_class_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_inl_file_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_inl_file_stat SelfClass;
  public:
    t_sep sep;
    TAutoPtr<t_class> body;
  public:
    void DoReset();
  public:
    t_inl_file_stat(const t_inl_file_stat&)=delete;
    t_inl_file_stat();
  public:
    t_inl_file_stat(t_inl_file_stat&&_Right);
    void operator=(t_inl_file_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
  public:
    bool go(i_dev&dev);
  };
public:
  typedef t_inl_file SelfClass;
public:
  vector<TAutoPtr<i_class_stat>> arr;
public:
  void DoReset();
public:
  t_inl_file(const t_inl_file&)=delete;
  t_inl_file();
public:
  t_inl_file(t_inl_file&&_Right);
  void operator=(t_inl_file&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    static metatype*GetRTTI(IEnvRTTI&RTTI);
    static string GetFullName();
  };
public:
  bool go(i_dev&dev);
public:
};
#pragma once
class TSimpleBinarySaver:public IVisitorRTTI{
public:
  typedef TSimpleBinarySaver SelfClass;
public:
  struct t_dev{
    QapIO&IO;
    void*pValue;
    vector<void*> stack;
    void push(){
      stack.push_back(pValue);
    }
    void pop(){
      QapAssert(!stack.empty());
      pValue=stack.back();
      stack.pop_back();
    }
  };
public:
  t_dev&dev;
  TSimpleBinarySaver(t_dev&dev):dev(dev){}
public:
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TYPE*p){
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    TDataIO IO;
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return IO.IO.mem;
  }
  static string toStrEx(TType*pType,void*pValue){
    TDataIO IO;
    SelfClass::t_dev dev={IO,pValue};
    SelfClass V(dev);
    pType->Use(V);
    return IO.IO.mem;
  }
  static void toIO(QapIO&IO,TRawPtr&ptr){
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
  }
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType){QapDebugMsg("no way");return;}
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      dev.push();
      dev.pValue=ex.getValue(dev.pValue);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSys*p)
  {
    p->BinIO->Save(dev.IO,dev.pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    auto Count=VecAPI->GetCount(dev.pValue);
    {
      dev.push();
      dev.pValue=&Count;
      p->SizeType->Use(*this);
      dev.pop();
    }
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(dev.pValue,i);
      dev.push();
      dev.pValue=ptr;
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSelfPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeWeakPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("no way");
  }
};
class TSimpleBinaryLoader:public IVisitorRTTI{
public:
  typedef TSimpleBinaryLoader SelfClass;
public:
  struct t_dev{
    QapIO&IO;
    void*pValue;
    vector<void*> stack;
    void push(){
      stack.push_back(pValue);
    }
    void pop(){
      QapAssert(!stack.empty());
      pValue=stack.back();
      stack.pop_back();
    }
  };
public:
  t_dev&dev;
  TSimpleBinaryLoader(t_dev&dev):dev(dev){}
public:
  template<class TYPE>
  static bool fromIO(IEnvRTTI&Env,TYPE*p,QapIO&IO){
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }
  static bool fromIOEx(IEnvRTTI&Env,const TRawPtr&ptr,QapIO&IO){
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
    return true;
  }
  template<class TYPE>
  static bool fromStr(IEnvRTTI&Env,TYPE*p,const string&source){
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }
  static bool fromStrEx(const string&source,TType*pType,void*pValue){
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,pValue};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }
  static bool fromStrEx(const string&source,TRawPtr&ptr){
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
    return true;
  }
  static bool fromStrEx(QapIO&IO,TRawPtr&ptr){
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
    return true;
  }
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType){QapDebugMsg("no way");return;}
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      dev.push();
      dev.pValue=ex.getValue(dev.pValue);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSys*p)
  {
    p->BinIO->Load(dev.IO,dev.pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=0;
    {
      dev.push();
      dev.pValue=&Count;
      p->SizeType->Use(*this);
      dev.pop();
    }
    VecAPI->SetCount(dev.pValue,Count);
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(dev.pValue,i);
      dev.push();
      dev.pValue=ptr;
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSelfPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeWeakPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("no way");
  }
};
template<class TYPE>
static bool qap_simple_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source)
{
  string mem=TSimpleBinarySaver::toStr(Env,&source);
  return TSimpleBinaryLoader::fromStr(Env,&dest,mem);
}
static bool qap_simple_clone_unsafe(TType*pType,void*pDest,void*pSource)
{
  string mem=TSimpleBinarySaver::toStrEx(pType,pSource);
  return TSimpleBinaryLoader::fromStrEx(mem,pType,pDest);
}
void UberInfoBox(const string&caption,const string&text);
void InfoBox(const string&text){UberInfoBox("InfoBox",text);}
class TToolLexToStr{
public:
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TAutoPtr<TYPE>&inp){
    if(!inp)return "";
    string out;
    auto ok=save_obj(Env,inp,out);
    QapAssert(ok);
    return out;
  }
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TYPE&inp){
    string out;
    auto ok=save_obj(Env,inp,out);
    QapAssert(ok);
    return out;
  }
};
struct t_some_shit_grabber_tool:public TToolLexToStr,public t_inl_file{
  IEnvRTTI&Env;
  vector<string>&out;
  t_some_shit_grabber_tool(IEnvRTTI&Env,vector<string>&out):Env(Env),out(out){}
  typedef vector<TAutoPtr<i_class_stat>> t_class_stats;
  struct t_mem{
    struct t_elem{
      t_class_stats*parr;
      string name;
    };
    vector<t_elem> stack;
    void push(t_class_stats&arr,const string&name)
    {
      auto&back=qap_add_back(stack);
      back.parr=&arr;
      back.name=name;
    }
    void pop(t_class_stats&arr,const string&name)
    {
      QapAssert(!stack.empty());
      QapAssert(&arr==stack.back().parr);
      QapAssert(name==stack.back().name);
      stack.pop_back();
    }
    string get_sub(int n)
    {
      string out;
      for(int i=0;i<std::min<int>(n,stack.size());i++){
        out+=stack[i].name+"::";
      }
      return out;
    }
  };
  t_mem mem;
  static string without_first_sep(const string&src)
  {
    string out=src;
    for(;
    )
    {
      {int pos=out.find_first_not_of('\n');if(pos>0){out=out.substr(pos);}else break;}
      {int pos=out.find_first_not_of(' ');if(pos>0){out=out.substr(pos);}else break;}
    }
    return out;
  }
  static string without_last_part(const string&text,const string&last_part){
    QapAssert(text.size()>last_part.size());
    QapAssert(text.substr(text.size()-last_part.size())==last_part);
    return text.substr(0,last_part.size());
  }
  typedef t_fv_class_stat::t_type_expr::t_keyword t_keyword;
  bool drop_keyword(vector<t_keyword>&arr,const string&kw){
    bool ok=false;
    QapCleanIf(arr,[&kw,&ok](t_keyword&ex){if(ex.keyword!=kw)return false;ok=true; return true;});
    return ok;
  }
  t_class_class_stat*find_type_in_stats_by_name(t_class_stats&arr,const string&name)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(auto*p=t_class_class_stat::UberCast(ex.get()))
      {
        if(p->body.name==name)return p;
      }
    }
    return nullptr;
  }
  typedef t_fv_class_stat::t_type_expr::t_raw_name_part t_raw_name_part;
  typedef t_fv_class_stat::t_type_expr::t_scopes t_scopes;
  t_typedef_class_stat*find_typedef_in_stats_by_name(t_class_stats&arr,const string&name)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(auto*p=t_typedef_class_stat::UberCast(ex.get()))
      {
        if(auto*prn=t_raw_name_part::UberCast(p->body.name.body.get()))
        {
          if(prn->name==name)return p;
          continue;
        }
        QapDebugMsg("no way");
      }
    }
    return nullptr;
  }
  string find_type_in_mem_by_name(const string&name)
  {
    auto&arr=mem.stack;
    for(int i=0;i<arr.size();i++)
    {
      auto id=arr.size()-i-1;
      auto&ex=arr[id];
      auto*ptype=find_type_in_stats_by_name(*ex.parr,name);
      auto*ptypedef=find_typedef_in_stats_by_name(*ex.parr,name);
      if(!ptype&&!ptypedef)continue;
      return mem.get_sub(id+1);
    }
    return "";
  }
  struct t_bot_with_t_scopes{
    t_scopes&src;
    bool used;
    t_scopes buf;
    void rollback()
    {
      if(!used)return;
      src=std::move(buf);
    }
  };
  /*struct t_tmp_obj{
    t_fv_class_stat&src;
    bool used;
    t_fv_class_stat buf;
    ~t_tmp_obj()
    {
      if(!used)return;
      src=std::move(buf);
    }
  };*/
  void foo(t_fv_class_stat&value,const string&prefix)
  {
    auto*pw=t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(value.body.way.get());
    if(!pw)return;
    typedef t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body t_impl_func_body;
    if(!t_impl_func_body::UberCast(pw->body.get()))return;
    auto*rnp=t_raw_name_part::UberCast(
      value.body.name.body.get()
    );
    if(!rnp)return;
    typedef std::remove_reference<decltype(value.body.type.get()->scopes.arr[0].body)>::type t_body;
    QapAssert(value.body.type);
    t_bot_with_t_scopes ret_type_bot={value.body.type.get()->scopes,false};
    if(!prefix.empty())for(;
    )
    {
      auto&t=*value.body.type.get();
      QapAssert(!t.first);
      auto&scopes=t.scopes;
      vector<string> out;
      auto f=[&out](t_body&b){
        QapAssert(!b.params);
        qap_add_back(out)=b.name;
      };
      f(scopes.first);
      auto&arr=scopes.arr;
      for(int i=0;i<arr.size();i++)
      {
        f(arr[i].body);
      }
      auto path=split(prefix,"::");path.pop_back();
      auto res=qap_find_str(path,out[0]);
      if(res.empty())
      {
        auto pre_path=find_type_in_mem_by_name(out[0]);
        string out_type=pre_path+join(out,"::");
        {
          ret_type_bot.buf=std::move(t.scopes);
          ret_type_bot.used=true;
          auto res=load_obj_full(Env,t.scopes,out_type);
          QapAssert(res.ok);
        }
        int gg=1;
        break;
      }
      auto subpath=qap_arr_slice(path,res.back());
      vector<string> fullpath;
      QapToolsVectorEx(fullpath)+=std::move(subpath);
      QapToolsVectorEx(fullpath)+=std::move(out);
      auto out_type=join(fullpath,"::");
      {
        ret_type_bot.buf=std::move(t.scopes);
        ret_type_bot.used=true;
        auto res=load_obj_full(Env,t.scopes,out_type);
        QapAssert(res.ok);
      }
      int gg=1;
      break;
    }
    vector<t_keyword> buff_arr; bool need_restore=false; bool friend_dropped=false; bool virtual_dropped=false;
    {
      vector<t_keyword>&arr=value.body.keywords;
      drop_keyword(arr,"inline");
      if(prefix.empty())drop_keyword(arr,"static");
      int gg=1;
      qap_simple_clone(Env,buff_arr,arr);
      static auto starr=split("explicit,static",",");
      for(int i=0;i<starr.size();i++)need_restore=need_restore||drop_keyword(arr,starr[i]);
      friend_dropped=drop_keyword(arr,"friend");
      virtual_dropped=drop_keyword(arr,"virtual");
      need_restore=need_restore||friend_dropped||virtual_dropped;
    }
    auto f=[&]()->string{
      string out;
      out+=toStr(Env,value.body.keywords);
      out+=toStr(Env,value.body.type);
      out+=toStr(Env,value.body.cv);
      out+=toStr(Env,value.body.sep0);
      out+=toStr(Env,value.body.path);
      out+=toStr(Env,value.body.sep1);
      return out;
    };
    if(!prefix.empty())if(value.body.path)
    {
      auto prefix_back=split(prefix.substr(0,prefix.size()-2),"::").back();
      auto path_back=value.body.path.get()->arr.back().value;
      if(path_back!=prefix_back)
      {
        QapNoWay();
      }
      QapAssert(value.body.path.get()->arr.size()==1);
      value.body.path=nullptr;
    }
    if(!prefix.empty())QapAssert(!value.body.path);
    auto impl_bef=f();
    ret_type_bot.rollback();
    if(need_restore)value.body.keywords=std::move(buff_arr);
    auto ast_bef=f();
    QapAssert(pw->params);
    string aft;
    if(pw->params)
    {
      auto&arr=pw->params.get()->arr;
      typedef std::remove_reference<decltype(arr[0].value)>::type t_item;
      vector<t_item> items;items.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        items[i]=std::move(ex.value);
        ex.value=nullptr;
      }
      aft=toStr(Env,*pw);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.value=std::move(items[i]);
      }
    }
    impl_bef=without_first_sep(impl_bef);
    auto short_aft=toStr(Env,pw->params)+toStr(Env,pw->cv1);
    string new_path=prefix;if(friend_dropped)new_path.clear();
    qap_add_back(out)=impl_bef+new_path+rnp->name+aft;
    t_fv_class_stat tmp;
    auto tmp_src=ast_bef+rnp->name+short_aft+";";
    auto tmp_res=load_obj_full(Env,tmp,tmp_src);
    QapAssert(tmp_res.ok);
    value=std::move(tmp);
  }
  template<class T_FUNC_LIKE_STAT_IMPL>
  void bar(T_FUNC_LIKE_STAT_IMPL&value,const string&prefix)
  {
    auto*pimpl=t_impl_func_body::UberCast(value.body.get());
    if(!pimpl)return;
    __if_exists(T_FUNC_LIKE_STAT_IMPL::prefix)
    {
      TAutoPtr<t_ctor_class_stat::t_impl::t_explicit>&value_prefix=value.prefix;
      TAutoPtr<t_ctor_class_stat::t_impl::t_explicit> backup_value_prefix=std::move(value_prefix);
    }
    vector<t_keyword> buff_arr; bool need_restore=false; bool friend_dropped=false; bool virtual_dropped=false;
    {
      __if_exists(T_FUNC_LIKE_STAT_IMPL::keywords)
      {
        vector<t_keyword>&arr=value.keywords;
        drop_keyword(arr,"inline");
        if(prefix.empty())drop_keyword(arr,"static");
        int gg=1;
        qap_simple_clone(Env,buff_arr,arr);
        static auto starr=split("explicit,static",",");
        for(int i=0;i<starr.size();i++)need_restore=need_restore||drop_keyword(arr,starr[i]);
        friend_dropped=drop_keyword(arr,"friend");
        virtual_dropped=drop_keyword(arr,"virtual");
        need_restore=need_restore||friend_dropped||virtual_dropped;
      }
    }
    if(!prefix.empty())if(value.path)
    {
      auto prefix_back=split(prefix.substr(0,prefix.size()-2),"::").back();
      auto path_back=value.path.get()->arr.back().value;
      if(path_back!=prefix_back)
      {
        QapNoWay();
      }
      QapAssert(value.path.get()->arr.size()==1);
      value.path=nullptr;
    }
    if(!prefix.empty())QapAssert(!value.path);
    if(prefix.empty()&&value.path)return;
    QapAssert(!value.path);
    int gg=1;
    if(!friend_dropped)
    {
      TAutoPtr<t_func_path> tmp;
      auto res=load_obj_full(Env,tmp,prefix);
      QapAssert(res.ok);
      value.path=std::move(tmp);
    }
    if(friend_dropped)QapAssert(!value.path);
    if(true)
    {
      auto&arr=value.params.arr;
      typedef std::remove_reference<decltype(arr[0].value)>::type t_item;
      vector<t_item> items;items.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        items[i]=std::move(ex.value);
        ex.value=nullptr;
      }
      qap_add_back(out)=without_first_sep(toStr(Env,value));
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.value=std::move(items[i]);
      }
    }
    value.path=nullptr;
    value.body.build<t_null_func_body>(Env);
    __if_exists(T_FUNC_LIKE_STAT_IMPL::keywords){if(need_restore)value.keywords=std::move(buff_arr);}
    __if_exists(T_FUNC_LIKE_STAT_IMPL::prefix)
    {
      value_prefix=std::move(backup_value_prefix);
    }
  }
  void grab_all_class_name_form_tree(t_class_stats&arr,const string&prefix)
  {
    for(int i=0;i<arr.size();i++)
    {
      auto*ptr=arr[i].get();
      if(auto*p=t_fv_class_stat::UberCast(ptr))
      {
        foo(*p,prefix);
      }
      if(auto*p=t_ctor_class_stat::UberCast(ptr))
      {
        bar(p->body,prefix);
      }
      if(auto*p=t_common_oper_class_stat::UberCast(ptr))
      {
        bar(p->body,prefix);
      }
      if(auto*p=t_oper_cast_class_stat::UberCast(ptr))
      {
        bar(*p,prefix);
      }
      if(auto*p=t_dtor_class_stat::UberCast(ptr))
      {
        bar(*p,prefix);
      }
      auto*cs=t_class_class_stat::UberCast(ptr);
      if(!cs)continue;
      auto*b=cs->body.body.get();
      if(!b)continue;
      mem.push(b->arr,cs->body.name);
      grab_all_class_name_form_tree(b->arr,prefix+cs->body.name+"::");
      mem.pop(b->arr,cs->body.name);
    }
  }
};
void xxx_empty_unit_test_old(IEnvRTTI&Env)
{
  if(0)
  {
    auto d=file_get_contents("D:\\temp\\uidev_fct\\Sgon\\otak.i");
    d=StrReplace(d,"\rn","\n");
    d=StrReplace(d,"\r","");
    auto arr=split(d,"\n");
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        int skip=0;
        for(int j=0;j<ex.size();j++)if(ex[j]!=' ')skip++;
        if(skip)continue;
        ex="";
      }
      int dest=0;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.empty())continue;
        if(dest!=i)arr[dest]=ex;
        dest++;
      }
      arr.resize(dest);
      d=join(arr,"\n");
    }
    file_put_contents("otak.i",d);
    InfoBox("finish!");
    return;
  }
  auto content=file_get_contents(1?"../lex_gen/inl_parser_test.h":"../Macro/all.h");
  auto code=StrReplace(content,"\r","\n");
  auto test_out=split(code,"\n//out\n")[1];
  code=split(code,"\n//out\n")[0];
  QapClock clock;
  clock.Start();
  t_inl_file tmp;
  auto res=load_obj_full(Env,tmp,code);
  clock.Stop();
  int gg=1;
  InfoBox("time:"+FToS(clock.MS())+"ms\n"+res.msg);
  {
    vector<string> out;
    t_some_shit_grabber_tool tool(Env,out);
    tool.grab_all_class_name_form_tree(tmp.arr,"");
    string tree;
    QapAssert(save_obj(Env,tmp,tree));
    InfoBox(tree+"\n//impl\n"+join(out,"\n"));
  }
  TerminateProcess(GetCurrentProcess(),0);
  if(!res.ok)return;
}
struct TCompileUnitMan:public ICompileUnitMan
{
  vector<ICompileUnit*> arr;
  void add(ICompileUnit*pUnit){arr.push_back(pUnit);}
  static TCompileUnitMan&get_man()
  {
    static TCompileUnitMan comp_unit_man;
    return comp_unit_man;
  }
  static void reg_and_run_all(IEnvRTTI&Env)
  {
    auto&man=get_man();
    auto&arr=man.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto*ex=arr[i];
      string fn=ex->get_filename();
      ex->RegAll(Env);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto*ex=arr[i];
      string fn=ex->get_filename();
      ex->Run(Env);
    }
  }
};
ICompileUnitMan&ICompileUnitMan::get_man()
{
  return TCompileUnitMan::get_man();
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  auto&comp_unit_man=TCompileUnitMan::get_man();
  string unit_name=comp_unit_man.arr[0]->get_filename();
  static GlobalEnv gEnv(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TStdAllocator MA;
  {
    TEnvRTTI Env;
    Env.Arr.reserve(1024);
    Env.Alloc=&MA;
    Env.OwnerEnv=&Env;
    TCompileUnitMan::reg_and_run_all(Env);
    xxx_empty_unit_test_old(Env);
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}

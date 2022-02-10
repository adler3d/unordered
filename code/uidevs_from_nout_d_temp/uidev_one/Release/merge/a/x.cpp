#include "ph.h"
int max(int a,int b)
{
  return a>b?a:b;
}
int min(int a,int b)
{
  return a<b?a:b;
}
float max(float a,float b)
{
  return a>b?a:b;
}
float min(float a,float b)
{
  return a<b?a:b;
}
double max(double a,double b)
{
  return a>b?a:b;
}
double min(double a,double b)
{
  return a<b?a:b;
}
TScreenMode GetScreenMode()
{
  HDC DC=GetDC(0);
  TScreenMode Res={GetDeviceCaps(DC,HORZRES),GetDeviceCaps(DC,VERTRES),GetDeviceCaps(DC,BITSPIXEL),GetDeviceCaps(DC,VREFRESH)};
  ReleaseDC(0,DC);
  return Res;
}
CharMask::CharMask(CharMask&&ref)
{
  for (uint i=0;i<sizeof(mask);i++)mask[i]=ref.mask[i];
}
CharMask::CharMask()
{
  for (uint i=0;i<sizeof(mask);i++)mask[i]=false;
}
CharMask CharMask::fromStr(const string&str)
{
  CharMask tmp;
  tmp.prepare(str);
  return std::move(tmp);
}
void CharMask::prepare(const std::string&allowed)
{
  for (uint i=0;i<sizeof(mask);i++)mask[i]=false;
  for (uint i=0;i<uint(allowed.size());i++)
  {
    unsigned char uc=uchar(allowed[i]);
    bool&flag=mask[uc];
    QapAssert(!flag);
    flag=true;
  }
}
bool CharMask::check(const std::string&str)const
{
  auto n=str.size();
  if (!n)return true;
  const auto*p=&str[0];
  auto e=p+n;
  for (;p<e;p++)
  {
    if (!mask[uchar(*p)])return false;
  }
  return true;
}
bool CharMask::operator[](uchar index)const
{
  return mask[index];
}
real RndReal(const real&min,const real&max)
{
  return min+(max-min)*(real)rand()/(real)RAND_MAX;
}
string CToS(const char&val)
{
  string tmp="";
  tmp.push_back(val);
  return tmp;
}
string IToS(const int&val)
{
  char c[16];
  _itoa_s(val,c,10);
  return string(c);
}
string UCToS(const unsigned char&val)
{
  char d[8];
  sprintf_s(d,sizeof(d),"%u",val);
  return string(d);
}
string HToS(const int&val)
{
  char c[16];
  _itoa_s(val,c,16);
  return "0x"+string(c);
}
string IToSex(const int&val)
{
  char c[40];
  sprintf_s(c,"%08i",val);
  int i=0;
  while (c[i]=='0')c[i++]='-';
  return string(c);
}
string FToS(const real&val)
{
  char c[64];
  if (abs(val)>1e9)
  {
    _snprintf_s(c,32,32,"%e",val);
  }
  else
  {
    sprintf_s(c,"%.2f",val);
  }
  return string(c);
}
string BToS(const bool&val)
{
  return val?"true":"false";
}
string IToH(const int&val)
{
  char d[255];
  sprintf_s(d,sizeof(d),"0x%08X",val);
  return string(d);
}
string IToH(const int&val,int n)
{
  char d[255];
  n=n<0?8:n>8?8:n;
  string c=IToS(n);
  sprintf_s(d,sizeof(d),("0x%0"+c+"X").c_str(),val);
  return string(d);
}
string IToH_raw(const int&val)
{
  char d[255];
  sprintf_s(d,sizeof(d),"%08X",val);
  return string(d);
}
char HToC(const string&str)
{
  size_t val;
  sscanf_s(str.c_str(),"%02x",&val);
  return char(val);
}
bool SToF(const string&str,real&val)
{
  sscanf_s(str.c_str(),"%lf",&val);
  return true;
}
bool SToB(const string&str,bool&val)
{
  val=str=="true";
  return true;
}
bool SToB(const string&str)
{
  return str=="true";
}
bool SToC(const string&str,char&val)
{
  if (str.size()!=1)return false;
  val=str[0];
  return true;
}
bool HToI(const string&str,int&val)
{
  sscanf_s(str.c_str(),"0x%08X",&val);
  return true;
}
int HToI(const string&str)
{
  int val;
  sscanf_s(str.c_str(),"0x%08X",&val);
  return val;
}
int HToI_raw(const string&str)
{
  int val;
  sscanf_s(str.c_str(),"%08X",&val);
  return val;
}
string CToH_raw(const unsigned char&val)
{
  char d[3];
  sprintf_s(d,sizeof(d),"%02X",val);
  return string(d);
}
string SToS(const string&s)
{
  return s;
}
string SToSex(const string&S,const int&l)
{
  string s(l,' ');
  for (int i=0;i<int(S.size());i++)s[i]=S[i];
  return s;
}
int SToI(const string&S)
{
  int i;
  sscanf_s(S.c_str(),"%i",&i);
  return i;
}
int SToI_fast(const string&S)
{
  int i;
  sscanf_s(S.c_str(),"%i",&i);
  return i;
}
string GetFileName(const string&filename)
{
  static CharMask mask("\\/");
  if (filename.empty())return filename;
  int c=0;
  for (int i=filename.size()-1;i>=0;i--)
  {
    if (mask.mask[filename[i]])
    {
      string out=filename.substr(i+1,c);
      return out;
    }
    c++;
  }
  return filename;
}
bool IsRawDirName(const std::string&dirname)
{
  static CharMask mask(".");
  const string&raw=GetFileName(dirname);
  return !mask.check(raw);
}
string RemoveFileExt(const string&FN)
{
  const int pos=FN.rfind(".");
  return std::move(FN.substr(0,pos));
}
string ChangeFileExt(const string&FN,const string&Ext)
{
  string tmp=RemoveFileExt(FN)+Ext;
  return std::move(tmp);
}
string BackSlashesToSlashes(const string&data)
{
  string tmp=data;
  for (int i=0;i<tmp.size();i++)
  {
    char&c=tmp[i];
    if (c=='\\')
    {
      c='/';
    }
  }
  return std::move(tmp);
}
string ScanParam(const string&Before,const string&Where,const string&After,int&Pos)
{
  int E=Where.find(Before, Pos);
  if (E==-1)
  {
    Pos=-1;
    return "";
  }
  Pos=Where.find(Before,Pos)+Before.length();
  E=After.empty()?Where.size():Where.find(After,Pos);
  if (E==-1)
  {
    Pos=-1;
    return "";
  }
  string result;
  result.assign(Where,Pos,E-Pos);
  return std::move(result);
}
string GetDataTimeStr()
{
  class UG
  {
  public:
    static inline string X(int val,string fs)
    {
      char c[40];
      sprintf_s(c,fs.c_str(),val);
      return string(c);
    }
  };
  SYSTEMTIME LT;
  GetLocalTime(&LT);
  string Str;
  Str=UG::X(LT.wYear,"%0""2""i")+"-"+UG::X(LT.wMonth,"%0""2""i")+"-"+UG::X(LT.wDay,"%0""2""i")+" "
      +UG::X(LT.wHour,"%0""2""i")+"-"+UG::X(LT.wMinute,"%0""2""i")+"-"+UG::X(LT.wSecond,"%0""2""i")+"-"+UG::X(LT.wMilliseconds,"%0""3""i");
  Str.resize(Str.size()-1);
  return Str;
}
string GetFileExt(const string&FN)
{
  int e=FN.rfind(".");
  string ext=ScanParam(".",FN,"",e);
  return ext;
}
string LowerStr(const string&s)
{
  string str=s;
  for (int i=0;i<int(str.size());i++)str[i]=tolower(str[i]);
  return std::move(str);
}
string UpperStr(const string&s)
{
  string str=s;
  for (int i=0;i<int(str.size());i++)str[i]=toupper(str[i]);
  return std::move(str);
}
bool IsNumChar(const uchar&c)
{
  return bool(uchar('0')<=c&&uchar('9')>=c);
}
bool IsLegalChar(const uchar&c)
{
  return bool(uchar('a')<=c&&uchar('z')>=c)||bool(uchar('A')<=c&&uchar('Z')>=c)||bool(uchar('0')<=c&&uchar('9')>=c);
}
Extractor::Gripper::Gripper(const string&before,const string&after):before(before),after(after) {}
string Extractor::Gripper::grip(const string&source)const
{
  return before+source+after;
}
Extractor::Extractor(const string&source):pos(0),source(source) {}
string Extractor::extract(const Gripper&ref)
{
  string s=ScanParam(ref.before,source,ref.after,pos);
  if (pos>=0)pos+=s.size()+ref.after.size();
  return s;
}
Extractor::operator bool()
{
  return pos>=0;
}
string gen_dip(char from,char to)
{
  QapAssert(from<to);
  string out;
  out.reserve(to-from);
  bool flag=from!=to;
  for (auto c=from;flag;c++)
  {
    flag=flag&&(c!=to);
    out.push_back(c);
  }
  return out;
}
string gen_dips(const string&rule)
{
  QapAssert(!(rule.size()%2));
  string out;
  for (int i=0;i<rule.size();i+=2)
  {
    out+=gen_dip(rule[i+0],rule[i+1]);
  }
  return out;
}
string dip_inv(const string&dip)
{
  string out;
  char min=std::numeric_limits<char>::min();
  char max=std::numeric_limits<char>::max();
  bool flag=min!=max;
  for (auto c=min;flag;c++)
  {
    flag=flag&&(c!=max);
    auto e=dip.find(CToS(c));
    if (e!=std::string::npos)continue;
    out.push_back(c);
  }
  return out;
}
vector<string> split(const string&s,const string&needle)
{
  vector<string> arr;
  if (s.empty())return arr;
  size_t p=0;
  for (;;)
  {
    auto pos=s.find(needle,p);
    if (pos==std::string::npos)
    {
      arr.push_back(s.substr(p));
      return arr;
    }
    arr.push_back(s.substr(p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}
string join(const vector<string>&arr,const string&glue)
{
  string out;
  size_t c=0;
  size_t dc=glue.size();
  for (int i=0;i<arr.size();i++)
  {
    if (i)c+=dc;
    c+=arr[i].size();
  }
  out.reserve(c);
  for (int i=0;i<arr.size();i++)
  {
    if (i)out+=glue;
    out+=arr[i];
  }
  return out;
}
string StrReplace(const string&input,const string&sub,const string&now)
{
  return join(split(input,sub),now);
}
string urlencode(const string&str)
{
  string tmp;
  tmp.reserve(str.size()*3);
  for (int i=0;i<str.size();i++)
    tmp+=IsLegalChar(str[i])?CToS(str[i]):"%"+CToH_raw(str[i]);
  return tmp;
}
string urldecode(const string&s)
{
  auto arr=split(s,"%");
  string out="";
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (i==0)
    {
      out+=ex;
      continue;
    }
    QapAssert(ex.size()>=2);
    out.push_back(char(HToC(ex.substr(0,2))));
    out+=ex.substr(2);
  }
  return out;
}
vector<int> qap_find_str(const vector<string>&arr,const string&value)
{
  vector<int> out;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (ex==value)out.push_back(i);
  }
  return out;
}
int WinMessageBox(const string&caption,const string&text)
{
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  QapMsgBoxRetval retval=qmbrSkip;
  if (IDCONTINUE==nCode)retval=qmbrIgnore;
  if (IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
}
int TMessageBoxCaller::Call(const string&caption,const string&text)
{
  return Get()(caption,text);
}
TQapMessageBox&TMessageBoxCaller::Get()
{
  static TQapMessageBox func=WinMessageBox;
  return func;
}
TMessageBoxCaller::t_hack::t_hack(TQapMessageBox func)
{
  old=Get();
  Get()=func;
}
TMessageBoxCaller::t_hack::~t_hack()
{
  Get()=old;
}
bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if (ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+IToS(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nAssertion failed :\n"+exp;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Assertion failed",text);
  if (qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if (ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+IToS(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nDebug message :\n"+msg;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Debug message",text);
  if (qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
CppString::CppString() {}
CppString::CppString(const string&ref)
{
  oper_set(ref);
}
void CppString::operator=(const string&ref)
{
  oper_set(ref);
}
string CppString::toCode(uchar ch)
{
  string tmp=CToH_raw(ch);
  string out="\\x"+tmp;
  return out;
}
const CharMask&CppString::getMask()
{
  static CharMask mask(
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789"
    "_ π"
    "+-*/=|~!@#$%^&()[]{}<>.,:?;`"
    "¿¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ"
    "‡·‚„‰Â∏ÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ"
  );
  return mask;
}
void CppString::oper_set(const string&ref)
{
  int linestart=0;
  const CharMask&mask=CppString::getMask();
  data.clear();
  data.reserve(ref.size());
  struct Hidden
  {
    string&data;
    string line;
    int line_count;
    Hidden(string&data):data(data)
    {
      line_count=0;
    }
    ~Hidden()
    {
      if (!line.empty())next();
      if (line.size()<=64)return;
      string beg="BEGIN()\n";
      string end="END()\n";
      data=beg+data+end;
    }
    void next()
    {
      static const int c8k=2<<12;
      line_count++;
      data+=line;
      line.clear();
      if (!(line_count%c8k))
      {
        QapDebugMsg("big line");
        data+="END()\nBEGIN()\n";
      }
    }
    void check()
    {
      const int linesize=line.size();
      if (linesize>80)next();
    }
  } HD(data);
  string&line=HD.line;
  for (int i=0;i<ref.size();i++)
  {
    uchar ex=ref[i];
    HD.check();
    if (!mask[ex])
    {
      if (ex=='\\')
      {
        line+="\\\\";
        continue;
      }
      if (ex=='\"')
      {
        line+="\\\"";
        continue;
      }
      if (ex=='\'')
      {
        line+="\\\'";
        continue;
      }
      if (ex=='\n')
      {
        line+="\\n";
        continue;
      }
      if (ex=='\r')
      {
        line+="\\r";
        continue;
      }
      if (ex=='\t')
      {
        line+="\\t";
        continue;
      }
      if (ex=='\b')
      {
        line+="\\b";
        continue;
      }
      if (ex=='\f')
      {
        line+="\\f";
        continue;
      }
      if (ex=='\0')
      {
        line+="\\0";
        continue;
      }
      if (ex=='\1')
      {
        line+="\\1";
        continue;
      }
      if (ex=='\2')
      {
        line+="\\2";
        continue;
      }
      if (ex=='\3')
      {
        line+="\\3";
        continue;
      }
      if (ex=='\4')
      {
        line+="\\4";
        continue;
      }
      if (ex=='\5')
      {
        line+="\\5";
        continue;
      }
      if (ex=='\6')
      {
        line+="\\6";
        continue;
      }
      if (ex=='\7')
      {
        line+="\\7";
        continue;
      }
      line+=toCode(ex);
    }
    else
    {
      line.push_back(ex);
    }
  }
}
bool CppString::IsValidCppChar(char c)
{
  const CharMask&mask=CppString::getMask();
  unsigned char uc=*(unsigned char*)(void*)&c;
  return mask.mask[uc];
}
BinString::BinString() {}
BinString::BinString(const string&ref)
{
  oper_set(ref);
}
void BinString::operator=(const string&ref)
{
  oper_set(ref);
}
string BinString::fullCppStr2RawStr(const string&cpp)
{
  QapAssert(cpp.size()>2);
  QapAssert(cpp.front()=='"');
  QapAssert(cpp.back()=='"');
  BinString bin=cpp.substr(1,cpp.size()-2);
  return bin.data;
}
string BinString::toCode(uchar ch)
{
  string tmp=CToH_raw(ch);
  string out="'\\x"+tmp+"'";
  return out;
}
void BinString::oper_set(const string&ref)
{
  int linestart=0;
  const CharMask&mask=CppString::getMask();
  data.clear();
  data.reserve(ref.size());
  uchar prev=0;
  for (int i=0;i<ref.size();i++)
  {
    uchar ex=ref[i];
    if ((!mask[ex])||(prev=='\\'))
    {
      {
        if ((prev=="\\\\"[0])&&(ex=="\\\\"[1]))
        {
          data.push_back('\\');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\\""[0])&&(ex=="\\\""[1]))
        {
          data.push_back('\"');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\\'"[0])&&(ex=="\\\'"[1]))
        {
          data.push_back('\'');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\n"[0])&&(ex=="\\n"[1]))
        {
          data.push_back('\n');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\r"[0])&&(ex=="\\r"[1]))
        {
          data.push_back('\r');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\t"[0])&&(ex=="\\t"[1]))
        {
          data.push_back('\t');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\b"[0])&&(ex=="\\b"[1]))
        {
          data.push_back('\b');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\f"[0])&&(ex=="\\f"[1]))
        {
          data.push_back('\f');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\0"[0])&&(ex=="\\0"[1]))
        {
          data.push_back('\0');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\1"[0])&&(ex=="\\1"[1]))
        {
          data.push_back('\1');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\2"[0])&&(ex=="\\2"[1]))
        {
          data.push_back('\2');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\3"[0])&&(ex=="\\3"[1]))
        {
          data.push_back('\3');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\4"[0])&&(ex=="\\4"[1]))
        {
          data.push_back('\4');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\5"[0])&&(ex=="\\5"[1]))
        {
          data.push_back('\5');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\6"[0])&&(ex=="\\6"[1]))
        {
          data.push_back('\6');
          prev=0;
          continue;
        }
      }
      {
        if ((prev=="\\7"[0])&&(ex=="\\7"[1]))
        {
          data.push_back('\7');
          prev=0;
          continue;
        }
      }
      if ((prev!='\\')&&ex=='\\')
      {
        prev=ex;
        continue;
      }
      QapDebugMsg("bad char("+toCode(ex)+") = \'"+CToS(ex)+"\'");
      return;
    }
    else
    {
      data.push_back(ex);
    }
    prev=ex;
  }
}
void IVisitorRTTI::Do(TTypeFactory*p) {}
int UniqueID::GetID()
{
  static int SysID=0;
  return ++SysID;
}
void UniqueID::operator=(const UniqueID&)
{
  QapAssert(0);
}
UniqueID::UniqueID(const UniqueID&)
{
  QapAssert(0);
}
void UniqueID::on_init()
{
  weak_on_init<0>();
}
void UniqueID::on_free()
{
  weak_on_free<0>();
}
void UniqueID::on_move(int from,int to)
{
  weak_on_move<0>(from,to);
}
UniqueID::~UniqueID()
{
  on_free();
}
UniqueID::UniqueID()
{
  id=GetID();
  on_init();
}
UniqueID::UniqueID(UniqueID&&_Right)
{
  oper_set(std::move(_Right));
}
void UniqueID::operator=(UniqueID&&_Right)
{
  oper_set(std::move(_Right));
}
void UniqueID::oper_set(UniqueID&&_Right)
{
  on_move(_Right.id,id);
}
void IBinIO::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
IBinIO::IBinIO()
{
  DoReset();
}
IBinIO::IBinIO(IBinIO&&_Right)
{
  operator=(std::move(_Right));
}
void IBinIO::operator=(IBinIO&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string IBinIO::ProxySys$$::GetFullName()
{
  return "IBinIO";
}
void IBinIO::Save(QapIO&IO,void*p)
{
  QapDebugMsg("no way.");
}
void IBinIO::Load(QapIO&IO,void*p)
{
  QapDebugMsg("no way.");
}
void IBinIO::Copy(void*pOut,void*pInp)
{
  QapDebugMsg("no way.");
}
bool IBinIO::IsSame(void*pA,void*pB)
{
  QapDebugMsg("no way.");
  return *(bool*)nullptr;
}
TType*IBinIO::GetElementType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
TType*IBinIO::GetMetaType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
IBinIO::~IBinIO() {}
void ITxtIO::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
ITxtIO::ITxtIO()
{
  DoReset();
}
ITxtIO::ITxtIO(ITxtIO&&_Right)
{
  operator=(std::move(_Right));
}
void ITxtIO::operator=(ITxtIO&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string ITxtIO::ProxySys$$::GetFullName()
{
  return "ITxtIO";
}
void ITxtIO::Save(string&s,void*p)
{
  QapDebugMsg("no way.");
}
void ITxtIO::Load(string&s,void*p)
{
  QapDebugMsg("no way.");
}
TType*ITxtIO::GetElementType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
TType*ITxtIO::GetMetaType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
ITxtIO::~ITxtIO() {}
void IVectorAPI::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
IVectorAPI::IVectorAPI()
{
  DoReset();
}
IVectorAPI::IVectorAPI(IVectorAPI&&_Right)
{
  operator=(std::move(_Right));
}
void IVectorAPI::operator=(IVectorAPI&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string IVectorAPI::ProxySys$$::GetFullName()
{
  return "IVectorAPI";
}
IVectorAPI::~IVectorAPI() {}
IVectorAPI::SizeType IVectorAPI::GetCount(void*p)
{
  QapDebugMsg("no way.");
  return 0;
}
void IVectorAPI::SetCount(void*p,SizeType c)
{
  QapDebugMsg("no way.");
}
void*IVectorAPI::GetItem(void*p,SizeType i)
{
  QapDebugMsg("no way.");
  return nullptr;
}
TType*IVectorAPI::GetElementType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
TType*IVectorAPI::GetMetaType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
noused_t::noused_t(nullptr_t) {}
TMemory::TMemory():ptr(nullptr),size(0) {}
TMemory::operator bool()const
{
  QapAssert(bool(ptr)==bool(size));
  return ptr;
}
void TMemory::operator=(nullptr_t)
{
  ptr=nullptr;
  size=0;
}
void TMemory::operator=(TMemory&&_Right)
{
  ptr=_Right.ptr;
  _Right.ptr=nullptr;
  size=_Right.size;
  _Right.size=0;
}
void IProduct::DoReset()
{
  {
    ;
  }
}
IProduct::IProduct()
{
  DoReset();
}
IProduct::IProduct(IProduct&&_Right)
{
  operator=(std::move(_Right));
}
void IProduct::operator=(IProduct&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string IProduct::ProxySys$$::GetFullName()
{
  return "IProduct";
}
void IProduct::safe_free()
{
  if (bool(*this))Free();
}
const TMemory&IProduct::GetMemory()const
{
  QapDebugMsg("no way.");
  return *(TMemory*)nullptr;
}
TMemory&IProduct::GetMemory()
{
  QapDebugMsg("no way.");
  return *(TMemory*)nullptr;
}
IAllocator*IProduct::GetAlloc()
{
  QapDebugMsg("no way.");
  return nullptr;
}
IFactory*IProduct::GetFactory()
{
  QapDebugMsg("no way.");
  return nullptr;
}
TType*IProduct::GetType()
{
  QapDebugMsg("no way.");
  return nullptr;
}
void IProduct::Init()
{
  weak_Init<0>();
}
void IProduct::Free()
{
  weak_Free<0>();
}
IProduct::operator bool()const
{
  return bool(GetMemory());
}
void TProduct::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Memory);
  detail::FieldTryDoReset(this->Alloc);
  detail::FieldTryDoReset(this->Factory);
}
TProduct::TProduct()
{
  DoReset();
}
TProduct::TProduct(TProduct&&_Right)
{
  operator=(std::move(_Right));
}
void TProduct::operator=(TProduct&&_Right)
{
  struct hidden
  {
    static void foo(IProduct(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    IProduct::operator=(std::move(_Right));;
  }
  this->Memory=std::move(_Right.Memory);;
  this->Alloc=std::move(_Right.Alloc);;
  this->Factory=std::move(_Right.Factory);;
}
string TProduct::ProxySys$$::GetFullName()
{
  return "TProduct";
}
const TMemory&TProduct::GetMemory()const
{
  return Memory;
}
TMemory&TProduct::GetMemory()
{
  return Memory;
}
IAllocator*TProduct::GetAlloc()
{
  return Alloc.get();
}
IFactory*TProduct::GetFactory()
{
  return Factory.get();
}
TType*TProduct::GetType()
{
  return nullptr;
}
TProduct::~TProduct()
{
  safe_free();
}
void TRTTIProduct::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Memory);
  detail::FieldTryDoReset(this->pType);
}
TRTTIProduct::TRTTIProduct()
{
  DoReset();
}
TRTTIProduct::TRTTIProduct(TRTTIProduct&&_Right)
{
  operator=(std::move(_Right));
}
void TRTTIProduct::operator=(TRTTIProduct&&_Right)
{
  struct hidden
  {
    static void foo(IProduct(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    IProduct::operator=(std::move(_Right));;
  }
  this->Memory=std::move(_Right.Memory);;
  this->pType=std::move(_Right.pType);;
}
string TRTTIProduct::ProxySys$$::GetFullName()
{
  return "TRTTIProduct";
}
const TMemory&TRTTIProduct::GetMemory()const
{
  return Memory;
}
TMemory&TRTTIProduct::GetMemory()
{
  return Memory;
}
IAllocator* TRTTIProduct::GetAlloc()
{
  return weak_GetAlloc<0>();
}
IFactory* TRTTIProduct::GetFactory()
{
  return weak_GetFactory<0>();
}
TType* TRTTIProduct::GetType()
{
  return weak_GetType<0>();
}
TRTTIProduct::~TRTTIProduct()
{
  safe_free();
}
void IFactory::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
IFactory::IFactory()
{
  DoReset();
}
IFactory::IFactory(IFactory&&_Right)
{
  operator=(std::move(_Right));
}
void IFactory::operator=(IFactory&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string IFactory::ProxySys$$::GetFullName()
{
  return "IFactory";
}
IFactory::~IFactory() {}
void IFactory::Init(IAllocator*pAlloc,TMemory&)
{
  QapDebugMsg("no way.");
}
void IFactory::Free(IAllocator*pAlloc,TMemory&)
{
  QapDebugMsg("no way.");
}
string IFactory::GetElementTypeFullName()const
{
  QapDebugMsg("no way.");
  return "";
}
TType*IFactory::GetElementType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
TType*IFactory::GetMetaType(IEnvRTTI&Env)
{
  QapDebugMsg("no way.");
  return nullptr;
}
int IFactory::GetSize()
{
  QapDebugMsg("no way.");
  return 0;
}
void IFactory::UnsafeInit(const TMemory&)
{
  QapDebugMsg("no way.");
}
void IFactory::UnsafeFree(const TMemory&)
{
  QapDebugMsg("no way.");
}
void IFactory::UnsafeMove(const TMemory&Dest,const TMemory&Source)
{
  QapDebugMsg("no way.");
}
void IFactory::unlink() {}
void IAllocator::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
IAllocator::IAllocator()
{
  DoReset();
}
IAllocator::IAllocator(IAllocator&&_Right)
{
  operator=(std::move(_Right));
}
void IAllocator::operator=(IAllocator&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string IAllocator::ProxySys$$::GetFullName()
{
  return "IAllocator";
}
void IAllocator::Alloc(TMemory&)
{
  QapDebugMsg("no way.");
}
void IAllocator::Dealloc(TMemory&)
{
  QapDebugMsg("no way.");
}
IAllocator::TMemInfo&IAllocator::GetMemInfo()
{
  QapDebugMsg("no way.");
  return *(TMemInfo*)nullptr;
}
void IAllocator::TMemInfo::DoReset()
{
  {
    ;
  }
  (this->AllocCount)=(0);
  (this->DeallocCount)=(0);
  (this->MemoryUsed)=(0);
}
IAllocator::TMemInfo::TMemInfo()
{
  DoReset();
}
IAllocator::TMemInfo::TMemInfo(TMemInfo&&_Right)
{
  operator=(std::move(_Right));
}
void IAllocator::TMemInfo::operator=(TMemInfo&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->AllocCount=std::move(_Right.AllocCount);;
  this->DeallocCount=std::move(_Right.DeallocCount);;
  this->MemoryUsed=std::move(_Right.MemoryUsed);;
}
string IAllocator::TMemInfo::ProxySys$$::GetFullName()
{
  return "TMemInfo";
}
IAllocator::TMemInfo::~TMemInfo()
{
  QapAssert(AllocCount==DeallocCount);
  QapAssert(!MemoryUsed);
}
void IAllocator::TMemInfo::OnAlloc(TMemory&Mem)
{
  AllocCount++;
  MemoryUsed+=Mem.size;
}
void IAllocator::TMemInfo::OnDealloc(TMemory&Mem)
{
  DeallocCount++;
  MemoryUsed-=Mem.size;
}
void TDynStructFactory::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->pType);
}
TDynStructFactory::TDynStructFactory()
{
  DoReset();
}
TDynStructFactory::TDynStructFactory(TDynStructFactory&&_Right)
{
  operator=(std::move(_Right));
}
void TDynStructFactory::operator=(TDynStructFactory&&_Right)
{
  struct hidden
  {
    static void foo(IFactory(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    IFactory::operator=(std::move(_Right));;
  }
  this->pType=std::move(_Right.pType);;
}
string TDynStructFactory::ProxySys$$::GetFullName()
{
  return "TDynStructFactory";
}
void TDynStructFactory::Init(IAllocator*pAlloc,TMemory&Mem)
{
  Mem.size=GetSize();
  pAlloc->Alloc(Mem);
  Create<ptr_t>(get(Mem.ptr));
}
void TDynStructFactory::Free(IAllocator*pAlloc,TMemory&Mem)
{
  Destroy<ptr_t>(get(Mem.ptr));
  pAlloc->Dealloc(Mem);
  Mem.size=0;
}
int TDynStructFactory::GetSize()
{
  return weak_GetSize<void>();
}
void TDynStructFactory::UnsafeInit(const TMemory&Mem)
{
  QapAssert(Mem.ptr);
  QapAssert(Mem.size==GetSize());
  Create<ptr_t>(get(Mem.ptr));
}
void TDynStructFactory::UnsafeFree(const TMemory&Mem)
{
  QapAssert(Mem.ptr);
  QapAssert(Mem.size==GetSize());
  Destroy<ptr_t>(get(Mem.ptr));
}
void TDynStructFactory::UnsafeMove(const TMemory&Dest,const TMemory&Source)
{
  QapAssert(Dest.ptr);
  QapAssert(Dest.size==GetSize());
  QapAssert(Source.ptr);
  QapAssert(Source.size==GetSize());
  Move<ptr_t>(get(Dest.ptr),get(Source.ptr));
}
void TDynStructFactory::unlink()
{
  pType=nullptr;
}
TType*TDynStructFactory::GetElementType(IEnvRTTI&Env)
{
  return weak_GetElementType(Env);
}
TType*TDynStructFactory::GetMetaType(IEnvRTTI&Env)
{
  QapDebugMsg("[2014.08.23]: it used?");
  return nullptr;
}
TDynStructFactory::ptr_t*TDynStructFactory::get(TMemory::ptr_t*ptr)
{
  return (ptr_t*)(void*)ptr;
}
void TDynSelfPtrFactory::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->pType);
}
TDynSelfPtrFactory::TDynSelfPtrFactory()
{
  DoReset();
}
TDynSelfPtrFactory::TDynSelfPtrFactory(TDynSelfPtrFactory&&_Right)
{
  operator=(std::move(_Right));
}
void TDynSelfPtrFactory::operator=(TDynSelfPtrFactory&&_Right)
{
  struct hidden
  {
    static void foo(IFactory(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    IFactory::operator=(std::move(_Right));;
  }
  this->pType=std::move(_Right.pType);;
}
string TDynSelfPtrFactory::ProxySys$$::GetFullName()
{
  return "TDynSelfPtrFactory";
}
void TDynSelfPtrFactory::Init(IAllocator*pAlloc,TMemory&Mem)
{
  Mem.size=GetSize();
  pAlloc->Alloc(Mem);
  Create<ptr_t>(get(Mem.ptr));
}
void TDynSelfPtrFactory::Free(IAllocator*pAlloc,TMemory&Mem)
{
  Destroy<ptr_t>(get(Mem.ptr));
  pAlloc->Dealloc(Mem);
  Mem.size=0;
}
int TDynSelfPtrFactory::GetSize()
{
  return weak_GetSize<int>();
}
void TDynSelfPtrFactory::UnsafeInit(const TMemory&Mem)
{
  QapAssert(Mem.ptr);
  QapAssert(Mem.size==GetSize());
  Create<ptr_t>(get(Mem.ptr));
}
void TDynSelfPtrFactory::UnsafeFree(const TMemory&Mem)
{
  QapAssert(Mem.ptr);
  QapAssert(Mem.size==GetSize());
  Destroy<ptr_t>(get(Mem.ptr));
}
void TDynSelfPtrFactory::UnsafeMove(const TMemory&Dest,const TMemory&Source)
{
  QapAssert(Dest.ptr);
  QapAssert(Dest.size==GetSize());
  QapAssert(Source.ptr);
  QapAssert(Source.size==GetSize());
  QapDebugMsg("no way");
}
void TDynSelfPtrFactory::unlink()
{
  pType=nullptr;
}
TType*TDynSelfPtrFactory::GetElementType(IEnvRTTI&Env)
{
  return weak_GetElementType(Env);
}
TType*TDynSelfPtrFactory::GetMetaType(IEnvRTTI&Env)
{
  QapDebugMsg("[2014.08.23]: it used?");
  return nullptr;
}
TDynSelfPtrFactory::ptr_t*TDynSelfPtrFactory::get(TMemory::ptr_t*ptr)
{
  return (ptr_t*)(void*)ptr;
}
void TStdAllocator::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Info);
}
TStdAllocator::TStdAllocator()
{
  DoReset();
}
TStdAllocator::TStdAllocator(TStdAllocator&&_Right)
{
  operator=(std::move(_Right));
}
void TStdAllocator::operator=(TStdAllocator&&_Right)
{
  struct hidden
  {
    static void foo(IAllocator(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    IAllocator::operator=(std::move(_Right));;
  }
  this->Info=std::move(_Right.Info);;
}
string TStdAllocator::ProxySys$$::GetFullName()
{
  return "TStdAllocator";
}
void TStdAllocator::Alloc(TMemory&Mem)
{
  Mem.ptr=(TMemory::ptr_t*)new uchar[Mem.size];
  Info.OnAlloc(Mem);
}
void TStdAllocator::Dealloc(TMemory&Mem)
{
  Info.OnDealloc(Mem);
  memset(Mem.ptr,0,Mem.size);
  delete[] (uchar*)Mem.ptr;
  Mem.ptr=nullptr;
}
IAllocator::TMemInfo&TStdAllocator::GetMemInfo()
{
  return Info;
}
void EnvType::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Type);
  detail::FieldTryDoReset(this->Factory);
}
EnvType::EnvType()
{
  DoReset();
}
EnvType::EnvType(EnvType&&_Right)
{
  operator=(std::move(_Right));
}
void EnvType::operator=(EnvType&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Type=std::move(_Right.Type);;
  this->Factory=std::move(_Right.Factory);;
}
string EnvType::ProxySys$$::GetFullName()
{
  return "EnvType";
}
bool EnvType::CheckFactory()
{
  return weak_CheckFactory<0>();
}
void IEnvRTTI::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
IEnvRTTI::IEnvRTTI()
{
  DoReset();
}
IEnvRTTI::IEnvRTTI(IEnvRTTI&&_Right)
{
  operator=(std::move(_Right));
}
void IEnvRTTI::operator=(IEnvRTTI&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string IEnvRTTI::ProxySys$$::GetFullName()
{
  return "IEnvRTTI";
}
IAllocator*IEnvRTTI::GetAlloc()
{
  QapDebugMsg("no way");
  return nullptr;
}
int IEnvRTTI::RegInfo(TAutoPtr<TType>&&_Right)
{
  QapDebugMsg("no way");
  return 0;
}
EnvType&IEnvRTTI::GetEnvTypeById(int id)
{
  QapDebugMsg("no way");
  return *(EnvType*)nullptr;
}
vector<EnvType>&IEnvRTTI::GetArr()
{
  QapDebugMsg("no way");
  return *(vector<EnvType>*)nullptr;
}
void IEnvRTTI::OnRegBeg(TType*Info)
{
  QapDebugMsg("no way");
}
void IEnvRTTI::OnRegRet(TType*Info)
{
  QapDebugMsg("no way");
}
void IEnvRTTI::OnRegEnd(TType*Info)
{
  QapDebugMsg("no way");
}
IEnvRTTI*IEnvRTTI::GetOwnerEnv()
{
  QapDebugMsg("no way");
  return nullptr;
}
IEnvRTTI::TTypeFullNameComparator::TTypeFullNameComparator(const string&fn):fn(fn) {}
bool IEnvRTTI::TTypeFullNameComparator::operator()(EnvType&ex)
{
  return template_detail<0>::campare_type_full_name(ex.Type.get(),fn);
}
TType*IEnvRTTI::FindTypeByName_is_ug_but_work(const string&fn)
{
  auto&types=GetArr();
  auto&arr=qap_find(types,TTypeFullNameComparator(fn));
  QapAssert(arr.size()<=1);
  if (arr.empty())return nullptr;
  return types[arr[0]].Type.get();
}
TType*IEnvRTTI::FindTypeByFactory(IFactory*pFactory)
{
  return weak_FindTypeByFactory<void>(pFactory);
}
bool IEnvRTTI::IsRootEnv()
{
  return GetOwnerEnv()==this;
}
IEnvRTTI*IEnvRTTI::GetRootEnv()
{
  IEnvRTTI*pEnv=this;
  while (pEnv)
  {
    auto*p=pEnv->GetOwnerEnv();
    if (p==pEnv)return pEnv;
    pEnv=p;
  }
  QapDebugMsg("WTF?");
  return nullptr;
}
void TTypeInfo::DoReset()
{
  {
    ;
  }
  (this->Name)=("unnamed");
  (this->Size)=(0);
  (this->Align)=(0);
}
TTypeInfo::TTypeInfo()
{
  DoReset();
}
TTypeInfo::TTypeInfo(TTypeInfo&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeInfo::operator=(TTypeInfo&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Name=std::move(_Right.Name);;
  this->Size=std::move(_Right.Size);;
  this->Align=std::move(_Right.Align);;
}
string TTypeInfo::ProxySys$$::GetFullName()
{
  return "TTypeInfo";
}
void TType::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Env);
  detail::FieldTryDoReset(this->Factory);
  detail::FieldTryDoReset(this->Info);
}
TType::TType()
{
  DoReset();
}
TType::TType(TType&&_Right)
{
  operator=(std::move(_Right));
}
void TType::operator=(TType&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Env=std::move(_Right.Env);;
  this->Factory=std::move(_Right.Factory);;
  this->Info=std::move(_Right.Info);;
}
string TType::ProxySys$$::GetFullName()
{
  return "TType";
}
void TType::Use(IVisitorRTTI&)
{
  QapDebugMsg("no way.");
}
string TType::GetFullName()
{
  return Info.Name;
}
TType*TType::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TType*TType::GetSubType()const
{
  return nullptr;
}
bool TType::ready()const
{
  return Env&&Env->GetAlloc()&&Factory;
}
IAllocator*TType::GetAlloc()
{
  return Env?Env->GetAlloc():nullptr;
}
bool TType::CanDestroy()const
{
  return 1==Self.P.HardCount;
}
bool TType::IsBasedOn(TType*A)const
{
  if (this==A)return true;
  TType*subtype=this->GetSubType();
  return subtype?subtype->IsBasedOn(A):false;
}
void TTypeSys::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->BinIO);
  detail::FieldTryDoReset(this->TxtIO);
}
TTypeSys::TTypeSys()
{
  DoReset();
}
TTypeSys::TTypeSys(TTypeSys&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeSys::operator=(TTypeSys&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->BinIO=std::move(_Right.BinIO);;
  this->TxtIO=std::move(_Right.TxtIO);;
}
string TTypeSys::ProxySys$$::GetFullName()
{
  return "TTypeSys";
}
void TTypeSys::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
TTypeSys::~TTypeSys()
{
  if (BinIO||TxtIO)
  {
    QapDebugMsg("bad idea");
  }
  BinIO=nullptr;
  TxtIO=nullptr;
}
TType*TTypeSys::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeSys::SelfClass*TTypeSys::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeVector::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->SizeType);
  detail::FieldTryDoReset(this->ElementType);
  detail::FieldTryDoReset(this->VecAPI);
}
TTypeVector::TTypeVector()
{
  DoReset();
}
TTypeVector::TTypeVector(TTypeVector&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeVector::operator=(TTypeVector&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->SizeType=std::move(_Right.SizeType);;
  this->ElementType=std::move(_Right.ElementType);;
  this->VecAPI=std::move(_Right.VecAPI);;
}
string TTypeVector::ProxySys$$::GetFullName()
{
  return "TTypeVector";
}
void TTypeVector::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeVector::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeVector::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+">");
}
TType*TTypeVector::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeVector::SelfClass*TTypeVector::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeArray::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->Size)=(0);
  detail::FieldTryDoReset(this->ElementType);
}
TTypeArray::TTypeArray()
{
  DoReset();
}
TTypeArray::TTypeArray(TTypeArray&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeArray::operator=(TTypeArray&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->Size=std::move(_Right.Size);;
  this->ElementType=std::move(_Right.ElementType);;
}
string TTypeArray::ProxySys$$::GetFullName()
{
  return "TTypeArray";
}
void TTypeArray::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeArray::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeArray::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+","+IToS(Size)+">");
}
TType*TTypeArray::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeArray::SelfClass*TTypeArray::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeFactory::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
  detail::FieldTryDoReset(this->SubType);
  detail::FieldTryDoReset(this->SmartType);
}
TTypeFactory::TTypeFactory()
{
  DoReset();
}
TTypeFactory::TTypeFactory(TTypeFactory&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeFactory::operator=(TTypeFactory&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
  this->SubType=std::move(_Right.SubType);;
  this->SmartType=std::move(_Right.SmartType);;
}
string TTypeFactory::ProxySys$$::GetFullName()
{
  return "TTypeFactory";
}
void TTypeFactory::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeFactory::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeFactory::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+">");
}
TType*TTypeFactory::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TType*TTypeFactory::GetSubType()const
{
  return SubType?SubType.get():nullptr;
}
void QapSysMember::DoReset()
{
  {
    ;
  }
  (this->Name)=("unnamed");
  detail::FieldTryDoReset(this->Type);
}
QapSysMember::QapSysMember()
{
  DoReset();
}
QapSysMember::QapSysMember(QapSysMember&&_Right)
{
  operator=(std::move(_Right));
}
void QapSysMember::operator=(QapSysMember&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Name=std::move(_Right.Name);;
  this->Type=std::move(_Right.Type);;
}
string QapSysMember::ProxySys$$::GetFullName()
{
  return "QapSysMember";
}
void QapSysMember::set(const string&Name,TType*Type)
{
  this->Name=Name;
  this->Type=Type;
}
void TTypeSelfPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
  detail::FieldTryDoReset(this->mSaveID);
}
TTypeSelfPtr::TTypeSelfPtr()
{
  DoReset();
}
TTypeSelfPtr::TTypeSelfPtr(TTypeSelfPtr&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeSelfPtr::operator=(TTypeSelfPtr&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
  this->mSaveID=std::move(_Right.mSaveID);;
}
string TTypeSelfPtr::ProxySys$$::GetFullName()
{
  return "TTypeSelfPtr";
}
void TTypeSelfPtr::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeSelfPtr::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeSelfPtr::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+">");
}
TType*TTypeSelfPtr::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeSelfPtr::SelfClass*TTypeSelfPtr::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeAutoPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
  detail::FieldTryDoReset(this->mType);
}
TTypeAutoPtr::TTypeAutoPtr()
{
  DoReset();
}
TTypeAutoPtr::TTypeAutoPtr(TTypeAutoPtr&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeAutoPtr::operator=(TTypeAutoPtr&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
  this->mType=std::move(_Right.mType);;
}
string TTypeAutoPtr::ProxySys$$::GetFullName()
{
  return "TTypeAutoPtr";
}
void TTypeAutoPtr::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeAutoPtr::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeAutoPtr::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+">");
}
TType*TTypeAutoPtr::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeAutoPtr::SelfClass*TTypeAutoPtr::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeWeakPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
  detail::FieldTryDoReset(this->mSaveID);
}
TTypeWeakPtr::TTypeWeakPtr()
{
  DoReset();
}
TTypeWeakPtr::TTypeWeakPtr(TTypeWeakPtr&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeWeakPtr::operator=(TTypeWeakPtr&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
  this->mSaveID=std::move(_Right.mSaveID);;
}
string TTypeWeakPtr::ProxySys$$::GetFullName()
{
  return "TTypeWeakPtr";
}
void TTypeWeakPtr::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeWeakPtr::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeWeakPtr::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+">");
}
TType*TTypeWeakPtr::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeWeakPtr::SelfClass*TTypeWeakPtr::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeHardPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
  detail::FieldTryDoReset(this->mSaveID);
}
TTypeHardPtr::TTypeHardPtr()
{
  DoReset();
}
TTypeHardPtr::TTypeHardPtr(TTypeHardPtr&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeHardPtr::operator=(TTypeHardPtr&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
  this->mSaveID=std::move(_Right.mSaveID);;
}
string TTypeHardPtr::ProxySys$$::GetFullName()
{
  return "TTypeHardPtr";
}
void TTypeHardPtr::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeHardPtr::GetElementName()
{
  return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));
}
string TTypeHardPtr::GetFullName()
{
  return std::move(Info.Name+"<"+GetElementName()+">");
}
TType*TTypeHardPtr::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeHardPtr::SelfClass*TTypeHardPtr::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeVoidPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->mType);
  detail::FieldTryDoReset(this->mPtr);
}
TTypeVoidPtr::TTypeVoidPtr()
{
  DoReset();
}
TTypeVoidPtr::TTypeVoidPtr(TTypeVoidPtr&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeVoidPtr::operator=(TTypeVoidPtr&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->mType=std::move(_Right.mType);;
  this->mPtr=std::move(_Right.mPtr);;
}
string TTypeVoidPtr::ProxySys$$::GetFullName()
{
  return "TTypeVoidPtr";
}
void TTypeVoidPtr::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeVoidPtr::GetFullName()
{
  return Info.Name;
}
TType*TTypeVoidPtr::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeVoidPtr::SelfClass*TTypeVoidPtr::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeFieldPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->mObject);
  detail::FieldTryDoReset(this->mType);
  detail::FieldTryDoReset(this->mOffset);
  detail::FieldTryDoReset(this->mIndex);
}
TTypeFieldPtr::TTypeFieldPtr()
{
  DoReset();
}
TTypeFieldPtr::TTypeFieldPtr(TTypeFieldPtr&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeFieldPtr::operator=(TTypeFieldPtr&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->mObject=std::move(_Right.mObject);;
  this->mType=std::move(_Right.mType);;
  this->mOffset=std::move(_Right.mOffset);;
  this->mIndex=std::move(_Right.mIndex);;
}
string TTypeFieldPtr::ProxySys$$::GetFullName()
{
  return "TTypeFieldPtr";
}
void TTypeFieldPtr::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeFieldPtr::GetFullName()
{
  return Info.Name;
}
TType*TTypeFieldPtr::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TTypeFieldPtr::SelfClass*TTypeFieldPtr::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
void TTypeStruct::Member::DoReset()
{
  {
    ;
  }
  (this->Name)=("unnamed");
  (this->Offset)=(0);
  detail::FieldTryDoReset(this->Type);
  detail::FieldTryDoReset(this->Mode);
  detail::FieldTryDoReset(this->Value);
}
TTypeStruct::Member::Member()
{
  DoReset();
}
TTypeStruct::Member::Member(Member&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeStruct::Member::operator=(Member&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Name=std::move(_Right.Name);;
  this->Offset=std::move(_Right.Offset);;
  this->Type=std::move(_Right.Type);;
  this->Mode=std::move(_Right.Mode);;
  this->Value=std::move(_Right.Value);;
}
string TTypeStruct::Member::ProxySys$$::GetFullName()
{
  return "Member";
}
void*TTypeStruct::Member::getValue(void*pValue)
{
  return (void*)(Offset+int(pValue));
}
void TTypeStruct::TExtInfo::DoReset()
{
  {
    ;
  }
  (this->SelfId)=(-1);
  detail::FieldTryDoReset(this->SpecInfo);
  (this->Polymorph)=(false);
  (this->Abstract)=(false);
  (this->PoorDesign)=(false);
}
TTypeStruct::TExtInfo::TExtInfo()
{
  DoReset();
}
TTypeStruct::TExtInfo::TExtInfo(TExtInfo&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeStruct::TExtInfo::operator=(TExtInfo&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->SelfId=std::move(_Right.SelfId);;
  this->SpecInfo=std::move(_Right.SpecInfo);;
  this->Polymorph=std::move(_Right.Polymorph);;
  this->Abstract=std::move(_Right.Abstract);;
  this->PoorDesign=std::move(_Right.PoorDesign);;
}
string TTypeStruct::TExtInfo::ProxySys$$::GetFullName()
{
  return "TExtInfo";
}
void TTypeStruct::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->SubType);
  detail::FieldTryDoReset(this->OwnType);
  detail::FieldTryDoReset(this->Members);
  detail::FieldTryDoReset(this->Nesteds);
  detail::FieldTryDoReset(this->extInfo);
}
TTypeStruct::TTypeStruct()
{
  DoReset();
}
TTypeStruct::TTypeStruct(TTypeStruct&&_Right)
{
  operator=(std::move(_Right));
}
void TTypeStruct::operator=(TTypeStruct&&_Right)
{
  struct hidden
  {
    static void foo(TType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    TType::operator=(std::move(_Right));;
  }
  this->SubType=std::move(_Right.SubType);;
  this->OwnType=std::move(_Right.OwnType);;
  this->Members=std::move(_Right.Members);;
  this->Nesteds=std::move(_Right.Nesteds);;
  this->extInfo=std::move(_Right.extInfo);;
}
string TTypeStruct::ProxySys$$::GetFullName()
{
  return "TTypeStruct";
}
void TTypeStruct::Use(IVisitorRTTI&A)
{
  A.Do(this);
}
string TTypeStruct::GetElementName(THardPtr<TType>&ElementType)
{
  return std::move(ElementType?ElementType->GetFullName()+"::":"");
}
string TTypeStruct::GetFullName()
{
  return std::move(GetElementName(OwnType)+Info.Name);
}
string TTypeStruct::GetDebugInfo()
{
  string fn=GetFullName();
  string code;
  auto&arr=Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    code+=(i?",":"")+ex.Name;
  }
  return fn+"={"+code+"}";
}
bool TTypeStruct::TestField(const Member&it,int depth)
{
  QapAssert((it.Mode=="DEF")||(it.Mode=="SET"));
  if (it.Mode=="DEF")do
    {
      auto*pFieldType=TTypeSys::UberCast(it.Type.get());
      if (!pFieldType)break;
      string ftfn=pFieldType->GetFullName();
      static const vector<string> white_list=split("bool|uint|int|float|real|char|uchar|string","|");
      bool white=false;
      for (int i=0;i<white_list.size();i++)
      {
        white=white||(ftfn==white_list[i]);
      }
      if (white)break;
      string fn=GetFullName();
      QapDebugMsg("field - \""+fn+"\"::"+it.Name+"\" has illegal DEF mode");
    }
    while (false);
  if (SubType)
  {
    auto*pSubType=TTypeStruct::UberCast(SubType.get());
    bool result=pSubType->TestField(it,depth+1);
    if (!result)return result;
  }
  auto&arr=Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    int cmp_id=0;
    static string idToStr[]={"Name","Offset",};
    const int cmp_n=lenof(idToStr)-(depth?1:0);
    do
    {
      if (cmp_id<cmp_n)
      {
        if (it.Name==ex.Name)break;
        cmp_id++;;
      }
      if (cmp_id<cmp_n)
      {
        if (it.Offset==ex.Offset)break;
        cmp_id++;;
      }
      ;
    }
    while (false);
    if (cmp_id!=cmp_n)
    {
      string tmp=idToStr[cmp_id];
      string fn=GetFullName();
      if (tmp=="Name")if (it.Name=="Self")if (fn=="QapWinProgram")continue;
      if ((-1==it.Offset)&&(-1==Info.Size))continue;
      QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
      return depth;
    }
  }
  return true;
}
TTypeStruct::SelfClass*TTypeStruct::UberCast(TType*ptr)
{
  return IVisitorRTTI::UberCast<SelfClass>(ptr);
}
TTypeStruct::Member*TTypeStruct::IsStruct::GetNearSelf(THardPtr<TType>&pType)
{
  if (!pType)return nullptr;
  TType*type=pType.get();
  return GetNearSelf(type);
}
TTypeStruct::Member*TTypeStruct::IsStruct::GetNearSelf(TType*type)
{
  if (!type)return nullptr;
  auto*tmp=UberCast(type);
  if (!tmp)
  {
    return GetNearSelf(type->GetSubType());
  }
  return tmp->GetNearSelf();
}
TTypeStruct::Member*TTypeStruct::IsStruct::MemberIndexByOffset::FieldInfo::get()
{
  if (!base)return nullptr;
  auto&it=base->Members[index];
  return &it;
}
bool TTypeStruct::IsStruct::MemberIndexByOffset::get(Input&in,Output&out)
{
  auto*base=UberCast(in.type);
  string in_ft_fn=in.fieldtype->GetFullName();
  if (base)
  {
    auto&arr=base->Members;
    for (int i=0;i<arr.size();i++,out.index++)
    {
      auto&it=arr[i];
      if (it.Offset!=in.offset)
      {
        TType*mt=it.Type.get();
        int mos=in.offset-it.Offset;
        Input input={mt,mos,in.fieldtype};
        bool result=get(input,out);
        if (!result)continue;
        return result;
      }
      auto*type=it.Type.get();
      {
        string type_fn=type->GetFullName();
        string base_fn=base->GetFullName();
        in_ft_fn=in_ft_fn;
      }
      if (type==in.fieldtype)
      {
        out.info.base=base;
        out.info.index=i;
        return true;
      }
      else
      {
        TType*mt=it.Type.get();
        int mos=in.offset-it.Offset;
        Input input={mt,mos,in.fieldtype};
        bool result=get(input,out);
        if (!result)continue;
        return result;
      }
      QapDebugMsg("breakpoint");
    }
  }
  if (!base&&in.type)
  {
    TType*SubType=in.type->GetSubType();
    if (SubType)
    {
      Input input={SubType,in.offset,in.fieldtype};
      return get(input,out);
    }
  }
  return false;
}
TTypeStruct::Member*TTypeStruct::GetNearSelf()
{
  return extInfo.SelfId<0?IsStruct::GetNearSelf(GetSubType()):&Members[extInfo.SelfId];
}
void TTypeStruct::AddField(Member&&field)
{
  QapAssert(field.Type);
  QapAssert(TestField(field));
  QapAssert(field.Type&&field.Type->Info.Align>0);
  if (field.Name=="Self")
  {
    if (true)do
      {
        auto*type=TTypeSelfPtr::UberCast(field.Type.get());
        QapAssert(type);
        if (this!=type->ElementType.get())
        {
          string fn=GetFullName();
          QapDebugMsg("field - \""+fn+"\"::"+field.Name+"\" has wrong type");
        }
      }
      while (false);
    if (GetNearSelf())do
      {
        auto*type=field.Type.get();
        auto*pSubType=TTypeStruct::UberCast(SubType.get());
        string fn=GetFullName();
        string subtype=pSubType->GetFullName();
        if ("QapWinProgram"==subtype)if ("eWinProgram"==fn)break;
        if ("QapWinProgram"==subtype)if ("QapProgramD3D9"==fn)break;
        QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
      }
      while (false);
    extInfo.SelfId=Members.size();
  }
  Members.push_back(std::move(field));
}
void TTypeStruct::AddMemberSET(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
{
  Member tmp;
  tmp.Type=MemType;
  tmp.Name=MemName;
  tmp.Offset=Offset;
  tmp.Mode=Mode;
  tmp.Value=Value;
  AddField(std::move(tmp));
}
void TTypeStruct::AddMemberDEF(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
{
  Member tmp;
  tmp.Type=MemType;
  tmp.Name=MemName;
  tmp.Offset=Offset;
  tmp.Mode=Mode;
  tmp.Value=Value;
  AddField(std::move(tmp));
}
void TTypeStruct::AddMemberSYS(...) {}
void TTypeStruct::AddMemberSYD(...) {}
void TTypeStruct::AddNested(TType*NestedType)
{
  Nesteds.push_back(NestedType);
}
vector<string>&TTypeStruct::get_white_list()
{
  static vector<string> arr;
  if (!arr.empty())return arr;
  string white_list[]=
  {
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
  for (int i=0;i<lenof(white_list);i++)
  {
    arr.push_back(white_list[i]);
  };
  return arr;
}
bool TTypeStruct::find_in_white_list(const string&type_fullname)
{
  auto&arr=get_white_list();
  for (int i=0;i<arr.size();i++)
  {
    if (arr[i]==type_fullname)return true;
  }
  return false;
}
void TTypeStruct::SelfTesting()
{
  static string all_messages;
  if (!Members.empty())
  {
    auto&front=Members.front();
    bool bad=!SubType&&front.Offset;
    bool mute=(extInfo.Polymorph&&!SubType)&&(front.Offset==Info.Align);
    if (bad)
    {
      string fn=this->GetFullName();
      string msg="\""+fn+"\" - offset of the first field of the type is "+IToS(front.Offset);
      all_messages+=msg+"\n";
      mute=mute||find_in_white_list(fn);
      if (!mute)QapDebugMsg(msg);
    }
  }
  if (!Members.empty())
  {
    auto&back=Members.back();
    int aligned_size=getAligned(back.Offset+back.Type->Info.Size,Info.Align);
    bool bad=aligned_size!=Info.Size;
    if (bad)
    {
      string fn=this->GetFullName();
      string msg="\""+fn+"\" - size of the type is "+IToS(Info.Size)+". expected aligned_size = "+IToS(aligned_size);
      all_messages+=msg+"\n";
      bool mute=find_in_white_list(fn);
      if (!mute)QapDebugMsg(msg);
    }
  }
  if (Members.empty())
  {
    int expected_size=0;
    {
      if (!SubType)
      {
        expected_size=1;
        if (extInfo.Polymorph)expected_size=Info.Align;
      }
      if (SubType)expected_size=SubType->Info.Size;
    }
    bool bad=expected_size!=Info.Size;
    if (bad)
    {
      string fn=this->GetFullName();
      string msg=(
            "\""+fn+"\" - size of the type is "+IToS(Info.Size)+"\n"
            "expected size: "+IToS(expected_size)+"\n"
            "PoorDesign?"
          );
      all_messages+=msg+"\n";
      bool mute=extInfo.PoorDesign||find_in_white_list(fn);
      if (!mute)QapDebugMsg(msg);
    }
  }
  if (OwnType&&!Nesteds.empty())
  {
    const string&parent=OwnType->Info.Name;
    auto&arr=Nesteds;
    for (int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if (parent!=ex->Info.Name)continue;
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
void TTypeStruct::Calc()
{
  QapAssert(Info.Size>0);
  QapAssert(Info.Align>0);
  auto*subtype=SubType.get();
  if (subtype)
  {
    QapAssert(subtype->Info.Size>0);
    QapAssert(subtype->Info.Align>0);
  }
  auto&arr=Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    auto*type=ex.Type.get();
    QapAssert(type->Info.Size>0);
    QapAssert(type->Info.Align>0);
    QapAssert(ex.Offset>=0);
  }
  int gfdsq=0;
}
int TTypeStruct::getAligned(int offset,int align)
{
  QapAssert(offset>=0);
  int x=offset%align;
  return offset+(x?align-x:0);
}
void TTypeStruct::ReCalcMembersOffset()
{
  int Offset=0;
  int MaxAlign=0;
  auto*subtype=SubType.get();
  if (subtype)
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
  for (int i=0;i<arr.size();i++)
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
TType*TTypeStruct::GetMetaType(IEnvRTTI&Env)
{
  return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
}
TType*TTypeStruct::GetSubType()const
{
  return SubType?SubType.get():nullptr;
}
bool TTypeStruct::IsEqual(TTypeStruct*type)
{
  if (Members.size()!=type->Members.size())return false;
  for (int i=0;i<Members.size();i++)
  {
    auto&it=Members[i];
    auto&ex=type->Members[i];
    if (it.Type.get()!=ex.Type.get())do
      {
        const int&id1=it.Type->Self.P.SaveID;
        const int&id2=ex.Type->Self.P.SaveID;
        if ((id1&&id2)&&(id1==id2))break;
        return false;
      }
      while (false);
    int cmp_id=0;
    static string idToStr[]={"Name", "Mode",};
    static const int cmp_n=lenof(idToStr);
    do
    {
      if (it.Name!=ex.Name)break;
      cmp_id++;;
      if (it.Mode!=ex.Mode)break;
      cmp_id++;
    }
    while (false);
    if (cmp_id!=cmp_n)
    {
      string tmp=idToStr[cmp_id];
      QapDebugMsg("wrong "+tmp+" in "+GetFullName()+"::"+it.Name);
      return false;
    }
  }
  return true;
}
bool TTypeStruct::hasMember(const string&name)
{
  auto arr=qap_find(Members,[&name](Member&ex)
  {
    return ex.Name==name;
  }
                   );
  if (arr.size()>1)
  {
    QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);
    return true;
  }
  return !arr.empty();
}
TTypeStruct::Member&TTypeStruct::unsafe_find_member(const string&name)
{
  auto arr=qap_find(Members,[&name](Member&ex)
  {
    return ex.Name==name;
  }
                   );
  if (arr.size()!=1)
  {
    QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);
    return *(Member*)nullptr;
  }
  return Members[arr[0]];
}
TTypeStruct::Member*TTypeStruct::find_member(const string&name)
{
  auto arr=qap_find(Members,[&name](Member&ex)
  {
    return ex.Name==name;
  }
                   );
  if (arr.empty())return nullptr;
  if (arr.size()>1)
  {
    QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);
    return nullptr;
  }
  return &Members[arr[0]];
}
TTypeStruct::Member*TTypeStruct::find_member_full(const string&name)
{
  if (!SubType)return find_member(name);
  auto*pSubType=SubType.get();
  auto*p=TTypeStruct::UberCast(pSubType);
  if (!p)
  {
    QapDebugMsg("parent of type is not struct?\n"+GetFullName());
    return nullptr;
  }
  auto*fromSub=p->find_member_full(name);
  auto*fromThis=this->find_member(name);
  if (bool(fromSub)==bool(fromThis))
  {
    QapAssert(!fromSub&&!fromThis);
    return false;
  }
  return fromSub?fromSub:fromThis;
}
void IEsoteric::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
IEsoteric::IEsoteric()
{
  DoReset();
}
IEsoteric::IEsoteric(IEsoteric&&_Right)
{
  operator=(std::move(_Right));
}
void IEsoteric::operator=(IEsoteric&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string IEsoteric::ProxySys$$::GetFullName()
{
  return "IEsoteric";
}
TRawPtr::TRawPtr():pType(nullptr),pValue(nullptr) {}
TRawPtr::TRawPtr(TType*pType,void*pValue):pType(pType),pValue(pValue) {}
void TRawPtr::set(TType*pType,void*pValue)
{
  this->pType=pType;
  this->pValue=pValue;
}
void TRawPtr::setZero()
{
  pType=nullptr;
  pValue=nullptr;
}
bool TRawPtr::IsValid()
{
  return pType&&pValue;
}
void TVoidPtr::DoReset()
{
  {
    ;
  }
  (this->type)=(nullptr);
  (this->ptr)=(nullptr);
}
TVoidPtr::TVoidPtr()
{
  DoReset();
}
string TVoidPtr::ProxySys$$::GetFullName()
{
  return "TVoidPtr";
}
TVoidPtr::operator bool()const
{
  return bool(ptr);
}
void TVoidPtr::oper_set(SelfClass&&ref)
{
  off();
  type=std::move(ref.type);
  ptr=std::move(ref.ptr);
}
void TVoidPtr::operator=(SelfClass&&ref)
{
  oper_set(std::move(ref));
}
void TVoidPtr::off()
{
  type=nullptr;
  ptr=nullptr;
}
void TVoidPtr::operator=(const nullptr_t&null)
{
  off();
}
void TVoidPtr::mega_unsafe_connect(TType*pType,void*pValue)
{
  off();
  if (!pType||!pValue)return;
  auto*ex=TTypeStruct::IsStruct::GetNearSelf(pType);
  if (!ex)
  {
    string fn=pType->GetFullName();
    QapDebugMsg("field \""+fn+"::Self\" not found");
    return;
  }
  TSelfPtr<IEsoteric>*self=(TSelfPtr<IEsoteric>*)ex->getValue(pValue);
  this->ptr.P=&self->P;
  this->type=pType;
}
void TVoidPtr::mega_unsafe_connect(const TRawPtr&ptr)
{
  mega_unsafe_connect(ptr.pType,ptr.pValue);
}
SubFieldsInfo::OutDeviceEx::TMemberID::TMemberID(int id):id(id) {}
void SubFieldsInfo::OutDeviceEx::TMemberID::Use(IVisitor&A)
{
  A.Do(this);
}
void SubFieldsInfo::OutDeviceEx::TSubType::Use(IVisitor&A)
{
  A.Do(this);
}
SubFieldsInfo::OutDeviceEx::TContext::TContext():pCmd(nullptr),pType(nullptr),Offset(0),head(nullptr) {}
void SubFieldsInfo::OutDeviceEx::TCmdVisitor::Do(TMemberID*p)
{
  int id=p->id;
  TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
  QapAssert(pMetaType);
  auto&ex=pMetaType->Members[id];
  pContext->Offset+=ex.Offset;
  pContext->pType=ex.Type.get();
  pContext->head=&ex.Name;
}
void SubFieldsInfo::OutDeviceEx::TCmdVisitor::Do(TSubType*p)
{
  pContext->Offset=pContext->Offset;
  pContext->pType=pContext->pType->GetSubType();
  pContext->head=nullptr;
  QapAssert(pContext->pType);
}
void SubFieldsInfo::OutDeviceEx::TCmdOffsetVisitor::Do(TMemberID*p)
{
  int id=p->id;
  TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
  QapAssert(pMetaType);
  auto&ex=pMetaType->Members[id];
  pContext->Offset+=ex.Offset;
  pContext->pType=ex.Type.get();
}
void SubFieldsInfo::OutDeviceEx::TCmdOffsetVisitor::Do(TSubType*p)
{
  pContext->pType=pContext->pType->GetSubType();
}
void SubFieldsInfo::OutDeviceEx::push(DevCmd*pCmd)
{
  branch.push_back(Context);
  Context.pCmd=pCmd;
  if (pCmd)
  {
    TCmdVisitor CV;
    CV.pContext=&Context;
    pCmd->Use(CV);
  }
}
void SubFieldsInfo::OutDeviceEx::pop()
{
  Context=branch.back();
  branch.pop_back();
}
string SubFieldsInfo::OutDeviceEx::GetFullFieldNameByIdFromBranch(int id)
{
  string path;
  for (int i=id;i<branch.size();i++)
  {
    auto&ex=branch[i];
    if (ex.head)path+=*ex.head+".";
  }
  if (Context.head)
  {
    path+=*Context.head;
  }
  else if (!path.empty()&&(path.back()=='.'))
  {
    path.pop_back();
  }
  return std::move(path);
}
int SubFieldsInfo::OutDeviceEx::GetRelativeFieldOffsetByIdFromBranch(int id)
{
  TType*pType=nullptr;
  {
    auto&ex=branch[id];
    pType=ex.pType;
  }
  TCmdOffsetVisitor::TContext Context={pType,0};
  TCmdOffsetVisitor COV;
  COV.pContext=&Context;
  for (int i=id+1;i<branch.size();i++)
  {
    auto&ex=branch[i];
    if (!ex.pCmd)return -1;
    ex.pCmd->Use(COV);
  }
  if (!this->Context.pCmd)
  {
    return -1;
  }
  this->Context.pCmd->Use(COV);
  return Context.Offset;
}
void SubFieldsInfo::TOffsetVerifier::TFieldInfo::setZero()
{
  this->Offset=0;
  this->pType=nullptr;
}
SubFieldsInfo::TOffsetVerifier::IndexGetter::IndexGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1) {}
bool SubFieldsInfo::TOffsetVerifier::IndexGetter::Do(SelfClass&OV,TType*p)
{
  if (Result)return false;
  if (Info.Offset!=OV.Offset)return true;
  Result=bool(Info.pType==p);
  if (Result)Index=OV.Index;
  return !Result;
}
SubFieldsInfo::TOffsetVerifier::InfoGetter::InfoGetter(TFieldInfo&Info,int Index):Info(Info),Result(false),Index(Index) {}
bool SubFieldsInfo::TOffsetVerifier::InfoGetter::Do(SelfClass&OV,TType*p)
{
  if (Result)return false;
  if (OV.Index!=Index)return true;
  Info.Offset=OV.Offset;
  Info.pType=p;
  Result=true;
  return !Result;
}
SubFieldsInfo::TOffsetVerifier::FieldNameGetter::FieldNameGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1) {}
bool SubFieldsInfo::TOffsetVerifier::FieldNameGetter::Do(SelfClass&V,TType*p)
{
  if (Result)return false;
  if (Info.Offset!=V.Offset)return true;
  Result=bool(Info.pType==p);
  if (Result)
  {
    Index=V.Index;
    fieldname=V.dev.GetFullFieldNameByIdFromBranch(0);
  }
  return !Result;
}
SubFieldsInfo::TOffsetVerifier::TOffsetVerifier(TSaveDev&dev,ICallBack&CB,int Offset,int&Index):dev(dev),CB(CB),Offset(Offset),Index(Index) {}
SubFieldsInfo::TOffsetVerifier::TOffsetVerifier(SelfClass&owner,int Offset):dev(owner.dev),CB(owner.CB),Offset(Offset),Index(owner.Index)
{
  Index++;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeStruct*p)
{
  if (!CB.Do(*this,p))return;
  if (p->SubType)
  {
    TSaveDev::TSubType tmp;
    dev.push(&tmp);
    SelfClass next(*this,Offset);
    p->SubType->Use(next);
    dev.pop();
  }
  auto&arr=p->Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    TSaveDev::TMemberID tmp(i);
    dev.push(&tmp);
    SelfClass next(*this,Offset+ex.Offset);
    ex.Type->Use(next);
    dev.pop();
  }
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeSys*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeVector*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeArray*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeSelfPtr*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeAutoPtr*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeWeakPtr*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeHardPtr*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeVoidPtr*p)
{
  if (!CB.Do(*this,p))return;
}
void SubFieldsInfo::TOffsetVerifier::Do(TTypeFieldPtr*p)
{
  if (!CB.Do(*this,p))return;
}
string SubFieldsInfo::FieldInfoToFieldName(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
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
int SubFieldsInfo::FieldInfoToIndex(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
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
SubFieldsInfo::TOffsetVerifier::TFieldInfo SubFieldsInfo::IndexToFieldInfo(TType*pType,int Index)
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
void TFieldPtr::DoReset()
{
  {
    ;
  }
  (this->object)=(nullptr);
  (this->type)=(nullptr);
  (this->offset)=(-1);
}
TFieldPtr::TFieldPtr()
{
  DoReset();
}
string TFieldPtr::ProxySys$$::GetFullName()
{
  return "TFieldPtr";
}
void TFieldPtr::off()
{
  object=nullptr;
  type=nullptr;
  offset=-1;
}
TFieldPtr::operator bool()
{
  return object;
}
void*TFieldPtr::getValue()
{
  void*pValue=object.ptr.get();
  return TTypeStruct::AddOffset(pValue,offset);
}
TType*TFieldPtr::getType()
{
  if (!object)return nullptr;
  if (!type)return nullptr;
  return type.get();
}
void TFieldPtr::TInfo::SetToField(TFieldPtr&Field)
{
  Field=*this;
}
TFieldPtr::TInfo::operator bool()const
{
  return pValue&&pType&&pFieldType&&(Offset>=0);
}
TFieldPtr::TInfo::TInfo():pType(nullptr),pValue(nullptr),pFieldType(nullptr),Offset(-1) {}
void TFieldPtr::TInfo::set(TTypeStruct*pType,void*pValue,TType*pFieldType,int Offset)
{
  this->pType=pType;
  this->pValue=pValue;
  this->pFieldType=pFieldType;
  this->Offset=Offset;
}
void TFieldPtr::TInfo::GrabFrom(TFieldPtr&FP)
{
  this->pType=TTypeStruct::UberCast(FP.object.type.get());
  this->pValue=FP.object.ptr.get();
  this->pFieldType=FP.type.get();
  this->Offset=FP.offset;
}
void TFieldPtr::oper_set(SelfClass&&ref)
{
  off();
  object=std::move(ref.object);
  type=std::move(ref.type);
  offset=std::move(ref.offset);
  ref.offset=-1;
}
void TFieldPtr::operator=(SelfClass&&ref)
{
  oper_set(std::move(ref));
}
TFieldPtr::TFieldPtr(SelfClass&&ref)
{
  oper_set(std::move(ref));
}
void TFieldPtr::operator=(const TInfo&ref)
{
  off();
  if (!ref)return;
  bool result=IsValid(ref.pType,ref.pFieldType,ref.Offset);
  if (!result)QapDebugMsg("WTF?");
  object.mega_unsafe_connect(ref.pType,ref.pValue);
  type=ref.pFieldType;
  offset=ref.Offset;
}
bool TFieldPtr::IsValid(TType*pType,TType*pFieldType,int Offset)
{
  SubFieldsInfo::TOffsetVerifier::TFieldInfo Info={pFieldType,Offset};
  return 0<=SubFieldsInfo::FieldInfoToIndex(pType,Info);
}
string vec2d::ProxySys$$::GetFullName()
{
  return "vec2d";
}
vec2d::vec2d():x(0.0),y(0.0) {}
vec2d::vec2d(const real&x,const real&y):x(x),y(y) {}
vec2d::vec2d(const vec2d&v):x(v.x),y(v.y) {}
void vec2d::operator=(const vec2d&v)
{
  x=v.x;
  y=v.y;
}
vec2d vec2d::operator+()const
{
  return *this;
}
vec2d vec2d::operator-()const
{
  return vec2d(-x,-y);
}
void vec2d::operator+=(const vec2d&v)
{
  x+=v.x;
  y+=v.y;
}
void vec2d::operator-=(const vec2d&v)
{
  x-=v.x;
  y-=v.y;
}
void vec2d::operator*=(const real&f)
{
  x*=f;
  y*=f;
}
void vec2d::operator/=(const real&f)
{
  x/=f;
  y/=f;
}
vec2d vec2d::Rot(const vec2d&OX)const
{
  real M=OX.Mag();
  return vec2d(((x*+OX.x)+(y*OX.y))/M,((x*-OX.y)+(y*OX.x))/M);
}
vec2d vec2d::UnRot(const vec2d&OX)const
{
  real M=OX.Mag();
  if (M==0.0f)
  {
    return vec2d(0,0);
  }
  ;
  return vec2d(((x*OX.x)+(y*-OX.y))/M,((x*OX.y)+(y*+OX.x))/M);
}
vec2d vec2d::Ort()const
{
  return vec2d(-y,x);
}
vec2d vec2d::Norm()const
{
  if ((x==0)&&(y==0))
  {
    return vec2d(0,0);
  }
  return vec2d(x/this->Mag(),y/this->Mag());
}
vec2d vec2d::SetMag(const real&val)const
{
  return this->Norm()*val;
}
vec2d vec2d::Mul(const vec2d&v)const
{
  return vec2d(x*v.x,y*v.y);
}
vec2d vec2d::Div(const vec2d&v)const
{
  return vec2d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y);
}
real vec2d::GetAng()const
{
  return atan2(y,x);
}
real vec2d::Mag()const
{
  return sqrt(x*x+y*y);
}
real vec2d::SqrMag()const
{
  return x*x+y*y;
}
vec2d operator+(const vec2d&u,const vec2d&v)
{
  return vec2d(u.x+v.x,u.y+v.y);
}
vec2d operator-(const vec2d&u,const vec2d&v)
{
  return vec2d(u.x-v.x,u.y-v.y);
}
vec2d operator*(const vec2d&u,const real&v)
{
  return vec2d(u.x*v,u.y*v);
}
vec2d operator*(const real&u,const vec2d&v)
{
  return vec2d(u*v.x,u*v.y);
}
bool operator==(const vec2d&u,const vec2d&v)
{
  return (u.x==v.x)&&(u.y==v.y);
}
bool operator!=(const vec2d&u,const vec2d&v)
{
  return (u.x!=v.x)||(u.y!=v.y);
}
real dot(const vec2d&a,const vec2d&b)
{
  return a.x*b.x+a.y*b.y;
}
real cross(const vec2d&a,const vec2d&b)
{
  return a.x*b.y-a.y*b.x;
}
string QapColor::ProxySys$$::GetFullName()
{
  return "QapColor";
}
QapColor::QapColor():b(255),g(255),r(255),a(255) {}
QapColor::QapColor(byte A,byte R,byte G,byte B):a(A),r(R),g(G),b(B) {}
QapColor::QapColor(byte R,byte G,byte B):a(255),r(R),g(G),b(B) {}
QapColor::QapColor(const QapColor& v):a(v.a),r(v.r),g(v.g),b(v.b) {}
QapColor&QapColor::operator=(const QapColor&v)
{
  a=v.a;
  r=v.r;
  g=v.g;
  b=v.b;
  return *this;
}
QapColor QapColor::operator+()const
{
  return *this;
}
QapColor&QapColor::operator*=(const QapColor&v)
{
  {
    a=Clamp(int(a)*int(v.a)/int(255),int(0),int(255));
  }
  {
    r=Clamp(int(r)*int(v.r)/int(255),int(0),int(255));
  }
  {
    g=Clamp(int(g)*int(v.g)/int(255),int(0),int(255));
  }
  {
    b=Clamp(int(b)*int(v.b)/int(255),int(0),int(255));
  }
  return *this;
}
QapColor&QapColor::operator+=(const QapColor&v)
{
  {
    a=Clamp(int(a)+int(v.a),int(0),int(255));
  }
  {
    r=Clamp(int(r)+int(v.r),int(0),int(255));
  }
  {
    g=Clamp(int(g)+int(v.g),int(0),int(255));
  }
  {
    b=Clamp(int(b)+int(v.b),int(0),int(255));
  }
  return *this;
}
QapColor&QapColor::operator-=(const QapColor&v)
{
  {
    a=Clamp(int(a)-int(v.a),int(0),int(255));
  }
  {
    r=Clamp(int(r)-int(v.r),int(0),int(255));
  }
  {
    g=Clamp(int(g)-int(v.g),int(0),int(255));
  }
  {
    b=Clamp(int(b)-int(v.b),int(0),int(255));
  }
  return *this;
}
QapColor QapColor::operator*(const QapColor&v)const
{
  return QapColor(int(int(a)*int(v.a))/int(255),int(int(r)*int(v.r))/int(255),int(int(g)*int(v.g))/int(255),int(int(b)*int(v.b))/int(255));
}
QapColor QapColor::operator+(const QapColor&v)const
{
  return QapColor(Clamp(int(a)+int(v.a),int(0),int(255)),Clamp(int(r)+int(v.r),int(0),int(255)),Clamp(int(g)+int(v.g),int(0),int(255)),Clamp(int(b)+int(v.b),int(0),int(255)));
}
QapColor QapColor::operator-(const QapColor&v)const
{
  return QapColor(Clamp(int(a)-int(v.a),int(0),int(255)),Clamp(int(r)-int(v.r),int(0),int(255)),Clamp(int(g)-int(v.g),int(0),int(255)),Clamp(int(b)-int(v.b),int(0),int(255)));
}
QapColor&QapColor::operator*=(real f)
{
  {
    b=byte(Clamp(real(b)*f,0.0,255.0));
  }
  ;
  {
    g=byte(Clamp(real(g)*f,0.0,255.0));
  }
  ;
  {
    r=byte(Clamp(real(r)*f,0.0,255.0));
  }
  ;
  return *this;
}
QapColor&QapColor::operator/=(real r)
{
  real f=1.0/r;
  {
    b=byte(Clamp(real(b)*f,0.0,255.0));
  }
  ;
  {
    g=byte(Clamp(real(g)*f,0.0,255.0));
  }
  ;
  {
    r=byte(Clamp(real(r)*f,0.0,255.0));
  }
  ;
  return *this;
}
QapColor::QapColor(const D3DCOLOR& v)
{
  *((D3DCOLOR*)(void*)this)=v;
}
QapColor::operator D3DCOLOR&()const
{
  return *(DWORD*)this;
}
QapColor::byte QapColor::GetLuminance()
{
  return int(int(r)+int(g)+int(b))/int(3);
}
QapColor QapColor::Mix(const QapColor&A,const QapColor&B,const real&t)
{
  real ct=Clamp(t,0.0,1.0);
  real tA=1.0-ct;
  real tB=ct;
  QapColor O;
  {
    O.b=byte(Clamp(real(A.b)*tA+real(B.b)*tB,0.0,255.0));
  }
  {
    O.g=byte(Clamp(real(A.g)*tA+real(B.g)*tB,0.0,255.0));
  }
  {
    O.r=byte(Clamp(real(A.r)*tA+real(B.r)*tB,0.0,255.0));
  }
  {
    O.a=byte(Clamp(real(A.a)*tA+real(B.a)*tB,0.0,255.0));
  }
  return O;
}
QapColor QapColor::HalfMix(const QapColor&A,const QapColor&B)
{
  QapColor O;
  {
    O.b=(int(A.b)+int(B.b))>>1;
  }
  {
    O.g=(int(A.g)+int(B.g))>>1;
  }
  {
    O.r=(int(A.r)+int(B.r))>>1;
  }
  {
    O.a=(int(A.a)+int(B.a))>>1;
  }
  return O;
}
string vec4i::ProxySys$$::GetFullName()
{
  return "vec4i";
}
vec4i::vec4i():x(0),y(0),z(0),w(0) {}
vec4i::vec4i(int x,int y,int z,int w):x(x),y(y),z(z),w(w) {}
vec4i::vec4i(const QapColor&ref):x(ref.a),y(ref.r),z(ref.g),w(ref.b) {}
void vec4i::operator+=(const vec4i&v)
{
  x+=v.x;
  y+=v.y;
  z+=v.z;
  w+=v.w;
}
vec4i vec4i::operator*(const int&v)
{
  return vec4i(x*v,y*v,z*v,w*v);
}
vec4i vec4i::operator/(const int&v)
{
  return vec4i(x/v,y/v,z/v,w/v);
}
void vec4i::operator/=(const int&v)
{
  x/=v;
  y/=v;
  z/=v;
  w/=v;
}
void vec4i::operator>>=(const int&v)
{
  x>>=v;
  y>>=v;
  z>>=v;
  w>>=v;
}
vec4i vec4i::operator+(const vec4i&v)
{
  return vec4i(x+v.x,y+v.y,z+v.z,w+v.w);
}
QapColor vec4i::unsafe_but_fast_GetColor()
{
  QapAssert(x>=0&&x<256);
  QapAssert(y>=0&&y<256);
  QapAssert(z>=0&&z<256);
  QapAssert(w>=0&&w<256);
  return QapColor(x,y,z,w);
}
vec3f::vec3f():x(0),y(0),z(0) {}
vec3f::vec3f(float x,float y,float z):x(x),y(y),z(z) {}
vec4f::vec4f():b(1.0),g(1.0),r(1.0),a(1.0) {}
vec4f::vec4f(float b,float g,float r,float a):b(b),g(g),r(r),a(a) {}
vec4f::vec4f(const QapColor&ref):b(ref.b/255.f),g(ref.g/255.f),r(ref.r/255.f),a(ref.a/255.f) {}
vec4f&vec4f::operator+=(const vec4f&v)
{
  b+=v.b;
  g+=v.g;
  r+=v.r;
  a+=v.a;
  return *this;
}
vec4f operator*(const float&u,const vec4f&v)
{
  return vec4f(u*v.b,u*v.g,u*v.r,u*v.a);
}
vec4f operator+(const vec4f&u,const vec4f&v)
{
  return vec4f(u.b+v.b,u.g+v.g,u.r+v.r,u.a+v.a);
}
QapColor vec4f::GetColor()
{
  return QapColor(Clamp(int(a*255),int(0),int(255)),Clamp(int(r*255),int(0),int(255)),Clamp(int(g*255),int(0),int(255)),Clamp(int(b*255),int(0),int(255)));
}
string vec2f::ProxySys$$::GetFullName()
{
  return "vec2f";
}
vec2f::vec2f():x(0),y(0) {}
vec2f::vec2f(const vec2d&v)
{
  x=v.x;
  y=v.y;
}
vec2f::vec2f(float x,float y):x(x),y(y) {}
void vec2f::set_zero()
{
  x=0.0f;
  y=0.0f;
}
vec2f operator*(const vec2f&u,const float&v)
{
  return vec2f(u.x*v,u.y*v);
}
vec2f operator*(const float&u,const vec2f&v)
{
  return vec2f(u*v.x,u*v.y);
}
vec2f operator+(const vec2f&u,const vec2f&v)
{
  return vec2f(u.x+v.x,u.y+v.y);
}
vec2f operator-(const vec2f&u,const vec2f&v)
{
  return vec2f(u.x-v.x,u.y-v.y);
}
void vec2f::operator+=(const vec2d&v)
{
  x+=v.x;
  y+=v.y;
}
void vec2f::operator-=(const vec2d&v)
{
  x-=v.x;
  y-=v.y;
}
vec2f operator*(float u,const vec2f&v)
{
  return vec2f(u*v.x,u*v.y);
}
vec2f::operator vec2d()const
{
  return vec2d(x,y);
}
string vec2i::ProxySys$$::GetFullName()
{
  return "vec2i";
}
vec2i::vec2i():x(0),y(0) {}
vec2i::vec2i(int x,int y):x(x),y(y) {}
vec2i operator*(int u,const vec2i&v)
{
  return vec2i(u*v.x,u*v.y);
}
vec2i operator*(const vec2i&v,int u)
{
  return vec2i(u*v.x,u*v.y);
}
vec2i operator/(const vec2i&v,int d)
{
  return vec2i(v.x/d,v.y/d);
}
vec2i operator+(const vec2i&u,const vec2i&v)
{
  return vec2i(u.x+v.x,u.y+v.y);
}
vec2i operator-(const vec2i&u,const vec2i&v)
{
  return vec2i(u.x-v.x,u.y-v.y);
}
void vec2i::operator+=(const vec2i&v)
{
  x+=v.x;
  y+=v.y;
}
void vec2i::operator-=(const vec2i&v)
{
  x-=v.x;
  y-=v.y;
}
vec2i vec2i::Mul(const vec2i&v)const
{
  return vec2i(x*v.x,y*v.y);
}
int vec2i::SqrMag()
{
  return x*x+y*y;
}
float vec2i::Mag()
{
  return sqrt(float(x*x+y*y));
}
vec2i vec2i::abs()
{
  return vec2i(std::abs(x),std::abs(y));
}
bool vec2i::dist_less(const vec2i&point,int dist)
{
  return (point-*this).SqrMag()<dist*dist;
}
vec2i::operator vec2d()const
{
  return vec2d(x,y);
}
vec2i::operator vec2f()const
{
  return vec2f(x,y);
}
vec2i vec2i::operator+()const
{
  return vec2i(+x,+y);
}
vec2i vec2i::operator-()const
{
  return vec2i(-x,-y);
}
bool operator==(const vec2i&u,const vec2i&v)
{
  return (u.x==v.x)&&(u.y==v.y);
}
bool operator!=(const vec2i&u,const vec2i&v)
{
  return (u.x!=v.x)||(u.y!=v.y);
}
Dip2i::Dip2i(int a,int b):a(a),b(b) {}
void Dip2i::Take(int x)
{
  a=min(a,x);
  b=max(b,x);
}
Dip2i Dip2i::Norm()const
{
  return Dip2i(min(a,b),max(a,b));
}
int Dip2i::Mag()const
{
  return b-a;
}
Dip2i::Transform::Transform(float x,float s):x(x),s(s) {}
Dip2i::Transform::Transform(const Dip2i&from,const Dip2i&to)
{
  s=float(to.Norm().Mag())/float(from.Norm().Mag());
  x=to.a-from.a;
}
float Dip2i::Transform::operator*(int v)
{
  return x+v*s;
}
rot2f::rot2f():s(0.0f),c(1.0f) {}
rot2f::rot2f(float ang)
{
  set(ang);
}
void rot2f::set(float ang)
{
  s=sinf(ang);
  c=cosf(ang);
}
void rot2f::set_ident()
{
  s=0.0f;
  c=1.0f;
}
float rot2f::GetAng()const
{
  return std::atan2(s,c);
}
vec2f rot2f::GetXAxis()const
{
  return vec2f(+c,+s);
}
vec2f rot2f::GetYAxis()const
{
  return vec2f(-s,+c);
}
vec2f operator*(const rot2f&q,const vec2d&v)
{
  return vec2f(q.c*v.x-q.s*v.y,q.s*v.x+q.c*v.y);
}
QapMat22::QapMat22():col1(1,0),col2(0,1) {}
QapMat22::QapMat22(const vec2f&c1,const vec2f&c2)
{
  col1=c1;
  col2=c2;
}
QapMat22::QapMat22(float a11,float a12,float a21,float a22)
{
  col1.x=a11;
  col1.y=a21;
  col2.x=a12;
  col2.y=a22;
}
QapMat22::QapMat22(float ang)
{
  float c=cosf(ang);
  float s=sinf(ang);
  col1.x=c;
  col2.x=-s;
  col1.y=s;
  col2.y=+c;
}
void QapMat22::set(const vec2f&c1,const vec2f&c2)
{
  col1=c1;
  col2=c2;
}
void QapMat22::set(float ang)
{
  float c=cosf(ang);
  float s=sinf(ang);
  col1.x=c;
  col2.x=-s;
  col1.y=s;
  col2.y=+c;
}
void QapMat22::set_ident()
{
  col1.x = 1.0f;
  col2.x = 0.0f;
  col1.y = 0.0f;
  col2.y = 1.0f;
}
void QapMat22::set_zero()
{
  col1.x = 0.0f;
  col2.x = 0.0f;
  col1.y = 0.0f;
  col2.y = 0.0f;
}
float QapMat22::GetAngle()const
{
  return atan2(col1.y, col1.x);
}
transform2f::transform2f() {}
transform2f::transform2f(const vec2f&p,const QapMat22&r):p(p),r(r) {}
transform2f::transform2f(const vec2f&p):p(p) {}
void transform2f::set_ident()
{
  p.set_zero();
  r.set_ident();
}
void transform2f::set(const vec2d&p,float ang)
{
  this->p=p;
  this->r.set(ang);
}
float transform2f::getAng()const
{
  return atan2(r.col1.y,r.col1.x);
}
vec2f operator*(const transform2f&T,const vec2f&v)
{
  float x=(+T.r.col1.x*v.x+T.r.col2.x*v.y)+T.p.x;
  float y=(+T.r.col1.y*v.x+T.r.col2.y*v.y)+T.p.y;
  return vec2f(x,y);
}
transform2f MakeZoomTransform(const vec2d&zoom)
{
  transform2f tmp(vec2f_zero,QapMat22(vec2f(zoom.x,0.f),vec2f(0.f,zoom.y)));
  return tmp;
}
TLine::TLine() {}
TLine::TLine(const vec2d&A,const vec2d&B):A(A),B(B) {}
TLine::TLine(const real&ax,const real&ay,const real&bx,const real&by):ax(ax),ay(ay),bx(bx),by(by) {}
vec2d Vec2dEx(const real&ang,const real&mag)
{
  return vec2d(cos(ang)*mag,sin(ang)*mag);
}
real vec2d_cross(const vec2d&a,const vec2d&b)
{
  return a.x*b.y-a.y*b.x;
}
int round(const real&val)
{
  return int(val>=0?val+0.5:val-0.5);
}
vec2d PToV(const POINT&v)
{
  return vec2d(v.x,v.y);
}
TwoDeclareMetaType::TwoDeclareMetaType():pdTType(nullptr),pdDeclareType(nullptr) {}
void DeclareEnvType::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Type);
}
DeclareEnvType::DeclareEnvType()
{
  DoReset();
}
DeclareEnvType::DeclareEnvType(DeclareEnvType&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareEnvType::operator=(DeclareEnvType&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Type=std::move(_Right.Type);;
}
string DeclareEnvType::ProxySys$$::GetFullName()
{
  return "DeclareEnvType";
}
bool DeclareEnvType::IsEmpty(SelfClass&ref)
{
  return !bool(ref.Type);
}
void DeclareEnvRTTI::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Arr);
}
DeclareEnvRTTI::DeclareEnvRTTI()
{
  DoReset();
}
DeclareEnvRTTI::DeclareEnvRTTI(DeclareEnvRTTI&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareEnvRTTI::operator=(DeclareEnvRTTI&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Arr=std::move(_Right.Arr);;
}
string DeclareEnvRTTI::ProxySys$$::GetFullName()
{
  return "DeclareEnvRTTI";
}
DeclareEnvRTTI::TwoDeclareType::TwoDeclareType(const TwoDeclareType&Ref):pdTType(nullptr),pdDeclareType(nullptr)
{
  oper_set(Ref);
}
DeclareEnvRTTI::TwoDeclareType::TwoDeclareType():pdTType(nullptr),pdDeclareType(nullptr) {}
void DeclareEnvRTTI::TwoDeclareType::oper_set(const TwoDeclareType&Ref)
{
  this->pdTType=Ref.pdTType;
  this->pdDeclareType=Ref.pdDeclareType;
}
void DeclareEnvRTTI::TwoDeclareType::operator=(const TwoDeclareType&Ref)
{
  oper_set(Ref);
}
void DeclareEnvRTTI::GrabFrom(DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt)
{
  TDeclareEnvRTTI_WeakDetail<void>::GrabFrom(*this,Source,Space,tdmt);
}
void DeclareEnvRTTI::RetAll(TSpaceDependsTools&Tools)
{
  QapDebugMsg("no used?");
}
bool DeclareEnvRTTI::ApplyTo(TSpaceDependsTools&Tools,TSpace&tmpSpace)
{
  QapDebugMsg("no used?");
  return false;
}
EnvVoidPtr::EnvVoidPtr():ptr(nullptr),type(nullptr) {}
EnvVoidPtr::EnvVoidPtr(ptr_t*ptr,TType*type):ptr(ptr),type(type) {}
EnvVoidPtr::ptr_t::ptr_t*EnvVoidPtr::get()const
{
  return ptr?ptr->ptr:nullptr;
}
bool EnvVoidPtr::IsValid()const
{
  return bool(ptr)&&bool(type);
}
bool EnvVoidPtr::IsNull()const
{
  return bool(!ptr)&&bool(!type);
}
void EnvVoidPtr::set_zero()
{
  ptr=nullptr;
  type=nullptr;
}
bool EnvVoidPtr::operator==(const EnvVoidPtr&ref)const
{
  return oper_eq(ref);
}
bool EnvVoidPtr::operator!=(const EnvVoidPtr&ref)const
{
  return !oper_eq(ref);
}
bool EnvVoidPtr::oper_eq(const EnvVoidPtr&ref)const
{
  return (this->ptr==ref.ptr)&&(this->type==ref.type);
}
void EnvItem::DoReset()
{
  {
    ;
  }
  (this->id)=(0);
  detail::FieldTryDoReset(this->ptr);
  detail::FieldTryDoReset(this->ptr_lnk);
  (this->name)=("");
  (this->count)=(0);
  (this->passed)=(false);
  (this->system)=(false);
  (this->hidden)=(false);
}
EnvItem::EnvItem()
{
  DoReset();
}
EnvItem::EnvItem(EnvItem&&_Right)
{
  operator=(std::move(_Right));
}
void EnvItem::operator=(EnvItem&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->id=std::move(_Right.id);;
  this->ptr=std::move(_Right.ptr);;
  this->ptr_lnk=std::move(_Right.ptr_lnk);;
  this->name=std::move(_Right.name);;
  this->count=std::move(_Right.count);;
  this->passed=std::move(_Right.passed);;
  this->system=std::move(_Right.system);;
  this->hidden=std::move(_Right.hidden);;
}
string EnvItem::ProxySys$$::GetFullName()
{
  return "EnvItem";
}
EnvItem&EnvItem::copy(const EnvItem&source)
{
  this->id=source.id;
  this->name=source.name;
  this->ptr=source.ptr;
  this->ptr_lnk=source.ptr_lnk;
  this->count=source.count;
  this->passed=source.passed;
  this->system=source.system;
  this->hidden=source.hidden;
  return *this;
}
void EnvItem::CheckNullptr()
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
bool EnvItem::oper_eq(const SelfClass&ref,bool ignore_id)const
{
  bool result=ignore_id||(this->id==ref.id);
  result=result&&(this->name==ref.name);
  result=result&&(this->ptr==ref.ptr);
  result=result&&(this->ptr_lnk==ref.ptr_lnk);
  result=result&&(this->count==ref.count);
  result=result&&(this->passed==ref.passed);
  result=result&&(this->system==ref.system);
  result=result&&(this->hidden==ref.hidden);
  return result;
}
bool EnvItem::operator==(const SelfClass&ref)const
{
  return oper_eq(ref);
}
bool EnvItem::IsNoUsed()
{
  return id&&ptr.IsNull()&&ptr_lnk.IsNull();
}
void EnvItem::SetAsNullptr()
{
  name="nullptr";
  count=1;
  passed=true;
  system=true;
  hidden=false;
}
EnvItem&EnvItem::get_lnk(TServerPtrSpace&Space)const
{
  return weak_get_lnk<void>(Space);
}
int SpaceMutator::find_key_by_value(EnvVoidPtr::ptr_t*ptr)
{
  for (int i=0;i<arr.size();i++)
  {
    if (arr[i]==ptr)return i;
  }
  return -1;
}
bool SpaceMutator::has_value(EnvVoidPtr::ptr_t*ptr)
{
  return find_key_by_value(ptr)!=-1;
}
void TServerPtrSpace::operator=(SelfClass&&Ref)
{
  clear();
  Arr=std::move(Ref.Arr);
}
TServerPtrSpace::TServerPtrSpace(SelfClass&&Ref)
{
  clear();
  Arr=std::move(Ref.Arr);
}
TServerPtrSpace::TServerPtrSpace()
{
  Arr.reserve(1024*128);
  auto&ex=UnsafeAdd(nullptr,nullptr);
  ex.SetAsNullptr();
}
TServerPtrSpace::~TServerPtrSpace()
{
  clear();
}
void TServerPtrSpace::hack_clear()
{
  for (int i=0;i<Arr.size();i++)
  {
    Del(Arr[i],true);
  }
  Arr.clear();
}
void TServerPtrSpace::clear()
{
  for (int i=0;i<Arr.size();i++)
  {
    Del(Arr[i]);
  }
  Arr.clear();
}
void TServerPtrSpace::make_linked(EnvItem&a,EnvItem&b)
{
  bool f0=a.ptr_lnk.IsNull();
  bool f1=b.ptr_lnk.IsNull();
  QapAssert(f0&&f1);
  a.ptr_lnk=b.ptr;
  b.ptr_lnk=a.ptr;
}
bool TServerPtrSpace::CheckServTID(int tid)
{
  if (!IsAllowed(tid))return false;
  auto&item=Arr[tid];
  bool flag=true;
  flag=item.ptr.ptr;
  QapAssert(flag);
  flag=tid==item.ptr.ptr->SaveID;
  QapAssert(flag);
  return flag;
}
bool TServerPtrSpace::CheckServSaveID(TServerPtr<IEsoteric>*pServ)const
{
  QapAssert(pServ);
  int SaveID=pServ->SaveID;
  {
    bool flag=(SaveID>0)&&(SaveID<Arr.size());
    if (!flag)
    {
      QapAssert(!SaveID);
      return false;
    }
  }
  auto&ex=Arr[SaveID];
  bool flag=ex.ptr.ptr==pServ;
  QapAssert(flag);
  return flag;
}
EnvItem&TServerPtrSpace::UnsafeAdd(const EnvVoidPtr&ptr)
{
  int id=Arr.size();
  {
    if (id>=Arr.capacity())QapDebugMsg("grow are not allowed here.\n"+IToS(Arr.capacity()));
    EnvItem tmp;
    Arr.push_back(std::move(tmp));
  }
  auto&back=Arr.back();
  auto*pServ=ptr.ptr;
  if (pServ)pServ->SaveID=id;
  back.id=id;
  back.ptr=ptr;
  return back;
}
EnvItem&TServerPtrSpace::Insert(const EnvItem&item)
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
    if (!p)return;
    int&sid=p->SaveID;
    QapAssert(!sid);
    sid=id;
  };
  connect(back.ptr);
  return back;
}
EnvItem&TServerPtrSpace::InsertTo(int id,const EnvItem&item)
{
  auto&back=Arr[id];
  QapAssert(back.IsNoUsed());
  back.copy(item).id=id;
  auto connect=[id](EnvVoidPtr&ptr)->void
  {
    auto*p=ptr.ptr;
    if (!p)return;
    int&sid=p->SaveID;
    QapAssert(!sid);
    sid=id;
  };
  connect(back.ptr);
  return back;
}
EnvItem&TServerPtrSpace::UnsafeAdd(TServerPtr<IEsoteric>*pServ,TType*pType)
{
  return UnsafeAdd(EnvVoidPtr(pServ,pType));
}
EnvItem&TServerPtrSpace::AddExt(TServerPtr<IEsoteric>*pServ,TType*pType,const string&name)
{
  QapAssert(pServ);
  if (true)
  {
    bool flag=CheckServSaveID(pServ);
    if (flag)
    {
      QapAssert(false);
      return Arr[pServ->SaveID];
    }
  }
  auto&back=UnsafeAdd(pServ,pType);
  back.name=name;
  return back;
}
void TServerPtrSpace::Del(EnvItem&item,bool hack_mode)
{
  Del(item.ptr.ptr,hack_mode);
}
void TServerPtrSpace::Del(TServerPtr<IEsoteric>*pServ,bool hack_mode)
{
  if (!pServ)return;
  QapAssert(pServ->SaveID);
  {
    const int&id=pServ->SaveID;
    QapAssert(IsAllowed(id));
    auto&ex=Arr[id];
    QapAssert(ex.id==id);
    if (1)
    {
      bool f[]=
      {
        ex.ptr.ptr==pServ,
        ex.ptr_lnk.ptr==pServ
      };
      QapAssert(f[0]!=f[1]);
    }
    ex.ptr=nullptr;
    if (!hack_mode)if (ex.ptr_lnk.ptr)
      {
        QapAssert(ex.ptr_lnk.ptr->SaveID!=id);
      }
    ex.ptr_lnk=nullptr;
  }
  pServ->SaveID=0;
}
EnvVoidPtr::ptr_t*TServerPtrSpace::GetPtrByID(int id)
{
  return Arr[id].ptr.ptr;
}
EnvVoidPtr::ptr_t*TServerPtrSpace::GetAdvPtrByID(int id)
{
  return Arr[id].ptr_lnk.ptr;
}
EnvItem&TServerPtrSpace::operator[](int index)
{
  return Arr[index];
}
const EnvItem&TServerPtrSpace::operator[](int index)const
{
  return Arr[index];
}
bool TServerPtrSpace::IsAllowed(int index)
{
  return (0<=index)&&(index<Arr.size());
}
bool TServerPtrSpace::IsSolved(int index)
{
  return IsAllowed(index)&&(Arr[index].ptr.ptr);
}
int TServerPtrSpace::size()
{
  return Arr.size();
}
void TServerPtrSpace::resize(int count)
{
  QapAssert(count>=size());
  for (int i=size();i<count;i++)
  {
    UnsafeAdd(nullptr,nullptr);
  }
}
void TServerPtrSpace::Repack()
{
  typedef TServerPtrSpace TSpace;
  TSpace&Space=*this;
  TSpace tmpSpace=std::move(Space);
  for (int i=0;i<tmpSpace.size();i++)
  {
    auto&item=tmpSpace[i];
    if (!item.count)continue;
    {
      EnvItem temp;
      temp.copy(item);
      tmpSpace.Del(item);
      auto&back=Space.Insert(temp);
      QapAssert(&back==&Space[back.id]);
    }
  }
}
void TServerPtrSpace::RepackV2(SelfClass&Out)
{
  typedef TServerPtrSpace TSpace;
  TSpace&Space=*this;
  TSpace tmpSpace=std::move(Space);
  Space=std::move(TSpace());
  Out=std::move(TSpace());
  Out.resize(tmpSpace.size());
  int X=1;
  for (int i=1;i<tmpSpace.size();i++)if (tmpSpace[i].count)X++;
  for (int i=1;i<tmpSpace.size();i++)
  {
    auto&item=tmpSpace[i];
    if (!item.count)
    {
      auto&space=Out;
      EnvItem temp;
      temp.copy(item);
      tmpSpace.Del(item);
      auto&back=space.InsertTo(X,temp);
      QapAssert(&back==&space[back.id]);
      X++;
      continue;
    }
    if (item.count)
    {
      auto&space=Space;
      EnvItem temp;
      temp.copy(item);
      tmpSpace.Del(item);
      auto&back=space.Insert(temp);
      QapAssert(&back==&space[back.id]);
      continue;
    }
  }
}
void TServerPtrSpace::Mutate(SpaceMutator&SM)
{
  typedef TServerPtrSpace TSpace;
  TSpace&Space=*this;
  TSpace tmpSpace=std::move(Space);
  Space.reserve(tmpSpace.size());
  auto func=[&tmpSpace,&Space](int i)
  {
    auto&item=tmpSpace[i];
    if (item.id==-1)return;
    EnvItem temp;
    temp.copy(item);
    tmpSpace.Del(item);
    auto&back=Space.Insert(temp);
    QapAssert(&back==&Space[back.id]);
  };
  func(0);
  auto&arr=SM.arr;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    QapAssert(ex->SaveID);
    QapAssert(tmpSpace.IsAllowed(ex->SaveID));
    auto&item=tmpSpace[ex->SaveID];
    QapAssert(item.id>0);
    QapAssert(item.id==ex->SaveID);
    {
      EnvItem temp;
      temp.copy(item);
      tmpSpace.Del(item);
      item.id=-1;
      auto&back=Space.Insert(temp);
      QapAssert(&back==&Space[back.id]);
    }
  }
  for (int i=1;i<tmpSpace.size();i++)func(i);
}
void TServerPtrSpace::CopyAdvFrom(SelfClass&Source)
{
  QapDebugMsg("deprecated");
  auto&arr=Source.Arr;
  clear();
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (ex.ptr_lnk.IsNull())
    {
      EnvItem tmp;
      Insert(tmp);
      continue;
    }
    auto name=ex.name+"->getLink()";
    AddExt(ex.ptr_lnk.ptr,ex.ptr_lnk.type,name);
  }
}
void TServerPtrSpace::CopyAdvFromV2(SelfClass&Source,SelfClass&BigSpace)
{
  auto&arr=Source.Arr;
  (*this)=std::move(SelfClass());
  for (int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (ex.ptr_lnk.IsNull())
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
void TServerPtrSpace::Swap(int A,int B)
{
  if (A==B)return;
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
string TServerPtrSpace::GetListOfNoPassed(bool all)
{
  string log;
  auto&arr=Arr;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (!all)if (!ex.count||ex.passed)continue;
    log+=ex.name+"\n";
  }
  return log;
}
bool TServerPtrSpace::CheckHidden()
{
  int errors=0;
  auto&arr=Arr;
  for (int i=0;i<arr.size();i++)
  {
    auto&item=arr[i];
    if (item.hidden&&item.count)
    {
      QapDebugMsg("item(\""+item.name+"\").count = "+IToS(item.count));
      errors++;
    }
  }
  return !errors;
}
EnvItem*TServerPtrSpace::find_by_name(const string&name)
{
  for (int i=0;i<size();i++)
  {
    EnvItem&EX=Arr[i];
    if (name==EX.name)return &EX;
  }
  return nullptr;
}
bool TServerPtrSpace::IsValid()
{
  if (Arr.empty())
  {
    QapAssert("undefine behevior. also: may be true");
    return true;
  }
  Arr[0].CheckNullptr();
  for (int i=1;i<Arr.size();i++)
  {
    auto&item=Arr[i];
    if (!item.ptr.type&&!item.ptr.ptr)return false;
    if (1)
    {
      bool flag=bool(item.ptr_lnk.ptr)==bool(item.ptr_lnk.type);
      if (!flag)return false;
    }
  }
  return true;
}
void TServerPtrSpace::reserve(int _Count)
{
  Arr.reserve(_Count);
}
void TServerPtrSpace::AddPointsFromSys()
{
  weak_detail<void>::AddPointsFromSys(*this);
}
void TServerPtrSpace::AddPointsFromEnv(IEnvRTTI&Env)
{
  weak_detail<void>::AddPointsFromEnv(*this,Env);
}
void TServerPtrSpace::AddPointsFrom(const TRawPtr&ptr)
{
  weak_detail<void>::AddPointsFrom(*this,ptr);
}
void TServerPtrSpace::UpdatePointsTypeFrom(const TRawPtr&ptr)
{
  weak_detail<void>::UpdatePointsTypeFrom(*this,ptr);
}
void TBigMetaTypePack::DoReset()
{
  this->pEnvType=nullptr;;
  this->pTType=nullptr;;
  this->pTTypeStruct=nullptr;;
  this->pTTypeSys=nullptr;;
  this->pDeclareType=nullptr;;
  this->pDeclareTypeStruct=nullptr;;
  this->pDeclareTypeSys=nullptr;
}
TBigMetaTypePack::TBigMetaTypePack(const SelfClass&ref)
{
  DoReset();
  oper_set(ref);
}
TBigMetaTypePack::TBigMetaTypePack()
{
  DoReset();
}
TBigMetaTypePack::TBigMetaTypePack(IEnvRTTI&Env)
{
  DoReset();
  prepare(Env);
}
void TBigMetaTypePack::oper_set(const SelfClass&ref)
{
  this->pEnvType=ref.pEnvType;;
  this->pTType=ref.pTType;;
  this->pTTypeStruct=ref.pTTypeStruct;;
  this->pTTypeSys=ref.pTTypeSys;;
  this->pDeclareType=ref.pDeclareType;;
  this->pDeclareTypeStruct=ref.pDeclareTypeStruct;;
  this->pDeclareTypeSys=ref.pDeclareTypeSys;
}
void TBigMetaTypePack::operator=(const SelfClass&ref)
{
  oper_set(ref);
}
void EnvAdapter::TMetaTypePack::DoReset()
{
  this->pTType=nullptr;;
  this->pTTypeStruct=nullptr;; ;
}
EnvAdapter::TMetaTypePack::TMetaTypePack(const SelfClass&ref)
{
  DoReset();
  oper_set(ref);
}
EnvAdapter::TMetaTypePack::TMetaTypePack()
{
  DoReset();
}
EnvAdapter::TMetaTypePack::TMetaTypePack(IEnvRTTI&Env)
{
  DoReset();
  prepare(Env);
}
void EnvAdapter::TMetaTypePack::oper_set(const SelfClass&ref)
{
  this->pTType=ref.pTType;;
  this->pTTypeStruct=ref.pTTypeStruct;; ;
}
void EnvAdapter::TMetaTypePack::operator=(const SelfClass&ref)
{
  oper_set(ref);
}
TType*EnvAdapter::FindTypeByFactory(IEnvRTTI&Env,IFactory*pFactory)
{
  auto&arr=Env.GetArr();
  for (int i=0;i<arr.size();i++)
  {
    auto*pType=arr[i].Type.get();
    if (pType->Factory.get()==pFactory)return pType;
  }
  return nullptr;
}
TType*EnvAdapter::FindTypeByFactoryFast(IEnvRTTI&Env,TServerPtrSpace&Space,IFactory*pFactory)
{
  auto&ptr_lnk=Space[pFactory->Self].ptr_lnk;
  if (ptr_lnk.IsNull())
  {
    ptr_lnk=Space[FindTypeByFactory(Env,pFactory)->Self].ptr;
  }
  if (ptr_lnk.IsValid())return (TType*)ptr_lnk.get();
  return nullptr;
}
void EnvAdapter::GoV3(TServerPtrSpace&Space,IEnvRTTI&Env)
{
  GoV2(Space,Env,TMetaTypePack(Env));
}
void EnvAdapter::GoV2(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
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
void EnvAdapter::GoSys(TServerPtrSpace&Space)
{
  GoFactory(Space);
  GoCppIO(Space);
  GoBinIO(Space);
  GoVectorAPI(Space);
}
void EnvAdapter::GoFactory(TServerPtrSpace&Space)
{
  auto&Arr=TFactory<void>::GetFactorys();
  for (int i=0;i<Arr.size();i++)
  {
    IFactory*it=Arr[i].get();
    string name="TFactory<"+it->GetElementTypeFullName()+">::Get()";
    auto&ex=Space.AddExt(get(it->Self),nullptr,name);
    ex.system=true;
    ex.hidden=true;
  }
}
void EnvAdapter::GoCppIO(TServerPtrSpace&Space)
{
  auto&Arr=THeadCppIO<void>::GetArr();
  for (int i=0;i<Arr.size();i++)
  {
    auto*it=Arr[i].get();
    string name="THeadCppIO<...hidden...>::Get()";
    auto&ex=Space.AddExt(get(it->Self),nullptr,name);
    ex.system=true;
    ex.hidden=true;
  }
}
void EnvAdapter::GoBinIO(TServerPtrSpace&Space)
{
  auto&Arr=THeadBinIO<void>::GetArr();
  for (int i=0;i<Arr.size();i++)
  {
    auto*it=Arr[i].get();
    string name="THeadBinIO<...hidden...>::Get()";
    auto&ex=Space.AddExt(get(it->Self),nullptr,name);
    ex.system=true;
    ex.hidden=true;
  }
}
void EnvAdapter::GoVectorAPI(TServerPtrSpace&Space)
{
  auto&Arr=TVectorAPI<void>::GetArr();
  for (int i=0;i<Arr.size();i++)
  {
    auto*it=Arr[i].get();
    string name="TVectorAPI<...hidden...>::Get()";
    auto&ex=Space.AddExt(get(it->Self),nullptr,name);
    ex.system=true;
    ex.hidden=true;
  }
}
void EnvAdapter::GoEnv(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
{
  auto*pTType=TypePack.pTType;
  auto*pTTypeStruct=TypePack.pTTypeStruct;
  auto&Arr=Env.GetArr();
  for (int i=0;i<Arr.size();i++)
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
void EnvAdapter::FixEnvType(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
{
  auto*pTType=TypePack.pTType;
  auto*pTTypeStruct=TypePack.pTTypeStruct;
  auto&Arr=Env.GetArr();
  for (int i=0;i<Arr.size();i++)
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
bool EnvAdapter::IsFactoryEqual(TType*p,TType*b)
{
  return p->Factory.get()==b->Factory.get();
}
bool EnvAdapter::IsBasedOn(TType*p,TType*base)
{
  if (IsFactoryEqual(p,base))return true;
  TType*subtype=p->GetSubType();
  return subtype?IsBasedOn(subtype,base):false;
}
bool IQapStream::Load()
{
  return false;
}
bool IQapStream::Save()
{
  return false;
}
TQapFileStream::TQapFileStream(const string&fn,bool readonly):fn(fn),readonly(readonly) {}
bool TQapFileStream::Load()
{
  return IO.IO.LoadFile(fn);
}
bool TQapFileStream::Save()
{
  if (readonly)
  {
    QapDebugMsg("yes?");
    return false;
  }
  return IO.IO.SaveFile(fn);
}
QapIO&TQapFileStream::GetContent()
{
  return IO;
}
TQapMemoryStream::TQapMemoryStream() {}
bool TQapMemoryStream::Load()
{
  return true;
}
bool TQapMemoryStream::Save()
{
  return true;
}
QapIO&TQapMemoryStream::GetContent()
{
  return IO;
}
TDataIOStream::TDataIOStream(TDataIO&IO):IO(IO) {}
bool TDataIOStream::Load()
{
  return true;
}
bool TDataIOStream::Save()
{
  return true;
}
QapIO&TDataIOStream::GetContent()
{
  return IO;
}
TQapRawObject::TQapRawObject(const TRawPtr&ptr)
{
  raw_ptr=ptr;
}
TQapRawObject::TQapRawObject(TType*pType,void*pValue)
{
  raw_ptr.pType=pType;
  raw_ptr.pValue=pValue;
}
TRawPtr&TQapRawObject::Get(IEnvRTTI&Env)
{
  return raw_ptr;
}
void DeclareType::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
DeclareType::DeclareType()
{
  DoReset();
}
DeclareType::DeclareType(DeclareType&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareType::operator=(DeclareType&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string DeclareType::ProxySys$$::GetFullName()
{
  return "DeclareType";
}
void DeclareType::Use(IDeclareVisitorRTTI&)
{
  QapDebugMsg("no way.");
}
string DeclareType::GetFullName()const
{
  return QapDeclareDetail<void>::GetFullName(this);
}
DeclareType*DeclareType::GetSubType()const
{
  return QapDeclareDetail<void>::GetSubType(this);
}
bool DeclareType::IsBasedOn(const DeclareType*A)const
{
  return QapDeclareDetail<void>::IsBasedOn(this,A);
}
void DeclareTypeSys::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->FullName)=("unnamed");
}
DeclareTypeSys::DeclareTypeSys()
{
  DoReset();
}
DeclareTypeSys::DeclareTypeSys(DeclareTypeSys&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeSys::operator=(DeclareTypeSys&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->FullName=std::move(_Right.FullName);;
}
string DeclareTypeSys::ProxySys$$::GetFullName()
{
  return "DeclareTypeSys";
}
void DeclareTypeSys::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeSys::SelfClass*DeclareTypeSys::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeSelfPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
}
DeclareTypeSelfPtr::DeclareTypeSelfPtr()
{
  DoReset();
}
DeclareTypeSelfPtr::DeclareTypeSelfPtr(DeclareTypeSelfPtr&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeSelfPtr::operator=(DeclareTypeSelfPtr&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
}
string DeclareTypeSelfPtr::ProxySys$$::GetFullName()
{
  return "DeclareTypeSelfPtr";
}
void DeclareTypeSelfPtr::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeSelfPtr::SelfClass*DeclareTypeSelfPtr::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeAutoPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
}
DeclareTypeAutoPtr::DeclareTypeAutoPtr()
{
  DoReset();
}
DeclareTypeAutoPtr::DeclareTypeAutoPtr(DeclareTypeAutoPtr&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeAutoPtr::operator=(DeclareTypeAutoPtr&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
}
string DeclareTypeAutoPtr::ProxySys$$::GetFullName()
{
  return "DeclareTypeAutoPtr";
}
void DeclareTypeAutoPtr::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeAutoPtr::SelfClass*DeclareTypeAutoPtr::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeWeakPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
}
DeclareTypeWeakPtr::DeclareTypeWeakPtr()
{
  DoReset();
}
DeclareTypeWeakPtr::DeclareTypeWeakPtr(DeclareTypeWeakPtr&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeWeakPtr::operator=(DeclareTypeWeakPtr&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
}
string DeclareTypeWeakPtr::ProxySys$$::GetFullName()
{
  return "DeclareTypeWeakPtr";
}
void DeclareTypeWeakPtr::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeWeakPtr::SelfClass*DeclareTypeWeakPtr::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeHardPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
}
DeclareTypeHardPtr::DeclareTypeHardPtr()
{
  DoReset();
}
DeclareTypeHardPtr::DeclareTypeHardPtr(DeclareTypeHardPtr&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeHardPtr::operator=(DeclareTypeHardPtr&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
}
string DeclareTypeHardPtr::ProxySys$$::GetFullName()
{
  return "DeclareTypeHardPtr";
}
void DeclareTypeHardPtr::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeHardPtr::SelfClass*DeclareTypeHardPtr::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeFieldPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
}
DeclareTypeFieldPtr::DeclareTypeFieldPtr()
{
  DoReset();
}
DeclareTypeFieldPtr::DeclareTypeFieldPtr(DeclareTypeFieldPtr&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeFieldPtr::operator=(DeclareTypeFieldPtr&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
}
string DeclareTypeFieldPtr::ProxySys$$::GetFullName()
{
  return "DeclareTypeFieldPtr";
}
void DeclareTypeFieldPtr::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeFieldPtr::SelfClass*DeclareTypeFieldPtr::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeVoidPtr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
}
DeclareTypeVoidPtr::DeclareTypeVoidPtr()
{
  DoReset();
}
DeclareTypeVoidPtr::DeclareTypeVoidPtr(DeclareTypeVoidPtr&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeVoidPtr::operator=(DeclareTypeVoidPtr&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
}
string DeclareTypeVoidPtr::ProxySys$$::GetFullName()
{
  return "DeclareTypeVoidPtr";
}
void DeclareTypeVoidPtr::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeVoidPtr::SelfClass*DeclareTypeVoidPtr::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeVector::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
}
DeclareTypeVector::DeclareTypeVector()
{
  DoReset();
}
DeclareTypeVector::DeclareTypeVector(DeclareTypeVector&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeVector::operator=(DeclareTypeVector&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
}
string DeclareTypeVector::ProxySys$$::GetFullName()
{
  return "DeclareTypeVector";
}
void DeclareTypeVector::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeVector::SelfClass*DeclareTypeVector::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareTypeArray::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->ElementType);
  (this->Size)=(0);
}
DeclareTypeArray::DeclareTypeArray()
{
  DoReset();
}
DeclareTypeArray::DeclareTypeArray(DeclareTypeArray&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeArray::operator=(DeclareTypeArray&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->ElementType=std::move(_Right.ElementType);;
  this->Size=std::move(_Right.Size);;
}
string DeclareTypeArray::ProxySys$$::GetFullName()
{
  return "DeclareTypeArray";
}
void DeclareTypeArray::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeArray::SelfClass*DeclareTypeArray::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
void DeclareMember::DoReset()
{
  {
    ;
  }
  (this->Name)=("unnamed");
  detail::FieldTryDoReset(this->Type);
  detail::FieldTryDoReset(this->Mode);
  detail::FieldTryDoReset(this->Value);
}
DeclareMember::DeclareMember()
{
  DoReset();
}
DeclareMember::DeclareMember(DeclareMember&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareMember::operator=(DeclareMember&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Name=std::move(_Right.Name);;
  this->Type=std::move(_Right.Type);;
  this->Mode=std::move(_Right.Mode);;
  this->Value=std::move(_Right.Value);;
}
string DeclareMember::ProxySys$$::GetFullName()
{
  return "DeclareMember";
}
bool DeclareMember::IsEqual(SelfClass&other)
{
  QapDebugMsg("no way.");return false;
}
void DeclareTypeStruct::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->Name)=("unnamed");
  detail::FieldTryDoReset(this->SubType);
  detail::FieldTryDoReset(this->OwnType);
  detail::FieldTryDoReset(this->Members);
}
DeclareTypeStruct::DeclareTypeStruct()
{
  DoReset();
}
DeclareTypeStruct::DeclareTypeStruct(DeclareTypeStruct&&_Right)
{
  operator=(std::move(_Right));
}
void DeclareTypeStruct::operator=(DeclareTypeStruct&&_Right)
{
  struct hidden
  {
    static void foo(DeclareType(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DeclareType::operator=(std::move(_Right));;
  }
  this->Name=std::move(_Right.Name);;
  this->SubType=std::move(_Right.SubType);;
  this->OwnType=std::move(_Right.OwnType);;
  this->Members=std::move(_Right.Members);;
}
string DeclareTypeStruct::ProxySys$$::GetFullName()
{
  return "DeclareTypeStruct";
}
void DeclareTypeStruct::Use(IDeclareVisitorRTTI&A)
{
  A.Do(this);
}
DeclareTypeStruct::SelfClass*DeclareTypeStruct::UberCast(DeclareType*ptr)
{
  return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);
}
bool DeclareTypeStruct::TestField(const DeclareMember&it,int depth)
{
  if (SubType)
  {
    auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
    bool result=pSubType->TestField(it,depth+1);
    if (!result)return result;
  }
  auto&arr=Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    int cmp_id=0;
    static string idToStr[]={"Name",};
    const int cmp_n=lenof(idToStr)-(depth?1:0);
    do
    {
      if (cmp_id<cmp_n)
      {
        if (it.Name==ex.Name)break;
        cmp_id++;;
      }
      ;
    }
    while (false);
    if (cmp_id!=cmp_n)
    {
      string tmp=idToStr[cmp_id];
      string fn=GetFullName();
      if (tmp=="Name")if (it.Name=="Self")if (fn=="QapWinProgram")continue;
      QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
      return depth;
    }
  }
  return true;
}
DeclareMember*DeclareTypeStruct::GetNearSelf()
{
  auto&arr=Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (ex.Name!="Self")continue;
    auto*pFieldType=DeclareTypeSelfPtr::UberCast(ex.Type.get());
    QapAssert(pFieldType);
    QapAssert(pFieldType->ElementType.get()==this);
    return &ex;
  }
  auto*pSubType=DeclareTypeStruct::UberCast(GetSubType());
  return pSubType?pSubType->GetNearSelf():nullptr;
}
void DeclareTypeStruct::AddField(DeclareMember&&field)
{
  QapAssert(TestField(field));
  if (field.Name=="Self")
  {
    if (true)do
      {
        auto*type=DeclareTypeSelfPtr::UberCast(field.Type.get());
        QapAssert(type);
        if (this!=type->ElementType.get())
        {
          string fn=GetFullName();
          QapDebugMsg("field - \""+fn+"\"::"+field.Name+"\" has wrong type");
        }
      }
      while (false);
    if (GetNearSelf())do
      {
        auto*type=field.Type.get();
        auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
        string fn=GetFullName();
        string subtype=pSubType->GetFullName();
        if ("QapWinProgram"==subtype)if ("eWinProgram"==fn)break;
        if ("QapWinProgram"==subtype)if ("QapProgramD3D9"==fn)break;
        QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
      }
      while (false);
  }
  Members.push_back(std::move(field));
}
void DeclareTypeStruct::AddMember(DeclareType*MemType,const string&MemName,const string&Mode,const string&Value)
{
  DeclareMember tmp;
  tmp.Type=MemType;
  tmp.Name=MemName;
  tmp.Mode=Mode;
  tmp.Value=Value;
  AddField(std::move(tmp));
}
void DeclareDetail::StructTools::field_cmp_result_item::SetToDef()
{
  ida=-1;
  idb=-1;
}
vector<DeclareDetail::StructTools::field_cmp_result_item> DeclareDetail::StructTools::CompareFieldsLists(const vector<DeclareMember>&A,const vector<DeclareMember>&B)
{
  field_cmp_result_item tmp;
  tmp.SetToDef();
  vector<field_cmp_result_item> result;
  result.reserve(A.size()+B.size());
  vector<bool> passed;
  passed.resize(B.size(),false);
  for (int i=0;i<A.size();i++)
  {
    result.push_back(tmp);
    auto&ex=result.back();
    auto&ax=A[i];
    ex.ida=i;
    ex.fna=ax.Name;
    for (int j=0;j<B.size();j++)
    {
      if (passed[j])continue;
      auto&bx=B[j];
      if (ax.Name!=bx.Name)continue;
      ex.fnb=bx.Name;
      ex.idb=j;
      passed[j]=true;
    }
  }
  for (int j=0;j<B.size();j++)
  {
    if (passed[j])continue;
    result.push_back(tmp);
    auto&ex=result.back();
    auto&bx=B[j];
    ex.fnb=bx.Name;
    ex.idb=j;
    passed[j]=true;
  }
  return std::move(result);
}
void DeclareDetail::StructTools::Filter_RemoveEqual(vector<field_cmp_result_item>&arr)
{
  vector<field_cmp_result_item> tmp;
  std::swap(tmp,arr);
  for (int i=0;i<tmp.size();i++)
  {
    auto&ex=tmp[i];
    if ((ex.ida<0)!=(ex.idb<0))
    {
      arr.push_back(std::move(ex));
    }
  }
}
string DeclareDetail::StructTools::CompareFieldsLists_ToString(const vector<field_cmp_result_item>&arr)
{
  string out;
  int n_a=[&]()->size_t {size_t n=0;
      for (size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fna.size(),n);
      return n;
                        }();
  int n_b=[&]()->size_t {size_t n=0;
      for (size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fnb.size(),n);
      return n;
                        }();
  auto&f=[](const string&s,size_t n)->string {string tmp=s;
      for (size_t i=s.size();i<n;i++)tmp+=" ";
      return tmp;
                                             };
for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    out+=f(ex.fna,n_a)+" = "+f(ex.fnb,n_b)+"\n";
  }
  return out;
}
void DeclareDetail::GetFullName::Do(DeclareTypeSys*p)
{
  fullname=p->FullName;
}
void DeclareDetail::GetFullName::Do(DeclareTypeSelfPtr*p)
{
  string template_name="TSelfPtr";
  fullname=template_name+"<"+p->ElementType->GetFullName()+">";
}
void DeclareDetail::GetFullName::Do(DeclareTypeAutoPtr*p)
{
  string template_name="TAutoPtr";
  fullname=template_name+"<"+p->ElementType->GetFullName()+">";
}
void DeclareDetail::GetFullName::Do(DeclareTypeWeakPtr*p)
{
  string template_name="TWeakPtr";
  fullname=template_name+"<"+p->ElementType->GetFullName()+">";
}
void DeclareDetail::GetFullName::Do(DeclareTypeHardPtr*p)
{
  string template_name="THardPtr";
  fullname=template_name+"<"+p->ElementType->GetFullName()+">";
}
void DeclareDetail::GetFullName::Do(DeclareTypeVoidPtr*p)
{
  string name="TVoidPtr";
  fullname=name;
}
void DeclareDetail::GetFullName::Do(DeclareTypeFieldPtr*p)
{
  string name="TFieldPtr";
  fullname=name;
}
void DeclareDetail::GetFullName::Do(DeclareTypeVector*p)
{
  string template_name="vector";
  fullname=template_name+"<"+p->ElementType->GetFullName()+">";
}
void DeclareDetail::GetFullName::Do(DeclareTypeArray*p)
{
  string template_name="array";
  fullname=template_name+"<"+p->ElementType->GetFullName()+","+IToS(p->Size)+">";
}
void DeclareDetail::GetFullName::Do(DeclareTypeStruct*p)
{
  string template_name="TSelfPtr";
  auto*pOwnType=p->OwnType.get();
  fullname=pOwnType?pOwnType->GetFullName()+"::"+p->Name:p->Name;
}
DeclareDetail::GetSubType::GetSubType():pValue(nullptr) {}
void DeclareDetail::GetSubType::Do(DeclareTypeSys*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeSelfPtr*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeAutoPtr*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeWeakPtr*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeHardPtr*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeVoidPtr*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeFieldPtr*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeVector*p)
{
  pValue=nullptr;
}
void DeclareDetail::GetSubType::Do(DeclareTypeStruct*p)
{
  pValue=p->SubType.get();
}
TSmartPtrVisitor::TSmartPtrVisitor(ICallBack&CB,void*pValue):CB(CB),pValue(pValue) {}
TSmartPtrVisitor::TSmartPtrVisitor(TSmartPtrVisitor&owner,void*pValue):CB(owner.CB),pValue(pValue) {}
void TSmartPtrVisitor::Do(TTypeStruct*p)
{
  if (p->SubType)
  {
    SelfClass next(*this,pValue);
    p->SubType->Use(next);
  }
  auto&arr=p->Members;
  static bool debug_flag=false;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
    if (debug_flag)
    {
      string fn=p->GetFullName();
      if (fn=="TType")if (ex.Name=="Factory")do
          {
            TType*pval=(TType*)(void*)pValue;
            string val_fn=pval->GetFullName();
            THardPtr<TType>&value=*(THardPtr<TType>*)(void*)next.pValue;
            auto*ptr=value.P.ptr;
            if (!ptr)break;
            int sid=ptr->SaveID;
            sid=sid+1-1;
          }
          while (false);
    }
    ex.Type->Use(next);
    if (debug_flag)
    {
      string fn=ex.Type->GetFullName();
      int ksjdlasd=0;
    }
  }
}
void TSmartPtrVisitor::Do(TTypeSys*p)
{
}
void TSmartPtrVisitor::Do(TTypeVector*p)
{
  auto*VecAPI=p->VecAPI.get();
  int Count=VecAPI->GetCount(pValue);
  TType*elemType=p->ElementType.get();
  for (int i=0;i<Count;i++)
  {
    void*ptr=VecAPI->GetItem(pValue,i);
    SelfClass next(*this,ptr);
    elemType->Use(next);
  }
}
void TSmartPtrVisitor::Do(TTypeArray*p)
{
  int Count=p->Size;
  TType*elemType=p->ElementType.get();
  int elemSize=elemType->Info.Size;
  for (int i=0;i<Count;i++)
  {
    void*ptr=&((uchar*)pValue)[elemSize*i];
    SelfClass next(*this,ptr);
    elemType->Use(next);
  }
}
void TSmartPtrVisitor::Do(TTypeSelfPtr*p)
{
  TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
  CB.Visit(value.P,p->ElementType.get());
}
void TSmartPtrVisitor::Do(TTypeAutoPtr*p)
{
  if (!p->ElementType)
  {
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
  if (ptr&&type)
  {
    SelfClass next(*this,ptr);
    type->Use(next);
  }
}
void TSmartPtrVisitor::Do(TTypeWeakPtr*p)
{
  TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
  CB.Visit(value.P,p->ElementType.get());
}
void TSmartPtrVisitor::Do(TTypeHardPtr*p)
{
  THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
  CB.Visit(value.P,p->ElementType.get());
}
void TSmartPtrVisitor::Do(TTypeVoidPtr*p)
{
  TVoidPtr&value=*(TVoidPtr*)pValue;
  TType*pmTypeType=p->mType.Type.get();
  {
    SelfClass next(*this,&value.type);
    pmTypeType->Use(next);
  }
  CB.Visit(value.ptr.P);
}
void TSmartPtrVisitor::Do(TTypeFieldPtr*p)
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
void TSmartPtrVisitor::Do(TTypeFactory*p)
{
  IFactory&value=*(IFactory*)pValue;
  TSelfPtr<IEsoteric>&Self=*(TSelfPtr<IEsoteric>*)(void*)&value.Self;
  TType*SmartType=p->SmartType.get();
  CB.Visit(Self.P,SmartType);
}
TClientPtrCounter::TClientPtrCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
{
  QapDebugMsg("deprecated");
  QapDebugMsg("see TClientPtrUserCallBackCounter");
  prepare(Env);
}
void TClientPtrCounter::prepare(IEnvRTTI&Env)
{
  pTType=Sys$$<TType>::GetRTTI(Env);
  pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
}
void TClientPtrCounter::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
void TClientPtrCounter::Visit(TClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TClientPtrCounter::Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TClientPtrCounter::Visit(TClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
void TClientPtrCounter::Visit(THardClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
void TClientPtrCounter::DoVisitSaveID(int id,bool safe,TType*elemType)
{
  if (!id)
  {
    QapDebugMsg("bad news");
    return;
  }
  auto&item=Space[id];
  if (item.passed)return;
  if (item.count)return;
  if (true)
  {
    QapAssert(item.ptr.type);
    auto*pType=item.ptr.type;
    bool trigger=pType->IsBasedOn(pTType);
    if (trigger)
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
    if (safe)
    {
      bool good=pType->IsBasedOn(elemType);
      QapAssert(good);
    }
  }
  item.count++;
  return;
}
TServerPtrGraber::TServerPtrGraber(TServerPtrSpace&Space,bool automark):Space(Space),automark(automark)
{
  AddCount=0;
  SkipCount=0;
}
void TServerPtrGraber::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
{
  QapDebugMsg
  (
    "[2014.05.14 12:09]\n"
    "This class can not determine the actual type of the object and is no longer using.\n"
    "Look at 'TServerPtrGraberWithRealType'"
  );
  if (Space.CheckServSaveID(&Serv))
  {
    QapDebugMsg("the way used? ORL?");
    SkipCount++;
    auto&ex=Space[Serv.SaveID];
    if (automark)
    {
      ex.count++;
      ex.passed=true;
    }
    return;
  }
  auto&ex=Space.UnsafeAdd(&Serv,elemType);
  AddCount++;
  if (automark)
  {
    ex.count++;
    ex.passed=true;
  }
}
void TServerPtrGraber::Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
void TServerPtrGraber::Visit(THardClientPtr<IEsoteric>&A,TType*elemType) {}
void TServerPtrGraber::Visit(TClientPtr<IEsoteric>&A) {}
void TServerPtrGraber::Visit(THardClientPtr<IEsoteric>&A) {}
TServerPtrCounter::TServerPtrCounter(int&count):count(count) {}
void TServerPtrCounter::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
{
  count++;
}
void TServerPtrCounter::Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
void TServerPtrCounter::Visit(THardClientPtr<IEsoteric>&A,TType*elemType) {}
void TServerPtrCounter::Visit(TClientPtr<IEsoteric>&A) {}
void TServerPtrCounter::Visit(THardClientPtr<IEsoteric>&A) {}
TClientPtrSolver::TwoMetaType::TwoMetaType(const TwoMetaType&Ref):pTType(nullptr),pDeclareType(nullptr)
{
  oper_set(Ref);
}
TClientPtrSolver::TwoMetaType::TwoMetaType():pTType(nullptr),pDeclareType(nullptr) {}
TClientPtrSolver::TwoMetaType::TwoMetaType(IEnvRTTI&Env):pTType(nullptr),pDeclareType(nullptr)
{
  prepare(Env);
}
void TClientPtrSolver::TwoMetaType::prepare(IEnvRTTI&Env)
{
  pTType=Sys$$<TType>::GetRTTI(Env);
  pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
}
void TClientPtrSolver::TwoMetaType::oper_set(const TwoMetaType&Ref)
{
  this->pTType=Ref.pTType;
  this->pDeclareType=Ref.pDeclareType;
}
void TClientPtrSolver::TwoMetaType::operator=(const TwoMetaType&Ref)
{
  oper_set(Ref);
}
TClientPtrSolver::TClientPtrSolver(TSpace&Space,const TwoMetaType&tmt):Space(Space),pTType(tmt.pTType),pDeclareType(tmt.pDeclareType) {}
void TClientPtrSolver::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
void TClientPtrSolver::Visit(TClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TClientPtrSolver::Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TClientPtrSolver::Visit(TClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
void TClientPtrSolver::Visit(THardClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
TServerPtr<IEsoteric>*TClientPtrSolver::DoVisitSaveID(int id,bool safe,TType*elemType)
{
  if (!id)return nullptr;
  if (id<0||id>=Space.size())
  {
    QapDebugMsg("Error!\nWrong id:\n"+IToS(id));
    return nullptr;
  }
  auto&item=Space[id];
  if (item.ptr.type)
  {
    if (!safe)
    {
      return item.ptr.ptr;
    }
    QapAssert(elemType);
    bool flag=elemType->IsBasedOn(pTType);
    if (!flag)
    {
      int gg=1;
    }
    if (flag)
    {
      bool f[]=
      {
        item.ptr.type->IsBasedOn(pTType),
        item.ptr.type->IsBasedOn(pDeclareType)
      };
      bool good=!f[0]&&f[1];
      if (!good)
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
  }
  else
  {
    QapDebugMsg("norm");
    return item.ptr.ptr;
  }
  QapDebugMsg("no way.");
  return nullptr;
}
void TClientPtrKiller::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
void TClientPtrKiller::Visit(TClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A);
}
void TClientPtrKiller::Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A);
}
void TClientPtrKiller::Visit(TClientPtr<IEsoteric>&A)
{
  MegaVisit(A);
}
void TClientPtrKiller::Visit(THardClientPtr<IEsoteric>&A)
{
  MegaVisit(A);
}
TDumpPtrSolver::TDumpPtrSolver(TSpace&ST_Space,TSpace&LT_Space):ST_Space(ST_Space),LT_Space(LT_Space) {}
void TDumpPtrSolver::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
void TDumpPtrSolver::Visit(TClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TDumpPtrSolver::Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TDumpPtrSolver::Visit(TClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
void TDumpPtrSolver::Visit(THardClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
TServerPtr<IEsoteric>*TDumpPtrSolver::DoVisitSaveID(int id,bool safe,TType*elemType)
{
  if (LT_Space[id].system)return ST_Space[id].ptr.ptr;
  return LT_Space[id].ptr.ptr;
}
void TClientPtrVisitor::ICallBack::DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
{
  QapDebugMsg("no way.");
}
TClientPtrVisitor::TClientPtrVisitor(ICallBack&CB):CB(CB) {}
void TClientPtrVisitor::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
void TClientPtrVisitor::Visit(TClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TClientPtrVisitor::Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
{
  MegaVisit(A,elemType);
}
void TClientPtrVisitor::Visit(TClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
void TClientPtrVisitor::Visit(THardClientPtr<IEsoteric>&A)
{
  MegaVisitEx(A);
}
void THardClientSpace::Do()
{
  for (int i=0;i<Arr.size();i++)
  {
    auto*it=Arr[i];
    auto&ex=*it;
    if (ex)ex=nullptr;
  }
}
THardClientPtrGraber::THardClientPtrGraber(TSpace&Space):Space(Space) {}
void THardClientPtrGraber::Visit(TServerPtr<IEsoteric>&Serv,TType*elemType) {}
void THardClientPtrGraber::Visit(TClientPtr<IEsoteric>&A,TType*elemType) {}
void THardClientPtrGraber::Visit(THardClientPtr<IEsoteric>&A,TType*elemType)
{
  Space.Arr.push_back(&A);
}
void THardClientPtrGraber::Visit(TClientPtr<IEsoteric>&A) {}
void THardClientPtrGraber::Visit(THardClientPtr<IEsoteric>&A)
{
  Space.Arr.push_back(&A);
}
void ClientMarker(TSmartPtrVisitor::ICallBack&ClientCounter,TType*pType,void*pValue)
{
  TSmartPtrVisitor SPG(ClientCounter,pValue);
  pType->Use(SPG);
}
TServerPtrGraberWithRealType::TServerPtrGraberWithRealType(TSpace&Space,TType*pType,void*pValue,bool automark):Space(Space),pValue(pValue),automark(automark)
{
  AddCount=0;
  SkipCount=0;
  push(pType);
}
void TServerPtrGraberWithRealType::push(TType*pType)
{
  types.push_back(pType);
}
void TServerPtrGraberWithRealType::pop(TType*pType)
{
  QapAssert(!types.empty());
  QapAssert(pType==types.back());
  types.pop_back();
}
void TServerPtrGraberWithRealType::ptr_push(void*ptr)
{
  values.push_back(pValue);
  pValue=ptr;
}
void TServerPtrGraberWithRealType::ptr_pop(void*ptr)
{
  QapAssert(!values.empty());
  QapAssert(ptr==pValue);
  pValue=values.back();
  values.pop_back();
}
void TServerPtrGraberWithRealType::Do(TTypeStruct*p)
{
  if (p->SubType)
  {
    auto*pSubType=p->SubType.get();
    ptr_push(pValue);
    pSubType->Use(*this);
    ptr_pop(pValue);
  }
  auto&arr=p->Members;
  for (int i=0;i<arr.size();i++)
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
void TServerPtrGraberWithRealType::Do(TTypeSys*p)
{/*yoi aiiaua ian ia eioa?anoao.*/}
void TServerPtrGraberWithRealType::Do(TTypeFactory*p)
{/*yoi aiiaua ian ia eioa?anoao.*/}
void TServerPtrGraberWithRealType::Do(TTypeVector*p)
{
  auto*VecAPI=p->VecAPI.get();
  int Count=VecAPI->GetCount(pValue);
  TType*elemType=p->ElementType.get();
  push(elemType);
  for (int i=0;i<Count;i++)
  {
    void*ptr=VecAPI->GetItem(pValue,i);
    ptr_push(ptr);
    elemType->Use(*this);
    ptr_pop(ptr);
  }
  pop(elemType);
}
void TServerPtrGraberWithRealType::Do(TTypeArray*p)
{
  int Count=p->Size;
  TType*elemType=p->ElementType.get();
  int elemSize=elemType->Info.Size;
  push(elemType);
  for (int i=0;i<Count;i++)
  {
    void*ptr=&((uchar*)pValue)[elemSize*i];
    ptr_push(ptr);
    elemType->Use(*this);
    ptr_pop(ptr);
  }
  pop(elemType);
}
void TServerPtrGraberWithRealType::Do(TTypeSelfPtr*p)
{
  TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
  auto&Serv=value.P;
  if (Space.CheckServSaveID(&Serv))
  {
    QapDebugMsg("the way used? ORL?");
    SkipCount++;
    auto&ex=Space[Serv.SaveID];
    if (automark)
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
  if (automark)
  {
    ex.count++;
    ex.passed=true;
  }
}
void TServerPtrGraberWithRealType::Do(TTypeAutoPtr*p)
{
  if (!p->ElementType)
  {
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
  if (ptr&&type)
  {
    ptr_push(ptr);
    pType->Use(*this);
    ptr_pop(ptr);
  }
  pop(pType);
}
void TServerPtrGraberWithRealType::Do(TTypeWeakPtr*p)
{/*yoi aiiaua ian ia eioa?anoao.*/}
void TServerPtrGraberWithRealType::Do(TTypeHardPtr*p)
{/*yoi aiiaua ian ia eioa?anoao.*/}
void TServerPtrGraberWithRealType::Do(TTypeVoidPtr*p)
{/*yoi aiiaua ian ia eioa?anoao.*/}
void TServerPtrGraberWithRealType::Do(TTypeFieldPtr*p)
{/*yoi aiiaua ian ia eioa?anoao.*/}
void GrabServerPtr(TServerPtrSpace&Space,TType*pType,void*pValue,bool automark)
{
  TServerPtrGraberWithRealType SPGWRT(Space,pType,pValue,automark);
  pType->Use(SPGWRT);
  return;
}
TClientPtrVcbCounter::TClientPtrVcbCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
{
  prepare(Env);
}
void TClientPtrVcbCounter::prepare(IEnvRTTI&Env)
{
  pTType=Sys$$<TType>::GetRTTI(Env);
  pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
}
void TClientPtrVcbCounter::DoVisitSaveID(int id,bool safe,TType*elemType)
{
  if (!id)
  {
    QapDebugMsg("bad news");
    return;
  }
  auto&item=Space[id];
  if (item.passed)return;
  if (item.count)return;
  if (true)
  {
    QapAssert(item.ptr.type);
    auto*pType=item.ptr.type;
    bool trigger=pType->IsBasedOn(pTType);
    if (trigger)
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
    if (safe)
    {
      bool good=EnvAdapter::IsBasedOn(pType,elemType);
      QapAssert(good);
    }
  }
  item.count++;
  return;
}
void TClientPtrVcbCounter::DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
{
  if (!serv)return;
  DoVisitSaveID(serv->SaveID,safe,elemType);
}
TClientPtrVcbCounter20120828::TClientPtrVcbCounter20120828(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr),firstmode(true)
{
  prepare(Env);
}
void TClientPtrVcbCounter20120828::prepare(IEnvRTTI&Env)
{
  pTType=Sys$$<TType>::GetRTTI(Env);
  pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
}
void TClientPtrVcbCounter20120828::DoVisitSaveID(int id,bool safe,TType*elemType)
{
  if (!id)
  {
    QapDebugMsg("bad news");
    return;
  }
  auto&item=Space[id];
  if (item.passed)return;
  if (item.count)return;
  if (item.system)return;
  if (true)
  {
    QapAssert(item.ptr.type);
    auto*pType=item.ptr.type;
    bool trigger=pType->IsBasedOn(pTType)||pType->IsBasedOn(pDeclareType);
    if (trigger)
    {
      int gg=1;
    }
    QapAssert(!item.hidden);
    if (safe)
    {
      bool good=EnvAdapter::IsBasedOn(pType,elemType);
      QapAssert(good);
    }
  }
  item.count++;
  return;
}
void TClientPtrVcbCounter20120828::DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
{
  if (!serv)return;
  DoVisitSaveID(serv->SaveID,safe,elemType);
}
DependsSolver::DependsSolver(IEnvRTTI&Env,TClientPtrVisitor&CPC):CPC(CPC)
{
  pTType=Sys$$<TType>::GetRTTI(Env);
  pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  fullprocess=false;
}
void DependsSolver::prepare(TSpace&Space,bool force)
{
  Arr.clear();
  for (int i=0;i<Space.size();i++)
  {
    auto&item=Space[i];
    if (item.hidden)QapAssert(item.system);
    bool skip=item.system||item.passed||!item.count;
    if (skip)continue;
    if (false)
    {
      bool skip=item.ptr.type->IsBasedOn(pTType);
      if (skip)
      {
        int gg=1;
        continue;
      }
    }
    if (!fullprocess)
    {
      bool skip=item.ptr.type->IsBasedOn(pDeclareType);
      if (skip)
      {
        QapDebugMsg("WTF?");
        continue;
      }
    }
    Arr.push_back(item.id);
  }
}
void DependsSolver::pass(TSpace&Space,const TRawPtr&ptr)
{
  TType*pType=ptr.pType;
  void*pValue=ptr.pValue;
  if (true)
  {
    int sid=pType->Self.P.SaveID;
    QapAssert(sid);
    CPC.CB.DoVisitServerPtr(pType->Self.P,true,pTType);
  }
  ClientMarker(CPC,pType,pValue);
}
TRawPtr DependsSolver::get(const EnvVoidPtr&ptr)
{
  TRawPtr tmp;
  tmp.pType=ptr.type;
  tmp.pValue=ptr.get();
  return tmp;
}
void DependsSolver::step(TSpace&Space)
{
  for (int i=0;i<Arr.size();i++)
  {
    int id=Arr[i];
    if (!id)continue;
    auto&item=Space[id];
    QapAssert(!item.system);
    if (!item.ptr.type)
    {
      QapAssert(item.passed&&item.ptr.type);
      item.passed=true;
      continue;
    }
    if (!fullprocess)
    {
      bool skip=item.ptr.type->IsBasedOn(pDeclareType);
      if (skip)
      {
        QapDebugMsg("WTF?");
        continue;
      }
    }
    pass(Space,get(item.ptr));
    item.passed=true;
  }
}
void DependsSolver::SolveDepends(TSpace&Space,bool fullprocess)
{
  this->fullprocess=fullprocess;
  prepare(Space,false);
  for (int loop_counter=0;!Arr.empty()&&(loop_counter<1024);loop_counter++)
  {
    step(Space);
    prepare(Space,false);
  }
  QapAssert(Arr.empty());
  QapAssert(Space[0].count>0);
  this->fullprocess=false;
}
TPrinter::TPrinter(string&s):s(s)
{
  sep=" = ";
}
void TPrinter::Indent()
{
  indent+="  ";
}
void TPrinter::Outdent()
{
  indent.resize(max(0,indent.size()-2));
}
void TPrinter::Print(string const&data)
{
  s+=indent+data+"\n";
}
void TMessage::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->type);
  (this->mode)=(mmRet);
}
TMessage::TMessage()
{
  DoReset();
}
TMessage::TMessage(TMessage&&_Right)
{
  operator=(std::move(_Right));
}
void TMessage::operator=(TMessage&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->type=std::move(_Right.type);;
  this->mode=std::move(_Right.mode);;
}
string TMessage::ProxySys$$::GetFullName()
{
  return "TMessage";
}
void EnvTypeHolder::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->FullName);
  detail::FieldTryDoReset(this->Type);
  detail::FieldTryDoReset(this->Factory);
}
EnvTypeHolder::EnvTypeHolder()
{
  DoReset();
}
EnvTypeHolder::EnvTypeHolder(EnvTypeHolder&&_Right)
{
  operator=(std::move(_Right));
}
void EnvTypeHolder::operator=(EnvTypeHolder&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->FullName=std::move(_Right.FullName);;
  this->Type=std::move(_Right.Type);;
  this->Factory=std::move(_Right.Factory);;
}
string EnvTypeHolder::ProxySys$$::GetFullName()
{
  return "EnvTypeHolder";
}
void EnvTypeHolder::hack_move(TProduct&out,TRTTIProduct&inp)
{
  out.Alloc=inp.GetAlloc();
  out.Factory=inp.GetFactory();
  out.Memory=std::move(inp.Memory);
  inp.pType=nullptr;
}
void EnvTypeHolder::eat(EnvType&item)
{
  FullName=item.Type->GetFullName();
  hack_move(Type,item.Type.Product);
  if (item.Factory)hack_move(Factory,item.Factory.Product);
}
void EnvTypeHolder::boom()
{
  Type.Free();
  if (Factory)Factory.Free();
}
TType*EnvTypeHolder::GetType()
{
  return (TType*)Type.Memory.ptr;
}
IFactory*EnvTypeHolder::GetFactory()
{
  return (IFactory*)Factory.Memory.ptr;
}
void TEnvRTTI::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Arr);
  detail::FieldTryDoReset(this->Alloc);
  detail::FieldTryDoReset(this->ID);
  detail::FieldTryDoReset(this->messages);
  detail::FieldTryDoReset(this->OwnerEnv);
}
TEnvRTTI::TEnvRTTI()
{
  DoReset();
}
TEnvRTTI::TEnvRTTI(TEnvRTTI&&_Right)
{
  operator=(std::move(_Right));
}
void TEnvRTTI::operator=(TEnvRTTI&&_Right)
{
  struct hidden
  {
    static void foo(IEnvRTTI(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    IEnvRTTI::operator=(std::move(_Right));;
  }
  this->Arr=std::move(_Right.Arr);;
  this->Alloc=std::move(_Right.Alloc);;
  this->ID=std::move(_Right.ID);;
  this->messages=std::move(_Right.messages);;
  this->OwnerEnv=std::move(_Right.OwnerEnv);;
}
string TEnvRTTI::ProxySys$$::GetFullName()
{
  return "TEnvRTTI";
}
string TEnvRTTI::GetTypeFullNames()
{
  string tmp;
  for (int i=0;i<Arr.size();i++)
  {
    if (i)tmp+=",\n";
    tmp+=Arr[i].Type->GetFullName();
  }
  return std::move(tmp);
}
void TEnvRTTI::PrintLog(const string&fn)
{
  CrutchIO io;
  TPrinter printer(io.mem);
  for (int i=0;i<messages.size();i++)
  {
    TMessage&EX=messages[i];
    TType*Info=EX.type.get();
    if (EX.mode==TMessage::mmBeg)
    {
      printer.Print("Register(\""+Info->GetFullName()+"\")");
      printer.Print("{");
      printer.Indent();
    }
    if (EX.mode==TMessage::mmRet)
    {
      printer.Print("Ret(\""+Info->GetFullName()+"\");");
    }
    if (EX.mode==TMessage::mmEnd)
    {
      printer.Outdent();
      printer.Print("}//"+Info->GetFullName());
    }
  }
  io.SaveFile(fn);
}
void TEnvRTTI::OnRegBeg(TType*Info)
{
  TMessage tmp;
  tmp.type=Info;
  tmp.mode=TMessage::mmBeg;
  messages.emplace_back(std::move(tmp));
}
void TEnvRTTI::OnRegRet(TType*Info)
{
  TMessage tmp;
  tmp.type=Info;
  tmp.mode=TMessage::mmRet;
  messages.emplace_back(std::move(tmp));
}
void TEnvRTTI::OnRegEnd(TType*Info)
{
  TMessage tmp;
  tmp.type=Info;
  tmp.mode=TMessage::mmEnd;
  messages.emplace_back(std::move(tmp));
}
IAllocator*TEnvRTTI::GetAlloc()
{
  return Alloc.get();
}
int TEnvRTTI::RegInfo(TAutoPtr<TType>&&_Right)
{
  EnvType tmp;
  tmp.Type=std::move(_Right);
  Arr.push_back(std::move(tmp));
  return Arr.size()-1;
}
EnvType&TEnvRTTI::GetEnvTypeById(int id)
{
  return Arr[id];
}
vector<EnvType>&TEnvRTTI::GetArr()
{
  return Arr;
}
TEnvRTTI::~TEnvRTTI()
{
  clear();
}
IEnvRTTI*TEnvRTTI::GetOwnerEnv()
{
  return OwnerEnv.get();
}
void TEnvRTTI::update()
{
  QapCleanIf(Arr,[](EnvType&ex)
  {
    return !ex.Type;
  }
            );
}
bool TEnvRTTI::IsValid()
{
  for (int i=Arr.size()-1;i>=0;i--)
  {
    auto&ex=Arr[i].Type;
    if (!ex)
    {
      int temp=0;
      QapDebugMsg("fail");
      return false;
    }
  }
  return true;
}
void TEnvRTTI::clear()
{
  if (!IsValid())
  {
    QapDebugMsg("fail");
    update();
    QapAssert(IsValid());
  }
  unlink();
  int skip_count=0;
  for (int i=Arr.size()-1;i>=0;i=i?--i:i=Arr.size()-1)
  {
    skip_count++;
    auto&item=Arr[i];
    TAutoPtr<TType>&ex=item.Type;
    auto&nm=ex->Info.Name;
    auto&fn=ex->GetFullName();
    bool skip=!ex->CanDestroy();
    if (skip&&skip_count>Arr.size())break;
    if (skip)continue;
    item.Type=nullptr;
    item.Factory=nullptr;
    std::swap(item,Arr.back());
    Arr.pop_back();
    skip_count=0;
  }
  if (!Arr.empty())
  {
    PrintCur();
    QapAssert(Arr.empty());
    Arr.clear();
  }
}
bool TEnvRTTI::IsLegalChar(const unsigned char&c)
{
  return InDip<char>('a',c,'z')||InDip<char>('A',c,'Z')||InDip<char>('0',c,'9');
}
string TEnvRTTI::string2xml(const string&str)
{
  string tmp;
  tmp.reserve(str.size()*3);
  for (int i=0;i<str.size();i++)
  {
    tmp+=IsLegalChar(str[i])?CToS(str[i]):"&#"+IToS(str[i])+";";
  }
  return std::move(tmp);
}
void TEnvRTTI::PrintCur()
{
  ;
  for (int i=0;i<Arr.size();i++)
  {
    TAutoPtr<TType>&EX=Arr[i].Type;
    TType*pVal=EX.get();
    TType*pType=EX.Product.GetType();
    IAllocator*pAlloc=EX.Product.GetAlloc();
    IFactory*pFactory=EX.Product.GetFactory();
    auto&fn=EX->GetFullName();
    ;
  }
}
void TEnvRTTI::add_sniper_job(THardClientSpace&Space,TRawPtr&raw_ptr)
{
  THardClientPtrGraber Graber(Space);
  TSmartPtrVisitor CPG(Graber,raw_ptr.pValue);
  raw_ptr.pType->Use(CPG);
}
void TEnvRTTI::unlink()
{
  if (Arr.empty())return;
  THardClientSpace Space;
  for (int i=0;i<Arr.size();i++)
  {
    auto&item=Arr[i];
    TRawPtr type(item.Type.Product.pType.get(),item.Type.get());
    add_sniper_job(Space,type);
    if (!item.Factory)continue;
    TRawPtr fact(item.Factory.Product.pType.get(),item.Factory.get());
    add_sniper_job(Space,fact);
  }
  vector<EnvTypeHolder> holders;
  holders.resize(Arr.size());
  for (int i=0;i<Arr.size();i++)
  {
    auto&item=Arr[i];
    auto&holder=holders[i];
    holder.eat(item);
  };
  Arr.clear();
  Space.Do();
  int skip_count=0;
  for (int i=int(holders.size())-1;skip_count<=int(holders.size());skip_count++,i=(!i?holders.size()-1:i-1))
  {
    auto&holder=holders[i];
    auto*pType=holder.GetType();
    bool skip=!pType->CanDestroy();
    if (skip)
    {
      QapDebugMsg("type : '"+holder.FullName+"'\nWTF?");
      continue;
    }
    holders[i].boom();
    std::swap(holder,holders.back());
    holders.pop_back();
    skip_count=0;
  }
  if (!holders.empty())
  {
    for (int i=0;i<holders.size();i++)
    {
      auto&holder=holders[i];
      auto&fn=holder.FullName;
      TType*pType=holder.GetType();
      int hc=pType->Self.P.HardCount;
      ;
    }
    bool please_no=true;
    QapAssert(holders.empty());
    holders.clear();
  }
}
TType*FindTypeByFullName(IEnvRTTI&Env,const string&FullName)
{
  auto&arr=Env.GetArr();
  for (int i=0;i<arr.size();i++)
  {
    auto*p=arr[i].Type.get();
    if (p->GetFullName()==FullName)
    {
      return p;
    }
  }
  return nullptr;
}
QapBitmapInfo::QapBitmapInfo(int W,int H):BH(BI.bmiHeader)
{
  ZeroMemory(&BI,sizeof(BI));
  BH.biSize=sizeof(BI.bmiHeader);
  BH.biWidth=W;
  BH.biHeight=H;
  BH.biPlanes=1;
  BH.biBitCount=32;
  BH.biSizeImage=W*H*4;
}
void FastBMP::Init(HDC DC,int W,int H)
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
void FastBMP::Free()
{
  QapAssert(DeleteObject(BMP));
  QapAssert(DeleteDC(MDC));
  delete[] mem;
}
QapMat4::QapMat4() {}
QapMat4::QapMat4(
  const float m00, const float m01, const float m02, const float m03,
  const float m10, const float m11, const float m12, const float m13,
  const float m20, const float m21, const float m22, const float m23,
  const float m30, const float m31, const float m32, const float m33
)
{
  {
    {
      m[0][0]=m00;
    }
    ;
    {
      m[0][1]=m01;
    }
    ;
    {
      m[0][2]=m02;
    }
    ;
    {
      m[0][3]=m03;
    }
    ;
  }
  ;;
  {
    {
      m[1][0]=m10;
    }
    ;
    {
      m[1][1]=m11;
    }
    ;
    {
      m[1][2]=m12;
    }
    ;
    {
      m[1][3]=m13;
    }
    ;
  }
  ;;
  {
    {
      m[2][0]=m20;
    }
    ;
    {
      m[2][1]=m21;
    }
    ;
    {
      m[2][2]=m22;
    }
    ;
    {
      m[2][3]=m23;
    }
    ;
  }
  ;;
  {
    {
      m[3][0]=m30;
    }
    ;
    {
      m[3][1]=m31;
    }
    ;
    {
      m[3][2]=m32;
    }
    ;
    {
      m[3][3]=m33;
    }
    ;
  }
  ;;
}
QapMat4 operator+(const QapMat4&m,const QapMat4&n)
{
  QapMat4 O;
  for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=m.m[i][j]+n.m[i][j];
  return O;
}
QapMat4 operator-(const QapMat4&m,const QapMat4&n)
{
  QapMat4 O;
  for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=m.m[i][j]-n.m[i][j];
  return O;
}
QapMat4 operator-(const QapMat4&m)
{
  QapMat4 O;
  for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=-m.m[i][j];
  return O;
}
QapMat4 operator*(const QapMat4&m,const QapMat4&n)
{
  return QapMat4(
        (m.m[0][0]*n.m[0][0]+m.m[0][1]*n.m[1][0]+m.m[0][2]*n.m[2][0]+m.m[0][3]*n.m[3][0]),(m.m[0][0]*n.m[0][1]+m.m[0][1]*n.m[1][1]+m.m[0][2]*n.m[2][1]+m.m[0][3]*n.m[3][1]),(m.m[0][0]*n.m[0][2]+m.m[0][1]*n.m[1][2]+m.m[0][2]*n.m[2][2]+m.m[0][3]*n.m[3][2]),(m.m[0][0]*n.m[0][3]+m.m[0][1]*n.m[1][3]+m.m[0][2]*n.m[2][3]+m.m[0][3]*n.m[3][3]),
        (m.m[1][0]*n.m[0][0]+m.m[1][1]*n.m[1][0]+m.m[1][2]*n.m[2][0]+m.m[1][3]*n.m[3][0]),(m.m[1][0]*n.m[0][1]+m.m[1][1]*n.m[1][1]+m.m[1][2]*n.m[2][1]+m.m[1][3]*n.m[3][1]),(m.m[1][0]*n.m[0][2]+m.m[1][1]*n.m[1][2]+m.m[1][2]*n.m[2][2]+m.m[1][3]*n.m[3][2]),(m.m[1][0]*n.m[0][3]+m.m[1][1]*n.m[1][3]+m.m[1][2]*n.m[2][3]+m.m[1][3]*n.m[3][3]),
        (m.m[2][0]*n.m[0][0]+m.m[2][1]*n.m[1][0]+m.m[2][2]*n.m[2][0]+m.m[2][3]*n.m[3][0]),(m.m[2][0]*n.m[0][1]+m.m[2][1]*n.m[1][1]+m.m[2][2]*n.m[2][1]+m.m[2][3]*n.m[3][1]),(m.m[2][0]*n.m[0][2]+m.m[2][1]*n.m[1][2]+m.m[2][2]*n.m[2][2]+m.m[2][3]*n.m[3][2]),(m.m[2][0]*n.m[0][3]+m.m[2][1]*n.m[1][3]+m.m[2][2]*n.m[2][3]+m.m[2][3]*n.m[3][3]),
        (m.m[3][0]*n.m[0][0]+m.m[3][1]*n.m[1][0]+m.m[3][2]*n.m[2][0]+m.m[3][3]*n.m[3][0]),(m.m[3][0]*n.m[0][1]+m.m[3][1]*n.m[1][1]+m.m[3][2]*n.m[2][1]+m.m[3][3]*n.m[3][1]),(m.m[3][0]*n.m[0][2]+m.m[3][1]*n.m[1][2]+m.m[3][2]*n.m[2][2]+m.m[3][3]*n.m[3][2]),(m.m[3][0]*n.m[0][3]+m.m[3][1]*n.m[1][3]+m.m[3][2]*n.m[2][3]+m.m[3][3]*n.m[3][3])
      );
}
QapMat4 operator*(const QapMat4 &m,float x)
{
  QapMat4 O;
  for (int i=0;i<4;i++)for (int j=0;j<4;j++)O.m[i][j]=x*m.m[i][j];
  return O;
}
QapMat4 Transpose(const QapMat4&m)
{
  return QapMat4(
        m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
        m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
        m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
        m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
      );
}
QapMat4 RotateZ(float angle)
{
  float c=cosf(angle),s=sinf(angle);
  return QapMat4(
        +c,+s,+0,+0,
        -s,+c,+0,+0,
        +0,+0,+1,+0,
        +0,+0,+0,+1
      );
}
QapMat4 Translate(const float x,const float y,const float z)
{
  return QapMat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        x,y,z,1
      );
}
QapMat4 Scale(const float x,const float y,const float z)
{
  return QapMat4(
        x,0,0,0,
        0,y,0,0,
        0,0,z,0,
        0,0,0,1
      );
}
QapMat4 Identity4()
{
  return QapMat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
      );
}
void QapD3DPresentParameters::DoReset()
{
  {
    ;
  }
  (this->pp)=(Zero(pp));
}
QapD3DPresentParameters::QapD3DPresentParameters()
{
  DoReset();
}
string QapD3DPresentParameters::ProxySys$$::GetFullName()
{
  return "QapD3DPresentParameters";
}
D3DPRESENT_PARAMETERS&QapD3DPresentParameters::SetToDef(HWND hWnd,bool VSync)
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
void QapD3D9::DoReset()
{
  {
    ;
  }
  (this->pD3D)=(nullptr);
}
QapD3D9::QapD3D9()
{
  DoReset();
}
string QapD3D9::ProxySys$$::GetFullName()
{
  return "QapD3D9";
}
QapD3D9::QapD3D9(QapD3D9&&Ref)
{
  DoReset();
  oper_set(std::move(Ref));
}
QapD3D9::~QapD3D9()
{
  Free();
}
void QapD3D9::oper_set(QapD3D9&&Ref)
{
  Free();
  this->pD3D=Ref.pD3D;
  Ref.pD3D=nullptr;
}
void QapD3D9::operator=(QapD3D9&&Ref)
{
  oper_set(std::move(Ref));
}
void QapD3D9::Init()
{
  Free();
  pD3D=Direct3DCreate9(D3D_SDK_VERSION);
  if (!pD3D)
  {
    QapDebugMsg("Cannot create Direct3D9");
    return;
  }
}
void QapD3D9::Free()
{
  if (pD3D)pD3D->Release();
}
void QapD3D9ResourceList::DoReset()
{
  {
    ;
  }
  (this->Arr)=(vector<QapD3D9Resource*>());
  (this->Lost)=(false);
}
QapD3D9ResourceList::QapD3D9ResourceList()
{
  DoReset();
}
string QapD3D9ResourceList::ProxySys$$::GetFullName()
{
  return "QapD3D9ResourceList";
}
QapD3D9ResourceList::QapD3D9ResourceList(QapD3D9ResourceList&&Ref)
{
  DoReset();
  oper_set(std::move(Ref));
}
QapD3D9ResourceList::~QapD3D9ResourceList()
{
  Free();
}
void QapD3D9ResourceList::oper_set(QapD3D9ResourceList&&Ref)
{
  Free();
  {
    this->Arr=std::move(Ref.Arr);
  }
  {
    this->Lost=std::move(Ref.Lost);
  }
}
void QapD3D9ResourceList::operator=(QapD3D9ResourceList&&Ref)
{
  oper_set(std::move(Ref));
}
void QapD3D9ResourceList::Free()
{
  Lost=false;
  QapAssert(Arr.empty());
}
void QapD3D9ResourceList::OnLost()
{
  Lost=true;
  for (int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    ex->OnLost();
  }
}
void QapD3D9ResourceList::OnReset()
{
  Lost=false;
  for (int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    ex->OnReset();
  }
}
bool QapD3D9ResourceList::HasRes(QapD3D9Resource*pRes,int*pIndex)
{
  for (int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if (ex!=pRes)continue;
    if (pIndex)*pIndex=i;
    return true;
  }
  if (pIndex)*pIndex=-1;
  return false;
}
void QapD3D9ResourceList::Reg(QapD3D9Resource*pRes)
{
  QapAssert(bool(pRes));
  QapAssert(!HasRes(pRes));
  Arr.push_back(pRes);
}
void QapD3D9ResourceList::UnReg(QapD3D9Resource*pRes)
{
  int i=-1;
  bool flag=HasRes(pRes,&i);
  if (!flag)
  {
    QapAssert(flag);
    return;
  }
  std::swap(Arr[i],Arr.back());
  Arr.pop_back();
}
void QapD3DDev9::DoReset()
{
  {
    ;
  }
  (this->PresParams)=(QapD3DPresentParameters());
  (this->pDev)=(nullptr);
  (this->Resources)=(QapD3D9ResourceList());
}
QapD3DDev9::QapD3DDev9()
{
  DoReset();
}
string QapD3DDev9::ProxySys$$::GetFullName()
{
  return "QapD3DDev9";
}
QapD3DDev9::QapD3DDev9(QapD3DDev9&&Ref)
{
  DoReset();
  oper_set(std::move(Ref));
}
QapD3DDev9::~QapD3DDev9()
{
  Free();
}
void QapD3DDev9::oper_set(QapD3DDev9&&Ref)
{
  Free();
  {
    this->PresParams=std::move(Ref.PresParams);
  }
  {
    this->pDev=std::move(Ref.pDev);
    Ref.pDev=nullptr;
  }
  {
    this->Resources=std::move(Ref.Resources);
  }
}
void QapD3DDev9::operator=(QapD3DDev9&&Ref)
{
  oper_set(std::move(Ref));
}
void QapD3DDev9::Init(HWND hWnd,QapD3D9&D3D)
{
  QapAssert(D3D.pD3D);
  Free();
  D3D.pD3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&PresParams.pp,&pDev);
  if (!pDev)
  {
    QapDebugMsg("Cannot create Direct3DDevice9");
    return;
  }
}
void QapD3DDev9::Free()
{
  if (pDev)pDev->Release();
}
void QapD3DDev9::ResetStates()
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
bool QapD3DDev9::BeginScene()
{
  if (Resources.Lost)
  {
    EndScene();
    return false;
  };
  pDev->BeginScene();
  ResetStates();
  return true;
}
bool QapD3DDev9::EndScene()
{
  if (Resources.Lost)
  {
    HRESULT hr=pDev->TestCooperativeLevel();
    if (hr!=D3DERR_DEVICENOTRESET)return false;
    pDev->Reset(&PresParams.pp);
    Resources.OnReset();
    return false;
  };
  pDev->EndScene();
  return !Resources.Lost;
}
bool QapD3DDev9::Present(const RECT*pSource,const RECT*pDest)
{
  if (!Resources.Lost)
  {
    Resources.Lost=D3DERR_DEVICELOST==pDev->Present(pSource,pDest,NULL,NULL);
    if (Resources.Lost)Resources.OnLost();
  }
  return !Resources.Lost;
}
void QapD3DDev9::Blend(BlendType Mode)
{
  pDev->SetRenderState(D3DRS_ALPHABLENDENABLE,Mode!=BT_NONE);
  if (Mode==BT_NONE)return;
  if (Mode==BT_SUB)
  {
    pDev->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, 0 );
    pDev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
    pDev->SetTextureStageState(0, D3DTSS_COLORARG1,D3DTA_TEXTURE);
    pDev->SetTextureStageState(0, D3DTSS_COLORARG2,D3DTA_DIFFUSE);
    pDev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
    pDev->SetTextureStageState(0, D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
    pDev->SetTextureStageState(0, D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);
    pDev->SetRenderState(D3DRS_BLENDOP,D3DBLENDOP_ADD);
    pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
    pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
    return;
  }
  if (Mode==BT_ADD)
  {
    pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
    pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
    return;
  }
}
void QapD3DDev9::Alpha(AlphaType Mode)
{
  pDev->SetRenderState(D3DRS_ALPHATESTENABLE,Mode!=AM_NONE);
  if (Mode==AM_NONE)return;
  if (Mode==AM_GEQUAL_ONE)
  {
    pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_GREATEREQUAL);
    pDev->SetRenderState(D3DRS_ALPHAREF,1);
    return;
  }
  if (Mode==AM_NEQUAL_MAX)
  {
    pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_NOTEQUAL);
    pDev->SetRenderState(D3DRS_ALPHAREF,255);
    return;
  }
}
void QapD3DDev9::OrthoLH(D3DMATRIX&out,float w,float h,float zn,float zf)
{
  QapMat4 mat=QapMat4(
        2.0/w,0,0,0,
        0,2.0/h,0,0,
        0,0,1/(zf-zn),0,
        0,0,-zn/(zf-zn),1
      );
  out=mat*Identity4();
}
void QapD3DDev9::Set2D(vec2d CamPos,real zoom,real ang,vec2i*pSize)
{
  auto&pp=PresParams.pp;
  vec2i v=pSize?*pSize:vec2i(pp.BackBufferWidth,pp.BackBufferHeight);
  QapMat4 matProj(Identity4());
  QapMat4 matView(Identity4());
  if ((v.x%2)||(v.y%2))
  {
    if (v.x%2)CamPos.x+=0.5f;
    if (v.y%2)CamPos.y+=0.5f;
  }
  QapMat4 matWorld(Translate(-CamPos.x,-CamPos.y,0)*Scale(zoom,zoom,1.0)*RotateZ(ang));
  OrthoLH(matProj,float(v.x),float(v.y),-1.0,1.0);
  pDev->SetTransform(D3DTS_PROJECTION,&matProj);
  pDev->SetTransform(D3DTS_VIEW,&matView);
  pDev->SetTransform(D3DTS_WORLD,&matWorld);
}
void QapD3DDev9::Clear2D(const QapColor&Color)
{
  pDev->Clear(0,nullptr,D3DCLEAR_TARGET,Color,1.0f,0);
}
void QapDev::TDynamicResource::operator=(OwnerClass*pOwner)
{
  this->pOwner=pOwner;
}
QapDev::TDynamicResource::TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr)
{
  if (pDev)pDev->Resources.Reg(this);
}
QapDev::TDynamicResource::~TDynamicResource()
{
  if (pDev)pDev->Resources.UnReg(this);
}
void QapDev::TDynamicResource::Mount(OwnerClass*pOwner,QapD3DDev9*pDev)
{
  QapAssert(pOwner);
  QapAssert(pDev);
  this->pOwner=pOwner;
  this->pDev=pDev;
  if (pDev)pDev->Resources.Reg(this);
}
void QapDev::TDynamicResource::OnLost()
{
  if (pOwner)
  {
    flag=bool(pOwner->VB);
    pOwner->Free();
  }
  else
  {
    QapDebugMsg("fail");
    flag=false;
  }
}
void QapDev::TDynamicResource::OnReset()
{
  if (pOwner&&flag)pOwner->ReInit();
}
QapDev::Ver::Ver():x(0),y(0),z(0),tu(0),tv(0) {}
QapDev::Ver::Ver(float x,float y,const QapColor&color,float u,float v):x(x),y(y),z(0),color(color),tu(u),tv(v) {}
QapDev::Ver::Ver(const vec2f&pos,const QapColor&color,float u,float v):x(pos.x),y(pos.y),z(0),color(color),tu(u),tv(v) {}
QapDev::Ver::Ver(const vec2f&pos,const QapColor&color,const vec2f&texcoord):x(pos.x),y(pos.y),z(0),color(color),tu(texcoord.x),tv(texcoord.y) {}
vec2f&QapDev::Ver::get_pos()
{
  return *(vec2f*)&x;
}
vec2f&QapDev::Ver::get_pos()const
{
  return *(vec2f*)&x;
}
vec2f&QapDev::Ver::get_tpos()
{
  return *(vec2f*)&tu;
}
vec2f&QapDev::Ver::get_tpos()const
{
  return *(vec2f*)&tu;
}
QapDev::BatchScope::BatchScope(QapDev&RD):RD(RD)
{
  flag=!RD.Batching;
  if (flag)RD.BeginBatch();
}
QapDev::BatchScope::~BatchScope()
{
  if (flag)RD.EndBatch();
}
void QapDev::DoReset()
{
  {
    ;
  }
  (this->DynRes)=(this);
  (this->pDev)=(nullptr);
  (this->VB)=(nullptr);
  (this->IB)=(nullptr);
  (this->VBA)=(nullptr);
  (this->IBA)=(nullptr);
  (this->color)=(0xFFFFFFFF);
  (this->VPos)=(0);
  (this->IPos)=(0);
  (this->MaxVPos)=(0);
  (this->MaxIPos)=(0);
  (this->DIPs)=(0);
  (this->Verts)=(0);
  (this->Tris)=(0);
  (this->BlendMode)=(BlendType::BT_SUB);
  (this->AlphaMode)=(AlphaType::AM_NONE);
  (this->Batching)=(false);
  (this->Textured)=(false);
  detail::FieldTryDoReset(this->xf);
  detail::FieldTryDoReset(this->txf);
}
QapDev::QapDev()
{
  DoReset();
}
string QapDev::ProxySys$$::GetFullName()
{
  return "QapDev";
}
QapDev::~QapDev()
{
  Free();
}
void QapDev::ReInit()
{
  Init(MaxVPos,MaxIPos);
}
void QapDev::MountDev(QapD3DDev9&Dev)
{
  this->pDev=Dev.pDev;
  this->DynRes.Mount(this,&Dev);
}
void QapDev::Init(int VCount,int ICount)
{
  if (!VB)
  {
    MaxVPos=VCount;
    MaxIPos=ICount;
    pDev->CreateVertexBuffer(VCount*sizeof(Ver),D3DUSAGE_DYNAMIC,FVF,D3DPOOL_DEFAULT,&VB,NULL);
    pDev->CreateIndexBuffer(ICount*sizeof(int),D3DUSAGE_DYNAMIC,D3DFMT_INDEX32,D3DPOOL_DEFAULT,&IB,NULL);
    VBA=0;
    IBA=0;
    VPos=0;
    IPos=0;
    DIPs=0;
    Verts=0;
    Tris=0;
    xf.set_ident();
    txf.set_ident();
  };
}
void QapDev::Free()
{
  if (VB)
  {
    VB->Release();
    VB=nullptr;
    VBA=nullptr;
  }
  if (IB)
  {
    IB->Release();
    IB=nullptr;
    IBA=nullptr;
  }
  VPos=0;
  IPos=0;
  Batching=false;
  BlendMode=BlendType::BT_SUB;
  AlphaMode=AlphaType::AM_NONE;
}
void QapDev::BeginBatch()
{
  Batching=true;
  VBA=0;
  IBA=0;
  VPos=0;
  IPos=0;
  if (!IB||!VB)return;
  IB->Lock(0,sizeof(int)*MaxIPos,(void **)&IBA,0);
  VB->Lock(0,sizeof(Ver)*MaxVPos,(void **)&VBA,0);
}
void QapDev::EndBatch()
{
  Batching=false;
  if (!IB||!VB)return;
  IB->Unlock();
  VB->Unlock();
  if (VPos&&IPos)
  {
    DIP();
  }
  VBA=0;
  IBA=0;
}
void QapDev::DIP()
{
  pDev->SetFVF(FVF);
  pDev->SetStreamSource(0,VB,0,sizeof(Ver));
  pDev->SetIndices(IB);
  pDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,VPos,0,IPos/3);
  DIPs++;
  Verts+=VPos;
  Tris+=IPos/3;
}
bool QapDev::IsBatching()
{
  return Batching;
}
int QapDev::GetIPos()
{
  return IPos;
}
int QapDev::GetVPos()
{
  return VPos;
}
int QapDev::GetDIPs()
{
  return DIPs;
}
int QapDev::GetVerts()
{
  return Verts;
}
int QapDev::GetTris()
{
  return Tris;
}
const QapColor&QapDev::GetColor()
{
  return color;
}
void QapDev::NextFrame()
{
  DIPs=0;
  Verts=0;
  Tris=0;
  SetBlendMode(BlendMode);
  SetAlphaMode(AlphaMode);
}
void QapDev::HackMode(bool Textured)
{
  this->Textured=Textured;
}
void QapDev::BindTex(int Stage,const nullptr_t)
{
  pDev->SetTexture(Stage,nullptr);
  Textured=false;
}
QapDev::Ver&QapDev::AddVertexRaw()
{
  return VBA[VPos++];
}
int QapDev::AddVertex(const Ver&Source)
{
  QapAssert(VPos<MaxVPos);
  Ver&Dest=VBA[VPos];
  Dest=Source;
  {
    vec2f&v=Dest.get_pos();
    v=xf*v;
  }
  if (Textured)
  {
    vec2f&v=Dest.get_tpos();
    v=txf*v;
  }
  return VPos++;
}
int QapDev::AddVertex(float x,float y,const QapColor&c,float u,float v)
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
int QapDev::AddVertex(const vec2f&pos,const QapColor&c,float u,float v)
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
int QapDev::AddVertex(const vec2f&pos,const QapColor&c,const vec2f&tpos)
{
  QapDev::Ver tmp;
  tmp.get_pos()=pos;
  tmp.z=0;
  tmp.color=c;
  tmp.get_tpos()=tpos;
  auto id=AddVertex(tmp);
  return id;
}
void QapDev::AddTris(int A,int B,int C)
{
  QapAssert(IPos+2<MaxIPos);
  QapAssert(A>=0&&A<MaxVPos);
  QapAssert(B>=0&&B<MaxVPos);
  QapAssert(C>=0&&C<MaxVPos);
  IBA[IPos++]=A;
  IBA[IPos++]=B;
  IBA[IPos++]=C;
}
void QapDev::SetColor(const QapColor&C)
{
  color=C;
}
void QapDev::SetTransform(transform2f const&val)
{
  xf=val;
}
transform2f QapDev::GetTransform()
{
  return xf;
}
void QapDev::SetTextureTransform(transform2f const&val)
{
  txf=val;
}
transform2f QapDev::GetTextureTransform()
{
  return txf;
}
QapDev::BlendType QapDev::GetBlendMode()
{
  return BlendMode;
}
QapDev::AlphaType QapDev::GetAlphaMode()
{
  return AlphaMode;
}
void QapDev::SetBlendMode(BlendType Mode)
{
  DynRes.pDev->Blend(BlendMode=Mode);
}
void QapDev::SetAlphaMode(AlphaType Mode)
{
  DynRes.pDev->Alpha(AlphaMode=Mode);
}
void QapDev::DrawSolidRect(const vec2d&a,const vec2d&b)
{
  BatchScope Scope(*this);
  {
    int n=VPos;
    {
      AddVertex(a.x,a.y,color,0.0f,1.0f);
    };
    {
      AddVertex(b.x,a.y,color,1.0f,1.0f);
    };
    {
      AddVertex(b.x,b.y,color,1.0f,0.0f);
    };
    {
      AddVertex(a.x,b.y,color,0.0f,0.0f);
    };
    AddTris(n+1,n+0,n+3);
    AddTris(n+3,n+2,n+1);
  }
}
void QapDev::DrawRect(const vec2i&ap,const vec2i&bp,int line_size)
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
void QapDev::DrawRect(const vec2d&a,const vec2d&b,int line_size)
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
void QapDev::DrawRectAsQuad(const vec2i&pos,const vec2i&size,int line_size)
{
  auto a=pos-size/2;
  auto b=a+size;
  DrawRect(a,b,line_size);
}
void QapDev::DrawRectAsQuad(const vec2d&pos,const vec2d&size,int line_size)
{
  auto hs=size*0.5;
  DrawRect(pos-hs,pos+hs,line_size);
}
void QapDev::DrawQuadWithHalfPixelOffset(int x,int y,int w,int h)
{
  DrawQuad(float(x)+0.5,float(y)-0.5,float(w),float(h));
}
void QapDev::DrawQuadWithHalfPixelOffset(const vec2i&p,int w,int h)
{
  DrawQuadWithHalfPixelOffset(p.x,p.y,w,h);
}
void QapDev::DrawQuadWithHalfPixelOffset(const vec2i&p,const vec2i&size)
{
  DrawQuadWithHalfPixelOffset(p.x,p.y,size.x,size.y);
}
void QapDev::DrawQuad(float x,float y,float w,float h)
{
  BatchScope Scope(*this);
  {
    int n=VPos;
    {
      AddVertex(x+(-0.5f)*w,y+(-0.5f)*h,color,0.0f,1.0f);
    };
    {
      AddVertex(x+(+0.5f)*w,y+(-0.5f)*h,color,1.0f,1.0f);
    };
    {
      AddVertex(x+(+0.5f)*w,y+(+0.5f)*h,color,1.0f,0.0f);
    };
    {
      AddVertex(x+(-0.5f)*w,y+(+0.5f)*h,color,0.0f,0.0f);
    };
    AddTris(n+1,n+0,n+3);
    AddTris(n+3,n+2,n+1);
  }
}
void QapDev::DrawQuad(float x,float y,float w,float h,float a)
{
  BatchScope Scope(*this);
  {
    vec2d OZ=Vec2dEx(a,1.0);
    vec2d O(x,y);
    int n=VPos;
    {
      AddVertex(vec2f(O+vec2d(-0.5f*w,-0.5f*h).UnRot(OZ)),color,0.0f,1.0f);
    };
    {
      AddVertex(vec2f(O+vec2d(+0.5f*w,-0.5f*h).UnRot(OZ)),color,1.0f,1.0f);
    };
    {
      AddVertex(vec2f(O+vec2d(+0.5f*w,+0.5f*h).UnRot(OZ)),color,1.0f,0.0f);
    };
    {
      AddVertex(vec2f(O+vec2d(-0.5f*w,+0.5f*h).UnRot(OZ)),color,0.0f,0.0f);
    };
    AddTris(n+1,n+0,n+3);
    AddTris(n+3,n+2,n+1);
  }
}
void QapDev::DrawQuad(float x,float y,const vec2d&size,float ang)
{
  DrawQuad(x,y,size.x,size.y,ang);
}
void QapDev::DrawQuad(const vec2d&pos,const vec2d&size,float ang)
{
  DrawQuad(pos.x,pos.y,size.x,size.y,ang);
}
void QapDev::DrawQuad(const vec2d&pos,const vec2d&size)
{
  DrawQuad(pos.x,pos.y,size.x,size.y);
}
void QapDev::DrawQuad(const vec2d&pos,float w,float h,float ang)
{
  DrawQuad(pos.x,pos.y,w,h,ang);
}
void QapDev::DrawQuad(const vec2d&pos,float w,float h)
{
  DrawQuad(pos.x,pos.y,w,h);
}
void QapDev::DrawTrigon(const vec2d&A,const vec2d&B,const vec2d&C)
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
void QapDev::DrawConvex(const vector<vec2d>&Points)
{
  BatchScope Scope(*this);
  {
    if (Points.empty())return;
    int c=Points.size();
    int n=VPos;
    for (int i=0;i<c;i++)AddVertex(Points[i],color,0.5,0.5);
    for (int i=2;i<c;i++)AddTris(n,n+i-1,n+i-0);
  }
}
void QapDev::DrawCircleOld(const vec2d&pos,real r,real ang,real ls,int seg)
{
  static PointArray PA;
  PA.resize(seg);
  for (int i=0;i<seg;i++)
  {
    vec2d v=Vec2dEx((real)i/(real)seg*2.0*Pi,r);
    PA[i]=pos+v;
  };
  DrawPolyLine(PA,ls,true);
}
void QapDev::DrawCircle(const vec2d&pos,real r,real ang,real ls,int seg)
{
  DrawCircleEx(pos,r-ls*0.5,r+ls*0.5,seg,ang);
}
void QapDev::DrawCircleEx(const vec2d&pos,real r0,real r1,int seg,real ang)
{
  int n=seg;
  if (n<=0)return;
  BatchScope Scope(*this);
  static vector<int> VID;
  VID.resize(n*2);
  for (int i=0;i<n;i++)
  {
    vec2d v=Vec2dEx(ang+Pi2*(real(i)/real(n)),1);
    VID[0+i]=AddVertex(pos+v*r0,color,0,0);
    VID[n+i]=AddVertex(pos+v*r1,color,0,0);
  }
  for (int i=0;i<n;i++)
  {
    int a=VID[0+(i+0)%n];
    int b=VID[0+(i+1)%n];
    int c=VID[n+(i+0)%n];
    int d=VID[n+(i+1)%n];
    AddTris(a,b,d);
    AddTris(d,c,a);
  }
}
void QapTexMem::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Arr);
  (this->W)=(0);
  (this->H)=(0);
}
string QapTexMem::ProxySys$$::GetFullName()
{
  return "QapTexMem";
}
QapTexMem::QapTexMem()
{
  DoReset();
}
QapTexMem::QapTexMem(const QapTexMem&Ref)
{
  oper_set(Ref);
}
void QapTexMem::operator=(const QapTexMem&Ref)
{
  oper_set(Ref);
}
void QapTexMem::oper_set(const QapTexMem&Ref)
{
  this->Arr=Ref.Arr;
  this->W=Ref.W;
  this->H=Ref.H;
}
QapTexMem::QapTexMem(QapTexMem&&Ref)
{
  oper_set(std::move(Ref));
}
void QapTexMem::operator=(QapTexMem&&Ref)
{
  oper_set(std::move(Ref));
}
void QapTexMem::oper_set(QapTexMem&&Ref)
{
  this->Self=std::move(Ref.Self);
  this->Arr=std::move(Ref.Arr);
  this->W=std::move(Ref.W);
  this->H=std::move(Ref.H);
}
QapTexMem QapTexMem::Clone()
{
  QapTexMem tmp;
  tmp=*this;
  return std::move(tmp);
}
void QapTexMem::CopyDataFrom(const QapTexMem&Ref)
{
  QapTexMem tmp;
  this->Arr=Ref.Arr;
  this->W=Ref.W;
  this->H=Ref.H;
}
void QapTexMem::MoveDataFrom(QapTexMem&Ref)
{
  QapTexMem tmp;
  this->Arr=std::move(Ref.Arr);
  this->W=std::move(Ref.W);
  Ref.W=0;
  this->H=std::move(Ref.H);
  Ref.H=0;
}
void QapTexMem::Init(int W,int H)
{
  this->W=W;
  this->H=H;
  Arr.Init(W*H);
}
void QapTexMem::Free()
{
  Arr.Free();
}
QapColor*QapTexMem::get()
{
  return Arr.get();
}
const QapColor*QapTexMem::get()const
{
  return Arr.get();
}
QapTexMem::operator bool()const
{
  return Arr;
}
void QapTexMem::InvertY()
{
  QapColor*pBits=Arr.get();
  for (int i=0;i<H/2;i++)
  {
    int a=W*(i);
    int b=W*(H-i-1);
    for (int j=0;j<W;j++)
    {
      std::swap(pBits[a+j],pBits[b+j]);
    }
  }
}
void QapTexMem::InvertX()
{
  QapColor*pBits=Arr.get();
  for (int i=0;i<H;i++)
  {
    QapColor*pLine=&pBits[i*W];
    for (int j=0;j<W/2;j++)
    {
      int a=j;
      int b=W-j-1;
      std::swap(pLine[a],pLine[b]);
    }
  }
}
void QapTexMem::GenRect(int TexSize)
{
  Init(TexSize,TexSize);
  auto*pT=get();
  for (int i=0;i<TexSize;i++)
  {
    for (int j=0;j<TexSize;j++)
    {
      *pT=0x80000000;
      pT++;
    }
  }
  RectLine(0,0,TexSize,TexSize,0xffffffff);
}
void QapTexMem::GenBall(int TexSize)
{
  Init(TexSize,TexSize);
  auto*pT=get();
  for (int i=0;i<TexSize;i++)
  {
    for (int j=0;j<TexSize;j++)
    {
      float x=i-TexSize/2;
      float y=j-TexSize/2;
      float r=(float)TexSize/2;
      float m=((x*x)+(y*y))/(r*r);
      if (m>1.0f)
      {
        *pT=0x00000000;
        pT++;
        continue;
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
void QapTexMem::GenQuad(int TexSize)
{
  Init(TexSize,TexSize);
  auto*pT=get();
  for (int i=0;i<TexSize;i++)
  {
    for (int j=0;j<TexSize;j++)
    {
      float x=i-TexSize/2+0.5f,y=j-TexSize/2+0.5f;
      float r=(float)TexSize/2;
      float m=((x*x*x*x)+(y*y*y*y))/(r*r*r*r);
      if (m>1.0f)
      {
        *pT=0x00000000;
        pT++;
        continue;
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
void QapTexMem::FillBorder(int x,int y,const QapTexMem&Source,int n)
{
  auto&Target=*this;
  if (!Source)
  {
    QapAssert(false);
    return;
  }
  int sW=Source.W;
  int sH=Source.H;
  int mX=min(W,x+sW);
  int mY=min(H,y+sH);
  auto*pS=Source.get();
  auto*pT=Target.get();
  if (1)
  {
    {
      auto src=pS[(00-0)+(00-0)*sW];
      for (int i=0;i<n;i++)for (int j=0;j<n;j++)if ((y+(j+(00-n)))>=0)if ((y+(j+(00-n)))<H)if ((x+(i+(00-n)))<W)if ((x+(i+(00-n)))>=0)pT[(x+(i+(00-n)))+(y+(j+(00-n)))*W]=(src);;
    };
    {
      auto src=pS[(sW-1)+(00-0)*sW];
      for (int i=0;i<n;i++)for (int j=0;j<n;j++)if ((y+(j+(00-n)))>=0)if ((y+(j+(00-n)))<H)if ((x+(i+(sW-0)))<W)if ((x+(i+(sW-0)))>=0)pT[(x+(i+(sW-0)))+(y+(j+(00-n)))*W]=(src);;
    };
    {
      auto src=pS[(sW-1)+(sH-1)*sW];
      for (int i=0;i<n;i++)for (int j=0;j<n;j++)if ((y+(j+(sH-0)))>=0)if ((y+(j+(sH-0)))<H)if ((x+(i+(sW-0)))<W)if ((x+(i+(sW-0)))>=0)pT[(x+(i+(sW-0)))+(y+(j+(sH-0)))*W]=(src);;
    };
    {
      auto src=pS[(00-0)+(sH-1)*sW];
      for (int i=0;i<n;i++)for (int j=0;j<n;j++)if ((y+(j+(sH-0)))>=0)if ((y+(j+(sH-0)))<H)if ((x+(i+(00-n)))<W)if ((x+(i+(00-n)))>=0)pT[(x+(i+(00-n)))+(y+(j+(sH-0)))*W]=(src);;
    };
  }
  if (1)
  {
    for (int k=1;k<=n;k++)
    {
      {
        int j=00+y;
        if (InDip(0,j-k,H-1))for (int i=max(0,x);i<mX;i++)
          {
            pT[i+(j-k)*W]=pS[(i-x)+(j-y)*sW];
          }
      }
      {
        int j=mY-1;
        if (InDip(0,j+k,H-1))for (int i=max(0,x);i<mX;i++)
          {
            pT[i+(j+k)*W]=pS[(i-x)+(j-y)*sW];
          }
      }
      {
        int i=00+x;
        if (InDip(0,i-k,W-1))for (int j=max(0,y);j<mY;j++)
          {
            pT[(i-k)+j*W]=pS[(i-x)+(j-y)*sW];
          }
      }
      {
        int i=mX-1;
        if (InDip(0,i+k,W-1))for (int j=max(0,y);j<mY;j++)
          {
            pT[(i+k)+j*W]=pS[(i-x)+(j-y)*sW];
          }
      }
    }
  }
  return;
}
void QapTexMem::FillMem(int x,int y,const QapTexMem&Source)
{
  auto&Target=*this;
  if (!Source)
  {
    QapAssert(false);
    return;
  }
  int sW=Source.W;
  int sH=Source.H;
  int mX=min(W,x+sW);
  int mY=min(H,y+sH);
  auto*pS=Source.get();
  auto*pT=Target.get();
  for (int j=max(0,y);j<mY;j++)
  {
    for (int i=max(0,x);i<mX;i++)
    {
      pT[i+j*W]=pS[(i-x)+(j-y)*sW];
    }
  }
  return;
}
void QapTexMem::DrawInHalfScale(const QapTexMem&Source,int count)
{
  if (count<0)return;
  if (!count)
  {
    CopyDataFrom(Source);
    return;
  }
  QapTexMem Src=Source;
  for (int i=0;i<count;i++)
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
    for (int y=0;y<tH;y++)for (int x=0;x<tW;x++)
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
void QapTexMem::DrawMemWithBlend(int x,int y,const QapTexMem&Source,const QapColor&color)
{
  auto&Target=*this;
  if (!Source)
  {
    QapAssert(false);
    return;
  }
  int sW=Source.W;
  int sH=Source.H;
  int mX=min(W,x+sW);
  int mY=min(H,y+sH);
  auto*pS=Source.get();
  auto*pT=Target.get();
  for (int j=max(0,y);j<mY;j++)
  {
    for (int i=max(0,x);i<mX;i++)
    {
      auto inp=pS[(i-x)+(j-y)*sW]*color;
      auto&out=pT[i+j*W];
      auto a=inp.a;
      auto b=255-a;
      out.a=inp.a;
      out.r=(out.r*b+inp.r*a)/255;
      out.g=(out.g*b+inp.g*a)/255;
      out.b=(out.b*b+inp.b*a)/255;
    }
  }
  return;
}
void QapTexMem::Clear(const QapColor&color)
{
  auto*pBits=get();
  for (int i=0;i<W*H;i++)pBits[i]=color;
}
void QapTexMem::FillLine(const int Y,const QapColor&Color)
{
  auto*pBits=get();
  for (int i=0;i<W;i++)
  {
    QapColor&pix=pBits[Y*W+i];
    pix=Color;
  }
}
void QapTexMem::FillColumn(const int X,const QapColor&Color)
{
  auto*pBits=get();
  for (int i=0;i<H;i++)
  {
    QapColor&pix=pBits[i*W+X];
    pix=Color;
  }
}
void QapTexMem::RectLine(int X,int Y,int W,int H,const QapColor&Color)
{
  FillLineEx(Y+0-0,X+0,X+W,Color);
  FillLineEx(Y+H-1,X+0,X+W,Color);
  FillColomnEx(X+0-0,Y+0,Y+H,Color);
  FillColomnEx(X+W-1,Y+0,Y+H,Color);
}
void QapTexMem::FillLineEx(const int Y,const int X0,const int X1,const QapColor&Color)
{
  auto*pBits=get();
  int x0=Clamp<int>(X0,0,W);
  int x1=Clamp<int>(X1,0,W);
  if (x0>x1)std::swap(x0,x1);
  for (int i=x0;i<x1;i++)
  {
    QapColor&pix=pBits[Y*W+i];
    pix=Color;
  }
}
void QapTexMem::FillColomnEx(const int X,const int Y0,const int Y1,const QapColor&Color)
{
  auto*pBits=get();
  int y0=Clamp<int>(Y0,0,H);
  int y1=Clamp<int>(Y1,0,H);
  if (y0>y1)std::swap(y0,y1);
  for (int i=y0;i<y1;i++)
  {
    QapColor&pix=pBits[i*W+X];
    pix=Color;
  }
}
void QapTexMem::CopyAlpha(QapTexMem&Alpha)
{
  auto*pBits=get();
  auto*pAlphaBits=get();
  if (Alpha.W!=W||Alpha.H!=H)return;
  for (int i=0;i<W*H;i++)pBits[i].a=pAlphaBits[i].a;
}
void QapTexMem::CalcAlpha()
{
  auto*pBits=get();
  for (int i=0;i<W*H;i++)pBits[i].a=pBits[i].GetLuminance();
}
void QapTexMem::CalcAlpha(const QapColor&Color,int threshold)
{
  auto*pBits=get();
  for (int i=0;i<W*H;i++)pBits[i].a=pBits[i]==Color?0:255;
  const QapColor&c=Color;
  int t=threshold;
  int t3=t*3;
  for (int i=0;i<W*H;i++)
  {
    QapColor&p=pBits[i];
    int fr=abs(int(p.r)-int(c.r));;
    int fg=abs(int(p.g)-int(c.g));;
    int fb=abs(int(p.b)-int(c.b));;
    int sum=fr+fg+fb;
    p.a=sum>t3?255:t3?255*sum/t3:0;
  }
}
void QapTexMem::DrawSolidCircle(int x,int y,int r,const QapColor&color)
{
  auto rr=r*r;
  int mX=min(W,x+r);
  int mY=min(H,y+r);
  auto*pT=get();
  for (int j=max(0,y-r);j<mY;j++)
  {
    for (int i=max(0,x-r);i<mX;i++)
    {
      auto px=i-x;
      auto py=j-y;
      if (px*px+py*py>=rr)continue;
      auto&out=pT[i+j*W];
      out=color;
    }
  }
}
void QapTexMem::DrawSolidQuad(int x,int y,int w,int h,const QapColor&color)
{
  int mX=min(W,x+w/2);
  int mY=min(H,y+h/2);
  auto*pT=get();
  for (int j=max(0,y-h/2);j<mY;j++)
  {
    for (int i=max(0,x-w/2);i<mX;i++)
    {
      auto&out=pT[i+j*W];
      out=color;
    }
  }
}
void QapTexMem::FillChannel(const QapColor&Source,DWORD BitMask)
{
  auto*pBits=get();
  for (int i=0;i<W*H;i++)
  {
    QapColor&C=pBits[i];
    C=(~BitMask&C)|(BitMask&Source);
  };
}
void QapTexMem::BlurTexture(int PassCount)
{
  auto*pBits=get();
  if (!pBits||!W||!H)return;
  static vector<QapColor> vMem;
  vMem.resize(W*H);
  if (W*H!=Arr.Mem.size)
  {
    QapDebugMsg("WTF?");
    return;
  }
  auto*pBuff=&vMem[0];
  static const int BBM[]=
  {
    1,2,1,
    2,4,2,
    1,2,1
  };
  static int MartixSum=0;
  if (!MartixSum)
  {
    for (int i=0;i<lenof(BBM);i++)MartixSum+=BBM[i];
  }
  QapAssert(MartixSum==16);
  const int PosRange[]=
  {
    -W-1,-W,-W+1,
    -1-0,+0,-0+1,
    +W-1,+W,+W+1
  };
  for (int PassId=0;PassId<PassCount;PassId++)
  {
    memcpy_s(pBuff,sizeof(QapColor)*vMem.size(),pBits,Arr.Mem.size*sizeof(QapColor));
    for (int j=1;j<H-1;j++)
    {
      for (int i=1;i<W-1;i++)
      {
        auto&out=pBits[j*W+i];
        auto cur_id=j*W+i;
        vec4i buff;
        for (int t=0;t<9;t++)
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
void QapTexFile::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->FN);
  detail::FieldTryDoReset(this->Mem);
}
QapTexFile::QapTexFile()
{
  DoReset();
}
QapTexFile::QapTexFile(QapTexFile&&_Right)
{
  operator=(std::move(_Right));
}
void QapTexFile::operator=(QapTexFile&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->FN=std::move(_Right.FN);;
  this->Mem=std::move(_Right.Mem);;
}
string QapTexFile::ProxySys$$::GetFullName()
{
  return "QapTexFile";
}
void QapTexFile::Load()
{
  LoadTextureFromFile(Mem,FN);
}
void QapTexFile::Save()
{
  SaveTextureToFile(Mem,FN);
}
void QapTex::TDynamicResource::operator=(OwnerClass*pOwner)
{
  this->pOwner=pOwner;
}
QapTex::TDynamicResource::TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr)
{
  if (pDev)pDev->Resources.Reg(this);
}
QapTex::TDynamicResource::~TDynamicResource()
{
  if (pDev)pDev->Resources.UnReg(this);
}
void QapTex::TDynamicResource::Mount(OwnerClass*pOwner,QapD3DDev9*pDev)
{
  QapAssert(pOwner);
  QapAssert(pDev);
  this->pOwner=pOwner;
  this->pDev=pDev;
  if (pDev)pDev->Resources.Reg(this);
}
void QapTex::TDynamicResource::OnLost()
{
  if (pOwner)
  {
    flag=bool(pOwner->Tex);
    pOwner->Free();
  }
  else
  {
    QapDebugMsg("fail");
    flag=false;
  }
}
void QapTex::TDynamicResource::OnReset()
{
  if (pOwner&&flag)pOwner->ReInit();
}
void QapTex::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  (this->W)=(0);
  (this->H)=(0);
  (this->DynRes)=(this);
  (this->Tex)=(nullptr);
}
QapTex::QapTex()
{
  DoReset();
}
string QapTex::ProxySys$$::GetFullName()
{
  return "QapTex";
}
QapTex::~QapTex()
{
  Free();
}
void QapTex::ReInit() {}
void QapTex::MountDev(QapD3DDev9&Dev)
{
  this->DynRes.Mount(this,&Dev);
}
void QapTex::Init(int W,int H,int Levels)
{
  Free();
  auto*Sys=DynRes.pDev;
  Sys->pDev->CreateTexture(W,H,Levels,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&Tex,NULL);
}
void QapTex::Free()
{
  if (!Tex)return;
  Tex->Release();
  Tex=nullptr;
}
QapTex::operator bool()const
{
  return Tex;
}
void QapTex::Bind(int lvl)
{
  auto*Sys=DynRes.pDev;
  if (!Sys)return;
  Sys->pDev->SetTexture(lvl,Tex);
}
void QapTex::operator=(const QapTex&)
{
  QapDebugMsg("fail");
}
void TResourceHolder::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Caption);
}
TResourceHolder::TResourceHolder()
{
  DoReset();
}
TResourceHolder::TResourceHolder(TResourceHolder&&_Right)
{
  operator=(std::move(_Right));
}
void TResourceHolder::operator=(TResourceHolder&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Caption=std::move(_Right.Caption);;
}
string TResourceHolder::ProxySys$$::GetFullName()
{
  return "TResourceHolder";
}
void QapResource::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Holders);
}
QapResource::QapResource()
{
  DoReset();
}
QapResource::QapResource(QapResource&&_Right)
{
  operator=(std::move(_Right));
}
void QapResource::operator=(QapResource&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Holders=std::move(_Right.Holders);;
}
string QapResource::ProxySys$$::GetFullName()
{
  return "QapResource";
}
QapResource::IEnv::operator IEnvRTTI&()
{
  return Env;
}
void QapResource::Do(IEnv&Env) {}
void QapResource::Run(IEnvRTTI&Env,QapD3DDev9*pDev)
{
  if (!pDev)return;
  IEnv env={Env,pDev};
  Do(env);
}
void QapResourceList::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Items);
}
QapResourceList::QapResourceList()
{
  DoReset();
}
QapResourceList::QapResourceList(QapResourceList&&_Right)
{
  operator=(std::move(_Right));
}
void QapResourceList::operator=(QapResourceList&&_Right)
{
  struct hidden
  {
    static void foo(QapResource(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    QapResource::operator=(std::move(_Right));;
  }
  this->Items=std::move(_Right.Items);;
}
string QapResourceList::ProxySys$$::GetFullName()
{
  return "QapResourceList";
}
void QapResourceList::Del() {}
void QapResourceList::Do(IEnv&Env)
{
  for (int i=0;i<Items.size();i++)
  {
    auto*ex=Items[i].get();
    if (!ex)continue;
    ex->Do(Env);
  }
}
void QapTexGen::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Mem);
  detail::FieldTryDoReset(this->Tex);
}
QapTexGen::QapTexGen()
{
  DoReset();
}
QapTexGen::QapTexGen(QapTexGen&&_Right)
{
  operator=(std::move(_Right));
}
void QapTexGen::operator=(QapTexGen&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Mem=std::move(_Right.Mem);;
  this->Tex=std::move(_Right.Tex);;
}
string QapTexGen::ProxySys$$::GetFullName()
{
  return "QapTexGen";
}
void QapTexGen::Gen(QapTexMem*Mem,QapTex*Tex,int MaxLevelCount)
{
  if (!Tex||!Mem)return;
  int W=Mem->W;
  int H=Mem->H;
  QapColor*pBits=Mem->get();
  Tex->W=W;
  Tex->H=H;
  QapAssert(W*H==Mem->Arr.Mem.size);
  int SW=1,SWC=0;
  for (int &i=SWC;SW<W;i++)SW*=2;
  if (SW>W)goto fail;
  int SH=1,SHC=0;
  for (int &i=SHC;SH<H;i++)SH*=2;
  if (SH>H)goto fail;
  if (0)
  {
fail:
    QapDebugMsg("NPOT("+IToS(W)+"x"+IToS(H)+")");
    return;
  }
  int Levels=min(MaxLevelCount,min(SWC,SHC));
  IDirect3DTexture9*&tex=Tex->Tex;
  Tex->Init(W,H,Levels);
  if (!tex)
  {
    QapDebugMsg("fail");
    return;
  }
  D3DLOCKED_RECT rect[16];
  struct QapARGB
  {
    BYTE B,G,R,A;
  };
  QapARGB* pBitsEx[16];
  for (int i=0;i<Levels;i++)
  {
    tex->LockRect(i,&rect[i],NULL,0);
    pBitsEx[i]=(QapARGB*)rect[i].pBits;
  };
  {
    QapColor* pDestBits=(QapColor*)rect[0].pBits;
    memcpy_s(pDestBits,SW*SH*sizeof(QapColor),pBits,SW*SH*sizeof(QapColor));
    SW/=2;
    SH/=2;
  }
  for (int k=1;k<Levels;k++)
  {
    QapARGB *PC=(QapARGB*)rect[k].pBits;
    for (int j=0;j<SH;j++)
      for (int i=0;i<SW;i++)
      {
        QapARGB A[4]={pBitsEx[k-1][0+2*0*SW+2*i+4*j*SW],pBitsEx[k-1][0+2*1*SW+2*i+4*j*SW],pBitsEx[k-1][1+2*0*SW+2*i+4*j*SW],pBitsEx[k-1][1+2*1*SW+2*i+4*j*SW]};
        float AF[4]={0,0,0,0};
        for (int t=0;t<4;t++)
        {
          AF[0]+=A[t].R;
          AF[1]+=A[t].G;
          AF[2]+=A[t].B;
          AF[3]+=A[t].A;
        };
        for (int t=0;t<4;t++)AF[t]*=0.25*(1.0/255.0);
        QapColor PCC=D3DCOLOR_COLORVALUE(AF[0],AF[1],AF[2],AF[3]);
        *PC=*((QapARGB*)&PCC);
        PC++;
      }
    SW/=2;
    SH/=2;
  }
  for (int i=0;i<Levels;i++)tex->UnlockRect(i);
}
void QapTexGen::Do()
{
  if (!Mem||!Tex)return;
  auto*mem=Mem.get();
  auto*tex=Tex.get();
  Gen(mem,tex);
  if (0)
  {
    static int i=0;
    i++;
    SaveTextureToFile(*mem,"hack"+IToS(i)+".png");
  }
}
void QapTexObject::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->File);
  detail::FieldTryDoReset(this->Tex);
  detail::FieldTryDoReset(this->Gen);
}
QapTexObject::QapTexObject()
{
  DoReset();
}
QapTexObject::QapTexObject(QapTexObject&&_Right)
{
  operator=(std::move(_Right));
}
void QapTexObject::operator=(QapTexObject&&_Right)
{
  struct hidden
  {
    static void foo(QapResource(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    QapResource::operator=(std::move(_Right));;
  }
  this->File=std::move(_Right.File);;
  this->Tex=std::move(_Right.Tex);;
  this->Gen=std::move(_Right.Gen);;
}
string QapTexObject::ProxySys$$::GetFullName()
{
  return "QapTexObject";
}
void QapTexObject::SetToDef()
{
  Gen.Mem=&File.Mem;
  Gen.Tex=&Tex;
}
bool QapTexObject::t_fn_parser::main()
{
  if (fn.empty())return false;
  if (fn[0]!='?')return false;
  int e=0;
  func=ScanParam("?",fn,"(",e);
  if (e<0)return false;
  e+=func.size()+string("(").size();
  size=ScanParam("",fn,")",e);
  if (e<0)return false;
  value=SToI(size);
  return true;
}
void QapTexObject::Do(IEnv&Env)
{
  if (!Tex.DynRes.pDev)
  {
    QapAssert(!File.Mem);
    for (;;)
    {
      t_fn_parser parser;
      parser.fn=File.FN;
      if (parser.main())
      {
        if (parser.func=="GenRect")
        {
          File.Mem.GenRect(parser.value);
          break;
        }
        if (parser.func=="GenBall")
        {
          File.Mem.GenBall(parser.value);
          break;
        }
        if (parser.func=="GenQuad")
        {
          File.Mem.GenQuad(parser.value);
          break;
        }
        QapDebugMsg("texmem.func not found: "+parser.func+"\nFile.FN:\n"+File.FN);
        break;
      }
      File.Load();
      break;
    }
    Tex.MountDev(*Env.pDev);
  }
  if (!Gen.Tex->Tex)Gen.Do();
}
void QapResourceDetector::TDynamicResource::operator=(OwnerClass*pOwner)
{
  this->pOwner=pOwner;
}
QapResourceDetector::TDynamicResource::TDynamicResource():pOwner(nullptr),flag(false),pDev(nullptr)
{
  if (pDev)pDev->Resources.Reg(this);
}
QapResourceDetector::TDynamicResource::~TDynamicResource()
{
  if (pDev)pDev->Resources.UnReg(this);
}
void QapResourceDetector::TDynamicResource::Mount(OwnerClass*pOwner,QapD3DDev9*pDev)
{
  QapAssert(pOwner);
  QapAssert(pDev);
  this->pOwner=pOwner;
  this->pDev=pDev;
  if (pDev)pDev->Resources.Reg(this);
}
void QapResourceDetector::TDynamicResource::OnLost()
{
  if (pOwner)
  {
    flag=bool(pOwner->used);
    pOwner->PreFree();
  }
  else
  {
    QapDebugMsg("fail");
    flag=false;
  }
}
void QapResourceDetector::TDynamicResource::OnReset()
{
  if (pOwner&&flag)pOwner->PreInit();
}
void QapResourceDetector::DoReset()
{
  {
    ;
  }
  (this->needinit)=(false);
  (this->DynRes)=(this);
  (this->used)=(false);
}
QapResourceDetector::QapResourceDetector()
{
  DoReset();
}
string QapResourceDetector::ProxySys$$::GetFullName()
{
  return "QapResourceDetector";
}
QapResourceDetector::~QapResourceDetector()
{
  Free();
}
void QapResourceDetector::MountDev(QapD3DDev9&Dev)
{
  this->DynRes.Mount(this,&Dev);
}
void QapResourceDetector::PreInit()
{
  needinit=true;
}
void QapResourceDetector::PreFree()
{
  Free();
}
void QapResourceDetector::Init()
{
  used=true;
  needinit=false;
}
void QapResourceDetector::Free()
{
  used=false;
}
QapResourceDetector::operator bool()const
{
  return used;
}
void QapFontInfo::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Coords);
}
QapFontInfo::QapFontInfo()
{
  DoReset();
}
string QapFontInfo::ProxySys$$::GetFullName()
{
  return "QapFontInfo";
}
vec2i&QapFontInfo::operator[](int index)
{
  return Coords[index];
}
const vec2i&QapFontInfo::operator[](int index)const
{
  return Coords[index];
}
void QapFont::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Mem);
  detail::FieldTryDoReset(this->Info);
}
QapFont::QapFont()
{
  DoReset();
}
QapFont::QapFont(QapFont&&_Right)
{
  operator=(std::move(_Right));
}
void QapFont::operator=(QapFont&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Mem=std::move(_Right.Mem);;
  this->Info=std::move(_Right.Info);;
}
string QapFont::ProxySys$$::GetFullName()
{
  return "QapFont";
}
void QapFontGen::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  (this->Name)=(1?"FixedSys":"Arial");
  (this->Size)=(1?10:14);
  (this->Bold)=(false);
  (this->TexSize)=(512);
  detail::FieldTryDoReset(this->Font);
}
QapFontGen::QapFontGen()
{
  DoReset();
}
QapFontGen::QapFontGen(QapFontGen&&_Right)
{
  operator=(std::move(_Right));
}
void QapFontGen::operator=(QapFontGen&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Name=std::move(_Right.Name);;
  this->Size=std::move(_Right.Size);;
  this->Bold=std::move(_Right.Bold);;
  this->TexSize=std::move(_Right.TexSize);;
  this->Font=std::move(_Right.Font);;
}
string QapFontGen::ProxySys$$::GetFullName()
{
  return "QapFontGen";
}
void QapFontGen::Do(HWND hWnd)
{
  if (!Font)return;
  auto&Out=Font->Mem;
  auto&Info=Font->Info;
  CreateFontMem(hWnd,Out,Info,Name,Size,Bold,TexSize);
}
void QapFontGen::CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize)
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
          RECT Rect;
          SetRect(&Rect,0,0,TexSize,TexSize);
          FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
          SelectObject(MDC,FNT);
          SetBkMode(MDC,TRANSPARENT);
          SetTextColor(MDC,0xFFFFFF);
          for (int i=0;i<256;i++)TextOutA(MDC,i%16*(TexSize/16),i/16*(TexSize/16),(LPCSTR)&i,1);
          {
            QapBitmapInfo QBI(TexSize,TexSize);
            GetDIBits(MDC,BMP,0,TexSize,pix,&QBI.BI,DIB_RGB_COLORS);
          }
          for (int i=0;i<TexSize*TexSize;i++)
          {
            pix[i].a=pix[i].r;
            pix[i].r=255;
            pix[i].g=255;
            pix[i].b=255;
          }
          for (int i=0;i<256;i++)
          {
            SIZE cs;
            GetTextExtentPoint32A(MDC,(LPCSTR)&i,1,&cs);
            Info.Coords[i]=vec2i(cs.cx,cs.cy);
          }
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
void QapFontObject::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Font);
  detail::FieldTryDoReset(this->FontGen);
  detail::FieldTryDoReset(this->Tex);
  detail::FieldTryDoReset(this->TexGen);
}
QapFontObject::QapFontObject()
{
  DoReset();
}
QapFontObject::QapFontObject(QapFontObject&&_Right)
{
  operator=(std::move(_Right));
}
void QapFontObject::operator=(QapFontObject&&_Right)
{
  struct hidden
  {
    static void foo(QapResource(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    QapResource::operator=(std::move(_Right));;
  }
  this->Font=std::move(_Right.Font);;
  this->FontGen=std::move(_Right.FontGen);;
  this->Tex=std::move(_Right.Tex);;
  this->TexGen=std::move(_Right.TexGen);;
}
string QapFontObject::ProxySys$$::GetFullName()
{
  return "QapFontObject";
}
void QapFontObject::SetToDef()
{
  FontGen.Font=&Font;
  TexGen.Mem=&Font.Mem;
  TexGen.Tex=&Tex;
}
void QapFontObject::MountDev(QapD3DDev9*pDev)
{
  if (Tex.DynRes.pDev)return;
  Tex.MountDev(*pDev);
}
void QapFontObject::DoGenFont(QapD3DDev9*pDev)
{
  HWND hWnd=pDev->PresParams.pp.hDeviceWindow;
  FontGen.Do(hWnd);
}
void QapFontObject::DoGenTex()
{
  TexGen.Do();
}
void QapFontObject::Do(IEnv&Env)
{
  if (!Tex.DynRes.pDev)
  {
    QapAssert(!Font.Mem);
    HWND hWnd=Env.pDev->PresParams.pp.hDeviceWindow;
    FontGen.Do(hWnd);
    Tex.MountDev(*Env.pDev);
  }
  if (!TexGen.Tex->Tex)TexGen.Do();
}
int QapQ3Text::GetLength(const QapFont&Font,const string&Text)
{
  float xp=0;
  int i=0;
  while (i<Text.size())
  {
    if (Text[i]!='^')
    {
      int I=(byte)Text[i];
      float cx=float(Font.Info[I].x);
      xp+=cx;
      i++;
      continue;
    };
    i++;
    if (i>Text.size())continue;
    if ((Text[i]>='0')&&(Text[i]<='9'))
    {
      i++;
      continue;
    };
    if ((Text[i]>='A')&&(Text[i]<='F'))
    {
      i++;
      continue;
    };
  }
  return xp;
}
string QapQ3Text::ToNormal(const string&Text)
{
  string s;
  int i=0;
  while (i<Text.size())
  {
    if (Text[i]!='^')
    {
      s.push_back(Text[i++]);
      continue;
    }
    i++;
    if (i>Text.size())continue;
    if ((Text[i]>='0')&&(Text[i]<='9'))
    {
      i++;
      continue;
    };
    if ((Text[i]>='A')&&(Text[i]<='F'))
    {
      i++;
      continue;
    };
  }
  return s;
}
int QapQ3Text::AddVertexEx(QapDev*RD,float x,float y,QapColor c,float u,float v)
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
void QapQ3Text::DrawQapText(QapDev*RD,QapFont&Font,float X,float Y,const string&Text)
{
  static QapColor CT[]=
  {
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
    float xp=0;
    int i=0;
    vec2f ts=vec2f(Font.Mem.W,Font.Mem.H);
    vec2f off=vec2f(1.f/float(ts.x),1.f/float(ts.y))*0.5f;
    QapColor color=RD->GetColor();
    while (i<Text.size())
    {
      unsigned char UC=Text[i];
      if (UC!='^')
      {
        float U=off.x+float(UC%16)/16;
        float V=off.y+float(UC/16)/16;
        vec2f c=Font.Info[UC];
        vec2f t=vec2f(c.x/ts.x,c.y/ts.y);
        int A=AddVertexEx(RD,xp+X+(0.f),Y+(-c.y),color,U+(0.f),V+(+t.y));;
        int B=AddVertexEx(RD,xp+X+(c.x),Y+(-c.y),color,U+(t.x),V+(+t.y));;
        int C=AddVertexEx(RD,xp+X+(c.x),Y+(+0.f),color,U+(t.x),V+(+0.f));;
        int D=AddVertexEx(RD,xp+X+(0.f),Y+(+0.f),color,U+(0.f),V+(+0.f));;
        RD->AddTris(A,B,C);
        RD->AddTris(C,D,A);
        xp+=c.x;
        QuadCount++;
        i++;
        continue;
      };
      i++;
      if (i>Text.size())continue;
      UC=Text[i];
      if ((UC>='0')&&(UC<='9'))
      {
        color=CT[UC-'0'+0x0];
        i++;
        continue;
      };
      if ((UC>='A')&&(UC<='F'))
      {
        color=CT[UC-'A'+0xA];
        i++;
        continue;
      };
    }
    if (0)RD->SetColor(color);
  }
}
int QapText::GetLength(const QapFont&Font,const string&Text)
{
  int out=0;
  for (int i=0;i<Text.size();i++)
  {
    auto id=(byte)Text[i];
    auto cx=Font.Info[id].x;
    out+=cx;
  }
  return out;
}
int QapText::AddVertexEx(QapDev&qDev,float x,float y,QapColor c,float u,float v)
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
void QapText::add_draw_call(vector<t_draw_call>&out,char c,const vec2i&pos,const vec2i&size)
{
  t_draw_call tmp;
  tmp.c=c;
  tmp.pos=pos;
  tmp.size=size;
  out.push_back(std::move(tmp));
}
void QapText::DoNothing(unsigned char UC,const vec2i&p,const vec2i&s) {}
void QapText::Draw(QapDev&qDev,QapFont&Font,float X,float Y,const string&Text)
{
  DrawEx(qDev,Font,X,Y,Text,DoNothing);
}
int&get_QapClone_counter()
{
  static int counter=0;
  return counter;
}
real&QapClone_timer()
{
  static real time=0;
  return time;
}
ICompileUnit::ICompileUnit()
{
  ICompileUnitMan::get_man().add(this);
}
string cur_date_str()
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
void ISubProgram::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->Caption);
  (this->Enabled)=(true);
  detail::FieldTryDoReset(this->NeedRemove);
}
ISubProgram::ISubProgram()
{
  DoReset();
}
ISubProgram::ISubProgram(ISubProgram&&_Right)
{
  operator=(std::move(_Right));
}
void ISubProgram::operator=(ISubProgram&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Caption=std::move(_Right.Caption);;
  this->Enabled=std::move(_Right.Enabled);;
  this->NeedRemove=std::move(_Right.NeedRemove);;
}
string ISubProgram::ProxySys$$::GetFullName()
{
  return "ISubProgram";
}
ISubProgram::t_context::operator IEnvRTTI&()
{
  return Env;
}
void ISubProgram::Update(t_context&Env) {}
void ISubProgram::TryUpdate(t_context&con)
{
  if (NeedRemove)return;
  if (!Enabled)return;
  Update(con);
}
void TProgramNode::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Programs);
}
TProgramNode::TProgramNode()
{
  DoReset();
}
TProgramNode::TProgramNode(TProgramNode&&_Right)
{
  operator=(std::move(_Right));
}
void TProgramNode::operator=(TProgramNode&&_Right)
{
  struct hidden
  {
    static void foo(ISubProgram(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    ISubProgram::operator=(std::move(_Right));;
  }
  this->Programs=std::move(_Right.Programs);;
}
string TProgramNode::ProxySys$$::GetFullName()
{
  return "TProgramNode";
}
void TProgramNode::ForceUpdate(t_context&con)
{
  auto&arr=Programs;
  for (int i=0;i<arr.size();i++)
  {
    auto*ex=arr[i].get();
    if (!ex)continue;
    ex->TryUpdate(con);
  }
}
void TProgramNode::Update(t_context&con)
{
  if (!Enabled)return;
  ForceUpdate(con);
}
TAutoPtr<ISubProgram>&TProgramNode::front()
{
  return Programs.front();
}
TAutoPtr<ISubProgram>&TProgramNode::back()
{
  return Programs.back();
}
bool TProgramNode::empty()const
{
  return Programs.empty();
}
void IUnitProgram::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  (this->Deaded)=(false);
}
IUnitProgram::IUnitProgram()
{
  DoReset();
}
IUnitProgram::IUnitProgram(IUnitProgram&&_Right)
{
  operator=(std::move(_Right));
}
void IUnitProgram::operator=(IUnitProgram&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->Deaded=std::move(_Right.Deaded);;
}
string IUnitProgram::ProxySys$$::GetFullName()
{
  return "IUnitProgram";
}
void IUnitProgram::OnBuild(TBuildContext&Context) {}
void IUnitProgram::Update(IEnvRTTI&Env) {}
void TReloadDetector::DoReset()
{
  {
    ;
  }
  (this->needinit)=(false);
  (this->fresh)=(true);
}
TReloadDetector::TReloadDetector()
{
  DoReset();
}
string TReloadDetector::ProxySys$$::GetFullName()
{
  return "TReloadDetector";
}
void TReloadDetector::Init()
{
  fresh=false;
  needinit=false;
}
void TReloadDetector::Free()
{
  fresh=true;
}
void TReloadDetector::Update()
{
  needinit=fresh;
}
QapKeyboard::TKeyState::TKeyState()
{
  SetToDef();
}
void QapKeyboard::TKeyState::SetToDef()
{
  for (int i=0;i<MAX_KEY;i++)data[i]=false;
}
bool&QapKeyboard::TKeyState::operator[](int index)
{
  if (!InDip<int>(0,index,MAX_KEY-1))
  {
    QapDebugMsg("bad index");
    static bool tmp;
    return tmp;
  }
  return data[index];
}
const bool&QapKeyboard::TKeyState::operator[](int index)const
{
  if (!InDip<int>(0,index,MAX_KEY-1))
  {
    QapDebugMsg("bad index");
    static bool tmp;
    return tmp;
  }
  return data[index];
}
void QapKeyboard::DoReset()
{
  {
    ;
  }
  (this->LastKey)=(0);
  (this->LastChar)=(0);
  detail::FieldTryDoReset(this->NeedReset);
  (this->News)=(false);
  detail::FieldTryDoReset(this->Down);
  detail::FieldTryDoReset(this->Changed);
}
QapKeyboard::QapKeyboard()
{
  DoReset();
}
string QapKeyboard::ProxySys$$::GetFullName()
{
  return "QapKeyboard";
}
void QapKeyboard::operator=(const QapKeyboard&)
{
  QapDebugMsg("QapKeyboard is noncopyable");
}
void QapKeyboard::try_reset()
{
  if (!NeedReset)return;
  reset();
}
void QapKeyboard::reset()
{
  NeedReset=false;
  LastKey=0;
  LastChar=0;
  News=false;
  Down.SetToDef();
  Changed.SetToDef();
}
void QapKeyboard::KeyUpdate(int Key,bool Value)
{
  if (Value)LastKey=Key;
  Down[Key]=Value;
  Changed[Key]=true;
}
void QapKeyboard::CharUpdate(char c)
{
  LastChar=c;
  News=true;
}
void QapKeyboard::Sync()
{
  this->News=false;
  Changed.SetToDef();
}
bool QapKeyboard::OnDown(int index)const
{
  return Changed[index]&&Down[index];
}
void eQuad::DoReset()
{
  {
    ;
  }
  (this->x)=(320);
  (this->y)=(240);
  (this->w)=(320);
  (this->h)=(240);
}
eQuad::eQuad()
{
  DoReset();
}
eQuad::eQuad(eQuad&&_Right)
{
  operator=(std::move(_Right));
}
void eQuad::operator=(eQuad&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->x=std::move(_Right.x);;
  this->y=std::move(_Right.y);;
  this->w=std::move(_Right.w);;
  this->h=std::move(_Right.h);;
}
string eQuad::ProxySys$$::GetFullName()
{
  return "eQuad";
}
void eQuad::Set(int x,int y,int w,int h)
{
  this->x=x;
  this->y=y;
  this->w=w;
  this->h=h;
}
vec2i&eQuad::GetPos()
{
  return *(vec2i*)(void*)(&this->x);
}
vec2i&eQuad::GetSize()
{
  return *(vec2i*)(void*)(&this->w);
}
void eQuad::SetAs(const vec2i&pos,const vec2i&size)
{
  GetPos()=pos;
  GetSize()=size;
}
RECT eQuad::GetWinRect()
{
  RECT tmp={x,y,x+w,y+h};
  return tmp;
}
void eQuad::SetWinRect(const RECT&rect)
{
  eQuad&r=*(eQuad*)(void*)(&rect);
  Set(r.x,r.y,r.w-r.x,r.h-r.y);
}
void eQuad::SetSize(const SIZE&size)
{
  w=size.cx;
  h=size.cy;
}
eQuad eQuad::getFullScreen()
{
  eQuad tmp;
  auto mode=GetScreenMode();
  tmp.Set(0,0,mode.W,mode.H);
  return std::move(tmp);
}
void eQuad::setAtCenter(const eQuad&quad)
{
  QapAssert(quad.w>=w);
  QapAssert(quad.h>=h);
  x=(quad.w-w)/2;
  y=(quad.h-h)/2;
}
void eQuad::subpos(const eQuad&q)
{
  x-=q.x;
  y-=q.y;
}
void eQuad::setAtCenterScreen()
{
  setAtCenter(getFullScreen());
}
void IProgramD3D9::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
  detail::FieldTryDoReset(this->D9);
  detail::FieldTryDoReset(this->D9Dev);
  detail::FieldTryDoReset(this->UserCode);
}
IProgramD3D9::IProgramD3D9()
{
  DoReset();
}
IProgramD3D9::IProgramD3D9(IProgramD3D9&&_Right)
{
  operator=(std::move(_Right));
}
void IProgramD3D9::operator=(IProgramD3D9&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
  this->D9=std::move(_Right.D9);;
  this->D9Dev=std::move(_Right.D9Dev);;
  this->UserCode=std::move(_Right.UserCode);;
}
string IProgramD3D9::ProxySys$$::GetFullName()
{
  return "IProgramD3D9";
}
vec2i IProgramD3D9::WindowGetClientSize()
{
  QapDebugMsg("no way");
  return vec2i(128,128);
}
QapKeyboard&IProgramD3D9::GetKeyBoard()
{
  QapDebugMsg("no way");
  return *(QapKeyboard*)nullptr;
}
vec2i IProgramD3D9::WindowGetMousePos()
{
  QapDebugMsg("no way");
  return vec2i(128,128);
}
eQuad&IProgramD3D9::WindowGetQuad()
{
  QapDebugMsg("no way");
  return *(eQuad*)nullptr;
}
void IProgramD3D9::WindowUpdateMode()
{
  QapDebugMsg("no way");
  return;
}
void IProgramD3D9::WindowFullScreen(bool fullscreen)
{
  QapDebugMsg("no way");
  return;
}
int IProgramD3D9::WindowGetzDelta()
{
  QapDebugMsg("no way");
  return 0;
}
void ITreeDebuggerBranch::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->Self);
}
ITreeDebuggerBranch::ITreeDebuggerBranch()
{
  DoReset();
}
ITreeDebuggerBranch::ITreeDebuggerBranch(ITreeDebuggerBranch&&_Right)
{
  operator=(std::move(_Right));
}
void ITreeDebuggerBranch::operator=(ITreeDebuggerBranch&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->Self=std::move(_Right.Self);;
}
string ITreeDebuggerBranch::ProxySys$$::GetFullName()
{
  return "ITreeDebuggerBranch";
}
TRawPtr ITreeDebuggerBranch::GetRawPtr()
{
  QapDebugMsg("no way.");
  TRawPtr tmp(nullptr,nullptr);
  return tmp;
}
string ITreeDebuggerBranch::GetCode()
{
  QapDebugMsg("no way.");
  return "";
}
void QapPluginMan::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->Items);
}
QapPluginMan::QapPluginMan()
{
  DoReset();
}
QapPluginMan::QapPluginMan(QapPluginMan&&_Right)
{
  operator=(std::move(_Right));
}
void QapPluginMan::operator=(QapPluginMan&&_Right)
{
  struct hidden
  {
    static void foo(ISubProgram(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    ISubProgram::operator=(std::move(_Right));;
  }
  this->Items=std::move(_Right.Items);;
}
string QapPluginMan::ProxySys$$::GetFullName()
{
  return "QapPluginMan";
}
IUnitProgram*QapPluginMan::unsafe_AddItem(IEnvRTTI&Env,TType*pType)
{
  Items.resize(Items.size()+1);
  auto&back=Items.back();
  back.Product.pType=pType;
  back.Product.Init();
  return back.get();
}
void QapPluginMan::MakeAll(IEnvRTTI&Env,QapRenderProgram*pQRP,TType*pIUnitProgram)
{
  IUnitProgram::TBuildContext Context={Env,*this,*pQRP};
  auto&arr=Env.GetArr();
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    auto*pType=ex.Type.get();
    if (!pType->IsBasedOn(pIUnitProgram))continue;
    if (!pType->Factory)continue;
    unsafe_AddItem(Env,pType)->OnBuild(Context);
  }
}
void QapPluginMan::Update(t_context&con)
{
  auto&arr=Items;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (!ex)continue;
    auto*pItem=ex.get();
    pItem->Update(con.Env);
  }
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (!ex)continue;
    auto*pItem=ex.get();
    if (pItem->Deaded)ex=nullptr;
  }
  QapClean(Items);
}
bool QapPluginMan::empty()const
{
  return Items.empty();
}
GlobalEnv::GlobalEnv(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR lpCmdLine,
  int nCmdShow
):
    hInstance(hInstance),
    hPrevInstance(hPrevInstance),
    lpCmdLine(lpCmdLine),
    nCmdShow(nCmdShow)
{
  GlobalEnv::Get(this);
}
const GlobalEnv&GlobalEnv::Get(GlobalEnv*ptr)
{
  static GlobalEnv*pGE=nullptr;
  if (!pGE)std::swap(pGE,ptr);
  QapAssert(pGE&&!ptr);
  return *pGE;
}
bool IsKeyDown(int vKey)
{
  int i=GetAsyncKeyState(vKey);
  return i<0;
}
bool is_first_part_of(const string&text,const string&first_part)
{
  return first_part==text.substr(0,first_part.size());
}
string without_first_part(const string&text,const string&first_part)
{
  return text.substr(first_part.size());
}
bool remove_first_part_of(string&text,const string&first_part)
{
  if (!is_first_part_of(text,first_part))return false;
  text=without_first_part(text,first_part);
  return true;
}
void TOutDev::DevCmd::DoReset()
{
  {
    ;
  }
}
TOutDev::DevCmd::DevCmd()
{
  DoReset();
}
TOutDev::DevCmd::DevCmd(DevCmd&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::DevCmd::operator=(DevCmd&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string TOutDev::DevCmd::ProxySys$$::GetFullName()
{
  return "DevCmd";
}
void TOutDev::DevCmd::Use(IVisitor&A)
{
  QapDebugMsg("no way.");
}
void TOutDev::TMemberID::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->id)=(-1);
}
TOutDev::TMemberID::TMemberID()
{
  DoReset();
}
TOutDev::TMemberID::TMemberID(TMemberID&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::TMemberID::operator=(TMemberID&&_Right)
{
  struct hidden
  {
    static void foo(DevCmd(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DevCmd::operator=(std::move(_Right));;
  }
  this->id=std::move(_Right.id);;
}
string TOutDev::TMemberID::ProxySys$$::GetFullName()
{
  return "TMemberID";
}
TOutDev::TMemberID::TMemberID(int id):id(id) {}
void TOutDev::TMemberID::Use(IVisitor&A)
{
  A.Do(this);
}
TOutDev::TMemberID::SelfClass*TOutDev::TMemberID::UberCast(DevCmd*p)
{
  return IVisitor::UberCast<SelfClass>(p);
}
void TOutDev::TSubType::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
}
TOutDev::TSubType::TSubType()
{
  DoReset();
}
TOutDev::TSubType::TSubType(TSubType&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::TSubType::operator=(TSubType&&_Right)
{
  struct hidden
  {
    static void foo(DevCmd(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DevCmd::operator=(std::move(_Right));;
  }
}
string TOutDev::TSubType::ProxySys$$::GetFullName()
{
  return "TSubType";
}
void TOutDev::TSubType::Use(IVisitor&A)
{
  A.Do(this);
}
TOutDev::TSubType::SelfClass*TOutDev::TSubType::UberCast(DevCmd*p)
{
  return IVisitor::UberCast<SelfClass>(p);
}
void TOutDev::TVecID::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->id)=(-1);
}
TOutDev::TVecID::TVecID()
{
  DoReset();
}
TOutDev::TVecID::TVecID(TVecID&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::TVecID::operator=(TVecID&&_Right)
{
  struct hidden
  {
    static void foo(DevCmd(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DevCmd::operator=(std::move(_Right));;
  }
  this->id=std::move(_Right.id);;
}
string TOutDev::TVecID::ProxySys$$::GetFullName()
{
  return "TVecID";
}
TOutDev::TVecID::TVecID(int id):id(id) {}
void TOutDev::TVecID::Use(IVisitor&A)
{
  A.Do(this);
}
TOutDev::TVecID::SelfClass*TOutDev::TVecID::UberCast(DevCmd*p)
{
  return IVisitor::UberCast<SelfClass>(p);
}
void TOutDev::TChunk::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
}
TOutDev::TChunk::TChunk()
{
  DoReset();
}
TOutDev::TChunk::TChunk(TChunk&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::TChunk::operator=(TChunk&&_Right)
{
  struct hidden
  {
    static void foo(DevCmd(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DevCmd::operator=(std::move(_Right));;
  }
}
string TOutDev::TChunk::ProxySys$$::GetFullName()
{
  return "TChunk";
}
void TOutDev::TChunk::Use(IVisitor&A)
{
  A.Do(this);
}
TOutDev::TChunk::SelfClass*TOutDev::TChunk::UberCast(DevCmd*p)
{
  return IVisitor::UberCast<SelfClass>(p);
}
void TOutDev::TField::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
}
TOutDev::TField::TField()
{
  DoReset();
}
TOutDev::TField::TField(TField&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::TField::operator=(TField&&_Right)
{
  struct hidden
  {
    static void foo(DevCmd(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    DevCmd::operator=(std::move(_Right));;
  }
}
string TOutDev::TField::ProxySys$$::GetFullName()
{
  return "TField";
}
void TOutDev::TField::Use(IVisitor&A)
{
  A.Do(this);
}
TOutDev::TField::SelfClass*TOutDev::TField::UberCast(DevCmd*p)
{
  return IVisitor::UberCast<SelfClass>(p);
}
TOutDev::TContext::TContext():pCmd(nullptr),pType(nullptr),pValue(nullptr) {}
void TOutDev::TCmdVisitor::t_dev::err(const char*pcode,int line)
{
  ok=false;
  this->pcode=pcode;
  this->line=line;
}
TOutDev::TCmdVisitor::TCmdVisitor(t_dev&dev,TContext*pContext):dev(dev),pContext(pContext) {}
void TOutDev::TCmdVisitor::Do(TMemberID*p)
{
  int id=p->id;
  TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
  if (!(pMetaType))
  {
    dev.err("pMetaType",159);
    return;
  };
  if (!(id<pMetaType->Members.size()))
  {
    dev.err("id<pMetaType->Members.size()",161);
    return;
  };
  if (!(id>=0))
  {
    dev.err("id>=0",162);
    return;
  };
  auto&ex=pMetaType->Members[id];
  pContext->pValue=ex.getValue(pContext->pValue);
  pContext->pType=ex.Type.get();
  pContext->head=ex.Name;
}
void TOutDev::TCmdVisitor::Do(TSubType*p)
{
  pContext->pValue=pContext->pValue;
  pContext->pType=pContext->pType->GetSubType();
  pContext->head="";
  if (!(pContext->pType))
  {
    dev.err("pContext->pType",173);
    return;
  };
}
void TOutDev::TCmdVisitor::Do(TVecID*p)
{
  int id=p->id;
  TTypeVector*pMetaType=TTypeVector::UberCast(pContext->pType);
  if (!(pMetaType))
  {
    dev.err("pMetaType",179);
    return;
  };
  TType*pElemType=pMetaType->ElementType.get();
  auto*pVecAPI=pMetaType->VecAPI.get();
  int count=pVecAPI->GetCount(pContext->pValue);
  if (!((id>=0)&&(id<count)))
  {
    dev.err("(id>=0)&&(id<count)",183);
    return;
  };
  pContext->pValue=pVecAPI->GetItem(pContext->pValue,id);
  pContext->pType=pElemType;
  pContext->head="["+IToS(id)+"]";
}
void TOutDev::TCmdVisitor::Do(TChunk*p)
{
  TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(pContext->pType);
  if (!(pMetaType))
  {
    dev.err("pMetaType",191);
    return;
  };
  TAutoPtr<void>&value=*(TAutoPtr<void>*)pContext->pValue;
  pContext->pValue=value.get();
  pContext->pType=value.Product.pType.get();
  pContext->head="";
}
void TOutDev::TCmdVisitor::Do(TField*p)
{
  TTypeFieldPtr*pMetaType=TTypeFieldPtr::UberCast(pContext->pType);
  if (!(pMetaType))
  {
    dev.err("pMetaType",201);
    return;
  };
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
TOutDev::TCmdHeadVisitor::TCmdHeadVisitor()
{
  out="Root";
}
void TOutDev::TCmdHeadVisitor::add_dot()
{
  bool flag=out.substr(out.size()-2)=="->";
  if (!flag)out.push_back('.');
}
void TOutDev::TCmdHeadVisitor::Do(TMemberID*p)
{
  int id=p->id;
  TTypeStruct*pMetaType=TTypeStruct::UberCast(Context.pType);
  QapAssert(pMetaType);
  auto&ex=pMetaType->Members[id];
  add_dot();
  out+=ex.Name;
}
void TOutDev::TCmdHeadVisitor::Do(TSubType*p)
{
}
void TOutDev::TCmdHeadVisitor::Do(TVecID*p)
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
void TOutDev::TCmdHeadVisitor::Do(TChunk*p)
{
  TTypeAutoPtr*pMetaType=TTypeAutoPtr::UberCast(Context.pType);
  QapAssert(pMetaType);
  TAutoPtr<void>&value=*(TAutoPtr<void>*)Context.pValue;
  auto*pObjectType=value.Product.pType.get();
  if (pObjectType==pMetaType)
  {
    out+="->";
    return;
  }
  string fn=pObjectType->GetFullName();
  add_dot();
  out+="get{"+fn+"}()";
}
void TOutDev::TCmdHeadVisitor::Do(TField*p)
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
  if (true||object_type==field_type)
  {
    add_dot();
    out=out+"getValue<"+ft_fn+">()";
  }
  else
  {
  }
}
void TOutDev::TCmdOffsetVisitorEx::Do(TMemberID*p)
{
  int id=p->id;
  TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->Field.pType);
  QapAssert(pMetaType);
  auto&ex=pMetaType->Members[id];
  pContext->Offset+=ex.Offset;
  TContextPoint field={ex.Type.get(),ex.getValue(pContext->Field.pValue)};
  pContext->Field=field;
}
void TOutDev::TCmdOffsetVisitorEx::Do(TSubType*p)
{
  pContext->Field.pType=pContext->Field.pType->GetSubType();
}
void TOutDev::TCmdOffsetVisitorEx::Do(TVecID*p)
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
void TOutDev::TCmdOffsetVisitorEx::Do(TChunk*p)
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
void TOutDev::TCmdOffsetVisitorEx::Do(TField*p)
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
void TOutDev::TCmdCloneVisitor::Init(IEnvRTTI*pEnv)
{
  this->pEnv=pEnv;
}
void TOutDev::TCmdCloneVisitor::Do(TMemberID*p)
{
  auto*ptr=pCmd.build<TMemberID>(*pEnv);
  ptr->id=p->id;
}
void TOutDev::TCmdCloneVisitor::Do(TSubType*p)
{
  auto*ptr=pCmd.build<TSubType>(*pEnv);
}
void TOutDev::TCmdCloneVisitor::Do(TVecID*p)
{
  auto*ptr=pCmd.build<TVecID>(*pEnv);
  ptr->id=p->id;
}
void TOutDev::TCmdCloneVisitor::Do(TChunk*p)
{
  auto*ptr=pCmd.build<TChunk>(*pEnv);
}
void TOutDev::TCmdCloneVisitor::Do(TField*p)
{
  auto*ptr=pCmd.build<TField>(*pEnv);
}
void TOutDev::DoReset()
{
  {
    ;
  }
}
TOutDev::TOutDev()
{
  DoReset();
}
TOutDev::TOutDev(TOutDev&&_Right)
{
  operator=(std::move(_Right));
}
void TOutDev::operator=(TOutDev&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string TOutDev::ProxySys$$::GetFullName()
{
  return "TOutDev";
}
void TIsSameVisitor::TBranch::push_impl()
{
  items.push_back(top);
}
void TIsSameVisitor::TBranch::pop_impl()
{
  top=items.back();
  items.pop_back();
}
TOutDev::TContext&TIsSameVisitor::TBranch::back()
{
  return items.back();
}
TOutDev::TContext&TIsSameVisitor::TBranch::front()
{
  return items.front();
}
int TIsSameVisitor::TBranch::size()
{
  return items.size();
}
TOutDev::TContext&TIsSameVisitor::TBranch::operator[](int index)
{
  return items[index];
}
void TIsSameVisitor::TBranch::push(DevCmd*pCmd)
{
  QapAssert(!top.pCmd&&top.head.empty());
  push_impl();
  if (pCmd)
  {
    TCmdVisitor::t_dev dev;
    TCmdVisitor CV(dev,&top);
    pCmd->Use(CV);
    QapAssert(dev.ok);
    auto&back=this->back();
    back.head=std::move(top.head);
    back.pCmd=std::move(pCmd);
  }
  else
  {
    top.pType=nullptr;
    top.pValue=nullptr;
  }
  top.pCmd=nullptr;
  top.head.clear();
}
void TIsSameVisitor::TBranch::pop()
{
  QapAssert(!top.pCmd&&top.head.empty());
  pop_impl();
  top.pCmd=nullptr;
  top.head.clear();
}
void TIsSameVisitor::fail()
{
  ok=false;
}
void TIsSameVisitor::push(DevCmd*pCmd)
{
  bef.push(pCmd);
  aft.push(pCmd);
}
void TIsSameVisitor::pop()
{
  bef.pop();
  aft.pop();
}
TIsSameVisitor::TIsSameVisitor(TBranch&bef,TBranch&aft):bef(bef),aft(aft),ok(true),pTopType(bef.top.pType) {}
void TIsSameVisitor::Do(TTypeStruct*p)
{
  if (bef.top.pType!=aft.top.pType)return fail();
  auto*subtype=p->SubType.get();
  auto&arr=p->Members;
  if (subtype)
  {
    TOutDev::TSubType tmp;
    push(&tmp);
    pTopType->Use(*this);
    pop();
    if (!ok)return;
  }
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    TOutDev::TMemberID tmp(i);
    push(&tmp);
    pTopType->Use(*this);
    pop();
    if (!ok)return;
  }
}
void TIsSameVisitor::Do(TTypeArray*p)
{
  QapDebugMsg("no way");
  return fail();
}
void TIsSameVisitor::Do(TTypeSys*p)
{
  if (bef.top.pType!=aft.top.pType)return fail();
  auto*pbio=p->BinIO.get();
  auto result=pbio->IsSame(bef.top.pValue,aft.top.pValue);
  if (!result)return fail();
}
void TIsSameVisitor::Do(TTypeVector*p)
{
  if (bef.top.pType!=aft.top.pType)return fail();
  auto*VecAPI=p->VecAPI.get();
  int CountBef=VecAPI->GetCount(bef.top.pValue);
  int CountAft=VecAPI->GetCount(aft.top.pValue);
  if (CountBef!=CountAft)return fail();
  if (!CountBef)return;
  TType*elemType=p->ElementType.get();
  for (int i=0;i<CountBef;i++)
  {
    TOutDev::TVecID tmp(i);
    push(&tmp);
    pTopType->Use(*this);
    pop();
    if (!ok)return;
  }
}
void TIsSameVisitor::Do(TTypeSelfPtr*p)
{
  QapDebugMsg("no way");
}
void TIsSameVisitor::Do(TTypeAutoPtr*p)
{
  TAutoPtr<void>&valueBef=*(TAutoPtr<void>*)bef.top.pValue;
  TAutoPtr<void>&valueAft=*(TAutoPtr<void>*)aft.top.pValue;
  if (bool(valueBef)!=bool(valueAft))return fail();
  if (!valueBef)return;
  TOutDev::TChunk tmp;
  push(&tmp);
  pTopType->Use(*this);
  pop();
}
void TIsSameVisitor::Do(TTypeWeakPtr*p)
{
  QapDebugMsg("no way");
  return fail();
}
void TIsSameVisitor::Do(TTypeHardPtr*p)
{
  QapDebugMsg("no way");
  return fail();
}
void TIsSameVisitor::Do(TTypeVoidPtr*p)
{
  QapDebugMsg("deprecated");
  QapDebugMsg("no way");
  return fail();
}
void TIsSameVisitor::Do(TTypeFieldPtr*p)
{
  QapDebugMsg("deprecated");
  QapDebugMsg("no way");
  return fail();
}
string t_error_tool::t_subline::toCpp(const string&raw)
{
  CppString cpp=raw;
  return cpp.data;
}
int t_error_tool::t_subline::toCppLen(const string&raw)
{
  CppString cpp=raw;
  return cpp.data.size();
}
string t_error_tool::t_subline::gen(size_t count,char c)
{
  string tmp;
  tmp.resize(count,c);
  return tmp;
}
t_error_tool::t_subline t_error_tool::t_subline::go(const string&line,size_t offset)
{
  t_subline out;
  QapAssert(line.size()<=1024);
  if (offset>=line.size())
  {
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
t_error_tool::t_line_info t_error_tool::t_line_info::get(const string&mem,size_t pos)
{
  t_line_info out={0,0,false};
  out.go(mem,pos);
  return out;
}
void t_error_tool::t_line_info::go(const string&mem,size_t pos)
{
  QapAssert(pos<mem.size());
  line_id=0;
  curpos=0;
  ok=true;
  for (int i=0;i<pos;i++)
  {
    if (mem[i]=='\n')
    {
      line_id++;
      curpos=i+1;
      ok=true;
    }
  }
}
string t_error_tool::get_codefrag(const string&code,size_t pos)
{
  auto subline_go=t_subline::go;
  auto go=[&subline_go,&pos](const t_line_info&info,const string&line,size_t offset,const string&sep)->string
  {
    auto sub=subline_go(line,offset);
    QapAssert(sub.error.empty());
    return "{\"line\":"+IToS(info.line_id)+",\"pos\":"+IToS(pos-info.curpos)+"}\n\""+sub.cpp+"\" "+sep+"\n-"+sub.low;
  };
  QapAssert(!code.empty());
  QapAssert(pos<code.size());
  auto info=t_line_info::get(code,pos);
  if (!info.ok)
  {
    QapAssert(false);
  }
  int offset=pos-info.curpos;
  auto eol=code.find('\n',info.curpos);
  if (eol==string::npos)
  {
    auto line=code.substr(info.curpos,string::npos);
    return go(info,line,offset,"EOD");
  }
  auto line=code.substr(info.curpos,eol-info.curpos+1);
  return go(info,line,offset,"...");
}
QapStrFinder QapStrFinder::fromArr(const vector<string>&arr)
{
  QapStrFinder tmp;
  tmp.build(arr);
  return std::move(tmp);
}
void QapStrFinder::build(const vector<string>&arr)
{
  vecs.reserve(1024*8);
  qap_add_back(lines);
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    add_keyword(ex);
  }
}
void QapStrFinder::add_keyword(const string&keyword)
{
  auto id=keywords.size();
  keywords.push_back(keyword);
  int state=0;
  int last_pos=-1;
  for (int i=0;i<keyword.size();i++)
  {
    state=add(state,id,i,last_pos);
  }
}
int QapStrFinder::add(int line_id,int keyword_id,int pos,int&last_pos)
{
  const auto next_pos=pos+1;
  auto&kw=keywords[keyword_id];
  const auto c=kw[pos];
  int next_line=lines[line_id].cmds[c].next_line;
  bool eow=(next_pos==kw.size());
  bool need_new_line=(next_line==-1)&&!eow;
  if (need_new_line)
  {
    next_line=lines.size();
    auto&back=qap_add_back(lines);
  }
  auto&ex=lines[line_id].cmds[c];
  if (ex.arr_id<0)
  {
    ex.arr_id=vecs.size();
    qap_add_back(vecs);
  }
  auto&arr=vecs[ex.arr_id];
  arr.push_back(keyword_id);
  if (ex.pos==-1)
  {
    ex.pos=pos;
  }
  QapAssert(ex.pos==pos);
  ex.next_line=next_line;
  if (eow)
  {
    QapAssert(ex.last_pos!=next_pos);
    ex.last_pos=next_pos;
    QapAssert(last_pos!=next_pos);
    last_pos=next_pos;
  }
  if (last_pos!=-1)
  {
    ex.last_pos=last_pos;
  }
  if (ex.last_pos!=-1)last_pos=ex.last_pos;
  return ex.next_line;
}
void QapStrFinderFast::t_cmd::update(int next,bool eow,int kw_id)
{
  auto&cmd=*this;
  QapAssert(cmd.next==-1||next==cmd.next);
  cmd.next=next;
  if (!eow)return;
  write_eow(kw_id);
}
void QapStrFinderFast::t_cmd::write_eow(int kw_id)
{
  if (kw_id==end_id)return;
  QapAssert(-1==end_id);
  end_id=kw_id;
}
int QapStrFinderFast::t_node::read_cmd_next(uchar c)const
{
  return cmds[c].next;
}
int QapStrFinderFast::t_node::go_next(uchar c,int&end_id)const
{
  auto&cmd=cmds[c];
  end_id=cmd.end_id;
  return cmd.next;
}
QapStrFinderFast::t_cmd&QapStrFinderFast::t_node::read_cmd(uchar c)
{
  return cmds[c];
}
int QapStrFinderFast::t_item::read_cmd_next(uchar c)const
{
  if (this->c!=c)return -1;
  return cmd.next;
}
int QapStrFinderFast::t_item::go_next(uchar c,int&end_id)const
{
  if (this->c!=c)return -1;
  end_id=cmd.end_id;
  return cmd.next;
}
QapStrFinderFast::t_cmd&QapStrFinderFast::t_item::read_cmd(uchar c)
{
  QapAssert(this->c==c);
  return cmd;
}
void QapStrFinderFast::t_proxy::set_node(int id)
{
  this->id=id;
  this->type='N';
}
void QapStrFinderFast::t_proxy::set_item(int id)
{
  this->id=id;
  this->type='I';
}
void QapStrFinderFast::t_proxy::set_lazy(int id)
{
  this->id=id;
  this->type='L';
}
bool operator==(const QapStrFinderFast::t_find_result&a,const QapStrFinderFast::t_find_result&b)
{
  if (a.ok!=b.ok)return false;
  if (a.kw_id!=b.kw_id)return false;
  return true;
}
QapStrFinderFast QapStrFinderFast::fromArr(const vector<string>&arr)
{
  QapStrFinderFast tmp;
  tmp.build(arr);
  return std::move(tmp);
}
void QapStrFinderFast::rebuild()
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
  for (int i=0;i<keywords.size();i++)
  {
    auto&ex=keywords[i];
    add_loop(0,0,i);
  }
  int gg=1;
}
void QapStrFinderFast::build(const vector<string>&arr)
{
  keywords=arr;
  rebuild();
}
int QapStrFinderFast::add(int ptr,uchar c,int keyword_id,int pos,bool eow,bool&need_break)
{
  if (proxies[ptr].type=='L')
  {
    if (lazys[proxies[ptr].id].kw_id==keyword_id)
    {
      need_break=true;
      return -1;
    }
    unpack(ptr,keyword_id);
    QapAssert(proxies[ptr].type!='L');
  }
  int next=read_next(ptr,c);
  if (-1!=next)
  {
    if (!eow)
    {
      return next;
    }
    QapAssert(eow);
    unsafe_read_cmd(ptr,c).write_eow(keyword_id);
    return next;
  }
  bool need_new_line=(next==-1)&&!eow;
  if (need_new_line)
  {
    next=new_proxy();
  }
  write_next(ptr,c,next,eow,keyword_id,pos,need_break);
  return read_next(ptr,c);
}
void QapStrFinderFast::add_loop(int ptr,int pos,int kid)
{
  int state=ptr;
  auto&kw=keywords[kid];
  bool nb=false;
  for (int i=pos;i<kw.size();i++)
  {
    uchar c=kw[i];
    auto eow=kw.size()==i+1;
    state=add(state,c,kid,i,eow,nb);
    if (nb)break;
  }
}
void QapStrFinderFast::unpack(int ptr,int kb)
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
void QapStrFinderFast::write_next(int ptr,uchar c,int next,bool eow,int kw_id,int pos,bool&need_break)
{
  QapAssert(proxies[ptr].type!='L');
  auto&p=proxies[ptr];
  auto&t=p.type;
  auto&id=p.id;
  if (t=='E')
  {
    QapAssert(-1==id);
    if (eow)
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
  if (t=='N')
  {
    auto&node=nodes[id];
    auto&cmd=node.cmds[c];
    cmd.update(next,eow,kw_id);
    return;
  }
  if (t=='I')
  {
    auto&item=items[id];
    if (item.c==c)
    {
      auto&cmd=item.cmd;
      cmd.update(next,eow,kw_id);
      return;
    }
    if (item.c!=c)
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
QapStrFinderFast::t_cmd&QapStrFinderFast::unsafe_read_cmd(int ptr,uchar c)
{
  auto&p=proxies[ptr];
  auto&t=p.type;
  auto&id=p.id;
  if (t=='N')return nodes[id].read_cmd(c);
  if (t=='I')return items[id].read_cmd(c);
  QapDebugMsg("no way");
  return *(t_cmd*)nullptr;
}
int QapStrFinderFast::read_next(int ptr,uchar c)const
{
  auto&p=proxies[ptr];
  auto&t=p.type;
  auto&id=p.id;
  if (t=='E')return -1;
  if (t=='N')return nodes[id].read_cmd_next(c);
  if (t=='I')return items[id].read_cmd_next(c);
  if (t=='L')return -1;
  QapDebugMsg("no way");
  return -1;
}
int QapStrFinderFast::go_next_for_find(int ptr,uchar c,const string&mem,int&state,int&pos,int&next_pos,int&end_id)const
{
  end_id=-1;
  auto&p=proxies[ptr];
  auto&t=p.type;
  auto&id=p.id;
  QapAssert(t!='E');
  if (t=='N')return nodes[id].go_next(c,end_id);
  if (t=='I')return items[id].go_next(c,end_id);
  if (t=='L')
  {
    int gg=1;
    auto&L=lazys[id];
    QapAssert(L.pos==pos);
    auto&kw=keywords[L.kw_id];
    if (kw==mem)
    {
      pos=kw.size()-1;
      end_id=L.kw_id;
      return -1;
    }
    return -1;
  }
  QapDebugMsg("no way");
  return -1;
}
int QapStrFinderFast::new_proxy()
{
  int id=proxies.size();
  proxies.emplace_back();
  return id;
}
int QapStrFinderFast::new_node()
{
  int id=nodes.size();
  nodes.emplace_back();
  return id;
}
int QapStrFinderFast::new_item()
{
  if (!free_items.empty())
  {
    int id=free_items.back();
    free_items.pop_back();
    return id;
  };
  int id=items.size();
  items.emplace_back();
  return id;
}
int QapStrFinderFast::new_lazy()
{
  if (!free_lazys.empty())
  {
    int id=free_lazys.back();
    free_lazys.pop_back();
    return id;
  };
  int id=lazys.size();
  lazys.emplace_back();
  return id;
}
QapStrFinderFast::t_find_result QapStrFinderFast::find_impl(const string&mem,int&state,int&pos,int&next_pos,int&end_id)
{
  t_find_result fail={false,-1};
  auto n=mem.size();
  if (pos>=n)return fail;
  for (;pos<n;pos=next_pos)
  {
    next_pos=pos+1;
    const uchar c=mem[pos];
    state=go_next_for_find(state,c,mem,state,pos,next_pos,end_id);
    if (state!=-1)continue;
    if (end_id==-1)return fail;
    auto len=1+pos;
    if (n!=len)return fail;
    return {true,end_id};
  }
  QapAssert(state>=0);
  if (end_id==-1)return fail;
  return {true,end_id};
}
QapStrFinderFast::t_find_result QapStrFinderFast::find(const string&mem)
{
  int pos=0;
  int state=0;
  int next_pos=1;
  int end_id=-1;
  return find_impl(mem,state,pos,next_pos,end_id);
}
IEnvRTTI&i_dev::getEnv()
{
  QapDebugMsg("no way.");
  return *(IEnvRTTI*)nullptr;
}
void i_dev::push(t_fallback*ptr)
{
  QapDebugMsg("no way.");
}
void i_dev::pop(t_fallback*ptr)
{
  QapDebugMsg("no way.");
}
void i_dev::setPos(int pos)
{
  QapDebugMsg("no way.");
}
void i_dev::getPos(int&pos)
{
  QapDebugMsg("no way.");
}
bool i_dev::isSave()
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::isLoad()
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_any(string&body,const string&any)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_any(string&body,const CharMask&any)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_const_raw(const char*const ptr,size_t size)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_const(const string&str)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_end(string&body,const string&end)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_any_char(char&c,const string&any)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_any_char(char&c,const CharMask&any)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_any_str_from_vec(string&ref,const vector<string>&arr)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_any_str_from_vec(string&ref,const QapStrFinder&arr)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_blob(string&body,size_t count)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_dev::go_const(const char&ref)
{
  return go_const_raw(&ref,sizeof(ref));
}
void t_scope_tool::operator+=(bool value)
{
  ok=value;
}
int&get_qap_fallback_counter()
{
  static int counter=0;
  return counter;
}
t_fallback::t_fallback(i_dev&dev,const char*const ptr):dev(dev),ok(mandatory.ok),pos(-1)
{
  dev.push(this);
}
t_fallback::~t_fallback()
{
  dev.pop(this);
  get_qap_fallback_counter()++;
}
t_load_dev::t_load_dev(IEnvRTTI&Env,const string&mem,size_t pos):Env(Env),mem(mem),pos(pos),maxpos(pos) {}
void t_load_dev::push(t_fallback*ptr)
{
  ptr->pos=pos;
  maxpos=std::max(maxpos,pos);
}
void t_load_dev::pop(t_fallback*ptr)
{
  if (ptr->ok)return;
  if (pos==ptr->pos)return;
  pos=ptr->pos;
}
void t_load_dev::setPos(int pos)
{
  this->pos=pos;
}
void t_load_dev::getPos(int&pos)
{
  pos=this->pos;
}
IEnvRTTI&t_load_dev::getEnv()
{
  return Env;
}
bool t_load_dev::isSave()
{
  return false;
}
bool t_load_dev::isLoad()
{
  return true;
}
bool t_load_dev::go_any(string&body,const string&any)
{
  for (auto i=pos;i<mem.size();i++)
  {
    auto e=any.find(CToS(mem[i]));
    if (e!=string::npos)continue;
    body=mem.substr(pos,i-pos);
    pos=i;
    return !body.empty();
  }
  body=mem.substr(pos);
  pos+=body.size();
  return !body.empty();
}
bool t_load_dev::go_any(string&body,const CharMask&any)
{
  auto n=mem.size();
  if (pos>=n)return false;
  const auto*p=&mem[pos];
  auto e=p+n;
  auto&mask=any.mask;
  for (;p<e;p++)
  {
    if (mask[uchar(*p)])continue;
    auto body_size=p-&mem[pos];
    body=mem.substr(pos,body_size);
    pos+=body_size;
    return body_size;
  }
  body=mem.substr(pos);
  pos+=body.size();
  return !body.empty();
}
bool t_load_dev::go_const_raw(const char*const ptr,size_t size)
{
  auto end=pos+size;
  if (end>mem.size())return false;
  for (int i=0;i<size;i++)
  {
    if (mem[pos+i]==ptr[i])continue;
    return false;
  }
  pos+=size;
  return true;
}
bool t_load_dev::go_const(const string&body)
{
  auto size=body.size();
  auto end=pos+size;
  if (end>mem.size())return false;
  for (int i=0;i<size;i++)
  {
    if (mem[pos+i]==body[i])continue;
    return false;
  }
  pos+=body.size();
  return true;
}
bool t_load_dev::go_end(string&body,const string&aft)
{
  auto e=mem.find(aft,pos);
  if (e==string::npos)return false;
  body=mem.substr(pos,e-pos);
  pos=e;
  bool ok=go_const(aft);
  QapAssert(ok);
  return ok;
}
bool t_load_dev::go_any_char(char&body,const string&any)
{
  if (mem.empty())return false;
  if (pos>=mem.size())return false;
  auto e=any.find(CToS(mem[pos]));
  if (e==string::npos)return false;
  body=mem[pos];
  pos++;
  return true;
}
bool t_load_dev::go_any_char(char&body,const CharMask&any)
{
  if (mem.empty())return false;
  if (pos>=mem.size())return false;
  auto ok=any[mem[pos]];
  if (!ok)return false;
  body=mem[pos];
  pos++;
  return true;
}
bool t_load_dev::go_blob(string&body,size_t count)
{
  bool ok=count<=mem.size()-pos;
  if (!ok)return ok;
  body=mem.substr(pos,count);
  pos+=count;
  return true;
}
t_load_dev::t_keywords::t_func::t_func(const t_keywords&keywords):keywords(keywords)
{
  auto&arr=keywords.arr;
  int n=arr.size();
  items.resize(n);
  for (int i=0;i<n;i++)
  {
    items[i]=i;
  }
}
void t_load_dev::t_keywords::t_func::operator()(char c)
{
  auto&arr=keywords.arr;
  bool need_clean=false;
  int cur_pos=pos;
  pos++;
  for (size_t i=0;i<items.size();i++)
  {
    auto&id=items[i];
    auto&ex=arr[id];
    if (c!=ex[cur_pos])
    {
      id=-1;
      need_clean=true;
      continue;
    }
  }
  if (need_clean)
  {
    QapCleanIf(items,[](int id)
    {
      return id<0;
    }
              );
    need_clean=false;
  }
  if (items.empty())
  {
    fail=true;
    return;
  }
  if (items.size()==1)
  {
    next=pos<arr[items[0]].size();
    ok=ok||!next;
    return;
  }
  next=true;
  for (int i=0;i<items.size();i++)
  {
    auto&id=items[i];
    if (pos!=arr[id].size())continue;
    ok=true;
    QapAssert(ok_pos!=pos);
    ok_pos=pos;
    ok_way_id=id;
    id=-1;
    need_clean=true;
  }
  if (need_clean)
  {
    QapCleanIf(items,[](int id)
    {
      return id<0;
    }
              );
    QapAssert(!items.empty());
    QapAssert(ok);
  }
  int gg=1;
}
bool t_load_dev::t_keywords::t_func::exec(const string&ref)
{
  auto&func=*this;
  for (int i=0;i<ref.size();i++)
  {
    func(ref[i]);
    if (fail)
    {
      return false;
    }
    if (func.next)continue;
    QapAssert(ok);
    return true;
  }
  return ok;
}
bool t_load_dev::go_any_str_from_vec(string&ref,const vector<string>&arr)
{
  return go_any_str_from_vec_old_and_slow(ref,arr);
  QapAssert(!arr.empty());
  t_keywords keywords={arr};
  auto&body=ref;
  auto n=mem.size();
  if (pos>=n)return false;
  const auto*p=&mem[pos];
  auto e=p+n;
  t_keywords::t_func func(keywords);
  for (;p<e;p++)
  {
    func(*p);
    if (func.fail)
    {
      if (!func.ok)return false;
      body=mem.substr(pos,func.ok_pos);
      pos+=body.size();
      return true;
    }
    if (func.next)continue;
    QapAssert(func.ok);
    p++;
    auto body_size=p-&mem[pos];
    body=mem.substr(pos,body_size);
    pos+=body_size;
    return true;
  }
  if (!func.ok)return false;
  body=mem.substr(pos);
  pos+=body.size();
  return !body.empty();
}
bool t_load_dev::go_any_str_from_vec(string&ref,const QapStrFinder&arr)
{
  auto&body=ref;
  auto&tool=arr;
  auto&lines=tool.lines;
  auto n=mem.size();
  if (pos>=n)return false;
  const auto*p=&mem[pos];
  auto e=p+n;
  int state=0;
  int last_pos=-1;
  for (;p<e;p++)
  {
    auto c=*p;
    auto&ex=lines[state].cmds[c];
    state=ex.next_line;
    if (ex.last_pos!=-1)last_pos=ex.last_pos;
    if (state!=-1)continue;
    if (last_pos==-1)return false;
    body=mem.substr(pos,last_pos);
    pos+=body.size();
    return true;
  }
  QapAssert(state>=0);
  if (last_pos==-1)return false;
  body=mem.substr(pos,last_pos);
  pos+=body.size();
  return !body.empty();
}
bool t_load_dev::go_any_str_from_vec_old_and_slow(string&ref,const vector<string>&arr)
{
  t_fallback scope(*this,__FUNCTION__);
  bool&ok=scope.ok;
  QapAssert(!arr.empty());
  vector<int> out;
  out.resize(arr.size());
  int count=0;
  int id=-1;
  int winpos=-1;
  int def_pos=0;
  getPos(def_pos);
  for (int i=0;i<arr.size();i++)
  {
    t_fallback scope(*this,__FUNCTION__"::loop");
    auto&ex=arr[i];
    QapAssert(!ex.empty());
    scope.ok=this->go_const(ex);
    int dev_pos=0;
    getPos(dev_pos);
    out[i]=dev_pos;
    if (scope.ok)
    {
      id=i;
      count++;
      winpos=dev_pos;
    }
    scope.ok=false;
  }
  ok=count;
  if (!ok)return ok;
  if (count>1)
  {
    int best=0;
    for (int i=1;i<out.size();i++)
    {
      if (out[i]==def_pos)continue;
      bool error_detected=out[i]==out[best];
      if (error_detected)
      {
        CppString cpp=arr[i];
        string msg="error detected:\n";
        msg+="arr["+IToS(i)+"] == arr["+IToS(best)+"]\n";
        msg+="value = \""+cpp.data+"\"";
        QapDebugMsg(msg)
      }
      if (out[i]>out[best])best=i;
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
t_save_dev::t_save_dev(IEnvRTTI&Env,string&mem):Env(Env),mem(mem) {}
void t_save_dev::push(t_fallback*ptr)
{
  ptr->pos=mem.size();
}
void t_save_dev::pop(t_fallback*ptr)
{
  if (ptr->ok)return;
  mem.resize(ptr->pos);
}
void t_save_dev::setPos(int pos)
{
  QapNoWay();
  this->mem.resize(pos);
}
void t_save_dev::getPos(int&pos)
{
  pos=this->mem.size();
}
IEnvRTTI&t_save_dev::getEnv()
{
  return Env;
}
bool t_save_dev::isSave()
{
  return true;
}
bool t_save_dev::isLoad()
{
  return false;
}
bool t_save_dev::go_any(string&body,const string&any)
{
  if (body.empty())return false;
  string tmp=body;
  for (int i=0;i<any.size();i++)tmp=join(split(tmp,CToS(any[i])),"");
  bool ok=tmp.empty();
  QapAssert(ok);
  mem+=body;
  return ok;
}
bool t_save_dev::go_any(string&body,const CharMask&any)
{
  if (body.empty())return false;
  bool ok=any.check(body);
  QapAssert(ok);
  mem+=body;
  return ok;
}
bool t_save_dev::go_const_raw(const char*const ptr,size_t size)
{
  mem+=string(ptr,size);
  return true;
}
bool t_save_dev::go_const(const string&body)
{
  mem+=body;
  return true;
}
bool t_save_dev::go_end(string&body,const string&aft)
{
  auto e=body.find(aft);
  bool ok=e==string::npos;
  QapAssert(ok);
  if (!ok)return false;
  mem+=body;
  ok=go_const(aft);
  QapAssert(ok);
  return ok;
}
bool t_save_dev::go_any_char(char&body,const string&any)
{
  auto ok=any.find(body)!=string::npos;
  QapAssert(ok)
  mem.push_back(body);
  return ok;
}
bool t_save_dev::go_any_char(char&body,const CharMask&any)
{
  auto ok=any[body];
  QapAssert(ok)
  mem.push_back(body);
  return ok;
}
bool t_save_dev::go_blob(string&body,size_t count)
{
  bool ok=count==body.size();
  QapAssert(ok);
  if (!ok)return ok;
  mem+=body;
  return true;
}
bool t_save_dev::go_any_str_from_vec(string&ref,const vector<string>&arr)
{
  t_fallback scope(*this,__FUNCTION__);
  bool&ok=scope.ok;
  QapAssert(!arr.empty());
  int id=-1;
  int count=0;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    QapAssert(!ex.empty());
    if (ex==ref)
    {
      count++;
      id=i;
    }
  }
  QapAssert(count<=1);
  ok=count;
  if (!ok)return ok;
  ok=go_const(arr[id]);
  QapAssert(ok);
  return ok;
}
bool t_save_dev::go_any_str_from_vec(string&ref,const QapStrFinder&arr)
{
  return go_any_str_from_vec(ref,arr.keywords);
}
string two_text_diff(const string&out,const string&data)
{
  auto maxval=std::max(out.size(),data.size());
  auto minval=std::min(out.size(),data.size());
  auto ds=maxval-minval;
  int pos=-1;
  for (int i=0;i<minval;i++)
  {
    if (out[i]!=data[i])
    {
      pos=i;
      break;
    }
  }
  string msg="diff:\n  min_size="+IToS(minval)+"  diff_size="+IToS(ds)+"  pos="+IToS(pos)+"\n";
  if (pos<0)
  {
    QapAssert(minval==out.size());
    auto out=t_error_tool::get_codefrag(data,minval);
    out="{\"offset\":"+IToS(minval)+"}\n"+out;
    msg+=out;
  }
  if (pos>=0)
  {
    int count=10;
    CppString a_cpp=data.substr(std::max<int>(pos-count,0),count*2);
    CppString b_cpp=out.substr(std::max<int>(pos-count,0),count*2);
    msg+="  inp: \""+a_cpp.data+"\"\n";
    msg+="  out: \""+b_cpp.data+"\"\n";
  }
  QapDebugMsg(msg);
  return msg;
}
void t_config_2013::t_item::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->type);
}
t_config_2013::t_item::t_item()
{
  DoReset();
}
t_config_2013::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_config_2013::t_item::operator=(t_item&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->type=std::move(_Right.type);;
}
string t_config_2013::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_config_2013::t_item::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\n");
  if (!ok)return ok;
  D+=dev.go_any(type,gen_dips("azAZ09")+"_$@:");
  if (!ok)return ok;
  return ok;
}
void t_config_2013::t_info::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->type);
  detail::FieldTryDoReset(this->pos);
}
t_config_2013::t_info::t_info()
{
  DoReset();
}
t_config_2013::t_info::t_info(t_info&&_Right)
{
  operator=(std::move(_Right));
}
void t_config_2013::t_info::operator=(t_info&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->type=std::move(_Right.type);;
  this->pos=std::move(_Right.pos);;
}
string t_config_2013::t_info::ProxySys$$::GetFullName()
{
  return "t_info";
}
bool t_config_2013::t_info::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_any(type,gen_dips("azAZ09")+"_$@:");
  if (!ok)return ok;
  D+=dev.go_const("(");
  if (!ok)return ok;
  D+=dev.go_any(pos,gen_dips("09"));
  if (!ok)return ok;
  D+=dev.go_const(")");
  if (!ok)return ok;
  return ok;
}
void t_config_2013::t_event::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->time);
  detail::FieldTryDoReset(this->A);
  detail::FieldTryDoReset(this->B);
}
t_config_2013::t_event::t_event()
{
  DoReset();
}
t_config_2013::t_event::t_event(t_event&&_Right)
{
  operator=(std::move(_Right));
}
void t_config_2013::t_event::operator=(t_event&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->time=std::move(_Right.time);;
  this->A=std::move(_Right.A);;
  this->B=std::move(_Right.B);;
}
string t_config_2013::t_event::ProxySys$$::GetFullName()
{
  return "t_event";
}
bool t_config_2013::t_event::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\n+[");
  if (!ok)return ok;
  D+=dev.go_any(time,gen_dips("09")+".: ");
  if (!ok)return ok;
  D+=dev.go_const("] ");
  if (!ok)return ok;
  D+=dev.go_auto(A);
  if (!ok)return ok;
  D+=dev.go_const(" ");
  if (!ok)return ok;
  D+=dev.go_auto(B);
  if (!ok)return ok;
  return ok;
}
void t_config_2013::t_line::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->head);
  detail::FieldTryDoReset(this->arr);
  detail::FieldTryDoReset(this->events);
}
t_config_2013::t_line::t_line()
{
  DoReset();
}
t_config_2013::t_line::t_line(t_line&&_Right)
{
  operator=(std::move(_Right));
}
void t_config_2013::t_line::operator=(t_line&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->head=std::move(_Right.head);;
  this->arr=std::move(_Right.arr);;
  this->events=std::move(_Right.events);;
}
string t_config_2013::t_line::ProxySys$$::GetFullName()
{
  return "t_line";
}
bool t_config_2013::t_line::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_any(head,gen_dips("azAZ09")+"_$@:");
  if (!ok)return ok;
  M+=dev.go_const("\n====>");
  if (!ok)return ok;
  M+=dev.go_const("\n[arr]");
  if (!ok)return ok;
  M+=dev.go_auto(arr);
  if (!ok)return ok;
  M+=dev.go_const("\n[events]");
  if (!ok)return ok;
  O+=dev.go_auto(events);
  if (!ok)return ok;
  M+=dev.go_const("\n<====\n");
  if (!ok)return ok;
  return ok;
}
void t_config_2013::t_doc::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->lines);
}
t_config_2013::t_doc::t_doc()
{
  DoReset();
}
t_config_2013::t_doc::t_doc(t_doc&&_Right)
{
  operator=(std::move(_Right));
}
void t_config_2013::t_doc::operator=(t_doc&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->lines=std::move(_Right.lines);;
}
string t_config_2013::t_doc::ProxySys$$::GetFullName()
{
  return "t_doc";
}
bool t_config_2013::t_doc::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_auto(lines);
  if (!ok)return ok;
  return ok;
}
void t_config_2013::DoReset()
{
  {
    ;
  }
}
t_config_2013::t_config_2013()
{
  DoReset();
}
t_config_2013::t_config_2013(t_config_2013&&_Right)
{
  operator=(std::move(_Right));
}
void t_config_2013::operator=(t_config_2013&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string t_config_2013::ProxySys$$::GetFullName()
{
  return "t_config_2013";
}
t_poly_tool&t_poly_tool::get(IEnvRTTI&Env)
{
  static const string fn="config.cfg";
  static t_poly_tool tool;
  static t_doc&doc=tool.doc;
  static QapClock clock;
  static bool first=true;
  if (first)
  {
    clock.Start();/*doc.lines.reserve(2048);*/
  }
  if (clock.MS()<360*1000)if (!first)return tool;
  first=false;
  clock.Stop();
  clock.Start();
  CrutchIO IO;
  bool ok=IO.LoadFile(fn);
  if (ok)
  {
    t_doc tmp;
    doc=std::move(tmp);/*doc.lines.reserve(2048);*/
  }
  if (!ok)
  {
    IO.mem.clear();
    QapAssert(save_obj(Env,doc,IO.mem));
    IO.SaveFile(fn);
    return tool;
  }
  clock.Stop();
  clock.Start();
  QapAssert(load_obj(Env,doc,IO.mem));
  clock.Stop();
  clock.Start();
  real time=clock.MS();
  clock.Stop();
  clock.Start();
  return tool;
}
void t_poly_tool::save_doc(IEnvRTTI&Env,const string&fn)
{
  CrutchIO IO;
  QapAssert(save_obj(Env,this->doc,IO.mem));
  IO.SaveFile(fn);
}
t_config_2013::t_line&t_poly_tool::find(const string&type)
{
  auto&arr=doc.lines;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (ex.head==type)return ex;
  }
  arr.push_back(t_line());
  auto&back=arr.back();
  back.head=type;
  return back;
}
int t_poly_tool::get_mass(const vector<t_item>&arr,const string&type)
{
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (ex.type==type)return i;
  }
  QapAssert(false);
  return -1;
}
t_poly_tool::t_point&t_poly_tool::t_points::find(const string&name)
{
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (name==ex.name)return ex;
  }
  QapAssert(false);
  return *(t_point*)nullptr;
}
void t_poly_tool::t_points::set_passed(bool value)
{
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    ex.passed=value;
  }
}
void t_poly_tool::t_points::load_points(const vector<string>&inp)
{
  arr.resize(inp.size());
  for (int i=0;i<inp.size();i++)
  {
    auto&ex=inp[i];
    auto&p=arr[i];
    p.name=ex;
    p.id=i;
    p.passed=false;
    p.group=-1;
  }
}
void t_poly_tool::t_points::load_edges_from_events(const vector<t_event>&events)
{
  for (int i=0;i<events.size();i++)
  {
    auto&ex=events[i];
    auto&pa=find(ex.A.type);
    auto&pb=find(ex.B.type);
    pa.inp.push_back(pb.id);
    pb.out.push_back(pa.id);
  }
}
void t_poly_tool::t_points::t_wave::update(int id)
{
  auto&ex=points.arr[id];
  ex.group=group;
  ex.passed=true;
  auto&arr=ex.out;
  for (int i=0;i<arr.size();i++)
  {
    auto&id=arr[i];
    auto&ex=points.arr[id];
    QapAssert(id!=first_id);
    if (first_id==id)result=true;
    next.push_back(ex.id);
  }
}
void t_poly_tool::t_points::t_wave::run()
{
  points.set_passed(false);
  next.push_back(first_id);
  for (int iter=0;!next.empty();iter++)
  {
    prev=std::move(next);
    for (int i=0;i<prev.size();i++)
    {
      auto&id=prev[i];
      auto&ex=points.arr[id];
      if (ex.passed)continue;
      update(ex.id);
    }
  }
}
bool t_poly_tool::t_points::isCyclical()
{
  t_wave wave={*this};
  wave.result=false;
  string view;
  view.resize(arr.size());
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    for (int i=0;i<arr.size();i++)
    {
      view[i]=arr[i].group<0?'N':'0'+arr[i].group;
    }
    if (ex.group>=0)continue;
    wave.first_id=ex.id;
    wave.group=ex.id;
    wave.run();
  }
  return wave.result;
}
vector<string> t_poly_tool::t_points::toList()
{
  vector<string> out;
  set_passed(false);
  vector<int> heads;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if (!ex.out.empty())continue;
    heads.push_back(ex.id);
  }
  vector<int> next;
  for (int iter=0;!heads.empty();iter++)
  {
    vector<int> next_heads;
    for (int i=0;i<heads.size();i++)
    {
      auto&id=heads[i];
      auto&ex=arr[id];
      auto&inp=ex.inp;
      for (int i=0;i<inp.size();i++)
      {
        auto&id=inp[i];
        auto&ex=arr[id];
        if (ex.passed)continue;
        bool found=false;
        for (int i=0;i<next_heads.size();i++)if (next_heads[i]==ex.id)found=true;
        if (found)continue;
        next_heads.push_back(ex.id);
      }
    }
    for (int i=0;i<next_heads.size();i++)
    {
      auto&id=next_heads[i];
      auto&ex=arr[id];
      auto&out=ex.out;
      bool ok=true;
      for (int i=0;i<out.size();i++)
      {
        auto&id=out[i];
        for (int i=0;i<next_heads.size();i++)
        {
          if (next_heads[i]==id)ok=false;
        }
      }
      if (!ok)continue;
      next.push_back(ex.id);
    }
    for (int i=0;i<next.size();i++)
    {
      auto&id=next[i];
      auto&ex=arr[id];
      ex.passed=true;
    }
    std::sort(heads.begin(),heads.end());
    for (int i=0;i<heads.size();i++)
    {
      auto&id=heads[i];
      auto&ex=arr[id];
      out.push_back(ex.name);
    }
    heads=std::move(next);
  }
  return out;
}
vector<string> t_poly_tool::list_apply_events(const vector<string>&arr,vector<t_event>&events)
{
  t_points points;
  points.load_points(arr);
  points.load_edges_from_events(events);
  bool ok=!points.isCyclical();
  QapAssert(ok);
  auto list=points.toList();
  return list;
}
void t_poly_tool::remake(vector<t_item>&points,vector<t_event>&events)
{
  vector<string> arr;
  arr.resize(points.size());
  for (int i=0;i<arr.size();i++)
  {
    arr[i]=points[i].type;
  }
  auto out=list_apply_events(arr,events);
  QapAssert(out.size()==points.size());
  for (int i=0;i<arr.size();i++)
  {
    points[i].type=out[i];
  }
}
void t_number::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->body);
}
t_number::t_number()
{
  DoReset();
}
t_number::t_number(t_number&&_Right)
{
  operator=(std::move(_Right));
}
void t_number::operator=(t_number&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->body=std::move(_Right.body);;
}
string t_number::ProxySys$$::GetFullName()
{
  return "t_number";
}
bool t_number::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_any(body,gen_dips("09"));
  if (!ok)return ok;
  return ok;
}
void i_str_item::DoReset()
{
  {
    ;
  }
}
i_str_item::i_str_item()
{
  DoReset();
}
i_str_item::i_str_item(i_str_item&&_Right)
{
  operator=(std::move(_Right));
}
void i_str_item::operator=(i_str_item&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string i_str_item::ProxySys$$::GetFullName()
{
  return "i_str_item";
}
bool i_str_item::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_str_item::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl=
  {
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool i_str_item::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (!std::is_polymorphic<SelfClass>::value)if (!ref)
    {
      return false;
    }
  if (!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
string i_str_item::get_code()const
{
  QapDebugMsg("no way.");
  return "";
}
string i_str_item::get_value()const
{
  QapDebugMsg("no way.");
  return "";
}
void t_str_item_raw::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_str_item_raw::t_str_item_raw()
{
  DoReset();
}
t_str_item_raw::t_str_item_raw(t_str_item_raw&&_Right)
{
  operator=(std::move(_Right));
}
void t_str_item_raw::operator=(t_str_item_raw&&_Right)
{
  struct hidden
  {
    static void foo(i_str_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_str_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_str_item_raw::ProxySys$$::GetFullName()
{
  return "t_str_item_raw";
}
bool t_str_item_raw::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  static const auto dip_for_body=CharMask::fromStr(dip_inv("\"\\\n"));
  D+=dev.go_any(body,dip_for_body);
  if (!ok)return ok;
  return ok;
}
string t_str_item_raw::get_code()const
{
  return body;
}
string t_str_item_raw::get_value()const
{
  return body;
}
void t_str_item_hex::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_str_item_hex::t_str_item_hex()
{
  DoReset();
}
t_str_item_hex::t_str_item_hex(t_str_item_hex&&_Right)
{
  operator=(std::move(_Right));
}
void t_str_item_hex::operator=(t_str_item_hex&&_Right)
{
  struct hidden
  {
    static void foo(i_str_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_str_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_str_item_hex::ProxySys$$::GetFullName()
{
  return "t_str_item_hex";
}
bool t_str_item_hex::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\\x");
  if (!ok)return ok;
  static const string dip_for_body=gen_dips("09afAF");
  D+=dev.go_any_arr_char(body,dip_for_body);
  if (!ok)return ok;
  return ok;
}
string t_str_item_hex::get_code()const
{
  return "\\x"+CToS(body[0])+CToS(body[1]);
}
string t_str_item_hex::get_value()const
{
  string code;
  code.push_back(body[0]);
  code.push_back(body[1]);
  auto n=HToI_raw(code);
  auto value=CToS(n);
  return value;
}
void t_str_item_num::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_str_item_num::t_str_item_num()
{
  DoReset();
}
t_str_item_num::t_str_item_num(t_str_item_num&&_Right)
{
  operator=(std::move(_Right));
}
void t_str_item_num::operator=(t_str_item_num&&_Right)
{
  struct hidden
  {
    static void foo(i_str_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_str_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_str_item_num::ProxySys$$::GetFullName()
{
  return "t_str_item_num";
}
bool t_str_item_num::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\\u");
  if (!ok)return ok;
  static const string dip_for_body=gen_dips("09");
  D+=dev.go_any_arr_char(body,dip_for_body);
  if (!ok)return ok;
  return ok;
}
string t_str_item_num::get_code()const
{
  return "\\u"+CToS(body[0])+CToS(body[1]);
}
string t_str_item_num::get_value()const
{
  string code;
  code.push_back(body[0]);
  code.push_back(body[1]);
  auto n=SToI(code);
  auto value=CToS(n);
  return value;
}
void t_str_item_fix::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->body)=('n');
}
t_str_item_fix::t_str_item_fix()
{
  DoReset();
}
t_str_item_fix::t_str_item_fix(t_str_item_fix&&_Right)
{
  operator=(std::move(_Right));
}
void t_str_item_fix::operator=(t_str_item_fix&&_Right)
{
  struct hidden
  {
    static void foo(i_str_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_str_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_str_item_fix::ProxySys$$::GetFullName()
{
  return "t_str_item_fix";
}
bool t_str_item_fix::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\\");
  if (!ok)return ok;
  static const string dip_for_body="tfbrn\\\"\'"+gen_dips("07");
  D+=dev.go_any_char(body,dip_for_body);
  if (!ok)return ok;
  return ok;
}
string t_str_item_fix::get_code()const
{
  return "\\"+CToS(body);
}
string t_str_item_fix::get_value()const
{
  string code=SelfClass::get_code();
  BinString str=code;
  return str.data;
}
void t_str_item::t_impl::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->arr);
}
t_str_item::t_impl::t_impl()
{
  DoReset();
}
t_str_item::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_str_item::t_impl::operator=(t_impl&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->arr=std::move(_Right.arr);;
}
string t_str_item::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_str_item::t_impl::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_const("\"");
  if (!ok)return ok;
  O+=dev.go_auto(arr);
  if (!ok)return ok;
  M+=dev.go_const("\"");
  if (!ok)return ok;
  return ok;
}
string t_str_item::t_impl::get_code()const
{
  string out;
  for (int i=0;i<arr.size();i++)
  {
    out+=arr[i]->get_code();
  }
  return out;
}
string t_str_item::t_impl::get_value()const
{
  string out;
  for (int i=0;i<arr.size();i++)
  {
    out+=arr[i]->get_value();
  }
  return out;
}
void t_str_item::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->value);
}
t_str_item::t_str_item()
{
  DoReset();
}
t_str_item::t_str_item(t_str_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_str_item::operator=(t_str_item&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->value=std::move(_Right.value);;
}
string t_str_item::ProxySys$$::GetFullName()
{
  return "t_str_item";
}
bool t_str_item::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_str<t_impl>(value);
  if (!ok)return ok;
  return ok;
}
string t_str_item::get_code()const
{
  return value;
}
string t_str_item::get_value()const
{
  QapDebugMsg("no impl");
  return "";
}
void i_char_item::DoReset()
{
  {
    ;
  }
}
i_char_item::i_char_item()
{
  DoReset();
}
i_char_item::i_char_item(i_char_item&&_Right)
{
  operator=(std::move(_Right));
}
void i_char_item::operator=(i_char_item&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string i_char_item::ProxySys$$::GetFullName()
{
  return "i_char_item";
}
bool i_char_item::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_char_item::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl=
  {
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool i_char_item::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (!std::is_polymorphic<SelfClass>::value)if (!ref)
    {
      return false;
    }
  if (!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
string i_char_item::get_code()const
{
  QapDebugMsg("no way.");
  return "";
}
string i_char_item::get_value()const
{
  QapDebugMsg("no way.");
  return "";
}
void t_char_item_raw::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_char_item_raw::t_char_item_raw()
{
  DoReset();
}
t_char_item_raw::t_char_item_raw(t_char_item_raw&&_Right)
{
  operator=(std::move(_Right));
}
void t_char_item_raw::operator=(t_char_item_raw&&_Right)
{
  struct hidden
  {
    static void foo(i_char_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_char_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_char_item_raw::ProxySys$$::GetFullName()
{
  return "t_char_item_raw";
}
bool t_char_item_raw::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_any(body,dip_inv("\'\\\n"));
  if (!ok)return ok;
  return ok;
}
string t_char_item_raw::get_code()const
{
  return body;
}
string t_char_item_raw::get_value()const
{
  return body;
}
void t_char_item_hex::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_char_item_hex::t_char_item_hex()
{
  DoReset();
}
t_char_item_hex::t_char_item_hex(t_char_item_hex&&_Right)
{
  operator=(std::move(_Right));
}
void t_char_item_hex::operator=(t_char_item_hex&&_Right)
{
  struct hidden
  {
    static void foo(i_char_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_char_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_char_item_hex::ProxySys$$::GetFullName()
{
  return "t_char_item_hex";
}
bool t_char_item_hex::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\\x");
  if (!ok)return ok;
  D+=dev.go_any_arr_char(body,gen_dips("09afAF"));
  if (!ok)return ok;
  return ok;
}
string t_char_item_hex::get_code()const
{
  return "\\x"+CToS(body[0])+CToS(body[1]);
}
string t_char_item_hex::get_value()const
{
  string code;
  code.push_back(body[0]);
  code.push_back(body[1]);
  auto n=HToI_raw(code);
  auto value=CToS(n);
  return value;
}
void t_char_item_num::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_char_item_num::t_char_item_num()
{
  DoReset();
}
t_char_item_num::t_char_item_num(t_char_item_num&&_Right)
{
  operator=(std::move(_Right));
}
void t_char_item_num::operator=(t_char_item_num&&_Right)
{
  struct hidden
  {
    static void foo(i_char_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_char_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_char_item_num::ProxySys$$::GetFullName()
{
  return "t_char_item_num";
}
bool t_char_item_num::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\\u");
  if (!ok)return ok;
  D+=dev.go_any_arr_char(body,gen_dips("09"));
  if (!ok)return ok;
  return ok;
}
string t_char_item_num::get_code()const
{
  return "\\u"+CToS(body[0])+CToS(body[1]);
}
string t_char_item_num::get_value()const
{
  string code;
  code.push_back(body[0]);
  code.push_back(body[1]);
  auto n=SToI(code);
  auto value=CToS(n);
  return value;
}
void t_char_item_fix::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->body)=('\0');
}
t_char_item_fix::t_char_item_fix()
{
  DoReset();
}
t_char_item_fix::t_char_item_fix(t_char_item_fix&&_Right)
{
  operator=(std::move(_Right));
}
void t_char_item_fix::operator=(t_char_item_fix&&_Right)
{
  struct hidden
  {
    static void foo(i_char_item(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_char_item::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_char_item_fix::ProxySys$$::GetFullName()
{
  return "t_char_item_fix";
}
bool t_char_item_fix::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\\");
  if (!ok)return ok;
  D+=dev.go_any_char(body,"tfbrn\\\"\'"+gen_dips("07"));
  if (!ok)return ok;
  return ok;
}
string t_char_item_fix::get_code()const
{
  return "\\"+CToS(body);
}
string t_char_item_fix::get_value()const
{
  string code=SelfClass::get_code();
  BinString str=code;
  return str.data;
}
void t_char_item::t_impl::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->body);
}
t_char_item::t_impl::t_impl()
{
  DoReset();
}
t_char_item::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_char_item::t_impl::operator=(t_impl&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->body=std::move(_Right.body);;
}
string t_char_item::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_char_item::t_impl::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("\'");
  if (!ok)return ok;
  D+=dev.go_auto(body);
  if (!ok)return ok;
  D+=dev.go_const("\'");
  if (!ok)return ok;
  return ok;
}
string t_char_item::t_impl::get_code()const
{
  return "\'"+body->get_code()+"\'";
}
string t_char_item::t_impl::get_value()const
{
  return body->get_value();
}
void t_char_item::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->value);
}
t_char_item::t_char_item()
{
  DoReset();
}
t_char_item::t_char_item(t_char_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_char_item::operator=(t_char_item&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->value=std::move(_Right.value);;
}
string t_char_item::ProxySys$$::GetFullName()
{
  return "t_char_item";
}
bool t_char_item::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_str<t_impl>(value);
  return ok;
}
string t_char_item::get_code()const
{
  return value;
}
string t_char_item::get_value()const
{
  QapDebugMsg("no impl");
  return "";
}
void RegAllCppLex(IEnvRTTI&Env)
{
  {
    Sys$$<t_char_item_raw>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_char_item_hex>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_char_item_num>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_char_item_fix>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_str_item_raw>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_str_item_hex>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_str_item_num>::GetRTTI(Env);
  }
  ;;
  {
    Sys$$<t_str_item_fix>::GetRTTI(Env);
  }
  ;;
}
void i_sep::DoReset()
{
  {
    ;
  }
}
i_sep::i_sep()
{
  DoReset();
}
i_sep::i_sep(i_sep&&_Right)
{
  operator=(std::move(_Right));
}
void i_sep::operator=(i_sep&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string i_sep::ProxySys$$::GetFullName()
{
  return "i_sep";
}
bool i_sep::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_sep::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl=
  {
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool i_sep::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (!std::is_polymorphic<SelfClass>::value)if (!ref)
    {
      return false;
    }
  if (!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
string i_sep::make_code()const
{
  QapDebugMsg("no way.");
  return "";
}
void i_expr::DoReset()
{
  {
    ;
  }
}
i_expr::i_expr()
{
  DoReset();
}
i_expr::i_expr(i_expr&&_Right)
{
  operator=(std::move(_Right));
}
void i_expr::operator=(i_expr&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
}
string i_expr::ProxySys$$::GetFullName()
{
  return "i_expr";
}
bool i_expr::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool i_expr::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl=
  {
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool i_expr::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if (!std::is_polymorphic<SelfClass>::value)if (!ref)
    {
      return false;
    }
  if (!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_sep_seq::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_sep_seq::t_sep_seq()
{
  DoReset();
}
t_sep_seq::t_sep_seq(t_sep_seq&&_Right)
{
  operator=(std::move(_Right));
}
void t_sep_seq::operator=(t_sep_seq&&_Right)
{
  struct hidden
  {
    static void foo(i_sep(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_sep::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_sep_seq::ProxySys$$::GetFullName()
{
  return "t_sep_seq";
}
bool t_sep_seq::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_any(body," \t\r\n");
  if (!ok)return ok;
  return ok;
}
string t_sep_seq::make_code()const
{
  return body;
}
void t_c_comment::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_c_comment::t_c_comment()
{
  DoReset();
}
t_c_comment::t_c_comment(t_c_comment&&_Right)
{
  operator=(std::move(_Right));
}
void t_c_comment::operator=(t_c_comment&&_Right)
{
  struct hidden
  {
    static void foo(i_sep(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_sep::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_c_comment::ProxySys$$::GetFullName()
{
  return "t_c_comment";
}
bool t_c_comment::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("/*");
  if (!ok)return ok;
  D+=dev.go_end(body,"*/");
  if (!ok)return ok;
  return ok;
}
string t_c_comment::make_code()const
{
  return "/*"+body+"*/";
}
void t_cpp_comment::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_cpp_comment::t_cpp_comment()
{
  DoReset();
}
t_cpp_comment::t_cpp_comment(t_cpp_comment&&_Right)
{
  operator=(std::move(_Right));
}
void t_cpp_comment::operator=(t_cpp_comment&&_Right)
{
  struct hidden
  {
    static void foo(i_sep(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_sep::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_cpp_comment::ProxySys$$::GetFullName()
{
  return "t_cpp_comment";
}
bool t_cpp_comment::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_const("//");
  if (!ok)return ok;
  D+=dev.go_end(body,"\n");
  if (!ok)return ok;
  return ok;
}
string t_cpp_comment::make_code()const
{
  return "//"+body+"\n";
}
void t_sep::t_impl::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->arr);
}
t_sep::t_impl::t_impl()
{
  DoReset();
}
t_sep::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_sep::t_impl::operator=(t_impl&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->arr=std::move(_Right.arr);;
}
string t_sep::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_sep::t_impl::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_auto(arr);
  if (!ok)return ok;
  return ok;
}
string t_sep::t_impl::make_code()const
{
  string out="";
  for (int i=0;i<arr.size();i++)
  {
    out+=arr[i]->make_code();
  }
  return out;
}
void t_sep::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->value);
}
t_sep::t_sep()
{
  DoReset();
}
t_sep::t_sep(t_sep&&_Right)
{
  operator=(std::move(_Right));
}
void t_sep::operator=(t_sep&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->value=std::move(_Right.value);;
}
string t_sep::ProxySys$$::GetFullName()
{
  return "t_sep";
}
bool t_sep::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_str<t_impl>(value);
  if (!ok)return ok;
  return ok;
}
string t_sep::make_code()const
{
  return value;
}
void t_str::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_str::t_str()
{
  DoReset();
}
t_str::t_str(t_str&&_Right)
{
  operator=(std::move(_Right));
}
void t_str::operator=(t_str&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_str::ProxySys$$::GetFullName()
{
  return "t_str";
}
bool t_str::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_auto(body);
  if (!ok)return ok;
  return ok;
}
void t_char::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_char::t_char()
{
  DoReset();
}
t_char::t_char(t_char&&_Right)
{
  operator=(std::move(_Right));
}
void t_char::operator=(t_char&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_char::ProxySys$$::GetFullName()
{
  return "t_char";
}
bool t_char::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_auto(body);
  if (!ok)return ok;
  return ok;
}
void t_num::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_num::t_num()
{
  DoReset();
}
t_num::t_num(t_num&&_Right)
{
  operator=(std::move(_Right));
}
void t_num::operator=(t_num&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_num::ProxySys$$::GetFullName()
{
  return "t_num";
}
bool t_num::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_auto(body);
  if (!ok)return ok;
  return ok;
}
void t_name::t_keyword::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->value);
}
t_name::t_keyword::t_keyword()
{
  DoReset();
}
t_name::t_keyword::t_keyword(t_keyword&&_Right)
{
  operator=(std::move(_Right));
}
void t_name::t_keyword::operator=(t_keyword&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->value=std::move(_Right.value);;
}
string t_name::t_keyword::ProxySys$$::GetFullName()
{
  return "t_keyword";
}
bool t_name::t_keyword::go(i_dev&dev)
{
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
  if (!ok)return ok;
  return ok;
}
void t_name::t_impl::DoReset()
{
  {
    ;
  }
  (this->A)=('A');
  detail::FieldTryDoReset(this->B);
}
t_name::t_impl::t_impl()
{
  DoReset();
}
t_name::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_name::t_impl::operator=(t_impl&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->A=std::move(_Right.A);;
  this->B=std::move(_Right.B);;
}
string t_name::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_name::t_impl::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  static const auto dip_for_a=CharMask::fromStr(gen_dips("azAZ")+"_$@");
  M+=dev.go_any_char(A,dip_for_a);
  if (!ok)return ok;
  static const auto dip_for_b=CharMask::fromStr(gen_dips("azAZ09")+"_$@");
  O+=dev.go_any(B,dip_for_b);
  if (!ok)return ok;
  return ok;
}
string t_name::t_impl::get()const
{
  return CToS(A)+B;
}
void t_name::t_impl_ex::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->impl);
}
t_name::t_impl_ex::t_impl_ex()
{
  DoReset();
}
t_name::t_impl_ex::t_impl_ex(t_impl_ex&&_Right)
{
  operator=(std::move(_Right));
}
void t_name::t_impl_ex::operator=(t_impl_ex&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->impl=std::move(_Right.impl);;
}
string t_name::t_impl_ex::ProxySys$$::GetFullName()
{
  return "t_impl_ex";
}
bool t_name::t_impl_ex::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_diff<t_keyword>(impl);
  if (!ok)return ok;
  return ok;
}
void t_name::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->value);
}
t_name::t_name()
{
  DoReset();
}
t_name::t_name(t_name&&_Right)
{
  operator=(std::move(_Right));
}
void t_name::operator=(t_name&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->value=std::move(_Right.value);;
}
string t_name::ProxySys$$::GetFullName()
{
  return "t_name";
}
bool t_name::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_str<t_impl_ex>(value);
  if (!ok)return ok;
  return ok;
}
string t_name::get()const
{
  return value;
}
void t_id::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->body);
}
t_id::t_id()
{
  DoReset();
}
t_id::t_id(t_id&&_Right)
{
  operator=(std::move(_Right));
}
void t_id::operator=(t_id&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_id::ProxySys$$::GetFullName()
{
  return "t_id";
}
bool t_id::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_auto(body);
  if (!ok)return ok;
  return ok;
}
void t_sign::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  (this->body)=('?');
}
t_sign::t_sign()
{
  DoReset();
}
t_sign::t_sign(t_sign&&_Right)
{
  operator=(std::move(_Right));
}
void t_sign::operator=(t_sign&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->body=std::move(_Right.body);;
}
string t_sign::ProxySys$$::GetFullName()
{
  return "t_sign";
}
bool t_sign::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  D+=dev.go_any_char(body,"~|&=<>!:?;,.+-*/%^");
  if (!ok)return ok;
  return ok;
}
void t_soft_brackets::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->arr);
}
t_soft_brackets::t_soft_brackets()
{
  DoReset();
}
t_soft_brackets::t_soft_brackets(t_soft_brackets&&_Right)
{
  operator=(std::move(_Right));
}
void t_soft_brackets::operator=(t_soft_brackets&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->arr=std::move(_Right.arr);;
}
string t_soft_brackets::ProxySys$$::GetFullName()
{
  return "t_soft_brackets";
}
bool t_soft_brackets::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_const("(");
  if (!ok)return ok;
  O+=dev.go_auto(arr);
  if (!ok)return ok;
  M+=dev.go_const(")");
  if (!ok)return ok;
  return ok;
}
void t_hard_brackets::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->arr);
}
t_hard_brackets::t_hard_brackets()
{
  DoReset();
}
t_hard_brackets::t_hard_brackets(t_hard_brackets&&_Right)
{
  operator=(std::move(_Right));
}
void t_hard_brackets::operator=(t_hard_brackets&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->arr=std::move(_Right.arr);;
}
string t_hard_brackets::ProxySys$$::GetFullName()
{
  return "t_hard_brackets";
}
bool t_hard_brackets::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_const("[");
  if (!ok)return ok;
  O+=dev.go_auto(arr);
  if (!ok)return ok;
  M+=dev.go_const("]");
  if (!ok)return ok;
  return ok;
}
void t_curly_brackets::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);;
  }
  detail::FieldTryDoReset(this->arr);
}
t_curly_brackets::t_curly_brackets()
{
  DoReset();
}
t_curly_brackets::t_curly_brackets(t_curly_brackets&&_Right)
{
  operator=(std::move(_Right));
}
void t_curly_brackets::operator=(t_curly_brackets&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};;
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));;
  }
  this->arr=std::move(_Right.arr);;
}
string t_curly_brackets::ProxySys$$::GetFullName()
{
  return "t_curly_brackets";
}
bool t_curly_brackets::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_const("{");
  if (!ok)return ok;
  O+=dev.go_auto(arr);
  if (!ok)return ok;
  M+=dev.go_const("}");
  if (!ok)return ok;
  return ok;
}
void t_param::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->body);
}
t_param::t_param()
{
  DoReset();
}
t_param::t_param(t_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_param::operator=(t_param&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->sep=std::move(_Right.sep);;
  this->body=std::move(_Right.body);;
}
string t_param::ProxySys$$::GetFullName()
{
  return "t_param";
}
bool t_param::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_auto(sep);
  if (!ok)return ok;
  M+=dev.go_auto(body);
  if (!ok)return ok;
  return ok;
}
void t_line::DoReset()
{
  {
    ;
  }
  detail::FieldTryDoReset(this->cmd);
  detail::FieldTryDoReset(this->params);
}
t_line::t_line()
{
  DoReset();
}
t_line::t_line(t_line&&_Right)
{
  operator=(std::move(_Right));
}
void t_line::operator=(t_line&&_Right)
{
  ;
  if (&_Right==this)return;
  {
    ;
  }
  this->cmd=std::move(_Right.cmd);;
  this->params=std::move(_Right.params);;
}
string t_line::ProxySys$$::GetFullName()
{
  return "t_line";
}
bool t_line::go(i_dev&dev)
{
  t_fallback scope(dev,__FUNCTION__);
  auto&ok=scope.ok;
  auto&D=scope.mandatory;
  auto&M=scope.mandatory;
  auto&O=scope.optional;
  M+=dev.go_auto(cmd);
  if (!ok)return ok;
  O+=dev.go_auto(params);
  if (!ok)return ok;
  return ok;
}
vector<string> t_line::get_raw_params(IEnvRTTI&Env)
{
  vector<string> out;
  for (int i=0;i<params.size();i++)
  {
    auto&ex=params[i];
    string mem;
    bool ok=save_obj(Env,ex.body,mem);
    QapAssert(ok);
    out.push_back(mem);
  }
  return std::move(out);
}
void QapLexerRegAll(IEnvRTTI&Env)
{
  {
    Sys$$<t_sep_seq>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_c_comment>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_cpp_comment>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_sep>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_str>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_char>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_num>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_name>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_id>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_sign>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_soft_brackets>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_hard_brackets>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_curly_brackets>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_line>::GetRTTI(Env);
  }
  ;
  {
    Sys$$<t_param>::GetRTTI(Env);
  }
  ;
}
void TSimpleBinarySaver::t_dev::push()
{
  stack.push_back(pValue);
}
void TSimpleBinarySaver::t_dev::pop()
{
  QapAssert(!stack.empty());
  pValue=stack.back();
  stack.pop_back();
}
TSimpleBinarySaver::TSimpleBinarySaver(t_dev&dev):dev(dev) {}
string TSimpleBinarySaver::toStrEx(TType*pType,void*pValue)
{
  TDataIO IO;
  SelfClass::t_dev dev={IO,pValue};
  SelfClass V(dev);
  pType->Use(V);
  return IO.IO.mem;
}
void TSimpleBinarySaver::toIO(QapIO&IO,TRawPtr&ptr)
{
  SelfClass::t_dev dev={IO,ptr.pValue};
  SelfClass V(dev);
  ptr.pType->Use(V);
}
void TSimpleBinarySaver::Do(TTypeStruct*p)
{
  if (p->SubType)
  {
    QapDebugMsg("no way");
    return;
  }
  auto&arr=p->Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    dev.push();
    dev.pValue=ex.getValue(dev.pValue);
    ex.Type->Use(*this);
    dev.pop();
  }
}
void TSimpleBinarySaver::Do(TTypeSys*p)
{
  p->BinIO->Save(dev.IO,dev.pValue);
}
void TSimpleBinarySaver::Do(TTypeVector*p)
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
  for (int i=0;i<Count;i++)
  {
    void*ptr=VecAPI->GetItem(dev.pValue,i);
    dev.push();
    dev.pValue=ptr;
    elemType->Use(*this);
    dev.pop();
  }
}
void TSimpleBinarySaver::Do(TTypeArray*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinarySaver::Do(TTypeSelfPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinarySaver::Do(TTypeAutoPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinarySaver::Do(TTypeWeakPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinarySaver::Do(TTypeHardPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinarySaver::Do(TTypeVoidPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinarySaver::Do(TTypeFieldPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::t_dev::push()
{
  stack.push_back(pValue);
}
void TSimpleBinaryLoader::t_dev::pop()
{
  QapAssert(!stack.empty());
  pValue=stack.back();
  stack.pop_back();
}
TSimpleBinaryLoader::TSimpleBinaryLoader(t_dev&dev):dev(dev) {}
bool TSimpleBinaryLoader::fromIOEx(IEnvRTTI&Env,const TRawPtr&ptr,QapIO&IO)
{
  SelfClass::t_dev dev={IO,ptr.pValue};
  SelfClass V(dev);
  ptr.pType->Use(V);
  return true;
}
bool TSimpleBinaryLoader::fromStrEx(const string&source,TType*pType,void*pValue)
{
  TDataIO IO;
  IO.IO.mem=source;
  SelfClass::t_dev dev={IO,pValue};
  SelfClass V(dev);
  pType->Use(V);
  return true;
}
bool TSimpleBinaryLoader::fromStrEx(const string&source,TRawPtr&ptr)
{
  TDataIO IO;
  IO.IO.mem=source;
  SelfClass::t_dev dev={IO,ptr.pValue};
  SelfClass V(dev);
  ptr.pType->Use(V);
  return true;
}
bool TSimpleBinaryLoader::fromStrEx(QapIO&IO,TRawPtr&ptr)
{
  SelfClass::t_dev dev={IO,ptr.pValue};
  SelfClass V(dev);
  ptr.pType->Use(V);
  return true;
}
void TSimpleBinaryLoader::Do(TTypeStruct*p)
{
  if (p->SubType)
  {
    QapDebugMsg("no way");
    return;
  }
  auto&arr=p->Members;
  for (int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    dev.push();
    dev.pValue=ex.getValue(dev.pValue);
    ex.Type->Use(*this);
    dev.pop();
  }
}
void TSimpleBinaryLoader::Do(TTypeSys*p)
{
  p->BinIO->Load(dev.IO,dev.pValue);
}
void TSimpleBinaryLoader::Do(TTypeVector*p)
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
  for (int i=0;i<Count;i++)
  {
    void*ptr=VecAPI->GetItem(dev.pValue,i);
    dev.push();
    dev.pValue=ptr;
    elemType->Use(*this);
    dev.pop();
  }
}
void TSimpleBinaryLoader::Do(TTypeArray*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::Do(TTypeSelfPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::Do(TTypeAutoPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::Do(TTypeWeakPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::Do(TTypeHardPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::Do(TTypeVoidPtr*p)
{
  QapDebugMsg("no way");
}
void TSimpleBinaryLoader::Do(TTypeFieldPtr*p)
{
  QapDebugMsg("no way");
}
bool qap_simple_clone_unsafe(TType*pType,void*pDest,void*pSource)
{
  string mem=TSimpleBinarySaver::toStrEx(pType,pSource);
  return TSimpleBinaryLoader::fromStrEx(mem,pType,pDest);
}
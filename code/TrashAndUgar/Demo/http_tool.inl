struct HttpTool{
  static string urlencode(const string&str)
  {
    string tmp;tmp.reserve(str.size()*3);
    for(int i=0;i<str.size();i++)
      tmp+=IsLegalChar(str[i])?CToS(str[i]):"%"+CToH_raw(str[i]);
    return tmp;
  }
  static char HToC(const string&str){size_t val;sscanf_s(str.c_str(),"%02x",&val); return char(val);}
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
  static string get(const string&content,const string&key)
  {
    string out=get_raw(content,key);
    return urldecode(out);
  }
  static string get_raw(const string&content,const string&key){
    auto arr=split(content,"&");
    for(int i=0;i<arr.size();i++){
      auto ex=split(arr[i],"=");
      if(ex.size()<2)continue;
      if(ex[0]==key)return ex[1];
    }
    return "";
  }
  static string str2html(const string&s){
    string rule="&~&amp;#<~&lt;#>~&gt;";
    auto arr=split(rule,"#");
    string out=s;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto e=split(ex,"~");
      auto&from=e[0];
      auto&to=e[1];
      out=StrReplace(out,from,to);
    }
    return out;
  }
  static string str2pre(const string&s){
    return "<pre>"+str2html(s)+"</pre>";
  }
  static string get_all_20131110(){
    string out="";
    out+=gen_dips("azAZ09");
    out+="~|&=<>!:?;,.+-*/%^";
    out+="[]{}()";
    out+="\"\'";
    out+="\t\f\b\r\n\\";
    out+="_$@";
    out+=" `#";
    out+=gen_dips("àÿÀß")+"¸¨¹";
    return out;
  }
  struct t_map_20131110{
    struct t_rec{
      bool ok;
      int ptr;
    };
    vector<t_rec> arr;
  };
  static t_map_20131110 get_map_20131110(){
    t_map_20131110 out;
    auto&arr=out.arr;
    arr.resize(256);
    auto all=get_all_20131110();
    for(int i=0;i<all.size();i++){
      auto&ex=all[i];
      auto u=(uchar)ex;
      auto&ey=arr[u];
      ey.ok=true;
      ey.ptr=i;
    }
    return out;
  }
  static string HexStrToWin1251_20131110(const string&inp){
    QapAssert(!(inp.size()%2));
    string out="";
    static string all=get_all_20131110();
    for(int i=0;i<inp.size();i+=2){
      auto ex=inp.substr(i,2);
      int code=HToI_raw(ex);
      QapAssert(InDip<int>(1,code+1,all.size()))
      out+=all[code];
    }
    return out;
  }
  static string Win1251ToHexStr_20131110(const string&inp){
    string out;
    static auto m=get_map_20131110();
    out.reserve(inp.size()*2);
    for(int i=0;i<inp.size();i++){
      auto ex=(uchar)inp[i];
      QapAssert(m.arr[ex].ok);
      out+=CToH_raw(m.arr[ex].ptr);
    }
    return out;
  }
};

struct THttpRequest{
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(string,method,$)\
  ADD(string,host,$)\
  ADD(string,webpath,$)\
  ADD(string,content,$)\
  ADD(string,connection,$)\
  ADD(string,origin,$)\
  ADD(string,refferer,$)\
  //===
  #include "defprovar.inl"
  //===
  THttpRequest(){DoReset();}
public:
};

struct t_answer{
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(string,type,$)\
  ADD(string,body,$)\
  //===
  #include "defprovar.inl"
  //===
  t_answer(){DoReset();}
public:
  static t_answer gen(const string&type,const string&body){
    t_answer tmp;
    tmp.type=type;
    tmp.body=body;
    return std::move(tmp);
  }
  string get(const THttpRequest&request)const{return get(request.connection,request.origin);}
  string get(const string&connection,const string&origin)const{
    //u8;   => utf-8
    //win;  => windows-1251
    //html; => text/html;
    //raw;  => text/plain;
    //404;  => NOT FOUND
    //200;  => OK
    string code="200 OK";
    string content_type="text/plain";
    string charset="utf-8";
    #define f(KEY,CODE)if(string::npos!=type.find(KEY)){CODE;}
    f("200",code="200 OK");
    f("404",code="404 Not Found");
    f("html",content_type="text/html");
    f("raw",content_type="text/plain");
    f("png",content_type="image/png");
    f("u8",charset="utf-8");
    f("win",charset="windows-1251");
    #undef f
    auto con=connection;if(con.empty())con="close";
    string head(
      "HTTP/1.1 "+code+"\r\n"
      "Server: Respondent/1.0\r\n"
      "Content-Type: "+content_type+"; charset="+charset+"\r\n"
      "Transfer-Encoding: chunked\r\n"
      "Connection: "+con+"\r\n"
      +string(origin.empty()?"":"Access-Control-Allow-Origin: "+origin+"\r\n")+
      //"Connection: keep-alive\r\n"
      //"Connection: close\r\n"
      "Cache-Control: no-store, no-cache, must-revalidate\r\n"
      "Pragma: no-cache\r\n\r\n"
    );
    string end(
      "\r\n"
      "0"
      "\r\n\r\n"
    );
    return head+IToH_raw(body.size())+"\r\n"+body+end;
  }
};

static string get_first_part(const string&query,char needle){auto p=query.find(needle);if(p==std::string::npos)return query;return query.substr(0,p);}
static string get_second_part(const string&query,char needle){auto p=query.find(needle);if(p==std::string::npos)return "";return query.substr(p+1);}
static string get_query(const string&webpath){return get_second_part(webpath,'?');}
static string get_param_value(const vector<string>&params,const string&param){
  vector<string> p;for(int i=0;i<params.size();i++){qap_add_back(p)=get_first_part(params[i],'=');}
  auto ids=qap_find_str(p,param);
  if(ids.empty())return "";
  return get_second_part(params[ids[0]],'=');
}
static string get_decoded_param_value(const vector<string>&params,const string&param){
  return HttpTool::urldecode(get_param_value(params,param));
}

static bool params_defined(const vector<string>&params,const string&list)
{
  vector<string> p;for(int i=0;i<params.size();i++){qap_add_back(p)=get_first_part(params[i],'=');}
  auto arr=split(list,",");
  for(int i=0;i<arr.size();i++){if(qap_find_str(p,arr[i]).empty())return false;}
  return true;
}

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
  static string ScanParam(const string&Before,const string&Where,const string&After,int&Pos)
  {
    int E=Where.find(Before, Pos);
    if(E==-1){Pos=-1; return "";}
    Pos=Where.find(Before,Pos)+Before.length();
    E=After.empty()?Where.size():Where.find(After,Pos);
    if(E==-1){Pos=-1; return "";}
    string result; result.assign(Where,Pos,E-Pos);
    return std::move(result);
  }
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


#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_GETP(rettype,getp,arr,name)\
  rettype*getp(const string&name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_GETREF(rettype,getref,arr,name)\
  rettype&getref(const string&name)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.name!=name)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    QapAssert(p);\
    return *p;\
  }
static string vector_to_json_array(const vector<string>&arr,const string&keyname){
  vector<string> out;
  for(int i=0;i<arr.size();i++)out.push_back("{\""+keyname+"\":\""+arr[i]+"\"}");
  return "["+join(out,",\n")+"]";
}

struct toJsStr{
  static const CharMask&getMask()
  {
    static CharMask mask(
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "0123456789"
      "_ ¹"
      "+-*/=|~!@#$%^&()[]{}<>.,:?;`'"
      "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß"
      "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ"
    );
    return mask;
  }
  static string fromStr(const string&ref)
  {
    const CharMask&mask=getMask();
    string out;
    out.reserve(ref.size()+ref.size()/16);
    for(int i=0;i<ref.size();i++)
    {
      uchar ex=ref[i];
      if(mask[ex]){
        out.push_back(ex);
        continue;
      }
      #define F(A,B)if(ex==A){out+=B;continue;}
      F('\\',"\\\\")
      F('\"',"\\\"")
      F('\n',"\\n")
      F('\r',"\\r")
      F('\t',"\\t")
      F('\b',"\\b")
      F('\f',"\\f")
      #undef F
      QapDebugMsg("no way!");
    }
    return out;
  }
  static string arc(const string&ref)
  {
    const CharMask&mask=getMask();
    string out;
    out.reserve(ref.size());
    uchar prev=0;
    for(int i=0;i<ref.size();i++)
    {
      uchar ex=ref[i];
      if((!mask[ex])||(prev=='\\'))
      {
        #define F(A,B){if((prev==B[0])&&(ex==B[1])){out.push_back(A);prev=0;continue;}}
        F('\\',"\\\\")
        F('\"',"\\\"")
        F('\n',"\\n")
        F('\r',"\\r")
        F('\t',"\\t")
        F('\b',"\\b")
        F('\f',"\\f")
        #undef F
        if((prev!='\\')&&ex=='\\'){prev=ex;continue;}
        QapDebugMsg("bad char("+BinString::toCode(ex)+") = \'"+CToS(ex)+"\'");
        return out;
      }else{
        out.push_back(ex);
      }
      prev=ex;
    }
    return out;
  }
};

static string Str2Json(const string&ref){return "\""+toJsStr::fromStr(ref)+"\"";}

static string vector_to_json_array_ex(const vector<string>&arr,const string&keyname){
  vector<string> out;
  for(int i=0;i<arr.size();i++)out.push_back("{"+Str2Json(keyname)+":"+Str2Json(arr[i])+"}");
  return "["+join(out,",\n")+"]";
}

static string Json2Str(const string&ref){
  QapAssert(ref.size()>1);
  QapAssert(ref.front()=='"');
  QapAssert(ref.back()=='"');
  string tmp=ref.substr(1,ref.size()-2);
  return toJsStr::arc(tmp);
}
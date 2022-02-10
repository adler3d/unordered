struct t_char_seq{
  int n;
  char c;
};

struct t_raw_seq{
  string data;
};

struct t_clone_one{
  int len;
  int ptr;
};

struct t_clone_seq{
  int n;
  int len;
  int ptr;
};

class t_tool{
public:
  //-----
  //----- toBin
  //-----
public:
  static bool toBin(string&out,t_char_seq&ref){
    QapAssert(ref.n>1&&ref.n<64);
    string tmp="nc";
    tmp[0]=64*0+ref.n;
    tmp[1]=ref.c;
    out+=tmp;
    return true;
  }
  static bool toBin(string&out,t_raw_seq&ref){
    QapAssert(ref.data.size()<64);
    string tmp="s";
    tmp[0]=64*1+ref.data.size();
    tmp+=ref.data;
    out+=tmp;
    return true;
  }
  static bool toBin(string&out,t_clone_one&ref){
    // out="abc"; ref.len=1; ref.ptr=1; out="abcc";
    QapAssert(ref.len>1&&ref.len<64);
    QapAssert(ref.ptr>1&&ref.ptr<256);
    QapAssert(ref.len<=ref.ptr);
    QapAssert(out.size()>=ref.ptr);
    string tmp="lp";
    tmp[0]=64*2+ref.len;
    tmp[1]=ref.ptr;
    out+=tmp;
    return true;
  }
  static bool toBin(string&out,t_clone_seq&ref){
    QapAssert(ref.len>1&&ref.n<64);
    QapAssert(ref.len>1&&ref.len<256);
    QapAssert(ref.ptr>1&&ref.ptr<256);
    QapAssert(ref.len<=ref.ptr);
    QapAssert(out.size()>=ref.ptr);
    string tmp="nlp";
    tmp[0]=64*3+ref.n;
    tmp[1]=ref.len;
    tmp[2]=ref.ptr;
    out+=tmp;
    return true;
  }
public:
  //-----
  //----- Exec
  //-----
public:
  static bool Exec(string&out,t_char_seq&ref){
    QapAssert(ref.n>1&&ref.n<64);
    string tmp;
    tmp.resize(ref.n,ref.c);
    out+=tmp;
    return true;
  }
  static bool Exec(string&out,t_raw_seq&ref){
    QapAssert(ref.data.size()<64);
    out+=ref.data;
    return true;
  }
  static bool Exec(string&out,t_clone_one&ref){
    // out="abc"; ref.len=1; ref.ptr=1; out="abcc";
    QapAssert(ref.len>1&&ref.len<64);
    QapAssert(ref.ptr>1&&ref.ptr<256);
    QapAssert(ref.len<=ref.ptr);
    QapAssert(out.size()>=ref.ptr);
    string tmp=out.substr(out.size()-ref.ptr,ref.len);
    out+=tmp;
    return true;
  }
  static bool Exec(string&out,t_clone_seq&ref){
    // out="abc"; ref.len=1; ref.ptr=1; out="abcc";
    QapAssert(ref.n>1&&ref.n<64);
    QapAssert(ref.len>1&&ref.len<256);
    QapAssert(ref.ptr>1&&ref.ptr<256);
    QapAssert(ref.len<=ref.ptr);
    QapAssert(out.size()>=ref.ptr);
    string tmp=out.substr(out.size()-ref.ptr,ref.len);
    for(int i=0;i<ref.n;i++)out+=tmp;
    return true;
  }
};

struct t_pack{
  vector<t_char_seq> arr0;
  vector<t_raw_seq> arr1;
  vector<t_clone_one> arr2;
  vector<t_clone_seq> arr3;
};

struct t_packed_data{
  t_pack pack;
  vector<int> arr;
public:
  string Exec(t_packed_data&ref)
  {
    string out;
    int c[4]={0,0,0,0};
    for(int i=0;i<arr.size();i++)
    {
      int ex=arr[i];
      #define F(ID)if(id==ID){auto&n=c[ex];t_tool::Exec(out,arr##ID[n]);n++;}
      F(0)F(1)F(2)F(3)
      #undef F
    }
    return out;
  }
  string toBin(size_t size){string tmp;tmp.resize(sizeof(size_t));(size_t&)tmp[0]=size;return size;}
  template<class TYPE>
  bool toBin(string&out,vector<TYPE>&arr)
  {
    auto size=toBin(arr.size());
    out+=size;
    for(int i=0;i<arr.size();i++)
    {
      bool ok=t_tool::toBin(out,arr[i]);
      if(!ok)return false;
    }
    return true;
  }
  bool toBin(string&out)
  {
    #define F(ID){bool ok=toBin(out,pack.arr##ID);if(!ok)return false;}
    F(0)F(1)F(2)F(3)
    #undef F
    string tmp;
    bool inc=arr.size()%4;
    tmp.resize(arr.size()/4+inc?1:0);
    for(int i=0;i<arr.size();i+++)
    {
      auto&dest=tmp[i/4];
      int id=i%4;
      auto v=arr[i+id];
      QapAssert(v<4);
      auto src=(0x3&v)<<id;
      dest=dest|src;
    }
    out+=tmp;
    return out;
  }
};
























struct t_packed_data{
  vector<TAutoPtr<i_cmd>> arr;
};





struct t_node{
  char c;
  int n;
  array(TAutoPtr<t_node>,256) arr;
};




















#include "StdAfx.h"

class t_qaprle{
public:
  //struct t_byte_node{
  //public:
  //#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_byte_node)OWNER(t_qaprle)
  //#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  //ADDBEG()\
  //ADDVAR(int,n,DEF,$,$)\
  //ADDVAR(TAutoPtr<array(t_byte_node,256)>,arr,DEF,$,$)\
  //ADDEND()
  ////=====+>>>>>t_byte_node
  //#include "QapGenStruct.inl"
  ////<<<<<+=====t_byte_node
  //public:
  //};
public:
  class t_byte_seq{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_byte_seq)OWNER(t_qaprle)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,n,SET,2,$)\
  ADDVAR(char,c,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pack
  #include "QapGenStruct.inl"
  //<<<<<+=====t_pack
  public:
  };
  class t_data_one{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_data_one)OWNER(t_qaprle)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,data,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_data_one
  #include "QapGenStruct.inl"
  //<<<<<+=====t_data_one
  public:
  };
  class t_copy_one{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_copy_one)OWNER(t_qaprle)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,len,DEF,$,$)\
  ADDVAR(int,ptr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_copy_one
  #include "QapGenStruct.inl"
  //<<<<<+=====t_copy_one
  public:
  };
  class t_copy_seq{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_copy_seq)OWNER(t_qaprle)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,n,DEF,$,$)\
  ADDVAR(int,len,DEF,$,$)\
  ADDVAR(int,ptr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_copy_seq
  #include "QapGenStruct.inl"
  //<<<<<+=====t_copy_seq
  public:
  };
  class t_pack{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pack)OWNER(t_qaprle)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_byte_seq>,arr0,DEF,$,$)\
  ADDVAR(vector<t_data_one>,arr1,DEF,$,$)\
  ADDVAR(vector<t_copy_one>,arr2,DEF,$,$)\
  ADDVAR(vector<t_copy_seq>,arr3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pack
  #include "QapGenStruct.inl"
  //<<<<<+=====t_pack
  public:
  };
  class t_packed_data{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_packed_data)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_pack,pack,DEF,$,$)\
  ADDVAR(vector<int>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_packed_data
  #include "QapGenStruct.inl"
  //<<<<<+=====t_packed_data
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(t_byte_seq)F(t_data_one)F(t_copy_one)F(t_copy_seq)F(t_pack)F(t_packed_data)//F(t_byte_node)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_qaprle)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_qaprle
#include "QapGenStruct.inl"
//<<<<<+=====t_qaprle
public:
  static bool Exec(string&out,const t_byte_seq&ref){
    QapAssert(ref.n>0&&ref.n<64);
    string tmp;
    tmp.resize(ref.n,ref.c);
    out+=tmp;
    return true;
  }
  static bool Exec(string&out,const t_data_one&ref){
    QapAssert(ref.data.size()<64);
    out+=ref.data;
    return true;
  }
  static bool Exec(string&out,const t_copy_one&ref){
    // out="abc"; ref.len=1; ref.ptr=1; out="abcc";
    QapAssert(ref.len>1&&ref.len<64);
    QapAssert(ref.ptr>1&&ref.ptr<256);
    QapAssert(ref.len<=ref.ptr);
    QapAssert(out.size()>=ref.ptr);
    string tmp=out.substr(out.size()-ref.ptr,ref.len);
    out+=tmp;
    return true;
  }
  static bool Exec(string&out,const t_copy_seq&ref){
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
public:
  template<class TYPE>
  static bool Exec(string&out,const vector<TYPE>&arr,int id)
  {
    QapAssert(id<arr.size());
    if(id>=arr.size())return false;
    return Exec(out,arr[id]);
  }
  static bool Exec(string&out,const t_packed_data&ref)
  {
    out.clear();
    int c[4]={0,0,0,0};
    for(int i=0;i<ref.arr.size();i++)
    {
      int ex=ref.arr[i];
      #define F(ID)if(ex==ID){auto&n=c[ex];bool ok=Exec(out,ref.pack.arr##ID,n);if(!ok)return false;n++;}
      F(0)F(1)F(2)F(3)
      #undef F
    }
    return true;
  }
public:
  static bool toBin(string&out,const t_byte_seq&ref){
    QapAssert(ref.n>0&&ref.n<64);
    string tmp="nc";
    tmp[0]=64*0+ref.n;
    tmp[1]=ref.c;
    out+=tmp;
    return true;
  }
  static bool toBin(string&out,const t_data_one&ref){
    QapAssert(ref.data.size()<64);
    string tmp="s";
    tmp[0]=64*1+ref.data.size();
    tmp+=ref.data;
    out+=tmp;
    return true;
  }
  static bool toBin(string&out,const t_copy_one&ref){
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
  static bool toBin(string&out,const t_copy_seq&ref){
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
  template<class TYPE>
  static bool toBinFull(string&out,vector<TYPE>&arr,int id)
  {
    QapAssert(id<arr.size());
    if(id>=arr.size())return false;
    return toBin(out,arr[id]);
  }
  static bool toBinFull(string&out,t_packed_data&ref)
  {
    out.clear();
    int c[4]={0,0,0,0};
    for(int i=0;i<ref.arr.size();i++)
    {
      int ex=ref.arr[i];
      #define F(ID)if(ex==ID){auto&n=c[ex];bool ok=toBinFull(out,ref.pack.arr##ID,n);if(!ok)return false;n++;}
      F(0)F(1)F(2)F(3)
      #undef F
    }
    return true;
  }
public:
  //static string toBin(size_t size){string tmp;tmp.resize(sizeof(size_t));(size_t&)tmp[0]=size;return tmp;}
  //template<class TYPE>
  //static bool toBin(string&out,const vector<TYPE>&arr)
  //{
  //  auto size=toBin(arr.size());
  //  out+=size;
  //  for(int i=0;i<arr.size();i++)
  //  {
  //    bool ok=toBin(out,arr[i]);
  //    if(!ok)return false;
  //  }
  //  return true;
  //}
  //static bool toBin(string&out,const t_packed_data&ref)
  //{
  //  #define F(ID){bool ok=toBin(out,ref.pack.arr##ID);if(!ok)return false;}
  //  F(0)F(1)F(2)F(3)
  //  #undef F
  //  string tmp;
  //  auto&arr=ref.arr;
  //  bool inc=arr.size()%4;
  //  tmp.resize(arr.size()/4+inc?1:0);
  //  for(int i=0;i<arr.size();i++)
  //  {
  //    auto&dest=tmp[i/4];
  //    int id=i%4;
  //    auto v=arr[i];
  //    QapAssert(v<4);
  //    if(v>4)return false;
  //    auto src=(0x3&v)<<id;
  //    dest=dest|src;
  //  }
  //  out+=toBin(arr.size());
  //  out+=tmp;
  //  return true;
  //}
public:
  //F(t_byte_seq)F(t_data_one)F(t_copy_one)F(t_copy_seq)
  static bool fromBin(const string&inp,int&pos,t_byte_seq&ref)
  {
    if(pos+1>=inp.size())return false;
    ref.n=inp[pos]%64;
    ref.c=inp[pos+1];
    pos+=2;
    return true;
  }
  static bool fromBin(const string&inp,int&pos,t_data_one&ref)
  {
    auto size=inp[pos]%64;
    if(pos+size>=inp.size())return false;
    ref.data=inp.substr(pos+1,size);
    pos+=1+size;
    return true;
  }
  static bool fromBin(const string&inp,int&pos,t_copy_one&ref)
  {
    if(pos+1>=inp.size())return false;
    ref.len=inp[pos]%64;
    ref.ptr=inp[pos+1];
    pos+=2;
    return true;
  }
  static bool fromBin(const string&inp,int&pos,t_copy_seq&ref)
  {
    if(pos+2>=inp.size())return false;
    ref.n=inp[pos]%64;
    ref.len=inp[pos+1];
    ref.ptr=inp[pos+2];
    pos+=3;
    return true;
  }
public:
  static bool fromBin(const string&inp,t_packed_data&ref)
  {
    ref.pack.arr0.clear();
    ref.pack.arr1.clear();
    ref.pack.arr2.clear();
    ref.pack.arr3.clear();
    ref.arr.clear();
    for(int pos=0;pos<inp.size();)
    {
      auto&a=inp[pos];
      auto id=a/64;
      #define F(ID)if(id==ID){auto&back=qap_add_back(ref.pack.arr##ID);bool ok=fromBin(inp,pos,back);if(!ok)return false;ref.arr.push_back(id);}
      F(0)F(1)F(2)F(3)
      #undef F
    }
    return true;
  }
public:
  static bool fromSrc(const string&src,t_packed_data&ref)
  {
    ref.pack.arr0.clear();
    ref.pack.arr1.clear();
    ref.pack.arr2.clear();
    ref.pack.arr3.clear();
    ref.arr.clear();
    //t_byte_node root;
    //vector<t_byte_node*> cur;
    //vector<t_byte_node*> next;
    //cur.push_back(&root);
    //auto hanlde=[&next](TAutoPtr<t_byte_node>&ref)
    //{
    //};
    //for(int pos=0;pos<src.size();pos++)
    //{
    //  auto&c=src[pos];
    //  for(int i=0;i<cur.size();i++)
    //  {
    //    auto*p=cur[i];
    //    if(!p->arr)
    //    auto&ref=p->arr[c];
    //    if(ref)
    //    {
    //      auto*ptr=ref.get();
    //      ptr->n++;
    //      continue;
    //    }
    //    auto*ptr=ref.build<t_byte_node>(Env);
    //    ptr->n++;
    //    next.push_back(ptr);
    //  }
    //  cur=std::move(next);
    //}
    for(int pos=0;pos<src.size();)
    {
      auto&a=src[pos];
      //t_byte_seq
      {
        int n=1;
        for(int i=1;pos+i<src.size();i++)
        {
          if(a!=src[pos+i])break;
          n++;
          if(n==63)break;
        }
        if(n>1)
        {
          auto&back=qap_add_back(ref.pack.arr0);
          back.n=n;
          back.c=a;
          pos+=n;
          ref.arr.push_back(0);
          continue;
        }
      }
      //t_data_one
      {
        auto&back=qap_add_back(ref.pack.arr1);
        int n=1;
        for(int i=1;pos+i<src.size();i++)
        {
          if(src[pos+i-1]==src[pos+i-0])break;
          n++;
          if(n==63)break;
        }
        back.data=src.substr(pos,n);
        pos+=n;
        ref.arr.push_back(1);
        continue;
      }
      int gg=1;
    }
    return true;
  }
};

class TBookPage20140912:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPage20140912)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_qaprle::t_packed_data,cmds,DEF,$,$)\
ADDVAR(string,inp,DEF,$,$)\
ADDVAR(string,out,DEF,$,$)\
ADDVAR(bool,need_from_src,DEF,$,$)\
ADDVAR(bool,need_from_bin,DEF,$,$)\
ADDVAR(bool,need_to_bin,DEF,$,$)\
ADDVAR(bool,need_to_hex,DEF,$,$)\
ADDVAR(bool,need_from_hex,DEF,$,$)\
ADDVAR(bool,need_exec,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPage20140912
#include "QapGenStruct.inl"
//<<<<<+=====TBookPage20140912
public:
  static string BlobToHex(const string&inp)
  {
    string out="";
    for(int i=0;i<inp.size();i++){
      if(i)out+=" ";out+=CToH_raw(inp[i]); 
    }
    return out;
  }
  static string HexToBlob(const string&inp)
  {
    string str=StrReplace(inp," ","");
    string out="";
    for(int i=0;i<str.size();i+=2){
      out+=char(HToI_raw(str.substr(i,2)));
    }
    return out;
  }
  void Update(t_context&con)
  {
    if(need_from_src)
    {
      bool ok=t_qaprle::fromSrc(out,cmds);
      QapAssert(ok);
      need_from_src=false;
    }
    if(need_from_bin)
    {
      bool ok=t_qaprle::fromBin(out,cmds);
      QapAssert(ok);
      need_from_bin=false;
    }
    if(need_to_bin)
    {
      out.clear();
      bool ok=t_qaprle::toBinFull(out,cmds);
      QapAssert(ok);
      need_to_bin=false;
    }
    if(need_to_hex)
    {
      out=BlobToHex(out);need_to_hex=false;
    }
    if(need_from_hex)
    {
      out=HexToBlob(out);need_from_hex=false;
    }
    if(need_exec)
    {
      out.clear();
      bool ok=t_qaprle::Exec(out,cmds);
      QapAssert(ok);
      need_exec=false;
    }
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
        F(TType)F(TBookPage20140912)
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
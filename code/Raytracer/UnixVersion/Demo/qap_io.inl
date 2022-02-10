class CrutchIO{
public:
  static bool FileExist(const string&FN)
  {
    std::fstream f;
    f.open(FN.c_str(),std::ios::in|std::ios::binary);
    return f.is_open();
  }
private:
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
public:
  int pos;
  string mem;
  CrutchIO():mem(""),pos(0){};
  bool LoadFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f)return false;
    int L=FileLength(f);
    mem.resize(L);
    if(L)f.read(&mem[0],L);
    //printf("f->size=%i\n",L);
    //printf("f->Chcount=%i\n",f._Chcount);
    f.close(); pos=0;
    return true;
  };
  bool SaveFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)return false;
    if(!mem.empty())f.write(&mem[0],mem.size());
    f.close(); pos=0; int L=mem.size();
    return true;
  };
  void read(char*c,int count)
  {
    for(int i=0;i<count;i++)c[i]=mem[pos++];//FIXME: тут можно юзать memcpy
  };
  void write(char*c,int count)
  {
    //mem.reserve(max(mem.capacity(),mem.size()+count));
    int n=mem.size();
    mem.resize(n+count);//Hint: resize гарантировано копирует содержимое.
    for(int i=0;i<count;i++)mem[n+i]=c[i];//FIXME: тут можно юзать memcpy
    pos+=count;
  };
};
//-------------------------------------------//
class QapIO{
public:
  QapIO(){}
public:
  virtual void SavePOD(void*p,int count)=0;
  virtual void LoadPOD(void*p,int count)=0;
  virtual bool TryLoad(int count)=0;
  virtual void Crash()=0;
  virtual bool IsCrashed()=0;
  virtual bool IsSizeIO()=0;
  virtual int GetSize()=0;
  virtual void WriteTo(QapIO&ref)=0;
public:
  #define LIST(F)F(int)F(unsigned int)F(char)F(unsigned char)F(bool)F(int64)F(uint64)F(float)F(real)F(short)F(unsigned short)F(vec2i)F(vec2d)F(vec2f)
  #define F(TYPE)void load(TYPE&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}
  LIST(F)
  #undef F
  #define F(TYPE)void save(TYPE&ref){SavePOD(&ref,sizeof(ref));}
  LIST(F)
  #undef F
  #undef LIST
  void load(std::string&ref)
  {
    int size=0;
    load(size);
    if(size<0){Crash();return;}
    if(!size){ref.clear();return;}
    if(!TryLoad(size)){Crash();return;}
    ref.resize(size);
    LoadPOD(&ref[0],size);
  }
  void save(std::string&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    SavePOD(&ref[0],size);
  }
  template<class TYPE>
  void load(std::vector<TYPE>&ref)
  {
    int size=0;
    load(size);
    if(size<0){Crash();return;}
    ref.resize(size);
    for(int i=0;i<size;i++){
      load(ref[i]);
    }
  }
  template<class TYPE>
  void load_as_pod(std::vector<TYPE>&ref)
  {
    int size=0;
    load(size);
    if(size<0){Crash();return;}
    ref.resize(size);
    for(int i=0;i<size;i++){
      LoadPOD(&ref[i],sizeof(TYPE));
    }
  }
  template<class TYPE>
  void save(std::vector<TYPE>&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      save(ref[i]);
    }
  }
  template<class TYPE>
  void save_as_pod(std::vector<TYPE>&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      SavePOD(&ref[i],sizeof(TYPE));
    }
  }
  void write_raw_string(string&s){if(s.empty())return;SavePOD((void*)&s[0],s.size());}
};
//-------------------------------------------//
class TDataIO:public QapIO{
public:
  CrutchIO IO;
  bool crashed;
  TDataIO():crashed(false),QapIO(){}
  //TDataIO(const TDataIO&)=delete;
  //TDataIO(TDataIO&)=delete;
  //TDataIO(TDataIO&&)=delete;
  //void operator=(const TDataIO&)=delete;
  //void operator=(TDataIO&)=delete;
  //void operator=(TDataIO&&)=delete;
public:
  void SavePOD(void*p,int count)
  {
    this->IO.write((char*)p,count);
  }
  void LoadPOD(void*p,int count)
  {
    int max_count=int(this->IO.mem.size())-int(this->IO.pos);
    if(count>max_count)
    {
      QapAssert(count<=max_count);
      return;
    }
    this->IO.read((char*)p,count);
  }
  bool TryLoad(int count)
  {
    auto max_size=int(IO.mem.size())-int(IO.pos);
    return (count>=0)&&(max_size>=count);
  }
  void Crash()
  {
    IO.pos=IO.mem.size();
    crashed=true;
  }
  bool IsCrashed()
  {
    return crashed;
  }
  bool IsSizeIO()
  {
    return false;
  }
  int GetSize()
  {
    return IO.mem.size();
  }
  void SaveTo(QapIO&Stream)
  {
    int size=IO.mem.size();
    Stream.SavePOD(&size,sizeof(size));
    if(!size)return;
    Stream.SavePOD(&IO.mem.front(),size);
  }
  void LoadFrom(QapIO&Stream)
  {
    int size;
    Stream.LoadPOD(&size,sizeof(size));
    if(!size)return;
    IO.mem.resize(size);
    Stream.LoadPOD(&IO.mem.front(),size);
  }
  void WriteTo(QapIO&ref)
  {
    ref.write_raw_string(IO.mem);
  }
};
//-------------------------------------------//
class TSizeIO:public QapIO{
public:
  int size;
  bool crashed;
public:
  TSizeIO():size(0),crashed(false),QapIO(){}
  void SavePOD(void*p,int count){size+=count;}
  void LoadPOD(void*p,int count){QapNoWay();Crash();}
  bool TryLoad(int count){QapNoWay();Crash();return false;}
  void Crash(){crashed=true;}
  bool IsCrashed(){return crashed;}
  bool IsSizeIO(){return true;}
  int GetSize()
  {
    return size;
  }
  void WriteTo(QapIO&ref)
  {
    if(!ref.IsSizeIO()){QapNoWay();Crash();return;}
    ref.SavePOD(nullptr,size);
  }
};


template<int BLOCK_LENGTH=1024*1024>
class FsIO:public QapIO{
public:
  fstream f;
  string block;
  int bpos;
  int pos;
  int n;
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
  FsIO(const string&FN){
    using namespace std;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f){n=0;pos=0;bpos=0;return;}
    n=FileLength(f);
    pos=0;bpos=0;
    read_block();
  }
  void read_block(){
    int v=std::min(BLOCK_LENGTH,n-bpos);
    block.resize(v);
    f.read(&block[0],block.size());
    bpos+=block.size();
  }
public:
  virtual void SavePOD(void*p,int count){QapNoWay();}
  virtual void LoadPOD(void*ptr,int c)
  {
    auto*p=(char*)ptr;auto count=c;
    QapAssert(count>=1);
    QapAssert(pos+count<=n);
    for(;;)
    {
      if(pos+count<=bpos){
        auto addr=pos-(bpos-block.size());
        QapAssert(addr>=0&&addr<block.size());
        memcpy(p,&block[addr],count);
        pos+=count;
        return;
      }else{
        auto addr=pos-(bpos-block.size());
        auto bef_n=bpos-pos;
        QapAssert(bef_n<=block.size()-addr);
        if(block.size()!=addr&&bef_n!=0)
        {
          QapAssert(addr>=0&&addr<block.size());
          memcpy(p,&block[addr],bef_n);
        }
        read_block();
        p+=bef_n;
        count-=bef_n;
        pos+=bef_n;
      }
    }
    int gg=1;
  }
  virtual bool TryLoad(int count){return pos+count<=n;}
  virtual void Crash(){QapNoWay();}
  virtual bool IsCrashed(){return n<=0;}
  virtual bool IsSizeIO(){return false;}
  virtual int GetSize(){return n;}
  virtual void WriteTo(QapIO&ref){QapNoWay();}
};

class FsWrite:public QapIO{
public:
  fstream f;
  int pos;
  int n;
  FsWrite(const string&FN){
    using namespace std;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)QapNoWay();
    pos=0;//bpos=0;
  }
public:
  virtual void SavePOD(void*p,int count){
    f.write((char*)p,count);
    pos+=count;
  }
  virtual void LoadPOD(void*ptr,int c){QapNoWay();}
  virtual bool TryLoad(int count){QapNoWay();return false;}
  virtual void Crash(){QapNoWay();}
  virtual bool IsCrashed(){return false;}
  virtual bool IsSizeIO(){return false;}
  virtual int GetSize(){QapNoWay();return n;}
  virtual void WriteTo(QapIO&ref){QapNoWay();}
};
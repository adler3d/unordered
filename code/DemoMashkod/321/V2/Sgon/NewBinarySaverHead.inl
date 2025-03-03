class TQapIO:public QapIO{
public:
  CrutchIO IO;
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
};

struct IQapStream{
  virtual bool Load(){return false;}
  virtual bool Save(){return false;}
  virtual TQapIO&GetContent()=0;
};

struct TQapFileStream:public IQapStream{
  TQapIO IO;
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
  TQapIO&GetContent(){return IO;};
};

struct TQapMemoryStream:public IQapStream{
  TQapIO IO;
  TQapMemoryStream(){}
  bool Load(){
    return true;
  }
  bool Save(){
    return true;
  }
  TQapIO&GetContent(){return IO;};
};

struct TQapIOStream:public IQapStream{
  TQapIO&IO;
  TQapIOStream(TQapIO&IO):IO(IO){}
  bool Load(){return true;}
  bool Save(){return true;}
  TQapIO&GetContent(){return IO;};
};

struct IQapRawObject{
  typedef TVoidPtr::TRawPtr TRawPtr;
  virtual TRawPtr&Get(IEnvRTTI&Env)=0;
};

struct TQapRawObject:public IQapRawObject{
  TRawPtr raw_ptr;
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

//bool QapUberLoad(IEnvRTTI&Env,IQapRawObject&&Object,IQapStream&&Stream)
//{
//  if(!Stream.Load())return false;
//  auto&Content=Stream.GetContent();
//  auto&raw_ptr=Object.GetObject(Env);
//  auto&pType=raw_ptr.pType;
//  auto&pValue=raw_ptr.pValue;
//  //begin
//
//  //end
//  return true;
//}
//
//bool QapUberSave(IEnvRTTI&Env,IQapRawObject&&Object,IQapStream&&Stream)
//{
//  auto&Content=Stream.GetContent();
//  auto&raw_ptr=Object.GetObject(Env);
//  auto&pType=raw_ptr.pType;
//  auto&pValue=raw_ptr.pValue;
//  //begin
//
//  //end
//  return !Content.IO.mem.empty()&&Stream.Save();
//}
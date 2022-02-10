namespace detail{
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
};

template<class TYPE>
struct Sys$${
  static void Save(TDataIO&IO,TYPE&ref)
  {
    ProxySys$$<TYPE,detail::has_ProxySys$$<TYPE>::value>::Save(IO,ref);
  }
  static void Load(TDataIO&IO,TYPE&ref)
  {
    ProxySys$$<TYPE,detail::has_ProxySys$$<TYPE>::value>::Load(IO,ref);
  }
};

template<class TYPE>void QapSave(TDataIO&IO,TYPE*){static_assert(false,"fail");}
template<class TYPE>void QapLoad(TDataIO&IO,TYPE*){static_assert(false,"fail");}

template<class TYPE>void QapSave(TDataIO&IO,TYPE&ref){Sys$$<TYPE>::Save(IO,ref);}
template<class TYPE>void QapLoad(TDataIO&IO,TYPE&ref){Sys$$<TYPE>::Load(IO,ref);}
template<class TYPE>string QapSaveToStr(TYPE&ref){TDataIO IO;QapSave(IO,ref);return IO.IO.mem;}
template<class TYPE>void QapLoadFromStr(TYPE&ref,const string&data){TDataIO IO; IO.IO.mem=data;QapLoad(IO,ref);}


template<class TYPE>string QapSaveToStrWithSizeOfType(TYPE&ref)
{
  int size_of_type=sizeof(TYPE);
  TDataIO IO;QapSave(IO,size_of_type);QapSave(IO,ref);return IO.IO.mem;
}
template<class TYPE>void QapLoadFromStrWithSizeOfType(TYPE&ref,const string&data){
  int size_of_type=-1;
  TDataIO IO;IO.IO.mem=data;QapLoad(IO,size_of_type);if(size_of_type!=sizeof(TYPE))return;QapLoad(IO,ref);
}

template<typename TYPE,bool is_proxy>
struct ProxySys$$;
template<typename TYPE>
struct ProxySys$$<TYPE,true>
{
  static void Save(TDataIO&IO,TYPE&ref){
    TYPE::ProxySys$$::Save(IO,ref);
  }
  static void Load(TDataIO&IO,TYPE&ref){
    TYPE::ProxySys$$::Load(IO,ref);
  }
};


template<>
struct Sys$$<QapKeyboard::TKeyState>{
  static void Save(TDataIO&IO,QapKeyboard::TKeyState&ref)
  {
    static_assert(QapKeyboard::TKeyState::MAX_KEY==263,"hm...");
    std::bitset<256+8> bs;
    for(int i=0;i<ref.MAX_KEY;i++){auto&ex=ref.data[i];QapAssert(1>=*(uchar*)(void*)&ex);bs[i]=ex;}
    IO.SavePOD(&bs,sizeof(bs));
  }
  static void Load(TDataIO&IO,QapKeyboard::TKeyState&ref)
  {
    static_assert(QapKeyboard::TKeyState::MAX_KEY==263,"hm...");
    std::bitset<256+8> bs;
    IO.LoadPOD(&bs,sizeof(bs));
    for(int i=0;i<ref.MAX_KEY;i++){auto&ex=ref.data[i];ex=bs[i];}
  }
};

//-->
#define SYS_RAW_POD_TYPE(QapKeyboard)\
  template<>\
  struct Sys$$<QapKeyboard>{\
    static void Save(TDataIO&IO,QapKeyboard&ref)\
    {\
      IO.SavePOD(&ref,sizeof(ref));\
    }\
    static void Load(TDataIO&IO,QapKeyboard&ref)\
    {\
      IO.LoadPOD(&ref,sizeof(ref));\
    }\
  };
//---
#define LIST(F)F(QapColor)F(vec2i)F(vec2f)F(vec2d)
LIST(SYS_RAW_POD_TYPE)
#undef LIST
//---
#undef SYS_RAW_POD_TYPE
//<--

template<class TYPE>
struct Sys$$<vector<TYPE>>{
  static void Save(TDataIO&IO,vector<TYPE>&ref)
  {
    int size=ref.size();
    IO.save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      auto&ex=ref[i];
      Sys$$<TYPE>::Save(IO,ex);
    }
  }
  static void Load(TDataIO&IO,vector<TYPE>&ref)
  {
    int size=0;
    IO.load(size);
    if(size<0){IO.Crash();return;}
    ref.resize(size);
    for(int i=0;i<size;i++){
      auto&ex=ref[i];
      Sys$$<TYPE>::Load(IO,ex);
    }
  }
};

//-->
#define SYS_SIMPLE_TYPE(string)\
  template<>\
  struct Sys$$<string>{\
    static void Save(TDataIO&IO,string&ref)\
    {\
      IO.save(ref);\
    }\
    static void Load(TDataIO&IO,string&ref)\
    {\
      IO.load(ref);\
    }\
  };
//---
#define LIST(F)F(int)F(unsigned int)F(char)F(unsigned char)F(bool)F(int64)F(uint64)F(float)F(real)F(short)F(unsigned short)F(string)
#define F(TYPE)SYS_SIMPLE_TYPE(TYPE)
LIST(F)
#undef F
#undef LIST
//---
#undef SYS_SIMPLE_TYPE
//<--
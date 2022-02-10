
#if(0)
class IConvertor{
public:
  struct source_type{};
  struct dest_type{};
  struct ExInfo{
    string Dest;
    string Source;
  };
  struct TInfo{
    TType*DestType;
    TType*SourceType;
    ExInfo GetText()
    {
      ExInfo tmp={DestType->GetFullName(),SourceType->GetFullName()};
      return tmp;
    }
  };
public:
  virtual void Do(dest_type*pDest,source_type*pSource)=0;
  virtual TInfo&GetInfo()=0;
};

template<typename DEST_TYPE,typename SOURCE_TYPE>
class RawConv:public IConvertor{
public:
  TInfo Info;
public:
  TInfo&GetInfo(){return Info;}
public:
  //#define DEF_CONV_SPEC(DEST,SOURCE)DEST(DEST_TYPE)SOURCE(SOURCE_TYPE)
  //#include "conv_spec.inl"
public:
  struct dest_conv{
    typedef dest_type in_type;typedef DEST_TYPE out_type;
    static out_type*get(in_type*pValue){return (out_type*)(void*)pValue;}
  };
  struct source_conv{
    typedef source_type in_type;typedef SOURCE_TYPE out_type;
    static out_type*get(in_type*pValue){return (out_type*)(void*)pValue;}
  };
  static typename dest_conv::out_type*get(typename dest_conv::in_type*pValue)
  {return dest_conv::get(pValue);}
  static typename source_conv::out_type*get(typename source_conv::in_type*pValue)
  {return source_conv::get(pValue);}
public:
  struct IEnv{
    IEnvRTTI&Env;
    virtual void AddConv(TType*ConvType)=0;
  };
  static void Reg()
  {

  }
  void Init()
  {
    /*
      Info - а не костыль ли это? Может хранить всё это где-то повыше?
      А тут моно сделать статический метод. Который будет регестрировать конвертор.
    */
  }
  void Do(dest_type*pDest,source_type*pSource)
  {
    auto&vD=*get(pDest);
    auto&vS=*get(pSource);
    vD=vS;
  }
};

class Convertor:public IConvertor{
public:
  typedef TTypeStruct::Member Member;
  struct Item{
    Member A;
    Member B;
    Convertor*pConv;
    void Do(void*pDest,void*pSource)
    {
      QapAssert(pConv);
      QapAssert(pDest&&pSource);
      auto*pD=(dest_type*)A.getValue(pDest);
      auto*pS=(source_type*)B.getValue(pSource);
      pConv->Do(pD,pS);
    }
  };
public:
  TInfo Info;
  vector<Item> Arr;
public:
  TInfo&GetInfo(){return Info;}
public:
  void Prepare(TType*DestType,TType*SourceType)
  {
    
  }
public:
  void Do(dest_type*pDest,source_type*pSource)
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex.Do(pDest,pSource);
    }
  }
};
#endif

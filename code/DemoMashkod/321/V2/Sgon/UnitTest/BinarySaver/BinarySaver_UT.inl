class BinarySaverUnitTest{
public:
  static void Run()
  {
    TStdAllocator MA;
    TEnvRTTI Env;
    Env.Alloc=&MA;

    //Foo(Env);
    //Bar(Env);

    //Foo2(Env);
    //Bar2(Env);

  }
  static void Foo2(TEnvRTTI&Env)
  {
    TAutoPtr<TStruct7zip> AP;
    AP=UberInit<TStruct7zip>(Env);
    QapSaveToFile(Env,AP,"7zip.qap");
  }
  static void Bar2(TEnvRTTI&Env)
  {
    TAutoPtr<TStruct7zip> AP;
    #define F(TYPE){Sys$$<TYPE>::GetRTTI(Env);}
      F(TAutoPtr<TStruct7zip>);
    #undef F
    QapLoadFromFile(Env,AP,"7zip.qap");
  }
  static void Foo(TEnvRTTI&Env)
  {
    TAutoPtr<TSiteX> X2;
    BuildX4(Env,X2);
    QapSaveToFile(Env,X2,"Site_v0.qap");
  }
  static void Bar(TEnvRTTI&Env)
  {
    TAutoPtr<TSiteX> X2;
    #define F(TYPE){Sys$$<TYPE>::GetRTTI(Env);}
      F(TAutoPtr<TSiteX1>);
      F(TAutoPtr<TSiteX2>);
      F(TAutoPtr<TSiteX3>);
      F(TAutoPtr<TSiteX4>);
    #undef F
    QapLoadFromFile(Env,X2,"Site_v0.qap");
  }
public:
  static void BuildX3(TEnvRTTI&Env,TAutoPtr<TSiteX>&result)
  {
    #define GEN(TYPE,NAME)TAutoPtr<TYPE> NAME=UberInit<TYPE>(Env);
    GEN(TSiteX3,tmp);
    auto*ptr=tmp.get();
    result=std::move(tmp);
    BuildX1(Env,ptr->Add(),"begin");
    BuildX1(Env,ptr->Add(),"trollface.exe");
    BuildX3_ext(Env,ptr->Add());
    BuildX1(Env,ptr->Add(),"coolface.exe");
    BuildX1(Env,ptr->Add(),"end");
    #undef GEN
  }
  static void BuildX2(TEnvRTTI&Env,TAutoPtr<TSiteX>&result)
  {
    #define GEN(TYPE,NAME)TAutoPtr<TYPE> NAME=UberInit<TYPE>(Env);
    GEN(TSiteX2,tmp);
    auto*ptr=tmp.get();
    result=std::move(tmp);
    BuildX3(Env,ptr->Next);
    #undef GEN
  }
  static void BuildX3_ext(TEnvRTTI&Env,TAutoPtr<TSiteX>&result)
  {
    #define GEN(TYPE,NAME)TAutoPtr<TYPE> NAME=UberInit<TYPE>(Env);
    GEN(TSiteX3,tmp);
    auto*ptr=tmp.get();
    result=std::move(tmp);
    BuildX1(Env,ptr->Add(),"begin");
    for(int i=0;i<4;i++)BuildX1(Env,ptr->Add(),"item["+IToS(i)+"].rar");
    BuildX1(Env,ptr->Add(),"end");
    #undef GEN
  }
  static void BuildX1(TEnvRTTI&Env,TAutoPtr<TSiteX>&result,const string&name)
  {
    #define GEN(TYPE,NAME)TAutoPtr<TYPE> NAME=UberInit<TYPE>(Env);
    GEN(TSiteX1,tmp);
    auto*ptr=tmp.get();
    result=std::move(tmp);
    ptr->name=name;
    #undef GEN
  }
  static void BuildX4(TEnvRTTI&Env,TAutoPtr<TSiteX>&result)
  {
    #define GEN(TYPE,NAME)TAutoPtr<TYPE> NAME=UberInit<TYPE>(Env);
    GEN(TSiteX4,tmp);
    auto*ptr=tmp.get();
    result=std::move(tmp);
    ptr->Hi3.name="lost";
    #undef GEN
  }
};
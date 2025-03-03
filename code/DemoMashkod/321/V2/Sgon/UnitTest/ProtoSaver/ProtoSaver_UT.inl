class ProtoSaverUnitTest{
public:
  static void Run()
  {
    TStdAllocator MA;
    TEnvRTTI Env;
    Env.Alloc=&MA;

    //Foo(Env);
    Bar(Env);

    //Foo2(Env);
    //Bar2(Env);

  }
  static void Foo(TEnvRTTI&Env)
  {
    TAutoPtr<TSiteX> site;
    BinarySaverUnitTest::BuildX2(Env,site);
    ProtoSaveToFile(Env,"proto.hpp","site",site);
  }
  static void Bar(TEnvRTTI&Env)
  {
    NodeStructuresList::RegAll(Env);

    TAutoPtr<TNode> AP=UberInit<TNode>(Env);
    (*AP.get())=std::move(NodeUnitTest::GetAppNode(Env));
    //QapSaveToFile(Env,AP,"Node_v0.qap");

    //TAutoPtr<TNode> AP;
    //QapLoadFromFile(Env,AP,"Node_v0.qap");

    ProtoSaveToFile(Env,"proto.hpp","AP",AP);
  }
};
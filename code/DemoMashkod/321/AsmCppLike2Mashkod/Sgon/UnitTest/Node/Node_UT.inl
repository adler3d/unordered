struct NodeUnitTest
{
  static void AddGenerator(IEnvRTTI&Env,TNode&node)
  {
    vector<TNode*> Arr;
    #define ADD_NODE(NAME,TYPE)\
      TNode NAME;{TNode&tmp=NAME;tmp.Caption=#NAME;tmp.Content=UberInit<TYPE>(Env);}Arr.push_back(&NAME);;
      ADD_NODE(OutNode,TDefContent);
      ADD_NODE(Generator,TGenNode);
      ADD_NODE(Manager,TUpdater);
    #undef ADD_NODE
    {
      //ошибка. type cast
      TUpdater*man=(TUpdater*)Manager.Content.get();
      TGenNode*gen=(TGenNode*)Generator.Content.get();
      man->Manager.pEnv=&Env;
      gen->Man=&man->Manager;
      gen->Node=&OutNode;
      gen->Name="item";
    }
    for(int i=0;i<Arr.size();i++)
      node.Attaches(std::move(*Arr[i]));
  };
  static TNode GetAppNode(IEnvRTTI&Env)
  {
    TNode node;
    node.Caption="Root";
    node.Content=UberInit<TRootContent>(Env);
    {
      TNode tmp;
      tmp.Caption="Application";
      tmp.Content=UberInit<TContent>(Env);
      node.Attaches(std::move(tmp));
    }
    AddGenerator(Env,node);
    return std::move(node);
  }
  template<typename U,typename V>
  static void UberCopy(TWeakPtr<U>&Dest,const TWeakPtr<V>&Source){
    static_assert(std::is_base_of<V,U>::value,"no way");
    static_assert(std::is_polymorphic<U>::value,"no way");
    V*tmp=Source.get();
    bool skip=tmp!=dynamic_cast<U*>(tmp);
    Dest=Source&&!skip?*(TWeakPtr<U>*)&Source:nullptr;
  }
  static void Run()
  {
    TStdAllocator MA;
    TEnvRTTI Env;
    Env.Alloc=&MA;
    int MU=0;
    Out("\n[Begin]\n");
    {
      NodeStructuresList::RegAll(Env);
      //TNode Node(NodeUnitTest::GetAppNode(Env));

      //TAutoPtr<TNode> AP=UberInit<TNode>(Env);
      //(*AP.get())=std::move(Node);
      //QapSaveToFile(Env,AP,"Node_v0.qap");

      TAutoPtr<TNode> AP;
      QapLoadFromFile(Env,AP,"Node_v0.qap");

      AP->Update();
      MU=MA.GetMemInfo().MemoryUsed;
    }
    Out("\n[End]\n");
    Out("AllocCount : "+IToS(MA.Info.AllocCount));
    Out("DeallocCount : "+IToS(MA.Info.DeallocCount));
    Out("MemoryUsed : "+IToS(MU)+"\n");
  }
};
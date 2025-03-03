class TNode;

class TBlock
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBlock)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<TNode>,Node,DEF,$,$)\
ADDVAR(2,TWeakPtr<TBlock>,Prev,DEF,$,$)\
ADDEND()
//=====+>>>>>TBlock
#include "QapGenStruct.inl"
//<<<<<+=====TBlock
public:
  static void SysHasSelf();
public:
  template<class TNode>
  void Init(TNode*P){
    if(!P)return;
    Node=P;
    Prev=Node->Block;
    Node->Block=this;
  }
  template<class TNode>
  void Free(){if(Node)Node->Block=Prev;}
public:
  TBlock(TNode*P){Init<TNode>(P);}
 ~TBlock(){Free<TNode>();}
};

//fetus
class TNode{
public:
  class IContent{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IContent)OWNER(TNode)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDEND()
    //=====+>>>>>IContent
    #include "QapGenStruct.inl"
    //<<<<<+=====IContent
  public:
    static void SysHasSelf();
  public:
    virtual void Update(TNode*Sender)=0;
  };
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TNode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,string,Caption,SET,"unnamed",$)\
ADDVAR(2,bool,Deaded,SET,false,$)\
ADDVAR(3,TWeakPtr<TNode>,Parent,DEF,$,$)\
ADDVAR(4,vector<TNode>,Items,DEF,$,$)\
ADDVAR(5,TWeakPtr<TBlock>,Block,DEF,$,$)\
ADDVAR(6,TAutoPtr<IContent>,Content,DEF,$,$)\
ADDEND()
//=====+>>>>>TNode
#include "QapGenStruct.inl"
//<<<<<+=====TNode
public:
  static void SysHasSelf();
public:
  void Update(){
    if(Content)
    {
      TBlock Block(this);
      Content->Update(this);
    }
  }
  void Attaches(TNode&&node){
    QapAssert(!Block);
    node.Parent=this;
    Items.push_back(std::move(node));
  }
  void Clean()
  {
    DoClean();
    for(int i=0;i<Items.size();i++)
      Items[i].Clean();
  }
  void DoClean()
  {
    int c=0;
    for(int i=0;i<Items.size();i++)
    {
      auto&it=Items[i];
      if(it.Deaded){continue;}
      if(i!=c)Items[c]=std::move(it);
      c++;
    }
    Items.resize(c);
  }
  void Clear()
  {
    for(int i=0;i<Items.size();i++)Items[i].Dead();
    Clean();
  }
  void Dead(){Deaded=true;}
};

//Can be inserted into any structure.
class TNodeManager{
public:
  class ICommand{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ICommand)OWNER(TNodeManager)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDEND()
    //=====+>>>>>ICommand
    #include "QapGenStruct.inl"
    //<<<<<+=====ICommand
  public:
    static void SysHasSelf();
  public:
    virtual void Use(TNodeManager*Man)=0;
  };
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TNodeManager)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<IEnvRTTI>,pEnv,DEF,$,$)\
ADDVAR(2,vector<TAutoPtr<ICommand>>,Commands,DEF,$,$)\
ADDEND()
//=====+>>>>>TNodeManager
#include "QapGenStruct.inl"
//<<<<<+=====TNodeManager
public:
  static void SysHasSelf();
public:
  #define MACRO_WEAK
  #include "macro_scope.inl"
  MACRO_WEAK_PROC(AddNode,(TNode*Target,TNode&&Node),(Target,std::move(Node)))
  {
    if(!pEnv)return;
    IEnvRTTI&Env=*pEnv.get();
    TAutoPtr<TCmdPushBack> Cmd=UberInit<TCmdPushBack>(Env);
    Cmd->Target=Target;
    Cmd->Node=std::move(Node);
    Commands.push_back(std::move(Cmd));
  }
  #include "macro_scope.inl"
  IEnvRTTI&GetEnv(){QapAssert(pEnv);return *pEnv.get();}
  void Update()
  {
    for(int i=0;i<Commands.size();i++)
    {
      auto&EX=Commands[i];
      if(!EX)return;
      EX->Use(this);
    }
    Commands.clear();
  }
};

//Command attaches a new node to the tree
class TCmdPushBack:public TNodeManager::ICommand{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TCmdPushBack)PARENT(TNodeManager::ICommand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TNode,Node,DEF,$,$)\
ADDVAR(1,TWeakPtr<TNode>,Target,DEF,$,$)\
ADDEND()
//=====+>>>>>TCmdPushBack
#include "QapGenStruct.inl"
//<<<<<+=====TCmdPushBack
public:
  void Use(TNodeManager*Man){
    if(!Target)return;
    Target->Attaches(std::move(Node));
  }
};

class TUpdater:public TNode::IContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUpdater)PARENT(TNode::IContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TNodeManager,Manager,DEF,$,$)\
ADDVAR(1,int,Counter,SET,0,$)\
ADDEND()
//=====+>>>>>TUpdater
#include "QapGenStruct.inl"
//<<<<<+=====TUpdater
public:
  void Update(TNode*Sender){
    Counter++;
    Manager.Update();
  };
};

class TContent;

class TGenNode:public TNode::IContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGenNode)PARENT(TNode::IContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TWeakPtr<TNodeManager>,Man,DEF,$,$)\
ADDVAR(1,TWeakPtr<TNode>,Node,DEF,$,$)\
ADDVAR(2,string,Name,SET,"unnamed",$)\
ADDVAR(3,int,Counter,SET,0,$)\
ADDEND()
//=====+>>>>>TGenNode
#include "QapGenStruct.inl"
//<<<<<+=====TGenNode
public:
  void Update(TNode*Sender){
    if(!Node||!Man&&!Man->pEnv)return;
    TNode tmp;
    tmp.Caption=Name+IToS(Counter++);
    tmp.Content=UberInit<TContent>(Man->GetEnv());
    Man->AddNode(Node.get(),std::move(tmp));
  }
};

class TContent:public TNode::IContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TContent)PARENT(TNode::IContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,Counter,SET,0,$)\
ADDEND()
//=====+>>>>>TContent
#include "QapGenStruct.inl"
//<<<<<+=====TContent
public:
  void Update(TNode*Sender){
    //Out("Counter = "+IToS(Counter));
    Counter++;
  }
};

class TRootContent:public TNode::IContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRootContent)PARENT(TNode::IContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TRootContent
#include "QapGenStruct.inl"
//<<<<<+=====TRootContent
public:
  static void UpdateItems(TNode*P){
    for(int i=0;i<P->Items.size();i++)P->Items[i].Update();
  }
  void Update(TNode*Sender){
    for(int i=10;i;i--){
      //Out("[Next]");
      UpdateItems(Sender);
      //Out("[Next]");
    };
  }
};

class TDefContent:public TNode::IContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDefContent)PARENT(TNode::IContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TDefContent
#include "QapGenStruct.inl"
//<<<<<+=====TDefContent
public:
  static void UpdateItems(TNode*P){
    for(int i=0;i<P->Items.size();i++)P->Items[i].Update();
  }
  void Update(TNode*Sender){
    UpdateItems(Sender);
  }
};

#define STRUCT_LIST(F)\
F(TBlock)\
F(TNode)F(TNode::IContent)\
F(TNodeManager)F(TNodeManager::ICommand)\
F(TCmdPushBack)F(TUpdater)F(TGenNode)F(TContent)F(TRootContent)F(TDefContent)
//`#define DEF_PRO_REG_TYPES_STRUCT(F)STRUCT_LIST(F)
//`//=====+++>>>>>TYPES(STRUCT)
//`#include "DefGenReg.inl"
//`//<<<<<+++=====TYPES(STRUCT)
struct NodeStructuresList{
  template<class QAP_RTTI>
  static void RegAll(QAP_RTTI&Env)
  {
    #define DEF_MACRO(TYPE)Sys$$<TYPE>::GetRTTI(Env);;
    STRUCT_LIST(DEF_MACRO);
    #undef DEF_MACRO
  }
};
#undef STRUCT_LIST
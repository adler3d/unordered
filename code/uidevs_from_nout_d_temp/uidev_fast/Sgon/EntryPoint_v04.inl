class TDependsStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDependsStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,Value,SET,128,$)\
ADDVAR(string,Name,DEF,$,$)\
ADDEND()
//=====+>>>>>TDependsStruct
#include "QapGenStruct.inl"
//<<<<<+=====TDependsStruct
};

class TBadStruct;

class TSelfStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSelfStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>TSelfStruct
#include "QapGenStruct.inl"
//<<<<<+=====TSelfStruct
public:
  static void SysHasSelf();
};

//

class TOtherDependsStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TOtherDependsStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,Value,SET,'9',$)\
ADDVAR(TDependsStruct,DS,DEF,$,$)\
ADDVAR(string,key_word,DEF,$,$)\
ADDVAR(TSelfStruct,some,DEF,$,$)\
ADDEND()
//=====+>>>>>TOtherDependsStruct
#include "QapGenStruct.inl"
//<<<<<+=====TOtherDependsStruct
};

class TBadStruct{
public:
  class Item{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Item)OWNER(TBadStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Item
    #include "QapGenStruct.inl"
    //<<<<<+=====Item
  public:
    static void SysHasSelf();
  public:
    virtual void go(){}
  };
  class Node:public Item{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Node)PARENT(Item)OWNER(TBadStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,Caption,DEF,$,$)\
    ADDVAR(vector<TAutoPtr<Item>>,Items,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Node
    #include "QapGenStruct.inl"
    //<<<<<+=====Node
  };
  class Leaf:public Item{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Leaf)PARENT(Item)OWNER(TBadStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,Name,DEF,$,$)\
    ADDVAR(TWeakPtr<Item>,Friend,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Leaf
    #include "QapGenStruct.inl"
    //<<<<<+=====Leaf
  };
public:
#define DEF_PRO_NESTED(F)F(Item)F(Node)F(Leaf)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBadStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,FirstField,SET,0,$)\
ADDVAR(TWeakPtr<DeclareType>,pDeclareType,DEF,$,$)\
ADDVAR(TDependsStruct,Sub,DEF,$,$)\
ADDVAR(TOtherDependsStruct,Sup,DEF,$,$)\
ADDVAR(vector<TWeakPtr<Item>>,ArrOfWeakPtr,DEF,$,$)\
ADDVAR(TBadStruct::Node,Root,DEF,$,$)\
ADDEND()
//=====+>>>>>TBadStruct
#include "QapGenStruct.inl"
//<<<<<+=====TBadStruct
};

class TBadLeaf{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBadLeaf)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TFieldPtr,Field,DEF,$,$)\
ADDVAR(TBadStruct::Node,Tree,DEF,$,$)\
ADDEND()
//=====+>>>>>TBadLeaf
#include "QapGenStruct.inl"
//<<<<<+=====TBadLeaf
public:
  static void SysHasSelf();
};

void BuildTree(TBadStruct::Node&Tree,TEnvRTTI&Env)
{
  Tree.Items.resize(4);
  for(int i=0;i<3;i++)
  {
    auto*p=Tree.Items[i].build<TBadStruct::Node>(Env);
    p->Caption="Node_"+IToS(i);
    if(i==1)
    {
      p->Items.resize(2);
      auto*ex=p->Items[0].build<TBadStruct::Node>(Env);
      ex->Caption="adler3d.narod.ru";
      ex=p->Items[1].build<TBadStruct::Node>(Env);
      ex->Caption="next item";
    }
    if(i==2)
    {
      p->Items.resize(4);
      for(int j=0;j<4;j++)
      {
        auto*ex=p->Items[j].build<TBadStruct::Leaf>(Env);
        ex->Friend=Tree.Items[j].get();
        ex->Name=CToS('A'+j);
      }
    }
  }
}
//template<class FUNC>
void AddN(ToolsYED&tools,int id,int N,int depth)
{
  if(!depth)return;
  for(int j=0;j<N;j++)
  {
    int last=tools.nodes.size();
    tools.add_node(IToS(last));
    tools.add_edge(id,last);
    AddN(tools,last,rand()%16,rand()%depth);
  }
}

void LoL()
{
  srand(GetTickCount());
  ToolsYED tools;
  tools.add_node(IToS(0));
  for(int i=0;i<10;i++)
  {
    int id=tools.nodes.size();
    tools.add_node(IToS(id));
    tools.add_edge(0,id);
    /*auto next=[](ToolsYED&tools,int id)
    {
      AddN(tools,id,3,[](ToolsYED&tools,int id){});
    };*/
    AddN(tools,id,rand()%8,rand()%6);
  }
  for(int i=0;i<200;i++)
  {
    //tools.edges.push_back(vec2i(rand()%100,rand()%100));
  }
  tools.load();
  tools.gen();
  tools.save();
}

void TestNext()
{
  srand(GetTickCount());
  ToolsYED tools;
  int group=tools.add_node(IToS(0));
  int first=tools.add_node(IToS(1),group);
  for(int i=0;i<10;i++)
  {
    int id=tools.nodes.size();
    tools.add_node(IToS(id),group);
    tools.add_edge(id,first);
  }
  tools.load();
  tools.gen();
  tools.save();
}

void TestNext2()
{
  srand(GetTickCount());
  ToolsYED tools;
  for(int i=0;i<200;i++)
  {
    tools.add_node(IToS(i));
  }
  for(int i=4;i<200;i++)
  {
    tools.nodes[i].parent=rand()%i;
  }
  tools.SetLQ();
  tools.load();
  tools.gen();
  tools.save();
}

void GenCricle(ToolsYED&tools,int n_owner)
{
  int n_circle=tools.add_node("TCircle");
  tools.add_edge(n_owner,n_circle);
  int n_position=tools.add_node("position = vec2d",n_circle);
  int n_x=tools.add_node("x = real(0.0)",n_position);
  int n_y=tools.add_node("y = real(0.0)",n_position);
  int n_radius=tools.add_node("radius = real(10.0)",n_circle);
  int n_self=tools.add_node("Self = TSelfPtr<TCircle>(0x000001)",n_circle);
  int n_sext=tools.add_node("Next = TWeakPtr<TCircle>(nullptr)",n_circle);
}

void TestNext3()
{
  srand(GetTickCount());
  ToolsYED tools;/*
  for(int i=0;i<200;i++)
  {
    tools.add_node(IToS(i));
  }
  for(int i=4;i<200;i++)
  {
    tools.nodes[i].parent=rand()%i;
  }*/
  int n_arr=tools.add_node("vector<TAutoPtr<TCircle>> arr;");
  for(int i=0;i<4;i++)
  {
    //int n_arr_i=tools.add_node("");
    int n_owner=tools.add_node("["+IToS(i)+"] = TAutoPtr<TCircle>");
    //tools.add_edge(n_arr,n_arr_i);
    tools.add_edge(n_arr,n_owner);
    GenCricle(tools,n_owner);
  }
  tools.SetLQ();
  tools.load();
  tools.gen();
  tools.save();
}

class TStringStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TStringStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Caption,DEF,$,$)\
ADDEND()
//=====+>>>>>TStringStruct
#include "QapGenStruct.inl"
//<<<<<+=====TStringStruct
};

void TestNext4(TEnvRTTI&Env)
{
  srand(GetTickCount());

  TBadLeaf Root;
  BuildTree(Root.Tree,Env);

  vector<TAutoPtr<TStringStruct>> MainArr;
  for(int i=0;i<9;i++)
  {
    TAutoPtr<TStringStruct> tmp;
    tmp.build<TStringStruct>(Env);
    tmp->Caption=IToS(i);
    MainArr.push_back(std::move(tmp));
  }

  ToolsYED tools;

  QapUberFullSaver(Env,QapRawUberObject(MainArr),UberSaveDeviceYed(tools));

  tools.SetLQ();
  tools.load();
  tools.gen();
  tools.output.filename="YedLeaf.graphml";
  tools.save();
}

class TCaptionStruct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TCaptionStruct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,DEF,$,$)\
ADDEND()
//=====+>>>>>TCaptionStruct
#include "QapGenStruct.inl"
//<<<<<+=====TCaptionStruct
public:
  static void SysHasSelf();
};

class TSomeContainer{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSomeContainer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<TCaptionStruct>>,Captions,DEF,$,$)\
ADDVAR(vector<TWeakPtr<TCaptionStruct>>,PtrArray,DEF,$,$)\
ADDEND()
//=====+>>>>>TSomeContainer
#include "QapGenStruct.inl"
//<<<<<+=====TSomeContainer
};

void TestNext5(TEnvRTTI&Env)
{
  srand(GetTickCount());

  TBadLeaf Root;
  BuildTree(Root.Tree,Env);

  TSomeContainer SomeCon;
  SomeCon.Captions.resize(3);
  SomeCon.PtrArray.resize(3);
  for(int i=0;i<3;i++)
  {
    auto&ex=SomeCon.Captions[i];
    ex.build<TCaptionStruct>(Env);
    ex->Caption=IToS(i);
    SomeCon.PtrArray[i]=ex.get();
  }

  ToolsYED tools;

  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceYed(tools));

  tools.SetLQ();
  tools.load();
  tools.gen();
  tools.output.filename="new.graphml";
  tools.save();
}

class TMegaHolder;

class IMegaItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IMegaItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TMegaHolder>,Owner,DEF,$,$)\
ADDEND()
//=====+>>>>>IMegaItem
#include "QapGenStruct.inl"
//<<<<<+=====IMegaItem
public:
  virtual void Run(){}
};

class TMegaHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMegaHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TAutoPtr<IMegaItem>,Item,DEF,$,$)\
ADDEND()
//=====+>>>>>TMegaHolder
#include "QapGenStruct.inl"
//<<<<<+=====TMegaHolder
public:
  static void SysHasSelf();
public:
  template<class TYPE>
  TYPE*build(IEnvRTTI&Env)
  {
    auto*p=Item.build<TYPE>(Env);
    p->Owner=this;
    return p;
  }
};

class QapMegaItem:public IMegaItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapMegaItem)PARENT(IMegaItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,DEF,$,$)\
ADDEND()
//=====+>>>>>QapMegaItem
#include "QapGenStruct.inl"
//<<<<<+=====QapMegaItem
public:
  void Run(){}
};

class QapReloadCounter:public IMegaItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapReloadCounter)PARENT(IMegaItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,Count,SET,0,$)\
ADDEND()
//=====+>>>>>QapReloadCounter
#include "QapGenStruct.inl"
//<<<<<+=====QapReloadCounter
public:
  void Run(){}
};

class TMegaContainer{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMegaContainer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(vector<TMegaHolder>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TMegaContainer
#include "QapGenStruct.inl"
//<<<<<+=====TMegaContainer
public:
  static void SysHasSelf();
public:
  void Go(IEnvRTTI&Env)
  {
    int count=2;
    Items.resize(count);
    for(int i=0;i<count;i++)
    {
      auto*ex=Items[i].build<QapMegaItem>(Env);
      ex->Name="Item"+IToS(i);
    }
  }
};

void TestNext6(TEnvRTTI&Env)
{
  srand(GetTickCount());

  ToolsYED tools;

  //TBadLeaf Root;
  //BuildTree(Root.Tree,Env);

  TMegaContainer Container;
  Sys$$<QapMegaItem>::GetRTTI(Env);
  Sys$$<QapReloadCounter>::GetRTTI(Env);
  //QapUberLoad(Env,QapRawUberObject(Container),TQapFileStream("Container.qap",true));
  QapUberFullLoader(Env,QapRawUberObject(Container),UberLoadDeviceBin(TQapFileStream("Container.qap",true)));

  Container.Items.push_back(TMegaHolder());
  Container.Items.back().build<QapReloadCounter>(Env)->Count=Container.Items.size();

  //Container.Go(Env);

  //int x;
  //IQapRawObject::TRawPtr raw_ptr(Env,x);
  //TQapBinaryObject qbo;
  //TConservationMachine Machine(Env,qbo);
  //Machine.Setup(raw_ptr);
  //Machine.Tools.

  QapUberFullSaver(Env,QapRawUberObject(Container),UberSaveDeviceBin(TQapFileStream("Container.qap",false)));

  QapUberFullSaver(Env,QapRawUberObject(Container),UberSaveDeviceProto(TQapFileStream("Container.hpp",false)));

  QapUberFullSaver(Env,QapRawUberObject(Container),UberSaveDeviceYed(tools));

  //tools.edges.clear();
  //tools.ConvToParentTree();

  tools.SetLQ();
  tools.load();
  tools.gen();
  tools.output.filename="Container.graphml";
  tools.save();
}

class TRootNextV7{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRootNextV7)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(DeclareTypeStruct,FieldType,DEF,$,$)\
ADDVAR(DeclareTypeSelfPtr,SelfType,DEF,$,$)\
ADDVAR(int,Counter,SET,0,$)\
ADDEND()
//=====+>>>>>TRootNextV7
#include "QapGenStruct.inl"
//<<<<<+=====TRootNextV7
public:
  static void SysHasSelf();
public:
  void SetToDef()
  {
    auto&Root=*this;
    auto&ft=Root.FieldType;
    auto&st=Root.SelfType;
    ft.Name="TUserwareStruct";
    ft.Members.push_back(DeclareMember());
    auto&back=ft.Members.back();
    back.Mode="DEF";
    back.Number=0;
    back.Name="Self";
    back.Type=&st;
    back.Value="$";
    st.ElementType=&ft;
  }
};

void TestNext7(TEnvRTTI&Env)
{
  srand(GetTickCount());

  TRootNextV7 Root;

  //HackType ht;
  //ht.MakeQwertyStruct

  bool Result=QapUberFullLoader(Env,QapRawUberObject(Root),UberLoadDeviceBin(TQapFileStream("Root.qap",true)));

  if(!Result)Root.SetToDef();
  Root.Counter++;

  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceBin(TQapFileStream("Root.qap",false)));
  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceProto(TQapFileStream("Root.hpp",false)));

  TQapIO IO;
  QapUberFullSaver(Env,QapRawUberObject(Root),UberSaveDeviceProto(TQapIOStream(IO)));

  QapUberFullSaver(Env,QapRawUberObject(IO.IO.mem),UberSaveDeviceProto(TQapFileStream("Root.Proto.hpp",false)));
}

//#include "DynamicTestProgram.inl"

//void TestNext8(TEnvRTTI&Env)
//{
//  TSomeTestProgram STP;
//  STP.Go(Env);
//}

void EntryPoint_v04(TEnvRTTI&Env)
{
  TestNext4(Env);
  //TestNext8(Env);
  return;

  /*
  Sys$$<TBadStruct>::GetRTTI(Env);
  Sys$$<TWeakPtr<TType>>::GetRTTI(Env);
  TBadLeaf Root;
  bool good=QapUberLoad(Env,QapRawUberObject(Root),TQapFileStream("bad_struct.hpp",true));
  Env.Prepare4();
  BuildTree(Root.Tree,Env);
  auto*p=Root.Tree.Items.back().build<TBadStruct::Node>(Env);
  p->Caption="Door";
  Root.Field.ConnectToField(Env,*p,p->Caption);
  QapUberSave(Env,QapRawUberObject(Root),TQapFileStream("bad_struct.hpp",false));
  QapUberProtoSave(Env,QapRawUberObject(Root),TQapFileStream("bad_struct_proto.h",false));
  */

  //if(!good)
  //{
  //  Root.Sub.Value=10;
  //  Root.Sub.Name="Sub";
  //  //Root.pTType=Sys$$<int>::GetRTTI(Env);
  //  Root.Sup.Value=99;
  //  Root.Sup.DS.Value=0;
  //  Root.Sup.DS.Name="0123456789ABCDEFG";
  //  Root.Sup.key_word="ver. 1.0";
  //  Root.Root.Items.resize(10);
  //  Root.Root.Caption="Root";
  //  Root.ArrOfWeakPtr.resize(5);
  //  for(int i=0;i<10;i++)
  //  {
  //    auto*p=Root.Root.Items[i].build<TBadStruct::Node>(Env);
  //    p->Caption="Node_"+IToS(i);
  //    if(i%2)Root.ArrOfWeakPtr[i/2]=p;
  //    if(i==4)
  //    {
  //      p->Items.resize(2);
  //      auto*ex=p->Items[0].build<TBadStruct::Node>(Env);
  //      ex->Caption="adler3d.narod.ru";
  //      ex=p->Items[1].build<TBadStruct::Node>(Env);
  //      ex->Caption="next item";
  //    }
  //    if(i==5)
  //    {
  //      p->Items.resize(4);
  //      for(int j=0;j<4;j++)
  //      {
  //        auto*ex=p->Items[j].build<TBadStruct::Leaf>(Env);
  //        ex->Friend=Root.Root.Items[j].get();
  //        ex->Name=CToS('A'+j);
  //      }
  //    }
  //  }
  //  QapUberSave(Env,QapRawUberObject(Root),TQapFileStream("bad_struct.hpp",false));
  //}
  int gg=1;
  return;
}
class TGUI_Content_Q3Text:public IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_Content_Q3Text)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<QapFontObject>,FontObject,DEF,$,$)\
ADDVAR(string,Text,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_Content_Q3Text
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_Content_Q3Text
public:
  void Render(TRenderContext&Context)
  {
    if(!FontObject)return;
    auto&qDev=Context.qDev;
    auto&Font=FontObject->Font;
    auto&FontTex=FontObject->Tex;
    FontTex.Bind();
    qDev.SetColor(0xff202020);
    vec2d dv=-Context.size*0.5;
    dv.y+=Context.size.y;
    vec2d pos=Context.pos+dv;
    vec2d mpos=Context.mpos+dv;
    mpos.x=Context.mpos.x+Context.size.x*0.5;
    int char_id=-1;
    string text=Text;
    if((mpos.y>0)&&(mpos.y<Font.Info[0].y))
    {
      if((mpos.x>0)&&(mpos.x<QapQ3Text::GetLength(Font,Text)))
      {
        char_id=mpos.x/Font.Info[0].x;
        text=text.substr(0,char_id)+"^E"+CToS(text[char_id])+"^0"+text.substr(char_id+1);
      }
    }
    QapQ3Text::DrawQapText(&qDev,Font,int(pos.x),int(pos.y),text);
  }
  void GetSize(vec2d&size)
  {
    size=vec2d_zero;
    if(!FontObject)return;
    auto&font=FontObject->Font;
    size.x=QapQ3Text::GetLength(font,Text);
    size.y=font.Info[0].y;
  }
};

class TGUI_ContentHolder:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_ContentHolder)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TAutoPtr<IGUI_Content>,Content,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_ContentHolder
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_ContentHolder
public:
  static void SysHasSelf();
public:
};

class TGUI_Panel{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_Panel)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TGUIRect,Current,SET,TGUIRect(vec2d(0,0),vec2d(256,128)),$)\
ADDVAR(TGUIRect,Rect,SET,TGUIRect(vec2d(0,0),vec2d(256,128)),$)\
ADDVAR()\
ADDVAR()\
ADDVAR(vector<TGUI_Panel>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_Panel
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_Panel
public:
  static void SysHasSelf();
public:
  struct IVisitor
  {
    virtual void Do(TGUI_Panel*p){}
  };
  void Use(IVisitor&A){A.Do(this);}
  TGUI_Panel*AddItem()
  {
    Items.push_back(std::move(TGUI_Panel()));
    return &Items.back();
  }
};

class TGUI_PanelOwner:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_PanelOwner)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<IProgramD3D9>,Program,DEF,$,$)\
ADDVAR(TGUI_Panel,Root,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_PanelOwner
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_PanelOwner
public:
  static void SysHasSelf();
public:
  typedef IGUI_Content::TRenderContext TRenderContext;
  typedef IGUI_Content::TUpdateContext TUpdateContext;
  typedef TGUI_Panel::IVisitor IVisitor;
public:
  struct TRenderVisitor:public IVisitor
  {
    TRenderContext&Context;
    TRenderVisitor(TRenderContext&Context):Context(Context){}
    void Do(TGUI_Panel*p)
    {
      auto&it=*p;
      //
      auto&qDev=Context.qDev;
      qDev.BindTex(0,nullptr);
      static QapColor color=0x20202020;
      qDev.SetColor(color);
      //
      vec2d cs=Context.size;
      vec2d&pos=it.Current.pos;
      vec2d&size=it.Current.size;
      {
        vec2d p=Context.pos+pos;
        qDev.DrawQuad(p.x,p.y,size.x,size.y,0);
      }
      if(!it.Items.empty()||it.Content)
      {
        TRenderContext Scope={
          Context.pos+pos,
          size,
          Context.mpos-pos,
          qDev
        };
        if(it.Content)it.Content->Render(Scope);
        auto&arr=it.Items;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          TRenderVisitor next(Scope);
          ex.Use(next);
        }
      }
    }
  };
  struct TUpdateVisitor:public IVisitor
  {
    TUpdateContext&Context;
    TUpdateVisitor(TUpdateContext&Context):Context(Context){}
    void Do(TGUI_Panel*p)
    {
      auto&it=*p;
      vec2d cs=Context.size;       
      vec2d&pos=it.Current.pos;
      vec2d&size=it.Current.size;
      const vec2d&rp=it.Rect.pos;
      const vec2d&rs=it.Rect.size;
      const vec2d&ap=it.Anchors.pos;
      const vec2d&as=it.Anchors.size;
      size=rs;
      if(it.Content)it.Content->GetSize(size);
      size.x=Clamp<int>(size.x,0,cs.x);
      size.y=Clamp<int>(size.y,0,cs.y);
      //Clamp();
      if(as.x>0)size.x=cs.x;
      if(as.y>0)size.y=cs.y;
      vec2d s=(cs-size)*0.5;
      pos=rp;
      if(rp.x>+s.x||ap.x>0){pos.x=+s.x;}
      if(rp.x<-s.x||ap.x<0){pos.x=-s.x;}
      if(rp.y>+s.y||ap.y>0){pos.y=+s.y;}
      if(rp.y<-s.y||ap.y<0){pos.y=-s.y;}
      if(!it.Items.empty()||it.Content)
      {
        TUpdateContext Scope={
          Context.pos+pos,
          size,
          Context.mpos-pos,
          Context.zDelta,
          Context.keyboard
        };
        if(it.Content)it.Content->Update(Scope);
        auto&arr=it.Items;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          TUpdateVisitor next(Scope);
          ex.Use(next);
        }
      }
    }
  };
  void Render(QapDev&qDev)
  {
    if(!Program)return;
    auto*prog=Program.get();
    vec2d pos=vec2d(0,0);
    vec2d size=prog->WindowGetClientSize();
    vec2d mpos=prog->WindowGetMousePos();
    TRenderContext Context={pos,size,mpos,qDev};
    TRenderVisitor V(Context);
    Root.Use(V);
  }
  void Update(IEnv&Env)
  {
    if(!Program)return;
    auto*prog=Program.get();
    vec2d pos=vec2d(0,0);
    vec2d size=prog->WindowGetClientSize();
    vec2d mpos=prog->WindowGetMousePos();
    int zDelta=prog->WindowGetzDelta();
    QapKeyboard&keyboard=prog->GetKeyBoard();
    IGUI_Content::TUpdateContext Context={pos,size,mpos,zDelta,keyboard};
    TUpdateVisitor V(Context);
    Root.Use(V);
  }
};


class MeUnit20121009:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnit20121009)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(string,Caption,SET,"GUI_Panel_Builder",$)\
ADDEND()
//=====+>>>>>MeUnit20121009
#include "QapGenStruct.inl"
//<<<<<+=====MeUnit20121009
public:
  static void SysHasSelf();
public:
  static void OnBuildEx(TBuildContext&Context,QapTreeDebugger*pQapTreeDebugger)
  {
    auto&Env=Context.Env;
    auto&Qrp=Context.Qrp;
    auto&PluginMan=Context.PluginMan;
    //BT
    auto*pD3D9Prog=Qrp.Program.get();
    auto*pFontObj=Qrp.ResList.AddItem<QapFontObject>(Env);
    pFontObj->SetToDef();
    pFontObj->Run(Env,&pD3D9Prog->D9Dev);
    //BT
    auto*pNode=pD3D9Prog->UserCode.AddItem<TProgramNode>(Env);
    //BT
    auto*pOnDown=true?&pQapTreeDebugger->OnDownSelect:pNode->AddItem<QapTextSelectorV4OnDown>(Env);
    pOnDown->Branch=&pQapTreeDebugger->SelectBranch;
    //BT
    auto*pKVP=pNode->AddItem<KeyVisorProgram>(Env);
    pKVP->Key=mbLeft;
    pKVP->Keyboard=&pD3D9Prog->GetKeyBoard();
    //BT
    pKVP->OnDown=pOnDown;
    //BT
    auto*pSelector=pNode->AddItem<QapTextSelectorV4>(Env);
    pSelector->base=Sys$$<IUnitProgram>::GetRTTI(Env);
    pSelector->selector.Font=pFontObj;
    pSelector->KeyVisor=pKVP;
    //BT
    pOnDown->Selector=pSelector;
    //BT
    auto*pContentHolder=pNode->AddItem<TGUI_ContentHolder>(Env);
    auto*pContent=pContentHolder->Content.build<TGUI_Content_Q3Text>(Env);
    pContent->Text="good night!";
    pContent->FontObject=pFontObj;
    //BT
    auto*pRenderNode=Qrp.Scene.AddItem<TRenderNodeEx>(Env);
    auto*pPanelOwner=pRenderNode->AddItem<TGUI_PanelOwner>(Env);
    pPanelOwner->Program=pD3D9Prog;
    pPanelOwner->Root.Rect.size=vec2d(360,625);
    pPanelOwner->Root.Anchors.pos.x=+1;
    //BT
    auto*pPanelForQ3text=pPanelOwner->Root.AddItem();
    pPanelForQ3text->Rect.size=vec2d(64,64);
    pPanelForQ3text->Content=pContent;
    pPanelForQ3text->Anchors.pos.y=-1;
    //BT
    auto*pPanelForSelector=pPanelOwner->Root.AddItem();
    pPanelForSelector->Rect.size=vec2d(64,64);
    pPanelForSelector->Content=&pSelector->selector;
  }
  void OnBuild(TBuildContext&Context)
  {
    //OnBuildEx(Context);
    //
  }
  void Update(IEnvRTTI&Env)
  {
    //nothing
  }
};
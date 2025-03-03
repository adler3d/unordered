class TGUIRect{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUIRect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,vec2d,pos,DEF,$,$)\
ADDVAR(1,vec2d,size,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUIRect
#include "QapGenStruct.inl"
//<<<<<+=====TGUIRect
public:
  TGUIRect(const vec2d&pos,const vec2d&size):pos(pos),size(size){}
  TGUIRect(vec2d&&pos,vec2d&&size):pos(std::move(pos)),size(std::move(size)){}
  vec2d getQuadPoint(bool x,bool y)const
  {
    return vec2d(pos.x+(size.x*0.5)*(x?+1.0:-1.0),pos.y+(size.y*0.5)*(y?-1.0:+1.0));
  }
  vec2d getQuadPoint(int id)const
  {
    //    y
    //    ^
    //   0|1
    //----.---->x
    //   2|3
    //    |
    return getQuadPoint((id==1)||(id==3),(id==2)||(id==3));
  }
  bool CheckPoint(const vec2d&p)const{
    return (abs(p.x-pos.x)<=size.x*0.5)&&(abs(p.y-pos.y)<=size.y*0.5);
  }
};

class QapIndentLine{    
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapIndentLine)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,indent,SET,0,$)\
ADDVAR(1,string,text,DEF,$,$)\
ADDEND()
//=====+>>>>>QapIndentLine
#include "QapGenStruct.inl"
//<<<<<+=====QapIndentLine
};

class QapTextSelectorV1:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV1)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<IProgramD3D9>,Program,DEF,$,$)\
ADDVAR(2,TWeakPtr<QapFontObject>,Font,DEF,$,$)\
ADDVAR(3,vec2d,Pos,SET,vec2d(+400,+280),$)\
ADDVAR(4,vec2d,MPos,SET,vec2d(0,0),$)\
ADDVAR(5,int,zDelta,SET,0,$)\
ADDVAR(6,int,SelectId,SET,-1,$)\
ADDVAR(7,vector<QapIndentLine>,Lines,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV1
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV1
public:
  static void SysHasSelf();
public:
  static bool toMonoEx(const string&line,string&mono)
  {
    bool flag=false;
    bool good=false;
    bool need=false;
    for(int i=0;i<line.size();i++)
    {
      auto&ex=line[i];
      if(ex=='^'){flag=true;continue;}
      if(!flag)
      {
        mono+=good?CToS(ex):" ";
        continue;
      }else{flag=false;}
      if(ex=='E'){good=true;need=true;continue;}
      good=false;
    }
    return need;
  };
  struct SelectIdUpdater
  {
    int x;
    int y;
    int dy;
    int dx;
    QapFont&font;
    const vec2d&Pos;
    const vec2d&MPos;
    SelectIdUpdater(QapFont&font,int zDelta,const vec2d&Pos,const vec2d&MPos):font(font),Pos(Pos),MPos(MPos)
    {
      x=0;
      y=Pos.y+zDelta;
      dy=-font.Info.Coords[0].y;
      dx=font.Info.Coords[0].x;
    }
    bool skip_line(const TGUIRect&Rect)
    {
      int value=y-Rect.pos.y;
      return !InDip<int>(-0.5*Rect.size.y+font.Info[0].y,value,+0.5*Rect.size.y);// !Rect.CheckPoint(vec2d(Rect.pos.x+1,y-Rect.pos.y));
    }
    bool foo(QapIndentLine&ex)
    {
      bool flag=false;
      int h=-dy-2;
      x=Pos.x+dx*ex.indent;
      if(InDip<int>(0,MPos.y-y-dy,h))
      {
        int L=QapQ3Text::GetLength(font,".."+ex.text);
        if(InDip<int>(0,MPos.x-x,L))
        {
          flag=true;
        }
      }
      return flag;
    }
    void next_line()
    {
      y+=dy;
    }
  };
  void Render(QapDev&qDev)
  {
    if(!Font)return;
    auto&font=Font->Font;
    auto&tex=Font->Tex;
    SelectIdUpdater SIU(font,zDelta,Pos,MPos);
    auto&x=SIU.x;
    auto&y=SIU.y;
    tex.Bind();
    QapDev::BatchScope Scope(qDev);
    for(int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      SIU.foo(ex);
      bool flag=SelectId==i;
      string line=!flag?"^1.^0"+ex.text+"^1.":"^7[^0"+ex.text+"^7]";
      for(;;)
      {
        string mono;
        if(!toMonoEx(line,mono))break;
        qDev.SetColor(0xff000000);
        QapQ3Text::DrawQapText(&qDev,font,x+1,y-1,mono);
        break;
      }
      QapQ3Text::DrawQapText(&qDev,font,x,y,line);
      SIU.next_line();
    }
  }
  void Update(IEnv&Env)
  {
    if(!Program)return;
    auto*prog=Program.get();
    MPos=prog->WindowGetMousePos();
    if(InDip<int>(Pos.x-10,MPos.x,Pos.x+80))
    {
      zDelta-=64*Sign(prog->WindowGetzDelta());
    }
    if(Font)
    {
      SelectIdUpdater SIU(Font->Font,zDelta,Pos,MPos);
      for(int i=0;i<Lines.size();i++)
      {
        auto&ex=Lines[i];
        bool flag=SIU.foo(ex);
        if(flag){
          SelectId=i;
        }
        SIU.next_line();
      }
    }
  }
};

class QapTextSelectorV0OnDown:public KeyVisorProgram::ICallback{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV0OnDown)PARENT(KeyVisorProgram::ICallback)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,bool,Enabled,SET,false,$)\
ADDVAR(2,bool,AutoDisable,SET,true,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV0OnDown
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV0OnDown
public:
  void Update(IEnv&Env){
    if(AutoDisable)Enabled=false;
  }
  void DoMove(KeyVisorProgram*pSender){Enabled=true;}
  void foo()
  {
    auto&OnDown=*this;
    if(OnDown.Enabled)
    {
      //QapTextSelectorV0 selector;
      //if(selector.select)
      //{
      //  class QapTreeDebuger;
      //  QapTreeDebuger qtd;
      //  qtd.select=selector.select.get();
      //}
    }
  }
};

class QapTextSelectorV0:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV0)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<KeyVisorProgram>,KeyVisor,DEF,$,$)\
ADDVAR(2,TWeakPtr<TType>,base,DEF,$,$)\
ADDVAR(3,TWeakPtr<TType>,select,DEF,$,$)\
ADDVAR(4,bool,need_refresh,SET,false,$)\
ADDVAR(5,bool,auto_update,SET,true,$)\
ADDVAR(6,vector<TWeakPtr<TType>>,list,DEF,$,$)\
ADDVAR(7,QapTextSelectorV1,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV0
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV0
public:
  static void SysHasSelf();
public:  
  struct Hidden
  {
    vector<TWeakPtr<TType>>&list;
    void add(TType*pType)
    {
      list.push_back(pType);
    }
    void render(QapDev&qDev,QapFont&font)
    {
      vec2d startpos=vec2d(10,10);
      QapQ3Text::DrawQapText(&qDev,font,startpos.x,startpos.y,"");
      //qDev.DrawT
    }
    void FindAllDerivedTypes(IEnvRTTI&Env,TType*pBaseType)
    {
      auto&arr=Env.GetArr();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto*p=ex.Type.get();
        if(!p->Factory)continue;
        if(!p->IsBasedOn(pBaseType))continue;
        add(p);
      }
    }
  };
public:
  void unselect()
  {
    select=nullptr;
    selector.SelectId=-1;
  }
  void change_base(TWeakPtr<TType>&pBaseType)
  {
    QapTextSelectorV0&selector=*this;
    selector.list.clear();
    selector.selector.Lines.clear();
    selector.unselect();
    selector.base=pBaseType.get();
    selector.need_refresh=true; 
  }
public:
  void Render(QapDev&qDev)
  {
    selector.Render(qDev);
  }
  void Update(IEnv&zEnv)
  {
    if(KeyVisor)
    {
      auto*key=KeyVisor.get();
      //key->Down
    }
    if(!base)
    {
      list.clear();
      selector.Lines.clear();
      unselect();
    }
    auto&Env=zEnv.Env;
    if(need_refresh)
    {
      need_refresh=false;
      list.clear();
      auto*pBaseType=base.get();
      Hidden hd={list};
      hd.FindAllDerivedTypes(Env,pBaseType);
    }
    if(auto_update)
    {
      unselect();
      selector.Update(zEnv);
      selector.Lines.clear();
      for(int i=0;i<list.size();i++)
      {
        auto&ex=list[i];
        if(!ex)return;
        auto*p=ex.get();
        QapIndentLine qil;
        qil.indent=0;
        qil.text=p->GetFullName();
        selector.Lines.push_back(std::move(qil));
        if(selector.SelectId==i)select=p;
      }
    }
    //ParentClass::u
  }
};

class MeUnit4:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnit4)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<QapTextSelectorV0>,Selector,DEF,$,$)\
ADDVAR(2,TWeakPtr<KeyVisorProgram>,KeyVisor,DEF,$,$)\
ADDVAR(3,TWeakPtr<QapTextSelectorV0OnDown>,OnDown,DEF,$,$)\
ADDEND()
//=====+>>>>>MeUnit4
#include "QapGenStruct.inl"
//<<<<<+=====MeUnit4
public:
  static void SysHasSelf();
public:
  void OnBuild(TBuildContext&Context)
  {
    auto&Env=Context.Env;
    auto&Qrp=Context.Qrp;
    auto&PluginMan=Context.PluginMan;
    //
    auto*font_obj=Qrp.ResList.AddItem<QapFontObject>(Env);
    font_obj->SetToDef();
    font_obj->Run(Env,&Qrp.Program->D9Dev);
    //
    auto*pNode=Qrp.Program->UserCode.AddItem<TProgramNode>(Env);
    //
    auto*pOnDown=pNode->AddItem<QapTextSelectorV0OnDown>(Env);
    //
    auto*pKVP=pNode->AddItem<KeyVisorProgram>(Env);
    pKVP->Key=mbLeft;
    pKVP->Keyboard=&Qrp.Program->GetKeyBoard();
    //
    this->KeyVisor=pKVP;
    //
    pKVP->OnDown=pOnDown;
    this->OnDown=pOnDown;
    //
    auto*selector=Qrp.Scene.AddItem<QapTextSelectorV0>(Env);
    selector->base=Sys$$<IUnitProgram>::GetRTTI(Env);
    selector->selector.Font=font_obj;
    selector->selector.Program=Qrp.Program.get();
    selector->KeyVisor=pKVP;
    //
    this->Selector=selector;
  }
  void Update(IEnvRTTI&Env)
  {
    //nothing
    if(OnDown&&KeyVisor&&Selector)
    {
      auto*pOnDown=OnDown.get();
      if(pOnDown->Enabled)
      {
        auto*pNewObjectType=Selector->select.get();
        //pNewObjectType
      }
    }
  }
};
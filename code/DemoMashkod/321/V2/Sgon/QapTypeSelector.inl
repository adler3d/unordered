class QapTextSelectorV3:public IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV3)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TWeakPtr<QapFontObject>,Font,DEF,$,$)\
ADDVAR(1,int,zDelta,SET,0,$)\
ADDVAR(2,int,SelectId,SET,-1,$)\
ADDVAR(3,vector<QapIndentLine>,Lines,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV3
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV3
public:
  static bool toMonoEx(const string&line,string&mono)
  {
    return QapTextSelectorV1::toMonoEx(line,mono);
  }
  typedef QapTextSelectorV1::SelectIdUpdater SelectIdUpdater;
  void Render(TRenderContext&Context)
  {
    if(!Font)return;
    auto&qDev=Context.qDev;
    auto&font=Font->Font;
    auto&tex=Font->Tex;
    vec2d pos=Context.pos-Context.size*0.5;
    pos.y+=Context.size.y;
    vec2d mpos=Context.pos+Context.mpos;
    SelectIdUpdater SIU(font,zDelta,pos,mpos);
    auto&x=SIU.x;
    auto&y=SIU.y;
    tex.Bind();
    TGUIRect ContextRect(Context.pos,Context.size);
    QapDev::BatchScope Scope(qDev);
    for(int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      if(SIU.skip_line(ContextRect))
      {
        SIU.next_line();
        continue;
      }
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
  void GetSize(vec2d&size)
  {
    if(!Font)return;
    if(Lines.empty())return;
    size=vec2d_zero;
    auto&font=Font->Font;
    int dx=font.Info.Coords[0].x;
    int dy=font.Info.Coords[0].y;
    for(int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      int x=dx*ex.indent+QapQ3Text::GetLength(font,ex.text+"..");
      size.x=std::max<int>(size.x,x);
      size.y+=dy;
    }
  }
  void Update(TUpdateContext&Context)
  {
    if(!Font)return;
    TGUIRect rect(Context.pos,Context.size);
    //
    vec2d pos=Context.pos-Context.size*0.5;
    pos.y+=Context.size.y;
    vec2d mpos=Context.pos+Context.mpos;
    //
    if(rect.CheckPoint(mpos))
    {
      zDelta-=64*Sign(Context.zDelta);
    }else{return;}
    if(Font)
    {
      SelectIdUpdater SIU(Font->Font,zDelta,pos,mpos);
      for(int i=0;i<Lines.size();i++)
      {
        auto&ex=Lines[i];
        //if(SIU.skip_line())
        bool flag=SIU.foo(ex);
        if(flag){
          SelectId=i;
        }
        SIU.next_line();
      }
    }
  }
};

class QapTextSelectorV4:public ISubProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV4)PARENT(ISubProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,TWeakPtr<KeyVisorProgram>,KeyVisor,DEF,$,$)\
ADDVAR(2,TWeakPtr<TType>,base,DEF,$,$)\
ADDVAR(3,TWeakPtr<TType>,select,DEF,$,$)\
ADDVAR(4,bool,focused,SET,false,$)\
ADDVAR(5,bool,need_refresh,SET,false,$)\
ADDVAR(6,bool,auto_update,SET,true,$)\
ADDVAR(7,vector<TWeakPtr<TType>>,list,DEF,$,$)\
ADDVAR(8,QapTextSelectorV3,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV4
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV4
public:
  static void SysHasSelf();
public:  
  typedef QapTextSelectorV0::Hidden Hidden;
public:
  void unselect()
  {
    select=nullptr;
    selector.SelectId=-1;
  }
  void change_base(TWeakPtr<TType>&pBaseType)
  {
    change_base_raw(pBaseType.get());
  }
  void change_base_raw(TType*pBaseType)
  {
    auto&selector=*this;
    selector.list.clear();
    selector.selector.Lines.clear();
    selector.unselect();
    selector.base=pBaseType;
    selector.need_refresh=true; 
  }
  static TType*GetTAutoPtr_ElemType_From_RawPtr(TVoidPtr::TRawPtr&raw_ptr)
  {
    auto*value=raw_ptr.pValue;
    auto*type=TTypeAutoPtr::UberCast(raw_ptr.pType);
    if(!type||!value)return nullptr;
    if(!type->ElementType)return nullptr;
    auto*elem_type=type->ElementType.get();
    return elem_type;
  }
  void change_base_ex(ITreeDebuggerBranch&Branch)
  {
    auto*pBaseType=GetTAutoPtr_ElemType_From_RawPtr(Branch.GetRawPtr());
    if(!pBaseType)return;
    change_base_raw(pBaseType);
  }
public:
  void Update(IEnv&zEnv)
  {
    if(KeyVisor)
    {
      auto*key=KeyVisor.get();
      if(key->Down){
        //unselect();
      }
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
      TType*pSelect=nullptr;
      selector.Lines.clear();
      for(int i=0;i<list.size();i++)
      {
        auto&ex=list[i];
        QapIndentLine qil;
        if(!ex)
        {
          selector.Lines.push_back(std::move(qil));
          continue;
        }
        auto*p=ex.get();
        qil.indent=0;
        qil.text=p->GetFullName();
        if(selector.SelectId==i)
        {
          pSelect=p;
          qil.text="^E"+qil.text;
        }
        selector.Lines.push_back(std::move(qil));
      }
      unselect();
      focused=bool(pSelect);
      if(pSelect)
      {
        select=pSelect;
      }else{
        select=nullptr;
      }
    }
    //ParentClass::u
  }
};

class QapTextSelectorV4OnDown:public KeyVisorProgram::ICallback{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapTextSelectorV4OnDown)PARENT(KeyVisorProgram::ICallback)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(1,bool,Enabled,SET,false,$)\
ADDVAR(2,bool,AutoDisable,SET,true,$)\
ADDVAR(3,TWeakPtr<QapTextSelectorV4>,Selector,DEF,$,$)\
ADDVAR(4,TWeakPtr<ITreeDebuggerBranch>,Branch,DEF,$,$)\
ADDEND()
//=====+>>>>>QapTextSelectorV4OnDown
#include "QapGenStruct.inl"
//<<<<<+=====QapTextSelectorV4OnDown
public:
  TType*GetSafeTypeFromBranch()
  {
    if(!Branch)return nullptr;
    auto*pBranch=Branch.get();
    auto raw_ptr=pBranch->GetRawPtr();
    auto*value=raw_ptr.pValue;
    auto*type=TTypeAutoPtr::UberCast(raw_ptr.pType);
    if(!type||!value)return nullptr;
    if(!type->ElementType)return nullptr;
    auto*elem_type=type->ElementType.get();
    //return 
  }
  void UpdateEx()
  {
    if(AutoDisable&&Enabled)do
    {
      Enabled=false;
      if(!Selector)break;
      auto*pSelector=Selector.get();
      if(!pSelector->focused)break;
      if(!pSelector->base)break;
      if(!pSelector->select)break;
      if(!Branch)break;
      auto*pBranch=Branch.get();
      auto raw_ptr=pBranch->GetRawPtr();
      auto*elem_type=QapTextSelectorV4::GetTAutoPtr_ElemType_From_RawPtr(raw_ptr);
      if(!elem_type)break;
      auto*pType=pSelector->select.get();
      if(!pType->IsBasedOn(elem_type))break;
      TAutoPtr<void>&Value=*(TAutoPtr<void>*)raw_ptr.pValue;
      Value=nullptr;
      auto&Product=Value.Product;
      Product.pType=pType;
      Product.Init();
      break;
    }while(false);
  }
  void Update(IEnv&Env)
  {
    UpdateEx();
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
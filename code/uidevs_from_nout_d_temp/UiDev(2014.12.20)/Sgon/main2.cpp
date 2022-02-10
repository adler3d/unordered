//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//

class TMachineRenderItem:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMachineRenderItem)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(vector<TAutoPtr<IRenderItem>>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TMachineRenderItem
#include "QapGenStruct.inl"
//<<<<<+=====TMachineRenderItem
public:
  static void SysHasSelf();
public:  template<class TYPE>
  TYPE*AddItem(IEnvRTTI&Env)
  {
    {IRenderItem*tmp=(TYPE*)nullptr;}//safe_cast
    Items.resize(Items.size()+1);
    return Items.back().build<TYPE>(Env);
  }
public:
  void Render(QapDev&qDev)
  {
    for(int i=0;i<Items.size();i++)
    {
      auto*ex=Items[i].get();
      if(!ex)continue;
      ex->Render(qDev);
    }
  }
public:
  TAutoPtr<IRenderItem>&front(){
    return Items.front();
  }
  TAutoPtr<IRenderItem>&back(){
    return Items.back();
  }
};

class QapQ3Text_v0:public IRenderItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapQ3Text_v0)PARENT(IRenderItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<QapFontObject>,FontObject,DEF,$,$)\
ADDVAR(string,Text,DEF,$,$)\
ADDVAR(vec2f,pos,SET,vec2f(600,20),$)\
ADDEND()
//=====+>>>>>QapQ3Text_v0
#include "QapGenStruct.inl"
//<<<<<+=====QapQ3Text_v0
public:
  static void SysHasSelf();
public:
  void Render(QapDev&qDev)
  {
    if(!FontObject)return;
    auto&Font=FontObject->Font;
    auto&FontTex=FontObject->Tex;
    FontTex.Bind();
    QapQ3Text::DrawQapText(&qDev,Font,pos.x,pos.y,Text);
  }
};

class qap_PointList:public IRenderItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_PointList)PARENT(IRenderItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<QapTex>,pTex,DEF,$,$)\
ADDVAR(vector<vec2d>,points,DEF,$,$)\
ADDVAR(vec2d,size,SET,vec2d(32,32),$)\
ADDVAR(real,ang,SET,0.0,$)\
ADDEND()
//=====+>>>>>qap_PointList
#include "QapGenStruct.inl"
//<<<<<+=====qap_PointList
public:
  static void SysHasSelf();
public:
  void Render(QapDev&qDev)
  {
    if(pTex)pTex->Bind(0);
    QapDev::BatchScope Scope(qDev);
    //qDev.BeginBatch();
    {
      qDev.SetColor(0xffffffff);
      for(int i=0;i<points.size();i++)
      {
        auto&ex=points[i];
        qDev.DrawQuad(ex.x+0.5,ex.y,size.x,size.y,ang);
      }
      if(0)
      {
        qDev.DrawPolyLine(points,1,false);
        qDev.SetColor(0xff00ff00);
        for(int i=0;i<points.size();i++)
        {
          auto&ex=points[i];
          qDev.DrawQuad(ex.x+0.5,ex.y,size.x*0.5,size.y*0.5,-ang*2);
        }
      }
    }
    //qDev.EndBatch();
  }
};

class MeUnit1:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnit1)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,value,SET,0,$)\
ADDVAR(string,str_value,DEF,$,$)\
ADDVAR(bool,auto_inc,SET,true,$)\
ADDVAR(bool,auto_itos,SET,true,$)\
ADDVAR(TWeakPtr<IProgramD3D9>,program,DEF,$,$)\
ADDVAR(TWeakPtr<qap_PointList>,points,DEF,$,$)\
ADDEND()
//=====+>>>>>MeUnit1
#include "QapGenStruct.inl"
//<<<<<+=====MeUnit1
public:
  void OnBuild(TBuildContext&Context)
  {
    auto&Env=Context.Env;
    auto&Qrp=Context.Qrp;
    auto&PluginMan=Context.PluginMan;
    if(Qrp.Scene.Items.empty())
    {
      auto*font_obj=Qrp.ResList.AddItem<QapFontObject>(Env);
      font_obj->SetToDef();
      font_obj->Run(Env,&Qrp.Program->D9Dev);
      auto*tex_obj=Qrp.ResList.AddItem<QapTexObject>(Env);
      tex_obj->File.FN="D:/Share/PNG/Creep.tga";
      tex_obj->SetToDef();
      tex_obj->Run(Env,&Qrp.Program->D9Dev);
      auto*mri=Qrp.Scene.AddItem<TMachineRenderItem>(Env);
      for(int i=0;i<3;i++)
      {
        auto*p=mri->AddItem<QapQ3Text_v0>(Env);
        p->Text="Hello World!";
        p->FontObject=font_obj;
        p->pos=vec2f(+400,-250);
        p->pos.y-=i*20;
      }
      points=mri->AddItem<qap_PointList>(Env);
      points->pTex=&tex_obj->Tex;
      program=Qrp.Program.get();
      //p->FontObject=Qrp.
    }
  }
  void Update(IEnvRTTI&Env)
  {
    if(auto_inc)value++;
    if(auto_itos)str_value=IToS(value);
    if(program)
    {
      auto&keyboard=program->GetKeyBoard();
      if(keyboard.Down[VK_SPACE])
      {
        keyboard.Down[VK_SPACE]=false;
        if(points)points->points.push_back(program->WindowGetMousePos());
      }
    }
  }
};

class MeUnit2:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnit2)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,id,SET,0,$)\
ADDVAR(bool,need_init,SET,false,$)\
ADDVAR(bool,need_free,SET,false,$)\
ADDVAR(bool,need_inc,SET,false,$)\
ADDVAR(bool,need_dec,SET,false,$)\
ADDVAR(string,message,SET,"noname",$)\
ADDVAR(vector<string>,arr,DEF,$,$)\
ADDVAR(bool,auto_update,SET,true,$)\
ADDEND()
//=====+>>>>>MeUnit2
#include "QapGenStruct.inl"
//<<<<<+=====MeUnit2
public:
  void Update(IEnvRTTI&Env)
  {
    if(need_init)
    {
      need_init=false;
      arr.push_back("attic");
      arr.push_back("shelf");
      arr.push_back("rotation");
      arr.push_back("angle");
      arr.push_back("Tortuar");
      arr.push_back("footpath");
      arr.push_back("layout");
      arr.push_back("sofa");
      arr.push_back("chair");
      arr.push_back("stool");
      arr.push_back("sock");
      arr.push_back("socks");
      arr.push_back("cup");
      arr.push_back("breadbasket");
      arr.push_back("sugar-bowl");
      arr.push_back("sugar");
      arr.push_back("bread");
      arr.push_back("pants");
      arr.push_back("edict");
      arr.push_back("awl");
      arr.push_back("soap");
      arr.push_back("egg");
      arr.push_back("bowl");
      arr.push_back("chicken");
      arr.push_back("wire");
      arr.push_back("decision");
    }
    if(need_free)
    {
      need_free=false;
      arr.clear();
    }
    if(need_inc)do
    {
      need_inc=false;
      if(arr.empty())break;
      id++;
      id=Clamp<int>(id,0,arr.size()-1);
      message=arr[id];
    }while(false);
    if(need_dec)do
    {
      need_dec=false;
      if(arr.empty())break;
      id--;
      id=Clamp<int>(id,0,arr.size()-1);
      message=arr[id];
    }while(false);
    if(auto_update)do
    {
      if(arr.empty())break;
      id=Clamp<int>(id,0,arr.size()-1);
      message=arr[id];
    }while(false);
  }
};

class MeUnit3:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(MeUnit3)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(int,buffer,SET,0,$)\
ADDVAR(bool,need_init,SET,false,$)\
ADDVAR(TFieldPtr,ptr,DEF,$,$)\
ADDEND()
//=====+>>>>>MeUnit3
#include "QapGenStruct.inl"
//<<<<<+=====MeUnit3
public:
  static void SysHasSelf();
public:
  void Update(IEnvRTTI&Env)
  {
    if(need_init)
    {
      need_init=false;
      ptr.ConnectToField(Env,*this,buffer);
    }
  }
};

class TGUI_MouseTrigon:public IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_MouseTrigon)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,SizeA,SET,32,$)\
ADDVAR(int,SizeB,SET,16,$)\
ADDEND()
//=====+>>>>>TGUI_MouseTrigon
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_MouseTrigon
public:
  virtual void Render(TRenderContext&Context){
    DrawGreenTrigon(Context.qDev,Context.pos+Context.mpos,SizeA,SizeB);
  }
  virtual void Update(TUpdateContext&Context){}
public:
  virtual void GetSize(vec2d&size){size=vec2d(512,512);}
public:
  static void DrawGreenTrigon(QapDev&qDev,const vec2d&pos,int SizeA,int SizeB)
  {
    qDev.SetColor(0xFF50A050);
    qDev.DrawTrigon(pos+vec2d(0,0),pos+vec2d(-SizeB,-SizeA),pos+vec2d(+SizeB,-SizeA));
  }
};

class TUnit20121101:public IUnitProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUnit20121101)PARENT(IUnitProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TWeakPtr<IUnitProgram>,LinkA,DEF,$,$)\
ADDVAR(TWeakPtr<IUnitProgram>,LinkB,DEF,$,$)\
ADDVAR(TWeakPtr<IUnitProgram>,LinkC,DEF,$,$)\
ADDVAR(TAutoPtr<IUnitProgram>,Other,DEF,$,$)\
ADDEND()
//=====+>>>>>TUnit20121101
#include "QapGenStruct.inl"
//<<<<<+=====TUnit20121101
public:
  static void SysHasSelf();
public:
};

class KeyVisor{
public:
  class ICallback{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ICallback)OWNER(KeyVisor)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>ICallback
    #include "QapGenStruct.inl"
    //<<<<<+=====ICallback
  public:
    static void SysHasSelf();
  public:
    virtual void DoMove(KeyVisor*pSender){}
  };
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(KeyVisor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(int,Key,SET,0,$)\
ADDVAR(bool,Down,SET,false,$)\
ADDVAR(TWeakPtr<ICallback>,OnUp,DEF,$,$)\
ADDVAR(TWeakPtr<ICallback>,OnMove,DEF,$,$)\
ADDVAR(TWeakPtr<ICallback>,OnDown,DEF,$,$)\
ADDEND()
//=====+>>>>>KeyVisor
#include "QapGenStruct.inl"
//<<<<<+=====KeyVisor
public:
  static void SysHasSelf();
public:
  void CallAction(TWeakPtr<ICallback>&A)
  {
    if(!A)return;
    A->DoMove(this);
  }
public:
  void DoMove(QapKeyboard&Keyboard)
  {
    if(!InDip<int>(0,Key,QapKeyboard::TKeyState::MAX_KEY-1))return;
    bool Flag=Keyboard.Down[Key];
    if(Flag==Down)
    {
      if(Keyboard.Changed[Key])
      {
        Down=!Down;if(Down){KeyDown();CallAction(OnDown);}else{KeyUp();CallAction(OnUp);}
        Down=!Down;if(Down){KeyDown();CallAction(OnDown);}else{KeyUp();CallAction(OnUp);}
      };
      if(Down){KeyMove();CallAction(OnMove);}
      return;
    }
    if(!Down&&Flag){Down=true;KeyDown();CallAction(OnDown);}
    if(Down&&!Flag){Down=false;KeyUp();CallAction(OnUp);}
    if(Down){KeyMove();CallAction(OnMove);}
  }
  virtual void KeyDown(){};
  virtual void KeyUp(){};
  virtual void KeyMove(){};
};

class TGUI_PointList:public IGUI_Content{
public:
  class TCallback:public KeyVisor::ICallback{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TCallback)PARENT(KeyVisor::ICallback)OWNER(TGUI_PointList)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
    ADDVAR(bool,Passed,SET,false,$)\
    ADDEND()
    //=====+>>>>>TCallback
    #include "QapGenStruct.inl"
    //<<<<<+=====TCallback
  public:
    static void SysHasSelf();
  public:
    void DoMove(KeyVisor*pSender)
    {
      Passed=true;
    }
  };
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_PointList)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<QapTex>,pTex,DEF,$,$)\
ADDVAR(KeyVisor,Key,DEF,$,$)\
ADDVAR(TCallback,OnDown,DEF,$,$)\
ADDVAR(bool,need_init_key,SET,false,$)\
ADDVAR(bool,drawpolyline,SET,false,$)\
ADDVAR(vec2i,size,SET,vec2i(32,32),$)\
ADDVAR(real,ang,SET,0.0,$)\
ADDVAR(vector<vec2i>,points,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_PointList
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_PointList
public:
  void Render(TRenderContext&Context)
  {
    QapDev&qDev=Context.qDev;
    if(pTex)pTex->Bind(0);
    QapDev::BatchScope Scope(qDev);
    //qDev.BeginBatch();
    {
      qDev.SetColor(0xffffffff);
      auto&pos=Context.pos;
      for(int i=0;i<points.size();i++)
      {
        auto&ex=points[i];
        qDev.DrawQuad(pos.x+ex.x,pos.y+ex.y,size.x,size.y,ang);
      }
      if(drawpolyline)
      {
        auto old_transform=qDev.GetTransform();
        qDev.SetTransform(transform2f(vec2f(pos),rot2f_ident));
        qDev.DrawPolyLine(points,1,false);
        qDev.SetColor(0xff00ff00);
        for(int i=0;i<points.size();i++)
        {
          auto&ex=points[i];
          qDev.DrawQuad(ex.x,ex.y,size.x*0.5,size.y*0.5,-ang*2);
        }
        qDev.SetTransform(old_transform);
      }
    }
    //qDev.EndBatch();
  }
  void GetSize(vec2d&size)
  {
    vec2i s=vec2i_zero;
    for(int i=0;i<points.size();i++)
    {
      auto&ex=points[i];
      s.x=std::max<int>(abs(ex.x),s.x);
      s.y=std::max<int>(abs(ex.y),s.y);
    }
    size=s;
    size*=2;
  }
  void Update(TUpdateContext&Context)
  {
    if(need_init_key)
    {
      need_init_key=false;
      Key.Key=mbMiddle;
      Key.OnDown=&OnDown;
    }
    OnDown.Passed=false;
    Key.DoMove(Context.keyboard);
    if(OnDown.Passed)
    {
      auto&p=Context.mpos;
      points.push_back(std::move(vec2i(p.x,p.y)));
    }
  }
};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      //F(MeUnit4)F(QapTextSelectorV0)F(QapTextSelectorV1)
      //F(QapTextSelectorV3)F(QapTextSelectorV4)F(QapTextSelectorV4OnDown)
      //F(MeUnit20121009)F(TGUI_PanelOwner)F(TGUI_Content_Q3Text)F(TGUI_ContentHolder)
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)\
        F(MeUnit1)F(MeUnit2)F(MeUnit3)\
        F(QapQ3Text_v0)F(TMachineRenderItem)F(qap_PointList)F(QapTexObject)\
        F(TGUI_PointList)\
        F(TUnit20121101)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    virtual void Run(IEnvRTTI&Env)
    {

    }
    ThisCompileUnit(){
      int df=0;
    }
  };
  ThisCompileUnit ThisUnit;
}
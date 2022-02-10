#include "StdAfx.h"
//#include <utility>

class TBookPageWithPathPrinter:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithPathPrinter)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,info,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithPathPrinter
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithPathPrinter
public:
  void Render(t_context&con)
  {
    auto&qDev=con.root.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      qDev.BindTex(0,&pFont->Tex);
      qDev.SetColor(0xff000000);
      //vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      auto add=[&](const string&text,int x,int y){
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+x),int(con.pos.y+y),text);//p.y+=-font.Info[0].y;
      };
      add(info,-QapQ3Text::GetLength(font,info)/2,0);
    }
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    info=con.GetCurBranchAsStr(this);
  }
};

class TCaptionFinder:public IVisitorRTTI{
public:
  typedef TCaptionFinder SelfClass;
public:
  struct t_out_item{int stack_size;IRenderProgram*ptr;};
  struct t_dev{
    TType*pTTypeIRenderProgram;
    TType*pTTypeString;
    string caption;
    void*pValue;
    IRenderProgram*cur_prog;
    vector<void*> stack;
    vector<t_out_item> out;
    void push(){
      stack.push_back(pValue);
    }
    void pop(){
      QapAssert(!stack.empty());
      pValue=stack.back();
      //QapAssert(stack.back()==pValue);
      stack.pop_back();
    }
    IRenderProgram*get_result()
    {
      QapAssert(out.size()<=1);
      if(out.empty())return nullptr;
      return out[0].ptr;
    }
  };
public:
  t_dev&dev;
  TCaptionFinder(t_dev&dev):dev(dev){}
public:
  void Do(TTypeStruct*p)
  {
    if(p->GetFullName()=="TGabobGame")
    {
      int gg=1;
      return;
    }
    if(p->SubType)
    {
      dev.push();
      dev.pValue=dev.pValue;
      p->SubType->Use(*this);
      dev.pop();
    }
    if(p==dev.pTTypeIRenderProgram)
    {
      dev.cur_prog=(IRenderProgram*)dev.pValue;
      auto*pCaption=p->find_member("Caption");
      bool ok=pCaption->Type.get()==dev.pTTypeString;
      if(ok)
      {
        auto&str=*(string*)pCaption->getValue(dev.pValue);
        if(str==dev.caption){dev.out.push_back({dev.stack.size(),dev.cur_prog});}
      }else{QapDebugMsg("WTF?");}
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      dev.push();
      dev.pValue=ex.getValue(dev.pValue);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSys*p)
  {
    //QapDebugMsg("no way");
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    auto Count=VecAPI->GetCount(dev.pValue);
    {
      dev.push();
      dev.pValue=&Count;
      p->SizeType->Use(*this);
      dev.pop();
    }
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(dev.pValue,i);
      dev.push();
      dev.pValue=ptr;
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSelfPtr*p)
  {
    //QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)dev.pValue;
    THardPtr<TType>&type=value.Product.pType;
    TType*pmTypeType=p->mType.Type.get();
    {
      dev.push();
      dev.pValue=&type;
      pmTypeType->Use(*this);
      dev.pop();
    }
    auto*ptr=value.get();
    QapAssert(bool(ptr)==bool(type));
    if(type)
    {
      dev.push();
      dev.pValue=ptr;
      type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeWeakPtr*p)
  {
    //QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p)
  {
    //QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    //QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    //QapDebugMsg("no way");
  }
};

bool branch_exec_from_string(IRenderProgram::t_context&con,const string&code,void*pThis)
{
  string hard_coded_cmd="if(kb.OnDown(VK_F6)){auto&f=root.find_by_caption(\"[QapTreeDebugger,TGUI_PanelOwner]\").Enabled;f=!f;}";
  if(code!=hard_coded_cmd)return false;
  if(!con.root.win.Keyboard.OnDown(VK_F6))return false;
  TRawPtr raw_ptr(con.Env,con.root.Scene);
  TCaptionFinder::t_dev dev;
  dev.pValue=raw_ptr.pValue;
  dev.pTTypeIRenderProgram=Sys$$<IRenderProgram>::GetRTTI(con.Env);
  dev.pTTypeString=Sys$$<string>::GetRTTI(con.Env);
  dev.caption="[QapTreeDebugger,TGUI_PanelOwner]";
  dev.cur_prog=nullptr;
  TCaptionFinder V(dev);
  raw_ptr.pType->Use(V);
  auto*ptr=dev.get_result();
  if(!ptr)return false;
  auto&f=ptr->Enabled;
  f=!f;
  return true;
};
/*
class t_some_struct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_some_struct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,izi,SET,"it easy",$)\
ADDVAR(bool,some_flag,DEF,$,$)\
ADDVAR(string,some_string,DEF,$,$)\
ADDVAR(int,noused2,DEF,$,$)\
ADDEND()
//=====+>>>>>t_some_struct
#include "QapGenStruct.inl"
//<<<<<+=====t_some_struct
public:
};

class t_some_struct2{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_some_struct2)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,gogogo,DEF,$,$)\
ADDVAR(t_some_struct,noused2,DEF,$,$)\
ADDEND()
//=====+>>>>>t_some_struct2
#include "QapGenStruct.inl"
//<<<<<+=====t_some_struct2
public:
};

class t_some_struct3{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_some_struct3)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(t_some_struct2,a,DEF,$,$)\
ADDVAR(t_some_struct2,b,DEF,$,$)\
ADDEND()
//=====+>>>>>t_some_struct3
#include "QapGenStruct.inl"
//<<<<<+=====t_some_struct3
public:
};

class t_some_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_some_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_some_struct3>,hoho,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(int,value,DEF,$,$)\
ADDVAR(string,so,DEF,$,$)\
ADDVAR(int,buffer,DEF,$,$)\
ADDEND()
//=====+>>>>>t_some_item
#include "QapGenStruct.inl"
//<<<<<+=====t_some_item
public:
};

class TProgramWithLoaderTest:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramWithLoaderTest)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,ogogo,DEF,$,$)\
ADDVAR(int,nothing,DEF,$,$)\
ADDVAR(vector<vector<t_some_item>>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramWithLoaderTest
#include "QapGenStruct.inl"
//<<<<<+=====TProgramWithLoaderTest
public:
  void Render(t_context&con){}
  void Update(t_context&con){}
};
*/
class TProgramWithTreeScriptExecuter:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProgramWithTreeScriptExecuter)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(string,code,DEF,$,$)\
ADDEND()
//=====+>>>>>TProgramWithTreeScriptExecuter
#include "QapGenStruct.inl"
//<<<<<+=====TProgramWithTreeScriptExecuter
public:
  void Render(t_context&con){}
  void Update(t_context&con)
  {
    if(need_init)
    {
      need_init=false;
      code="if(kb.OnDown(VK_F6)){auto&f=root.find_by_caption(\"[QapTreeDebugger,TGUI_PanelOwner]\").Enabled;f=!f;}";
      Caption="NodeSwitcher";
    }
    branch_exec_from_string(con,code,this);
  }
};

class TTest20140731_20140819:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTest20140731_20140819)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,point_id,SET,-1,$)\
ADDVAR(vec2i,offset,DEF,$,$)\
ADDVAR(bool,fixed,DEF,$,$)\
ADDVAR(bool,down,DEF,$,$)\
ADDVAR(vec2i,pos,DEF,$,$)\
ADDVAR(int,w,SET,128.0,$)\
ADDVAR(int,point_size,SET,16,$)\
ADDVAR(int,line_size,SET,4,$)\
ADDVAR(QapColor,point_color,SET,0xff404040,$)\
ADDVAR(bool,draw_points,DEF,$,$)\
ADDVAR(bool,bruteforce,DEF,$,$)\
ADDEND()
//=====+>>>>>TTest20140731_20140819
#include "QapGenStruct.inl"
//<<<<<+=====TTest20140731_20140819
public:
  void foo(){}
  array<vec2i,2> get_arr(const vec2i&offset)
  {
    array<vec2i,2> tmp; auto&a=tmp[0];auto&b=tmp[1];
    //tmp.reserve(2);
    //auto&a=qap_add_back(tmp);
    //auto&b=qap_add_back(tmp);
    auto dir=vec2i(1,0);
    a=offset+pos-dir*w/2;
    b=a+dir*w;
    return tmp;
  }
  void Render(t_context&con)
  {
    auto&qDev=con.root.qDev;
    qDev.SetBlendMode(QapDev::BlendType::BT_SUB);
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    auto one=vec2i(1,1);
    auto&arr=get_arr(vec2i_zero);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      qDev.SetColor(i==point_id?QapColor::HalfMix(point_color,0xffffffff):point_color);
      qDev.DrawCircle(ex,point_size,0,line_size,16);
    }
    qDev.SetColor(10==point_id?QapColor::HalfMix(point_color,0xffffffff):point_color);
    qDev.DrawCircle(pos,point_size,0,line_size,16);
    qDev.BindTex(0,nullptr);
  }
  void Update(t_context&con)
  {
    auto&kb=con.root.win.Keyboard;
    bool d=kb.Down[mbLeft];
    bool ondown=kb.OnDown(mbLeft);
    bool shift=kb.Down[VK_SHIFT];
    auto mpos=con.root.win.GetMousePos();
    if(ondown&&!down)
    {
      auto arr=get_arr(vec2i_zero);
      down=false;
      point_id=-1;
      for(int i=0;i<arr.size();i++)if((mpos-arr[i]).Mag()<point_size)
      {
        down=true;
        point_id=i;
        offset=mpos-arr[i];
      }
      //auto res=qap_find(arr,[&](vec2i&ex){return (mpos-ex).Mag()<point_size;});
    }
    if(down&&d&&!shift)
    {
      auto before=TRawRect::get_arr_x(0,pos.x,w);
      if(bruteforce)
      {
        auto new_pos=pos;
        auto new_w=w;
      
        for(pos.x=-1000;pos.x<+1000;pos.x++)
        for(w=-2000;w<2000;w++)
        {
          auto arr=TRawRect::get_arr_x(0,pos.x,w);
          if(arr[point_id]!=(mpos-offset).x)continue;
          if(arr[1-point_id]!=before[1-point_id])continue;
          new_w=w;new_pos=pos;
          goto end;
        }
        end:
        w=new_w;
        pos=new_pos;
      }else{
        TRawRect::calc_new_w_and_pos(mpos.x,offset.x,w,pos.x,point_id);
      }
      auto arr=TRawRect::get_arr_x(0,pos.x,w);
      QapAssert(arr[point_id]==(mpos-offset).x);
      QapAssert(arr[1-point_id]==before[1-point_id]);
      int gg=1;
    }
    down=down&&d;
    if(!down)point_id=-1;
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
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TBookPageWithPathPrinter)F(TProgramWithTreeScriptExecuter)F(TTest20140731_20140819)
        //F(TProgramWithLoaderTest)
        //F(TBookPageRectTable)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}
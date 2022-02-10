#include "StdAfx.h"
//#include <utility>

template<class TYPE>
struct t_qap_arr_safe_get_result{
  bool ok;
  TYPE*p;
};

template<class TYPE>
t_qap_arr_safe_get_result<TYPE> qap_arr_safe_get(vector<TYPE>&arr,int id)
{
  t_qap_arr_safe_get_result<TYPE> fail={false,nullptr};
  if(id<0)return fail;
  if(id>=arr.size())return fail;
  return {true,&arr[id]};
}

template<class TYPE>
static void qap_arr_drop_item_by_id(vector<TYPE>&arr,int id)
{
  QapAssert(!arr.empty());
  QapAssert(id>=0);
  QapAssert(id<arr.size());
  if(arr.empty())return;
  vector<TYPE> out;
  out.reserve(arr.size()-1);
  for(int i=0;i<arr.size();i++)if(i!=id)out.push_back(std::move(arr[i]));
  arr=std::move(out);
}

class TSuperOutDevice:public TOutDev{
public:
  class TBranch{
  public:
    TContext top;
    vector<TContext> items;
    void push(){items.push_back(top);}
    void pop(){top=items.back();items.pop_back();}
    TContext&back(){return items.back();}
    TContext&front(){return items.front();}
    int size(){return items.size();}
    TContext&operator[](int index){return items[index];}
  };
public:
  TBranch branch;
public:
  void push(DevCmd*pCmd)
  {
    auto&top=branch.top;
    QapAssert(!top.pCmd&&top.head.empty());
    branch.push();
    if(pCmd)
    {
      TCmdVisitor CV;
      CV.pContext=&top;
      pCmd->Use(CV);
      auto&back=branch.back();
      back.head=std::move(top.head);
      back.pCmd=std::move(pCmd);
    }else{
      top.pType=nullptr;
      top.pValue=nullptr;
    }
    top.pCmd=nullptr;
    top.head.clear();
  }
  void pop()
  {
    auto&top=branch.top;
    QapAssert(!top.pCmd&&top.head.empty());
    branch.pop();
    top.pCmd=nullptr;
    top.head.clear();
  }
};

class TBookPage20140814;

struct t_super_context{
  IEnvRTTI&Env;
  TD3DGameBoxBuilder&root;
  TBookPage20140814&head;
  TSuperOutDevice dev;
};

class IUniqueContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IUniqueContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IUniqueContent
#include "QapGenStruct.inl"
//<<<<<+=====IUniqueContent
public:
  virtual void Render(t_super_context&con){}
  virtual void Update(t_super_context&con){}
};

class TUniqueContentWithString:public IUniqueContent{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUniqueContentWithString)PARENT(IUniqueContent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>TUniqueContentWithString
#include "QapGenStruct.inl"
//<<<<<+=====TUniqueContentWithString
public:
  void Render(t_super_context&con)
  {
  }
  void Update(t_super_context&con)
  {
  }
};

class TUniqueRect{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TUniqueRect)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,Enabled,SET,true,$)\
ADDVAR(bool,AutoRender,SET,true,$)\
ADDVAR(bool,AutoUpdate,SET,true,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(vector<TUniqueRect>,points,DEF,$,$)\
ADDVAR(TAutoPtr<IUniqueContent>,content,DEF,$,$)\
ADDEND()
//=====+>>>>>TUniqueRect
#include "QapGenStruct.inl"
//<<<<<+=====TUniqueRect
public:
  static int test()
  {
    #define OFFSET_OF(TYPE,NAME)int(&(((TYPE*)nullptr)->*(&TYPE::NAME)))
    auto ee=ProxySys$$::GetFieldId(OFFSET_OF(SelfClass,points));
    QapDebugMsg("e");
    //OFFSET_OF(Enabled)==
    #undef OFFSET_OF
    return 1;
  }
};

void TUniqueRect_UpdateContent(TUniqueRect&item,IBookPage::t_context&con)
{
  if(!item.content)return;
  IBookPage::t_context context={
    con.context,
    con.Env,
    con.root,
    con.kb,
    con.qDev,
    con.head,
    con.book,
    con.pos+item.rect.pos,
    item.rect.get_size(),
    con.path
  };
  //item.content->Update(context);
}
class TBookPage20140814:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPage20140814)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TUniqueRect,root,DEF,$,$)\
ADDVAR(TUniqueRect,drag_rect,DEF,$,$)\
ADDVAR(vector<int>,drag_path,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPage20140814
#include "QapGenStruct.inl"
//<<<<<+=====TBookPage20140814
public:
  struct t_text_view{
    struct t_item{
      vec2i pos;
      string text;
    };
    vector<t_item> buff;
    void add(TUniqueRect&rect,const vec2i&offset)
    {
      if(!rect.AutoRender||!rect.Enabled)return;
      if(!rect.name.empty())
      {
        auto&back=qap_add_back(buff);
        back.pos=offset+rect.rect.pos;
        back.text=rect.name;
      }
      auto&arr=rect.points;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        add(ex,offset+rect.rect.pos);
      }
    }
  };
  void RenderViewText(t_context&con)
  {
    auto&qDev=con.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      qDev.BindTex(0,&pFont->Tex);
      con.qDev.SetColor(0xff000000);
      //vec2d p=con.pos+vec2d(+10,-10)+vec2d(-con.size.x,+con.size.y)*0.5;
      auto add=[&](const string&text,int x,int y){
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+x),int(con.pos.y+y),text);//p.y+=-font.Info[0].y;
      };
      auto addpoint=[&](TUniqueRect&point,const vec2i&offset){
        auto p=point.rect.pos+offset;
        add(point.name,p.x-QapQ3Text::GetLength(font,point.name)/2,p.y+font.Info[0].y/2);
      };
      auto additem=[&](t_text_view::t_item&item){
        auto p=item.pos;
        add(item.text,p.x-QapQ3Text::GetLength(font,item.text)/2,p.y+font.Info[0].y/2);
      };
      t_text_view tv;
      tv.add(root,vec2i_zero);
      tv.add(drag_rect,vec2i_zero);
      QapAssert(drag_rect.Enabled==(drag_rect.rect.down_a||drag_rect.rect.down_b));
      if(drag_rect.Enabled)QapAssert(!drag_path.empty());
      QapDev::BatchScope Scope(qDev);
      auto&arr=tv.buff;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        additem(ex);
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void RenderUniqueRect(t_context&con,TUniqueRect&item,bool is_root)
  {
    if(!item.AutoRender||!item.Enabled)return;
    if(!is_root)item.rect.Render(con);
    auto&arr=item.points;
    t_context context={
      con.context,
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      con.book,
      is_root?con.pos:con.pos+item.rect.pos,
      is_root?con.size:item.rect.get_size(),
      con.path
    };
    t_super_context supercon={
      con.Env,
      con.root,
      *this
    };
    //TOutDev::TMemberID devcmd(;
    //supercon.dev.push(&devcmd);
    if(item.content)item.content->Render(supercon);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      RenderUniqueRect(context,ex,false);
    }
  }
  void Render(t_context&con)
  {
    RenderUniqueRect(con,root,true);
    RenderUniqueRect(con,drag_rect,false);
    RenderViewText(con);
  }
  struct t_rect_upadter{
    TBookPage20140814&owner;
    bool passed;
    vector<int> path;
    void Update(t_context&con,TUniqueRect&item,bool is_root)
    {
      if(passed)return;
      if(!item.AutoUpdate||!item.Enabled)return;
      auto&drag_rect=owner.drag_rect;
      auto&drag_path=owner.drag_path;
      auto&arr=item.points;
      t_context context={
        con.context,
        con.Env,
        con.root,
        con.kb,
        con.qDev,
        con.head,
        con.book,
        is_root?con.pos:con.pos+item.rect.pos,
        is_root?con.size:item.rect.get_size(),
        con.path
      };
      //if(item.content)item.content->Update(context);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        path.push_back(i);
        Update(context,ex,false);
        path.pop_back();
      }
      if(is_root)return;
      if(!passed)
      {
        item.rect.Update(con);
      }
      if(passed)
      {
        //item.rect.UpdateEx(con,vec2i_zero,vec2i_zero);
      }
      if(item.rect.down_a||item.rect.down_b)
      {
        QapAssert(!passed);
        if(passed)return;
        if(item.rect.case_id==10)//!PointInQuad(ex.rect.pos,vec2i_zero,item.rect.get_size()))
        {
          drag_rect=std::move(item);
          item.rect.down_a=false;
          item.rect.down_b=false;
          item.Enabled=false;
          drag_rect.rect.pos+=item.rect.pos;
          QapAssert(drag_path.empty());
          drag_path=path;
        }
        passed=true;
      }
    }
  };
  struct t_path_builder{
    const vec2i&point;
    vector<int> path;
    bool Do(const vec2i&pos,TUniqueRect&item,bool is_root)
    {
      vector<int> out;
      auto&arr=item.points;
      auto offset=item.rect.pos+pos;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!ex.Enabled)continue;
        path.push_back(i);
        auto ok=Do(offset,ex,false);
        if(ok)return ok;
        path.pop_back();
      }
      if(is_root||PointInQuad(point,pos+item.rect.pos,item.rect.get_size()))
      {
        return true;
      }
      return false;
    }
  };
  void Update(t_context&con)
  {
    t_rect_upadter ru={*this};
    ru.passed=false;
    ru.Update(con,root,true);
    UpdateDragRect(con);
  }
  void UpdateDragRect(t_context&con)
  {
    if(!drag_rect.Enabled)return;
    drag_rect.rect.Update(con);
    if(drag_rect.content)TUniqueRect_UpdateContent(drag_rect,con);
    bool draged=drag_rect.rect.down_a||drag_rect.rect.down_b;
    if(draged)return;
    if(drag_path.empty())
    {
      drag_rect.Enabled=false;
      return;
    }
    t_path_builder pb={drag_rect.rect.pos};
    pb.Do(vec2i_zero,root,true);
    auto short_path=drag_path;
    short_path.pop_back();
    if(pb.path!=short_path)
    {
      //QapDebugMsg("no way.");
      {
        TUniqueRect*pcur=&root;
        vec2i offset=vec2i_zero;
        for(int i=0;i<pb.path.size();i++)
        {
          auto res=qap_arr_safe_get(pcur->points,pb.path[i]);
          QapAssert(res.ok);
          if(!res.ok)return;
          offset+=pcur->rect.pos;
          pcur=res.p;
        }
        drag_rect.rect.pos-=offset+pcur->rect.pos;
        pcur->points.push_back(std::move(drag_rect));
        drag_rect.Enabled=false;
      }
      //
      {
        TUniqueRect*pcur=&root;
        vec2i offset=vec2i_zero;
        for(int i=0;i<short_path.size();i++)
        {
          auto res=qap_arr_safe_get(pcur->points,short_path[i]);
          QapAssert(res.ok);
          if(!res.ok)return;
          offset+=pcur->rect.pos;
          pcur=res.p;
        }
        qap_arr_drop_item_by_id(pcur->points,drag_path.back());
      }
      //
      drag_path.clear();
      return;
    }
    TUniqueRect*pcur=&root;
    vec2i offset=vec2i_zero;
    for(int i=0;i<drag_path.size();i++)
    {
      auto res=qap_arr_safe_get(pcur->points,drag_path[i]);
      QapAssert(res.ok);
      if(!res.ok)return;
      offset+=pcur->rect.pos;
      pcur=res.p;
    }
    drag_rect.rect.pos-=offset;
    *pcur=std::move(drag_rect);
    drag_rect.Enabled=false;
    drag_path.clear();
  }
};
/*
class TBookPageRectTable:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageRectTable)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TBookPageRectTable
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageRectTable
public:
  void Render(t_context&con)
  {
  }
  void Update(t_context&con)
  {
    if(!con.is_hovered())return;
    if(!con.kb.Down[VK_MENU])return;
    if(con.kb.OnDown('Y'))
    {
      auto pType=con.book.pages[con.book.page_id].Product.pType.get();
      bool ok=pType->IsBasedOn(Sys$$<TBookPage20140814>::GetRTTI(con.Env));
      if(!ok)return;
      auto&ref=*(TBookPage20140814*)con.book.pages[con.book.page_id].get();
      QapAssert(ref.root.content.get()==this);
      auto&arr=ref.root.points;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.rect.h=con.size.y/arr.size();
        ex.rect.w=con.size.x;
        ex.rect.pos.x=0;
        ex.rect.pos.y=(con.size.y-con.size.y/arr.size())/2-i*con.size.y/arr.size();
      }
    }
    if(con.kb.OnDown('X'))
    {
      auto pType=con.book.pages[con.book.page_id].Product.pType.get();
      bool ok=pType->IsBasedOn(Sys$$<TBookPage20140814>::GetRTTI(con.Env));
      if(!ok)return;
      auto&ref=*(TBookPage20140814*)con.book.pages[con.book.page_id].get();
      QapAssert(ref.root.content.get()==this);
      auto&arr=ref.root.points;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.rect.w=con.size.x/arr.size();
        ex.rect.h=con.size.y;
        ex.rect.pos.y=0;
        ex.rect.pos.x=(con.size.x-con.size.x/arr.size())/2-i*con.size.x/arr.size();
      }
    }
  }
};*/

class TDay20140817BookV01:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDay20140817BookV01)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TDay20140605Book,book,DEF,$,$)\
ADDEND()
//=====+>>>>>TDay20140817BookV01
#include "QapGenStruct.inl"
//<<<<<+=====TDay20140817BookV01
public:
  void Render(t_context&con)
  {
    vector<TDay20140605Book*> path;
    IBookPage::t_context context={
      con.dev,
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.root.qDev,
      *(TDay20140605BookV00*)nullptr,
      book,
      vec2i_zero,
      vec2i_zero,
      path
    };
    context.pos=vec2i_zero;
    context.size=con.root.win.GetClientSize();
    book.Render(context);
  }
  void Update(t_context&con)
  {
    vector<TDay20140605Book*> path;
    IBookPage::t_context context={
      con.dev,
      con.Env,
      con.root,
      con.root.win.Keyboard,
      con.root.qDev,
      *(TDay20140605BookV00*)nullptr,
      book,
      vec2i_zero,
      vec2i_zero,
      path
    };
    context.pos=vec2i_zero;
    context.size=con.root.win.GetClientSize();
    {
      auto&dev=con.dev;
      TOutDevScopeMemberID devscope(dev,ProxySys$$::GET_FIELD_ID::book);
      book.Update(context);
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
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TBookPage20140814)F(TDay20140817BookV01)F(TUniqueContentWithString)
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
  ThisCompileUnit ThisUnit;
}
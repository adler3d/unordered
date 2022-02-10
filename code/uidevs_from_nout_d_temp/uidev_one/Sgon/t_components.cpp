#define DEF_PRO_HEAD
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL

bool ExecBranchScript(IBookPage::t_context&con,const string&code,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars);

bool EasyExecBranchScript(IBookPage::t_context&con,const string&script,vector<t_branch_head_ptr>&ptrs)
{
  vector<TAutoPtr<void>> vars;
  int ptrs_n=ptrs.size();
  bool last_ok=ExecBranchScript(con,script,ptrs,vars);
  ptrs.resize(ptrs_n);
  return last_ok;
}

class TComponent{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TComponent)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,caption,DEF,$,$)\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(bool,enabled,SET,true,$)\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(bool,auto_draw,SET,true,$)\
ADDVAR(string,script,DEF,$,$)\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(vector<TComponent>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TComponent
#include "QapGenStruct.inl"
//<<<<<+=====TComponent
public:
  typedef IBookPage::t_context t_context;
public:
  void Update(t_context&con)
  {
    if(!auto_move||!enabled)return;
    rect.Update(con);
    auto sub_con=con.make_sub_context(rect);
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::arr);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        TOutDevScopeVecID devscope(con.context.dev,i);
        ex.Update(sub_con);
      }
    }
    QapCleanIf(arr,[](TComponent&ex){return ex.need_remove;});
  }
  void Render(t_context&con)
  {
    if(!auto_draw||!enabled)return;
    rect.Render(con);
    auto sub_con=con.make_sub_context(rect);
    if(script=="for(int i=0;i<10;i++){auto x=i;x*=32;qDev.DrawQuad(x,0,16,16);}")
    {
      auto&qDev=con.qDev;
      auto qDev_DrawQuad=[&qDev,sub_con](int x,int y,int w,int h){
        qDev.DrawQuad(sub_con.pos+vec2i(x,y),w,h);
      };
      for(int i=0;i<10;i++){auto x=i;x*=32;qDev_DrawQuad(x,0,16,16);}
    }
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.Render(sub_con);
      }
    }
  }
};

#include "IScriptAST.inl"

class TScriptItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TScriptItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,caption,DEF,$,$)\
ADDVAR(bool,need_remove,DEF,$,$)\
ADDVAR(bool,force_run_once,DEF,$,$)\
ADDVAR(bool,enabled,SET,true,$)\
ADDVAR(bool,auto_move,SET,true,$)\
ADDVAR(bool,auto_draw,SET,true,$)\
ADDVAR(bool,auto_rebuild,SET,true,$)\
ADDVAR(string,data,DEF,$,$)\
ADDVAR(string,script,DEF,$,$)\
ADDVAR(bool,need_build_ast,DEF,$,$)\
ADDVAR(TAutoPtr<IScriptAST>,script_ast,DEF,$,$)\
ADDVAR(bool,last_ok,DEF,$,$)\
ADDVAR(int,oks,DEF,$,$)\
ADDVAR(int,fails,DEF,$,$)\
ADDVAR(int,build_oks,DEF,$,$)\
ADDVAR(int,build_fails,DEF,$,$)\
ADDEND()
//=====+>>>>>TScriptItem
#include "QapGenStruct.inl"
//<<<<<+=====TScriptItem
public:
  typedef IBookPage::t_context t_context;
public:
  static vector<t_branch_head_ptr> get_ptrs(t_context&con)
  {
    auto&path=con.path;
    auto*pprev_book=&con.book;
    auto ps=path.size();
    if(!ps)pprev_book=nullptr;
    if(ps)
    {
      if(path.back()!=&con.book)pprev_book=path.back();
      if(path.back()==&con.book)pprev_book=ps>1?path[ps-2]:nullptr;
    }
    vector<t_branch_head_ptr> ptrs;
    #define F(NAME,VAR){auto&back=qap_add_back(ptrs);back.name=NAME;back.raw_ptr.set(con.Env,VAR);}
    F("root",con.root);
    if(pprev_book)F("prevbook",*pprev_book);
    F("book",con.book);
    {auto&back=qap_add_back(ptrs);back.name="self";back.raw_ptr.set(con.context.dev.branch.top.pType,con.context.dev.branch.top.pValue);}
    #undef F
    return ptrs;
  }
  void Update(t_context&con)
  {
    if(force_run_once)
    {
      UpdateEx(con);
      force_run_once=false;
      return;
    }
    if(!auto_move||!enabled)return;
    UpdateEx(con);
  }
  void UpdateEx(t_context&con)
  {
    if(script.empty())return;
    if(auto_rebuild&&script_ast)
    {
      auto*p=script_ast.get();
      need_build_ast=need_build_ast||!p->check_source(script);
    }
    if(need_build_ast){need_build_ast=false;script_ast=nullptr;}
    if(!script_ast)
    {
      build_branch_script_ast(con.Env,script_ast,script);
      bool ok=script_ast;
      (ok?build_oks:build_fails)++;
      if(!ok)return;
    }
    auto*pScript=script_ast.get();;
    if(pScript)
    {
      auto ptrs=get_ptrs(con);
      auto res=pScript->exec(con,ptrs);
      last_ok=res.ok;
      (last_ok?oks:fails)++;
      return;
    }
    QapNoWay();
    auto ptrs=get_ptrs(con);
    last_ok=EasyExecBranchScript(con,script,ptrs);
    (last_ok?oks:fails)++;
  }
};

class TBookPageWithComponents:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithComponents)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TComponent,component,DEF,$,$)\
ADDVAR(TMultyBook,books,DEF,$,$)\
ADDVAR(vector<TScriptItem>,items,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithComponents
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithComponents
public:
  void UpdateItems(t_context&con)
  {
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::items);
      for(int i=0;i<items.size();i++)
      {
        auto&ex=items[i];
        TOutDevScopeVecID devscope(con.context.dev,i);
        ex.Update(con);
      }
    }
    QapCleanIf(items,[](TScriptItem&ex){return ex.need_remove;});
  }
  void Update(t_context&con)
  {
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::component);
      component.Update(con);
    }
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::books);
      books.Update(con);
    }
    UpdateItems(con);
  }
  void Render(t_context&con)
  {
    component.Render(con);
    books.Render(con);
  }
};

class TBookPageWithScriptList:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithScriptList)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,tick_max,SET,96,$)\
ADDVAR(TTextSelector,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithScriptList
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithScriptList
public:
  static string unsafe_get_curBranchAsStr(t_context&con,int start_id=0)
  {
    return con.GetCurBranchAsStr(con.context.dev.branch.top.pValue,start_id);
  }
  static TBookPageWithComponents*cbrft_for_TBookPageWithComponents(t_context&con)
  {
    auto&context=con.context;
    auto*pType=Sys$$<TBookPageWithComponents>::GetRTTI(con.Env);
    if(!pType)return nullptr;
    auto&arr=context.dev.branch;
    if(arr.empty()){QapNoWay();return nullptr;}
    for(int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ax=arr[i];
      if(ax.pType!=pType)continue;
      return (TBookPageWithComponents*)ax.pValue;
    }
    string msg="cbrft not found this type on current branch.\nbranch:\n"+unsafe_get_curBranchAsStr(con)+"\n\ntype:\n"+pType->GetFullName();
    QapDebugMsg(msg);
    return nullptr;
  }
  static string get_head_of_book(TMultyBook::TBook&book)
  {
    vector<string> out;
    auto&arr=book.book.pages;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex)continue;
      qap_add_back(out)=ex->Caption;
    }
    return "["+join(out," | ")+"]";
  }
  bool CheckSelector(t_context&con)
  {
    if(!selector.OnDown)return false;
    selector.OnDown=false;
    auto selected=selector.Lines[selector.SelectId];
    int e=0;
    auto ssid=ScanParam("[",selected,"]",e);
    if(e<0)return false;
    int id=SToI(ssid);
    auto*p=cbrft_for_TBookPageWithComponents(con);
    if(!p)return false;
    auto&flag=p->items[id].enabled;
    flag=!flag;
    RefreshSelector(con);
    return true;
  }
  void RefreshSelector(t_context&con)
  {
    auto*p=cbrft_for_TBookPageWithComponents(con);
    if(!p)return;
    selector.Lines.clear();
    auto&arr=p->items;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      //if(ex.enabled)continue;
      qap_add_back(selector.Lines)="script["+IToS(i)+"]; enabled = "+IToS(ex.enabled)+"; caption = "+ex.caption;
    }
  }
  void Update(t_context&con)
  {
    if(need_init){need_init=false;RefreshSelector(con);}
    //
    {
      auto&dev=con.context.dev;
      TOutDevScopeMemberID devscopeMember(dev,ProxySys$$::GET_FIELD_ID::selector);
      selector.Update(con);
    }
    bool need_refresh=false;
    if(con.is_hovered())
    {
      auto&kb=con.kb;
      if(kb.OnDown(VK_F5)||(kb.Down[VK_CONTROL]&&kb.OnDown('R')))
      {
        need_refresh=true;
      }
      if(kb.OnDown('A')&&kb.Down[VK_CONTROL])
      {
        //show_all_books=!show_all_books;
        need_refresh=true;
      }
    }
    tick++;
    if(tick>tick_max){tick=0;need_refresh=true;}
    if(need_refresh)
    {
      RefreshSelector(con);
    }
    CheckSelector(con);
  }
  void Render(t_context&con)
  {
    selector.Render(con);
  }
};

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const{return __FILE__;}
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TBookPageWithComponents)F(TBookPageWithScriptList)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}
#include "StdAfx.h"

class TBookPageWithHiddenBooks:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithHiddenBooks)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,tick_max,SET,96,$)\
ADDVAR(bool,show_all_books,DEF,$,$)\
ADDVAR(TTextSelector,selector,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithHiddenBooks
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithHiddenBooks
public:
  static string unsafe_get_curBranchAsStr(t_context&con,int start_id=0)
  {
    return con.GetCurBranchAsStr(con.context.dev.branch.top.pValue,start_id);
  }
  static TMultyBook*cbrft_for_TMultyBook(t_context&con)
  {
    auto&context=con.context;
    auto*pType=Sys$$<TMultyBook>::GetRTTI(con.Env);
    if(!pType)return nullptr;
    auto&arr=context.dev.branch;
    if(arr.empty()){QapNoWay();return nullptr;}
    for(int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ax=arr[i];
      if(ax.pType!=pType)continue;
      return (TMultyBook*)ax.pValue;
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
    auto*p=cbrft_for_TMultyBook(con);
    if(!p)return false;
    auto&flag=p->books[id].Enabled;
    flag=!flag;
    RefreshSelector(con);
    return true;
  }
  void RefreshSelector(t_context&con)
  {
    auto*p=cbrft_for_TMultyBook(con);
    if(!p)return;
    selector.Lines.clear();
    auto&arr=p->books;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.Enabled&&!show_all_books)continue;
      qap_add_back(selector.Lines)="books["+IToS(i)+"]; Enabled = "+IToS(ex.Enabled)+"; Caption = "+get_head_of_book(ex);
    }
  }
  void Update(t_context&con)
  {
    if(need_init){need_init=false;Caption="HiddenBooks";RefreshSelector(con);}
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
        show_all_books=!show_all_books;
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
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TBookPageWithHiddenBooks)
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
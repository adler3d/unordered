#include "InetDownloader.hpp"

class t_button{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_button)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(vec2d,pos,DEF,$,$)\
ADDVAR(vec2d,size,DEF,$,$)\
ADDVAR(string,onclick,DEF,$,$)\
ADDEND()
//=====+>>>>>t_button
#include "QapGenStruct.inl"
//<<<<<+=====t_button
public:
};

class TPageWithMenu{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPageWithMenu)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(bool,need_resize_buttons,DEF,$,$)\
ADDVAR(QapColor,def_color,SET,0xffd0d0d0,$)\
ADDVAR(QapColor,hov_color,SET,0xffdcdcdc,$)\
ADDVAR(vector<t_button>,buttons,DEF,$,$)\
ADDVAR(bool,editor_enabled,SET,true,$)\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(string,main_server_name,SET,"qap.zz.vc",$)\
ADDVAR(string,main_server_path,SET,"/server/",$)\
ADDVAR(string,netserver,DEF,$,$)\
ADDVAR(TMultyBook,books,DEF,$,$)\
ADDEND()
//=====+>>>>>TPageWithMenu
#include "QapGenStruct.inl"
//<<<<<+=====TPageWithMenu
public:
  typedef IBookPage::t_context t_context;
public:
  void Init(t_context&con)
  {        
    editor.text="//menu\nrefresh;menu\neditor;(editor;)\nscroll;(scroll;)\nbooks;(books;)\nempty;empty\n\n\n//empty\n";
    editor.text+="menu;@@@;self.onclick=\"@@@;self.pos.x=650\\nself.pos.y=350\\nself.onclick=\\\"menu\\\"\"";
    editor.need_load_text=false;
    LoadButtons(con,editor.text,"menu");
    need_init=false;
  }
  void RenderText(t_context&con)
  {
    auto&qDev=con.root.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    {
      QapDev::BatchScope Scope(con.qDev);
      qDev.BindTex(0,&pFont->Tex);
      QapColor text_color=0xff000000;
      qDev.SetColor(text_color);
      int cy=font.Info[' '].y;
      auto add_text=[&](const string&text,vec2d&p){
        auto len=QapQ3Text::GetLength(font,text);
        QapQ3Text::DrawQapText(&qDev,font,int(con.pos.x+p.x-len/2),int(con.pos.y+p.y+cy/2),text);
      };
      auto&arr=buttons;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        qDev.SetColor(ex.onclick.empty()?QapColor::HalfMix(text_color,0xffffffff):text_color);
        if(ex.name=="#netserver"){add_text(netserver,ex.pos);continue;}
        add_text(ex.name,ex.pos);
      }
    }
    qDev.BindTex(0,nullptr);
  }
  void Render(t_context&con)
  {
    auto&qDev=con.root.qDev;
    auto mpos=con.get_mpos();
    qDev.BindTex(0,nullptr);
    auto&arr=buttons;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      qDev.SetColor(def_color);
      bool ok=PointInQuad(mpos,ex.pos,ex.size);
      if(ok)qDev.SetColor(hov_color);
      if(ex.onclick.empty())qDev.color=QapColor::HalfMix(def_color,0xff808080);
      qDev.DrawQuad(con.pos+ex.pos,ex.size);
    }
    RenderText(con);
    qDev.BindTex(0,nullptr);
    if(editor_enabled)editor.Render(con);
    books.Render(con);
  }
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
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    if(need_init)Init(con);
    if(con.is_hovered()&&con.kb.OnDown(mbLeft))
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::buttons);
      auto mpos=con.get_mpos();
      auto&arr=buttons;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        bool ok=PointInQuad(mpos,ex.pos,ex.size);
        if(!ok)continue;
        if(is_first_part_of(ex.onclick,"@@@;"))
        {
          TOutDevScopeVecID devscope(con.context.dev,i);
          vector<TAutoPtr<void>> vars;
          auto ptrs=get_ptrs(con);
          string code=without_first_part(ex.onclick,"@@@;");
          bool ok=ExecBranchScript(con,code,ptrs,vars);
          if(!ok)QapDebugMsg("script in button.onclick failed:\n"+code);
          break;
        }
        if(ex.onclick=="()"){ex.name+=" ()";break;}
        if(ex.onclick=="(x++;)"){ex.pos.x+=10;break;}
        if(ex.onclick=="(y++;)"){ex.pos.y+=10;break;}
        if(ex.onclick=="(x--;)"){ex.pos.x-=10;break;}
        if(ex.onclick=="(y--;)"){ex.pos.y-=10;break;}
        if(ex.onclick=="(exit;)"){con.context.root.win.Close();break;}
        if(ex.onclick=="(line;)"){menu_as_line(con);break;}
        if(ex.onclick=="(books;)"){books.Enabled=!books.Enabled;break;}
        if(ex.onclick=="(editor;)"){editor_enabled=!editor_enabled;break;}
        if(ex.onclick=="(scroll;)"){editor.scroll_lines=editor.scroll_lines?0:3;break;}
        if(ex.onclick=="(netserver;)"){netserver=NetDownloadExec(main_server_name,main_server_path);break;}
        if(!ex.onclick.empty())
        {
          LoadButtons(con,editor.text,ex.onclick);
          break;
        }
        break;
      }
      need_resize_buttons=true;
    }
    if(need_resize_buttons)
    {
      need_resize_buttons=false;
      auto&arr=buttons;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        const string&ex_name=(ex.name=="#netserver"?netserver:ex.name);
        ex.size=vec2d(QapText::GetLength(font,ex_name)+18,18);
      }
    }
    int gg_for_books=1;
    {
      TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::books);
      books.Update(con);
    }
    if(editor_enabled)
    {
      auto&arr=books.books;
      bool skip=false;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(!ex.Enabled||!ex.Moved)continue;
        skip=skip||con.make_sub_context(ex.rect).is_hovered();
      }
      if(!skip||!books.Enabled||!books.Moved)
      {
        editor.Update(con);
      }
    }
    int gg=1;
  }
  void menu_as_line(t_context&con)
  {
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;
    int x=0;
    int dx=18;
    for(int i=0;i<buttons.size();i++)
    {
      auto&ex=buttons[i];
      ex.pos=vec2d(x+ex.size.x/2,0);
      x+=dx+ex.size.x;
    }
    for(int i=0;i<buttons.size();i++)
    {
      auto&ex=buttons[i];
      ex.pos.x-=x/2;
    }
  }
  void LoadButtons(t_context&con,const string&s,const string&cmd)
  {
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=con.root.SysRes.FontObj->Font;auto cy=font.Info[' '].y; int dy=-(18+18);
    int gw=2;
    auto arr=split(s,"\n");
    int n=0; string head;
    vector<t_button> out;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.substr(0,2)=="//"){head=ex.substr(2);continue;}
      if(ex.empty()){head.clear();continue;}
      if(head!=cmd){continue;}
      auto t=split(ex,";");
      auto&back=qap_add_back(out);
      back.name=t[0];
      back.pos=vec2d(0,dy*n);n++;
      back.size=vec2d(QapText::GetLength(font,back.name)+18,18);
      QapPopFront(t);
      back.onclick=join(t,";");
    }
    if(!n)return;
    buttons=std::move(out);
    for(int i=0;i<buttons.size();i++)
    {
      auto&ex=buttons[i];
      ex.pos.y-=n*dy/2;
    }
  }
  static string NetDownloadExec(const string&host,const string&path,const string&cookie="")
  {
    string out;
    DownLoader DL(host,path,cookie);
    DL.start();
    for(int i=0;DL.update();i++){
      Sleep(16);
      int wait_here=1;
    }
    out=DL.data;
    string content=DownLoader::GetContent(DL.data,true);
    DL.stop();
    int gg=1;
    return content;
  }
};

class TBookPageWithButtons:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithButtons)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TPageWithMenu,impl,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithButtons
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithButtons
public:
  void Update(t_context&con)
  {
    TOutDevScopeMemberID devscope(con.context.dev,ProxySys$$::GET_FIELD_ID::impl);
    impl.Update(con);
  }
  void Render(t_context&con)
  {
    impl.Render(con);
  }
};
#define DEF_PRO_FULL
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL
//#include <utility>

class TBookPage20140605FullBook:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPage20140605FullBook)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vec2i,old_pos,DEF,$,$)\
ADDVAR(vec2i,old_size,DEF,$,$)\
ADDVAR(bool,flag,DEF,$,$)\
ADDVAR(bool,fixed,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPage20140605FullBook
#include "QapGenStruct.inl"
//<<<<<+=====TBookPage20140605FullBook
public:
  void Render(t_context&con)
  {
    if(!con.root.SysRes.FontObj)return;
    auto*pFont=con.root.SysRes.FontObj.get();
    auto&font=pFont->Font;
    con.qDev.BindTex(0,&pFont->Tex);
    auto p=con.pos+vec2i(+10,-10)+vec2i(-con.size.x,+con.size.y)/2;
    QapQ3Text::DrawQapText(&con.qDev,font,int(p.x),int(p.y),"press F5.");
    con.qDev.BindTex(0,0);
  }
  void Update(t_context&con)
  {
    if(!con.kb.OnDown(VK_F5))return;
    if(!flag){
      old_pos=vec2i(0,0);
      old_size=con.root.win.GetClientSize();
    }
    flag=true;
    std::swap(old_pos,con.head.rect.pos);
    std::swap(old_size.x,con.head.rect.w);
    std::swap(old_size.y,con.head.rect.h);
    con.head.rect.fixed=fixed;
  }
};

class TBookPageWithScrollBar:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithScrollBar)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TScrollBar,bar,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithScrollBar
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithScrollBar
public:
  void Update(t_context&con){bar.Update(con);}
  void Render(t_context&con){bar.Render(con);}
};

class TRectWithScrollBar{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRectWithScrollBar)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(TScrollBar,bar,DEF,$,$)\
ADDEND()
//=====+>>>>>TRectWithScrollBar
#include "QapGenStruct.inl"
//<<<<<+=====TRectWithScrollBar
public:
};

class TBookPageWithColoredRect:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithColoredRect)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(QapColor,color,DEF,$,$)\
ADDVAR(TRawRect,rect,DEF,$,$)\
ADDVAR(vector<TRectWithScrollBar>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithColoredRect
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithColoredRect
public:
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    qDev.BindTex(0,nullptr);
    qDev.SetColor(color);
    qDev.DrawQuad(con.pos+rect.pos,rect.get_size());
    rect.Render(con);
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      *(TDay20140605Book*)nullptr,
      con.pos,
      con.size,
      con.path,
      con.context
    };
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.rect.Render(con);
      context.pos=con.pos+ex.rect.pos;
      context.size=ex.rect.get_size();
      ex.bar.Render(context);
    }
  }
  void Update(t_context&con)
  {
    if(con.kb.Down[VK_SHIFT])if(false)
    {
      POINT p;
      GetCursorPos(&p);auto ff=GetDC(0);
      color=GetPixel(ff,p.x,p.y);
      ReleaseDC(0,ff);
      arr[0].bar.value=color.r;
      arr[1].bar.value=color.g;
      arr[2].bar.value=color.b;
      arr[3].bar.value=255;
    }
    if(!tick)
    {
      auto pad=16;
      auto h=16;
      auto bw=32;
      arr.resize(4);
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        ex.rect.fixed=true;
        ex.rect.w=256;
        ex.rect.h=16;
        ex.rect.pos.y=(2-i)*h*2-h;
        ex.rect.pos.x=-(bw+pad)/2;
        ex.bar.maxv=255;
        if(i==0)ex.bar.color=0xff0000ff;
        if(i==1)ex.bar.color=0xff00ff00;
        if(i==2)ex.bar.color=0xffff0000;
        if(i==3)ex.bar.color=0x80ffffff;
        ex.rect.rect_color=0xff000000;
        if(i==0)ex.bar.value=160;
        if(i==1)ex.bar.value=160;
        if(i==2)ex.bar.value=160;
        if(i==3)ex.bar.value=255;
      }
      rect.pos.x=128+(bw+pad)/2;
      rect.w=64;
      rect.h=h*2*4;
      rect.fixed=true;
      Caption="ColoredRect";
    }
    rect.Update(con);
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      *(TDay20140605Book*)nullptr,
      con.pos,
      con.size,
      con.path,
      con.context
    };
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      ex.rect.Update(con);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      context.pos=con.pos+ex.rect.pos;
      context.size=ex.rect.get_size();
      ex.bar.Update(context);
      if(i==0)color.b=ex.bar.value;
      if(i==1)color.g=ex.bar.value;
      if(i==2)color.r=ex.bar.value;
      if(i==3)color.a=ex.bar.value;
    }
    tick++;
  }
};

class TChatMsg{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TChatMsg)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,time,DEF,$,$)\
ADDVAR(string,msg,DEF,$,$)\
ADDEND()
//=====+>>>>>TChatMsg
#include "QapGenStruct.inl"
//<<<<<+=====TChatMsg
public:
};

class TBookPageWithChat:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithChat)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(TTextEditor,view,DEF,$,$)\
ADDVAR(TRawRect,editor_rect,DEF,$,$)\
ADDVAR(TRawRect,view_rect,DEF,$,$)\
ADDVAR(TScrollBar,bar,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,ls,SET,2,$)\
ADDVAR(vector<TChatMsg>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithChat
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithChat
public:
  void Render(t_context&con)
  {
    bar.Render(con);
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      *(TDay20140605Book*)nullptr,
      editor_rect.pos,
      editor_rect.get_size(),
      con.path,
      con.context
    };
    context.pos=con.pos;
    context.size=con.size;
    editor_rect.Render(context);
    view_rect.Render(context);
    context.pos=con.pos+editor_rect.pos;
    context.size=editor_rect.get_size();
    editor.Render(context);
    context.pos=con.pos+view_rect.pos;
    context.size=view_rect.get_size();
    view.Render(context);
  }
  void Update(t_context&con)
  {
    if(!tick||(con.kb.OnDown(VK_F4)&&con.is_hovered()))
    {
      if(!tick){bar.dir='y';bar.reverse=false;bar.value=5000;bar.maxv=10000;bar.color=0xff707070;bar.size=8;}
      if(Caption.empty())Caption="Chat";
      view.show_caret=false;
      view.readonly=true;
      view.border=8;
      view_rect.fixed=true;
      view_rect.line_size=ls;
      editor.border=8;
      editor_rect.fixed=true;
      editor_rect.line_size=ls;
      t_raw_rect_splitter_tool::update_rects(con,bar,view_rect,editor_rect,ls);
    }
    bar.Update(con);
    bool skip_update_content=false;
    if(con.is_hovered())if(bar.get_quad(con).contains(con.get_mpos()))
    {
      bool a=bar.down;
      bool ox=con.kb.OnDown('X');
      bool oy=con.kb.OnDown('Y');
      bool c=ox||oy;
      if(a&&c)
      {
        bar.dir='y'==bar.dir?'x':'y';
        bar.offset=vec2i_zero;
        skip_update_content=true;
      }
    }
    t_raw_rect_splitter_tool::update_rects(con,bar,view_rect,editor_rect,ls);
    if(skip_update_content)return;
    tick++;
    IBookPage::t_context context={
      con.Env,
      con.root,
      con.kb,
      con.qDev,
      con.head,
      con.book,
      editor_rect.pos,
      editor_rect.get_size(),
      con.path,
      con.context
    };
    context.pos=con.pos;
    context.size=con.size;
    editor_rect.Update(context);
    view_rect.Update(context);
    context.pos=con.pos+editor_rect.pos;
    context.size=editor_rect.get_size();
    editor.Update(context);
    context.pos=con.pos+view_rect.pos;
    context.size=view_rect.get_size();
    view.Update(context);
    if(con.kb.OnDown(VK_RETURN)&&con.is_hovered()&&con.kb.Down[VK_CONTROL])
    {
      auto&back=qap_add_back(arr);
      back.time=cur_date_str();
      back.msg=editor.text;
      editor.text.clear();
      auto&out=view.text;
      out.clear();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        //if(i)out+="\n";
        out+="----------["+ex.time+"]----------\n"+ex.msg;
      }
    }
  }
};

class TBookPageWithBook:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithBook)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TDay20140605Book,book,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithBook
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithBook
public:
  void Render(t_context&con)
  {
    auto hi=book.get_header_info(con.pos,con.size);
    auto context=con.fork();
    context.pos=hi.body_pos;
    context.size=hi.body_size;
    book.Render(context);
  }
  void Update(t_context&con)
  {
    auto hi=book.get_header_info(con.pos,con.size);
    auto context=con.fork();
    context.pos=hi.body_pos;
    context.size=hi.body_size;
    TOutDevScopeMemberID devscopeMember(con.context.dev,ProxySys$$::GET_FIELD_ID::book);
    book.Update(context);
  }
};

class TBookPageWithTwoBookWithSep:public IBookPage{
public:
#define DEF_PRO_FIELD_ID
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTwoBookWithSep)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(TDay20140605Book,bef,DEF,$,$)\
ADDVAR(TScrollBar,sep,DEF,$,$)\
ADDVAR(TDay20140605Book,aft,DEF,$,$)\
ADDVAR(TRawRect,bef_rect,DEF,$,$)\
ADDVAR(TRawRect,aft_rect,DEF,$,$)\
ADDVAR(int,ls,SET,2,$)\
ADDEND()
//=====+>>>>>TBookPageWithTwoBookWithSep
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTwoBookWithSep
public:
  static void RenderBook(t_context&con,TDay20140605Book&book)
  {
    auto hi=book.get_header_info(con.pos,con.size);
    auto context=con.fork();
    context.pos=hi.body_pos;
    context.size=hi.body_size;
    book.Render(context);
  }
  static void UpdateBook(t_context&con,TDay20140605Book&book)
  {
    auto hi=book.get_header_info(con.pos,con.size);
    auto context=con.fork();
    context.pos=hi.body_pos;
    context.size=hi.body_size;
    book.Update(context);
  }
  void Render(t_context&con)
  {
    bef_rect.Render(con);
    aft_rect.Render(con);
    //for bef
    {
      auto context=con.make_sub_context(bef_rect);
      RenderBook(context,bef);
    }
    //for aft
    {
      auto context=con.make_sub_context(aft_rect);
      RenderBook(context,aft);
    }
    sep.Render(con);
  }
  void Update(t_context&con)
  {
    if(need_init)
    {
      need_init=false;sep.dir='y';sep.reverse=false;sep.value=5000;sep.maxv=10000;sep.color=0xff707070;sep.size=8;
      bef_rect.fixed=true;
      bef_rect.line_size=ls;
      aft_rect.fixed=true;
      aft_rect.line_size=ls;
      t_raw_rect_splitter_tool::update_rects(con,sep,bef_rect,aft_rect,ls);
    }
    sep.Update(con);
    bool skip_update_content=false;
    if(con.is_hovered())if(sep.get_quad(con).contains(con.get_mpos()))
    {
      bool a=sep.down;
      bool ox=con.kb.OnDown('X');
      bool oy=con.kb.OnDown('Y');
      bool c=ox||oy;
      if(a&&c)
      {
        sep.dir='y'==sep.dir?'x':'y';
        sep.offset=vec2i_zero;
        skip_update_content=true;
      }
    }
    t_raw_rect_splitter_tool::update_rects(con,sep,bef_rect,aft_rect,ls);
    if(skip_update_content)return;
    //for bef
    {
      auto context=con.make_sub_context(bef_rect);
      TOutDevScopeMemberID devscopeMember(con.context.dev,ProxySys$$::GET_FIELD_ID::bef);
      UpdateBook(context,bef);
    }
    //for aft
    {
      auto context=con.make_sub_context(aft_rect);
      TOutDevScopeMemberID devscopeMember(con.context.dev,ProxySys$$::GET_FIELD_ID::aft);
      UpdateBook(context,aft);
    }
  }
};

bool qap_public_add_alias_from_line(IBookPage::t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars);
bool qap_public_MakeMenuForLineEx(IBookPage::t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs,vector<string>&buff_arr,TTextSelector&menu);

#include "IScriptAST.inl"

class TPageWithBranchLexV04:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPageWithBranchLexV04)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,need_init,SET,true,$)\
ADDVAR(bool,run,DEF,$,$)\
ADDVAR(bool,auto_run,DEF,$,$)\
ADDVAR(bool,wait_mbLeftUp,DEF,$,$)\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(vector<string>,buff_arr,DEF,$,$)\
ADDVAR(TRawRectAndMenuItems,menu,DEF,$,$)\
ADDEND()
//=====+>>>>>TPageWithBranchLexV04
#include "QapGenStruct.inl"
//<<<<<+=====TPageWithBranchLexV04
public:
  void Render(t_context&con)
  {
    editor.Render(con);
    //menu
    {
      menu.Render(con);
    }
  }
  void GetSize(t_context&con,vec2i&size)
  {
    if(!con.root.SysRes.FontObj)return;
    auto&Lines=menu.selector.Lines;
    if(Lines.empty())return;
    size=vec2i_zero;
    auto&font=con.root.SysRes.FontObj->Font;
    int dx=font.Info.Coords[0].x;
    int dy=font.Info.Coords[0].y;
    for(int i=0;i<Lines.size();i++)
    {
      auto&ex=Lines[i];
      int x=QapQ3Text::GetLength(font,ex+"..");
      size.x=std::max<int>(size.x,x);
      size.y+=dy;
    }
    size.y+=5;
  }
  bool SysKeyHandler(t_context&con)
  {
    if(!con.is_hovered())return false;
    auto&kb=con.kb;
    auto ctrl_down=kb.Down[VK_CONTROL];
    if(ctrl_down&&kb.OnDown(VK_RETURN))
    {
      run=true;
      return true;
    }
    if(kb.OnDown(mbLeft)&&menu.Enabled)
    {
      int gg=1;
      if(con.make_sub_context(menu.rect).is_hovered())
      {
        int gg=1;
        wait_mbLeftUp=true;
        return true;
      }
    }
    if(ctrl_down&&kb.OnDown(VK_BACK))
    {
      auto dpos=editor.text.rfind('.',editor.caret_pos);
      if(!dpos)return true;
      if(string::npos==dpos)return true;
      //dpos--:
      auto&text=editor.text; auto&p=editor.caret_pos;auto&s=editor.sel_caret_pos;
      text=text.substr(0,dpos)+text.substr(p);
      p=dpos;s=dpos;
      return true;
    }
    return false;
  }
  bool CheckMenuSelector(t_context&con)
  {
    if(!menu.selector.OnDown)return false;
    wait_mbLeftUp=true;
    if(!editor.caret_pos)return true;
    menu.selector.OnDown=false;
    auto selected=menu.selector.Lines[menu.selector.SelectId];
    auto arr=split(selected," = ");
    if(arr.empty())return true;
    auto name=split(arr[0]," ").front();
    editor.insert_string(con,name);
    return true;
  }
  vector<t_branch_head_ptr> get_ptrs(t_context&con)
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
    F("self",*this);
    #undef F
    return ptrs;
  }
  void UpdateMenu(t_context&con)
  {
    if(!con.is_hovered())return;
    auto&kb=con.kb;
    auto ctrl_down=kb.Down[VK_CONTROL];
    if(kb.OnDown(VK_OEM_PERIOD)||(ctrl_down&&kb.OnDown(mbRight)))
    {
      auto&text=editor.text; auto caret_pos=editor.caret_pos;
      if(caret_pos<=0)return;
      auto sol=text.rfind('\n',caret_pos-1);
      if(string::npos==sol){sol=0;}else{sol++;}
      auto line=text.substr(sol,caret_pos-sol);
      if(line.find("\"")!=line.find("="))return;
      line+="?";
      vector<TAutoPtr<void>> vars;
      auto ptrs=get_ptrs(con);
      auto lines=split(text,"\n");
      int car_pos_y=editor.car_pos.y;
      car_pos_y=std::max<int>(0,std::min<int>(car_pos_y,lines.size()));
      for(int i=0;i<car_pos_y;i++)
      {
        auto&ex=lines[i];
        bool flag=is_first_part_of(ex,"auto ");
        if(!flag)continue;
        bool ok=qap_public_add_alias_from_line(con,ex,ptrs,vars);
        if(!ok){QapDebugMsg("error when attempt to create alias:\n"+ex);return;}
      }
      bool ok=qap_public_MakeMenuForLineEx(con,line,ptrs,buff_arr,menu.selector);
      QapAssert(ok);
      if(ok)if(con.root.SysRes.FontObj)
      {
        auto cy=con.root.SysRes.FontObj->Font.Info[' '].y;
        auto tr=editor.make_tr(con);
        tr.loop(con.qDev,con.root.SysRes.FontObj->Font,false);
        auto caret_p=tr.caret_p-con.pos;
        menu.rect.pos=caret_p;
        vec2i size;
        GetSize(con,size);
        auto&mr=menu.rect;
        mr.w=size.x;
        mr.h=size.y;
        mr.pos.x+=size.x/2;
        mr.pos.y+=-(size.y/2+cy);
        menu.Enabled=true;
      }
      return;
    }
  }
  void Update(t_context&con)
  {
    if(need_init)
    {
      need_init=false;
      editor.border=8;
      menu.rect.draw_rect=false;
      //menu.rect.line_size=2;
      menu.rect.draw_quad=true;
      menu.rect.quad_color=QapColor(228,228,228);
      //menu.rect.rect_color=0xffe0e0e0;
    }
    menu.Update(con);
    bool in_menu=CheckMenuSelector(con);
    bool skh=SysKeyHandler(con);
    if(wait_mbLeftUp)wait_mbLeftUp=con.kb.Down[mbLeft];
    bool hard_condition=!skh&&!in_menu&&!wait_mbLeftUp;
    if((!menu.Enabled&&!run)||hard_condition)if(!skh)
    {
      auto prev_car_pos=editor.caret_pos;
      editor.Update(con);
      if(editor.caret_pos!=prev_car_pos)menu.Enabled=false;
    }
    UpdateMenu(con);
    if(run||auto_run)Run(con);
  }
  void Run(t_context&con)
  {
    auto ptrs=get_ptrs(con);
    run=false;
    auto&script=editor.text;
    TAutoPtr<IScriptAST> script_ast;
    if(!script_ast)
    {
      build_branch_script_ast(con.Env,script_ast,script);
      bool ok=script_ast;
      if(!ok)return;
    }
    auto*pScript=script_ast.get();;
    if(pScript)
    {
      auto ptrs=get_ptrs(con);
      auto res=pScript->exec(con,ptrs);
      return;
    }
  }
};

bool TDynStructFactory_set_not_sys_field_from_string(TType*p,const string&source,void*pValue)
{
  QapDebugMsg("no impl, but who care?");
  return true;
}

void build_tree(TD3DGameBoxBuilder&builder,IEnvRTTI&Env)
{
  builder.InitSysRes(Env);
  //pFontObj->SetToDef();
  //pFontObj->Run(Env,&pD3D9Prog->D9Dev);

  auto&Scene=builder.Scene;

  auto*zero=Scene.AddItem<TRenderNode>(Env);zero->Caption="zero";
  auto*one=Scene.AddItem<TRenderNode>(Env);one->Caption="one";
  //auto*nodeswitcher=one->AddItem<TBookPageNodeSwitcher>(Env);
  for(;;)
  {
    auto*pType=Env.FindTypeByName_is_ug_but_work("TProgramWithTreeScriptExecuter");
    QapAssert(pType);
    if(!pType)break;
    bool ok=pType->IsBasedOn(Sys$$<IRenderProgram>::GetRTTI(Env));
    QapAssert(ok);
    if(!ok)break;
    qap_add_back(one->Items).unsafe_build(pType);
    break;
  }
  //one->AddItem<TDay20140605BookV00>(Env)->NeedRemove=true;
  auto*book=one->AddItem<TDay20140605BookV00>(Env);
  book->rect.fixed=true;
  //nodeswitcher->Caption="NodeSwitcher";
  {
    auto*fb=book->book.AddItem<TBookPage20140605FullBook>(Env);
    fb->Caption="FullBook";
    fb->fixed=true;
  }
  book->book.AddItem<TPageWithPageAdder>(Env)->Caption=" + ";
  auto*qtdmainnode=Scene.AddItem<TRenderNode>(Env);
  qtdmainnode->Caption="[TPressEscapeToClose,[QapTreeDebugger,TGUI_PanelOwner]]";

  qtdmainnode->AddItem<TPressEscapeToClose>(Env);

  auto*qtdnode=qtdmainnode->AddItem<TRenderNode>(Env);
  qtdnode->Caption="[QapTreeDebugger,TGUI_PanelOwner]";
  //qtdnode->Enabled=false;

  auto*qtd=qtdnode->AddItem<QapTreeDebugger>(Env);

  auto*pPanelOwner=qtdnode->AddItem<TGUI_PanelOwner>(Env);
  pPanelOwner->Root.Rect.size=vec2i(360,625);
  pPanelOwner->Root.Anchors.pos.x=+1;
    
  auto*pPanelForQ3text=pPanelOwner->Root.AddItem();
  pPanelForQ3text->Rect.size=vec2i(64,64);
  pPanelForQ3text->Anchors.pos.y=-1;
  {
    auto*ptr=pPanelForQ3text->Content.build<TGUI_Content_Q3Text>(Env);
    ptr->Text=cur_date_str();
  }

  auto*pPanelForSelector=pPanelOwner->Root.AddItem();
  pPanelForSelector->Rect.size=vec2i(64,64);
  {
    auto*pSelector=pPanelForSelector->Content.build<QapTextSelectorV20140605>(Env);
    qtd->Selector.selector=pSelector;
    //pSelector->Lines=split("Foo|Bar|Baz","|");
    //pSelector->selector.Font=pFontObj;
    //pSelector->KeyVisor=pKVP;
  }

  //nodeswitcher->node=qtdnode;
}

bool QapPublicUberFullLoaderBinLastHopeMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp);
bool QapPublicUberFullLoaderBinLastHope(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);

static void builder_main(TD3DGameBoxBuilder&builder,IEnvRTTI&Env,const string&caption)
{
  QapClock def_clock;
  def_clock.Start();
  bool ok=QapPublicUberFullLoaderBin(Env,QapRawUberObject(builder),builder.get_file_name());
  def_clock.Stop();
  builder.ufli.DoReset();
  builder.ufli.def_ok=ok;
  builder.ufli.def_ms=def_clock.MS();
  if(!ok)
  {
    QapClock lasthope_clock;
    lasthope_clock.Start();
    ok=QapPublicUberFullLoaderBinLastHope(Env,QapRawUberObject(builder),builder.get_file_name());
    lasthope_clock.Stop();
    builder.ufli.hope_ok=true;
    builder.ufli.hope_ms=lasthope_clock.MS();
  }
  if(!ok)
  {
    builder.ufli.build_tree=true;
    build_tree(builder,Env);
    builder.init(Env,caption);
  }
  if(ok)
  {
    builder.win.NeedClose=false;
    builder.win.Init();
    builder.init_d3d();
    builder.win.Quad.setAsFullScreen();
    builder.win.WindowMode();
    UpdateWindow(builder.win.Form.WinPair.hWnd);
  }
  builder.loop(Env);
}
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
        F(TType)F(vec2d)F(TD3DGameBox)F(QapFontObject)F(QapTreeDebugger)F(T20140604)\
        F(TGUI_PanelOwner)F(QapTextSelectorV20140605)F(TGUI_Content_Q3Text)\
        F(TWeakPtrTest20140605)F(TDay20140605TestV00)F(TBookPage20140605FullBook)\
        F(TBookPageV00)F(TDay20140605BookV00)\
        F(TPressEscapeToClose)\
        F(TPageWithPageAdder)F(TBookPageWithQuit)F(TBookPageWithMultyBook)F(TProgramWithIBookPageAdopter)\
        F(TBookPageWithDisable)\
        F(TBookPageWithScrollBar)F(TBookPageWithColoredRect)F(TBookPageWithChat)F(TBookPageWithBook)\
        F(TBookPageWithTwoBookWithSep)\
        F(TPageWithBranchLexV04)
        //F(TBookPageWithMultyBook)F(TBookPageNodeSwitcher)F(TBookPageMultyNodeSwitcher)
        //F(TBookPageWithGame20140609)F(t_client_a)F(t_client_b)F(t_client_c)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
      TD3DGameBoxBuilder builder;
      builder_main(builder,Env,"2014.06.03");
      //starter(Env);
    }
    ThisCompileUnit(){
      //TMessageBoxCaller::Get()=MegaMessageBox;
    }
  };
  ThisCompileUnit ThisUnit;
}

#include "main2.inl"

void StartMemLeakTest()
{
  #ifdef _DEBUG
  int tmpDbgFlag;
  HANDLE hLogFile=CreateFile("VS_log.txt",GENERIC_WRITE,FILE_SHARE_WRITE,
    NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
  _CrtSetReportMode(_CRT_ASSERT,_CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW | _CRTDBG_MODE_DEBUG);
  _CrtSetReportMode(_CRT_WARN,_CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
  _CrtSetReportMode(_CRT_ERROR,_CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW | _CRTDBG_MODE_DEBUG);

  _CrtSetReportFile(_CRT_ASSERT,hLogFile);
  _CrtSetReportFile(_CRT_WARN,hLogFile);
  _CrtSetReportFile(_CRT_ERROR,hLogFile);

  tmpDbgFlag=_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
  tmpDbgFlag|=_CRTDBG_ALLOC_MEM_DF;
  tmpDbgFlag|=_CRTDBG_DELAY_FREE_MEM_DF;
  tmpDbgFlag|=_CRTDBG_LEAK_CHECK_DF;
  _CrtSetDbgFlag(tmpDbgFlag);
  //_CrtSetBreakAlloc(109);
  //int *pV=new int;
  #endif
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //StartMemLeakTest();
  //BlurTest();return 0;
  auto&comp_unit_man=TCompileUnitMan::get_man();
  string unit_name=comp_unit_man.arr[0]->get_filename();
  static GlobalEnv gEnv(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TStdAllocator MA;
  {
    TEnvRTTI Env;
    Env.Arr.reserve(1024);
    Env.Alloc=&MA;
    Env.OwnerEnv=&Env;
    TCompileUnitMan::reg_and_run_all(Env);
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}

//-----
static int somefunc_for_workaround_for_qapdev_drawquad()
{
  if(rand()%8==8)
  {
    QapDev dev;
    dev.DrawQuad(vec2d_zero,1,1,1);
    dev.DrawQuad(vec2d_zero,1,1);
    {TTypeStruct*p=nullptr;return (int)p->find_member_full("");}
    {TType*p2=(TType*)rand();return p2->IsBasedOn(p2);}
  }
  return 0;
}

static int workaround_for_qapdev_drawquad=somefunc_for_workaround_for_qapdev_drawquad();
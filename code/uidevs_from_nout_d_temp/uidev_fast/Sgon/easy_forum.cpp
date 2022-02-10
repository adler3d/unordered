#include "StdAfx.h"
//#include <utility>
/*
class TSimpleDebugger:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TSimpleDebugger)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TSimpleDebugger
#include "QapGenStruct.inl"
//<<<<<+=====TSimpleDebugger
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
  }
};*/


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

class TBookPageWithForum:public IBookPage{
public:
  class t_user{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_user)OWNER(TBookPageWithForum)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(string,email,DEF,$,$)\
  ADDVAR(string,password,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_user
  #include "QapGenStruct.inl"
  //<<<<<+=====t_user
  public:
  };
  class t_post{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_post)OWNER(TBookPageWithForum)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(string,time,DEF,$,$)\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_post
  #include "QapGenStruct.inl"
  //<<<<<+=====t_post
  public:
  };
  class t_topic{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_topic)OWNER(TBookPageWithForum)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_post>,posts,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_topic
  #include "QapGenStruct.inl"
  //<<<<<+=====t_topic
  public:
  };
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithForum)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(TTextEditor,view,DEF,$,$)\
ADDVAR(TRawRect,editor_rect,DEF,$,$)\
ADDVAR(TRawRect,view_rect,DEF,$,$)\
ADDVAR(TScrollBar,bar,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(vector<t_topic>,topics,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithForum
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithForum
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
  void UpdateRects(t_context&con,bool full)
  {
    auto bar_y=bar.get_quad(con).pos.y;
    auto CH=con.size.y;
    int ls=2;
    auto vs=-bar_y+CH/2-ls*2-bar.size/2;
    auto es=+bar_y+CH/2-ls*2-bar.size/2+CH%2;
    //int h=(con.size.y-ls*5)/2;
    int w=(con.size.x-ls*3);
    if(full)view.show_caret=false;
    if(full)view.readonly=true;
    if(full)view.border=8;
    if(full)view_rect.fixed=true;
    if(full)view_rect.line_size=ls;
    if(view_rect.fixed)
    {
      int ls=view_rect.line_size;
      view_rect.pos.x=0;
      view_rect.pos.y=bar_y+vs-vs/2+ls+bar.size/2;
      view_rect.w=w;
      view_rect.h=vs;
    }
    if(full)editor.border=8;
    if(full)editor_rect.fixed=true;
    if(full)editor_rect.line_size=ls;
    if(editor_rect.fixed)
    {
      int ls=editor_rect.line_size;
      editor_rect.pos.x=0;
      editor_rect.pos.y=bar_y-es/2-ls-bar.size/2;
      editor_rect.w=w;
      editor_rect.h=es;
    }
  }
  void Update(t_context&con)
  {
    if(!tick||(con.kb.OnDown(VK_F4)&&con.is_hovered()))
    {
      if(!tick){bar.dir='y';bar.reverse=false;bar.value=5000;bar.maxv=10000;bar.color=0xff707070;bar.size=8;}
      if(Caption.empty())Caption="Forum";
      UpdateRects(con,true);
    }
    bar.Update(con);
    UpdateRects(con,false);
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
    if(con.kb.OnDown(VK_RETURN)&&con.is_hovered()&&con.kb.Down[VK_CONTROL])
    {
      if(topics.empty())
      {
        qap_add_back(qap_add_back(topics).posts).body="Первая тема";
        //qap_add_back(topics[0].posts
      }
      {
        auto&back=qap_add_back(topics[0].posts);
        back.time=cur_date_str();
        //back.type="";
        back.name="Admin";
        back.body=editor.text;
      }
      editor.text.clear();
      auto&out=view.text;
      out.clear();
      out=get_first_15_posts_from_topic(0);
      return;
    }
    editor.Update(context);
    context.pos=con.pos+view_rect.pos;
    context.size=view_rect.get_size();
    view.Update(context);
    int gg=1;
  }
  struct t_message{
    vector<string> head;
    vector<string> body;
  };
  static string line2out(const string&s){return "| "+s+" |";}
  static string body2out(const string&s)
  {
    auto inp=StrReplace(s,"\r","");
    auto out=StrReplace(inp,"\n"," |\n| ");
    return line2out(out);
  }
  static vector<string> body2lines(const string&s)
  {
    auto inp=StrReplace(s,"\r","");
    return split(inp,"\n");
    //auto out=StrReplace(inp,"\n"," |\n| ");
    //return line2out(out);
  }
  static int get_post_head_size(const vector<string>&arr){
    return join(arr," | ").size();
  };
  static int get_max_x_of_body(const vector<string>&arr){
    int n=-1;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(int(ex.size())>n)n=ex.size();
    }
    return n;
  }
  static int get_body_and_head_size(const vector<string>&head,const vector<string>&body)
  {
    auto h=get_post_head_size(head);
    auto b=get_max_x_of_body(body);
    return std::max(h,b);
  }
  static int get_w_of(const t_message&msg)
  {
    return get_body_and_head_size(msg.head,msg.body);
  }
  static void sync_body_and_head_size(vector<string>&head,vector<string>&body,int w)
  {
    auto h=get_post_head_size(head);
    if(h<w)
    {
      head[1].resize(w-h,'-');
    }
    for(int i=0;i<body.size();i++)
    {
      auto&ex=body[i];
      if(ex.size()==w)continue;
      QapAssert(ex.size()<w);
      string spaces;
      spaces.resize(w-ex.size(),' ');
      ex+=spaces;
    }
  }
  static vector<string> message2lines(t_message&msg,int w)
  {
    sync_body_and_head_size(msg.head,msg.body,w);
    return make_lines(msg.head,msg.body);
  }
  static vector<string> make_lines(const vector<string>&head,const vector<string>&body)
  {
    vector<string> out;
    string head_line=line2out(join(head," | "));
    string sep_line=string(head_line.size(),'-');
    qap_add_back(out)=sep_line;
    qap_add_back(out)=head_line;
    qap_add_back(out)=sep_line;
    for(int i=0;i<body.size();i++)qap_add_back(out)=line2out(body[i]);
    qap_add_back(out)=sep_line;
    return out;
  }
  string get_first_15_posts_from_topic(int topic)
  {
    QapAssert(topic>=0);
    QapAssert(topic<topics.size());
    if(topic>=topics.size())return "";
    if(topic<0)return "";
    auto&t=topics[topic];
    auto&p=t.posts;
    vector<string> lines;
    vector<t_message> arr;
    for(int i=1;i<p.size();i++)
    {
      //if(i>15)break;
      auto&ex=p[i];
      vector<string> line;
      line.push_back(ex.name);
      line.push_back("");
      line.push_back("#"+IToS(i));
      line.push_back(ex.time);
      auto body=body2lines(ex.body);
      arr.push_back({line,body});
      continue;
    }
    int w=-1;
    for(int i=0;i<arr.size();i++)w=std::max<int>(w,get_w_of(arr[i]));
    for(int i=0;i<arr.size();i++){QapToolsVectorEx(lines)+=message2lines(arr[i],w);qap_add_back(lines);}
    return join(lines,"\n");
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
        F(TType)F(TBookPageWithForum)
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
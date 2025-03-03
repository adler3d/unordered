class TGUI_Content_Q3Text:public IGUI_Content{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_Content_Q3Text)PARENT(IGUI_Content)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Text,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_Content_Q3Text
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_Content_Q3Text
public:
  void Render(TRenderContext&Context)
  {
    if(!Context.context.root.SysRes.FontObj)return;
    auto&qDev=Context.qDev;
    auto&Font=Context.context.root.SysRes.FontObj->Font;
    auto&FontTex=Context.context.root.SysRes.FontObj->Tex;
    FontTex.Bind();
    qDev.SetColor(0xff202020);
    vec2i dv=-Context.size/2;
    dv.y+=Context.size.y;
    vec2i pos=Context.pos+dv;
    vec2i mpos=Context.mpos+dv;
    mpos.x=Context.mpos.x+Context.size.x/2;
    int char_id=-1;
    string text=Text;
    if((mpos.y>0)&&(mpos.y<Font.Info[0].y))
    {
      if((mpos.x>0)&&(mpos.x<QapQ3Text::GetLength(Font,Text)))
      {
        char_id=mpos.x/Font.Info[0].x;
        text=text.substr(0,char_id)+"^E"+CToS(text[char_id])+"^0"+text.substr(char_id+1);
      }
    }
    QapQ3Text::DrawQapText(&qDev,Font,int(pos.x),int(pos.y),text);
  }
  void GetSize(IRenderProgram::t_context&context,vec2i&size)
  {
    size=vec2i_zero;
    if(!context.root.SysRes.FontObj)return;
    auto&font=context.root.SysRes.FontObj->Font;
    size.x=QapQ3Text::GetLength(font,Text);
    size.y=font.Info[0].y;
  }
};

class TGUI_Panel{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_Panel)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TGUIRect,Current,SET,TGUIRect(vec2i(0,0),vec2i(256,128)),$)\
ADDVAR(TGUIRect,Rect,SET,TGUIRect(vec2i(0,0),vec2i(256,128)),$)\
ADDVAR(TGUIRect,Anchors,SET,TGUIRect(vec2i(0,0),vec2i(0,0)),$);\
ADDVAR(TAutoPtr<IGUI_Content>,Content,DEF,$,$);\
ADDVAR(vector<TGUI_Panel>,Items,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_Panel
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_Panel
public:
  static void SysHasSelf();
public:
  struct IVisitor
  {
    virtual void Do(TGUI_Panel*p){}
  };
  void Use(IVisitor&A){A.Do(this);}
  TGUI_Panel*AddItem()
  {
    Items.push_back(std::move(TGUI_Panel()));
    return &Items.back();
  }
};

class TGUI_PanelOwner:public IRenderProgram{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TGUI_PanelOwner)PARENT(IRenderProgram)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TGUI_Panel,Root,DEF,$,$)\
ADDEND()
//=====+>>>>>TGUI_PanelOwner
#include "QapGenStruct.inl"
//<<<<<+=====TGUI_PanelOwner
public:
  typedef IGUI_Content::TRenderContext TRenderContext;
  typedef IGUI_Content::TUpdateContext TUpdateContext;
  typedef TGUI_Panel::IVisitor IVisitor;
public:
  struct TRenderVisitor:public IVisitor
  {
    TRenderContext&Context;
    TRenderVisitor(TRenderContext&Context):Context(Context){}
    void Do(TGUI_Panel*p)
    {
      auto&it=*p;
      //
      auto&qDev=Context.qDev;
      qDev.BindTex(0,nullptr);
      static QapColor color=0x20202020;
      qDev.SetColor(color);
      //
      vec2i cs=Context.size;
      vec2i&pos=it.Current.pos;
      vec2i&size=it.Current.size;
      {
        auto p=Context.pos+pos;
        qDev.DrawQuad(p.x,p.y,size.x,size.y,0);
      }
      if(!it.Items.empty()||it.Content)
      {
        TRenderContext Scope={
          Context.pos+pos,
          size,
          Context.mpos-pos,
          Context.context,
          qDev
        };
        if(it.Content)it.Content->Render(Scope);
        auto&arr=it.Items;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          TRenderVisitor next(Scope);
          ex.Use(next);
        }
      }
    }
  };
  struct TUpdateVisitor:public IVisitor
  {
    TUpdateContext&Context;
    TUpdateVisitor(TUpdateContext&Context):Context(Context){}
    void Do(TGUI_Panel*p)
    {
      auto&it=*p;
      vec2i cs=Context.size;       
      vec2i&pos=it.Current.pos;
      vec2i&size=it.Current.size;
      const vec2i&rp=it.Rect.pos;
      const vec2i&rs=it.Rect.size;
      const vec2i&ap=it.Anchors.pos;
      const vec2i&as=it.Anchors.size;
      size=rs;
      if(it.Content)it.Content->GetSize(Context.context,size);
      size.x=Clamp<int>(size.x,0,cs.x);
      size.y=Clamp<int>(size.y,0,cs.y);
      //Clamp();
      if(as.x>0)size.x=cs.x;
      if(as.y>0)size.y=cs.y;
      vec2i s=(cs-size)/2;
      pos=rp;
      if(rp.x>+s.x||ap.x>0){pos.x=+s.x;}
      if(rp.x<-s.x||ap.x<0){pos.x=-s.x;}
      if(rp.y>+s.y||ap.y>0){pos.y=+s.y;}
      if(rp.y<-s.y||ap.y<0){pos.y=-s.y;}
      if(!it.Items.empty()||it.Content)
      {
        TUpdateContext Scope={
          Context.pos+pos,
          size,
          Context.mpos-pos,
          Context.zDelta,
          Context.context,
          Context.keyboard
        };
        if(it.Content)it.Content->Update(Scope);
        auto&arr=it.Items;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          TUpdateVisitor next(Scope);
          ex.Use(next);
        }
      }
    }
  };
  void Render(t_context&con)
  {
    vec2i pos=vec2i(0,0);
    vec2i size=con.root.win.GetClientSize();
    vec2i mpos=con.root.win.GetMousePos();
    TRenderContext Context={pos,size,mpos,con,con.root.qDev};
    TRenderVisitor V(Context);
    Root.Use(V);
  }
  void Update(t_context&con)
  {
    vec2i pos=vec2i(0,0);
    vec2i size=con.root.win.GetClientSize();
    vec2i mpos=con.root.win.GetMousePos();
    int zDelta=con.root.win.zDelta;
    QapKeyboard&keyboard=con.root.win.Keyboard;
    IGUI_Content::TUpdateContext Context={pos,size,mpos,zDelta,con,keyboard};
    TUpdateVisitor V(Context);
    Root.Use(V);
  }
};
#include "StdAfx.h"

class TTextEditorFixed{
public:
  class t_log_item{
  public:
  #define DEF_PRO_AUTO_COPY()
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_log_item)OWNER(TTextEditorFixed)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(bool,need_remove,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(int,n,DEF,$,$)\
  ADDVAR(real,rt,DEF,$,$)\
  ADDVAR(real,pde,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_log_item
  #include "QapGenStruct.inl"
  //<<<<<+=====t_log_item
  public:
  };
  class TProfiler{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProfiler)OWNER(TTextEditorFixed)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(bool,need_reset,DEF,$,$)\
  ADDVAR(int,n,DEF,$,$)\
  ADDVAR(real,total_rt,DEF,$,$)\
  ADDVAR(real,rt,DEF,$,$)\
  ADDVAR(real,total_pde,DEF,$,$)\
  ADDVAR(real,pde,DEF,$,$)\
  ADDVAR(bool,add_to_log,DEF,$,$)\
  ADDVAR(vector<t_log_item>,logs,DEF,$,$)\
  ADDEND()
  //=====+>>>>>TProfiler
  #include "QapGenStruct.inl"
  //<<<<<+=====TProfiler
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(TProfiler)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTextEditorFixed)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,text,DEF,$,$)\
ADDVAR(string,fn,SET,"test_new3.txt",$)\
ADDVAR(bool,need_load_text,SET,true,$)\
ADDVAR(int,border,SET,5,$)\
ADDVAR(int,caret_pos,DEF,$,$)\
ADDVAR(vec2i,car_pos,DEF,$,$)\
ADDVAR(int,sel_caret_pos,DEF,$,$)\
ADDVAR(int,tick,DEF,$,$)\
ADDVAR(int,max_tick,SET,32,$)\
ADDVAR(bool,mouse_on_down_handled,DEF,$,$)\
ADDVAR(bool,mouse_on_down_handled_for_select_word,DEF,$,$)\
ADDVAR(bool,caret_debug,DEF,$,$)\
ADDVAR(bool,show_caret,SET,true,$)\
ADDVAR(bool,readonly,DEF,$,$)\
ADDVAR(vec2i,dc_mpos,DEF,$,$)\
ADDVAR(int,dc_tick,DEF,$,$)\
ADDVAR(int,dc_max_tick,SET,32,$)\
ADDVAR(bool,is_double_click,DEF,$,$)\
ADDVAR(int,scroll_y,DEF,$,$)\
ADDVAR(int,scroll_lines,SET,3,$)\
ADDVAR(string,buffer,DEF,$,$)\
ADDVAR(bool,log_enabled,DEF,$,$)\
ADDVAR(int,log_tick,DEF,$,$)\
ADDVAR(bool,use_new_loop,SET,true,$)\
ADDVAR(vector<string>,logs,DEF,$,$)\
ADDVAR(TProfiler,profiler,DEF,$,$)\
ADDEND()
//=====+>>>>>TTextEditorFixed
#include "QapGenStruct.inl"
//<<<<<+=====TTextEditorFixed
public:
  typedef IBookPage::t_context t_context;
public:
  bool is_selected(){return caret_pos!=sel_caret_pos;}
public:
  struct t_text_renderer
  {
    const int scroll_y;
    const int scroll_lines;
    const vec2i con_pos;
    const vec2i con_size;
    const int border;
    const string&text;
    const int caret_pos;
    const int sel_caret_pos;
    bool caret_detected;
    bool sel_car_detected;
    vec2i caret_p;
    vec2i sel_car_p;
    int x;
    int y;
    int dx;
    int dy;
    int cx;
    int cy;
    int max_x;
    int caret;
    vec2i pos;
    vec2i mpos;
    int mpos_id;
    bool need_find_mpos_id;
    bool use_new_loop;
    //vector<string> lines;
    vector<QapText::t_draw_call> sel_calls;
    void next_line(){y+=dy?dy:-cy;dy=0;x=pos.x;}
    void operator()(unsigned char UC,const vec2i&p,const vec2i&size)
    {
      if(caret==text.size()){
        int wtf=1;
        return;
      }
      auto uc=(byte)text[caret];
      QapAssert(uc==UC);
      if(caret==caret_pos){caret_p=p;caret_detected=true;}
      if(caret==sel_caret_pos){sel_car_p=p;sel_car_detected=true;}
      if(caret_detected!=sel_car_detected)
      {
        QapText::add_draw_call(sel_calls,UC,p,vec2i(size.x,-size.y));
      }
      //
      find_mpos(uc=='\n',p,size);
      caret++;
    }
    void find_mpos(bool end_of_line,const vec2i&p,const vec2i&size)
    {
      if(need_find_mpos_id)
      {
        auto mp=mpos+con_pos;
        auto b=p+vec2i(size.x,-size.y);
        if(end_of_line)b.x=con_pos.x+con_size.x;
        if(CD_Rect2Point(p,b,mp))
        {
          if(p.x!=mp.x)if(p.y!=mp.y)if(b.x!=mp.x)if(b.y!=mp.y)QapAssert(mpos_id==-1);
          mpos_id=caret;
          bool our_side=end_of_line||(mp.x*2<(p+b).x);
          if(!our_side)mpos_id++;
        }
      }
    }
    void loop_ex(QapFont&font)
    {
      need_find_mpos_id=true;
      QapDev&qDev=*(QapDev*)nullptr;
      loop(qDev,font,false);
    }
    struct t_dev{
      t_text_renderer&owner;
      const string&text;
      int offset;
      int size;
      vector<vec2i> stack;
      void push(){stack.push_back({offset,size});}
      void pop(){auto&back=stack.back();offset=back.x;size=back.y;stack.pop_back();}
      bool go_end(char c)
      {
        QapAssert(size>=0);
        QapAssert(offset>=0);
        int n=std::min<int>(offset+size,text.size());
        for(int i=offset;i<n;i++)
        {
          if(text[i]==c)
          {
            size=i-offset;
            return true;
          }
        }
        size=n-offset;
        return false;
      }
      static int find_not(const string&text,int offset,char c)
      {
        int n=text.size();
        for(int i=offset;i<n;i++)
        {
          if(text[i]!=c)return i-offset;
        }
        return -1;
      }
    };
    bool is_end_of_context()const
    {
      bool end_of_context=y<con_pos.y-con_size.y+border;
      bool is_selected=sel_caret_pos!=caret_pos;
      if(!is_selected)if(end_of_context)return true;
      if(is_selected)
      {
        if(caret_detected!=sel_car_detected)
        {
          int gg=1;
        }
        if(caret_detected&&sel_car_detected)if(end_of_context)
        {
          int gg=1;
          return true;
        }
      }
      return false;
    }
    void handle_line(t_dev&dev,QapDev&qDev,QapFont&font,bool need_draw)
    {
      auto&func=*this;
      for(bool ok=true;ok;)
      {
        int word_size=0;
        dev.push();
        int bef_x=x;
        int bef_y=y;
        {
          ok=dev.go_end(' ');
          word_size=dev.size;
          string this_word_is=text.substr(dev.offset,dev.size);
          auto&ex=this_word_is;
          //if(ex.empty()){dy=std::min(dy,-cy);continue;}
          vec2i size;
          int cur_dy=0;
          {
            dx=QapText::GetLength(font,ex);
            size=vec2i(dx,cy);
            cur_dy=-size.y;
          }
          if(x+dx>max_x)
          {
            if(need_find_mpos_id)
            {
              int gg=1;
            }
            next_line();
          }
          dy=std::min(dy,cur_dy);
          if(is_end_of_context()){dev.pop();break;}
          if(!need_draw)QapText::PreDrawEx(font,int(x),int(y),ex,func);
          if(need_draw)if(y<con_pos.y+con_size.y)QapText::Draw(qDev,font,int(x),int(y),ex);
          x+=dx;
          int gg=1;
        }
        dev.pop();
        dev.offset+=word_size;
        dev.size-=word_size;
        auto e=t_dev::find_not(text,dev.offset,' ');
        if(e<0)
        {
          e=dev.size;/*QapDebugMsg("no way");*/
        }
        if(e==5)if(need_find_mpos_id)
        {
          int gg=1;
        }
        if(y!=bef_y)
        {
          int gg=1;
          if(need_find_mpos_id)
          {
            gg=2;
          }
        }
        for(int i=0;i<e;i++)
        {
          if(!need_draw)
          {
            auto p=vec2i(x,y);
            auto s=vec2i(cx,cy);
            if(e==i+1)//if(need_find_mpos_id)//if(e==5)
            {
              int the_end=1;
              dev.push();
              dev.offset+=e;
              dev.size-=e;
              dev.go_end(' ');
              string this_word_is=text.substr(dev.offset,dev.size);
              auto&ex=this_word_is;
              int dx=QapText::GetLength(font,ex);
              if(x+cx+dx>max_x)
              {
                int gg=1;
                s.x=max_x-x;
              }
              dev.pop();
            }
            func(' ',p,s);
          }
          x+=cx;
        }
        if(is_end_of_context())break;
        string this_sep_is=text.substr(dev.offset,e);
        dev.offset+=e;
        dev.size-=e;
      }
    }
    void handle_text(t_dev&dev,QapDev&qDev,QapFont&font,bool need_draw)
    {
      auto&func=*this;
      for(bool ok=true;ok;)
      {
        int cur_size=dev.size;
        int line_size=0;
        dev.push();
        {
          ok=dev.go_end('\n');
          line_size=dev.size;
          handle_line(dev,qDev,font,need_draw);
          if(is_end_of_context()){dev.pop();break;}
        }
        dev.pop();
        dev.offset+=line_size;
        dev.size-=line_size;
        auto e=t_dev::find_not(text,dev.offset,'\n');
        if(e<0)
        {
          e=dev.size;/*QapDebugMsg("no way");*/
        }
        for(int i=0;i<e;i++)
        {
          if(!need_draw)func('\n',vec2i(x,y),vec2i(cx,cy));
          next_line();dx=cx;
        }
        //string this_sep_is=text.substr(dev.offset,e);
        dev.offset+=e;
        dev.size-=e;
      }
      int hm=1;
      {
        find_mpos(true,vec2i(x,y),vec2i(cx,cy));
        if(need_find_mpos_id)
        {
          if(mpos_id==-1)
          {
            if(mpos.y-cy<y-con_pos.y)
            {
              mpos_id=caret;
            }
          }
        }
        if(!need_draw)if(text.size()==caret_pos){caret_p=vec2i(x,y);caret_detected=true;}
        if(!need_draw)if(text.size()==sel_caret_pos){sel_car_p=vec2i(x,y);sel_car_detected=true;}
        int gg=1;
      }
    }
    void new_loop(QapDev&qDev,QapFont&font,bool need_draw)
    {
      if(need_find_mpos_id)QapAssert(!need_draw);
      mpos_id=-1;
      auto&func=*this;
      string raw=StrReplace(text,"\r","");
      {
        pos=con_pos+vec2i(-con_size.x,+con_size.y)+vec2i(+1,-1)*border;
        max_x=con_pos.x+con_size.x-border;
        if(!need_draw)caret_detected=false;
        if(!need_draw)sel_car_detected=false;
        cx=+font.Info.Coords[0].x;
        cy=font.Info.Coords[0].y;
        x=pos.x;
        y=pos.y-(scroll_y*cy*scroll_lines);
        dx=cx;
        dy=-cy;
        caret=0;
      }
      t_dev dev={*this,raw,0,text.size()};
      dev.push();
      handle_text(dev,qDev,font,need_draw);
      dev.pop();
    }
    void loop(QapDev&qDev,QapFont&font,bool need_draw)
    {
      if(use_new_loop){new_loop(qDev,font,need_draw);return;}
      if(need_find_mpos_id)QapAssert(!need_draw);
      mpos_id=-1;
      auto&func=*this;
      string raw=StrReplace(text,"\r","");
      auto lines=split(raw,"\n");
      pos=con_pos+vec2i(-con_size.x,+con_size.y)+vec2i(+1,-1)*border;
      max_x=con_pos.x+con_size.x-border;
      if(!need_draw)caret_detected=false;
      if(!need_draw)sel_car_detected=false;
      cx=+font.Info.Coords[0].x;
      cy=font.Info.Coords[0].y;
      x=pos.x;
      y=pos.y-(scroll_y*cy*scroll_lines);
      dx=cx;
      dy=-cy;
      caret=0;
      auto is_end_of_context=[&]()->bool
      {
        bool end_of_context=y<con_pos.y-con_size.y+border;
        bool is_selected=sel_caret_pos!=caret_pos;
        if(!is_selected)if(end_of_context)return true;
        if(is_selected)
        {
          if(caret_detected!=sel_car_detected)
          {
            int gg=1;
          }
          if(caret_detected&&sel_car_detected)if(end_of_context)return true;
        }
        return false;
      };
      for(int i=0;i<lines.size();i++)
      {
        auto&line=lines[i];
        auto arr=split(line," ");
        for(int j=0;j<arr.size();j++)
        {
          auto&ex=arr[j];
          if(j)
          {
            if(!need_draw)func(' ',vec2i(x,y),vec2i(cx,cy));
            x+=cx;
          }
          //if(ex.empty()){dy=std::min(dy,-cy);continue;}
          vec2i size;
          int cur_dy=0;
          {
            dx=QapText::GetLength(font,ex);
            size=vec2i(dx,cy);
            cur_dy=-size.y;
          }
          if(x+dx>max_x){
            next_line();
          }
          dy=std::min(dy,cur_dy);
          if(is_end_of_context())break;
          if(!need_draw)QapText::PreDrawEx(font,int(x),int(y),ex,func);
          if(need_draw)if(y<con_pos.y+con_size.y)QapText::Draw(qDev,font,int(x),int(y),ex);
          x+=dx;
        }
        if(is_end_of_context())break;
        if(i+1!=lines.size())
        {
          if(!need_draw)func('\n',vec2i(x,y),vec2i(cx,cy));
          next_line();dx=cx;
        }
      }
      find_mpos(true,vec2i(x,y),vec2i(cx,cy));
      if(need_find_mpos_id)
      {
        if(mpos_id==-1)
        {
          if(mpos.y-cy<y-con_pos.y)
          {
            mpos_id=caret;
          }
        }
      }
      if(!need_draw)if(text.size()==caret_pos){caret_p=vec2i(x,y);caret_detected=true;}
      if(!need_draw)if(text.size()==sel_caret_pos){sel_car_p=vec2i(x,y);sel_car_detected=true;}
      int gg=1;
    }
  };
public:
  t_text_renderer make_tr(t_context&con)
  {
    t_text_renderer tr={
      scroll_y,scroll_lines,
      con.pos,con.size/2,
      border,text,
      caret_pos,sel_caret_pos
    };
    tr.use_new_loop=use_new_loop;
    return std::move(tr);
  }
  void Render(t_context&con)
  {
    auto&qDev=con.qDev;
    if(!con.root.SysRes.FontObj)return;
    auto*pfont_obj=con.root.SysRes.FontObj.get();
    auto&font=pfont_obj->Font;
    auto&tex=pfont_obj->Tex;
    QapClock clock;clock.Start();
    if(false)
    {
      qDev.BindTex(0,nullptr);
      qDev.SetColor(0xffffffff);
      qDev.DrawQuad(con.pos,con.size);
    }
    auto tr=make_tr(con);
    //
    auto active_size=con.size-vec2i(border,border)*0;
    //
    auto&caret_p=tr.caret_p;
    auto&sel_car_p=tr.sel_car_p;
    auto&caret_detected=tr.caret_detected;
    auto&sel_car_detected=tr.sel_car_detected;
    {
      QapClock sub_clock;sub_clock.Start();
      //pass for PreDrawEx
      tr.loop(qDev,font,false);
      //
      sub_clock.Stop();
      profiler.total_pde+=sub_clock.MS();
      profiler.pde=profiler.total_pde/real(profiler.n+1);
    }
    //
    if(show_caret&&sel_car_detected&&is_selected())
    {
      QapDev::BatchScope Scope(qDev);
      qDev.BindTex(0,nullptr);
      qDev.SetColor(0x99a0a0ff);
      if(true)
      {
        auto&arr=tr.sel_calls;
        for(int i=0;i<arr.size();i++)
        {
          auto&ex=arr[i];
          if(!PointInQuad(ex.pos,con.pos,active_size))continue;
          qDev.DrawQuadWithHalfPixelOffset(ex.pos+ex.size/2,ex.size);
        }
      }
    }
    //pass for DrawEx
    {
      QapDev::BatchScope Scope(qDev);
      qDev.BindTex(0,&tex);
      qDev.SetColor(0xff000000);
      tr.loop(qDev,font,true);
    }
    //
    qDev.BindTex(0,nullptr);
    //
    if(show_caret)if(caret_debug||(tick<=max_tick/2))if(caret_detected)if(PointInQuad(caret_p,con.pos,active_size))
    {
      QapDev::BatchScope Scope(qDev);
      qDev.SetColor(0xff000000);
      qDev.DrawQuadWithHalfPixelOffset(caret_p.x+1,caret_p.y-tr.cy/2,1,tr.cy);
    }
    //
    clock.Stop();
    if(profiler.need_reset)profiler.DoReset();
    if(profiler.add_to_log)
    {
      auto logs=profiler.logs;
      auto&back=qap_add_back(logs);
      back.n=profiler.n;
      back.rt=profiler.rt;
      back.pde=profiler.pde;
      profiler.DoReset();
      profiler.logs=logs;
    }
    QapCleanIf(profiler.logs,[](t_log_item&ex){return ex.need_remove;});
    profiler.total_rt+=clock.MS();
    profiler.rt=profiler.total_rt/real(profiler.n+1);
    profiler.n++;
  }
  static vec2i get_caret_pos(const string&text,int caret_pos)
  {
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    int c=0;int sol=0;
    for(int i=0;i<caret_pos;i++){
      if(text[i]=='\n'){sol=i+1;c++;}
    }
    return vec2i(caret_pos-sol,c);
  }
  static bool is_allowed_char(char c)
  {
    static const string allowed=gen_dips("azAZàÿÀß09")+"¸"+" _=+-*/\\~!@#$%^&|()[]{}`'\"?.,<>;:";
    return allowed.find(c)!=string::npos;
  }
  static bool is_char_from_word(char c)
  {
    static const string char_from_word=gen_dips("azAZàÿÀß09")+"¸"+"_@$";
    return char_from_word.find(c)!=string::npos;
  }
  static size_t find_end_of_word(const string&text,size_t offset)
  {
    QapAssert(offset<text.size());
    for(auto i=offset;i<text.size();i++)
    {
      if(!is_char_from_word(text[i]))return i;
    }
    return string::npos;
  }
  static size_t rfind_begin_of_word(const string&text,size_t offset)
  {
    QapAssert(offset<text.size());
    for(auto i=offset;;)
    {
      if(!is_char_from_word(text[i]))return i;
      if(!i)break;
      i--;
    }
    return string::npos;
  }
  void UpdateCarPos(t_context&con)
  {
    auto&kb=con.kb;
    bool ctrl=kb.Down[VK_CONTROL];
    bool shift=kb.Down[VK_SHIFT];
    bool mod=con.kb.OnDown(mbLeft);
    bool md=con.kb.Down[mbLeft];
    bool need_select=false;
    if(shift)
    {
      need_select=true;
    }
    if(mod)
    {
      mouse_on_down_handled=true;//sel_caret_pos!=caret_pos;
    }
    if(md&&!mod&&mouse_on_down_handled)
    {
      need_select=true;
    }
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    sel_caret_pos=Clamp<int>(sel_caret_pos,0,text.size());
    car_pos=get_caret_pos(text,caret_pos);
    if(!need_select||(kb.News&&is_allowed_char(kb.LastChar)))
    {
      sel_caret_pos=caret_pos;log("sel_caret_pos=caret_pos");
    }
  }
  void insert_string(t_context&con,const string&content)
  {
    QapAssert(!is_selected())
    {
      text=text.substr(0,caret_pos)+content+text.substr(caret_pos);
    }
    caret_pos+=content.size();
    tick=0;UpdateCarPos(con);
  }
  void UpdateText(t_context&con)
  {
    auto&kb=con.kb;
    bool ctrl=kb.Down[VK_CONTROL];
    bool shift=kb.Down[VK_SHIFT];
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    sel_caret_pos=Clamp<int>(sel_caret_pos,0,text.size());
    auto copy_to_buffer=[&]()
    {
      if(!is_selected())return;
      int a=std::min(caret_pos,sel_caret_pos);
      int b=std::max(caret_pos,sel_caret_pos);
      a=Clamp<int>(a,0,text.size());
      b=Clamp<int>(b,0,text.size());
      QapAssert(b-a>0);
      buffer=text.substr(a,b-a);
    };
    auto remove_selected_text=[&]()
    {
      if(!is_selected())return;
      int a=std::min(caret_pos,sel_caret_pos);
      int b=std::max(caret_pos,sel_caret_pos);
      a=Clamp<int>(a,0,text.size());
      b=Clamp<int>(b,0,text.size());
      text=text.substr(0,a)+text.substr(b);
      caret_pos=a;
      sel_caret_pos=a;
    };
    if(kb.OnDown('C')&&ctrl)copy_to_buffer();
    if(kb.OnDown('X')&&ctrl)if(!readonly)
    {
      copy_to_buffer();
      remove_selected_text();
    }
    if(kb.OnDown('V')&&ctrl)if(!readonly)
    {
      remove_selected_text();
      insert_string(con,buffer);
    }
    if(kb.OnDown('A')&&ctrl)
    {
      sel_caret_pos=0;
      caret_pos=text.size();
    }
    if(kb.OnDown('S')&&ctrl)if(!readonly)
    {
      file_put_contents(fn,text);
    }
    if(kb.OnDown('L')&&ctrl)
    {
      text=StrReplace(file_get_contents(fn),"\r","");
    }
    if(!text.empty())
    {
      if(kb.OnDown(VK_END))
      {
        if(ctrl)caret_pos=text.size();
        if(!ctrl)
        {
          int eol=text.find("\n",caret_pos);
          if(string::npos!=eol)caret_pos=eol;
          if(string::npos==eol)caret_pos=text.size();
        }
        tick=0;UpdateCarPos(con);
      }
      if(kb.OnDown(VK_HOME))
      {
        if(ctrl){caret_pos=0;scroll_y=0;}
        if(!ctrl)if(caret_pos)
        {
          int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
          if(string::npos!=sol)caret_pos=sol+1;
          if(string::npos==sol)caret_pos=0;
        }
        tick=0;UpdateCarPos(con);
      }
    }
    caret_pos=Clamp<int>(caret_pos,0,text.size());
    if(kb.OnDown(VK_DELETE))if(!readonly)
    {
      bool selected=is_selected();
      remove_selected_text();
      if(!selected)
      {
        int offset=std::min<int>(caret_pos+1,text.size());
        text=text.substr(0,caret_pos)+text.substr(offset);
      }
      tick=0;UpdateCarPos(con);
    }
    if(kb.OnDown(VK_BACK))if(!readonly)
    {
      bool selected=is_selected();
      remove_selected_text();
      if(!selected)if(caret_pos>0)
      {
        text=text.substr(0,caret_pos-1)+text.substr(caret_pos);
        caret_pos--;
        sel_caret_pos=caret_pos;
      }
      tick=0;UpdateCarPos(con);
    }
    if(kb.OnDown(VK_RETURN))if(!readonly)
    {
      remove_selected_text();
      insert_string(con,"\n");
      //text=text.substr(0,caret_pos)+"\n"+text.substr(caret_pos);
      //caret_pos++;
      //tick=0;UpdateCarPos(con);
    }
    if(kb.News)if(is_allowed_char(kb.LastChar))if(!readonly)
    {
      remove_selected_text();
      insert_string(con,CToS(kb.LastChar));
      //if(!is_selected)
      //{
      //  text=text.substr(0,caret_pos)+CToS(kb.LastChar)+text.substr(caret_pos);
      //}
      //caret_pos++;tick=0;UpdateCarPos(con);
    }
    if(kb.OnDown(VK_DOWN))[&]()
    {
      int car_pos_x=car_pos.x+1;
      int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
      int offset=0;
      if(string::npos!=sol)offset=caret_pos-sol;
      if(string::npos==sol)offset=caret_pos+1;
      if(offset<car_pos_x)offset=car_pos_x;
      int eol=text.find("\n",caret_pos);
      if(string::npos==eol)return;//caret_pos=text.size();
      if(string::npos!=eol)
      {
        int p=text.find("\n",eol+1);
        if(p==string::npos)p=text.size();
        int next_line_size=p-eol;
        QapAssert(next_line_size);
        if(next_line_size<offset)offset=next_line_size;
        if(!offset)offset++;
        caret_pos=eol+offset;
      }
      tick=0;UpdateCarPos(con);
      car_pos.x=car_pos_x-1;
    }();
    if(kb.OnDown(VK_UP))[&]()
    {
      int car_pos_x=car_pos.x+1;
      int sol=!caret_pos?0:text.rfind("\n",caret_pos-1);
      int offset=0;
      if(string::npos==sol)return;//sol=0;
      if(string::npos!=sol)offset=caret_pos-sol;
      if(offset<car_pos_x)offset=car_pos_x;
      int sopl=text.rfind("\n",sol-1);
      int next_line_size=sol-1;
      if(string::npos==sopl)next_line_size=sol+1;
      if(string::npos!=sopl)next_line_size=sol-sopl;
      //QapAssert(next_line_size);
      if(next_line_size<offset)offset=next_line_size;
      caret_pos=sopl+offset;
      tick=0;UpdateCarPos(con);
      car_pos.x=car_pos_x-1;
    }();
    if(kb.OnDown(VK_LEFT))if(!text.empty())if(caret_pos<=text.size()&&caret_pos>0)
    {
      bool hyper_jump=(caret_pos!=text.size())&&(text[caret_pos-1]==' ');
      bool word_jump=ctrl&&!hyper_jump;
      if(ctrl&&hyper_jump)
      {
        for(int i=caret_pos-1;i>=0;i--)
        {
          if(text[i]==' ')continue;
          caret_pos=i+1;
          break;
        }
      }
      QapAssert(caret_pos);
      bool inside_word=is_char_from_word(text[caret_pos-1]);
      if(word_jump)if(caret_pos>0)
      {
        QapAssert(string("012").rfind('2',2)==2);
        //auto p=text.rfind(' ',caret_pos-1);
        auto p=rfind_begin_of_word(text,caret_pos-1);
        if(p!=string::npos)caret_pos=p+1;
        if(p==string::npos)caret_pos=0;
      }
      if(!inside_word||!ctrl){caret_pos--;}
      tick=0;UpdateCarPos(con);
    }
    if(kb.OnDown(VK_RIGHT))if(!text.empty())if(caret_pos<text.size()&&caret_pos>=0)
    {
      bool hyper_jump=text[caret_pos]==' ';
      bool word_jump=ctrl&&!hyper_jump;
      if(ctrl&&hyper_jump)
      {
        for(int i=caret_pos;i<text.size();i++)
        {
          if(text[i]==' ')continue;
          caret_pos=i;
          break;
        }
      }
      bool inside_word=is_char_from_word(text[caret_pos]);
      if(word_jump)
      {
        QapAssert(string(" 12").find(' ',0)!=string::npos);
        //auto p=text.find(' ',caret_pos);
        auto p=find_end_of_word(text,caret_pos);
        if(p!=string::npos)caret_pos=p;
        if(p==string::npos)caret_pos=int(text.size());
      }
      if(!inside_word||!ctrl){caret_pos++;}
      tick=0;UpdateCarPos(con);
    }
    caret_pos=Clamp<int>(caret_pos,0,text.size());
  }
  static string strpad(const string&s,int n){
    QapAssert(n>s.size());
    string tmp;tmp.resize(n-s.size(),'0');
    return tmp+s;
  }
  static string toStr(const vec2i&v){return "{x:"+IToS(v.x)+",y:"+IToS(v.y);}
  void log(const string&msg)
  {
    static QapClock clock;if(!clock.run)clock.Start();
    if(!log_enabled)return;
    logs.push_back("["+strpad(FToS(clock.MS()),11)+"] ["+strpad(IToS(log_tick),7)+"]["+strpad(IToS(dc_tick),3)+"] : "+msg);
  };
  void UpdateMouse(t_context&con)
  {
    if(dc_tick)dc_tick--;
    if(con.kb.OnDown(mbRight))log("mbRight");
    scroll_y+=Sign(con.root.win.zDelta);
    bool mod=con.kb.OnDown(mbLeft);
    bool md=con.kb.Down[mbLeft];
    if(md&&!mod&&!mouse_on_down_handled)
    {
      int gg=1;
      return;
    }
    if(!md)
    {
      mouse_on_down_handled=false;
      mouse_on_down_handled_for_select_word=false;
      return;
    }
    auto*pfont_obj=con.root.SysRes.FontObj.get();
    auto&font=pfont_obj->Font;
    bool ctrl=con.kb.Down[VK_CONTROL];
    bool mouse_moved=dc_mpos!=con.get_mpos();
    if(!mod&&is_double_click)return;
    is_double_click=(mod)&&(!mouse_moved)&&(dc_tick);
    if(is_double_click){
      log("is_double_click");
    }
    bool need_select_word=false;
    if(is_double_click)need_select_word=true;
    if(ctrl&&mod)
    {
      mouse_on_down_handled_for_select_word=true;
    }
    if(mouse_on_down_handled_for_select_word)
    {
      need_select_word=true;
    }
    auto tr=make_tr(con);
    tr.mpos=con.get_mpos();
    tr.loop_ex(font);
    if(tr.mpos_id<0)return;
    caret_pos=tr.mpos_id;
    if(mouse_moved)
    {
      tick=0;UpdateCarPos(con);
    }
    if(mod)
    {
      dc_tick=dc_max_tick;
      vec2i dv=dc_mpos-con.get_mpos();
      dc_mpos=con.get_mpos();
      log("mod {dc_mpos:"+toStr(dc_mpos)+",dv:"+toStr(dv)+"}");
    }
    if(!need_select_word||text.empty()||caret_pos>=text.size())return;
    log("select{mouse_moved:"+BToS(mouse_moved)+"}");
    //DoSelectCurrentWorld();
    if(text[caret_pos]==' ')
    {
      //std::swap
    }
    auto eow=find_end_of_word(text,caret_pos);//text.find(" ",caret_pos);
    auto bow=rfind_begin_of_word(text,caret_pos);//text.rfind(" ",caret_pos);
    if(eow==string::npos)eow=text.size();
    if(eow==string::npos)bow=0;
    sel_caret_pos=bow+1;
    caret_pos=eow;
  }
  void Update(t_context&con)
  {
    log_tick++;
    if(!caret_debug)tick++;
    if(tick>max_tick)tick=0;
    if(con.is_hovered()){
      if(scroll_y>0)scroll_y=0;
      UpdateText(con);UpdateMouse(con);
      if(scroll_y>0)scroll_y=0;
    }
    if(!need_load_text)return;
    need_load_text=false;
    //text=file_get_contents(fn);
    text=StrReplace(file_get_contents(fn),"\r","");
  }
};

class TBookPageWithTextEditorFixed:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBookPageWithTextEditorFixed)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TTextEditorFixed,editor,DEF,$,$)\
ADDEND()
//=====+>>>>>TBookPageWithTextEditorFixed
#include "QapGenStruct.inl"
//<<<<<+=====TBookPageWithTextEditorFixed
public:
  void Update(t_context&con){editor.Update(con);}
  void Render(t_context&con){editor.Render(con);}
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
        F(TType)F(TBookPageWithTextEditorFixed)
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
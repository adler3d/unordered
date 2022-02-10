#include "QapLite.h"

bool isRight(const vec2d&prev,const vec2d&o,const vec2d&next){return (next-o).Rot(prev-o).y>0;}

struct QapFontInfo{
  typedef vec2i vec2i_256[256];
  vec2i_256 Coords;
  vec2i&operator[](int index){return Coords[index];}
  const vec2i&operator[](int index)const{return Coords[index];}
};

struct QapFont{
  QapTexMem Mem;
  QapFontInfo Info;
};

struct QapBitmapInfo{
  BITMAPINFO BI;
  BITMAPINFOHEADER&BH;
  QapBitmapInfo(int W,int H):BH(BI.bmiHeader){
    ZeroMemory(&BI,sizeof(BI));
    BH.biSize=sizeof(BI.bmiHeader);
    BH.biWidth=W;BH.biHeight=H;
    BH.biPlanes=1;BH.biBitCount=32;
    BH.biSizeImage=W*H*4;
  }
};

static void CreateFontMem(HWND hWnd,QapTexMem&Out,QapFontInfo&Info,const string&Name,int Size,bool Bold,int TexSize)
{
  Out.Free();
  Out.Init(TexSize,TexSize);
  QapColor*pix=Out.get();
  {
    HDC DC=GetDC(hWnd);
    int W=Bold?FW_BOLD:FW_NORMAL;
    int H=-MulDiv(Size,GetDeviceCaps(DC,LOGPIXELSY),72);
    {
      HFONT FNT=CreateFontA(H,0,0,0,W,0,0,0,RUSSIAN_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH,Name.c_str());
      {
        HDC MDC=CreateCompatibleDC(DC);
        {
          HBITMAP BMP=CreateCompatibleBitmap(DC,TexSize,TexSize);
          SelectObject(MDC,BMP);
          RECT Rect; SetRect(&Rect,0,0,TexSize,TexSize);
          FillRect(MDC,&Rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
          SelectObject(MDC,FNT);
          SetBkMode(MDC,TRANSPARENT);
          SetTextColor(MDC,0xFFFFFF);
          for(int i=0;i<256;i++)TextOutA(MDC,i%16*(TexSize/16),i/16*(TexSize/16),(LPCSTR)&i,1);
          {QapBitmapInfo QBI(TexSize,TexSize);GetDIBits(MDC,BMP,0,TexSize,pix,&QBI.BI,DIB_RGB_COLORS);}
          for(int i=0;i<TexSize*TexSize;i++){pix[i].a=pix[i].r;pix[i].r=255;pix[i].g=255;pix[i].b=255;}
          for(int i=0;i<256;i++){SIZE cs;GetTextExtentPoint32A(MDC,(LPCSTR)&i,1,&cs);Info.Coords[i]=vec2i(cs.cx,cs.cy);}
          DeleteObject(BMP);
        }
        DeleteDC(MDC);
      }
      DeleteObject(FNT); 
    }
    ReleaseDC(hWnd,DC);
  }
  Out.InvertY();
  //QapTexMem*pMem=new QapTexMem("Font_"+Name+"_"+IToS(TexSize),TexSize,TexSize,(QapColor*)pix);
  //return pMem;
}

class TGame:public TD3DGameBoxBuilder{
public:
  /*
    burner is unique type of objects because this machine has progressbar for remining fuel.
    so we need to introduce furnace
    if i gnore fuel. then coal jsut not need for me at all.
    but i can implement frunce as mahine with hidden counter of fired fuel.
    ok.
    now i need to think about other types of machines.
    for example any of assembling mahine.
    oh. wait... machine need this pregress bar of compliting assembling stage.
    so. ok. i can. add progress bar to assembling machine.
    what about electronic circuit?
    and copper cable?
    and copper palete?
    and iron palete?
    some times we need to put our stream into machine and produce the iron plate from iron ore.
    
    t_koef{t_number num;{go_auto(num);go_const("*");}}//t_koef.num={real,FToS,SToF}
    t_line{t_koef koef;t_name name;{O+=go_auto(koef);M+=go_auto(name);}}

    t_record{
      t_line head;
      vector<t_line> lines;
      {
        go_auto(head);
        go_const("{");
        go_vec_with_sep(lines,"\n  ");
        go_const("}\n");
      }
    }

    2*CopperCable{
      1*CopperPlate
      0.5*sec
    }

    ElectricCircuit{
      1*IronPlate
      3*CopperCable
      0.5*sec
    }

    machine_types{
      
      stone furnace{
        
      }
    }
  */
  static bool can_be_moved(const string&from,const string&to)
  {
    auto b="belt";
    auto m="miner";
    auto i="inserter";
    auto c="chest";
    auto a="machine";
    if(to==b||to==c||to==a)return true;
    return false;
  }
  static const int cell_size=32;
  static const int item_wh=cell_size/2;
  struct t_source{
    vec2d pos;
    string name;
    int num;
    bool deaded;
    t_source(){deaded=false;num=50;pos=vec2d_zero;}
    void set(const string&name,int num,const vec2d&pos){
      this->name=name;
      this->num=num;
      this->pos=pos;
    }
  };
  struct t_item{
    vec2d pos;
    string name;
    bool deaded;
    t_item(){deaded=false;}
  };
  struct t_obj{
    vec2d pos;
    vec2d dir;
    vec2d size;
    string name;
    vector<t_item> items;
    bool deaded;
    t_obj(){deaded=false;dir=vec2d(1,0);pos=vec2d_zero;size=vec2d(cell_size,cell_size);}
    t_obj&set(real x,real y,const string&name){this->pos=vec2d(x,y);this->name=name;return *this;}
    t_obj&set(const vec2d&pos,const string&name){this->pos=pos;this->name=name;return *this;}
    bool take_item(t_obj&from)
    {
      if(from.items.empty())return false;
      qap_add_back(items)=from.items.back();
      from.items.pop_back();
      return true;
    }
  };
  vector<t_source> sources;
  vector<t_obj> objs;
  vector<t_item> items;
  int tick;
  vec2d cur_dir;
  string cur_name;
  vector<string> obj_types;
public:
  void gen_belt_line(vec2i a,vec2i b,vec2i dir)
  {
    auto ab=b-a;
    QapAssert(ab.x==0||ab.y==0);
    auto d=abs(ab.x+ab.y);
    auto dv=vec2i(Sign(ab.x),Sign(ab.y));
    for(int i=0;i<=d;i++)
    {
      auto&ref=qap_add_back(objs);
      ref.pos=a*cell_size+dv*i*cell_size;
      ref.name="belt";
      ref.dir=dir;
    }
  }
  void add_chest(vec2i pos)
  {
    auto&ref=qap_add_back(objs);
    ref.name="chest";
    ref.pos=pos*cell_size;
  }
  void add_inserter(vec2i pos,vec2i dir)
  {
    auto&ref=qap_add_back(objs);
    ref.name="inserter";
    ref.pos=pos*cell_size;
    ref.dir=dir;
  }
  void add_machine(vec2i pos,vec2i dir)
  {
    auto&ref=qap_add_back(objs);
    ref.name="machine";
    ref.pos=pos*cell_size;
    ref.dir=dir;
    ref.size.x=cell_size;
    ref.size.y=cell_size;
  }
  void add_miner(vec2i pos,vec2i dir)
  {
    auto&ref=qap_add_back(objs);
    ref.name="miner";
    ref.pos=pos*cell_size;
    ref.dir=dir;
    ref.size.x=cell_size;
    ref.size.y=cell_size;
  }
  void add_source(string name,vec2i pos,int num=100)
  {
    auto&ref=qap_add_back(sources);
    ref.name=name;
    ref.pos=pos*cell_size;
  }
  TGame()
  {
    obj_types=split("belt,miner,inserter,chest,machine",",");
    tick=0;
    qap_add_back(sources).set("coal",100,vec2d(-15,0)*cell_size);
    for(int i=0;i<8;i++)for(int j=0;j<4;j++)
    {
      qap_add_back(sources).set("stone",100,vec2d(-20+i,+7-j)*cell_size);
    }
    qap_add_back(objs).set(-cell_size*15,+0*cell_size,"miner");
    qap_add_back(objs).set(+cell_size*15,+0*cell_size,"miner").dir=vec2d(0,1);
    //qap_add_back(objs).set(-cell_size*10,-1*cell_size,"inserter").dir=vec2d(0,-1);
    add_chest(vec2i(0,0));
    add_inserter(vec2i(+1,+0),vec2i(-1,+0));
    add_inserter(vec2i(-1,+0),vec2i(+1,+0));
    add_inserter(vec2i(+0,+1),vec2i(+0,+1));
    qap_add_back(objs).set(-cell_size*20,+15*cell_size,"machine").size=vec2d(1,1)*cell_size*1;
    add_miner(vec2i(+11,0),vec2i(-1,0));
    add_miner(vec2i(-11,0),vec2i(+1,0));
    add_source("coal",vec2i(-11,0));
    add_source("stone",vec2i(+11,0));

    gen_belt_line(vec2i(+02,0),vec2i(10,0),vec2i(-1,0));
    gen_belt_line(vec2i(-10,0),vec2i(-2,0),vec2i(+1,0));
    gen_belt_line(vec2i(0,2),vec2i(0,10),vec2i(0,1));
    gen_belt_line(vec2i(+0,+11),vec2i(17,+11),vec2i(+1,+0));
    gen_belt_line(vec2i(18,+11),vec2i(18,-10),vec2i(+0,-1));
    gen_belt_line(vec2i(-7,-11),vec2i(18,-11),vec2i(-1,+0));
    gen_belt_line(vec2i(-8,-11),vec2i(-8,-01),vec2i(+0,+1));
    if(0)
    {
      for(int i=-14;i<+10;i++)
      {
        //if(i==-10)continue;
        qap_add_back(objs).set(cell_size*i,0,"belt").dir=vec2d(1,0);
      }
      //qap_add_back(objs).set(cell_size*10,0,"belt").dir=vec2d(0,1);
      for(int i=0;i<9;i++)
      {
        qap_add_back(objs).set(cell_size*10,cell_size*i,"belt").dir=vec2d(0,1);
      }
      for(int i=-35;i<+11;i++)
      {
        qap_add_back(objs).set(cell_size*i,+9*cell_size,"belt").dir=vec2d(-1,0);
      }
    }
    cur_dir=vec2d(1,0);
    cur_name="belt";
  }
public:
  static void DrawLine(QapDev&qDev,const vec2d&a,const vec2d&b,real line_size){
    qDev.DrawQuad((b+a)*0.5,(b-a).Mag(),line_size,(b-a).GetAng());
  }
  static bool mpos_test(const vec2d&pos,const vec2d&mpos,int r)
  {
    auto d=pos-mpos;
    return (abs(d.x)<=r&&abs(d.y)<=r);
  }
  bool check_space(const vec2d&pos,int koef=2)
  {
    int r=item_wh/koef;
    for(int i=0;i<items.size();i++)
    {
      auto&ex=items[i];
      auto d=(ex.pos-pos);
      if(abs(d.x)<=r&&abs(d.y)<=r)return false;
    }
    return true;
  }
  static vec2d fix(const vec2d&pos,const vec2d&dir)
  {
    auto v=pos.Rot(dir);
    v.y+=-Sign(v.y);
    return v.UnRot(dir);
  }
  void move_items_at_space(const vec2d&pos,const vec2d&dir)
  {
    int r=cell_size/2;
    int rr=r*r;
    for(int i=0;i<items.size();i++)
    {
      auto&ex=items[i];
      auto d=(ex.pos-pos);
      if(abs(d.x)<=r&&abs(d.y)<=r)
      {
        auto np=ex.pos+dir*(cell_size/2);
        if(!check_space(np))continue;
        auto df=fix(ex.pos-pos,dir);
        ex.pos=pos+df;
        ex.pos+=dir;
        int v=ex.pos.x+1;
      }
    }
  }
  t_source*get_source_at_space(const vec2d&pos)
  {
    int r=cell_size/2;
    int rr=r*r;
    for(int i=0;i<sources.size();i++)
    {
      auto&ex=sources[i];
      auto d=(ex.pos-pos);
      if(abs(d.x)<=r&&abs(d.y)<=r)
      {
        return &ex;
      }
    }
    return nullptr;
  }
  t_item*get_item_at_space(const vec2d&pos)
  {
    int r=cell_size/2;
    int rr=r*r;
    for(int i=0;i<items.size();i++)
    {
      auto&ex=items[i];
      auto d=(ex.pos-pos);
      if(abs(d.x)<=r&&abs(d.y)<=r)
      {
        return &ex;
      }
    }
    return nullptr;
  }
  t_obj*obj_place_test(const vec2d&pos)
  {
    for(int i=0;i<objs.size();i++)
    {
      auto&ex=objs[i];
      if(mpos_test(ex.pos,pos,cell_size/2))
      {
        return &ex;
      }
    }
    return nullptr;
  }
  bool try_insert(t_item&item,const vec2d&out_point)
  {
    bool ok=check_space(out_point,1);
    if(!ok)return false;
    auto*obj=obj_place_test(out_point);
    if(!obj||obj->name=="belt")
    {
      item.pos=out_point;
      return true;
    }
    //split("belt,miner,inserter,chest,machine",",");
    if(obj->name=="inserter"){return false;}
    {
      qap_add_back(obj->items)=item;
      item.deaded=true;
      return true;
    }
    QapDebugMsg("no impl");
    return false;
  }
  void DoMove()
  {
    static const int r=cell_size/2;
    tick++;
    if(win.Keyboard.Down[VK_ESCAPE])win.Close();
    vec2d mpos=win.GetMousePos();
    for(int i=0;i<objs.size();i++)
    {
      auto&ex=objs[i];
      if(mpos_test(ex.pos,mpos,r))
      {
        if(win.Keyboard.OnDown('X'))ex.deaded=true;
        if(win.Keyboard.OnDown('R'))
        {
          ex.dir=(-ex.dir).Ort();
          cur_dir=ex.dir;
        }
      }
      if(ex.name=="belt")
      {
        move_items_at_space(ex.pos,ex.dir);
        continue;
      }
      if(ex.name=="miner")
      {
        if(tick%16!=0)continue;
        auto space=ex.pos+ex.dir*cell_size;
        t_item item;
        auto*source=get_source_at_space(ex.pos);
        if(!source||source->num<=0)continue;
        auto ok=try_insert(item,space);
        if(!ok)continue;
        item.name=source->name;
        source->num--;
        qap_add_back(items)=item;
        continue;
      }
      if(ex.name=="inserter")
      {
        auto*ptr=get_item_at_space(ex.pos-ex.dir*cell_size);
        if(!ptr)
        {
          auto inp_point=ex.pos-ex.dir*cell_size;
          auto*obj=obj_place_test(inp_point);
          if(obj)if(obj->name=="chest")if(!obj->items.empty())
          {
            auto out_point=ex.pos+ex.dir*cell_size;
            auto ok=check_space(out_point);
            if(ok)
            {
              auto item=obj->items.back();
              obj->items.pop_back();
              item.pos=out_point;
              qap_add_back(items)=item;
              continue;
            }
            auto*out_obj=obj_place_test(out_point);
            if(out_obj)
            {
              if(out_obj->name=="belt")continue;
              if(out_obj->name=="chest")
              {
                out_obj->take_item(*obj);
                //QapDebugMsg("no impl. inserter attempt to move item form chest to chest");
                //out_obj->push_item(obj->pop_item());
                continue;
              }
              QapDebugMsg("no impl. inserter attempt to move item form chest to "+out_obj->name);
            }
            continue;
          }
          continue;
        }
        auto out_point=ex.pos+ex.dir*cell_size;
        out_point=get_aligned(out_point);
        try_insert(*ptr,out_point);
        continue;
      }
    }
    if(win.Keyboard.Down[mbRight])for(;;)
    {
      auto*obj=obj_place_test(get_aligned_mpos());
      if(obj)
      {
        obj->dir=cur_dir;
        break;
      }
      qap_add_back(objs).set(get_aligned_mpos(),cur_name).dir=cur_dir;
      break;
    }
    clean_if(sources,[](t_source&ex)->bool{return ex.num<=0;});
    clean_if(objs,[](t_obj&ex)->bool{return ex.deaded;});
    clean_if(items,[](t_item&ex)->bool{return ex.deaded;});
    for(int i=0;i<obj_types.size();i++)
    {
      if(win.Keyboard.Down['1'+i])cur_name=obj_types[i];
    }
  }
  void DrawMPosCell()
  {
    vec2d mpos_aligned=get_aligned_mpos();
    qDev.SetColor(0x80ffffff);
    qDev.DrawQuad(mpos_aligned,cell_size,cell_size);
  }
  struct t_simbol{
    struct t_quad{
      vec2i p;
      vec2i s;
      void set(int x,int y,int w,int h){p.x=x;p.y=y;s.x=w;s.y=h;}
    };
    vector<t_quad> arr;
  };
  void DrawText(int offsetx,int offsety,const string&text)
  {
    static QapTexMem out;
    static QapFontInfo info;
    if(!out.W)CreateFontMem(win.Form.WinPair.hWnd,out,info,"system",8,false,512);
    static real ms=0;
    static vector<t_simbol> arr;
    auto d=out.W/16;
    vector<unsigned char> x_chars;
    if(arr.empty())
    {
      arr.resize(256);
      for(int i=0;i<256;i++)
      {
        unsigned char c=i;
        auto&cinfo=arr[c];
        auto size=info.Coords[c];
        auto p=vec2i(c%16,c/16);
        int n=d;
        auto s=out.Arr.get();
        //static const bool use_x=false;
        auto buffx=cinfo.arr;
        auto buffy=cinfo.arr;
        //if(use_x)
        {
          for(int y=0;y<n;y++)for(int x=0;x<size.x;x++)
          {
            auto addr=p.x*d+x+(p.y*d+y)*out.W;
            auto&ex=s[addr];
            if(!ex.a)continue;
            int sx=1;
            for(int cx=x+1;cx<size.x;cx++){
              if(!s[addr-x+cx].a)break;
              sx++;
            }
            qap_add_back(buffx).set(x,y,sx,1);
            if(sx>1)x+=sx-1;
          }
        }
        //if(!use_x)
        {
          for(int x=0;x<size.x;x++)for(int y=0;y<n;y++)
          {
            auto addr=p.x*d+x+(p.y*d+y)*out.W;
            auto&ex=s[addr];
            if(!ex.a)continue;
            int sy=1;
            for(int cy=y+1;cy<n;cy++){
              auto naddr=p.x*d+x+(p.y*d+cy)*out.W;
              if(!s[naddr].a)break;
              sy++;
            }
            qap_add_back(buffy).set(x,y-1,1,-sy);
            if(sy>1){
              y+=sy-1;
            }
          }
        }
        bool best_x=buffx.size()<buffy.size();
        if(best_x){
          qap_add_back(x_chars)=c;
        }
        cinfo.arr=best_x?buffx:buffy;
      }
    }
    string msg=text;//="ABCDEFGHIJKLMNOPRSTQUVWXYZ // "+FToS(ms)+" ms";
    //out.Arr[
    //static 
    //qDev.SetColor(0xff000000);
    vec2i offset=vec2i(offsetx,offsety);
    auto ps=cell_size*0.125*0.5;
    QapClock clock;clock.Start();
    for(int i=0;i<msg.size();i++)
    {
      unsigned char c=msg[i];
      auto&quads=arr[c].arr;
      auto size=info.Coords[c];
      for(int j=0;j<quads.size();j++)
      {
        auto&ex=quads[j];
        qDev.DrawQuad(offset+vec2d(ex.p.x,-ex.p.y)*ps+(vec2d(ex.s)-vec2d(1,1))*ps*0.5,ps*ex.s.x,ps*ex.s.y);
      }
      //auto size=info.Coords[c];
      //auto p=vec2i(c%16,c/16);
      //int n=d;
      //auto s=out.Arr.get();
      //for(int y=0;y<n;y++)for(int x=0;x<size.x;x++)
      //{
      //  auto addr=p.x*d+x+(p.y*d+y)*out.W;
      //  auto&ex=s[addr];
      //  if(!ex.a)continue;
      //  int sx=1;
      //  for(int cx=x+1;cx<size.x;cx++){
      //    if(!s[addr-x+cx].a)break;
      //    sx++;
      //  }
      //  qDev.DrawQuad(offset+vec2d(x-80,-y+64)*ps+vec2d(sx*ps*0.5,0),ps*sx,ps);
      //  if(sx>1)x+=sx-1;
      //}
      offset.x+=size.x*ps;
    }
    clock.Stop();ms=clock.MS();
    //string s=
    //".      .\n"
    //"..    ..\n"
    //"..    ..\n"
    //"..    ..\n"
    //"........\n"
    //"........\n"
    //"..    ..\n"
    //"..    ..\n"
    //"..    ..\n"
    //".      .\n";
    //int x=0;int y=0;
    //for(int i=0;i<s.size();i++)
    //{
    //  auto&ex=s[i];
    //  if(ex=='\n'){y++;x=0;continue;}
    //  if(ex==' '){x++;continue;}
    //  qDev.DrawQuad(vec2d(x,y+7)*cell_size*0.25,cell_size*0.25,cell_size*0.25);
    //  x++;
    //}
    //qDev.DrawQuad(vec2d(
  }
  void DoDraw()
  {
    QapDev::BatchScope Scope(qDev);
    vec2d mpos=win.GetMousePos();
    qDev.BindTex(0,nullptr);
    qDev.SetColor(0xff000000);
    DrawText(-512,+300,"Текст сверху слева.");
    //qDev.DrawQuad(mpos,10,10);
    int obj_wh=32;
    for(int i=0;i<sources.size();i++)
    {
      auto&ex=sources[i];
      qDev.SetColor(0xff000000);
      qDev.DrawCircleEx(ex.pos,0,cell_size*0.5,5,0);
    }
    for(int pass=1;pass<=2;pass++)
    {
      for(int i=0;i<objs.size();i++)
      {
        auto&ex=objs[i];
        if(ex.name=="belt")
        {
          if(1==pass)
          {
            qDev.SetColor(0xff505050);
            qDev.DrawQuad(ex.pos,ex.size.x,ex.size.y);
          }
          if(pass==2)
          {
            vec2d dirx=vec2d(1,0).UnRot(ex.dir);
            vec2d diry=vec2d(0,1).UnRot(ex.dir);
            real k=ex.size.x*0.5*0.5;
            qDev.color=0x40e0e0e0;
            vec2d dp=vec2d(1,0).UnRot(ex.dir)*(tick%cell_size);
            auto a=qDev.AddVertex(ex.pos+dp+dirx*k,qDev.color,vec2f_zero);
            auto b=qDev.AddVertex(ex.pos+dp+diry*k,qDev.color,vec2f_zero);
            auto c=qDev.AddVertex(ex.pos+dp-diry*k,qDev.color,vec2f_zero);
            qDev.AddTris(a,b,c);
          }
          continue;
        }
        if(ex.name=="miner")if(1==pass)
        {
          qDev.SetColor(0xff000000);
          qDev.DrawQuad(ex.pos,ex.size.x,ex.size.y);
          continue;
        }
        if(ex.name=="inserter")if(1==pass)
        {
          qDev.SetColor(0xffdf0000);
          qDev.DrawQuad(ex.pos,ex.size.x,ex.size.y);
          qDev.SetColor(0xff8f0000);
          DrawLine(qDev,ex.pos,ex.pos+ex.dir*cell_size,2);
          continue;
        }
        if(ex.name=="chest")if(1==pass)
        {
          qDev.SetColor(0xff00df00);
          qDev.DrawQuad(ex.pos,ex.size.x,ex.size.y);
          continue;
        }
        if(ex.name=="machine")if(1==pass)
        {
          qDev.SetColor(0xff0000df);
          qDev.DrawQuad(ex.pos,ex.size.x,ex.size.y);
          continue;
        }
      }
      //int item_wh=8;
      qDev.SetColor(0x80ffffff);
      for(int i=0;i<items.size();i++)
      {
        auto&ex=items[i];
        if(1==pass)
        {
          if(ex.name=="coal")qDev.SetColor(0xff000000);
          if(ex.name=="stone")qDev.SetColor(0xff909050);
          qDev.DrawCircleEx(ex.pos,cell_size*0.5,0,9,0);
        }
        if(2==pass)
        {
          qDev.SetColor(0xffffffff);
          DrawText(ex.pos.x-cell_size/4,ex.pos.y+cell_size/2,UpperStr(CToS(ex.name[0])));
        }
        //qDev.DrawQuad(items[i].pos,item_wh,item_wh);
      };
    }
    DrawMPosCell();
  }
  vec2d get_aligned(const vec2d&pos)
  {
    vec2d pos_aligned=pos;
    const int some_const=cell_size/2+cell_size*1024*512;
    pos_aligned.x=int((int(pos.x)+some_const)/cell_size)*cell_size-some_const;
    pos_aligned.y=int((int(pos.y)+some_const)/cell_size)*cell_size-some_const;
    return pos_aligned+vec2d(1,1)*cell_size*0.5;
  }
  vec2d get_aligned_mpos()
  {
    vec2d mpos=win.GetMousePos();
    return get_aligned(mpos);
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}
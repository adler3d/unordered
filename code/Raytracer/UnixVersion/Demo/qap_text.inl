
public:
  typedef QapDev::t_geom t_geom;
public:
  struct t_simbol{
    struct t_quad{
      vec2i p;
      vec2i s;
      void set(int x,int y,int w,int h){p.x=x;p.y=y;s.x=w;s.y=h;}
    };
    vector<t_quad> arr;
  };
  struct qap_text{
    struct t_simbol{
      struct t_quad{
        vec2i p;
        vec2i s;
        void set(int x,int y,int w,int h){p.x=x;p.y=y;s.x=w;s.y=h;}
      };
      t_geom geom;
      real ps;
      vector<t_quad> arr;
      void make_geom(real ps)
      {
        this->ps=ps;
        for(int j=0;j<arr.size();j++)
        {
          auto&ex=arr[j];
          auto p=vec2d(ex.p.x,-ex.p.y)*ps+(vec2d(ex.s)-vec2d(1,1))*ps*0.5;
          auto sx=ps*ex.s.x;
          auto sy=ps*ex.s.y;
          geom.add(QapDev::GenGeomQuad(p,sx,sy));
        }
      }
    };
    struct t_mem{
      QapTexMem out;
      QapFontInfo info;
      vector<t_simbol> arr;
      vector<unsigned char> x_chars;
      //int def_text_size;
      real ms;
      t_mem():ms(0){}
      void prepare(HWND hwnd){if(arr.empty())init(hwnd);}
      void init(HWND hwnd)
      {
        QapAssert(arr.empty());
        if(!out.W)CreateFontMem(hwnd,out,info,"system",8,false,512,true);
        arr.resize(256);
        for(int i=0;i<256;i++)
        {
          unsigned char c=i;
          auto&cinfo=arr[c];
          cinfo.ps=-1;
          auto size=info.Coords[c];
          auto p=vec2i(c%16,c/16);
          int n=out.W/16;
          auto s=out.Arr.get();
          auto buffx=cinfo.arr;
          auto buffy=cinfo.arr;
          //if(use_x)
          {
            for(int y=0;y<n;y++)for(int x=0;x<size.x;x++)
            {
              auto addr=p.x*n+x+(p.y*n+y)*out.W;
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
              auto addr=p.x*n+x+(p.y*n+y)*out.W;
              auto&ex=s[addr];
              if(!ex.a)continue;
              int sy=1;
              for(int cy=y+1;cy<n;cy++){
                auto naddr=p.x*n+x+(p.y*n+cy)*out.W;
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
    };
    static t_mem&get_mem(HWND hwnd){static t_mem mem;mem.prepare(hwnd);return mem;}
    static vec2i get_size(QapDev&qDev,const string&text,int cell_size=32)
    {
      auto&mem=get_mem(qDev.DynRes.pDev->PresParams.pp.hDeviceWindow);
      QapFontInfo&info=mem.info;
      vector<t_simbol>&arr=mem.arr;
      auto ps=cell_size*0.125*0.5;
      auto offset=vec2i_zero;
      for(int i=0;i<text.size();i++)
      {
        unsigned char c=text[i];
        auto size=info.Coords[c];
        offset.x+=size.x*ps;
      }
      return vec2i(offset.x,info.Coords[' '].y);
    }
    static void draw(QapDev&qDev,int px,int py,const string&text,int cell_size=32){draw(qDev,vec2i(px,py),text,cell_size);}
    static void draw(QapDev&qDev,const vec2d&pos,const string&text,int cell_size=32){draw(qDev,vec2i(pos.x,pos.y),text,cell_size);}
    static void draw(QapDev&qDev,const vec2i&pos,const string&text,int cell_size=32)
    {
      auto&mem=get_mem(qDev.DynRes.pDev->PresParams.pp.hDeviceWindow);
      QapFontInfo&info=mem.info;
      vector<t_simbol>&arr=mem.arr;
      auto ps=cell_size*0.125*0.5;
      auto offset=pos;
      for(int i=0;i<text.size();i++)
      {
        unsigned char c=text[i];
        auto size=info.Coords[c];
        auto&ex=arr[c];
        if(ex.ps<0)ex.make_geom(ps);
        if(ex.ps==ps)
        {
          qDev.DrawGeomWithOffset(ex.geom,offset);
        }
        if(ex.ps!=ps)
        {
          auto&quads=ex.arr;
          for(int j=0;j<quads.size();j++)
          {
            auto&ex=quads[j];
            auto p=vec2d(ex.p.x,-ex.p.y)*ps+(vec2d(ex.s)-vec2d(1,1))*ps*0.5;
            auto sx=ps*ex.s.x;
            auto sy=ps*ex.s.y;
            qDev.DrawQuad(offset+p,sx,sy);
          }
        }
        offset.x+=size.x*ps;
      }
    }
  };
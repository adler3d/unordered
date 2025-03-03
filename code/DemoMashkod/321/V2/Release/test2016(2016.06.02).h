{
  int g_ptr_addr(){return 1024*(64+7);}
  int g_mem_addr(){return 1024*(64+7)+8;}
  int alloc(int size){
    int g_addr=g_ptr_addr();
    int g_ptr=get_int(g_addr);
    if(!g_ptr){
      int ram_base=(1024*(64+8));
      g_ptr=ram_base;
    }
    set_int(g_addr,g_ptr+size);
    return g_ptr;
  }
  struct vec2i{
    int x;
    int y;
    int mag(){return hypot(x,y);}
  };
  vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;};
  int add(int addr,int v){return set_int(addr,v);}
  int hypot(vec2i v){return hypot(v.x,v.y);}
  vec2i sub(vec2i a,vec2i b){return vec2i(a.x-b.x,a.y-b.y);}
  vec2i add(vec2i a,vec2i b){return vec2i(a.x+b.x,a.y+b.y);}
  vec2i mul(vec2i a,int k){return vec2i(a.x*k,a.y*k);}
  vec2i div(vec2i a,int k){return vec2i(a.x/k,a.y/k);}
  // -----=====
  int get_int(int addr){int out=0;__asm("mov(eax,param_addr);mov(var_out,ptr[eax]);");return out;}
  int set_int(int addr,int v){__asm("mov(eax,param_addr);mov(ptr[eax],param_v);");return addr+1;}
  int setebx(int value){__asm("mov(ebx,param_value);");return 0;}
  int hypot(int x,int y){int out=0;__asm("mov(eax,param_x);mov(ebx,param_y);hypot(eax,ebx);mov(var_out,eax);");return out;}
  // -----=====
  int QapAssert(int cond){if(!cond){__asm("label(\"Run-time error!\");mov(err,-1);");};}
  int QapAssert(int A,int B){if(A!=B){__asm("label(\"Run-time error!\");mov(err,-1);");};}
  int min(int a,int b){if(a<b)return a;return b;}
  int max(int a,int b){if(a>b)return a;return b;}
  int clamp(int low,int top,int value){return min(max(low,value),top);}
  struct qap_vertex{
    int color;
    vec2i pos;
  };
  qap_vertex qap_vertex(int color,vec2i pos){qap_vertex tmp;tmp.color=color;tmp.pos=pos;return tmp;}
  struct vector_qap_vertex{
    int p;int n;int cap;
    int reserve(int c){p=alloc(3*c);n=0;cap=c;return 0;}
    int sys_add(int ref){p=set_int(p,ref);return p;}
    int sys_add(vec2i ref){sys_add(ref.x);sys_add(ref.y);return p;}
    int add(int color,vec2i pos){QapAssert(n<cap);sys_add(color);sys_add(pos);n++;return p;}
    int add(qap_vertex ref){QapAssert(n<cap);sys_add(ref.color);sys_add(ref.pos);n++;return p;}
    vec2i get_vec2i(int addr){
      return vec2i(get_int(addr),get_int(addr+1));
    }
    qap_vertex get(int addr){
      return qap_vertex(get_int(addr),get_vec2i(addr+1));
    }
    qap_vertex at(int id){
      return get(p+(id-n)*3);
    }
    vector_int to_vector_int(){
      vector_int tmp;tmp.p=p;tmp.n=n*3;tmp.cap=cap*3;
      return tmp;
    }
    qap_vertex front(){QapAssert(n>0);return at(0);}
    qap_vertex back(){QapAssert(n>0);return at(n-1);}
    vector_qap_vertex clone(){
      vector_qap_vertex tmp;
      tmp.reserve(cap);
      for(int i=0;i<n;i++)tmp.add(at(i));
      return tmp;
    }
    int is_equal(vector_qap_vertex VA)
    {
      QapAssert(VA.n,n);
      for(int i=0;i<n;i++)
      {
        auto a=VA.at(i);
        auto b=at(i);
        QapAssert(a.color,b.color);
        QapAssert(a.pos.x,b.pos.x);
        QapAssert(a.pos.y,b.pos.y);
      }
    }
    int addr_at(int id){return p+(id-n)*3;}
    int add_with_offset(vector_qap_vertex VA,vec2i offset)
    {
      auto did=addr_at(n);auto sid=VA.addr_at(0);
      int x=offset.x;
      int y=offset.y;
      int van=VA.n;
      __asm("mov(eax,var_did);mov(ebx,var_sid);");
      for(;van;van--)
      {
        __asm("mov(edx,ptr[ebx]);mov(ptr[eax],edx);");
        __asm("mov(edx,ptr[ebx+1]);add(edx,var_x);mov(ptr[eax+1],edx);");
        __asm("mov(edx,ptr[ebx+2]);add(edx,var_y);mov(ptr[eax+2],edx);");
        __asm("add(ebx,3);add(eax,3);");
        //did+=3;sid+=3;
      }
      n+=VA.n;
      p+=VA.n*3;
    }
    int add_with_color(vector_qap_vertex VA,int color,vec2i offset)
    {
      auto did=addr_at(n);auto sid=VA.addr_at(0);
      int x=offset.x;
      int y=offset.y;
      int van=VA.n;
      __asm("mov(eax,var_did);mov(ebx,var_sid);");
      for(;van;van--)
      {
        __asm("mov(ptr[eax],param_color);");
        __asm("mov(edx,ptr[ebx+1]);add(edx,var_x);mov(ptr[eax+1],edx);");
        __asm("mov(edx,ptr[ebx+2]);add(edx,var_y);mov(ptr[eax+2],edx);");
        __asm("add(ebx,3);add(eax,3);");
        //did+=3;sid+=3;
      }
      n+=VA.n;
      p+=VA.n*3;
    }
  };
  struct vector_int{
    int p;int n;int cap;
    int reserve(int c){p=alloc(1*c);n=0;cap=c;return 0;}
    int add(int ref){QapAssert(n<cap);p=set_int(p,ref);n++;return p;}
    int get(int addr){
      return get_int(addr);
    }
    int at(int id){
      return get(p+id-n);
    }
    int front(){QapAssert(n>0);return at(0);}
    int back(){QapAssert(n>0);return at(n-1);}
    int add_mega_fast(vector_int IA,int vpos){
      int sp=IA.p-IA.n;
      int c=IA.n;
      __asm("mov(edx,param_vpos);mov(eax,field_p);");
      for(;c;c--){
        //ptr[p]=ptr[sp];
        __asm("mov(ebx,var_sp);mov(ebx,ptr[ebx]);add(ebx,edx);mov(ptr[eax],ebx);inc(eax);");
        sp++;
      }
      n+=IA.n;
      p+=IA.n;
    }
    int addr_at(int id){return p+(id-n)*1;}
  };
  struct t_out_dev{
    vector_qap_vertex VA;
    vector_int IA;
    int color;
    int AddTris(int a,int b,int c){IA.add(a);IA.add(b);IA.add(c);return 0;}
    int AddVertex(qap_vertex qv){VA.add(qv);return 0;}
    int AddVertex(int x,int y){VA.add(color,vec2i(x,y));return 0;}
    int AddVertex(vec2i pos){VA.add(color,pos);return 0;}
    int AddVertexAndRetVID(vec2i pos){VA.add(color,pos);return VA.n-1;}
    int add(t_out_dev geom)
    {
      QapAssert(0==geom.IA.n%3);
      int vpos=VA.n;
      for(int i=0;i<geom.VA.n;i++)VA.add(geom.VA.at(i));
      for(int i=0;i<geom.IA.n;i++)IA.add(vpos+geom.IA.at(i));
      return 0;
    }
    int add_wo(t_out_dev geom,vec2i offset)
    {
      QapAssert(0==geom.IA.n%3);
      int vpos=VA.n;
      for(int i=0;i<geom.VA.n;i++){auto tmp=geom.VA.at(i);tmp.pos=add(tmp.pos,offset);VA.add(tmp);}
      for(int i=0;i<geom.IA.n;i++)IA.add(vpos+geom.IA.at(i));
      return 0;
    }
    int add_wc(t_out_dev geom,vec2i offset)
    {
      QapAssert(0==geom.IA.n%3);
      int vpos=VA.n;
      for(int i=0;i<geom.VA.n;i++){auto tmp=geom.VA.at(i);tmp.color=color;tmp.pos=add(tmp.pos,offset);VA.add(tmp);}
      for(int i=0;i<geom.IA.n;i++)IA.add(vpos+geom.IA.at(i));
      return 0;
    }
    int add_with_offset(t_out_dev geom,vec2i offset)
    {
      QapAssert(VA.n<1024*16);
      QapAssert(0==geom.IA.n%3);
      IA.add_mega_fast(geom.IA,VA.n);
      VA.add_with_offset(geom.VA,offset);
      return 0;
    }
    int add_with_color(t_out_dev geom,vec2i offset)
    {
      QapAssert(VA.n<1024*16);
      QapAssert(0==geom.IA.n%3);
      IA.add_mega_fast(geom.IA,VA.n);
      VA.add_with_color(geom.VA,color,offset);
      return 0;
    }
    t_out_dev GenGeomQuad(int x,int y,int w,int h)
    {
      auto geom=new_geom(1);geom.color=color;
      int hx=w/2;int hy=h/2;
      geom.AddVertex(x-hx,y-hy);
      geom.AddVertex(x+hx,y-hy);
      geom.AddVertex(x+hx,y+hy);
      geom.AddVertex(x-hx,y+hy); 
      geom.AddTris(1,0,3);
      geom.AddTris(3,2,1);
      return geom;
    }
  };
  t_out_dev new_geom(int n)
  {
    t_out_dev tmp;
    tmp.VA.reserve(4*n);
    tmp.IA.reserve(6*n);
    return tmp;
  }
  // struct qap_mesh{
  //   vector{qap_vertex} VA;
  //   vector{int} IA;
  // };

  struct t_input{
    vec2i mpos;
    int zDelta;
    vector_int kb_down;
    vector_int kb_changed;
  };
  struct t_dev{
    int p;
    int read_int(){int v=get_int(p);p++;return v;}
    vec2i read_vec2i(){return vec2i(read_int(),read_int());}
    vector_int read_vector_int(){vector_int tmp;tmp.n=read_int();p+=tmp.n;tmp.p=p;return tmp;}
    vector_int read_IA(){return read_vector_int();}
    vector_qap_vertex read_VA(){vector_qap_vertex tmp;tmp.n=read_int();p+=tmp.n*3;tmp.p=p;return tmp;}
    t_out_dev read_geom(){t_out_dev od;od.VA=read_VA();od.IA=read_IA();return od;}
    int write(int ref){p=set_int(p,ref);return p;}
    int write(int c,int x,int y){write(c);write(x);write(y);return p;}
    int write(vec2i pos){write(pos.x);write(pos.y);return p;}
    int write(int c,vec2i pos){write(c);write(pos.x);write(pos.y);return p;}
    int write(qap_vertex v){write(v.color);write(v.pos);return p;}
    int write(t_out_dev dev)
    {
      write(dev.VA.n);
      //for(int i=0;i<dev.VA.n;i++)write(dev.VA.at(i));
      {
        auto sp=dev.VA.addr_at(0);
        auto dev_va_n=dev.VA.n;
        __asm("mov(eax,var_sp);mov(ebx,field_p);");
        for(;dev_va_n;dev_va_n--){
          //__asm("mov(eax,var_sp);mov(ebx,field_p);");
          __asm("mov(edx,ptr[eax+0]);mov(ptr[ebx+0],edx);");
          __asm("mov(edx,ptr[eax+1]);mov(ptr[ebx+1],edx);");
          __asm("mov(edx,ptr[eax+2]);mov(ptr[ebx+2],edx);");
          //sp+=3;p+=3;
          __asm("add(eax,3);add(ebx,3);");
        }
        p+=dev.VA.n*3;
      }
      write(dev.IA.n);
      //for(int i=0;i<dev.IA.n;i++)write(dev.IA.at(i));
      {
        auto sp=dev.IA.addr_at(0);
        QapAssert(0,dev.IA.n%3);
        auto dev_ia_n=dev.IA.n/3;
        __asm("mov(eax,var_sp);mov(ebx,field_p);");
        for(;dev_ia_n;dev_ia_n--){
          __asm("mov(edx,ptr[eax+0]);mov(ptr[ebx+0],edx);");
          __asm("mov(edx,ptr[eax+1]);mov(ptr[ebx+1],edx);");
          __asm("mov(edx,ptr[eax+2]);mov(ptr[ebx+2],edx);");
          __asm("add(eax,3);add(ebx,3);");
        }
        p+=dev.IA.n;
      }
    }
    int write_def(vec2i pos)
    {
      //VA.N
      write(6);
      //VA
      int black=255<<(8*3);
      int white=-1;
      int red=black+(255<<(8*2));
      int green=black+(255<<(8*1));
      int blue=black+(255<<(8*0));
      int color=black;
      write(color,add(pos,vec2i(-30,0)));
      write(color,add(pos,vec2i(0,30)));
      write(color,add(pos,vec2i(+30,0)));
      vec2i gos=pos;gos.x+=60;
      write(color,add(gos,vec2i(-30,0)));
      write(color,add(gos,vec2i(0,30)));
      write(green,add(gos,vec2i(+30,0)));
      //IA.N
      int IAN=2*3;
      write(IAN);
      //IA
      for(int i=0;i<IAN;i++)write(i);
    }
  };
  struct t_mem{
    int ptr;
    int size;
  };
  int g_obj_addr(){return 1024*(64+7)+512;}
  vec2i get_obj_pos(t_input inp)
  {
    auto obj=vec2i(-200,30);auto obj_addr=g_obj_addr();
    if(get_int(obj_addr+2))
    {
      obj.x=get_int(obj_addr+0);
      obj.y=get_int(obj_addr+1);
    }else{
      set_int(obj_addr+2,1);
    }
    int VK_LEFT=0;int VK_RIGHT=0;
    int VK_UP=0;int VK_DOWN=0;
    __asm("mov(var_VK_LEFT,VK_LEFT);mov(var_VK_RIGHT,VK_RIGHT);");
    __asm("mov(var_VK_UP,VK_UP);mov(var_VK_DOWN,VK_DOWN);");
    int speed=2;
    if(inp.kb_down.at(VK_LEFT)){obj.x-=speed;}
    if(inp.kb_down.at(VK_RIGHT)){obj.x+=speed;}
    if(inp.kb_down.at(VK_UP)){obj.y+=speed;}
    if(inp.kb_down.at(VK_DOWN)){obj.y-=speed;}
    set_int(obj_addr+0,obj.x);
    set_int(obj_addr+1,obj.y);
    return obj;
  }
  t_out_dev gen_grid(vec2i mpos)
  {
    auto od=new_geom(64*4*16*2);
    auto quad=od.GenGeomQuad(0,0,10,10);
    auto line=new_geom(64*2*4);
    for(int x=0;x<64;x++)
    {
      line.color=(255<<24)+((16+x*7)<<8);
      auto pos=vec2i(mpos.x+16*x,0);
      line.add_with_color(quad,pos);
    }
    for(int y=0;y<16;y++)
    {
      auto pos=vec2i(0,16*y);
      od.add_with_offset(line,pos);
    }
    return od;
  }
  t_out_dev get_grid(vec2i mpos)
  {
    t_dev dev;
    dev.p=get_int(g_mem_addr());
    if(!dev.read_int())
    {
      int dev_p=dev.p;
      dev.write(gen_grid(mpos));
      int size=dev.p-dev_p;
      set_int(dev_p-1,size);
      dev.p=dev_p;
    }
    return dev.read_geom();
  }
  t_mem cr_test(t_input inp)
  {
    auto obj_pos=get_obj_pos(inp);
    //out.write_def(inp.mpos);
    vec2i mpos=inp.mpos;
    auto od=new_geom(1024*4);
    od.color=(255<<24)+(128<<8);
    if(1)
    {
      auto no_offset=vec2i(0,0);
      {
        auto q1=od.GenGeomQuad(mpos.x,mpos.y,30,30);
        od.color=(255<<24)+(128<<8)+(255<<16);
        auto q2=od.GenGeomQuad(mpos.x,mpos.y-64,100,10);
        auto q3=od.GenGeomQuad(200+mpos.x,mpos.y,10,60);
        od.add_with_offset(q1,no_offset);
        od.add_with_offset(q2,no_offset);
        od.add_with_offset(q3,no_offset);
      }
      //auto no_offset=vec2i(0,0);
      /*
      for(int x=0;x<64;x++)
      {
        //od.color=(255<<24)+((128+x*7)<<8);
        od.color=(255<<24)+((16+x*7)<<8);
        auto px=obj_pos.x+mpos.x+16*x;
        for(int y=0;y<16;y++)
        {
          od.add(od.GenGeomQuad(px,obj_pos.y+16*y,10,10));
        }
      }*/
      
      //od.add_with_offset(get_grid(vec2i(0,0)),add(obj_pos,mpos));
      //od.add_with_offset(gen_grid(add(obj_pos,mpos)),vec2i(0,0));
      if(1)
      {
        auto quad=od.GenGeomQuad(0,0,10,10);
        for(int x=0;x<64;x++)
        {
          od.color=(255<<24)+((16+x*7)<<8);
          auto pos=vec2i(obj_pos.x+mpos.x+16*x,0);
          for(int y=0;y<16;y++)
          {
            pos.y=obj_pos.y+16*y;
            od.add_with_color(quad,pos);
          }
        }
      }
      
    }else{
      od=od.GenGeomQuad(mpos.x,mpos.y,30,30);
    }
    t_mem mem;
    mem.ptr=alloc(1024*1024);
    t_dev out;
    out.p=mem.ptr;
    out.write(od);
    mem.size=out.p-mem.ptr;
    return mem;
  }
  int main(int ptr)
  {
    set_int(g_ptr_addr(),0);
    set_int(g_mem_addr(),alloc(1024*512));
    t_input inp;t_dev dev;dev.p=ptr;
    inp.mpos=dev.read_vec2i();
    inp.zDelta=dev.read_int();
    inp.kb_down=dev.read_vector_int();
    inp.kb_changed=dev.read_vector_int();
    t_mem out=cr_test(inp);
    setebx(out.size);
    __asm("mov(ecx,1);");
    return out.ptr;
  }
}
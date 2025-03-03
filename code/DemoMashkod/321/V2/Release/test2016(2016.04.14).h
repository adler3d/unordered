{
  struct vec2i{
    int x=0;
    int y=0;
    //int set(int nx,int ny){int x=0;x=nx;y=ny;return x+y;}
    //int mag(){return hypot(x,y);}
    //int mul(int nx,int ny){return vec2i(nx*x,ny*y);}
  };
  
  struct t_quad{
    vec2i a;
    vec2i b;
  };
  struct t_abc{int a;int b;int c;};
  t_abc foo(t_quad q,vec2i offset){
    t_abc tmp;
    tmp.a=q.a.x;
    tmp.b=q.b.y;
    tmp.c=q.a.y+q.b.x+offset.x;
    return tmp;
  }
  int new_main(){
    t_quad q;
    t_abc abc=foo(q,vec2i(0,1));
    /*
    {
      VAR("t_abc",abc);ctor(abcl);
      VAR("t_abc",retval);ctor(retval);
      {
        push(q);
        VAR("vec2i",retval);ctor(retval);
        {
          push(0);
          push(1);
          call("vec2i(int,int)");
        }
        lea(esp,retval);
        call("foo(int,vec2i");
        dtor(retval);
      }
      lea(esp,retval);
      copy(abc,retval);
      dtor(retval);
      dtor(abc);
    }
    */
    return 0;
  }
  
  int getmem(int addr){__asm("mov(eax,param_addr);mov(eax,ptr[eax]);");}
  void setmem(int addr,int v){__asm("push(ebx);mov(eax,param_addr);mov(ebx,param_v);mov(ptr[eax],ebx);pop(ebx);");}
  void setebx(int value){__asm("mov(ebx,param_value);");}
  int hypot(int x,int y){__asm("mov(eax,param_x);mov(ebx,param_y);hypot(eax,ebx);");}
  int CatmullRomEx(int p1,int p2,int p3,int p4,int t,int z){
    int a=p2;
    int b=p3-p1;
    int c=2*p1-5*p2+4*p3-p4;
    int d=3*(p2-p3)+p4-p1;
    d=(d*t)/z;
    d+=c;
    d=(d*t)/z;
    d+=b;
    d=(d*t)/z;
    return a+d/2;
  }
  vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;}
  struct AB{
    int a;
    int b;
    vec2i c;
  };
  void win(){
    AB g;
    g.c.y=0;
  }
  /*
  proc{
    VAR(struct_AB,var_g);
    mov(var_g["c"]["y"],0);
  }
  */
  /*
  {STRUCT(vec2i){
    FIELD(int,field_x);
    FIELD(int,field_y);
  }}
  
  {proc("vec2i::`ctor"){
    PARAM(vec2i,result);
    mov(result["x"],0);
    mov(result["y"],0);
  }}

  VAR(vec2i,out); //sub(esp,2);
  call("vec2i::`ctor");
  
  */
  vec2i foo()
  {
    vec2i out;
    out.x=0;
    out.y=0;
  }
  int bar(vec2i p){return p.x+p.y;}
  int nothing(){
    vec2i z=foo();
    vec2i point;
    point.x=10;
    point.y=20;
    int v=bar(point);
    return v;
  }
  /*
  push(point,sizeof(vec2i)); // sub(esp,sizeof(vec2i));{push(esp);push(point);push(sizeof(vec2i));call("memcpy");add(esp,3);}
  call("bar");
  */
  int hypot(vec2i v){return hypot(v.x,v.y);}
  vec2i div(vec2i v,int d){return vec2i(v.x/d,v.y/d);}
  vec2i operator*(vec2i v,int m){return vec2i(v.x*m,v.y*m);}
  vec2i b_add_ba_set_mag_m(vec2i a,vec2i b,int m)
  {
    auto ba=a-b;
    int h=hypot(ba);
    if(!h)return a;
    return b+div(ba*m,h);
  }
  int CatmullRomG(int addr,vec2i a_,vec2i b,vec2i c,vec2i d_,int t,int z)
  {
    int ax=ax_;int ay=ay_;int dx=dx_;int dy=dy_;
    int m=hypot(bx-cx,by-cy);
    auto a=b_add_ba_set_mag_m(a,b,m);
    auto d=b_add_ba_set_mag_m(d,c,m);
    int out_x=CatmullRomEx(a.x,b.x,c.x,d.x,t,z);
    int out_y=CatmullRomEx(a.y,b.y,c.y,d.y,t,z);
    return add_point(addr,out_x,out_y);
  }
  int add_point(int addr,int x,int y){
    int p=addr;
    setmem(p,x);p++;
    setmem(p,y);p++;
    return p;
  }
  int cr_test(int mposx,int mposy)
  {
    int int_size=1;
    int vec2i_size=int_size*2;
    int t_line_size=vec2i_size*2;
    int p_base=1024*2;
    int p=p_base;
    int ax=450;int ay= 50;
    int bx=650;int by=150; bx=mposx; by=mposy;
    int cx=300;int cy=500;
    int dx=390;int dy=550;
    int g_base=1024*16;
    int g=g_base;
    int point_count=16; int z=point_count;
    
    for(int i=0;i<point_count;i++)
    {
      int t=(i*z)/point_count;
      g=CatmullRomG(g,ax,ay,ax,ay,bx,by,cx,cy,t,z);
    }
    g=CatmullRomG(g,ax,ay,ax,ay,bx,by,cx,cy,z,z);
//
    for(int i=0;i<point_count;i++)
    {
      int t=(i*z)/point_count;
      g=CatmullRomG(g,ax,ay,bx,by,cx,cy,dx,dy,t,z);
    }
    g=CatmullRomG(g,ax,ay,bx,by,cx,cy,dx,dy,z,z);
//
    for(int i=0;i<point_count;i++)
    {
      int t=(i*z)/point_count;
      g=CatmullRomG(g,bx,by,cx,cy,dx,dy,dx,dy,t,z);
    }
    g=CatmullRomG(g,bx,by,cx,cy,dx,dy,dx,dy,z,z);
//
    int n=(g-g_base)/vec2i_size;
    for(int i=1;i<n;i++){
      int aptr=g_base+(i-1)*vec2i_size;
      int bptr=g_base+(i-0)*vec2i_size;
      p=add_line_by_addrs(p,aptr,bptr);
    }
    int ptr=p_base-1;
    int size=p-ptr;
    setmem(ptr,(p-p_base)/t_line_size);
    setebx(size);
    return ptr;
  }
  int main(int mx,int my){return cr_test(mx,my);}
  int add_line(int addr,int x0,int y0,int x1,int y1){
    int p=addr;
    setmem(p,x0);p+=1;
    setmem(p,y0);p+=1;
    setmem(p,x1);p+=1;
    setmem(p,y1);p+=1;
    return p;
  }
  int add_line_by_addrs(int addr,int aptr,int bptr){
    int p=addr;
    setmem(p,getmem(aptr+0));p+=1;
    setmem(p,getmem(aptr+1));p+=1;
    setmem(p,getmem(bptr+0));p+=1;
    setmem(p,getmem(bptr+1));p+=1;
    return p;
  }
}
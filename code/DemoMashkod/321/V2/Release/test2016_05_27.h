{
  struct vec2i{
    int x;
    int y;
    int mag(){return hypot(x,y);}
  };
  vec2i vec2i(int x,int y){vec2i tmp;tmp.x=x;tmp.y=y;return tmp;};
  struct t_line{
    vec2i a;
    vec2i b;
  };
  t_line t_line(vec2i a,vec2i b){
    t_line tmp;
    tmp.a=a;tmp.b=b;
    return tmp;
  };
  int dev_test(){return 0;}
  int add(int addr,int v){return set_int(addr,v);}
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
  int hypot(vec2i v){return hypot(v.x,v.y);}
  vec2i sub(vec2i a,vec2i b){return vec2i(a.x-b.x,a.y-b.y);}
  vec2i add(vec2i a,vec2i b){return vec2i(a.x+b.x,a.y+b.y);}
  vec2i mul(vec2i a,int k){return vec2i(a.x*k,a.y*k);}
  vec2i div(vec2i a,int k){return vec2i(a.x/k,a.y/k);}
  vec2i VCatmullRom(vec2i a_,vec2i b,vec2i c,vec2i d_,int t,int z)
  {
    vec2i a=a_;vec2i d=d_;
    int m=hypot(sub(b,c));
    {
      vec2i v=sub(a,b);
      int D=hypot(v);
      if(D)
      {
        a=add(b,div(mul(v,m),D));
      }
    }
    {
      vec2i v=sub(d,c);
      int D=hypot(v);
      if(D)
      {
        d=add(c,div(mul(v,m),D));
      }
    }
    return vec2i(
      CatmullRomEx(a.x,b.x,c.x,d.x,t,z),
      CatmullRomEx(a.y,b.y,c.y,d.y,t,z)
    );
  }
  int CatmullRomG(int addr,vec2i a,vec2i b,vec2i c,vec2i d,int t,int z)
  {
    return add(
      addr,
      VCatmullRom(a,b,c,d,t,z)
    );
  }
  // -----=====
  int get_int(int addr){int out=0;__asm("mov(eax,param_addr);mov(var_out,ptr[eax]);");return out;}
  int set_int(int addr,int v){__asm("push(ebx);mov(eax,param_addr);mov(ebx,param_v);mov(ptr[eax],ebx);pop(ebx);");return addr+1;}
  int setebx(int value){__asm("mov(ebx,param_value);");return 0;}
  int hypot(int x,int y){int out=0;__asm("mov(eax,param_x);mov(ebx,param_y);hypot(eax,ebx);mov(var_out,eax);");return out;}
  // -----=====
  struct vector_t_line{
    int p;int n;
    int sys_add(int ref){p=set_int(p,ref);return p;}
    int sys_add(vec2i ref){sys_add(ref.x);sys_add(ref.y);return p;}
    int add(t_line ref){sys_add(ref.a);sys_add(ref.b);n++;return p;}
    vec2i get_vec2i(int addr){
      return vec2i(get_int(addr),get_int(addr+1));
    }
    t_line get(int addr){
      return t_line(get_vec2i(addr),get_vec2i(addr+2));
    }
    t_line at(int id){
      return get(p+(id-n)*4);
    }
  };
  struct vector_vec2i{
    int p;int n;
    int sys_add(int ref){p=set_int(p,ref);return p;}
    int add(vec2i ref){sys_add(ref.x);sys_add(ref.y);n++;return p;}
    vec2i get(int addr){
      return vec2i(get_int(addr),get_int(addr+1));
    }
    vec2i at(int id){
      return get(p+(id-n)*2);
    }
    int CatmullRom(vector_vec2i arr,int id){
      int point_count=16;int z=point_count;
      QapAssert(arr.n>=3);
      int n=arr.n;
      vec2i a=arr.at(clamp(0,n-1,id-1));
      vec2i b=arr.at(clamp(0,n-1,id+0));
      vec2i c=arr.at(clamp(0,n-1,id+1));
      vec2i d=arr.at(clamp(0,n-1,id+2));
      for(int i=0;i<point_count;i++)
      {
        int t=(i*z)/point_count;
        add(VCatmullRom(a,b,c,d,t,z));
      }
      add(VCatmullRom(a,b,c,d,z,z));
      return p;
    }
  };
  int QapAssert(int cond){return 0;}
  int min(int a,int b){if(a<b)return a;return b;}
  int max(int a,int b){if(a>b)return a;return b;}
  int clamp(int low,int top,int value){return min(max(low,value),top);}
  /*struct t_dev{
    int p;
    int add(int ref){p=set_int(p,ref);return p;}
    int add(vec2i ref){add(ref.x);add(ref.y);return p;}
    int add(t_line ref){add(ref.a);add(ref.b);return p;}
  };*/
  struct t_mem{
    int ptr;
    int size;
  };
  t_mem cr_test(int mposx,int mposy)
  {
    int out_base=1024*2;
    int arr_base=1024*16;
    int dev_base=1024*32;
    vec2i a=vec2i(450, 50);
    vec2i b=vec2i(650,150); b.x=mposx; b.y=mposy;
    vec2i c=vec2i(300,500);
    vec2i d=vec2i(390,550);
    vector_vec2i arr;arr.p=arr_base;arr.n=0;
    {
      arr.add(vec2i(0,0));
      arr.add(a);
      arr.add(b);
      arr.add(c);
      arr.add(d);
      arr.add(vec2i(450,550));
    }
    vector_vec2i dev;dev.p=dev_base;dev.n=0;
    for(int i=0;i+1<arr.n;i++)dev.CatmullRom(arr,i);
    vector_t_line out;out.p=out_base;out.n=0;
    int n=dev.n;
    for(int i=1;i<n;i++){
      out.add(t_line(dev.at(i-1),dev.at(i-0)));
    }
    out.add(t_line(vec2i( -100,0),vec2i(+1000,0)));
    out.add(t_line(vec2i(0,-10),vec2i(0,+10)));
    t_mem mem;
    mem.ptr=out_base-1;
    mem.size=out.p-mem.ptr;
    set_int(mem.ptr,out.n);
    return mem;
  }
  int main(int mx,int my)
  {
    dev_test();
    t_mem out=cr_test(mx,my);
    setebx(out.size);
    return out.ptr;
  }
}
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
  int hypot(vec2i v){return hypot(v.x,v.y);}
  vec2i sub(vec2i a,vec2i b){return vec2i(a.x-b.x,a.y-b.y);}
  vec2i add(vec2i a,vec2i b){return vec2i(a.x+b.x,a.y+b.y);}
  vec2i mul(vec2i a,int k){return vec2i(a.x*k,a.y*k);}
  vec2i div(vec2i a,int k){return vec2i(a.x/k,a.y/k);}
  // -----=====
  int get_int(int addr){int out=0;__asm("mov(eax,param_addr);mov(var_out,ptr[eax]);");return out;}
  int set_int(int addr,int v){__asm("push(ebx);mov(eax,param_addr);mov(ebx,param_v);mov(ptr[eax],ebx);pop(ebx);");return addr+1;}
  int setebx(int value){__asm("mov(ebx,param_value);");return 0;}
  int hypot(int x,int y){int out=0;__asm("mov(eax,param_x);mov(ebx,param_y);hypot(eax,ebx);mov(var_out,eax);");return out;}
  // -----=====
  int QapAssert(int cond){return 0;}
  int min(int a,int b){if(a<b)return a;return b;}
  int max(int a,int b){if(a>b)return a;return b;}
  int clamp(int low,int top,int value){return min(max(low,value),top);}
  struct t_dev{
    int p;
    int add(int ref){p=set_int(p,ref);return p;}
    int add(vec2i ref){add(ref.x);add(ref.y);return p;}
    int add(t_line ref){add(ref.a);add(ref.b);return p;}
  };
  struct t_out_dev{
    t_vpos;
    int 
  };
  struct qap_vertex{
    int color;
    vec2i pos;
  };
  // struct qap_mesh{
  //   vector{qap_vertex} VA;
  //   vector{int} IA;
  // };
  struct t_mem{
    int ptr;
    int size;
  };
  t_mem cr_test(int mposx,int mposy)
  {
    int out_base=1024*(64+8);
    
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
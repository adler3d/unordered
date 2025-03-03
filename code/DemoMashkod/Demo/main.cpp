#ifndef DEF_BUILD_MICRO
#include "QapLite.h"
#include "TQapGameV2.inl"
#include <memory>
using std::unique_ptr;
#endif
//#include "get_cpu_speed.cpp"
//=====>>>>>main
#ifndef DEF_BUILD_MICRO
  //  #define DEF_BUILD_MACRO
#endif
#ifdef DEF_BUILD_MACRO
  #include "../Macro/all.h"
#else

//#define CL_WITHOUT_ASM_APP

static void pad_in_place(string&s,int pad_to){string h;h.resize(std::max<int>(0,pad_to-s.size()),' ');s=s+h;}
static void pad_bef_in_place(string&s,int pad_to){string h;h.resize(std::max<int>(0,pad_to-s.size()),' ');s=h+s;}
static string pad(string s,int pad_to){pad_in_place(s,pad_to);return s;}
static string pad_bef(string s,int pad_to){pad_bef_in_place(s,pad_to);return s;}
struct t_cmd{
  #define DEF_PRO_CLASSNAME()t_cmd
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,id,0)\
  ADD(int,dest,0)\
  ADD(int,a,0)\
  ADD(int,b,0)\
  //===
  #include "defprovar.inl"
  //===
  void set(int id,int dest=0,int a=0,int b=0){this->id=id;this->dest=dest;this->a=a;this->b=b;}
  t_cmd(int id,int dest=0,int a=0,int b=0){this->id=id;this->dest=dest;this->a=a;this->b=b;}
  string to_source()const{
    return "arr.push_back(t_cmd("+to_nums()+"));";
  }
  string to_nums()const{
    vector<string> out;
    auto f=[&](int v){out.push_back(IToS(v));};
    f(id);f(dest);f(a);f(b);
    return join(out,",");
  }
  void from_nums(const string&s){
    auto arr=split(s,",");int i=0;
    auto f=[&](int&v){QapAssert(qap_check_id(arr,i));v=SToI(arr[i]);i++;};
    f(id);f(dest);f(a);f(b);
  }
};

#define CMD_LIKE_ADD(CMD,func)\
CMD(func(reg[dest],reg[a],reg[b]))\
CMD(func(reg[dest],reg[a],mem[b]))\
CMD(func(reg[dest],reg[a],raw[b]))\
CMD(func(reg[dest],mem[a],reg[b]))\
CMD(func(reg[dest],mem[a],mem[b]))\
CMD(func(reg[dest],mem[a],raw[b]))\
CMD(func(reg[dest],raw[a],reg[b]))\
CMD(func(reg[dest],raw[a],mem[b]))\
CMD(func(reg[dest],raw[a],raw[b]))\
CMD(func(mem[dest],reg[a],reg[b]))\
CMD(func(mem[dest],reg[a],mem[b]))\
CMD(func(mem[dest],reg[a],raw[b]))\
CMD(func(mem[dest],mem[a],reg[b]))\
CMD(func(mem[dest],mem[a],mem[b]))\
CMD(func(mem[dest],mem[a],raw[b]))\
CMD(func(mem[dest],raw[a],reg[b]))\
CMD(func(mem[dest],raw[a],mem[b]))\
CMD(func(mem[dest],raw[a],raw[b]))\
/* CMD_LIKE_ADD */

#define CMD_LIKE_MOV(CMD,func)\
CMD(func(reg[dest],reg[src]))\
CMD(func(reg[dest],mem[src]))\
CMD(func(reg[dest],raw[src]))\
CMD(func(mem[dest],reg[src]))\
CMD(func(mem[dest],mem[src]))\
CMD(func(mem[dest],raw[src]))\
CMD(func(raw[dest],reg[src]))\
CMD(func(raw[dest],mem[src]))\
CMD(func(raw[dest],raw[src]))\
\
CMD(func(ptr(dest),reg[src]))\
CMD(func(ptr(dest),mem[src]))\
CMD(func(ptr(dest),raw[src]))\
CMD(func(reg[dest],ptr(src)))\
CMD(func(mem[dest],ptr(src)))\
CMD(func(raw[dest],ptr(src)))\
\
CMD(func(ptr[reg[dest]+raw[a]],reg[b]))\
CMD(func(ptr[reg[dest]+raw[a]],mem[b]))\
CMD(func(ptr[reg[dest]+raw[a]],raw[b]))\
CMD(func(ptr[reg[dest]+raw[a]],ptr(b)))\
CMD(func(reg[dest],ptr[reg[a]+raw[b]]))\
CMD(func(mem[dest],ptr[reg[a]+raw[b]]))\
CMD(func(raw[dest],ptr[reg[a]+raw[b]]))\
CMD(func(ptr(dest),ptr[reg[a]+raw[b]]))\
/* CMD_LIKE_MOVPTR */

#define CMD_ONEPARAM_IS_OUT(CMD,func)\
CMD(func(reg[dest]))\
CMD(func(mem[dest]))\
\
CMD(func(ptr[reg[dest]+raw[a]]))\
/* CMD_ONEPARAM_IS_OUT */

#define CMD_ONEPARAM_IS_INP(CMD,func)\
CMD(func(reg[dest]))\
CMD(func(mem[dest]))\
CMD(func(raw[dest]))\
\
CMD(func(ptr[reg[dest]+raw[a]]))\
/* CMD_ONEPARAM_IS_INP */

#define CMD_ZERO(CMD,func)\
CMD(func())\
/* CMD_ZERO */

#define F_INC_DEC(F,CMD,PART)F(CMD,PART##_inc);F(CMD,PART##_dec);F(CMD,rep_##PART##_inc);F(CMD,rep_##PART##_dec);

#define CMDS_LIKE_ADD(CMD,F)\
F(CMD,hypot)\
F(CMD,add)\
F(CMD,sub)\
F(CMD,mul)\
F(CMD,div)\
F(CMD,mod)\
F(CMD,eq)\
F(CMD,neq)\
F(CMD,less)\
F(CMD,more)\
F(CMD,nless)\
F(CMD,nmore)\
F(CMD,or)\
F(CMD,and)\
F(CMD,bwxor)\
F(CMD,bwor)\
F(CMD,bwand)\
F(CMD,shr)\
F(CMD,shl)\
F(CMD,ushr)\
F(CMD,ushl)\
\
F(CMD,getbit)\
F(CMD,setbit)\
F(CMD,getbyte)\
F(CMD,setbyte)\
/* CMDS_LIKE_ADD */

#define CMDS_LIKE_MOV(CMD,F)\
F_INC_DEC(F,CMD,add_mulsd)\
F(CMD,jz)\
F(CMD,jnz)\
F(CMD,mov)\
F(CMD,not)\
F(CMD,inv)\
F(CMD,sqrt)\
CMDS_LIKE_ADD(CMD,F)\
/* CMDS_LIKE_MOV */

#define CMDS_ONEPARAM_IS_INP(CMD,F)\
F(CMD,memgetuaint)\
F(CMD,memsetuaint)\
F(CMD,memgetbyte)\
F(CMD,memsetbyte)\
F(CMD,jmp)\
F(CMD,call)\
F(CMD,push)\
F(CMD,loop)\
F_INC_DEC(F,CMD,addsd)\
F_INC_DEC(F,CMD,subsd)\
F_INC_DEC(F,CMD,mulsd)\
F_INC_DEC(F,CMD,divsd)\
F_INC_DEC(F,CMD,modsd)\
F_INC_DEC(F,CMD,bwxorsd)\
F_INC_DEC(F,CMD,bworsd)\
F_INC_DEC(F,CMD,bwandsd)\
/* CMDS_ONEPARAM_IS_INP */

#define CMDS_ONEPARAM_IS_OUT(CMD,F)\
F(CMD,pop)\
F(CMD,inc)\
F(CMD,dec)\
F(CMD,not)\
F(CMD,inv)\
/* CMDS_ONEPARAM_IS_OUT */

#define CMDS_ZERO(CMD,F)\
F(CMD,ret)\
F(CMD,nop)\
F(CMD,label)\
F(CMD,CatmullRomEx)\
F(CMD,CatmullRom)\
F(CMD,movsd_inc)\
F(CMD,movsd_dec)\
F(CMD,lodsd_inc)\
F(CMD,lodsd_dec)\
F(CMD,stosd_inc)\
F(CMD,stosd_dec)\
F(CMD,rep_movsd_inc)\
F(CMD,rep_movsd_dec)\
F(CMD,rep_lodsd_inc)\
F(CMD,rep_lodsd_dec)\
F(CMD,rep_stosd_inc)\
F(CMD,rep_stosd_dec)\
/* CMDS_ZERO */

#define CMDS(CMD)\
CMDS_LIKE_MOV(CMD,CMD_LIKE_MOV)\
CMDS_LIKE_ADD(CMD,CMD_LIKE_ADD)\
CMDS_ONEPARAM_IS_INP(CMD,CMD_ONEPARAM_IS_INP)\
CMDS_ONEPARAM_IS_OUT(CMD,CMD_ONEPARAM_IS_OUT)\
CMDS_ZERO(CMD,CMD_ZERO)\
CMD(lea(reg[dest],ptr[reg[a]+raw[b]]))\
CMD(pushlea(ptr[reg[dest]+raw[a]]))\
/* CMDS */

enum t_register{
  #define DEF_PRO_REGISTERS(F)\
  F(eax               )\
  F(ebx               )\
  F(ecx               )\
  F(edx               )\
  F(ebp               )\
  F(esp               )\
  F(edi               )\
  F(esi               )\
  F(eip               )\
  F(err               )\
  F(cmd_counter       )\
  F(debug_depth       )\
  /* DEF_PRO_REGISTERS */
  #define F(NAME)NAME,
  DEF_PRO_REGISTERS(F)
  #undef F
  num_of_registers
};

static vector<string> iplog;
static int total_iters=0;

static void fuck_u_debugger()
{
  string win=join(iplog,"\n");
  file_put_contents("fuck_u_debugger.txt",win);
  int gg=win.size();
}

struct t_machine{
  #define DEF_PRO_CLASSNAME()t_machine
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,dno,1024*16)\
  ADD(vector<t_cmd>,arr,$)\
  ADD(vector<int>,mem,$)\
  ADD(vector<int>,reg,$)\
  ADD(vector<string>,arr2str,$)\
  ADD(vector<string>,labels,$)\
  //===
  #include "defprovar.inl"
  //===
  void memgetuaint(int addr){QapAssert(addr>=0&&addr+3<mem.size()*sizeof(int));reg[eax]=(int&)(((unsigned char*)&mem[0])[addr]);}
  void memsetuaint(int addr){QapAssert(addr>=0&&addr+3<mem.size()*sizeof(int));(int&)(((unsigned char*)&mem[0])[addr])=reg[eax];}
  void memgetbyte(int addr){QapAssert(addr>=0&&addr<mem.size()*sizeof(int));reg[eax]=((unsigned char*)&mem[0])[addr];}
  void memsetbyte(int addr){QapAssert(addr>=0&&addr<mem.size()*sizeof(int));((unsigned char*)&mem[0])[addr]=reg[eax];}
  //
  void getbit (int&dest,int src,int id){dest=(*(std::bitset<32>*)&dest)[abs(id)%32];}
  void setbit (int&dest,int src,int id){(*(std::bitset<32>*)&dest)[abs(id)%32]=src;}
  void getbyte(int&dest,int src,int id){dest=((unsigned char*)&src)[abs(id)%4];}
  void setbyte(int&dest,int src,int id){((unsigned char*)&dest)[abs(id)%4]=src;}
  //
  void getbit (int&inout,int id){inout=(*(std::bitset<32>*)&inout)[abs(id)%32];}
  void setbit (int&inout,int id){QapNoWay();}
  void getbyte(int&inout,int id){inout=((unsigned char*)&inout)[abs(id)%4];}
  void setbyte(int&inout,int id){QapNoWay();}
  //
  void getbit (const int&,int,int){QapNoWay();}
  void setbit (const int&,int,int){QapNoWay();}
  void getbyte(const int&,int,int){QapNoWay();}
  void setbyte(const int&,int,int){QapNoWay();}
  //
  void getbit (const int&,int){QapNoWay();}
  void setbit (const int&,int){QapNoWay();}
  void getbyte(const int&,int){QapNoWay();}
  void setbyte(const int&,int){QapNoWay();}
  //
  void jz(const int&dest,const int&src){if(!src)jmp(dest);}
  void jnz(const int&dest,const int&src){if(src)jmp(dest);}
  void lea(const int&dest,const int&src){QapNoWay();}
  void mov(const int&,const int&){QapNoWay();}
  void not(const int&,const int&){QapNoWay();}
  void inv(const int&,const int&){QapNoWay();}
  void sqrt(const int&dest,const int&src){QapNoWay();}
  void lea(int&dest,const int&src){dest=(&src)-(&mem[0]);}
  void mov(int&dest,const int&src){dest=src;}
  void not(int&dest,const int&src){dest=!bool(src);}
  void inv(int&dest,const int&src){dest=-src;}
  void sqrt(int&dest,const int&src){dest=::sqrt(double(src));}
  //
  void not(int&dest){dest=!bool(dest);}
  void inv(int&dest){dest=-dest;}
  void pushlea(const int&src){push((&src)-(&mem[0]));}
  void loop(const int&dest){reg[ecx]--;if(!reg[ecx])return;mov(reg[eip],dest);}
  void movsd_inc(){mov(mem[reg[edi]],mem[reg[esi]]);reg[edi]++;reg[esi]++;}
  void movsd_dec(){mov(mem[reg[edi]],mem[reg[esi]]);reg[edi]--;reg[esi]--;}
  void lodsd_inc(){mov(reg[eax],mem[reg[esi]]);reg[esi]++;}
  void lodsd_dec(){mov(reg[eax],mem[reg[esi]]);reg[esi]--;}
  void stosd_inc(){mov(mem[reg[edi]],reg[eax]);reg[edi]++;}
  void stosd_dec(){mov(mem[reg[edi]],reg[eax]);reg[edi]--;}
  //
  void add_mulsd_inc(const int&k,const int&dv){lodsd_inc();mul(reg[eax],k);add(reg[eax],dv);stosd_inc();}
  void add_mulsd_dec(const int&k,const int&dv){lodsd_dec();mul(reg[eax],k);add(reg[eax],dv);stosd_dec();}
  void rep_add_mulsd_inc(const int&k,const int&dv){if(!reg[ecx])return;reg[ecx]--;reg[eip]--;add_mulsd_dec(k,dv);}
  void rep_add_mulsd_dec(const int&k,const int&dv){if(!reg[ecx])return;reg[ecx]--;reg[eip]--;add_mulsd_dec(k,dv);}
  //
  #define F(PROC)void rep_##PROC(){if(!reg[ecx])return;reg[ecx]--;reg[eip]--;PROC();}
  #define REP(NAME)F(NAME##_inc);F(NAME##_dec);
  REP(movsd);
  REP(lodsd);
  REP(stosd);
  #undef REP
  #undef F
  //
  #define F(CMD,DIR,OPER)void CMD##sd_##DIR(const int&b){mem[reg[edi]]=mem[reg[esi]]##OPER##b;DIR(reg[esi]);DIR(reg[edi]);}
  #define SD_INC_DEC(NAME,OPER)F(NAME,inc,OPER);F(NAME,dec,OPER);
  SD_INC_DEC(add,+);
  SD_INC_DEC(sub,-);
  SD_INC_DEC(mul,*);
  SD_INC_DEC(div,/);
  SD_INC_DEC(mod,%);
  SD_INC_DEC(bwxor,^);
  SD_INC_DEC(bwor,|);
  SD_INC_DEC(bwand,&);
  #undef SD_INC_DEC
  #undef F
  //
  #define F(PROC)void rep_##PROC(const int&dv){if(!reg[ecx])return;reg[ecx]--;reg[eip]--;PROC(dv);}
  #define REP(NAME)F(NAME##sd_inc);F(NAME##sd_dec);
  REP(add);
  REP(sub);
  REP(mul);
  REP(div);
  REP(mod);
  REP(bwxor);
  REP(bwor);
  REP(bwand);
  #undef REP
  #undef F
  //
  #define CMD_LIST(F)\
  F(hypot,::sqrt(double(a*a+b*b)))\
  F(add  ,a+b )\
  F(sub  ,a-b )\
  F(mul  ,a*b )\
  F(div  ,b?a/b:0 )\
  F(mod  ,b?a%b:0 )\
  F(eq   ,a==b)\
  F(neq  ,a!=b)\
  F(less ,a<b )\
  F(more ,a>b )\
  F(nless ,a>=b )\
  F(nmore ,a<=b )\
  F(bwxor,a^b )\
  F(bwor ,a|b )\
  F(bwand,a&b )\
  F(or   ,a||b)\
  F(and  ,a&&b)\
  F(shr  ,a>>b)\
  F(shl  ,a<<b)\
  F(ushr  ,unsigned(a)>>b)\
  F(ushl  ,unsigned(a)<<b)\
  /* CMD_LIST */
  #define F(CMD,CODE)void CMD(int&dest,int a,int b){dest=CODE;}
  CMD_LIST(F);
  #undef F
  #define F(CMD,CODE)void CMD(int&a,int b){a=CODE;}
  CMD_LIST(F);
  #undef F
  #define F(CMD,CODE)void CMD(const int&a,int b){QapNoWay();}
  CMD_LIST(F);
  #undef F
  #undef CMD_LIST
  //
  void jmp(const int&dest){reg[eip]=dest;}
  void inc(int&inout){inout++;}
  void dec(int&inout){inout--;}
  void push(const int&inp){reg[esp]--;mem[reg[esp]]=inp;}
  void pop(int&dest){dest=mem[reg[esp]];reg[esp]++;}
  void call(const int&addr){
    push(reg[eip]);
    jmp(addr);
    reg[debug_depth]++;// mem[ebp]==old_ebp; mem[mem[reg[ebp]]-1]-1==call_ip
  }
  void ret(){pop(reg[eip]);jmp(reg[eip]);reg[debug_depth]--;/*for(int i=reg[esp]-1;i>=0;i--)mem[i]=0;*/}
  void nop(){}
  void label(){}
  void CatmullRomEx(){
    int pos_param=1+6;
    #define F(p)auto&p=mem[reg[ebp]+pos_param--];
    F(p1)F(p2)F(p3)F(p4)F(t)F(z);
    #undef F
    reg[eax]=native_CatmullRomEx(p1,p2,p3,p4,t,z);
  }
  int native_hypot(int x,int y){return ::sqrt(double(x*x+y*y));}
  int native_CatmullRomEx(int p1,int p2,int p3,int p4,int t,int z){
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
  void CatmullRom()
  {
    int pos_param=1+11;
    #define F(p)auto&p=mem[reg[ebp]+pos_param--];
    F(addr)F(ax_)F(ay_)F(bx)F(by)F(cx)F(cy)F(dx_)F(dy_)F(t)F(z)
    #undef F
    int ax=ax_;int ay=ay_;int dx=dx_;int dy=dy_;
    int m=native_hypot(bx-cx,by-cy);
    {
      int x=ax-bx;
      int y=ay-by;
      int d=native_hypot(x,y);
      if(d)
      {
        ax=bx+m*x/d;
        ay=by+m*y/d;
      }
    }
    {
      int x=dx-cx;
      int y=dy-cy;
      int d=native_hypot(x,y);
      if(d)
      {
        dx=cx+m*x/d;
        dy=cy+m*y/d;
      }
    }
    int out_x=native_CatmullRomEx(ax,bx,cx,dx,t,z);
    int out_y=native_CatmullRomEx(ay,by,cy,dy,t,z);
    int p=addr;
    mem[p++]=out_x;
    mem[p++]=out_y;
    reg[eax]=p;
  }
  static string cmd2body(int id){
    int cur_id=0;
    #define F(BODY)if(id==cur_id++){return #BODY;};;
    CMDS(F);
    #undef F
    return "";
  }
  static string reg2str(int id)
  {
    int cur_id=0;
    #define F(REG)if(id==cur_id++)return #REG;
    DEF_PRO_REGISTERS(F);
    #undef F
    return "[... error in reg2str ...]";
  }
  string ptrreg2str(int id){
    return "ptr["+reg2str(id)+"]";
  }
  string mem2str(int id){return "mem["+IToS(id)+"]";}
  string cmd2str(t_cmd cmd)
  {
    auto s=cmd2body(cmd.id);
    auto sxraw=[](string s,string b){return s+"["+b+"]";};
    auto sxreg=[](string s,string b){return s+"["+b+"]";};
    auto sxptr=[](string s,string b){return s+"("+b+")";};
    auto sxmem=[](string s,string b){return s+"["+b+"]";};
    #define PRO_F(CMD,CONV,dest)s=join(split(s,sx##CMD(#CMD,#dest)),CONV(__if_not_exists(t_cmd::dest){cmd.a}__if_exists(t_cmd::dest){cmd.dest}));
    #define LIST(CMD,CONV,F)F(CMD,CONV,dest)F(CMD,CONV,src)F(CMD,CONV,a)F(CMD,CONV,b)
    LIST(raw,IToS,PRO_F);
    LIST(reg,reg2str,PRO_F);
    LIST(ptr,ptrreg2str,PRO_F);
    LIST(mem,mem2str,PRO_F);
    #undef LIST
    #undef PRO_F
    s=join(split(s,"+-"),"-");
    return s;
  }
  struct t_raw_const{int operator[](int value)const{return value;}};
  struct t_ptr_proxy{vector<int>&mem;int&operator[](int addr)const{return mem[addr];}};
  void new_exec(const t_cmd&cmd)
  {
    static const t_raw_const raw;static const t_ptr_proxy ptr={mem};
    auto&dest=cmd.dest;
    auto&src=cmd.a;
    auto&a=cmd.a;
    auto&b=cmd.b;
    int cur_id=0;
    const int base_counter=__COUNTER__+1;
    switch(cmd.id)
    {
      #define ptr(REG)mem[reg[REG]]
      #define F(BODY)case __COUNTER__-base_counter:{BODY;break;};;
      CMDS(F);
      #undef F
      #undef ptr
    }
  }
  string ip2str(int ip)
  {
    if(!qap_check_id(arr2str,ip))return qap_check_id(arr,ip)?cmd2str(arr[ip]):"...[ip="+IToS(ip)+"]...";
    return arr2str[ip];
  }
  void sim_n(int n)
  {
    for(int i=0;i<n;i++)
    {
      auto ip=reg[eip]++;
      if(total_iters>=0)
      {
        total_iters++;
        auto f=[](string s,int n)->string{pad_bef(s,n);return s;};
        auto r=[&](int xxx){return f(IToS(reg[xxx]),6);};
        auto comment=[](string s){return "/* "+s+" */  ";};
        auto d=comment(f(IToS(reg[debug_depth]),3))+ip2str(ip);pad(d,60);
        qap_add_back(iplog)=d+" // "+r(ebp)+"  "+r(esp)+" ;  "+(reg[ebp]==dno?"dno":ip2str(mem[reg[ebp]+1]-1));
      }
      //if(651==total_iters){
      //  fuck_u_debugger();
      //}
      //if(ip==818){
      //  auto cmd=ip2str(ip);
      //  int gg=1;
      //}
      if(!qap_check_id(arr,ip))QapNoWay();
      //static bool need_debug=true;
      //#define F(offset)ip2str(ip+(offset));
      //string cmdprev2=F(-2);
      //string cmdprev1=F(-1);
      //string cmdthis0=F(-0);//---
      //string cmdnext1=F(+1);
      //string cmdnext2=F(+2);
      //string cmdnext3=F(+3);
      //string cmdnext4=F(+4);
      //#undef F
      //if(this->reg[cmd_counter]==260||this->reg[cmd_counter]==1060){
      //  int gg=1;
      //}
      //if(reg[debug_depth]==3){
      //  int gg=1;
      //  if(mem[reg[ebp]-2]==3){
      //    int gg=1;
      //  }
      //}
      //if(reg[debug_depth]==2){
      //  int gg=1;
      //}
      //if(reg[debug_depth]==1){
      //  int gg=1;
      //}
      //if(reg[debug_depth]==0){
      //  int gg=1;
      //}
      //if(cmdprev1=="call(\"streq\")"){
      //  int gg=1;
      //}
      //if(cmdprev1=="call(\"get_int\")"){
      //  int gg=1;
      //}
      //if(cmdprev1=="call(\"get_byte\")"){
      //  int gg=1;
      //}
      new_exec(arr[ip]);
      reg[cmd_counter]++;
    }
  }
  void sim_till_err()
  {
    for(;!reg[err];)sim_n(1);
    int gg=1;
  }
  
  static int max_str_size_in_vec_of_str(const vector<string>&arr){int max=-1;for(int i=0;i<arr.size();i++)max=std::max<int>(max,arr[i].size());return max;}
  static void vec_pad(vector<string>&arr,int pad_to){for(int i=0;i<arr.size();i++)pad(arr[i],pad_to);}
 
  #ifndef CL_WITHOUT_ASM_APP
  #include "pro_app_build_impl.inl"
  struct t_mash_code_provider:public t_app_builder
  {
    void proc(const string&s){label(s);}
    #define REG_SCOPE()t_reg_scope scope(this);
    struct t_reg_scope{
      t_app_builder*p;
      #define F(REG)p->push(reg[REG]);
      t_reg_scope(t_app_builder*p):p(p){t_reg reg(p->ctti);F(eax)F(ebx)F(ecx)F(edx)}
      #undef F
      #define F(REG)p->pop(reg[REG]);
     ~t_reg_scope(){t_reg reg(p->ctti);F(edx)F(ecx)F(ebx)F(eax)}
      #undef F
      #undef LIST
    };

    #define DEF_PRO_PROXY_REG(NAME)auto&NAME=reg[::NAME];

    void move_from(t_mash_code_provider*other){
      auto&arr=other->out;
      for(int i=0;i<arr.size();i++)qap_add_back(out)=std::move(arr[i]);
    }

    int calc_header_size(){int int_size=ctti.type2size("int");return int_size+int_size;}// esp_old=esp;push(eip); push(ebp);return abs(esp_old-esp);
    int get_header_size(){static int header_size=calc_header_size();return header_size;}

    struct t_proc_scope{
      typedef t_mash_code_provider t_prov;
      string name;
      int&pos_param;
      t_prov*prov;
      t_proc_scope(t_prov*prov,const string&name,int&pos_param):prov(prov),name(name),pos_param(pos_param){start();}
      ~t_proc_scope(){finish();}
      int get_params_size(const vector<string>&arr){
        int out=0;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          out+=prov->ctti.type2size(ex);
        }
        return out;
      }
      int get_params_size(const string&s){return get_params_size(split(s,","));}
      void start(){
        auto&ctti=prov->ctti;
        #include "asm_header.inl"
        if(split(name,"(").size()>1)
        {
          //pos_param+=
          pos_param=get_params_size(split(split(name,"(")[1],")")[0]);
        }
        prov->proc(name);
        prov->push(ebp);
        prov->mov(ebp,esp);
      }
      void finish(){
        auto&ctti=prov->ctti;
        #include "asm_header.inl"
        prov->label(name+"::ret");
        prov->mov(esp,ebp);
        prov->pop(ebp);
        prov->ret();
      }
      struct t_ret{
        t_proc_scope*owner;
        t_ret(t_proc_scope*owner):owner(owner){};
        void operator()(){owner->prov->jmp(owner->name+"::ret");}
      };
    };

    struct t_var_scope{
      typedef t_mash_code_provider t_prov;
      int&pos_var;
      t_prov*prov;
      int size;
      t_var_scope(t_prov*prov,int&pos_var,int size):prov(prov),pos_var(pos_var),size(size){start();}
      ~t_var_scope(){finish();}
      void start(){
        auto&ctti=prov->ctti;
        #include "asm_header.inl"
        pos_var+=size;
        if(1==size){prov->dec(esp);}else{prov->sub(esp,size);}
      }
      void finish(){
        auto&ctti=prov->ctti;
        #include "asm_header.inl"
        pos_var-=size;
        if(1==size){prov->inc(esp);}else{prov->add(esp,size);}
      }
    };

    struct t_caller_scope{
      typedef t_mash_code_provider t_prov;
      int&pos_var;
      t_prov*prov;
      int old_pos;
      t_caller_scope(t_prov*prov,int&pos_var):prov(prov),pos_var(pos_var){start();}
      ~t_caller_scope(){finish();}
      void start(){
        old_pos=pos_var;
        prov->esp_info.caller_scope_bef();
      }
      //static bool mode(){return file_get_contents("caller_scope_mode.txt").size();}
      void finish(){
        auto&ctti=prov->ctti;
        #include "asm_header.inl"
        prov->esp_info.caller_scope_aft();
        //static const int k=mode()?+1:-1;
        QapAssert(pos_var==old_pos);
        prov->add(esp,old_pos-pos_var+prov->esp_info.n);
      }
    };
    struct t_loop_scope{
      typedef t_mash_code_provider t_prov;
      t_prov*prov;
      int beg_eip;
      t_loop_scope(t_prov*prov):prov(prov){start();}
      ~t_loop_scope(){finish();}
      void start(){
        beg_eip=prov->out.size();
      }
      void finish(){
        auto&ctti=prov->ctti;
        #include "asm_header.inl"
        prov->loop(beg_eip);
      }
    };
    struct t_result{
      t_ctti&ctti;
      int phs;
      int&pos_param;
      string type;
      int offset;
      t_result(t_ctti&ctti,int phs,int&pos_param,const string&type):ctti(ctti),phs(phs),pos_param(pos_param),type(type),offset(0){start();}
      void reserve_mem_for_result(const string&type){pos_param+=ctti.type2size(type);}
      void start(){
        reserve_mem_for_result("int");
        pos_param-=ctti.type2size("int");
        offset=pos_param;
      }
      t_ptr_reg_offset get_presult(){
        #include "asm_header.inl"
        return ptr[ebp+(phs+offset)].set_type("int");
      }
    };
    #define LOOP_SCOPE()t_loop_scope loop_scope(this);
    #define CALLER_SCOPE()t_caller_scope caller_scope(this,pos_var);
    #define STRUCT(NAME)qap_add_back(ctti.structs).name=NAME;
    #define FIELD(TYPE,NAME)qap_add_back(ctti.structs.back().fields).set(TYPE,NAME);
    #define proc(NAME)int pos_member=0;int pos_var=0;int pos_param=0;t_proc_scope proc_scope(this,NAME,pos_param);t_proc_scope::t_ret ret(&proc_scope);
    #define VAR_THIS_PTR()VAR("int",this_ptr);mov(this_ptr,ecx);
    #define VAR(TYPE,NAME)t_var_scope varscope_##NAME(this,pos_var,ctti.type2size(TYPE));auto NAME=ptr[ebp-pos_var].set_type(TYPE);
    #define PARAM(TYPE,NAME)pos_param-=ctti.type2size(TYPE);QapAssert(pos_param>=0);auto NAME=ptr[ebp+(phs+pos_param)].set_type(TYPE);
    #define PARAM_RESULT(TYPE)t_result result(ctti,phs,pos_param,TYPE);//pos_param+=ctti.type2size(TYPE);PARAM(TYPE,result);
    #define MEMBER(TYPE,NAME)auto NAME=ptr[ecx+pos_member].set_type(TYPE);pos_member+=ctti.type2size(TYPE);
    void copy(t_ptr_reg_offset&dest,int src){
      QapAssert(dest.type=="int");
      mov(dest,src);
    }
    void copy(t_ptr_reg_offset&dest,t_reg&src){
      QapAssert(dest.type=="int");
      mov(dest,src);
    }
    void copy(t_result&dest,t_reg&src)
    {
      #include "asm_header.inl"
      mov(edx,dest.get_presult());
      auto res=ptr[edx+0].set_type(dest.type);
      copy(res,src);
    }
    void copy(t_result&dest,int src)
    {
      #include "asm_header.inl"
      mov(edx,dest.get_presult());
      auto res=ptr[edx+0].set_type(dest.type);
      copy(res,src);
    }
    void copy(t_result&dest,t_ptr_reg_offset&src)
    {
      #include "asm_header.inl"
      mov(edx,dest.get_presult());
      auto res=ptr[edx+0].set_type(dest.type);
      copy(res,src);
    }
    void copy(t_ptr_reg_offset&dest,t_ptr_reg_offset&src){
      QapAssert(dest.type==src.type);
      push(src);pop(dest);
      //auto n=ctti.type2size(dest.type);
      //auto tmpd=dest;tmpd.type="int";
      //auto tmps=src; tmps.type="int";
      //for(int i=0;i<n;i++){
      //  push(tmps);
      //  pop(tmpd);
      //  tmpd.offset++;
      //  tmps.offset++;
      //}
    }
    void pushlea(t_ptr_reg_offset&ref){
      auto&self=*(t_app_builder*)this;
      self.pushlea(ref);
      self.esp_info.n++;
    }
    void push(t_ptr_reg_offset&ref){
      auto&self=*(t_app_builder*)this;
      auto n=ctti.type2size(ref.type);
      auto tmp=ref;tmp.type="int";tmp.offset+=n;
      for(int i=0;i<n;i++){
        tmp.offset--;
        self.push(tmp);
      }
      self.esp_info.n+=n;
    }
    void push(int value){
      auto&self=*(t_app_builder*)this;
      self.push(value);
      self.esp_info.n++;
    }
    void push(t_machine::t_reg&value)
    {
      auto&self=*(t_app_builder*)this;
      self.push(value);
      self.esp_info.n++;
    }
    void check_pop_allowed(){QapAssert(!esp_info.inside_call_scope);}
    void pop()
    {
      check_pop_allowed();
      QapNoWay();
    }
    void pop(t_ptr_reg_offset&ref){
      check_pop_allowed();
      auto&self=*(t_app_builder*)this;
      auto n=ctti.type2size(ref.type);
      auto tmp=ref;tmp.type="int";
      for(int i=n-1;i>=0;i--){
        self.pop(tmp);
        tmp.offset++;
      }
    }
    void pop(int&value){
      check_pop_allowed();
      auto&self=*(t_app_builder*)this;
      self.pop(value);
    }
    void pop(t_machine::t_reg&value)
    {
      check_pop_allowed();
      auto&self=*(t_app_builder*)this;
      self.pop(value);
    }
    void asmogovno()
    {
      #include "asm_header.inl"
      int phs=get_header_size();
      //int forid=1000;
      //string s;
      //int gg=1;

      jmp("begin");

      if(1)
      {
        #include "asmogovno.inl"
      }else{
        {proc("func_new_main()"){
          ret();
        }}
      }
      ////---------------------
      label("begin");
      if(0)
      {
        mov(eax,0);
        mov(ebx,0);
        call("func_new_main()");
        add(esp,2);
      }else
      {
        int pos_var=0;
        VAR("int",var_eax);
        pushlea(var_eax);
        push(ecx);
        call("func_main(int)");
        add(esp,2);
        mov(eax,var_eax);
      }
      mov(err,1);
    }
    //void Less(t_ptr_reg_offset&flag,t_ptr_reg_offset&i,t_ptr_reg_offset&n){DEF_PRO_VSE_PIZDEC();mov(eax,i);mov(ebx,n);less(edx,eax,ebx);mov(flag,edx);}
  };

 void def_app_raw()
  {
    t_mash_code_provider prov;
    prov.asmogovno();
    arr=prov.get();
    labels.clear();
    {
      auto&out=prov.out;labels.resize(out.size());
      for(int i=0;i<out.size();i++){
        if(out[i]->is_lable())if(auto*p=(t_label*)out[i].get())labels[i]=p->name;
      }
    }
  }
  struct t_def_app_result{
    vector<string> out;vector<string> note;
  };
  t_def_app_result def_app()
  {
    def_app_raw();
    t_def_app_result result;auto&out=result.out;auto&note=result.note;
    for(int i=0;i<arr.size();i++){
      out.push_back(arr[i].to_source());
      auto cmd=cmd2str(arr[i]);
      if(cmd=="label()"){
        cmd="label(\""+labels[i]+"\")  //"+IToS(i);
      }
      auto f=[&](string&cmd,string bef,string aft){
        auto tmp=split(cmd,bef);
        if(tmp.size()>1){
          auto tmp2=split(tmp[1],aft);
          auto strid=tmp2[0];
          cmd=bef+"\""+labels[SToI(strid)]+"\""+aft+joinwithoutfirst(tmp2,aft);
        }
      };
      f(cmd,"call(",")");
      f(cmd,"jmp(",")");
      f(cmd,"jz(",",");
      f(cmd,"jnz(",",");
      qap_add_back(note)=" // "+cmd;
      qap_add_back(arr2str)=cmd;
    }
    int ms=max_str_size_in_vec_of_str(out);
    vec_pad(out,ms);
    for(int i=0;i<out.size();i++)out[i]+=note[i];
    string code=join(out,"\n"); // CODE <<--------------------------<<<<<<<<<<<<<<<<<-----------------
    file_put_contents("asm_app.txt.inl",code);
    file_put_contents("asm.txt.inl",join(arr2str,"\n"));
    num_of_registers;
    int end=code.size();
    return result;
  }
  #endif
  void load_mashkod()
  {
    auto fc=file_get_contents("mashkod.txt");
    if(fc.empty())return;
    auto lines=split(fc,"\n");
    QapAssert(lines[0]=="/*");
    arr.clear();int id=-1;
    for(int i=0;i<lines.size();i++){
      auto&ex=lines[i];
      if(ex=="/*")continue;
      if(ex=="*/"){id=i;break;}
      qap_add_back(arr).from_nums(ex);
    }
    if(id<0)return;
    for(int i=id+1;i<lines.size();i++){
      auto&ex=lines[i];
      qap_add_back(arr2str)=lines[i];
    }
  }
  string get_mashkod()
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      out.push_back(arr[i].to_nums());//
    }
    return "/*\n"+join(out,"\n")+"\n*/\n"+join(arr2str,"\n");
  }
  static string joinwithoutfirst(const vector<string>&arr,const string&glue){
    auto tmp=arr;
    QapPopFront(tmp);
    return join(tmp,glue);
  }
  int write_to(int addr,const vector<int>&arr){for(int i=0;i<arr.size();i++)mem[addr+i]=arr[i];return addr+arr.size();}
  string read_str(int addr,int size){
    string out;
    if(size<=0)return out;
    out.resize(size*sizeof(int));
    int*p=(int*)&out[0];
    for(int i=0;i<size;i++){
      *p=mem[i+addr];
      p++;
    }
    return out;
  }
  static vector<int> str2arr(const string&s)
  {
    vector<int> out;
    out.resize(s.size()/4+Sign<int>(s.size()%4),0);
    //out[0]=s.size();
    if(s.empty())return out;
    char*p=(char*)&out[0];
    for(int i=0;i<s.size();i++){
      p[i]=s[i];
    }
    return out;
  }
};

//static int doit=t_machine::main();

struct t_line{
  #define DEF_PRO_CLASSNAME()t_line
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2i,a,$)\
  ADD(vec2i,b,$)\
  //===
  #include "defprovar.inl"
  //===
};

struct qap_vertex{
  #define DEF_PRO_CLASSNAME()qap_vertex
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(QapColor,color,$)\
  ADD(vec2i,pos,$)\
  //===
  #include "defprovar.inl"
  //===
};

struct qap_mesh{
  #define DEF_PRO_CLASSNAME()qap_mesh
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<qap_vertex>,VA,$)\
  ADD(vector<int>,IA,$)\
  //===
  #include "defprovar.inl"
  //===
};

struct t_vm_input{
  #define DEF_PRO_CLASSNAME()t_vm_input
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vec2i,mpos,$)\
  ADD(int,zDelta,$)\
  ADD(vector<int>,kb_down,$)\
  ADD(vector<int>,kb_changed,$)\
  //===
  #include "defprovar.inl"
  //===
  void load(QapKeyboard&kb){
    static const int n=QapKeyboard::TKeyState::MAX_KEY;
    kb_down.resize(n);
    kb_changed.resize(n);
    for(int i=0;i<n;i++)kb_down[i]=kb.Down[i];
    for(int i=0;i<n;i++)kb_changed[i]=kb.Changed[i];
  }
};
#ifndef CL_ASM_APP
class TGame:public TQapGameV2{
public:
  #include "cam_code.inl"
public:
  #define DEF_PRO_CLASSNAME()TGame
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(bool,need_init,true)\
  ADD(t_cam,cam,$)\
  ADD(t_machine,vm,$)\
  ADD(int,zPos,0)\
  ADD(int,text_size,16)\
  ADD(real,time_inp,$)\
  ADD(real,time_sim,$)\
  ADD(real,time_out,$)\
  ADD(bool,vm_debbuger,true)\
  ADD(bool,pause,true)\
  ADD(bool,show_last_output,true)\
  ADD(bool,view_at_eip,true)\
  ADD(bool,cam_kb_enabled,false)\
  ADD(string,last_output,$)\
  ADD(char,mode,'O')\
  //===
  #include "defprovar.inl"
  //===
public:
public:
  ~TGame(){on_free();}
  void sys_load(){QapLoadFromStrWithSizeOfType(*this,file_get_contents("game.bin"));}
  void sys_save(){file_put_contents("game.bin",QapSaveToStrWithSizeOfType(*this));}
  void on_init(){need_init=false;set_to_def();sys_load();need_init=false;}
  void on_free(){if(false)sys_save();}
  void try_set_to_def(){if(need_init){need_init=false;set_to_def();}}
  void set_to_def()
  {
    srand(0*time(0));
    //cam.pos=vec2d(1,1)*360;
    cam.pos=vec2d_zero;
    cam.scale=1.0/4.0;
    if(true)
    {
      vm=t_machine();
      vm.mem.resize(1024*1024*4);
      vm.reg.resize(num_of_registers);
      vm.reg[err]=1;
      vm.dno=1024*16;
      vm.reg[esp]=vm.dno;
      vm.reg[ebp]=vm.dno;
      
      #ifndef CL_WITHOUT_ASM_APP
        vm.def_app();
      #else
        vm.load_mashkod();
        vm_debbuger=false;
        pause=false;
      #endif
      //
    }
    srand(0*time(0));
    int gg=1;
  }
public:
  //#include "special_cd_func.inl"
public:
  void inv(bool&flag){flag=!flag;}
  void DoPreMove()
  {
    try_set_to_def();
    if(kb.Down[VK_ESCAPE])win.Close();
    if(kb.OnDown(VK_F4)&&kb.Down(VK_CONTROL))need_init=true;
    if(kb.OnDown(VK_F1)&&kb.Down(VK_CONTROL))inv(cam_kb_enabled);
    if(kb.OnDown(VK_F5)&&kb.Down(VK_SHIFT))inv(vm_debbuger);
    if(kb.OnDown(VK_F1)&&kb.Down(VK_SHIFT))inv(show_last_output);
    if(kb.OnDown(VK_F2)&&kb.Down(VK_SHIFT))inv(view_at_eip);
    if(kb.OnUp(VK_PAUSE))inv(pause);
    if(cam_kb_enabled)cam_kb_move();
    //do_cd();
    //for(int i=0;i<arr.size();i++)arr[i].move();
    if(vm_debbuger)move_debugger();
  }
  void DoPreDraw()
  {
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    qDev.SetColor(0xff000000);
    //
    //{
    //  OFFCENTRIC_SCOPE_IMPL();
    //  for(int i=0;i<arr.size();i++){
    //    qDev.SetColor(arr[i].vm.reg[encolor]);
    //    qDev.DrawSolidCircle(arr[i].pos,r,8,0);
    //  }
    //  for(int i=0;i<foods.size();i++)qDev.DrawQuad(foods[i].pos,4,4);
    //}
    {
      draw_vm(qDev);
    }
    if(vm_debbuger)draw_debugger();
    //
    qDev.SetColor(0xff000000);
    DrawDownedKeys();
  }
  void move_debugger()
  {
    auto&gas=vm.arr2str;
    zPos-=Sign(win.zDelta)*64;
    if(kb.OnDown(VK_HOME))zPos=0;
    if(!cam_kb_enabled){
      if(kb.OnDown(VK_UP))zPos-=viewport.size.y/16;
      if(kb.OnDown(VK_DOWN))zPos+=viewport.size.y/16;
    }
    if(kb.OnDown(VK_NEXT))zPos+=viewport.size.y-32;
    if(kb.OnDown(VK_PRIOR))zPos-=viewport.size.y-32;
    if(kb.OnDown(VK_HOME))zPos=0;
    if(kb.OnDown(VK_END))zPos=(gas.size())*16-viewport.size.y/2;
    //
    if(kb.OnDown(VK_F10))vm_step('S');
    if(kb.OnDown(VK_F11)&&!kb.Down(VK_SHIFT))vm_step('I');
    if(kb.OnDown(VK_F11)&&kb.Down(VK_SHIFT))vm_step('O');
  }
  void vm_inp()
  {
    QapClock clock;clock.Start();
    auto p=/*cam.pos+*/mpos;
    vm.reg[err]=0;
    vm.reg[eip]=0;
    vm.reg[eax]=p.x;
    vm.reg[ebx]=p.y;
    vm.reg[edx]=0;
    vm.reg[esp]=vm.dno;
    vm.reg[ebp]=vm.dno;
    vm.reg[cmd_counter]=0;
    t_vm_input vm_input;
    vm_input.load(kb);
    vm_input.mpos=vec2i(p.x,p.y);
    vm_input.zDelta=win.zDelta;
    auto str_inp=QapSaveToStr(vm_input);
    const int inp_addr=1024*64;
    vm.reg[ecx]=inp_addr;
    vm.write_to(inp_addr,vm.str2arr(str_inp));
    time_inp=clock.MS();
    time_sim=0;
  }
  void vm_before_step()
  {
    if(vm.reg[err]==1)vm_inp();
  }
  void vm_after_step()
  {
    if(vm.reg[err]==-1)
    {
      auto csstr=join(get_vm_callstack(),"\n");
      int gg=csstr.size();
      QapDebugMsg("callstack:\n"+csstr);
      vm.reg[err]=0;
    }
    if(vm.reg[err]==1)
    {
      int gg=1;
      vm_out();
    }
    if(view_at_eip)
    {
      //x=zPos+i*k+750/2; top=+wh.y/2; low=-wh.y/2;
      int dy=-16;
      int y=750/2+dy*10;
      zPos=-(vm.reg[eip]*dy+y);
    }
  }
  void vm_step(char mode='S')// 'O' = out; 'S' = step; 'I' = into;
  {
    if(vm.arr.empty())return;
    this->mode=mode;
    vm_before_step();
    auto&depth=vm.reg[debug_depth];
    auto cur_depth=depth-(mode=='O'?1:0);
    QapClock clock;clock.Start();
    for(;;){
      vm.sim_n(1);
      if(mode=='I'||vm.reg[err]||cur_depth>=depth)break;
    }
    time_sim+=clock.MS();
    vm_after_step();
  }
  int draw_debugger(int offset=10)
  {
    auto&gas=vm.arr2str;int first=-1;int last=-1;
    for(int i=0;i<gas.size();i++){
      auto&ex=gas[i];
      auto pos=vec2d(-600,zPos+750/2-offset*16);offset++;
      auto this_is_eip=i==vm.reg[eip];
      if(viewport.clamp(pos)!=pos)continue;
      if(first<0)first=i;last=i;
      string prefix=this_is_eip?"->  ":"";
      auto s=pad_bef(IToS(i),6)+"   "+pad(prefix,4)+ex;
      bool deaded=false;
      qDev.color=deaded?0xff808080:0xff000000;
      qap_text::draw(qDev,pos,s,text_size);
    }
    auto draw_scrollbar=[&](int ip,int ys_mode)->void
    {
      if(gas.empty())return;
      auto wh=viewport.size;
      real ap=real(ip)/gas.size();
      real ys=first-last?real(first-last)*wh.y/gas.size():15;
      if(ys_mode>0)ys=ys_mode;
      qDev.DrawQuad(vec2i(-wh.x/2+9,wh.y/2-ap*wh.y),5,ys);
      qDev.color=QapColor::HalfMix(qDev.color,0xff808080);
      qDev.DrawQuad(vec2i(-wh.x/2+9,wh.y/2-ap*wh.y),3,ys-2);
    };
    qDev.color=0xff000000;
    if(gas.size())draw_scrollbar((first+last)/2,-1);
    qDev.color=0xffaa0000;
    draw_scrollbar(vm.reg[eip],8);
    return offset;
  }
  void vm_out()
  {
    if(vm.reg[err]!=1)return;
    if(1==total_iters){
      fuck_u_debugger();
    }
      //t_vm_native&vmn=get_vmn(&vm);vm.reg[eax]=vmn.main(p.x,p.y);  
    auto head=vm.reg[eax];
    auto size=vm.reg[ebx];
    last_output=vm.read_str(head,size);
    if(bool need_debug=false)if(!last_output.empty()){
      qap_mesh m;
      QapLoadFromStr(m,last_output);
      int gg=1;
    }
  }
  void draw_vm(QapDev&qDev)
  {
    total_iters=-1;
    if(!pause)
    {
      vm_step(mode);
    }
    QapClock clock;clock.Start();
    if(!last_output.empty()&&show_last_output)
    {
      OFFCENTRIC_SCOPE_IMPL();
      qap_mesh m;
      QapLoadFromStr(m,last_output);
      QapDev::BatchScope Scope(qDev);
      {
        auto&VA=m.VA;auto&IA=m.IA;
        int base=qDev.VPos;
        for(int i=0;i<VA.size();i++)
        {
          auto&p=VA[i];
          qDev.AddVertex(p.pos,p.color,0,0);
        }
        for(int i=0;i<IA.size();i+=3)qDev.AddTris(base+IA[i+0],base+IA[i+1],base+IA[i+2]);
      }
    }
    auto time_out=clock.MS();clock.Stop();clock.Start();
    int vm_ins=vm.reg[cmd_counter];
    int y=viewport.size.y/2-16;int dy=-16;
    qap_text::draw(qDev,vec2d(+viewport.size.x/2-160,y),"vm_ins = "+IToS(vm_ins),text_size);y+=dy;
    qap_text::draw(qDev,vec2d(+viewport.size.x/2-160,y),"time_inp = "+FToS(time_inp)+" ms",text_size);y+=dy;
    qap_text::draw(qDev,vec2d(+viewport.size.x/2-160,y),"time_sim = "+FToS(time_sim)+" ms",text_size);y+=dy;
    qap_text::draw(qDev,vec2d(+viewport.size.x/2-160,y),"time_out = "+FToS(time_out)+" ms",text_size);y+=dy;
    if(this->vm_debbuger)
    {
      auto arr=get_vm_callstack();
      y=viewport.size.y/2-16;
      for(int i=0;i<arr.size();i++){qap_text::draw(qDev,vec2d(+viewport.size.x/2-720,y),arr[i],text_size);y+=dy;}
    }
    if(this->vm_debbuger)
    {
      auto arr=get_vm_regs_values();reverse(arr);
      y=-viewport.size.y/2+32;1;
      for(int i=0;i<arr.size();i++){qap_text::draw(qDev,vec2d(+viewport.size.x/2-520,y),arr[i],text_size);y-=dy;}
    }
    if(this->vm_debbuger)
    {
      auto arr=get_vm_stack_values();//reverse(arr);
      y=-viewport.size.y/2+32;
      for(int i=0;i<arr.size();i++){qap_text::draw(qDev,vec2d(+viewport.size.x/2-210,y),arr[i],text_size);y-=dy;}
    }
  }



  vector<string> get_vm_callstack()
  {
    auto&reg=vm.reg;auto&mem=vm.mem;
    vector<string> callstack;
    int ebp_value=reg[ebp];
    int eip_value=reg[eip];
    for(;;)
    {
      qap_add_back(callstack)=pad_bef(IToS(eip_value),6)+" ;  "+(ebp_value==vm.dno?"dno":vm.ip2str(mem[ebp_value+1]-1));
      if(ebp_value==vm.dno)break;
      eip_value=mem[ebp_value+1];
      ebp_value=mem[ebp_value];
    }
    return callstack;
  }
  vector<string> get_vm_regs_values()
  {
    vector<string> out;
    for(int i=0;i<vm.reg.size();i++){
      qap_add_back(out)=vm.reg2str(i)+" = "+IToS(vm.reg[i]);
    }
    return out;
  }
  vector<string> get_vm_stack_values()
  {
    vector<string> out;
    int ebp_value=vm.reg[ebp];
    int esp_value=vm.reg[esp];
    int offset=0;
    for(int i=5;i;i--)
    {
      qap_add_back(out)="ptr[ebp+"+IToS(i)+"] = "+IToS(vm.mem[ebp_value+i]);
    }
    for(int i=esp_value;i<=ebp_value;i++)
    {
      qap_add_back(out)="ptr[ebp-"+IToS(offset)+"] = "+IToS(vm.mem[ebp_value-offset]);
      offset++;
    }
    return out;
  }
};
int main(){
  TGame builder;
  builder.DoNice();
  return 0;
}
#else
int main(){
  t_machine m;
  m.def_app();
  auto str=m.get_mashkod();
  file_put_contents("mashkod.txt",str);
}
#endif
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  auto cmdline=string(GlobalEnv::Get().lpCmdLine);
  auto last_param=cmdline.empty()?"":split(cmdline," ").back();
  if(last_param=="REGS_AND_CMDS")
  {
    vector<string> out;
    for(int i=0;i<num_of_registers;i++)qap_add_back(out)=t_machine::reg2str(i);
    auto text=join(out,",");
    out.clear();qap_add_back(out)=text;
    for(int i=0;out.back().size();i++)qap_add_back(out)=t_machine::cmd2body(i);
    out.pop_back();
    text=join(out,"\n");
    file_put_contents("regs_and_cmds.txt",text);
    TerminateProcess(GetCurrentProcess(),0);
  }
  main();
  return 0;
}
#endif
//<<<<<=====main
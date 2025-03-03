{
  {
    struct t_core{
      struct t_other{}
      real ee;
      string mem;// "TODO: string may be empty" - ok;
      int get_zero(){return 0;}
      void add(string s){mem+=s+"\n";}
    };
    t_core temp;
    t_core make_it(){return t_core();}
    auto e=make_it();
    t_core core=t_core();
    t_core::t_other other=t_core::t_other();
    int WTF=1;
    auto tmp=core.mem;
    core.mem+="";
    core.add("first");
    struct vec2d
    {
      struct t_other{}
      real x=0.0;
      real y=0.0;
      vec2d inv(){return vec2d(-x,-y);}
    };
    auto v=vec2d(0,0);
    string toStr(real v){return __FToS(v);}
    //string toStr(vec2d v){return "x: "+toStr(v.x)+"    "+"y: "+toStr(v.y);}
    auto msg=toStr(v);
    return "["+__cur_date_str()+"]: 2014.01.17 16:03 MSK\n"+msg;
  }
  {
    real a=__microtime();
    /*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
    string IToS(int a){return __IToS(a);}
    string add(string name,real value)  {return "  "+name+" = "+__FToS(value)+"\n";}
    string add(string name,int value)   {return "  "+name+" = "+__IToS(value)+"\n";}
    string add(string name,bool value)  {return "  "+name+" = "+__BToS(value)+"\n";}
    string add(string name,string value){return "  "+name+" = "+value+"\n";}
    real operator/(real a,int b){return a/__IToF(b);}
    real operator/(int a,real b){return __IToF(a)/b;}
    /*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
    int max_sqrt(int val)
    {
      for(int i=0;i<=val;i++){
        if(i*i>val)return i;
      }
      return val;
    }
    bool is_prime(int value)
    {
      int ms=max_sqrt(value);
      for(int i=2;i<ms;i++){
        if(value%i>0)continue;
        return false;
      }
      return true;
    }
    int near_prime(int value){
      for(int i=value;i>1;i--){
        if(is_prime(i))return i;
      }
      return -1;
    }
    string all_prime_in_dip(int offset,int end){
      string out;
      for(int i=offset;i<end;i++){
        if(!is_prime(i))continue;
        out+=__IToS(i)+"\n";
      }
      return out;
    }
    /*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
    int inp=32;
    int k=1000;
    real time=(__microtime()-a)/k;
    auto msg="BEGIN\n";
    msg+=add("time",(__microtime()-a)/k);
    msg+=add("inp",inp);
    a=__microtime();
    msg+=add("is_prime(inp)",is_prime(inp));
    msg+="\n"+add("time",(__microtime()-a)/k);
    a=__microtime();
    msg+=add("near_prime(inp)",near_prime(inp));
    msg+="\n"+add("time",(__microtime()-a)/k);
    msg+="END";
    a=__microtime();
    msg+="\n"+all_prime_in_dip(2,inp);
    msg+="\n"+add("time",(__microtime()-a)/k);
    return msg;
  }
}
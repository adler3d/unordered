struct t_proccessor_rule_gen{
  //G = read = 0
  //E = write = 1
  struct t_context{
    bool cmd;
    bool addr;
    bool value;
    bool a;
    bool b;
  };
  struct t_rule_gen{
    t_context&inp;
    t_context&out;
    void read()
    {
      const auto&flag=inp.addr?inp.b:inp.a;
      out.value=flag;
    }
    void write()
    {
      auto&flag=inp.addr?out.b:out.a;
      flag=inp.value;
    }
    void go()
    {
      out=inp;
      if(inp.cmd){write();}else{read();}
    }
  };

  struct bool5{
    bool arr[5];
    int get()
    {
      int result=0;
      for(int i=0;i<5;i++)result+=arr[i]<<i;
      return result;
    }
    void set(int value)
    {
      int result=0;
      for(int i=0;i<5;i++)arr[i]=(value>>i)%2;
      return result;
    }
    t_context&toContext(){
      return *(t_context*)(void*)this;
    }
    static void char_replace(string&str,char from,char to){
      for(int i=0;i<str.size();i++){if(str[i]==from)str[i]=to;
    }
    static char BoolToChar(bool flag){return flag?'E':'G';}
    string use(const string&s)
    {
      string str=s;
      for(int i=0;i<5;i++)char_replace(str,'0'+i,BoolToChar(arr[i]));
      return str;
    }
  };
public:
  static void start()
  {
    for(int i=0;i<(1<<5);i++){
      bool5 input,output;
      input.set(i);
      auto&inp=input.toContext();
      auto&out=output.toContext();
      t_rule_gen rule_gen={inp,out};
      rule_gen.go();
      if(inp==out)continue;
      "B2B1B0X\n"
      "OOOOOOO\n"
      "OB4Y3BO\n"

      "XB2B1B0\n"
      "OOOOOOO\n"
      "OB4Y3BO\n"
    }
  }
};
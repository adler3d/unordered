#include "vk_keys.inl"
class QapKeyboard
{
public:
  struct TKeyState
  {
    static const int MAX_KEY=263;
    bool data[MAX_KEY];
    TKeyState()
    {
      SetToDef();
    }
    void SetToDef()
    {
      for (int i=0;i<MAX_KEY;i++)data[i]=false;
    }
    bool&operator[](int index)
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    bool&operator()(int index)
    {
      if(!InDip<int>(0,index,MAX_KEY-1))
      {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    const bool&operator()(int index)const
  {
      if(!InDip<int>(0,index,MAX_KEY-1))
    {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
    }
      return data[index];
  }
    const bool&operator[](int index)const
  {
      if(!InDip<int>(0,index,MAX_KEY-1))
  {
        QapDebugMsg("bad index");
        static bool tmp;
        return tmp;
      }
      return data[index];
    }
    typedef TKeyState SelfClass;
    bool oper_eq(const SelfClass&ref)const{
      for(int i=0;i<lenof(data);i++)if(data[i]!=ref.data[i])return false;
      return true;
    }
    bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);}
    bool operator==(const SelfClass&ref)const{return oper_eq(ref);}
    bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}
  };
public:
  #define DEF_PRO_TEMPLATE_DATAIO()
  #define DEF_PRO_CLASSNAME()QapKeyboard
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(int,LastKey,0)\
  ADD(char,LastChar,0)\
  ADD(bool,News,false)\
  ADD(TKeyState,Down,$)\
  ADD(TKeyState,Changed,$)\
  //===
  #include "defprovar.inl"
  //===
public:
  void KeyUpdate(int Key,bool Value)
  {
    if(Value)LastKey=Key;
    Down[Key]=Value;
    Changed[Key]=true;
  }
  void CharUpdate(char c)
  {
    LastChar=c;
    News=true;
  }
  void Sync()
  {
    this->News=false;
    Changed.SetToDef();
  }
  bool OnDown(int index)const
  {
    return Changed[index]&&Down[index];
  }
  bool OnUp(int index)const
  {
    return Changed[index]&&!Down[index];
  }
  vec2d get_dir_from_wasd_and_arrows()const
  {
    vec2d dp=vec2d_zero;
    auto dir_x=vec2d(1,0);
    auto dir_y=vec2d(0,1);
    #define F(dir,key_a,key_b)if(Down[key_a]||Down[key_b]){dp+=dir;}
    F(-dir_x,VK_LEFT,'A');
    F(+dir_x,VK_RIGHT,'D');
    F(+dir_y,VK_UP,'W');
    F(-dir_y,VK_DOWN,'S');
    #undef F
    return dp;
  }
  bool operator()(const string&hotkey)const{
    if(hotkey.size()==1)return OnDown(hotkey[0]);
    auto arr=split(hotkey,"+");
    QapAssert(arr.size()==2&&arr[1].size()==1);
    bool ok=false;
    auto f=[&](const char*p,int key){if(LowerStr(p)==LowerStr(arr[0]))ok=Down(key);};
    f("ALT",VK_MENU);
    f("CTRL",VK_CONTROL);
    f("SHIFT",VK_SHIFT);
    return ok&&OnDown(arr[1][0]);
  }
  bool any_down(const string&keys){
    for(int i=0;i<keys.size();i++)if(Down[keys[i]]){
      //QapDebugMsg("pos:"+IToS(i)+"    charcode:"+IToS(keys[i])+"    char:"+keys.substr(i,1));
      return true;
    }
    return false;
  }
  enum t_arrows{arrows};
  bool any_down(const t_arrows&){
    #define F(key)if(Down[key])return true;
    F(VK_LEFT);
    F(VK_RIGHT);
    F(VK_UP);
    F(VK_DOWN);
    #undef F
    return false;
  }
};
enum TMouseButton
{
  mbLeft=257,
  mbRight=258,
  mbMiddle=259,
};
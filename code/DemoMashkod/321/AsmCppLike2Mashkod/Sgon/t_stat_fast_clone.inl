class t_clone_sys{
public:
  typedef TVoidPtr::TRawPtr TRawPtr;
  typedef t_simple_stat_lex::i_stat i_stat;
  typedef t_simple_stat_lex::i_expr i_expr;
public:
  #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
  F(t_without_add)
  #undef F
public:
  struct t_clone_stat_dev{
    IEnvRTTI&Env;
    vector<TAutoPtr<i_stat>*> stack;
    void push(TAutoPtr<i_stat>*ptr){stack.push_back(ptr);}
    void pop(TAutoPtr<i_stat>*ptr){QapAssert(!stack.empty());QapAssert(stack.back()==ptr);stack.pop_back();}
    TAutoPtr<i_stat>&get(){QapAssert(!stack.empty());return *stack.back();}
  };
  struct t_clone_expr_dev{
    IEnvRTTI&Env;
    vector<TAutoPtr<i_expr>*> stack;
    void push(TAutoPtr<i_expr>*ptr){stack.push_back(ptr);}
    void pop(TAutoPtr<i_expr>*ptr){QapAssert(!stack.empty());QapAssert(stack.back()==ptr);stack.pop_back();}
    TAutoPtr<i_expr>&get(){QapAssert(!stack.empty());return *stack.back();}
  };
  struct t_clone_shit_dev{
    IEnvRTTI&Env;
    vector<TAutoPtr<t_without_add::i_expr>*> stack;
    void push(TAutoPtr<t_without_add::i_expr>*ptr){stack.push_back(ptr);}
    void pop(TAutoPtr<t_without_add::i_expr>*ptr){QapAssert(!stack.empty());QapAssert(stack.back()==ptr);stack.pop_back();}
    TAutoPtr<t_without_add::i_expr>&get(){QapAssert(!stack.empty());return *stack.back();}
  };
public:
  class t_shit_visitor:public t_without_add::i_expr_visitor{
  public:
    t_clone_shit_dev&dev;
    t_shit_visitor(t_clone_shit_dev&dev):dev(dev){}
  public:
    void Do(t_char_expr*p){Go(p);}
    void Do(t_bool_expr*p){Go(p);}
    void Do(t_int_expr*p){Go(p);}
    void Do(t_string_expr*p){Go(p);}
    void Do(t_var_expr*p){Go(p);}
    void Do(t_block_expr*p){Go(p);}
    void Do(t_call_expr*p){Go(p);}
  public:
    template<class TYPE>
    void Go(TYPE*p){
      auto&dest=*dev.get().build<TYPE>(dev.Env);
      auto&source=*p;
      t_clone_sys::t_expr_visitor::clone(dev.Env,dest.body,source.body);
    }
  public:
    typedef TAutoPtr<t_without_add::i_expr> TAP;
    static void clone(IEnvRTTI&Env,TAP&dest,TAP&source){
      if(!source)return;
      t_clone_shit_dev dev={Env};
      dev.push(&dest);
      t_shit_visitor V(dev);
      source->Use(V);
    }
  };
public:
  class t_expr_visitor:public t_simple_stat_lex::i_expr_visitor{
  public:
    t_clone_expr_dev&dev;
    t_expr_visitor(t_clone_expr_dev&dev):dev(dev){}
  public:
    void Do(t_char_expr*p){
      auto&dest=*dev.get().build<t_char_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_bool_expr*p){
      auto&dest=*dev.get().build<t_bool_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_int_expr*p){
      auto&dest=*dev.get().build<t_int_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_string_expr*p){
      auto&dest=*dev.get().build<t_string_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_var_expr*p){
      auto&dest=*dev.get().build<t_var_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_block_expr*p){
      auto&dest=*dev.get().build<t_block_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_add_expr*p){
      auto&dest=*dev.get().build<t_add_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
    void Do(t_call_expr*p){
      auto&dest=*dev.get().build<t_call_expr>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }
  public:
    static void clone(IEnvRTTI&Env,t_char_expr&dest,t_char_expr&source){
      clone(Env,dest.body,source.body);
    }
    static void clone(IEnvRTTI&Env,t_bool_expr&dest,t_bool_expr&source){
      clone(Env,dest.value,source.value);
    }
    static void clone(IEnvRTTI&Env,t_int_expr&dest,t_int_expr&source){
      clone(Env,dest.value,source.value);
    }
    static void clone(IEnvRTTI&Env,t_string_expr&dest,t_string_expr&source){
      clone(Env,dest.body,source.body);
    }
    static void clone(IEnvRTTI&Env,t_var_expr&dest,t_var_expr&source){
      clone(Env,dest.name,source.name);
    }
    static void clone(IEnvRTTI&Env,t_block_expr&dest,t_block_expr&source){
      clone(Env,dest.body,source.body);
    }
    static void clone(IEnvRTTI&Env,t_add_expr&dest,t_add_expr&source){
      clone(Env,dest.arr,source.arr);
    }
    static void clone(IEnvRTTI&Env,t_call_expr&dest,t_call_expr&source){
      clone(Env,dest.func,source.func);
      clone(Env,dest.sep,source.sep);
      clone(Env,dest.params,source.params);
      //F(t_name,func);
      //F(t_sep,sep);
      //F(t_call_params,params);
    }
  public:
    #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
    F(t_string)
    F(t_call_params);
    F(t_call_param);
    //UG
    F(t_add_subexpr);
    #undef F
  public:
    static void clone(IEnvRTTI&Env,t_char_item&dest,t_char_item&source){
      dest.value=source.value;
    }
    static void clone(IEnvRTTI&Env,string&dest,string&source){
      dest=source;
    }
    static void clone(IEnvRTTI&Env,t_string&dest,t_string&source){
      dest.value=source.value;
    }
    static void clone(IEnvRTTI&Env,t_name&dest,t_name&source){
      dest.value=source.value;
    }
    static void clone(IEnvRTTI&Env,t_sep&dest,t_sep&source){
      dest.value=source.value;
    }
    static void clone(IEnvRTTI&Env,t_add_subexpr&dest,t_add_subexpr&source){
      clone(Env,dest.body,source.body);
    }
    static void clone(IEnvRTTI&Env,TAutoPtr<t_without_add::i_expr>&dest,TAutoPtr<t_without_add::i_expr>&source){
      t_shit_visitor::clone(Env,dest,source);
    }
    static void clone(IEnvRTTI&Env,t_call_param&dest,t_call_param&source){
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.body,source.body);
      clone(Env,dest.sep1,source.sep1);
      //F(t_sep,sep0);
      //F(TAutoPtr<i_expr>,body);
      //F(t_sep,sep1);
    }
    template<class TYPE>
    static void clone(IEnvRTTI&Env,vector<TYPE>&dest,vector<TYPE>&source){
      dest.resize(source.size());
      for(int i=0;i<dest.size();i++){
        clone(Env,dest[i],source[i]);
      }
    }
    static void clone(IEnvRTTI&Env,t_call_params&dest,t_call_params&source){
      clone(Env,dest.sep,source.sep);
      clone(Env,dest.arr,source.arr);
      //F(t_sep,sep);
      //F(vector<t_call_param>,arr);
    }
  public:
    static void clone(IEnvRTTI&Env,TAutoPtr<i_expr>&dest,TAutoPtr<i_expr>&source)
    {
      if(!source)return;
      t_clone_expr_dev dev={Env};
      dev.push(&dest);
      t_expr_visitor V(dev);
      source->Use(V);
    }
  };
public:
  class t_stat_visitor:public t_simple_stat_lex::i_stat_visitor{
  public:
    t_clone_stat_dev&dev;
    t_stat_visitor(t_clone_stat_dev&dev):dev(dev){}
  public:
    #define F(TYPE)void Do(TYPE*p){auto&dest=*dev.get().build<TYPE>(dev.Env);auto&source=*p;clone(dev.Env,dest,source);}
      F(t_var_stat);
      F(t_sep_stat);
      F(t_block_stat);
      F(t_expr_stat);
      F(t_func_stat);
      F(t_oper_stat);
      F(t_ret_stat);
      F(t_null_stat);
      F(t_setadd_stat);
      F(t_set_stat);
      F(t_break_stat);
      F(t_continue_stat);
      F(t_for_stat);
      F(t_if_stat);
    #undef F
  public:/*
    void Do(t_var_stat*p){
      auto&dest=*dev.get().build<t_var_stat>(dev.Env);
      auto&source=*p;
      clone(dev.Env,dest,source);
    }*/
    static void clone(IEnvRTTI&Env,t_var_stat&dest,t_var_stat&source){
      clone(Env,dest.type,source.type);
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.name,source.name);
      clone(Env,dest.sep1,source.sep1);
      clone(Env,dest.sep2,source.sep2);
      clone(Env,dest.value,source.value);
      clone(Env,dest.sep3,source.sep3);
      #define F(TYPE,NAME)//clone(Env,dest.NAME,source.NAME);
      {
        F(t_name,type);
        F(t_sep,sep0);
        F(t_name,name);
        F(t_sep,sep1);
        F(t_sep,sep2);
        F(TAutoPtr<i_expr>,value);
        F(t_sep,sep3);
      }
      #undef F
    }
    static void clone(IEnvRTTI&Env,t_sep_stat&dest,t_sep_stat&source){
      clone(Env,dest.sep,source.sep);
    }
    static void clone(IEnvRTTI&Env,t_expr_stat&dest,t_expr_stat&source){
      clone(Env,dest.body,source.body);
    }
    static void clone(IEnvRTTI&Env,t_func_stat&dest,t_func_stat&source){
      clone(Env,dest.type,source.type);
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.name,source.name);
      clone(Env,dest.sep1,source.sep1);
      clone(Env,dest.params,source.params);
      clone(Env,dest.sep2,source.sep2);
      clone(Env,dest.body,source.body);
      //F(t_name,type);
      //F(t_sep,sep0);
      //F(t_name,name);
      //F(t_sep,sep1);
      //F(t_params,params);
      //F(t_sep,sep2);
      //F(t_func_body,body);
    }
    static void clone(IEnvRTTI&Env,t_oper_stat&dest,t_oper_stat&source){
      clone(Env,dest.type,source.type);
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.sep1,source.sep1);
      clone(Env,dest.oper,source.oper);
      clone(Env,dest.sep2,source.sep2);
      clone(Env,dest.params,source.params);
      clone(Env,dest.sep3,source.sep3);
      clone(Env,dest.body,source.body);
      //F(t_name,type);
      //F(t_sep,sep0);
      //F(t_sep,sep1);
      //F(string,oper);
      //F(t_sep,sep2);
      //F(t_params,params);
      //F(t_sep,sep3);
      //F(t_func_body,body);
    }
    static void clone(IEnvRTTI&Env,t_ret_stat&dest,t_ret_stat&source){
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.body,source.body);
      clone(Env,dest.sep1,source.sep1);
      //F(t_sep,sep0);
      //F(TAutoPtr<i_expr>,body);
      //F(t_sep,sep1);
    }
    static void clone(IEnvRTTI&Env,t_null_stat&dest,t_null_stat&source){}
    static void clone(IEnvRTTI&Env,t_setadd_stat&dest,t_setadd_stat&source){
      clone(Env,dest.name,source.name);
      clone(Env,dest.value,source.value);
      //F(t_name,name);
      //F(TAutoPtr<i_expr>,value);
    }
    static void clone(IEnvRTTI&Env,t_set_stat&dest,t_set_stat&source){
      clone(Env,dest.name,source.name);
      clone(Env,dest.value,source.value);
      //F(t_name,name);
      //F(TAutoPtr<i_expr>,value);
    }
    static void clone(IEnvRTTI&Env,t_break_stat&dest,t_break_stat&source){}
    static void clone(IEnvRTTI&Env,t_continue_stat&dest,t_continue_stat&source){}
    static void clone(IEnvRTTI&Env,t_for_stat&dest,t_for_stat&source){
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.init,source.init);
      clone(Env,dest.cond,source.cond);
      clone(Env,dest.next,source.next);
      clone(Env,dest.sep1,source.sep1);
      clone(Env,dest.body,source.body);
      //F(t_sep,sep0);
      //F(t_var_stat,init);
      //F(t_less_expr,cond);
      //F(t_addadd_expr,next);
      //F(t_sep,sep1);
      //F(t_block_stat,body);
    }
    static void clone(IEnvRTTI&Env,t_if_stat&dest,t_if_stat&source){
      clone(Env,dest.cond,source.cond);
      clone(Env,dest.sep,source.sep);
      clone(Env,dest.bef,source.bef);
      clone(Env,dest.aft,source.aft);
      //F(t_eq_expr,cond);
      //F(t_sep,sep);
      //F(t_block_stat,bef);
      //F(TAutoPtr<t_else>,aft);
    }
  public:
    #define F(TYPE)typedef t_simple_stat_lex::TYPE TYPE;
    F(t_params);
    F(t_param);
    F(t_func_body);
    F(t_less_expr);
    F(t_addadd_expr);
    F(t_block_stat);
    //UG
    F(t_command_block);
    F(t_eq_expr);
    #undef F
  public:
    static void clone(IEnvRTTI&Env,t_name&dest,t_name&source){
      dest.value=source.value;
    }
    static void clone(IEnvRTTI&Env,t_sep&dest,t_sep&source){
      dest.value=source.value;
    }
    static void clone(IEnvRTTI&Env,t_params&dest,t_params&source){
      clone(Env,dest.arr,source.arr);
      clone(Env,dest.sep,source.sep);
      //F(vector<t_param>,arr);
      //F(t_sep,sep);
    }
    static void clone(IEnvRTTI&Env,t_func_body&dest,t_func_body&source){
      clone(Env,dest.arr,source.arr);
    }
    static void clone(IEnvRTTI&Env,string&dest,string&source){
      dest=source;
    }
    static void clone(IEnvRTTI&Env,t_less_expr&dest,t_less_expr&source){
      clone(Env,dest.bef,source.bef);
      clone(Env,dest.aft,source.aft);
      //F(TAutoPtr<i_expr>,bef);
      //F(TAutoPtr<i_expr>,aft);
    }
    static void clone(IEnvRTTI&Env,t_addadd_expr&dest,t_addadd_expr&source){
      clone(Env,dest.body,source.body);
      //F(t_name,body);
    }
    static void clone(IEnvRTTI&Env,t_block_stat&dest,t_block_stat&source){
      clone(Env,dest.body,source.body);
      //F(t_command_block,body);
    }
    static void clone(IEnvRTTI&Env,t_eq_expr&dest,t_eq_expr&source){
      clone(Env,dest.bef,source.bef);
      clone(Env,dest.aft,source.aft);
      //F(TAutoPtr<i_expr>,bef);
      //F(TAutoPtr<i_expr>,aft);
    }
  public:
    typedef t_if_stat::t_else t_else;
    static void clone(IEnvRTTI&Env,TAutoPtr<t_else>&dest,TAutoPtr<t_else>&source){
      if(!source)return;
      auto*pDest=dest.build<t_else>(Env);
      auto*pSource=source.get();
      clone(Env,*pDest,*pSource);
    }
  public:
    static void clone(IEnvRTTI&Env,t_param&dest,t_param&source){
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.type,source.type);
      clone(Env,dest.sep1,source.sep1);
      clone(Env,dest.name,source.name);
      clone(Env,dest.sep2,source.sep2);
      //F(t_sep,sep0);
      //F(t_name,type);
      //F(t_sep,sep1);
      //F(t_name,name);
      //F(t_sep,sep2);
    }
    static void clone(IEnvRTTI&Env,t_command_block&dest,t_command_block&source){
      clone(Env,dest.arr,source.arr);
      //F(vector<TAutoPtr<i_stat>>,arr);
    }
    static void clone(IEnvRTTI&Env,t_else&dest,t_else&source){
      clone(Env,dest.sep0,source.sep0);
      clone(Env,dest.sep1,source.sep1);
      clone(Env,dest.body,source.body);
      //F(t_sep,sep0);
      //F(t_sep,sep1);
      //F(t_block_stat,body);
    }
  public:
    template<class TYPE>
    static void clone(IEnvRTTI&Env,vector<TYPE>&dest,vector<TYPE>&source){
      dest.resize(source.size());
      for(int i=0;i<dest.size();i++){
        clone(Env,dest[i],source[i]);
      }
    }
  public:
    static void clone(IEnvRTTI&Env,TAutoPtr<i_expr>&dest,TAutoPtr<i_expr>&source){
      t_expr_visitor::clone(Env,dest,source);
    }
  public:
    static void clone(IEnvRTTI&Env,TAutoPtr<i_stat>&dest,TAutoPtr<i_stat>&source)
    {
      if(!source)return;
      t_clone_stat_dev dev={Env};
      dev.push(&dest);
      t_stat_visitor V(dev);
      source->Use(V);
    }
  };
public:
  static void clone(IEnvRTTI&Env,TAutoPtr<i_stat>&dest,TAutoPtr<i_stat>&source)
  {
    t_stat_visitor::clone(Env,dest,source);
  }
public:
  typedef t_simple_stat_lex::t_func_body t_func_body;
  static void clone(IEnvRTTI&Env,t_func_body&dest,t_func_body&source)
  {
    t_stat_visitor::clone(Env,dest.arr,source.arr);
  }
};

/*
    virtual void Do(t_var_stat*p){
      auto&ref=dev.get();
      auto*ptr=ref.build<t_var_stat>(dev.Env);
      auto*pType=TTypeStruct::UberCast(ref.Product.pType.get());
      QapAssert(pType);
      auto&arr=pType->Members;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto*pDest=ex.getValue(ptr);
        auto*pSrc=ex.getValue(p);
        //ADDVAR(0,t_name,type,DEF,$,$)\
        //ADDVAR(1,t_sep,sep0,DEF,$,$)\
        //ADDVAR(2,t_name,name,DEF,$,$)\
        //ADDVAR(3,t_sep,sep1,DEF,$,$)\
        //ADDVAR(4,t_sep,sep2,DEF,$,$)\
        //ADDVAR(5,TAutoPtr<i_expr>,value,DEF,$,$)\
        //ADDVAR(6,t_sep,sep3,DEF,$,$)\
        //ex.Type->
        //тут нужно копировать содержимое в pDest из pSrc.
      }
    }
*/


/*

var arr=POST['data'].split(' ').join("").split("\r").join("").split("\\\n");
var out=[];
var clones=[];
for(var i=0;i<arr.length;i++){
  var t=arr[i].split(",");
  out.push("//F("+t[1]+","+t[2]+");");
  clones.push("clone(Env,dest."+t[2]+",source."+t[2]+");");
}
return clones.join("\n")+"\n"+out.join("\n");

*//*
----------------
2014.01.02
----------------
что находится в этом файле?
тут размещен исходный код системы которая клонирует объекты хранящиеся в:
  TAutoPtr<i_stat>
  t_func_body
  TAutoPtr<i_expr>


ну офигеть. я вместо того, чтобы начать делать генератор клонеров, взял и начал заниматься написание ручного высоко скоростного копирователя.
хотя. надо сказать просто чисто копирователь не такая и плохая вещь как может показаться по началу.
вообще копирователь будет работать быстрее чем qap_lex_clone. И
вообще я наверно именно им и буду пользоваться.
короче внём явно есть большая необходимость. т.к он работает не только с лексемами но и вообще с любыми типами.
и это очень хорошо.

так. я себя уговорил продолжать делать универсальный копирователь.

так. проблемма я не могу глядя на описание типа понять с чем он работает - следовательно мне нужно его как-то регестрировать.
а мне лень регестрировать.
регистрировать
регистрировать
регестрировать
регестрирровать
регестрировать
регестрировать
хочешь попробовать со мной конкурировать по скорости написания текста.
я считаю что печатаю очень быстро.
кончено может быть есть настоящие професионалаы, но моя цель не просто печатать текст
а вообще то писать программу. а для того, чтобы писать программу вообще говоря уменее быстро печатать не так уж и необходимо.
но для того, чтобы записывать свои мысли и уметь их редактировать ивообще хоть как то их структурировать мне призо

мне приходиться очень много печатать только для того, чтобы я мог бы видеть свои мысли полностью.
я записываю свои мысли для того, чтобы затем их отредактировать.
короче если я не буду записывать свои мысли то я очень быстро запутаюсь.
за записывание своих мыслей помогает мне.
хотя может быть я всё вру и ничего мне это не помогает.
больше всего помогает - это зафиксировать мысли.

вот! я понял в чём суть того, что я печатаю текст во время мыслительных процессов.
просто если ничего не печатать, то тогда становиться очень трудно понять, 

короче вся проблемма в том, что мозг генерирует бесконечный поток мыслей.
короче мне приходиться выкидывать большую часть мыслий.

итак факт. большая часть мыслей которые приходят ко мне вголоду приходят не вовремя.
моя задача - то отфильтровать мысли.
на исполнение нужно отправлять только те мысли которые в данной ситуации ведут к наиболее
выгодному для меня состоянию.

точнее нифига не так.
все мысли которые приходят ко мне в голову всегда выгодны в данной ситуации. но вот глобально - хрен их знает.

короче проблемма в том, что нужно как-то фильтровать мысли и выполнять из них те, которые в глобальном плане дают какой-то выйгрышь.

самый самак - это когда мысль в локальном ситуации нифига не выгодна - но вот лобально - выгодна.

да да это очень странный момент когда приходиться идти на уступки локально, чтобы получить глобальный выйгрышь.
это нужно для того, чтобы перехитрить тех, кто не умеет идти на уступки.

короче суть в том, что большая часть населения планеты очень не охотно идёт на уступки.
они готовы заплатить за локальную победу - глобальны поражением.

мозг человеку нужен для того, чтобы мыслить глобально.
суть в том, что мозг человека наверно единственное что в это мире может мыслить настолько глобально.

регистрировать.

регистрировать
регистрировать
регистрировать
регистрировать
регистрировать.

то такое прикольное слово его можно чень быстро написать. 
вообще можно писать и медленее.

ааа. ладно давай вообще поговорим о чём-то ещё.

я пишу текст.
программа слушает этот текст и ищет ещё кого-то кто думает о том же.
короче это вообще решаемая задача глядя на два потока набираемых символов понять, что они чем-то очень похожи.

ладно если меня так сильно интересует эта тема, то тогда нужно записывать спецальной программой все мысли которые приходят мне в голову.
а затем когда накопиться большая куча моих мыслей можно будет попробовать их проанализировать - как вручную так и глобально.

ну ок. вот я могу прямо тут в этом коментарии начать писать ту программу.

на чём писать JavaScript или C++? Вообще JavaScript Возможно даст результат чуть раньше и крос платформеный, но что?
С++: плюсы(можно использовать свои убер технологии. - это не плюс я ещё не разу не получал от этого выгоды.)
ладно если не сипользовать 

итак с++ полон соблазнов использовать свои наработки и короче приведёт к генерированию мыслей о том как бы это всё соеденеить с моей программой.
и возможно ещё до получения первого результата я уже начну соеденё...

в первом приближении:
если делать на С++ то тогда нужно писать независимый проект который почти не использует мои старые наработки.

JavaScript как замерить время

window.performance.now()

теперь надо понять как поймать сообщение о том, что нажата клавиша.

вообще тут есть проблемма дело в том, что пользователь может не только писать текст но ещё и изменять его.
ну тоесть его очень трудно заставить не кликать мышкой по тексту.
да это печально.

но что поделать.
ладно приступим.

JavaScript OnKeyDown

document.onkeydown = function(event){
  events = event || window.event;
  if (events.keyCode == 13) {
  process();
  }
}

struct foo{
  void*a;
  void*b;
  struct t_impl{
    string&a;
    string&b;
  };
  void go(){

  }
};

спорный вопрос.
хранить в t_clone_dev указтель на dest.
хранить в t_clone_dev указтель на dest и на source.

вообще я могу сделать так, чтобы там было два стека. один будет следить за dest другой за source.
как лучше довольно трудно понять.

*/
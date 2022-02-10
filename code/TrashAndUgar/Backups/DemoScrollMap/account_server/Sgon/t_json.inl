class t_json{
public:
  //===>>===i_value_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_true)\
  ADD(t_false)\
  ADD(t_null)\
  ADD(t_string)\
  ADD(t_number)\
  ADD(t_empty_array)\
  ADD(t_array)\
  ADD(t_empty_object)\
  ADD(t_object)\
  ADDEND()

  class i_value;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_value_visitor{
  public:
    #define ADD(U)virtual void Do(U*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_json::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
      #define ADD(U)void Do(U*p){ptr=get(p);}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_value*p){
      if(!p)return nullptr;Is<TYPE,i_value_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_value_visitor
public:
  class i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_value
  #include "QapGenStruct.inl"
  //<<<<<+=====i_value
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_true);
        F(t_false);
        F(t_null);
        F(t_string);
        F(t_number);
        F(t_empty_array);
        F(t_array);
        F(t_empty_object);
        F(t_object);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
    virtual void Use(i_value_visitor&){QapDebugMsg("no way.");/*A.Do(this);*/}
  };
  class t_true:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_true)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_true
  #include "QapGenStruct.inl"
  //<<<<<+=====t_true
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("true");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
  class t_false:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_false)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_false
  #include "QapGenStruct.inl"
  //<<<<<+=====t_false
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("false");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
  class t_null:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null
  #include "QapGenStruct.inl"
  //<<<<<+=====t_null
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("null");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
  class t_string:public i_value{
  public:
    class i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_item
    #include "QapGenStruct.inl"
    //<<<<<+=====i_item
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_raw);
          F(t_fix);
          F(t_hex);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
      virtual string get_code()const{QapDebugMsg("no way.");return "";}
      virtual string get_value()const{QapDebugMsg("no way.");return "";}
    };
    class t_raw:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)PARENT(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_raw
    #include "QapGenStruct.inl"
    //<<<<<+=====t_raw
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static auto dip_inv_quote_slash_lf=dip_inv("\"\\\n");
        D+=dev.go_any(body,dip_inv_quote_slash_lf);
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{return body;}
      string get_value()const{return body;}
    };
    class t_fix:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fix)PARENT(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,body,SET,'z',$)\
    ADDEND()
    //=====+>>>>>t_fix
    #include "QapGenStruct.inl"
    //<<<<<+=====t_fix
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("\\");
        if(!ok)return ok;
        D+=dev.go_any_char(body,"\"\\/bfnrt");
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{return "\\"+CToS(body);}
      string get_value()const{
        string code=SelfClass::get_code();
        BinString str=code;
        return str.data;
      }
    };
    class t_hex:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex)PARENT(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(array(char,4),arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_hex
    #include "QapGenStruct.inl"
    //<<<<<+=====t_hex
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("\\u");
        if(!ok)return ok;
        static auto gen_dips_09afAF=gen_dips("09afAF");
        D+=dev.go_any_arr_char(arr,gen_dips_09afAF);
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{return "\\u"+CToS(arr[0])+CToS(arr[1])+CToS(arr[2])+CToS(arr[3]);}
      string get_value()const{
        QapDebugMsg("not suported");
        string code=SelfClass::get_code();
        BinString str=code;
        return str.data;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("\"");
        if(!ok)return ok;
        D+=dev.go_auto(arr);
        if(!ok)return ok;
        D+=dev.go_const("\"");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_raw)F(t_fix)F(t_hex)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string
  #include "QapGenStruct.inl"
  //<<<<<+=====t_string
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  public:
    string get_code()const{
      return value;
      //string out;
      //auto&arr=body.arr;
      //for(int i=0;i<arr.size();i++){
      //  out+=arr[i]->get_code();
      //}
      //return "\""+out+"\"";
    }
    string get_value()const{
      QapDebugMsg("no impl");
      string out;
      /*auto&arr=body.arr;
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->get_value();
      }*/
      return out;
    }
  };
  class t_number:public i_value{
  public:
    class i_int{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_int)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_int
    #include "QapGenStruct.inl"
    //<<<<<+=====i_int
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_num);
          F(t_zero);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
      virtual string get_code()const{QapDebugMsg("no way.");return "";}
    };
    class t_minus{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_minus)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_minus
    #include "QapGenStruct.inl"
    //<<<<<+=====t_minus
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("-");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_frac{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_frac
    #include "QapGenStruct.inl"
    //<<<<<+=====t_frac
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const(".");
        if(!ok)return ok;
        static auto gen_dips_09=gen_dips("09");
        M+=dev.go_any(arr,gen_dips_09);
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{return "."+arr;}
    };
    class t_sign{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,sign,SET,'+',$)\
    ADDEND()
    //=====+>>>>>t_sign
    #include "QapGenStruct.inl"
    //<<<<<+=====t_sign
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_any_char(sign,"-+");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_exp{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,e,SET,'e',$)\
    ADDVAR(TAutoPtr<t_sign>,sign,DEF,$,$)\
    ADDVAR(string,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_exp
    #include "QapGenStruct.inl"
    //<<<<<+=====t_exp
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static auto eE="eE";
        M+=dev.go_any_char(e,eE);
        if(!ok)return ok;
        O+=dev.go_auto(sign);
        if(!ok)return ok;
        static auto gen_dips_09=gen_dips("09");
        M+=dev.go_any(arr,gen_dips_09);
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{
        string out;
        out+=CToS(e);
        if(sign)out+=CToS(sign->sign);
        out+=arr;
        return out;
      }
    };
    class t_num:public i_int{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_int)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,first,SET,'1',$)\
    ADDVAR(string,num,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_num
    #include "QapGenStruct.inl"
    //<<<<<+=====t_num
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static auto gen_dips_19=gen_dips("19");
        M+=dev.go_any_char(first,gen_dips_19);
        if(!ok)return ok;
        static auto gen_dips_09=gen_dips("09");
        O+=dev.go_any(num,gen_dips_09);
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{return CToS(first)+num;}
    };
    class t_zero:public i_int{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_int)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_zero
    #include "QapGenStruct.inl"
    //<<<<<+=====t_zero
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("0");
        if(!ok)return ok;
        return ok;
      }
      string get_code()const{return "0";}
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_minus>,minus,DEF,$,$)\
    ADDVAR(TAutoPtr<i_int>,val,DEF,$,$)\
    ADDVAR(TAutoPtr<t_frac>,frac,DEF,$,$)\
    ADDVAR(TAutoPtr<t_exp>,exp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(minus);
        if(!ok)return ok;
        M+=dev.go_auto(val);
        if(!ok)return ok;
        O+=dev.go_auto(frac);
        if(!ok)return ok;
        O+=dev.go_auto(exp);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_minus)F(t_frac)F(t_sign)F(t_exp)F(t_num)F(t_zero)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number
  #include "QapGenStruct.inl"
  //<<<<<+=====t_number
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  public:
    string get_code()const{
      return value;
    }
  };
  class t_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep
  #include "QapGenStruct.inl"
  //<<<<<+=====t_sep
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_any(body," \t\r\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_empty_array:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_empty_array)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_empty_array
  #include "QapGenStruct.inl"
  //<<<<<+=====t_empty_array
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("[");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
  class t_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<i_value>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_value
  #include "QapGenStruct.inl"
  //<<<<<+=====t_value
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_array:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_array)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_value>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_array
  #include "QapGenStruct.inl"
  //<<<<<+=====t_array
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("[");
      if(!ok)return ok;
      M+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
  class t_empty_object:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_empty_object)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_empty_object
  #include "QapGenStruct.inl"
  //<<<<<+=====t_empty_object
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
  class t_pair{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pair)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_string,key,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_value,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pair
  #include "QapGenStruct.inl"
  //<<<<<+=====t_pair
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(key);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const(":");
      if(!ok)return ok;
      M+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_object:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_object)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_pair>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_object
  #include "QapGenStruct.inl"
  //<<<<<+=====t_object
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if(!ok)return ok;
      M+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
    void Use(i_value_visitor&A){A.Do(this);}
  };
public:
#define DEF_PRO_NESTED(F)F(t_true)F(t_false)F(t_null)F(t_string)F(t_number)F(t_sep)F(t_empty_array)F(t_value)\
F(t_array)F(t_empty_object)F(t_pair)F(t_object)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_json)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_json
#include "QapGenStruct.inl"
//<<<<<+=====t_json
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    return ok;
  }
};

/*
//list of types:
F(t_json)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fjson%7B%0A%0At%5Ftrue%3D%3Ei%5Fvalue%7B%7Bgo%5Fconst%28%22true%22%29%3B%7D%7
D%0At%5Ffalse%3D%3Ei%5Fvalue%7B%7Bgo%5Fconst%28%22false%22%29%3B%7D%7D%0At%5Fnul
l%3D%3Ei%5Fvalue%7B%7Bgo%5Fconst%28%22null%22%29%3B%7D%7D%0A%0At%5Fstring%3D%3Ei
%5Fvalue%7B%0A%20%20t%5Fraw%3D%3Ei%5Fitem%7Bstring%20body%3B%7Bgo%5Fany%28body%2
Cdip%5Finv%28%22%5C%22%5C%5C%5Cn%22%29%29%3B%7D%7D%0A%20%20t%5Ffix%3D%3Ei%5Fitem
%7Bchar%20body%3D%27z%27%3B%7Bgo%5Fconst%28%22%5C%5C%22%29%3Bgo%5Fany%5Fchar%28b
ody%2C%22%5C%22%5C%5C%2Fbfnrt%22%29%3B%7D%7D%0A%20%20t%5Fhex%3D%3Ei%5Fitem%7Barr
ay%28char%2C4%29%20arr%3B%7Bgo%5Fconst%28%22%5C%5Cu%22%29%3Bgo%5Fany%5Farr%5Fcha
r%28arr%2Cgen%5Fdips%28%2209afAF%22%29%29%3B%7D%7D%0A%20%20t%5Fitems%7Bvector%3C
TAutoPtr%3Ci%5Fitem%3E%3E%20arr%3B%7Bgo%5Fauto%28arr%29%3B%7D%7D%0A%20%20t%5Fite
ms%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%22%22%29%3B%0A%20%20%
20%20go%5Fauto%28body%29%3B%0A%20%20%20%20go%5Fconst%28%22%5C%22%22%29%3B%0A%20%
20%7D%0A%7D%0A%0At%5Fnumber%3D%3Ei%5Fvalue%7B%0A%20%20t%5Fminus%7B%7Bgo%5Fconst%
28%22%2D%22%29%3B%7D%7D%0A%20%20t%5Ffrac%7B%0A%20%20%20%20string%20arr%3B%0A%20%
20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%2E%22%29%3B%0A%20%20%20%
20%20%20M%2B%3Dgo%5Fany%28arr%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%20%20%7D
%0A%20%20%7D%0A%20%20t%5Fsign%7B%0A%20%20%20%20char%20sign%3D%27%2B%27%3B%0A%20%
20%20%20%7B%0A%20%20%20%20%20%20go%5Fany%5Fchar%28sign%2C%22%2D%2B%22%29%3B%0A%2
0%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fexp%7B%0A%20%20%20%20char%20e%3D%27e%27%3B
%0A%20%20%20%20TAutoPtr%3Ct%5Fsign%3E%20sign%3B%0A%20%20%20%20string%20arr%3B%0A
%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28e%2C%22eE%22%29%3B%
0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sign%29%3B%0A%20%20%20%20%20%20M%2B%3Dgo%
5Fany%28arr%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20
%20t%5Fnum%3D%3Ei%5Fint%7B%0A%20%20%20%20char%20first%3D%271%27%3B%0A%20%20%20%2
0string%20num%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28
first%2Cgen%5Fdips%28%2219%22%29%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fany%28num
%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fzero
%3D%3Ei%5Fint%7B%7Bgo%5Fconst%28%220%22%29%3B%7D%7D%0A%20%20TAutoPtr%3Ct%5Fminus
%3E%20minus%3B%0A%20%20TAutoPtr%3Ci%5Fint%3E%20val%3B%0A%20%20TAutoPtr%3Ct%5Ffra
c%3E%20frac%3B%0A%20%20TAutoPtr%3Ct%5Fexp%3E%20exp%3B%0A%20%20%7B%0A%20%20%20%20
O%2B%3Dgo%5Fauto%28minus%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28val%29%3B%0A%20%
20%20%20O%2B%3Dgo%5Fauto%28frac%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28exp%29%3B
%0A%20%20%7D%0A%7D%0A%0At%5Fsep%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20
%20%20go%5Fany%28body%2C%22%20%5Ct%5Cr%5Cn%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fe
mpty%5Farray%3D%3Ei%5Fvalue%7B%0A%20%20t%5Fsep%20sep%3B%0A%20%20%7B%0A%20%20%20%
20M%2B%3Dgo%5Fconst%28%22%5B%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B
%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fva
lue%7B%0A%20%20t%5Fsep%20sep%3B%0A%20%20TAutoPtr%3Ci%5Fvalue%3E%20body%3B%0A%20%
20%7B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%
28body%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fcomma%5Fvalue%7B%0A%20%20t%5Fsep%20sep%3
B%0A%20%20t%5Fvalue%20body%3B%0A%20%20%7B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%2
9%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%2C%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5
Fauto%28body%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Farray%3D%3Ei%5Fvalue%7B%0A%20%20t%
5Fvalue%20first%3B%0A%20%20vector%3Ct%5Fcomma%5Fvalue%3E%20arr%3B%0A%20%20t%5Fse
p%20sep%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5B%22%29%3B%0A%20%2
0%20%20M%2B%3Dgo%5Fauto%28first%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B
%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%5D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fempty%5Fobject%3D%3Ei%5Fvalue%7B%0A%20%
20t%5Fsep%20sep%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B
%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%7D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fpair%7B%0A%20%20t%5Fsep%20sep0%3B%0A%20
%20t%5Fstring%20key%3B%0A%20%20t%5Fsep%20sep1%3B%0A%20%20t%5Fvalue%20value%3B%0A
%20%20%7B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0A%20%20%20%20M%2B%3Dgo%5F
auto%28key%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0A%20%20%20%20M%2B%
3Dgo%5Fconst%28%22%3A%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28value%29%3B%0A%2
0%20%7D%0A%7D%0A%0At%5Fcomma%5Fpair%7B%0A%20%20t%5Fsep%20sep%3B%0A%20%20t%5Fpair
%20body%3B%0A%20%20%7B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20
M%2B%3Dgo%5Fconst%28%22%2C%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%
0A%20%20%7D%0A%7D%0A%0At%5Fobject%3D%3Ei%5Fvalue%7B%0A%20%20t%5Fpair%20first%3B%
0A%20%20vector%3Ct%5Fcomma%5Fpair%3E%20arr%3B%0A%20%20t%5Fsep%20sep%3B%0A%20%20%
7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fa
uto%28first%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20O%2B%
3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%
20%7D%0A%7D%0A%0A%7D
*/

class t_json_tree{
public:
  //===>>===i_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_bool)\
  ADD(t_null)\
  ADD(t_string)\
  ADD(t_number)\
  ADD(t_array)\
  ADD(t_object)\
  ADDEND()

  class i_value;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_visitor{
  public:
    #define ADD(U)virtual void Do(U*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_json_tree::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
      #define ADD(U)void Do(U*p){ptr=get(p);}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_value*p){
      if(!p)return nullptr;Is<TYPE,i_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_visitor
public:
  class i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_value
  #include "QapGenStruct.inl"
  //<<<<<+=====i_value
  public:
    //F(t_bool);
    //F(t_null);
    //F(t_string);
    //F(t_number);
    //F(t_array);
    //F(t_object);
    virtual void Use(i_visitor&A){QapDebugMsg("no way");/*A.Do(this);*/}
  };
  class t_bool:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool)PARENT(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool
  #include "QapGenStruct.inl"
  //<<<<<+=====t_bool
  public:
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_null:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null)PARENT(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null
  #include "QapGenStruct.inl"
  //<<<<<+=====t_null
  public:
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_string:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string
  #include "QapGenStruct.inl"
  //<<<<<+=====t_string
  public:
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_number:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number
  #include "QapGenStruct.inl"
  //<<<<<+=====t_number
  public:
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_array:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_array)PARENT(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_value>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_array
  #include "QapGenStruct.inl"
  //<<<<<+=====t_array
  public:
    void Use(i_visitor&A){A.Do(this);}
  };
  class t_pair{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pair)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,key,DEF,$,$)\
  ADDVAR(TAutoPtr<i_value>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pair
  #include "QapGenStruct.inl"
  //<<<<<+=====t_pair
  public:
  };
  class t_object:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_object)PARENT(i_value)OWNER(t_json_tree)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_pair>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_object
  #include "QapGenStruct.inl"
  //<<<<<+=====t_object
  public:
    void Use(i_visitor&A){A.Do(this);}
    t_pair&add_pair(const string&key){
      QapAssert(find_key(key)<0);
      arr.resize(arr.size()+1);
      auto&back= arr.back();
      back.key=key;
      return back;
    }
    int find_key(const string&key)const
    {
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(ex.key==key)return i;
      }
      return -1;
    }
    t_pair&find_pair(const string&key){
      auto id=find_key(key);
      QapAssert(id>=0);
      return arr[id];
    }
  };
#define DEF_PRO_NESTED(F)F(t_bool)F(t_null)F(t_string)F(t_number)F(t_array)F(t_pair)F(t_object)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_json_tree)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_json_tree
#include "QapGenStruct.inl"
//<<<<<+=====t_json_tree
public:
  struct t_dev{
    IEnvRTTI&Env;
    TAutoPtr<i_value>&result;
  };
  class t_value_visitor:public t_json::i_value_visitor{
  public:
    typedef t_json_tree t_main;
  public:
    t_dev&dev;
    t_value_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_true*p){
      dev.result.build<t_main::t_bool>(dev.Env)->value="true";
    }
    void Do(t_false*p){
      dev.result.build<t_main::t_bool>(dev.Env)->value="false";
    }
    void Do(t_null*p){
      dev.result.build<t_main::t_null>(dev.Env);
    }
    void Do(t_string*p){
      auto*ptr=dev.result.build<t_main::t_string>(dev.Env);
      ptr->body=p->get_code();
    }
    void Do(t_number*p){
      auto*ptr=dev.result.build<t_main::t_number>(dev.Env);
      ptr->body=p->get_code();
    }
    void Do(t_empty_array*p){
      dev.result.build<t_main::t_array>(dev.Env);
    }
    void Do(t_array*p){
      auto*ptr=dev.result.build<t_main::t_array>(dev.Env);
      ptr->arr.resize(p->arr.size());
      //clone(dev.Env,ptr->arr[0],p->first.body);
      for(int i=0;i<p->arr.size();i++){
        clone(dev.Env,ptr->arr[i],p->arr[i].body);
      }
    }
    void Do(t_empty_object*p){
      dev.result.build<t_main::t_object>(dev.Env);
    }
    void Do(t_object*p){
      auto*ptr=dev.result.build<t_main::t_object>(dev.Env);
      ptr->arr.resize(p->arr.size());
      auto clone_pair=[this](t_main::t_pair&dest,const t_json::t_pair&src)->void{
        dest.key=src.key.get_code();
        clone(dev.Env,dest.value,src.value.body);
      };
      //clone_pair(ptr->arr[0],p->first);
      for(int i=0;i<p->arr.size();i++){
        clone_pair(ptr->arr[i],p->arr[i]);
      }
    }
  };
  static void clone(IEnvRTTI&Env,TAutoPtr<i_value>&dest,const TAutoPtr<t_json::i_value>&src){
    dest=nullptr;
    if(!src)return;
    t_dev temp={Env,dest};
    t_value_visitor V(temp);
    auto*p=src.get();
    p->Use(V);
  }
public:
  struct t_save_dev{
    string&out;
    bool pretty;
    int offset;
    bool next_line;
    t_save_dev(string&out,bool pretty):out(out),pretty(pretty),offset(0),next_line(false){}
    void operator++(int){offset++;}
    void operator--(int){offset--;}
    void next(){next_line=true;}
    void add(const string&str){
      if(!pretty){out+=str;return;}
      if(next_line){
        string buff;
        buff.resize(offset*2,' ');
        out+="\n"+buff;
        next_line=false;
      }
      out+=str;
    }
  };
  struct t_visitor:public i_visitor{
  public:
    t_save_dev&dev;
    t_visitor(t_save_dev&dev):dev(dev){}
  public:
    void Do(t_bool*p){
      dev.add(p->value);
    }
    void Do(t_null*p){
      dev.add("null");
    }
    void Do(t_string*p){
      dev.add(p->body);
    }
    void Do(t_number*p){
      dev.add(p->body);
    }
    void Do(t_array*p){
      auto&arr=p->arr;
      dev.add("[");
      dev++;
      for(int i=0;i<arr.size();i++){
        if(i)dev.out+=",";
        dev.next();
        auto&ex=arr[i];
        ex->Use(*this);
      }
      if(dev.pretty)if(arr.size())dev.next();
      dev--;
      dev.add("]");
    }
    //static string gen_ws(int count){string buff;buff.resize(count,' ');return buff;}
    //void Do(t_pair*p,int max_field_length){
    //  string sep=dev.pretty?gen_ws(max_field_length-p->key.size())+": ":":";
    //  dev.add(p->key+sep);
    //  p->value->Use(*this);
    //}
    void Do(t_pair*p){
      string sep=dev.pretty?": ":":";
      dev.add(p->key+sep);
      p->value->Use(*this);
    }
    void Do(t_object*p){
      auto&arr=p->arr;
      dev.add("{");
      dev++;
      //int max_field_length=0;
      //for(int i=0;i<arr.size();i++){
      //  max_field_length=std::max<int>(max_field_length,arr[i].key.size());
      //}
      for(int i=0;i<arr.size();i++){
        if(i)dev.out+=",";
        dev.next();
        auto&ex=arr[i];
        Do(&ex);
      }
      if(dev.pretty)if(arr.size())dev.next();
      dev--;
      dev.add("}");
    }
  };
};

/*
//list of types:
F(t_json_tree)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fjson%5Ftree%7B%0A%0At%5Fbool%3D%3Ei%5Fvalue%7Bstring%20value%3B%7D%0At%5Fnul
l%3D%3Ei%5Fvalue%7B%7D%0A%0At%5Fstring%3D%3Ei%5Fvalue%7Bstring%20body%3B%7D%0At%
5Fnumber%3D%3Ei%5Fvalue%7Bstring%20body%3B%7D%0A%0At%5Farray%3D%3Ei%5Fvalue%7Bve
ctor%3CTAutoPtr%3Ci%5Fvalue%3E%3E%20arr%3B%7D%0A%0At%5Fpair%7B%0A%20%20string%20
key%3B%0A%20%20TAutoPtr%3Ci%5Fvalue%3E%20value%3B%0A%7D%0A%0At%5Fobject%3D%3Ei%5
Fvalue%7Bvector%3Ct%5Fpair%3E%20arr%3B%7D%0A%0A%7D
*/
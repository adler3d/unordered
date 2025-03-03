//time = 13.34 ms.

class t_xml_scope{
public:
  //===>>===i_node_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_comment)\
  ADD(t_text)\
  ADD(t_start)\
  ADD(t_end)\
  ADDEND()

  class i_node;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_node_visitor{
  public:
    typedef t_xml_scope::i_node i_node;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_xml_scope::U U;
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
    static TYPE*UberCast(i_node*p){
      if(!p)return nullptr;Is<TYPE,i_node_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_node_visitor
  //class t_visitor:public t_xml_scope::i_node_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_comment*p){}
  //  void Do(t_text*p){}
  //  void Do(t_start*p){}
  //  void Do(t_end*p){}
  //};
public:
  class i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_node
  #include "QapGenStruct.inl"
  //<<<<<+=====i_node
  public:
    typedef i_node_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_comment);
        F(t_text);
        F(t_start);
        F(t_end);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_name{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,char,A,SET,'0x00',$)\
  ADDVAR(1,string,B,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name
  #include "QapGenStruct.inl"
  //<<<<<+=====t_name
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=gen_dips("azAZ")+"_$@";
      M+=dev.go_any_char(A,g_static_var_0);
      if(!ok)return ok;
      static const auto g_static_var_1=gen_dips("azAZ09")+"_$@-.:";
      O+=dev.go_any(B,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,body,DEF,$,$)\
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
      static const auto g_static_var_0=" \r\n";
      D+=dev.go_any(body,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_comment:public i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comment)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_comment
  #include "QapGenStruct.inl"
  //<<<<<+=====t_comment
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("<!--");
      if(!ok)return ok;
      D+=dev.go_end(body,"-->");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_text:public i_node{
  public:
    //===>>===i_elem_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_raw)\
    ADDEND()
  
    class i_elem;
  
    #define DEF_PRO_BLANK()
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    #undef DEF_PRO_BLANK
  
    #define DEF_PRO_BLANK()
    class i_elem_visitor{
    public:
      typedef t_text::i_elem i_elem;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_text::U U;
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
      static TYPE*UberCast(i_elem*p){
        if(!p)return nullptr;Is<TYPE,i_elem_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
    #undef DEF_PRO_BLANK
  
    #undef LIST
    //===<<===i_elem_visitor
    //class t_visitor:public t_text::i_elem_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_raw*p){}
    //};
  public:
    class i_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_elem)OWNER(t_text)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_elem
    #include "QapGenStruct.inl"
    //<<<<<+=====i_elem
    public:
      typedef i_elem_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_raw);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_raw:public i_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)PARENT(i_elem)OWNER(t_text)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,text,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_raw
    #include "QapGenStruct.inl"
    //<<<<<+=====t_raw
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=dip_inv("<");
        D+=dev.go_any(text,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_raw)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_text)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,text,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_text
  #include "QapGenStruct.inl"
  //<<<<<+=====t_text
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<vector<TAutoPtr<i_elem>>>(text);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_start:public i_node{
  public:
    //===>>===i_value_visitor
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_string)\
    ADD(t_number)\
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
      typedef t_start::i_value i_value;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_start::U U;
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
    //class t_visitor:public t_start::i_value_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_string*p){}
    //  void Do(t_number*p){}
    //};
  public:
    class i_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_value)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_value
    #include "QapGenStruct.inl"
    //<<<<<+=====i_value
    public:
      typedef i_value_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        template<int>
        bool load()
        {
          F(t_string);
          F(t_number);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
        #include "QapLexPolyEnd.inl"
      };
    };
    class t_string:public i_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_value)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_string
    #include "QapGenStruct.inl"
    //<<<<<+=====t_string
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("\"");
        if(!ok)return ok;
        O+=dev.go_str<vector<TAutoPtr<i_str_item>>>(value);
        if(!ok)return ok;
        M+=dev.go_const("\"");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_number:public i_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_value)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_number
    #include "QapGenStruct.inl"
    //<<<<<+=====t_number
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=gen_dips("09");
        D+=dev.go_any(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_attr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_attr)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(0,string,sep0,DEF,$,$)\
    ADDVAR(1,string,name,DEF,$,$)\
    ADDVAR(2,string,sep1,DEF,$,$)\
    ADDVAR(3,string,sep2,DEF,$,$)\
    ADDVAR(4,TAutoPtr<i_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_attr
    #include "QapGenStruct.inl"
    //<<<<<+=====t_attr
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_str<t_sep>(sep0);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep1);
        if(!ok)return ok;
        M+=dev.go_const("=");
        if(!ok)return ok;
        O+=dev.go_str<t_sep>(sep2);
        if(!ok)return ok;
        M+=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_slash{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_slash)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_slash
    #include "QapGenStruct.inl"
    //<<<<<+=====t_slash
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("/");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_string)\
    F(t_number)\
    F(t_attr  )\
    F(t_slash )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_start)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,sep0,DEF,$,$)\
  ADDVAR(1,string,tag,DEF,$,$)\
  ADDVAR(2,vector<t_attr>,attrs,DEF,$,$)\
  ADDVAR(3,string,sep1,DEF,$,$)\
  ADDVAR(4,string,slash,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_start
  #include "QapGenStruct.inl"
  //<<<<<+=====t_start
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("<");
      if(!ok)return ok;
      O+=dev.go_str<t_sep>(sep0);
      if(!ok)return ok;
      M+=dev.go_str<t_name>(tag);
      if(!ok)return ok;
      O+=dev.go_auto(attrs);
      if(!ok)return ok;
      O+=dev.go_str<t_sep>(sep1);
      if(!ok)return ok;
      O+=dev.go_str<TAutoPtr<t_slash>>(slash);
      if(!ok)return ok;
      M+=dev.go_const(">");
      if(!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_start::TYPE TYPE;
    //  F(i_value);
    //  F(t_string);
    //  F(t_number);
    //  F(t_attr);
    //  F(t_slash);
    //  #undef F
    //public:
    //  void Do(t_string&ref){}
    //  void Do(t_number&ref){}
    //  void Do(t_attr&ref){}
    //  void Do(t_slash&ref){}
    //};
  };
  class t_end:public i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_end)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,tag,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_end
  #include "QapGenStruct.inl"
  //<<<<<+=====t_end
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("</");
      if(!ok)return ok;
      D+=dev.go_str<t_name>(tag);
      if(!ok)return ok;
      D+=dev.go_const(">");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_content{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_content)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,vector<TAutoPtr<i_node>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_content
  #include "QapGenStruct.inl"
  //<<<<<+=====t_content
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_name   )\
  F(t_sep    )\
  F(t_comment)\
  F(t_text   )\
  F(t_start  )\
  F(t_end    )\
  F(t_content)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_xml_scope)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_xml_scope
#include "QapGenStruct.inl"
//<<<<<+=====t_xml_scope
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_xml_scope::TYPE TYPE;
  //  F(i_node);
  //  F(t_name);
  //  F(t_sep);
  //  F(t_comment);
  //  F(t_text);
  //  F(t_start);
  //  F(t_end);
  //  F(t_content);
  //  #undef F
  //public:
  //  void Do(t_name&ref){}
  //  void Do(t_sep&ref){}
  //  void Do(t_comment&ref){}
  //  void Do(t_text&ref){}
  //  void Do(t_start&ref){}
  //  void Do(t_end&ref){}
  //  void Do(t_content&ref){}
  //};
};

/*
//list of types:
F(t_xml_scope)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fxml%5Fscope%7B%0D%0A%20%20t%5Fname%7B%0D%0A%20%20%20%20char%20A%3D%270x00%27
%3B%0D%0A%20%20%20%20string%20B%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M
%2B%3Dgo%5Fany%5Fchar%28A%2Cgen%5Fdips%28%22azAZ%22%29%2B%22%5F%24%40%22%29%3B%0
D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fany%28B%2Cgen%5Fdips%28%22azAZ09%22%29%2B%22%5
F%24%40%2D%2E%3A%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fsep
%7B%0D%0A%20%20%20%20string%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20go%5Fany%28body%2C%22%20%5Cr%5Cn%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%
0D%0A%20%20t%5Fcomment%3D%3Ei%5Fnode%7B%0D%0A%20%20%20%20string%20body%3B%0D%0A%
20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%3C%21%2D%2D%22%29%3B%0D%0
A%20%20%20%20%20%20go%5Fend%28body%2C%22%2D%2D%3E%22%29%3B%0D%0A%20%20%20%20%7D%
0D%0A%20%20%7D%0D%0A%20%20t%5Ftext%3D%3Ei%5Fnode%7B%0D%0A%20%20%20%20t%5Fraw%3D%
3Ei%5Felem%7B%0D%0A%20%20%20%20%20%20string%20text%3B%0D%0A%20%20%20%20%20%20%7B
%0D%0A%20%20%20%20%20%20%20%20go%5Fany%28text%2Cdip%5Finv%28%22%3C%22%29%29%3B%0
D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20string%20text%3B
%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fstr%3Cvector%3CTAutoPtr%3Ci%5F
elem%3E%3E%3E%28text%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fst
art%3D%3Ei%5Fnode%7B%0D%0A%20%20%20%20t%5Fstring%3D%3Ei%5Fvalue%7B%0D%0A%20%20%2
0%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%2
0%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dg
o%5Fstr%3Cvector%3CTAutoPtr%3Ci%5Fstr%5Fitem%3E%3E%3E%28value%29%3B%0D%0A%20%20%
20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0D%0A%20%20%20%20%20%20%
7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fnumber%3D%3Ei%5Fvalue%7B%0D%0A%20%2
0%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%2
0%20%20go%5Fany%28value%2Cgen%5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%20%20
%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fattr%7B%0D%0A%20%20%20%20%20%20str
ing%20sep0%3B%0D%0A%20%20%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%20%20str
ing%20sep1%3B%0D%0A%20%20%20%20%20%20string%20sep2%3B%0D%0A%20%20%20%20%20%20TAu
toPtr%3Ci%5Fvalue%3E%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M
%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo
%5Fstr%3Ct%5Fsep%3E%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%
28%22%3D%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28se
p2%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20
%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fslash%7B%7Bgo%5Fconst%
28%22%2F%22%29%3B%7D%7D%0D%0A%20%20%20%20string%20sep0%3B%0D%0A%20%20%20%20strin
g%20tag%3B%0D%0A%20%20%20%20vector%3Ct%5Fattr%3E%20attrs%3B%0D%0A%20%20%20%20str
ing%20sep1%3B%0D%0A%20%20%20%20string%20slash%3B%0D%0A%20%20%20%20%7B%0D%0A%20%2
0%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3C%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dg
o%5Fstr%3Ct%5Fsep%3E%28sep0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fn
ame%3E%28tag%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28attrs%29%3B%0D%0A%2
0%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fsep%3E%28sep1%29%3B%0D%0A%20%20%20%20%20%2
0O%2B%3Dgo%5Fstr%3CTAutoPtr%3Ct%5Fslash%3E%3E%28slash%29%3B%0D%0A%20%20%20%20%20
%20M%2B%3Dgo%5Fconst%28%22%3E%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A
%20%20t%5Fend%3D%3Ei%5Fnode%7B%0D%0A%20%20%20%20string%20tag%3B%0D%0A%20%20%20%2
0%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%3C%2F%22%29%3B%0D%0A%20%20%20%20%20
%20go%5Fstr%3Ct%5Fname%3E%28tag%29%3B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%3E
%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fcontent%7B%0D%0A%20
%20%20%20vector%3CTAutoPtr%3Ci%5Fnode%3E%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%
20%20%20%20%20%20go%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A
%7D
*/